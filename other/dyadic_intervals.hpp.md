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
  bundledCode: "#line 1 \"other/dyadic_intervals.hpp\"\n// \u6607\u9806\u3068\u306F\
    \u9650\u3089\u306A\u3044\uFF0C\u4E21\u7AEF\u304B\u3089\u547C\u3070\u308C\u308B\
    \ntemplate <typename F>\nvoid dyadic_intervals(ll L, ll R, F f) {\n  FOR(k, 64)\
    \ {\n    if (L == R) break;\n    ll b = 1LL << k;\n    if (L & b) f(L, L + b),\
    \ L += b;\n    if (R & b) f(R - b, R), R -= b;\n  }\n}\n"
  code: "// \u6607\u9806\u3068\u306F\u9650\u3089\u306A\u3044\uFF0C\u4E21\u7AEF\u304B\
    \u3089\u547C\u3070\u308C\u308B\ntemplate <typename F>\nvoid dyadic_intervals(ll\
    \ L, ll R, F f) {\n  FOR(k, 64) {\n    if (L == R) break;\n    ll b = 1LL << k;\n\
    \    if (L & b) f(L, L + b), L += b;\n    if (R & b) f(R - b, R), R -= b;\n  }\n\
    }\n"
  dependsOn: []
  isVerificationFile: false
  path: other/dyadic_intervals.hpp
  requiredBy: []
  timestamp: '2026-07-14 09:59:38+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: other/dyadic_intervals.hpp
layout: document
redirect_from:
- /library/other/dyadic_intervals.hpp
- /library/other/dyadic_intervals.hpp.html
title: other/dyadic_intervals.hpp
---
