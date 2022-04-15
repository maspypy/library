---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: alg/monoid_max.hpp
    title: alg/monoid_max.hpp
  - icon: ':heavy_check_mark:'
    path: alg/monoid_min.hpp
    title: alg/monoid_min.hpp
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':warning:'
  attributes:
    links: []
  bundledCode: "#line 1 \"alg/monoid_max.hpp\"\ntemplate <class X, X INF>\r\nstruct\
    \ Monoid_Max {\r\n  using value_type = X;\r\n  static constexpr X op(const X &x,\
    \ const X &y) noexcept { return max(x, y); }\r\n  static constexpr X unit() {\
    \ return -INF; }\r\n  static constexpr bool commute = true;\r\n};\r\n#line 1 \"\
    alg/monoid_min.hpp\"\ntemplate <class X, X INF>\r\nstruct Monoid_Min {\r\n  using\
    \ value_type = X;\r\n  static constexpr X op(const X &x, const X &y) noexcept\
    \ { return min(x, y); }\r\n  static constexpr X unit() { return INF; }\r\n  static\
    \ constexpr bool commute = true;\r\n};\r\n#line 3 \"alg/lazy_max_min.hpp\"\ntemplate\
    \ <typename E = ll, E INF = 1LL << 60>\r\nstruct Lazy_Max_Min {\r\n  using MX\
    \ = Monoid_Max<E, INF>;\r\n  using MA = Monoid_Min<E, INF>;\r\n  using X_structure\
    \ = MX;\r\n  using A_structure = MA;\r\n  using X = typename MX::value_type;\r\
    \n  using A = typename MA::value_type;\r\n  static constexpr X act(const X &x,\
    \ const A &a) { return min(x, a); }\r\n};\r\n"
  code: "#include \"alg/monoid_max.hpp\"\r\n#include \"alg/monoid_min.hpp\"\r\ntemplate\
    \ <typename E = ll, E INF = 1LL << 60>\r\nstruct Lazy_Max_Min {\r\n  using MX\
    \ = Monoid_Max<E, INF>;\r\n  using MA = Monoid_Min<E, INF>;\r\n  using X_structure\
    \ = MX;\r\n  using A_structure = MA;\r\n  using X = typename MX::value_type;\r\
    \n  using A = typename MA::value_type;\r\n  static constexpr X act(const X &x,\
    \ const A &a) { return min(x, a); }\r\n};\r\n"
  dependsOn:
  - alg/monoid_max.hpp
  - alg/monoid_min.hpp
  isVerificationFile: false
  path: alg/lazy_max_min.hpp
  requiredBy: []
  timestamp: '2022-04-16 04:26:49+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: alg/lazy_max_min.hpp
layout: document
redirect_from:
- /library/alg/lazy_max_min.hpp
- /library/alg/lazy_max_min.hpp.html
title: alg/lazy_max_min.hpp
---
