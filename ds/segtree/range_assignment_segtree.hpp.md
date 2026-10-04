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
    \    build(m, [](int i) -> X { return MX::id(); });\n  }\n  void build(const vc<X>&\
    \ v) {\n    build(len(v), [&](int i) -> X { return v[i]; });\n  }\n  template\
    \ <typename F>\n  void build(int m, F f) {\n    n = m, log = 0;\n    while ((1\
    \ << log) < n) ++log;\n    size = 1 << log;\n    dat.assign(size << 1, MX::id());\n\
    \    FOR(i, n) dat[size + i] = f(i);\n    FOR_R(i, 1, size) update(i);\n  }\n\n\
    \  X get(int i) const { return dat[size + i]; }\n  vc<X> get_all() const { return\
    \ {dat.begin() + size, dat.begin() + size + n}; }\n\n  void update(int i) { dat[i]\
    \ = Monoid::op(dat[2 * i], dat[2 * i + 1]); }\n  void set(int i, const X& x) {\n\
    \    assert(i < n);\n    dat[i += size] = x;\n    while (i >>= 1) update(i);\n\
    \  }\n\n  void multiply(int i, const X& x) {\n    assert(i < n);\n    i += size;\n\
    \    dat[i] = Monoid::op(dat[i], x);\n    while (i >>= 1) update(i);\n  }\n\n\
    \  X prod(int L, int R) const {\n    assert(0 <= L && L <= R && R <= n);\n   \
    \ X vl = Monoid::id(), vr = Monoid::id();\n    L += size, R += size;\n    while\
    \ (L < R) {\n      if (L & 1) vl = Monoid::op(vl, dat[L++]);\n      if (R & 1)\
    \ vr = Monoid::op(dat[--R], vr);\n      L >>= 1, R >>= 1;\n    }\n    return Monoid::op(vl,\
    \ vr);\n  }\n\n  vc<int> prod_ids(int L, int R) const {\n    assert(0 <= L &&\
    \ L <= R && R <= n);\n    vc<int> I, J;\n    L += size, R += size;\n    while\
    \ (L < R) {\n      if (L & 1) I.eb(L++);\n      if (R & 1) J.eb(--R);\n      L\
    \ >>= 1, R >>= 1;\n    }\n    reverse(all(J));\n    concat(I, J);\n    return\
    \ I;\n  }\n\n  X prod_all() const { return dat[1]; }\n\n  template <class F>\n\
    \  int max_right(F check, int L) const {\n    assert(0 <= L && L <= n && check(Monoid::id()));\n\
    \    if (L == n) return n;\n    L += size;\n    X sm = Monoid::id();\n    do {\n\
    \      while (L % 2 == 0) L >>= 1;\n      if (!check(Monoid::op(sm, dat[L])))\
    \ {\n        while (L < size) {\n          L = 2 * L;\n          if (check(Monoid::op(sm,\
    \ dat[L]))) {\n            sm = Monoid::op(sm, dat[L++]);\n          }\n     \
    \   }\n        return L - size;\n      }\n      sm = Monoid::op(sm, dat[L++]);\n\
    \    } while ((L & -L) != L);\n    return n;\n  }\n\n  template <class F>\n  int\
    \ min_left(F check, int R) const {\n    assert(0 <= R && R <= n && check(Monoid::id()));\n\
    \    if (R == 0) return 0;\n    R += size;\n    X sm = Monoid::id();\n    do {\n\
    \      --R;\n      while (R > 1 && (R % 2)) R >>= 1;\n      if (!check(Monoid::op(dat[R],\
    \ sm))) {\n        while (R < size) {\n          R = 2 * R + 1;\n          if\
    \ (check(Monoid::op(dat[R], sm))) {\n            sm = Monoid::op(dat[R--], sm);\n\
    \          }\n        }\n        return R + 1 - size;\n      }\n      sm = Monoid::op(dat[R],\
    \ sm);\n    } while ((R & -R) != R);\n    return 0;\n  }\n\n  // prod_{l<=i<r}\
    \ A[i xor x]\n  X xor_prod(int l, int r, int xor_val) const {\n    static_assert(Monoid::commute);\n\
    \    X x = Monoid::id();\n    for (int k = 0; k < log + 1; ++k) {\n      if (l\
    \ >= r) break;\n      if (l & 1) {\n        x = Monoid::op(x, dat[(size >> k)\
    \ + ((l++) ^ xor_val)]);\n      }\n      if (r & 1) {\n        x = Monoid::op(x,\
    \ dat[(size >> k) + ((--r) ^ xor_val)]);\n      }\n      l /= 2, r /= 2, xor_val\
    \ /= 2;\n    }\n    return x;\n  }\n\n  // f(i), i in I\n  // \u8FD1\u3044\u30A4\
    \u30F3\u30C7\u30C3\u30AF\u30B9\u3092\u5927\u91CF\u306B\u540C\u6642\u66F4\u65B0\
    \u3057\u305F\u3044\u3068\u304D\u306B\u52B9\u7387\u304C\u826F\u304F\u306A\u308B\
    \u3068\u3044\u3046\u72D9\u3044\n  template <typename F>\n  void set_many_sorted(vc<int>\
    \ I, F f) {\n    if (I.empty()) return;\n\n    FOR(k, len(I)) {\n      assert(0\
    \ <= I[k] && I[k] < n);\n      if (k) assert(I[k - 1] < I[k]);\n    }\n\n    FOR(k,\
    \ len(I)) {\n      int i = I[k];\n      dat[size + i] = f(i);\n      I[k] += size;\n\
    \    }\n\n    int m = len(I);\n    while (I[0] > 1) {\n      int nxt = 0;\n  \
    \    int last = -1;\n      FOR(k, m) {\n        int p = I[k] >> 1;\n        if\
    \ (p == last) continue;\n        update(p);\n        I[nxt++] = p;\n        last\
    \ = p;\n      }\n      m = nxt;\n    }\n  }\n};\n#line 1 \"alg/monoid_pow.hpp\"\
    \n\n// chat gpt\ntemplate <typename U, typename Arg1, typename Arg2>\nstruct has_power_method\
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
    \ >= 0);\n    if (exp == 0) return Monoid::id();\n    if (exp == 1) return x;\n\
    \    X res = Monoid::id();\n    while (exp) {\n      if (exp & 1) res = Monoid::op(res,\
    \ x);\n      x = Monoid::op(x, x);\n      exp >>= 1;\n    }\n    return res;\n\
    \  }\n}\n#line 1 \"ds/fastset.hpp\"\n// 64-ary tree\n// space: (N/63) * u64\n\
    struct FastSet {\n  static constexpr u32 B = 64;\n  int n = 0, log = 0;\n  vvc<u64>\
    \ seg;\n\n  FastSet() {}\n  FastSet(int n) { build(n); }\n\n  int size() { return\
    \ n; }\n\n  void fill_one() {\n    int cur = n;\n    for (auto& vs : seg) {\n\
    \      int p = cur / B, q = cur % B;\n      FOR(i, p) vs[i] = -1ull;\n      if\
    \ (q) vs[p] = full_mask(q);\n      cur = (cur + B - 1) / B;\n    }\n  }\n\n  template\
    \ <typename F>\n  FastSet(int n, F f) {\n    build(n, f);\n  }\n\n  void build(int\
    \ m) {\n    seg.clear();\n    n = m;\n    do {\n      seg.push_back(vc<u64>((m\
    \ + B - 1) / B));\n      m = (m + B - 1) / B;\n    } while (m > 1);\n    log =\
    \ len(seg);\n  }\n  template <typename F>\n  void build(int n, F f) {\n    build(n);\n\
    \    FOR(i, n) { seg[0][i / B] |= u64(bool(f(i))) << (i % B); }\n    FOR(h, log\
    \ - 1) {\n      FOR(i, len(seg[h])) {\n        seg[h + 1][i / B] |= u64(bool(seg[h][i]))\
    \ << (i % B);\n      }\n    }\n  }\n\n  bool operator[](int i) const {\n    assert(0\
    \ <= i && i < n);\n    return seg[0][i / B] >> (i % B) & 1;\n  }\n  void insert(int\
    \ i) {\n    assert(0 <= i && i < n);\n    for (int h = 0; h < log; h++) {\n  \
    \    u64& x = seg[h][i / B];\n      u64 mask = u64(1) << (i % B);\n      if (x\
    \ & mask) return;\n      x |= mask;\n      i /= B;\n    }\n  }\n  void add(int\
    \ i) { insert(i); }\n  void erase(int i) {\n    assert(0 <= i && i < n);\n   \
    \ for (int h = 0; h < log; h++) {\n      u64& x = seg[h][i / B];\n      u64 mask\
    \ = u64(1) << (i % B);\n      if (!(x & mask)) return;\n      x ^= mask;\n   \
    \   if (x) return;\n      i /= B;\n    }\n  }\n  void remove(int i) { erase(i);\
    \ }\n\n  // min[x,n) or n\n  int next(int i) {\n    assert(i <= n);\n    chmax(i,\
    \ 0);\n    for (int h = 0; h < log; h++) {\n      if (i / B == seg[h].size())\
    \ break;\n      u64 d = seg[h][i / B] >> (i % B);\n      if (!d) {\n        i\
    \ = i / B + 1;\n        continue;\n      }\n      i += lowbit(d);\n      for (int\
    \ g = h - 1; g >= 0; g--) {\n        i *= B;\n        i += lowbit(seg[g][i / B]);\n\
    \      }\n      return i;\n    }\n    return n;\n  }\n\n  // max [0,x], or -1\n\
    \  int prev(int i) {\n    assert(i >= -1);\n    if (i >= n) i = n - 1;\n    for\
    \ (int h = 0; h < log; h++) {\n      if (i == -1) break;\n      u64 d = seg[h][i\
    \ / B] << (63 - i % B);\n      if (!d) {\n        i = i / B - 1;\n        continue;\n\
    \      }\n      i -= __builtin_clzll(d);\n      for (int g = h - 1; g >= 0; g--)\
    \ {\n        i *= B;\n        i += topbit(seg[g][i / B]);\n      }\n      return\
    \ i;\n    }\n    return -1;\n  }\n\n  bool any(int l, int r) {\n    assert(0 <=\
    \ l && l <= r && r <= n);\n    return next(l) < r;\n  }\n\n  // [l, r). erase=true\
    \ \u306E\u3068\u304D\u3001callback \u5185\u304B\u3089 this \u3092\u5909\u66F4\u3057\
    \u3066\u306F\u3044\u3051\u306A\u3044\u3002\n  template <typename F>\n  void enumerate(int\
    \ l, int r, F f, bool erase = false) {\n    assert(0 <= l && l <= r && r <= n);\n\
    \    if (!erase) {\n      for (int x = next(l); x < r; x = next(x + 1)) f(x);\n\
    \      return;\n    }\n    for (int x = next(l); x < r;) {\n      int w = x /\
    \ B;\n      int lo = max(l, w * int(B)) - w * int(B);\n      int hi = min(r, (w\
    \ + 1) * int(B)) - w * int(B);\n      u64 erase_bits = seg[0][w] & (full_mask(hi)\
    \ & ~full_mask(lo));\n      u64 bits = erase_bits;\n      while (bits) {\n   \
    \     int k = lowbit(bits);\n        f(w * int(B) + k);\n        bits ^= u64(1)\
    \ << k;\n      }\n      seg[0][w] ^= erase_bits;\n      if (!seg[0][w]) propagate_empty_word(w);\n\
    \      x = next(min(r, (w + 1) * int(B)));\n    }\n  }\n\n  void reset() {\n \
    \   int x = next(0);\n    while (x < n) {\n      int w = x / B;\n      seg[0][w]\
    \ = 0;\n      propagate_empty_word(w);\n      x = next(min(n, (w + 1) * int(B)));\n\
    \    }\n  }\n\n  string to_string() {\n    string s(n, '?');\n    for (int i =\
    \ 0; i < n; ++i) s[i] = ((*this)[i] ? '1' : '0');\n    return s;\n  }\n\n private:\n\
    \  // seg[0][w] \u304C 0 \u306B\u306A\u3063\u305F\u5F8C\u306B\u547C\u3076\u3002\
    \n  void propagate_empty_word(int i) {\n    for (int h = 1; h < log; ++h) {\n\
    \      u64& y = seg[h][i / B];\n      u64 mask = u64(1) << (i % B);\n      y ^=\
    \ mask;\n      if (y) break;\n      i /= B;\n    }\n  }\n};\n#line 4 \"ds/segtree/range_assignment_segtree.hpp\"\
    \n\ntemplate <typename Monoid>\nstruct Range_Assignment_SegTree {\n  using MX\
    \ = Monoid;\n  using X = typename MX::value_type;\n  int n;\n  SegTree<MX> seg;\n\
    \  FastSet cut;\n  vc<X> dat;\n\n  Range_Assignment_SegTree() {}\n  Range_Assignment_SegTree(int\
    \ n) { build(n); }\n  template <typename F>\n  Range_Assignment_SegTree(int n,\
    \ F f) {\n    build(n, f);\n  }\n  Range_Assignment_SegTree(const vc<X> &v) {\
    \ build(v); }\n\n  void build(int m) {\n    build(m, [](int i) -> X { return MX::id();\
    \ });\n  }\n  void build(const vc<X> &v) {\n    build(len(v), [&](int i) -> X\
    \ { return v[i]; });\n  }\n  template <typename F>\n  void build(int m, F f) {\n\
    \    n = m;\n    cut.build(n);\n    cut.fill_one();\n    dat.resize(m);\n    seg.build(m,\
    \ [&](int i) { return dat[i] = f(i); });\n  }\n\n  X prod(int l, int r) {\n  \
    \  int a = cut.prev(l), c = cut.prev(r);\n    if (a == c) {\n      return monoid_pow<MX>(dat[a],\
    \ r - l);\n    };\n    int b = cut.next(l);\n    assert(b <= c);\n    X x = monoid_pow<MX>(dat[a],\
    \ b - l);\n    X y = seg.prod(b, c);\n    X z = monoid_pow<MX>(dat[c], r - c);\n\
    \    return MX::op(MX::op(x, y), z);\n  }\n\n  X prod_all() { return seg.prod_all();\
    \ }\n\n  void assign(int l, int r, X x) {\n    if (l == r) return;\n\n    int\
    \ a = cut.prev(l);\n    int b = cut.next(r);\n\n    bool has_left = (a < l);\n\
    \    bool has_right = (r < b);\n\n    X left, right;\n    if (has_left) {\n  \
    \    left = monoid_pow<MX>(dat[a], l - a);\n    }\n\n    if (has_right) {\n  \
    \    X y = dat[cut.prev(r)];\n      dat[r] = y;\n      right = monoid_pow<MX>(y,\
    \ b - r);\n    }\n\n    X mid = monoid_pow<MX>(x, r - l);\n\n    vc<int> I;\n\
    \    if (has_left) I.eb(a);\n    I.eb(l);\n    cut.enumerate(l + 1, r, [&](int\
    \ i) { I.eb(i); }, true);\n\n    if (has_right) I.eb(r);\n\n    // \u3053\u3053\
    \u3067 I \u306F strictly increasing\n    dat[l] = x;\n    cut.insert(l);\n   \
    \ if (has_right) cut.insert(r);\n\n    seg.set_many_sorted(move(I), [&](int i)\
    \ -> X {\n      if (has_left && i == a) return left;\n      if (i == l) return\
    \ mid;\n      if (has_right && i == r) return right;\n      return MX::id();\n\
    \    });\n  }\n\n  vc<X> get_all() {\n    vc<X> ANS(n);\n    int p = 0;\n    while\
    \ (p < n) {\n      int q = cut.next(p + 1);\n      FOR(i, p, q) ANS[i] = dat[p];\n\
    \      p = q;\n    }\n    return ANS;\n  }\n};\n"
  code: "#include \"ds/segtree/segtree.hpp\"\n#include \"alg/monoid_pow.hpp\"\n#include\
    \ \"ds/fastset.hpp\"\n\ntemplate <typename Monoid>\nstruct Range_Assignment_SegTree\
    \ {\n  using MX = Monoid;\n  using X = typename MX::value_type;\n  int n;\n  SegTree<MX>\
    \ seg;\n  FastSet cut;\n  vc<X> dat;\n\n  Range_Assignment_SegTree() {}\n  Range_Assignment_SegTree(int\
    \ n) { build(n); }\n  template <typename F>\n  Range_Assignment_SegTree(int n,\
    \ F f) {\n    build(n, f);\n  }\n  Range_Assignment_SegTree(const vc<X> &v) {\
    \ build(v); }\n\n  void build(int m) {\n    build(m, [](int i) -> X { return MX::id();\
    \ });\n  }\n  void build(const vc<X> &v) {\n    build(len(v), [&](int i) -> X\
    \ { return v[i]; });\n  }\n  template <typename F>\n  void build(int m, F f) {\n\
    \    n = m;\n    cut.build(n);\n    cut.fill_one();\n    dat.resize(m);\n    seg.build(m,\
    \ [&](int i) { return dat[i] = f(i); });\n  }\n\n  X prod(int l, int r) {\n  \
    \  int a = cut.prev(l), c = cut.prev(r);\n    if (a == c) {\n      return monoid_pow<MX>(dat[a],\
    \ r - l);\n    };\n    int b = cut.next(l);\n    assert(b <= c);\n    X x = monoid_pow<MX>(dat[a],\
    \ b - l);\n    X y = seg.prod(b, c);\n    X z = monoid_pow<MX>(dat[c], r - c);\n\
    \    return MX::op(MX::op(x, y), z);\n  }\n\n  X prod_all() { return seg.prod_all();\
    \ }\n\n  void assign(int l, int r, X x) {\n    if (l == r) return;\n\n    int\
    \ a = cut.prev(l);\n    int b = cut.next(r);\n\n    bool has_left = (a < l);\n\
    \    bool has_right = (r < b);\n\n    X left, right;\n    if (has_left) {\n  \
    \    left = monoid_pow<MX>(dat[a], l - a);\n    }\n\n    if (has_right) {\n  \
    \    X y = dat[cut.prev(r)];\n      dat[r] = y;\n      right = monoid_pow<MX>(y,\
    \ b - r);\n    }\n\n    X mid = monoid_pow<MX>(x, r - l);\n\n    vc<int> I;\n\
    \    if (has_left) I.eb(a);\n    I.eb(l);\n    cut.enumerate(l + 1, r, [&](int\
    \ i) { I.eb(i); }, true);\n\n    if (has_right) I.eb(r);\n\n    // \u3053\u3053\
    \u3067 I \u306F strictly increasing\n    dat[l] = x;\n    cut.insert(l);\n   \
    \ if (has_right) cut.insert(r);\n\n    seg.set_many_sorted(move(I), [&](int i)\
    \ -> X {\n      if (has_left && i == a) return left;\n      if (i == l) return\
    \ mid;\n      if (has_right && i == r) return right;\n      return MX::id();\n\
    \    });\n  }\n\n  vc<X> get_all() {\n    vc<X> ANS(n);\n    int p = 0;\n    while\
    \ (p < n) {\n      int q = cut.next(p + 1);\n      FOR(i, p, q) ANS[i] = dat[p];\n\
    \      p = q;\n    }\n    return ANS;\n  }\n};\n"
  dependsOn:
  - ds/segtree/segtree.hpp
  - alg/monoid_pow.hpp
  - ds/fastset.hpp
  isVerificationFile: false
  path: ds/segtree/range_assignment_segtree.hpp
  requiredBy: []
  timestamp: '2026-10-05 00:45:05+09:00'
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
