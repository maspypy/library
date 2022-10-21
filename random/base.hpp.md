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
  bundledCode: "#line 2 \"random/base.hpp\"\n\nll RNG(ll a, ll b) {\n  static mt19937\
    \ mt(chrono::steady_clock::now().time_since_epoch().count());\n  uniform_int_distribution<ll>\
    \ dist(a, b - 1);\n  return dist(mt);\n}\n\nll RNG(ll a) { return RNG(0, a); }\n"
  code: "#pragma once\n\nll RNG(ll a, ll b) {\n  static mt19937 mt(chrono::steady_clock::now().time_since_epoch().count());\n\
    \  uniform_int_distribution<ll> dist(a, b - 1);\n  return dist(mt);\n}\n\nll RNG(ll\
    \ a) { return RNG(0, a); }\n"
  dependsOn: []
  isVerificationFile: false
  path: random/base.hpp
  requiredBy: []
  timestamp: '2022-10-21 16:42:45+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: random/base.hpp
layout: document
redirect_from:
- /library/random/base.hpp
- /library/random/base.hpp.html
title: random/base.hpp
---
