---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: alg/monoid/max.hpp
    title: alg/monoid/max.hpp
  - icon: ':heavy_check_mark:'
    path: alg/monoid/min.hpp
    title: alg/monoid/min.hpp
  - icon: ':heavy_check_mark:'
    path: alg/monoid/monoid_reverse.hpp
    title: alg/monoid/monoid_reverse.hpp
  - icon: ':heavy_check_mark:'
    path: ds/segtree/dual_segtree.hpp
    title: ds/segtree/dual_segtree.hpp
  - icon: ':heavy_check_mark:'
    path: ds/segtree/segtree.hpp
    title: ds/segtree/segtree.hpp
  - icon: ':heavy_check_mark:'
    path: ds/unionfind/unionfind.hpp
    title: ds/unionfind/unionfind.hpp
  - icon: ':question:'
    path: graph/base.hpp
    title: graph/base.hpp
  - icon: ':heavy_check_mark:'
    path: graph/ds/dual_tree_monoid.hpp
    title: graph/ds/dual_tree_monoid.hpp
  - icon: ':heavy_check_mark:'
    path: graph/ds/tree_monoid.hpp
    title: graph/ds/tree_monoid.hpp
  - icon: ':heavy_check_mark:'
    path: graph/tree.hpp
    title: graph/tree.hpp
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/aoj/GRL_2_A.test.cpp
    title: test/aoj/GRL_2_A.test.cpp
  - icon: ':heavy_check_mark:'
    path: test_atcoder/abc270_f.test.cpp
    title: test_atcoder/abc270_f.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links:
    - https://codeforces.com/contest/828/problem/F
  bundledCode: "#line 2 \"ds/unionfind/unionfind.hpp\"\n\nstruct UnionFind {\n  int\
    \ n, n_comp;\n  vc<int> dat; // par or (-size)\n  UnionFind(int n = 0) { build(n);\
    \ }\n\n  void build(int m) {\n    n = m, n_comp = m;\n    dat.assign(n, -1);\n\
    \  }\n\n  void reset() { build(n); }\n\n  int operator[](int x) {\n    while (dat[x]\
    \ >= 0) {\n      int pp = dat[dat[x]];\n      if (pp < 0) { return dat[x]; }\n\
    \      x = dat[x] = pp;\n    }\n    return x;\n  }\n\n  ll size(int x) {\n   \
    \ assert(dat[x] < 0);\n    return -dat[x];\n  }\n\n  bool merge(int x, int y)\
    \ {\n    x = (*this)[x], y = (*this)[y];\n    if (x == y) return false;\n    if\
    \ (-dat[x] < -dat[y]) swap(x, y);\n    dat[x] += dat[y], dat[y] = x, n_comp--;\n\
    \    return true;\n  }\n};\n#line 2 \"graph/base.hpp\"\n\ntemplate <typename T>\n\
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
    \  Graph(int N) : N(N), M(0), prepared(0) {}\n\n  void build(int n) {\n    N =\
    \ n, M = 0;\n    prepared = 0;\n    edges.clear();\n    indptr.clear();\n    csr_edges.clear();\n\
    \    vc_deg.clear();\n    vc_indeg.clear();\n    vc_outdeg.clear();\n  }\n\n \
    \ void add(int frm, int to, T cost = 1, int i = -1) {\n    assert(!prepared);\n\
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
    \    }\n  }\n\n  // G \u306B\u304A\u3051\u308B\u9802\u70B9 V[i] \u304C\u3001\u65B0\
    \u3057\u3044\u30B0\u30E9\u30D5\u3067 i \u306B\u306A\u308B\u3088\u3046\u306B\u3059\
    \u308B\n  Graph<T, directed> rearrange(vc<int> V) {\n    int n = len(V);\n   \
    \ map<int, int> MP;\n    FOR(i, n) MP[V[i]] = i;\n    Graph<T, directed> G(n);\n\
    \    for (auto&& e: edges) {\n      if (MP.count(e.frm) && MP.count(e.to)) {\n\
    \        G.add(MP[e.frm], MP[e.to], e.cost);\n      }\n    }\n    G.build();\n\
    \    return G;\n  }\n\nprivate:\n  void calc_deg() {\n    assert(vc_deg.empty());\n\
    \    vc_deg.resize(N);\n    for (auto&& e: edges) vc_deg[e.frm]++, vc_deg[e.to]++;\n\
    \  }\n\n  void calc_deg_inout() {\n    assert(vc_indeg.empty());\n    vc_indeg.resize(N);\n\
    \    vc_outdeg.resize(N);\n    for (auto&& e: edges) { vc_indeg[e.to]++, vc_outdeg[e.frm]++;\
    \ }\n  }\n};\n#line 2 \"graph/tree.hpp\"\n\r\n#line 4 \"graph/tree.hpp\"\n\r\n\
    // HLD euler tour \u3092\u3068\u3063\u3066\u3044\u308D\u3044\u308D\u3002\r\n//\
    \ \u6728\u4EE5\u5916\u3001\u975E\u9023\u7D50\u3067\u3082 dfs \u9806\u5E8F\u3084\
    \u89AA\u304C\u3068\u308C\u308B\u3002\r\ntemplate <typename GT>\r\nstruct Tree\
    \ {\r\n  using Graph_type = GT;\r\n  GT *G_ptr;\r\n  using WT = typename GT::cost_type;\r\
    \n  int N;\r\n  vector<int> LID, RID, head, V, parent, VtoE;\r\n  vc<int> depth;\r\
    \n  vc<WT> depth_weighted;\r\n\r\n  Tree() {}\r\n  Tree(GT &G, int r = 0, bool\
    \ hld = 1) { build(G, r, hld); }\r\n\r\n  void build(GT &G, int r = 0, bool hld\
    \ = 1) {\r\n    G_ptr = &G;\r\n    N = G.N;\r\n    LID.assign(N, -1), RID.assign(N,\
    \ -1), head.assign(N, r);\r\n    V.assign(N, -1), parent.assign(N, -1), VtoE.assign(N,\
    \ -1);\r\n    depth.assign(N, -1), depth_weighted.assign(N, 0);\r\n    assert(G.is_prepared());\r\
    \n    int t1 = 0;\r\n    dfs_sz(r, -1, hld);\r\n    dfs_hld(r, t1);\r\n  }\r\n\
    \r\n  void dfs_sz(int v, int p, bool hld) {\r\n    auto &sz = RID;\r\n    parent[v]\
    \ = p;\r\n    depth[v] = (p == -1 ? 0 : depth[p] + 1);\r\n    sz[v] = 1;\r\n \
    \   int l = G_ptr->indptr[v], r = G_ptr->indptr[v + 1];\r\n    auto &csr = G_ptr->csr_edges;\r\
    \n    // \u4F7F\u3046\u8FBA\u304C\u3042\u308C\u3070\u5148\u982D\u306B\u3059\u308B\
    \r\n    for (int i = r - 2; i >= l; --i) {\r\n      if (hld && depth[csr[i + 1].to]\
    \ == -1) swap(csr[i], csr[i + 1]);\r\n    }\r\n    int hld_sz = 0;\r\n    for\
    \ (int i = l; i < r; ++i) {\r\n      auto e = csr[i];\r\n      if (depth[e.to]\
    \ != -1) continue;\r\n      depth_weighted[e.to] = depth_weighted[v] + e.cost;\r\
    \n      VtoE[e.to] = e.id;\r\n      dfs_sz(e.to, v, hld);\r\n      sz[v] += sz[e.to];\r\
    \n      if (hld && chmax(hld_sz, sz[e.to]) && l < i) { swap(csr[l], csr[i]); }\r\
    \n    }\r\n  }\r\n\r\n  void dfs_hld(int v, int &times) {\r\n    LID[v] = times++;\r\
    \n    RID[v] += LID[v];\r\n    V[LID[v]] = v;\r\n    bool heavy = true;\r\n  \
    \  for (auto &&e: (*G_ptr)[v]) {\r\n      if (depth[e.to] <= depth[v]) continue;\r\
    \n      head[e.to] = (heavy ? head[v] : e.to);\r\n      heavy = false;\r\n   \
    \   dfs_hld(e.to, times);\r\n    }\r\n  }\r\n\r\n  vc<int> heavy_path_at(int v)\
    \ {\r\n    vc<int> P = {v};\r\n    while (1) {\r\n      int a = P.back();\r\n\
    \      for (auto &&e: (*G_ptr)[a]) {\r\n        if (e.to != parent[a] && head[e.to]\
    \ == v) {\r\n          P.eb(e.to);\r\n          break;\r\n        }\r\n      }\r\
    \n      if (P.back() == a) break;\r\n    }\r\n    return P;\r\n  }\r\n\r\n  int\
    \ e_to_v(int eid) {\r\n    auto e = (*G_ptr).edges[eid];\r\n    return (parent[e.frm]\
    \ == e.to ? e.frm : e.to);\r\n  }\r\n  int v_to_e(int v) { return VtoE[v]; }\r\
    \n\r\n  int ELID(int v) { return 2 * LID[v] - depth[v]; }\r\n  int ERID(int v)\
    \ { return 2 * RID[v] - depth[v] - 1; }\r\n\r\n  /* k: 0-indexed */\r\n  int LA(int\
    \ v, int k) {\r\n    assert(k <= depth[v]);\r\n    while (1) {\r\n      int u\
    \ = head[v];\r\n      if (LID[v] - k >= LID[u]) return V[LID[v] - k];\r\n    \
    \  k -= LID[v] - LID[u] + 1;\r\n      v = parent[u];\r\n    }\r\n  }\r\n\r\n \
    \ int LCA(int u, int v) {\r\n    for (;; v = parent[head[v]]) {\r\n      if (LID[u]\
    \ > LID[v]) swap(u, v);\r\n      if (head[u] == head[v]) return u;\r\n    }\r\n\
    \  }\r\n\r\n  int lca(int u, int v) { return LCA(u, v); }\r\n  int la(int u, int\
    \ v) { return LA(u, v); }\r\n\r\n  int subtree_size(int v, int root = -1) {\r\n\
    \    if (root == -1) return RID[v] - LID[v];\r\n    if (v == root) return N;\r\
    \n    int x = jump(v, root, 1);\r\n    if (in_subtree(v, x)) return RID[v] - LID[v];\r\
    \n    return N - RID[x] + LID[x];\r\n  }\r\n\r\n  int dist(int a, int b) {\r\n\
    \    int c = LCA(a, b);\r\n    return depth[a] + depth[b] - 2 * depth[c];\r\n\
    \  }\r\n\r\n  WT dist(int a, int b, bool weighted) {\r\n    assert(weighted);\r\
    \n    int c = LCA(a, b);\r\n    return depth_weighted[a] + depth_weighted[b] -\
    \ WT(2) * depth_weighted[c];\r\n  }\r\n\r\n  // a is in b\r\n  bool in_subtree(int\
    \ a, int b) { return LID[b] <= LID[a] && LID[a] < RID[b]; }\r\n\r\n  int jump(int\
    \ a, int b, ll k) {\r\n    if (k == 1) {\r\n      if (a == b) return -1;\r\n \
    \     return (in_subtree(b, a) ? LA(b, depth[b] - depth[a] - 1) : parent[a]);\r\
    \n    }\r\n    int c = LCA(a, b);\r\n    int d_ac = depth[a] - depth[c];\r\n \
    \   int d_bc = depth[b] - depth[c];\r\n    if (k > d_ac + d_bc) return -1;\r\n\
    \    if (k <= d_ac) return LA(a, k);\r\n    return LA(b, d_ac + d_bc - k);\r\n\
    \  }\r\n\r\n  vc<int> collect_child(int v) {\r\n    vc<int> res;\r\n    for (auto\
    \ &&e: (*G_ptr)[v])\r\n      if (e.to != parent[v]) res.eb(e.to);\r\n    return\
    \ res;\r\n  }\r\n\r\n  vc<pair<int, int>> get_path_decomposition(int u, int v,\
    \ bool edge) {\r\n    // [\u59CB\u70B9, \u7D42\u70B9] \u306E\"\u9589\"\u533A\u9593\
    \u5217\u3002\r\n    vc<pair<int, int>> up, down;\r\n    while (1) {\r\n      if\
    \ (head[u] == head[v]) break;\r\n      if (LID[u] < LID[v]) {\r\n        down.eb(LID[head[v]],\
    \ LID[v]);\r\n        v = parent[head[v]];\r\n      } else {\r\n        up.eb(LID[u],\
    \ LID[head[u]]);\r\n        u = parent[head[u]];\r\n      }\r\n    }\r\n    if\
    \ (LID[u] < LID[v]) down.eb(LID[u] + edge, LID[v]);\r\n    elif (LID[v] + edge\
    \ <= LID[u]) up.eb(LID[u], LID[v] + edge);\r\n    reverse(all(down));\r\n    up.insert(up.end(),\
    \ all(down));\r\n    return up;\r\n  }\r\n\r\n  vc<int> restore_path(int u, int\
    \ v) {\r\n    vc<int> P;\r\n    for (auto &&[a, b]: get_path_decomposition(u,\
    \ v, 0)) {\r\n      if (a <= b) {\r\n        FOR(i, a, b + 1) P.eb(V[i]);\r\n\
    \      } else {\r\n        FOR_R(i, b, a + 1) P.eb(V[i]);\r\n      }\r\n    }\r\
    \n    return P;\r\n  }\r\n};\r\n#line 2 \"graph/ds/tree_monoid.hpp\"\n\r\n#line\
    \ 2 \"ds/segtree/segtree.hpp\"\n\ntemplate <class Monoid>\nstruct SegTree {\n\
    \  using MX = Monoid;\n  using X = typename MX::value_type;\n  using value_type\
    \ = X;\n  vc<X> dat;\n  int n, log, size;\n\n  SegTree() {}\n  SegTree(int n)\
    \ { build(n); }\n  template <typename F>\n  SegTree(int n, F f) {\n    build(n,\
    \ f);\n  }\n  SegTree(const vc<X>& v) { build(v); }\n\n  void build(int m) {\n\
    \    build(m, [](int i) -> X { return MX::unit(); });\n  }\n  void build(const\
    \ vc<X>& v) {\n    build(len(v), [&](int i) -> X { return v[i]; });\n  }\n  template\
    \ <typename F>\n  void build(int m, F f) {\n    n = m, log = 1;\n    while ((1\
    \ << log) < n) ++log;\n    size = 1 << log;\n    dat.assign(size << 1, MX::unit());\n\
    \    FOR(i, n) dat[size + i] = f(i);\n    FOR_R(i, 1, size) update(i);\n  }\n\n\
    \  X get(int i) { return dat[size + i]; }\n  vc<X> get_all() { return {dat.begin()\
    \ + size, dat.begin() + size + n}; }\n\n  void update(int i) { dat[i] = Monoid::op(dat[2\
    \ * i], dat[2 * i + 1]); }\n  void set(int i, const X& x) {\n    assert(i < n);\n\
    \    dat[i += size] = x;\n    while (i >>= 1) update(i);\n  }\n\n  void multiply(int\
    \ i, const X& x) {\n    assert(i < n);\n    i += size;\n    dat[i] = Monoid::op(dat[i],\
    \ x);\n    while (i >>= 1) update(i);\n  }\n\n  X prod(int L, int R) {\n    assert(0\
    \ <= L && L <= R && R <= n);\n    X vl = Monoid::unit(), vr = Monoid::unit();\n\
    \    L += size, R += size;\n    while (L < R) {\n      if (L & 1) vl = Monoid::op(vl,\
    \ dat[L++]);\n      if (R & 1) vr = Monoid::op(dat[--R], vr);\n      L >>= 1,\
    \ R >>= 1;\n    }\n    return Monoid::op(vl, vr);\n  }\n\n  X prod_all() { return\
    \ dat[1]; }\n\n  template <class F>\n  int max_right(F check, int L) {\n    assert(0\
    \ <= L && L <= n && check(Monoid::unit()));\n    if (L == n) return n;\n    L\
    \ += size;\n    X sm = Monoid::unit();\n    do {\n      while (L % 2 == 0) L >>=\
    \ 1;\n      if (!check(Monoid::op(sm, dat[L]))) {\n        while (L < size) {\n\
    \          L = 2 * L;\n          if (check(Monoid::op(sm, dat[L]))) { sm = Monoid::op(sm,\
    \ dat[L++]); }\n        }\n        return L - size;\n      }\n      sm = Monoid::op(sm,\
    \ dat[L++]);\n    } while ((L & -L) != L);\n    return n;\n  }\n\n  template <class\
    \ F>\n  int min_left(F check, int R) {\n    assert(0 <= R && R <= n && check(Monoid::unit()));\n\
    \    if (R == 0) return 0;\n    R += size;\n    X sm = Monoid::unit();\n    do\
    \ {\n      --R;\n      while (R > 1 && (R % 2)) R >>= 1;\n      if (!check(Monoid::op(dat[R],\
    \ sm))) {\n        while (R < size) {\n          R = 2 * R + 1;\n          if\
    \ (check(Monoid::op(dat[R], sm))) { sm = Monoid::op(dat[R--], sm); }\n       \
    \ }\n        return R + 1 - size;\n      }\n      sm = Monoid::op(dat[R], sm);\n\
    \    } while ((R & -R) != R);\n    return 0;\n  }\n\n  // \u30E2\u30CE\u30A4\u30C9\
    \u304C\u53EF\u63DB\u306A\u3089\u3001prod_{l<=i<r} A[i xor x] \u304C\u8A08\u7B97\
    \u53EF\u80FD\n  X xor_prod(int l, int r, int xor_val) {\n    static_assert(Monoid::commute);\n\
    \    X x = Monoid::unit();\n    for (int k = 0; k < log + 1; ++k) {\n      if\
    \ (l >= r) break;\n      if (l & 1) { x = Monoid::op(x, dat[(size >> k) + ((l++)\
    \ ^ xor_val)]); }\n      if (r & 1) { x = Monoid::op(x, dat[(size >> k) + ((--r)\
    \ ^ xor_val)]); }\n      l /= 2, r /= 2, xor_val /= 2;\n    }\n    return x;\n\
    \  }\n};\n#line 2 \"alg/monoid/monoid_reverse.hpp\"\n\r\ntemplate <class Monoid>\r\
    \nstruct Monoid_Reverse {\r\n  using value_type = typename Monoid::value_type;\r\
    \n  using X = value_type;\r\n  static constexpr X op(const X &x, const X &y) {\
    \ return Monoid::op(y, x); }\r\n  static constexpr X unit() { return Monoid::unit();\
    \ }\r\n  static const bool commute = Monoid::commute;\r\n};\r\n#line 6 \"graph/ds/tree_monoid.hpp\"\
    \n\r\ntemplate <typename TREE, typename Monoid, bool edge>\r\nstruct Tree_Monoid\
    \ {\r\n  using RevMonoid = Monoid_Reverse<Monoid>;\r\n  using X = typename Monoid::value_type;\r\
    \n  TREE &tree;\r\n  int N;\r\n  SegTree<Monoid> seg;\r\n  SegTree<RevMonoid>\
    \ seg_r;\r\n\r\n  Tree_Monoid(TREE &tree) : tree(tree), N(tree.N) {\r\n    build([](int\
    \ i) -> X { return Monoid::unit(); });\r\n  }\r\n\r\n  Tree_Monoid(TREE &tree,\
    \ vc<X> &dat) : tree(tree), N(tree.N) {\r\n    build([&](int i) -> X { return\
    \ dat[i]; });\r\n  }\r\n\r\n  template <typename F>\r\n  Tree_Monoid(TREE &tree,\
    \ F f) : tree(tree), N(tree.N) {\r\n    build(f);\r\n  }\r\n\r\n  template <typename\
    \ F>\r\n  void build(F f) {\r\n    vc<X> seg_raw(N, Monoid::unit());\r\n    if\
    \ (!edge) {\r\n      seg.build(N, [&](int i) -> X { return f(tree.V[i]); });\r\
    \n      if (!Monoid::commute) {\r\n        seg_r.build(N, [&](int i) -> X { return\
    \ f(tree.V[i]); });\r\n      }\r\n    } else {\r\n      seg.build(N, [&](int i)\
    \ -> X {\r\n        return (i == 0 ? Monoid::unit() : f(tree.v_to_e(tree.V[i])));\r\
    \n      });\r\n      if (!Monoid::commute) {\r\n        seg_r.build(N, [&](int\
    \ i) -> X {\r\n          return (i == 0 ? Monoid::unit() : f(tree.v_to_e(tree.V[i])));\r\
    \n        });\r\n      }\r\n    }\r\n  }\r\n\r\n  void set(int i, X x) {\r\n \
    \   if (edge) i = tree.e_to_v(i);\r\n    i = tree.LID[i];\r\n    seg.set(i, x);\r\
    \n    if (!Monoid::commute) seg_r.set(i, x);\r\n  }\r\n\r\n  void multiply(int\
    \ i, X x) {\r\n    if (edge) i = tree.e_to_v(i);\r\n    i = tree.LID[i];\r\n \
    \   seg.multiply(i, x);\r\n    if (!Monoid::commute) seg_r.multiply(i, x);\r\n\
    \  }\r\n\r\n  X prod_path(int u, int v) {\r\n    auto pd = tree.get_path_decomposition(u,\
    \ v, edge);\r\n    X val = Monoid::unit();\r\n    for (auto &&[a, b]: pd) {\r\n\
    \      X x = (a <= b ? seg.prod(a, b + 1)\r\n                    : (Monoid::commute\
    \ ? seg.prod(b, a + 1)\r\n                                       : seg_r.prod(b,\
    \ a + 1)));\r\n      val = Monoid::op(val, x);\r\n    }\r\n    return val;\r\n\
    \  }\r\n\r\n  // uv path \u4E0A\u3067 prod_path(u, x) \u304C check \u3092\u6E80\
    \u305F\u3059\u6700\u5F8C\u306E x\r\n  // \u306A\u3051\u308C\u3070 -1\r\n  // https://codeforces.com/contest/1059/problem/E\r\
    \n  // https://codeforces.com/contest/1230/problem/E\r\n  // edge: https://atcoder.jp/contests/tkppc3/tasks/tkppc3_i\r\
    \n  // edge \u304C\u7279\u306B\u602A\u3057\u3044\u304B\u3082\r\n  template <class\
    \ F>\r\n  int max_path(F check, int u, int v) {\r\n    if (edge) return max_path_edge(check,\
    \ u, v);\r\n    if (!check(prod_path(u, u))) return -1;\r\n    auto pd = tree.get_path_decomposition(u,\
    \ v, edge);\r\n    X val = Monoid::unit();\r\n    for (auto &&[a, b]: pd) {\r\n\
    \      X x = (a <= b ? seg.prod(a, b + 1)\r\n                    : (Monoid::commute\
    \ ? seg.prod(b, a + 1)\r\n                                       : seg_r.prod(b,\
    \ a + 1)));\r\n      if (check(Monoid::op(val, x))) {\r\n        val = Monoid::op(val,\
    \ x);\r\n        u = (tree.V[b]);\r\n        continue;\r\n      }\r\n      auto\
    \ check_tmp = [&](X x) -> bool { return check(Monoid::op(val, x)); };\r\n    \
    \  if (a <= b) {\r\n        // \u4E0B\u308A\r\n        auto i = seg.max_right(check_tmp,\
    \ a);\r\n        return (i == a ? u : tree.V[i - 1]);\r\n      } else {\r\n  \
    \      // \u4E0A\u308A\r\n        auto i = (Monoid::commute ? seg.min_left(check_tmp,\
    \ a + 1)\r\n                                  : seg_r.min_left(check_tmp, a +\
    \ 1));\r\n        if (i == a + 1) return u;\r\n        return tree.V[i];\r\n \
    \     }\r\n    }\r\n    return v;\r\n  }\r\n\r\n  X prod_subtree(int u) {\r\n\
    \    int l = tree.LID[u], r = tree.RID[u];\r\n    return seg.prod(l + edge, r);\r\
    \n  }\r\n\r\n  X prod_all() { return prod_subtree(tree.V[0]); }\r\n\r\nprivate:\r\
    \n  template <class F>\r\n  int max_path_edge(F check, int u, int v) {\r\n   \
    \ assert(edge);\r\n    if (!check(Monoid::unit())) return -1;\r\n    int lca =\
    \ tree.lca(u, v);\r\n    auto pd = tree.get_path_decomposition(u, lca, edge);\r\
    \n    X val = Monoid::unit();\r\n\r\n    // climb\r\n    for (auto &&[a, b]: pd)\
    \ {\r\n      assert(a >= b);\r\n      X x = (Monoid::commute ? seg.prod(b, a +\
    \ 1) : seg_r.prod(b, a + 1));\r\n      if (check(Monoid::op(val, x))) {\r\n  \
    \      val = Monoid::op(val, x);\r\n        u = (tree.parent[tree.V[b]]);\r\n\
    \        continue;\r\n      }\r\n      auto check_tmp = [&](X x) -> bool { return\
    \ check(Monoid::op(val, x)); };\r\n      auto i = (Monoid::commute ? seg.min_left(check_tmp,\
    \ a + 1)\r\n                                : seg_r.min_left(check_tmp, a + 1));\r\
    \n      if (i == a + 1) return u;\r\n      return tree.parent[tree.V[i]];\r\n\
    \    }\r\n    // down\r\n    pd = tree.get_path_decomposition(lca, v, edge);\r\
    \n    for (auto &&[a, b]: pd) {\r\n      assert(a <= b);\r\n      X x = seg.prod(a,\
    \ b + 1);\r\n      if (check(Monoid::op(val, x))) {\r\n        val = Monoid::op(val,\
    \ x);\r\n        u = (tree.V[b]);\r\n        continue;\r\n      }\r\n      auto\
    \ check_tmp = [&](X x) -> bool { return check(Monoid::op(val, x)); };\r\n    \
    \  auto i = seg.max_right(check_tmp, a);\r\n      return (i == a ? u : tree.V[i\
    \ - 1]);\r\n    }\r\n    return v;\r\n  }\r\n};\r\n#line 2 \"ds/segtree/dual_segtree.hpp\"\
    \n\ntemplate <typename Monoid>\nstruct Dual_SegTree {\n  using MA = Monoid;\n\
    \  using A = typename MA::value_type;\n  int n, log, size;\n  vc<A> laz;\n\n \
    \ Dual_SegTree() : Dual_SegTree(0) {}\n  Dual_SegTree(int n) { build(n); }\n\n\
    \  void build(int m) {\n    n = m;\n    log = 1;\n    while ((1 << log) < n) ++log;\n\
    \    size = 1 << log;\n    laz.assign(size << 1, MA::unit());\n  }\n\n  A get(int\
    \ p) {\n    assert(0 <= p && p < n);\n    p += size;\n    for (int i = log; i\
    \ >= 1; i--) push(p >> i);\n    return laz[p];\n  }\n\n  vc<A> get_all() {\n \
    \   FOR(i, size) push(i);\n    return {laz.begin() + size, laz.begin() + size\
    \ + n};\n  }\n\n  void apply(int l, int r, const A& a) {\n    assert(0 <= l &&\
    \ l <= r && r <= n);\n    if (l == r) return;\n    l += size, r += size;\n   \
    \ if (!MA::commute) {\n      for (int i = log; i >= 1; i--) {\n        if (((l\
    \ >> i) << i) != l) push(l >> i);\n        if (((r >> i) << i) != r) push((r -\
    \ 1) >> i);\n      }\n    }\n    while (l < r) {\n      if (l & 1) all_apply(l++,\
    \ a);\n      if (r & 1) all_apply(--r, a);\n      l >>= 1, r >>= 1;\n    }\n \
    \ }\n\nprivate:\n  void push(int k) {\n    if (laz[k] == MA::unit()) return;\n\
    \    all_apply(2 * k, laz[k]), all_apply(2 * k + 1, laz[k]);\n    laz[k] = MA::unit();\n\
    \  }\n  void all_apply(int k, A a) { laz[k] = MA::op(laz[k], a); }\n};\n#line\
    \ 3 \"graph/ds/dual_tree_monoid.hpp\"\n\r\ntemplate <typename TREE, typename Monoid,\
    \ bool edge>\r\nstruct Dual_Tree_Monoid {\r\n  using X = typename Monoid::value_type;\r\
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
    \ + edge, r, x);\r\n  }\r\n};\r\n#line 2 \"alg/monoid/min.hpp\"\n\r\ntemplate\
    \ <typename E>\r\nstruct Monoid_Min {\r\n  using X = E;\r\n  using value_type\
    \ = X;\r\n  static constexpr X op(const X &x, const X &y) noexcept { return min(x,\
    \ y); }\r\n  static constexpr X unit() { return infty<E>; }\r\n  static constexpr\
    \ bool commute = true;\r\n};\r\n#line 2 \"alg/monoid/max.hpp\"\n\r\ntemplate <typename\
    \ E>\r\nstruct Monoid_Max {\r\n  using X = E;\r\n  using value_type = X;\r\n \
    \ static constexpr X op(const X &x, const X &y) noexcept { return max(x, y); }\r\
    \n  static constexpr X unit() { return -infty<E>; }\r\n  static constexpr bool\
    \ commute = true;\r\n};\r\n#line 8 \"graph/minimum_spanning_tree.hpp\"\n\r\n//\
    \ return : {T mst_cost, vc<bool> in_mst, Graph MST}\r\ntemplate <typename T>\r\
    \ntuple<T, vc<bool>, Graph<T>> minimum_spanning_tree(Graph<T>& G) {\r\n  int N\
    \ = G.N;\r\n  int M = len(G.edges);\r\n  vc<pair<T, int>> edges;\r\n  FOR(i, M)\
    \ {\r\n    auto& e = G.edges[i];\r\n    edges.eb(e.cost, i);\r\n  }\r\n  sort(all(edges));\r\
    \n  vc<bool> in_mst(M);\r\n  UnionFind uf(N);\r\n  T mst_cost = T(0);\r\n  Graph<T>\
    \ MST(N);\r\n  for (auto&& [cost, i]: edges) {\r\n    auto& e = G.edges[i];\r\n\
    \    if (uf.merge(e.frm, e.to)) {\r\n      in_mst[i] = 1;\r\n      mst_cost +=\
    \ e.cost;\r\n    }\r\n  }\r\n  FOR(i, M) if (in_mst[i]) {\r\n    auto& e = G.edges[i];\r\
    \n    MST.add(e.frm, e.to, e.cost);\r\n  }\r\n  MST.build();\r\n  return {mst_cost,\
    \ in_mst, MST};\r\n}\r\n\r\n// https://codeforces.com/contest/828/problem/F\r\n\
    // return : {T mst_cost, vc<bool> in_mst, Graph MST, vc<T> dat}\r\n// dat : \u8FBA\
    \u3054\u3068\u306B\u3001\u4ED6\u306E\u8FBA\u3092\u4FDD\u3063\u305F\u3068\u304D\
    \u306B MST \u8FBA\u306B\u306A\u308B\u6700\u5927\u91CD\u307F\r\ntemplate <typename\
    \ T>\r\ntuple<T, vc<bool>, Graph<T>, vc<T>> minimum_spanning_tree_cycle_data(\r\
    \n    Graph<T>& G) {\r\n  int N = G.N;\r\n  int M = len(G.edges);\r\n  auto [mst_cost,\
    \ in_mst, MST] = minimum_spanning_tree(G);\r\n  Tree<decltype(G)> tree(MST);\r\
    \n  vc<T> dat;\r\n  FOR(i, M) if (in_mst[i]) dat.eb(G.edges[i].cost);\r\n  Tree_Monoid<decltype(tree),\
    \ Monoid_Max<T>, 1> TM1(tree, dat);\r\n  Dual_Tree_Monoid<decltype(tree), Monoid_Min<T>,\
    \ 1> TM2(tree);\r\n  FOR(i, M) {\r\n    if (!in_mst[i]) {\r\n      auto& e = G.edges[i];\r\
    \n      TM2.apply_path(e.frm, e.to, e.cost);\r\n    }\r\n  }\r\n  vc<T> ANS(M);\r\
    \n  int m = 0;\r\n  FOR(i, M) {\r\n    auto& e = G.edges[i];\r\n    if (in_mst[i])\r\
    \n      ANS[i] = TM2.get(m++);\r\n    else\r\n      ANS[i] = TM1.prod_path(e.frm,\
    \ e.to);\r\n  }\r\n  return {mst_cost, in_mst, MST, ANS};\r\n}\n"
  code: "#include \"ds/unionfind/unionfind.hpp\"\r\n#include \"graph/base.hpp\"\r\n\
    #include \"graph/tree.hpp\"\r\n#include \"graph/ds/tree_monoid.hpp\"\r\n#include\
    \ \"graph/ds/dual_tree_monoid.hpp\"\r\n#include \"alg/monoid/min.hpp\"\r\n#include\
    \ \"alg/monoid/max.hpp\"\r\n\r\n// return : {T mst_cost, vc<bool> in_mst, Graph\
    \ MST}\r\ntemplate <typename T>\r\ntuple<T, vc<bool>, Graph<T>> minimum_spanning_tree(Graph<T>&\
    \ G) {\r\n  int N = G.N;\r\n  int M = len(G.edges);\r\n  vc<pair<T, int>> edges;\r\
    \n  FOR(i, M) {\r\n    auto& e = G.edges[i];\r\n    edges.eb(e.cost, i);\r\n \
    \ }\r\n  sort(all(edges));\r\n  vc<bool> in_mst(M);\r\n  UnionFind uf(N);\r\n\
    \  T mst_cost = T(0);\r\n  Graph<T> MST(N);\r\n  for (auto&& [cost, i]: edges)\
    \ {\r\n    auto& e = G.edges[i];\r\n    if (uf.merge(e.frm, e.to)) {\r\n     \
    \ in_mst[i] = 1;\r\n      mst_cost += e.cost;\r\n    }\r\n  }\r\n  FOR(i, M) if\
    \ (in_mst[i]) {\r\n    auto& e = G.edges[i];\r\n    MST.add(e.frm, e.to, e.cost);\r\
    \n  }\r\n  MST.build();\r\n  return {mst_cost, in_mst, MST};\r\n}\r\n\r\n// https://codeforces.com/contest/828/problem/F\r\
    \n// return : {T mst_cost, vc<bool> in_mst, Graph MST, vc<T> dat}\r\n// dat :\
    \ \u8FBA\u3054\u3068\u306B\u3001\u4ED6\u306E\u8FBA\u3092\u4FDD\u3063\u305F\u3068\
    \u304D\u306B MST \u8FBA\u306B\u306A\u308B\u6700\u5927\u91CD\u307F\r\ntemplate\
    \ <typename T>\r\ntuple<T, vc<bool>, Graph<T>, vc<T>> minimum_spanning_tree_cycle_data(\r\
    \n    Graph<T>& G) {\r\n  int N = G.N;\r\n  int M = len(G.edges);\r\n  auto [mst_cost,\
    \ in_mst, MST] = minimum_spanning_tree(G);\r\n  Tree<decltype(G)> tree(MST);\r\
    \n  vc<T> dat;\r\n  FOR(i, M) if (in_mst[i]) dat.eb(G.edges[i].cost);\r\n  Tree_Monoid<decltype(tree),\
    \ Monoid_Max<T>, 1> TM1(tree, dat);\r\n  Dual_Tree_Monoid<decltype(tree), Monoid_Min<T>,\
    \ 1> TM2(tree);\r\n  FOR(i, M) {\r\n    if (!in_mst[i]) {\r\n      auto& e = G.edges[i];\r\
    \n      TM2.apply_path(e.frm, e.to, e.cost);\r\n    }\r\n  }\r\n  vc<T> ANS(M);\r\
    \n  int m = 0;\r\n  FOR(i, M) {\r\n    auto& e = G.edges[i];\r\n    if (in_mst[i])\r\
    \n      ANS[i] = TM2.get(m++);\r\n    else\r\n      ANS[i] = TM1.prod_path(e.frm,\
    \ e.to);\r\n  }\r\n  return {mst_cost, in_mst, MST, ANS};\r\n}"
  dependsOn:
  - ds/unionfind/unionfind.hpp
  - graph/base.hpp
  - graph/tree.hpp
  - graph/ds/tree_monoid.hpp
  - ds/segtree/segtree.hpp
  - alg/monoid/monoid_reverse.hpp
  - graph/ds/dual_tree_monoid.hpp
  - ds/segtree/dual_segtree.hpp
  - alg/monoid/min.hpp
  - alg/monoid/max.hpp
  isVerificationFile: false
  path: graph/minimum_spanning_tree.hpp
  requiredBy: []
  timestamp: '2023-04-09 04:15:48+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/aoj/GRL_2_A.test.cpp
  - test_atcoder/abc270_f.test.cpp
documentation_of: graph/minimum_spanning_tree.hpp
layout: document
redirect_from:
- /library/graph/minimum_spanning_tree.hpp
- /library/graph/minimum_spanning_tree.hpp.html
title: graph/minimum_spanning_tree.hpp
---
