---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: true
  _pathExtension: cpp
  _verificationStatusIcon: ':x:'
  attributes: {}
  bundledCode: "Traceback (most recent call last):\n  File \"/opt/hostedtoolcache/Python/3.12.13/x64/lib/python3.12/site-packages/onlinejudge_verify/documentation/build.py\"\
    , line 71, in _render_source_code_stat\n    bundled_code = language.bundle(stat.path,\
    \ basedir=basedir, options={'include_paths': [basedir]}).decode()\n          \
    \         ^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^\n\
    \  File \"/opt/hostedtoolcache/Python/3.12.13/x64/lib/python3.12/site-packages/onlinejudge_verify/languages/cplusplus.py\"\
    , line 187, in bundle\n    bundler.update(path)\n  File \"/opt/hostedtoolcache/Python/3.12.13/x64/lib/python3.12/site-packages/onlinejudge_verify/languages/cplusplus_bundle.py\"\
    , line 401, in update\n    self.update(self._resolve(pathlib.Path(included), included_from=path))\n\
    \                ^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^\n \
    \ File \"/opt/hostedtoolcache/Python/3.12.13/x64/lib/python3.12/site-packages/onlinejudge_verify/languages/cplusplus_bundle.py\"\
    , line 260, in _resolve\n    raise BundleErrorAt(path, -1, \"no such header\"\
    )\nonlinejudge_verify.languages.cplusplus_bundle.BundleErrorAt: flow/mincostflow.hpp:\
    \ line -1: no such header\n"
  code: "#define PROBLEM \"https://judge.yosupo.jp/problem/assignment\"\n#include\
    \ \"my_template.hpp\"\n#include \"other/io.hpp\"\n#include \"flow/mincostflow.hpp\"\
    \n\nvoid solve() {\n  LL(N);\n  int source = 0;\n  auto left = [&](int i) -> int\
    \ { return 1 + i; };\n  auto right = [&](int i) -> int { return 1 + N + i; };\n\
    \  int sink = right(N);\n  Min_Cost_Flow<int, ll, true> G(N + N + 2, source, sink);\n\
    \  FOR(i, N) FOR(j, N) {\n    LL(x);\n    G.add(left(i), right(j), 1, x);\n  }\n\
    \  FOR(i, N) {\n    G.add(source, left(i), 1, 0);\n    G.add(right(i), sink, 1,\
    \ 0);\n  }\n  auto xy = G.slope();\n  auto edges = G.edges();\n  vi ANS(N);\n\
    \  for (auto&& e: edges) {\n    if (e.flow && 1 <= e.frm && e.frm <= N) {\n  \
    \    ANS[e.frm - 1] = e.to - right(0);\n    }\n  }\n  print(xy.back().se);\n \
    \ print(ANS);\n}\n\nsigned main() {\n  solve();\n  return 0;\n}"
  dependsOn: []
  isVerificationFile: true
  path: test/2_library_checker/graph/assignment_mcf.test.cpp
  requiredBy: []
  timestamp: '1970-01-01 00:00:00+00:00'
  verificationStatus: TEST_WRONG_ANSWER
  verifiedWith: []
documentation_of: test/2_library_checker/graph/assignment_mcf.test.cpp
layout: document
redirect_from:
- /verify/test/2_library_checker/graph/assignment_mcf.test.cpp
- /verify/test/2_library_checker/graph/assignment_mcf.test.cpp.html
title: test/2_library_checker/graph/assignment_mcf.test.cpp
---
