---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: alg/monoid_pow.hpp
    title: alg/monoid_pow.hpp
  _extendedRequiredBy:
  - icon: ':heavy_check_mark:'
    path: mod/floor_sum_of_linear_polynomial.hpp
    title: mod/floor_sum_of_linear_polynomial.hpp
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/library_checker/math/sum_of_floor_of_linear_2.test.cpp
    title: test/library_checker/math/sum_of_floor_of_linear_2.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/mytest/floor_sum_of_polynomial.test.cpp
    title: test/mytest/floor_sum_of_polynomial.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/yukicoder/2362.test.cpp
    title: test/yukicoder/2362.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links:
    - https://qoj.ac/contest/1411/problem/7620
    - https://yukicoder.me/submissions/883884
  bundledCode: "#line 2 \"alg/monoid_pow.hpp\"\n\ntemplate <typename Monoid>\ntypename\
    \ Monoid::X monoid_pow(typename Monoid::X x, u64 exp) {\n  using X = typename\
    \ Monoid::X;\n  assert(exp >= 0);\n  X res = Monoid::unit();\n  while (exp) {\n\
    \    if (exp & 1) res = Monoid::op(res, x);\n    x = Monoid::op(x, x);\n    exp\
    \ >>= 1;\n  }\n  return res;\n}\n#line 2 \"mod/floor_monoid_product.hpp\"\n\n\
    // https://yukicoder.me/submissions/883884\n// https://qoj.ac/contest/1411/problem/7620\n\
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
  code: "#include \"alg/monoid_pow.hpp\"\n\n// https://yukicoder.me/submissions/883884\n\
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
  timestamp: '2023-12-09 23:29:41+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/library_checker/math/sum_of_floor_of_linear_2.test.cpp
  - test/mytest/floor_sum_of_polynomial.test.cpp
  - test/yukicoder/2362.test.cpp
documentation_of: mod/floor_monoid_product.hpp
layout: document
redirect_from:
- /library/mod/floor_monoid_product.hpp
- /library/mod/floor_monoid_product.hpp.html
title: mod/floor_monoid_product.hpp
---
