---
data:
  _extendedDependsOn:
  - icon: ':x:'
    path: alg/monoid_max.hpp
    title: alg/monoid_max.hpp
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
  bundledCode: "#line 1 \"alg/monoid_max.hpp\"\ntemplate <class X, X INF>\r\nstruct\
    \ Monoid_Max {\r\n  using value_type = X;\r\n  static constexpr X op(const X &x,\
    \ const X &y) noexcept { return max(x, y); }\r\n  static constexpr X unit() {\
    \ return -INF; }\r\n  static constexpr bool commute = true;\r\n};\r\n#line 1 \"\
    alg/monoid_set.hpp\"\ntemplate <typename E, E none_val>\r\nstruct Monoid_Set {\r\
    \n  using value_type = E;\r\n  using X = value_type;\r\n  static X op(X x, X y)\
    \ { return (y == none_val ? x : y); }\r\n  static constexpr X unit() { return\
    \ none_val; }\r\n  static constexpr bool commute = false;\r\n};\n#line 3 \"alg/lazy_max_set.hpp\"\
    \n\r\ntemplate <typename E, E INF, E none_val>\r\nstruct Lazy_Max_Set {\r\n  using\
    \ MX = Monoid_Max<E, INF>;\r\n  using MA = Monoid_Set<E, none_val>;\r\n  using\
    \ X_structure = MX;\r\n  using A_structure = MA;\r\n  using X = typename MX::value_type;\r\
    \n  using A = typename MA::value_type;\r\n  static constexpr X act(const X &x,\
    \ const A &a) { return (a==none_val ? x : a) ;}\r\n};\r\n"
  code: "#include \"alg/monoid_max.hpp\"\r\n#include \"alg/monoid_set.hpp\"\r\n\r\n\
    template <typename E, E INF, E none_val>\r\nstruct Lazy_Max_Set {\r\n  using MX\
    \ = Monoid_Max<E, INF>;\r\n  using MA = Monoid_Set<E, none_val>;\r\n  using X_structure\
    \ = MX;\r\n  using A_structure = MA;\r\n  using X = typename MX::value_type;\r\
    \n  using A = typename MA::value_type;\r\n  static constexpr X act(const X &x,\
    \ const A &a) { return (a==none_val ? x : a) ;}\r\n};\r\n"
  dependsOn:
  - alg/monoid_max.hpp
  - alg/monoid_set.hpp
  isVerificationFile: false
  path: alg/lazy_max_set.hpp
  requiredBy: []
  timestamp: '2022-04-16 04:26:49+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: alg/lazy_max_set.hpp
layout: document
redirect_from:
- /library/alg/lazy_max_set.hpp
- /library/alg/lazy_max_set.hpp.html
title: alg/lazy_max_set.hpp
---
