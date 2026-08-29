---
data:
  _extendedDependsOn:
  - icon: ':question:'
    path: ds/hashmap.hpp
    title: ds/hashmap.hpp
  - icon: ':heavy_check_mark:'
    path: mod/barrett.hpp
    title: mod/barrett.hpp
  - icon: ':heavy_check_mark:'
    path: mod/mod_pow.hpp
    title: mod/mod_pow.hpp
  - icon: ':heavy_check_mark:'
    path: mod/montgomery_modint.hpp
    title: mod/montgomery_modint.hpp
  - icon: ':heavy_check_mark:'
    path: mod/primitive_root.hpp
    title: mod/primitive_root.hpp
  - icon: ':heavy_check_mark:'
    path: nt/factor.hpp
    title: nt/factor.hpp
  - icon: ':heavy_check_mark:'
    path: nt/is_prime.hpp
    title: nt/is_prime.hpp
  - icon: ':heavy_check_mark:'
    path: nt/lpf_table.hpp
    title: nt/lpf_table.hpp
  - icon: ':question:'
    path: nt/prime_table.hpp
    title: nt/prime_table.hpp
  - icon: ':question:'
    path: other/bit.hpp
    title: other/bit.hpp
  - icon: ':question:'
    path: random/base.hpp
    title: random/base.hpp
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/1_mytest/modfast.test.cpp
    title: test/1_mytest/modfast.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 1 \"mod/primitive_root.hpp\"\n\n#line 1 \"nt/factor.hpp\"\n\n\
    #line 1 \"random/base.hpp\"\n\nu64 RNG_64() {\n  static u64 x_ = u64(chrono::duration_cast<chrono::nanoseconds>(chrono::high_resolution_clock::now().time_since_epoch()).count())\
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
    T kth_bit(int k) {\n  assert(0 <= k && k < int(8 * sizeof(T)));\n  return T(1)\
    \ << k;\n}\ntemplate <typename T>\nbool has_kth_bit(T x, int k) {\n  assert(0\
    \ <= k && k < int(8 * sizeof(T)));\n  return x >> k & 1;\n}\n\ntemplate <typename\
    \ UINT>\nstruct all_bit {\n  static_assert(is_unsigned<UINT>::value);\n  UINT\
    \ s;\n  all_bit(UINT s) : s(s) {}\n  struct iter {\n    UINT s;\n    int operator*()\
    \ const { return lowbit(s); }\n    void operator++() { s &= s - 1; }\n    bool\
    \ operator!=(nullptr_t) const { return s; }\n  };\n  iter begin() const { return\
    \ {s}; }\n  nullptr_t end() const { return nullptr; }\n};\n\ntemplate <typename\
    \ UINT>\nstruct all_subset {\n  static_assert(is_unsigned<UINT>::value);\n  UINT\
    \ s;\n  all_subset(UINT s) : s(s) {}\n  struct iter {\n    UINT s, t;\n    bool\
    \ done = false;\n    UINT operator*() const { return t; }\n    void operator++()\
    \ {\n      done = (t == 0);\n      t = (t - 1) & s;\n    }\n    bool operator!=(nullptr_t)\
    \ const { return !done; }\n  };\n  iter begin() const { return {s, s}; }\n  nullptr_t\
    \ end() const { return nullptr; }\n};\n\nconstexpr u64 full_mask(int n) {\n  assert(0\
    \ <= n && n <= 64);\n  return n == 64 ? -1ULL : (1ULL << n) - 1;\n}\n\nu64 bit_reverse(u64\
    \ x) {\n  x = ((x & 0x5555555555555555ULL) << 1) | ((x >> 1) & 0x5555555555555555ULL);\n\
    \  x = ((x & 0x3333333333333333ULL) << 2) | ((x >> 2) & 0x3333333333333333ULL);\n\
    \  x = ((x & 0x0f0f0f0f0f0f0f0fULL) << 4) | ((x >> 4) & 0x0f0f0f0f0f0f0f0fULL);\n\
    \  x = ((x & 0x00ff00ff00ff00ffULL) << 8) | ((x >> 8) & 0x00ff00ff00ff00ffULL);\n\
    \  x = ((x & 0x0000ffff0000ffffULL) << 16) | ((x >> 16) & 0x0000ffff0000ffffULL);\n\
    \  x = (x << 32) | (x >> 32);\n  return x;\n}\n#line 1 \"mod/montgomery_modint.hpp\"\
    \n\n// odd mod.\n// x \u306E\u4EE3\u308F\u308A\u306B rx \u3092\u6301\u3064\ntemplate\
    \ <int id, typename U1, typename U2>\nstruct Montgomery_modint {\n  using mint\
    \ = Montgomery_modint;\n  inline static U1 m, r, n2;\n  static constexpr int W\
    \ = numeric_limits<U1>::digits;\n\n  static void set_mod(U1 mod) {\n    assert(mod\
    \ & 1 && mod <= U1(1) << (W - 2));\n    m = mod, n2 = -U2(m) % m, r = m;\n   \
    \ FOR(6) r *= 2 - m * r;\n    r = -r;\n    assert(r * m == U1(-1));\n  }\n  static\
    \ U1 reduce(U2 b) { return (b + U2(U1(b) * r) * m) >> W; }\n\n  U1 x;\n  Montgomery_modint()\
    \ : x(0) {}\n  Montgomery_modint(U1 x) : x(reduce(U2(x) * n2)){};\n  U1 val()\
    \ const {\n    U1 y = reduce(x);\n    return y >= m ? y - m : y;\n  }\n  mint\
    \ &operator+=(mint y) {\n    x = ((x += y.x) >= m ? x - m : x);\n    return *this;\n\
    \  }\n  mint &operator-=(mint y) {\n    x -= (x >= y.x ? y.x : y.x - m);\n   \
    \ return *this;\n  }\n  mint &operator*=(mint y) {\n    x = reduce(U2(x) * y.x);\n\
    \    return *this;\n  }\n  mint operator+(mint y) const { return mint(*this) +=\
    \ y; }\n  mint operator-(mint y) const { return mint(*this) -= y; }\n  mint operator*(mint\
    \ y) const { return mint(*this) *= y; }\n  bool operator==(mint y) const {\n \
    \   return (x >= m ? x - m : x) == (y.x >= m ? y.x - m : y.x);\n  }\n  bool operator!=(mint\
    \ y) const { return not operator==(y); }\n  mint pow(ll n) const {\n    assert(n\
    \ >= 0);\n    mint y = 1, z = *this;\n    for (; n; n >>= 1, z *= z)\n      if\
    \ (n & 1) y *= z;\n    return y;\n  }\n};\n\ntemplate <int id>\nusing Montgomery_modint_32\
    \ = Montgomery_modint<id, u32, u64>;\ntemplate <int id>\nusing Montgomery_modint_64\
    \ = Montgomery_modint<id, u64, u128>;\n#line 3 \"nt/is_prime.hpp\"\n\nbool is_prime(const\
    \ u64 x) {\n  assert(x < u64(1) << 62);\n  if (x == 2 or x == 3 or x == 5 or x\
    \ == 7) return true;\n  if (x % 2 == 0 or x % 3 == 0 or x % 5 == 0 or x % 7 ==\
    \ 0) return false;\n  if (x < 121) return x > 1;\n  const u64 d = (x - 1) >> lowbit(x\
    \ - 1);\n\n  using mint = Montgomery_modint_64<202311020>;\n\n  mint::set_mod(x);\n\
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
    }\n\nll find_prime_factor(ll n) {\n  assert(n > 1);\n  if (is_prime(n)) return\
    \ n;\n  FOR(100) {\n    ll m = 0;\n    if (n < (1 << 30)) {\n      using mint\
    \ = Montgomery_modint_32<20231025>;\n      mint::set_mod(n);\n      m = rho<mint>(n,\
    \ RNG(0, n));\n    } else {\n      using mint = Montgomery_modint_64<20231025>;\n\
    \      mint::set_mod(n);\n      m = rho<mint>(n, RNG(0, n));\n    }\n    if (is_prime(m))\
    \ return m;\n    n = m;\n  }\n  assert(0);\n  return -1;\n}\n\n// \u30BD\u30FC\
    \u30C8\u3057\u3066\u304F\u308C\u308B\nvc<pair<ll, int>> factor(ll n) {\n  assert(n\
    \ >= 1);\n  vc<pair<ll, int>> pf;\n  FOR(p, 2, 100) {\n    if (p * p > n) break;\n\
    \    if (n % p == 0) {\n      ll e = 0;\n      do {\n        n /= p, e += 1;\n\
    \      } while (n % p == 0);\n      pf.eb(p, e);\n    }\n  }\n  while (n > 1)\
    \ {\n    ll p = find_prime_factor(n);\n    ll e = 0;\n    do {\n      n /= p,\
    \ e += 1;\n    } while (n % p == 0);\n    pf.eb(p, e);\n  }\n  sort(all(pf));\n\
    \  return pf;\n}\n\nvc<pair<ll, int>> factor_by_lpf(ll n, vc<int>& lpf) {\n  vc<pair<ll,\
    \ int>> res;\n  while (n > 1) {\n    int p = lpf[n];\n    int e = 0;\n    while\
    \ (n % p == 0) {\n      n /= p;\n      ++e;\n    }\n    res.eb(p, e);\n  }\n \
    \ return res;\n}\n#line 1 \"mod/mod_pow.hpp\"\n\n#line 1 \"mod/montgomery_modint.hpp\"\
    \n\n// odd mod.\n// x \u306E\u4EE3\u308F\u308A\u306B rx \u3092\u6301\u3064\ntemplate\
    \ <int id, typename U1, typename U2>\nstruct Montgomery_modint {\n  using mint\
    \ = Montgomery_modint;\n  inline static U1 m, r, n2;\n  static constexpr int W\
    \ = numeric_limits<U1>::digits;\n\n  static void set_mod(U1 mod) {\n    assert(mod\
    \ & 1 && mod <= U1(1) << (W - 2));\n    m = mod, n2 = -U2(m) % m, r = m;\n   \
    \ FOR(6) r *= 2 - m * r;\n    r = -r;\n    assert(r * m == U1(-1));\n  }\n  static\
    \ U1 reduce(U2 b) { return (b + U2(U1(b) * r) * m) >> W; }\n\n  U1 x;\n  Montgomery_modint()\
    \ : x(0) {}\n  Montgomery_modint(U1 x) : x(reduce(U2(x) * n2)){};\n  U1 val()\
    \ const {\n    U1 y = reduce(x);\n    return y >= m ? y - m : y;\n  }\n  mint\
    \ &operator+=(mint y) {\n    x = ((x += y.x) >= m ? x - m : x);\n    return *this;\n\
    \  }\n  mint &operator-=(mint y) {\n    x -= (x >= y.x ? y.x : y.x - m);\n   \
    \ return *this;\n  }\n  mint &operator*=(mint y) {\n    x = reduce(U2(x) * y.x);\n\
    \    return *this;\n  }\n  mint operator+(mint y) const { return mint(*this) +=\
    \ y; }\n  mint operator-(mint y) const { return mint(*this) -= y; }\n  mint operator*(mint\
    \ y) const { return mint(*this) *= y; }\n  bool operator==(mint y) const {\n \
    \   return (x >= m ? x - m : x) == (y.x >= m ? y.x - m : y.x);\n  }\n  bool operator!=(mint\
    \ y) const { return not operator==(y); }\n  mint pow(ll n) const {\n    assert(n\
    \ >= 0);\n    mint y = 1, z = *this;\n    for (; n; n >>= 1, z *= z)\n      if\
    \ (n & 1) y *= z;\n    return y;\n  }\n};\n\ntemplate <int id>\nusing Montgomery_modint_32\
    \ = Montgomery_modint<id, u32, u64>;\ntemplate <int id>\nusing Montgomery_modint_64\
    \ = Montgomery_modint<id, u64, u128>;\n#line 1 \"mod/barrett.hpp\"\n\n// https://github.com/atcoder/ac-library/blob/master/atcoder/internal_math.hpp\n\
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
    \  }\n\n  u64 mul(u64 a, u64 b) { return modulo(u128(a) * b); }\n};\n#line 4 \"\
    mod/mod_pow.hpp\"\n\nu32 mod_pow(int a, ll n, int mod) {\n  assert(n >= 0);\n\
    \  if (mod == 1) return 0;\n  a = ((a %= mod) < 0 ? a + mod : a);\n  if ((mod\
    \ & 1) && (mod < (1 << 30))) {\n    using mint = Montgomery_modint_32<202311021>;\n\
    \    mint::set_mod(mod);\n    return mint(a).pow(n).val();\n  }\n  Barrett bt(mod);\n\
    \  int r = 1;\n  while (n) {\n    if (n & 1) r = bt.mul(r, a);\n    a = bt.mul(a,\
    \ a), n >>= 1;\n  }\n  return r;\n}\n\nu64 mod_pow_64(ll a, ll n, u64 mod) {\n\
    \  assert(n >= 0);\n  if (mod == 1) return 0;\n  a = ((a %= mod) < 0 ? a + mod\
    \ : a);\n  if ((mod & 1) && (mod < (u64(1) << 62))) {\n    using mint = Montgomery_modint_64<202311021>;\n\
    \    mint::set_mod(mod);\n    return mint(a).pow(n).val();\n  }\n  Barrett_64\
    \ bt(mod);\n  ll r = 1;\n  while (n) {\n    if (n & 1) r = bt.mul(r, a);\n   \
    \ a = bt.mul(a, a), n >>= 1;\n  }\n  return r;\n}\n#line 1 \"random/base.hpp\"\
    \n\nu64 RNG_64() {\n  static u64 x_ = u64(chrono::duration_cast<chrono::nanoseconds>(chrono::high_resolution_clock::now().time_since_epoch()).count())\
    \ * 10150724397891781847ULL;\n  x_ ^= x_ << 7;\n  return x_ ^= x_ >> 9;\n}\n\n\
    u64 RNG(u64 lim) { return RNG_64() % lim; }\n\nll RNG(ll l, ll r) { return l +\
    \ RNG_64() % (r - l); }\n#line 5 \"mod/primitive_root.hpp\"\n\n// int\nint primitive_root(int\
    \ p, bool min = true) {\n  auto pf = factor(p - 1);\n  auto is_ok = [&](int g)\
    \ -> bool {\n    for (auto&& [q, e] : pf)\n      if (mod_pow(g, (p - 1) / q, p)\
    \ == 1) return false;\n    return true;\n  };\n  if (min) {\n    FOR(x, 1, p)\
    \ if (is_ok(x)) return x;\n  }\n  while (1) {\n    int x = RNG(1, p);\n    if\
    \ (is_ok(x)) return x;\n  }\n  return -1;\n}\n\nll primitive_root_64(ll p) {\n\
    \  auto pf = factor(p - 1);\n  auto is_ok = [&](ll g) -> bool {\n    for (auto&&\
    \ [q, e] : pf)\n      if (mod_pow_64(g, (p - 1) / q, p) == 1) return false;\n\
    \    return true;\n  };\n  while (1) {\n    ll x = RNG(1, p);\n    if (is_ok(x))\
    \ return x;\n  }\n  return -1;\n}\n\n// https://codeforces.com/contest/1190/problem/F\n\
    ll primitive_root_prime_power_64(ll p, ll e) {\n  assert(p >= 3);\n  ll g = primitive_root_64(p);\n\
    \  ll q = p;\n  ll phi = p - 1;\n  FOR(e - 1) {\n    q *= p;\n    phi *= p;\n\
    \    if (mod_pow_64(g, phi / p, q) == 1) g += q / p;\n  }\n  return g;\n}\n#line\
    \ 1 \"nt/prime_table.hpp\"\n\ntemplate <typename T = int>\nvc<T> prime_table(int\
    \ LIM) {\n  ++LIM;\n  const int S = 32768;\n  static int done = 2;\n  static vc<T>\
    \ primes = {2}, sieve(S + 1);\n\n  if (done < LIM) {\n    done = LIM;\n\n    primes\
    \ = {2}, sieve.assign(S + 1, 0);\n    const int R = LIM / 2;\n    primes.reserve(int(LIM\
    \ / log(LIM) * 1.1));\n    vc<pair<int, int>> cp;\n    for (int i = 3; i <= S;\
    \ i += 2) {\n      if (!sieve[i]) {\n        cp.eb(i, i * i / 2);\n        for\
    \ (int j = i * i; j <= S; j += 2 * i) sieve[j] = 1;\n      }\n    }\n    for (int\
    \ L = 1; L <= R; L += S) {\n      array<bool, S> block{};\n      for (auto& [p,\
    \ idx] : cp)\n        for (int i = idx; i < S + L; idx = (i += p)) block[i - L]\
    \ = 1;\n      FOR(i, min(S, R - L)) if (!block[i]) primes.eb((L + i) * 2 + 1);\n\
    \    }\n  }\n  int k = LB(primes, LIM + 1);\n  return {primes.begin(), primes.begin()\
    \ + k};\n}\n#line 2 \"nt/lpf_table.hpp\"\n\n// [0, LIM], 0, 1 \u306B\u306F -1\
    \ \u304C\u5165\u308B\u3002\nvc<int> lpf_table(ll LIM) {\n  auto primes = prime_table(LIM);\n\
    \  vc<int> res(LIM + 1, -1);\n  FOR_R(i, len(primes)) {\n    auto p = primes[i];\n\
    \    FOR3(j, 1, LIM / p + 1) res[p * j] = p;\n  }\n  return res;\n}\n#line 1 \"\
    ds/hashmap.hpp\"\n\n// u64 -> Val\ntemplate <typename Val>\nstruct HashMap {\n\
    \  // n \u306F\u5165\u308C\u305F\u3044\u3082\u306E\u306E\u500B\u6570\u3067 ok\n\
    \  HashMap(u32 n = 0) { build(n); }\n  void build(u32 n) {\n    u32 k = 8;\n \
    \   while (k < n * 2) k *= 2;\n    cap = k / 2, mask = k - 1;\n    key.resize(k),\
    \ val.resize(k), used.assign(k, 0);\n  }\n\n  // size \u3092\u4FDD\u3063\u305F\
    \u307E\u307E. size=0 \u306B\u3059\u308B\u3068\u304D\u306F build \u3059\u308B\u3053\
    \u3068.\n  void clear() {\n    used.assign(len(used), 0);\n    cap = (mask + 1)\
    \ / 2;\n  }\n  int size() { return len(used) / 2 - cap; }\n\n  int index(const\
    \ u64& k) {\n    int i = 0;\n    for (i = hash(k); used[i] && key[i] != k; i =\
    \ (i + 1) & mask) {}\n    return i;\n  }\n\n  Val& operator[](const u64& k) {\n\
    \    if (cap == 0) extend();\n    int i = index(k);\n    if (!used[i]) { used[i]\
    \ = 1, key[i] = k, val[i] = Val{}, --cap; }\n    return val[i];\n  }\n\n  Val\
    \ get(const u64& k, Val default_value) {\n    int i = index(k);\n    return (used[i]\
    \ ? val[i] : default_value);\n  }\n\n  bool count(const u64& k) {\n    int i =\
    \ index(k);\n    return used[i] && key[i] == k;\n  }\n\n  // f(key, val)\n  template\
    \ <typename F>\n  void enumerate_all(F f) {\n    FOR(i, len(used)) if (used[i])\
    \ f(key[i], val[i]);\n  }\n\nprivate:\n  u32 cap, mask;\n  vc<u64> key;\n  vc<Val>\
    \ val;\n  vc<bool> used;\n\n  u64 hash(u64 x) {\n    static const u64 FIXED_RANDOM\
    \ = std::chrono::steady_clock::now().time_since_epoch().count();\n    x += FIXED_RANDOM;\n\
    \    x = (x ^ (x >> 30)) * 0xbf58476d1ce4e5b9;\n    x = (x ^ (x >> 27)) * 0x94d049bb133111eb;\n\
    \    return (x ^ (x >> 31)) & mask;\n  }\n\n  void extend() {\n    vc<pair<u64,\
    \ Val>> dat;\n    dat.reserve(len(used) / 2 - cap);\n    FOR(i, len(used)) {\n\
    \      if (used[i]) dat.eb(key[i], val[i]);\n    }\n    build(2 * len(dat));\n\
    \    for (auto& [a, b]: dat) (*this)[a] = b;\n  }\n};\n#line 4 \"mod/modfast.hpp\"\
    \n\ntemplate <int p>\nstruct ModFast {\n  static_assert(p < (1 << 30));\n\n  u32\
    \ root;\n  array<u32, 65537> POW[2];\n  array<pair<u16, u16>, 1 + (1 << 20)> FRAC;\n\
    \n  static constexpr int K = 1 << 21;\n  array<u32, 2 * K + 1> LOG;\n  array<u32,\
    \ 2 * K + 1> INV;\n\n  ModFast() {\n    root = (p == 998244353 ? 3 : primitive_root(p));\n\
    \    build_pow();\n    build_inv();\n    build_log();\n    build_frac();\n  }\n\
    \n  void build_inv() {\n    INV[K + 1] = 1;\n    for (u32 i = 2; i <= K; ++i)\
    \ {\n      u64 q = (p + i - 1) / i;\n      INV[K + i] = INV[K + i * q - p] * u64(q)\
    \ % p;\n    }\n    FOR(i, 1, K + 1) INV[K - i] = p - INV[K + i];\n  }\n\n  u32\
    \ pow(u32 a, ll exp) {\n    assert(0 <= a && a < p && 0 <= exp && exp < (1 <<\
    \ 30));\n    if (a == 0) return (exp == 0 ? 1 : 0);\n    return pow_r_32(log_r(a)\
    \ * exp % (p - 1));\n  }\n\n  u32 pow_r_32(u32 exp) {\n    assert(0 <= exp &&\
    \ exp <= p - 1);\n    return u64(POW[0][exp & 32767]) * POW[1][exp >> 15] % p;\n\
    \  }\n  u32 pow_r(ll exp) {\n    exp %= p - 1;\n    if (exp < 0) exp += p - 1;\n\
    \    return u64(POW[0][exp & 32767]) * POW[1][exp >> 15] % p;\n  }\n\n  // [0,\
    \ 2p-2)\n  u32 log_r(u32 x) {\n    assert(1 <= x && x < p);\n    auto [a, b] =\
    \ FRAC[x >> 10];\n    u32 t = x * b - a * p;\n    return LOG[K + t] + (p - 1)\
    \ - LOG[K + b];\n  }\n\n  u32 inverse(u32 x) {\n    assert(1 <= x && x < p);\n\
    \    auto [a, b] = FRAC[x >> 10];\n    u32 t = x * b - a * p;\n    return INV[K\
    \ + t] * u64(b) % p;\n  }\n\n  template <typename T>\n  vc<T> get_log_table(int\
    \ n) {\n    assert(n <= K);\n    return {LOG.begin() + K, LOG.begin() + K + n\
    \ + 1};\n  }\n\n private:\n  void build_pow() {\n    POW[0][0] = POW[1][0] = 1;\n\
    \    FOR(i, (1 << 15)) POW[0][i + 1] = POW[0][i] * u64(root) % p;\n    FOR(i,\
    \ (1 << 15)) POW[1][i + 1] = POW[1][i] * u64(POW[0][1 << 15]) % p;\n  }\n\n  //\
    \ 0.085 sec.\n  void build_log() {\n    const int LIM = 1 << 21;\n    auto lpf\
    \ = lpf_table(LIM);\n\n    const int S = 1 << 17;\n    HashMap<u32> MP(S);\n \
    \   u32 pw = 1;\n    for (int k = 0; k < S; ++k, pw = u64(root) * pw % p) {\n\
    \      MP[pw] = k;\n    }\n    u32 q = pow_r_32(p - 1 - S);\n    auto BSGS = [&](u32\
    \ s) -> u32 {\n      u32 ans = 0;\n      while (1) {\n        u32 v = MP.get(s,\
    \ -1);\n        if (v != u32(-1)) {\n          return ans + v;\n        }\n  \
    \      ans += S, s = u64(s) * q % p;\n      }\n      return 0;\n    };\n\n   \
    \ LOG[K + 1] = 0;\n    FOR(i, 2, 1 + (1 << 21)) {\n      if (lpf[i] < i) {\n \
    \       LOG[K + i] = (LOG[K + lpf[i]] + LOG[K + i / lpf[i]]) % (p - 1);\n    \
    \    continue;\n      }\n      if (i < 100) {\n        LOG[K + i] = BSGS(i);\n\
    \        continue;\n      }\n      if (i * i > p) {\n        auto [j, k] = divmod<int>(p,\
    \ i);\n        // i = (-k)/j\n        LOG[K + i] =\n            (LOG[K + k] +\
    \ (p - 1) / 2 + (p - 1) - LOG[K + j]) % (p - 1);\n        continue;\n      }\n\
    \      while (1) {\n        u32 k = RNG(0, p - 1);\n        u64 ans = p - 1 -\
    \ k;\n        u32 x = u64(i) * pow_r_32(k) % p;\n        auto div = [&](u32 q)\
    \ -> void { x /= q, ans += LOG[K + q]; };\n        for (u32 q : {2, 3, 5, 7, 11,\
    \ 13, 17, 19}) {\n          while (x % q == 0) div(q);\n        }\n        if\
    \ (x >= LIM) continue;\n        while (i < x && x < LIM && lpf[x] < i) div(lpf[x]);\n\
    \        if (1 < x && x < i) div(x);\n        if (x == 1) {\n          LOG[K +\
    \ i] = ans % (p - 1);\n          break;\n        }\n      }\n    }\n    FOR(i,\
    \ 1, 1 + (1 << 21)) {\n      LOG[K - i] = (LOG[K + i] + (p - 1) / 2) % (p - 1);\n\
    \    }\n  }\n\n  void build_frac() {\n    vc<tuple<u16, u16, u16, u16>> que;\n\
    \    que.eb(0, 1, 1, 1);\n    while (len(que)) {\n      auto [a, b, c, d] = POP(que);\n\
    \      if (b + d < 2048) {\n        que.eb(a + c, b + d, c, d), que.eb(a, b, a\
    \ + c, b + d);\n        continue;\n      }\n      u32 s = (u64(a) * p) / (1024\
    \ * b);\n      u32 t = (u64(c) * p) / (1024 * d);\n      FRAC[s] = {a, b}, FRAC[t]\
    \ = {c, d};\n      a = min(a, c), b = min(b, d);\n      FOR(i, s + 1, t) FRAC[i]\
    \ = {a, b};\n    }\n  }\n};\n"
  code: "#include \"mod/primitive_root.hpp\"\n#include \"nt/lpf_table.hpp\"\n#include\
    \ \"ds/hashmap.hpp\"\n\ntemplate <int p>\nstruct ModFast {\n  static_assert(p\
    \ < (1 << 30));\n\n  u32 root;\n  array<u32, 65537> POW[2];\n  array<pair<u16,\
    \ u16>, 1 + (1 << 20)> FRAC;\n\n  static constexpr int K = 1 << 21;\n  array<u32,\
    \ 2 * K + 1> LOG;\n  array<u32, 2 * K + 1> INV;\n\n  ModFast() {\n    root = (p\
    \ == 998244353 ? 3 : primitive_root(p));\n    build_pow();\n    build_inv();\n\
    \    build_log();\n    build_frac();\n  }\n\n  void build_inv() {\n    INV[K +\
    \ 1] = 1;\n    for (u32 i = 2; i <= K; ++i) {\n      u64 q = (p + i - 1) / i;\n\
    \      INV[K + i] = INV[K + i * q - p] * u64(q) % p;\n    }\n    FOR(i, 1, K +\
    \ 1) INV[K - i] = p - INV[K + i];\n  }\n\n  u32 pow(u32 a, ll exp) {\n    assert(0\
    \ <= a && a < p && 0 <= exp && exp < (1 << 30));\n    if (a == 0) return (exp\
    \ == 0 ? 1 : 0);\n    return pow_r_32(log_r(a) * exp % (p - 1));\n  }\n\n  u32\
    \ pow_r_32(u32 exp) {\n    assert(0 <= exp && exp <= p - 1);\n    return u64(POW[0][exp\
    \ & 32767]) * POW[1][exp >> 15] % p;\n  }\n  u32 pow_r(ll exp) {\n    exp %= p\
    \ - 1;\n    if (exp < 0) exp += p - 1;\n    return u64(POW[0][exp & 32767]) *\
    \ POW[1][exp >> 15] % p;\n  }\n\n  // [0, 2p-2)\n  u32 log_r(u32 x) {\n    assert(1\
    \ <= x && x < p);\n    auto [a, b] = FRAC[x >> 10];\n    u32 t = x * b - a * p;\n\
    \    return LOG[K + t] + (p - 1) - LOG[K + b];\n  }\n\n  u32 inverse(u32 x) {\n\
    \    assert(1 <= x && x < p);\n    auto [a, b] = FRAC[x >> 10];\n    u32 t = x\
    \ * b - a * p;\n    return INV[K + t] * u64(b) % p;\n  }\n\n  template <typename\
    \ T>\n  vc<T> get_log_table(int n) {\n    assert(n <= K);\n    return {LOG.begin()\
    \ + K, LOG.begin() + K + n + 1};\n  }\n\n private:\n  void build_pow() {\n   \
    \ POW[0][0] = POW[1][0] = 1;\n    FOR(i, (1 << 15)) POW[0][i + 1] = POW[0][i]\
    \ * u64(root) % p;\n    FOR(i, (1 << 15)) POW[1][i + 1] = POW[1][i] * u64(POW[0][1\
    \ << 15]) % p;\n  }\n\n  // 0.085 sec.\n  void build_log() {\n    const int LIM\
    \ = 1 << 21;\n    auto lpf = lpf_table(LIM);\n\n    const int S = 1 << 17;\n \
    \   HashMap<u32> MP(S);\n    u32 pw = 1;\n    for (int k = 0; k < S; ++k, pw =\
    \ u64(root) * pw % p) {\n      MP[pw] = k;\n    }\n    u32 q = pow_r_32(p - 1\
    \ - S);\n    auto BSGS = [&](u32 s) -> u32 {\n      u32 ans = 0;\n      while\
    \ (1) {\n        u32 v = MP.get(s, -1);\n        if (v != u32(-1)) {\n       \
    \   return ans + v;\n        }\n        ans += S, s = u64(s) * q % p;\n      }\n\
    \      return 0;\n    };\n\n    LOG[K + 1] = 0;\n    FOR(i, 2, 1 + (1 << 21))\
    \ {\n      if (lpf[i] < i) {\n        LOG[K + i] = (LOG[K + lpf[i]] + LOG[K +\
    \ i / lpf[i]]) % (p - 1);\n        continue;\n      }\n      if (i < 100) {\n\
    \        LOG[K + i] = BSGS(i);\n        continue;\n      }\n      if (i * i >\
    \ p) {\n        auto [j, k] = divmod<int>(p, i);\n        // i = (-k)/j\n    \
    \    LOG[K + i] =\n            (LOG[K + k] + (p - 1) / 2 + (p - 1) - LOG[K + j])\
    \ % (p - 1);\n        continue;\n      }\n      while (1) {\n        u32 k = RNG(0,\
    \ p - 1);\n        u64 ans = p - 1 - k;\n        u32 x = u64(i) * pow_r_32(k)\
    \ % p;\n        auto div = [&](u32 q) -> void { x /= q, ans += LOG[K + q]; };\n\
    \        for (u32 q : {2, 3, 5, 7, 11, 13, 17, 19}) {\n          while (x % q\
    \ == 0) div(q);\n        }\n        if (x >= LIM) continue;\n        while (i\
    \ < x && x < LIM && lpf[x] < i) div(lpf[x]);\n        if (1 < x && x < i) div(x);\n\
    \        if (x == 1) {\n          LOG[K + i] = ans % (p - 1);\n          break;\n\
    \        }\n      }\n    }\n    FOR(i, 1, 1 + (1 << 21)) {\n      LOG[K - i] =\
    \ (LOG[K + i] + (p - 1) / 2) % (p - 1);\n    }\n  }\n\n  void build_frac() {\n\
    \    vc<tuple<u16, u16, u16, u16>> que;\n    que.eb(0, 1, 1, 1);\n    while (len(que))\
    \ {\n      auto [a, b, c, d] = POP(que);\n      if (b + d < 2048) {\n        que.eb(a\
    \ + c, b + d, c, d), que.eb(a, b, a + c, b + d);\n        continue;\n      }\n\
    \      u32 s = (u64(a) * p) / (1024 * b);\n      u32 t = (u64(c) * p) / (1024\
    \ * d);\n      FRAC[s] = {a, b}, FRAC[t] = {c, d};\n      a = min(a, c), b = min(b,\
    \ d);\n      FOR(i, s + 1, t) FRAC[i] = {a, b};\n    }\n  }\n};\n"
  dependsOn:
  - mod/primitive_root.hpp
  - nt/factor.hpp
  - random/base.hpp
  - nt/is_prime.hpp
  - other/bit.hpp
  - mod/montgomery_modint.hpp
  - mod/mod_pow.hpp
  - mod/barrett.hpp
  - nt/lpf_table.hpp
  - nt/prime_table.hpp
  - ds/hashmap.hpp
  isVerificationFile: false
  path: mod/modfast.hpp
  requiredBy: []
  timestamp: '2026-08-29 09:24:19+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/1_mytest/modfast.test.cpp
documentation_of: mod/modfast.hpp
layout: document
redirect_from:
- /library/mod/modfast.hpp
- /library/mod/modfast.hpp.html
title: mod/modfast.hpp
---
