---
data:
  _extendedDependsOn:
  - icon: ':question:'
    path: setfunc/ranked_zeta.hpp
    title: setfunc/ranked_zeta.hpp
  _extendedRequiredBy:
  - icon: ':heavy_check_mark:'
    path: graph/chromatic.hpp
    title: graph/chromatic.hpp
  - icon: ':warning:'
    path: graph/tutte_polynomial.hpp
    title: graph/tutte_polynomial.hpp
  - icon: ':heavy_check_mark:'
    path: linalg/hafnian.hpp
    title: linalg/hafnian.hpp
  - icon: ':question:'
    path: setfunc/power_projection_of_sps.hpp
    title: setfunc/power_projection_of_sps.hpp
  - icon: ':question:'
    path: setfunc/sps_exp.hpp
    title: setfunc/sps_exp.hpp
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/2_library_checker/graph/chromatic_number.test.cpp
    title: test/2_library_checker/graph/chromatic_number.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/2_library_checker/graph/chromatic_polynomial.test.cpp
    title: test/2_library_checker/graph/chromatic_polynomial.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/2_library_checker/linear_algebra/hafnian_of_matrix.test.cpp
    title: test/2_library_checker/linear_algebra/hafnian_of_matrix.test.cpp
  - icon: ':x:'
    path: test/2_library_checker/set_power_series/power_projection_of_sps.test.cpp
    title: test/2_library_checker/set_power_series/power_projection_of_sps.test.cpp
  - icon: ':x:'
    path: test/2_library_checker/set_power_series/powproj_sps.test.cpp
    title: test/2_library_checker/set_power_series/powproj_sps.test.cpp
  - icon: ':x:'
    path: test/2_library_checker/set_power_series/sps_exp.test.cpp
    title: test/2_library_checker/set_power_series/sps_exp.test.cpp
  - icon: ':x:'
    path: test/2_library_checker/set_power_series/subset_convolution.test.cpp
    title: test/2_library_checker/set_power_series/subset_convolution.test.cpp
  - icon: ':x:'
    path: test/3_yukicoder/2507.test.cpp
    title: test/3_yukicoder/2507.test.cpp
  - icon: ':x:'
    path: test/5_atcoder/abc236h.test.cpp
    title: test/5_atcoder/abc236h.test.cpp
  - icon: ':x:'
    path: test/5_atcoder/abc253h.test.cpp
    title: test/5_atcoder/abc253h.test.cpp
  - icon: ':x:'
    path: test/5_atcoder/arc105.test.cpp
    title: test/5_atcoder/arc105.test.cpp
  _isVerificationFailed: true
  _pathExtension: hpp
  _verificationStatusIcon: ':question:'
  attributes:
    links: []
  bundledCode: "#line 2 \"setfunc/subset_convolution.hpp\"\n\r\n#line 2 \"setfunc/ranked_zeta.hpp\"\
    \n\r\ntemplate <typename T, int LIM>\r\nvc<array<T, LIM + 1>> ranked_zeta(const\
    \ vc<T>& f) {\r\n  int n = topbit(len(f));\r\n  assert(n <= LIM);\r\n  assert(len(f)\
    \ == 1 << n);\r\n  vc<array<T, LIM + 1>> Rf(1 << n);\r\n  for (int s = 0; s <\
    \ (1 << n); ++s) Rf[s][popcnt(s)] = f[s];\r\n  for (int i = 0; i < n; ++i) {\r\
    \n    int w = 1 << i;\r\n    for (int p = 0; p < (1 << n); p += 2 * w) {\r\n \
    \     for (int s = p; s < p + w; ++s) {\r\n        int t = s | 1 << i;\r\n   \
    \     for (int d = 0; d <= n; ++d) Rf[t][d] += Rf[s][d];\r\n      }\r\n    }\r\
    \n  }\r\n  return Rf;\r\n}\r\n\r\ntemplate <typename T, int LIM>\r\nvc<T> ranked_mobius(vc<array<T,\
    \ LIM + 1>>& Rf) {\r\n  int n = topbit(len(Rf));\r\n  assert(len(Rf) == 1 << n);\r\
    \n  for (int i = 0; i < n; ++i) {\r\n    int w = 1 << i;\r\n    for (int p = 0;\
    \ p < (1 << n); p += 2 * w) {\r\n      for (int s = p; s < p + w; ++s) {\r\n \
    \       int t = s | 1 << i;\r\n        for (int d = 0; d <= n; ++d) Rf[t][d] -=\
    \ Rf[s][d];\r\n      }\r\n    }\r\n  }\r\n  vc<T> f(1 << n);\r\n  for (int s =\
    \ 0; s < (1 << n); ++s) f[s] = Rf[s][popcnt(s)];\r\n  return f;\r\n}\n#line 4\
    \ \"setfunc/subset_convolution.hpp\"\n\r\ntemplate <typename T, int LIM = 20>\r\
    \nvc<T> subset_convolution_square(const vc<T>& A) {\r\n  auto RA = ranked_zeta<T,\
    \ LIM>(A);\r\n  int n = topbit(len(RA));\r\n  FOR(s, len(RA)) {\r\n    auto& f\
    \ = RA[s];\r\n    FOR_R(d, n + 1) {\r\n      T x = 0;\r\n      FOR(i, d + 1) x\
    \ += f[i] * f[d - i];\r\n      f[d] = x;\r\n    }\r\n  }\r\n  return ranked_mobius<T,\
    \ LIM>(RA);\r\n}\r\n\r\ntemplate <typename T, int LIM = 20>\r\nvc<T> subset_convolution(const\
    \ vc<T>& A, const vc<T>& B) {\r\n  if (A == B) return subset_convolution_square(A);\r\
    \n  auto RA = ranked_zeta<T, LIM>(A);\r\n  auto RB = ranked_zeta<T, LIM>(B);\r\
    \n  int n = topbit(len(RA));\r\n  FOR(s, len(RA)) {\r\n    auto &f = RA[s], &g\
    \ = RB[s];\r\n    FOR_R(d, n + 1) {\r\n      T x = 0;\r\n      FOR(i, d + 1) x\
    \ += f[i] * g[d - i];\r\n      f[d] = x;\r\n    }\r\n  }\r\n  return ranked_mobius<T,\
    \ LIM>(RA);\r\n}\r\n"
  code: "#pragma once\r\n\r\n#include \"setfunc/ranked_zeta.hpp\"\r\n\r\ntemplate\
    \ <typename T, int LIM = 20>\r\nvc<T> subset_convolution_square(const vc<T>& A)\
    \ {\r\n  auto RA = ranked_zeta<T, LIM>(A);\r\n  int n = topbit(len(RA));\r\n \
    \ FOR(s, len(RA)) {\r\n    auto& f = RA[s];\r\n    FOR_R(d, n + 1) {\r\n     \
    \ T x = 0;\r\n      FOR(i, d + 1) x += f[i] * f[d - i];\r\n      f[d] = x;\r\n\
    \    }\r\n  }\r\n  return ranked_mobius<T, LIM>(RA);\r\n}\r\n\r\ntemplate <typename\
    \ T, int LIM = 20>\r\nvc<T> subset_convolution(const vc<T>& A, const vc<T>& B)\
    \ {\r\n  if (A == B) return subset_convolution_square(A);\r\n  auto RA = ranked_zeta<T,\
    \ LIM>(A);\r\n  auto RB = ranked_zeta<T, LIM>(B);\r\n  int n = topbit(len(RA));\r\
    \n  FOR(s, len(RA)) {\r\n    auto &f = RA[s], &g = RB[s];\r\n    FOR_R(d, n +\
    \ 1) {\r\n      T x = 0;\r\n      FOR(i, d + 1) x += f[i] * g[d - i];\r\n    \
    \  f[d] = x;\r\n    }\r\n  }\r\n  return ranked_mobius<T, LIM>(RA);\r\n}\r\n"
  dependsOn:
  - setfunc/ranked_zeta.hpp
  isVerificationFile: false
  path: setfunc/subset_convolution.hpp
  requiredBy:
  - linalg/hafnian.hpp
  - graph/tutte_polynomial.hpp
  - graph/chromatic.hpp
  - setfunc/sps_exp.hpp
  - setfunc/power_projection_of_sps.hpp
  timestamp: '2023-09-23 23:33:32+09:00'
  verificationStatus: LIBRARY_SOME_WA
  verifiedWith:
  - test/3_yukicoder/2507.test.cpp
  - test/5_atcoder/arc105.test.cpp
  - test/5_atcoder/abc236h.test.cpp
  - test/5_atcoder/abc253h.test.cpp
  - test/2_library_checker/set_power_series/power_projection_of_sps.test.cpp
  - test/2_library_checker/set_power_series/sps_exp.test.cpp
  - test/2_library_checker/set_power_series/subset_convolution.test.cpp
  - test/2_library_checker/set_power_series/powproj_sps.test.cpp
  - test/2_library_checker/linear_algebra/hafnian_of_matrix.test.cpp
  - test/2_library_checker/graph/chromatic_polynomial.test.cpp
  - test/2_library_checker/graph/chromatic_number.test.cpp
documentation_of: setfunc/subset_convolution.hpp
layout: document
redirect_from:
- /library/setfunc/subset_convolution.hpp
- /library/setfunc/subset_convolution.hpp.html
title: setfunc/subset_convolution.hpp
---
