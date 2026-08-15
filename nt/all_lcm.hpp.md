---
data:
  _extendedDependsOn:
  - icon: ':question:'
    path: mod/mongomery_modint.hpp
    title: mod/mongomery_modint.hpp
  - icon: ':question:'
    path: nt/factor.hpp
    title: nt/factor.hpp
  - icon: ':question:'
    path: nt/lpf_table.hpp
    title: nt/lpf_table.hpp
  - icon: ':question:'
    path: nt/prime_table.hpp
    title: nt/prime_table.hpp
  - icon: ':question:'
    path: nt/primetest.hpp
    title: nt/primetest.hpp
  - icon: ':question:'
    path: other/bit.hpp
    title: other/bit.hpp
  - icon: ':question:'
    path: random/base.hpp
    title: random/base.hpp
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':warning:'
  attributes:
    links: []
  bundledCode: "#line 1 \"nt/factor.hpp\"\n\n#line 1 \"random/base.hpp\"\n\nu64 RNG_64()\
    \ {\n  static u64 x_ = u64(chrono::duration_cast<chrono::nanoseconds>(chrono::high_resolution_clock::now().time_since_epoch()).count())\
    \ * 10150724397891781847ULL;\n  x_ ^= x_ << 7;\n  return x_ ^= x_ >> 9;\n}\n\n\
    u64 RNG(u64 lim) { return RNG_64() % lim; }\n\nll RNG(ll l, ll r) { return l +\
    \ RNG_64() % (r - l); }\n#line 1 \"other/bit.hpp\"\n\nint popcnt(int x) { return\
    \ __builtin_popcount(x); }\nint popcnt(u32 x) { return __builtin_popcount(x);\
    \ }\nint popcnt(ll x) { return __builtin_popcountll(x); }\nint popcnt(u64 x) {\
    \ return __builtin_popcountll(x); }\nint popcnt_sgn(int x) { return (__builtin_parity(unsigned(x))\
    \ & 1 ? -1 : 1); }\nint popcnt_sgn(u32 x) { return (__builtin_parity(x) & 1 ?\
    \ -1 : 1); }\nint popcnt_sgn(ll x) { return (__builtin_parityll(x) & 1 ? -1 :\
    \ 1); }\nint popcnt_sgn(u64 x) { return (__builtin_parityll(x) & 1 ? -1 : 1);\
    \ }\n// (0, 1, 2, 3, 4) -> (-1, 0, 1, 1, 2)\nint topbit(int x) { return (x ==\
    \ 0 ? -1 : 31 - __builtin_clz(x)); }\nint topbit(u32 x) { return (x == 0 ? -1\
    \ : 31 - __builtin_clz(x)); }\nint topbit(ll x) { return (x == 0 ? -1 : 63 - __builtin_clzll(x));\
    \ }\nint topbit(u64 x) { return (x == 0 ? -1 : 63 - __builtin_clzll(x)); }\n//\
    \ (0, 1, 2, 3, 4) -> (-1, 0, 1, 0, 2)\nint lowbit(int x) { return (x == 0 ? -1\
    \ : __builtin_ctz(x)); }\nint lowbit(u32 x) { return (x == 0 ? -1 : __builtin_ctz(x));\
    \ }\nint lowbit(ll x) { return (x == 0 ? -1 : __builtin_ctzll(x)); }\nint lowbit(u64\
    \ x) { return (x == 0 ? -1 : __builtin_ctzll(x)); }\n\ntemplate <typename T>\n\
    T kth_bit(int k) {\n  return T(1) << k;\n}\ntemplate <typename T>\nbool has_kth_bit(T\
    \ x, int k) {\n  return x >> k & 1;\n}\n\ntemplate <typename UINT>\nstruct all_bit\
    \ {\n  UINT s;\n  all_bit(UINT s) : s(s) {}\n  struct iter {\n    UINT s;\n  \
    \  int operator*() const { return lowbit(s); }\n    void operator++() { s &= s\
    \ - 1; }\n    bool operator!=(nullptr_t) const { return s; }\n  };\n  iter begin()\
    \ const { return {s}; }\n  nullptr_t end() const { return nullptr; }\n};\n\ntemplate\
    \ <typename UINT>\nstruct all_subset {\n  UINT s;\n  all_subset(UINT s) : s(s)\
    \ {}\n  struct iter {\n    UINT s, t;\n    bool done = false;\n    UINT operator*()\
    \ const { return t; }\n    void operator++() {\n      done = (t == 0);\n     \
    \ t = (t - 1) & s;\n    }\n    bool operator!=(nullptr_t) const { return !done;\
    \ }\n  };\n  iter begin() const { return {s, s}; }\n  nullptr_t end() const {\
    \ return nullptr; }\n};\n\nconstexpr u64 full_mask(int n) { return n == 64 ? -1ULL\
    \ : (1ULL << n) - 1; }\n#line 1 \"mod/mongomery_modint.hpp\"\n\n// odd mod.\n\
    // x \u306E\u4EE3\u308F\u308A\u306B rx \u3092\u6301\u3064\ntemplate <int id, typename\
    \ U1, typename U2>\nstruct Mongomery_modint {\n  using mint = Mongomery_modint;\n\
    \  inline static U1 m, r, n2;\n  static constexpr int W = numeric_limits<U1>::digits;\n\
    \n  static void set_mod(U1 mod) {\n    assert(mod & 1 && mod <= U1(1) << (W -\
    \ 2));\n    m = mod, n2 = -U2(m) % m, r = m;\n    FOR(5) r *= 2 - m * r;\n   \
    \ r = -r;\n    assert(r * m == U1(-1));\n  }\n  static U1 reduce(U2 b) { return\
    \ (b + U2(U1(b) * r) * m) >> W; }\n\n  U1 x;\n  Mongomery_modint() : x(0) {}\n\
    \  Mongomery_modint(U1 x) : x(reduce(U2(x) * n2)){};\n  U1 val() const {\n   \
    \ U1 y = reduce(x);\n    return y >= m ? y - m : y;\n  }\n  mint &operator+=(mint\
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
    \ = Mongomery_modint<id, u64, u128>;\n#line 3 \"nt/primetest.hpp\"\n\nbool primetest(const\
    \ u64 x) {\n  assert(x < u64(1) << 62);\n  if (x == 2 or x == 3 or x == 5 or x\
    \ == 7) return true;\n  if (x % 2 == 0 or x % 3 == 0 or x % 5 == 0 or x % 7 ==\
    \ 0) return false;\n  if (x < 121) return x > 1;\n  const u64 d = (x - 1) >> lowbit(x\
    \ - 1);\n\n  using mint = Mongomery_modint_64<202311020>;\n\n  mint::set_mod(x);\n\
    \  const mint one(u64(1)), minus_one(x - 1);\n  auto ok = [&](u64 a) -> bool {\n\
    \    auto y = mint(a).pow(d);\n    u64 t = d;\n    while (y != one && y != minus_one\
    \ && t != x - 1) y *= y, t <<= 1;\n    if (y != minus_one && t % 2 == 0) return\
    \ false;\n    return true;\n  };\n  if (x < (u64(1) << 32)) {\n    for (u64 a\
    \ : {2, 7, 61})\n      if (!ok(a)) return false;\n  } else {\n    for (u64 a :\
    \ {2, 325, 9375, 28178, 450775, 9780504, 1795265022}) {\n      if (!ok(a)) return\
    \ false;\n    }\n  }\n  return true;\n}\n#line 4 \"nt/factor.hpp\"\n\ntemplate\
    \ <typename mint>\nll rho(ll n, ll c) {\n  assert(n > 1);\n  const mint cc(c);\n\
    \  auto f = [&](mint x) { return x * x + cc; };\n  mint x = 1, y = 2, z = 1, q\
    \ = 1;\n  ll g = 1;\n  const ll m = 1LL << (__lg(n) / 5);\n  for (ll r = 1; g\
    \ == 1; r <<= 1) {\n    x = y;\n    FOR(r) y = f(y);\n    for (ll k = 0; k < r\
    \ && g == 1; k += m) {\n      z = y;\n      FOR(min(m, r - k)) y = f(y), q *=\
    \ x - y;\n      g = gcd(q.val(), n);\n    }\n  }\n  if (g == n) do {\n      z\
    \ = f(z);\n      g = gcd((x - z).val(), n);\n    } while (g == 1);\n  return g;\n\
    }\n\nll find_prime_factor(ll n) {\n  assert(n > 1);\n  if (primetest(n)) return\
    \ n;\n  FOR(100) {\n    ll m = 0;\n    if (n < (1 << 30)) {\n      using mint\
    \ = Mongomery_modint_32<20231025>;\n      mint::set_mod(n);\n      m = rho<mint>(n,\
    \ RNG(0, n));\n    } else {\n      using mint = Mongomery_modint_64<20231025>;\n\
    \      mint::set_mod(n);\n      m = rho<mint>(n, RNG(0, n));\n    }\n    if (primetest(m))\
    \ return m;\n    n = m;\n  }\n  assert(0);\n  return -1;\n}\n\n// \u30BD\u30FC\
    \u30C8\u3057\u3066\u304F\u308C\u308B\nvc<pair<ll, int>> factor(ll n) {\n  assert(n\
    \ >= 1);\n  vc<pair<ll, int>> pf;\n  FOR(p, 2, 100) {\n    if (p * p > n) break;\n\
    \    if (n % p == 0) {\n      ll e = 0;\n      do { n /= p, e += 1; } while (n\
    \ % p == 0);\n      pf.eb(p, e);\n    }\n  }\n  while (n > 1) {\n    ll p = find_prime_factor(n);\n\
    \    ll e = 0;\n    do { n /= p, e += 1; } while (n % p == 0);\n    pf.eb(p, e);\n\
    \  }\n  sort(all(pf));\n  return pf;\n}\n\nvc<pair<ll, int>> factor_by_lpf(ll\
    \ n, vc<int>& lpf) {\n  vc<pair<ll, int>> res;\n  while (n > 1) {\n    int p =\
    \ lpf[n];\n    int e = 0;\n    while (n % p == 0) {\n      n /= p;\n      ++e;\n\
    \    }\n    res.eb(p, e);\n  }\n  return res;\n}\n#line 1 \"nt/prime_table.hpp\"\
    \n\ntemplate <typename T = int>\nvc<T> prime_table(int LIM) {\n  ++LIM;\n  const\
    \ int S = 32768;\n  static int done = 2;\n  static vc<T> primes = {2}, sieve(S\
    \ + 1);\n\n  if (done < LIM) {\n    done = LIM;\n\n    primes = {2}, sieve.assign(S\
    \ + 1, 0);\n    const int R = LIM / 2;\n    primes.reserve(int(LIM / log(LIM)\
    \ * 1.1));\n    vc<pair<int, int>> cp;\n    for (int i = 3; i <= S; i += 2) {\n\
    \      if (!sieve[i]) {\n        cp.eb(i, i * i / 2);\n        for (int j = i\
    \ * i; j <= S; j += 2 * i) sieve[j] = 1;\n      }\n    }\n    for (int L = 1;\
    \ L <= R; L += S) {\n      array<bool, S> block{};\n      for (auto& [p, idx]\
    \ : cp)\n        for (int i = idx; i < S + L; idx = (i += p)) block[i - L] = 1;\n\
    \      FOR(i, min(S, R - L)) if (!block[i]) primes.eb((L + i) * 2 + 1);\n    }\n\
    \  }\n  int k = LB(primes, LIM + 1);\n  return {primes.begin(), primes.begin()\
    \ + k};\n}\n#line 2 \"nt/lpf_table.hpp\"\n\n// [0, LIM], 0, 1 \u306B\u306F -1\
    \ \u304C\u5165\u308B\u3002\nvc<int> lpf_table(ll LIM) {\n  auto primes = prime_table(LIM);\n\
    \  vc<int> res(LIM + 1, -1);\n  FOR_R(i, len(primes)) {\n    auto p = primes[i];\n\
    \    FOR3(j, 1, LIM / p + 1) res[p * j] = p;\n  }\n  return res;\n}\n#line 3 \"\
    nt/all_lcm.hpp\"\n\ntemplate <typename mint>\nmint all_lcm(vc<int> A, bool use_lpf)\
    \ {\n  if (A.empty()) return 1;\n  map<int, int> MP;\n  int mx = MAX(A);\n  vc<int>\
    \ lpf;\n  if (use_lpf) lpf = lpf_table(mx);\n  for (auto&& n: A) {\n    auto pfs\
    \ = (use_lpf ? factor_by_lpf(n, lpf) : factor(n));\n    for (auto&& [p, e]: pfs)\
    \ chmax(MP[p], e);\n  }\n  mint x = 1;\n  for (auto&& [p, e]: MP) { x *= mint(p).pow(e);\
    \ }\n  return x;\n}\n"
  code: "#include \"nt/factor.hpp\"\n#include \"nt/lpf_table.hpp\"\n\ntemplate <typename\
    \ mint>\nmint all_lcm(vc<int> A, bool use_lpf) {\n  if (A.empty()) return 1;\n\
    \  map<int, int> MP;\n  int mx = MAX(A);\n  vc<int> lpf;\n  if (use_lpf) lpf =\
    \ lpf_table(mx);\n  for (auto&& n: A) {\n    auto pfs = (use_lpf ? factor_by_lpf(n,\
    \ lpf) : factor(n));\n    for (auto&& [p, e]: pfs) chmax(MP[p], e);\n  }\n  mint\
    \ x = 1;\n  for (auto&& [p, e]: MP) { x *= mint(p).pow(e); }\n  return x;\n}\n"
  dependsOn:
  - nt/factor.hpp
  - random/base.hpp
  - nt/primetest.hpp
  - other/bit.hpp
  - mod/mongomery_modint.hpp
  - nt/lpf_table.hpp
  - nt/prime_table.hpp
  isVerificationFile: false
  path: nt/all_lcm.hpp
  requiredBy: []
  timestamp: '2026-08-16 04:03:00+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: nt/all_lcm.hpp
layout: document
redirect_from:
- /library/nt/all_lcm.hpp
- /library/nt/all_lcm.hpp.html
title: nt/all_lcm.hpp
---
