---
data:
  _extendedDependsOn:
  - icon: ':question:'
    path: enumerate/product.hpp
    title: enumerate/product.hpp
  - icon: ':question:'
    path: graph/base.hpp
    title: graph/base.hpp
  - icon: ':x:'
    path: graph/prufer_code.hpp
    title: graph/prufer_code.hpp
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':warning:'
  attributes:
    links:
    - https://codeforces.com/contest/611/problem/H
  bundledCode: "#line 1 \"enumerate/product.hpp\"\n// [0, A0) x [0, A1) x ...\ntemplate\
    \ <typename F>\nvoid enumerate_product(vc<int> A, F query) {\n  int N = len(A);\n\
    \  auto dfs = [&](auto& dfs, vc<int>& p) -> void {\n    int n = len(p);\n    if\
    \ (n == N) return query(p);\n    FOR(x, A[n]) {\n      p.eb(x);\n      dfs(dfs,\
    \ p);\n      p.pop_back();\n    }\n  };\n  vc<int> p;\n  dfs(dfs, p);\n}\n#line\
    \ 2 \"graph/base.hpp\"\n\ntemplate <typename T>\nstruct Edge {\n  int frm, to;\n\
    \  T cost;\n  int id;\n};\n\ntemplate <typename T = int, bool directed = false>\n\
    struct Graph {\n  static constexpr bool is_directed = directed;\n  int N, M;\n\
    \  using cost_type = T;\n  using edge_type = Edge<T>;\n  vector<edge_type> edges;\n\
    \  vector<int> indptr;\n  vector<edge_type> csr_edges;\n  vc<int> vc_deg, vc_indeg,\
    \ vc_outdeg;\n  bool prepared;\n\n  class OutgoingEdges {\n  public:\n    OutgoingEdges(const\
    \ Graph* G, int l, int r) : G(G), l(l), r(r) {}\n\n    const edge_type* begin()\
    \ const {\n      if (l == r) { return 0; }\n      return &G->csr_edges[l];\n \
    \   }\n\n    const edge_type* end() const {\n      if (l == r) { return 0; }\n\
    \      return &G->csr_edges[r];\n    }\n\n  private:\n    const Graph* G;\n  \
    \  int l, r;\n  };\n\n  bool is_prepared() { return prepared; }\n\n  Graph() :\
    \ N(0), M(0), prepared(0) {}\n  Graph(int N) : N(N), M(0), prepared(0) {}\n\n\
    \  void build(int n) {\n    N = n, M = 0;\n    prepared = 0;\n    edges.clear();\n\
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
    #line 2 \"graph/prufer_code.hpp\"\n\n// [0,n-1]^{n-1}, \u305F\u3060\u3057\u672B\
    \u5C3E\u306F n-1, \u3068\u3044\u3046\u5B9A\u5F0F\u5316 (n=1 ok)\nvc<int> to_prufer_code(Graph<int,\
    \ 0>& G) {\n  // \u30E9\u30D9\u30EB\u6700\u5C0F\u306E\u8449\u3092\u3068\u308B\
    \ -> \u89AA\u3092\u5217\u306B\u8FFD\u52A0\n  int n = G.N;\n  vc<int> par(n);\n\
    \  {\n    auto dfs = [&](auto& dfs, int v, int p) -> void {\n      par[v] = p;\n\
    \      for (auto& e: G[v])\n        if (e.to != p) dfs(dfs, e.to, v);\n    };\n\
    \    dfs(dfs, n - 1, -1);\n  }\n  vc<int> deg = G.deg_array();\n  vc<int> res(n\
    \ - 1);\n  int p = 0;\n  int leaf = -1;\n  FOR(i, n - 1) {\n    if (leaf == -1)\
    \ {\n      while (deg[p] != 1) ++p;\n      leaf = p;\n    }\n    res[i] = par[leaf];\n\
    \    deg[leaf]--, deg[par[leaf]]--;\n    leaf = (deg[par[leaf]] == 1 && par[leaf]\
    \ < p ? par[leaf] : -1);\n  }\n  return res;\n}\n\nGraph<int, 0> from_prufer_code(vc<int>\
    \ code) {\n  int n = len(code) + 1;\n  Graph<int, 0> G(n);\n  if (n == 1) return\
    \ G;\n  assert(code.back() == n - 1);\n  vc<int> deg(n, 1);\n  for (auto& v: code)\
    \ deg[v]++;\n\n  int p = 0;\n  int leaf = -1;\n  FOR(i, n - 1) {\n    if (leaf\
    \ == -1) {\n      while (deg[p] != 1) p++;\n      leaf = p;\n    }\n    G.add(code[i],\
    \ leaf);\n    deg[leaf]--, deg[code[i]]--;\n    leaf = (code[i] < p && deg[code[i]]\
    \ == 1 ? code[i] : -1);\n  }\n  G.build();\n  return G;\n}\n#line 3 \"enumerate/labeled_tree.hpp\"\
    \n\n// https://codeforces.com/contest/611/problem/H\ntemplate <typename F>\nvoid\
    \ enumerate_labeled_tree(int N, F f) {\n  if (N == 1) {\n    Graph<int, 0> G(N);\n\
    \    f(G);\n    return;\n  }\n  enumerate_product(vc<int>(N - 2, N), [&](vc<int>\
    \ A) -> void {\n    A.eb(N - 1);\n    Graph<int, 0> G = from_prufer_code(A);\n\
    \    f(G);\n  });\n}\n"
  code: "#include \"enumerate/product.hpp\"\n#include \"graph/prufer_code.hpp\"\n\n\
    // https://codeforces.com/contest/611/problem/H\ntemplate <typename F>\nvoid enumerate_labeled_tree(int\
    \ N, F f) {\n  if (N == 1) {\n    Graph<int, 0> G(N);\n    f(G);\n    return;\n\
    \  }\n  enumerate_product(vc<int>(N - 2, N), [&](vc<int> A) -> void {\n    A.eb(N\
    \ - 1);\n    Graph<int, 0> G = from_prufer_code(A);\n    f(G);\n  });\n}\n"
  dependsOn:
  - enumerate/product.hpp
  - graph/prufer_code.hpp
  - graph/base.hpp
  isVerificationFile: false
  path: enumerate/labeled_tree.hpp
  requiredBy: []
  timestamp: '2024-05-24 21:01:28+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: enumerate/labeled_tree.hpp
layout: document
redirect_from:
- /library/enumerate/labeled_tree.hpp
- /library/enumerate/labeled_tree.hpp.html
title: enumerate/labeled_tree.hpp
---