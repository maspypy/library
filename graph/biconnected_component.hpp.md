---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: graph/base.hpp
    title: graph/base.hpp
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/aoj/GRO_3_A_articulation.test.cpp
    title: test/aoj/GRO_3_A_articulation.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/library_checker/graph/biconnected_component.test.cpp
    title: test/library_checker/graph/biconnected_component.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/yukicoder/1326_bct.test.cpp
    title: test/yukicoder/1326_bct.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
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
    \ {}\n\n  void add(int frm, int to, T cost = 1, int i = -1) {\n    assert(!prepared);\n\
    \    assert(0 <= frm && 0 <= to && to < N);\n    if (i == -1) i = M;\n    auto\
    \ e = edge_type({frm, to, cost, i});\n    edges.eb(e);\n    ++M;\n  }\n\n  //\
    \ wt, off\n  void read_tree(bool wt = false, int off = 1) { read_graph(N - 1,\
    \ wt, off); }\n\n  void read_graph(int M, bool wt = false, int off = 1) {\n  \
    \  for (int m = 0; m < M; ++m) {\n      INT(a, b);\n      a -= off, b -= off;\n\
    \      if (!wt) {\n        add(a, b);\n      } else {\n        T c;\n        read(c);\n\
    \        add(a, b, c);\n      }\n    }\n    build();\n  }\n\n  void read_parent(int\
    \ off = 1) {\n    for (int v = 1; v < N; ++v) {\n      INT(p);\n      p -= off;\n\
    \      add(p, v);\n    }\n    build();\n  }\n\n  void build() {\n    assert(!prepared);\n\
    \    prepared = true;\n    indptr.assign(N + 1, 0);\n    for (auto&& e: edges)\
    \ {\n      indptr[e.frm + 1]++;\n      if (!directed) indptr[e.to + 1]++;\n  \
    \  }\n    for (int v = 0; v < N; ++v) { indptr[v + 1] += indptr[v]; }\n    auto\
    \ counter = indptr;\n    csr_edges.resize(indptr.back() + 1);\n    for (auto&&\
    \ e: edges) {\n      csr_edges[counter[e.frm]++] = e;\n      if (!directed)\n\
    \        csr_edges[counter[e.to]++] = edge_type({e.to, e.frm, e.cost, e.id});\n\
    \    }\n  }\n\n  OutgoingEdges operator[](int v) const {\n    assert(prepared);\n\
    \    return {this, indptr[v], indptr[v + 1]};\n  }\n\n  vc<int> deg_array() {\n\
    \    if (vc_deg.empty()) calc_deg();\n    return vc_deg;\n  }\n\n  pair<vc<int>,\
    \ vc<int>> deg_array_inout() {\n    if (vc_indeg.empty()) calc_deg_inout();\n\
    \    return {vc_indeg, vc_outdeg};\n  }\n\n  int deg(int v) {\n    if (vc_deg.empty())\
    \ calc_deg();\n    return vc_deg[v];\n  }\n\n  int in_deg(int v) {\n    if (vc_indeg.empty())\
    \ calc_deg_inout();\n    return vc_indeg[v];\n  }\n\n  int out_deg(int v) {\n\
    \    if (vc_outdeg.empty()) calc_deg_inout();\n    return vc_outdeg[v];\n  }\n\
    \n  void debug() {\n    print(\"Graph\");\n    if (!prepared) {\n      print(\"\
    frm to cost id\");\n      for (auto&& e: edges) print(e.frm, e.to, e.cost, e.id);\n\
    \    } else {\n      print(\"indptr\", indptr);\n      print(\"frm to cost id\"\
    );\n      FOR(v, N) for (auto&& e: (*this)[v]) print(e.frm, e.to, e.cost, e.id);\n\
    \    }\n  }\n\nprivate:\n  void calc_deg() {\n    assert(vc_deg.empty());\n  \
    \  vc_deg.resize(N);\n    for (auto&& e: edges) vc_deg[e.frm]++, vc_deg[e.to]++;\n\
    \  }\n\n  void calc_deg_inout() {\n    assert(vc_indeg.empty());\n    vc_indeg.resize(N);\n\
    \    vc_outdeg.resize(N);\n    for (auto&& e: edges) { vc_indeg[e.to]++, vc_outdeg[e.frm]++;\
    \ }\n  }\n};\n#line 2 \"graph/biconnected_component.hpp\"\n\n/*\n\u5B64\u7ACB\u70B9\
    \u306F\u3001\u8FBA\u306E\u306A\u3044 component \u3067\u3001block \u306B\u306A\u308B\
    \u3002\u95A2\u7BC0\u70B9\u3067\u306F\u306A\u3044\u3002\nblock cut tree\u306E\u9802\
    \u70B9\u756A\u53F7\uFF1A\n[0, n_block)\uFF1Ablock\n[n_block, n_block + n_cut)\uFF1A\
    cut \uFF08\u95A2\u7BC0\u70B9\uFF09\n*/\ntemplate <typename GT>\nstruct Biconnected_Component\
    \ {\n  GT& G;\n  vc<pair<int, int>> BCT_edges;\n  int n_block, n_cut;\n  vc<vc<int>>\
    \ comp_e;\n  vc<vc<int>> comp_v; // block -> vs\n  vc<int> BCT_idx_edge;\n  vc<int>\
    \ BCT_idx_vertex;\n\n  Biconnected_Component(GT& G) : G(G) {\n    auto [ord, low]\
    \ = calculate_lowlink();\n    calculate_bcc(ord, low);\n    build_bct();\n  }\n\
    \n  int BCT_idx_v(int v) { return BCT_idx_vertex[v]; }\n  int BCT_idx_e(int eid)\
    \ { return BCT_idx_edge[eid]; }\n  Graph<int> BCT() {\n    Graph<int> bct(n_block\
    \ + n_cut);\n    for (auto&& [a, b]: BCT_edges) bct.add(a, b);\n    bct.build();\n\
    \    return bct;\n  }\n  bool is_articulation(int v) { return BCT_idx_v(v) >=\
    \ n_block; }\n\nprivate:\n  void build_bct() {\n    int n = G.N;\n    vvc<int>\
    \ nbd(n);\n    n_block = len(comp_e);\n    comp_v.resize(n_block);\n    n_cut\
    \ = 0;\n    BCT_idx_edge.resize(G.M);\n    BCT_idx_vertex.resize(G.N);\n\n   \
    \ auto add = [&](int v, int c) -> void {\n      if (len(nbd[v]) && nbd[v].back()\
    \ == c) return;\n      nbd[v].eb(c);\n    };\n\n    FOR(c, len(comp_e)) {\n  \
    \    for (auto&& eid: comp_e[c]) {\n        BCT_idx_edge[eid] = c;\n        auto&\
    \ e = G.edges[eid];\n        add(e.frm, c);\n        add(e.to, c);\n      }\n\
    \    }\n\n    FOR(v, n) {\n      if (len(nbd[v]) == 0) {\n        // \u5B64\u7ACB\
    \u70B9\u306F\u8FBA\u306E\u306A\u3044 block\n        BCT_idx_vertex[v] = n_block++;\n\
    \        comp_v.eb(vc<int>({int(v)}));\n      }\n      if (len(nbd[v]) >= 2) {\n\
    \        BCT_idx_vertex[v] = n_block + n_cut;\n        for (auto&& c: nbd[v])\
    \ {\n          BCT_edges.eb(n_block + n_cut, c);\n          comp_v[c].eb(v);\n\
    \        }\n        n_cut++;\n      }\n      elif (len(nbd[v]) == 1) {\n     \
    \   int c = nbd[v][0];\n        BCT_idx_vertex[v] = c;\n        comp_v[c].eb(v);\n\
    \      }\n    }\n\n    comp_e.resize(n_block);\n  }\n\n  pair<vc<int>, vc<int>>\
    \ calculate_lowlink() {\n    int n = G.N;\n    vc<bool> used(n);\n    vc<int>\
    \ low(n), ord(n);\n    int k = 0;\n    auto dfs = [&](auto self, int v, int eid)\
    \ -> void {\n      used[v] = 1;\n      low[v] = ord[v] = k++;\n      for (auto&&\
    \ e: G[v]) {\n        if (e.id == eid) continue;\n        if (!used[e.to]) {\n\
    \          self(self, e.to, e.id);\n          chmin(low[v], low[e.to]);\n    \
    \    } else {\n          chmin(low[v], ord[e.to]);\n        }\n      }\n    };\n\
    \    FOR(v, n) if (!used[v]) dfs(dfs, v, -1);\n    return {ord, low};\n  }\n\n\
    \  void calculate_bcc(vc<int>& ord, vc<int>& low) {\n    int n = G.N;\n    vc<bool>\
    \ used(n);\n    vc<int> buf;\n    auto dfs = [&](auto self, int v, int eid) ->\
    \ void {\n      used[v] = 1;\n      for (auto&& e: G[v]) {\n        if (e.id ==\
    \ eid) continue;\n        if (!used[e.to] || ord[e.to] < ord[v]) buf.eb(e.id);\n\
    \        if (used[e.to]) continue;\n        self(self, e.to, e.id);\n        if\
    \ (low[e.to] < ord[v]) continue;\n        vc<int> edges;\n        while (1) {\n\
    \          edges.eb(buf.back());\n          buf.pop_back();\n          if (edges.back()\
    \ == e.id) break;\n        }\n        comp_e.eb(edges);\n      }\n    };\n   \
    \ FOR(v, n) if (!used[v]) dfs(dfs, v, -1);\n  }\n};\n"
  code: "#include \"graph/base.hpp\"\n\n/*\n\u5B64\u7ACB\u70B9\u306F\u3001\u8FBA\u306E\
    \u306A\u3044 component \u3067\u3001block \u306B\u306A\u308B\u3002\u95A2\u7BC0\u70B9\
    \u3067\u306F\u306A\u3044\u3002\nblock cut tree\u306E\u9802\u70B9\u756A\u53F7\uFF1A\
    \n[0, n_block)\uFF1Ablock\n[n_block, n_block + n_cut)\uFF1Acut \uFF08\u95A2\u7BC0\
    \u70B9\uFF09\n*/\ntemplate <typename GT>\nstruct Biconnected_Component {\n  GT&\
    \ G;\n  vc<pair<int, int>> BCT_edges;\n  int n_block, n_cut;\n  vc<vc<int>> comp_e;\n\
    \  vc<vc<int>> comp_v; // block -> vs\n  vc<int> BCT_idx_edge;\n  vc<int> BCT_idx_vertex;\n\
    \n  Biconnected_Component(GT& G) : G(G) {\n    auto [ord, low] = calculate_lowlink();\n\
    \    calculate_bcc(ord, low);\n    build_bct();\n  }\n\n  int BCT_idx_v(int v)\
    \ { return BCT_idx_vertex[v]; }\n  int BCT_idx_e(int eid) { return BCT_idx_edge[eid];\
    \ }\n  Graph<int> BCT() {\n    Graph<int> bct(n_block + n_cut);\n    for (auto&&\
    \ [a, b]: BCT_edges) bct.add(a, b);\n    bct.build();\n    return bct;\n  }\n\
    \  bool is_articulation(int v) { return BCT_idx_v(v) >= n_block; }\n\nprivate:\n\
    \  void build_bct() {\n    int n = G.N;\n    vvc<int> nbd(n);\n    n_block = len(comp_e);\n\
    \    comp_v.resize(n_block);\n    n_cut = 0;\n    BCT_idx_edge.resize(G.M);\n\
    \    BCT_idx_vertex.resize(G.N);\n\n    auto add = [&](int v, int c) -> void {\n\
    \      if (len(nbd[v]) && nbd[v].back() == c) return;\n      nbd[v].eb(c);\n \
    \   };\n\n    FOR(c, len(comp_e)) {\n      for (auto&& eid: comp_e[c]) {\n   \
    \     BCT_idx_edge[eid] = c;\n        auto& e = G.edges[eid];\n        add(e.frm,\
    \ c);\n        add(e.to, c);\n      }\n    }\n\n    FOR(v, n) {\n      if (len(nbd[v])\
    \ == 0) {\n        // \u5B64\u7ACB\u70B9\u306F\u8FBA\u306E\u306A\u3044 block\n\
    \        BCT_idx_vertex[v] = n_block++;\n        comp_v.eb(vc<int>({int(v)}));\n\
    \      }\n      if (len(nbd[v]) >= 2) {\n        BCT_idx_vertex[v] = n_block +\
    \ n_cut;\n        for (auto&& c: nbd[v]) {\n          BCT_edges.eb(n_block + n_cut,\
    \ c);\n          comp_v[c].eb(v);\n        }\n        n_cut++;\n      }\n    \
    \  elif (len(nbd[v]) == 1) {\n        int c = nbd[v][0];\n        BCT_idx_vertex[v]\
    \ = c;\n        comp_v[c].eb(v);\n      }\n    }\n\n    comp_e.resize(n_block);\n\
    \  }\n\n  pair<vc<int>, vc<int>> calculate_lowlink() {\n    int n = G.N;\n   \
    \ vc<bool> used(n);\n    vc<int> low(n), ord(n);\n    int k = 0;\n    auto dfs\
    \ = [&](auto self, int v, int eid) -> void {\n      used[v] = 1;\n      low[v]\
    \ = ord[v] = k++;\n      for (auto&& e: G[v]) {\n        if (e.id == eid) continue;\n\
    \        if (!used[e.to]) {\n          self(self, e.to, e.id);\n          chmin(low[v],\
    \ low[e.to]);\n        } else {\n          chmin(low[v], ord[e.to]);\n       \
    \ }\n      }\n    };\n    FOR(v, n) if (!used[v]) dfs(dfs, v, -1);\n    return\
    \ {ord, low};\n  }\n\n  void calculate_bcc(vc<int>& ord, vc<int>& low) {\n   \
    \ int n = G.N;\n    vc<bool> used(n);\n    vc<int> buf;\n    auto dfs = [&](auto\
    \ self, int v, int eid) -> void {\n      used[v] = 1;\n      for (auto&& e: G[v])\
    \ {\n        if (e.id == eid) continue;\n        if (!used[e.to] || ord[e.to]\
    \ < ord[v]) buf.eb(e.id);\n        if (used[e.to]) continue;\n        self(self,\
    \ e.to, e.id);\n        if (low[e.to] < ord[v]) continue;\n        vc<int> edges;\n\
    \        while (1) {\n          edges.eb(buf.back());\n          buf.pop_back();\n\
    \          if (edges.back() == e.id) break;\n        }\n        comp_e.eb(edges);\n\
    \      }\n    };\n    FOR(v, n) if (!used[v]) dfs(dfs, v, -1);\n  }\n};\n"
  dependsOn:
  - graph/base.hpp
  isVerificationFile: false
  path: graph/biconnected_component.hpp
  requiredBy: []
  timestamp: '2022-08-29 21:19:08+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/yukicoder/1326_bct.test.cpp
  - test/library_checker/graph/biconnected_component.test.cpp
  - test/aoj/GRO_3_A_articulation.test.cpp
documentation_of: graph/biconnected_component.hpp
layout: document
redirect_from:
- /library/graph/biconnected_component.hpp
- /library/graph/biconnected_component.hpp.html
title: graph/biconnected_component.hpp
---
