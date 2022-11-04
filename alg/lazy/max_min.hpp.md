---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: alg/monoid/max.hpp
    title: alg/monoid/max.hpp
  - icon: ':heavy_check_mark:'
    path: alg/monoid/min.hpp
    title: alg/monoid/min.hpp
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':warning:'
  attributes:
    links: []
  bundledCode: "#line 2 \"alg/monoid/max.hpp\"\ntemplate <class X>\r\nstruct Monoid_Max\
    \ {\r\n  using value_type = X;\r\n  static constexpr X op(const X &x, const X\
    \ &y) noexcept { return max(x, y); }\r\n  static constexpr X unit() { return numeric_limits<X>::lowest();\
    \ }\r\n  static constexpr bool commute = true;\r\n};\r\n#line 2 \"alg/monoid/min.hpp\"\
    \ntemplate <class X>\r\nstruct Monoid_Min {\r\n  using value_type = X;\r\n  static\
    \ constexpr X op(const X &x, const X &y) noexcept { return min(x, y); }\r\n  static\
    \ constexpr X unit() { return numeric_limits<X>::max(); }\r\n  static constexpr\
    \ bool commute = true;\r\n};\r\n#line 3 \"alg/lazy/max_min.hpp\"\n\r\ntemplate\
    \ <typename E>\r\nstruct Lazy_Max_Min {\r\n  using MX = Monoid_Max<E>;\r\n  using\
    \ MA = Monoid_Min<E>;\r\n  using X_structure = MX;\r\n  using A_structure = MA;\r\
    \n  using X = typename MX::value_type;\r\n  using A = typename MA::value_type;\r\
    \n  static constexpr X act(const X &x, const A &a) { return min(x, a); }\r\n};\r\
    \n"
  code: "#include \"alg/monoid/max.hpp\"\r\n#include \"alg/monoid/min.hpp\"\r\n\r\n\
    template <typename E>\r\nstruct Lazy_Max_Min {\r\n  using MX = Monoid_Max<E>;\r\
    \n  using MA = Monoid_Min<E>;\r\n  using X_structure = MX;\r\n  using A_structure\
    \ = MA;\r\n  using X = typename MX::value_type;\r\n  using A = typename MA::value_type;\r\
    \n  static constexpr X act(const X &x, const A &a) { return min(x, a); }\r\n};\r\
    \n"
  dependsOn:
  - alg/monoid/max.hpp
  - alg/monoid/min.hpp
  isVerificationFile: false
  path: alg/lazy/max_min.hpp
  requiredBy: []
  timestamp: '2022-10-24 14:33:15+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: alg/lazy/max_min.hpp
layout: document
redirect_from:
- /library/alg/lazy/max_min.hpp
- /library/alg/lazy/max_min.hpp.html
title: alg/lazy/max_min.hpp
---
