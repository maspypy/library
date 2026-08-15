---
data:
  _extendedDependsOn:
  - icon: ':question:'
    path: nt/prime_sum.hpp
    title: nt/prime_sum.hpp
  - icon: ':question:'
    path: nt/prime_table.hpp
    title: nt/prime_table.hpp
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/1_mytest/primesum_mod4.test.cpp
    title: test/1_mytest/primesum_mod4.test.cpp
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
    \ primes.eb((L + i) * 2 + 1);\n    }\n  }\n  int k = LB(primes, LIM + 1);\n  return\
    \ {primes.begin(), primes.begin() + k};\n}\n#line 2 \"nt/prime_sum.hpp\"\n\n/*\n\
    N \u3068\u5B8C\u5168\u4E57\u6CD5\u7684\u95A2\u6570 f \u306E prefix sum \u95A2\u6570\
    \ F \u3092\u4E0E\u3048\u308B\u3002\nn = floor(N/d) \u3068\u306A\u308B n \u306B\
    \u5BFE\u3059\u308B sum_{p <= n} f(p) \u3092\u8A08\u7B97\u3059\u308B\u3002\n\u7279\
    \u306B\u3001\u7D20\u6570\u306E k \u4E57\u548C\u3084\u3001mod m \u3054\u3068\u3067\
    \u306E\u7D20\u6570\u306E k \u4E57\u548C\u304C\u8A08\u7B97\u3067\u304D\u308B\u3002\
    \nComplexity: O(N^{3/4}/logN) time, O(N^{1/2}) space.\n*/\ntemplate <typename\
    \ T>\nstruct Prime_Sum {\n  ll N;\n  ll sqN;\n  vc<T> sum_lo, sum_hi;\n  bool\
    \ calculated;\n\n  Prime_Sum(ll N) : N(N), sqN(sqrtl(N)), calculated(0) {}\n\n\
    \  // [1, x] \u305F\u3060\u3057\u3001x = floor(N, i) \u306E\u5F62\n  T operator[](ll\
    \ x) {\n    assert(calculated);\n    return (x <= sqN ? sum_lo[x] : sum_hi[double(N)\
    \ / x]);\n  }\n\n  template <typename F>\n  void calc(const F f) {\n    auto primes\
    \ = prime_table<int>(sqN);\n    sum_lo.resize(sqN + 1);\n    sum_hi.resize(sqN\
    \ + 1);\n    FOR(i, 1, sqN + 1) sum_lo[i] = f(i) - 1;\n    FOR(i, 1, sqN + 1)\
    \ sum_hi[i] = f(double(N) / i) - 1;\n    for (int p : primes) {\n      ll pp =\
    \ ll(p) * p;\n      if (pp > N) break;\n      int R = min(sqN, N / pp);\n    \
    \  int M = sqN / p;\n      T x = sum_lo[p - 1];\n      T fp = sum_lo[p] - sum_lo[p\
    \ - 1];\n      for (int i = 1; i <= M; ++i) sum_hi[i] -= fp * (sum_hi[i * p] -\
    \ x);\n      for (int i = M + 1; i <= R; ++i)\n        sum_hi[i] -= fp * (sum_lo[N\
    \ / (double(i) * p)] - x);\n      for (int n = sqN; n >= pp; --n) sum_lo[n] -=\
    \ fp * (sum_lo[n / p] - x);\n    }\n    calculated = 1;\n  }\n\n  void calc_count()\
    \ {\n    calc([](ll x) -> T { return x; });\n  }\n\n  void calc_sum() {\n    calc([](ll\
    \ x) -> T {\n      ll a = x, b = x + 1;\n      if (!(x & 1)) a /= 2;\n      if\
    \ (x & 1) b /= 2;\n      return T(a) * T(b);\n    });\n  }\n};\n#line 1 \"nt/prime_table.hpp\"\
    \n\ntemplate <typename T = int>\nvc<T> prime_table(int LIM) {\n  ++LIM;\n  const\
    \ int S = 32768;\n  static int done = 2;\n  static vc<T> primes = {2}, sieve(S\
    \ + 1);\n\n  if (done < LIM) {\n    done = LIM;\n\n    primes = {2}, sieve.assign(S\
    \ + 1, 0);\n    const int R = LIM / 2;\n    primes.reserve(int(LIM / log(LIM)\
    \ * 1.1));\n    vc<pair<int, int>> cp;\n    for (int i = 3; i <= S; i += 2) {\n\
    \      if (!sieve[i]) {\n        cp.eb(i, i * i / 2);\n        for (int j = i\
    \ * i; j <= S; j += 2 * i) sieve[j] = 1;\n      }\n    }\n    for (int L = 1;\
    \ L <= R; L += S) {\n      array<bool, S> block{};\n      for (auto& [p, idx]\
    \ : cp)\n        for (int i = idx; i < S + L; idx = (i += p)) block[i - L] = 1;\n\
    \      FOR(i, min(S, R - L)) if (!block[i]) primes.eb((L + i) * 2 + 1);\n    }\n\
    \  }\n  int k = LB(primes, LIM + 1);\n  return {primes.begin(), primes.begin()\
    \ + k};\n}\n#line 3 \"nt/prime_sum_mod4.hpp\"\n\ntemplate <typename T>\nstruct\
    \ Prime_Sum_Mod_4 {\n  ll N;\n  ll sqN;\n\n  Prime_Sum<T> A, B;\n  Prime_Sum_Mod_4(ll\
    \ N) : N(N), sqN(sqrtl(N)), A(N), B(N) {}\n\n  pair<T, T> operator[](ll x) {\n\
    \    T a = A[x], b = B[x];\n    return {(a + b) / T(2), (a - b) / T(2)};\n  }\n\
    \n  void calc_count() {\n    A.calc([](ll x) -> T { return (x + 1) / 2; });\n\
    \    B.calc([](ll x) -> T { return ((x + 3) % 4 <= 1 ? 1 : 0); });\n  }\n\n  void\
    \ calc_sum() {\n    A.calc([](ll x) -> T {\n      ll n = (x + 1) / 2;\n      return\
    \ T(n) * T(n);\n    });\n    B.calc([](ll x) -> T {\n      ll n = (x + 1) / 2;\n\
    \      return (n % 2 == 0 ? T(-n) : T(n));\n    });\n  }\n};\n"
  code: "#include \"nt/prime_sum.hpp\"\n#include \"nt/prime_table.hpp\"\n\ntemplate\
    \ <typename T>\nstruct Prime_Sum_Mod_4 {\n  ll N;\n  ll sqN;\n\n  Prime_Sum<T>\
    \ A, B;\n  Prime_Sum_Mod_4(ll N) : N(N), sqN(sqrtl(N)), A(N), B(N) {}\n\n  pair<T,\
    \ T> operator[](ll x) {\n    T a = A[x], b = B[x];\n    return {(a + b) / T(2),\
    \ (a - b) / T(2)};\n  }\n\n  void calc_count() {\n    A.calc([](ll x) -> T { return\
    \ (x + 1) / 2; });\n    B.calc([](ll x) -> T { return ((x + 3) % 4 <= 1 ? 1 :\
    \ 0); });\n  }\n\n  void calc_sum() {\n    A.calc([](ll x) -> T {\n      ll n\
    \ = (x + 1) / 2;\n      return T(n) * T(n);\n    });\n    B.calc([](ll x) -> T\
    \ {\n      ll n = (x + 1) / 2;\n      return (n % 2 == 0 ? T(-n) : T(n));\n  \
    \  });\n  }\n};\n"
  dependsOn:
  - nt/prime_sum.hpp
  - nt/prime_table.hpp
  isVerificationFile: false
  path: nt/prime_sum_mod4.hpp
  requiredBy: []
  timestamp: '2026-08-16 04:03:00+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/1_mytest/primesum_mod4.test.cpp
documentation_of: nt/prime_sum_mod4.hpp
layout: document
redirect_from:
- /library/nt/prime_sum_mod4.hpp
- /library/nt/prime_sum_mod4.hpp.html
title: nt/prime_sum_mod4.hpp
---
