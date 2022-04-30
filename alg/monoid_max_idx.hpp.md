---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/yukicoder/529_two_edge.test.cpp
    title: test/yukicoder/529_two_edge.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 2 \"alg/monoid_max_idx.hpp\"\ntemplate <typename T, T INF>\r\
    \nstruct Monoid_Max_Idx {\r\n  using value_type = pair<T, int>;\r\n  using X =\
    \ value_type;\r\n  static X op(X x, X y) { return max(x, y); }\r\n  static constexpr\
    \ X unit() { return {-INF, -1}; }\r\n  static constexpr bool commute = true;\r\
    \n};\r\n"
  code: "#pragma once\r\ntemplate <typename T, T INF>\r\nstruct Monoid_Max_Idx {\r\
    \n  using value_type = pair<T, int>;\r\n  using X = value_type;\r\n  static X\
    \ op(X x, X y) { return max(x, y); }\r\n  static constexpr X unit() { return {-INF,\
    \ -1}; }\r\n  static constexpr bool commute = true;\r\n};\r\n"
  dependsOn: []
  isVerificationFile: false
  path: alg/monoid_max_idx.hpp
  requiredBy: []
  timestamp: '2022-04-16 04:26:49+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/yukicoder/529_two_edge.test.cpp
documentation_of: alg/monoid_max_idx.hpp
layout: document
redirect_from:
- /library/alg/monoid_max_idx.hpp
- /library/alg/monoid_max_idx.hpp.html
title: alg/monoid_max_idx.hpp
---
