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
    path: test/2_library_checker/string/zalgorithm_by_rollinghash2.test.cpp
    title: test/2_library_checker/string/zalgorithm_by_rollinghash2.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 1 \"alg/monoid/rolling_hash.hpp\"\n\n#line 1 \"random/base.hpp\"\
    \n\nu64 RNG_64() {\n  static u64 x_ = u64(chrono::duration_cast<chrono::nanoseconds>(chrono::high_resolution_clock::now().time_since_epoch()).count())\
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
    }\n\nvoid wt(modint61 x) { fastio::wt(x.val); }\n#endif\n#line 4 \"alg/monoid/rolling_hash.hpp\"\
    \n\n// pow of base, val\nstruct Monoid_Rolling_Hash {\n  using value_type = pair<modint61,\
    \ modint61>;\n  using X = value_type;\n\n  static u64 &get_param() {\n    static\
    \ u64 base = 0;\n    return base;\n  }\n  static void set_param(u64 base) { get_param()\
    \ = base; }\n\n  static X from_element(u64 x) {\n    while (get_param() == 0)\
    \ set_param(RNG_64());\n    return {get_param(), x};\n  }\n  static X op(X x,\
    \ X y) { return {x.fi * y.fi, x.se * y.fi + y.se}; }\n  static constexpr X unit()\
    \ { return {1, 0}; }\n  static constexpr bool commute = false;\n};\n"
  code: "\n#include \"random/base.hpp\"\n#include \"mod/modint61.hpp\"\n\n// pow of\
    \ base, val\nstruct Monoid_Rolling_Hash {\n  using value_type = pair<modint61,\
    \ modint61>;\n  using X = value_type;\n\n  static u64 &get_param() {\n    static\
    \ u64 base = 0;\n    return base;\n  }\n  static void set_param(u64 base) { get_param()\
    \ = base; }\n\n  static X from_element(u64 x) {\n    while (get_param() == 0)\
    \ set_param(RNG_64());\n    return {get_param(), x};\n  }\n  static X op(X x,\
    \ X y) { return {x.fi * y.fi, x.se * y.fi + y.se}; }\n  static constexpr X unit()\
    \ { return {1, 0}; }\n  static constexpr bool commute = false;\n};"
  dependsOn:
  - random/base.hpp
  - mod/modint61.hpp
  isVerificationFile: false
  path: alg/monoid/rolling_hash.hpp
  requiredBy: []
  timestamp: '2026-08-17 09:52:06+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/2_library_checker/string/zalgorithm_by_rollinghash2.test.cpp
documentation_of: alg/monoid/rolling_hash.hpp
layout: document
redirect_from:
- /library/alg/monoid/rolling_hash.hpp
- /library/alg/monoid/rolling_hash.hpp.html
title: alg/monoid/rolling_hash.hpp
---
