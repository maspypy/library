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
  bundledCode: "#line 1 \"alg/monoid/and.hpp\"\n\ntemplate <typename X>\nstruct Monoid_And\
    \ {\n  using value_type = X;\n  static X op(X x, X y) { return x & y; }\n  static\
    \ constexpr X unit() { return X(-1); };\n  static constexpr bool commute = true;\n\
    };\n"
  code: "\ntemplate <typename X>\nstruct Monoid_And {\n  using value_type = X;\n \
    \ static X op(X x, X y) { return x & y; }\n  static constexpr X unit() { return\
    \ X(-1); };\n  static constexpr bool commute = true;\n};\n"
  dependsOn: []
  isVerificationFile: false
  path: alg/monoid/and.hpp
  requiredBy: []
  timestamp: '2026-08-16 04:03:00+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: alg/monoid/and.hpp
layout: document
redirect_from:
- /library/alg/monoid/and.hpp
- /library/alg/monoid/and.hpp.html
title: alg/monoid/and.hpp
---
