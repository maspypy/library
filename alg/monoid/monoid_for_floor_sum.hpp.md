---
data:
  _extendedDependsOn: []
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
    links: []
  bundledCode: "#line 1 \"alg/monoid/monoid_for_floor_sum.hpp\"\n\n// sum i^kfloor:\
    \ floor path \u3067 (x,y) \u304B\u3089 x \u65B9\u5411\u306B\u9032\u3080\u3068\u304D\
    \u306B x^ky \u3092\u8DB3\u3059\ntemplate <typename T, int K>\nstruct Monoid_for_floor_sum\
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
    \ }\n  static constexpr bool commute = 0;\n};\n"
  code: "\n// sum i^kfloor: floor path \u3067 (x,y) \u304B\u3089 x \u65B9\u5411\u306B\
    \u9032\u3080\u3068\u304D\u306B x^ky \u3092\u8DB3\u3059\ntemplate <typename T,\
    \ int K>\nstruct Monoid_for_floor_sum {\n  using ARR = array<array<T, K + 1>,\
    \ 2>;\n  struct Data {\n    ARR dp;\n    T dx, dy;\n  };\n\n  using value_type\
    \ = Data;\n  using X = value_type;\n  static X op(X a, X b) {\n    static T comb[K\
    \ + 1][K + 1];\n    if (comb[0][0] != T(1)) {\n      comb[0][0] = T(1);\n    \
    \  FOR(i, K) FOR(j, i + 1) {\n        comb[i + 1][j] += comb[i][j], comb[i + 1][j\
    \ + 1] += comb[i][j];\n      }\n    }\n    T pow = 1;\n    FOR(j, K + 1) {\n \
    \     FOR(i, K - j + 1) {\n        T x = comb[i + j][i];\n        a.dp[0][i +\
    \ j] += b.dp[0][i] * pow * x;\n        a.dp[1][i + j] += (b.dp[0][i] * a.dy +\
    \ b.dp[1][i]) * pow * x;\n      }\n      pow *= a.dx;\n    }\n    a.dx += b.dx,\
    \ a.dy += b.dy;\n    return a;\n  }\n\n  static X to_x() {\n    X x = unit();\n\
    \    x.dp[0][0] = 1, x.dx = 1;\n    return x;\n  }\n  static X to_y() {\n    X\
    \ x = unit();\n    x.dy = 1;\n    return x;\n  }\n  static constexpr X unit()\
    \ { return {ARR{}, T(0), T(0)}; }\n  static constexpr bool commute = 0;\n};"
  dependsOn: []
  isVerificationFile: false
  path: alg/monoid/monoid_for_floor_sum.hpp
  requiredBy:
  - mod/floor_sum_of_linear_polynomial.hpp
  timestamp: '2023-11-23 14:15:12+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/yukicoder/2362.test.cpp
  - test/mytest/floor_sum_of_polynomial.test.cpp
  - test/library_checker/math/sum_of_floor_of_linear_2.test.cpp
documentation_of: alg/monoid/monoid_for_floor_sum.hpp
layout: document
redirect_from:
- /library/alg/monoid/monoid_for_floor_sum.hpp
- /library/alg/monoid/monoid_for_floor_sum.hpp.html
title: alg/monoid/monoid_for_floor_sum.hpp
---
