---
data:
  _extendedDependsOn:
  - icon: ':question:'
    path: alg/monoid/assign.hpp
    title: alg/monoid/assign.hpp
  - icon: ':heavy_check_mark:'
    path: alg/monoid/summax.hpp
    title: alg/monoid/summax.hpp
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/1_mytest/dynamic_lazy_segtree.test.cpp
    title: test/1_mytest/dynamic_lazy_segtree.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/1_mytest/dynamic_lazy_segtree_persistent.test.cpp
    title: test/1_mytest/dynamic_lazy_segtree_persistent.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/1_mytest/summax_assign.test.cpp
    title: test/1_mytest/summax_assign.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links:
    - https://github.com/maspypy/library/blob/main/alg/acted_monoid/summax_assign.hpp
  bundledCode: "#line 1 \"alg/acted_monoid/summax_assign.hpp\"\n// Source: https://github.com/maspypy/library/blob/main/alg/acted_monoid/summax_assign.hpp\n\
    #line 1 \"alg/monoid/summax.hpp\"\n// Source: https://github.com/maspypy/library/blob/main/alg/monoid/summax.hpp\n\
    \ntemplate <typename E>\nstruct Monoid_SumMax {\n  using value_type = pair<E,\
    \ E>;\n  using X = value_type;\n  static X op(X x, X y) { return {x.fi + y.fi,\
    \ max(x.se, y.se)}; }\n  static X from_element(E e) { return {e, e}; }\n  static\
    \ constexpr X id() { return {E(0), -infty<E>}; }\n  static constexpr bool commute\
    \ = 1;\n};\n#line 1 \"alg/monoid/assign.hpp\"\n// Source: https://github.com/maspypy/library/blob/main/alg/monoid/assign.hpp\n\
    \ntemplate <typename X, int none_val>\nstruct Monoid_Assign {\n  using value_type\
    \ = X;\n  static X op(X x, X y) { return (y == X(none_val) ? x : y); }\n  static\
    \ constexpr X id() { return X(none_val); }\n  static constexpr bool commute =\
    \ false;\n};\n#line 4 \"alg/acted_monoid/summax_assign.hpp\"\n\ntemplate <typename\
    \ E, E none_val>\nstruct ActedMonoid_SumMax_Assign {\n  using Monoid_X = Monoid_SumMax<E>;\n\
    \  using Monoid_A = Monoid_Assign<E, none_val>;\n  using X = typename Monoid_X::value_type;\n\
    \  using A = typename Monoid_A::value_type;\n  static constexpr X act(const X&\
    \ x, const A& a, const ll& size) {\n    if (a == Monoid_A::id()) return x;\n \
    \   return {E(size) * a, a};\n  }\n};\n"
  code: "// Source: https://github.com/maspypy/library/blob/main/alg/acted_monoid/summax_assign.hpp\n\
    #include \"alg/monoid/summax.hpp\"\n#include \"alg/monoid/assign.hpp\"\n\ntemplate\
    \ <typename E, E none_val>\nstruct ActedMonoid_SumMax_Assign {\n  using Monoid_X\
    \ = Monoid_SumMax<E>;\n  using Monoid_A = Monoid_Assign<E, none_val>;\n  using\
    \ X = typename Monoid_X::value_type;\n  using A = typename Monoid_A::value_type;\n\
    \  static constexpr X act(const X& x, const A& a, const ll& size) {\n    if (a\
    \ == Monoid_A::id()) return x;\n    return {E(size) * a, a};\n  }\n};\n"
  dependsOn:
  - alg/monoid/summax.hpp
  - alg/monoid/assign.hpp
  isVerificationFile: false
  path: alg/acted_monoid/summax_assign.hpp
  requiredBy: []
  timestamp: '2026-10-15 19:54:56+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/1_mytest/dynamic_lazy_segtree.test.cpp
  - test/1_mytest/summax_assign.test.cpp
  - test/1_mytest/dynamic_lazy_segtree_persistent.test.cpp
documentation_of: alg/acted_monoid/summax_assign.hpp
layout: document
redirect_from:
- /library/alg/acted_monoid/summax_assign.hpp
- /library/alg/acted_monoid/summax_assign.hpp.html
title: alg/acted_monoid/summax_assign.hpp
---
