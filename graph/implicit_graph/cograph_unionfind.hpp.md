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
    links: []
  bundledCode: "#line 2 \"ds/unionfind/unionfind.hpp\"\n\nstruct UnionFind {\n  int\
    \ n, n_comp;\n  vc<int> dat; // par or (-size)\n  UnionFind(int n = 0) { build(n);\
    \ }\n\n  void build(int m) {\n    n = m, n_comp = m;\n    dat.assign(n, -1);\n\
    \  }\n\n  void reset() { build(n); }\n\n  int operator[](int x) {\n    while (dat[x]\
    \ >= 0) {\n      int pp = dat[dat[x]];\n      if (pp < 0) { return dat[x]; }\n\
    \      x = dat[x] = pp;\n    }\n    return x;\n  }\n\n  ll size(int x) {\n   \
    \ assert(dat[x] < 0);\n    return -dat[x];\n  }\n\n  bool merge(int x, int y)\
    \ {\n    x = (*this)[x], y = (*this)[y];\n    if (x == y) return false;\n    if\
    \ (-dat[x] < -dat[y]) swap(x, y);\n    dat[x] += dat[y], dat[y] = x, n_comp--;\n\
    \    return true;\n  }\n};\n#line 2 \"graph/implicit_graph/cograph_unionfind.hpp\"\
    \n\ntemplate <typename GT>\nUnionFind cograph_unionfind(GT& G) {\n  const int\
    \ N = G.N;\n  UnionFind uf(N);\n  FastSet ss(N);\n  FOR(v, N) ss.insert(v);\n\n\
    \  vc<int> que;\n  FOR(v, N) {\n    if (!ss[v]) continue;\n    que.eb(v);\n  \
    \  while (len(que)) {\n      int a = POP(que);\n      vc<int> tmp;\n      for\
    \ (auto&& e: G[a]) {\n        if (ss[e.to]) tmp.eb(e.to);\n      }\n      for\
    \ (auto&& x: tmp) ss.erase(x);\n      ss.enumerate(0, N, [&](int to) -> void {\n\
    \        ss.erase(to);\n        que.eb(to);\n        uf.merge(a, to);\n      });\n\
    \      for (auto&& x: tmp) ss.insert(x);\n    }\n  }\n  return uf;\n}\n"
  code: "#include \"ds/unionfind/unionfind.hpp\"\n\ntemplate <typename GT>\nUnionFind\
    \ cograph_unionfind(GT& G) {\n  const int N = G.N;\n  UnionFind uf(N);\n  FastSet\
    \ ss(N);\n  FOR(v, N) ss.insert(v);\n\n  vc<int> que;\n  FOR(v, N) {\n    if (!ss[v])\
    \ continue;\n    que.eb(v);\n    while (len(que)) {\n      int a = POP(que);\n\
    \      vc<int> tmp;\n      for (auto&& e: G[a]) {\n        if (ss[e.to]) tmp.eb(e.to);\n\
    \      }\n      for (auto&& x: tmp) ss.erase(x);\n      ss.enumerate(0, N, [&](int\
    \ to) -> void {\n        ss.erase(to);\n        que.eb(to);\n        uf.merge(a,\
    \ to);\n      });\n      for (auto&& x: tmp) ss.insert(x);\n    }\n  }\n  return\
    \ uf;\n}"
  dependsOn:
  - ds/unionfind/unionfind.hpp
  isVerificationFile: false
  path: graph/implicit_graph/cograph_unionfind.hpp
  requiredBy: []
  timestamp: '2023-03-15 22:02:24+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: graph/implicit_graph/cograph_unionfind.hpp
layout: document
redirect_from:
- /library/graph/implicit_graph/cograph_unionfind.hpp
- /library/graph/implicit_graph/cograph_unionfind.hpp.html
title: graph/implicit_graph/cograph_unionfind.hpp
---
