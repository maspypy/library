---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: ds/hashmap.hpp
    title: ds/hashmap.hpp
  - icon: ':heavy_check_mark:'
    path: graph/base.hpp
    title: graph/base.hpp
  - icon: ':heavy_check_mark:'
    path: graph/ds/static_toptree.hpp
    title: graph/ds/static_toptree.hpp
  - icon: ':heavy_check_mark:'
    path: graph/tree.hpp
    title: graph/tree.hpp
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/2_library_checker/tree/point_set_tree_path_composite_sum_fixed_root.test.cpp
    title: test/2_library_checker/tree/point_set_tree_path_composite_sum_fixed_root.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links:
    - https://codeforces.com/contest/1172/problem/E
    - https://codeforces.com/contest/1942/problem/H
  bundledCode: "#line 1 \"graph/tree.hpp\"\n\n#line 1 \"ds/hashmap.hpp\"\n\n// u64\
    \ -> Val\ntemplate <typename Val>\nstruct HashMap {\n  // n \u306F\u5165\u308C\
    \u305F\u3044\u3082\u306E\u306E\u500B\u6570\u3067 ok\n  HashMap(u32 n = 0) { build(n);\
    \ }\n  void build(u32 n) {\n    u32 k = 8;\n    while (k < n * 2) k *= 2;\n  \
    \  cap = k / 2, mask = k - 1;\n    key.resize(k), val.resize(k), used.assign(k,\
    \ 0);\n  }\n\n  // size \u3092\u4FDD\u3063\u305F\u307E\u307E. size=0 \u306B\u3059\
    \u308B\u3068\u304D\u306F build \u3059\u308B\u3053\u3068.\n  void clear() {\n \
    \   used.assign(len(used), 0);\n    cap = (mask + 1) / 2;\n  }\n  int size() {\
    \ return len(used) / 2 - cap; }\n\n  int index(const u64& k) {\n    int i = 0;\n\
    \    for (i = hash(k); used[i] && key[i] != k; i = (i + 1) & mask) {}\n    return\
    \ i;\n  }\n\n  Val& operator[](const u64& k) {\n    if (cap == 0) extend();\n\
    \    int i = index(k);\n    if (!used[i]) { used[i] = 1, key[i] = k, val[i] =\
    \ Val{}, --cap; }\n    return val[i];\n  }\n\n  Val get(const u64& k, Val default_value)\
    \ {\n    int i = index(k);\n    return (used[i] ? val[i] : default_value);\n \
    \ }\n\n  bool count(const u64& k) {\n    int i = index(k);\n    return used[i]\
    \ && key[i] == k;\n  }\n\n  // f(key, val)\n  template <typename F>\n  void enumerate_all(F\
    \ f) {\n    FOR(i, len(used)) if (used[i]) f(key[i], val[i]);\n  }\n\nprivate:\n\
    \  u32 cap, mask;\n  vc<u64> key;\n  vc<Val> val;\n  vc<bool> used;\n\n  u64 hash(u64\
    \ x) {\n    static const u64 FIXED_RANDOM = std::chrono::steady_clock::now().time_since_epoch().count();\n\
    \    x += FIXED_RANDOM;\n    x = (x ^ (x >> 30)) * 0xbf58476d1ce4e5b9;\n    x\
    \ = (x ^ (x >> 27)) * 0x94d049bb133111eb;\n    return (x ^ (x >> 31)) & mask;\n\
    \  }\n\n  void extend() {\n    vc<pair<u64, Val>> dat;\n    dat.reserve(len(used)\
    \ / 2 - cap);\n    FOR(i, len(used)) {\n      if (used[i]) dat.eb(key[i], val[i]);\n\
    \    }\n    build(2 * len(dat));\n    for (auto& [a, b]: dat) (*this)[a] = b;\n\
    \  }\n};\n#line 2 \"graph/base.hpp\"\n\ntemplate <typename T>\nstruct Edge {\n\
    \  int frm, to;\n  T cost;\n  int id;\n};\n\ntemplate <typename T = int, bool\
    \ directed = false>\nstruct Graph {\n  static constexpr bool is_directed = directed;\n\
    \  int N, M;\n  using cost_type = T;\n  using edge_type = Edge<T>;\n  vector<edge_type>\
    \ edges;\n  vector<int> indptr;\n  vector<edge_type> csr_edges;\n  vc<int> vc_deg,\
    \ vc_indeg, vc_outdeg;\n  HashMap<int> MP_FOR_EID;\n  bool prepared;\n\n  class\
    \ OutgoingEdges {\n   public:\n    OutgoingEdges(const Graph* G, int l, int r)\
    \ : G(G), l(l), r(r) {}\n\n    const edge_type* begin() const {\n      if (l ==\
    \ r) {\n        return 0;\n      }\n      return &G->csr_edges[l];\n    }\n\n\
    \    const edge_type* end() const {\n      if (l == r) {\n        return 0;\n\
    \      }\n      return &G->csr_edges[r];\n    }\n\n   private:\n    const Graph*\
    \ G;\n    int l, r;\n  };\n\n  bool is_prepared() { return prepared; }\n\n  Graph()\
    \ : N(0), M(0), prepared(0) {}\n  Graph(int N) : N(N), M(0), prepared(0) {}\n\n\
    \  void build(int n) {\n    N = n, M = 0;\n    prepared = 0;\n    edges.clear();\n\
    \    indptr.clear();\n    csr_edges.clear();\n    vc_deg.clear();\n    vc_indeg.clear();\n\
    \    vc_outdeg.clear();\n    MP_FOR_EID.clear();\n  }\n\n  void add(int frm, int\
    \ to, T cost = 1, int i = -1) {\n    assert(!prepared);\n    assert(0 <= frm &&\
    \ frm < N && 0 <= to && to < N);\n    if (i == -1) i = M;\n    auto e = edge_type({frm,\
    \ to, cost, i});\n    edges.eb(e);\n    ++M;\n  }\n\n#ifdef FASTIO\n  // wt, off\n\
    \  void read_tree(bool wt = false, int off = 1) { read_graph(N - 1, wt, off);\
    \ }\n\n  void read_graph(int M, bool wt = false, int off = 1) {\n    for (int\
    \ m = 0; m < M; ++m) {\n      INT(a, b);\n      a -= off, b -= off;\n      if\
    \ (!wt) {\n        add(a, b);\n      } else {\n        T c;\n        read(c);\n\
    \        add(a, b, c);\n      }\n    }\n    build();\n  }\n#endif\n\n  void build()\
    \ {\n    assert(!prepared);\n    prepared = true;\n    indptr.assign(N + 1, 0);\n\
    \    for (auto&& e : edges) {\n      indptr[e.frm + 1]++;\n      if (!directed)\
    \ indptr[e.to + 1]++;\n    }\n    for (int v = 0; v < N; ++v) {\n      indptr[v\
    \ + 1] += indptr[v];\n    }\n    auto counter = indptr;\n    csr_edges.resize(indptr.back()\
    \ + 1);\n    for (auto&& e : edges) {\n      csr_edges[counter[e.frm]++] = e;\n\
    \      if (!directed)\n        csr_edges[counter[e.to]++] = edge_type({e.to, e.frm,\
    \ e.cost, e.id});\n    }\n  }\n\n  OutgoingEdges operator[](int v) const {\n \
    \   assert(prepared);\n    return {this, indptr[v], indptr[v + 1]};\n  }\n\n \
    \ vc<int> deg_array() {\n    if (vc_deg.empty()) calc_deg();\n    return vc_deg;\n\
    \  }\n\n  pair<vc<int>, vc<int>> deg_array_inout() {\n    if (vc_indeg.empty())\
    \ calc_deg_inout();\n    return {vc_indeg, vc_outdeg};\n  }\n\n  int deg(int v)\
    \ {\n    if (vc_deg.empty()) calc_deg();\n    return vc_deg[v];\n  }\n\n  int\
    \ in_deg(int v) {\n    if (vc_indeg.empty()) calc_deg_inout();\n    return vc_indeg[v];\n\
    \  }\n\n  int out_deg(int v) {\n    if (vc_outdeg.empty()) calc_deg_inout();\n\
    \    return vc_outdeg[v];\n  }\n\n#ifdef FASTIO\n  void debug() {\n#ifdef LOCAL\n\
    \    print(\"Graph\");\n    if (!prepared) {\n      print(\"frm to cost id\");\n\
    \      for (auto&& e : edges) print(e.frm, e.to, e.cost, e.id);\n    } else {\n\
    \      print(\"indptr\", indptr);\n      print(\"frm to cost id\");\n      FOR(v,\
    \ N) for (auto&& e : (*this)[v]) print(e.frm, e.to, e.cost, e.id);\n    }\n  \
    \  flush();\n#endif\n  }\n#endif\n\n  vc<int> new_idx;\n  vc<bool> used_e;\n\n\
    \  // G \u306B\u304A\u3051\u308B\u9802\u70B9 V[i] \u304C\u3001\u65B0\u3057\u3044\
    \u30B0\u30E9\u30D5\u3067 i \u306B\u306A\u308B\u3088\u3046\u306B\u3059\u308B\n\
    \  // {G, es}\n  // sum(deg(v)) \u306E\u8A08\u7B97\u91CF\u306B\u306A\u3063\u3066\
    \u3044\u3066\u3001\n  // \u65B0\u3057\u3044\u30B0\u30E9\u30D5\u306E n+m \u3088\
    \u308A\u5927\u304D\u3044\u53EF\u80FD\u6027\u304C\u3042\u308B\u306E\u3067\u6CE8\
    \u610F\n  Graph<T, directed> rearrange(vc<int> V, bool keep_eid = 0) {\n    if\
    \ (len(new_idx) != N) new_idx.assign(N, -1);\n    int n = len(V);\n    FOR(i,\
    \ n) new_idx[V[i]] = i;\n    Graph<T, directed> G(n);\n    vc<int> history;\n\
    \    FOR(i, n) {\n      for (auto&& e : (*this)[V[i]]) {\n        if (len(used_e)\
    \ <= e.id) used_e.resize(e.id + 1);\n        if (used_e[e.id]) continue;\n   \
    \     int a = e.frm, b = e.to;\n        if (new_idx[a] != -1 && new_idx[b] !=\
    \ -1) {\n          history.eb(e.id);\n          used_e[e.id] = 1;\n          int\
    \ eid = (keep_eid ? e.id : -1);\n          G.add(new_idx[a], new_idx[b], e.cost,\
    \ eid);\n        }\n      }\n    }\n    FOR(i, n) new_idx[V[i]] = -1;\n    for\
    \ (auto&& eid : history) used_e[eid] = 0;\n    G.build();\n    return G;\n  }\n\
    \n  Graph<T, true> to_directed_tree(int root = -1) {\n    if (root == -1) root\
    \ = 0;\n    assert(!is_directed && prepared && M == N - 1);\n    Graph<T, true>\
    \ G1(N);\n    vc<int> par(N, -1);\n    auto dfs = [&](auto& dfs, int v) -> void\
    \ {\n      for (auto& e : (*this)[v]) {\n        if (e.to == par[v]) continue;\n\
    \        par[e.to] = v, dfs(dfs, e.to);\n      }\n    };\n    dfs(dfs, root);\n\
    \    for (auto& e : edges) {\n      int a = e.frm, b = e.to;\n      if (par[a]\
    \ == b) swap(a, b);\n      assert(par[b] == a);\n      G1.add(a, b, e.cost);\n\
    \    }\n    G1.build();\n    return G1;\n  }\n\n  int get_eid(u64 a, u64 b) {\n\
    \    if (len(MP_FOR_EID) == 0) {\n      MP_FOR_EID.build(N - 1);\n      for (auto&\
    \ e : edges) {\n        u64 a = e.frm, b = e.to;\n        u64 k = to_eid_key(a,\
    \ b);\n        MP_FOR_EID[k] = e.id;\n      }\n    }\n    return MP_FOR_EID.get(to_eid_key(a,\
    \ b), -1);\n  }\n\n  u64 to_eid_key(u64 a, u64 b) {\n    if (!directed && a >\
    \ b) swap(a, b);\n    return N * a + b;\n  }\n\n private:\n  void calc_deg() {\n\
    \    assert(vc_deg.empty());\n    vc_deg.resize(N);\n    for (auto&& e : edges)\
    \ vc_deg[e.frm]++, vc_deg[e.to]++;\n  }\n\n  void calc_deg_inout() {\n    assert(vc_indeg.empty());\n\
    \    vc_indeg.resize(N);\n    vc_outdeg.resize(N);\n    for (auto&& e : edges)\
    \ {\n      vc_indeg[e.to]++, vc_outdeg[e.frm]++;\n    }\n  }\n};\n#line 3 \"graph/tree.hpp\"\
    \n\n// HLD euler tour \u3092\u3068\u3063\u3066\u3044\u308D\u3044\u308D\n// HLD=false:\
    \ \u5165\u529B\u8FBA\u9806\u3067 preorder\ntemplate <typename GT, bool HLD = true>\n\
    struct Tree {\n  using Graph_type = GT;\n  GT &G;\n  using WT = typename GT::cost_type;\n\
    \  int N;\n  vector<int> LID, RID, head, V, parent, VtoE;\n  vc<int> depth;\n\
    \  vc<WT> depth_weighted;\n  vc<int> memo_tail;\n\n  Tree(GT &G, int r = 0) :\
    \ G(G) { build(r); }\n\n  void build(int r = 0) {\n    if (r == -1) return;  //\
    \ build \u3092\u9045\u5EF6\u3057\u305F\u3044\u3068\u304D\n    if constexpr (!HLD)\n\
    \      build_simple(r);\n    else\n      build_HLD(r);\n  }\n\n  vc<int> heavy_path_at(int\
    \ v) {\n    static_assert(HLD);\n    assert(head[v] == v);\n    int k = LID[v];\n\
    \    vc<int> P;\n    while (k < N && head[V[k]] == v) P.eb(V[k++]);\n    return\
    \ P;\n  }\n\n  int heavy_child(int v) {\n    static_assert(HLD);\n    if (RID[v]\
    \ == LID[v] + 1) return -1;\n    return V[LID[v] + 1];\n  }\n\n  int tail(int\
    \ v) {\n    static_assert(HLD);\n    if (memo_tail.empty()) {\n      memo_tail.assign(N,\
    \ -1);\n      FOR_R(i, N) {\n        int v = V[i];\n        int w = heavy_child(v);\n\
    \        memo_tail[v] = (w == -1 ? v : memo_tail[w]);\n      }\n    }\n    return\
    \ memo_tail[v];\n  }\n\n  int e_to_v(int eid) {\n    auto e = G.edges[eid];\n\
    \    return (parent[e.frm] == e.to ? e.frm : e.to);\n  }\n  int v_to_e(int v)\
    \ { return VtoE[v]; }\n  int get_eid(int u, int v) {\n    if (parent[u] != v)\
    \ swap(u, v);\n    assert(parent[u] == v);\n    return VtoE[u];\n  }\n\n  int\
    \ ELID(int v) { return 2 * LID[v] - depth[v]; }\n  int ERID(int v) { return 2\
    \ * RID[v] - depth[v] - 1; }\n\n  // \u76EE\u6A19\u5730\u70B9\u3078\u9032\u3080\
    \u500B\u6570\u304C k\n  int LA(int v, int k) {\n    static_assert(HLD);\n    assert(k\
    \ <= depth[v]);\n    while (1) {\n      int u = head[v];\n      if (LID[v] - k\
    \ >= LID[u]) return V[LID[v] - k];\n      k -= LID[v] - LID[u] + 1;\n      v =\
    \ parent[u];\n    }\n  }\n  int la(int u, int v) { return LA(u, v); }\n\n  int\
    \ LCA(int u, int v) {\n    static_assert(HLD);\n    for (;; v = parent[head[v]])\
    \ {\n      if (LID[u] > LID[v]) swap(u, v);\n      if (head[u] == head[v]) return\
    \ u;\n    }\n  }\n\n  int meet(int a, int b, int c) {\n    static_assert(HLD);\n\
    \    return LCA(a, b) ^ LCA(a, c) ^ LCA(b, c);\n  }\n  int lca(int u, int v) {\
    \ return LCA(u, v); }\n\n  int subtree_size(int v) { return RID[v] - LID[v]; }\n\
    \n  int subtree_size(int v, int root) {\n    static_assert(HLD);\n    if (v ==\
    \ root) return N;\n    int x = jump(v, root, 1);\n    if (in_subtree(v, x)) return\
    \ RID[v] - LID[v];\n    return N - RID[x] + LID[x];\n  }\n\n  int dist(int a,\
    \ int b) {\n    static_assert(HLD);\n    int c = LCA(a, b);\n    return depth[a]\
    \ + depth[b] - 2 * depth[c];\n  }\n\n  WT dist_weighted(int a, int b) {\n    static_assert(HLD);\n\
    \    int c = LCA(a, b);\n    return depth_weighted[a] + depth_weighted[b] - WT(2)\
    \ * depth_weighted[c];\n  }\n\n  // a is in b\n  bool in_subtree(int a, int b)\
    \ { return LID[b] <= LID[a] && LID[a] < RID[b]; }\n\n  int jump(int a, int b,\
    \ ll k) {\n    static_assert(HLD);\n    if (k == 1) {\n      if (a == b) return\
    \ -1;\n      return (in_subtree(b, a) ? LA(b, depth[b] - depth[a] - 1) : parent[a]);\n\
    \    }\n    int c = LCA(a, b);\n    int d_ac = depth[a] - depth[c];\n    int d_bc\
    \ = depth[b] - depth[c];\n    if (k > d_ac + d_bc) return -1;\n    if (k <= d_ac)\
    \ return LA(a, k);\n    return LA(b, d_ac + d_bc - k);\n  }\n\n  vc<int> collect_child(int\
    \ v) {\n    vc<int> res;\n    for (auto &&e : G[v])\n      if (e.to != parent[v])\
    \ res.eb(e.to);\n    return res;\n  }\n\n  vc<int> collect_subtree(int v) {\n\
    \    return {V.begin() + LID[v], V.begin() + RID[v]};\n  }\n\n  vc<int> collect_light(int\
    \ v) {\n    static_assert(HLD);\n    vc<int> res;\n    for (auto &&e : G[v]) {\n\
    \      if (e.to != parent[v] && head[e.to] == e.to) res.eb(e.to);\n    }\n   \
    \ return res;\n  }\n\n  vc<pair<int, int>> get_path_decomposition(int u, int v,\
    \ bool edge) {\n    static_assert(HLD);\n    // [\u59CB\u70B9, \u7D42\u70B9] \u306E\
    \"\u9589\"\u533A\u9593\u5217\u3002\n    vc<pair<int, int>> up, down;\n    while\
    \ (1) {\n      if (head[u] == head[v]) break;\n      if (LID[u] < LID[v]) {\n\
    \        down.eb(LID[head[v]], LID[v]);\n        v = parent[head[v]];\n      }\
    \ else {\n        up.eb(LID[u], LID[head[u]]);\n        u = parent[head[u]];\n\
    \      }\n    }\n    if (LID[u] < LID[v]) down.eb(LID[u] + edge, LID[v]);\n  \
    \  elif (LID[v] + edge <= LID[u]) up.eb(LID[u], LID[v] + edge);\n    reverse(all(down));\n\
    \    up.insert(up.end(), all(down));\n    return up;\n  }\n\n  // \u8FBA\u306E\
    \u5217\u306E\u60C5\u5831 (frm,to,str)\n  // str = \"heavy_up\", \"heavy_down\"\
    , \"light_up\", \"light_down\"\n  vc<tuple<int, int, string>> get_path_decomposition_detail(int\
    \ u, int v) {\n    static_assert(HLD);\n    vc<tuple<int, int, string>> up, down;\n\
    \    while (1) {\n      if (head[u] == head[v]) break;\n      if (LID[u] < LID[v])\
    \ {\n        if (v != head[v]) down.eb(head[v], v, \"heavy_down\"), v = head[v];\n\
    \        down.eb(parent[v], v, \"light_down\"), v = parent[v];\n      } else {\n\
    \        if (u != head[u]) up.eb(u, head[u], \"heavy_up\"), u = head[u];\n   \
    \     up.eb(u, parent[u], \"light_up\"), u = parent[u];\n      }\n    }\n    if\
    \ (LID[u] < LID[v]) down.eb(u, v, \"heavy_down\");\n    elif (LID[v] < LID[u])\
    \ up.eb(u, v, \"heavy_up\");\n    reverse(all(down));\n    concat(up, down);\n\
    \    return up;\n  }\n\n  vc<int> restore_path(int u, int v) {\n    vc<int> L,\
    \ R;\n    while (depth[u] > depth[v]) L.eb(u), u = parent[u];\n    while (depth[u]\
    \ < depth[v]) R.eb(v), v = parent[v];\n    while (u != v) L.eb(u), R.eb(v), u\
    \ = parent[u], v = parent[v];\n    L.eb(u);\n    while (len(R)) L.eb(POP(R));\n\
    \    return L;\n  }\n\n  // path [a,b] \u3068 [c,d] \u306E\u4EA4\u308F\u308A.\
    \ \u7A7A\u306A\u3089\u3070 {-1,-1}.\n  // https://codeforces.com/problemset/problem/500/G\n\
    \  pair<int, int> path_intersection(int a, int b, int c, int d) {\n    static_assert(HLD);\n\
    \    int ab = lca(a, b), ac = lca(a, c), ad = lca(a, d);\n    int bc = lca(b,\
    \ c), bd = lca(b, d), cd = lca(c, d);\n    int x = ab ^ ac ^ bc, y = ab ^ ad ^\
    \ bd;  // meet(a,b,c), meet(a,b,d)\n    if (x != y) return {x, y};\n    int z\
    \ = ac ^ ad ^ cd;\n    if (x != z) x = -1;\n    return {x, x};\n  }\n\n  // uv\
    \ path \u4E0A\u3067 check(v) \u3092\u6E80\u305F\u3059\u6700\u5F8C\u306E v\n  //\
    \ \u306A\u3051\u308C\u3070 \uFF08\u3064\u307E\u308A check(v) \u304C ng \uFF09\
    -1\n  template <class F>\n  int max_path(F check, int u, int v) {\n    static_assert(HLD);\n\
    \    if (!check(u)) return -1;\n    auto pd = get_path_decomposition(u, v, false);\n\
    \    for (auto [a, b] : pd) {\n      if (!check(V[a])) return u;\n      if (check(V[b]))\
    \ {\n        u = V[b];\n        continue;\n      }\n      int c =\n          binary_search([&](int\
    \ c) -> bool { return check(V[c]); }, a, b, 0);\n      return V[c];\n    }\n \
    \   return u;\n  }\n\n private:\n  void build_simple(int r = 0) {\n    N = G.N;\n\
    \    LID.assign(N, 0), RID.assign(N, 0);\n    V.assign(N, -1), parent.assign(N,\
    \ -1), VtoE.assign(N, -1);\n    depth.assign(N, 0), depth_weighted.assign(N, 0);\n\
    \    assert(G.is_prepared());\n\n    // 1st dfs.\n    int k = 0;\n    vc<int>\
    \ st;\n    st.reserve(N);\n    st.eb(r);\n    while (len(st)) {\n      int v =\
    \ POP(st);\n      LID[v] = k, V[k] = v;\n      ++k;\n      for (int i = G.indptr[v\
    \ + 1] - 1; i >= G.indptr[v]; --i) {\n        auto &e = G.csr_edges[i];\n    \
    \    if (e.to == parent[v]) continue;\n        parent[e.to] = v;\n        depth[e.to]\
    \ = depth[v] + 1;\n        depth_weighted[e.to] = depth_weighted[v] + e.cost;\n\
    \        VtoE[e.to] = e.id;\n        st.eb(e.to);\n      }\n    }\n\n    FOR_R(i,\
    \ N) {\n      int v = V[i];\n      chmax(RID[v], LID[v] + 1);\n      if (parent[v]\
    \ != -1) chmax(RID[parent[v]], RID[v]);\n    }\n  }\n\n  void build_HLD(int r\
    \ = 0) {\n    N = G.N;\n    LID.assign(N, 0), RID.assign(N, 0), head.assign(N,\
    \ r);\n    V.assign(N, -1), parent.assign(N, -1), VtoE.assign(N, -1);\n    depth.assign(N,\
    \ 0), depth_weighted.assign(N, 0);\n    memo_tail.clear();\n    assert(G.is_prepared());\n\
    \n    // 1st dfs.\n    {\n      int k = 0;\n      vc<int> st;\n      st.reserve(N);\n\
    \      st.eb(r);\n      while (len(st)) {\n        int v = POP(st);\n        V[k++]\
    \ = v;\n        for (auto &e : G[v]) {\n          if (e.to == parent[v]) continue;\n\
    \          parent[e.to] = v, st.eb(e.to), depth[e.to] = depth[v] + 1;\n      \
    \    depth_weighted[e.to] = depth_weighted[v] + e.cost;\n          VtoE[e.to]\
    \ = e.id;\n        }\n      }\n      // \u4E00\u6642\u7684\u306B RID[v] := sz[v]\n\
    \      FOR_R(i, N) {\n        int v = V[i];\n        RID[v] += 1;\n        if\
    \ (parent[v] != -1) RID[parent[v]] += RID[v];\n      }\n    }\n    // 2nd dfs.\n\
    \    {\n      int k = 0;\n      vc<int> st;\n      st.reserve(N);\n      st.eb(r);\n\
    \      while (len(st)) {\n        int v = POP(st);\n        V[k] = v, LID[v] =\
    \ k;\n        RID[v] = k + RID[v];\n        ++k;\n        int max_sz = 0, max_ch\
    \ = -1;\n        for (auto &e : G[v]) {\n          if (e.to == parent[v]) continue;\n\
    \          if (chmax(max_sz, RID[e.to])) max_ch = e.to;\n        }\n        for\
    \ (int i = G.indptr[v + 1] - 1; i >= G.indptr[v]; --i) {\n          auto &e =\
    \ G.csr_edges[i];\n          if (e.to == parent[v] || e.to == max_ch) continue;\n\
    \          st.eb(e.to), head[e.to] = e.to;\n        }\n        if (max_ch != -1)\
    \ st.eb(max_ch), head[max_ch] = head[v];\n      }\n    }\n  }\n};\n#line 2 \"\
    graph/ds/static_toptree.hpp\"\n\n/*\n\u53C2\u8003 joitour tatyam\n\u30AF\u30E9\
    \u30B9\u30BF\u306F\u6839\u304C virtual \u306A\u3082\u306E\u306E\u307F\u3067\u3042\
    \u308B\u3088\u3046\u306A\u7C21\u6613\u7248\nN \u500B\u306E (\u9802+\u8FBA) \u3092\
    \u30DE\u30FC\u30B8\u3057\u3066\u3044\u3063\u3066\uFF0C\u6728\u5168\u4F53\uFF0B\
    \u6839\u304B\u3089\u89AA\u3078\u306E\u8FBA\u3068\u3059\u308B\uFF0E\nsingle(v)\
    \ : v \u3068\u305D\u306E\u89AA\u8FBA\u3092\u5408\u308F\u305B\u305F\u30AF\u30E9\
    \u30B9\u30BF\nrake(L,R) : L \u306E boundary \u3092\u7DAD\u6301\ncompress(L,R)\
    \  (top-down) \u9806\u306B x,y\n*/\ntemplate <typename TREE>\nstruct Static_TopTree\
    \ {\n  int N;\n  TREE &tree;\n  vc<int> par, lch, rch, A, B;  // A, B boundary\
    \ (top-down)\n  vc<bool> is_compress;\n\n  Static_TopTree(TREE &tree) : tree(tree)\
    \ { build(); }\n\n  void build() {\n    N = tree.N;\n    par.assign(N, -1), lch.assign(N,\
    \ -1), rch.assign(N, -1), A.assign(N, -1),\n        B.assign(N, -1), is_compress.assign(N,\
    \ 0);\n    FOR(v, N) { A[v] = tree.parent[v], B[v] = v; }\n    build_dfs(tree.V[0]);\n\
    \    assert(len(par) == 2 * N - 1);\n  }\n\n  // \u6728\u5168\u4F53\u3067\u306E\
    \u96C6\u7D04\u5024\u3092\u5F97\u308B\n  // single(v) : v \u3068\u305D\u306E\u89AA\
    \u8FBA\u3092\u5408\u308F\u305B\u305F\u30AF\u30E9\u30B9\u30BF\n  // rake(x, y)\
    \ uv(top down) \u304C boundary \u306B\u306A\u308B\u3088\u3046\u306B rake\n  //\
    \ compress(x,y)  (top-down) \u9806\u306B (a,b] + (b,c]\n  template <typename TREE_DP,\
    \ typename F>\n  typename TREE_DP::value_type tree_dp(F single) {\n    using Data\
    \ = typename TREE_DP::value_type;\n    auto dfs = [&](auto &dfs, int k) -> Data\
    \ {\n      if (0 <= k && k < N) return single(k);\n      Data x = dfs(dfs, lch[k]),\
    \ y = dfs(dfs, rch[k]);\n      if (is_compress[k]) {\n        assert(B[lch[k]]\
    \ == A[rch[k]]);\n        return TREE_DP::compress(x, y);\n      }\n      return\
    \ TREE_DP::rake(x, y);\n    };\n    return dfs(dfs, 2 * N - 2);\n  }\n\n private:\n\
    \  int new_node(int l, int r, int a, int b, bool c) {\n    int v = len(par);\n\
    \    par.eb(-1), lch.eb(l), rch.eb(r), A.eb(a), B.eb(b), is_compress.eb(c);\n\
    \    par[l] = par[r] = v;\n    return v;\n  }\n\n  // height, node idx\n  // compress\
    \ \u53C2\u8003\uFF1Ahttps://atcoder.jp/contests/abc351/editorial/9910\n  // \u305F\
    \u3060\u3057 heavy path \u306E\u9078\u3073\u65B9\u307E\u3067\u306F\u8003\u616E\
    \u3057\u306A\u3044\n  pair<int, int> build_dfs(int v) {\n    assert(tree.head[v]\
    \ == v);\n    auto path = tree.heavy_path_at(v);\n    vc<pair<int, int>> stack;\n\
    \    stack.eb(0, path[0]);\n    auto merge_last_two = [&]() -> void {\n      auto\
    \ [h2, k2] = POP(stack);\n      auto [h1, k1] = POP(stack);\n      stack.eb(max(h1,\
    \ h2) + 1, new_node(k1, k2, A[k1], B[k2], true));\n    };\n\n    FOR(i, 1, len(path))\
    \ {\n      pq_min<pair<int, int>> que;\n      int k = path[i];\n      que.emplace(0,\
    \ k);\n      for (auto &c : tree.collect_light(path[i - 1])) {\n        que.emplace(build_dfs(c));\n\
    \      }\n      while (len(que) >= 2) {\n        auto [h1, i1] = POP(que);\n \
    \       auto [h2, i2] = POP(que);\n        if (i2 == k) swap(i1, i2);\n      \
    \  int i3 = new_node(i1, i2, A[i1], B[i1], false);\n        if (k == i1) k = i3;\n\
    \        que.emplace(max(h1, h2) + 1, i3);\n      }\n      stack.eb(POP(que));\n\
    \n      while (1) {\n        int n = len(stack);\n        if (n >= 3 && (stack[n\
    \ - 3].fi == stack[n - 2].fi ||\n                       stack[n - 3].fi <= stack[n\
    \ - 1].fi)) {\n          auto [h3, k3] = POP(stack);\n          merge_last_two(),\
    \ stack.eb(h3, k3);\n        }\n        elif (n >= 2 && stack[n - 2].fi <= stack[n\
    \ - 1].fi) {\n          merge_last_two();\n        }\n        else break;\n  \
    \    }\n    }\n    while (len(stack) >= 2) {\n      merge_last_two();\n    }\n\
    \    return POP(stack);\n  }\n};\n#line 2 \"graph/ds/dynamic_tree_dp.hpp\"\n\n\
    // reroot \u3067\u304D\u306A\u3044\u7C21\u6613\u7248\n// https://codeforces.com/contest/1172/problem/E\n\
    // https://codeforces.com/contest/1942/problem/H\n// single(v) : v \u3068\u305D\
    \u306E\u89AA\u8FBA\u3092\u5408\u308F\u305B\u305F\u30AF\u30E9\u30B9\u30BF\n// rake(L,R)\
    \ : L \u306E boundary \u3092\u7DAD\u6301\n// compress(L,R)  (top-down) \u9806\u306B\
    \ L,R\ntemplate <typename TREE, typename TREE_DP>\nstruct Dynamic_Tree_Dp {\n\
    \  using X = typename TREE_DP::value_type;\n  Static_TopTree<TREE> STT;\n  vc<X>\
    \ dp;\n\n  template <typename F>\n  Dynamic_Tree_Dp(TREE& tree, F single) : STT(tree)\
    \ {\n    int N = tree.N;\n    dp.resize(2 * N - 1);\n    FOR(i, N) dp[i] = single(i);\n\
    \    FOR(i, N, 2 * N - 1) update(i);\n  }\n\n  void set(int v, X x) {\n    dp[v]\
    \ = x;\n    for (int i = STT.par[v]; i != -1; i = STT.par[i]) update(i);\n  }\n\
    \n  X prod_all() { return dp.back(); }\n\nprivate:\n  inline void update(int i)\
    \ {\n    X &L = dp[STT.lch[i]], &R = dp[STT.rch[i]];\n    dp[i] = (STT.is_compress[i]\
    \ ? TREE_DP::compress(L, R) : TREE_DP::rake(L, R));\n  }\n};\n"
  code: "#include \"graph/ds/static_toptree.hpp\"\n\n// reroot \u3067\u304D\u306A\u3044\
    \u7C21\u6613\u7248\n// https://codeforces.com/contest/1172/problem/E\n// https://codeforces.com/contest/1942/problem/H\n\
    // single(v) : v \u3068\u305D\u306E\u89AA\u8FBA\u3092\u5408\u308F\u305B\u305F\u30AF\
    \u30E9\u30B9\u30BF\n// rake(L,R) : L \u306E boundary \u3092\u7DAD\u6301\n// compress(L,R)\
    \  (top-down) \u9806\u306B L,R\ntemplate <typename TREE, typename TREE_DP>\nstruct\
    \ Dynamic_Tree_Dp {\n  using X = typename TREE_DP::value_type;\n  Static_TopTree<TREE>\
    \ STT;\n  vc<X> dp;\n\n  template <typename F>\n  Dynamic_Tree_Dp(TREE& tree,\
    \ F single) : STT(tree) {\n    int N = tree.N;\n    dp.resize(2 * N - 1);\n  \
    \  FOR(i, N) dp[i] = single(i);\n    FOR(i, N, 2 * N - 1) update(i);\n  }\n\n\
    \  void set(int v, X x) {\n    dp[v] = x;\n    for (int i = STT.par[v]; i != -1;\
    \ i = STT.par[i]) update(i);\n  }\n\n  X prod_all() { return dp.back(); }\n\n\
    private:\n  inline void update(int i) {\n    X &L = dp[STT.lch[i]], &R = dp[STT.rch[i]];\n\
    \    dp[i] = (STT.is_compress[i] ? TREE_DP::compress(L, R) : TREE_DP::rake(L,\
    \ R));\n  }\n};"
  dependsOn:
  - graph/ds/static_toptree.hpp
  - graph/tree.hpp
  - graph/base.hpp
  - ds/hashmap.hpp
  isVerificationFile: false
  path: graph/ds/dynamic_tree_dp.hpp
  requiredBy: []
  timestamp: '2026-08-16 04:03:00+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/2_library_checker/tree/point_set_tree_path_composite_sum_fixed_root.test.cpp
documentation_of: graph/ds/dynamic_tree_dp.hpp
layout: document
redirect_from:
- /library/graph/ds/dynamic_tree_dp.hpp
- /library/graph/ds/dynamic_tree_dp.hpp.html
title: graph/ds/dynamic_tree_dp.hpp
---
