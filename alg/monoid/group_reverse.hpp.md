---
data:
  _extendedDependsOn: []
  _extendedRequiredBy:
  - icon: ':question:'
    path: graph/ds/tree_group.hpp
    title: graph/ds/tree_group.hpp
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/library_checker/datastructure/vertex_add_path_sum_group.test.cpp
    title: test/library_checker/datastructure/vertex_add_path_sum_group.test.cpp
  - icon: ':x:'
    path: test/library_checker/datastructure/vertex_set_path_composite_group.test.cpp
    title: test/library_checker/datastructure/vertex_set_path_composite_group.test.cpp
  _isVerificationFailed: true
  _pathExtension: hpp
  _verificationStatusIcon: ':question:'
  attributes:
    links: []
  bundledCode: "#line 2 \"alg/monoid/group_reverse.hpp\"\n\r\ntemplate <class Group>\r\
    \nstruct Group_Reverse {\r\n  using value_type = typename Group::value_type;\r\
    \n  using X = value_type;\r\n  static constexpr X op(const X &x, const X &y) {\
    \ return Group::op(y, x); }\r\n  static constexpr X inverse(const X &x) { return\
    \ Group::inverse(x); }\r\n  static constexpr X unit() { return Group::unit();\
    \ }\r\n  static const bool commute = Group::commute;\r\n};\r\n"
  code: "#pragma once\r\n\r\ntemplate <class Group>\r\nstruct Group_Reverse {\r\n\
    \  using value_type = typename Group::value_type;\r\n  using X = value_type;\r\
    \n  static constexpr X op(const X &x, const X &y) { return Group::op(y, x); }\r\
    \n  static constexpr X inverse(const X &x) { return Group::inverse(x); }\r\n \
    \ static constexpr X unit() { return Group::unit(); }\r\n  static const bool commute\
    \ = Group::commute;\r\n};\r\n"
  dependsOn: []
  isVerificationFile: false
  path: alg/monoid/group_reverse.hpp
  requiredBy:
  - graph/ds/tree_group.hpp
  timestamp: '2022-12-01 09:04:06+09:00'
  verificationStatus: LIBRARY_SOME_WA
  verifiedWith:
  - test/library_checker/datastructure/vertex_set_path_composite_group.test.cpp
  - test/library_checker/datastructure/vertex_add_path_sum_group.test.cpp
documentation_of: alg/monoid/group_reverse.hpp
layout: document
redirect_from:
- /library/alg/monoid/group_reverse.hpp
- /library/alg/monoid/group_reverse.hpp.html
title: alg/monoid/group_reverse.hpp
---
