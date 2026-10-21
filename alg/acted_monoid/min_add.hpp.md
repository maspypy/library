---
data:
  _extendedDependsOn:
  - icon: ':question:'
    path: alg/monoid/add.hpp
    title: alg/monoid/add.hpp
  - icon: ':heavy_check_mark:'
    path: alg/monoid/min.hpp
    title: alg/monoid/min.hpp
  _extendedRequiredBy:
  - icon: ':heavy_check_mark:'
    path: seq/common_interval_decomposition.hpp
    title: seq/common_interval_decomposition.hpp
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/1_mytest/range_add_range_min.test.cpp
    title: test/1_mytest/range_add_range_min.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/2_library_checker/graph/common_interval_decomposition.test.cpp
    title: test/2_library_checker/graph/common_interval_decomposition.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/3_yukicoder/1234.test.cpp
    title: test/3_yukicoder/1234.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/3_yukicoder/1270.test.cpp
    title: test/3_yukicoder/1270.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/3_yukicoder/1720.test.cpp
    title: test/3_yukicoder/1720.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/4_aoj/DSL_2_H.test.cpp
    title: test/4_aoj/DSL_2_H.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links:
    - https://github.com/maspypy/library/blob/main/alg/acted_monoid/min_add.hpp
  bundledCode: "#line 1 \"alg/acted_monoid/min_add.hpp\"\n// Source: https://github.com/maspypy/library/blob/main/alg/acted_monoid/min_add.hpp\n\
    #line 1 \"alg/monoid/add.hpp\"\n// Source: https://github.com/maspypy/library/blob/main/alg/monoid/add.hpp\n\
    \ntemplate <typename E>\nstruct Monoid_Add {\n  using X = E;\n  using value_type\
    \ = X;\n  static constexpr X op(const X &x, const X &y) noexcept { return x +\
    \ y; }\n  static constexpr X inverse(const X &x) noexcept { return -x; }\n  static\
    \ constexpr X power(const X &x, ll n) noexcept { return X(n) * x; }\n  static\
    \ constexpr X id() { return X(0); }\n  static constexpr bool commute = true;\n\
    };\n#line 1 \"alg/monoid/min.hpp\"\n// Source: https://github.com/maspypy/library/blob/main/alg/monoid/min.hpp\n\
    // require: all values x satisfy x <= infty<E>\ntemplate <typename E>\nstruct\
    \ Monoid_Min {\n  using X = E;\n  using value_type = X;\n  static constexpr X\
    \ op(const X &x, const X &y) noexcept { return min(x, y); }\n  static constexpr\
    \ X id() { return infty<E>; }\n  static constexpr bool commute = true;\n};\n#line\
    \ 4 \"alg/acted_monoid/min_add.hpp\"\n\ntemplate <typename E>\nstruct ActedMonoid_Min_Add\
    \ {\n  using Monoid_X = Monoid_Min<E>;\n  using Monoid_A = Monoid_Add<E>;\n  using\
    \ X = typename Monoid_X::value_type;\n  using A = typename Monoid_A::value_type;\n\
    \  static constexpr X act(const X &x, const A &a, const ll &size) {\n    if (x\
    \ == infty<E>) return x;\n    return x + a;\n  }\n};\n"
  code: "// Source: https://github.com/maspypy/library/blob/main/alg/acted_monoid/min_add.hpp\n\
    #include \"alg/monoid/add.hpp\"\n#include \"alg/monoid/min.hpp\"\n\ntemplate <typename\
    \ E>\nstruct ActedMonoid_Min_Add {\n  using Monoid_X = Monoid_Min<E>;\n  using\
    \ Monoid_A = Monoid_Add<E>;\n  using X = typename Monoid_X::value_type;\n  using\
    \ A = typename Monoid_A::value_type;\n  static constexpr X act(const X &x, const\
    \ A &a, const ll &size) {\n    if (x == infty<E>) return x;\n    return x + a;\n\
    \  }\n};\n"
  dependsOn:
  - alg/monoid/add.hpp
  - alg/monoid/min.hpp
  isVerificationFile: false
  path: alg/acted_monoid/min_add.hpp
  requiredBy:
  - seq/common_interval_decomposition.hpp
  timestamp: '2026-10-15 19:54:56+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/3_yukicoder/1720.test.cpp
  - test/3_yukicoder/1270.test.cpp
  - test/3_yukicoder/1234.test.cpp
  - test/4_aoj/DSL_2_H.test.cpp
  - test/1_mytest/range_add_range_min.test.cpp
  - test/2_library_checker/graph/common_interval_decomposition.test.cpp
documentation_of: alg/acted_monoid/min_add.hpp
layout: document
redirect_from:
- /library/alg/acted_monoid/min_add.hpp
- /library/alg/acted_monoid/min_add.hpp.html
title: alg/acted_monoid/min_add.hpp
---
