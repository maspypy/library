---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: nt/primetable.hpp
    title: nt/primetable.hpp
  _extendedRequiredBy:
  - icon: ':heavy_check_mark:'
    path: nt/all_lcm.hpp
    title: nt/all_lcm.hpp
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/yukicoder/1411.test.cpp
    title: test/yukicoder/1411.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/yukicoder/1881.test.cpp
    title: test/yukicoder/1881.test.cpp
  - icon: ':heavy_check_mark:'
    path: test_atcoder/abc152e.test.cpp
    title: test_atcoder/abc152e.test.cpp
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
    \ {primes.begin(), primes.begin() + k};\n}\n#line 3 \"nt/lpf_table.hpp\"\n\n//\
    \ [0, LIM], 0, 1 \u306B\u306F -1 \u304C\u5165\u308B\u3002\nvc<int> lpf_table(ll\
    \ LIM) {\n  auto primes = primetable(LIM);\n  vc<int> res(LIM + 1, -1);\n  FOR_R(i,\
    \ len(primes)) {\n    auto p = primes[i];\n    FOR3(j, 1, LIM / p + 1) res[p *\
    \ j] = p;\n  }\n  return res;\n}\n"
  code: "#pragma once\n#include \"nt/primetable.hpp\"\n\n// [0, LIM], 0, 1 \u306B\u306F\
    \ -1 \u304C\u5165\u308B\u3002\nvc<int> lpf_table(ll LIM) {\n  auto primes = primetable(LIM);\n\
    \  vc<int> res(LIM + 1, -1);\n  FOR_R(i, len(primes)) {\n    auto p = primes[i];\n\
    \    FOR3(j, 1, LIM / p + 1) res[p * j] = p;\n  }\n  return res;\n}\n"
  dependsOn:
  - nt/primetable.hpp
  isVerificationFile: false
  path: nt/lpf_table.hpp
  requiredBy:
  - nt/all_lcm.hpp
  timestamp: '2022-12-12 09:21:17+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/yukicoder/1411.test.cpp
  - test/yukicoder/1881.test.cpp
  - test_atcoder/abc152e.test.cpp
documentation_of: nt/lpf_table.hpp
layout: document
redirect_from:
- /library/nt/lpf_table.hpp
- /library/nt/lpf_table.hpp.html
title: nt/lpf_table.hpp
---
