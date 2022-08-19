---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':x:'
    path: test/yukicoder/1036_dseg_minleft_maxright.test.cpp
    title: test/yukicoder/1036_dseg_minleft_maxright.test.cpp
  - icon: ':x:'
    path: test/yukicoder/1036_seg_maxright_minleft.test.cpp
    title: test/yukicoder/1036_seg_maxright_minleft.test.cpp
  - icon: ':x:'
    path: test/yukicoder/1036_swag.test.cpp
    title: test/yukicoder/1036_swag.test.cpp
  _isVerificationFailed: true
  _pathExtension: hpp
  _verificationStatusIcon: ':x:'
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
  verificationStatus: LIBRARY_ALL_WA
  verifiedWith:
  - test/yukicoder/1036_swag.test.cpp
  - test/yukicoder/1036_dseg_minleft_maxright.test.cpp
  - test/yukicoder/1036_seg_maxright_minleft.test.cpp
documentation_of: alg/monoid_gcd.hpp
layout: document
redirect_from:
- /library/alg/monoid_gcd.hpp
- /library/alg/monoid_gcd.hpp.html
title: alg/monoid_gcd.hpp
---
