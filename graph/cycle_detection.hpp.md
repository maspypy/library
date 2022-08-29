---
data:
  _extendedDependsOn:
  - icon: ':question:'
    path: graph/base.hpp
    title: graph/base.hpp
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':x:'
    path: test/library_checker/graph/cycle_detection.test.cpp
    title: test/library_checker/graph/cycle_detection.test.cpp
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
    \ }\n  }\n};\n#line 2 \"graph/cycle_detection.hpp\"\n\r\n// \u8FBA\u306E\u5217\
    \ or \u9802\u70B9\u5217\u306E vector \u3092\u8FD4\u3059\r\n// \u898B\u3064\u304B\
    \u3089\u306A\u304B\u3063\u305F\u5834\u5408\u306B\u306F\u3001\u7A7A vector\r\n\
    template <typename Graph>\r\nvc<int> cycle_detection(Graph& G, bool is_edge =\
    \ 0) {\r\n  assert(G.is_directed());\r\n  assert(G.is_prepared());\r\n  if (!is_edge)\
    \ {\r\n    auto C = cycle_detection(G, true);\r\n    if (len(C) == 0) return C;\r\
    \n    vc<int> ANS(len(C));\r\n    FOR(i, len(C)) {\r\n      auto e = G.edges[C[i]];\r\
    \n      ANS[i] = e.frm;\r\n    }\r\n    return ANS;\r\n  }\r\n\r\n  int N = G.N;\r\
    \n  vc<int> used(N);\r\n  vc<int> path; // edge\r\n  vc<pair<int, int>> par(N);\r\
    \n  vector<int> ANS;\r\n\r\n  auto dfs = [&](auto self, int v) -> void {\r\n \
    \   used[v] = 1;\r\n    for (auto&& e: G[v]) {\r\n      if (len(ANS)) return;\r\
    \n      if (!used[e.to]) {\r\n        par[e.to] = {v, e.id};\r\n        self(self,\
    \ e.to);\r\n      }\r\n      elif (used[e.to] == 1) {\r\n        ANS = {e.id};\r\
    \n        int cur = v;\r\n        while (cur != e.to) {\r\n          ANS.eb(par[cur].se);\r\
    \n          cur = par[cur].fi;\r\n        }\r\n        reverse(all(ANS));\r\n\
    \        return;\r\n      }\r\n    }\r\n    used[v] = 2;\r\n  };\r\n  FOR(v, N)\
    \ if (!used[v]) dfs(dfs, v);\r\n  return ANS;\r\n}\n"
  code: "#include \"graph/base.hpp\"\r\n\r\n// \u8FBA\u306E\u5217 or \u9802\u70B9\u5217\
    \u306E vector \u3092\u8FD4\u3059\r\n// \u898B\u3064\u304B\u3089\u306A\u304B\u3063\
    \u305F\u5834\u5408\u306B\u306F\u3001\u7A7A vector\r\ntemplate <typename Graph>\r\
    \nvc<int> cycle_detection(Graph& G, bool is_edge = 0) {\r\n  assert(G.is_directed());\r\
    \n  assert(G.is_prepared());\r\n  if (!is_edge) {\r\n    auto C = cycle_detection(G,\
    \ true);\r\n    if (len(C) == 0) return C;\r\n    vc<int> ANS(len(C));\r\n   \
    \ FOR(i, len(C)) {\r\n      auto e = G.edges[C[i]];\r\n      ANS[i] = e.frm;\r\
    \n    }\r\n    return ANS;\r\n  }\r\n\r\n  int N = G.N;\r\n  vc<int> used(N);\r\
    \n  vc<int> path; // edge\r\n  vc<pair<int, int>> par(N);\r\n  vector<int> ANS;\r\
    \n\r\n  auto dfs = [&](auto self, int v) -> void {\r\n    used[v] = 1;\r\n   \
    \ for (auto&& e: G[v]) {\r\n      if (len(ANS)) return;\r\n      if (!used[e.to])\
    \ {\r\n        par[e.to] = {v, e.id};\r\n        self(self, e.to);\r\n      }\r\
    \n      elif (used[e.to] == 1) {\r\n        ANS = {e.id};\r\n        int cur =\
    \ v;\r\n        while (cur != e.to) {\r\n          ANS.eb(par[cur].se);\r\n  \
    \        cur = par[cur].fi;\r\n        }\r\n        reverse(all(ANS));\r\n   \
    \     return;\r\n      }\r\n    }\r\n    used[v] = 2;\r\n  };\r\n  FOR(v, N) if\
    \ (!used[v]) dfs(dfs, v);\r\n  return ANS;\r\n}"
  dependsOn:
  - graph/base.hpp
  isVerificationFile: false
  path: graph/cycle_detection.hpp
  requiredBy: []
  timestamp: '2022-08-29 21:19:08+09:00'
  verificationStatus: LIBRARY_ALL_WA
  verifiedWith:
  - test/library_checker/graph/cycle_detection.test.cpp
documentation_of: graph/cycle_detection.hpp
layout: document
redirect_from:
- /library/graph/cycle_detection.hpp
- /library/graph/cycle_detection.hpp.html
title: graph/cycle_detection.hpp
---
