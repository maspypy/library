---
data:
  _extendedDependsOn: []
  _extendedRequiredBy:
  - icon: ':question:'
    path: linalg/det.hpp
    title: linalg/det.hpp
  - icon: ':question:'
    path: linalg/det_mod.hpp
    title: linalg/det_mod.hpp
  - icon: ':heavy_check_mark:'
    path: mod/binomial.hpp
    title: mod/binomial.hpp
  - icon: ':heavy_check_mark:'
    path: mod/mod_kth_root.hpp
    title: mod/mod_kth_root.hpp
  - icon: ':heavy_check_mark:'
    path: mod/mod_pow.hpp
    title: mod/mod_pow.hpp
  - icon: ':heavy_check_mark:'
    path: mod/primitive_root.hpp
    title: mod/primitive_root.hpp
  - icon: ':heavy_check_mark:'
    path: mod/tetration.hpp
    title: mod/tetration.hpp
  - icon: ':question:'
    path: nt/crt.hpp
    title: nt/crt.hpp
  - icon: ':heavy_check_mark:'
    path: nt/gaussian_integers.hpp
    title: nt/gaussian_integers.hpp
  - icon: ':heavy_check_mark:'
    path: nt/lcm.hpp
    title: nt/lcm.hpp
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/library_checker/math/binomial_coefficient.test.cpp
    title: test/library_checker/math/binomial_coefficient.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/library_checker/math/kth_root_mod.test.cpp
    title: test/library_checker/math/kth_root_mod.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/library_checker/math/primitive_root.test.cpp
    title: test/library_checker/math/primitive_root.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/library_checker/math/tetration.test.cpp
    title: test/library_checker/math/tetration.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/library_checker/matrix/det_mod.test.cpp
    title: test/library_checker/matrix/det_mod.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/library_checker/matrix/matrix_det.test.cpp
    title: test/library_checker/matrix/matrix_det.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/yukicoder/1025.test.cpp
    title: test/yukicoder/1025.test.cpp
  - icon: ':x:'
    path: test/yukicoder/1303.test.cpp
    title: test/yukicoder/1303.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/yukicoder/1593.test.cpp
    title: test/yukicoder/1593.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/yukicoder/187.test.cpp
    title: test/yukicoder/187.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/yukicoder/1956.test.cpp
    title: test/yukicoder/1956.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/yukicoder/2119.test.cpp
    title: test/yukicoder/2119.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/yukicoder/2120.test.cpp
    title: test/yukicoder/2120.test.cpp
  - icon: ':x:'
    path: test/yukicoder/590.test.cpp
    title: test/yukicoder/590.test.cpp
  _isVerificationFailed: true
  _pathExtension: hpp
  _verificationStatusIcon: ':question:'
  attributes:
    links:
    - https://judge.yosupo.jp/submission/46090
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
    \ * m};\r\n  }\r\n\r\n  int m;\r\n  int s;\r\n  u64 x;\r\n};\r\n"
  code: "#pragma once\r\nstruct fast_div {\r\n  // Min25 https://judge.yosupo.jp/submission/46090\r\
    \n  // \u540C\u3058\u5B9A\u6570\u3067\u4F55\u5EA6\u3082\u9664\u7B97\u3059\u308B\
    \u3068\u304D\u306E\u9AD8\u901F\u5316\u306B\u4F7F\u3048\u308B\r\n  using i64 =\
    \ long long;\r\n  using u64 = unsigned long long;\r\n  using u128 = __uint128_t;\r\
    \n  constexpr fast_div() : m(), s(), x() {}\r\n  constexpr fast_div(int n)\r\n\
    \      : m(n), s(std::__lg(n - 1)), x(((u128(1) << (s + 64)) + n - 1) / n) {}\r\
    \n  constexpr friend u64 operator/(u64 n, const fast_div& d) {\r\n    return (u128(n)\
    \ * d.x >> d.s) >> 64;\r\n  }\r\n  constexpr friend int operator%(u64 n, const\
    \ fast_div& d) {\r\n    return n - n / d * d.m;\r\n  }\r\n  constexpr std::pair<i64,\
    \ int> divmod(u64 n) const {\r\n    u64 q = n / *this;\r\n    return {q, n - q\
    \ * m};\r\n  }\r\n\r\n  int m;\r\n  int s;\r\n  u64 x;\r\n};\r\n"
  dependsOn: []
  isVerificationFile: false
  path: mod/fast_div.hpp
  requiredBy:
  - mod/binomial.hpp
  - mod/tetration.hpp
  - mod/mod_kth_root.hpp
  - mod/mod_pow.hpp
  - mod/primitive_root.hpp
  - nt/gaussian_integers.hpp
  - nt/lcm.hpp
  - nt/crt.hpp
  - linalg/det_mod.hpp
  - linalg/det.hpp
  timestamp: '2022-05-12 00:26:23+09:00'
  verificationStatus: LIBRARY_SOME_WA
  verifiedWith:
  - test/yukicoder/187.test.cpp
  - test/yukicoder/1025.test.cpp
  - test/yukicoder/590.test.cpp
  - test/yukicoder/1956.test.cpp
  - test/yukicoder/1303.test.cpp
  - test/yukicoder/2119.test.cpp
  - test/yukicoder/1593.test.cpp
  - test/yukicoder/2120.test.cpp
  - test/library_checker/math/kth_root_mod.test.cpp
  - test/library_checker/math/tetration.test.cpp
  - test/library_checker/math/primitive_root.test.cpp
  - test/library_checker/math/binomial_coefficient.test.cpp
  - test/library_checker/matrix/det_mod.test.cpp
  - test/library_checker/matrix/matrix_det.test.cpp
documentation_of: mod/fast_div.hpp
layout: document
redirect_from:
- /library/mod/fast_div.hpp
- /library/mod/fast_div.hpp.html
title: mod/fast_div.hpp
---
