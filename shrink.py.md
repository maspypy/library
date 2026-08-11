---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: py
  _verificationStatusIcon: ':warning:'
  attributes:
    links: []
  bundledCode: "Traceback (most recent call last):\n  File \"/opt/hostedtoolcache/Python/3.12.13/x64/lib/python3.12/site-packages/onlinejudge_verify/documentation/build.py\"\
    , line 71, in _render_source_code_stat\n    bundled_code = language.bundle(stat.path,\
    \ basedir=basedir, options={'include_paths': [basedir]}).decode()\n          \
    \         ^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^\n\
    \  File \"/opt/hostedtoolcache/Python/3.12.13/x64/lib/python3.12/site-packages/onlinejudge_verify/languages/python.py\"\
    , line 96, in bundle\n    raise NotImplementedError\nNotImplementedError\n"
  code: "#!/usr/bin/env python3\n\"\"\"Conservative post-processor for a single-file\
    \ competitive-programming source.\n\nThis intentionally is not a C++ optimiser.\
    \  It removes expander artefacts and\ntop-level functions that are unreachable\
    \ by a token-level dependency graph.\nIt keeps macros, aliases, constexpr objects,\
    \ classes, operators,\nspecialisations and overload groups intact.\nThe final\
    \ compiler check is mandatory unless --no-check is given.\n\"\"\"\n\nfrom __future__\
    \ import annotations\n\nimport argparse\nimport os\nimport re\nimport shlex\n\
    import subprocess\nimport sys\nimport tempfile\nfrom collections import defaultdict,\
    \ deque\nfrom dataclasses import dataclass\nfrom pathlib import Path\n\n\nIDENT_RE\
    \ = re.compile(r\"[A-Za-z_][A-Za-z_0-9]*\")\nARTIFACT_RE = re.compile(r\"// (?:BEGIN|END):\"\
    )\nBEGIN_RE = re.compile(r\"^\\s*// BEGIN: (.+?)\\s*$\")\nEND_RE = re.compile(r\"\
    // END: (.+?)\\s*$\")\nLINE_RE = re.compile(r\"^\\s*#\\s*line\\b\")\nLINE_FILE_RE\
    \ = re.compile(r'^\\s*#\\s*line\\s+\\d+\\s+\"([^\"]+)\"')\nDEFINE_RE = re.compile(r\"\
    ^\\s*#\\s*define\\s+([A-Za-z_]\\w*)\")\nUSING_RE = re.compile(r\"^\\s*using\\\
    s+([A-Za-z_]\\w*)\\s*=\")\nCONST_RE = re.compile(\n    r\"\\bconstexpr\\s+(?:auto|[A-Za-z_]\\\
    w*(?:\\s*<[^;={}>]*>)?)\\s+([A-Za-z_]\\w*)\\s*=\"\n)\n\n\n@dataclass(frozen=True)\n\
    class Candidate:\n    start: int\n    end: int\n    name: str\n    kind: str\n\
    \n\ndef code_view(line: str) -> str:\n    \"\"\"Replace strings and comments with\
    \ spaces, preserving positions roughly.\"\"\"\n    out: list[str] = []\n    i\
    \ = 0\n    quote = \"\"\n    while i < len(line):\n        c = line[i]\n     \
    \   if quote:\n            out.append(\" \")\n            if c == \"\\\\\" and\
    \ i + 1 < len(line):\n                out.append(\" \")\n                i +=\
    \ 2\n                continue\n            if c == quote:\n                quote\
    \ = \"\"\n            i += 1\n            continue\n        if c in \"\\\"'\"\
    :\n            quote = c\n            out.append(\" \")\n            i += 1\n\
    \        elif c == \"/\" and i + 1 < len(line) and line[i + 1] == \"/\":\n   \
    \         out.extend(\" \" * (len(line) - i))\n            break\n        else:\n\
    \            out.append(c)\n            i += 1\n    return \"\".join(out)\n\n\n\
    def code_views(lines: list[str]) -> list[str]:\n    \"\"\"Like code_view(), but\
    \ also tracks block comments across line boundaries.\"\"\"\n    out: list[str]\
    \ = []\n    in_block = False\n    for line in lines:\n        chars = list(code_view(line))\n\
    \        i = 0\n        while i < len(line):\n            if in_block:\n     \
    \           chars[i] = \" \"\n                if line.startswith(\"*/\", i):\n\
    \                    chars[i : i + 2] = [\" \", \" \"]\n                    i\
    \ += 2\n                    in_block = False\n                else:\n        \
    \            i += 1\n            elif line.startswith(\"/*\", i):\n          \
    \      chars[i : i + 2] = [\" \", \" \"]\n                i += 2\n           \
    \     in_block = True\n            else:\n                i += 1\n        out.append(\"\
    \".join(chars))\n    return out\n\n\ndef brace_delta(line: str) -> int:\n    view\
    \ = code_view(line)\n    return view.count(\"{\") - view.count(\"}\")\n\n\ndef\
    \ remove_known_inactive(lines: list[str], undefined: set[str]) -> list[str]:\n\
    \    \"\"\"Resolve only #if defined(NAME) / #ifdef NAME for explicitly absent\
    \ names.\"\"\"\n    out: list[str] = []\n    # (parent_is_output, condition_known,\
    \ chosen_branch, this_branch_is_output)\n    stack: list[tuple[bool, bool, bool,\
    \ bool]] = []\n    current = True\n    known_if = re.compile(r\"^\\s*#\\s*if\\\
    s+(?:defined\\s*\\(\\s*([A-Za-z_]\\w*)\\s*\\)|defined\\s+([A-Za-z_]\\w*))\\s*$\"\
    )\n    known_if_not = re.compile(r\"^\\s*#\\s*if\\s*!\\s*defined\\s*\\(\\s*([A-Za-z_]\\\
    w*)\\s*\\)\\s*$\")\n    ifdef = re.compile(r\"^\\s*#\\s*ifdef\\s+([A-Za-z_]\\\
    w*)\\s*$\")\n    ifndef = re.compile(r\"^\\s*#\\s*ifndef\\s+([A-Za-z_]\\w*)\\\
    s*$\")\n    for line in lines:\n        defined = DEFINE_RE.match(line)\n    \
    \    if current and defined:\n            undefined.discard(defined.group(1))\n\
    \        m_not = known_if_not.match(line) or ifndef.match(line)\n        m_yes\
    \ = known_if.match(line) or ifdef.match(line)\n        if m_not or m_yes:\n  \
    \          name = next(x for x in (m_not or m_yes).groups() if x is not None)\n\
    \            if name in undefined:\n                value = bool(m_not)\n    \
    \            stack.append((current, True, value, current and value))\n       \
    \         current = current and value\n                continue\n            stack.append((current,\
    \ False, False, current))\n            if current:\n                out.append(line)\n\
    \            continue\n        if re.match(r\"^\\s*#\\s*else\\b\", line) and stack:\n\
    \            parent, known, chosen, _ = stack[-1]\n            if known:\n   \
    \             current = parent and not chosen\n                stack[-1] = (parent,\
    \ known, True, current)\n                continue\n            current = parent\n\
    \            if current:\n                out.append(line)\n            continue\n\
    \        if re.match(r\"^\\s*#\\s*endif\\b\", line) and stack:\n            parent,\
    \ known, _, _ = stack.pop()\n            current = parent\n            if not\
    \ known and current:\n                out.append(line)\n            continue\n\
    \        if current:\n            out.append(line)\n    return out\n\n\ndef strip_artifacts(lines:\
    \ list[str]) -> list[str]:\n    out = []\n    for line in lines:\n        if LINE_RE.match(line):\n\
    \            continue\n        m = ARTIFACT_RE.search(line)\n        if m:\n \
    \           line = line[:m.start()].rstrip() + (\"\\n\" if line.endswith(\"\\\
    n\") else \"\")\n        if line.strip():\n            out.append(line)\n    return\
    \ out\n\n\ndef strip_header_comments(lines: list[str]) -> list[str]:\n    \"\"\
    \"Remove ordinary comments only while inside an expanded include file.\"\"\"\n\
    \    out: list[str] = []\n    stack: list[str] = []\n    current_file = \"\"\n\
    \    in_block = False\n    for line in lines:\n        file_match = LINE_FILE_RE.match(line)\n\
    \        if file_match:\n            current_file = file_match.group(1)\n    \
    \        out.append(line)\n            continue\n        begin = BEGIN_RE.match(line)\n\
    \        end = END_RE.match(line)\n        if begin:\n            stack.append(begin.group(1))\n\
    \            current_file = begin.group(1)\n            out.append(line)\n   \
    \         continue\n        if end:\n            out.append(line)\n          \
    \  if stack:\n                stack.pop()\n            if stack:\n           \
    \     current_file = stack[-1]\n            continue\n        in_header = current_file\
    \ != \"main.cpp\"\n        if not in_header and not in_block:\n            out.append(line)\n\
    \            continue\n        chars = list(line)\n        i = 0\n        quote\
    \ = \"\"\n        while i < len(chars):\n            if in_block:\n          \
    \      if chars[i] != \"\\n\":\n                    chars[i] = \" \"\n       \
    \         if line.startswith(\"*/\", i):\n                    chars[i : i + 2]\
    \ = [\" \", \" \"]\n                    i += 2\n                    in_block =\
    \ False\n                else:\n                    i += 1\n                continue\n\
    \            c = chars[i]\n            if quote:\n                if c == \"\\\
    \\\" and i + 1 < len(chars):\n                    i += 2\n                   \
    \ continue\n                if c == quote:\n                    quote = \"\"\n\
    \                i += 1\n                continue\n            if c in \"\\\"\
    '\":\n                quote = c\n                i += 1\n            elif line.startswith(\"\
    //\", i):\n                for j in range(i, len(chars)):\n                  \
    \  if chars[j] != \"\\n\":\n                        chars[j] = \" \"\n       \
    \         break\n            elif line.startswith(\"/*\", i):\n              \
    \  chars[i : i + 2] = [\" \", \" \"]\n                i += 2\n               \
    \ in_block = True\n            else:\n                i += 1\n        out.append(\"\
    \".join(chars))\n    return out\n\n\ndef find_semicolon(lines: list[str], views:\
    \ list[str], start: int) -> int | None:\n    depth = 0\n    for i in range(start,\
    \ len(lines)):\n        view = views[i]\n        for c in view:\n            if\
    \ c in \"({[\":\n                depth += 1\n            elif c in \")} ]\".replace(\"\
    \ \", \"\"):\n                depth -= 1\n            elif c == \";\" and depth\
    \ == 0:\n                return i\n    return None\n\n\ndef find_block_end(lines:\
    \ list[str], views: list[str], start: int) -> int | None:\n    depth = 0\n   \
    \ seen = False\n    for i in range(start, len(lines)):\n        view = views[i]\n\
    \        for c in view:\n            if c == \"{\":\n                depth +=\
    \ 1\n                seen = True\n            elif c == \"}\" and seen:\n    \
    \            depth -= 1\n                if depth == 0:\n                    return\
    \ i\n    return None\n\n\ndef function_name(prefix: str) -> str | None:\n    if\
    \ \"operator\" in prefix or re.search(r\"(?:^|\\\\n)\\\\s*(?:class|struct)\\\\\
    b\", prefix):\n        return None\n    paren = prefix.rfind(\"(\")\n    if paren\
    \ < 0:\n        return None\n    left = prefix[:paren]\n    names = IDENT_RE.findall(left)\n\
    \    if not names:\n        return None\n    name = names[-1]\n    if name in\
    \ {\"if\", \"for\", \"while\", \"switch\", \"catch\"}:\n        return None\n\
    \    return name\n\n\ndef find_candidates(lines: list[str]) -> list[Candidate]:\n\
    \    ans: list[Candidate] = []\n    views = code_views(lines)\n    depth = 0\n\
    \    i = 0\n    while i < len(lines):\n        line = lines[i]\n        view =\
    \ views[i]\n        if depth != 0:\n            depth += view.count(\"{\") - view.count(\"\
    }\")\n            i += 1\n            continue\n        m = DEFINE_RE.match(line)\n\
    \        if m:\n            end = i\n            while lines[end].rstrip().endswith(\"\
    \\\\\") and end + 1 < len(lines):\n                end += 1\n            # Macro\
    \ expansion and token pasting are deliberately outside this\n            # tool's\
    \ safety envelope.  Preserve every macro definition.\n            i = end + 1\n\
    \            continue\n        if view.lstrip().startswith(\"#\"):\n         \
    \   i += 1\n            continue\n        # Do not begin a function candidate\
    \ on an arbitrary declaration: doing\n        # so can swallow a preceding `using`\
    \ until the next function body.\n        if not view.lstrip().startswith(\"template\"\
    ) and not (\"(\" in view and \"{\" in view):\n            i += 1\n           \
    \ continue\n        # Function and variable templates may start with one or more\
    \ template lines.\n        start = i\n        probe = i\n        while probe <\
    \ len(lines) and views[probe].lstrip().startswith(\"template\"):\n           \
    \ probe += 1\n        header = \"\".join(views[start : min(len(lines), probe +\
    \ 4)])\n        brace = header.find(\"{\")\n        if brace >= 0:\n         \
    \   prefix = header[:brace]\n            name = function_name(prefix)\n      \
    \      end = find_block_end(lines, views, start)\n            if name and end\
    \ is not None:\n                # Functions entered implicitly by the runtime\
    \ (notably\n                # __attribute__((destructor))) have no ordinary source-level\n\
    \                # call site.  Keep every attribute-bearing definition.\n    \
    \            if \"__attribute__\" in \"\".join(views[start : end + 1]):\n    \
    \                i = end + 1\n                    continue\n                ans.append(Candidate(start,\
    \ end, name, \"function\"))\n                i = end + 1\n                continue\n\
    \        depth += view.count(\"{\") - view.count(\"}\")\n        i += 1\n    return\
    \ ans\n\n\ndef identifiers(lines: list[str]) -> set[str]:\n    return set(IDENT_RE.findall(\"\
    \\n\".join(code_view(x) for x in lines)))\n\n\ndef remove_unreachable(lines: list[str])\
    \ -> tuple[list[str], list[Candidate]]:\n    candidates = find_candidates(lines)\n\
    \    by_name: dict[str, list[Candidate]] = defaultdict(list)\n    occupied = [False]\
    \ * len(lines)\n    for c in candidates:\n        by_name[c.name].append(c)\n\
    \        for i in range(c.start, c.end + 1):\n            occupied[i] = True\n\
    \    names = set(by_name)\n    roots = identifiers([line for i, line in enumerate(lines)\
    \ if not occupied[i]]) & names\n    # The C++ entry point is necessarily live\
    \ even though no source token calls it.\n    roots.add(\"main\")\n    deps: dict[str,\
    \ set[str]] = defaultdict(set)\n    for c in candidates:\n        used = identifiers(lines[c.start\
    \ : c.end + 1]) & names\n        used.discard(c.name)\n        deps[c.name].update(used)\n\
    \    live: set[str] = set()\n    que = deque(roots)\n    while que:\n        name\
    \ = que.popleft()\n        if name in live:\n            continue\n        live.add(name)\n\
    \        que.extend(deps[name] - live)\n    removed = [c for c in candidates if\
    \ c.name not in live]\n    dead_line = [False] * len(lines)\n    for c in removed:\n\
    \        for i in range(c.start, c.end + 1):\n            dead_line[i] = True\n\
    \    return [line for i, line in enumerate(lines) if not dead_line[i]], removed\n\
    \n\ndef check(command: str, path: Path) -> None:\n    rendered = command.format(file=shlex.quote(str(path)))\n\
    \    result = subprocess.run(rendered, shell=True, text=True, stdout=subprocess.PIPE,\
    \ stderr=subprocess.PIPE)\n    if result.returncode:\n        sys.stderr.write(result.stdout)\n\
    \        sys.stderr.write(result.stderr)\n        raise RuntimeError(f\"compile\
    \ check failed: {rendered}\")\n\n\ndef main() -> int:\n    parser = argparse.ArgumentParser(description=\"\
    Conservatively shrink an expanded C++ source.\")\n    parser.add_argument(\"input\"\
    , type=Path)\n    parser.add_argument(\"-o\", \"--output\", type=Path, help=\"\
    write to this file (default: standard output)\")\n    parser.add_argument(\"--undefined\"\
    , default=\"USE_PCH,LOCAL\", help=\"comma-separated macros known to be undefined\"\
    )\n    parser.add_argument(\"--check\", default=\"g++ -std=c++20 -O2 -mavx2 -mpopcnt\
    \ -fsyntax-only {file}\")\n    parser.add_argument(\"--no-check\", action=\"store_true\"\
    , help=\"skip baseline and final compiler checks\")\n    parser.add_argument(\"\
    --report\", action=\"store_true\")\n    args = parser.parse_args()\n    source\
    \ = args.input.read_text()\n    undefined = {x for x in args.undefined.split(\"\
    ,\") if x}\n    lines = source.splitlines(keepends=True)\n    lines = remove_known_inactive(lines,\
    \ undefined)\n    lines, removed = remove_unreachable(lines)\n    lines = strip_header_comments(lines)\n\
    \    lines = strip_artifacts(lines)\n    result = \"\".join(lines)\n    if not\
    \ result.endswith(\"\\n\"):\n        result += \"\\n\"\n\n    if not args.no_check:\n\
    \        check(args.check, args.input)\n    temp_dir = args.output.parent if args.output\
    \ else None\n    if args.output:\n        args.output.parent.mkdir(parents=True,\
    \ exist_ok=True)\n    with tempfile.NamedTemporaryFile(\"w\", encoding=\"utf-8\"\
    , delete=False, dir=temp_dir, suffix=\".cpp\") as f:\n        f.write(result)\n\
    \        temporary = Path(f.name)\n    try:\n        if not args.no_check:\n \
    \           check(args.check, temporary)\n        if args.output:\n          \
    \  os.replace(temporary, args.output)\n        else:\n            sys.stdout.write(result)\n\
    \            temporary.unlink()\n    except Exception:\n        temporary.unlink(missing_ok=True)\n\
    \        raise\n    if args.report:\n        print(f\"{len(source.encode())} ->\
    \ {len(result.encode())} bytes; removed {len(removed)} declarations\", file=sys.stderr)\n\
    \        for c in removed:\n            print(f\"  {c.kind:9} {c.name}\", file=sys.stderr)\n\
    \    return 0\n\n\nif __name__ == \"__main__\":\n    try:\n        raise SystemExit(main())\n\
    \    except RuntimeError as e:\n        print(f\"shrink.py: {e}\", file=sys.stderr)\n\
    \        raise SystemExit(1)\n"
  dependsOn: []
  isVerificationFile: false
  path: shrink.py
  requiredBy: []
  timestamp: '1970-01-01 00:00:00+00:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: shrink.py
layout: document
redirect_from:
- /library/shrink.py
- /library/shrink.py.html
title: shrink.py
---
