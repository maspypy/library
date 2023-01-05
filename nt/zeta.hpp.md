---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: nt/primetable.hpp
    title: nt/primetable.hpp
  _extendedRequiredBy:
  - icon: ':heavy_check_mark:'
    path: mod/tetration.hpp
    title: mod/tetration.hpp
  - icon: ':heavy_check_mark:'
    path: nt/euler_phi.hpp
    title: nt/euler_phi.hpp
  - icon: ':heavy_check_mark:'
    path: nt/gcd_convolution.hpp
    title: nt/gcd_convolution.hpp
  - icon: ':heavy_check_mark:'
    path: nt/lcm_convolution.hpp
    title: nt/lcm_convolution.hpp
  - icon: ':heavy_check_mark:'
    path: nt/mobius_table.hpp
    title: nt/mobius_table.hpp
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/aoj/NTL_1_D.test.cpp
    title: test/aoj/NTL_1_D.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/library_checker/math/gcd_convolution.test.cpp
    title: test/library_checker/math/gcd_convolution.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/library_checker/math/lcm_convolution.test.cpp
    title: test/library_checker/math/lcm_convolution.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/library_checker/math/tetration.test.cpp
    title: test/library_checker/math/tetration.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/yukicoder/1262.test.cpp
    title: test/yukicoder/1262.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/yukicoder/1666.test.cpp
    title: test/yukicoder/1666.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/yukicoder/1760.test.cpp
    title: test/yukicoder/1760.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 2 \"nt/primetable.hpp\"\n\ntemplate <typename T = long long>\n\
    vc<T> primetable(int LIM) {\n  ++LIM;\n  const int S = 32768;\n  static int done\
    \ = 2;\n  static vc<T> primes = {2}, sieve(S + 1);\n\n  if (done < LIM) {\n  \
    \  done = LIM;\n\n    primes = {2}, sieve.assign(S + 1, 0);\n    const int R =\
    \ LIM / 2;\n    primes.reserve(int(LIM / log(LIM) * 1.1));\n    vc<pair<int, int>>\
    \ cp;\n    for (int i = 3; i <= S; i += 2) {\n      if (!sieve[i]) {\n       \
    \ cp.eb(i, i * i / 2);\n        for (int j = i * i; j <= S; j += 2 * i) sieve[j]\
    \ = 1;\n      }\n    }\n    for (int L = 1; L <= R; L += S) {\n      array<bool,\
    \ S> block{};\n      for (auto& [p, idx]: cp)\n        for (int i = idx; i < S\
    \ + L; idx = (i += p)) block[i - L] = 1;\n      FOR(i, min(S, R - L)) if (!block[i])\
    \ primes.eb((L + i) * 2 + 1);\n    }\n  }\n  int k = LB(primes, LIM + 1);\n  return\
    \ {primes.begin(), primes.begin() + k};\n}\n#line 3 \"nt/zeta.hpp\"\n\r\ntemplate\
    \ <typename T>\r\nvoid divisor_zeta(vc<T>& A) {\r\n  assert(A[0] == 0);\r\n  int\
    \ N = len(A) - 1;\r\n  auto P = primetable(N);\r\n  for (auto&& p: P) { FOR3(x,\
    \ 1, N / p + 1) A[p * x] += A[x]; }\r\n}\r\n\r\ntemplate <typename T>\r\nvoid\
    \ divisor_mobius(vc<T>& A) {\r\n  assert(A[0] == 0);\r\n  int N = len(A) - 1;\r\
    \n  auto P = primetable(N);\r\n  for (auto&& p: P) { FOR3_R(x, 1, N / p + 1) A[p\
    \ * x] -= A[x]; }\r\n}\r\n\r\ntemplate <typename T>\r\nvoid multiplier_zeta(vc<T>&\
    \ A) {\r\n  assert(A[0] == 0);\r\n  int N = len(A) - 1;\r\n  auto P = primetable(N);\r\
    \n  for (auto&& p: P) { FOR3_R(x, 1, N / p + 1) A[x] += A[p * x]; }\r\n}\r\n\r\
    \ntemplate <typename T>\r\nvoid multiplier_mobius(vc<T>& A) {\r\n  assert(A[0]\
    \ == 0);\r\n  int N = len(A) - 1;\r\n  auto P = primetable(N);\r\n  for (auto&&\
    \ p: P) { FOR3(x, 1, N / p + 1) A[x] -= A[p * x]; }\r\n}\r\n"
  code: "#pragma once\r\n#include \"nt/primetable.hpp\"\r\n\r\ntemplate <typename\
    \ T>\r\nvoid divisor_zeta(vc<T>& A) {\r\n  assert(A[0] == 0);\r\n  int N = len(A)\
    \ - 1;\r\n  auto P = primetable(N);\r\n  for (auto&& p: P) { FOR3(x, 1, N / p\
    \ + 1) A[p * x] += A[x]; }\r\n}\r\n\r\ntemplate <typename T>\r\nvoid divisor_mobius(vc<T>&\
    \ A) {\r\n  assert(A[0] == 0);\r\n  int N = len(A) - 1;\r\n  auto P = primetable(N);\r\
    \n  for (auto&& p: P) { FOR3_R(x, 1, N / p + 1) A[p * x] -= A[x]; }\r\n}\r\n\r\
    \ntemplate <typename T>\r\nvoid multiplier_zeta(vc<T>& A) {\r\n  assert(A[0] ==\
    \ 0);\r\n  int N = len(A) - 1;\r\n  auto P = primetable(N);\r\n  for (auto&& p:\
    \ P) { FOR3_R(x, 1, N / p + 1) A[x] += A[p * x]; }\r\n}\r\n\r\ntemplate <typename\
    \ T>\r\nvoid multiplier_mobius(vc<T>& A) {\r\n  assert(A[0] == 0);\r\n  int N\
    \ = len(A) - 1;\r\n  auto P = primetable(N);\r\n  for (auto&& p: P) { FOR3(x,\
    \ 1, N / p + 1) A[x] -= A[p * x]; }\r\n}\r\n"
  dependsOn:
  - nt/primetable.hpp
  isVerificationFile: false
  path: nt/zeta.hpp
  requiredBy:
  - nt/euler_phi.hpp
  - nt/mobius_table.hpp
  - nt/lcm_convolution.hpp
  - nt/gcd_convolution.hpp
  - mod/tetration.hpp
  timestamp: '2022-12-12 09:21:17+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/aoj/NTL_1_D.test.cpp
  - test/yukicoder/1760.test.cpp
  - test/yukicoder/1262.test.cpp
  - test/yukicoder/1666.test.cpp
  - test/library_checker/math/gcd_convolution.test.cpp
  - test/library_checker/math/lcm_convolution.test.cpp
  - test/library_checker/math/tetration.test.cpp
documentation_of: nt/zeta.hpp
layout: document
redirect_from:
- /library/nt/zeta.hpp
- /library/nt/zeta.hpp.html
title: nt/zeta.hpp
---
