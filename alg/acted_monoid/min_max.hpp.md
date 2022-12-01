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
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':warning:'
  attributes:
    links: []
  bundledCode: "#line 2 \"alg/monoid/max.hpp\"\n\r\ntemplate <class X>\r\nstruct Monoid_Max\
    \ {\r\n  using value_type = X;\r\n  static constexpr X op(const X &x, const X\
    \ &y) noexcept { return max(x, y); }\r\n  static constexpr X unit() { return numeric_limits<X>::lowest();\
    \ }\r\n  static constexpr bool commute = true;\r\n};\r\n#line 2 \"alg/monoid/min.hpp\"\
    \n\r\ntemplate <class X>\r\nstruct Monoid_Min {\r\n  using value_type = X;\r\n\
    \  static constexpr X op(const X &x, const X &y) noexcept { return min(x, y);\
    \ }\r\n  static constexpr X unit() { return numeric_limits<X>::max(); }\r\n  static\
    \ constexpr bool commute = true;\r\n};\r\n#line 3 \"alg/acted_monoid/min_max.hpp\"\
    \n\ntemplate <typename E>\nstruct ActedMonoid_Min_Max {\n  using Monoid_X = Monoid_Min<E>;\n\
    \  using Monoid_A = Monoid_Max<E>;\n  using X = typename Monoid_X::value_type;\n\
    \  using A = typename Monoid_A::value_type;\n  static constexpr X act(const X\
    \ &x, const A &a) { return max(x, a); }\n};\n"
  code: "#include \"alg/monoid/max.hpp\"\n#include \"alg/monoid/min.hpp\"\n\ntemplate\
    \ <typename E>\nstruct ActedMonoid_Min_Max {\n  using Monoid_X = Monoid_Min<E>;\n\
    \  using Monoid_A = Monoid_Max<E>;\n  using X = typename Monoid_X::value_type;\n\
    \  using A = typename Monoid_A::value_type;\n  static constexpr X act(const X\
    \ &x, const A &a) { return max(x, a); }\n};\n"
  dependsOn:
  - alg/monoid/max.hpp
  - alg/monoid/min.hpp
  isVerificationFile: false
  path: alg/acted_monoid/min_max.hpp
  requiredBy: []
  timestamp: '2022-12-01 09:04:06+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: alg/acted_monoid/min_max.hpp
layout: document
redirect_from:
- /library/alg/acted_monoid/min_max.hpp
- /library/alg/acted_monoid/min_max.hpp.html
title: alg/acted_monoid/min_max.hpp
---
