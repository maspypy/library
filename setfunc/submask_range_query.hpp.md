---
data:
  _extendedDependsOn:
  - icon: ':question:'
    path: alg/monoid/add.hpp
    title: alg/monoid/add.hpp
  - icon: ':heavy_check_mark:'
    path: alg/monoid/xor.hpp
    title: alg/monoid/xor.hpp
  - icon: ':heavy_check_mark:'
    path: enumerate/bits.hpp
    title: enumerate/bits.hpp
  - icon: ':question:'
    path: random/base.hpp
    title: random/base.hpp
  - icon: ':heavy_check_mark:'
    path: random/shuffle.hpp
    title: random/shuffle.hpp
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':warning:'
  attributes:
    links: []
  bundledCode: "#line 2 \"random/base.hpp\"\n\nu64 RNG_64() {\n  static u64 x_ = u64(chrono::duration_cast<chrono::nanoseconds>(chrono::high_resolution_clock::now().time_since_epoch()).count())\
    \ * 10150724397891781847ULL;\n  x_ ^= x_ << 7;\n  return x_ ^= x_ >> 9;\n}\n\n\
    u64 RNG(u64 lim) { return RNG_64() % lim; }\n\nll RNG(ll l, ll r) { return l +\
    \ RNG_64() % (r - l); }\n#line 2 \"random/shuffle.hpp\"\n\ntemplate <typename\
    \ T>\nvoid shuffle(vc<T>& A) {\n  FOR(i, len(A)) {\n    int j = RNG(0, i + 1);\n\
    \    if (i != j) swap(A[i], A[j]);\n  }\n}\n#line 2 \"alg/monoid/add.hpp\"\n\r\
    \ntemplate <typename E>\r\nstruct Monoid_Add {\r\n  using X = E;\r\n  using value_type\
    \ = X;\r\n  static constexpr X op(const X &x, const X &y) noexcept { return x\
    \ + y; }\r\n  static constexpr X inverse(const X &x) noexcept { return -x; }\r\
    \n  static constexpr X power(const X &x, ll n) noexcept { return X(n) * x; }\r\
    \n  static constexpr X unit() { return X(0); }\r\n  static constexpr bool commute\
    \ = true;\r\n};\r\n#line 2 \"alg/monoid/xor.hpp\"\n\r\ntemplate <typename X>\r\
    \nstruct Monoid_Xor {\r\n  using value_type = X;\r\n  static X op(X x, X y) {\
    \ return x ^ y; }\r\n  static constexpr X inverse(const X &x) noexcept { return\
    \ x; }\r\n  static constexpr X power(const X &x, ll n) noexcept {\r\n    return\
    \ (n & 1 ? x : 0);\r\n  }\r\n  static constexpr X unit(){return X(0);};\r\n  static\
    \ constexpr bool commute = true;\r\n};\r\n#line 1 \"enumerate/bits.hpp\"\ntemplate\
    \ <typename BS, typename F>\nvoid enumerate_bits_bitset(BS& b, int L, int R, F&&\
    \ f) {\n  if (L >= len(b)) return;\n  int p = (b[L] ? L : b._Find_next(L));\n\
    \  while (p < R) {\n    f(p);\n    p = b._Find_next(p);\n  }\n}\n\ntemplate <typename\
    \ UINT, typename F>\ninline void enumerate_all_bit(UINT s, F&& f) {\n  static_assert(is_unsigned<UINT>::value);\n\
    \  while (s) {\n    f(lowbit(s));\n    s &= s - 1;\n  }\n}\n\ntemplate <typename\
    \ UINT, bool inc_empty, typename F>\ninline void enumerate_all_subset(UINT s,\
    \ F&& f) {\n  static_assert(is_unsigned<UINT>::value);\n  for (UINT t = s; t;\
    \ t = (t - 1) & s) f(t);\n  if constexpr (inc_empty) f(0);\n}\n#line 5 \"setfunc/submask_range_query.hpp\"\
    \n\n// O((4/3)^LOG) per query\ntemplate <typename Monoid>\nstruct Boolean_Range_Add_Point_Get\
    \ {\n  using MX = Monoid;\n  using X = typename MX::value_type;\n\n  const int\
    \ LOG;\n  vc<X> S;\n  array<u32, 3> mask;\n\n  /*\n  0: [x0,x1]\n  1: [x0+x1,x0]\n\
    \  2: [x0+x1,x1]\n  */\n\n  Boolean_Range_Add_Point_Get(int LOG) : LOG(LOG), mask{}\
    \ {\n    S.assign(1 << LOG, MX::unit());\n    init_by_random();\n  }\n\n  void\
    \ init_by_random() {\n    mask[0] = mask[1] = mask[2] = 0;\n    FOR(i, LOG) {\
    \ mask[RNG(0, 3)] |= u32(1) << i; }\n  }\n\n  void init_by_query(const vc<pair<u32,\
    \ u32>>& ADD, const vc<u32>& GET) {\n    for (auto& [lo, hi] : ADD) assert((lo\
    \ & ~hi) == 0);\n    mask[0] = mask[1] = mask[2] = 0;\n\n    auto eval = [&]()\
    \ -> ll {\n      ll ans = 0;\n\n      for (auto& [lo, hi] : ADD) {\n        u32\
    \ s = 0;\n        s ^= (lo ^ hi) & mask[0];\n        s ^= lo & mask[1];\n    \
    \    s ^= (~hi) & mask[2];\n        ans += 1 << popcnt(s);\n      }\n\n      for\
    \ (u32 i : GET) {\n        u32 s = 0;\n        s ^= (~i) & mask[1];\n        s\
    \ ^= i & mask[2];\n        ans += 1 << popcnt(s);\n      }\n\n      return ans;\n\
    \    };\n\n    vc<int> I(LOG);\n    FOR(i, LOG) I[i] = i;\n    shuffle(I);\n\n\
    \    array<ll, 3> c;\n    for (int i : I) {\n      FOR(k, 3) {\n        mask[k]\
    \ |= u32(1) << i, c[k] = eval(), mask[k] &= ~(u32(1) << i);\n      }\n      int\
    \ k = min_element(all(c)) - c.begin();\n      mask[k] |= u32(1) << i;\n    }\n\
    \  }\n\n  void add(u32 lo, u32 hi, X x) {\n    assert((lo & ~hi) == 0);\n\n  \
    \  u32 a = 0;\n    u32 s = 0;\n    u32 b = 0;\n\n    a ^= lo & mask[0];\n    s\
    \ ^= (lo ^ hi) & mask[0];\n\n    a ^= (~hi) & mask[1];\n    s ^= lo & mask[1];\n\
    \    b ^= lo & mask[1];\n\n    a ^= lo & mask[2];\n    s ^= (~hi) & mask[2];\n\
    \    b ^= (~hi) & mask[2];\n\n    enumerate_all_subset<u32, true>(s, [&](u32 t)\
    \ -> void {\n      X y = (__builtin_parity(t & b) ? MX::inverse(x) : x);\n   \
    \   S[a | t] = MX::op(S[a | t], y);\n    });\n  }\n\n  X get(u32 i) {\n    u32\
    \ a = i & mask[0];\n    u32 s = 0;\n\n    s ^= (~i) & mask[1];\n    s ^= i & mask[2];\n\
    \n    X ANS = MX::unit();\n    enumerate_all_subset<u32, true>(\n        s, [&](u32\
    \ t) -> void { ANS = MX::op(ANS, S[a | t]); });\n    return ANS;\n  }\n};\n"
  code: "#include \"random/shuffle.hpp\"\n#include \"alg/monoid/add.hpp\"\n#include\
    \ \"alg/monoid/xor.hpp\"\n#include \"enumerate/bits.hpp\"\n\n// O((4/3)^LOG) per\
    \ query\ntemplate <typename Monoid>\nstruct Boolean_Range_Add_Point_Get {\n  using\
    \ MX = Monoid;\n  using X = typename MX::value_type;\n\n  const int LOG;\n  vc<X>\
    \ S;\n  array<u32, 3> mask;\n\n  /*\n  0: [x0,x1]\n  1: [x0+x1,x0]\n  2: [x0+x1,x1]\n\
    \  */\n\n  Boolean_Range_Add_Point_Get(int LOG) : LOG(LOG), mask{} {\n    S.assign(1\
    \ << LOG, MX::unit());\n    init_by_random();\n  }\n\n  void init_by_random()\
    \ {\n    mask[0] = mask[1] = mask[2] = 0;\n    FOR(i, LOG) { mask[RNG(0, 3)] |=\
    \ u32(1) << i; }\n  }\n\n  void init_by_query(const vc<pair<u32, u32>>& ADD, const\
    \ vc<u32>& GET) {\n    for (auto& [lo, hi] : ADD) assert((lo & ~hi) == 0);\n \
    \   mask[0] = mask[1] = mask[2] = 0;\n\n    auto eval = [&]() -> ll {\n      ll\
    \ ans = 0;\n\n      for (auto& [lo, hi] : ADD) {\n        u32 s = 0;\n       \
    \ s ^= (lo ^ hi) & mask[0];\n        s ^= lo & mask[1];\n        s ^= (~hi) &\
    \ mask[2];\n        ans += 1 << popcnt(s);\n      }\n\n      for (u32 i : GET)\
    \ {\n        u32 s = 0;\n        s ^= (~i) & mask[1];\n        s ^= i & mask[2];\n\
    \        ans += 1 << popcnt(s);\n      }\n\n      return ans;\n    };\n\n    vc<int>\
    \ I(LOG);\n    FOR(i, LOG) I[i] = i;\n    shuffle(I);\n\n    array<ll, 3> c;\n\
    \    for (int i : I) {\n      FOR(k, 3) {\n        mask[k] |= u32(1) << i, c[k]\
    \ = eval(), mask[k] &= ~(u32(1) << i);\n      }\n      int k = min_element(all(c))\
    \ - c.begin();\n      mask[k] |= u32(1) << i;\n    }\n  }\n\n  void add(u32 lo,\
    \ u32 hi, X x) {\n    assert((lo & ~hi) == 0);\n\n    u32 a = 0;\n    u32 s =\
    \ 0;\n    u32 b = 0;\n\n    a ^= lo & mask[0];\n    s ^= (lo ^ hi) & mask[0];\n\
    \n    a ^= (~hi) & mask[1];\n    s ^= lo & mask[1];\n    b ^= lo & mask[1];\n\n\
    \    a ^= lo & mask[2];\n    s ^= (~hi) & mask[2];\n    b ^= (~hi) & mask[2];\n\
    \n    enumerate_all_subset<u32, true>(s, [&](u32 t) -> void {\n      X y = (__builtin_parity(t\
    \ & b) ? MX::inverse(x) : x);\n      S[a | t] = MX::op(S[a | t], y);\n    });\n\
    \  }\n\n  X get(u32 i) {\n    u32 a = i & mask[0];\n    u32 s = 0;\n\n    s ^=\
    \ (~i) & mask[1];\n    s ^= i & mask[2];\n\n    X ANS = MX::unit();\n    enumerate_all_subset<u32,\
    \ true>(\n        s, [&](u32 t) -> void { ANS = MX::op(ANS, S[a | t]); });\n \
    \   return ANS;\n  }\n};"
  dependsOn:
  - random/shuffle.hpp
  - random/base.hpp
  - alg/monoid/add.hpp
  - alg/monoid/xor.hpp
  - enumerate/bits.hpp
  isVerificationFile: false
  path: setfunc/submask_range_query.hpp
  requiredBy: []
  timestamp: '2026-05-06 04:02:27+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: setfunc/submask_range_query.hpp
layout: document
redirect_from:
- /library/setfunc/submask_range_query.hpp
- /library/setfunc/submask_range_query.hpp.html
title: setfunc/submask_range_query.hpp
---
