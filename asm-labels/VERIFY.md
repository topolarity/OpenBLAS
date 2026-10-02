# Verifying the L(name) change

This branch, `ct/asm-local-labels-verify`, is the change (`ct/asm-local-labels`)
plus one commit that adds this directory, so `HEAD~1` is the change itself.
Not for merging.

## What the change is for

The assembly kernels name their labels `.Lxxx`. That prefix makes a label local
to the assembler on ELF and COFF, but not on Mach-O, where the prefix is `L`:
there every such label is a symbol in the object. With
`.subsections_via_symbols`, which `common_x86_64.h` has used on Darwin since
GotoBLAS2, the linker takes every symbol for the start of a block of code that
it may treat on its own, and does not see that one block falls through into
the next. Two things then go wrong on x86_64 macOS, on `develop`:

- **Folding.** Apple's new linker (the default since Xcode 15; seen here with
  ld-1267) folds a block that is byte for byte the same as a block of another
  kernel into that one, when linking at `-O2`. The code before the folded
  block runs on into whatever comes next. `mwe/` shows it with two four-line
  functions: `clang -arch x86_64 -O2 main.c f.s g.s` crashes;
  with `-Wl,-no_deduplicate`, or `-Wl,-ld_classic`, it prints 1 and 2.
- **Dead stripping.** With `-dead_strip`, a block that no branch refers to is
  removed. The old linker does this too.

On arm64 the kernels do not use the directive, so nothing goes wrong, but
nothing in them can be dead-stripped either, and the directive cannot simply
be added: the assembler refuses a conditional branch to a label that is a
symbol.

The change spells the labels `L(name)`: `.Lname` as before, except on Mach-O,
where it is `Lname`. It then turns the directive on for arm64 Darwin.

## What has to hold

1. **Everywhere but Mach-O, no object changes.** `L(name)` expands to what was
   written before. The only exceptions are the six assembly kernels whose
   labels were symbols on every platform (commit "Make the remaining labels
   ... local"): their code must be the same, with the label symbols gone.
   That commit also touches two C kernels with inline assembly,
   `dznrm2_thunderx2t99_fast.c` and `dgemm_kernel_4x8_skylakex.c`; no KERNEL
   file uses them, so no build compiles them.
2. **On Mach-O, the kernels still compute the same thing**, each kernel object
   defines its entry point and nothing else, and the linker no longer damages
   them.

## Please run on Linux

Point 1 has so far only been checked by cross-assembling from macOS with
clang. It needs a real build with GCC and GNU as:

```sh
git fetch https://github.com/topolarity/OpenBLAS ct/asm-local-labels-verify
git checkout FETCH_HEAD
python3 asm-labels/verify.py <upstream develop> HEAD~1 \
    --config "DYNAMIC_ARCH=1" --config "DYNAMIC_ARCH=1 DYNAMIC_OLDER=1"
```

`<upstream develop>` only has to contain the commit the change is based on
(06365ff18); the merge base is used. For each configuration the script builds
the base and the change, compares the results of make's tests, and compares
every object file. It passes if every object is byte-identical, except those
of the kernels above, which may differ in their symbol table only.

At the end it lists the `.S` files of `kernel/x86_64` (or `kernel/arm64`) that
no configuration compiled. Those are not covered; please add `--config
"TARGET=<core>"` runs for cores that use them where that is practical
(`TARGET=PILEDRIVER` covers `dgemm_kernel_6x4_piledriver.S`, one of those),
and report the list that remains.

On x86_64 Linux and, if there is one, on arm64 Linux (which covers the SVE
kernels that macOS cannot build). Please report the full output, `uname -a`
and the compiler and binutils versions.

Running the tests on AVX2/AVX-512 hardware matters for macOS too: Rosetta has
no AVX, so on macOS those kernels were assembled and compared but never run.
For most of them the new macOS code is byte for byte the Linux code (below),
so Linux running them is the evidence.

## Tools

| Tool | What it does |
|---|---|
| `use_local_label_macro.py` | The generator of the two `Generated-by:` commits: rewrites every `.Lname` token of `kernel/x86_64/*.S` and `kernel/arm64/*.S` to `L(name)`. |
| `verify.py` | Builds base and change and compares every object (above). For ELF and COFF, and arm64 Mach-O. |
| `compare-kernels.py` | macOS: replays the kernel compile commands of an existing build on the old and the new source. Natively, or for an ELF target (`--elf TRIPLE`), or checking that the new Mach-O text is the ELF text (`--like-elf TRIPLE`). |
| `compare-preprocessed.py` | macOS: preprocesses every `.S` file of a kernel directory, used by the build or not, for an ELF target, from the old and the new tree. |
| `find-split-kernels.py` | Looks in a linked x86_64 Mach-O library for branches from one function to a `.L` label inside another: what folding leaves behind. |

## Results on macOS

Apple M4, macOS 26.5.2, Apple clang 21.0.0 (clang-2100.1.1.101, ld-1267),
GNU Fortran 16.1.0; base 06365ff18. x86_64 is built on the same machine
(`arch -x86_64 make ARCH=x86_64 BINARY=64 CC="clang -arch x86_64"
HOSTCC="clang -arch x86_64" NOFORTRAN=1`, with `-march=native` removed from
`GETARCH_FLAGS`) and run under Rosetta, which has no AVX.

The object and text comparisons of the first three tables were made on an
earlier state of the change, which differed from the final one by three
comments in the headers and by the two C kernels that no build compiles.
"End to end" below is a rebuild of 292b50b1e, which lacks only the edit to
`dgemm_kernel_4x8_skylakex.c`.

Cross-assembled for ELF (clang, `x86_64-unknown-linux-gnu` and
`aarch64-unknown-linux-gnu`, with the config headers of the macOS builds and
`OS_LINUX` for `OS_DARWIN`):

| Check | Result |
|---|---|
| every `.S` file preprocesses to the same text | 327 of 333; the other 6 are the kernels with renamed labels |
| those 6: same `.text` | yes, and each is down to 1 symbol |
| kernel objects of a `DYNAMIC_ARCH=1` build, byte for byte | x86_64: 2,619 of 2,619 (8 of them compared as preprocessed text: they do not assemble outside the build, which rewrites `config_kernel.h` for each core); arm64: 476 of 476 |

arm64 macOS, `make DYNAMIC_ARCH=1`:

| Check | Result |
|---|---|
| make's tests | pass: utest 140/140 and 1562/1562, as on develop |
| kernel objects: text unchanged, entry symbol only | 476 of 476 |
| all objects (`verify.py --builds`) | 8,610 of 9,086 byte-identical; the 476 assembly kernels differ in their symbol table only |
| every kernel object has the subsections flag and no label symbol | 2,317 of 2,317 |

x86_64 macOS, `make DYNAMIC_ARCH=1` (14 cores):

| Check | Result |
|---|---|
| make's tests | pass: utest 138/138 and 1539/1539. On develop utest crashes in test 1. |
| every kernel object has no label symbol | 11,367 of 11,367 |
| new Mach-O text is the ELF text | 2,205 of 2,619 objects. 406 are extended-precision (x87) kernels; the one examined differs only by `ffreep`, which `common_x86_64.h` replaces by `fstp` on Darwin. 8 could not be replayed (as above). |

The Mach-O text of the x86_64 kernels does change: a branch to a label that
is a symbol is assembled in its long form with a relocation, and to a local
label in its short form, as on ELF.

End to end, on 292b50b1e:

| Check | Result |
|---|---|
| `verify.py upstream/develop <change> --config "DYNAMIC_ARCH=1"` (arm64) | 3 of 3: builds, make's tests match the base, 8,610 of 9,086 objects byte-identical and the 476 assembly kernels differ in their symbol table only |
| `make lapack-test` (arm64) | 5,438,659 tests, no errors |
| `openblas_utest` relinked with `-Wl,-dead_strip` (arm64) | 140/140 with each of ARMV8, NEOVERSEN1, VORTEXM4 |
| `cmake -DDYNAMIC_ARCH=ON`, ctest (arm64) | 116 of 116 |
| x86_64 `make DYNAMIC_ARCH=1` | make's tests pass (138/138, 1539/1539); 0 of 11,367 kernel objects have a label symbol |
| x86_64 size programs with `-dead_strip` | all run correctly (and all still link every kernel: without #6088 nothing can be pruned) |

With the dispatch split (OpenMathLib/OpenBLAS#6088) on top, static links with
`-dead_strip` (text size; every program runs correctly unless marked):

| arm64 | develop | #6088 | #6088 + this |
|---|---|---|---|
| runtime only | 4.50 MB | 2.41 MB | 0.007 MB |
| `dgemm` | 4.52 MB | 2.52 MB | 0.17 MB |
| `dgesv` + `daxpy` + `dgemv` + `dnrm2` | 4.51 MB | 2.66 MB | 0.32 MB |
| every `cblas_d*` | 4.72 MB | 3.11 MB | 0.99 MB |

| x86_64 | develop | #6088 | #6088 + this |
|---|---|---|---|
| runtime only | 33.2 MB | 0.03 MB | 0.03 MB |
| `dgemm` | 33.2 MB (broken) | 0.57 MB (broken) | 0.80 MB |
| `dgesv` + `daxpy` + `dgemv` + `dnrm2` | 33.2 MB (broken) | 3.19 MB (broken) | 3.54 MB |
| every `cblas_d*` | 33.4 MB | 5.93 MB | 7.06 MB |

`openblas_utest` of that combination, relinked with `-Wl,-dead_strip`, passes
on arm64 (140/140 with each of ARMV8, NEOVERSEN1, VORTEXM4) and on x86_64
(138/138).

Prebuilt x86_64 macOS libraries of 0.3.34 (PyPI `scipy-openblas64`, Julia's
`OpenBLAS_jll`, conda-forge `libopenblas`) all have the label symbols, and
`find-split-kernels.py` finds no folded block in any of them (2,581 functions
in the utest of the develop build above): they were linked by older linkers.

## Not covered

- Linux and Windows builds (see "Please run on Linux").
- The kernel sources that no macOS build uses: 20 of `kernel/arm64` (SVE,
  ThunderX2, Cortex-A53/A72, 4x4 generic), about 80 of `kernel/x86_64`. They
  were only compared after preprocessing.
- AVX kernels were never run on macOS.
- cmake and `make lapack-test` on x86_64 (no x86_64 Fortran compiler here).
- `verify.py`'s check that only the kernels with renamed labels lose symbols:
  it is skipped on Mach-O, so it has never run.
- `kernel/x86` (32-bit) has the same labels and the same directive in
  `common_x86.h`; it is not touched.
- Older Apple linkers: only ld-1267 and its `-ld_classic` were tried.
