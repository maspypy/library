---
data:
  _extendedDependsOn:
  - icon: ':question:'
    path: graph/base.hpp
    title: graph/base.hpp
  - icon: ':heavy_check_mark:'
    path: graph/degree.hpp
    title: graph/degree.hpp
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':warning:'
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
    \      return &G->csr_edges[r];\n    }\n\n  private:\n    const Graph* G;\n  \
    \  int l, r;\n  };\n\n  bool is_prepared() { return prepared; }\n  constexpr bool\
    \ is_directed() { return directed; }\n\n  Graph() : N(0), M(0), prepared(0) {}\n\
    \  Graph(int N) : N(N), M(0), prepared(0) {}\n\n  void add(int frm, int to, T\
    \ cost = 1, int i = -1) {\n    assert(!prepared);\n    assert(0 <= frm && 0 <=\
    \ to && to < N);\n    if (i == -1) i = M;\n    auto e = edge_type({frm, to, cost,\
    \ i});\n    edges.eb(e);\n    ++M;\n  }\n\n  // wt, off\n  void read_tree(bool\
    \ wt = false, int off = 1) { read_graph(N - 1, wt, off); }\n\n  void read_graph(int\
    \ M, bool wt = false, int off = 1) {\n    for (int m = 0; m < M; ++m) {\n    \
    \  INT(a, b);\n      a -= off, b -= off;\n      if (!wt) {\n        add(a, b);\n\
    \      } else {\n        T c;\n        read(c);\n        add(a, b, c);\n     \
    \ }\n    }\n    build();\n  }\n\n  void read_parent(int off = 1) {\n    for (int\
    \ v = N - 1; v >= 1; --v) {\n      INT(p);\n      p -= off;\n      add(p, v);\n\
    \    }\n    build();\n  }\n\n  void build() {\n    assert(!prepared);\n    prepared\
    \ = true;\n    indptr.assign(N + 1, 0);\n    for (auto&& e: edges) {\n      indptr[e.frm\
    \ + 1]++;\n      if (!directed) indptr[e.to + 1]++;\n    }\n    for (int v = 0;\
    \ v < N; ++v) { indptr[v + 1] += indptr[v]; }\n    auto counter = indptr;\n  \
    \  csr_edges.resize(indptr.back() + 1);\n    for (auto&& e: edges) {\n      csr_edges[counter[e.frm]++]\
    \ = e;\n      if (!directed)\n        csr_edges[counter[e.to]++] = edge_type({e.to,\
    \ e.frm, e.cost, e.id});\n    }\n  }\n\n  OutgoingEdges operator[](int v) const\
    \ {\n    assert(prepared);\n    return {this, indptr[v], indptr[v + 1]};\n  }\n\
    \n  void debug() {\n    print(\"Graph\");\n    if (!prepared) {\n      print(\"\
    frm to cost id\");\n      for (auto&& e: edges) print(e.frm, e.to, e.cost, e.id);\n\
    \    } else {\n      print(\"indptr\", indptr);\n      print(\"frm to cost id\"\
    );\n      FOR(v, N) for (auto&& e: (*this)[v]) print(e.frm, e.to, e.cost, e.id);\n\
    \    }\n  }\n};\n#line 2 \"graph/degree.hpp\"\n\r\ntemplate <typename Graph>\r\
    \nvector<int> degree(Graph& G) {\r\n  vector<int> deg(G.N);\r\n  for(auto&& e\
    \ : G.edges) deg[e.frm]++, deg[e.to]++;\r\n  return deg;\r\n}\r\n\r\ntemplate\
    \ <typename Graph>\r\npair<vector<int>, vector<int>> degree_inout(Graph& G) {\r\
    \n  vector<int> indeg(G.N), outdeg(G.N);\r\n  for (auto&& e: G.edges) { indeg[e.to]++,\
    \ outdeg[e.frm]++; }\r\n  return {indeg, outdeg};\r\n}\r\n#line 2 \"graph/unicyclic.hpp\"\
    \n\nstruct UnicyclicGraph {\n  int root;\n  Graph<int, 1> tree;\n  vc<int> TO;\n\
    \  vc<int> cycle; // \u6839\u306B\u5411\u304B\u3046\u3088\u3046\u306A\u9802\u70B9\
    \u5217\n  vc<bool> in_cycle;\n\n  template <typename Graph>\n  UnicyclicGraph(Graph&\
    \ G) : tree(G.N) {\n    int N = G.N;\n    assert(N == G.M);\n    TO.assign(N,\
    \ -1);\n    vc<bool> done(N);\n    vc<int> que;\n    auto deg = degree(G);\n \
    \   FOR(v, N) if (deg[v] == 1) que.eb(v);\n    while (len(que)) {\n      auto\
    \ v = que.back();\n      que.pop_back();\n      for (auto&& e: G[v]) {\n     \
    \   if (done[e.id]) continue;\n        done[e.id] = 1;\n        int to = e.to;\n\
    \        TO[v] = to;\n        deg[to] -= 1;\n        if (deg[to] == 1) que.eb(to);\n\
    \      }\n      deg[v] = 0;\n    }\n    root = -1;\n    FOR(v, N) if (deg[v] ==\
    \ 2) root = v;\n    assert(root != -1);\n    vc<int> P = {root};\n    while (1)\
    \ {\n      int v = P.back();\n      bool upd = 0;\n      for (auto&& e: G[v])\
    \ {\n        if (done[e.id]) continue;\n        done[e.id] = 1;\n        P.eb(e.to);\n\
    \        upd = 1;\n        break;\n      }\n      if (!upd) break;\n    }\n  \
    \  FOR(i, len(P) - 1) TO[P[i]] = P[i + 1];\n    cycle = {P.begin() + 1, P.end()};\n\
    \    reverse(all(cycle));\n    in_cycle.assign(N, false);\n    for(auto&& v :\
    \ cycle) in_cycle[v] = 1;\n    FOR(v, N) if (v != root) tree.add(TO[v], v);\n\
    \    tree.build();\n  }\n};\n"
  code: "#include \"graph/degree.hpp\"\n\nstruct UnicyclicGraph {\n  int root;\n \
    \ Graph<int, 1> tree;\n  vc<int> TO;\n  vc<int> cycle; // \u6839\u306B\u5411\u304B\
    \u3046\u3088\u3046\u306A\u9802\u70B9\u5217\n  vc<bool> in_cycle;\n\n  template\
    \ <typename Graph>\n  UnicyclicGraph(Graph& G) : tree(G.N) {\n    int N = G.N;\n\
    \    assert(N == G.M);\n    TO.assign(N, -1);\n    vc<bool> done(N);\n    vc<int>\
    \ que;\n    auto deg = degree(G);\n    FOR(v, N) if (deg[v] == 1) que.eb(v);\n\
    \    while (len(que)) {\n      auto v = que.back();\n      que.pop_back();\n \
    \     for (auto&& e: G[v]) {\n        if (done[e.id]) continue;\n        done[e.id]\
    \ = 1;\n        int to = e.to;\n        TO[v] = to;\n        deg[to] -= 1;\n \
    \       if (deg[to] == 1) que.eb(to);\n      }\n      deg[v] = 0;\n    }\n   \
    \ root = -1;\n    FOR(v, N) if (deg[v] == 2) root = v;\n    assert(root != -1);\n\
    \    vc<int> P = {root};\n    while (1) {\n      int v = P.back();\n      bool\
    \ upd = 0;\n      for (auto&& e: G[v]) {\n        if (done[e.id]) continue;\n\
    \        done[e.id] = 1;\n        P.eb(e.to);\n        upd = 1;\n        break;\n\
    \      }\n      if (!upd) break;\n    }\n    FOR(i, len(P) - 1) TO[P[i]] = P[i\
    \ + 1];\n    cycle = {P.begin() + 1, P.end()};\n    reverse(all(cycle));\n   \
    \ in_cycle.assign(N, false);\n    for(auto&& v : cycle) in_cycle[v] = 1;\n   \
    \ FOR(v, N) if (v != root) tree.add(TO[v], v);\n    tree.build();\n  }\n};\n"
  dependsOn:
  - graph/degree.hpp
  - graph/base.hpp
  isVerificationFile: false
  path: graph/unicyclic.hpp
  requiredBy: []
  timestamp: '2022-08-13 00:10:01+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: graph/unicyclic.hpp
layout: document
redirect_from:
- /library/graph/unicyclic.hpp
- /library/graph/unicyclic.hpp.html
title: graph/unicyclic.hpp
---
