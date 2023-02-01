---
data:
  _extendedDependsOn:
  - icon: ':question:'
    path: alg/monoid/add.hpp
    title: alg/monoid/add.hpp
  - icon: ':x:'
    path: alg/monoid/minmincnt.hpp
    title: alg/monoid/minmincnt.hpp
  _extendedRequiredBy:
  - icon: ':x:'
    path: other/rectangle_union.hpp
    title: other/rectangle_union.hpp
  _extendedVerifiedWith:
  - icon: ':x:'
    path: test/aoj/DSL_4_A.test.cpp
    title: test/aoj/DSL_4_A.test.cpp
  - icon: ':x:'
    path: test/library_checker/datastructure/area_of_union_of_rectangles.test.cpp
    title: test/library_checker/datastructure/area_of_union_of_rectangles.test.cpp
  _isVerificationFailed: true
  _pathExtension: hpp
  _verificationStatusIcon: ':x:'
  attributes:
    links: []
  bundledCode: "#line 2 \"alg/monoid/minmincnt.hpp\"\n\r\n// \u6700\u5C0F\u5024\u3001\
    \u6700\u5C0F\u5024\u306E\u500B\u6570\r\ntemplate <typename E>\r\nstruct Monoid_MinMincnt\
    \ {\r\n  using value_type = pair<E, E>;\r\n  using X = value_type;\r\n  static\
    \ X op(X x, X y) {\r\n    auto [xmin, xmincnt] = x;\r\n    auto [ymin, ymincnt]\
    \ = y;\r\n    if (xmin > ymin) return {ymin, ymincnt};\r\n    if (xmin == ymin)\
    \ return {xmin, xmincnt + ymincnt};\r\n    return {xmin, xmincnt};\r\n  }\r\n\
    \  static constexpr X unit() { return {infty<E>, 0}; }\r\n  static constexpr bool\
    \ commute = true;\r\n};\n#line 2 \"alg/monoid/add.hpp\"\n\r\ntemplate <typename\
    \ X>\r\nstruct Monoid_Add {\r\n  using value_type = X;\r\n  static constexpr X\
    \ op(const X &x, const X &y) noexcept { return x + y; }\r\n  static constexpr\
    \ X inverse(const X &x) noexcept { return -x; }\r\n  static constexpr X power(const\
    \ X &x, ll n) noexcept { return X(n) * x; }\r\n  static constexpr X unit() { return\
    \ X(0); }\r\n  static constexpr bool commute = true;\r\n};\r\n#line 3 \"alg/acted_monoid/minmincnt_add.hpp\"\
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
  - other/rectangle_union.hpp
  timestamp: '2023-02-01 23:31:55+09:00'
  verificationStatus: LIBRARY_ALL_WA
  verifiedWith:
  - test/aoj/DSL_4_A.test.cpp
  - test/library_checker/datastructure/area_of_union_of_rectangles.test.cpp
documentation_of: alg/acted_monoid/minmincnt_add.hpp
layout: document
redirect_from:
- /library/alg/acted_monoid/minmincnt_add.hpp
- /library/alg/acted_monoid/minmincnt_add.hpp.html
title: alg/acted_monoid/minmincnt_add.hpp
---
