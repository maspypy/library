---
data:
  _extendedDependsOn: []
  _extendedRequiredBy:
  - icon: ':x:'
    path: alg/lazy/add_mul.hpp
    title: alg/lazy/add_mul.hpp
  - icon: ':heavy_check_mark:'
    path: mod/mod_log.hpp
    title: mod/mod_log.hpp
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/library_checker/math/discrete_logarithm_mod.test.cpp
    title: test/library_checker/math/discrete_logarithm_mod.test.cpp
  - icon: ':x:'
    path: test/yukicoder/899.test.cpp
    title: test/yukicoder/899.test.cpp
  _isVerificationFailed: true
  _pathExtension: hpp
  _verificationStatusIcon: ':question:'
  attributes:
    links: []
  bundledCode: "#line 2 \"alg/monoid/mul.hpp\"\n\r\ntemplate <class T>\r\nstruct Monoid_Mul\
    \ {\r\n  using value_type = T;\r\n  using X = T;\r\n  static constexpr X op(const\
    \ X &x, const X &y) noexcept { return x * y; }\r\n  static constexpr X inverse(const\
    \ X &x) noexcept { return X(1) / x; }\r\n  static constexpr X unit() { return\
    \ X(1); }\r\n  static constexpr bool commute = true;\r\n};\r\n"
  code: "#pragma once\r\n\r\ntemplate <class T>\r\nstruct Monoid_Mul {\r\n  using\
    \ value_type = T;\r\n  using X = T;\r\n  static constexpr X op(const X &x, const\
    \ X &y) noexcept { return x * y; }\r\n  static constexpr X inverse(const X &x)\
    \ noexcept { return X(1) / x; }\r\n  static constexpr X unit() { return X(1);\
    \ }\r\n  static constexpr bool commute = true;\r\n};\r\n"
  dependsOn: []
  isVerificationFile: false
  path: alg/monoid/mul.hpp
  requiredBy:
  - alg/lazy/add_mul.hpp
  - mod/mod_log.hpp
  timestamp: '2022-11-27 14:10:12+09:00'
  verificationStatus: LIBRARY_SOME_WA
  verifiedWith:
  - test/yukicoder/899.test.cpp
  - test/library_checker/math/discrete_logarithm_mod.test.cpp
documentation_of: alg/monoid/mul.hpp
layout: document
redirect_from:
- /library/alg/monoid/mul.hpp
- /library/alg/monoid/mul.hpp.html
title: alg/monoid/mul.hpp
---
