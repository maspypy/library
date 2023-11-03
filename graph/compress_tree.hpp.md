---
data:
  _extendedDependsOn:
  - icon: ':question:'
    path: graph/base.hpp
    title: graph/base.hpp
  - icon: ':heavy_check_mark:'
    path: graph/tree.hpp
    title: graph/tree.hpp
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':warning:'
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
    \ e = edge_type({frm, to, cost, i});\n    edges.eb(e);\n    ++M;\n  }\n\n  //\
    \ wt, off\n  void read_tree(bool wt = false, int off = 1) { read_graph(N - 1,\
    \ wt, off); }\n\n  void read_graph(int M, bool wt = false, int off = 1) {\n  \
    \  for (int m = 0; m < M; ++m) {\n      INT(a, b);\n      a -= off, b -= off;\n\
    \      if (!wt) {\n        add(a, b);\n      } else {\n        T c;\n        read(c);\n\
    \        add(a, b, c);\n      }\n    }\n    build();\n  }\n\n  void build() {\n\
    \    assert(!prepared);\n    prepared = true;\n    indptr.assign(N + 1, 0);\n\
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
    \ }\n  }\n};\n#line 4 \"graph/tree.hpp\"\n\r\n// HLD euler tour \u3092\u3068\u3063\
    \u3066\u3044\u308D\u3044\u308D\u3002\r\ntemplate <typename GT>\r\nstruct Tree\
    \ {\r\n  using Graph_type = GT;\r\n  GT &G;\r\n  using WT = typename GT::cost_type;\r\
    \n  int N;\r\n  vector<int> LID, RID, head, V, parent, VtoE;\r\n  vc<int> depth;\r\
    \n  vc<WT> depth_weighted;\r\n\r\n  Tree(GT &G, int r = 0, bool hld = 1) : G(G)\
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
    \n  }\r\n\r\n  vc<pair<int, int>> get_path_decomposition(int u, int v, bool edge)\
    \ {\r\n    // [\u59CB\u70B9, \u7D42\u70B9] \u306E\"\u9589\"\u533A\u9593\u5217\u3002\
    \r\n    vc<pair<int, int>> up, down;\r\n    while (1) {\r\n      if (head[u] ==\
    \ head[v]) break;\r\n      if (LID[u] < LID[v]) {\r\n        down.eb(LID[head[v]],\
    \ LID[v]);\r\n        v = parent[head[v]];\r\n      } else {\r\n        up.eb(LID[u],\
    \ LID[head[u]]);\r\n        u = parent[head[u]];\r\n      }\r\n    }\r\n    if\
    \ (LID[u] < LID[v]) down.eb(LID[u] + edge, LID[v]);\r\n    elif (LID[v] + edge\
    \ <= LID[u]) up.eb(LID[u], LID[v] + edge);\r\n    reverse(all(down));\r\n    up.insert(up.end(),\
    \ all(down));\r\n    return up;\r\n  }\r\n\r\n  vc<int> restore_path(int u, int\
    \ v) {\r\n    vc<int> P;\r\n    for (auto &&[a, b]: get_path_decomposition(u,\
    \ v, 0)) {\r\n      if (a <= b) {\r\n        FOR(i, a, b + 1) P.eb(V[i]);\r\n\
    \      } else {\r\n        FOR_R(i, b, a + 1) P.eb(V[i]);\r\n      }\r\n    }\r\
    \n    return P;\r\n  }\r\n};\r\n#line 2 \"graph/compress_tree.hpp\"\n\n// (\u5727\
    \u7E2E\u3055\u308C\u305F\u6728\u306E\u9802\u70B9\u30E9\u30D9\u30EB\u305F\u3061\
    \u3001\u30B0\u30E9\u30D5)\n// \u65B0\u3057\u3044\u30B0\u30E9\u30D5\uFF1A\u8FBA\
    \u91CD\u307F\u3042\u308A\ntemplate <typename TREE>\npair<vc<int>, typename TREE::Graph_type>\
    \ compress_tree(TREE& tree, vc<int> V) {\n  // \u5927\u4E8B\u306A\u70B9\u3092\u30EA\
    \u30B9\u30C8\u30A2\u30C3\u30D7\u3059\u308B\n  // \u3082\u3068\u3082\u3068\u306E\
    \u6839\u306F\u542B\u307E\u308C\u308B\u3088\u3046\u306B\u3059\u308B\n  sort(all(V),\
    \ [&](auto& x, auto& y) { return tree.LID[x] < tree.LID[y]; });\n  int n = len(V);\n\
    \  FOR(i, n) {\n    int j = (i + 1 == n ? 0 : i + 1);\n    V.eb(tree.lca(V[i],\
    \ V[j]));\n  }\n  V.eb(tree.V[0]);\n  sort(all(V), [&](auto& x, auto& y) { return\
    \ tree.LID[x] < tree.LID[y]; });\n  V.erase(unique(all(V)), V.end());\n  // \u8FBA\
    \u3092\u5F35\u3063\u3066\u30B0\u30E9\u30D5\u3092\u4F5C\u308B\n  n = len(V);\n\
    \  using GT = typename TREE::Graph_type;\n  using WT = typename GT::cost_type;\n\
    \  GT G(n);\n  vc<int> st = {0};\n  FOR(i, 1, n) {\n    while (1) {\n      int\
    \ p = V[st.back()];\n      int v = V[i];\n      if (tree.in_subtree(v, p)) break;\n\
    \      st.pop_back();\n    }\n    int p = V[st.back()];\n    int v = V[i];\n \
    \   WT d = tree.depth_weighted[v] - tree.depth_weighted[p];\n    G.add(st.back(),\
    \ i, d);\n    st.eb(i);\n  }\n  G.build();\n  return {V, G};\n}\n"
  code: "#include \"graph/tree.hpp\"\n\n// (\u5727\u7E2E\u3055\u308C\u305F\u6728\u306E\
    \u9802\u70B9\u30E9\u30D9\u30EB\u305F\u3061\u3001\u30B0\u30E9\u30D5)\n// \u65B0\
    \u3057\u3044\u30B0\u30E9\u30D5\uFF1A\u8FBA\u91CD\u307F\u3042\u308A\ntemplate <typename\
    \ TREE>\npair<vc<int>, typename TREE::Graph_type> compress_tree(TREE& tree, vc<int>\
    \ V) {\n  // \u5927\u4E8B\u306A\u70B9\u3092\u30EA\u30B9\u30C8\u30A2\u30C3\u30D7\
    \u3059\u308B\n  // \u3082\u3068\u3082\u3068\u306E\u6839\u306F\u542B\u307E\u308C\
    \u308B\u3088\u3046\u306B\u3059\u308B\n  sort(all(V), [&](auto& x, auto& y) { return\
    \ tree.LID[x] < tree.LID[y]; });\n  int n = len(V);\n  FOR(i, n) {\n    int j\
    \ = (i + 1 == n ? 0 : i + 1);\n    V.eb(tree.lca(V[i], V[j]));\n  }\n  V.eb(tree.V[0]);\n\
    \  sort(all(V), [&](auto& x, auto& y) { return tree.LID[x] < tree.LID[y]; });\n\
    \  V.erase(unique(all(V)), V.end());\n  // \u8FBA\u3092\u5F35\u3063\u3066\u30B0\
    \u30E9\u30D5\u3092\u4F5C\u308B\n  n = len(V);\n  using GT = typename TREE::Graph_type;\n\
    \  using WT = typename GT::cost_type;\n  GT G(n);\n  vc<int> st = {0};\n  FOR(i,\
    \ 1, n) {\n    while (1) {\n      int p = V[st.back()];\n      int v = V[i];\n\
    \      if (tree.in_subtree(v, p)) break;\n      st.pop_back();\n    }\n    int\
    \ p = V[st.back()];\n    int v = V[i];\n    WT d = tree.depth_weighted[v] - tree.depth_weighted[p];\n\
    \    G.add(st.back(), i, d);\n    st.eb(i);\n  }\n  G.build();\n  return {V, G};\n\
    }\n"
  dependsOn:
  - graph/tree.hpp
  - graph/base.hpp
  isVerificationFile: false
  path: graph/compress_tree.hpp
  requiredBy: []
  timestamp: '2023-11-01 01:33:38+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: graph/compress_tree.hpp
layout: document
redirect_from:
- /library/graph/compress_tree.hpp
- /library/graph/compress_tree.hpp.html
title: graph/compress_tree.hpp
---
