---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':x:'
    path: test/mytest/add_chmin_chmax.test.cpp
    title: test/mytest/add_chmin_chmax.test.cpp
  - icon: ':x:'
    path: test_atcoder/abc196_E.test.cpp
    title: test_atcoder/abc196_E.test.cpp
  _isVerificationFailed: true
  _pathExtension: hpp
  _verificationStatusIcon: ':x:'
  attributes:
    links: []
  bundledCode: "#line 2 \"alg/monoid/add_chmin_chmax.hpp\"\n\n// max(min(x+a,b),c)\
    \ \u3068\u8868\u305B\u308B\u95A2\u6570\u306E\u5408\u6210\ntemplate <typename E>\n\
    struct Monoid_Add_Chmin_Chmax {\n  using value_type = tuple<E, E, E>;\n  using\
    \ X = value_type;\n\n  static X op(X x, X y) {\n    auto [a, b, c] = x;\n    auto\
    \ [d, e, f] = y;\n    a = a + d;\n    b = (b == infty<E> ? b : b + d);\n    c\
    \ = (c == -infty<E> ? c : c + d);\n    b = min(b, e);\n    c = max(min(c, e),\
    \ f);\n    return {a, b, c};\n  }\n\n  static E eval(X f, E x) {\n    auto [a,\
    \ b, c] = f;\n    return max(min(x + a, b), c);\n  }\n\n  static X add(E a) {\
    \ return {a, infty<E>, -infty<E>}; }\n  static X chmin(E b) { return {0, b, -infty<E>};\
    \ }\n  static X chmax(E c) { return {0, infty<E>, c}; }\n\n  static constexpr\
    \ X unit() { return {0, infty<E>, -infty<E>}; }\n  static constexpr bool commute\
    \ = 0;\n};\n"
  code: "#pragma once\n\n// max(min(x+a,b),c) \u3068\u8868\u305B\u308B\u95A2\u6570\
    \u306E\u5408\u6210\ntemplate <typename E>\nstruct Monoid_Add_Chmin_Chmax {\n \
    \ using value_type = tuple<E, E, E>;\n  using X = value_type;\n\n  static X op(X\
    \ x, X y) {\n    auto [a, b, c] = x;\n    auto [d, e, f] = y;\n    a = a + d;\n\
    \    b = (b == infty<E> ? b : b + d);\n    c = (c == -infty<E> ? c : c + d);\n\
    \    b = min(b, e);\n    c = max(min(c, e), f);\n    return {a, b, c};\n  }\n\n\
    \  static E eval(X f, E x) {\n    auto [a, b, c] = f;\n    return max(min(x +\
    \ a, b), c);\n  }\n\n  static X add(E a) { return {a, infty<E>, -infty<E>}; }\n\
    \  static X chmin(E b) { return {0, b, -infty<E>}; }\n  static X chmax(E c) {\
    \ return {0, infty<E>, c}; }\n\n  static constexpr X unit() { return {0, infty<E>,\
    \ -infty<E>}; }\n  static constexpr bool commute = 0;\n};"
  dependsOn: []
  isVerificationFile: false
  path: alg/monoid/add_chmin_chmax.hpp
  requiredBy: []
  timestamp: '2023-02-01 23:31:55+09:00'
  verificationStatus: LIBRARY_ALL_WA
  verifiedWith:
  - test_atcoder/abc196_E.test.cpp
  - test/mytest/add_chmin_chmax.test.cpp
documentation_of: alg/monoid/add_chmin_chmax.hpp
layout: document
redirect_from:
- /library/alg/monoid/add_chmin_chmax.hpp
- /library/alg/monoid/add_chmin_chmax.hpp.html
title: alg/monoid/add_chmin_chmax.hpp
---
