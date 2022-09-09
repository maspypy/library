---
data:
  _extendedDependsOn:
  - icon: ':x:'
    path: alg/group_cntsum.hpp
    title: alg/group_cntsum.hpp
  - icon: ':x:'
    path: alg/monoid_set.hpp
    title: alg/monoid_set.hpp
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':x:'
    path: test/aoj/DSL_2_I.test.cpp
    title: test/aoj/DSL_2_I.test.cpp
  _isVerificationFailed: true
  _pathExtension: hpp
  _verificationStatusIcon: ':x:'
  attributes:
    links: []
  bundledCode: "#line 1 \"alg/group_cntsum.hpp\"\ntemplate <typename E = long long>\r\
    \nstruct Group_CntSum {\r\n  using value_type = pair<E, E>;\r\n  using X = value_type;\r\
    \n  static constexpr X op(const X &x, const X &y) {\r\n    return {x.fi + y.fi,\
    \ x.se + y.se};\r\n  }\r\n  static constexpr X inverse(const X &x) { return {-x.fi,\
    \ -x.se}; }\r\n  static constexpr X unit() { return {0, 0}; }\r\n  static constexpr\
    \ bool commute = true;\r\n};\r\n#line 1 \"alg/monoid_set.hpp\"\ntemplate <typename\
    \ E, E none_val>\r\nstruct Monoid_Set {\r\n  using value_type = E;\r\n  using\
    \ X = value_type;\r\n  static X op(X x, X y) { return (y == none_val ? x : y);\
    \ }\r\n  static constexpr X unit() { return none_val; }\r\n  static constexpr\
    \ bool commute = false;\r\n};\n#line 3 \"alg/lazy_cntsum_set.hpp\"\n\r\ntemplate\
    \ <typename E, E none_val>\r\nstruct Lazy_CntSum_Set {\r\n  using X_structure\
    \ = Group_CntSum<E>;\r\n  using A_structure = Monoid_Set<E, none_val>;\r\n  using\
    \ X = typename X_structure::value_type;\r\n  using A = typename A_structure::value_type;\r\
    \n  static constexpr X act(const X &x, const A &a) {\r\n    if (a == A_structure::unit())\
    \ return x;\r\n    return {x.fi, x.fi * a};\r\n  }\r\n};\n"
  code: "#include \"alg/group_cntsum.hpp\"\r\n#include \"alg/monoid_set.hpp\"\r\n\r\
    \ntemplate <typename E, E none_val>\r\nstruct Lazy_CntSum_Set {\r\n  using X_structure\
    \ = Group_CntSum<E>;\r\n  using A_structure = Monoid_Set<E, none_val>;\r\n  using\
    \ X = typename X_structure::value_type;\r\n  using A = typename A_structure::value_type;\r\
    \n  static constexpr X act(const X &x, const A &a) {\r\n    if (a == A_structure::unit())\
    \ return x;\r\n    return {x.fi, x.fi * a};\r\n  }\r\n};"
  dependsOn:
  - alg/group_cntsum.hpp
  - alg/monoid_set.hpp
  isVerificationFile: false
  path: alg/lazy_cntsum_set.hpp
  requiredBy: []
  timestamp: '2022-04-16 04:26:49+09:00'
  verificationStatus: LIBRARY_ALL_WA
  verifiedWith:
  - test/aoj/DSL_2_I.test.cpp
documentation_of: alg/lazy_cntsum_set.hpp
layout: document
redirect_from:
- /library/alg/lazy_cntsum_set.hpp
- /library/alg/lazy_cntsum_set.hpp.html
title: alg/lazy_cntsum_set.hpp
---
