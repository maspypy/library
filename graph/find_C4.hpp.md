---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: graph/base.hpp
    title: graph/base.hpp
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':warning:'
  attributes:
    links:
    - https://codeforces.com/problemset/problem/1468/M
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
    \ }\n  }\n};\n#line 2 \"graph/find_C4.hpp\"\n\n// \u7121\u5411\u30B0\u30E9\u30D5\
    \u304B\u3089 C4 \u3092\u3072\u3068\u3064\u898B\u3064\u3051\u308B\n// https://codeforces.com/problemset/problem/1468/M\n\
    template <typename GT>\ntuple<int, int, int, int> find_C4(GT& G) {\n  assert(!G.is_directed());\n\
    \  int N = G.N;\n  auto deg = G.deg_array();\n  auto I = argsort(deg);\n  reverse(all(I));\n\
    \  vc<int> rk(N);\n  FOR(i, N) rk[I[i]] = i;\n\n  // \u9077\u79FB\u5148\u3092\u964D\
    \u9806\u306B\u4E26\u3079\u308B\n  vvc<int> TO(N);\n  for (auto&& e: G.edges) {\n\
    \    int a = rk[e.frm], b = rk[e.to];\n    TO[a].eb(b);\n    TO[b].eb(a);\n  }\n\
    \  FOR(v, N) {\n    sort(all(TO[v]));\n    reverse(all(TO[v]));\n  }\n  vc<int>\
    \ par(N, -1);\n  FOR(a, N) {\n    for (auto&& b: TO[a]) TO[b].pop_back();\n  \
    \  for (auto&& b: TO[a]) {\n      for (auto&& c: TO[b]) {\n        if (par[c]\
    \ != -1) { return {I[a], I[b], I[c], I[par[c]]}; }\n        par[c] = b;\n    \
    \  }\n    }\n    for (auto&& b: TO[a]) {\n      for (auto&& c: TO[b]) { par[c]\
    \ = -1; }\n    }\n  }\n  return {-1, -1, -1, -1};\n}\n"
  code: "#include \"graph/base.hpp\"\n\n// \u7121\u5411\u30B0\u30E9\u30D5\u304B\u3089\
    \ C4 \u3092\u3072\u3068\u3064\u898B\u3064\u3051\u308B\n// https://codeforces.com/problemset/problem/1468/M\n\
    template <typename GT>\ntuple<int, int, int, int> find_C4(GT& G) {\n  assert(!G.is_directed());\n\
    \  int N = G.N;\n  auto deg = G.deg_array();\n  auto I = argsort(deg);\n  reverse(all(I));\n\
    \  vc<int> rk(N);\n  FOR(i, N) rk[I[i]] = i;\n\n  // \u9077\u79FB\u5148\u3092\u964D\
    \u9806\u306B\u4E26\u3079\u308B\n  vvc<int> TO(N);\n  for (auto&& e: G.edges) {\n\
    \    int a = rk[e.frm], b = rk[e.to];\n    TO[a].eb(b);\n    TO[b].eb(a);\n  }\n\
    \  FOR(v, N) {\n    sort(all(TO[v]));\n    reverse(all(TO[v]));\n  }\n  vc<int>\
    \ par(N, -1);\n  FOR(a, N) {\n    for (auto&& b: TO[a]) TO[b].pop_back();\n  \
    \  for (auto&& b: TO[a]) {\n      for (auto&& c: TO[b]) {\n        if (par[c]\
    \ != -1) { return {I[a], I[b], I[c], I[par[c]]}; }\n        par[c] = b;\n    \
    \  }\n    }\n    for (auto&& b: TO[a]) {\n      for (auto&& c: TO[b]) { par[c]\
    \ = -1; }\n    }\n  }\n  return {-1, -1, -1, -1};\n}\n"
  dependsOn:
  - graph/base.hpp
  isVerificationFile: false
  path: graph/find_C4.hpp
  requiredBy: []
  timestamp: '2023-11-01 01:33:38+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: graph/find_C4.hpp
layout: document
redirect_from:
- /library/graph/find_C4.hpp
- /library/graph/find_C4.hpp.html
title: graph/find_C4.hpp
---
