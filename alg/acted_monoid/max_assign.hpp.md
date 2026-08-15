---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: alg/monoid/assign.hpp
    title: alg/monoid/assign.hpp
  - icon: ':question:'
    path: alg/monoid/max.hpp
    title: alg/monoid/max.hpp
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/1_mytest/max_assign.test.cpp
    title: test/1_mytest/max_assign.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 1 \"alg/monoid/max.hpp\"\n\ntemplate <typename E>\nstruct Monoid_Max\
    \ {\n  using X = E;\n  using value_type = X;\n  static constexpr X op(const X\
    \ &x, const X &y) noexcept { return max(x, y); }\n  static constexpr X unit()\
    \ { return -infty<E>; }\n  static constexpr bool commute = true;\n};\n#line 1\
    \ \"alg/monoid/assign.hpp\"\n\ntemplate <typename X, int none_val>\nstruct Monoid_Assign\
    \ {\n  using value_type = X;\n  static X op(X x, X y) { return (y == X(none_val)\
    \ ? x : y); }\n  static constexpr X unit() { return X(none_val); }\n  static constexpr\
    \ bool commute = false;\n};\n#line 3 \"alg/acted_monoid/max_assign.hpp\"\n\r\n\
    template <typename E, E none_val>\r\nstruct ActedMonoid_Max_Assign {\r\n  using\
    \ Monoid_X = Monoid_Max<E>;\r\n  using Monoid_A = Monoid_Assign<E, none_val>;\r\
    \n  using X = typename Monoid_X::value_type;\r\n  using A = typename Monoid_A::value_type;\r\
    \n  static constexpr X act(const X &x, const A &a, const ll &size) {\r\n    return\
    \ (a == none_val ? x : a);\r\n  }\r\n};\r\n"
  code: "#include \"alg/monoid/max.hpp\"\r\n#include \"alg/monoid/assign.hpp\"\r\n\
    \r\ntemplate <typename E, E none_val>\r\nstruct ActedMonoid_Max_Assign {\r\n \
    \ using Monoid_X = Monoid_Max<E>;\r\n  using Monoid_A = Monoid_Assign<E, none_val>;\r\
    \n  using X = typename Monoid_X::value_type;\r\n  using A = typename Monoid_A::value_type;\r\
    \n  static constexpr X act(const X &x, const A &a, const ll &size) {\r\n    return\
    \ (a == none_val ? x : a);\r\n  }\r\n};\r\n"
  dependsOn:
  - alg/monoid/max.hpp
  - alg/monoid/assign.hpp
  isVerificationFile: false
  path: alg/acted_monoid/max_assign.hpp
  requiredBy: []
  timestamp: '2026-08-16 04:03:00+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/1_mytest/max_assign.test.cpp
documentation_of: alg/acted_monoid/max_assign.hpp
layout: document
redirect_from:
- /library/alg/acted_monoid/max_assign.hpp
- /library/alg/acted_monoid/max_assign.hpp.html
title: alg/acted_monoid/max_assign.hpp
---
