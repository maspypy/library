---
data:
  _extendedDependsOn:
  - icon: ':question:'
    path: nt/primetable.hpp
    title: nt/primetable.hpp
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':x:'
    path: test/library_checker/math/counting_primes.test.cpp
    title: test/library_checker/math/counting_primes.test.cpp
  - icon: ':x:'
    path: test/library_checker/math/totient_sum.test.cpp
    title: test/library_checker/math/totient_sum.test.cpp
  _isVerificationFailed: true
  _pathExtension: hpp
  _verificationStatusIcon: ':x:'
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
    \ LIM + 1);\n  return {primes.begin(), primes.begin() + k};\n}\n#line 2 \"nt/primesum.hpp\"\
    \n\r\n/*\r\nN \u3068\u5B8C\u5168\u4E57\u6CD5\u7684\u95A2\u6570 f \u306E prefix\
    \ sum \u95A2\u6570 F \u3092\u4E0E\u3048\u308B\u3002\r\nn = floor(N/d) \u3068\u306A\
    \u308B n \u306B\u5BFE\u3059\u308B sum_{p <= n} f(p) \u3092\u8A08\u7B97\u3059\u308B\
    \u3002\r\n\u7279\u306B\u3001p^k \u306E\u548C\u3084\u3001mod m \u3054\u3068\u3067\
    \u306E p^k \u306E\u548C\u304C\u8A08\u7B97\u3067\u304D\u308B\u3002\r\nComplexity:\
    \ O(N^{3/4}/logN) time, O(N^{1/2}) space.\r\n*/\r\ntemplate <typename T>\r\npair<vc<T>,\
    \ vc<T>> primesum_F(ll N, function<T(ll)> F) {\r\n  ll sqN = sqrtl(N);\r\n  auto\
    \ primes = primetable(sqN);\r\n  vc<T> sum_lo(sqN + 1), sum_hi(sqN + 1);\r\n \
    \ FOR3(i, 1, sqN + 1) sum_lo[i] = F(i) - 1;\r\n  FOR3(i, 1, sqN + 1) sum_hi[i]\
    \ = F(double(N) / i) - 1;\r\n  for (auto&& p: primes) {\r\n    ll pp = p * p;\r\
    \n    if (pp > N) break;\r\n    ll R = min(sqN, N / pp);\r\n    ll M = sqN / p;\r\
    \n    T x = sum_lo[p - 1];\r\n    T fp = sum_lo[p] - sum_lo[p - 1];\r\n    FOR3(i,\
    \ 1, M + 1) sum_hi[i] -= fp * (sum_hi[i * p] - x);\r\n    FOR3(i, M + 1, R + 1)\
    \ sum_hi[i] -= fp * (sum_lo[double(N) / (i * p)] - x);\r\n    FOR3_R(n, pp, sqN\
    \ + 1) sum_lo[n] -= fp * (sum_lo[double(n) / p] - x);\r\n  }\r\n  return {sum_lo,\
    \ sum_hi};\r\n}\r\n\r\ntemplate <typename T>\r\npair<vc<T>, vc<T>> primecnt(ll\
    \ N) {\r\n  auto F = [&](ll N) -> T { return N; };\r\n  return primesum_F<T>(N,\
    \ F);\r\n}\r\n\r\ntemplate <typename T>\r\npair<vc<T>, vc<T>> primesum(ll N) {\r\
    \n  auto F = [&](ll N) -> T {\r\n    return (N & 1 ? T((N + 1) / 2) * T(N) : T(N\
    \ / 2) * T(N + 1));\r\n  };\r\n  return primesum_F<T>(N, F);\r\n}\r\n"
  code: "#include \"nt/primetable.hpp\"\r\n\r\n/*\r\nN \u3068\u5B8C\u5168\u4E57\u6CD5\
    \u7684\u95A2\u6570 f \u306E prefix sum \u95A2\u6570 F \u3092\u4E0E\u3048\u308B\
    \u3002\r\nn = floor(N/d) \u3068\u306A\u308B n \u306B\u5BFE\u3059\u308B sum_{p\
    \ <= n} f(p) \u3092\u8A08\u7B97\u3059\u308B\u3002\r\n\u7279\u306B\u3001p^k \u306E\
    \u548C\u3084\u3001mod m \u3054\u3068\u3067\u306E p^k \u306E\u548C\u304C\u8A08\u7B97\
    \u3067\u304D\u308B\u3002\r\nComplexity: O(N^{3/4}/logN) time, O(N^{1/2}) space.\r\
    \n*/\r\ntemplate <typename T>\r\npair<vc<T>, vc<T>> primesum_F(ll N, function<T(ll)>\
    \ F) {\r\n  ll sqN = sqrtl(N);\r\n  auto primes = primetable(sqN);\r\n  vc<T>\
    \ sum_lo(sqN + 1), sum_hi(sqN + 1);\r\n  FOR3(i, 1, sqN + 1) sum_lo[i] = F(i)\
    \ - 1;\r\n  FOR3(i, 1, sqN + 1) sum_hi[i] = F(double(N) / i) - 1;\r\n  for (auto&&\
    \ p: primes) {\r\n    ll pp = p * p;\r\n    if (pp > N) break;\r\n    ll R = min(sqN,\
    \ N / pp);\r\n    ll M = sqN / p;\r\n    T x = sum_lo[p - 1];\r\n    T fp = sum_lo[p]\
    \ - sum_lo[p - 1];\r\n    FOR3(i, 1, M + 1) sum_hi[i] -= fp * (sum_hi[i * p] -\
    \ x);\r\n    FOR3(i, M + 1, R + 1) sum_hi[i] -= fp * (sum_lo[double(N) / (i *\
    \ p)] - x);\r\n    FOR3_R(n, pp, sqN + 1) sum_lo[n] -= fp * (sum_lo[double(n)\
    \ / p] - x);\r\n  }\r\n  return {sum_lo, sum_hi};\r\n}\r\n\r\ntemplate <typename\
    \ T>\r\npair<vc<T>, vc<T>> primecnt(ll N) {\r\n  auto F = [&](ll N) -> T { return\
    \ N; };\r\n  return primesum_F<T>(N, F);\r\n}\r\n\r\ntemplate <typename T>\r\n\
    pair<vc<T>, vc<T>> primesum(ll N) {\r\n  auto F = [&](ll N) -> T {\r\n    return\
    \ (N & 1 ? T((N + 1) / 2) * T(N) : T(N / 2) * T(N + 1));\r\n  };\r\n  return primesum_F<T>(N,\
    \ F);\r\n}\r\n"
  dependsOn:
  - nt/primetable.hpp
  isVerificationFile: false
  path: nt/primesum.hpp
  requiredBy: []
  timestamp: '2022-05-11 21:45:09+09:00'
  verificationStatus: LIBRARY_ALL_WA
  verifiedWith:
  - test/library_checker/math/totient_sum.test.cpp
  - test/library_checker/math/counting_primes.test.cpp
documentation_of: nt/primesum.hpp
layout: document
redirect_from:
- /library/nt/primesum.hpp
- /library/nt/primesum.hpp.html
title: nt/primesum.hpp
---
