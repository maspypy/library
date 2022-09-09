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
  - icon: ':heavy_check_mark:'
    path: test/yukicoder/1036_3.test.cpp
    title: test/yukicoder/1036_3.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 1 \"alg/monoid_gcd.hpp\"\ntemplate <typename INT>\nstruct Monoid_Gcd\
    \ {\n  using value_type = INT;\n  using X = value_type;\n  static X op(X x, X\
    \ y) { return gcd(x, y); }\n  static constexpr X unit() { return 0; }\n  static\
    \ constexpr bool commute = true;\n};\n"
  code: "template <typename INT>\nstruct Monoid_Gcd {\n  using value_type = INT;\n\
    \  using X = value_type;\n  static X op(X x, X y) { return gcd(x, y); }\n  static\
    \ constexpr X unit() { return 0; }\n  static constexpr bool commute = true;\n\
    };\n"
  dependsOn: []
  isVerificationFile: false
  path: alg/monoid_gcd.hpp
  requiredBy: []
  timestamp: '2022-04-24 16:57:10+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/yukicoder/1036_2.test.cpp
  - test/yukicoder/1036_3.test.cpp
  - test/yukicoder/1036.test.cpp
documentation_of: alg/monoid_gcd.hpp
layout: document
redirect_from:
- /library/alg/monoid_gcd.hpp
- /library/alg/monoid_gcd.hpp.html
title: alg/monoid_gcd.hpp
---
