---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/yukicoder/4_2.test.cpp
    title: test/yukicoder/4_2.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 1 \"knapsack/subset_sum.hpp\"\n\n// \u975E\u8CA0\u91CD\u307F\
    \ vals \u3092\u4F7F\u3063\u3066\u3001target \u3092\u4F5C\u308C\u308B\u304B\u3069\
    \u3046\u304B\uFF1F\n// \u4F5C\u308C\u308B\u306A\u3089\u3070\u5FA9\u5143\u3001\u305D\
    \u3046\u3067\u306A\u3044\u306A\u3089\u3070 {} \u3092\u8FD4\u3059\n// O(N max(vals))\
    \ \u6642\u9593\ntemplate <typename INT>\nvc<int> subset_sum(vc<INT>& vals, int\
    \ target) {\n  if (target <= 0) return {};\n  int n = len(vals);\n  int mx = MAX(vals);\n\
    \  int b = 0, sb = 0;\n  while (b < n && sb + vals[b] <= target) { sb += vals[b++];\
    \ }\n  if (b == n && sb != target) return {};\n\n  int off = target - mx + 1;\n\
    \  vc<int> dp(2 * mx, -1);\n  vv(int, PAR, n, 2 * mx, -1);\n  dp[sb - off] = b;\n\
    \  FOR3(i, b, n) {\n    auto newdp = dp;\n    auto& par = PAR[i];\n    int a =\
    \ vals[i];\n    FOR(j, mx) {\n      if (chmax(newdp[j + a], dp[j])) { par[j +\
    \ a] = -2; }\n    }\n    FOR3_R(j, mx, 2 * mx) {\n      FOR3_R(k, max(dp[j], 0),\
    \ newdp[j]) {\n        if (chmax(newdp[j - vals[k]], k)) par[j - vals[k]] = k;\n\
    \      }\n    }\n    swap(dp, newdp);\n  }\n  if (dp[mx - 1] == -1) return {};\n\
    \  vc<bool> use(n);\n  int i = n - 1, j = mx - 1;\n  while (i >= b) {\n    int\
    \ p = PAR[i][j];\n    if (p == -2) {\n      use[i] = !use[i];\n      j -= vals[i--];\n\
    \    }\n    elif (p == -1) { --i; }\n    else {\n      use[p] = !use[p];\n   \
    \   j += vals[p];\n    }\n  }\n  while (i >= 0) {\n    use[i] = !use[i];\n   \
    \ --i;\n  }\n  vc<int> I;\n  FOR(i, n) if (use[i]) I.eb(i);\n\n  ll sm = 0;\n\
    \  for (auto&& i: I) sm += vals[i];\n  assert(sm == target);\n\n  return I;\n\
    }\n"
  code: "\n// \u975E\u8CA0\u91CD\u307F vals \u3092\u4F7F\u3063\u3066\u3001target \u3092\
    \u4F5C\u308C\u308B\u304B\u3069\u3046\u304B\uFF1F\n// \u4F5C\u308C\u308B\u306A\u3089\
    \u3070\u5FA9\u5143\u3001\u305D\u3046\u3067\u306A\u3044\u306A\u3089\u3070 {} \u3092\
    \u8FD4\u3059\n// O(N max(vals)) \u6642\u9593\ntemplate <typename INT>\nvc<int>\
    \ subset_sum(vc<INT>& vals, int target) {\n  if (target <= 0) return {};\n  int\
    \ n = len(vals);\n  int mx = MAX(vals);\n  int b = 0, sb = 0;\n  while (b < n\
    \ && sb + vals[b] <= target) { sb += vals[b++]; }\n  if (b == n && sb != target)\
    \ return {};\n\n  int off = target - mx + 1;\n  vc<int> dp(2 * mx, -1);\n  vv(int,\
    \ PAR, n, 2 * mx, -1);\n  dp[sb - off] = b;\n  FOR3(i, b, n) {\n    auto newdp\
    \ = dp;\n    auto& par = PAR[i];\n    int a = vals[i];\n    FOR(j, mx) {\n   \
    \   if (chmax(newdp[j + a], dp[j])) { par[j + a] = -2; }\n    }\n    FOR3_R(j,\
    \ mx, 2 * mx) {\n      FOR3_R(k, max(dp[j], 0), newdp[j]) {\n        if (chmax(newdp[j\
    \ - vals[k]], k)) par[j - vals[k]] = k;\n      }\n    }\n    swap(dp, newdp);\n\
    \  }\n  if (dp[mx - 1] == -1) return {};\n  vc<bool> use(n);\n  int i = n - 1,\
    \ j = mx - 1;\n  while (i >= b) {\n    int p = PAR[i][j];\n    if (p == -2) {\n\
    \      use[i] = !use[i];\n      j -= vals[i--];\n    }\n    elif (p == -1) { --i;\
    \ }\n    else {\n      use[p] = !use[p];\n      j += vals[p];\n    }\n  }\n  while\
    \ (i >= 0) {\n    use[i] = !use[i];\n    --i;\n  }\n  vc<int> I;\n  FOR(i, n)\
    \ if (use[i]) I.eb(i);\n\n  ll sm = 0;\n  for (auto&& i: I) sm += vals[i];\n \
    \ assert(sm == target);\n\n  return I;\n}"
  dependsOn: []
  isVerificationFile: false
  path: knapsack/subset_sum.hpp
  requiredBy: []
  timestamp: '2022-10-21 17:08:40+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/yukicoder/4_2.test.cpp
documentation_of: knapsack/subset_sum.hpp
layout: document
redirect_from:
- /library/knapsack/subset_sum.hpp
- /library/knapsack/subset_sum.hpp.html
title: knapsack/subset_sum.hpp
---
