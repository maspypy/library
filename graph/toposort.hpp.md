---
data:
  _extendedDependsOn:
  - icon: ':question:'
    path: graph/base.hpp
    title: graph/base.hpp
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':warning:'
  attributes:
    links:
    - https://codeforces.com/contest/798/problem/E
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
    \ { vc_indeg[e.to]++, vc_outdeg[e.frm]++; }\n  }\n};\n#line 2 \"graph/toposort.hpp\"\
    \n\n// DAG \u3058\u3083\u306A\u304B\u3063\u305F\u3089\u7A7A\u914D\u5217\n// \u8F9E\
    \u66F8\u9806\u6700\u5C0F\u3082\u3067\u304D\u308B\uFF1AO(NlogN) \u2192 abc223\n\
    template <typename Graph>\nvc<int> toposort(Graph& G, bool lex_min = false) {\n\
    \  assert(G.is_prepared());\n  assert(G.is_directed());\n  auto [indeg, outdeg]\
    \ = G.deg_array_inout();\n  if (!lex_min) {\n    vc<int> V;\n    ll N = G.N;\n\
    \    FOR(v, N) if (indeg[v] == 0) V.eb(v);\n    ll p = 0;\n    while (p < len(V))\
    \ {\n      auto v = V[p++];\n      for (auto&& e: G[v]) {\n        if (--indeg[e.to]\
    \ == 0) V.eb(e.to);\n      }\n    }\n    if (len(V) < N) { V.clear(); }\n    return\
    \ V;\n  } else {\n    pqg<int> que;\n    vc<int> V;\n    ll N = G.N;\n    FOR(v,\
    \ N) if (indeg[v] == 0) que.push(v);\n    while (len(que)) {\n      auto v = que.top();\n\
    \      que.pop();\n      V.eb(v);\n      for (auto&& e: G[v]) {\n        if (--indeg[e.to]\
    \ == 0) que.push(e.to);\n      }\n    }\n    if (len(V) < N) { V.clear(); }\n\
    \    return V;\n  }\n}\n\n// https://codeforces.com/contest/798/problem/E\n//\
    \ toposort \u306E\u5019\u88DC\u3092\u3072\u3068\u3064\u51FA\u529B\u3059\u308B\u3002\
    \u30C1\u30A7\u30C3\u30AF\u306F\u3057\u306A\u3044\u3002\n// \u967D\u306B\u30B0\u30E9\
    \u30D5\u3092\u4F5C\u3089\u305A\u3001\u4F55\u3089\u304B\u306E\u30C7\u30FC\u30BF\
    \u69CB\u9020\u3067\u672A\u8A2A\u554F\u306E\u884C\u304D\u5148\u3092\u63A2\u3059\
    \u60F3\u5B9A\u3002\n// set_used(v)\uFF1Av \u3092\u4F7F\u7528\u6E08\u306B\u5909\
    \u66F4\u3059\u308B\n// find_unused(v)\uFF1Av \u306E\u884C\u304D\u5148\u3092\u63A2\
    \u3059\u3002\u306A\u3051\u308C\u3070 -1 \u3092\u8FD4\u3059\u3053\u3068\u3002\n\
    template <typename F1, typename F2>\nvc<int> toposort(int N, F1 set_used, F2 find_unused)\
    \ {\n  vc<int> V;\n  vc<bool> done(N);\n  auto dfs = [&](auto self, ll v) -> void\
    \ {\n    set_used(v);\n    done[v] = 1;\n    while (1) {\n      int to = find_unused(v);\n\
    \      if (to == -1) break;\n      self(self, to);\n    }\n    V.eb(v);\n  };\n\
    \  FOR(v, N) if (!done[v]) dfs(dfs, v);\n  return V;\n}\n"
  code: "#include \"graph/base.hpp\"\n\n// DAG \u3058\u3083\u306A\u304B\u3063\u305F\
    \u3089\u7A7A\u914D\u5217\n// \u8F9E\u66F8\u9806\u6700\u5C0F\u3082\u3067\u304D\u308B\
    \uFF1AO(NlogN) \u2192 abc223\ntemplate <typename Graph>\nvc<int> toposort(Graph&\
    \ G, bool lex_min = false) {\n  assert(G.is_prepared());\n  assert(G.is_directed());\n\
    \  auto [indeg, outdeg] = G.deg_array_inout();\n  if (!lex_min) {\n    vc<int>\
    \ V;\n    ll N = G.N;\n    FOR(v, N) if (indeg[v] == 0) V.eb(v);\n    ll p = 0;\n\
    \    while (p < len(V)) {\n      auto v = V[p++];\n      for (auto&& e: G[v])\
    \ {\n        if (--indeg[e.to] == 0) V.eb(e.to);\n      }\n    }\n    if (len(V)\
    \ < N) { V.clear(); }\n    return V;\n  } else {\n    pqg<int> que;\n    vc<int>\
    \ V;\n    ll N = G.N;\n    FOR(v, N) if (indeg[v] == 0) que.push(v);\n    while\
    \ (len(que)) {\n      auto v = que.top();\n      que.pop();\n      V.eb(v);\n\
    \      for (auto&& e: G[v]) {\n        if (--indeg[e.to] == 0) que.push(e.to);\n\
    \      }\n    }\n    if (len(V) < N) { V.clear(); }\n    return V;\n  }\n}\n\n\
    // https://codeforces.com/contest/798/problem/E\n// toposort \u306E\u5019\u88DC\
    \u3092\u3072\u3068\u3064\u51FA\u529B\u3059\u308B\u3002\u30C1\u30A7\u30C3\u30AF\
    \u306F\u3057\u306A\u3044\u3002\n// \u967D\u306B\u30B0\u30E9\u30D5\u3092\u4F5C\u3089\
    \u305A\u3001\u4F55\u3089\u304B\u306E\u30C7\u30FC\u30BF\u69CB\u9020\u3067\u672A\
    \u8A2A\u554F\u306E\u884C\u304D\u5148\u3092\u63A2\u3059\u60F3\u5B9A\u3002\n// set_used(v)\uFF1A\
    v \u3092\u4F7F\u7528\u6E08\u306B\u5909\u66F4\u3059\u308B\n// find_unused(v)\uFF1A\
    v \u306E\u884C\u304D\u5148\u3092\u63A2\u3059\u3002\u306A\u3051\u308C\u3070 -1\
    \ \u3092\u8FD4\u3059\u3053\u3068\u3002\ntemplate <typename F1, typename F2>\n\
    vc<int> toposort(int N, F1 set_used, F2 find_unused) {\n  vc<int> V;\n  vc<bool>\
    \ done(N);\n  auto dfs = [&](auto self, ll v) -> void {\n    set_used(v);\n  \
    \  done[v] = 1;\n    while (1) {\n      int to = find_unused(v);\n      if (to\
    \ == -1) break;\n      self(self, to);\n    }\n    V.eb(v);\n  };\n  FOR(v, N)\
    \ if (!done[v]) dfs(dfs, v);\n  return V;\n}\n"
  dependsOn:
  - graph/base.hpp
  isVerificationFile: false
  path: graph/toposort.hpp
  requiredBy: []
  timestamp: '2022-08-30 02:42:36+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: graph/toposort.hpp
layout: document
redirect_from:
- /library/graph/toposort.hpp
- /library/graph/toposort.hpp.html
title: graph/toposort.hpp
---
