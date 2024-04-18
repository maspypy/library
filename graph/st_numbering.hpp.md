---
data:
  _extendedDependsOn:
  - icon: ':question:'
    path: graph/base.hpp
    title: graph/base.hpp
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':x:'
    path: test/mytest/st_numbering.test.cpp
    title: test/mytest/st_numbering.test.cpp
  _isVerificationFailed: true
  _pathExtension: hpp
  _verificationStatusIcon: ':x:'
  attributes:
    links:
    - https://en.wikipedia.org/wiki/Bipolar_orientation
  bundledCode: "#line 1 \"graph/st_numbering.hpp\"\n\n#line 2 \"graph/base.hpp\"\n\
    \ntemplate <typename T>\nstruct Edge {\n  int frm, to;\n  T cost;\n  int id;\n\
    };\n\ntemplate <typename T = int, bool directed = false>\nstruct Graph {\n  static\
    \ constexpr bool is_directed = directed;\n  int N, M;\n  using cost_type = T;\n\
    \  using edge_type = Edge<T>;\n  vector<edge_type> edges;\n  vector<int> indptr;\n\
    \  vector<edge_type> csr_edges;\n  vc<int> vc_deg, vc_indeg, vc_outdeg;\n  bool\
    \ prepared;\n\n  class OutgoingEdges {\n  public:\n    OutgoingEdges(const Graph*\
    \ G, int l, int r) : G(G), l(l), r(r) {}\n\n    const edge_type* begin() const\
    \ {\n      if (l == r) { return 0; }\n      return &G->csr_edges[l];\n    }\n\n\
    \    const edge_type* end() const {\n      if (l == r) { return 0; }\n      return\
    \ &G->csr_edges[r];\n    }\n\n  private:\n    const Graph* G;\n    int l, r;\n\
    \  };\n\n  bool is_prepared() { return prepared; }\n\n  Graph() : N(0), M(0),\
    \ prepared(0) {}\n  Graph(int N) : N(N), M(0), prepared(0) {}\n\n  void build(int\
    \ n) {\n    N = n, M = 0;\n    prepared = 0;\n    edges.clear();\n    indptr.clear();\n\
    \    csr_edges.clear();\n    vc_deg.clear();\n    vc_indeg.clear();\n    vc_outdeg.clear();\n\
    \  }\n\n  void add(int frm, int to, T cost = 1, int i = -1) {\n    assert(!prepared);\n\
    \    assert(0 <= frm && 0 <= to && to < N);\n    if (i == -1) i = M;\n    auto\
    \ e = edge_type({frm, to, cost, i});\n    edges.eb(e);\n    ++M;\n  }\n\n#ifdef\
    \ FASTIO\n  // wt, off\n  void read_tree(bool wt = false, int off = 1) { read_graph(N\
    \ - 1, wt, off); }\n\n  void read_graph(int M, bool wt = false, int off = 1) {\n\
    \    for (int m = 0; m < M; ++m) {\n      INT(a, b);\n      a -= off, b -= off;\n\
    \      if (!wt) {\n        add(a, b);\n      } else {\n        T c;\n        read(c);\n\
    \        add(a, b, c);\n      }\n    }\n    build();\n  }\n#endif\n\n  void build()\
    \ {\n    assert(!prepared);\n    prepared = true;\n    indptr.assign(N + 1, 0);\n\
    \    for (auto&& e: edges) {\n      indptr[e.frm + 1]++;\n      if (!directed)\
    \ indptr[e.to + 1]++;\n    }\n    for (int v = 0; v < N; ++v) { indptr[v + 1]\
    \ += indptr[v]; }\n    auto counter = indptr;\n    csr_edges.resize(indptr.back()\
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
    \    return vc_outdeg[v];\n  }\n\n#ifdef FASTIO\n  void debug() {\n    print(\"\
    Graph\");\n    if (!prepared) {\n      print(\"frm to cost id\");\n      for (auto&&\
    \ e: edges) print(e.frm, e.to, e.cost, e.id);\n    } else {\n      print(\"indptr\"\
    , indptr);\n      print(\"frm to cost id\");\n      FOR(v, N) for (auto&& e: (*this)[v])\
    \ print(e.frm, e.to, e.cost, e.id);\n    }\n  }\n#endif\n\n  vc<int> new_idx;\n\
    \  vc<bool> used_e;\n\n  // G \u306B\u304A\u3051\u308B\u9802\u70B9 V[i] \u304C\
    \u3001\u65B0\u3057\u3044\u30B0\u30E9\u30D5\u3067 i \u306B\u306A\u308B\u3088\u3046\
    \u306B\u3059\u308B\n  // {G, es}\n  Graph<T, directed> rearrange(vc<int> V, bool\
    \ keep_eid = 0) {\n    if (len(new_idx) != N) new_idx.assign(N, -1);\n    int\
    \ n = len(V);\n    FOR(i, n) new_idx[V[i]] = i;\n    Graph<T, directed> G(n);\n\
    \    vc<int> history;\n    FOR(i, n) {\n      for (auto&& e: (*this)[V[i]]) {\n\
    \        if (len(used_e) <= e.id) used_e.resize(e.id + 1);\n        if (used_e[e.id])\
    \ continue;\n        int a = e.frm, b = e.to;\n        if (new_idx[a] != -1 &&\
    \ new_idx[b] != -1) {\n          history.eb(e.id);\n          used_e[e.id] = 1;\n\
    \          int eid = (keep_eid ? e.id : -1);\n          G.add(new_idx[a], new_idx[b],\
    \ e.cost, eid);\n        }\n      }\n    }\n    FOR(i, n) new_idx[V[i]] = -1;\n\
    \    for (auto&& eid: history) used_e[eid] = 0;\n    G.build();\n    return G;\n\
    \  }\n\nprivate:\n  void calc_deg() {\n    assert(vc_deg.empty());\n    vc_deg.resize(N);\n\
    \    for (auto&& e: edges) vc_deg[e.frm]++, vc_deg[e.to]++;\n  }\n\n  void calc_deg_inout()\
    \ {\n    assert(vc_indeg.empty());\n    vc_indeg.resize(N);\n    vc_outdeg.resize(N);\n\
    \    for (auto&& e: edges) { vc_indeg[e.to]++, vc_outdeg[e.frm]++; }\n  }\n};\n\
    #line 3 \"graph/st_numbering.hpp\"\n\n// https://en.wikipedia.org/wiki/Bipolar_orientation\n\
    // \u9806\u5217 p \u3092\u6C42\u3081\u308B. s=p[0], ..., p[n-1]=t.\n// \u3053\u306E\
    \u9806\u3067\u5411\u304D\u4ED8\u3051\u308B\u3068\u4EFB\u610F\u306E v \u306B\u5BFE\
    \u3057\u3066 svt \u30D1\u30B9\u304C\u5B58\u5728.\n// \u5B58\u5728\u6761\u4EF6\uFF1A\
    BCT \u3067\u5168\u90E8\u306E\u6210\u5206\u3092\u901A\u308B st \u30D1\u30B9\u304C\
    \u3042\u308B \u4E0D\u53EF\u80FD\u306A\u3089\u3070 empty \u3092\u304B\u3048\u3059\
    .\ntemplate <typename GT>\nvc<int> st_numbering(GT &G, int s, int t) {\n  static_assert(!GT::is_directed);\n\
    \  assert(G.is_prepared());\n  int N = G.N;\n  if (N == 1) return {0};\n  if (s\
    \ == t) return {};\n  vc<int> par(N, -1), pre(N, -1), low(N, -1);\n  vc<int> V;\n\
    \n  auto dfs = [&](auto &dfs, int v) -> void {\n    pre[v] = len(V), V.eb(v);\n\
    \    low[v] = v;\n    for (auto &e: G[v]) {\n      int w = e.to;\n      if (v\
    \ == w) continue;\n      if (pre[w] == -1) {\n        dfs(dfs, w);\n        par[w]\
    \ = v;\n        if (pre[low[w]] < pre[low[v]]) { low[v] = low[w]; }\n      }\n\
    \      elif (pre[w] < pre[low[v]]) { low[v] = w; }\n    }\n  };\n\n  pre[s] =\
    \ 0, V.eb(s);\n  dfs(dfs, t);\n  if (len(V) != N) return {};\n  vc<int> nxt(N,\
    \ -1), prev(N);\n  nxt[s] = t, prev[t] = s;\n\n  vc<int> sgn(N);\n  sgn[s] = -1;\n\
    \  FOR(i, 2, len(V)) {\n    int v = V[i];\n    int p = par[v];\n    if (sgn[low[v]]\
    \ == -1) {\n      int q = prev[p];\n      if (q == -1) return {};\n      nxt[q]\
    \ = v, nxt[v] = p;\n      prev[v] = q, prev[p] = v;\n      sgn[p] = 1;\n    }\
    \ else {\n      int q = nxt[p];\n      if (q == -1) return {};\n      nxt[p] =\
    \ v, nxt[v] = q;\n      prev[v] = p, prev[q] = v;\n      sgn[p] = -1;\n    }\n\
    \  }\n  vc<int> A = {s};\n  while (A.back() != t) { A.eb(nxt[A.back()]); }\n \
    \ // \u4F5C\u308C\u3066\u3044\u308B\u304B\u5224\u5B9A\n  if (len(A) < N) return\
    \ {};\n  assert(A[0] == s && A.back() == t);\n  vc<int> rk(N, -1);\n  FOR(i, N)\
    \ rk[A[i]] = i;\n  assert(MIN(rk) != -1);\n  FOR(i, N) {\n    bool l = 0, r =\
    \ 0;\n    int v = A[i];\n    for (auto &e: G[v]) {\n      if (rk[e.to] < rk[v])\
    \ l = 1;\n      if (rk[v] < rk[e.to]) r = 1;\n    }\n    if (i > 0 && !l) return\
    \ {};\n    if (i < N - 1 && !r) return {};\n  }\n  return A;\n}\n"
  code: "\n#include \"graph/base.hpp\"\n\n// https://en.wikipedia.org/wiki/Bipolar_orientation\n\
    // \u9806\u5217 p \u3092\u6C42\u3081\u308B. s=p[0], ..., p[n-1]=t.\n// \u3053\u306E\
    \u9806\u3067\u5411\u304D\u4ED8\u3051\u308B\u3068\u4EFB\u610F\u306E v \u306B\u5BFE\
    \u3057\u3066 svt \u30D1\u30B9\u304C\u5B58\u5728.\n// \u5B58\u5728\u6761\u4EF6\uFF1A\
    BCT \u3067\u5168\u90E8\u306E\u6210\u5206\u3092\u901A\u308B st \u30D1\u30B9\u304C\
    \u3042\u308B \u4E0D\u53EF\u80FD\u306A\u3089\u3070 empty \u3092\u304B\u3048\u3059\
    .\ntemplate <typename GT>\nvc<int> st_numbering(GT &G, int s, int t) {\n  static_assert(!GT::is_directed);\n\
    \  assert(G.is_prepared());\n  int N = G.N;\n  if (N == 1) return {0};\n  if (s\
    \ == t) return {};\n  vc<int> par(N, -1), pre(N, -1), low(N, -1);\n  vc<int> V;\n\
    \n  auto dfs = [&](auto &dfs, int v) -> void {\n    pre[v] = len(V), V.eb(v);\n\
    \    low[v] = v;\n    for (auto &e: G[v]) {\n      int w = e.to;\n      if (v\
    \ == w) continue;\n      if (pre[w] == -1) {\n        dfs(dfs, w);\n        par[w]\
    \ = v;\n        if (pre[low[w]] < pre[low[v]]) { low[v] = low[w]; }\n      }\n\
    \      elif (pre[w] < pre[low[v]]) { low[v] = w; }\n    }\n  };\n\n  pre[s] =\
    \ 0, V.eb(s);\n  dfs(dfs, t);\n  if (len(V) != N) return {};\n  vc<int> nxt(N,\
    \ -1), prev(N);\n  nxt[s] = t, prev[t] = s;\n\n  vc<int> sgn(N);\n  sgn[s] = -1;\n\
    \  FOR(i, 2, len(V)) {\n    int v = V[i];\n    int p = par[v];\n    if (sgn[low[v]]\
    \ == -1) {\n      int q = prev[p];\n      if (q == -1) return {};\n      nxt[q]\
    \ = v, nxt[v] = p;\n      prev[v] = q, prev[p] = v;\n      sgn[p] = 1;\n    }\
    \ else {\n      int q = nxt[p];\n      if (q == -1) return {};\n      nxt[p] =\
    \ v, nxt[v] = q;\n      prev[v] = p, prev[q] = v;\n      sgn[p] = -1;\n    }\n\
    \  }\n  vc<int> A = {s};\n  while (A.back() != t) { A.eb(nxt[A.back()]); }\n \
    \ // \u4F5C\u308C\u3066\u3044\u308B\u304B\u5224\u5B9A\n  if (len(A) < N) return\
    \ {};\n  assert(A[0] == s && A.back() == t);\n  vc<int> rk(N, -1);\n  FOR(i, N)\
    \ rk[A[i]] = i;\n  assert(MIN(rk) != -1);\n  FOR(i, N) {\n    bool l = 0, r =\
    \ 0;\n    int v = A[i];\n    for (auto &e: G[v]) {\n      if (rk[e.to] < rk[v])\
    \ l = 1;\n      if (rk[v] < rk[e.to]) r = 1;\n    }\n    if (i > 0 && !l) return\
    \ {};\n    if (i < N - 1 && !r) return {};\n  }\n  return A;\n}\n"
  dependsOn:
  - graph/base.hpp
  isVerificationFile: false
  path: graph/st_numbering.hpp
  requiredBy: []
  timestamp: '2024-04-19 02:20:22+09:00'
  verificationStatus: LIBRARY_ALL_WA
  verifiedWith:
  - test/mytest/st_numbering.test.cpp
documentation_of: graph/st_numbering.hpp
layout: document
redirect_from:
- /library/graph/st_numbering.hpp
- /library/graph/st_numbering.hpp.html
title: graph/st_numbering.hpp
---
