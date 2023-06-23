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
  bundledCode: "#line 2 \"alg/monoid/and.hpp\"\n\ntemplate <typename X>\nstruct Monoid_And\
    \ {\n  using value_type = X;\n  static X op(X x, X y) { return x & y; }\n  static\
    \ constexpr X unit() { return X(-1); };\n  static constexpr bool commute = true;\n\
    };\n"
  code: "#pragma once\n\ntemplate <typename X>\nstruct Monoid_And {\n  using value_type\
    \ = X;\n  static X op(X x, X y) { return x & y; }\n  static constexpr X unit()\
    \ { return X(-1); };\n  static constexpr bool commute = true;\n};\n"
  dependsOn: []
  isVerificationFile: false
  path: alg/monoid/and.hpp
  requiredBy: []
  timestamp: '2023-06-23 23:21:15+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: alg/monoid/and.hpp
layout: document
redirect_from:
- /library/alg/monoid/and.hpp
- /library/alg/monoid/and.hpp.html
title: alg/monoid/and.hpp
---
