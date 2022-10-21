---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':warning:'
  attributes:
    links: []
  bundledCode: "#line 2 \"alg/monoid/cntsummax.hpp\"\n\r\nstruct Monoid_CntSumMax\
    \ {\r\n  using value_type = tuple<ll, ll, ll>;\r\n  using X = value_type;\r\n\
    \  static X op(X x, X y) {\r\n    auto [xc, xs, xm] = x;\r\n    auto [yc, ys,\
    \ ym] = y;\r\n    return {xc + yc, xs + ys, max(xm, ym)};\r\n  }\r\n  static constexpr\
    \ X unit() { return {0, 0, numeric_limits<ll>::lowest()}; }\r\n  static constexpr\
    \ bool commute = true;\r\n};\r\n"
  code: "#pragma once\r\n\r\nstruct Monoid_CntSumMax {\r\n  using value_type = tuple<ll,\
    \ ll, ll>;\r\n  using X = value_type;\r\n  static X op(X x, X y) {\r\n    auto\
    \ [xc, xs, xm] = x;\r\n    auto [yc, ys, ym] = y;\r\n    return {xc + yc, xs +\
    \ ys, max(xm, ym)};\r\n  }\r\n  static constexpr X unit() { return {0, 0, numeric_limits<ll>::lowest()};\
    \ }\r\n  static constexpr bool commute = true;\r\n};\r\n"
  dependsOn: []
  isVerificationFile: false
  path: alg/monoid/cntsummax.hpp
  requiredBy: []
  timestamp: '2022-10-21 16:22:09+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: alg/monoid/cntsummax.hpp
layout: document
redirect_from:
- /library/alg/monoid/cntsummax.hpp
- /library/alg/monoid/cntsummax.hpp.html
title: alg/monoid/cntsummax.hpp
---
