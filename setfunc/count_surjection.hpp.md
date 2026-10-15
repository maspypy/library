---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':x:'
    path: test/4_aoj/DPL_5_C.test.cpp
    title: test/4_aoj/DPL_5_C.test.cpp
  _isVerificationFailed: true
  _pathExtension: hpp
  _verificationStatusIcon: ':x:'
  attributes:
    links:
    - https://github.com/maspypy/library/blob/main/setfunc/count_surjection.hpp
  bundledCode: "#line 1 \"setfunc/count_surjection.hpp\"\n// Source: https://github.com/maspypy/library/blob/main/setfunc/count_surjection.hpp\n\
    template<typename mint>\nmint count_surjection(ll n, ll m) {\n  if (n < m) return\
    \ 0;\n  mint res = 0;\n  FOR(i, m + 1) {\n    mint sgn = ((m - i) & 1 ? -1 : 1);\n\
    \    res += mint(i).pow(n) * C<mint>(m, i) * sgn;\n  }\n  return res;\n}\n"
  code: "// Source: https://github.com/maspypy/library/blob/main/setfunc/count_surjection.hpp\n\
    template<typename mint>\nmint count_surjection(ll n, ll m) {\n  if (n < m) return\
    \ 0;\n  mint res = 0;\n  FOR(i, m + 1) {\n    mint sgn = ((m - i) & 1 ? -1 : 1);\n\
    \    res += mint(i).pow(n) * C<mint>(m, i) * sgn;\n  }\n  return res;\n}"
  dependsOn: []
  isVerificationFile: false
  path: setfunc/count_surjection.hpp
  requiredBy: []
  timestamp: '2026-10-15 19:54:56+09:00'
  verificationStatus: LIBRARY_ALL_WA
  verifiedWith:
  - test/4_aoj/DPL_5_C.test.cpp
documentation_of: setfunc/count_surjection.hpp
layout: document
redirect_from:
- /library/setfunc/count_surjection.hpp
- /library/setfunc/count_surjection.hpp.html
title: setfunc/count_surjection.hpp
---
