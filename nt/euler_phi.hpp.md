---
data:
  _extendedDependsOn:
  - icon: ':question:'
    path: nt/factor.hpp
    title: nt/factor.hpp
  - icon: ':question:'
    path: nt/primetable.hpp
    title: nt/primetable.hpp
  - icon: ':question:'
    path: nt/primetest.hpp
    title: nt/primetest.hpp
  - icon: ':question:'
    path: nt/zeta.hpp
    title: nt/zeta.hpp
  _extendedRequiredBy:
  - icon: ':heavy_check_mark:'
    path: mod/tetration.hpp
    title: mod/tetration.hpp
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/aoj/NTL_1_D.test.cpp
    title: test/aoj/NTL_1_D.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/library_checker/math/tetration.test.cpp
    title: test/library_checker/math/tetration.test.cpp
  - icon: ':x:'
    path: test/yukicoder/1262.test.cpp
    title: test/yukicoder/1262.test.cpp
  _isVerificationFailed: true
  _pathExtension: hpp
  _verificationStatusIcon: ':question:'
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
    \ {primes.begin(), primes.begin() + k};\n}\n#line 3 \"nt/zeta.hpp\"\n\r\ntemplate\
    \ <typename T>\r\nvoid divisor_zeta(vc<T>& A) {\r\n  assert(A[0] == 0);\r\n  int\
    \ N = len(A) - 1;\r\n  auto P = primetable(N);\r\n  for (auto&& p: P) { FOR3(x,\
    \ 1, N / p + 1) A[p * x] += A[x]; }\r\n}\r\n\r\ntemplate <typename T>\r\nvoid\
    \ divisor_mobius(vc<T>& A) {\r\n  assert(A[0] == 0);\r\n  int N = len(A) - 1;\r\
    \n  auto P = primetable(N);\r\n  for (auto&& p: P) { FOR3_R(x, 1, N / p + 1) A[p\
    \ * x] -= A[x]; }\r\n}\r\n\r\ntemplate <typename T>\r\nvoid multiplier_zeta(vc<T>&\
    \ A) {\r\n  assert(A[0] == 0);\r\n  int N = len(A) - 1;\r\n  auto P = primetable(N);\r\
    \n  for (auto&& p: P) { FOR3_R(x, 1, N / p + 1) A[x] += A[p * x]; }\r\n}\r\n\r\
    \ntemplate <typename T>\r\nvoid multiplier_mobius(vc<T>& A) {\r\n  assert(A[0]\
    \ == 0);\r\n  int N = len(A) - 1;\r\n  auto P = primetable(N);\r\n  for (auto&&\
    \ p: P) { FOR3(x, 1, N / p + 1) A[x] -= A[p * x]; }\r\n}\r\n#line 2 \"nt/primetest.hpp\"\
    \nstruct m64 {\r\n  using i64 = int64_t;\r\n  using u64 = uint64_t;\r\n  using\
    \ u128 = __uint128_t;\r\n\r\n  inline static u64 m, r, n2; // r * m = -1 (mod\
    \ 1<<64), n2 = 1<<128 (mod m)\r\n  static void set_mod(u64 m) {\r\n    assert((m\
    \ & 1) == 1);\r\n    m64::m = m;\r\n    n2 = -u128(m) % m;\r\n    r = m;\r\n \
    \   FOR(_, 5) r *= 2 - m * r;\r\n    r = -r;\r\n    assert(r * m == -1ull);\r\n\
    \  }\r\n  static u64 reduce(u128 b) { return (b + u128(u64(b) * r) * m) >> 64;\
    \ }\r\n\r\n  u64 x;\r\n  m64() : x(0) {}\r\n  m64(u64 x) : x(reduce(u128(x) *\
    \ n2)){};\r\n  u64 val() const {\r\n    u64 y = reduce(x);\r\n    return y >=\
    \ m ? y - m : y;\r\n  }\r\n  m64 &operator+=(m64 y) {\r\n    x += y.x - (m <<\
    \ 1);\r\n    x = (i64(x) < 0 ? x + (m << 1) : x);\r\n    return *this;\r\n  }\r\
    \n  m64 &operator-=(m64 y) {\r\n    x -= y.x;\r\n    x = (i64(x) < 0 ? x + (m\
    \ << 1) : x);\r\n    return *this;\r\n  }\r\n  m64 &operator*=(m64 y) {\r\n  \
    \  x = reduce(u128(x) * y.x);\r\n    return *this;\r\n  }\r\n  m64 operator+(m64\
    \ y) const { return m64(*this) += y; }\r\n  m64 operator-(m64 y) const { return\
    \ m64(*this) -= y; }\r\n  m64 operator*(m64 y) const { return m64(*this) *= y;\
    \ }\r\n  bool operator==(m64 y) const {\r\n    return (x >= m ? x - m : x) ==\
    \ (y.x >= m ? y.x - m : y.x);\r\n  }\r\n  bool operator!=(m64 y) const { return\
    \ not operator==(y); }\r\n  m64 pow(u64 n) const {\r\n    m64 y = 1, z = *this;\r\
    \n    for (; n; n >>= 1, z *= z)\r\n      if (n & 1) y *= z;\r\n    return y;\r\
    \n  }\r\n};\r\n\r\nbool primetest(const uint64_t x) {\r\n  using u64 = uint64_t;\r\
    \n  if (x == 2 or x == 3 or x == 5 or x == 7) return true;\r\n  if (x % 2 == 0\
    \ or x % 3 == 0 or x % 5 == 0 or x % 7 == 0) return false;\r\n  if (x < 121) return\
    \ x > 1;\r\n  const u64 d = (x - 1) >> __builtin_ctzll(x - 1);\r\n  m64::set_mod(x);\r\
    \n  const m64 one(1), minus_one(x - 1);\r\n  auto ok = [&](u64 a) {\r\n    auto\
    \ y = m64(a).pow(d);\r\n    u64 t = d;\r\n    while (y != one and y != minus_one\
    \ and t != x - 1) y *= y, t <<= 1;\r\n    if (y != minus_one and t % 2 == 0) return\
    \ false;\r\n    return true;\r\n  };\r\n  if (x < (1ull << 32)) {\r\n    for (u64\
    \ a: {2, 7, 61})\r\n      if (not ok(a)) return false;\r\n  } else {\r\n    for\
    \ (u64 a: {2, 325, 9375, 28178, 450775, 9780504, 1795265022}) {\r\n      if (x\
    \ <= a) return true;\r\n      if (not ok(a)) return false;\r\n    }\r\n  }\r\n\
    \  return true;\r\n}\n#line 3 \"nt/factor.hpp\"\n\nmt19937_64 rng_mt{random_device{}()};\n\
    ll rnd(ll n) { return uniform_int_distribution<ll>(0, n - 1)(rng_mt); }\n\nll\
    \ rho(ll n, ll c) {\n  m64::set_mod(n);\n  assert(n > 1);\n  const m64 cc(c);\n\
    \  auto f = [&](m64 x) { return x * x + cc; };\n  m64 x = 1, y = 2, z = 1, q =\
    \ 1;\n  ll g = 1;\n  const ll m = 1LL << (__lg(n) / 5); // ?\n  for (ll r = 1;\
    \ g == 1; r <<= 1) {\n    x = y;\n    FOR(_, r) y = f(y);\n    for (ll k = 0;\
    \ k < r and g == 1; k += m) {\n      z = y;\n      FOR(_, min(m, r - k)) y = f(y),\
    \ q *= x - y;\n      g = gcd(q.val(), n);\n    }\n  }\n  if (g == n) do {\n  \
    \    z = f(z);\n      g = gcd((x - z).val(), n);\n    } while (g == 1);\n  return\
    \ g;\n}\n\nll find_prime_factor(ll n) {\n  assert(n > 1);\n  if (primetest(n))\
    \ return n;\n  FOR(_, 100) {\n    ll m = rho(n, rnd(n));\n    if (primetest(m))\
    \ return m;\n    n = m;\n  }\n  cerr << \"failed\" << endl;\n  assert(false);\n\
    \  return -1;\n}\n\n// \u30BD\u30FC\u30C8\u3057\u3066\u304F\u308C\u308B\nvc<pair<ll,\
    \ int>> factor(ll n) {\n  assert(n >= 1);\n  vc<pair<ll, int>> pf;\n  FOR3(p,\
    \ 2, 100) {\n    if (p * p > n) break;\n    if (n % p == 0) {\n      ll e = 0;\n\
    \      do { n /= p, e += 1; } while (n % p == 0);\n      pf.eb(p, e);\n    }\n\
    \  }\n  while (n > 1) {\n    ll p = find_prime_factor(n);\n    ll e = 0;\n   \
    \ do { n /= p, e += 1; } while (n % p == 0);\n    pf.eb(p, e);\n  }\n  sort(all(pf));\n\
    \  return pf;\n}\n\nvc<pair<ll, int>> factor_by_lpf(ll n, vc<int>& lpf) {\n  vc<pair<ll,\
    \ int>> res;\n  while (n > 1) {\n    int p = lpf[n];\n    int e = 0;\n    while\
    \ (n % p == 0) {\n      n /= p;\n      ++e;\n    }\n    res.eb(p, e);\n  }\n \
    \ return res;\n}\n#line 3 \"nt/euler_phi.hpp\"\n\r\nll euler_phi(ll n) {\r\n \
    \ auto pf = factor(n);\r\n  for (auto&& [p, e]: pf) n -= n / p;\r\n  return n;\r\
    \n}\r\n\r\nvi euler_phi_table(ll n) {\r\n  vi A(n + 1);\r\n  iota(all(A), 0);\r\
    \n  divisor_mobius(A);\r\n  return A;\r\n}\r\n"
  code: "#include \"nt/zeta.hpp\"\r\n#include \"nt/factor.hpp\"\r\n\r\nll euler_phi(ll\
    \ n) {\r\n  auto pf = factor(n);\r\n  for (auto&& [p, e]: pf) n -= n / p;\r\n\
    \  return n;\r\n}\r\n\r\nvi euler_phi_table(ll n) {\r\n  vi A(n + 1);\r\n  iota(all(A),\
    \ 0);\r\n  divisor_mobius(A);\r\n  return A;\r\n}\r\n"
  dependsOn:
  - nt/zeta.hpp
  - nt/primetable.hpp
  - nt/factor.hpp
  - nt/primetest.hpp
  isVerificationFile: false
  path: nt/euler_phi.hpp
  requiredBy:
  - mod/tetration.hpp
  timestamp: '2023-01-09 23:28:24+09:00'
  verificationStatus: LIBRARY_SOME_WA
  verifiedWith:
  - test/library_checker/math/tetration.test.cpp
  - test/yukicoder/1262.test.cpp
  - test/aoj/NTL_1_D.test.cpp
documentation_of: nt/euler_phi.hpp
layout: document
redirect_from:
- /library/nt/euler_phi.hpp
- /library/nt/euler_phi.hpp.html
title: nt/euler_phi.hpp
---
