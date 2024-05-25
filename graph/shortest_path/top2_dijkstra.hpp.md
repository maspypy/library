---
data:
  _extendedDependsOn:
  - icon: ':x:'
    path: alg/monoid/min2.hpp
    title: alg/monoid/min2.hpp
  - icon: ':question:'
    path: graph/base.hpp
    title: graph/base.hpp
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':x:'
    path: test_atcoder/abc245g2.test.cpp
    title: test_atcoder/abc245g2.test.cpp
  _isVerificationFailed: true
  _pathExtension: hpp
  _verificationStatusIcon: ':x:'
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
    \nprivate:\n  void calc_deg() {\n    assert(vc_deg.empty());\n    vc_deg.resize(N);\n\
    \    for (auto&& e: edges) vc_deg[e.frm]++, vc_deg[e.to]++;\n  }\n\n  void calc_deg_inout()\
    \ {\n    assert(vc_indeg.empty());\n    vc_indeg.resize(N);\n    vc_outdeg.resize(N);\n\
    \    for (auto&& e: edges) { vc_indeg[e.to]++, vc_outdeg[e.frm]++; }\n  }\n};\n\
    #line 2 \"alg/monoid/min2.hpp\"\n\ntemplate <typename T, typename KEY>\nstruct\
    \ Monoid_Min2 {\n  struct Data {\n    T min1, min2;\n    KEY key1, key2;\n   \
    \ bool add_element(T x, KEY key) {\n      if (key1 == key) { return chmin(min1,\
    \ x); }\n      if (key2 == key) {\n        bool upd = chmin(min2, x);\n      \
    \  if (min1 > min2) swap(min1, min2), swap(key1, key2);\n        return upd;\n\
    \      }\n      if (min1 > x) {\n        min2 = min1, key2 = key1, min1 = x, key1\
    \ = key;\n        return 1;\n      }\n      elif (min2 > x) {\n        min2 =\
    \ x, key2 = key;\n        return 1;\n      }\n      return 0;\n    }\n  };\n \
    \ using value_type = Data;\n  using X = value_type;\n\n  static X op(X x, X y)\
    \ {\n    x.add_element(y.min1, y.key1);\n    x.add_element(y.min2, y.key2);\n\
    \    return x;\n  }\n  static constexpr X unit() { return {infty<T>, infty<T>,\
    \ -1, -1}; }\n  static constexpr bool commute = true;\n};\n#line 3 \"graph/shortest_path/top2_dijkstra.hpp\"\
    \n\n// \u7D4C\u8DEF\u5FA9\u5143\u306F\u306A\u3057\u3067\u8DDD\u96E2\u3068\u7A2E\
    \u985E\u3060\u3051\u306B\u306A\u3063\u3066\u3044\u308B\ntemplate <typename T,\
    \ typename GT>\nvc<typename Monoid_Min2<T, int>::Data> top2_dijkstra(GT& G, vc<int>\
    \ vs) {\n  assert(G.is_prepared());\n  int N = G.N;\n  using Mono = Monoid_Min2<T,\
    \ int>;\n  using Data = typename Mono::Data;\n  vc<Data> dist(N, Mono::unit());\n\
    \  pqg<tuple<T, int, int>> que; // \u8DDD\u96E2\u3001\u753A\u3001\u8272\n\n  auto\
    \ upd = [&](int v, int c, T x) -> void {\n    if (dist[v].add_element(x, c)) que.emplace(x,\
    \ v, c);\n  };\n\n  for (auto& v: vs) { upd(v, v, 0); }\n\n  while (len(que))\
    \ {\n    auto [dv, v, c] = POP(que);\n    bool ok = 0;\n    auto& e = dist[v];\n\
    \    if (e.min1 == dv && e.key1 == c) ok = 1;\n    if (e.min2 == dv && e.key2\
    \ == c) ok = 1;\n    if (!ok) continue;\n    for (auto&& e: G[v]) { upd(e.to,\
    \ c, dv + e.cost); }\n  }\n  return dist;\n}\n"
  code: "#include \"graph/base.hpp\"\n#include \"alg/monoid/min2.hpp\"\n\n// \u7D4C\
    \u8DEF\u5FA9\u5143\u306F\u306A\u3057\u3067\u8DDD\u96E2\u3068\u7A2E\u985E\u3060\
    \u3051\u306B\u306A\u3063\u3066\u3044\u308B\ntemplate <typename T, typename GT>\n\
    vc<typename Monoid_Min2<T, int>::Data> top2_dijkstra(GT& G, vc<int> vs) {\n  assert(G.is_prepared());\n\
    \  int N = G.N;\n  using Mono = Monoid_Min2<T, int>;\n  using Data = typename\
    \ Mono::Data;\n  vc<Data> dist(N, Mono::unit());\n  pqg<tuple<T, int, int>> que;\
    \ // \u8DDD\u96E2\u3001\u753A\u3001\u8272\n\n  auto upd = [&](int v, int c, T\
    \ x) -> void {\n    if (dist[v].add_element(x, c)) que.emplace(x, v, c);\n  };\n\
    \n  for (auto& v: vs) { upd(v, v, 0); }\n\n  while (len(que)) {\n    auto [dv,\
    \ v, c] = POP(que);\n    bool ok = 0;\n    auto& e = dist[v];\n    if (e.min1\
    \ == dv && e.key1 == c) ok = 1;\n    if (e.min2 == dv && e.key2 == c) ok = 1;\n\
    \    if (!ok) continue;\n    for (auto&& e: G[v]) { upd(e.to, c, dv + e.cost);\
    \ }\n  }\n  return dist;\n}"
  dependsOn:
  - graph/base.hpp
  - alg/monoid/min2.hpp
  isVerificationFile: false
  path: graph/shortest_path/top2_dijkstra.hpp
  requiredBy: []
  timestamp: '2024-05-24 21:01:28+09:00'
  verificationStatus: LIBRARY_ALL_WA
  verifiedWith:
  - test_atcoder/abc245g2.test.cpp
documentation_of: graph/shortest_path/top2_dijkstra.hpp
layout: document
redirect_from:
- /library/graph/shortest_path/top2_dijkstra.hpp
- /library/graph/shortest_path/top2_dijkstra.hpp.html
title: graph/shortest_path/top2_dijkstra.hpp
---