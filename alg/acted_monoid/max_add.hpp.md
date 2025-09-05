---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: alg/monoid/add.hpp
    title: alg/monoid/add.hpp
  - icon: ':question:'
    path: alg/monoid/max.hpp
    title: alg/monoid/max.hpp
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/1_mytest/range_add_range_max.test.cpp
    title: test/1_mytest/range_add_range_max.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/3_yukicoder/686.test.cpp
    title: test/3_yukicoder/686.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 2 \"alg/monoid/add.hpp\"\n\r\ntemplate <typename E>\r\nstruct\
    \ Monoid_Add {\r\n  using X = E;\r\n  using value_type = X;\r\n  static constexpr\
    \ X op(const X &x, const X &y) noexcept { return x + y; }\r\n  static constexpr\
    \ X inverse(const X &x) noexcept { return -x; }\r\n  static constexpr X power(const\
    \ X &x, ll n) noexcept { return X(n) * x; }\r\n  static constexpr X unit() { return\
    \ X(0); }\r\n  static constexpr bool commute = true;\r\n};\r\n#line 2 \"alg/monoid/max.hpp\"\
    \n\r\ntemplate <typename E>\r\nstruct Monoid_Max {\r\n  using X = E;\r\n  using\
    \ value_type = X;\r\n  static constexpr X op(const X &x, const X &y) noexcept\
    \ { return max(x, y); }\r\n  static constexpr X unit() { return -infty<E>; }\r\
    \n  static constexpr bool commute = true;\r\n};\r\n#line 3 \"alg/acted_monoid/max_add.hpp\"\
    \n\r\ntemplate <typename E>\r\nstruct ActedMonoid_Max_Add {\r\n  using Monoid_X\
    \ = Monoid_Max<E>;\r\n  using Monoid_A = Monoid_Add<E>;\r\n  using X = typename\
    \ Monoid_X::value_type;\r\n  using A = typename Monoid_A::value_type;\r\n  static\
    \ constexpr X act(const X &x, const A &a, const ll &size) {\r\n    if (x == -infty<E>)\
    \ return x;\r\n    return x + a;\r\n  }\r\n};\r\n"
  code: "#include \"alg/monoid/add.hpp\"\r\n#include \"alg/monoid/max.hpp\"\r\n\r\n\
    template <typename E>\r\nstruct ActedMonoid_Max_Add {\r\n  using Monoid_X = Monoid_Max<E>;\r\
    \n  using Monoid_A = Monoid_Add<E>;\r\n  using X = typename Monoid_X::value_type;\r\
    \n  using A = typename Monoid_A::value_type;\r\n  static constexpr X act(const\
    \ X &x, const A &a, const ll &size) {\r\n    if (x == -infty<E>) return x;\r\n\
    \    return x + a;\r\n  }\r\n};\r\n"
  dependsOn:
  - alg/monoid/add.hpp
  - alg/monoid/max.hpp
  isVerificationFile: false
  path: alg/acted_monoid/max_add.hpp
  requiredBy: []
  timestamp: '2024-01-23 05:58:02+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/3_yukicoder/686.test.cpp
  - test/1_mytest/range_add_range_max.test.cpp
documentation_of: alg/acted_monoid/max_add.hpp
layout: document
redirect_from:
- /library/alg/acted_monoid/max_add.hpp
- /library/alg/acted_monoid/max_add.hpp.html
title: alg/acted_monoid/max_add.hpp
---
