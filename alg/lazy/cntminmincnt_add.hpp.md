---
data:
  _extendedDependsOn:
  - icon: ':question:'
    path: alg/monoid/add.hpp
    title: alg/monoid/add.hpp
  - icon: ':heavy_check_mark:'
    path: alg/monoid/cntminmincnt.hpp
    title: alg/monoid/cntminmincnt.hpp
  _extendedRequiredBy:
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
    \ }\r\n  static constexpr bool commute = true;\r\n};\n#line 2 \"alg/monoid/add.hpp\"\
    \n\r\ntemplate <typename E>\r\nstruct Monoid_Add {\r\n  using X = E;\r\n  using\
    \ value_type = X;\r\n  static constexpr X op(const X &x, const X &y) noexcept\
    \ { return x + y; }\r\n  static constexpr X inverse(const X &x) noexcept { return\
    \ -x; }\r\n  static constexpr X power(const X &x, ll n) noexcept { return X(n)\
    \ * x; }\r\n  static constexpr X unit() { return X(0); }\r\n  static constexpr\
    \ bool commute = true;\r\n};\r\n#line 3 \"alg/lazy/cntminmincnt_add.hpp\"\n\r\n\
    template <typename E>\r\nstruct Lazy_CntMinMincnt_Add {\r\n  using MX = Monoid_CntMinMincnt<E>;\r\
    \n  using MA = Monoid_Add<E>;\r\n  using X_structure = MX;\r\n  using A_structure\
    \ = MA;\r\n  using X = typename MX::value_type;\r\n  using A = typename MA::value_type;\r\
    \n  static constexpr X act(const X &x, const A &a) {\r\n    auto [xcnt, xmin,\
    \ xmincnt] = x;\r\n    if (xmin == numeric_limits<ll>::max()) return x;\r\n  \
    \  return {xcnt, xmin + a, xmincnt};\r\n  }\r\n};\r\n"
  code: "#include \"alg/monoid/cntminmincnt.hpp\"\r\n#include \"alg/monoid/add.hpp\"\
    \r\n\r\ntemplate <typename E>\r\nstruct Lazy_CntMinMincnt_Add {\r\n  using MX\
    \ = Monoid_CntMinMincnt<E>;\r\n  using MA = Monoid_Add<E>;\r\n  using X_structure\
    \ = MX;\r\n  using A_structure = MA;\r\n  using X = typename MX::value_type;\r\
    \n  using A = typename MA::value_type;\r\n  static constexpr X act(const X &x,\
    \ const A &a) {\r\n    auto [xcnt, xmin, xmincnt] = x;\r\n    if (xmin == numeric_limits<ll>::max())\
    \ return x;\r\n    return {xcnt, xmin + a, xmincnt};\r\n  }\r\n};\r\n"
  dependsOn:
  - alg/monoid/cntminmincnt.hpp
  - alg/monoid/add.hpp
  isVerificationFile: false
  path: alg/lazy/cntminmincnt_add.hpp
  requiredBy:
  - ds/query/rectangleunion.hpp
  timestamp: '2022-11-27 15:42:25+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/library_checker/datastructure/area_of_union_of_rectangles.test.cpp
  - test/aoj/DSL_4_A.test.cpp
documentation_of: alg/lazy/cntminmincnt_add.hpp
layout: document
redirect_from:
- /library/alg/lazy/cntminmincnt_add.hpp
- /library/alg/lazy/cntminmincnt_add.hpp.html
title: alg/lazy/cntminmincnt_add.hpp
---
