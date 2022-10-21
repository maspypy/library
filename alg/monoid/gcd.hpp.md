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
  bundledCode: "#line 1 \"alg/monoid/gcd.hpp\"\ntemplate <typename INT>\nstruct Monoid_Gcd\
    \ {\n  using value_type = INT;\n  using X = value_type;\n  static X op(X x, X\
    \ y) { return gcd(x, y); }\n  static constexpr X unit() { return 0; }\n  static\
    \ constexpr bool commute = true;\n};\n"
  code: "template <typename INT>\nstruct Monoid_Gcd {\n  using value_type = INT;\n\
    \  using X = value_type;\n  static X op(X x, X y) { return gcd(x, y); }\n  static\
    \ constexpr X unit() { return 0; }\n  static constexpr bool commute = true;\n\
    };\n"
  dependsOn: []
  isVerificationFile: false
  path: alg/monoid/gcd.hpp
  requiredBy: []
  timestamp: '2022-10-21 16:22:09+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: alg/monoid/gcd.hpp
layout: document
redirect_from:
- /library/alg/monoid/gcd.hpp
- /library/alg/monoid/gcd.hpp.html
title: alg/monoid/gcd.hpp
---
