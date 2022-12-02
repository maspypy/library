---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/mytest/maxplus_concave.test.cpp
    title: test/mytest/maxplus_concave.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 1 \"seq/maxplus_convolution_concave.hpp\"\ntemplate <typename\
    \ T>\nvc<T> maxplus_convolution_concave(const vc<T>& A, const vc<T>& B, const\
    \ T INF) {\n  ll NA = len(A), NB = len(B);\n  ll LA = 0, RA = NA, LB = 0, RB =\
    \ NB;\n  while (LA < RA && A[LA] == -INF) ++LA;\n  while (LA < RA && A[RA - 1]\
    \ == -INF) --RA;\n  while (LB < RB && B[LB] == -INF) ++LB;\n  while (LB < RB &&\
    \ B[RB - 1] == -INF) --RB;\n  // check concave\n  FOR3(i, LA + 1, RA - 1) assert(2\
    \ * A[i] >= A[i - 1] + A[i + 1]);\n  FOR3(i, LB + 1, RB - 1) assert(2 * B[i] >=\
    \ B[i - 1] + B[i + 1]);\n\n  vc<T> C(NA + NB - 1, -INF);\n  int i = LA, j = LB;\n\
    \  while (i < RA && j < RB) {\n    C[i + j] = A[i] + B[j];\n    if (i == RA -\
    \ 1) ++j;\n    elif (j == RB - 1)++ i;\n    else {\n      if (A[i + 1] + B[j]\
    \ > A[i] + B[j + 1])\n        ++i;\n      else\n        ++j;\n    }\n  }\n  return\
    \ C;\n}\n"
  code: "template <typename T>\nvc<T> maxplus_convolution_concave(const vc<T>& A,\
    \ const vc<T>& B, const T INF) {\n  ll NA = len(A), NB = len(B);\n  ll LA = 0,\
    \ RA = NA, LB = 0, RB = NB;\n  while (LA < RA && A[LA] == -INF) ++LA;\n  while\
    \ (LA < RA && A[RA - 1] == -INF) --RA;\n  while (LB < RB && B[LB] == -INF) ++LB;\n\
    \  while (LB < RB && B[RB - 1] == -INF) --RB;\n  // check concave\n  FOR3(i, LA\
    \ + 1, RA - 1) assert(2 * A[i] >= A[i - 1] + A[i + 1]);\n  FOR3(i, LB + 1, RB\
    \ - 1) assert(2 * B[i] >= B[i - 1] + B[i + 1]);\n\n  vc<T> C(NA + NB - 1, -INF);\n\
    \  int i = LA, j = LB;\n  while (i < RA && j < RB) {\n    C[i + j] = A[i] + B[j];\n\
    \    if (i == RA - 1) ++j;\n    elif (j == RB - 1)++ i;\n    else {\n      if\
    \ (A[i + 1] + B[j] > A[i] + B[j + 1])\n        ++i;\n      else\n        ++j;\n\
    \    }\n  }\n  return C;\n}\n"
  dependsOn: []
  isVerificationFile: false
  path: seq/maxplus_convolution_concave.hpp
  requiredBy: []
  timestamp: '2022-10-21 16:42:45+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/mytest/maxplus_concave.test.cpp
documentation_of: seq/maxplus_convolution_concave.hpp
layout: document
redirect_from:
- /library/seq/maxplus_convolution_concave.hpp
- /library/seq/maxplus_convolution_concave.hpp.html
title: seq/maxplus_convolution_concave.hpp
---
