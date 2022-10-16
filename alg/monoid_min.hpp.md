---
data:
  _extendedDependsOn: []
  _extendedRequiredBy:
  - icon: ':warning:'
    path: alg/lazy_max_min.hpp
    title: alg/lazy_max_min.hpp
  - icon: ':heavy_check_mark:'
    path: alg/lazy_min_add.hpp
    title: alg/lazy_min_add.hpp
  - icon: ':warning:'
    path: alg/lazy_min_min.hpp
    title: alg/lazy_min_min.hpp
  - icon: ':heavy_check_mark:'
    path: alg/lazy_min_set.hpp
    title: alg/lazy_min_set.hpp
  - icon: ':heavy_check_mark:'
    path: ds/common_interval_decomposition.hpp
    title: ds/common_interval_decomposition.hpp
  - icon: ':heavy_check_mark:'
    path: ds/range_mex_query.hpp
    title: ds/range_mex_query.hpp
  - icon: ':heavy_check_mark:'
    path: graph/minimum_spanning_tree.hpp
    title: graph/minimum_spanning_tree.hpp
  - icon: ':heavy_check_mark:'
    path: string/longest_common_substring.hpp
    title: string/longest_common_substring.hpp
  - icon: ':warning:'
    path: string/sort_all_substring.hpp
    title: string/sort_all_substring.hpp
  - icon: ':heavy_check_mark:'
    path: string/suffix_tree.hpp
    title: string/suffix_tree.hpp
  - icon: ':heavy_check_mark:'
    path: string/suffixarray.hpp
    title: string/suffixarray.hpp
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/aoj/1508.test.cpp
    title: test/aoj/1508.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/aoj/DSL_2_F.test.cpp
    title: test/aoj/DSL_2_F.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/aoj/DSL_2_H.test.cpp
    title: test/aoj/DSL_2_H.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/aoj/GRL_2_A.test.cpp
    title: test/aoj/GRL_2_A.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/atcoder/abc270_f.test.cpp
    title: test/atcoder/abc270_f.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/atcoder/arc151_e.test.cpp
    title: test/atcoder/arc151_e.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/library_checker/datastructure/staticrmq_seg.test.cpp
    title: test/library_checker/datastructure/staticrmq_seg.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/library_checker/datastructure/staticrmq_sparse.test.cpp
    title: test/library_checker/datastructure/staticrmq_sparse.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/library_checker/graph/common_interval_decomposition.test.cpp
    title: test/library_checker/graph/common_interval_decomposition.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/library_checker/string/number_of_substrings.test.cpp
    title: test/library_checker/string/number_of_substrings.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/library_checker/string/suffix_array.test.cpp
    title: test/library_checker/string/suffix_array.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/library_checker/string/suffix_array_vec.test.cpp
    title: test/library_checker/string/suffix_array_vec.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/mytest/range_mex.test.cpp
    title: test/mytest/range_mex.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/mytest/suffix_tree.test.cpp
    title: test/mytest/suffix_tree.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/yukicoder/1212.test.cpp
    title: test/yukicoder/1212.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/yukicoder/1234.test.cpp
    title: test/yukicoder/1234.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/yukicoder/1270.test.cpp
    title: test/yukicoder/1270.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/yukicoder/1600.test.cpp
    title: test/yukicoder/1600.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/yukicoder/1720.test.cpp
    title: test/yukicoder/1720.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/yukicoder/913.test.cpp
    title: test/yukicoder/913.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 2 \"alg/monoid_min.hpp\"\ntemplate <class X>\r\nstruct Monoid_Min\
    \ {\r\n  using value_type = X;\r\n  static constexpr X op(const X &x, const X\
    \ &y) noexcept { return min(x, y); }\r\n  static constexpr X unit() { return numeric_limits<X>::max();\
    \ }\r\n  static constexpr bool commute = true;\r\n};\r\n"
  code: "#pragma once\r\ntemplate <class X>\r\nstruct Monoid_Min {\r\n  using value_type\
    \ = X;\r\n  static constexpr X op(const X &x, const X &y) noexcept { return min(x,\
    \ y); }\r\n  static constexpr X unit() { return numeric_limits<X>::max(); }\r\n\
    \  static constexpr bool commute = true;\r\n};\r\n"
  dependsOn: []
  isVerificationFile: false
  path: alg/monoid_min.hpp
  requiredBy:
  - graph/minimum_spanning_tree.hpp
  - alg/lazy_max_min.hpp
  - alg/lazy_min_add.hpp
  - alg/lazy_min_set.hpp
  - alg/lazy_min_min.hpp
  - ds/range_mex_query.hpp
  - ds/common_interval_decomposition.hpp
  - string/suffixarray.hpp
  - string/longest_common_substring.hpp
  - string/suffix_tree.hpp
  - string/sort_all_substring.hpp
  timestamp: '2022-05-13 21:02:36+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/aoj/GRL_2_A.test.cpp
  - test/aoj/1508.test.cpp
  - test/aoj/DSL_2_H.test.cpp
  - test/aoj/DSL_2_F.test.cpp
  - test/library_checker/graph/common_interval_decomposition.test.cpp
  - test/library_checker/datastructure/staticrmq_sparse.test.cpp
  - test/library_checker/datastructure/staticrmq_seg.test.cpp
  - test/library_checker/string/suffix_array.test.cpp
  - test/library_checker/string/number_of_substrings.test.cpp
  - test/library_checker/string/suffix_array_vec.test.cpp
  - test/yukicoder/1600.test.cpp
  - test/yukicoder/913.test.cpp
  - test/yukicoder/1270.test.cpp
  - test/yukicoder/1234.test.cpp
  - test/yukicoder/1212.test.cpp
  - test/yukicoder/1720.test.cpp
  - test/mytest/suffix_tree.test.cpp
  - test/mytest/range_mex.test.cpp
  - test/atcoder/arc151_e.test.cpp
  - test/atcoder/abc270_f.test.cpp
documentation_of: alg/monoid_min.hpp
layout: document
redirect_from:
- /library/alg/monoid_min.hpp
- /library/alg/monoid_min.hpp.html
title: alg/monoid_min.hpp
---
