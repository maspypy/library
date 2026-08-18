---
data:
  _extendedDependsOn:
  - icon: ':question:'
    path: ds/fastset.hpp
    title: ds/fastset.hpp
  - icon: ':question:'
    path: ds/hashmap.hpp
    title: ds/hashmap.hpp
  - icon: ':question:'
    path: graph/base.hpp
    title: graph/base.hpp
  - icon: ':question:'
    path: other/bit.hpp
    title: other/bit.hpp
  _extendedRequiredBy:
  - icon: ':heavy_check_mark:'
    path: graph/all_cycle_common_vertices.hpp
    title: graph/all_cycle_common_vertices.hpp
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/1_mytest/all_cycle_common_vertex.test.cpp
    title: test/1_mytest/all_cycle_common_vertex.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/4_aoj/2251_1.test.cpp
    title: test/4_aoj/2251_1.test.cpp
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
    \ {\n      vc_indeg[e.to]++, vc_outdeg[e.frm]++;\n    }\n  }\n};\n#line 1 \"other/bit.hpp\"\
    \n\nint popcnt(int x) { return __builtin_popcount(x); }\nint popcnt(u32 x) { return\
    \ __builtin_popcount(x); }\nint popcnt(ll x) { return __builtin_popcountll(x);\
    \ }\nint popcnt(u64 x) { return __builtin_popcountll(x); }\nint popcnt_sgn(int\
    \ x) { return (__builtin_parity(unsigned(x)) & 1 ? -1 : 1); }\nint popcnt_sgn(u32\
    \ x) { return (__builtin_parity(x) & 1 ? -1 : 1); }\nint popcnt_sgn(ll x) { return\
    \ (__builtin_parityll(x) & 1 ? -1 : 1); }\nint popcnt_sgn(u64 x) { return (__builtin_parityll(x)\
    \ & 1 ? -1 : 1); }\n// (0, 1, 2, 3, 4) -> (-1, 0, 1, 1, 2)\nint topbit(int x)\
    \ { return (x == 0 ? -1 : 31 - __builtin_clz(x)); }\nint topbit(u32 x) { return\
    \ (x == 0 ? -1 : 31 - __builtin_clz(x)); }\nint topbit(ll x) { return (x == 0\
    \ ? -1 : 63 - __builtin_clzll(x)); }\nint topbit(u64 x) { return (x == 0 ? -1\
    \ : 63 - __builtin_clzll(x)); }\n// (0, 1, 2, 3, 4) -> (-1, 0, 1, 0, 2)\nint lowbit(int\
    \ x) { return (x == 0 ? -1 : __builtin_ctz(x)); }\nint lowbit(u32 x) { return\
    \ (x == 0 ? -1 : __builtin_ctz(x)); }\nint lowbit(ll x) { return (x == 0 ? -1\
    \ : __builtin_ctzll(x)); }\nint lowbit(u64 x) { return (x == 0 ? -1 : __builtin_ctzll(x));\
    \ }\n\ntemplate <typename T>\nT kth_bit(int k) {\n  return T(1) << k;\n}\ntemplate\
    \ <typename T>\nbool has_kth_bit(T x, int k) {\n  return x >> k & 1;\n}\n\ntemplate\
    \ <typename UINT>\nstruct all_bit {\n  UINT s;\n  all_bit(UINT s) : s(s) {}\n\
    \  struct iter {\n    UINT s;\n    int operator*() const { return lowbit(s); }\n\
    \    void operator++() { s &= s - 1; }\n    bool operator!=(nullptr_t) const {\
    \ return s; }\n  };\n  iter begin() const { return {s}; }\n  nullptr_t end() const\
    \ { return nullptr; }\n};\n\ntemplate <typename UINT>\nstruct all_subset {\n \
    \ UINT s;\n  all_subset(UINT s) : s(s) {}\n  struct iter {\n    UINT s, t;\n \
    \   bool done = false;\n    UINT operator*() const { return t; }\n    void operator++()\
    \ {\n      done = (t == 0);\n      t = (t - 1) & s;\n    }\n    bool operator!=(nullptr_t)\
    \ const { return !done; }\n  };\n  iter begin() const { return {s, s}; }\n  nullptr_t\
    \ end() const { return nullptr; }\n};\n\nconstexpr u64 full_mask(int n) { return\
    \ n == 64 ? -1ULL : (1ULL << n) - 1; }\n\nu64 bit_reverse(u64 x) {\n  x = ((x\
    \ & 0x5555555555555555ULL) << 1) | ((x >> 1) & 0x5555555555555555ULL);\n  x =\
    \ ((x & 0x3333333333333333ULL) << 2) | ((x >> 2) & 0x3333333333333333ULL);\n \
    \ x = ((x & 0x0f0f0f0f0f0f0f0fULL) << 4) | ((x >> 4) & 0x0f0f0f0f0f0f0f0fULL);\n\
    \  x = ((x & 0x00ff00ff00ff00ffULL) << 8) | ((x >> 8) & 0x00ff00ff00ff00ffULL);\n\
    \  x = ((x & 0x0000ffff0000ffffULL) << 16) | ((x >> 16) & 0x0000ffff0000ffffULL);\n\
    \  x = (x << 32) | (x >> 32);\n  return x;\n}\n#line 2 \"ds/fastset.hpp\"\n\n\
    // 64-ary tree\n// space: (N/63) * u64\nstruct FastSet {\n  static constexpr u32\
    \ B = 64;\n  int n = 0, log = 0;\n  vvc<u64> seg;\n\n  FastSet() {}\n  FastSet(int\
    \ n) { build(n); }\n\n  int size() { return n; }\n\n  void fill_one() {\n    int\
    \ cur = n;\n    for (auto& vs : seg) {\n      int p = cur / B, q = cur % B;\n\
    \      FOR(i, p) vs[i] = -1ull;\n      if (q) vs[p] = full_mask(q);\n      cur\
    \ = (cur + B - 1) / B;\n    }\n  }\n\n  template <typename F>\n  FastSet(int n,\
    \ F f) {\n    build(n, f);\n  }\n\n  void build(int m) {\n    seg.clear();\n \
    \   n = m;\n    do {\n      seg.push_back(vc<u64>((m + B - 1) / B));\n      m\
    \ = (m + B - 1) / B;\n    } while (m > 1);\n    log = len(seg);\n  }\n  template\
    \ <typename F>\n  void build(int n, F f) {\n    build(n);\n    FOR(i, n) { seg[0][i\
    \ / B] |= u64(f(i)) << (i % B); }\n    FOR(h, log - 1) {\n      FOR(i, len(seg[h]))\
    \ {\n        seg[h + 1][i / B] |= u64(bool(seg[h][i])) << (i % B);\n      }\n\
    \    }\n  }\n\n  bool operator[](int i) const { return seg[0][i / B] >> (i % B)\
    \ & 1; }\n  void insert(int i) {\n    assert(0 <= i && i < n);\n    for (int h\
    \ = 0; h < log; h++) {\n      seg[h][i / B] |= u64(1) << (i % B), i /= B;\n  \
    \  }\n  }\n  void add(int i) { insert(i); }\n  void erase(int i) {\n    assert(0\
    \ <= i && i < n);\n    u64 x = 0;\n    for (int h = 0; h < log; h++) {\n     \
    \ seg[h][i / B] &= ~(u64(1) << (i % B));\n      seg[h][i / B] |= x << (i % B);\n\
    \      x = bool(seg[h][i / B]);\n      i /= B;\n    }\n  }\n  void remove(int\
    \ i) { erase(i); }\n\n  // min[x,n) or n\n  int next(int i) {\n    assert(i <=\
    \ n);\n    chmax(i, 0);\n    for (int h = 0; h < log; h++) {\n      if (i / B\
    \ == seg[h].size()) break;\n      u64 d = seg[h][i / B] >> (i % B);\n      if\
    \ (!d) {\n        i = i / B + 1;\n        continue;\n      }\n      i += lowbit(d);\n\
    \      for (int g = h - 1; g >= 0; g--) {\n        i *= B;\n        i += lowbit(seg[g][i\
    \ / B]);\n      }\n      return i;\n    }\n    return n;\n  }\n\n  // max [0,x],\
    \ or -1\n  int prev(int i) {\n    assert(i >= -1);\n    if (i >= n) i = n - 1;\n\
    \    for (int h = 0; h < log; h++) {\n      if (i == -1) break;\n      u64 d =\
    \ seg[h][i / B] << (63 - i % B);\n      if (!d) {\n        i = i / B - 1;\n  \
    \      continue;\n      }\n      i -= __builtin_clzll(d);\n      for (int g =\
    \ h - 1; g >= 0; g--) {\n        i *= B;\n        i += topbit(seg[g][i / B]);\n\
    \      }\n      return i;\n    }\n    return -1;\n  }\n\n  bool any(int l, int\
    \ r) { return next(l) < r; }\n\n  // [l, r)\n  template <typename F>\n  void enumerate(int\
    \ l, int r, F f) {\n    for (int x = next(l); x < r; x = next(x + 1)) f(x);\n\
    \  }\n\n  void reset() {\n    enumerate(0, n, [&](int i) -> void { erase(i); });\n\
    \  }\n\n  string to_string() {\n    string s(n, '?');\n    for (int i = 0; i <\
    \ n; ++i) s[i] = ((*this)[i] ? '1' : '0');\n    return s;\n  }\n};\n#line 3 \"\
    graph/toposort.hpp\"\n\n// \u8F9E\u66F8\u9806\u6700\u5C0F\u306E toposort \u3092\
    \u8FD4\u3059\ntemplate <typename GT>\nvc<int> toposort(GT& G) {\n  static_assert(GT::is_directed);\n\
    \  assert(G.is_prepared());\n  const int N = G.N;\n  auto [indeg, outdeg] = G.deg_array_inout();\n\
    \  FastSet que(N);\n  vc<int> V;\n  FOR(v, N) if (indeg[v] == 0) que.insert(v);\n\
    \  while (1) {\n    int v = que.next(0);\n    if (v == N) break;\n    que.erase(v),\
    \ V.eb(v);\n    for (auto&& e: G[v]) {\n      if (--indeg[e.to] == 0) que.insert(e.to);\n\
    \    }\n  }\n  return (len(V) < N ? vc<int>{} : V);\n}\n\n// inv_perm=true: inv\
    \ perm \u304C\u8F9E\u66F8\u6700\u5C0F\uFF08\u5404\u30A4\u30F3\u30C7\u30C3\u30AF\
    \u30B9\u306E\u73FE\u308C\u308B\u5834\u6240\u306E\u5217\u304C\u6700\u5C0F\uFF09\
    \ntemplate <typename GT>\nvc<int> lex_min_toposort(GT& G, bool inv_perm = false)\
    \ {\n  static_assert(GT::is_directed);\n  assert(G.is_prepared());\n  const int\
    \ N = G.N;\n  if (inv_perm) {\n    GT H(N);\n    for (auto& e: G.edges) H.add(N\
    \ - 1 - e.to, N - 1 - e.frm);\n    H.build();\n    auto V = lex_min_toposort(H,\
    \ false);\n    reverse(all(V));\n    for (auto& x: V) x = N - 1 - x;\n    return\
    \ V;\n  }\n  auto [indeg, outdeg] = G.deg_array_inout();\n  FastSet que(N);\n\
    \  vc<int> V;\n  FOR(v, N) if (indeg[v] == 0) que.insert(v);\n  while (1) {\n\
    \    int v = que.next(0);\n    if (v == N) break;\n    que.erase(v), V.eb(v);\n\
    \    for (auto&& e: G[v]) {\n      if (--indeg[e.to] == 0) que.insert(e.to);\n\
    \    }\n  }\n  return (len(V) < N ? vc<int>{} : V);\n}\n"
  code: "#include \"graph/base.hpp\"\n#include \"ds/fastset.hpp\"\n\n// \u8F9E\u66F8\
    \u9806\u6700\u5C0F\u306E toposort \u3092\u8FD4\u3059\ntemplate <typename GT>\n\
    vc<int> toposort(GT& G) {\n  static_assert(GT::is_directed);\n  assert(G.is_prepared());\n\
    \  const int N = G.N;\n  auto [indeg, outdeg] = G.deg_array_inout();\n  FastSet\
    \ que(N);\n  vc<int> V;\n  FOR(v, N) if (indeg[v] == 0) que.insert(v);\n  while\
    \ (1) {\n    int v = que.next(0);\n    if (v == N) break;\n    que.erase(v), V.eb(v);\n\
    \    for (auto&& e: G[v]) {\n      if (--indeg[e.to] == 0) que.insert(e.to);\n\
    \    }\n  }\n  return (len(V) < N ? vc<int>{} : V);\n}\n\n// inv_perm=true: inv\
    \ perm \u304C\u8F9E\u66F8\u6700\u5C0F\uFF08\u5404\u30A4\u30F3\u30C7\u30C3\u30AF\
    \u30B9\u306E\u73FE\u308C\u308B\u5834\u6240\u306E\u5217\u304C\u6700\u5C0F\uFF09\
    \ntemplate <typename GT>\nvc<int> lex_min_toposort(GT& G, bool inv_perm = false)\
    \ {\n  static_assert(GT::is_directed);\n  assert(G.is_prepared());\n  const int\
    \ N = G.N;\n  if (inv_perm) {\n    GT H(N);\n    for (auto& e: G.edges) H.add(N\
    \ - 1 - e.to, N - 1 - e.frm);\n    H.build();\n    auto V = lex_min_toposort(H,\
    \ false);\n    reverse(all(V));\n    for (auto& x: V) x = N - 1 - x;\n    return\
    \ V;\n  }\n  auto [indeg, outdeg] = G.deg_array_inout();\n  FastSet que(N);\n\
    \  vc<int> V;\n  FOR(v, N) if (indeg[v] == 0) que.insert(v);\n  while (1) {\n\
    \    int v = que.next(0);\n    if (v == N) break;\n    que.erase(v), V.eb(v);\n\
    \    for (auto&& e: G[v]) {\n      if (--indeg[e.to] == 0) que.insert(e.to);\n\
    \    }\n  }\n  return (len(V) < N ? vc<int>{} : V);\n}\n"
  dependsOn:
  - graph/base.hpp
  - ds/hashmap.hpp
  - ds/fastset.hpp
  - other/bit.hpp
  isVerificationFile: false
  path: graph/toposort.hpp
  requiredBy:
  - graph/all_cycle_common_vertices.hpp
  timestamp: '2026-08-19 06:34:57+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/1_mytest/all_cycle_common_vertex.test.cpp
  - test/4_aoj/2251_1.test.cpp
documentation_of: graph/toposort.hpp
layout: document
redirect_from:
- /library/graph/toposort.hpp
- /library/graph/toposort.hpp.html
title: graph/toposort.hpp
---
