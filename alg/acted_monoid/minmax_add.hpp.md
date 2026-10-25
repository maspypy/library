---
data:
  _extendedDependsOn:
  - icon: ':question:'
    path: alg/monoid/add.hpp
    title: alg/monoid/add.hpp
  - icon: ':heavy_check_mark:'
    path: alg/monoid/minmax.hpp
    title: alg/monoid/minmax.hpp
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/1_mytest/minmax_add.test.cpp
    title: test/1_mytest/minmax_add.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links:
    - https://github.com/maspypy/library/blob/main/alg/acted_monoid/minmax_add.hpp
  bundledCode: "#line 1 \"alg/acted_monoid/minmax_add.hpp\"\n// Source: https://github.com/maspypy/library/blob/main/alg/acted_monoid/minmax_add.hpp\n\
    #line 1 \"alg/monoid/add.hpp\"\n// Source: https://github.com/maspypy/library/blob/main/alg/monoid/add.hpp\n\
    \ntemplate <typename E>\nstruct Monoid_Add {\n  using X = E;\n  using value_type\
    \ = X;\n  static constexpr X op(const X &x, const X &y) noexcept { return x +\
    \ y; }\n  static constexpr X inverse(const X &x) noexcept { return -x; }\n  static\
    \ constexpr X power(const X &x, ll n) noexcept { return X(n) * x; }\n  static\
    \ constexpr X id() { return X(0); }\n  static constexpr bool commute = true;\n\
    };\n#line 1 \"alg/monoid/minmax.hpp\"\n// Source: https://github.com/maspypy/library/blob/main/alg/monoid/minmax.hpp\n\
    \ntemplate <class X>\nstruct Monoid_MinMax {\n  using P = pair<X, X>;\n  using\
    \ value_type = P;\n  static constexpr P op(const P x, const P y) noexcept {\n\
    \    return {min(x.fi, y.fi), max(x.se, y.se)};\n  }\n  static constexpr P from_element(const\
    \ X x) { return {x, x}; }\n  static constexpr P id() { return {infty<X>, -infty<X>};\
    \ }\n  static constexpr bool commute = true;\n};\n#line 4 \"alg/acted_monoid/minmax_add.hpp\"\
    \n\ntemplate <typename E>\nstruct ActedMonoid_MinMax_Add {\n  using Monoid_X =\
    \ Monoid_MinMax<E>;\n  using Monoid_A = Monoid_Add<E>;\n  using X = typename Monoid_X::value_type;\n\
    \  using A = typename Monoid_A::value_type;\n  static constexpr X act(const X\
    \ &x, const A &a, const ll &size) {\n    E lo = (x.fi == infty<E> ? x.fi : x.fi\
    \ + a);\n    E hi = (x.se == -infty<E> ? x.se : x.se + a);\n    return {lo, hi};\n\
    \  }\n};\n"
  code: "// Source: https://github.com/maspypy/library/blob/main/alg/acted_monoid/minmax_add.hpp\n\
    #include \"alg/monoid/add.hpp\"\n#include \"alg/monoid/minmax.hpp\"\n\ntemplate\
    \ <typename E>\nstruct ActedMonoid_MinMax_Add {\n  using Monoid_X = Monoid_MinMax<E>;\n\
    \  using Monoid_A = Monoid_Add<E>;\n  using X = typename Monoid_X::value_type;\n\
    \  using A = typename Monoid_A::value_type;\n  static constexpr X act(const X\
    \ &x, const A &a, const ll &size) {\n    E lo = (x.fi == infty<E> ? x.fi : x.fi\
    \ + a);\n    E hi = (x.se == -infty<E> ? x.se : x.se + a);\n    return {lo, hi};\n\
    \  }\n};\n"
  dependsOn:
  - alg/monoid/add.hpp
  - alg/monoid/minmax.hpp
  isVerificationFile: false
  path: alg/acted_monoid/minmax_add.hpp
  requiredBy: []
  timestamp: '2026-10-15 19:54:56+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/1_mytest/minmax_add.test.cpp
documentation_of: alg/acted_monoid/minmax_add.hpp
layout: document
redirect_from:
- /library/alg/acted_monoid/minmax_add.hpp
- /library/alg/acted_monoid/minmax_add.hpp.html
title: alg/acted_monoid/minmax_add.hpp
---
