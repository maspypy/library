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
    path: graph/shortest_path/restore_path.hpp
    title: graph/shortest_path/restore_path.hpp
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':x:'
    path: test/library_checker/tree/tree_diameter.test.cpp
    title: test/library_checker/tree/tree_diameter.test.cpp
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
    \ { vc_indeg[e.to]++, vc_outdeg[e.frm]++; }\n  }\n};\n#line 3 \"graph/shortest_path/bfs01.hpp\"\
    \n\ntemplate <typename Graph, typename INT = int>\npair<vc<INT>, vc<int>> bfs01(Graph&\
    \ G, ll v) {\n  assert(G.is_prepared());\n  int N = G.N;\n  vc<INT> dist(N, -1);\n\
    \  vc<int> par(N, -1);\n  deque<int> que;\n\n  dist[v] = 0;\n  que.push_front(v);\n\
    \  while (!que.empty()) {\n    auto v = que.front();\n    que.pop_front();\n \
    \   for (auto&& e: G[v]) {\n      if (dist[e.to] == -1 || dist[e.to] > dist[e.frm]\
    \ + e.cost) {\n        dist[e.to] = dist[e.frm] + e.cost;\n        par[e.to] =\
    \ e.frm;\n        if (e.cost == 0)\n          que.push_front(e.to);\n        else\n\
    \          que.push_back(e.to);\n      }\n    }\n  }\n  return {dist, par};\n\
    }\n\n// \u591A\u70B9\u30B9\u30BF\u30FC\u30C8\u3002[dist, par, root]\ntemplate\
    \ <typename Graph>\ntuple<vc<ll>, vc<int>, vc<int>> bfs01(Graph& G, vc<int> vs)\
    \ {\n  assert(G.is_prepared());\n  int N = G.N;\n  vc<ll> dist(N, -1);\n  vc<int>\
    \ par(N, -1);\n  vc<int> root(N, -1);\n  deque<int> que;\n\n  for (auto&& v: vs)\
    \ {\n    dist[v] = 0;\n    root[v] = v;\n    que.push_front(v);\n  }\n\n  while\
    \ (!que.empty()) {\n    auto v = que.front();\n    que.pop_front();\n    for (auto&&\
    \ e: G[v]) {\n      if (dist[e.to] == -1 || dist[e.to] > dist[e.frm] + e.cost)\
    \ {\n        dist[e.to] = dist[e.frm] + e.cost;\n        root[e.to] = root[e.frm];\n\
    \        par[e.to] = e.frm;\n        if (e.cost == 0)\n          que.push_front(e.to);\n\
    \        else\n          que.push_back(e.to);\n      }\n    }\n  }\n  return {dist,\
    \ par, root};\n}\n#line 1 \"graph/shortest_path/restore_path.hpp\"\nvector<int>\
    \ restore_path(vector<int> par, int t){\r\n  vector<int> pth = {t};\r\n  while\
    \ (par[pth.back()] != -1) pth.eb(par[pth.back()]);\r\n  reverse(all(pth));\r\n\
    \  return pth;\r\n}\n#line 3 \"graph/tree_diameter.hpp\"\n\r\ntemplate <typename\
    \ T>\r\npair<T, vc<int>> tree_diameter(Graph<T>& G) {\r\n  assert(G.is_prepared());\r\
    \n  int A, B;\r\n  {\r\n    auto [dist, par] = bfs01<decltype(G), T>(G, 0);\r\n\
    \    A = max_element(all(dist)) - dist.begin();\r\n  }\r\n  auto [dist, par] =\
    \ bfs01<decltype(G), T>(G, A);\r\n  B = max_element(all(dist)) - dist.begin();\r\
    \n  vc<int> P = restore_path(par, B);\r\n  return {dist[B], P};\r\n}\r\n"
  code: "#include \"graph/shortest_path/bfs01.hpp\"\r\n#include \"graph/shortest_path/restore_path.hpp\"\
    \r\n\r\ntemplate <typename T>\r\npair<T, vc<int>> tree_diameter(Graph<T>& G) {\r\
    \n  assert(G.is_prepared());\r\n  int A, B;\r\n  {\r\n    auto [dist, par] = bfs01<decltype(G),\
    \ T>(G, 0);\r\n    A = max_element(all(dist)) - dist.begin();\r\n  }\r\n  auto\
    \ [dist, par] = bfs01<decltype(G), T>(G, A);\r\n  B = max_element(all(dist)) -\
    \ dist.begin();\r\n  vc<int> P = restore_path(par, B);\r\n  return {dist[B], P};\r\
    \n}\r\n"
  dependsOn:
  - graph/shortest_path/bfs01.hpp
  - graph/base.hpp
  - graph/shortest_path/restore_path.hpp
  isVerificationFile: false
  path: graph/tree_diameter.hpp
  requiredBy: []
  timestamp: '2022-12-05 10:41:25+09:00'
  verificationStatus: LIBRARY_ALL_WA
  verifiedWith:
  - test/library_checker/tree/tree_diameter.test.cpp
documentation_of: graph/tree_diameter.hpp
layout: document
redirect_from:
- /library/graph/tree_diameter.hpp
- /library/graph/tree_diameter.hpp.html
title: graph/tree_diameter.hpp
---
