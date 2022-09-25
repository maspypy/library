---
data:
  _extendedDependsOn:
  - icon: ':question:'
    path: graph/base.hpp
    title: graph/base.hpp
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/yukicoder/1170.test.cpp
    title: test/yukicoder/1170.test.cpp
  - icon: ':x:'
    path: test/yukicoder/1868.test.cpp
    title: test/yukicoder/1868.test.cpp
  _isVerificationFailed: true
  _pathExtension: hpp
  _verificationStatusIcon: ':question:'
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
    \ { vc_indeg[e.to]++, vc_outdeg[e.frm]++; }\n  }\n};\n#line 3 \"graph/range_to_range_graph.hpp\"\
    \n\ntemplate <typename T>\nstruct Range_to_Range_Graph {\n  int n;\n  int n_node;\n\
    \  vc<tuple<int, int, T>> edges;\n\n  Range_to_Range_Graph(int n) : n(n), n_node(n\
    \ * 3) {\n    FOR3(i, 2, n + n) { edges.eb(to_upper_idx(i / 2), to_upper_idx(i),\
    \ 0); }\n    FOR3(i, 2, n + n) { edges.eb(to_lower_idx(i), to_lower_idx(i / 2),\
    \ 0); }\n  }\n\n  inline int to_upper_idx(const int& i) {\n    if (i >= n) return\
    \ i - n;\n    return n + i;\n  }\n\n  inline int to_lower_idx(const int& i) {\n\
    \    if (i >= n) return i - n;\n    return n + n + i;\n  }\n\n  void add(int frm,\
    \ int to, T wt) { edges.eb(frm, to, wt); }\n\n  void add_frm_range(int frm_l,\
    \ int frm_r, int to, T wt) {\n    int l = frm_l + n, r = frm_r + n;\n    while\
    \ (l < r) {\n      if (l & 1) add(to_lower_idx(l++), to, wt);\n      if (r & 1)\
    \ add(to_lower_idx(--r), to, wt);\n      l >>= 1, r >>= 1;\n    }\n  }\n\n  void\
    \ add_to_range(int frm, int to_l, int to_r, T wt) {\n    int l = to_l + n, r =\
    \ to_r + n;\n    while (l < r) {\n      if (l & 1) add(frm, to_upper_idx(l++),\
    \ wt);\n      if (r & 1) add(frm, to_upper_idx(--r), wt);\n      l >>= 1, r >>=\
    \ 1;\n    }\n  }\n\n  void add_range_to_range(int frm_l, int frm_r, int to_l,\
    \ int to_r, T wt) {\n    int new_node = n_node++;\n    add_frm_range(frm_l, frm_r,\
    \ new_node, wt);\n    add_to_range(new_node, to_l, to_r, T(0));\n  }\n\n  Graph<T,\
    \ 1> build() {\n    Graph<T, 1> G(n_node);\n    for (auto&& [a, b, c]: edges)\
    \ G.add(a, b, c);\n    G.build();\n    return G;\n  }\n};\n"
  code: "#pragma once\n#include \"graph/base.hpp\"\n\ntemplate <typename T>\nstruct\
    \ Range_to_Range_Graph {\n  int n;\n  int n_node;\n  vc<tuple<int, int, T>> edges;\n\
    \n  Range_to_Range_Graph(int n) : n(n), n_node(n * 3) {\n    FOR3(i, 2, n + n)\
    \ { edges.eb(to_upper_idx(i / 2), to_upper_idx(i), 0); }\n    FOR3(i, 2, n + n)\
    \ { edges.eb(to_lower_idx(i), to_lower_idx(i / 2), 0); }\n  }\n\n  inline int\
    \ to_upper_idx(const int& i) {\n    if (i >= n) return i - n;\n    return n +\
    \ i;\n  }\n\n  inline int to_lower_idx(const int& i) {\n    if (i >= n) return\
    \ i - n;\n    return n + n + i;\n  }\n\n  void add(int frm, int to, T wt) { edges.eb(frm,\
    \ to, wt); }\n\n  void add_frm_range(int frm_l, int frm_r, int to, T wt) {\n \
    \   int l = frm_l + n, r = frm_r + n;\n    while (l < r) {\n      if (l & 1) add(to_lower_idx(l++),\
    \ to, wt);\n      if (r & 1) add(to_lower_idx(--r), to, wt);\n      l >>= 1, r\
    \ >>= 1;\n    }\n  }\n\n  void add_to_range(int frm, int to_l, int to_r, T wt)\
    \ {\n    int l = to_l + n, r = to_r + n;\n    while (l < r) {\n      if (l & 1)\
    \ add(frm, to_upper_idx(l++), wt);\n      if (r & 1) add(frm, to_upper_idx(--r),\
    \ wt);\n      l >>= 1, r >>= 1;\n    }\n  }\n\n  void add_range_to_range(int frm_l,\
    \ int frm_r, int to_l, int to_r, T wt) {\n    int new_node = n_node++;\n    add_frm_range(frm_l,\
    \ frm_r, new_node, wt);\n    add_to_range(new_node, to_l, to_r, T(0));\n  }\n\n\
    \  Graph<T, 1> build() {\n    Graph<T, 1> G(n_node);\n    for (auto&& [a, b, c]:\
    \ edges) G.add(a, b, c);\n    G.build();\n    return G;\n  }\n};"
  dependsOn:
  - graph/base.hpp
  isVerificationFile: false
  path: graph/range_to_range_graph.hpp
  requiredBy: []
  timestamp: '2022-08-30 02:42:36+09:00'
  verificationStatus: LIBRARY_SOME_WA
  verifiedWith:
  - test/yukicoder/1170.test.cpp
  - test/yukicoder/1868.test.cpp
documentation_of: graph/range_to_range_graph.hpp
layout: document
redirect_from:
- /library/graph/range_to_range_graph.hpp
- /library/graph/range_to_range_graph.hpp.html
title: graph/range_to_range_graph.hpp
---
