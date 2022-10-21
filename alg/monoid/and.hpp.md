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
  bundledCode: "#line 1 \"alg/monoid/and.hpp\"\ntemplate <typename E>\r\nstruct Monoid_And\
    \ {\r\n  using value_type = E;\r\n  using X = value_type;\r\n  static X op(X x,\
    \ X y) { return x & y; }\r\n  static constexpr X unit() { return numeric_limits<E>::max();\
    \ }\r\n  static constexpr bool commute = true;\r\n};\r\n"
  code: "template <typename E>\r\nstruct Monoid_And {\r\n  using value_type = E;\r\
    \n  using X = value_type;\r\n  static X op(X x, X y) { return x & y; }\r\n  static\
    \ constexpr X unit() { return numeric_limits<E>::max(); }\r\n  static constexpr\
    \ bool commute = true;\r\n};\r\n"
  dependsOn: []
  isVerificationFile: false
  path: alg/monoid/and.hpp
  requiredBy: []
  timestamp: '2022-10-21 16:22:09+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: alg/monoid/and.hpp
layout: document
redirect_from:
- /library/alg/monoid/and.hpp
- /library/alg/monoid/and.hpp.html
title: alg/monoid/and.hpp
---
