---
data:
  _extendedDependsOn:
  - icon: ':x:'
    path: ds/segtree/lazy_segtree.hpp
    title: ds/segtree/lazy_segtree.hpp
  - icon: ':question:'
    path: graph/base.hpp
    title: graph/base.hpp
  - icon: ':question:'
    path: graph/tree.hpp
    title: graph/tree.hpp
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':x:'
    path: test/aoj/GRL_5_E.test.cpp
    title: test/aoj/GRL_5_E.test.cpp
  - icon: ':x:'
    path: test/yukicoder/1197.test.cpp
    title: test/yukicoder/1197.test.cpp
  - icon: ':x:'
    path: test/yukicoder/1790.test.cpp
    title: test/yukicoder/1790.test.cpp
  - icon: ':x:'
    path: test/yukicoder/235.test.cpp
    title: test/yukicoder/235.test.cpp
  _isVerificationFailed: true
  _pathExtension: hpp
  _verificationStatusIcon: ':x:'
  attributes:
    links: []
  bundledCode: "#line 2 \"ds/segtree/lazy_segtree.hpp\"\n\ntemplate <typename ActedMonoid>\n\
    struct Lazy_SegTree {\n  using AM = ActedMonoid;\n  using MX = typename AM::Monoid_X;\n\
    \  using MA = typename AM::Monoid_A;\n  using X = typename MX::value_type;\n \
    \ using A = typename MA::value_type;\n  int n, log, size;\n  vc<X> dat;\n  vc<A>\
    \ laz;\n\n  Lazy_SegTree() {}\n  Lazy_SegTree(int n) { build(n); }\n  template\
    \ <typename F>\n  Lazy_SegTree(int n, F f) {\n    build(n, f);\n  }\n  Lazy_SegTree(const\
    \ vc<X>& v) { build(v); }\n\n  void build(int m) {\n    build(m, [](int i) ->\
    \ X { return MX::unit(); });\n  }\n  void build(const vc<X>& v) {\n    build(len(v),\
    \ [&](int i) -> X { return v[i]; });\n  }\n  template <typename F>\n  void build(int\
    \ m, F f) {\n    n = m, log = 1;\n    while ((1 << log) < n) ++log;\n    size\
    \ = 1 << log;\n    dat.assign(size << 1, MX::unit());\n    laz.assign(size, MA::unit());\n\
    \    FOR(i, n) dat[size + i] = f(i);\n    FOR_R(i, 1, size) update(i);\n  }\n\n\
    \  void update(int k) { dat[k] = MX::op(dat[2 * k], dat[2 * k + 1]); }\n  void\
    \ set(int p, X x) {\n    assert(0 <= p && p < n);\n    p += size;\n    for (int\
    \ i = log; i >= 1; i--) push(p >> i);\n    dat[p] = x;\n    for (int i = 1; i\
    \ <= log; i++) update(p >> i);\n  }\n\n  X get(int p) {\n    assert(0 <= p &&\
    \ p < n);\n    p += size;\n    for (int i = log; i >= 1; i--) push(p >> i);\n\
    \    return dat[p];\n  }\n\n  vc<X> get_all() {\n    FOR(k, 1, size) { push(k);\
    \ }\n    return {dat.begin() + size, dat.begin() + size + n};\n  }\n\n  X prod(int\
    \ l, int r) {\n    assert(0 <= l && l <= r && r <= n);\n    if (l == r) return\
    \ MX::unit();\n    l += size, r += size;\n    for (int i = log; i >= 1; i--) {\n\
    \      if (((l >> i) << i) != l) push(l >> i);\n      if (((r >> i) << i) != r)\
    \ push((r - 1) >> i);\n    }\n    X xl = MX::unit(), xr = MX::unit();\n    while\
    \ (l < r) {\n      if (l & 1) xl = MX::op(xl, dat[l++]);\n      if (r & 1) xr\
    \ = MX::op(dat[--r], xr);\n      l >>= 1, r >>= 1;\n    }\n    return MX::op(xl,\
    \ xr);\n  }\n\n  X prod_all() { return dat[1]; }\n\n  void apply(int l, int r,\
    \ A a) {\n    assert(0 <= l && l <= r && r <= n);\n    if (l == r) return;\n \
    \   l += size, r += size;\n    for (int i = log; i >= 1; i--) {\n      if (((l\
    \ >> i) << i) != l) push(l >> i);\n      if (((r >> i) << i) != r) push((r - 1)\
    \ >> i);\n    }\n    int l2 = l, r2 = r;\n    while (l < r) {\n      if (l & 1)\
    \ apply_at(l++, a);\n      if (r & 1) apply_at(--r, a);\n      l >>= 1, r >>=\
    \ 1;\n    }\n    l = l2, r = r2;\n    for (int i = 1; i <= log; i++) {\n     \
    \ if (((l >> i) << i) != l) update(l >> i);\n      if (((r >> i) << i) != r) update((r\
    \ - 1) >> i);\n    }\n  }\n\n  template <typename F>\n  int max_right(const F\
    \ check, int l) {\n    assert(0 <= l && l <= n);\n    assert(check(MX::unit()));\n\
    \    if (l == n) return n;\n    l += size;\n    for (int i = log; i >= 1; i--)\
    \ push(l >> i);\n    X sm = MX::unit();\n    do {\n      while (l % 2 == 0) l\
    \ >>= 1;\n      if (!check(MX::op(sm, dat[l]))) {\n        while (l < size) {\n\
    \          push(l);\n          l = (2 * l);\n          if (check(MX::op(sm, dat[l])))\
    \ { sm = MX::op(sm, dat[l++]); }\n        }\n        return l - size;\n      }\n\
    \      sm = MX::op(sm, dat[l++]);\n    } while ((l & -l) != l);\n    return n;\n\
    \  }\n\n  template <typename F>\n  int min_left(const F check, int r) {\n    assert(0\
    \ <= r && r <= n);\n    assert(check(MX::unit()));\n    if (r == 0) return 0;\n\
    \    r += size;\n    for (int i = log; i >= 1; i--) push((r - 1) >> i);\n    X\
    \ sm = MX::unit();\n    do {\n      r--;\n      while (r > 1 && (r % 2)) r >>=\
    \ 1;\n      if (!check(MX::op(dat[r], sm))) {\n        while (r < size) {\n  \
    \        push(r);\n          r = (2 * r + 1);\n          if (check(MX::op(dat[r],\
    \ sm))) { sm = MX::op(dat[r--], sm); }\n        }\n        return r + 1 - size;\n\
    \      }\n      sm = MX::op(dat[r], sm);\n    } while ((r & -r) != r);\n    return\
    \ 0;\n  }\n\nprivate:\n  void apply_at(int k, A a) {\n    ll sz = 1 << (log -\
    \ topbit(k));\n    dat[k] = AM::act(dat[k], a, sz);\n    if (k < size) laz[k]\
    \ = MA::op(laz[k], a);\n  }\n  void push(int k) {\n    if (laz[k] == MA::unit())\
    \ return;\n    apply_at(2 * k, laz[k]), apply_at(2 * k + 1, laz[k]);\n    laz[k]\
    \ = MA::unit();\n  }\n};\n#line 2 \"graph/base.hpp\"\n\ntemplate <typename T>\n\
    struct Edge {\n  int frm, to;\n  T cost;\n  int id;\n};\n\ntemplate <typename\
    \ T = int, bool directed = false>\nstruct Graph {\n  int N, M;\n  using cost_type\
    \ = T;\n  using edge_type = Edge<T>;\n  vector<edge_type> edges;\n  vector<int>\
    \ indptr;\n  vector<edge_type> csr_edges;\n  vc<int> vc_deg, vc_indeg, vc_outdeg;\n\
    \  bool prepared;\n\n  class OutgoingEdges {\n  public:\n    OutgoingEdges(const\
    \ Graph* G, int l, int r) : G(G), l(l), r(r) {}\n\n    const edge_type* begin()\
    \ const {\n      if (l == r) { return 0; }\n      return &G->csr_edges[l];\n \
    \   }\n\n    const edge_type* end() const {\n      if (l == r) { return 0; }\n\
    \      return &G->csr_edges[r];\n    }\n\n  private:\n    const Graph* G;\n  \
    \  int l, r;\n  };\n\n  bool is_prepared() { return prepared; }\n  constexpr bool\
    \ is_directed() { return directed; }\n\n  Graph() : N(0), M(0), prepared(0) {}\n\
    \  Graph(int N) : N(N), M(0), prepared(0) {}\n\n  void resize(int n) { N = n;\
    \ }\n\n  void add(int frm, int to, T cost = 1, int i = -1) {\n    assert(!prepared);\n\
    \    assert(0 <= frm && 0 <= to && to < N);\n    if (i == -1) i = M;\n    auto\
    \ e = edge_type({frm, to, cost, i});\n    edges.eb(e);\n    ++M;\n  }\n\n  //\
    \ wt, off\n  void read_tree(bool wt = false, int off = 1) { read_graph(N - 1,\
    \ wt, off); }\n\n  void read_graph(int M, bool wt = false, int off = 1) {\n  \
    \  for (int m = 0; m < M; ++m) {\n      INT(a, b);\n      a -= off, b -= off;\n\
    \      if (!wt) {\n        add(a, b);\n      } else {\n        T c;\n        read(c);\n\
    \        add(a, b, c);\n      }\n    }\n    build();\n  }\n\n  void read_parent(int\
    \ off = 1) {\n    for (int v = 1; v < N; ++v) {\n      INT(p);\n      p -= off;\n\
    \      add(p, v);\n    }\n    build();\n  }\n\n  void build() {\n    assert(!prepared);\n\
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
    \n  void debug() {\n    print(\"Graph\");\n    if (!prepared) {\n      print(\"\
    frm to cost id\");\n      for (auto&& e: edges) print(e.frm, e.to, e.cost, e.id);\n\
    \    } else {\n      print(\"indptr\", indptr);\n      print(\"frm to cost id\"\
    );\n      FOR(v, N) for (auto&& e: (*this)[v]) print(e.frm, e.to, e.cost, e.id);\n\
    \    }\n  }\n\nprivate:\n  void calc_deg() {\n    assert(vc_deg.empty());\n  \
    \  vc_deg.resize(N);\n    for (auto&& e: edges) vc_deg[e.frm]++, vc_deg[e.to]++;\n\
    \  }\n\n  void calc_deg_inout() {\n    assert(vc_indeg.empty());\n    vc_indeg.resize(N);\n\
    \    vc_outdeg.resize(N);\n    for (auto&& e: edges) { vc_indeg[e.to]++, vc_outdeg[e.frm]++;\
    \ }\n  }\n};\n#line 3 \"graph/tree.hpp\"\n\r\n// HLD euler tour \u3092\u3068\u3063\
    \u3066\u3044\u308D\u3044\u308D\u3002\r\n// \u6728\u4EE5\u5916\u3001\u975E\u9023\
    \u7D50\u3067\u3082 dfs \u9806\u5E8F\u3084\u89AA\u304C\u3068\u308C\u308B\u3002\r\
    \ntemplate <typename GT>\r\nstruct Tree {\r\n  using Graph_type = GT;\r\n  GT\
    \ &G;\r\n  using WT = typename GT::cost_type;\r\n  int N;\r\n  bool hld;\r\n \
    \ vector<int> LID, RID, head, V, parent;\r\n  vc<int> depth;\r\n  vc<WT> depth_weighted;\r\
    \n\r\n  Tree(GT &G, int r = -1, bool hld = 1)\r\n      : G(G),\r\n        N(G.N),\r\
    \n        hld(hld),\r\n        LID(G.N),\r\n        RID(G.N),\r\n        head(G.N,\
    \ r),\r\n        V(G.N),\r\n        parent(G.N, -1),\r\n        depth(G.N, -1),\r\
    \n        depth_weighted(G.N, 0) {\r\n    assert(G.is_prepared());\r\n    int\
    \ t1 = 0;\r\n    if (r != -1) {\r\n      dfs_sz(r, -1);\r\n      dfs_hld(r, t1);\r\
    \n    } else {\r\n      for (int r = 0; r < N; ++r) {\r\n        if (parent[r]\
    \ == -1) {\r\n          head[r] = r;\r\n          dfs_sz(r, -1);\r\n         \
    \ dfs_hld(r, t1);\r\n        }\r\n      }\r\n    }\r\n  }\r\n\r\n  void dfs_sz(int\
    \ v, int p) {\r\n    auto &sz = RID;\r\n    parent[v] = p;\r\n    depth[v] = (p\
    \ == -1 ? 0 : depth[p] + 1);\r\n    sz[v] = 1;\r\n    int l = G.indptr[v], r =\
    \ G.indptr[v + 1];\r\n    auto &csr = G.csr_edges;\r\n    // \u4F7F\u3046\u8FBA\
    \u304C\u3042\u308C\u3070\u5148\u982D\u306B\u3059\u308B\r\n    for (int i = r -\
    \ 2; i >= l; --i) {\r\n      if (hld && depth[csr[i + 1].to] == -1) swap(csr[i],\
    \ csr[i + 1]);\r\n    }\r\n    int hld_sz = 0;\r\n    for (int i = l; i < r; ++i)\
    \ {\r\n      auto e = csr[i];\r\n      if (depth[e.to] != -1) continue;\r\n  \
    \    depth_weighted[e.to] = depth_weighted[v] + e.cost;\r\n      dfs_sz(e.to,\
    \ v);\r\n      sz[v] += sz[e.to];\r\n      if (hld && chmax(hld_sz, sz[e.to])\
    \ && l < i) { swap(csr[l], csr[i]); }\r\n    }\r\n  }\r\n\r\n  void dfs_hld(int\
    \ v, int &times) {\r\n    LID[v] = times++;\r\n    RID[v] += LID[v];\r\n    V[LID[v]]\
    \ = v;\r\n    bool heavy = true;\r\n    for (auto &&e: G[v]) {\r\n      if (depth[e.to]\
    \ <= depth[v]) continue;\r\n      head[e.to] = (heavy ? head[v] : e.to);\r\n \
    \     heavy = false;\r\n      dfs_hld(e.to, times);\r\n    }\r\n  }\r\n\r\n  vc<int>\
    \ heavy_path_at(int v) {\r\n    vc<int> P = {v};\r\n    while (1) {\r\n      int\
    \ a = P.back();\r\n      for (auto &&e: G[a]) {\r\n        if (e.to != parent[a]\
    \ && head[e.to] == v) {\r\n          P.eb(e.to);\r\n          break;\r\n     \
    \   }\r\n      }\r\n      if (P.back() == a) break;\r\n    }\r\n    return P;\r\
    \n  }\r\n\r\n  int e_to_v(int eid) {\r\n    auto e = G.edges[eid];\r\n    return\
    \ (parent[e.frm] == e.to ? e.frm : e.to);\r\n  }\r\n\r\n  int ELID(int v) { return\
    \ 2 * LID[v] - depth[v]; }\r\n  int ERID(int v) { return 2 * RID[v] - depth[v]\
    \ - 1; }\r\n\r\n  /* k: 0-indexed */\r\n  int LA(int v, int k) {\r\n    assert(k\
    \ <= depth[v]);\r\n    while (1) {\r\n      int u = head[v];\r\n      if (LID[v]\
    \ - k >= LID[u]) return V[LID[v] - k];\r\n      k -= LID[v] - LID[u] + 1;\r\n\
    \      v = parent[u];\r\n    }\r\n  }\r\n\r\n  int LCA(int u, int v) {\r\n   \
    \ for (;; v = parent[head[v]]) {\r\n      if (LID[u] > LID[v]) swap(u, v);\r\n\
    \      if (head[u] == head[v]) return u;\r\n    }\r\n  }\r\n\r\n  int lca(int\
    \ u, int v) { return LCA(u, v); }\r\n  int la(int u, int v) { return LA(u, v);\
    \ }\r\n\r\n  int subtree_size(int v) { return RID[v] - LID[v]; }\r\n\r\n  int\
    \ dist(int a, int b) {\r\n    int c = LCA(a, b);\r\n    return depth[a] + depth[b]\
    \ - 2 * depth[c];\r\n  }\r\n\r\n  WT dist(int a, int b, bool weighted) {\r\n \
    \   assert(weighted);\r\n    int c = LCA(a, b);\r\n    return depth_weighted[a]\
    \ + depth_weighted[b] - WT(2) * depth_weighted[c];\r\n  }\r\n\r\n  // a is in\
    \ b\r\n  bool in_subtree(int a, int b) { return LID[b] <= LID[a] && LID[a] < RID[b];\
    \ }\r\n\r\n  int jump(int a, int b, ll k) {\r\n    if (k == 1) {\r\n      if (a\
    \ == b) return -1;\r\n      return (in_subtree(b, a) ? LA(b, depth[b] - depth[a]\
    \ - 1) : parent[a]);\r\n    }\r\n    int c = LCA(a, b);\r\n    int d_ac = depth[a]\
    \ - depth[c];\r\n    int d_bc = depth[b] - depth[c];\r\n    if (k > d_ac + d_bc)\
    \ return -1;\r\n    if (k <= d_ac) return LA(a, k);\r\n    return LA(b, d_ac +\
    \ d_bc - k);\r\n  }\r\n\r\n  vc<int> collect_child(int v) {\r\n    vc<int> res;\r\
    \n    for (auto &&e: G[v])\r\n      if (e.to != parent[v]) res.eb(e.to);\r\n \
    \   return res;\r\n  }\r\n\r\n  vc<pair<int, int>> get_path_decomposition(int\
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
    \n    return P;\r\n  }\r\n};\r\n#line 3 \"graph/ds/lazy_tree_monoid.hpp\"\n\r\n\
    template <typename TREE, typename ActedMonoid, bool edge = false>\r\nstruct Lazy_Tree_Monoid\
    \ {\r\n  using MonoX = typename ActedMonoid::Monoid_X;\r\n  using MonoA = typename\
    \ ActedMonoid::Monoid_A;\r\n  static_assert(MonoX::commute);\r\n  using X = typename\
    \ MonoX::value_type;\r\n  using A = typename MonoA::value_type;\r\n  TREE &tree;\r\
    \n  int N;\r\n  Lazy_SegTree<ActedMonoid> seg;\r\n\r\n  Lazy_Tree_Monoid(TREE\
    \ &tree) : tree(tree), N(tree.N), seg(tree.N) {}\r\n\r\n  Lazy_Tree_Monoid(TREE\
    \ &tree, vc<X> dat) : tree(tree), N(tree.N) {\r\n    vc<X> seg_raw(N, MonoX::unit());\r\
    \n    if (!edge) {\r\n      FOR(v, N) seg_raw[tree.LID[v]] = dat[v];\r\n    }\
    \ else {\r\n      FOR(e, N - 1) {\r\n        int v = tree.e_to_v(e);\r\n     \
    \   seg_raw[tree.LID[v]] = dat[e];\r\n      }\r\n    }\r\n    seg = Lazy_SegTree<ActedMonoid>(seg_raw);\r\
    \n  }\r\n\r\n  template <typename F>\r\n  Lazy_Tree_Monoid(TREE &tree, F f) :\
    \ tree(tree), N(tree.N) {\r\n    vc<X> seg_raw(N, MonoX::unit());\r\n    if (!edge)\
    \ {\r\n      FOR(v, N) seg_raw[tree.LID[v]] = f(v);\r\n    } else {\r\n      FOR(e,\
    \ N - 1) {\r\n        int v = tree.e_to_v(e);\r\n        seg_raw[tree.LID[v]]\
    \ = f(e);\r\n      }\r\n    }\r\n    seg = Lazy_SegTree<ActedMonoid>(seg_raw);\r\
    \n  }\r\n\r\n  void set(int i, X x) {\r\n    if (edge) i = tree.e_to_v(i);\r\n\
    \    i = tree.LID[i];\r\n    seg.set(i, x);\r\n  }\r\n\r\n  X get(int v) { return\
    \ seg.get(tree.LID[v]); }\r\n  vc<X> get_all() {\r\n    vc<X> dat = seg.get_all();\r\
    \n    vc<X> res(N);\r\n    FOR(v, N) res[v] = dat[tree.LID[v]];\r\n    return\
    \ res;\r\n  }\r\n\r\n  X prod_path(int u, int v) {\r\n    auto pd = tree.get_path_decomposition(u,\
    \ v, edge);\r\n    X val = MonoX::unit();\r\n    for (auto &&[a, b]: pd) {\r\n\
    \      X x = (a <= b ? seg.prod(a, b + 1) : seg.prod(b, a + 1));\r\n      val\
    \ = MonoX::op(val, x);\r\n    }\r\n    return val;\r\n  }\r\n\r\n  X prod_subtree(int\
    \ u) {\r\n    int l = tree.LID[u], r = tree.RID[u];\r\n    return seg.prod(l +\
    \ edge, r);\r\n  }\r\n\r\n  X prod_all() { return seg.prod_all(); }\r\n\r\n  void\
    \ apply_path(int u, int v, A a) {\r\n    auto pd = tree.get_path_decomposition(u,\
    \ v, edge);\r\n    for (auto &&[x, y]: pd) {\r\n      int l = min(x, y), r = max(x,\
    \ y);\r\n      seg.apply(l, r + 1, a);\r\n    }\r\n  }\r\n\r\n  void apply_subtree(int\
    \ u, A a) {\r\n    int l = tree.LID[u], r = tree.RID[u];\r\n    return seg.apply(l\
    \ + edge, r, a);\r\n  }\r\n\r\n  template <class F>\r\n  int max_path(F &check,\
    \ int u, int v) {\r\n    if (edge) return max_path_edge(check, u, v);\r\n    if\
    \ (!check(prod_path(u, u))) return -1;\r\n    auto pd = tree.get_path_decomposition(u,\
    \ v, edge);\r\n    X val = MonoX::unit();\r\n    for (auto &&[a, b]: pd) {\r\n\
    \      X x = (a <= b ? seg.prod(a, b + 1) : seg.prod(b, a + 1));\r\n      if (check(MonoX::op(val,\
    \ x))) {\r\n        val = MonoX::op(val, x);\r\n        u = (tree.V[b]);\r\n \
    \       continue;\r\n      }\r\n      auto check_tmp = [&](X x) -> bool { return\
    \ check(MonoX::op(val, x)); };\r\n      if (a <= b) {\r\n        // \u4E0B\u308A\
    \r\n        auto i = seg.max_right(check_tmp, a);\r\n        return (i == a ?\
    \ u : tree.V[i - 1]);\r\n      } else {\r\n        // \u4E0A\u308A\r\n       \
    \ auto i = seg.min_left(check_tmp, a + 1);\r\n        if (i == a + 1) return u;\r\
    \n        return tree.V[i];\r\n      }\r\n    }\r\n    return v;\r\n  }\r\n\r\n\
    private:\r\n  template <class F>\r\n  int max_path_edge(F &check, int u, int v)\
    \ {\r\n    assert(edge);\r\n    if (!check(MonoX::unit())) return -1;\r\n    int\
    \ lca = tree.lca(u, v);\r\n    auto pd = tree.get_path_decomposition(u, lca, edge);\r\
    \n    X val = MonoX::unit();\r\n\r\n    // climb\r\n    for (auto &&[a, b]: pd)\
    \ {\r\n      assert(a >= b);\r\n      X x = seg.prod(b, a + 1);\r\n      if (check(MonoX::op(val,\
    \ x))) {\r\n        val = MonoX::op(val, x);\r\n        u = (tree.parent[tree.V[b]]);\r\
    \n        continue;\r\n      }\r\n      auto check_tmp = [&](X x) -> bool { return\
    \ check(MonoX::op(val, x)); };\r\n      auto i = seg.min_left(check_tmp, a + 1);\r\
    \n      if (i == a + 1) return u;\r\n      return tree.parent[tree.V[i]];\r\n\
    \    }\r\n    // down\r\n    pd = tree.get_path_decomposition(lca, v, edge);\r\
    \n    for (auto &&[a, b]: pd) {\r\n      assert(a <= b);\r\n      X x = seg.prod(a,\
    \ b + 1);\r\n      if (check(MonoX::op(val, x))) {\r\n        val = MonoX::op(val,\
    \ x);\r\n        u = (tree.V[b]);\r\n        continue;\r\n      }\r\n      auto\
    \ check_tmp = [&](X x) -> bool { return check(MonoX::op(val, x)); };\r\n     \
    \ auto i = seg.max_right(check_tmp, a);\r\n      return (i == a ? u : tree.V[i\
    \ - 1]);\r\n    }\r\n    return v;\r\n  }\r\n};\r\n"
  code: "#include \"ds/segtree/lazy_segtree.hpp\"\r\n#include \"graph/tree.hpp\"\r\
    \n\r\ntemplate <typename TREE, typename ActedMonoid, bool edge = false>\r\nstruct\
    \ Lazy_Tree_Monoid {\r\n  using MonoX = typename ActedMonoid::Monoid_X;\r\n  using\
    \ MonoA = typename ActedMonoid::Monoid_A;\r\n  static_assert(MonoX::commute);\r\
    \n  using X = typename MonoX::value_type;\r\n  using A = typename MonoA::value_type;\r\
    \n  TREE &tree;\r\n  int N;\r\n  Lazy_SegTree<ActedMonoid> seg;\r\n\r\n  Lazy_Tree_Monoid(TREE\
    \ &tree) : tree(tree), N(tree.N), seg(tree.N) {}\r\n\r\n  Lazy_Tree_Monoid(TREE\
    \ &tree, vc<X> dat) : tree(tree), N(tree.N) {\r\n    vc<X> seg_raw(N, MonoX::unit());\r\
    \n    if (!edge) {\r\n      FOR(v, N) seg_raw[tree.LID[v]] = dat[v];\r\n    }\
    \ else {\r\n      FOR(e, N - 1) {\r\n        int v = tree.e_to_v(e);\r\n     \
    \   seg_raw[tree.LID[v]] = dat[e];\r\n      }\r\n    }\r\n    seg = Lazy_SegTree<ActedMonoid>(seg_raw);\r\
    \n  }\r\n\r\n  template <typename F>\r\n  Lazy_Tree_Monoid(TREE &tree, F f) :\
    \ tree(tree), N(tree.N) {\r\n    vc<X> seg_raw(N, MonoX::unit());\r\n    if (!edge)\
    \ {\r\n      FOR(v, N) seg_raw[tree.LID[v]] = f(v);\r\n    } else {\r\n      FOR(e,\
    \ N - 1) {\r\n        int v = tree.e_to_v(e);\r\n        seg_raw[tree.LID[v]]\
    \ = f(e);\r\n      }\r\n    }\r\n    seg = Lazy_SegTree<ActedMonoid>(seg_raw);\r\
    \n  }\r\n\r\n  void set(int i, X x) {\r\n    if (edge) i = tree.e_to_v(i);\r\n\
    \    i = tree.LID[i];\r\n    seg.set(i, x);\r\n  }\r\n\r\n  X get(int v) { return\
    \ seg.get(tree.LID[v]); }\r\n  vc<X> get_all() {\r\n    vc<X> dat = seg.get_all();\r\
    \n    vc<X> res(N);\r\n    FOR(v, N) res[v] = dat[tree.LID[v]];\r\n    return\
    \ res;\r\n  }\r\n\r\n  X prod_path(int u, int v) {\r\n    auto pd = tree.get_path_decomposition(u,\
    \ v, edge);\r\n    X val = MonoX::unit();\r\n    for (auto &&[a, b]: pd) {\r\n\
    \      X x = (a <= b ? seg.prod(a, b + 1) : seg.prod(b, a + 1));\r\n      val\
    \ = MonoX::op(val, x);\r\n    }\r\n    return val;\r\n  }\r\n\r\n  X prod_subtree(int\
    \ u) {\r\n    int l = tree.LID[u], r = tree.RID[u];\r\n    return seg.prod(l +\
    \ edge, r);\r\n  }\r\n\r\n  X prod_all() { return seg.prod_all(); }\r\n\r\n  void\
    \ apply_path(int u, int v, A a) {\r\n    auto pd = tree.get_path_decomposition(u,\
    \ v, edge);\r\n    for (auto &&[x, y]: pd) {\r\n      int l = min(x, y), r = max(x,\
    \ y);\r\n      seg.apply(l, r + 1, a);\r\n    }\r\n  }\r\n\r\n  void apply_subtree(int\
    \ u, A a) {\r\n    int l = tree.LID[u], r = tree.RID[u];\r\n    return seg.apply(l\
    \ + edge, r, a);\r\n  }\r\n\r\n  template <class F>\r\n  int max_path(F &check,\
    \ int u, int v) {\r\n    if (edge) return max_path_edge(check, u, v);\r\n    if\
    \ (!check(prod_path(u, u))) return -1;\r\n    auto pd = tree.get_path_decomposition(u,\
    \ v, edge);\r\n    X val = MonoX::unit();\r\n    for (auto &&[a, b]: pd) {\r\n\
    \      X x = (a <= b ? seg.prod(a, b + 1) : seg.prod(b, a + 1));\r\n      if (check(MonoX::op(val,\
    \ x))) {\r\n        val = MonoX::op(val, x);\r\n        u = (tree.V[b]);\r\n \
    \       continue;\r\n      }\r\n      auto check_tmp = [&](X x) -> bool { return\
    \ check(MonoX::op(val, x)); };\r\n      if (a <= b) {\r\n        // \u4E0B\u308A\
    \r\n        auto i = seg.max_right(check_tmp, a);\r\n        return (i == a ?\
    \ u : tree.V[i - 1]);\r\n      } else {\r\n        // \u4E0A\u308A\r\n       \
    \ auto i = seg.min_left(check_tmp, a + 1);\r\n        if (i == a + 1) return u;\r\
    \n        return tree.V[i];\r\n      }\r\n    }\r\n    return v;\r\n  }\r\n\r\n\
    private:\r\n  template <class F>\r\n  int max_path_edge(F &check, int u, int v)\
    \ {\r\n    assert(edge);\r\n    if (!check(MonoX::unit())) return -1;\r\n    int\
    \ lca = tree.lca(u, v);\r\n    auto pd = tree.get_path_decomposition(u, lca, edge);\r\
    \n    X val = MonoX::unit();\r\n\r\n    // climb\r\n    for (auto &&[a, b]: pd)\
    \ {\r\n      assert(a >= b);\r\n      X x = seg.prod(b, a + 1);\r\n      if (check(MonoX::op(val,\
    \ x))) {\r\n        val = MonoX::op(val, x);\r\n        u = (tree.parent[tree.V[b]]);\r\
    \n        continue;\r\n      }\r\n      auto check_tmp = [&](X x) -> bool { return\
    \ check(MonoX::op(val, x)); };\r\n      auto i = seg.min_left(check_tmp, a + 1);\r\
    \n      if (i == a + 1) return u;\r\n      return tree.parent[tree.V[i]];\r\n\
    \    }\r\n    // down\r\n    pd = tree.get_path_decomposition(lca, v, edge);\r\
    \n    for (auto &&[a, b]: pd) {\r\n      assert(a <= b);\r\n      X x = seg.prod(a,\
    \ b + 1);\r\n      if (check(MonoX::op(val, x))) {\r\n        val = MonoX::op(val,\
    \ x);\r\n        u = (tree.V[b]);\r\n        continue;\r\n      }\r\n      auto\
    \ check_tmp = [&](X x) -> bool { return check(MonoX::op(val, x)); };\r\n     \
    \ auto i = seg.max_right(check_tmp, a);\r\n      return (i == a ? u : tree.V[i\
    \ - 1]);\r\n    }\r\n    return v;\r\n  }\r\n};\r\n"
  dependsOn:
  - ds/segtree/lazy_segtree.hpp
  - graph/tree.hpp
  - graph/base.hpp
  isVerificationFile: false
  path: graph/ds/lazy_tree_monoid.hpp
  requiredBy: []
  timestamp: '2023-01-31 23:11:49+09:00'
  verificationStatus: LIBRARY_ALL_WA
  verifiedWith:
  - test/yukicoder/1197.test.cpp
  - test/yukicoder/235.test.cpp
  - test/yukicoder/1790.test.cpp
  - test/aoj/GRL_5_E.test.cpp
documentation_of: graph/ds/lazy_tree_monoid.hpp
layout: document
redirect_from:
- /library/graph/ds/lazy_tree_monoid.hpp
- /library/graph/ds/lazy_tree_monoid.hpp.html
title: graph/ds/lazy_tree_monoid.hpp
---
