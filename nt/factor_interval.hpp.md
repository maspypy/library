---
data:
  _extendedDependsOn:
  - icon: ':x:'
    path: nt/primetable.hpp
    title: nt/primetable.hpp
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':x:'
    path: test_atcoder/abc227g.test.cpp
    title: test_atcoder/abc227g.test.cpp
  _isVerificationFailed: true
  _pathExtension: hpp
  _verificationStatusIcon: ':x:'
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
    \ primes.begin() + k};\n}\n#line 2 \"nt/factor_interval.hpp\"\n\n// n \u304C p\
    \ \u3092\u6301\u3064\u3068\u304D f(n, p) \u3092\u547C\u3076\ntemplate <typename\
    \ F>\nvoid factor_interval(ll L, ll R, F f) {\n  int n = R - L;\n  auto primes\
    \ = primetable(sqrt(R));\n  vi A(n);\n  iota(all(A), L);\n  for (auto&& p: primes)\
    \ {\n    ll pp = 1;\n    while (1) {\n      if (pp > R / p) break;\n      pp *=\
    \ p;\n      ll s = ceil(L, pp) * pp;\n      while (s < R) {\n        f(s, p);\n\
    \        A[s - L] /= p;\n        s += pp;\n      }\n    }\n  }\n  FOR(i, n) if\
    \ (A[i] > 1) f(L + i, A[i]);\n}\n"
  code: "#include \"nt/primetable.hpp\"\n\n// n \u304C p \u3092\u6301\u3064\u3068\u304D\
    \ f(n, p) \u3092\u547C\u3076\ntemplate <typename F>\nvoid factor_interval(ll L,\
    \ ll R, F f) {\n  int n = R - L;\n  auto primes = primetable(sqrt(R));\n  vi A(n);\n\
    \  iota(all(A), L);\n  for (auto&& p: primes) {\n    ll pp = 1;\n    while (1)\
    \ {\n      if (pp > R / p) break;\n      pp *= p;\n      ll s = ceil(L, pp) *\
    \ pp;\n      while (s < R) {\n        f(s, p);\n        A[s - L] /= p;\n     \
    \   s += pp;\n      }\n    }\n  }\n  FOR(i, n) if (A[i] > 1) f(L + i, A[i]);\n\
    }\n"
  dependsOn:
  - nt/primetable.hpp
  isVerificationFile: false
  path: nt/factor_interval.hpp
  requiredBy: []
  timestamp: '2023-08-06 03:59:07+09:00'
  verificationStatus: LIBRARY_ALL_WA
  verifiedWith:
  - test_atcoder/abc227g.test.cpp
documentation_of: nt/factor_interval.hpp
layout: document
redirect_from:
- /library/nt/factor_interval.hpp
- /library/nt/factor_interval.hpp.html
title: nt/factor_interval.hpp
---
