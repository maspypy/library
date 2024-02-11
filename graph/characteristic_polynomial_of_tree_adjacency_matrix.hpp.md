---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: ds/unionfind/unionfind.hpp
    title: ds/unionfind/unionfind.hpp
  - icon: ':heavy_check_mark:'
    path: graph/base.hpp
    title: graph/base.hpp
  - icon: ':heavy_check_mark:'
    path: graph/ds/static_toptree.hpp
    title: graph/ds/static_toptree.hpp
  - icon: ':heavy_check_mark:'
    path: graph/shortest_path/bfs01.hpp
    title: graph/shortest_path/bfs01.hpp
  - icon: ':heavy_check_mark:'
    path: graph/tree.hpp
    title: graph/tree.hpp
  _extendedRequiredBy:
  - icon: ':heavy_check_mark:'
    path: graph/tree_walk_generating_function.hpp
    title: graph/tree_walk_generating_function.hpp
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/mytest/tree_walk_gf.test.cpp
    title: test/mytest/tree_walk_gf.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/yukicoder/2587.test.cpp
    title: test/yukicoder/2587.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/yukicoder/2587_2.test.cpp
    title: test/yukicoder/2587_2.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 2 \"graph/tree.hpp\"\n\r\n#line 2 \"graph/base.hpp\"\n\ntemplate\
    \ <typename T>\nstruct Edge {\n  int frm, to;\n  T cost;\n  int id;\n};\n\ntemplate\
    \ <typename T = int, bool directed = false>\nstruct Graph {\n  static constexpr\
    \ bool is_directed = directed;\n  int N, M;\n  using cost_type = T;\n  using edge_type\
    \ = Edge<T>;\n  vector<edge_type> edges;\n  vector<int> indptr;\n  vector<edge_type>\
    \ csr_edges;\n  vc<int> vc_deg, vc_indeg, vc_outdeg;\n  bool prepared;\n\n  class\
    \ OutgoingEdges {\n  public:\n    OutgoingEdges(const Graph* G, int l, int r)\
    \ : G(G), l(l), r(r) {}\n\n    const edge_type* begin() const {\n      if (l ==\
    \ r) { return 0; }\n      return &G->csr_edges[l];\n    }\n\n    const edge_type*\
    \ end() const {\n      if (l == r) { return 0; }\n      return &G->csr_edges[r];\n\
    \    }\n\n  private:\n    const Graph* G;\n    int l, r;\n  };\n\n  bool is_prepared()\
    \ { return prepared; }\n\n  Graph() : N(0), M(0), prepared(0) {}\n  Graph(int\
    \ N) : N(N), M(0), prepared(0) {}\n\n  void build(int n) {\n    N = n, M = 0;\n\
    \    prepared = 0;\n    edges.clear();\n    indptr.clear();\n    csr_edges.clear();\n\
    \    vc_deg.clear();\n    vc_indeg.clear();\n    vc_outdeg.clear();\n  }\n\n \
    \ void add(int frm, int to, T cost = 1, int i = -1) {\n    assert(!prepared);\n\
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
    \ keep_eid = 0) {\n    if (len(new_idx) != N) new_idx.assign(N, -1);\n    if (len(used_e)\
    \ != M) used_e.assign(M, 0);\n    int n = len(V);\n    FOR(i, n) new_idx[V[i]]\
    \ = i;\n    Graph<T, directed> G(n);\n    vc<int> history;\n    FOR(i, n) {\n\
    \      for (auto&& e: (*this)[V[i]]) {\n        if (used_e[e.id]) continue;\n\
    \        int a = e.frm, b = e.to;\n        if (new_idx[a] != -1 && new_idx[b]\
    \ != -1) {\n          history.eb(e.id);\n          used_e[e.id] = 1;\n       \
    \   int eid = (keep_eid ? e.id : -1);\n          G.add(new_idx[a], new_idx[b],\
    \ e.cost, eid);\n        }\n      }\n    }\n    FOR(i, n) new_idx[V[i]] = -1;\n\
    \    for (auto&& eid: history) used_e[eid] = 0;\n    G.build();\n    return G;\n\
    \  }\n\nprivate:\n  void calc_deg() {\n    assert(vc_deg.empty());\n    vc_deg.resize(N);\n\
    \    for (auto&& e: edges) vc_deg[e.frm]++, vc_deg[e.to]++;\n  }\n\n  void calc_deg_inout()\
    \ {\n    assert(vc_indeg.empty());\n    vc_indeg.resize(N);\n    vc_outdeg.resize(N);\n\
    \    for (auto&& e: edges) { vc_indeg[e.to]++, vc_outdeg[e.frm]++; }\n  }\n};\n\
    #line 4 \"graph/tree.hpp\"\n\r\n// HLD euler tour \u3092\u3068\u3063\u3066\u3044\
    \u308D\u3044\u308D\u3002\r\ntemplate <typename GT>\r\nstruct Tree {\r\n  using\
    \ Graph_type = GT;\r\n  GT &G;\r\n  using WT = typename GT::cost_type;\r\n  int\
    \ N;\r\n  vector<int> LID, RID, head, V, parent, VtoE;\r\n  vc<int> depth;\r\n\
    \  vc<WT> depth_weighted;\r\n\r\n  Tree(GT &G, int r = 0, bool hld = 1) : G(G)\
    \ { build(r, hld); }\r\n\r\n  void build(int r = 0, bool hld = 1) {\r\n    if\
    \ (r == -1) return; // build \u3092\u9045\u5EF6\u3057\u305F\u3044\u3068\u304D\r\
    \n    N = G.N;\r\n    LID.assign(N, -1), RID.assign(N, -1), head.assign(N, r);\r\
    \n    V.assign(N, -1), parent.assign(N, -1), VtoE.assign(N, -1);\r\n    depth.assign(N,\
    \ -1), depth_weighted.assign(N, 0);\r\n    assert(G.is_prepared());\r\n    int\
    \ t1 = 0;\r\n    dfs_sz(r, -1, hld);\r\n    dfs_hld(r, t1);\r\n  }\r\n\r\n  void\
    \ dfs_sz(int v, int p, bool hld) {\r\n    auto &sz = RID;\r\n    parent[v] = p;\r\
    \n    depth[v] = (p == -1 ? 0 : depth[p] + 1);\r\n    sz[v] = 1;\r\n    int l\
    \ = G.indptr[v], r = G.indptr[v + 1];\r\n    auto &csr = G.csr_edges;\r\n    //\
    \ \u4F7F\u3046\u8FBA\u304C\u3042\u308C\u3070\u5148\u982D\u306B\u3059\u308B\r\n\
    \    for (int i = r - 2; i >= l; --i) {\r\n      if (hld && depth[csr[i + 1].to]\
    \ == -1) swap(csr[i], csr[i + 1]);\r\n    }\r\n    int hld_sz = 0;\r\n    for\
    \ (int i = l; i < r; ++i) {\r\n      auto e = csr[i];\r\n      if (depth[e.to]\
    \ != -1) continue;\r\n      depth_weighted[e.to] = depth_weighted[v] + e.cost;\r\
    \n      VtoE[e.to] = e.id;\r\n      dfs_sz(e.to, v, hld);\r\n      sz[v] += sz[e.to];\r\
    \n      if (hld && chmax(hld_sz, sz[e.to]) && l < i) { swap(csr[l], csr[i]); }\r\
    \n    }\r\n  }\r\n\r\n  void dfs_hld(int v, int &times) {\r\n    LID[v] = times++;\r\
    \n    RID[v] += LID[v];\r\n    V[LID[v]] = v;\r\n    bool heavy = true;\r\n  \
    \  for (auto &&e: G[v]) {\r\n      if (depth[e.to] <= depth[v]) continue;\r\n\
    \      head[e.to] = (heavy ? head[v] : e.to);\r\n      heavy = false;\r\n    \
    \  dfs_hld(e.to, times);\r\n    }\r\n  }\r\n\r\n  vc<int> heavy_path_at(int v)\
    \ {\r\n    vc<int> P = {v};\r\n    while (1) {\r\n      int a = P.back();\r\n\
    \      for (auto &&e: G[a]) {\r\n        if (e.to != parent[a] && head[e.to] ==\
    \ v) {\r\n          P.eb(e.to);\r\n          break;\r\n        }\r\n      }\r\n\
    \      if (P.back() == a) break;\r\n    }\r\n    return P;\r\n  }\r\n\r\n  int\
    \ heavy_child(int v) {\r\n    int k = LID[v] + 1;\r\n    if (k == N) return -1;\r\
    \n    int w = V[k];\r\n    return (parent[w] == v ? w : -1);\r\n  }\r\n\r\n  int\
    \ e_to_v(int eid) {\r\n    auto e = G.edges[eid];\r\n    return (parent[e.frm]\
    \ == e.to ? e.frm : e.to);\r\n  }\r\n  int v_to_e(int v) { return VtoE[v]; }\r\
    \n\r\n  int ELID(int v) { return 2 * LID[v] - depth[v]; }\r\n  int ERID(int v)\
    \ { return 2 * RID[v] - depth[v] - 1; }\r\n\r\n  // \u76EE\u6A19\u5730\u70B9\u3078\
    \u9032\u3080\u500B\u6570\u304C k\r\n  int LA(int v, int k) {\r\n    assert(k <=\
    \ depth[v]);\r\n    while (1) {\r\n      int u = head[v];\r\n      if (LID[v]\
    \ - k >= LID[u]) return V[LID[v] - k];\r\n      k -= LID[v] - LID[u] + 1;\r\n\
    \      v = parent[u];\r\n    }\r\n  }\r\n  int la(int u, int v) { return LA(u,\
    \ v); }\r\n\r\n  int LCA(int u, int v) {\r\n    for (;; v = parent[head[v]]) {\r\
    \n      if (LID[u] > LID[v]) swap(u, v);\r\n      if (head[u] == head[v]) return\
    \ u;\r\n    }\r\n  }\r\n  // root \u3092\u6839\u3068\u3057\u305F\u5834\u5408\u306E\
    \ lca\r\n  int LCA_root(int u, int v, int root) {\r\n    return LCA(u, v) ^ LCA(u,\
    \ root) ^ LCA(v, root);\r\n  }\r\n  int lca(int u, int v) { return LCA(u, v);\
    \ }\r\n  int lca_root(int u, int v, int root) { return LCA_root(u, v, root); }\r\
    \n\r\n  int subtree_size(int v, int root = -1) {\r\n    if (root == -1) return\
    \ RID[v] - LID[v];\r\n    if (v == root) return N;\r\n    int x = jump(v, root,\
    \ 1);\r\n    if (in_subtree(v, x)) return RID[v] - LID[v];\r\n    return N - RID[x]\
    \ + LID[x];\r\n  }\r\n\r\n  int dist(int a, int b) {\r\n    int c = LCA(a, b);\r\
    \n    return depth[a] + depth[b] - 2 * depth[c];\r\n  }\r\n\r\n  WT dist_weighted(int\
    \ a, int b) {\r\n    int c = LCA(a, b);\r\n    return depth_weighted[a] + depth_weighted[b]\
    \ - WT(2) * depth_weighted[c];\r\n  }\r\n\r\n  // a is in b\r\n  bool in_subtree(int\
    \ a, int b) { return LID[b] <= LID[a] && LID[a] < RID[b]; }\r\n\r\n  int jump(int\
    \ a, int b, ll k) {\r\n    if (k == 1) {\r\n      if (a == b) return -1;\r\n \
    \     return (in_subtree(b, a) ? LA(b, depth[b] - depth[a] - 1) : parent[a]);\r\
    \n    }\r\n    int c = LCA(a, b);\r\n    int d_ac = depth[a] - depth[c];\r\n \
    \   int d_bc = depth[b] - depth[c];\r\n    if (k > d_ac + d_bc) return -1;\r\n\
    \    if (k <= d_ac) return LA(a, k);\r\n    return LA(b, d_ac + d_bc - k);\r\n\
    \  }\r\n\r\n  vc<int> collect_child(int v) {\r\n    vc<int> res;\r\n    for (auto\
    \ &&e: G[v])\r\n      if (e.to != parent[v]) res.eb(e.to);\r\n    return res;\r\
    \n  }\r\n\r\n  vc<int> collect_light(int v) {\r\n    vc<int> res;\r\n    bool\
    \ skip = true;\r\n    for (auto &&e: G[v])\r\n      if (e.to != parent[v]) {\r\
    \n        if (!skip) res.eb(e.to);\r\n        skip = false;\r\n      }\r\n   \
    \ return res;\r\n  }\r\n\r\n  vc<pair<int, int>> get_path_decomposition(int u,\
    \ int v, bool edge) {\r\n    // [\u59CB\u70B9, \u7D42\u70B9] \u306E\"\u9589\"\u533A\
    \u9593\u5217\u3002\r\n    vc<pair<int, int>> up, down;\r\n    while (1) {\r\n\
    \      if (head[u] == head[v]) break;\r\n      if (LID[u] < LID[v]) {\r\n    \
    \    down.eb(LID[head[v]], LID[v]);\r\n        v = parent[head[v]];\r\n      }\
    \ else {\r\n        up.eb(LID[u], LID[head[u]]);\r\n        u = parent[head[u]];\r\
    \n      }\r\n    }\r\n    if (LID[u] < LID[v]) down.eb(LID[u] + edge, LID[v]);\r\
    \n    elif (LID[v] + edge <= LID[u]) up.eb(LID[u], LID[v] + edge);\r\n    reverse(all(down));\r\
    \n    up.insert(up.end(), all(down));\r\n    return up;\r\n  }\r\n\r\n  vc<int>\
    \ restore_path(int u, int v) {\r\n    vc<int> P;\r\n    for (auto &&[a, b]: get_path_decomposition(u,\
    \ v, 0)) {\r\n      if (a <= b) {\r\n        FOR(i, a, b + 1) P.eb(V[i]);\r\n\
    \      } else {\r\n        FOR_R(i, b, a + 1) P.eb(V[i]);\r\n      }\r\n    }\r\
    \n    return P;\r\n  }\r\n};\r\n#line 2 \"graph/ds/static_toptree.hpp\"\n\n/*\n\
    tute \u3055\u3093\u306E\u5B9F\u88C5 https://yukicoder.me/submissions/838092 \u3092\
    \u53C2\u8003\u306B\u3057\u3066\u3044\u308B.\n\u3044\u308F\u3086\u308B toptree\
    \ \uFF08\u8FBA\u304B\u3089\u306F\u3058\u3081\u3066\u30DE\u30FC\u30B8\u904E\u7A0B\
    \u3092\u6728\u306B\u3059\u308B\uFF09\u3068\u306F\u5C11\u3057\u7570\u306A\u308B\
    \u306F\u305A.\n\u6728\u3092\u300Cheavy path \u4E0A\u306E\u8FBA\u3067\u5206\u5272\
    \u300D\u300C\u6839\u3092 virtual \u306B\u3059\u308B\u300D\n\u300Clight edges \u306E\
    \u5206\u5272\u300D\u300Clight edge \u3092\u6D88\u3059\u300D\u3067\u9802\u70B9\u306B\
    \u5206\u5272\u3057\u3066\u3044\u304F.\n\u9006\u306B\u305F\u3069\u308C\u3070\uFF0C\
    1 \u9802\u70B9\u304B\u3089\u306F\u3058\u3081\u3066\u6728\u5168\u4F53\u3092\u4F5C\
    \u308B\u9AD8\u3055 O(logN) \u306E\u6728\u306B\u306A\u308B.\n\u9AD8\u3055\u306B\
    \u3064\u3044\u3066\uFF1Ahttps://www.mathenachia.blog/mergetech-and-logn/\n\u30FB\
    lch == rch == -1\uFF1A\u9802\u70B9\n\u30FBrch == -1\uFF1A\n  \u30FBheavy \u306A\
    \u3089 light \u306E\u96C6\u7D04\u306B\u9802\u70B9\u3092\u4ED8\u52A0\u3057\u305F\
    \u3082\u306E\n  \u30FBlight \u306A\u3089 \u6839\u4ED8\u304D\u6728\u306B light\
    \ edge \u3092\u4ED8\u52A0\u3057\u305F\u3082\u306E\n\u30FB\u5B50\u304C 2 \u3064\
    \n  \u30FBheavy \u306A\u3089 heavy path \u3092\u8FBA\u3067\u7D50\u5408\u3057\u305F\
    \u3082\u306E\n  \u30FBlight \u306A\u3089 light edge \u305F\u3061\u306E\u30DE\u30FC\
    \u30B8\n*/\ntemplate <typename TREE>\nstruct Static_TopTree {\n  TREE &tree;\n\
    \n  vc<int> par, lch, rch, A, B;\n  vc<bool> heavy;\n\n  Static_TopTree(TREE &tree)\
    \ : tree(tree) {\n    int root = tree.V[0];\n    build(root);\n    // relabel\n\
    \    int n = len(par);\n    reverse(all(par)), reverse(all(lch)), reverse(all(rch)),\
    \ reverse(all(A)),\n        reverse(all(B)), reverse(all(heavy));\n    for (auto\
    \ &x: par) x = (x == -1 ? -1 : n - 1 - x);\n    for (auto &x: lch) x = (x == -1\
    \ ? -1 : n - 1 - x);\n    for (auto &x: rch) x = (x == -1 ? -1 : n - 1 - x);\n\
    \  }\n\n  // \u6728\u5168\u4F53\u3067\u306E\u96C6\u7D04\u5024\u3092\u5F97\u308B\
    \n  // from_vertex(v)\n  // add_vertex(x, v)\n  // add_edge(x, u, v)  : u \u304C\
    \u89AA\n  // merge_light(x, y)\n  // merge_heavy(x, y, a, b, c, d)  : [a,b] +\
    \ [c,d] = [a,d]\n  template <typename Data, typename F1, typename F2, typename\
    \ F3, typename F4,\n            typename F5>\n  Data tree_dp(F1 from_vertex, F2\
    \ add_vertex, F3 add_edge, F4 merge_light,\n               F5 merge_heavy) {\n\
    \    auto dfs = [&](auto &dfs, int k) -> Data {\n      if (lch[k] == -1 && rch[k]\
    \ == -1) { return from_vertex(A[k]); }\n      if (rch[k] == -1) {\n        Data\
    \ x = dfs(dfs, lch[k]);\n        if (heavy[k]) {\n          return add_vertex(x,\
    \ A[k]);\n        } else {\n          return add_edge(x, A[k], B[lch[k]]);\n \
    \       }\n      }\n      Data x = dfs(dfs, lch[k]);\n      Data y = dfs(dfs,\
    \ rch[k]);\n      if (heavy[k]) {\n        return merge_heavy(x, y, A[lch[k]],\
    \ B[lch[k]], A[rch[k]], B[rch[k]]);\n      }\n      return merge_light(x, y);\n\
    \    };\n    return dfs(dfs, 0);\n  }\n\nprivate:\n  int add_node(int l, int r,\
    \ int a, int b, bool h) {\n    int ret = len(par);\n    par.eb(-1), lch.eb(l),\
    \ rch.eb(r), A.eb(a), B.eb(b), heavy.eb(h);\n    if (l != -1) par[l] = ret;\n\
    \    if (r != -1) par[r] = ret;\n    return ret;\n  }\n\n  int build(int v) {\n\
    \    // v \u306F heavy path \u306E\u6839\u306A\u306E\u3067 v \u3092\u6839\u3068\
    \u3059\u308B\u90E8\u5206\u6728\u306B\u5BFE\u5FDC\u3059\u308B\u30CE\u30FC\u30C9\
    \u3092\u4F5C\u308B\n    assert(tree.head[v] == v);\n    auto path = tree.heavy_path_at(v);\n\
    \    reverse(all(path));\n\n    auto dfs = [&](auto &dfs, int l, int r) -> int\
    \ {\n      // path[l:r)\n      if (l + 1 < r) {\n        int m = (l + r) / 2;\n\
    \        int x = dfs(dfs, l, m);\n        int y = dfs(dfs, m, r);\n        return\
    \ add_node(x, y, path[l], path[r - 1], true);\n      }\n      assert(r == l +\
    \ 1);\n      int me = path[l];\n      // sz, idx\n      pqg<pair<int, int>> que;\n\
    \      for (auto &to: tree.collect_light(me)) {\n        int x = build(to);\n\
    \        int y = add_node(x, -1, me, me, false);\n        que.emplace(tree.subtree_size(to),\
    \ y);\n      }\n      if (que.empty()) { return add_node(-1, -1, me, me, true);\
    \ }\n      while (len(que) >= 2) {\n        auto [s1, x] = POP(que);\n       \
    \ auto [s2, y] = POP(que);\n        int z = add_node(x, y, me, me, false);\n \
    \       que.emplace(s1 + s2, z);\n      }\n      auto [s, x] = POP(que);\n   \
    \   return add_node(x, -1, me, me, true);\n    };\n    return dfs(dfs, 0, len(path));\n\
    \  }\n};\n#line 3 \"graph/shortest_path/bfs01.hpp\"\n\ntemplate <typename T, typename\
    \ GT>\npair<vc<T>, vc<int>> bfs01(GT& G, int v) {\n  assert(G.is_prepared());\n\
    \  int N = G.N;\n  vc<T> dist(N, infty<T>);\n  vc<int> par(N, -1);\n  deque<int>\
    \ que;\n\n  dist[v] = 0;\n  que.push_front(v);\n  while (!que.empty()) {\n   \
    \ auto v = que.front();\n    que.pop_front();\n    for (auto&& e: G[v]) {\n  \
    \    if (dist[e.to] == infty<T> || dist[e.to] > dist[e.frm] + e.cost) {\n    \
    \    dist[e.to] = dist[e.frm] + e.cost;\n        par[e.to] = e.frm;\n        if\
    \ (e.cost == 0)\n          que.push_front(e.to);\n        else\n          que.push_back(e.to);\n\
    \      }\n    }\n  }\n  return {dist, par};\n}\n\n// \u591A\u70B9\u30B9\u30BF\u30FC\
    \u30C8\u3002[dist, par, root]\ntemplate <typename T, typename GT>\ntuple<vc<T>,\
    \ vc<int>, vc<int>> bfs01(GT& G, vc<int> vs) {\n  assert(G.is_prepared());\n \
    \ int N = G.N;\n  vc<T> dist(N, infty<T>);\n  vc<int> par(N, -1);\n  vc<int> root(N,\
    \ -1);\n  deque<int> que;\n\n  for (auto&& v: vs) {\n    dist[v] = 0;\n    root[v]\
    \ = v;\n    que.push_front(v);\n  }\n\n  while (!que.empty()) {\n    auto v =\
    \ que.front();\n    que.pop_front();\n    for (auto&& e: G[v]) {\n      if (dist[e.to]\
    \ == infty<T> || dist[e.to] > dist[e.frm] + e.cost) {\n        dist[e.to] = dist[e.frm]\
    \ + e.cost;\n        root[e.to] = root[e.frm];\n        par[e.to] = e.frm;\n \
    \       if (e.cost == 0)\n          que.push_front(e.to);\n        else\n    \
    \      que.push_back(e.to);\n      }\n    }\n  }\n  return {dist, par, root};\n\
    }\n#line 2 \"ds/unionfind/unionfind.hpp\"\n\nstruct UnionFind {\n  int n, n_comp;\n\
    \  vc<int> dat; // par or (-size)\n  UnionFind(int n = 0) { build(n); }\n\n  void\
    \ build(int m) {\n    n = m, n_comp = m;\n    dat.assign(n, -1);\n  }\n\n  void\
    \ reset() { build(n); }\n\n  int operator[](int x) {\n    while (dat[x] >= 0)\
    \ {\n      int pp = dat[dat[x]];\n      if (pp < 0) { return dat[x]; }\n     \
    \ x = dat[x] = pp;\n    }\n    return x;\n  }\n\n  ll size(int x) {\n    x = (*this)[x];\n\
    \    return -dat[x];\n  }\n\n  bool merge(int x, int y) {\n    x = (*this)[x],\
    \ y = (*this)[y];\n    if (x == y) return false;\n    if (-dat[x] < -dat[y]) swap(x,\
    \ y);\n    dat[x] += dat[y], dat[y] = x, n_comp--;\n    return true;\n  }\n};\n\
    #line 4 \"graph/characteristic_polynomial_of_tree_adjacency_matrix.hpp\"\n\n//\
    \ det(I-xA) \u306E\u8A08\u7B97 (\u56FA\u6709\u591A\u9805\u5F0F\u306E reverse \u306B\
    \u306A\u3063\u3066\u3044\u308B)\n// weight(i,j)\uFF1AA[i][j]\n// \u5076\u6570\u6B21\
    \u3060\u3051\u3057\u304B\u51FA\u3066\u3053\u306A\u3044\u306E\u3067 loop \u3042\
    \u308A\u3088\u308A\u9AD8\u901F\ntemplate <typename mint, typename F>\nvc<mint>\
    \ characteristic_poly_of_tree_adjacency_matrix_not_allow_loop(\n    Graph<int,\
    \ 0>& G, F weight) {\n  // int N = G.N;\n  // vv(mint, A, N, N);\n  // vv(mint,\
    \ B, N, N);\n  // FOR(i, N) A[i][i] = 1;\n  // FOR(i, N) {\n  //   for (auto&\
    \ e: G[i]) { B[i][e.to] = -weight(i, e.to); }\n  // }\n  // return det_A_plus_xB(A,\
    \ B);\n  using poly = vc<mint>;\n  Tree<Graph<int, 0>> tree(G);\n  Static_TopTree<decltype(tree)>\
    \ STT(tree);\n\n  using Data = array<array<poly, 2>, 2>;\n  auto add = [&](poly&\
    \ f, poly& g, int s, mint wt = 1) -> void {\n    if (g.empty()) return;\n    if\
    \ (len(f) < len(g) + s) f.resize(len(g) + s);\n    FOR(i, len(g)) f[s + i] +=\
    \ g[i] * wt;\n  };\n  auto from_vertex = [&](int v) -> Data {\n    Data X;\n \
    \   X[0][0] = poly{mint(1)};\n    return X;\n  };\n  auto add_vertex = [&](Data&\
    \ X, int v) -> Data { return X; };\n  auto add_edge = [&](Data& X, int u, int\
    \ v) -> Data {\n    mint wt = -weight(u, v) * weight(v, u);\n    Data Y;\n   \
    \ FOR(a, 2) {\n      add(Y[0][0], X[a][0], 0);\n      add(Y[1][1], X[a][0], 1,\
    \ wt);\n      add(Y[0][0], X[a][1], 0);\n    }\n    return Y;\n  };\n  auto merge_light\
    \ = [&](Data& X, Data& Y) -> Data {\n    poly &X0 = X[0][0], &X1 = X[1][1];\n\
    \    poly &Y0 = Y[0][0], &Y1 = Y[1][1];\n    poly A = convolution(X0, Y0);\n \
    \   poly B = convolution(X0, Y1);\n    poly C = convolution(X1, Y0);\n    Data\
    \ Z;\n    add(Z[0][0], A, 0), add(Z[1][1], B, 0), add(Z[1][1], C, 0);\n    return\
    \ Z;\n  };\n  auto merge_heavy\n      = [&](Data& X, Data& Y, int va, int vb,\
    \ int vc, int vd) -> Data {\n    Data Z;\n    mint wt = -weight(vb, vc) * weight(vc,\
    \ vb);\n    FOR(a, 2) FOR(d, 2) {\n      poly f0 = X[a][0], &f1 = X[a][1];\n \
    \     poly g0 = Y[0][d], &g1 = Y[1][d];\n      // \u8FBA\u3092\u4F7F\u3046\n \
    \     poly f = convolution(f0, g0);\n      int x = (va != vb ? a : 1);\n     \
    \ int y = (vc != vd ? d : 1);\n      add(Z[x][y], f, 1, wt);\n      // \u8FBA\u3092\
    \u4F7F\u308F\u306A\u3044\n      add(f0, f1, 0), add(g0, g1, 0);\n      f = convolution(f0,\
    \ g0);\n      add(Z[a][d], f, 0);\n    }\n    return Z;\n  };\n\n  Data X = STT.tree_dp<Data>(from_vertex,\
    \ add_vertex, add_edge, merge_light,\n                             merge_heavy);\n\
    \  vc<mint> ANS(G.N + 1);\n  FOR(a, 2) FOR(b, 2) {\n    FOR(i, len(X[a][b])) {\
    \ ANS[2 * i] += X[a][b][i]; }\n  }\n  return ANS;\n}\n\ntemplate <typename mint,\
    \ typename F>\nvc<mint> characteristic_poly_of_tree_adjacency_matrix_allow_loop(\n\
    \    Graph<int, 0>& G, F weight) {\n  // \u70B9\u3068\u30DE\u30C3\u30C1\u30F3\u30B0\
    \u306B\u5206\u89E3\n  // \u30DE\u30C3\u30C1\u30F3\u30B0\uFF1A-w[i][j]w[j][i]x^2\n\
    \  // \u70B9\uFF1A1-w[i][i]x\n  using poly = vc<mint>;\n  Tree<Graph<int, 0>>\
    \ tree(G);\n  Static_TopTree<decltype(tree)> STT(tree);\n\n  using Data = array<array<poly,\
    \ 2>, 2>;\n  auto add = [&](poly& f, poly& g, int s, mint wt = 1) -> void {\n\
    \    if (g.empty()) return;\n    if (len(f) < len(g) + s) f.resize(len(g) + s);\n\
    \    FOR(i, len(g)) f[s + i] += g[i] * wt;\n  };\n  auto from_vertex = [&](int\
    \ v) -> Data {\n    mint wt = weight(v, v);\n    Data X;\n    X[0][0] = poly{mint(1)};\n\
    \    X[1][1] = poly{mint(1), -wt};\n    return X;\n  };\n  auto add_vertex = [&](Data&\
    \ X, int v) -> Data {\n    mint wt = weight(v, v);\n    // 1-wtx\n    add(X[1][1],\
    \ X[0][0], 0, mint(1));\n    add(X[1][1], X[0][0], 1, -wt);\n    return X;\n \
    \ };\n  auto add_edge = [&](Data& X, int u, int v) -> Data {\n    if (X[0][1].empty())\
    \ { X[1][0] = X[0][0]; }\n    mint wt = weight(u, v) * weight(v, u);\n    Data\
    \ Y;\n    add(Y[1][1], X[1][0], 2, -wt);\n    add(Y[0][0], X[1][1], 0);\n    return\
    \ Y;\n  };\n  auto merge_light = [&](Data& X, Data& Y) -> Data {\n    poly &X0\
    \ = X[0][0], &X1 = X[1][1];\n    poly &Y0 = Y[0][0], &Y1 = Y[1][1];\n    poly\
    \ A = convolution(X0, Y0);\n    poly B = convolution(X0, Y1);\n    poly C = convolution(X1,\
    \ Y0);\n    Data Z;\n    add(Z[0][0], A, 0), add(Z[1][1], B, 0), add(Z[1][1],\
    \ C, 0);\n    return Z;\n  };\n  auto merge_heavy\n      = [&](Data& X, Data&\
    \ Y, int va, int vb, int vc, int vd) -> Data {\n    Data Z;\n    mint wt = weight(vb,\
    \ vc) * weight(vc, vb);\n    FOR(a, 2) FOR(b, 2) FOR(c, 2) FOR(d, 2) {\n     \
    \ bool non_use = 1;\n      bool use = (b == 0) && (c == 0);\n      if (va != vb\
    \ && b == 0) non_use = 0;\n      if (vc != vd && c == 0) non_use = 0;\n      if\
    \ (!non_use && !use) continue;\n      poly f = convolution(X[a][b], Y[c][d]);\n\
    \      if (non_use) add(Z[a][d], f, 0);\n      if (use) {\n        int x = (va\
    \ != vb ? a : 1);\n        int y = (vc != vd ? d : 1);\n        add(Z[x][y], f,\
    \ 2, -wt);\n      }\n    }\n    return Z;\n  };\n\n  Data X = STT.tree_dp<Data>(from_vertex,\
    \ add_vertex, add_edge, merge_light,\n                             merge_heavy);\n\
    \  poly& ANS = X[1][1];\n  return ANS;\n}\n\n// det(I-xA) \u306E\u8A08\u7B97 (\u56FA\
    \u6709\u591A\u9805\u5F0F\u306E reverse \u306B\u306A\u3063\u3066\u3044\u308B)\n\
    // weight(i,j)\uFF1AA[i][j]\ntemplate <bool ALLOW_LOOP, typename mint, typename\
    \ F>\nvc<mint> characteristic_poly_of_tree_adjacency_matrix(Graph<int, 0>& G,\n\
    \                                                      F weight) {\n  if constexpr\
    \ (ALLOW_LOOP) {\n    return characteristic_poly_of_tree_adjacency_matrix_allow_loop<mint>(\n\
    \        G, weight);\n  } else {\n    return characteristic_poly_of_tree_adjacency_matrix_not_allow_loop<mint>(\n\
    \        G, weight);\n  }\n}\n"
  code: "#include \"graph/ds/static_toptree.hpp\"\n#include \"graph/shortest_path/bfs01.hpp\"\
    \n#include \"ds/unionfind/unionfind.hpp\"\n\n// det(I-xA) \u306E\u8A08\u7B97 (\u56FA\
    \u6709\u591A\u9805\u5F0F\u306E reverse \u306B\u306A\u3063\u3066\u3044\u308B)\n\
    // weight(i,j)\uFF1AA[i][j]\n// \u5076\u6570\u6B21\u3060\u3051\u3057\u304B\u51FA\
    \u3066\u3053\u306A\u3044\u306E\u3067 loop \u3042\u308A\u3088\u308A\u9AD8\u901F\
    \ntemplate <typename mint, typename F>\nvc<mint> characteristic_poly_of_tree_adjacency_matrix_not_allow_loop(\n\
    \    Graph<int, 0>& G, F weight) {\n  // int N = G.N;\n  // vv(mint, A, N, N);\n\
    \  // vv(mint, B, N, N);\n  // FOR(i, N) A[i][i] = 1;\n  // FOR(i, N) {\n  //\
    \   for (auto& e: G[i]) { B[i][e.to] = -weight(i, e.to); }\n  // }\n  // return\
    \ det_A_plus_xB(A, B);\n  using poly = vc<mint>;\n  Tree<Graph<int, 0>> tree(G);\n\
    \  Static_TopTree<decltype(tree)> STT(tree);\n\n  using Data = array<array<poly,\
    \ 2>, 2>;\n  auto add = [&](poly& f, poly& g, int s, mint wt = 1) -> void {\n\
    \    if (g.empty()) return;\n    if (len(f) < len(g) + s) f.resize(len(g) + s);\n\
    \    FOR(i, len(g)) f[s + i] += g[i] * wt;\n  };\n  auto from_vertex = [&](int\
    \ v) -> Data {\n    Data X;\n    X[0][0] = poly{mint(1)};\n    return X;\n  };\n\
    \  auto add_vertex = [&](Data& X, int v) -> Data { return X; };\n  auto add_edge\
    \ = [&](Data& X, int u, int v) -> Data {\n    mint wt = -weight(u, v) * weight(v,\
    \ u);\n    Data Y;\n    FOR(a, 2) {\n      add(Y[0][0], X[a][0], 0);\n      add(Y[1][1],\
    \ X[a][0], 1, wt);\n      add(Y[0][0], X[a][1], 0);\n    }\n    return Y;\n  };\n\
    \  auto merge_light = [&](Data& X, Data& Y) -> Data {\n    poly &X0 = X[0][0],\
    \ &X1 = X[1][1];\n    poly &Y0 = Y[0][0], &Y1 = Y[1][1];\n    poly A = convolution(X0,\
    \ Y0);\n    poly B = convolution(X0, Y1);\n    poly C = convolution(X1, Y0);\n\
    \    Data Z;\n    add(Z[0][0], A, 0), add(Z[1][1], B, 0), add(Z[1][1], C, 0);\n\
    \    return Z;\n  };\n  auto merge_heavy\n      = [&](Data& X, Data& Y, int va,\
    \ int vb, int vc, int vd) -> Data {\n    Data Z;\n    mint wt = -weight(vb, vc)\
    \ * weight(vc, vb);\n    FOR(a, 2) FOR(d, 2) {\n      poly f0 = X[a][0], &f1 =\
    \ X[a][1];\n      poly g0 = Y[0][d], &g1 = Y[1][d];\n      // \u8FBA\u3092\u4F7F\
    \u3046\n      poly f = convolution(f0, g0);\n      int x = (va != vb ? a : 1);\n\
    \      int y = (vc != vd ? d : 1);\n      add(Z[x][y], f, 1, wt);\n      // \u8FBA\
    \u3092\u4F7F\u308F\u306A\u3044\n      add(f0, f1, 0), add(g0, g1, 0);\n      f\
    \ = convolution(f0, g0);\n      add(Z[a][d], f, 0);\n    }\n    return Z;\n  };\n\
    \n  Data X = STT.tree_dp<Data>(from_vertex, add_vertex, add_edge, merge_light,\n\
    \                             merge_heavy);\n  vc<mint> ANS(G.N + 1);\n  FOR(a,\
    \ 2) FOR(b, 2) {\n    FOR(i, len(X[a][b])) { ANS[2 * i] += X[a][b][i]; }\n  }\n\
    \  return ANS;\n}\n\ntemplate <typename mint, typename F>\nvc<mint> characteristic_poly_of_tree_adjacency_matrix_allow_loop(\n\
    \    Graph<int, 0>& G, F weight) {\n  // \u70B9\u3068\u30DE\u30C3\u30C1\u30F3\u30B0\
    \u306B\u5206\u89E3\n  // \u30DE\u30C3\u30C1\u30F3\u30B0\uFF1A-w[i][j]w[j][i]x^2\n\
    \  // \u70B9\uFF1A1-w[i][i]x\n  using poly = vc<mint>;\n  Tree<Graph<int, 0>>\
    \ tree(G);\n  Static_TopTree<decltype(tree)> STT(tree);\n\n  using Data = array<array<poly,\
    \ 2>, 2>;\n  auto add = [&](poly& f, poly& g, int s, mint wt = 1) -> void {\n\
    \    if (g.empty()) return;\n    if (len(f) < len(g) + s) f.resize(len(g) + s);\n\
    \    FOR(i, len(g)) f[s + i] += g[i] * wt;\n  };\n  auto from_vertex = [&](int\
    \ v) -> Data {\n    mint wt = weight(v, v);\n    Data X;\n    X[0][0] = poly{mint(1)};\n\
    \    X[1][1] = poly{mint(1), -wt};\n    return X;\n  };\n  auto add_vertex = [&](Data&\
    \ X, int v) -> Data {\n    mint wt = weight(v, v);\n    // 1-wtx\n    add(X[1][1],\
    \ X[0][0], 0, mint(1));\n    add(X[1][1], X[0][0], 1, -wt);\n    return X;\n \
    \ };\n  auto add_edge = [&](Data& X, int u, int v) -> Data {\n    if (X[0][1].empty())\
    \ { X[1][0] = X[0][0]; }\n    mint wt = weight(u, v) * weight(v, u);\n    Data\
    \ Y;\n    add(Y[1][1], X[1][0], 2, -wt);\n    add(Y[0][0], X[1][1], 0);\n    return\
    \ Y;\n  };\n  auto merge_light = [&](Data& X, Data& Y) -> Data {\n    poly &X0\
    \ = X[0][0], &X1 = X[1][1];\n    poly &Y0 = Y[0][0], &Y1 = Y[1][1];\n    poly\
    \ A = convolution(X0, Y0);\n    poly B = convolution(X0, Y1);\n    poly C = convolution(X1,\
    \ Y0);\n    Data Z;\n    add(Z[0][0], A, 0), add(Z[1][1], B, 0), add(Z[1][1],\
    \ C, 0);\n    return Z;\n  };\n  auto merge_heavy\n      = [&](Data& X, Data&\
    \ Y, int va, int vb, int vc, int vd) -> Data {\n    Data Z;\n    mint wt = weight(vb,\
    \ vc) * weight(vc, vb);\n    FOR(a, 2) FOR(b, 2) FOR(c, 2) FOR(d, 2) {\n     \
    \ bool non_use = 1;\n      bool use = (b == 0) && (c == 0);\n      if (va != vb\
    \ && b == 0) non_use = 0;\n      if (vc != vd && c == 0) non_use = 0;\n      if\
    \ (!non_use && !use) continue;\n      poly f = convolution(X[a][b], Y[c][d]);\n\
    \      if (non_use) add(Z[a][d], f, 0);\n      if (use) {\n        int x = (va\
    \ != vb ? a : 1);\n        int y = (vc != vd ? d : 1);\n        add(Z[x][y], f,\
    \ 2, -wt);\n      }\n    }\n    return Z;\n  };\n\n  Data X = STT.tree_dp<Data>(from_vertex,\
    \ add_vertex, add_edge, merge_light,\n                             merge_heavy);\n\
    \  poly& ANS = X[1][1];\n  return ANS;\n}\n\n// det(I-xA) \u306E\u8A08\u7B97 (\u56FA\
    \u6709\u591A\u9805\u5F0F\u306E reverse \u306B\u306A\u3063\u3066\u3044\u308B)\n\
    // weight(i,j)\uFF1AA[i][j]\ntemplate <bool ALLOW_LOOP, typename mint, typename\
    \ F>\nvc<mint> characteristic_poly_of_tree_adjacency_matrix(Graph<int, 0>& G,\n\
    \                                                      F weight) {\n  if constexpr\
    \ (ALLOW_LOOP) {\n    return characteristic_poly_of_tree_adjacency_matrix_allow_loop<mint>(\n\
    \        G, weight);\n  } else {\n    return characteristic_poly_of_tree_adjacency_matrix_not_allow_loop<mint>(\n\
    \        G, weight);\n  }\n}\n"
  dependsOn:
  - graph/ds/static_toptree.hpp
  - graph/tree.hpp
  - graph/base.hpp
  - graph/shortest_path/bfs01.hpp
  - ds/unionfind/unionfind.hpp
  isVerificationFile: false
  path: graph/characteristic_polynomial_of_tree_adjacency_matrix.hpp
  requiredBy:
  - graph/tree_walk_generating_function.hpp
  timestamp: '2023-12-15 23:42:47+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/mytest/tree_walk_gf.test.cpp
  - test/yukicoder/2587_2.test.cpp
  - test/yukicoder/2587.test.cpp
documentation_of: graph/characteristic_polynomial_of_tree_adjacency_matrix.hpp
layout: document
redirect_from:
- /library/graph/characteristic_polynomial_of_tree_adjacency_matrix.hpp
- /library/graph/characteristic_polynomial_of_tree_adjacency_matrix.hpp.html
title: graph/characteristic_polynomial_of_tree_adjacency_matrix.hpp
---
