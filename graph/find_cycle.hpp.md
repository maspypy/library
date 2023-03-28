---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: graph/base.hpp
    title: graph/base.hpp
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/library_checker/graph/cycle_detection.test.cpp
    title: test/library_checker/graph/cycle_detection.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/library_checker/graph/cycle_detection_undirected.test.cpp
    title: test/library_checker/graph/cycle_detection_undirected.test.cpp
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
    \ { vc_indeg[e.to]++, vc_outdeg[e.frm]++; }\n  }\n};\n#line 2 \"graph/find_cycle.hpp\"\
    \n\r\ntemplate <typename GT>\r\npair<vc<int>, vc<int>> find_cycle_directed(GT&\
    \ G) {\r\n  assert(G.is_directed());\r\n  assert(G.is_prepared());\r\n\r\n  int\
    \ N = G.N;\r\n  vc<int> used(N);\r\n  vc<pair<int, int>> par(N);\r\n  vector<int>\
    \ es, vs;\r\n\r\n  auto dfs = [&](auto self, int v) -> void {\r\n    used[v] =\
    \ 1;\r\n    for (auto&& e: G[v]) {\r\n      if (len(es)) return;\r\n      if (!used[e.to])\
    \ {\r\n        par[e.to] = {v, e.id};\r\n        self(self, e.to);\r\n      }\r\
    \n      elif (used[e.to] == 1) {\r\n        es = {e.id};\r\n        int cur =\
    \ v;\r\n        while (cur != e.to) {\r\n          es.eb(par[cur].se);\r\n   \
    \       cur = par[cur].fi;\r\n        }\r\n        reverse(all(es));\r\n     \
    \   return;\r\n      }\r\n    }\r\n    used[v] = 2;\r\n  };\r\n  FOR(v, N) if\
    \ (!used[v]) dfs(dfs, v);\r\n  if (es.empty()) return {vs, es};\r\n\r\n  vs.resize(len(es));\r\
    \n  FOR(i, len(es)) { vs[i] = G.edges[es[i]].frm; }\r\n  return {vs, es};\r\n\
    }\r\n\r\n// {vs, es}\u3001\u5B58\u5728\u3057\u306A\u3051\u308C\u3070 empty\r\n\
    // \u6975\u5C0F\u306A\u3082\u306E\u3092\u8FD4\u3059\r\ntemplate <typename GT>\r\
    \npair<vc<int>, vc<int>> find_cycle_undirected(GT& G) {\r\n  const int N = G.N;\r\
    \n  const int M = G.M;\r\n  vc<int> dep(N, -1);\r\n  vc<bool> used_e(M);\r\n \
    \ vc<int> par(N, -1); // \u8FBA\u756A\u53F7\r\n\r\n  auto dfs = [&](auto& dfs,\
    \ int v, int d) -> int {\r\n    dep[v] = d;\r\n    for (auto&& e: G[v]) {\r\n\
    \      if (used_e[e.id]) continue;\r\n      if (dep[e.to] != -1) return v;\r\n\
    \      used_e[e.id] = 1;\r\n      par[e.to] = e.id;\r\n      int res = dfs(dfs,\
    \ e.to, d + 1);\r\n      if (res != -1) return res;\r\n    }\r\n    return -1;\r\
    \n  };\r\n\r\n  vc<int> vs, es;\r\n  FOR(v, N) {\r\n    if (dep[v] != -1) continue;\r\
    \n    // v \u304B\u3089\u306E dfs \u6728\u306B\u304A\u3044\u3066\u3001w \u304C\
    \u5F8C\u9000\u8FBA\u3092\u6301\u3064\r\n    int w = dfs(dfs, v, 0);\r\n    if\
    \ (w == -1) continue;\r\n    int b = -1, back_e = -1;\r\n    while (1) {\r\n \
    \     for (auto&& e: G[w]) {\r\n        if (used_e[e.id]) continue;\r\n      \
    \  if (dep[e.to] > dep[w] || dep[e.to] == -1) continue;\r\n        b = w, back_e\
    \ = e.id;\r\n      }\r\n      if (w == v) break;\r\n      auto& e = G.edges[par[w]];\r\
    \n      w = e.frm + e.to - w;\r\n    }\r\n    // b \u304B\u3089\u306E\u5F8C\u9000\
    \u8FBA back_e \u3092\u4F7F\u3063\u3066\u30B5\u30A4\u30AF\u30EB\u3092\u4F5C\u308B\
    \r\n    int a = G.edges[back_e].frm + G.edges[back_e].to - b;\r\n    es.eb(back_e),\
    \ vs.eb(a);\r\n    while (1) {\r\n      int x = vs.back();\r\n      auto& e =\
    \ G.edges[es.back()];\r\n      int y = e.frm + e.to - x;\r\n      if (y == a)\
    \ break;\r\n      vs.eb(y);\r\n      es.eb(par[y]);\r\n    }\r\n    return {vs,\
    \ es};\r\n  }\r\n  return {vs, es};\r\n}\r\n\r\n// {vs, es} \uFF1A\u8FBA\u306E\
    \u5217\u3068\u9802\u70B9\u306E\u5217\u3092\u8FD4\u3059\u3002es[i] \u306F vs[i]\
    \ \u304B\u3089 vs[i+1]\u3002\r\n// \u3068\u308A\u3042\u3048\u305A\u7121\u5411\u306E\
    \u3068\u304D\u306B\u306F\u6975\u5C0F\u306A\u3082\u306E\u3092\u8FD4\u3059\u3053\
    \u3068\u306B\u3057\u305F\u3002\r\ntemplate <typename GT>\r\npair<vc<int>, vc<int>>\
    \ find_cycle(GT& G) {\r\n  if (G.is_directed()) return find_cycle_directed(G);\r\
    \n  return find_cycle_undirected(G);\r\n}\r\n"
  code: "#include \"graph/base.hpp\"\r\n\r\ntemplate <typename GT>\r\npair<vc<int>,\
    \ vc<int>> find_cycle_directed(GT& G) {\r\n  assert(G.is_directed());\r\n  assert(G.is_prepared());\r\
    \n\r\n  int N = G.N;\r\n  vc<int> used(N);\r\n  vc<pair<int, int>> par(N);\r\n\
    \  vector<int> es, vs;\r\n\r\n  auto dfs = [&](auto self, int v) -> void {\r\n\
    \    used[v] = 1;\r\n    for (auto&& e: G[v]) {\r\n      if (len(es)) return;\r\
    \n      if (!used[e.to]) {\r\n        par[e.to] = {v, e.id};\r\n        self(self,\
    \ e.to);\r\n      }\r\n      elif (used[e.to] == 1) {\r\n        es = {e.id};\r\
    \n        int cur = v;\r\n        while (cur != e.to) {\r\n          es.eb(par[cur].se);\r\
    \n          cur = par[cur].fi;\r\n        }\r\n        reverse(all(es));\r\n \
    \       return;\r\n      }\r\n    }\r\n    used[v] = 2;\r\n  };\r\n  FOR(v, N)\
    \ if (!used[v]) dfs(dfs, v);\r\n  if (es.empty()) return {vs, es};\r\n\r\n  vs.resize(len(es));\r\
    \n  FOR(i, len(es)) { vs[i] = G.edges[es[i]].frm; }\r\n  return {vs, es};\r\n\
    }\r\n\r\n// {vs, es}\u3001\u5B58\u5728\u3057\u306A\u3051\u308C\u3070 empty\r\n\
    // \u6975\u5C0F\u306A\u3082\u306E\u3092\u8FD4\u3059\r\ntemplate <typename GT>\r\
    \npair<vc<int>, vc<int>> find_cycle_undirected(GT& G) {\r\n  const int N = G.N;\r\
    \n  const int M = G.M;\r\n  vc<int> dep(N, -1);\r\n  vc<bool> used_e(M);\r\n \
    \ vc<int> par(N, -1); // \u8FBA\u756A\u53F7\r\n\r\n  auto dfs = [&](auto& dfs,\
    \ int v, int d) -> int {\r\n    dep[v] = d;\r\n    for (auto&& e: G[v]) {\r\n\
    \      if (used_e[e.id]) continue;\r\n      if (dep[e.to] != -1) return v;\r\n\
    \      used_e[e.id] = 1;\r\n      par[e.to] = e.id;\r\n      int res = dfs(dfs,\
    \ e.to, d + 1);\r\n      if (res != -1) return res;\r\n    }\r\n    return -1;\r\
    \n  };\r\n\r\n  vc<int> vs, es;\r\n  FOR(v, N) {\r\n    if (dep[v] != -1) continue;\r\
    \n    // v \u304B\u3089\u306E dfs \u6728\u306B\u304A\u3044\u3066\u3001w \u304C\
    \u5F8C\u9000\u8FBA\u3092\u6301\u3064\r\n    int w = dfs(dfs, v, 0);\r\n    if\
    \ (w == -1) continue;\r\n    int b = -1, back_e = -1;\r\n    while (1) {\r\n \
    \     for (auto&& e: G[w]) {\r\n        if (used_e[e.id]) continue;\r\n      \
    \  if (dep[e.to] > dep[w] || dep[e.to] == -1) continue;\r\n        b = w, back_e\
    \ = e.id;\r\n      }\r\n      if (w == v) break;\r\n      auto& e = G.edges[par[w]];\r\
    \n      w = e.frm + e.to - w;\r\n    }\r\n    // b \u304B\u3089\u306E\u5F8C\u9000\
    \u8FBA back_e \u3092\u4F7F\u3063\u3066\u30B5\u30A4\u30AF\u30EB\u3092\u4F5C\u308B\
    \r\n    int a = G.edges[back_e].frm + G.edges[back_e].to - b;\r\n    es.eb(back_e),\
    \ vs.eb(a);\r\n    while (1) {\r\n      int x = vs.back();\r\n      auto& e =\
    \ G.edges[es.back()];\r\n      int y = e.frm + e.to - x;\r\n      if (y == a)\
    \ break;\r\n      vs.eb(y);\r\n      es.eb(par[y]);\r\n    }\r\n    return {vs,\
    \ es};\r\n  }\r\n  return {vs, es};\r\n}\r\n\r\n// {vs, es} \uFF1A\u8FBA\u306E\
    \u5217\u3068\u9802\u70B9\u306E\u5217\u3092\u8FD4\u3059\u3002es[i] \u306F vs[i]\
    \ \u304B\u3089 vs[i+1]\u3002\r\n// \u3068\u308A\u3042\u3048\u305A\u7121\u5411\u306E\
    \u3068\u304D\u306B\u306F\u6975\u5C0F\u306A\u3082\u306E\u3092\u8FD4\u3059\u3053\
    \u3068\u306B\u3057\u305F\u3002\r\ntemplate <typename GT>\r\npair<vc<int>, vc<int>>\
    \ find_cycle(GT& G) {\r\n  if (G.is_directed()) return find_cycle_directed(G);\r\
    \n  return find_cycle_undirected(G);\r\n}\r\n"
  dependsOn:
  - graph/base.hpp
  isVerificationFile: false
  path: graph/find_cycle.hpp
  requiredBy: []
  timestamp: '2023-03-02 23:03:25+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/library_checker/graph/cycle_detection.test.cpp
  - test/library_checker/graph/cycle_detection_undirected.test.cpp
documentation_of: graph/find_cycle.hpp
layout: document
redirect_from:
- /library/graph/find_cycle.hpp
- /library/graph/find_cycle.hpp.html
title: graph/find_cycle.hpp
---
