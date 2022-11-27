---
data:
  _extendedDependsOn: []
  _extendedRequiredBy:
  - icon: ':x:'
    path: alg/lazy/reverse.hpp
    title: alg/lazy/reverse.hpp
  - icon: ':x:'
    path: graph/ds/lazytreemonoid.hpp
    title: graph/ds/lazytreemonoid.hpp
  _extendedVerifiedWith:
  - icon: ':x:'
    path: test/aoj/GRL_5_E.test.cpp
    title: test/aoj/GRL_5_E.test.cpp
  - icon: ':x:'
    path: test/yukicoder/1197.test.cpp
    title: test/yukicoder/1197.test.cpp
  - icon: ':x:'
    path: test/yukicoder/235.test.cpp
    title: test/yukicoder/235.test.cpp
  _isVerificationFailed: true
  _pathExtension: hpp
  _verificationStatusIcon: ':x:'
  attributes:
    links: []
  bundledCode: "#line 2 \"alg/monoid/reverse_monoid.hpp\"\ntemplate <class Monoid>\r\
    \nstruct Monoid_Reverse {\r\n  using value_type = typename Monoid::value_type;\r\
    \n  using X = value_type;\r\n  static constexpr X op(const X &x, const X &y) {\
    \ return Monoid::op(y, x); }\r\n  static constexpr X unit() { return Monoid::unit();\
    \ }\r\n  static const bool commute = Monoid::commute;\r\n};\r\n"
  code: "#pragma once\r\ntemplate <class Monoid>\r\nstruct Monoid_Reverse {\r\n  using\
    \ value_type = typename Monoid::value_type;\r\n  using X = value_type;\r\n  static\
    \ constexpr X op(const X &x, const X &y) { return Monoid::op(y, x); }\r\n  static\
    \ constexpr X unit() { return Monoid::unit(); }\r\n  static const bool commute\
    \ = Monoid::commute;\r\n};\r\n"
  dependsOn: []
  isVerificationFile: false
  path: alg/monoid/reverse_monoid.hpp
  requiredBy:
  - alg/lazy/reverse.hpp
  - graph/ds/lazytreemonoid.hpp
  timestamp: '2022-11-27 13:06:40+09:00'
  verificationStatus: LIBRARY_ALL_WA
  verifiedWith:
  - test/yukicoder/235.test.cpp
  - test/yukicoder/1197.test.cpp
  - test/aoj/GRL_5_E.test.cpp
documentation_of: alg/monoid/reverse_monoid.hpp
layout: document
redirect_from:
- /library/alg/monoid/reverse_monoid.hpp
- /library/alg/monoid/reverse_monoid.hpp.html
title: alg/monoid/reverse_monoid.hpp
---
