---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: alg/monoid/add_pair.hpp
    title: alg/monoid/add_pair.hpp
  - icon: ':heavy_check_mark:'
    path: alg/monoid/assign.hpp
    title: alg/monoid/assign.hpp
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/aoj/DSL_2_I.test.cpp
    title: test/aoj/DSL_2_I.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 1 \"alg/monoid/add_pair.hpp\"\ntemplate <typename E>\r\nstruct\
    \ Monoid_Add_Pair {\r\n  using value_type = pair<E, E>;\r\n  using X = value_type;\r\
    \n  static constexpr X op(const X &x, const X &y) {\r\n    return {x.fi + y.fi,\
    \ x.se + y.se};\r\n  }\r\n  static constexpr X inverse(const X &x) { return {-x.fi,\
    \ -x.se}; }\r\n  static constexpr X unit() { return {0, 0}; }\r\n  static constexpr\
    \ bool commute = true;\r\n};\r\n#line 1 \"alg/monoid/assign.hpp\"\ntemplate <typename\
    \ X, X none_val>\r\nstruct Monoid_Assign {\r\n  using value_type = X;\r\n  static\
    \ X op(X x, X y) { return (y == none_val ? x : y); }\r\n  static constexpr X unit()\
    \ { return none_val; }\r\n  static constexpr bool commute = false;\r\n};\r\n#line\
    \ 3 \"alg/acted_monoid/cntsum_assign.hpp\"\n\r\ntemplate <typename E, E none_val>\r\
    \nstruct ActedMonoid_CntSum_Assign {\r\n  using Monoid_X = Monoid_Add_Pair<E>;\r\
    \n  using Monoid_A = Monoid_Assign<E, none_val>;\r\n  using X = typename Monoid_X::value_type;\r\
    \n  using A = typename Monoid_A::value_type;\r\n  static constexpr X act(const\
    \ X &x, const A &a) {\r\n    if (a == Monoid_A::unit()) return x;\r\n    return\
    \ {x.fi, x.fi * a};\r\n  }\r\n};\r\n"
  code: "#include \"alg/monoid/add_pair.hpp\"\r\n#include \"alg/monoid/assign.hpp\"\
    \r\n\r\ntemplate <typename E, E none_val>\r\nstruct ActedMonoid_CntSum_Assign\
    \ {\r\n  using Monoid_X = Monoid_Add_Pair<E>;\r\n  using Monoid_A = Monoid_Assign<E,\
    \ none_val>;\r\n  using X = typename Monoid_X::value_type;\r\n  using A = typename\
    \ Monoid_A::value_type;\r\n  static constexpr X act(const X &x, const A &a) {\r\
    \n    if (a == Monoid_A::unit()) return x;\r\n    return {x.fi, x.fi * a};\r\n\
    \  }\r\n};\r\n"
  dependsOn:
  - alg/monoid/add_pair.hpp
  - alg/monoid/assign.hpp
  isVerificationFile: false
  path: alg/acted_monoid/cntsum_assign.hpp
  requiredBy: []
  timestamp: '2022-11-28 18:54:34+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/aoj/DSL_2_I.test.cpp
documentation_of: alg/acted_monoid/cntsum_assign.hpp
layout: document
redirect_from:
- /library/alg/acted_monoid/cntsum_assign.hpp
- /library/alg/acted_monoid/cntsum_assign.hpp.html
title: alg/acted_monoid/cntsum_assign.hpp
---
