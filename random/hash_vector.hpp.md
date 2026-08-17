---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: mod/modint61.hpp
    title: mod/modint61.hpp
  - icon: ':heavy_check_mark:'
    path: random/base.hpp
    title: random/base.hpp
  _extendedRequiredBy:
  - icon: ':heavy_check_mark:'
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
  - icon: ':heavy_check_mark:'
    path: test/3_yukicoder/1881.test.cpp
    title: test/3_yukicoder/1881.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/3_yukicoder/541.test.cpp
    title: test/3_yukicoder/541.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/3_yukicoder/578.test.cpp
    title: test/3_yukicoder/578.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/3_yukicoder/579.test.cpp
    title: test/3_yukicoder/579.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 1 \"random/hash_vector.hpp\"\n\n#line 1 \"random/base.hpp\"\n\
    \nu64 RNG_64() {\n  static u64 x_ = u64(chrono::duration_cast<chrono::nanoseconds>(chrono::high_resolution_clock::now().time_since_epoch()).count())\
    \ * 10150724397891781847ULL;\n  x_ ^= x_ << 7;\n  return x_ ^= x_ >> 9;\n}\n\n\
    u64 RNG(u64 lim) { return RNG_64() % lim; }\n\nll RNG(ll l, ll r) { return l +\
    \ RNG_64() % (r - l); }\n#line 1 \"mod/modint61.hpp\"\n\nstruct modint61 {\n \
    \ static constexpr u64 mod = (1ULL << 61) - 1;\n  u64 val;\n  constexpr modint61()\
    \ : val(0ULL) {}\n  constexpr modint61(u32 x) : val(x) {}\n  constexpr modint61(u64\
    \ x) : val(x % mod) {}\n  constexpr modint61(int x) : val((x < 0) ? (x + static_cast<ll>(mod))\
    \ : x) {}\n  constexpr modint61(ll x) : val(((x %= static_cast<ll>(mod)) < 0)\
    \ ? (x + static_cast<ll>(mod)) : x) {}\n  static constexpr u64 get_mod() { return\
    \ mod; }\n\n  modint61 &operator+=(const modint61 &a) {\n    val = ((val += a.val)\
    \ >= mod) ? (val - mod) : val;\n    return *this;\n  }\n  modint61 &operator-=(const\
    \ modint61 &a) {\n    val = ((val -= a.val) >= mod) ? (val + mod) : val;\n   \
    \ return *this;\n  }\n  modint61 &operator*=(const modint61 &a) {\n    const unsigned\
    \ __int128 y = static_cast<unsigned __int128>(val) * a.val;\n    val = (y >> 61)\
    \ + (y & mod);\n    val = (val >= mod) ? (val - mod) : val;\n    return *this;\n\
    \  }\n  modint61 operator-() const { return modint61(val ? mod - val : u64(0));\
    \ }\n  modint61 &operator/=(const modint61 &a) { return (*this *= a.inverse());\
    \ }\n  modint61 operator+(const modint61 &p) const { return modint61(*this) +=\
    \ p; }\n  modint61 operator-(const modint61 &p) const { return modint61(*this)\
    \ -= p; }\n  modint61 operator*(const modint61 &p) const { return modint61(*this)\
    \ *= p; }\n  modint61 operator/(const modint61 &p) const { return modint61(*this)\
    \ /= p; }\n  bool operator<(const modint61 &other) const { return val < other.val;\
    \ }\n  bool operator==(const modint61 &p) const { return val == p.val; }\n  bool\
    \ operator!=(const modint61 &p) const { return val != p.val; }\n  modint61 inverse()\
    \ const {\n    ll a = val, b = mod, u = 1, v = 0, t;\n    while (b > 0) {\n  \
    \    t = a / b;\n      swap(a -= t * b, b), swap(u -= t * v, v);\n    }\n    return\
    \ modint61(u);\n  }\n  modint61 pow(ll n) const {\n    assert(n >= 0);\n    modint61\
    \ ret(1), mul(val);\n    while (n > 0) {\n      if (n & 1) ret *= mul;\n     \
    \ mul *= mul, n >>= 1;\n    }\n    return ret;\n  }\n};\n\n#ifdef FASTIO\nvoid\
    \ rd(modint61 &x) {\n  fastio::rd(x.val);\n  assert(0 <= x.val && x.val < modint61::mod);\n\
    }\n\nvoid wt(modint61 x) { fastio::wt(x.val); }\n#endif\n#line 4 \"random/hash_vector.hpp\"\
    \n\ntemplate <typename T>\nu64 hash_vector(vc<T> X) {\n  using mint = modint61;\n\
    \  static vc<mint> hash_base;\n  int n = len(X);\n  while (len(hash_base) <= n)\
    \ { hash_base.eb(RNG(mint::get_mod())); }\n  mint H = 0;\n  FOR(i, n) H += hash_base[i]\
    \ * mint(X[i]);\n  H += hash_base[n];\n  return H.val;\n}\n\ntemplate <typename\
    \ T, int K>\nu64 hash_array(array<T, K> X) {\n  using mint = modint61;\n  static\
    \ array<mint, K> hash_base{};\n  if (hash_base[0] == mint(0)) FOR(i, K) hash_base[i]\
    \ = RNG_64();\n  mint H = 0;\n  FOR(i, K) H += hash_base[i] * mint(X[i]);\n  return\
    \ H.val;\n}\n"
  code: "\n#include \"random/base.hpp\"\n#include \"mod/modint61.hpp\"\n\ntemplate\
    \ <typename T>\nu64 hash_vector(vc<T> X) {\n  using mint = modint61;\n  static\
    \ vc<mint> hash_base;\n  int n = len(X);\n  while (len(hash_base) <= n) { hash_base.eb(RNG(mint::get_mod()));\
    \ }\n  mint H = 0;\n  FOR(i, n) H += hash_base[i] * mint(X[i]);\n  H += hash_base[n];\n\
    \  return H.val;\n}\n\ntemplate <typename T, int K>\nu64 hash_array(array<T, K>\
    \ X) {\n  using mint = modint61;\n  static array<mint, K> hash_base{};\n  if (hash_base[0]\
    \ == mint(0)) FOR(i, K) hash_base[i] = RNG_64();\n  mint H = 0;\n  FOR(i, K) H\
    \ += hash_base[i] * mint(X[i]);\n  return H.val;\n}\n"
  dependsOn:
  - random/base.hpp
  - mod/modint61.hpp
  isVerificationFile: false
  path: random/hash_vector.hpp
  requiredBy:
  - other/connected_dp.hpp
  timestamp: '2026-08-16 04:03:00+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/1_mytest/tdpc_grid_dp.test.cpp
  - test/3_yukicoder/578.test.cpp
  - test/3_yukicoder/1397.test.cpp
  - test/3_yukicoder/1881.test.cpp
  - test/3_yukicoder/1561.test.cpp
  - test/3_yukicoder/579.test.cpp
  - test/3_yukicoder/541.test.cpp
documentation_of: random/hash_vector.hpp
layout: document
redirect_from:
- /library/random/hash_vector.hpp
- /library/random/hash_vector.hpp.html
title: random/hash_vector.hpp
---
