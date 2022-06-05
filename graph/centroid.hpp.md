---
data:
  _extendedDependsOn:
  - icon: ':question:'
    path: graph/base.hpp
    title: graph/base.hpp
  _extendedRequiredBy:
  - icon: ':heavy_check_mark:'
    path: graph/tree_all_distances.hpp
    title: graph/tree_all_distances.hpp
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/library_checker/tree/frequency_table_of_tree_distance.test.cpp
    title: test/library_checker/tree/frequency_table_of_tree_distance.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/yukicoder/1002_centroid.test.cpp
    title: test/yukicoder/1002_centroid.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/yukicoder/1038_centroid.test.cpp
    title: test/yukicoder/1038_centroid.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 2 \"graph/base.hpp\"\n\ntemplate <typename T>\nstruct Edge {\n\
    \  int frm, to;\n  T cost;\n  int id;\n};\n\ntemplate <typename T = int, bool\
    \ directed = false>\nstruct Graph {\n  int N, M;\n  using cost_type = T;\n  using\
    \ edge_type = Edge<T>;\n  vector<edge_type> edges;\n  vector<int> indptr;\n  vector<edge_type>\
    \ csr_edges;\n  bool prepared;\n\n  class OutgoingEdges {\n  public:\n    OutgoingEdges(const\
    \ Graph* G, int l, int r) : G(G), l(l), r(r) {}\n\n    const edge_type* begin()\
    \ const {\n      if (l == r) { return 0; }\n      return &G->csr_edges[l];\n \
    \   }\n\n    const edge_type* end() const {\n      if (l == r) { return 0; }\n\
    \      return &G->csr_edges[r];\n    }\n\n  private:\n    int l, r;\n    const\
    \ Graph* G;\n  };\n\n  bool is_prepared() { return prepared; }\n  constexpr bool\
    \ is_directed() { return directed; }\n\n  Graph() : N(0), M(0), prepared(0) {}\n\
    \  Graph(int N) : N(N), M(0), prepared(0) {}\n\n  void add(int frm, int to, T\
    \ cost = 1, int i = -1) {\n    assert(!prepared);\n    assert(0 <= frm && 0 <=\
    \ to && to < N);\n    if (i == -1) i = M;\n    auto e = edge_type({frm, to, cost,\
    \ i});\n    edges.eb(e);\n    ++M;\n  }\n\n  // wt, off\n  void read_tree(bool\
    \ wt = false, int off = 1) { read_graph(N - 1, wt, off); }\n\n  void read_graph(int\
    \ M, bool wt = false, int off = 1) {\n    FOR(M) {\n      INT(a, b);\n      a\
    \ -= off, b -= off;\n      if (!wt) {\n        add(a, b);\n      } else {\n  \
    \      T c;\n        read(c);\n        add(a, b, c);\n      }\n    }\n    build();\n\
    \  }\n\n  void read_parent(int off = 1) {\n    FOR3(v, 1, N) {\n      INT(p);\n\
    \      p -= off;\n      add(p, v);\n    }\n    build();\n  }\n\n  void build()\
    \ {\n    assert(!prepared);\n    prepared = true;\n    indptr.assign(N + 1, 0);\n\
    \    for (auto&& e: edges) {\n      indptr[e.frm + 1]++;\n      if (!directed)\
    \ indptr[e.to + 1]++;\n    }\n    FOR(v, N) indptr[v + 1] += indptr[v];\n    auto\
    \ counter = indptr;\n    csr_edges.resize(indptr.back() + 1);\n    for (auto&&\
    \ e: edges) {\n      csr_edges[counter[e.frm]++] = e;\n      if (!directed)\n\
    \        csr_edges[counter[e.to]++] = edge_type({e.to, e.frm, e.cost, e.id});\n\
    \    }\n  }\n\n  OutgoingEdges operator[](int v) const {\n    assert(prepared);\n\
    \    return {this, indptr[v], indptr[v + 1]};\n  }\n\n  void debug() {\n    print(\"\
    Graph\");\n    if (!prepared) {\n      print(\"frm to cost id\");\n      for (auto&&\
    \ e: edges) print(e.frm, e.to, e.cost, e.id);\n    } else {\n      print(\"indptr\"\
    , indptr);\n      print(\"frm to cost id\");\n      FOR(v, N) for (auto&& e: (*this)[v])\
    \ print(e.frm, e.to, e.cost, e.id);\n    }\n  }\n};\n#line 2 \"graph/centroid.hpp\"\
    \ntemplate <typename Graph>\r\nvc<int> find_centroids(Graph& G) {\r\n  int N =\
    \ G.N;\r\n  vc<int> par(N, -1);\r\n  vc<int> V(N);\r\n  vc<int> sz(N);\r\n  int\
    \ l = 0, r = 0;\r\n  V[r++] = 0;\r\n  while (l < r) {\r\n    int v = V[l++];\r\
    \n    for (auto&& e: G[v])\r\n      if (e.to != par[v]) {\r\n        par[e.to]\
    \ = v;\r\n        V[r++] = e.to;\r\n      }\r\n  }\r\n  FOR_R(i, N) {\r\n    int\
    \ v = V[i];\r\n    sz[v] += 1;\r\n    int p = par[v];\r\n    if (p != -1) sz[p]\
    \ += sz[v];\r\n  }\r\n\r\n  int M = N / 2;\r\n  auto check = [&](int v) -> bool\
    \ {\r\n    if (N - sz[v] > M) return false;\r\n    for (auto&& e: G[v]) {\r\n\
    \      if (e.to != par[v] && sz[e.to] > M) return false;\r\n    }\r\n    return\
    \ true;\r\n  };\r\n  vc<int> ANS;\r\n  FOR(v, N) if (check(v)) ANS.eb(v);\r\n\
    \  return ANS;\r\n}\r\n\r\ntemplate <typename Graph, typename E = int>\r\nstruct\
    \ CentroidDecomposition {\r\n  using edge_type = typename Graph::edge_type;\r\n\
    \  using F = function<E(E, edge_type)>;\r\n  Graph& G;\r\n  int N;\r\n  F f; //\
    \ (E path value, edge e) -> E new_path_value\r\n  vc<int> sz;\r\n  vc<int> par;\r\
    \n  vector<int> cdep; // depth in centroid tree\r\n  bool calculated;\r\n\r\n\
    \  CentroidDecomposition(\r\n      Graph& G, F f = [](int x, edge_type e) { return\
    \ x + e.cost; })\r\n      : G(G), N(G.N), f(f), sz(G.N), par(G.N), cdep(G.N, -1)\
    \ {\r\n    calculated = 0;\r\n    build();\r\n  }\r\nprivate:\r\n  int find(int\
    \ v) {\r\n    vc<int> V = {v};\r\n    par[v] = -1;\r\n    int p = 0;\r\n    while\
    \ (p < len(V)) {\r\n      int v = V[p++];\r\n      sz[v] = 0;\r\n      for (auto&&\
    \ e: G[v]) {\r\n        if (e.to == par[v] || cdep[e.to] != -1) continue;\r\n\
    \        par[e.to] = v;\r\n        V.eb(e.to);\r\n      }\r\n    }\r\n    while\
    \ (len(V)) {\r\n      int v = V.back();\r\n      V.pop_back();\r\n      sz[v]\
    \ += 1;\r\n      if (p - sz[v] <= p / 2) return v;\r\n      sz[par[v]] += sz[v];\r\
    \n    }\r\n    return -1;\r\n  }\r\n  void build() {\r\n    assert(G.is_prepared());\r\
    \n    assert(!G.is_directed());\r\n    assert(!calculated);\r\n    calculated\
    \ = 1;\r\n\r\n    vc<pair<int, int>> st;\r\n    st.eb(0, 0);\r\n    while (!st.empty())\
    \ {\r\n      auto [lv, v] = st.back();\r\n      st.pop_back();\r\n      auto c\
    \ = find(v);\r\n      cdep[c] = lv;\r\n      for (auto&& e: G[c]) {\r\n      \
    \  if (cdep[e.to] == -1) { st.eb(lv + 1, e.to); }\r\n      }\r\n    }\r\n  }\r\
    \n\r\npublic:\r\n  vc<vc<pair<int, E>>> collect(int root, E root_val) {\r\n  \
    \  /*\r\n    root \u3092\u91CD\u5FC3\u3068\u3059\u308B\u6728\u306B\u304A\u3044\
    \u3066\u3001(v, path data v) \u306E vector\r\n    \u3092\u3001\u65B9\u5411\u3054\
    \u3068\u306B\u96C6\u3081\u3066\u8FD4\u3059 \u30FB0 \u756A\u76EE\uFF1Aroot \u304B\
    \u3089\u306E\u30D1\u30B9\u3059\u3079\u3066\uFF08root \u3092\u542B\u3080\uFF09\
    \ \u30FBi\r\n    \u756A\u76EE\uFF1Ai \u756A\u76EE\u306E\u65B9\u5411\r\n    */\r\
    \n    vc<vc<pair<int, E>>> res = {{{root, root_val}}};\r\n    for (auto&& e: G[root])\
    \ {\r\n      int nxt = e.to;\r\n      if (cdep[nxt] < cdep[root]) continue;\r\n\
    \      vc<pair<int, E>> dat;\r\n      int p = 0;\r\n      dat.eb(nxt, f(root_val,\
    \ e));\r\n      par[nxt] = root;\r\n      while (p < len(dat)) {\r\n        auto\
    \ [v, val] = dat[p++];\r\n        for (auto&& e: G[v]) {\r\n          if (e.to\
    \ == par[v]) continue;\r\n          if (cdep[e.to] < cdep[root]) continue;\r\n\
    \          par[e.to] = v;\r\n          dat.eb(e.to, f(val, e));\r\n        }\r\
    \n      }\r\n      res.eb(dat);\r\n      res[0].insert(res[0].end(), all(dat));\r\
    \n    }\r\n    return res;\r\n  }\r\n};\r\n"
  code: "#include \"graph/base.hpp\"\r\ntemplate <typename Graph>\r\nvc<int> find_centroids(Graph&\
    \ G) {\r\n  int N = G.N;\r\n  vc<int> par(N, -1);\r\n  vc<int> V(N);\r\n  vc<int>\
    \ sz(N);\r\n  int l = 0, r = 0;\r\n  V[r++] = 0;\r\n  while (l < r) {\r\n    int\
    \ v = V[l++];\r\n    for (auto&& e: G[v])\r\n      if (e.to != par[v]) {\r\n \
    \       par[e.to] = v;\r\n        V[r++] = e.to;\r\n      }\r\n  }\r\n  FOR_R(i,\
    \ N) {\r\n    int v = V[i];\r\n    sz[v] += 1;\r\n    int p = par[v];\r\n    if\
    \ (p != -1) sz[p] += sz[v];\r\n  }\r\n\r\n  int M = N / 2;\r\n  auto check = [&](int\
    \ v) -> bool {\r\n    if (N - sz[v] > M) return false;\r\n    for (auto&& e: G[v])\
    \ {\r\n      if (e.to != par[v] && sz[e.to] > M) return false;\r\n    }\r\n  \
    \  return true;\r\n  };\r\n  vc<int> ANS;\r\n  FOR(v, N) if (check(v)) ANS.eb(v);\r\
    \n  return ANS;\r\n}\r\n\r\ntemplate <typename Graph, typename E = int>\r\nstruct\
    \ CentroidDecomposition {\r\n  using edge_type = typename Graph::edge_type;\r\n\
    \  using F = function<E(E, edge_type)>;\r\n  Graph& G;\r\n  int N;\r\n  F f; //\
    \ (E path value, edge e) -> E new_path_value\r\n  vc<int> sz;\r\n  vc<int> par;\r\
    \n  vector<int> cdep; // depth in centroid tree\r\n  bool calculated;\r\n\r\n\
    \  CentroidDecomposition(\r\n      Graph& G, F f = [](int x, edge_type e) { return\
    \ x + e.cost; })\r\n      : G(G), N(G.N), f(f), sz(G.N), par(G.N), cdep(G.N, -1)\
    \ {\r\n    calculated = 0;\r\n    build();\r\n  }\r\nprivate:\r\n  int find(int\
    \ v) {\r\n    vc<int> V = {v};\r\n    par[v] = -1;\r\n    int p = 0;\r\n    while\
    \ (p < len(V)) {\r\n      int v = V[p++];\r\n      sz[v] = 0;\r\n      for (auto&&\
    \ e: G[v]) {\r\n        if (e.to == par[v] || cdep[e.to] != -1) continue;\r\n\
    \        par[e.to] = v;\r\n        V.eb(e.to);\r\n      }\r\n    }\r\n    while\
    \ (len(V)) {\r\n      int v = V.back();\r\n      V.pop_back();\r\n      sz[v]\
    \ += 1;\r\n      if (p - sz[v] <= p / 2) return v;\r\n      sz[par[v]] += sz[v];\r\
    \n    }\r\n    return -1;\r\n  }\r\n  void build() {\r\n    assert(G.is_prepared());\r\
    \n    assert(!G.is_directed());\r\n    assert(!calculated);\r\n    calculated\
    \ = 1;\r\n\r\n    vc<pair<int, int>> st;\r\n    st.eb(0, 0);\r\n    while (!st.empty())\
    \ {\r\n      auto [lv, v] = st.back();\r\n      st.pop_back();\r\n      auto c\
    \ = find(v);\r\n      cdep[c] = lv;\r\n      for (auto&& e: G[c]) {\r\n      \
    \  if (cdep[e.to] == -1) { st.eb(lv + 1, e.to); }\r\n      }\r\n    }\r\n  }\r\
    \n\r\npublic:\r\n  vc<vc<pair<int, E>>> collect(int root, E root_val) {\r\n  \
    \  /*\r\n    root \u3092\u91CD\u5FC3\u3068\u3059\u308B\u6728\u306B\u304A\u3044\
    \u3066\u3001(v, path data v) \u306E vector\r\n    \u3092\u3001\u65B9\u5411\u3054\
    \u3068\u306B\u96C6\u3081\u3066\u8FD4\u3059 \u30FB0 \u756A\u76EE\uFF1Aroot \u304B\
    \u3089\u306E\u30D1\u30B9\u3059\u3079\u3066\uFF08root \u3092\u542B\u3080\uFF09\
    \ \u30FBi\r\n    \u756A\u76EE\uFF1Ai \u756A\u76EE\u306E\u65B9\u5411\r\n    */\r\
    \n    vc<vc<pair<int, E>>> res = {{{root, root_val}}};\r\n    for (auto&& e: G[root])\
    \ {\r\n      int nxt = e.to;\r\n      if (cdep[nxt] < cdep[root]) continue;\r\n\
    \      vc<pair<int, E>> dat;\r\n      int p = 0;\r\n      dat.eb(nxt, f(root_val,\
    \ e));\r\n      par[nxt] = root;\r\n      while (p < len(dat)) {\r\n        auto\
    \ [v, val] = dat[p++];\r\n        for (auto&& e: G[v]) {\r\n          if (e.to\
    \ == par[v]) continue;\r\n          if (cdep[e.to] < cdep[root]) continue;\r\n\
    \          par[e.to] = v;\r\n          dat.eb(e.to, f(val, e));\r\n        }\r\
    \n      }\r\n      res.eb(dat);\r\n      res[0].insert(res[0].end(), all(dat));\r\
    \n    }\r\n    return res;\r\n  }\r\n};\r\n"
  dependsOn:
  - graph/base.hpp
  isVerificationFile: false
  path: graph/centroid.hpp
  requiredBy:
  - graph/tree_all_distances.hpp
  timestamp: '2022-05-13 20:32:38+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/yukicoder/1002_centroid.test.cpp
  - test/yukicoder/1038_centroid.test.cpp
  - test/library_checker/tree/frequency_table_of_tree_distance.test.cpp
documentation_of: graph/centroid.hpp
layout: document
redirect_from:
- /library/graph/centroid.hpp
- /library/graph/centroid.hpp.html
title: graph/centroid.hpp
---
