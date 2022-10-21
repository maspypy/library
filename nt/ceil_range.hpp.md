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
  bundledCode: "#line 1 \"nt/ceil_range.hpp\"\n#define ceil_range(q, l, r, n) \\\r\
    \n  for (ll q = 1, l = n, r = (1LL<<60);\\\r\n  q <= n; q = (q == n ? n + 1 :\
    \ ceil(n, ceil(n, q) - 1)), l = ceil(n, q), r = ceil(n, q - 1))\r\n"
  code: "#define ceil_range(q, l, r, n) \\\r\n  for (ll q = 1, l = n, r = (1LL<<60);\\\
    \r\n  q <= n; q = (q == n ? n + 1 : ceil(n, ceil(n, q) - 1)), l = ceil(n, q),\
    \ r = ceil(n, q - 1))\r\n"
  dependsOn: []
  isVerificationFile: false
  path: nt/ceil_range.hpp
  requiredBy: []
  timestamp: '2022-10-21 16:42:45+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: nt/ceil_range.hpp
layout: document
redirect_from:
- /library/nt/ceil_range.hpp
- /library/nt/ceil_range.hpp.html
title: nt/ceil_range.hpp
---
