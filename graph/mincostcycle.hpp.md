---
data:
  _extendedDependsOn:
  - icon: ':question:'
    path: graph/base.hpp
    title: graph/base.hpp
  - icon: ':x:'
    path: graph/shortest_path/bfs01.hpp
    title: graph/shortest_path/bfs01.hpp
  - icon: ':question:'
    path: graph/shortest_path/dijkstra.hpp
    title: graph/shortest_path/dijkstra.hpp
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':x:'
    path: test/yukicoder/1320.test.cpp
    title: test/yukicoder/1320.test.cpp
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
    \n\ntemplate <typename T, typename GT>\npair<vc<T>, vc<int>> dijkstra(GT& G, int\
    \ v) {\n  auto N = G.N;\n  vector<T> dist(N, infty<T>);\n  vector<int> par(N,\
    \ -1);\n  using P = pair<T, int>;\n\n  priority_queue<P, vector<P>, greater<P>>\
    \ que;\n\n  dist[v] = 0;\n  que.emplace(0, v);\n  while (!que.empty()) {\n   \
    \ auto [dv, v] = que.top();\n    que.pop();\n    if (dv > dist[v]) continue;\n\
    \    for (auto&& e: G[v]) {\n      if (chmin(dist[e.to], dist[e.frm] + e.cost))\
    \ {\n        par[e.to] = e.frm;\n        que.emplace(dist[e.to], e.to);\n    \
    \  }\n    }\n  }\n  return {dist, par};\n}\n\n// \u591A\u70B9\u30B9\u30BF\u30FC\
    \u30C8\u3002[dist, par, root]\ntemplate <typename T, typename GT>\ntuple<vc<T>,\
    \ vc<int>, vc<int>> dijkstra(GT& G, vc<int> vs) {\n  assert(G.is_prepared());\n\
    \  int N = G.N;\n  vc<ll> dist(N, infty<T>);\n  vc<int> par(N, -1);\n  vc<int>\
    \ root(N, -1);\n\n  using P = pair<T, int>;\n\n  priority_queue<P, vector<P>,\
    \ greater<P>> que;\n\n  for (auto&& v: vs) {\n    dist[v] = 0;\n    root[v] =\
    \ v;\n    que.emplace(T(0), v);\n  }\n\n  while (!que.empty()) {\n    auto [dv,\
    \ v] = que.top();\n    que.pop();\n    if (dv > dist[v]) continue;\n    for (auto&&\
    \ e: G[v]) {\n      if (chmin(dist[e.to], dist[e.frm] + e.cost)) {\n        root[e.to]\
    \ = root[e.frm];\n        par[e.to] = e.frm;\n        que.push(mp(dist[e.to],\
    \ e.to));\n      }\n    }\n  }\n  return {dist, par, root};\n}\n#line 3 \"graph/shortest_path/bfs01.hpp\"\
    \n\ntemplate <typename T, typename GT>\npair<vc<T>, vc<int>> bfs01(GT& G, int\
    \ v) {\n  assert(G.is_prepared());\n  int N = G.N;\n  vc<T> dist(N, infty<T>);\n\
    \  vc<int> par(N, -1);\n  deque<int> que;\n\n  dist[v] = 0;\n  que.push_front(v);\n\
    \  while (!que.empty()) {\n    auto v = que.front();\n    que.pop_front();\n \
    \   for (auto&& e: G[v]) {\n      if (dist[e.to] == infty<T> || dist[e.to] > dist[e.frm]\
    \ + e.cost) {\n        dist[e.to] = dist[e.frm] + e.cost;\n        par[e.to] =\
    \ e.frm;\n        if (e.cost == 0)\n          que.push_front(e.to);\n        else\n\
    \          que.push_back(e.to);\n      }\n    }\n  }\n  return {dist, par};\n\
    }\n\n// \u591A\u70B9\u30B9\u30BF\u30FC\u30C8\u3002[dist, par, root]\ntemplate\
    \ <typename T, typename GT>\ntuple<vc<T>, vc<int>, vc<int>> bfs01(GT& G, vc<int>\
    \ vs) {\n  assert(G.is_prepared());\n  int N = G.N;\n  vc<T> dist(N, infty<T>);\n\
    \  vc<int> par(N, -1);\n  vc<int> root(N, -1);\n  deque<int> que;\n\n  for (auto&&\
    \ v: vs) {\n    dist[v] = 0;\n    root[v] = v;\n    que.push_front(v);\n  }\n\n\
    \  while (!que.empty()) {\n    auto v = que.front();\n    que.pop_front();\n \
    \   for (auto&& e: G[v]) {\n      if (dist[e.to] == infty<T> || dist[e.to] > dist[e.frm]\
    \ + e.cost) {\n        dist[e.to] = dist[e.frm] + e.cost;\n        root[e.to]\
    \ = root[e.frm];\n        par[e.to] = e.frm;\n        if (e.cost == 0)\n     \
    \     que.push_front(e.to);\n        else\n          que.push_back(e.to);\n  \
    \    }\n    }\n  }\n  return {dist, par, root};\n}\n#line 3 \"graph/mincostcycle.hpp\"\
    \n\r\ntemplate <typename T, typename Graph>\r\nT MinCostCycle(Graph& G) {\r\n\
    \  int M = G.M;\r\n  int N = G.N;\r\n  T mx = 0;\r\n  T res = infty<T>;\r\n\r\n\
    \  FOR(i, M) {\r\n    auto& e = G.edges[i];\r\n    T cost = e.cost;\r\n    int\
    \ frm = e.to, to = e.frm;\r\n    Graph Gi(N);\r\n    FOR(j, M) if (i != j) {\r\
    \n      auto& e = G.edges[j];\r\n      Gi.add(e.frm, e.to, e.cost);\r\n    }\r\
    \n    Gi.build();\r\n\r\n    T x = (mx <= 1 ? bfs01<T>(Gi, frm).fi[to]\r\n   \
    \                : dijkstra<T>(Gi, frm).fi[to]);\r\n    if (x == -1) x = infty<T>;\r\
    \n    chmin(res, cost + x);\r\n  }\r\n  if (res == infty<T>) res = -1;\r\n  return\
    \ res;\r\n}\r\n"
  code: "#include \"graph/shortest_path/dijkstra.hpp\"\r\n#include \"graph/shortest_path/bfs01.hpp\"\
    \r\n\r\ntemplate <typename T, typename Graph>\r\nT MinCostCycle(Graph& G) {\r\n\
    \  int M = G.M;\r\n  int N = G.N;\r\n  T mx = 0;\r\n  T res = infty<T>;\r\n\r\n\
    \  FOR(i, M) {\r\n    auto& e = G.edges[i];\r\n    T cost = e.cost;\r\n    int\
    \ frm = e.to, to = e.frm;\r\n    Graph Gi(N);\r\n    FOR(j, M) if (i != j) {\r\
    \n      auto& e = G.edges[j];\r\n      Gi.add(e.frm, e.to, e.cost);\r\n    }\r\
    \n    Gi.build();\r\n\r\n    T x = (mx <= 1 ? bfs01<T>(Gi, frm).fi[to]\r\n   \
    \                : dijkstra<T>(Gi, frm).fi[to]);\r\n    if (x == -1) x = infty<T>;\r\
    \n    chmin(res, cost + x);\r\n  }\r\n  if (res == infty<T>) res = -1;\r\n  return\
    \ res;\r\n}\r\n"
  dependsOn:
  - graph/shortest_path/dijkstra.hpp
  - graph/base.hpp
  - graph/shortest_path/bfs01.hpp
  isVerificationFile: false
  path: graph/mincostcycle.hpp
  requiredBy: []
  timestamp: '2023-02-02 12:48:15+09:00'
  verificationStatus: LIBRARY_ALL_WA
  verifiedWith:
  - test/yukicoder/1320.test.cpp
documentation_of: graph/mincostcycle.hpp
layout: document
redirect_from:
- /library/graph/mincostcycle.hpp
- /library/graph/mincostcycle.hpp.html
title: graph/mincostcycle.hpp
---
