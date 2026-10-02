#!/usr/bin/env python3
"""Look in a linked x86_64 Mach-O library for kernels that the linker has
taken apart.

Usage: find-split-kernels.py LIBRARY

Reports
  * how many ".L" label symbols the library has (labels that the assembler
    kept as symbols; 0 if the library was stripped of local symbols, in
    which case nothing more can be said from the symbol table);
  * branches from one function into the middle of another, at a ".L" label:
    the mark of a block that was folded into an identical one elsewhere;
  * functions whose last ".L" block is not followed by the next function's
    code but has no return either cannot be seen this way, so the count is a
    lower bound.
"""
import bisect, re, subprocess, sys

lib = sys.argv[1]
syms = []
for line in subprocess.run(["nm", "-n", "-arch", "x86_64", lib], capture_output=True, text=True).stdout.splitlines():
    p = line.split()
    if len(p) == 3 and p[1] in "tT":
        syms.append((int(p[0], 16), p[2]))
labels = [s for s in syms if s[1].startswith(".L")]
funcs = [s for s in syms if not s[1].startswith(".L") and not s[1].startswith("L")]
print(f"{lib}: {len(funcs)} function symbols, {len(labels)} .L label symbols")
if not labels:
    sys.exit(0)
faddr = [a for a, _ in funcs]
label_at = dict(labels)

def owner(addr):
    i = bisect.bisect_right(faddr, addr) - 1
    return funcs[i][1] if i >= 0 else None

dis = subprocess.run(["objdump", "-d", "--no-show-raw-insn", lib],
                     capture_output=True, text=True).stdout
branch = re.compile(r"^\s*([0-9a-f]+):\s+(j[a-z]+)\s+0x([0-9a-f]+)")
hits = {}
for line in dis.splitlines():
    m = branch.match(line)
    if not m:
        continue
    src, target = int(m.group(1), 16), int(m.group(3), 16)
    if target in label_at and owner(src) != owner(target):
        hits.setdefault(owner(src), set()).add(f"{label_at[target]} in {owner(target)}")
print(f"functions that branch to a .L label inside another function: {len(hits)}")
for f in sorted(hits)[:15]:
    print(f"  {f} -> {', '.join(sorted(hits[f])[:3])}")
