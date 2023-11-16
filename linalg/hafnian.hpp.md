---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: enumerate/bits.hpp
    title: enumerate/bits.hpp
  - icon: ':question:'
    path: setfunc/ranked_zeta.hpp
    title: setfunc/ranked_zeta.hpp
  - icon: ':heavy_check_mark:'
    path: setfunc/sps_exp.hpp
    title: setfunc/sps_exp.hpp
  - icon: ':question:'
    path: setfunc/subset_convolution.hpp
    title: setfunc/subset_convolution.hpp
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/library_checker/matrix/hafnian_of_matrix.test.cpp
    title: test/library_checker/matrix/hafnian_of_matrix.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
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
    \ LIM>(RA);\r\n}\r\n#line 2 \"setfunc/sps_exp.hpp\"\n\n// sum_i f_i/i! s^i, s^i\
    \ is subset-convolution\ntemplate <typename mint, int LIM>\nvc<mint> sps_exp(vc<mint>&\
    \ s) {\n  const int N = topbit(len(s));\n  assert(len(s) == (1 << N) && s[0] ==\
    \ mint(0));\n  vc<mint> dp(1 << N);\n  dp[0] = mint(1);\n  FOR(i, N) {\n    vc<mint>\
    \ a = {s.begin() + (1 << i), s.begin() + (2 << i)};\n    vc<mint> b = {dp.begin(),\
    \ dp.begin() + (1 << i)};\n    a = subset_convolution<mint, LIM>(a, b);\n    copy(all(a),\
    \ dp.begin() + (1 << i));\n  }\n  return dp;\n}\n#line 1 \"enumerate/bits.hpp\"\
    \ntemplate <typename F>\nvoid enumerate_bits_32(u32 s, F f) {\n  while (s) {\n\
    \    int i = __builtin_ctz(s);\n    f(i);\n    s ^= 1 << i;\n  }\n}\n\ntemplate\
    \ <typename F>\nvoid enumerate_bits_64(u64 s, F f) {\n  while (s) {\n    int i\
    \ = __builtin_ctzll(s);\n    f(i);\n    s ^= u64(1) << i;\n  }\n}\n\ntemplate\
    \ <typename BS, typename F>\nvoid enumerate_bits_bitset(BS& b, int L, int R, F\
    \ f) {\n  int p = (b[L] ? L : b._Find_next(L));\n  while (p < R) {\n    f(p);\n\
    \    p = b._Find_next(p);\n  }\n}\n#line 3 \"linalg/hafnian.hpp\"\n\r\n// \u96A3\
    \u63A5\u884C\u5217\u306B\u5BFE\u3057\u3066\u5B8C\u5168\u30DE\u30C3\u30C1\u30F3\
    \u30B0\u3092\u6570\u3048\u308B\u3002\r\ntemplate <typename mint, int LIM = 20>\r\
    \nmint Hufnian(vc<vc<mint>>& mat) {\r\n  int N = len(mat);\r\n  int n = N / 2;\r\
    \n  assert(n <= LIM);\r\n  vc<mint> cyc(1 << n);\r\n\r\n  FOR(i, N / 2) {\r\n\
    \    int A = 2 * i + 0, B = 2 * i + 1;\r\n    int K = 2 * i;\r\n    cyc[1 << i]\
    \ += mat[A][B];\r\n    vc<mint> dp(K << i);\r\n    for (int j = 0; j < i; ++j)\
    \ {\r\n      int j0 = 2 * j + 0, j1 = 2 * j + 1;\r\n      dp[(K << j) + j0] +=\
    \ mat[A][j1], dp[(K << j) + j1] += mat[A][j0];\r\n    }\r\n    for (int s = 0;\
    \ s < (1 << i); ++s) {\r\n      for (int j = 0; j < i; ++j) {\r\n        int j0\
    \ = 2 * j + 0, j1 = 2 * j + 1;\r\n        cyc[s | 1 << i] += dp[K * s + j0] *\
    \ mat[B][j0];\r\n        cyc[s | 1 << i] += dp[K * s + j1] * mat[B][j1];\r\n \
    \       enumerate_bits_32((1 << i) - 1 - s, [&](int k) -> void {\r\n         \
    \ int k0 = 2 * k + 0, k1 = 2 * k + 1;\r\n          int t = s | 1 << k;\r\n   \
    \       dp[K * t + k0] += dp[K * s + j0] * mat[j0][k1];\r\n          dp[K * t\
    \ + k0] += dp[K * s + j1] * mat[j1][k1];\r\n          dp[K * t + k1] += dp[K *\
    \ s + j0] * mat[j0][k0];\r\n          dp[K * t + k1] += dp[K * s + j1] * mat[j1][k0];\r\
    \n        });\r\n      }\r\n    }\r\n  }\r\n  return sps_exp<mint, LIM>(cyc).back();\r\
    \n}\r\n"
  code: "#include \"setfunc/sps_exp.hpp\"\r\n#include \"enumerate/bits.hpp\"\r\n\r\
    \n// \u96A3\u63A5\u884C\u5217\u306B\u5BFE\u3057\u3066\u5B8C\u5168\u30DE\u30C3\u30C1\
    \u30F3\u30B0\u3092\u6570\u3048\u308B\u3002\r\ntemplate <typename mint, int LIM\
    \ = 20>\r\nmint Hufnian(vc<vc<mint>>& mat) {\r\n  int N = len(mat);\r\n  int n\
    \ = N / 2;\r\n  assert(n <= LIM);\r\n  vc<mint> cyc(1 << n);\r\n\r\n  FOR(i, N\
    \ / 2) {\r\n    int A = 2 * i + 0, B = 2 * i + 1;\r\n    int K = 2 * i;\r\n  \
    \  cyc[1 << i] += mat[A][B];\r\n    vc<mint> dp(K << i);\r\n    for (int j = 0;\
    \ j < i; ++j) {\r\n      int j0 = 2 * j + 0, j1 = 2 * j + 1;\r\n      dp[(K <<\
    \ j) + j0] += mat[A][j1], dp[(K << j) + j1] += mat[A][j0];\r\n    }\r\n    for\
    \ (int s = 0; s < (1 << i); ++s) {\r\n      for (int j = 0; j < i; ++j) {\r\n\
    \        int j0 = 2 * j + 0, j1 = 2 * j + 1;\r\n        cyc[s | 1 << i] += dp[K\
    \ * s + j0] * mat[B][j0];\r\n        cyc[s | 1 << i] += dp[K * s + j1] * mat[B][j1];\r\
    \n        enumerate_bits_32((1 << i) - 1 - s, [&](int k) -> void {\r\n       \
    \   int k0 = 2 * k + 0, k1 = 2 * k + 1;\r\n          int t = s | 1 << k;\r\n \
    \         dp[K * t + k0] += dp[K * s + j0] * mat[j0][k1];\r\n          dp[K *\
    \ t + k0] += dp[K * s + j1] * mat[j1][k1];\r\n          dp[K * t + k1] += dp[K\
    \ * s + j0] * mat[j0][k0];\r\n          dp[K * t + k1] += dp[K * s + j1] * mat[j1][k0];\r\
    \n        });\r\n      }\r\n    }\r\n  }\r\n  return sps_exp<mint, LIM>(cyc).back();\r\
    \n}\r\n"
  dependsOn:
  - setfunc/sps_exp.hpp
  - setfunc/subset_convolution.hpp
  - setfunc/ranked_zeta.hpp
  - enumerate/bits.hpp
  isVerificationFile: false
  path: linalg/hafnian.hpp
  requiredBy: []
  timestamp: '2023-09-23 23:33:32+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/library_checker/matrix/hafnian_of_matrix.test.cpp
documentation_of: linalg/hafnian.hpp
layout: document
redirect_from:
- /library/linalg/hafnian.hpp
- /library/linalg/hafnian.hpp.html
title: linalg/hafnian.hpp
---
