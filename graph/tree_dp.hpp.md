---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: graph/base.hpp
    title: graph/base.hpp
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
    \ v = 1; v < N; ++v) {\n      INT(p);\n      p -= off;\n      add(p, v);\n   \
    \ }\n    build();\n  }\n\n  void build() {\n    assert(!prepared);\n    prepared\
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
    \    }\n  }\n};\n#line 2 \"graph/tree_dp.hpp\"\n\r\n// \u6728\u5168\u4F53\u306B\
    \u5BFE\u3059\u308B\u7D50\u679C\u3092 return \u3059\u308B\u3002\r\n// \u90E8\u5206\
    \u6728\u3054\u3068\u306B\u51E6\u7406\u3057\u305F\u3044\u5834\u5408\u306F\u3001\
    fev \u306E\u6700\u5F8C\u306B\u884C\u3046\u3088\u3046\u306B\u305B\u3088\u3002\r\
    \ntemplate <typename Graph, typename Data, typename F1, typename F2, typename\
    \ F3>\r\nData tree_dp(Graph& G, F1 fee, F2 fev, F3 fve, Data unit, int root =\
    \ 0) {\r\n  int N = G.N;\r\n\r\n  auto dfs = [&](auto& dfs, int v, int p) -> Data\
    \ {\r\n    Data x = unit;\r\n    for (auto&& e: G[v]) {\r\n      if (e.to == p)\
    \ continue;\r\n      x = fee(x, fve(dfs(dfs, e.to, v), e));\r\n    }\r\n    return\
    \ fev(x, v);\r\n  };\r\n  return dfs(dfs, root, -1);\r\n}\r\n"
  code: "#include \"graph/base.hpp\"\r\n\r\n// \u6728\u5168\u4F53\u306B\u5BFE\u3059\
    \u308B\u7D50\u679C\u3092 return \u3059\u308B\u3002\r\n// \u90E8\u5206\u6728\u3054\
    \u3068\u306B\u51E6\u7406\u3057\u305F\u3044\u5834\u5408\u306F\u3001fev \u306E\u6700\
    \u5F8C\u306B\u884C\u3046\u3088\u3046\u306B\u305B\u3088\u3002\r\ntemplate <typename\
    \ Graph, typename Data, typename F1, typename F2, typename F3>\r\nData tree_dp(Graph&\
    \ G, F1 fee, F2 fev, F3 fve, Data unit, int root = 0) {\r\n  int N = G.N;\r\n\r\
    \n  auto dfs = [&](auto& dfs, int v, int p) -> Data {\r\n    Data x = unit;\r\n\
    \    for (auto&& e: G[v]) {\r\n      if (e.to == p) continue;\r\n      x = fee(x,\
    \ fve(dfs(dfs, e.to, v), e));\r\n    }\r\n    return fev(x, v);\r\n  };\r\n  return\
    \ dfs(dfs, root, -1);\r\n}\r\n"
  dependsOn:
  - graph/base.hpp
  isVerificationFile: false
  path: graph/tree_dp.hpp
  requiredBy: []
  timestamp: '2022-08-18 17:59:01+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: graph/tree_dp.hpp
layout: document
redirect_from:
- /library/graph/tree_dp.hpp
- /library/graph/tree_dp.hpp.html
title: graph/tree_dp.hpp
---
