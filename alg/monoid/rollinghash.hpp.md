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
  - icon: ':heavy_check_mark:'
    path: test/library_checker/string/zalgorithm_by_rollinghash2.test.cpp
    title: test/library_checker/string/zalgorithm_by_rollinghash2.test.cpp
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
    ll RNG(ll l, ll r) { return l + RNG_64() % (r - l); }\n#line 2 \"mod/modint61.hpp\"\
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
    \n  static constexpr ll get_mod() { return mod; }\r\n};\r\n#line 4 \"alg/monoid/rollinghash.hpp\"\
    \n\r\n// pow of base, val\r\nstruct Monoid_Rolling_Hash {\r\n  using value_type\
    \ = pair<modint61, modint61>;\r\n  using X = value_type;\r\n\r\n  static u64 &get_param()\
    \ {\r\n    static u64 base = 0;\r\n    return base;\r\n  }\r\n  static void set_param(u64\
    \ base) { get_param() = base; }\r\n\r\n  static X from_element(u64 x) {\r\n  \
    \  while (get_param() == 0) set_param(RNG_64());\r\n    return {get_param(), x};\r\
    \n  }\r\n  static X op(X x, X y) { return {x.fi * y.fi, x.se * y.fi + y.se}; }\r\
    \n  static constexpr X unit() { return {1, 0}; }\r\n  static constexpr bool commute\
    \ = false;\r\n};\n"
  code: "#pragma once\r\n#include \"random/base.hpp\"\r\n#include \"mod/modint61.hpp\"\
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
  timestamp: '2022-11-28 00:22:56+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/library_checker/string/zalgorithm_by_rollinghash2.test.cpp
documentation_of: alg/monoid/rollinghash.hpp
layout: document
redirect_from:
- /library/alg/monoid/rollinghash.hpp
- /library/alg/monoid/rollinghash.hpp.html
title: alg/monoid/rollinghash.hpp
---
