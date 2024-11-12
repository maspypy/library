---
data:
  _extendedDependsOn:
  - icon: ':question:'
    path: graph/base.hpp
    title: graph/base.hpp
  _extendedRequiredBy:
  - icon: ':heavy_check_mark:'
    path: graph/centroid_decomposition.hpp
    title: graph/centroid_decomposition.hpp
  - icon: ':question:'
    path: graph/characteristic_polynomial_of_tree_adjacency_matrix.hpp
    title: graph/characteristic_polynomial_of_tree_adjacency_matrix.hpp
  - icon: ':heavy_check_mark:'
    path: graph/ds/contour_query_range.hpp
    title: graph/ds/contour_query_range.hpp
  - icon: ':heavy_check_mark:'
    path: graph/st_numbering.hpp
    title: graph/st_numbering.hpp
  - icon: ':heavy_check_mark:'
    path: graph/tree_all_distances.hpp
    title: graph/tree_all_distances.hpp
  - icon: ':warning:'
    path: graph/tree_center.hpp
    title: graph/tree_center.hpp
  - icon: ':heavy_check_mark:'
    path: graph/tree_diameter.hpp
    title: graph/tree_diameter.hpp
  - icon: ':question:'
    path: graph/tree_walk_generating_function.hpp
    title: graph/tree_walk_generating_function.hpp
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/1_mytest/st_numbering.test.cpp
    title: test/1_mytest/st_numbering.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/1_mytest/tree_walk_gf.test.cpp
    title: test/1_mytest/tree_walk_gf.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/2_library_checker/graph/st_numbering.test.cpp
    title: test/2_library_checker/graph/st_numbering.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/2_library_checker/tree/frequency_table_of_tree_distance.test.cpp
    title: test/2_library_checker/tree/frequency_table_of_tree_distance.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/2_library_checker/tree/frequency_table_of_tree_distance_0.test.cpp
    title: test/2_library_checker/tree/frequency_table_of_tree_distance_0.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/2_library_checker/tree/frequency_table_of_tree_distance_2.test.cpp
    title: test/2_library_checker/tree/frequency_table_of_tree_distance_2.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/2_library_checker/tree/tree_diameter.test.cpp
    title: test/2_library_checker/tree/tree_diameter.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/2_library_checker/tree/vertex_add_range_contour_sum_on_tree.test.cpp
    title: test/2_library_checker/tree/vertex_add_range_contour_sum_on_tree.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/2_library_checker/tree/vertex_get_range_contour_add_on_tree.test.cpp
    title: test/2_library_checker/tree/vertex_get_range_contour_add_on_tree.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/3_yukicoder/1038.test.cpp
    title: test/3_yukicoder/1038.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/3_yukicoder/1718.test.cpp
    title: test/3_yukicoder/1718.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/3_yukicoder/1796_1.test.cpp
    title: test/3_yukicoder/1796_1.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/3_yukicoder/1868.test.cpp
    title: test/3_yukicoder/1868.test.cpp
  - icon: ':x:'
    path: test/3_yukicoder/2587.test.cpp
    title: test/3_yukicoder/2587.test.cpp
  - icon: ':x:'
    path: test/3_yukicoder/2587_2.test.cpp
    title: test/3_yukicoder/2587_2.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/3_yukicoder/2892.test.cpp
    title: test/3_yukicoder/2892.test.cpp
  _isVerificationFailed: true
  _pathExtension: hpp
  _verificationStatusIcon: ':question:'
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
    \ { vc_indeg[e.to]++, vc_outdeg[e.frm]++; }\n  }\n};\n#line 3 \"graph/shortest_path/bfs01.hpp\"\
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
    \    }\n    }\n  }\n  return {dist, par, root};\n}\n"
  code: "#pragma once\n#include \"graph/base.hpp\"\n\ntemplate <typename T, typename\
    \ GT>\npair<vc<T>, vc<int>> bfs01(GT& G, int v) {\n  assert(G.is_prepared());\n\
    \  int N = G.N;\n  vc<T> dist(N, infty<T>);\n  vc<int> par(N, -1);\n  deque<int>\
    \ que;\n\n  dist[v] = 0;\n  que.push_front(v);\n  while (!que.empty()) {\n   \
    \ auto v = que.front();\n    que.pop_front();\n    for (auto&& e: G[v]) {\n  \
    \    if (dist[e.to] == infty<T> || dist[e.to] > dist[e.frm] + e.cost) {\n    \
    \    dist[e.to] = dist[e.frm] + e.cost;\n        par[e.to] = e.frm;\n        if\
    \ (e.cost == 0)\n          que.push_front(e.to);\n        else\n          que.push_back(e.to);\n\
    \      }\n    }\n  }\n  return {dist, par};\n}\n\n// \u591A\u70B9\u30B9\u30BF\u30FC\
    \u30C8\u3002[dist, par, root]\ntemplate <typename T, typename GT>\ntuple<vc<T>,\
    \ vc<int>, vc<int>> bfs01(GT& G, vc<int> vs) {\n  assert(G.is_prepared());\n \
    \ int N = G.N;\n  vc<T> dist(N, infty<T>);\n  vc<int> par(N, -1);\n  vc<int> root(N,\
    \ -1);\n  deque<int> que;\n\n  for (auto&& v: vs) {\n    dist[v] = 0;\n    root[v]\
    \ = v;\n    que.push_front(v);\n  }\n\n  while (!que.empty()) {\n    auto v =\
    \ que.front();\n    que.pop_front();\n    for (auto&& e: G[v]) {\n      if (dist[e.to]\
    \ == infty<T> || dist[e.to] > dist[e.frm] + e.cost) {\n        dist[e.to] = dist[e.frm]\
    \ + e.cost;\n        root[e.to] = root[e.frm];\n        par[e.to] = e.frm;\n \
    \       if (e.cost == 0)\n          que.push_front(e.to);\n        else\n    \
    \      que.push_back(e.to);\n      }\n    }\n  }\n  return {dist, par, root};\n\
    }\n"
  dependsOn:
  - graph/base.hpp
  isVerificationFile: false
  path: graph/shortest_path/bfs01.hpp
  requiredBy:
  - graph/characteristic_polynomial_of_tree_adjacency_matrix.hpp
  - graph/ds/contour_query_range.hpp
  - graph/tree_all_distances.hpp
  - graph/tree_walk_generating_function.hpp
  - graph/tree_diameter.hpp
  - graph/st_numbering.hpp
  - graph/centroid_decomposition.hpp
  - graph/tree_center.hpp
  timestamp: '2024-05-29 22:32:29+09:00'
  verificationStatus: LIBRARY_SOME_WA
  verifiedWith:
  - test/3_yukicoder/1038.test.cpp
  - test/3_yukicoder/1868.test.cpp
  - test/3_yukicoder/1796_1.test.cpp
  - test/3_yukicoder/1718.test.cpp
  - test/3_yukicoder/2587.test.cpp
  - test/3_yukicoder/2892.test.cpp
  - test/3_yukicoder/2587_2.test.cpp
  - test/1_mytest/tree_walk_gf.test.cpp
  - test/1_mytest/st_numbering.test.cpp
  - test/2_library_checker/graph/st_numbering.test.cpp
  - test/2_library_checker/tree/frequency_table_of_tree_distance.test.cpp
  - test/2_library_checker/tree/tree_diameter.test.cpp
  - test/2_library_checker/tree/frequency_table_of_tree_distance_2.test.cpp
  - test/2_library_checker/tree/vertex_get_range_contour_add_on_tree.test.cpp
  - test/2_library_checker/tree/frequency_table_of_tree_distance_0.test.cpp
  - test/2_library_checker/tree/vertex_add_range_contour_sum_on_tree.test.cpp
documentation_of: graph/shortest_path/bfs01.hpp
layout: document
redirect_from:
- /library/graph/shortest_path/bfs01.hpp
- /library/graph/shortest_path/bfs01.hpp.html
title: graph/shortest_path/bfs01.hpp
---
