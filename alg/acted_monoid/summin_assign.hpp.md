---
data:
  _extendedDependsOn:
  - icon: ':x:'
    path: alg/monoid/assign.hpp
    title: alg/monoid/assign.hpp
  - icon: ':warning:'
    path: alg/monoid/summin.hpp
    title: alg/monoid/summin.hpp
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':warning:'
  attributes:
    links: []
  bundledCode: "#line 2 \"alg/monoid/summin.hpp\"\n\r\ntemplate <typename E>\r\nstruct\
    \ Monoid_SumMin {\r\n  using value_type = tuple<E, E, E>;\r\n  using X = value_type;\r\
    \n  static X op(X x, X y) {\r\n    auto [xc, xs, xm] = x;\r\n    auto [yc, ys,\
    \ ym] = y;\r\n    return {xc + yc, xs + ys, max(xm, ym)};\r\n  }\r\n  static X\
    \ from_element(E x) { return {1, x, x}; }\r\n  static constexpr X unit() { return\
    \ {0, 0, numeric_limits<ll>::max()}; }\r\n  static constexpr bool commute = true;\r\
    \n};\r\n#line 2 \"alg/monoid/assign.hpp\"\n\r\ntemplate <typename X, X none_val>\r\
    \nstruct Monoid_Assign {\r\n  using value_type = X;\r\n  static X op(X x, X y)\
    \ { return (y == none_val ? x : y); }\r\n  static constexpr X unit() { return\
    \ none_val; }\r\n  static constexpr bool commute = false;\r\n};\r\n#line 3 \"\
    alg/acted_monoid/summin_assign.hpp\"\n\r\ntemplate <typename E, ll none_val>\r\
    \nstruct ActedMonoid_CntSumMin_Assign {\r\n  using Monoid_X = Monoid_SumMin<E>;\r\
    \n  using Monoid_A = Monoid_Assign<ll, none_val>;\r\n  using X = typename Monoid_X::value_type;\r\
    \n  using A = typename Monoid_A::value_type;\r\n  static constexpr X act(const\
    \ X& x, const A& a, const ll& size) {\r\n    if (a == Monoid_A::unit()) return\
    \ x;\r\n    return {E(size) * a, a};\r\n  }\r\n};\r\n"
  code: "#include \"alg/monoid/summin.hpp\"\r\n#include \"alg/monoid/assign.hpp\"\r\
    \n\r\ntemplate <typename E, ll none_val>\r\nstruct ActedMonoid_CntSumMin_Assign\
    \ {\r\n  using Monoid_X = Monoid_SumMin<E>;\r\n  using Monoid_A = Monoid_Assign<ll,\
    \ none_val>;\r\n  using X = typename Monoid_X::value_type;\r\n  using A = typename\
    \ Monoid_A::value_type;\r\n  static constexpr X act(const X& x, const A& a, const\
    \ ll& size) {\r\n    if (a == Monoid_A::unit()) return x;\r\n    return {E(size)\
    \ * a, a};\r\n  }\r\n};\r\n"
  dependsOn:
  - alg/monoid/summin.hpp
  - alg/monoid/assign.hpp
  isVerificationFile: false
  path: alg/acted_monoid/summin_assign.hpp
  requiredBy: []
  timestamp: '2022-12-03 08:35:02+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: alg/acted_monoid/summin_assign.hpp
layout: document
redirect_from:
- /library/alg/acted_monoid/summin_assign.hpp
- /library/alg/acted_monoid/summin_assign.hpp.html
title: alg/acted_monoid/summin_assign.hpp
---
