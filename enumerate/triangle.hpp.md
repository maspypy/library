---
data:
  _extendedDependsOn:
  - icon: ':question:'
    path: graph/base.hpp
    title: graph/base.hpp
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/2_library_checker/graph/enumerate_triangles.test.cpp
    title: test/2_library_checker/graph/enumerate_triangles.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 2 \"graph/base.hpp\"\n\ntemplate <typename T>\nstruct Edge {\n\
    \  int frm, to;\n  T cost;\n  int id;\n};\n\ntemplate <typename T = int, bool\
    \ directed = false>\nstruct Graph {\n  static constexpr bool is_directed = directed;\n\
    \  int N, M;\n  using cost_type = T;\n  using edge_type = Edge<T>;\n  vector<edge_type>\
    \ edges;\n  vector<int> indptr;\n  vector<edge_type> csr_edges;\n  vc<int> vc_deg,\
    \ vc_indeg, vc_outdeg;\n  bool prepared;\n\n  class OutgoingEdges {\n  public:\n\
    \    OutgoingEdges(const Graph* G, int l, int r) : G(G), l(l), r(r) {}\n\n   \
    \ const edge_type* begin() const {\n      if (l == r) { return 0; }\n      return\
    \ &G->csr_edges[l];\n    }\n\n    const edge_type* end() const {\n      if (l\
    \ == r) { return 0; }\n      return &G->csr_edges[r];\n    }\n\n  private:\n \
    \   const Graph* G;\n    int l, r;\n  };\n\n  bool is_prepared() { return prepared;\
    \ }\n\n  Graph() : N(0), M(0), prepared(0) {}\n  Graph(int N) : N(N), M(0), prepared(0)\
    \ {}\n\n  void build(int n) {\n    N = n, M = 0;\n    prepared = 0;\n    edges.clear();\n\
    \    indptr.clear();\n    csr_edges.clear();\n    vc_deg.clear();\n    vc_indeg.clear();\n\
    \    vc_outdeg.clear();\n  }\n\n  void add(int frm, int to, T cost = 1, int i\
    \ = -1) {\n    assert(!prepared);\n    assert(0 <= frm && 0 <= to && to < N);\n\
    \    if (i == -1) i = M;\n    auto e = edge_type({frm, to, cost, i});\n    edges.eb(e);\n\
    \    ++M;\n  }\n\n#ifdef FASTIO\n  // wt, off\n  void read_tree(bool wt = false,\
    \ int off = 1) { read_graph(N - 1, wt, off); }\n\n  void read_graph(int M, bool\
    \ wt = false, int off = 1) {\n    for (int m = 0; m < M; ++m) {\n      INT(a,\
    \ b);\n      a -= off, b -= off;\n      if (!wt) {\n        add(a, b);\n     \
    \ } else {\n        T c;\n        read(c);\n        add(a, b, c);\n      }\n \
    \   }\n    build();\n  }\n#endif\n\n  void build() {\n    assert(!prepared);\n\
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
    \n#ifdef FASTIO\n  void debug() {\n    print(\"Graph\");\n    if (!prepared) {\n\
    \      print(\"frm to cost id\");\n      for (auto&& e: edges) print(e.frm, e.to,\
    \ e.cost, e.id);\n    } else {\n      print(\"indptr\", indptr);\n      print(\"\
    frm to cost id\");\n      FOR(v, N) for (auto&& e: (*this)[v]) print(e.frm, e.to,\
    \ e.cost, e.id);\n    }\n  }\n#endif\n\n  vc<int> new_idx;\n  vc<bool> used_e;\n\
    \n  // G \u306B\u304A\u3051\u308B\u9802\u70B9 V[i] \u304C\u3001\u65B0\u3057\u3044\
    \u30B0\u30E9\u30D5\u3067 i \u306B\u306A\u308B\u3088\u3046\u306B\u3059\u308B\n\
    \  // {G, es}\n  // sum(deg(v)) \u306E\u8A08\u7B97\u91CF\u306B\u306A\u3063\u3066\
    \u3044\u3066\u3001\n  // \u65B0\u3057\u3044\u30B0\u30E9\u30D5\u306E n+m \u3088\
    \u308A\u5927\u304D\u3044\u53EF\u80FD\u6027\u304C\u3042\u308B\u306E\u3067\u6CE8\
    \u610F\n  Graph<T, directed> rearrange(vc<int> V, bool keep_eid = 0) {\n    if\
    \ (len(new_idx) != N) new_idx.assign(N, -1);\n    int n = len(V);\n    FOR(i,\
    \ n) new_idx[V[i]] = i;\n    Graph<T, directed> G(n);\n    vc<int> history;\n\
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
    \ { vc_indeg[e.to]++, vc_outdeg[e.frm]++; }\n  }\n};\n#line 2 \"enumerate/triangle.hpp\"\
    \n\r\ntemplate <typename Gr, typename F>\r\nvoid enumerate_triangle(Gr& G, F query)\
    \ {\r\n  int N = G.N;\r\n  Graph<int, 1> H(N);\r\n  set<pair<int, int>> done;\r\
    \n  auto add = [&](int a, int b) -> void {\r\n    pair<int, int> p = {a, b};\r\
    \n    if (done.count(p)) return;\r\n    done.insert(p);\r\n    H.add(a, b);\r\n\
    \  };\r\n  for (auto&& e: G.edges) {\r\n    // \u6CE8\u610F\uFF1A\u6B21\u6570\u6BD4\
    \u8F03\u3060\u3051\u3060\u3068 DAG \u306B\u306A\u3089\u305A\u3001\u30B5\u30A4\u30AF\
    \u30EB\u304C\u3067\u304D\u3066\u3057\u307E\u3046\r\n    if (mp(G.deg(e.frm), e.frm)\
    \ < mp(G.deg(e.to), e.to))\r\n      add(e.frm, e.to);\r\n    else\r\n      add(e.to,\
    \ e.frm);\r\n  }\r\n  H.build();\r\n\r\n  vc<bool> table(N);\r\n  FOR(a, N) {\r\
    \n    for (auto&& e: H[a]) { table[e.to] = 1; }\r\n    for (auto&& e: H[a]) {\r\
    \n      int b = e.to;\r\n      for (auto&& f: H[b]) {\r\n        int c = f.to;\r\
    \n        if (table[c]) query(a, b, c);\r\n      }\r\n    }\r\n    for (auto&&\
    \ e: H[a]) { table[e.to] = 0; }\r\n  }\r\n}\r\n"
  code: "#include \"graph/base.hpp\"\r\n\r\ntemplate <typename Gr, typename F>\r\n\
    void enumerate_triangle(Gr& G, F query) {\r\n  int N = G.N;\r\n  Graph<int, 1>\
    \ H(N);\r\n  set<pair<int, int>> done;\r\n  auto add = [&](int a, int b) -> void\
    \ {\r\n    pair<int, int> p = {a, b};\r\n    if (done.count(p)) return;\r\n  \
    \  done.insert(p);\r\n    H.add(a, b);\r\n  };\r\n  for (auto&& e: G.edges) {\r\
    \n    // \u6CE8\u610F\uFF1A\u6B21\u6570\u6BD4\u8F03\u3060\u3051\u3060\u3068 DAG\
    \ \u306B\u306A\u3089\u305A\u3001\u30B5\u30A4\u30AF\u30EB\u304C\u3067\u304D\u3066\
    \u3057\u307E\u3046\r\n    if (mp(G.deg(e.frm), e.frm) < mp(G.deg(e.to), e.to))\r\
    \n      add(e.frm, e.to);\r\n    else\r\n      add(e.to, e.frm);\r\n  }\r\n  H.build();\r\
    \n\r\n  vc<bool> table(N);\r\n  FOR(a, N) {\r\n    for (auto&& e: H[a]) { table[e.to]\
    \ = 1; }\r\n    for (auto&& e: H[a]) {\r\n      int b = e.to;\r\n      for (auto&&\
    \ f: H[b]) {\r\n        int c = f.to;\r\n        if (table[c]) query(a, b, c);\r\
    \n      }\r\n    }\r\n    for (auto&& e: H[a]) { table[e.to] = 0; }\r\n  }\r\n\
    }\r\n"
  dependsOn:
  - graph/base.hpp
  isVerificationFile: false
  path: enumerate/triangle.hpp
  requiredBy: []
  timestamp: '2024-10-14 04:14:06+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/2_library_checker/graph/enumerate_triangles.test.cpp
documentation_of: enumerate/triangle.hpp
layout: document
redirect_from:
- /library/enumerate/triangle.hpp
- /library/enumerate/triangle.hpp.html
title: enumerate/triangle.hpp
---
