---
data:
  _extendedDependsOn: []
  _extendedRequiredBy:
  - icon: ':warning:'
    path: alg/acted_monoid/cntsummin_add.hpp
    title: alg/acted_monoid/cntsummin_add.hpp
  - icon: ':x:'
    path: alg/acted_monoid/cntsummin_assign.hpp
    title: alg/acted_monoid/cntsummin_assign.hpp
  _extendedVerifiedWith:
  - icon: ':x:'
    path: test/mytest/cntsummin_assign.test.cpp
    title: test/mytest/cntsummin_assign.test.cpp
  _isVerificationFailed: true
  _pathExtension: hpp
  _verificationStatusIcon: ':x:'
  attributes:
    links: []
  bundledCode: "#line 2 \"alg/monoid/cntsummin.hpp\"\n\r\ntemplate <typename E>\r\n\
    struct Monoid_CntSumMin {\r\n  using value_type = tuple<E, E, E>;\r\n  using X\
    \ = value_type;\r\n  static X op(X x, X y) {\r\n    auto [xc, xs, xm] = x;\r\n\
    \    auto [yc, ys, ym] = y;\r\n    return {xc + yc, xs + ys, max(xm, ym)};\r\n\
    \  }\r\n  static X from_element(E x) { return {1, x, x}; }\r\n  static constexpr\
    \ X unit() { return {0, 0, numeric_limits<ll>::max()}; }\r\n  static constexpr\
    \ bool commute = true;\r\n};\r\n"
  code: "#pragma once\r\n\r\ntemplate <typename E>\r\nstruct Monoid_CntSumMin {\r\n\
    \  using value_type = tuple<E, E, E>;\r\n  using X = value_type;\r\n  static X\
    \ op(X x, X y) {\r\n    auto [xc, xs, xm] = x;\r\n    auto [yc, ys, ym] = y;\r\
    \n    return {xc + yc, xs + ys, max(xm, ym)};\r\n  }\r\n  static X from_element(E\
    \ x) { return {1, x, x}; }\r\n  static constexpr X unit() { return {0, 0, numeric_limits<ll>::max()};\
    \ }\r\n  static constexpr bool commute = true;\r\n};\r\n"
  dependsOn: []
  isVerificationFile: false
  path: alg/monoid/cntsummin.hpp
  requiredBy:
  - alg/acted_monoid/cntsummin_assign.hpp
  - alg/acted_monoid/cntsummin_add.hpp
  timestamp: '2022-11-27 22:15:30+09:00'
  verificationStatus: LIBRARY_ALL_WA
  verifiedWith:
  - test/mytest/cntsummin_assign.test.cpp
documentation_of: alg/monoid/cntsummin.hpp
layout: document
redirect_from:
- /library/alg/monoid/cntsummin.hpp
- /library/alg/monoid/cntsummin.hpp.html
title: alg/monoid/cntsummin.hpp
---
