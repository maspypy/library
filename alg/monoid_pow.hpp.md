---
data:
  _extendedDependsOn: []
  _extendedRequiredBy:
  - icon: ':heavy_check_mark:'
    path: mod/floor_monoid_product.hpp
    title: mod/floor_monoid_product.hpp
  - icon: ':heavy_check_mark:'
    path: mod/floor_sum_of_linear_polynomial.hpp
    title: mod/floor_sum_of_linear_polynomial.hpp
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/library_checker/math/sum_of_floor_of_linear_2.test.cpp
    title: test/library_checker/math/sum_of_floor_of_linear_2.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/mytest/floor_sum_of_polynomial.test.cpp
    title: test/mytest/floor_sum_of_polynomial.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/yukicoder/2362.test.cpp
    title: test/yukicoder/2362.test.cpp
  - icon: ':heavy_check_mark:'
    path: test_atcoder/abc200f.test.cpp
    title: test_atcoder/abc200f.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 2 \"alg/monoid_pow.hpp\"\n\ntemplate <typename Monoid>\ntypename\
    \ Monoid::X monoid_pow(typename Monoid::X x, u64 exp) {\n  using X = typename\
    \ Monoid::X;\n  assert(exp >= 0);\n  X res = Monoid::unit();\n  while (exp) {\n\
    \    if (exp & 1) res = Monoid::op(res, x);\n    x = Monoid::op(x, x);\n    exp\
    \ >>= 1;\n  }\n  return res;\n}\n"
  code: "#pragma once\n\ntemplate <typename Monoid>\ntypename Monoid::X monoid_pow(typename\
    \ Monoid::X x, u64 exp) {\n  using X = typename Monoid::X;\n  assert(exp >= 0);\n\
    \  X res = Monoid::unit();\n  while (exp) {\n    if (exp & 1) res = Monoid::op(res,\
    \ x);\n    x = Monoid::op(x, x);\n    exp >>= 1;\n  }\n  return res;\n}"
  dependsOn: []
  isVerificationFile: false
  path: alg/monoid_pow.hpp
  requiredBy:
  - mod/floor_monoid_product.hpp
  - mod/floor_sum_of_linear_polynomial.hpp
  timestamp: '2023-11-23 14:15:12+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/library_checker/math/sum_of_floor_of_linear_2.test.cpp
  - test/mytest/floor_sum_of_polynomial.test.cpp
  - test/yukicoder/2362.test.cpp
  - test_atcoder/abc200f.test.cpp
documentation_of: alg/monoid_pow.hpp
layout: document
redirect_from:
- /library/alg/monoid_pow.hpp
- /library/alg/monoid_pow.hpp.html
title: alg/monoid_pow.hpp
---
