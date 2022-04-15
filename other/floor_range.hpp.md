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
  bundledCode: "#line 1 \"other/floor_range.hpp\"\n#define floor_range(q, l, r, n)\
    \ \\\r\n  for (ll q = 1, l = n / (q + 1) + 1, r = n / q + 1;\\\r\n  q <= n; q\
    \ = (q == n ? n + 1 : n / (n / (q + 1))), l = n / (q + 1) + 1, r = n / q + 1)\r\
    \n"
  code: "#define floor_range(q, l, r, n) \\\r\n  for (ll q = 1, l = n / (q + 1) +\
    \ 1, r = n / q + 1;\\\r\n  q <= n; q = (q == n ? n + 1 : n / (n / (q + 1))), l\
    \ = n / (q + 1) + 1, r = n / q + 1)\r\n"
  dependsOn: []
  isVerificationFile: false
  path: other/floor_range.hpp
  requiredBy: []
  timestamp: '2022-04-16 04:26:49+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: other/floor_range.hpp
layout: document
redirect_from:
- /library/other/floor_range.hpp
- /library/other/floor_range.hpp.html
title: other/floor_range.hpp
---
