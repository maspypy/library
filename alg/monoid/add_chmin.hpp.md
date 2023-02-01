---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':x:'
    path: test/mytest/add_chmin.test.cpp
    title: test/mytest/add_chmin.test.cpp
  _isVerificationFailed: true
  _pathExtension: hpp
  _verificationStatusIcon: ':x:'
  attributes:
    links: []
  bundledCode: "#line 2 \"alg/monoid/add_chmin.hpp\"\n\n// min(x+a,b) \u3068\u8868\
    \u305B\u308B\u95A2\u6570\u306E\u5408\u6210\ntemplate <typename E>\nstruct Monoid_Add_Chmin\
    \ {\n  using value_type = pair<E, E>;\n  using X = value_type;\n\n  static X op(X\
    \ x, X y) {\n    auto [a, b] = x;\n    auto [d, e] = y;\n    a = a + d;\n    b\
    \ = (b == INF<E> ? b : b + d);\n    b = min(b, e);\n    return {a, b};\n  }\n\n\
    \  static E eval(X f, E x) { return min(x + f.fi, f.se); }\n\n  static X add(E\
    \ a) { return {a, INF<E>}; }\n  static X chmin(E b) { return {0, b}; }\n\n  static\
    \ constexpr X unit() { return {0, INF<E>}; }\n  static constexpr bool commute\
    \ = 0;\n};\n"
  code: "#pragma once\n\n// min(x+a,b) \u3068\u8868\u305B\u308B\u95A2\u6570\u306E\u5408\
    \u6210\ntemplate <typename E>\nstruct Monoid_Add_Chmin {\n  using value_type =\
    \ pair<E, E>;\n  using X = value_type;\n\n  static X op(X x, X y) {\n    auto\
    \ [a, b] = x;\n    auto [d, e] = y;\n    a = a + d;\n    b = (b == INF<E> ? b\
    \ : b + d);\n    b = min(b, e);\n    return {a, b};\n  }\n\n  static E eval(X\
    \ f, E x) { return min(x + f.fi, f.se); }\n\n  static X add(E a) { return {a,\
    \ INF<E>}; }\n  static X chmin(E b) { return {0, b}; }\n\n  static constexpr X\
    \ unit() { return {0, INF<E>}; }\n  static constexpr bool commute = 0;\n};"
  dependsOn: []
  isVerificationFile: false
  path: alg/monoid/add_chmin.hpp
  requiredBy: []
  timestamp: '2023-02-01 22:47:27+09:00'
  verificationStatus: LIBRARY_ALL_WA
  verifiedWith:
  - test/mytest/add_chmin.test.cpp
documentation_of: alg/monoid/add_chmin.hpp
layout: document
redirect_from:
- /library/alg/monoid/add_chmin.hpp
- /library/alg/monoid/add_chmin.hpp.html
title: alg/monoid/add_chmin.hpp
---
