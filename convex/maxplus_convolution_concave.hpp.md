---
data:
  _extendedDependsOn:
  - icon: ':question:'
    path: convex/smawk.hpp
    title: convex/smawk.hpp
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':x:'
    path: test/mytest/maxplus_concave.test.cpp
    title: test/mytest/maxplus_concave.test.cpp
  _isVerificationFailed: true
  _pathExtension: hpp
  _verificationStatusIcon: ':x:'
  attributes:
    links: []
  bundledCode: "#line 2 \"convex/smawk.hpp\"\n\n// select(i,j,k) \u306F (i,j) -> (i,k)\
    \ \u3092\u884C\u3046\u304B\u3069\u3046\u304B\n// \u6B8B\u5FF5\u306A\u304C\u3089\
    \ monotone minima \u3088\u308A\u9AD8\u901F\u306A\u5834\u5408\u304C\u5B58\u5728\
    \u3057\u306A\u3044\u8AAC\u304C\u3042\u308B\ntemplate <typename F>\nvc<int> smawk(int\
    \ H, int W, F select) {\n  auto dfs = [&](auto& dfs, vc<int> X, vc<int> Y) ->\
    \ vc<int> {\n    int N = len(X);\n    if (N == 0) return {};\n    vc<int> YY;\n\
    \    for (auto&& y: Y) {\n      while (len(YY)) {\n        int py = YY.back(),\
    \ x = X[len(YY) - 1];\n        if (!select(x, py, y)) break;\n        YY.pop_back();\n\
    \      }\n      if (len(YY) < len(X)) YY.eb(y);\n    }\n    vc<int> XX;\n    FOR(i,\
    \ 1, len(X), 2) XX.eb(X[i]);\n    vc<int> II = dfs(dfs, XX, YY);\n    vc<int>\
    \ I(N);\n    FOR(i, len(II)) I[i + i + 1] = II[i];\n    int p = 0;\n    FOR(i,\
    \ 0, N, 2) {\n      int LIM = (i + 1 == N ? Y.back() : I[i + 1]);\n      int best\
    \ = Y[p];\n      while (Y[p] < LIM) {\n        ++p;\n        if (select(X[i],\
    \ best, Y[p])) best = Y[p];\n      }\n      I[i] = best;\n    }\n    return I;\n\
    \  };\n  vc<int> X(H), Y(W);\n  iota(all(X), 0), iota(all(Y), 0);\n  return dfs(dfs,\
    \ X, Y);\n}\n#line 2 \"convex/maxplus_convolution_concave.hpp\"\n\ntemplate <typename\
    \ T, bool concaveA, bool concaveB>\nvc<T> maxplus_convolution_concave(vc<T> A,\
    \ vc<T> B) {\n  static_assert(concaveA || concaveB);\n  assert(infty<int> < infty<int>\
    \ + infty<int>);\n  if (!concaveB) swap(A, B);\n  int NA = len(A), NB = len(B);\n\
    \  int N = NA + NB - 1;\n  int L = 0, R = NB;\n  while (L < R && B[L] == -infty<int>)\
    \ ++L;\n  if (L == R) return vc<T>(N, -infty<int>);\n  while (B[R - 1] == -infty<int>)\
    \ --R;\n  B = {B.begin() + L, B.begin() + R};\n  int nB = R - L;\n  int n = NA\
    \ + nB - 1;\n\n  auto select = [&](int i, int j, int k) -> int {\n    if (i <\
    \ k) return j;\n    if (i - j >= nB) return k;\n    return (A[j] + B[i - j] <\
    \ A[k] + B[i - k] ? k : j);\n  };\n\n  vc<int> J = SMAWK(n, NA, select);\n  vc<T>\
    \ C(N, -infty<int>);\n  FOR(i, n) C[L + i] = A[J[i]] + (A[J[i]] == -infty<int>\
    \ ? 0 : B[i - J[i]]);\n  return C;\n}\n"
  code: "#include \"convex/smawk.hpp\"\n\ntemplate <typename T, bool concaveA, bool\
    \ concaveB>\nvc<T> maxplus_convolution_concave(vc<T> A, vc<T> B) {\n  static_assert(concaveA\
    \ || concaveB);\n  assert(infty<int> < infty<int> + infty<int>);\n  if (!concaveB)\
    \ swap(A, B);\n  int NA = len(A), NB = len(B);\n  int N = NA + NB - 1;\n  int\
    \ L = 0, R = NB;\n  while (L < R && B[L] == -infty<int>) ++L;\n  if (L == R) return\
    \ vc<T>(N, -infty<int>);\n  while (B[R - 1] == -infty<int>) --R;\n  B = {B.begin()\
    \ + L, B.begin() + R};\n  int nB = R - L;\n  int n = NA + nB - 1;\n\n  auto select\
    \ = [&](int i, int j, int k) -> int {\n    if (i < k) return j;\n    if (i - j\
    \ >= nB) return k;\n    return (A[j] + B[i - j] < A[k] + B[i - k] ? k : j);\n\
    \  };\n\n  vc<int> J = SMAWK(n, NA, select);\n  vc<T> C(N, -infty<int>);\n  FOR(i,\
    \ n) C[L + i] = A[J[i]] + (A[J[i]] == -infty<int> ? 0 : B[i - J[i]]);\n  return\
    \ C;\n}\n"
  dependsOn:
  - convex/smawk.hpp
  isVerificationFile: false
  path: convex/maxplus_convolution_concave.hpp
  requiredBy: []
  timestamp: '2023-08-10 00:32:23+09:00'
  verificationStatus: LIBRARY_ALL_WA
  verifiedWith:
  - test/mytest/maxplus_concave.test.cpp
documentation_of: convex/maxplus_convolution_concave.hpp
layout: document
redirect_from:
- /library/convex/maxplus_convolution_concave.hpp
- /library/convex/maxplus_convolution_concave.hpp.html
title: convex/maxplus_convolution_concave.hpp
---
