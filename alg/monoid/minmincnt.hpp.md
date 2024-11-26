---
data:
  _extendedDependsOn: []
  _extendedRequiredBy:
  - icon: ':question:'
    path: alg/acted_monoid/minmincnt_add.hpp
    title: alg/acted_monoid/minmincnt_add.hpp
  - icon: ':question:'
    path: ds/rectangle_union.hpp
    title: ds/rectangle_union.hpp
  - icon: ':warning:'
    path: graph/count/count_connected_intervals.hpp
    title: graph/count/count_connected_intervals.hpp
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/2_library_checker/data_structure/area_of_union_of_rectangles.test.cpp
    title: test/2_library_checker/data_structure/area_of_union_of_rectangles.test.cpp
  - icon: ':x:'
    path: test/4_aoj/DSL_4_A.test.cpp
    title: test/4_aoj/DSL_4_A.test.cpp
  - icon: ':x:'
    path: test/5_atcoder/abc318b.test.cpp
    title: test/5_atcoder/abc318b.test.cpp
  _isVerificationFailed: true
  _pathExtension: hpp
  _verificationStatusIcon: ':question:'
  attributes:
    links: []
  bundledCode: "#line 2 \"alg/monoid/minmincnt.hpp\"\n\r\n// \u6700\u5C0F\u5024\u3001\
    \u6700\u5C0F\u5024\u306E\u500B\u6570\r\ntemplate <typename E>\r\nstruct Monoid_MinMincnt\
    \ {\r\n  using value_type = pair<E, E>;\r\n  using X = value_type;\r\n  static\
    \ X op(X x, X y) {\r\n    auto [xmin, xmincnt] = x;\r\n    auto [ymin, ymincnt]\
    \ = y;\r\n    if (xmin > ymin) return y;\r\n    if (xmin < ymin) return x;\r\n\
    \    return {xmin, xmincnt + ymincnt};\r\n  }\r\n  static constexpr X unit() {\
    \ return {infty<E>, 0}; }\r\n  static constexpr bool commute = true;\r\n};\n"
  code: "#pragma once\r\n\r\n// \u6700\u5C0F\u5024\u3001\u6700\u5C0F\u5024\u306E\u500B\
    \u6570\r\ntemplate <typename E>\r\nstruct Monoid_MinMincnt {\r\n  using value_type\
    \ = pair<E, E>;\r\n  using X = value_type;\r\n  static X op(X x, X y) {\r\n  \
    \  auto [xmin, xmincnt] = x;\r\n    auto [ymin, ymincnt] = y;\r\n    if (xmin\
    \ > ymin) return y;\r\n    if (xmin < ymin) return x;\r\n    return {xmin, xmincnt\
    \ + ymincnt};\r\n  }\r\n  static constexpr X unit() { return {infty<E>, 0}; }\r\
    \n  static constexpr bool commute = true;\r\n};"
  dependsOn: []
  isVerificationFile: false
  path: alg/monoid/minmincnt.hpp
  requiredBy:
  - ds/rectangle_union.hpp
  - alg/acted_monoid/minmincnt_add.hpp
  - graph/count/count_connected_intervals.hpp
  timestamp: '2023-04-02 02:09:38+09:00'
  verificationStatus: LIBRARY_SOME_WA
  verifiedWith:
  - test/4_aoj/DSL_4_A.test.cpp
  - test/5_atcoder/abc318b.test.cpp
  - test/2_library_checker/data_structure/area_of_union_of_rectangles.test.cpp
documentation_of: alg/monoid/minmincnt.hpp
layout: document
redirect_from:
- /library/alg/monoid/minmincnt.hpp
- /library/alg/monoid/minmincnt.hpp.html
title: alg/monoid/minmincnt.hpp
---
