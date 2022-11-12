---
data:
  _extendedDependsOn:
  - icon: ':question:'
    path: alg/group/add.hpp
    title: alg/group/add.hpp
  - icon: ':heavy_check_mark:'
    path: alg/monoid/minmax.hpp
    title: alg/monoid/minmax.hpp
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':warning:'
  attributes:
    links: []
  bundledCode: "#line 2 \"alg/group/add.hpp\"\n\r\ntemplate <typename E>\r\nstruct\
    \ Group_Add {\r\n  using X = E;\r\n  using value_type = X;\r\n  static constexpr\
    \ X op(const X &x, const X &y) noexcept { return x + y; }\r\n  static constexpr\
    \ X inverse(const X &x) noexcept { return -x; }\r\n  static constexpr X power(const\
    \ X &x, ll n) noexcept { return X(n) * x; }\r\n  static constexpr X unit() { return\
    \ X(0); }\r\n  static constexpr bool commute = true;\r\n};\r\n#line 2 \"alg/monoid/minmax.hpp\"\
    \n\r\ntemplate <class X>\r\nstruct Monoid_MinMax {\r\n  using P = pair<X, X>;\r\
    \n  using value_type = P;\r\n  static constexpr P op(const P x, const P y) noexcept\
    \ {\r\n    return {min(x.fi, y.fi), max(x.se, y.se)};\r\n  }\r\n  static constexpr\
    \ P from_element(const X x) { return {x, x}; }\r\n  static constexpr P unit()\
    \ {\r\n    return {numeric_limits<X>::max(), numeric_limits<X>::lowest()};\r\n\
    \  }\r\n  static constexpr bool commute = true;\r\n};\r\n#line 3 \"alg/lazy/minmax_add.hpp\"\
    \n\r\ntemplate <typename E, E INF>\r\nstruct Lazy_MinMax_Add {\r\n  using MX =\
    \ Monoid_MinMax<E, INF>;\r\n  using MA = Group_Add<E>;\r\n  using X_structure\
    \ = MX;\r\n  using A_structure = MA;\r\n  using X = typename MX::value_type;\r\
    \n  using A = typename MA::value_type;\r\n  static constexpr X act(const X &x,\
    \ const A &a) {\r\n    X lo = (x.fi == numeric_limits<X>::max() ? x.fi : x.fi\
    \ + a);\r\n    X hi = (x.se == numeric_limits<X>::lowest() ? x.se : x.se + a);\r\
    \n    return {lo, hi};\r\n  }\r\n};\n"
  code: "#include \"alg/group/add.hpp\"\r\n#include \"alg/monoid/minmax.hpp\"\r\n\r\
    \ntemplate <typename E, E INF>\r\nstruct Lazy_MinMax_Add {\r\n  using MX = Monoid_MinMax<E,\
    \ INF>;\r\n  using MA = Group_Add<E>;\r\n  using X_structure = MX;\r\n  using\
    \ A_structure = MA;\r\n  using X = typename MX::value_type;\r\n  using A = typename\
    \ MA::value_type;\r\n  static constexpr X act(const X &x, const A &a) {\r\n  \
    \  X lo = (x.fi == numeric_limits<X>::max() ? x.fi : x.fi + a);\r\n    X hi =\
    \ (x.se == numeric_limits<X>::lowest() ? x.se : x.se + a);\r\n    return {lo,\
    \ hi};\r\n  }\r\n};"
  dependsOn:
  - alg/group/add.hpp
  - alg/monoid/minmax.hpp
  isVerificationFile: false
  path: alg/lazy/minmax_add.hpp
  requiredBy: []
  timestamp: '2022-10-24 14:33:15+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: alg/lazy/minmax_add.hpp
layout: document
redirect_from:
- /library/alg/lazy/minmax_add.hpp
- /library/alg/lazy/minmax_add.hpp.html
title: alg/lazy/minmax_add.hpp
---
