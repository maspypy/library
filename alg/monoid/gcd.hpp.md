---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/yukicoder/1036.test.cpp
    title: test/yukicoder/1036.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/yukicoder/1036_2.test.cpp
    title: test/yukicoder/1036_2.test.cpp
  - icon: ':x:'
    path: test/yukicoder/1036_3.test.cpp
    title: test/yukicoder/1036_3.test.cpp
  _isVerificationFailed: true
  _pathExtension: hpp
  _verificationStatusIcon: ':question:'
  attributes:
    links: []
  bundledCode: "#line 2 \"alg/monoid/gcd.hpp\"\n\ntemplate <typename X>\nstruct Monoid_Gcd\
    \ {\n  using value_type = X;\n  static X op(X x, X y) { return gcd(x, y); }\n\
    \  static constexpr X unit() { return 0; }\n  static constexpr bool commute =\
    \ true;\n};\n"
  code: "#pragma once\n\ntemplate <typename X>\nstruct Monoid_Gcd {\n  using value_type\
    \ = X;\n  static X op(X x, X y) { return gcd(x, y); }\n  static constexpr X unit()\
    \ { return 0; }\n  static constexpr bool commute = true;\n};\n"
  dependsOn: []
  isVerificationFile: false
  path: alg/monoid/gcd.hpp
  requiredBy: []
  timestamp: '2022-12-01 09:04:06+09:00'
  verificationStatus: LIBRARY_SOME_WA
  verifiedWith:
  - test/yukicoder/1036_2.test.cpp
  - test/yukicoder/1036.test.cpp
  - test/yukicoder/1036_3.test.cpp
documentation_of: alg/monoid/gcd.hpp
layout: document
redirect_from:
- /library/alg/monoid/gcd.hpp
- /library/alg/monoid/gcd.hpp.html
title: alg/monoid/gcd.hpp
---
