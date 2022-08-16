---
data:
  _extendedDependsOn: []
  _extendedRequiredBy:
  - icon: ':question:'
    path: mod/powertable.hpp
    title: mod/powertable.hpp
  - icon: ':heavy_check_mark:'
    path: mod/tetration.hpp
    title: mod/tetration.hpp
  - icon: ':heavy_check_mark:'
    path: nt/euler_phi.hpp
    title: nt/euler_phi.hpp
  - icon: ':heavy_check_mark:'
    path: nt/gcd_convolution.hpp
    title: nt/gcd_convolution.hpp
  - icon: ':question:'
    path: nt/lcm_convolution.hpp
    title: nt/lcm_convolution.hpp
  - icon: ':warning:'
    path: nt/lpf_table.hpp
    title: nt/lpf_table.hpp
  - icon: ':x:'
    path: nt/mobius_table.hpp
    title: nt/mobius_table.hpp
  - icon: ':heavy_check_mark:'
    path: nt/multiplicative_sum.hpp
    title: nt/multiplicative_sum.hpp
  - icon: ':heavy_check_mark:'
    path: nt/primesum.hpp
    title: nt/primesum.hpp
  - icon: ':question:'
    path: nt/zeta.hpp
    title: nt/zeta.hpp
  - icon: ':heavy_check_mark:'
    path: poly/poly_taylor_shift.hpp
    title: poly/poly_taylor_shift.hpp
  - icon: ':heavy_check_mark:'
    path: seq/stirling_number_1.hpp
    title: seq/stirling_number_1.hpp
  - icon: ':question:'
    path: seq/stirling_number_2.hpp
    title: seq/stirling_number_2.hpp
  - icon: ':x:'
    path: seq/surjection.hpp
    title: seq/surjection.hpp
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/aoj/NTL_1_D_eulerphi.test.cpp
    title: test/aoj/NTL_1_D_eulerphi.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/library_checker/math/counting_primes.test.cpp
    title: test/library_checker/math/counting_primes.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/library_checker/math/enumerate_primes.test.cpp
    title: test/library_checker/math/enumerate_primes.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/library_checker/math/gcd_convolution.test.cpp
    title: test/library_checker/math/gcd_convolution.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/library_checker/math/lcm_convolution.test.cpp
    title: test/library_checker/math/lcm_convolution.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/library_checker/math/stirling_number_of_the_first_kind.test.cpp
    title: test/library_checker/math/stirling_number_of_the_first_kind.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/library_checker/math/stirling_number_of_the_second_kind.test.cpp
    title: test/library_checker/math/stirling_number_of_the_second_kind.test.cpp
  - icon: ':x:'
    path: test/library_checker/math/sum_of_exp_times_poly.test.cpp
    title: test/library_checker/math/sum_of_exp_times_poly.test.cpp
  - icon: ':x:'
    path: test/library_checker/math/sum_of_exp_times_poly_limit.test.cpp
    title: test/library_checker/math/sum_of_exp_times_poly_limit.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/library_checker/math/tetration.test.cpp
    title: test/library_checker/math/tetration.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/library_checker/math/totient_sum.test.cpp
    title: test/library_checker/math/totient_sum.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/library_checker/polynomial/polynomial_taylor_shift.test.cpp
    title: test/library_checker/polynomial/polynomial_taylor_shift.test.cpp
  - icon: ':x:'
    path: test/yukicoder/1321_surj.test.cpp
    title: test/yukicoder/1321_surj.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/yukicoder/1666_integer_kth_root.test.cpp
    title: test/yukicoder/1666_integer_kth_root.test.cpp
  - icon: ':x:'
    path: test/yukicoder/1760.test.cpp
    title: test/yukicoder/1760.test.cpp
  _isVerificationFailed: true
  _pathExtension: hpp
  _verificationStatusIcon: ':question:'
  attributes:
    links: []
  bundledCode: "#line 2 \"nt/primetable.hpp\"\nvc<ll> primetable(int LIM) {\n  ++LIM;\n\
    \  const int S = 32768;\n  static int done = 2;\n  static vc<ll> primes = {2},\
    \ sieve(S + 1);\n\n  if (done < LIM) {\n    done = LIM;\n\n    primes = {2}, sieve.assign(S\
    \ + 1, 0);\n    const int R = LIM / 2;\n    primes.reserve(int(LIM / log(LIM)\
    \ * 1.1));\n    vc<pi> cp;\n    for (int i = 3; i <= S; i += 2) {\n      if (!sieve[i])\
    \ {\n        cp.eb(i, i * i / 2);\n        for (int j = i * i; j <= S; j += 2\
    \ * i) sieve[j] = 1;\n      }\n    }\n    for (int L = 1; L <= R; L += S) {\n\
    \      array<bool, S> block{};\n      for (auto& [p, idx]: cp)\n        for (int\
    \ i = idx; i < S + L; idx = (i += p)) block[i - L] = 1;\n      FOR(i, min(S, R\
    \ - L)) if (!block[i]) primes.eb((L + i) * 2 + 1);\n    }\n  }\n  int k = LB(primes,\
    \ LIM + 1);\n  return {primes.begin(), primes.begin() + k};\n}\n"
  code: "#pragma once\nvc<ll> primetable(int LIM) {\n  ++LIM;\n  const int S = 32768;\n\
    \  static int done = 2;\n  static vc<ll> primes = {2}, sieve(S + 1);\n\n  if (done\
    \ < LIM) {\n    done = LIM;\n\n    primes = {2}, sieve.assign(S + 1, 0);\n   \
    \ const int R = LIM / 2;\n    primes.reserve(int(LIM / log(LIM) * 1.1));\n   \
    \ vc<pi> cp;\n    for (int i = 3; i <= S; i += 2) {\n      if (!sieve[i]) {\n\
    \        cp.eb(i, i * i / 2);\n        for (int j = i * i; j <= S; j += 2 * i)\
    \ sieve[j] = 1;\n      }\n    }\n    for (int L = 1; L <= R; L += S) {\n     \
    \ array<bool, S> block{};\n      for (auto& [p, idx]: cp)\n        for (int i\
    \ = idx; i < S + L; idx = (i += p)) block[i - L] = 1;\n      FOR(i, min(S, R -\
    \ L)) if (!block[i]) primes.eb((L + i) * 2 + 1);\n    }\n  }\n  int k = LB(primes,\
    \ LIM + 1);\n  return {primes.begin(), primes.begin() + k};\n}\n"
  dependsOn: []
  isVerificationFile: false
  path: nt/primetable.hpp
  requiredBy:
  - mod/powertable.hpp
  - mod/tetration.hpp
  - nt/multiplicative_sum.hpp
  - nt/mobius_table.hpp
  - nt/gcd_convolution.hpp
  - nt/primesum.hpp
  - nt/euler_phi.hpp
  - nt/lcm_convolution.hpp
  - nt/zeta.hpp
  - nt/lpf_table.hpp
  - poly/poly_taylor_shift.hpp
  - seq/surjection.hpp
  - seq/stirling_number_1.hpp
  - seq/stirling_number_2.hpp
  timestamp: '2022-04-16 04:26:49+09:00'
  verificationStatus: LIBRARY_SOME_WA
  verifiedWith:
  - test/yukicoder/1760.test.cpp
  - test/yukicoder/1321_surj.test.cpp
  - test/yukicoder/1666_integer_kth_root.test.cpp
  - test/library_checker/polynomial/polynomial_taylor_shift.test.cpp
  - test/library_checker/math/lcm_convolution.test.cpp
  - test/library_checker/math/sum_of_exp_times_poly_limit.test.cpp
  - test/library_checker/math/enumerate_primes.test.cpp
  - test/library_checker/math/stirling_number_of_the_second_kind.test.cpp
  - test/library_checker/math/counting_primes.test.cpp
  - test/library_checker/math/totient_sum.test.cpp
  - test/library_checker/math/stirling_number_of_the_first_kind.test.cpp
  - test/library_checker/math/sum_of_exp_times_poly.test.cpp
  - test/library_checker/math/gcd_convolution.test.cpp
  - test/library_checker/math/tetration.test.cpp
  - test/aoj/NTL_1_D_eulerphi.test.cpp
documentation_of: nt/primetable.hpp
layout: document
redirect_from:
- /library/nt/primetable.hpp
- /library/nt/primetable.hpp.html
title: nt/primetable.hpp
---
