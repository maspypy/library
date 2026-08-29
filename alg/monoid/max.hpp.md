---
data:
  _extendedDependsOn: []
  _extendedRequiredBy:
  - icon: ':x:'
    path: alg/acted_monoid/max_add.hpp
    title: alg/acted_monoid/max_add.hpp
  - icon: ':x:'
    path: alg/acted_monoid/max_assign.hpp
    title: alg/acted_monoid/max_assign.hpp
  - icon: ':x:'
    path: alg/acted_monoid/max_max.hpp
    title: alg/acted_monoid/max_max.hpp
  - icon: ':x:'
    path: alg/acted_monoid/max_min.hpp
    title: alg/acted_monoid/max_min.hpp
  - icon: ':x:'
    path: alg/acted_monoid/min_max.hpp
    title: alg/acted_monoid/min_max.hpp
  - icon: ':x:'
    path: graph/minimum_spanning_tree.hpp
    title: graph/minimum_spanning_tree.hpp
  _extendedVerifiedWith:
  - icon: ':x:'
    path: test/1_mytest/max_assign.test.cpp
    title: test/1_mytest/max_assign.test.cpp
  - icon: ':x:'
    path: test/1_mytest/max_max.test.cpp
    title: test/1_mytest/max_max.test.cpp
  - icon: ':x:'
    path: test/1_mytest/max_min.test.cpp
    title: test/1_mytest/max_min.test.cpp
  - icon: ':x:'
    path: test/1_mytest/min_max.test.cpp
    title: test/1_mytest/min_max.test.cpp
  - icon: ':x:'
    path: test/1_mytest/range_add_range_max.test.cpp
    title: test/1_mytest/range_add_range_max.test.cpp
  - icon: ':x:'
    path: test/2_library_checker/tree/mst.test.cpp
    title: test/2_library_checker/tree/mst.test.cpp
  - icon: ':x:'
    path: test/3_yukicoder/1117.test.cpp
    title: test/3_yukicoder/1117.test.cpp
  - icon: ':x:'
    path: test/3_yukicoder/1625.test.cpp
    title: test/3_yukicoder/1625.test.cpp
  - icon: ':x:'
    path: test/3_yukicoder/1625_2.test.cpp
    title: test/3_yukicoder/1625_2.test.cpp
  - icon: ':x:'
    path: test/3_yukicoder/1790.test.cpp
    title: test/3_yukicoder/1790.test.cpp
  - icon: ':x:'
    path: test/3_yukicoder/1826.test.cpp
    title: test/3_yukicoder/1826.test.cpp
  - icon: ':x:'
    path: test/3_yukicoder/1826_2.test.cpp
    title: test/3_yukicoder/1826_2.test.cpp
  - icon: ':x:'
    path: test/3_yukicoder/2026.test.cpp
    title: test/3_yukicoder/2026.test.cpp
  - icon: ':x:'
    path: test/3_yukicoder/2242.test.cpp
    title: test/3_yukicoder/2242.test.cpp
  - icon: ':x:'
    path: test/3_yukicoder/2295.test.cpp
    title: test/3_yukicoder/2295.test.cpp
  - icon: ':x:'
    path: test/3_yukicoder/2859.test.cpp
    title: test/3_yukicoder/2859.test.cpp
  - icon: ':x:'
    path: test/3_yukicoder/686.test.cpp
    title: test/3_yukicoder/686.test.cpp
  - icon: ':x:'
    path: test/4_aoj/GRL_2_A.test.cpp
    title: test/4_aoj/GRL_2_A.test.cpp
  _isVerificationFailed: true
  _pathExtension: hpp
  _verificationStatusIcon: ':x:'
  attributes:
    links: []
  bundledCode: "#line 1 \"alg/monoid/max.hpp\"\n\ntemplate <typename E>\nstruct Monoid_Max\
    \ {\n  using X = E;\n  using value_type = X;\n  static constexpr X op(const X\
    \ &x, const X &y) noexcept { return max(x, y); }\n  static constexpr X unit()\
    \ { return -infty<E>; }\n  static constexpr bool commute = true;\n};\n"
  code: "\ntemplate <typename E>\nstruct Monoid_Max {\n  using X = E;\n  using value_type\
    \ = X;\n  static constexpr X op(const X &x, const X &y) noexcept { return max(x,\
    \ y); }\n  static constexpr X unit() { return -infty<E>; }\n  static constexpr\
    \ bool commute = true;\n};\n"
  dependsOn: []
  isVerificationFile: false
  path: alg/monoid/max.hpp
  requiredBy:
  - graph/minimum_spanning_tree.hpp
  - alg/acted_monoid/max_min.hpp
  - alg/acted_monoid/max_assign.hpp
  - alg/acted_monoid/min_max.hpp
  - alg/acted_monoid/max_max.hpp
  - alg/acted_monoid/max_add.hpp
  timestamp: '2026-08-16 04:03:00+09:00'
  verificationStatus: LIBRARY_ALL_WA
  verifiedWith:
  - test/1_mytest/max_min.test.cpp
  - test/1_mytest/max_assign.test.cpp
  - test/1_mytest/max_max.test.cpp
  - test/1_mytest/min_max.test.cpp
  - test/1_mytest/range_add_range_max.test.cpp
  - test/2_library_checker/tree/mst.test.cpp
  - test/4_aoj/GRL_2_A.test.cpp
  - test/3_yukicoder/2242.test.cpp
  - test/3_yukicoder/1826_2.test.cpp
  - test/3_yukicoder/2859.test.cpp
  - test/3_yukicoder/1826.test.cpp
  - test/3_yukicoder/2295.test.cpp
  - test/3_yukicoder/1790.test.cpp
  - test/3_yukicoder/2026.test.cpp
  - test/3_yukicoder/686.test.cpp
  - test/3_yukicoder/1625_2.test.cpp
  - test/3_yukicoder/1625.test.cpp
  - test/3_yukicoder/1117.test.cpp
documentation_of: alg/monoid/max.hpp
layout: document
redirect_from:
- /library/alg/monoid/max.hpp
- /library/alg/monoid/max.hpp.html
title: alg/monoid/max.hpp
---
