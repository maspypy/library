---
data:
  _extendedDependsOn: []
  _extendedRequiredBy:
  - icon: ':heavy_check_mark:'
    path: alg/lazy_cntsum_affine.hpp
    title: alg/lazy_cntsum_affine.hpp
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/library_checker/datastructure/dynamic_sequence_range_affine_range_sum_rbst.test.cpp
    title: test/library_checker/datastructure/dynamic_sequence_range_affine_range_sum_rbst.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/library_checker/datastructure/dynamic_sequence_range_affine_range_sum_splay.test.cpp
    title: test/library_checker/datastructure/dynamic_sequence_range_affine_range_sum_splay.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/library_checker/datastructure/point_set_range_composite_monoid.test.cpp
    title: test/library_checker/datastructure/point_set_range_composite_monoid.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/library_checker/datastructure/queue_operate_all_composite.test.cpp
    title: test/library_checker/datastructure/queue_operate_all_composite.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/library_checker/datastructure/range_affine_range_sum.test.cpp
    title: test/library_checker/datastructure/range_affine_range_sum.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/library_checker/datastructure/vertex_set_path_composite_group.test.cpp
    title: test/library_checker/datastructure/vertex_set_path_composite_group.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/library_checker/datastructure/vertex_set_path_composite_monoid.test.cpp
    title: test/library_checker/datastructure/vertex_set_path_composite_monoid.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/yukicoder/1891_xor_sparse.test.cpp
    title: test/yukicoder/1891_xor_sparse.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/yukicoder/255.test.cpp
    title: test/yukicoder/255.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 1 \"alg/group_affine.hpp\"\ntemplate <typename K>\nstruct Group_Affine\
    \ {\n  using F = pair<K, K>;\n  using value_type = F;\n  static constexpr F op(const\
    \ F &x, const F &y) noexcept {\n    return F({x.fi * y.fi, x.se * y.fi + y.se});\n\
    \  }\n  static constexpr F inverse(const F &x) {\n    auto [a, b] = x;\n    a\
    \ = K(1) / a;\n    return {a, a * (-b)};\n  }\n  static constexpr K eval(const\
    \ F &f, K x) noexcept { return f.fi * x + f.se; }\n  static constexpr F unit()\
    \ { return {K(1), K(0)}; }\n  static constexpr bool commute = false;\n};\n"
  code: "template <typename K>\nstruct Group_Affine {\n  using F = pair<K, K>;\n \
    \ using value_type = F;\n  static constexpr F op(const F &x, const F &y) noexcept\
    \ {\n    return F({x.fi * y.fi, x.se * y.fi + y.se});\n  }\n  static constexpr\
    \ F inverse(const F &x) {\n    auto [a, b] = x;\n    a = K(1) / a;\n    return\
    \ {a, a * (-b)};\n  }\n  static constexpr K eval(const F &f, K x) noexcept { return\
    \ f.fi * x + f.se; }\n  static constexpr F unit() { return {K(1), K(0)}; }\n \
    \ static constexpr bool commute = false;\n};"
  dependsOn: []
  isVerificationFile: false
  path: alg/group_affine.hpp
  requiredBy:
  - alg/lazy_cntsum_affine.hpp
  timestamp: '2022-04-16 04:26:49+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/library_checker/datastructure/dynamic_sequence_range_affine_range_sum_splay.test.cpp
  - test/library_checker/datastructure/queue_operate_all_composite.test.cpp
  - test/library_checker/datastructure/dynamic_sequence_range_affine_range_sum_rbst.test.cpp
  - test/library_checker/datastructure/vertex_set_path_composite_group.test.cpp
  - test/library_checker/datastructure/range_affine_range_sum.test.cpp
  - test/library_checker/datastructure/point_set_range_composite_monoid.test.cpp
  - test/library_checker/datastructure/vertex_set_path_composite_monoid.test.cpp
  - test/yukicoder/1891_xor_sparse.test.cpp
  - test/yukicoder/255.test.cpp
documentation_of: alg/group_affine.hpp
layout: document
redirect_from:
- /library/alg/group_affine.hpp
- /library/alg/group_affine.hpp.html
title: alg/group_affine.hpp
---
