---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/yukicoder/1240.test.cpp
    title: test/yukicoder/1240.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 1 \"enumerate/xor_range.hpp\"\n// lo <= (x ^ a) < hi \u3068\u306A\
    \u308B x \u306E\u533A\u9593 [L, R) \u306E\u5217\u6319\ntemplate <typename F>\n\
    void xor_range(u64 a, u64 lo, u64 hi, F query) {\n  FOR(k, 64) {\n    if (lo ==\
    \ hi) break;\n    ll b = 1LL << k;\n    if (lo & b) { query((lo ^ a), (lo ^ a)\
    \ + b), lo += b; }\n    if (hi & b) { query((hi - b) ^ a, ((hi - b) ^ a) + b),\
    \ hi -= b; }\n    if (a & b) a ^= b;\n  }\n}\n"
  code: "// lo <= (x ^ a) < hi \u3068\u306A\u308B x \u306E\u533A\u9593 [L, R) \u306E\
    \u5217\u6319\ntemplate <typename F>\nvoid xor_range(u64 a, u64 lo, u64 hi, F query)\
    \ {\n  FOR(k, 64) {\n    if (lo == hi) break;\n    ll b = 1LL << k;\n    if (lo\
    \ & b) { query((lo ^ a), (lo ^ a) + b), lo += b; }\n    if (hi & b) { query((hi\
    \ - b) ^ a, ((hi - b) ^ a) + b), hi -= b; }\n    if (a & b) a ^= b;\n  }\n}\n"
  dependsOn: []
  isVerificationFile: false
  path: enumerate/xor_range.hpp
  requiredBy: []
  timestamp: '2022-12-06 21:19:07+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/yukicoder/1240.test.cpp
documentation_of: enumerate/xor_range.hpp
layout: document
redirect_from:
- /library/enumerate/xor_range.hpp
- /library/enumerate/xor_range.hpp.html
title: enumerate/xor_range.hpp
---
