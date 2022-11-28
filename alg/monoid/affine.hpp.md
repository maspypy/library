---
data:
  _extendedDependsOn: []
  _extendedRequiredBy:
  - icon: ':warning:'
    path: alg/acted_monoid/cntsum_affine.hpp
    title: alg/acted_monoid/cntsum_affine.hpp
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/library_checker/datastructure/point_set_range_composite_monoid.test.cpp
    title: test/library_checker/datastructure/point_set_range_composite_monoid.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/library_checker/datastructure/queue_operate_all_composite.test.cpp
    title: test/library_checker/datastructure/queue_operate_all_composite.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/library_checker/datastructure/range_affine_point_add.test.cpp
    title: test/library_checker/datastructure/range_affine_point_add.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/library_checker/datastructure/sort_segtree.test.cpp
    title: test/library_checker/datastructure/sort_segtree.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/library_checker/datastructure/sort_segtree_1.test.cpp
    title: test/library_checker/datastructure/sort_segtree_1.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/mytest/splay.test.cpp
    title: test/mytest/splay.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/yukicoder/1502.test.cpp
    title: test/yukicoder/1502.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/yukicoder/1891.test.cpp
    title: test/yukicoder/1891.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 1 \"alg/monoid/affine.hpp\"\ntemplate <typename K>\nstruct Monoid_Affine\
    \ {\n  using F = pair<K, K>;\n  using value_type = F;\n  static constexpr F op(const\
    \ F &x, const F &y) noexcept {\n    return F({x.first * y.first, x.second * y.first\
    \ + y.second});\n  }\n  static constexpr F inverse(const F &x) {\n    auto [a,\
    \ b] = x;\n    a = K(1) / a;\n    return {a, a * (-b)};\n  }\n  static constexpr\
    \ K eval(const F &f, K x) noexcept {\n    return f.first * x + f.second;\n  }\n\
    \  static constexpr F unit() { return {K(1), K(0)}; }\n  static constexpr bool\
    \ commute = false;\n};\n"
  code: "template <typename K>\nstruct Monoid_Affine {\n  using F = pair<K, K>;\n\
    \  using value_type = F;\n  static constexpr F op(const F &x, const F &y) noexcept\
    \ {\n    return F({x.first * y.first, x.second * y.first + y.second});\n  }\n\
    \  static constexpr F inverse(const F &x) {\n    auto [a, b] = x;\n    a = K(1)\
    \ / a;\n    return {a, a * (-b)};\n  }\n  static constexpr K eval(const F &f,\
    \ K x) noexcept {\n    return f.first * x + f.second;\n  }\n  static constexpr\
    \ F unit() { return {K(1), K(0)}; }\n  static constexpr bool commute = false;\n\
    };\n"
  dependsOn: []
  isVerificationFile: false
  path: alg/monoid/affine.hpp
  requiredBy:
  - alg/acted_monoid/cntsum_affine.hpp
  timestamp: '2022-11-27 15:05:49+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/yukicoder/1502.test.cpp
  - test/yukicoder/1891.test.cpp
  - test/mytest/splay.test.cpp
  - test/library_checker/datastructure/point_set_range_composite_monoid.test.cpp
  - test/library_checker/datastructure/queue_operate_all_composite.test.cpp
  - test/library_checker/datastructure/sort_segtree.test.cpp
  - test/library_checker/datastructure/sort_segtree_1.test.cpp
  - test/library_checker/datastructure/range_affine_point_add.test.cpp
documentation_of: alg/monoid/affine.hpp
layout: document
redirect_from:
- /library/alg/monoid/affine.hpp
- /library/alg/monoid/affine.hpp.html
title: alg/monoid/affine.hpp
---
