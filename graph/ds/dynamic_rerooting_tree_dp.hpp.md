---
data:
  _extendedDependsOn:
  - icon: ':question:'
    path: ds/hashmap.hpp
    title: ds/hashmap.hpp
  - icon: ':question:'
    path: graph/base.hpp
    title: graph/base.hpp
  - icon: ':question:'
    path: graph/ds/static_toptree.hpp
    title: graph/ds/static_toptree.hpp
  - icon: ':question:'
    path: graph/tree.hpp
    title: graph/tree.hpp
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/2_library_checker/tree/point_set_tree_path_composite_sum.test.cpp
    title: test/2_library_checker/tree/point_set_tree_path_composite_sum.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 2 \"graph/tree.hpp\"\n\r\n#line 2 \"ds/hashmap.hpp\"\n\r\n//\
    \ u64 -> Val\r\ntemplate <typename Val>\r\nstruct HashMap {\r\n  // n \u306F\u5165\
    \u308C\u305F\u3044\u3082\u306E\u306E\u500B\u6570\u3067 ok\r\n  HashMap(u32 n =\
    \ 0) { build(n); }\r\n  void build(u32 n) {\r\n    u32 k = 8;\r\n    while (k\
    \ < n * 2) k *= 2;\r\n    cap = k / 2, mask = k - 1;\r\n    key.resize(k), val.resize(k),\
    \ used.assign(k, 0);\r\n  }\r\n\r\n  // size \u3092\u4FDD\u3063\u305F\u307E\u307E\
    . size=0 \u306B\u3059\u308B\u3068\u304D\u306F build \u3059\u308B\u3053\u3068.\r\
    \n  void clear() {\r\n    used.assign(len(used), 0);\r\n    cap = (mask + 1) /\
    \ 2;\r\n  }\r\n  int size() { return len(used) / 2 - cap; }\r\n\r\n  int index(const\
    \ u64& k) {\r\n    int i = 0;\r\n    for (i = hash(k); used[i] && key[i] != k;\
    \ i = (i + 1) & mask) {}\r\n    return i;\r\n  }\r\n\r\n  Val& operator[](const\
    \ u64& k) {\r\n    if (cap == 0) extend();\r\n    int i = index(k);\r\n    if\
    \ (!used[i]) { used[i] = 1, key[i] = k, val[i] = Val{}, --cap; }\r\n    return\
    \ val[i];\r\n  }\r\n\r\n  Val get(const u64& k, Val default_value) {\r\n    int\
    \ i = index(k);\r\n    return (used[i] ? val[i] : default_value);\r\n  }\r\n\r\
    \n  bool count(const u64& k) {\r\n    int i = index(k);\r\n    return used[i]\
    \ && key[i] == k;\r\n  }\r\n\r\n  // f(key, val)\r\n  template <typename F>\r\n\
    \  void enumerate_all(F f) {\r\n    FOR(i, len(used)) if (used[i]) f(key[i], val[i]);\r\
    \n  }\r\n\r\nprivate:\r\n  u32 cap, mask;\r\n  vc<u64> key;\r\n  vc<Val> val;\r\
    \n  vc<bool> used;\r\n\r\n  u64 hash(u64 x) {\r\n    static const u64 FIXED_RANDOM\
    \ = std::chrono::steady_clock::now().time_since_epoch().count();\r\n    x += FIXED_RANDOM;\r\
    \n    x = (x ^ (x >> 30)) * 0xbf58476d1ce4e5b9;\r\n    x = (x ^ (x >> 27)) * 0x94d049bb133111eb;\r\
    \n    return (x ^ (x >> 31)) & mask;\r\n  }\r\n\r\n  void extend() {\r\n    vc<pair<u64,\
    \ Val>> dat;\r\n    dat.reserve(len(used) / 2 - cap);\r\n    FOR(i, len(used))\
    \ {\r\n      if (used[i]) dat.eb(key[i], val[i]);\r\n    }\r\n    build(2 * len(dat));\r\
    \n    for (auto& [a, b]: dat) (*this)[a] = b;\r\n  }\r\n};\n#line 3 \"graph/base.hpp\"\
    \n\ntemplate <typename T>\nstruct Edge {\n  int frm, to;\n  T cost;\n  int id;\n\
    };\n\ntemplate <typename T = int, bool directed = false>\nstruct Graph {\n  static\
    \ constexpr bool is_directed = directed;\n  int N, M;\n  using cost_type = T;\n\
    \  using edge_type = Edge<T>;\n  vector<edge_type> edges;\n  vector<int> indptr;\n\
    \  vector<edge_type> csr_edges;\n  vc<int> vc_deg, vc_indeg, vc_outdeg;\n  bool\
    \ prepared;\n\n  class OutgoingEdges {\n  public:\n    OutgoingEdges(const Graph*\
    \ G, int l, int r) : G(G), l(l), r(r) {}\n\n    const edge_type* begin() const\
    \ {\n      if (l == r) { return 0; }\n      return &G->csr_edges[l];\n    }\n\n\
    \    const edge_type* end() const {\n      if (l == r) { return 0; }\n      return\
    \ &G->csr_edges[r];\n    }\n\n  private:\n    const Graph* G;\n    int l, r;\n\
    \  };\n\n  bool is_prepared() { return prepared; }\n\n  Graph() : N(0), M(0),\
    \ prepared(0) {}\n  Graph(int N) : N(N), M(0), prepared(0) {}\n\n  void build(int\
    \ n) {\n    N = n, M = 0;\n    prepared = 0;\n    edges.clear();\n    indptr.clear();\n\
    \    csr_edges.clear();\n    vc_deg.clear();\n    vc_indeg.clear();\n    vc_outdeg.clear();\n\
    \  }\n\n  void add(int frm, int to, T cost = 1, int i = -1) {\n    assert(!prepared);\n\
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
    \      if (!directed) csr_edges[counter[e.to]++] = edge_type({e.to, e.frm, e.cost,\
    \ e.id});\n    }\n  }\n\n  OutgoingEdges operator[](int v) const {\n    assert(prepared);\n\
    \    return {this, indptr[v], indptr[v + 1]};\n  }\n\n  vc<int> deg_array() {\n\
    \    if (vc_deg.empty()) calc_deg();\n    return vc_deg;\n  }\n\n  pair<vc<int>,\
    \ vc<int>> deg_array_inout() {\n    if (vc_indeg.empty()) calc_deg_inout();\n\
    \    return {vc_indeg, vc_outdeg};\n  }\n\n  int deg(int v) {\n    if (vc_deg.empty())\
    \ calc_deg();\n    return vc_deg[v];\n  }\n\n  int in_deg(int v) {\n    if (vc_indeg.empty())\
    \ calc_deg_inout();\n    return vc_indeg[v];\n  }\n\n  int out_deg(int v) {\n\
    \    if (vc_outdeg.empty()) calc_deg_inout();\n    return vc_outdeg[v];\n  }\n\
    \n#ifdef FASTIO\n  void debug() {\n#ifdef LOCAL\n    print(\"Graph\");\n    if\
    \ (!prepared) {\n      print(\"frm to cost id\");\n      for (auto&& e: edges)\
    \ print(e.frm, e.to, e.cost, e.id);\n    } else {\n      print(\"indptr\", indptr);\n\
    \      print(\"frm to cost id\");\n      FOR(v, N) for (auto&& e: (*this)[v])\
    \ print(e.frm, e.to, e.cost, e.id);\n    }\n#endif\n  }\n#endif\n\n  vc<int> new_idx;\n\
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
    \    }\n    G1.build();\n    return G1;\n  }\n\n  HashMap<int> MP_FOR_EID;\n\n\
    \  int get_eid(u64 a, u64 b) {\n    if (len(MP_FOR_EID) == 0) {\n      MP_FOR_EID.build(N\
    \ - 1);\n      for (auto& e: edges) {\n        u64 a = e.frm, b = e.to;\n    \
    \    u64 k = to_eid_key(a, b);\n        MP_FOR_EID[k] = e.id;\n      }\n    }\n\
    \    return MP_FOR_EID.get(to_eid_key(a, b), -1);\n  }\n\n  u64 to_eid_key(u64\
    \ a, u64 b) {\n    if (!directed && a > b) swap(a, b);\n    return N * a + b;\n\
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
    \n    int w = V[k];\r\n    return (parent[w] == v ? w : -1);\r\n  }\r\n\r\n  vc<int>\
    \ memo_tail;\r\n\r\n  int tail(int v) {\r\n    if (memo_tail.empty()) {\r\n  \
    \    memo_tail.assign(N, -1);\r\n      FOR_R(i, N) {\r\n        int v = V[i];\r\
    \n        int w = heavy_child(v);\r\n        memo_tail[v] = (w == -1 ? v : memo_tail[w]);\r\
    \n      }\r\n    }\r\n    return memo_tail[v];\r\n  }\r\n\r\n  int e_to_v(int\
    \ eid) {\r\n    auto e = G.edges[eid];\r\n    return (parent[e.frm] == e.to ?\
    \ e.frm : e.to);\r\n  }\r\n  int v_to_e(int v) { return VtoE[v]; }\r\n  int get_eid(int\
    \ u, int v) {\r\n    if (parent[u] != v) swap(u, v);\r\n    assert(parent[u] ==\
    \ v);\r\n    return VtoE[u];\r\n  }\r\n\r\n  int ELID(int v) { return 2 * LID[v]\
    \ - depth[v]; }\r\n  int ERID(int v) { return 2 * RID[v] - depth[v] - 1; }\r\n\
    \r\n  // \u76EE\u6A19\u5730\u70B9\u3078\u9032\u3080\u500B\u6570\u304C k\r\n  int\
    \ LA(int v, int k) {\r\n    assert(k <= depth[v]);\r\n    while (1) {\r\n    \
    \  int u = head[v];\r\n      if (LID[v] - k >= LID[u]) return V[LID[v] - k];\r\
    \n      k -= LID[v] - LID[u] + 1;\r\n      v = parent[u];\r\n    }\r\n  }\r\n\
    \  int la(int u, int v) { return LA(u, v); }\r\n\r\n  int LCA(int u, int v) {\r\
    \n    for (;; v = parent[head[v]]) {\r\n      if (LID[u] > LID[v]) swap(u, v);\r\
    \n      if (head[u] == head[v]) return u;\r\n    }\r\n  }\r\n\r\n  int meet(int\
    \ a, int b, int c) { return LCA(a, b) ^ LCA(a, c) ^ LCA(b, c); }\r\n  int lca(int\
    \ u, int v) { return LCA(u, v); }\r\n\r\n  int subtree_size(int v, int root =\
    \ -1) {\r\n    if (root == -1) return RID[v] - LID[v];\r\n    if (v == root) return\
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
    \ res.eb(e.to);\r\n    return res;\r\n  }\r\n\r\n  vc<int> collect_subtree(int\
    \ v) { return {V.begin() + LID[v], V.begin() + RID[v]}; }\r\n\r\n  vc<int> collect_light(int\
    \ v) {\r\n    vc<int> res;\r\n    bool skip = true;\r\n    for (auto &&e: G[v])\r\
    \n      if (e.to != parent[v]) {\r\n        if (!skip) res.eb(e.to);\r\n     \
    \   skip = false;\r\n      }\r\n    return res;\r\n  }\r\n\r\n  vc<pair<int, int>>\
    \ get_path_decomposition(int u, int v, bool edge) {\r\n    // [\u59CB\u70B9, \u7D42\
    \u70B9] \u306E\"\u9589\"\u533A\u9593\u5217\u3002\r\n    vc<pair<int, int>> up,\
    \ down;\r\n    while (1) {\r\n      if (head[u] == head[v]) break;\r\n      if\
    \ (LID[u] < LID[v]) {\r\n        down.eb(LID[head[v]], LID[v]);\r\n        v =\
    \ parent[head[v]];\r\n      } else {\r\n        up.eb(LID[u], LID[head[u]]);\r\
    \n        u = parent[head[u]];\r\n      }\r\n    }\r\n    if (LID[u] < LID[v])\
    \ down.eb(LID[u] + edge, LID[v]);\r\n    elif (LID[v] + edge <= LID[u]) up.eb(LID[u],\
    \ LID[v] + edge);\r\n    reverse(all(down));\r\n    up.insert(up.end(), all(down));\r\
    \n    return up;\r\n  }\r\n\r\n  // \u8FBA\u306E\u5217\u306E\u60C5\u5831 (frm,to,str)\r\
    \n  // str = \"heavy_up\", \"heavy_down\", \"light_up\", \"light_down\"\r\n  vc<tuple<int,\
    \ int, string>> get_path_decomposition_detail(int u, int v) {\r\n    vc<tuple<int,\
    \ int, string>> up, down;\r\n    while (1) {\r\n      if (head[u] == head[v])\
    \ break;\r\n      if (LID[u] < LID[v]) {\r\n        if (v != head[v]) down.eb(head[v],\
    \ v, \"heavy_down\"), v = head[v];\r\n        down.eb(parent[v], v, \"light_down\"\
    ), v = parent[v];\r\n      } else {\r\n        if (u != head[u]) up.eb(u, head[u],\
    \ \"heavy_up\"), u = head[u];\r\n        up.eb(u, parent[u], \"light_up\"), u\
    \ = parent[u];\r\n      }\r\n    }\r\n    if (LID[u] < LID[v]) down.eb(u, v, \"\
    heavy_down\");\r\n    elif (LID[v] < LID[u]) up.eb(u, v, \"heavy_up\");\r\n  \
    \  reverse(all(down));\r\n    concat(up, down);\r\n    return up;\r\n  }\r\n\r\
    \n  vc<int> restore_path(int u, int v) {\r\n    vc<int> P;\r\n    for (auto &&[a,\
    \ b]: get_path_decomposition(u, v, 0)) {\r\n      if (a <= b) {\r\n        FOR(i,\
    \ a, b + 1) P.eb(V[i]);\r\n      } else {\r\n        FOR_R(i, b, a + 1) P.eb(V[i]);\r\
    \n      }\r\n    }\r\n    return P;\r\n  }\r\n\r\n  // path [a,b] \u3068 [c,d]\
    \ \u306E\u4EA4\u308F\u308A. \u7A7A\u306A\u3089\u3070 {-1,-1}.\r\n  // https://codeforces.com/problemset/problem/500/G\r\
    \n  pair<int, int> path_intersection(int a, int b, int c, int d) {\r\n    int\
    \ ab = lca(a, b), ac = lca(a, c), ad = lca(a, d);\r\n    int bc = lca(b, c), bd\
    \ = lca(b, d), cd = lca(c, d);\r\n    int x = ab ^ ac ^ bc, y = ab ^ ad ^ bd;\
    \ // meet(a,b,c), meet(a,b,d)\r\n    if (x != y) return {x, y};\r\n    int z =\
    \ ac ^ ad ^ cd;\r\n    if (x != z) x = -1;\r\n    return {x, x};\r\n  }\r\n\r\n\
    \  // uv path \u4E0A\u3067 check(v) \u3092\u6E80\u305F\u3059\u6700\u5F8C\u306E\
    \ v\r\n  // \u306A\u3051\u308C\u3070 \uFF08\u3064\u307E\u308A check(v) \u304C\
    \ ng \uFF09-1\r\n  template <class F>\r\n  int max_path(F check, int u, int v)\
    \ {\r\n    if (!check(u)) return -1;\r\n    auto pd = get_path_decomposition(u,\
    \ v, false);\r\n    for (auto [a, b]: pd) {\r\n      if (!check(V[a])) return\
    \ u;\r\n      if (check(V[b])) {\r\n        u = V[b];\r\n        continue;\r\n\
    \      }\r\n      int c = binary_search([&](int c) -> bool { return check(V[c]);\
    \ }, a, b, 0);\r\n      return V[c];\r\n    }\r\n    return u;\r\n  }\r\n};\r\n\
    #line 2 \"graph/ds/static_toptree.hpp\"\n\n/*\n\u53C2\u8003 joitour tatyam\n\u30AF\
    \u30E9\u30B9\u30BF\u306F\u6839\u304C virtual \u306A\u3082\u306E\u306E\u307F\u3067\
    \u3042\u308B\u3088\u3046\u306A\u7C21\u6613\u7248\nN \u500B\u306E (\u9802+\u8FBA\
    ) \u3092\u30DE\u30FC\u30B8\u3057\u3066\u3044\u3063\u3066\uFF0C\u6728\u5168\u4F53\
    \uFF0B\u6839\u304B\u3089\u89AA\u3078\u306E\u8FBA\u3068\u3059\u308B\uFF0E\nsingle(v)\
    \ : v \u3068\u305D\u306E\u89AA\u8FBA\u3092\u5408\u308F\u305B\u305F\u30AF\u30E9\
    \u30B9\u30BF\nrake(L,R) : L \u306E boundary \u3092\u7DAD\u6301\ncompress(L,R)\
    \  (top-down) \u9806\u306B x,y\n*/\ntemplate <typename TREE>\nstruct Static_TopTree\
    \ {\n  int N;\n  TREE &tree;\n  vc<int> par, lch, rch, A, B; // A, B boundary\
    \ (top-down)\n  vc<bool> is_compress;\n\n  Static_TopTree(TREE &tree) : tree(tree)\
    \ { build(); }\n\n  void build() {\n    N = tree.N;\n    par.assign(N, -1), lch.assign(N,\
    \ -1), rch.assign(N, -1), A.assign(N, -1), B.assign(N, -1), is_compress.assign(N,\
    \ 0);\n    FOR(v, N) { A[v] = tree.parent[v], B[v] = v; }\n    build_dfs(tree.V[0]);\n\
    \    assert(len(par) == 2 * N - 1);\n  }\n\n  // \u6728\u5168\u4F53\u3067\u306E\
    \u96C6\u7D04\u5024\u3092\u5F97\u308B\n  // single(v) : v \u3068\u305D\u306E\u89AA\
    \u8FBA\u3092\u5408\u308F\u305B\u305F\u30AF\u30E9\u30B9\u30BF\n  // rake(x, y,\
    \ u, v) uv(top down) \u304C boundary \u306B\u306A\u308B\u3088\u3046\u306B rake\
    \ (maybe v=-1)\n  // compress(x,y,a,b,c)  (top-down) \u9806\u306B (a,b] + (b,c]\n\
    \  template <typename TREE_DP, typename F>\n  typename TREE_DP::value_type tree_dp(F\
    \ single) {\n    using Data = typename TREE_DP::value_type;\n    auto dfs = [&](auto\
    \ &dfs, int k) -> Data {\n      if (0 <= k && k < N) return single(k);\n     \
    \ Data x = dfs(dfs, lch[k]), y = dfs(dfs, rch[k]);\n      if (is_compress[k])\
    \ {\n        assert(B[lch[k]] == A[rch[k]]);\n        return TREE_DP::compress(x,\
    \ y);\n      }\n      return TREE_DP::rake(x, y);\n    };\n    return dfs(dfs,\
    \ 2 * N - 2);\n  }\n\nprivate:\n  int new_node(int l, int r, int a, int b, bool\
    \ c) {\n    int v = len(par);\n    par.eb(-1), lch.eb(l), rch.eb(r), A.eb(a),\
    \ B.eb(b), is_compress.eb(c);\n    par[l] = par[r] = v;\n    return v;\n  }\n\n\
    \  // height, node idx\n  // compress \u53C2\u8003\uFF1Ahttps://atcoder.jp/contests/abc351/editorial/9910\n\
    \  // \u305F\u3060\u3057 heavy path \u306E\u9078\u3073\u65B9\u307E\u3067\u306F\
    \u8003\u616E\u3057\u306A\u3044\n  pair<int, int> build_dfs(int v) {\n    assert(tree.head[v]\
    \ == v);\n    auto path = tree.heavy_path_at(v);\n    vc<pair<int, int>> stack;\n\
    \    stack.eb(0, path[0]);\n    auto merge_last_two = [&]() -> void {\n      auto\
    \ [h2, k2] = POP(stack);\n      auto [h1, k1] = POP(stack);\n      stack.eb(max(h1,\
    \ h2) + 1, new_node(k1, k2, A[k1], B[k2], true));\n    };\n\n    FOR(i, 1, len(path))\
    \ {\n      pqg<pair<int, int>> que;\n      int k = path[i];\n      que.emplace(0,\
    \ k);\n      for (auto &c: tree.collect_light(path[i - 1])) { que.emplace(build_dfs(c));\
    \ }\n      while (len(que) >= 2) {\n        auto [h1, i1] = POP(que);\n      \
    \  auto [h2, i2] = POP(que);\n        if (i2 == k) swap(i1, i2);\n        int\
    \ i3 = new_node(i1, i2, A[i1], B[i1], false);\n        if (k == i1) k = i3;\n\
    \        que.emplace(max(h1, h2) + 1, i3);\n      }\n      stack.eb(POP(que));\n\
    \n      while (1) {\n        int n = len(stack);\n        if (n >= 3 && (stack[n\
    \ - 3].fi == stack[n - 2].fi || stack[n - 3].fi <= stack[n - 1].fi)) {\n     \
    \     auto [h3, k3] = POP(stack);\n          merge_last_two(), stack.eb(h3, k3);\n\
    \        }\n        elif (n >= 2 && stack[n - 2].fi <= stack[n - 1].fi) { merge_last_two();\
    \ }\n        else break;\n      }\n    }\n    while (len(stack) >= 2) { merge_last_two();\
    \ }\n    return POP(stack);\n  }\n};\n#line 2 \"graph/ds/dynamic_rerooting_tree_dp.hpp\"\
    \n\n/*\nstruct Data {\n  // type, s, t \u306F\u5FC5\u305A\u5B9A\u7FA9\u3059\u308B\
    . \uFF08\u7D4C\u9A13\u4E0A\u3069\u3046\u305B\u30C7\u30D0\u30C3\u30B0\u3067\u5FC5\
    \u8981\u306B\u306A\u308B\uFF09. s \u304C\u6839.\n  // type==0: s\u304C virtual.\
    \ type==1: t \u304C virtual.\n  int type, s, t;\n};\n\nstruct TREE_DP {\n  using\
    \ value_type = Data;\n  using X = value_type;\n\n  static X rake(const X& L, const\
    \ X& R) {\n    assert(L.type == 0 && R.type == 0 && L.s == R.s);\n    X ANS =\
    \ {0, L.s, L.t};\n  }\n  static X rake2(const X& L, const X& R) {\n    assert(L.type\
    \ == 1 && R.type == 0 && L.s == R.s);\n    X ANS = {1, L.s, L.t};\n  }\n  static\
    \ X compress(const X& L, const X& R) {\n    assert(L.type == 0 && R.type == 0\
    \ && L.t == R.s);\n    X ANS = {0, L.s, R.t};\n  }\n  static X compress2(const\
    \ X& L, const X& R) {\n    assert(L.type == 1 && R.type == 1 && L.t == R.s);\n\
    \    X ANS = {1, L.s, R.t};\n  }\n  static X compress3(const X& L, const X& R)\
    \ {\n    assert(L.type == 1 && R.type == 0 && L.t == R.s);\n    X ANS = {1, L.s,\
    \ L.t};\n  }\n};\n*/\n\ntemplate <typename TREE, typename TREE_DP>\nstruct Dynamic_Rerooting_Tree_Dp\
    \ {\n  using X = typename TREE_DP::value_type;\n  Static_TopTree<TREE> STT;\n\
    \  vc<pair<X, X>> dp;\n\n  template <typename F>\n  Dynamic_Rerooting_Tree_Dp(TREE&\
    \ tree, F f) : STT(tree) {\n    assert(tree.V[0] == 0); // \u3055\u307C\u308A\n\
    \    int N = tree.N;\n    dp.resize(2 * N - 1);\n    FOR(v, N) {\n      dp[v]\
    \ = f(v);\n      assert(dp[v].fi.type == 0 && dp[v].se.type == 1);\n      assert(dp[v].fi.s\
    \ == STT.tree.parent[v] && dp[v].fi.t == v);\n      assert(dp[v].se.t == STT.tree.parent[v]\
    \ && dp[v].se.s == v);\n    }\n    FOR(i, N, 2 * N - 1) update(i);\n  }\n\n  //\
    \ v \u3068\u89AA\u3092\u7D50\u3076\u8FBA. \u89AA\u304C virtual / \u5B50\u304C\
    \ virtual\n  void set(int v, pair<X, X> x) {\n    dp[v] = x;\n    assert(dp[v].fi.type\
    \ == 0 && dp[v].se.type == 1);\n    assert(dp[v].fi.s == STT.tree.parent[v] &&\
    \ dp[v].fi.t == v);\n    assert(dp[v].se.t == STT.tree.parent[v] && dp[v].se.s\
    \ == v);\n    for (int i = STT.par[v]; i != -1; i = STT.par[i]) { update(i); }\n\
    \  }\n\n  X prod_all(int v) {\n    int i = v;\n    X a = dp[i].se, b, c;\n   \
    \ b.type = c.type = -1;\n    while (1) {\n      int p = STT.par[i];\n      if\
    \ (p == -1) break;\n      int l = STT.lch[p], r = STT.rch[p];\n      if (STT.is_compress[p])\
    \ {\n        if (l == i) {\n          b = (b.type == -1 ? dp[r].fi : TREE_DP::compress(b,\
    \ dp[r].fi));\n        } else {\n          a = (a.type == -1 ? dp[l].se : TREE_DP::compress2(a,\
    \ dp[l].se));\n        }\n      } else {\n        if (STT.lch[p] == i) {\n   \
    \       if (a.type == -1) {\n            b = (b.type == -1 ? dp[r].fi : TREE_DP::rake(b,\
    \ dp[r].fi));\n          } else {\n            a = TREE_DP::compress3(a, dp[r].fi);\n\
    \          }\n        } else {\n          if (a.type == -1) {\n            c =\
    \ TREE_DP::compress3(c, b);\n            a.type = -1;\n            b = dp[l].fi;\n\
    \          } else {\n            a = (b.type == -1 ? a : TREE_DP::rake2(a, b));\n\
    \            c = (c.type == -1 ? a : TREE_DP::compress2(c, a));\n            a.type\
    \ = -1;\n            b = dp[l].fi;\n          }\n        }\n      }\n      i =\
    \ p;\n    }\n    a = (b.type == -1 ? a : TREE_DP::rake2(a, b));\n    return (c.type\
    \ == -1 ? a : TREE_DP::compress2(c, a));\n  }\n\nprivate:\n  inline void update(int\
    \ i) {\n    auto& [L1, L2] = dp[STT.lch[i]];\n    auto& [R1, R2] = dp[STT.rch[i]];\n\
    \    if (STT.is_compress[i]) {\n      dp[i] = {TREE_DP::compress(L1, R1), TREE_DP::compress2(R2,\
    \ L2)};\n    } else {\n      dp[i] = {TREE_DP::rake(L1, R1), TREE_DP::compress3(L2,\
    \ R1)};\n    }\n  }\n};\n"
  code: "#include \"graph/ds/static_toptree.hpp\"\n\n/*\nstruct Data {\n  // type,\
    \ s, t \u306F\u5FC5\u305A\u5B9A\u7FA9\u3059\u308B. \uFF08\u7D4C\u9A13\u4E0A\u3069\
    \u3046\u305B\u30C7\u30D0\u30C3\u30B0\u3067\u5FC5\u8981\u306B\u306A\u308B\uFF09\
    . s \u304C\u6839.\n  // type==0: s\u304C virtual. type==1: t \u304C virtual.\n\
    \  int type, s, t;\n};\n\nstruct TREE_DP {\n  using value_type = Data;\n  using\
    \ X = value_type;\n\n  static X rake(const X& L, const X& R) {\n    assert(L.type\
    \ == 0 && R.type == 0 && L.s == R.s);\n    X ANS = {0, L.s, L.t};\n  }\n  static\
    \ X rake2(const X& L, const X& R) {\n    assert(L.type == 1 && R.type == 0 &&\
    \ L.s == R.s);\n    X ANS = {1, L.s, L.t};\n  }\n  static X compress(const X&\
    \ L, const X& R) {\n    assert(L.type == 0 && R.type == 0 && L.t == R.s);\n  \
    \  X ANS = {0, L.s, R.t};\n  }\n  static X compress2(const X& L, const X& R) {\n\
    \    assert(L.type == 1 && R.type == 1 && L.t == R.s);\n    X ANS = {1, L.s, R.t};\n\
    \  }\n  static X compress3(const X& L, const X& R) {\n    assert(L.type == 1 &&\
    \ R.type == 0 && L.t == R.s);\n    X ANS = {1, L.s, L.t};\n  }\n};\n*/\n\ntemplate\
    \ <typename TREE, typename TREE_DP>\nstruct Dynamic_Rerooting_Tree_Dp {\n  using\
    \ X = typename TREE_DP::value_type;\n  Static_TopTree<TREE> STT;\n  vc<pair<X,\
    \ X>> dp;\n\n  template <typename F>\n  Dynamic_Rerooting_Tree_Dp(TREE& tree,\
    \ F f) : STT(tree) {\n    assert(tree.V[0] == 0); // \u3055\u307C\u308A\n    int\
    \ N = tree.N;\n    dp.resize(2 * N - 1);\n    FOR(v, N) {\n      dp[v] = f(v);\n\
    \      assert(dp[v].fi.type == 0 && dp[v].se.type == 1);\n      assert(dp[v].fi.s\
    \ == STT.tree.parent[v] && dp[v].fi.t == v);\n      assert(dp[v].se.t == STT.tree.parent[v]\
    \ && dp[v].se.s == v);\n    }\n    FOR(i, N, 2 * N - 1) update(i);\n  }\n\n  //\
    \ v \u3068\u89AA\u3092\u7D50\u3076\u8FBA. \u89AA\u304C virtual / \u5B50\u304C\
    \ virtual\n  void set(int v, pair<X, X> x) {\n    dp[v] = x;\n    assert(dp[v].fi.type\
    \ == 0 && dp[v].se.type == 1);\n    assert(dp[v].fi.s == STT.tree.parent[v] &&\
    \ dp[v].fi.t == v);\n    assert(dp[v].se.t == STT.tree.parent[v] && dp[v].se.s\
    \ == v);\n    for (int i = STT.par[v]; i != -1; i = STT.par[i]) { update(i); }\n\
    \  }\n\n  X prod_all(int v) {\n    int i = v;\n    X a = dp[i].se, b, c;\n   \
    \ b.type = c.type = -1;\n    while (1) {\n      int p = STT.par[i];\n      if\
    \ (p == -1) break;\n      int l = STT.lch[p], r = STT.rch[p];\n      if (STT.is_compress[p])\
    \ {\n        if (l == i) {\n          b = (b.type == -1 ? dp[r].fi : TREE_DP::compress(b,\
    \ dp[r].fi));\n        } else {\n          a = (a.type == -1 ? dp[l].se : TREE_DP::compress2(a,\
    \ dp[l].se));\n        }\n      } else {\n        if (STT.lch[p] == i) {\n   \
    \       if (a.type == -1) {\n            b = (b.type == -1 ? dp[r].fi : TREE_DP::rake(b,\
    \ dp[r].fi));\n          } else {\n            a = TREE_DP::compress3(a, dp[r].fi);\n\
    \          }\n        } else {\n          if (a.type == -1) {\n            c =\
    \ TREE_DP::compress3(c, b);\n            a.type = -1;\n            b = dp[l].fi;\n\
    \          } else {\n            a = (b.type == -1 ? a : TREE_DP::rake2(a, b));\n\
    \            c = (c.type == -1 ? a : TREE_DP::compress2(c, a));\n            a.type\
    \ = -1;\n            b = dp[l].fi;\n          }\n        }\n      }\n      i =\
    \ p;\n    }\n    a = (b.type == -1 ? a : TREE_DP::rake2(a, b));\n    return (c.type\
    \ == -1 ? a : TREE_DP::compress2(c, a));\n  }\n\nprivate:\n  inline void update(int\
    \ i) {\n    auto& [L1, L2] = dp[STT.lch[i]];\n    auto& [R1, R2] = dp[STT.rch[i]];\n\
    \    if (STT.is_compress[i]) {\n      dp[i] = {TREE_DP::compress(L1, R1), TREE_DP::compress2(R2,\
    \ L2)};\n    } else {\n      dp[i] = {TREE_DP::rake(L1, R1), TREE_DP::compress3(L2,\
    \ R1)};\n    }\n  }\n};\n"
  dependsOn:
  - graph/ds/static_toptree.hpp
  - graph/tree.hpp
  - graph/base.hpp
  - ds/hashmap.hpp
  isVerificationFile: false
  path: graph/ds/dynamic_rerooting_tree_dp.hpp
  requiredBy: []
  timestamp: '2025-05-05 02:10:07+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/2_library_checker/tree/point_set_tree_path_composite_sum.test.cpp
documentation_of: graph/ds/dynamic_rerooting_tree_dp.hpp
layout: document
redirect_from:
- /library/graph/ds/dynamic_rerooting_tree_dp.hpp
- /library/graph/ds/dynamic_rerooting_tree_dp.hpp.html
title: graph/ds/dynamic_rerooting_tree_dp.hpp
---
