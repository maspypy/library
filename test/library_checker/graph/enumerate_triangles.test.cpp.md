---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: true
  _pathExtension: cpp
  _verificationStatusIcon: ':x:'
  attributes: {}
  bundledCode: "Traceback (most recent call last):\n  File \"/opt/hostedtoolcache/Python/3.11.1/x64/lib/python3.11/site-packages/onlinejudge_verify/documentation/build.py\"\
    , line 71, in _render_source_code_stat\n    bundled_code = language.bundle(stat.path,\
    \ basedir=basedir, options={'include_paths': [basedir]}).decode()\n          \
    \         ^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^\n\
    \  File \"/opt/hostedtoolcache/Python/3.11.1/x64/lib/python3.11/site-packages/onlinejudge_verify/languages/cplusplus.py\"\
    , line 187, in bundle\n    bundler.update(path)\n  File \"/opt/hostedtoolcache/Python/3.11.1/x64/lib/python3.11/site-packages/onlinejudge_verify/languages/cplusplus_bundle.py\"\
    , line 401, in update\n    self.update(self._resolve(pathlib.Path(included), included_from=path))\n\
    \                ^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^\n \
    \ File \"/opt/hostedtoolcache/Python/3.11.1/x64/lib/python3.11/site-packages/onlinejudge_verify/languages/cplusplus_bundle.py\"\
    , line 260, in _resolve\n    raise BundleErrorAt(path, -1, \"no such header\"\
    )\nonlinejudge_verify.languages.cplusplus_bundle.BundleErrorAt: enumerate/triangles.hpp:\
    \ line -1: no such header\n"
  code: "#define PROBLEM \"https://judge.yosupo.jp/problem/enumerate_triangles\"\r\
    \n#include \"my_template.hpp\"\r\n#include \"other/io.hpp\"\r\n#include \"enumerate/triangles.hpp\"\
    \r\n\r\nvoid solve() {\r\n  LL(N, M);\r\n  VEC(int, A, N);\r\n  Graph G(N);\r\n\
    \  G.read_graph(M, 0, 0);\r\n  i128 sum = 0;\r\n  auto query\r\n      = [&](int\
    \ a, int b, int c) -> void { sum += i128(A[a]) * A[b] * A[c]; };\r\n  enumerate_triangles(G,\
    \ query);\r\n  int ANS = sum % 998244353;\r\n  print(ANS);\r\n}\r\n\r\nsigned\
    \ main() {\r\n  solve();\r\n\r\n  return 0;\r\n}\r\n"
  dependsOn: []
  isVerificationFile: true
  path: test/library_checker/graph/enumerate_triangles.test.cpp
  requiredBy: []
  timestamp: '1970-01-01 00:00:00+00:00'
  verificationStatus: TEST_WRONG_ANSWER
  verifiedWith: []
documentation_of: test/library_checker/graph/enumerate_triangles.test.cpp
layout: document
redirect_from:
- /verify/test/library_checker/graph/enumerate_triangles.test.cpp
- /verify/test/library_checker/graph/enumerate_triangles.test.cpp.html
title: test/library_checker/graph/enumerate_triangles.test.cpp
---
