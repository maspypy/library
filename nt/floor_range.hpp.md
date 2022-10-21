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
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: nt/floor_range.hpp
layout: document
redirect_from:
- /library/nt/floor_range.hpp
- /library/nt/floor_range.hpp.html
title: nt/floor_range.hpp
---
