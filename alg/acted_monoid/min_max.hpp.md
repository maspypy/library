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
    path: test/1_mytest/min_max.test.cpp
    title: test/1_mytest/min_max.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 1 \"alg/monoid/max.hpp\"\n// require: all values x satisfy x\
    \ >= -infty<E>\ntemplate <typename E>\nstruct Monoid_Max {\n  using X = E;\n \
    \ using value_type = X;\n  static constexpr X op(const X &x, const X &y) noexcept\
    \ { return max(x, y); }\n  static constexpr X id() { return -infty<E>; }\n  static\
    \ constexpr bool commute = true;\n};\n#line 1 \"alg/monoid/min.hpp\"\n// require:\
    \ all values x satisfy x <= infty<E>\ntemplate <typename E>\nstruct Monoid_Min\
    \ {\n  using X = E;\n  using value_type = X;\n  static constexpr X op(const X\
    \ &x, const X &y) noexcept { return min(x, y); }\n  static constexpr X id() {\
    \ return infty<E>; }\n  static constexpr bool commute = true;\n};\n#line 3 \"\
    alg/acted_monoid/min_max.hpp\"\n\ntemplate <typename E>\nstruct ActedMonoid_Min_Max\
    \ {\n  using Monoid_X = Monoid_Min<E>;\n  using Monoid_A = Monoid_Max<E>;\n  using\
    \ X = typename Monoid_X::value_type;\n  using A = typename Monoid_A::value_type;\n\
    \  static constexpr X act(const X &x, const A &a, const ll &size) {\n    return\
    \ max(x, a);\n  }\n};\n"
  code: "#include \"alg/monoid/max.hpp\"\n#include \"alg/monoid/min.hpp\"\n\ntemplate\
    \ <typename E>\nstruct ActedMonoid_Min_Max {\n  using Monoid_X = Monoid_Min<E>;\n\
    \  using Monoid_A = Monoid_Max<E>;\n  using X = typename Monoid_X::value_type;\n\
    \  using A = typename Monoid_A::value_type;\n  static constexpr X act(const X\
    \ &x, const A &a, const ll &size) {\n    return max(x, a);\n  }\n};\n"
  dependsOn:
  - alg/monoid/max.hpp
  - alg/monoid/min.hpp
  isVerificationFile: false
  path: alg/acted_monoid/min_max.hpp
  requiredBy: []
  timestamp: '2026-08-30 21:27:49+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/1_mytest/min_max.test.cpp
documentation_of: alg/acted_monoid/min_max.hpp
layout: document
redirect_from:
- /library/alg/acted_monoid/min_max.hpp
- /library/alg/acted_monoid/min_max.hpp.html
title: alg/acted_monoid/min_max.hpp
---
