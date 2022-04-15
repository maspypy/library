---
data:
  _extendedDependsOn:
  - icon: ':question:'
    path: nt/primetable.hpp
    title: nt/primetable.hpp
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/library_checker/math/totient_sum.test.cpp
    title: test/library_checker/math/totient_sum.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links:
    - http://baihacker.github.io/main/2020/The_prefix-sum_of_multiplicative_function_the_black_algorithm.html
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
    \ LIM + 1);\n  return {primes.begin(), primes.begin() + k};\n}\n#line 2 \"nt/multiplicative_sum.hpp\"\
    \ntemplate <typename T, typename FUNC>\r\nT multiplicative_sum(ll N, FUNC F, vc<T>&\
    \ sum_lo, vc<T>& sum_hi) {\r\n  // F(p^e) \u3092\u4E0E\u3048\u308B\u95A2\u6570\
    \u306B\u52A0\u3048\u3001\u4E8B\u524D\u306B\u8A08\u7B97\u3057\u305F prime sum \u3092\
    \u6301\u305F\u305B\u308B\r\n  // black algorithm in\r\n  // http://baihacker.github.io/main/2020/The_prefix-sum_of_multiplicative_function_the_black_algorithm.html\r\
    \n  ll sqN = sqrtl(N);\r\n  auto P = primetable(sqN);\r\n  auto get = [&](ll d)\
    \ -> T {\r\n    return (d <= sqN ? sum_lo[d] : sum_hi[double(N) / d]);\r\n  };\r\
    \n\r\n  T ANS = T(1) + get(N); // 1 and prime\r\n\r\n  // t = up_i^k \u306E\u3068\
    \u304D\u306B\u3001(t, i, k, f(t), f(u)) \u3092\u6301\u305F\u305B\u308B\r\n\r\n\
    \  auto dfs = [&](auto self, ll t, ll i, ll k, T ft, T fu) -> void {\r\n    T\
    \ f_nxt = fu * F(P[i], k + 1);\r\n    // \u5B50\u30CE\u30FC\u30C9\u3092\u5168\u90E8\
    \u52A0\u7B97\r\n    ANS += f_nxt;\r\n    ANS += ft * (get(double(N) / t) - get(P[i]));\r\
    \n\r\n    ll lim = sqrtl(double(N) / t);\r\n    if (P[i] <= lim) { self(self,\
    \ t * P[i], i, k + 1, f_nxt, fu); }\r\n    FOR3(j, i + 1, len(P)) {\r\n      if\
    \ (P[j] > lim) break;\r\n      self(self, t * P[j], j, 1, ft * F(P[j], 1), ft);\r\
    \n    }\r\n  };\r\n  FOR(i, len(P)) if (P[i] <= sqN) dfs(dfs, P[i], i, 1, F(P[i],\
    \ 1), 1);\r\n  return ANS;\r\n}\n"
  code: "#include \"nt/primetable.hpp\"\r\ntemplate <typename T, typename FUNC>\r\n\
    T multiplicative_sum(ll N, FUNC F, vc<T>& sum_lo, vc<T>& sum_hi) {\r\n  // F(p^e)\
    \ \u3092\u4E0E\u3048\u308B\u95A2\u6570\u306B\u52A0\u3048\u3001\u4E8B\u524D\u306B\
    \u8A08\u7B97\u3057\u305F prime sum \u3092\u6301\u305F\u305B\u308B\r\n  // black\
    \ algorithm in\r\n  // http://baihacker.github.io/main/2020/The_prefix-sum_of_multiplicative_function_the_black_algorithm.html\r\
    \n  ll sqN = sqrtl(N);\r\n  auto P = primetable(sqN);\r\n  auto get = [&](ll d)\
    \ -> T {\r\n    return (d <= sqN ? sum_lo[d] : sum_hi[double(N) / d]);\r\n  };\r\
    \n\r\n  T ANS = T(1) + get(N); // 1 and prime\r\n\r\n  // t = up_i^k \u306E\u3068\
    \u304D\u306B\u3001(t, i, k, f(t), f(u)) \u3092\u6301\u305F\u305B\u308B\r\n\r\n\
    \  auto dfs = [&](auto self, ll t, ll i, ll k, T ft, T fu) -> void {\r\n    T\
    \ f_nxt = fu * F(P[i], k + 1);\r\n    // \u5B50\u30CE\u30FC\u30C9\u3092\u5168\u90E8\
    \u52A0\u7B97\r\n    ANS += f_nxt;\r\n    ANS += ft * (get(double(N) / t) - get(P[i]));\r\
    \n\r\n    ll lim = sqrtl(double(N) / t);\r\n    if (P[i] <= lim) { self(self,\
    \ t * P[i], i, k + 1, f_nxt, fu); }\r\n    FOR3(j, i + 1, len(P)) {\r\n      if\
    \ (P[j] > lim) break;\r\n      self(self, t * P[j], j, 1, ft * F(P[j], 1), ft);\r\
    \n    }\r\n  };\r\n  FOR(i, len(P)) if (P[i] <= sqN) dfs(dfs, P[i], i, 1, F(P[i],\
    \ 1), 1);\r\n  return ANS;\r\n}"
  dependsOn:
  - nt/primetable.hpp
  isVerificationFile: false
  path: nt/multiplicative_sum.hpp
  requiredBy: []
  timestamp: '2022-04-16 04:26:49+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/library_checker/math/totient_sum.test.cpp
documentation_of: nt/multiplicative_sum.hpp
layout: document
redirect_from:
- /library/nt/multiplicative_sum.hpp
- /library/nt/multiplicative_sum.hpp.html
title: nt/multiplicative_sum.hpp
---
