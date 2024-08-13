---
data:
  _extendedDependsOn:
  - icon: ':x:'
    path: alg/monoid/monoid_for_floor_sum.hpp
    title: alg/monoid/monoid_for_floor_sum.hpp
  - icon: ':question:'
    path: alg/monoid_pow.hpp
    title: alg/monoid_pow.hpp
  - icon: ':x:'
    path: mod/floor_monoid_product.hpp
    title: mod/floor_monoid_product.hpp
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':x:'
    path: test/library_checker/math/sum_of_floor_of_linear_2.test.cpp
    title: test/library_checker/math/sum_of_floor_of_linear_2.test.cpp
  - icon: ':x:'
    path: test/mytest/floor_sum_of_polynomial.test.cpp
    title: test/mytest/floor_sum_of_polynomial.test.cpp
  - icon: ':x:'
    path: test/yukicoder/2362.test.cpp
    title: test/yukicoder/2362.test.cpp
  _isVerificationFailed: true
  _pathExtension: hpp
  _verificationStatusIcon: ':x:'
  attributes:
    links: []
  bundledCode: "#line 1 \"mod/floor_sum_of_linear_polynomial.hpp\"\n\n#line 2 \"alg/monoid_pow.hpp\"\
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
    \    return res;\n  }\n}\n#line 2 \"mod/floor_monoid_product.hpp\"\n\n// https://yukicoder.me/submissions/883884\n\
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
    #line 1 \"alg/monoid/monoid_for_floor_sum.hpp\"\n\n// sum i^kfloor: floor path\
    \ \u3067 (x,y) \u304B\u3089 x \u65B9\u5411\u306B\u9032\u3080\u3068\u304D\u306B\
    \ x^ky \u3092\u8DB3\u3059\ntemplate <typename T, int K>\nstruct Monoid_for_floor_sum\
    \ {\n  using ARR = array<array<T, K + 1>, 2>;\n  struct Data {\n    ARR dp;\n\
    \    T dx, dy;\n  };\n\n  using value_type = Data;\n  using X = value_type;\n\
    \  static X op(X a, X b) {\n    static T comb[K + 1][K + 1];\n    if (comb[0][0]\
    \ != T(1)) {\n      comb[0][0] = T(1);\n      FOR(i, K) FOR(j, i + 1) {\n    \
    \    comb[i + 1][j] += comb[i][j], comb[i + 1][j + 1] += comb[i][j];\n      }\n\
    \    }\n    T pow = 1;\n    FOR(j, K + 1) {\n      FOR(i, K - j + 1) {\n     \
    \   T x = comb[i + j][i];\n        a.dp[0][i + j] += b.dp[0][i] * pow * x;\n \
    \       a.dp[1][i + j] += (b.dp[0][i] * a.dy + b.dp[1][i]) * pow * x;\n      }\n\
    \      pow *= a.dx;\n    }\n    a.dx += b.dx, a.dy += b.dy;\n    return a;\n \
    \ }\n\n  static X to_x() {\n    X x = unit();\n    x.dp[0][0] = 1, x.dx = 1;\n\
    \    return x;\n  }\n  static X to_y() {\n    X x = unit();\n    x.dy = 1;\n \
    \   return x;\n  }\n  static constexpr X unit() { return {ARR{}, T(0), T(0)};\
    \ }\n  static constexpr bool commute = 0;\n};\n#line 4 \"mod/floor_sum_of_linear_polynomial.hpp\"\
    \n\n// sum(i^k*floor) for k=0,1,...,K\ntemplate <typename T, int K, typename U>\n\
    array<T, K + 1> floor_sum_of_linear_polynomial(U N, U a, U b, U mod) {\n  static_assert(is_same_v<U,\
    \ u64> || is_same_v<U, u128>);\n  assert(a == 0 || N < (U(-1) - b) / a);\n  using\
    \ Mono = Monoid_for_floor_sum<T, K>;\n  auto z = floor_monoid_product<Mono>(Mono::to_x(),\
    \ Mono::to_y(), N, a, b, mod);\n  return z.dp[1];\n};\n"
  code: "\n#include \"mod/floor_monoid_product.hpp\"\n#include \"alg/monoid/monoid_for_floor_sum.hpp\"\
    \n\n// sum(i^k*floor) for k=0,1,...,K\ntemplate <typename T, int K, typename U>\n\
    array<T, K + 1> floor_sum_of_linear_polynomial(U N, U a, U b, U mod) {\n  static_assert(is_same_v<U,\
    \ u64> || is_same_v<U, u128>);\n  assert(a == 0 || N < (U(-1) - b) / a);\n  using\
    \ Mono = Monoid_for_floor_sum<T, K>;\n  auto z = floor_monoid_product<Mono>(Mono::to_x(),\
    \ Mono::to_y(), N, a, b, mod);\n  return z.dp[1];\n};"
  dependsOn:
  - mod/floor_monoid_product.hpp
  - alg/monoid_pow.hpp
  - alg/monoid/monoid_for_floor_sum.hpp
  isVerificationFile: false
  path: mod/floor_sum_of_linear_polynomial.hpp
  requiredBy: []
  timestamp: '2024-01-23 03:59:43+09:00'
  verificationStatus: LIBRARY_ALL_WA
  verifiedWith:
  - test/yukicoder/2362.test.cpp
  - test/mytest/floor_sum_of_polynomial.test.cpp
  - test/library_checker/math/sum_of_floor_of_linear_2.test.cpp
documentation_of: mod/floor_sum_of_linear_polynomial.hpp
layout: document
redirect_from:
- /library/mod/floor_sum_of_linear_polynomial.hpp
- /library/mod/floor_sum_of_linear_polynomial.hpp.html
title: mod/floor_sum_of_linear_polynomial.hpp
---
