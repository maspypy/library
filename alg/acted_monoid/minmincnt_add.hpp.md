---
data:
  _extendedDependsOn:
  - icon: ':question:'
    path: alg/monoid/add.hpp
    title: alg/monoid/add.hpp
  - icon: ':heavy_check_mark:'
    path: alg/monoid/minmincnt.hpp
    title: alg/monoid/minmincnt.hpp
  _extendedRequiredBy:
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
    \ xmincnt + ymincnt};\n  }\n  static constexpr X id() { return {infty<E>, 0};\
    \ }\n  static constexpr bool commute = true;\n};\n#line 1 \"alg/monoid/add.hpp\"\
    \n\ntemplate <typename E>\nstruct Monoid_Add {\n  using X = E;\n  using value_type\
    \ = X;\n  static constexpr X op(const X &x, const X &y) noexcept { return x +\
    \ y; }\n  static constexpr X inverse(const X &x) noexcept { return -x; }\n  static\
    \ constexpr X power(const X &x, ll n) noexcept { return X(n) * x; }\n  static\
    \ constexpr X id() { return X(0); }\n  static constexpr bool commute = true;\n\
    };\n#line 3 \"alg/acted_monoid/minmincnt_add.hpp\"\n\r\ntemplate <typename E>\r\
    \nstruct ActedMonoid_MinMincnt_Add {\r\n  using Monoid_X = Monoid_MinMincnt<E>;\r\
    \n  using Monoid_A = Monoid_Add<E>;\r\n  using X = typename Monoid_X::value_type;\r\
    \n  using A = typename Monoid_A::value_type;\r\n  static constexpr X act(const\
    \ X &x, const A &a, const ll &size) {\r\n    auto [xmin, xmincnt] = x;\r\n   \
    \ if (xmin == infty<E>) return x;\r\n    return {xmin + a, xmincnt};\r\n  }\r\n\
    };\r\n"
  code: "#include \"alg/monoid/minmincnt.hpp\"\r\n#include \"alg/monoid/add.hpp\"\r\
    \n\r\ntemplate <typename E>\r\nstruct ActedMonoid_MinMincnt_Add {\r\n  using Monoid_X\
    \ = Monoid_MinMincnt<E>;\r\n  using Monoid_A = Monoid_Add<E>;\r\n  using X = typename\
    \ Monoid_X::value_type;\r\n  using A = typename Monoid_A::value_type;\r\n  static\
    \ constexpr X act(const X &x, const A &a, const ll &size) {\r\n    auto [xmin,\
    \ xmincnt] = x;\r\n    if (xmin == infty<E>) return x;\r\n    return {xmin + a,\
    \ xmincnt};\r\n  }\r\n};\r\n"
  dependsOn:
  - alg/monoid/minmincnt.hpp
  - alg/monoid/add.hpp
  isVerificationFile: false
  path: alg/acted_monoid/minmincnt_add.hpp
  requiredBy:
  - graph/count/count_connected_intervals.hpp
  - ds/rectangle_union.hpp
  timestamp: '2026-08-30 21:09:36+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/2_library_checker/data_structure/area_of_union_of_rectangles.test.cpp
  - test/4_aoj/DSL_4_A.test.cpp
documentation_of: alg/acted_monoid/minmincnt_add.hpp
layout: document
redirect_from:
- /library/alg/acted_monoid/minmincnt_add.hpp
- /library/alg/acted_monoid/minmincnt_add.hpp.html
title: alg/acted_monoid/minmincnt_add.hpp
---
