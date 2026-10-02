#!/usr/bin/env python3
"""Verify the L(name) change on this machine: build the base and the change
and compare every object file.

Usage: asm-labels/verify.py BASE NEW [options]

  BASE, NEW      git refs: the upstream commit the change is based on (the
                 merge base is used), and the change.  Run from the OpenBLAS
                 repository.
  --work DIR     where to build (default: a new directory under $TMPDIR)
  --jobs N       make -j (default: the number of CPUs)
  --config A     make arguments of a configuration to build (repeatable;
                 default: one configuration, "DYNAMIC_ARCH=1")
  --builds B N   compare two existing build trees instead of building

Wherever L(name) is .Lname - everywhere but on Mach-O - the change must not
alter the contents of any object.  Each object of the change is therefore
compared with the base's: byte for byte, and where that fails, section by
section ("objdump -s", which leaves out the symbol table).  The only objects
allowed to differ at all are those of the kernels whose labels used to be
symbols (HAND_EDITED below), and only in their symbol table.

Also reports whether the tests run by make gave the same results, and which
kernel sources of kernel/x86_64 and kernel/arm64 no configuration compiled:
those are not covered.

On x86_64 Mach-O the code itself changes (see VERIFY.md), so this check does
not apply there; use compare-kernels.py.
"""

import argparse
import concurrent.futures
import glob
import os
import re
import shlex
import shutil
import subprocess
import sys
import tempfile

HAND_EDITED = ("dgemm_kernel_6x4_piledriver.S", "nrm2.S", "znrm2.S", "zscal.S",
               "sgemm_direct_sme1_2VLx2VL.S", "sgemm_direct_sme1_preprocess.S",
               "dznrm2_thunderx2t99_fast.c", "dgemm_kernel_4x8_skylakex.c")
results = []


def report(check, passed, detail=""):
    results.append((check, passed))
    print(f"{'PASS' if passed else 'FAIL'}  {check}" + (f": {detail}" if detail else ""), flush=True)


def git(*args):
    return subprocess.run(["git", *args], check=True, capture_output=True, text=True).stdout


def export(ref, directory):
    os.makedirs(directory)
    archive = subprocess.Popen(["git", "archive", ref], stdout=subprocess.PIPE)
    subprocess.run(["tar", "-x", "-C", directory], stdin=archive.stdout, check=True)
    archive.wait()


def test_summary(directory):
    with open(os.path.join(directory, "build.log"), errors="replace") as f:
        log = f.read()
    return (log.count("PASSED"), re.findall(r"RESULTS: \d+ tests \(\d+ ok, \d+ failed, \d+ skipped\)", log))


def sources(directory):
    """{object name: source file name} for the kernel objects, and the set of
    kernel sources compiled, from build.log."""
    by_object, compiled = {}, set()
    with open(os.path.join(directory, "build.log"), errors="replace") as f:
        for line in f:
            m = re.search(r"kernel/(x86_64|arm64)/([\w.]+\.[Sc])\b.* -o (\S+)", line)
            if m:
                by_object[os.path.basename(m.group(3))] = m.group(2)
                compiled.add(m.group(1) + "/" + m.group(2))
    return by_object, compiled


def contents(obj):
    dump = subprocess.run(["objdump", "-s", obj], capture_output=True, text=True).stdout
    return dump.split("\n", 2)[-1]   # without the line that names the file


def compare(label, base, new):
    objects = sorted(os.path.relpath(p, new) for p in glob.glob(os.path.join(new, "**", "*.o"), recursive=True))
    missing = [o for o in objects if not os.path.exists(os.path.join(base, o))]
    by_object, compiled = sources(new)

    def one(o):
        a, b = os.path.join(base, o), os.path.join(new, o)
        if not os.path.exists(a):
            return o, "missing"
        with open(a, "rb") as f, open(b, "rb") as g:
            if f.read() == g.read():
                return o, "identical"
        return o, "symbols" if contents(a) == contents(b) else "DIFFERENT"

    with concurrent.futures.ThreadPoolExecutor(os.cpu_count()) as pool:
        outcome = dict(pool.map(one, objects))
    different = [o for o, r in outcome.items() if r == "DIFFERENT"]
    symbols = [o for o, r in outcome.items() if r == "symbols"]
    unexpected = [o for o in symbols if by_object.get(os.path.basename(o)) not in HAND_EDITED]
    report(f"{label} no object's contents changed", not different and not missing,
           f"{sum(r == 'identical' for r in outcome.values())} of {len(objects)} objects byte-identical, "
           f"{len(symbols)} differ in their symbol table only"
           + (f"; DIFFERENT: {' '.join(different[:8])}" if different else "")
           + (f"; not in the base: {' '.join(missing[:8])}" if missing else ""))
    if sys.platform == "darwin":
        # On Mach-O every label was a symbol, so every assembly kernel loses some.
        print(f"      {label} {len(symbols)} objects lost label symbols (expected on Mach-O)", flush=True)
    else:
        report(f"{label} only the kernels with renamed labels lost symbols", not unexpected,
               " ".join(sorted({by_object.get(os.path.basename(o), o) for o in symbols})) or "none built"
               if not unexpected else "unexpected: " + " ".join(unexpected[:8]))
    return compiled


def main():
    p = argparse.ArgumentParser(description=__doc__, formatter_class=argparse.RawDescriptionHelpFormatter)
    p.add_argument("base", nargs="?")
    p.add_argument("new", nargs="?")
    p.add_argument("--work")
    p.add_argument("--jobs", type=int, default=os.cpu_count())
    p.add_argument("--config", action="append", default=[])
    p.add_argument("--builds", nargs=2, metavar=("BASE_BUILD", "NEW_BUILD"))
    a = p.parse_args()

    compiled = set()
    if a.builds:
        compiled |= compare("[existing builds]", *a.builds)
        tree = a.builds[1]
    else:
        new = git("rev-parse", a.new).strip()
        base = git("merge-base", a.base, new).strip()
        work = a.work or tempfile.mkdtemp(prefix="asm-labels-verify.")
        print(f"base {base[:10]}, new {new[:10]}, building in {work}", flush=True)
        for config in a.config or ["DYNAMIC_ARCH=1"]:
            label = f"[{config}]"
            dirs = {k: os.path.join(work, re.sub(r"[^\w.-]+", "_", f"{config}-{k}")) for k in ("base", "new")}
            procs = {}
            for k, ref in (("base", base), ("new", new)):
                if os.path.exists(dirs[k]):
                    shutil.rmtree(dirs[k])
                export(ref, dirs[k])
                log = open(os.path.join(dirs[k], "build.log"), "w")
                procs[k] = subprocess.Popen(["make", f"-j{max(1, a.jobs // 2)}", *shlex.split(config)],
                                            cwd=dirs[k], stdout=log, stderr=subprocess.STDOUT)
            status = {k: proc.wait() for k, proc in procs.items()}
            if status["base"] != 0:
                print(f"SKIP  {label}: the base does not build either (exit {status['base']})", flush=True)
                continue
            report(f"{label} builds", status["new"] == 0)
            if status["new"] != 0:
                continue
            before, after = test_summary(dirs["base"]), test_summary(dirs["new"])
            report(f"{label} make's tests match the base", before == after and all(", 0 failed" in r for r in after[1]),
                   f"{after[0]} PASSED lines, {'; '.join(after[1])}")
            compiled |= compare(label, dirs["base"], dirs["new"])
        tree = dirs["new"]

    for arch in ("x86_64", "arm64"):
        every = {arch + "/" + os.path.basename(f) for f in glob.glob(os.path.join(tree, "kernel", arch, "*.S"))}
        used = every & compiled
        if used:
            rest = sorted(every - compiled)
            print(f"kernel/{arch}: {len(used)} of {len(every)} .S files were compiled; not covered: "
                  + (" ".join(os.path.basename(r) for r in rest) if rest else "none"), flush=True)

    failed = [c for c, ok in results if not ok]
    print(f"\n{len(results) - len(failed)} of {len(results)} checks passed"
          + ("" if not failed else ";  FAILED: " + "; ".join(failed)))
    sys.exit(1 if failed else 0)


if __name__ == "__main__":
    main()
