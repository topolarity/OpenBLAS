#!/usr/bin/env python3
"""Label every entry of the gotoblas_t initializer in kernel/setparam-ref.c
with the field it initializes.

The initializer is positional: about 1300 entries, inside two dozen nested
#if blocks, that line up with the fields of gotoblas_t in common_param.h only
by order.  This script rewrites it with designated initializers, one entry
per line.  Values, conditionals and order stay exactly as they were, so the
compiled tables do not change:

    gotoblas_t TABLE_NAME = {             gotoblas_t TABLE_NAME = {
      1, 2,                                 .p = 1,
    #ifdef BUILD_X                          .q = 2,
      x_kernelTS,                  ==>    #ifdef BUILD_X
    #endif                                  .x_kernel = x_kernelTS,
      copyTS,                             #endif
    };                                      .copy = copyTS,
                                          };

How entries are matched with fields
-----------------------------------
A "guard macro" is any macro that a condition inside the gotoblas_t struct
tests: BUILD_SINGLE, BUILD_BFLOAT16, SMALL_MATRIX_OPT, ARCH_ARM64, and so on.
For every combination of guard macros being defined or not (1024 of them),
the script works out which fields and which entries the preprocessor keeps,
and pairs them in order, just as the compiler does.

Conditionals in the initializer that test anything else, such as
"#if SGEMM_DEFAULT_UNROLL_M != SGEMM_DEFAULT_UNROLL_N", choose between
alternative values for the same fields, so each of their branches must hold
the same number of entries, and an entry is paired by its position in its
branch.

Every entry must be paired with the same field in every combination in which
it is compiled; the script stops with an error otherwise, and also if a
condition uses anything beyond the simple forms these files use.

This file also provides the model of #if blocks that split_dispatch_groups.py
uses.  The examples below run as tests: python3 -m doctest add_explicit_inits.py

Usage: dispatch-split/add_explicit_inits.py [OPENBLAS_SOURCE_DIR]
"""

import collections
import functools
import itertools
import os
import re
import sys

COMMON_PARAM = "common_param.h"
SETPARAM = os.path.join("kernel", "setparam-ref.c")


# --- #if blocks ------------------------------------------------------------
#
# The struct and the initializer are runs of one-item lines interleaved with
# #if/#ifdef/#ifndef/#elif/#else/#endif.  They are parsed into a tree whose
# nodes are either line numbers (index into the list of lines) or
# Conditionals.

Branch = collections.namedtuple("Branch", "line condition body")


class Conditional:
    """One #if ... #endif block.

    branches: a Branch(line, condition, body) per #if/#elif/#else, where
        condition is a C expression ("1" for #else, "defined(X)" for
        #ifdef X) and body is the list of nodes inside the branch.
    endif: the line number of the #endif.
    """

    def __init__(self):
        self.branches = []
        self.endif = None


def parse_conditionals(lines, start=0, stop=None):
    """Parse lines[start:stop] into a list of nodes.

    >>> nodes = parse_conditionals(["a", "#ifdef X", "b", "#else", "c", "#endif"])
    >>> nodes[0], [(b.line, b.condition, b.body) for b in nodes[1].branches], nodes[1].endif
    (0, [(1, 'defined(X)', [2]), (3, '1', [4])], 5)
    """
    stop = len(lines) if stop is None else stop
    root = []
    bodies = [root]      # the body being filled at each nesting level
    open_blocks = []
    for i in range(start, stop):
        m = re.match(r"\s*#\s*(\w+)\s*(.*?)\s*(//.*)?$", lines[i])
        keyword, argument = (m.group(1), m.group(2)) if m else (None, None)
        if keyword in ("if", "ifdef", "ifndef"):
            condition = {"if": argument,
                         "ifdef": f"defined({argument})",
                         "ifndef": f"!defined({argument})"}[keyword]
            block = Conditional()
            block.branches.append(Branch(i, condition, []))
            bodies[-1].append(block)
            open_blocks.append(block)
            bodies.append(block.branches[-1].body)
        elif keyword in ("elif", "else"):
            block = open_blocks[-1]
            block.branches.append(Branch(i, argument if keyword == "elif" else "1", []))
            bodies[-1] = block.branches[-1].body
        elif keyword == "endif":
            open_blocks.pop().endif = i
            bodies.pop()
        elif keyword is not None:
            raise ValueError(f"line {i + 1}: unexpected #{keyword}")
        else:
            bodies[-1].append(i)
    if open_blocks:
        raise ValueError("unterminated #if")
    return root


# --- Conditions --------------------------------------------------------------
#
# A configuration is the set of guard macros that are defined; each is taken
# to be either undefined or defined to 1, which is how BUILD_*, ARCH_* and
# the feature macros are set.  Conditions are evaluated by the small parser
# below, which knows only the forms these files use and rejects anything
# else:  NAME, NUMBER, NAME == NUMBER, NAME != NUMBER, defined(NAME),
# defined NAME, !, &&, || and parentheses.

def macros(condition):
    """The macro names a condition tests.

    >>> sorted(macros("(BUILD_SINGLE==1) || !defined(ARCH_ARM64)"))
    ['ARCH_ARM64', 'BUILD_SINGLE']
    """
    return set(re.findall(r"\b[A-Za-z_]\w*\b", condition)) - {"defined"}


def all_configurations(guard_macros):
    """Every subset of guard_macros, as a frozenset of the defined ones."""
    names = sorted(guard_macros)
    for chosen in itertools.product((False, True), repeat=len(names)):
        yield frozenset(n for n, on in zip(names, chosen) if on)


@functools.lru_cache(maxsize=None)
def evaluate(condition, configuration):
    """Whether condition holds when exactly the macros in configuration are
    defined (to 1).

    >>> evaluate("(BUILD_SINGLE == 1) || defined(BUILD_DOUBLE)", frozenset({"BUILD_DOUBLE"}))
    True
    >>> evaluate("!defined(ARCH_ARM64) && BUILD_SINGLE", frozenset({"ARCH_ARM64", "BUILD_SINGLE"}))
    False
    >>> evaluate("BUILD_SINGLE + 1", frozenset())
    Traceback (most recent call last):
    ValueError: unsupported condition: 'BUILD_SINGLE + 1'
    """
    tokens = re.findall(r"\s*(defined|[A-Za-z_]\w*|\d+|==|!=|&&|\|\||[!()]|\S)", condition)
    position = 0

    def peek():
        return tokens[position] if position < len(tokens) else None

    def take(expected=None):
        nonlocal position
        token = peek()
        if token is None or (expected is not None and token != expected):
            raise ValueError(f"unsupported condition: {condition!r}")
        position += 1
        return token

    def either():           # a || b || ...
        value = both()
        while peek() == "||":
            take()
            value = both() or value
        return value

    def both():             # a && b && ...
        value = comparison()
        while peek() == "&&":
            take()
            value = comparison() and value
        return value

    def comparison():       # a == b, a != b, or just a
        value = negation()
        if peek() in ("==", "!="):
            op = take()
            other = negation()
            value = int(value == other) if op == "==" else int(value != other)
        return value

    def negation():         # !a
        if peek() == "!":
            take()
            return int(not negation())
        return operand()

    def operand():
        token = take()
        if token == "(":
            value = either()
            take(")")
            return value
        if token == "defined":
            parenthesized = peek() == "("
            if parenthesized:
                take("(")
            name = take()
            if parenthesized:
                take(")")
            return int(name in configuration)
        if token.isdigit():
            return int(token)
        if re.fullmatch(r"[A-Za-z_]\w*", token):
            return int(token in configuration)
        raise ValueError(f"unsupported condition: {condition!r}")

    value = either()
    if peek() is not None:
        raise ValueError(f"unsupported condition: {condition!r}")
    return bool(value)


def guard_macros_of(nodes):
    """Every macro tested by any condition in a tree."""
    found = set()
    for node in nodes:
        if isinstance(node, Conditional):
            for branch in node.branches:
                found |= macros(branch.condition) | guard_macros_of(branch.body)
    return found


def compiled_lines(nodes, configuration):
    """The line numbers that the preprocessor keeps under configuration."""
    kept = []
    for node in nodes:
        if isinstance(node, Conditional):
            for branch in node.branches:
                if evaluate(branch.condition, configuration):
                    kept += compiled_lines(branch.body, configuration)
                    break
        else:
            kept.append(node)
    return kept


# --- The gotoblas_t struct and its initializer -------------------------------

def struct_fields(lines):
    """Find the gotoblas_t struct of common_param.h (the one under
    #ifdef DYNAMIC_ARCH).

    Returns (first line, last line, tree of the body, fields), where first and
    last are the "typedef struct {" and "} gotoblas_t;" lines and fields maps
    each declaration line to the field names it declares.

    >>> first, last, tree, fields = struct_fields([
    ...     "#ifdef DYNAMIC_ARCH", "typedef struct {", "  int p, q;",
    ...     "  int (*copy)(BLASLONG, double *);", "} gotoblas_t;"])
    >>> first, last, fields
    (1, 4, {2: ['p', 'q'], 3: ['copy']})
    """
    first = next(i for i, l in enumerate(lines) if l.startswith("#ifdef DYNAMIC_ARCH"))
    first = next(i for i in range(first, len(lines)) if lines[i].startswith("typedef struct {"))
    last = next(i for i in range(first, len(lines)) if lines[i].startswith("} gotoblas_t;"))
    fields = {}
    for i in range(first + 1, last):
        code = re.sub(r"/\*.*?\*/", "", lines[i]).split("//")[0].strip()
        if not code or code.startswith("#"):
            continue
        if not code.endswith(";") or "/*" in code:
            raise ValueError(f"{COMMON_PARAM}:{i + 1}: cannot parse {lines[i]!r}")
        function_pointer = re.search(r"\(\s*\*\s*(\w+)\s*\)", code)
        if function_pointer:
            fields[i] = [function_pointer.group(1)]
        else:
            names = re.match(r"(?:\w+\s+)+?(\w+(?:\s*,\s*\w+)*)\s*;$", code).group(1)
            fields[i] = [n.strip() for n in names.split(",")]
    return first, last, parse_conditionals(lines, first + 1, last), fields


def split_entries(code):
    """The comma-terminated entries on one initializer line.

    >>> split_entries("  MAX(A, B), copyTS,")
    ['MAX(A, B)', 'copyTS']
    """
    entries, depth, current = [], 0, ""
    for ch in code:
        if ch == "," and depth == 0:
            entries.append(current.strip())
            current = ""
            continue
        depth += (ch == "(") - (ch == ")")
        current += ch
    if current.strip():
        raise ValueError(f"entry without trailing comma: {code!r}")
    return entries


def initializer_entries(lines):
    """Find the gotoblas_t initializer of setparam-ref.c.

    Returns (tree of the body, entries, comments), where entries maps each
    line to the entries on it and comments maps a line to its trailing
    // comment."""
    first = next(i for i, l in enumerate(lines) if l.startswith("gotoblas_t TABLE_NAME = {"))
    last = next(i for i in range(first, len(lines)) if lines[i].startswith("};"))
    entries, comments = {}, {}
    for i in range(first + 1, last):
        code, has_comment, comment = lines[i].partition("//")
        if code.strip().startswith("#") or not code.strip():
            continue
        if "/*" in code:
            raise ValueError(f"{SETPARAM}:{i + 1}: block comment in initializer")
        entries[i] = split_entries(code)
        if has_comment:
            comments[i] = "//" + comment
    return parse_conditionals(lines, first + 1, last), entries, comments


def initialized_positions(nodes, configuration, entries, guard_macros):
    """Under configuration, the initializer as a list with one item per
    initialized position: the entries, written (line, index on the line),
    that may fill that position.

    A conditional on guard macros is resolved; one that tests anything else
    chooses between alternatives, whose branches must all hold the same
    number of entries, so that the k-th entry of every branch fills the same
    position:

    >>> lines = ["  1, 2,", "#if UNROLL_M != UNROLL_N", "  a,", "#else", "  b,", "#endif"]
    >>> nodes = parse_conditionals(lines)
    >>> entries = {0: ["1", "2"], 2: ["a"], 4: ["b"]}
    >>> initialized_positions(nodes, frozenset(), entries, guard_macros=set())
    [[(0, 0)], [(0, 1)], [(2, 0), (4, 0)]]
    """
    positions = []
    for node in nodes:
        if not isinstance(node, Conditional):
            positions += [[(node, k)] for k in range(len(entries.get(node, [])))]
            continue
        tested = set().union(*(macros(b.condition) for b in node.branches))
        if tested <= guard_macros:
            for branch in node.branches:
                if evaluate(branch.condition, configuration):
                    positions += initialized_positions(branch.body, configuration, entries, guard_macros)
                    break
            continue
        if tested & guard_macros:
            raise ValueError(f"line {node.branches[0].line + 1}: condition mixes "
                             "field guards with value choices")
        alternatives = [initialized_positions(b.body, configuration, entries, guard_macros)
                        for b in node.branches]
        if len(node.branches) == 1 or node.branches[-1].condition != "1":
            alternatives.append([])  # the implicit empty #else
        if len({len(a) for a in alternatives}) != 1:
            raise ValueError(f"line {node.branches[0].line + 1}: alternative branches "
                             "initialize different numbers of fields")
        positions += [sum(column, []) for column in zip(*alternatives)]
    return positions


def add_labels(param_lines, setparam_lines):
    """Return setparam-ref.c with every gotoblas_t initializer labelled.

    >>> param = '''#ifdef DYNAMIC_ARCH
    ... typedef struct {
    ...   int p, q;
    ... #if BUILD_X == 1
    ...   int (*x_kernel)(void);
    ... #endif
    ...   int (*copy)(void);
    ... } gotoblas_t;'''.split("\\n")
    >>> setparam = '''gotoblas_t TABLE_NAME = {
    ...   1, 2, // tuning
    ... #ifdef BUILD_X
    ... #if UNROLL_M != UNROLL_N
    ...   x_kernel_aTS,
    ... #else
    ...   x_kernel_bTS,
    ... #endif
    ... #endif
    ...   copyTS,
    ... };'''.split("\\n")
    >>> print("\\n".join(add_labels(param, setparam)))
    gotoblas_t TABLE_NAME = {
      .p = 1,
      .q = 2, // tuning
    #ifdef BUILD_X
    #if UNROLL_M != UNROLL_N
      .x_kernel = x_kernel_aTS,
    #else
      .x_kernel = x_kernel_bTS,
    #endif
    #endif
      .copy = copyTS,
    };
    """
    _, _, struct, fields = struct_fields(param_lines)
    initializer, entries, comments = initializer_entries(setparam_lines)
    guard_macros = guard_macros_of(struct)

    label = {}
    for configuration in all_configurations(guard_macros):
        compiled_fields = [f for i in compiled_lines(struct, configuration) for f in fields.get(i, [])]
        positions = initialized_positions(initializer, configuration, entries, guard_macros)
        if len(compiled_fields) != len(positions):
            raise ValueError(f"{len(positions)} initializers for {len(compiled_fields)} fields "
                             f"with {sorted(configuration)} defined")
        for field, position in zip(compiled_fields, positions):
            for entry in position:
                if label.setdefault(entry, field) != field:
                    raise ValueError(f"{SETPARAM}:{entry[0] + 1}: entry initializes both "
                                     f"{label[entry]} and {field}, depending on configuration")

    out = []
    for i, line in enumerate(setparam_lines):
        if i not in entries:
            out.append(line)
            continue
        indent = re.match(r"\s*", line).group(0)
        labelled = []
        for k, value in enumerate(entries[i]):
            if (i, k) not in label:
                raise ValueError(f"{SETPARAM}:{i + 1}: entry {value!r} is never compiled")
            labelled.append(f"{indent}.{label[(i, k)]} = {value},")
        if i in comments:
            labelled[-1] += " " + comments[i]
        out += labelled
    return out


def main():
    top = sys.argv[1] if len(sys.argv) > 1 else "."
    with open(os.path.join(top, COMMON_PARAM)) as f:
        param_lines = f.read().split("\n")
    with open(os.path.join(top, SETPARAM)) as f:
        setparam_lines = f.read().split("\n")
    out = add_labels(param_lines, setparam_lines)
    with open(os.path.join(top, SETPARAM), "w") as f:
        f.write("\n".join(out))
    print(f"labelled the gotoblas_t initializer of {SETPARAM}")


if __name__ == "__main__":
    main()
