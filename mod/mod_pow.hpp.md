---
data:
  _extendedDependsOn:
  - icon: ':question:'
    path: mod/barret.hpp
    title: mod/barret.hpp
  _extendedRequiredBy:
  - icon: ':x:'
    path: mod/mod_kth_root.hpp
    title: mod/mod_kth_root.hpp
  - icon: ':x:'
    path: mod/primitive_root.hpp
    title: mod/primitive_root.hpp
  - icon: ':x:'
    path: nt/gaussian_integers.hpp
    title: nt/gaussian_integers.hpp
  - icon: ':x:'
    path: poly/multivar_convolution_cyclic.hpp
    title: poly/multivar_convolution_cyclic.hpp
  _extendedVerifiedWith:
  - icon: ':x:'
    path: test/library_checker/math/kth_root_mod.test.cpp
    title: test/library_checker/math/kth_root_mod.test.cpp
  - icon: ':x:'
    path: test/library_checker/math/multivariate_convolution_cyclic.test.cpp
    title: test/library_checker/math/multivariate_convolution_cyclic.test.cpp
  - icon: ':x:'
    path: test/library_checker/math/primitive_root.test.cpp
    title: test/library_checker/math/primitive_root.test.cpp
  - icon: ':x:'
    path: test/yukicoder/1025.test.cpp
    title: test/yukicoder/1025.test.cpp
  - icon: ':x:'
    path: test/yukicoder/1593.test.cpp
    title: test/yukicoder/1593.test.cpp
  _isVerificationFailed: true
  _pathExtension: hpp
  _verificationStatusIcon: ':x:'
  attributes:
    links: []
  bundledCode: "#line 2 \"mod/barret.hpp\"\n\nstruct Barret_Reduction {\n  using i64\
    \ = long long;\n  using u64 = unsigned long long;\n  using u128 = __uint128_t;\n\
    \  int m, s;\n  u64 x;\n  constexpr Barret_Reduction() : m(), s(), x() {}\n  constexpr\
    \ Barret_Reduction(int n)\n      : m(n), s(std::__lg(n - 1)), x(((u128(1) << (s\
    \ + 64)) + n - 1) / n) {}\n  constexpr friend u64 operator/(u64 n, const Barret_Reduction&\
    \ d) {\n    return (u128(n) * d.x >> d.s) >> 64;\n  }\n  constexpr friend int\
    \ operator%(u64 n, const Barret_Reduction& d) {\n    return n - n / d * d.m;\n\
    \  }\n  constexpr pair<i64, int> divmod(u64 n) const {\n    u64 q = n / *this;\n\
    \    return {q, n - q * m};\n  }\n};\n#line 3 \"mod/mod_pow.hpp\"\n\r\n// int\r\
    \nll mod_pow(ll a, ll n, int mod) {\r\n  Barret_Reduction BR(mod);\r\n  a = a\
    \ % BR;\r\n  ll p = a;\r\n  ll v = 1;\r\n  while (n) {\r\n    if (n & 1) v = v\
    \ * p % BR;\r\n    p = p * p % BR;\r\n    n >>= 1;\r\n  }\r\n  return v;\r\n}\r\
    \n\r\nll mod_pow_long(ll a, ll n, ll mod) {\r\n  a %= mod;\r\n  ll p = a;\r\n\
    \  ll v = 1;\r\n  while (n) {\r\n    if (n & 1) v = i128(v) * p % mod;\r\n   \
    \ p = i128(p) * p % mod;\r\n    n >>= 1;\r\n  }\r\n  return v;\r\n}\r\n"
  code: "#pragma once\r\n#include \"mod/barret.hpp\"\r\n\r\n// int\r\nll mod_pow(ll\
    \ a, ll n, int mod) {\r\n  Barret_Reduction BR(mod);\r\n  a = a % BR;\r\n  ll\
    \ p = a;\r\n  ll v = 1;\r\n  while (n) {\r\n    if (n & 1) v = v * p % BR;\r\n\
    \    p = p * p % BR;\r\n    n >>= 1;\r\n  }\r\n  return v;\r\n}\r\n\r\nll mod_pow_long(ll\
    \ a, ll n, ll mod) {\r\n  a %= mod;\r\n  ll p = a;\r\n  ll v = 1;\r\n  while (n)\
    \ {\r\n    if (n & 1) v = i128(v) * p % mod;\r\n    p = i128(p) * p % mod;\r\n\
    \    n >>= 1;\r\n  }\r\n  return v;\r\n}\r\n"
  dependsOn:
  - mod/barret.hpp
  isVerificationFile: false
  path: mod/mod_pow.hpp
  requiredBy:
  - mod/primitive_root.hpp
  - mod/mod_kth_root.hpp
  - nt/gaussian_integers.hpp
  - poly/multivar_convolution_cyclic.hpp
  timestamp: '2023-04-27 03:47:30+09:00'
  verificationStatus: LIBRARY_ALL_WA
  verifiedWith:
  - test/yukicoder/1025.test.cpp
  - test/yukicoder/1593.test.cpp
  - test/library_checker/math/kth_root_mod.test.cpp
  - test/library_checker/math/primitive_root.test.cpp
  - test/library_checker/math/multivariate_convolution_cyclic.test.cpp
documentation_of: mod/mod_pow.hpp
layout: document
redirect_from:
- /library/mod/mod_pow.hpp
- /library/mod/mod_pow.hpp.html
title: mod/mod_pow.hpp
---
