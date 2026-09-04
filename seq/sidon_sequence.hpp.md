---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: mod/barrett.hpp
    title: mod/barrett.hpp
  - icon: ':heavy_check_mark:'
    path: mod/mod_pow.hpp
    title: mod/mod_pow.hpp
  - icon: ':heavy_check_mark:'
    path: mod/mod_sqrt.hpp
    title: mod/mod_sqrt.hpp
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
    path: other/bit.hpp
    title: other/bit.hpp
  - icon: ':heavy_check_mark:'
    path: random/base.hpp
    title: random/base.hpp
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':warning:'
  attributes:
    links: []
  bundledCode: "#line 1 \"random/base.hpp\"\n\nu64 RNG_64() {\n  static u64 x_ = u64(chrono::duration_cast<chrono::nanoseconds>(\n\
    \                      chrono::high_resolution_clock::now().time_since_epoch())\n\
    \                          .count()) *\n                  10150724397891781847ULL;\n\
    \  x_ ^= x_ << 7;\n  return x_ ^= x_ >> 9;\n}\n\nu64 RNG(u64 lim) {\n  assert(lim\
    \ > 0);\n  return RNG_64() % lim;\n}\n\nll RNG(ll l, ll r) {\n  assert(l < r);\n\
    \  return l + RNG_64() % (r - l);\n}\n#line 1 \"mod/mod_pow.hpp\"\n\n#line 1 \"\
    mod/montgomery_modint.hpp\"\n\n// odd mod.\n// x \u306E\u4EE3\u308F\u308A\u306B\
    \ rx \u3092\u6301\u3064\ntemplate <int id, typename U1, typename U2>\nstruct Montgomery_modint\
    \ {\n  using mint = Montgomery_modint;\n  inline static U1 m, r, n2;\n  static\
    \ constexpr int W = numeric_limits<U1>::digits;\n\n  static void set_mod(U1 mod)\
    \ {\n    assert(mod & 1 && mod <= U1(1) << (W - 2));\n    m = mod, n2 = -U2(m)\
    \ % m, r = m;\n    FOR(6) r *= 2 - m * r;\n    r = -r;\n    assert(r * m == U1(-1));\n\
    \  }\n  static U1 reduce(U2 b) { return (b + U2(U1(b) * r) * m) >> W; }\n\n  U1\
    \ x;\n  Montgomery_modint() : x(0) {}\n  Montgomery_modint(U1 x) : x(reduce(U2(x)\
    \ * n2)){};\n  U1 val() const {\n    U1 y = reduce(x);\n    return y >= m ? y\
    \ - m : y;\n  }\n  mint &operator+=(mint y) {\n    x = ((x += y.x) >= m ? x -\
    \ m : x);\n    return *this;\n  }\n  mint &operator-=(mint y) {\n    x -= (x >=\
    \ y.x ? y.x : y.x - m);\n    return *this;\n  }\n  mint &operator*=(mint y) {\n\
    \    x = reduce(U2(x) * y.x);\n    return *this;\n  }\n  mint operator+(mint y)\
    \ const { return mint(*this) += y; }\n  mint operator-(mint y) const { return\
    \ mint(*this) -= y; }\n  mint operator*(mint y) const { return mint(*this) *=\
    \ y; }\n  bool operator==(mint y) const {\n    return (x >= m ? x - m : x) ==\
    \ (y.x >= m ? y.x - m : y.x);\n  }\n  bool operator!=(mint y) const { return not\
    \ operator==(y); }\n  mint pow(ll n) const {\n    assert(n >= 0);\n    mint y\
    \ = 1, z = *this;\n    for (; n; n >>= 1, z *= z)\n      if (n & 1) y *= z;\n\
    \    return y;\n  }\n};\n\ntemplate <int id>\nusing Montgomery_modint_32 = Montgomery_modint<id,\
    \ u32, u64>;\ntemplate <int id>\nusing Montgomery_modint_64 = Montgomery_modint<id,\
    \ u64, u128>;\n#line 1 \"mod/barrett.hpp\"\n\n// https://github.com/atcoder/ac-library/blob/master/atcoder/internal_math.hpp\n\
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
    \ a = bt.mul(a, a), n >>= 1;\n  }\n  return r;\n}\n#line 3 \"mod/mod_sqrt.hpp\"\
    \n\r\n// p \u306F\u7D20\u6570. \u89E3\u306A\u3057\u306F -1.\r\nint mod_sqrt(int\
    \ a, int p) {\r\n  if (p == 2) return a;\r\n  if (a == 0) return 0;\r\n  int k\
    \ = (p - 1) / 2;\r\n  if (mod_pow(a, k, p) != 1) return -1;\r\n  auto find = [&]()\
    \ -> pi {\r\n    while (1) {\r\n      ll b = RNG(2, p);\r\n      ll D = (b * b\
    \ - a) % p;\r\n      if (D == 0) return {b, D};\r\n      if (mod_pow(D, k, p)\
    \ != 1) return {b, D};\r\n    }\r\n  };\r\n  auto [b, D] = find();\r\n  if (D\
    \ == 0) return b;\r\n  ++k;\r\n  // (b + sqrt(D))^k\r\n  ll f0 = b, f1 = 1, g0\
    \ = 1, g1 = 0;\r\n  while (k) {\r\n    if (k & 1) {\r\n      tie(g0, g1) = mp(f0\
    \ * g0 + D * f1 % p * g1, f1 * g0 + f0 * g1);\r\n      g0 %= p, g1 %= p;\r\n \
    \   }\r\n    tie(f0, f1) = mp(f0 * f0 + D * f1 % p * f1, 2 * f0 * f1);\r\n   \
    \ f0 %= p, f1 %= p;\r\n    k >>= 1;\r\n  }\r\n  if (g0 < 0) g0 += p;\r\n  return\
    \ g0;\r\n}\r\n\r\n// p \u306F\u7D20\u6570. \u89E3\u306A\u3057\u306F -1.\r\nll\
    \ mod_sqrt_64(ll a, ll p) {\r\n  if (p == 2) return a;\r\n  if (a == 0) return\
    \ 0;\r\n  ll k = (p - 1) / 2;\r\n  if (mod_pow_64(a, k, p) != 1) return -1;\r\n\
    \  auto find = [&]() -> pair<i128, i128> {\r\n    while (1) {\r\n      i128 b\
    \ = RNG(2, p);\r\n      i128 D = b * b - a;\r\n      D %= p;\r\n      if (D ==\
    \ 0) return {b, D};\r\n      if (mod_pow_64(D, k, p) != 1) return {b, D};\r\n\
    \    }\r\n  };\r\n  auto [b, D] = find();\r\n  if (D == 0) return b;\r\n  ++k;\r\
    \n  // (b + sqrt(D))^k\r\n  i128 f0 = b, f1 = 1, g0 = 1, g1 = 0;\r\n  while (k)\
    \ {\r\n    if (k & 1) {\r\n      tie(g0, g1) = mp(f0 * g0 + D * f1 % p * g1, f1\
    \ * g0 + f0 * g1);\r\n      g0 %= p, g1 %= p;\r\n    }\r\n    tie(f0, f1) = mp(f0\
    \ * f0 + D * f1 % p * f1, 2 * f0 * f1);\r\n    f0 %= p, f1 %= p;\r\n    k >>=\
    \ 1;\r\n  }\r\n  return g0;\r\n}\r\n#line 1 \"other/bit.hpp\"\n\nint popcnt(int\
    \ x) { return __builtin_popcount(x); }\nint popcnt(u32 x) { return __builtin_popcount(x);\
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
    \ false;\n    }\n  }\n  return true;\n}\n#line 1 \"mod/primitive_root.hpp\"\n\n\
    #line 1 \"nt/factor.hpp\"\n\n#line 1 \"random/base.hpp\"\n\nu64 RNG_64() {\n \
    \ static u64 x_ = u64(chrono::duration_cast<chrono::nanoseconds>(\n          \
    \            chrono::high_resolution_clock::now().time_since_epoch())\n      \
    \                    .count()) *\n                  10150724397891781847ULL;\n\
    \  x_ ^= x_ << 7;\n  return x_ ^= x_ >> 9;\n}\n\nu64 RNG(u64 lim) {\n  assert(lim\
    \ > 0);\n  return RNG_64() % lim;\n}\n\nll RNG(ll l, ll r) {\n  assert(l < r);\n\
    \  return l + RNG_64() % (r - l);\n}\n#line 1 \"other/bit.hpp\"\n\nint popcnt(int\
    \ x) { return __builtin_popcount(x); }\nint popcnt(u32 x) { return __builtin_popcount(x);\
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
    }\n\nll find_prime_factor(ll n) {\n  assert(1 < n && n < (1LL << 62));\n  if (n\
    \ % 2 == 0) return 2;\n  if (is_prime(n)) return n;\n  FOR(100) {\n    ll m =\
    \ 0;\n    if (n < (1 << 30)) {\n      using mint = Montgomery_modint_32<20231025>;\n\
    \      mint::set_mod(n);\n      m = rho<mint>(n, RNG(0, n));\n    } else {\n \
    \     using mint = Montgomery_modint_64<20231025>;\n      mint::set_mod(n);\n\
    \      m = rho<mint>(n, RNG(0, n));\n    }\n    if (is_prime(m)) return m;\n \
    \   n = m;\n  }\n  assert(0);\n  return -1;\n}\n\n// \u30BD\u30FC\u30C8\u3057\u3066\
    \u304F\u308C\u308B\nvc<pair<ll, int>> factor(ll n) {\n  assert(1 <= n && n < (1LL\
    \ << 62));\n  vc<pair<ll, int>> pf;\n  FOR(p, 2, 100) {\n    if (p * p > n) break;\n\
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
    \n\nu64 RNG_64() {\n  static u64 x_ = u64(chrono::duration_cast<chrono::nanoseconds>(\n\
    \                      chrono::high_resolution_clock::now().time_since_epoch())\n\
    \                          .count()) *\n                  10150724397891781847ULL;\n\
    \  x_ ^= x_ << 7;\n  return x_ ^= x_ >> 9;\n}\n\nu64 RNG(u64 lim) {\n  assert(lim\
    \ > 0);\n  return RNG_64() % lim;\n}\n\nll RNG(ll l, ll r) {\n  assert(l < r);\n\
    \  return l + RNG_64() % (r - l);\n}\n#line 5 \"mod/primitive_root.hpp\"\n\n//\
    \ int\nint primitive_root(int p, bool min = true) {\n  auto pf = factor(p - 1);\n\
    \  auto is_ok = [&](int g) -> bool {\n    for (auto&& [q, e] : pf)\n      if (mod_pow(g,\
    \ (p - 1) / q, p) == 1) return false;\n    return true;\n  };\n  if (min) {\n\
    \    FOR(x, 1, p) if (is_ok(x)) return x;\n  }\n  while (1) {\n    int x = RNG(1,\
    \ p);\n    if (is_ok(x)) return x;\n  }\n  return -1;\n}\n\nll primitive_root_64(ll\
    \ p) {\n  auto pf = factor(p - 1);\n  auto is_ok = [&](ll g) -> bool {\n    for\
    \ (auto&& [q, e] : pf)\n      if (mod_pow_64(g, (p - 1) / q, p) == 1) return false;\n\
    \    return true;\n  };\n  while (1) {\n    ll x = RNG(1, p);\n    if (is_ok(x))\
    \ return x;\n  }\n  return -1;\n}\n\n// https://codeforces.com/contest/1190/problem/F\n\
    ll primitive_root_prime_power_64(ll p, ll e) {\n  assert(p >= 3);\n  ll g = primitive_root_64(p);\n\
    \  ll q = p;\n  ll phi = p - 1;\n  FOR(e - 1) {\n    q *= p;\n    phi *= p;\n\
    \    if (mod_pow_64(g, phi / p, q) == 1) g += q / p;\n  }\n  return g;\n}\n#line\
    \ 4 \"seq/sidon_sequence.hpp\"\n\n// a[i]+a[j] \u304C distinct \u306B\u306A\u308B\
    \u3088\u3046\u306B a[i] \u3092\u4F5C\u308B\n// [0,p(p-1)) \u306B p-1 \u500B\u3068\
    \u3044\u3046\u7C21\u5358\u306A\u65B9\u6CD5\u304C\u3042\u308B.\nstruct Sidon_Sequence\
    \ {\n  u32 N, p, r;\n  // positive \u306B\u3057\u305F\n  vc<u32> exp, log;\n \
    \ vc<u64> A;\n\n  Sidon_Sequence(u32 N) : N(N) {\n    p = max<ll>(3, N + 1);\n\
    \    while (!is_prime(p)) ++p;\n    exp.resize(p - 1);\n    log.resize(p);\n \
    \   u32 r = primitive_root(p);\n    exp[0] = 1;\n    FOR(i, p - 2) exp[i + 1]\
    \ = exp[i] * u64(r) % p;\n    FOR(i, p - 1) log[exp[i]] = i;\n    A.resize(N);\n\
    \    for (u32 i = 0; i < N; ++i) {\n      u64 a = i;\n      u64 b = exp[i];\n\
    \      u64 t = (a < b ? a - b + p - 1 : a - b);\n      A[i] = (b + t * p) % (u64(p)\
    \ * (p - 1));\n    }\n  }\n\n  u64 operator[](int i) { return A[i]; }\n\n  pair<int,\
    \ int> query(u64 val) {\n    u64 prod = exp[val % (p - 1)];\n    u64 sm = val\
    \ % p;\n    u64 sq = (sm * sm + 4 * (p - prod)) % p;\n    if (log[sq] & 1) return\
    \ {-1, -1};\n    assert(log[sq] % 2 == 0);\n    u64 k = log[sq] / 2;\n    u32\
    \ x = sm + exp[k], y = sm + p - exp[k];\n    x += (x & 1) * p, y += (y & 1) *\
    \ p;\n    x = x / 2 % p, y = y / 2 % p;\n    x = log[x], y = log[y];\n    if (x\
    \ < N && y < N && A[x] + A[y] == val) return {x, y};\n    return {-1, -1};\n \
    \ }\n};\n"
  code: "#include \"mod/mod_sqrt.hpp\"\n#include \"nt/is_prime.hpp\"\n#include \"\
    mod/primitive_root.hpp\"\n\n// a[i]+a[j] \u304C distinct \u306B\u306A\u308B\u3088\
    \u3046\u306B a[i] \u3092\u4F5C\u308B\n// [0,p(p-1)) \u306B p-1 \u500B\u3068\u3044\
    \u3046\u7C21\u5358\u306A\u65B9\u6CD5\u304C\u3042\u308B.\nstruct Sidon_Sequence\
    \ {\n  u32 N, p, r;\n  // positive \u306B\u3057\u305F\n  vc<u32> exp, log;\n \
    \ vc<u64> A;\n\n  Sidon_Sequence(u32 N) : N(N) {\n    p = max<ll>(3, N + 1);\n\
    \    while (!is_prime(p)) ++p;\n    exp.resize(p - 1);\n    log.resize(p);\n \
    \   u32 r = primitive_root(p);\n    exp[0] = 1;\n    FOR(i, p - 2) exp[i + 1]\
    \ = exp[i] * u64(r) % p;\n    FOR(i, p - 1) log[exp[i]] = i;\n    A.resize(N);\n\
    \    for (u32 i = 0; i < N; ++i) {\n      u64 a = i;\n      u64 b = exp[i];\n\
    \      u64 t = (a < b ? a - b + p - 1 : a - b);\n      A[i] = (b + t * p) % (u64(p)\
    \ * (p - 1));\n    }\n  }\n\n  u64 operator[](int i) { return A[i]; }\n\n  pair<int,\
    \ int> query(u64 val) {\n    u64 prod = exp[val % (p - 1)];\n    u64 sm = val\
    \ % p;\n    u64 sq = (sm * sm + 4 * (p - prod)) % p;\n    if (log[sq] & 1) return\
    \ {-1, -1};\n    assert(log[sq] % 2 == 0);\n    u64 k = log[sq] / 2;\n    u32\
    \ x = sm + exp[k], y = sm + p - exp[k];\n    x += (x & 1) * p, y += (y & 1) *\
    \ p;\n    x = x / 2 % p, y = y / 2 % p;\n    x = log[x], y = log[y];\n    if (x\
    \ < N && y < N && A[x] + A[y] == val) return {x, y};\n    return {-1, -1};\n \
    \ }\n};\n"
  dependsOn:
  - mod/mod_sqrt.hpp
  - random/base.hpp
  - mod/mod_pow.hpp
  - mod/montgomery_modint.hpp
  - mod/barrett.hpp
  - nt/is_prime.hpp
  - other/bit.hpp
  - mod/primitive_root.hpp
  - nt/factor.hpp
  isVerificationFile: false
  path: seq/sidon_sequence.hpp
  requiredBy: []
  timestamp: '2026-09-04 09:44:55+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: seq/sidon_sequence.hpp
layout: document
redirect_from:
- /library/seq/sidon_sequence.hpp
- /library/seq/sidon_sequence.hpp.html
title: seq/sidon_sequence.hpp
---
