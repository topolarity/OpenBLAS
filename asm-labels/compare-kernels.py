#!/usr/bin/env python3
"""Check that the assembly kernels assemble to the same code from two source
trees, by replaying the kernel compile commands of an existing build.

Usage: compare-kernels.py BUILD_DIR OLD_TREE NEW_TREE ARCH [--elf TRIPLE | --like-elf TRIPLE]

BUILD_DIR  a tree built with "make ... > build.log 2>&1" (its config.h and
           other generated headers are used for both sides)
OLD_TREE, NEW_TREE  source trees (git worktrees or exports)
ARCH       x86_64 or arm64: the kernel directory to check

Every distinct "cc -c ... ../kernel/ARCH/x.S -o y.o" command of build.log is
run on the old and on the new source.  Natively (Mach-O), the text sections
must be identical, and the new object must define no symbol but its entry
points.  With --elf TRIPLE the commands are rerun for that target, with
OS_LINUX instead of OS_DARWIN in config.h, and the objects must be identical
byte for byte (or, where the old source does not assemble for that target
with this build's flags, the preprocessed sources).

On x86_64 the Mach-O text itself changes: a branch to a label that is a
symbol is assembled in its long form, with a relocation, and to a local label
in its short form.  --like-elf TRIPLE checks instead that the text of the new
Mach-O object is the text of the same source assembled for TRIPLE, where the
labels always were local.
"""

import concurrent.futures
import glob
import os
import re
import shlex
import shutil
import subprocess
import sys
import tempfile


def headers(build, tree, dest, elf):
    """The headers of TREE plus the generated ones of BUILD, in DEST."""
    os.makedirs(dest)
    for h in glob.glob(os.path.join(build, "*.h")):
        shutil.copy(h, dest)
    for h in glob.glob(os.path.join(tree, "*.h")):
        shutil.copy(h, dest)
    if elf:
        for p in glob.glob(os.path.join(dest, "config*.h")):
            if True:
                with open(p) as f:
                    s = f.read()
                with open(p, "w") as f:
                    f.write(s.replace("OS_DARWIN", "OS_LINUX"))


def main():
    args = sys.argv[1:]
    elf = like_elf = None
    if "--elf" in args:
        i = args.index("--elf")
        elf = args[i + 1]
        del args[i:i + 2]
    if "--like-elf" in args:
        i = args.index("--like-elf")
        like_elf = args[i + 1]
        del args[i:i + 2]
    build, old, new, arch = args
    build, old, new = (os.path.abspath(p) for p in (build, old, new))
    work = tempfile.mkdtemp()
    for side, tree in (("old", old), ("new", new)):
        headers(build, tree, os.path.join(work, "hdr-" + side), elf)
    if like_elf:
        headers(build, new, os.path.join(work, "hdr-elf"), like_elf)

    def text_of(obj, section):
        dump = subprocess.run(["objdump", "-s", "-j", section, obj], capture_output=True, text=True).stdout
        out = []
        for line in dump.split("Contents of section", 1)[-1].splitlines()[1:]:
            out.append(line[1:].split(" ", 1)[1][:36].replace(" ", "") if line.startswith(" ") else "")
        return "".join(out)

    src_re = re.compile(r"(?:\S*/)?kernel/%s/(\w+\.S)$" % arch)
    commands = {}
    with open(os.path.join(build, "build.log"), errors="replace") as f:
        for line in f:
            if f"kernel/{arch}/" not in line or " -c " not in line:
                continue
            try:
                words = shlex.split(line)
            except ValueError:
                continue
            srcs = [w for w in words if src_re.match(w)]
            if len(srcs) != 1 or "-o" not in words:
                continue
            out = words[words.index("-o") + 1]
            commands.setdefault(out, (words, srcs[0]))

    def run(item):
        out, (words, src) = item
        name = src_re.match(src).group(1)
        objs = {}
        sides = [("old", old, elf), ("new", new, elf)] + ([("elf", new, like_elf)] if like_elf else [])
        for side, tree, elf_ in sides:
            obj = os.path.join(work, f"{side}-{out}")
            cmd = []
            skip = False
            for w in words:
                if skip:
                    skip = False
                    continue
                if w == "-o":
                    skip = True
                elif w == src:
                    cmd.append(os.path.join(tree, "kernel", arch, name))
                elif w in ("-I..", "-I../.."):
                    pass
                elif elf_ and w == "-arch":
                    skip = True
                elif elf_ and w.startswith("-DASMNAME=_"):
                    cmd.append("-DASMNAME=" + w[len("-DASMNAME=_"):])   # no leading underscore on ELF
                else:
                    cmd.append(w)
            cmd += ["-w", "-I", os.path.join(work, "hdr-" + side), "-o", obj]
            if elf_:
                cmd.insert(1, "--target=" + elf_)
            r = subprocess.run(cmd, capture_output=True, text=True, cwd=os.path.join(build, "kernel"))
            if r.returncode != 0 and elf and side == "old":
                # Not assemblable for this target with these flags, before or
                # after: compare what the assembler would have been given.
                pre = {}
                for side2, tree2 in (("old", old), ("new", new)):
                    c = [w.replace(tree, tree2).replace("hdr-old", "hdr-" + side2) for w in cmd]
                    c[c.index("-c")] = "-E"
                    c[c.index("-o") + 1] = "-"
                    pre[side2] = subprocess.run(c + ["-P"], capture_output=True, text=True,
                                                cwd=os.path.join(build, "kernel")).stdout
                return out, name, None if pre["old"] and pre["old"] == pre["new"] else "preprocessed sources differ"
            if r.returncode != 0:
                if side == "elf":
                    continue
                return out, name, f"{side} does not assemble: " + r.stderr.strip().splitlines()[0][:150]
            objs[side] = obj
        if like_elf:
            syms = [l.split()[-1] for l in
                    subprocess.run(["nm", objs["new"]], capture_output=True, text=True).stdout.splitlines()
                    if len(l.split()) == 3 and not l.split()[-1].startswith("ltmp")]
            if len(syms) != 1:
                return out, name, "symbols besides the entry: " + " ".join(syms[:8])
            if "elf" not in objs:
                return out, name, "does not assemble for " + like_elf
            if text_of(objs["new"], "__text") != text_of(objs["elf"], ".text"):
                return out, name, "text differs from the ELF text"
            return out, name, None
        if elf:
            with open(objs["old"], "rb") as a, open(objs["new"], "rb") as b:
                same = a.read() == b.read()
            return out, name, None if same else "objects differ"
        text = {s: subprocess.run(["otool", "-t", o], capture_output=True, text=True).stdout.split("\n", 1)[1]
                for s, o in objs.items()}
        if text["old"] != text["new"]:
            return out, name, "text differs"
        syms = [l.split()[-1] for l in
                subprocess.run(["nm", objs["new"]], capture_output=True, text=True).stdout.splitlines()
                if len(l.split()) == 3 and l.split()[1] in "tTsSdD" and not l.split()[-1].startswith("ltmp")]
        extra = [s for s in syms if not re.match(r"_\w+$", s) or len(syms) > 1 and s.startswith(".")]
        if len(syms) > 1 or extra:
            return out, name, "symbols besides the entry: " + " ".join(syms[:8])
        return out, name, None

    with concurrent.futures.ThreadPoolExecutor(os.cpu_count()) as pool:
        results = list(pool.map(run, sorted(commands.items())))
    shutil.rmtree(work)
    bad = [(o, n, why) for o, n, why in results if why]
    by_source = {}
    for o, n, why in bad:
        by_source.setdefault((n, why), []).append(o)
    for (n, why), outs in sorted(by_source.items()):
        print(f"{n}: {why}  ({len(outs)} objects, e.g. {outs[0]})")
    target = elf or ("native, like " + like_elf if like_elf else "native")
    print(f"{arch} {target}: {len(results) - len(bad)} of {len(results)} objects the same, "
          f"from {len({n for _, n, _ in results})} source files")
    sys.exit(1 if bad else 0)


if __name__ == "__main__":
    main()
