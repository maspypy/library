---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':x:'
    path: test/3_yukicoder/2890.test.cpp
    title: test/3_yukicoder/2890.test.cpp
  _isVerificationFailed: true
  _pathExtension: hpp
  _verificationStatusIcon: ':x:'
  attributes:
    links: []
  bundledCode: "#line 1 \"alg/monoid/add_chmin_chmax_with_cost.hpp\"\n// (L,R,a,b,c)\n\
    // position = clamp(x,L,R) + a\n// chmax_cost = b + max(L - x, 0)\n// chmin_cost\
    \ = c + max(x - R, 0)\ntemplate <typename T>\nstruct Monoid_Add_Chmin_Chmax_with_Cost\
    \ {\n  struct S {\n    T L, R, a, b, c;\n  };\n  using value_type = S;\n  using\
    \ X = value_type;\n\n  // Return {position, chmax_cost, chmin_cost}\n  static\
    \ tuple<T, T, T> eval(const X& f, T x) {\n    auto [L, R, a, b, c] = f;\n    T\
    \ chmax_cost = b + max<T>(L - x, 0);\n    T chmin_cost = c + max<T>(x - R, 0);\n\
    \    return {clamp(x, L, R) + a, chmax_cost, chmin_cost};\n  }\n\n  // g(f(x))\n\
    \  static X op(const X& f, const X& g) {\n    auto [Lf, Rf, af, bf, cf] = f;\n\
    \    auto [Lg, Rg, ag, bg, cg] = g;\n    T L = clamp(Lg - af, Lf, Rf);\n    T\
    \ R = clamp(Rg - af, Lf, Rf);\n    T y_at_L = get<0>(eval(f, L));\n    T y_at_R\
    \ = get<0>(eval(f, R));\n    T b = bf + max<T>(Lf - L, 0) + bg + max<T>(Lg - y_at_L,\
    \ 0);\n    T c = cf + max<T>(R - Rf, 0) + cg + max<T>(y_at_R - Rg, 0);\n    T\
    \ a = clamp(y_at_L, Lg, Rg) + ag - L;\n    return {L, R, a, b, c};\n  }\n\n  //\
    \ x -> clamp(x + add, low, high)\n  static constexpr X add_clamp(T add, T low,\
    \ T high) {\n    return {low - add, high - add, add, 0, 0};\n  }\n  // x -> clamp(x,\
    \ low, high) + add\n  static constexpr X clamp_add(T add, T low, T high) {\n \
    \   return add_clamp(add, low + add, high + add);\n  }\n  static constexpr X id()\
    \ { return {-infty<T>, infty<T>, 0, 0, 0}; }\n  static constexpr bool commute\
    \ = false;\n};\n"
  code: "// (L,R,a,b,c)\n// position = clamp(x,L,R) + a\n// chmax_cost = b + max(L\
    \ - x, 0)\n// chmin_cost = c + max(x - R, 0)\ntemplate <typename T>\nstruct Monoid_Add_Chmin_Chmax_with_Cost\
    \ {\n  struct S {\n    T L, R, a, b, c;\n  };\n  using value_type = S;\n  using\
    \ X = value_type;\n\n  // Return {position, chmax_cost, chmin_cost}\n  static\
    \ tuple<T, T, T> eval(const X& f, T x) {\n    auto [L, R, a, b, c] = f;\n    T\
    \ chmax_cost = b + max<T>(L - x, 0);\n    T chmin_cost = c + max<T>(x - R, 0);\n\
    \    return {clamp(x, L, R) + a, chmax_cost, chmin_cost};\n  }\n\n  // g(f(x))\n\
    \  static X op(const X& f, const X& g) {\n    auto [Lf, Rf, af, bf, cf] = f;\n\
    \    auto [Lg, Rg, ag, bg, cg] = g;\n    T L = clamp(Lg - af, Lf, Rf);\n    T\
    \ R = clamp(Rg - af, Lf, Rf);\n    T y_at_L = get<0>(eval(f, L));\n    T y_at_R\
    \ = get<0>(eval(f, R));\n    T b = bf + max<T>(Lf - L, 0) + bg + max<T>(Lg - y_at_L,\
    \ 0);\n    T c = cf + max<T>(R - Rf, 0) + cg + max<T>(y_at_R - Rg, 0);\n    T\
    \ a = clamp(y_at_L, Lg, Rg) + ag - L;\n    return {L, R, a, b, c};\n  }\n\n  //\
    \ x -> clamp(x + add, low, high)\n  static constexpr X add_clamp(T add, T low,\
    \ T high) {\n    return {low - add, high - add, add, 0, 0};\n  }\n  // x -> clamp(x,\
    \ low, high) + add\n  static constexpr X clamp_add(T add, T low, T high) {\n \
    \   return add_clamp(add, low + add, high + add);\n  }\n  static constexpr X id()\
    \ { return {-infty<T>, infty<T>, 0, 0, 0}; }\n  static constexpr bool commute\
    \ = false;\n};\n"
  dependsOn: []
  isVerificationFile: false
  path: alg/monoid/add_chmin_chmax_with_cost.hpp
  requiredBy: []
  timestamp: '2026-10-14 16:39:00+09:00'
  verificationStatus: LIBRARY_ALL_WA
  verifiedWith:
  - test/3_yukicoder/2890.test.cpp
documentation_of: alg/monoid/add_chmin_chmax_with_cost.hpp
layout: document
redirect_from:
- /library/alg/monoid/add_chmin_chmax_with_cost.hpp
- /library/alg/monoid/add_chmin_chmax_with_cost.hpp.html
title: alg/monoid/add_chmin_chmax_with_cost.hpp
---
