---
data:
  _extendedDependsOn: []
  _extendedRequiredBy:
  - icon: ':warning:'
    path: alg/lazy/powersums_set.hpp
    title: alg/lazy/powersums_set.hpp
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':warning:'
  attributes:
    links: []
  bundledCode: "#line 1 \"alg/monoid/set.hpp\"\ntemplate <typename E, E none_val>\r\
    \nstruct Monoid_Set {\r\n  using value_type = E;\r\n  using X = value_type;\r\n\
    \  static X op(X x, X y) { return (y == none_val ? x : y); }\r\n  static constexpr\
    \ X unit() { return none_val; }\r\n  static constexpr bool commute = false;\r\n\
    };\n"
  code: "template <typename E, E none_val>\r\nstruct Monoid_Set {\r\n  using value_type\
    \ = E;\r\n  using X = value_type;\r\n  static X op(X x, X y) { return (y == none_val\
    \ ? x : y); }\r\n  static constexpr X unit() { return none_val; }\r\n  static\
    \ constexpr bool commute = false;\r\n};"
  dependsOn: []
  isVerificationFile: false
  path: alg/monoid/set.hpp
  requiredBy:
  - alg/lazy/powersums_set.hpp
  timestamp: '2022-10-21 16:22:09+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: alg/monoid/set.hpp
layout: document
redirect_from:
- /library/alg/monoid/set.hpp
- /library/alg/monoid/set.hpp.html
title: alg/monoid/set.hpp
---
