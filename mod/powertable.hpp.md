---
data:
  _extendedDependsOn:
  - icon: ':question:'
    path: nt/primetable.hpp
    title: nt/primetable.hpp
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':x:'
    path: test/library_checker/math/sum_of_exp_times_poly_limit.test.cpp
    title: test/library_checker/math/sum_of_exp_times_poly_limit.test.cpp
  - icon: ':x:'
    path: test/mytest/qoj5443.test.cpp
    title: test/mytest/qoj5443.test.cpp
  - icon: ':x:'
    path: test/yukicoder/1760.test.cpp
    title: test/yukicoder/1760.test.cpp
  - icon: ':x:'
    path: test/yukicoder/2206.test.cpp
    title: test/yukicoder/2206.test.cpp
  - icon: ':x:'
    path: test_atcoder/abc202_f.test.cpp
    title: test_atcoder/abc202_f.test.cpp
  - icon: ':x:'
    path: test_atcoder/abc249_ex.test.cpp
    title: test_atcoder/abc249_ex.test.cpp
  _isVerificationFailed: true
  _pathExtension: hpp
  _verificationStatusIcon: ':x:'
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
    \ {primes.begin(), primes.begin() + k};\n}\n#line 3 \"mod/powertable.hpp\"\n\r\
    \n// a^0, ..., a^N\r\ntemplate <typename mint>\r\nvc<mint> powertable_1(mint a,\
    \ ll N) {\r\n  // table of a^i\r\n  vc<mint> f(N + 1, 1);\r\n  FOR(i, N) f[i +\
    \ 1] = a * f[i];\r\n  return f;\r\n}\r\n\r\n// 0^e, ..., N^e\r\ntemplate <typename\
    \ mint>\r\nvc<mint> powertable_2(ll e, ll N) {\r\n  auto primes = primetable(N);\r\
    \n  vc<mint> f(N + 1, 1);\r\n  f[0] = mint(0).pow(e);\r\n  for (auto&& p: primes)\
    \ {\r\n    if (p > N) break;\r\n    mint xp = mint(p).pow(e);\r\n    ll pp = p;\r\
    \n    while (pp <= N) {\r\n      ll i = pp;\r\n      while (i <= N) {\r\n    \
    \    f[i] *= xp;\r\n        i += pp;\r\n      }\r\n      pp *= p;\r\n    }\r\n\
    \  }\r\n  return f;\r\n}\r\n"
  code: "#pragma once\r\n#include \"nt/primetable.hpp\"\r\n\r\n// a^0, ..., a^N\r\n\
    template <typename mint>\r\nvc<mint> powertable_1(mint a, ll N) {\r\n  // table\
    \ of a^i\r\n  vc<mint> f(N + 1, 1);\r\n  FOR(i, N) f[i + 1] = a * f[i];\r\n  return\
    \ f;\r\n}\r\n\r\n// 0^e, ..., N^e\r\ntemplate <typename mint>\r\nvc<mint> powertable_2(ll\
    \ e, ll N) {\r\n  auto primes = primetable(N);\r\n  vc<mint> f(N + 1, 1);\r\n\
    \  f[0] = mint(0).pow(e);\r\n  for (auto&& p: primes) {\r\n    if (p > N) break;\r\
    \n    mint xp = mint(p).pow(e);\r\n    ll pp = p;\r\n    while (pp <= N) {\r\n\
    \      ll i = pp;\r\n      while (i <= N) {\r\n        f[i] *= xp;\r\n       \
    \ i += pp;\r\n      }\r\n      pp *= p;\r\n    }\r\n  }\r\n  return f;\r\n}\r\n"
  dependsOn:
  - nt/primetable.hpp
  isVerificationFile: false
  path: mod/powertable.hpp
  requiredBy: []
  timestamp: '2022-12-12 09:21:17+09:00'
  verificationStatus: LIBRARY_ALL_WA
  verifiedWith:
  - test_atcoder/abc249_ex.test.cpp
  - test_atcoder/abc202_f.test.cpp
  - test/yukicoder/2206.test.cpp
  - test/yukicoder/1760.test.cpp
  - test/library_checker/math/sum_of_exp_times_poly_limit.test.cpp
  - test/mytest/qoj5443.test.cpp
documentation_of: mod/powertable.hpp
layout: document
redirect_from:
- /library/mod/powertable.hpp
- /library/mod/powertable.hpp.html
title: mod/powertable.hpp
---
