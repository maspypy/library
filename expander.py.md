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
  bundledCode: "Traceback (most recent call last):\n  File \"/opt/hostedtoolcache/Python/3.14.5/x64/lib/python3.14/site-packages/onlinejudge_verify/documentation/build.py\"\
    , line 71, in _render_source_code_stat\n    bundled_code = language.bundle(stat.path,\
    \ basedir=basedir, options={'include_paths': [basedir]}).decode()\n          \
    \         ~~~~~~~~~~~~~~~^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^\n\
    \  File \"/opt/hostedtoolcache/Python/3.14.5/x64/lib/python3.14/site-packages/onlinejudge_verify/languages/python.py\"\
    , line 96, in bundle\n    raise NotImplementedError\nNotImplementedError\n"
  code: "import sys\nimport os\nimport re\n\nSCRIPT_DIR = os.path.dirname(os.path.abspath(__file__))\n\
    LIBRARY_DIR = SCRIPT_DIR\n\nINCLUDE_PATHS = [\n    '.',\n    LIBRARY_DIR,\n]\n\
    \nextra_paths = os.environ.get('MASPY_EXPANDER_INCLUDE_PATHS')\nif extra_paths:\n\
    \    INCLUDE_PATHS.extend(extra_paths.split(os.pathsep))\n\nvisited = set()\n\n\
    \ndef resolve_include(header):\n    for path in INCLUDE_PATHS:\n        full_path\
    \ = os.path.join(path, header)\n        if os.path.isfile(full_path):\n      \
    \      return os.path.abspath(full_path)\n    return None\n\n\ndef expand_file(path,\
    \ display_name=None, caller_file=None, caller_line=None):\n    abs_path = os.path.abspath(path)\n\
    \    if abs_path in visited:\n        return\n    visited.add(abs_path)\n\n  \
    \  if display_name is None:\n        display_name = os.path.basename(path)\n\n\
    \    print(f'// BEGIN: {display_name}')\n    print(f'#line 1 \"{display_name}\"\
    ')\n\n    with open(path) as f:\n        for i, line in enumerate(f, start=1):\n\
    \            if line.strip() == \"#pragma once\":\n                continue\n\n\
    \            m = re.match(r'#\\s*include\\s*\"([^\"]+)\"', line)\n           \
    \ if m:\n                header = m.group(1)\n                resolved = resolve_include(header)\n\
    \                if resolved:\n                    if resolved not in visited:\n\
    \                        expand_file(resolved, header, display_name, i + 1)\n\
    \                    print(f'#line {i + 1} \"{display_name}\"')\n            \
    \    else:\n                    print(f'// [warning] include not found: {header}')\n\
    \            elif re.match(r'#\\s*include\\s*<[^>]+>', line):\n              \
    \  print(line, end='')\n            else:\n                print(line, end='')\n\
    \n    print(f'// END: {display_name}')\n\n\nif __name__ == '__main__':\n    if\
    \ len(sys.argv) != 2:\n        print(\"Usage: python3 expander.py main.cpp > singlefile.cpp\"\
    )\n        sys.exit(1)\n\n    expand_file(sys.argv[1])"
  dependsOn: []
  isVerificationFile: false
  path: expander.py
  requiredBy: []
  timestamp: '1970-01-01 00:00:00+00:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: expander.py
layout: document
redirect_from:
- /library/expander.py
- /library/expander.py.html
title: expander.py
---
