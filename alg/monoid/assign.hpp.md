---
data:
  _extendedDependsOn: []
  _extendedRequiredBy:
  - icon: ':x:'
    path: alg/acted_monoid/max_assign.hpp
    title: alg/acted_monoid/max_assign.hpp
  - icon: ':x:'
    path: alg/acted_monoid/min_assign.hpp
    title: alg/acted_monoid/min_assign.hpp
  - icon: ':x:'
    path: alg/acted_monoid/powersums_assign.hpp
    title: alg/acted_monoid/powersums_assign.hpp
  - icon: ':x:'
    path: alg/acted_monoid/sum_assign.hpp
    title: alg/acted_monoid/sum_assign.hpp
  - icon: ':x:'
    path: alg/acted_monoid/summax_assign.hpp
    title: alg/acted_monoid/summax_assign.hpp
  - icon: ':x:'
    path: alg/acted_monoid/summin_assign.hpp
    title: alg/acted_monoid/summin_assign.hpp
  _extendedVerifiedWith:
  - icon: ':x:'
    path: test/1_mytest/dynamic_lazy_segtree.test.cpp
    title: test/1_mytest/dynamic_lazy_segtree.test.cpp
  - icon: ':x:'
    path: test/1_mytest/dynamic_lazy_segtree_persistent.test.cpp
    title: test/1_mytest/dynamic_lazy_segtree_persistent.test.cpp
  - icon: ':x:'
    path: test/1_mytest/max_assign.test.cpp
    title: test/1_mytest/max_assign.test.cpp
  - icon: ':x:'
    path: test/1_mytest/range_assign.test.cpp
    title: test/1_mytest/range_assign.test.cpp
  - icon: ':x:'
    path: test/1_mytest/rbst_am.test.cpp
    title: test/1_mytest/rbst_am.test.cpp
  - icon: ':x:'
    path: test/1_mytest/rbst_am_persistent.test.cpp
    title: test/1_mytest/rbst_am_persistent.test.cpp
  - icon: ':x:'
    path: test/1_mytest/rbst_monoid.test.cpp
    title: test/1_mytest/rbst_monoid.test.cpp
  - icon: ':x:'
    path: test/1_mytest/rbst_monoid_persistent.test.cpp
    title: test/1_mytest/rbst_monoid_persistent.test.cpp
  - icon: ':x:'
    path: test/1_mytest/splay_monoid.test.cpp
    title: test/1_mytest/splay_monoid.test.cpp
  - icon: ':x:'
    path: test/1_mytest/summax_assign.test.cpp
    title: test/1_mytest/summax_assign.test.cpp
  - icon: ':x:'
    path: test/1_mytest/summin_assign.test.cpp
    title: test/1_mytest/summin_assign.test.cpp
  - icon: ':x:'
    path: test/3_yukicoder/1548.test.cpp
    title: test/3_yukicoder/1548.test.cpp
  - icon: ':x:'
    path: test/3_yukicoder/2292.test.cpp
    title: test/3_yukicoder/2292.test.cpp
  - icon: ':x:'
    path: test/4_aoj/DSL_2_D.test.cpp
    title: test/4_aoj/DSL_2_D.test.cpp
  - icon: ':x:'
    path: test/4_aoj/DSL_2_F.test.cpp
    title: test/4_aoj/DSL_2_F.test.cpp
  - icon: ':x:'
    path: test/4_aoj/DSL_2_I.test.cpp
    title: test/4_aoj/DSL_2_I.test.cpp
  _isVerificationFailed: true
  _pathExtension: hpp
  _verificationStatusIcon: ':x:'
  attributes:
    links: []
  bundledCode: "#line 1 \"alg/monoid/assign.hpp\"\n\ntemplate <typename X, int none_val>\n\
    struct Monoid_Assign {\n  using value_type = X;\n  static X op(X x, X y) { return\
    \ (y == X(none_val) ? x : y); }\n  static constexpr X unit() { return X(none_val);\
    \ }\n  static constexpr bool commute = false;\n};\n"
  code: "\ntemplate <typename X, int none_val>\nstruct Monoid_Assign {\n  using value_type\
    \ = X;\n  static X op(X x, X y) { return (y == X(none_val) ? x : y); }\n  static\
    \ constexpr X unit() { return X(none_val); }\n  static constexpr bool commute\
    \ = false;\n};\n"
  dependsOn: []
  isVerificationFile: false
  path: alg/monoid/assign.hpp
  requiredBy:
  - alg/acted_monoid/min_assign.hpp
  - alg/acted_monoid/max_assign.hpp
  - alg/acted_monoid/sum_assign.hpp
  - alg/acted_monoid/powersums_assign.hpp
  - alg/acted_monoid/summax_assign.hpp
  - alg/acted_monoid/summin_assign.hpp
  timestamp: '2026-08-16 04:03:00+09:00'
  verificationStatus: LIBRARY_ALL_WA
  verifiedWith:
  - test/1_mytest/rbst_monoid_persistent.test.cpp
  - test/1_mytest/range_assign.test.cpp
  - test/1_mytest/splay_monoid.test.cpp
  - test/1_mytest/summin_assign.test.cpp
  - test/1_mytest/max_assign.test.cpp
  - test/1_mytest/rbst_am.test.cpp
  - test/1_mytest/rbst_monoid.test.cpp
  - test/1_mytest/rbst_am_persistent.test.cpp
  - test/1_mytest/summax_assign.test.cpp
  - test/1_mytest/dynamic_lazy_segtree_persistent.test.cpp
  - test/1_mytest/dynamic_lazy_segtree.test.cpp
  - test/4_aoj/DSL_2_D.test.cpp
  - test/4_aoj/DSL_2_F.test.cpp
  - test/4_aoj/DSL_2_I.test.cpp
  - test/3_yukicoder/2292.test.cpp
  - test/3_yukicoder/1548.test.cpp
documentation_of: alg/monoid/assign.hpp
layout: document
redirect_from:
- /library/alg/monoid/assign.hpp
- /library/alg/monoid/assign.hpp.html
title: alg/monoid/assign.hpp
---
