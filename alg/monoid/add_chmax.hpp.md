---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':x:'
    path: test/yukicoder/1524.test.cpp
    title: test/yukicoder/1524.test.cpp
  _isVerificationFailed: true
  _pathExtension: hpp
  _verificationStatusIcon: ':x:'
  attributes:
    links: []
  bundledCode: "#line 2 \"alg/monoid/add_chmax.hpp\"\n\r\n// max(x+a,b) \u3068\u8868\
    \u305B\u308B\u95A2\u6570\u306E\u5408\u6210\r\ntemplate <typename E>\r\nstruct\
    \ Monoid_Add_Chmax {\r\n  using value_type = pair<E, E>;\r\n  using X = value_type;\r\
    \n  static X op(X x, X y) {\r\n    auto [a, c] = x;\r\n    auto [d, f] = y;\r\n\
    \    a = a + d;\r\n    c = (c == -infty<E> ? c : c + d);\r\n    c = max(c, f);\r\
    \n    return {a, c};\r\n  }\r\n\r\n  static E eval(X f, E x) { return max(x +\
    \ f.fi, f.se); }\r\n  static X add(E a) { return {a, -infty<E>}; }\r\n  static\
    \ X chmax(E c) { return {0, c}; }\r\n\r\n  static constexpr X unit() { return\
    \ {0, -infty<E>}; }\r\n  static constexpr bool commute = 0;\r\n};\n"
  code: "#pragma once\r\n\r\n// max(x+a,b) \u3068\u8868\u305B\u308B\u95A2\u6570\u306E\
    \u5408\u6210\r\ntemplate <typename E>\r\nstruct Monoid_Add_Chmax {\r\n  using\
    \ value_type = pair<E, E>;\r\n  using X = value_type;\r\n  static X op(X x, X\
    \ y) {\r\n    auto [a, c] = x;\r\n    auto [d, f] = y;\r\n    a = a + d;\r\n \
    \   c = (c == -infty<E> ? c : c + d);\r\n    c = max(c, f);\r\n    return {a,\
    \ c};\r\n  }\r\n\r\n  static E eval(X f, E x) { return max(x + f.fi, f.se); }\r\
    \n  static X add(E a) { return {a, -infty<E>}; }\r\n  static X chmax(E c) { return\
    \ {0, c}; }\r\n\r\n  static constexpr X unit() { return {0, -infty<E>}; }\r\n\
    \  static constexpr bool commute = 0;\r\n};"
  dependsOn: []
  isVerificationFile: false
  path: alg/monoid/add_chmax.hpp
  requiredBy: []
  timestamp: '2023-02-01 23:31:55+09:00'
  verificationStatus: LIBRARY_ALL_WA
  verifiedWith:
  - test/yukicoder/1524.test.cpp
documentation_of: alg/monoid/add_chmax.hpp
layout: document
redirect_from:
- /library/alg/monoid/add_chmax.hpp
- /library/alg/monoid/add_chmax.hpp.html
title: alg/monoid/add_chmax.hpp
---
