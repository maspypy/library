---
data:
  _extendedDependsOn:
  - icon: ':question:'
    path: enumerate/floor_range.hpp
    title: enumerate/floor_range.hpp
  - icon: ':question:'
    path: nt/array_on_floor.hpp
    title: nt/array_on_floor.hpp
  - icon: ':question:'
    path: nt/mobius_table.hpp
    title: nt/mobius_table.hpp
  - icon: ':question:'
    path: nt/primetable.hpp
    title: nt/primetable.hpp
  - icon: ':question:'
    path: nt/zeta.hpp
    title: nt/zeta.hpp
  _extendedRequiredBy:
  - icon: ':x:'
    path: nt/range_rational_count.hpp
    title: nt/range_rational_count.hpp
  _extendedVerifiedWith:
  - icon: ':x:'
    path: test/3_yukicoder/2266.test.cpp
    title: test/3_yukicoder/2266.test.cpp
  _isVerificationFailed: true
  _pathExtension: hpp
  _verificationStatusIcon: ':x:'
  attributes:
    links: []
  bundledCode: "#line 1 \"nt/array_on_floor.hpp\"\n// N=10 \u3060\u3068 dat = {dp[1],\
    \ dp[2], dp[3], dp[5], dp[10]} \u307F\u305F\u3044\u306B\u306A\u308B\n// hashmap\
    \ \u3088\u308A\u6570\u500D\u9AD8\u901F\ntemplate <typename T>\nstruct Array_On_Floor\
    \ {\n  u64 N;\n  u32 t, sq;\n  vc<T> dat;\n  Array_On_Floor() {}\n  Array_On_Floor(u64\
    \ N, T default_value = T{}) : N(N) {\n    assert(N <= u64(1) << 50);\n    sq =\
    \ sqrtl(N);\n    t = (u64(sq) * sq + sq <= N ? sq : sq - 1);\n    dat.resize(t\
    \ + sq, default_value);\n  }\n\n  u32 size() { return dat.size(); }\n\n  T& operator[](u64\
    \ d) {\n    int i = get_index(d);\n    return dat[i];\n  }\n\n  inline u32 get_index(u64\
    \ d) {\n    assert(d > 0);\n    if (d <= t) return d - 1;\n    return dat.size()\
    \ - u32(double(N) / d);\n  }\n\n  // dat[i] \u306B\u5BFE\u5FDC\u3059\u308B floor\n\
    \  u64 get_floor(u32 i) { return (i < t ? 1 + i : double(N) / (t + sq - i)); }\n\
    \n  template <typename F>\n  void enumerate_all(F f) {\n    FOR(i, len(dat)) {\
    \ f(get_floor(i), dat[i]); }\n  }\n};\n#line 2 \"nt/primetable.hpp\"\n\ntemplate\
    \ <typename T = int>\nvc<T> primetable(int LIM) {\n  ++LIM;\n  const int S = 32768;\n\
    \  static int done = 2;\n  static vc<T> primes = {2}, sieve(S + 1);\n\n  if (done\
    \ < LIM) {\n    done = LIM;\n\n    primes = {2}, sieve.assign(S + 1, 0);\n   \
    \ const int R = LIM / 2;\n    primes.reserve(int(LIM / log(LIM) * 1.1));\n   \
    \ vc<pair<int, int>> cp;\n    for (int i = 3; i <= S; i += 2) {\n      if (!sieve[i])\
    \ {\n        cp.eb(i, i * i / 2);\n        for (int j = i * i; j <= S; j += 2\
    \ * i) sieve[j] = 1;\n      }\n    }\n    for (int L = 1; L <= R; L += S) {\n\
    \      array<bool, S> block{};\n      for (auto& [p, idx]: cp)\n        for (int\
    \ i = idx; i < S + L; idx = (i += p)) block[i - L] = 1;\n      FOR(i, min(S, R\
    \ - L)) if (!block[i]) primes.eb((L + i) * 2 + 1);\n    }\n  }\n  int k = LB(primes,\
    \ LIM + 1);\n  return {primes.begin(), primes.begin() + k};\n}\n#line 3 \"nt/zeta.hpp\"\
    \n\r\ntemplate <typename T>\r\nvoid divisor_zeta(vc<T>& A) {\r\n  assert(A[0]\
    \ == 0);\r\n  int N = len(A) - 1;\r\n  auto P = primetable(N);\r\n  for (auto&&\
    \ p: P) { FOR3(x, 1, N / p + 1) A[p * x] += A[x]; }\r\n}\r\n\r\ntemplate <typename\
    \ T>\r\nvoid divisor_mobius(vc<T>& A) {\r\n  assert(A[0] == 0);\r\n  int N = len(A)\
    \ - 1;\r\n  auto P = primetable(N);\r\n  for (auto&& p: P) { FOR3_R(x, 1, N /\
    \ p + 1) A[p * x] -= A[x]; }\r\n}\r\n\r\ntemplate <typename T>\r\nvoid multiplier_zeta(vc<T>&\
    \ A) {\r\n  assert(A[0] == 0);\r\n  int N = len(A) - 1;\r\n  auto P = primetable(N);\r\
    \n  for (auto&& p: P) { FOR3_R(x, 1, N / p + 1) A[x] += A[p * x]; }\r\n}\r\n\r\
    \ntemplate <typename T>\r\nvoid multiplier_mobius(vc<T>& A) {\r\n  assert(A[0]\
    \ == 0);\r\n  int N = len(A) - 1;\r\n  auto P = primetable(N);\r\n  for (auto&&\
    \ p: P) { FOR3(x, 1, N / p + 1) A[x] -= A[p * x]; }\r\n}\r\n#line 2 \"nt/mobius_table.hpp\"\
    \n\r\ntemplate<typename T>\r\nvc<T> mobius_table(int N){\r\n  vc<T> mu(N + 1);\r\
    \n  mu[1] = T(1);\r\n  divisor_mobius(mu);\r\n  return mu;\r\n}\n#line 1 \"enumerate/floor_range.hpp\"\
    \n// \u5546\u304C q \u306E\u533A\u9593 [l,r) \u3092 q \u306B\u3064\u3044\u3066\
    \u6607\u9806\r\ntemplate <typename F>\r\nvoid floor_range(u64 N, F f) {\r\n  assert(N\
    \ <= (u64(1) << 50));\r\n  u64 sq = sqrtl(N);\r\n  u32 n = (sq * sq + sq <= N\
    \ ? sq : sq - 1);\r\n  u64 prev = N + 1;\r\n  for (u32 q = 1; q <= n; ++q) {\r\
    \n    u64 x = double(N) / (q + 1) + 1;\r\n    f(q, x, prev), prev = x;\r\n  }\r\
    \n  for (u32 l = sq; l >= 1; --l) { f(u64(double(N) / l), l, l + 1); }\r\n}\r\n\
    #line 4 \"nt/mertens.hpp\"\n\ntemplate <typename T>\nstruct Mertens {\n  Array_On_Floor<T>\
    \ sum;\n  Mertens() {}\n  Mertens(u64 N, u64 K = -1) { build(N, K); }\n  void\
    \ build(u64 N, u64 K = -1) {\n    sum = Array_On_Floor<T>(N);\n    if (K == u64(-1))\
    \ { K = pow(N, 0.67); }\n    vc<T> A = mobius_table<T>(K);\n    FOR(k, 1, K) A[k\
    \ + 1] += A[k];\n    FOR(i, len(sum)) {\n      u64 n = sum.get_floor(i);\n   \
    \   if (n <= K) {\n        sum.dat[i] = A[n];\n        continue;\n      }\n  \
    \    T ans = 1;\n      floor_range(n, [&](u64 q, u64 l, u64 r) -> void {\n   \
    \     if (q == n) return;\n        ans -= sum[q] * T(r - l);\n      });\n    \
    \  sum.dat[i] = ans;\n    }\n  }\n  T operator[](u64 n) { return sum[n]; }\n};\n"
  code: "#include \"nt/array_on_floor.hpp\"\n#include \"nt/mobius_table.hpp\"\n#include\
    \ \"enumerate/floor_range.hpp\"\n\ntemplate <typename T>\nstruct Mertens {\n \
    \ Array_On_Floor<T> sum;\n  Mertens() {}\n  Mertens(u64 N, u64 K = -1) { build(N,\
    \ K); }\n  void build(u64 N, u64 K = -1) {\n    sum = Array_On_Floor<T>(N);\n\
    \    if (K == u64(-1)) { K = pow(N, 0.67); }\n    vc<T> A = mobius_table<T>(K);\n\
    \    FOR(k, 1, K) A[k + 1] += A[k];\n    FOR(i, len(sum)) {\n      u64 n = sum.get_floor(i);\n\
    \      if (n <= K) {\n        sum.dat[i] = A[n];\n        continue;\n      }\n\
    \      T ans = 1;\n      floor_range(n, [&](u64 q, u64 l, u64 r) -> void {\n \
    \       if (q == n) return;\n        ans -= sum[q] * T(r - l);\n      });\n  \
    \    sum.dat[i] = ans;\n    }\n  }\n  T operator[](u64 n) { return sum[n]; }\n\
    };\n"
  dependsOn:
  - nt/array_on_floor.hpp
  - nt/mobius_table.hpp
  - nt/zeta.hpp
  - nt/primetable.hpp
  - enumerate/floor_range.hpp
  isVerificationFile: false
  path: nt/mertens.hpp
  requiredBy:
  - nt/range_rational_count.hpp
  timestamp: '2024-08-13 20:27:42+09:00'
  verificationStatus: LIBRARY_ALL_WA
  verifiedWith:
  - test/3_yukicoder/2266.test.cpp
documentation_of: nt/mertens.hpp
layout: document
redirect_from:
- /library/nt/mertens.hpp
- /library/nt/mertens.hpp.html
title: nt/mertens.hpp
---
