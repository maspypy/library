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
    \n}\n#line 2 \"setfunc/subset_convolution.hpp\"\n\r\ntemplate <typename T, int\
    \ LIM = 20>\r\nvc<T> subset_convolution(const vc<T>& A, const vc<T>& B) {\r\n\
    \  if (A == B) return subset_convolution_square(A);\r\n  auto RA = ranked_zeta<T,\
    \ LIM>(A);\r\n  auto RB = ranked_zeta<T, LIM>(B);\r\n  int n = topbit(len(RA));\r\
    \n  FOR(s, len(RA)) {\r\n    auto &f = RA[s], g = RB[s];\r\n    FOR_R(d, n + 1)\
    \ {\r\n      T x = 0;\r\n      FOR(i, d + 1) x += f[i] * g[d - i];\r\n      f[d]\
    \ = x;\r\n    }\r\n  }\r\n  return ranked_mobius<T, LIM>(RA);\r\n}\r\n\r\ntemplate\
    \ <typename T, int LIM = 20>\r\nvc<T> subset_convolution_square(const vc<T>& A)\
    \ {\r\n  auto RA = ranked_zeta<T, LIM>(A);\r\n  int n = topbit(len(RA));\r\n \
    \ FOR(s, len(RA)) {\r\n    auto& f = RA[s];\r\n    FOR_R(d, n + 1) {\r\n     \
    \ T x = 0;\r\n      FOR(i, d + 1) x += f[i] * f[d - i];\r\n      f[d] = x;\r\n\
    \    }\r\n  }\r\n  return ranked_mobius<T, LIM>(RA);\r\n}\n"
  code: "#include \"setfunc/ranked_zeta.hpp\"\r\n\r\ntemplate <typename T, int LIM\
    \ = 20>\r\nvc<T> subset_convolution(const vc<T>& A, const vc<T>& B) {\r\n  if\
    \ (A == B) return subset_convolution_square(A);\r\n  auto RA = ranked_zeta<T,\
    \ LIM>(A);\r\n  auto RB = ranked_zeta<T, LIM>(B);\r\n  int n = topbit(len(RA));\r\
    \n  FOR(s, len(RA)) {\r\n    auto &f = RA[s], g = RB[s];\r\n    FOR_R(d, n + 1)\
    \ {\r\n      T x = 0;\r\n      FOR(i, d + 1) x += f[i] * g[d - i];\r\n      f[d]\
    \ = x;\r\n    }\r\n  }\r\n  return ranked_mobius<T, LIM>(RA);\r\n}\r\n\r\ntemplate\
    \ <typename T, int LIM = 20>\r\nvc<T> subset_convolution_square(const vc<T>& A)\
    \ {\r\n  auto RA = ranked_zeta<T, LIM>(A);\r\n  int n = topbit(len(RA));\r\n \
    \ FOR(s, len(RA)) {\r\n    auto& f = RA[s];\r\n    FOR_R(d, n + 1) {\r\n     \
    \ T x = 0;\r\n      FOR(i, d + 1) x += f[i] * f[d - i];\r\n      f[d] = x;\r\n\
    \    }\r\n  }\r\n  return ranked_mobius<T, LIM>(RA);\r\n}"
  dependsOn:
  - setfunc/ranked_zeta.hpp
  isVerificationFile: false
  path: setfunc/subset_convolution.hpp
  requiredBy: []
  timestamp: '2022-08-19 07:15:10+09:00'
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
