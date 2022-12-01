---
data:
  _extendedDependsOn:
  - icon: ':x:'
    path: alg/monoid/add.hpp
    title: alg/monoid/add.hpp
  - icon: ':warning:'
    path: alg/monoid/minmax.hpp
    title: alg/monoid/minmax.hpp
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':warning:'
  attributes:
    links: []
  bundledCode: "#line 2 \"alg/monoid/add.hpp\"\n\r\ntemplate <typename X>\r\nstruct\
    \ Monoid_Add {\r\n  using value_type = X;\r\n  static constexpr X op(const X &x,\
    \ const X &y) noexcept { return x + y; }\r\n  static constexpr X inverse(const\
    \ X &x) noexcept { return -x; }\r\n  static constexpr X power(const X &x, ll n)\
    \ noexcept { return X(n) * x; }\r\n  static constexpr X unit() { return X(0);\
    \ }\r\n  static constexpr bool commute = true;\r\n};\r\n#line 2 \"alg/monoid/minmax.hpp\"\
    \n\r\ntemplate <class X>\r\nstruct Monoid_MinMax {\r\n  using P = pair<X, X>;\r\
    \n  using value_type = P;\r\n  static constexpr P op(const P x, const P y) noexcept\
    \ {\r\n    return {min(x.fi, y.fi), max(x.se, y.se)};\r\n  }\r\n  static constexpr\
    \ P from_element(const X x) { return {x, x}; }\r\n  static constexpr P unit()\
    \ {\r\n    return {numeric_limits<X>::max(), numeric_limits<X>::lowest()};\r\n\
    \  }\r\n  static constexpr bool commute = true;\r\n};\r\n#line 3 \"alg/acted_monoid/minmax_add.hpp\"\
    \n\r\ntemplate <typename E>\r\nstruct ActedMonoid_MinMax_Add {\r\n  using Monoid_X\
    \ = Monoid_MinMax<E>;\r\n  using Monoid_A = Monoid_Add<E>;\r\n  using X = typename\
    \ Monoid_X::value_type;\r\n  using A = typename Monoid_A::value_type;\r\n  static\
    \ constexpr X act(const X &x, const A &a) {\r\n    E lo = (x.fi == numeric_limits<E>::max()\
    \ ? x.fi : x.fi + a);\r\n    E hi = (x.se == numeric_limits<E>::lowest() ? x.se\
    \ : x.se + a);\r\n    return {lo, hi};\r\n  }\r\n};\r\n"
  code: "#include \"alg/monoid/add.hpp\"\r\n#include \"alg/monoid/minmax.hpp\"\r\n\
    \r\ntemplate <typename E>\r\nstruct ActedMonoid_MinMax_Add {\r\n  using Monoid_X\
    \ = Monoid_MinMax<E>;\r\n  using Monoid_A = Monoid_Add<E>;\r\n  using X = typename\
    \ Monoid_X::value_type;\r\n  using A = typename Monoid_A::value_type;\r\n  static\
    \ constexpr X act(const X &x, const A &a) {\r\n    E lo = (x.fi == numeric_limits<E>::max()\
    \ ? x.fi : x.fi + a);\r\n    E hi = (x.se == numeric_limits<E>::lowest() ? x.se\
    \ : x.se + a);\r\n    return {lo, hi};\r\n  }\r\n};\r\n"
  dependsOn:
  - alg/monoid/add.hpp
  - alg/monoid/minmax.hpp
  isVerificationFile: false
  path: alg/acted_monoid/minmax_add.hpp
  requiredBy: []
  timestamp: '2022-11-28 15:05:14+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: alg/acted_monoid/minmax_add.hpp
layout: document
redirect_from:
- /library/alg/acted_monoid/minmax_add.hpp
- /library/alg/acted_monoid/minmax_add.hpp.html
title: alg/acted_monoid/minmax_add.hpp
---
