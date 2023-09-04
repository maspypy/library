---
data:
  _extendedDependsOn:
  - icon: ':question:'
    path: graph/base.hpp
    title: graph/base.hpp
  - icon: ':heavy_check_mark:'
    path: graph/tree.hpp
    title: graph/tree.hpp
  - icon: ':heavy_check_mark:'
    path: graph/tree_dp/rerooting_dp.hpp
    title: graph/tree_dp/rerooting_dp.hpp
  - icon: ':question:'
    path: mod/modint61.hpp
    title: mod/modint61.hpp
  - icon: ':question:'
    path: random/base.hpp
    title: random/base.hpp
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/library_checker/graph/classify_tree.test.cpp
    title: test/library_checker/graph/classify_tree.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 2 \"mod/modint61.hpp\"\n\r\nstruct modint61 {\r\n  static constexpr\
    \ u64 mod = (1ULL << 61) - 1;\r\n  u64 val;\r\n  constexpr modint61() : val(0ULL)\
    \ {}\r\n  constexpr modint61(u32 x) : val(x) {}\r\n  constexpr modint61(u64 x)\
    \ : val(x % mod) {}\r\n  constexpr modint61(int x) : val((x < 0) ? (x + static_cast<ll>(mod))\
    \ : x) {}\r\n  constexpr modint61(ll x)\r\n      : val(((x %= static_cast<ll>(mod))\
    \ < 0) ? (x + static_cast<ll>(mod))\r\n                                      \
    \        : x) {}\r\n  static constexpr u64 get_mod() { return mod; }\r\n  modint61\
    \ &operator+=(const modint61 &a) {\r\n    val = ((val += a.val) >= mod) ? (val\
    \ - mod) : val;\r\n    return *this;\r\n  }\r\n  modint61 &operator-=(const modint61\
    \ &a) {\r\n    val = ((val -= a.val) >= mod) ? (val + mod) : val;\r\n    return\
    \ *this;\r\n  }\r\n  modint61 &operator*=(const modint61 &a) {\r\n    const unsigned\
    \ __int128 y = static_cast<unsigned __int128>(val) * a.val;\r\n    val = (y >>\
    \ 61) + (y & mod);\r\n    val = (val >= mod) ? (val - mod) : val;\r\n    return\
    \ *this;\r\n  }\r\n  modint61 &operator/=(const modint61 &a) { return (*this *=\
    \ a.inverse()); }\r\n  modint61 operator+(const modint61 &p) const { return modint61(*this)\
    \ += p; }\r\n  modint61 operator-(const modint61 &p) const { return modint61(*this)\
    \ -= p; }\r\n  modint61 operator*(const modint61 &p) const { return modint61(*this)\
    \ *= p; }\r\n  modint61 operator/(const modint61 &p) const { return modint61(*this)\
    \ /= p; }\r\n  bool operator==(const modint61 &p) const { return val == p.val;\
    \ }\r\n  bool operator!=(const modint61 &p) const { return val != p.val; }\r\n\
    \  modint61 inverse() const {\r\n    ll a = val, b = mod, u = 1, v = 0, t;\r\n\
    \    while (b > 0) {\r\n      t = a / b;\r\n      swap(a -= t * b, b), swap(u\
    \ -= t * v, v);\r\n    }\r\n    return modint61(u);\r\n  }\r\n  modint61 pow(ll\
    \ n) const {\r\n    assert(n >= 0);\r\n    modint61 ret(1), mul(val);\r\n    while\
    \ (n > 0) {\r\n      if (n & 1) ret *= mul;\r\n      mul *= mul, n >>= 1;\r\n\
    \    }\r\n    return ret;\r\n  }\r\n#ifdef FASTIO\r\n  void write() { fastio::printer.write(val);\
    \ }\r\n  void read() {\r\n    ll x;\r\n    fastio::scanner.read(x);\r\n    val\
    \ = (val >= 0 ? val % mod : (mod - (-val) % mod) % mod);\r\n  }\r\n#endif\r\n\
    };\n#line 2 \"graph/base.hpp\"\n\ntemplate <typename T>\nstruct Edge {\n  int\
    \ frm, to;\n  T cost;\n  int id;\n};\n\ntemplate <typename T = int, bool directed\
    \ = false>\nstruct Graph {\n  int N, M;\n  using cost_type = T;\n  using edge_type\
    \ = Edge<T>;\n  vector<edge_type> edges;\n  vector<int> indptr;\n  vector<edge_type>\
    \ csr_edges;\n  vc<int> vc_deg, vc_indeg, vc_outdeg;\n  bool prepared;\n\n  class\
    \ OutgoingEdges {\n  public:\n    OutgoingEdges(const Graph* G, int l, int r)\
    \ : G(G), l(l), r(r) {}\n\n    const edge_type* begin() const {\n      if (l ==\
    \ r) { return 0; }\n      return &G->csr_edges[l];\n    }\n\n    const edge_type*\
    \ end() const {\n      if (l == r) { return 0; }\n      return &G->csr_edges[r];\n\
    \    }\n\n  private:\n    const Graph* G;\n    int l, r;\n  };\n\n  bool is_prepared()\
    \ { return prepared; }\n  constexpr bool is_directed() { return directed; }\n\n\
    \  Graph() : N(0), M(0), prepared(0) {}\n  Graph(int N) : N(N), M(0), prepared(0)\
    \ {}\n\n  void build(int n) {\n    N = n, M = 0;\n    prepared = 0;\n    edges.clear();\n\
    \    indptr.clear();\n    csr_edges.clear();\n    vc_deg.clear();\n    vc_indeg.clear();\n\
    \    vc_outdeg.clear();\n  }\n\n  void add(int frm, int to, T cost = 1, int i\
    \ = -1) {\n    assert(!prepared);\n    assert(0 <= frm && 0 <= to && to < N);\n\
    \    if (i == -1) i = M;\n    auto e = edge_type({frm, to, cost, i});\n    edges.eb(e);\n\
    \    ++M;\n  }\n\n  // wt, off\n  void read_tree(bool wt = false, int off = 1)\
    \ { read_graph(N - 1, wt, off); }\n\n  void read_graph(int M, bool wt = false,\
    \ int off = 1) {\n    for (int m = 0; m < M; ++m) {\n      INT(a, b);\n      a\
    \ -= off, b -= off;\n      if (!wt) {\n        add(a, b);\n      } else {\n  \
    \      T c;\n        read(c);\n        add(a, b, c);\n      }\n    }\n    build();\n\
    \  }\n\n  void build() {\n    assert(!prepared);\n    prepared = true;\n    indptr.assign(N\
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
    \ }\n  }\n};\n#line 2 \"graph/tree.hpp\"\n\r\n#line 4 \"graph/tree.hpp\"\n\r\n\
    // HLD euler tour \u3092\u3068\u3063\u3066\u3044\u308D\u3044\u308D\u3002\r\n//\
    \ \u6728\u4EE5\u5916\u3001\u975E\u9023\u7D50\u3067\u3082 dfs \u9806\u5E8F\u3084\
    \u89AA\u304C\u3068\u308C\u308B\u3002\r\ntemplate <typename GT>\r\nstruct Tree\
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
    \ { return 2 * RID[v] - depth[v] - 1; }\r\n\r\n  /* k: 0-indexed */\r\n  int LA(int\
    \ v, int k) {\r\n    assert(k <= depth[v]);\r\n    while (1) {\r\n      int u\
    \ = head[v];\r\n      if (LID[v] - k >= LID[u]) return V[LID[v] - k];\r\n    \
    \  k -= LID[v] - LID[u] + 1;\r\n      v = parent[u];\r\n    }\r\n  }\r\n  int\
    \ la(int u, int v) { return LA(u, v); }\r\n\r\n  int LCA(int u, int v) {\r\n \
    \   for (;; v = parent[head[v]]) {\r\n      if (LID[u] > LID[v]) swap(u, v);\r\
    \n      if (head[u] == head[v]) return u;\r\n    }\r\n  }\r\n  // root \u3092\u6839\
    \u3068\u3057\u305F\u5834\u5408\u306E lca\r\n  int LCA_root(int u, int v, int root)\
    \ {\r\n    return LCA(u, v) ^ LCA(u, root) ^ LCA(v, root);\r\n  }\r\n  int lca(int\
    \ u, int v) { return LCA(u, v); }\r\n  int lca_root(int u, int v, int root) {\
    \ return LCA_root(u, v, root); }\r\n\r\n  int subtree_size(int v, int root = -1)\
    \ {\r\n    if (root == -1) return RID[v] - LID[v];\r\n    if (v == root) return\
    \ N;\r\n    int x = jump(v, root, 1);\r\n    if (in_subtree(v, x)) return RID[v]\
    \ - LID[v];\r\n    return N - RID[x] + LID[x];\r\n  }\r\n\r\n  int dist(int a,\
    \ int b) {\r\n    int c = LCA(a, b);\r\n    return depth[a] + depth[b] - 2 * depth[c];\r\
    \n  }\r\n\r\n  WT dist_weighted(int a, int b) {\r\n    int c = LCA(a, b);\r\n\
    \    return depth_weighted[a] + depth_weighted[b] - WT(2) * depth_weighted[c];\r\
    \n  }\r\n\r\n  // a is in b\r\n  bool in_subtree(int a, int b) { return LID[b]\
    \ <= LID[a] && LID[a] < RID[b]; }\r\n\r\n  int jump(int a, int b, ll k) {\r\n\
    \    if (k == 1) {\r\n      if (a == b) return -1;\r\n      return (in_subtree(b,\
    \ a) ? LA(b, depth[b] - depth[a] - 1) : parent[a]);\r\n    }\r\n    int c = LCA(a,\
    \ b);\r\n    int d_ac = depth[a] - depth[c];\r\n    int d_bc = depth[b] - depth[c];\r\
    \n    if (k > d_ac + d_bc) return -1;\r\n    if (k <= d_ac) return LA(a, k);\r\
    \n    return LA(b, d_ac + d_bc - k);\r\n  }\r\n\r\n  vc<int> collect_child(int\
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
    \n    return P;\r\n  }\r\n};\r\n#line 2 \"random/base.hpp\"\n\nu64 RNG_64() {\n\
    \  static uint64_t x_\n      = uint64_t(chrono::duration_cast<chrono::nanoseconds>(\n\
    \                     chrono::high_resolution_clock::now().time_since_epoch())\n\
    \                     .count())\n        * 10150724397891781847ULL;\n  x_ ^= x_\
    \ << 7;\n  return x_ ^= x_ >> 9;\n}\n\nu64 RNG(u64 lim) { return RNG_64() % lim;\
    \ }\n\nll RNG(ll l, ll r) { return l + RNG_64() % (r - l); }\n#line 1 \"graph/tree_dp/rerooting_dp.hpp\"\
    \n\r\n#line 4 \"graph/tree_dp/rerooting_dp.hpp\"\n\r\ntemplate <typename TREE,\
    \ typename Data>\r\nstruct Rerooting_dp {\r\n  TREE& tree;\r\n  vc<Data> dp_1;\
    \ // \u8FBA pv \u306B\u5BFE\u3057\u3066\u3001\u90E8\u5206\u6728 v\r\n  vc<Data>\
    \ dp_2; // \u8FBA pv \u306B\u5BFE\u3057\u3066\u3001\u90E8\u5206\u6728 p\r\n  vc<Data>\
    \ dp;   // full tree\r\n\r\n  template <typename F1, typename F2, typename F3>\r\
    \n  Rerooting_dp(TREE& tree, F1 f_ee, F2 f_ev, F3 f_ve, const Data unit)\r\n \
    \     : tree(tree) {\r\n    assert(!tree.G.is_directed());\r\n    build(f_ee,\
    \ f_ev, f_ve, unit);\r\n  }\r\n\r\n  // v \u3092\u6839\u3068\u3057\u305F\u3068\
    \u304D\u306E full tree\r\n  Data operator[](int v) { return dp[v]; }\r\n\r\n \
    \ // root \u3092\u6839\u3068\u3057\u305F\u3068\u304D\u306E\u90E8\u5206\u6728 v\r\
    \n  Data get(int root, int v) {\r\n    if (root == v) return dp[v];\r\n    if\
    \ (!tree.in_subtree(root, v)) { return dp_1[v]; }\r\n    int w = tree.jump(v,\
    \ root, 1);\r\n    return dp_2[w];\r\n  }\r\n\r\n  template <typename F1, typename\
    \ F2, typename F3>\r\n  void build(F1 f_ee, F2 f_ev, F3 f_ve, const Data unit)\
    \ {\r\n    int N = tree.N;\r\n    // dp1: subtree\r\n    dp_1.assign(N, unit);\r\
    \n    FOR_R(i, N) {\r\n      int v = tree.V[i];\r\n      for (auto&& e: tree.G[v])\
    \ {\r\n        if (e.to == tree.parent[v]) continue;\r\n        dp_1[v] = f_ee(dp_1[v],\
    \ f_ve(dp_1[e.to], e));\r\n      }\r\n      dp_1[v] = f_ev(dp_1[v], v);\r\n  \
    \  }\r\n\r\n    // dp2[v]: subtree of p, rooted at v\r\n    dp_2.assign(N, unit);\r\
    \n    // dp[v]: fulltree, rooted at v\r\n    dp.assign(N, unit);\r\n    FOR(i,\
    \ N) {\r\n      int p = tree.V[i];\r\n      vc<int> ch;\r\n      vc<Data> ch_data;\r\
    \n      Data x = unit;\r\n      for (auto&& e: tree.G[p]) {\r\n        if (e.to\
    \ == tree.parent[p]) {\r\n          x = f_ve(dp_2[p], e);\r\n        } else {\r\
    \n          ch.eb(e.to);\r\n          ch_data.eb(f_ve(dp_1[e.to], e));\r\n   \
    \     }\r\n      }\r\n      int n = len(ch);\r\n      if (!n) {\r\n        dp[p]\
    \ = f_ev(x, p);\r\n        continue;\r\n      }\r\n      vc<Data> prod_left(n,\
    \ x);\r\n      FOR(i, n - 1) prod_left[i + 1] = f_ee(prod_left[i], ch_data[i]);\r\
    \n      Data prod_right = unit;\r\n      FOR_R(i, n) {\r\n        dp_2[ch[i]]\
    \ = f_ev(f_ee(prod_left[i], prod_right), p);\r\n        prod_right = f_ee(prod_right,\
    \ ch_data[i]);\r\n      }\r\n      dp[p] = f_ev(f_ee(x, prod_right), p);\r\n \
    \   }\r\n  }\r\n};\r\n#line 6 \"graph/tree_dp/subtree_hash.hpp\"\n\ntemplate <typename\
    \ TREE>\nstruct SubTree_Hash {\n  using mint = modint61;\n  TREE& tree;\n  vc<u64>\
    \ dp, dp_1, dp_2;\n\n  SubTree_Hash(TREE& tree) : tree(tree) {\n    int N = tree.N;\n\
    \    using T = pair<int, mint>;\n    T unit = {0, mint(1)};\n\n    auto f_ee =\
    \ [&](T A, T B) -> T { return {max(A.fi, B.fi), A.se * B.se}; };\n    auto f_ev\
    \ = [&](T A, int v) -> T { return {A.fi + 1, A.se}; };\n    auto f_ve = [&](T\
    \ A, const auto& e) -> T {\n      return {A.fi, A.se + hash_base(A.fi)};\n   \
    \ };\n\n    Rerooting_dp<decltype(tree), T> DP(tree, f_ee, f_ev, f_ve, unit);\n\
    \    dp.resize(N), dp_1.resize(N), dp_2.resize(N);\n    FOR(v, N) dp[v] = DP.dp[v].se.val;\n\
    \    FOR(v, N) dp_1[v] = DP.dp_1[v].se.val;\n    FOR(v, N) dp_2[v] = DP.dp_2[v].se.val;\n\
    \  }\n\n  // v \u3092\u6839\u3068\u3057\u305F\u3068\u304D\u306E full tree\n  u64\
    \ operator[](int v) { return dp[v]; }\n\n  // root \u3092\u6839\u3068\u3057\u305F\
    \u3068\u304D\u306E\u90E8\u5206\u6728 v\n  u64 get(int root, int v) {\n    if (root\
    \ == v) return dp[v];\n    if (!tree.in_subtree(root, v)) { return dp_1[v]; }\n\
    \    int w = tree.jump(v, root, 1);\n    return dp_2[w];\n  }\n\n  static mint\
    \ hash_base(int k) {\n    static vc<mint> dat;\n    while (len(dat) <= k) dat.eb(RNG(mint::get_mod()));\n\
    \    return dat[k];\n  }\n};\n"
  code: "#include \"mod/modint61.hpp\"\n#include \"graph/base.hpp\"\n#include \"graph/tree.hpp\"\
    \n#include \"random/base.hpp\"\n#include \"graph/tree_dp/rerooting_dp.hpp\"\n\n\
    template <typename TREE>\nstruct SubTree_Hash {\n  using mint = modint61;\n  TREE&\
    \ tree;\n  vc<u64> dp, dp_1, dp_2;\n\n  SubTree_Hash(TREE& tree) : tree(tree)\
    \ {\n    int N = tree.N;\n    using T = pair<int, mint>;\n    T unit = {0, mint(1)};\n\
    \n    auto f_ee = [&](T A, T B) -> T { return {max(A.fi, B.fi), A.se * B.se};\
    \ };\n    auto f_ev = [&](T A, int v) -> T { return {A.fi + 1, A.se}; };\n   \
    \ auto f_ve = [&](T A, const auto& e) -> T {\n      return {A.fi, A.se + hash_base(A.fi)};\n\
    \    };\n\n    Rerooting_dp<decltype(tree), T> DP(tree, f_ee, f_ev, f_ve, unit);\n\
    \    dp.resize(N), dp_1.resize(N), dp_2.resize(N);\n    FOR(v, N) dp[v] = DP.dp[v].se.val;\n\
    \    FOR(v, N) dp_1[v] = DP.dp_1[v].se.val;\n    FOR(v, N) dp_2[v] = DP.dp_2[v].se.val;\n\
    \  }\n\n  // v \u3092\u6839\u3068\u3057\u305F\u3068\u304D\u306E full tree\n  u64\
    \ operator[](int v) { return dp[v]; }\n\n  // root \u3092\u6839\u3068\u3057\u305F\
    \u3068\u304D\u306E\u90E8\u5206\u6728 v\n  u64 get(int root, int v) {\n    if (root\
    \ == v) return dp[v];\n    if (!tree.in_subtree(root, v)) { return dp_1[v]; }\n\
    \    int w = tree.jump(v, root, 1);\n    return dp_2[w];\n  }\n\n  static mint\
    \ hash_base(int k) {\n    static vc<mint> dat;\n    while (len(dat) <= k) dat.eb(RNG(mint::get_mod()));\n\
    \    return dat[k];\n  }\n};\n"
  dependsOn:
  - mod/modint61.hpp
  - graph/base.hpp
  - graph/tree.hpp
  - random/base.hpp
  - graph/tree_dp/rerooting_dp.hpp
  isVerificationFile: false
  path: graph/tree_dp/subtree_hash.hpp
  requiredBy: []
  timestamp: '2023-08-19 23:09:56+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/library_checker/graph/classify_tree.test.cpp
documentation_of: graph/tree_dp/subtree_hash.hpp
layout: document
redirect_from:
- /library/graph/tree_dp/subtree_hash.hpp
- /library/graph/tree_dp/subtree_hash.hpp.html
title: graph/tree_dp/subtree_hash.hpp
---
