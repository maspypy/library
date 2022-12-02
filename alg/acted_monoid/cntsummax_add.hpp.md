---
data:
  _extendedDependsOn:
  - icon: ':question:'
    path: alg/monoid/add.hpp
    title: alg/monoid/add.hpp
  - icon: ':x:'
    path: alg/monoid/cntsummax.hpp
    title: alg/monoid/cntsummax.hpp
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':x:'
    path: test/mytest/cntsummax_add.test.cpp
    title: test/mytest/cntsummax_add.test.cpp
  _isVerificationFailed: true
  _pathExtension: hpp
  _verificationStatusIcon: ':x:'
  attributes:
    links: []
  bundledCode: "#line 2 \"alg/monoid/cntsummax.hpp\"\n\r\ntemplate <typename E>\r\n\
    struct Monoid_CntSumMax {\r\n  using value_type = tuple<E, E, E>;\r\n  using X\
    \ = value_type;\r\n  static X op(X x, X y) {\r\n    auto [xc, xs, xm] = x;\r\n\
    \    auto [yc, ys, ym] = y;\r\n    return {xc + yc, xs + ys, max(xm, ym)};\r\n\
    \  }\r\n  static X from_element(E x) { return {1, x, x}; }\r\n  static constexpr\
    \ X unit() { return {0, 0, numeric_limits<ll>::lowest()}; }\r\n  static constexpr\
    \ bool commute = true;\r\n};\r\n#line 2 \"alg/monoid/add.hpp\"\n\r\ntemplate <typename\
    \ X>\r\nstruct Monoid_Add {\r\n  using value_type = X;\r\n  static constexpr X\
    \ op(const X &x, const X &y) noexcept { return x + y; }\r\n  static constexpr\
    \ X inverse(const X &x) noexcept { return -x; }\r\n  static constexpr X power(const\
    \ X &x, ll n) noexcept { return X(n) * x; }\r\n  static constexpr X unit() { return\
    \ X(0); }\r\n  static constexpr bool commute = true;\r\n};\r\n#line 3 \"alg/acted_monoid/cntsummax_add.hpp\"\
    \n\ntemplate <typename E>\nstruct ActedMonoid_CntSumMax_Add {\n  using Monoid_X\
    \ = Monoid_CntSumMax<E>;\n  using Monoid_A = Monoid_Add<E>;\n  using X = typename\
    \ Monoid_X::value_type;\n  using A = typename Monoid_A::value_type;\n  static\
    \ constexpr X act(const X& x, const A& a) {\n    auto [xc, xs, xm] = x;\n    xm\
    \ = (xm == numeric_limits<E>::lowest() ? xm : xm + a);\n    return {xc, xs + xc\
    \ * a, xm};\n  }\n};\n"
  code: "#include \"alg/monoid/cntsummax.hpp\"\n#include \"alg/monoid/add.hpp\"\n\n\
    template <typename E>\nstruct ActedMonoid_CntSumMax_Add {\n  using Monoid_X =\
    \ Monoid_CntSumMax<E>;\n  using Monoid_A = Monoid_Add<E>;\n  using X = typename\
    \ Monoid_X::value_type;\n  using A = typename Monoid_A::value_type;\n  static\
    \ constexpr X act(const X& x, const A& a) {\n    auto [xc, xs, xm] = x;\n    xm\
    \ = (xm == numeric_limits<E>::lowest() ? xm : xm + a);\n    return {xc, xs + xc\
    \ * a, xm};\n  }\n};\n"
  dependsOn:
  - alg/monoid/cntsummax.hpp
  - alg/monoid/add.hpp
  isVerificationFile: false
  path: alg/acted_monoid/cntsummax_add.hpp
  requiredBy: []
  timestamp: '2022-11-28 15:09:50+09:00'
  verificationStatus: LIBRARY_ALL_WA
  verifiedWith:
  - test/mytest/cntsummax_add.test.cpp
documentation_of: alg/acted_monoid/cntsummax_add.hpp
layout: document
redirect_from:
- /library/alg/acted_monoid/cntsummax_add.hpp
- /library/alg/acted_monoid/cntsummax_add.hpp.html
title: alg/acted_monoid/cntsummax_add.hpp
---
