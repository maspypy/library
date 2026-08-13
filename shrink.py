#!/usr/bin/env python3
"""Conservative post-processor for a single-file competitive-programming source.

This intentionally is not a C++ optimiser.  It removes expander artefacts and
top-level functions that are unreachable by a token-level dependency graph.
It keeps macros, aliases, constexpr objects, classes, operators,
specialisations and overload groups intact.
The final compiler check is mandatory unless --no-check is given.
"""

from __future__ import annotations

import argparse
import os
import re
import shlex
import subprocess
import sys
import tempfile
from collections import defaultdict, deque
from dataclasses import dataclass
from pathlib import Path


IDENT_RE = re.compile(r"[A-Za-z_][A-Za-z_0-9]*")
ARTIFACT_RE = re.compile(r"// (?:BEGIN|END):")
BEGIN_RE = re.compile(r"^\s*// BEGIN: (.+?)\s*$")
END_RE = re.compile(r"// END: (.+?)\s*$")
LINE_RE = re.compile(r"^\s*#\s*line\b")
LINE_FILE_RE = re.compile(r'^\s*#\s*line\s+\d+\s+"([^"]+)"')
DEFINE_RE = re.compile(r"^\s*#\s*define\s+([A-Za-z_]\w*)")
USING_RE = re.compile(r"^\s*using\s+([A-Za-z_]\w*)\s*=")
CONST_RE = re.compile(
    r"\bconstexpr\s+(?:auto|[A-Za-z_]\w*(?:\s*<[^;={}>]*>)?)\s+([A-Za-z_]\w*)\s*="
)


@dataclass(frozen=True)
class Candidate:
    start: int
    end: int
    name: str
    kind: str


def code_view(line: str) -> str:
    """Replace strings and comments with spaces, preserving positions roughly."""
    out: list[str] = []
    i = 0
    quote = ""
    while i < len(line):
        c = line[i]
        if quote:
            out.append(" ")
            if c == "\\" and i + 1 < len(line):
                out.append(" ")
                i += 2
                continue
            if c == quote:
                quote = ""
            i += 1
            continue
        if c in "\"'":
            quote = c
            out.append(" ")
            i += 1
        elif c == "/" and i + 1 < len(line) and line[i + 1] == "/":
            out.extend(" " * (len(line) - i))
            break
        else:
            out.append(c)
            i += 1
    return "".join(out)


def code_views(lines: list[str]) -> list[str]:
    """Like code_view(), but also tracks block comments across line boundaries."""
    out: list[str] = []
    in_block = False
    for line in lines:
        chars = list(code_view(line))
        i = 0
        while i < len(line):
            if in_block:
                chars[i] = " "
                if line.startswith("*/", i):
                    chars[i: i + 2] = [" ", " "]
                    i += 2
                    in_block = False
                else:
                    i += 1
            elif line.startswith("/*", i):
                chars[i: i + 2] = [" ", " "]
                i += 2
                in_block = True
            else:
                i += 1
        out.append("".join(chars))
    return out


def brace_delta(line: str) -> int:
    view = code_view(line)
    return view.count("{") - view.count("}")


def remove_known_inactive(lines: list[str], undefined: set[str]) -> list[str]:
    """Resolve only #if defined(NAME) / #ifdef NAME for explicitly absent names."""
    out: list[str] = []
    # (parent_is_output, condition_known, chosen_branch, this_branch_is_output)
    stack: list[tuple[bool, bool, bool, bool]] = []
    current = True
    known_if = re.compile(
        r"^\s*#\s*if\s+(?:defined\s*\(\s*([A-Za-z_]\w*)\s*\)|defined\s+([A-Za-z_]\w*))\s*$")
    known_if_not = re.compile(
        r"^\s*#\s*if\s*!\s*defined\s*\(\s*([A-Za-z_]\w*)\s*\)\s*$")
    ifdef = re.compile(r"^\s*#\s*ifdef\s+([A-Za-z_]\w*)\s*$")
    ifndef = re.compile(r"^\s*#\s*ifndef\s+([A-Za-z_]\w*)\s*$")
    for line in lines:
        defined = DEFINE_RE.match(line)
        if current and defined:
            undefined.discard(defined.group(1))
        m_not = known_if_not.match(line) or ifndef.match(line)
        m_yes = known_if.match(line) or ifdef.match(line)
        if m_not or m_yes:
            name = next(x for x in (m_not or m_yes).groups() if x is not None)
            if name in undefined:
                value = bool(m_not)
                stack.append((current, True, value, current and value))
                current = current and value
                continue
            stack.append((current, False, False, current))
            if current:
                out.append(line)
            continue
        if re.match(r"^\s*#\s*else\b", line) and stack:
            parent, known, chosen, _ = stack[-1]
            if known:
                current = parent and not chosen
                stack[-1] = (parent, known, True, current)
                continue
            current = parent
            if current:
                out.append(line)
            continue
        if re.match(r"^\s*#\s*endif\b", line) and stack:
            parent, known, _, _ = stack.pop()
            current = parent
            if not known and current:
                out.append(line)
            continue
        if current:
            out.append(line)
    return out


def strip_artifacts(lines: list[str]) -> list[str]:
    out = []
    for line in lines:
        if LINE_RE.match(line):
            continue
        m = ARTIFACT_RE.search(line)
        if m:
            line = line[:m.start()].rstrip() + \
                ("\n" if line.endswith("\n") else "")
        if line.strip():
            out.append(line)
    return out


def strip_header_comments(lines: list[str]) -> list[str]:
    """Remove ordinary comments only while inside an expanded include file."""
    out: list[str] = []
    stack: list[str] = []
    current_file = ""
    in_block = False
    for line in lines:
        file_match = LINE_FILE_RE.match(line)
        if file_match:
            current_file = file_match.group(1)
            out.append(line)
            continue
        begin = BEGIN_RE.match(line)
        end = END_RE.match(line)
        if begin:
            stack.append(begin.group(1))
            current_file = begin.group(1)
            out.append(line)
            continue
        if end:
            out.append(line)
            if stack:
                stack.pop()
            if stack:
                current_file = stack[-1]
            continue
        in_header = current_file != "main.cpp"
        if not in_header and not in_block:
            out.append(line)
            continue
        chars = list(line)
        i = 0
        quote = ""
        while i < len(chars):
            if in_block:
                if chars[i] != "\n":
                    chars[i] = " "
                if line.startswith("*/", i):
                    chars[i: i + 2] = [" ", " "]
                    i += 2
                    in_block = False
                else:
                    i += 1
                continue
            c = chars[i]
            if quote:
                if c == "\\" and i + 1 < len(chars):
                    i += 2
                    continue
                if c == quote:
                    quote = ""
                i += 1
                continue
            if c in "\"'":
                quote = c
                i += 1
            elif line.startswith("//", i):
                for j in range(i, len(chars)):
                    if chars[j] != "\n":
                        chars[j] = " "
                break
            elif line.startswith("/*", i):
                chars[i: i + 2] = [" ", " "]
                i += 2
                in_block = True
            else:
                i += 1
        out.append("".join(chars))
    return out


def find_semicolon(lines: list[str], views: list[str], start: int) -> int | None:
    depth = 0
    for i in range(start, len(lines)):
        view = views[i]
        for c in view:
            if c in "({[":
                depth += 1
            elif c in ")} ]".replace(" ", ""):
                depth -= 1
            elif c == ";" and depth == 0:
                return i
    return None


def find_function_end(lines: list[str], views: list[str], start: int) -> int | None:
    """Find a function body, ignoring braces in parameters and attributes."""
    paren_depth = 0
    bracket_depth = 0
    brace_depth = 0
    seen_body = False
    for i in range(start, len(lines)):
        view = views[i]
        for c in view:
            if not seen_body:
                if c == "(":
                    paren_depth += 1
                elif c == ")":
                    paren_depth -= 1
                elif c == "[":
                    bracket_depth += 1
                elif c == "]":
                    bracket_depth -= 1
                elif c == "{" and paren_depth == 0 and bracket_depth == 0:
                    brace_depth = 1
                    seen_body = True
            elif c == "{":
                brace_depth += 1
            elif c == "}":
                brace_depth -= 1
                if brace_depth == 0:
                    return i
    return None


def function_name(prefix: str) -> str | None:
    if "operator" in prefix or re.search(r"(?:^|\n)\s*(?:class|struct|union|enum)\b", prefix):
        return None
    paren = prefix.rfind("(")
    if paren < 0:
        return None
    left = prefix[:paren]
    names = IDENT_RE.findall(left)
    if not names:
        return None
    name = names[-1]
    if name in {"if", "for", "while", "switch", "catch"}:
        return None
    return name


def find_candidates(lines: list[str]) -> list[Candidate]:
    ans: list[Candidate] = []
    views = code_views(lines)
    depth = 0
    i = 0
    while i < len(lines):
        line = lines[i]
        view = views[i]
        if depth != 0:
            depth += view.count("{") - view.count("}")
            i += 1
            continue
        m = DEFINE_RE.match(line)
        if m:
            end = i
            while lines[end].rstrip().endswith("\\") and end + 1 < len(lines):
                end += 1
            # Macro expansion and token pasting are deliberately outside this
            # tool's safety envelope.  Preserve every macro definition.
            i = end + 1
            continue
        if view.lstrip().startswith("#"):
            i += 1
            continue
        # Do not begin a function candidate on an arbitrary declaration: doing
        # so can swallow a preceding `using` until the next function body.
        if not view.lstrip().startswith("template") and not ("(" in view and "{" in view):
            # This branch still has to maintain scope depth.  Otherwise a
            # class declaration is skipped without entering its scope and its
            # members are later mistaken for top-level functions.
            depth += view.count("{") - view.count("}")
            i += 1
            continue
        # Function and variable templates may start with one or more template lines.
        start = i
        probe = i
        while probe < len(lines) and views[probe].lstrip().startswith("template"):
            probe += 1
        header = "".join(views[start: min(len(lines), probe + 4)])
        brace = header.find("{")
        if brace >= 0:
            prefix = header[:brace]
            name = function_name(prefix)
            end = find_function_end(lines, views, start)
            if name and end is not None:
                # Functions entered implicitly by the runtime (notably
                # __attribute__((destructor))) have no ordinary source-level
                # call site.  Keep every attribute-bearing definition.
                if "__attribute__" in "".join(views[start: end + 1]):
                    i = end + 1
                    continue
                ans.append(Candidate(start, end, name, "function"))
                i = end + 1
                continue
        depth += view.count("{") - view.count("}")
        i += 1
    return ans


def identifiers(lines: list[str]) -> set[str]:
    return set(IDENT_RE.findall("\n".join(code_view(x) for x in lines)))


def remove_unreachable(lines: list[str]) -> tuple[list[str], list[Candidate]]:
    candidates = find_candidates(lines)
    by_name: dict[str, list[Candidate]] = defaultdict(list)
    occupied = [False] * len(lines)
    for c in candidates:
        by_name[c.name].append(c)
        for i in range(c.start, c.end + 1):
            occupied[i] = True
    names = set(by_name)
    roots = identifiers(
        [line for i, line in enumerate(lines) if not occupied[i]]) & names
    # The C++ entry point is necessarily live even though no source token calls it.
    roots.add("main")
    deps: dict[str, set[str]] = defaultdict(set)
    for c in candidates:
        used = identifiers(lines[c.start: c.end + 1]) & names
        used.discard(c.name)
        deps[c.name].update(used)
    live: set[str] = set()
    que = deque(roots)
    while que:
        name = que.popleft()
        if name in live:
            continue
        live.add(name)
        que.extend(deps[name] - live)
    removed = [c for c in candidates if c.name not in live]
    dead_line = [False] * len(lines)
    for c in removed:
        for i in range(c.start, c.end + 1):
            dead_line[i] = True
    return [line for i, line in enumerate(lines) if not dead_line[i]], removed


def check(command: str, path: Path) -> None:
    rendered = command.format(file=shlex.quote(str(path)))
    result = subprocess.run(rendered, shell=True, text=True,
                            stdout=subprocess.PIPE, stderr=subprocess.PIPE)
    if result.returncode:
        sys.stderr.write(result.stdout)
        sys.stderr.write(result.stderr)
        raise RuntimeError(f"compile check failed: {rendered}")


def main() -> int:
    parser = argparse.ArgumentParser(
        description="Conservatively shrink an expanded C++ source.")
    parser.add_argument("input", type=Path)
    parser.add_argument("-o", "--output", type=Path,
                        help="write to this file (default: standard output)")
    parser.add_argument("--undefined", default="USE_PCH,LOCAL",
                        help="comma-separated macros known to be undefined")
    parser.add_argument(
        "--check", default="g++ -std=c++20 -O2 -mavx2 -mpopcnt -fsyntax-only {file}")
    parser.add_argument("--no-check", action="store_true",
                        help="skip baseline and final compiler checks")
    parser.add_argument("--report", action="store_true")
    args = parser.parse_args()
    source = args.input.read_text()
    undefined = {x for x in args.undefined.split(",") if x}
    lines = source.splitlines(keepends=True)
    lines = remove_known_inactive(lines, undefined)
    lines, removed = remove_unreachable(lines)
    lines = strip_header_comments(lines)
    lines = strip_artifacts(lines)
    result = "".join(lines)
    if not result.endswith("\n"):
        result += "\n"

    if not args.no_check:
        check(args.check, args.input)
    temp_dir = args.output.parent if args.output else None
    if args.output:
        args.output.parent.mkdir(parents=True, exist_ok=True)
    with tempfile.NamedTemporaryFile("w", encoding="utf-8", delete=False, dir=temp_dir, suffix=".cpp") as f:
        f.write(result)
        temporary = Path(f.name)
    try:
        if not args.no_check:
            check(args.check, temporary)
        if args.output:
            os.replace(temporary, args.output)
        else:
            sys.stdout.write(result)
            temporary.unlink()
    except Exception:
        temporary.unlink(missing_ok=True)
        raise
    if args.report:
        print(f"{len(source.encode())} -> {len(result.encode())} bytes; removed {len(removed)} declarations", file=sys.stderr)
        for c in removed:
            print(f"  {c.kind:9} {c.name}", file=sys.stderr)
    return 0


if __name__ == "__main__":
    try:
        raise SystemExit(main())
    except RuntimeError as e:
        print(f"shrink.py: {e}", file=sys.stderr)
        raise SystemExit(1)
