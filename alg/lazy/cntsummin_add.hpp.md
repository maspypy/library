---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: alg/group/add.hpp
    title: alg/group/add.hpp
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
  bundledCode: "#line 2 \"alg/monoid/cntsummin.hpp\"\n\r\nstruct Monoid_CntSumMin\
    \ {\r\n  using value_type = tuple<ll, ll, ll>;\r\n  using X = value_type;\r\n\
    \  static X op(X x, X y) {\r\n    auto [xc, xs, xm] = x;\r\n    auto [yc, ys,\
    \ ym] = y;\r\n    return {xc + yc, xs + ys, min(xm, ym)};\r\n  }\r\n  static constexpr\
    \ X unit() { return {0, 0, numeric_limits<ll>::max()}; }\r\n  static constexpr\
    \ bool commute = true;\r\n};\r\n#line 2 \"alg/group/add.hpp\"\n\r\ntemplate <typename\
    \ E>\r\nstruct Group_Add {\r\n  using X = E;\r\n  using value_type = X;\r\n  static\
    \ constexpr X op(const X &x, const X &y) noexcept { return x + y; }\r\n  static\
    \ constexpr X inverse(const X &x) noexcept { return -x; }\r\n  static constexpr\
    \ X power(const X &x, ll n) noexcept { return X(n) * x; }\r\n  static constexpr\
    \ X unit() { return X(0); }\r\n  static constexpr bool commute = true;\r\n};\r\
    \n#line 3 \"alg/lazy/cntsummin_add.hpp\"\n\r\nstruct Lazy_CntSumMin_Add {\r\n\
    \  static constexpr ll INF = 1LL << 60;\r\n  using MX = Monoid_CntSumMin;\r\n\
    \  using MA = Group_Add<ll>;\r\n  using X_structure = MX;\r\n  using A_structure\
    \ = MA;\r\n  using X = typename MX::value_type;\r\n  using A = typename MA::value_type;\r\
    \n  static constexpr X act(const X& x, const A& a) {\r\n    auto [xc, xs, xm]\
    \ = x;\r\n    return {xc, xs + xc * a, xm + a};\r\n  }\r\n};\r\n"
  code: "#include \"alg/monoid/cntsummin.hpp\"\r\n#include \"alg/group/add.hpp\"\r\
    \n\r\nstruct Lazy_CntSumMin_Add {\r\n  static constexpr ll INF = 1LL << 60;\r\n\
    \  using MX = Monoid_CntSumMin;\r\n  using MA = Group_Add<ll>;\r\n  using X_structure\
    \ = MX;\r\n  using A_structure = MA;\r\n  using X = typename MX::value_type;\r\
    \n  using A = typename MA::value_type;\r\n  static constexpr X act(const X& x,\
    \ const A& a) {\r\n    auto [xc, xs, xm] = x;\r\n    return {xc, xs + xc * a,\
    \ xm + a};\r\n  }\r\n};\r\n"
  dependsOn:
  - alg/monoid/cntsummin.hpp
  - alg/group/add.hpp
  isVerificationFile: false
  path: alg/lazy/cntsummin_add.hpp
  requiredBy: []
  timestamp: '2022-10-24 14:33:15+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: alg/lazy/cntsummin_add.hpp
layout: document
redirect_from:
- /library/alg/lazy/cntsummin_add.hpp
- /library/alg/lazy/cntsummin_add.hpp.html
title: alg/lazy/cntsummin_add.hpp
---
