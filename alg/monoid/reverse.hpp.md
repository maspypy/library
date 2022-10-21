---
data:
  _extendedDependsOn: []
  _extendedRequiredBy:
  - icon: ':heavy_check_mark:'
    path: graph/ds/statictreemonoid.hpp
    title: graph/ds/statictreemonoid.hpp
  - icon: ':heavy_check_mark:'
    path: graph/ds/treemonoid.hpp
    title: graph/ds/treemonoid.hpp
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/yukicoder/1212.test.cpp
    title: test/yukicoder/1212.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/yukicoder/1216.test.cpp
    title: test/yukicoder/1216.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/yukicoder/1216_2.test.cpp
    title: test/yukicoder/1216_2.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 2 \"alg/monoid/reverse.hpp\"\ntemplate <class Monoid>\r\nstruct\
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
  path: alg/monoid/reverse.hpp
  requiredBy:
  - graph/ds/treemonoid.hpp
  - graph/ds/statictreemonoid.hpp
  timestamp: '2022-10-21 16:22:09+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/yukicoder/1212.test.cpp
  - test/yukicoder/1216_2.test.cpp
  - test/yukicoder/1216.test.cpp
documentation_of: alg/monoid/reverse.hpp
layout: document
redirect_from:
- /library/alg/monoid/reverse.hpp
- /library/alg/monoid/reverse.hpp.html
title: alg/monoid/reverse.hpp
---
