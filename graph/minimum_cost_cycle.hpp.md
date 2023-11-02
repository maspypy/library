---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: graph/base.hpp
    title: graph/base.hpp
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/yukicoder/1320.test.cpp
    title: test/yukicoder/1320.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
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
    \ }\n  }\n};\n#line 2 \"graph/minimum_cost_cycle.hpp\"\n\r\n// {wt, vs, es}, O(N\
    \ * shortest path)\r\ntemplate <typename T, typename GT>\r\ntuple<T, vc<int>,\
    \ vc<int>> minimum_cost_cycle_directed(GT& G) {\r\n  const int N = G.N;\r\n  T\
    \ mi = 0, ma = 0;\r\n  for (auto& e: G.edges) chmin(mi, e.cost), chmax(ma, e.cost);\r\
    \n  assert(mi >= 0);\r\n\r\n  T ans = infty<T>;\r\n  vc<T> dist(N);\r\n  vc<int>\
    \ vs, es;\r\n  vc<int> par_e(N, -1);\r\n  pqg<pair<T, int>> que;\r\n  deque<int>\
    \ deq;\r\n  FOR(r, N) {\r\n    fill(dist.begin() + r, dist.end(), infty<T>);\r\
    \n    if (ma <= 1) {\r\n      auto push = [&](int v, bool back) -> void {\r\n\
    \        (back ? deq.eb(v) : deq.emplace_front(v));\r\n      };\r\n      for (auto&\
    \ e: G[r]) {\r\n        if (r <= e.to && chmin(dist[e.to], e.cost))\r\n      \
    \    par_e[e.to] = e.id, push(e.to, e.cost);\r\n      }\r\n      while (len(deq))\
    \ {\r\n        auto v = POP(deq);\r\n        for (auto& e: G[v]) {\r\n       \
    \   if (r <= e.to && chmin(dist[e.to], dist[v] + e.cost)) {\r\n            par_e[e.to]\
    \ = e.id, push(e.to, e.cost);\r\n          }\r\n        }\r\n      }\r\n    }\
    \ else {\r\n      for (auto& e: G[r]) {\r\n        if (r <= e.to && chmin(dist[e.to],\
    \ e.cost)) {\r\n          par_e[e.to] = e.id, que.emplace(e.cost, e.to);\r\n \
    \       }\r\n      }\r\n      while (len(que)) {\r\n        auto [dv, v] = POP(que);\r\
    \n        if (dist[v] != dv) continue;\r\n        for (auto& e: G[v]) {\r\n  \
    \        T x = dv + e.cost;\r\n          if (r <= e.to && chmin(dist[e.to], x))\
    \ {\r\n            par_e[e.to] = e.id, que.emplace(x, e.to);\r\n          }\r\n\
    \        }\r\n      }\r\n    }\r\n    if (chmin(ans, dist[r])) {\r\n      vs.clear(),\
    \ es.clear();\r\n      vs.eb(r);\r\n      while (1) {\r\n        int eid = par_e[vs.back()];\r\
    \n        es.eb(eid);\r\n        vs.eb(G.edges[eid].frm);\r\n        if (vs.back()\
    \ == r) break;\r\n      }\r\n      reverse(all(vs));\r\n      reverse(all(es));\r\
    \n    };\r\n  }\r\n  return {ans, vs, es};\r\n}\r\n\r\n// {wt, vs, es}, O(N *\
    \ shortest path)\r\ntemplate <typename T, typename GT>\r\ntuple<T, vc<int>, vc<int>>\
    \ minimum_cost_cycle_undirected(GT& G) {\r\n  const int N = G.N;\r\n  T ans =\
    \ infty<T>;\r\n  vc<T> dist(N);\r\n  vc<int> par_e(N);\r\n  vc<int> vs, es;\r\n\
    \  FOR(r, N) {\r\n    fill(dist.begin() + r, dist.end(), infty<T>);\r\n    pqg<pair<T,\
    \ int>> que;\r\n    dist[r] = 0, que.emplace(0, r);\r\n    while (len(que)) {\r\
    \n      auto [dv, v] = POP(que);\r\n      if (dist[v] != dv) continue;\r\n   \
    \   for (auto& e: G[v]) {\r\n        if (e.to < r) continue;\r\n        T x =\
    \ dv + e.cost;\r\n        if (chmin(dist[e.to], x)) {\r\n          par_e[e.to]\
    \ = e.id;\r\n          que.emplace(x, e.to);\r\n        }\r\n      }\r\n    }\r\
    \n    int best_e = -1;\r\n    for (auto& e: G.edges) {\r\n      int a = e.frm,\
    \ b = e.to;\r\n      if (a < r || b < r || par_e[a] == e.id || par_e[b] == e.id)\
    \ continue;\r\n      if (chmin(ans, dist[a] + dist[b] + e.cost)) best_e = e.id;\r\
    \n    }\r\n    if (best_e == -1) continue;\r\n    vs.clear(), es.clear();\r\n\
    \    auto& e = G.edges[best_e];\r\n    int a = e.frm, b = e.to;\r\n    // r ->\
    \ a\r\n    while (a != r) {\r\n      int eid = par_e[a];\r\n      vs.eb(a), es.eb(eid);\r\
    \n      a = G.edges[eid].frm ^ G.edges[eid].to ^ a;\r\n    }\r\n    vs.eb(a);\r\
    \n    reverse(all(vs)), reverse(all(es));\r\n    es.eb(best_e);\r\n    while (b\
    \ != r) {\r\n      int eid = par_e[b];\r\n      vs.eb(b), es.eb(eid);\r\n    \
    \  b = G.edges[eid].frm ^ G.edges[eid].to ^ b;\r\n    }\r\n    vs.eb(b);\r\n \
    \ }\r\n  return {ans, vs, es};\r\n}\r\n\r\n// {wt, vs, es}, O(N * shortest path)\r\
    \ntemplate <typename T, typename GT>\r\ntuple<T, vc<int>, vc<int>> minimum_cost_cycle(GT&\
    \ G) {\r\n  for (auto& e: G.edges) assert(e.cost >= 0);\r\n  if constexpr (GT::is_directed)\
    \ {\r\n    return minimum_cost_cycle_directed<T>(G);\r\n  } else {\r\n    return\
    \ minimum_cost_cycle_undirected<T>(G);\r\n  }\r\n}\r\n"
  code: "#include \"graph/base.hpp\"\r\n\r\n// {wt, vs, es}, O(N * shortest path)\r\
    \ntemplate <typename T, typename GT>\r\ntuple<T, vc<int>, vc<int>> minimum_cost_cycle_directed(GT&\
    \ G) {\r\n  const int N = G.N;\r\n  T mi = 0, ma = 0;\r\n  for (auto& e: G.edges)\
    \ chmin(mi, e.cost), chmax(ma, e.cost);\r\n  assert(mi >= 0);\r\n\r\n  T ans =\
    \ infty<T>;\r\n  vc<T> dist(N);\r\n  vc<int> vs, es;\r\n  vc<int> par_e(N, -1);\r\
    \n  pqg<pair<T, int>> que;\r\n  deque<int> deq;\r\n  FOR(r, N) {\r\n    fill(dist.begin()\
    \ + r, dist.end(), infty<T>);\r\n    if (ma <= 1) {\r\n      auto push = [&](int\
    \ v, bool back) -> void {\r\n        (back ? deq.eb(v) : deq.emplace_front(v));\r\
    \n      };\r\n      for (auto& e: G[r]) {\r\n        if (r <= e.to && chmin(dist[e.to],\
    \ e.cost))\r\n          par_e[e.to] = e.id, push(e.to, e.cost);\r\n      }\r\n\
    \      while (len(deq)) {\r\n        auto v = POP(deq);\r\n        for (auto&\
    \ e: G[v]) {\r\n          if (r <= e.to && chmin(dist[e.to], dist[v] + e.cost))\
    \ {\r\n            par_e[e.to] = e.id, push(e.to, e.cost);\r\n          }\r\n\
    \        }\r\n      }\r\n    } else {\r\n      for (auto& e: G[r]) {\r\n     \
    \   if (r <= e.to && chmin(dist[e.to], e.cost)) {\r\n          par_e[e.to] = e.id,\
    \ que.emplace(e.cost, e.to);\r\n        }\r\n      }\r\n      while (len(que))\
    \ {\r\n        auto [dv, v] = POP(que);\r\n        if (dist[v] != dv) continue;\r\
    \n        for (auto& e: G[v]) {\r\n          T x = dv + e.cost;\r\n          if\
    \ (r <= e.to && chmin(dist[e.to], x)) {\r\n            par_e[e.to] = e.id, que.emplace(x,\
    \ e.to);\r\n          }\r\n        }\r\n      }\r\n    }\r\n    if (chmin(ans,\
    \ dist[r])) {\r\n      vs.clear(), es.clear();\r\n      vs.eb(r);\r\n      while\
    \ (1) {\r\n        int eid = par_e[vs.back()];\r\n        es.eb(eid);\r\n    \
    \    vs.eb(G.edges[eid].frm);\r\n        if (vs.back() == r) break;\r\n      }\r\
    \n      reverse(all(vs));\r\n      reverse(all(es));\r\n    };\r\n  }\r\n  return\
    \ {ans, vs, es};\r\n}\r\n\r\n// {wt, vs, es}, O(N * shortest path)\r\ntemplate\
    \ <typename T, typename GT>\r\ntuple<T, vc<int>, vc<int>> minimum_cost_cycle_undirected(GT&\
    \ G) {\r\n  const int N = G.N;\r\n  T ans = infty<T>;\r\n  vc<T> dist(N);\r\n\
    \  vc<int> par_e(N);\r\n  vc<int> vs, es;\r\n  FOR(r, N) {\r\n    fill(dist.begin()\
    \ + r, dist.end(), infty<T>);\r\n    pqg<pair<T, int>> que;\r\n    dist[r] = 0,\
    \ que.emplace(0, r);\r\n    while (len(que)) {\r\n      auto [dv, v] = POP(que);\r\
    \n      if (dist[v] != dv) continue;\r\n      for (auto& e: G[v]) {\r\n      \
    \  if (e.to < r) continue;\r\n        T x = dv + e.cost;\r\n        if (chmin(dist[e.to],\
    \ x)) {\r\n          par_e[e.to] = e.id;\r\n          que.emplace(x, e.to);\r\n\
    \        }\r\n      }\r\n    }\r\n    int best_e = -1;\r\n    for (auto& e: G.edges)\
    \ {\r\n      int a = e.frm, b = e.to;\r\n      if (a < r || b < r || par_e[a]\
    \ == e.id || par_e[b] == e.id) continue;\r\n      if (chmin(ans, dist[a] + dist[b]\
    \ + e.cost)) best_e = e.id;\r\n    }\r\n    if (best_e == -1) continue;\r\n  \
    \  vs.clear(), es.clear();\r\n    auto& e = G.edges[best_e];\r\n    int a = e.frm,\
    \ b = e.to;\r\n    // r -> a\r\n    while (a != r) {\r\n      int eid = par_e[a];\r\
    \n      vs.eb(a), es.eb(eid);\r\n      a = G.edges[eid].frm ^ G.edges[eid].to\
    \ ^ a;\r\n    }\r\n    vs.eb(a);\r\n    reverse(all(vs)), reverse(all(es));\r\n\
    \    es.eb(best_e);\r\n    while (b != r) {\r\n      int eid = par_e[b];\r\n \
    \     vs.eb(b), es.eb(eid);\r\n      b = G.edges[eid].frm ^ G.edges[eid].to ^\
    \ b;\r\n    }\r\n    vs.eb(b);\r\n  }\r\n  return {ans, vs, es};\r\n}\r\n\r\n\
    // {wt, vs, es}, O(N * shortest path)\r\ntemplate <typename T, typename GT>\r\n\
    tuple<T, vc<int>, vc<int>> minimum_cost_cycle(GT& G) {\r\n  for (auto& e: G.edges)\
    \ assert(e.cost >= 0);\r\n  if constexpr (GT::is_directed) {\r\n    return minimum_cost_cycle_directed<T>(G);\r\
    \n  } else {\r\n    return minimum_cost_cycle_undirected<T>(G);\r\n  }\r\n}\r\n"
  dependsOn:
  - graph/base.hpp
  isVerificationFile: false
  path: graph/minimum_cost_cycle.hpp
  requiredBy: []
  timestamp: '2023-11-01 01:50:41+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/yukicoder/1320.test.cpp
documentation_of: graph/minimum_cost_cycle.hpp
layout: document
redirect_from:
- /library/graph/minimum_cost_cycle.hpp
- /library/graph/minimum_cost_cycle.hpp.html
title: graph/minimum_cost_cycle.hpp
---
