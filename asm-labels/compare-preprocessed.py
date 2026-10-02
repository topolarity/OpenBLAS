#!/usr/bin/env python3
"""Check that every .S file of a kernel directory preprocesses to the same
text from two source trees, for an ELF target (where L(name) is .Lname).

Usage: compare-preprocessed.py BUILD_DIR OLD_TREE NEW_TREE ARCH TRIPLE

Unlike compare-kernels.py this covers the files that the build in BUILD_DIR
did not use (other cores, SVE, ...): it does not assemble anything, and only
needs BUILD_DIR for its generated headers.  Each file is tried with the four
combinations of DOUBLE and COMPLEX.
"""
import concurrent.futures, glob, itertools, os, shutil, subprocess, sys, tempfile

build, old, new, arch, triple = sys.argv[1:]
work = tempfile.mkdtemp()
for side, tree in (("old", old), ("new", new)):
    d = os.path.join(work, side); os.makedirs(d)
    for h in glob.glob(os.path.join(build, "*.h")) + glob.glob(os.path.join(tree, "*.h")):
        shutil.copy(h, d)
    for p in glob.glob(os.path.join(d, "config*.h")):
        s = open(p).read(); open(p, "w").write(s.replace("OS_DARWIN", "OS_LINUX"))

def pre(side, tree, name, defs):
    r = subprocess.run(["clang", "--target=" + triple, "-E", "-P", "-w", "-DASMNAME=f", "-DASMFNAME=f_",
                        "-DNAME=f_", "-DCNAME=f", *defs, "-I", os.path.join(work, side),
                        os.path.join(tree, "kernel", arch, name)], capture_output=True, text=True)
    return r.returncode, r.stdout

def check(name):
    out = []
    for defs in itertools.product(("-UDOUBLE", "-DDOUBLE"), ("-UCOMPLEX", "-DCOMPLEX")):
        a, b = pre("old", old, name, defs), pre("new", new, name, defs)
        out.append("same" if a == b and a[0] == 0 else "error" if a[0] or b[0] else "DIFFERENT")
    return name, out

names = sorted(os.path.basename(p) for p in glob.glob(os.path.join(new, "kernel", arch, "*.S")))
with concurrent.futures.ThreadPoolExecutor(os.cpu_count()) as pool:
    results = list(pool.map(check, names))
shutil.rmtree(work)
bad = [(n, o) for n, o in results if "DIFFERENT" in o or "same" not in o]
for n, o in bad:
    print(n, " ".join(o))
print(f"{arch}: {len(results) - len(bad)} of {len(results)} files preprocess to the same text")
sys.exit(1 if bad else 0)
