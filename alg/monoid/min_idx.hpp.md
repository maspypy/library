---
data:
  _extendedDependsOn: []
  _extendedRequiredBy:
  - icon: ':heavy_check_mark:'
    path: alg/acted_monoid/minidx_add.hpp
    title: alg/acted_monoid/minidx_add.hpp
  - icon: ':heavy_check_mark:'
    path: convex/dynamic_lichao.hpp
    title: convex/dynamic_lichao.hpp
  - icon: ':warning:'
    path: ds/pds/persistent_dynamic_lichao.hpp
    title: ds/pds/persistent_dynamic_lichao.hpp
  - icon: ':warning:'
    path: geo/manhattan_nns.hpp
    title: geo/manhattan_nns.hpp
  - icon: ':heavy_check_mark:'
    path: string/suffix_tree.hpp
    title: string/suffix_tree.hpp
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/library_checker/datastructure/line_add_get_min_dynamic.test.cpp
    title: test/library_checker/datastructure/line_add_get_min_dynamic.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/library_checker/datastructure/segment_add_get_min_dynamic.test.cpp
    title: test/library_checker/datastructure/segment_add_get_min_dynamic.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/mytest/minidx_add.test.cpp
    title: test/mytest/minidx_add.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/mytest/suffix_tree.test.cpp
    title: test/mytest/suffix_tree.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 2 \"alg/monoid/min_idx.hpp\"\n\r\ntemplate <typename T, bool\
    \ tie_is_left = true>\r\nstruct Monoid_Min_Idx {\r\n  using value_type = pair<T,\
    \ int>;\r\n  using X = value_type;\r\n  static constexpr bool is_small(const X&\
    \ x, const X& y) {\r\n    if (x.fi < y.fi) return true;\r\n    if (x.fi > y.fi)\
    \ return false;\r\n    return (tie_is_left ? (x.se < y.se) : (x.se >= y.se));\r\
    \n  }\r\n  static X op(X x, X y) { return (is_small(x, y) ? x : y); }\r\n  static\
    \ constexpr X unit() { return {numeric_limits<T>::max(), -1}; }\r\n  static constexpr\
    \ bool commute = true;\r\n};\r\n"
  code: "#pragma once\r\n\r\ntemplate <typename T, bool tie_is_left = true>\r\nstruct\
    \ Monoid_Min_Idx {\r\n  using value_type = pair<T, int>;\r\n  using X = value_type;\r\
    \n  static constexpr bool is_small(const X& x, const X& y) {\r\n    if (x.fi <\
    \ y.fi) return true;\r\n    if (x.fi > y.fi) return false;\r\n    return (tie_is_left\
    \ ? (x.se < y.se) : (x.se >= y.se));\r\n  }\r\n  static X op(X x, X y) { return\
    \ (is_small(x, y) ? x : y); }\r\n  static constexpr X unit() { return {numeric_limits<T>::max(),\
    \ -1}; }\r\n  static constexpr bool commute = true;\r\n};\r\n"
  dependsOn: []
  isVerificationFile: false
  path: alg/monoid/min_idx.hpp
  requiredBy:
  - alg/acted_monoid/minidx_add.hpp
  - string/suffix_tree.hpp
  - convex/dynamic_lichao.hpp
  - geo/manhattan_nns.hpp
  - ds/pds/persistent_dynamic_lichao.hpp
  timestamp: '2022-12-01 09:04:06+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/mytest/minidx_add.test.cpp
  - test/mytest/suffix_tree.test.cpp
  - test/library_checker/datastructure/line_add_get_min_dynamic.test.cpp
  - test/library_checker/datastructure/segment_add_get_min_dynamic.test.cpp
documentation_of: alg/monoid/min_idx.hpp
layout: document
redirect_from:
- /library/alg/monoid/min_idx.hpp
- /library/alg/monoid/min_idx.hpp.html
title: alg/monoid/min_idx.hpp
---
