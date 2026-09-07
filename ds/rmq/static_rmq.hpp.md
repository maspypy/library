---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: ds/sparse_table/sparse_table.hpp
    title: ds/sparse_table/sparse_table.hpp
  - icon: ':heavy_check_mark:'
    path: other/bit.hpp
    title: other/bit.hpp
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/2_library_checker/data_structure/staticrmq_x.test.cpp
    title: test/2_library_checker/data_structure/staticrmq_x.test.cpp
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
    \  x = (x << 32) | (x >> 32);\n  return x;\n}\n#line 1 \"other/bit.hpp\"\n\nint\
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
    \  x = (x << 32) | (x >> 32);\n  return x;\n}\n#line 2 \"ds/sparse_table/sparse_table.hpp\"\
    \n\n// \u51AA\u7B49\u306A\u30E2\u30CE\u30A4\u30C9\u3067\u3042\u308B\u3053\u3068\
    \u3092\u4EEE\u5B9A\u3002disjoint sparse table \u3088\u308A x \u500D\u9AD8\u901F\
    \ntemplate <class Monoid>\nstruct Sparse_Table {\n  using MX = Monoid;\n  using\
    \ X = typename MX::value_type;\n  int n, log;\n  vvc<X> dat;\n\n  Sparse_Table()\
    \ {}\n  Sparse_Table(int n) { build(n); }\n  template <typename F>\n  Sparse_Table(int\
    \ n, F f) {\n    build(n, f);\n  }\n  Sparse_Table(const vc<X>& v) { build(v);\
    \ }\n\n  void build(int m) {\n    build(m, [](int i) -> X { return MX::id(); });\n\
    \  }\n  void build(const vc<X>& v) {\n    build(len(v), [&](int i) -> X { return\
    \ v[i]; });\n  }\n  template <typename F>\n  void build(int m, F f) {\n    n =\
    \ m, log = 1;\n    while ((1 << log) < n) ++log;\n    dat.resize(log);\n    dat[0].resize(n);\n\
    \    FOR(i, n) dat[0][i] = f(i);\n\n    FOR(i, log - 1) {\n      dat[i + 1].resize(len(dat[i])\
    \ - (1 << i));\n      FOR(j, len(dat[i]) - (1 << i)) {\n        dat[i + 1][j]\
    \ = MX::op(dat[i][j], dat[i][j + (1 << i)]);\n      }\n    }\n  }\n\n  X prod(int\
    \ L, int R) const {\n    if (L == R) return MX::id();\n    if (R == L + 1) return\
    \ dat[0][L];\n    int k = topbit(R - L - 1);\n    return MX::op(dat[k][L], dat[k][R\
    \ - (1 << k)]);\n  }\n\n  template <class F>\n  int max_right(const F check, int\
    \ L) const {\n    assert(0 <= L && L <= n && check(MX::id()));\n    if (L == n)\
    \ return n;\n    int ok = L, ng = n + 1;\n    while (ok + 1 < ng) {\n      int\
    \ k = (ok + ng) / 2;\n      bool bl = check(prod(L, k));\n      if (bl) ok = k;\n\
    \      if (!bl) ng = k;\n    }\n    return ok;\n  }\n\n  template <class F>\n\
    \  int min_left(const F check, int R) const {\n    assert(0 <= R && R <= n &&\
    \ check(MX::id()));\n    if (R == 0) return 0;\n    int ok = R, ng = -1;\n   \
    \ while (ng + 1 < ok) {\n      int k = (ok + ng) / 2;\n      bool bl = check(prod(k,\
    \ R));\n      if (bl) ok = k;\n      if (!bl) ng = k;\n    }\n    return ok;\n\
    \  }\n};\n#line 3 \"ds/rmq/static_rmq.hpp\"\n\n// \u69CB\u7BC9 O(N), \u30AF\u30A8\
    \u30EA O(1)\n// static_range_product \u3088\u308A\u9045\u3044\u3063\u307D\u3044\
    \u306E\u3067\u4F7F\u3046\u3053\u3068\u306F\u306A\u3055\u305D\u3046\u3060\ntemplate\
    \ <typename Monoid>\nstruct Static_RMQ {\n  using MX = Monoid;\n  using X = typename\
    \ MX::value_type;\n  static constexpr int LOG = 4;\n  int N, b_num;\n  vc<X> A,\
    \ pre, suf;  // inclusive\n  Sparse_Table<Monoid> ST;\n\n  using u16 = unsigned\
    \ short;\n  vc<u16> dat;\n\n  Static_RMQ() {}\n  template <typename F>\n  Static_RMQ(int\
    \ n, F f) {\n    build(n, f);\n  }\n  Static_RMQ(const vc<X>& v) { build(v); }\n\
    \n  void build(const vc<X>& v) {\n    build(len(v), [&](int i) -> X { return v[i];\
    \ });\n  }\n  template <typename F>\n  void build(int m, F f) {\n    N = m;\n\
    \    b_num = N >> LOG;\n    A.resize(N);\n    FOR(i, N) A[i] = f(i);\n    pre\
    \ = A, suf = A;\n    FOR(i, 1, N) {\n      if (i & 15) pre[i] = MX::op(pre[i -\
    \ 1], A[i]);\n    }\n    FOR_R(i, 1, N) {\n      if (i & 15) suf[i - 1] = MX::op(A[i\
    \ - 1], suf[i]);\n    }\n    ST.build(b_num, [&](int i) -> X { return suf[i <<\
    \ LOG]; });\n    // \u9577\u3055 16 \u4EE5\u4E0B\u306E\u30AF\u30A8\u30EA\u306B\
    \u5BFE\u5FDC\u3059\u308B\u305F\u3081\u306E\u524D\u8A08\u7B97\n    // [i,i+16)\
    \ \u5185\u3067 i+j \u304C [i,i+j] \u3067\u306E\u6700\u5C0F\u5024\u3068\u306A\u308B\
    \u5834\u5408\u306B j-th bit \u3092\u7ACB\u3066\u308B\n    dat.resize(N);\n   \
    \ u32 stack = 0;\n    FOR_R(i, N) {\n      stack = (stack << 1) & 65535;\n   \
    \   while (stack) {\n        int k = lowbit(stack);\n        if (MX::op(A[i],\
    \ A[i + k]) != A[i]) break;\n        stack &= ~(u32(1) << k);\n      }\n     \
    \ stack |= u32(1);\n      dat[i] = stack;\n    }\n  }\n\n  X prod(int L, int R)\
    \ {\n    assert(0 <= L && L <= R && R <= N);\n    if (L == R) return MX::id();\n\
    \    if (R - L <= 16) {\n      u32 d = dat[L] & ((u32(1) << (R - L)) - 1);\n \
    \     return A[L + topbit(d)];\n    }\n    --R;\n    int a = L >> LOG, b = R >>\
    \ LOG;\n    X x = ST.prod(a + 1, b);\n    x = MX::op(suf[L], x);\n    x = MX::op(x,\
    \ pre[R]);\n    return x;\n  }\n};\n"
  code: "#include \"other/bit.hpp\"\n#include \"ds/sparse_table/sparse_table.hpp\"\
    \n\n// \u69CB\u7BC9 O(N), \u30AF\u30A8\u30EA O(1)\n// static_range_product \u3088\
    \u308A\u9045\u3044\u3063\u307D\u3044\u306E\u3067\u4F7F\u3046\u3053\u3068\u306F\
    \u306A\u3055\u305D\u3046\u3060\ntemplate <typename Monoid>\nstruct Static_RMQ\
    \ {\n  using MX = Monoid;\n  using X = typename MX::value_type;\n  static constexpr\
    \ int LOG = 4;\n  int N, b_num;\n  vc<X> A, pre, suf;  // inclusive\n  Sparse_Table<Monoid>\
    \ ST;\n\n  using u16 = unsigned short;\n  vc<u16> dat;\n\n  Static_RMQ() {}\n\
    \  template <typename F>\n  Static_RMQ(int n, F f) {\n    build(n, f);\n  }\n\
    \  Static_RMQ(const vc<X>& v) { build(v); }\n\n  void build(const vc<X>& v) {\n\
    \    build(len(v), [&](int i) -> X { return v[i]; });\n  }\n  template <typename\
    \ F>\n  void build(int m, F f) {\n    N = m;\n    b_num = N >> LOG;\n    A.resize(N);\n\
    \    FOR(i, N) A[i] = f(i);\n    pre = A, suf = A;\n    FOR(i, 1, N) {\n     \
    \ if (i & 15) pre[i] = MX::op(pre[i - 1], A[i]);\n    }\n    FOR_R(i, 1, N) {\n\
    \      if (i & 15) suf[i - 1] = MX::op(A[i - 1], suf[i]);\n    }\n    ST.build(b_num,\
    \ [&](int i) -> X { return suf[i << LOG]; });\n    // \u9577\u3055 16 \u4EE5\u4E0B\
    \u306E\u30AF\u30A8\u30EA\u306B\u5BFE\u5FDC\u3059\u308B\u305F\u3081\u306E\u524D\
    \u8A08\u7B97\n    // [i,i+16) \u5185\u3067 i+j \u304C [i,i+j] \u3067\u306E\u6700\
    \u5C0F\u5024\u3068\u306A\u308B\u5834\u5408\u306B j-th bit \u3092\u7ACB\u3066\u308B\
    \n    dat.resize(N);\n    u32 stack = 0;\n    FOR_R(i, N) {\n      stack = (stack\
    \ << 1) & 65535;\n      while (stack) {\n        int k = lowbit(stack);\n    \
    \    if (MX::op(A[i], A[i + k]) != A[i]) break;\n        stack &= ~(u32(1) <<\
    \ k);\n      }\n      stack |= u32(1);\n      dat[i] = stack;\n    }\n  }\n\n\
    \  X prod(int L, int R) {\n    assert(0 <= L && L <= R && R <= N);\n    if (L\
    \ == R) return MX::id();\n    if (R - L <= 16) {\n      u32 d = dat[L] & ((u32(1)\
    \ << (R - L)) - 1);\n      return A[L + topbit(d)];\n    }\n    --R;\n    int\
    \ a = L >> LOG, b = R >> LOG;\n    X x = ST.prod(a + 1, b);\n    x = MX::op(suf[L],\
    \ x);\n    x = MX::op(x, pre[R]);\n    return x;\n  }\n};\n"
  dependsOn:
  - other/bit.hpp
  - ds/sparse_table/sparse_table.hpp
  isVerificationFile: false
  path: ds/rmq/static_rmq.hpp
  requiredBy: []
  timestamp: '2026-08-30 21:09:36+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/2_library_checker/data_structure/staticrmq_x.test.cpp
documentation_of: ds/rmq/static_rmq.hpp
layout: document
redirect_from:
- /library/ds/rmq/static_rmq.hpp
- /library/ds/rmq/static_rmq.hpp.html
title: ds/rmq/static_rmq.hpp
---
