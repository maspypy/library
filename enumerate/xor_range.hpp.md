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
  bundledCode: "#line 1 \"enumerate/xor_range.hpp\"\n// lo <= a ^ x < hi \u3068\u306A\
    \u308B x \u306E\u533A\u9593 [L, R) \u306E\u5217\u6319\ntemplate <typename F>\n\
    void xor_range(u64 a, u64 lo, u64 hi, F query) {\n  FOR(k, 64) {\n    if (lo ==\
    \ hi) break;\n    ll b = 1LL << k;\n    if (lo & b) {\n      query((lo ^ a), (lo\
    \ ^ a) + b);\n      lo += b;\n    }\n    if (hi & b) {\n      query((hi - b) ^\
    \ a, ((hi - b) ^ a) + b);\n      hi -= b;\n    }\n    if (a & b) a ^= b;\n  }\n\
    }\n"
  code: "// lo <= a ^ x < hi \u3068\u306A\u308B x \u306E\u533A\u9593 [L, R) \u306E\
    \u5217\u6319\ntemplate <typename F>\nvoid xor_range(u64 a, u64 lo, u64 hi, F query)\
    \ {\n  FOR(k, 64) {\n    if (lo == hi) break;\n    ll b = 1LL << k;\n    if (lo\
    \ & b) {\n      query((lo ^ a), (lo ^ a) + b);\n      lo += b;\n    }\n    if\
    \ (hi & b) {\n      query((hi - b) ^ a, ((hi - b) ^ a) + b);\n      hi -= b;\n\
    \    }\n    if (a & b) a ^= b;\n  }\n}\n"
  dependsOn: []
  isVerificationFile: false
  path: enumerate/xor_range.hpp
  requiredBy: []
  timestamp: '2022-11-27 13:10:58+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: enumerate/xor_range.hpp
layout: document
redirect_from:
- /library/enumerate/xor_range.hpp
- /library/enumerate/xor_range.hpp.html
title: enumerate/xor_range.hpp
---
