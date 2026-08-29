---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/3_yukicoder/2890.test.cpp
    title: test/3_yukicoder/2890.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 1 \"alg/monoid/add_chmin_chmax_with_cost.hpp\"\ntemplate <typename\
    \ T>\nstruct Monoid_Add_Chmin_Chmax_with_Cost {\n  // clamp(x+a,l,r) \u306F (a,0,0,l-a,r-a)\
    \ \u3068\u3059\u308B\n  // eval_cost(f,x) \u3059\u308B\u3068\u3001add, chmax,\
    \ chmin \u306B\u3088\u308B x \u306E\u5909\u5316\u91CF\u304C\u5165\u308B\n  struct\
    \ F {\n    T a, b, c, x1, x2;\n    F(T a = 0, T b = 0, T c = 0, T x1 = -infty<T>,\
    \ T x2 = infty<T>)\n        : a(a), b(b), c(c), x1(x1), x2(x2) {}\n    // add,\
    \ chmax, chmin\n    tuple<T, T, T> eval_cost(T x) {\n      return {a, b + max<T>(x1\
    \ - x, 0), c + max<T>(x - x2, 0)};\n    }\n    T eval(T x) {\n      auto [add,\
    \ ma, mi] = eval_cost(x);\n      return x + add + ma - mi;\n    }\n  };\n  using\
    \ value_type = F;\n  using X = value_type;\n  static X op(X L, X R) {\n    X M;\n\
    \    T x1 = L.x1, x2 = L.x2;\n    T y1 = R.x1 - L.a - L.b + L.c, y2 = R.x2 - L.a\
    \ - L.b + L.c;\n    M.a = L.a + R.a;\n    if (y1 < x1) M.b = L.b + R.b, M.x1 =\
    \ x1;\n    elif (y1 < x2) M.b = L.b + R.b, M.x1 = y1;\n    else M.b = L.b + R.b\
    \ + y1 - x2, M.x1 = x2;\n    if (y2 < x1) M.c = L.c + R.c + x1 - y2, M.x2 = x1;\n\
    \    elif (y2 < x2) M.c = L.c + R.c, M.x2 = y2;\n    else M.c = L.c + R.c, M.x2\
    \ = x2;\n    return M;\n  }\n\n  static constexpr X unit() { return F(); }\n \
    \ static constexpr bool commute = 0;\n};\n"
  code: "template <typename T>\nstruct Monoid_Add_Chmin_Chmax_with_Cost {\n  // clamp(x+a,l,r)\
    \ \u306F (a,0,0,l-a,r-a) \u3068\u3059\u308B\n  // eval_cost(f,x) \u3059\u308B\u3068\
    \u3001add, chmax, chmin \u306B\u3088\u308B x \u306E\u5909\u5316\u91CF\u304C\u5165\
    \u308B\n  struct F {\n    T a, b, c, x1, x2;\n    F(T a = 0, T b = 0, T c = 0,\
    \ T x1 = -infty<T>, T x2 = infty<T>)\n        : a(a), b(b), c(c), x1(x1), x2(x2)\
    \ {}\n    // add, chmax, chmin\n    tuple<T, T, T> eval_cost(T x) {\n      return\
    \ {a, b + max<T>(x1 - x, 0), c + max<T>(x - x2, 0)};\n    }\n    T eval(T x) {\n\
    \      auto [add, ma, mi] = eval_cost(x);\n      return x + add + ma - mi;\n \
    \   }\n  };\n  using value_type = F;\n  using X = value_type;\n  static X op(X\
    \ L, X R) {\n    X M;\n    T x1 = L.x1, x2 = L.x2;\n    T y1 = R.x1 - L.a - L.b\
    \ + L.c, y2 = R.x2 - L.a - L.b + L.c;\n    M.a = L.a + R.a;\n    if (y1 < x1)\
    \ M.b = L.b + R.b, M.x1 = x1;\n    elif (y1 < x2) M.b = L.b + R.b, M.x1 = y1;\n\
    \    else M.b = L.b + R.b + y1 - x2, M.x1 = x2;\n    if (y2 < x1) M.c = L.c +\
    \ R.c + x1 - y2, M.x2 = x1;\n    elif (y2 < x2) M.c = L.c + R.c, M.x2 = y2;\n\
    \    else M.c = L.c + R.c, M.x2 = x2;\n    return M;\n  }\n\n  static constexpr\
    \ X unit() { return F(); }\n  static constexpr bool commute = 0;\n};\n"
  dependsOn: []
  isVerificationFile: false
  path: alg/monoid/add_chmin_chmax_with_cost.hpp
  requiredBy: []
  timestamp: '2026-08-17 17:13:54+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/3_yukicoder/2890.test.cpp
documentation_of: alg/monoid/add_chmin_chmax_with_cost.hpp
layout: document
redirect_from:
- /library/alg/monoid/add_chmin_chmax_with_cost.hpp
- /library/alg/monoid/add_chmin_chmax_with_cost.hpp.html
title: alg/monoid/add_chmin_chmax_with_cost.hpp
---
