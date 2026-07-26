---
data:
  _extendedDependsOn:
  - icon: ':question:'
    path: other/bit.hpp
    title: other/bit.hpp
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/1_mytest/count_K4.test.cpp
    title: test/1_mytest/count_K4.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 2 \"other/bit.hpp\"\n\nint popcnt(int x) { return __builtin_popcount(x);\
    \ }\nint popcnt(u32 x) { return __builtin_popcount(x); }\nint popcnt(ll x) { return\
    \ __builtin_popcountll(x); }\nint popcnt(u64 x) { return __builtin_popcountll(x);\
    \ }\nint popcnt_sgn(int x) { return (__builtin_parity(unsigned(x)) & 1 ? -1 :\
    \ 1); }\nint popcnt_sgn(u32 x) { return (__builtin_parity(x) & 1 ? -1 : 1); }\n\
    int popcnt_sgn(ll x) { return (__builtin_parityll(x) & 1 ? -1 : 1); }\nint popcnt_sgn(u64\
    \ x) { return (__builtin_parityll(x) & 1 ? -1 : 1); }\n// (0, 1, 2, 3, 4) -> (-1,\
    \ 0, 1, 1, 2)\nint topbit(int x) { return (x == 0 ? -1 : 31 - __builtin_clz(x));\
    \ }\nint topbit(u32 x) { return (x == 0 ? -1 : 31 - __builtin_clz(x)); }\nint\
    \ topbit(ll x) { return (x == 0 ? -1 : 63 - __builtin_clzll(x)); }\nint topbit(u64\
    \ x) { return (x == 0 ? -1 : 63 - __builtin_clzll(x)); }\n// (0, 1, 2, 3, 4) ->\
    \ (-1, 0, 1, 0, 2)\nint lowbit(int x) { return (x == 0 ? -1 : __builtin_ctz(x));\
    \ }\nint lowbit(u32 x) { return (x == 0 ? -1 : __builtin_ctz(x)); }\nint lowbit(ll\
    \ x) { return (x == 0 ? -1 : __builtin_ctzll(x)); }\nint lowbit(u64 x) { return\
    \ (x == 0 ? -1 : __builtin_ctzll(x)); }\n\ntemplate <typename T>\nT kth_bit(int\
    \ k) {\n  return T(1) << k;\n}\ntemplate <typename T>\nbool has_kth_bit(T x, int\
    \ k) {\n  return x >> k & 1;\n}\n\ntemplate <typename UINT>\nstruct all_bit {\n\
    \  UINT s;\n  struct iter {\n    UINT s;\n    int operator*() const { return lowbit(s);\
    \ }\n    void operator++() { s &= s - 1; }\n    bool operator!=(nullptr_t) const\
    \ { return s; }\n  };\n  iter begin() const { return {s}; }\n  nullptr_t end()\
    \ const { return nullptr; }\n};\n\ntemplate <typename UINT>\nstruct all_subset\
    \ {\n  UINT s;\n  struct iter {\n    UINT s, t;\n    bool done = false;\n    UINT\
    \ operator*() const { return t; }\n    void operator++() {\n      done = (t ==\
    \ 0);\n      t = (t - 1) & s;\n    }\n    bool operator!=(nullptr_t) const { return\
    \ !done; }\n  };\n  iter begin() const { return {s, s}; }\n  nullptr_t end() const\
    \ { return nullptr; }\n};\n\nconstexpr u64 full_mask(int n) { return n == 64 ?\
    \ -1ULL : (1ULL << n) - 1; }\n#line 2 \"graph/count/count_K4.hpp\"\n\n// M^{1.5}\
    \ + M^2/w\n// simple graph \u3092\u4EEE\u5B9A\ntemplate <typename GT>\nll count_K4(GT&\
    \ G) {\n  static_assert(!GT::is_directed);\n  assert(G.is_prepared());\n  const\
    \ int N = G.N;\n  Graph<int, 1> DAG(N);\n  {\n    auto deg = G.deg_array();\n\
    \    auto comp = [&](int a, int b) -> bool {\n      return (deg[a] == deg[b] ?\
    \ a < b : deg[a] < deg[b]);\n    };\n    for (auto&& e : G.edges) {\n      int\
    \ a = e.frm, b = e.to;\n      if (!comp(a, b)) swap(a, b);\n      DAG.add(a, b);\n\
    \    }\n    DAG.build();\n  }\n\n  vc<int> new_idx(N, -1);\n  ll ANS = 0;\n  FOR(a,\
    \ N) {\n    vc<int> V;\n    for (auto&& e : DAG[a]) V.eb(e.to);\n    FOR(i, len(V))\
    \ new_idx[V[i]] = i;\n    int n = len(V);\n    Graph<bool, 1> H(n);\n    FOR(i,\
    \ n) {\n      for (auto&& e : DAG[V[i]]) {\n        int j = new_idx[e.to];\n \
    \       if (j == -1) continue;\n        H.add(i, j);\n      }\n    }\n    H.build();\n\
    \    FOR(b, ceil(n, 64)) {\n      int L = 64 * b;\n      int R = L + 64;\n   \
    \   chmin(R, n);\n      vc<u64> dp(n);\n      FOR(i, L, R) {\n        for (auto&&\
    \ e : H[i]) {\n          dp[e.to] |= u64(1) << (i - L);\n        }\n      }\n\
    \      for (auto&& e : H.edges) {\n        ANS += popcnt(dp[e.frm] & dp[e.to]);\n\
    \      }\n    }\n    FOR(i, len(V)) new_idx[V[i]] = -1;\n  }\n  return ANS;\n\
    }\n"
  code: "#include \"other/bit.hpp\"\n\n// M^{1.5} + M^2/w\n// simple graph \u3092\u4EEE\
    \u5B9A\ntemplate <typename GT>\nll count_K4(GT& G) {\n  static_assert(!GT::is_directed);\n\
    \  assert(G.is_prepared());\n  const int N = G.N;\n  Graph<int, 1> DAG(N);\n \
    \ {\n    auto deg = G.deg_array();\n    auto comp = [&](int a, int b) -> bool\
    \ {\n      return (deg[a] == deg[b] ? a < b : deg[a] < deg[b]);\n    };\n    for\
    \ (auto&& e : G.edges) {\n      int a = e.frm, b = e.to;\n      if (!comp(a, b))\
    \ swap(a, b);\n      DAG.add(a, b);\n    }\n    DAG.build();\n  }\n\n  vc<int>\
    \ new_idx(N, -1);\n  ll ANS = 0;\n  FOR(a, N) {\n    vc<int> V;\n    for (auto&&\
    \ e : DAG[a]) V.eb(e.to);\n    FOR(i, len(V)) new_idx[V[i]] = i;\n    int n =\
    \ len(V);\n    Graph<bool, 1> H(n);\n    FOR(i, n) {\n      for (auto&& e : DAG[V[i]])\
    \ {\n        int j = new_idx[e.to];\n        if (j == -1) continue;\n        H.add(i,\
    \ j);\n      }\n    }\n    H.build();\n    FOR(b, ceil(n, 64)) {\n      int L\
    \ = 64 * b;\n      int R = L + 64;\n      chmin(R, n);\n      vc<u64> dp(n);\n\
    \      FOR(i, L, R) {\n        for (auto&& e : H[i]) {\n          dp[e.to] |=\
    \ u64(1) << (i - L);\n        }\n      }\n      for (auto&& e : H.edges) {\n \
    \       ANS += popcnt(dp[e.frm] & dp[e.to]);\n      }\n    }\n    FOR(i, len(V))\
    \ new_idx[V[i]] = -1;\n  }\n  return ANS;\n}"
  dependsOn:
  - other/bit.hpp
  isVerificationFile: false
  path: graph/count/count_K4.hpp
  requiredBy: []
  timestamp: '2026-07-26 22:20:09+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/1_mytest/count_K4.test.cpp
documentation_of: graph/count/count_K4.hpp
layout: document
redirect_from:
- /library/graph/count/count_K4.hpp
- /library/graph/count/count_K4.hpp.html
title: graph/count/count_K4.hpp
---
