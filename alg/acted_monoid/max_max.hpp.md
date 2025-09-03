---
data:
  _extendedDependsOn:
  - icon: ':question:'
    path: alg/monoid/max.hpp
    title: alg/monoid/max.hpp
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':x:'
    path: test/1_mytest/max_max.test.cpp
    title: test/1_mytest/max_max.test.cpp
  _isVerificationFailed: true
  _pathExtension: hpp
  _verificationStatusIcon: ':x:'
  attributes:
    links: []
  bundledCode: "#line 2 \"alg/monoid/max.hpp\"\n\r\ntemplate <typename E>\r\nstruct\
    \ Monoid_Max {\r\n  using X = E;\r\n  using value_type = X;\r\n  static constexpr\
    \ X op(const X &x, const X &y) noexcept { return max(x, y); }\r\n  static constexpr\
    \ X unit() { return -infty<E>; }\r\n  static constexpr bool commute = true;\r\n\
    };\r\n#line 2 \"alg/acted_monoid/max_max.hpp\"\n\r\ntemplate <typename E>\r\n\
    struct ActedMonoid_Max_Max {\r\n  using Monoid_X = Monoid_Max<E>;\r\n  using Monoid_A\
    \ = Monoid_Max<E>;\r\n  using X = typename Monoid_X::value_type;\r\n  using A\
    \ = typename Monoid_A::value_type;\r\n  static constexpr X act(const X &x, const\
    \ A &a, const ll &size) {\r\n    return max(x, a);\r\n  }\r\n};\r\n"
  code: "#include \"alg/monoid/max.hpp\"\r\n\r\ntemplate <typename E>\r\nstruct ActedMonoid_Max_Max\
    \ {\r\n  using Monoid_X = Monoid_Max<E>;\r\n  using Monoid_A = Monoid_Max<E>;\r\
    \n  using X = typename Monoid_X::value_type;\r\n  using A = typename Monoid_A::value_type;\r\
    \n  static constexpr X act(const X &x, const A &a, const ll &size) {\r\n    return\
    \ max(x, a);\r\n  }\r\n};\r\n"
  dependsOn:
  - alg/monoid/max.hpp
  isVerificationFile: false
  path: alg/acted_monoid/max_max.hpp
  requiredBy: []
  timestamp: '2023-02-01 23:31:55+09:00'
  verificationStatus: LIBRARY_ALL_WA
  verifiedWith:
  - test/1_mytest/max_max.test.cpp
documentation_of: alg/acted_monoid/max_max.hpp
layout: document
redirect_from:
- /library/alg/acted_monoid/max_max.hpp
- /library/alg/acted_monoid/max_max.hpp.html
title: alg/acted_monoid/max_max.hpp
---
