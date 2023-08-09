---
data:
  _extendedDependsOn:
  - icon: ':warning:'
    path: convex/monotone_minima.hpp
    title: convex/monotone_minima.hpp
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':warning:'
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
    \ minplus_convolution_convex_convex(vc<T>& A, vc<T>& B) {\n  const int n = len(A),\
    \ m = len(B);\n  if (n == 0 && m == 0) return {};\n  vc<T> C(n + m - 1);\n  int\
    \ a = 0, b = 0;\n  C[0] = A[0] + B[0];\n  for (int i = 1; i < n + m - 1; ++i)\
    \ {\n    if (b == m - 1 || (a != n - 1 && A[a + 1] + B[b] < A[a] + B[b + 1]))\
    \ {\n      C[i] = A[++a] + B[b];\n    } else {\n      C[i] = A[a] + B[++b];\n\
    \    }\n  }\n  return C;\n}\n\ntemplate <typename T>\nvc<T> minplus_convolution_arbitrary_convex(vc<T>&\
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
  code: "#include \"convex/monotone_minima.hpp\"\n\ntemplate <typename T>\nvc<T> minplus_convolution_convex_convex(vc<T>&\
    \ A, vc<T>& B) {\n  const int n = len(A), m = len(B);\n  if (n == 0 && m == 0)\
    \ return {};\n  vc<T> C(n + m - 1);\n  int a = 0, b = 0;\n  C[0] = A[0] + B[0];\n\
    \  for (int i = 1; i < n + m - 1; ++i) {\n    if (b == m - 1 || (a != n - 1 &&\
    \ A[a + 1] + B[b] < A[a] + B[b + 1])) {\n      C[i] = A[++a] + B[b];\n    } else\
    \ {\n      C[i] = A[a] + B[++b];\n    }\n  }\n  return C;\n}\n\ntemplate <typename\
    \ T>\nvc<T> minplus_convolution_arbitrary_convex(vc<T>& a, vc<T>& b) {\n  int\
    \ n = len(a), m = len(b);\n  auto select = [&](int i, int j, int k) -> bool {\n\
    \    if (i < k) return false;\n    if (i - j >= m) return true;\n    return a[j]\
    \ + b[i - j] >= a[k] + b[i - k];\n  };\n  vc<int> J = smawk(n + m - 1, n, select);\n\
    \  // vc<int> J = monotone_minima(n + m - 1, n, select);\n  vc<T> c(n + m - 1);\n\
    \  FOR(i, n + m - 1) c[i] = a[J[i]] + b[i - J[i]];\n  return c;\n}\n\ntemplate\
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
  requiredBy: []
  timestamp: '2023-08-10 02:06:33+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: convex/minplus_convolution.hpp
layout: document
redirect_from:
- /library/convex/minplus_convolution.hpp
- /library/convex/minplus_convolution.hpp.html
title: convex/minplus_convolution.hpp
---
