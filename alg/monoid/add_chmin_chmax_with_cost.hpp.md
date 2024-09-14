---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':x:'
    path: test/3_yukicoder/2890.test.cpp
    title: test/3_yukicoder/2890.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/5_atcoder/abc365f.test.cpp
    title: test/5_atcoder/abc365f.test.cpp
  _isVerificationFailed: true
  _pathExtension: hpp
  _verificationStatusIcon: ':question:'
  attributes:
    links: []
  bundledCode: "#line 1 \"alg/monoid/add_chmin_chmax_with_cost.hpp\"\n\ntemplate <typename\
    \ T>\nstruct Monoid_Add_Chmin_Chmax_With_Cost {\n  // x \u3092\u3046\u3064\u3057\
    \u305F\u3068\u304D, add \u306B\u3088\u308B\u5909\u5316\u91CF\u304C a\n  // chmax\
    \ \u306B\u3088\u308B\u5897\u52A0\u91CF\u304C b + max(x1-x,0)\n  // chmin \u306B\
    \u3088\u308B\u6E1B\u5C11\u91CF\u304C c + max(x-x2,0)\n  struct F {\n    T a, b,\
    \ c, x1, x2;\n    F(T a = 0, T b = 0, T c = 0, T x1 = -infty<T>, T x2 = infty<T>)\
    \ : a(a), b(b), c(c), x1(x1), x2(x2) {}\n    // add, chmax, chmin\n    tuple<T,\
    \ T, T> eval_cost(T x) { return {a, b + max<T>(x1 - x, 0), c + max<T>(x - x2,\
    \ 0)}; }\n    T eval(T x) {\n      auto [add, ma, mi] = eval_cost(x);\n      return\
    \ x + add + ma - mi;\n    }\n  };\n  using value_type = F;\n  using X = value_type;\n\
    \  static X op(X L, X R) {\n    X M;\n    T x1 = L.x1, x2 = L.x2;\n    T y1 =\
    \ R.x1 - L.a - L.b + L.c, y2 = R.x2 - L.a - L.b + L.c;\n    M.a = L.a + R.a;\n\
    \    if (y1 < x1) M.b = L.b + R.b, M.x1 = x1;\n    elif (y1 < x2) M.b = L.b +\
    \ R.b, M.x1 = y1;\n    else M.b = L.b + R.b + y1 - x2, M.x1 = x2;\n    if (y2\
    \ < x1) M.c = L.c + R.c + x1 - y2, M.x2 = x1;\n    elif (y2 < x2) M.c = L.c +\
    \ R.c, M.x2 = y2;\n    else M.c = L.c + R.c, M.x2 = x2;\n    return M;\n  }\n\n\
    \  static constexpr X unit() { return F(); }\n  static constexpr bool commute\
    \ = 0;\n};\n"
  code: "\ntemplate <typename T>\nstruct Monoid_Add_Chmin_Chmax_With_Cost {\n  //\
    \ x \u3092\u3046\u3064\u3057\u305F\u3068\u304D, add \u306B\u3088\u308B\u5909\u5316\
    \u91CF\u304C a\n  // chmax \u306B\u3088\u308B\u5897\u52A0\u91CF\u304C b + max(x1-x,0)\n\
    \  // chmin \u306B\u3088\u308B\u6E1B\u5C11\u91CF\u304C c + max(x-x2,0)\n  struct\
    \ F {\n    T a, b, c, x1, x2;\n    F(T a = 0, T b = 0, T c = 0, T x1 = -infty<T>,\
    \ T x2 = infty<T>) : a(a), b(b), c(c), x1(x1), x2(x2) {}\n    // add, chmax, chmin\n\
    \    tuple<T, T, T> eval_cost(T x) { return {a, b + max<T>(x1 - x, 0), c + max<T>(x\
    \ - x2, 0)}; }\n    T eval(T x) {\n      auto [add, ma, mi] = eval_cost(x);\n\
    \      return x + add + ma - mi;\n    }\n  };\n  using value_type = F;\n  using\
    \ X = value_type;\n  static X op(X L, X R) {\n    X M;\n    T x1 = L.x1, x2 =\
    \ L.x2;\n    T y1 = R.x1 - L.a - L.b + L.c, y2 = R.x2 - L.a - L.b + L.c;\n   \
    \ M.a = L.a + R.a;\n    if (y1 < x1) M.b = L.b + R.b, M.x1 = x1;\n    elif (y1\
    \ < x2) M.b = L.b + R.b, M.x1 = y1;\n    else M.b = L.b + R.b + y1 - x2, M.x1\
    \ = x2;\n    if (y2 < x1) M.c = L.c + R.c + x1 - y2, M.x2 = x1;\n    elif (y2\
    \ < x2) M.c = L.c + R.c, M.x2 = y2;\n    else M.c = L.c + R.c, M.x2 = x2;\n  \
    \  return M;\n  }\n\n  static constexpr X unit() { return F(); }\n  static constexpr\
    \ bool commute = 0;\n};\n"
  dependsOn: []
  isVerificationFile: false
  path: alg/monoid/add_chmin_chmax_with_cost.hpp
  requiredBy: []
  timestamp: '2024-08-28 14:05:49+09:00'
  verificationStatus: LIBRARY_SOME_WA
  verifiedWith:
  - test/3_yukicoder/2890.test.cpp
  - test/5_atcoder/abc365f.test.cpp
documentation_of: alg/monoid/add_chmin_chmax_with_cost.hpp
layout: document
redirect_from:
- /library/alg/monoid/add_chmin_chmax_with_cost.hpp
- /library/alg/monoid/add_chmin_chmax_with_cost.hpp.html
title: alg/monoid/add_chmin_chmax_with_cost.hpp
---
