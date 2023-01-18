---
data:
  _extendedDependsOn:
  - icon: ':question:'
    path: graph/base.hpp
    title: graph/base.hpp
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':x:'
    path: test/aoj/DPL_2_A.test.cpp
    title: test/aoj/DPL_2_A.test.cpp
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
    \ { vc_indeg[e.to]++, vc_outdeg[e.frm]++; }\n  }\n};\n#line 3 \"graph/minimum_hamiltonian_cycle.hpp\"\
    \n\n/*\nreturn [cost, cycle]\ncycle \u306A\u3057\u306E\u5834\u5408\uFF1A{-1, {}}\n\
    */\ntemplate <typename T, typename GT>\npair<T, vc<int>> minimum_hamiltonian_cycle(GT&\
    \ G) {\n  assert(G.is_prepared());\n  T INF = numeric_limits<T>::max();\n  int\
    \ n = G.N;\n  vv(T, dist, n, n, INF);\n  FOR(v, n) {\n    for (auto&& e: G[v])\
    \ chmin(dist[v][e.to], e.cost);\n  }\n  n -= 1;\n  vv(T, dp, 1 << n, n, INF);\n\
    \  FOR(v, n) chmin(dp[1 << v][v], dist[n][v]);\n  FOR(s, 1 << n) FOR(frm, n) if\
    \ (dp[s][frm] < INF) {\n    FOR(to, n) {\n      int t = s | 1 << to;\n      T\
    \ cost = dist[frm][to];\n      if (s < t && cost < INF) chmin(dp[t][to], dp[s][frm]\
    \ + cost);\n    }\n  }\n  int s = (1 << n) - 1;\n  T res = INF;\n  int best_v\
    \ = -1;\n  FOR(v, n) if (dist[v][n] < INF && dp[s][v] < INF) {\n    if (chmin(res,\
    \ dp[s][v] + dist[v][n])) best_v = v;\n  }\n  if (res == INF) return {-1, {}};\n\
    \  vc<int> C = {n, best_v};\n  int t = s;\n  while (len(C) <= n) {\n    int to\
    \ = C.back();\n    int frm = [&]() -> int {\n      FOR(frm, n) {\n        int\
    \ s = t ^ (1 << to);\n        if (dp[s][frm] < INF && dist[frm][to] < INF\n  \
    \          && dp[s][frm] + dist[frm][to] == dp[t][to])\n          return frm;\n\
    \      }\n      return -1;\n    }();\n    C.eb(frm);\n    t ^= 1 << to;\n  }\n\
    \  reverse(all(C));\n  return {res, C};\n}\n"
  code: "#pragma once\n#include \"graph/base.hpp\"\n\n/*\nreturn [cost, cycle]\ncycle\
    \ \u306A\u3057\u306E\u5834\u5408\uFF1A{-1, {}}\n*/\ntemplate <typename T, typename\
    \ GT>\npair<T, vc<int>> minimum_hamiltonian_cycle(GT& G) {\n  assert(G.is_prepared());\n\
    \  T INF = numeric_limits<T>::max();\n  int n = G.N;\n  vv(T, dist, n, n, INF);\n\
    \  FOR(v, n) {\n    for (auto&& e: G[v]) chmin(dist[v][e.to], e.cost);\n  }\n\
    \  n -= 1;\n  vv(T, dp, 1 << n, n, INF);\n  FOR(v, n) chmin(dp[1 << v][v], dist[n][v]);\n\
    \  FOR(s, 1 << n) FOR(frm, n) if (dp[s][frm] < INF) {\n    FOR(to, n) {\n    \
    \  int t = s | 1 << to;\n      T cost = dist[frm][to];\n      if (s < t && cost\
    \ < INF) chmin(dp[t][to], dp[s][frm] + cost);\n    }\n  }\n  int s = (1 << n)\
    \ - 1;\n  T res = INF;\n  int best_v = -1;\n  FOR(v, n) if (dist[v][n] < INF &&\
    \ dp[s][v] < INF) {\n    if (chmin(res, dp[s][v] + dist[v][n])) best_v = v;\n\
    \  }\n  if (res == INF) return {-1, {}};\n  vc<int> C = {n, best_v};\n  int t\
    \ = s;\n  while (len(C) <= n) {\n    int to = C.back();\n    int frm = [&]() ->\
    \ int {\n      FOR(frm, n) {\n        int s = t ^ (1 << to);\n        if (dp[s][frm]\
    \ < INF && dist[frm][to] < INF\n            && dp[s][frm] + dist[frm][to] == dp[t][to])\n\
    \          return frm;\n      }\n      return -1;\n    }();\n    C.eb(frm);\n\
    \    t ^= 1 << to;\n  }\n  reverse(all(C));\n  return {res, C};\n}\n"
  dependsOn:
  - graph/base.hpp
  isVerificationFile: false
  path: graph/minimum_hamiltonian_cycle.hpp
  requiredBy: []
  timestamp: '2022-12-05 10:41:25+09:00'
  verificationStatus: LIBRARY_ALL_WA
  verifiedWith:
  - test/aoj/DPL_2_A.test.cpp
documentation_of: graph/minimum_hamiltonian_cycle.hpp
layout: document
redirect_from:
- /library/graph/minimum_hamiltonian_cycle.hpp
- /library/graph/minimum_hamiltonian_cycle.hpp.html
title: graph/minimum_hamiltonian_cycle.hpp
---
