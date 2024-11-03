---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: nt/primetable.hpp
    title: nt/primetable.hpp
  _extendedRequiredBy:
  - icon: ':heavy_check_mark:'
    path: nt/count_by_factor_type.hpp
    title: nt/count_by_factor_type.hpp
  - icon: ':heavy_check_mark:'
    path: nt/primesum_mod4.hpp
    title: nt/primesum_mod4.hpp
  - icon: ':heavy_check_mark:'
    path: nt/primesum_mod6.hpp
    title: nt/primesum_mod6.hpp
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/1_mytest/count_by_factor_type.test.cpp
    title: test/1_mytest/count_by_factor_type.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/1_mytest/prime_sum.test.cpp
    title: test/1_mytest/prime_sum.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/1_mytest/primesum_mod4.test.cpp
    title: test/1_mytest/primesum_mod4.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/1_mytest/primesum_mod6.test.cpp
    title: test/1_mytest/primesum_mod6.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/2_library_checker/number_theory/counting_primes.test.cpp
    title: test/2_library_checker/number_theory/counting_primes.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/2_library_checker/number_theory/totient_sum.test.cpp
    title: test/2_library_checker/number_theory/totient_sum.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/3_yukicoder/1276.test.cpp
    title: test/3_yukicoder/1276.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/3_yukicoder/1781.test.cpp
    title: test/3_yukicoder/1781.test.cpp
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
    \ primes.begin() + k};\n}\n#line 3 \"nt/primesum.hpp\"\n\r\n/*\r\nN \u3068\u5B8C\
    \u5168\u4E57\u6CD5\u7684\u95A2\u6570 f \u306E prefix sum \u95A2\u6570 F \u3092\
    \u4E0E\u3048\u308B\u3002\r\nn = floor(N/d) \u3068\u306A\u308B n \u306B\u5BFE\u3059\
    \u308B sum_{p <= n} f(p) \u3092\u8A08\u7B97\u3059\u308B\u3002\r\n\u7279\u306B\u3001\
    \u7D20\u6570\u306E k \u4E57\u548C\u3084\u3001mod m \u3054\u3068\u3067\u306E\u7D20\
    \u6570\u306E k \u4E57\u548C\u304C\u8A08\u7B97\u3067\u304D\u308B\u3002\r\nComplexity:\
    \ O(N^{3/4}/logN) time, O(N^{1/2}) space.\r\n*/\r\ntemplate <typename T>\r\nstruct\
    \ PrimeSum {\r\n  ll N;\r\n  ll sqN;\r\n  vc<T> sum_lo, sum_hi;\r\n  bool calculated;\r\
    \n\r\n  PrimeSum(ll N) : N(N), sqN(sqrtl(N)), calculated(0) {}\r\n\r\n  // [1,\
    \ x] \u305F\u3060\u3057\u3001x = floor(N, i) \u306E\u5F62\r\n  T operator[](ll\
    \ x) {\r\n    assert(calculated);\r\n    return (x <= sqN ? sum_lo[x] : sum_hi[double(N)\
    \ / x]);\r\n  }\r\n\r\n  template <typename F>\r\n  void calc(const F f) {\r\n\
    \    auto primes = primetable<int>(sqN);\r\n    sum_lo.resize(sqN + 1);\r\n  \
    \  sum_hi.resize(sqN + 1);\r\n    FOR3(i, 1, sqN + 1) sum_lo[i] = f(i) - 1;\r\n\
    \    FOR3(i, 1, sqN + 1) sum_hi[i] = f(double(N) / i) - 1;\r\n    for (int p:\
    \ primes) {\r\n      ll pp = ll(p) * p;\r\n      if (pp > N) break;\r\n      int\
    \ R = min(sqN, N / pp);\r\n      int M = sqN / p;\r\n      T x = sum_lo[p - 1];\r\
    \n      T fp = sum_lo[p] - sum_lo[p - 1];\r\n      for (int i = 1; i <= M; ++i)\
    \ sum_hi[i] -= fp * (sum_hi[i * p] - x);\r\n      for (int i = M + 1; i <= R;\
    \ ++i) sum_hi[i] -= fp * (sum_lo[N / (double(i) * p)] - x);\r\n      for (int\
    \ n = sqN; n >= pp; --n) sum_lo[n] -= fp * (sum_lo[n / p] - x);\r\n    }\r\n \
    \   calculated = 1;\r\n  }\r\n\r\n  void calc_count() {\r\n    calc([](ll x) ->\
    \ T { return x; });\r\n  }\r\n\r\n  void calc_sum() {\r\n    calc([](ll x) ->\
    \ T {\r\n      ll a = x, b = x + 1;\r\n      if (!(x & 1)) a /= 2;\r\n      if\
    \ (x & 1) b /= 2;\r\n      return T(a) * T(b);\r\n    });\r\n  }\r\n};\n"
  code: "#pragma once\r\n#include \"nt/primetable.hpp\"\r\n\r\n/*\r\nN \u3068\u5B8C\
    \u5168\u4E57\u6CD5\u7684\u95A2\u6570 f \u306E prefix sum \u95A2\u6570 F \u3092\
    \u4E0E\u3048\u308B\u3002\r\nn = floor(N/d) \u3068\u306A\u308B n \u306B\u5BFE\u3059\
    \u308B sum_{p <= n} f(p) \u3092\u8A08\u7B97\u3059\u308B\u3002\r\n\u7279\u306B\u3001\
    \u7D20\u6570\u306E k \u4E57\u548C\u3084\u3001mod m \u3054\u3068\u3067\u306E\u7D20\
    \u6570\u306E k \u4E57\u548C\u304C\u8A08\u7B97\u3067\u304D\u308B\u3002\r\nComplexity:\
    \ O(N^{3/4}/logN) time, O(N^{1/2}) space.\r\n*/\r\ntemplate <typename T>\r\nstruct\
    \ PrimeSum {\r\n  ll N;\r\n  ll sqN;\r\n  vc<T> sum_lo, sum_hi;\r\n  bool calculated;\r\
    \n\r\n  PrimeSum(ll N) : N(N), sqN(sqrtl(N)), calculated(0) {}\r\n\r\n  // [1,\
    \ x] \u305F\u3060\u3057\u3001x = floor(N, i) \u306E\u5F62\r\n  T operator[](ll\
    \ x) {\r\n    assert(calculated);\r\n    return (x <= sqN ? sum_lo[x] : sum_hi[double(N)\
    \ / x]);\r\n  }\r\n\r\n  template <typename F>\r\n  void calc(const F f) {\r\n\
    \    auto primes = primetable<int>(sqN);\r\n    sum_lo.resize(sqN + 1);\r\n  \
    \  sum_hi.resize(sqN + 1);\r\n    FOR3(i, 1, sqN + 1) sum_lo[i] = f(i) - 1;\r\n\
    \    FOR3(i, 1, sqN + 1) sum_hi[i] = f(double(N) / i) - 1;\r\n    for (int p:\
    \ primes) {\r\n      ll pp = ll(p) * p;\r\n      if (pp > N) break;\r\n      int\
    \ R = min(sqN, N / pp);\r\n      int M = sqN / p;\r\n      T x = sum_lo[p - 1];\r\
    \n      T fp = sum_lo[p] - sum_lo[p - 1];\r\n      for (int i = 1; i <= M; ++i)\
    \ sum_hi[i] -= fp * (sum_hi[i * p] - x);\r\n      for (int i = M + 1; i <= R;\
    \ ++i) sum_hi[i] -= fp * (sum_lo[N / (double(i) * p)] - x);\r\n      for (int\
    \ n = sqN; n >= pp; --n) sum_lo[n] -= fp * (sum_lo[n / p] - x);\r\n    }\r\n \
    \   calculated = 1;\r\n  }\r\n\r\n  void calc_count() {\r\n    calc([](ll x) ->\
    \ T { return x; });\r\n  }\r\n\r\n  void calc_sum() {\r\n    calc([](ll x) ->\
    \ T {\r\n      ll a = x, b = x + 1;\r\n      if (!(x & 1)) a /= 2;\r\n      if\
    \ (x & 1) b /= 2;\r\n      return T(a) * T(b);\r\n    });\r\n  }\r\n};"
  dependsOn:
  - nt/primetable.hpp
  isVerificationFile: false
  path: nt/primesum.hpp
  requiredBy:
  - nt/primesum_mod4.hpp
  - nt/primesum_mod6.hpp
  - nt/count_by_factor_type.hpp
  timestamp: '2024-09-30 22:44:02+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/3_yukicoder/1276.test.cpp
  - test/3_yukicoder/1781.test.cpp
  - test/1_mytest/primesum_mod6.test.cpp
  - test/1_mytest/prime_sum.test.cpp
  - test/1_mytest/primesum_mod4.test.cpp
  - test/1_mytest/count_by_factor_type.test.cpp
  - test/2_library_checker/number_theory/counting_primes.test.cpp
  - test/2_library_checker/number_theory/totient_sum.test.cpp
documentation_of: nt/primesum.hpp
layout: document
redirect_from:
- /library/nt/primesum.hpp
- /library/nt/primesum.hpp.html
title: nt/primesum.hpp
---
