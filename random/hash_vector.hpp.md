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
  - icon: ':question:'
    path: other/connected_dp.hpp
    title: other/connected_dp.hpp
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/1_mytest/tdpc_grid_dp.test.cpp
    title: test/1_mytest/tdpc_grid_dp.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/3_yukicoder/1397.test.cpp
    title: test/3_yukicoder/1397.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/3_yukicoder/1561.test.cpp
    title: test/3_yukicoder/1561.test.cpp
  - icon: ':x:'
    path: test/3_yukicoder/1881.test.cpp
    title: test/3_yukicoder/1881.test.cpp
  - icon: ':x:'
    path: test/3_yukicoder/541.test.cpp
    title: test/3_yukicoder/541.test.cpp
  - icon: ':x:'
    path: test/3_yukicoder/578.test.cpp
    title: test/3_yukicoder/578.test.cpp
  - icon: ':x:'
    path: test/3_yukicoder/579.test.cpp
    title: test/3_yukicoder/579.test.cpp
  _isVerificationFailed: true
  _pathExtension: hpp
  _verificationStatusIcon: ':question:'
  attributes:
    links: []
  bundledCode: "#line 2 \"random/hash_vector.hpp\"\n\n#line 2 \"random/base.hpp\"\n\
    \nu64 RNG_64() {\n  static u64 x_ = u64(chrono::duration_cast<chrono::nanoseconds>(chrono::high_resolution_clock::now().time_since_epoch()).count())\
    \ * 10150724397891781847ULL;\n  x_ ^= x_ << 7;\n  return x_ ^= x_ >> 9;\n}\n\n\
    u64 RNG(u64 lim) { return RNG_64() % lim; }\n\nll RNG(ll l, ll r) { return l +\
    \ RNG_64() % (r - l); }\n#line 2 \"mod/modint61.hpp\"\n\r\nstruct modint61 {\r\
    \n  static constexpr u64 mod = (1ULL << 61) - 1;\r\n  u64 val;\r\n  constexpr\
    \ modint61() : val(0ULL) {}\r\n  constexpr modint61(u32 x) : val(x) {}\r\n  constexpr\
    \ modint61(u64 x) : val(x % mod) {}\r\n  constexpr modint61(int x) : val((x <\
    \ 0) ? (x + static_cast<ll>(mod)) : x) {}\r\n  constexpr modint61(ll x) : val(((x\
    \ %= static_cast<ll>(mod)) < 0) ? (x + static_cast<ll>(mod)) : x) {}\r\n  static\
    \ constexpr u64 get_mod() { return mod; }\r\n\r\n  modint61 &operator+=(const\
    \ modint61 &a) {\r\n    val = ((val += a.val) >= mod) ? (val - mod) : val;\r\n\
    \    return *this;\r\n  }\r\n  modint61 &operator-=(const modint61 &a) {\r\n \
    \   val = ((val -= a.val) >= mod) ? (val + mod) : val;\r\n    return *this;\r\n\
    \  }\r\n  modint61 &operator*=(const modint61 &a) {\r\n    const unsigned __int128\
    \ y = static_cast<unsigned __int128>(val) * a.val;\r\n    val = (y >> 61) + (y\
    \ & mod);\r\n    val = (val >= mod) ? (val - mod) : val;\r\n    return *this;\r\
    \n  }\r\n  modint61 operator-() const { return modint61(val ? mod - val : u64(0));\
    \ }\r\n  modint61 &operator/=(const modint61 &a) { return (*this *= a.inverse());\
    \ }\r\n  modint61 operator+(const modint61 &p) const { return modint61(*this)\
    \ += p; }\r\n  modint61 operator-(const modint61 &p) const { return modint61(*this)\
    \ -= p; }\r\n  modint61 operator*(const modint61 &p) const { return modint61(*this)\
    \ *= p; }\r\n  modint61 operator/(const modint61 &p) const { return modint61(*this)\
    \ /= p; }\r\n  bool operator<(const modint61 &other) const { return val < other.val;\
    \ }\r\n  bool operator==(const modint61 &p) const { return val == p.val; }\r\n\
    \  bool operator!=(const modint61 &p) const { return val != p.val; }\r\n  modint61\
    \ inverse() const {\r\n    ll a = val, b = mod, u = 1, v = 0, t;\r\n    while\
    \ (b > 0) {\r\n      t = a / b;\r\n      swap(a -= t * b, b), swap(u -= t * v,\
    \ v);\r\n    }\r\n    return modint61(u);\r\n  }\r\n  modint61 pow(ll n) const\
    \ {\r\n    assert(n >= 0);\r\n    modint61 ret(1), mul(val);\r\n    while (n >\
    \ 0) {\r\n      if (n & 1) ret *= mul;\r\n      mul *= mul, n >>= 1;\r\n    }\r\
    \n    return ret;\r\n  }\r\n};\r\n\r\n#ifdef FASTIO\r\nvoid rd(modint61 &x) {\r\
    \n  fastio::rd(x.val);\r\n  assert(0 <= x.val && x.val < modint61::mod);\r\n}\r\
    \n\r\nvoid wt(modint61 x) { fastio::wt(x.val); }\r\n#endif\n#line 5 \"random/hash_vector.hpp\"\
    \n\ntemplate <typename T>\nu64 hash_vector(vc<T> X) {\n  using mint = modint61;\n\
    \  static vc<mint> hash_base;\n  int n = len(X);\n  while (len(hash_base) <= n)\
    \ { hash_base.eb(RNG(mint::get_mod())); }\n  mint H = 0;\n  FOR(i, n) H += hash_base[i]\
    \ * mint(X[i]);\n  H += hash_base[n];\n  return H.val;\n}\n\ntemplate <typename\
    \ T, int K>\nu64 hash_array(array<T, K> X) {\n  using mint = modint61;\n  static\
    \ array<mint, K> hash_base{};\n  if (hash_base[0] == mint(0)) FOR(i, K) hash_base[i]\
    \ = RNG_64();\n  mint H = 0;\n  FOR(i, K) H += hash_base[i] * mint(X[i]);\n  return\
    \ H.val;\n}\n"
  code: "#pragma once\n\n#include \"random/base.hpp\"\n#include \"mod/modint61.hpp\"\
    \n\ntemplate <typename T>\nu64 hash_vector(vc<T> X) {\n  using mint = modint61;\n\
    \  static vc<mint> hash_base;\n  int n = len(X);\n  while (len(hash_base) <= n)\
    \ { hash_base.eb(RNG(mint::get_mod())); }\n  mint H = 0;\n  FOR(i, n) H += hash_base[i]\
    \ * mint(X[i]);\n  H += hash_base[n];\n  return H.val;\n}\n\ntemplate <typename\
    \ T, int K>\nu64 hash_array(array<T, K> X) {\n  using mint = modint61;\n  static\
    \ array<mint, K> hash_base{};\n  if (hash_base[0] == mint(0)) FOR(i, K) hash_base[i]\
    \ = RNG_64();\n  mint H = 0;\n  FOR(i, K) H += hash_base[i] * mint(X[i]);\n  return\
    \ H.val;\n}\n"
  dependsOn:
  - random/base.hpp
  - mod/modint61.hpp
  isVerificationFile: false
  path: random/hash_vector.hpp
  requiredBy:
  - other/connected_dp.hpp
  timestamp: '2024-10-18 02:58:53+09:00'
  verificationStatus: LIBRARY_SOME_WA
  verifiedWith:
  - test/3_yukicoder/578.test.cpp
  - test/3_yukicoder/1397.test.cpp
  - test/3_yukicoder/541.test.cpp
  - test/3_yukicoder/1561.test.cpp
  - test/3_yukicoder/579.test.cpp
  - test/3_yukicoder/1881.test.cpp
  - test/1_mytest/tdpc_grid_dp.test.cpp
documentation_of: random/hash_vector.hpp
layout: document
redirect_from:
- /library/random/hash_vector.hpp
- /library/random/hash_vector.hpp.html
title: random/hash_vector.hpp
---
