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
  - icon: ':x:'
    path: test/yukicoder/1276.test.cpp
    title: test/yukicoder/1276.test.cpp
  - icon: ':x:'
    path: test/yukicoder/1781.test.cpp
    title: test/yukicoder/1781.test.cpp
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
    \ LIM + 1);\n  return {primes.begin(), primes.begin() + k};\n}\n#line 2 \"nt/multiplicative_sum.hpp\"\
    \n\r\n// f_pe\uFF1AT(int p,int e), f(p^e)\r\n// f_psum\uFF1A[1, x] \u3067\u306E\
    \ f(p) \u306E\u548C\r\ntemplate <typename T, typename F1, typename F2>\r\nT multiplicative_sum(ll\
    \ N, F1 f_pe, F2 f_psum) {\r\n  ll sqN = sqrtl(N);\r\n  auto P = primetable(sqN);\r\
    \n\r\n  T ANS = T(1) + f_psum(N); // 1 and prime\r\n  // t = up_i^k \u306E\u3068\
    \u304D\u306B\u3001(t, i, k, f(t), f(u)) \u3092\u6301\u305F\u305B\u308B\r\n\r\n\
    \  auto dfs = [&](auto self, ll t, ll i, ll k, T ft, T fu) -> void {\r\n    T\
    \ f_nxt = fu * f_pe(P[i], k + 1);\r\n    // \u5B50\u30CE\u30FC\u30C9\u3092\u5168\
    \u90E8\u52A0\u7B97\r\n    ANS += f_nxt;\r\n    ANS += ft * (f_psum(double(N) /\
    \ t) - f_psum(P[i]));\r\n\r\n    ll lim = sqrtl(double(N) / t);\r\n    if (P[i]\
    \ <= lim) { self(self, t * P[i], i, k + 1, f_nxt, fu); }\r\n    FOR3(j, i + 1,\
    \ len(P)) {\r\n      if (P[j] > lim) break;\r\n      self(self, t * P[j], j, 1,\
    \ ft * f_pe(P[j], 1), ft);\r\n    }\r\n  };\r\n  FOR(i, len(P)) if (P[i] <= sqN)\
    \ dfs(dfs, P[i], i, 1, f_pe(P[i], 1), 1);\r\n  return ANS;\r\n}\n"
  code: "#include \"nt/primetable.hpp\"\r\n\r\n// f_pe\uFF1AT(int p,int e), f(p^e)\r\
    \n// f_psum\uFF1A[1, x] \u3067\u306E f(p) \u306E\u548C\r\ntemplate <typename T,\
    \ typename F1, typename F2>\r\nT multiplicative_sum(ll N, F1 f_pe, F2 f_psum)\
    \ {\r\n  ll sqN = sqrtl(N);\r\n  auto P = primetable(sqN);\r\n\r\n  T ANS = T(1)\
    \ + f_psum(N); // 1 and prime\r\n  // t = up_i^k \u306E\u3068\u304D\u306B\u3001\
    (t, i, k, f(t), f(u)) \u3092\u6301\u305F\u305B\u308B\r\n\r\n  auto dfs = [&](auto\
    \ self, ll t, ll i, ll k, T ft, T fu) -> void {\r\n    T f_nxt = fu * f_pe(P[i],\
    \ k + 1);\r\n    // \u5B50\u30CE\u30FC\u30C9\u3092\u5168\u90E8\u52A0\u7B97\r\n\
    \    ANS += f_nxt;\r\n    ANS += ft * (f_psum(double(N) / t) - f_psum(P[i]));\r\
    \n\r\n    ll lim = sqrtl(double(N) / t);\r\n    if (P[i] <= lim) { self(self,\
    \ t * P[i], i, k + 1, f_nxt, fu); }\r\n    FOR3(j, i + 1, len(P)) {\r\n      if\
    \ (P[j] > lim) break;\r\n      self(self, t * P[j], j, 1, ft * f_pe(P[j], 1),\
    \ ft);\r\n    }\r\n  };\r\n  FOR(i, len(P)) if (P[i] <= sqN) dfs(dfs, P[i], i,\
    \ 1, f_pe(P[i], 1), 1);\r\n  return ANS;\r\n}"
  dependsOn:
  - nt/primetable.hpp
  isVerificationFile: false
  path: nt/multiplicative_sum.hpp
  requiredBy: []
  timestamp: '2022-08-19 00:54:59+09:00'
  verificationStatus: LIBRARY_SOME_WA
  verifiedWith:
  - test/yukicoder/1276.test.cpp
  - test/yukicoder/1781.test.cpp
  - test/library_checker/math/totient_sum.test.cpp
documentation_of: nt/multiplicative_sum.hpp
layout: document
redirect_from:
- /library/nt/multiplicative_sum.hpp
- /library/nt/multiplicative_sum.hpp.html
title: nt/multiplicative_sum.hpp
---
