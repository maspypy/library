---
data:
  _extendedDependsOn: []
  _extendedRequiredBy:
  - icon: ':warning:'
    path: setfunc/boolean_range_add_point_get.hpp
    title: setfunc/boolean_range_add_point_get.hpp
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/3_yukicoder/1602.test.cpp
    title: test/3_yukicoder/1602.test.cpp
  - icon: ':x:'
    path: test/3_yukicoder/1641.test.cpp
    title: test/3_yukicoder/1641.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/3_yukicoder/1790.test.cpp
    title: test/3_yukicoder/1790.test.cpp
  - icon: ':x:'
    path: test/3_yukicoder/2293.test.cpp
    title: test/3_yukicoder/2293.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/3_yukicoder/2294.test.cpp
    title: test/3_yukicoder/2294.test.cpp
  _isVerificationFailed: true
  _pathExtension: hpp
  _verificationStatusIcon: ':question:'
  attributes:
    links: []
  bundledCode: "#line 1 \"alg/monoid/xor.hpp\"\n\ntemplate <typename X>\nstruct Monoid_Xor\
    \ {\n  using value_type = X;\n  static X op(X x, X y) { return x ^ y; }\n  static\
    \ constexpr X inverse(const X &x) noexcept { return x; }\n  static constexpr X\
    \ power(const X &x, ll n) noexcept {\n    return (n & 1 ? x : 0);\n  }\n  static\
    \ constexpr X unit(){return X(0);};\n  static constexpr bool commute = true;\n\
    };\n"
  code: "\ntemplate <typename X>\nstruct Monoid_Xor {\n  using value_type = X;\n \
    \ static X op(X x, X y) { return x ^ y; }\n  static constexpr X inverse(const\
    \ X &x) noexcept { return x; }\n  static constexpr X power(const X &x, ll n) noexcept\
    \ {\n    return (n & 1 ? x : 0);\n  }\n  static constexpr X unit(){return X(0);};\n\
    \  static constexpr bool commute = true;\n};\n"
  dependsOn: []
  isVerificationFile: false
  path: alg/monoid/xor.hpp
  requiredBy:
  - setfunc/boolean_range_add_point_get.hpp
  timestamp: '2026-08-16 04:03:00+09:00'
  verificationStatus: LIBRARY_SOME_WA
  verifiedWith:
  - test/3_yukicoder/2294.test.cpp
  - test/3_yukicoder/1602.test.cpp
  - test/3_yukicoder/1790.test.cpp
  - test/3_yukicoder/2293.test.cpp
  - test/3_yukicoder/1641.test.cpp
documentation_of: alg/monoid/xor.hpp
layout: document
redirect_from:
- /library/alg/monoid/xor.hpp
- /library/alg/monoid/xor.hpp.html
title: alg/monoid/xor.hpp
---
