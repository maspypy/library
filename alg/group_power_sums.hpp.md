---
data:
  _extendedDependsOn: []
  _extendedRequiredBy:
  - icon: ':heavy_check_mark:'
    path: alg/lazy_powersums_set.hpp
    title: alg/lazy_powersums_set.hpp
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/yukicoder/1548_power_sums.test.cpp
    title: test/yukicoder/1548_power_sums.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 2 \"alg/group_power_sums.hpp\"\n\r\n// 0 \u4E57\u548C\u304B\u3089\
    \ K-1 \u4E57\u548C\u307E\u3067\r\ntemplate <typename mint, int K>\r\nstruct Group_power_sums\
    \ {\r\n  using value_type = vc<mint>;\r\n  using X = value_type;\r\n  static X\
    \ op(X x, X y) {\r\n    vc<mint> z(K);\r\n    FOR(i, K) z[i] = x[i] + y[i];\r\n\
    \    return z;\r\n  }\r\n  static X from_element(mint x) {\r\n    vc<mint> a(K);\r\
    \n    a[0] = 1;\r\n    FOR(i, K - 1) a[i + 1] = a[i] * K;\r\n  }\r\n  static X\
    \ unit() { return vc<mint>(K, mint(0)); }\r\n  static constexpr bool commute =\
    \ 1;\r\n};\r\n"
  code: "#pragma once\r\n\r\n// 0 \u4E57\u548C\u304B\u3089 K-1 \u4E57\u548C\u307E\u3067\
    \r\ntemplate <typename mint, int K>\r\nstruct Group_power_sums {\r\n  using value_type\
    \ = vc<mint>;\r\n  using X = value_type;\r\n  static X op(X x, X y) {\r\n    vc<mint>\
    \ z(K);\r\n    FOR(i, K) z[i] = x[i] + y[i];\r\n    return z;\r\n  }\r\n  static\
    \ X from_element(mint x) {\r\n    vc<mint> a(K);\r\n    a[0] = 1;\r\n    FOR(i,\
    \ K - 1) a[i + 1] = a[i] * K;\r\n  }\r\n  static X unit() { return vc<mint>(K,\
    \ mint(0)); }\r\n  static constexpr bool commute = 1;\r\n};\r\n"
  dependsOn: []
  isVerificationFile: false
  path: alg/group_power_sums.hpp
  requiredBy:
  - alg/lazy_powersums_set.hpp
  timestamp: '2022-05-26 00:08:45+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/yukicoder/1548_power_sums.test.cpp
documentation_of: alg/group_power_sums.hpp
layout: document
redirect_from:
- /library/alg/group_power_sums.hpp
- /library/alg/group_power_sums.hpp.html
title: alg/group_power_sums.hpp
---
