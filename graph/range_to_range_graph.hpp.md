---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: ds/hashmap.hpp
    title: ds/hashmap.hpp
  - icon: ':heavy_check_mark:'
    path: graph/base.hpp
    title: graph/base.hpp
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/3_yukicoder/1170.test.cpp
    title: test/3_yukicoder/1170.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/3_yukicoder/1868.test.cpp
    title: test/3_yukicoder/1868.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 1 \"ds/hashmap.hpp\"\n\n// u64 -> Val\ntemplate <typename Val>\n\
    struct HashMap {\n  // n \u306F\u5165\u308C\u305F\u3044\u3082\u306E\u306E\u500B\
    \u6570\u3067 ok\n  HashMap(u32 n = 0) { build(n); }\n  void build(u32 n) {\n \
    \   u32 k = 8;\n    while (k < n * 2) k *= 2;\n    cap = k / 2, mask = k - 1;\n\
    \    key.resize(k), val.resize(k), used.assign(k, 0);\n  }\n\n  // size \u3092\
    \u4FDD\u3063\u305F\u307E\u307E. size=0 \u306B\u3059\u308B\u3068\u304D\u306F build\
    \ \u3059\u308B\u3053\u3068.\n  void clear() {\n    used.assign(len(used), 0);\n\
    \    cap = (mask + 1) / 2;\n  }\n  int size() { return len(used) / 2 - cap; }\n\
    \n  int index(const u64& k) {\n    int i = 0;\n    for (i = hash(k); used[i] &&\
    \ key[i] != k; i = (i + 1) & mask) {}\n    return i;\n  }\n\n  Val& operator[](const\
    \ u64& k) {\n    if (cap == 0) extend();\n    int i = index(k);\n    if (!used[i])\
    \ { used[i] = 1, key[i] = k, val[i] = Val{}, --cap; }\n    return val[i];\n  }\n\
    \n  Val get(const u64& k, Val default_value) {\n    int i = index(k);\n    return\
    \ (used[i] ? val[i] : default_value);\n  }\n\n  bool count(const u64& k) {\n \
    \   int i = index(k);\n    return used[i] && key[i] == k;\n  }\n\n  // f(key,\
    \ val)\n  template <typename F>\n  void enumerate_all(F f) {\n    FOR(i, len(used))\
    \ if (used[i]) f(key[i], val[i]);\n  }\n\nprivate:\n  u32 cap, mask;\n  vc<u64>\
    \ key;\n  vc<Val> val;\n  vc<bool> used;\n\n  u64 hash(u64 x) {\n    static const\
    \ u64 FIXED_RANDOM = std::chrono::steady_clock::now().time_since_epoch().count();\n\
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
    \ {\n      vc_indeg[e.to]++, vc_outdeg[e.frm]++;\n    }\n  }\n};\n#line 2 \"graph/range_to_range_graph.hpp\"\
    \n\ntemplate <typename T>\nstruct Range_to_Range_Graph {\n  int n;\n  int n_node;\n\
    \  vc<tuple<int, int, T>> edges;\n\n  Range_to_Range_Graph(int n) : n(n), n_node(n\
    \ * 3) {\n    FOR(i, 2, n + n) { edges.eb(to_upper_idx(i / 2), to_upper_idx(i),\
    \ 0); }\n    FOR(i, 2, n + n) { edges.eb(to_lower_idx(i), to_lower_idx(i / 2),\
    \ 0); }\n  }\n\n  inline int to_upper_idx(const int& i) {\n    if (i >= n) return\
    \ i - n;\n    return n + i;\n  }\n\n  inline int to_lower_idx(const int& i) {\n\
    \    if (i >= n) return i - n;\n    return n + n + i;\n  }\n\n  void add(int frm,\
    \ int to, T wt) { edges.eb(frm, to, wt); }\n\n  void add_from_range(int frm_l,\
    \ int frm_r, int to, T wt) {\n    int l = frm_l + n, r = frm_r + n;\n    while\
    \ (l < r) {\n      if (l & 1) add(to_lower_idx(l++), to, wt);\n      if (r & 1)\
    \ add(to_lower_idx(--r), to, wt);\n      l >>= 1, r >>= 1;\n    }\n  }\n\n  void\
    \ add_to_range(int frm, int to_l, int to_r, T wt) {\n    int l = to_l + n, r =\
    \ to_r + n;\n    while (l < r) {\n      if (l & 1) add(frm, to_upper_idx(l++),\
    \ wt);\n      if (r & 1) add(frm, to_upper_idx(--r), wt);\n      l >>= 1, r >>=\
    \ 1;\n    }\n  }\n\n  void add_range_to_range(int frm_l, int frm_r, int to_l,\
    \ int to_r, T wt) {\n    int new_node = n_node++;\n    add_from_range(frm_l, frm_r,\
    \ new_node, wt);\n    add_to_range(new_node, to_l, to_r, T(0));\n  }\n\n  Graph<T,\
    \ 1> build() {\n    Graph<T, 1> G(n_node);\n    for (auto&& [a, b, c] : edges)\
    \ G.add(a, b, c);\n    G.build();\n    return G;\n  }\n};\n\n// DST \u65B9\u5F0F\
    \n// template <typename T>\n// struct Range_to_Range_Graph {\n//   int n;\n//\
    \   int n_node;\n//   vc<tuple<int, int, T>> edges;\n//   vc<tuple<int, int, int,\
    \ T>> FRM, TO;\n//   vc<int> A;\n\n//   const int K = 16;\n\n//   Range_to_Range_Graph(int\
    \ n) : n(n), n_node(n), A(n) {}\n\n//   void add(int frm, int to, T wt = 1) {\
    \ edges.eb(frm, to, wt); }\n//   void add_from_range(int frm_l, int frm_r, int\
    \ to, T wt = 1) {\n//     assert(0 <= frm_l && frm_l <= frm_r && frm_r <= n);\n\
    //     if (frm_l == frm_r) return;\n//     if (frm_r == frm_l + 1) return add(frm_l,\
    \ to, wt);\n//     FRM.eb(frm_l, frm_r, to, wt);\n//   }\n\n//   void add_to_range(int\
    \ frm, int to_l, int to_r, T wt = 1) {\n//     assert(0 <= to_l && to_l <= to_r\
    \ && to_r <= n);\n//     if (to_l == to_r) return;\n//     if (to_r == to_l +\
    \ 1) return add(frm, to_l, wt);\n//     TO.eb(frm, to_l, to_r, wt);\n//   }\n\n\
    //   // n_node, edges \u304C\u3044\u3044\u611F\u3058\u306B\u306A\u308B\n//   void\
    \ build() {\n//     int blk = ceil<int>(N, K);\n//     vvc<int> SI(blk);\n// \
    \    if (len(FRM)) {\n//       vc<int> A(N), B(N);\n\n//       FOR(i, len(FRM))\
    \ { auto [a, b, c, w] = FRM[i]; }\n//       int Q = len(FRM);\n//       vc<int>\
    \ I(Q);\n//       FOR(i, Q) I[i] = i;\n//       rec_frm(0, n, I);\n//       FRM.clear(),\
    \ FRM.shrink_to_fit();\n//     }\n\n//     Q = len(TO);\n//     I.resize(Q);\n\
    //     FOR(i, Q) I[i] = i;\n//     rec_to(0, n, I);\n//     TO.clear(), TO.shrink_to_fit();\n\
    //     // Graph<T, 1> G(n_node);\n//     // for (auto& [a, b, w] : edges) G.add(a,\
    \ b, w);\n//     // G.build();\n//     // return G;\n//   }\n\n//  private:\n\
    //   void rec_frm_small(int L, int R, vc<int>& I) {\n//     if (I.empty()) return;\n\
    //     int M = (L + R) / 2;\n//     vc<int> I1, I2, J;\n//     int s = M, t =\
    \ M;\n//     for (int i : I) {\n//       auto [a, b, c, w] = FRM[i];\n//     \
    \  if (b <= M) {\n//         I1.eb(i);\n//       }\n//       elif (M <= a) { I2.eb(i);\
    \ }\n//       else {\n//         chmin(s, a), chmax(t, b);\n//         J.eb(i);\n\
    //       }\n//     }\n//     rec_frm_small(L, M, I1), rec_frm_small(M, R, I2);\n\
    //     if (J.empty()) return;\n//     A[M - 1] = M - 1, A[M] = M;\n//     FOR_R(i,\
    \ s, M - 1) {\n//       A[i] = n_node++;\n//       add(i, A[i], 0), add(A[i +\
    \ 1], A[i], 0);\n//     }\n//     FOR(i, M + 1, t) {\n//       A[i] = n_node++;\n\
    //       add(i, A[i], 0), add(A[i - 1], A[i], 0);\n//     }\n//     for (int i\
    \ : J) {\n//       auto [a, b, c, w] = FRM[i];\n//       add(A[a], c, w), add(A[b\
    \ - 1], c, w);\n//     }\n//   }\n\n//   void rec_to(int L, int R, vc<int>& I)\
    \ {\n//     if (I.empty()) return;\n//     int M = (L + R) / 2;\n//     vc<int>\
    \ I1, I2, J;\n//     int s = M, t = M;\n//     for (int i : I) {\n//       auto\
    \ [c, a, b, w] = TO[i];\n//       if (b <= M) {\n//         I1.eb(i);\n//    \
    \   }\n//       elif (M <= a) { I2.eb(i); }\n//       else {\n//         chmin(s,\
    \ a), chmax(t, b);\n//         J.eb(i);\n//       }\n//     }\n//     rec_to(L,\
    \ M, I1), rec_to(M, R, I2);\n//     if (J.empty()) return;\n//     A[M - 1] =\
    \ M - 1, A[M] = M;\n//     FOR_R(i, s, M - 1) {\n//       A[i] = n_node++;\n//\
    \       add(A[i], i, 0), add(A[i], A[i + 1], 0);\n//     }\n//     FOR(i, M +\
    \ 1, t) {\n//       A[i] = n_node++;\n//       add(A[i], i, 0), add(A[i], A[i\
    \ - 1], 0);\n//     }\n//     for (int i : J) {\n//       auto [c, a, b, w] =\
    \ TO[i];\n//       add(c, A[a], w), add(c, A[b - 1], w);\n//     }\n//   }\n//\
    \ };\n"
  code: "#include \"graph/base.hpp\"\n\ntemplate <typename T>\nstruct Range_to_Range_Graph\
    \ {\n  int n;\n  int n_node;\n  vc<tuple<int, int, T>> edges;\n\n  Range_to_Range_Graph(int\
    \ n) : n(n), n_node(n * 3) {\n    FOR(i, 2, n + n) { edges.eb(to_upper_idx(i /\
    \ 2), to_upper_idx(i), 0); }\n    FOR(i, 2, n + n) { edges.eb(to_lower_idx(i),\
    \ to_lower_idx(i / 2), 0); }\n  }\n\n  inline int to_upper_idx(const int& i) {\n\
    \    if (i >= n) return i - n;\n    return n + i;\n  }\n\n  inline int to_lower_idx(const\
    \ int& i) {\n    if (i >= n) return i - n;\n    return n + n + i;\n  }\n\n  void\
    \ add(int frm, int to, T wt) { edges.eb(frm, to, wt); }\n\n  void add_from_range(int\
    \ frm_l, int frm_r, int to, T wt) {\n    int l = frm_l + n, r = frm_r + n;\n \
    \   while (l < r) {\n      if (l & 1) add(to_lower_idx(l++), to, wt);\n      if\
    \ (r & 1) add(to_lower_idx(--r), to, wt);\n      l >>= 1, r >>= 1;\n    }\n  }\n\
    \n  void add_to_range(int frm, int to_l, int to_r, T wt) {\n    int l = to_l +\
    \ n, r = to_r + n;\n    while (l < r) {\n      if (l & 1) add(frm, to_upper_idx(l++),\
    \ wt);\n      if (r & 1) add(frm, to_upper_idx(--r), wt);\n      l >>= 1, r >>=\
    \ 1;\n    }\n  }\n\n  void add_range_to_range(int frm_l, int frm_r, int to_l,\
    \ int to_r, T wt) {\n    int new_node = n_node++;\n    add_from_range(frm_l, frm_r,\
    \ new_node, wt);\n    add_to_range(new_node, to_l, to_r, T(0));\n  }\n\n  Graph<T,\
    \ 1> build() {\n    Graph<T, 1> G(n_node);\n    for (auto&& [a, b, c] : edges)\
    \ G.add(a, b, c);\n    G.build();\n    return G;\n  }\n};\n\n// DST \u65B9\u5F0F\
    \n// template <typename T>\n// struct Range_to_Range_Graph {\n//   int n;\n//\
    \   int n_node;\n//   vc<tuple<int, int, T>> edges;\n//   vc<tuple<int, int, int,\
    \ T>> FRM, TO;\n//   vc<int> A;\n\n//   const int K = 16;\n\n//   Range_to_Range_Graph(int\
    \ n) : n(n), n_node(n), A(n) {}\n\n//   void add(int frm, int to, T wt = 1) {\
    \ edges.eb(frm, to, wt); }\n//   void add_from_range(int frm_l, int frm_r, int\
    \ to, T wt = 1) {\n//     assert(0 <= frm_l && frm_l <= frm_r && frm_r <= n);\n\
    //     if (frm_l == frm_r) return;\n//     if (frm_r == frm_l + 1) return add(frm_l,\
    \ to, wt);\n//     FRM.eb(frm_l, frm_r, to, wt);\n//   }\n\n//   void add_to_range(int\
    \ frm, int to_l, int to_r, T wt = 1) {\n//     assert(0 <= to_l && to_l <= to_r\
    \ && to_r <= n);\n//     if (to_l == to_r) return;\n//     if (to_r == to_l +\
    \ 1) return add(frm, to_l, wt);\n//     TO.eb(frm, to_l, to_r, wt);\n//   }\n\n\
    //   // n_node, edges \u304C\u3044\u3044\u611F\u3058\u306B\u306A\u308B\n//   void\
    \ build() {\n//     int blk = ceil<int>(N, K);\n//     vvc<int> SI(blk);\n// \
    \    if (len(FRM)) {\n//       vc<int> A(N), B(N);\n\n//       FOR(i, len(FRM))\
    \ { auto [a, b, c, w] = FRM[i]; }\n//       int Q = len(FRM);\n//       vc<int>\
    \ I(Q);\n//       FOR(i, Q) I[i] = i;\n//       rec_frm(0, n, I);\n//       FRM.clear(),\
    \ FRM.shrink_to_fit();\n//     }\n\n//     Q = len(TO);\n//     I.resize(Q);\n\
    //     FOR(i, Q) I[i] = i;\n//     rec_to(0, n, I);\n//     TO.clear(), TO.shrink_to_fit();\n\
    //     // Graph<T, 1> G(n_node);\n//     // for (auto& [a, b, w] : edges) G.add(a,\
    \ b, w);\n//     // G.build();\n//     // return G;\n//   }\n\n//  private:\n\
    //   void rec_frm_small(int L, int R, vc<int>& I) {\n//     if (I.empty()) return;\n\
    //     int M = (L + R) / 2;\n//     vc<int> I1, I2, J;\n//     int s = M, t =\
    \ M;\n//     for (int i : I) {\n//       auto [a, b, c, w] = FRM[i];\n//     \
    \  if (b <= M) {\n//         I1.eb(i);\n//       }\n//       elif (M <= a) { I2.eb(i);\
    \ }\n//       else {\n//         chmin(s, a), chmax(t, b);\n//         J.eb(i);\n\
    //       }\n//     }\n//     rec_frm_small(L, M, I1), rec_frm_small(M, R, I2);\n\
    //     if (J.empty()) return;\n//     A[M - 1] = M - 1, A[M] = M;\n//     FOR_R(i,\
    \ s, M - 1) {\n//       A[i] = n_node++;\n//       add(i, A[i], 0), add(A[i +\
    \ 1], A[i], 0);\n//     }\n//     FOR(i, M + 1, t) {\n//       A[i] = n_node++;\n\
    //       add(i, A[i], 0), add(A[i - 1], A[i], 0);\n//     }\n//     for (int i\
    \ : J) {\n//       auto [a, b, c, w] = FRM[i];\n//       add(A[a], c, w), add(A[b\
    \ - 1], c, w);\n//     }\n//   }\n\n//   void rec_to(int L, int R, vc<int>& I)\
    \ {\n//     if (I.empty()) return;\n//     int M = (L + R) / 2;\n//     vc<int>\
    \ I1, I2, J;\n//     int s = M, t = M;\n//     for (int i : I) {\n//       auto\
    \ [c, a, b, w] = TO[i];\n//       if (b <= M) {\n//         I1.eb(i);\n//    \
    \   }\n//       elif (M <= a) { I2.eb(i); }\n//       else {\n//         chmin(s,\
    \ a), chmax(t, b);\n//         J.eb(i);\n//       }\n//     }\n//     rec_to(L,\
    \ M, I1), rec_to(M, R, I2);\n//     if (J.empty()) return;\n//     A[M - 1] =\
    \ M - 1, A[M] = M;\n//     FOR_R(i, s, M - 1) {\n//       A[i] = n_node++;\n//\
    \       add(A[i], i, 0), add(A[i], A[i + 1], 0);\n//     }\n//     FOR(i, M +\
    \ 1, t) {\n//       A[i] = n_node++;\n//       add(A[i], i, 0), add(A[i], A[i\
    \ - 1], 0);\n//     }\n//     for (int i : J) {\n//       auto [c, a, b, w] =\
    \ TO[i];\n//       add(c, A[a], w), add(c, A[b - 1], w);\n//     }\n//   }\n//\
    \ };"
  dependsOn:
  - graph/base.hpp
  - ds/hashmap.hpp
  isVerificationFile: false
  path: graph/range_to_range_graph.hpp
  requiredBy: []
  timestamp: '2026-08-17 16:26:58+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/3_yukicoder/1868.test.cpp
  - test/3_yukicoder/1170.test.cpp
documentation_of: graph/range_to_range_graph.hpp
layout: document
redirect_from:
- /library/graph/range_to_range_graph.hpp
- /library/graph/range_to_range_graph.hpp.html
title: graph/range_to_range_graph.hpp
---
