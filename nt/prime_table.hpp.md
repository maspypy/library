---
data:
  _extendedDependsOn: []
  _extendedRequiredBy:
  - icon: ':heavy_check_mark:'
    path: mod/modfast.hpp
    title: mod/modfast.hpp
  - icon: ':heavy_check_mark:'
    path: mod/tetration.hpp
    title: mod/tetration.hpp
  - icon: ':warning:'
    path: nt/all_lcm.hpp
    title: nt/all_lcm.hpp
  - icon: ':heavy_check_mark:'
    path: nt/euler_phi.hpp
    title: nt/euler_phi.hpp
  - icon: ':warning:'
    path: nt/find_coprime_pair.hpp
    title: nt/find_coprime_pair.hpp
  - icon: ':heavy_check_mark:'
    path: nt/gcd_convolution.hpp
    title: nt/gcd_convolution.hpp
  - icon: ':heavy_check_mark:'
    path: nt/lcm_convolution.hpp
    title: nt/lcm_convolution.hpp
  - icon: ':heavy_check_mark:'
    path: nt/lpf_table.hpp
    title: nt/lpf_table.hpp
  - icon: ':heavy_check_mark:'
    path: nt/mertens.hpp
    title: nt/mertens.hpp
  - icon: ':heavy_check_mark:'
    path: nt/mobius_table.hpp
    title: nt/mobius_table.hpp
  - icon: ':heavy_check_mark:'
    path: nt/range_rational_count.hpp
    title: nt/range_rational_count.hpp
  - icon: ':question:'
    path: nt/zeta.hpp
    title: nt/zeta.hpp
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/1_mytest/modfast.test.cpp
    title: test/1_mytest/modfast.test.cpp
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
    path: test/3_yukicoder/1411.test.cpp
    title: test/3_yukicoder/1411.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/3_yukicoder/1575.test.cpp
    title: test/3_yukicoder/1575.test.cpp
  - icon: ':x:'
    path: test/3_yukicoder/1666.test.cpp
    title: test/3_yukicoder/1666.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/3_yukicoder/1881.test.cpp
    title: test/3_yukicoder/1881.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/3_yukicoder/2266.test.cpp
    title: test/3_yukicoder/2266.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/4_aoj/NTL_1_D.test.cpp
    title: test/4_aoj/NTL_1_D.test.cpp
  _isVerificationFailed: true
  _pathExtension: hpp
  _verificationStatusIcon: ':question:'
  attributes:
    links: []
  bundledCode: "#line 2 \"nt/prime_table.hpp\"\n\ntemplate <typename T = int>\nvc<T>\
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
    \ {primes.begin(), primes.begin() + k};\n}\n"
  code: "#pragma once\n\ntemplate <typename T = int>\nvc<T> prime_table(int LIM) {\n\
    \  ++LIM;\n  const int S = 32768;\n  static int done = 2;\n  static vc<T> primes\
    \ = {2}, sieve(S + 1);\n\n  if (done < LIM) {\n    done = LIM;\n\n    primes =\
    \ {2}, sieve.assign(S + 1, 0);\n    const int R = LIM / 2;\n    primes.reserve(int(LIM\
    \ / log(LIM) * 1.1));\n    vc<pair<int, int>> cp;\n    for (int i = 3; i <= S;\
    \ i += 2) {\n      if (!sieve[i]) {\n        cp.eb(i, i * i / 2);\n        for\
    \ (int j = i * i; j <= S; j += 2 * i) sieve[j] = 1;\n      }\n    }\n    for (int\
    \ L = 1; L <= R; L += S) {\n      array<bool, S> block{};\n      for (auto& [p,\
    \ idx] : cp)\n        for (int i = idx; i < S + L; idx = (i += p)) block[i - L]\
    \ = 1;\n      FOR(i, min(S, R - L)) if (!block[i]) primes.eb((L + i) * 2 + 1);\n\
    \    }\n  }\n  int k = LB(primes, LIM + 1);\n  return {primes.begin(), primes.begin()\
    \ + k};\n}\n"
  dependsOn: []
  isVerificationFile: false
  path: nt/prime_table.hpp
  requiredBy:
  - nt/zeta.hpp
  - nt/all_lcm.hpp
  - nt/find_coprime_pair.hpp
  - nt/mobius_table.hpp
  - nt/euler_phi.hpp
  - nt/mertens.hpp
  - nt/lcm_convolution.hpp
  - nt/gcd_convolution.hpp
  - nt/range_rational_count.hpp
  - nt/lpf_table.hpp
  - mod/tetration.hpp
  - mod/modfast.hpp
  timestamp: '2026-08-15 15:50:39+09:00'
  verificationStatus: LIBRARY_SOME_WA
  verifiedWith:
  - test/1_mytest/modfast.test.cpp
  - test/2_library_checker/convolution/gcd_convolution.test.cpp
  - test/2_library_checker/convolution/lcm_convolution.test.cpp
  - test/2_library_checker/number_theory/tetration.test.cpp
  - test/4_aoj/NTL_1_D.test.cpp
  - test/3_yukicoder/1262.test.cpp
  - test/3_yukicoder/1881.test.cpp
  - test/3_yukicoder/1411.test.cpp
  - test/3_yukicoder/1575.test.cpp
  - test/3_yukicoder/1666.test.cpp
  - test/3_yukicoder/2266.test.cpp
documentation_of: nt/prime_table.hpp
layout: document
redirect_from:
- /library/nt/prime_table.hpp
- /library/nt/prime_table.hpp.html
title: nt/prime_table.hpp
---
