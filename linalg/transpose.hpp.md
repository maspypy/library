---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/yukicoder/2108.test.cpp
    title: test/yukicoder/2108.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 1 \"linalg/transpose.hpp\"\ntemplate <typename VC>\nvc<VC> transpose(const\
    \ int n, const int m, const vc<VC>& A) {\n  vc<VC> B(m, VC(n, A[0][0]));\n  FOR(x,\
    \ n) FOR(y, m) B[y][x] = A[x][y];\n  return B;\n}\n"
  code: "template <typename VC>\nvc<VC> transpose(const int n, const int m, const\
    \ vc<VC>& A) {\n  vc<VC> B(m, VC(n, A[0][0]));\n  FOR(x, n) FOR(y, m) B[y][x]\
    \ = A[x][y];\n  return B;\n}\n"
  dependsOn: []
  isVerificationFile: false
  path: linalg/transpose.hpp
  requiredBy: []
  timestamp: '2023-04-09 03:51:05+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/yukicoder/2108.test.cpp
documentation_of: linalg/transpose.hpp
layout: document
redirect_from:
- /library/linalg/transpose.hpp
- /library/linalg/transpose.hpp.html
title: linalg/transpose.hpp
---
