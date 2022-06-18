---
data:
  _extendedDependsOn:
  - icon: ':question:'
    path: alg/monoid_min.hpp
    title: alg/monoid_min.hpp
  - icon: ':heavy_check_mark:'
    path: alg/monoid_set.hpp
    title: alg/monoid_set.hpp
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/aoj/DSL_2_F_min_set_lazy.test.cpp
    title: test/aoj/DSL_2_F_min_set_lazy.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 2 \"alg/monoid_min.hpp\"\ntemplate <class X>\r\nstruct Monoid_Min\
    \ {\r\n  using value_type = X;\r\n  static constexpr X op(const X &x, const X\
    \ &y) noexcept { return min(x, y); }\r\n  static constexpr X unit() { return numeric_limits<X>::max();\
    \ }\r\n  static constexpr bool commute = true;\r\n};\r\n#line 1 \"alg/monoid_set.hpp\"\
    \ntemplate <typename E, E none_val>\r\nstruct Monoid_Set {\r\n  using value_type\
    \ = E;\r\n  using X = value_type;\r\n  static X op(X x, X y) { return (y == none_val\
    \ ? x : y); }\r\n  static constexpr X unit() { return none_val; }\r\n  static\
    \ constexpr bool commute = false;\r\n};\n#line 3 \"alg/lazy_min_set.hpp\"\n\r\n\
    template <typename E, E none_val>\r\nstruct Lazy_Min_Set {\r\n  using MX = Monoid_Min<E>;\r\
    \n  using MA = Monoid_Set<E, none_val>;\r\n  using X_structure = MX;\r\n  using\
    \ A_structure = MA;\r\n  using X = typename MX::value_type;\r\n  using A = typename\
    \ MA::value_type;\r\n  static constexpr X act(const X &x, const A &a) {\r\n  \
    \  return (a == none_val ? x : a);\r\n  }\r\n};\r\n"
  code: "#include \"alg/monoid_min.hpp\"\r\n#include \"alg/monoid_set.hpp\"\r\n\r\n\
    template <typename E, E none_val>\r\nstruct Lazy_Min_Set {\r\n  using MX = Monoid_Min<E>;\r\
    \n  using MA = Monoid_Set<E, none_val>;\r\n  using X_structure = MX;\r\n  using\
    \ A_structure = MA;\r\n  using X = typename MX::value_type;\r\n  using A = typename\
    \ MA::value_type;\r\n  static constexpr X act(const X &x, const A &a) {\r\n  \
    \  return (a == none_val ? x : a);\r\n  }\r\n};\r\n"
  dependsOn:
  - alg/monoid_min.hpp
  - alg/monoid_set.hpp
  isVerificationFile: false
  path: alg/lazy_min_set.hpp
  requiredBy: []
  timestamp: '2022-05-13 21:02:36+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/aoj/DSL_2_F_min_set_lazy.test.cpp
documentation_of: alg/lazy_min_set.hpp
layout: document
redirect_from:
- /library/alg/lazy_min_set.hpp
- /library/alg/lazy_min_set.hpp.html
title: alg/lazy_min_set.hpp
---
