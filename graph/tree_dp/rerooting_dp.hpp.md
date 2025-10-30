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
    path: graph/tree.hpp
    title: graph/tree.hpp
  _extendedRequiredBy:
  - icon: ':warning:'
    path: graph/tree_dp/subtree_depth_sum.hpp
    title: graph/tree_dp/subtree_depth_sum.hpp
  - icon: ':warning:'
    path: graph/tree_dp/subtree_diameter.hpp
    title: graph/tree_dp/subtree_diameter.hpp
  - icon: ':heavy_check_mark:'
    path: graph/tree_dp/subtree_hash.hpp
    title: graph/tree_dp/subtree_hash.hpp
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/1_mytest/enumerate_unlabeled_tree.test.cpp
    title: test/1_mytest/enumerate_unlabeled_tree.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/2_library_checker/graph/classify_tree.test.cpp
    title: test/2_library_checker/graph/classify_tree.test.cpp
  - icon: ':x:'
    path: test/2_library_checker/tree/rerooting_dp.test.cpp
    title: test/2_library_checker/tree/rerooting_dp.test.cpp
  - icon: ':x:'
    path: test/3_yukicoder/1295.test.cpp
    title: test/3_yukicoder/1295.test.cpp
  - icon: ':x:'
    path: test/3_yukicoder/1418.test.cpp
    title: test/3_yukicoder/1418.test.cpp
  - icon: ':x:'
    path: test/3_yukicoder/1494.test.cpp
    title: test/3_yukicoder/1494.test.cpp
  - icon: ':x:'
    path: test/3_yukicoder/1718.test.cpp
    title: test/3_yukicoder/1718.test.cpp
  - icon: ':x:'
    path: test/3_yukicoder/1976.test.cpp
    title: test/3_yukicoder/1976.test.cpp
  - icon: ':x:'
    path: test/3_yukicoder/2360.test.cpp
    title: test/3_yukicoder/2360.test.cpp
  _isVerificationFailed: true
  _pathExtension: hpp
  _verificationStatusIcon: ':question:'
  attributes:
    links: []
  bundledCode: "#line 2 \"ds/hashmap.hpp\"\n\r\n// u64 -> Val\r\ntemplate <typename\
    \ Val>\r\nstruct HashMap {\r\n  // n \u306F\u5165\u308C\u305F\u3044\u3082\u306E\
    \u306E\u500B\u6570\u3067 ok\r\n  HashMap(u32 n = 0) { build(n); }\r\n  void build(u32\
    \ n) {\r\n    u32 k = 8;\r\n    while (k < n * 2) k *= 2;\r\n    cap = k / 2,\
    \ mask = k - 1;\r\n    key.resize(k), val.resize(k), used.assign(k, 0);\r\n  }\r\
    \n\r\n  // size \u3092\u4FDD\u3063\u305F\u307E\u307E. size=0 \u306B\u3059\u308B\
    \u3068\u304D\u306F build \u3059\u308B\u3053\u3068.\r\n  void clear() {\r\n   \
    \ used.assign(len(used), 0);\r\n    cap = (mask + 1) / 2;\r\n  }\r\n  int size()\
    \ { return len(used) / 2 - cap; }\r\n\r\n  int index(const u64& k) {\r\n    int\
    \ i = 0;\r\n    for (i = hash(k); used[i] && key[i] != k; i = (i + 1) & mask)\
    \ {}\r\n    return i;\r\n  }\r\n\r\n  Val& operator[](const u64& k) {\r\n    if\
    \ (cap == 0) extend();\r\n    int i = index(k);\r\n    if (!used[i]) { used[i]\
    \ = 1, key[i] = k, val[i] = Val{}, --cap; }\r\n    return val[i];\r\n  }\r\n\r\
    \n  Val get(const u64& k, Val default_value) {\r\n    int i = index(k);\r\n  \
    \  return (used[i] ? val[i] : default_value);\r\n  }\r\n\r\n  bool count(const\
    \ u64& k) {\r\n    int i = index(k);\r\n    return used[i] && key[i] == k;\r\n\
    \  }\r\n\r\n  // f(key, val)\r\n  template <typename F>\r\n  void enumerate_all(F\
    \ f) {\r\n    FOR(i, len(used)) if (used[i]) f(key[i], val[i]);\r\n  }\r\n\r\n\
    private:\r\n  u32 cap, mask;\r\n  vc<u64> key;\r\n  vc<Val> val;\r\n  vc<bool>\
    \ used;\r\n\r\n  u64 hash(u64 x) {\r\n    static const u64 FIXED_RANDOM = std::chrono::steady_clock::now().time_since_epoch().count();\r\
    \n    x += FIXED_RANDOM;\r\n    x = (x ^ (x >> 30)) * 0xbf58476d1ce4e5b9;\r\n\
    \    x = (x ^ (x >> 27)) * 0x94d049bb133111eb;\r\n    return (x ^ (x >> 31)) &\
    \ mask;\r\n  }\r\n\r\n  void extend() {\r\n    vc<pair<u64, Val>> dat;\r\n   \
    \ dat.reserve(len(used) / 2 - cap);\r\n    FOR(i, len(used)) {\r\n      if (used[i])\
    \ dat.eb(key[i], val[i]);\r\n    }\r\n    build(2 * len(dat));\r\n    for (auto&\
    \ [a, b]: dat) (*this)[a] = b;\r\n  }\r\n};\n#line 3 \"graph/base.hpp\"\n\ntemplate\
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
    #line 2 \"graph/tree.hpp\"\n\r\n#line 4 \"graph/tree.hpp\"\n\r\n// HLD euler tour\
    \ \u3092\u3068\u3063\u3066\u3044\u308D\u3044\u308D\u3002\r\ntemplate <typename\
    \ GT>\r\nstruct Tree {\r\n  using Graph_type = GT;\r\n  GT &G;\r\n  using WT =\
    \ typename GT::cost_type;\r\n  int N;\r\n  vector<int> LID, RID, head, V, parent,\
    \ VtoE;\r\n  vc<int> depth;\r\n  vc<WT> depth_weighted;\r\n\r\n  Tree(GT &G, int\
    \ r = 0, bool hld = 1) : G(G) { build(r, hld); }\r\n\r\n  void build(int r = 0,\
    \ bool hld = 1) {\r\n    if (r == -1) return; // build \u3092\u9045\u5EF6\u3057\
    \u305F\u3044\u3068\u304D\r\n    N = G.N;\r\n    LID.assign(N, -1), RID.assign(N,\
    \ -1), head.assign(N, r);\r\n    V.assign(N, -1), parent.assign(N, -1), VtoE.assign(N,\
    \ -1);\r\n    depth.assign(N, -1), depth_weighted.assign(N, 0);\r\n    assert(G.is_prepared());\r\
    \n    int t1 = 0;\r\n    dfs_sz(r, -1, hld);\r\n    dfs_hld(r, t1);\r\n  }\r\n\
    \r\n  void dfs_sz(int v, int p, bool hld) {\r\n    auto &sz = RID;\r\n    parent[v]\
    \ = p;\r\n    depth[v] = (p == -1 ? 0 : depth[p] + 1);\r\n    sz[v] = 1;\r\n \
    \   int l = G.indptr[v], r = G.indptr[v + 1];\r\n    auto &csr = G.csr_edges;\r\
    \n    // \u4F7F\u3046\u8FBA\u304C\u3042\u308C\u3070\u5148\u982D\u306B\u3059\u308B\
    \r\n    for (int i = r - 2; i >= l; --i) {\r\n      if (hld && depth[csr[i + 1].to]\
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
    #line 4 \"graph/tree_dp/rerooting_dp.hpp\"\n\r\ntemplate <typename TREE, typename\
    \ Data>\r\nstruct Rerooting_dp {\r\n  static_assert(!TREE::Graph_type::is_directed);\r\
    \n  TREE& tree;\r\n  vc<Data> dp_1; // \u8FBA pv \u306B\u5BFE\u3057\u3066\u3001\
    \u90E8\u5206\u6728 v\r\n  vc<Data> dp_2; // \u8FBA pv \u306B\u5BFE\u3057\u3066\
    \u3001\u90E8\u5206\u6728 p\r\n  vc<Data> dp;   // full tree\r\n\r\n  template\
    \ <typename F1, typename F2, typename F3>\r\n  Rerooting_dp(TREE& tree, F1 f_ee,\
    \ F2 f_ev, F3 f_ve, const Data unit) : tree(tree) {\r\n    build(f_ee, f_ev, f_ve,\
    \ unit);\r\n  }\r\n\r\n  // v \u3092\u6839\u3068\u3057\u305F\u3068\u304D\u306E\
    \ full tree\r\n  Data operator[](int v) { return dp[v]; }\r\n\r\n  // root \u3092\
    \u6839\u3068\u3057\u305F\u3068\u304D\u306E\u90E8\u5206\u6728 v\r\n  Data get(int\
    \ v, int root) {\r\n    if (root == v) return dp[v];\r\n    if (!tree.in_subtree(root,\
    \ v)) { return dp_1[v]; }\r\n    int w = tree.jump(v, root, 1);\r\n    return\
    \ dp_2[w];\r\n  }\r\n\r\n  template <typename F1, typename F2, typename F3>\r\n\
    \  void build(F1 f_ee, F2 f_ev, F3 f_ve, const Data unit) {\r\n    int N = tree.N;\r\
    \n    // dp1: subtree\r\n    dp_1.assign(N, unit);\r\n    FOR_R(i, N) {\r\n  \
    \    int v = tree.V[i];\r\n      for (auto&& e: tree.G[v]) {\r\n        if (e.to\
    \ == tree.parent[v]) continue;\r\n        dp_1[v] = f_ee(dp_1[v], f_ve(dp_1[e.to],\
    \ e));\r\n      }\r\n      dp_1[v] = f_ev(dp_1[v], v);\r\n    }\r\n\r\n    //\
    \ dp2[v]: subtree of p, rooted at v\r\n    dp_2.assign(N, unit);\r\n    // dp[v]:\
    \ fulltree, rooted at v\r\n    dp.assign(N, unit);\r\n    FOR(i, N) {\r\n    \
    \  int p = tree.V[i];\r\n      vc<int> ch;\r\n      vc<Data> ch_data;\r\n    \
    \  Data x = unit;\r\n      for (auto&& e: tree.G[p]) {\r\n        if (e.to ==\
    \ tree.parent[p]) {\r\n          x = f_ve(dp_2[p], e);\r\n        } else {\r\n\
    \          ch.eb(e.to);\r\n          ch_data.eb(f_ve(dp_1[e.to], e));\r\n    \
    \    }\r\n      }\r\n      int n = len(ch);\r\n      if (!n) {\r\n        dp[p]\
    \ = f_ev(x, p);\r\n        continue;\r\n      }\r\n      vc<Data> prod_left(n,\
    \ x);\r\n      FOR(i, n - 1) prod_left[i + 1] = f_ee(prod_left[i], ch_data[i]);\r\
    \n      Data prod_right = unit;\r\n      FOR_R(i, n) {\r\n        dp_2[ch[i]]\
    \ = f_ev(f_ee(prod_left[i], prod_right), p);\r\n        prod_right = f_ee(prod_right,\
    \ ch_data[i]);\r\n      }\r\n      dp[p] = f_ev(f_ee(x, prod_right), p);\r\n \
    \   }\r\n  }\r\n};\r\n"
  code: "#pragma once\r\n#include \"graph/base.hpp\"\r\n#include \"graph/tree.hpp\"\
    \r\n\r\ntemplate <typename TREE, typename Data>\r\nstruct Rerooting_dp {\r\n \
    \ static_assert(!TREE::Graph_type::is_directed);\r\n  TREE& tree;\r\n  vc<Data>\
    \ dp_1; // \u8FBA pv \u306B\u5BFE\u3057\u3066\u3001\u90E8\u5206\u6728 v\r\n  vc<Data>\
    \ dp_2; // \u8FBA pv \u306B\u5BFE\u3057\u3066\u3001\u90E8\u5206\u6728 p\r\n  vc<Data>\
    \ dp;   // full tree\r\n\r\n  template <typename F1, typename F2, typename F3>\r\
    \n  Rerooting_dp(TREE& tree, F1 f_ee, F2 f_ev, F3 f_ve, const Data unit) : tree(tree)\
    \ {\r\n    build(f_ee, f_ev, f_ve, unit);\r\n  }\r\n\r\n  // v \u3092\u6839\u3068\
    \u3057\u305F\u3068\u304D\u306E full tree\r\n  Data operator[](int v) { return\
    \ dp[v]; }\r\n\r\n  // root \u3092\u6839\u3068\u3057\u305F\u3068\u304D\u306E\u90E8\
    \u5206\u6728 v\r\n  Data get(int v, int root) {\r\n    if (root == v) return dp[v];\r\
    \n    if (!tree.in_subtree(root, v)) { return dp_1[v]; }\r\n    int w = tree.jump(v,\
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
    \   }\r\n  }\r\n};\r\n"
  dependsOn:
  - graph/base.hpp
  - ds/hashmap.hpp
  - graph/tree.hpp
  isVerificationFile: false
  path: graph/tree_dp/rerooting_dp.hpp
  requiredBy:
  - graph/tree_dp/subtree_diameter.hpp
  - graph/tree_dp/subtree_hash.hpp
  - graph/tree_dp/subtree_depth_sum.hpp
  timestamp: '2025-05-05 02:10:07+09:00'
  verificationStatus: LIBRARY_SOME_WA
  verifiedWith:
  - test/3_yukicoder/1976.test.cpp
  - test/3_yukicoder/1418.test.cpp
  - test/3_yukicoder/1494.test.cpp
  - test/3_yukicoder/2360.test.cpp
  - test/3_yukicoder/1718.test.cpp
  - test/3_yukicoder/1295.test.cpp
  - test/1_mytest/enumerate_unlabeled_tree.test.cpp
  - test/2_library_checker/graph/classify_tree.test.cpp
  - test/2_library_checker/tree/rerooting_dp.test.cpp
documentation_of: graph/tree_dp/rerooting_dp.hpp
layout: document
redirect_from:
- /library/graph/tree_dp/rerooting_dp.hpp
- /library/graph/tree_dp/rerooting_dp.hpp.html
title: graph/tree_dp/rerooting_dp.hpp
---
