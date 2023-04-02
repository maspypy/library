---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: graph/base.hpp
    title: graph/base.hpp
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/aoj/GRL_1_C.test.cpp
    title: test/aoj/GRL_1_C.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/yukicoder/1344.test.cpp
    title: test/yukicoder/1344.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/yukicoder/17.test.cpp
    title: test/yukicoder/17.test.cpp
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
    \ print(e.frm, e.to, e.cost, e.id);\n    }\n  }\n\n  // G \u306B\u304A\u3051\u308B\
    \u9802\u70B9 V[i] \u304C\u3001\u65B0\u3057\u3044\u30B0\u30E9\u30D5\u3067 i \u306B\
    \u306A\u308B\u3088\u3046\u306B\u3059\u308B\n  Graph<T, directed> rearrange(vc<int>\
    \ V) {\n    int n = len(V);\n    map<int, int> MP;\n    FOR(i, n) MP[V[i]] = i;\n\
    \    Graph<T, directed> G(n);\n    for (auto&& e: edges) {\n      if (MP.count(e.frm)\
    \ && MP.count(e.to)) {\n        G.add(MP[e.frm], MP[e.to], e.cost);\n      }\n\
    \    }\n    G.build();\n    return G;\n  }\n\nprivate:\n  void calc_deg() {\n\
    \    assert(vc_deg.empty());\n    vc_deg.resize(N);\n    for (auto&& e: edges)\
    \ vc_deg[e.frm]++, vc_deg[e.to]++;\n  }\n\n  void calc_deg_inout() {\n    assert(vc_indeg.empty());\n\
    \    vc_indeg.resize(N);\n    vc_outdeg.resize(N);\n    for (auto&& e: edges)\
    \ { vc_indeg[e.to]++, vc_outdeg[e.frm]++; }\n  }\n};\n#line 3 \"graph/shortest_path/warshall_floyd.hpp\"\
    \n\n// \u8CA0\u8FBA\u304C\u3042\u3063\u3066\u3082\u8CA0\u9589\u8DEF\u304C\u306A\
    \u3051\u308C\u3070\u6B63\u3057\u304F\u52D5\u4F5C\u3059\u308B\u3002\n// \u8CA0\u9589\
    \u8DEF\u304C\u3042\u308B\u304B\u3069\u3046\u304B\u306F\u3001dist[v][v] < 0 \u3068\
    \u306A\u308B v \u304C\u3042\u308B\u304B\u3069\u3046\u304B\u3067\u5224\u5B9A\u3002\
    \ntemplate <typename T, typename GT>\nvc<vc<T>> warshall_floyd(GT& G) {\n  ll\
    \ N = G.N;\n  vv(T, dist, N, N, infty<T>);\n  FOR(v, N) {\n    dist[v][v] = 0;\n\
    \    for (auto&& e: G[v]) chmin(dist[v][e.to], e.cost);\n  }\n  FOR(k, N) FOR(i,\
    \ N) {\n    if (dist[i][k] == infty<T>) continue;\n    FOR(j, N) {\n      if (dist[k][j]\
    \ == infty<T>) continue;\n      chmin(dist[i][j], dist[i][k] + dist[k][j]);\n\
    \    }\n  }\n  return dist;\n}\n"
  code: "#pragma once\n#include \"graph/base.hpp\"\n\n// \u8CA0\u8FBA\u304C\u3042\u3063\
    \u3066\u3082\u8CA0\u9589\u8DEF\u304C\u306A\u3051\u308C\u3070\u6B63\u3057\u304F\
    \u52D5\u4F5C\u3059\u308B\u3002\n// \u8CA0\u9589\u8DEF\u304C\u3042\u308B\u304B\u3069\
    \u3046\u304B\u306F\u3001dist[v][v] < 0 \u3068\u306A\u308B v \u304C\u3042\u308B\
    \u304B\u3069\u3046\u304B\u3067\u5224\u5B9A\u3002\ntemplate <typename T, typename\
    \ GT>\nvc<vc<T>> warshall_floyd(GT& G) {\n  ll N = G.N;\n  vv(T, dist, N, N, infty<T>);\n\
    \  FOR(v, N) {\n    dist[v][v] = 0;\n    for (auto&& e: G[v]) chmin(dist[v][e.to],\
    \ e.cost);\n  }\n  FOR(k, N) FOR(i, N) {\n    if (dist[i][k] == infty<T>) continue;\n\
    \    FOR(j, N) {\n      if (dist[k][j] == infty<T>) continue;\n      chmin(dist[i][j],\
    \ dist[i][k] + dist[k][j]);\n    }\n  }\n  return dist;\n}"
  dependsOn:
  - graph/base.hpp
  isVerificationFile: false
  path: graph/shortest_path/warshall_floyd.hpp
  requiredBy: []
  timestamp: '2023-04-02 04:25:25+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/aoj/GRL_1_C.test.cpp
  - test/yukicoder/17.test.cpp
  - test/yukicoder/1344.test.cpp
documentation_of: graph/shortest_path/warshall_floyd.hpp
layout: document
redirect_from:
- /library/graph/shortest_path/warshall_floyd.hpp
- /library/graph/shortest_path/warshall_floyd.hpp.html
title: graph/shortest_path/warshall_floyd.hpp
---
