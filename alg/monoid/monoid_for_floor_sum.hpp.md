---
data:
  _extendedDependsOn: []
  _extendedRequiredBy:
  - icon: ':heavy_check_mark:'
    path: convex/lattice_point_sum_polynomial.hpp
    title: convex/lattice_point_sum_polynomial.hpp
  - icon: ':heavy_check_mark:'
    path: convex/lattice_point_sum_polynomial_pq.hpp
    title: convex/lattice_point_sum_polynomial_pq.hpp
  - icon: ':heavy_check_mark:'
    path: mod/floor_sum_of_linear_polynomial.hpp
    title: mod/floor_sum_of_linear_polynomial.hpp
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/1_mytest/floor_sum_of_polynomial.test.cpp
    title: test/1_mytest/floor_sum_of_polynomial.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/1_mytest/lattice_point_sum_polynomial.test.cpp
    title: test/1_mytest/lattice_point_sum_polynomial.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/1_mytest/lattice_point_sum_polynomial_pq.test.cpp
    title: test/1_mytest/lattice_point_sum_polynomial_pq.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/2_library_checker/number_theory/sum_of_floor_of_linear_2.test.cpp
    title: test/2_library_checker/number_theory/sum_of_floor_of_linear_2.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/3_yukicoder/2362.test.cpp
    title: test/3_yukicoder/2362.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 2 \"alg/monoid/monoid_for_floor_sum.hpp\"\n// sum i^k1floor^k2:\
    \ floor path \u3067 (x,y) \u304B\u3089 x \u65B9\u5411\u306B\u9032\u3080\u3068\u304D\
    \u306B x^k1y^k2 \u3092\u8DB3\u3059\ntemplate <typename T, int K1, int K2>\nstruct\
    \ Monoid_for_floor_sum {\n  using ARR = array<array<T, K2 + 1>, K1 + 1>;\n  struct\
    \ Data {\n    ARR dp;\n    T dx, dy;\n  };\n\n  using value_type = Data;\n  using\
    \ X = value_type;\n  static X op(X a, X b) {\n    static constexpr int n = max(K1,\
    \ K2);\n    static T comb[n + 1][n + 1];\n    if (comb[0][0] != T(1)) {\n    \
    \  comb[0][0] = T(1);\n      FOR(i, n) FOR(j, i + 1) { comb[i + 1][j] += comb[i][j],\
    \ comb[i + 1][j + 1] += comb[i][j]; }\n    }\n\n    array<T, K1 + 1> pow_x;\n\
    \    array<T, K2 + 1> pow_y;\n    pow_x[0] = 1, pow_y[0] = 1;\n    FOR(i, K1)\
    \ pow_x[i + 1] = pow_x[i] * a.dx;\n    FOR(i, K2) pow_y[i + 1] = pow_y[i] * a.dy;\n\
    \n    // +dy\n    FOR(i, K1 + 1) {\n      FOR_R(j, K2 + 1) {\n        T x = b.dp[i][j];\n\
    \        FOR(k, j + 1, K2 + 1) b.dp[i][k] += comb[k][j] * pow_y[k - j] * x;\n\
    \      }\n    }\n    // +dx\n    FOR(j, K2 + 1) {\n      FOR_R(i, K1 + 1) { FOR(k,\
    \ i, K1 + 1) a.dp[k][j] += comb[k][i] * pow_x[k - i] * b.dp[i][j]; }\n    }\n\n\
    \    a.dx += b.dx, a.dy += b.dy;\n    return a;\n  }\n\n  static X to_x() {\n\
    \    X x = unit();\n    x.dp[0][0] = 1, x.dx = 1;\n    return x;\n  }\n  static\
    \ X to_y() {\n    X x = unit();\n    x.dy = 1;\n    return x;\n  }\n  static constexpr\
    \ X unit() { return {ARR{}, T(0), T(0)}; }\n  static constexpr bool commute =\
    \ 0;\n};\n"
  code: "#pragma once\n// sum i^k1floor^k2: floor path \u3067 (x,y) \u304B\u3089 x\
    \ \u65B9\u5411\u306B\u9032\u3080\u3068\u304D\u306B x^k1y^k2 \u3092\u8DB3\u3059\
    \ntemplate <typename T, int K1, int K2>\nstruct Monoid_for_floor_sum {\n  using\
    \ ARR = array<array<T, K2 + 1>, K1 + 1>;\n  struct Data {\n    ARR dp;\n    T\
    \ dx, dy;\n  };\n\n  using value_type = Data;\n  using X = value_type;\n  static\
    \ X op(X a, X b) {\n    static constexpr int n = max(K1, K2);\n    static T comb[n\
    \ + 1][n + 1];\n    if (comb[0][0] != T(1)) {\n      comb[0][0] = T(1);\n    \
    \  FOR(i, n) FOR(j, i + 1) { comb[i + 1][j] += comb[i][j], comb[i + 1][j + 1]\
    \ += comb[i][j]; }\n    }\n\n    array<T, K1 + 1> pow_x;\n    array<T, K2 + 1>\
    \ pow_y;\n    pow_x[0] = 1, pow_y[0] = 1;\n    FOR(i, K1) pow_x[i + 1] = pow_x[i]\
    \ * a.dx;\n    FOR(i, K2) pow_y[i + 1] = pow_y[i] * a.dy;\n\n    // +dy\n    FOR(i,\
    \ K1 + 1) {\n      FOR_R(j, K2 + 1) {\n        T x = b.dp[i][j];\n        FOR(k,\
    \ j + 1, K2 + 1) b.dp[i][k] += comb[k][j] * pow_y[k - j] * x;\n      }\n    }\n\
    \    // +dx\n    FOR(j, K2 + 1) {\n      FOR_R(i, K1 + 1) { FOR(k, i, K1 + 1)\
    \ a.dp[k][j] += comb[k][i] * pow_x[k - i] * b.dp[i][j]; }\n    }\n\n    a.dx +=\
    \ b.dx, a.dy += b.dy;\n    return a;\n  }\n\n  static X to_x() {\n    X x = unit();\n\
    \    x.dp[0][0] = 1, x.dx = 1;\n    return x;\n  }\n  static X to_y() {\n    X\
    \ x = unit();\n    x.dy = 1;\n    return x;\n  }\n  static constexpr X unit()\
    \ { return {ARR{}, T(0), T(0)}; }\n  static constexpr bool commute = 0;\n};\n"
  dependsOn: []
  isVerificationFile: false
  path: alg/monoid/monoid_for_floor_sum.hpp
  requiredBy:
  - convex/lattice_point_sum_polynomial.hpp
  - convex/lattice_point_sum_polynomial_pq.hpp
  - mod/floor_sum_of_linear_polynomial.hpp
  timestamp: '2025-02-12 14:27:42+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/1_mytest/lattice_point_sum_polynomial_pq.test.cpp
  - test/1_mytest/lattice_point_sum_polynomial.test.cpp
  - test/1_mytest/floor_sum_of_polynomial.test.cpp
  - test/3_yukicoder/2362.test.cpp
  - test/2_library_checker/number_theory/sum_of_floor_of_linear_2.test.cpp
documentation_of: alg/monoid/monoid_for_floor_sum.hpp
layout: document
redirect_from:
- /library/alg/monoid/monoid_for_floor_sum.hpp
- /library/alg/monoid/monoid_for_floor_sum.hpp.html
title: alg/monoid/monoid_for_floor_sum.hpp
---
