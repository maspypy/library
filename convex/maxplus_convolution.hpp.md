---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':x:'
    path: test/1_mytest/maxplus_concave.test.cpp
    title: test/1_mytest/maxplus_concave.test.cpp
  _isVerificationFailed: true
  _pathExtension: hpp
  _verificationStatusIcon: ':x:'
  attributes:
    links: []
  bundledCode: "#line 1 \"convex/maxplus_convolution.hpp\"\n\ntemplate <typename T>\n\
    vc<T> maxplus_convolution_concave_concave(vc<T>& A, vc<T>& B) {\n  int n = len(A),\
    \ m = len(B);\n  if (n == 0 || m == 0) return {};\n  vc<T> C(n + m - 1, -infty<T>);\n\
    \  while (n > 0 && A[n - 1] == -infty<T>) --n;\n  while (m > 0 && B[m - 1] ==\
    \ -infty<T>) --m;\n  if (n == 0 || m == 0) return C;\n  int a = 0, b = 0;\n  while\
    \ (a < n && A[a] == -infty<T>) ++a;\n  while (b < m && B[b] == -infty<T>) ++b;\n\
    \  C[a + b] = A[a] + B[b];\n  for (int i = a + b + 1; i < n + m - 1; ++i) {\n\
    \    if (b == m - 1 || (a != n - 1 && A[a + 1] + B[b] > A[a] + B[b + 1])) {\n\
    \      chmax(C[i], A[++a] + B[b]);\n    } else {\n      chmax(C[i], A[a] + B[++b]);\n\
    \    }\n  }\n  return C;\n}\n\ntemplate <typename T>\nvc<T> maxplus_convolution_arbitrary_concave(vc<T>&\
    \ A, vc<T>& B) {\n  int n = len(A), m0 = len(B);\n  if (n == 0 || m0 == 0) return\
    \ {};\n  vc<T> C(n + m0 - 1, -infty<T>);\n  int m = m0;\n  while (m > 0 && B[m\
    \ - 1] == -infty<T>) --m;\n  if (m == 0) return C;\n  int b = 0;\n  while (b <\
    \ m && B[b] == -infty<T>) ++b;\n\n  int z = n + m - b - 1;\n  vc<int> idx(z +\
    \ 1);\n  C[b] = A[0] + B[b];\n  idx[0] = 0, idx[z] = n - 1;\n\n  int d = 1;\n\
    \  while (d < z) d <<= 1;\n  for (int q = d >> 1; q > 0; q >>= 1) {\n    for (int\
    \ h = q; h < z; h += q << 1) {\n      int l = h - q;\n      int r = min(h + q,\
    \ z);\n      idx[h] = idx[l];\n      for (int j = idx[l]; j <= idx[r]; ++j) {\n\
    \        if (j <= h && h - j < m - b && C[b + h] <= A[j] + B[b + h - j]) {\n \
    \         C[b + h] = A[j] + B[b + h - j];\n          idx[h] = j;\n        }\n\
    \      }\n    }\n  }\n  return C;\n}\n\ntemplate <typename T, bool conA, bool\
    \ conB>\nvc<T> maxplus_convolution(vc<T>& A, vc<T>& B) {\n  static_assert(conA\
    \ || conB);\n  if constexpr (conA && conB) return maxplus_convolution_concave_concave(A,\
    \ B);\n  if constexpr (conA && !conB)\n    return maxplus_convolution_arbitrary_concave(B,\
    \ A);\n  if constexpr (conB && !conA)\n    return maxplus_convolution_arbitrary_concave(A,\
    \ B);\n  return {};\n}\n"
  code: "\ntemplate <typename T>\nvc<T> maxplus_convolution_concave_concave(vc<T>&\
    \ A, vc<T>& B) {\n  int n = len(A), m = len(B);\n  if (n == 0 || m == 0) return\
    \ {};\n  vc<T> C(n + m - 1, -infty<T>);\n  while (n > 0 && A[n - 1] == -infty<T>)\
    \ --n;\n  while (m > 0 && B[m - 1] == -infty<T>) --m;\n  if (n == 0 || m == 0)\
    \ return C;\n  int a = 0, b = 0;\n  while (a < n && A[a] == -infty<T>) ++a;\n\
    \  while (b < m && B[b] == -infty<T>) ++b;\n  C[a + b] = A[a] + B[b];\n  for (int\
    \ i = a + b + 1; i < n + m - 1; ++i) {\n    if (b == m - 1 || (a != n - 1 && A[a\
    \ + 1] + B[b] > A[a] + B[b + 1])) {\n      chmax(C[i], A[++a] + B[b]);\n    }\
    \ else {\n      chmax(C[i], A[a] + B[++b]);\n    }\n  }\n  return C;\n}\n\ntemplate\
    \ <typename T>\nvc<T> maxplus_convolution_arbitrary_concave(vc<T>& A, vc<T>& B)\
    \ {\n  int n = len(A), m0 = len(B);\n  if (n == 0 || m0 == 0) return {};\n  vc<T>\
    \ C(n + m0 - 1, -infty<T>);\n  int m = m0;\n  while (m > 0 && B[m - 1] == -infty<T>)\
    \ --m;\n  if (m == 0) return C;\n  int b = 0;\n  while (b < m && B[b] == -infty<T>)\
    \ ++b;\n\n  int z = n + m - b - 1;\n  vc<int> idx(z + 1);\n  C[b] = A[0] + B[b];\n\
    \  idx[0] = 0, idx[z] = n - 1;\n\n  int d = 1;\n  while (d < z) d <<= 1;\n  for\
    \ (int q = d >> 1; q > 0; q >>= 1) {\n    for (int h = q; h < z; h += q << 1)\
    \ {\n      int l = h - q;\n      int r = min(h + q, z);\n      idx[h] = idx[l];\n\
    \      for (int j = idx[l]; j <= idx[r]; ++j) {\n        if (j <= h && h - j <\
    \ m - b && C[b + h] <= A[j] + B[b + h - j]) {\n          C[b + h] = A[j] + B[b\
    \ + h - j];\n          idx[h] = j;\n        }\n      }\n    }\n  }\n  return C;\n\
    }\n\ntemplate <typename T, bool conA, bool conB>\nvc<T> maxplus_convolution(vc<T>&\
    \ A, vc<T>& B) {\n  static_assert(conA || conB);\n  if constexpr (conA && conB)\
    \ return maxplus_convolution_concave_concave(A, B);\n  if constexpr (conA && !conB)\n\
    \    return maxplus_convolution_arbitrary_concave(B, A);\n  if constexpr (conB\
    \ && !conA)\n    return maxplus_convolution_arbitrary_concave(A, B);\n  return\
    \ {};\n}\n"
  dependsOn: []
  isVerificationFile: false
  path: convex/maxplus_convolution.hpp
  requiredBy: []
  timestamp: '2026-08-16 04:03:00+09:00'
  verificationStatus: LIBRARY_ALL_WA
  verifiedWith:
  - test/1_mytest/maxplus_concave.test.cpp
documentation_of: convex/maxplus_convolution.hpp
layout: document
redirect_from:
- /library/convex/maxplus_convolution.hpp
- /library/convex/maxplus_convolution.hpp.html
title: convex/maxplus_convolution.hpp
---
