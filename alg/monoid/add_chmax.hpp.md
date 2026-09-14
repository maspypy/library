---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/3_yukicoder/1524.test.cpp
    title: test/3_yukicoder/1524.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 1 \"alg/monoid/add_chmax.hpp\"\n\n// max(x+a,b) \u3068\u8868\
    \u305B\u308B\u95A2\u6570\u306E\u5408\u6210\ntemplate <typename E>\nstruct Monoid_Add_Chmax\
    \ {\n  using value_type = pair<E, E>;\n  using X = value_type;\n  static X op(X\
    \ x, X y) {\n    auto [a, c] = x;\n    auto [d, f] = y;\n    a = a + d;\n    c\
    \ = (c == -infty<E> ? c : c + d);\n    c = max(c, f);\n    return {a, c};\n  }\n\
    \n  static E eval(X f, E x) { return max(x + f.fi, f.se); }\n  static X add(E\
    \ a) { return {a, -infty<E>}; }\n  static X chmax(E c) { return {0, c}; }\n\n\
    \  static constexpr X id() { return {0, -infty<E>}; }\n  static constexpr bool\
    \ commute = 0;\n};\n"
  code: "\n// max(x+a,b) \u3068\u8868\u305B\u308B\u95A2\u6570\u306E\u5408\u6210\n\
    template <typename E>\nstruct Monoid_Add_Chmax {\n  using value_type = pair<E,\
    \ E>;\n  using X = value_type;\n  static X op(X x, X y) {\n    auto [a, c] = x;\n\
    \    auto [d, f] = y;\n    a = a + d;\n    c = (c == -infty<E> ? c : c + d);\n\
    \    c = max(c, f);\n    return {a, c};\n  }\n\n  static E eval(X f, E x) { return\
    \ max(x + f.fi, f.se); }\n  static X add(E a) { return {a, -infty<E>}; }\n  static\
    \ X chmax(E c) { return {0, c}; }\n\n  static constexpr X id() { return {0, -infty<E>};\
    \ }\n  static constexpr bool commute = 0;\n};"
  dependsOn: []
  isVerificationFile: false
  path: alg/monoid/add_chmax.hpp
  requiredBy: []
  timestamp: '2026-08-30 21:09:36+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/3_yukicoder/1524.test.cpp
documentation_of: alg/monoid/add_chmax.hpp
layout: document
redirect_from:
- /library/alg/monoid/add_chmax.hpp
- /library/alg/monoid/add_chmax.hpp.html
title: alg/monoid/add_chmax.hpp
---
