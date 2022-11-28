---
data:
  _extendedDependsOn: []
  _extendedRequiredBy:
  - icon: ':warning:'
    path: alg/acted_monoid/cntsummin_assign.hpp
    title: alg/acted_monoid/cntsummin_assign.hpp
  - icon: ':warning:'
    path: alg/acted_monoid/max_assign.hpp
    title: alg/acted_monoid/max_assign.hpp
  - icon: ':warning:'
    path: alg/acted_monoid/min_assign.hpp
    title: alg/acted_monoid/min_assign.hpp
  - icon: ':warning:'
    path: alg/acted_monoid/powersums_assign.hpp
    title: alg/acted_monoid/powersums_assign.hpp
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':warning:'
  attributes:
    links: []
  bundledCode: "#line 1 \"alg/monoid/assign.hpp\"\ntemplate <typename X, X none_val>\r\
    \nstruct Monoid_Assign {\r\n  using value_type = X;\r\n  static X op(X x, X y)\
    \ { return (y == none_val ? x : y); }\r\n  static constexpr X unit() { return\
    \ none_val; }\r\n  static constexpr bool commute = false;\r\n};\r\n"
  code: "template <typename X, X none_val>\r\nstruct Monoid_Assign {\r\n  using value_type\
    \ = X;\r\n  static X op(X x, X y) { return (y == none_val ? x : y); }\r\n  static\
    \ constexpr X unit() { return none_val; }\r\n  static constexpr bool commute =\
    \ false;\r\n};\r\n"
  dependsOn: []
  isVerificationFile: false
  path: alg/monoid/assign.hpp
  requiredBy:
  - alg/acted_monoid/cntsummin_assign.hpp
  - alg/acted_monoid/max_assign.hpp
  - alg/acted_monoid/min_assign.hpp
  - alg/acted_monoid/powersums_assign.hpp
  timestamp: '2022-11-28 14:51:10+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: alg/monoid/assign.hpp
layout: document
redirect_from:
- /library/alg/monoid/assign.hpp
- /library/alg/monoid/assign.hpp.html
title: alg/monoid/assign.hpp
---
