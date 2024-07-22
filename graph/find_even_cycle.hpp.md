---
data:
  _extendedDependsOn:
  - icon: ':question:'
    path: graph/base.hpp
    title: graph/base.hpp
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':x:'
    path: test/mytest/find_even_cycle.test.cpp
    title: test/mytest/find_even_cycle.test.cpp
  _isVerificationFailed: true
  _pathExtension: hpp
  _verificationStatusIcon: ':x:'
  attributes:
    links:
    - https://chaoxu.prof/posts/2014-03-08-even-cycle-in-a-simple-graph.html
    - https://scoreboard.icpc.global/46/finals46.pdf
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
    \ { vc_indeg[e.to]++, vc_outdeg[e.frm]++; }\n  }\n};\n#line 2 \"graph/find_even_cycle.hpp\"\
    \n\n// (vs, es), size=(n+1,n)\n// [R] https://scoreboard.icpc.global/46/finals46.pdf\n\
    template <typename GT>\npair<vc<int>, vc<int>> find_even_cycle(GT &G) {\n  /*\n\
    \  \u53C2\u8003\uFF1Ahttps://chaoxu.prof/posts/2014-03-08-even-cycle-in-a-simple-graph.html\n\
    \  DFS\u6728\u3092\u4F5C\u308B, \u5F8C\u9000\u8FBA\u3054\u3068\u306B\u30B5\u30A4\
    \u30AF\u30EB\u3092\u4F5C\u308B\n  \u5076\u30B5\u30A4\u30AF\u30EB\u304C\u3067\u304D\
    \u308C\u3070 OK\n  \u5171\u901A\u8FBA\u3092\u6301\u3064\u5947\u30B5\u30A4\u30AF\
    \u30EB\u304C\u3042\u308B \u2192 \u305D\u308C\u3089\u306E XOR \u304C\u6E80\u305F\
    \u3059\n  \u3069\u3061\u3089\u3082\u306A\u3044 \u2192 \u5947\u30B5\u30A4\u30AF\
    \u30EB\u304B\u3089\u306A\u308B\u30AB\u30AF\u30BF\u30B9 \u2192 \u3080\u308A\n \
    \ */\n  static_assert(!GT::is_directed);\n  const int N = G.N, M = G.M;\n  if\
    \ (N == 1) return {{}, {}};\n  bool FOUND = 0;\n  vvc<int> cyc; // edge index\n\
    \  vc<int> in_cycle(M, -1);\n  vc<int> path_v;\n  vc<int> path_e;\n  vc<bool>\
    \ used(M);\n  vc<bool> vis(N);\n  pair<int, int> cid = {-1, -1};\n  auto dfs =\
    \ [&](auto &dfs, int v) -> void {\n    for (auto &e: G[v]) {\n      if (FOUND)\
    \ return;\n      if (used[e.id]) continue;\n      used[e.id] = 1;\n\n      if\
    \ (!vis[e.to]) {\n        vis[e.to] = 1, used[e.id] = 1;\n        path_v.eb(e.to),\
    \ path_e.eb(e.id);\n        dfs(dfs, e.to);\n        if (FOUND) return;\n    \
    \    POP(path_v), POP(path_e);\n        continue;\n      }\n      // cycle \u767A\
    \u898B\n      vc<int> EID = {e.id};\n      int p = len(path_v) - 1;\n      while\
    \ (path_v[p] != e.to) { EID.eb(path_e[--p]); }\n      int k = len(cyc);\n    \
    \  cyc.eb(EID);\n      if (len(EID) % 2 == 0) {\n        cid = {k, k}, FOUND =\
    \ 1;\n        return;\n      }\n      for (auto &i: EID) {\n        if (in_cycle[i]\
    \ != -1) {\n          cid = {k, in_cycle[i]}, FOUND = 1;\n          return;\n\
    \        }\n        in_cycle[i] = k;\n      }\n    }\n  };\n  FOR(v, N) {\n  \
    \  if (vis[v]) continue;\n    path_v = {int(v)};\n    vis[v] = 1;\n    dfs(dfs,\
    \ v);\n  }\n  if (!FOUND) return {{}, {}};\n  vc<int> es = [&]() {\n    if (cid.fi\
    \ == cid.se) { return cyc[cid.fi]; }\n    auto [a, b] = cid;\n    vc<int> use(M);\n\
    \    for (auto &e: cyc[a]) use[e] ^= 1;\n    for (auto &e: cyc[b]) use[e] ^= 1;\n\
    \    vc<int> es;\n    FOR(i, M) if (use[i]) es.eb(i);\n    return es;\n  }();\n\
    \n  vc<pair<int, int>> v_to_e(N, {-1, -1});\n  auto add = [&](int v, int e) ->\
    \ void {\n    if (v_to_e[v].fi == -1) {\n      v_to_e[v].fi = e;\n    } else {\n\
    \      v_to_e[v].se = e;\n    }\n  };\n  for (auto &e: es) { add(G.edges[e].frm,\
    \ e), add(G.edges[e].to, e); }\n\n  int v0 = G.edges[es[0]].frm;\n  vc<int> vs\
    \ = {v0};\n  es.clear(), es.shrink_to_fit();\n  es = {v_to_e[v0].fi};\n  while\
    \ (1) {\n    int e = es.back();\n    int a = G.edges[e].frm, b = G.edges[e].to;\n\
    \    assert(vs.back() == a || vs.back() == b);\n    if (vs.back() != a) swap(a,\
    \ b);\n    vs.eb(b);\n    if (b == v0) break;\n    es.eb(v_to_e[b].fi + v_to_e[b].se\
    \ - e);\n  }\n  return {vs, es};\n}\n"
  code: "#include \"graph/base.hpp\"\n\n// (vs, es), size=(n+1,n)\n// [R] https://scoreboard.icpc.global/46/finals46.pdf\n\
    template <typename GT>\npair<vc<int>, vc<int>> find_even_cycle(GT &G) {\n  /*\n\
    \  \u53C2\u8003\uFF1Ahttps://chaoxu.prof/posts/2014-03-08-even-cycle-in-a-simple-graph.html\n\
    \  DFS\u6728\u3092\u4F5C\u308B, \u5F8C\u9000\u8FBA\u3054\u3068\u306B\u30B5\u30A4\
    \u30AF\u30EB\u3092\u4F5C\u308B\n  \u5076\u30B5\u30A4\u30AF\u30EB\u304C\u3067\u304D\
    \u308C\u3070 OK\n  \u5171\u901A\u8FBA\u3092\u6301\u3064\u5947\u30B5\u30A4\u30AF\
    \u30EB\u304C\u3042\u308B \u2192 \u305D\u308C\u3089\u306E XOR \u304C\u6E80\u305F\
    \u3059\n  \u3069\u3061\u3089\u3082\u306A\u3044 \u2192 \u5947\u30B5\u30A4\u30AF\
    \u30EB\u304B\u3089\u306A\u308B\u30AB\u30AF\u30BF\u30B9 \u2192 \u3080\u308A\n \
    \ */\n  static_assert(!GT::is_directed);\n  const int N = G.N, M = G.M;\n  if\
    \ (N == 1) return {{}, {}};\n  bool FOUND = 0;\n  vvc<int> cyc; // edge index\n\
    \  vc<int> in_cycle(M, -1);\n  vc<int> path_v;\n  vc<int> path_e;\n  vc<bool>\
    \ used(M);\n  vc<bool> vis(N);\n  pair<int, int> cid = {-1, -1};\n  auto dfs =\
    \ [&](auto &dfs, int v) -> void {\n    for (auto &e: G[v]) {\n      if (FOUND)\
    \ return;\n      if (used[e.id]) continue;\n      used[e.id] = 1;\n\n      if\
    \ (!vis[e.to]) {\n        vis[e.to] = 1, used[e.id] = 1;\n        path_v.eb(e.to),\
    \ path_e.eb(e.id);\n        dfs(dfs, e.to);\n        if (FOUND) return;\n    \
    \    POP(path_v), POP(path_e);\n        continue;\n      }\n      // cycle \u767A\
    \u898B\n      vc<int> EID = {e.id};\n      int p = len(path_v) - 1;\n      while\
    \ (path_v[p] != e.to) { EID.eb(path_e[--p]); }\n      int k = len(cyc);\n    \
    \  cyc.eb(EID);\n      if (len(EID) % 2 == 0) {\n        cid = {k, k}, FOUND =\
    \ 1;\n        return;\n      }\n      for (auto &i: EID) {\n        if (in_cycle[i]\
    \ != -1) {\n          cid = {k, in_cycle[i]}, FOUND = 1;\n          return;\n\
    \        }\n        in_cycle[i] = k;\n      }\n    }\n  };\n  FOR(v, N) {\n  \
    \  if (vis[v]) continue;\n    path_v = {int(v)};\n    vis[v] = 1;\n    dfs(dfs,\
    \ v);\n  }\n  if (!FOUND) return {{}, {}};\n  vc<int> es = [&]() {\n    if (cid.fi\
    \ == cid.se) { return cyc[cid.fi]; }\n    auto [a, b] = cid;\n    vc<int> use(M);\n\
    \    for (auto &e: cyc[a]) use[e] ^= 1;\n    for (auto &e: cyc[b]) use[e] ^= 1;\n\
    \    vc<int> es;\n    FOR(i, M) if (use[i]) es.eb(i);\n    return es;\n  }();\n\
    \n  vc<pair<int, int>> v_to_e(N, {-1, -1});\n  auto add = [&](int v, int e) ->\
    \ void {\n    if (v_to_e[v].fi == -1) {\n      v_to_e[v].fi = e;\n    } else {\n\
    \      v_to_e[v].se = e;\n    }\n  };\n  for (auto &e: es) { add(G.edges[e].frm,\
    \ e), add(G.edges[e].to, e); }\n\n  int v0 = G.edges[es[0]].frm;\n  vc<int> vs\
    \ = {v0};\n  es.clear(), es.shrink_to_fit();\n  es = {v_to_e[v0].fi};\n  while\
    \ (1) {\n    int e = es.back();\n    int a = G.edges[e].frm, b = G.edges[e].to;\n\
    \    assert(vs.back() == a || vs.back() == b);\n    if (vs.back() != a) swap(a,\
    \ b);\n    vs.eb(b);\n    if (b == v0) break;\n    es.eb(v_to_e[b].fi + v_to_e[b].se\
    \ - e);\n  }\n  return {vs, es};\n}"
  dependsOn:
  - graph/base.hpp
  isVerificationFile: false
  path: graph/find_even_cycle.hpp
  requiredBy: []
  timestamp: '2024-05-29 22:32:29+09:00'
  verificationStatus: LIBRARY_ALL_WA
  verifiedWith:
  - test/mytest/find_even_cycle.test.cpp
documentation_of: graph/find_even_cycle.hpp
layout: document
redirect_from:
- /library/graph/find_even_cycle.hpp
- /library/graph/find_even_cycle.hpp.html
title: graph/find_even_cycle.hpp
---
