---
data:
  _extendedDependsOn:
  - icon: ':question:'
    path: alg/monoid/add.hpp
    title: alg/monoid/add.hpp
  - icon: ':question:'
    path: alg/monoid/min.hpp
    title: alg/monoid/min.hpp
  _extendedRequiredBy:
  - icon: ':heavy_check_mark:'
    path: seq/common_interval_decomposition.hpp
    title: seq/common_interval_decomposition.hpp
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/1_mytest/range_add_range_min.test.cpp
    title: test/1_mytest/range_add_range_min.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/2_library_checker/graph/common_interval_decomposition.test.cpp
    title: test/2_library_checker/graph/common_interval_decomposition.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/3_yukicoder/1234.test.cpp
    title: test/3_yukicoder/1234.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/3_yukicoder/1270.test.cpp
    title: test/3_yukicoder/1270.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/3_yukicoder/1720.test.cpp
    title: test/3_yukicoder/1720.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/4_aoj/DSL_2_H.test.cpp
    title: test/4_aoj/DSL_2_H.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 1 \"alg/monoid/add.hpp\"\n\ntemplate <typename E>\nstruct Monoid_Add\
    \ {\n  using X = E;\n  using value_type = X;\n  static constexpr X op(const X\
    \ &x, const X &y) noexcept { return x + y; }\n  static constexpr X inverse(const\
    \ X &x) noexcept { return -x; }\n  static constexpr X power(const X &x, ll n)\
    \ noexcept { return X(n) * x; }\n  static constexpr X unit() { return X(0); }\n\
    \  static constexpr bool commute = true;\n};\n#line 1 \"alg/monoid/min.hpp\"\n\
    \ntemplate <typename E>\nstruct Monoid_Min {\n  using X = E;\n  using value_type\
    \ = X;\n  static constexpr X op(const X &x, const X &y) noexcept { return min(x,\
    \ y); }\n  static constexpr X unit() { return infty<E>; }\n  static constexpr\
    \ bool commute = true;\n};\n#line 3 \"alg/acted_monoid/min_add.hpp\"\n\r\ntemplate\
    \ <typename E>\r\nstruct ActedMonoid_Min_Add {\r\n  using Monoid_X = Monoid_Min<E>;\r\
    \n  using Monoid_A = Monoid_Add<E>;\r\n  using X = typename Monoid_X::value_type;\r\
    \n  using A = typename Monoid_A::value_type;\r\n  static constexpr X act(const\
    \ X &x, const A &a, const ll &size) {\r\n    if (x == infty<E>) return x;\r\n\
    \    return x + a;\r\n  }\r\n};\r\n"
  code: "#include \"alg/monoid/add.hpp\"\r\n#include \"alg/monoid/min.hpp\"\r\n\r\n\
    template <typename E>\r\nstruct ActedMonoid_Min_Add {\r\n  using Monoid_X = Monoid_Min<E>;\r\
    \n  using Monoid_A = Monoid_Add<E>;\r\n  using X = typename Monoid_X::value_type;\r\
    \n  using A = typename Monoid_A::value_type;\r\n  static constexpr X act(const\
    \ X &x, const A &a, const ll &size) {\r\n    if (x == infty<E>) return x;\r\n\
    \    return x + a;\r\n  }\r\n};\r\n"
  dependsOn:
  - alg/monoid/add.hpp
  - alg/monoid/min.hpp
  isVerificationFile: false
  path: alg/acted_monoid/min_add.hpp
  requiredBy:
  - seq/common_interval_decomposition.hpp
  timestamp: '2026-08-16 04:03:00+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/1_mytest/range_add_range_min.test.cpp
  - test/2_library_checker/graph/common_interval_decomposition.test.cpp
  - test/4_aoj/DSL_2_H.test.cpp
  - test/3_yukicoder/1270.test.cpp
  - test/3_yukicoder/1234.test.cpp
  - test/3_yukicoder/1720.test.cpp
documentation_of: alg/acted_monoid/min_add.hpp
layout: document
redirect_from:
- /library/alg/acted_monoid/min_add.hpp
- /library/alg/acted_monoid/min_add.hpp.html
title: alg/acted_monoid/min_add.hpp
---
