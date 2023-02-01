---
data:
  _extendedDependsOn: []
  _extendedRequiredBy:
  - icon: ':heavy_check_mark:'
    path: alg/acted_monoid/minmincnt_add.hpp
    title: alg/acted_monoid/minmincnt_add.hpp
  - icon: ':heavy_check_mark:'
    path: other/rectangle_union.hpp
    title: other/rectangle_union.hpp
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/aoj/DSL_4_A.test.cpp
    title: test/aoj/DSL_4_A.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/library_checker/datastructure/area_of_union_of_rectangles.test.cpp
    title: test/library_checker/datastructure/area_of_union_of_rectangles.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 2 \"alg/monoid/minmincnt.hpp\"\n\r\n// \u6700\u5C0F\u5024\u3001\
    \u6700\u5C0F\u5024\u306E\u500B\u6570\r\ntemplate <typename E>\r\nstruct Monoid_MinMincnt\
    \ {\r\n  using value_type = pair<E, E>;\r\n  using X = value_type;\r\n  static\
    \ X op(X x, X y) {\r\n    auto [xmin, xmincnt] = x;\r\n    auto [ymin, ymincnt]\
    \ = y;\r\n    if (xmin > ymin) return {ymin, ymincnt};\r\n    if (xmin == ymin)\
    \ return {xmin, xmincnt + ymincnt};\r\n    return {xmin, xmincnt};\r\n  }\r\n\
    \  static constexpr X unit() { return {infty<E>, 0}; }\r\n  static constexpr bool\
    \ commute = true;\r\n};\n"
  code: "#pragma once\r\n\r\n// \u6700\u5C0F\u5024\u3001\u6700\u5C0F\u5024\u306E\u500B\
    \u6570\r\ntemplate <typename E>\r\nstruct Monoid_MinMincnt {\r\n  using value_type\
    \ = pair<E, E>;\r\n  using X = value_type;\r\n  static X op(X x, X y) {\r\n  \
    \  auto [xmin, xmincnt] = x;\r\n    auto [ymin, ymincnt] = y;\r\n    if (xmin\
    \ > ymin) return {ymin, ymincnt};\r\n    if (xmin == ymin) return {xmin, xmincnt\
    \ + ymincnt};\r\n    return {xmin, xmincnt};\r\n  }\r\n  static constexpr X unit()\
    \ { return {infty<E>, 0}; }\r\n  static constexpr bool commute = true;\r\n};"
  dependsOn: []
  isVerificationFile: false
  path: alg/monoid/minmincnt.hpp
  requiredBy:
  - alg/acted_monoid/minmincnt_add.hpp
  - other/rectangle_union.hpp
  timestamp: '2023-02-01 23:31:55+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/aoj/DSL_4_A.test.cpp
  - test/library_checker/datastructure/area_of_union_of_rectangles.test.cpp
documentation_of: alg/monoid/minmincnt.hpp
layout: document
redirect_from:
- /library/alg/monoid/minmincnt.hpp
- /library/alg/monoid/minmincnt.hpp.html
title: alg/monoid/minmincnt.hpp
---
