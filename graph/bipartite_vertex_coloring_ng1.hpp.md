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
    - https://codeforces.com/contest/1680/problem/F
  bundledCode: "#line 1 \"graph/bipartite_vertex_coloring_ng1.hpp\"\n\n// 1 \u8FBA\
    \u3092\u9664\u3044\u3066\u4E8C\u90E8\u30B0\u30E9\u30D5\u306B\u306A\u308B\u3088\
    \u3046\u306B\u3059\u308B\n// https://codeforces.com/contest/1680/problem/F\ntemplate\
    \ <typename GT>\nvc<int> bipartite_vertex_coloring_ng1(GT& G) {\n  assert(G.is_prepared());\n\
    \  const int N = G.N, M = G.M;\n  vc<int> V, par(N, -1), color(N, -1);\n  V.reserve(N);\n\
    \  vc<int> dp_0(N), dp_1(N);\n  vc<bool> done(M);\n  int odd = 0;\n  auto dfs\
    \ = [&](auto& dfs, int v) -> void {\n    V.eb(v);\n    for (auto&& e: G[v]) {\n\
    \      if (done[e.id]) continue;\n      done[e.id] = 1;\n      if (color[e.to]\
    \ == -1) {\n        par[e.to] = v, color[e.to] = color[v] ^ 1;\n        dfs(dfs,\
    \ e.to);\n      } else {\n        if (color[v] != color[e.to]) dp_0[v]++, dp_0[e.to]--;\n\
    \        if (color[v] == color[e.to]) dp_1[v]++, dp_1[e.to]--, odd++;\n      }\n\
    \    }\n  };\n  FOR(v, N) if (color[v] == -1) color[v] = 0, dfs(dfs, v);\n  FOR_R(i,\
    \ N) {\n    int v = V[i], p = par[V[i]];\n    if (p == -1) continue;\n    dp_0[p]\
    \ += dp_0[v], dp_1[p] += dp_1[v];\n  }\n  if (odd <= 1) return color;\n  FOR(v,\
    \ N) {\n    if (par[v] == -1 || dp_1[v] != odd || (dp_0[v] && dp_1[v])) continue;\n\
    \    for (auto&& w: V) {\n      if (par[w] == -1) continue;\n      color[w] =\
    \ color[par[w]] ^ (w == v ? 0 : 1);\n    }\n    return color;\n  }\n  return {};\n\
    }\n"
  code: "\n// 1 \u8FBA\u3092\u9664\u3044\u3066\u4E8C\u90E8\u30B0\u30E9\u30D5\u306B\
    \u306A\u308B\u3088\u3046\u306B\u3059\u308B\n// https://codeforces.com/contest/1680/problem/F\n\
    template <typename GT>\nvc<int> bipartite_vertex_coloring_ng1(GT& G) {\n  assert(G.is_prepared());\n\
    \  const int N = G.N, M = G.M;\n  vc<int> V, par(N, -1), color(N, -1);\n  V.reserve(N);\n\
    \  vc<int> dp_0(N), dp_1(N);\n  vc<bool> done(M);\n  int odd = 0;\n  auto dfs\
    \ = [&](auto& dfs, int v) -> void {\n    V.eb(v);\n    for (auto&& e: G[v]) {\n\
    \      if (done[e.id]) continue;\n      done[e.id] = 1;\n      if (color[e.to]\
    \ == -1) {\n        par[e.to] = v, color[e.to] = color[v] ^ 1;\n        dfs(dfs,\
    \ e.to);\n      } else {\n        if (color[v] != color[e.to]) dp_0[v]++, dp_0[e.to]--;\n\
    \        if (color[v] == color[e.to]) dp_1[v]++, dp_1[e.to]--, odd++;\n      }\n\
    \    }\n  };\n  FOR(v, N) if (color[v] == -1) color[v] = 0, dfs(dfs, v);\n  FOR_R(i,\
    \ N) {\n    int v = V[i], p = par[V[i]];\n    if (p == -1) continue;\n    dp_0[p]\
    \ += dp_0[v], dp_1[p] += dp_1[v];\n  }\n  if (odd <= 1) return color;\n  FOR(v,\
    \ N) {\n    if (par[v] == -1 || dp_1[v] != odd || (dp_0[v] && dp_1[v])) continue;\n\
    \    for (auto&& w: V) {\n      if (par[w] == -1) continue;\n      color[w] =\
    \ color[par[w]] ^ (w == v ? 0 : 1);\n    }\n    return color;\n  }\n  return {};\n\
    }"
  dependsOn: []
  isVerificationFile: false
  path: graph/bipartite_vertex_coloring_ng1.hpp
  requiredBy: []
  timestamp: '2023-01-27 17:51:37+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: graph/bipartite_vertex_coloring_ng1.hpp
layout: document
redirect_from:
- /library/graph/bipartite_vertex_coloring_ng1.hpp
- /library/graph/bipartite_vertex_coloring_ng1.hpp.html
title: graph/bipartite_vertex_coloring_ng1.hpp
---
