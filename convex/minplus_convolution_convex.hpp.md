---
data:
  _extendedDependsOn:
  - icon: ':x:'
    path: convex/smawk.hpp
    title: convex/smawk.hpp
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':x:'
    path: test/mytest/minplus_convex.test.cpp
    title: test/mytest/minplus_convex.test.cpp
  _isVerificationFailed: true
  _pathExtension: hpp
  _verificationStatusIcon: ':x:'
  attributes:
    links: []
  bundledCode: "#line 2 \"convex/smawk.hpp\"\n// select(i,j,k) \u306F (i,j) \u3068\
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
    \  return dfs(dfs, X, Y);\n}\n#line 2 \"convex/minplus_convolution_convex.hpp\"\
    \n\ntemplate <typename T, bool convA, bool convB>\nvc<T> minplus_convolution_convex(vc<T>\
    \ A, vc<T> B) {\n  static_assert(convA || convB);\n  if (!convB) swap(A, B);\n\
    \  int NA = len(A), NB = len(B);\n  int N = NA + NB - 1;\n  int L = 0, R = NB;\n\
    \  while (L < R && B[L] == infty<T>) ++L;\n  if (L == R) return vc<T>(N, infty<T>);\n\
    \  while (B[R - 1] == infty<T>) --R;\n  B = {B.begin() + L, B.begin() + R};\n\
    \  int nB = R - L;\n  int n = NA + nB - 1;\n\n  auto select = [&](int i, int j,\
    \ int k) -> int {\n    if (i < k) return j;\n    if (i - j >= nB) return k;\n\
    \    return (A[j] + B[i - j] > A[k] + B[i - k] ? k : j);\n  };\n\n  vc<int> J\
    \ = SMAWK(n, NA, select);\n  vc<T> C(N, infty<T>);\n  FOR(i, n) C[L + i] = (A[J[i]]\
    \ == infty<T> ? infty<T> : A[J[i]] + B[i - J[i]]);\n  return C;\n}\n"
  code: "#include \"convex/smawk.hpp\"\n\ntemplate <typename T, bool convA, bool convB>\n\
    vc<T> minplus_convolution_convex(vc<T> A, vc<T> B) {\n  static_assert(convA ||\
    \ convB);\n  if (!convB) swap(A, B);\n  int NA = len(A), NB = len(B);\n  int N\
    \ = NA + NB - 1;\n  int L = 0, R = NB;\n  while (L < R && B[L] == infty<T>) ++L;\n\
    \  if (L == R) return vc<T>(N, infty<T>);\n  while (B[R - 1] == infty<T>) --R;\n\
    \  B = {B.begin() + L, B.begin() + R};\n  int nB = R - L;\n  int n = NA + nB -\
    \ 1;\n\n  auto select = [&](int i, int j, int k) -> int {\n    if (i < k) return\
    \ j;\n    if (i - j >= nB) return k;\n    return (A[j] + B[i - j] > A[k] + B[i\
    \ - k] ? k : j);\n  };\n\n  vc<int> J = SMAWK(n, NA, select);\n  vc<T> C(N, infty<T>);\n\
    \  FOR(i, n) C[L + i] = (A[J[i]] == infty<T> ? infty<T> : A[J[i]] + B[i - J[i]]);\n\
    \  return C;\n}\n"
  dependsOn:
  - convex/smawk.hpp
  isVerificationFile: false
  path: convex/minplus_convolution_convex.hpp
  requiredBy: []
  timestamp: '2023-02-12 02:05:24+09:00'
  verificationStatus: LIBRARY_ALL_WA
  verifiedWith:
  - test/mytest/minplus_convex.test.cpp
documentation_of: convex/minplus_convolution_convex.hpp
layout: document
redirect_from:
- /library/convex/minplus_convolution_convex.hpp
- /library/convex/minplus_convolution_convex.hpp.html
title: convex/minplus_convolution_convex.hpp
---
