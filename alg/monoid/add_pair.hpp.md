---
data:
  _extendedDependsOn: []
  _extendedRequiredBy:
  - icon: ':x:'
    path: alg/acted_monoid/cntsum_add.hpp
    title: alg/acted_monoid/cntsum_add.hpp
  - icon: ':heavy_check_mark:'
    path: alg/acted_monoid/cntsum_affine.hpp
    title: alg/acted_monoid/cntsum_affine.hpp
  - icon: ':heavy_check_mark:'
    path: convex/slope_trick/slope_super.hpp
    title: convex/slope_trick/slope_super.hpp
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/1_mytest/cf702_F.test.cpp
    title: test/1_mytest/cf702_F.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/1_mytest/cf702_F_splay.test.cpp
    title: test/1_mytest/cf702_F_splay.test.cpp
  - icon: ':x:'
    path: test/1_mytest/mo_on_tree.test.cpp
    title: test/1_mytest/mo_on_tree.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/1_mytest/slope_super.test.cpp
    title: test/1_mytest/slope_super.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/2_library_checker/data_structure/dynamic_point_rectangle_affine_rectangle_sum.test.cpp
    title: test/2_library_checker/data_structure/dynamic_point_rectangle_affine_rectangle_sum.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/3_yukicoder/1919.test.cpp
    title: test/3_yukicoder/1919.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/3_yukicoder/1919_2.test.cpp
    title: test/3_yukicoder/1919_2.test.cpp
  - icon: ':x:'
    path: test/3_yukicoder/235.test.cpp
    title: test/3_yukicoder/235.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/3_yukicoder/255.test.cpp
    title: test/3_yukicoder/255.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/3_yukicoder/2627.test.cpp
    title: test/3_yukicoder/2627.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/3_yukicoder/749.test.cpp
    title: test/3_yukicoder/749.test.cpp
  _isVerificationFailed: true
  _pathExtension: hpp
  _verificationStatusIcon: ':question:'
  attributes:
    links: []
  bundledCode: "#line 1 \"alg/monoid/add_pair.hpp\"\n\ntemplate <typename E>\nstruct\
    \ Monoid_Add_Pair {\n  using value_type = pair<E, E>;\n  using X = value_type;\n\
    \  static constexpr X op(const X &x, const X &y) {\n    return {x.fi + y.fi, x.se\
    \ + y.se};\n  }\n  static constexpr X inverse(const X &x) { return {-x.fi, -x.se};\
    \ }\n  static constexpr X unit() { return {0, 0}; }\n  static constexpr bool commute\
    \ = true;\n};\n"
  code: "\ntemplate <typename E>\nstruct Monoid_Add_Pair {\n  using value_type = pair<E,\
    \ E>;\n  using X = value_type;\n  static constexpr X op(const X &x, const X &y)\
    \ {\n    return {x.fi + y.fi, x.se + y.se};\n  }\n  static constexpr X inverse(const\
    \ X &x) { return {-x.fi, -x.se}; }\n  static constexpr X unit() { return {0, 0};\
    \ }\n  static constexpr bool commute = true;\n};\n"
  dependsOn: []
  isVerificationFile: false
  path: alg/monoid/add_pair.hpp
  requiredBy:
  - alg/acted_monoid/cntsum_affine.hpp
  - alg/acted_monoid/cntsum_add.hpp
  - convex/slope_trick/slope_super.hpp
  timestamp: '2026-08-16 04:03:00+09:00'
  verificationStatus: LIBRARY_SOME_WA
  verifiedWith:
  - test/1_mytest/cf702_F_splay.test.cpp
  - test/1_mytest/mo_on_tree.test.cpp
  - test/1_mytest/cf702_F.test.cpp
  - test/1_mytest/slope_super.test.cpp
  - test/2_library_checker/data_structure/dynamic_point_rectangle_affine_rectangle_sum.test.cpp
  - test/3_yukicoder/2627.test.cpp
  - test/3_yukicoder/1919.test.cpp
  - test/3_yukicoder/749.test.cpp
  - test/3_yukicoder/235.test.cpp
  - test/3_yukicoder/255.test.cpp
  - test/3_yukicoder/1919_2.test.cpp
documentation_of: alg/monoid/add_pair.hpp
layout: document
redirect_from:
- /library/alg/monoid/add_pair.hpp
- /library/alg/monoid/add_pair.hpp.html
title: alg/monoid/add_pair.hpp
---
