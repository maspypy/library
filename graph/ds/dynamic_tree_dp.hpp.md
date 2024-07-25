---
data:
  _extendedDependsOn:
  - icon: ':question:'
    path: graph/base.hpp
    title: graph/base.hpp
  - icon: ':heavy_check_mark:'
    path: graph/ds/static_toptree.hpp
    title: graph/ds/static_toptree.hpp
  - icon: ':question:'
    path: graph/tree.hpp
    title: graph/tree.hpp
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test_atcoder/abc351g.test.cpp
    title: test_atcoder/abc351g.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links:
    - https://codeforces.com/contest/1172/problem/E
    - https://codeforces.com/contest/1942/problem/H
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
    \u306B\u3059\u308B\n  // {G, es}\n  // sum(deg(v)) \u306E\u8A08\u7B97\u91CF\u306B\
    \u306A\u3063\u3066\u3044\u3066\u3001\n  // \u65B0\u3057\u3044\u30B0\u30E9\u30D5\
    \u306E n+m \u3088\u308A\u5927\u304D\u3044\u53EF\u80FD\u6027\u304C\u3042\u308B\u306E\
    \u3067\u6CE8\u610F\n  Graph<T, directed> rearrange(vc<int> V, bool keep_eid =\
    \ 0) {\n    if (len(new_idx) != N) new_idx.assign(N, -1);\n    int n = len(V);\n\
    \    FOR(i, n) new_idx[V[i]] = i;\n    Graph<T, directed> G(n);\n    vc<int> history;\n\
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
    \ { vc_indeg[e.to]++, vc_outdeg[e.frm]++; }\n  }\n};\n#line 4 \"graph/tree.hpp\"\
    \n\r\n// HLD euler tour \u3092\u3068\u3063\u3066\u3044\u308D\u3044\u308D\u3002\
    \r\ntemplate <typename GT>\r\nstruct Tree {\r\n  using Graph_type = GT;\r\n  GT\
    \ &G;\r\n  using WT = typename GT::cost_type;\r\n  int N;\r\n  vector<int> LID,\
    \ RID, head, V, parent, VtoE;\r\n  vc<int> depth;\r\n  vc<WT> depth_weighted;\r\
    \n\r\n  Tree(GT &G, int r = 0, bool hld = 1) : G(G) { build(r, hld); }\r\n\r\n\
    \  void build(int r = 0, bool hld = 1) {\r\n    if (r == -1) return; // build\
    \ \u3092\u9045\u5EF6\u3057\u305F\u3044\u3068\u304D\r\n    N = G.N;\r\n    LID.assign(N,\
    \ -1), RID.assign(N, -1), head.assign(N, r);\r\n    V.assign(N, -1), parent.assign(N,\
    \ -1), VtoE.assign(N, -1);\r\n    depth.assign(N, -1), depth_weighted.assign(N,\
    \ 0);\r\n    assert(G.is_prepared());\r\n    int t1 = 0;\r\n    dfs_sz(r, -1,\
    \ hld);\r\n    dfs_hld(r, t1);\r\n  }\r\n\r\n  void dfs_sz(int v, int p, bool\
    \ hld) {\r\n    auto &sz = RID;\r\n    parent[v] = p;\r\n    depth[v] = (p ==\
    \ -1 ? 0 : depth[p] + 1);\r\n    sz[v] = 1;\r\n    int l = G.indptr[v], r = G.indptr[v\
    \ + 1];\r\n    auto &csr = G.csr_edges;\r\n    // \u4F7F\u3046\u8FBA\u304C\u3042\
    \u308C\u3070\u5148\u982D\u306B\u3059\u308B\r\n    for (int i = r - 2; i >= l;\
    \ --i) {\r\n      if (hld && depth[csr[i + 1].to] == -1) swap(csr[i], csr[i +\
    \ 1]);\r\n    }\r\n    int hld_sz = 0;\r\n    for (int i = l; i < r; ++i) {\r\n\
    \      auto e = csr[i];\r\n      if (depth[e.to] != -1) continue;\r\n      depth_weighted[e.to]\
    \ = depth_weighted[v] + e.cost;\r\n      VtoE[e.to] = e.id;\r\n      dfs_sz(e.to,\
    \ v, hld);\r\n      sz[v] += sz[e.to];\r\n      if (hld && chmax(hld_sz, sz[e.to])\
    \ && l < i) { swap(csr[l], csr[i]); }\r\n    }\r\n  }\r\n\r\n  void dfs_hld(int\
    \ v, int &times) {\r\n    LID[v] = times++;\r\n    RID[v] += LID[v];\r\n    V[LID[v]]\
    \ = v;\r\n    bool heavy = true;\r\n    for (auto &&e: G[v]) {\r\n      if (depth[e.to]\
    \ <= depth[v]) continue;\r\n      head[e.to] = (heavy ? head[v] : e.to);\r\n \
    \     heavy = false;\r\n      dfs_hld(e.to, times);\r\n    }\r\n  }\r\n\r\n  vc<int>\
    \ heavy_path_at(int v) {\r\n    vc<int> P = {v};\r\n    while (1) {\r\n      int\
    \ a = P.back();\r\n      for (auto &&e: G[a]) {\r\n        if (e.to != parent[a]\
    \ && head[e.to] == v) {\r\n          P.eb(e.to);\r\n          break;\r\n     \
    \   }\r\n      }\r\n      if (P.back() == a) break;\r\n    }\r\n    return P;\r\
    \n  }\r\n\r\n  int heavy_child(int v) {\r\n    int k = LID[v] + 1;\r\n    if (k\
    \ == N) return -1;\r\n    int w = V[k];\r\n    return (parent[w] == v ? w : -1);\r\
    \n  }\r\n\r\n  int e_to_v(int eid) {\r\n    auto e = G.edges[eid];\r\n    return\
    \ (parent[e.frm] == e.to ? e.frm : e.to);\r\n  }\r\n  int v_to_e(int v) { return\
    \ VtoE[v]; }\r\n  int get_eid(int u, int v) {\r\n    if (parent[u] != v) swap(u,\
    \ v);\r\n    assert(parent[u] == v);\r\n    return VtoE[u];\r\n  }\r\n\r\n  int\
    \ ELID(int v) { return 2 * LID[v] - depth[v]; }\r\n  int ERID(int v) { return\
    \ 2 * RID[v] - depth[v] - 1; }\r\n\r\n  // \u76EE\u6A19\u5730\u70B9\u3078\u9032\
    \u3080\u500B\u6570\u304C k\r\n  int LA(int v, int k) {\r\n    assert(k <= depth[v]);\r\
    \n    while (1) {\r\n      int u = head[v];\r\n      if (LID[v] - k >= LID[u])\
    \ return V[LID[v] - k];\r\n      k -= LID[v] - LID[u] + 1;\r\n      v = parent[u];\r\
    \n    }\r\n  }\r\n  int la(int u, int v) { return LA(u, v); }\r\n\r\n  int LCA(int\
    \ u, int v) {\r\n    for (;; v = parent[head[v]]) {\r\n      if (LID[u] > LID[v])\
    \ swap(u, v);\r\n      if (head[u] == head[v]) return u;\r\n    }\r\n  }\r\n\r\
    \n  int meet(int a, int b, int c) { return LCA(a, b) ^ LCA(a, c) ^ LCA(b, c);\
    \ }\r\n  int lca(int u, int v) { return LCA(u, v); }\r\n\r\n  int subtree_size(int\
    \ v, int root = -1) {\r\n    if (root == -1) return RID[v] - LID[v];\r\n    if\
    \ (v == root) return N;\r\n    int x = jump(v, root, 1);\r\n    if (in_subtree(v,\
    \ x)) return RID[v] - LID[v];\r\n    return N - RID[x] + LID[x];\r\n  }\r\n\r\n\
    \  int dist(int a, int b) {\r\n    int c = LCA(a, b);\r\n    return depth[a] +\
    \ depth[b] - 2 * depth[c];\r\n  }\r\n\r\n  WT dist_weighted(int a, int b) {\r\n\
    \    int c = LCA(a, b);\r\n    return depth_weighted[a] + depth_weighted[b] -\
    \ WT(2) * depth_weighted[c];\r\n  }\r\n\r\n  // a is in b\r\n  bool in_subtree(int\
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
    \n    return P;\r\n  }\r\n\r\n  // path [a,b] \u3068 [c,d] \u306E\u4EA4\u308F\u308A\
    . \u7A7A\u306A\u3089\u3070 {-1,-1}.\r\n  // https://codeforces.com/problemset/problem/500/G\r\
    \n  pair<int, int> path_intersection(int a, int b, int c, int d) {\r\n    int\
    \ ab = lca(a, b), ac = lca(a, c), ad = lca(a, d);\r\n    int bc = lca(b, c), bd\
    \ = lca(b, d), cd = lca(c, d);\r\n    int x = ab ^ ac ^ bc, y = ab ^ ad ^ bd;\
    \ // meet(a,b,c), meet(a,b,d)\r\n    if (x != y) return {x, y};\r\n    int z =\
    \ ac ^ ad ^ cd;\r\n    if (x != z) x = -1;\r\n    return {x, x};\r\n  }\r\n};\r\
    \n#line 2 \"graph/ds/static_toptree.hpp\"\n\n/*\n\u53C2\u8003 joitour tatyam\n\
    \u30AF\u30E9\u30B9\u30BF\u3068\u306F\u6839\u304C\u6B20\u3051\u305F\u72B6\u614B\
    \nN \u500B\u306E (\u9802+\u8FBA) \u3092\u30DE\u30FC\u30B8\u3057\u3066\u3044\u3063\
    \u3066\uFF0C\u6728\u5168\u4F53\uFF0B\u6839\u304B\u3089\u89AA\u3078\u306E\u8FBA\
    \u3068\u3059\u308B\uFF0E\nsingle(v) : v \u3068\u305D\u306E\u89AA\u8FBA\u3092\u5408\
    \u308F\u305B\u305F\u30AF\u30E9\u30B9\u30BF\nrake(x, y, u, v) uv(top down) \u304C\
    \ boundary \u306B\u306A\u308B\u3088\u3046\u306B rake (maybe v=-1)\ncompress(x,y,a,b,c)\
    \  (top-down) \u9806\u306B (a,b] + (b,c]\n*/\ntemplate <typename TREE>\nstruct\
    \ Static_TopTree {\n  int N;\n  TREE &tree;\n  vc<int> par, lch, rch, A, B; //\
    \ A, B boundary (top-down)\n  vc<bool> is_compress;\n\n  Static_TopTree(TREE &tree)\
    \ : tree(tree) { build(); }\n\n  void build() {\n    N = tree.N;\n    par.assign(N,\
    \ -1), lch.assign(N, -1), rch.assign(N, -1), A.assign(N, -1),\n        B.assign(N,\
    \ -1), is_compress.assign(N, 0);\n    FOR(v, N) { A[v] = tree.parent[v], B[v]\
    \ = v; }\n    build_dfs(tree.V[0]);\n    assert(len(par) == 2 * N - 1);\n  }\n\
    \n  // \u6728\u5168\u4F53\u3067\u306E\u96C6\u7D04\u5024\u3092\u5F97\u308B\n  //\
    \ single(v) : v \u3068\u305D\u306E\u89AA\u8FBA\u3092\u5408\u308F\u305B\u305F\u30AF\
    \u30E9\u30B9\u30BF\n  // rake(x, y, u, v) uv(top down) \u304C boundary \u306B\u306A\
    \u308B\u3088\u3046\u306B rake (maybe v=-1)\n  // compress(x,y,a,b,c)  (top-down)\
    \ \u9806\u306B (a,b] + (b,c]\n  template <typename Data, typename F1, typename\
    \ F2, typename F3>\n  Data tree_dp(F1 single, F2 rake, F3 compress) {\n    auto\
    \ dfs = [&](auto &dfs, int k) -> Data {\n      if (0 <= k && k < N) return single(k);\n\
    \      Data x = dfs(dfs, lch[k]), y = dfs(dfs, rch[k]);\n      if (is_compress[k])\
    \ {\n        assert(B[lch[k]] == A[rch[k]]);\n        return compress(x, y, A[lch[k]],\
    \ B[lch[k]], B[rch[k]]);\n      }\n      return rake(x, y, A[k], B[k]);\n    };\n\
    \    return dfs(dfs, 2 * N - 2);\n  }\n\nprivate:\n  int new_node(int l, int r,\
    \ int a, int b, bool c) {\n    int v = len(par);\n    par.eb(-1), lch.eb(l), rch.eb(r),\
    \ A.eb(a), B.eb(b), is_compress.eb(c);\n    par[l] = par[r] = v;\n    return v;\n\
    \  }\n  int build_dfs(int v) {\n    assert(tree.head[v] == v);\n    auto path\
    \ = tree.heavy_path_at(v);\n    auto dfs = [&](auto &dfs, int l, int r) -> int\
    \ {\n      // path[l:r)\n      if (l + 1 < r) {\n        int m = (l + r) / 2;\n\
    \        int x = dfs(dfs, l, m);\n        int y = dfs(dfs, m, r);\n        return\
    \ new_node(x, y, A[x], B[y], true);\n      }\n      assert(r == l + 1);\n    \
    \  if (l == 0) { return path[l]; }\n      // sz, idx\n      pqg<pair<int, int>>\
    \ que;\n      int p = path[l - 1];\n      for (auto &to: tree.collect_light(p))\
    \ {\n        int x = build_dfs(to);\n        que.emplace(tree.subtree_size(to),\
    \ x);\n      }\n      if (que.empty()) { return path[l]; }\n      while (len(que)\
    \ >= 2) {\n        auto [s1, x] = POP(que);\n        auto [s2, y] = POP(que);\n\
    \        int z = new_node(x, y, p, -1, false);\n        que.emplace(s1 + s2, z);\n\
    \      }\n      auto [s, x] = POP(que);\n      return new_node(path[l], x, p,\
    \ path[l], false);\n    };\n    return dfs(dfs, 0, len(path));\n  }\n};\n#line\
    \ 2 \"graph/ds/dynamic_tree_dp.hpp\"\n\n// https://codeforces.com/contest/1172/problem/E\n\
    // https://codeforces.com/contest/1942/problem/H\n// single(v) : v \u3068\u305D\
    \u306E\u89AA\u8FBA\u3092\u5408\u308F\u305B\u305F\u30AF\u30E9\u30B9\u30BF\n// rake(x,\
    \ y, u, v) uv(top down) \u304C boundary \u306B\u306A\u308B\u3088\u3046\u306B rake\
    \ (maybe v=-1)\n// compress(x,y,a,b,c)  (top-down) \u9806\u306B (a,b] + (b,c]\n\
    template <typename TREE, typename Data>\nstruct Dynamic_Tree_Dp {\n  Static_TopTree<TREE>\
    \ STT;\n  vc<Data> dp;\n\n  Dynamic_Tree_Dp(TREE& tree) : STT(tree) {}\n\n  template\
    \ <typename F1, typename F2, typename F3>\n  Data init_dp(F1 single, F2 rake,\
    \ F3 compress) {\n    int n = len(STT.par);\n    dp.resize(n);\n    FOR(i, n)\
    \ { upd(i, single, rake, compress); }\n    return dp.back();\n  }\n\n  template\
    \ <typename F1, typename F2, typename F3>\n  Data recalc(int v, F1 single, F2\
    \ rake, F3 compress) {\n    assert(!dp.empty());\n    for (int k = v; k != -1;\
    \ k = STT.par[k]) { upd(k, single, rake, compress); }\n    return dp.back();\n\
    \  }\n\n  Data get() { return dp.back(); }\n\nprivate:\n  template <typename F1,\
    \ typename F2, typename F3>\n  void upd(int k, F1 single, F2 rake, F3 compress)\
    \ {\n    if (0 <= k && k < STT.N) {\n      dp[k] = single(k);\n      return;\n\
    \    }\n    int l = STT.lch[k], r = STT.rch[k];\n    if (STT.is_compress[k]) {\n\
    \      int a = STT.A[l], b = STT.B[l];\n      int c = STT.A[r], d = STT.B[r];\n\
    \      assert(b == c);\n      dp[k] = compress(dp[l], dp[r], a, b, d);\n    }\
    \ else {\n      dp[k] = rake(dp[l], dp[r], STT.A[k], STT.B[k]);\n    }\n  }\n\
    };\n"
  code: "#include \"graph/ds/static_toptree.hpp\"\n\n// https://codeforces.com/contest/1172/problem/E\n\
    // https://codeforces.com/contest/1942/problem/H\n// single(v) : v \u3068\u305D\
    \u306E\u89AA\u8FBA\u3092\u5408\u308F\u305B\u305F\u30AF\u30E9\u30B9\u30BF\n// rake(x,\
    \ y, u, v) uv(top down) \u304C boundary \u306B\u306A\u308B\u3088\u3046\u306B rake\
    \ (maybe v=-1)\n// compress(x,y,a,b,c)  (top-down) \u9806\u306B (a,b] + (b,c]\n\
    template <typename TREE, typename Data>\nstruct Dynamic_Tree_Dp {\n  Static_TopTree<TREE>\
    \ STT;\n  vc<Data> dp;\n\n  Dynamic_Tree_Dp(TREE& tree) : STT(tree) {}\n\n  template\
    \ <typename F1, typename F2, typename F3>\n  Data init_dp(F1 single, F2 rake,\
    \ F3 compress) {\n    int n = len(STT.par);\n    dp.resize(n);\n    FOR(i, n)\
    \ { upd(i, single, rake, compress); }\n    return dp.back();\n  }\n\n  template\
    \ <typename F1, typename F2, typename F3>\n  Data recalc(int v, F1 single, F2\
    \ rake, F3 compress) {\n    assert(!dp.empty());\n    for (int k = v; k != -1;\
    \ k = STT.par[k]) { upd(k, single, rake, compress); }\n    return dp.back();\n\
    \  }\n\n  Data get() { return dp.back(); }\n\nprivate:\n  template <typename F1,\
    \ typename F2, typename F3>\n  void upd(int k, F1 single, F2 rake, F3 compress)\
    \ {\n    if (0 <= k && k < STT.N) {\n      dp[k] = single(k);\n      return;\n\
    \    }\n    int l = STT.lch[k], r = STT.rch[k];\n    if (STT.is_compress[k]) {\n\
    \      int a = STT.A[l], b = STT.B[l];\n      int c = STT.A[r], d = STT.B[r];\n\
    \      assert(b == c);\n      dp[k] = compress(dp[l], dp[r], a, b, d);\n    }\
    \ else {\n      dp[k] = rake(dp[l], dp[r], STT.A[k], STT.B[k]);\n    }\n  }\n\
    };"
  dependsOn:
  - graph/ds/static_toptree.hpp
  - graph/tree.hpp
  - graph/base.hpp
  isVerificationFile: false
  path: graph/ds/dynamic_tree_dp.hpp
  requiredBy: []
  timestamp: '2024-05-29 22:32:29+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test_atcoder/abc351g.test.cpp
documentation_of: graph/ds/dynamic_tree_dp.hpp
layout: document
redirect_from:
- /library/graph/ds/dynamic_tree_dp.hpp
- /library/graph/ds/dynamic_tree_dp.hpp.html
title: graph/ds/dynamic_tree_dp.hpp
---
