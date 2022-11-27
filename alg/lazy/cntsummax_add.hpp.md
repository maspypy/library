---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: alg/monoid/add.hpp
    title: alg/monoid/add.hpp
  - icon: ':heavy_check_mark:'
    path: alg/monoid/cntsummax.hpp
    title: alg/monoid/cntsummax.hpp
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':warning:'
  attributes:
    links: []
  bundledCode: "#line 2 \"alg/monoid/cntsummax.hpp\"\n\r\ntemplate <typename E>\r\n\
    struct Monoid_CntSumMax {\r\n  using value_type = tuple<E, E, E>;\r\n  using X\
    \ = value_type;\r\n  static X op(X x, X y) {\r\n    auto [xc, xs, xm] = x;\r\n\
    \    auto [yc, ys, ym] = y;\r\n    return {xc + yc, xs + ys, max(xm, ym)};\r\n\
    \  }\r\n  static X from_element(E x) { return {1, x, x}; }\r\n  static constexpr\
    \ X unit() { return {0, 0, numeric_limits<ll>::lowest()}; }\r\n  static constexpr\
    \ bool commute = true;\r\n};\r\n#line 2 \"alg/monoid/add.hpp\"\n\r\ntemplate <typename\
    \ E>\r\nstruct Monoid_Add {\r\n  using X = E;\r\n  using value_type = X;\r\n \
    \ static constexpr X op(const X &x, const X &y) noexcept { return x + y; }\r\n\
    \  static constexpr X inverse(const X &x) noexcept { return -x; }\r\n  static\
    \ constexpr X power(const X &x, ll n) noexcept { return X(n) * x; }\r\n  static\
    \ constexpr X unit() { return X(0); }\r\n  static constexpr bool commute = true;\r\
    \n};\r\n#line 3 \"alg/lazy/cntsummax_add.hpp\"\n\ntemplate <typename E>\nstruct\
    \ Lazy_CntSumMax_Add {\n  using MX = Monoid_CntSumMax<E>;\n  using MA = Monoid_Add<E>;\n\
    \  using X_structure = MX;\n  using A_structure = MA;\n  using X = typename MX::value_type;\n\
    \  using A = typename MA::value_type;\n  static constexpr X act(const X& x, const\
    \ A& a) {\n    auto [xc, xs, xm] = x;\n    xm = (xm == numeric_limits<E>::lowest()\
    \ ? xm : xm + a);\n    return {xc, xs + xc * a, xm};\n  }\n};\n"
  code: "#include \"alg/monoid/cntsummax.hpp\"\n#include \"alg/monoid/add.hpp\"\n\n\
    template <typename E>\nstruct Lazy_CntSumMax_Add {\n  using MX = Monoid_CntSumMax<E>;\n\
    \  using MA = Monoid_Add<E>;\n  using X_structure = MX;\n  using A_structure =\
    \ MA;\n  using X = typename MX::value_type;\n  using A = typename MA::value_type;\n\
    \  static constexpr X act(const X& x, const A& a) {\n    auto [xc, xs, xm] = x;\n\
    \    xm = (xm == numeric_limits<E>::lowest() ? xm : xm + a);\n    return {xc,\
    \ xs + xc * a, xm};\n  }\n};\n"
  dependsOn:
  - alg/monoid/cntsummax.hpp
  - alg/monoid/add.hpp
  isVerificationFile: false
  path: alg/lazy/cntsummax_add.hpp
  requiredBy: []
  timestamp: '2022-11-27 22:19:51+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: alg/lazy/cntsummax_add.hpp
layout: document
redirect_from:
- /library/alg/lazy/cntsummax_add.hpp
- /library/alg/lazy/cntsummax_add.hpp.html
title: alg/lazy/cntsummax_add.hpp
---
