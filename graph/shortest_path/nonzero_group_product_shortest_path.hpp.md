---
data:
  _extendedDependsOn:
  - icon: ':question:'
    path: graph/base.hpp
    title: graph/base.hpp
  - icon: ':question:'
    path: graph/shortest_path/dijkstra.hpp
    title: graph/shortest_path/dijkstra.hpp
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/3_yukicoder/1602.test.cpp
    title: test/3_yukicoder/1602.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links:
    - https://arxiv.org/abs/1906.04062
  bundledCode: "#line 1 \"graph/shortest_path/nonzero_group_product_shortest_path.hpp\"\
    \n\n#line 2 \"graph/base.hpp\"\n\ntemplate <typename T>\nstruct Edge {\n  int\
    \ frm, to;\n  T cost;\n  int id;\n};\n\ntemplate <typename T = int, bool directed\
    \ = false>\nstruct Graph {\n  static constexpr bool is_directed = directed;\n\
    \  int N, M;\n  using cost_type = T;\n  using edge_type = Edge<T>;\n  vector<edge_type>\
    \ edges;\n  vector<int> indptr;\n  vector<edge_type> csr_edges;\n  vc<int> vc_deg,\
    \ vc_indeg, vc_outdeg;\n  bool prepared;\n\n  class OutgoingEdges {\n  public:\n\
    \    OutgoingEdges(const Graph* G, int l, int r) : G(G), l(l), r(r) {}\n\n   \
    \ const edge_type* begin() const {\n      if (l == r) { return 0; }\n      return\
    \ &G->csr_edges[l];\n    }\n\n    const edge_type* end() const {\n      if (l\
    \ == r) { return 0; }\n      return &G->csr_edges[r];\n    }\n\n  private:\n \
    \   const Graph* G;\n    int l, r;\n  };\n\n  bool is_prepared() { return prepared;\
    \ }\n\n  Graph() : N(0), M(0), prepared(0) {}\n  Graph(int N) : N(N), M(0), prepared(0)\
    \ {}\n\n  void build(int n) {\n    N = n, M = 0;\n    prepared = 0;\n    edges.clear();\n\
    \    indptr.clear();\n    csr_edges.clear();\n    vc_deg.clear();\n    vc_indeg.clear();\n\
    \    vc_outdeg.clear();\n  }\n\n  void add(int frm, int to, T cost = 1, int i\
    \ = -1) {\n    assert(!prepared);\n    assert(0 <= frm && 0 <= to && to < N);\n\
    \    if (i == -1) i = M;\n    auto e = edge_type({frm, to, cost, i});\n    edges.eb(e);\n\
    \    ++M;\n  }\n\n#ifdef FASTIO\n  // wt, off\n  void read_tree(bool wt = false,\
    \ int off = 1) { read_graph(N - 1, wt, off); }\n\n  void read_graph(int M, bool\
    \ wt = false, int off = 1) {\n    for (int m = 0; m < M; ++m) {\n      INT(a,\
    \ b);\n      a -= off, b -= off;\n      if (!wt) {\n        add(a, b);\n     \
    \ } else {\n        T c;\n        read(c);\n        add(a, b, c);\n      }\n \
    \   }\n    build();\n  }\n#endif\n\n  void build() {\n    assert(!prepared);\n\
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
    \n#ifdef FASTIO\n  void debug() {\n    print(\"Graph\");\n    if (!prepared) {\n\
    \      print(\"frm to cost id\");\n      for (auto&& e: edges) print(e.frm, e.to,\
    \ e.cost, e.id);\n    } else {\n      print(\"indptr\", indptr);\n      print(\"\
    frm to cost id\");\n      FOR(v, N) for (auto&& e: (*this)[v]) print(e.frm, e.to,\
    \ e.cost, e.id);\n    }\n  }\n#endif\n\n  vc<int> new_idx;\n  vc<bool> used_e;\n\
    \n  // G \u306B\u304A\u3051\u308B\u9802\u70B9 V[i] \u304C\u3001\u65B0\u3057\u3044\
    \u30B0\u30E9\u30D5\u3067 i \u306B\u306A\u308B\u3088\u3046\u306B\u3059\u308B\n\
    \  // {G, es}\n  // sum(deg(v)) \u306E\u8A08\u7B97\u91CF\u306B\u306A\u3063\u3066\
    \u3044\u3066\u3001\n  // \u65B0\u3057\u3044\u30B0\u30E9\u30D5\u306E n+m \u3088\
    \u308A\u5927\u304D\u3044\u53EF\u80FD\u6027\u304C\u3042\u308B\u306E\u3067\u6CE8\
    \u610F\n  Graph<T, directed> rearrange(vc<int> V, bool keep_eid = 0) {\n    if\
    \ (len(new_idx) != N) new_idx.assign(N, -1);\n    int n = len(V);\n    FOR(i,\
    \ n) new_idx[V[i]] = i;\n    Graph<T, directed> G(n);\n    vc<int> history;\n\
    \    FOR(i, n) {\n      for (auto&& e: (*this)[V[i]]) {\n        if (len(used_e)\
    \ <= e.id) used_e.resize(e.id + 1);\n        if (used_e[e.id]) continue;\n   \
    \     int a = e.frm, b = e.to;\n        if (new_idx[a] != -1 && new_idx[b] !=\
    \ -1) {\n          history.eb(e.id);\n          used_e[e.id] = 1;\n          int\
    \ eid = (keep_eid ? e.id : -1);\n          G.add(new_idx[a], new_idx[b], e.cost,\
    \ eid);\n        }\n      }\n    }\n    FOR(i, n) new_idx[V[i]] = -1;\n    for\
    \ (auto&& eid: history) used_e[eid] = 0;\n    G.build();\n    return G;\n  }\n\
    \n  Graph<T, true> to_directed_tree(int root = -1) {\n    if (root == -1) root\
    \ = 0;\n    assert(!is_directed && prepared && M == N - 1);\n    Graph<T, true>\
    \ G1(N);\n    vc<int> par(N, -1);\n    auto dfs = [&](auto& dfs, int v) -> void\
    \ {\n      for (auto& e: (*this)[v]) {\n        if (e.to == par[v]) continue;\n\
    \        par[e.to] = v, dfs(dfs, e.to);\n      }\n    };\n    dfs(dfs, root);\n\
    \    for (auto& e: edges) {\n      int a = e.frm, b = e.to;\n      if (par[a]\
    \ == b) swap(a, b);\n      assert(par[b] == a);\n      G1.add(a, b, e.cost);\n\
    \    }\n    G1.build();\n    return G1;\n  }\n\nprivate:\n  void calc_deg() {\n\
    \    assert(vc_deg.empty());\n    vc_deg.resize(N);\n    for (auto&& e: edges)\
    \ vc_deg[e.frm]++, vc_deg[e.to]++;\n  }\n\n  void calc_deg_inout() {\n    assert(vc_indeg.empty());\n\
    \    vc_indeg.resize(N);\n    vc_outdeg.resize(N);\n    for (auto&& e: edges)\
    \ { vc_indeg[e.to]++, vc_outdeg[e.frm]++; }\n  }\n};\n#line 3 \"graph/shortest_path/dijkstra.hpp\"\
    \n\ntemplate <typename T, typename GT>\npair<vc<T>, vc<int>> dijkstra_dense(GT&\
    \ G, int s) {\n  const int N = G.N;\n  vc<T> dist(N, infty<T>);\n  vc<int> par(N,\
    \ -1);\n  vc<bool> done(N);\n  dist[s] = 0;\n  while (1) {\n    int v = -1;\n\
    \    T mi = infty<T>;\n    FOR(i, N) {\n      if (!done[i] && chmin(mi, dist[i]))\
    \ v = i;\n    }\n    if (v == -1) break;\n    done[v] = 1;\n    for (auto&& e:\
    \ G[v]) {\n      if (chmin(dist[e.to], dist[v] + e.cost)) par[e.to] = v;\n   \
    \ }\n  }\n  return {dist, par};\n}\n\ntemplate <typename T, typename GT, bool\
    \ DENSE = false>\npair<vc<T>, vc<int>> dijkstra(GT& G, int v) {\n  if (DENSE)\
    \ return dijkstra_dense<T>(G, v);\n  auto N = G.N;\n  vector<T> dist(N, infty<T>);\n\
    \  vector<int> par(N, -1);\n  using P = pair<T, int>;\n\n  priority_queue<P, vector<P>,\
    \ greater<P>> que;\n\n  dist[v] = 0;\n  que.emplace(0, v);\n  while (!que.empty())\
    \ {\n    auto [dv, v] = que.top();\n    que.pop();\n    if (dv > dist[v]) continue;\n\
    \    for (auto&& e: G[v]) {\n      if (chmin(dist[e.to], dist[e.frm] + e.cost))\
    \ {\n        par[e.to] = e.frm;\n        que.emplace(dist[e.to], e.to);\n    \
    \  }\n    }\n  }\n  return {dist, par};\n}\n\n// \u591A\u70B9\u30B9\u30BF\u30FC\
    \u30C8\u3002[dist, par, root]\ntemplate <typename T, typename GT>\ntuple<vc<T>,\
    \ vc<int>, vc<int>> dijkstra(GT& G, vc<int> vs) {\n  assert(G.is_prepared());\n\
    \  int N = G.N;\n  vc<T> dist(N, infty<T>);\n  vc<int> par(N, -1);\n  vc<int>\
    \ root(N, -1);\n\n  using P = pair<T, int>;\n\n  priority_queue<P, vector<P>,\
    \ greater<P>> que;\n\n  for (auto&& v: vs) {\n    dist[v] = 0;\n    root[v] =\
    \ v;\n    que.emplace(T(0), v);\n  }\n\n  while (!que.empty()) {\n    auto [dv,\
    \ v] = que.top();\n    que.pop();\n    if (dv > dist[v]) continue;\n    for (auto&&\
    \ e: G[v]) {\n      if (chmin(dist[e.to], dist[e.frm] + e.cost)) {\n        root[e.to]\
    \ = root[e.frm];\n        par[e.to] = e.frm;\n        que.push(mp(dist[e.to],\
    \ e.to));\n      }\n    }\n  }\n  return {dist, par, root};\n}\n#line 4 \"graph/shortest_path/nonzero_group_product_shortest_path.hpp\"\
    \n\n// given: group-labeled undirected graph G, and s.\n// return: shortest path\
    \ length from s to v, for each v.\n// remark: path is not a walk. directed case\
    \ is NP hard.\n// https://arxiv.org/abs/1906.04062\ntemplate <typename WT, typename\
    \ Monoid, typename GT>\nvc<WT> nonzero_group_product_shortest_path(\n    GT& G,\
    \ vc<typename Monoid::value_type> edge_label, int s) {\n  static_assert(!GT::is_directed);\n\
    \  const int N = G.N, M = G.M;\n\n  using X = typename Monoid::value_type;\n\n\
    \  auto get = [&](int eid, int frm) -> X {\n    auto& e = G.edges[eid];\n    X\
    \ x = edge_label[e.id];\n    return (e.frm == frm ? x : Monoid::inverse(x));\n\
    \  };\n\n  // shortest path tree\n  vc<WT> dist(N, infty<WT>);\n  vc<X> phi(N,\
    \ Monoid::unit());\n  vc<int> par(N, -1);\n  vc<int> depth(N);\n  dist[s] = 0;\n\
    \  pqg<pair<WT, int>> que;\n  que.emplace(0, s);\n  while (len(que)) {\n    auto\
    \ [dv, v] = POP(que);\n    if (dv != dist[v]) continue;\n    for (auto& e: G[v])\
    \ {\n      if (chmin(dist[e.to], dv + e.cost)) {\n        phi[e.to] = Monoid::op(phi[v],\
    \ get(e.id, v));\n        que.emplace(dist[e.to], e.to);\n        par[e.to] =\
    \ v, depth[e.to] = depth[v] + 1;\n      }\n    }\n  }\n\n  vc<bool> cons(M);\n\
    \  FOR(i, M) {\n    int a = G.edges[i].frm, b = G.edges[i].to;\n    X x = Monoid::op(phi[a],\
    \ edge_label[i]);\n    cons[i] = (x == phi[b]);\n  }\n\n  vc<WT> h(M, infty<WT>);\n\
    \  vc<WT> q(N, infty<WT>);\n  for (auto& e: G.edges) {\n    if (dist[e.frm] ==\
    \ infty<WT>) continue;\n    if (!cons[e.id] && chmin(h[e.id], dist[e.frm] + dist[e.to]\
    \ + e.cost)) {\n      que.emplace(h[e.id], e.id);\n    }\n  }\n\n  vc<int> root(N);\n\
    \  FOR(v, N) root[v] = v;\n\n  auto get_root = [&](int v) -> int {\n    while\
    \ (root[v] != v) { v = root[v] = root[root[v]]; }\n    return v;\n  };\n\n  while\
    \ (len(que)) {\n    auto [x, eid] = POP(que);\n    if (x != h[eid]) continue;\n\
    \    int a = G.edges[eid].frm, b = G.edges[eid].to;\n    a = get_root(a), b =\
    \ get_root(b);\n    vc<int> B;\n    while (a != b) {\n      if (depth[a] < depth[b])\
    \ swap(a, b);\n      B.eb(a), a = get_root(par[a]);\n    }\n    for (auto& w:\
    \ B) {\n      root[w] = a, q[w] = x - dist[w];\n      for (auto& e: G[w]) {\n\
    \        if (cons[e.id] && chmin(h[e.id], q[w] + dist[e.to] + e.cost)) {\n   \
    \       que.emplace(h[e.id], e.id);\n        }\n      }\n    }\n  }\n\n  vc<WT>\
    \ ANS(N, infty<WT>);\n  FOR(v, N) ANS[v] = (phi[v] == Monoid::unit() ? q[v] :\
    \ dist[v]);\n  return ANS;\n}\n"
  code: "\n#include \"graph/base.hpp\"\n#include \"graph/shortest_path/dijkstra.hpp\"\
    \n\n// given: group-labeled undirected graph G, and s.\n// return: shortest path\
    \ length from s to v, for each v.\n// remark: path is not a walk. directed case\
    \ is NP hard.\n// https://arxiv.org/abs/1906.04062\ntemplate <typename WT, typename\
    \ Monoid, typename GT>\nvc<WT> nonzero_group_product_shortest_path(\n    GT& G,\
    \ vc<typename Monoid::value_type> edge_label, int s) {\n  static_assert(!GT::is_directed);\n\
    \  const int N = G.N, M = G.M;\n\n  using X = typename Monoid::value_type;\n\n\
    \  auto get = [&](int eid, int frm) -> X {\n    auto& e = G.edges[eid];\n    X\
    \ x = edge_label[e.id];\n    return (e.frm == frm ? x : Monoid::inverse(x));\n\
    \  };\n\n  // shortest path tree\n  vc<WT> dist(N, infty<WT>);\n  vc<X> phi(N,\
    \ Monoid::unit());\n  vc<int> par(N, -1);\n  vc<int> depth(N);\n  dist[s] = 0;\n\
    \  pqg<pair<WT, int>> que;\n  que.emplace(0, s);\n  while (len(que)) {\n    auto\
    \ [dv, v] = POP(que);\n    if (dv != dist[v]) continue;\n    for (auto& e: G[v])\
    \ {\n      if (chmin(dist[e.to], dv + e.cost)) {\n        phi[e.to] = Monoid::op(phi[v],\
    \ get(e.id, v));\n        que.emplace(dist[e.to], e.to);\n        par[e.to] =\
    \ v, depth[e.to] = depth[v] + 1;\n      }\n    }\n  }\n\n  vc<bool> cons(M);\n\
    \  FOR(i, M) {\n    int a = G.edges[i].frm, b = G.edges[i].to;\n    X x = Monoid::op(phi[a],\
    \ edge_label[i]);\n    cons[i] = (x == phi[b]);\n  }\n\n  vc<WT> h(M, infty<WT>);\n\
    \  vc<WT> q(N, infty<WT>);\n  for (auto& e: G.edges) {\n    if (dist[e.frm] ==\
    \ infty<WT>) continue;\n    if (!cons[e.id] && chmin(h[e.id], dist[e.frm] + dist[e.to]\
    \ + e.cost)) {\n      que.emplace(h[e.id], e.id);\n    }\n  }\n\n  vc<int> root(N);\n\
    \  FOR(v, N) root[v] = v;\n\n  auto get_root = [&](int v) -> int {\n    while\
    \ (root[v] != v) { v = root[v] = root[root[v]]; }\n    return v;\n  };\n\n  while\
    \ (len(que)) {\n    auto [x, eid] = POP(que);\n    if (x != h[eid]) continue;\n\
    \    int a = G.edges[eid].frm, b = G.edges[eid].to;\n    a = get_root(a), b =\
    \ get_root(b);\n    vc<int> B;\n    while (a != b) {\n      if (depth[a] < depth[b])\
    \ swap(a, b);\n      B.eb(a), a = get_root(par[a]);\n    }\n    for (auto& w:\
    \ B) {\n      root[w] = a, q[w] = x - dist[w];\n      for (auto& e: G[w]) {\n\
    \        if (cons[e.id] && chmin(h[e.id], q[w] + dist[e.to] + e.cost)) {\n   \
    \       que.emplace(h[e.id], e.id);\n        }\n      }\n    }\n  }\n\n  vc<WT>\
    \ ANS(N, infty<WT>);\n  FOR(v, N) ANS[v] = (phi[v] == Monoid::unit() ? q[v] :\
    \ dist[v]);\n  return ANS;\n}"
  dependsOn:
  - graph/base.hpp
  - graph/shortest_path/dijkstra.hpp
  isVerificationFile: false
  path: graph/shortest_path/nonzero_group_product_shortest_path.hpp
  requiredBy: []
  timestamp: '2024-05-29 22:32:29+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/3_yukicoder/1602.test.cpp
documentation_of: graph/shortest_path/nonzero_group_product_shortest_path.hpp
layout: document
redirect_from:
- /library/graph/shortest_path/nonzero_group_product_shortest_path.hpp
- /library/graph/shortest_path/nonzero_group_product_shortest_path.hpp.html
title: graph/shortest_path/nonzero_group_product_shortest_path.hpp
---
