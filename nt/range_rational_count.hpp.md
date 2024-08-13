---
data:
  _extendedDependsOn:
  - icon: ':x:'
    path: enumerate/floor_range.hpp
    title: enumerate/floor_range.hpp
  - icon: ':x:'
    path: mod/floor_sum_of_linear.hpp
    title: mod/floor_sum_of_linear.hpp
  - icon: ':x:'
    path: nt/array_on_floor.hpp
    title: nt/array_on_floor.hpp
  - icon: ':x:'
    path: nt/mertens.hpp
    title: nt/mertens.hpp
  - icon: ':x:'
    path: nt/mobius_table.hpp
    title: nt/mobius_table.hpp
  - icon: ':x:'
    path: nt/primetable.hpp
    title: nt/primetable.hpp
  - icon: ':x:'
    path: nt/zeta.hpp
    title: nt/zeta.hpp
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':x:'
    path: test/yukicoder/2266.test.cpp
    title: test/yukicoder/2266.test.cpp
  _isVerificationFailed: true
  _pathExtension: hpp
  _verificationStatusIcon: ':x:'
  attributes:
    links: []
  bundledCode: "#line 1 \"nt/range_rational_count.hpp\"\n\n#line 1 \"nt/array_on_floor.hpp\"\
    \n// N=10 \u3060\u3068 dat = {dp[1], dp[2], dp[3], dp[5], dp[10]} \u307F\u305F\
    \u3044\u306B\u306A\u308B\n// hashmap \u3088\u308A\u6570\u500D\u9AD8\u901F\ntemplate\
    \ <typename T>\nstruct Array_On_Floor {\n  u64 N;\n  u32 t, sq;\n  vc<T> dat;\n\
    \  Array_On_Floor() {}\n  Array_On_Floor(u64 N, T default_value = T{}) : N(N)\
    \ {\n    assert(N <= u64(1) << 50);\n    sq = sqrtl(N);\n    t = (u64(sq) * sq\
    \ + sq <= N ? sq : sq - 1);\n    dat.resize(t + sq, default_value);\n  }\n\n \
    \ u32 size() { return dat.size(); }\n\n  T& operator[](u64 d) {\n    int i = get_index(d);\n\
    \    return dat[i];\n  }\n\n  inline u32 get_index(u64 d) {\n    assert(d > 0);\n\
    \    if (d <= t) return d - 1;\n    return dat.size() - u32(double(N) / d);\n\
    \  }\n\n  // dat[i] \u306B\u5BFE\u5FDC\u3059\u308B floor\n  u64 get_floor(u32\
    \ i) { return (i < t ? 1 + i : double(N) / (t + sq - i)); }\n\n  template <typename\
    \ F>\n  void enumerate_all(F f) {\n    FOR(i, len(dat)) { f(get_floor(i), dat[i]);\
    \ }\n  }\n};\n#line 2 \"nt/primetable.hpp\"\n\ntemplate <typename T = int>\nvc<T>\
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
    \ primes.begin() + k};\n}\n#line 3 \"nt/zeta.hpp\"\n\r\ntemplate <typename T>\r\
    \nvoid divisor_zeta(vc<T>& A) {\r\n  assert(A[0] == 0);\r\n  int N = len(A) -\
    \ 1;\r\n  auto P = primetable(N);\r\n  for (auto&& p: P) { FOR3(x, 1, N / p +\
    \ 1) A[p * x] += A[x]; }\r\n}\r\n\r\ntemplate <typename T>\r\nvoid divisor_mobius(vc<T>&\
    \ A) {\r\n  assert(A[0] == 0);\r\n  int N = len(A) - 1;\r\n  auto P = primetable(N);\r\
    \n  for (auto&& p: P) { FOR3_R(x, 1, N / p + 1) A[p * x] -= A[x]; }\r\n}\r\n\r\
    \ntemplate <typename T>\r\nvoid multiplier_zeta(vc<T>& A) {\r\n  assert(A[0] ==\
    \ 0);\r\n  int N = len(A) - 1;\r\n  auto P = primetable(N);\r\n  for (auto&& p:\
    \ P) { FOR3_R(x, 1, N / p + 1) A[x] += A[p * x]; }\r\n}\r\n\r\ntemplate <typename\
    \ T>\r\nvoid multiplier_mobius(vc<T>& A) {\r\n  assert(A[0] == 0);\r\n  int N\
    \ = len(A) - 1;\r\n  auto P = primetable(N);\r\n  for (auto&& p: P) { FOR3(x,\
    \ 1, N / p + 1) A[x] -= A[p * x]; }\r\n}\r\n#line 2 \"nt/mobius_table.hpp\"\n\r\
    \ntemplate<typename T>\r\nvc<T> mobius_table(int N){\r\n  vc<T> mu(N + 1);\r\n\
    \  mu[1] = T(1);\r\n  divisor_mobius(mu);\r\n  return mu;\r\n}\n#line 1 \"enumerate/floor_range.hpp\"\
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
    \  sum.dat[i] = ans;\n    }\n  }\n  T operator[](u64 n) { return sum[n]; }\n};\n\
    #line 2 \"mod/floor_sum_of_linear.hpp\"\n\n// sum_{x in [L,R)} floor(ax + b, mod)\n\
    // I \u306F\u7BC4\u56F2\u5185\u3067 ax+b \u304C\u30AA\u30FC\u30D0\u30FC\u30D5\u30ED\
    \u30FC\u3057\u306A\u3044\u7A0B\u5EA6\ntemplate <typename O = i128, typename I\
    \ = long long>\nO floor_sum_of_linear(I L, I R, I a, I b, I mod) {\n  assert(L\
    \ <= R);\n  O res = 0;\n  b += L * a;\n  I N = R - L;\n\n  if (b < 0) {\n    I\
    \ k = ceil(-b, mod);\n    b += k * mod;\n    res -= O(N) * O(k);\n  }\n\n  while\
    \ (N) {\n    I q;\n    tie(q, a) = divmod(a, mod);\n    res += (N & 1 ? O(N) *\
    \ O((N - 1) / 2) * O(q) : O(N / 2) * O(N - 1) * O(q));\n    if (b >= mod) {\n\
    \      tie(q, b) = divmod(b, mod);\n      res += O(N) * q;\n    }\n    tie(N,\
    \ b) = divmod(a * N + b, mod);\n    tie(a, mod) = mp(mod, a);\n  }\n  return res;\n\
    }\n#line 4 \"nt/range_rational_count.hpp\"\n\n// \u6700\u5927\u5206\u6BCD N \u3092\
    \u6307\u5B9A\u3059\u308B\n// \u65E2\u7D04\u5206\u6570\u3092\u6570\u3048\u305F\u308A\
    \ k \u756A\u76EE\u3092\u6C42\u3081\u305F\u308A\u3059\u308B\nstruct Range_Rational_Count\
    \ {\n  u32 N;\n  u64 total;\n  Mertens<int> M;\n  Range_Rational_Count(u32 N)\
    \ : N(N), M(N) { total = count(1, 1); }\n\n  // [0, a/b)\n  u64 count(u32 a, u32\
    \ b) {\n    assert(a <= b);\n    if (a == 0) return 0;\n    // [0,a/b]\n    u64\
    \ ans = 1;\n    floor_range(N, [&](u32 q, u32 l, u32 r) -> void {\n      ans +=\
    \ u64(M[q]) * floor_sum_of_linear<u64, u64>(l, r, a, 0, b);\n    });\n    // a/b\n\
    \    if (b <= N) --ans;\n    return ans;\n  }\n\n  // [0,1) \u306E\u4E2D\u3067\
    \ k \u756A\u76EE\n  pair<u32, u32> kth(u64 k) {\n    assert(k < total);\n    u32\
    \ int_part = k / total;\n    k %= total;\n    map<pair<u32, u32>, u64> MP;\n \
    \   auto query = [&](u32 a, u32 b) -> u64 {\n      pair<u32, u32> k = {a, b};\n\
    \      if (MP.count(k)) return MP[k];\n      return MP[k] = count(a, b);\n   \
    \ };\n    // k \u500B\u4EE5\u4E0B\u306A\u3082\u306E\u306E max\n    u32 a = 0,\
    \ b = 1, c = 1, d = 1;\n    while (b + d <= N) {\n      // \u53F3\u306B\u9032\u3080\
    \n      u32 l = 0, r = 1;\n      while (b + r * d <= N && query(a + r * c, b +\
    \ r * d) <= k) {\n        l = r, r = 2 * r;\n      }\n      while (l + 1 < r)\
    \ {\n        u32 m = l + (r - l) / 2;\n        (query(a + m * c, b + m * d) <=\
    \ k ? l : r) = m;\n      }\n      a += l * c, b += l * d;\n      // \u5DE6\u306B\
    \u9032\u3080\n      l = 0, r = 1;\n      while (r * b + d <= N && query(r * a\
    \ + c, r * b + d) > k) {\n        l = r, r = 2 * r;\n      }\n      while (l +\
    \ 1 < r) {\n        u32 m = l + (r - l) / 2;\n        (query(m * a + c, m * b\
    \ + d) > k ? l : r) = m;\n      }\n      c += l * a, d += l * b;\n    }\n    return\
    \ {int_part * b + a, b};\n  }\n};\n"
  code: "\n#include \"nt/mertens.hpp\"\n#include \"mod/floor_sum_of_linear.hpp\"\n\
    \n// \u6700\u5927\u5206\u6BCD N \u3092\u6307\u5B9A\u3059\u308B\n// \u65E2\u7D04\
    \u5206\u6570\u3092\u6570\u3048\u305F\u308A k \u756A\u76EE\u3092\u6C42\u3081\u305F\
    \u308A\u3059\u308B\nstruct Range_Rational_Count {\n  u32 N;\n  u64 total;\n  Mertens<int>\
    \ M;\n  Range_Rational_Count(u32 N) : N(N), M(N) { total = count(1, 1); }\n\n\
    \  // [0, a/b)\n  u64 count(u32 a, u32 b) {\n    assert(a <= b);\n    if (a ==\
    \ 0) return 0;\n    // [0,a/b]\n    u64 ans = 1;\n    floor_range(N, [&](u32 q,\
    \ u32 l, u32 r) -> void {\n      ans += u64(M[q]) * floor_sum_of_linear<u64, u64>(l,\
    \ r, a, 0, b);\n    });\n    // a/b\n    if (b <= N) --ans;\n    return ans;\n\
    \  }\n\n  // [0,1) \u306E\u4E2D\u3067 k \u756A\u76EE\n  pair<u32, u32> kth(u64\
    \ k) {\n    assert(k < total);\n    u32 int_part = k / total;\n    k %= total;\n\
    \    map<pair<u32, u32>, u64> MP;\n    auto query = [&](u32 a, u32 b) -> u64 {\n\
    \      pair<u32, u32> k = {a, b};\n      if (MP.count(k)) return MP[k];\n    \
    \  return MP[k] = count(a, b);\n    };\n    // k \u500B\u4EE5\u4E0B\u306A\u3082\
    \u306E\u306E max\n    u32 a = 0, b = 1, c = 1, d = 1;\n    while (b + d <= N)\
    \ {\n      // \u53F3\u306B\u9032\u3080\n      u32 l = 0, r = 1;\n      while (b\
    \ + r * d <= N && query(a + r * c, b + r * d) <= k) {\n        l = r, r = 2 *\
    \ r;\n      }\n      while (l + 1 < r) {\n        u32 m = l + (r - l) / 2;\n \
    \       (query(a + m * c, b + m * d) <= k ? l : r) = m;\n      }\n      a += l\
    \ * c, b += l * d;\n      // \u5DE6\u306B\u9032\u3080\n      l = 0, r = 1;\n \
    \     while (r * b + d <= N && query(r * a + c, r * b + d) > k) {\n        l =\
    \ r, r = 2 * r;\n      }\n      while (l + 1 < r) {\n        u32 m = l + (r -\
    \ l) / 2;\n        (query(m * a + c, m * b + d) > k ? l : r) = m;\n      }\n \
    \     c += l * a, d += l * b;\n    }\n    return {int_part * b + a, b};\n  }\n\
    };"
  dependsOn:
  - nt/mertens.hpp
  - nt/array_on_floor.hpp
  - nt/mobius_table.hpp
  - nt/zeta.hpp
  - nt/primetable.hpp
  - enumerate/floor_range.hpp
  - mod/floor_sum_of_linear.hpp
  isVerificationFile: false
  path: nt/range_rational_count.hpp
  requiredBy: []
  timestamp: '2024-08-13 20:27:42+09:00'
  verificationStatus: LIBRARY_ALL_WA
  verifiedWith:
  - test/yukicoder/2266.test.cpp
documentation_of: nt/range_rational_count.hpp
layout: document
redirect_from:
- /library/nt/range_rational_count.hpp
- /library/nt/range_rational_count.hpp.html
title: nt/range_rational_count.hpp
---
