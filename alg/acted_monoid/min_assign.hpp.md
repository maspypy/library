---
data:
  _extendedDependsOn:
  - icon: ':question:'
    path: alg/monoid/assign.hpp
    title: alg/monoid/assign.hpp
  - icon: ':question:'
    path: alg/monoid/min.hpp
    title: alg/monoid/min.hpp
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':x:'
    path: test/1_mytest/rbst_am.test.cpp
    title: test/1_mytest/rbst_am.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/1_mytest/rbst_am_persistent.test.cpp
    title: test/1_mytest/rbst_am_persistent.test.cpp
  - icon: ':x:'
    path: test/4_aoj/DSL_2_F.test.cpp
    title: test/4_aoj/DSL_2_F.test.cpp
  _isVerificationFailed: true
  _pathExtension: hpp
  _verificationStatusIcon: ':question:'
  attributes:
    links: []
  bundledCode: "#line 2 \"alg/monoid/min.hpp\"\n\r\ntemplate <typename E>\r\nstruct\
    \ Monoid_Min {\r\n  using X = E;\r\n  using value_type = X;\r\n  static constexpr\
    \ X op(const X &x, const X &y) noexcept { return min(x, y); }\r\n  static constexpr\
    \ X unit() { return infty<E>; }\r\n  static constexpr bool commute = true;\r\n\
    };\r\n#line 2 \"alg/monoid/assign.hpp\"\n\r\ntemplate <typename X, int none_val>\r\
    \nstruct Monoid_Assign {\r\n  using value_type = X;\r\n  static X op(X x, X y)\
    \ { return (y == X(none_val) ? x : y); }\r\n  static constexpr X unit() { return\
    \ X(none_val); }\r\n  static constexpr bool commute = false;\r\n};\r\n#line 3\
    \ \"alg/acted_monoid/min_assign.hpp\"\n\r\ntemplate <typename E, E none_val>\r\
    \nstruct ActedMonoid_Min_Assign {\r\n  using Monoid_X = Monoid_Min<E>;\r\n  using\
    \ Monoid_A = Monoid_Assign<E, none_val>;\r\n  using X = typename Monoid_X::value_type;\r\
    \n  using A = typename Monoid_A::value_type;\r\n  static constexpr X act(const\
    \ X &x, const A &a, const ll &size) {\r\n    return (a == none_val ? x : a);\r\
    \n  }\r\n};\r\n"
  code: "#include \"alg/monoid/min.hpp\"\r\n#include \"alg/monoid/assign.hpp\"\r\n\
    \r\ntemplate <typename E, E none_val>\r\nstruct ActedMonoid_Min_Assign {\r\n \
    \ using Monoid_X = Monoid_Min<E>;\r\n  using Monoid_A = Monoid_Assign<E, none_val>;\r\
    \n  using X = typename Monoid_X::value_type;\r\n  using A = typename Monoid_A::value_type;\r\
    \n  static constexpr X act(const X &x, const A &a, const ll &size) {\r\n    return\
    \ (a == none_val ? x : a);\r\n  }\r\n};\r\n"
  dependsOn:
  - alg/monoid/min.hpp
  - alg/monoid/assign.hpp
  isVerificationFile: false
  path: alg/acted_monoid/min_assign.hpp
  requiredBy: []
  timestamp: '2023-10-14 20:28:40+09:00'
  verificationStatus: LIBRARY_SOME_WA
  verifiedWith:
  - test/1_mytest/rbst_am_persistent.test.cpp
  - test/1_mytest/rbst_am.test.cpp
  - test/4_aoj/DSL_2_F.test.cpp
documentation_of: alg/acted_monoid/min_assign.hpp
layout: document
redirect_from:
- /library/alg/acted_monoid/min_assign.hpp
- /library/alg/acted_monoid/min_assign.hpp.html
title: alg/acted_monoid/min_assign.hpp
---
