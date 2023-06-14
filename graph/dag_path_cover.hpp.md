---
data:
  _extendedDependsOn:
  - icon: ':question:'
    path: ds/unionfind/unionfind.hpp
    title: ds/unionfind/unionfind.hpp
  - icon: ':heavy_check_mark:'
    path: flow/maxflow.hpp
    title: flow/maxflow.hpp
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/aoj/2251_1.test.cpp
    title: test/aoj/2251_1.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 1 \"flow/maxflow.hpp\"\ntemplate <typename Cap>\nstruct MaxFlowGraph\
    \ {\n  struct Edge {\n    int to, rev;\n    Cap cap;\n    Cap flow = 0;\n  };\n\
    \n  int N;\n  vc<tuple<int, int, Cap, Cap>> dat;\n  vc<int> prog, level;\n  vc<int>\
    \ que;\n  vc<Edge> edges;\n  vc<int> indptr;\n  Cap flow_ans;\n  bool calculated;\n\
    \  bool is_prepared;\n\n  MaxFlowGraph(int N) : N(N), calculated(0), is_prepared(0)\
    \ {}\n\n  void add(int frm, int to, Cap cap, Cap rev_cap = 0) {\n    assert(0\
    \ <= frm && frm < N);\n    assert(0 <= to && to < N);\n    assert(Cap(0) <= cap);\n\
    \    if (frm == to) return;\n    dat.eb(frm, to, cap, rev_cap);\n  }\n\n  void\
    \ build() {\n    assert(!is_prepared);\n    int M = len(dat);\n    is_prepared\
    \ = 1;\n    indptr.assign(N, 0);\n    for (auto&& [a, b, c, d]: dat) indptr[a]++,\
    \ indptr[b]++;\n    indptr = cumsum<int>(indptr);\n    vc<int> nxt_idx = indptr;\n\
    \    edges.resize(2 * M);\n    for (auto&& [a, b, c, d]: dat) {\n      int p =\
    \ nxt_idx[a]++;\n      int q = nxt_idx[b]++;\n      edges[p] = Edge{b, q, c};\n\
    \      edges[q] = Edge{a, p, d};\n    }\n  }\n\n  vc<tuple<int, int, Cap>> get_flow_edges()\
    \ {\n    vc<tuple<int, int, Cap>> res;\n    FOR(frm, N) {\n      FOR(k, indptr[frm],\
    \ indptr[frm + 1]) {\n        auto& e = edges[k];\n        if (e.flow <= 0) continue;\n\
    \        res.eb(frm, e.to, e.flow);\n      }\n    }\n    return res;\n  }\n\n\
    \  Cap flow(int source, int sink) {\n    assert(is_prepared);\n    if (calculated)\
    \ return flow_ans;\n    calculated = true;\n    flow_ans = 0;\n    while (set_level(source,\
    \ sink)) {\n      prog = indptr;\n      while (1) {\n        Cap x = flow_dfs(source,\
    \ sink, infty<Cap>);\n        if (x == 0) break;\n        flow_ans += x;\n   \
    \     chmin(flow_ans, infty<Cap>);\n        if (flow_ans == infty<Cap>) return\
    \ flow_ans;\n      }\n    }\n    return flow_ans;\n  }\n\n  // \u6700\u5C0F\u30AB\
    \u30C3\u30C8\u306E\u5024\u304A\u3088\u3073\u3001\u30AB\u30C3\u30C8\u3092\u8868\
    \u3059 01 \u5217\u3092\u8FD4\u3059\n  pair<Cap, vc<int>> cut(int source, int sink)\
    \ {\n    Cap f = flow(source, sink);\n    vc<int> res(N);\n    FOR(v, N) res[v]\
    \ = (level[v] >= 0 ? 0 : 1);\n    return {f, res};\n  }\n\nprivate:\n  bool set_level(int\
    \ source, int sink) {\n    que.resize(N);\n    level.assign(N, -1);\n    level[source]\
    \ = 0;\n    int l = 0, r = 0;\n    que[r++] = source;\n    while (l < r) {\n \
    \     int v = que[l++];\n      FOR(k, indptr[v], indptr[v + 1]) {\n        auto&\
    \ e = edges[k];\n        if (e.cap > 0 && level[e.to] == -1) {\n          level[e.to]\
    \ = level[v] + 1;\n          if (e.to == sink) return true;\n          que[r++]\
    \ = e.to;\n        }\n      }\n    }\n    return false;\n  }\n\n  Cap flow_dfs(int\
    \ v, int sink, Cap lim) {\n    if (v == sink) return lim;\n    Cap res = 0;\n\
    \    for (int& i = prog[v]; i < indptr[v + 1]; ++i) {\n      auto& e = edges[i];\n\
    \      if (e.cap > 0 && level[e.to] == level[v] + 1) {\n        Cap a = flow_dfs(e.to,\
    \ sink, min(lim, e.cap));\n        if (a > 0) {\n          e.cap -= a, e.flow\
    \ += a;\n          edges[e.rev].cap += a, edges[e.rev].flow -= a;\n          res\
    \ += a;\n          lim -= a;\n          if (lim == 0) break;\n        }\n    \
    \  }\n    }\n    return res;\n  }\n};\n#line 2 \"ds/unionfind/unionfind.hpp\"\n\
    \nstruct UnionFind {\n  int n, n_comp;\n  vc<int> dat; // par or (-size)\n  UnionFind(int\
    \ n = 0) { build(n); }\n\n  void build(int m) {\n    n = m, n_comp = m;\n    dat.assign(n,\
    \ -1);\n  }\n\n  void reset() { build(n); }\n\n  int operator[](int x) {\n   \
    \ while (dat[x] >= 0) {\n      int pp = dat[dat[x]];\n      if (pp < 0) { return\
    \ dat[x]; }\n      x = dat[x] = pp;\n    }\n    return x;\n  }\n\n  ll size(int\
    \ x) {\n    x = (*this)[x];\n    return -dat[x];\n  }\n\n  bool merge(int x, int\
    \ y) {\n    x = (*this)[x], y = (*this)[y];\n    if (x == y) return false;\n \
    \   if (-dat[x] < -dat[y]) swap(x, y);\n    dat[x] += dat[y], dat[y] = x, n_comp--;\n\
    \    return true;\n  }\n};\n#line 3 \"graph/dag_path_cover.hpp\"\n\n// \u5404\u9802\
    \u70B9\u306E\u8272\u3092\u304B\u3048\u3059\u3002\u5404\u8272\u306F\u3072\u3068\
    \u3064\u306E\u30D1\u30B9\u4E0A\u306B\u3042\u308B\u3088\u3046\u306B\u3059\u308B\
    \ntemplate <typename DAG>\nvc<int> dag_path_cover(DAG& G) {\n  assert(G.is_directed());\n\
    \  for (auto&& e: G.edges) assert(e.frm < e.to);\n\n  int N = G.N;\n  MaxFlowGraph<int>\
    \ F(2 * N + 2);\n  int source = 2 * N, sink = 2 * N + 1;\n  FOR(v, N) {\n    F.add(source,\
    \ 2 * v + 1, 1);\n    F.add(2 * v + 0, sink, 1);\n    F.add(2 * v + 0, 2 * v +\
    \ 1, infty<int>);\n  }\n  for (auto&& e: G.edges) F.add(2 * e.frm + 1, 2 * e.to\
    \ + 0, infty<int>);\n  F.build();\n\n  int flow = F.flow(source, sink);\n\n  vvc<pair<int,\
    \ int>> flow_edges(N + N + 2);\n  for (auto&& [a, b, c]: F.get_flow_edges()) {\
    \ flow_edges[a].eb(b, c); }\n\n  UnionFind uf(N);\n  for (auto&& [a, f]: flow_edges[source])\
    \ {\n    assert(f == 1);\n    int b = a;\n    while (1) {\n      auto [to, x]\
    \ = POP(flow_edges[b]);\n      x -= 1;\n      if (x > 0) flow_edges[b].eb(to,\
    \ x);\n      if (to == sink) break;\n      b = to;\n    }\n    uf.merge(a / 2,\
    \ b / 2);\n  }\n\n  vc<int> ANS(N, -1);\n  int p = 0;\n  FOR(v, N) if (uf[v] ==\
    \ v) ANS[v] = p++;\n  FOR(v, N) if (uf[v] != v) ANS[v] = ANS[uf[v]];\n  return\
    \ ANS;\n};\n"
  code: "#include \"flow/maxflow.hpp\"\n#include \"ds/unionfind/unionfind.hpp\"\n\n\
    // \u5404\u9802\u70B9\u306E\u8272\u3092\u304B\u3048\u3059\u3002\u5404\u8272\u306F\
    \u3072\u3068\u3064\u306E\u30D1\u30B9\u4E0A\u306B\u3042\u308B\u3088\u3046\u306B\
    \u3059\u308B\ntemplate <typename DAG>\nvc<int> dag_path_cover(DAG& G) {\n  assert(G.is_directed());\n\
    \  for (auto&& e: G.edges) assert(e.frm < e.to);\n\n  int N = G.N;\n  MaxFlowGraph<int>\
    \ F(2 * N + 2);\n  int source = 2 * N, sink = 2 * N + 1;\n  FOR(v, N) {\n    F.add(source,\
    \ 2 * v + 1, 1);\n    F.add(2 * v + 0, sink, 1);\n    F.add(2 * v + 0, 2 * v +\
    \ 1, infty<int>);\n  }\n  for (auto&& e: G.edges) F.add(2 * e.frm + 1, 2 * e.to\
    \ + 0, infty<int>);\n  F.build();\n\n  int flow = F.flow(source, sink);\n\n  vvc<pair<int,\
    \ int>> flow_edges(N + N + 2);\n  for (auto&& [a, b, c]: F.get_flow_edges()) {\
    \ flow_edges[a].eb(b, c); }\n\n  UnionFind uf(N);\n  for (auto&& [a, f]: flow_edges[source])\
    \ {\n    assert(f == 1);\n    int b = a;\n    while (1) {\n      auto [to, x]\
    \ = POP(flow_edges[b]);\n      x -= 1;\n      if (x > 0) flow_edges[b].eb(to,\
    \ x);\n      if (to == sink) break;\n      b = to;\n    }\n    uf.merge(a / 2,\
    \ b / 2);\n  }\n\n  vc<int> ANS(N, -1);\n  int p = 0;\n  FOR(v, N) if (uf[v] ==\
    \ v) ANS[v] = p++;\n  FOR(v, N) if (uf[v] != v) ANS[v] = ANS[uf[v]];\n  return\
    \ ANS;\n};"
  dependsOn:
  - flow/maxflow.hpp
  - ds/unionfind/unionfind.hpp
  isVerificationFile: false
  path: graph/dag_path_cover.hpp
  requiredBy: []
  timestamp: '2023-06-11 17:06:39+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/aoj/2251_1.test.cpp
documentation_of: graph/dag_path_cover.hpp
layout: document
redirect_from:
- /library/graph/dag_path_cover.hpp
- /library/graph/dag_path_cover.hpp.html
title: graph/dag_path_cover.hpp
---
