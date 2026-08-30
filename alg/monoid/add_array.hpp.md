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
  bundledCode: "#line 1 \"alg/monoid/add_array.hpp\"\n\ntemplate <typename E, int\
    \ K>\nstruct Monoid_Add_Array {\n  using value_type = array<E, K>;\n  using X\
    \ = value_type;\n  static X op(X x, X y) {\n    FOR(i, K) x[i] += y[i];\n    return\
    \ x;\n  }\n  static constexpr X id() { return X{}; }\n  static constexpr X inverse(X\
    \ x) {\n    for (auto& v: x) v = -v;\n    return x;\n  }\n  static constexpr X\
    \ power(X x, ll n) {\n    for (auto& v: x) v *= E(n);\n    return x;\n  }\n  static\
    \ constexpr bool commute = 1;\n};\n"
  code: "\ntemplate <typename E, int K>\nstruct Monoid_Add_Array {\n  using value_type\
    \ = array<E, K>;\n  using X = value_type;\n  static X op(X x, X y) {\n    FOR(i,\
    \ K) x[i] += y[i];\n    return x;\n  }\n  static constexpr X id() { return X{};\
    \ }\n  static constexpr X inverse(X x) {\n    for (auto& v: x) v = -v;\n    return\
    \ x;\n  }\n  static constexpr X power(X x, ll n) {\n    for (auto& v: x) v *=\
    \ E(n);\n    return x;\n  }\n  static constexpr bool commute = 1;\n};\n"
  dependsOn: []
  isVerificationFile: false
  path: alg/monoid/add_array.hpp
  requiredBy:
  - alg/acted_monoid/powersums_assign.hpp
  timestamp: '2026-08-30 21:09:36+09:00'
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
