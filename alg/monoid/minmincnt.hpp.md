---
data:
  _extendedDependsOn: []
  _extendedRequiredBy:
  - icon: ':heavy_check_mark:'
    path: alg/acted_monoid/minmincnt_add.hpp
    title: alg/acted_monoid/minmincnt_add.hpp
  - icon: ':heavy_check_mark:'
    path: ds/rectangle_union.hpp
    title: ds/rectangle_union.hpp
  - icon: ':warning:'
    path: graph/count/count_connected_intervals.hpp
    title: graph/count/count_connected_intervals.hpp
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/2_library_checker/data_structure/area_of_union_of_rectangles.test.cpp
    title: test/2_library_checker/data_structure/area_of_union_of_rectangles.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/4_aoj/DSL_4_A.test.cpp
    title: test/4_aoj/DSL_4_A.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 1 \"alg/monoid/minmincnt.hpp\"\n\n// \u6700\u5C0F\u5024\u3001\
    \u6700\u5C0F\u5024\u306E\u500B\u6570\ntemplate <typename E>\nstruct Monoid_MinMincnt\
    \ {\n  using value_type = pair<E, E>;\n  using X = value_type;\n  static X op(X\
    \ x, X y) {\n    auto [xmin, xmincnt] = x;\n    auto [ymin, ymincnt] = y;\n  \
    \  if (xmin > ymin) return y;\n    if (xmin < ymin) return x;\n    return {xmin,\
    \ xmincnt + ymincnt};\n  }\n  static constexpr X unit() { return {infty<E>, 0};\
    \ }\n  static constexpr bool commute = true;\n};\n"
  code: "\n// \u6700\u5C0F\u5024\u3001\u6700\u5C0F\u5024\u306E\u500B\u6570\ntemplate\
    \ <typename E>\nstruct Monoid_MinMincnt {\n  using value_type = pair<E, E>;\n\
    \  using X = value_type;\n  static X op(X x, X y) {\n    auto [xmin, xmincnt]\
    \ = x;\n    auto [ymin, ymincnt] = y;\n    if (xmin > ymin) return y;\n    if\
    \ (xmin < ymin) return x;\n    return {xmin, xmincnt + ymincnt};\n  }\n  static\
    \ constexpr X unit() { return {infty<E>, 0}; }\n  static constexpr bool commute\
    \ = true;\n};"
  dependsOn: []
  isVerificationFile: false
  path: alg/monoid/minmincnt.hpp
  requiredBy:
  - graph/count/count_connected_intervals.hpp
  - ds/rectangle_union.hpp
  - alg/acted_monoid/minmincnt_add.hpp
  timestamp: '2026-08-16 04:03:00+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/2_library_checker/data_structure/area_of_union_of_rectangles.test.cpp
  - test/4_aoj/DSL_4_A.test.cpp
documentation_of: alg/monoid/minmincnt.hpp
layout: document
redirect_from:
- /library/alg/monoid/minmincnt.hpp
- /library/alg/monoid/minmincnt.hpp.html
title: alg/monoid/minmincnt.hpp
---
