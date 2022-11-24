---
data:
  _extendedDependsOn:
  - icon: ':question:'
    path: alg/group/add.hpp
    title: alg/group/add.hpp
  - icon: ':question:'
    path: alg/monoid/min.hpp
    title: alg/monoid/min.hpp
  _extendedRequiredBy:
  - icon: ':heavy_check_mark:'
    path: ds/common_interval_decomposition.hpp
    title: ds/common_interval_decomposition.hpp
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/aoj/DSL_2_H.test.cpp
    title: test/aoj/DSL_2_H.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/library_checker/graph/common_interval_decomposition.test.cpp
    title: test/library_checker/graph/common_interval_decomposition.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/yukicoder/1234.test.cpp
    title: test/yukicoder/1234.test.cpp
  - icon: ':x:'
    path: test/yukicoder/1270.test.cpp
    title: test/yukicoder/1270.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/yukicoder/1720.test.cpp
    title: test/yukicoder/1720.test.cpp
  _isVerificationFailed: true
  _pathExtension: hpp
  _verificationStatusIcon: ':question:'
  attributes:
    links: []
  bundledCode: "#line 2 \"alg/group/add.hpp\"\n\r\ntemplate <typename E>\r\nstruct\
    \ Group_Add {\r\n  using X = E;\r\n  using value_type = X;\r\n  static constexpr\
    \ X op(const X &x, const X &y) noexcept { return x + y; }\r\n  static constexpr\
    \ X inverse(const X &x) noexcept { return -x; }\r\n  static constexpr X power(const\
    \ X &x, ll n) noexcept { return X(n) * x; }\r\n  static constexpr X unit() { return\
    \ X(0); }\r\n  static constexpr bool commute = true;\r\n};\r\n#line 2 \"alg/monoid/min.hpp\"\
    \ntemplate <class X>\r\nstruct Monoid_Min {\r\n  using value_type = X;\r\n  static\
    \ constexpr X op(const X &x, const X &y) noexcept { return min(x, y); }\r\n  static\
    \ constexpr X unit() { return numeric_limits<X>::max(); }\r\n  static constexpr\
    \ bool commute = true;\r\n};\r\n#line 3 \"alg/lazy/min_add.hpp\"\n\r\ntemplate\
    \ <typename E>\r\nstruct Lazy_Min_Add {\r\n  using MX = Monoid_Min<E>;\r\n  using\
    \ MA = Group_Add<E>;\r\n  using X_structure = MX;\r\n  using A_structure = MA;\r\
    \n  using X = typename MX::value_type;\r\n  using A = typename MA::value_type;\r\
    \n  static constexpr X act(const X &x, const A &a) {\r\n    if (x == numeric_limits<E>::max())\
    \ return x;\r\n    return x + a;\r\n  }\r\n};\n"
  code: "#include \"alg/group/add.hpp\"\r\n#include \"alg/monoid/min.hpp\"\r\n\r\n\
    template <typename E>\r\nstruct Lazy_Min_Add {\r\n  using MX = Monoid_Min<E>;\r\
    \n  using MA = Group_Add<E>;\r\n  using X_structure = MX;\r\n  using A_structure\
    \ = MA;\r\n  using X = typename MX::value_type;\r\n  using A = typename MA::value_type;\r\
    \n  static constexpr X act(const X &x, const A &a) {\r\n    if (x == numeric_limits<E>::max())\
    \ return x;\r\n    return x + a;\r\n  }\r\n};"
  dependsOn:
  - alg/group/add.hpp
  - alg/monoid/min.hpp
  isVerificationFile: false
  path: alg/lazy/min_add.hpp
  requiredBy:
  - ds/common_interval_decomposition.hpp
  timestamp: '2022-10-21 17:59:25+09:00'
  verificationStatus: LIBRARY_SOME_WA
  verifiedWith:
  - test/library_checker/graph/common_interval_decomposition.test.cpp
  - test/aoj/DSL_2_H.test.cpp
  - test/yukicoder/1720.test.cpp
  - test/yukicoder/1234.test.cpp
  - test/yukicoder/1270.test.cpp
documentation_of: alg/lazy/min_add.hpp
layout: document
redirect_from:
- /library/alg/lazy/min_add.hpp
- /library/alg/lazy/min_add.hpp.html
title: alg/lazy/min_add.hpp
---
