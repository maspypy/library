---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: alg/monoid_pow.hpp
    title: alg/monoid_pow.hpp
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
  - icon: ':heavy_check_mark:'
    path: mod/floor_sum_of_linear_polynomial_pq.hpp
    title: mod/floor_sum_of_linear_polynomial_pq.hpp
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/1_mytest/floor_sum_of_polynomial.test.cpp
    title: test/1_mytest/floor_sum_of_polynomial.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/1_mytest/floor_sum_of_polynomial_pq.test.cpp
    title: test/1_mytest/floor_sum_of_polynomial_pq.test.cpp
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
    links:
    - https://qoj.ac/contest/1411/problem/7620
    - https://yukicoder.me/submissions/883884
  bundledCode: "#line 2 \"alg/monoid_pow.hpp\"\n\n// chat gpt\ntemplate <typename\
    \ U, typename Arg1, typename Arg2>\nstruct has_power_method {\nprivate:\n  //\
    \ \u30D8\u30EB\u30D1\u30FC\u95A2\u6570\u306E\u5B9F\u88C5\n  template <typename\
    \ V, typename A1, typename A2>\n  static auto check(int)\n      -> decltype(std::declval<V>().power(std::declval<A1>(),\n\
    \                                          std::declval<A2>()),\n            \
    \      std::true_type{});\n  template <typename, typename, typename>\n  static\
    \ auto check(...) -> std::false_type;\n\npublic:\n  // \u30E1\u30BD\u30C3\u30C9\
    \u306E\u6709\u7121\u3092\u8868\u3059\u578B\n  static constexpr bool value = decltype(check<U,\
    \ Arg1, Arg2>(0))::value;\n};\n\ntemplate <typename Monoid>\ntypename Monoid::X\
    \ monoid_pow(typename Monoid::X x, ll exp) {\n  using X = typename Monoid::X;\n\
    \  if constexpr (has_power_method<Monoid, X, ll>::value) {\n    return Monoid::power(x,\
    \ exp);\n  } else {\n    assert(exp >= 0);\n    X res = Monoid::unit();\n    while\
    \ (exp) {\n      if (exp & 1) res = Monoid::op(res, x);\n      x = Monoid::op(x,\
    \ x);\n      exp >>= 1;\n    }\n    return res;\n  }\n}\n#line 3 \"mod/floor_monoid_product.hpp\"\
    \n\n// https://yukicoder.me/submissions/883884\n// https://qoj.ac/contest/1411/problem/7620\n\
    // U \u306F\u7BC4\u56F2\u5185\u3067 ax+b \u304C\u30AA\u30FC\u30D0\u30FC\u30D5\u30ED\
    \u30FC\u3057\u306A\u3044\u7A0B\u5EA6\n// yyy x yyyy x ... yyy x yyy (x \u3092\
    \ N \u500B)\n// k \u500B\u76EE\u306E x \u307E\u3067\u306B floor(ak+b,m) \u500B\
    \u306E y \u304C\u3042\u308B\n// my<=ax+b \u306B\u304A\u3051\u308B lattice path\
    \ \u306B\u304A\u3051\u308B\u8FBA\u306E\u5217\u3068\u898B\u306A\u305B\u308B\ntemplate\
    \ <typename Monoid, typename X, typename U>\nX floor_monoid_product(X x, X y,\
    \ U N, U a, U b, U m) {\n  U c = (a * N + b) / m;\n  X pre = Monoid::unit(), suf\
    \ = Monoid::unit();\n  while (1) {\n    const U p = a / m, q = b / m;\n    a %=\
    \ m, b %= m;\n    x = Monoid::op(x, monoid_pow<Monoid>(y, p));\n    pre = Monoid::op(pre,\
    \ monoid_pow<Monoid>(y, q));\n    c -= (p * N + q);\n    if (c == 0) break;\n\
    \    const U d = (m * c - b - 1) / a + 1;\n    suf = Monoid::op(y, Monoid::op(monoid_pow<Monoid>(x,\
    \ N - d), suf));\n    b = m - b - 1 + a, N = c - 1, c = d;\n    swap(m, a), swap(x,\
    \ y);\n  }\n  x = monoid_pow<Monoid>(x, N);\n  return Monoid::op(Monoid::op(pre,\
    \ x), suf);\n}\n"
  code: "#pragma once\n#include \"alg/monoid_pow.hpp\"\n\n// https://yukicoder.me/submissions/883884\n\
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
    \ monoid_pow<Monoid>(x, N);\n  return Monoid::op(Monoid::op(pre, x), suf);\n}"
  dependsOn:
  - alg/monoid_pow.hpp
  isVerificationFile: false
  path: mod/floor_monoid_product.hpp
  requiredBy:
  - mod/floor_sum_of_linear_polynomial.hpp
  - mod/floor_sum_of_linear_polynomial_pq.hpp
  - convex/lattice_point_sum_polynomial_pq.hpp
  - convex/lattice_point_sum_polynomial.hpp
  timestamp: '2025-02-12 14:27:42+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/3_yukicoder/2362.test.cpp
  - test/2_library_checker/number_theory/sum_of_floor_of_linear_2.test.cpp
  - test/1_mytest/lattice_point_sum_polynomial.test.cpp
  - test/1_mytest/floor_sum_of_polynomial_pq.test.cpp
  - test/1_mytest/lattice_point_sum_polynomial_pq.test.cpp
  - test/1_mytest/floor_sum_of_polynomial.test.cpp
documentation_of: mod/floor_monoid_product.hpp
layout: document
redirect_from:
- /library/mod/floor_monoid_product.hpp
- /library/mod/floor_monoid_product.hpp.html
title: mod/floor_monoid_product.hpp
---
