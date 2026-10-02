#!/bin/sh
# Check that two versions of kernel/setparam-ref.c compile to identical
# objects, for every core of an existing DYNAMIC_ARCH build and for several
# BUILD_* / feature configurations beyond the one that was built.
#
# Usage: compare-setparam.sh BUILD_DIR OLD_SETPARAM_REF_C NEW_SETPARAM_REF_C
#
# BUILD_DIR is a tree built with "make DYNAMIC_ARCH=1 ... > build.log 2>&1";
# the per-core compile commands are replayed from build.log.
set -eu
build=$1 old=$(realpath "$2") new=$(realpath "$3")
work=$(mktemp -d)
trap 'rm -rf "$work"' EXIT

# One configuration per line; the empty first line is the configuration
# that was built.
variants="
-DBUILD_BFLOAT16=1 -DBUILD_HFLOAT16=1
-UBUILD_SINGLE -UBUILD_COMPLEX -UBUILD_COMPLEX16
-UBUILD_DOUBLE -UBUILD_COMPLEX -UBUILD_COMPLEX16
-UBUILD_SINGLE -UBUILD_DOUBLE -UBUILD_COMPLEX16
-UBUILD_SINGLE -UBUILD_DOUBLE -UBUILD_COMPLEX
-USMALL_MATRIX_OPT -UEXPRECISION"

cd "$build/kernel"
grep -E -- ' setparam_[A-Z0-9_]+\.c -o ' ../build.log | sort -u | while read -r cmd; do
    core=$(echo "$cmd" | sed -E 's/.* setparam_([A-Z0-9_]+)\.c -o .*/\1/')
    echo "$variants" | while read -r extra; do
        for v in old new; do
            eval src=\$$v
            sed "s/TS/_$core/g" "$src" > "$work/setparam_$core.c"
            # Compile in place (for the relative include paths), from the
            # scratch copy of the source.
            eval "$(echo "$cmd" | sed -E "s# setparam_$core\.c -o [^ ]+# -I. -w $extra $work/setparam_$core.c -o $work/$v.o#")"
        done
        if cmp -s "$work/old.o" "$work/new.o"; then
            echo "same      $core $extra"
        else
            echo "DIFFERENT $core $extra"
        fi
    done
done | tee "$work/log"
! grep -q DIFFERENT "$work/log"
