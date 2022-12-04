---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: mod/modint61.hpp
    title: mod/modint61.hpp
  - icon: ':question:'
    path: random/base.hpp
    title: random/base.hpp
  _extendedRequiredBy:
  - icon: ':heavy_check_mark:'
    path: other/connected_dp.hpp
    title: other/connected_dp.hpp
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/mytest/tdpc_grid_dp.test.cpp
    title: test/mytest/tdpc_grid_dp.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/yukicoder/1561.test.cpp
    title: test/yukicoder/1561.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/yukicoder/1881.test.cpp
    title: test/yukicoder/1881.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/yukicoder/541.test.cpp
    title: test/yukicoder/541.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/yukicoder/578.test.cpp
    title: test/yukicoder/578.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/yukicoder/579.test.cpp
    title: test/yukicoder/579.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 2 \"random/hash_vector.hpp\"\n\n#line 2 \"random/base.hpp\"\n\
    \nu64 RNG_64() {\n  static uint64_t x_\n      = uint64_t(chrono::duration_cast<chrono::nanoseconds>(\n\
    \                     chrono::high_resolution_clock::now().time_since_epoch())\n\
    \                     .count())\n        * 10150724397891781847ULL;\n  x_ ^= x_\
    \ << 7;\n  return x_ ^= x_ >> 9;\n}\n\nu64 RNG(u64 lim) { return RNG_64() % lim;\
    \ }\n\nll RNG(ll l, ll r) { return l + RNG_64() % (r - l); }\n#line 2 \"mod/modint61.hpp\"\
    \nstruct modint61 {\r\n  static constexpr bool is_modint = true;\r\n  static constexpr\
    \ ll mod = (1LL << 61) - 1;\r\n  ll val;\r\n  constexpr modint61(const ll x =\
    \ 0) : val(x) {\r\n    while(val < 0) val += mod;\r\n    while(val >= mod) val\
    \ -= mod;\r\n  }\r\n  bool operator<(const modint61 &other) const {\r\n    return\
    \ val < other.val;\r\n  } // To use std::map\r\n  bool operator==(const modint61\
    \ &p) const { return val == p.val; }\r\n  bool operator!=(const modint61 &p) const\
    \ { return val != p.val; }\r\n  modint61 &operator+=(const modint61 &p) {\r\n\
    \    if ((val += p.val) >= mod) val -= mod;\r\n    return *this;\r\n  }\r\n  modint61\
    \ &operator-=(const modint61 &p) {\r\n    if ((val += mod - p.val) >= mod) val\
    \ -= mod;\r\n    return *this;\r\n  }\r\n  modint61 &operator*=(const modint61\
    \ &p) {\r\n    ll a = val, b = p.val;\r\n    const ll MASK30 = (1LL << 30) - 1;\r\
    \n    const ll MASK31 = (1LL << 31) - 1;\r\n    const ll MASK61 = (1LL << 61)\
    \ - 1;\r\n    ll au = a >> 31, ad = a & MASK31;\r\n    ll bu = b >> 31, bd = b\
    \ & MASK31;\r\n    ll x = ad * bu + au * bd;\r\n    ll xu = x >> 30, xd = x &\
    \ MASK30;\r\n    x = au * bu * 2 + xu + (xd << 31) + ad * bd;\r\n    xu = x >>\
    \ 61, xd = x & MASK61;\r\n    x = xu + xd;\r\n    if (x >= MASK61) x -= MASK61;\r\
    \n    val = x;\r\n    return *this;\r\n  }\r\n  modint61 operator-() const { return\
    \ modint61(get_mod() - val); }\r\n  modint61 &operator/=(const modint61 &p) {\r\
    \n    *this *= p.inverse();\r\n    return *this;\r\n  }\r\n  modint61 operator+(const\
    \ modint61 &p) const { return modint61(*this) += p; }\r\n  modint61 operator-(const\
    \ modint61 &p) const { return modint61(*this) -= p; }\r\n  modint61 operator*(const\
    \ modint61 &p) const { return modint61(*this) *= p; }\r\n  modint61 operator/(const\
    \ modint61 &p) const { return modint61(*this) /= p; }\r\n\r\n  modint61 inverse()\
    \ const {\r\n    ll a = val, b = mod, u = 1, v = 0, t;\r\n    while (b > 0) {\r\
    \n      t = a / b;\r\n      swap(a -= t * b, b), swap(u -= t * v, v);\r\n    }\r\
    \n    return modint61(u);\r\n  }\r\n  modint61 pow(int64_t n) const {\r\n    modint61\
    \ ret(1), mul(val);\r\n    while (n > 0) {\r\n      if (n & 1) ret = ret * mul;\r\
    \n      mul = mul * mul;\r\n      n >>= 1;\r\n    }\r\n    return ret;\r\n  }\r\
    \n  static constexpr ll get_mod() { return mod; }\r\n};\r\n#line 5 \"random/hash_vector.hpp\"\
    \n\ntemplate <typename T>\nll hash_vector(vc<T> X) {\n  using mint = modint61;\n\
    \  static vc<mint> hash_base;\n  int n = len(X);\n  while (len(hash_base) <= n)\
    \ { hash_base.eb(RNG(mint::get_mod())); }\n  mint H = 0;\n  FOR(i, n) H += hash_base[i]\
    \ * mint(X[i]);\n  H += hash_base[n];\n  return H.val;\n}\n"
  code: "#pragma once\n\n#include \"random/base.hpp\"\n#include \"mod/modint61.hpp\"\
    \n\ntemplate <typename T>\nll hash_vector(vc<T> X) {\n  using mint = modint61;\n\
    \  static vc<mint> hash_base;\n  int n = len(X);\n  while (len(hash_base) <= n)\
    \ { hash_base.eb(RNG(mint::get_mod())); }\n  mint H = 0;\n  FOR(i, n) H += hash_base[i]\
    \ * mint(X[i]);\n  H += hash_base[n];\n  return H.val;\n}\n"
  dependsOn:
  - random/base.hpp
  - mod/modint61.hpp
  isVerificationFile: false
  path: random/hash_vector.hpp
  requiredBy:
  - other/connected_dp.hpp
  timestamp: '2022-10-26 11:17:35+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/yukicoder/541.test.cpp
  - test/yukicoder/1561.test.cpp
  - test/yukicoder/1881.test.cpp
  - test/yukicoder/578.test.cpp
  - test/yukicoder/579.test.cpp
  - test/mytest/tdpc_grid_dp.test.cpp
documentation_of: random/hash_vector.hpp
layout: document
redirect_from:
- /library/random/hash_vector.hpp
- /library/random/hash_vector.hpp.html
title: random/hash_vector.hpp
---
