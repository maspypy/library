---
data:
  _extendedDependsOn:
  - icon: ':x:'
    path: setfunc/ranked_zeta.hpp
    title: setfunc/ranked_zeta.hpp
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':x:'
    path: test/library_checker/convolution/subset_convolution.test.cpp
    title: test/library_checker/convolution/subset_convolution.test.cpp
  _isVerificationFailed: true
  _pathExtension: hpp
  _verificationStatusIcon: ':x:'
  attributes:
    links: []
  bundledCode: "#line 2 \"setfunc/ranked_zeta.hpp\"\n\r\ntemplate <typename T>\r\n\
    vc<vc<T>> ranked_zeta(const vc<T>& f) {\r\n  int n = topbit(len(f));\r\n  assert(len(f)\
    \ == 1 << n);\r\n  vv(T, Rf, 1 << n, n + 1);\r\n  for (int s = 0; s < (1 << n);\
    \ ++s) Rf[s][popcnt(s)] = f[s];\r\n  for (int i = 0; i < n; ++i) {\r\n    for\
    \ (int s = 0; s < (1 << n); ++s) {\r\n      int t = s | 1 << i;\r\n      if (s\
    \ == t) continue;\r\n      for (int d = 0; d <= n; ++d) Rf[t][d] += Rf[s][d];\r\
    \n    }\r\n  }\r\n  return Rf;\r\n}\r\n\r\ntemplate <typename T>\r\nvc<T> ranked_mobius(vc<vc<T>>&\
    \ Rf) {\r\n  int n = topbit(len(Rf));\r\n  assert(len(Rf) == 1 << n);\r\n  for\
    \ (int i = 0; i < n; ++i) {\r\n    for (int s = 0; s < (1 << n); ++s) {\r\n  \
    \    int t = s | 1 << i;\r\n      if (s == t) continue;\r\n      for (int d =\
    \ 0; d <= n; ++d) Rf[t][d] -= Rf[s][d];\r\n    }\r\n  }\r\n  vc<T> f(1 << n);\r\
    \n  for (int s = 0; s < (1 << n); ++s) f[s] = Rf[s][popcnt(s)];\r\n  return f;\r\
    \n}\n#line 2 \"setfunc/subset_convolution.hpp\"\n\r\ntemplate <typename T>\r\n\
    vc<T> subset_convolution(vc<T> A, vc<T> B) {\r\n  auto RA = ranked_zeta(A);\r\n\
    \  auto RB = ranked_zeta(B);\r\n  int n = len(RA[0]) - 1;\r\n  FOR(s, len(RA))\
    \ {\r\n    vc<T> f(n + 1);\r\n    FOR(i, n + 1) FOR(j, n - i + 1) f[i + j] +=\
    \ RA[s][i] * RB[s][j];\r\n    RA[s] = f;\r\n  }\r\n  return ranked_mobius(RA);\r\
    \n}\r\n"
  code: "#include \"setfunc/ranked_zeta.hpp\"\r\n\r\ntemplate <typename T>\r\nvc<T>\
    \ subset_convolution(vc<T> A, vc<T> B) {\r\n  auto RA = ranked_zeta(A);\r\n  auto\
    \ RB = ranked_zeta(B);\r\n  int n = len(RA[0]) - 1;\r\n  FOR(s, len(RA)) {\r\n\
    \    vc<T> f(n + 1);\r\n    FOR(i, n + 1) FOR(j, n - i + 1) f[i + j] += RA[s][i]\
    \ * RB[s][j];\r\n    RA[s] = f;\r\n  }\r\n  return ranked_mobius(RA);\r\n}\r\n"
  dependsOn:
  - setfunc/ranked_zeta.hpp
  isVerificationFile: false
  path: setfunc/subset_convolution.hpp
  requiredBy: []
  timestamp: '2022-08-14 06:04:34+09:00'
  verificationStatus: LIBRARY_ALL_WA
  verifiedWith:
  - test/library_checker/convolution/subset_convolution.test.cpp
documentation_of: setfunc/subset_convolution.hpp
layout: document
redirect_from:
- /library/setfunc/subset_convolution.hpp
- /library/setfunc/subset_convolution.hpp.html
title: setfunc/subset_convolution.hpp
---
