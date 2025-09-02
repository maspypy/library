---
data:
  _extendedDependsOn:
  - icon: ':x:'
    path: ds/hashmap.hpp
    title: ds/hashmap.hpp
  - icon: ':x:'
    path: mod/barrett.hpp
    title: mod/barrett.hpp
  - icon: ':x:'
    path: mod/mod_inv.hpp
    title: mod/mod_inv.hpp
  - icon: ':x:'
    path: mod/mod_pow.hpp
    title: mod/mod_pow.hpp
  - icon: ':x:'
    path: mod/mongomery_modint.hpp
    title: mod/mongomery_modint.hpp
  - icon: ':x:'
    path: mod/primitive_root.hpp
    title: mod/primitive_root.hpp
  - icon: ':x:'
    path: nt/factor.hpp
    title: nt/factor.hpp
  - icon: ':x:'
    path: nt/primetest.hpp
    title: nt/primetest.hpp
  - icon: ':x:'
    path: random/base.hpp
    title: random/base.hpp
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':x:'
    path: test/2_library_checker/number_theory/kth_root_mod.test.cpp
    title: test/2_library_checker/number_theory/kth_root_mod.test.cpp
  _isVerificationFailed: true
  _pathExtension: hpp
  _verificationStatusIcon: ':x:'
  attributes:
    links: []
  bundledCode: "#line 2 \"mod/mongomery_modint.hpp\"\n\n// odd mod.\n// x \u306E\u4EE3\
    \u308F\u308A\u306B rx \u3092\u6301\u3064\ntemplate <int id, typename U1, typename\
    \ U2>\nstruct Mongomery_modint {\n  using mint = Mongomery_modint;\n  inline static\
    \ U1 m, r, n2;\n  static constexpr int W = numeric_limits<U1>::digits;\n\n  static\
    \ void set_mod(U1 mod) {\n    assert(mod & 1 && mod <= U1(1) << (W - 2));\n  \
    \  m = mod, n2 = -U2(m) % m, r = m;\n    FOR(5) r *= 2 - m * r;\n    r = -r;\n\
    \    assert(r * m == U1(-1));\n  }\n  static U1 reduce(U2 b) { return (b + U2(U1(b)\
    \ * r) * m) >> W; }\n\n  U1 x;\n  Mongomery_modint() : x(0) {}\n  Mongomery_modint(U1\
    \ x) : x(reduce(U2(x) * n2)){};\n  U1 val() const {\n    U1 y = reduce(x);\n \
    \   return y >= m ? y - m : y;\n  }\n  mint &operator+=(mint y) {\n    x = ((x\
    \ += y.x) >= m ? x - m : x);\n    return *this;\n  }\n  mint &operator-=(mint\
    \ y) {\n    x -= (x >= y.x ? y.x : y.x - m);\n    return *this;\n  }\n  mint &operator*=(mint\
    \ y) {\n    x = reduce(U2(x) * y.x);\n    return *this;\n  }\n  mint operator+(mint\
    \ y) const { return mint(*this) += y; }\n  mint operator-(mint y) const { return\
    \ mint(*this) -= y; }\n  mint operator*(mint y) const { return mint(*this) *=\
    \ y; }\n  bool operator==(mint y) const {\n    return (x >= m ? x - m : x) ==\
    \ (y.x >= m ? y.x - m : y.x);\n  }\n  bool operator!=(mint y) const { return not\
    \ operator==(y); }\n  mint pow(ll n) const {\n    assert(n >= 0);\n    mint y\
    \ = 1, z = *this;\n    for (; n; n >>= 1, z *= z)\n      if (n & 1) y *= z;\n\
    \    return y;\n  }\n};\n\ntemplate <int id>\nusing Mongomery_modint_32 = Mongomery_modint<id,\
    \ u32, u64>;\ntemplate <int id>\nusing Mongomery_modint_64 = Mongomery_modint<id,\
    \ u64, u128>;\n#line 3 \"nt/primetest.hpp\"\n\r\nbool primetest(const u64 x) {\r\
    \n  assert(x < u64(1) << 62);\r\n  if (x == 2 or x == 3 or x == 5 or x == 7) return\
    \ true;\r\n  if (x % 2 == 0 or x % 3 == 0 or x % 5 == 0 or x % 7 == 0) return\
    \ false;\r\n  if (x < 121) return x > 1;\r\n  const u64 d = (x - 1) >> lowbit(x\
    \ - 1);\r\n\r\n  using mint = Mongomery_modint_64<202311020>;\r\n\r\n  mint::set_mod(x);\r\
    \n  const mint one(u64(1)), minus_one(x - 1);\r\n  auto ok = [&](u64 a) -> bool\
    \ {\r\n    auto y = mint(a).pow(d);\r\n    u64 t = d;\r\n    while (y != one &&\
    \ y != minus_one && t != x - 1) y *= y, t <<= 1;\r\n    if (y != minus_one &&\
    \ t % 2 == 0) return false;\r\n    return true;\r\n  };\r\n  if (x < (u64(1) <<\
    \ 32)) {\r\n    for (u64 a: {2, 7, 61})\r\n      if (!ok(a)) return false;\r\n\
    \  } else {\r\n    for (u64 a: {2, 325, 9375, 28178, 450775, 9780504, 1795265022})\
    \ {\r\n      if (!ok(a)) return false;\r\n    }\r\n  }\r\n  return true;\r\n}\n\
    #line 2 \"mod/primitive_root.hpp\"\n\r\n#line 2 \"nt/factor.hpp\"\n\n#line 2 \"\
    random/base.hpp\"\n\nu64 RNG_64() {\n  static u64 x_ = u64(chrono::duration_cast<chrono::nanoseconds>(chrono::high_resolution_clock::now().time_since_epoch()).count())\
    \ * 10150724397891781847ULL;\n  x_ ^= x_ << 7;\n  return x_ ^= x_ >> 9;\n}\n\n\
    u64 RNG(u64 lim) { return RNG_64() % lim; }\n\nll RNG(ll l, ll r) { return l +\
    \ RNG_64() % (r - l); }\n#line 5 \"nt/factor.hpp\"\n\ntemplate <typename mint>\n\
    ll rho(ll n, ll c) {\n  assert(n > 1);\n  const mint cc(c);\n  auto f = [&](mint\
    \ x) { return x * x + cc; };\n  mint x = 1, y = 2, z = 1, q = 1;\n  ll g = 1;\n\
    \  const ll m = 1LL << (__lg(n) / 5);\n  for (ll r = 1; g == 1; r <<= 1) {\n \
    \   x = y;\n    FOR(r) y = f(y);\n    for (ll k = 0; k < r && g == 1; k += m)\
    \ {\n      z = y;\n      FOR(min(m, r - k)) y = f(y), q *= x - y;\n      g = gcd(q.val(),\
    \ n);\n    }\n  }\n  if (g == n) do {\n      z = f(z);\n      g = gcd((x - z).val(),\
    \ n);\n    } while (g == 1);\n  return g;\n}\n\nll find_prime_factor(ll n) {\n\
    \  assert(n > 1);\n  if (primetest(n)) return n;\n  FOR(100) {\n    ll m = 0;\n\
    \    if (n < (1 << 30)) {\n      using mint = Mongomery_modint_32<20231025>;\n\
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
    \    }\n    res.eb(p, e);\n  }\n  return res;\n}\n#line 2 \"mod/mod_pow.hpp\"\n\
    \r\n#line 2 \"mod/barrett.hpp\"\n\n// https://github.com/atcoder/ac-library/blob/master/atcoder/internal_math.hpp\n\
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
    \  }\n\n  u64 mul(u64 a, u64 b) { return modulo(u128(a) * b); }\n};\n#line 5 \"\
    mod/mod_pow.hpp\"\n\r\nu32 mod_pow(int a, ll n, int mod) {\r\n  assert(n >= 0);\r\
    \n  if (mod == 1) return 0;\r\n  a = ((a %= mod) < 0 ? a + mod : a);\r\n  if ((mod\
    \ & 1) && (mod < (1 << 30))) {\r\n    using mint = Mongomery_modint_32<202311021>;\r\
    \n    mint::set_mod(mod);\r\n    return mint(a).pow(n).val();\r\n  }\r\n  Barrett\
    \ bt(mod);\r\n  int r = 1;\r\n  while (n) {\r\n    if (n & 1) r = bt.mul(r, a);\r\
    \n    a = bt.mul(a, a), n >>= 1;\r\n  }\r\n  return r;\r\n}\r\n\r\nu64 mod_pow_64(ll\
    \ a, ll n, u64 mod) {\r\n  assert(n >= 0);\r\n  if (mod == 1) return 0;\r\n  a\
    \ = ((a %= mod) < 0 ? a + mod : a);\r\n  if ((mod & 1) && (mod < (u64(1) << 62)))\
    \ {\r\n    using mint = Mongomery_modint_64<202311021>;\r\n    mint::set_mod(mod);\r\
    \n    return mint(a).pow(n).val();\r\n  }\r\n  Barrett_64 bt(mod);\r\n  ll r =\
    \ 1;\r\n  while (n) {\r\n    if (n & 1) r = bt.mul(r, a);\r\n    a = bt.mul(a,\
    \ a), n >>= 1;\r\n  }\r\n  return r;\r\n}\n#line 6 \"mod/primitive_root.hpp\"\n\
    \r\n// int\r\nint primitive_root(int p) {\r\n  auto pf = factor(p - 1);\r\n  auto\
    \ is_ok = [&](int g) -> bool {\r\n    for (auto&& [q, e]: pf)\r\n      if (mod_pow(g,\
    \ (p - 1) / q, p) == 1) return false;\r\n    return true;\r\n  };\r\n  while (1)\
    \ {\r\n    int x = RNG(1, p);\r\n    if (is_ok(x)) return x;\r\n  }\r\n  return\
    \ -1;\r\n}\r\n\r\nll primitive_root_64(ll p) {\r\n  auto pf = factor(p - 1);\r\
    \n  auto is_ok = [&](ll g) -> bool {\r\n    for (auto&& [q, e]: pf)\r\n      if\
    \ (mod_pow_64(g, (p - 1) / q, p) == 1) return false;\r\n    return true;\r\n \
    \ };\r\n  while (1) {\r\n    ll x = RNG(1, p);\r\n    if (is_ok(x)) return x;\r\
    \n  }\r\n  return -1;\r\n}\r\n\r\n// https://codeforces.com/contest/1190/problem/F\r\
    \nll primitive_root_prime_power_64(ll p, ll e) {\r\n  assert(p >= 3);\r\n  ll\
    \ g = primitive_root_64(p);\r\n  ll q = p;\r\n  ll phi = p - 1;\r\n  FOR(e - 1)\
    \ {\r\n    q *= p;\r\n    phi *= p;\r\n    if (mod_pow_64(g, phi / p, q) == 1)\
    \ g += q / p;\r\n  }\r\n  return g;\r\n}\r\n#line 2 \"mod/mod_inv.hpp\"\n\r\n\
    // long \u3067\u3082\u5927\u4E08\u592B\r\n// (val * x - 1) \u304C mod \u306E\u500D\
    \u6570\u306B\u306A\u308B\u3088\u3046\u306B\u3059\u308B\r\n// \u7279\u306B mod=0\
    \ \u306A\u3089 x=0 \u304C\u6E80\u305F\u3059\r\nll mod_inv(ll val, ll mod) {\r\n\
    \  if (mod == 0) return 0;\r\n  mod = abs(mod);\r\n  val %= mod;\r\n  if (val\
    \ < 0) val += mod;\r\n  ll a = val, b = mod, u = 1, v = 0, t;\r\n  while (b >\
    \ 0) {\r\n    t = a / b;\r\n    swap(a -= t * b, b), swap(u -= t * v, v);\r\n\
    \  }\r\n  if (u < 0) u += mod;\r\n  return u;\r\n}\r\n#line 2 \"ds/hashmap.hpp\"\
    \n\r\n// u64 -> Val\r\ntemplate <typename Val>\r\nstruct HashMap {\r\n  // n \u306F\
    \u5165\u308C\u305F\u3044\u3082\u306E\u306E\u500B\u6570\u3067 ok\r\n  HashMap(u32\
    \ n = 0) { build(n); }\r\n  void build(u32 n) {\r\n    u32 k = 8;\r\n    while\
    \ (k < n * 2) k *= 2;\r\n    cap = k / 2, mask = k - 1;\r\n    key.resize(k),\
    \ val.resize(k), used.assign(k, 0);\r\n  }\r\n\r\n  // size \u3092\u4FDD\u3063\
    \u305F\u307E\u307E. size=0 \u306B\u3059\u308B\u3068\u304D\u306F build \u3059\u308B\
    \u3053\u3068.\r\n  void clear() {\r\n    used.assign(len(used), 0);\r\n    cap\
    \ = (mask + 1) / 2;\r\n  }\r\n  int size() { return len(used) / 2 - cap; }\r\n\
    \r\n  int index(const u64& k) {\r\n    int i = 0;\r\n    for (i = hash(k); used[i]\
    \ && key[i] != k; i = (i + 1) & mask) {}\r\n    return i;\r\n  }\r\n\r\n  Val&\
    \ operator[](const u64& k) {\r\n    if (cap == 0) extend();\r\n    int i = index(k);\r\
    \n    if (!used[i]) { used[i] = 1, key[i] = k, val[i] = Val{}, --cap; }\r\n  \
    \  return val[i];\r\n  }\r\n\r\n  Val get(const u64& k, Val default_value) {\r\
    \n    int i = index(k);\r\n    return (used[i] ? val[i] : default_value);\r\n\
    \  }\r\n\r\n  bool count(const u64& k) {\r\n    int i = index(k);\r\n    return\
    \ used[i] && key[i] == k;\r\n  }\r\n\r\n  // f(key, val)\r\n  template <typename\
    \ F>\r\n  void enumerate_all(F f) {\r\n    FOR(i, len(used)) if (used[i]) f(key[i],\
    \ val[i]);\r\n  }\r\n\r\nprivate:\r\n  u32 cap, mask;\r\n  vc<u64> key;\r\n  vc<Val>\
    \ val;\r\n  vc<bool> used;\r\n\r\n  u64 hash(u64 x) {\r\n    static const u64\
    \ FIXED_RANDOM = std::chrono::steady_clock::now().time_since_epoch().count();\r\
    \n    x += FIXED_RANDOM;\r\n    x = (x ^ (x >> 30)) * 0xbf58476d1ce4e5b9;\r\n\
    \    x = (x ^ (x >> 27)) * 0x94d049bb133111eb;\r\n    return (x ^ (x >> 31)) &\
    \ mask;\r\n  }\r\n\r\n  void extend() {\r\n    vc<pair<u64, Val>> dat;\r\n   \
    \ dat.reserve(len(used) / 2 - cap);\r\n    FOR(i, len(used)) {\r\n      if (used[i])\
    \ dat.eb(key[i], val[i]);\r\n    }\r\n    build(2 * len(dat));\r\n    for (auto&\
    \ [a, b]: dat) (*this)[a] = b;\r\n  }\r\n};\n#line 5 \"mod/mod_kth_root.hpp\"\n\
    \r\n// mod \u306F int\r\nint mod_kth_root(ll k, ll a, int mod) {\r\n  assert(primetest(mod)\
    \ && 0 <= a && a < mod);\r\n  if (k == 0) return (a == 1 ? 1 : -1);\r\n  if (a\
    \ == 0) return 0;\r\n  if (mod == 2) return a;\r\n  k %= mod - 1;\r\n  Barrett\
    \ bt(mod);\r\n\r\n  ll g = gcd(k, mod - 1);\r\n  if (mod_pow(a, (mod - 1) / g,\
    \ mod) != 1) return -1;\r\n\r\n  ll c = mod_inv(k / g, (mod - 1) / g);\r\n  a\
    \ = mod_pow(a, c, mod);\r\n  k = (k * c) % (mod - 1);\r\n  if (k == 0) return\
    \ 1;\r\n\r\n  g = primitive_root(mod);\r\n\r\n  auto solve_pp = [&](ll p, int\
    \ e, ll a) -> ll {\r\n    int f = 0;\r\n    ll pf = 1;\r\n    while ((mod - 1)\
    \ % (pf * p) == 0) ++f, pf *= p;\r\n    ll m = (mod - 1) / pf;\r\n    /*\r\n \
    \   \u30FB\u4F4D\u6570 Qm \u306E\u5DE1\u56DE\u7FA4\r\n    \u30FBa \u306E p^e \u4E57\
    \u6839\u3092\u3068\u308A\u305F\u3044\u3002\u6301\u3064\u3053\u3068\u306F\u5206\
    \u304B\u3063\u3066\u3044\u308B\r\n    \u30FBa / x^{p^e} = b \u3092\u7DAD\u6301\
    \u3059\u308B\u3002\u307E\u305A\u306F\u3001b \u304C p \u3067\u5272\u308C\u308B\u56DE\
    \u6570\u3092\u5897\u3084\u3057\u3066\u3044\u304F\u3002\r\n    */\r\n    ll x =\
    \ 1, b = a, c = f - e; // b ^ {mp^c} = 1\r\n    int pc = 1;\r\n    FOR(c) pc *=\
    \ p;\r\n    int pe = 1;\r\n    FOR(e) pe *= p;\r\n    // \u5FC5\u8981\u306A\u3089\
    \u3070\u539F\u59CB p \u4E57\u6839\u306B\u95A2\u3059\u308B\u96E2\u6563\u5BFE\u6570\
    \u554F\u984C\u306E\u30BB\u30C3\u30C8\u30A2\u30C3\u30D7\r\n    ll G = mod_pow(g,\
    \ (mod - 1) / p, mod);\r\n    int M = 0;\r\n    HashMap<int> MP;\r\n    ll GM_inv\
    \ = -1;\r\n    if (c) {\r\n      while (M * M < p) ++M;\r\n      MP.build(M);\r\
    \n      ll Gpow = 1;\r\n      FOR(m, M) {\r\n        MP[Gpow] = m;\r\n       \
    \ Gpow = bt.mul(Gpow, G);\r\n      }\r\n      GM_inv = mod_pow(Gpow, mod - 2,\
    \ mod);\r\n    }\r\n\r\n    while (c) {\r\n      /*\r\n      b^{mp^c} = 1 \u304C\
    \u5206\u304B\u3063\u3066\u3044\u308B\u3002(b/x^{p^e}})^{mp^{c-1}} = 1 \u306B\u3057\
    \u305F\u3044\u3002\r\n      x = g^{p^{f-c-e}*k} \u3068\u3057\u3066\u63A2\u3059\
    \u3002\u539F\u59CB p \u4E57\u6839 B, G \u306B\u5BFE\u3059\u308B B = G^k \u306B\
    \u5E30\u7740\u3002\r\n      */\r\n      ll B = mod_pow(b, m * pc / p, mod);\r\n\
    \      int k = [&](ll B) -> int {\r\n        FOR(m, M + 1) {\r\n          if (MP.count(B))\
    \ return m * M + MP[B];\r\n          B = bt.mul(B, GM_inv);\r\n        }\r\n \
    \       return -1;\r\n      }(B);\r\n      x = bt.mul(x, mod_pow(g, pf / pc /\
    \ pe * k, mod));\r\n      ll exp = pf / pc * k % (mod - 1);\r\n      b = bt.mul(b,\
    \ mod_pow(g, mod - 1 - exp, mod));\r\n      --c;\r\n      pc /= p;\r\n    }\r\n\
    \    int k = pe - mod_inv(m, pe);\r\n    k = (k * m + 1) / pe;\r\n    ll y = mod_pow(b,\
    \ k, mod);\r\n    x = bt.mul(x, y);\r\n    return x;\r\n  };\r\n\r\n  auto pf\
    \ = factor(k);\r\n  for (auto&& [p, e]: pf) a = solve_pp(p, e, a);\r\n  return\
    \ a;\r\n}\r\n\r\nll mod_kth_root_64(ll k, ll a, ll mod) {\r\n  assert(primetest(mod)\
    \ && 0 <= a && a < mod);\r\n  if (k == 0) return (a == 1 ? 1 : -1);\r\n  if (a\
    \ == 0) return 0;\r\n  if (mod == 2) return a;\r\n  k %= mod - 1;\r\n\r\n  ll\
    \ g = gcd(k, mod - 1);\r\n  if (mod_pow_64(a, (mod - 1) / g, mod) != 1) return\
    \ -1;\r\n\r\n  ll c = mod_inv(k / g, (mod - 1) / g);\r\n  a = mod_pow_64(a, c,\
    \ mod);\r\n  k = i128(k) * c % (mod - 1);\r\n  if (k == 0) return 1;\r\n\r\n \
    \ g = primitive_root_64(mod);\r\n\r\n  auto solve_pp = [&](ll p, ll e, ll a) ->\
    \ ll {\r\n    ll f = 0;\r\n    ll pf = 1;\r\n    while (((mod - 1) / pf) % p ==\
    \ 0) ++f, pf *= p;\r\n    ll m = (mod - 1) / pf;\r\n    /*\r\n    \u30FB\u4F4D\
    \u6570 Qm \u306E\u5DE1\u56DE\u7FA4\r\n    \u30FBa \u306E p^e \u4E57\u6839\u3092\
    \u3068\u308A\u305F\u3044\u3002\u6301\u3064\u3053\u3068\u306F\u5206\u304B\u3063\
    \u3066\u3044\u308B\r\n    \u30FBa / x^{p^e} = b \u3092\u7DAD\u6301\u3059\u308B\
    \u3002\u307E\u305A\u306F\u3001b \u304C p \u3067\u5272\u308C\u308B\u56DE\u6570\u3092\
    \u5897\u3084\u3057\u3066\u3044\u304F\u3002\r\n    */\r\n    ll x = 1, b = a, c\
    \ = f - e; // b ^ {mp^c} = 1\r\n    ll pc = 1;\r\n    FOR(c) pc *= p;\r\n    ll\
    \ pe = 1;\r\n    FOR(e) pe *= p;\r\n    // \u5FC5\u8981\u306A\u3089\u3070\u539F\
    \u59CB p \u4E57\u6839\u306B\u95A2\u3059\u308B\u96E2\u6563\u5BFE\u6570\u554F\u984C\
    \u306E\u30BB\u30C3\u30C8\u30A2\u30C3\u30D7\r\n    ll G = mod_pow_64(g, (mod -\
    \ 1) / p, mod);\r\n    ll M = 0;\r\n    ll GM_inv = -1;\r\n    HashMap<ll> MP;\r\
    \n    if (c) {\r\n      while (M * M < p) ++M;\r\n      MP.build(M);\r\n     \
    \ ll Gpow = 1;\r\n      FOR(m, M) {\r\n        MP[Gpow] = m;\r\n        Gpow =\
    \ i128(Gpow) * G % mod;\r\n      }\r\n      GM_inv = mod_pow_64(Gpow, mod - 2,\
    \ mod);\r\n    }\r\n\r\n    while (c) {\r\n      /*\r\n      b^{mp^c} = 1 \u304C\
    \u5206\u304B\u3063\u3066\u3044\u308B\u3002(b/x^{p^e}})^{mp^{c-1}} = 1 \u306B\u3057\
    \u305F\u3044\u3002\r\n      x = g^{p^{f-c-e}*k} \u3068\u3057\u3066\u63A2\u3059\
    \u3002\u539F\u59CB p \u4E57\u6839 B, G \u306B\u5BFE\u3059\u308B B = G^k \u306B\
    \u5E30\u7740\u3002\r\n      */\r\n      ll B = mod_pow_64(b, pc / p * m, mod);\r\
    \n      ll k = [&](ll B) -> ll {\r\n        FOR(m, M + 1) {\r\n          if (MP.count(B))\
    \ return m * M + MP[B];\r\n          B = i128(B) * GM_inv % mod;\r\n        }\r\
    \n        return -1;\r\n      }(B);\r\n      x = i128(x) * mod_pow_64(g, pf /\
    \ pc / pe * k, mod) % mod;\r\n\r\n      ll exp = pf / pc * i128(k) % (mod - 1);\r\
    \n      b = i128(b) * mod_pow_64(g, mod - 1 - exp, mod) % mod;\r\n      --c;\r\
    \n      pc /= p;\r\n    }\r\n    ll k = pe - mod_inv(m, pe);\r\n    k = (i128(k)\
    \ * m + 1) / pe;\r\n    ll y = mod_pow_64(b, k, mod);\r\n    x = i128(x) * y %\
    \ mod;\r\n    return x;\r\n  };\r\n\r\n  auto pf = factor(k);\r\n  for (auto&&\
    \ [p, e]: pf) a = solve_pp(p, e, a);\r\n  return a;\r\n}\r\n"
  code: "#include \"nt/primetest.hpp\"\r\n#include \"mod/primitive_root.hpp\"\r\n\
    #include \"mod/mod_inv.hpp\"\r\n#include \"ds/hashmap.hpp\"\r\n\r\n// mod \u306F\
    \ int\r\nint mod_kth_root(ll k, ll a, int mod) {\r\n  assert(primetest(mod) &&\
    \ 0 <= a && a < mod);\r\n  if (k == 0) return (a == 1 ? 1 : -1);\r\n  if (a ==\
    \ 0) return 0;\r\n  if (mod == 2) return a;\r\n  k %= mod - 1;\r\n  Barrett bt(mod);\r\
    \n\r\n  ll g = gcd(k, mod - 1);\r\n  if (mod_pow(a, (mod - 1) / g, mod) != 1)\
    \ return -1;\r\n\r\n  ll c = mod_inv(k / g, (mod - 1) / g);\r\n  a = mod_pow(a,\
    \ c, mod);\r\n  k = (k * c) % (mod - 1);\r\n  if (k == 0) return 1;\r\n\r\n  g\
    \ = primitive_root(mod);\r\n\r\n  auto solve_pp = [&](ll p, int e, ll a) -> ll\
    \ {\r\n    int f = 0;\r\n    ll pf = 1;\r\n    while ((mod - 1) % (pf * p) ==\
    \ 0) ++f, pf *= p;\r\n    ll m = (mod - 1) / pf;\r\n    /*\r\n    \u30FB\u4F4D\
    \u6570 Qm \u306E\u5DE1\u56DE\u7FA4\r\n    \u30FBa \u306E p^e \u4E57\u6839\u3092\
    \u3068\u308A\u305F\u3044\u3002\u6301\u3064\u3053\u3068\u306F\u5206\u304B\u3063\
    \u3066\u3044\u308B\r\n    \u30FBa / x^{p^e} = b \u3092\u7DAD\u6301\u3059\u308B\
    \u3002\u307E\u305A\u306F\u3001b \u304C p \u3067\u5272\u308C\u308B\u56DE\u6570\u3092\
    \u5897\u3084\u3057\u3066\u3044\u304F\u3002\r\n    */\r\n    ll x = 1, b = a, c\
    \ = f - e; // b ^ {mp^c} = 1\r\n    int pc = 1;\r\n    FOR(c) pc *= p;\r\n   \
    \ int pe = 1;\r\n    FOR(e) pe *= p;\r\n    // \u5FC5\u8981\u306A\u3089\u3070\u539F\
    \u59CB p \u4E57\u6839\u306B\u95A2\u3059\u308B\u96E2\u6563\u5BFE\u6570\u554F\u984C\
    \u306E\u30BB\u30C3\u30C8\u30A2\u30C3\u30D7\r\n    ll G = mod_pow(g, (mod - 1)\
    \ / p, mod);\r\n    int M = 0;\r\n    HashMap<int> MP;\r\n    ll GM_inv = -1;\r\
    \n    if (c) {\r\n      while (M * M < p) ++M;\r\n      MP.build(M);\r\n     \
    \ ll Gpow = 1;\r\n      FOR(m, M) {\r\n        MP[Gpow] = m;\r\n        Gpow =\
    \ bt.mul(Gpow, G);\r\n      }\r\n      GM_inv = mod_pow(Gpow, mod - 2, mod);\r\
    \n    }\r\n\r\n    while (c) {\r\n      /*\r\n      b^{mp^c} = 1 \u304C\u5206\u304B\
    \u3063\u3066\u3044\u308B\u3002(b/x^{p^e}})^{mp^{c-1}} = 1 \u306B\u3057\u305F\u3044\
    \u3002\r\n      x = g^{p^{f-c-e}*k} \u3068\u3057\u3066\u63A2\u3059\u3002\u539F\
    \u59CB p \u4E57\u6839 B, G \u306B\u5BFE\u3059\u308B B = G^k \u306B\u5E30\u7740\
    \u3002\r\n      */\r\n      ll B = mod_pow(b, m * pc / p, mod);\r\n      int k\
    \ = [&](ll B) -> int {\r\n        FOR(m, M + 1) {\r\n          if (MP.count(B))\
    \ return m * M + MP[B];\r\n          B = bt.mul(B, GM_inv);\r\n        }\r\n \
    \       return -1;\r\n      }(B);\r\n      x = bt.mul(x, mod_pow(g, pf / pc /\
    \ pe * k, mod));\r\n      ll exp = pf / pc * k % (mod - 1);\r\n      b = bt.mul(b,\
    \ mod_pow(g, mod - 1 - exp, mod));\r\n      --c;\r\n      pc /= p;\r\n    }\r\n\
    \    int k = pe - mod_inv(m, pe);\r\n    k = (k * m + 1) / pe;\r\n    ll y = mod_pow(b,\
    \ k, mod);\r\n    x = bt.mul(x, y);\r\n    return x;\r\n  };\r\n\r\n  auto pf\
    \ = factor(k);\r\n  for (auto&& [p, e]: pf) a = solve_pp(p, e, a);\r\n  return\
    \ a;\r\n}\r\n\r\nll mod_kth_root_64(ll k, ll a, ll mod) {\r\n  assert(primetest(mod)\
    \ && 0 <= a && a < mod);\r\n  if (k == 0) return (a == 1 ? 1 : -1);\r\n  if (a\
    \ == 0) return 0;\r\n  if (mod == 2) return a;\r\n  k %= mod - 1;\r\n\r\n  ll\
    \ g = gcd(k, mod - 1);\r\n  if (mod_pow_64(a, (mod - 1) / g, mod) != 1) return\
    \ -1;\r\n\r\n  ll c = mod_inv(k / g, (mod - 1) / g);\r\n  a = mod_pow_64(a, c,\
    \ mod);\r\n  k = i128(k) * c % (mod - 1);\r\n  if (k == 0) return 1;\r\n\r\n \
    \ g = primitive_root_64(mod);\r\n\r\n  auto solve_pp = [&](ll p, ll e, ll a) ->\
    \ ll {\r\n    ll f = 0;\r\n    ll pf = 1;\r\n    while (((mod - 1) / pf) % p ==\
    \ 0) ++f, pf *= p;\r\n    ll m = (mod - 1) / pf;\r\n    /*\r\n    \u30FB\u4F4D\
    \u6570 Qm \u306E\u5DE1\u56DE\u7FA4\r\n    \u30FBa \u306E p^e \u4E57\u6839\u3092\
    \u3068\u308A\u305F\u3044\u3002\u6301\u3064\u3053\u3068\u306F\u5206\u304B\u3063\
    \u3066\u3044\u308B\r\n    \u30FBa / x^{p^e} = b \u3092\u7DAD\u6301\u3059\u308B\
    \u3002\u307E\u305A\u306F\u3001b \u304C p \u3067\u5272\u308C\u308B\u56DE\u6570\u3092\
    \u5897\u3084\u3057\u3066\u3044\u304F\u3002\r\n    */\r\n    ll x = 1, b = a, c\
    \ = f - e; // b ^ {mp^c} = 1\r\n    ll pc = 1;\r\n    FOR(c) pc *= p;\r\n    ll\
    \ pe = 1;\r\n    FOR(e) pe *= p;\r\n    // \u5FC5\u8981\u306A\u3089\u3070\u539F\
    \u59CB p \u4E57\u6839\u306B\u95A2\u3059\u308B\u96E2\u6563\u5BFE\u6570\u554F\u984C\
    \u306E\u30BB\u30C3\u30C8\u30A2\u30C3\u30D7\r\n    ll G = mod_pow_64(g, (mod -\
    \ 1) / p, mod);\r\n    ll M = 0;\r\n    ll GM_inv = -1;\r\n    HashMap<ll> MP;\r\
    \n    if (c) {\r\n      while (M * M < p) ++M;\r\n      MP.build(M);\r\n     \
    \ ll Gpow = 1;\r\n      FOR(m, M) {\r\n        MP[Gpow] = m;\r\n        Gpow =\
    \ i128(Gpow) * G % mod;\r\n      }\r\n      GM_inv = mod_pow_64(Gpow, mod - 2,\
    \ mod);\r\n    }\r\n\r\n    while (c) {\r\n      /*\r\n      b^{mp^c} = 1 \u304C\
    \u5206\u304B\u3063\u3066\u3044\u308B\u3002(b/x^{p^e}})^{mp^{c-1}} = 1 \u306B\u3057\
    \u305F\u3044\u3002\r\n      x = g^{p^{f-c-e}*k} \u3068\u3057\u3066\u63A2\u3059\
    \u3002\u539F\u59CB p \u4E57\u6839 B, G \u306B\u5BFE\u3059\u308B B = G^k \u306B\
    \u5E30\u7740\u3002\r\n      */\r\n      ll B = mod_pow_64(b, pc / p * m, mod);\r\
    \n      ll k = [&](ll B) -> ll {\r\n        FOR(m, M + 1) {\r\n          if (MP.count(B))\
    \ return m * M + MP[B];\r\n          B = i128(B) * GM_inv % mod;\r\n        }\r\
    \n        return -1;\r\n      }(B);\r\n      x = i128(x) * mod_pow_64(g, pf /\
    \ pc / pe * k, mod) % mod;\r\n\r\n      ll exp = pf / pc * i128(k) % (mod - 1);\r\
    \n      b = i128(b) * mod_pow_64(g, mod - 1 - exp, mod) % mod;\r\n      --c;\r\
    \n      pc /= p;\r\n    }\r\n    ll k = pe - mod_inv(m, pe);\r\n    k = (i128(k)\
    \ * m + 1) / pe;\r\n    ll y = mod_pow_64(b, k, mod);\r\n    x = i128(x) * y %\
    \ mod;\r\n    return x;\r\n  };\r\n\r\n  auto pf = factor(k);\r\n  for (auto&&\
    \ [p, e]: pf) a = solve_pp(p, e, a);\r\n  return a;\r\n}\r\n"
  dependsOn:
  - nt/primetest.hpp
  - mod/mongomery_modint.hpp
  - mod/primitive_root.hpp
  - nt/factor.hpp
  - random/base.hpp
  - mod/mod_pow.hpp
  - mod/barrett.hpp
  - mod/mod_inv.hpp
  - ds/hashmap.hpp
  isVerificationFile: false
  path: mod/mod_kth_root.hpp
  requiredBy: []
  timestamp: '2025-01-20 22:41:37+09:00'
  verificationStatus: LIBRARY_ALL_WA
  verifiedWith:
  - test/2_library_checker/number_theory/kth_root_mod.test.cpp
documentation_of: mod/mod_kth_root.hpp
layout: document
redirect_from:
- /library/mod/mod_kth_root.hpp
- /library/mod/mod_kth_root.hpp.html
title: mod/mod_kth_root.hpp
---
