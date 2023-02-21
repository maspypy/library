---
data:
  _extendedDependsOn: []
  _extendedRequiredBy:
  - icon: ':x:'
    path: setfunc/subset_convolution.hpp
    title: setfunc/subset_convolution.hpp
  _extendedVerifiedWith:
  - icon: ':x:'
    path: test/library_checker/convolution/subset_convolution.test.cpp
    title: test/library_checker/convolution/subset_convolution.test.cpp
  _isVerificationFailed: true
  _pathExtension: hpp
  _verificationStatusIcon: ':x:'
  attributes:
    links: []
  bundledCode: "#line 2 \"setfunc/ranked_zeta.hpp\"\n\r\ntemplate <typename T, int\
    \ LIM = 20>\r\nvc<array<T, LIM + 1>> ranked_zeta(const vc<T>& f) {\r\n  int n\
    \ = topbit(len(f));\r\n  assert(n <= LIM);\r\n  assert(len(f) == 1 << n);\r\n\
    \  vc<array<T, LIM + 1>> Rf(1 << n);\r\n  for (int s = 0; s < (1 << n); ++s) Rf[s][popcnt(s)]\
    \ = f[s];\r\n  for (int i = 0; i < n; ++i) {\r\n    for (int s = 0; s < (1 <<\
    \ n); ++s) {\r\n      int t = s | 1 << i;\r\n      if (s == t) continue;\r\n \
    \     for (int d = 0; d <= n; ++d) Rf[t][d] += Rf[s][d];\r\n    }\r\n  }\r\n \
    \ return Rf;\r\n}\r\n\r\ntemplate <typename T, int LIM = 20>\r\nvc<T> ranked_mobius(vc<array<T,\
    \ LIM + 1>>& Rf) {\r\n  int n = topbit(len(Rf));\r\n  assert(len(Rf) == 1 << n);\r\
    \n  for (int i = 0; i < n; ++i) {\r\n    for (int s = 0; s < (1 << n); ++s) {\r\
    \n      int t = s | 1 << i;\r\n      if (s == t) continue;\r\n      for (int d\
    \ = 0; d <= n; ++d) Rf[t][d] -= Rf[s][d];\r\n    }\r\n  }\r\n  vc<T> f(1 << n);\r\
    \n  for (int s = 0; s < (1 << n); ++s) f[s] = Rf[s][popcnt(s)];\r\n  return f;\r\
    \n}\n"
  code: "#pragma once\r\n\r\ntemplate <typename T, int LIM = 20>\r\nvc<array<T, LIM\
    \ + 1>> ranked_zeta(const vc<T>& f) {\r\n  int n = topbit(len(f));\r\n  assert(n\
    \ <= LIM);\r\n  assert(len(f) == 1 << n);\r\n  vc<array<T, LIM + 1>> Rf(1 << n);\r\
    \n  for (int s = 0; s < (1 << n); ++s) Rf[s][popcnt(s)] = f[s];\r\n  for (int\
    \ i = 0; i < n; ++i) {\r\n    for (int s = 0; s < (1 << n); ++s) {\r\n      int\
    \ t = s | 1 << i;\r\n      if (s == t) continue;\r\n      for (int d = 0; d <=\
    \ n; ++d) Rf[t][d] += Rf[s][d];\r\n    }\r\n  }\r\n  return Rf;\r\n}\r\n\r\ntemplate\
    \ <typename T, int LIM = 20>\r\nvc<T> ranked_mobius(vc<array<T, LIM + 1>>& Rf)\
    \ {\r\n  int n = topbit(len(Rf));\r\n  assert(len(Rf) == 1 << n);\r\n  for (int\
    \ i = 0; i < n; ++i) {\r\n    for (int s = 0; s < (1 << n); ++s) {\r\n      int\
    \ t = s | 1 << i;\r\n      if (s == t) continue;\r\n      for (int d = 0; d <=\
    \ n; ++d) Rf[t][d] -= Rf[s][d];\r\n    }\r\n  }\r\n  vc<T> f(1 << n);\r\n  for\
    \ (int s = 0; s < (1 << n); ++s) f[s] = Rf[s][popcnt(s)];\r\n  return f;\r\n}"
  dependsOn: []
  isVerificationFile: false
  path: setfunc/ranked_zeta.hpp
  requiredBy:
  - setfunc/subset_convolution.hpp
  timestamp: '2022-08-19 05:33:28+09:00'
  verificationStatus: LIBRARY_ALL_WA
  verifiedWith:
  - test/library_checker/convolution/subset_convolution.test.cpp
documentation_of: setfunc/ranked_zeta.hpp
layout: document
redirect_from:
- /library/setfunc/ranked_zeta.hpp
- /library/setfunc/ranked_zeta.hpp.html
title: setfunc/ranked_zeta.hpp
---
