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
    path: mod/modint.hpp
    title: mod/modint.hpp
  - icon: ':question:'
    path: mod/modint_common.hpp
    title: mod/modint_common.hpp
  - icon: ':question:'
    path: other/bit.hpp
    title: other/bit.hpp
  - icon: ':heavy_check_mark:'
    path: setfunc/bitwise_transform.hpp
    title: setfunc/bitwise_transform.hpp
  - icon: ':heavy_check_mark:'
    path: setfunc/ranked_zeta.hpp
    title: setfunc/ranked_zeta.hpp
  - icon: ':heavy_check_mark:'
    path: setfunc/sps_composition.hpp
    title: setfunc/sps_composition.hpp
  - icon: ':warning:'
    path: setfunc/sps_log.hpp
    title: setfunc/sps_log.hpp
  _extendedRequiredBy:
  - icon: ':warning:'
    path: graph/count/count_biconnected_subgraph.hpp
    title: graph/count/count_biconnected_subgraph.hpp
  - icon: ':warning:'
    path: graph/count/count_bridgeless_subgraph.hpp
    title: graph/count/count_bridgeless_subgraph.hpp
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':warning:'
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
    \ {\n      vc_indeg[e.to]++, vc_outdeg[e.frm]++;\n    }\n  }\n};\n#line 1 \"mod/modint_common.hpp\"\
    \n\n#line 1 \"other/bit.hpp\"\n\nint popcnt(int x) { return __builtin_popcount(x);\
    \ }\nint popcnt(u32 x) { return __builtin_popcount(x); }\nint popcnt(ll x) { return\
    \ __builtin_popcountll(x); }\nint popcnt(u64 x) { return __builtin_popcountll(x);\
    \ }\nint popcnt_sgn(int x) { return (__builtin_parity(unsigned(x)) & 1 ? -1 :\
    \ 1); }\nint popcnt_sgn(u32 x) { return (__builtin_parity(x) & 1 ? -1 : 1); }\n\
    int popcnt_sgn(ll x) { return (__builtin_parityll(x) & 1 ? -1 : 1); }\nint popcnt_sgn(u64\
    \ x) { return (__builtin_parityll(x) & 1 ? -1 : 1); }\n// (0, 1, 2, 3, 4) -> (-1,\
    \ 0, 1, 1, 2)\nint topbit(int x) { return (x == 0 ? -1 : 31 - __builtin_clz(x));\
    \ }\nint topbit(u32 x) { return (x == 0 ? -1 : 31 - __builtin_clz(x)); }\nint\
    \ topbit(ll x) { return (x == 0 ? -1 : 63 - __builtin_clzll(x)); }\nint topbit(u64\
    \ x) { return (x == 0 ? -1 : 63 - __builtin_clzll(x)); }\n// (0, 1, 2, 3, 4) ->\
    \ (-1, 0, 1, 0, 2)\nint lowbit(int x) { return (x == 0 ? -1 : __builtin_ctz(x));\
    \ }\nint lowbit(u32 x) { return (x == 0 ? -1 : __builtin_ctz(x)); }\nint lowbit(ll\
    \ x) { return (x == 0 ? -1 : __builtin_ctzll(x)); }\nint lowbit(u64 x) { return\
    \ (x == 0 ? -1 : __builtin_ctzll(x)); }\n\ntemplate <typename T>\nT kth_bit(int\
    \ k) {\n  assert(0 <= k && k < int(8 * sizeof(T)));\n  return T(1) << k;\n}\n\
    template <typename T>\nbool has_kth_bit(T x, int k) {\n  assert(0 <= k && k <\
    \ int(8 * sizeof(T)));\n  return x >> k & 1;\n}\n\ntemplate <typename UINT>\n\
    struct all_bit {\n  static_assert(is_unsigned<UINT>::value);\n  UINT s;\n  all_bit(UINT\
    \ s) : s(s) {}\n  struct iter {\n    UINT s;\n    int operator*() const { return\
    \ lowbit(s); }\n    void operator++() { s &= s - 1; }\n    bool operator!=(nullptr_t)\
    \ const { return s; }\n  };\n  iter begin() const { return {s}; }\n  nullptr_t\
    \ end() const { return nullptr; }\n};\n\ntemplate <typename UINT>\nstruct all_subset\
    \ {\n  static_assert(is_unsigned<UINT>::value);\n  UINT s;\n  all_subset(UINT\
    \ s) : s(s) {}\n  struct iter {\n    UINT s, t;\n    bool done = false;\n    UINT\
    \ operator*() const { return t; }\n    void operator++() {\n      done = (t ==\
    \ 0);\n      t = (t - 1) & s;\n    }\n    bool operator!=(nullptr_t) const { return\
    \ !done; }\n  };\n  iter begin() const { return {s, s}; }\n  nullptr_t end() const\
    \ { return nullptr; }\n};\n\nconstexpr u64 full_mask(int n) {\n  assert(0 <= n\
    \ && n <= 64);\n  return n == 64 ? -1ULL : (1ULL << n) - 1;\n}\n\nu64 bit_reverse(u64\
    \ x) {\n  x = ((x & 0x5555555555555555ULL) << 1) | ((x >> 1) & 0x5555555555555555ULL);\n\
    \  x = ((x & 0x3333333333333333ULL) << 2) | ((x >> 2) & 0x3333333333333333ULL);\n\
    \  x = ((x & 0x0f0f0f0f0f0f0f0fULL) << 4) | ((x >> 4) & 0x0f0f0f0f0f0f0f0fULL);\n\
    \  x = ((x & 0x00ff00ff00ff00ffULL) << 8) | ((x >> 8) & 0x00ff00ff00ff00ffULL);\n\
    \  x = ((x & 0x0000ffff0000ffffULL) << 16) | ((x >> 16) & 0x0000ffff0000ffffULL);\n\
    \  x = (x << 32) | (x >> 32);\n  return x;\n}\n#line 3 \"mod/modint_common.hpp\"\
    \n\nstruct has_mod_impl {\n  template <class T>\n  static auto check(T &&x) ->\
    \ decltype(x.get_mod(), std::true_type{});\n  template <class T>\n  static auto\
    \ check(...) -> std::false_type;\n};\n\ntemplate <class T>\nclass has_mod : public\
    \ decltype(has_mod_impl::check<T>(std::declval<T>())) {};\n\ntemplate <typename\
    \ mint>\nmint fact(int n) {\n  static const int mod = mint::get_mod();\n  assert(0\
    \ <= n && n < mod);\n  static vector<mint> dat = {1, 1};\n  if (len(dat) <= n)\
    \ {\n    int now = len(dat);\n    int m = min(mod, 1 << (topbit(n) + 1));\n  \
    \  dat.resize(m);\n    FOR(i, now, m) dat[i] = dat[i - 1] * mint::raw(i);\n  }\n\
    \  return dat[n];\n}\n\ntemplate <typename mint>\nmint fact_inv(int n) {\n  static\
    \ const int mod = mint::get_mod();\n  static vector<mint> dat = {1, 1};\n  if\
    \ (n < 0) return mint(0);\n  if (len(dat) <= n) {\n    int now = len(dat);\n \
    \   int m = min(mod, 1 << (topbit(n) + 1));\n    dat.resize(m);\n    dat[m - 1]\
    \ = fact<mint>(m - 1).inverse();\n    FOR_R(i, now, m - 1) dat[i] = dat[i + 1]\
    \ * mint::raw(i + 1);\n  }\n  return dat[n];\n}\n\ntemplate <class mint, class...\
    \ Ts>\nmint fact_invs(Ts... xs) {\n  return (mint(1) * ... * fact_inv<mint>(xs));\n\
    }\n\ntemplate <typename mint>\nmint inv(int n) {\n  static const int mod = mint::get_mod();\n\
    \  assert(1 <= n && n < mod);\n  return fact<mint>(n - 1) * fact_inv<mint>(n);\n\
    }\n\ntemplate <>\ndouble inv<double>(int n) {\n  assert(n != 0);\n  return 1.0\
    \ / n;\n}\n\ntemplate <typename mint, class Head, class... Tail>\nmint multinomial(Head\
    \ &&head, Tail &&...tail) {\n  return fact<mint>(head) * fact_invs<mint>(std::forward<Tail>(tail)...);\n\
    }\n\ntemplate <typename mint>\nmint C_dense(int n, int k) {\n  assert(n >= 0);\n\
    \  if (k < 0 || n < k) return 0;\n  static vvc<mint> C;\n  static int H = 0, W\
    \ = 0;\n  auto calc = [&](int i, int j) -> mint {\n    if (i == 0) return (j ==\
    \ 0 ? mint(1) : mint(0));\n    return C[i - 1][j] + (j ? C[i - 1][j - 1] : 0);\n\
    \  };\n  if (W <= k) {\n    FOR(i, H) {\n      C[i].resize(k + 1);\n      FOR(j,\
    \ W, k + 1) { C[i][j] = calc(i, j); }\n    }\n    W = k + 1;\n  }\n  if (H <=\
    \ n) {\n    C.resize(n + 1);\n    FOR(i, H, n + 1) {\n      C[i].resize(W);\n\
    \      FOR(j, W) { C[i][j] = calc(i, j); }\n    }\n    H = n + 1;\n  }\n  return\
    \ C[n][k];\n}\n\ntemplate <typename mint, bool large = false, bool dense = false>\n\
    mint C(ll n, ll k) {\n  assert(n >= 0);\n  if (k < 0 || n < k) return 0;\n  if\
    \ constexpr (dense) return C_dense<mint>(n, k);\n  if constexpr (!large) return\
    \ multinomial<mint>(n, k, n - k);\n  k = min(k, n - k);\n  mint x(1);\n  FOR(i,\
    \ k) x *= mint(n - i);\n  return x * fact_inv<mint>(k);\n}\n\ntemplate <typename\
    \ mint, bool large = false>\nmint C_inv(ll n, ll k) {\n  assert(n >= 0);\n  assert(0\
    \ <= k && k <= n);\n  if (!large) return fact_inv<mint>(n) * fact<mint>(k) * fact<mint>(n\
    \ - k);\n  return mint(1) / C<mint, 1>(n, k);\n}\n\n// [x^d](1-x)^{-n}\ntemplate\
    \ <typename mint, bool large = false, bool dense = false>\nmint C_negative(ll\
    \ n, ll d) {\n  assert(n >= 0);\n  if (d < 0) return mint(0);\n  if (n == 0) {\n\
    \    return (d == 0 ? mint(1) : mint(0));\n  }\n  return C<mint, large, dense>(n\
    \ + d - 1, d);\n}\n#line 2 \"mod/modint.hpp\"\n\ntemplate <int mod>\nstruct modint\
    \ {\n  static constexpr u32 umod = u32(mod);\n  static_assert(0 < umod && umod\
    \ < u32(1) << 31);\n  u32 val;\n\n  static modint raw(u32 v) {\n    modint x;\n\
    \    x.val = v;\n    return x;\n  }\n  constexpr modint() : val(0) {}\n  constexpr\
    \ modint(u32 x) : val(x % umod) {}\n  constexpr modint(u64 x) : val(x % umod)\
    \ {}\n  constexpr modint(u128 x) : val(x % umod) {}\n  constexpr modint(int x)\
    \ : val((x %= mod) < 0 ? x + mod : x){};\n  constexpr modint(ll x) : val((x %=\
    \ mod) < 0 ? x + mod : x){};\n  constexpr modint(i128 x) : val((x %= mod) < 0\
    \ ? x + mod : x){};\n  bool operator<(const modint &other) const { return val\
    \ < other.val; }\n  modint &operator+=(const modint &p) {\n    if ((val += p.val)\
    \ >= umod) val -= umod;\n    return *this;\n  }\n  modint &operator-=(const modint\
    \ &p) {\n    if ((val += umod - p.val) >= umod) val -= umod;\n    return *this;\n\
    \  }\n  modint &operator*=(const modint &p) {\n    val = u64(val) * p.val % umod;\n\
    \    return *this;\n  }\n  modint &operator/=(const modint &p) {\n    *this *=\
    \ p.inverse();\n    return *this;\n  }\n  modint operator-() const { return modint::raw(val\
    \ ? mod - val : u32(0)); }\n  modint operator+(const modint &p) const { return\
    \ modint(*this) += p; }\n  modint operator-(const modint &p) const { return modint(*this)\
    \ -= p; }\n  modint operator*(const modint &p) const { return modint(*this) *=\
    \ p; }\n  modint operator/(const modint &p) const { return modint(*this) /= p;\
    \ }\n  bool operator==(const modint &p) const { return val == p.val; }\n  bool\
    \ operator!=(const modint &p) const { return val != p.val; }\n  modint inverse()\
    \ const {\n    int a = val, b = mod, u = 1, v = 0, t;\n    while (b > 0) {\n \
    \     t = a / b;\n      swap(a -= t * b, b), swap(u -= t * v, v);\n    }\n   \
    \ return modint(u);\n  }\n  modint pow(ll n) const {\n    if (n < 0) return inverse().pow(-n);\n\
    \    assert(n >= 0);\n    modint ret(1), mul(val);\n    while (n > 0) {\n    \
    \  if (n & 1) ret *= mul;\n      mul *= mul;\n      n >>= 1;\n    }\n    return\
    \ ret;\n  }\n  static constexpr int get_mod() { return mod; }\n  // (n, r), r\
    \ \u306F 1 \u306E 2^n \u4E57\u6839\n  static constexpr pair<int, int> ntt_info()\
    \ {\n    if (mod == 120586241) return {20, 74066978};\n    if (mod == 167772161)\
    \ return {25, 17};\n    if (mod == 469762049) return {26, 30};\n    if (mod ==\
    \ 754974721) return {24, 362};\n    if (mod == 880803841) return {23, 211};\n\
    \    if (mod == 943718401) return {22, 663003469};\n    if (mod == 998244353)\
    \ return {23, 31};\n    if (mod == 1004535809) return {21, 582313106};\n    if\
    \ (mod == 1012924417) return {21, 368093570};\n    if (mod == 1224736769) return\
    \ {24, 1191450770};\n    if (mod == 2013265921) return {27, 244035102};\n    return\
    \ {-1, -1};\n  }\n  static constexpr bool can_ntt() { return ntt_info().fi !=\
    \ -1; }\n};\n\n#ifdef FASTIO\ntemplate <int mod>\nvoid rd(modint<mod> &x) {\n\
    \  fastio::rd(x.val);\n  x.val %= mod;\n  // assert(0 <= x.val && x.val < mod);\n\
    }\ntemplate <int mod>\nvoid wt(modint<mod> x) {\n  fastio::wt(x.val);\n}\n#endif\n\
    \nusing modint107 = modint<1000000007>;\nusing modint998 = modint<998244353>;\n\
    #line 1 \"setfunc/ranked_zeta.hpp\"\n\n#line 1 \"setfunc/bitwise_transform.hpp\"\
    \n\nnamespace bitwise {\n\nenum class trans_type {\n  hadamard,\n  superset_zeta,\n\
    \  superset_mobius,\n  subset_zeta,\n  subset_mobius,\n  ranked_zeta,\n  ranked_mobius,\n\
    \  superset_zeta_or\n};\n\ntemplate <typename ARR>\ninline void ranked_add(ARR&\
    \ a, const ARR& b) {\n  for (int d = 0; d < int(a.size()); ++d) a[d] += b[d];\n\
    }\n\ntemplate <typename ARR>\ninline void ranked_sub(ARR& a, const ARR& b) {\n\
    \  for (int d = 0; d < int(a.size()); ++d) a[d] -= b[d];\n}\n\ntemplate <trans_type\
    \ type, int N, typename T>\ninline void bitwise_transform_fixed(T* a) {\n  static_assert(N\
    \ >= 1 && (N & (N - 1)) == 0);\n  if constexpr (N == 1) {\n    return;\n  } else\
    \ {\n    constexpr int H = N / 2;\n    bitwise_transform_fixed<type, H>(a);\n\
    \    bitwise_transform_fixed<type, H>(a + H);\n    if constexpr (type == trans_type::hadamard)\
    \ {\n      for (int i = 0; i < H; ++i) {\n        auto x = a[i], y = a[H + i];\n\
    \        a[i] = x + y, a[H + i] = x - y;\n      }\n    }\n    if constexpr (type\
    \ == trans_type::superset_zeta) {\n      for (int i = 0; i < H; ++i) a[i] += a[H\
    \ + i];\n    }\n    if constexpr (type == trans_type::superset_mobius) {\n   \
    \   for (int i = 0; i < H; ++i) a[i] -= a[H + i];\n    }\n    if constexpr (type\
    \ == trans_type::subset_zeta) {\n      for (int i = 0; i < H; ++i) a[H + i] +=\
    \ a[i];\n    }\n    if constexpr (type == trans_type::subset_mobius) {\n     \
    \ for (int i = 0; i < H; ++i) a[H + i] -= a[i];\n    }\n    if constexpr (type\
    \ == trans_type::ranked_zeta) {\n      for (int i = 0; i < H; ++i) ranked_add(a[H\
    \ + i], a[i]);\n    }\n    if constexpr (type == trans_type::ranked_mobius) {\n\
    \      for (int i = 0; i < H; ++i) ranked_sub(a[H + i], a[i]);\n    }\n    if\
    \ constexpr (type == trans_type::superset_zeta_or) {\n      for (int i = 0; i\
    \ < H; ++i) a[i] |= a[H + i];\n    }\n  }\n}\n\ntemplate <trans_type type, int\
    \ N, typename T>\ninline void bitwise_transform_dispatch(vc<T>& a) {\n  if (len(a)\
    \ == N) {\n    return bitwise_transform_fixed<type, N>(a.data());\n  }\n  if constexpr\
    \ (N > 1) {\n    return bitwise_transform_dispatch<type, N / 2>(a);\n  }\n}\n\n\
    template <trans_type type, typename T>\ninline void bitwise_transform(vc<T>& a)\
    \ {\n  int n = len(a);\n  assert(n >= 1);\n  assert((n & (n - 1)) == 0);\n  assert(n\
    \ <= (1 << 25));\n  bitwise_transform_dispatch<type, 1 << 25>(a);\n}\n}  // namespace\
    \ bitwise\n#line 3 \"setfunc/ranked_zeta.hpp\"\n\ntemplate <typename T, int LIM>\n\
    vc<array<T, LIM + 1>> ranked_zeta(const vc<T>& f) {\n  int n = topbit(len(f));\n\
    \  assert(n <= LIM);\n  assert(len(f) == 1 << n);\n  vc<array<T, LIM + 1>> Rf(1\
    \ << n);\n  for (int s = 0; s < (1 << n); ++s) Rf[s][popcnt(s)] = f[s];\n  bitwise::bitwise_transform<bitwise::trans_type::ranked_zeta>(Rf);\n\
    \  return Rf;\n}\n\ntemplate <typename T, int LIM>\nvc<T> ranked_mobius(vc<array<T,\
    \ LIM + 1>>& Rf) {\n  bitwise::bitwise_transform<bitwise::trans_type::ranked_mobius>(Rf);\n\
    \  vc<T> f(len(Rf));\n  for (int s = 0; s < len(f); ++s) f[s] = Rf[s][popcnt(s)];\n\
    \  return f;\n}\n#line 2 \"setfunc/sps_composition.hpp\"\n\n// sum_i f_i/i! s^i,\
    \ s^i is subset-convolution\ntemplate <typename mint, int LIM>\nvc<mint> sps_composition_egf(vc<mint>&\
    \ f, vc<mint>& s) {\n  const int N = topbit(len(s));\n  assert(len(s) == (1 <<\
    \ N) && s[0] == mint(0));\n  if (len(f) > N) f.resize(N + 1);\n  int D = len(f)\
    \ - 1;\n  using ARR = array<mint, LIM + 1>;\n  vvc<ARR> zs(N);\n  FOR(i, N) {\
    \ zs[i] = ranked_zeta<mint, LIM>({s.begin() + (1 << i), s.begin() + (2 << i)});\
    \ }\n\n  // dp : (d/dt)^df(s) (d=D,D-1,...)\n  vc<mint> dp(1 << (N - D));\n  dp[0]\
    \ = f[D];\n  FOR_R(d, D) {\n    vc<mint> newdp(1 << (N - d));\n    newdp[0] =\
    \ f[d];\n    vc<ARR> zdp = ranked_zeta<mint, LIM>(dp);\n    FOR(i, N - d) {\n\
    \      // zs[1<<i:2<<i], zdp[0:1<<i]\n      vc<ARR> znewdp(1 << i);\n      FOR(k,\
    \ 1 << i) {\n        FOR(p, i + 1) FOR(q, i - p + 1) { znewdp[k][p + q] += zdp[k][p]\
    \ * zs[i][k][q]; }\n      }\n      auto x = ranked_mobius<mint, LIM>(znewdp);\n\
    \      copy(all(x), newdp.begin() + (1 << i));\n    }\n    swap(dp, newdp);\n\
    \  }\n  return dp;\n}\n\n// sum_i f_i s^i, s^i is subset-convolution\ntemplate\
    \ <typename mint, int LIM>\nvc<mint> sps_composition_poly(vc<mint> f, vc<mint>\
    \ s) {\n  const int N = topbit(len(s));\n  assert(len(s) == (1 << N));\n  if (f.empty())\
    \ return vc<mint>(1 << N, mint(0));\n  // convert to egf problem\n  int D = min<int>(len(f)\
    \ - 1, N);\n  vc<mint> g(D + 1);\n  mint c = s[0];\n  s[0] = 0;\n  // (x+c)^i\n\
    \  vc<mint> pow(D + 1);\n  pow[0] = 1;\n  FOR(i, len(f)) {\n    FOR(j, D + 1)\
    \ g[j] += f[i] * pow[j];\n    FOR_R(j, D + 1) pow[j] = pow[j] * c + (j == 0 ?\
    \ mint(0) : pow[j - 1]);\n  }\n  // to egf\n  mint factorial = 1;\n  FOR(j, D\
    \ + 1) g[j] *= factorial, factorial *= mint(j + 1);\n  return sps_composition_egf<mint,\
    \ LIM>(g, s);\n}\n#line 3 \"setfunc/sps_log.hpp\"\n\n// exp \u306E\u9006\u624B\
    \u9806\u3067\u8A08\u7B97\u3059\u308B\ntemplate <typename mint, int LIM>\nvc<mint>\
    \ sps_log(vc<mint>& dp) {\n  const int N = topbit(len(dp));\n  assert(len(dp)\
    \ == (1 << N) && dp[0] == mint(1));\n  vc<mint> s(1 << N);\n  FOR_R(i, N) {\n\
    \    vc<mint> a = {dp.begin() + (1 << i), dp.begin() + (2 << i)};\n    vc<mint>\
    \ b = {dp.begin(), dp.begin() + (1 << i)};\n    auto RA = ranked_zeta<mint, LIM>(a);\n\
    \    auto RB = ranked_zeta<mint, LIM>(b);\n    FOR(s, 1 << i) {\n      auto &f\
    \ = RA[s], &g = RB[s];\n      // assert(g[0] == mint(1));\n      FOR(d, i + 1)\
    \ { FOR(i, d) f[d] -= f[i] * g[d - i]; }\n    }\n    a = ranked_mobius<mint, LIM>(RA);\n\
    \    copy(all(a), s.begin() + (1 << i));\n  }\n  return s;\n}\n#line 3 \"graph/count/count_connected_subgraph.hpp\"\
    \n\n// O(N^2 2^N)\ntemplate <typename T, int LIM>\nvc<T> count_connected_subgraph(Graph<int,\
    \ 0> G) {\n  int N = G.N;\n  assert(N <= LIM);\n  vc<T> pw(G.M + 1, 1);\n  FOR(i,\
    \ G.M) pw[i + 1] = pw[i] + pw[i];\n\n  // edge\n  vc<int> E(1 << N);\n  for (auto&\
    \ e: G.edges) { E[(1 << e.frm) | (1 << e.to)]++; }\n  FOR(i, N) FOR(s, 1 << N)\
    \ {\n    int t = s | 1 << i;\n    if (s < t) E[t] += E[s];\n  }\n\n  // any graph\n\
    \  vc<T> dp(1 << N);\n  FOR(s, 1 << N) dp[s] = pw[E[s]];\n\n  // connected\n \
    \ return sps_log<T, LIM>(dp);\n}\n"
  code: "#include \"graph/base.hpp\"\n#include \"setfunc/sps_log.hpp\"\n\n// O(N^2\
    \ 2^N)\ntemplate <typename T, int LIM>\nvc<T> count_connected_subgraph(Graph<int,\
    \ 0> G) {\n  int N = G.N;\n  assert(N <= LIM);\n  vc<T> pw(G.M + 1, 1);\n  FOR(i,\
    \ G.M) pw[i + 1] = pw[i] + pw[i];\n\n  // edge\n  vc<int> E(1 << N);\n  for (auto&\
    \ e: G.edges) { E[(1 << e.frm) | (1 << e.to)]++; }\n  FOR(i, N) FOR(s, 1 << N)\
    \ {\n    int t = s | 1 << i;\n    if (s < t) E[t] += E[s];\n  }\n\n  // any graph\n\
    \  vc<T> dp(1 << N);\n  FOR(s, 1 << N) dp[s] = pw[E[s]];\n\n  // connected\n \
    \ return sps_log<T, LIM>(dp);\n}"
  dependsOn:
  - graph/base.hpp
  - ds/hashmap.hpp
  - setfunc/sps_log.hpp
  - mod/modint.hpp
  - mod/modint_common.hpp
  - other/bit.hpp
  - setfunc/sps_composition.hpp
  - setfunc/ranked_zeta.hpp
  - setfunc/bitwise_transform.hpp
  isVerificationFile: false
  path: graph/count/count_connected_subgraph.hpp
  requiredBy:
  - graph/count/count_bridgeless_subgraph.hpp
  - graph/count/count_biconnected_subgraph.hpp
  timestamp: '2026-08-29 09:24:19+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: graph/count/count_connected_subgraph.hpp
layout: document
redirect_from:
- /library/graph/count/count_connected_subgraph.hpp
- /library/graph/count/count_connected_subgraph.hpp.html
title: graph/count/count_connected_subgraph.hpp
---
