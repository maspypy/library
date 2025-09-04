---
data:
  _extendedDependsOn: []
  _extendedRequiredBy:
  - icon: ':question:'
    path: ds/segtree/dynamic_segtree.hpp
    title: ds/segtree/dynamic_segtree.hpp
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/2_library_checker/data_structure/point_set_range_composite_dynamic.test.cpp
    title: test/2_library_checker/data_structure/point_set_range_composite_dynamic.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/2_library_checker/data_structure/range_kth_smallest_pseg.test.cpp
    title: test/2_library_checker/data_structure/range_kth_smallest_pseg.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/3_yukicoder/1649.test.cpp
    title: test/3_yukicoder/1649.test.cpp
  - icon: ':x:'
    path: test/3_yukicoder/1826.test.cpp
    title: test/3_yukicoder/1826.test.cpp
  - icon: ':x:'
    path: test/3_yukicoder/2935.test.cpp
    title: test/3_yukicoder/2935.test.cpp
  - icon: ':x:'
    path: test/3_yukicoder/789.test.cpp
    title: test/3_yukicoder/789.test.cpp
  _isVerificationFailed: true
  _pathExtension: hpp
  _verificationStatusIcon: ':question:'
  attributes:
    links: []
  bundledCode: "#line 1 \"alg/default_prod.hpp\"\ntemplate <class Monoid>\nstruct\
    \ DefaultUnitProd {\n  using X = typename Monoid::value_type;\n  static constexpr\
    \ bool unit_only = true;\n  X operator()(long long, long long) const { return\
    \ Monoid::unit(); }\n};\n"
  code: "template <class Monoid>\nstruct DefaultUnitProd {\n  using X = typename Monoid::value_type;\n\
    \  static constexpr bool unit_only = true;\n  X operator()(long long, long long)\
    \ const { return Monoid::unit(); }\n};\n"
  dependsOn: []
  isVerificationFile: false
  path: alg/default_prod.hpp
  requiredBy:
  - ds/segtree/dynamic_segtree.hpp
  timestamp: '2025-09-01 19:47:27+09:00'
  verificationStatus: LIBRARY_SOME_WA
  verifiedWith:
  - test/3_yukicoder/1649.test.cpp
  - test/3_yukicoder/789.test.cpp
  - test/3_yukicoder/2935.test.cpp
  - test/3_yukicoder/1826.test.cpp
  - test/2_library_checker/data_structure/point_set_range_composite_dynamic.test.cpp
  - test/2_library_checker/data_structure/range_kth_smallest_pseg.test.cpp
documentation_of: alg/default_prod.hpp
layout: document
redirect_from:
- /library/alg/default_prod.hpp
- /library/alg/default_prod.hpp.html
title: alg/default_prod.hpp
---
