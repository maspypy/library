---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':warning:'
  attributes:
    links: []
  bundledCode: "#line 1 \"alg/monoid/add_divide.hpp\"\n\n// x -> (x+a)/b+c\n// \u5408\
    \u6210\u306E\u3044\u305F\u308B\u3068\u3053\u308D\u3067 infty<ll>/2 \u4EE5\u4E0A\
    \u306B\u306A\u3089\u306A\u3044\u3053\u3068\u3092\u4EEE\u5B9A. \u304F\u3089\u3044\
    \u3067\u5927\u4E08\u592B\u3060\u3068\u601D\u3046.\nstruct Monoid_Add_Divide {\n\
    \  using value_type = tuple<ll, ll, ll>;\n  using X = value_type;\n  static X\
    \ op(X L, X R) {\n    auto [a1, b1, c1] = L;\n    auto [a2, b2, c2] = R;\n   \
    \ auto [q, r] = divmod<ll>(c1 + a2, b2);\n    i128 a = a1 + i128(b1) * r;\n  \
    \  i128 b = i128(b1) * b2;\n    ll c = q + c2;\n    while (a >= b) a -= b, c +=\
    \ 1;\n    assert(0 <= a && a < b);\n    if (b < infty<ll>) return {a, b, c};\n\
    \    i128 t = b - a;\n    if (a <= infty<ll> / 2) return {a, infty<ll>, c};\n\
    \    if (t <= infty<ll> / 2) return {infty<ll> - t, infty<ll>, c};\n    return\
    \ {infty<ll> / 2, infty<ll>, c};\n  }\n  static X add(ll x) { return {x, 1, 0};\
    \ }\n  static X divide(ll x) { return {0, 1, x}; }\n\n  static ll eval(X f, ll\
    \ x) {\n    auto [a, b, c] = f;\n    return floor<ll>(x + a, b) + c;\n  }\n\n\
    \  static constexpr X unit() { return {0, 1, 0}; }\n  static constexpr bool commute\
    \ = 0;\n};\n"
  code: "\n// x -> (x+a)/b+c\n// \u5408\u6210\u306E\u3044\u305F\u308B\u3068\u3053\u308D\
    \u3067 infty<ll>/2 \u4EE5\u4E0A\u306B\u306A\u3089\u306A\u3044\u3053\u3068\u3092\
    \u4EEE\u5B9A. \u304F\u3089\u3044\u3067\u5927\u4E08\u592B\u3060\u3068\u601D\u3046\
    .\nstruct Monoid_Add_Divide {\n  using value_type = tuple<ll, ll, ll>;\n  using\
    \ X = value_type;\n  static X op(X L, X R) {\n    auto [a1, b1, c1] = L;\n   \
    \ auto [a2, b2, c2] = R;\n    auto [q, r] = divmod<ll>(c1 + a2, b2);\n    i128\
    \ a = a1 + i128(b1) * r;\n    i128 b = i128(b1) * b2;\n    ll c = q + c2;\n  \
    \  while (a >= b) a -= b, c += 1;\n    assert(0 <= a && a < b);\n    if (b < infty<ll>)\
    \ return {a, b, c};\n    i128 t = b - a;\n    if (a <= infty<ll> / 2) return {a,\
    \ infty<ll>, c};\n    if (t <= infty<ll> / 2) return {infty<ll> - t, infty<ll>,\
    \ c};\n    return {infty<ll> / 2, infty<ll>, c};\n  }\n  static X add(ll x) {\
    \ return {x, 1, 0}; }\n  static X divide(ll x) { return {0, 1, x}; }\n\n  static\
    \ ll eval(X f, ll x) {\n    auto [a, b, c] = f;\n    return floor<ll>(x + a, b)\
    \ + c;\n  }\n\n  static constexpr X unit() { return {0, 1, 0}; }\n  static constexpr\
    \ bool commute = 0;\n};"
  dependsOn: []
  isVerificationFile: false
  path: alg/monoid/add_divide.hpp
  requiredBy: []
  timestamp: '2025-04-06 22:12:23+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: alg/monoid/add_divide.hpp
layout: document
redirect_from:
- /library/alg/monoid/add_divide.hpp
- /library/alg/monoid/add_divide.hpp.html
title: alg/monoid/add_divide.hpp
---
