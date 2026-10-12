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
  bundledCode: "#line 1 \"alg/monoid/add_chmin_chmax_with_cost.hpp\"\n\n/*\nposition:\n\
    x<=L: L+a\nL<=x<=R:x+a\nR<=x: R+a\n\ncost:\nx<=L: b-(L-x)\nL<=x<=R: b\nR<=x: b-(x-R)\n\
    */\n\nstruct Monoid_Add_Chmin_Chmax_with_Cost {\n  struct S {\n    ll L, R, a,\
    \ b;\n  };\n  using value_type = S;\n  using X = value_type;\n  static X op(const\
    \ X& f, const X& g) {\n    // g(f(x))\n    ll l = clamp(g.L - f.a, f.L, f.R);\n\
    \    ll r = clamp(g.R - f.a, f.L, f.R);\n    ll y = clamp(l + f.a, g.L, g.R);\n\
    \    ll a = y + g.a - l;\n    ll b = f.b + g.b - abs(l + f.a - y);\n    return\
    \ {l, r, a, b};\n  }\n  static constexpr X id() { return {-infty<ll>, infty<ll>,\
    \ 0, 0}; }\n  static constexpr bool commute = 0;\n  // return: {position, cost}\n\
    \  static pair<ll, ll> eval(const S& f, ll x) {\n    auto [L, R, a, b] = f;\n\
    \    if (x <= L) {\n      return {L + a, b - (L - x)};\n    }\n    elif (x <=\
    \ R) { return {x + a, b}; }\n    else {\n      return {R + a, b - (x - R)};\n\
    \    }\n  }\n};\n"
  code: "\n/*\nposition:\nx<=L: L+a\nL<=x<=R:x+a\nR<=x: R+a\n\ncost:\nx<=L: b-(L-x)\n\
    L<=x<=R: b\nR<=x: b-(x-R)\n*/\n\nstruct Monoid_Add_Chmin_Chmax_with_Cost {\n \
    \ struct S {\n    ll L, R, a, b;\n  };\n  using value_type = S;\n  using X = value_type;\n\
    \  static X op(const X& f, const X& g) {\n    // g(f(x))\n    ll l = clamp(g.L\
    \ - f.a, f.L, f.R);\n    ll r = clamp(g.R - f.a, f.L, f.R);\n    ll y = clamp(l\
    \ + f.a, g.L, g.R);\n    ll a = y + g.a - l;\n    ll b = f.b + g.b - abs(l + f.a\
    \ - y);\n    return {l, r, a, b};\n  }\n  static constexpr X id() { return {-infty<ll>,\
    \ infty<ll>, 0, 0}; }\n  static constexpr bool commute = 0;\n  // return: {position,\
    \ cost}\n  static pair<ll, ll> eval(const S& f, ll x) {\n    auto [L, R, a, b]\
    \ = f;\n    if (x <= L) {\n      return {L + a, b - (L - x)};\n    }\n    elif\
    \ (x <= R) { return {x + a, b}; }\n    else {\n      return {R + a, b - (x - R)};\n\
    \    }\n  }\n};"
  dependsOn: []
  isVerificationFile: false
  path: alg/monoid/add_chmin_chmax_with_cost.hpp
  requiredBy: []
  timestamp: '2026-10-13 07:15:02+09:00'
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
