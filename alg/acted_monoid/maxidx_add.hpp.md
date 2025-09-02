---
data:
  _extendedDependsOn:
  - icon: ':x:'
    path: alg/monoid/add.hpp
    title: alg/monoid/add.hpp
  - icon: ':x:'
    path: alg/monoid/max_idx.hpp
    title: alg/monoid/max_idx.hpp
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':x:'
    path: test/1_mytest/maxidx_add.test.cpp
    title: test/1_mytest/maxidx_add.test.cpp
  _isVerificationFailed: true
  _pathExtension: hpp
  _verificationStatusIcon: ':x:'
  attributes:
    links: []
  bundledCode: "#line 2 \"alg/monoid/add.hpp\"\n\r\ntemplate <typename E>\r\nstruct\
    \ Monoid_Add {\r\n  using X = E;\r\n  using value_type = X;\r\n  static constexpr\
    \ X op(const X &x, const X &y) noexcept { return x + y; }\r\n  static constexpr\
    \ X inverse(const X &x) noexcept { return -x; }\r\n  static constexpr X power(const\
    \ X &x, ll n) noexcept { return X(n) * x; }\r\n  static constexpr X unit() { return\
    \ X(0); }\r\n  static constexpr bool commute = true;\r\n};\r\n#line 2 \"alg/monoid/max_idx.hpp\"\
    \n\r\ntemplate <typename T, bool tie_is_left = true>\r\nstruct Monoid_Max_Idx\
    \ {\r\n  using value_type = pair<T, int>;\r\n  using X = value_type;\r\n  static\
    \ X op(X x, X y) {\r\n    if (x.fi > y.fi) return x;\r\n    if (x.fi < y.fi) return\
    \ y;\r\n    if (x.se > y.se) swap(x, y);\r\n    return (tie_is_left ? x : y);\r\
    \n  }\r\n  static constexpr X unit() { return {-infty<T>, -1}; }\r\n  static constexpr\
    \ bool commute = true;\r\n};\r\n#line 3 \"alg/acted_monoid/maxidx_add.hpp\"\n\r\
    \ntemplate <typename E, bool tie_is_left = true>\r\nstruct ActedMonoid_MaxIdx_Add\
    \ {\r\n  using Monoid_X = Monoid_Max_Idx<E, tie_is_left>;\r\n  using Monoid_A\
    \ = Monoid_Add<E>;\r\n  using X = typename Monoid_X::value_type;\r\n  using A\
    \ = typename Monoid_A::value_type;\r\n  static constexpr X act(const X &x, const\
    \ A &a, const ll &size) {\r\n    if (x.fi == -infty<E>) return x;\r\n    return\
    \ {x.fi + a, x.se};\r\n  }\r\n};\r\n"
  code: "#include \"alg/monoid/add.hpp\"\r\n#include \"alg/monoid/max_idx.hpp\"\r\n\
    \r\ntemplate <typename E, bool tie_is_left = true>\r\nstruct ActedMonoid_MaxIdx_Add\
    \ {\r\n  using Monoid_X = Monoid_Max_Idx<E, tie_is_left>;\r\n  using Monoid_A\
    \ = Monoid_Add<E>;\r\n  using X = typename Monoid_X::value_type;\r\n  using A\
    \ = typename Monoid_A::value_type;\r\n  static constexpr X act(const X &x, const\
    \ A &a, const ll &size) {\r\n    if (x.fi == -infty<E>) return x;\r\n    return\
    \ {x.fi + a, x.se};\r\n  }\r\n};\r\n"
  dependsOn:
  - alg/monoid/add.hpp
  - alg/monoid/max_idx.hpp
  isVerificationFile: false
  path: alg/acted_monoid/maxidx_add.hpp
  requiredBy: []
  timestamp: '2024-01-23 05:58:02+09:00'
  verificationStatus: LIBRARY_ALL_WA
  verifiedWith:
  - test/1_mytest/maxidx_add.test.cpp
documentation_of: alg/acted_monoid/maxidx_add.hpp
layout: document
redirect_from:
- /library/alg/acted_monoid/maxidx_add.hpp
- /library/alg/acted_monoid/maxidx_add.hpp.html
title: alg/acted_monoid/maxidx_add.hpp
---
