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
  bundledCode: "Traceback (most recent call last):\n  File \"/opt/hostedtoolcache/Python/3.13.5/x64/lib/python3.13/site-packages/onlinejudge_verify/documentation/build.py\"\
    , line 71, in _render_source_code_stat\n    bundled_code = language.bundle(stat.path,\
    \ basedir=basedir, options={'include_paths': [basedir]}).decode()\n          \
    \         ~~~~~~~~~~~~~~~^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^\n\
    \  File \"/opt/hostedtoolcache/Python/3.13.5/x64/lib/python3.13/site-packages/onlinejudge_verify/languages/python.py\"\
    , line 96, in bundle\n    raise NotImplementedError\nNotImplementedError\n"
  code: "import sys\nimport os\nimport re\n\nINCLUDE_PATHS = ['.', os.path.expanduser('~/compro/library')]\n\
    visited = set()\n\ndef resolve_include(header):\n    for path in INCLUDE_PATHS:\n\
    \        full_path = os.path.join(path, header)\n        if os.path.isfile(full_path):\n\
    \            return os.path.abspath(full_path)\n    return None\n\ndef expand_file(path,\
    \ display_name=None, caller_file=None, caller_line=None):\n    abs_path = os.path.abspath(path)\n\
    \    if abs_path in visited:\n        return\n    visited.add(abs_path)\n\n  \
    \  if display_name is None:\n        display_name = os.path.basename(path)\n\n\
    \    print(f'// BEGIN: {display_name}')\n    print(f'#line 1 \"{display_name}\"\
    ')  # \u30D5\u30A1\u30A4\u30EB\u306E\u5192\u982D\u3067 `#line` \u3092\u5165\u308C\
    \u308B\n\n    with open(path) as f:\n        for i, line in enumerate(f, start=1):\n\
    \            if line.strip() == \"#pragma once\":\n                continue\n\n\
    \            m = re.match(r'#\\s*include\\s*\"([^\"]+)\"', line)\n           \
    \ if m:\n                header = m.group(1)\n                resolved = resolve_include(header)\n\
    \                if resolved:\n                    expand_file(resolved, header,\
    \ display_name, i + 1)\n                    print(f'#line {i + 1} \"{display_name}\"\
    ')  # \u2190 \u547C\u3073\u51FA\u3057\u5143\u306B\u623B\u308B\u4F4D\u7F6E\n  \
    \              else:\n                    print(f'// [warning] include not found:\
    \ {header}')\n            elif re.match(r'#\\s*include\\s*<[^>]+>', line):\n \
    \               print(line, end='')\n            else:\n                print(line,\
    \ end='')\n\n    print(f'// END: {display_name}')\n\nif __name__ == '__main__':\n\
    \    if len(sys.argv) != 2:\n        print(\"Usage: python3 expander.py main.cpp\
    \ > singlefile.cpp\")\n        sys.exit(1)\n\n    expand_file(sys.argv[1])\n"
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
