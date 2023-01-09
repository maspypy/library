---
data:
  _extendedDependsOn:
  - icon: ':question:'
    path: alg/monoid/monoid_reverse.hpp
    title: alg/monoid/monoid_reverse.hpp
  - icon: ':question:'
    path: ds/disjointsparse/disjointsparse.hpp
    title: ds/disjointsparse/disjointsparse.hpp
  - icon: ':question:'
    path: graph/base.hpp
    title: graph/base.hpp
  - icon: ':question:'
    path: graph/tree.hpp
    title: graph/tree.hpp
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':x:'
    path: test/yukicoder/1216.test.cpp
    title: test/yukicoder/1216.test.cpp
  - icon: ':x:'
    path: test/yukicoder/1216_2.test.cpp
    title: test/yukicoder/1216_2.test.cpp
  _isVerificationFailed: true
  _pathExtension: hpp
  _verificationStatusIcon: ':x:'
  attributes:
    links:
    - https://atcoder.jp/contests/tkppc3/tasks/tkppc3_i
    - https://codeforces.com/contest/1059/problem/E
    - https://codeforces.com/contest/1230/problem/E
  bundledCode: "#line 2 \"ds/disjointsparse/disjointsparse.hpp\"\n\r\ntemplate <class\
    \ Monoid>\r\nstruct DisjointSparse {\r\n  using MX = Monoid;\r\n  using X = typename\
    \ MX::value_type;\r\n  int n, log;\r\n  vvc<X> dat;\r\n\r\n  DisjointSparse()\
    \ {}\r\n  DisjointSparse(int n) { build(n); }\r\n  template <typename F>\r\n \
    \ DisjointSparse(int n, F f) {\r\n    build(n, f);\r\n  }\r\n  DisjointSparse(const\
    \ vc<X>& v) { build(v); }\r\n\r\n  void build(int m) {\r\n    build(m, [](int\
    \ i) -> X { return MX::unit(); });\r\n  }\r\n  void build(const vc<X>& v) {\r\n\
    \    build(len(v), [&](int i) -> X { return v[i]; });\r\n  }\r\n  template <typename\
    \ F>\r\n  void build(int m, F f) {\r\n    n = m, log = 1;\r\n    while ((1 <<\
    \ log) < n) ++log;\r\n    dat.resize(log);\r\n    dat[0].reserve(n);\r\n    FOR(i,\
    \ n) dat[0].eb(f(i));\r\n    FOR(i, 1, log) {\r\n      auto& v = dat[i];\r\n \
    \     v = dat[0];\r\n      int b = 1 << i;\r\n      for (int m = b; m <= n; m\
    \ += 2 * b) {\r\n        int L = m - b, R = min(n, m + b);\r\n        FOR3_R(j,\
    \ L + 1, m) v[j - 1] = MX::op(v[j - 1], v[j]);\r\n        FOR3(j, m, R - 1) v[j\
    \ + 1] = MX::op(v[j], v[j + 1]);\r\n      }\r\n    }\r\n  }\r\n\r\n  X prod(int\
    \ L, int R) {\r\n    if (L == R) return MX::unit();\r\n    --R;\r\n    if (L ==\
    \ R) return dat[0][L];\r\n    int k = 31 - __builtin_clz(L ^ R);\r\n    return\
    \ MX::op(dat[k][L], dat[k][R]);\r\n  }\r\n\r\n  template <class F>\r\n  int max_right(const\
    \ F check, int L) {\r\n    assert(0 <= L && L <= n && check(MX::unit()));\r\n\
    \    if (L == n) return n;\r\n    int ok = L, ng = n + 1;\r\n    while (ok + 1\
    \ < ng) {\r\n      int k = (ok + ng) / 2;\r\n      bool bl = check(prod(L, k));\r\
    \n      if (bl) ok = k;\r\n      if (!bl) ng = k;\r\n    }\r\n    return ok;\r\
    \n  }\r\n\r\n  template <class F>\r\n  int min_left(const F check, int R) {\r\n\
    \    assert(0 <= R && R <= n && check(MX::unit()));\r\n    if (R == 0) return\
    \ 0;\r\n    int ok = R, ng = -1;\r\n    while (ng + 1 < ok) {\r\n      int k =\
    \ (ok + ng) / 2;\r\n      bool bl = check(prod(k, R));\r\n      if (bl) ok = k;\r\
    \n      if (!bl) ng = k;\r\n    }\r\n    return ok;\r\n  }\r\n};\n#line 2 \"graph/base.hpp\"\
    \n\ntemplate <typename T>\nstruct Edge {\n  int frm, to;\n  T cost;\n  int id;\n\
    };\n\ntemplate <typename T = int, bool directed = false>\nstruct Graph {\n  int\
    \ N, M;\n  using cost_type = T;\n  using edge_type = Edge<T>;\n  vector<edge_type>\
    \ edges;\n  vector<int> indptr;\n  vector<edge_type> csr_edges;\n  vc<int> vc_deg,\
    \ vc_indeg, vc_outdeg;\n  bool prepared;\n\n  class OutgoingEdges {\n  public:\n\
    \    OutgoingEdges(const Graph* G, int l, int r) : G(G), l(l), r(r) {}\n\n   \
    \ const edge_type* begin() const {\n      if (l == r) { return 0; }\n      return\
    \ &G->csr_edges[l];\n    }\n\n    const edge_type* end() const {\n      if (l\
    \ == r) { return 0; }\n      return &G->csr_edges[r];\n    }\n\n  private:\n \
    \   const Graph* G;\n    int l, r;\n  };\n\n  bool is_prepared() { return prepared;\
    \ }\n  constexpr bool is_directed() { return directed; }\n\n  Graph() : N(0),\
    \ M(0), prepared(0) {}\n  Graph(int N) : N(N), M(0), prepared(0) {}\n\n  void\
    \ resize(int n) { N = n; }\n\n  void add(int frm, int to, T cost = 1, int i =\
    \ -1) {\n    assert(!prepared);\n    assert(0 <= frm && 0 <= to && to < N);\n\
    \    if (i == -1) i = M;\n    auto e = edge_type({frm, to, cost, i});\n    edges.eb(e);\n\
    \    ++M;\n  }\n\n  // wt, off\n  void read_tree(bool wt = false, int off = 1)\
    \ { read_graph(N - 1, wt, off); }\n\n  void read_graph(int M, bool wt = false,\
    \ int off = 1) {\n    for (int m = 0; m < M; ++m) {\n      INT(a, b);\n      a\
    \ -= off, b -= off;\n      if (!wt) {\n        add(a, b);\n      } else {\n  \
    \      T c;\n        read(c);\n        add(a, b, c);\n      }\n    }\n    build();\n\
    \  }\n\n  void read_parent(int off = 1) {\n    for (int v = 1; v < N; ++v) {\n\
    \      INT(p);\n      p -= off;\n      add(p, v);\n    }\n    build();\n  }\n\n\
    \  void build() {\n    assert(!prepared);\n    prepared = true;\n    indptr.assign(N\
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
    \ print(e.frm, e.to, e.cost, e.id);\n    }\n  }\n\nprivate:\n  void calc_deg()\
    \ {\n    assert(vc_deg.empty());\n    vc_deg.resize(N);\n    for (auto&& e: edges)\
    \ vc_deg[e.frm]++, vc_deg[e.to]++;\n  }\n\n  void calc_deg_inout() {\n    assert(vc_indeg.empty());\n\
    \    vc_indeg.resize(N);\n    vc_outdeg.resize(N);\n    for (auto&& e: edges)\
    \ { vc_indeg[e.to]++, vc_outdeg[e.frm]++; }\n  }\n};\n#line 3 \"graph/tree.hpp\"\
    \n\r\n// HLD euler tour \u3092\u3068\u3063\u3066\u3044\u308D\u3044\u308D\u3002\
    \r\n// \u6728\u4EE5\u5916\u3001\u975E\u9023\u7D50\u3067\u3082 dfs \u9806\u5E8F\
    \u3084\u89AA\u304C\u3068\u308C\u308B\u3002\r\ntemplate <typename GT>\r\nstruct\
    \ TREE {\r\n  using Graph_type = GT;\r\n  GT &G;\r\n  using WT = typename GT::cost_type;\r\
    \n  int N;\r\n  bool hld;\r\n  vector<int> LID, RID, head, V, parent, root;\r\n\
    \  vc<int> depth;\r\n  vc<WT> depth_weighted;\r\n  vector<bool> in_tree;\r\n\r\
    \n  TREE(GT &G, int r = -1, bool hld = 1)\r\n      : G(G),\r\n        N(G.N),\r\
    \n        hld(hld),\r\n        LID(G.N),\r\n        RID(G.N),\r\n        head(G.N,\
    \ r),\r\n        V(G.N),\r\n        parent(G.N, -1),\r\n        root(G.N, -1),\r\
    \n        depth(G.N, -1),\r\n        depth_weighted(G.N, 0),\r\n        in_tree(G.M,\
    \ 0) {\r\n    assert(G.is_prepared());\r\n    int t1 = 0;\r\n    if (r != -1)\
    \ {\r\n      dfs_sz(r, -1);\r\n      dfs_hld(r, t1);\r\n    } else {\r\n     \
    \ for (int r = 0; r < N; ++r) {\r\n        if (parent[r] == -1) {\r\n        \
    \  head[r] = r;\r\n          dfs_sz(r, -1);\r\n          dfs_hld(r, t1);\r\n \
    \       }\r\n      }\r\n    }\r\n    for (auto &&v: V) root[v] = (parent[v] ==\
    \ -1 ? v : root[parent[v]]);\r\n  }\r\n\r\n  void dfs_sz(int v, int p) {\r\n \
    \   auto &sz = RID;\r\n    parent[v] = p;\r\n    depth[v] = (p == -1 ? 0 : depth[p]\
    \ + 1);\r\n    sz[v] = 1;\r\n    int l = G.indptr[v], r = G.indptr[v + 1];\r\n\
    \    auto &csr = G.csr_edges;\r\n    // \u4F7F\u3046\u8FBA\u304C\u3042\u308C\u3070\
    \u5148\u982D\u306B\u3059\u308B\r\n    for (int i = r - 2; i >= l; --i) {\r\n \
    \     if (hld && depth[csr[i + 1].to] == -1) swap(csr[i], csr[i + 1]);\r\n   \
    \ }\r\n    int hld_sz = 0;\r\n    for (int i = l; i < r; ++i) {\r\n      auto\
    \ e = csr[i];\r\n      if (depth[e.to] != -1) continue;\r\n      in_tree[e.id]\
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
    \n    up.insert(up.end(), all(down));\r\n    return up;\r\n  }\r\n\r\n  vc<int>\
    \ restore_path(int u, int v) {\r\n    vc<int> P;\r\n    for (auto &&[a, b]: get_path_decomposition(u,\
    \ v, 0)) {\r\n      if (a <= b) {\r\n        FOR(i, a, b + 1) P.eb(V[i]);\r\n\
    \      } else {\r\n        FOR_R(i, b, a + 1) P.eb(V[i]);\r\n      }\r\n    }\r\
    \n    return P;\r\n  }\r\n};\r\n#line 2 \"alg/monoid/monoid_reverse.hpp\"\n\r\n\
    template <class Monoid>\r\nstruct Monoid_Reverse {\r\n  using value_type = typename\
    \ Monoid::value_type;\r\n  using X = value_type;\r\n  static constexpr X op(const\
    \ X &x, const X &y) { return Monoid::op(y, x); }\r\n  static constexpr X unit()\
    \ { return Monoid::unit(); }\r\n  static const bool commute = Monoid::commute;\r\
    \n};\r\n#line 4 \"graph/ds/static_tree_monoid.hpp\"\n\ntemplate <typename TREE,\
    \ typename Monoid, bool edge = false>\nstruct Static_Tree_Monoid {\n  using RevMonoid\
    \ = Monoid_Reverse<Monoid>;\n  using X = typename Monoid::value_type;\n  TREE\
    \ &tree;\n  int N;\n  DisjointSparse<Monoid> seg;\n  DisjointSparse<RevMonoid>\
    \ seg_r;\n\n  Static_Tree_Monoid(TREE &tree) : tree(tree), N(tree.N), seg(tree.N)\
    \ {\n    if (!Monoid::commute) seg_r = DisjointSparse<RevMonoid>(tree.N);\n  }\n\
    \n  Static_Tree_Monoid(TREE &tree, vc<X> &dat) : tree(tree), N(tree.N) {\n   \
    \ vc<X> seg_raw(N, Monoid::unit());\n    if (!edge) {\n      FOR(v, N) seg_raw[tree.LID[v]]\
    \ = dat[v];\n    } else {\n      FOR(e, N - 1) {\n        int v = tree.e_to_v(e);\n\
    \        seg_raw[tree.LID[v]] = dat[e];\n      }\n    }\n    seg = DisjointSparse<Monoid>(seg_raw);\n\
    \    if (!Monoid::commute) seg_r = DisjointSparse<RevMonoid>(seg_raw);\n  }\n\n\
    \  X prod_path(int u, int v) {\n    auto pd = tree.get_path_decomposition(u, v,\
    \ edge);\n    X val = Monoid::unit();\n    for (auto &&[a, b]: pd) {\n      X\
    \ x = (a <= b ? seg.prod(a, b + 1)\n                    : (Monoid::commute ? seg.prod(b,\
    \ a + 1)\n                                       : seg_r.prod(b, a + 1)));\n \
    \     val = Monoid::op(val, x);\n    }\n    return val;\n  }\n\n  // uv path \u4E0A\
    \u3067 prod_path(u, x) \u304C check \u3092\u6E80\u305F\u3059\u6700\u5F8C\u306E\
    \ x\n  // \u306A\u3051\u308C\u3070 -1\n  // https://codeforces.com/contest/1059/problem/E\n\
    \  // https://codeforces.com/contest/1230/problem/E\n  // edge: https://atcoder.jp/contests/tkppc3/tasks/tkppc3_i\n\
    \  // edge \u304C\u7279\u306B\u602A\u3057\u3044\u304B\u3082\n  template <class\
    \ F>\n  int max_path(F &check, int u, int v) {\n    if (edge) return max_path_edge(check,\
    \ u, v);\n    if (!check(prod_path(u, u))) return -1;\n    auto pd = tree.get_path_decomposition(u,\
    \ v, edge);\n    X val = Monoid::unit();\n    for (auto &&[a, b]: pd) {\n    \
    \  X x = (a <= b ? seg.prod(a, b + 1)\n                    : (Monoid::commute\
    \ ? seg.prod(b, a + 1)\n                                       : seg_r.prod(b,\
    \ a + 1)));\n      if (check(Monoid::op(val, x))) {\n        val = Monoid::op(val,\
    \ x);\n        u = (tree.V[b]);\n        continue;\n      }\n      auto check_tmp\
    \ = [&](X x) -> bool { return check(Monoid::op(val, x)); };\n      if (a <= b)\
    \ {\n        // \u4E0B\u308A\n        auto i = seg.max_right(check_tmp, a);\n\
    \        return (i == a ? u : tree.V[i - 1]);\n      } else {\n        // \u4E0A\
    \u308A\n        auto i = (Monoid::commute ? seg.min_left(check_tmp, a + 1)\n \
    \                                 : seg_r.min_left(check_tmp, a + 1));\n     \
    \   if (i == a + 1) return u;\n        return (edge ? tree.parent[tree.V[i]] :\
    \ tree.V[i]);\n      }\n    }\n    return v;\n  }\n\n  X prod_subtree(int u) {\n\
    \    int l = tree.LID[u], r = tree.RID[u];\n    return seg.prod(l + edge, r);\n\
    \  }\n\n  void debug() {\n    print(\"tree_monoid\");\n    tree.debug();\n   \
    \ seg.debug();\n    seg_r.debug();\n  }\n\nprivate:\n  template <class F>\n  int\
    \ max_path_edge(F &check, int u, int v) {\n    assert(edge);\n    if (!check(Monoid::unit()))\
    \ return -1;\n    int lca = tree.lca(u, v);\n    auto pd = tree.get_path_decomposition(u,\
    \ lca, edge);\n    X val = Monoid::unit();\n\n    // climb\n    for (auto &&[a,\
    \ b]: pd) {\n      assert(a >= b);\n      X x = (Monoid::commute ? seg.prod(b,\
    \ a + 1) : seg_r.prod(b, a + 1));\n      if (check(Monoid::op(val, x))) {\n  \
    \      val = Monoid::op(val, x);\n        u = (tree.parent[tree.V[b]]);\n    \
    \    continue;\n      }\n      auto check_tmp = [&](X x) -> bool { return check(Monoid::op(val,\
    \ x)); };\n      auto i = (Monoid::commute ? seg.min_left(check_tmp, a + 1)\n\
    \                                : seg_r.min_left(check_tmp, a + 1));\n      if\
    \ (i == a + 1) return u;\n      return tree.parent[tree.V[i]];\n    }\n    //\
    \ down\n    pd = tree.get_path_decomposition(lca, v, edge);\n    for (auto &&[a,\
    \ b]: pd) {\n      assert(a <= b);\n      X x = seg.prod(a, b + 1);\n      if\
    \ (check(Monoid::op(val, x))) {\n        val = Monoid::op(val, x);\n        u\
    \ = (tree.V[b]);\n        continue;\n      }\n      auto check_tmp = [&](X x)\
    \ -> bool { return check(Monoid::op(val, x)); };\n      auto i = seg.max_right(check_tmp,\
    \ a);\n      return (i == a ? u : tree.V[i - 1]);\n    }\n    return v;\n  }\n\
    };\n"
  code: "#include \"ds/disjointsparse/disjointsparse.hpp\"\n#include \"graph/tree.hpp\"\
    \n#include \"alg/monoid/monoid_reverse.hpp\"\n\ntemplate <typename TREE, typename\
    \ Monoid, bool edge = false>\nstruct Static_Tree_Monoid {\n  using RevMonoid =\
    \ Monoid_Reverse<Monoid>;\n  using X = typename Monoid::value_type;\n  TREE &tree;\n\
    \  int N;\n  DisjointSparse<Monoid> seg;\n  DisjointSparse<RevMonoid> seg_r;\n\
    \n  Static_Tree_Monoid(TREE &tree) : tree(tree), N(tree.N), seg(tree.N) {\n  \
    \  if (!Monoid::commute) seg_r = DisjointSparse<RevMonoid>(tree.N);\n  }\n\n \
    \ Static_Tree_Monoid(TREE &tree, vc<X> &dat) : tree(tree), N(tree.N) {\n    vc<X>\
    \ seg_raw(N, Monoid::unit());\n    if (!edge) {\n      FOR(v, N) seg_raw[tree.LID[v]]\
    \ = dat[v];\n    } else {\n      FOR(e, N - 1) {\n        int v = tree.e_to_v(e);\n\
    \        seg_raw[tree.LID[v]] = dat[e];\n      }\n    }\n    seg = DisjointSparse<Monoid>(seg_raw);\n\
    \    if (!Monoid::commute) seg_r = DisjointSparse<RevMonoid>(seg_raw);\n  }\n\n\
    \  X prod_path(int u, int v) {\n    auto pd = tree.get_path_decomposition(u, v,\
    \ edge);\n    X val = Monoid::unit();\n    for (auto &&[a, b]: pd) {\n      X\
    \ x = (a <= b ? seg.prod(a, b + 1)\n                    : (Monoid::commute ? seg.prod(b,\
    \ a + 1)\n                                       : seg_r.prod(b, a + 1)));\n \
    \     val = Monoid::op(val, x);\n    }\n    return val;\n  }\n\n  // uv path \u4E0A\
    \u3067 prod_path(u, x) \u304C check \u3092\u6E80\u305F\u3059\u6700\u5F8C\u306E\
    \ x\n  // \u306A\u3051\u308C\u3070 -1\n  // https://codeforces.com/contest/1059/problem/E\n\
    \  // https://codeforces.com/contest/1230/problem/E\n  // edge: https://atcoder.jp/contests/tkppc3/tasks/tkppc3_i\n\
    \  // edge \u304C\u7279\u306B\u602A\u3057\u3044\u304B\u3082\n  template <class\
    \ F>\n  int max_path(F &check, int u, int v) {\n    if (edge) return max_path_edge(check,\
    \ u, v);\n    if (!check(prod_path(u, u))) return -1;\n    auto pd = tree.get_path_decomposition(u,\
    \ v, edge);\n    X val = Monoid::unit();\n    for (auto &&[a, b]: pd) {\n    \
    \  X x = (a <= b ? seg.prod(a, b + 1)\n                    : (Monoid::commute\
    \ ? seg.prod(b, a + 1)\n                                       : seg_r.prod(b,\
    \ a + 1)));\n      if (check(Monoid::op(val, x))) {\n        val = Monoid::op(val,\
    \ x);\n        u = (tree.V[b]);\n        continue;\n      }\n      auto check_tmp\
    \ = [&](X x) -> bool { return check(Monoid::op(val, x)); };\n      if (a <= b)\
    \ {\n        // \u4E0B\u308A\n        auto i = seg.max_right(check_tmp, a);\n\
    \        return (i == a ? u : tree.V[i - 1]);\n      } else {\n        // \u4E0A\
    \u308A\n        auto i = (Monoid::commute ? seg.min_left(check_tmp, a + 1)\n \
    \                                 : seg_r.min_left(check_tmp, a + 1));\n     \
    \   if (i == a + 1) return u;\n        return (edge ? tree.parent[tree.V[i]] :\
    \ tree.V[i]);\n      }\n    }\n    return v;\n  }\n\n  X prod_subtree(int u) {\n\
    \    int l = tree.LID[u], r = tree.RID[u];\n    return seg.prod(l + edge, r);\n\
    \  }\n\n  void debug() {\n    print(\"tree_monoid\");\n    tree.debug();\n   \
    \ seg.debug();\n    seg_r.debug();\n  }\n\nprivate:\n  template <class F>\n  int\
    \ max_path_edge(F &check, int u, int v) {\n    assert(edge);\n    if (!check(Monoid::unit()))\
    \ return -1;\n    int lca = tree.lca(u, v);\n    auto pd = tree.get_path_decomposition(u,\
    \ lca, edge);\n    X val = Monoid::unit();\n\n    // climb\n    for (auto &&[a,\
    \ b]: pd) {\n      assert(a >= b);\n      X x = (Monoid::commute ? seg.prod(b,\
    \ a + 1) : seg_r.prod(b, a + 1));\n      if (check(Monoid::op(val, x))) {\n  \
    \      val = Monoid::op(val, x);\n        u = (tree.parent[tree.V[b]]);\n    \
    \    continue;\n      }\n      auto check_tmp = [&](X x) -> bool { return check(Monoid::op(val,\
    \ x)); };\n      auto i = (Monoid::commute ? seg.min_left(check_tmp, a + 1)\n\
    \                                : seg_r.min_left(check_tmp, a + 1));\n      if\
    \ (i == a + 1) return u;\n      return tree.parent[tree.V[i]];\n    }\n    //\
    \ down\n    pd = tree.get_path_decomposition(lca, v, edge);\n    for (auto &&[a,\
    \ b]: pd) {\n      assert(a <= b);\n      X x = seg.prod(a, b + 1);\n      if\
    \ (check(Monoid::op(val, x))) {\n        val = Monoid::op(val, x);\n        u\
    \ = (tree.V[b]);\n        continue;\n      }\n      auto check_tmp = [&](X x)\
    \ -> bool { return check(Monoid::op(val, x)); };\n      auto i = seg.max_right(check_tmp,\
    \ a);\n      return (i == a ? u : tree.V[i - 1]);\n    }\n    return v;\n  }\n\
    };\n"
  dependsOn:
  - ds/disjointsparse/disjointsparse.hpp
  - graph/tree.hpp
  - graph/base.hpp
  - alg/monoid/monoid_reverse.hpp
  isVerificationFile: false
  path: graph/ds/static_tree_monoid.hpp
  requiredBy: []
  timestamp: '2023-01-09 23:26:05+09:00'
  verificationStatus: LIBRARY_ALL_WA
  verifiedWith:
  - test/yukicoder/1216.test.cpp
  - test/yukicoder/1216_2.test.cpp
documentation_of: graph/ds/static_tree_monoid.hpp
layout: document
redirect_from:
- /library/graph/ds/static_tree_monoid.hpp
- /library/graph/ds/static_tree_monoid.hpp.html
title: graph/ds/static_tree_monoid.hpp
---
