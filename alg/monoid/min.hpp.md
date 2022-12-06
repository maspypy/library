---
data:
  _extendedDependsOn: []
  _extendedRequiredBy:
  - icon: ':x:'
    path: alg/acted_monoid/max_min.hpp
    title: alg/acted_monoid/max_min.hpp
  - icon: ':question:'
    path: alg/acted_monoid/min_add.hpp
    title: alg/acted_monoid/min_add.hpp
  - icon: ':question:'
    path: alg/acted_monoid/min_assign.hpp
    title: alg/acted_monoid/min_assign.hpp
  - icon: ':x:'
    path: alg/acted_monoid/min_max.hpp
    title: alg/acted_monoid/min_max.hpp
  - icon: ':x:'
    path: alg/acted_monoid/min_min.hpp
    title: alg/acted_monoid/min_min.hpp
  - icon: ':x:'
    path: ds/offline_query/range_mex_query.hpp
    title: ds/offline_query/range_mex_query.hpp
  - icon: ':heavy_check_mark:'
    path: graph/minimum_spanning_tree.hpp
    title: graph/minimum_spanning_tree.hpp
  - icon: ':x:'
    path: seq/common_interval_decomposition.hpp
    title: seq/common_interval_decomposition.hpp
  - icon: ':x:'
    path: string/longest_common_substring.hpp
    title: string/longest_common_substring.hpp
  - icon: ':x:'
    path: string/suffix_tree.hpp
    title: string/suffix_tree.hpp
  - icon: ':x:'
    path: string/suffixarray.hpp
    title: string/suffixarray.hpp
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/aoj/1508.test.cpp
    title: test/aoj/1508.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/aoj/1508_2.test.cpp
    title: test/aoj/1508_2.test.cpp
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
  - icon: ':x:'
    path: test/atcoder/arc151_e.test.cpp
    title: test/atcoder/arc151_e.test.cpp
  - icon: ':x:'
    path: test/library_checker/datastructure/staticrmq_seg.test.cpp
    title: test/library_checker/datastructure/staticrmq_seg.test.cpp
  - icon: ':x:'
    path: test/library_checker/datastructure/staticrmq_sparse.test.cpp
    title: test/library_checker/datastructure/staticrmq_sparse.test.cpp
  - icon: ':x:'
    path: test/library_checker/graph/common_interval_decomposition.test.cpp
    title: test/library_checker/graph/common_interval_decomposition.test.cpp
  - icon: ':x:'
    path: test/library_checker/string/number_of_substrings.test.cpp
    title: test/library_checker/string/number_of_substrings.test.cpp
  - icon: ':x:'
    path: test/library_checker/string/suffix_array.test.cpp
    title: test/library_checker/string/suffix_array.test.cpp
  - icon: ':x:'
    path: test/library_checker/string/suffix_array_vec.test.cpp
    title: test/library_checker/string/suffix_array_vec.test.cpp
  - icon: ':x:'
    path: test/mytest/dynamic_segtree_sparse.test.cpp
    title: test/mytest/dynamic_segtree_sparse.test.cpp
  - icon: ':x:'
    path: test/mytest/max_min.test.cpp
    title: test/mytest/max_min.test.cpp
  - icon: ':x:'
    path: test/mytest/min_max.test.cpp
    title: test/mytest/min_max.test.cpp
  - icon: ':x:'
    path: test/mytest/min_min.test.cpp
    title: test/mytest/min_min.test.cpp
  - icon: ':x:'
    path: test/mytest/range_mex.test.cpp
    title: test/mytest/range_mex.test.cpp
  - icon: ':x:'
    path: test/mytest/rbst_am.test.cpp
    title: test/mytest/rbst_am.test.cpp
  - icon: ':x:'
    path: test/mytest/rbst_am_persistent.test.cpp
    title: test/mytest/rbst_am_persistent.test.cpp
  - icon: ':x:'
    path: test/mytest/rbst_test.test.cpp
    title: test/mytest/rbst_test.test.cpp
  - icon: ':x:'
    path: test/mytest/suffix_tree.test.cpp
    title: test/mytest/suffix_tree.test.cpp
  - icon: ':x:'
    path: test/yukicoder/1212.test.cpp
    title: test/yukicoder/1212.test.cpp
  - icon: ':x:'
    path: test/yukicoder/1234.test.cpp
    title: test/yukicoder/1234.test.cpp
  - icon: ':x:'
    path: test/yukicoder/1270.test.cpp
    title: test/yukicoder/1270.test.cpp
  - icon: ':x:'
    path: test/yukicoder/1600.test.cpp
    title: test/yukicoder/1600.test.cpp
  - icon: ':x:'
    path: test/yukicoder/1720.test.cpp
    title: test/yukicoder/1720.test.cpp
  - icon: ':x:'
    path: test/yukicoder/913.test.cpp
    title: test/yukicoder/913.test.cpp
  _isVerificationFailed: true
  _pathExtension: hpp
  _verificationStatusIcon: ':question:'
  attributes:
    links: []
  bundledCode: "#line 2 \"alg/monoid/min.hpp\"\n\r\ntemplate <class X>\r\nstruct Monoid_Min\
    \ {\r\n  using value_type = X;\r\n  static constexpr X op(const X &x, const X\
    \ &y) noexcept { return min(x, y); }\r\n  static constexpr X unit() { return numeric_limits<X>::max();\
    \ }\r\n  static constexpr bool commute = true;\r\n};\r\n"
  code: "#pragma once\r\n\r\ntemplate <class X>\r\nstruct Monoid_Min {\r\n  using\
    \ value_type = X;\r\n  static constexpr X op(const X &x, const X &y) noexcept\
    \ { return min(x, y); }\r\n  static constexpr X unit() { return numeric_limits<X>::max();\
    \ }\r\n  static constexpr bool commute = true;\r\n};\r\n"
  dependsOn: []
  isVerificationFile: false
  path: alg/monoid/min.hpp
  requiredBy:
  - alg/acted_monoid/min_add.hpp
  - alg/acted_monoid/min_assign.hpp
  - alg/acted_monoid/min_min.hpp
  - alg/acted_monoid/min_max.hpp
  - alg/acted_monoid/max_min.hpp
  - string/longest_common_substring.hpp
  - string/suffix_tree.hpp
  - string/suffixarray.hpp
  - seq/common_interval_decomposition.hpp
  - ds/offline_query/range_mex_query.hpp
  - graph/minimum_spanning_tree.hpp
  timestamp: '2022-12-01 09:04:06+09:00'
  verificationStatus: LIBRARY_SOME_WA
  verifiedWith:
  - test/yukicoder/1600.test.cpp
  - test/yukicoder/913.test.cpp
  - test/yukicoder/1234.test.cpp
  - test/yukicoder/1720.test.cpp
  - test/yukicoder/1270.test.cpp
  - test/yukicoder/1212.test.cpp
  - test/mytest/min_max.test.cpp
  - test/mytest/dynamic_segtree_sparse.test.cpp
  - test/mytest/range_mex.test.cpp
  - test/mytest/suffix_tree.test.cpp
  - test/mytest/min_min.test.cpp
  - test/mytest/max_min.test.cpp
  - test/mytest/rbst_am.test.cpp
  - test/mytest/rbst_am_persistent.test.cpp
  - test/mytest/rbst_test.test.cpp
  - test/library_checker/string/suffix_array.test.cpp
  - test/library_checker/string/number_of_substrings.test.cpp
  - test/library_checker/string/suffix_array_vec.test.cpp
  - test/library_checker/datastructure/staticrmq_seg.test.cpp
  - test/library_checker/datastructure/staticrmq_sparse.test.cpp
  - test/library_checker/graph/common_interval_decomposition.test.cpp
  - test/atcoder/arc151_e.test.cpp
  - test/atcoder/abc270_f.test.cpp
  - test/aoj/GRL_2_A.test.cpp
  - test/aoj/1508_2.test.cpp
  - test/aoj/DSL_2_F.test.cpp
  - test/aoj/1508.test.cpp
  - test/aoj/DSL_2_H.test.cpp
documentation_of: alg/monoid/min.hpp
layout: document
redirect_from:
- /library/alg/monoid/min.hpp
- /library/alg/monoid/min.hpp.html
title: alg/monoid/min.hpp
---
