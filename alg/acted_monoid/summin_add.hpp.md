---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: alg/monoid/add.hpp
    title: alg/monoid/add.hpp
  - icon: ':heavy_check_mark:'
    path: alg/monoid/summin.hpp
    title: alg/monoid/summin.hpp
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/mytest/summin_add.test.cpp
    title: test/mytest/summin_add.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 2 \"alg/monoid/summin.hpp\"\n\r\ntemplate <typename E>\r\nstruct\
    \ Monoid_SumMin {\r\n  using value_type = pair<E, E>;\r\n  using X = value_type;\r\
    \n  static X op(X x, X y) { return {x.fi + y.fi, min(x.se, y.se)}; }\r\n  static\
    \ X from_element(E x) { return {x, x}; }\r\n  static constexpr X unit() { return\
    \ {E(0), numeric_limits<ll>::max()}; }\r\n  static constexpr bool commute = true;\r\
    \n};\r\n#line 2 \"alg/monoid/add.hpp\"\n\r\ntemplate <typename X>\r\nstruct Monoid_Add\
    \ {\r\n  using value_type = X;\r\n  static constexpr X op(const X &x, const X\
    \ &y) noexcept { return x + y; }\r\n  static constexpr X inverse(const X &x) noexcept\
    \ { return -x; }\r\n  static constexpr X power(const X &x, ll n) noexcept { return\
    \ X(n) * x; }\r\n  static constexpr X unit() { return X(0); }\r\n  static constexpr\
    \ bool commute = true;\r\n};\r\n#line 3 \"alg/acted_monoid/summin_add.hpp\"\n\r\
    \ntemplate <typename E>\r\nstruct ActedMonoid_SumMin_Add {\r\n  using Monoid_X\
    \ = Monoid_SumMin<E>;\r\n  using Monoid_A = Monoid_Add<E>;\r\n  using X = typename\
    \ Monoid_X::value_type;\r\n  using A = typename Monoid_A::value_type;\r\n  static\
    \ constexpr X act(const X& x, const A& a, const ll& size) {\r\n    auto [xs, xm]\
    \ = x;\r\n    xm = (xm == numeric_limits<E>::max() ? xm : xm + a);\r\n    return\
    \ {xs + E(size) * a, xm};\r\n  }\r\n};\r\n"
  code: "#include \"alg/monoid/summin.hpp\"\r\n#include \"alg/monoid/add.hpp\"\r\n\
    \r\ntemplate <typename E>\r\nstruct ActedMonoid_SumMin_Add {\r\n  using Monoid_X\
    \ = Monoid_SumMin<E>;\r\n  using Monoid_A = Monoid_Add<E>;\r\n  using X = typename\
    \ Monoid_X::value_type;\r\n  using A = typename Monoid_A::value_type;\r\n  static\
    \ constexpr X act(const X& x, const A& a, const ll& size) {\r\n    auto [xs, xm]\
    \ = x;\r\n    xm = (xm == numeric_limits<E>::max() ? xm : xm + a);\r\n    return\
    \ {xs + E(size) * a, xm};\r\n  }\r\n};\r\n"
  dependsOn:
  - alg/monoid/summin.hpp
  - alg/monoid/add.hpp
  isVerificationFile: false
  path: alg/acted_monoid/summin_add.hpp
  requiredBy: []
  timestamp: '2022-12-04 15:54:38+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/mytest/summin_add.test.cpp
documentation_of: alg/acted_monoid/summin_add.hpp
layout: document
redirect_from:
- /library/alg/acted_monoid/summin_add.hpp
- /library/alg/acted_monoid/summin_add.hpp.html
title: alg/acted_monoid/summin_add.hpp
---
