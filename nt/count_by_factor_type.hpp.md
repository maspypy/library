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
    path: test/1_mytest/count_by_factor_type.test.cpp
    title: test/1_mytest/count_by_factor_type.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links:
    - https://atcoder.jp/contests/xmascon20/tasks/xmascon20_d
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
    \ primes.begin() + k};\n}\n#line 2 \"nt/primesum.hpp\"\n\r\n/*\r\nN \u3068\u5B8C\
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
    \ ++i)\r\n        sum_hi[i] -= fp * (sum_lo[N / (double(i) * p)] - x);\r\n   \
    \   for (int n = sqN; n >= pp; --n) sum_lo[n] -= fp * (sum_lo[n / p] - x);\r\n\
    \    }\r\n    calculated = 1;\r\n  }\r\n\r\n  void calc_count() {\r\n    calc([](ll\
    \ x) -> T { return x; });\r\n  }\r\n\r\n  void calc_sum() {\r\n    calc([](ll\
    \ x) -> T {\r\n      ll a = x, b = x + 1;\r\n      if (!(x & 1)) a /= 2;\r\n \
    \     if (x & 1) b /= 2;\r\n      return T(a) * T(b);\r\n    });\r\n  }\r\n};\n\
    #line 3 \"nt/count_by_factor_type.hpp\"\n\n// factor type: \u964D\u9806 270 ->\
    \ (3,1,1)\n// N=10^9: 1324 \u7A2E\u985E, 0.4sec\n// https://atcoder.jp/contests/xmascon20/tasks/xmascon20_d\n\
    map<vc<int>, ll> count_by_factor_type(ll N) {\n  ll sqN = sqrtl(N);\n  auto P\
    \ = primetable<int>(sqN);\n  PrimeSum<ll> X(N);\n  X.calc_count();\n\n  // 1 and\
    \ prime\n  map<vc<int>, ll> ANS;\n  ANS[vc<int>()] = 1;\n  if (X[N] > 0) ANS[vc<int>({1})]\
    \ = X[N];\n\n  auto add = [&](vc<int> F, int k) -> vc<int> {\n    int p = len(F);\n\
    \    F.eb(k);\n    while (0 < p && F[p - 1] < F[p]) { swap(F[p - 1], F[p]), --p;\
    \ }\n    return F;\n  };\n\n  // t = up_i^k \u306E\u3068\u304D\u306B\n  auto dfs\
    \ = [&](auto& dfs, ll t, ll i, ll k, vc<int> U) -> void {\n    // U * primes \u3092\
    \u8FFD\u52A0\u3059\u308B\n    vc<int> nxt1 = add(U, k + 1);\n    ANS[nxt1]++;\n\
    \    vc<int> Uk = add(U, k);\n    vc<int> nxt2 = add(Uk, 1);\n    ll cnt = X[N\
    \ / t] - X[P[i]];\n    if (cnt > 0) ANS[nxt2] += X[N / t] - X[P[i]];\n    ll lim\
    \ = sqrtl(double(N) / t);\n    if (P[i] <= lim) { dfs(dfs, t * P[i], i, k + 1,\
    \ U); }\n    FOR(j, i + 1, len(P)) {\n      if (P[j] > lim) break;\n      dfs(dfs,\
    \ t * P[j], j, 1, Uk);\n    }\n  };\n  FOR(i, len(P)) if (P[i] <= sqN) dfs(dfs,\
    \ P[i], i, 1, {});\n  return ANS;\n}\n"
  code: "#include \"nt/primetable.hpp\"\n#include \"nt/primesum.hpp\"\n\n// factor\
    \ type: \u964D\u9806 270 -> (3,1,1)\n// N=10^9: 1324 \u7A2E\u985E, 0.4sec\n//\
    \ https://atcoder.jp/contests/xmascon20/tasks/xmascon20_d\nmap<vc<int>, ll> count_by_factor_type(ll\
    \ N) {\n  ll sqN = sqrtl(N);\n  auto P = primetable<int>(sqN);\n  PrimeSum<ll>\
    \ X(N);\n  X.calc_count();\n\n  // 1 and prime\n  map<vc<int>, ll> ANS;\n  ANS[vc<int>()]\
    \ = 1;\n  if (X[N] > 0) ANS[vc<int>({1})] = X[N];\n\n  auto add = [&](vc<int>\
    \ F, int k) -> vc<int> {\n    int p = len(F);\n    F.eb(k);\n    while (0 < p\
    \ && F[p - 1] < F[p]) { swap(F[p - 1], F[p]), --p; }\n    return F;\n  };\n\n\
    \  // t = up_i^k \u306E\u3068\u304D\u306B\n  auto dfs = [&](auto& dfs, ll t, ll\
    \ i, ll k, vc<int> U) -> void {\n    // U * primes \u3092\u8FFD\u52A0\u3059\u308B\
    \n    vc<int> nxt1 = add(U, k + 1);\n    ANS[nxt1]++;\n    vc<int> Uk = add(U,\
    \ k);\n    vc<int> nxt2 = add(Uk, 1);\n    ll cnt = X[N / t] - X[P[i]];\n    if\
    \ (cnt > 0) ANS[nxt2] += X[N / t] - X[P[i]];\n    ll lim = sqrtl(double(N) / t);\n\
    \    if (P[i] <= lim) { dfs(dfs, t * P[i], i, k + 1, U); }\n    FOR(j, i + 1,\
    \ len(P)) {\n      if (P[j] > lim) break;\n      dfs(dfs, t * P[j], j, 1, Uk);\n\
    \    }\n  };\n  FOR(i, len(P)) if (P[i] <= sqN) dfs(dfs, P[i], i, 1, {});\n  return\
    \ ANS;\n}"
  dependsOn:
  - nt/primetable.hpp
  - nt/primesum.hpp
  isVerificationFile: false
  path: nt/count_by_factor_type.hpp
  requiredBy: []
  timestamp: '2024-09-10 18:20:16+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/1_mytest/count_by_factor_type.test.cpp
documentation_of: nt/count_by_factor_type.hpp
layout: document
redirect_from:
- /library/nt/count_by_factor_type.hpp
- /library/nt/count_by_factor_type.hpp.html
title: nt/count_by_factor_type.hpp
---
