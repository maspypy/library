---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/library_checker/convolution/subset_convolution.test.cpp
    title: test/library_checker/convolution/subset_convolution.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 1 \"setfunc/subset_convolution.hpp\"\ntemplate <typename T,\
    \ int LIM = 20>\r\nvc<T> subset_convolution(vc<T>& A, vc<T>& B) {\r\n  using F\
    \ = array<T, LIM + 1>;\r\n  int N = len(A);\r\n  int log = topbit(N);\r\n  assert(N\
    \ == 1 << log);\r\n  vc<F> RA(N), RB(N);\r\n  FOR(s, N) RA[s][popcnt(s)] = A[s];\r\
    \n  FOR(s, N) RB[s][popcnt(s)] = B[s];\r\n  // subset zeta\r\n  FOR(i, log) FOR(s,\
    \ 1 << log) if (!(s & 1 << i)) {\r\n    int t = s | 1 << i;\r\n    FOR(k, log\
    \ + 1) RA[t][k] += RA[s][k], RB[t][k] += RB[s][k];\r\n  }\r\n  // pointwise multiplication\r\
    \n  FOR(s, 1 << log) {\r\n    auto &f = RA[s], &g = RB[s];\r\n    FOR_R(i, log\
    \ + 1) {\r\n      FOR3(j, 1, log - i + 1) f[i + j] += f[i] * g[j];\r\n      f[i]\
    \ *= g[0];\r\n    }\r\n  }\r\n  // subset mobius\r\n  FOR(i, log) FOR(s, 1 <<\
    \ log) if (!(s & 1 << i)) {\r\n    int t = s | 1 << i;\r\n    FOR(k, log + 1)\
    \ RA[t][k] -= RA[s][k];\r\n  }\r\n  vc<T> res(N);\r\n  FOR(s, N) res[s] = RA[s][popcnt(s)];\r\
    \n  return res;\r\n}\r\n"
  code: "template <typename T, int LIM = 20>\r\nvc<T> subset_convolution(vc<T>& A,\
    \ vc<T>& B) {\r\n  using F = array<T, LIM + 1>;\r\n  int N = len(A);\r\n  int\
    \ log = topbit(N);\r\n  assert(N == 1 << log);\r\n  vc<F> RA(N), RB(N);\r\n  FOR(s,\
    \ N) RA[s][popcnt(s)] = A[s];\r\n  FOR(s, N) RB[s][popcnt(s)] = B[s];\r\n  //\
    \ subset zeta\r\n  FOR(i, log) FOR(s, 1 << log) if (!(s & 1 << i)) {\r\n    int\
    \ t = s | 1 << i;\r\n    FOR(k, log + 1) RA[t][k] += RA[s][k], RB[t][k] += RB[s][k];\r\
    \n  }\r\n  // pointwise multiplication\r\n  FOR(s, 1 << log) {\r\n    auto &f\
    \ = RA[s], &g = RB[s];\r\n    FOR_R(i, log + 1) {\r\n      FOR3(j, 1, log - i\
    \ + 1) f[i + j] += f[i] * g[j];\r\n      f[i] *= g[0];\r\n    }\r\n  }\r\n  //\
    \ subset mobius\r\n  FOR(i, log) FOR(s, 1 << log) if (!(s & 1 << i)) {\r\n   \
    \ int t = s | 1 << i;\r\n    FOR(k, log + 1) RA[t][k] -= RA[s][k];\r\n  }\r\n\
    \  vc<T> res(N);\r\n  FOR(s, N) res[s] = RA[s][popcnt(s)];\r\n  return res;\r\n\
    }\r\n"
  dependsOn: []
  isVerificationFile: false
  path: setfunc/subset_convolution.hpp
  requiredBy: []
  timestamp: '2022-04-16 04:26:49+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/library_checker/convolution/subset_convolution.test.cpp
documentation_of: setfunc/subset_convolution.hpp
layout: document
redirect_from:
- /library/setfunc/subset_convolution.hpp
- /library/setfunc/subset_convolution.hpp.html
title: setfunc/subset_convolution.hpp
---
