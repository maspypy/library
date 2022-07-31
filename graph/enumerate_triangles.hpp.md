---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: graph/base.hpp
    title: graph/base.hpp
  - icon: ':heavy_check_mark:'
    path: graph/degree.hpp
    title: graph/degree.hpp
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/library_checker/graph/enumerate_triangles.test.cpp
    title: test/library_checker/graph/enumerate_triangles.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
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
    \ outdeg[e.frm]++; }\r\n  return {indeg, outdeg};\r\n}\r\n#line 3 \"graph/enumerate_triangles.hpp\"\
    \n\r\ntemplate <typename Gr, typename F>\r\nvoid enumerate_triangles(Gr& G, F\
    \ query) {\r\n  int N = G.N;\r\n  auto deg = degree(G);\r\n  Graph<int, 1> H(N);\r\
    \n  for (auto&& e: G.edges) {\r\n    // \u6CE8\u610F\uFF1A\u6B21\u6570\u6BD4\u8F03\
    \u3060\u3051\u3060\u3068 DAG \u306B\u306A\u3089\u305A\u3001\u30B5\u30A4\u30AF\u30EB\
    \u304C\u3067\u304D\u3066\u3057\u307E\u3046\r\n    if (mp(deg[e.frm], e.frm) <\
    \ mp(deg[e.to], e.to))\r\n      H.add(e.frm, e.to);\r\n    else\r\n      H.add(e.to,\
    \ e.frm);\r\n  }\r\n  H.build();\r\n\r\n  vc<bool> table(N);\r\n  FOR(a, N) {\r\
    \n    for (auto&& e: H[a]) { table[e.to] = 1; }\r\n    for (auto&& e: H[a]) {\r\
    \n      int b = e.to;\r\n      for (auto&& f: H[b]) {\r\n        int c = f.to;\r\
    \n        if (table[c]) query(a, b, c);\r\n      }\r\n    }\r\n    for (auto&&\
    \ e: H[a]) { table[e.to] = 0; }\r\n  }\r\n}\r\n"
  code: "#include \"graph/base.hpp\"\r\n#include \"graph/degree.hpp\"\r\n\r\ntemplate\
    \ <typename Gr, typename F>\r\nvoid enumerate_triangles(Gr& G, F query) {\r\n\
    \  int N = G.N;\r\n  auto deg = degree(G);\r\n  Graph<int, 1> H(N);\r\n  for (auto&&\
    \ e: G.edges) {\r\n    // \u6CE8\u610F\uFF1A\u6B21\u6570\u6BD4\u8F03\u3060\u3051\
    \u3060\u3068 DAG \u306B\u306A\u3089\u305A\u3001\u30B5\u30A4\u30AF\u30EB\u304C\u3067\
    \u304D\u3066\u3057\u307E\u3046\r\n    if (mp(deg[e.frm], e.frm) < mp(deg[e.to],\
    \ e.to))\r\n      H.add(e.frm, e.to);\r\n    else\r\n      H.add(e.to, e.frm);\r\
    \n  }\r\n  H.build();\r\n\r\n  vc<bool> table(N);\r\n  FOR(a, N) {\r\n    for\
    \ (auto&& e: H[a]) { table[e.to] = 1; }\r\n    for (auto&& e: H[a]) {\r\n    \
    \  int b = e.to;\r\n      for (auto&& f: H[b]) {\r\n        int c = f.to;\r\n\
    \        if (table[c]) query(a, b, c);\r\n      }\r\n    }\r\n    for (auto&&\
    \ e: H[a]) { table[e.to] = 0; }\r\n  }\r\n}\r\n"
  dependsOn:
  - graph/base.hpp
  - graph/degree.hpp
  isVerificationFile: false
  path: graph/enumerate_triangles.hpp
  requiredBy: []
  timestamp: '2022-07-20 17:19:03+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/library_checker/graph/enumerate_triangles.test.cpp
documentation_of: graph/enumerate_triangles.hpp
layout: document
redirect_from:
- /library/graph/enumerate_triangles.hpp
- /library/graph/enumerate_triangles.hpp.html
title: graph/enumerate_triangles.hpp
---
