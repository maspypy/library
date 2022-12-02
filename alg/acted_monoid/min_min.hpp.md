---
data:
  _extendedDependsOn:
  - icon: ':question:'
    path: alg/monoid/min.hpp
    title: alg/monoid/min.hpp
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':x:'
    path: test/mytest/min_min.test.cpp
    title: test/mytest/min_min.test.cpp
  _isVerificationFailed: true
  _pathExtension: hpp
  _verificationStatusIcon: ':x:'
  attributes:
    links: []
  bundledCode: "#line 2 \"alg/monoid/min.hpp\"\n\r\ntemplate <class X>\r\nstruct Monoid_Min\
    \ {\r\n  using value_type = X;\r\n  static constexpr X op(const X &x, const X\
    \ &y) noexcept { return min(x, y); }\r\n  static constexpr X unit() { return numeric_limits<X>::max();\
    \ }\r\n  static constexpr bool commute = true;\r\n};\r\n#line 2 \"alg/acted_monoid/min_min.hpp\"\
    \n\r\ntemplate <typename E>\r\nstruct ActedMonoid_Min_Min {\r\n  using Monoid_X\
    \ = Monoid_Min<E>;\r\n  using Monoid_A = Monoid_Min<E>;\r\n  using X = typename\
    \ Monoid_X::value_type;\r\n  using A = typename Monoid_A::value_type;\r\n  static\
    \ constexpr X act(const X &x, const A &a) { return min(x, a); }\r\n};\r\n"
  code: "#include \"alg/monoid/min.hpp\"\r\n\r\ntemplate <typename E>\r\nstruct ActedMonoid_Min_Min\
    \ {\r\n  using Monoid_X = Monoid_Min<E>;\r\n  using Monoid_A = Monoid_Min<E>;\r\
    \n  using X = typename Monoid_X::value_type;\r\n  using A = typename Monoid_A::value_type;\r\
    \n  static constexpr X act(const X &x, const A &a) { return min(x, a); }\r\n};\r\
    \n"
  dependsOn:
  - alg/monoid/min.hpp
  isVerificationFile: false
  path: alg/acted_monoid/min_min.hpp
  requiredBy: []
  timestamp: '2022-12-01 09:04:06+09:00'
  verificationStatus: LIBRARY_ALL_WA
  verifiedWith:
  - test/mytest/min_min.test.cpp
documentation_of: alg/acted_monoid/min_min.hpp
layout: document
redirect_from:
- /library/alg/acted_monoid/min_min.hpp
- /library/alg/acted_monoid/min_min.hpp.html
title: alg/acted_monoid/min_min.hpp
---
