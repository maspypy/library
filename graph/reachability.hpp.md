---
data:
  _extendedDependsOn:
  - icon: ':question:'
    path: graph/base.hpp
    title: graph/base.hpp
  - icon: ':x:'
    path: graph/strongly_connected_component.hpp
    title: graph/strongly_connected_component.hpp
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':x:'
    path: test/aoj/0275.test.cpp
    title: test/aoj/0275.test.cpp
  _isVerificationFailed: true
  _pathExtension: hpp
  _verificationStatusIcon: ':x:'
  attributes:
    links: []
  bundledCode: "#line 2 \"graph/base.hpp\"\n\ntemplate <typename T>\nstruct Edge {\n\
    \  int frm, to;\n  T cost;\n  int id;\n};\n\ntemplate <typename T = int, bool\
    \ directed = false>\nstruct Graph {\n  int N, M;\n  using cost_type = T;\n  using\
    \ edge_type = Edge<T>;\n  vector<edge_type> edges;\n  vector<int> indptr;\n  vector<edge_type>\
    \ csr_edges;\n  vc<int> vc_deg, vc_indeg, vc_outdeg;\n  bool prepared;\n\n  class\
    \ OutgoingEdges {\n  public:\n    OutgoingEdges(const Graph* G, int l, int r)\
    \ : G(G), l(l), r(r) {}\n\n    const edge_type* begin() const {\n      if (l ==\
    \ r) { return 0; }\n      return &G->csr_edges[l];\n    }\n\n    const edge_type*\
    \ end() const {\n      if (l == r) { return 0; }\n      return &G->csr_edges[r];\n\
    \    }\n\n  private:\n    const Graph* G;\n    int l, r;\n  };\n\n  bool is_prepared()\
    \ { return prepared; }\n  constexpr bool is_directed() { return directed; }\n\n\
    \  Graph() : N(0), M(0), prepared(0) {}\n  Graph(int N) : N(N), M(0), prepared(0)\
    \ {}\n\n  void resize(int n) { N = n; }\n\n  void add(int frm, int to, T cost\
    \ = 1, int i = -1) {\n    assert(!prepared);\n    assert(0 <= frm && 0 <= to &&\
    \ to < N);\n    if (i == -1) i = M;\n    auto e = edge_type({frm, to, cost, i});\n\
    \    edges.eb(e);\n    ++M;\n  }\n\n  // wt, off\n  void read_tree(bool wt = false,\
    \ int off = 1) { read_graph(N - 1, wt, off); }\n\n  void read_graph(int M, bool\
    \ wt = false, int off = 1) {\n    for (int m = 0; m < M; ++m) {\n      INT(a,\
    \ b);\n      a -= off, b -= off;\n      if (!wt) {\n        add(a, b);\n     \
    \ } else {\n        T c;\n        read(c);\n        add(a, b, c);\n      }\n \
    \   }\n    build();\n  }\n\n  void read_parent(int off = 1) {\n    for (int v\
    \ = 1; v < N; ++v) {\n      INT(p);\n      p -= off;\n      add(p, v);\n    }\n\
    \    build();\n  }\n\n  void build() {\n    assert(!prepared);\n    prepared =\
    \ true;\n    indptr.assign(N + 1, 0);\n    for (auto&& e: edges) {\n      indptr[e.frm\
    \ + 1]++;\n      if (!directed) indptr[e.to + 1]++;\n    }\n    for (int v = 0;\
    \ v < N; ++v) { indptr[v + 1] += indptr[v]; }\n    auto counter = indptr;\n  \
    \  csr_edges.resize(indptr.back() + 1);\n    for (auto&& e: edges) {\n      csr_edges[counter[e.frm]++]\
    \ = e;\n      if (!directed)\n        csr_edges[counter[e.to]++] = edge_type({e.to,\
    \ e.frm, e.cost, e.id});\n    }\n  }\n\n  OutgoingEdges operator[](int v) const\
    \ {\n    assert(prepared);\n    return {this, indptr[v], indptr[v + 1]};\n  }\n\
    \n  vc<int> deg_array() {\n    if (vc_deg.empty()) calc_deg();\n    return vc_deg;\n\
    \  }\n\n  pair<vc<int>, vc<int>> deg_array_inout() {\n    if (vc_indeg.empty())\
    \ calc_deg_inout();\n    return {vc_indeg, vc_outdeg};\n  }\n\n  int deg(int v)\
    \ {\n    if (vc_deg.empty()) calc_deg();\n    return vc_deg[v];\n  }\n\n  int\
    \ in_deg(int v) {\n    if (vc_indeg.empty()) calc_deg_inout();\n    return vc_indeg[v];\n\
    \  }\n\n  int out_deg(int v) {\n    if (vc_outdeg.empty()) calc_deg_inout();\n\
    \    return vc_outdeg[v];\n  }\n\n  void debug() {\n    print(\"Graph\");\n  \
    \  if (!prepared) {\n      print(\"frm to cost id\");\n      for (auto&& e: edges)\
    \ print(e.frm, e.to, e.cost, e.id);\n    } else {\n      print(\"indptr\", indptr);\n\
    \      print(\"frm to cost id\");\n      FOR(v, N) for (auto&& e: (*this)[v])\
    \ print(e.frm, e.to, e.cost, e.id);\n    }\n  }\n\nprivate:\n  void calc_deg()\
    \ {\n    assert(vc_deg.empty());\n    vc_deg.resize(N);\n    for (auto&& e: edges)\
    \ vc_deg[e.frm]++, vc_deg[e.to]++;\n  }\n\n  void calc_deg_inout() {\n    assert(vc_indeg.empty());\n\
    \    vc_indeg.resize(N);\n    vc_outdeg.resize(N);\n    for (auto&& e: edges)\
    \ { vc_indeg[e.to]++, vc_outdeg[e.frm]++; }\n  }\n};\n#line 3 \"graph/strongly_connected_component.hpp\"\
    \n\ntemplate <typename Graph>\npair<int, vc<int>> strongly_connected_component(Graph&\
    \ G) {\n  assert(G.is_directed());\n  assert(G.is_prepared());\n  int N = G.N;\n\
    \  int C = 0;\n  vc<int> comp(N);\n  vc<int> low(N);\n  vc<int> ord(N, -1);\n\
    \  vc<int> visited;\n  int now = 0;\n\n  auto dfs = [&](auto self, int v) -> void\
    \ {\n    low[v] = now;\n    ord[v] = now;\n    ++now;\n    visited.eb(v);\n  \
    \  for (auto&& [frm, to, cost, id]: G[v]) {\n      if (ord[to] == -1) {\n    \
    \    self(self, to);\n        chmin(low[v], low[to]);\n      } else {\n      \
    \  chmin(low[v], ord[to]);\n      }\n    }\n    if (low[v] == ord[v]) {\n    \
    \  while (1) {\n        int u = visited.back();\n        visited.pop_back();\n\
    \        ord[u] = N;\n        comp[u] = C;\n        if (u == v) break;\n     \
    \ }\n      ++C;\n    }\n  };\n  FOR(v, N) {\n    if (ord[v] == -1) dfs(dfs, v);\n\
    \  }\n  FOR(v, N) comp[v] = C - 1 - comp[v];\n  return {C, comp};\n}\n\ntemplate\
    \ <typename GT>\nGraph<int, 1> scc_dag(GT& G, int C, vc<int>& comp) {\n  Graph<int,\
    \ 1> DAG(C);\n  vvc<int> edges(C);\n  for (auto&& e: G.edges) {\n    int x = comp[e.frm],\
    \ y = comp[e.to];\n    if (x == y) continue;\n    edges[x].eb(y);\n  }\n  FOR(c,\
    \ C) {\n    UNIQUE(edges[c]);\n    for (auto&& to: edges[c]) DAG.add(c, to);\n\
    \  }\n  DAG.build();\n  return DAG;\n}\n#line 3 \"graph/reachability.hpp\"\n\n\
    // \u6709\u5411\u30B0\u30E9\u30D5\u306E\u5230\u9054\u53EF\u80FD\u6027\u30AF\u30A8\
    \u30EA\u3002O((N+M)Q/w)\u3002\ntemplate <typename GT, typename P>\nvc<int> reachability(GT&\
    \ G, vc<P> query) {\n  auto [C, comp] = strongly_connected_component(G);\n  Graph<int,\
    \ 1> DAG(C);\n  for (auto&& e: G.edges) {\n    auto a = comp[e.frm], b = comp[e.to];\n\
    \    assert(a <= b);\n    if (a < b) DAG.add(a, b);\n  }\n  DAG.build();\n\n \
    \ int Q = len(query);\n  vc<u64> dp(C);\n  vc<int> res(Q);\n  for (int l = 0;\
    \ l < Q; l += 64) {\n    int r = min(l + 64, Q);\n    fill(all(dp), u64(0));\n\
    \n    FOR3(qid, l, r) {\n      auto v = comp[query[qid].fi];\n      dp[v] |= u64(1)\
    \ << (qid - l);\n    }\n    FOR(v, C) for (auto&& e: DAG[v]) { dp[e.to] |= dp[v];\
    \ }\n    FOR3(qid, l, r) {\n      auto v = comp[query[qid].se];\n      if (dp[v]\
    \ & (u64(1) << (qid - l))) res[qid] = 1;\n    }\n  }\n  return res;\n}\n"
  code: "#pragma once\n#include \"graph/strongly_connected_component.hpp\"\n\n// \u6709\
    \u5411\u30B0\u30E9\u30D5\u306E\u5230\u9054\u53EF\u80FD\u6027\u30AF\u30A8\u30EA\
    \u3002O((N+M)Q/w)\u3002\ntemplate <typename GT, typename P>\nvc<int> reachability(GT&\
    \ G, vc<P> query) {\n  auto [C, comp] = strongly_connected_component(G);\n  Graph<int,\
    \ 1> DAG(C);\n  for (auto&& e: G.edges) {\n    auto a = comp[e.frm], b = comp[e.to];\n\
    \    assert(a <= b);\n    if (a < b) DAG.add(a, b);\n  }\n  DAG.build();\n\n \
    \ int Q = len(query);\n  vc<u64> dp(C);\n  vc<int> res(Q);\n  for (int l = 0;\
    \ l < Q; l += 64) {\n    int r = min(l + 64, Q);\n    fill(all(dp), u64(0));\n\
    \n    FOR3(qid, l, r) {\n      auto v = comp[query[qid].fi];\n      dp[v] |= u64(1)\
    \ << (qid - l);\n    }\n    FOR(v, C) for (auto&& e: DAG[v]) { dp[e.to] |= dp[v];\
    \ }\n    FOR3(qid, l, r) {\n      auto v = comp[query[qid].se];\n      if (dp[v]\
    \ & (u64(1) << (qid - l))) res[qid] = 1;\n    }\n  }\n  return res;\n}"
  dependsOn:
  - graph/strongly_connected_component.hpp
  - graph/base.hpp
  isVerificationFile: false
  path: graph/reachability.hpp
  requiredBy: []
  timestamp: '2022-08-30 02:42:36+09:00'
  verificationStatus: LIBRARY_ALL_WA
  verifiedWith:
  - test/aoj/0275.test.cpp
documentation_of: graph/reachability.hpp
layout: document
redirect_from:
- /library/graph/reachability.hpp
- /library/graph/reachability.hpp.html
title: graph/reachability.hpp
---
