---
data:
  _extendedDependsOn:
  - icon: ':question:'
    path: alg/monoid/min.hpp
    title: alg/monoid/min.hpp
  - icon: ':question:'
    path: alg/monoid/set.hpp
    title: alg/monoid/set.hpp
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/aoj/DSL_2_F.test.cpp
    title: test/aoj/DSL_2_F.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 2 \"alg/monoid/min.hpp\"\ntemplate <class X>\r\nstruct Monoid_Min\
    \ {\r\n  using value_type = X;\r\n  static constexpr X op(const X &x, const X\
    \ &y) noexcept { return min(x, y); }\r\n  static constexpr X unit() { return numeric_limits<X>::max();\
    \ }\r\n  static constexpr bool commute = true;\r\n};\r\n#line 1 \"alg/monoid/set.hpp\"\
    \ntemplate <typename E, E none_val>\r\nstruct Monoid_Set {\r\n  using value_type\
    \ = E;\r\n  using X = value_type;\r\n  static X op(X x, X y) { return (y == none_val\
    \ ? x : y); }\r\n  static constexpr X unit() { return none_val; }\r\n  static\
    \ constexpr bool commute = false;\r\n};\n#line 3 \"alg/lazy/min_set.hpp\"\n\r\n\
    template <typename E, E none_val>\r\nstruct Lazy_Min_Set {\r\n  using MX = Monoid_Min<E>;\r\
    \n  using MA = Monoid_Set<E, none_val>;\r\n  using X_structure = MX;\r\n  using\
    \ A_structure = MA;\r\n  using X = typename MX::value_type;\r\n  using A = typename\
    \ MA::value_type;\r\n  static constexpr X act(const X &x, const A &a) {\r\n  \
    \  return (a == none_val ? x : a);\r\n  }\r\n};\r\n"
  code: "#include \"alg/monoid/min.hpp\"\r\n#include \"alg/monoid/set.hpp\"\r\n\r\n\
    template <typename E, E none_val>\r\nstruct Lazy_Min_Set {\r\n  using MX = Monoid_Min<E>;\r\
    \n  using MA = Monoid_Set<E, none_val>;\r\n  using X_structure = MX;\r\n  using\
    \ A_structure = MA;\r\n  using X = typename MX::value_type;\r\n  using A = typename\
    \ MA::value_type;\r\n  static constexpr X act(const X &x, const A &a) {\r\n  \
    \  return (a == none_val ? x : a);\r\n  }\r\n};\r\n"
  dependsOn:
  - alg/monoid/min.hpp
  - alg/monoid/set.hpp
  isVerificationFile: false
  path: alg/lazy/min_set.hpp
  requiredBy: []
  timestamp: '2022-10-21 19:08:45+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/aoj/DSL_2_F.test.cpp
documentation_of: alg/lazy/min_set.hpp
layout: document
redirect_from:
- /library/alg/lazy/min_set.hpp
- /library/alg/lazy/min_set.hpp.html
title: alg/lazy/min_set.hpp
---
