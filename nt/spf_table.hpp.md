---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: nt/prime_table.hpp
    title: nt/prime_table.hpp
  _extendedRequiredBy:
  - icon: ':heavy_check_mark:'
    path: mod/modfast.hpp
    title: mod/modfast.hpp
  - icon: ':warning:'
    path: nt/all_lcm.hpp
    title: nt/all_lcm.hpp
  - icon: ':warning:'
    path: nt/find_coprime_pair.hpp
    title: nt/find_coprime_pair.hpp
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/1_mytest/modfast.test.cpp
    title: test/1_mytest/modfast.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/3_yukicoder/1411.test.cpp
    title: test/3_yukicoder/1411.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/3_yukicoder/1575.test.cpp
    title: test/3_yukicoder/1575.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/3_yukicoder/1881.test.cpp
    title: test/3_yukicoder/1881.test.cpp
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
    \ {primes.begin(), primes.begin() + k};\n}\n#line 2 \"nt/spf_table.hpp\"\n\n//\
    \ [0, LIM], 0, 1 \u306B\u306F -1 \u304C\u5165\u308B\u3002\nvc<int> spf_table(int\
    \ LIM) {\n  auto primes = prime_table(LIM);\n  vc<int> spf(LIM + 1, -1);\n  int\
    \ sq = sqrt(LIM);\n  for (int i = 2; i <= LIM; i += 2) spf[i] = 2;\n  FOR_R(i,\
    \ len(primes)) {\n    auto p = primes[i];\n    spf[p] = p;\n    if (sq < p) continue;\n\
    \    for (int k = p * p; k <= LIM; k += 2 * p) spf[k] = p;\n  }\n  return spf;\n\
    }\n"
  code: "#include \"nt/prime_table.hpp\"\n\n// [0, LIM], 0, 1 \u306B\u306F -1 \u304C\
    \u5165\u308B\u3002\nvc<int> spf_table(int LIM) {\n  auto primes = prime_table(LIM);\n\
    \  vc<int> spf(LIM + 1, -1);\n  int sq = sqrt(LIM);\n  for (int i = 2; i <= LIM;\
    \ i += 2) spf[i] = 2;\n  FOR_R(i, len(primes)) {\n    auto p = primes[i];\n  \
    \  spf[p] = p;\n    if (sq < p) continue;\n    for (int k = p * p; k <= LIM; k\
    \ += 2 * p) spf[k] = p;\n  }\n  return spf;\n}\n"
  dependsOn:
  - nt/prime_table.hpp
  isVerificationFile: false
  path: nt/spf_table.hpp
  requiredBy:
  - nt/all_lcm.hpp
  - nt/find_coprime_pair.hpp
  - mod/modfast.hpp
  timestamp: '2026-09-16 20:09:04+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/1_mytest/modfast.test.cpp
  - test/3_yukicoder/1411.test.cpp
  - test/3_yukicoder/1575.test.cpp
  - test/3_yukicoder/1881.test.cpp
documentation_of: nt/spf_table.hpp
layout: document
redirect_from:
- /library/nt/spf_table.hpp
- /library/nt/spf_table.hpp.html
title: nt/spf_table.hpp
---
