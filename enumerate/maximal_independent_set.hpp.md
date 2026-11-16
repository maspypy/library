---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: enumerate/bits.hpp
    title: enumerate/bits.hpp
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':warning:'
  attributes:
    links:
    - https://atcoder.jp/contests/jag2014autumn/tasks/icpc2014autumn_i
    - https://github.com/maspypy/library/blob/main/enumerate/maximal_independent_set.hpp
  bundledCode: "#line 1 \"enumerate/maximal_independent_set.hpp\"\n// Source: https://github.com/maspypy/library/blob/main/enumerate/maximal_independent_set.hpp\n\
    \n#line 1 \"enumerate/bits.hpp\"\n// Source: https://github.com/maspypy/library/blob/main/enumerate/bits.hpp\n\
    template <typename BS, typename F>\nvoid enumerate_bits_bitset(BS& b, int L, int\
    \ R, F&& f) {\n  if (L >= len(b)) return;\n  bool end = false;\n  int p = (b[L]\
    \ ? L : b._Find_next(L));\n  while (p < R) {\n    f(p, end);\n    if (end) break;\n\
    \    p = b._Find_next(p);\n  }\n}\n\ntemplate <typename UINT, typename F>\ninline\
    \ void enumerate_all_bit(UINT s, F&& f) {\n  static_assert(is_unsigned<UINT>::value);\n\
    \  bool end = false;\n  while (s) {\n    f(lowbit(s), end);\n    if (end) break;\n\
    \    s &= s - 1;\n  }\n}\n\ntemplate <typename UINT, bool inc_empty, typename\
    \ F>\ninline void enumerate_all_subset(UINT s, F&& f) {\n  static_assert(is_unsigned<UINT>::value);\n\
    \  bool end = false;\n  for (UINT t = s; t; t = (t - 1) & s) {\n    f(t, end);\n\
    \    if (end) break;\n  }\n  if constexpr (inc_empty) {\n    if (!end) f(UINT(0),\
    \ end);\n  }\n}\n#line 4 \"enumerate/maximal_independent_set.hpp\"\n\n// 3^(N/3).\
    \ \u6975\u5927.\n// https://atcoder.jp/contests/jag2014autumn/tasks/icpc2014autumn_i\n\
    template <typename GT, typename F>\nvoid enumerate_maximal_independent_set(const\
    \ GT& G, F f) {\n  assert(G.N < 64);\n  int N = G.N;\n  vc<u64> adj(N);\n  for\
    \ (auto& e : G.edges) {\n    adj[e.frm] |= u64(1) << e.to;\n    adj[e.to] |= u64(1)\
    \ << e.frm;\n  }\n  bool end = false;\n  auto dfs = [&](auto& dfs, u64 I, u64\
    \ V) -> void {\n    if (V == 0) {\n      f(I, end);\n      return;\n    }\n  \
    \  int min_deg = infty<int>;\n    int v = -1;\n    enumerate_all_bit(V, [&](int\
    \ i, bool) -> void {\n      int d = popcnt(V & adj[i]);\n      if (chmin(min_deg,\
    \ d)) v = i;\n    });\n    u64 cand = (V & adj[v]) | u64(1) << v;\n    enumerate_all_bit(cand,\
    \ [&](int v, bool& end_inner) -> void {\n      dfs(dfs, I | u64(1) << v, V & (~(u64(1)\
    \ << v)) & ~(adj[v]));\n      end_inner = end;\n    });\n  };\n  u64 FULL = 0;\n\
    \  FOR(i, N) FULL |= u64(1) << i;\n  dfs(dfs, 0, FULL);\n}\n"
  code: "// Source: https://github.com/maspypy/library/blob/main/enumerate/maximal_independent_set.hpp\n\
    \n#include \"enumerate/bits.hpp\"\n\n// 3^(N/3). \u6975\u5927.\n// https://atcoder.jp/contests/jag2014autumn/tasks/icpc2014autumn_i\n\
    template <typename GT, typename F>\nvoid enumerate_maximal_independent_set(const\
    \ GT& G, F f) {\n  assert(G.N < 64);\n  int N = G.N;\n  vc<u64> adj(N);\n  for\
    \ (auto& e : G.edges) {\n    adj[e.frm] |= u64(1) << e.to;\n    adj[e.to] |= u64(1)\
    \ << e.frm;\n  }\n  bool end = false;\n  auto dfs = [&](auto& dfs, u64 I, u64\
    \ V) -> void {\n    if (V == 0) {\n      f(I, end);\n      return;\n    }\n  \
    \  int min_deg = infty<int>;\n    int v = -1;\n    enumerate_all_bit(V, [&](int\
    \ i, bool) -> void {\n      int d = popcnt(V & adj[i]);\n      if (chmin(min_deg,\
    \ d)) v = i;\n    });\n    u64 cand = (V & adj[v]) | u64(1) << v;\n    enumerate_all_bit(cand,\
    \ [&](int v, bool& end_inner) -> void {\n      dfs(dfs, I | u64(1) << v, V & (~(u64(1)\
    \ << v)) & ~(adj[v]));\n      end_inner = end;\n    });\n  };\n  u64 FULL = 0;\n\
    \  FOR(i, N) FULL |= u64(1) << i;\n  dfs(dfs, 0, FULL);\n}\n"
  dependsOn:
  - enumerate/bits.hpp
  isVerificationFile: false
  path: enumerate/maximal_independent_set.hpp
  requiredBy: []
  timestamp: '2026-11-16 16:26:17+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: enumerate/maximal_independent_set.hpp
layout: document
redirect_from:
- /library/enumerate/maximal_independent_set.hpp
- /library/enumerate/maximal_independent_set.hpp.html
title: enumerate/maximal_independent_set.hpp
---
