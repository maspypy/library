---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':warning:'
  attributes:
    links: []
  bundledCode: "#line 2 \"alg/monoid_max_xplusa_b.hpp\"\n\r\n// max(x+a, b) \u306E\
    \u5408\u6210\r\ntemplate <typename T, T INF>\r\nstruct Monoid_Max_xplusa_b {\r\
    \n  using value_type = pi;\r\n  using X = value_type;\r\n  static X op(X A, X\
    \ B) {\r\n    auto [a, b] = A;\r\n    auto [c, d] = B;\r\n    ll e = a + c, f\
    \ = max(b + c, d);\r\n    chmax(e, -INF);\r\n    chmax(f, -INF);\r\n    return\
    \ {e, f};\r\n  }\r\n  static constexpr X unit() { return {0, -INF}; }\r\n  static\
    \ constexpr bool commute = false;\r\n};\n"
  code: "#pragma once\r\n\r\n// max(x+a, b) \u306E\u5408\u6210\r\ntemplate <typename\
    \ T, T INF>\r\nstruct Monoid_Max_xplusa_b {\r\n  using value_type = pi;\r\n  using\
    \ X = value_type;\r\n  static X op(X A, X B) {\r\n    auto [a, b] = A;\r\n   \
    \ auto [c, d] = B;\r\n    ll e = a + c, f = max(b + c, d);\r\n    chmax(e, -INF);\r\
    \n    chmax(f, -INF);\r\n    return {e, f};\r\n  }\r\n  static constexpr X unit()\
    \ { return {0, -INF}; }\r\n  static constexpr bool commute = false;\r\n};"
  dependsOn: []
  isVerificationFile: false
  path: alg/monoid_max_xplusa_b.hpp
  requiredBy: []
  timestamp: '2022-04-16 04:26:49+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: alg/monoid_max_xplusa_b.hpp
layout: document
redirect_from:
- /library/alg/monoid_max_xplusa_b.hpp
- /library/alg/monoid_max_xplusa_b.hpp.html
title: alg/monoid_max_xplusa_b.hpp
---
