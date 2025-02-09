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
  - icon: ':x:'
    path: seq/common_interval_decomposition.hpp
    title: seq/common_interval_decomposition.hpp
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/1_mytest/range_add_range_min.test.cpp
    title: test/1_mytest/range_add_range_min.test.cpp
  - icon: ':x:'
    path: test/2_library_checker/graph/common_interval_decomposition.test.cpp
    title: test/2_library_checker/graph/common_interval_decomposition.test.cpp
  - icon: ':x:'
    path: test/3_yukicoder/1234.test.cpp
    title: test/3_yukicoder/1234.test.cpp
  - icon: ':x:'
    path: test/3_yukicoder/1270.test.cpp
    title: test/3_yukicoder/1270.test.cpp
  - icon: ':x:'
    path: test/3_yukicoder/1720.test.cpp
    title: test/3_yukicoder/1720.test.cpp
  - icon: ':x:'
    path: test/4_aoj/DSL_2_H.test.cpp
    title: test/4_aoj/DSL_2_H.test.cpp
  _isVerificationFailed: true
  _pathExtension: hpp
  _verificationStatusIcon: ':question:'
  attributes:
    links: []
  bundledCode: "#line 2 \"alg/monoid/add.hpp\"\n\r\ntemplate <typename E>\r\nstruct\
    \ Monoid_Add {\r\n  using X = E;\r\n  using value_type = X;\r\n  static constexpr\
    \ X op(const X &x, const X &y) noexcept { return x + y; }\r\n  static constexpr\
    \ X inverse(const X &x) noexcept { return -x; }\r\n  static constexpr X power(const\
    \ X &x, ll n) noexcept { return X(n) * x; }\r\n  static constexpr X unit() { return\
    \ X(0); }\r\n  static constexpr bool commute = true;\r\n};\r\n#line 2 \"alg/monoid/min.hpp\"\
    \n\r\ntemplate <typename E>\r\nstruct Monoid_Min {\r\n  using X = E;\r\n  using\
    \ value_type = X;\r\n  static constexpr X op(const X &x, const X &y) noexcept\
    \ { return min(x, y); }\r\n  static constexpr X unit() { return infty<E>; }\r\n\
    \  static constexpr bool commute = true;\r\n};\r\n#line 3 \"alg/acted_monoid/min_add.hpp\"\
    \n\r\ntemplate <typename E>\r\nstruct ActedMonoid_Min_Add {\r\n  using Monoid_X\
    \ = Monoid_Min<E>;\r\n  using Monoid_A = Monoid_Add<E>;\r\n  using X = typename\
    \ Monoid_X::value_type;\r\n  using A = typename Monoid_A::value_type;\r\n  static\
    \ constexpr X act(const X &x, const A &a, const ll &size) {\r\n    if (x == infty<E>)\
    \ return x;\r\n    return x + a;\r\n  }\r\n};\r\n"
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
  timestamp: '2024-01-23 05:58:02+09:00'
  verificationStatus: LIBRARY_SOME_WA
  verifiedWith:
  - test/3_yukicoder/1234.test.cpp
  - test/3_yukicoder/1270.test.cpp
  - test/3_yukicoder/1720.test.cpp
  - test/2_library_checker/graph/common_interval_decomposition.test.cpp
  - test/1_mytest/range_add_range_min.test.cpp
  - test/4_aoj/DSL_2_H.test.cpp
documentation_of: alg/acted_monoid/min_add.hpp
layout: document
redirect_from:
- /library/alg/acted_monoid/min_add.hpp
- /library/alg/acted_monoid/min_add.hpp.html
title: alg/acted_monoid/min_add.hpp
---
