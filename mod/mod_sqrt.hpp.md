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
    path: random/base.hpp
    title: random/base.hpp
  _extendedRequiredBy:
  - icon: ':heavy_check_mark:'
    path: graph/count/count_bipartite.hpp
    title: graph/count/count_bipartite.hpp
  - icon: ':heavy_check_mark:'
    path: nt/four_square.hpp
    title: nt/four_square.hpp
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
  - icon: ':heavy_check_mark:'
    path: test/mytest/four_square.test.cpp
    title: test/mytest/four_square.test.cpp
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
    ll RNG(ll l, ll r) { return l + RNG_64() % (r - l); }\n#line 2 \"mod/barrett.hpp\"\
    \n\n// https://github.com/atcoder/ac-library/blob/master/atcoder/internal_math.hpp\n\
    struct Barrett {\n  u32 m;\n  u64 im;\n  explicit Barrett(u32 m = 1) : m(m), im(u64(-1)\
    \ / m + 1) {}\n  u32 umod() const { return m; }\n  u32 modulo(u64 z) {\n    if\
    \ (m == 1) return 0;\n    u64 x = (u64)(((unsigned __int128)(z)*im) >> 64);\n\
    \    u64 y = x * m;\n    return (z - y + (z < y ? m : 0));\n  }\n  u64 floor(u64\
    \ z) {\n    if (m == 1) return z;\n    u64 x = (u64)(((unsigned __int128)(z)*im)\
    \ >> 64);\n    u64 y = x * m;\n    return (z < y ? x - 1 : x);\n  }\n  pair<u64,\
    \ u32> divmod(u64 z) {\n    if (m == 1) return {z, 0};\n    u64 x = (u64)(((unsigned\
    \ __int128)(z)*im) >> 64);\n    u64 y = x * m;\n    if (z < y) return {x - 1,\
    \ z - y + m};\n    return {x, z - y};\n  }\n  u32 mul(u32 a, u32 b) { return modulo(u64(a)\
    \ * b); }\n};\n#line 3 \"mod/mod_pow.hpp\"\n\r\nll mod_pow(ll a, ll n, int mod)\
    \ {\r\n  assert(n >= 0);\r\n  a %= mod;\r\n  if (a < 0) a += mod;\r\n  Barrett\
    \ bt(mod);\r\n  ll p = a, v = bt.modulo(1);\r\n  while (n) {\r\n    if (n & 1)\
    \ v = bt.mul(v, p);\r\n    p = bt.mul(p, p);\r\n    n >>= 1;\r\n  }\r\n  return\
    \ v;\r\n}\r\n\r\nll mod_pow_64(ll a, ll n, ll mod) {\r\n  assert(n >= 0);\r\n\
    \  a %= mod;\r\n  if (a < 0) a += mod;\r\n  ll p = a, v = 1 % mod;\r\n  while\
    \ (n) {\r\n    if (n & 1) v = i128(v) * p % mod;\r\n    p = i128(p) * p % mod;\r\
    \n    n >>= 1;\r\n  }\r\n  return v;\r\n}\r\n#line 3 \"mod/mod_sqrt.hpp\"\n\r\n\
    // p \u306F\u7D20\u6570. \u89E3\u306A\u3057\u306F -1.\r\nint mod_sqrt(int a, int\
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
  - mod/barrett.hpp
  isVerificationFile: false
  path: mod/mod_sqrt.hpp
  requiredBy:
  - nt/four_square.hpp
  - graph/count/count_bipartite.hpp
  - poly/fps_sqrt.hpp
  timestamp: '2023-10-14 15:49:24+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/library_checker/math/sqrt_mod.test.cpp
  - test/library_checker/polynomial/sqrt_of_fps.test.cpp
  - test/library_checker/polynomial/sqrt_of_fps_sparse.test.cpp
  - test/mytest/count_bipartite.test.cpp
  - test/mytest/four_square.test.cpp
documentation_of: mod/mod_sqrt.hpp
layout: document
redirect_from:
- /library/mod/mod_sqrt.hpp
- /library/mod/mod_sqrt.hpp.html
title: mod/mod_sqrt.hpp
---
