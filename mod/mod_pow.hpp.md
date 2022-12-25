---
data:
  _extendedDependsOn:
  - icon: ':question:'
    path: mod/fast_div.hpp
    title: mod/fast_div.hpp
  _extendedRequiredBy:
  - icon: ':heavy_check_mark:'
    path: mod/mod_kth_root.hpp
    title: mod/mod_kth_root.hpp
  - icon: ':question:'
    path: mod/primitive_root.hpp
    title: mod/primitive_root.hpp
  - icon: ':heavy_check_mark:'
    path: nt/gaussian_integers.hpp
    title: nt/gaussian_integers.hpp
  - icon: ':heavy_check_mark:'
    path: nt/lcm.hpp
    title: nt/lcm.hpp
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/library_checker/math/kth_root_mod.test.cpp
    title: test/library_checker/math/kth_root_mod.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/library_checker/math/primitive_root.test.cpp
    title: test/library_checker/math/primitive_root.test.cpp
  - icon: ':x:'
    path: test/yukicoder/1025.test.cpp
    title: test/yukicoder/1025.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/yukicoder/1593.test.cpp
    title: test/yukicoder/1593.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/yukicoder/187.test.cpp
    title: test/yukicoder/187.test.cpp
  _isVerificationFailed: true
  _pathExtension: hpp
  _verificationStatusIcon: ':question:'
  attributes:
    links: []
  bundledCode: "#line 2 \"mod/fast_div.hpp\"\nstruct fast_div {\r\n  // Min25 https://judge.yosupo.jp/submission/46090\r\
    \n  // \u540C\u3058\u5B9A\u6570\u3067\u4F55\u5EA6\u3082\u9664\u7B97\u3059\u308B\
    \u3068\u304D\u306E\u9AD8\u901F\u5316\u306B\u4F7F\u3048\u308B\r\n  using i64 =\
    \ long long;\r\n  using u64 = unsigned long long;\r\n  using u128 = __uint128_t;\r\
    \n  constexpr fast_div() : m(), s(), x() {}\r\n  constexpr fast_div(int n)\r\n\
    \      : m(n), s(std::__lg(n - 1)), x(((u128(1) << (s + 64)) + n - 1) / n) {}\r\
    \n  constexpr friend u64 operator/(u64 n, const fast_div& d) {\r\n    return (u128(n)\
    \ * d.x >> d.s) >> 64;\r\n  }\r\n  constexpr friend int operator%(u64 n, const\
    \ fast_div& d) {\r\n    return n - n / d * d.m;\r\n  }\r\n  constexpr std::pair<i64,\
    \ int> divmod(u64 n) const {\r\n    u64 q = n / *this;\r\n    return {q, n - q\
    \ * m};\r\n  }\r\n\r\n  int m;\r\n  int s;\r\n  u64 x;\r\n};\r\n#line 3 \"mod/mod_pow.hpp\"\
    \n// int\r\nll mod_pow(ll a, ll n, int mod){\r\n  fast_div fd(mod);\r\n  a = a\
    \ % fd;\r\n  ll p = a;\r\n  ll v = 1;\r\n  while(n){\r\n    if(n & 1) v = v *\
    \ p % fd;\r\n    p = p * p % fd;\r\n    n >>= 1;\r\n  }\r\n  return v;\r\n}\r\n\
    \r\nll mod_pow_long(ll a, ll n, ll mod){\r\n  a %= mod;\r\n  ll p = a;\r\n  ll\
    \ v = 1;\r\n  while(n){\r\n    if(n & 1) v = i128(v) * p % mod;\r\n    p = i128(p)\
    \ * p % mod;\r\n    n >>= 1;\r\n  }\r\n  return v;\r\n}\r\n"
  code: "#pragma once\r\n#include \"mod/fast_div.hpp\"\r\n// int\r\nll mod_pow(ll\
    \ a, ll n, int mod){\r\n  fast_div fd(mod);\r\n  a = a % fd;\r\n  ll p = a;\r\n\
    \  ll v = 1;\r\n  while(n){\r\n    if(n & 1) v = v * p % fd;\r\n    p = p * p\
    \ % fd;\r\n    n >>= 1;\r\n  }\r\n  return v;\r\n}\r\n\r\nll mod_pow_long(ll a,\
    \ ll n, ll mod){\r\n  a %= mod;\r\n  ll p = a;\r\n  ll v = 1;\r\n  while(n){\r\
    \n    if(n & 1) v = i128(v) * p % mod;\r\n    p = i128(p) * p % mod;\r\n    n\
    \ >>= 1;\r\n  }\r\n  return v;\r\n}\r\n"
  dependsOn:
  - mod/fast_div.hpp
  isVerificationFile: false
  path: mod/mod_pow.hpp
  requiredBy:
  - nt/gaussian_integers.hpp
  - nt/lcm.hpp
  - mod/mod_kth_root.hpp
  - mod/primitive_root.hpp
  timestamp: '2022-05-19 23:05:54+09:00'
  verificationStatus: LIBRARY_SOME_WA
  verifiedWith:
  - test/yukicoder/1025.test.cpp
  - test/yukicoder/1593.test.cpp
  - test/yukicoder/187.test.cpp
  - test/library_checker/math/kth_root_mod.test.cpp
  - test/library_checker/math/primitive_root.test.cpp
documentation_of: mod/mod_pow.hpp
layout: document
redirect_from:
- /library/mod/mod_pow.hpp
- /library/mod/mod_pow.hpp.html
title: mod/mod_pow.hpp
---
