---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: py
  _verificationStatusIcon: ':warning:'
  attributes:
    links:
    - https://github.com/maspypy/library
  bundledCode: "Traceback (most recent call last):\n  File \"/opt/hostedtoolcache/Python/3.12.15/x64/lib/python3.12/site-packages/onlinejudge_verify/documentation/build.py\"\
    , line 71, in _render_source_code_stat\n    bundled_code = language.bundle(stat.path,\
    \ basedir=basedir, options={'include_paths': [basedir]}).decode()\n          \
    \         ^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^\n\
    \  File \"/opt/hostedtoolcache/Python/3.12.15/x64/lib/python3.12/site-packages/onlinejudge_verify/languages/python.py\"\
    , line 96, in bundle\n    raise NotImplementedError\nNotImplementedError\n"
  code: "#!/usr/bin/env python3\n\"\"\"Keep per-header source URLs in sync with their\
    \ paths in this repository.\"\"\"\n\nfrom __future__ import annotations\n\nimport\
    \ argparse\nimport subprocess\nimport sys\nfrom pathlib import Path\nfrom urllib.parse\
    \ import quote\n\n\nREPOSITORY_URL = \"https://github.com/maspypy/library\"\n\
    SOURCE_PREFIX = \"// Source: \"\n\n\ndef tracked_headers(root: Path) -> list[Path]:\n\
    \    \"\"\"Return every tracked .hpp file, including files in normally ignored\
    \ paths.\"\"\"\n    result = subprocess.run(\n        [\"git\", \"-C\", str(root),\
    \ \"ls-files\", \"-z\", \"--\", \"*.hpp\"],\n        check=True,\n        stdout=subprocess.PIPE,\n\
    \    )\n    return [root / name for name in result.stdout.decode(\"utf-8\").split(\"\
    \\0\") if name]\n\n\ndef expected_source_line(root: Path, path: Path) -> bytes:\n\
    \    relative_path = path.relative_to(root).as_posix()\n    url_path = quote(relative_path,\
    \ safe=\"/-._~\")\n    return f\"{SOURCE_PREFIX}{REPOSITORY_URL}/blob/main/{url_path}\"\
    .encode(\"ascii\")\n\n\ndef normalized_content(root: Path, path: Path) -> bytes:\n\
    \    content = path.read_bytes().replace(b\"\\r\\n\", b\"\\n\")\n    bom = b\"\
    \\xef\\xbb\\xbf\" if content.startswith(b\"\\xef\\xbb\\xbf\") else b\"\"\n   \
    \ if bom:\n        content = content[len(bom) :]\n\n    # Header files use LF\
    \ by repository policy (see .gitattributes).\n    lines = content.splitlines(keepends=True)\n\
    \    source_line = expected_source_line(root, path) + b\"\\n\"\n\n    # A Source\
    \ line is a reserved, top-of-file metadata line.  Normalizing all\n    # such\
    \ lines in the leading comment/blank block also repairs an old header\n    # placed\
    \ after a comment block without touching source citations in code.\n    header_end\
    \ = 0\n    for line in lines:\n        bare = line.rstrip(b\"\\r\\n\")\n     \
    \   if bare == b\"\" or bare.startswith(b\"//\") or bare.startswith(b\"/*\") or\
    \ bare.startswith(b\"*\") or bare.startswith(b\"*/\"):\n            header_end\
    \ += 1\n        else:\n            break\n    leading = [\n        line\n    \
    \    for line in lines[:header_end]\n        if not line.rstrip(b\"\\r\\n\").startswith(SOURCE_PREFIX.encode(\"\
    ascii\"))\n    ]\n    return bom + source_line + b\"\".join(leading + lines[header_end:])\n\
    \n\ndef update(root: Path, check: bool) -> int:\n    changed: list[Path] = []\n\
    \    for path in tracked_headers(root):\n        normalized = normalized_content(root,\
    \ path)\n        if path.read_bytes() != normalized:\n            changed.append(path)\n\
    \            if not check:\n                path.write_bytes(normalized)\n\n \
    \   if changed:\n        for path in changed:\n            print(path.relative_to(root).as_posix())\n\
    \        if check:\n            print(\"Source URL headers are missing or stale.\
    \ Run: python scripts/update_source_urls.py\", file=sys.stderr)\n            return\
    \ 1\n    return 0\n\n\ndef main() -> int:\n    parser = argparse.ArgumentParser(description=__doc__)\n\
    \    parser.add_argument(\"--check\", action=\"store_true\", help=\"report stale\
    \ headers without changing files\")\n    parser.add_argument(\"--root\", type=Path,\
    \ default=Path(__file__).resolve().parents[1], help=\"repository root\")\n   \
    \ args = parser.parse_args()\n    return update(args.root.resolve(), args.check)\n\
    \n\nif __name__ == \"__main__\":\n    raise SystemExit(main())\n"
  dependsOn: []
  isVerificationFile: false
  path: scripts/update_source_urls.py
  requiredBy: []
  timestamp: '1970-01-01 00:00:00+00:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: scripts/update_source_urls.py
layout: document
redirect_from:
- /library/scripts/update_source_urls.py
- /library/scripts/update_source_urls.py.html
title: scripts/update_source_urls.py
---
