---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':warning:'
  attributes:
    links: []
  bundledCode: "#line 1 \"graph/count/count_K4.hpp\"\n\n// M^{1.5} + M^2/w\n// simple\
    \ graph \u3092\u4EEE\u5B9A\ntemplate <typename GT>\nll count_K4(GT& G) {\n  assert(G.is_prepared()\
    \ && !G.is_directed());\n  const int N = G.N;\n  Graph<bool, 1> DAG(N);\n  {\n\
    \    auto deg = G.deg_array();\n    auto comp = [&](int a, int b) -> bool {\n\
    \      return (deg[a] == deg[b] ? a < b : deg[a] < deg[b]);\n    };\n    for (auto&&\
    \ e: G.edges) {\n      int a = e.frm, b = e.to;\n      if (!comp(a, b)) swap(a,\
    \ b);\n      DAG.add(a, b);\n    }\n    DAG.build();\n  }\n\n  vc<int> new_idx(N,\
    \ -1);\n  ll ANS = 0;\n  FOR(a, N) {\n    vc<int> V;\n    for (auto&& e: DAG[a])\
    \ V.eb(e.to);\n    FOR(i, len(V)) new_idx[V[i]] = i;\n    int n = len(V);\n  \
    \  Graph<bool, 1> H(n);\n    FOR(i, n) {\n      for (auto&& e: DAG[V[i]]) {\n\
    \        int j = new_idx[e.to];\n        if (j == -1) continue;\n        H.add(i,\
    \ j);\n      }\n    }\n    H.build();\n    FOR(b, ceil(n, 64)) {\n      int L\
    \ = 64 * b;\n      int R = L + 64;\n      chmin(R, n);\n      vc<u64> dp(n);\n\
    \      FOR(i, L, R) {\n        for (auto&& e: H[i]) { dp[e.to] |= u64(1) << (i\
    \ - L); }\n      }\n      for (auto&& e: H.edges) { ANS += popcnt(dp[e.frm] &\
    \ dp[e.to]); }\n    }\n    FOR(i, len(V)) new_idx[V[i]] = -1;\n  }\n  return ANS;\n\
    }\n"
  code: "\n// M^{1.5} + M^2/w\n// simple graph \u3092\u4EEE\u5B9A\ntemplate <typename\
    \ GT>\nll count_K4(GT& G) {\n  assert(G.is_prepared() && !G.is_directed());\n\
    \  const int N = G.N;\n  Graph<bool, 1> DAG(N);\n  {\n    auto deg = G.deg_array();\n\
    \    auto comp = [&](int a, int b) -> bool {\n      return (deg[a] == deg[b] ?\
    \ a < b : deg[a] < deg[b]);\n    };\n    for (auto&& e: G.edges) {\n      int\
    \ a = e.frm, b = e.to;\n      if (!comp(a, b)) swap(a, b);\n      DAG.add(a, b);\n\
    \    }\n    DAG.build();\n  }\n\n  vc<int> new_idx(N, -1);\n  ll ANS = 0;\n  FOR(a,\
    \ N) {\n    vc<int> V;\n    for (auto&& e: DAG[a]) V.eb(e.to);\n    FOR(i, len(V))\
    \ new_idx[V[i]] = i;\n    int n = len(V);\n    Graph<bool, 1> H(n);\n    FOR(i,\
    \ n) {\n      for (auto&& e: DAG[V[i]]) {\n        int j = new_idx[e.to];\n  \
    \      if (j == -1) continue;\n        H.add(i, j);\n      }\n    }\n    H.build();\n\
    \    FOR(b, ceil(n, 64)) {\n      int L = 64 * b;\n      int R = L + 64;\n   \
    \   chmin(R, n);\n      vc<u64> dp(n);\n      FOR(i, L, R) {\n        for (auto&&\
    \ e: H[i]) { dp[e.to] |= u64(1) << (i - L); }\n      }\n      for (auto&& e: H.edges)\
    \ { ANS += popcnt(dp[e.frm] & dp[e.to]); }\n    }\n    FOR(i, len(V)) new_idx[V[i]]\
    \ = -1;\n  }\n  return ANS;\n}"
  dependsOn: []
  isVerificationFile: false
  path: graph/count/count_K4.hpp
  requiredBy: []
  timestamp: '2023-05-12 16:35:47+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: graph/count/count_K4.hpp
layout: document
redirect_from:
- /library/graph/count/count_K4.hpp
- /library/graph/count/count_K4.hpp.html
title: graph/count/count_K4.hpp
---
