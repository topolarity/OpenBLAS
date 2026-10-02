#!/bin/sh
# Compare every object file of two OpenBLAS build trees.
# Usage: compare-builds.sh OLD_BUILD_DIR NEW_BUILD_DIR
# Prints the objects that differ or exist on one side only.
set -eu
old=$1 new=$2
(cd "$old" && find . -name '*.o' | sort) > "${TMPDIR:-/tmp}/old.$$"
(cd "$new" && find . -name '*.o' | sort) > "${TMPDIR:-/tmp}/new.$$"
comm -23 "${TMPDIR:-/tmp}/old.$$" "${TMPDIR:-/tmp}/new.$$" | sed 's/^/only in old: /'
comm -13 "${TMPDIR:-/tmp}/old.$$" "${TMPDIR:-/tmp}/new.$$" | sed 's/^/only in new: /'
comm -12 "${TMPDIR:-/tmp}/old.$$" "${TMPDIR:-/tmp}/new.$$" | while read -r o; do
    cmp -s "$old/$o" "$new/$o" || echo "differs: $o"
done
echo "$(wc -l < "${TMPDIR:-/tmp}/new.$$") objects compared"
rm -f "${TMPDIR:-/tmp}/old.$$" "${TMPDIR:-/tmp}/new.$$"
