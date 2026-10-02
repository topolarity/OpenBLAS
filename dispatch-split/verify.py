#!/usr/bin/env python3
"""Verify the dispatch split on this machine: run every check of VERIFY.md
and report PASS or FAIL for each.

Usage: dispatch-split/verify.py BASE NEW [options]

  BASE, NEW      git refs: the upstream commit the change is based on, and
                 the change (the top of ct/dispatch-split).  Run from the
                 OpenBLAS repository.

  --work DIR     where to build (default: a new directory under $TMPDIR);
                 each build takes about 2 GB
  --jobs N       make -j (default: the number of CPUs)
  --make-args A  extra make arguments for every build, e.g. "TARGET=..."
  --config A     also build with these extra make arguments (repeatable),
                 e.g. --config BUILD_BFLOAT16=1 --config DYNAMIC_OLDER=1;
                 each such configuration gets the build, test and table
                 checks
  --lapack       also run "make lapack-test" on NEW
  --cmake        also build NEW with cmake -DDYNAMIC_ARCH=ON and run ctest
  --target T     also build BASE and NEW without DYNAMIC_ARCH, for TARGET=T,
                 and check that every object is byte-identical

CC and LDLIBS are passed on to the checks that link test programs.
"""

import argparse
import os
import re
import shlex
import shutil
import subprocess
import sys
import tempfile

HERE = os.path.dirname(os.path.abspath(__file__))
results = []   # (check, outcome, detail); outcome is PASS, FAIL or SKIP


def report(check, passed, detail="", skipped=False):
    outcome = "SKIP" if skipped else "PASS" if passed else "FAIL"
    results.append((check, outcome, detail))
    print(f"{outcome}  {check}" + (f": {detail}" if detail else ""), flush=True)


def git(*args, **kw):
    return subprocess.run(["git", *args], check=True, capture_output=True, text=True, **kw).stdout


def export(ref, directory):
    os.makedirs(directory)
    archive = subprocess.Popen(["git", "archive", ref], stdout=subprocess.PIPE)
    subprocess.run(["tar", "-x", "-C", directory], stdin=archive.stdout, check=True)
    archive.wait()


def build(directory, make_args, jobs):
    """make, with the output in build.log, which the checks read."""
    with open(os.path.join(directory, "build.log"), "w") as log:
        return subprocess.Popen(["make", f"-j{jobs}", "DYNAMIC_ARCH=1", *make_args],
                                cwd=directory, stdout=log, stderr=subprocess.STDOUT)


def test_summary(directory):
    """What the tests run by make reported, from build.log."""
    with open(os.path.join(directory, "build.log"), errors="replace") as f:
        log = f.read()
    return {"PASSED lines": log.count("PASSED"),
            "utest": re.findall(r"RESULTS: \d+ tests \(\d+ ok, \d+ failed, \d+ skipped\)", log)}


def utest_outcome(directory, core):
    env = dict(os.environ, OPENBLAS_CORETYPE=core, OPENBLAS_VERBOSE="2")
    try:
        run = subprocess.run(["./openblas_utest"], cwd=os.path.join(directory, "utest"), env=env,
                             capture_output=True, text=True, timeout=1800)
    except subprocess.TimeoutExpired:
        return "timeout"
    if run.returncode in (-4, 132):
        return "illegal instruction"   # this CPU cannot run the core's kernels
    m = re.search(r"RESULTS: \d+ tests \((\d+) ok, (\d+) failed", run.stdout)
    if run.returncode == 0 and m and m.group(2) == "0":
        return f"{m.group(1)} ok"
    return f"failed (exit {run.returncode})"


def run_tool(name, *args):
    return subprocess.run([sys.executable if name.endswith(".py") else "sh",
                           os.path.join(HERE, name), *args], capture_output=True, text=True)


def generated_commit(base, new, script):
    for commit in git("rev-list", f"{base}..{new}").split():
        trailers = git("log", "-1", "--format=%(trailers:key=Generated-by,valueonly)", commit)
        if f"dispatch-split/{script}" in trailers:
            return commit
    return None


def main():
    p = argparse.ArgumentParser(description=__doc__, formatter_class=argparse.RawDescriptionHelpFormatter)
    p.add_argument("base")
    p.add_argument("new")
    p.add_argument("--work")
    p.add_argument("--jobs", type=int, default=os.cpu_count())
    p.add_argument("--make-args", default="")
    p.add_argument("--config", action="append", default=[])
    p.add_argument("--lapack", action="store_true")
    p.add_argument("--cmake", action="store_true")
    p.add_argument("--target")
    a = p.parse_args()

    base = git("rev-parse", a.base).strip()
    new = git("rev-parse", a.new).strip()
    base = git("merge-base", base, new).strip()
    work = a.work or tempfile.mkdtemp(prefix="dispatch-split-verify.")
    make_args = shlex.split(a.make_args)
    print(f"base {base[:10]}, new {new[:10]}, building in {work}", flush=True)

    # 1. The generated commits are exactly what the scripts produce.
    replay = run_tool("replay.sh", base, new)
    report("generated commits reproduce from the scripts",
           replay.returncode == 0 and "same tree as the original" in replay.stdout,
           (replay.stdout + replay.stderr).strip().splitlines()[-1] if replay.returncode else "")
    subprocess.run(["git", "branch", "-D", "dispatch-split-replay"], capture_output=True)

    inits = generated_commit(base, new, "add_explicit_inits.py")
    prep = git("rev-parse", f"{inits}~1").strip() if inits else None

    configurations = [("default", make_args)] + [(c, make_args + shlex.split(c)) for c in a.config]
    for name, args in configurations:
        full = name == "default"
        trees = {"base": base, "new": new}
        if full and prep:
            trees["prep"] = prep
        dirs = {k: os.path.join(work, re.sub(r"[^\w.-]+", "_", f"{name}-{k}")) for k in trees}
        for k, ref in trees.items():
            if os.path.exists(dirs[k]):
                shutil.rmtree(dirs[k])
            export(ref, dirs[k])
        procs = {k: build(dirs[k], args, max(1, a.jobs // len(trees))) for k in trees}
        status = {k: proc.wait() for k, proc in procs.items()}
        label = f"[{name}]"
        if status["base"] != 0:
            report(f"{label} builds", False, f"the base does not build either (exit {status['base']})",
                   skipped=True)
            continue
        report(f"{label} builds", all(s == 0 for s in status.values()),
               ", ".join(f"{k} exit {s}" for k, s in status.items() if s))
        if status["new"] != 0:
            continue

        # 2. The tests run by make give the same results.
        before, after = test_summary(dirs["base"]), test_summary(dirs["new"])
        clean = all(", 0 failed" in r for r in after["utest"])
        report(f"{label} make's tests (ctest, utest) match the base", before == after and clean,
               f"new: {after['PASSED lines']} PASSED lines, {'; '.join(after['utest'])}")

        # 3. Every core dispatches to the same kernels and parameters.
        tables = run_tool("compare-tables.py", dirs["base"], dirs["new"])
        report(f"{label} dispatch tables identical", tables.returncode == 0,
               (tables.stdout.strip().splitlines() or [tables.stderr.strip()])[-1][:200])
        if not full:
            continue

        # 4. The designated initializers compile to identical objects.
        if prep and status.get("prep") == 0:
            with tempfile.TemporaryDirectory() as t:
                old_src, new_src = os.path.join(t, "old.c"), os.path.join(t, "new.c")
                with open(old_src, "w") as f:
                    f.write(git("show", f"{prep}:kernel/setparam-ref.c"))
                with open(new_src, "w") as f:
                    f.write(git("show", f"{inits}:kernel/setparam-ref.c"))
                cmp = run_tool("compare-setparam.sh", dirs["prep"], old_src, new_src)
            lines = cmp.stdout.split("\n")
            same = sum(l.startswith("same") for l in lines)
            report("designated initializers compile to identical setparam objects",
                   cmp.returncode == 0 and same > 0, f"{same} identical, "
                   f"{sum(l.startswith('DIFFERENT') for l in lines)} different")

        # 5. Every core this CPU can run passes utest, as in the base.
        with open(os.path.join(dirs["new"], "dyn_cores.h")) as f:
            cores = re.findall(r"X\((\w+), arg\)", f.read())
        outcomes = {c: (utest_outcome(dirs["base"], c), utest_outcome(dirs["new"], c)) for c in cores}
        runnable = [c for c, (b, n) in outcomes.items() if n.endswith(" ok")]
        report("utest with OPENBLAS_CORETYPE=<core> matches the base for every core",
               all(b == n for b, n in outcomes.values()) and runnable,
               f"pass: {' '.join(runnable)}; "
               + "; ".join(f"{c}: base {b}, new {n}" for c, (b, n) in outcomes.items()
                           if not n.endswith(" ok") or b != n))

        # 6. Static links keep only what they call.
        for k in ("base", "new"):
            size = run_tool("measure-size.sh", dirs[k])
            print(f"static link sizes, {k}:\n{size.stdout}{size.stderr}", flush=True)
        size = run_tool("measure-size.sh", dirs["new"])
        runtime = re.search(r"^runtime\s+\d+\s+(\d+)$", size.stdout, re.M)
        report("a program calling no BLAS links no per-core functions",
               bool(runtime) and runtime.group(1) == "0",
               f"{runtime.group(1) if runtime else '?'} linked")

        if a.lapack:
            with open(os.path.join(dirs["new"], "lapack.log"), "w") as log:
                status = subprocess.run(["make", "lapack-test"], cwd=dirs["new"],
                                        stdout=log, stderr=subprocess.STDOUT).returncode
            with open(os.path.join(dirs["new"], "lapack.log"), errors="replace") as f:
                m = re.search(r"ALL PRECISIONS\s+(\d+)\s+(\d+).*?\s(\d+)\s+\(", f.read())
            report("make lapack-test: no errors", status == 0 and m and m.group(2) == "0" and m.group(3) == "0",
                   f"{m.group(1)} tests, {m.group(2)} numerical errors, {m.group(3)} other" if m else "no summary")

        if a.cmake:
            cdir = os.path.join(work, "cmake-new")
            if os.path.exists(cdir):
                shutil.rmtree(cdir)
            export(new, cdir)
            bdir = os.path.join(cdir, "build")
            os.makedirs(bdir)
            ok = (subprocess.run(["cmake", "..", "-DDYNAMIC_ARCH=ON", "-DBUILD_TESTING=ON",
                                  "-DCMAKE_BUILD_TYPE=Release"], cwd=bdir, capture_output=True).returncode == 0
                  and subprocess.run(["make", f"-j{a.jobs}"], cwd=bdir, capture_output=True).returncode == 0)
            ctest = subprocess.run(["ctest", f"-j{a.jobs}"], cwd=bdir, capture_output=True, text=True) if ok else None
            report("cmake -DDYNAMIC_ARCH=ON builds and passes ctest", bool(ctest) and ctest.returncode == 0,
                   (ctest.stdout.strip().splitlines() or [""])[-3] if ctest else "build failed")

    if a.target:
        dirs = {k: os.path.join(work, f"nodynamic-{k}") for k in ("base", "new")}
        for k, ref in (("base", base), ("new", new)):
            if os.path.exists(dirs[k]):
                shutil.rmtree(dirs[k])
            export(ref, dirs[k])
        procs = {k: subprocess.Popen(["make", f"-j{max(1, a.jobs // 2)}", f"TARGET={a.target}", *make_args],
                                     cwd=d, stdout=subprocess.DEVNULL, stderr=subprocess.DEVNULL)
                 for k, d in dirs.items()}
        if all(proc.wait() == 0 for proc in procs.values()):
            cmp = run_tool("compare-builds.sh", dirs["base"], dirs["new"])
            out = cmp.stdout.strip().splitlines()
            report(f"without DYNAMIC_ARCH (TARGET={a.target}) every object is byte-identical",
                   len(out) == 1 and out[0].endswith("objects compared"), out[-1] if out else cmp.stderr)
        else:
            report(f"without DYNAMIC_ARCH (TARGET={a.target}) builds", False)

    failed = [c for c, outcome, _ in results if outcome == "FAIL"]
    skipped = [c for c, outcome, _ in results if outcome == "SKIP"]
    print(f"\n{len(results) - len(failed) - len(skipped)} of {len(results)} checks passed"
          + (f", {len(skipped)} skipped" if skipped else "")
          + ("" if not failed else ";  FAILED: " + "; ".join(failed)))
    sys.exit(1 if failed else 0)


if __name__ == "__main__":
    main()
