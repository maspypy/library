---
data:
  _extendedDependsOn:
  - icon: ':question:'
    path: nt/primesum.hpp
    title: nt/primesum.hpp
  - icon: ':question:'
    path: nt/primetable.hpp
    title: nt/primetable.hpp
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/mytest/primesum_mod6.test.cpp
    title: test/mytest/primesum_mod6.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 2 \"nt/primetable.hpp\"\n\ntemplate <typename T = long long>\n\
    vc<T> primetable(int LIM) {\n  ++LIM;\n  const int S = 32768;\n  static int done\
    \ = 2;\n  static vc<T> primes = {2}, sieve(S + 1);\n\n  if (done < LIM) {\n  \
    \  done = LIM;\n\n    primes = {2}, sieve.assign(S + 1, 0);\n    const int R =\
    \ LIM / 2;\n    primes.reserve(int(LIM / log(LIM) * 1.1));\n    vc<pair<int, int>>\
    \ cp;\n    for (int i = 3; i <= S; i += 2) {\n      if (!sieve[i]) {\n       \
    \ cp.eb(i, i * i / 2);\n        for (int j = i * i; j <= S; j += 2 * i) sieve[j]\
    \ = 1;\n      }\n    }\n    for (int L = 1; L <= R; L += S) {\n      array<bool,\
    \ S> block{};\n      for (auto& [p, idx]: cp)\n        for (int i = idx; i < S\
    \ + L; idx = (i += p)) block[i - L] = 1;\n      FOR(i, min(S, R - L)) if (!block[i])\
    \ primes.eb((L + i) * 2 + 1);\n    }\n  }\n  int k = LB(primes, LIM + 1);\n  return\
    \ {primes.begin(), primes.begin() + k};\n}\n#line 2 \"nt/primesum.hpp\"\n\r\n\
    /*\r\nN \u3068\u5B8C\u5168\u4E57\u6CD5\u7684\u95A2\u6570 f \u306E prefix sum \u95A2\
    \u6570 F \u3092\u4E0E\u3048\u308B\u3002\r\nn = floor(N/d) \u3068\u306A\u308B n\
    \ \u306B\u5BFE\u3059\u308B sum_{p <= n} f(p) \u3092\u8A08\u7B97\u3059\u308B\u3002\
    \r\n\u7279\u306B\u3001\u7D20\u6570\u306E k \u4E57\u548C\u3084\u3001mod m \u3054\
    \u3068\u3067\u306E\u7D20\u6570\u306E k \u4E57\u548C\u304C\u8A08\u7B97\u3067\u304D\
    \u308B\u3002\r\nComplexity: O(N^{3/4}/logN) time, O(N^{1/2}) space.\r\n*/\r\n\
    template <typename T>\r\nstruct PrimeSum {\r\n  ll N;\r\n  ll sqN;\r\n  vc<T>\
    \ sum_lo, sum_hi;\r\n  bool calculated;\r\n\r\n  PrimeSum(ll N) : N(N), sqN(sqrtl(N)),\
    \ calculated(0) {}\r\n\r\n  // [1, x] \u305F\u3060\u3057\u3001x = floor(N, i)\
    \ \u306E\u5F62\r\n  T operator[](ll x) {\r\n    assert(calculated);\r\n    return\
    \ (x <= sqN ? sum_lo[x] : sum_hi[double(N) / x]);\r\n  }\r\n\r\n  template <typename\
    \ F>\r\n  void calc(const F f) {\r\n    auto primes = primetable(sqN);\r\n   \
    \ sum_lo.resize(sqN + 1);\r\n    sum_hi.resize(sqN + 1);\r\n    FOR3(i, 1, sqN\
    \ + 1) sum_lo[i] = f(i) - 1;\r\n    FOR3(i, 1, sqN + 1) sum_hi[i] = f(double(N)\
    \ / i) - 1;\r\n    for (auto&& p: primes) {\r\n      ll pp = p * p;\r\n      if\
    \ (pp > N) break;\r\n      ll R = min(sqN, N / pp);\r\n      ll M = sqN / p;\r\
    \n      T x = sum_lo[p - 1];\r\n      T fp = sum_lo[p] - sum_lo[p - 1];\r\n  \
    \    FOR3(i, 1, M + 1) sum_hi[i] -= fp * (sum_hi[i * p] - x);\r\n      FOR3(i,\
    \ M + 1, R + 1) sum_hi[i] -= fp * (sum_lo[double(N) / (i * p)] - x);\r\n     \
    \ FOR3_R(n, pp, sqN + 1) sum_lo[n] -= fp * (sum_lo[double(n / p)] - x);\r\n  \
    \  }\r\n    calculated = 1;\r\n  }\r\n\r\n  void calc_count() {\r\n    calc([](ll\
    \ x) -> T { return x; });\r\n  }\r\n\r\n  void calc_sum() {\r\n    calc([](ll\
    \ x) -> T {\r\n      ll a = x, b = x + 1;\r\n      if (!(x & 1)) a /= 2;\r\n \
    \     if (x & 1) b /= 2;\r\n      return T(a) * T(b);\r\n    });\r\n  }\r\n};\r\
    \n#line 3 \"nt/primesum_mod6.hpp\"\n\ntemplate <typename T>\nstruct PrimeSum_Mod_6\
    \ {\n  ll N;\n  ll sqN;\n\n  PrimeSum<T> A, B;\n  PrimeSum_Mod_6(ll N) : N(N),\
    \ sqN(sqrtl(N)), A(N), B(N) {}\n\n  pair<T, T> operator[](ll x) {\n    T a = A[x],\
    \ b = B[x];\n    return {(a + b) / T(2), (a - b) / T(2)};\n  }\n\n  void calc_count()\
    \ {\n    A.calc([](ll x) -> T { return ((x + 2) / 3 - (x % 6 == 4)); });\n   \
    \ B.calc([](ll x) -> T { return ((x + 5) % 6 <= 3 ? 1 : 0); });\n  }\n\n  void\
    \ calc_sum() {\n    A.calc([](ll x) -> T {\n      ll n = (x + 2) / 3 - (x % 6\
    \ == 4);\n      ll k = n / 2;\n      if (n % 2 == 0) { return T(6 * k) * T(k);\
    \ }\n      return T(6 * k) * T(k) + T(6 * k + 1);\n    });\n    B.calc([](ll x)\
    \ -> T {\n      ll n = (x + 2) / 3 - (x % 6 == 4);\n      ll k = n / 2;\n    \
    \  if (n % 2 == 0) { return T(-4 * k); }\n      return T(-4 * k + 6 * k + 1);\n\
    \    });\n  }\n};\n"
  code: "#include \"nt/primesum.hpp\"\n#include \"nt/primetable.hpp\"\n\ntemplate\
    \ <typename T>\nstruct PrimeSum_Mod_6 {\n  ll N;\n  ll sqN;\n\n  PrimeSum<T> A,\
    \ B;\n  PrimeSum_Mod_6(ll N) : N(N), sqN(sqrtl(N)), A(N), B(N) {}\n\n  pair<T,\
    \ T> operator[](ll x) {\n    T a = A[x], b = B[x];\n    return {(a + b) / T(2),\
    \ (a - b) / T(2)};\n  }\n\n  void calc_count() {\n    A.calc([](ll x) -> T { return\
    \ ((x + 2) / 3 - (x % 6 == 4)); });\n    B.calc([](ll x) -> T { return ((x + 5)\
    \ % 6 <= 3 ? 1 : 0); });\n  }\n\n  void calc_sum() {\n    A.calc([](ll x) -> T\
    \ {\n      ll n = (x + 2) / 3 - (x % 6 == 4);\n      ll k = n / 2;\n      if (n\
    \ % 2 == 0) { return T(6 * k) * T(k); }\n      return T(6 * k) * T(k) + T(6 *\
    \ k + 1);\n    });\n    B.calc([](ll x) -> T {\n      ll n = (x + 2) / 3 - (x\
    \ % 6 == 4);\n      ll k = n / 2;\n      if (n % 2 == 0) { return T(-4 * k); }\n\
    \      return T(-4 * k + 6 * k + 1);\n    });\n  }\n};\n"
  dependsOn:
  - nt/primesum.hpp
  - nt/primetable.hpp
  isVerificationFile: false
  path: nt/primesum_mod6.hpp
  requiredBy: []
  timestamp: '2022-12-12 09:21:17+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/mytest/primesum_mod6.test.cpp
documentation_of: nt/primesum_mod6.hpp
layout: document
redirect_from:
- /library/nt/primesum_mod6.hpp
- /library/nt/primesum_mod6.hpp.html
title: nt/primesum_mod6.hpp
---
