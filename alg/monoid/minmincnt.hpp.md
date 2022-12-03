---
data:
  _extendedDependsOn: []
  _extendedRequiredBy:
  - icon: ':warning:'
    path: alg/acted_monoid/minmincnt_add.hpp
    title: alg/acted_monoid/minmincnt_add.hpp
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':warning:'
  attributes:
    links: []
  bundledCode: "#line 2 \"alg/monoid/minmincnt.hpp\"\n\r\n// \u6700\u5C0F\u5024\u3001\
    \u6700\u5C0F\u5024\u306E\u500B\u6570\r\ntemplate <typename E>\r\nstruct Monoid_MinMincnt\
    \ {\r\n  using value_type = tuple<E, E, E>;\r\n  using X = value_type;\r\n  static\
    \ X from_element(E x) { return {x, 1}; }\r\n  static X op(X x, X y) {\r\n    auto\
    \ [xmin, xmincnt] = x;\r\n    auto [ymin, ymincnt] = y;\r\n    if (xmin > ymin)\
    \ return {ymin, ymincnt};\r\n    if (xmin == ymin) return {xmin, xmincnt + ymincnt};\r\
    \n    return {xmin, xmincnt};\r\n  }\r\n  static constexpr X unit() { return {numeric_limits<E>::max(),\
    \ 0}; }\r\n  static constexpr bool commute = true;\r\n};\n"
  code: "#pragma once\r\n\r\n// \u6700\u5C0F\u5024\u3001\u6700\u5C0F\u5024\u306E\u500B\
    \u6570\r\ntemplate <typename E>\r\nstruct Monoid_MinMincnt {\r\n  using value_type\
    \ = tuple<E, E, E>;\r\n  using X = value_type;\r\n  static X from_element(E x)\
    \ { return {x, 1}; }\r\n  static X op(X x, X y) {\r\n    auto [xmin, xmincnt]\
    \ = x;\r\n    auto [ymin, ymincnt] = y;\r\n    if (xmin > ymin) return {ymin,\
    \ ymincnt};\r\n    if (xmin == ymin) return {xmin, xmincnt + ymincnt};\r\n   \
    \ return {xmin, xmincnt};\r\n  }\r\n  static constexpr X unit() { return {numeric_limits<E>::max(),\
    \ 0}; }\r\n  static constexpr bool commute = true;\r\n};"
  dependsOn: []
  isVerificationFile: false
  path: alg/monoid/minmincnt.hpp
  requiredBy:
  - alg/acted_monoid/minmincnt_add.hpp
  timestamp: '2022-12-03 07:16:30+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: alg/monoid/minmincnt.hpp
layout: document
redirect_from:
- /library/alg/monoid/minmincnt.hpp
- /library/alg/monoid/minmincnt.hpp.html
title: alg/monoid/minmincnt.hpp
---
