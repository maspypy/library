---
data:
  _extendedDependsOn:
  - icon: ':question:'
    path: convex/monotone_minima.hpp
    title: convex/monotone_minima.hpp
  - icon: ':question:'
    path: convex/smawk.hpp
    title: convex/smawk.hpp
  _extendedRequiredBy:
  - icon: ':x:'
    path: convex/minplus_convolution_of_triples.hpp
    title: convex/minplus_convolution_of_triples.hpp
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/library_checker/convolution/minplus_convolution_conv_arb.test.cpp
    title: test/library_checker/convolution/minplus_convolution_conv_arb.test.cpp
  - icon: ':x:'
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
    }\n#line 2 \"convex/smawk.hpp\"\n\n// select(i,j,k) \u306F (i,j) -> (i,k) \u3092\
    \u884C\u3046\u304B\u3069\u3046\u304B\n// \u6B8B\u5FF5\u306A\u304C\u3089 monotone\
    \ minima \u3088\u308A\u9AD8\u901F\u306A\u5834\u5408\u304C\u5B58\u5728\u3057\u306A\
    \u3044\u8AAC\u304C\u3042\u308B\ntemplate <typename F>\nvc<int> smawk(int H, int\
    \ W, F select) {\n  auto dfs = [&](auto& dfs, vc<int> X, vc<int> Y) -> vc<int>\
    \ {\n    int N = len(X);\n    if (N == 0) return {};\n    vc<int> YY;\n    for\
    \ (auto&& y: Y) {\n      while (len(YY)) {\n        int py = YY.back(), x = X[len(YY)\
    \ - 1];\n        if (!select(x, py, y)) break;\n        YY.pop_back();\n     \
    \ }\n      if (len(YY) < len(X)) YY.eb(y);\n    }\n    vc<int> XX;\n    FOR(i,\
    \ 1, len(X), 2) XX.eb(X[i]);\n    vc<int> II = dfs(dfs, XX, YY);\n    vc<int>\
    \ I(N);\n    FOR(i, len(II)) I[i + i + 1] = II[i];\n    int p = 0;\n    FOR(i,\
    \ 0, N, 2) {\n      int LIM = (i + 1 == N ? Y.back() : I[i + 1]);\n      int best\
    \ = Y[p];\n      while (Y[p] < LIM) {\n        ++p;\n        if (select(X[i],\
    \ best, Y[p])) best = Y[p];\n      }\n      I[i] = best;\n    }\n    return I;\n\
    \  };\n  vc<int> X(H), Y(W);\n  iota(all(X), 0), iota(all(Y), 0);\n  return dfs(dfs,\
    \ X, Y);\n}\n#line 3 \"convex/minplus_convolution_convex.hpp\"\n\ntemplate <typename\
    \ T>\nvc<T> minplus_convolution_convex_convex(vc<T>& A, vc<T>& B) {\n  const int\
    \ n = len(A), m = len(B);\n  if (n == 0 && m == 0) return {};\n  vc<T> C(n + m\
    \ - 1);\n  int a = 0, b = 0;\n  C[0] = A[0] + B[0];\n  for (int i = 1; i < n +\
    \ m - 1; ++i) {\n    if (b == m - 1 || (a != n - 1 && A[a + 1] + B[b] < A[a] +\
    \ B[b + 1])) {\n      C[i] = A[++a] + B[b];\n    } else {\n      C[i] = A[a] +\
    \ B[++b];\n    }\n  }\n  return C;\n}\n\ntemplate <typename T>\nvc<T> minplus_convolution_arbitrary_convex(vc<T>&\
    \ a, vc<T>& b) {\n  int n = len(a), m = len(b);\n  auto select = [&](int i, int\
    \ j, int k) -> bool {\n    if (i < k) return false;\n    if (i - j >= m) return\
    \ true;\n    return a[j] + b[i - j] >= a[k] + b[i - k];\n  };\n  vc<int> J = smawk(n\
    \ + m - 1, n, select);\n  // vc<int> J = monotone_minima(n + m - 1, n, select);\n\
    \  vc<T> c(n + m - 1);\n  FOR(i, n + m - 1) c[i] = a[J[i]] + b[i - J[i]];\n  return\
    \ c;\n}\n\ntemplate <typename T, bool convA, bool convB>\nvc<T> minplus_convolution(vc<T>&\
    \ A, vc<T>& B) {\n  static_assert(convA || convB);\n  if constexpr (convA && convB)\
    \ return minplus_convolution_convex_convex(A, B);\n  if constexpr (convA && !convB)\n\
    \    return minplus_convolution_arbitrary_convex(B, A);\n  if constexpr (convB\
    \ && !convA)\n    return minplus_convolution_arbitrary_convex(A, B);\n  return\
    \ {};\n}\n"
  code: "#include \"convex/monotone_minima.hpp\"\n#include \"convex/smawk.hpp\"\n\n\
    template <typename T>\nvc<T> minplus_convolution_convex_convex(vc<T>& A, vc<T>&\
    \ B) {\n  const int n = len(A), m = len(B);\n  if (n == 0 && m == 0) return {};\n\
    \  vc<T> C(n + m - 1);\n  int a = 0, b = 0;\n  C[0] = A[0] + B[0];\n  for (int\
    \ i = 1; i < n + m - 1; ++i) {\n    if (b == m - 1 || (a != n - 1 && A[a + 1]\
    \ + B[b] < A[a] + B[b + 1])) {\n      C[i] = A[++a] + B[b];\n    } else {\n  \
    \    C[i] = A[a] + B[++b];\n    }\n  }\n  return C;\n}\n\ntemplate <typename T>\n\
    vc<T> minplus_convolution_arbitrary_convex(vc<T>& a, vc<T>& b) {\n  int n = len(a),\
    \ m = len(b);\n  auto select = [&](int i, int j, int k) -> bool {\n    if (i <\
    \ k) return false;\n    if (i - j >= m) return true;\n    return a[j] + b[i -\
    \ j] >= a[k] + b[i - k];\n  };\n  vc<int> J = smawk(n + m - 1, n, select);\n \
    \ // vc<int> J = monotone_minima(n + m - 1, n, select);\n  vc<T> c(n + m - 1);\n\
    \  FOR(i, n + m - 1) c[i] = a[J[i]] + b[i - J[i]];\n  return c;\n}\n\ntemplate\
    \ <typename T, bool convA, bool convB>\nvc<T> minplus_convolution(vc<T>& A, vc<T>&\
    \ B) {\n  static_assert(convA || convB);\n  if constexpr (convA && convB) return\
    \ minplus_convolution_convex_convex(A, B);\n  if constexpr (convA && !convB)\n\
    \    return minplus_convolution_arbitrary_convex(B, A);\n  if constexpr (convB\
    \ && !convA)\n    return minplus_convolution_arbitrary_convex(A, B);\n  return\
    \ {};\n}\n"
  dependsOn:
  - convex/monotone_minima.hpp
  - convex/smawk.hpp
  isVerificationFile: false
  path: convex/minplus_convolution_convex.hpp
  requiredBy:
  - convex/minplus_convolution_of_triples.hpp
  timestamp: '2023-08-10 00:32:23+09:00'
  verificationStatus: LIBRARY_SOME_WA
  verifiedWith:
  - test/mytest/minplus_conv_triple.test.cpp
  - test/mytest/minplus_convex.test.cpp
  - test/library_checker/convolution/minplus_convolution_conv_arb.test.cpp
  - test/library_checker/convolution/minplus_convolution_conv_conv.test.cpp
documentation_of: convex/minplus_convolution_convex.hpp
layout: document
redirect_from:
- /library/convex/minplus_convolution_convex.hpp
- /library/convex/minplus_convolution_convex.hpp.html
title: convex/minplus_convolution_convex.hpp
---
