---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: alg/monoid/add.hpp
    title: alg/monoid/add.hpp
  - icon: ':heavy_check_mark:'
    path: alg/monoid/summax.hpp
    title: alg/monoid/summax.hpp
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/mytest/kdtree_am.test.cpp
    title: test/mytest/kdtree_am.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/mytest/summax_add.test.cpp
    title: test/mytest/summax_add.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 2 \"alg/monoid/summax.hpp\"\n\ntemplate <typename E>\nstruct\
    \ Monoid_SumMax {\n  using value_type = pair<E, E>;\n  using X = value_type;\n\
    \  static X op(X x, X y) { return {x.fi + y.fi, max(x.se, y.se)}; }\n  static\
    \ X from_element(E e) { return {e, e}; }\n  static constexpr X unit() { return\
    \ {E(0), -infty<E>}; }\n  static constexpr bool commute = 1;\n};\n#line 2 \"alg/monoid/add.hpp\"\
    \n\r\ntemplate <typename X>\r\nstruct Monoid_Add {\r\n  using value_type = X;\r\
    \n  static constexpr X op(const X &x, const X &y) noexcept { return x + y; }\r\
    \n  static constexpr X inverse(const X &x) noexcept { return -x; }\r\n  static\
    \ constexpr X power(const X &x, ll n) noexcept { return X(n) * x; }\r\n  static\
    \ constexpr X unit() { return X(0); }\r\n  static constexpr bool commute = true;\r\
    \n};\r\n#line 3 \"alg/acted_monoid/summax_add.hpp\"\n\ntemplate <typename E>\n\
    struct ActedMonoid_SumMax_Add {\n  using Monoid_X = Monoid_SumMax<E>;\n  using\
    \ Monoid_A = Monoid_Add<E>;\n  using X = typename Monoid_X::value_type;\n  using\
    \ A = typename Monoid_A::value_type;\n  static constexpr X act(const X& x, const\
    \ A& a, const ll& size) {\n    auto [xs, xm] = x;\n    xm = (xm == -infty<E> ?\
    \ xm : xm + a);\n    return {xs + E(size) * a, xm};\n  }\n};\n"
  code: "#include \"alg/monoid/summax.hpp\"\n#include \"alg/monoid/add.hpp\"\n\ntemplate\
    \ <typename E>\nstruct ActedMonoid_SumMax_Add {\n  using Monoid_X = Monoid_SumMax<E>;\n\
    \  using Monoid_A = Monoid_Add<E>;\n  using X = typename Monoid_X::value_type;\n\
    \  using A = typename Monoid_A::value_type;\n  static constexpr X act(const X&\
    \ x, const A& a, const ll& size) {\n    auto [xs, xm] = x;\n    xm = (xm == -infty<E>\
    \ ? xm : xm + a);\n    return {xs + E(size) * a, xm};\n  }\n};\n"
  dependsOn:
  - alg/monoid/summax.hpp
  - alg/monoid/add.hpp
  isVerificationFile: false
  path: alg/acted_monoid/summax_add.hpp
  requiredBy: []
  timestamp: '2023-02-01 23:31:55+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/mytest/kdtree_am.test.cpp
  - test/mytest/summax_add.test.cpp
documentation_of: alg/acted_monoid/summax_add.hpp
layout: document
redirect_from:
- /library/alg/acted_monoid/summax_add.hpp
- /library/alg/acted_monoid/summax_add.hpp.html
title: alg/acted_monoid/summax_add.hpp
---
