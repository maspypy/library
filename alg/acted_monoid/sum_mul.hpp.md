---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: alg/monoid/add.hpp
    title: alg/monoid/add.hpp
  - icon: ':heavy_check_mark:'
    path: alg/monoid/mul.hpp
    title: alg/monoid/mul.hpp
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/3_yukicoder/899.test.cpp
    title: test/3_yukicoder/899.test.cpp
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
    \  static constexpr bool commute = true;\n};\n#line 1 \"alg/monoid/mul.hpp\"\n\
    \ntemplate <class T>\nstruct Monoid_Mul {\n  using value_type = T;\n  using X\
    \ = T;\n  static constexpr X op(const X &x, const X &y) noexcept { return x *\
    \ y; }\n  static constexpr X inverse(const X &x) noexcept { return X(1) / x; }\n\
    \  static constexpr X unit() { return X(1); }\n  static constexpr bool commute\
    \ = true;\n};\n#line 3 \"alg/acted_monoid/sum_mul.hpp\"\n\r\ntemplate <typename\
    \ E>\r\nstruct ActedMonoid_Sum_Mul {\r\n  using Monoid_X = Monoid_Add<E>;\r\n\
    \  using Monoid_A = Monoid_Mul<E>;\r\n  using X = typename Monoid_X::value_type;\r\
    \n  using A = typename Monoid_A::value_type;\r\n  static constexpr X act(const\
    \ X &x, const A &a, const ll &size = 1) {\r\n    return x * a;\r\n  }\r\n};\r\n"
  code: "#include \"alg/monoid/add.hpp\"\r\n#include \"alg/monoid/mul.hpp\"\r\n\r\n\
    template <typename E>\r\nstruct ActedMonoid_Sum_Mul {\r\n  using Monoid_X = Monoid_Add<E>;\r\
    \n  using Monoid_A = Monoid_Mul<E>;\r\n  using X = typename Monoid_X::value_type;\r\
    \n  using A = typename Monoid_A::value_type;\r\n  static constexpr X act(const\
    \ X &x, const A &a, const ll &size = 1) {\r\n    return x * a;\r\n  }\r\n};\r\n"
  dependsOn:
  - alg/monoid/add.hpp
  - alg/monoid/mul.hpp
  isVerificationFile: false
  path: alg/acted_monoid/sum_mul.hpp
  requiredBy: []
  timestamp: '2026-08-16 04:03:00+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/3_yukicoder/899.test.cpp
documentation_of: alg/acted_monoid/sum_mul.hpp
layout: document
redirect_from:
- /library/alg/acted_monoid/sum_mul.hpp
- /library/alg/acted_monoid/sum_mul.hpp.html
title: alg/acted_monoid/sum_mul.hpp
---
