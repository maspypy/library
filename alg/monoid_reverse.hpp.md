---
data:
  _extendedDependsOn: []
  _extendedRequiredBy:
  - icon: ':x:'
    path: alg/lazy_reverse.hpp
    title: alg/lazy_reverse.hpp
  - icon: ':x:'
    path: graph/lazytreemonoid.hpp
    title: graph/lazytreemonoid.hpp
  _extendedVerifiedWith:
  - icon: ':x:'
    path: test/aoj/GRL_5_E_lazytreemonoid.test.cpp
    title: test/aoj/GRL_5_E_lazytreemonoid.test.cpp
  _isVerificationFailed: true
  _pathExtension: hpp
  _verificationStatusIcon: ':x:'
  attributes:
    links: []
  bundledCode: "#line 2 \"alg/monoid_reverse.hpp\"\ntemplate <class Monoid>\r\nstruct\
    \ Monoid_Reverse {\r\n  using value_type = typename Monoid::value_type;\r\n  using\
    \ X = value_type;\r\n  static constexpr X op(const X &x, const X &y) { return\
    \ Monoid::op(y, x); }\r\n  static constexpr X unit() { return Monoid::unit();\
    \ }\r\n  static const bool commute = Monoid::commute;\r\n};\r\n"
  code: "#pragma once\r\ntemplate <class Monoid>\r\nstruct Monoid_Reverse {\r\n  using\
    \ value_type = typename Monoid::value_type;\r\n  using X = value_type;\r\n  static\
    \ constexpr X op(const X &x, const X &y) { return Monoid::op(y, x); }\r\n  static\
    \ constexpr X unit() { return Monoid::unit(); }\r\n  static const bool commute\
    \ = Monoid::commute;\r\n};\r\n"
  dependsOn: []
  isVerificationFile: false
  path: alg/monoid_reverse.hpp
  requiredBy:
  - graph/lazytreemonoid.hpp
  - alg/lazy_reverse.hpp
  timestamp: '2022-04-23 17:49:11+09:00'
  verificationStatus: LIBRARY_ALL_WA
  verifiedWith:
  - test/aoj/GRL_5_E_lazytreemonoid.test.cpp
documentation_of: alg/monoid_reverse.hpp
layout: document
redirect_from:
- /library/alg/monoid_reverse.hpp
- /library/alg/monoid_reverse.hpp.html
title: alg/monoid_reverse.hpp
---
