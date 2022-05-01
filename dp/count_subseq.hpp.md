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
  bundledCode: "#line 1 \"dp/count_subseq.hpp\"\ntemplate <typename mint, typename\
    \ T>\nmint count_subseq(vc<T> S) {\n  ll N = len(S);\n  map<T, ll> IDX;\n  vc<mint>\
    \ DP(N + 1);\n  DP[0] = 1;\n  FOR(i, N) {\n    T c = S[i];\n    DP[i + 1] = DP[i]\
    \ + DP[i];\n    if (IDX.count(c)) { DP[i + 1] -= DP[IDX[c]]; }\n    IDX[c] = i;\n\
    \  }\n  return DP.back();\n}\n"
  code: "template <typename mint, typename T>\nmint count_subseq(vc<T> S) {\n  ll\
    \ N = len(S);\n  map<T, ll> IDX;\n  vc<mint> DP(N + 1);\n  DP[0] = 1;\n  FOR(i,\
    \ N) {\n    T c = S[i];\n    DP[i + 1] = DP[i] + DP[i];\n    if (IDX.count(c))\
    \ { DP[i + 1] -= DP[IDX[c]]; }\n    IDX[c] = i;\n  }\n  return DP.back();\n}\n"
  dependsOn: []
  isVerificationFile: false
  path: dp/count_subseq.hpp
  requiredBy: []
  timestamp: '2022-05-01 15:15:05+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: dp/count_subseq.hpp
layout: document
redirect_from:
- /library/dp/count_subseq.hpp
- /library/dp/count_subseq.hpp.html
title: dp/count_subseq.hpp
---
