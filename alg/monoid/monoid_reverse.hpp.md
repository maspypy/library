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
  bundledCode: "#line 2 \"alg/monoid/monoid_reverse.hpp\"\ntemplate <class Monoid>\r\
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
  path: alg/monoid/monoid_reverse.hpp
  requiredBy: []
  timestamp: '2022-11-28 14:51:10+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: alg/monoid/monoid_reverse.hpp
layout: document
redirect_from:
- /library/alg/monoid/monoid_reverse.hpp
- /library/alg/monoid/monoid_reverse.hpp.html
title: alg/monoid/monoid_reverse.hpp
---
