---
data:
  _extendedDependsOn:
  - icon: ':question:'
    path: alg/monoid/add.hpp
    title: alg/monoid/add.hpp
  - icon: ':heavy_check_mark:'
    path: alg/monoid/assign.hpp
    title: alg/monoid/assign.hpp
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/1_mytest/range_assign.test.cpp
    title: test/1_mytest/range_assign.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/3_yukicoder/2292.test.cpp
    title: test/3_yukicoder/2292.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/4_aoj/DSL_2_I.test.cpp
    title: test/4_aoj/DSL_2_I.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links:
    - https://github.com/maspypy/library/blob/main/alg/acted_monoid/sum_assign.hpp
  bundledCode: "#line 1 \"alg/acted_monoid/sum_assign.hpp\"\n// Source: https://github.com/maspypy/library/blob/main/alg/acted_monoid/sum_assign.hpp\n\
    #line 1 \"alg/monoid/add.hpp\"\n// Source: https://github.com/maspypy/library/blob/main/alg/monoid/add.hpp\n\
    \ntemplate <typename E>\nstruct Monoid_Add {\n  using X = E;\n  using value_type\
    \ = X;\n  static constexpr X op(const X &x, const X &y) noexcept { return x +\
    \ y; }\n  static constexpr X inverse(const X &x) noexcept { return -x; }\n  static\
    \ constexpr X power(const X &x, ll n) noexcept { return X(n) * x; }\n  static\
    \ constexpr X id() { return X(0); }\n  static constexpr bool commute = true;\n\
    };\n#line 1 \"alg/monoid/assign.hpp\"\n// Source: https://github.com/maspypy/library/blob/main/alg/monoid/assign.hpp\n\
    \ntemplate <typename X, int none_val>\nstruct Monoid_Assign {\n  using value_type\
    \ = X;\n  static X op(X x, X y) { return (y == X(none_val) ? x : y); }\n  static\
    \ constexpr X id() { return X(none_val); }\n  static constexpr bool commute =\
    \ false;\n};\n#line 4 \"alg/acted_monoid/sum_assign.hpp\"\n\ntemplate <typename\
    \ E, E none_val>\nstruct ActedMonoid_Sum_Assign {\n  using Monoid_X = Monoid_Add<E>;\n\
    \  using Monoid_A = Monoid_Assign<E, none_val>;\n  using X = typename Monoid_X::value_type;\n\
    \  using A = typename Monoid_A::value_type;\n  static constexpr X act(const X\
    \ &x, const A &a, const ll &size) {\n    if (a == Monoid_A::id()) return x;\n\
    \    return a * E(size);\n  }\n};\n"
  code: "// Source: https://github.com/maspypy/library/blob/main/alg/acted_monoid/sum_assign.hpp\n\
    #include \"alg/monoid/add.hpp\"\n#include \"alg/monoid/assign.hpp\"\n\ntemplate\
    \ <typename E, E none_val>\nstruct ActedMonoid_Sum_Assign {\n  using Monoid_X\
    \ = Monoid_Add<E>;\n  using Monoid_A = Monoid_Assign<E, none_val>;\n  using X\
    \ = typename Monoid_X::value_type;\n  using A = typename Monoid_A::value_type;\n\
    \  static constexpr X act(const X &x, const A &a, const ll &size) {\n    if (a\
    \ == Monoid_A::id()) return x;\n    return a * E(size);\n  }\n};\n"
  dependsOn:
  - alg/monoid/add.hpp
  - alg/monoid/assign.hpp
  isVerificationFile: false
  path: alg/acted_monoid/sum_assign.hpp
  requiredBy: []
  timestamp: '2026-10-15 19:54:56+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/3_yukicoder/2292.test.cpp
  - test/4_aoj/DSL_2_I.test.cpp
  - test/1_mytest/range_assign.test.cpp
documentation_of: alg/acted_monoid/sum_assign.hpp
layout: document
redirect_from:
- /library/alg/acted_monoid/sum_assign.hpp
- /library/alg/acted_monoid/sum_assign.hpp.html
title: alg/acted_monoid/sum_assign.hpp
---
