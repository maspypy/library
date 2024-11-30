---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: graph/base.hpp
    title: graph/base.hpp
  - icon: ':heavy_check_mark:'
    path: graph/blackbox/complement_graph_bfs.hpp
    title: graph/blackbox/complement_graph_bfs.hpp
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':warning:'
  attributes:
    links: []
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
    \ { vc_indeg[e.to]++, vc_outdeg[e.frm]++; }\n  }\n};\n#line 2 \"graph/blackbox/complement_graph_bfs.hpp\"\
    \n\ntemplate <typename GT>\npair<vc<int>, vc<int>> complement_graph_bfs(GT& G,\
    \ int s) {\n  static vc<int> que, NG, dist, par, yet;\n  const int N = G.N;\n\
    \  if (len(que) < N) que.resize(N);\n  if (len(NG) < N) NG.resize(N);\n  if (len(yet)\
    \ < N) yet.resize(N);\n  dist.assign(N, infty<int>);\n  par.assign(N, -1);\n \
    \ int ql = 0, qr = 0;\n  dist[s] = 0, que[qr++] = s;\n  int p = 0;\n  FOR(v, N)\
    \ if (v != s) yet[p++] = v;\n  while (ql < qr) {\n    int v = que[ql++];\n   \
    \ for (auto& e: G[v]) NG[e.to] = 1;\n    for (int i = p - 1; i >= 0; --i) {\n\
    \      int to = yet[i];\n      if (NG[to]) continue;\n      dist[to] = dist[v]\
    \ + 1, par[to] = v, que[qr++] = to;\n      swap(yet[i], yet[--p]);\n    }\n  \
    \  for (auto& e: G[v]) NG[e.to] = 0;\n  }\n  return {dist, par};\n}\n#line 2 \"\
    graph/blackbox/complement_graph_distance.hpp\"\n\n// \u8DDD\u96E2 2 \u4EE5\u4E0A\
    \u306E 2 \u70B9\u7D44\u306E\u5217\u6319. {v,w,dvw}.\ntemplate <typename GT>\n\
    vc<tuple<int, int, int>> complement_graph_all_distance(GT& G) {\n  const int N\
    \ = G.N;\n  auto deg = G.deg_array();\n  int S = min_element(all(deg)) - deg.begin();\n\
    \  vc<int> nbd(N);\n  for (auto& e: G[S]) { nbd[e.to] = 1; }\n\n  vc<tuple<int,\
    \ int, int>> res;\n  for (auto& e: G.edges) {\n    if (nbd[e.frm] || nbd[e.to])\
    \ continue;\n    // a -> S -> b\n    int a = e.frm, b = e.to;\n    res.eb(a, b,\
    \ 2);\n  }\n\n  for (auto& e: G[S]) {\n    int a = e.to;\n    auto dist = complement_graph_bfs(G,\
    \ a).fi;\n    FOR(b, N) {\n      if (dist[b] <= 1) continue;\n      if (nbd[b]\
    \ && a >= b) continue;\n      res.eb(a, b, dist[b]);\n    }\n  }\n  return res;\n\
    }\n"
  code: "#include \"graph/blackbox/complement_graph_bfs.hpp\"\n\n// \u8DDD\u96E2 2\
    \ \u4EE5\u4E0A\u306E 2 \u70B9\u7D44\u306E\u5217\u6319. {v,w,dvw}.\ntemplate <typename\
    \ GT>\nvc<tuple<int, int, int>> complement_graph_all_distance(GT& G) {\n  const\
    \ int N = G.N;\n  auto deg = G.deg_array();\n  int S = min_element(all(deg)) -\
    \ deg.begin();\n  vc<int> nbd(N);\n  for (auto& e: G[S]) { nbd[e.to] = 1; }\n\n\
    \  vc<tuple<int, int, int>> res;\n  for (auto& e: G.edges) {\n    if (nbd[e.frm]\
    \ || nbd[e.to]) continue;\n    // a -> S -> b\n    int a = e.frm, b = e.to;\n\
    \    res.eb(a, b, 2);\n  }\n\n  for (auto& e: G[S]) {\n    int a = e.to;\n   \
    \ auto dist = complement_graph_bfs(G, a).fi;\n    FOR(b, N) {\n      if (dist[b]\
    \ <= 1) continue;\n      if (nbd[b] && a >= b) continue;\n      res.eb(a, b, dist[b]);\n\
    \    }\n  }\n  return res;\n}\n"
  dependsOn:
  - graph/blackbox/complement_graph_bfs.hpp
  - graph/base.hpp
  isVerificationFile: false
  path: graph/blackbox/complement_graph_distance.hpp
  requiredBy: []
  timestamp: '2024-05-29 22:32:29+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: graph/blackbox/complement_graph_distance.hpp
layout: document
redirect_from:
- /library/graph/blackbox/complement_graph_distance.hpp
- /library/graph/blackbox/complement_graph_distance.hpp.html
title: graph/blackbox/complement_graph_distance.hpp
---
