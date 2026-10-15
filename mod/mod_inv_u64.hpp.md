---
data:
  _extendedDependsOn: []
  _extendedRequiredBy:
  - icon: ':warning:'
    path: mod/mod_log_u64.hpp
    title: mod/mod_log_u64.hpp
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':warning:'
  attributes:
    links:
    - https://github.com/maspypy/library/blob/main/mod/mod_inv_u64.hpp
  bundledCode: "#line 1 \"mod/mod_inv_u64.hpp\"\n// Source: https://github.com/maspypy/library/blob/main/mod/mod_inv_u64.hpp\n\
    u64 mod_inv_u64(u64 a) {\n  assert(a & 1);\n  u64 x = 1;\n  x = x * (2ULL - a\
    \ * x);\n  x = x * (2ULL - a * x);\n  x = x * (2ULL - a * x);\n  x = x * (2ULL\
    \ - a * x);\n  x = x * (2ULL - a * x);\n  x = x * (2ULL - a * x);\n  assert(a\
    \ * x == 1);\n  return x;\n}\n"
  code: "// Source: https://github.com/maspypy/library/blob/main/mod/mod_inv_u64.hpp\n\
    u64 mod_inv_u64(u64 a) {\n  assert(a & 1);\n  u64 x = 1;\n  x = x * (2ULL - a\
    \ * x);\n  x = x * (2ULL - a * x);\n  x = x * (2ULL - a * x);\n  x = x * (2ULL\
    \ - a * x);\n  x = x * (2ULL - a * x);\n  x = x * (2ULL - a * x);\n  assert(a\
    \ * x == 1);\n  return x;\n}\n"
  dependsOn: []
  isVerificationFile: false
  path: mod/mod_inv_u64.hpp
  requiredBy:
  - mod/mod_log_u64.hpp
  timestamp: '2026-10-15 19:54:56+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: mod/mod_inv_u64.hpp
layout: document
redirect_from:
- /library/mod/mod_inv_u64.hpp
- /library/mod/mod_inv_u64.hpp.html
title: mod/mod_inv_u64.hpp
---
