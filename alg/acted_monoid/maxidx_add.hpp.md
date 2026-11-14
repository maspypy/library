---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: alg/monoid/add.hpp
    title: alg/monoid/add.hpp
  - icon: ':heavy_check_mark:'
    path: alg/monoid/maxidx.hpp
    title: alg/monoid/maxidx.hpp
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/1_mytest/maxidx_add.test.cpp
    title: test/1_mytest/maxidx_add.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links:
    - https://github.com/maspypy/library/blob/main/alg/acted_monoid/maxidx_add.hpp
  bundledCode: "#line 1 \"alg/acted_monoid/maxidx_add.hpp\"\n// Source: https://github.com/maspypy/library/blob/main/alg/acted_monoid/maxidx_add.hpp\n\
    #line 1 \"alg/monoid/add.hpp\"\n// Source: https://github.com/maspypy/library/blob/main/alg/monoid/add.hpp\n\
    \ntemplate <typename E>\nstruct Monoid_Add {\n  using X = E;\n  using value_type\
    \ = X;\n  static constexpr X op(const X &x, const X &y) noexcept { return x +\
    \ y; }\n  static constexpr X inverse(const X &x) noexcept { return -x; }\n  static\
    \ constexpr X power(const X &x, ll n) noexcept { return X(n) * x; }\n  static\
    \ constexpr X id() { return X(0); }\n  static constexpr bool commute = true;\n\
    };\n#line 1 \"alg/monoid/maxidx.hpp\"\n// Source: https://github.com/maspypy/library/blob/main/alg/monoid/maxidx.hpp\n\
    \ntemplate <typename T, bool tie_is_left = true>\nstruct Monoid_MaxIdx {\n  using\
    \ value_type = pair<T, int>;\n  using X = value_type;\n  static X op(X x, X y)\
    \ {\n    if (x.fi > y.fi) return x;\n    if (x.fi < y.fi) return y;\n    if (x.se\
    \ > y.se) swap(x, y);\n    return (tie_is_left ? x : y);\n  }\n  static constexpr\
    \ X id() { return {-infty<T>, -1}; }\n  static constexpr bool commute = true;\n\
    };\n#line 4 \"alg/acted_monoid/maxidx_add.hpp\"\n\ntemplate <typename E, bool\
    \ tie_is_left = true>\nstruct ActedMonoid_MaxIdx_Add {\n  using Monoid_X = Monoid_MaxIdx<E,\
    \ tie_is_left>;\n  using Monoid_A = Monoid_Add<E>;\n  using X = typename Monoid_X::value_type;\n\
    \  using A = typename Monoid_A::value_type;\n  static constexpr X act(const X\
    \ &x, const A &a, const ll &size) {\n    if (x.fi == -infty<E>) return x;\n  \
    \  return {x.fi + a, x.se};\n  }\n};\n"
  code: "// Source: https://github.com/maspypy/library/blob/main/alg/acted_monoid/maxidx_add.hpp\n\
    #include \"alg/monoid/add.hpp\"\n#include \"alg/monoid/maxidx.hpp\"\n\ntemplate\
    \ <typename E, bool tie_is_left = true>\nstruct ActedMonoid_MaxIdx_Add {\n  using\
    \ Monoid_X = Monoid_MaxIdx<E, tie_is_left>;\n  using Monoid_A = Monoid_Add<E>;\n\
    \  using X = typename Monoid_X::value_type;\n  using A = typename Monoid_A::value_type;\n\
    \  static constexpr X act(const X &x, const A &a, const ll &size) {\n    if (x.fi\
    \ == -infty<E>) return x;\n    return {x.fi + a, x.se};\n  }\n};\n"
  dependsOn:
  - alg/monoid/add.hpp
  - alg/monoid/maxidx.hpp
  isVerificationFile: false
  path: alg/acted_monoid/maxidx_add.hpp
  requiredBy: []
  timestamp: '2026-10-15 19:54:56+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/1_mytest/maxidx_add.test.cpp
documentation_of: alg/acted_monoid/maxidx_add.hpp
layout: document
redirect_from:
- /library/alg/acted_monoid/maxidx_add.hpp
- /library/alg/acted_monoid/maxidx_add.hpp.html
title: alg/acted_monoid/maxidx_add.hpp
---
