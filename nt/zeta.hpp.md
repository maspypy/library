---
data:
  _extendedDependsOn:
  - icon: ':question:'
    path: nt/prime_table.hpp
    title: nt/prime_table.hpp
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
    path: nt/mertens.hpp
    title: nt/mertens.hpp
  - icon: ':heavy_check_mark:'
    path: nt/mobius_table.hpp
    title: nt/mobius_table.hpp
  - icon: ':heavy_check_mark:'
    path: nt/range_rational_count.hpp
    title: nt/range_rational_count.hpp
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/2_library_checker/convolution/gcd_convolution.test.cpp
    title: test/2_library_checker/convolution/gcd_convolution.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/2_library_checker/convolution/lcm_convolution.test.cpp
    title: test/2_library_checker/convolution/lcm_convolution.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/2_library_checker/number_theory/tetration.test.cpp
    title: test/2_library_checker/number_theory/tetration.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/3_yukicoder/1262.test.cpp
    title: test/3_yukicoder/1262.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/3_yukicoder/1666.test.cpp
    title: test/3_yukicoder/1666.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/3_yukicoder/1760.test.cpp
    title: test/3_yukicoder/1760.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/3_yukicoder/2266.test.cpp
    title: test/3_yukicoder/2266.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/4_aoj/NTL_1_D.test.cpp
    title: test/4_aoj/NTL_1_D.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 1 \"nt/prime_table.hpp\"\n\ntemplate <typename T = int>\nvc<T>\
    \ prime_table(int LIM) {\n  ++LIM;\n  const int S = 32768;\n  static int done\
    \ = 2;\n  static vc<T> primes = {2}, sieve(S + 1);\n\n  if (done < LIM) {\n  \
    \  done = LIM;\n\n    primes = {2}, sieve.assign(S + 1, 0);\n    const int R =\
    \ LIM / 2;\n    primes.reserve(int(LIM / log(LIM) * 1.1));\n    vc<pair<int, int>>\
    \ cp;\n    for (int i = 3; i <= S; i += 2) {\n      if (!sieve[i]) {\n       \
    \ cp.eb(i, i * i / 2);\n        for (int j = i * i; j <= S; j += 2 * i) sieve[j]\
    \ = 1;\n      }\n    }\n    for (int L = 1; L <= R; L += S) {\n      array<bool,\
    \ S> block{};\n      for (auto& [p, idx] : cp)\n        for (int i = idx; i <\
    \ S + L; idx = (i += p)) block[i - L] = 1;\n      FOR(i, min(S, R - L)) if (!block[i])\
    \ primes.eb((L + i) * 2 + 1);\n    }\n  }\n  int k = LB(primes, LIM);\n  return\
    \ {primes.begin(), primes.begin() + k};\n}\n#line 2 \"nt/zeta.hpp\"\n\ntemplate\
    \ <typename T>\nvoid divisor_zeta(vc<T>& A) {\n  assert(A[0] == 0);\n  int N =\
    \ len(A) - 1;\n  auto P = prime_table(N);\n  for (auto&& p : P) {\n    FOR3(x,\
    \ 1, N / p + 1) A[p * x] += A[x];\n  }\n}\n\ntemplate <typename T>\nvoid divisor_mobius(vc<T>&\
    \ A) {\n  assert(A[0] == 0);\n  int N = len(A) - 1;\n  auto P = prime_table(N);\n\
    \  for (auto&& p : P) {\n    FOR3_R(x, 1, N / p + 1) A[p * x] -= A[x];\n  }\n\
    }\n\ntemplate <typename T>\nvoid multiple_zeta(vc<T>& A) {\n  assert(A[0] == 0);\n\
    \  int N = len(A) - 1;\n  auto P = prime_table(N);\n  for (auto&& p : P) {\n \
    \   FOR3_R(x, 1, N / p + 1) A[x] += A[p * x];\n  }\n}\n\ntemplate <typename T>\n\
    void multiple_mobius(vc<T>& A) {\n  assert(A[0] == 0);\n  int N = len(A) - 1;\n\
    \  auto P = prime_table(N);\n  for (auto&& p : P) {\n    FOR3(x, 1, N / p + 1)\
    \ A[x] -= A[p * x];\n  }\n}\n"
  code: "#include \"nt/prime_table.hpp\"\n\ntemplate <typename T>\nvoid divisor_zeta(vc<T>&\
    \ A) {\n  assert(A[0] == 0);\n  int N = len(A) - 1;\n  auto P = prime_table(N);\n\
    \  for (auto&& p : P) {\n    FOR3(x, 1, N / p + 1) A[p * x] += A[x];\n  }\n}\n\
    \ntemplate <typename T>\nvoid divisor_mobius(vc<T>& A) {\n  assert(A[0] == 0);\n\
    \  int N = len(A) - 1;\n  auto P = prime_table(N);\n  for (auto&& p : P) {\n \
    \   FOR3_R(x, 1, N / p + 1) A[p * x] -= A[x];\n  }\n}\n\ntemplate <typename T>\n\
    void multiple_zeta(vc<T>& A) {\n  assert(A[0] == 0);\n  int N = len(A) - 1;\n\
    \  auto P = prime_table(N);\n  for (auto&& p : P) {\n    FOR3_R(x, 1, N / p +\
    \ 1) A[x] += A[p * x];\n  }\n}\n\ntemplate <typename T>\nvoid multiple_mobius(vc<T>&\
    \ A) {\n  assert(A[0] == 0);\n  int N = len(A) - 1;\n  auto P = prime_table(N);\n\
    \  for (auto&& p : P) {\n    FOR3(x, 1, N / p + 1) A[x] -= A[p * x];\n  }\n}\n"
  dependsOn:
  - nt/prime_table.hpp
  isVerificationFile: false
  path: nt/zeta.hpp
  requiredBy:
  - nt/mobius_table.hpp
  - nt/euler_phi.hpp
  - nt/mertens.hpp
  - nt/lcm_convolution.hpp
  - nt/gcd_convolution.hpp
  - nt/range_rational_count.hpp
  - mod/tetration.hpp
  timestamp: '2026-08-31 13:26:17+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/2_library_checker/convolution/gcd_convolution.test.cpp
  - test/2_library_checker/convolution/lcm_convolution.test.cpp
  - test/2_library_checker/number_theory/tetration.test.cpp
  - test/4_aoj/NTL_1_D.test.cpp
  - test/3_yukicoder/1262.test.cpp
  - test/3_yukicoder/1666.test.cpp
  - test/3_yukicoder/1760.test.cpp
  - test/3_yukicoder/2266.test.cpp
documentation_of: nt/zeta.hpp
layout: document
redirect_from:
- /library/nt/zeta.hpp
- /library/nt/zeta.hpp.html
title: nt/zeta.hpp
---
