---
data:
  _extendedDependsOn: []
  _extendedRequiredBy:
  - icon: ':warning:'
    path: convex/maxplus_convolution_concave.hpp
    title: convex/maxplus_convolution_concave.hpp
  - icon: ':warning:'
    path: convex/minplus_convolution_convex.hpp
    title: convex/minplus_convolution_convex.hpp
  _extendedVerifiedWith:
  - icon: ':x:'
    path: test/mytest/smawk.test.cpp
    title: test/mytest/smawk.test.cpp
  _isVerificationFailed: true
  _pathExtension: hpp
  _verificationStatusIcon: ':x:'
  attributes:
    links: []
  bundledCode: "#line 1 \"convex/smawk.hpp\"\n// select(i,j,k) \u306F (i,j) \u3068\
    \ (i,k) \u306E\u3046\u3061 k \u3092\u9078\u3076\u306A\u3089 true\n// tie break\
    \ \u306E\u306A\u3044\u72B6\u6CC1\u3067 argmin \u306A\u3089\u3001(i,j) > (i,k)\n\
    template <typename F>\nvc<int> SMAWK(int H, int W, F select) {\n  auto dfs = [&](auto&\
    \ dfs, vc<int> X, vc<int> Y) -> vc<int> {\n    int N = len(X);\n    if (N == 0)\
    \ return {};\n    vc<int> YY;\n    for (auto&& y: Y) {\n      while (len(YY))\
    \ {\n        int py = YY.back(), x = X[len(YY) - 1];\n        if (!select(x, py,\
    \ y)) break;\n        YY.pop_back();\n      }\n      if (len(YY) < len(X)) YY.eb(y);\n\
    \    }\n    vc<int> XX;\n    FOR(i, 1, len(X), 2) XX.eb(X[i]);\n    vc<int> II\
    \ = dfs(dfs, XX, YY);\n    vc<int> I(N);\n    FOR(i, len(II)) I[i + i + 1] = II[i];\n\
    \    int p = 0;\n    FOR(i, 0, N, 2) {\n      int LIM = (i + 1 == N ? Y.back()\
    \ : I[i + 1]);\n      int best = Y[p];\n      while (Y[p] < LIM) {\n        ++p;\n\
    \        if (select(X[i], best, Y[p])) best = Y[p];\n      }\n      I[i] = best;\n\
    \    }\n    return I;\n  };\n  vc<int> X(H), Y(W);\n  iota(all(X), 0), iota(all(Y),\
    \ 0);\n  return dfs(dfs, X, Y);\n}\n"
  code: "// select(i,j,k) \u306F (i,j) \u3068 (i,k) \u306E\u3046\u3061 k \u3092\u9078\
    \u3076\u306A\u3089 true\n// tie break \u306E\u306A\u3044\u72B6\u6CC1\u3067 argmin\
    \ \u306A\u3089\u3001(i,j) > (i,k)\ntemplate <typename F>\nvc<int> SMAWK(int H,\
    \ int W, F select) {\n  auto dfs = [&](auto& dfs, vc<int> X, vc<int> Y) -> vc<int>\
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
    \ X, Y);\n}"
  dependsOn: []
  isVerificationFile: false
  path: convex/smawk.hpp
  requiredBy:
  - convex/minplus_convolution_convex.hpp
  - convex/maxplus_convolution_concave.hpp
  timestamp: '2023-01-12 22:34:48+09:00'
  verificationStatus: LIBRARY_ALL_WA
  verifiedWith:
  - test/mytest/smawk.test.cpp
documentation_of: convex/smawk.hpp
layout: document
redirect_from:
- /library/convex/smawk.hpp
- /library/convex/smawk.hpp.html
title: convex/smawk.hpp
---
