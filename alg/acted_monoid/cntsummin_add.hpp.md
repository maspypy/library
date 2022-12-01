---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: alg/monoid/add.hpp
    title: alg/monoid/add.hpp
  - icon: ':warning:'
    path: alg/monoid/cntsummin.hpp
    title: alg/monoid/cntsummin.hpp
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':warning:'
  attributes:
    links: []
  bundledCode: "#line 2 \"alg/monoid/cntsummin.hpp\"\n\r\ntemplate <typename E>\r\n\
    struct Monoid_CntSumMin {\r\n  using value_type = tuple<E, E, E>;\r\n  using X\
    \ = value_type;\r\n  static X op(X x, X y) {\r\n    auto [xc, xs, xm] = x;\r\n\
    \    auto [yc, ys, ym] = y;\r\n    return {xc + yc, xs + ys, max(xm, ym)};\r\n\
    \  }\r\n  static X from_element(E x) { return {1, x, x}; }\r\n  static constexpr\
    \ X unit() { return {0, 0, numeric_limits<ll>::max()}; }\r\n  static constexpr\
    \ bool commute = true;\r\n};\r\n#line 2 \"alg/monoid/add.hpp\"\n\r\ntemplate <typename\
    \ X>\r\nstruct Monoid_Add {\r\n  using value_type = X;\r\n  static constexpr X\
    \ op(const X &x, const X &y) noexcept { return x + y; }\r\n  static constexpr\
    \ X inverse(const X &x) noexcept { return -x; }\r\n  static constexpr X power(const\
    \ X &x, ll n) noexcept { return X(n) * x; }\r\n  static constexpr X unit() { return\
    \ X(0); }\r\n  static constexpr bool commute = true;\r\n};\r\n#line 3 \"alg/acted_monoid/cntsummin_add.hpp\"\
    \n\r\ntemplate <typename E>\r\nstruct ActedMonoid_CntSumMin_Add {\r\n  using Monoid_X\
    \ = Monoid_CntSumMin<E>;\r\n  using Monoid_A = Monoid_Add<E>;\r\n  using X = typename\
    \ Monoid_X::value_type;\r\n  using A = typename Monoid_A::value_type;\r\n  static\
    \ constexpr X act(const X& x, const A& a) {\r\n    auto [xc, xs, xm] = x;\r\n\
    \    xm = (xm == numeric_limits<E>::max() ? xm : xm + a);\r\n    return {xc, xs\
    \ + xc * a, xm};\r\n  }\r\n};\r\n"
  code: "#include \"alg/monoid/cntsummin.hpp\"\r\n#include \"alg/monoid/add.hpp\"\r\
    \n\r\ntemplate <typename E>\r\nstruct ActedMonoid_CntSumMin_Add {\r\n  using Monoid_X\
    \ = Monoid_CntSumMin<E>;\r\n  using Monoid_A = Monoid_Add<E>;\r\n  using X = typename\
    \ Monoid_X::value_type;\r\n  using A = typename Monoid_A::value_type;\r\n  static\
    \ constexpr X act(const X& x, const A& a) {\r\n    auto [xc, xs, xm] = x;\r\n\
    \    xm = (xm == numeric_limits<E>::max() ? xm : xm + a);\r\n    return {xc, xs\
    \ + xc * a, xm};\r\n  }\r\n};\r\n"
  dependsOn:
  - alg/monoid/cntsummin.hpp
  - alg/monoid/add.hpp
  isVerificationFile: false
  path: alg/acted_monoid/cntsummin_add.hpp
  requiredBy: []
  timestamp: '2022-11-28 17:32:24+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: alg/acted_monoid/cntsummin_add.hpp
layout: document
redirect_from:
- /library/alg/acted_monoid/cntsummin_add.hpp
- /library/alg/acted_monoid/cntsummin_add.hpp.html
title: alg/acted_monoid/cntsummin_add.hpp
---
