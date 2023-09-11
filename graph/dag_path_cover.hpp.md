---
data:
  _extendedDependsOn:
  - icon: ':question:'
    path: ds/unionfind/unionfind.hpp
    title: ds/unionfind/unionfind.hpp
  - icon: ':x:'
    path: flow/maxflow.hpp
    title: flow/maxflow.hpp
  - icon: ':question:'
    path: graph/base.hpp
    title: graph/base.hpp
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':x:'
    path: test/aoj/2251_1.test.cpp
    title: test/aoj/2251_1.test.cpp
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
    \ }\n  }\n};\n#line 1 \"flow/maxflow.hpp\"\n// incremental \u306B\u8FBA\u3092\u8FFD\
    \u52A0\u3057\u3066\u3088\u3044\ntemplate <typename Cap>\nstruct MaxFlow {\n  struct\
    \ Edge {\n    int to, rev;\n    Cap cap;\n    Cap flow = 0;\n  };\n\n  const int\
    \ N, source, sink;\n  vvc<Edge> edges;\n  vc<int> prog, level;\n  vc<int> que;\n\
    \  bool calculated;\n  Cap flow_ans;\n\n  MaxFlow(int N, int source, int sink)\n\
    \      : N(N),\n        source(source),\n        sink(sink),\n        edges(N),\n\
    \        calculated(0),\n        flow_ans(0) {}\n\n  void add(int frm, int to,\
    \ Cap cap, Cap rev_cap = 0) {\n    calculated = 0;\n    assert(0 <= frm && frm\
    \ < N);\n    assert(0 <= to && to < N);\n    assert(frm != to);\n    assert(Cap(0)\
    \ <= cap);\n    if (frm == to) return;\n    int a = len(edges[frm]);\n    int\
    \ b = len(edges[to]);\n    edges[frm].eb(Edge{to, b, cap, 0});\n    edges[to].eb(Edge{frm,\
    \ a, cap, 0});\n  }\n\n  // frm, to, flow\n  vc<tuple<int, int, Cap>> get_flow_edges()\
    \ {\n    vc<tuple<int, int, Cap>> res;\n    FOR(frm, N) {\n      for (auto&& e:\
    \ edges[frm]) {\n        if (e.flow == 0) continue;\n        res.eb(frm, e.to,\
    \ e.flow);\n      }\n    }\n    return res;\n  }\n\n  // \u5DEE\u5206\u3067\u306F\
    \u306A\u304F\u3053\u308C\u307E\u3067\u306E\u7DCF\u91CF\n  Cap flow() {\n    if\
    \ (calculated) return flow_ans;\n    calculated = true;\n    while (set_level())\
    \ {\n      prog.assign(N, 0);\n      while (1) {\n        Cap x = flow_dfs(source,\
    \ infty<Cap>);\n        if (x == 0) break;\n        flow_ans += x;\n        chmin(flow_ans,\
    \ infty<Cap>);\n        if (flow_ans == infty<Cap>) return flow_ans;\n      }\n\
    \    }\n    return flow_ans;\n  }\n\n  // \u6700\u5C0F\u30AB\u30C3\u30C8\u306E\
    \u5024\u304A\u3088\u3073\u3001\u30AB\u30C3\u30C8\u3092\u8868\u3059 01 \u5217\u3092\
    \u8FD4\u3059\n  pair<Cap, vc<int>> cut() {\n    flow();\n    vc<int> res(N);\n\
    \    FOR(v, N) res[v] = (level[v] >= 0 ? 0 : 1);\n    return {flow_ans, res};\n\
    \  }\n\n  // O(F(N+M)) \u304F\u3089\u3044\u4F7F\u3063\u3066\u7D4C\u8DEF\u5FA9\u5143\
    \n  // simple path \u306B\u306A\u308B\n  vvc<int> path_decomposition() {\n   \
    \ flow();\n    auto edges = get_flow_edges();\n    vvc<int> TO(N);\n    for (auto&&\
    \ [frm, to, flow]: edges) { FOR(flow) TO[frm].eb(to); }\n    vvc<int> res;\n \
    \   vc<int> vis(N);\n\n    FOR(flow_ans) {\n      vc<int> path = {source};\n \
    \     vis[source] = 1;\n      while (path.back() != sink) {\n        int to =\
    \ POP(TO[path.back()]);\n        while (vis[to]) { vis[POP(path)] = 0; }\n   \
    \     path.eb(to), vis[to] = 1;\n      }\n      for (auto&& v: path) vis[v] =\
    \ 0;\n      res.eb(path);\n    }\n    return res;\n  }\n\nprivate:\n  bool set_level()\
    \ {\n    que.resize(N);\n    level.assign(N, -1);\n    level[source] = 0;\n  \
    \  int l = 0, r = 0;\n    que[r++] = source;\n    while (l < r) {\n      int v\
    \ = que[l++];\n      for (auto&& e: edges[v]) {\n        if (e.cap > 0 && level[e.to]\
    \ == -1) {\n          level[e.to] = level[v] + 1;\n          if (e.to == sink)\
    \ return true;\n          que[r++] = e.to;\n        }\n      }\n    }\n    return\
    \ false;\n  }\n\n  Cap flow_dfs(int v, Cap lim) {\n    if (v == sink) return lim;\n\
    \    Cap res = 0;\n    for (int& i = prog[v]; i < len(edges[v]); ++i) {\n    \
    \  auto& e = edges[v][i];\n      if (e.cap > 0 && level[e.to] == level[v] + 1)\
    \ {\n        Cap a = flow_dfs(e.to, min(lim, e.cap));\n        if (a > 0) {\n\
    \          e.cap -= a, e.flow += a;\n          edges[e.to][e.rev].cap += a, edges[e.to][e.rev].flow\
    \ -= a;\n          res += a;\n          lim -= a;\n          if (lim == 0) break;\n\
    \        }\n      }\n    }\n    return res;\n  }\n};\n#line 2 \"ds/unionfind/unionfind.hpp\"\
    \n\nstruct UnionFind {\n  int n, n_comp;\n  vc<int> dat; // par or (-size)\n \
    \ UnionFind(int n = 0) { build(n); }\n\n  void build(int m) {\n    n = m, n_comp\
    \ = m;\n    dat.assign(n, -1);\n  }\n\n  void reset() { build(n); }\n\n  int operator[](int\
    \ x) {\n    while (dat[x] >= 0) {\n      int pp = dat[dat[x]];\n      if (pp <\
    \ 0) { return dat[x]; }\n      x = dat[x] = pp;\n    }\n    return x;\n  }\n\n\
    \  ll size(int x) {\n    x = (*this)[x];\n    return -dat[x];\n  }\n\n  bool merge(int\
    \ x, int y) {\n    x = (*this)[x], y = (*this)[y];\n    if (x == y) return false;\n\
    \    if (-dat[x] < -dat[y]) swap(x, y);\n    dat[x] += dat[y], dat[y] = x, n_comp--;\n\
    \    return true;\n  }\n};\n#line 4 \"graph/dag_path_cover.hpp\"\n\n// \u5404\u9802\
    \u70B9\u306E\u8272\u3092\u304B\u3048\u3059\u3002\u5404\u8272\u306F\u3072\u3068\
    \u3064\u306E\u30D1\u30B9\u4E0A\u306B\u3042\u308B\u3088\u3046\u306B\u3059\u308B\
    \ntemplate <typename DAG>\nvc<int> dag_path_cover(DAG& G) {\n  assert(G.is_directed());\n\
    \  for (auto&& e: G.edges) assert(e.frm < e.to);\n\n  int N = G.N;\n  int source\
    \ = 2 * N, sink = 2 * N + 1;\n  MaxFlow<int> F(2 * N + 2, source, sink);\n  FOR(v,\
    \ N) {\n    F.add(source, 2 * v + 1, 1);\n    F.add(2 * v + 0, sink, 1);\n   \
    \ F.add(2 * v + 0, 2 * v + 1, infty<int>);\n  }\n  for (auto&& e: G.edges) F.add(2\
    \ * e.frm + 1, 2 * e.to + 0, infty<int>);\n\n  int flow = F.flow();\n\n  vvc<pair<int,\
    \ int>> flow_edges(N + N + 2);\n  for (auto&& [a, b, c]: F.get_flow_edges()) {\
    \ flow_edges[a].eb(b, c); }\n\n  UnionFind uf(N);\n  for (auto&& [a, f]: flow_edges[source])\
    \ {\n    assert(f == 1);\n    int b = a;\n    while (1) {\n      auto [to, x]\
    \ = POP(flow_edges[b]);\n      x -= 1;\n      if (x > 0) flow_edges[b].eb(to,\
    \ x);\n      if (to == sink) break;\n      b = to;\n    }\n    uf.merge(a / 2,\
    \ b / 2);\n  }\n\n  vc<int> ANS(N, -1);\n  int p = 0;\n  FOR(v, N) if (uf[v] ==\
    \ v) ANS[v] = p++;\n  FOR(v, N) if (uf[v] != v) ANS[v] = ANS[uf[v]];\n  return\
    \ ANS;\n};\n"
  code: "#include \"graph/base.hpp\"\n#include \"flow/maxflow.hpp\"\n#include \"ds/unionfind/unionfind.hpp\"\
    \n\n// \u5404\u9802\u70B9\u306E\u8272\u3092\u304B\u3048\u3059\u3002\u5404\u8272\
    \u306F\u3072\u3068\u3064\u306E\u30D1\u30B9\u4E0A\u306B\u3042\u308B\u3088\u3046\
    \u306B\u3059\u308B\ntemplate <typename DAG>\nvc<int> dag_path_cover(DAG& G) {\n\
    \  assert(G.is_directed());\n  for (auto&& e: G.edges) assert(e.frm < e.to);\n\
    \n  int N = G.N;\n  int source = 2 * N, sink = 2 * N + 1;\n  MaxFlow<int> F(2\
    \ * N + 2, source, sink);\n  FOR(v, N) {\n    F.add(source, 2 * v + 1, 1);\n \
    \   F.add(2 * v + 0, sink, 1);\n    F.add(2 * v + 0, 2 * v + 1, infty<int>);\n\
    \  }\n  for (auto&& e: G.edges) F.add(2 * e.frm + 1, 2 * e.to + 0, infty<int>);\n\
    \n  int flow = F.flow();\n\n  vvc<pair<int, int>> flow_edges(N + N + 2);\n  for\
    \ (auto&& [a, b, c]: F.get_flow_edges()) { flow_edges[a].eb(b, c); }\n\n  UnionFind\
    \ uf(N);\n  for (auto&& [a, f]: flow_edges[source]) {\n    assert(f == 1);\n \
    \   int b = a;\n    while (1) {\n      auto [to, x] = POP(flow_edges[b]);\n  \
    \    x -= 1;\n      if (x > 0) flow_edges[b].eb(to, x);\n      if (to == sink)\
    \ break;\n      b = to;\n    }\n    uf.merge(a / 2, b / 2);\n  }\n\n  vc<int>\
    \ ANS(N, -1);\n  int p = 0;\n  FOR(v, N) if (uf[v] == v) ANS[v] = p++;\n  FOR(v,\
    \ N) if (uf[v] != v) ANS[v] = ANS[uf[v]];\n  return ANS;\n};\n"
  dependsOn:
  - graph/base.hpp
  - flow/maxflow.hpp
  - ds/unionfind/unionfind.hpp
  isVerificationFile: false
  path: graph/dag_path_cover.hpp
  requiredBy: []
  timestamp: '2023-09-12 01:16:35+09:00'
  verificationStatus: LIBRARY_ALL_WA
  verifiedWith:
  - test/aoj/2251_1.test.cpp
documentation_of: graph/dag_path_cover.hpp
layout: document
redirect_from:
- /library/graph/dag_path_cover.hpp
- /library/graph/dag_path_cover.hpp.html
title: graph/dag_path_cover.hpp
---
