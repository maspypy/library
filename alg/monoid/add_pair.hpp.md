---
data:
  _extendedDependsOn: []
  _extendedRequiredBy:
  - icon: ':x:'
    path: alg/lazy/cntsum_add.hpp
    title: alg/lazy/cntsum_add.hpp
  _extendedVerifiedWith:
  - icon: ':x:'
    path: test/yukicoder/1197.test.cpp
    title: test/yukicoder/1197.test.cpp
  - icon: ':x:'
    path: test/yukicoder/235.test.cpp
    title: test/yukicoder/235.test.cpp
  - icon: ':x:'
    path: test/yukicoder/789_2.test.cpp
    title: test/yukicoder/789_2.test.cpp
  _isVerificationFailed: true
  _pathExtension: hpp
  _verificationStatusIcon: ':x:'
  attributes:
    links: []
  bundledCode: "#line 1 \"alg/monoid/add_pair.hpp\"\ntemplate <typename E>\r\nstruct\
    \ Group_Add_Pair {\r\n  using value_type = pair<E, E>;\r\n  using X = value_type;\r\
    \n  static constexpr X op(const X &x, const X &y) {\r\n    return {x.fi + y.fi,\
    \ x.se + y.se};\r\n  }\r\n  static constexpr X inverse(const X &x) { return {-x.fi,\
    \ -x.se}; }\r\n  static constexpr X unit() { return {0, 0}; }\r\n  static constexpr\
    \ bool commute = true;\r\n};\r\n"
  code: "template <typename E>\r\nstruct Group_Add_Pair {\r\n  using value_type =\
    \ pair<E, E>;\r\n  using X = value_type;\r\n  static constexpr X op(const X &x,\
    \ const X &y) {\r\n    return {x.fi + y.fi, x.se + y.se};\r\n  }\r\n  static constexpr\
    \ X inverse(const X &x) { return {-x.fi, -x.se}; }\r\n  static constexpr X unit()\
    \ { return {0, 0}; }\r\n  static constexpr bool commute = true;\r\n};\r\n"
  dependsOn: []
  isVerificationFile: false
  path: alg/monoid/add_pair.hpp
  requiredBy:
  - alg/lazy/cntsum_add.hpp
  timestamp: '2022-11-27 13:57:38+09:00'
  verificationStatus: LIBRARY_ALL_WA
  verifiedWith:
  - test/yukicoder/235.test.cpp
  - test/yukicoder/789_2.test.cpp
  - test/yukicoder/1197.test.cpp
documentation_of: alg/monoid/add_pair.hpp
layout: document
redirect_from:
- /library/alg/monoid/add_pair.hpp
- /library/alg/monoid/add_pair.hpp.html
title: alg/monoid/add_pair.hpp
---
