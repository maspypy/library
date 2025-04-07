---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: ds/unionfind/unionfind.hpp
    title: ds/unionfind/unionfind.hpp
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':warning:'
  attributes:
    links:
    - https://qoj.ac/contest/1472/problem/7905
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
    \ (*this)[i];\n    return A;\n  }\n};\n#line 2 \"ds/monotone/prefix_add_append_get_max.hpp\"\
    \n\n// prefix add / \u672B\u5C3E\u8FFD\u52A0 / \u5168\u4F53 max\n// https://qoj.ac/contest/1472/problem/7905\n\
    struct Prefix_Add_Append_Get_Max {\n  int n;\n  UnionFind uf;\n  vc<pair<int,\
    \ int>> range;\n  vi dat;\n  ll max;\n  Prefix_Add_Append_Get_Max(int max_n) :\
    \ n(max_n), uf(max_n), range(max_n), max(-infty<ll>) {}\n\n  void append(int i,\
    \ ll x) {\n    assert(i == len(dat) && i < n);\n    range[i] = {i, i + 1};\n \
    \   if (i == 0) {\n      max = x;\n      dat.eb(x);\n      return;\n    }\n  \
    \  if (x > max) {\n      dat.eb(x - max);\n      max = x;\n      return;\n   \
    \ }\n    dat.eb(0);\n    merge(i);\n    return;\n  }\n\n  void merge(int i) {\n\
    \    int a = uf[i - 1], b = uf[i];\n    assert(a != b);\n    uf.merge(a, b);\n\
    \    int c = uf[a];\n    range[c].fi = range[a].fi, range[c].se = range[b].se;\n\
    \  }\n\n  // [0,i), +x\n  void prefix_add(int i, ll x) {\n    if (i == 0) return;\n\
    \    assert(i <= len(dat) && x >= 0);\n    dat[0] += x, max += x;\n    while (x\
    \ > 0) {\n      auto [l, r] = range[uf[i]];\n      int p = (l == i ? l : r);\n\
    \      if (p == len(dat)) return;\n      ll y = dat[p];\n      ll z = min(x, y);\n\
    \      dat[p] -= z, x -= z, max -= z;\n      if (dat[p] == 0) {\n        merge(p);\n\
    \        continue;\n      }\n    }\n  }\n\n  ll get_max() { return max; }\n};\n"
  code: "#include \"ds/unionfind/unionfind.hpp\"\n\n// prefix add / \u672B\u5C3E\u8FFD\
    \u52A0 / \u5168\u4F53 max\n// https://qoj.ac/contest/1472/problem/7905\nstruct\
    \ Prefix_Add_Append_Get_Max {\n  int n;\n  UnionFind uf;\n  vc<pair<int, int>>\
    \ range;\n  vi dat;\n  ll max;\n  Prefix_Add_Append_Get_Max(int max_n) : n(max_n),\
    \ uf(max_n), range(max_n), max(-infty<ll>) {}\n\n  void append(int i, ll x) {\n\
    \    assert(i == len(dat) && i < n);\n    range[i] = {i, i + 1};\n    if (i ==\
    \ 0) {\n      max = x;\n      dat.eb(x);\n      return;\n    }\n    if (x > max)\
    \ {\n      dat.eb(x - max);\n      max = x;\n      return;\n    }\n    dat.eb(0);\n\
    \    merge(i);\n    return;\n  }\n\n  void merge(int i) {\n    int a = uf[i -\
    \ 1], b = uf[i];\n    assert(a != b);\n    uf.merge(a, b);\n    int c = uf[a];\n\
    \    range[c].fi = range[a].fi, range[c].se = range[b].se;\n  }\n\n  // [0,i),\
    \ +x\n  void prefix_add(int i, ll x) {\n    if (i == 0) return;\n    assert(i\
    \ <= len(dat) && x >= 0);\n    dat[0] += x, max += x;\n    while (x > 0) {\n \
    \     auto [l, r] = range[uf[i]];\n      int p = (l == i ? l : r);\n      if (p\
    \ == len(dat)) return;\n      ll y = dat[p];\n      ll z = min(x, y);\n      dat[p]\
    \ -= z, x -= z, max -= z;\n      if (dat[p] == 0) {\n        merge(p);\n     \
    \   continue;\n      }\n    }\n  }\n\n  ll get_max() { return max; }\n};"
  dependsOn:
  - ds/unionfind/unionfind.hpp
  isVerificationFile: false
  path: ds/monotone/prefix_add_append_get_max.hpp
  requiredBy: []
  timestamp: '2024-11-14 21:00:22+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: ds/monotone/prefix_add_append_get_max.hpp
layout: document
redirect_from:
- /library/ds/monotone/prefix_add_append_get_max.hpp
- /library/ds/monotone/prefix_add_append_get_max.hpp.html
title: ds/monotone/prefix_add_append_get_max.hpp
---
