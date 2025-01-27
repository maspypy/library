---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':x:'
    path: test/3_yukicoder/866.test.cpp
    title: test/3_yukicoder/866.test.cpp
  _isVerificationFailed: true
  _pathExtension: hpp
  _verificationStatusIcon: ':x:'
  attributes:
    links: []
  bundledCode: "#line 2 \"alg/monoid/or.hpp\"\n\r\ntemplate <typename X>\r\nstruct\
    \ Monoid_Or {\r\n  using value_type = X;\r\n  static X op(X x, X y) { return x\
    \ | y; }\r\n  static constexpr X unit(){return X(0);};\r\n  static constexpr bool\
    \ commute = true;\r\n};\r\n"
  code: "#pragma once\r\n\r\ntemplate <typename X>\r\nstruct Monoid_Or {\r\n  using\
    \ value_type = X;\r\n  static X op(X x, X y) { return x | y; }\r\n  static constexpr\
    \ X unit(){return X(0);};\r\n  static constexpr bool commute = true;\r\n};\r\n"
  dependsOn: []
  isVerificationFile: false
  path: alg/monoid/or.hpp
  requiredBy: []
  timestamp: '2022-12-15 05:38:31+09:00'
  verificationStatus: LIBRARY_ALL_WA
  verifiedWith:
  - test/3_yukicoder/866.test.cpp
documentation_of: alg/monoid/or.hpp
layout: document
redirect_from:
- /library/alg/monoid/or.hpp
- /library/alg/monoid/or.hpp.html
title: alg/monoid/or.hpp
---
