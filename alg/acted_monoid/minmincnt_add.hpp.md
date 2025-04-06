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
  bundledCode: "#line 2 \"alg/monoid/minmincnt.hpp\"\n\r\n// \u6700\u5C0F\u5024\u3001\
    \u6700\u5C0F\u5024\u306E\u500B\u6570\r\ntemplate <typename E>\r\nstruct Monoid_MinMincnt\
    \ {\r\n  using value_type = pair<E, E>;\r\n  using X = value_type;\r\n  static\
    \ X op(X x, X y) {\r\n    auto [xmin, xmincnt] = x;\r\n    auto [ymin, ymincnt]\
    \ = y;\r\n    if (xmin > ymin) return y;\r\n    if (xmin < ymin) return x;\r\n\
    \    return {xmin, xmincnt + ymincnt};\r\n  }\r\n  static constexpr X unit() {\
    \ return {infty<E>, 0}; }\r\n  static constexpr bool commute = true;\r\n};\n#line\
    \ 2 \"alg/monoid/add.hpp\"\n\r\ntemplate <typename E>\r\nstruct Monoid_Add {\r\
    \n  using X = E;\r\n  using value_type = X;\r\n  static constexpr X op(const X\
    \ &x, const X &y) noexcept { return x + y; }\r\n  static constexpr X inverse(const\
    \ X &x) noexcept { return -x; }\r\n  static constexpr X power(const X &x, ll n)\
    \ noexcept { return X(n) * x; }\r\n  static constexpr X unit() { return X(0);\
    \ }\r\n  static constexpr bool commute = true;\r\n};\r\n#line 3 \"alg/acted_monoid/minmincnt_add.hpp\"\
    \n\r\ntemplate <typename E>\r\nstruct ActedMonoid_MinMincnt_Add {\r\n  using Monoid_X\
    \ = Monoid_MinMincnt<E>;\r\n  using Monoid_A = Monoid_Add<E>;\r\n  using X = typename\
    \ Monoid_X::value_type;\r\n  using A = typename Monoid_A::value_type;\r\n  static\
    \ constexpr X act(const X &x, const A &a, const ll &size) {\r\n    auto [xmin,\
    \ xmincnt] = x;\r\n    if (xmin == infty<E>) return x;\r\n    return {xmin + a,\
    \ xmincnt};\r\n  }\r\n};\r\n"
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
  timestamp: '2024-01-23 05:58:02+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/4_aoj/DSL_4_A.test.cpp
  - test/2_library_checker/data_structure/area_of_union_of_rectangles.test.cpp
documentation_of: alg/acted_monoid/minmincnt_add.hpp
layout: document
redirect_from:
- /library/alg/acted_monoid/minmincnt_add.hpp
- /library/alg/acted_monoid/minmincnt_add.hpp.html
title: alg/acted_monoid/minmincnt_add.hpp
---
