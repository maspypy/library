---
data:
  _extendedDependsOn: []
  _extendedRequiredBy:
  - icon: ':x:'
    path: alg/acted_monoid/max_add.hpp
    title: alg/acted_monoid/max_add.hpp
  - icon: ':warning:'
    path: alg/acted_monoid/max_assign.hpp
    title: alg/acted_monoid/max_assign.hpp
  - icon: ':warning:'
    path: alg/acted_monoid/max_max.hpp
    title: alg/acted_monoid/max_max.hpp
  - icon: ':warning:'
    path: alg/acted_monoid/max_min.hpp
    title: alg/acted_monoid/max_min.hpp
  - icon: ':warning:'
    path: alg/acted_monoid/min_max.hpp
    title: alg/acted_monoid/min_max.hpp
  _extendedVerifiedWith:
  - icon: ':x:'
    path: test/yukicoder/1117.test.cpp
    title: test/yukicoder/1117.test.cpp
  - icon: ':x:'
    path: test/yukicoder/1790.test.cpp
    title: test/yukicoder/1790.test.cpp
  - icon: ':x:'
    path: test/yukicoder/2026.test.cpp
    title: test/yukicoder/2026.test.cpp
  - icon: ':x:'
    path: test/yukicoder/686.test.cpp
    title: test/yukicoder/686.test.cpp
  _isVerificationFailed: true
  _pathExtension: hpp
  _verificationStatusIcon: ':x:'
  attributes:
    links: []
  bundledCode: "#line 2 \"alg/monoid/max.hpp\"\n\r\ntemplate <class X>\r\nstruct Monoid_Max\
    \ {\r\n  using value_type = X;\r\n  static constexpr X op(const X &x, const X\
    \ &y) noexcept { return max(x, y); }\r\n  static constexpr X unit() { return numeric_limits<X>::lowest();\
    \ }\r\n  static constexpr bool commute = true;\r\n};\r\n"
  code: "#pragma once\r\n\r\ntemplate <class X>\r\nstruct Monoid_Max {\r\n  using\
    \ value_type = X;\r\n  static constexpr X op(const X &x, const X &y) noexcept\
    \ { return max(x, y); }\r\n  static constexpr X unit() { return numeric_limits<X>::lowest();\
    \ }\r\n  static constexpr bool commute = true;\r\n};\r\n"
  dependsOn: []
  isVerificationFile: false
  path: alg/monoid/max.hpp
  requiredBy:
  - alg/acted_monoid/max_assign.hpp
  - alg/acted_monoid/max_max.hpp
  - alg/acted_monoid/max_add.hpp
  - alg/acted_monoid/min_max.hpp
  - alg/acted_monoid/max_min.hpp
  timestamp: '2022-12-01 09:04:06+09:00'
  verificationStatus: LIBRARY_ALL_WA
  verifiedWith:
  - test/yukicoder/686.test.cpp
  - test/yukicoder/2026.test.cpp
  - test/yukicoder/1790.test.cpp
  - test/yukicoder/1117.test.cpp
documentation_of: alg/monoid/max.hpp
layout: document
redirect_from:
- /library/alg/monoid/max.hpp
- /library/alg/monoid/max.hpp.html
title: alg/monoid/max.hpp
---
