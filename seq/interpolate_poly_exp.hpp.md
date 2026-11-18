---
data:
  _extendedDependsOn: []
  _extendedRequiredBy:
  - icon: ':x:'
    path: seq/interpolate_poly_exp_sum.hpp
    title: seq/interpolate_poly_exp_sum.hpp
  _extendedVerifiedWith:
  - icon: ':x:'
    path: test/2_library_checker/other/sum_of_exp_times_poly.test.cpp
    title: test/2_library_checker/other/sum_of_exp_times_poly.test.cpp
  _isVerificationFailed: true
  _pathExtension: hpp
  _verificationStatusIcon: ':x:'
  attributes:
    links:
    - https://github.com/maspypy/library/blob/main/seq/interpolate_poly_exp.hpp
  bundledCode: "#line 1 \"seq/interpolate_poly_exp.hpp\"\n// Source: https://github.com/maspypy/library/blob/main/seq/interpolate_poly_exp.hpp\n\
    template <typename mint>\nmint interpolate_poly_exp(vc<mint> a, mint r, ll n)\
    \ {\n  // a[i] = r^i * (polynomial of i) \u3068\u306A\u3063\u3066\u3044\u308B\u5834\
    \u5408\u306E\u88DC\u9593\n  if (r == 0) return (n == 0 ? a[0] : 0);\n  mint inv_r\
    \ = mint(1) / r;\n  mint p = 1;\n  for (auto&& x: a) {\n    x *= p;\n    p *=\
    \ inv_r;\n  }\n  return lagrange_interpolate_iota(a, mint(n)) * r.pow(n);\n}\n"
  code: "// Source: https://github.com/maspypy/library/blob/main/seq/interpolate_poly_exp.hpp\n\
    template <typename mint>\nmint interpolate_poly_exp(vc<mint> a, mint r, ll n)\
    \ {\n  // a[i] = r^i * (polynomial of i) \u3068\u306A\u3063\u3066\u3044\u308B\u5834\
    \u5408\u306E\u88DC\u9593\n  if (r == 0) return (n == 0 ? a[0] : 0);\n  mint inv_r\
    \ = mint(1) / r;\n  mint p = 1;\n  for (auto&& x: a) {\n    x *= p;\n    p *=\
    \ inv_r;\n  }\n  return lagrange_interpolate_iota(a, mint(n)) * r.pow(n);\n}\n"
  dependsOn: []
  isVerificationFile: false
  path: seq/interpolate_poly_exp.hpp
  requiredBy:
  - seq/interpolate_poly_exp_sum.hpp
  timestamp: '2026-10-15 19:54:56+09:00'
  verificationStatus: LIBRARY_ALL_WA
  verifiedWith:
  - test/2_library_checker/other/sum_of_exp_times_poly.test.cpp
documentation_of: seq/interpolate_poly_exp.hpp
layout: document
redirect_from:
- /library/seq/interpolate_poly_exp.hpp
- /library/seq/interpolate_poly_exp.hpp.html
title: seq/interpolate_poly_exp.hpp
---
