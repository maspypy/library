---
data:
  _extendedDependsOn:
  - icon: ':question:'
    path: alg/monoid_min.hpp
    title: alg/monoid_min.hpp
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':warning:'
  attributes:
    links: []
  bundledCode: "#line 2 \"alg/monoid_min.hpp\"\ntemplate <class X, X INF>\r\nstruct\
    \ Monoid_Min {\r\n  using value_type = X;\r\n  static constexpr X op(const X &x,\
    \ const X &y) noexcept { return min(x, y); }\r\n  static constexpr X unit() {\
    \ return INF; }\r\n  static constexpr bool commute = true;\r\n};\r\n#line 2 \"\
    alg/lazy_min_min.hpp\"\n\r\ntemplate <typename E, E INF>\r\nstruct Lazy_Min_Min\
    \ {\r\n  using MX = Monoid_Min<E, INF>;\r\n  using MA = Monoid_Min<E, INF>;\r\n\
    \  using X_structure = MX;\r\n  using A_structure = MA;\r\n  using X = typename\
    \ MX::value_type;\r\n  using A = typename MA::value_type;\r\n  static constexpr\
    \ X act(const X &x, const A &a) { return min(x, a); }\r\n};\r\n"
  code: "#include \"alg/monoid_min.hpp\"\r\n\r\ntemplate <typename E, E INF>\r\nstruct\
    \ Lazy_Min_Min {\r\n  using MX = Monoid_Min<E, INF>;\r\n  using MA = Monoid_Min<E,\
    \ INF>;\r\n  using X_structure = MX;\r\n  using A_structure = MA;\r\n  using X\
    \ = typename MX::value_type;\r\n  using A = typename MA::value_type;\r\n  static\
    \ constexpr X act(const X &x, const A &a) { return min(x, a); }\r\n};\r\n"
  dependsOn:
  - alg/monoid_min.hpp
  isVerificationFile: false
  path: alg/lazy_min_min.hpp
  requiredBy: []
  timestamp: '2022-05-06 16:05:53+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: alg/lazy_min_min.hpp
layout: document
redirect_from:
- /library/alg/lazy_min_min.hpp
- /library/alg/lazy_min_min.hpp.html
title: alg/lazy_min_min.hpp
---
