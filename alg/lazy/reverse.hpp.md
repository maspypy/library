---
data:
  _extendedDependsOn:
  - icon: ':question:'
    path: alg/monoid/reverse_monoid.hpp
    title: alg/monoid/reverse_monoid.hpp
  _extendedRequiredBy:
  - icon: ':question:'
    path: graph/ds/lazytreemonoid.hpp
    title: graph/ds/lazytreemonoid.hpp
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/aoj/GRL_5_E.test.cpp
    title: test/aoj/GRL_5_E.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/yukicoder/1197.test.cpp
    title: test/yukicoder/1197.test.cpp
  - icon: ':x:'
    path: test/yukicoder/1790.test.cpp
    title: test/yukicoder/1790.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/yukicoder/235.test.cpp
    title: test/yukicoder/235.test.cpp
  _isVerificationFailed: true
  _pathExtension: hpp
  _verificationStatusIcon: ':question:'
  attributes:
    links: []
  bundledCode: "#line 2 \"alg/monoid/reverse_monoid.hpp\"\ntemplate <class Monoid>\r\
    \nstruct Monoid_Reverse {\r\n  using value_type = typename Monoid::value_type;\r\
    \n  using X = value_type;\r\n  static constexpr X op(const X &x, const X &y) {\
    \ return Monoid::op(y, x); }\r\n  static constexpr X unit() { return Monoid::unit();\
    \ }\r\n  static const bool commute = Monoid::commute;\r\n};\r\n#line 2 \"alg/lazy/reverse.hpp\"\
    \n\r\ntemplate <typename Lazy>\r\nstruct Lazy_Reverse {\r\n  using MX = Monoid_Reverse<typename\
    \ Lazy::X_structure>;\r\n  using MA = typename Lazy::A_structure;\r\n  using X_structure\
    \ = MX;\r\n  using A_structure = MA;\r\n  using X = typename MX::value_type;\r\
    \n  using A = typename MA::value_type;\r\n  static constexpr X act(const X &x,\
    \ const A &a) { return Lazy::act(x, a); }\r\n};\r\n"
  code: "#include \"alg/monoid/reverse_monoid.hpp\"\r\n\r\ntemplate <typename Lazy>\r\
    \nstruct Lazy_Reverse {\r\n  using MX = Monoid_Reverse<typename Lazy::X_structure>;\r\
    \n  using MA = typename Lazy::A_structure;\r\n  using X_structure = MX;\r\n  using\
    \ A_structure = MA;\r\n  using X = typename MX::value_type;\r\n  using A = typename\
    \ MA::value_type;\r\n  static constexpr X act(const X &x, const A &a) { return\
    \ Lazy::act(x, a); }\r\n};\r\n"
  dependsOn:
  - alg/monoid/reverse_monoid.hpp
  isVerificationFile: false
  path: alg/lazy/reverse.hpp
  requiredBy:
  - graph/ds/lazytreemonoid.hpp
  timestamp: '2022-11-27 13:56:21+09:00'
  verificationStatus: LIBRARY_SOME_WA
  verifiedWith:
  - test/yukicoder/235.test.cpp
  - test/yukicoder/1790.test.cpp
  - test/yukicoder/1197.test.cpp
  - test/aoj/GRL_5_E.test.cpp
documentation_of: alg/lazy/reverse.hpp
layout: document
redirect_from:
- /library/alg/lazy/reverse.hpp
- /library/alg/lazy/reverse.hpp.html
title: alg/lazy/reverse.hpp
---
