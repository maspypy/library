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
    \ T, typename STRING>\nmint count_subseq(STRING S) {\n  auto key = S;\n  UNIQUE(key);\n\
    \  for(auto&& x : S)x=LB(key,x);\n  vc<int> IDX(len(key),-1);\n  ll N = len(S);\n\
    \  vc<mint> DP(N + 1);\n  DP[0] = 1;\n  FOR(i, N) {\n    T c = S[i];\n    DP[i\
    \ + 1] = DP[i] + DP[i];\n    if (IDX[c] != -1) { DP[i + 1] -= DP[IDX[c]]; }\n\
    \    IDX[c] = i;\n  }\n  return DP.back();\n}\n"
  code: "template <typename mint, typename T, typename STRING>\nmint count_subseq(STRING\
    \ S) {\n  auto key = S;\n  UNIQUE(key);\n  for(auto&& x : S)x=LB(key,x);\n  vc<int>\
    \ IDX(len(key),-1);\n  ll N = len(S);\n  vc<mint> DP(N + 1);\n  DP[0] = 1;\n \
    \ FOR(i, N) {\n    T c = S[i];\n    DP[i + 1] = DP[i] + DP[i];\n    if (IDX[c]\
    \ != -1) { DP[i + 1] -= DP[IDX[c]]; }\n    IDX[c] = i;\n  }\n  return DP.back();\n\
    }\n"
  dependsOn: []
  isVerificationFile: false
  path: dp/count_subseq.hpp
  requiredBy: []
  timestamp: '2022-07-31 09:53:37+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: dp/count_subseq.hpp
layout: document
redirect_from:
- /library/dp/count_subseq.hpp
- /library/dp/count_subseq.hpp.html
title: dp/count_subseq.hpp
---
