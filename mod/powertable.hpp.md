---
data:
  _extendedDependsOn:
  - icon: ':question:'
    path: nt/primetable.hpp
    title: nt/primetable.hpp
  _extendedRequiredBy:
  - icon: ':heavy_check_mark:'
    path: linalg/det_A_plus_xB.hpp
    title: linalg/det_A_plus_xB.hpp
  - icon: ':heavy_check_mark:'
    path: poly/poly_taylor_shift.hpp
    title: poly/poly_taylor_shift.hpp
  - icon: ':heavy_check_mark:'
    path: seq/famous/eulerian_number.hpp
    title: seq/famous/eulerian_number.hpp
  - icon: ':heavy_check_mark:'
    path: seq/famous/stirling_number_1.hpp
    title: seq/famous/stirling_number_1.hpp
  - icon: ':heavy_check_mark:'
    path: seq/famous/stirling_number_2.hpp
    title: seq/famous/stirling_number_2.hpp
  - icon: ':heavy_check_mark:'
    path: seq/famous/surjection.hpp
    title: seq/famous/surjection.hpp
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/atcoder/abc249_ex.test.cpp
    title: test/atcoder/abc249_ex.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/library_checker/math/stirling_number_of_the_first_kind.test.cpp
    title: test/library_checker/math/stirling_number_of_the_first_kind.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/library_checker/math/stirling_number_of_the_second_kind.test.cpp
    title: test/library_checker/math/stirling_number_of_the_second_kind.test.cpp
  - icon: ':x:'
    path: test/library_checker/math/sum_of_exp_times_poly.test.cpp
    title: test/library_checker/math/sum_of_exp_times_poly.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/library_checker/math/sum_of_exp_times_poly_limit.test.cpp
    title: test/library_checker/math/sum_of_exp_times_poly_limit.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/library_checker/polynomial/polynomial_taylor_shift.test.cpp
    title: test/library_checker/polynomial/polynomial_taylor_shift.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/mytest/bell.test.cpp
    title: test/mytest/bell.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/mytest/eulerian_number.test.cpp
    title: test/mytest/eulerian_number.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/yukicoder/1303.test.cpp
    title: test/yukicoder/1303.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/yukicoder/1321.test.cpp
    title: test/yukicoder/1321.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/yukicoder/1392.test.cpp
    title: test/yukicoder/1392.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/yukicoder/1760.test.cpp
    title: test/yukicoder/1760.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/yukicoder/1821.test.cpp
    title: test/yukicoder/1821.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/yukicoder/1875.test.cpp
    title: test/yukicoder/1875.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/yukicoder/1907.test.cpp
    title: test/yukicoder/1907.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/yukicoder/2005.test.cpp
    title: test/yukicoder/2005.test.cpp
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
    \ LIM + 1);\n  return {primes.begin(), primes.begin() + k};\n}\n#line 3 \"mod/powertable.hpp\"\
    \n\r\n// a^0, ..., a^N\r\ntemplate <typename mint>\r\nvc<mint> powertable_1(mint\
    \ a, ll N) {\r\n  // table of a^i\r\n  vc<mint> f(N + 1, 1);\r\n  FOR(i, N) f[i\
    \ + 1] = a * f[i];\r\n  return f;\r\n}\r\n\r\n// 0^e, ..., N^e\r\ntemplate <typename\
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
  requiredBy:
  - poly/poly_taylor_shift.hpp
  - seq/famous/eulerian_number.hpp
  - seq/famous/stirling_number_2.hpp
  - seq/famous/surjection.hpp
  - seq/famous/stirling_number_1.hpp
  - linalg/det_A_plus_xB.hpp
  timestamp: '2022-08-17 05:57:42+09:00'
  verificationStatus: LIBRARY_SOME_WA
  verifiedWith:
  - test/yukicoder/1821.test.cpp
  - test/yukicoder/2005.test.cpp
  - test/yukicoder/1392.test.cpp
  - test/yukicoder/1760.test.cpp
  - test/yukicoder/1303.test.cpp
  - test/yukicoder/1907.test.cpp
  - test/yukicoder/1875.test.cpp
  - test/yukicoder/1321.test.cpp
  - test/mytest/bell.test.cpp
  - test/mytest/eulerian_number.test.cpp
  - test/library_checker/polynomial/polynomial_taylor_shift.test.cpp
  - test/library_checker/math/stirling_number_of_the_first_kind.test.cpp
  - test/library_checker/math/stirling_number_of_the_second_kind.test.cpp
  - test/library_checker/math/sum_of_exp_times_poly.test.cpp
  - test/library_checker/math/sum_of_exp_times_poly_limit.test.cpp
  - test/atcoder/abc249_ex.test.cpp
documentation_of: mod/powertable.hpp
layout: document
redirect_from:
- /library/mod/powertable.hpp
- /library/mod/powertable.hpp.html
title: mod/powertable.hpp
---
