---
data:
  _extendedDependsOn:
  - icon: ':question:'
    path: graph/base.hpp
    title: graph/base.hpp
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/yukicoder/1069.test.cpp
    title: test/yukicoder/1069.test.cpp
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
    \ { vc_indeg[e.to]++, vc_outdeg[e.frm]++; }\n  }\n};\n#line 2 \"graph/shortest_path/K_shortest_path.hpp\"\
    \n\n// (cost, vs, es)\ntemplate <typename T, typename GT>\nvc<tuple<T, vc<int>,\
    \ vc<int>>> K_shortest_path(GT& G, int s, int t, int K) {\n  assert(G.is_directed());\n\
    \  const int N = G.N;\n\n  // (cost, vs, es)\n  vc<tuple<T, vc<int>, vc<int>>>\
    \ res;\n  // \u63A2\u7D22\u306E\u8D77\u70B9 (es, ng_edges)\n  vc<pair<vc<int>,\
    \ vc<int>>> nodes;\n  // \u7B54\u306E\u5019\u88DC (cost, es, ng_es, n), (ng_es,\
    \ n)\uFF1A\u305D\u306E path \u3092\u898B\u3064\u3051\u305F\u3068\u304D\u306E\u6761\
    \u4EF6\n  vc<tuple<T, vc<int>, vc<int>, int>> paths;\n\n  nodes.eb(vc<int>(),\
    \ vc<int>());\n  vc<T> dist(N, infty<T>);\n  vc<bool> ng_v(N);\n  vc<bool> ng_e(G.M);\n\
    \  vc<int> par(N, -1);\n\n  while (len(res) < K) {\n    for (auto&& [es, ng_es]:\
    \ nodes) {\n      fill(all(par), -1);\n      fill(all(ng_v), 0);\n      fill(all(ng_e),\
    \ 0);\n      fill(all(dist), infty<T>);\n\n      T pref_cost = 0;\n      for (auto&&\
    \ x: es) pref_cost += G.edges[x].cost;\n\n      for (auto&& x: es) ng_v[G.edges[x].frm]\
    \ = 1, ng_e[x] = 1;\n      for (auto&& x: ng_es) ng_e[x] = 1;\n      // dijkstra\n\
    \      pqg<pair<T, int>> que;\n      auto add = [&](int v, T d, int p) -> void\
    \ {\n        if (chmin(dist[v], d)) {\n          que.emplace(d, v);\n        \
    \  par[v] = p;\n        }\n      };\n      int s0 = (es.empty() ? s : G.edges[es.back()].to);\n\
    \      add(s0, pref_cost, -1);\n      while (len(que)) {\n        auto [dv, v]\
    \ = POP(que);\n        if (dv != dist[v]) continue;\n        if (v == t) break;\n\
    \        for (auto&& e: G[v]) {\n          if (ng_e[e.id] || ng_v[e.to]) continue;\n\
    \          add(e.to, dv + e.cost, e.id);\n        }\n      }\n      // failed\n\
    \      if (par[t] == -1) continue;\n      // restore path\n      vc<int> add_e;\n\
    \      {\n        int v = t;\n        while (v != s0) {\n          add_e.eb(par[v]);\n\
    \          v = G.edges[par[v]].frm;\n        }\n      }\n      reverse(all(add_e));\n\
    \      int n = len(es);\n      // find a path\n      es.insert(es.end(), all(add_e));\n\
    \      paths.eb(dist[t], es, ng_es, n);\n    }\n    // choose best path\n    if\
    \ (len(paths) == 0) break;\n    pair<int, T> best = {-1, infty<T>};\n    FOR(i,\
    \ len(paths)) {\n      T cost = get<0>(paths[i]);\n      if (chmin(best.se, cost))\
    \ best.fi = i;\n    }\n    int idx = best.fi;\n    swap(paths[idx], paths[len(paths)\
    \ - 1]);\n    auto [cost, es, ng_es, n] = POP(paths);\n    vc<int> vs = {s};\n\
    \    for (auto&& x: es) vs.eb(G.edges[x].to);\n    res.eb(cost, vs, es);\n\n \
    \   nodes.clear();\n    FOR(k, n, len(es)) {\n      // k \u756A\u76EE\u306E\u8FBA\
    \u307E\u3067\u3092\u56FA\u5B9A\u3057\u3066\n      vc<int> new_es = {es.begin(),\
    \ es.begin() + k};\n      vc<int> new_ng = ng_es;\n      new_ng.eb(es[k]);\n \
    \     nodes.eb(new_es, new_ng);\n    }\n  }\n  return res;\n}\n"
  code: "#include \"graph/base.hpp\"\n\n// (cost, vs, es)\ntemplate <typename T, typename\
    \ GT>\nvc<tuple<T, vc<int>, vc<int>>> K_shortest_path(GT& G, int s, int t, int\
    \ K) {\n  assert(G.is_directed());\n  const int N = G.N;\n\n  // (cost, vs, es)\n\
    \  vc<tuple<T, vc<int>, vc<int>>> res;\n  // \u63A2\u7D22\u306E\u8D77\u70B9 (es,\
    \ ng_edges)\n  vc<pair<vc<int>, vc<int>>> nodes;\n  // \u7B54\u306E\u5019\u88DC\
    \ (cost, es, ng_es, n), (ng_es, n)\uFF1A\u305D\u306E path \u3092\u898B\u3064\u3051\
    \u305F\u3068\u304D\u306E\u6761\u4EF6\n  vc<tuple<T, vc<int>, vc<int>, int>> paths;\n\
    \n  nodes.eb(vc<int>(), vc<int>());\n  vc<T> dist(N, infty<T>);\n  vc<bool> ng_v(N);\n\
    \  vc<bool> ng_e(G.M);\n  vc<int> par(N, -1);\n\n  while (len(res) < K) {\n  \
    \  for (auto&& [es, ng_es]: nodes) {\n      fill(all(par), -1);\n      fill(all(ng_v),\
    \ 0);\n      fill(all(ng_e), 0);\n      fill(all(dist), infty<T>);\n\n      T\
    \ pref_cost = 0;\n      for (auto&& x: es) pref_cost += G.edges[x].cost;\n\n \
    \     for (auto&& x: es) ng_v[G.edges[x].frm] = 1, ng_e[x] = 1;\n      for (auto&&\
    \ x: ng_es) ng_e[x] = 1;\n      // dijkstra\n      pqg<pair<T, int>> que;\n  \
    \    auto add = [&](int v, T d, int p) -> void {\n        if (chmin(dist[v], d))\
    \ {\n          que.emplace(d, v);\n          par[v] = p;\n        }\n      };\n\
    \      int s0 = (es.empty() ? s : G.edges[es.back()].to);\n      add(s0, pref_cost,\
    \ -1);\n      while (len(que)) {\n        auto [dv, v] = POP(que);\n        if\
    \ (dv != dist[v]) continue;\n        if (v == t) break;\n        for (auto&& e:\
    \ G[v]) {\n          if (ng_e[e.id] || ng_v[e.to]) continue;\n          add(e.to,\
    \ dv + e.cost, e.id);\n        }\n      }\n      // failed\n      if (par[t] ==\
    \ -1) continue;\n      // restore path\n      vc<int> add_e;\n      {\n      \
    \  int v = t;\n        while (v != s0) {\n          add_e.eb(par[v]);\n      \
    \    v = G.edges[par[v]].frm;\n        }\n      }\n      reverse(all(add_e));\n\
    \      int n = len(es);\n      // find a path\n      es.insert(es.end(), all(add_e));\n\
    \      paths.eb(dist[t], es, ng_es, n);\n    }\n    // choose best path\n    if\
    \ (len(paths) == 0) break;\n    pair<int, T> best = {-1, infty<T>};\n    FOR(i,\
    \ len(paths)) {\n      T cost = get<0>(paths[i]);\n      if (chmin(best.se, cost))\
    \ best.fi = i;\n    }\n    int idx = best.fi;\n    swap(paths[idx], paths[len(paths)\
    \ - 1]);\n    auto [cost, es, ng_es, n] = POP(paths);\n    vc<int> vs = {s};\n\
    \    for (auto&& x: es) vs.eb(G.edges[x].to);\n    res.eb(cost, vs, es);\n\n \
    \   nodes.clear();\n    FOR(k, n, len(es)) {\n      // k \u756A\u76EE\u306E\u8FBA\
    \u307E\u3067\u3092\u56FA\u5B9A\u3057\u3066\n      vc<int> new_es = {es.begin(),\
    \ es.begin() + k};\n      vc<int> new_ng = ng_es;\n      new_ng.eb(es[k]);\n \
    \     nodes.eb(new_es, new_ng);\n    }\n  }\n  return res;\n}"
  dependsOn:
  - graph/base.hpp
  isVerificationFile: false
  path: graph/shortest_path/K_shortest_path.hpp
  requiredBy: []
  timestamp: '2023-04-09 03:51:17+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/yukicoder/1069.test.cpp
documentation_of: graph/shortest_path/K_shortest_path.hpp
layout: document
redirect_from:
- /library/graph/shortest_path/K_shortest_path.hpp
- /library/graph/shortest_path/K_shortest_path.hpp.html
title: graph/shortest_path/K_shortest_path.hpp
---
