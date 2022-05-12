---
data:
  _extendedDependsOn:
  - icon: ':question:'
    path: alg/group_add.hpp
    title: alg/group_add.hpp
  - icon: ':x:'
    path: alg/monoid_cntminmincnt.hpp
    title: alg/monoid_cntminmincnt.hpp
  _extendedRequiredBy:
  - icon: ':x:'
    path: ds/rectangleunion.hpp
    title: ds/rectangleunion.hpp
  _extendedVerifiedWith:
  - icon: ':x:'
    path: test/aoj/DSL_4_A_rectangle_union.test.cpp
    title: test/aoj/DSL_4_A_rectangle_union.test.cpp
  _isVerificationFailed: true
  _pathExtension: hpp
  _verificationStatusIcon: ':x:'
  attributes:
    links: []
  bundledCode: "#line 2 \"alg/monoid_cntminmincnt.hpp\"\n// \u5168\u4F53\u306E\u500B\
    \u6570\u3001\u6700\u5C0F\u5024\u3001\u6700\u5C0F\u5024\u306E\u500B\u6570\r\ntemplate\
    \ <ll INF>\r\nstruct Monoid_CntMinMincnt {\r\n  using value_type = tuple<ll, ll,\
    \ ll>;\r\n  using X = value_type;\r\n  static X op(X x, X y) {\r\n    auto [xcnt,\
    \ xmin, xmincnt] = x;\r\n    auto [ycnt, ymin, ymincnt] = y;\r\n    if (xmin >\
    \ ymin) return {xcnt + ycnt, ymin, ymincnt};\r\n    if (xmin == ymin) return {xcnt\
    \ + ycnt, xmin, xmincnt + ymincnt};\r\n    return {xcnt + ycnt, xmin, xmincnt};\r\
    \n  }\r\n  static constexpr X unit() { return {0, INF, 0}; }\r\n  static constexpr\
    \ bool commute = true;\r\n};\n#line 2 \"alg/group_add.hpp\"\ntemplate <class X>\r\
    \nstruct Group_Add {\r\n  using value_type = X;\r\n  static constexpr X op(const\
    \ X &x, const X &y) noexcept { return x + y; }\r\n  static constexpr X inverse(const\
    \ X &x) noexcept { return -x; }\r\n  static constexpr X power(const X &x, ll n)\
    \ noexcept { return n * x; }\r\n  static constexpr X unit() { return X(0); }\r\
    \n  static constexpr bool commute = true;\r\n};\r\n#line 3 \"alg/lazy_cntminmincnt_add.hpp\"\
    \n\r\ntemplate <ll INF>\r\nstruct Lazy_CntMinMincnt_Add {\r\n  using MX = Monoid_CntMinMincnt<INF>;\r\
    \n  using MA = Group_Add<ll>;\r\n  using X_structure = MX;\r\n  using A_structure\
    \ = MA;\r\n  using X = typename MX::value_type;\r\n  using A = typename MA::value_type;\r\
    \n  static constexpr X act(const X &x, const A &a) {\r\n    auto [xcnt, xmin,\
    \ xmincnt] = x;\r\n    return {xcnt, min(INF, xmin + a), xmincnt};\r\n  }\r\n\
    };\n"
  code: "#include \"alg/monoid_cntminmincnt.hpp\"\r\n#include \"alg/group_add.hpp\"\
    \r\n\r\ntemplate <ll INF>\r\nstruct Lazy_CntMinMincnt_Add {\r\n  using MX = Monoid_CntMinMincnt<INF>;\r\
    \n  using MA = Group_Add<ll>;\r\n  using X_structure = MX;\r\n  using A_structure\
    \ = MA;\r\n  using X = typename MX::value_type;\r\n  using A = typename MA::value_type;\r\
    \n  static constexpr X act(const X &x, const A &a) {\r\n    auto [xcnt, xmin,\
    \ xmincnt] = x;\r\n    return {xcnt, min(INF, xmin + a), xmincnt};\r\n  }\r\n\
    };"
  dependsOn:
  - alg/monoid_cntminmincnt.hpp
  - alg/group_add.hpp
  isVerificationFile: false
  path: alg/lazy_cntminmincnt_add.hpp
  requiredBy:
  - ds/rectangleunion.hpp
  timestamp: '2022-04-16 04:26:49+09:00'
  verificationStatus: LIBRARY_ALL_WA
  verifiedWith:
  - test/aoj/DSL_4_A_rectangle_union.test.cpp
documentation_of: alg/lazy_cntminmincnt_add.hpp
layout: document
redirect_from:
- /library/alg/lazy_cntminmincnt_add.hpp
- /library/alg/lazy_cntminmincnt_add.hpp.html
title: alg/lazy_cntminmincnt_add.hpp
---
