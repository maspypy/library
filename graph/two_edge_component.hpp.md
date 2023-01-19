---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':x:'
    path: test/aoj/GRL_3_B.test.cpp
    title: test/aoj/GRL_3_B.test.cpp
  - icon: ':x:'
    path: test/library_checker/graph/two_edge_component.test.cpp
    title: test/library_checker/graph/two_edge_component.test.cpp
  - icon: ':x:'
    path: test/yukicoder/1983.test.cpp
    title: test/yukicoder/1983.test.cpp
  - icon: ':x:'
    path: test/yukicoder/529.test.cpp
    title: test/yukicoder/529.test.cpp
  _isVerificationFailed: true
  _pathExtension: hpp
  _verificationStatusIcon: ':x:'
  attributes:
    links: []
  bundledCode: "#line 1 \"graph/two_edge_component.hpp\"\n// (\u6210\u5206\u6570,\
    \ \u6210\u5206\u756A\u53F7\u306E vector)\r\ntemplate <typename GT>\r\npair<int,\
    \ vc<int>> two_edge_component(GT& G) {\r\n  assert(!G.is_directed());\r\n  int\
    \ N = G.N, M = G.M, n_comp = 0;\r\n  vc<int> V, par(N, -2), dp(N), comp(N);\r\n\
    \  V.reserve(N);\r\n  vc<bool> used(M);\r\n  auto dfs = [&](auto& dfs, int v)\
    \ -> void {\r\n    V.eb(v);\r\n    for (auto&& e: G[v]) {\r\n      if (used[e.id])\
    \ continue;\r\n      if (par[e.to] != -2) dp[v]++, dp[e.to]--, used[e.id] = 1;\r\
    \n      if (par[e.to] == -2) {\r\n        used[e.id] = 1;\r\n        par[e.to]\
    \ = v;\r\n        dfs(dfs, e.to);\r\n      }\r\n    }\r\n  };\r\n  FOR(v, N) if\
    \ (par[v] == -2) { par[v] = -1, dfs(dfs, v); }\r\n  FOR_R(i, N) {\r\n    if (par[V[i]]\
    \ != -1) dp[par[V[i]]] += dp[V[i]];\r\n  }\r\n  for (auto&& v: V) comp[v] = (dp[v]\
    \ == 0 ? n_comp++ : comp[par[v]]);\r\n  return {n_comp, comp};\r\n}\n"
  code: "// (\u6210\u5206\u6570, \u6210\u5206\u756A\u53F7\u306E vector)\r\ntemplate\
    \ <typename GT>\r\npair<int, vc<int>> two_edge_component(GT& G) {\r\n  assert(!G.is_directed());\r\
    \n  int N = G.N, M = G.M, n_comp = 0;\r\n  vc<int> V, par(N, -2), dp(N), comp(N);\r\
    \n  V.reserve(N);\r\n  vc<bool> used(M);\r\n  auto dfs = [&](auto& dfs, int v)\
    \ -> void {\r\n    V.eb(v);\r\n    for (auto&& e: G[v]) {\r\n      if (used[e.id])\
    \ continue;\r\n      if (par[e.to] != -2) dp[v]++, dp[e.to]--, used[e.id] = 1;\r\
    \n      if (par[e.to] == -2) {\r\n        used[e.id] = 1;\r\n        par[e.to]\
    \ = v;\r\n        dfs(dfs, e.to);\r\n      }\r\n    }\r\n  };\r\n  FOR(v, N) if\
    \ (par[v] == -2) { par[v] = -1, dfs(dfs, v); }\r\n  FOR_R(i, N) {\r\n    if (par[V[i]]\
    \ != -1) dp[par[V[i]]] += dp[V[i]];\r\n  }\r\n  for (auto&& v: V) comp[v] = (dp[v]\
    \ == 0 ? n_comp++ : comp[par[v]]);\r\n  return {n_comp, comp};\r\n}"
  dependsOn: []
  isVerificationFile: false
  path: graph/two_edge_component.hpp
  requiredBy: []
  timestamp: '2023-01-19 23:47:02+09:00'
  verificationStatus: LIBRARY_ALL_WA
  verifiedWith:
  - test/library_checker/graph/two_edge_component.test.cpp
  - test/yukicoder/529.test.cpp
  - test/yukicoder/1983.test.cpp
  - test/aoj/GRL_3_B.test.cpp
documentation_of: graph/two_edge_component.hpp
layout: document
redirect_from:
- /library/graph/two_edge_component.hpp
- /library/graph/two_edge_component.hpp.html
title: graph/two_edge_component.hpp
---
