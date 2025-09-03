---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':x:'
    path: test/1_mytest/floor_ceil_ranges.test.cpp
    title: test/1_mytest/floor_ceil_ranges.test.cpp
  _isVerificationFailed: true
  _pathExtension: hpp
  _verificationStatusIcon: ':x:'
  attributes:
    links: []
  bundledCode: "#line 1 \"enumerate/ceil_range.hpp\"\n// \u5546\u304C q \u306E\u533A\
    \u9593 [l,r) \u3092 q \u306B\u3064\u3044\u3066\u6607\u9806\ntemplate <typename\
    \ F>\nvoid ceil_range(ll N, F f) {\n  assert(N <= (1LL << 50));\n  ll sq = sqrtl(N);\n\
    \  ll prev = infty<ll>;\n  for (int q = 1; q <= sq; ++q) {\n    ll x = (N + q\
    \ - 1) / q;\n    f(q, x, prev), prev = x;\n  }\n  int n = (N <= sq * sq + sq ?\
    \ sq : sq + 1);\n  if (N == sq * sq) --n;\n  for (int l = n; l >= 1; --l) { f((N\
    \ + l - 1) / l, l, l + 1); }\n}\n"
  code: "// \u5546\u304C q \u306E\u533A\u9593 [l,r) \u3092 q \u306B\u3064\u3044\u3066\
    \u6607\u9806\ntemplate <typename F>\nvoid ceil_range(ll N, F f) {\n  assert(N\
    \ <= (1LL << 50));\n  ll sq = sqrtl(N);\n  ll prev = infty<ll>;\n  for (int q\
    \ = 1; q <= sq; ++q) {\n    ll x = (N + q - 1) / q;\n    f(q, x, prev), prev =\
    \ x;\n  }\n  int n = (N <= sq * sq + sq ? sq : sq + 1);\n  if (N == sq * sq) --n;\n\
    \  for (int l = n; l >= 1; --l) { f((N + l - 1) / l, l, l + 1); }\n}\n"
  dependsOn: []
  isVerificationFile: false
  path: enumerate/ceil_range.hpp
  requiredBy: []
  timestamp: '2024-09-14 09:20:23+09:00'
  verificationStatus: LIBRARY_ALL_WA
  verifiedWith:
  - test/1_mytest/floor_ceil_ranges.test.cpp
documentation_of: enumerate/ceil_range.hpp
layout: document
redirect_from:
- /library/enumerate/ceil_range.hpp
- /library/enumerate/ceil_range.hpp.html
title: enumerate/ceil_range.hpp
---
