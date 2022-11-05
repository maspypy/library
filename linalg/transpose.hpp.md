---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':x:'
    path: test/yukicoder/2108.test.cpp
    title: test/yukicoder/2108.test.cpp
  _isVerificationFailed: true
  _pathExtension: hpp
  _verificationStatusIcon: ':x:'
  attributes:
    links: []
  bundledCode: "#line 1 \"linalg/transpose.hpp\"\n// vvc<T> \u3068 vc<string> \u3092\
    \u60F3\u5B9A\ntemplate <typename VC>\nvc<VC> transpose(const int n, const int\
    \ m, const vc<VC>& A) {\n  vc<VC> B(m, VC(n, A[0][0]));\n  FOR(x, n) FOR(y, m)\
    \ B[y][x] = A[x][y];\n  return B;\n}\n"
  code: "// vvc<T> \u3068 vc<string> \u3092\u60F3\u5B9A\ntemplate <typename VC>\n\
    vc<VC> transpose(const int n, const int m, const vc<VC>& A) {\n  vc<VC> B(m, VC(n,\
    \ A[0][0]));\n  FOR(x, n) FOR(y, m) B[y][x] = A[x][y];\n  return B;\n}\n"
  dependsOn: []
  isVerificationFile: false
  path: linalg/transpose.hpp
  requiredBy: []
  timestamp: '2022-11-06 01:50:09+09:00'
  verificationStatus: LIBRARY_ALL_WA
  verifiedWith:
  - test/yukicoder/2108.test.cpp
documentation_of: linalg/transpose.hpp
layout: document
redirect_from:
- /library/linalg/transpose.hpp
- /library/linalg/transpose.hpp.html
title: linalg/transpose.hpp
---
