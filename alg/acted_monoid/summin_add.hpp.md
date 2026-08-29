---
data:
  _extendedDependsOn:
  - icon: ':x:'
    path: alg/monoid/add.hpp
    title: alg/monoid/add.hpp
  - icon: ':x:'
    path: alg/monoid/summin.hpp
    title: alg/monoid/summin.hpp
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':x:'
    path: test/1_mytest/summin_add.test.cpp
    title: test/1_mytest/summin_add.test.cpp
  _isVerificationFailed: true
  _pathExtension: hpp
  _verificationStatusIcon: ':x:'
  attributes:
    links: []
  bundledCode: "#line 1 \"alg/monoid/summin.hpp\"\n\ntemplate <typename E>\nstruct\
    \ Monoid_SumMin {\n  using value_type = pair<E, E>;\n  using X = value_type;\n\
    \  static X op(X x, X y) { return {x.fi + y.fi, min(x.se, y.se)}; }\n  static\
    \ X from_element(E x) { return {x, x}; }\n  static constexpr X unit() { return\
    \ {E(0), infty<E>}; }\n  static constexpr bool commute = true;\n};\n#line 1 \"\
    alg/monoid/add.hpp\"\n\ntemplate <typename E>\nstruct Monoid_Add {\n  using X\
    \ = E;\n  using value_type = X;\n  static constexpr X op(const X &x, const X &y)\
    \ noexcept { return x + y; }\n  static constexpr X inverse(const X &x) noexcept\
    \ { return -x; }\n  static constexpr X power(const X &x, ll n) noexcept { return\
    \ X(n) * x; }\n  static constexpr X unit() { return X(0); }\n  static constexpr\
    \ bool commute = true;\n};\n#line 3 \"alg/acted_monoid/summin_add.hpp\"\n\r\n\
    template <typename E>\r\nstruct ActedMonoid_SumMin_Add {\r\n  using Monoid_X =\
    \ Monoid_SumMin<E>;\r\n  using Monoid_A = Monoid_Add<E>;\r\n  using X = typename\
    \ Monoid_X::value_type;\r\n  using A = typename Monoid_A::value_type;\r\n  static\
    \ constexpr X act(const X& x, const A& a, const ll& size) {\r\n    auto [xs, xm]\
    \ = x;\r\n    xm = (xm == infty<E> ? xm : xm + a);\r\n    return {xs + E(size)\
    \ * a, xm};\r\n  }\r\n};\r\n"
  code: "#include \"alg/monoid/summin.hpp\"\r\n#include \"alg/monoid/add.hpp\"\r\n\
    \r\ntemplate <typename E>\r\nstruct ActedMonoid_SumMin_Add {\r\n  using Monoid_X\
    \ = Monoid_SumMin<E>;\r\n  using Monoid_A = Monoid_Add<E>;\r\n  using X = typename\
    \ Monoid_X::value_type;\r\n  using A = typename Monoid_A::value_type;\r\n  static\
    \ constexpr X act(const X& x, const A& a, const ll& size) {\r\n    auto [xs, xm]\
    \ = x;\r\n    xm = (xm == infty<E> ? xm : xm + a);\r\n    return {xs + E(size)\
    \ * a, xm};\r\n  }\r\n};\r\n"
  dependsOn:
  - alg/monoid/summin.hpp
  - alg/monoid/add.hpp
  isVerificationFile: false
  path: alg/acted_monoid/summin_add.hpp
  requiredBy: []
  timestamp: '2026-08-16 04:03:00+09:00'
  verificationStatus: LIBRARY_ALL_WA
  verifiedWith:
  - test/1_mytest/summin_add.test.cpp
documentation_of: alg/acted_monoid/summin_add.hpp
layout: document
redirect_from:
- /library/alg/acted_monoid/summin_add.hpp
- /library/alg/acted_monoid/summin_add.hpp.html
title: alg/acted_monoid/summin_add.hpp
---
