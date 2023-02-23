---
data:
  _extendedDependsOn:
  - icon: ':question:'
    path: alg/monoid/add.hpp
    title: alg/monoid/add.hpp
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':x:'
    path: test/aoj/GRL_5_E.test.cpp
    title: test/aoj/GRL_5_E.test.cpp
  - icon: ':x:'
    path: test/mytest/ARC30D.test.cpp
    title: test/mytest/ARC30D.test.cpp
  - icon: ':x:'
    path: test/mytest/rbst_am_2.test.cpp
    title: test/mytest/rbst_am_2.test.cpp
  - icon: ':x:'
    path: test/mytest/splay_am.test.cpp
    title: test/mytest/splay_am.test.cpp
  - icon: ':x:'
    path: test/yukicoder/1197.test.cpp
    title: test/yukicoder/1197.test.cpp
  - icon: ':x:'
    path: test/yukicoder/789_2.test.cpp
    title: test/yukicoder/789_2.test.cpp
  - icon: ':x:'
    path: test_atcoder/abc234g.test.cpp
    title: test_atcoder/abc234g.test.cpp
  _isVerificationFailed: true
  _pathExtension: hpp
  _verificationStatusIcon: ':x:'
  attributes:
    links: []
  bundledCode: "#line 2 \"alg/monoid/add.hpp\"\n\r\ntemplate <typename X>\r\nstruct\
    \ Monoid_Add {\r\n  using value_type = X;\r\n  static constexpr X op(const X &x,\
    \ const X &y) noexcept { return x + y; }\r\n  static constexpr X inverse(const\
    \ X &x) noexcept { return -x; }\r\n  static constexpr X power(const X &x, ll n)\
    \ noexcept { return X(n) * x; }\r\n  static constexpr X unit() { return X(0);\
    \ }\r\n  static constexpr bool commute = true;\r\n};\r\n#line 2 \"alg/acted_monoid/sum_add.hpp\"\
    \n\r\ntemplate <typename E>\r\nstruct ActedMonoid_Sum_Add {\r\n  using Monoid_X\
    \ = Monoid_Add<E>;\r\n  using Monoid_A = Monoid_Add<E>;\r\n  using X = typename\
    \ Monoid_X::value_type;\r\n  using A = typename Monoid_A::value_type;\r\n  static\
    \ constexpr X act(const X &x, const A &a, const ll &size) {\r\n    return x +\
    \ a * E(size);\r\n  }\r\n};\r\n"
  code: "#include \"alg/monoid/add.hpp\"\r\n\r\ntemplate <typename E>\r\nstruct ActedMonoid_Sum_Add\
    \ {\r\n  using Monoid_X = Monoid_Add<E>;\r\n  using Monoid_A = Monoid_Add<E>;\r\
    \n  using X = typename Monoid_X::value_type;\r\n  using A = typename Monoid_A::value_type;\r\
    \n  static constexpr X act(const X &x, const A &a, const ll &size) {\r\n    return\
    \ x + a * E(size);\r\n  }\r\n};\r\n"
  dependsOn:
  - alg/monoid/add.hpp
  isVerificationFile: false
  path: alg/acted_monoid/sum_add.hpp
  requiredBy: []
  timestamp: '2022-12-03 07:16:30+09:00'
  verificationStatus: LIBRARY_ALL_WA
  verifiedWith:
  - test_atcoder/abc234g.test.cpp
  - test/yukicoder/1197.test.cpp
  - test/yukicoder/789_2.test.cpp
  - test/mytest/rbst_am_2.test.cpp
  - test/mytest/splay_am.test.cpp
  - test/mytest/ARC30D.test.cpp
  - test/aoj/GRL_5_E.test.cpp
documentation_of: alg/acted_monoid/sum_add.hpp
layout: document
redirect_from:
- /library/alg/acted_monoid/sum_add.hpp
- /library/alg/acted_monoid/sum_add.hpp.html
title: alg/acted_monoid/sum_add.hpp
---
