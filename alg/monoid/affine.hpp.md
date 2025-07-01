---
data:
  _extendedDependsOn: []
  _extendedRequiredBy:
  - icon: ':x:'
    path: alg/acted_monoid/cntsum_affine.hpp
    title: alg/acted_monoid/cntsum_affine.hpp
  - icon: ':x:'
    path: alg/acted_monoid/sum_affine.hpp
    title: alg/acted_monoid/sum_affine.hpp
  - icon: ':warning:'
    path: alg/acted_set/affine.hpp
    title: alg/acted_set/affine.hpp
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/1_mytest/mo_on_tree.test.cpp
    title: test/1_mytest/mo_on_tree.test.cpp
  - icon: ':x:'
    path: test/1_mytest/prefix_max_segtree.test.cpp
    title: test/1_mytest/prefix_max_segtree.test.cpp
  - icon: ':x:'
    path: test/1_mytest/rbst_monoid_2.test.cpp
    title: test/1_mytest/rbst_monoid_2.test.cpp
  - icon: ':x:'
    path: test/1_mytest/splay.test.cpp
    title: test/1_mytest/splay.test.cpp
  - icon: ':x:'
    path: test/2_library_checker/data_structure/deque_operate_all_compsite.test.cpp
    title: test/2_library_checker/data_structure/deque_operate_all_compsite.test.cpp
  - icon: ':x:'
    path: test/2_library_checker/data_structure/dynamic_point_rectangle_affine_rectangle_sum.test.cpp
    title: test/2_library_checker/data_structure/dynamic_point_rectangle_affine_rectangle_sum.test.cpp
  - icon: ':x:'
    path: test/2_library_checker/data_structure/dynamic_sequence_range_affine_range_sum_rbst.test.cpp
    title: test/2_library_checker/data_structure/dynamic_sequence_range_affine_range_sum_rbst.test.cpp
  - icon: ':x:'
    path: test/2_library_checker/data_structure/dynamic_sequence_range_affine_range_sum_splay.test.cpp
    title: test/2_library_checker/data_structure/dynamic_sequence_range_affine_range_sum_splay.test.cpp
  - icon: ':x:'
    path: test/2_library_checker/data_structure/persistent_range_affine_range_sum.test.cpp
    title: test/2_library_checker/data_structure/persistent_range_affine_range_sum.test.cpp
  - icon: ':x:'
    path: test/2_library_checker/data_structure/point_set_range_composite_dynamic.test.cpp
    title: test/2_library_checker/data_structure/point_set_range_composite_dynamic.test.cpp
  - icon: ':x:'
    path: test/2_library_checker/data_structure/point_set_range_composite_monoid.test.cpp
    title: test/2_library_checker/data_structure/point_set_range_composite_monoid.test.cpp
  - icon: ':x:'
    path: test/2_library_checker/data_structure/queue_operate_all_composite.test.cpp
    title: test/2_library_checker/data_structure/queue_operate_all_composite.test.cpp
  - icon: ':x:'
    path: test/2_library_checker/data_structure/range_affine_point_add.test.cpp
    title: test/2_library_checker/data_structure/range_affine_point_add.test.cpp
  - icon: ':x:'
    path: test/2_library_checker/data_structure/range_affine_range_sum.test.cpp
    title: test/2_library_checker/data_structure/range_affine_range_sum.test.cpp
  - icon: ':x:'
    path: test/2_library_checker/data_structure/range_set_range_composite.test.cpp
    title: test/2_library_checker/data_structure/range_set_range_composite.test.cpp
  - icon: ':x:'
    path: test/2_library_checker/data_structure/sort_segtree.test.cpp
    title: test/2_library_checker/data_structure/sort_segtree.test.cpp
  - icon: ':x:'
    path: test/2_library_checker/data_structure/sort_segtree_1.test.cpp
    title: test/2_library_checker/data_structure/sort_segtree_1.test.cpp
  - icon: ':x:'
    path: test/2_library_checker/tree/dynamic_tree_vertex_set_path_composite.test.cpp
    title: test/2_library_checker/tree/dynamic_tree_vertex_set_path_composite.test.cpp
  - icon: ':x:'
    path: test/2_library_checker/tree/vertex_set_path_composite_monoid.test.cpp
    title: test/2_library_checker/tree/vertex_set_path_composite_monoid.test.cpp
  - icon: ':x:'
    path: test/3_yukicoder/1502.test.cpp
    title: test/3_yukicoder/1502.test.cpp
  - icon: ':x:'
    path: test/3_yukicoder/1891.test.cpp
    title: test/3_yukicoder/1891.test.cpp
  - icon: ':x:'
    path: test/3_yukicoder/2342.test.cpp
    title: test/3_yukicoder/2342.test.cpp
  - icon: ':x:'
    path: test/3_yukicoder/2342_2.test.cpp
    title: test/3_yukicoder/2342_2.test.cpp
  - icon: ':x:'
    path: test/3_yukicoder/255.test.cpp
    title: test/3_yukicoder/255.test.cpp
  - icon: ':x:'
    path: test/3_yukicoder/2595.test.cpp
    title: test/3_yukicoder/2595.test.cpp
  _isVerificationFailed: true
  _pathExtension: hpp
  _verificationStatusIcon: ':question:'
  attributes:
    links: []
  bundledCode: "#line 2 \"alg/monoid/affine.hpp\"\n\n// op(F, G) = comp(G,F), F \u306E\
    \u3042\u3068\u3067 G\ntemplate <typename K>\nstruct Monoid_Affine {\n  using F\
    \ = pair<K, K>;\n  using value_type = F;\n  using X = value_type;\n  static constexpr\
    \ F op(const F &x, const F &y) noexcept {\n    return F({x.first * y.first, x.second\
    \ * y.first + y.second});\n  }\n  static constexpr F inverse(const F &x) {\n \
    \   auto [a, b] = x;\n    a = K(1) / a;\n    return {a, a * (-b)};\n  }\n  static\
    \ constexpr K eval(const F &f, K x) noexcept {\n    return f.first * x + f.second;\n\
    \  }\n  static constexpr F unit() { return {K(1), K(0)}; }\n  static constexpr\
    \ bool commute = false;\n};\n"
  code: "#pragma once\n\n// op(F, G) = comp(G,F), F \u306E\u3042\u3068\u3067 G\ntemplate\
    \ <typename K>\nstruct Monoid_Affine {\n  using F = pair<K, K>;\n  using value_type\
    \ = F;\n  using X = value_type;\n  static constexpr F op(const F &x, const F &y)\
    \ noexcept {\n    return F({x.first * y.first, x.second * y.first + y.second});\n\
    \  }\n  static constexpr F inverse(const F &x) {\n    auto [a, b] = x;\n    a\
    \ = K(1) / a;\n    return {a, a * (-b)};\n  }\n  static constexpr K eval(const\
    \ F &f, K x) noexcept {\n    return f.first * x + f.second;\n  }\n  static constexpr\
    \ F unit() { return {K(1), K(0)}; }\n  static constexpr bool commute = false;\n\
    };\n"
  dependsOn: []
  isVerificationFile: false
  path: alg/monoid/affine.hpp
  requiredBy:
  - alg/acted_set/affine.hpp
  - alg/acted_monoid/cntsum_affine.hpp
  - alg/acted_monoid/sum_affine.hpp
  timestamp: '2023-07-25 22:13:04+09:00'
  verificationStatus: LIBRARY_SOME_WA
  verifiedWith:
  - test/1_mytest/mo_on_tree.test.cpp
  - test/1_mytest/prefix_max_segtree.test.cpp
  - test/1_mytest/splay.test.cpp
  - test/1_mytest/rbst_monoid_2.test.cpp
  - test/2_library_checker/tree/dynamic_tree_vertex_set_path_composite.test.cpp
  - test/2_library_checker/tree/vertex_set_path_composite_monoid.test.cpp
  - test/2_library_checker/data_structure/point_set_range_composite_dynamic.test.cpp
  - test/2_library_checker/data_structure/sort_segtree_1.test.cpp
  - test/2_library_checker/data_structure/dynamic_sequence_range_affine_range_sum_rbst.test.cpp
  - test/2_library_checker/data_structure/queue_operate_all_composite.test.cpp
  - test/2_library_checker/data_structure/range_affine_range_sum.test.cpp
  - test/2_library_checker/data_structure/persistent_range_affine_range_sum.test.cpp
  - test/2_library_checker/data_structure/dynamic_point_rectangle_affine_rectangle_sum.test.cpp
  - test/2_library_checker/data_structure/deque_operate_all_compsite.test.cpp
  - test/2_library_checker/data_structure/dynamic_sequence_range_affine_range_sum_splay.test.cpp
  - test/2_library_checker/data_structure/point_set_range_composite_monoid.test.cpp
  - test/2_library_checker/data_structure/sort_segtree.test.cpp
  - test/2_library_checker/data_structure/range_set_range_composite.test.cpp
  - test/2_library_checker/data_structure/range_affine_point_add.test.cpp
  - test/3_yukicoder/2342_2.test.cpp
  - test/3_yukicoder/2595.test.cpp
  - test/3_yukicoder/1502.test.cpp
  - test/3_yukicoder/2342.test.cpp
  - test/3_yukicoder/1891.test.cpp
  - test/3_yukicoder/255.test.cpp
documentation_of: alg/monoid/affine.hpp
layout: document
redirect_from:
- /library/alg/monoid/affine.hpp
- /library/alg/monoid/affine.hpp.html
title: alg/monoid/affine.hpp
---
