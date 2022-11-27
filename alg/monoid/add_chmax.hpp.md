---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/yukicoder/1524.test.cpp
    title: test/yukicoder/1524.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 1 \"alg/monoid/add_chmax.hpp\"\n// max(x+a,b) \u3068\u8868\u305B\
    \u308B\u95A2\u6570\u306E\u5408\u6210\r\ntemplate <typename E>\r\nstruct Monoid_Add_Chmax\
    \ {\r\n  using value_type = pair<E, E>;\r\n  using X = value_type;\r\n  static\
    \ constexpr E L_INF = numeric_limits<E>::lowest();\r\n\r\n  static X op(X x, X\
    \ y) {\r\n    auto [a, c] = x;\r\n    auto [d, f] = y;\r\n    a = a + d;\r\n \
    \   c = (c == L_INF ? c : c + d);\r\n    c = max(c, f);\r\n    return {a, c};\r\
    \n  }\r\n\r\n  static E eval(X f, E x) { return max(x + f.fi, f.se); }\r\n  static\
    \ X add(E a) { return {a, L_INF}; }\r\n  static X chmax(E c) { return {0, c};\
    \ }\r\n\r\n  static constexpr X unit() { return {0, L_INF}; }\r\n  static constexpr\
    \ bool commute = 0;\r\n};\n"
  code: "// max(x+a,b) \u3068\u8868\u305B\u308B\u95A2\u6570\u306E\u5408\u6210\r\n\
    template <typename E>\r\nstruct Monoid_Add_Chmax {\r\n  using value_type = pair<E,\
    \ E>;\r\n  using X = value_type;\r\n  static constexpr E L_INF = numeric_limits<E>::lowest();\r\
    \n\r\n  static X op(X x, X y) {\r\n    auto [a, c] = x;\r\n    auto [d, f] = y;\r\
    \n    a = a + d;\r\n    c = (c == L_INF ? c : c + d);\r\n    c = max(c, f);\r\n\
    \    return {a, c};\r\n  }\r\n\r\n  static E eval(X f, E x) { return max(x + f.fi,\
    \ f.se); }\r\n  static X add(E a) { return {a, L_INF}; }\r\n  static X chmax(E\
    \ c) { return {0, c}; }\r\n\r\n  static constexpr X unit() { return {0, L_INF};\
    \ }\r\n  static constexpr bool commute = 0;\r\n};"
  dependsOn: []
  isVerificationFile: false
  path: alg/monoid/add_chmax.hpp
  requiredBy: []
  timestamp: '2022-11-27 23:55:36+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/yukicoder/1524.test.cpp
documentation_of: alg/monoid/add_chmax.hpp
layout: document
redirect_from:
- /library/alg/monoid/add_chmax.hpp
- /library/alg/monoid/add_chmax.hpp.html
title: alg/monoid/add_chmax.hpp
---
