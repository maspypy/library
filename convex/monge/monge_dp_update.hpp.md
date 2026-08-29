---
data:
  _extendedDependsOn:
  - icon: ':x:'
    path: convex/monotone_minima.hpp
    title: convex/monotone_minima.hpp
  - icon: ':x:'
    path: convex/smawk.hpp
    title: convex/smawk.hpp
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':x:'
    path: test/3_yukicoder/952.test.cpp
    title: test/3_yukicoder/952.test.cpp
  _isVerificationFailed: true
  _pathExtension: hpp
  _verificationStatusIcon: ':x:'
  attributes:
    links: []
  bundledCode: "#line 1 \"convex/monge/monge_dp_update.hpp\"\n\n#line 1 \"convex/monotone_minima.hpp\"\
    \n\n// \u5404\u884C\u306E\u6700\u9069\u5217\u3092\u6C42\u3081\u308B\n// better(i,j,k):\
    \ \u884C i \u306B\u304A\u3044\u3066\u5217 k \u304C\u5217 j \u3088\u308A\u826F\u3044\
    \u3068\u304D true\n// \u9069\u7528\u6761\u4EF6\uFF1Abetter \u306B\u3088\u3063\u3066\
    \u9078\u3070\u308C\u308B\u6700\u9069\u5217 opt[i] \u304C i \u306B\u3064\u3044\u3066\
    \u5E83\u7FA9\u5358\u8ABF\u5897\u52A0\ntemplate <typename F>\nvc<int> monotone_minima(int\
    \ H, int W, F better) {\n  if (H == 0) return {};\n  assert(H > 0 && W > 0);\n\
    \n  vc<int> idx(H + 1);\n  idx[0] = 0;\n  FOR(y, 1, W) {\n    if (better(0, idx[0],\
    \ y)) idx[0] = y;\n  }\n  idx[H] = W - 1;\n\n  int d = 1;\n  while (d < H) d <<=\
    \ 1;\n  for (int q = d >> 1; q > 0; q >>= 1) {\n    for (int h = q; h < H; h +=\
    \ q << 1) {\n      int l = h - q;\n      int r = min(h + q, H);\n      int best\
    \ = idx[l];\n      for (int y = idx[l] + 1; y <= idx[r]; ++y) {\n        if (better(h,\
    \ best, y)) best = y;\n      }\n      idx[h] = best;\n    }\n  }\n  idx.pop_back();\n\
    \  return idx;\n}\n#line 1 \"convex/smawk.hpp\"\n\n// \u5404\u884C\u306E\u6700\
    \u9069\u5217\u3092\u6C42\u3081\u308B.\n// better(i,j,k): \u884C i \u306B\u304A\
    \u3044\u3066\u5217 k \u304C\u5217 j \u3088\u308A\u826F\u3044\u3068\u304D true.\n\
    // \u9069\u7528\u6761\u4EF6\uFF1Atotally monotone matrix.\ntemplate <typename\
    \ F>\nvc<int> smawk(int H, int W, F better) {\n  if (H == 0) return {};\n  assert(W\
    \ > 0);\n\n  auto dfs = [&](auto& dfs, vc<int> X, vc<int> Y) -> vc<int> {\n  \
    \  int N = len(X);\n    if (N == 0) return {};\n\n    vc<int> YY;\n    for (auto&&\
    \ y : Y) {\n      while (len(YY)) {\n        int py = YY.back(), x = X[len(YY)\
    \ - 1];\n        if (!better(x, py, y)) break;\n        YY.pop_back();\n     \
    \ }\n      if (len(YY) < len(X)) YY.eb(y);\n    }\n\n    vc<int> XX;\n    FOR(i,\
    \ 1, len(X), 2) XX.eb(X[i]);\n\n    vc<int> II = dfs(dfs, XX, YY);\n    vc<int>\
    \ I(N);\n    FOR(i, len(II)) I[i + i + 1] = II[i];\n\n    int p = 0;\n    FOR(i,\
    \ 0, N, 2) {\n      int lim = (i + 1 == N ? Y.back() : I[i + 1]);\n      int best\
    \ = Y[p];\n      while (Y[p] < lim) {\n        ++p;\n        if (better(X[i],\
    \ best, Y[p])) best = Y[p];\n      }\n      I[i] = best;\n    }\n    return I;\n\
    \  };\n\n  vc<int> X(H), Y(W);\n  iota(all(X), 0), iota(all(Y), 0);\n  return\
    \ dfs(dfs, X, Y);\n}\n#line 4 \"convex/monge/monge_dp_update.hpp\"\n\ntemplate\
    \ <typename T, typename F>\nvc<T> monge_dp_update(int N, vc<T>& dp, F f) {\n \
    \ assert(len(dp) == N + 1);\n\n  auto better = [&](int i, int j, int k) -> bool\
    \ {\n    if (i <= k) return false;\n    if (i <= j) return true;\n    return dp[j]\
    \ + f(j, i) > dp[k] + f(k, i);\n  };\n\n  vc<int> I = monotone_minima(N + 1, N\
    \ + 1, better);\n  // vc<int> I = smawk(N + 1, N + 1, better);\n\n  vc<T> newdp(N\
    \ + 1, infty<T>);\n  FOR(j, N + 1) {\n    int i = I[j];\n    if (i < j) newdp[j]\
    \ = dp[i] + f(i, j);\n  }\n  return newdp;\n}\n"
  code: "\n#include \"convex/monotone_minima.hpp\"\n#include \"convex/smawk.hpp\"\n\
    \ntemplate <typename T, typename F>\nvc<T> monge_dp_update(int N, vc<T>& dp, F\
    \ f) {\n  assert(len(dp) == N + 1);\n\n  auto better = [&](int i, int j, int k)\
    \ -> bool {\n    if (i <= k) return false;\n    if (i <= j) return true;\n   \
    \ return dp[j] + f(j, i) > dp[k] + f(k, i);\n  };\n\n  vc<int> I = monotone_minima(N\
    \ + 1, N + 1, better);\n  // vc<int> I = smawk(N + 1, N + 1, better);\n\n  vc<T>\
    \ newdp(N + 1, infty<T>);\n  FOR(j, N + 1) {\n    int i = I[j];\n    if (i < j)\
    \ newdp[j] = dp[i] + f(i, j);\n  }\n  return newdp;\n}"
  dependsOn:
  - convex/monotone_minima.hpp
  - convex/smawk.hpp
  isVerificationFile: false
  path: convex/monge/monge_dp_update.hpp
  requiredBy: []
  timestamp: '2026-08-16 04:03:00+09:00'
  verificationStatus: LIBRARY_ALL_WA
  verifiedWith:
  - test/3_yukicoder/952.test.cpp
documentation_of: convex/monge/monge_dp_update.hpp
layout: document
redirect_from:
- /library/convex/monge/monge_dp_update.hpp
- /library/convex/monge/monge_dp_update.hpp.html
title: convex/monge/monge_dp_update.hpp
---
