---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':warning:'
  attributes:
    links:
    - https://uoj.ac/contest/103/problem/1015
  bundledCode: "#line 1 \"setfunc/division_free_xor_convolution.hpp\"\n// https://uoj.ac/contest/103/problem/1015\n\
    template <typename T>\nvc<T> division_free_xor_convolution(vc<T> a, vc<T> b) {\n\
    \  int K = topbit(len(a));\n  int n = len(a);\n  SHOW(a);\n  SHOW(b);\n  // y\
    \ = x + 1\n  // x = y - 1\n  // supseset zeta\n  for (int i = 1; i != n; i <<=\
    \ 1) {\n    for (int j = 0; j != n; j += i << 1) {\n      for (int k = 0; k !=\
    \ i; k++) {\n        a[j + k] -= a[i + j + k];\n        b[j + k] -= b[i + j +\
    \ k];\n      }\n    }\n  }\n  SHOW(a);\n  SHOW(b);\n\n  // ranked\n  vv(T, A,\
    \ 1 << K, 0);\n  vv(T, B, 1 << K, 0);\n  FOR(s, n) {\n    int k = popcnt(s);\n\
    \    A[s].resize(k + 1);\n    B[s].resize(k + 1);\n    A[s][k] += a[s];\n    B[s][k]\
    \ += b[s];\n  }\n\n  // subset zeta\n  for (int i = 1; i != n; i <<= 1) {\n  \
    \  for (int j = 0; j != n; j += i << 1) {\n      for (int k = 0; k != i; k++)\
    \ {\n        int m = len(A[j + k]);\n        FOR(d, m) A[i + j + k][d] += A[j\
    \ + k][d];\n        FOR(d, m) B[i + j + k][d] += B[j + k][d];\n      }\n    }\n\
    \  }\n\n  // pointwise convolution\n  FOR(s, n) { A[s] = convolution<T>(A[s],\
    \ B[s]); }\n\n  // subset mobius\n  for (int i = 1; i != n; i <<= 1) {\n    for\
    \ (int j = 0; j != n; j += i << 1) {\n      for (int k = 0; k != i; k++) {\n \
    \       int m = len(A[j + k]);\n        FOR(d, m) { A[i + j + k][d] -= A[j + k][d];\
    \ }\n      }\n    }\n  }\n\n  // unrank. \u3053\u3053\u3092\u4E0A\u624B\u304F\u3084\
    \u308B\n  FOR(s, n) {\n    int m = popcnt(s);\n    T x = 0;\n    FOR_R(i, m, len(A[s]))\
    \ { x = x + x + A[s][i]; }\n    a[s] = x;\n  }\n\n  // y = x + 1\n  for (int i\
    \ = 1; i != n; i <<= 1) {\n    for (int j = 0; j != n; j += i << 1) {\n      for\
    \ (int k = 0; k != i; k++) {\n        a[j + k] += a[i + j + k];\n      }\n   \
    \ }\n  }\n  return a;\n}\n"
  code: "// https://uoj.ac/contest/103/problem/1015\ntemplate <typename T>\nvc<T>\
    \ division_free_xor_convolution(vc<T> a, vc<T> b) {\n  int K = topbit(len(a));\n\
    \  int n = len(a);\n  SHOW(a);\n  SHOW(b);\n  // y = x + 1\n  // x = y - 1\n \
    \ // supseset zeta\n  for (int i = 1; i != n; i <<= 1) {\n    for (int j = 0;\
    \ j != n; j += i << 1) {\n      for (int k = 0; k != i; k++) {\n        a[j +\
    \ k] -= a[i + j + k];\n        b[j + k] -= b[i + j + k];\n      }\n    }\n  }\n\
    \  SHOW(a);\n  SHOW(b);\n\n  // ranked\n  vv(T, A, 1 << K, 0);\n  vv(T, B, 1 <<\
    \ K, 0);\n  FOR(s, n) {\n    int k = popcnt(s);\n    A[s].resize(k + 1);\n   \
    \ B[s].resize(k + 1);\n    A[s][k] += a[s];\n    B[s][k] += b[s];\n  }\n\n  //\
    \ subset zeta\n  for (int i = 1; i != n; i <<= 1) {\n    for (int j = 0; j !=\
    \ n; j += i << 1) {\n      for (int k = 0; k != i; k++) {\n        int m = len(A[j\
    \ + k]);\n        FOR(d, m) A[i + j + k][d] += A[j + k][d];\n        FOR(d, m)\
    \ B[i + j + k][d] += B[j + k][d];\n      }\n    }\n  }\n\n  // pointwise convolution\n\
    \  FOR(s, n) { A[s] = convolution<T>(A[s], B[s]); }\n\n  // subset mobius\n  for\
    \ (int i = 1; i != n; i <<= 1) {\n    for (int j = 0; j != n; j += i << 1) {\n\
    \      for (int k = 0; k != i; k++) {\n        int m = len(A[j + k]);\n      \
    \  FOR(d, m) { A[i + j + k][d] -= A[j + k][d]; }\n      }\n    }\n  }\n\n  //\
    \ unrank. \u3053\u3053\u3092\u4E0A\u624B\u304F\u3084\u308B\n  FOR(s, n) {\n  \
    \  int m = popcnt(s);\n    T x = 0;\n    FOR_R(i, m, len(A[s])) { x = x + x +\
    \ A[s][i]; }\n    a[s] = x;\n  }\n\n  // y = x + 1\n  for (int i = 1; i != n;\
    \ i <<= 1) {\n    for (int j = 0; j != n; j += i << 1) {\n      for (int k = 0;\
    \ k != i; k++) {\n        a[j + k] += a[i + j + k];\n      }\n    }\n  }\n  return\
    \ a;\n}\n"
  dependsOn: []
  isVerificationFile: false
  path: setfunc/division_free_xor_convolution.hpp
  requiredBy: []
  timestamp: '2025-12-02 17:14:38+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: setfunc/division_free_xor_convolution.hpp
layout: document
redirect_from:
- /library/setfunc/division_free_xor_convolution.hpp
- /library/setfunc/division_free_xor_convolution.hpp.html
title: setfunc/division_free_xor_convolution.hpp
---
