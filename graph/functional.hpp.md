---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: ds/unionfind.hpp
    title: ds/unionfind.hpp
  - icon: ':heavy_check_mark:'
    path: graph/base.hpp
    title: graph/base.hpp
  - icon: ':heavy_check_mark:'
    path: graph/hld.hpp
    title: graph/hld.hpp
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':warning:'
  attributes:
    links: []
  bundledCode: "#line 2 \"ds/unionfind.hpp\"\n\nstruct UnionFind {\n  int num;\n \
    \ int comp;\n  vc<int> size, par;\n  UnionFind(int n) : num(n), comp(n), size(n,\
    \ 1), par(n) {\n    iota(par.begin(), par.end(), 0);\n  }\n  int find(int x) {\n\
    \    while (par[x] != x) {\n      par[x] = par[par[x]];\n      x = par[x];\n \
    \   }\n    return x;\n  }\n\n  int operator[](int x) { return find(x); }\n\n \
    \ bool merge(ll x, ll y) {\n    x = find(x);\n    y = find(y);\n    if (x == y)\
    \ { return false; }\n    comp--;\n    if (size[x] < size[y]) swap(x, y);\n   \
    \ size[x] += size[y];\n    size[y] = 0;\n    par[y] = x;\n    return true;\n \
    \ }\n\n  vc<int> find_all() {\n    vc<int> A(num);\n    FOR(i, num) A[i] = find(i);\n\
    \    return A;\n  }\n\n  void reset(){\n    comp = num;\n    size.assign(num,\
    \ 1);\n    iota(all(par), 0);\n  }\n};\n#line 2 \"graph/base.hpp\"\n\ntemplate\
    \ <typename T>\nstruct Edge {\n  int frm, to;\n  T cost;\n  int id;\n};\n\ntemplate\
    \ <typename T = int, bool directed = false>\nstruct Graph {\n  int N, M;\n  using\
    \ cost_type = T;\n  using edge_type = Edge<T>;\n  vector<edge_type> edges;\n \
    \ vector<int> indptr;\n  vector<edge_type> csr_edges;\n  bool prepared;\n\n  class\
    \ OutgoingEdges {\n  public:\n    OutgoingEdges(const Graph* G, int l, int r)\
    \ : G(G), l(l), r(r) {}\n\n    const edge_type* begin() const {\n      if (l ==\
    \ r) { return 0; }\n      return &G->csr_edges[l];\n    }\n\n    const edge_type*\
    \ end() const {\n      if (l == r) { return 0; }\n      return &G->csr_edges[r];\n\
    \    }\n\n  private:\n    int l, r;\n    const Graph* G;\n  };\n\n  bool is_prepared()\
    \ { return prepared; }\n  constexpr bool is_directed() { return directed; }\n\n\
    \  Graph() : N(0), M(0), prepared(0) {}\n  Graph(int N) : N(N), M(0), prepared(0)\
    \ {}\n\n  void add(int frm, int to, T cost = 1, int i = -1) {\n    assert(!prepared);\n\
    \    assert(0 <= frm && 0 <= to && to < N);\n    if (i == -1) i = M;\n    auto\
    \ e = edge_type({frm, to, cost, i});\n    edges.eb(e);\n    ++M;\n  }\n\n  //\
    \ wt, off\n  void read_tree(bool wt = false, int off = 1) { read_graph(N - 1,\
    \ wt, off); }\n\n  void read_graph(int M, bool wt = false, int off = 1) {\n  \
    \  FOR(M) {\n      INT(a, b);\n      a -= off, b -= off;\n      if (!wt) {\n \
    \       add(a, b);\n      } else {\n        T c;\n        read(c);\n        add(a,\
    \ b, c);\n      }\n    }\n    build();\n  }\n\n  void read_parent(int off = 1)\
    \ {\n    FOR3(v, 1, N) {\n      INT(p);\n      p -= off;\n      add(p, v);\n \
    \   }\n    build();\n  }\n\n  void build() {\n    assert(!prepared);\n    prepared\
    \ = true;\n    indptr.assign(N + 1, 0);\n    for (auto&& e: edges) {\n      indptr[e.frm\
    \ + 1]++;\n      if (!directed) indptr[e.to + 1]++;\n    }\n    FOR(v, N) indptr[v\
    \ + 1] += indptr[v];\n    auto counter = indptr;\n    csr_edges.resize(indptr.back()\
    \ + 1);\n    for (auto&& e: edges) {\n      csr_edges[counter[e.frm]++] = e;\n\
    \      if (!directed)\n        csr_edges[counter[e.to]++] = edge_type({e.to, e.frm,\
    \ e.cost, e.id});\n    }\n  }\n\n  OutgoingEdges operator[](int v) const {\n \
    \   assert(prepared);\n    return {this, indptr[v], indptr[v + 1]};\n  }\n\n \
    \ void debug() {\n    print(\"Graph\");\n    if (!prepared) {\n      print(\"\
    frm to cost id\");\n      for (auto&& e: edges) print(e.frm, e.to, e.cost, e.id);\n\
    \    } else {\n      print(\"indptr\", indptr);\n      print(\"frm to cost id\"\
    );\n      FOR(v, N) for (auto&& e: (*this)[v]) print(e.frm, e.to, e.cost, e.id);\n\
    \    }\n  }\n};\n#line 3 \"graph/hld.hpp\"\n\r\n/*\r\nHL\u5206\u89E3\u3002O(N)\
    \ \u6642\u9593\u69CB\u7BC9\u3002\r\nLCA, LA \u306A\u3069\u306F O(logN) \u6642\u9593\
    \u3002\r\n\u6728\u4EE5\u5916\u3001\u975E\u9023\u7D50\u3067\u3082\u4F7F\u3048\u308B\
    \u3088\u3046\u306B\u3057\u305F\u3002dfs\u9806\u5E8F\u3084\u89AA\u304C\u3068\u308C\
    \u308B\u3002\r\n*/\r\ntemplate <typename Graph>\r\nstruct HLD {\r\n  Graph &G;\r\
    \n  using Graph_type = Graph;\r\n  using WT = typename Graph::cost_type;\r\n \
    \ int N;\r\n  vector<int> LID, RID, head, V, parent, root;\r\n  vc<int> depth;\r\
    \n  vc<WT> depth_weighted;\r\n  vector<bool> in_tree;\r\n\r\n  HLD(Graph &G, int\
    \ r = -1)\r\n      : G(G),\r\n        N(G.N),\r\n        LID(G.N),\r\n       \
    \ RID(G.N),\r\n        head(G.N, r),\r\n        V(G.N),\r\n        parent(G.N,\
    \ -1),\r\n        depth(G.N, -1),\r\n        depth_weighted(G.N, 0),\r\n     \
    \   root(G.N, -1),\r\n        in_tree(G.M, 0) {\r\n    assert(G.is_prepared());\r\
    \n    int t1 = 0;\r\n    if (r != -1) {\r\n      dfs_sz(r, -1);\r\n      dfs_hld(r,\
    \ t1);\r\n    } else {\r\n      FOR(r, N) if (parent[r] == -1) {\r\n        head[r]\
    \ = r;\r\n        dfs_sz(r, -1);\r\n        dfs_hld(r, t1);\r\n      }\r\n   \
    \ }\r\n    for (auto &&v: V) root[v] = (parent[v] == -1 ? v : root[parent[v]]);\r\
    \n  }\r\n\r\n  void dfs_sz(int v, int p) {\r\n    auto &sz = RID;\r\n    parent[v]\
    \ = p;\r\n    depth[v] = (p == -1 ? 0 : depth[p] + 1);\r\n    sz[v] = 1;\r\n \
    \   int l = G.indptr[v], r = G.indptr[v + 1];\r\n    auto &csr = G.csr_edges;\r\
    \n    // \u4F7F\u3046\u8FBA\u304C\u3042\u308C\u3070\u5148\u982D\u306B\u3059\u308B\
    \r\n    FOR3_R(i, l, r - 1) {\r\n      if (depth[csr[i + 1].to] == -1) swap(csr[i],\
    \ csr[i + 1]);\r\n    }\r\n    int hld_sz = 0;\r\n    for (int i = l; i < r; ++i)\
    \ {\r\n      auto e = csr[i];\r\n      if (depth[e.to] != -1) continue;\r\n  \
    \    in_tree[e.id] = 1;\r\n      depth_weighted[e.to] = depth_weighted[v] + e.cost;\r\
    \n      dfs_sz(e.to, v);\r\n      sz[v] += sz[e.to];\r\n      if (chmax(hld_sz,\
    \ sz[e.to]) && l < i) { swap(csr[l], csr[i]); }\r\n    }\r\n  }\r\n\r\n  void\
    \ dfs_hld(int v, int &times) {\r\n    LID[v] = times++;\r\n    RID[v] += LID[v];\r\
    \n    V[LID[v]] = v;\r\n    bool heavy = true;\r\n    for (auto &&e: G[v]) {\r\
    \n      if (!in_tree[e.id] || depth[e.to] <= depth[v]) continue;\r\n      head[e.to]\
    \ = (heavy ? head[v] : e.to);\r\n      heavy = false;\r\n      dfs_hld(e.to, times);\r\
    \n    }\r\n  }\r\n\r\n  int e_to_v(int eid) {\r\n    auto e = G.edges[eid];\r\n\
    \    return (parent[e.frm] == e.to ? e.frm : e.to);\r\n  }\r\n\r\n  int ELID(int\
    \ v) { return 2 * LID[v] - depth[v]; }\r\n  int ERID(int v) { return 2 * RID[v]\
    \ - depth[v] - 1; }\r\n\r\n  /* k: 0-indexed */\r\n  int LA(int v, int k) {\r\n\
    \    while (1) {\r\n      int u = head[v];\r\n      if (LID[v] - k >= LID[u])\
    \ return V[LID[v] - k];\r\n      k -= LID[v] - LID[u] + 1;\r\n      v = parent[u];\r\
    \n    }\r\n  }\r\n\r\n  int LCA(int u, int v) {\r\n    for (;; v = parent[head[v]])\
    \ {\r\n      if (LID[u] > LID[v]) swap(u, v);\r\n      if (head[u] == head[v])\
    \ return u;\r\n    }\r\n  }\r\n\r\n  int lca(int u, int v) { return LCA(u, v);\
    \ }\r\n  int la(int u, int v) { return LA(u, v); }\r\n\r\n  int subtree_size(int\
    \ v) { return RID[v] - LID[v]; }\r\n\r\n  int dist(int a, int b) {\r\n    int\
    \ c = LCA(a, b);\r\n    return depth[a] + depth[b] - 2 * depth[c];\r\n  }\r\n\r\
    \n  WT dist(int a, int b, bool weighted) {\r\n    assert(weighted);\r\n    int\
    \ c = LCA(a, b);\r\n    return depth_weighted[a] + depth_weighted[b] - 2 * depth_weighted[c];\r\
    \n  }\r\n\r\n  bool in_subtree(int a, int b) { return LID[b] <= LID[a] && LID[a]\
    \ < RID[b]; }\r\n\r\n  int move(int a, int b) {\r\n    assert(a != b);\r\n   \
    \ return (in_subtree(b, a) ? LA(b, depth[b] - depth[a] - 1) : parent[a]);\r\n\
    \  }\r\n\r\n  vc<int> collect_child(int v) {\r\n    vc<int> res;\r\n    for (auto\
    \ &&e: G[v])\r\n      if (e.to != parent[v]) res.eb(e.to);\r\n    return res;\r\
    \n  }\r\n\r\n  vc<pair<int, int>> get_path_decomposition(int u, int v, bool edge)\
    \ {\r\n    // [\u59CB\u70B9, \u7D42\u70B9] \u306E\"\u9589\"\u533A\u9593\u5217\u3002\
    \r\n    vc<pair<int, int>> up, down;\r\n    while (1) {\r\n      if (head[u] ==\
    \ head[v]) break;\r\n      if (LID[u] < LID[v]) {\r\n        down.eb(LID[head[v]],\
    \ LID[v]);\r\n        v = parent[head[v]];\r\n      } else {\r\n        up.eb(LID[u],\
    \ LID[head[u]]);\r\n        u = parent[head[u]];\r\n      }\r\n    }\r\n    if\
    \ (LID[u] < LID[v]) down.eb(LID[u] + edge, LID[v]);\r\n    elif (LID[v] + edge\
    \ <= LID[u]) up.eb(LID[u], LID[v] + edge);\r\n    reverse(all(down));\r\n    up.insert(up.end(),\
    \ all(down));\r\n    return up;\r\n  }\r\n\r\n  void debug() {\r\n    print(\"\
    V\", V);\r\n    print(\"LID\", LID);\r\n    print(\"RID\", RID);\r\n    print(\"\
    parent\", parent);\r\n    print(\"depth\", depth);\r\n    print(\"head\", head);\r\
    \n    print(\"in_tree(edge)\", in_tree);\r\n    print(\"root\", root);\r\n  }\r\
    \n};\r\n#line 4 \"graph/functional.hpp\"\n\r\ntemplate <typename T = int>\r\n\
    struct FunctionalGraph {\r\n  int N, M;\r\n  Graph<T, 1> tree; // \u65B0\u3057\
    \u3044\u9802\u70B9 N \u3092\u6839\u3068\u3057\u3066\u8FFD\u52A0\u3057\u305F\u6709\
    \u5411\u6728\u3002\u9006\u5411\u304D\u306E\u8FBA\u306B\u306A\u308B\u3002\r\n \
    \ // HLD<Graph<T, 1>> hld;\r\n  vc<int> TO;\r\n  vc<T> wt;\r\n  vc<int> root;\r\
    \n\r\n  FunctionalGraph() {}\r\n  FunctionalGraph(int N) : N(N), M(0), TO(N, -1),\
    \ wt(N), root(N, -1) {}\r\n\r\n  void add(int a, int b, T c = 1) {\r\n    assert(0\
    \ <= a && a < N);\r\n    assert(TO[a] == -1);\r\n    ++M;\r\n    TO[a] = b;\r\n\
    \    wt[a] = c;\r\n  }\r\n\r\n  void build() {\r\n    assert(N == M);\r\n    UnionFind\
    \ uf(N);\r\n    FOR(v, N) if (!uf.merge(v, TO[v])) { root[v] = v; }\r\n    FOR(v,\
    \ N) if (root[v] == v) root[uf[v]] = v;\r\n    FOR(v, N) root[v] = root[uf[v]];\r\
    \n\r\n    tree = Graph<T, 1>(N + 1);\r\n    FOR(v, N) {\r\n      if (root[v] !=\
    \ v)\r\n        tree.add(TO[v], v);\r\n      else\r\n        tree.add(N, v);\r\
    \n    }\r\n    tree.prepare();\r\n  }\r\n\r\n  void debug() {\r\n    print(\"\
    TO\", TO);\r\n    print(\"root\");\r\n    print(root);\r\n    print(\"\u6839\u3092\
    \u8FFD\u52A0\u3057\u305F\u6728 tree\");\r\n    tree.debug();\r\n  }\r\n};\r\n"
  code: "#include \"ds/unionfind.hpp\"\r\n#include \"graph/base.hpp\"\r\n#include\
    \ \"graph/hld.hpp\"\r\n\r\ntemplate <typename T = int>\r\nstruct FunctionalGraph\
    \ {\r\n  int N, M;\r\n  Graph<T, 1> tree; // \u65B0\u3057\u3044\u9802\u70B9 N\
    \ \u3092\u6839\u3068\u3057\u3066\u8FFD\u52A0\u3057\u305F\u6709\u5411\u6728\u3002\
    \u9006\u5411\u304D\u306E\u8FBA\u306B\u306A\u308B\u3002\r\n  // HLD<Graph<T, 1>>\
    \ hld;\r\n  vc<int> TO;\r\n  vc<T> wt;\r\n  vc<int> root;\r\n\r\n  FunctionalGraph()\
    \ {}\r\n  FunctionalGraph(int N) : N(N), M(0), TO(N, -1), wt(N), root(N, -1) {}\r\
    \n\r\n  void add(int a, int b, T c = 1) {\r\n    assert(0 <= a && a < N);\r\n\
    \    assert(TO[a] == -1);\r\n    ++M;\r\n    TO[a] = b;\r\n    wt[a] = c;\r\n\
    \  }\r\n\r\n  void build() {\r\n    assert(N == M);\r\n    UnionFind uf(N);\r\n\
    \    FOR(v, N) if (!uf.merge(v, TO[v])) { root[v] = v; }\r\n    FOR(v, N) if (root[v]\
    \ == v) root[uf[v]] = v;\r\n    FOR(v, N) root[v] = root[uf[v]];\r\n\r\n    tree\
    \ = Graph<T, 1>(N + 1);\r\n    FOR(v, N) {\r\n      if (root[v] != v)\r\n    \
    \    tree.add(TO[v], v);\r\n      else\r\n        tree.add(N, v);\r\n    }\r\n\
    \    tree.prepare();\r\n  }\r\n\r\n  void debug() {\r\n    print(\"TO\", TO);\r\
    \n    print(\"root\");\r\n    print(root);\r\n    print(\"\u6839\u3092\u8FFD\u52A0\
    \u3057\u305F\u6728 tree\");\r\n    tree.debug();\r\n  }\r\n};\r\n"
  dependsOn:
  - ds/unionfind.hpp
  - graph/base.hpp
  - graph/hld.hpp
  isVerificationFile: false
  path: graph/functional.hpp
  requiredBy: []
  timestamp: '2022-05-23 16:54:27+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: graph/functional.hpp
layout: document
redirect_from:
- /library/graph/functional.hpp
- /library/graph/functional.hpp.html
title: graph/functional.hpp
---
