---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: flow/maxflow.hpp
    title: flow/maxflow.hpp
  - icon: ':heavy_check_mark:'
    path: graph/base.hpp
    title: graph/base.hpp
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/5_atcoder/abc354g.test.cpp
    title: test/5_atcoder/abc354g.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 1 \"flow/maxflow.hpp\"\n// incremental \u306B\u8FBA\u3092\u8FFD\
    \u52A0\u3057\u3066\u3088\u3044\n// \u8FBA\u306E\u5BB9\u91CF\u306E\u5909\u66F4\u304C\
    \u53EF\u80FD\n// \u5909\u66F4\u3059\u308B capacity \u304C F \u306E\u3068\u304D\
    \u3001O((N+M)|F|) \u6642\u9593\u3067\u66F4\u65B0\ntemplate <typename Cap>\nstruct\
    \ MaxFlow {\n  struct Edge {\n    int to, rev;\n    Cap cap; // \u6B8B\u3063\u3066\
    \u3044\u308B\u5BB9\u91CF. \u3057\u305F\u304C\u3063\u3066 cap+flow \u304C\u5B9A\
    \u6570.\n    Cap flow = 0;\n  };\n\n  const int N, source, sink;\n  vvc<Edge>\
    \ edges;\n  vc<pair<int, int>> pos;\n  vc<int> prog, level;\n  vc<int> que;\n\
    \  bool calculated;\n\n  MaxFlow(int N, int source, int sink)\n      : N(N),\n\
    \        source(source),\n        sink(sink),\n        edges(N),\n        calculated(0),\n\
    \        flow_ans(0) {}\n\n  void add(int frm, int to, Cap cap, Cap rev_cap =\
    \ 0) {\n    calculated = 0;\n    assert(0 <= frm && frm < N);\n    assert(0 <=\
    \ to && to < N);\n    assert(Cap(0) <= cap);\n    int a = len(edges[frm]);\n \
    \   int b = (frm == to ? a + 1 : len(edges[to]));\n    pos.eb(frm, a);\n    edges[frm].eb(Edge{to,\
    \ b, cap, 0});\n    edges[to].eb(Edge{frm, a, rev_cap, 0});\n  }\n\n  void change_capacity(int\
    \ i, Cap after) {\n    auto [frm, idx] = pos[i];\n    auto& e = edges[frm][idx];\n\
    \    Cap before = e.cap + e.flow;\n    if (before < after) {\n      calculated\
    \ = (e.cap > 0);\n      e.cap += after - before;\n      return;\n    }\n    e.cap\
    \ = after - e.flow;\n    // \u5DEE\u5206\u3092\u62BC\u3057\u623B\u3059\u51E6\u7406\
    \u767A\u751F\n    if (e.cap < 0) flow_push_back(e);\n  }\n\n  void flow_push_back(Edge&\
    \ e0) {\n    auto& re0 = edges[e0.to][e0.rev];\n    int a = re0.to;\n    int b\
    \ = e0.to;\n    /*\n    \u8FBA e0 \u306E\u5BB9\u91CF\u304C\u6B63\u306B\u306A\u308B\
    \u3088\u3046\u306B\u623B\u3059\n    path-cycle \u5206\u89E3\u3092\u8003\u3048\u308C\
    \u3070\u3001\n    - uv \u8FBA\u3092\u542B\u3080\u30B5\u30A4\u30AF\u30EB\u3092\u6D88\
    \u3059\n    - suvt \u30D1\u30B9\u3092\u6D88\u3059\n    \u524D\u8005\u306F\u6B8B\
    \u4F59\u30B0\u30E9\u30D5\u3067 ab \u30D1\u30B9\uFF08flow_ans \u304C\u5909\u308F\
    \u3089\u306A\u3044\uFF09\n    \u5F8C\u8005\u306F\u6B8B\u4F59\u30B0\u30E9\u30D5\
    \u3067 tb, as \u30D1\u30B9\n    */\n\n    auto find_path = [&](int s, int t, Cap\
    \ lim) -> Cap {\n      vc<bool> vis(N);\n      prog.assign(N, 0);\n      auto\
    \ dfs = [&](auto& dfs, int v, Cap f) -> Cap {\n        if (v == t) return f;\n\
    \        for (int& i = prog[v]; i < len(edges[v]); ++i) {\n          auto& e =\
    \ edges[v][i];\n          if (vis[e.to] || e.cap <= Cap(0)) continue;\n      \
    \    vis[e.to] = 1;\n          Cap a = dfs(dfs, e.to, min(f, e.cap));\n      \
    \    assert(a >= 0);\n          if (a == Cap(0)) continue;\n          e.cap -=\
    \ a, e.flow += a;\n          edges[e.to][e.rev].cap += a, edges[e.to][e.rev].flow\
    \ -= a;\n          return a;\n        }\n        return 0;\n      };\n      return\
    \ dfs(dfs, s, lim);\n    };\n\n    while (e0.cap < 0) {\n      Cap x = find_path(a,\
    \ b, -e0.cap);\n      if (x == Cap(0)) break;\n      e0.cap += x, e0.flow -= x;\n\
    \      re0.cap -= x, re0.flow += x;\n    }\n    Cap c = -e0.cap;\n    while (c\
    \ > 0 && a != source) {\n      Cap x = find_path(a, source, c);\n      assert(x\
    \ > 0);\n      c -= x;\n    }\n    c = -e0.cap;\n    while (c > 0 && b != sink)\
    \ {\n      Cap x = find_path(sink, b, c);\n      assert(x > 0);\n      c -= x;\n\
    \    }\n    c = -e0.cap;\n    e0.cap += c, e0.flow -= c;\n    re0.cap -= c, re0.flow\
    \ += c;\n    flow_ans -= c;\n  }\n\n  // frm, to, flow\n  vc<tuple<int, int, Cap>>\
    \ get_flow_edges() {\n    vc<tuple<int, int, Cap>> res;\n    FOR(frm, N) {\n \
    \     for (auto&& e: edges[frm]) {\n        if (e.flow <= 0) continue;\n     \
    \   res.eb(frm, e.to, e.flow);\n      }\n    }\n    return res;\n  }\n\n  vc<bool>\
    \ vis;\n\n  // \u5DEE\u5206\u3067\u306F\u306A\u304F\u3053\u308C\u307E\u3067\u306E\
    \u7DCF\u91CF\n  Cap flow() {\n    if (calculated) return flow_ans;\n    calculated\
    \ = true;\n    while (set_level()) {\n      prog.assign(N, 0);\n      while (1)\
    \ {\n        Cap x = flow_dfs(source, infty<Cap>);\n        if (x == 0) break;\n\
    \        flow_ans += x;\n        chmin(flow_ans, infty<Cap>);\n        if (flow_ans\
    \ == infty<Cap>) return flow_ans;\n      }\n    }\n    return flow_ans;\n  }\n\
    \n  // \u6700\u5C0F\u30AB\u30C3\u30C8\u306E\u5024\u304A\u3088\u3073\u3001\u30AB\
    \u30C3\u30C8\u3092\u8868\u3059 01 \u5217\u3092\u8FD4\u3059\n  pair<Cap, vc<int>>\
    \ cut() {\n    flow();\n    vc<int> res(N);\n    FOR(v, N) res[v] = (level[v]\
    \ >= 0 ? 0 : 1);\n    return {flow_ans, res};\n  }\n\n  // O(F(N+M)) \u304F\u3089\
    \u3044\u4F7F\u3063\u3066\u7D4C\u8DEF\u5FA9\u5143\n  // simple path \u306B\u306A\
    \u308B\n  vvc<int> path_decomposition() {\n    flow();\n    auto edges = get_flow_edges();\n\
    \    vvc<int> TO(N);\n    for (auto&& [frm, to, flow]: edges) { FOR(flow) TO[frm].eb(to);\
    \ }\n    vvc<int> res;\n    vc<int> vis(N);\n\n    FOR(flow_ans) {\n      vc<int>\
    \ path = {source};\n      vis[source] = 1;\n      while (path.back() != sink)\
    \ {\n        int to = POP(TO[path.back()]);\n        while (vis[to]) { vis[POP(path)]\
    \ = 0; }\n        path.eb(to), vis[to] = 1;\n      }\n      for (auto&& v: path)\
    \ vis[v] = 0;\n      res.eb(path);\n    }\n    return res;\n  }\n\n  void debug()\
    \ {\n    print(\"source\", source);\n    print(\"sink\", sink);\n    print(\"\
    edges (frm, to, cap, flow)\");\n    FOR(v, N) {\n      for (auto& e: edges[v])\
    \ {\n        if (e.cap == 0 && e.flow == 0) continue;\n        print(v, e.to,\
    \ e.cap, e.flow);\n      }\n    }\n  }\n\nprivate:\n  Cap flow_ans;\n\n  bool\
    \ set_level() {\n    que.resize(N);\n    level.assign(N, -1);\n    level[source]\
    \ = 0;\n    int l = 0, r = 0;\n    que[r++] = source;\n    while (l < r) {\n \
    \     int v = que[l++];\n      for (auto&& e: edges[v]) {\n        if (e.cap >\
    \ 0 && level[e.to] == -1) {\n          level[e.to] = level[v] + 1;\n         \
    \ if (e.to == sink) return true;\n          que[r++] = e.to;\n        }\n    \
    \  }\n    }\n    return false;\n  }\n\n  Cap flow_dfs(int v, Cap lim) {\n    if\
    \ (v == sink) return lim;\n    Cap res = 0;\n    for (int& i = prog[v]; i < len(edges[v]);\
    \ ++i) {\n      auto& e = edges[v][i];\n      if (e.cap > 0 && level[e.to] ==\
    \ level[v] + 1) {\n        Cap a = flow_dfs(e.to, min(lim, e.cap));\n        if\
    \ (a > 0) {\n          e.cap -= a, e.flow += a;\n          edges[e.to][e.rev].cap\
    \ += a, edges[e.to][e.rev].flow -= a;\n          res += a;\n          lim -= a;\n\
    \          if (lim == 0) break;\n        }\n      }\n    }\n    return res;\n\
    \  }\n};\n#line 2 \"graph/base.hpp\"\n\ntemplate <typename T>\nstruct Edge {\n\
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
    \ { vc_indeg[e.to]++, vc_outdeg[e.frm]++; }\n  }\n};\n#line 3 \"graph/maximum_weighted_antichain.hpp\"\
    \n\ntemplate <typename WT, typename GT>\npair<WT, vc<int>> maximum_weighted_antichain(GT&\
    \ G, vc<WT> wt) {\n  int N = G.N;\n  int s = 2 * N, t = 2 * N + 1;\n  MaxFlow<WT>\
    \ F(2 * N + 2, s, t);\n  FOR(i, N) F.add(s, 2 * i + 0, wt[i]);\n  FOR(i, N) F.add(2\
    \ * i + 1, t, wt[i]);\n  for (auto& e: G.edges) F.add(2 * e.frm + 0, 2 * e.to\
    \ + 1, infty<WT>);\n  auto [ans, cut] = F.cut();\n  vc<int> antichain;\n  FOR(v,\
    \ N) {\n    if (cut[2 * v + 0] == 0 && cut[2 * v + 1] == 1) antichain.eb(v);\n\
    \  }\n  ans = SUM<WT>(wt) - ans;\n  return {ans, antichain};\n}\n"
  code: "#include \"flow/maxflow.hpp\"\n#include \"graph/base.hpp\"\n\ntemplate <typename\
    \ WT, typename GT>\npair<WT, vc<int>> maximum_weighted_antichain(GT& G, vc<WT>\
    \ wt) {\n  int N = G.N;\n  int s = 2 * N, t = 2 * N + 1;\n  MaxFlow<WT> F(2 *\
    \ N + 2, s, t);\n  FOR(i, N) F.add(s, 2 * i + 0, wt[i]);\n  FOR(i, N) F.add(2\
    \ * i + 1, t, wt[i]);\n  for (auto& e: G.edges) F.add(2 * e.frm + 0, 2 * e.to\
    \ + 1, infty<WT>);\n  auto [ans, cut] = F.cut();\n  vc<int> antichain;\n  FOR(v,\
    \ N) {\n    if (cut[2 * v + 0] == 0 && cut[2 * v + 1] == 1) antichain.eb(v);\n\
    \  }\n  ans = SUM<WT>(wt) - ans;\n  return {ans, antichain};\n}\n"
  dependsOn:
  - flow/maxflow.hpp
  - graph/base.hpp
  isVerificationFile: false
  path: graph/maximum_weighted_antichain.hpp
  requiredBy: []
  timestamp: '2024-06-11 22:40:57+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/5_atcoder/abc354g.test.cpp
documentation_of: graph/maximum_weighted_antichain.hpp
layout: document
redirect_from:
- /library/graph/maximum_weighted_antichain.hpp
- /library/graph/maximum_weighted_antichain.hpp.html
title: graph/maximum_weighted_antichain.hpp
---
