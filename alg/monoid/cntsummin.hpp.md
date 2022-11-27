---
data:
  _extendedDependsOn: []
  _extendedRequiredBy:
  - icon: ':warning:'
    path: alg/lazy/cntsummin_add.hpp
    title: alg/lazy/cntsummin_add.hpp
  - icon: ':warning:'
    path: alg/lazy/cntsummin_set.hpp
    title: alg/lazy/cntsummin_set.hpp
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':warning:'
  attributes:
    links: []
  bundledCode: "#line 2 \"alg/monoid/cntsummin.hpp\"\n\r\nstruct Monoid_CntSumMin\
    \ {\r\n  using value_type = tuple<ll, ll, ll>;\r\n  using X = value_type;\r\n\
    \  static X op(X x, X y) {\r\n    auto [xc, xs, xm] = x;\r\n    auto [yc, ys,\
    \ ym] = y;\r\n    return {xc + yc, xs + ys, min(xm, ym)};\r\n  }\r\n  static constexpr\
    \ X unit() { return {0, 0, numeric_limits<ll>::max()}; }\r\n  static constexpr\
    \ bool commute = true;\r\n};\r\n"
  code: "#pragma once\r\n\r\nstruct Monoid_CntSumMin {\r\n  using value_type = tuple<ll,\
    \ ll, ll>;\r\n  using X = value_type;\r\n  static X op(X x, X y) {\r\n    auto\
    \ [xc, xs, xm] = x;\r\n    auto [yc, ys, ym] = y;\r\n    return {xc + yc, xs +\
    \ ys, min(xm, ym)};\r\n  }\r\n  static constexpr X unit() { return {0, 0, numeric_limits<ll>::max()};\
    \ }\r\n  static constexpr bool commute = true;\r\n};\r\n"
  dependsOn: []
  isVerificationFile: false
  path: alg/monoid/cntsummin.hpp
  requiredBy:
  - alg/lazy/cntsummin_add.hpp
  - alg/lazy/cntsummin_set.hpp
  timestamp: '2022-10-21 16:22:09+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: alg/monoid/cntsummin.hpp
layout: document
redirect_from:
- /library/alg/monoid/cntsummin.hpp
- /library/alg/monoid/cntsummin.hpp.html
title: alg/monoid/cntsummin.hpp
---
