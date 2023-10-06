---
data:
  _extendedDependsOn:
  - icon: ':question:'
    path: convex/monotone_minima.hpp
    title: convex/monotone_minima.hpp
  _extendedRequiredBy:
  - icon: ':x:'
    path: convex/minplus_convolution_of_triples.hpp
    title: convex/minplus_convolution_of_triples.hpp
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/library_checker/convolution/minplus_convolution_conv_arb.test.cpp
    title: test/library_checker/convolution/minplus_convolution_conv_arb.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/library_checker/convolution/minplus_convolution_conv_conv.test.cpp
    title: test/library_checker/convolution/minplus_convolution_conv_conv.test.cpp
  - icon: ':x:'
    path: test/mytest/minplus_conv_triple.test.cpp
    title: test/mytest/minplus_conv_triple.test.cpp
  - icon: ':x:'
    path: test/mytest/minplus_convex.test.cpp
    title: test/mytest/minplus_convex.test.cpp
  _isVerificationFailed: true
  _pathExtension: hpp
  _verificationStatusIcon: ':question:'
  attributes:
    links: []
  bundledCode: "#line 1 \"convex/monotone_minima.hpp\"\n\n// select(i,j,k) : (i,j)\
    \ -> (i,k) \u3092\u884C\u3046\u304B\u3069\u3046\u304B\ntemplate <typename F>\n\
    vc<int> monotone_minima(int H, int W, F select) {\n  vc<int> min_col(H);\n  auto\
    \ dfs = [&](auto& dfs, int x1, int x2, int y1, int y2) -> void {\n    if (x1 ==\
    \ x2) return;\n    int x = (x1 + x2) / 2;\n    int best_y = y1;\n    for (int\
    \ y = y1 + 1; y < y2; ++y) {\n      if (select(x, best_y, y)) best_y = y;\n  \
    \  }\n    min_col[x] = best_y;\n    dfs(dfs, x1, x, y1, best_y + 1);\n    dfs(dfs,\
    \ x + 1, x2, best_y, y2);\n  };\n  dfs(dfs, 0, H, 0, W);\n  return min_col;\n\
    }\n#line 2 \"convex/minplus_convolution.hpp\"\n\ntemplate <typename T>\nvc<T>\
    \ minplus_convolution_convex_convex(vc<T>& A, vc<T>& B) {\n  int n = len(A), m\
    \ = len(B);\n  if (n == 0 && m == 0) return {};\n  vc<T> C(n + m - 1, infty<T>);\n\
    \  while (n > 0 && A[n - 1] == infty<T>) --n;\n  while (m > 0 && B[m - 1] == infty<T>)\
    \ --m;\n  if (n == 0 && m == 0) return C;\n  int a = 0, b = 0;\n  while (a < n\
    \ && A[a] == infty<T>) ++a;\n  while (b < m && B[b] == infty<T>) ++b;\n  C[a +\
    \ b] = A[a] + B[b];\n  for (int i = a + b + 1; i < n + m - 1; ++i) {\n    if (b\
    \ == m - 1 || (a != n - 1 && A[a + 1] + B[b] < A[a] + B[b + 1])) {\n      chmin(C[i],\
    \ A[++a] + B[b]);\n    } else {\n      chmin(C[i], A[a] + B[++b]);\n    }\n  }\n\
    \  return C;\n}\n\ntemplate <typename T>\nvc<T> minplus_convolution_arbitrary_convex(vc<T>&\
    \ A, vc<T>& B) {\n  int n = len(A), m = len(B);\n  if (n == 0 && m == 0) return\
    \ {};\n  vc<T> C(n + m - 1, infty<T>);\n  while (m > 0 && B[m - 1] == infty<T>)\
    \ --m;\n  if (m == 0) return C;\n  int b = 0;\n  while (b < m && B[b] == infty<T>)\
    \ ++b;\n\n  auto select = [&](int i, int j, int k) -> bool {\n    if (i < k) return\
    \ false;\n    if (i - j >= m - b) return true;\n    return A[j] + B[b + i - j]\
    \ >= A[k] + B[b + i - k];\n  };\n  vc<int> J = monotone_minima(n + m - b - 1,\
    \ n, select);\n  FOR(i, n + m - b - 1) {\n    T x = A[J[i]], y = B[b + i - J[i]];\n\
    \    if (x < infty<T> && y < infty<T>) C[b + i] = x + y;\n  }\n  return C;\n}\n\
    \ntemplate <typename T, bool convA, bool convB>\nvc<T> minplus_convolution(vc<T>&\
    \ A, vc<T>& B) {\n  static_assert(convA || convB);\n  if constexpr (convA && convB)\
    \ return minplus_convolution_convex_convex(A, B);\n  if constexpr (convA && !convB)\n\
    \    return minplus_convolution_arbitrary_convex(B, A);\n  if constexpr (convB\
    \ && !convA)\n    return minplus_convolution_arbitrary_convex(A, B);\n  return\
    \ {};\n}\n"
  code: "#include \"convex/monotone_minima.hpp\"\n\ntemplate <typename T>\nvc<T> minplus_convolution_convex_convex(vc<T>&\
    \ A, vc<T>& B) {\n  int n = len(A), m = len(B);\n  if (n == 0 && m == 0) return\
    \ {};\n  vc<T> C(n + m - 1, infty<T>);\n  while (n > 0 && A[n - 1] == infty<T>)\
    \ --n;\n  while (m > 0 && B[m - 1] == infty<T>) --m;\n  if (n == 0 && m == 0)\
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
  timestamp: '2023-08-10 03:11:20+09:00'
  verificationStatus: LIBRARY_SOME_WA
  verifiedWith:
  - test/library_checker/convolution/minplus_convolution_conv_conv.test.cpp
  - test/library_checker/convolution/minplus_convolution_conv_arb.test.cpp
  - test/mytest/minplus_convex.test.cpp
  - test/mytest/minplus_conv_triple.test.cpp
documentation_of: convex/minplus_convolution.hpp
layout: document
redirect_from:
- /library/convex/minplus_convolution.hpp
- /library/convex/minplus_convolution.hpp.html
title: convex/minplus_convolution.hpp
---
