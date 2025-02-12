---
data:
  _extendedDependsOn:
  - icon: ':question:'
    path: alg/monoid/monoid_for_floor_sum.hpp
    title: alg/monoid/monoid_for_floor_sum.hpp
  - icon: ':question:'
    path: alg/monoid_pow.hpp
    title: alg/monoid_pow.hpp
  - icon: ':question:'
    path: mod/floor_monoid_product.hpp
    title: mod/floor_monoid_product.hpp
  _extendedRequiredBy:
  - icon: ':x:'
    path: convex/lattice_point_sum_polynomial.hpp
    title: convex/lattice_point_sum_polynomial.hpp
  - icon: ':x:'
    path: convex/lattice_point_sum_polynomial_pq.hpp
    title: convex/lattice_point_sum_polynomial_pq.hpp
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/1_mytest/floor_sum_of_polynomial.test.cpp
    title: test/1_mytest/floor_sum_of_polynomial.test.cpp
  - icon: ':x:'
    path: test/1_mytest/lattice_point_sum_polynomial.test.cpp
    title: test/1_mytest/lattice_point_sum_polynomial.test.cpp
  - icon: ':x:'
    path: test/1_mytest/lattice_point_sum_polynomial_pq.test.cpp
    title: test/1_mytest/lattice_point_sum_polynomial_pq.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/2_library_checker/number_theory/sum_of_floor_of_linear_2.test.cpp
    title: test/2_library_checker/number_theory/sum_of_floor_of_linear_2.test.cpp
  - icon: ':x:'
    path: test/3_yukicoder/2362.test.cpp
    title: test/3_yukicoder/2362.test.cpp
  _isVerificationFailed: true
  _pathExtension: hpp
  _verificationStatusIcon: ':question:'
  attributes:
    links: []
  bundledCode: "#line 2 \"mod/floor_sum_of_linear_polynomial.hpp\"\n\n#line 2 \"alg/monoid_pow.hpp\"\
    \n\n// chat gpt\ntemplate <typename U, typename Arg1, typename Arg2>\nstruct has_power_method\
    \ {\nprivate:\n  // \u30D8\u30EB\u30D1\u30FC\u95A2\u6570\u306E\u5B9F\u88C5\n \
    \ template <typename V, typename A1, typename A2>\n  static auto check(int)\n\
    \      -> decltype(std::declval<V>().power(std::declval<A1>(),\n             \
    \                             std::declval<A2>()),\n                  std::true_type{});\n\
    \  template <typename, typename, typename>\n  static auto check(...) -> std::false_type;\n\
    \npublic:\n  // \u30E1\u30BD\u30C3\u30C9\u306E\u6709\u7121\u3092\u8868\u3059\u578B\
    \n  static constexpr bool value = decltype(check<U, Arg1, Arg2>(0))::value;\n\
    };\n\ntemplate <typename Monoid>\ntypename Monoid::X monoid_pow(typename Monoid::X\
    \ x, ll exp) {\n  using X = typename Monoid::X;\n  if constexpr (has_power_method<Monoid,\
    \ X, ll>::value) {\n    return Monoid::power(x, exp);\n  } else {\n    assert(exp\
    \ >= 0);\n    X res = Monoid::unit();\n    while (exp) {\n      if (exp & 1) res\
    \ = Monoid::op(res, x);\n      x = Monoid::op(x, x);\n      exp >>= 1;\n    }\n\
    \    return res;\n  }\n}\n#line 3 \"mod/floor_monoid_product.hpp\"\n\n// https://yukicoder.me/submissions/883884\n\
    // https://qoj.ac/contest/1411/problem/7620\n// U \u306F\u7BC4\u56F2\u5185\u3067\
    \ ax+b \u304C\u30AA\u30FC\u30D0\u30FC\u30D5\u30ED\u30FC\u3057\u306A\u3044\u7A0B\
    \u5EA6\n// yyy x yyyy x ... yyy x yyy (x \u3092 N \u500B)\n// k \u500B\u76EE\u306E\
    \ x \u307E\u3067\u306B floor(ak+b,m) \u500B\u306E y \u304C\u3042\u308B\n// my<=ax+b\
    \ \u306B\u304A\u3051\u308B lattice path \u306B\u304A\u3051\u308B\u8FBA\u306E\u5217\
    \u3068\u898B\u306A\u305B\u308B\ntemplate <typename Monoid, typename X, typename\
    \ U>\nX floor_monoid_product(X x, X y, U N, U a, U b, U m) {\n  U c = (a * N +\
    \ b) / m;\n  X pre = Monoid::unit(), suf = Monoid::unit();\n  while (1) {\n  \
    \  const U p = a / m, q = b / m;\n    a %= m, b %= m;\n    x = Monoid::op(x, monoid_pow<Monoid>(y,\
    \ p));\n    pre = Monoid::op(pre, monoid_pow<Monoid>(y, q));\n    c -= (p * N\
    \ + q);\n    if (c == 0) break;\n    const U d = (m * c - b - 1) / a + 1;\n  \
    \  suf = Monoid::op(y, Monoid::op(monoid_pow<Monoid>(x, N - d), suf));\n    b\
    \ = m - b - 1 + a, N = c - 1, c = d;\n    swap(m, a), swap(x, y);\n  }\n  x =\
    \ monoid_pow<Monoid>(x, N);\n  return Monoid::op(Monoid::op(pre, x), suf);\n}\n\
    #line 2 \"alg/monoid/monoid_for_floor_sum.hpp\"\n// sum i^k1floor^k2: floor path\
    \ \u3067 (x,y) \u304B\u3089 x \u65B9\u5411\u306B\u9032\u3080\u3068\u304D\u306B\
    \ x^k1y^k2 \u3092\u8DB3\u3059\ntemplate <typename T, int K1, int K2>\nstruct Monoid_for_floor_sum\
    \ {\n  using ARR = array<array<T, K2 + 1>, K1 + 1>;\n  struct Data {\n    ARR\
    \ dp;\n    T dx, dy;\n  };\n\n  using value_type = Data;\n  using X = value_type;\n\
    \  static X op(X a, X b) {\n    static constexpr int n = max(K1, K2);\n    static\
    \ T comb[n + 1][n + 1];\n    if (comb[0][0] != T(1)) {\n      comb[0][0] = T(1);\n\
    \      FOR(i, n) FOR(j, i + 1) { comb[i + 1][j] += comb[i][j], comb[i + 1][j +\
    \ 1] += comb[i][j]; }\n    }\n\n    array<T, K1 + 1> pow_x;\n    array<T, K2 +\
    \ 1> pow_y;\n    pow_x[0] = 1, pow_y[0] = 1;\n    FOR(i, K1) pow_x[i + 1] = pow_x[i]\
    \ * a.dx;\n    FOR(i, K2) pow_y[i + 1] = pow_y[i] * a.dy;\n\n    // +dy\n    FOR(i,\
    \ K1 + 1) {\n      FOR_R(j, K2 + 1) {\n        T x = b.dp[i][j];\n        FOR(k,\
    \ j + 1, K2 + 1) b.dp[i][k] += comb[k][j] * pow_y[k - j] * x;\n      }\n    }\n\
    \    // +dx\n    FOR(j, K2 + 1) {\n      FOR_R(i, K1 + 1) { FOR(k, i, K1 + 1)\
    \ a.dp[k][j] += comb[k][i] * pow_x[k - i] * b.dp[i][j]; }\n    }\n\n    a.dx +=\
    \ b.dx, a.dy += b.dy;\n    return a;\n  }\n\n  static X to_x() {\n    X x = unit();\n\
    \    x.dp[0][0] = 1, x.dx = 1;\n    return x;\n  }\n  static X to_y() {\n    X\
    \ x = unit();\n    x.dy = 1;\n    return x;\n  }\n  static constexpr X unit()\
    \ { return {ARR{}, T(0), T(0)}; }\n  static constexpr bool commute = 0;\n};\n\
    #line 5 \"mod/floor_sum_of_linear_polynomial.hpp\"\n\n// \u5168\u90E8\u975E\u8CA0\
    , T \u306F\u7B54, U \u306F ax+b \u304C\u30AA\u30FC\u30D0\u30FC\u30D5\u30ED\u30FC\
    \u3057\u306A\u3044\ntemplate <typename T, int K1, int K2, typename U>\narray<array<T,\
    \ K2 + 1>, K1 + 1> floor_sum_of_linear_polynomial_nonnegative(U N, U a, U b, U\
    \ mod) {\n  static_assert(is_same_v<U, u64> || is_same_v<U, u128>);\n  assert(a\
    \ == 0 || N < (U(-1) - b) / a);\n  using Mono = Monoid_for_floor_sum<T, K1, K2>;\n\
    \  auto x = floor_monoid_product<Mono>(Mono::to_x(), Mono::to_y(), N, a, b, mod);\n\
    \  return x.dp;\n};\n\n// sum_{L<=x<R} x^i floor(ax+b,mod)^j\n// a+bx \u304C I,\
    \ U \u3067\u30AA\u30FC\u30D0\u30FC\u30D5\u30ED\u30FC\u3057\u306A\u3044\ntemplate\
    \ <typename T, int K1, int K2, typename I>\narray<array<T, K2 + 1>, K1 + 1> floor_sum_of_linear_polynomial(I\
    \ L, I R, I a, I b, I mod) {\n  static_assert(is_same_v<I, ll> || is_same_v<I,\
    \ i128>);\n  assert(L <= R && mod > 0);\n  if (a < 0) {\n    auto ANS = floor_sum_of_linear_polynomial<T,\
    \ K1, K2, I>(-R + 1, -L + 1, -a, b, mod);\n    FOR(i, K1 + 1) {\n      if (i %\
    \ 2 == 1) { FOR(j, K2 + 1) ANS[i][j] = -ANS[i][j]; }\n    }\n    return ANS;\n\
    \  }\n  assert(a >= 0);\n  I ADD_X = L;\n  I N = R - L;\n  b += a * L;\n  I ADD_Y\
    \ = floor<I>(b, mod);\n  b -= ADD_Y * mod;\n  assert(a >= 0 && b >= 0);\n\n  using\
    \ Mono = Monoid_for_floor_sum<T, K1, K2>;\n  using Data = typename Mono::Data;\n\
    \  using U = std::conditional_t<is_same_v<I, ll>, u64, u128>;\n  Data A = floor_monoid_product<Mono,\
    \ Data, U>(Mono::to_x(), Mono::to_y(), N, a, b, mod);\n  Data offset = Mono::unit();\n\
    \  offset.dx = T(ADD_X), offset.dy = T(ADD_Y);\n  A = Mono::op(offset, A);\n \
    \ return A.dp;\n};\n"
  code: "#pragma once\n\n#include \"mod/floor_monoid_product.hpp\"\n#include \"alg/monoid/monoid_for_floor_sum.hpp\"\
    \n\n// \u5168\u90E8\u975E\u8CA0, T \u306F\u7B54, U \u306F ax+b \u304C\u30AA\u30FC\
    \u30D0\u30FC\u30D5\u30ED\u30FC\u3057\u306A\u3044\ntemplate <typename T, int K1,\
    \ int K2, typename U>\narray<array<T, K2 + 1>, K1 + 1> floor_sum_of_linear_polynomial_nonnegative(U\
    \ N, U a, U b, U mod) {\n  static_assert(is_same_v<U, u64> || is_same_v<U, u128>);\n\
    \  assert(a == 0 || N < (U(-1) - b) / a);\n  using Mono = Monoid_for_floor_sum<T,\
    \ K1, K2>;\n  auto x = floor_monoid_product<Mono>(Mono::to_x(), Mono::to_y(),\
    \ N, a, b, mod);\n  return x.dp;\n};\n\n// sum_{L<=x<R} x^i floor(ax+b,mod)^j\n\
    // a+bx \u304C I, U \u3067\u30AA\u30FC\u30D0\u30FC\u30D5\u30ED\u30FC\u3057\u306A\
    \u3044\ntemplate <typename T, int K1, int K2, typename I>\narray<array<T, K2 +\
    \ 1>, K1 + 1> floor_sum_of_linear_polynomial(I L, I R, I a, I b, I mod) {\n  static_assert(is_same_v<I,\
    \ ll> || is_same_v<I, i128>);\n  assert(L <= R && mod > 0);\n  if (a < 0) {\n\
    \    auto ANS = floor_sum_of_linear_polynomial<T, K1, K2, I>(-R + 1, -L + 1, -a,\
    \ b, mod);\n    FOR(i, K1 + 1) {\n      if (i % 2 == 1) { FOR(j, K2 + 1) ANS[i][j]\
    \ = -ANS[i][j]; }\n    }\n    return ANS;\n  }\n  assert(a >= 0);\n  I ADD_X =\
    \ L;\n  I N = R - L;\n  b += a * L;\n  I ADD_Y = floor<I>(b, mod);\n  b -= ADD_Y\
    \ * mod;\n  assert(a >= 0 && b >= 0);\n\n  using Mono = Monoid_for_floor_sum<T,\
    \ K1, K2>;\n  using Data = typename Mono::Data;\n  using U = std::conditional_t<is_same_v<I,\
    \ ll>, u64, u128>;\n  Data A = floor_monoid_product<Mono, Data, U>(Mono::to_x(),\
    \ Mono::to_y(), N, a, b, mod);\n  Data offset = Mono::unit();\n  offset.dx = T(ADD_X),\
    \ offset.dy = T(ADD_Y);\n  A = Mono::op(offset, A);\n  return A.dp;\n};\n"
  dependsOn:
  - mod/floor_monoid_product.hpp
  - alg/monoid_pow.hpp
  - alg/monoid/monoid_for_floor_sum.hpp
  isVerificationFile: false
  path: mod/floor_sum_of_linear_polynomial.hpp
  requiredBy:
  - convex/lattice_point_sum_polynomial.hpp
  - convex/lattice_point_sum_polynomial_pq.hpp
  timestamp: '2025-02-12 14:27:42+09:00'
  verificationStatus: LIBRARY_SOME_WA
  verifiedWith:
  - test/3_yukicoder/2362.test.cpp
  - test/2_library_checker/number_theory/sum_of_floor_of_linear_2.test.cpp
  - test/1_mytest/lattice_point_sum_polynomial.test.cpp
  - test/1_mytest/lattice_point_sum_polynomial_pq.test.cpp
  - test/1_mytest/floor_sum_of_polynomial.test.cpp
documentation_of: mod/floor_sum_of_linear_polynomial.hpp
layout: document
redirect_from:
- /library/mod/floor_sum_of_linear_polynomial.hpp
- /library/mod/floor_sum_of_linear_polynomial.hpp.html
title: mod/floor_sum_of_linear_polynomial.hpp
---
