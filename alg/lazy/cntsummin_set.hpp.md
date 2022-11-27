---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: alg/monoid/cntsummin.hpp
    title: alg/monoid/cntsummin.hpp
  - icon: ':heavy_check_mark:'
    path: alg/monoid/set.hpp
    title: alg/monoid/set.hpp
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/mytest/cntsummin_set.test.cpp
    title: test/mytest/cntsummin_set.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 2 \"alg/monoid/cntsummin.hpp\"\n\r\ntemplate <typename E>\r\n\
    struct Monoid_CntSumMin {\r\n  using value_type = tuple<E, E, E>;\r\n  using X\
    \ = value_type;\r\n  static X op(X x, X y) {\r\n    auto [xc, xs, xm] = x;\r\n\
    \    auto [yc, ys, ym] = y;\r\n    return {xc + yc, xs + ys, max(xm, ym)};\r\n\
    \  }\r\n  static X from_element(E x) { return {1, x, x}; }\r\n  static constexpr\
    \ X unit() { return {0, 0, numeric_limits<ll>::max()}; }\r\n  static constexpr\
    \ bool commute = true;\r\n};\r\n#line 1 \"alg/monoid/set.hpp\"\ntemplate <typename\
    \ E, E none_val>\r\nstruct Monoid_Set {\r\n  using value_type = E;\r\n  using\
    \ X = value_type;\r\n  static X op(X x, X y) { return (y == none_val ? x : y);\
    \ }\r\n  static constexpr X unit() { return none_val; }\r\n  static constexpr\
    \ bool commute = false;\r\n};\n#line 3 \"alg/lazy/cntsummin_set.hpp\"\n\r\ntemplate\
    \ <typename E, ll none_val>\r\nstruct Lazy_CntSumMin_Set {\r\n  static constexpr\
    \ ll INF = 1LL << 60;\r\n  using MX = Monoid_CntSumMin<E>;\r\n  using MA = Monoid_Set<ll,\
    \ none_val>;\r\n  using X_structure = MX;\r\n  using A_structure = MA;\r\n  using\
    \ X = typename MX::value_type;\r\n  using A = typename MA::value_type;\r\n  static\
    \ constexpr X act(const X& x, const A& a) {\r\n    if (a == MA::unit()) return\
    \ x;\r\n    auto [xc, xs, xm] = x;\r\n    return {xc, xc * a, a};\r\n  }\r\n};\r\
    \n"
  code: "#include \"alg/monoid/cntsummin.hpp\"\r\n#include \"alg/monoid/set.hpp\"\r\
    \n\r\ntemplate <typename E, ll none_val>\r\nstruct Lazy_CntSumMin_Set {\r\n  static\
    \ constexpr ll INF = 1LL << 60;\r\n  using MX = Monoid_CntSumMin<E>;\r\n  using\
    \ MA = Monoid_Set<ll, none_val>;\r\n  using X_structure = MX;\r\n  using A_structure\
    \ = MA;\r\n  using X = typename MX::value_type;\r\n  using A = typename MA::value_type;\r\
    \n  static constexpr X act(const X& x, const A& a) {\r\n    if (a == MA::unit())\
    \ return x;\r\n    auto [xc, xs, xm] = x;\r\n    return {xc, xc * a, a};\r\n \
    \ }\r\n};\r\n"
  dependsOn:
  - alg/monoid/cntsummin.hpp
  - alg/monoid/set.hpp
  isVerificationFile: false
  path: alg/lazy/cntsummin_set.hpp
  requiredBy: []
  timestamp: '2022-11-27 22:15:30+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/mytest/cntsummin_set.test.cpp
documentation_of: alg/lazy/cntsummin_set.hpp
layout: document
redirect_from:
- /library/alg/lazy/cntsummin_set.hpp
- /library/alg/lazy/cntsummin_set.hpp.html
title: alg/lazy/cntsummin_set.hpp
---
