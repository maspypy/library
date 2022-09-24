---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':x:'
    path: test/aoj/DPL_5_C.test.cpp
    title: test/aoj/DPL_5_C.test.cpp
  _isVerificationFailed: true
  _pathExtension: hpp
  _verificationStatusIcon: ':x:'
  attributes:
    links: []
  bundledCode: "#line 1 \"setfunc/count_surjection.hpp\"\ntemplate<typename mint>\r\
    \nmint count_surjection(ll n, ll m) {\r\n  if (n < m) return 0;\r\n  mint res\
    \ = 0;\r\n  FOR(i, m + 1) {\r\n    mint sgn = ((m - i) & 1 ? -1 : 1);\r\n    res\
    \ += mint(i).pow(n) * C<mint>(m, i) * sgn;\r\n  }\r\n  return res;\r\n}\n"
  code: "template<typename mint>\r\nmint count_surjection(ll n, ll m) {\r\n  if (n\
    \ < m) return 0;\r\n  mint res = 0;\r\n  FOR(i, m + 1) {\r\n    mint sgn = ((m\
    \ - i) & 1 ? -1 : 1);\r\n    res += mint(i).pow(n) * C<mint>(m, i) * sgn;\r\n\
    \  }\r\n  return res;\r\n}"
  dependsOn: []
  isVerificationFile: false
  path: setfunc/count_surjection.hpp
  requiredBy: []
  timestamp: '2022-04-16 19:49:52+09:00'
  verificationStatus: LIBRARY_ALL_WA
  verifiedWith:
  - test/aoj/DPL_5_C.test.cpp
documentation_of: setfunc/count_surjection.hpp
layout: document
redirect_from:
- /library/setfunc/count_surjection.hpp
- /library/setfunc/count_surjection.hpp.html
title: setfunc/count_surjection.hpp
---
