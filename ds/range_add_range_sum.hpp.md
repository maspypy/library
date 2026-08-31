---
data:
  _extendedDependsOn:
  - icon: ':question:'
    path: alg/monoid/add.hpp
    title: alg/monoid/add.hpp
  - icon: ':question:'
    path: ds/fenwicktree/fenwicktree.hpp
    title: ds/fenwicktree/fenwicktree.hpp
  - icon: ':question:'
    path: other/bit.hpp
    title: other/bit.hpp
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/4_aoj/DSL_2_E.test.cpp
    title: test/4_aoj/DSL_2_E.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/4_aoj/DSL_2_G.test.cpp
    title: test/4_aoj/DSL_2_G.test.cpp
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
    \  x = (x << 32) | (x >> 32);\n  return x;\n}\n#line 1 \"alg/monoid/add.hpp\"\n\
    \ntemplate <typename E>\nstruct Monoid_Add {\n  using X = E;\n  using value_type\
    \ = X;\n  static constexpr X op(const X &x, const X &y) noexcept { return x +\
    \ y; }\n  static constexpr X inverse(const X &x) noexcept { return -x; }\n  static\
    \ constexpr X power(const X &x, ll n) noexcept { return X(n) * x; }\n  static\
    \ constexpr X id() { return X(0); }\n  static constexpr bool commute = true;\n\
    };\n#line 3 \"ds/fenwicktree/fenwicktree.hpp\"\n\ntemplate <typename Monoid>\n\
    struct FenwickTree {\n  using G = Monoid;\n  using MX = Monoid;\n  using E = typename\
    \ G::value_type;\n  int n;\n  vector<E> dat;\n  E total;\n\n  FenwickTree() {}\n\
    \  FenwickTree(int n) { build(n); }\n  template <typename F>\n  FenwickTree(int\
    \ n, F f) {\n    build(n, f);\n  }\n  FenwickTree(const vc<E>& v) { build(v);\
    \ }\n\n  void build(int m) {\n    n = m;\n    dat.assign(m, G::id());\n    total\
    \ = G::id();\n  }\n  void build(const vc<E>& v) {\n    build(len(v), [&](int i)\
    \ -> E { return v[i]; });\n  }\n  template <typename F>\n  void build(int m, F\
    \ f) {\n    n = m;\n    dat.clear();\n    dat.reserve(n);\n    total = G::id();\n\
    \    FOR(i, n) { dat.eb(f(i)); }\n    for (int i = 1; i <= n; ++i) {\n      int\
    \ j = i + (i & -i);\n      if (j <= n) dat[j - 1] = G::op(dat[i - 1], dat[j -\
    \ 1]);\n    }\n    total = prefix_sum(m);\n  }\n\n  E prod_all() const { return\
    \ total; }\n  E sum_all() const { return total; }\n  E sum(int k) const { return\
    \ prefix_sum(k); }\n  E prod(int k) const { return prefix_prod(k); }\n  E prefix_sum(int\
    \ k) const { return prefix_prod(k); }\n  E prefix_prod(int k) const {\n    chmin(k,\
    \ n);\n    E ret = G::id();\n    for (; k > 0; k -= k & -k) ret = G::op(ret, dat[k\
    \ - 1]);\n    return ret;\n  }\n  E sum(int L, int R) const { return prod(L, R);\
    \ }\n  E prod(int L, int R) const {\n    chmax(L, 0), chmin(R, n);\n    if (L\
    \ == 0) return prefix_prod(R);\n    assert(0 <= L && L <= R && R <= n);\n    E\
    \ pos = G::id(), neg = G::id();\n    while (L < R) {\n      pos = G::op(pos, dat[R\
    \ - 1]), R -= R & -R;\n    }\n    while (R < L) {\n      neg = G::op(neg, dat[L\
    \ - 1]), L -= L & -L;\n    }\n    return G::op(pos, G::inverse(neg));\n  }\n\n\
    \  vc<E> get_all() const {\n    vc<E> res(n);\n    FOR(i, n) res[i] = prod(i,\
    \ i + 1);\n    return res;\n  }\n\n  void add(int k, E x) { multiply(k, x); }\n\
    \  void multiply(int k, E x) {\n    SHOW(n, k);\n    static_assert(G::commute);\n\
    \    assert(0 <= k && k < n);\n    total = G::op(total, x);\n    for (++k; k <=\
    \ n; k += k & -k) dat[k - 1] = G::op(dat[k - 1], x);\n  }\n  void set(int k, E\
    \ x) { add(k, G::op(G::inverse(prod(k, k + 1)), x)); }\n\n  template <class F>\n\
    \  int max_right(const F check, int L = 0) const {\n    assert(check(G::id()));\n\
    \    E s = G::id();\n    int i = L;\n    // 2^k \u9032\u3080\u3068\u30C0\u30E1\
    \n    int k = [&]() {\n      while (1) {\n        if (i % 2 == 1) {\n        \
    \  s = G::op(s, G::inverse(dat[i - 1])), i -= 1;\n        }\n        if (i ==\
    \ 0) {\n          return topbit(n) + 1;\n        }\n        int k = lowbit(i)\
    \ - 1;\n        if (i + (1 << k) > n) return k;\n        E t = G::op(s, dat[i\
    \ + (1 << k) - 1]);\n        if (!check(t)) {\n          return k;\n        }\n\
    \        s = G::op(s, G::inverse(dat[i - 1])), i -= i & -i;\n      }\n    }();\n\
    \    while (k) {\n      --k;\n      if (i + (1 << k) - 1 < len(dat)) {\n     \
    \   E t = G::op(s, dat[i + (1 << k) - 1]);\n        if (i + (1 << k) <= L || check(t))\
    \ {\n          i += (1 << k), s = t;\n        }\n      }\n    }\n    return i;\n\
    \  }\n\n  // check(i, x)\n  template <class F>\n  int max_right_with_index(const\
    \ F check, int L = 0) const {\n    assert(check(L, G::id()));\n    E s = G::id();\n\
    \    int i = L;\n    // 2^k \u9032\u3080\u3068\u30C0\u30E1\n    int k = [&]()\
    \ {\n      while (1) {\n        if (i % 2 == 1) {\n          s = G::op(s, G::inverse(dat[i\
    \ - 1])), i -= 1;\n        }\n        if (i == 0) {\n          return topbit(n)\
    \ + 1;\n        }\n        int k = lowbit(i) - 1;\n        if (i + (1 << k) >\
    \ n) return k;\n        E t = G::op(s, dat[i + (1 << k) - 1]);\n        if (!check(i\
    \ + (1 << k), t)) {\n          return k;\n        }\n        s = G::op(s, G::inverse(dat[i\
    \ - 1])), i -= i & -i;\n      }\n    }();\n    while (k) {\n      --k;\n     \
    \ if (i + (1 << k) - 1 < len(dat)) {\n        E t = G::op(s, dat[i + (1 << k)\
    \ - 1]);\n        if (i + (1 << k) <= L || check(i + (1 << k), t)) {\n       \
    \   i += (1 << k), s = t;\n        }\n      }\n    }\n    return i;\n  }\n\n \
    \ template <class F>\n  int min_left(const F check, int R) const {\n    assert(check(G::id()));\n\
    \    E s = G::id();\n    int i = R;\n    // false \u306B\u306A\u308B\u3068\u3053\
    \u308D\u307E\u3067\u623B\u308B\n    int k = 0;\n    while (i > 0 && check(s))\
    \ {\n      s = G::op(s, dat[i - 1]);\n      k = lowbit(i);\n      i -= i & -i;\n\
    \    }\n    if (check(s)) {\n      assert(i == 0);\n      return 0;\n    }\n \
    \   // 2^k \u9032\u3080\u3068 ok \u306B\u306A\u308B\n    // false \u3092\u7DAD\
    \u6301\u3057\u3066\u9032\u3080\n    while (k) {\n      --k;\n      E t = G::op(s,\
    \ G::inverse(dat[i + (1 << k) - 1]));\n      if (!check(t)) {\n        i += (1\
    \ << k), s = t;\n      }\n    }\n    return i + 1;\n  }\n\n  int kth(E k, int\
    \ L = 0) const {\n    return max_right([&k](E x) -> bool { return x <= k; }, L);\n\
    \  }\n};\n#line 2 \"ds/range_add_range_sum.hpp\"\n\ntemplate <typename Monoid>\n\
    struct Range_Add_Range_Sum {\n  using MX = Monoid;\n  using E = typename MX::value_type;\n\
    \n  struct Mono {\n    using value_type = pair<E, E>;\n    using X = value_type;\n\
    \    static X op(X x, X y) { return {MX::op(x.fi, y.fi), MX::op(x.se, y.se)};\
    \ }\n    static constexpr X id() { return {MX::id(), MX::id()}; }\n    static\
    \ constexpr bool commute = 1;\n  };\n  FenwickTree<Mono> bit;\n\n  Range_Add_Range_Sum()\
    \ {}\n  Range_Add_Range_Sum(int n) { build(n); }\n  template <typename F>\n  Range_Add_Range_Sum(int\
    \ n, F f) {\n    build(n, f);\n  }\n  Range_Add_Range_Sum(const vc<E>& v) { build(v);\
    \ }\n\n  void build(int m) {\n    build(m, [](int i) -> E { return MX::id(); });\n\
    \  }\n  void build(const vc<E>& v) {\n    build(len(v), [&](int i) -> E { return\
    \ v[i]; });\n  }\n  template <typename F>\n  void build(int m, F f) {\n    bit.build(m\
    \ + 1, [&](int i) -> pair<E, E> {\n      if (i == m) return {MX::id(), MX::id()};\n\
    \      return {f(i), MX::id()};\n    });\n  }\n\n  void add(int L, int R, E a)\
    \ {\n    E b = MX::inverse(a);\n    bit.add(L, {MX::power(b, L), a});\n    bit.add(R,\
    \ {MX::power(a, R), b});\n  }\n\n  E sum(int L, int R) {\n    auto [x0, x1] =\
    \ bit.sum(L);\n    auto [y0, y1] = bit.sum(R);\n    E x = MX::op(MX::power(x1,\
    \ L), x0);\n    E y = MX::op(MX::power(y1, R), y0);\n    return MX::op(MX::inverse(x),\
    \ y);\n  }\n};\n"
  code: "#include \"ds/fenwicktree/fenwicktree.hpp\"\n\ntemplate <typename Monoid>\n\
    struct Range_Add_Range_Sum {\n  using MX = Monoid;\n  using E = typename MX::value_type;\n\
    \n  struct Mono {\n    using value_type = pair<E, E>;\n    using X = value_type;\n\
    \    static X op(X x, X y) { return {MX::op(x.fi, y.fi), MX::op(x.se, y.se)};\
    \ }\n    static constexpr X id() { return {MX::id(), MX::id()}; }\n    static\
    \ constexpr bool commute = 1;\n  };\n  FenwickTree<Mono> bit;\n\n  Range_Add_Range_Sum()\
    \ {}\n  Range_Add_Range_Sum(int n) { build(n); }\n  template <typename F>\n  Range_Add_Range_Sum(int\
    \ n, F f) {\n    build(n, f);\n  }\n  Range_Add_Range_Sum(const vc<E>& v) { build(v);\
    \ }\n\n  void build(int m) {\n    build(m, [](int i) -> E { return MX::id(); });\n\
    \  }\n  void build(const vc<E>& v) {\n    build(len(v), [&](int i) -> E { return\
    \ v[i]; });\n  }\n  template <typename F>\n  void build(int m, F f) {\n    bit.build(m\
    \ + 1, [&](int i) -> pair<E, E> {\n      if (i == m) return {MX::id(), MX::id()};\n\
    \      return {f(i), MX::id()};\n    });\n  }\n\n  void add(int L, int R, E a)\
    \ {\n    E b = MX::inverse(a);\n    bit.add(L, {MX::power(b, L), a});\n    bit.add(R,\
    \ {MX::power(a, R), b});\n  }\n\n  E sum(int L, int R) {\n    auto [x0, x1] =\
    \ bit.sum(L);\n    auto [y0, y1] = bit.sum(R);\n    E x = MX::op(MX::power(x1,\
    \ L), x0);\n    E y = MX::op(MX::power(y1, R), y0);\n    return MX::op(MX::inverse(x),\
    \ y);\n  }\n};\n"
  dependsOn:
  - ds/fenwicktree/fenwicktree.hpp
  - other/bit.hpp
  - alg/monoid/add.hpp
  isVerificationFile: false
  path: ds/range_add_range_sum.hpp
  requiredBy: []
  timestamp: '2026-09-01 01:04:54+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/4_aoj/DSL_2_G.test.cpp
  - test/4_aoj/DSL_2_E.test.cpp
documentation_of: ds/range_add_range_sum.hpp
layout: document
redirect_from:
- /library/ds/range_add_range_sum.hpp
- /library/ds/range_add_range_sum.hpp.html
title: ds/range_add_range_sum.hpp
---
