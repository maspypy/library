---
data:
  _extendedDependsOn:
  - icon: ':question:'
    path: nt/prime_table.hpp
    title: nt/prime_table.hpp
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/2_library_checker/number_theory/totient_sum.test.cpp
    title: test/2_library_checker/number_theory/totient_sum.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/3_yukicoder/1276.test.cpp
    title: test/3_yukicoder/1276.test.cpp
  - icon: ':x:'
    path: test/3_yukicoder/1781.test.cpp
    title: test/3_yukicoder/1781.test.cpp
  _isVerificationFailed: true
  _pathExtension: hpp
  _verificationStatusIcon: ':question:'
  attributes:
    links:
    - https://github.com/maspypy/library/blob/main/nt/multiplicative_sum.hpp
  bundledCode: "#line 1 \"nt/multiplicative_sum.hpp\"\n// Source: https://github.com/maspypy/library/blob/main/nt/multiplicative_sum.hpp\n\
    #line 1 \"nt/prime_table.hpp\"\n// Source: https://github.com/maspypy/library/blob/main/nt/prime_table.hpp\n\
    \ntemplate <typename T = int>\nvc<T> prime_table(int LIM) {\n  ++LIM;\n  const\
    \ int S = 32768;\n  static int done = 2;\n  static vc<T> primes = {2}, sieve(S\
    \ + 1);\n\n  if (done < LIM) {\n    done = LIM;\n\n    primes = {2}, sieve.assign(S\
    \ + 1, 0);\n    const int R = LIM / 2;\n    primes.reserve(int(LIM / log(LIM)\
    \ * 1.1));\n    vc<pair<int, int>> cp;\n    for (int i = 3; i <= S; i += 2) {\n\
    \      if (!sieve[i]) {\n        cp.eb(i, i * i / 2);\n        for (int j = i\
    \ * i; j <= S; j += 2 * i) sieve[j] = 1;\n      }\n    }\n    for (int L = 1;\
    \ L <= R; L += S) {\n      array<bool, S> block{};\n      for (auto& [p, idx]\
    \ : cp)\n        for (int i = idx; i < S + L; idx = (i += p)) block[i - L] = 1;\n\
    \      FOR(i, min(S, R - L)) if (!block[i]) primes.eb((L + i) * 2 + 1);\n    }\n\
    \  }\n  int k = LB(primes, LIM);\n  return {primes.begin(), primes.begin() + k};\n\
    }\n#line 3 \"nt/multiplicative_sum.hpp\"\n\n// f_pe\uFF1AT(int p,int e), f(p^e)\n\
    // f_psum\uFF1A[1, x] \u3067\u306E f(p) \u306E\u548C\ntemplate <typename T, typename\
    \ F1, typename F2>\nT multiplicative_sum(ll N, F1 f_pe, F2 f_psum) {\n  ll sqN\
    \ = sqrtl(N);\n  auto P = prime_table<int>(sqN);\n\n  T ANS = T(1) + f_psum(N);\
    \  // 1 and prime\n  // t = up_i^k \u306E\u3068\u304D\u306B\u3001(t, i, k, f(t),\
    \ f(u)) \u3092\u6301\u305F\u305B\u308B\n\n  auto dfs = [&](auto self, ll t, ll\
    \ i, ll k, T ft, T fu) -> void {\n    T f_nxt = fu * f_pe(P[i], k + 1);\n    //\
    \ \u5B50\u30CE\u30FC\u30C9\u3092\u5168\u90E8\u52A0\u7B97\n    ANS += f_nxt;\n\
    \    ANS += ft * (f_psum(double(N) / t) - f_psum(P[i]));\n\n    ll lim = sqrtl(double(N)\
    \ / t);\n    if (P[i] <= lim) {\n      self(self, t * P[i], i, k + 1, f_nxt, fu);\n\
    \    }\n    FOR3(j, i + 1, len(P)) {\n      if (P[j] > lim) break;\n      self(self,\
    \ t * P[j], j, 1, ft * f_pe(P[j], 1), ft);\n    }\n  };\n  FOR(i, len(P)) if (P[i]\
    \ <= sqN) dfs(dfs, P[i], i, 1, f_pe(P[i], 1), 1);\n  return ANS;\n}\n"
  code: "// Source: https://github.com/maspypy/library/blob/main/nt/multiplicative_sum.hpp\n\
    #include \"nt/prime_table.hpp\"\n\n// f_pe\uFF1AT(int p,int e), f(p^e)\n// f_psum\uFF1A\
    [1, x] \u3067\u306E f(p) \u306E\u548C\ntemplate <typename T, typename F1, typename\
    \ F2>\nT multiplicative_sum(ll N, F1 f_pe, F2 f_psum) {\n  ll sqN = sqrtl(N);\n\
    \  auto P = prime_table<int>(sqN);\n\n  T ANS = T(1) + f_psum(N);  // 1 and prime\n\
    \  // t = up_i^k \u306E\u3068\u304D\u306B\u3001(t, i, k, f(t), f(u)) \u3092\u6301\
    \u305F\u305B\u308B\n\n  auto dfs = [&](auto self, ll t, ll i, ll k, T ft, T fu)\
    \ -> void {\n    T f_nxt = fu * f_pe(P[i], k + 1);\n    // \u5B50\u30CE\u30FC\u30C9\
    \u3092\u5168\u90E8\u52A0\u7B97\n    ANS += f_nxt;\n    ANS += ft * (f_psum(double(N)\
    \ / t) - f_psum(P[i]));\n\n    ll lim = sqrtl(double(N) / t);\n    if (P[i] <=\
    \ lim) {\n      self(self, t * P[i], i, k + 1, f_nxt, fu);\n    }\n    FOR3(j,\
    \ i + 1, len(P)) {\n      if (P[j] > lim) break;\n      self(self, t * P[j], j,\
    \ 1, ft * f_pe(P[j], 1), ft);\n    }\n  };\n  FOR(i, len(P)) if (P[i] <= sqN)\
    \ dfs(dfs, P[i], i, 1, f_pe(P[i], 1), 1);\n  return ANS;\n}"
  dependsOn:
  - nt/prime_table.hpp
  isVerificationFile: false
  path: nt/multiplicative_sum.hpp
  requiredBy: []
  timestamp: '2026-10-15 19:54:56+09:00'
  verificationStatus: LIBRARY_SOME_WA
  verifiedWith:
  - test/3_yukicoder/1781.test.cpp
  - test/3_yukicoder/1276.test.cpp
  - test/2_library_checker/number_theory/totient_sum.test.cpp
documentation_of: nt/multiplicative_sum.hpp
layout: document
redirect_from:
- /library/nt/multiplicative_sum.hpp
- /library/nt/multiplicative_sum.hpp.html
title: nt/multiplicative_sum.hpp
---
