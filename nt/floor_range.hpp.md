---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
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
  bundledCode: "#line 1 \"nt/floor_range.hpp\"\n#define floor_range(q, l, r, n) \\\
    \r\n  for (ll q = 1, l = (n) / (q + 1) + 1, r = (n) / q + 1;\\\r\n  q <= (n);\
    \ q = (q == (n) ? (n) + 1 : (n) / ((n) / (q + 1))), l = (n) / (q + 1) + 1, r =\
    \ (n) / q + 1)\r\n"
  code: "#define floor_range(q, l, r, n) \\\r\n  for (ll q = 1, l = (n) / (q + 1)\
    \ + 1, r = (n) / q + 1;\\\r\n  q <= (n); q = (q == (n) ? (n) + 1 : (n) / ((n)\
    \ / (q + 1))), l = (n) / (q + 1) + 1, r = (n) / q + 1)\r\n"
  dependsOn: []
  isVerificationFile: false
  path: nt/floor_range.hpp
  requiredBy: []
  timestamp: '2022-10-21 16:42:45+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/yukicoder/1260.test.cpp
  - test/yukicoder/4954.test.cpp
  - test/yukicoder/1276.test.cpp
  - test/yukicoder/1573.test.cpp
documentation_of: nt/floor_range.hpp
layout: document
redirect_from:
- /library/nt/floor_range.hpp
- /library/nt/floor_range.hpp.html
title: nt/floor_range.hpp
---
