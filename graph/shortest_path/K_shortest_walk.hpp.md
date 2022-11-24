---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: ds/pds/persistent_meldable_heap.hpp
    title: ds/pds/persistent_meldable_heap.hpp
  - icon: ':heavy_check_mark:'
    path: graph/base.hpp
    title: graph/base.hpp
  - icon: ':heavy_check_mark:'
    path: graph/reverse_graph.hpp
    title: graph/reverse_graph.hpp
  - icon: ':heavy_check_mark:'
    path: graph/shortest_path/dijkstra.hpp
    title: graph/shortest_path/dijkstra.hpp
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/library_checker/graph/K_shortest_walk.test.cpp
    title: test/library_checker/graph/K_shortest_walk.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 1 \"ds/pds/persistent_meldable_heap.hpp\"\n\ntemplate <typename\
    \ VAL, int NODES = 5'000'000>\nstruct Persistent_Meldable_Heap {\n  struct Node\
    \ {\n    Node *l, *r;\n    VAL x;\n    int s;\n  };\n\n  Node *pool;\n  int pid;\n\
    \n  Persistent_Meldable_Heap() : pid(0) { pool = new Node[NODES]; }\n\n  Node\
    \ *new_node(const VAL &x) {\n    pool[pid].l = pool[pid].r = nullptr;\n    pool[pid].x\
    \ = x;\n    pool[pid].s = 1;\n    return &(pool[pid++]);\n  }\n\n  Node *copy_node(Node\
    \ *a) {\n    if (!a) return a;\n    Node *b = new_node(a->x);\n    b->s = a->s;\n\
    \    b->l = a->l;\n    b->r = a->r;\n    return b;\n  }\n\n  Node *meld(Node *a,\
    \ Node *b) {\n    a = copy_node(a);\n    b = copy_node(b);\n    if (!a) return\
    \ b;\n    if (!b) return a;\n    if ((a->x) > (b->x)) swap(a, b);\n    a->r =\
    \ (a->r ? meld(a->r, b) : b);\n    if (!(a->l) || (a->l->s < a->r->s)) swap(a->l,\
    \ a->r);\n    a->s = (a->r ? a->r->s : 0) + 1;\n    return a;\n  }\n\n  Node *push(Node\
    \ *a, VAL x) { return meld(a, new_node(x)); }\n  Node *pop(Node *a) { return meld(a->l,\
    \ a->r); }\n  VAL top(Node *a) { return a->x; }\n\n  vc<VAL> collect(Node *a)\
    \ {\n    vc<VAL> A;\n    auto dfs = [&](auto &dfs, Node *a) -> void {\n      if\
    \ (!a) return;\n      A.eb(a->x);\n      dfs(dfs, a->l);\n      dfs(dfs, a->r);\n\
    \    };\n    dfs(dfs, a);\n    return A;\n  }\n};\n#line 2 \"graph/base.hpp\"\n\
    \ntemplate <typename T>\nstruct Edge {\n  int frm, to;\n  T cost;\n  int id;\n\
    };\n\ntemplate <typename T = int, bool directed = false>\nstruct Graph {\n  int\
    \ N, M;\n  using cost_type = T;\n  using edge_type = Edge<T>;\n  vector<edge_type>\
    \ edges;\n  vector<int> indptr;\n  vector<edge_type> csr_edges;\n  vc<int> vc_deg,\
    \ vc_indeg, vc_outdeg;\n  bool prepared;\n\n  class OutgoingEdges {\n  public:\n\
    \    OutgoingEdges(const Graph* G, int l, int r) : G(G), l(l), r(r) {}\n\n   \
    \ const edge_type* begin() const {\n      if (l == r) { return 0; }\n      return\
    \ &G->csr_edges[l];\n    }\n\n    const edge_type* end() const {\n      if (l\
    \ == r) { return 0; }\n      return &G->csr_edges[r];\n    }\n\n  private:\n \
    \   const Graph* G;\n    int l, r;\n  };\n\n  bool is_prepared() { return prepared;\
    \ }\n  constexpr bool is_directed() { return directed; }\n\n  Graph() : N(0),\
    \ M(0), prepared(0) {}\n  Graph(int N) : N(N), M(0), prepared(0) {}\n\n  void\
    \ resize(int n) { N = n; }\n\n  void add(int frm, int to, T cost = 1, int i =\
    \ -1) {\n    assert(!prepared);\n    assert(0 <= frm && 0 <= to && to < N);\n\
    \    if (i == -1) i = M;\n    auto e = edge_type({frm, to, cost, i});\n    edges.eb(e);\n\
    \    ++M;\n  }\n\n  // wt, off\n  void read_tree(bool wt = false, int off = 1)\
    \ { read_graph(N - 1, wt, off); }\n\n  void read_graph(int M, bool wt = false,\
    \ int off = 1) {\n    for (int m = 0; m < M; ++m) {\n      INT(a, b);\n      a\
    \ -= off, b -= off;\n      if (!wt) {\n        add(a, b);\n      } else {\n  \
    \      T c;\n        read(c);\n        add(a, b, c);\n      }\n    }\n    build();\n\
    \  }\n\n  void read_parent(int off = 1) {\n    for (int v = 1; v < N; ++v) {\n\
    \      INT(p);\n      p -= off;\n      add(p, v);\n    }\n    build();\n  }\n\n\
    \  void build() {\n    assert(!prepared);\n    prepared = true;\n    indptr.assign(N\
    \ + 1, 0);\n    for (auto&& e: edges) {\n      indptr[e.frm + 1]++;\n      if\
    \ (!directed) indptr[e.to + 1]++;\n    }\n    for (int v = 0; v < N; ++v) { indptr[v\
    \ + 1] += indptr[v]; }\n    auto counter = indptr;\n    csr_edges.resize(indptr.back()\
    \ + 1);\n    for (auto&& e: edges) {\n      csr_edges[counter[e.frm]++] = e;\n\
    \      if (!directed)\n        csr_edges[counter[e.to]++] = edge_type({e.to, e.frm,\
    \ e.cost, e.id});\n    }\n  }\n\n  OutgoingEdges operator[](int v) const {\n \
    \   assert(prepared);\n    return {this, indptr[v], indptr[v + 1]};\n  }\n\n \
    \ vc<int> deg_array() {\n    if (vc_deg.empty()) calc_deg();\n    return vc_deg;\n\
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
    \ {dist, par, root};\n}\n#line 2 \"graph/reverse_graph.hpp\"\n\r\ntemplate <typename\
    \ T>\r\nGraph<T, 1> reverse_graph(Graph<T, 1>& G) {\r\n  assert(G.is_directed());\r\
    \n  Graph<T, 1> G1(G.N);\r\n  for (auto&& e: G.edges) { G1.add(e.to, e.frm, e.cost,\
    \ e.id); }\r\n  G1.build();\r\n  return G1;\r\n}\r\n#line 4 \"graph/shortest_path/K_shortest_walk.hpp\"\
    \n\n// INF \u57CB\u3081\u3057\u3066\u5FC5\u305A\u9577\u3055 K \u306B\u3059\u308B\
    \ntemplate <typename T, typename GT>\nvc<T> K_shortest_walk(GT &G, int s, int\
    \ t, int K, T INF) {\n  assert(G.is_directed());\n  int N = G.N;\n  auto RG =\
    \ reverse_graph(G);\n  auto [dist, par] = dijkstra<ll, decltype(RG)>(RG, t, INF);\n\
    \  if (dist[s] == INF) { return vc<T>(K, INF); }\n\n  using P = pair<T, int>;\n\
    \  Persistent_Meldable_Heap<P> X;\n  using Node = typename Persistent_Meldable_Heap<P>::Node;\n\
    \  vc<Node *> nodes(N, nullptr);\n\n  vc<bool> vis(N);\n  vc<int> st = {t};\n\
    \  vis[t] = 1;\n  while (len(st)) {\n    int v = pick(st);\n    bool done = 0;\n\
    \    for (auto &&e: G[v]) {\n      if (dist[e.to] == INF) continue;\n      if\
    \ (!done && par[v] == e.to && dist[v] == dist[e.to] + e.cost) {\n        done\
    \ = 1;\n        continue;\n      }\n      T cost = -dist[v] + e.cost + dist[e.to];\n\
    \      nodes[v] = X.push(nodes[v], {cost, e.to});\n    }\n    for (auto &&e: RG[v])\
    \ {\n      if (vis[e.to]) continue;\n      if (par[e.to] == v) {\n        nodes[e.to]\
    \ = X.meld(nodes[e.to], nodes[v]);\n        vis[e.to] = 1;\n        st.eb(e.to);\n\
    \      }\n    }\n  }\n\n  ll base = dist[s];\n  vc<ll> ANS = {base};\n  if (nodes[s])\
    \ {\n    using PAIR = pair<ll, Node *>;\n    auto comp = [](auto a, auto b) {\
    \ return a.fi > b.fi; };\n    priority_queue<PAIR, vc<PAIR>, decltype(comp)> que(comp);\n\
    \    que.emplace(base + X.top(nodes[s]).fi, nodes[s]);\n    while (len(ANS) <\
    \ K && len(que)) {\n      auto [d, n] = que.top();\n      que.pop();\n      ANS.eb(d);\n\
    \      if (n->l) que.emplace(d + (n->l->x.fi) - (n->x.fi), n->l);\n      if (n->r)\
    \ que.emplace(d + (n->r->x.fi) - (n->x.fi), n->r);\n      Node *m = nodes[n->x.se];\n\
    \      if (m) { que.emplace(d + m->x.fi, m); }\n    }\n  }\n  while (len(ANS)\
    \ < K) ANS.eb(INF);\n  return ANS;\n}\n"
  code: "#include \"ds/pds/persistent_meldable_heap.hpp\"\n#include \"graph/shortest_path/dijkstra.hpp\"\
    \n#include \"graph/reverse_graph.hpp\"\n\n// INF \u57CB\u3081\u3057\u3066\u5FC5\
    \u305A\u9577\u3055 K \u306B\u3059\u308B\ntemplate <typename T, typename GT>\n\
    vc<T> K_shortest_walk(GT &G, int s, int t, int K, T INF) {\n  assert(G.is_directed());\n\
    \  int N = G.N;\n  auto RG = reverse_graph(G);\n  auto [dist, par] = dijkstra<ll,\
    \ decltype(RG)>(RG, t, INF);\n  if (dist[s] == INF) { return vc<T>(K, INF); }\n\
    \n  using P = pair<T, int>;\n  Persistent_Meldable_Heap<P> X;\n  using Node =\
    \ typename Persistent_Meldable_Heap<P>::Node;\n  vc<Node *> nodes(N, nullptr);\n\
    \n  vc<bool> vis(N);\n  vc<int> st = {t};\n  vis[t] = 1;\n  while (len(st)) {\n\
    \    int v = pick(st);\n    bool done = 0;\n    for (auto &&e: G[v]) {\n     \
    \ if (dist[e.to] == INF) continue;\n      if (!done && par[v] == e.to && dist[v]\
    \ == dist[e.to] + e.cost) {\n        done = 1;\n        continue;\n      }\n \
    \     T cost = -dist[v] + e.cost + dist[e.to];\n      nodes[v] = X.push(nodes[v],\
    \ {cost, e.to});\n    }\n    for (auto &&e: RG[v]) {\n      if (vis[e.to]) continue;\n\
    \      if (par[e.to] == v) {\n        nodes[e.to] = X.meld(nodes[e.to], nodes[v]);\n\
    \        vis[e.to] = 1;\n        st.eb(e.to);\n      }\n    }\n  }\n\n  ll base\
    \ = dist[s];\n  vc<ll> ANS = {base};\n  if (nodes[s]) {\n    using PAIR = pair<ll,\
    \ Node *>;\n    auto comp = [](auto a, auto b) { return a.fi > b.fi; };\n    priority_queue<PAIR,\
    \ vc<PAIR>, decltype(comp)> que(comp);\n    que.emplace(base + X.top(nodes[s]).fi,\
    \ nodes[s]);\n    while (len(ANS) < K && len(que)) {\n      auto [d, n] = que.top();\n\
    \      que.pop();\n      ANS.eb(d);\n      if (n->l) que.emplace(d + (n->l->x.fi)\
    \ - (n->x.fi), n->l);\n      if (n->r) que.emplace(d + (n->r->x.fi) - (n->x.fi),\
    \ n->r);\n      Node *m = nodes[n->x.se];\n      if (m) { que.emplace(d + m->x.fi,\
    \ m); }\n    }\n  }\n  while (len(ANS) < K) ANS.eb(INF);\n  return ANS;\n}\n"
  dependsOn:
  - ds/pds/persistent_meldable_heap.hpp
  - graph/shortest_path/dijkstra.hpp
  - graph/base.hpp
  - graph/reverse_graph.hpp
  isVerificationFile: false
  path: graph/shortest_path/K_shortest_walk.hpp
  requiredBy: []
  timestamp: '2022-11-24 17:14:47+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/library_checker/graph/K_shortest_walk.test.cpp
documentation_of: graph/shortest_path/K_shortest_walk.hpp
layout: document
redirect_from:
- /library/graph/shortest_path/K_shortest_walk.hpp
- /library/graph/shortest_path/K_shortest_walk.hpp.html
title: graph/shortest_path/K_shortest_walk.hpp
---
