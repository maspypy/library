---
data:
  _extendedDependsOn: []
  _extendedRequiredBy:
  - icon: ':warning:'
    path: alg/lazy_minidx_add.hpp
    title: alg/lazy_minidx_add.hpp
  - icon: ':heavy_check_mark:'
    path: ds/dynamic_lichao.hpp
    title: ds/dynamic_lichao.hpp
  - icon: ':warning:'
    path: geo/manhattan_nns.hpp
    title: geo/manhattan_nns.hpp
  - icon: ':warning:'
    path: pds/persistent_dynamic_lichao.hpp
    title: pds/persistent_dynamic_lichao.hpp
  - icon: ':x:'
    path: string/suffix_tree.hpp
    title: string/suffix_tree.hpp
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/library_checker/datastructure/line_add_get_min_dynamic.test.cpp
    title: test/library_checker/datastructure/line_add_get_min_dynamic.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/library_checker/datastructure/segment_add_get_min_dynamic.test.cpp
    title: test/library_checker/datastructure/segment_add_get_min_dynamic.test.cpp
  - icon: ':x:'
    path: test/mytest/suffix_tree.test.cpp
    title: test/mytest/suffix_tree.test.cpp
  _isVerificationFailed: true
  _pathExtension: hpp
  _verificationStatusIcon: ':question:'
  attributes:
    links: []
  bundledCode: "#line 1 \"alg/monoid_min_idx.hpp\"\ntemplate <typename T, bool tie_is_left\
    \ = true>\r\nstruct Monoid_Min_Idx {\r\n  using value_type = pair<T, int>;\r\n\
    \  using X = value_type;\r\n  static constexpr bool is_small(const X& x, const\
    \ X& y) {\r\n    if (x.fi < y.fi) return true;\r\n    if (x.fi > y.fi) return\
    \ false;\r\n    return (tie_is_left ? (x.se < y.se) : (x.se >= y.se));\r\n  }\r\
    \n  static X op(X x, X y) { return (is_small(x, y) ? x : y); }\r\n  static constexpr\
    \ X unit() { return {numeric_limits<T>::max(), -1}; }\r\n  static constexpr bool\
    \ commute = true;\r\n};\r\n"
  code: "template <typename T, bool tie_is_left = true>\r\nstruct Monoid_Min_Idx {\r\
    \n  using value_type = pair<T, int>;\r\n  using X = value_type;\r\n  static constexpr\
    \ bool is_small(const X& x, const X& y) {\r\n    if (x.fi < y.fi) return true;\r\
    \n    if (x.fi > y.fi) return false;\r\n    return (tie_is_left ? (x.se < y.se)\
    \ : (x.se >= y.se));\r\n  }\r\n  static X op(X x, X y) { return (is_small(x, y)\
    \ ? x : y); }\r\n  static constexpr X unit() { return {numeric_limits<T>::max(),\
    \ -1}; }\r\n  static constexpr bool commute = true;\r\n};\r\n"
  dependsOn: []
  isVerificationFile: false
  path: alg/monoid_min_idx.hpp
  requiredBy:
  - string/suffix_tree.hpp
  - alg/lazy_minidx_add.hpp
  - geo/manhattan_nns.hpp
  - pds/persistent_dynamic_lichao.hpp
  - ds/dynamic_lichao.hpp
  timestamp: '2022-05-27 16:21:11+09:00'
  verificationStatus: LIBRARY_SOME_WA
  verifiedWith:
  - test/mytest/suffix_tree.test.cpp
  - test/library_checker/datastructure/segment_add_get_min_dynamic.test.cpp
  - test/library_checker/datastructure/line_add_get_min_dynamic.test.cpp
documentation_of: alg/monoid_min_idx.hpp
layout: document
redirect_from:
- /library/alg/monoid_min_idx.hpp
- /library/alg/monoid_min_idx.hpp.html
title: alg/monoid_min_idx.hpp
---
