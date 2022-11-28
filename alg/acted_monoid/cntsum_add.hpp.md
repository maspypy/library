---
data:
  _extendedDependsOn:
  - icon: ':question:'
    path: alg/monoid/add.hpp
    title: alg/monoid/add.hpp
  - icon: ':question:'
    path: alg/monoid/add_pair.hpp
    title: alg/monoid/add_pair.hpp
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/yukicoder/235.test.cpp
    title: test/yukicoder/235.test.cpp
  - icon: ':x:'
    path: test/yukicoder/789_2.test.cpp
    title: test/yukicoder/789_2.test.cpp
  _isVerificationFailed: true
  _pathExtension: hpp
  _verificationStatusIcon: ':question:'
  attributes:
    links: []
  bundledCode: "#line 2 \"alg/monoid/add.hpp\"\n\r\ntemplate <typename X>\r\nstruct\
    \ Monoid_Add {\r\n  using value_type = X;\r\n  static constexpr X op(const X &x,\
    \ const X &y) noexcept { return x + y; }\r\n  static constexpr X inverse(const\
    \ X &x) noexcept { return -x; }\r\n  static constexpr X power(const X &x, ll n)\
    \ noexcept { return X(n) * x; }\r\n  static constexpr X unit() { return X(0);\
    \ }\r\n  static constexpr bool commute = true;\r\n};\r\n#line 1 \"alg/monoid/add_pair.hpp\"\
    \ntemplate <typename E>\r\nstruct Monoid_Add_Pair {\r\n  using value_type = pair<E,\
    \ E>;\r\n  using X = value_type;\r\n  static constexpr X op(const X &x, const\
    \ X &y) {\r\n    return {x.fi + y.fi, x.se + y.se};\r\n  }\r\n  static constexpr\
    \ X inverse(const X &x) { return {-x.fi, -x.se}; }\r\n  static constexpr X unit()\
    \ { return {0, 0}; }\r\n  static constexpr bool commute = true;\r\n};\r\n#line\
    \ 3 \"alg/acted_monoid/cntsum_add.hpp\"\n\r\ntemplate <typename E>\r\nstruct ActedMonoid_CntSum_Add\
    \ {\r\n  using Monoid_X = Monoid_Add_Pair<E>;\r\n  using Monoid_A = Monoid_Add<E>;\r\
    \n  using X = typename Monoid_X::value_type;\r\n  using A = typename Monoid_A::value_type;\r\
    \n  static constexpr X act(const X &x, const A &a) {\r\n    return {x.fi, x.se\
    \ + x.fi * a};\r\n  }\r\n};\r\n"
  code: "#include \"alg/monoid/add.hpp\"\r\n#include \"alg/monoid/add_pair.hpp\"\r\
    \n\r\ntemplate <typename E>\r\nstruct ActedMonoid_CntSum_Add {\r\n  using Monoid_X\
    \ = Monoid_Add_Pair<E>;\r\n  using Monoid_A = Monoid_Add<E>;\r\n  using X = typename\
    \ Monoid_X::value_type;\r\n  using A = typename Monoid_A::value_type;\r\n  static\
    \ constexpr X act(const X &x, const A &a) {\r\n    return {x.fi, x.se + x.fi *\
    \ a};\r\n  }\r\n};\r\n"
  dependsOn:
  - alg/monoid/add.hpp
  - alg/monoid/add_pair.hpp
  isVerificationFile: false
  path: alg/acted_monoid/cntsum_add.hpp
  requiredBy: []
  timestamp: '2022-11-28 15:09:50+09:00'
  verificationStatus: LIBRARY_SOME_WA
  verifiedWith:
  - test/yukicoder/235.test.cpp
  - test/yukicoder/789_2.test.cpp
documentation_of: alg/acted_monoid/cntsum_add.hpp
layout: document
redirect_from:
- /library/alg/acted_monoid/cntsum_add.hpp
- /library/alg/acted_monoid/cntsum_add.hpp.html
title: alg/acted_monoid/cntsum_add.hpp
---
