---
data:
  _extendedDependsOn: []
  _extendedRequiredBy:
  - icon: ':warning:'
    path: alg/acted_monoid/cntminmincnt_add.hpp
    title: alg/acted_monoid/cntminmincnt_add.hpp
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':warning:'
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
  - alg/acted_monoid/cntminmincnt_add.hpp
  timestamp: '2022-10-25 12:10:43+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: alg/monoid/cntminmincnt.hpp
layout: document
redirect_from:
- /library/alg/monoid/cntminmincnt.hpp
- /library/alg/monoid/cntminmincnt.hpp.html
title: alg/monoid/cntminmincnt.hpp
---
