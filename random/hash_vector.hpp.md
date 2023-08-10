---
data:
  _extendedDependsOn:
  - icon: ':question:'
    path: mod/modint61.hpp
    title: mod/modint61.hpp
  - icon: ':question:'
    path: random/base.hpp
    title: random/base.hpp
  _extendedRequiredBy:
  - icon: ':x:'
    path: other/connected_dp.hpp
    title: other/connected_dp.hpp
  _extendedVerifiedWith:
  - icon: ':x:'
    path: test/mytest/tdpc_grid_dp.test.cpp
    title: test/mytest/tdpc_grid_dp.test.cpp
  - icon: ':x:'
    path: test/yukicoder/1397.test.cpp
    title: test/yukicoder/1397.test.cpp
  - icon: ':x:'
    path: test/yukicoder/1561.test.cpp
    title: test/yukicoder/1561.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/yukicoder/1881.test.cpp
    title: test/yukicoder/1881.test.cpp
  - icon: ':x:'
    path: test/yukicoder/541.test.cpp
    title: test/yukicoder/541.test.cpp
  - icon: ':x:'
    path: test/yukicoder/578.test.cpp
    title: test/yukicoder/578.test.cpp
  - icon: ':x:'
    path: test/yukicoder/579.test.cpp
    title: test/yukicoder/579.test.cpp
  _isVerificationFailed: true
  _pathExtension: hpp
  _verificationStatusIcon: ':question:'
  attributes:
    links: []
  bundledCode: "#line 2 \"random/hash_vector.hpp\"\n\n#line 2 \"random/base.hpp\"\n\
    \nu64 RNG_64() {\n  static uint64_t x_\n      = uint64_t(chrono::duration_cast<chrono::nanoseconds>(\n\
    \                     chrono::high_resolution_clock::now().time_since_epoch())\n\
    \                     .count())\n        * 10150724397891781847ULL;\n  x_ ^= x_\
    \ << 7;\n  return x_ ^= x_ >> 9;\n}\n\nu64 RNG(u64 lim) { return RNG_64() % lim;\
    \ }\n\nll RNG(ll l, ll r) { return l + RNG_64() % (r - l); }\n#line 2 \"mod/modint61.hpp\"\
    \n\r\n// https : // yosupo.hatenablog.com/entry/2023/08/06/181942\r\n// x \u306E\
    \u4EE3\u308F\u308A\u306B 8x \u3092 [8, 8MOD] \u3067\u6301\u3064\r\nstruct modint61\
    \ {\r\n  static constexpr u64 MOD = (1ULL << 61) - 1;\r\n  static constexpr u64\
    \ MOD8 = MOD * 8;\r\n  u64 x8;\r\n  constexpr modint61() : x8(MOD8) {}\r\n  constexpr\
    \ modint61(u32 x) : x8((x + MOD - 1) % MOD * 8 + 8) {}\r\n  constexpr modint61(u64\
    \ x) : x8((x + MOD - 1) % MOD * 8 + 8) {}\r\n  constexpr modint61(int x) : x8((x\
    \ + MOD - 1) % MOD * 8 + 8) {}\r\n  constexpr modint61(ll x)\r\n      : x8(8 *\
    \ (((x %= ll(MOD)) <= 0) ? (x + ll(MOD)) : x)) {}\r\n\r\n  static constexpr u64\
    \ get_mod() { return MOD; }\r\n  modint61 &operator+=(const modint61 &a) {\r\n\
    \    if (__builtin_uaddll_overflow(x8, a.x8, &x8)) x8 -= MOD8;\r\n    return *this;\r\
    \n  }\r\n  modint61 &operator-=(const modint61 &a) {\r\n    if (__builtin_uaddll_overflow(x8,\
    \ MOD8 - a.x8, &x8)) x8 -= MOD8;\r\n    return *this;\r\n  }\r\n  modint61 &operator*=(const\
    \ modint61 &a) {\r\n    u128 c = u128(x8) * (a.x8);\r\n    u64 x = c >> 67 <<\
    \ 3, y = c << 61 >> 64;\r\n    if (__builtin_uaddll_overflow(x, y, &x8)) x8 -=\
    \ MOD8;\r\n    return *this;\r\n  }\r\n  modint61 &operator/=(const modint61 &a)\
    \ { return (*this *= a.inverse()); }\r\n  modint61 operator+(const modint61 &p)\
    \ const { return modint61(*this) += p; }\r\n  modint61 operator-(const modint61\
    \ &p) const { return modint61(*this) -= p; }\r\n  modint61 operator*(const modint61\
    \ &p) const { return modint61(*this) *= p; }\r\n  modint61 operator/(const modint61\
    \ &p) const { return modint61(*this) /= p; }\r\n  bool operator==(const modint61\
    \ &p) const { return x8 == p.x8; }\r\n  bool operator!=(const modint61 &p) const\
    \ { return x8 != p.x8; }\r\n  u64 val() const { return (x8 == MOD8 ? 0 : x8 >>\
    \ 3); }\r\n  modint61 inverse() const {\r\n    ll a = val(), b = MOD, u = 1, v\
    \ = 0, t;\r\n    while (b > 0) {\r\n      t = a / b;\r\n      swap(a -= t * b,\
    \ b), swap(u -= t * v, v);\r\n    }\r\n    return modint61(u);\r\n  }\r\n  modint61\
    \ pow(ll n) const {\r\n    assert(n >= 0);\r\n    modint61 ret(1);\r\n    modint61\
    \ mul = (*this);\r\n    while (n > 0) {\r\n      if (n & 1) ret *= mul;\r\n  \
    \    mul *= mul, n >>= 1;\r\n    }\r\n    return ret;\r\n  }\r\n\r\n#ifdef FASTIO\r\
    \n  void write() { fastio::printer.write(val()); }\r\n  void read() {\r\n    ll\
    \ x;\r\n    fastio::scanner.read(x);\r\n    x8 = 8 * (((x %= ll(MOD)) <= 0) ?\
    \ (x + ll(MOD)) : x);\r\n  }\r\n#endif\r\n};\n#line 5 \"random/hash_vector.hpp\"\
    \n\ntemplate <typename T>\nu64 hash_vector(vc<T> X) {\n  using mint = modint61;\n\
    \  static vc<mint> hash_base;\n  int n = len(X);\n  while (len(hash_base) <= n)\
    \ { hash_base.eb(RNG(mint::get_mod())); }\n  mint H = 0;\n  FOR(i, n) H += hash_base[i]\
    \ * mint(X[i]);\n  H += hash_base[n];\n  return H.x8;\n}\n"
  code: "#pragma once\n\n#include \"random/base.hpp\"\n#include \"mod/modint61.hpp\"\
    \n\ntemplate <typename T>\nu64 hash_vector(vc<T> X) {\n  using mint = modint61;\n\
    \  static vc<mint> hash_base;\n  int n = len(X);\n  while (len(hash_base) <= n)\
    \ { hash_base.eb(RNG(mint::get_mod())); }\n  mint H = 0;\n  FOR(i, n) H += hash_base[i]\
    \ * mint(X[i]);\n  H += hash_base[n];\n  return H.x8;\n}"
  dependsOn:
  - random/base.hpp
  - mod/modint61.hpp
  isVerificationFile: false
  path: random/hash_vector.hpp
  requiredBy:
  - other/connected_dp.hpp
  timestamp: '2023-08-08 01:44:15+09:00'
  verificationStatus: LIBRARY_SOME_WA
  verifiedWith:
  - test/mytest/tdpc_grid_dp.test.cpp
  - test/yukicoder/1881.test.cpp
  - test/yukicoder/1397.test.cpp
  - test/yukicoder/1561.test.cpp
  - test/yukicoder/579.test.cpp
  - test/yukicoder/541.test.cpp
  - test/yukicoder/578.test.cpp
documentation_of: random/hash_vector.hpp
layout: document
redirect_from:
- /library/random/hash_vector.hpp
- /library/random/hash_vector.hpp.html
title: random/hash_vector.hpp
---
