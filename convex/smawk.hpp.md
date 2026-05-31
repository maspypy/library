---
data:
  _extendedDependsOn: []
  _extendedRequiredBy:
  - icon: ':warning:'
    path: convex/monge/monge.hpp
    title: convex/monge/monge.hpp
  - icon: ':warning:'
    path: convex/monge/monge_dp_update.hpp
    title: convex/monge/monge_dp_update.hpp
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/1_mytest/smawk.test.cpp
    title: test/1_mytest/smawk.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links:
    - https://codeforces.com/contest/1423/problem/M
  bundledCode: "#line 2 \"convex/smawk.hpp\"\n\n// \u5404\u884C\u306E\u6700\u9069\u5217\
    \u3092\u6C42\u3081\u308B.\n// better(i,j,k): \u884C i \u306B\u304A\u3044\u3066\
    \u5217 k \u304C\u5217 j \u3088\u308A\u826F\u3044\u3068\u304D true.\n// \u9069\u7528\
    \u6761\u4EF6\uFF1Atotally monotone matrix.\n// \u6B8B\u5FF5\u306A\u304C\u3089\
    \ monotone minima \u3088\u308A\u9AD8\u901F\u306A\u5834\u5408\u304C\u5B58\u5728\
    \u3057\u306A\u3044\u8AAC\u304C\u3042\u308B\n// https://codeforces.com/contest/1423/problem/M\n\
    template <typename F>\nvc<int> smawk(int H, int W, F better) {\n  if (H == 0)\
    \ return {};\n  assert(W > 0);\n\n  auto dfs = [&](auto& dfs, vc<int> X, vc<int>\
    \ Y) -> vc<int> {\n    int N = len(X);\n    if (N == 0) return {};\n\n    vc<int>\
    \ YY;\n    for (auto&& y : Y) {\n      while (len(YY)) {\n        int py = YY.back(),\
    \ x = X[len(YY) - 1];\n        if (!better(x, py, y)) break;\n        YY.pop_back();\n\
    \      }\n      if (len(YY) < len(X)) YY.eb(y);\n    }\n\n    vc<int> XX;\n  \
    \  FOR(i, 1, len(X), 2) XX.eb(X[i]);\n\n    vc<int> II = dfs(dfs, XX, YY);\n \
    \   vc<int> I(N);\n    FOR(i, len(II)) I[i + i + 1] = II[i];\n\n    int p = 0;\n\
    \    FOR(i, 0, N, 2) {\n      int lim = (i + 1 == N ? Y.back() : I[i + 1]);\n\
    \      int best = Y[p];\n      while (Y[p] < lim) {\n        ++p;\n        if\
    \ (better(X[i], best, Y[p])) best = Y[p];\n      }\n      I[i] = best;\n    }\n\
    \    return I;\n  };\n\n  vc<int> X(H), Y(W);\n  iota(all(X), 0), iota(all(Y),\
    \ 0);\n  return dfs(dfs, X, Y);\n}\n"
  code: "#pragma once\n\n// \u5404\u884C\u306E\u6700\u9069\u5217\u3092\u6C42\u3081\
    \u308B.\n// better(i,j,k): \u884C i \u306B\u304A\u3044\u3066\u5217 k \u304C\u5217\
    \ j \u3088\u308A\u826F\u3044\u3068\u304D true.\n// \u9069\u7528\u6761\u4EF6\uFF1A\
    totally monotone matrix.\n// \u6B8B\u5FF5\u306A\u304C\u3089 monotone minima \u3088\
    \u308A\u9AD8\u901F\u306A\u5834\u5408\u304C\u5B58\u5728\u3057\u306A\u3044\u8AAC\
    \u304C\u3042\u308B\n// https://codeforces.com/contest/1423/problem/M\ntemplate\
    \ <typename F>\nvc<int> smawk(int H, int W, F better) {\n  if (H == 0) return\
    \ {};\n  assert(W > 0);\n\n  auto dfs = [&](auto& dfs, vc<int> X, vc<int> Y) ->\
    \ vc<int> {\n    int N = len(X);\n    if (N == 0) return {};\n\n    vc<int> YY;\n\
    \    for (auto&& y : Y) {\n      while (len(YY)) {\n        int py = YY.back(),\
    \ x = X[len(YY) - 1];\n        if (!better(x, py, y)) break;\n        YY.pop_back();\n\
    \      }\n      if (len(YY) < len(X)) YY.eb(y);\n    }\n\n    vc<int> XX;\n  \
    \  FOR(i, 1, len(X), 2) XX.eb(X[i]);\n\n    vc<int> II = dfs(dfs, XX, YY);\n \
    \   vc<int> I(N);\n    FOR(i, len(II)) I[i + i + 1] = II[i];\n\n    int p = 0;\n\
    \    FOR(i, 0, N, 2) {\n      int lim = (i + 1 == N ? Y.back() : I[i + 1]);\n\
    \      int best = Y[p];\n      while (Y[p] < lim) {\n        ++p;\n        if\
    \ (better(X[i], best, Y[p])) best = Y[p];\n      }\n      I[i] = best;\n    }\n\
    \    return I;\n  };\n\n  vc<int> X(H), Y(W);\n  iota(all(X), 0), iota(all(Y),\
    \ 0);\n  return dfs(dfs, X, Y);\n}"
  dependsOn: []
  isVerificationFile: false
  path: convex/smawk.hpp
  requiredBy:
  - convex/monge/monge_dp_update.hpp
  - convex/monge/monge.hpp
  timestamp: '2026-05-31 18:13:57+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/1_mytest/smawk.test.cpp
documentation_of: convex/smawk.hpp
layout: document
redirect_from:
- /library/convex/smawk.hpp
- /library/convex/smawk.hpp.html
title: convex/smawk.hpp
---
