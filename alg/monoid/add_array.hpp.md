---
data:
  _extendedDependsOn: []
  _extendedRequiredBy:
  - icon: ':x:'
    path: alg/acted_monoid/powersums_assign.hpp
    title: alg/acted_monoid/powersums_assign.hpp
  _extendedVerifiedWith:
  - icon: ':x:'
    path: test/3_yukicoder/1548.test.cpp
    title: test/3_yukicoder/1548.test.cpp
  _isVerificationFailed: true
  _pathExtension: hpp
  _verificationStatusIcon: ':x:'
  attributes:
    links: []
  bundledCode: "#line 1 \"alg/monoid/add_array.hpp\"\n\ntemplate <typename E, int\
    \ K>\nstruct Monoid_Add_Array {\n  using value_type = array<E, K>;\n  using X\
    \ = value_type;\n  static X op(X x, X y) {\n    FOR(i, K) x[i] += y[i];\n    return\
    \ x;\n  }\n  static constexpr X unit() { return X{}; }\n  static constexpr X inverse(X\
    \ x) {\n    for (auto& v: x) v = -v;\n    return x;\n  }\n  static constexpr X\
    \ power(X x, ll n) {\n    for (auto& v: x) v *= E(n);\n    return x;\n  }\n  static\
    \ constexpr bool commute = 1;\n};\n"
  code: "\ntemplate <typename E, int K>\nstruct Monoid_Add_Array {\n  using value_type\
    \ = array<E, K>;\n  using X = value_type;\n  static X op(X x, X y) {\n    FOR(i,\
    \ K) x[i] += y[i];\n    return x;\n  }\n  static constexpr X unit() { return X{};\
    \ }\n  static constexpr X inverse(X x) {\n    for (auto& v: x) v = -v;\n    return\
    \ x;\n  }\n  static constexpr X power(X x, ll n) {\n    for (auto& v: x) v *=\
    \ E(n);\n    return x;\n  }\n  static constexpr bool commute = 1;\n};\n"
  dependsOn: []
  isVerificationFile: false
  path: alg/monoid/add_array.hpp
  requiredBy:
  - alg/acted_monoid/powersums_assign.hpp
  timestamp: '2026-08-16 04:03:00+09:00'
  verificationStatus: LIBRARY_ALL_WA
  verifiedWith:
  - test/3_yukicoder/1548.test.cpp
documentation_of: alg/monoid/add_array.hpp
layout: document
redirect_from:
- /library/alg/monoid/add_array.hpp
- /library/alg/monoid/add_array.hpp.html
title: alg/monoid/add_array.hpp
---
