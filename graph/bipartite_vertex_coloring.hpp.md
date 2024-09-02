---
data:
  _extendedDependsOn:
  - icon: ':question:'
    path: ds/unionfind/unionfind.hpp
    title: ds/unionfind/unionfind.hpp
  - icon: ':question:'
    path: graph/base.hpp
    title: graph/base.hpp
  _extendedRequiredBy:
  - icon: ':question:'
    path: flow/bipartite.hpp
    title: flow/bipartite.hpp
  - icon: ':heavy_check_mark:'
    path: flow/rank_maximal_bipartite_matching.hpp
    title: flow/rank_maximal_bipartite_matching.hpp
  - icon: ':heavy_check_mark:'
    path: graph/bipartite_edge_coloring.hpp
    title: graph/bipartite_edge_coloring.hpp
  - icon: ':question:'
    path: graph/maximum_antichain.hpp
    title: graph/maximum_antichain.hpp
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/1_mytest/find_odd_cycle.test.cpp
    title: test/1_mytest/find_odd_cycle.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/1_mytest/matching_ve.test.cpp
    title: test/1_mytest/matching_ve.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/1_mytest/tutte.test.cpp
    title: test/1_mytest/tutte.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/2_library_checker/graph/bipartite_edge_coloring.test.cpp
    title: test/2_library_checker/graph/bipartite_edge_coloring.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/2_library_checker/graph/bipartitematching.test.cpp
    title: test/2_library_checker/graph/bipartitematching.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/3_yukicoder/1479.test.cpp
    title: test/3_yukicoder/1479.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/3_yukicoder/1615.test.cpp
    title: test/3_yukicoder/1615.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/3_yukicoder/1744.test.cpp
    title: test/3_yukicoder/1744.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/3_yukicoder/1745.test.cpp
    title: test/3_yukicoder/1745.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/3_yukicoder/1911.test.cpp
    title: test/3_yukicoder/1911.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/4_aoj/1566.test.cpp
    title: test/4_aoj/1566.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/4_aoj/2251_2.test.cpp
    title: test/4_aoj/2251_2.test.cpp
  - icon: ':x:'
    path: test/5_atcoder/abc237ex.test.cpp
    title: test/5_atcoder/abc237ex.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/5_atcoder/abc274g.test.cpp
    title: test/5_atcoder/abc274g.test.cpp
  _isVerificationFailed: true
  _pathExtension: hpp
  _verificationStatusIcon: ':question:'
  attributes:
    links: []
  bundledCode: "#line 2 \"graph/bipartite_vertex_coloring.hpp\"\n\r\n#line 2 \"graph/base.hpp\"\
    \n\ntemplate <typename T>\nstruct Edge {\n  int frm, to;\n  T cost;\n  int id;\n\
    };\n\ntemplate <typename T = int, bool directed = false>\nstruct Graph {\n  static\
    \ constexpr bool is_directed = directed;\n  int N, M;\n  using cost_type = T;\n\
    \  using edge_type = Edge<T>;\n  vector<edge_type> edges;\n  vector<int> indptr;\n\
    \  vector<edge_type> csr_edges;\n  vc<int> vc_deg, vc_indeg, vc_outdeg;\n  bool\
    \ prepared;\n\n  class OutgoingEdges {\n  public:\n    OutgoingEdges(const Graph*\
    \ G, int l, int r) : G(G), l(l), r(r) {}\n\n    const edge_type* begin() const\
    \ {\n      if (l == r) { return 0; }\n      return &G->csr_edges[l];\n    }\n\n\
    \    const edge_type* end() const {\n      if (l == r) { return 0; }\n      return\
    \ &G->csr_edges[r];\n    }\n\n  private:\n    const Graph* G;\n    int l, r;\n\
    \  };\n\n  bool is_prepared() { return prepared; }\n\n  Graph() : N(0), M(0),\
    \ prepared(0) {}\n  Graph(int N) : N(N), M(0), prepared(0) {}\n\n  void build(int\
    \ n) {\n    N = n, M = 0;\n    prepared = 0;\n    edges.clear();\n    indptr.clear();\n\
    \    csr_edges.clear();\n    vc_deg.clear();\n    vc_indeg.clear();\n    vc_outdeg.clear();\n\
    \  }\n\n  void add(int frm, int to, T cost = 1, int i = -1) {\n    assert(!prepared);\n\
    \    assert(0 <= frm && 0 <= to && to < N);\n    if (i == -1) i = M;\n    auto\
    \ e = edge_type({frm, to, cost, i});\n    edges.eb(e);\n    ++M;\n  }\n\n#ifdef\
    \ FASTIO\n  // wt, off\n  void read_tree(bool wt = false, int off = 1) { read_graph(N\
    \ - 1, wt, off); }\n\n  void read_graph(int M, bool wt = false, int off = 1) {\n\
    \    for (int m = 0; m < M; ++m) {\n      INT(a, b);\n      a -= off, b -= off;\n\
    \      if (!wt) {\n        add(a, b);\n      } else {\n        T c;\n        read(c);\n\
    \        add(a, b, c);\n      }\n    }\n    build();\n  }\n#endif\n\n  void build()\
    \ {\n    assert(!prepared);\n    prepared = true;\n    indptr.assign(N + 1, 0);\n\
    \    for (auto&& e: edges) {\n      indptr[e.frm + 1]++;\n      if (!directed)\
    \ indptr[e.to + 1]++;\n    }\n    for (int v = 0; v < N; ++v) { indptr[v + 1]\
    \ += indptr[v]; }\n    auto counter = indptr;\n    csr_edges.resize(indptr.back()\
    \ + 1);\n    for (auto&& e: edges) {\n      csr_edges[counter[e.frm]++] = e;\n\
    \      if (!directed)\n        csr_edges[counter[e.to]++] = edge_type({e.to, e.frm,\
    \ e.cost, e.id});\n    }\n  }\n\n  OutgoingEdges operator[](int v) const {\n \
    \   assert(prepared);\n    return {this, indptr[v], indptr[v + 1]};\n  }\n\n \
    \ vc<int> deg_array() {\n    if (vc_deg.empty()) calc_deg();\n    return vc_deg;\n\
    \  }\n\n  pair<vc<int>, vc<int>> deg_array_inout() {\n    if (vc_indeg.empty())\
    \ calc_deg_inout();\n    return {vc_indeg, vc_outdeg};\n  }\n\n  int deg(int v)\
    \ {\n    if (vc_deg.empty()) calc_deg();\n    return vc_deg[v];\n  }\n\n  int\
    \ in_deg(int v) {\n    if (vc_indeg.empty()) calc_deg_inout();\n    return vc_indeg[v];\n\
    \  }\n\n  int out_deg(int v) {\n    if (vc_outdeg.empty()) calc_deg_inout();\n\
    \    return vc_outdeg[v];\n  }\n\n#ifdef FASTIO\n  void debug() {\n    print(\"\
    Graph\");\n    if (!prepared) {\n      print(\"frm to cost id\");\n      for (auto&&\
    \ e: edges) print(e.frm, e.to, e.cost, e.id);\n    } else {\n      print(\"indptr\"\
    , indptr);\n      print(\"frm to cost id\");\n      FOR(v, N) for (auto&& e: (*this)[v])\
    \ print(e.frm, e.to, e.cost, e.id);\n    }\n  }\n#endif\n\n  vc<int> new_idx;\n\
    \  vc<bool> used_e;\n\n  // G \u306B\u304A\u3051\u308B\u9802\u70B9 V[i] \u304C\
    \u3001\u65B0\u3057\u3044\u30B0\u30E9\u30D5\u3067 i \u306B\u306A\u308B\u3088\u3046\
    \u306B\u3059\u308B\n  // {G, es}\n  // sum(deg(v)) \u306E\u8A08\u7B97\u91CF\u306B\
    \u306A\u3063\u3066\u3044\u3066\u3001\n  // \u65B0\u3057\u3044\u30B0\u30E9\u30D5\
    \u306E n+m \u3088\u308A\u5927\u304D\u3044\u53EF\u80FD\u6027\u304C\u3042\u308B\u306E\
    \u3067\u6CE8\u610F\n  Graph<T, directed> rearrange(vc<int> V, bool keep_eid =\
    \ 0) {\n    if (len(new_idx) != N) new_idx.assign(N, -1);\n    int n = len(V);\n\
    \    FOR(i, n) new_idx[V[i]] = i;\n    Graph<T, directed> G(n);\n    vc<int> history;\n\
    \    FOR(i, n) {\n      for (auto&& e: (*this)[V[i]]) {\n        if (len(used_e)\
    \ <= e.id) used_e.resize(e.id + 1);\n        if (used_e[e.id]) continue;\n   \
    \     int a = e.frm, b = e.to;\n        if (new_idx[a] != -1 && new_idx[b] !=\
    \ -1) {\n          history.eb(e.id);\n          used_e[e.id] = 1;\n          int\
    \ eid = (keep_eid ? e.id : -1);\n          G.add(new_idx[a], new_idx[b], e.cost,\
    \ eid);\n        }\n      }\n    }\n    FOR(i, n) new_idx[V[i]] = -1;\n    for\
    \ (auto&& eid: history) used_e[eid] = 0;\n    G.build();\n    return G;\n  }\n\
    \n  Graph<T, true> to_directed_tree(int root = -1) {\n    if (root == -1) root\
    \ = 0;\n    assert(!is_directed && prepared && M == N - 1);\n    Graph<T, true>\
    \ G1(N);\n    vc<int> par(N, -1);\n    auto dfs = [&](auto& dfs, int v) -> void\
    \ {\n      for (auto& e: (*this)[v]) {\n        if (e.to == par[v]) continue;\n\
    \        par[e.to] = v, dfs(dfs, e.to);\n      }\n    };\n    dfs(dfs, root);\n\
    \    for (auto& e: edges) {\n      int a = e.frm, b = e.to;\n      if (par[a]\
    \ == b) swap(a, b);\n      assert(par[b] == a);\n      G1.add(a, b, e.cost);\n\
    \    }\n    G1.build();\n    return G1;\n  }\n\nprivate:\n  void calc_deg() {\n\
    \    assert(vc_deg.empty());\n    vc_deg.resize(N);\n    for (auto&& e: edges)\
    \ vc_deg[e.frm]++, vc_deg[e.to]++;\n  }\n\n  void calc_deg_inout() {\n    assert(vc_indeg.empty());\n\
    \    vc_indeg.resize(N);\n    vc_outdeg.resize(N);\n    for (auto&& e: edges)\
    \ { vc_indeg[e.to]++, vc_outdeg[e.frm]++; }\n  }\n};\n#line 2 \"ds/unionfind/unionfind.hpp\"\
    \n\nstruct UnionFind {\n  int n, n_comp;\n  vc<int> dat; // par or (-size)\n \
    \ UnionFind(int n = 0) { build(n); }\n\n  void build(int m) {\n    n = m, n_comp\
    \ = m;\n    dat.assign(n, -1);\n  }\n\n  void reset() { build(n); }\n\n  int operator[](int\
    \ x) {\n    while (dat[x] >= 0) {\n      int pp = dat[dat[x]];\n      if (pp <\
    \ 0) { return dat[x]; }\n      x = dat[x] = pp;\n    }\n    return x;\n  }\n\n\
    \  ll size(int x) {\n    x = (*this)[x];\n    return -dat[x];\n  }\n\n  bool merge(int\
    \ x, int y) {\n    x = (*this)[x], y = (*this)[y];\n    if (x == y) return false;\n\
    \    if (-dat[x] < -dat[y]) swap(x, y);\n    dat[x] += dat[y], dat[y] = x, n_comp--;\n\
    \    return true;\n  }\n\n  vc<int> get_all() {\n    vc<int> A(n);\n    FOR(i,\
    \ n) A[i] = (*this)[i];\n    return A;\n  }\n};\n#line 5 \"graph/bipartite_vertex_coloring.hpp\"\
    \n\r\n// \u4E8C\u90E8\u30B0\u30E9\u30D5\u3067\u306A\u304B\u3063\u305F\u5834\u5408\
    \u306B\u306F empty\r\ntemplate <typename GT>\r\nvc<int> bipartite_vertex_coloring(GT&\
    \ G) {\r\n  assert(!GT::is_directed);\r\n  assert(G.is_prepared());\r\n\r\n  int\
    \ n = G.N;\r\n  UnionFind uf(2 * n);\r\n  for (auto&& e: G.edges) {\r\n    int\
    \ u = e.frm, v = e.to;\r\n    uf.merge(u + n, v), uf.merge(u, v + n);\r\n  }\r\
    \n\r\n  vc<int> color(2 * n, -1);\r\n  FOR(v, n) if (uf[v] == v && color[uf[v]]\
    \ < 0) {\r\n    color[uf[v]] = 0;\r\n    color[uf[v + n]] = 1;\r\n  }\r\n  FOR(v,\
    \ n) color[v] = color[uf[v]];\r\n  color.resize(n);\r\n  FOR(v, n) if (uf[v] ==\
    \ uf[v + n]) return {};\r\n  return color;\r\n}\r\n"
  code: "#pragma once\r\n\r\n#include \"graph/base.hpp\"\r\n#include \"ds/unionfind/unionfind.hpp\"\
    \r\n\r\n// \u4E8C\u90E8\u30B0\u30E9\u30D5\u3067\u306A\u304B\u3063\u305F\u5834\u5408\
    \u306B\u306F empty\r\ntemplate <typename GT>\r\nvc<int> bipartite_vertex_coloring(GT&\
    \ G) {\r\n  assert(!GT::is_directed);\r\n  assert(G.is_prepared());\r\n\r\n  int\
    \ n = G.N;\r\n  UnionFind uf(2 * n);\r\n  for (auto&& e: G.edges) {\r\n    int\
    \ u = e.frm, v = e.to;\r\n    uf.merge(u + n, v), uf.merge(u, v + n);\r\n  }\r\
    \n\r\n  vc<int> color(2 * n, -1);\r\n  FOR(v, n) if (uf[v] == v && color[uf[v]]\
    \ < 0) {\r\n    color[uf[v]] = 0;\r\n    color[uf[v + n]] = 1;\r\n  }\r\n  FOR(v,\
    \ n) color[v] = color[uf[v]];\r\n  color.resize(n);\r\n  FOR(v, n) if (uf[v] ==\
    \ uf[v + n]) return {};\r\n  return color;\r\n}\r\n"
  dependsOn:
  - graph/base.hpp
  - ds/unionfind/unionfind.hpp
  isVerificationFile: false
  path: graph/bipartite_vertex_coloring.hpp
  requiredBy:
  - graph/maximum_antichain.hpp
  - graph/bipartite_edge_coloring.hpp
  - flow/rank_maximal_bipartite_matching.hpp
  - flow/bipartite.hpp
  timestamp: '2024-05-29 22:32:29+09:00'
  verificationStatus: LIBRARY_SOME_WA
  verifiedWith:
  - test/5_atcoder/abc274g.test.cpp
  - test/5_atcoder/abc237ex.test.cpp
  - test/3_yukicoder/1911.test.cpp
  - test/3_yukicoder/1744.test.cpp
  - test/3_yukicoder/1479.test.cpp
  - test/3_yukicoder/1745.test.cpp
  - test/3_yukicoder/1615.test.cpp
  - test/2_library_checker/graph/bipartitematching.test.cpp
  - test/2_library_checker/graph/bipartite_edge_coloring.test.cpp
  - test/1_mytest/matching_ve.test.cpp
  - test/1_mytest/tutte.test.cpp
  - test/1_mytest/find_odd_cycle.test.cpp
  - test/4_aoj/1566.test.cpp
  - test/4_aoj/2251_2.test.cpp
documentation_of: graph/bipartite_vertex_coloring.hpp
layout: document
redirect_from:
- /library/graph/bipartite_vertex_coloring.hpp
- /library/graph/bipartite_vertex_coloring.hpp.html
title: graph/bipartite_vertex_coloring.hpp
---
