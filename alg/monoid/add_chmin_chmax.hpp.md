---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/atcoder/abc196_E.test.cpp
    title: test/atcoder/abc196_E.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/mytest/add_chmin_chmax.test.cpp
    title: test/mytest/add_chmin_chmax.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 2 \"alg/monoid/add_chmin_chmax.hpp\"\n\n// max(min(x+a,b),c)\
    \ \u3068\u8868\u305B\u308B\u95A2\u6570\u306E\u5408\u6210\ntemplate <typename E>\n\
    struct Monoid_Add_Chmin_Chmax {\n  using value_type = tuple<E, E, E>;\n  using\
    \ X = value_type;\n  static constexpr E L_INF = numeric_limits<E>::lowest();\n\
    \  static constexpr E R_INF = numeric_limits<E>::max();\n\n  static X op(X x,\
    \ X y) {\n    auto [a, b, c] = x;\n    auto [d, e, f] = y;\n    a = a + d;\n \
    \   b = (b == R_INF ? b : b + d);\n    c = (c == L_INF ? c : c + d);\n    b =\
    \ min(b, e);\n    c = max(min(c, e), f);\n    return {a, b, c};\n  }\n\n  static\
    \ E eval(X f, E x) {\n    auto [a, b, c] = f;\n    return max(min(x + a, b), c);\n\
    \  }\n\n  static X add(E a) { return {a, R_INF, L_INF}; }\n  static X chmin(E\
    \ b) { return {0, b, L_INF}; }\n  static X chmax(E c) { return {0, R_INF, c};\
    \ }\n\n  static constexpr X unit() { return {0, R_INF, L_INF}; }\n  static constexpr\
    \ bool commute = 0;\n};\n"
  code: "#pragma once\n\n// max(min(x+a,b),c) \u3068\u8868\u305B\u308B\u95A2\u6570\
    \u306E\u5408\u6210\ntemplate <typename E>\nstruct Monoid_Add_Chmin_Chmax {\n \
    \ using value_type = tuple<E, E, E>;\n  using X = value_type;\n  static constexpr\
    \ E L_INF = numeric_limits<E>::lowest();\n  static constexpr E R_INF = numeric_limits<E>::max();\n\
    \n  static X op(X x, X y) {\n    auto [a, b, c] = x;\n    auto [d, e, f] = y;\n\
    \    a = a + d;\n    b = (b == R_INF ? b : b + d);\n    c = (c == L_INF ? c :\
    \ c + d);\n    b = min(b, e);\n    c = max(min(c, e), f);\n    return {a, b, c};\n\
    \  }\n\n  static E eval(X f, E x) {\n    auto [a, b, c] = f;\n    return max(min(x\
    \ + a, b), c);\n  }\n\n  static X add(E a) { return {a, R_INF, L_INF}; }\n  static\
    \ X chmin(E b) { return {0, b, L_INF}; }\n  static X chmax(E c) { return {0, R_INF,\
    \ c}; }\n\n  static constexpr X unit() { return {0, R_INF, L_INF}; }\n  static\
    \ constexpr bool commute = 0;\n};"
  dependsOn: []
  isVerificationFile: false
  path: alg/monoid/add_chmin_chmax.hpp
  requiredBy: []
  timestamp: '2022-12-01 09:04:06+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/mytest/add_chmin_chmax.test.cpp
  - test/atcoder/abc196_E.test.cpp
documentation_of: alg/monoid/add_chmin_chmax.hpp
layout: document
redirect_from:
- /library/alg/monoid/add_chmin_chmax.hpp
- /library/alg/monoid/add_chmin_chmax.hpp.html
title: alg/monoid/add_chmin_chmax.hpp
---
