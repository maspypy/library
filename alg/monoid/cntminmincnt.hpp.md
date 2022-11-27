---
data:
  _extendedDependsOn: []
  _extendedRequiredBy:
  - icon: ':heavy_check_mark:'
    path: alg/lazy/cntminmincnt_add.hpp
    title: alg/lazy/cntminmincnt_add.hpp
  - icon: ':heavy_check_mark:'
    path: ds/query/rectangleunion.hpp
    title: ds/query/rectangleunion.hpp
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
  bundledCode: "#line 2 \"alg/monoid/cntminmincnt.hpp\"\n\r\n// \u5168\u4F53\u306E\
    \u500B\u6570\u3001\u6700\u5C0F\u5024\u3001\u6700\u5C0F\u5024\u306E\u500B\u6570\
    \r\ntemplate <typename E>\r\nstruct Monoid_CntMinMincnt {\r\n  using value_type\
    \ = tuple<E, E, E>;\r\n  using X = value_type;\r\n  static X from_element(E x)\
    \ { return {1, x, 1}; }\r\n  static X op(X x, X y) {\r\n    auto [xcnt, xmin,\
    \ xmincnt] = x;\r\n    auto [ycnt, ymin, ymincnt] = y;\r\n    if (xmin > ymin)\
    \ return {xcnt + ycnt, ymin, ymincnt};\r\n    if (xmin == ymin) return {xcnt +\
    \ ycnt, xmin, xmincnt + ymincnt};\r\n    return {xcnt + ycnt, xmin, xmincnt};\r\
    \n  }\r\n  static constexpr X unit() { return {0, numeric_limits<E>::max(), 0};\
    \ }\r\n  static constexpr bool commute = true;\r\n};\n"
  code: "#pragma once\r\n\r\n// \u5168\u4F53\u306E\u500B\u6570\u3001\u6700\u5C0F\u5024\
    \u3001\u6700\u5C0F\u5024\u306E\u500B\u6570\r\ntemplate <typename E>\r\nstruct\
    \ Monoid_CntMinMincnt {\r\n  using value_type = tuple<E, E, E>;\r\n  using X =\
    \ value_type;\r\n  static X from_element(E x) { return {1, x, 1}; }\r\n  static\
    \ X op(X x, X y) {\r\n    auto [xcnt, xmin, xmincnt] = x;\r\n    auto [ycnt, ymin,\
    \ ymincnt] = y;\r\n    if (xmin > ymin) return {xcnt + ycnt, ymin, ymincnt};\r\
    \n    if (xmin == ymin) return {xcnt + ycnt, xmin, xmincnt + ymincnt};\r\n   \
    \ return {xcnt + ycnt, xmin, xmincnt};\r\n  }\r\n  static constexpr X unit() {\
    \ return {0, numeric_limits<E>::max(), 0}; }\r\n  static constexpr bool commute\
    \ = true;\r\n};"
  dependsOn: []
  isVerificationFile: false
  path: alg/monoid/cntminmincnt.hpp
  requiredBy:
  - alg/lazy/cntminmincnt_add.hpp
  - ds/query/rectangleunion.hpp
  timestamp: '2022-10-25 12:10:43+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/library_checker/datastructure/area_of_union_of_rectangles.test.cpp
  - test/aoj/DSL_4_A.test.cpp
documentation_of: alg/monoid/cntminmincnt.hpp
layout: document
redirect_from:
- /library/alg/monoid/cntminmincnt.hpp
- /library/alg/monoid/cntminmincnt.hpp.html
title: alg/monoid/cntminmincnt.hpp
---
