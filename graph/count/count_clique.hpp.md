---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':warning:'
  attributes:
    links:
    - https://contest.ucup.ac/contest/1358/problem/7514
  bundledCode: "#line 1 \"graph/count/count_clique.hpp\"\n\n// (n,m)=(1000,1000) \u3067\
    \ 24ms\n// https://contest.ucup.ac/contest/1358/problem/7514\ntemplate <typename\
    \ GT>\nu64 count_clique(GT& G) {\n  INT(N, M);\n  Graph<int, 0> G(N);\n  G.read_graph(M);\n\
    \n  u64 ANS = 1; // emptyset\n  vc<int> new_idx(N, -1);\n\n  while (N) {\n   \
    \ auto deg = G.deg_array();\n    int p = min_element(all(deg)) - deg.begin();\n\
    \    vc<int> nbd, other;\n    for (auto& e: G[p]) nbd.eb(e.to);\n    FOR(v, N)\
    \ {\n      if (v != p) other.eb(v);\n    }\n\n    // nbd graph \u306E\u88DC\u30B0\
    \u30E9\u30D5\u3092\u4F5C\u3063\u3066\u3001\u72EC\u7ACB\u96C6\u5408\u3092\u6570\
    \u3048\u308B\n    int n = len(nbd);\n    FOR(i, n) { new_idx[nbd[i]] = i; }\n\
    \    vv(int, adj, n, n);\n    for (auto& e: G.edges) {\n      int a = e.frm, b\
    \ = e.to;\n      a = new_idx[a], b = new_idx[b];\n      if (a == -1 || b == -1)\
    \ continue;\n      adj[a][b] = adj[b][a] = 1;\n    }\n    FOR(i, n) { new_idx[nbd[i]]\
    \ = -1; }\n    Graph<int, 0> G1(n);\n    FOR(i, n) FOR(j, i) if (!adj[i][j]) G1.add(i,\
    \ j);\n    G1.build();\n    u64 cnt = count_independent_set(G1);\n    ANS += cnt;\n\
    \    G = G.rearrange(other).fi;\n    assert(G.N == N - 1);\n    --N;\n  }\n  return\
    \ ANS;\n}\n"
  code: "\n// (n,m)=(1000,1000) \u3067 24ms\n// https://contest.ucup.ac/contest/1358/problem/7514\n\
    template <typename GT>\nu64 count_clique(GT& G) {\n  INT(N, M);\n  Graph<int,\
    \ 0> G(N);\n  G.read_graph(M);\n\n  u64 ANS = 1; // emptyset\n  vc<int> new_idx(N,\
    \ -1);\n\n  while (N) {\n    auto deg = G.deg_array();\n    int p = min_element(all(deg))\
    \ - deg.begin();\n    vc<int> nbd, other;\n    for (auto& e: G[p]) nbd.eb(e.to);\n\
    \    FOR(v, N) {\n      if (v != p) other.eb(v);\n    }\n\n    // nbd graph \u306E\
    \u88DC\u30B0\u30E9\u30D5\u3092\u4F5C\u3063\u3066\u3001\u72EC\u7ACB\u96C6\u5408\
    \u3092\u6570\u3048\u308B\n    int n = len(nbd);\n    FOR(i, n) { new_idx[nbd[i]]\
    \ = i; }\n    vv(int, adj, n, n);\n    for (auto& e: G.edges) {\n      int a =\
    \ e.frm, b = e.to;\n      a = new_idx[a], b = new_idx[b];\n      if (a == -1 ||\
    \ b == -1) continue;\n      adj[a][b] = adj[b][a] = 1;\n    }\n    FOR(i, n) {\
    \ new_idx[nbd[i]] = -1; }\n    Graph<int, 0> G1(n);\n    FOR(i, n) FOR(j, i) if\
    \ (!adj[i][j]) G1.add(i, j);\n    G1.build();\n    u64 cnt = count_independent_set(G1);\n\
    \    ANS += cnt;\n    G = G.rearrange(other).fi;\n    assert(G.N == N - 1);\n\
    \    --N;\n  }\n  return ANS;\n}\n"
  dependsOn: []
  isVerificationFile: false
  path: graph/count/count_clique.hpp
  requiredBy: []
  timestamp: '2023-10-06 05:10:45+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: graph/count/count_clique.hpp
layout: document
redirect_from:
- /library/graph/count/count_clique.hpp
- /library/graph/count/count_clique.hpp.html
title: graph/count/count_clique.hpp
---
