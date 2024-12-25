---
data:
  _extendedDependsOn:
  - icon: ':x:'
    path: ds/unionfind/unionfind.hpp
    title: ds/unionfind/unionfind.hpp
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':warning:'
  attributes:
    links:
    - https://atcoder.jp/contests/pakencamp-2023-day1/tasks/pakencamp_2023_day1_p
  bundledCode: "#line 2 \"ds/unionfind/unionfind.hpp\"\n\nstruct UnionFind {\n  int\
    \ n, n_comp;\n  vc<int> dat; // par or (-size)\n  UnionFind(int n = 0) { build(n);\
    \ }\n\n  void build(int m) {\n    n = m, n_comp = m;\n    dat.assign(n, -1);\n\
    \  }\n\n  void reset() { build(n); }\n\n  int operator[](int x) {\n    while (dat[x]\
    \ >= 0) {\n      int pp = dat[dat[x]];\n      if (pp < 0) { return dat[x]; }\n\
    \      x = dat[x] = pp;\n    }\n    return x;\n  }\n\n  ll size(int x) {\n   \
    \ x = (*this)[x];\n    return -dat[x];\n  }\n\n  bool merge(int x, int y) {\n\
    \    x = (*this)[x], y = (*this)[y];\n    if (x == y) return false;\n    if (-dat[x]\
    \ < -dat[y]) swap(x, y);\n    dat[x] += dat[y], dat[y] = x, n_comp--;\n    return\
    \ true;\n  }\n\n  vc<int> get_all() {\n    vc<int> A(n);\n    FOR(i, n) A[i] =\
    \ (*this)[i];\n    return A;\n  }\n};\n#line 2 \"graph/blackbox/mst.hpp\"\n\n\
    // Brouvka\n// find_unused(v)\uFF1Aunused \u306A\u3046\u3061\u3067\u3001v \u3068\
    \u6700\u5C0F\u30B3\u30B9\u30C8\u3067\u7D50\u3079\u308B\u70B9\u3092\u63A2\u3059\
    \u3002\n// pair<int,COST> \u306A\u3051\u308C\u3070 {-1,*} \u3092\u8FD4\u3059\u3053\
    \u3068\u3002\ntemplate <typename COST, typename F0, typename F1, typename F2>\n\
    vc<tuple<int, int, COST>> blackbox_mst(int N, F0 set_used, F1 set_unused,\n  \
    \                                     F2 find_unused) {\n  using edge = tuple<int,\
    \ int, COST>;\n  UnionFind uf(N);\n  vc<edge> res;\n  while (1) {\n    bool upd\
    \ = 0;\n    vvc<int> comp(N);\n    vc<edge> cand(N, {-1, -1, -1});\n    FOR(v,\
    \ N) comp[uf[v]].eb(v);\n    FOR(v, N) if (uf[v] == v) {\n      for (auto&& x:\
    \ comp[v]) { set_used(x); }\n      for (auto&& x: comp[v]) {\n        auto [y,\
    \ cost] = find_unused(x);\n        if (y == -1) continue;\n        auto [a, b,\
    \ c] = cand[v];\n        if (a == -1 || cost < c) { cand[v] = {x, y, cost}; }\n\
    \      }\n      for (auto&& x: comp[v]) { set_unused(x); }\n    }\n    FOR(v,\
    \ N) if (uf[v] == v) {\n      auto [a, b, c] = cand[v];\n      if (a == -1) continue;\n\
    \      upd = 1;\n      if (uf.merge(a, b)) res.eb(a, b, c);\n    }\n    if (!upd)\
    \ break;\n  }\n  return res;\n}\n\n// Brouvka\n// https://atcoder.jp/contests/pakencamp-2023-day1/tasks/pakencamp_2023_day1_p\n\
    // incremental \u306A\u30C7\u30FC\u30BF\u69CB\u9020\u3092\u4F7F\u3046\u7248\n\
    // init\uFF1A\u63A2\u7D22\u306E\u305F\u3081\u306E\u30C7\u30FC\u30BF\u69CB\u9020\
    \u521D\u671F\u5316\u7B49. 2logN \u56DE\u7A0B\u5EA6\u547C\u3070\u308C\u308B.\n\
    // add\uFF1A\u63A2\u7D22\u5BFE\u8C61\u306B\u8FFD\u52A0\n// find\uFF1A(w,wt) or\
    \ (-1,*)\ntemplate <typename COST, typename F0, typename F1, typename F2>\nvc<tuple<int,\
    \ int, COST>> blackbox_mst_incremental(int N, F0 init, F1 add,\n             \
    \                                      F2 find) {\n  using edge = tuple<int, int,\
    \ COST>;\n  UnionFind uf(N);\n  vc<edge> res;\n  while (uf.n_comp > 1) {\n   \
    \ bool upd = 0;\n    vvc<int> comp(N);\n    FOR(v, N) comp[uf[v]].eb(v);\n   \
    \ vc<COST> wt(N, infty<COST>);\n    vc<pair<int, int>> who(N, {-1, -1});\n   \
    \ init();\n    FOR(i, N) {\n      for (auto& v: comp[i]) {\n        auto [w, x]\
    \ = find(v);\n        if (w != -1 && chmin(wt[i], x)) who[i] = {v, w};\n     \
    \ }\n      for (auto& v: comp[i]) { add(v); }\n    }\n    init();\n    FOR_R(i,\
    \ N) {\n      for (auto& v: comp[i]) {\n        auto [w, x] = find(v);\n     \
    \   if (w != -1 && chmin(wt[i], x)) who[i] = {v, w};\n      }\n      for (auto&\
    \ v: comp[i]) { add(v); }\n    }\n    FOR(i, N) {\n      auto [a, b] = who[i];\n\
    \      if (a == -1) continue;\n      if (uf.merge(a, b)) {\n        upd = true;\n\
    \        res.eb(a, b, wt[i]);\n      }\n    }\n    if (!upd) break;\n  }\n  return\
    \ res;\n}\n\n// Prim\n// O(N^2)\n// https://atcoder.jp/contests/pakencamp-2023-day1/tasks/pakencamp_2023_day1_p\n\
    template <typename COST, typename F>\nvc<tuple<int, int, COST>> mst_prim(int N,\
    \ F cost) {\n  using edge = tuple<int, int, COST>;\n  UnionFind uf(N);\n  vc<edge>\
    \ res;\n  vc<ll> wt(N, infty<ll>);\n  vc<int> TO(N);\n  auto add = [&](int v)\
    \ -> void {\n    FOR(w, N) {\n      if (TO[w] != -1 && chmin(wt[w], cost(v, w)))\
    \ TO[w] = v;\n    }\n    wt[v] = infty<ll>;\n    TO[v] = -1;\n  };\n  add(0);\n\
    \  FOR(N - 1) {\n    int v = min_element(all(wt)) - wt.begin();\n    res.eb(TO[v],\
    \ v, wt[v]);\n    add(v);\n  }\n  return res;\n}\n"
  code: "#include \"ds/unionfind/unionfind.hpp\"\n\n// Brouvka\n// find_unused(v)\uFF1A\
    unused \u306A\u3046\u3061\u3067\u3001v \u3068\u6700\u5C0F\u30B3\u30B9\u30C8\u3067\
    \u7D50\u3079\u308B\u70B9\u3092\u63A2\u3059\u3002\n// pair<int,COST> \u306A\u3051\
    \u308C\u3070 {-1,*} \u3092\u8FD4\u3059\u3053\u3068\u3002\ntemplate <typename COST,\
    \ typename F0, typename F1, typename F2>\nvc<tuple<int, int, COST>> blackbox_mst(int\
    \ N, F0 set_used, F1 set_unused,\n                                       F2 find_unused)\
    \ {\n  using edge = tuple<int, int, COST>;\n  UnionFind uf(N);\n  vc<edge> res;\n\
    \  while (1) {\n    bool upd = 0;\n    vvc<int> comp(N);\n    vc<edge> cand(N,\
    \ {-1, -1, -1});\n    FOR(v, N) comp[uf[v]].eb(v);\n    FOR(v, N) if (uf[v] ==\
    \ v) {\n      for (auto&& x: comp[v]) { set_used(x); }\n      for (auto&& x: comp[v])\
    \ {\n        auto [y, cost] = find_unused(x);\n        if (y == -1) continue;\n\
    \        auto [a, b, c] = cand[v];\n        if (a == -1 || cost < c) { cand[v]\
    \ = {x, y, cost}; }\n      }\n      for (auto&& x: comp[v]) { set_unused(x); }\n\
    \    }\n    FOR(v, N) if (uf[v] == v) {\n      auto [a, b, c] = cand[v];\n   \
    \   if (a == -1) continue;\n      upd = 1;\n      if (uf.merge(a, b)) res.eb(a,\
    \ b, c);\n    }\n    if (!upd) break;\n  }\n  return res;\n}\n\n// Brouvka\n//\
    \ https://atcoder.jp/contests/pakencamp-2023-day1/tasks/pakencamp_2023_day1_p\n\
    // incremental \u306A\u30C7\u30FC\u30BF\u69CB\u9020\u3092\u4F7F\u3046\u7248\n\
    // init\uFF1A\u63A2\u7D22\u306E\u305F\u3081\u306E\u30C7\u30FC\u30BF\u69CB\u9020\
    \u521D\u671F\u5316\u7B49. 2logN \u56DE\u7A0B\u5EA6\u547C\u3070\u308C\u308B.\n\
    // add\uFF1A\u63A2\u7D22\u5BFE\u8C61\u306B\u8FFD\u52A0\n// find\uFF1A(w,wt) or\
    \ (-1,*)\ntemplate <typename COST, typename F0, typename F1, typename F2>\nvc<tuple<int,\
    \ int, COST>> blackbox_mst_incremental(int N, F0 init, F1 add,\n             \
    \                                      F2 find) {\n  using edge = tuple<int, int,\
    \ COST>;\n  UnionFind uf(N);\n  vc<edge> res;\n  while (uf.n_comp > 1) {\n   \
    \ bool upd = 0;\n    vvc<int> comp(N);\n    FOR(v, N) comp[uf[v]].eb(v);\n   \
    \ vc<COST> wt(N, infty<COST>);\n    vc<pair<int, int>> who(N, {-1, -1});\n   \
    \ init();\n    FOR(i, N) {\n      for (auto& v: comp[i]) {\n        auto [w, x]\
    \ = find(v);\n        if (w != -1 && chmin(wt[i], x)) who[i] = {v, w};\n     \
    \ }\n      for (auto& v: comp[i]) { add(v); }\n    }\n    init();\n    FOR_R(i,\
    \ N) {\n      for (auto& v: comp[i]) {\n        auto [w, x] = find(v);\n     \
    \   if (w != -1 && chmin(wt[i], x)) who[i] = {v, w};\n      }\n      for (auto&\
    \ v: comp[i]) { add(v); }\n    }\n    FOR(i, N) {\n      auto [a, b] = who[i];\n\
    \      if (a == -1) continue;\n      if (uf.merge(a, b)) {\n        upd = true;\n\
    \        res.eb(a, b, wt[i]);\n      }\n    }\n    if (!upd) break;\n  }\n  return\
    \ res;\n}\n\n// Prim\n// O(N^2)\n// https://atcoder.jp/contests/pakencamp-2023-day1/tasks/pakencamp_2023_day1_p\n\
    template <typename COST, typename F>\nvc<tuple<int, int, COST>> mst_prim(int N,\
    \ F cost) {\n  using edge = tuple<int, int, COST>;\n  UnionFind uf(N);\n  vc<edge>\
    \ res;\n  vc<ll> wt(N, infty<ll>);\n  vc<int> TO(N);\n  auto add = [&](int v)\
    \ -> void {\n    FOR(w, N) {\n      if (TO[w] != -1 && chmin(wt[w], cost(v, w)))\
    \ TO[w] = v;\n    }\n    wt[v] = infty<ll>;\n    TO[v] = -1;\n  };\n  add(0);\n\
    \  FOR(N - 1) {\n    int v = min_element(all(wt)) - wt.begin();\n    res.eb(TO[v],\
    \ v, wt[v]);\n    add(v);\n  }\n  return res;\n}\n"
  dependsOn:
  - ds/unionfind/unionfind.hpp
  isVerificationFile: false
  path: graph/blackbox/mst.hpp
  requiredBy: []
  timestamp: '2024-05-14 16:33:21+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: graph/blackbox/mst.hpp
layout: document
redirect_from:
- /library/graph/blackbox/mst.hpp
- /library/graph/blackbox/mst.hpp.html
title: graph/blackbox/mst.hpp
---
