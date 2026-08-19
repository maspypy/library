---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: alg/monoid_pow.hpp
    title: alg/monoid_pow.hpp
  - icon: ':heavy_check_mark:'
    path: ds/fastset.hpp
    title: ds/fastset.hpp
  - icon: ':heavy_check_mark:'
    path: ds/segtree/segtree.hpp
    title: ds/segtree/segtree.hpp
  - icon: ':heavy_check_mark:'
    path: other/bit.hpp
    title: other/bit.hpp
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/1_mytest/range_assign.test.cpp
    title: test/1_mytest/range_assign.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/2_library_checker/data_structure/range_set_range_composite.test.cpp
    title: test/2_library_checker/data_structure/range_set_range_composite.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 1 \"ds/segtree/segtree.hpp\"\n\ntemplate <class Monoid>\nstruct\
    \ SegTree {\n  using MX = Monoid;\n  using X = typename MX::value_type;\n  using\
    \ value_type = X;\n  vc<X> dat;\n  int n, log, size;\n\n  SegTree() {}\n  SegTree(int\
    \ n) { build(n); }\n  template <typename F>\n  SegTree(int n, F f) {\n    build(n,\
    \ f);\n  }\n  SegTree(const vc<X>& v) { build(v); }\n\n  void build(int m) {\n\
    \    build(m, [](int i) -> X { return MX::unit(); });\n  }\n  void build(const\
    \ vc<X>& v) {\n    build(len(v), [&](int i) -> X { return v[i]; });\n  }\n  template\
    \ <typename F>\n  void build(int m, F f) {\n    n = m, log = 1;\n    while ((1\
    \ << log) < n) ++log;\n    size = 1 << log;\n    dat.assign(size << 1, MX::unit());\n\
    \    FOR(i, n) dat[size + i] = f(i);\n    FOR_R(i, 1, size) update(i);\n  }\n\n\
    \  X get(int i) const { return dat[size + i]; }\n  vc<X> get_all() const { return\
    \ {dat.begin() + size, dat.begin() + size + n}; }\n\n  void update(int i) { dat[i]\
    \ = Monoid::op(dat[2 * i], dat[2 * i + 1]); }\n  void set(int i, const X& x) {\n\
    \    assert(i < n);\n    dat[i += size] = x;\n    while (i >>= 1) update(i);\n\
    \  }\n\n  void multiply(int i, const X& x) {\n    assert(i < n);\n    i += size;\n\
    \    dat[i] = Monoid::op(dat[i], x);\n    while (i >>= 1) update(i);\n  }\n\n\
    \  X prod(int L, int R) const {\n    assert(0 <= L && L <= R && R <= n);\n   \
    \ X vl = Monoid::unit(), vr = Monoid::unit();\n    L += size, R += size;\n   \
    \ while (L < R) {\n      if (L & 1) vl = Monoid::op(vl, dat[L++]);\n      if (R\
    \ & 1) vr = Monoid::op(dat[--R], vr);\n      L >>= 1, R >>= 1;\n    }\n    return\
    \ Monoid::op(vl, vr);\n  }\n\n  vc<int> prod_ids(int L, int R) const {\n    assert(0\
    \ <= L && L <= R && R <= n);\n    vc<int> I, J;\n    L += size, R += size;\n \
    \   while (L < R) {\n      if (L & 1) I.eb(L++);\n      if (R & 1) J.eb(--R);\n\
    \      L >>= 1, R >>= 1;\n    }\n    reverse(all(J));\n    concat(I, J);\n   \
    \ return I;\n  }\n\n  X prod_all() const { return dat[1]; }\n\n  template <class\
    \ F>\n  int max_right(F check, int L) const {\n    assert(0 <= L && L <= n &&\
    \ check(Monoid::unit()));\n    if (L == n) return n;\n    L += size;\n    X sm\
    \ = Monoid::unit();\n    do {\n      while (L % 2 == 0) L >>= 1;\n      if (!check(Monoid::op(sm,\
    \ dat[L]))) {\n        while (L < size) {\n          L = 2 * L;\n          if\
    \ (check(Monoid::op(sm, dat[L]))) {\n            sm = Monoid::op(sm, dat[L++]);\n\
    \          }\n        }\n        return L - size;\n      }\n      sm = Monoid::op(sm,\
    \ dat[L++]);\n    } while ((L & -L) != L);\n    return n;\n  }\n\n  template <class\
    \ F>\n  int min_left(F check, int R) const {\n    assert(0 <= R && R <= n && check(Monoid::unit()));\n\
    \    if (R == 0) return 0;\n    R += size;\n    X sm = Monoid::unit();\n    do\
    \ {\n      --R;\n      while (R > 1 && (R % 2)) R >>= 1;\n      if (!check(Monoid::op(dat[R],\
    \ sm))) {\n        while (R < size) {\n          R = 2 * R + 1;\n          if\
    \ (check(Monoid::op(dat[R], sm))) {\n            sm = Monoid::op(dat[R--], sm);\n\
    \          }\n        }\n        return R + 1 - size;\n      }\n      sm = Monoid::op(dat[R],\
    \ sm);\n    } while ((R & -R) != R);\n    return 0;\n  }\n\n  // prod_{l<=i<r}\
    \ A[i xor x]\n  X xor_prod(int l, int r, int xor_val) const {\n    static_assert(Monoid::commute);\n\
    \    X x = Monoid::unit();\n    for (int k = 0; k < log + 1; ++k) {\n      if\
    \ (l >= r) break;\n      if (l & 1) {\n        x = Monoid::op(x, dat[(size >>\
    \ k) + ((l++) ^ xor_val)]);\n      }\n      if (r & 1) {\n        x = Monoid::op(x,\
    \ dat[(size >> k) + ((--r) ^ xor_val)]);\n      }\n      l /= 2, r /= 2, xor_val\
    \ /= 2;\n    }\n    return x;\n  }\n};\n#line 1 \"alg/monoid_pow.hpp\"\n\n// chat\
    \ gpt\ntemplate <typename U, typename Arg1, typename Arg2>\nstruct has_power_method\
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
    \  }\n}\n#line 1 \"other/bit.hpp\"\n\nint popcnt(int x) { return __builtin_popcount(x);\
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
    \ k) {\n  return T(1) << k;\n}\ntemplate <typename T>\nbool has_kth_bit(T x, int\
    \ k) {\n  return x >> k & 1;\n}\n\ntemplate <typename UINT>\nstruct all_bit {\n\
    \  UINT s;\n  all_bit(UINT s) : s(s) {}\n  struct iter {\n    UINT s;\n    int\
    \ operator*() const { return lowbit(s); }\n    void operator++() { s &= s - 1;\
    \ }\n    bool operator!=(nullptr_t) const { return s; }\n  };\n  iter begin()\
    \ const { return {s}; }\n  nullptr_t end() const { return nullptr; }\n};\n\ntemplate\
    \ <typename UINT>\nstruct all_subset {\n  UINT s;\n  all_subset(UINT s) : s(s)\
    \ {}\n  struct iter {\n    UINT s, t;\n    bool done = false;\n    UINT operator*()\
    \ const { return t; }\n    void operator++() {\n      done = (t == 0);\n     \
    \ t = (t - 1) & s;\n    }\n    bool operator!=(nullptr_t) const { return !done;\
    \ }\n  };\n  iter begin() const { return {s, s}; }\n  nullptr_t end() const {\
    \ return nullptr; }\n};\n\nconstexpr u64 full_mask(int n) { return n == 64 ? -1ULL\
    \ : (1ULL << n) - 1; }\n\nu64 bit_reverse(u64 x) {\n  x = ((x & 0x5555555555555555ULL)\
    \ << 1) | ((x >> 1) & 0x5555555555555555ULL);\n  x = ((x & 0x3333333333333333ULL)\
    \ << 2) | ((x >> 2) & 0x3333333333333333ULL);\n  x = ((x & 0x0f0f0f0f0f0f0f0fULL)\
    \ << 4) | ((x >> 4) & 0x0f0f0f0f0f0f0f0fULL);\n  x = ((x & 0x00ff00ff00ff00ffULL)\
    \ << 8) | ((x >> 8) & 0x00ff00ff00ff00ffULL);\n  x = ((x & 0x0000ffff0000ffffULL)\
    \ << 16) | ((x >> 16) & 0x0000ffff0000ffffULL);\n  x = (x << 32) | (x >> 32);\n\
    \  return x;\n}\n#line 2 \"ds/fastset.hpp\"\n\n// 64-ary tree\n// space: (N/63)\
    \ * u64\nstruct FastSet {\n  static constexpr u32 B = 64;\n  int n = 0, log =\
    \ 0;\n  vvc<u64> seg;\n\n  FastSet() {}\n  FastSet(int n) { build(n); }\n\n  int\
    \ size() { return n; }\n\n  void fill_one() {\n    int cur = n;\n    for (auto&\
    \ vs : seg) {\n      int p = cur / B, q = cur % B;\n      FOR(i, p) vs[i] = -1ull;\n\
    \      if (q) vs[p] = full_mask(q);\n      cur = (cur + B - 1) / B;\n    }\n \
    \ }\n\n  template <typename F>\n  FastSet(int n, F f) {\n    build(n, f);\n  }\n\
    \n  void build(int m) {\n    seg.clear();\n    n = m;\n    do {\n      seg.push_back(vc<u64>((m\
    \ + B - 1) / B));\n      m = (m + B - 1) / B;\n    } while (m > 1);\n    log =\
    \ len(seg);\n  }\n  template <typename F>\n  void build(int n, F f) {\n    build(n);\n\
    \    FOR(i, n) { seg[0][i / B] |= u64(f(i)) << (i % B); }\n    FOR(h, log - 1)\
    \ {\n      FOR(i, len(seg[h])) {\n        seg[h + 1][i / B] |= u64(bool(seg[h][i]))\
    \ << (i % B);\n      }\n    }\n  }\n\n  bool operator[](int i) const { return\
    \ seg[0][i / B] >> (i % B) & 1; }\n  void insert(int i) {\n    assert(0 <= i &&\
    \ i < n);\n    for (int h = 0; h < log; h++) {\n      seg[h][i / B] |= u64(1)\
    \ << (i % B), i /= B;\n    }\n  }\n  void add(int i) { insert(i); }\n  void erase(int\
    \ i) {\n    assert(0 <= i && i < n);\n    u64 x = 0;\n    for (int h = 0; h <\
    \ log; h++) {\n      seg[h][i / B] &= ~(u64(1) << (i % B));\n      seg[h][i /\
    \ B] |= x << (i % B);\n      x = bool(seg[h][i / B]);\n      i /= B;\n    }\n\
    \  }\n  void remove(int i) { erase(i); }\n\n  // min[x,n) or n\n  int next(int\
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
    \ l, int r) { return next(l) < r; }\n\n  // [l, r)\n  template <typename F>\n\
    \  void enumerate(int l, int r, F f) {\n    for (int x = next(l); x < r; x = next(x\
    \ + 1)) f(x);\n  }\n\n  void reset() {\n    enumerate(0, n, [&](int i) -> void\
    \ { erase(i); });\n  }\n\n  string to_string() {\n    string s(n, '?');\n    for\
    \ (int i = 0; i < n; ++i) s[i] = ((*this)[i] ? '1' : '0');\n    return s;\n  }\n\
    };\n#line 4 \"ds/segtree/range_assignment_segtree.hpp\"\n\ntemplate <typename\
    \ Monoid>\nstruct Range_Assignment_SegTree {\n  using MX = Monoid;\n  using X\
    \ = typename MX::value_type;\n  int n;\n  SegTree<MX> seg;\n  FastSet cut;\n \
    \ vc<X> dat;\n\n  Range_Assignment_SegTree() {}\n  Range_Assignment_SegTree(int\
    \ n) { build(n); }\n  template <typename F>\n  Range_Assignment_SegTree(int n,\
    \ F f) {\n    build(n, f);\n  }\n  Range_Assignment_SegTree(const vc<X> &v) {\
    \ build(v); }\n\n  void build(int m) {\n    build(m, [](int i) -> X { return MX::unit();\
    \ });\n  }\n  void build(const vc<X> &v) {\n    build(len(v), [&](int i) -> X\
    \ { return v[i]; });\n  }\n  template <typename F>\n  void build(int m, F f) {\n\
    \    n = m;\n    seg.build(m, f), cut.build(n, [&](int i) -> int { return 1; });\n\
    \    dat = seg.get_all();\n  }\n\n  X prod(int l, int r) {\n    int a = cut.prev(l),\
    \ b = cut.next(l), c = cut.prev(r);\n    if (a == c) {\n      return monoid_pow<MX>(dat[a],\
    \ r - l);\n    };\n    assert(b <= c);\n    X x = monoid_pow<MX>(dat[a], b - l);\n\
    \    X y = seg.prod(b, c);\n    X z = monoid_pow<MX>(dat[c], r - c);\n    return\
    \ MX::op(MX::op(x, y), z);\n  }\n\n  X prod_all() { return seg.prod_all(); }\n\
    \n  void assign(int l, int r, X x) {\n    if (l == r) return;\n    int a = cut.prev(l),\
    \ b = cut.next(r);\n    if (a < l) seg.set(a, monoid_pow<MX>(dat[a], l - a));\n\
    \    if (r < b) {\n      X y = dat[cut.prev(r)];\n      dat[r] = y, cut.insert(r),\
    \ seg.set(r, monoid_pow<MX>(y, b - r));\n    }\n    cut.enumerate(l + 1, r,\n\
    \                  [&](int i) -> void { seg.set(i, MX::unit()), cut.erase(i);\
    \ });\n    dat[l] = x, cut.insert(l), seg.set(l, monoid_pow<MX>(x, r - l));\n\
    \  }\n\n  vc<X> get_all() {\n    vc<X> ANS(n);\n    int p = 0;\n    while (p <\
    \ n) {\n      int q = cut.next(p + 1);\n      FOR(i, p, q) ANS[i] = dat[p];\n\
    \      p = q;\n    }\n    return ANS;\n  }\n};\n"
  code: "#include \"ds/segtree/segtree.hpp\"\n#include \"alg/monoid_pow.hpp\"\n#include\
    \ \"ds/fastset.hpp\"\n\ntemplate <typename Monoid>\nstruct Range_Assignment_SegTree\
    \ {\n  using MX = Monoid;\n  using X = typename MX::value_type;\n  int n;\n  SegTree<MX>\
    \ seg;\n  FastSet cut;\n  vc<X> dat;\n\n  Range_Assignment_SegTree() {}\n  Range_Assignment_SegTree(int\
    \ n) { build(n); }\n  template <typename F>\n  Range_Assignment_SegTree(int n,\
    \ F f) {\n    build(n, f);\n  }\n  Range_Assignment_SegTree(const vc<X> &v) {\
    \ build(v); }\n\n  void build(int m) {\n    build(m, [](int i) -> X { return MX::unit();\
    \ });\n  }\n  void build(const vc<X> &v) {\n    build(len(v), [&](int i) -> X\
    \ { return v[i]; });\n  }\n  template <typename F>\n  void build(int m, F f) {\n\
    \    n = m;\n    seg.build(m, f), cut.build(n, [&](int i) -> int { return 1; });\n\
    \    dat = seg.get_all();\n  }\n\n  X prod(int l, int r) {\n    int a = cut.prev(l),\
    \ b = cut.next(l), c = cut.prev(r);\n    if (a == c) {\n      return monoid_pow<MX>(dat[a],\
    \ r - l);\n    };\n    assert(b <= c);\n    X x = monoid_pow<MX>(dat[a], b - l);\n\
    \    X y = seg.prod(b, c);\n    X z = monoid_pow<MX>(dat[c], r - c);\n    return\
    \ MX::op(MX::op(x, y), z);\n  }\n\n  X prod_all() { return seg.prod_all(); }\n\
    \n  void assign(int l, int r, X x) {\n    if (l == r) return;\n    int a = cut.prev(l),\
    \ b = cut.next(r);\n    if (a < l) seg.set(a, monoid_pow<MX>(dat[a], l - a));\n\
    \    if (r < b) {\n      X y = dat[cut.prev(r)];\n      dat[r] = y, cut.insert(r),\
    \ seg.set(r, monoid_pow<MX>(y, b - r));\n    }\n    cut.enumerate(l + 1, r,\n\
    \                  [&](int i) -> void { seg.set(i, MX::unit()), cut.erase(i);\
    \ });\n    dat[l] = x, cut.insert(l), seg.set(l, monoid_pow<MX>(x, r - l));\n\
    \  }\n\n  vc<X> get_all() {\n    vc<X> ANS(n);\n    int p = 0;\n    while (p <\
    \ n) {\n      int q = cut.next(p + 1);\n      FOR(i, p, q) ANS[i] = dat[p];\n\
    \      p = q;\n    }\n    return ANS;\n  }\n};\n"
  dependsOn:
  - ds/segtree/segtree.hpp
  - alg/monoid_pow.hpp
  - ds/fastset.hpp
  - other/bit.hpp
  isVerificationFile: false
  path: ds/segtree/range_assignment_segtree.hpp
  requiredBy: []
  timestamp: '2026-08-19 06:34:57+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/1_mytest/range_assign.test.cpp
  - test/2_library_checker/data_structure/range_set_range_composite.test.cpp
documentation_of: ds/segtree/range_assignment_segtree.hpp
layout: document
redirect_from:
- /library/ds/segtree/range_assignment_segtree.hpp
- /library/ds/segtree/range_assignment_segtree.hpp.html
title: ds/segtree/range_assignment_segtree.hpp
---
