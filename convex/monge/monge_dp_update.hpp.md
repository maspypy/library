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
  bundledCode: "#line 2 \"convex/smawk.hpp\"\n\n// select(i,j,k) \u306F (i,j) -> (i,k)\
    \ \u3092\u884C\u3046\u304B\u3069\u3046\u304B\n// \u6B8B\u5FF5\u306A\u304C\u3089\
    \ monotone minima \u3088\u308A\u9AD8\u901F\u306A\u5834\u5408\u304C\u5B58\u5728\
    \u3057\u306A\u3044\u8AAC\u304C\u3042\u308B\n// https://codeforces.com/contest/1423/problem/M\n\
    template <typename F>\nvc<int> smawk(int H, int W, F select) {\n  auto dfs = [&](auto&\
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
  timestamp: '2026-05-31 16:57:43+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: convex/monge/monge_dp_update.hpp
layout: document
redirect_from:
- /library/convex/monge/monge_dp_update.hpp
- /library/convex/monge/monge_dp_update.hpp.html
title: convex/monge/monge_dp_update.hpp
---
