---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/aoj/DPL_1_B.test.cpp
    title: test/aoj/DPL_1_B.test.cpp
  - icon: ':x:'
    path: test/aoj/DPL_1_F.test.cpp
    title: test/aoj/DPL_1_F.test.cpp
  - icon: ':x:'
    path: test/aoj/DPL_1_H.test.cpp
    title: test/aoj/DPL_1_H.test.cpp
  _isVerificationFailed: true
  _pathExtension: hpp
  _verificationStatusIcon: ':question:'
  attributes:
    links: []
  bundledCode: "#line 1 \"knapsack/knapsack01.hpp\"\n/*\nknapsack01 \u306E\u5168\u5217\
    \u6319\n\u30FBO(2^n) \u3067\u3001(wt, val) \u3092\u5168\u5217\u6319 + wt \u3067\
    \u30BD\u30FC\u30C8\n\u30FBremove extra = true \u2192 val \u304C\u5897\u52A0\u306B\
    \u306A\u308B\u3068\u3053\u308D\u3060\u3051\u6B8B\u3059\n*/\ntemplate <typename\
    \ WT, typename VAL>\nvc<pair<WT, VAL>> knapsack01_gen_all(vc<WT> weight, vc<VAL>\
    \ val,\n                                     bool remove_extra) {\n  int n = len(weight);\n\
    \  using P = pair<WT, VAL>;\n  vc<P> dp;\n  dp.eb(0, 0);\n  FOR(i, n) {\n    vc<P>\
    \ tmp(len(dp));\n    FOR(j, len(dp)) tmp[j] = {dp[j].fi + weight[i], dp[j].se\
    \ + val[i]};\n    vc<P> res;\n    merge(all(dp), all(tmp), back_inserter(res));\n\
    \    swap(dp, res);\n  }\n  if (!remove_extra) return dp;\n  vc<P> res;\n  res.reserve(len(dp));\n\
    \  for (auto&& [w, v]: dp) {\n    while (len(res) && res.back().fi == w) res.pop_back();\n\
    \    if (len(res) && res.back().se >= v) continue;\n    res.eb(w, v);\n  }\n \
    \ return res;\n}\n\ntemplate <typename WT, typename VAL>\nVAL knapsack01(vc<WT>\
    \ weight, vc<VAL> val, WT LIM) {\n  chmin(LIM, SUM<WT>(weight));\n  int n = len(weight);\n\
    \  assert(len(val) == n);\n\n  // \u534A\u5206\u5168\u5217\u6319 + \u5C3A\u53D6\
    \u308A\u6CD5\n  // O(2^{N/2})\n  auto sol_1 = [&]() -> VAL {\n    vc<WT> wt_l\
    \ = {weight.begin(), weight.begin() + n / 2};\n    vc<WT> wt_r = {weight.begin()\
    \ + n / 2, weight.end()};\n    vc<VAL> val_l = {val.begin(), val.begin() + n /\
    \ 2};\n    vc<VAL> val_r = {val.begin() + n / 2, val.end()};\n    auto dp1 = knapsack01_gen_all(wt_l,\
    \ val_l, true);\n    auto dp2 = knapsack01_gen_all(wt_r, val_r, true);\n    int\
    \ q = len(dp2);\n    VAL ANS = 0;\n    FOR(p, len(dp1)) {\n      while (q && (dp1[p].fi\
    \ + dp2[q - 1].fi > LIM)) --q;\n      if (q == 0) break;\n      chmax(ANS, dp1[p].se\
    \ + dp2[q - 1].se);\n    }\n    return ANS;\n  };\n\n  // wt \u3054\u3068\u306E\
    \ dp\n  // O(N LIM)\n  auto sol_2 = [&]() -> VAL {\n    vc<VAL> dp(LIM + 1);\n\
    \    ll total = 0;\n    FOR(k, n) {\n      ll mx = min<ll>(LIM - weight[k], total);\n\
    \      FOR_R(i, mx + 1) chmax(dp[i + weight[k]], dp[i] + val[k]);\n      total\
    \ += weight[k];\n    };\n    return MAX(dp);\n  };\n\n  // val \u3054\u3068\u306E\
    \ dp\n  // O(N sum val)\n  auto sol_3 = [&]() -> VAL {\n    // val -> min wt\n\
    \    vc<WT> dp(SUM<VAL>(val) + 1, LIM + 1);\n    dp[0] = 0;\n    ll total = 0;\n\
    \    FOR(k, n) {\n      FOR_R(i, total + 1) { chmin(dp[i + val[k]], dp[i] + weight[k]);\
    \ }\n      total += val[k];\n    }\n    VAL ANS = 0;\n    FOR(i, total + 1) if\
    \ (dp[i] <= LIM) ANS = i;\n    return ANS;\n  };\n\n  double t1 = log(2) * n *\
    \ 0.5;\n  double t2 = log((n + 1) * (LIM + 1));\n  double t3 = log((n + 1) * (SUM<WT>(val)\
    \ + 1));\n  double t = min({t1, t2, t3});\n  if (t == t1) return sol_1();\n  if\
    \ (t == t2) return sol_2();\n  return sol_3();\n}\n"
  code: "/*\nknapsack01 \u306E\u5168\u5217\u6319\n\u30FBO(2^n) \u3067\u3001(wt, val)\
    \ \u3092\u5168\u5217\u6319 + wt \u3067\u30BD\u30FC\u30C8\n\u30FBremove extra =\
    \ true \u2192 val \u304C\u5897\u52A0\u306B\u306A\u308B\u3068\u3053\u308D\u3060\
    \u3051\u6B8B\u3059\n*/\ntemplate <typename WT, typename VAL>\nvc<pair<WT, VAL>>\
    \ knapsack01_gen_all(vc<WT> weight, vc<VAL> val,\n                           \
    \          bool remove_extra) {\n  int n = len(weight);\n  using P = pair<WT,\
    \ VAL>;\n  vc<P> dp;\n  dp.eb(0, 0);\n  FOR(i, n) {\n    vc<P> tmp(len(dp));\n\
    \    FOR(j, len(dp)) tmp[j] = {dp[j].fi + weight[i], dp[j].se + val[i]};\n   \
    \ vc<P> res;\n    merge(all(dp), all(tmp), back_inserter(res));\n    swap(dp,\
    \ res);\n  }\n  if (!remove_extra) return dp;\n  vc<P> res;\n  res.reserve(len(dp));\n\
    \  for (auto&& [w, v]: dp) {\n    while (len(res) && res.back().fi == w) res.pop_back();\n\
    \    if (len(res) && res.back().se >= v) continue;\n    res.eb(w, v);\n  }\n \
    \ return res;\n}\n\ntemplate <typename WT, typename VAL>\nVAL knapsack01(vc<WT>\
    \ weight, vc<VAL> val, WT LIM) {\n  chmin(LIM, SUM<WT>(weight));\n  int n = len(weight);\n\
    \  assert(len(val) == n);\n\n  // \u534A\u5206\u5168\u5217\u6319 + \u5C3A\u53D6\
    \u308A\u6CD5\n  // O(2^{N/2})\n  auto sol_1 = [&]() -> VAL {\n    vc<WT> wt_l\
    \ = {weight.begin(), weight.begin() + n / 2};\n    vc<WT> wt_r = {weight.begin()\
    \ + n / 2, weight.end()};\n    vc<VAL> val_l = {val.begin(), val.begin() + n /\
    \ 2};\n    vc<VAL> val_r = {val.begin() + n / 2, val.end()};\n    auto dp1 = knapsack01_gen_all(wt_l,\
    \ val_l, true);\n    auto dp2 = knapsack01_gen_all(wt_r, val_r, true);\n    int\
    \ q = len(dp2);\n    VAL ANS = 0;\n    FOR(p, len(dp1)) {\n      while (q && (dp1[p].fi\
    \ + dp2[q - 1].fi > LIM)) --q;\n      if (q == 0) break;\n      chmax(ANS, dp1[p].se\
    \ + dp2[q - 1].se);\n    }\n    return ANS;\n  };\n\n  // wt \u3054\u3068\u306E\
    \ dp\n  // O(N LIM)\n  auto sol_2 = [&]() -> VAL {\n    vc<VAL> dp(LIM + 1);\n\
    \    ll total = 0;\n    FOR(k, n) {\n      ll mx = min<ll>(LIM - weight[k], total);\n\
    \      FOR_R(i, mx + 1) chmax(dp[i + weight[k]], dp[i] + val[k]);\n      total\
    \ += weight[k];\n    };\n    return MAX(dp);\n  };\n\n  // val \u3054\u3068\u306E\
    \ dp\n  // O(N sum val)\n  auto sol_3 = [&]() -> VAL {\n    // val -> min wt\n\
    \    vc<WT> dp(SUM<VAL>(val) + 1, LIM + 1);\n    dp[0] = 0;\n    ll total = 0;\n\
    \    FOR(k, n) {\n      FOR_R(i, total + 1) { chmin(dp[i + val[k]], dp[i] + weight[k]);\
    \ }\n      total += val[k];\n    }\n    VAL ANS = 0;\n    FOR(i, total + 1) if\
    \ (dp[i] <= LIM) ANS = i;\n    return ANS;\n  };\n\n  double t1 = log(2) * n *\
    \ 0.5;\n  double t2 = log((n + 1) * (LIM + 1));\n  double t3 = log((n + 1) * (SUM<WT>(val)\
    \ + 1));\n  double t = min({t1, t2, t3});\n  if (t == t1) return sol_1();\n  if\
    \ (t == t2) return sol_2();\n  return sol_3();\n}\n"
  dependsOn: []
  isVerificationFile: false
  path: knapsack/knapsack01.hpp
  requiredBy: []
  timestamp: '2022-10-21 17:08:40+09:00'
  verificationStatus: LIBRARY_SOME_WA
  verifiedWith:
  - test/aoj/DPL_1_H.test.cpp
  - test/aoj/DPL_1_B.test.cpp
  - test/aoj/DPL_1_F.test.cpp
documentation_of: knapsack/knapsack01.hpp
layout: document
redirect_from:
- /library/knapsack/knapsack01.hpp
- /library/knapsack/knapsack01.hpp.html
title: knapsack/knapsack01.hpp
---
