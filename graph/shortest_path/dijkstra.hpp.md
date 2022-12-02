---
data:
  _extendedDependsOn:
  - icon: ':question:'
    path: graph/base.hpp
    title: graph/base.hpp
  _extendedRequiredBy:
  - icon: ':x:'
    path: graph/mincostcycle.hpp
    title: graph/mincostcycle.hpp
  - icon: ':heavy_check_mark:'
    path: graph/shortest_path/K_shortest_walk.hpp
    title: graph/shortest_path/K_shortest_walk.hpp
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/aoj/0275.test.cpp
    title: test/aoj/0275.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/aoj/2251_1.test.cpp
    title: test/aoj/2251_1.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/aoj/2251_2.test.cpp
    title: test/aoj/2251_2.test.cpp
  - icon: ':x:'
    path: test/atcoder/arc151_e.test.cpp
    title: test/atcoder/arc151_e.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/library_checker/graph/K_shortest_walk.test.cpp
    title: test/library_checker/graph/K_shortest_walk.test.cpp
  - icon: ':x:'
    path: test/library_checker/graph/shortest_path.test.cpp
    title: test/library_checker/graph/shortest_path.test.cpp
  - icon: ':x:'
    path: test/yukicoder/1320.test.cpp
    title: test/yukicoder/1320.test.cpp
  - icon: ':x:'
    path: test/yukicoder/1601.test.cpp
    title: test/yukicoder/1601.test.cpp
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
    \ { vc_indeg[e.to]++, vc_outdeg[e.frm]++; }\n  }\n};\n#line 3 \"graph/shortest_path/dijkstra.hpp\"\
    \n\ntemplate <typename T, typename Graph>\npair<vc<T>, vc<int>> dijkstra(Graph&\
    \ G, int v, T INF) {\n  auto N = G.N;\n  vector<T> dist(N, INF);\n  vector<int>\
    \ par(N, -1);\n  using P = pair<T, int>;\n\n  priority_queue<P, vector<P>, greater<P>>\
    \ que;\n\n  dist[v] = 0;\n  que.emplace(0, v);\n  while (!que.empty()) {\n   \
    \ auto [dv, v] = que.top();\n    que.pop();\n    if (dv > dist[v]) continue;\n\
    \    for (auto&& e: G[v]) {\n      if (chmin(dist[e.to], dist[e.frm] + e.cost))\
    \ {\n        par[e.to] = e.frm;\n        que.emplace(dist[e.to], e.to);\n    \
    \  }\n    }\n  }\n  return {dist, par};\n}\n\n// \u591A\u70B9\u30B9\u30BF\u30FC\
    \u30C8\u3002[dist, par, root]\ntemplate <typename T, typename Graph>\ntuple<vc<T>,\
    \ vc<int>, vc<int>> dijkstra(Graph& G, vc<int> vs, T INF) {\n  assert(G.is_prepared());\n\
    \  int N = G.N;\n  vc<ll> dist(N, INF);\n  vc<int> par(N, -1);\n  vc<int> root(N,\
    \ -1);\n\n  using P = pair<T, int>;\n\n  priority_queue<P, vector<P>, greater<P>>\
    \ que;\n\n  for (auto&& v: vs) {\n    dist[v] = 0;\n    root[v] = v;\n    que.emplace(T(0),\
    \ v);\n  }\n\n  while (!que.empty()) {\n    auto [dv, v] = que.top();\n    que.pop();\n\
    \    if (dv > dist[v]) continue;\n    for (auto&& e: G[v]) {\n      if (chmin(dist[e.to],\
    \ dist[e.frm] + e.cost)) {\n        root[e.to] = root[e.frm];\n        par[e.to]\
    \ = e.frm;\n        que.push(mp(dist[e.to], e.to));\n      }\n    }\n  }\n  return\
    \ {dist, par, root};\n}\n"
  code: "#pragma once\n#include \"graph/base.hpp\"\n\ntemplate <typename T, typename\
    \ Graph>\npair<vc<T>, vc<int>> dijkstra(Graph& G, int v, T INF) {\n  auto N =\
    \ G.N;\n  vector<T> dist(N, INF);\n  vector<int> par(N, -1);\n  using P = pair<T,\
    \ int>;\n\n  priority_queue<P, vector<P>, greater<P>> que;\n\n  dist[v] = 0;\n\
    \  que.emplace(0, v);\n  while (!que.empty()) {\n    auto [dv, v] = que.top();\n\
    \    que.pop();\n    if (dv > dist[v]) continue;\n    for (auto&& e: G[v]) {\n\
    \      if (chmin(dist[e.to], dist[e.frm] + e.cost)) {\n        par[e.to] = e.frm;\n\
    \        que.emplace(dist[e.to], e.to);\n      }\n    }\n  }\n  return {dist,\
    \ par};\n}\n\n// \u591A\u70B9\u30B9\u30BF\u30FC\u30C8\u3002[dist, par, root]\n\
    template <typename T, typename Graph>\ntuple<vc<T>, vc<int>, vc<int>> dijkstra(Graph&\
    \ G, vc<int> vs, T INF) {\n  assert(G.is_prepared());\n  int N = G.N;\n  vc<ll>\
    \ dist(N, INF);\n  vc<int> par(N, -1);\n  vc<int> root(N, -1);\n\n  using P =\
    \ pair<T, int>;\n\n  priority_queue<P, vector<P>, greater<P>> que;\n\n  for (auto&&\
    \ v: vs) {\n    dist[v] = 0;\n    root[v] = v;\n    que.emplace(T(0), v);\n  }\n\
    \n  while (!que.empty()) {\n    auto [dv, v] = que.top();\n    que.pop();\n  \
    \  if (dv > dist[v]) continue;\n    for (auto&& e: G[v]) {\n      if (chmin(dist[e.to],\
    \ dist[e.frm] + e.cost)) {\n        root[e.to] = root[e.frm];\n        par[e.to]\
    \ = e.frm;\n        que.push(mp(dist[e.to], e.to));\n      }\n    }\n  }\n  return\
    \ {dist, par, root};\n}\n"
  dependsOn:
  - graph/base.hpp
  isVerificationFile: false
  path: graph/shortest_path/dijkstra.hpp
  requiredBy:
  - graph/mincostcycle.hpp
  - graph/shortest_path/K_shortest_walk.hpp
  timestamp: '2022-10-21 17:08:40+09:00'
  verificationStatus: LIBRARY_SOME_WA
  verifiedWith:
  - test/yukicoder/1320.test.cpp
  - test/yukicoder/1601.test.cpp
  - test/library_checker/graph/K_shortest_walk.test.cpp
  - test/library_checker/graph/shortest_path.test.cpp
  - test/atcoder/arc151_e.test.cpp
  - test/aoj/2251_1.test.cpp
  - test/aoj/2251_2.test.cpp
  - test/aoj/0275.test.cpp
documentation_of: graph/shortest_path/dijkstra.hpp
layout: document
redirect_from:
- /library/graph/shortest_path/dijkstra.hpp
- /library/graph/shortest_path/dijkstra.hpp.html
title: graph/shortest_path/dijkstra.hpp
---
