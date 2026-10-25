---
data:
  _extendedDependsOn:
  - icon: ':question:'
    path: nt/prime_table.hpp
    title: nt/prime_table.hpp
  - icon: ':heavy_check_mark:'
    path: nt/zeta.hpp
    title: nt/zeta.hpp
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/2_library_checker/convolution/lcm_convolution.test.cpp
    title: test/2_library_checker/convolution/lcm_convolution.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/3_yukicoder/1760.test.cpp
    title: test/3_yukicoder/1760.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links:
    - https://github.com/maspypy/library/blob/main/nt/lcm_convolution.hpp
  bundledCode: "#line 1 \"nt/lcm_convolution.hpp\"\n// Source: https://github.com/maspypy/library/blob/main/nt/lcm_convolution.hpp\n\
    #line 1 \"nt/zeta.hpp\"\n// Source: https://github.com/maspypy/library/blob/main/nt/zeta.hpp\n\
    #line 1 \"nt/prime_table.hpp\"\n// Source: https://github.com/maspypy/library/blob/main/nt/prime_table.hpp\n\
    \ntemplate <typename T = int>\nvc<T> prime_table(int LIM) {\n  assert(LIM <= infty<int>);\n\
    \  ++LIM;\n  const int S = 32768;\n  static int done = 2;\n  static vc<T> primes\
    \ = {2}, sieve(S + 1);\n\n  if (done < LIM) {\n    done = LIM;\n\n    primes =\
    \ {2}, sieve.assign(S + 1, 0);\n    const int R = LIM / 2;\n    primes.reserve(int(LIM\
    \ / log(LIM) * 1.1));\n    vc<pair<int, int>> cp;\n    for (int i = 3; i <= S;\
    \ i += 2) {\n      if (!sieve[i]) {\n        cp.eb(i, i * i / 2);\n        for\
    \ (int j = i * i; j <= S; j += 2 * i) sieve[j] = 1;\n      }\n    }\n    for (int\
    \ L = 1; L <= R; L += S) {\n      array<bool, S> block{};\n      for (auto& [p,\
    \ idx] : cp)\n        for (int i = idx; i < S + L; idx = (i += p)) block[i - L]\
    \ = 1;\n      FOR(i, min(S, R - L)) if (!block[i]) primes.eb((L + i) * 2 + 1);\n\
    \    }\n  }\n  int k = LB(primes, LIM);\n  return {primes.begin(), primes.begin()\
    \ + k};\n}\n#line 3 \"nt/zeta.hpp\"\n\ntemplate <typename T>\nvoid divisor_zeta(vc<T>&\
    \ A) {\n  assert(A[0] == 0);\n  int N = len(A) - 1;\n  auto P = prime_table(N);\n\
    \  for (auto&& p : P) {\n    FOR3(x, 1, N / p + 1) A[p * x] += A[x];\n  }\n}\n\
    \ntemplate <typename T>\nvoid divisor_mobius(vc<T>& A) {\n  assert(A[0] == 0);\n\
    \  int N = len(A) - 1;\n  auto P = prime_table(N);\n  for (auto&& p : P) {\n \
    \   FOR3_R(x, 1, N / p + 1) A[p * x] -= A[x];\n  }\n}\n\ntemplate <typename T>\n\
    void multiple_zeta(vc<T>& A) {\n  assert(A[0] == 0);\n  int N = len(A) - 1;\n\
    \  auto P = prime_table(N);\n  for (auto&& p : P) {\n    FOR3_R(x, 1, N / p +\
    \ 1) A[x] += A[p * x];\n  }\n}\n\ntemplate <typename T>\nvoid multiple_mobius(vc<T>&\
    \ A) {\n  assert(A[0] == 0);\n  int N = len(A) - 1;\n  auto P = prime_table(N);\n\
    \  for (auto&& p : P) {\n    FOR3(x, 1, N / p + 1) A[x] -= A[p * x];\n  }\n}\n\
    #line 3 \"nt/lcm_convolution.hpp\"\n\ntemplate <typename T>\nvc<T> lcm_convolution(vc<T>\
    \ A, vc<T>& B) {\n  assert(len(A) == len(B));\n  divisor_zeta(A);\n  divisor_zeta(B);\n\
    \  FOR(i, len(A)) A[i] *= B[i];\n  divisor_mobius(A);\n  return A;\n}\n"
  code: "// Source: https://github.com/maspypy/library/blob/main/nt/lcm_convolution.hpp\n\
    #include \"nt/zeta.hpp\"\n\ntemplate <typename T>\nvc<T> lcm_convolution(vc<T>\
    \ A, vc<T>& B) {\n  assert(len(A) == len(B));\n  divisor_zeta(A);\n  divisor_zeta(B);\n\
    \  FOR(i, len(A)) A[i] *= B[i];\n  divisor_mobius(A);\n  return A;\n}\n"
  dependsOn:
  - nt/zeta.hpp
  - nt/prime_table.hpp
  isVerificationFile: false
  path: nt/lcm_convolution.hpp
  requiredBy: []
  timestamp: '2026-10-24 09:51:44+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/3_yukicoder/1760.test.cpp
  - test/2_library_checker/convolution/lcm_convolution.test.cpp
documentation_of: nt/lcm_convolution.hpp
layout: document
redirect_from:
- /library/nt/lcm_convolution.hpp
- /library/nt/lcm_convolution.hpp.html
title: nt/lcm_convolution.hpp
---
