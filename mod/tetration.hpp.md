---
data:
  _extendedDependsOn:
  - icon: ':question:'
    path: mod/barrett.hpp
    title: mod/barrett.hpp
  - icon: ':question:'
    path: mod/mongomery_modint.hpp
    title: mod/mongomery_modint.hpp
  - icon: ':heavy_check_mark:'
    path: nt/euler_phi.hpp
    title: nt/euler_phi.hpp
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
  - icon: ':question:'
    path: random/base.hpp
    title: random/base.hpp
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/library_checker/math/tetration.test.cpp
    title: test/library_checker/math/tetration.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 2 \"mod/barrett.hpp\"\n\n// https://github.com/atcoder/ac-library/blob/master/atcoder/internal_math.hpp\n\
    struct Barrett {\n  u32 m;\n  u64 im;\n  explicit Barrett(u32 m = 1) : m(m), im(u64(-1)\
    \ / m + 1) {}\n  u32 umod() const { return m; }\n  u32 modulo(u64 z) {\n    if\
    \ (m == 1) return 0;\n    u64 x = (u64)(((unsigned __int128)(z)*im) >> 64);\n\
    \    u64 y = x * m;\n    return (z - y + (z < y ? m : 0));\n  }\n  u64 floor(u64\
    \ z) {\n    if (m == 1) return z;\n    u64 x = (u64)(((unsigned __int128)(z)*im)\
    \ >> 64);\n    u64 y = x * m;\n    return (z < y ? x - 1 : x);\n  }\n  pair<u64,\
    \ u32> divmod(u64 z) {\n    if (m == 1) return {z, 0};\n    u64 x = (u64)(((unsigned\
    \ __int128)(z)*im) >> 64);\n    u64 y = x * m;\n    if (z < y) return {x - 1,\
    \ z - y + m};\n    return {x, z - y};\n  }\n  u32 mul(u32 a, u32 b) { return modulo(u64(a)\
    \ * b); }\n};\n\nstruct Barrett_64 {\n  u128 mod, mh, ml;\n\n  explicit Barrett_64(u64\
    \ mod = 1) : mod(mod) {\n    u128 m = u128(-1) / mod;\n    if (m * mod + mod ==\
    \ u128(0)) ++m;\n    mh = m >> 64;\n    ml = m & u64(-1);\n  }\n\n  u64 umod()\
    \ const { return mod; }\n\n  u64 modulo(u128 x) {\n    u128 z = (x & u64(-1))\
    \ * ml;\n    z = (x & u64(-1)) * mh + (x >> 64) * ml + (z >> 64);\n    z = (x\
    \ >> 64) * mh + (z >> 64);\n    x -= z * mod;\n    return x < mod ? x : x - mod;\n\
    \  }\n\n  u64 mul(u64 a, u64 b) { return modulo(u128(a) * b); }\n};\n#line 2 \"\
    nt/primetable.hpp\"\n\ntemplate <typename T = int>\nvc<T> primetable(int LIM)\
    \ {\n  ++LIM;\n  const int S = 32768;\n  static int done = 2;\n  static vc<T>\
    \ primes = {2}, sieve(S + 1);\n\n  if (done < LIM) {\n    done = LIM;\n\n    primes\
    \ = {2}, sieve.assign(S + 1, 0);\n    const int R = LIM / 2;\n    primes.reserve(int(LIM\
    \ / log(LIM) * 1.1));\n    vc<pair<int, int>> cp;\n    for (int i = 3; i <= S;\
    \ i += 2) {\n      if (!sieve[i]) {\n        cp.eb(i, i * i / 2);\n        for\
    \ (int j = i * i; j <= S; j += 2 * i) sieve[j] = 1;\n      }\n    }\n    for (int\
    \ L = 1; L <= R; L += S) {\n      array<bool, S> block{};\n      for (auto& [p,\
    \ idx]: cp)\n        for (int i = idx; i < S + L; idx = (i += p)) block[i - L]\
    \ = 1;\n      FOR(i, min(S, R - L)) if (!block[i]) primes.eb((L + i) * 2 + 1);\n\
    \    }\n  }\n  int k = LB(primes, LIM + 1);\n  return {primes.begin(), primes.begin()\
    \ + k};\n}\n#line 3 \"nt/zeta.hpp\"\n\r\ntemplate <typename T>\r\nvoid divisor_zeta(vc<T>&\
    \ A) {\r\n  assert(A[0] == 0);\r\n  int N = len(A) - 1;\r\n  auto P = primetable(N);\r\
    \n  for (auto&& p: P) { FOR3(x, 1, N / p + 1) A[p * x] += A[x]; }\r\n}\r\n\r\n\
    template <typename T>\r\nvoid divisor_mobius(vc<T>& A) {\r\n  assert(A[0] == 0);\r\
    \n  int N = len(A) - 1;\r\n  auto P = primetable(N);\r\n  for (auto&& p: P) {\
    \ FOR3_R(x, 1, N / p + 1) A[p * x] -= A[x]; }\r\n}\r\n\r\ntemplate <typename T>\r\
    \nvoid multiplier_zeta(vc<T>& A) {\r\n  assert(A[0] == 0);\r\n  int N = len(A)\
    \ - 1;\r\n  auto P = primetable(N);\r\n  for (auto&& p: P) { FOR3_R(x, 1, N /\
    \ p + 1) A[x] += A[p * x]; }\r\n}\r\n\r\ntemplate <typename T>\r\nvoid multiplier_mobius(vc<T>&\
    \ A) {\r\n  assert(A[0] == 0);\r\n  int N = len(A) - 1;\r\n  auto P = primetable(N);\r\
    \n  for (auto&& p: P) { FOR3(x, 1, N / p + 1) A[x] -= A[p * x]; }\r\n}\r\n#line\
    \ 2 \"nt/factor.hpp\"\n\n#line 2 \"random/base.hpp\"\n\nu64 RNG_64() {\n  static\
    \ uint64_t x_\n      = uint64_t(chrono::duration_cast<chrono::nanoseconds>(\n\
    \                     chrono::high_resolution_clock::now().time_since_epoch())\n\
    \                     .count())\n        * 10150724397891781847ULL;\n  x_ ^= x_\
    \ << 7;\n  return x_ ^= x_ >> 9;\n}\n\nu64 RNG(u64 lim) { return RNG_64() % lim;\
    \ }\n\nll RNG(ll l, ll r) { return l + RNG_64() % (r - l); }\n#line 2 \"mod/mongomery_modint.hpp\"\
    \n\n// odd mod.\n// x \u306E\u4EE3\u308F\u308A\u306B rx \u3092\u6301\u3064\ntemplate\
    \ <int id, typename U1, typename U2>\nstruct Mongomery_modint {\n  using mint\
    \ = Mongomery_modint;\n  inline static U1 m, r, n2;\n  static constexpr int W\
    \ = numeric_limits<U1>::digits;\n\n  static void set_mod(U1 mod) {\n    assert(mod\
    \ & 1 && mod <= U1(1) << (W - 2));\n    m = mod, n2 = -U2(m) % m, r = m;\n   \
    \ FOR(5) r *= 2 - m * r;\n    r = -r;\n    assert(r * m == U1(-1));\n  }\n  static\
    \ U1 reduce(U2 b) { return (b + U2(U1(b) * r) * m) >> W; }\n\n  U1 x;\n  Mongomery_modint()\
    \ : x(0) {}\n  Mongomery_modint(U1 x) : x(reduce(U2(x) * n2)){};\n  U1 val() const\
    \ {\n    U1 y = reduce(x);\n    return y >= m ? y - m : y;\n  }\n  mint &operator+=(mint\
    \ y) {\n    x = ((x += y.x) >= m ? x - m : x);\n    return *this;\n  }\n  mint\
    \ &operator-=(mint y) {\n    x -= (x >= y.x ? y.x : y.x - m);\n    return *this;\n\
    \  }\n  mint &operator*=(mint y) {\n    x = reduce(U2(x) * y.x);\n    return *this;\n\
    \  }\n  mint operator+(mint y) const { return mint(*this) += y; }\n  mint operator-(mint\
    \ y) const { return mint(*this) -= y; }\n  mint operator*(mint y) const { return\
    \ mint(*this) *= y; }\n  bool operator==(mint y) const {\n    return (x >= m ?\
    \ x - m : x) == (y.x >= m ? y.x - m : y.x);\n  }\n  bool operator!=(mint y) const\
    \ { return not operator==(y); }\n  mint pow(ll n) const {\n    assert(n >= 0);\n\
    \    mint y = 1, z = *this;\n    for (; n; n >>= 1, z *= z)\n      if (n & 1)\
    \ y *= z;\n    return y;\n  }\n};\n\ntemplate <int id>\nusing Mongomery_modint_32\
    \ = Mongomery_modint<id, u32, u64>;\ntemplate <int id>\nusing Mongomery_modint_64\
    \ = Mongomery_modint<id, u64, u128>;\n#line 3 \"nt/primetest.hpp\"\n\r\nbool primetest(const\
    \ u64 x) {\r\n  assert(x < u64(1) << 62);\r\n  if (x == 2 or x == 3 or x == 5\
    \ or x == 7) return true;\r\n  if (x % 2 == 0 or x % 3 == 0 or x % 5 == 0 or x\
    \ % 7 == 0) return false;\r\n  if (x < 121) return x > 1;\r\n  const u64 d = (x\
    \ - 1) >> lowbit(x - 1);\r\n\r\n  using mint = Mongomery_modint_64<202311020>;\r\
    \n\r\n  mint::set_mod(x);\r\n  const mint one(u64(1)), minus_one(x - 1);\r\n \
    \ auto ok = [&](u64 a) -> bool {\r\n    auto y = mint(a).pow(d);\r\n    u64 t\
    \ = d;\r\n    while (y != one && y != minus_one && t != x - 1) y *= y, t <<= 1;\r\
    \n    if (y != minus_one && t % 2 == 0) return false;\r\n    return true;\r\n\
    \  };\r\n  if (x < (u64(1) << 32)) {\r\n    for (u64 a: {2, 7, 61})\r\n      if\
    \ (!ok(a)) return false;\r\n  } else {\r\n    for (u64 a: {2, 325, 9375, 28178,\
    \ 450775, 9780504, 1795265022}) {\r\n      if (!ok(a)) return false;\r\n    }\r\
    \n  }\r\n  return true;\r\n}\n#line 5 \"nt/factor.hpp\"\n\ntemplate <typename\
    \ mint>\nll rho(ll n, ll c) {\n  assert(n > 1);\n  const mint cc(c);\n  auto f\
    \ = [&](mint x) { return x * x + cc; };\n  mint x = 1, y = 2, z = 1, q = 1;\n\
    \  ll g = 1;\n  const ll m = 1LL << (__lg(n) / 5);\n  for (ll r = 1; g == 1; r\
    \ <<= 1) {\n    x = y;\n    FOR(r) y = f(y);\n    for (ll k = 0; k < r && g ==\
    \ 1; k += m) {\n      z = y;\n      FOR(min(m, r - k)) y = f(y), q *= x - y;\n\
    \      g = gcd(q.val(), n);\n    }\n  }\n  if (g == n) do {\n      z = f(z);\n\
    \      g = gcd((x - z).val(), n);\n    } while (g == 1);\n  return g;\n}\n\nll\
    \ find_prime_factor(ll n) {\n  assert(n > 1);\n  if (primetest(n)) return n;\n\
    \  FOR(100) {\n    ll m = 0;\n    if (n < (1 << 30)) {\n      using mint = Mongomery_modint_32<20231025>;\n\
    \      mint::set_mod(n);\n      m = rho<mint>(n, RNG(0, n));\n    } else {\n \
    \     using mint = Mongomery_modint_64<20231025>;\n      mint::set_mod(n);\n \
    \     m = rho<mint>(n, RNG(0, n));\n    }\n    if (primetest(m)) return m;\n \
    \   n = m;\n  }\n  assert(0);\n  return -1;\n}\n\n// \u30BD\u30FC\u30C8\u3057\u3066\
    \u304F\u308C\u308B\nvc<pair<ll, int>> factor(ll n) {\n  assert(n >= 1);\n  vc<pair<ll,\
    \ int>> pf;\n  FOR(p, 2, 100) {\n    if (p * p > n) break;\n    if (n % p == 0)\
    \ {\n      ll e = 0;\n      do { n /= p, e += 1; } while (n % p == 0);\n     \
    \ pf.eb(p, e);\n    }\n  }\n  while (n > 1) {\n    ll p = find_prime_factor(n);\n\
    \    ll e = 0;\n    do { n /= p, e += 1; } while (n % p == 0);\n    pf.eb(p, e);\n\
    \  }\n  sort(all(pf));\n  return pf;\n}\n\nvc<pair<ll, int>> factor_by_lpf(ll\
    \ n, vc<int>& lpf) {\n  vc<pair<ll, int>> res;\n  while (n > 1) {\n    int p =\
    \ lpf[n];\n    int e = 0;\n    while (n % p == 0) {\n      n /= p;\n      ++e;\n\
    \    }\n    res.eb(p, e);\n  }\n  return res;\n}\n#line 3 \"nt/euler_phi.hpp\"\
    \n\r\nll euler_phi(ll n) {\r\n  auto pf = factor(n);\r\n  for (auto&& [p, e]:\
    \ pf) n -= n / p;\r\n  return n;\r\n}\r\n\r\ntemplate <typename T>\r\nvc<T> euler_phi_table(ll\
    \ n) {\r\n  vc<T> A(n + 1);\r\n  FOR(i, 1, n + 1) A[i] = T(i);\r\n  divisor_mobius(A);\r\
    \n  return A;\r\n}\r\n#line 3 \"mod/tetration.hpp\"\n\r\nint tetration(vc<ll>\
    \ a, int mod) {\r\n  for (auto&& x: a) assert(x > 0);\r\n\r\n  // a[0]^(a[1]^(a[2]^...))\r\
    \n  vc<int> mod_chain = {mod};\r\n  while (mod_chain.back() > 1) mod_chain.eb(euler_phi(mod_chain.back()));\r\
    \n  while (len(a) > len(mod_chain)) a.pop_back();\r\n  while (len(mod_chain) >\
    \ len(a)) mod_chain.pop_back();\r\n\r\n  auto pow = [&](ll x, int n, int mod)\
    \ -> int {\r\n    Barrett bt(mod);\r\n    if (x >= mod) x = bt.modulo(x) + mod;\r\
    \n    ll v = 1;\r\n    do {\r\n      if (n & 1) {\r\n        v *= x;\r\n     \
    \   if (v >= mod) v = bt.modulo(v) + mod;\r\n      }\r\n      x *= x;\r\n    \
    \  if (x >= mod) x = bt.modulo(x) + mod;\r\n      n /= 2;\r\n    } while (n);\r\
    \n    return v;\r\n  };\r\n\r\n  int v = 1;\r\n  FOR_R(i, len(a)) v = pow(a[i],\
    \ v, mod_chain[i]);\r\n  return v % mod;\r\n}\r\n"
  code: "#include \"mod/barrett.hpp\"\r\n#include \"nt/euler_phi.hpp\"\r\n\r\nint\
    \ tetration(vc<ll> a, int mod) {\r\n  for (auto&& x: a) assert(x > 0);\r\n\r\n\
    \  // a[0]^(a[1]^(a[2]^...))\r\n  vc<int> mod_chain = {mod};\r\n  while (mod_chain.back()\
    \ > 1) mod_chain.eb(euler_phi(mod_chain.back()));\r\n  while (len(a) > len(mod_chain))\
    \ a.pop_back();\r\n  while (len(mod_chain) > len(a)) mod_chain.pop_back();\r\n\
    \r\n  auto pow = [&](ll x, int n, int mod) -> int {\r\n    Barrett bt(mod);\r\n\
    \    if (x >= mod) x = bt.modulo(x) + mod;\r\n    ll v = 1;\r\n    do {\r\n  \
    \    if (n & 1) {\r\n        v *= x;\r\n        if (v >= mod) v = bt.modulo(v)\
    \ + mod;\r\n      }\r\n      x *= x;\r\n      if (x >= mod) x = bt.modulo(x) +\
    \ mod;\r\n      n /= 2;\r\n    } while (n);\r\n    return v;\r\n  };\r\n\r\n \
    \ int v = 1;\r\n  FOR_R(i, len(a)) v = pow(a[i], v, mod_chain[i]);\r\n  return\
    \ v % mod;\r\n}\r\n"
  dependsOn:
  - mod/barrett.hpp
  - nt/euler_phi.hpp
  - nt/zeta.hpp
  - nt/primetable.hpp
  - nt/factor.hpp
  - random/base.hpp
  - nt/primetest.hpp
  - mod/mongomery_modint.hpp
  isVerificationFile: false
  path: mod/tetration.hpp
  requiredBy: []
  timestamp: '2023-11-02 05:00:07+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/library_checker/math/tetration.test.cpp
documentation_of: mod/tetration.hpp
layout: document
redirect_from:
- /library/mod/tetration.hpp
- /library/mod/tetration.hpp.html
title: mod/tetration.hpp
---
