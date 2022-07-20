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
  bundledCode: "#line 1 \"alg/monoid_and.hpp\"\ntemplate <typename E>\r\nstruct Monoid_And\
    \ {\r\n  using value_type = E;\r\n  using X = value_type;\r\n  static X op(X x,\
    \ X y) { return x & y; }\r\n  static constexpr X unit() { return numeric_limits<E>::max();\
    \ }\r\n  static constexpr bool commute = true;\r\n};\r\n"
  code: "template <typename E>\r\nstruct Monoid_And {\r\n  using value_type = E;\r\
    \n  using X = value_type;\r\n  static X op(X x, X y) { return x & y; }\r\n  static\
    \ constexpr X unit() { return numeric_limits<E>::max(); }\r\n  static constexpr\
    \ bool commute = true;\r\n};\r\n"
  dependsOn: []
  isVerificationFile: false
  path: alg/monoid_and.hpp
  requiredBy: []
  timestamp: '2022-07-20 17:24:50+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: alg/monoid_and.hpp
layout: document
redirect_from:
- /library/alg/monoid_and.hpp
- /library/alg/monoid_and.hpp.html
title: alg/monoid_and.hpp
---
