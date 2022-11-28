---
data:
  _extendedDependsOn:
  - icon: ':warning:'
    path: alg/monoid/monoid_reverse.hpp
    title: alg/monoid/monoid_reverse.hpp
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':warning:'
  attributes:
    links: []
  bundledCode: "#line 2 \"alg/monoid/monoid_reverse.hpp\"\ntemplate <class Monoid>\r\
    \nstruct Monoid_Reverse {\r\n  using value_type = typename Monoid::value_type;\r\
    \n  using X = value_type;\r\n  static constexpr X op(const X &x, const X &y) {\
    \ return Monoid::op(y, x); }\r\n  static constexpr X unit() { return Monoid::unit();\
    \ }\r\n  static const bool commute = Monoid::commute;\r\n};\r\n#line 2 \"alg/acted_monoid/reverse.hpp\"\
    \n\r\ntemplate <typename ActedMonoid>\r\nstruct ActedMonoid_Reverse {\r\n  using\
    \ Monoid_X = Monoid_Reverse<typename ActedMonoid::Monoid_X>;\r\n  using Monoid_A\
    \ = typename ActedMonoid::Monoid_A;\r\n  using X = typename Monoid_X::value_type;\r\
    \n  using A = typename Monoid_A::value_type;\r\n  static constexpr X act(const\
    \ X &x, const A &a) { return Lazy::act(x, a); }\r\n};\r\n"
  code: "#include \"alg/monoid/monoid_reverse.hpp\"\r\n\r\ntemplate <typename ActedMonoid>\r\
    \nstruct ActedMonoid_Reverse {\r\n  using Monoid_X = Monoid_Reverse<typename ActedMonoid::Monoid_X>;\r\
    \n  using Monoid_A = typename ActedMonoid::Monoid_A;\r\n  using X = typename Monoid_X::value_type;\r\
    \n  using A = typename Monoid_A::value_type;\r\n  static constexpr X act(const\
    \ X &x, const A &a) { return Lazy::act(x, a); }\r\n};\r\n"
  dependsOn:
  - alg/monoid/monoid_reverse.hpp
  isVerificationFile: false
  path: alg/acted_monoid/reverse.hpp
  requiredBy: []
  timestamp: '2022-11-28 15:05:14+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: alg/acted_monoid/reverse.hpp
layout: document
redirect_from:
- /library/alg/acted_monoid/reverse.hpp
- /library/alg/acted_monoid/reverse.hpp.html
title: alg/acted_monoid/reverse.hpp
---
