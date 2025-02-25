---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: nt/primetable.hpp
    title: nt/primetable.hpp
  - icon: ':heavy_check_mark:'
    path: nt/zeta.hpp
    title: nt/zeta.hpp
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/2_library_checker/convolution/gcd_convolution.test.cpp
    title: test/2_library_checker/convolution/gcd_convolution.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 2 \"nt/primetable.hpp\"\n\ntemplate <typename T = int>\nvc<T>\
    \ primetable(int LIM) {\n  ++LIM;\n  const int S = 32768;\n  static int done =\
    \ 2;\n  static vc<T> primes = {2}, sieve(S + 1);\n\n  if (done < LIM) {\n    done\
    \ = LIM;\n\n    primes = {2}, sieve.assign(S + 1, 0);\n    const int R = LIM /\
    \ 2;\n    primes.reserve(int(LIM / log(LIM) * 1.1));\n    vc<pair<int, int>> cp;\n\
    \    for (int i = 3; i <= S; i += 2) {\n      if (!sieve[i]) {\n        cp.eb(i,\
    \ i * i / 2);\n        for (int j = i * i; j <= S; j += 2 * i) sieve[j] = 1;\n\
    \      }\n    }\n    for (int L = 1; L <= R; L += S) {\n      array<bool, S> block{};\n\
    \      for (auto& [p, idx]: cp)\n        for (int i = idx; i < S + L; idx = (i\
    \ += p)) block[i - L] = 1;\n      FOR(i, min(S, R - L)) if (!block[i]) primes.eb((L\
    \ + i) * 2 + 1);\n    }\n  }\n  int k = LB(primes, LIM + 1);\n  return {primes.begin(),\
    \ primes.begin() + k};\n}\n#line 3 \"nt/zeta.hpp\"\n\r\ntemplate <typename T>\r\
    \nvoid divisor_zeta(vc<T>& A) {\r\n  assert(A[0] == 0);\r\n  int N = len(A) -\
    \ 1;\r\n  auto P = primetable(N);\r\n  for (auto&& p: P) { FOR3(x, 1, N / p +\
    \ 1) A[p * x] += A[x]; }\r\n}\r\n\r\ntemplate <typename T>\r\nvoid divisor_mobius(vc<T>&\
    \ A) {\r\n  assert(A[0] == 0);\r\n  int N = len(A) - 1;\r\n  auto P = primetable(N);\r\
    \n  for (auto&& p: P) { FOR3_R(x, 1, N / p + 1) A[p * x] -= A[x]; }\r\n}\r\n\r\
    \ntemplate <typename T>\r\nvoid multiplier_zeta(vc<T>& A) {\r\n  assert(A[0] ==\
    \ 0);\r\n  int N = len(A) - 1;\r\n  auto P = primetable(N);\r\n  for (auto&& p:\
    \ P) { FOR3_R(x, 1, N / p + 1) A[x] += A[p * x]; }\r\n}\r\n\r\ntemplate <typename\
    \ T>\r\nvoid multiplier_mobius(vc<T>& A) {\r\n  assert(A[0] == 0);\r\n  int N\
    \ = len(A) - 1;\r\n  auto P = primetable(N);\r\n  for (auto&& p: P) { FOR3(x,\
    \ 1, N / p + 1) A[x] -= A[p * x]; }\r\n}\r\n#line 2 \"nt/gcd_convolution.hpp\"\
    \n\ntemplate <typename T>\nvc<T> gcd_convolution(vc<T> A, vc<T>& B) {\n  assert(len(A)\
    \ == len(B));\n  multiplier_zeta(A);\n  multiplier_zeta(B);\n  FOR(i, len(A))\
    \ A[i] *= B[i];\n  multiplier_mobius(A);\n  return A;\n}\n"
  code: "#include \"nt/zeta.hpp\"\n\ntemplate <typename T>\nvc<T> gcd_convolution(vc<T>\
    \ A, vc<T>& B) {\n  assert(len(A) == len(B));\n  multiplier_zeta(A);\n  multiplier_zeta(B);\n\
    \  FOR(i, len(A)) A[i] *= B[i];\n  multiplier_mobius(A);\n  return A;\n}\n"
  dependsOn:
  - nt/zeta.hpp
  - nt/primetable.hpp
  isVerificationFile: false
  path: nt/gcd_convolution.hpp
  requiredBy: []
  timestamp: '2023-08-06 03:59:07+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/2_library_checker/convolution/gcd_convolution.test.cpp
documentation_of: nt/gcd_convolution.hpp
layout: document
redirect_from:
- /library/nt/gcd_convolution.hpp
- /library/nt/gcd_convolution.hpp.html
title: nt/gcd_convolution.hpp
---
