---
data:
  _extendedDependsOn: []
  _extendedRequiredBy:
  - icon: ':heavy_check_mark:'
    path: alg/acted_monoid/cntsummax_add.hpp
    title: alg/acted_monoid/cntsummax_add.hpp
  - icon: ':heavy_check_mark:'
    path: alg/acted_monoid/cntsummax_assign.hpp
    title: alg/acted_monoid/cntsummax_assign.hpp
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/mytest/cntsummax_add.test.cpp
    title: test/mytest/cntsummax_add.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/mytest/cntsummax_assign.test.cpp
    title: test/mytest/cntsummax_assign.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 2 \"alg/monoid/cntsummax.hpp\"\n\r\ntemplate <typename E>\r\n\
    struct Monoid_CntSumMax {\r\n  using value_type = tuple<E, E, E>;\r\n  using X\
    \ = value_type;\r\n  static X op(X x, X y) {\r\n    auto [xc, xs, xm] = x;\r\n\
    \    auto [yc, ys, ym] = y;\r\n    return {xc + yc, xs + ys, max(xm, ym)};\r\n\
    \  }\r\n  static X from_element(E x) { return {1, x, x}; }\r\n  static constexpr\
    \ X unit() { return {0, 0, numeric_limits<ll>::lowest()}; }\r\n  static constexpr\
    \ bool commute = true;\r\n};\r\n"
  code: "#pragma once\r\n\r\ntemplate <typename E>\r\nstruct Monoid_CntSumMax {\r\n\
    \  using value_type = tuple<E, E, E>;\r\n  using X = value_type;\r\n  static X\
    \ op(X x, X y) {\r\n    auto [xc, xs, xm] = x;\r\n    auto [yc, ys, ym] = y;\r\
    \n    return {xc + yc, xs + ys, max(xm, ym)};\r\n  }\r\n  static X from_element(E\
    \ x) { return {1, x, x}; }\r\n  static constexpr X unit() { return {0, 0, numeric_limits<ll>::lowest()};\
    \ }\r\n  static constexpr bool commute = true;\r\n};\r\n"
  dependsOn: []
  isVerificationFile: false
  path: alg/monoid/cntsummax.hpp
  requiredBy:
  - alg/acted_monoid/cntsummax_assign.hpp
  - alg/acted_monoid/cntsummax_add.hpp
  timestamp: '2022-11-27 22:15:30+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/mytest/cntsummax_assign.test.cpp
  - test/mytest/cntsummax_add.test.cpp
documentation_of: alg/monoid/cntsummax.hpp
layout: document
redirect_from:
- /library/alg/monoid/cntsummax.hpp
- /library/alg/monoid/cntsummax.hpp.html
title: alg/monoid/cntsummax.hpp
---
