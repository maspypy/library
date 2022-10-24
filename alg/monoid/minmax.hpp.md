---
data:
  _extendedDependsOn: []
  _extendedRequiredBy:
  - icon: ':warning:'
    path: alg/lazy/minmax_add.hpp
    title: alg/lazy/minmax_add.hpp
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/aoj/ITP2_3_B.test.cpp
    title: test/aoj/ITP2_3_B.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 2 \"alg/monoid/minmax.hpp\"\n\r\ntemplate <class X>\r\nstruct\
    \ Monoid_MinMax {\r\n  using P = pair<X, X>;\r\n  using value_type = P;\r\n  static\
    \ constexpr P op(const P x, const P y) noexcept {\r\n    return {min(x.fi, y.fi),\
    \ max(x.se, y.se)};\r\n  }\r\n  static constexpr P from_element(const X x) { return\
    \ {x, x}; }\r\n  static constexpr P unit() {\r\n    return {numeric_limits<X>::max(),\
    \ numeric_limits<X>::lowest()};\r\n  }\r\n  static constexpr bool commute = true;\r\
    \n};\r\n"
  code: "#pragma once\r\n\r\ntemplate <class X>\r\nstruct Monoid_MinMax {\r\n  using\
    \ P = pair<X, X>;\r\n  using value_type = P;\r\n  static constexpr P op(const\
    \ P x, const P y) noexcept {\r\n    return {min(x.fi, y.fi), max(x.se, y.se)};\r\
    \n  }\r\n  static constexpr P from_element(const X x) { return {x, x}; }\r\n \
    \ static constexpr P unit() {\r\n    return {numeric_limits<X>::max(), numeric_limits<X>::lowest()};\r\
    \n  }\r\n  static constexpr bool commute = true;\r\n};\r\n"
  dependsOn: []
  isVerificationFile: false
  path: alg/monoid/minmax.hpp
  requiredBy:
  - alg/lazy/minmax_add.hpp
  timestamp: '2022-10-21 16:22:09+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/aoj/ITP2_3_B.test.cpp
documentation_of: alg/monoid/minmax.hpp
layout: document
redirect_from:
- /library/alg/monoid/minmax.hpp
- /library/alg/monoid/minmax.hpp.html
title: alg/monoid/minmax.hpp
---
