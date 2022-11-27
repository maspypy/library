---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: alg/monoid/max.hpp
    title: alg/monoid/max.hpp
  - icon: ':heavy_check_mark:'
    path: alg/monoid/min.hpp
    title: alg/monoid/min.hpp
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/mytest/min_max.test.cpp
    title: test/mytest/min_max.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 2 \"alg/monoid/max.hpp\"\ntemplate <class X>\r\nstruct Monoid_Max\
    \ {\r\n  using value_type = X;\r\n  static constexpr X op(const X &x, const X\
    \ &y) noexcept { return max(x, y); }\r\n  static constexpr X unit() { return numeric_limits<X>::lowest();\
    \ }\r\n  static constexpr bool commute = true;\r\n};\r\n#line 2 \"alg/monoid/min.hpp\"\
    \ntemplate <class X>\r\nstruct Monoid_Min {\r\n  using value_type = X;\r\n  static\
    \ constexpr X op(const X &x, const X &y) noexcept { return min(x, y); }\r\n  static\
    \ constexpr X unit() { return numeric_limits<X>::max(); }\r\n  static constexpr\
    \ bool commute = true;\r\n};\r\n#line 3 \"alg/lazy/min_max.hpp\"\n\ntemplate <typename\
    \ E>\nstruct Lazy_Min_Max {\n  using MX = Monoid_Min<E>;\n  using MA = Monoid_Max<E>;\n\
    \  using X_structure = MX;\n  using A_structure = MA;\n  using X = typename MX::value_type;\n\
    \  using A = typename MA::value_type;\n  static constexpr X act(const X &x, const\
    \ A &a) { return max(x, a); }\n};\n"
  code: "#include \"alg/monoid/max.hpp\"\n#include \"alg/monoid/min.hpp\"\n\ntemplate\
    \ <typename E>\nstruct Lazy_Min_Max {\n  using MX = Monoid_Min<E>;\n  using MA\
    \ = Monoid_Max<E>;\n  using X_structure = MX;\n  using A_structure = MA;\n  using\
    \ X = typename MX::value_type;\n  using A = typename MA::value_type;\n  static\
    \ constexpr X act(const X &x, const A &a) { return max(x, a); }\n};\n"
  dependsOn:
  - alg/monoid/max.hpp
  - alg/monoid/min.hpp
  isVerificationFile: false
  path: alg/lazy/min_max.hpp
  requiredBy: []
  timestamp: '2022-11-27 22:28:55+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/mytest/min_max.test.cpp
documentation_of: alg/lazy/min_max.hpp
layout: document
redirect_from:
- /library/alg/lazy/min_max.hpp
- /library/alg/lazy/min_max.hpp.html
title: alg/lazy/min_max.hpp
---
