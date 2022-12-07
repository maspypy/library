---
data:
  _extendedDependsOn:
  - icon: ':question:'
    path: ds/segtree/dual_segtree.hpp
    title: ds/segtree/dual_segtree.hpp
  - icon: ':question:'
    path: graph/base.hpp
    title: graph/base.hpp
  - icon: ':question:'
    path: graph/tree.hpp
    title: graph/tree.hpp
  _extendedRequiredBy:
  - icon: ':question:'
    path: graph/minimum_spanning_tree.hpp
    title: graph/minimum_spanning_tree.hpp
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/aoj/GRL_2_A.test.cpp
    title: test/aoj/GRL_2_A.test.cpp
  - icon: ':x:'
    path: test/atcoder/abc270_f.test.cpp
    title: test/atcoder/abc270_f.test.cpp
  _isVerificationFailed: true
  _pathExtension: hpp
  _verificationStatusIcon: ':question:'
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
    \ { vc_indeg[e.to]++, vc_outdeg[e.frm]++; }\n  }\n};\n#line 3 \"graph/tree.hpp\"\
    \n\r\n// HLD euler tour \u3092\u3068\u3063\u3066\u3044\u308D\u3044\u308D\u3002\
    \r\n// \u6728\u4EE5\u5916\u3001\u975E\u9023\u7D50\u3067\u3082 dfs \u9806\u5E8F\
    \u3084\u89AA\u304C\u3068\u308C\u308B\u3002\r\ntemplate <typename GT>\r\nstruct\
    \ TREE {\r\n  GT &G;\r\n  using WT = typename GT::cost_type;\r\n  int N;\r\n \
    \ bool hld;\r\n  vector<int> LID, RID, head, V, parent, root;\r\n  vc<int> depth;\r\
    \n  vc<WT> depth_weighted;\r\n  vector<bool> in_tree;\r\n\r\n  TREE(GT &G, int\
    \ r = -1, bool hld = 1)\r\n      : G(G),\r\n        N(G.N),\r\n        hld(hld),\r\
    \n        LID(G.N),\r\n        RID(G.N),\r\n        head(G.N, r),\r\n        V(G.N),\r\
    \n        parent(G.N, -1),\r\n        root(G.N, -1),\r\n        depth(G.N, -1),\r\
    \n        depth_weighted(G.N, 0),\r\n        in_tree(G.M, 0) {\r\n    assert(G.is_prepared());\r\
    \n    int t1 = 0;\r\n    if (r != -1) {\r\n      dfs_sz(r, -1);\r\n      dfs_hld(r,\
    \ t1);\r\n    } else {\r\n      for (int r = 0; r < N; ++r) {\r\n        if (parent[r]\
    \ == -1) {\r\n          head[r] = r;\r\n          dfs_sz(r, -1);\r\n         \
    \ dfs_hld(r, t1);\r\n        }\r\n      }\r\n    }\r\n    for (auto &&v: V) root[v]\
    \ = (parent[v] == -1 ? v : root[parent[v]]);\r\n  }\r\n\r\n  void dfs_sz(int v,\
    \ int p) {\r\n    auto &sz = RID;\r\n    parent[v] = p;\r\n    depth[v] = (p ==\
    \ -1 ? 0 : depth[p] + 1);\r\n    sz[v] = 1;\r\n    int l = G.indptr[v], r = G.indptr[v\
    \ + 1];\r\n    auto &csr = G.csr_edges;\r\n    // \u4F7F\u3046\u8FBA\u304C\u3042\
    \u308C\u3070\u5148\u982D\u306B\u3059\u308B\r\n    for (int i = r - 2; i >= l;\
    \ --i) {\r\n      if (hld && depth[csr[i + 1].to] == -1) swap(csr[i], csr[i +\
    \ 1]);\r\n    }\r\n    int hld_sz = 0;\r\n    for (int i = l; i < r; ++i) {\r\n\
    \      auto e = csr[i];\r\n      if (depth[e.to] != -1) continue;\r\n      in_tree[e.id]\
    \ = 1;\r\n      depth_weighted[e.to] = depth_weighted[v] + e.cost;\r\n      dfs_sz(e.to,\
    \ v);\r\n      sz[v] += sz[e.to];\r\n      if (hld && chmax(hld_sz, sz[e.to])\
    \ && l < i) { swap(csr[l], csr[i]); }\r\n    }\r\n  }\r\n\r\n  void dfs_hld(int\
    \ v, int &times) {\r\n    LID[v] = times++;\r\n    RID[v] += LID[v];\r\n    V[LID[v]]\
    \ = v;\r\n    bool heavy = true;\r\n    for (auto &&e: G[v]) {\r\n      if (!in_tree[e.id]\
    \ || depth[e.to] <= depth[v]) continue;\r\n      head[e.to] = (heavy ? head[v]\
    \ : e.to);\r\n      heavy = false;\r\n      dfs_hld(e.to, times);\r\n    }\r\n\
    \  }\r\n\r\n  vc<int> heavy_path_at(int v) {\r\n    vc<int> P = {v};\r\n    while\
    \ (1) {\r\n      int a = P.back();\r\n      for (auto &&e: G[a]) {\r\n       \
    \ if (e.to != parent[a] && head[e.to] == v) {\r\n          P.eb(e.to);\r\n   \
    \       break;\r\n        }\r\n      }\r\n      if (P.back() == a) break;\r\n\
    \    }\r\n    return P;\r\n  }\r\n\r\n  int e_to_v(int eid) {\r\n    auto e =\
    \ G.edges[eid];\r\n    return (parent[e.frm] == e.to ? e.frm : e.to);\r\n  }\r\
    \n\r\n  int ELID(int v) { return 2 * LID[v] - depth[v]; }\r\n  int ERID(int v)\
    \ { return 2 * RID[v] - depth[v] - 1; }\r\n\r\n  /* k: 0-indexed */\r\n  int LA(int\
    \ v, int k) {\r\n    assert(k <= depth[v]);\r\n    while (1) {\r\n      int u\
    \ = head[v];\r\n      if (LID[v] - k >= LID[u]) return V[LID[v] - k];\r\n    \
    \  k -= LID[v] - LID[u] + 1;\r\n      v = parent[u];\r\n    }\r\n  }\r\n\r\n \
    \ int LCA(int u, int v) {\r\n    for (;; v = parent[head[v]]) {\r\n      if (LID[u]\
    \ > LID[v]) swap(u, v);\r\n      if (head[u] == head[v]) return u;\r\n    }\r\n\
    \  }\r\n\r\n  int lca(int u, int v) { return LCA(u, v); }\r\n  int la(int u, int\
    \ v) { return LA(u, v); }\r\n\r\n  int subtree_size(int v) { return RID[v] - LID[v];\
    \ }\r\n\r\n  int dist(int a, int b) {\r\n    int c = LCA(a, b);\r\n    return\
    \ depth[a] + depth[b] - 2 * depth[c];\r\n  }\r\n\r\n  WT dist(int a, int b, bool\
    \ weighted) {\r\n    assert(weighted);\r\n    int c = LCA(a, b);\r\n    return\
    \ depth_weighted[a] + depth_weighted[b] - WT(2) * depth_weighted[c];\r\n  }\r\n\
    \r\n  // a is in b\r\n  bool in_subtree(int a, int b) { return LID[b] <= LID[a]\
    \ && LID[a] < RID[b]; }\r\n\r\n  int jump(int a, int b, ll k) {\r\n    if (k ==\
    \ 1) {\r\n      if (a == b) return -1;\r\n      return (in_subtree(b, a) ? LA(b,\
    \ depth[b] - depth[a] - 1) : parent[a]);\r\n    }\r\n    int c = LCA(a, b);\r\n\
    \    int d_ac = depth[a] - depth[c];\r\n    int d_bc = depth[b] - depth[c];\r\n\
    \    if (k > d_ac + d_bc) return -1;\r\n    if (k <= d_ac) return LA(a, k);\r\n\
    \    return LA(b, d_ac + d_bc - k);\r\n  }\r\n\r\n  vc<int> collect_child(int\
    \ v) {\r\n    vc<int> res;\r\n    for (auto &&e: G[v])\r\n      if (e.to != parent[v])\
    \ res.eb(e.to);\r\n    return res;\r\n  }\r\n\r\n  vc<pair<int, int>> get_path_decomposition(int\
    \ u, int v, bool edge) {\r\n    // [\u59CB\u70B9, \u7D42\u70B9] \u306E\"\u9589\
    \"\u533A\u9593\u5217\u3002\r\n    vc<pair<int, int>> up, down;\r\n    while (1)\
    \ {\r\n      if (head[u] == head[v]) break;\r\n      if (LID[u] < LID[v]) {\r\n\
    \        down.eb(LID[head[v]], LID[v]);\r\n        v = parent[head[v]];\r\n  \
    \    } else {\r\n        up.eb(LID[u], LID[head[u]]);\r\n        u = parent[head[u]];\r\
    \n      }\r\n    }\r\n    if (LID[u] < LID[v]) down.eb(LID[u] + edge, LID[v]);\r\
    \n    elif (LID[v] + edge <= LID[u]) up.eb(LID[u], LID[v] + edge);\r\n    reverse(all(down));\r\
    \n    up.insert(up.end(), all(down));\r\n    return up;\r\n  }\r\n\r\n  void debug()\
    \ {\r\n    print(\"V\", V);\r\n    print(\"LID\", LID);\r\n    print(\"RID\",\
    \ RID);\r\n    print(\"parent\", parent);\r\n    print(\"depth\", depth);\r\n\
    \    print(\"head\", head);\r\n    print(\"in_tree(edge)\", in_tree);\r\n    print(\"\
    root\", root);\r\n  }\r\n};\r\n#line 2 \"ds/segtree/dual_segtree.hpp\"\n\ntemplate\
    \ <typename Monoid>\nstruct Dual_SegTree {\n  using MA = Monoid;\n  using A =\
    \ typename MA::value_type;\n  int n, log, size;\n  vc<A> laz;\n\n  Dual_SegTree()\
    \ : Dual_SegTree(0) {}\n  Dual_SegTree(int n) { build(n); }\n\n  void build(int\
    \ m) {\n    n = m;\n    log = 1;\n    while ((1 << log) < n) ++log;\n    size\
    \ = 1 << log;\n    laz.assign(size << 1, MA::unit());\n  }\n\n  A get(int p) {\n\
    \    assert(0 <= p && p < n);\n    p += size;\n    for (int i = log; i >= 1; i--)\
    \ push(p >> i);\n    return laz[p];\n  }\n\n  vc<A> get_all() {\n    FOR(i, size)\
    \ push(i);\n    return {laz.begin() + size, laz.begin() + size + n};\n  }\n\n\
    \  void apply(int l, int r, const A& a) {\n    assert(0 <= l && l <= r && r <=\
    \ n);\n    if (l == r) return;\n    l += size, r += size;\n    if (!MA::commute)\
    \ {\n      for (int i = log; i >= 1; i--) {\n        if (((l >> i) << i) != l)\
    \ push(l >> i);\n        if (((r >> i) << i) != r) push((r - 1) >> i);\n     \
    \ }\n    }\n    while (l < r) {\n      if (l & 1) all_apply(l++, a);\n      if\
    \ (r & 1) all_apply(--r, a);\n      l >>= 1, r >>= 1;\n    }\n  }\n\nprivate:\n\
    \  void push(int k) {\n    if (laz[k] == MA::unit()) return;\n    all_apply(2\
    \ * k, laz[k]), all_apply(2 * k + 1, laz[k]);\n    laz[k] = MA::unit();\n  }\n\
    \  void all_apply(int k, A a) { laz[k] = MA::op(laz[k], a); }\n};\n#line 3 \"\
    graph/ds/dual_tree_monoid.hpp\"\n\r\ntemplate <typename TREE, typename Monoid,\
    \ bool edge = false>\r\nstruct Dual_Tree_Monoid {\r\n  using X = typename Monoid::value_type;\r\
    \n  TREE &tree;\r\n  int N;\r\n  Dual_SegTree<Monoid> seg;\r\n\r\n  Dual_Tree_Monoid(TREE\
    \ &tree) : tree(tree), N(tree.N), seg(tree.N) {}\r\n\r\n  X get(int i) {\r\n \
    \   int v = i;\r\n    if (edge) {\r\n      auto &&e = tree.G.edges[i];\r\n   \
    \   v = (tree.parent[e.frm] == e.to ? e.frm : e.to);\r\n    }\r\n    return seg.get(tree.LID[v]);\r\
    \n  }\r\n\r\n  vc<X> get_all() {\r\n    vc<X> tmp = seg.get_all();\r\n    vc<X>\
    \ res;\r\n    FOR(i, N) {\r\n      if (edge && i == N - 1) break;\r\n      int\
    \ v = i;\r\n      if (edge) {\r\n        auto &&e = tree.G.edges[i];\r\n     \
    \   v = (tree.parent[e.frm] == e.to ? e.frm : e.to);\r\n      }\r\n      res.eb(tmp[tree.LID[v]]);\r\
    \n    }\r\n    return res;\r\n  }\r\n\r\n  void apply_path(int u, int v, X x)\
    \ {\r\n    auto pd = tree.get_path_decomposition(u, v, edge);\r\n    for (auto\
    \ &&[a, b]: pd) {\r\n      (a <= b ? seg.apply(a, b + 1, x) : seg.apply(b, a +\
    \ 1, x));\r\n    }\r\n    return;\r\n  }\r\n\r\n  void apply_subtree(int u, X\
    \ x) {\r\n    int l = tree.LID[u], r = tree.RID[u];\r\n    return seg.apply(l\
    \ + edge, r, x);\r\n  }\r\n};\r\n"
  code: "#include \"graph/tree.hpp\"\r\n#include \"ds/segtree/dual_segtree.hpp\"\r\
    \n\r\ntemplate <typename TREE, typename Monoid, bool edge = false>\r\nstruct Dual_Tree_Monoid\
    \ {\r\n  using X = typename Monoid::value_type;\r\n  TREE &tree;\r\n  int N;\r\
    \n  Dual_SegTree<Monoid> seg;\r\n\r\n  Dual_Tree_Monoid(TREE &tree) : tree(tree),\
    \ N(tree.N), seg(tree.N) {}\r\n\r\n  X get(int i) {\r\n    int v = i;\r\n    if\
    \ (edge) {\r\n      auto &&e = tree.G.edges[i];\r\n      v = (tree.parent[e.frm]\
    \ == e.to ? e.frm : e.to);\r\n    }\r\n    return seg.get(tree.LID[v]);\r\n  }\r\
    \n\r\n  vc<X> get_all() {\r\n    vc<X> tmp = seg.get_all();\r\n    vc<X> res;\r\
    \n    FOR(i, N) {\r\n      if (edge && i == N - 1) break;\r\n      int v = i;\r\
    \n      if (edge) {\r\n        auto &&e = tree.G.edges[i];\r\n        v = (tree.parent[e.frm]\
    \ == e.to ? e.frm : e.to);\r\n      }\r\n      res.eb(tmp[tree.LID[v]]);\r\n \
    \   }\r\n    return res;\r\n  }\r\n\r\n  void apply_path(int u, int v, X x) {\r\
    \n    auto pd = tree.get_path_decomposition(u, v, edge);\r\n    for (auto &&[a,\
    \ b]: pd) {\r\n      (a <= b ? seg.apply(a, b + 1, x) : seg.apply(b, a + 1, x));\r\
    \n    }\r\n    return;\r\n  }\r\n\r\n  void apply_subtree(int u, X x) {\r\n  \
    \  int l = tree.LID[u], r = tree.RID[u];\r\n    return seg.apply(l + edge, r,\
    \ x);\r\n  }\r\n};\r\n"
  dependsOn:
  - graph/tree.hpp
  - graph/base.hpp
  - ds/segtree/dual_segtree.hpp
  isVerificationFile: false
  path: graph/ds/dual_tree_monoid.hpp
  requiredBy:
  - graph/minimum_spanning_tree.hpp
  timestamp: '2022-12-05 10:41:25+09:00'
  verificationStatus: LIBRARY_SOME_WA
  verifiedWith:
  - test/atcoder/abc270_f.test.cpp
  - test/aoj/GRL_2_A.test.cpp
documentation_of: graph/ds/dual_tree_monoid.hpp
layout: document
redirect_from:
- /library/graph/ds/dual_tree_monoid.hpp
- /library/graph/ds/dual_tree_monoid.hpp.html
title: graph/ds/dual_tree_monoid.hpp
---
