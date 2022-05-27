---
data:
  _extendedDependsOn: []
  _extendedRequiredBy:
  - icon: ':warning:'
    path: alg/lazy_minidx_add.hpp
    title: alg/lazy_minidx_add.hpp
  - icon: ':x:'
    path: ds/dynamic_lichao.hpp
    title: ds/dynamic_lichao.hpp
  - icon: ':warning:'
    path: geo/manhattan_nns.hpp
    title: geo/manhattan_nns.hpp
  _extendedVerifiedWith:
  - icon: ':x:'
    path: test/library_checker/datastructure/line_add_get_min_dynamic.test.cpp
    title: test/library_checker/datastructure/line_add_get_min_dynamic.test.cpp
  - icon: ':x:'
    path: test/library_checker/datastructure/segment_add_get_min_dynamic.test.cpp
    title: test/library_checker/datastructure/segment_add_get_min_dynamic.test.cpp
  _isVerificationFailed: true
  _pathExtension: hpp
  _verificationStatusIcon: ':x:'
  attributes:
    links: []
  bundledCode: "#line 1 \"alg/monoid_min_idx.hpp\"\ntemplate <typename T, bool tie_is_left\
    \ = true>\r\nstruct Monoid_Min_Idx {\r\n  using value_type = pair<T, int>;\r\n\
    \  using X = value_type;\r\n  static X op(X x, X y) {\r\n    if (x.fi < y.fi)\
    \ return x;\r\n    if (x.fi > y.fi) return y;\r\n    if (x.se > y.se) swap(x,\
    \ y);\r\n    return (tie_is_left ? x : y);\r\n  }\r\n  static constexpr X unit()\
    \ { return {numeric_limits<T>::max(), -1}; }\r\n  static constexpr bool commute\
    \ = true;\r\n};\r\n"
  code: "template <typename T, bool tie_is_left = true>\r\nstruct Monoid_Min_Idx {\r\
    \n  using value_type = pair<T, int>;\r\n  using X = value_type;\r\n  static X\
    \ op(X x, X y) {\r\n    if (x.fi < y.fi) return x;\r\n    if (x.fi > y.fi) return\
    \ y;\r\n    if (x.se > y.se) swap(x, y);\r\n    return (tie_is_left ? x : y);\r\
    \n  }\r\n  static constexpr X unit() { return {numeric_limits<T>::max(), -1};\
    \ }\r\n  static constexpr bool commute = true;\r\n};\r\n"
  dependsOn: []
  isVerificationFile: false
  path: alg/monoid_min_idx.hpp
  requiredBy:
  - ds/dynamic_lichao.hpp
  - alg/lazy_minidx_add.hpp
  - geo/manhattan_nns.hpp
  timestamp: '2022-05-26 00:06:40+09:00'
  verificationStatus: LIBRARY_ALL_WA
  verifiedWith:
  - test/library_checker/datastructure/line_add_get_min_dynamic.test.cpp
  - test/library_checker/datastructure/segment_add_get_min_dynamic.test.cpp
documentation_of: alg/monoid_min_idx.hpp
layout: document
redirect_from:
- /library/alg/monoid_min_idx.hpp
- /library/alg/monoid_min_idx.hpp.html
title: alg/monoid_min_idx.hpp
---
