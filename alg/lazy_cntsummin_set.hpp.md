---
data:
  _extendedDependsOn:
  - icon: ':warning:'
    path: alg/monoid_cntsummin.hpp
    title: alg/monoid_cntsummin.hpp
  - icon: ':heavy_check_mark:'
    path: alg/monoid_set.hpp
    title: alg/monoid_set.hpp
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':warning:'
  attributes:
    links: []
  bundledCode: "#line 2 \"alg/monoid_cntsummin.hpp\"\nstruct Monoid_CntSumMin {\r\n\
    \  static constexpr ll INF = 1LL << 60;\r\n  using value_type = tuple<ll, ll,\
    \ ll>;\r\n  using X = value_type;\r\n  static X op(X x, X y) {\r\n    auto [xc,\
    \ xs, xm] = x;\r\n    auto [yc, ys, ym] = y;\r\n    return {xc + yc, xs + ys,\
    \ min(xm, ym)};\r\n  }\r\n  static constexpr X unit() { return {0, 0, INF}; }\r\
    \n  static constexpr bool commute = true;\r\n};\r\n#line 1 \"alg/monoid_set.hpp\"\
    \ntemplate <typename E, E none_val>\r\nstruct Monoid_Set {\r\n  using value_type\
    \ = E;\r\n  using X = value_type;\r\n  static X op(X x, X y) { return (y == none_val\
    \ ? x : y); }\r\n  static constexpr X unit() { return none_val; }\r\n  static\
    \ constexpr bool commute = false;\r\n};\n#line 3 \"alg/lazy_cntsummin_set.hpp\"\
    \n\r\nstruct Lazy_CntSumMin_Set {\r\n  static constexpr ll INF = 1LL<<60;\r\n\
    \  using MX = Monoid_CntSumMin;\r\n  using MA = Monoid_Set<ll, INF>;\r\n  using\
    \ X_structure = MX;\r\n  using A_structure = MA;\r\n  using X = typename MX::value_type;\r\
    \n  using A = typename MA::value_type;\r\n  static constexpr X act(const X& x,\
    \ const A& a) {\r\n    if (a == INF) return x;\r\n    auto [xc, xs, xm] = x;\r\
    \n    return {xc, xc * a, a};\r\n  }\r\n};\r\n"
  code: "#include \"alg/monoid_cntsummin.hpp\"\r\n#include \"alg/monoid_set.hpp\"\r\
    \n\r\nstruct Lazy_CntSumMin_Set {\r\n  static constexpr ll INF = 1LL<<60;\r\n\
    \  using MX = Monoid_CntSumMin;\r\n  using MA = Monoid_Set<ll, INF>;\r\n  using\
    \ X_structure = MX;\r\n  using A_structure = MA;\r\n  using X = typename MX::value_type;\r\
    \n  using A = typename MA::value_type;\r\n  static constexpr X act(const X& x,\
    \ const A& a) {\r\n    if (a == INF) return x;\r\n    auto [xc, xs, xm] = x;\r\
    \n    return {xc, xc * a, a};\r\n  }\r\n};\r\n"
  dependsOn:
  - alg/monoid_cntsummin.hpp
  - alg/monoid_set.hpp
  isVerificationFile: false
  path: alg/lazy_cntsummin_set.hpp
  requiredBy: []
  timestamp: '2022-04-16 04:26:49+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: alg/lazy_cntsummin_set.hpp
layout: document
redirect_from:
- /library/alg/lazy_cntsummin_set.hpp
- /library/alg/lazy_cntsummin_set.hpp.html
title: alg/lazy_cntsummin_set.hpp
---
