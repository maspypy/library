---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: alg/monoid/add.hpp
    title: alg/monoid/add.hpp
  - icon: ':heavy_check_mark:'
    path: ds/fastset.hpp
    title: ds/fastset.hpp
  - icon: ':heavy_check_mark:'
    path: ds/segtree/dual_segtree.hpp
    title: ds/segtree/dual_segtree.hpp
  - icon: ':heavy_check_mark:'
    path: other/bit.hpp
    title: other/bit.hpp
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':warning:'
  attributes:
    links:
    - https://atcoder.jp/contests/joisc2019/tasks/joisc2019_e
    - https://atcoder.jp/contests/joisp2024/tasks/joisp2024_i
  bundledCode: "#line 1 \"ds/segtree/range_add_make_decreasing.hpp\"\n\n#line 1 \"\
    ds/segtree/dual_segtree.hpp\"\n\ntemplate <typename Monoid>\nstruct Dual_SegTree\
    \ {\n  using MA = Monoid;\n  using A = typename MA::value_type;\n  int n, log,\
    \ size;\n  vc<A> laz;\n  vc<bool> has_laz;\n\n  Dual_SegTree() : Dual_SegTree(0)\
    \ {}\n  Dual_SegTree(int n) {\n    build(n, [&](int i) -> A { return MA::id();\
    \ });\n  }\n  template <typename F>\n  Dual_SegTree(int n, F f) {\n    build(n,\
    \ f);\n  }\n\n  template <typename F>\n  void build(int m, F f) {\n    n = m;\n\
    \    log = 1;\n    while ((1 << log) < n) ++log;\n    size = 1 << log;\n    laz.assign(size\
    \ << 1, MA::id());\n    FOR(i, n) laz[size + i] = f(i);\n    has_laz.assign(size,\
    \ false);\n  }\n  void build(int n) {\n    build(n, [&](int i) -> A { return MA::id();\
    \ });\n  }\n\n  A get(int p) {\n    assert(0 <= p && p < n);\n    p += size;\n\
    \    for (int i = log; i >= 1; i--) push(p >> i);\n    return laz[p];\n  }\n\n\
    \  vc<A> get_all() {\n    FOR(i, size) push(i);\n    return {laz.begin() + size,\
    \ laz.begin() + size + n};\n  }\n\n  void set(int p, A x) {\n    get(p);\n   \
    \ laz[p + size] = x;\n  }\n\n  void apply(int l, int r, const A& a) {\n    assert(0\
    \ <= l && l <= r && r <= n);\n    if (l == r) return;\n    l += size, r += size;\n\
    \    if (!MA::commute) {\n      for (int i = log; i >= 1; i--) {\n        if (((l\
    \ >> i) << i) != l) push(l >> i);\n        if (((r >> i) << i) != r) push((r -\
    \ 1) >> i);\n      }\n    }\n    while (l < r) {\n      if (l & 1) all_apply(l++,\
    \ a);\n      if (r & 1) all_apply(--r, a);\n      l >>= 1, r >>= 1;\n    }\n \
    \ }\n\n private:\n  void push(int k) {\n    if (!has_laz[k]) return;\n    has_laz[k]\
    \ = false;\n    all_apply(2 * k, laz[k]), all_apply(2 * k + 1, laz[k]);\n    laz[k]\
    \ = MA::id();\n  }\n  void all_apply(int k, A a) {\n    laz[k] = MA::op(laz[k],\
    \ a);\n    if (k < size) has_laz[k] = true;\n  }\n};\n#line 1 \"alg/monoid/add.hpp\"\
    \n\ntemplate <typename E>\nstruct Monoid_Add {\n  using X = E;\n  using value_type\
    \ = X;\n  static constexpr X op(const X &x, const X &y) noexcept { return x +\
    \ y; }\n  static constexpr X inverse(const X &x) noexcept { return -x; }\n  static\
    \ constexpr X power(const X &x, ll n) noexcept { return X(n) * x; }\n  static\
    \ constexpr X id() { return X(0); }\n  static constexpr bool commute = true;\n\
    };\n#line 1 \"other/bit.hpp\"\n\nint popcnt(int x) { return __builtin_popcount(x);\
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
    \ / B] |= u64(bool(f(i))) << (i % B); }\n    FOR(h, log - 1) {\n      FOR(i, len(seg[h]))\
    \ {\n        seg[h + 1][i / B] |= u64(bool(seg[h][i])) << (i % B);\n      }\n\
    \    }\n  }\n\n  bool operator[](int i) const {\n    assert(0 <= i && i < n);\n\
    \    return seg[0][i / B] >> (i % B) & 1;\n  }\n  void insert(int i) {\n    assert(0\
    \ <= i && i < n);\n    for (int h = 0; h < log; h++) {\n      seg[h][i / B] |=\
    \ u64(1) << (i % B), i /= B;\n    }\n  }\n  void add(int i) { insert(i); }\n \
    \ void erase(int i) {\n    assert(0 <= i && i < n);\n    u64 x = 0;\n    for (int\
    \ h = 0; h < log; h++) {\n      seg[h][i / B] &= ~(u64(1) << (i % B));\n     \
    \ seg[h][i / B] |= x << (i % B);\n      x = bool(seg[h][i / B]);\n      i /= B;\n\
    \    }\n  }\n  void remove(int i) { erase(i); }\n\n  // min[x,n) or n\n  int next(int\
    \ i) {\n    assert(i <= n);\n    chmax(i, 0);\n    for (int h = 0; h < log; h++)\
    \ {\n      if (i / B == seg[h].size()) break;\n      u64 d = seg[h][i / B] >>\
    \ (i % B);\n      if (!d) {\n        i = i / B + 1;\n        continue;\n     \
    \ }\n      i += lowbit(d);\n      for (int g = h - 1; g >= 0; g--) {\n       \
    \ i *= B;\n        i += lowbit(seg[g][i / B]);\n      }\n      return i;\n   \
    \ }\n    return n;\n  }\n\n  // max [0,x], or -1\n  int prev(int i) {\n    assert(i\
    \ >= -1);\n    if (i >= n) i = n - 1;\n    for (int h = 0; h < log; h++) {\n \
    \     if (i == -1) break;\n      u64 d = seg[h][i / B] << (63 - i % B);\n    \
    \  if (!d) {\n        i = i / B - 1;\n        continue;\n      }\n      i -= __builtin_clzll(d);\n\
    \      for (int g = h - 1; g >= 0; g--) {\n        i *= B;\n        i += topbit(seg[g][i\
    \ / B]);\n      }\n      return i;\n    }\n    return -1;\n  }\n\n  bool any(int\
    \ l, int r) {\n    assert(0 <= l && l <= r && r <= n);\n    return next(l) < r;\n\
    \  }\n\n  // [l, r)\n  template <typename F>\n  void enumerate(int l, int r, F\
    \ f) {\n    assert(0 <= l && l <= r && r <= n);\n    for (int x = next(l); x <\
    \ r; x = next(x + 1)) f(x);\n  }\n\n  void reset() {\n    enumerate(0, n, [&](int\
    \ i) -> void { erase(i); });\n  }\n\n  string to_string() {\n    string s(n, '?');\n\
    \    for (int i = 0; i < n; ++i) s[i] = ((*this)[i] ? '1' : '0');\n    return\
    \ s;\n  }\n};\n#line 5 \"ds/segtree/range_add_make_decreasing.hpp\"\n\n// \u533A\
    \u9593\u52A0\u7B97 / \u3042\u308B\u7BC4\u56F2\u3092 prefix \u5074\u304B\u3089\u5358\
    \u8ABF(\u5897\u52A0/\u6E1B\u5C11)\u306B\u306A\u308B\u3088\u3046\u306B\u4FEE\u6B63\
    \n// \u6307\u5B9A\u3057\u306A\u304B\u3063\u305F\u5834\u5408 0 \u57CB\u3081\u3067\
    \u521D\u671F\u5316\u3055\u308C\u308B\n// https://atcoder.jp/contests/joisc2019/tasks/joisc2019_e\n\
    // https://atcoder.jp/contests/joisp2024/tasks/joisp2024_i\nstruct Range_Add_Make_Monotonic_Decreasing\
    \ {\n  // \u4EE3\u8868\u70B9\u306E\u96C6\u5408\u3092\u6301\u3064. \u4EE3\u8868\
    \u70B9\u306B\u5BFE\u3059\u308B\u5024\u3092\u53CC\u5BFE\u30BB\u30B0\u6728\u3067\
    \u6301\u3064.\n  // A[i-1]>A[i] \u3068\u306A\u3063\u3066\u3044\u308B i \u5168\u4F53\
    \u3082\u6301\u3064.\n  int n;\n  FastSet S, INC;\n  Dual_SegTree<Monoid_Add<ll>>\
    \ seg;\n\n  Range_Add_Make_Monotonic_Decreasing() {}\n  Range_Add_Make_Monotonic_Decreasing(int\
    \ n) { build(n); }\n  template <typename F>\n  Range_Add_Make_Monotonic_Decreasing(int\
    \ n, F f) {\n    build(n, f);\n  }\n  Range_Add_Make_Monotonic_Decreasing(const\
    \ vi& v) { build(v); }\n\n  void build(int m) {\n    build(m, [](int i) -> ll\
    \ { return 0; });\n  }\n  template <typename F>\n  void build(int m, F f) {\n\
    \    vi v(m);\n    FOR(i, m) v[i] = f(i);\n    build(v);\n  }\n  void build(const\
    \ vi& v) {\n    n = len(v);\n    seg.build(n, [&](int i) -> ll { return v[i];\
    \ }), S.build(n), INC.build(n + 1);\n    FOR(i, n) S.insert(i);\n    FOR(i, 1,\
    \ n) if (v[i - 1] < v[i]) INC.insert(i);\n  }\n\n  ll get(int i) { return seg.get(S.prev(i));\
    \ }\n  vi get_all() {\n    auto A = seg.get_all();\n    int p = 0;\n    FOR(i,\
    \ n) {\n      if (S[i]) p = i;\n      A[i] = A[p];\n    }\n    return A;\n  }\n\
    \  void set(int i, ll x) {\n    split(i), split(i + 1);\n    seg.set(i, x);\n\
    \    INC.insert(i), INC.insert(i + 1);\n  }\n  void range_add(int L, int R, ll\
    \ x) {\n    split(L), split(R);\n    if (x > 0) INC.insert(L);\n    if (x < 0)\
    \ INC.insert(R);\n    seg.apply(L, R, x);\n  }\n  void range_assign(int L, int\
    \ R, ll x) {\n    split(L), split(R);\n    INC.insert(L), INC.insert(R);\n   \
    \ S.enumerate(L, R, [&](int i) -> void { S.erase(i); });\n    S.insert(L);\n \
    \   seg.set(L, x);\n  }\n  void make_increasing(int L, int R) {\n    split(L),\
    \ split(R);\n    INC.enumerate(L + 1, R, [&](int i) -> void {\n      ll mi = get(i\
    \ - 1);\n      while (i < R) {\n        INC.erase(i);\n        ll now = get(i);\n\
    \        if (mi > now) break;\n        S.erase(i);\n        i = S.next(i);\n \
    \     }\n    });\n  }\n\nprivate:\n  void split(int p) {\n    if (p == 0 || p\
    \ == n || S[p]) return;\n    seg.set(p, get(p));\n    S.insert(p);\n  }\n};\n"
  code: "\n#include \"ds/segtree/dual_segtree.hpp\"\n#include \"alg/monoid/add.hpp\"\
    \n#include \"ds/fastset.hpp\"\n\n// \u533A\u9593\u52A0\u7B97 / \u3042\u308B\u7BC4\
    \u56F2\u3092 prefix \u5074\u304B\u3089\u5358\u8ABF(\u5897\u52A0/\u6E1B\u5C11)\u306B\
    \u306A\u308B\u3088\u3046\u306B\u4FEE\u6B63\n// \u6307\u5B9A\u3057\u306A\u304B\u3063\
    \u305F\u5834\u5408 0 \u57CB\u3081\u3067\u521D\u671F\u5316\u3055\u308C\u308B\n\
    // https://atcoder.jp/contests/joisc2019/tasks/joisc2019_e\n// https://atcoder.jp/contests/joisp2024/tasks/joisp2024_i\n\
    struct Range_Add_Make_Monotonic_Decreasing {\n  // \u4EE3\u8868\u70B9\u306E\u96C6\
    \u5408\u3092\u6301\u3064. \u4EE3\u8868\u70B9\u306B\u5BFE\u3059\u308B\u5024\u3092\
    \u53CC\u5BFE\u30BB\u30B0\u6728\u3067\u6301\u3064.\n  // A[i-1]>A[i] \u3068\u306A\
    \u3063\u3066\u3044\u308B i \u5168\u4F53\u3082\u6301\u3064.\n  int n;\n  FastSet\
    \ S, INC;\n  Dual_SegTree<Monoid_Add<ll>> seg;\n\n  Range_Add_Make_Monotonic_Decreasing()\
    \ {}\n  Range_Add_Make_Monotonic_Decreasing(int n) { build(n); }\n  template <typename\
    \ F>\n  Range_Add_Make_Monotonic_Decreasing(int n, F f) {\n    build(n, f);\n\
    \  }\n  Range_Add_Make_Monotonic_Decreasing(const vi& v) { build(v); }\n\n  void\
    \ build(int m) {\n    build(m, [](int i) -> ll { return 0; });\n  }\n  template\
    \ <typename F>\n  void build(int m, F f) {\n    vi v(m);\n    FOR(i, m) v[i] =\
    \ f(i);\n    build(v);\n  }\n  void build(const vi& v) {\n    n = len(v);\n  \
    \  seg.build(n, [&](int i) -> ll { return v[i]; }), S.build(n), INC.build(n +\
    \ 1);\n    FOR(i, n) S.insert(i);\n    FOR(i, 1, n) if (v[i - 1] < v[i]) INC.insert(i);\n\
    \  }\n\n  ll get(int i) { return seg.get(S.prev(i)); }\n  vi get_all() {\n   \
    \ auto A = seg.get_all();\n    int p = 0;\n    FOR(i, n) {\n      if (S[i]) p\
    \ = i;\n      A[i] = A[p];\n    }\n    return A;\n  }\n  void set(int i, ll x)\
    \ {\n    split(i), split(i + 1);\n    seg.set(i, x);\n    INC.insert(i), INC.insert(i\
    \ + 1);\n  }\n  void range_add(int L, int R, ll x) {\n    split(L), split(R);\n\
    \    if (x > 0) INC.insert(L);\n    if (x < 0) INC.insert(R);\n    seg.apply(L,\
    \ R, x);\n  }\n  void range_assign(int L, int R, ll x) {\n    split(L), split(R);\n\
    \    INC.insert(L), INC.insert(R);\n    S.enumerate(L, R, [&](int i) -> void {\
    \ S.erase(i); });\n    S.insert(L);\n    seg.set(L, x);\n  }\n  void make_increasing(int\
    \ L, int R) {\n    split(L), split(R);\n    INC.enumerate(L + 1, R, [&](int i)\
    \ -> void {\n      ll mi = get(i - 1);\n      while (i < R) {\n        INC.erase(i);\n\
    \        ll now = get(i);\n        if (mi > now) break;\n        S.erase(i);\n\
    \        i = S.next(i);\n      }\n    });\n  }\n\nprivate:\n  void split(int p)\
    \ {\n    if (p == 0 || p == n || S[p]) return;\n    seg.set(p, get(p));\n    S.insert(p);\n\
    \  }\n};\n"
  dependsOn:
  - ds/segtree/dual_segtree.hpp
  - alg/monoid/add.hpp
  - ds/fastset.hpp
  - other/bit.hpp
  isVerificationFile: false
  path: ds/segtree/range_add_make_decreasing.hpp
  requiredBy: []
  timestamp: '2026-09-04 09:44:55+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: ds/segtree/range_add_make_decreasing.hpp
layout: document
redirect_from:
- /library/ds/segtree/range_add_make_decreasing.hpp
- /library/ds/segtree/range_add_make_decreasing.hpp.html
title: ds/segtree/range_add_make_decreasing.hpp
---
