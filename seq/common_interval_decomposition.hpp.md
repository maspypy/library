---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: alg/acted_monoid/min_add.hpp
    title: alg/acted_monoid/min_add.hpp
  - icon: ':question:'
    path: alg/monoid/add.hpp
    title: alg/monoid/add.hpp
  - icon: ':question:'
    path: alg/monoid/min.hpp
    title: alg/monoid/min.hpp
  - icon: ':question:'
    path: ds/segtree/lazy_segtree.hpp
    title: ds/segtree/lazy_segtree.hpp
  - icon: ':question:'
    path: other/bit.hpp
    title: other/bit.hpp
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/2_library_checker/graph/common_interval_decomposition.test.cpp
    title: test/2_library_checker/graph/common_interval_decomposition.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/3_yukicoder/1720.test.cpp
    title: test/3_yukicoder/1720.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 1 \"other/bit.hpp\"\n\nint popcnt(int x) { return __builtin_popcount(x);\
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
    \  x = (x << 32) | (x >> 32);\n  return x;\n}\n#line 2 \"ds/segtree/lazy_segtree.hpp\"\
    \n\ntemplate <typename ActedMonoid>\nstruct Lazy_SegTree {\n  using AM = ActedMonoid;\n\
    \  using MX = typename AM::Monoid_X;\n  using MA = typename AM::Monoid_A;\n  using\
    \ X = typename MX::value_type;\n  using A = typename MA::value_type;\n  int n,\
    \ log, size;\n  vc<X> dat;\n  vc<A> laz;\n  vc<bool> has_laz;\n\n  Lazy_SegTree()\
    \ {}\n  Lazy_SegTree(int n) { build(n); }\n  template <typename F>\n  Lazy_SegTree(int\
    \ n, F f) {\n    build(n, f);\n  }\n  Lazy_SegTree(const vc<X>& v) { build(v);\
    \ }\n\n  void build(int m) {\n    build(m, [](int i) -> X { return MX::unit();\
    \ });\n  }\n  void build(const vc<X>& v) {\n    build(len(v), [&](int i) -> X\
    \ { return v[i]; });\n  }\n  template <typename F>\n  void build(int m, F f) {\n\
    \    n = m, log = 1;\n    while ((1 << log) < n) ++log;\n    size = 1 << log;\n\
    \    dat.assign(size << 1, MX::unit());\n    laz.assign(size, MA::unit());\n \
    \   has_laz.assign(size, false);\n    FOR(i, n) dat[size + i] = f(i);\n    FOR_R(i,\
    \ 1, size) update(i);\n  }\n\n  void update(int k) { dat[k] = MX::op(dat[2 * k],\
    \ dat[2 * k + 1]); }\n  void set(int p, X x) {\n    assert(0 <= p && p < n);\n\
    \    p += size;\n    for (int i = log; i >= 1; i--) push(p >> i);\n    dat[p]\
    \ = x;\n    for (int i = 1; i <= log; i++) update(p >> i);\n  }\n  void multiply(int\
    \ p, const X& x) {\n    assert(0 <= p && p < n);\n    p += size;\n    for (int\
    \ i = log; i >= 1; i--) push(p >> i);\n    dat[p] = MX::op(dat[p], x);\n    for\
    \ (int i = 1; i <= log; i++) update(p >> i);\n  }\n\n  X get(int p) {\n    assert(0\
    \ <= p && p < n);\n    p += size;\n    for (int i = log; i >= 1; i--) push(p >>\
    \ i);\n    return dat[p];\n  }\n\n  vc<X> get_all() {\n    FOR(k, 1, size) { push(k);\
    \ }\n    return {dat.begin() + size, dat.begin() + size + n};\n  }\n\n  X prod(int\
    \ l, int r) {\n    assert(0 <= l && l <= r && r <= n);\n    if (l == r) return\
    \ MX::unit();\n    l += size, r += size;\n    for (int i = log; i >= 1; i--) {\n\
    \      if (((l >> i) << i) != l) push(l >> i);\n      if (((r >> i) << i) != r)\
    \ push((r - 1) >> i);\n    }\n    X xl = MX::unit(), xr = MX::unit();\n    while\
    \ (l < r) {\n      if (l & 1) xl = MX::op(xl, dat[l++]);\n      if (r & 1) xr\
    \ = MX::op(dat[--r], xr);\n      l >>= 1, r >>= 1;\n    }\n    return MX::op(xl,\
    \ xr);\n  }\n\n  X prod_all() { return dat[1]; }\n\n  void apply(int l, int r,\
    \ A a) {\n    assert(0 <= l && l <= r && r <= n);\n    if (l == r) return;\n \
    \   l += size, r += size;\n    for (int i = log; i >= 1; i--) {\n      if (((l\
    \ >> i) << i) != l) push(l >> i);\n      if (((r >> i) << i) != r) push((r - 1)\
    \ >> i);\n    }\n    int l2 = l, r2 = r;\n    while (l < r) {\n      if (l & 1)\
    \ apply_at(l++, a);\n      if (r & 1) apply_at(--r, a);\n      l >>= 1, r >>=\
    \ 1;\n    }\n    l = l2, r = r2;\n    for (int i = 1; i <= log; i++) {\n     \
    \ if (((l >> i) << i) != l) update(l >> i);\n      if (((r >> i) << i) != r) update((r\
    \ - 1) >> i);\n    }\n  }\n\n  template <typename F>\n  int max_right(const F\
    \ check, int l) {\n    assert(0 <= l && l <= n);\n    assert(check(MX::unit()));\n\
    \    if (l == n) return n;\n    l += size;\n    for (int i = log; i >= 1; i--)\
    \ push(l >> i);\n    X sm = MX::unit();\n    do {\n      while (l % 2 == 0) l\
    \ >>= 1;\n      if (!check(MX::op(sm, dat[l]))) {\n        while (l < size) {\n\
    \          push(l);\n          l = (2 * l);\n          if (check(MX::op(sm, dat[l])))\
    \ {\n            sm = MX::op(sm, dat[l++]);\n          }\n        }\n        return\
    \ l - size;\n      }\n      sm = MX::op(sm, dat[l++]);\n    } while ((l & -l)\
    \ != l);\n    return n;\n  }\n\n  template <typename F>\n  int min_left(const\
    \ F check, int r) {\n    assert(0 <= r && r <= n);\n    assert(check(MX::unit()));\n\
    \    if (r == 0) return 0;\n    r += size;\n    for (int i = log; i >= 1; i--)\
    \ push((r - 1) >> i);\n    X sm = MX::unit();\n    do {\n      r--;\n      while\
    \ (r > 1 && (r % 2)) r >>= 1;\n      if (!check(MX::op(dat[r], sm))) {\n     \
    \   while (r < size) {\n          push(r);\n          r = (2 * r + 1);\n     \
    \     if (check(MX::op(dat[r], sm))) {\n            sm = MX::op(dat[r--], sm);\n\
    \          }\n        }\n        return r + 1 - size;\n      }\n      sm = MX::op(dat[r],\
    \ sm);\n    } while ((r & -r) != r);\n    return 0;\n  }\n\n  // l <= i xor (xor_val)\
    \ < r \u3068\u306A\u308B i \u5168\u4F53\u306B apply\n  void apply_xor_range(int\
    \ l, int r, int xor_val, A a) {\n    assert(!(n & (n - 1)));\n    assert(0 <=\
    \ xor_val && xor_val < n);\n    assert(0 <= l && l <= r && r <= n);\n\n    auto\
    \ dfs = [&](auto& dfs, int idx, int seg_l, int seg_r) -> void {\n      if (l <=\
    \ seg_l && seg_r <= r) {\n        return apply_at(idx, a);\n      }\n      if\
    \ (r <= seg_l || seg_r <= l) return;\n      push(idx);\n      int seg_m = (seg_l\
    \ + seg_r) / 2;\n      int bit = (seg_r - seg_l) / 2;\n      int left = 2 * idx\
    \ + 0, right = 2 * idx + 1;\n      if (xor_val & bit) swap(left, right);\n   \
    \   dfs(dfs, left, seg_l, seg_m);\n      dfs(dfs, right, seg_m, seg_r);\n    \
    \  update(idx);\n    };\n    dfs(dfs, 1, 0, n);\n  }\n\n private:\n  void apply_at(int\
    \ k, A a) {\n    ll sz = 1 << (log - topbit(k));\n    dat[k] = AM::act(dat[k],\
    \ a, sz);\n    if (k < size) has_laz[k] = 1, laz[k] = MA::op(laz[k], a);\n  }\n\
    \  void push(int k) {\n    if (!has_laz[k]) return;\n    has_laz[k] = 0;\n   \
    \ apply_at(2 * k, laz[k]), apply_at(2 * k + 1, laz[k]);\n    laz[k] = MA::unit();\n\
    \  }\n};\n#line 1 \"alg/monoid/add.hpp\"\n\ntemplate <typename E>\nstruct Monoid_Add\
    \ {\n  using X = E;\n  using value_type = X;\n  static constexpr X op(const X\
    \ &x, const X &y) noexcept { return x + y; }\n  static constexpr X inverse(const\
    \ X &x) noexcept { return -x; }\n  static constexpr X power(const X &x, ll n)\
    \ noexcept { return X(n) * x; }\n  static constexpr X unit() { return X(0); }\n\
    \  static constexpr bool commute = true;\n};\n#line 1 \"alg/monoid/min.hpp\"\n\
    \ntemplate <typename E>\nstruct Monoid_Min {\n  using X = E;\n  using value_type\
    \ = X;\n  static constexpr X op(const X &x, const X &y) noexcept { return min(x,\
    \ y); }\n  static constexpr X unit() { return infty<E>; }\n  static constexpr\
    \ bool commute = true;\n};\n#line 3 \"alg/acted_monoid/min_add.hpp\"\n\r\ntemplate\
    \ <typename E>\r\nstruct ActedMonoid_Min_Add {\r\n  using Monoid_X = Monoid_Min<E>;\r\
    \n  using Monoid_A = Monoid_Add<E>;\r\n  using X = typename Monoid_X::value_type;\r\
    \n  using A = typename Monoid_A::value_type;\r\n  static constexpr X act(const\
    \ X &x, const A &a, const ll &size) {\r\n    if (x == infty<E>) return x;\r\n\
    \    return x + a;\r\n  }\r\n};\r\n#line 3 \"seq/common_interval_decomposition.hpp\"\
    \n\nstruct Common_Interval_Decomposition {\n  struct Node {\n    vc<Node*> ch;\n\
    \    bool inc, dec;\n    int l, r, lo, hi;\n    string type() {\n      if (r ==\
    \ l + 1) return \"leaf\";\n      if (inc) return \"inc\";\n      if (dec) return\
    \ \"dec\";\n      return \"prime\";\n    }\n  };\n\n  Node* pool;\n  Node* root;\n\
    \  int pid;\n\n  Common_Interval_Decomposition(vc<int>& P) : pid(0) {\n    pool\
    \ = new Node[2 * len(P)];\n    build(P);\n  }\n\n  Node* new_node(bool inc, bool\
    \ dec, int l, int r, int lo, int hi) {\n    pool[pid].inc = inc;\n    pool[pid].dec\
    \ = dec;\n    pool[pid].l = l;\n    pool[pid].r = r;\n    pool[pid].lo = lo;\n\
    \    pool[pid].hi = hi;\n    return &(pool[pid++]);\n  }\n\n  void build(vc<int>&\
    \ P) {\n    int N = len(P);\n    Lazy_SegTree<ActedMonoid_Min_Add<int>> seg(vc<int>(N,\
    \ 0));\n\n    vc<Node*> st;\n    vc<int> mi = {-1}, ma = {-1};\n    FOR(i, N)\
    \ {\n      while (mi.back() != -1 && P[i] < P[mi.back()]) {\n        int j = POP(mi);\n\
    \        seg.apply(mi.back() + 1, j + 1, P[j] - P[i]);\n      }\n      while (ma.back()\
    \ != -1 && P[i] > P[ma.back()]) {\n        int j = POP(ma);\n        seg.apply(ma.back()\
    \ + 1, j + 1, P[i] - P[j]);\n      }\n      mi.eb(i), ma.eb(i);\n\n      Node*\
    \ now = new_node(0, 0, i, i + 1, P[i], P[i] + 1);\n      while (len(st)) {\n \
    \       Node* n = st.back();\n        if (n->hi == now->lo) {\n          if (n->inc)\
    \ {\n            n->ch.eb(now);\n            n->r = now->r;\n            n->hi\
    \ = now->hi;\n            now = n;\n            st.pop_back();\n          } else\
    \ {\n            Node* p = new_node(1, 0, n->l, now->r, n->lo, now->hi);\n   \
    \         p->ch.eb(n);\n            p->ch.eb(now);\n            now = p;\n   \
    \         st.pop_back();\n          }\n          continue;\n        }\n      \
    \  if (n->lo == now->hi) {\n          if (n->dec) {\n            n->ch.eb(now);\n\
    \            n->r = now->r;\n            n->lo = now->lo;\n            now = n;\n\
    \            st.pop_back();\n          } else {\n            Node* p = new_node(0,\
    \ 1, n->l, now->r, now->lo, n->hi);\n            p->ch.eb(n);\n            p->ch.eb(now);\n\
    \            now = p;\n            st.pop_back();\n          }\n          continue;\n\
    \        }\n        // prime supernode creation\n        if (seg.prod(0, now->l)\
    \ != 0) break;\n        Node* p = new_node(0, 0, now->l, now->r, now->lo, now->hi);\n\
    \        p->ch.eb(now);\n        now = p;\n        while (1) {\n          auto\
    \ c = POP(st);\n          now->l = c->l;\n          chmin(now->lo, c->lo);\n \
    \         chmax(now->hi, c->hi);\n          now->ch.eb(c);\n          if (now->r\
    \ - now->l == now->hi - now->lo) break;\n        }\n        reverse(all(now->ch));\n\
    \      }\n      st.eb(now);\n      seg.apply(0, i + 1, -1);\n    }\n    assert(len(st)\
    \ == 1);\n    root = POP(st);\n    return;\n  }\n\n  void debug() {\n    auto\
    \ dfs = [&](auto& dfs, Node* n) -> void {\n      print(\"l, r, lo, hi\", n->l,\
    \ n->r, n->lo, n->hi);\n      for (auto&& c : n->ch) dfs(dfs, c);\n    };\n  \
    \  dfs(dfs, root);\n  };\n};\n"
  code: "#include \"ds/segtree/lazy_segtree.hpp\"\n#include \"alg/acted_monoid/min_add.hpp\"\
    \n\nstruct Common_Interval_Decomposition {\n  struct Node {\n    vc<Node*> ch;\n\
    \    bool inc, dec;\n    int l, r, lo, hi;\n    string type() {\n      if (r ==\
    \ l + 1) return \"leaf\";\n      if (inc) return \"inc\";\n      if (dec) return\
    \ \"dec\";\n      return \"prime\";\n    }\n  };\n\n  Node* pool;\n  Node* root;\n\
    \  int pid;\n\n  Common_Interval_Decomposition(vc<int>& P) : pid(0) {\n    pool\
    \ = new Node[2 * len(P)];\n    build(P);\n  }\n\n  Node* new_node(bool inc, bool\
    \ dec, int l, int r, int lo, int hi) {\n    pool[pid].inc = inc;\n    pool[pid].dec\
    \ = dec;\n    pool[pid].l = l;\n    pool[pid].r = r;\n    pool[pid].lo = lo;\n\
    \    pool[pid].hi = hi;\n    return &(pool[pid++]);\n  }\n\n  void build(vc<int>&\
    \ P) {\n    int N = len(P);\n    Lazy_SegTree<ActedMonoid_Min_Add<int>> seg(vc<int>(N,\
    \ 0));\n\n    vc<Node*> st;\n    vc<int> mi = {-1}, ma = {-1};\n    FOR(i, N)\
    \ {\n      while (mi.back() != -1 && P[i] < P[mi.back()]) {\n        int j = POP(mi);\n\
    \        seg.apply(mi.back() + 1, j + 1, P[j] - P[i]);\n      }\n      while (ma.back()\
    \ != -1 && P[i] > P[ma.back()]) {\n        int j = POP(ma);\n        seg.apply(ma.back()\
    \ + 1, j + 1, P[i] - P[j]);\n      }\n      mi.eb(i), ma.eb(i);\n\n      Node*\
    \ now = new_node(0, 0, i, i + 1, P[i], P[i] + 1);\n      while (len(st)) {\n \
    \       Node* n = st.back();\n        if (n->hi == now->lo) {\n          if (n->inc)\
    \ {\n            n->ch.eb(now);\n            n->r = now->r;\n            n->hi\
    \ = now->hi;\n            now = n;\n            st.pop_back();\n          } else\
    \ {\n            Node* p = new_node(1, 0, n->l, now->r, n->lo, now->hi);\n   \
    \         p->ch.eb(n);\n            p->ch.eb(now);\n            now = p;\n   \
    \         st.pop_back();\n          }\n          continue;\n        }\n      \
    \  if (n->lo == now->hi) {\n          if (n->dec) {\n            n->ch.eb(now);\n\
    \            n->r = now->r;\n            n->lo = now->lo;\n            now = n;\n\
    \            st.pop_back();\n          } else {\n            Node* p = new_node(0,\
    \ 1, n->l, now->r, now->lo, n->hi);\n            p->ch.eb(n);\n            p->ch.eb(now);\n\
    \            now = p;\n            st.pop_back();\n          }\n          continue;\n\
    \        }\n        // prime supernode creation\n        if (seg.prod(0, now->l)\
    \ != 0) break;\n        Node* p = new_node(0, 0, now->l, now->r, now->lo, now->hi);\n\
    \        p->ch.eb(now);\n        now = p;\n        while (1) {\n          auto\
    \ c = POP(st);\n          now->l = c->l;\n          chmin(now->lo, c->lo);\n \
    \         chmax(now->hi, c->hi);\n          now->ch.eb(c);\n          if (now->r\
    \ - now->l == now->hi - now->lo) break;\n        }\n        reverse(all(now->ch));\n\
    \      }\n      st.eb(now);\n      seg.apply(0, i + 1, -1);\n    }\n    assert(len(st)\
    \ == 1);\n    root = POP(st);\n    return;\n  }\n\n  void debug() {\n    auto\
    \ dfs = [&](auto& dfs, Node* n) -> void {\n      print(\"l, r, lo, hi\", n->l,\
    \ n->r, n->lo, n->hi);\n      for (auto&& c : n->ch) dfs(dfs, c);\n    };\n  \
    \  dfs(dfs, root);\n  };\n};\n"
  dependsOn:
  - ds/segtree/lazy_segtree.hpp
  - other/bit.hpp
  - alg/acted_monoid/min_add.hpp
  - alg/monoid/add.hpp
  - alg/monoid/min.hpp
  isVerificationFile: false
  path: seq/common_interval_decomposition.hpp
  requiredBy: []
  timestamp: '2026-08-29 09:24:19+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/2_library_checker/graph/common_interval_decomposition.test.cpp
  - test/3_yukicoder/1720.test.cpp
documentation_of: seq/common_interval_decomposition.hpp
layout: document
redirect_from:
- /library/seq/common_interval_decomposition.hpp
- /library/seq/common_interval_decomposition.hpp.html
title: seq/common_interval_decomposition.hpp
---
