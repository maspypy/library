---
data:
  _extendedDependsOn:
  - icon: ':question:'
    path: graph/base.hpp
    title: graph/base.hpp
  - icon: ':question:'
    path: graph/strongly_connected_component.hpp
    title: graph/strongly_connected_component.hpp
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':warning:'
  attributes:
    links:
    - https://yukicoder.me/problems/no/1436
  bundledCode: "#line 2 \"graph/base.hpp\"\n\ntemplate <typename T>\nstruct Edge {\n\
    \  int frm, to;\n  T cost;\n  int id;\n};\n\ntemplate <typename T = int, bool\
    \ directed = false>\nstruct Graph {\n  static constexpr bool is_directed = directed;\n\
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
    \    ++M;\n  }\n\n  // wt, off\n  void read_tree(bool wt = false, int off = 1)\
    \ { read_graph(N - 1, wt, off); }\n\n  void read_graph(int M, bool wt = false,\
    \ int off = 1) {\n    for (int m = 0; m < M; ++m) {\n      INT(a, b);\n      a\
    \ -= off, b -= off;\n      if (!wt) {\n        add(a, b);\n      } else {\n  \
    \      T c;\n        read(c);\n        add(a, b, c);\n      }\n    }\n    build();\n\
    \  }\n\n  void build() {\n    assert(!prepared);\n    prepared = true;\n    indptr.assign(N\
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
    \ print(e.frm, e.to, e.cost, e.id);\n    }\n  }\n\n  vc<int> new_idx;\n  vc<bool>\
    \ used_e;\n\n  // G \u306B\u304A\u3051\u308B\u9802\u70B9 V[i] \u304C\u3001\u65B0\
    \u3057\u3044\u30B0\u30E9\u30D5\u3067 i \u306B\u306A\u308B\u3088\u3046\u306B\u3059\
    \u308B\n  // {G, es}\n  pair<Graph<T, directed>, vc<int>> rearrange(vc<int> V)\
    \ {\n    if (len(new_idx) != N) new_idx.assign(N, -1);\n    if (len(used_e) !=\
    \ M) used_e.assign(M, 0);\n    int n = len(V);\n    FOR(i, n) new_idx[V[i]] =\
    \ i;\n    Graph<T, directed> G(n);\n    vc<int> es;\n    FOR(i, n) {\n      for\
    \ (auto&& e: (*this)[V[i]]) {\n        if (used_e[e.id]) continue;\n        int\
    \ a = e.frm, b = e.to;\n        if (new_idx[a] != -1 && new_idx[b] != -1) {\n\
    \          used_e[e.id] = 1;\n          G.add(new_idx[a], new_idx[b], e.cost);\n\
    \          es.eb(e.id);\n        }\n      }\n    }\n    FOR(i, n) new_idx[V[i]]\
    \ = -1;\n    for (auto&& eid: es) used_e[eid] = 0;\n    G.build();\n    return\
    \ {G, es};\n  }\n\nprivate:\n  void calc_deg() {\n    assert(vc_deg.empty());\n\
    \    vc_deg.resize(N);\n    for (auto&& e: edges) vc_deg[e.frm]++, vc_deg[e.to]++;\n\
    \  }\n\n  void calc_deg_inout() {\n    assert(vc_indeg.empty());\n    vc_indeg.resize(N);\n\
    \    vc_outdeg.resize(N);\n    for (auto&& e: edges) { vc_indeg[e.to]++, vc_outdeg[e.frm]++;\
    \ }\n  }\n};\n#line 3 \"graph/strongly_connected_component.hpp\"\n\ntemplate <typename\
    \ GT>\npair<int, vc<int>> strongly_connected_component(GT& G) {\n  static_assert(GT::is_directed);\n\
    \  assert(G.is_prepared());\n  int N = G.N;\n  int C = 0;\n  vc<int> comp(N),\
    \ low(N), ord(N, -1), path;\n  int now = 0;\n\n  auto dfs = [&](auto& dfs, int\
    \ v) -> void {\n    low[v] = ord[v] = now++;\n    path.eb(v);\n    for (auto&&\
    \ [frm, to, cost, id]: G[v]) {\n      if (ord[to] == -1) {\n        dfs(dfs, to),\
    \ chmin(low[v], low[to]);\n      } else {\n        chmin(low[v], ord[to]);\n \
    \     }\n    }\n    if (low[v] == ord[v]) {\n      while (1) {\n        int u\
    \ = POP(path);\n        ord[u] = N, comp[u] = C;\n        if (u == v) break;\n\
    \      }\n      ++C;\n    }\n  };\n  FOR(v, N) {\n    if (ord[v] == -1) dfs(dfs,\
    \ v);\n  }\n  FOR(v, N) comp[v] = C - 1 - comp[v];\n  return {C, comp};\n}\n\n\
    template <typename GT>\nGraph<int, 1> scc_dag(GT& G, int C, vc<int>& comp) {\n\
    \  Graph<int, 1> DAG(C);\n  vvc<int> edges(C);\n  for (auto&& e: G.edges) {\n\
    \    int x = comp[e.frm], y = comp[e.to];\n    if (x == y) continue;\n    edges[x].eb(y);\n\
    \  }\n  FOR(c, C) {\n    UNIQUE(edges[c]);\n    for (auto&& to: edges[c]) DAG.add(c,\
    \ to);\n  }\n  DAG.build();\n  return DAG;\n}\n#line 2 \"graph/find_odd_cycle.hpp\"\
    \n\n// (vs, es)\n// https://yukicoder.me/problems/no/1436\ntemplate <typename\
    \ GT>\npair<vc<int>, vc<int>> find_odd_cycle(GT& G) {\n  int N = G.N;\n  vc<int>\
    \ comp(N);\n  if constexpr (GT::is_directed) {\n    comp = strongly_connected_component<GT>(G).se;\n\
    \  }\n  vc<int> dist(2 * N, infty<int>);\n  vc<int> par(2 * N, -1); // edge index\n\
    \  deque<int> que;\n  auto add = [&](int v, int d, int p) -> void {\n    if (chmin(dist[v],\
    \ d)) { que.eb(v), par[v] = p; }\n  };\n  FOR(root, N) {\n    if (dist[2 * root\
    \ + 0] < infty<int>) continue;\n    if (dist[2 * root + 1] < infty<int>) continue;\n\
    \    add(2 * root, 0, -1);\n    while (len(que)) {\n      auto v = POP(que);\n\
    \      auto [a, b] = divmod(v, 2);\n      for (auto&& e: G[a]) {\n        if (comp[e.frm]\
    \ != comp[e.to]) continue;\n        int w = 2 * e.to + (b ^ 1);\n        add(w,\
    \ dist[v] + 1, e.id);\n      }\n    }\n    if (dist[2 * root + 1] == infty<int>)\
    \ continue;\n    // found\n    vc<int> edges;\n    vc<int> vs;\n    vs.eb(root);\n\
    \    int v = 2 * root + 1;\n    while (par[v] != -1) {\n      int i = par[v];\n\
    \      edges.eb(i);\n      auto& e = G.edges[i];\n      v = 2 * (e.frm + e.to)\
    \ + 1 - v;\n      vs.eb(v / 2);\n    }\n    reverse(all(edges));\n    reverse(all(vs));\n\
    \    // walk -> cycle\n    vc<int> used(N, -1);\n    int l = -1, r = -1;\n   \
    \ FOR(i, len(vs)) {\n      if (used[vs[i]] == -1) {\n        used[vs[i]] = i;\n\
    \        continue;\n      }\n      l = used[vs[i]];\n      r = i;\n      break;\n\
    \    }\n    assert(l != -1);\n    vs = {vs.begin() + l, vs.begin() + r};\n   \
    \ edges = {edges.begin() + l, edges.begin() + r};\n    vs.eb(vs[0]);\n    return\
    \ {vs, edges};\n  }\n  return {};\n}\n"
  code: "#include \"graph/strongly_connected_component.hpp\"\n\n// (vs, es)\n// https://yukicoder.me/problems/no/1436\n\
    template <typename GT>\npair<vc<int>, vc<int>> find_odd_cycle(GT& G) {\n  int\
    \ N = G.N;\n  vc<int> comp(N);\n  if constexpr (GT::is_directed) {\n    comp =\
    \ strongly_connected_component<GT>(G).se;\n  }\n  vc<int> dist(2 * N, infty<int>);\n\
    \  vc<int> par(2 * N, -1); // edge index\n  deque<int> que;\n  auto add = [&](int\
    \ v, int d, int p) -> void {\n    if (chmin(dist[v], d)) { que.eb(v), par[v] =\
    \ p; }\n  };\n  FOR(root, N) {\n    if (dist[2 * root + 0] < infty<int>) continue;\n\
    \    if (dist[2 * root + 1] < infty<int>) continue;\n    add(2 * root, 0, -1);\n\
    \    while (len(que)) {\n      auto v = POP(que);\n      auto [a, b] = divmod(v,\
    \ 2);\n      for (auto&& e: G[a]) {\n        if (comp[e.frm] != comp[e.to]) continue;\n\
    \        int w = 2 * e.to + (b ^ 1);\n        add(w, dist[v] + 1, e.id);\n   \
    \   }\n    }\n    if (dist[2 * root + 1] == infty<int>) continue;\n    // found\n\
    \    vc<int> edges;\n    vc<int> vs;\n    vs.eb(root);\n    int v = 2 * root +\
    \ 1;\n    while (par[v] != -1) {\n      int i = par[v];\n      edges.eb(i);\n\
    \      auto& e = G.edges[i];\n      v = 2 * (e.frm + e.to) + 1 - v;\n      vs.eb(v\
    \ / 2);\n    }\n    reverse(all(edges));\n    reverse(all(vs));\n    // walk ->\
    \ cycle\n    vc<int> used(N, -1);\n    int l = -1, r = -1;\n    FOR(i, len(vs))\
    \ {\n      if (used[vs[i]] == -1) {\n        used[vs[i]] = i;\n        continue;\n\
    \      }\n      l = used[vs[i]];\n      r = i;\n      break;\n    }\n    assert(l\
    \ != -1);\n    vs = {vs.begin() + l, vs.begin() + r};\n    edges = {edges.begin()\
    \ + l, edges.begin() + r};\n    vs.eb(vs[0]);\n    return {vs, edges};\n  }\n\
    \  return {};\n}"
  dependsOn:
  - graph/strongly_connected_component.hpp
  - graph/base.hpp
  isVerificationFile: false
  path: graph/find_odd_cycle.hpp
  requiredBy: []
  timestamp: '2023-11-03 12:23:39+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: graph/find_odd_cycle.hpp
layout: document
redirect_from:
- /library/graph/find_odd_cycle.hpp
- /library/graph/find_odd_cycle.hpp.html
title: graph/find_odd_cycle.hpp
---
