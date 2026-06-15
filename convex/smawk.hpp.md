---
data:
  _extendedDependsOn: []
  _extendedRequiredBy:
  - icon: ':warning:'
    path: convex/monge/monge.hpp
    title: convex/monge/monge.hpp
  - icon: ':x:'
    path: convex/monge/monge_dp_update.hpp
    title: convex/monge/monge_dp_update.hpp
  _extendedVerifiedWith:
  - icon: ':x:'
    path: test/1_mytest/alien.test.cpp
    title: test/1_mytest/alien.test.cpp
  - icon: ':x:'
    path: test/1_mytest/smawk.test.cpp
    title: test/1_mytest/smawk.test.cpp
  _isVerificationFailed: true
  _pathExtension: hpp
  _verificationStatusIcon: ':x:'
  attributes:
    links: []
  bundledCode: "#line 2 \"convex/smawk.hpp\"\n\n// \u5404\u884C\u306E\u6700\u9069\u5217\
    \u3092\u6C42\u3081\u308B.\n// better(i,j,k): \u884C i \u306B\u304A\u3044\u3066\
    \u5217 k \u304C\u5217 j \u3088\u308A\u826F\u3044\u3068\u304D true.\n// \u9069\u7528\
    \u6761\u4EF6\uFF1Atotally monotone matrix.\ntemplate <typename F>\nvc<int> smawk(int\
    \ H, int W, F better) {\n  if (H == 0) return {};\n  assert(W > 0);\n\n  auto\
    \ dfs = [&](auto& dfs, vc<int> X, vc<int> Y) -> vc<int> {\n    int N = len(X);\n\
    \    if (N == 0) return {};\n\n    vc<int> YY;\n    for (auto&& y : Y) {\n   \
    \   while (len(YY)) {\n        int py = YY.back(), x = X[len(YY) - 1];\n     \
    \   if (!better(x, py, y)) break;\n        YY.pop_back();\n      }\n      if (len(YY)\
    \ < len(X)) YY.eb(y);\n    }\n\n    vc<int> XX;\n    FOR(i, 1, len(X), 2) XX.eb(X[i]);\n\
    \n    vc<int> II = dfs(dfs, XX, YY);\n    vc<int> I(N);\n    FOR(i, len(II)) I[i\
    \ + i + 1] = II[i];\n\n    int p = 0;\n    FOR(i, 0, N, 2) {\n      int lim =\
    \ (i + 1 == N ? Y.back() : I[i + 1]);\n      int best = Y[p];\n      while (Y[p]\
    \ < lim) {\n        ++p;\n        if (better(X[i], best, Y[p])) best = Y[p];\n\
    \      }\n      I[i] = best;\n    }\n    return I;\n  };\n\n  vc<int> X(H), Y(W);\n\
    \  iota(all(X), 0), iota(all(Y), 0);\n  return dfs(dfs, X, Y);\n}\n"
  code: "#pragma once\n\n// \u5404\u884C\u306E\u6700\u9069\u5217\u3092\u6C42\u3081\
    \u308B.\n// better(i,j,k): \u884C i \u306B\u304A\u3044\u3066\u5217 k \u304C\u5217\
    \ j \u3088\u308A\u826F\u3044\u3068\u304D true.\n// \u9069\u7528\u6761\u4EF6\uFF1A\
    totally monotone matrix.\ntemplate <typename F>\nvc<int> smawk(int H, int W, F\
    \ better) {\n  if (H == 0) return {};\n  assert(W > 0);\n\n  auto dfs = [&](auto&\
    \ dfs, vc<int> X, vc<int> Y) -> vc<int> {\n    int N = len(X);\n    if (N == 0)\
    \ return {};\n\n    vc<int> YY;\n    for (auto&& y : Y) {\n      while (len(YY))\
    \ {\n        int py = YY.back(), x = X[len(YY) - 1];\n        if (!better(x, py,\
    \ y)) break;\n        YY.pop_back();\n      }\n      if (len(YY) < len(X)) YY.eb(y);\n\
    \    }\n\n    vc<int> XX;\n    FOR(i, 1, len(X), 2) XX.eb(X[i]);\n\n    vc<int>\
    \ II = dfs(dfs, XX, YY);\n    vc<int> I(N);\n    FOR(i, len(II)) I[i + i + 1]\
    \ = II[i];\n\n    int p = 0;\n    FOR(i, 0, N, 2) {\n      int lim = (i + 1 ==\
    \ N ? Y.back() : I[i + 1]);\n      int best = Y[p];\n      while (Y[p] < lim)\
    \ {\n        ++p;\n        if (better(X[i], best, Y[p])) best = Y[p];\n      }\n\
    \      I[i] = best;\n    }\n    return I;\n  };\n\n  vc<int> X(H), Y(W);\n  iota(all(X),\
    \ 0), iota(all(Y), 0);\n  return dfs(dfs, X, Y);\n}"
  dependsOn: []
  isVerificationFile: false
  path: convex/smawk.hpp
  requiredBy:
  - convex/monge/monge.hpp
  - convex/monge/monge_dp_update.hpp
  timestamp: '2026-06-15 22:08:56+09:00'
  verificationStatus: LIBRARY_ALL_WA
  verifiedWith:
  - test/1_mytest/smawk.test.cpp
  - test/1_mytest/alien.test.cpp
documentation_of: convex/smawk.hpp
layout: document
redirect_from:
- /library/convex/smawk.hpp
- /library/convex/smawk.hpp.html
title: convex/smawk.hpp
---
