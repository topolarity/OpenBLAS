#!/bin/sh
# Link small programs statically against an OpenBLAS build, with
# --gc-sections, and print for each the size of its text and how many
# per-core functions (kernels, named <name>_<CORE>) it links.
#
#   runtime   calls only openblas_get_num_threads(): cpu detection and the
#             runtime, no BLAS.  With the split it should link (almost) no
#             per-core functions; without it, it links all of them.
#   dgemm     cblas_dgemm only
#   solver    dgesv, daxpy, dgemv, dnrm2
#   alld      every cblas_d* routine, by address
#
# Usage: measure-size.sh BUILD_DIR
# CC and LDLIBS (default "-lgfortran -lpthread -lm") override the compiler
# and the libraries the programs are linked with.
set -eu
build=$(realpath "$1")
CC=${CC:-cc}
LDLIBS=${LDLIBS:--lgfortran -lpthread -lm}
work=$(mktemp -d)
trap 'rm -rf "$work"' EXIT

# Mach-O: ld64 spells --gc-sections -dead_strip, C symbols carry a leading
# "_", and size has no -A.
if [ "$(uname -s)" = Darwin ]; then
  gc=-Wl,-dead_strip us=_
  text_size() { size -m "$1" | awk '$1 == "Section" && $2 == "__text:" {print $3; exit}'; }
else
  gc=-Wl,--gc-sections us=
  text_size() { size -A "$1" | awk '$1 == ".text" {print $2}'; }
fi

cat > "$work/runtime.c" <<'EOF'
extern int openblas_get_num_threads(void);
int main(void) { return openblas_get_num_threads() < 1; }
EOF

cat > "$work/dgemm.c" <<'EOF'
#include <cblas.h>
int main(void) {
  double a[4] = {1, 2, 3, 4}, b[4] = {1, 0, 0, 1}, c[4];
  cblas_dgemm(CblasColMajor, CblasNoTrans, CblasNoTrans, 2, 2, 2, 1.0, a, 2, b, 2, 0.0, c, 2);
  return c[0] != 1;
}
EOF

cat > "$work/solver.c" <<'EOF'
#include <cblas.h>
extern void dgesv_(int *, int *, double *, int *, int *, double *, int *, int *);
int main(void) {
  int n = 2, one = 1, ipiv[2], info;
  double a[4] = {4, 1, 1, 3}, b[2] = {1, 2}, y[2] = {0, 0};
  dgesv_(&n, &one, a, &n, ipiv, b, &n, &info);
  cblas_daxpy(2, 1.0, b, 1, y, 1);
  cblas_dgemv(CblasColMajor, CblasNoTrans, 2, 2, 1.0, a, 2, b, 1, 0.0, y, 1);
  return info != 0 || cblas_dnrm2(2, y, 1) < 0;
}
EOF

# Every double-precision CBLAS routine, by address.
nm -g --defined-only "$build"/libopenblas.a 2>/dev/null | awk -v us="$us" '$3 ~ "^" us "cblas_d[a-z0-9_]*$" {print substr($3, length(us) + 1)}' | sort -u > "$work/syms"
{
  echo '#include <stdio.h>'
  sed 's/.*/extern void &(void);/' "$work/syms"
  echo 'void (*const fns[])(void) = {'
  sed 's/.*/  &,/' "$work/syms"
  echo '};'
  echo 'int main(void) {'
  echo '  for (unsigned i = 0; i < sizeof(fns) / sizeof(fns[0]); i++) printf("%p\\n", (void *)fns[i]);'
  echo '  return 0;'
  echo '}'
} > "$work/alld.c"

# The cores of the build, from its per-core parameter tables.
cores=$(ls "$build"/kernel/setparam_*.o | sed 's/.*setparam_\(.*\)\.o$/\1/' | paste -sd'|' -)

printf '%-8s %14s %20s\n' program "text bytes" "per-core functions"
for p in runtime dgemm solver alld; do
  # shellcheck disable=SC2086
  $CC -O2 -I"$build" "$work/$p.c" -o "$work/$p" $gc "$build"/libopenblas.a $LDLIBS
  "$work/$p" > /dev/null
  text=$(text_size "$work/$p")
  per_core=$(nm "$work/$p" | awk -v cores="$cores" '$2 ~ /^[tT]$/ && $3 ~ "_(" cores ")$"' | wc -l | tr -d ' ')
  printf '%-8s %14s %20s\n' "$p" "$text" "$per_core"
done
