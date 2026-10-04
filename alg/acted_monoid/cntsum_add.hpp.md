---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: alg/monoid/add.hpp
    title: alg/monoid/add.hpp
  - icon: ':heavy_check_mark:'
    path: alg/monoid/add_pair.hpp
    title: alg/monoid/add_pair.hpp
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/3_yukicoder/235.test.cpp
    title: test/3_yukicoder/235.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 1 \"alg/monoid/add_pair.hpp\"\n\ntemplate <typename E>\nstruct\
    \ Monoid_Add_Pair {\n  using value_type = pair<E, E>;\n  using X = value_type;\n\
    \  static constexpr X op(const X &x, const X &y) {\n    return {x.fi + y.fi, x.se\
    \ + y.se};\n  }\n  static constexpr X inverse(const X &x) { return {-x.fi, -x.se};\
    \ }\n  static constexpr X id() { return {0, 0}; }\n  static constexpr bool commute\
    \ = true;\n};\n#line 1 \"alg/monoid/add.hpp\"\n\ntemplate <typename E>\nstruct\
    \ Monoid_Add {\n  using X = E;\n  using value_type = X;\n  static constexpr X\
    \ op(const X &x, const X &y) noexcept { return x + y; }\n  static constexpr X\
    \ inverse(const X &x) noexcept { return -x; }\n  static constexpr X power(const\
    \ X &x, ll n) noexcept { return X(n) * x; }\n  static constexpr X id() { return\
    \ X(0); }\n  static constexpr bool commute = true;\n};\n#line 3 \"alg/acted_monoid/cntsum_add.hpp\"\
    \n\ntemplate <typename E>\nstruct ActedMonoid_CntSum_Add {\n  using Monoid_X =\
    \ Monoid_Add_Pair<E>;\n  using Monoid_A = Monoid_Add<E>;\n  using X = typename\
    \ Monoid_X::value_type;\n  using A = typename Monoid_A::value_type;\n  static\
    \ constexpr X act(const X &x, const A &a, const ll &size) {\n    return {x.fi,\
    \ x.se + x.fi * a};\n  }\n};\n"
  code: "#include \"alg/monoid/add_pair.hpp\"\n#include \"alg/monoid/add.hpp\"\n\n\
    template <typename E>\nstruct ActedMonoid_CntSum_Add {\n  using Monoid_X = Monoid_Add_Pair<E>;\n\
    \  using Monoid_A = Monoid_Add<E>;\n  using X = typename Monoid_X::value_type;\n\
    \  using A = typename Monoid_A::value_type;\n  static constexpr X act(const X\
    \ &x, const A &a, const ll &size) {\n    return {x.fi, x.se + x.fi * a};\n  }\n\
    };"
  dependsOn:
  - alg/monoid/add_pair.hpp
  - alg/monoid/add.hpp
  isVerificationFile: false
  path: alg/acted_monoid/cntsum_add.hpp
  requiredBy: []
  timestamp: '2026-08-30 21:09:36+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/3_yukicoder/235.test.cpp
documentation_of: alg/acted_monoid/cntsum_add.hpp
layout: document
redirect_from:
- /library/alg/acted_monoid/cntsum_add.hpp
- /library/alg/acted_monoid/cntsum_add.hpp.html
title: alg/acted_monoid/cntsum_add.hpp
---
