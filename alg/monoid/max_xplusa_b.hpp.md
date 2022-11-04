---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/yukicoder/1524.test.cpp
    title: test/yukicoder/1524.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 2 \"alg/monoid/max_xplusa_b.hpp\"\n\r\n// max(x+a, b) \u306E\
    \u5408\u6210\r\ntemplate <typename T>\r\nstruct Monoid_Max_xplusa_b {\r\n  using\
    \ value_type = pair<T, T>;\r\n  using X = value_type;\r\n  static const T LIM\
    \ = numeric_limits<T>::lowest();\r\n\r\n  static X add(T x) { return {x, LIM};\
    \ }\r\n  static X chmax(T x) { return {0, x}; }\r\n\r\n  static T op_add(T x,\
    \ T y) {\r\n    if (x == LIM) return LIM;\r\n    if (y == LIM) return LIM;\r\n\
    \    return x + y;\r\n  }\r\n  static T eval(X f, T x) {\r\n    auto [a, b] =\
    \ f;\r\n    return max(x + a, b);\r\n  }\r\n\r\n  static X op(X A, X B) {\r\n\
    \    auto [a, b] = A;\r\n    auto [c, d] = B;\r\n    return {op_add(a, c), max(op_add(b,\
    \ c), d)};\r\n  }\r\n  static constexpr X unit() { return {0, LIM}; }\r\n  static\
    \ constexpr bool commute = false;\r\n};\n"
  code: "#pragma once\r\n\r\n// max(x+a, b) \u306E\u5408\u6210\r\ntemplate <typename\
    \ T>\r\nstruct Monoid_Max_xplusa_b {\r\n  using value_type = pair<T, T>;\r\n \
    \ using X = value_type;\r\n  static const T LIM = numeric_limits<T>::lowest();\r\
    \n\r\n  static X add(T x) { return {x, LIM}; }\r\n  static X chmax(T x) { return\
    \ {0, x}; }\r\n\r\n  static T op_add(T x, T y) {\r\n    if (x == LIM) return LIM;\r\
    \n    if (y == LIM) return LIM;\r\n    return x + y;\r\n  }\r\n  static T eval(X\
    \ f, T x) {\r\n    auto [a, b] = f;\r\n    return max(x + a, b);\r\n  }\r\n\r\n\
    \  static X op(X A, X B) {\r\n    auto [a, b] = A;\r\n    auto [c, d] = B;\r\n\
    \    return {op_add(a, c), max(op_add(b, c), d)};\r\n  }\r\n  static constexpr\
    \ X unit() { return {0, LIM}; }\r\n  static constexpr bool commute = false;\r\n\
    };"
  dependsOn: []
  isVerificationFile: false
  path: alg/monoid/max_xplusa_b.hpp
  requiredBy: []
  timestamp: '2022-10-28 17:47:13+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/yukicoder/1524.test.cpp
documentation_of: alg/monoid/max_xplusa_b.hpp
layout: document
redirect_from:
- /library/alg/monoid/max_xplusa_b.hpp
- /library/alg/monoid/max_xplusa_b.hpp.html
title: alg/monoid/max_xplusa_b.hpp
---
