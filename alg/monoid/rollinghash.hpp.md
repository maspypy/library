---
data:
  _extendedDependsOn:
  - icon: ':question:'
    path: mod/modint61.hpp
    title: mod/modint61.hpp
  - icon: ':question:'
    path: random/base.hpp
    title: random/base.hpp
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':x:'
    path: test/library_checker/string/zalgorithm_by_rollinghash2.test.cpp
    title: test/library_checker/string/zalgorithm_by_rollinghash2.test.cpp
  _isVerificationFailed: true
  _pathExtension: hpp
  _verificationStatusIcon: ':x:'
  attributes:
    links: []
  bundledCode: "#line 2 \"alg/monoid/rollinghash.hpp\"\n\r\n#line 2 \"random/base.hpp\"\
    \n\nu64 RNG_64() {\n  static uint64_t x_\n      = uint64_t(chrono::duration_cast<chrono::nanoseconds>(\n\
    \                     chrono::high_resolution_clock::now().time_since_epoch())\n\
    \                     .count())\n        * 10150724397891781847ULL;\n  x_ ^= x_\
    \ << 7;\n  return x_ ^= x_ >> 9;\n}\n\nu64 RNG(u64 lim) { return RNG_64() % lim;\
    \ }\n\nll RNG(ll l, ll r) { return l + RNG_64() % (r - l); }\n#line 2 \"mod/modint61.hpp\"\
    \n\r\nstruct modint61 {\r\n  static constexpr u64 mod = (1ULL << 61) - 1;\r\n\
    \  u64 val;\r\n  constexpr modint61() : val(0ULL) {}\r\n  constexpr modint61(u32\
    \ x) : val(x) {}\r\n  constexpr modint61(u64 x) : val(x % mod) {}\r\n  constexpr\
    \ modint61(int x) : val((x < 0) ? (x + static_cast<ll>(mod)) : x) {}\r\n  constexpr\
    \ modint61(ll x)\r\n      : val(((x %= static_cast<ll>(mod)) < 0) ? (x + static_cast<ll>(mod))\r\
    \n                                              : x) {}\r\n  static constexpr\
    \ u64 get_mod() { return mod; }\r\n  modint61 &operator+=(const modint61 &a) {\r\
    \n    val = ((val += a.val) >= mod) ? (val - mod) : val;\r\n    return *this;\r\
    \n  }\r\n  modint61 &operator-=(const modint61 &a) {\r\n    val = ((val -= a.val)\
    \ >= mod) ? (val + mod) : val;\r\n    return *this;\r\n  }\r\n  modint61 &operator*=(const\
    \ modint61 &a) {\r\n    const unsigned __int128 y = static_cast<unsigned __int128>(val)\
    \ * a.val;\r\n    val = (y >> 61) + (y & mod);\r\n    val = (val >= mod) ? (val\
    \ - mod) : val;\r\n    return *this;\r\n  }\r\n  modint61 &operator/=(const modint61\
    \ &a) { return (*this *= a.inverse()); }\r\n  modint61 operator+(const modint61\
    \ &p) const { return modint61(*this) += p; }\r\n  modint61 operator-(const modint61\
    \ &p) const { return modint61(*this) -= p; }\r\n  modint61 operator*(const modint61\
    \ &p) const { return modint61(*this) *= p; }\r\n  modint61 operator/(const modint61\
    \ &p) const { return modint61(*this) /= p; }\r\n  bool operator==(const modint61\
    \ &p) const { return val == p.val; }\r\n  bool operator!=(const modint61 &p) const\
    \ { return val != p.val; }\r\n  modint61 inverse() const {\r\n    ll a = val,\
    \ b = mod, u = 1, v = 0, t;\r\n    while (b > 0) {\r\n      t = a / b;\r\n   \
    \   swap(a -= t * b, b), swap(u -= t * v, v);\r\n    }\r\n    return modint61(u);\r\
    \n  }\r\n  modint61 pow(ll n) const {\r\n    assert(n >= 0);\r\n    modint61 ret(1),\
    \ mul(val);\r\n    while (n > 0) {\r\n      if (n & 1) ret *= mul;\r\n      mul\
    \ *= mul, n >>= 1;\r\n    }\r\n    return ret;\r\n  }\r\n#ifdef FASTIO\r\n  void\
    \ write() { fastio::printer.write(val); }\r\n  void read() {\r\n    ll x;\r\n\
    \    fastio::scanner.read(x);\r\n    val = (val >= 0 ? val % mod : (mod - (-val)\
    \ % mod) % mod);\r\n  }\r\n#endif\r\n};\n#line 5 \"alg/monoid/rollinghash.hpp\"\
    \n\r\n// pow of base, val\r\nstruct Monoid_Rolling_Hash {\r\n  using value_type\
    \ = pair<modint61, modint61>;\r\n  using X = value_type;\r\n\r\n  static u64 &get_param()\
    \ {\r\n    static u64 base = 0;\r\n    return base;\r\n  }\r\n  static void set_param(u64\
    \ base) { get_param() = base; }\r\n\r\n  static X from_element(u64 x) {\r\n  \
    \  while (get_param() == 0) set_param(RNG_64());\r\n    return {get_param(), x};\r\
    \n  }\r\n  static X op(X x, X y) { return {x.fi * y.fi, x.se * y.fi + y.se}; }\r\
    \n  static constexpr X unit() { return {1, 0}; }\r\n  static constexpr bool commute\
    \ = false;\r\n};\n"
  code: "#pragma once\r\n\r\n#include \"random/base.hpp\"\r\n#include \"mod/modint61.hpp\"\
    \r\n\r\n// pow of base, val\r\nstruct Monoid_Rolling_Hash {\r\n  using value_type\
    \ = pair<modint61, modint61>;\r\n  using X = value_type;\r\n\r\n  static u64 &get_param()\
    \ {\r\n    static u64 base = 0;\r\n    return base;\r\n  }\r\n  static void set_param(u64\
    \ base) { get_param() = base; }\r\n\r\n  static X from_element(u64 x) {\r\n  \
    \  while (get_param() == 0) set_param(RNG_64());\r\n    return {get_param(), x};\r\
    \n  }\r\n  static X op(X x, X y) { return {x.fi * y.fi, x.se * y.fi + y.se}; }\r\
    \n  static constexpr X unit() { return {1, 0}; }\r\n  static constexpr bool commute\
    \ = false;\r\n};"
  dependsOn:
  - random/base.hpp
  - mod/modint61.hpp
  isVerificationFile: false
  path: alg/monoid/rollinghash.hpp
  requiredBy: []
  timestamp: '2023-08-13 16:19:41+09:00'
  verificationStatus: LIBRARY_ALL_WA
  verifiedWith:
  - test/library_checker/string/zalgorithm_by_rollinghash2.test.cpp
documentation_of: alg/monoid/rollinghash.hpp
layout: document
redirect_from:
- /library/alg/monoid/rollinghash.hpp
- /library/alg/monoid/rollinghash.hpp.html
title: alg/monoid/rollinghash.hpp
---
