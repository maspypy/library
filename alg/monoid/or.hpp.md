---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/3_yukicoder/866.test.cpp
    title: test/3_yukicoder/866.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 1 \"alg/monoid/or.hpp\"\n\ntemplate <typename X>\nstruct Monoid_Or\
    \ {\n  using value_type = X;\n  static X op(X x, X y) { return x | y; }\n  static\
    \ constexpr X id(){return X(0);};\n  static constexpr bool commute = true;\n};\n"
  code: "\ntemplate <typename X>\nstruct Monoid_Or {\n  using value_type = X;\n  static\
    \ X op(X x, X y) { return x | y; }\n  static constexpr X id(){return X(0);};\n\
    \  static constexpr bool commute = true;\n};\n"
  dependsOn: []
  isVerificationFile: false
  path: alg/monoid/or.hpp
  requiredBy: []
  timestamp: '2026-08-30 21:09:36+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/3_yukicoder/866.test.cpp
documentation_of: alg/monoid/or.hpp
layout: document
redirect_from:
- /library/alg/monoid/or.hpp
- /library/alg/monoid/or.hpp.html
title: alg/monoid/or.hpp
---
