---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: convex/monotone_minima.hpp
    title: convex/monotone_minima.hpp
  _extendedRequiredBy:
  - icon: ':heavy_check_mark:'
    path: convex/minplus_convolution_of_triples.hpp
    title: convex/minplus_convolution_of_triples.hpp
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/1_mytest/minplus_conv_triple.test.cpp
    title: test/1_mytest/minplus_conv_triple.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/1_mytest/minplus_convex.test.cpp
    title: test/1_mytest/minplus_convex.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/2_library_checker/convolution/minplus_convolution_conv_arb.test.cpp
    title: test/2_library_checker/convolution/minplus_convolution_conv_arb.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/2_library_checker/convolution/minplus_convolution_conv_conv.test.cpp
    title: test/2_library_checker/convolution/minplus_convolution_conv_conv.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 2 \"convex/monotone_minima.hpp\"\n\n// \u5404\u884C\u306E\u6700\
    \u9069\u5217\u3092\u6C42\u3081\u308B\n// better(i,j,k): \u884C i \u306B\u304A\u3044\
    \u3066\u5217 k \u304C\u5217 j \u3088\u308A\u826F\u3044\u3068\u304D true\n// \u9069\
    \u7528\u6761\u4EF6\uFF1Abetter \u306B\u3088\u3063\u3066\u9078\u3070\u308C\u308B\
    \u6700\u9069\u5217 opt[i] \u304C i \u306B\u3064\u3044\u3066\u5E83\u7FA9\u5358\u8ABF\
    \u5897\u52A0\ntemplate <typename F>\nvc<int> monotone_minima(int H, int W, F better)\
    \ {\n  if (H == 0) return {};\n  assert(H > 0 && W > 0);\n\n  vc<int> idx(H +\
    \ 1);\n  idx[0] = 0;\n  FOR(y, 1, W) {\n    if (better(0, idx[0], y)) idx[0] =\
    \ y;\n  }\n  idx[H] = W - 1;\n\n  int d = 1;\n  while (d < H) d <<= 1;\n  for\
    \ (int q = d >> 1; q > 0; q >>= 1) {\n    for (int h = q; h < H; h += q << 1)\
    \ {\n      int l = h - q;\n      int r = min(h + q, H);\n      int best = idx[l];\n\
    \      for (int y = idx[l] + 1; y <= idx[r]; ++y) {\n        if (better(h, best,\
    \ y)) best = y;\n      }\n      idx[h] = best;\n    }\n  }\n  idx.pop_back();\n\
    \  return idx;\n}\n#line 2 \"convex/minplus_convolution.hpp\"\n\ntemplate <typename\
    \ T>\nvc<T> minplus_convolution_convex_convex(vc<T>& A, vc<T>& B) {\n  int n =\
    \ len(A), m = len(B);\n  if (n == 0 && m == 0) return {};\n  vc<T> C(n + m - 1,\
    \ infty<T>);\n  while (n > 0 && A[n - 1] == infty<T>) --n;\n  while (m > 0 &&\
    \ B[m - 1] == infty<T>) --m;\n  if (n == 0 || m == 0) return C;\n  int a = 0,\
    \ b = 0;\n  while (a < n && A[a] == infty<T>) ++a;\n  while (b < m && B[b] ==\
    \ infty<T>) ++b;\n  C[a + b] = A[a] + B[b];\n  for (int i = a + b + 1; i < n +\
    \ m - 1; ++i) {\n    if (b == m - 1 || (a != n - 1 && A[a + 1] + B[b] < A[a] +\
    \ B[b + 1])) {\n      chmin(C[i], A[++a] + B[b]);\n    } else {\n      chmin(C[i],\
    \ A[a] + B[++b]);\n    }\n  }\n  return C;\n}\n\ntemplate <typename T>\nvc<T>\
    \ minplus_convolution_arbitrary_convex(vc<T>& A, vc<T>& B) {\n  int n = len(A),\
    \ m = len(B);\n  if (n == 0 && m == 0) return {};\n  vc<T> C(n + m - 1, infty<T>);\n\
    \  while (m > 0 && B[m - 1] == infty<T>) --m;\n  if (m == 0) return C;\n  int\
    \ b = 0;\n  while (b < m && B[b] == infty<T>) ++b;\n\n  auto select = [&](int\
    \ i, int j, int k) -> bool {\n    if (i < k) return false;\n    if (i - j >= m\
    \ - b) return true;\n    return A[j] + B[b + i - j] >= A[k] + B[b + i - k];\n\
    \  };\n  vc<int> J = monotone_minima(n + m - b - 1, n, select);\n  FOR(i, n +\
    \ m - b - 1) {\n    T x = A[J[i]], y = B[b + i - J[i]];\n    if (x < infty<T>\
    \ && y < infty<T>) C[b + i] = x + y;\n  }\n  return C;\n}\n\ntemplate <typename\
    \ T, bool convA, bool convB>\nvc<T> minplus_convolution(vc<T>& A, vc<T>& B) {\n\
    \  static_assert(convA || convB);\n  if constexpr (convA && convB) return minplus_convolution_convex_convex(A,\
    \ B);\n  if constexpr (convA && !convB)\n    return minplus_convolution_arbitrary_convex(B,\
    \ A);\n  if constexpr (convB && !convA)\n    return minplus_convolution_arbitrary_convex(A,\
    \ B);\n  return {};\n}\n"
  code: "#include \"convex/monotone_minima.hpp\"\n\ntemplate <typename T>\nvc<T> minplus_convolution_convex_convex(vc<T>&\
    \ A, vc<T>& B) {\n  int n = len(A), m = len(B);\n  if (n == 0 && m == 0) return\
    \ {};\n  vc<T> C(n + m - 1, infty<T>);\n  while (n > 0 && A[n - 1] == infty<T>)\
    \ --n;\n  while (m > 0 && B[m - 1] == infty<T>) --m;\n  if (n == 0 || m == 0)\
    \ return C;\n  int a = 0, b = 0;\n  while (a < n && A[a] == infty<T>) ++a;\n \
    \ while (b < m && B[b] == infty<T>) ++b;\n  C[a + b] = A[a] + B[b];\n  for (int\
    \ i = a + b + 1; i < n + m - 1; ++i) {\n    if (b == m - 1 || (a != n - 1 && A[a\
    \ + 1] + B[b] < A[a] + B[b + 1])) {\n      chmin(C[i], A[++a] + B[b]);\n    }\
    \ else {\n      chmin(C[i], A[a] + B[++b]);\n    }\n  }\n  return C;\n}\n\ntemplate\
    \ <typename T>\nvc<T> minplus_convolution_arbitrary_convex(vc<T>& A, vc<T>& B)\
    \ {\n  int n = len(A), m = len(B);\n  if (n == 0 && m == 0) return {};\n  vc<T>\
    \ C(n + m - 1, infty<T>);\n  while (m > 0 && B[m - 1] == infty<T>) --m;\n  if\
    \ (m == 0) return C;\n  int b = 0;\n  while (b < m && B[b] == infty<T>) ++b;\n\
    \n  auto select = [&](int i, int j, int k) -> bool {\n    if (i < k) return false;\n\
    \    if (i - j >= m - b) return true;\n    return A[j] + B[b + i - j] >= A[k]\
    \ + B[b + i - k];\n  };\n  vc<int> J = monotone_minima(n + m - b - 1, n, select);\n\
    \  FOR(i, n + m - b - 1) {\n    T x = A[J[i]], y = B[b + i - J[i]];\n    if (x\
    \ < infty<T> && y < infty<T>) C[b + i] = x + y;\n  }\n  return C;\n}\n\ntemplate\
    \ <typename T, bool convA, bool convB>\nvc<T> minplus_convolution(vc<T>& A, vc<T>&\
    \ B) {\n  static_assert(convA || convB);\n  if constexpr (convA && convB) return\
    \ minplus_convolution_convex_convex(A, B);\n  if constexpr (convA && !convB)\n\
    \    return minplus_convolution_arbitrary_convex(B, A);\n  if constexpr (convB\
    \ && !convA)\n    return minplus_convolution_arbitrary_convex(A, B);\n  return\
    \ {};\n}\n"
  dependsOn:
  - convex/monotone_minima.hpp
  isVerificationFile: false
  path: convex/minplus_convolution.hpp
  requiredBy:
  - convex/minplus_convolution_of_triples.hpp
  timestamp: '2026-05-31 17:32:53+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/1_mytest/minplus_conv_triple.test.cpp
  - test/1_mytest/minplus_convex.test.cpp
  - test/2_library_checker/convolution/minplus_convolution_conv_arb.test.cpp
  - test/2_library_checker/convolution/minplus_convolution_conv_conv.test.cpp
documentation_of: convex/minplus_convolution.hpp
layout: document
redirect_from:
- /library/convex/minplus_convolution.hpp
- /library/convex/minplus_convolution.hpp.html
title: convex/minplus_convolution.hpp
---
