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
  - icon: ':x:'
    path: test/yukicoder/1573.test.cpp
    title: test/yukicoder/1573.test.cpp
  - icon: ':x:'
    path: test/yukicoder/4954.test.cpp
    title: test/yukicoder/4954.test.cpp
  _isVerificationFailed: true
  _pathExtension: hpp
  _verificationStatusIcon: ':question:'
  attributes:
    links: []
  bundledCode: "#line 1 \"enumerate/floor_range.hpp\"\n// f(q, l, r)\uFF1A\u5546\u304C\
    \ q \u306B\u306A\u308B\u7BC4\u56F2\u304C [l, r)\r\ntemplate <typename F>\r\nvoid\
    \ floor_range(ll N, F f) {\r\n  ll q = 1, r = N + 1;\r\n  while (1) {\r\n    ll\
    \ l = N / (q + 1) + 1;\r\n    f(q, l, r);\r\n    if (q == N) break;\r\n    r =\
    \ l, q = N / (l - 1);\r\n  }\r\n}\r\n"
  code: "// f(q, l, r)\uFF1A\u5546\u304C q \u306B\u306A\u308B\u7BC4\u56F2\u304C [l,\
    \ r)\r\ntemplate <typename F>\r\nvoid floor_range(ll N, F f) {\r\n  ll q = 1,\
    \ r = N + 1;\r\n  while (1) {\r\n    ll l = N / (q + 1) + 1;\r\n    f(q, l, r);\r\
    \n    if (q == N) break;\r\n    r = l, q = N / (l - 1);\r\n  }\r\n}\r\n"
  dependsOn: []
  isVerificationFile: false
  path: enumerate/floor_range.hpp
  requiredBy: []
  timestamp: '2022-12-06 21:05:59+09:00'
  verificationStatus: LIBRARY_SOME_WA
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
