---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: alg/monoid/assign.hpp
    title: alg/monoid/assign.hpp
  - icon: ':heavy_check_mark:'
    path: alg/monoid/summax.hpp
    title: alg/monoid/summax.hpp
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/mytest/dynamic_lazy_segtree.test.cpp
    title: test/mytest/dynamic_lazy_segtree.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/mytest/dynamic_lazy_segtree_persistent.test.cpp
    title: test/mytest/dynamic_lazy_segtree_persistent.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/mytest/summax_assign.test.cpp
    title: test/mytest/summax_assign.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 2 \"alg/monoid/summax.hpp\"\n\ntemplate <typename E>\nstruct\
    \ Monoid_SumMax {\n  using value_type = pair<E, E>;\n  using X = value_type;\n\
    \  static X op(X x, X y) { return {x.fi + y.fi, max(x.se, y.se)}; }\n  static\
    \ X from_element(E e) { return {e, e}; }\n  static constexpr X unit() { return\
    \ {E(0), -infty<E>}; }\n  static constexpr bool commute = 1;\n};\n#line 2 \"alg/monoid/assign.hpp\"\
    \n\r\ntemplate <typename X, X none_val>\r\nstruct Monoid_Assign {\r\n  using value_type\
    \ = X;\r\n  static X op(X x, X y) { return (y == none_val ? x : y); }\r\n  static\
    \ constexpr X unit() { return none_val; }\r\n  static constexpr bool commute =\
    \ false;\r\n};\r\n#line 3 \"alg/acted_monoid/summax_assign.hpp\"\n\r\ntemplate\
    \ <typename E, E none_val>\r\nstruct ActedMonoid_SumMax_Assign {\r\n  using Monoid_X\
    \ = Monoid_SumMax<E>;\r\n  using Monoid_A = Monoid_Assign<E, none_val>;\r\n  using\
    \ X = typename Monoid_X::value_type;\r\n  using A = typename Monoid_A::value_type;\r\
    \n  static constexpr X act(const X& x, const A& a, const ll& size) {\r\n    if\
    \ (a == Monoid_A::unit()) return x;\r\n    return {E(size) * a, a};\r\n  }\r\n\
    };\r\n"
  code: "#include \"alg/monoid/summax.hpp\"\r\n#include \"alg/monoid/assign.hpp\"\r\
    \n\r\ntemplate <typename E, E none_val>\r\nstruct ActedMonoid_SumMax_Assign {\r\
    \n  using Monoid_X = Monoid_SumMax<E>;\r\n  using Monoid_A = Monoid_Assign<E,\
    \ none_val>;\r\n  using X = typename Monoid_X::value_type;\r\n  using A = typename\
    \ Monoid_A::value_type;\r\n  static constexpr X act(const X& x, const A& a, const\
    \ ll& size) {\r\n    if (a == Monoid_A::unit()) return x;\r\n    return {E(size)\
    \ * a, a};\r\n  }\r\n};\r\n"
  dependsOn:
  - alg/monoid/summax.hpp
  - alg/monoid/assign.hpp
  isVerificationFile: false
  path: alg/acted_monoid/summax_assign.hpp
  requiredBy: []
  timestamp: '2023-02-01 23:31:55+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/mytest/summax_assign.test.cpp
  - test/mytest/dynamic_lazy_segtree_persistent.test.cpp
  - test/mytest/dynamic_lazy_segtree.test.cpp
documentation_of: alg/acted_monoid/summax_assign.hpp
layout: document
redirect_from:
- /library/alg/acted_monoid/summax_assign.hpp
- /library/alg/acted_monoid/summax_assign.hpp.html
title: alg/acted_monoid/summax_assign.hpp
---
