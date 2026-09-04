---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: alg/monoid/monoid_reverse.hpp
    title: alg/monoid/monoid_reverse.hpp
  - icon: ':heavy_check_mark:'
    path: ds/hashmap.hpp
    title: ds/hashmap.hpp
  - icon: ':heavy_check_mark:'
    path: ds/segtree/lazy_segtree.hpp
    title: ds/segtree/lazy_segtree.hpp
  - icon: ':heavy_check_mark:'
    path: graph/base.hpp
    title: graph/base.hpp
  - icon: ':heavy_check_mark:'
    path: graph/tree.hpp
    title: graph/tree.hpp
  - icon: ':question:'
    path: other/bit.hpp
    title: other/bit.hpp
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/3_yukicoder/1197.test.cpp
    title: test/3_yukicoder/1197.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/3_yukicoder/1790.test.cpp
    title: test/3_yukicoder/1790.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/3_yukicoder/235.test.cpp
    title: test/3_yukicoder/235.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/4_aoj/GRL_5_E.test.cpp
    title: test/4_aoj/GRL_5_E.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 1 \"alg/monoid/monoid_reverse.hpp\"\n\ntemplate <class Monoid>\n\
    struct Monoid_Reverse {\n  using value_type = typename Monoid::value_type;\n \
    \ using X = value_type;\n  static constexpr X op(const X &x, const X &y) { return\
    \ Monoid::op(y, x); }\n  static constexpr X id() { return Monoid::id(); }\n  static\
    \ const bool commute = Monoid::commute;\n};\n#line 1 \"other/bit.hpp\"\n\nint\
    \ popcnt(int x) { return __builtin_popcount(x); }\nint popcnt(u32 x) { return\
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
    \ }\n\ntemplate <typename T>\nT kth_bit(int k) {\n  assert(0 <= k && k < int(8\
    \ * sizeof(T)));\n  return T(1) << k;\n}\ntemplate <typename T>\nbool has_kth_bit(T\
    \ x, int k) {\n  assert(0 <= k && k < int(8 * sizeof(T)));\n  return x >> k &\
    \ 1;\n}\n\ntemplate <typename UINT>\nstruct all_bit {\n  static_assert(is_unsigned<UINT>::value);\n\
    \  UINT s;\n  all_bit(UINT s) : s(s) {}\n  struct iter {\n    UINT s;\n    int\
    \ operator*() const { return lowbit(s); }\n    void operator++() { s &= s - 1;\
    \ }\n    bool operator!=(nullptr_t) const { return s; }\n  };\n  iter begin()\
    \ const { return {s}; }\n  nullptr_t end() const { return nullptr; }\n};\n\ntemplate\
    \ <typename UINT>\nstruct all_subset {\n  static_assert(is_unsigned<UINT>::value);\n\
    \  UINT s;\n  all_subset(UINT s) : s(s) {}\n  struct iter {\n    UINT s, t;\n\
    \    bool done = false;\n    UINT operator*() const { return t; }\n    void operator++()\
    \ {\n      done = (t == 0);\n      t = (t - 1) & s;\n    }\n    bool operator!=(nullptr_t)\
    \ const { return !done; }\n  };\n  iter begin() const { return {s, s}; }\n  nullptr_t\
    \ end() const { return nullptr; }\n};\n\nconstexpr u64 full_mask(int n) {\n  assert(0\
    \ <= n && n <= 64);\n  return n == 64 ? -1ULL : (1ULL << n) - 1;\n}\n\nu64 bit_reverse(u64\
    \ x) {\n  x = ((x & 0x5555555555555555ULL) << 1) | ((x >> 1) & 0x5555555555555555ULL);\n\
    \  x = ((x & 0x3333333333333333ULL) << 2) | ((x >> 2) & 0x3333333333333333ULL);\n\
    \  x = ((x & 0x0f0f0f0f0f0f0f0fULL) << 4) | ((x >> 4) & 0x0f0f0f0f0f0f0f0fULL);\n\
    \  x = ((x & 0x00ff00ff00ff00ffULL) << 8) | ((x >> 8) & 0x00ff00ff00ff00ffULL);\n\
    \  x = ((x & 0x0000ffff0000ffffULL) << 16) | ((x >> 16) & 0x0000ffff0000ffffULL);\n\
    \  x = (x << 32) | (x >> 32);\n  return x;\n}\n#line 2 \"ds/segtree/lazy_segtree.hpp\"\
    \n\ntemplate <typename ActedMonoid>\nstruct Lazy_SegTree {\n  using AM = ActedMonoid;\n\
    \  using MX = typename AM::Monoid_X;\n  using MA = typename AM::Monoid_A;\n  using\
    \ X = typename MX::value_type;\n  using A = typename MA::value_type;\n  int n,\
    \ log, size;\n  vc<X> dat;\n  vc<A> laz;\n  vc<bool> has_laz;\n\n  Lazy_SegTree()\
    \ {}\n  Lazy_SegTree(int n) { build(n); }\n  template <typename F>\n  Lazy_SegTree(int\
    \ n, F f) {\n    build(n, f);\n  }\n  Lazy_SegTree(const vc<X>& v) { build(v);\
    \ }\n\n  void build(int m) {\n    build(m, [](int i) -> X { return MX::id(); });\n\
    \  }\n  void build(const vc<X>& v) {\n    build(len(v), [&](int i) -> X { return\
    \ v[i]; });\n  }\n  template <typename F>\n  void build(int m, F f) {\n    n =\
    \ m, log = 1;\n    while ((1 << log) < n) ++log;\n    size = 1 << log;\n    dat.assign(size\
    \ << 1, MX::id());\n    laz.assign(size, MA::id());\n    has_laz.assign(size,\
    \ false);\n    FOR(i, n) dat[size + i] = f(i);\n    FOR_R(i, 1, size) update(i);\n\
    \  }\n\n  void update(int k) { dat[k] = MX::op(dat[2 * k], dat[2 * k + 1]); }\n\
    \  void set(int p, X x) {\n    assert(0 <= p && p < n);\n    p += size;\n    for\
    \ (int i = log; i >= 1; i--) push(p >> i);\n    dat[p] = x;\n    for (int i =\
    \ 1; i <= log; i++) update(p >> i);\n  }\n  void multiply(int p, const X& x) {\n\
    \    assert(0 <= p && p < n);\n    p += size;\n    for (int i = log; i >= 1; i--)\
    \ push(p >> i);\n    dat[p] = MX::op(dat[p], x);\n    for (int i = 1; i <= log;\
    \ i++) update(p >> i);\n  }\n\n  X get(int p) {\n    assert(0 <= p && p < n);\n\
    \    p += size;\n    for (int i = log; i >= 1; i--) push(p >> i);\n    return\
    \ dat[p];\n  }\n\n  vc<X> get_all() {\n    FOR(k, 1, size) { push(k); }\n    return\
    \ {dat.begin() + size, dat.begin() + size + n};\n  }\n\n  X prod(int l, int r)\
    \ {\n    assert(0 <= l && l <= r && r <= n);\n    if (l == r) return MX::id();\n\
    \    l += size, r += size;\n    for (int i = log; i >= 1; i--) {\n      if (((l\
    \ >> i) << i) != l) push(l >> i);\n      if (((r >> i) << i) != r) push((r - 1)\
    \ >> i);\n    }\n    X xl = MX::id(), xr = MX::id();\n    while (l < r) {\n  \
    \    if (l & 1) xl = MX::op(xl, dat[l++]);\n      if (r & 1) xr = MX::op(dat[--r],\
    \ xr);\n      l >>= 1, r >>= 1;\n    }\n    return MX::op(xl, xr);\n  }\n\n  X\
    \ prod_all() { return dat[1]; }\n\n  void apply(int l, int r, A a) {\n    assert(0\
    \ <= l && l <= r && r <= n);\n    if (l == r) return;\n    l += size, r += size;\n\
    \    for (int i = log; i >= 1; i--) {\n      if (((l >> i) << i) != l) push(l\
    \ >> i);\n      if (((r >> i) << i) != r) push((r - 1) >> i);\n    }\n    int\
    \ l2 = l, r2 = r;\n    while (l < r) {\n      if (l & 1) apply_at(l++, a);\n \
    \     if (r & 1) apply_at(--r, a);\n      l >>= 1, r >>= 1;\n    }\n    l = l2,\
    \ r = r2;\n    for (int i = 1; i <= log; i++) {\n      if (((l >> i) << i) !=\
    \ l) update(l >> i);\n      if (((r >> i) << i) != r) update((r - 1) >> i);\n\
    \    }\n  }\n\n  template <typename F>\n  int max_right(const F check, int l)\
    \ {\n    assert(0 <= l && l <= n);\n    assert(check(MX::id()));\n    if (l ==\
    \ n) return n;\n    l += size;\n    for (int i = log; i >= 1; i--) push(l >> i);\n\
    \    X sm = MX::id();\n    do {\n      while (l % 2 == 0) l >>= 1;\n      if (!check(MX::op(sm,\
    \ dat[l]))) {\n        while (l < size) {\n          push(l);\n          l = (2\
    \ * l);\n          if (check(MX::op(sm, dat[l]))) {\n            sm = MX::op(sm,\
    \ dat[l++]);\n          }\n        }\n        return l - size;\n      }\n    \
    \  sm = MX::op(sm, dat[l++]);\n    } while ((l & -l) != l);\n    return n;\n \
    \ }\n\n  template <typename F>\n  int min_left(const F check, int r) {\n    assert(0\
    \ <= r && r <= n);\n    assert(check(MX::id()));\n    if (r == 0) return 0;\n\
    \    r += size;\n    for (int i = log; i >= 1; i--) push((r - 1) >> i);\n    X\
    \ sm = MX::id();\n    do {\n      r--;\n      while (r > 1 && (r % 2)) r >>= 1;\n\
    \      if (!check(MX::op(dat[r], sm))) {\n        while (r < size) {\n       \
    \   push(r);\n          r = (2 * r + 1);\n          if (check(MX::op(dat[r], sm)))\
    \ {\n            sm = MX::op(dat[r--], sm);\n          }\n        }\n        return\
    \ r + 1 - size;\n      }\n      sm = MX::op(dat[r], sm);\n    } while ((r & -r)\
    \ != r);\n    return 0;\n  }\n\n  // l <= i xor (xor_val) < r \u3068\u306A\u308B\
    \ i \u5168\u4F53\u306B apply\n  void apply_xor_range(int l, int r, int xor_val,\
    \ A a) {\n    assert(!(n & (n - 1)));\n    assert(0 <= xor_val && xor_val < n);\n\
    \    assert(0 <= l && l <= r && r <= n);\n\n    auto dfs = [&](auto& dfs, int\
    \ idx, int seg_l, int seg_r) -> void {\n      if (l <= seg_l && seg_r <= r) {\n\
    \        return apply_at(idx, a);\n      }\n      if (r <= seg_l || seg_r <= l)\
    \ return;\n      push(idx);\n      int seg_m = (seg_l + seg_r) / 2;\n      int\
    \ bit = (seg_r - seg_l) / 2;\n      int left = 2 * idx + 0, right = 2 * idx +\
    \ 1;\n      if (xor_val & bit) swap(left, right);\n      dfs(dfs, left, seg_l,\
    \ seg_m);\n      dfs(dfs, right, seg_m, seg_r);\n      update(idx);\n    };\n\
    \    dfs(dfs, 1, 0, n);\n  }\n\n private:\n  void apply_at(int k, A a) {\n   \
    \ ll sz = 1 << (log - topbit(k));\n    dat[k] = AM::act(dat[k], a, sz);\n    if\
    \ (k < size) has_laz[k] = 1, laz[k] = MA::op(laz[k], a);\n  }\n  void push(int\
    \ k) {\n    if (!has_laz[k]) return;\n    has_laz[k] = 0;\n    apply_at(2 * k,\
    \ laz[k]), apply_at(2 * k + 1, laz[k]);\n    laz[k] = MA::id();\n  }\n};\n#line\
    \ 1 \"graph/tree.hpp\"\n\n#line 1 \"ds/hashmap.hpp\"\n\n// u64 -> Val\ntemplate\
    \ <typename Val>\nstruct HashMap {\n  // n \u306F\u5165\u308C\u305F\u3044\u3082\
    \u306E\u306E\u500B\u6570\u3067 ok\n  HashMap(u32 n = 0) { build(n); }\n  void\
    \ build(u32 n) {\n    u32 k = 8;\n    while (k < n * 2) k *= 2;\n    cap = k /\
    \ 2, mask = k - 1;\n    key.resize(k), val.resize(k), used.assign(k, 0);\n  }\n\
    \n  // size \u3092\u4FDD\u3063\u305F\u307E\u307E. size=0 \u306B\u3059\u308B\u3068\
    \u304D\u306F build \u3059\u308B\u3053\u3068.\n  void clear() {\n    used.assign(len(used),\
    \ 0);\n    cap = (mask + 1) / 2;\n  }\n  int size() { return len(used) / 2 - cap;\
    \ }\n\n  int index(const u64& k) {\n    int i = 0;\n    for (i = hash(k); used[i]\
    \ && key[i] != k; i = (i + 1) & mask) {\n    }\n    return i;\n  }\n\n  Val& operator[](const\
    \ u64& k) {\n    int i = index(k);\n    if (used[i]) return val[i];\n    if (cap\
    \ == 0) extend(), i = index(k);\n    used[i] = 1, key[i] = k, val[i] = Val{},\
    \ --cap;\n    return val[i];\n  }\n\n  Val get(const u64& k, Val default_value)\
    \ {\n    int i = index(k);\n    return (used[i] ? val[i] : default_value);\n \
    \ }\n\n  bool count(const u64& k) {\n    int i = index(k);\n    return used[i]\
    \ && key[i] == k;\n  }\n\n  // f(key, val)\n  template <typename F>\n  void enumerate_all(F\
    \ f) {\n    FOR(i, len(used)) if (used[i]) f(key[i], val[i]);\n  }\n\n private:\n\
    \  u32 cap, mask;\n  vc<u64> key;\n  vc<Val> val;\n  vc<bool> used;\n\n  u64 hash(u64\
    \ x) {\n    static const u64 FIXED_RANDOM =\n        std::chrono::steady_clock::now().time_since_epoch().count();\n\
    \    x += FIXED_RANDOM;\n    x = (x ^ (x >> 30)) * 0xbf58476d1ce4e5b9;\n    x\
    \ = (x ^ (x >> 27)) * 0x94d049bb133111eb;\n    return (x ^ (x >> 31)) & mask;\n\
    \  }\n\n  void extend() {\n    vc<pair<u64, Val>> dat;\n    dat.reserve(len(used)\
    \ / 2 - cap);\n    FOR(i, len(used)) {\n      if (used[i]) dat.eb(key[i], val[i]);\n\
    \    }\n    build(2 * len(dat));\n    for (auto& [a, b] : dat) (*this)[a] = b;\n\
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
    \ st.eb(max_ch), head[max_ch] = head[v];\n      }\n    }\n  }\n};\n#line 4 \"\
    graph/ds/lazy_tree_monoid.hpp\"\n\r\ntemplate <typename TREE, typename ActedMonoid,\
    \ bool edge>\r\nstruct Lazy_Tree_Monoid {\r\n  using MX = typename ActedMonoid::Monoid_X;\r\
    \n  using MA = typename ActedMonoid::Monoid_A;\r\n  using X = typename MX::value_type;\r\
    \n  using A = typename MA::value_type;\r\n  struct RevAM {\r\n    using Monoid_X\
    \ = Monoid_Reverse<MX>;\r\n    using Monoid_A = MA;\r\n    using X = typename\
    \ Monoid_X::value_type;\r\n    using A = typename Monoid_A::value_type;\r\n  \
    \  static X act(const X &x, const A &a, const ll &size) {\r\n      return ActedMonoid::act(x,\
    \ a, size);\r\n    }\r\n  };\r\n\r\n  TREE &tree;\r\n  int N;\r\n  Lazy_SegTree<ActedMonoid>\
    \ seg;\r\n  Lazy_SegTree<RevAM> seg_r;\r\n\r\n  Lazy_Tree_Monoid(TREE &tree) :\
    \ tree(tree), N(tree.N) {\r\n    build([](int i) -> X { return MX::id(); });\r\
    \n  }\r\n\r\n  Lazy_Tree_Monoid(TREE &tree, vc<X> &dat) : tree(tree), N(tree.N)\
    \ {\r\n    build([&](int i) -> X { return dat[i]; });\r\n  }\r\n\r\n  template\
    \ <typename F>\r\n  Lazy_Tree_Monoid(TREE &tree, F f) : tree(tree), N(tree.N)\
    \ {\r\n    build(f);\r\n  }\r\n\r\n  template <typename F>\r\n  void build(F f)\
    \ {\r\n    if (!edge) {\r\n      auto f_v = [&](int i) -> X { return f(tree.V[i]);\
    \ };\r\n      seg.build(N, f_v);\r\n      if constexpr (!MX::commute) {\r\n  \
    \      seg_r.build(N, f_v);\r\n      }\r\n    } else {\r\n      auto f_e = [&](int\
    \ i) -> X {\r\n        return (i == 0 ? MX::id() : f(tree.v_to_e(tree.V[i])));\r\
    \n      };\r\n      seg.build(N, f_e);\r\n      if constexpr (!MX::commute) {\r\
    \n        seg_r.build(N, f_e);\r\n      }\r\n    }\r\n  }\r\n\r\n  void set(int\
    \ i, X x) {\r\n    if constexpr (edge) i = tree.e_to_v(i);\r\n    i = tree.LID[i];\r\
    \n    seg.set(i, x);\r\n    if constexpr (!MX::commute) {\r\n      seg_r.set(i,\
    \ x);\r\n    }\r\n  }\r\n\r\n  X get(int v) { return seg.get(tree.LID[v]); }\r\
    \n  vc<X> get_all() {\r\n    vc<X> dat = seg.get_all();\r\n    if (!edge) {\r\n\
    \      vc<X> res(N);\r\n      FOR(v, N) res[v] = dat[tree.LID[v]];\r\n      return\
    \ res;\r\n    } else {\r\n      vc<X> res(N - 1);\r\n      FOR(i, N - 1) { res[i]\
    \ = dat[tree.LID[tree.e_to_v(i)]]; }\r\n      return res;\r\n    }\r\n  }\r\n\r\
    \n  X prod_path(int u, int v) {\r\n    auto pd = tree.get_path_decomposition(u,\
    \ v, edge);\r\n    X val = MX::id();\r\n    for (auto &&[a, b] : pd) {\r\n   \
    \   val = MX::op(val, get_prod(a, b));\r\n    }\r\n    return val;\r\n  }\r\n\r\
    \n  X prod_subtree(int u, int root = -1) {\r\n    if (root == u) return prod_all();\r\
    \n    if (root == -1 || tree.in_subtree(u, root)) {\r\n      int l = tree.LID[u],\
    \ r = tree.RID[u];\r\n      return seg.prod(l + edge, r);\r\n    }\r\n    assert(!edge);\
    \  // \u3055\u307C\u308A\r\n    u = tree.jump(u, root, 1);\r\n    int L = tree.LID[u],\
    \ R = tree.RID[u];\r\n    return MX::op(seg.prod(0, L), seg.prod(R, N));\r\n \
    \ }\r\n\r\n  X prod_all() {\r\n    static_assert(MX::commute);\r\n    return seg.prod_all();\r\
    \n  }\r\n\r\n  void apply_path(int u, int v, A a) {\r\n    auto pd = tree.get_path_decomposition(u,\
    \ v, edge);\r\n    for (auto &&[x, y] : pd) {\r\n      int l = min(x, y), r =\
    \ max(x, y);\r\n      seg.apply(l, r + 1, a);\r\n      if constexpr (!MX::commute)\
    \ {\r\n        seg_r.apply(l, r + 1, a);\r\n      }\r\n    }\r\n  }\r\n\r\n  void\
    \ apply_subtree(int u, A a) {\r\n    int l = tree.LID[u], r = tree.RID[u];\r\n\
    \    seg.apply(l + edge, r, a);\r\n    if constexpr (!MX::commute) {\r\n     \
    \ seg_r.apply(l + edge, r, a);\r\n    }\r\n  }\r\n\r\n  void apply_outtree(int\
    \ u, A a) {\r\n    int l = tree.LID[u], r = tree.RID[u];\r\n    seg.apply(0 +\
    \ edge, l + edge, a);\r\n    seg.apply(r, N, a);\r\n    if constexpr (!MX::commute)\
    \ {\r\n      seg_r.apply(0 + edge, l + edge, a);\r\n      seg_r.apply(r, N, a);\r\
    \n    }\r\n  }\r\n\r\n  template <class F>\r\n  int max_path(F check, int u, int\
    \ v) {\r\n    if constexpr (edge) return max_path_edge(check, u, v);\r\n    if\
    \ (!check(prod_path(u, u))) return -1;\r\n    auto pd = tree.get_path_decomposition(u,\
    \ v, edge);\r\n    X val = MX::id();\r\n    for (auto &&[a, b] : pd) {\r\n   \
    \   X x = get_prod(a, b);\r\n      if (check(MX::op(val, x))) {\r\n        val\
    \ = MX::op(val, x);\r\n        u = (tree.V[b]);\r\n        continue;\r\n     \
    \ }\r\n      auto check_tmp = [&](X x) -> bool { return check(MX::op(val, x));\
    \ };\r\n      if (a <= b) {\r\n        // \u4E0B\u308A\r\n        auto i = seg.max_right(check_tmp,\
    \ a);\r\n        return (i == a ? u : tree.V[i - 1]);\r\n      } else {\r\n  \
    \      // \u4E0A\u308A\r\n        int i = 0;\r\n        if constexpr (MX::commute)\
    \ i = seg.min_left(check_tmp, a + 1);\r\n        if constexpr (!MX::commute) i\
    \ = seg_r.min_left(check_tmp, a + 1);\r\n        if (i == a + 1) return u;\r\n\
    \        return tree.V[i];\r\n      }\r\n    }\r\n    return v;\r\n  }\r\n\r\n\
    \  // closed range [a,b] \u3092 heavy path \u306E\u5F62\u5F0F\u306B\u5FDC\u3058\
    \u3066\r\n  inline X get_prod(int a, int b) {\r\n    if constexpr (MX::commute)\r\
    \n      return (a <= b ? seg.prod(a, b + 1) : seg.prod(b, a + 1));\r\n    return\
    \ (a <= b ? seg.prod(a, b + 1) : seg_r.prod(b, a + 1));\r\n  }\r\n\r\n private:\r\
    \n  template <class F>\r\n  int max_path_edge(F check, int u, int v) {\r\n   \
    \ static_assert(edge);\r\n    if (!check(MX::id())) return -1;\r\n    int lca\
    \ = tree.LCA(u, v);\r\n    auto pd = tree.get_path_decomposition(u, lca, edge);\r\
    \n    X val = MX::id();\r\n\r\n    // climb\r\n    for (auto &&[a, b] : pd) {\r\
    \n      assert(a >= b);\r\n      X x = get_prod(a, b);\r\n      if (check(MX::op(val,\
    \ x))) {\r\n        val = MX::op(val, x);\r\n        u = (tree.parent[tree.V[b]]);\r\
    \n        continue;\r\n      }\r\n      auto check_tmp = [&](X x) -> bool { return\
    \ check(MX::op(val, x)); };\r\n      int i = 0;\r\n      if constexpr (MX::commute)\
    \ i = seg.min_left(check_tmp, a + 1);\r\n      if constexpr (!MX::commute) i =\
    \ seg_r.min_left(check_tmp, a + 1);\r\n      if (i == a + 1) return u;\r\n   \
    \   return tree.parent[tree.V[i]];\r\n    }\r\n    // down\r\n    pd = tree.get_path_decomposition(lca,\
    \ v, edge);\r\n    for (auto &&[a, b] : pd) {\r\n      assert(a <= b);\r\n   \
    \   X x = get_prod(a, b);\r\n      if (check(MX::op(val, x))) {\r\n        val\
    \ = MX::op(val, x);\r\n        u = (tree.V[b]);\r\n        continue;\r\n     \
    \ }\r\n      auto check_tmp = [&](X x) -> bool { return check(MX::op(val, x));\
    \ };\r\n      auto i = seg.max_right(check_tmp, a);\r\n      return (i == a ?\
    \ u : tree.V[i - 1]);\r\n    }\r\n    return v;\r\n  }\r\n};\r\n"
  code: "#include \"alg/monoid/monoid_reverse.hpp\"\r\n#include \"ds/segtree/lazy_segtree.hpp\"\
    \r\n#include \"graph/tree.hpp\"\r\n\r\ntemplate <typename TREE, typename ActedMonoid,\
    \ bool edge>\r\nstruct Lazy_Tree_Monoid {\r\n  using MX = typename ActedMonoid::Monoid_X;\r\
    \n  using MA = typename ActedMonoid::Monoid_A;\r\n  using X = typename MX::value_type;\r\
    \n  using A = typename MA::value_type;\r\n  struct RevAM {\r\n    using Monoid_X\
    \ = Monoid_Reverse<MX>;\r\n    using Monoid_A = MA;\r\n    using X = typename\
    \ Monoid_X::value_type;\r\n    using A = typename Monoid_A::value_type;\r\n  \
    \  static X act(const X &x, const A &a, const ll &size) {\r\n      return ActedMonoid::act(x,\
    \ a, size);\r\n    }\r\n  };\r\n\r\n  TREE &tree;\r\n  int N;\r\n  Lazy_SegTree<ActedMonoid>\
    \ seg;\r\n  Lazy_SegTree<RevAM> seg_r;\r\n\r\n  Lazy_Tree_Monoid(TREE &tree) :\
    \ tree(tree), N(tree.N) {\r\n    build([](int i) -> X { return MX::id(); });\r\
    \n  }\r\n\r\n  Lazy_Tree_Monoid(TREE &tree, vc<X> &dat) : tree(tree), N(tree.N)\
    \ {\r\n    build([&](int i) -> X { return dat[i]; });\r\n  }\r\n\r\n  template\
    \ <typename F>\r\n  Lazy_Tree_Monoid(TREE &tree, F f) : tree(tree), N(tree.N)\
    \ {\r\n    build(f);\r\n  }\r\n\r\n  template <typename F>\r\n  void build(F f)\
    \ {\r\n    if (!edge) {\r\n      auto f_v = [&](int i) -> X { return f(tree.V[i]);\
    \ };\r\n      seg.build(N, f_v);\r\n      if constexpr (!MX::commute) {\r\n  \
    \      seg_r.build(N, f_v);\r\n      }\r\n    } else {\r\n      auto f_e = [&](int\
    \ i) -> X {\r\n        return (i == 0 ? MX::id() : f(tree.v_to_e(tree.V[i])));\r\
    \n      };\r\n      seg.build(N, f_e);\r\n      if constexpr (!MX::commute) {\r\
    \n        seg_r.build(N, f_e);\r\n      }\r\n    }\r\n  }\r\n\r\n  void set(int\
    \ i, X x) {\r\n    if constexpr (edge) i = tree.e_to_v(i);\r\n    i = tree.LID[i];\r\
    \n    seg.set(i, x);\r\n    if constexpr (!MX::commute) {\r\n      seg_r.set(i,\
    \ x);\r\n    }\r\n  }\r\n\r\n  X get(int v) { return seg.get(tree.LID[v]); }\r\
    \n  vc<X> get_all() {\r\n    vc<X> dat = seg.get_all();\r\n    if (!edge) {\r\n\
    \      vc<X> res(N);\r\n      FOR(v, N) res[v] = dat[tree.LID[v]];\r\n      return\
    \ res;\r\n    } else {\r\n      vc<X> res(N - 1);\r\n      FOR(i, N - 1) { res[i]\
    \ = dat[tree.LID[tree.e_to_v(i)]]; }\r\n      return res;\r\n    }\r\n  }\r\n\r\
    \n  X prod_path(int u, int v) {\r\n    auto pd = tree.get_path_decomposition(u,\
    \ v, edge);\r\n    X val = MX::id();\r\n    for (auto &&[a, b] : pd) {\r\n   \
    \   val = MX::op(val, get_prod(a, b));\r\n    }\r\n    return val;\r\n  }\r\n\r\
    \n  X prod_subtree(int u, int root = -1) {\r\n    if (root == u) return prod_all();\r\
    \n    if (root == -1 || tree.in_subtree(u, root)) {\r\n      int l = tree.LID[u],\
    \ r = tree.RID[u];\r\n      return seg.prod(l + edge, r);\r\n    }\r\n    assert(!edge);\
    \  // \u3055\u307C\u308A\r\n    u = tree.jump(u, root, 1);\r\n    int L = tree.LID[u],\
    \ R = tree.RID[u];\r\n    return MX::op(seg.prod(0, L), seg.prod(R, N));\r\n \
    \ }\r\n\r\n  X prod_all() {\r\n    static_assert(MX::commute);\r\n    return seg.prod_all();\r\
    \n  }\r\n\r\n  void apply_path(int u, int v, A a) {\r\n    auto pd = tree.get_path_decomposition(u,\
    \ v, edge);\r\n    for (auto &&[x, y] : pd) {\r\n      int l = min(x, y), r =\
    \ max(x, y);\r\n      seg.apply(l, r + 1, a);\r\n      if constexpr (!MX::commute)\
    \ {\r\n        seg_r.apply(l, r + 1, a);\r\n      }\r\n    }\r\n  }\r\n\r\n  void\
    \ apply_subtree(int u, A a) {\r\n    int l = tree.LID[u], r = tree.RID[u];\r\n\
    \    seg.apply(l + edge, r, a);\r\n    if constexpr (!MX::commute) {\r\n     \
    \ seg_r.apply(l + edge, r, a);\r\n    }\r\n  }\r\n\r\n  void apply_outtree(int\
    \ u, A a) {\r\n    int l = tree.LID[u], r = tree.RID[u];\r\n    seg.apply(0 +\
    \ edge, l + edge, a);\r\n    seg.apply(r, N, a);\r\n    if constexpr (!MX::commute)\
    \ {\r\n      seg_r.apply(0 + edge, l + edge, a);\r\n      seg_r.apply(r, N, a);\r\
    \n    }\r\n  }\r\n\r\n  template <class F>\r\n  int max_path(F check, int u, int\
    \ v) {\r\n    if constexpr (edge) return max_path_edge(check, u, v);\r\n    if\
    \ (!check(prod_path(u, u))) return -1;\r\n    auto pd = tree.get_path_decomposition(u,\
    \ v, edge);\r\n    X val = MX::id();\r\n    for (auto &&[a, b] : pd) {\r\n   \
    \   X x = get_prod(a, b);\r\n      if (check(MX::op(val, x))) {\r\n        val\
    \ = MX::op(val, x);\r\n        u = (tree.V[b]);\r\n        continue;\r\n     \
    \ }\r\n      auto check_tmp = [&](X x) -> bool { return check(MX::op(val, x));\
    \ };\r\n      if (a <= b) {\r\n        // \u4E0B\u308A\r\n        auto i = seg.max_right(check_tmp,\
    \ a);\r\n        return (i == a ? u : tree.V[i - 1]);\r\n      } else {\r\n  \
    \      // \u4E0A\u308A\r\n        int i = 0;\r\n        if constexpr (MX::commute)\
    \ i = seg.min_left(check_tmp, a + 1);\r\n        if constexpr (!MX::commute) i\
    \ = seg_r.min_left(check_tmp, a + 1);\r\n        if (i == a + 1) return u;\r\n\
    \        return tree.V[i];\r\n      }\r\n    }\r\n    return v;\r\n  }\r\n\r\n\
    \  // closed range [a,b] \u3092 heavy path \u306E\u5F62\u5F0F\u306B\u5FDC\u3058\
    \u3066\r\n  inline X get_prod(int a, int b) {\r\n    if constexpr (MX::commute)\r\
    \n      return (a <= b ? seg.prod(a, b + 1) : seg.prod(b, a + 1));\r\n    return\
    \ (a <= b ? seg.prod(a, b + 1) : seg_r.prod(b, a + 1));\r\n  }\r\n\r\n private:\r\
    \n  template <class F>\r\n  int max_path_edge(F check, int u, int v) {\r\n   \
    \ static_assert(edge);\r\n    if (!check(MX::id())) return -1;\r\n    int lca\
    \ = tree.LCA(u, v);\r\n    auto pd = tree.get_path_decomposition(u, lca, edge);\r\
    \n    X val = MX::id();\r\n\r\n    // climb\r\n    for (auto &&[a, b] : pd) {\r\
    \n      assert(a >= b);\r\n      X x = get_prod(a, b);\r\n      if (check(MX::op(val,\
    \ x))) {\r\n        val = MX::op(val, x);\r\n        u = (tree.parent[tree.V[b]]);\r\
    \n        continue;\r\n      }\r\n      auto check_tmp = [&](X x) -> bool { return\
    \ check(MX::op(val, x)); };\r\n      int i = 0;\r\n      if constexpr (MX::commute)\
    \ i = seg.min_left(check_tmp, a + 1);\r\n      if constexpr (!MX::commute) i =\
    \ seg_r.min_left(check_tmp, a + 1);\r\n      if (i == a + 1) return u;\r\n   \
    \   return tree.parent[tree.V[i]];\r\n    }\r\n    // down\r\n    pd = tree.get_path_decomposition(lca,\
    \ v, edge);\r\n    for (auto &&[a, b] : pd) {\r\n      assert(a <= b);\r\n   \
    \   X x = get_prod(a, b);\r\n      if (check(MX::op(val, x))) {\r\n        val\
    \ = MX::op(val, x);\r\n        u = (tree.V[b]);\r\n        continue;\r\n     \
    \ }\r\n      auto check_tmp = [&](X x) -> bool { return check(MX::op(val, x));\
    \ };\r\n      auto i = seg.max_right(check_tmp, a);\r\n      return (i == a ?\
    \ u : tree.V[i - 1]);\r\n    }\r\n    return v;\r\n  }\r\n};\r\n"
  dependsOn:
  - alg/monoid/monoid_reverse.hpp
  - ds/segtree/lazy_segtree.hpp
  - other/bit.hpp
  - graph/tree.hpp
  - graph/base.hpp
  - ds/hashmap.hpp
  isVerificationFile: false
  path: graph/ds/lazy_tree_monoid.hpp
  requiredBy: []
  timestamp: '2026-09-01 10:19:35+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/3_yukicoder/1790.test.cpp
  - test/3_yukicoder/1197.test.cpp
  - test/3_yukicoder/235.test.cpp
  - test/4_aoj/GRL_5_E.test.cpp
documentation_of: graph/ds/lazy_tree_monoid.hpp
layout: document
redirect_from:
- /library/graph/ds/lazy_tree_monoid.hpp
- /library/graph/ds/lazy_tree_monoid.hpp.html
title: graph/ds/lazy_tree_monoid.hpp
---
