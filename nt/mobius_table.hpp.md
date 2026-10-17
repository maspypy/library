---
data:
  _extendedDependsOn:
  - icon: ':question:'
    path: nt/prime_table.hpp
    title: nt/prime_table.hpp
  - icon: ':question:'
    path: nt/zeta.hpp
    title: nt/zeta.hpp
  _extendedRequiredBy:
  - icon: ':x:'
    path: nt/mertens.hpp
    title: nt/mertens.hpp
  - icon: ':x:'
    path: nt/range_rational_count.hpp
    title: nt/range_rational_count.hpp
  _extendedVerifiedWith:
  - icon: ':x:'
    path: test/3_yukicoder/1760.test.cpp
    title: test/3_yukicoder/1760.test.cpp
  - icon: ':x:'
    path: test/3_yukicoder/2266.test.cpp
    title: test/3_yukicoder/2266.test.cpp
  _isVerificationFailed: true
  _pathExtension: hpp
  _verificationStatusIcon: ':x:'
  attributes:
    links:
    - https://github.com/maspypy/library/blob/main/nt/mobius_table.hpp
  bundledCode: "#line 1 \"nt/mobius_table.hpp\"\n// Source: https://github.com/maspypy/library/blob/main/nt/mobius_table.hpp\n\
    #line 1 \"nt/zeta.hpp\"\n// Source: https://github.com/maspypy/library/blob/main/nt/zeta.hpp\n\
    #line 1 \"nt/prime_table.hpp\"\n// Source: https://github.com/maspypy/library/blob/main/nt/prime_table.hpp\n\
    \ntemplate <typename T = int>\nvc<T> prime_table(int LIM) {\n  ++LIM;\n  const\
    \ int S = 32768;\n  static int done = 2;\n  static vc<T> primes = {2}, sieve(S\
    \ + 1);\n\n  if (done < LIM) {\n    done = LIM;\n\n    primes = {2}, sieve.assign(S\
    \ + 1, 0);\n    const int R = LIM / 2;\n    primes.reserve(int(LIM / log(LIM)\
    \ * 1.1));\n    vc<pair<int, int>> cp;\n    for (int i = 3; i <= S; i += 2) {\n\
    \      if (!sieve[i]) {\n        cp.eb(i, i * i / 2);\n        for (int j = i\
    \ * i; j <= S; j += 2 * i) sieve[j] = 1;\n      }\n    }\n    for (int L = 1;\
    \ L <= R; L += S) {\n      array<bool, S> block{};\n      for (auto& [p, idx]\
    \ : cp)\n        for (int i = idx; i < S + L; idx = (i += p)) block[i - L] = 1;\n\
    \      FOR(i, min(S, R - L)) if (!block[i]) primes.eb((L + i) * 2 + 1);\n    }\n\
    \  }\n  int k = LB(primes, LIM);\n  return {primes.begin(), primes.begin() + k};\n\
    }\n#line 3 \"nt/zeta.hpp\"\n\ntemplate <typename T>\nvoid divisor_zeta(vc<T>&\
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
    #line 3 \"nt/mobius_table.hpp\"\n\ntemplate <typename T>\nvc<T> mobius_table(int\
    \ N) {\n  vc<T> mu(N + 1);\n  if (1 <= N) mu[1] = T(1);\n  divisor_mobius(mu);\n\
    \  return mu;\n}\n"
  code: "// Source: https://github.com/maspypy/library/blob/main/nt/mobius_table.hpp\n\
    #include \"nt/zeta.hpp\"\n\ntemplate <typename T>\nvc<T> mobius_table(int N) {\n\
    \  vc<T> mu(N + 1);\n  if (1 <= N) mu[1] = T(1);\n  divisor_mobius(mu);\n  return\
    \ mu;\n}"
  dependsOn:
  - nt/zeta.hpp
  - nt/prime_table.hpp
  isVerificationFile: false
  path: nt/mobius_table.hpp
  requiredBy:
  - nt/range_rational_count.hpp
  - nt/mertens.hpp
  timestamp: '2026-10-15 19:54:56+09:00'
  verificationStatus: LIBRARY_ALL_WA
  verifiedWith:
  - test/3_yukicoder/1760.test.cpp
  - test/3_yukicoder/2266.test.cpp
documentation_of: nt/mobius_table.hpp
layout: document
redirect_from:
- /library/nt/mobius_table.hpp
- /library/nt/mobius_table.hpp.html
title: nt/mobius_table.hpp
---
