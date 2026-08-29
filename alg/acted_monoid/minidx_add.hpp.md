---
data:
  _extendedDependsOn:
  - icon: ':question:'
    path: alg/monoid/add.hpp
    title: alg/monoid/add.hpp
  - icon: ':heavy_check_mark:'
    path: alg/monoid/minidx.hpp
    title: alg/monoid/minidx.hpp
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/1_mytest/minidx_add.test.cpp
    title: test/1_mytest/minidx_add.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 1 \"alg/monoid/add.hpp\"\n\ntemplate <typename E>\nstruct Monoid_Add\
    \ {\n  using X = E;\n  using value_type = X;\n  static constexpr X op(const X\
    \ &x, const X &y) noexcept { return x + y; }\n  static constexpr X inverse(const\
    \ X &x) noexcept { return -x; }\n  static constexpr X power(const X &x, ll n)\
    \ noexcept { return X(n) * x; }\n  static constexpr X unit() { return X(0); }\n\
    \  static constexpr bool commute = true;\n};\n#line 1 \"alg/monoid/minidx.hpp\"\
    \n\ntemplate <typename T, bool tie_is_left = true>\nstruct Monoid_MinIdx {\n \
    \ using value_type = pair<T, int>;\n  using X = value_type;\n  static constexpr\
    \ bool is_small(const X& x, const X& y) {\n    if (x.fi < y.fi) return true;\n\
    \    if (x.fi > y.fi) return false;\n    return (tie_is_left ? (x.se < y.se) :\
    \ (x.se >= y.se));\n  }\n  static X op(X x, X y) { return (is_small(x, y) ? x\
    \ : y); }\n  static constexpr X unit() { return {infty<T>, -1}; }\n  static constexpr\
    \ bool commute = true;\n};\n#line 3 \"alg/acted_monoid/minidx_add.hpp\"\n\r\n\
    template <typename E, bool tie_is_left = true>\r\nstruct ActedMonoid_MinIdx_Add\
    \ {\r\n  using Monoid_X = Monoid_MinIdx<E, tie_is_left>;\r\n  using Monoid_A =\
    \ Monoid_Add<E>;\r\n  using X = typename Monoid_X::value_type;\r\n  using A =\
    \ typename Monoid_A::value_type;\r\n  static constexpr X act(const X &x, const\
    \ A &a, const ll &size) {\r\n    if (x.fi == infty<E>) return x;\r\n    return\
    \ {x.fi + a, x.se};\r\n  }\r\n};\r\n"
  code: "#include \"alg/monoid/add.hpp\"\r\n#include \"alg/monoid/minidx.hpp\"\r\n\
    \r\ntemplate <typename E, bool tie_is_left = true>\r\nstruct ActedMonoid_MinIdx_Add\
    \ {\r\n  using Monoid_X = Monoid_MinIdx<E, tie_is_left>;\r\n  using Monoid_A =\
    \ Monoid_Add<E>;\r\n  using X = typename Monoid_X::value_type;\r\n  using A =\
    \ typename Monoid_A::value_type;\r\n  static constexpr X act(const X &x, const\
    \ A &a, const ll &size) {\r\n    if (x.fi == infty<E>) return x;\r\n    return\
    \ {x.fi + a, x.se};\r\n  }\r\n};\r\n"
  dependsOn:
  - alg/monoid/add.hpp
  - alg/monoid/minidx.hpp
  isVerificationFile: false
  path: alg/acted_monoid/minidx_add.hpp
  requiredBy: []
  timestamp: '2026-08-17 09:25:20+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/1_mytest/minidx_add.test.cpp
documentation_of: alg/acted_monoid/minidx_add.hpp
layout: document
redirect_from:
- /library/alg/acted_monoid/minidx_add.hpp
- /library/alg/acted_monoid/minidx_add.hpp.html
title: alg/acted_monoid/minidx_add.hpp
---
