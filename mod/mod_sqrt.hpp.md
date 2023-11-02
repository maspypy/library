---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: mod/barrett.hpp
    title: mod/barrett.hpp
  - icon: ':heavy_check_mark:'
    path: mod/mod_pow.hpp
    title: mod/mod_pow.hpp
  - icon: ':heavy_check_mark:'
    path: mod/mongomery_modint.hpp
    title: mod/mongomery_modint.hpp
  - icon: ':heavy_check_mark:'
    path: random/base.hpp
    title: random/base.hpp
  _extendedRequiredBy:
  - icon: ':heavy_check_mark:'
    path: graph/count/count_bipartite.hpp
    title: graph/count/count_bipartite.hpp
  - icon: ':heavy_check_mark:'
    path: poly/fps_sqrt.hpp
    title: poly/fps_sqrt.hpp
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/library_checker/math/sqrt_mod.test.cpp
    title: test/library_checker/math/sqrt_mod.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/library_checker/polynomial/sqrt_of_fps.test.cpp
    title: test/library_checker/polynomial/sqrt_of_fps.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/library_checker/polynomial/sqrt_of_fps_sparse.test.cpp
    title: test/library_checker/polynomial/sqrt_of_fps_sparse.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/mytest/count_bipartite.test.cpp
    title: test/mytest/count_bipartite.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 2 \"random/base.hpp\"\n\nu64 RNG_64() {\n  static uint64_t x_\n\
    \      = uint64_t(chrono::duration_cast<chrono::nanoseconds>(\n              \
    \       chrono::high_resolution_clock::now().time_since_epoch())\n           \
    \          .count())\n        * 10150724397891781847ULL;\n  x_ ^= x_ << 7;\n \
    \ return x_ ^= x_ >> 9;\n}\n\nu64 RNG(u64 lim) { return RNG_64() % lim; }\n\n\
    ll RNG(ll l, ll r) { return l + RNG_64() % (r - l); }\n#line 2 \"mod/mod_pow.hpp\"\
    \n\r\n#line 2 \"mod/mongomery_modint.hpp\"\n\n// odd mod.\n// x \u306E\u4EE3\u308F\
    \u308A\u306B rx \u3092\u6301\u3064\ntemplate <int id, typename U1, typename U2>\n\
    struct Mongomery_modint {\n  using mint = Mongomery_modint;\n  inline static U1\
    \ m, r, n2;\n  static constexpr int W = numeric_limits<U1>::digits;\n\n  static\
    \ void set_mod(U1 mod) {\n    assert(mod & 1 && mod <= U1(1) << (W - 2));\n  \
    \  m = mod, n2 = -U2(m) % m, r = m;\n    FOR(5) r *= 2 - m * r;\n    r = -r;\n\
    \    assert(r * m == U1(-1));\n  }\n  static U1 reduce(U2 b) { return (b + U2(U1(b)\
    \ * r) * m) >> W; }\n\n  U1 x;\n  Mongomery_modint() : x(0) {}\n  Mongomery_modint(U1\
    \ x) : x(reduce(U2(x) * n2)){};\n  U1 val() const {\n    U1 y = reduce(x);\n \
    \   return y >= m ? y - m : y;\n  }\n  mint &operator+=(mint y) {\n    x = ((x\
    \ += y.x) >= m ? x - m : x);\n    return *this;\n  }\n  mint &operator-=(mint\
    \ y) {\n    x -= (x >= y.x ? y.x : y.x - m);\n    return *this;\n  }\n  mint &operator*=(mint\
    \ y) {\n    x = reduce(U2(x) * y.x);\n    return *this;\n  }\n  mint operator+(mint\
    \ y) const { return mint(*this) += y; }\n  mint operator-(mint y) const { return\
    \ mint(*this) -= y; }\n  mint operator*(mint y) const { return mint(*this) *=\
    \ y; }\n  bool operator==(mint y) const {\n    return (x >= m ? x - m : x) ==\
    \ (y.x >= m ? y.x - m : y.x);\n  }\n  bool operator!=(mint y) const { return not\
    \ operator==(y); }\n  mint pow(ll n) const {\n    assert(n >= 0);\n    mint y\
    \ = 1, z = *this;\n    for (; n; n >>= 1, z *= z)\n      if (n & 1) y *= z;\n\
    \    return y;\n  }\n};\n\ntemplate <int id>\nusing Mongomery_modint_32 = Mongomery_modint<id,\
    \ u32, u64>;\ntemplate <int id>\nusing Mongomery_modint_64 = Mongomery_modint<id,\
    \ u64, u128>;\n#line 2 \"mod/barrett.hpp\"\n\n// https://github.com/atcoder/ac-library/blob/master/atcoder/internal_math.hpp\n\
    struct Barrett {\n  u32 m;\n  u64 im;\n  explicit Barrett(u32 m = 1) : m(m), im(u64(-1)\
    \ / m + 1) {}\n  u32 umod() const { return m; }\n  u32 modulo(u64 z) {\n    if\
    \ (m == 1) return 0;\n    u64 x = (u64)(((unsigned __int128)(z)*im) >> 64);\n\
    \    u64 y = x * m;\n    return (z - y + (z < y ? m : 0));\n  }\n  u64 floor(u64\
    \ z) {\n    if (m == 1) return z;\n    u64 x = (u64)(((unsigned __int128)(z)*im)\
    \ >> 64);\n    u64 y = x * m;\n    return (z < y ? x - 1 : x);\n  }\n  pair<u64,\
    \ u32> divmod(u64 z) {\n    if (m == 1) return {z, 0};\n    u64 x = (u64)(((unsigned\
    \ __int128)(z)*im) >> 64);\n    u64 y = x * m;\n    if (z < y) return {x - 1,\
    \ z - y + m};\n    return {x, z - y};\n  }\n  u32 mul(u32 a, u32 b) { return modulo(u64(a)\
    \ * b); }\n};\n\nstruct Barrett_64 {\n  u128 mod, mh, ml;\n\n  explicit Barrett_64(u64\
    \ mod = 1) : mod(mod) {\n    u128 m = u128(-1) / mod;\n    if (m * mod + mod ==\
    \ u128(0)) ++m;\n    mh = m >> 64;\n    ml = m & u64(-1);\n  }\n\n  u64 umod()\
    \ const { return mod; }\n\n  u64 modulo(u128 x) {\n    u128 z = (x & u64(-1))\
    \ * ml;\n    z = (x & u64(-1)) * mh + (x >> 64) * ml + (z >> 64);\n    z = (x\
    \ >> 64) * mh + (z >> 64);\n    x -= z * mod;\n    return x < mod ? x : x - mod;\n\
    \  }\n\n  u64 mul(u64 a, u64 b) { return modulo(u128(a) * b); }\n};\n#line 5 \"\
    mod/mod_pow.hpp\"\n\r\nu32 mod_pow(int a, ll n, int mod) {\r\n  assert(n >= 0);\r\
    \n  a = ((a %= mod) < 0 ? a + mod : a);\r\n  if ((mod & 1) && (mod < (1 << 30)))\
    \ {\r\n    using mint = Mongomery_modint_32<202311021>;\r\n    mint::set_mod(mod);\r\
    \n    return mint(a).pow(n).val();\r\n  }\r\n  Barrett bt(mod);\r\n  int r = 1;\r\
    \n  while (n) {\r\n    if (n & 1) r = bt.mul(r, a);\r\n    a = bt.mul(a, a), n\
    \ >>= 1;\r\n  }\r\n  return r;\r\n}\r\n\r\nu64 mod_pow_64(ll a, ll n, u64 mod)\
    \ {\r\n  assert(n >= 0);\r\n  a = ((a %= mod) < 0 ? a + mod : a);\r\n  if ((mod\
    \ & 1) && (mod < (u64(1) << 62))) {\r\n    using mint = Mongomery_modint_64<202311021>;\r\
    \n    mint::set_mod(mod);\r\n    return mint(a).pow(n).val();\r\n  }\r\n  Barrett_64\
    \ bt(mod);\r\n  ll r = 1;\r\n  while (n) {\r\n    if (n & 1) r = bt.mul(r, a);\r\
    \n    a = bt.mul(a, a), n >>= 1;\r\n  }\r\n  return r;\r\n}\n#line 3 \"mod/mod_sqrt.hpp\"\
    \n\r\n// p \u306F\u7D20\u6570. \u89E3\u306A\u3057\u306F -1.\r\nint mod_sqrt(int\
    \ a, int p) {\r\n  if (p == 2) return a;\r\n  if (a == 0) return 0;\r\n  int k\
    \ = (p - 1) / 2;\r\n  if (mod_pow(a, k, p) != 1) return -1;\r\n  auto find = [&]()\
    \ -> pi {\r\n    while (1) {\r\n      ll b = RNG(2, p);\r\n      ll D = (b * b\
    \ - a) % p;\r\n      if (D == 0) return {b, D};\r\n      if (mod_pow(D, k, p)\
    \ != 1) return {b, D};\r\n    }\r\n  };\r\n  auto [b, D] = find();\r\n  if (D\
    \ == 0) return b;\r\n  ++k;\r\n  // (b + sqrt(D))^k\r\n  ll f0 = b, f1 = 1, g0\
    \ = 1, g1 = 0;\r\n  while (k) {\r\n    if (k & 1) {\r\n      tie(g0, g1) = mp(f0\
    \ * g0 + D * f1 % p * g1, f1 * g0 + f0 * g1);\r\n      g0 %= p, g1 %= p;\r\n \
    \   }\r\n    tie(f0, f1) = mp(f0 * f0 + D * f1 % p * f1, 2 * f0 * f1);\r\n   \
    \ f0 %= p, f1 %= p;\r\n    k >>= 1;\r\n  }\r\n  if (g0 < 0) g0 += p;\r\n  return\
    \ g0;\r\n}\r\n\r\n// p \u306F\u7D20\u6570. \u89E3\u306A\u3057\u306F -1.\r\nll\
    \ mod_sqrt_64(ll a, ll p) {\r\n  if (p == 2) return a;\r\n  if (a == 0) return\
    \ 0;\r\n  ll k = (p - 1) / 2;\r\n  if (mod_pow_64(a, k, p) != 1) return -1;\r\n\
    \  auto find = [&]() -> pair<i128, i128> {\r\n    while (1) {\r\n      i128 b\
    \ = RNG(2, p);\r\n      i128 D = b * b - a;\r\n      if (D == 0) return {b, D};\r\
    \n      if (mod_pow_64(D, k, p) != 1) return {b, D};\r\n    }\r\n  };\r\n  auto\
    \ [b, D] = find();\r\n  if (D == 0) return b;\r\n  ++k;\r\n  // (b + sqrt(D))^k\r\
    \n  i128 f0 = b, f1 = 1, g0 = 1, g1 = 0;\r\n  while (k) {\r\n    if (k & 1) {\r\
    \n      tie(g0, g1) = mp(f0 * g0 + D * f1 % p * g1, f1 * g0 + f0 * g1);\r\n  \
    \    g0 %= p, g1 %= p;\r\n    }\r\n    tie(f0, f1) = mp(f0 * f0 + D * f1 % p *\
    \ f1, 2 * f0 * f1);\r\n    f0 %= p, f1 %= p;\r\n    k >>= 1;\r\n  }\r\n  return\
    \ g0;\r\n}\r\n"
  code: "#include \"random/base.hpp\"\r\n#include \"mod/mod_pow.hpp\"\r\n\r\n// p\
    \ \u306F\u7D20\u6570. \u89E3\u306A\u3057\u306F -1.\r\nint mod_sqrt(int a, int\
    \ p) {\r\n  if (p == 2) return a;\r\n  if (a == 0) return 0;\r\n  int k = (p -\
    \ 1) / 2;\r\n  if (mod_pow(a, k, p) != 1) return -1;\r\n  auto find = [&]() ->\
    \ pi {\r\n    while (1) {\r\n      ll b = RNG(2, p);\r\n      ll D = (b * b -\
    \ a) % p;\r\n      if (D == 0) return {b, D};\r\n      if (mod_pow(D, k, p) !=\
    \ 1) return {b, D};\r\n    }\r\n  };\r\n  auto [b, D] = find();\r\n  if (D ==\
    \ 0) return b;\r\n  ++k;\r\n  // (b + sqrt(D))^k\r\n  ll f0 = b, f1 = 1, g0 =\
    \ 1, g1 = 0;\r\n  while (k) {\r\n    if (k & 1) {\r\n      tie(g0, g1) = mp(f0\
    \ * g0 + D * f1 % p * g1, f1 * g0 + f0 * g1);\r\n      g0 %= p, g1 %= p;\r\n \
    \   }\r\n    tie(f0, f1) = mp(f0 * f0 + D * f1 % p * f1, 2 * f0 * f1);\r\n   \
    \ f0 %= p, f1 %= p;\r\n    k >>= 1;\r\n  }\r\n  if (g0 < 0) g0 += p;\r\n  return\
    \ g0;\r\n}\r\n\r\n// p \u306F\u7D20\u6570. \u89E3\u306A\u3057\u306F -1.\r\nll\
    \ mod_sqrt_64(ll a, ll p) {\r\n  if (p == 2) return a;\r\n  if (a == 0) return\
    \ 0;\r\n  ll k = (p - 1) / 2;\r\n  if (mod_pow_64(a, k, p) != 1) return -1;\r\n\
    \  auto find = [&]() -> pair<i128, i128> {\r\n    while (1) {\r\n      i128 b\
    \ = RNG(2, p);\r\n      i128 D = b * b - a;\r\n      if (D == 0) return {b, D};\r\
    \n      if (mod_pow_64(D, k, p) != 1) return {b, D};\r\n    }\r\n  };\r\n  auto\
    \ [b, D] = find();\r\n  if (D == 0) return b;\r\n  ++k;\r\n  // (b + sqrt(D))^k\r\
    \n  i128 f0 = b, f1 = 1, g0 = 1, g1 = 0;\r\n  while (k) {\r\n    if (k & 1) {\r\
    \n      tie(g0, g1) = mp(f0 * g0 + D * f1 % p * g1, f1 * g0 + f0 * g1);\r\n  \
    \    g0 %= p, g1 %= p;\r\n    }\r\n    tie(f0, f1) = mp(f0 * f0 + D * f1 % p *\
    \ f1, 2 * f0 * f1);\r\n    f0 %= p, f1 %= p;\r\n    k >>= 1;\r\n  }\r\n  return\
    \ g0;\r\n}\r\n"
  dependsOn:
  - random/base.hpp
  - mod/mod_pow.hpp
  - mod/mongomery_modint.hpp
  - mod/barrett.hpp
  isVerificationFile: false
  path: mod/mod_sqrt.hpp
  requiredBy:
  - poly/fps_sqrt.hpp
  - graph/count/count_bipartite.hpp
  timestamp: '2023-11-02 05:38:57+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/mytest/count_bipartite.test.cpp
  - test/library_checker/math/sqrt_mod.test.cpp
  - test/library_checker/polynomial/sqrt_of_fps_sparse.test.cpp
  - test/library_checker/polynomial/sqrt_of_fps.test.cpp
documentation_of: mod/mod_sqrt.hpp
layout: document
redirect_from:
- /library/mod/mod_sqrt.hpp
- /library/mod/mod_sqrt.hpp.html
title: mod/mod_sqrt.hpp
---
