---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: alg/monoid/add_array.hpp
    title: alg/monoid/add_array.hpp
  - icon: ':heavy_check_mark:'
    path: alg/monoid/assign.hpp
    title: alg/monoid/assign.hpp
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/3_yukicoder/1548.test.cpp
    title: test/3_yukicoder/1548.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 1 \"alg/acted_monoid/powersums_assign.hpp\"\n\n#line 1 \"alg/monoid/assign.hpp\"\
    \n\ntemplate <typename X, int none_val>\nstruct Monoid_Assign {\n  using value_type\
    \ = X;\n  static X op(X x, X y) { return (y == X(none_val) ? x : y); }\n  static\
    \ constexpr X id() { return X(none_val); }\n  static constexpr bool commute =\
    \ false;\n};\n#line 1 \"alg/monoid/add_array.hpp\"\n\ntemplate <typename E, int\
    \ K>\nstruct Monoid_Add_Array {\n  using value_type = array<E, K>;\n  using X\
    \ = value_type;\n  static X op(X x, X y) {\n    FOR(i, K) x[i] += y[i];\n    return\
    \ x;\n  }\n  static constexpr X id() { return X{}; }\n  static constexpr X inverse(X\
    \ x) {\n    for (auto& v: x) v = -v;\n    return x;\n  }\n  static constexpr X\
    \ power(X x, ll n) {\n    for (auto& v: x) v *= E(n);\n    return x;\n  }\n  static\
    \ constexpr bool commute = 1;\n};\n#line 4 \"alg/acted_monoid/powersums_assign.hpp\"\
    \n\n// 0, 1, ..., K \u4E57\u548C\ntemplate <typename T, int K>\nstruct ActedMonoid_Power_Sums_Assign\
    \ {\n  using Monoid_X = Monoid_Add_Array<T, K + 1>;\n  using Monoid_A = Monoid_Assign<T,\
    \ -1>;\n  using X = typename Monoid_X::value_type;\n  using A = typename Monoid_A::value_type;\n\
    \  static constexpr X act(const X &x, const A &a, const ll &size) {\n    if (a\
    \ == Monoid_A::id()) return x;\n    X y;\n    T pow = 1;\n    FOR(i, K + 1) {\
    \ y[i] = x[0] * pow, pow *= a; }\n    return y;\n  }\n};\n"
  code: "\n#include \"alg/monoid/assign.hpp\"\n#include \"alg/monoid/add_array.hpp\"\
    \n\n// 0, 1, ..., K \u4E57\u548C\ntemplate <typename T, int K>\nstruct ActedMonoid_Power_Sums_Assign\
    \ {\n  using Monoid_X = Monoid_Add_Array<T, K + 1>;\n  using Monoid_A = Monoid_Assign<T,\
    \ -1>;\n  using X = typename Monoid_X::value_type;\n  using A = typename Monoid_A::value_type;\n\
    \  static constexpr X act(const X &x, const A &a, const ll &size) {\n    if (a\
    \ == Monoid_A::id()) return x;\n    X y;\n    T pow = 1;\n    FOR(i, K + 1) {\
    \ y[i] = x[0] * pow, pow *= a; }\n    return y;\n  }\n};\n"
  dependsOn:
  - alg/monoid/assign.hpp
  - alg/monoid/add_array.hpp
  isVerificationFile: false
  path: alg/acted_monoid/powersums_assign.hpp
  requiredBy: []
  timestamp: '2026-08-30 21:09:36+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/3_yukicoder/1548.test.cpp
documentation_of: alg/acted_monoid/powersums_assign.hpp
layout: document
redirect_from:
- /library/alg/acted_monoid/powersums_assign.hpp
- /library/alg/acted_monoid/powersums_assign.hpp.html
title: alg/acted_monoid/powersums_assign.hpp
---
