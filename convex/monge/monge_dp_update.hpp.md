---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: convex/smawk.hpp
    title: convex/smawk.hpp
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':warning:'
  attributes:
    links: []
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
    \ 0);\n  return dfs(dfs, X, Y);\n}\n#line 3 \"convex/monge/monge_dp_update.hpp\"\
    \n\n// newdp[j] = min_{0 <= i < j} dp[i] + f(i, j)\ntemplate <typename T, typename\
    \ F>\nvc<T> monge_dp_update(int N, vc<T>& dp, F f) {\n  assert(len(dp) == N +\
    \ 1);\n\n  auto select = [&](int i, int j, int k) -> int {\n    // row i corresponds\
    \ to destination i.\n    // valid source columns are k < i.\n    if (i <= k) return\
    \ j;\n    return (dp[j] + f(j, i) > dp[k] + f(k, i) ? k : j);\n  };\n\n  vc<int>\
    \ I = smawk(N + 1, N + 1, select);\n\n  vc<T> newdp(N + 1, infty<T>);\n  FOR(j,\
    \ N + 1) {\n    int i = I[j];\n    if (i < j) chmin(newdp[j], dp[i] + f(i, j));\n\
    \  }\n  return newdp;\n}\n"
  code: "#pragma once\n#include \"convex/smawk.hpp\"\n\n// newdp[j] = min_{0 <= i\
    \ < j} dp[i] + f(i, j)\ntemplate <typename T, typename F>\nvc<T> monge_dp_update(int\
    \ N, vc<T>& dp, F f) {\n  assert(len(dp) == N + 1);\n\n  auto select = [&](int\
    \ i, int j, int k) -> int {\n    // row i corresponds to destination i.\n    //\
    \ valid source columns are k < i.\n    if (i <= k) return j;\n    return (dp[j]\
    \ + f(j, i) > dp[k] + f(k, i) ? k : j);\n  };\n\n  vc<int> I = smawk(N + 1, N\
    \ + 1, select);\n\n  vc<T> newdp(N + 1, infty<T>);\n  FOR(j, N + 1) {\n    int\
    \ i = I[j];\n    if (i < j) chmin(newdp[j], dp[i] + f(i, j));\n  }\n  return newdp;\n\
    }"
  dependsOn:
  - convex/smawk.hpp
  isVerificationFile: false
  path: convex/monge/monge_dp_update.hpp
  requiredBy: []
  timestamp: '2026-05-31 18:13:57+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: convex/monge/monge_dp_update.hpp
layout: document
redirect_from:
- /library/convex/monge/monge_dp_update.hpp
- /library/convex/monge/monge_dp_update.hpp.html
title: convex/monge/monge_dp_update.hpp
---
