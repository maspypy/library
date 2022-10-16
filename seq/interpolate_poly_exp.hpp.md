---
data:
  _extendedDependsOn: []
  _extendedRequiredBy:
  - icon: ':heavy_check_mark:'
    path: seq/interpolate_poly_exp_sum.hpp
    title: seq/interpolate_poly_exp_sum.hpp
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/library_checker/math/sum_of_exp_times_poly.test.cpp
    title: test/library_checker/math/sum_of_exp_times_poly.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 1 \"seq/interpolate_poly_exp.hpp\"\ntemplate <typename mint>\r\
    \nmint interpolate_poly_exp(vc<mint> a, mint r, ll n) {\r\n  // a[i] = r^i * (polynomial\
    \ of i) \u3068\u306A\u3063\u3066\u3044\u308B\u5834\u5408\u306E\u88DC\u9593\r\n\
    \  if (r == 0) return (n == 0 ? a[0] : 0);\r\n  mint inv_r = mint(1) / r;\r\n\
    \  mint p = 1;\r\n  for (auto&& x: a) {\r\n    x *= p;\r\n    p *= inv_r;\r\n\
    \  }\r\n  return lagrange_interpolate_iota(a, mint(n)) * r.pow(n);\r\n}\r\n"
  code: "template <typename mint>\r\nmint interpolate_poly_exp(vc<mint> a, mint r,\
    \ ll n) {\r\n  // a[i] = r^i * (polynomial of i) \u3068\u306A\u3063\u3066\u3044\
    \u308B\u5834\u5408\u306E\u88DC\u9593\r\n  if (r == 0) return (n == 0 ? a[0] :\
    \ 0);\r\n  mint inv_r = mint(1) / r;\r\n  mint p = 1;\r\n  for (auto&& x: a) {\r\
    \n    x *= p;\r\n    p *= inv_r;\r\n  }\r\n  return lagrange_interpolate_iota(a,\
    \ mint(n)) * r.pow(n);\r\n}\r\n"
  dependsOn: []
  isVerificationFile: false
  path: seq/interpolate_poly_exp.hpp
  requiredBy:
  - seq/interpolate_poly_exp_sum.hpp
  timestamp: '2022-04-16 04:26:49+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/library_checker/math/sum_of_exp_times_poly.test.cpp
documentation_of: seq/interpolate_poly_exp.hpp
layout: document
redirect_from:
- /library/seq/interpolate_poly_exp.hpp
- /library/seq/interpolate_poly_exp.hpp.html
title: seq/interpolate_poly_exp.hpp
---
