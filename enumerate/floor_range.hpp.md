---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/mytest/floor_ceil_ranges.test.cpp
    title: test/mytest/floor_ceil_ranges.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/yukicoder/1260.test.cpp
    title: test/yukicoder/1260.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/yukicoder/1276.test.cpp
    title: test/yukicoder/1276.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/yukicoder/1573.test.cpp
    title: test/yukicoder/1573.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/yukicoder/4954.test.cpp
    title: test/yukicoder/4954.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 1 \"enumerate/floor_range.hpp\"\ntemplate <typename T, typename\
    \ F>\r\nvoid floor_range(T N, F f) {\r\n  ll thresh = 1'000'000'000'000;\r\n \
    \ ll sq = sqrtl(N);\r\n  int n = (sq * sq + sq <= N ? sq : sq - 1);\r\n  if (N\
    \ <= thresh) {\r\n    ll prev = N + 1;\r\n    for (int q = 1; q <= n; ++q) {\r\
    \n      ll x = double(N) / (q + 1) + 1;\r\n      f(q, x, prev), prev = x;\r\n\
    \    }\r\n    for (int l = sq; l >= 1; --l) { f(double(N) / l, l, l + 1); }\r\n\
    \  } else {\r\n    ll prev = N + 1;\r\n    for (int q = 1; q <= n; ++q) {\r\n\
    \      ll x = N / (q + 1) + 1;\r\n      f(q, x, prev), prev = x;\r\n    }\r\n\
    \    for (int l = sq; l >= 1; --l) { f(N / l, l, l + 1); }\r\n  }\r\n}\r\n"
  code: "template <typename T, typename F>\r\nvoid floor_range(T N, F f) {\r\n  ll\
    \ thresh = 1'000'000'000'000;\r\n  ll sq = sqrtl(N);\r\n  int n = (sq * sq + sq\
    \ <= N ? sq : sq - 1);\r\n  if (N <= thresh) {\r\n    ll prev = N + 1;\r\n   \
    \ for (int q = 1; q <= n; ++q) {\r\n      ll x = double(N) / (q + 1) + 1;\r\n\
    \      f(q, x, prev), prev = x;\r\n    }\r\n    for (int l = sq; l >= 1; --l)\
    \ { f(double(N) / l, l, l + 1); }\r\n  } else {\r\n    ll prev = N + 1;\r\n  \
    \  for (int q = 1; q <= n; ++q) {\r\n      ll x = N / (q + 1) + 1;\r\n      f(q,\
    \ x, prev), prev = x;\r\n    }\r\n    for (int l = sq; l >= 1; --l) { f(N / l,\
    \ l, l + 1); }\r\n  }\r\n}\r\n"
  dependsOn: []
  isVerificationFile: false
  path: enumerate/floor_range.hpp
  requiredBy: []
  timestamp: '2023-02-12 20:18:55+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/yukicoder/1573.test.cpp
  - test/yukicoder/1260.test.cpp
  - test/yukicoder/1276.test.cpp
  - test/yukicoder/4954.test.cpp
  - test/mytest/floor_ceil_ranges.test.cpp
documentation_of: enumerate/floor_range.hpp
layout: document
redirect_from:
- /library/enumerate/floor_range.hpp
- /library/enumerate/floor_range.hpp.html
title: enumerate/floor_range.hpp
---
