---
data:
  _extendedDependsOn:
  - icon: ':question:'
    path: ds/unionfind/unionfind.hpp
    title: ds/unionfind/unionfind.hpp
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':warning:'
  attributes:
    links: []
  bundledCode: "#line 2 \"ds/unionfind/unionfind.hpp\"\n\nstruct UnionFind {\n  int\
    \ n;\n  int n_comp;\n  vector<int> dat; // par or (-size)\n  UnionFind(int n =\
    \ 0) { build(n); }\n\n  void build(int m) {\n    n = m;\n    n_comp = m;\n   \
    \ dat.assign(n, -1);\n  }\n\n  int operator[](int x) {\n    while (dat[x] >= 0)\
    \ {\n      int pp = dat[dat[x]];\n      if (pp < 0) { return dat[x]; }\n     \
    \ x = dat[x] = pp;\n    }\n    return x;\n  }\n\n  int size(int x) {\n    assert(dat[x]\
    \ < 0);\n    return -dat[x];\n  }\n\n  bool merge(int x, int y) {\n    x = (*this)[x];\n\
    \    y = (*this)[y];\n    if (x == y) { return false; }\n    n_comp--;\n    if\
    \ (-dat[x] < -dat[y]) swap(x, y);\n    dat[x] += dat[y], dat[y] = x;\n    return\
    \ true;\n  }\n\n  vector<int> get_all() {\n    vector<int> A(n);\n    for (int\
    \ i = 0; i < n; ++i) A[i] = (*this)[i];\n    return A;\n  }\n};\n#line 2 \"graph/online_mst.hpp\"\
    \n\n// Brouvka\n// \u967D\u306B\u30B0\u30E9\u30D5\u3092\u4F5C\u3089\u305A\u3001\
    \u4F55\u3089\u304B\u306E\u30C7\u30FC\u30BF\u69CB\u9020\u3067\u672A\u8A2A\u554F\
    \u306E\u884C\u304D\u5148\u3092\u63A2\u3059\u60F3\u5B9A\u3002\n// find_unused(v)\uFF1A\
    unused \u306A\u3046\u3061\u3067\u3001v \u3068\u6700\u5C0F\u30B3\u30B9\u30C8\u3067\
    \u7D50\u3079\u308B\u70B9\u3092\u63A2\u3059\u3002\n// pair<int,COST> \u306A\u3051\
    \u308C\u3070 {-1,*} \u3092\u8FD4\u3059\u3053\u3068\u3002\ntemplate <typename COST,\
    \ typename F0, typename F1, typename F2>\nvc<tuple<int, int, COST>> online_mst(int\
    \ N, F0 set_used, F1 set_unused,\n                                     F2 find_unused)\
    \ {\n  using edge = tuple<int, int, COST>;\n  UnionFind uf(N);\n  vc<edge> res;\n\
    \  while (1) {\n    bool upd = 0;\n    vvc<int> comp(N);\n    vc<edge> cand(N,\
    \ {-1, -1, -1});\n    FOR(v, N) comp[uf[v]].eb(v);\n    FOR(v, N) if (uf[v] ==\
    \ v) {\n      for (auto&& x: comp[v]) { set_used(x); }\n      for (auto&& x: comp[v])\
    \ {\n        auto [y, cost] = find_unused(x);\n        if (y == -1) continue;\n\
    \        auto [a, b, c] = cand[v];\n        if (a == -1 || cost < c) { cand[v]\
    \ = {x, y, cost}; }\n      }\n      for (auto&& x: comp[v]) { set_unused(x); }\n\
    \    }\n    FOR(v, N) if (uf[v] == v) {\n      auto [a, b, c] = cand[v];\n   \
    \   if (a == -1) continue;\n      upd = 1;\n      uf.merge(a, b);\n      res.eb(a,\
    \ b, c);\n    }\n    if (!upd) break;\n  }\n  return res;\n}\n"
  code: "#include \"ds/unionfind/unionfind.hpp\"\n\n// Brouvka\n// \u967D\u306B\u30B0\
    \u30E9\u30D5\u3092\u4F5C\u3089\u305A\u3001\u4F55\u3089\u304B\u306E\u30C7\u30FC\
    \u30BF\u69CB\u9020\u3067\u672A\u8A2A\u554F\u306E\u884C\u304D\u5148\u3092\u63A2\
    \u3059\u60F3\u5B9A\u3002\n// find_unused(v)\uFF1Aunused \u306A\u3046\u3061\u3067\
    \u3001v \u3068\u6700\u5C0F\u30B3\u30B9\u30C8\u3067\u7D50\u3079\u308B\u70B9\u3092\
    \u63A2\u3059\u3002\n// pair<int,COST> \u306A\u3051\u308C\u3070 {-1,*} \u3092\u8FD4\
    \u3059\u3053\u3068\u3002\ntemplate <typename COST, typename F0, typename F1, typename\
    \ F2>\nvc<tuple<int, int, COST>> online_mst(int N, F0 set_used, F1 set_unused,\n\
    \                                     F2 find_unused) {\n  using edge = tuple<int,\
    \ int, COST>;\n  UnionFind uf(N);\n  vc<edge> res;\n  while (1) {\n    bool upd\
    \ = 0;\n    vvc<int> comp(N);\n    vc<edge> cand(N, {-1, -1, -1});\n    FOR(v,\
    \ N) comp[uf[v]].eb(v);\n    FOR(v, N) if (uf[v] == v) {\n      for (auto&& x:\
    \ comp[v]) { set_used(x); }\n      for (auto&& x: comp[v]) {\n        auto [y,\
    \ cost] = find_unused(x);\n        if (y == -1) continue;\n        auto [a, b,\
    \ c] = cand[v];\n        if (a == -1 || cost < c) { cand[v] = {x, y, cost}; }\n\
    \      }\n      for (auto&& x: comp[v]) { set_unused(x); }\n    }\n    FOR(v,\
    \ N) if (uf[v] == v) {\n      auto [a, b, c] = cand[v];\n      if (a == -1) continue;\n\
    \      upd = 1;\n      uf.merge(a, b);\n      res.eb(a, b, c);\n    }\n    if\
    \ (!upd) break;\n  }\n  return res;\n}"
  dependsOn:
  - ds/unionfind/unionfind.hpp
  isVerificationFile: false
  path: graph/online_mst.hpp
  requiredBy: []
  timestamp: '2022-12-04 15:34:04+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: graph/online_mst.hpp
layout: document
redirect_from:
- /library/graph/online_mst.hpp
- /library/graph/online_mst.hpp.html
title: graph/online_mst.hpp
---
