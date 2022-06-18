---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/yukicoder/1573_floor_range.test.cpp
    title: test/yukicoder/1573_floor_range.test.cpp
  - icon: ':x:'
    path: test/yukicoder/4954_quotients.test.cpp
    title: test/yukicoder/4954_quotients.test.cpp
  _isVerificationFailed: true
  _pathExtension: hpp
  _verificationStatusIcon: ':question:'
  attributes:
    links: []
  bundledCode: "#line 1 \"other/floor_range.hpp\"\n#define floor_range(q, l, r, n)\
    \ \\\r\n  for (ll q = 1, l = (n) / (q + 1) + 1, r = (n) / q + 1;\\\r\n  q <= (n);\
    \ q = (q == (n) ? (n) + 1 : (n) / ((n) / (q + 1))), l = (n) / (q + 1) + 1, r =\
    \ (n) / q + 1)\r\n"
  code: "#define floor_range(q, l, r, n) \\\r\n  for (ll q = 1, l = (n) / (q + 1)\
    \ + 1, r = (n) / q + 1;\\\r\n  q <= (n); q = (q == (n) ? (n) + 1 : (n) / ((n)\
    \ / (q + 1))), l = (n) / (q + 1) + 1, r = (n) / q + 1)\r\n"
  dependsOn: []
  isVerificationFile: false
  path: other/floor_range.hpp
  requiredBy: []
  timestamp: '2022-04-23 01:23:59+09:00'
  verificationStatus: LIBRARY_SOME_WA
  verifiedWith:
  - test/yukicoder/4954_quotients.test.cpp
  - test/yukicoder/1573_floor_range.test.cpp
documentation_of: other/floor_range.hpp
layout: document
redirect_from:
- /library/other/floor_range.hpp
- /library/other/floor_range.hpp.html
title: other/floor_range.hpp
---
