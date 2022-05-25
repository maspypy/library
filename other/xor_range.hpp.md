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
  bundledCode: "#line 1 \"other/xor_range.hpp\"\n// lo <= a ^ x < hi \u3068\u306A\u308B\
    \ x \u306E\u533A\u9593 [li, ri) \u305F\u3061\u3092\u8FD4\u3059\nvc<pi> xor_range(ll\
    \ a, ll lo, ll hi) {\n  vc<pi> res;\n  FOR(k, 64) {\n    if (lo == hi) break;\n\
    \    ll b = 1LL << k;\n    if (lo & b) {\n      res.eb((lo ^ a), (lo ^ a) + b);\n\
    \      lo += b;\n    }\n    if (hi & b) {\n      res.eb((hi - b) ^ a, ((hi - b)\
    \ ^ a) + b);\n      hi -= b;\n    }\n    if (a & b) a ^= b;\n  }\n  return res;\n\
    }\n"
  code: "// lo <= a ^ x < hi \u3068\u306A\u308B x \u306E\u533A\u9593 [li, ri) \u305F\
    \u3061\u3092\u8FD4\u3059\nvc<pi> xor_range(ll a, ll lo, ll hi) {\n  vc<pi> res;\n\
    \  FOR(k, 64) {\n    if (lo == hi) break;\n    ll b = 1LL << k;\n    if (lo &\
    \ b) {\n      res.eb((lo ^ a), (lo ^ a) + b);\n      lo += b;\n    }\n    if (hi\
    \ & b) {\n      res.eb((hi - b) ^ a, ((hi - b) ^ a) + b);\n      hi -= b;\n  \
    \  }\n    if (a & b) a ^= b;\n  }\n  return res;\n}\n"
  dependsOn: []
  isVerificationFile: false
  path: other/xor_range.hpp
  requiredBy: []
  timestamp: '2022-05-26 00:09:14+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: other/xor_range.hpp
layout: document
redirect_from:
- /library/other/xor_range.hpp
- /library/other/xor_range.hpp.html
title: other/xor_range.hpp
---
