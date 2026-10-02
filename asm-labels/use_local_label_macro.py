#!/usr/bin/env python3
"""Spell the assembler-local labels of the assembly kernels L(name).

Usage: use_local_label_macro.py [REPO] [DIR ...]

Rewrites every ".Lname" token in the .S files of the given kernel
directories (default: kernel/x86_64 kernel/arm64) to "L(name)".  L() is
defined in common_x86_64.h and common_arm64.h as ".L##x", or "L##x" on
Mach-O, where ".L" is not the assembler's prefix for local labels.

Nothing else is changed, so wherever L(name) expands to .Lname the
preprocessed source, and the object, is the same as before.

Files that do not include common.h cannot use the macro and are left alone;
they are listed at the end.
"""

import glob
import os
import re
import sys

# ".L" followed by a name, and not itself the tail of a longer token.
LABEL = re.compile(r"(?<![A-Za-z0-9_.$])\.L([A-Za-z0-9_]+)")


def main():
    repo = sys.argv[1] if len(sys.argv) > 1 else "."
    dirs = sys.argv[2:] or ["kernel/x86_64", "kernel/arm64"]
    files = labels = 0
    skipped = []
    for d in dirs:
        for path in sorted(glob.glob(os.path.join(repo, d, "*.S"))):
            with open(path, encoding="latin-1", newline="") as f:
                text = f.read()
            if not LABEL.search(text):
                continue
            if '#include "common.h"' not in text:
                skipped.append(os.path.relpath(path, repo))
                continue
            text, n = LABEL.subn(r"L(\1)", text)
            with open(path, "w", encoding="latin-1", newline="") as f:
                f.write(text)
            files += 1
            labels += n
    print(f"{labels} labels in {files} files")
    for path in skipped:
        print(f"left alone (no common.h): {path}")


if __name__ == "__main__":
    main()
