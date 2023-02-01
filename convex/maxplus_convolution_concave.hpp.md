---
data:
  _extendedDependsOn:
  - icon: ':question:'
    path: convex/smawk.hpp
    title: convex/smawk.hpp
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
  bundledCode: "#line 1 \"convex/smawk.hpp\"\n// select(i,j,k) \u306F (i,j) \u3068\
    \ (i,k) \u306E\u3046\u3061\u9078\u3076\u65B9\uFF08j or k\uFF09\ntemplate <typename\
    \ F>\nvc<int> SMAWK(int H, int W, F select) {\n  auto dfs = [&](auto& dfs, vc<int>\
    \ X, vc<int> Y) -> vc<int> {\n    int N = len(X);\n    if (N == 0) return {};\n\
    \    vc<int> YY;\n    for (auto&& y: Y) {\n      while (len(YY)) {\n        int\
    \ py = YY.back(), x = X[len(YY) - 1];\n        if (select(x, py, y) == py) break;\n\
    \        YY.pop_back();\n      }\n      if (len(YY) < len(X)) YY.eb(y);\n    }\n\
    \    vc<int> XX;\n    FOR(i, 1, len(X), 2) XX.eb(X[i]);\n    vc<int> II = dfs(dfs,\
    \ XX, YY);\n    vc<int> I(N);\n    FOR(i, len(II)) I[i + i + 1] = II[i];\n   \
    \ int p = 0;\n    FOR(i, 0, N, 2) {\n      int LIM = (i + 1 == N ? Y.back() :\
    \ I[i + 1]);\n      int best = Y[p];\n      while (Y[p] < LIM) {\n        ++p;\n\
    \        best = select(X[i], best, Y[p]);\n      }\n      I[i] = best;\n    }\n\
    \    return I;\n  };\n  vc<int> X(H), Y(W);\n  iota(all(X), 0), iota(all(Y), 0);\n\
    \  return dfs(dfs, X, Y);\n}\n#line 2 \"convex/maxplus_convolution_concave.hpp\"\
    \n\ntemplate <typename T, bool concaveA, bool concaveB>\nvc<T> maxplus_convolution_concave(vc<T>\
    \ A, vc<T> B) {\n  static_assert(concaveA || concaveB);\n  assert(infty<int> <\
    \ infty<int> + infty<int>);\n  if (!concaveB) swap(A, B);\n  int NA = len(A),\
    \ NB = len(B);\n  int N = NA + NB - 1;\n  int L = 0, R = NB;\n  while (L < R &&\
    \ B[L] == -infty<int>) ++L;\n  if (L == R) return vc<T>(N, -infty<int>);\n  while\
    \ (B[R - 1] == -infty<int>) --R;\n  B = {B.begin() + L, B.begin() + R};\n  int\
    \ nB = R - L;\n  int n = NA + nB - 1;\n\n  auto select = [&](int i, int j, int\
    \ k) -> int {\n    if (i < k) return j;\n    if (i - j >= nB) return k;\n    return\
    \ (A[j] + B[i - j] < A[k] + B[i - k] ? k : j);\n  };\n\n  vc<int> J = SMAWK(n,\
    \ NA, select);\n  vc<T> C(N, -infty<int>);\n  FOR(i, n) C[L + i] = A[J[i]] + (A[J[i]]\
    \ == -infty<int> ? 0 : B[i - J[i]]);\n  return C;\n}\n"
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
  timestamp: '2023-02-02 01:09:35+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/mytest/maxplus_concave.test.cpp
documentation_of: convex/maxplus_convolution_concave.hpp
layout: document
redirect_from:
- /library/convex/maxplus_convolution_concave.hpp
- /library/convex/maxplus_convolution_concave.hpp.html
title: convex/maxplus_convolution_concave.hpp
---
