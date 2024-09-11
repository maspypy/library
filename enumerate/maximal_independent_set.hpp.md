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
    - https://atcoder.jp/contests/jag2014autumn/tasks/icpc2014autumn_i
  bundledCode: "#line 1 \"enumerate/maximal_independent_set.hpp\"\n\n// 3^(N/3). \u6975\
    \u5927.\n// https://atcoder.jp/contests/jag2014autumn/tasks/icpc2014autumn_i\n\
    template <typename GT, typename F>\nvoid enumerate_maximal_independent_set(GT&\
    \ G, F f) {\n  assert(G.N < 64);\n  int N = G.N;\n  vc<u64> adj(N);\n  for (auto&\
    \ e: G.edges) {\n    adj[e.frm] |= u64(1) << e.to;\n    adj[e.to] |= u64(1) <<\
    \ e.frm;\n  }\n  auto dfs = [&](auto& dfs, u64 I, u64 V) -> void {\n    if (V\
    \ == 0) {\n      f(I);\n      return;\n    }\n    int min_deg = infty<int>;\n\
    \    int v = -1;\n    enumerate_bits_64(V, [&](int i) -> void {\n      int d =\
    \ popcnt(V & adj[i]);\n      if (chmin(min_deg, d)) v = i;\n    });\n    u64 cand\
    \ = (V & adj[v]) | u64(1) << v;\n    enumerate_bits_64(cand, [&](int v) -> void\
    \ { dfs(dfs, I | u64(1) << v, V & (~(u64(1) << v)) & ~(adj[v])); });\n  };\n \
    \ u64 FULL = 0;\n  FOR(i, N) FULL |= u64(1) << i;\n  dfs(dfs, 0, FULL);\n}\n"
  code: "\n// 3^(N/3). \u6975\u5927.\n// https://atcoder.jp/contests/jag2014autumn/tasks/icpc2014autumn_i\n\
    template <typename GT, typename F>\nvoid enumerate_maximal_independent_set(GT&\
    \ G, F f) {\n  assert(G.N < 64);\n  int N = G.N;\n  vc<u64> adj(N);\n  for (auto&\
    \ e: G.edges) {\n    adj[e.frm] |= u64(1) << e.to;\n    adj[e.to] |= u64(1) <<\
    \ e.frm;\n  }\n  auto dfs = [&](auto& dfs, u64 I, u64 V) -> void {\n    if (V\
    \ == 0) {\n      f(I);\n      return;\n    }\n    int min_deg = infty<int>;\n\
    \    int v = -1;\n    enumerate_bits_64(V, [&](int i) -> void {\n      int d =\
    \ popcnt(V & adj[i]);\n      if (chmin(min_deg, d)) v = i;\n    });\n    u64 cand\
    \ = (V & adj[v]) | u64(1) << v;\n    enumerate_bits_64(cand, [&](int v) -> void\
    \ { dfs(dfs, I | u64(1) << v, V & (~(u64(1) << v)) & ~(adj[v])); });\n  };\n \
    \ u64 FULL = 0;\n  FOR(i, N) FULL |= u64(1) << i;\n  dfs(dfs, 0, FULL);\n}\n"
  dependsOn: []
  isVerificationFile: false
  path: enumerate/maximal_independent_set.hpp
  requiredBy: []
  timestamp: '2024-09-11 14:57:00+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: enumerate/maximal_independent_set.hpp
layout: document
redirect_from:
- /library/enumerate/maximal_independent_set.hpp
- /library/enumerate/maximal_independent_set.hpp.html
title: enumerate/maximal_independent_set.hpp
---
