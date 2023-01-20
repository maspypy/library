---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/mytest/add_chmin.test.cpp
    title: test/mytest/add_chmin.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 2 \"alg/monoid/add_chmin.hpp\"\n\n// min(x+a,b) \u3068\u8868\
    \u305B\u308B\u95A2\u6570\u306E\u5408\u6210\ntemplate <typename E>\nstruct Monoid_Add_Chmin\
    \ {\n  using value_type = pair<E, E>;\n  using X = value_type;\n  static constexpr\
    \ E R_INF = numeric_limits<E>::max();\n\n  static X op(X x, X y) {\n    auto [a,\
    \ b] = x;\n    auto [d, e] = y;\n    a = a + d;\n    b = (b == R_INF ? b : b +\
    \ d);\n    b = min(b, e);\n    return {a, b};\n  }\n\n  static E eval(X f, E x)\
    \ { return min(x + f.fi, f.se); }\n\n  static X add(E a) { return {a, R_INF};\
    \ }\n  static X chmin(E b) { return {0, b}; }\n\n  static constexpr X unit() {\
    \ return {0, R_INF}; }\n  static constexpr bool commute = 0;\n};\n"
  code: "#pragma once\n\n// min(x+a,b) \u3068\u8868\u305B\u308B\u95A2\u6570\u306E\u5408\
    \u6210\ntemplate <typename E>\nstruct Monoid_Add_Chmin {\n  using value_type =\
    \ pair<E, E>;\n  using X = value_type;\n  static constexpr E R_INF = numeric_limits<E>::max();\n\
    \n  static X op(X x, X y) {\n    auto [a, b] = x;\n    auto [d, e] = y;\n    a\
    \ = a + d;\n    b = (b == R_INF ? b : b + d);\n    b = min(b, e);\n    return\
    \ {a, b};\n  }\n\n  static E eval(X f, E x) { return min(x + f.fi, f.se); }\n\n\
    \  static X add(E a) { return {a, R_INF}; }\n  static X chmin(E b) { return {0,\
    \ b}; }\n\n  static constexpr X unit() { return {0, R_INF}; }\n  static constexpr\
    \ bool commute = 0;\n};"
  dependsOn: []
  isVerificationFile: false
  path: alg/monoid/add_chmin.hpp
  requiredBy: []
  timestamp: '2022-12-01 09:04:06+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/mytest/add_chmin.test.cpp
documentation_of: alg/monoid/add_chmin.hpp
layout: document
redirect_from:
- /library/alg/monoid/add_chmin.hpp
- /library/alg/monoid/add_chmin.hpp.html
title: alg/monoid/add_chmin.hpp
---
