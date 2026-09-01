---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: alg/acted_monoid/minmincnt_add.hpp
    title: alg/acted_monoid/minmincnt_add.hpp
  - icon: ':heavy_check_mark:'
    path: alg/monoid/add.hpp
    title: alg/monoid/add.hpp
  - icon: ':heavy_check_mark:'
    path: alg/monoid/minmincnt.hpp
    title: alg/monoid/minmincnt.hpp
  - icon: ':question:'
    path: ds/hashmap.hpp
    title: ds/hashmap.hpp
  - icon: ':heavy_check_mark:'
    path: ds/segtree/lazy_segtree.hpp
    title: ds/segtree/lazy_segtree.hpp
  - icon: ':question:'
    path: graph/base.hpp
    title: graph/base.hpp
  - icon: ':question:'
    path: other/bit.hpp
    title: other/bit.hpp
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':warning:'
  attributes:
    links:
    - https://qoj.ac/contest/1277/problem/6674
  bundledCode: "#line 1 \"graph/count/count_connected_intervals.hpp\"\n\n#line 1 \"\
    alg/monoid/minmincnt.hpp\"\n\n// \u6700\u5C0F\u5024\u3001\u6700\u5C0F\u5024\u306E\
    \u500B\u6570\ntemplate <typename E>\nstruct Monoid_MinMincnt {\n  using value_type\
    \ = pair<E, E>;\n  using X = value_type;\n  static X op(X x, X y) {\n    auto\
    \ [xmin, xmincnt] = x;\n    auto [ymin, ymincnt] = y;\n    if (xmin > ymin) return\
    \ y;\n    if (xmin < ymin) return x;\n    return {xmin, xmincnt + ymincnt};\n\
    \  }\n  static constexpr X id() { return {infty<E>, 0}; }\n  static constexpr\
    \ bool commute = true;\n};\n#line 1 \"alg/monoid/add.hpp\"\n\ntemplate <typename\
    \ E>\nstruct Monoid_Add {\n  using X = E;\n  using value_type = X;\n  static constexpr\
    \ X op(const X &x, const X &y) noexcept { return x + y; }\n  static constexpr\
    \ X inverse(const X &x) noexcept { return -x; }\n  static constexpr X power(const\
    \ X &x, ll n) noexcept { return X(n) * x; }\n  static constexpr X id() { return\
    \ X(0); }\n  static constexpr bool commute = true;\n};\n#line 3 \"alg/acted_monoid/minmincnt_add.hpp\"\
    \n\r\ntemplate <typename E>\r\nstruct ActedMonoid_MinMincnt_Add {\r\n  using Monoid_X\
    \ = Monoid_MinMincnt<E>;\r\n  using Monoid_A = Monoid_Add<E>;\r\n  using X = typename\
    \ Monoid_X::value_type;\r\n  using A = typename Monoid_A::value_type;\r\n  static\
    \ constexpr X act(const X &x, const A &a, const ll &size) {\r\n    auto [xmin,\
    \ xmincnt] = x;\r\n    if (xmin == infty<E>) return x;\r\n    return {xmin + a,\
    \ xmincnt};\r\n  }\r\n};\r\n#line 1 \"other/bit.hpp\"\n\nint popcnt(int x) { return\
    \ __builtin_popcount(x); }\nint popcnt(u32 x) { return __builtin_popcount(x);\
    \ }\nint popcnt(ll x) { return __builtin_popcountll(x); }\nint popcnt(u64 x) {\
    \ return __builtin_popcountll(x); }\nint popcnt_sgn(int x) { return (__builtin_parity(unsigned(x))\
    \ & 1 ? -1 : 1); }\nint popcnt_sgn(u32 x) { return (__builtin_parity(x) & 1 ?\
    \ -1 : 1); }\nint popcnt_sgn(ll x) { return (__builtin_parityll(x) & 1 ? -1 :\
    \ 1); }\nint popcnt_sgn(u64 x) { return (__builtin_parityll(x) & 1 ? -1 : 1);\
    \ }\n// (0, 1, 2, 3, 4) -> (-1, 0, 1, 1, 2)\nint topbit(int x) { return (x ==\
    \ 0 ? -1 : 31 - __builtin_clz(x)); }\nint topbit(u32 x) { return (x == 0 ? -1\
    \ : 31 - __builtin_clz(x)); }\nint topbit(ll x) { return (x == 0 ? -1 : 63 - __builtin_clzll(x));\
    \ }\nint topbit(u64 x) { return (x == 0 ? -1 : 63 - __builtin_clzll(x)); }\n//\
    \ (0, 1, 2, 3, 4) -> (-1, 0, 1, 0, 2)\nint lowbit(int x) { return (x == 0 ? -1\
    \ : __builtin_ctz(x)); }\nint lowbit(u32 x) { return (x == 0 ? -1 : __builtin_ctz(x));\
    \ }\nint lowbit(ll x) { return (x == 0 ? -1 : __builtin_ctzll(x)); }\nint lowbit(u64\
    \ x) { return (x == 0 ? -1 : __builtin_ctzll(x)); }\n\ntemplate <typename T>\n\
    T kth_bit(int k) {\n  assert(0 <= k && k < int(8 * sizeof(T)));\n  return T(1)\
    \ << k;\n}\ntemplate <typename T>\nbool has_kth_bit(T x, int k) {\n  assert(0\
    \ <= k && k < int(8 * sizeof(T)));\n  return x >> k & 1;\n}\n\ntemplate <typename\
    \ UINT>\nstruct all_bit {\n  static_assert(is_unsigned<UINT>::value);\n  UINT\
    \ s;\n  all_bit(UINT s) : s(s) {}\n  struct iter {\n    UINT s;\n    int operator*()\
    \ const { return lowbit(s); }\n    void operator++() { s &= s - 1; }\n    bool\
    \ operator!=(nullptr_t) const { return s; }\n  };\n  iter begin() const { return\
    \ {s}; }\n  nullptr_t end() const { return nullptr; }\n};\n\ntemplate <typename\
    \ UINT>\nstruct all_subset {\n  static_assert(is_unsigned<UINT>::value);\n  UINT\
    \ s;\n  all_subset(UINT s) : s(s) {}\n  struct iter {\n    UINT s, t;\n    bool\
    \ done = false;\n    UINT operator*() const { return t; }\n    void operator++()\
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
    \ 1 \"ds/hashmap.hpp\"\n\n// u64 -> Val\ntemplate <typename Val>\nstruct HashMap\
    \ {\n  // n \u306F\u5165\u308C\u305F\u3044\u3082\u306E\u306E\u500B\u6570\u3067\
    \ ok\n  HashMap(u32 n = 0) { build(n); }\n  void build(u32 n) {\n    u32 k = 8;\n\
    \    while (k < n * 2) k *= 2;\n    cap = k / 2, mask = k - 1;\n    key.resize(k),\
    \ val.resize(k), used.assign(k, 0);\n  }\n\n  // size \u3092\u4FDD\u3063\u305F\
    \u307E\u307E. size=0 \u306B\u3059\u308B\u3068\u304D\u306F build \u3059\u308B\u3053\
    \u3068.\n  void clear() {\n    used.assign(len(used), 0);\n    cap = (mask + 1)\
    \ / 2;\n  }\n  int size() { return len(used) / 2 - cap; }\n\n  int index(const\
    \ u64& k) {\n    int i = 0;\n    for (i = hash(k); used[i] && key[i] != k; i =\
    \ (i + 1) & mask) {\n    }\n    return i;\n  }\n\n  Val& operator[](const u64&\
    \ k) {\n    int i = index(k);\n    if (used[i]) return val[i];\n    if (cap ==\
    \ 0) extend(), i = index(k);\n    used[i] = 1, key[i] = k, val[i] = Val{}, --cap;\n\
    \    return val[i];\n  }\n\n  Val get(const u64& k, Val default_value) {\n   \
    \ int i = index(k);\n    return (used[i] ? val[i] : default_value);\n  }\n\n \
    \ bool count(const u64& k) {\n    int i = index(k);\n    return used[i] && key[i]\
    \ == k;\n  }\n\n  // f(key, val)\n  template <typename F>\n  void enumerate_all(F\
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
    \ {\n      vc_indeg[e.to]++, vc_outdeg[e.frm]++;\n    }\n  }\n};\n#line 5 \"graph/count/count_connected_intervals.hpp\"\
    \n\n// G: tree\n// count(l,r) s.t. (v_i|l<=i<=r) is connected\n// https://qoj.ac/contest/1277/problem/6674\n\
    template <typename GT>\nll count_connected_intervals(GT& G) {\n  assert(!GT::is_directed);\n\
    \  int N = G.N;\n  using AM = ActedMonoid_MinMincnt_Add<int>;\n  Lazy_SegTree<AM>\
    \ seg(N, [&](int i) -> pair<int, int> { return {0, 1}; });\n\n  ll ANS = 0;\n\
    \  FOR(r, N) {\n    // |V|\n    seg.apply(0, r + 1, 1);\n    // |E|\n    for (auto&\
    \ e: G[r]) {\n      if (e.to < r) { seg.apply(0, e.to + 1, -1); }\n    }\n   \
    \ auto [mi, mi_cnt] = seg.prod(0, r + 1);\n    assert(mi >= 1);\n    if (mi ==\
    \ 1) ANS += mi_cnt;\n  }\n  return ANS;\n}\n"
  code: "\n#include \"alg/acted_monoid/minmincnt_add.hpp\"\n#include \"ds/segtree/lazy_segtree.hpp\"\
    \n#include \"graph/base.hpp\"\n\n// G: tree\n// count(l,r) s.t. (v_i|l<=i<=r)\
    \ is connected\n// https://qoj.ac/contest/1277/problem/6674\ntemplate <typename\
    \ GT>\nll count_connected_intervals(GT& G) {\n  assert(!GT::is_directed);\n  int\
    \ N = G.N;\n  using AM = ActedMonoid_MinMincnt_Add<int>;\n  Lazy_SegTree<AM> seg(N,\
    \ [&](int i) -> pair<int, int> { return {0, 1}; });\n\n  ll ANS = 0;\n  FOR(r,\
    \ N) {\n    // |V|\n    seg.apply(0, r + 1, 1);\n    // |E|\n    for (auto& e:\
    \ G[r]) {\n      if (e.to < r) { seg.apply(0, e.to + 1, -1); }\n    }\n    auto\
    \ [mi, mi_cnt] = seg.prod(0, r + 1);\n    assert(mi >= 1);\n    if (mi == 1) ANS\
    \ += mi_cnt;\n  }\n  return ANS;\n}"
  dependsOn:
  - alg/acted_monoid/minmincnt_add.hpp
  - alg/monoid/minmincnt.hpp
  - alg/monoid/add.hpp
  - ds/segtree/lazy_segtree.hpp
  - other/bit.hpp
  - graph/base.hpp
  - ds/hashmap.hpp
  isVerificationFile: false
  path: graph/count/count_connected_intervals.hpp
  requiredBy: []
  timestamp: '2026-09-01 10:19:35+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: graph/count/count_connected_intervals.hpp
layout: document
redirect_from:
- /library/graph/count/count_connected_intervals.hpp
- /library/graph/count/count_connected_intervals.hpp.html
title: graph/count/count_connected_intervals.hpp
---
