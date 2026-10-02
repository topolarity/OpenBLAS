#!/usr/bin/env python3
"""Split the kernels out of gotoblas_t into one small table per kernel group.

With DYNAMIC_ARCH, gotoblas_t holds every kernel of a core, and the cpu
detection code takes the address of every core's gotoblas_t, so a static link
keeps every kernel of every core.  This script moves the kernels into one
table per group and per core, reached through OPENBLAS_DISPATCH(group), so
that a program links only the groups it calls.  gotoblas_t keeps the tuning
parameters.  The macros it targets (OPENBLAS_DISPATCH, _OFFSET, _BASE and
DEFINE_DISPATCH_TABLE) are written by hand beforehand.

The rules
---------
1. A kernel is a function-pointer field of gotoblas_t, except those in
   NOT_KERNELS.

2. A kernel's group is the first "_"-separated token of its name, after
   skipping any of SKIPPED_PREFIXES: see group_of().

3. For every group G, in the order of their first field:

     common_param.h   typedef struct { <G's fields> } openblas_G_dispatch_t;
                      extern const openblas_G_dispatch_t *const
                          openblas_G_dispatch[OPENBLAS_NUM_CORES];
     setparam-ref.c   const openblas_G_dispatch_t openblas_G_dispatchTS = {
                          <G's initializers> };
     dispatch.c       DEFINE_DISPATCH_TABLE(G)

   Fields and initializers keep their text, order and conditionals; what is
   not a kernel stays in gotoblas_t and its initializer.  Blank and
   comment-only lines inside the struct and the initializer are dropped.

4. Each of those is wrapped in G's guard: the condition under which G has
   any field, which is the OR of the #if lines around each of its fields.
   Usually that is simply the #if around all of them (see Guard).  Inside the
   guard, a conditional that the guard already decides is dropped (see
   filtered()).

5. Everywhere in the tree, the three spellings of a kernel slot F of group G
   are renamed (see rename_kernel_slots()):

     gotoblas -> F     =>  OPENBLAS_DISPATCH(G) -> F
     FUNC_OFFSET(F)    =>  OPENBLAS_DISPATCH_OFFSET(G, F)
     FUNC_BASE(F)      =>  OPENBLAS_DISPATCH_BASE(G)

The examples below run as tests: python3 -m doctest split_dispatch_groups.py

Usage: dispatch-split/split_dispatch_groups.py [OPENBLAS_SOURCE_DIR] [--manifest FILE]

Run it on a clean checkout, after add_explicit_inits.py, which names the field
of every initializer.  --manifest writes the groups, their guards and their
fields, one group per line.
"""

import functools
import os
import re
import sys

sys.path.insert(0, os.path.dirname(os.path.abspath(__file__)))
from add_explicit_inits import (COMMON_PARAM, SETPARAM, Conditional,  # noqa: E402
                                all_configurations, evaluate, guard_macros_of,
                                macros, parse_conditionals, struct_fields)

DISPATCH_C = os.path.join("driver", "others", "dispatch.c")

# Function pointers in gotoblas_t that are not kernels, and stay there.
NOT_KERNELS = {"init"}

# Name prefixes that are not part of a kernel's group.
SKIPPED_PREFIXES = {"sme"}


def group_of(field):
    """The kernel group of a gotoblas_t field.

    >>> group_of("dgemm_kernel"), group_of("dgemm_small_kernel_nn"), group_of("sme_dgemm_kernel")
    ('dgemm', 'dgemm', 'dgemm')
    >>> group_of("idamax_k"), group_of("caxpyc_k")
    ('idamax', 'caxpyc')
    """
    tokens = field.split("_")
    return tokens[1] if tokens[0] in SKIPPED_PREFIXES else tokens[0]


KERNEL_SLOT = re.compile(r"\b(?:(FUNC_OFFSET|FUNC_BASE)\(\s*(\w+)\s*\)|gotoblas(\s*->\s*)(\w+)\b)")


def rename_kernel_slots(text, kernel_groups):
    """Rename every mention of a kernel slot in text (rule 5).

    >>> groups = {"dgemm_kernel": "dgemm", "dgemm_small_kernel_nn": "dgemm"}
    >>> rename_kernel_slots("#define DGEMM_KERNEL gotoblas -> dgemm_kernel", groups)
    '#define DGEMM_KERNEL OPENBLAS_DISPATCH(dgemm) -> dgemm_kernel'
    >>> rename_kernel_slots("FUNC_OFFSET(dgemm_small_kernel_nn) FUNC_BASE(dgemm_small_kernel_nn)", groups)
    'OPENBLAS_DISPATCH_OFFSET(dgemm, dgemm_small_kernel_nn) OPENBLAS_DISPATCH_BASE(dgemm)'
    >>> rename_kernel_slots("gotoblas -> dgemm_p", groups)  # not a kernel
    'gotoblas -> dgemm_p'
    """
    def rename(m):
        macro, field = m.group(1), m.group(2) or m.group(4)
        if field not in kernel_groups:
            return m.group(0)
        group = kernel_groups[field]
        if macro == "FUNC_OFFSET":
            return f"OPENBLAS_DISPATCH_OFFSET({group}, {field})"
        if macro == "FUNC_BASE":
            return f"OPENBLAS_DISPATCH_BASE({group})"
        return f"OPENBLAS_DISPATCH({group}){m.group(3)}{field}"
    return KERNEL_SLOT.sub(rename, text)


# --- Guards ----------------------------------------------------------------

def enclosing_branches(nodes, path=()):
    """For every content line of a tree, the branches it sits in, outermost
    first, as (Conditional, branch index) pairs."""
    found = {}
    for node in nodes:
        if isinstance(node, Conditional):
            for b, branch in enumerate(node.branches):
                found.update(enclosing_branches(branch.body, path + ((node, b),)))
        else:
            found[node] = path
    return found


@functools.lru_cache(maxsize=None)
def chosen_branch(block, configuration):
    """The index of the branch of block that configuration compiles, or None."""
    return next((b for b, branch in enumerate(block.branches)
                 if evaluate(branch.condition, configuration)), None)


class Guard:
    """The condition under which a group has at least one field: the OR, over
    its fields, of the AND of the #if lines around each field.  A term is
    dropped when another term holds in every configuration where it does:
    A || (A && B) is just A, and (A || B) || A is just A || B.

    With a single term the guard is written as the original #if lines;
    otherwise as one #if, as for ssymm, whose ARM64-only fields are guarded
    differently from the others:

    >>> lines = ["#if (BUILD_SINGLE==1)", "  int (*ssymm_iutcopy)(void);", "#endif",
    ...          "#if (BUILD_SINGLE==1) || (BUILD_DOUBLE==1)", "#ifdef ARCH_ARM64",
    ...          "  void (*ssymm_direct_alpha_betaLU)(void);", "#endif", "#endif"]
    >>> tree = parse_conditionals(lines)
    >>> configurations = list(all_configurations(guard_macros_of(tree)))
    >>> guard = Guard([1, 5], enclosing_branches(tree), lines, configurations)
    >>> guard.wrap(["..."])
    ['#if (BUILD_SINGLE==1) || (((BUILD_SINGLE==1) || (BUILD_DOUBLE==1)) && defined(ARCH_ARM64))', '...', '#endif']
    >>> Guard([1], enclosing_branches(tree), lines, configurations).wrap(["..."])
    ['#if (BUILD_SINGLE==1)', '...', '#endif']

    A field under a wider #if than the others makes theirs redundant:

    >>> lines = ["#if (BUILD_SINGLE==1) || (BUILD_DOUBLE==1)", "  int (*ssymm_kernel)(void);", "#endif",
    ...          "#if (BUILD_SINGLE==1)", "  int (*ssymm_iutcopy)(void);", "#endif"]
    >>> tree = parse_conditionals(lines)
    >>> configurations = list(all_configurations(guard_macros_of(tree)))
    >>> Guard([1, 4], enclosing_branches(tree), lines, configurations).wrap(["..."])
    ['#if (BUILD_SINGLE==1) || (BUILD_DOUBLE==1)', '...', '#endif']
    """

    def __init__(self, field_lines, enclosing, lines, configurations):
        self.directive = {}   # condition -> the #if line it came from
        terms = []
        for i in field_lines:
            term = []
            for block, b in enclosing[i]:
                if b != 0:
                    raise ValueError(f"line {block.branches[b].line + 1}: "
                                     "kernel guarded by #else or #elif")
                condition = block.branches[0].condition
                self.directive.setdefault(condition, lines[block.branches[0].line].strip())
                term.append(condition)
            if term not in terms:
                terms.append(term)
        holds = [frozenset(k for k, c in enumerate(configurations)
                           if all(evaluate(x, c) for x in t)) for t in terms]
        self.terms = [t for j, t in enumerate(terms)
                      if not any(k != j and holds[j] <= holds[k] and (holds[j] < holds[k] or k < j)
                                 for k in range(len(terms)))]
        # the configurations in which the group exists
        self.configurations = [c for c in configurations
                               if any(all(evaluate(x, c) for x in t) for t in self.terms)]

    def expression(self):
        """The guard as one C expression, parenthesized only where needed."""
        def parenthesized(x, needed):
            return f"({x})" if needed and ("||" in x or "&&" in x) else x
        return " || ".join(
            parenthesized(" && ".join(parenthesized(x, len(t) > 1) for x in t), len(self.terms) > 1)
            for t in self.terms)

    def wrap(self, body):
        if len(self.terms) == 1:
            term = self.terms[0]
            return [self.directive[x] for x in term] + body + ["#endif"] * len(term)
        return [f"#if {self.expression()}"] + body + ["#endif"]


def filtered(nodes, lines, keep, configurations, guard_macros):
    """The lines of a tree that keep() accepts, with the conditionals around
    them.  A conditional is left out if nothing in it is kept, and replaced by
    its body if it tests only guard macros and every one of configurations
    compiles the same branch of it.

    >>> lines = ["#if A == 1", "x1", "#if B == 1", "x2", "#endif", "#endif"]
    >>> tree = parse_conditionals(lines)
    >>> with_a = [c for c in all_configurations({"A", "B"}) if "A" in c]
    >>> filtered(tree, lines, lambda i: i == 3, with_a, {"A", "B"})
    ['#if B == 1', 'x2', '#endif']
    """
    out = []
    for node in nodes:
        if not isinstance(node, Conditional):
            if keep(node):
                out.append(lines[node])
            continue
        tested = set().union(*(macros(branch.condition) for branch in node.branches))
        if tested <= guard_macros:
            chosen = {chosen_branch(node, c) for c in configurations}
            if len(chosen) == 1:
                b = chosen.pop()
                if b is not None:
                    out += filtered(node.branches[b].body, lines, keep, configurations, guard_macros)
                continue
        bodies = [filtered(branch.body, lines, keep, configurations, guard_macros)
                  for branch in node.branches]
        if any(bodies):
            for branch, body in zip(node.branches, bodies):
                out.append(lines[branch.line])
                out += body
            out.append(lines[node.endif])
    return out


# --- The files ---------------------------------------------------------------

def rewrite_common_param(lines, first, last, struct, fields, group_lines, guards,
                         configurations, guard_macros):
    """gotoblas_t without its kernels, then one table type per group."""
    kernel_lines = {i for ls in group_lines.values() for i in ls}
    declaration = next(i for i in range(last, len(lines))
                       if lines[i].startswith("extern gotoblas_t *gotoblas;"))
    out = lines[:first + 1]
    parameter_lines = set(fields) - kernel_lines
    out += filtered(struct, lines, parameter_lines.__contains__, configurations, guard_macros)
    out += lines[last:declaration + 1]
    for group, guard in guards.items():
        body = filtered(struct, lines, set(group_lines[group]).__contains__,
                        guard.configurations, guard_macros)
        out += [""] + guard.wrap(
            ["typedef struct {"] + body +
            [f"}} openblas_{group}_dispatch_t;",
             f"extern const openblas_{group}_dispatch_t *const openblas_{group}_dispatch[OPENBLAS_NUM_CORES];"])
    out += lines[declaration + 1:]
    return out


def rewrite_setparam(lines, kernel_groups, guards, configurations, guard_macros):
    """The gotoblas_t initializer without its kernels, then one per-core table
    per group."""
    first = next(i for i, l in enumerate(lines) if l.startswith("gotoblas_t TABLE_NAME = {"))
    last = next(i for i in range(first, len(lines)) if lines[i].startswith("};"))
    initializer = parse_conditionals(lines, first + 1, last)
    field_at = {}   # initializer line -> the field it initializes
    for i in range(first + 1, last):
        m = re.match(r"\s*\.(\w+)\s*=", lines[i])
        if m:
            field_at[i] = m.group(1)
    missing = set(kernel_groups) - set(field_at.values())
    if missing:
        raise ValueError(f"kernels without an initializer: {sorted(missing)}")
    group_at = {i: kernel_groups.get(f) for i, f in field_at.items()}   # None: not a kernel

    out = lines[:first + 1]
    not_kernels = {i for i, g in group_at.items() if g is None}
    out += filtered(initializer, lines, not_kernels.__contains__, configurations, guard_macros)
    out.append(lines[last])
    for group, guard in guards.items():
        lines_of_group = {i for i, g in group_at.items() if g == group}
        body = filtered(initializer, lines, lines_of_group.__contains__,
                        guard.configurations, guard_macros)
        out += [""] + guard.wrap(
            [f"const openblas_{group}_dispatch_t openblas_{group}_dispatchTS = {{"] + body + ["};"])
    out += lines[last + 1:]
    return out


def define_dispatch_tables(lines, guards):
    """dispatch.c with a DEFINE_DISPATCH_TABLE() per group appended."""
    out = list(lines)
    for group, guard in guards.items():
        out += [""] + guard.wrap([f"DEFINE_DISPATCH_TABLE({group})"])
    return out


def rename_in_tree(top, kernel_groups):
    """Apply rename_kernel_slots() to every C source and header of the tree.
    Files are read and written as they are, whatever their line endings or
    encoding.  Returns the number of files changed."""
    changed = 0
    for directory, subdirectories, names in os.walk(top):
        subdirectories[:] = sorted(d for d in subdirectories if not d.startswith("."))
        for name in sorted(n for n in names if n.endswith((".c", ".h"))):
            path = os.path.join(directory, name)
            with open(path, newline="", errors="surrogateescape") as f:
                text = f.read()
            renamed = rename_kernel_slots(text, kernel_groups)
            if renamed != text:
                with open(path, "w", newline="", errors="surrogateescape") as f:
                    f.write(renamed)
                changed += 1
    return changed


def main():
    args = sys.argv[1:]
    manifest = None
    if "--manifest" in args:
        k = args.index("--manifest")
        manifest = args[k + 1]
        del args[k:k + 2]
    top = args[0] if args else "."

    with open(os.path.join(top, COMMON_PARAM)) as f:
        param_lines = f.read().split("\n")
    with open(os.path.join(top, SETPARAM)) as f:
        setparam_lines = f.read().split("\n")
    with open(os.path.join(top, DISPATCH_C)) as f:
        dispatch_lines = f.read().rstrip("\n").split("\n")

    # Rules 1 and 2: the kernels and their groups, in the order of the struct.
    first, last, struct, fields = struct_fields(param_lines)
    kernel_groups = {}   # field -> group
    group_lines = {}     # group -> its declaration lines
    for i, names in fields.items():
        if "(*" in param_lines[i] and names[0] not in NOT_KERNELS:
            kernel_groups[names[0]] = group_of(names[0])
            group_lines.setdefault(group_of(names[0]), []).append(i)

    # Rule 4: the guards.
    guard_macros = guard_macros_of(struct)
    configurations = list(all_configurations(guard_macros))
    enclosing = enclosing_branches(struct)
    guards = {g: Guard(ls, enclosing, param_lines, configurations) for g, ls in group_lines.items()}

    # Rule 3, then rule 5.
    new_param = rewrite_common_param(param_lines, first, last, struct, fields, group_lines,
                                     guards, configurations, guard_macros)
    new_setparam = rewrite_setparam(setparam_lines, kernel_groups, guards, configurations, guard_macros)
    new_dispatch = define_dispatch_tables(dispatch_lines, guards)
    with open(os.path.join(top, COMMON_PARAM), "w") as f:
        f.write("\n".join(new_param))
    with open(os.path.join(top, SETPARAM), "w") as f:
        f.write("\n".join(new_setparam))
    with open(os.path.join(top, DISPATCH_C), "w") as f:
        f.write("\n".join(new_dispatch) + "\n")
    renamed = rename_in_tree(top, kernel_groups)

    if manifest:
        with open(manifest, "w") as f:
            for group, guard in guards.items():
                members = [n for i in group_lines[group] for n in fields[i]]
                f.write(f"{group}\t{guard.expression() or '1'}\t{' '.join(members)}\n")

    print(f"moved {len(kernel_groups)} kernels out of gotoblas_t into {len(group_lines)} groups; "
          f"renamed kernel slots in {renamed} files")


if __name__ == "__main__":
    main()
