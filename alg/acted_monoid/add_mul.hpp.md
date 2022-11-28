---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: alg/monoid/add.hpp
    title: alg/monoid/add.hpp
  - icon: ':question:'
    path: alg/monoid/mul.hpp
    title: alg/monoid/mul.hpp
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/yukicoder/899.test.cpp
    title: test/yukicoder/899.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 2 \"alg/monoid/add.hpp\"\n\r\ntemplate <typename X>\r\nstruct\
    \ Monoid_Add {\r\n  using value_type = X;\r\n  static constexpr X op(const X &x,\
    \ const X &y) noexcept { return x + y; }\r\n  static constexpr X inverse(const\
    \ X &x) noexcept { return -x; }\r\n  static constexpr X power(const X &x, ll n)\
    \ noexcept { return X(n) * x; }\r\n  static constexpr X unit() { return X(0);\
    \ }\r\n  static constexpr bool commute = true;\r\n};\r\n#line 2 \"alg/monoid/mul.hpp\"\
    \n\r\ntemplate <class T>\r\nstruct Monoid_Mul {\r\n  using value_type = T;\r\n\
    \  using X = T;\r\n  static constexpr X op(const X &x, const X &y) noexcept {\
    \ return x * y; }\r\n  static constexpr X inverse(const X &x) noexcept { return\
    \ X(1) / x; }\r\n  static constexpr X unit() { return X(1); }\r\n  static constexpr\
    \ bool commute = true;\r\n};\r\n#line 3 \"alg/acted_monoid/add_mul.hpp\"\n\r\n\
    template <typename E>\r\nstruct ActedMonoid_Add_Mul {\r\n  using Monoid_X = Monoid_Add<E>;\r\
    \n  using Monoid_A = Monoid_Mul<E>;\r\n  using X = typename Monoid_X::value_type;\r\
    \n  using A = typename Monoid_A::value_type;\r\n  static constexpr X act(const\
    \ X &x, const A &a) { return x * a; }\r\n};\r\n"
  code: "#include \"alg/monoid/add.hpp\"\r\n#include \"alg/monoid/mul.hpp\"\r\n\r\n\
    template <typename E>\r\nstruct ActedMonoid_Add_Mul {\r\n  using Monoid_X = Monoid_Add<E>;\r\
    \n  using Monoid_A = Monoid_Mul<E>;\r\n  using X = typename Monoid_X::value_type;\r\
    \n  using A = typename Monoid_A::value_type;\r\n  static constexpr X act(const\
    \ X &x, const A &a) { return x * a; }\r\n};\r\n"
  dependsOn:
  - alg/monoid/add.hpp
  - alg/monoid/mul.hpp
  isVerificationFile: false
  path: alg/acted_monoid/add_mul.hpp
  requiredBy: []
  timestamp: '2022-11-28 18:35:13+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/yukicoder/899.test.cpp
documentation_of: alg/acted_monoid/add_mul.hpp
layout: document
redirect_from:
- /library/alg/acted_monoid/add_mul.hpp
- /library/alg/acted_monoid/add_mul.hpp.html
title: alg/acted_monoid/add_mul.hpp
---
