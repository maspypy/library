---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':warning:'
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
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: linalg/transpose.hpp
layout: document
redirect_from:
- /library/linalg/transpose.hpp
- /library/linalg/transpose.hpp.html
title: linalg/transpose.hpp
---
