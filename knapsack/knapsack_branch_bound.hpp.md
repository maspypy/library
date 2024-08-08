---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/yukicoder/626.test.cpp
    title: test/yukicoder/626.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 1 \"knapsack/knapsack_branch_bound.hpp\"\n// \u5206\u679D\u9650\
    \u5B9A\u6CD5\u3002yukicoder 626\ntemplate <typename WT, typename VAL>\nVAL knapsack_branch_bound(vc<WT>\
    \ wt, vc<VAL> val, WT LIM) {\n  int N = len(val);\n  using Re = long double;\n\
    \  vc<Re> sort_key(N);\n  FOR(i, N) sort_key[i] = Re(val[i]) / wt[i];\n  auto\
    \ I = argsort(sort_key);\n  reverse(all(I));\n  wt = rearrange(wt, I);\n  val\
    \ = rearrange(val, I);\n\n  VAL ANS = 0;\n  auto dfs = [&](auto dfs, int nxt,\
    \ WT now_wt, VAL now_val) -> void {\n    if (now_wt > LIM) return;\n    chmax(ANS,\
    \ now_val);\n    if (nxt == N) return;\n    Re bd = now_val;\n    Re rest = LIM\
    \ - now_wt;\n    FOR3(i, nxt, N) {\n      if (rest >= wt[i]) {\n        rest -=\
    \ wt[i];\n        bd += val[i];\n        continue;\n      }\n      bd += rest\
    \ / wt[i] * val[i];\n      break;\n    }\n    if (bd <= ANS) return;\n    dfs(dfs,\
    \ nxt + 1, now_wt + wt[nxt], now_val + val[nxt]);\n    dfs(dfs, nxt + 1, now_wt,\
    \ now_val);\n  };\n\n  dfs(dfs, 0, 0, 0);\n  return ANS;\n}\n"
  code: "// \u5206\u679D\u9650\u5B9A\u6CD5\u3002yukicoder 626\ntemplate <typename\
    \ WT, typename VAL>\nVAL knapsack_branch_bound(vc<WT> wt, vc<VAL> val, WT LIM)\
    \ {\n  int N = len(val);\n  using Re = long double;\n  vc<Re> sort_key(N);\n \
    \ FOR(i, N) sort_key[i] = Re(val[i]) / wt[i];\n  auto I = argsort(sort_key);\n\
    \  reverse(all(I));\n  wt = rearrange(wt, I);\n  val = rearrange(val, I);\n\n\
    \  VAL ANS = 0;\n  auto dfs = [&](auto dfs, int nxt, WT now_wt, VAL now_val) ->\
    \ void {\n    if (now_wt > LIM) return;\n    chmax(ANS, now_val);\n    if (nxt\
    \ == N) return;\n    Re bd = now_val;\n    Re rest = LIM - now_wt;\n    FOR3(i,\
    \ nxt, N) {\n      if (rest >= wt[i]) {\n        rest -= wt[i];\n        bd +=\
    \ val[i];\n        continue;\n      }\n      bd += rest / wt[i] * val[i];\n  \
    \    break;\n    }\n    if (bd <= ANS) return;\n    dfs(dfs, nxt + 1, now_wt +\
    \ wt[nxt], now_val + val[nxt]);\n    dfs(dfs, nxt + 1, now_wt, now_val);\n  };\n\
    \n  dfs(dfs, 0, 0, 0);\n  return ANS;\n}"
  dependsOn: []
  isVerificationFile: false
  path: knapsack/knapsack_branch_bound.hpp
  requiredBy: []
  timestamp: '2022-10-21 17:08:40+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/yukicoder/626.test.cpp
documentation_of: knapsack/knapsack_branch_bound.hpp
layout: document
redirect_from:
- /library/knapsack/knapsack_branch_bound.hpp
- /library/knapsack/knapsack_branch_bound.hpp.html
title: knapsack/knapsack_branch_bound.hpp
---
