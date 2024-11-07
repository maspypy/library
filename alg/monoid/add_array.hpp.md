---
data:
  _extendedDependsOn: []
  _extendedRequiredBy:
  - icon: ':heavy_check_mark:'
    path: alg/acted_monoid/powersums_assign.hpp
    title: alg/acted_monoid/powersums_assign.hpp
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/3_yukicoder/1548.test.cpp
    title: test/3_yukicoder/1548.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 2 \"alg/monoid/add_array.hpp\"\n\r\ntemplate <typename E, int\
    \ K>\r\nstruct Monoid_Add_Array {\r\n  using value_type = array<E, K>;\r\n  using\
    \ X = value_type;\r\n  static X op(X x, X y) {\r\n    FOR(i, K) x[i] += y[i];\r\
    \n    return x;\r\n  }\r\n  static constexpr X unit() { return X{}; }\r\n  static\
    \ constexpr X inverse(X x) {\r\n    for (auto& v: x) v = -v;\r\n    return x;\r\
    \n  }\r\n  static constexpr X power(X x, ll n) {\r\n    for (auto& v: x) v *=\
    \ E(n);\r\n    return x;\r\n  }\r\n  static constexpr bool commute = 1;\r\n};\r\
    \n"
  code: "#pragma once\r\n\r\ntemplate <typename E, int K>\r\nstruct Monoid_Add_Array\
    \ {\r\n  using value_type = array<E, K>;\r\n  using X = value_type;\r\n  static\
    \ X op(X x, X y) {\r\n    FOR(i, K) x[i] += y[i];\r\n    return x;\r\n  }\r\n\
    \  static constexpr X unit() { return X{}; }\r\n  static constexpr X inverse(X\
    \ x) {\r\n    for (auto& v: x) v = -v;\r\n    return x;\r\n  }\r\n  static constexpr\
    \ X power(X x, ll n) {\r\n    for (auto& v: x) v *= E(n);\r\n    return x;\r\n\
    \  }\r\n  static constexpr bool commute = 1;\r\n};\r\n"
  dependsOn: []
  isVerificationFile: false
  path: alg/monoid/add_array.hpp
  requiredBy:
  - alg/acted_monoid/powersums_assign.hpp
  timestamp: '2023-10-14 01:43:46+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/3_yukicoder/1548.test.cpp
documentation_of: alg/monoid/add_array.hpp
layout: document
redirect_from:
- /library/alg/monoid/add_array.hpp
- /library/alg/monoid/add_array.hpp.html
title: alg/monoid/add_array.hpp
---
