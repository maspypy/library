---
data:
  _extendedDependsOn: []
  _extendedRequiredBy:
  - icon: ':x:'
    path: convex/lattice_point_sum_polynomial_pq.hpp
    title: convex/lattice_point_sum_polynomial_pq.hpp
  - icon: ':x:'
    path: mod/floor_sum_of_linear_polynomial_pq.hpp
    title: mod/floor_sum_of_linear_polynomial_pq.hpp
  _extendedVerifiedWith:
  - icon: ':x:'
    path: test/1_mytest/floor_sum_of_polynomial_pq.test.cpp
    title: test/1_mytest/floor_sum_of_polynomial_pq.test.cpp
  - icon: ':x:'
    path: test/1_mytest/lattice_point_sum_polynomial_pq.test.cpp
    title: test/1_mytest/lattice_point_sum_polynomial_pq.test.cpp
  _isVerificationFailed: true
  _pathExtension: hpp
  _verificationStatusIcon: ':x:'
  attributes:
    links: []
  bundledCode: "#line 1 \"alg/monoid/monoid_for_floor_sum_pq.hpp\"\n\n// floor path\
    \ \u3067 (x,y) \u304B\u3089 x \u65B9\u5411\u306B\u9032\u3080\u3068\u304D\u306B\
    \ p^xq^yx^k1y^k2 \u3092\u8DB3\u3059\ntemplate <typename T, int K1, int K2>\nstruct\
    \ Monoid_for_floor_sum_pq {\n  using ARR = array<array<T, K2 + 1>, K1 + 1>;\n\
    \  struct Data {\n    ARR dp;\n    T dx, dy;\n    T prod;\n  };\n\n  static pair<T,\
    \ T> &get_pq() {\n    static pair<T, T> pq = {T(1), T(1)};\n    return pq;\n \
    \ }\n\n  static void set_pq(T p, T q) { get_pq() = {p, q}; }\n\n  using value_type\
    \ = Data;\n  using X = value_type;\n  static X op(X a, X b) {\n    static constexpr\
    \ int n = max(K1, K2);\n    static T comb[n + 1][n + 1];\n    if (comb[0][0] !=\
    \ T(1)) {\n      comb[0][0] = T(1);\n      FOR(i, n) FOR(j, i + 1) { comb[i +\
    \ 1][j] += comb[i][j], comb[i + 1][j + 1] += comb[i][j]; }\n    }\n\n    array<T,\
    \ K1 + 1> pow_x;\n    array<T, K2 + 1> pow_y;\n    pow_x[0] = 1, pow_y[0] = 1;\n\
    \    FOR(i, K1) pow_x[i + 1] = pow_x[i] * a.dx;\n    FOR(i, K2) pow_y[i + 1] =\
    \ pow_y[i] * a.dy;\n\n    FOR(i, K1 + 1) FOR(j, K2 + 1) { b.dp[i][j] *= a.prod;\
    \ }\n\n    // +dy\n    FOR(i, K1 + 1) {\n      FOR_R(j, K2 + 1) {\n        T x\
    \ = b.dp[i][j];\n        FOR(k, j + 1, K2 + 1) b.dp[i][k] += comb[k][j] * pow_y[k\
    \ - j] * x;\n      }\n    }\n\n    // +dx\n    FOR(j, K2 + 1) {\n      FOR_R(i,\
    \ K1 + 1) { FOR(k, i, K1 + 1) a.dp[k][j] += comb[k][i] * pow_x[k - i] * b.dp[i][j];\
    \ }\n    }\n\n    a.dx += b.dx, a.dy += b.dy, a.prod *= b.prod;\n    return a;\n\
    \  }\n\n  static X to_x() {\n    X x = unit();\n    x.dp[0][0] = 1, x.dx = 1,\
    \ x.prod = get_pq().fi;\n    return x;\n  }\n  static X to_y() {\n    X x = unit();\n\
    \    x.dy = 1, x.prod = get_pq().se;\n    return x;\n  }\n  static constexpr X\
    \ unit() { return {ARR{}, T(0), T(0), T(1)}; }\n  static constexpr bool commute\
    \ = 0;\n};\n"
  code: "\n// floor path \u3067 (x,y) \u304B\u3089 x \u65B9\u5411\u306B\u9032\u3080\
    \u3068\u304D\u306B p^xq^yx^k1y^k2 \u3092\u8DB3\u3059\ntemplate <typename T, int\
    \ K1, int K2>\nstruct Monoid_for_floor_sum_pq {\n  using ARR = array<array<T,\
    \ K2 + 1>, K1 + 1>;\n  struct Data {\n    ARR dp;\n    T dx, dy;\n    T prod;\n\
    \  };\n\n  static pair<T, T> &get_pq() {\n    static pair<T, T> pq = {T(1), T(1)};\n\
    \    return pq;\n  }\n\n  static void set_pq(T p, T q) { get_pq() = {p, q}; }\n\
    \n  using value_type = Data;\n  using X = value_type;\n  static X op(X a, X b)\
    \ {\n    static constexpr int n = max(K1, K2);\n    static T comb[n + 1][n + 1];\n\
    \    if (comb[0][0] != T(1)) {\n      comb[0][0] = T(1);\n      FOR(i, n) FOR(j,\
    \ i + 1) { comb[i + 1][j] += comb[i][j], comb[i + 1][j + 1] += comb[i][j]; }\n\
    \    }\n\n    array<T, K1 + 1> pow_x;\n    array<T, K2 + 1> pow_y;\n    pow_x[0]\
    \ = 1, pow_y[0] = 1;\n    FOR(i, K1) pow_x[i + 1] = pow_x[i] * a.dx;\n    FOR(i,\
    \ K2) pow_y[i + 1] = pow_y[i] * a.dy;\n\n    FOR(i, K1 + 1) FOR(j, K2 + 1) { b.dp[i][j]\
    \ *= a.prod; }\n\n    // +dy\n    FOR(i, K1 + 1) {\n      FOR_R(j, K2 + 1) {\n\
    \        T x = b.dp[i][j];\n        FOR(k, j + 1, K2 + 1) b.dp[i][k] += comb[k][j]\
    \ * pow_y[k - j] * x;\n      }\n    }\n\n    // +dx\n    FOR(j, K2 + 1) {\n  \
    \    FOR_R(i, K1 + 1) { FOR(k, i, K1 + 1) a.dp[k][j] += comb[k][i] * pow_x[k -\
    \ i] * b.dp[i][j]; }\n    }\n\n    a.dx += b.dx, a.dy += b.dy, a.prod *= b.prod;\n\
    \    return a;\n  }\n\n  static X to_x() {\n    X x = unit();\n    x.dp[0][0]\
    \ = 1, x.dx = 1, x.prod = get_pq().fi;\n    return x;\n  }\n  static X to_y()\
    \ {\n    X x = unit();\n    x.dy = 1, x.prod = get_pq().se;\n    return x;\n \
    \ }\n  static constexpr X unit() { return {ARR{}, T(0), T(0), T(1)}; }\n  static\
    \ constexpr bool commute = 0;\n};\n"
  dependsOn: []
  isVerificationFile: false
  path: alg/monoid/monoid_for_floor_sum_pq.hpp
  requiredBy:
  - mod/floor_sum_of_linear_polynomial_pq.hpp
  - convex/lattice_point_sum_polynomial_pq.hpp
  timestamp: '2025-02-12 05:55:32+09:00'
  verificationStatus: LIBRARY_ALL_WA
  verifiedWith:
  - test/1_mytest/lattice_point_sum_polynomial_pq.test.cpp
  - test/1_mytest/floor_sum_of_polynomial_pq.test.cpp
documentation_of: alg/monoid/monoid_for_floor_sum_pq.hpp
layout: document
redirect_from:
- /library/alg/monoid/monoid_for_floor_sum_pq.hpp
- /library/alg/monoid/monoid_for_floor_sum_pq.hpp.html
title: alg/monoid/monoid_for_floor_sum_pq.hpp
---
