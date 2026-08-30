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
  bundledCode: "#line 1 \"mod/mod_pow_u64.hpp\"\nu64 mod_pow_u64(u64 a, u64 n) {\n\
    \  u64 x = 1;\n  while (n) {\n    if (n & 1) x *= a;\n    a *= a, n >>= 1;\n \
    \ }\n  return x;\n}\n"
  code: "u64 mod_pow_u64(u64 a, u64 n) {\n  u64 x = 1;\n  while (n) {\n    if (n &\
    \ 1) x *= a;\n    a *= a, n >>= 1;\n  }\n  return x;\n}"
  dependsOn: []
  isVerificationFile: false
  path: mod/mod_pow_u64.hpp
  requiredBy: []
  timestamp: '2026-08-30 21:09:36+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: mod/mod_pow_u64.hpp
layout: document
redirect_from:
- /library/mod/mod_pow_u64.hpp
- /library/mod/mod_pow_u64.hpp.html
title: mod/mod_pow_u64.hpp
---
