---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':warning:'
  attributes:
    links:
    - https://qoj.ac/problem/969
  bundledCode: "#line 1 \"mod/modint_64bit.hpp\"\n// https://qoj.ac/problem/969\n\
    template <ll mod>\nstruct modint_64bit {\n  using T = modint_64bit;\n  static\
    \ constexpr u64 umod = u64(mod);\n  static_assert(umod < u64(1) << 63);\n  u64\
    \ val;\n  constexpr modint_64bit() : val(0) {}\n  constexpr modint_64bit(u64 x)\
    \ : val(x % umod) {}\n  constexpr modint_64bit(u128 x) : val(x % umod) {}\n  constexpr\
    \ modint_64bit(int x) : val((x %= mod) < 0 ? x + mod : x){};\n  constexpr modint_64bit(ll\
    \ x) : val((x %= mod) < 0 ? x + mod : x){};\n  constexpr modint_64bit(i128 x)\
    \ : val((x %= mod) < 0 ? x + mod : x){};\n  static T raw(u64 v) {\n    T x;\n\
    \    x.val = v;\n    return x;\n  }\n  bool operator<(const T& other) const {\
    \ return val < other.val; }\n  T& operator+=(const T& p) {\n    if ((val += p.val)\
    \ >= umod) val -= umod;\n    return *this;\n  }\n  T& operator-=(const T& p) {\n\
    \    if ((val += umod - p.val) >= umod) val -= umod;\n    return *this;\n  }\n\
    \  T& operator*=(const T& p) {\n    val = u128(val) * p.val % umod;\n    return\
    \ *this;\n  }\n  T& operator/=(const T& p) {\n    *this *= p.inverse();\n    return\
    \ *this;\n  }\n  T operator-() const { return raw(val ? mod - val : u32(0)); }\n\
    \  T operator+(const T& p) const { return modint_64bit(*this) += p; }\n  T operator-(const\
    \ T& p) const { return modint_64bit(*this) -= p; }\n  T operator*(const T& p)\
    \ const { return modint_64bit(*this) *= p; }\n  T operator/(const T& p) const\
    \ { return modint_64bit(*this) /= p; }\n  bool operator==(const T& p) const {\
    \ return val == p.val; }\n  bool operator!=(const T& p) const { return val !=\
    \ p.val; }\n  T inverse() const {\n    int a = val, b = mod, u = 1, v = 0, t;\n\
    \    while (b > 0) {\n      t = a / b;\n      swap(a -= t * b, b), swap(u -= t\
    \ * v, v);\n    }\n    return modint_64bit(u);\n  }\n  T pow(ll n) const {\n \
    \   assert(n >= 0);\n    T ret(1), mul(val);\n    while (n > 0) {\n      if (n\
    \ & 1) ret *= mul;\n      mul *= mul, n >>= 1;\n    }\n    return ret;\n  }\n\
    \  static constexpr ll get_mod() { return mod; }\n  // (n, r), r \u306F 1 \u306E\
    \ 2^n \u4E57\u6839\n  static constexpr pair<ll, ll> ntt_info() { return {-1, -1};\
    \ }\n  static constexpr bool can_ntt() { return ntt_info().fi != -1; }\n};\n#ifdef\
    \ FASTIO\ntemplate <ll mod>\nvoid rd(modint_64bit<mod>& x) {\n  fastio::rd(x.val);\n\
    \  x.val %= mod;\n}\ntemplate <ll mod>\nvoid wt(modint_64bit<mod> x) {\n  fastio::wt(x.val);\n\
    }\n#endif\n"
  code: "// https://qoj.ac/problem/969\ntemplate <ll mod>\nstruct modint_64bit {\n\
    \  using T = modint_64bit;\n  static constexpr u64 umod = u64(mod);\n  static_assert(umod\
    \ < u64(1) << 63);\n  u64 val;\n  constexpr modint_64bit() : val(0) {}\n  constexpr\
    \ modint_64bit(u64 x) : val(x % umod) {}\n  constexpr modint_64bit(u128 x) : val(x\
    \ % umod) {}\n  constexpr modint_64bit(int x) : val((x %= mod) < 0 ? x + mod :\
    \ x){};\n  constexpr modint_64bit(ll x) : val((x %= mod) < 0 ? x + mod : x){};\n\
    \  constexpr modint_64bit(i128 x) : val((x %= mod) < 0 ? x + mod : x){};\n  static\
    \ T raw(u64 v) {\n    T x;\n    x.val = v;\n    return x;\n  }\n  bool operator<(const\
    \ T& other) const { return val < other.val; }\n  T& operator+=(const T& p) {\n\
    \    if ((val += p.val) >= umod) val -= umod;\n    return *this;\n  }\n  T& operator-=(const\
    \ T& p) {\n    if ((val += umod - p.val) >= umod) val -= umod;\n    return *this;\n\
    \  }\n  T& operator*=(const T& p) {\n    val = u128(val) * p.val % umod;\n   \
    \ return *this;\n  }\n  T& operator/=(const T& p) {\n    *this *= p.inverse();\n\
    \    return *this;\n  }\n  T operator-() const { return raw(val ? mod - val :\
    \ u32(0)); }\n  T operator+(const T& p) const { return modint_64bit(*this) +=\
    \ p; }\n  T operator-(const T& p) const { return modint_64bit(*this) -= p; }\n\
    \  T operator*(const T& p) const { return modint_64bit(*this) *= p; }\n  T operator/(const\
    \ T& p) const { return modint_64bit(*this) /= p; }\n  bool operator==(const T&\
    \ p) const { return val == p.val; }\n  bool operator!=(const T& p) const { return\
    \ val != p.val; }\n  T inverse() const {\n    int a = val, b = mod, u = 1, v =\
    \ 0, t;\n    while (b > 0) {\n      t = a / b;\n      swap(a -= t * b, b), swap(u\
    \ -= t * v, v);\n    }\n    return modint_64bit(u);\n  }\n  T pow(ll n) const\
    \ {\n    assert(n >= 0);\n    T ret(1), mul(val);\n    while (n > 0) {\n     \
    \ if (n & 1) ret *= mul;\n      mul *= mul, n >>= 1;\n    }\n    return ret;\n\
    \  }\n  static constexpr ll get_mod() { return mod; }\n  // (n, r), r \u306F 1\
    \ \u306E 2^n \u4E57\u6839\n  static constexpr pair<ll, ll> ntt_info() { return\
    \ {-1, -1}; }\n  static constexpr bool can_ntt() { return ntt_info().fi != -1;\
    \ }\n};\n#ifdef FASTIO\ntemplate <ll mod>\nvoid rd(modint_64bit<mod>& x) {\n \
    \ fastio::rd(x.val);\n  x.val %= mod;\n}\ntemplate <ll mod>\nvoid wt(modint_64bit<mod>\
    \ x) {\n  fastio::wt(x.val);\n}\n#endif\n"
  dependsOn: []
  isVerificationFile: false
  path: mod/modint_64bit.hpp
  requiredBy: []
  timestamp: '2024-10-13 19:40:04+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: mod/modint_64bit.hpp
layout: document
redirect_from:
- /library/mod/modint_64bit.hpp
- /library/mod/modint_64bit.hpp.html
title: mod/modint_64bit.hpp
---
