#!/usr/bin/env python3
"""Check that two DYNAMIC_ARCH builds dispatch identically.

For every core of each build, dump what each of its dispatch tables holds:
the symbol name of every kernel pointer, and the value of every tuning
parameter after the core's init() has run.  Kernels are read from
gotoblas_<CORE> or, after the split, the way a kernel call reads them:
openblas_<group>_dispatch[gotoblas_<CORE>.core]; on a split build every core's
index is also checked to be distinct and in range.  The dumps of the two
builds must match line for line.

CC and LDLIBS (default "-lgfortran -lpthread -lm") override the compiler and
the libraries the probe is linked with.

Usage: compare-tables.py OLD_BUILD_DIR NEW_BUILD_DIR

Both trees must have been built with "make DYNAMIC_ARCH=1 > build.log 2>&1".
"""

import glob
import os
import re
import shlex
import subprocess
import sys
import tempfile

CC = os.environ.get("CC", "cc")
LDLIBS = os.environ.get("LDLIBS", "-lgfortran -lpthread -lm").split()


def compile_flags(build):
    """The flags the build used for its common objects (memory.c)."""
    with open(os.path.join(build, "build.log")) as f:
        for line in f:
            if " memory.c " not in line:
                continue
            words = shlex.split(line)
            if "memory.c" in words and "-c" in words:
                return [w for w in words[1:words.index("memory.c")]
                        if w != "-c" and not w.startswith("-I")]
    raise SystemExit(f"{build}: no compile line for memory.c in build.log")


def structs(build, flags, work):
    """{type name: [(field, is_pointer)]} for gotoblas_t and every dispatch
    table type, as the build's headers declare them."""
    src = os.path.join(work, "types.c")
    with open(src, "w") as f:
        f.write('#include "common.h"\n')
    pre = subprocess.run(["cc", "-E", "-P", *flags, "-I", build, src],
                         capture_output=True, text=True, check=True).stdout
    out = {}
    for body, name in re.findall(r"typedef struct\s*\{([^{}]*)\}\s*(gotoblas_t|openblas_\w+_dispatch_t)\s*;", pre):
        fields = []
        for decl in body.split(";"):
            decl = " ".join(decl.split())
            if not decl:
                continue
            m = re.search(r"\(\s*\*\s*(\w+)\s*\)", decl)
            if m:
                fields.append((m.group(1), True))
            else:
                names = re.match(r"(?:\w+\s+)+?(\w+(?:\s*,\s*\w+)*)$", decl).group(1)
                fields += [(n.strip(), False) for n in names.split(",")]
        out[name] = fields
    return out


def dump(build, work):
    flags = compile_flags(build)
    types = structs(build, flags, work)
    cores = sorted(re.sub(r".*setparam_(\w+)\.o$", r"\1", p)
                   for p in glob.glob(os.path.join(build, "kernel", "setparam_*.o")))
    split = any(f == "core" for f, _ in types["gotoblas_t"])
    # One run per core (argv[1]), so that a core whose init() this CPU cannot
    # run (e.g. it reads the SVE vector length) does not take the others down
    # with it.  Its kernels are still compared, as read before init().
    lines = ["#include <stdio.h>", "#include <string.h>", '#include "common.h"']
    lines += [f"extern gotoblas_t gotoblas_{core};" for core in cores]
    lines += ["int main(int argc, char **argv) {", '  printf("BASE main %p\\n", (void *)main);']
    if split:
        # Every core's index must be distinct and in range: otherwise two
        # cores would share, or overrun, the per-group arrays.
        lines.append("  int seen[OPENBLAS_NUM_CORES] = {0};")
        for core in cores:
            lines.append(f"  if (gotoblas_{core}.core < 0 || gotoblas_{core}.core >= OPENBLAS_NUM_CORES"
                         f' || seen[gotoblas_{core}.core]++) {{ fprintf(stderr, "bad core index for {core}\\n"); return 1; }}')
    for core in cores:
        prints = {True: [], False: []}
        for type_, fields in types.items():
            if type_ == "gotoblas_t":
                table = f"gotoblas_{core}"
            else:
                # Read the kernels the way a call does: through the group's
                # array, indexed by the core's own index.
                group = type_[len("openblas_"):-len("_dispatch_t")]
                table = f"(*openblas_{group}_dispatch[gotoblas_{core}.core])"
            for field, pointer in fields:
                if field in ("core", "init"):
                    continue
                if pointer:
                    prints[True].append(f'printf("%s{core} {field} %p\\n", pre, (void *){table}.{field});')
                else:
                    prints[False].append(f'printf("{core} {field} %ld\\n", (long){table}.{field});')
        lines.append(f'  if (!strcmp(argv[1], "{core}")) {{')
        lines.append('    const char *pre = "PRE ";')
        lines += ["    " + l for l in prints[True]]
        lines.append(f'    fflush(stdout); gotoblas_{core}.init(); pre = "";')
        lines += ["    " + l for l in prints[True] + prints[False]]
        lines.append("  }")
    lines.append("  return 0;\n}")
    src = os.path.join(work, "probe.c")
    with open(src, "w") as f:
        f.write("\n".join(lines) + "\n")
    lib = [p for p in glob.glob(os.path.join(build, "libopenblas*.a")) if "_p" not in os.path.basename(p)][0]
    exe = os.path.join(work, "probe")
    subprocess.run([CC, *flags, "-w", "-I", build, src, lib, "-o", exe, *LDLIBS], check=True)
    symbols, main_address = {}, None
    for line in subprocess.run(["nm", exe], capture_output=True, text=True, check=True).stdout.splitlines():
        parts = line.split()
        if len(parts) == 3 and parts[1] in "tTwW":
            if sys.platform == "darwin" and parts[2].startswith("_"):
                parts[2] = parts[2][1:]   # Mach-O prefixes C symbols with "_"
            symbols.setdefault(int(parts[0], 16), parts[2])
            if parts[2] == "main":
                main_address = int(parts[0], 16)
    out = []
    for core in cores:
        run = subprocess.run([exe, core], capture_output=True, text=True)
        illegal = run.returncode in (-4, 132)   # SIGILL in the core's init()
        if run.returncode != 0 and not illegal:
            raise SystemExit(f"{build}: probe failed for {core} (exit {run.returncode}): {run.stderr.strip()}")
        if illegal:
            out.append(f"{core} init() illegal_instruction")
        offset = 0
        for line in run.stdout.splitlines():
            if line.startswith("PRE "):
                if not illegal:
                    continue
                line = line[4:]
            core_, field, value = line.split()
            if core_ == "BASE":
                offset = int(value, 16) - main_address   # load offset of a PIE executable
                continue
            if value == "(nil)" or value == "0x0":
                value = "NULL"
            elif value.startswith("0x"):
                value = symbols.get(int(value, 16) - offset, value)
            out.append(f"{core_} {field} {value}")
    return sorted(out)


def main():
    old, new = sys.argv[1], sys.argv[2]
    with tempfile.TemporaryDirectory() as work:
        a = dump(old, work)
        b = dump(new, work)
    if a == b:
        print(f"identical: {len(a)} table entries "
              f"({len({l.split()[0] for l in a})} cores x {len({l.split()[1] for l in a})} fields)")
        return
    import difflib
    sys.stdout.writelines(difflib.unified_diff([l + "\n" for l in a], [l + "\n" for l in b], old, new))
    sys.exit(1)


if __name__ == "__main__":
    main()
