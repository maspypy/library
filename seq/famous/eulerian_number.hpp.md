---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/yukicoder/2005.test.cpp
    title: test/yukicoder/2005.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 1 \"seq/famous/eulerian_number.hpp\"\n// Eulerian number\n//\
    \ sum n^dx^n = A_d(x) / (1-x)^{d+1} \u3068\u306A\u308B d \u6B21\u591A\u9805\u5F0F\
    \u306E\u4FC2\u6570\u5217\ntemplate <typename mint>\nvvc<mint> eulerian_number_2d(int\
    \ N, int K) {\n  vv(mint, A, N + 1, K + 1);\n  A[0][0] = mint(1);\n  FOR(d, N)\
    \ FOR(k, 1, K + 1) {\n    A[d + 1][k] = mint(k) * A[d][k] + mint(d - k + 2) *\
    \ A[d][k - 1];\n  }\n  return A;\n}\n"
  code: "// Eulerian number\n// sum n^dx^n = A_d(x) / (1-x)^{d+1} \u3068\u306A\u308B\
    \ d \u6B21\u591A\u9805\u5F0F\u306E\u4FC2\u6570\u5217\ntemplate <typename mint>\n\
    vvc<mint> eulerian_number_2d(int N, int K) {\n  vv(mint, A, N + 1, K + 1);\n \
    \ A[0][0] = mint(1);\n  FOR(d, N) FOR(k, 1, K + 1) {\n    A[d + 1][k] = mint(k)\
    \ * A[d][k] + mint(d - k + 2) * A[d][k - 1];\n  }\n  return A;\n}\n"
  dependsOn: []
  isVerificationFile: false
  path: seq/famous/eulerian_number.hpp
  requiredBy: []
  timestamp: '2022-10-21 16:42:45+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/yukicoder/2005.test.cpp
documentation_of: seq/famous/eulerian_number.hpp
layout: document
redirect_from:
- /library/seq/famous/eulerian_number.hpp
- /library/seq/famous/eulerian_number.hpp.html
title: seq/famous/eulerian_number.hpp
---
