---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: ds/hashmap.hpp
    title: ds/hashmap.hpp
  - icon: ':heavy_check_mark:'
    path: mod/mongomery_modint.hpp
    title: mod/mongomery_modint.hpp
  - icon: ':heavy_check_mark:'
    path: nt/factor.hpp
    title: nt/factor.hpp
  - icon: ':heavy_check_mark:'
    path: nt/is_prime.hpp
    title: nt/is_prime.hpp
  - icon: ':heavy_check_mark:'
    path: other/bit.hpp
    title: other/bit.hpp
  - icon: ':question:'
    path: random/base.hpp
    title: random/base.hpp
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/3_yukicoder/1728.test.cpp
    title: test/3_yukicoder/1728.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/3_yukicoder/2264.test.cpp
    title: test/3_yukicoder/2264.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/3_yukicoder/2578.test.cpp
    title: test/3_yukicoder/2578.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
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
    \ = Mongomery_modint<id, u64, u128>;\n#line 3 \"nt/is_prime.hpp\"\n\nbool is_prime(const\
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
    }\n\nll find_prime_factor(ll n) {\n  assert(n > 1);\n  if (is_prime(n)) return\
    \ n;\n  FOR(100) {\n    ll m = 0;\n    if (n < (1 << 30)) {\n      using mint\
    \ = Mongomery_modint_32<20231025>;\n      mint::set_mod(n);\n      m = rho<mint>(n,\
    \ RNG(0, n));\n    } else {\n      using mint = Mongomery_modint_64<20231025>;\n\
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
    \ return res;\n}\n#line 1 \"ds/hashmap.hpp\"\n\n// u64 -> Val\ntemplate <typename\
    \ Val>\nstruct HashMap {\n  // n \u306F\u5165\u308C\u305F\u3044\u3082\u306E\u306E\
    \u500B\u6570\u3067 ok\n  HashMap(u32 n = 0) { build(n); }\n  void build(u32 n)\
    \ {\n    u32 k = 8;\n    while (k < n * 2) k *= 2;\n    cap = k / 2, mask = k\
    \ - 1;\n    key.resize(k), val.resize(k), used.assign(k, 0);\n  }\n\n  // size\
    \ \u3092\u4FDD\u3063\u305F\u307E\u307E. size=0 \u306B\u3059\u308B\u3068\u304D\u306F\
    \ build \u3059\u308B\u3053\u3068.\n  void clear() {\n    used.assign(len(used),\
    \ 0);\n    cap = (mask + 1) / 2;\n  }\n  int size() { return len(used) / 2 - cap;\
    \ }\n\n  int index(const u64& k) {\n    int i = 0;\n    for (i = hash(k); used[i]\
    \ && key[i] != k; i = (i + 1) & mask) {}\n    return i;\n  }\n\n  Val& operator[](const\
    \ u64& k) {\n    if (cap == 0) extend();\n    int i = index(k);\n    if (!used[i])\
    \ { used[i] = 1, key[i] = k, val[i] = Val{}, --cap; }\n    return val[i];\n  }\n\
    \n  Val get(const u64& k, Val default_value) {\n    int i = index(k);\n    return\
    \ (used[i] ? val[i] : default_value);\n  }\n\n  bool count(const u64& k) {\n \
    \   int i = index(k);\n    return used[i] && key[i] == k;\n  }\n\n  // f(key,\
    \ val)\n  template <typename F>\n  void enumerate_all(F f) {\n    FOR(i, len(used))\
    \ if (used[i]) f(key[i], val[i]);\n  }\n\nprivate:\n  u32 cap, mask;\n  vc<u64>\
    \ key;\n  vc<Val> val;\n  vc<bool> used;\n\n  u64 hash(u64 x) {\n    static const\
    \ u64 FIXED_RANDOM = std::chrono::steady_clock::now().time_since_epoch().count();\n\
    \    x += FIXED_RANDOM;\n    x = (x ^ (x >> 30)) * 0xbf58476d1ce4e5b9;\n    x\
    \ = (x ^ (x >> 27)) * 0x94d049bb133111eb;\n    return (x ^ (x >> 31)) & mask;\n\
    \  }\n\n  void extend() {\n    vc<pair<u64, Val>> dat;\n    dat.reserve(len(used)\
    \ / 2 - cap);\n    FOR(i, len(used)) {\n      if (used[i]) dat.eb(key[i], val[i]);\n\
    \    }\n    build(2 * len(dat));\n    for (auto& [a, b]: dat) (*this)[a] = b;\n\
    \  }\n};\n#line 3 \"nt/array_on_divisors.hpp\"\n\ntemplate <typename T>\nstruct\
    \ Array_On_Divisors {\n  vc<pair<ll, int>> pf;\n  vc<ll> divs;\n  vc<T> dat;\n\
    \  HashMap<int> MP;\n\n  Array_On_Divisors(ll N = 1) { build(N); }\n  Array_On_Divisors(vc<pair<ll,\
    \ int>> pf) { build(pf); }\n\n  void build(ll N) { build(factor(N)); }\n  void\
    \ build(vc<pair<ll, int>> pfs) {\n    if (!pf.empty() && pf == pfs) return;\n\
    \    pf = pfs;\n    ll n = 1;\n    for (auto&& [p, e] : pf) n *= (e + 1);\n  \
    \  divs.assign(n, 1);\n    dat.assign(n, T{});\n    int nxt = 1;\n    for (auto&&\
    \ [p, e] : pf) {\n      int L = nxt;\n      ll q = p;\n      FOR(e) {\n      \
    \  FOR(i, L) { divs[nxt++] = divs[i] * q; }\n        q *= p;\n      }\n    }\n\
    \    MP.build(n);\n    FOR(i, n) MP[divs[i]] = i;\n  }\n\n  T& operator[](ll d)\
    \ { return dat[MP[d]]; }\n\n  // f(p, k) \u3092\u4E0E\u3048\u308B \u2192 \u4E57\
    \u6CD5\u7684\u306B\u62E1\u5F35\n  template <typename F>\n  void set_multiplicative(F\
    \ f) {\n    dat.reserve(len(divs));\n    dat = {T(1)};\n    for (auto&& [p, e]\
    \ : pf) {\n      int n = len(divs);\n      FOR(k, 1, e + 1) { FOR(i, n) dat.eb(dat[i]\
    \ * f(p, k)); }\n    }\n  }\n\n  void set_euler_phi() {\n    dat.resize(len(divs));\n\
    \    FOR(i, len(divs)) dat[i] = T(divs[i]);\n    divisor_mobius();\n  }\n\n  void\
    \ set_mobius() {\n    set_multiplicative([&](ll p, int k) -> T {\n      if (k\
    \ >= 2) return T(0);\n      return (k == 1 ? T(-1) : T(0));\n    });\n  }\n\n\
    \  void multiple_zeta() {\n    ll k = 1;\n    for (auto&& [p, e] : pf) {\n   \
    \   ll mod = k * (e + 1);\n      FOR(i, len(divs) / mod) {\n        FOR_R(j, mod\
    \ - k) { dat[mod * i + j] += dat[mod * i + j + k]; }\n      }\n      k *= (e +\
    \ 1);\n    }\n  }\n\n  void multiple_mobius() {\n    ll k = 1;\n    for (auto&&\
    \ [p, e] : pf) {\n      ll mod = k * (e + 1);\n      FOR(i, len(divs) / mod) {\n\
    \        FOR(j, mod - k) { dat[mod * i + j] -= dat[mod * i + j + k]; }\n     \
    \ }\n      k *= (e + 1);\n    }\n  }\n\n  void divisor_zeta() {\n    ll k = 1;\n\
    \    for (auto&& [p, e] : pf) {\n      ll mod = k * (e + 1);\n      FOR(i, len(divs)\
    \ / mod) {\n        FOR(j, mod - k) { dat[mod * i + j + k] += dat[mod * i + j];\
    \ }\n      }\n      k *= (e + 1);\n    }\n  }\n\n  void divisor_mobius() {\n \
    \   ll k = 1;\n    for (auto&& [p, e] : pf) {\n      ll mod = k * (e + 1);\n \
    \     FOR(i, len(divs) / mod) {\n        FOR_R(j, mod - k) { dat[mod * i + j +\
    \ k] -= dat[mod * i + j]; }\n      }\n      k *= (e + 1);\n    }\n  }\n\n  //\
    \ (Ta,Tb)->T : a-b\n  template <typename F>\n  void divisor_mobius(F SUB) {\n\
    \    ll k = 1;\n    for (auto&& [p, e] : pf) {\n      ll mod = k * (e + 1);\n\
    \      FOR(i, len(divs) / mod) {\n        FOR_R(j, mod - k) {\n          dat[mod\
    \ * i + j + k] = SUB(dat[mod * i + j + k], dat[mod * i + j]);\n        }\n   \
    \   }\n      k *= (e + 1);\n    }\n  }\n\n  // ADD(Ta,Tb)->T : a+b\n  template\
    \ <typename F>\n  void multiplier_zeta(F ADD) {\n    ll k = 1;\n    for (auto&&\
    \ [p, e] : pf) {\n      ll mod = k * (e + 1);\n      FOR(i, len(divs) / mod) {\n\
    \        FOR_R(j, mod - k) {\n          dat[mod * i + j] = ADD(dat[mod * i + j],\
    \ dat[mod * i + j + k]);\n        }\n      }\n      k *= (e + 1);\n    }\n  }\n\
    \n  // SUB(Ta,Tb)->T : a-=b\n  template <typename F>\n  void multiplier_mobius(F\
    \ SUB) {\n    ll k = 1;\n    for (auto&& [p, e] : pf) {\n      ll mod = k * (e\
    \ + 1);\n      FOR(i, len(divs) / mod) {\n        FOR(j, mod - k) {\n        \
    \  dat[mod * i + j] = SUB(dat[mod * i + j], dat[mod * i + j + k]);\n        }\n\
    \      }\n      k *= (e + 1);\n    }\n  }\n\n  // ADD(T&a,Tb)->void : a+=b\n \
    \ template <typename F>\n  void divisor_zeta(F ADD) {\n    ll k = 1;\n    for\
    \ (auto&& [p, e] : pf) {\n      ll mod = k * (e + 1);\n      FOR(i, len(divs)\
    \ / mod) {\n        FOR(j, mod - k) {\n          dat[mod * i + j + k] = ADD(dat[mod\
    \ * i + j + k], dat[mod * i + j]);\n        }\n      }\n      k *= (e + 1);\n\
    \    }\n  }\n\n  template <typename F>\n  void set(F f) {\n    FOR(i, len(divs))\
    \ { dat[i] = f(divs[i]); }\n  }\n\n  // (d, fd)\n  // &fd \u3067\u53D7\u3051\u53D6\
    \u308C\u3070\u4EE3\u5165\u3068\u304B\u3082\u3067\u304D\u307E\u3059\n  template\
    \ <typename F>\n  void enumerate(F f) {\n    FOR(i, len(divs)) { f(divs[i], dat[i]);\
    \ }\n  }\n\n  // n \u306E\u7D04\u6570\u5168\u4F53\n  vi get_divisors(ll n) {\n\
    \    assert(divs.back() % n == 0);\n    vi dp = {1};\n    for (auto& [p, f] :\
    \ pf) {\n      ll e = 0;\n      while (n % p == 0) n /= p, ++e;\n      ll m =\
    \ len(dp);\n      FOR(i, m) {\n        ll x = dp[i];\n        FOR(j, 1, e + 1)\
    \ x *= p, dp.eb(x);\n      }\n    }\n    return dp;\n  }\n};\n"
  code: "#include \"nt/factor.hpp\"\n#include \"ds/hashmap.hpp\"\n\ntemplate <typename\
    \ T>\nstruct Array_On_Divisors {\n  vc<pair<ll, int>> pf;\n  vc<ll> divs;\n  vc<T>\
    \ dat;\n  HashMap<int> MP;\n\n  Array_On_Divisors(ll N = 1) { build(N); }\n  Array_On_Divisors(vc<pair<ll,\
    \ int>> pf) { build(pf); }\n\n  void build(ll N) { build(factor(N)); }\n  void\
    \ build(vc<pair<ll, int>> pfs) {\n    if (!pf.empty() && pf == pfs) return;\n\
    \    pf = pfs;\n    ll n = 1;\n    for (auto&& [p, e] : pf) n *= (e + 1);\n  \
    \  divs.assign(n, 1);\n    dat.assign(n, T{});\n    int nxt = 1;\n    for (auto&&\
    \ [p, e] : pf) {\n      int L = nxt;\n      ll q = p;\n      FOR(e) {\n      \
    \  FOR(i, L) { divs[nxt++] = divs[i] * q; }\n        q *= p;\n      }\n    }\n\
    \    MP.build(n);\n    FOR(i, n) MP[divs[i]] = i;\n  }\n\n  T& operator[](ll d)\
    \ { return dat[MP[d]]; }\n\n  // f(p, k) \u3092\u4E0E\u3048\u308B \u2192 \u4E57\
    \u6CD5\u7684\u306B\u62E1\u5F35\n  template <typename F>\n  void set_multiplicative(F\
    \ f) {\n    dat.reserve(len(divs));\n    dat = {T(1)};\n    for (auto&& [p, e]\
    \ : pf) {\n      int n = len(divs);\n      FOR(k, 1, e + 1) { FOR(i, n) dat.eb(dat[i]\
    \ * f(p, k)); }\n    }\n  }\n\n  void set_euler_phi() {\n    dat.resize(len(divs));\n\
    \    FOR(i, len(divs)) dat[i] = T(divs[i]);\n    divisor_mobius();\n  }\n\n  void\
    \ set_mobius() {\n    set_multiplicative([&](ll p, int k) -> T {\n      if (k\
    \ >= 2) return T(0);\n      return (k == 1 ? T(-1) : T(0));\n    });\n  }\n\n\
    \  void multiple_zeta() {\n    ll k = 1;\n    for (auto&& [p, e] : pf) {\n   \
    \   ll mod = k * (e + 1);\n      FOR(i, len(divs) / mod) {\n        FOR_R(j, mod\
    \ - k) { dat[mod * i + j] += dat[mod * i + j + k]; }\n      }\n      k *= (e +\
    \ 1);\n    }\n  }\n\n  void multiple_mobius() {\n    ll k = 1;\n    for (auto&&\
    \ [p, e] : pf) {\n      ll mod = k * (e + 1);\n      FOR(i, len(divs) / mod) {\n\
    \        FOR(j, mod - k) { dat[mod * i + j] -= dat[mod * i + j + k]; }\n     \
    \ }\n      k *= (e + 1);\n    }\n  }\n\n  void divisor_zeta() {\n    ll k = 1;\n\
    \    for (auto&& [p, e] : pf) {\n      ll mod = k * (e + 1);\n      FOR(i, len(divs)\
    \ / mod) {\n        FOR(j, mod - k) { dat[mod * i + j + k] += dat[mod * i + j];\
    \ }\n      }\n      k *= (e + 1);\n    }\n  }\n\n  void divisor_mobius() {\n \
    \   ll k = 1;\n    for (auto&& [p, e] : pf) {\n      ll mod = k * (e + 1);\n \
    \     FOR(i, len(divs) / mod) {\n        FOR_R(j, mod - k) { dat[mod * i + j +\
    \ k] -= dat[mod * i + j]; }\n      }\n      k *= (e + 1);\n    }\n  }\n\n  //\
    \ (Ta,Tb)->T : a-b\n  template <typename F>\n  void divisor_mobius(F SUB) {\n\
    \    ll k = 1;\n    for (auto&& [p, e] : pf) {\n      ll mod = k * (e + 1);\n\
    \      FOR(i, len(divs) / mod) {\n        FOR_R(j, mod - k) {\n          dat[mod\
    \ * i + j + k] = SUB(dat[mod * i + j + k], dat[mod * i + j]);\n        }\n   \
    \   }\n      k *= (e + 1);\n    }\n  }\n\n  // ADD(Ta,Tb)->T : a+b\n  template\
    \ <typename F>\n  void multiplier_zeta(F ADD) {\n    ll k = 1;\n    for (auto&&\
    \ [p, e] : pf) {\n      ll mod = k * (e + 1);\n      FOR(i, len(divs) / mod) {\n\
    \        FOR_R(j, mod - k) {\n          dat[mod * i + j] = ADD(dat[mod * i + j],\
    \ dat[mod * i + j + k]);\n        }\n      }\n      k *= (e + 1);\n    }\n  }\n\
    \n  // SUB(Ta,Tb)->T : a-=b\n  template <typename F>\n  void multiplier_mobius(F\
    \ SUB) {\n    ll k = 1;\n    for (auto&& [p, e] : pf) {\n      ll mod = k * (e\
    \ + 1);\n      FOR(i, len(divs) / mod) {\n        FOR(j, mod - k) {\n        \
    \  dat[mod * i + j] = SUB(dat[mod * i + j], dat[mod * i + j + k]);\n        }\n\
    \      }\n      k *= (e + 1);\n    }\n  }\n\n  // ADD(T&a,Tb)->void : a+=b\n \
    \ template <typename F>\n  void divisor_zeta(F ADD) {\n    ll k = 1;\n    for\
    \ (auto&& [p, e] : pf) {\n      ll mod = k * (e + 1);\n      FOR(i, len(divs)\
    \ / mod) {\n        FOR(j, mod - k) {\n          dat[mod * i + j + k] = ADD(dat[mod\
    \ * i + j + k], dat[mod * i + j]);\n        }\n      }\n      k *= (e + 1);\n\
    \    }\n  }\n\n  template <typename F>\n  void set(F f) {\n    FOR(i, len(divs))\
    \ { dat[i] = f(divs[i]); }\n  }\n\n  // (d, fd)\n  // &fd \u3067\u53D7\u3051\u53D6\
    \u308C\u3070\u4EE3\u5165\u3068\u304B\u3082\u3067\u304D\u307E\u3059\n  template\
    \ <typename F>\n  void enumerate(F f) {\n    FOR(i, len(divs)) { f(divs[i], dat[i]);\
    \ }\n  }\n\n  // n \u306E\u7D04\u6570\u5168\u4F53\n  vi get_divisors(ll n) {\n\
    \    assert(divs.back() % n == 0);\n    vi dp = {1};\n    for (auto& [p, f] :\
    \ pf) {\n      ll e = 0;\n      while (n % p == 0) n /= p, ++e;\n      ll m =\
    \ len(dp);\n      FOR(i, m) {\n        ll x = dp[i];\n        FOR(j, 1, e + 1)\
    \ x *= p, dp.eb(x);\n      }\n    }\n    return dp;\n  }\n};\n"
  dependsOn:
  - nt/factor.hpp
  - random/base.hpp
  - nt/is_prime.hpp
  - other/bit.hpp
  - mod/mongomery_modint.hpp
  - ds/hashmap.hpp
  isVerificationFile: false
  path: nt/array_on_divisors.hpp
  requiredBy: []
  timestamp: '2026-08-17 08:53:30+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/3_yukicoder/2578.test.cpp
  - test/3_yukicoder/2264.test.cpp
  - test/3_yukicoder/1728.test.cpp
documentation_of: nt/array_on_divisors.hpp
layout: document
redirect_from:
- /library/nt/array_on_divisors.hpp
- /library/nt/array_on_divisors.hpp.html
title: nt/array_on_divisors.hpp
---
