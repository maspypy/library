---
data:
  _extendedDependsOn: []
  _extendedRequiredBy:
  - icon: ':x:'
    path: convex/minplus_convolution_of_triples.hpp
    title: convex/minplus_convolution_of_triples.hpp
  _extendedVerifiedWith:
  - icon: ':x:'
    path: test/1_mytest/minplus_conv_triple.test.cpp
    title: test/1_mytest/minplus_conv_triple.test.cpp
  - icon: ':x:'
    path: test/1_mytest/minplus_convex.test.cpp
    title: test/1_mytest/minplus_convex.test.cpp
  - icon: ':x:'
    path: test/2_library_checker/convolution/minplus_convolution_conv_arb.test.cpp
    title: test/2_library_checker/convolution/minplus_convolution_conv_arb.test.cpp
  - icon: ':x:'
    path: test/2_library_checker/convolution/minplus_convolution_conv_conv.test.cpp
    title: test/2_library_checker/convolution/minplus_convolution_conv_conv.test.cpp
  _isVerificationFailed: true
  _pathExtension: hpp
  _verificationStatusIcon: ':x:'
  attributes:
    links: []
  bundledCode: "#line 2 \"convex/minplus_convolution.hpp\"\n\ntemplate <typename T>\n\
    vc<T> minplus_convolution_convex_convex(vc<T>& A, vc<T>& B) {\n  int n = len(A),\
    \ m = len(B);\n  if (n == 0 || m == 0) return {};\n  vc<T> C(n + m - 1, infty<T>);\n\
    \  while (n > 0 && A[n - 1] == infty<T>) --n;\n  while (m > 0 && B[m - 1] == infty<T>)\
    \ --m;\n  if (n == 0 || m == 0) return C;\n  int a = 0, b = 0;\n  while (a < n\
    \ && A[a] == infty<T>) ++a;\n  while (b < m && B[b] == infty<T>) ++b;\n  C[a +\
    \ b] = A[a] + B[b];\n  for (int i = a + b + 1; i < n + m - 1; ++i) {\n    if (b\
    \ == m - 1 || (a != n - 1 && A[a + 1] + B[b] < A[a] + B[b + 1])) {\n      chmin(C[i],\
    \ A[++a] + B[b]);\n    } else {\n      chmin(C[i], A[a] + B[++b]);\n    }\n  }\n\
    \  return C;\n}\n\ntemplate <typename T>\nvc<T> minplus_convolution_arbitrary_convex(vc<T>&\
    \ A, vc<T>& B) {\n  int n = len(A), m0 = len(B);\n  if (n == 0 || m0 == 0) return\
    \ {};\n  vc<T> C(n + m0 - 1, infty<T>);\n  int m = m0;\n  while (m > 0 && B[m\
    \ - 1] == infty<T>) --m;\n  if (m == 0) return C;\n  int b = 0;\n  while (b <\
    \ m && B[b] == infty<T>) ++b;\n\n  int z = n + m - b - 1;\n  vc<int> idx(z + 1);\n\
    \  C[b] = A[0] + B[b];\n  idx[0] = 0, idx[z] = n - 1;\n\n  int d = 1;\n  while\
    \ (d < z) d <<= 1;\n  for (int q = d >> 1; q > 0; q >>= 1) {\n    for (int h =\
    \ q; h < z; h += q << 1) {\n      int l = h - q;\n      int r = min(h + q, z);\n\
    \      idx[h] = idx[l];\n      for (int j = idx[l]; j <= idx[r]; ++j) {\n    \
    \    if (j <= h && h - j < m - b && C[b + h] >= A[j] + B[b + h - j]) {\n     \
    \     C[b + h] = A[j] + B[b + h - j];\n          idx[h] = j;\n        }\n    \
    \  }\n    }\n  }\n  return C;\n}\n\ntemplate <typename T, bool convA, bool convB>\n\
    vc<T> minplus_convolution(vc<T>& A, vc<T>& B) {\n  static_assert(convA || convB);\n\
    \  if constexpr (convA && convB) return minplus_convolution_convex_convex(A, B);\n\
    \  if constexpr (convA && !convB)\n    return minplus_convolution_arbitrary_convex(B,\
    \ A);\n  if constexpr (convB && !convA)\n    return minplus_convolution_arbitrary_convex(A,\
    \ B);\n  return {};\n}\n"
  code: "#pragma once\n\ntemplate <typename T>\nvc<T> minplus_convolution_convex_convex(vc<T>&\
    \ A, vc<T>& B) {\n  int n = len(A), m = len(B);\n  if (n == 0 || m == 0) return\
    \ {};\n  vc<T> C(n + m - 1, infty<T>);\n  while (n > 0 && A[n - 1] == infty<T>)\
    \ --n;\n  while (m > 0 && B[m - 1] == infty<T>) --m;\n  if (n == 0 || m == 0)\
    \ return C;\n  int a = 0, b = 0;\n  while (a < n && A[a] == infty<T>) ++a;\n \
    \ while (b < m && B[b] == infty<T>) ++b;\n  C[a + b] = A[a] + B[b];\n  for (int\
    \ i = a + b + 1; i < n + m - 1; ++i) {\n    if (b == m - 1 || (a != n - 1 && A[a\
    \ + 1] + B[b] < A[a] + B[b + 1])) {\n      chmin(C[i], A[++a] + B[b]);\n    }\
    \ else {\n      chmin(C[i], A[a] + B[++b]);\n    }\n  }\n  return C;\n}\n\ntemplate\
    \ <typename T>\nvc<T> minplus_convolution_arbitrary_convex(vc<T>& A, vc<T>& B)\
    \ {\n  int n = len(A), m0 = len(B);\n  if (n == 0 || m0 == 0) return {};\n  vc<T>\
    \ C(n + m0 - 1, infty<T>);\n  int m = m0;\n  while (m > 0 && B[m - 1] == infty<T>)\
    \ --m;\n  if (m == 0) return C;\n  int b = 0;\n  while (b < m && B[b] == infty<T>)\
    \ ++b;\n\n  int z = n + m - b - 1;\n  vc<int> idx(z + 1);\n  C[b] = A[0] + B[b];\n\
    \  idx[0] = 0, idx[z] = n - 1;\n\n  int d = 1;\n  while (d < z) d <<= 1;\n  for\
    \ (int q = d >> 1; q > 0; q >>= 1) {\n    for (int h = q; h < z; h += q << 1)\
    \ {\n      int l = h - q;\n      int r = min(h + q, z);\n      idx[h] = idx[l];\n\
    \      for (int j = idx[l]; j <= idx[r]; ++j) {\n        if (j <= h && h - j <\
    \ m - b && C[b + h] >= A[j] + B[b + h - j]) {\n          C[b + h] = A[j] + B[b\
    \ + h - j];\n          idx[h] = j;\n        }\n      }\n    }\n  }\n  return C;\n\
    }\n\ntemplate <typename T, bool convA, bool convB>\nvc<T> minplus_convolution(vc<T>&\
    \ A, vc<T>& B) {\n  static_assert(convA || convB);\n  if constexpr (convA && convB)\
    \ return minplus_convolution_convex_convex(A, B);\n  if constexpr (convA && !convB)\n\
    \    return minplus_convolution_arbitrary_convex(B, A);\n  if constexpr (convB\
    \ && !convA)\n    return minplus_convolution_arbitrary_convex(A, B);\n  return\
    \ {};\n}\n"
  dependsOn: []
  isVerificationFile: false
  path: convex/minplus_convolution.hpp
  requiredBy:
  - convex/minplus_convolution_of_triples.hpp
  timestamp: '2026-05-31 18:02:06+09:00'
  verificationStatus: LIBRARY_ALL_WA
  verifiedWith:
  - test/2_library_checker/convolution/minplus_convolution_conv_conv.test.cpp
  - test/2_library_checker/convolution/minplus_convolution_conv_arb.test.cpp
  - test/1_mytest/minplus_convex.test.cpp
  - test/1_mytest/minplus_conv_triple.test.cpp
documentation_of: convex/minplus_convolution.hpp
layout: document
redirect_from:
- /library/convex/minplus_convolution.hpp
- /library/convex/minplus_convolution.hpp.html
title: convex/minplus_convolution.hpp
---
