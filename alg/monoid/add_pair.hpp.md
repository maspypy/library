---
data:
  _extendedDependsOn: []
  _extendedRequiredBy:
  - icon: ':x:'
    path: alg/acted_monoid/cntsum_add.hpp
    title: alg/acted_monoid/cntsum_add.hpp
  - icon: ':heavy_check_mark:'
    path: alg/acted_monoid/cntsum_affine.hpp
    title: alg/acted_monoid/cntsum_affine.hpp
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/mytest/cf702_F.test.cpp
    title: test/mytest/cf702_F.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/mytest/cf702_F_splay.test.cpp
    title: test/mytest/cf702_F_splay.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/yukicoder/1919.test.cpp
    title: test/yukicoder/1919.test.cpp
  - icon: ':x:'
    path: test/yukicoder/235.test.cpp
    title: test/yukicoder/235.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/yukicoder/255.test.cpp
    title: test/yukicoder/255.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/yukicoder/749.test.cpp
    title: test/yukicoder/749.test.cpp
  _isVerificationFailed: true
  _pathExtension: hpp
  _verificationStatusIcon: ':question:'
  attributes:
    links: []
  bundledCode: "#line 2 \"alg/monoid/add_pair.hpp\"\n\r\ntemplate <typename E>\r\n\
    struct Monoid_Add_Pair {\r\n  using value_type = pair<E, E>;\r\n  using X = value_type;\r\
    \n  static constexpr X op(const X &x, const X &y) {\r\n    return {x.fi + y.fi,\
    \ x.se + y.se};\r\n  }\r\n  static constexpr X inverse(const X &x) { return {-x.fi,\
    \ -x.se}; }\r\n  static constexpr X unit() { return {0, 0}; }\r\n  static constexpr\
    \ bool commute = true;\r\n};\r\n"
  code: "#pragma once\r\n\r\ntemplate <typename E>\r\nstruct Monoid_Add_Pair {\r\n\
    \  using value_type = pair<E, E>;\r\n  using X = value_type;\r\n  static constexpr\
    \ X op(const X &x, const X &y) {\r\n    return {x.fi + y.fi, x.se + y.se};\r\n\
    \  }\r\n  static constexpr X inverse(const X &x) { return {-x.fi, -x.se}; }\r\n\
    \  static constexpr X unit() { return {0, 0}; }\r\n  static constexpr bool commute\
    \ = true;\r\n};\r\n"
  dependsOn: []
  isVerificationFile: false
  path: alg/monoid/add_pair.hpp
  requiredBy:
  - alg/acted_monoid/cntsum_add.hpp
  - alg/acted_monoid/cntsum_affine.hpp
  timestamp: '2022-12-01 09:04:06+09:00'
  verificationStatus: LIBRARY_SOME_WA
  verifiedWith:
  - test/mytest/cf702_F_splay.test.cpp
  - test/mytest/cf702_F.test.cpp
  - test/yukicoder/1919.test.cpp
  - test/yukicoder/255.test.cpp
  - test/yukicoder/235.test.cpp
  - test/yukicoder/749.test.cpp
documentation_of: alg/monoid/add_pair.hpp
layout: document
redirect_from:
- /library/alg/monoid/add_pair.hpp
- /library/alg/monoid/add_pair.hpp.html
title: alg/monoid/add_pair.hpp
---
