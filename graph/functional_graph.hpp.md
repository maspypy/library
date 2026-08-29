---
data:
  _extendedDependsOn:
  - icon: ':question:'
    path: alg/monoid/add.hpp
    title: alg/monoid/add.hpp
  - icon: ':question:'
    path: alg/monoid_pow.hpp
    title: alg/monoid_pow.hpp
  - icon: ':question:'
    path: ds/hashmap.hpp
    title: ds/hashmap.hpp
  - icon: ':question:'
    path: ds/unionfind/unionfind.hpp
    title: ds/unionfind/unionfind.hpp
  - icon: ':question:'
    path: graph/base.hpp
    title: graph/base.hpp
  - icon: ':question:'
    path: graph/tree.hpp
    title: graph/tree.hpp
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/3_yukicoder/1211.test.cpp
    title: test/3_yukicoder/1211.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/3_yukicoder/1242.test.cpp
    title: test/3_yukicoder/1242.test.cpp
  - icon: ':x:'
    path: test/3_yukicoder/2122.test.cpp
    title: test/3_yukicoder/2122.test.cpp
  _isVerificationFailed: true
  _pathExtension: hpp
  _verificationStatusIcon: ':question:'
  attributes:
    links: []
  bundledCode: "#line 1 \"alg/monoid/add.hpp\"\n\ntemplate <typename E>\nstruct Monoid_Add\
    \ {\n  using X = E;\n  using value_type = X;\n  static constexpr X op(const X\
    \ &x, const X &y) noexcept { return x + y; }\n  static constexpr X inverse(const\
    \ X &x) noexcept { return -x; }\n  static constexpr X power(const X &x, ll n)\
    \ noexcept { return X(n) * x; }\n  static constexpr X unit() { return X(0); }\n\
    \  static constexpr bool commute = true;\n};\n#line 1 \"alg/monoid_pow.hpp\"\n\
    \n// chat gpt\ntemplate <typename U, typename Arg1, typename Arg2>\nstruct has_power_method\
    \ {\n private:\n  // \u30D8\u30EB\u30D1\u30FC\u95A2\u6570\u306E\u5B9F\u88C5\n\
    \  template <typename V, typename A1, typename A2>\n  static auto check(int)\n\
    \      -> decltype(std::declval<V>().power(std::declval<A1>(),\n             \
    \                             std::declval<A2>()),\n                  std::true_type{});\n\
    \  template <typename, typename, typename>\n  static auto check(...) -> std::false_type;\n\
    \n public:\n  // \u30E1\u30BD\u30C3\u30C9\u306E\u6709\u7121\u3092\u8868\u3059\u578B\
    \n  static constexpr bool value = decltype(check<U, Arg1, Arg2>(0))::value;\n\
    };\n\ntemplate <typename Monoid>\ntypename Monoid::X monoid_pow(typename Monoid::X\
    \ x, ll exp) {\n  using X = typename Monoid::X;\n  if constexpr (has_power_method<Monoid,\
    \ X, ll>::value) {\n    return Monoid::power(x, exp);\n  } else {\n    assert(exp\
    \ >= 0);\n    if (exp == 0) return Monoid::unit();\n    if (exp == 1) return x;\n\
    \    X res = Monoid::unit();\n    while (exp) {\n      if (exp & 1) res = Monoid::op(res,\
    \ x);\n      x = Monoid::op(x, x);\n      exp >>= 1;\n    }\n    return res;\n\
    \  }\n}\n#line 1 \"graph/tree.hpp\"\n\n#line 1 \"ds/hashmap.hpp\"\n\n// u64 ->\
    \ Val\ntemplate <typename Val>\nstruct HashMap {\n  // n \u306F\u5165\u308C\u305F\
    \u3044\u3082\u306E\u306E\u500B\u6570\u3067 ok\n  HashMap(u32 n = 0) { build(n);\
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
    \ v) const {\n    static_assert(HLD);\n    assert(head[v] == v);\n    int k =\
    \ LID[v];\n    vc<int> P;\n    while (k < N && head[V[k]] == v) P.eb(V[k++]);\n\
    \    return P;\n  }\n\n  int heavy_child(int v) const {\n    static_assert(HLD);\n\
    \    if (RID[v] == LID[v] + 1) return -1;\n    return V[LID[v] + 1];\n  }\n\n\
    \  int tail(int v) {\n    static_assert(HLD);\n    if (memo_tail.empty()) {\n\
    \      memo_tail.assign(N, -1);\n      FOR_R(i, N) {\n        int v = V[i];\n\
    \        int w = heavy_child(v);\n        memo_tail[v] = (w == -1 ? v : memo_tail[w]);\n\
    \      }\n    }\n    return memo_tail[v];\n  }\n\n  int e_to_v(int eid) const\
    \ {\n    auto e = G.edges[eid];\n    return (parent[e.frm] == e.to ? e.frm : e.to);\n\
    \  }\n  int v_to_e(int v) const { return VtoE[v]; }\n  int get_eid(int u, int\
    \ v) const {\n    if (parent[u] != v) swap(u, v);\n    assert(parent[u] == v);\n\
    \    return VtoE[u];\n  }\n\n  int ELID(int v) const { return 2 * LID[v] - depth[v];\
    \ }\n  int ERID(int v) const { return 2 * RID[v] - depth[v] - 1; }\n\n  // \u76EE\
    \u6A19\u5730\u70B9\u3078\u9032\u3080\u500B\u6570\u304C k\n  int LA(int v, int\
    \ k) const {\n    static_assert(HLD);\n    assert(k <= depth[v]);\n    while (1)\
    \ {\n      int u = head[v];\n      if (LID[v] - k >= LID[u]) return V[LID[v] -\
    \ k];\n      k -= LID[v] - LID[u] + 1;\n      v = parent[u];\n    }\n  }\n\n \
    \ int LCA(int u, int v) const {\n    static_assert(HLD);\n    for (;; v = parent[head[v]])\
    \ {\n      if (LID[u] > LID[v]) swap(u, v);\n      if (head[u] == head[v]) return\
    \ u;\n    }\n  }\n\n  int meet(int a, int b, int c) const {\n    static_assert(HLD);\n\
    \    return LCA(a, b) ^ LCA(a, c) ^ LCA(b, c);\n  }\n\n  int subtree_size(int\
    \ v) const { return RID[v] - LID[v]; }\n\n  int subtree_size(int v, int root)\
    \ const {\n    static_assert(HLD);\n    if (v == root) return N;\n    int x =\
    \ jump(v, root, 1);\n    if (in_subtree(v, x)) return RID[v] - LID[v];\n    return\
    \ N - RID[x] + LID[x];\n  }\n\n  int dist(int a, int b) const {\n    static_assert(HLD);\n\
    \    int c = LCA(a, b);\n    return depth[a] + depth[b] - 2 * depth[c];\n  }\n\
    \n  WT dist_weighted(int a, int b) const {\n    static_assert(HLD);\n    int c\
    \ = LCA(a, b);\n    return depth_weighted[a] + depth_weighted[b] - WT(2) * depth_weighted[c];\n\
    \  }\n\n  // a is in b\n  bool in_subtree(int a, int b) const {\n    return LID[b]\
    \ <= LID[a] && LID[a] < RID[b];\n  }\n\n  int jump(int a, int b, ll k) const {\n\
    \    static_assert(HLD);\n    if (k == 1) {\n      if (a == b) return -1;\n  \
    \    return (in_subtree(b, a) ? LA(b, depth[b] - depth[a] - 1) : parent[a]);\n\
    \    }\n    int c = LCA(a, b);\n    int d_ac = depth[a] - depth[c];\n    int d_bc\
    \ = depth[b] - depth[c];\n    if (k > d_ac + d_bc) return -1;\n    if (k <= d_ac)\
    \ return LA(a, k);\n    return LA(b, d_ac + d_bc - k);\n  }\n\n  vc<int> collect_child(int\
    \ v) const {\n    vc<int> res;\n    for (auto &&e : G[v])\n      if (e.to != parent[v])\
    \ res.eb(e.to);\n    return res;\n  }\n\n  vc<int> collect_subtree(int v) const\
    \ {\n    return {V.begin() + LID[v], V.begin() + RID[v]};\n  }\n\n  vc<int> collect_light(int\
    \ v) const {\n    static_assert(HLD);\n    vc<int> res;\n    for (auto &&e : G[v])\
    \ {\n      if (e.to != parent[v] && head[e.to] == e.to) res.eb(e.to);\n    }\n\
    \    return res;\n  }\n\n  vc<pair<int, int>> get_path_decomposition(int u, int\
    \ v, bool edge) const {\n    static_assert(HLD);\n    // [\u59CB\u70B9, \u7D42\
    \u70B9] \u306E\"\u9589\"\u533A\u9593\u5217\u3002\n    vc<pair<int, int>> up, down;\n\
    \    while (1) {\n      if (head[u] == head[v]) break;\n      if (LID[u] < LID[v])\
    \ {\n        down.eb(LID[head[v]], LID[v]);\n        v = parent[head[v]];\n  \
    \    } else {\n        up.eb(LID[u], LID[head[u]]);\n        u = parent[head[u]];\n\
    \      }\n    }\n    if (LID[u] < LID[v]) down.eb(LID[u] + edge, LID[v]);\n  \
    \  elif (LID[v] + edge <= LID[u]) up.eb(LID[u], LID[v] + edge);\n    reverse(all(down));\n\
    \    up.insert(up.end(), all(down));\n    return up;\n  }\n\n  // \u8FBA\u306E\
    \u5217\u306E\u60C5\u5831 (frm,to,str)\n  // str = \"heavy_up\", \"heavy_down\"\
    , \"light_up\", \"light_down\"\n  vc<tuple<int, int, string>> get_path_decomposition_detail(\n\
    \      int u, int v) const {\n    static_assert(HLD);\n    vc<tuple<int, int,\
    \ string>> up, down;\n    while (1) {\n      if (head[u] == head[v]) break;\n\
    \      if (LID[u] < LID[v]) {\n        if (v != head[v]) down.eb(head[v], v, \"\
    heavy_down\"), v = head[v];\n        down.eb(parent[v], v, \"light_down\"), v\
    \ = parent[v];\n      } else {\n        if (u != head[u]) up.eb(u, head[u], \"\
    heavy_up\"), u = head[u];\n        up.eb(u, parent[u], \"light_up\"), u = parent[u];\n\
    \      }\n    }\n    if (LID[u] < LID[v]) down.eb(u, v, \"heavy_down\");\n   \
    \ elif (LID[v] < LID[u]) up.eb(u, v, \"heavy_up\");\n    reverse(all(down));\n\
    \    concat(up, down);\n    return up;\n  }\n\n  vc<int> restore_path(int u, int\
    \ v) const {\n    vc<int> L, R;\n    while (depth[u] > depth[v]) L.eb(u), u =\
    \ parent[u];\n    while (depth[u] < depth[v]) R.eb(v), v = parent[v];\n    while\
    \ (u != v) L.eb(u), R.eb(v), u = parent[u], v = parent[v];\n    L.eb(u);\n   \
    \ while (len(R)) L.eb(POP(R));\n    return L;\n  }\n\n  // path [a,b] \u3068 [c,d]\
    \ \u306E\u4EA4\u308F\u308A. \u7A7A\u306A\u3089\u3070 {-1,-1}.\n  // https://codeforces.com/problemset/problem/500/G\n\
    \  pair<int, int> path_intersection(int a, int b, int c, int d) const {\n    static_assert(HLD);\n\
    \    int ab = LCA(a, b), ac = LCA(a, c), ad = LCA(a, d);\n    int bc = LCA(b,\
    \ c), bd = LCA(b, d), cd = LCA(c, d);\n    int x = ab ^ ac ^ bc, y = ab ^ ad ^\
    \ bd;  // meet(a,b,c), meet(a,b,d)\n    if (x != y) return {x, y};\n    int z\
    \ = ac ^ ad ^ cd;\n    if (x != z) x = -1;\n    return {x, x};\n  }\n\n  // uv\
    \ path \u4E0A\u3067 check(v) \u3092\u6E80\u305F\u3059\u6700\u5F8C\u306E v\n  //\
    \ \u306A\u3051\u308C\u3070 \uFF08\u3064\u307E\u308A check(v) \u304C ng \uFF09\
    -1\n  template <class F>\n  int max_path(F check, int u, int v) const {\n    static_assert(HLD);\n\
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
    \ st.eb(max_ch), head[max_ch] = head[v];\n      }\n    }\n  }\n};\n#line 1 \"\
    ds/unionfind/unionfind.hpp\"\n\nstruct UnionFind {\n  int n, n_comp;\n  vc<int>\
    \ dat; // par or (-size)\n  UnionFind(int n = 0) { build(n); }\n\n  void build(int\
    \ m) {\n    n = m, n_comp = m;\n    dat.assign(n, -1);\n  }\n\n  void reset()\
    \ { build(n); }\n\n  int operator[](int x) {\n    while (dat[x] >= 0) {\n    \
    \  int pp = dat[dat[x]];\n      if (pp < 0) { return dat[x]; }\n      x = dat[x]\
    \ = pp;\n    }\n    return x;\n  }\n\n  ll size(int x) {\n    x = (*this)[x];\n\
    \    return -dat[x];\n  }\n\n  bool merge(int x, int y) {\n    x = (*this)[x],\
    \ y = (*this)[y];\n    if (x == y) return false;\n    if (-dat[x] < -dat[y]) swap(x,\
    \ y);\n    dat[x] += dat[y], dat[y] = x, n_comp--;\n    return true;\n  }\n\n\
    \  vc<int> get_all() {\n    vc<int> A(n);\n    FOR(i, n) A[i] = (*this)[i];\n\
    \    return A;\n  }\n};\n#line 5 \"graph/functional_graph.hpp\"\n\r\n// \u5185\
    \u90E8\u5B9F\u88C5\u306F N \u304C\u6839\u3068\u306A\u308B\u6728\u3092\u65B0\u305F\
    \u306B\u4F5C\u308B\r\n// functional graph \u306E\u8FBA\u306B static \u306A\u7FA4\
    \u306E\u8981\u7D20\u304C\u3042\u308B\u3068\u3059\u308B\r\n// \uFF08\u30E2\u30CE\
    \u30A4\u30C9\u306B\u3082\u3067\u304D\u308B\u304C\u305D\u308C\u306F doubling \u3057\
    \u3066\u3082\u3089\u3046\u3068\u3044\u3046\u3053\u3068\u3067\u3055\u307C\u308A\
    . \uFF09\r\ntemplate <typename Monoid>\r\nstruct Functional_Graph {\r\n  using\
    \ MX = Monoid;\r\n  using X = typename MX::value_type;\r\n  int N, M;\r\n  vc<int>\
    \ TO;\r\n  vc<X> wt, dp;\r\n  vc<int> root;\r\n  Graph<int, 1> G;\r\n\r\n  Functional_Graph()\
    \ {}\r\n  Functional_Graph(int N)\r\n      : N(N), M(0), TO(N, -1), wt(N, MX::unit()),\
    \ root(N, -1) {}\r\n\r\n  void add(int a, int b, X c = MX::unit()) {\r\n    assert(0\
    \ <= a && a < N);\r\n    assert(TO[a] == -1);\r\n    ++M;\r\n    TO[a] = b;\r\n\
    \    wt[a] = c;\r\n  }\r\n\r\n  pair<Graph<int, 1>, Tree<Graph<int, 1>>> build()\
    \ {\r\n    assert(N == M);\r\n    UnionFind uf(N);\r\n    FOR(v, N) if (!uf.merge(v,\
    \ TO[v])) { root[v] = v; }\r\n    FOR(v, N) if (root[v] == v) root[uf[v]] = v;\r\
    \n    FOR(v, N) root[v] = root[uf[v]];\r\n\r\n    G.build(N + 1);\r\n    FOR(v,\
    \ N) {\r\n      if (root[v] == v)\r\n        G.add(N, v);\r\n      else\r\n  \
    \      G.add(TO[v], v);\r\n    }\r\n    G.build();\r\n    Tree<Graph<int, 1>>\
    \ tree(G, N);\r\n    dp.assign(N, MX::unit());\r\n    FOR(i, 1, N + 1) {\r\n \
    \     int v = tree.V[i];\r\n      int p = tree.parent[v];\r\n      if (p == N)\
    \ {\r\n        continue;\r\n      }\r\n      dp[v] = MX::op(wt[v], dp[p]);\r\n\
    \    }\r\n    return {G, tree};\r\n  }\r\n\r\n  // a -> b \u306B\u304B\u304B\u308B\
    \u56DE\u6570. \u4E0D\u53EF\u80FD\u306A\u3089 infty<int>. O(1).\r\n  template <typename\
    \ TREE>\r\n  int dist(TREE& tree, int a, int b) {\r\n    if (tree.in_subtree(a,\
    \ b)) return tree.depth[a] - tree.depth[b];\r\n    int r = root[a];\r\n    int\
    \ btm = TO[r];\r\n    // a -> r -> btm -> b\r\n    if (tree.in_subtree(btm, b))\
    \ {\r\n      int x = tree.depth[a] - tree.depth[r];\r\n      x += 1;\r\n     \
    \ x += tree.depth[btm] - tree.depth[b];\r\n      return x;\r\n    }\r\n    return\
    \ infty<int>;\r\n  }\r\n\r\n  // functional graph \u306B\u5411\u304B\u3063\u3066\
    \u9032\u3080\r\n  // return: \u7D42\u70B9, \u7FA4\u306E\u7A4D\r\n  template <typename\
    \ TREE>\r\n  pair<int, X> jump(TREE& tree, int v, ll step) {\r\n    int d = tree.depth[v];\r\
    \n    if (step <= d - 1) {\r\n      int w = tree.jump(v, N, step);\r\n      return\
    \ {w, MX::op(dp[v], MX::inverse(dp[w]))};\r\n    }\r\n    X x = dp[v];\r\n   \
    \ v = root[v];\r\n    step -= d - 1;\r\n    int bottom = TO[v];\r\n    int c =\
    \ tree.depth[bottom];\r\n    x = MX::op(x, monoid_pow<MX>(MX::op(wt[v], dp[bottom]),\
    \ step / c));\r\n    step %= c;\r\n    if (step == 0) return {v, x};\r\n    int\
    \ w = tree.jump(bottom, N, step - 1);\r\n    x = MX::op(x, wt[v]);\r\n    x =\
    \ MX::op(x, dp[bottom]);\r\n    x = MX::op(x, MX::inverse(dp[w]));\r\n    return\
    \ {w, x};\r\n  }\r\n\r\n  // check(to, prod). infty<ll> \u4EE5\u4E0B. step \u3092\
    \u304B\u3048\u3059\r\n  template <typename TREE, typename F>\r\n  ll max_jump(TREE&\
    \ tree, F check, int v) {\r\n    X prod = MX::unit();\r\n    assert(check(v, prod));\r\
    \n    ll ans = 0;\r\n    if (check(root[v], dp[v])) {\r\n      ans += tree.depth[v]\
    \ - 1, prod = dp[v], v = root[v];\r\n      int bottom = TO[v];\r\n      ll c =\
    \ tree.depth[bottom];\r\n      vc<X> pw;\r\n      pw.eb(MX::op(wt[v], dp[bottom]));\r\
    \n      FOR(k, 63) {\r\n        if (!check(root[v], MX::op(prod, pw[k]))) {\r\n\
    \          break;\r\n        }\r\n        if (ans + (c << k) >= infty<ll>) return\
    \ infty<ll>;\r\n        pw.eb(MX::op(pw.back(), pw.back()));\r\n      }\r\n  \
    \    FOR_R(k, len(pw)) {\r\n        if (check(root[v], MX::op(prod, pw[k]))) {\r\
    \n          ans = min(ans + (c << k), infty<ll>);\r\n          prod = MX::op(prod,\
    \ pw[k]);\r\n        }\r\n      }\r\n      if (!check(bottom, MX::op(prod, wt[v])))\
    \ return ans;\r\n      v = bottom, prod = MX::op(prod, wt[v]);\r\n    }\r\n  \
    \  auto pd = tree.get_path_decomposition(v, root[v], false);\r\n    auto mycheck\
    \ = [&](int w) -> bool {\r\n      X x = MX::op(prod, MX::op(dp[v], MX::inverse(dp[w])));\r\
    \n      return check(w, x);\r\n    };\r\n    int last = v;\r\n    for (auto [a,\
    \ b] : pd) {\r\n      swap(a, b);\r\n      assert(a <= b);\r\n      if (mycheck(tree.V[a]))\
    \ {\r\n        last = tree.V[a];\r\n        continue;\r\n      }\r\n      if (!mycheck(tree.V[b]))\
    \ {\r\n        break;\r\n      }\r\n      int k = binary_search([&](int i) ->\
    \ bool { return mycheck(tree.V[i]); },\r\n                            b, a, 0);\r\
    \n      last = tree.V[k];\r\n      break;\r\n    }\r\n    ans += tree.depth[v]\
    \ - tree.depth[last];\r\n    return min(ans, infty<ll>);\r\n  }\r\n\r\n  // functional\
    \ graph \u306B step \u56DE\u9032\u3080\r\n  template <typename TREE>\r\n  vc<int>\
    \ jump_all(TREE& tree, ll step) {\r\n    vc<int> res(N, -1);\r\n    // v \u306E\
    \ k \u500B\u5148\u3092 res[w] \u306B\u5165\u308C\u308B\r\n    vvc<pair<int, int>>\
    \ query(N);\r\n    FOR(v, N) {\r\n      int d = tree.depth[v];\r\n      int r\
    \ = root[v];\r\n      if (d - 1 > step) {\r\n        query[v].eb(v, step);\r\n\
    \      }\r\n      if (d - 1 <= step) {\r\n        ll k = step - (d - 1);\r\n \
    \       int bottom = TO[r];\r\n        int c = tree.depth[bottom];\r\n       \
    \ k %= c;\r\n        if (k == 0) {\r\n          res[v] = r;\r\n          continue;\r\
    \n        }\r\n        query[bottom].eb(v, k - 1);\r\n      }\r\n    }\r\n\r\n\
    \    vc<int> path;\r\n    auto dfs = [&](auto& dfs, int v) -> void {\r\n     \
    \ path.eb(v);\r\n      for (auto&& [w, k] : query[v]) {\r\n        res[w] = path[len(path)\
    \ - 1 - k];\r\n      }\r\n      for (auto&& e : G[v]) dfs(dfs, e.to);\r\n    \
    \  path.pop_back();\r\n    };\r\n    for (auto&& e : G[N]) {\r\n      dfs(dfs,\
    \ e.to);\r\n    }\r\n    return res;\r\n  }\r\n\r\n  template <typename TREE>\r\
    \n  bool in_cycle(TREE& tree, int v) {\r\n    int r = root[v];\r\n    int bottom\
    \ = TO[r];\r\n    return tree.in_subtree(bottom, v);\r\n  }\r\n\r\n  // \u8449\
    \u5074\u304B\u3089\u9806\u306B\u306A\u3089\u3093\u3060\u3082\u306E\u3092\u51FA\
    \u529B\r\n  vc<int> collect_cycle(int r) {\r\n    assert(r == root[r]);\r\n  \
    \  vc<int> cyc = {TO[r]};\r\n    while (cyc.back() != r) cyc.eb(TO[cyc.back()]);\r\
    \n    return cyc;\r\n  }\r\n\r\n  // F^k(i)==F^k(j) \u3068\u306A\u308B\u6700\u5C0F\
    \u306E k OR -1\r\n  template <typename TREE>\r\n  int meet_time(TREE& tree, int\
    \ i, int j) {\r\n    if (i == j) return 0;\r\n    if (root[i] != root[j]) return\
    \ -1;\r\n    int r = root[i];\r\n    int b = TO[r];\r\n    int n = tree.depth[b]\
    \ - tree.depth[r] + 1;  // cyc len\r\n    if ((tree.depth[i] - tree.depth[j])\
    \ % n != 0) return -1;\r\n\r\n    if (tree.depth[i] == tree.depth[j]) {\r\n  \
    \    int lca = tree.LCA(i, j);\r\n      return tree.depth[i] - tree.depth[lca];\r\
    \n    }\r\n    int ti = tree.depth[i] - tree.depth[tree.LCA(b, i)];\r\n    int\
    \ tj = tree.depth[j] - tree.depth[tree.LCA(b, j)];\r\n    return max(ti, tj);\r\
    \n  }\r\n};\r\n"
  code: "#include \"alg/monoid/add.hpp\"\r\n#include \"alg/monoid_pow.hpp\"\r\n#include\
    \ \"graph/tree.hpp\"\r\n#include \"ds/unionfind/unionfind.hpp\"\r\n\r\n// \u5185\
    \u90E8\u5B9F\u88C5\u306F N \u304C\u6839\u3068\u306A\u308B\u6728\u3092\u65B0\u305F\
    \u306B\u4F5C\u308B\r\n// functional graph \u306E\u8FBA\u306B static \u306A\u7FA4\
    \u306E\u8981\u7D20\u304C\u3042\u308B\u3068\u3059\u308B\r\n// \uFF08\u30E2\u30CE\
    \u30A4\u30C9\u306B\u3082\u3067\u304D\u308B\u304C\u305D\u308C\u306F doubling \u3057\
    \u3066\u3082\u3089\u3046\u3068\u3044\u3046\u3053\u3068\u3067\u3055\u307C\u308A\
    . \uFF09\r\ntemplate <typename Monoid>\r\nstruct Functional_Graph {\r\n  using\
    \ MX = Monoid;\r\n  using X = typename MX::value_type;\r\n  int N, M;\r\n  vc<int>\
    \ TO;\r\n  vc<X> wt, dp;\r\n  vc<int> root;\r\n  Graph<int, 1> G;\r\n\r\n  Functional_Graph()\
    \ {}\r\n  Functional_Graph(int N)\r\n      : N(N), M(0), TO(N, -1), wt(N, MX::unit()),\
    \ root(N, -1) {}\r\n\r\n  void add(int a, int b, X c = MX::unit()) {\r\n    assert(0\
    \ <= a && a < N);\r\n    assert(TO[a] == -1);\r\n    ++M;\r\n    TO[a] = b;\r\n\
    \    wt[a] = c;\r\n  }\r\n\r\n  pair<Graph<int, 1>, Tree<Graph<int, 1>>> build()\
    \ {\r\n    assert(N == M);\r\n    UnionFind uf(N);\r\n    FOR(v, N) if (!uf.merge(v,\
    \ TO[v])) { root[v] = v; }\r\n    FOR(v, N) if (root[v] == v) root[uf[v]] = v;\r\
    \n    FOR(v, N) root[v] = root[uf[v]];\r\n\r\n    G.build(N + 1);\r\n    FOR(v,\
    \ N) {\r\n      if (root[v] == v)\r\n        G.add(N, v);\r\n      else\r\n  \
    \      G.add(TO[v], v);\r\n    }\r\n    G.build();\r\n    Tree<Graph<int, 1>>\
    \ tree(G, N);\r\n    dp.assign(N, MX::unit());\r\n    FOR(i, 1, N + 1) {\r\n \
    \     int v = tree.V[i];\r\n      int p = tree.parent[v];\r\n      if (p == N)\
    \ {\r\n        continue;\r\n      }\r\n      dp[v] = MX::op(wt[v], dp[p]);\r\n\
    \    }\r\n    return {G, tree};\r\n  }\r\n\r\n  // a -> b \u306B\u304B\u304B\u308B\
    \u56DE\u6570. \u4E0D\u53EF\u80FD\u306A\u3089 infty<int>. O(1).\r\n  template <typename\
    \ TREE>\r\n  int dist(TREE& tree, int a, int b) {\r\n    if (tree.in_subtree(a,\
    \ b)) return tree.depth[a] - tree.depth[b];\r\n    int r = root[a];\r\n    int\
    \ btm = TO[r];\r\n    // a -> r -> btm -> b\r\n    if (tree.in_subtree(btm, b))\
    \ {\r\n      int x = tree.depth[a] - tree.depth[r];\r\n      x += 1;\r\n     \
    \ x += tree.depth[btm] - tree.depth[b];\r\n      return x;\r\n    }\r\n    return\
    \ infty<int>;\r\n  }\r\n\r\n  // functional graph \u306B\u5411\u304B\u3063\u3066\
    \u9032\u3080\r\n  // return: \u7D42\u70B9, \u7FA4\u306E\u7A4D\r\n  template <typename\
    \ TREE>\r\n  pair<int, X> jump(TREE& tree, int v, ll step) {\r\n    int d = tree.depth[v];\r\
    \n    if (step <= d - 1) {\r\n      int w = tree.jump(v, N, step);\r\n      return\
    \ {w, MX::op(dp[v], MX::inverse(dp[w]))};\r\n    }\r\n    X x = dp[v];\r\n   \
    \ v = root[v];\r\n    step -= d - 1;\r\n    int bottom = TO[v];\r\n    int c =\
    \ tree.depth[bottom];\r\n    x = MX::op(x, monoid_pow<MX>(MX::op(wt[v], dp[bottom]),\
    \ step / c));\r\n    step %= c;\r\n    if (step == 0) return {v, x};\r\n    int\
    \ w = tree.jump(bottom, N, step - 1);\r\n    x = MX::op(x, wt[v]);\r\n    x =\
    \ MX::op(x, dp[bottom]);\r\n    x = MX::op(x, MX::inverse(dp[w]));\r\n    return\
    \ {w, x};\r\n  }\r\n\r\n  // check(to, prod). infty<ll> \u4EE5\u4E0B. step \u3092\
    \u304B\u3048\u3059\r\n  template <typename TREE, typename F>\r\n  ll max_jump(TREE&\
    \ tree, F check, int v) {\r\n    X prod = MX::unit();\r\n    assert(check(v, prod));\r\
    \n    ll ans = 0;\r\n    if (check(root[v], dp[v])) {\r\n      ans += tree.depth[v]\
    \ - 1, prod = dp[v], v = root[v];\r\n      int bottom = TO[v];\r\n      ll c =\
    \ tree.depth[bottom];\r\n      vc<X> pw;\r\n      pw.eb(MX::op(wt[v], dp[bottom]));\r\
    \n      FOR(k, 63) {\r\n        if (!check(root[v], MX::op(prod, pw[k]))) {\r\n\
    \          break;\r\n        }\r\n        if (ans + (c << k) >= infty<ll>) return\
    \ infty<ll>;\r\n        pw.eb(MX::op(pw.back(), pw.back()));\r\n      }\r\n  \
    \    FOR_R(k, len(pw)) {\r\n        if (check(root[v], MX::op(prod, pw[k]))) {\r\
    \n          ans = min(ans + (c << k), infty<ll>);\r\n          prod = MX::op(prod,\
    \ pw[k]);\r\n        }\r\n      }\r\n      if (!check(bottom, MX::op(prod, wt[v])))\
    \ return ans;\r\n      v = bottom, prod = MX::op(prod, wt[v]);\r\n    }\r\n  \
    \  auto pd = tree.get_path_decomposition(v, root[v], false);\r\n    auto mycheck\
    \ = [&](int w) -> bool {\r\n      X x = MX::op(prod, MX::op(dp[v], MX::inverse(dp[w])));\r\
    \n      return check(w, x);\r\n    };\r\n    int last = v;\r\n    for (auto [a,\
    \ b] : pd) {\r\n      swap(a, b);\r\n      assert(a <= b);\r\n      if (mycheck(tree.V[a]))\
    \ {\r\n        last = tree.V[a];\r\n        continue;\r\n      }\r\n      if (!mycheck(tree.V[b]))\
    \ {\r\n        break;\r\n      }\r\n      int k = binary_search([&](int i) ->\
    \ bool { return mycheck(tree.V[i]); },\r\n                            b, a, 0);\r\
    \n      last = tree.V[k];\r\n      break;\r\n    }\r\n    ans += tree.depth[v]\
    \ - tree.depth[last];\r\n    return min(ans, infty<ll>);\r\n  }\r\n\r\n  // functional\
    \ graph \u306B step \u56DE\u9032\u3080\r\n  template <typename TREE>\r\n  vc<int>\
    \ jump_all(TREE& tree, ll step) {\r\n    vc<int> res(N, -1);\r\n    // v \u306E\
    \ k \u500B\u5148\u3092 res[w] \u306B\u5165\u308C\u308B\r\n    vvc<pair<int, int>>\
    \ query(N);\r\n    FOR(v, N) {\r\n      int d = tree.depth[v];\r\n      int r\
    \ = root[v];\r\n      if (d - 1 > step) {\r\n        query[v].eb(v, step);\r\n\
    \      }\r\n      if (d - 1 <= step) {\r\n        ll k = step - (d - 1);\r\n \
    \       int bottom = TO[r];\r\n        int c = tree.depth[bottom];\r\n       \
    \ k %= c;\r\n        if (k == 0) {\r\n          res[v] = r;\r\n          continue;\r\
    \n        }\r\n        query[bottom].eb(v, k - 1);\r\n      }\r\n    }\r\n\r\n\
    \    vc<int> path;\r\n    auto dfs = [&](auto& dfs, int v) -> void {\r\n     \
    \ path.eb(v);\r\n      for (auto&& [w, k] : query[v]) {\r\n        res[w] = path[len(path)\
    \ - 1 - k];\r\n      }\r\n      for (auto&& e : G[v]) dfs(dfs, e.to);\r\n    \
    \  path.pop_back();\r\n    };\r\n    for (auto&& e : G[N]) {\r\n      dfs(dfs,\
    \ e.to);\r\n    }\r\n    return res;\r\n  }\r\n\r\n  template <typename TREE>\r\
    \n  bool in_cycle(TREE& tree, int v) {\r\n    int r = root[v];\r\n    int bottom\
    \ = TO[r];\r\n    return tree.in_subtree(bottom, v);\r\n  }\r\n\r\n  // \u8449\
    \u5074\u304B\u3089\u9806\u306B\u306A\u3089\u3093\u3060\u3082\u306E\u3092\u51FA\
    \u529B\r\n  vc<int> collect_cycle(int r) {\r\n    assert(r == root[r]);\r\n  \
    \  vc<int> cyc = {TO[r]};\r\n    while (cyc.back() != r) cyc.eb(TO[cyc.back()]);\r\
    \n    return cyc;\r\n  }\r\n\r\n  // F^k(i)==F^k(j) \u3068\u306A\u308B\u6700\u5C0F\
    \u306E k OR -1\r\n  template <typename TREE>\r\n  int meet_time(TREE& tree, int\
    \ i, int j) {\r\n    if (i == j) return 0;\r\n    if (root[i] != root[j]) return\
    \ -1;\r\n    int r = root[i];\r\n    int b = TO[r];\r\n    int n = tree.depth[b]\
    \ - tree.depth[r] + 1;  // cyc len\r\n    if ((tree.depth[i] - tree.depth[j])\
    \ % n != 0) return -1;\r\n\r\n    if (tree.depth[i] == tree.depth[j]) {\r\n  \
    \    int lca = tree.LCA(i, j);\r\n      return tree.depth[i] - tree.depth[lca];\r\
    \n    }\r\n    int ti = tree.depth[i] - tree.depth[tree.LCA(b, i)];\r\n    int\
    \ tj = tree.depth[j] - tree.depth[tree.LCA(b, j)];\r\n    return max(ti, tj);\r\
    \n  }\r\n};\r\n"
  dependsOn:
  - alg/monoid/add.hpp
  - alg/monoid_pow.hpp
  - graph/tree.hpp
  - graph/base.hpp
  - ds/hashmap.hpp
  - ds/unionfind/unionfind.hpp
  isVerificationFile: false
  path: graph/functional_graph.hpp
  requiredBy: []
  timestamp: '2026-08-29 08:41:49+09:00'
  verificationStatus: LIBRARY_SOME_WA
  verifiedWith:
  - test/3_yukicoder/1242.test.cpp
  - test/3_yukicoder/2122.test.cpp
  - test/3_yukicoder/1211.test.cpp
documentation_of: graph/functional_graph.hpp
layout: document
redirect_from:
- /library/graph/functional_graph.hpp
- /library/graph/functional_graph.hpp.html
title: graph/functional_graph.hpp
---
