---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/mytest/minplus_convex.test.cpp
    title: test/mytest/minplus_convex.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 1 \"seq/minplus_convolution_convex.hpp\"\ntemplate <typename\
    \ T>\nvc<T> minplus_convolution_convex(const vc<T>& A, const vc<T>& B, const T\
    \ INF) {\n  ll NA = len(A), NB = len(B);\n  ll LA = 0, RA = NA, LB = 0, RB = NB;\n\
    \  while (LA < RA && A[LA] == INF) ++LA;\n  while (LA < RA && A[RA - 1] == INF)\
    \ --RA;\n  while (LB < RB && B[LB] == INF) ++LB;\n  while (LB < RB && B[RB - 1]\
    \ == INF) --RB;\n  // check convex\n  FOR3(i, LA + 1, RA - 1) assert(2 * A[i]\
    \ <= A[i - 1] + A[i + 1]);\n  FOR3(i, LB + 1, RB - 1) assert(2 * B[i] <= B[i -\
    \ 1] + B[i + 1]);\n\n  vc<T> C(NA + NB - 1, INF);\n  int i = LA, j = LB;\n  while\
    \ (i < RA && j < RB) {\n    C[i + j] = A[i] + B[j];\n    if (i == RA - 1) ++j;\n\
    \    elif (j == RB - 1)++ i;\n    else {\n      if (A[i + 1] + B[j] < A[i] + B[j\
    \ + 1])\n        ++i;\n      else\n        ++j;\n    }\n  }\n  return C;\n}\n"
  code: "template <typename T>\nvc<T> minplus_convolution_convex(const vc<T>& A, const\
    \ vc<T>& B, const T INF) {\n  ll NA = len(A), NB = len(B);\n  ll LA = 0, RA =\
    \ NA, LB = 0, RB = NB;\n  while (LA < RA && A[LA] == INF) ++LA;\n  while (LA <\
    \ RA && A[RA - 1] == INF) --RA;\n  while (LB < RB && B[LB] == INF) ++LB;\n  while\
    \ (LB < RB && B[RB - 1] == INF) --RB;\n  // check convex\n  FOR3(i, LA + 1, RA\
    \ - 1) assert(2 * A[i] <= A[i - 1] + A[i + 1]);\n  FOR3(i, LB + 1, RB - 1) assert(2\
    \ * B[i] <= B[i - 1] + B[i + 1]);\n\n  vc<T> C(NA + NB - 1, INF);\n  int i = LA,\
    \ j = LB;\n  while (i < RA && j < RB) {\n    C[i + j] = A[i] + B[j];\n    if (i\
    \ == RA - 1) ++j;\n    elif (j == RB - 1)++ i;\n    else {\n      if (A[i + 1]\
    \ + B[j] < A[i] + B[j + 1])\n        ++i;\n      else\n        ++j;\n    }\n \
    \ }\n  return C;\n}\n"
  dependsOn: []
  isVerificationFile: false
  path: seq/minplus_convolution_convex.hpp
  requiredBy: []
  timestamp: '2022-10-21 16:42:45+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/mytest/minplus_convex.test.cpp
documentation_of: seq/minplus_convolution_convex.hpp
layout: document
redirect_from:
- /library/seq/minplus_convolution_convex.hpp
- /library/seq/minplus_convolution_convex.hpp.html
title: seq/minplus_convolution_convex.hpp
---
