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
  - icon: ':heavy_check_mark:'
    path: test/3_yukicoder/1760.test.cpp
    title: test/3_yukicoder/1760.test.cpp
  - icon: ':x:'
    path: test/3_yukicoder/2266.test.cpp
    title: test/3_yukicoder/2266.test.cpp
  _isVerificationFailed: true
  _pathExtension: hpp
  _verificationStatusIcon: ':question:'
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
    \ primes.eb((L + i) * 2 + 1);\n    }\n  }\n  int k = LB(primes, LIM + 1);\n  return\
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
    \ A[x] -= A[p * x];\n  }\n}\n#line 2 \"nt/mobius_table.hpp\"\n\r\ntemplate<typename\
    \ T>\r\nvc<T> mobius_table(int N){\r\n  vc<T> mu(N + 1);\r\n  mu[1] = T(1);\r\n\
    \  divisor_mobius(mu);\r\n  return mu;\r\n}\n"
  code: "#include \"nt/zeta.hpp\"\r\n\r\ntemplate<typename T>\r\nvc<T> mobius_table(int\
    \ N){\r\n  vc<T> mu(N + 1);\r\n  mu[1] = T(1);\r\n  divisor_mobius(mu);\r\n  return\
    \ mu;\r\n}"
  dependsOn:
  - nt/zeta.hpp
  - nt/prime_table.hpp
  isVerificationFile: false
  path: nt/mobius_table.hpp
  requiredBy:
  - nt/mertens.hpp
  - nt/range_rational_count.hpp
  timestamp: '2026-08-16 04:03:00+09:00'
  verificationStatus: LIBRARY_SOME_WA
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
