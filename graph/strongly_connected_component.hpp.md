---
data:
  _extendedDependsOn:
  - icon: ':question:'
    path: graph/base.hpp
    title: graph/base.hpp
  _extendedRequiredBy:
  - icon: ':heavy_check_mark:'
    path: graph/reachability.hpp
    title: graph/reachability.hpp
  - icon: ':x:'
    path: graph/twosat.hpp
    title: graph/twosat.hpp
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/aoj/275_dag_reachability.test.cpp
    title: test/aoj/275_dag_reachability.test.cpp
  - icon: ':x:'
    path: test/library_checker/graph/scc.test.cpp
    title: test/library_checker/graph/scc.test.cpp
  - icon: ':x:'
    path: test/library_checker/math/twosat.test.cpp
    title: test/library_checker/math/twosat.test.cpp
  - icon: ':x:'
    path: test/yukicoder/1170_range_to_range.test.cpp
    title: test/yukicoder/1170_range_to_range.test.cpp
  _isVerificationFailed: true
  _pathExtension: hpp
  _verificationStatusIcon: ':question:'
  attributes:
    links: []
  bundledCode: "#line 2 \"graph/base.hpp\"\n\ntemplate <typename T>\nstruct Edge {\n\
    \  int frm, to;\n  T cost;\n  int id;\n};\n\ntemplate <typename T = int, bool\
    \ directed = false>\nstruct Graph {\n  int N, M;\n  using cost_type = T;\n  using\
    \ edge_type = Edge<T>;\n  vector<edge_type> edges;\n  vector<int> indptr;\n  vector<edge_type>\
    \ csr_edges;\n  bool prepared;\n\n  class OutgoingEdges {\n  public:\n    OutgoingEdges(const\
    \ Graph* G, int l, int r) : G(G), l(l), r(r) {}\n\n    const edge_type* begin()\
    \ const {\n      if (l == r) { return 0; }\n      return &G->csr_edges[l];\n \
    \   }\n\n    const edge_type* end() const {\n      if (l == r) { return 0; }\n\
    \      return &G->csr_edges[r];\n    }\n\n  private:\n    int l, r;\n    const\
    \ Graph* G;\n  };\n\n  bool is_prepared() { return prepared; }\n  constexpr bool\
    \ is_directed() { return directed; }\n\n  Graph() : N(0), M(0), prepared(0) {}\n\
    \  Graph(int N) : N(N), M(0), prepared(0) {}\n\n  void add(int frm, int to, T\
    \ cost = 1, int i = -1) {\n    assert(!prepared);\n    assert(0 <= frm && 0 <=\
    \ to && to < N);\n    if (i == -1) i = M;\n    auto e = edge_type({frm, to, cost,\
    \ i});\n    edges.eb(e);\n    ++M;\n  }\n\n  // wt, off\n  void read_tree(bool\
    \ wt = false, int off = 1) { read_graph(N - 1, wt, off); }\n\n  void read_graph(int\
    \ M, bool wt = false, int off = 1) {\n    FOR(M) {\n      INT(a, b);\n      a\
    \ -= off, b -= off;\n      if (!wt) {\n        add(a, b);\n      } else {\n  \
    \      T c;\n        read(c);\n        add(a, b, c);\n      }\n    }\n    build();\n\
    \  }\n\n  void read_parent(int off = 1) {\n    FOR3(v, 1, N) {\n      INT(p);\n\
    \      p -= off;\n      add(p, v);\n    }\n    build();\n  }\n\n  void build()\
    \ {\n    assert(!prepared);\n    prepared = true;\n    indptr.assign(N + 1, 0);\n\
    \    for (auto&& e: edges) {\n      indptr[e.frm + 1]++;\n      if (!directed)\
    \ indptr[e.to + 1]++;\n    }\n    FOR(v, N) indptr[v + 1] += indptr[v];\n    auto\
    \ counter = indptr;\n    csr_edges.resize(indptr.back() + 1);\n    for (auto&&\
    \ e: edges) {\n      csr_edges[counter[e.frm]++] = e;\n      if (!directed)\n\
    \        csr_edges[counter[e.to]++] = edge_type({e.to, e.frm, e.cost, e.id});\n\
    \    }\n  }\n\n  OutgoingEdges operator[](int v) const {\n    assert(prepared);\n\
    \    return {this, indptr[v], indptr[v + 1]};\n  }\n\n  void debug() {\n    print(\"\
    Graph\");\n    if (!prepared) {\n      print(\"frm to cost id\");\n      for (auto&&\
    \ e: edges) print(e.frm, e.to, e.cost, e.id);\n    } else {\n      print(\"indptr\"\
    , indptr);\n      print(\"frm to cost id\");\n      FOR(v, N) for (auto&& e: (*this)[v])\
    \ print(e.frm, e.to, e.cost, e.id);\n    }\n  }\n};\n#line 3 \"graph/strongly_connected_component.hpp\"\
    \n\ntemplate <typename Graph>\npair<int, vc<int>> strongly_connected_component(Graph\
    \ &G) {\n  assert(G.is_directed());\n  assert(G.is_prepared());\n  int N = G.N;\n\
    \  int C = 0;\n  vc<int> comp(N);\n  vc<int> low(N);\n  vc<int> ord(N, -1);\n\
    \  vc<int> visited;\n  int now = 0;\n\n  auto dfs = [&](auto self, int v) -> void\
    \ {\n    low[v] = now;\n    ord[v] = now;\n    ++now;\n    visited.eb(v);\n  \
    \  for (auto &&[frm, to, cost, id]: G[v]) {\n      if (ord[to] == -1) {\n    \
    \    self(self, to);\n        chmin(low[v], low[to]);\n      } else {\n      \
    \  chmin(low[v], ord[to]);\n      }\n    }\n    if (low[v] == ord[v]) {\n    \
    \  while (1) {\n        int u = visited.back();\n        visited.pop_back();\n\
    \        ord[u] = N;\n        comp[u] = C;\n        if (u == v) break;\n     \
    \ }\n      ++C;\n    }\n  };\n  FOR(v, N) {\n    if (ord[v] == -1) dfs(dfs, v);\n\
    \  }\n  FOR(v, N) comp[v] = C - 1 - comp[v];\n  return {C, comp};\n}\n"
  code: "#pragma once\n#include \"graph/base.hpp\"\n\ntemplate <typename Graph>\n\
    pair<int, vc<int>> strongly_connected_component(Graph &G) {\n  assert(G.is_directed());\n\
    \  assert(G.is_prepared());\n  int N = G.N;\n  int C = 0;\n  vc<int> comp(N);\n\
    \  vc<int> low(N);\n  vc<int> ord(N, -1);\n  vc<int> visited;\n  int now = 0;\n\
    \n  auto dfs = [&](auto self, int v) -> void {\n    low[v] = now;\n    ord[v]\
    \ = now;\n    ++now;\n    visited.eb(v);\n    for (auto &&[frm, to, cost, id]:\
    \ G[v]) {\n      if (ord[to] == -1) {\n        self(self, to);\n        chmin(low[v],\
    \ low[to]);\n      } else {\n        chmin(low[v], ord[to]);\n      }\n    }\n\
    \    if (low[v] == ord[v]) {\n      while (1) {\n        int u = visited.back();\n\
    \        visited.pop_back();\n        ord[u] = N;\n        comp[u] = C;\n    \
    \    if (u == v) break;\n      }\n      ++C;\n    }\n  };\n  FOR(v, N) {\n   \
    \ if (ord[v] == -1) dfs(dfs, v);\n  }\n  FOR(v, N) comp[v] = C - 1 - comp[v];\n\
    \  return {C, comp};\n}\n"
  dependsOn:
  - graph/base.hpp
  isVerificationFile: false
  path: graph/strongly_connected_component.hpp
  requiredBy:
  - graph/reachability.hpp
  - graph/twosat.hpp
  timestamp: '2022-05-13 20:32:38+09:00'
  verificationStatus: LIBRARY_SOME_WA
  verifiedWith:
  - test/yukicoder/1170_range_to_range.test.cpp
  - test/library_checker/math/twosat.test.cpp
  - test/library_checker/graph/scc.test.cpp
  - test/aoj/275_dag_reachability.test.cpp
documentation_of: graph/strongly_connected_component.hpp
layout: document
redirect_from:
- /library/graph/strongly_connected_component.hpp
- /library/graph/strongly_connected_component.hpp.html
title: graph/strongly_connected_component.hpp
---
