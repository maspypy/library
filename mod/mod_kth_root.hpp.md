---
data:
  _extendedDependsOn:
  - icon: ':question:'
    path: ds/hashmap.hpp
    title: ds/hashmap.hpp
  - icon: ':x:'
    path: mod/fast_div.hpp
    title: mod/fast_div.hpp
  - icon: ':question:'
    path: mod/mod_inv.hpp
    title: mod/mod_inv.hpp
  - icon: ':x:'
    path: mod/mod_pow.hpp
    title: mod/mod_pow.hpp
  - icon: ':x:'
    path: mod/primitive_root.hpp
    title: mod/primitive_root.hpp
  - icon: ':question:'
    path: nt/factor.hpp
    title: nt/factor.hpp
  - icon: ':question:'
    path: nt/primetest.hpp
    title: nt/primetest.hpp
  - icon: ':question:'
    path: random/base.hpp
    title: random/base.hpp
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':x:'
    path: test/library_checker/math/kth_root_mod.test.cpp
    title: test/library_checker/math/kth_root_mod.test.cpp
  _isVerificationFailed: true
  _pathExtension: hpp
  _verificationStatusIcon: ':x:'
  attributes:
    links: []
  bundledCode: "#line 2 \"nt/primetest.hpp\"\nstruct m64 {\r\n  using i64 = int64_t;\r\
    \n  using u64 = uint64_t;\r\n  using u128 = __uint128_t;\r\n\r\n  inline static\
    \ u64 m, r, n2; // r * m = -1 (mod 1<<64), n2 = 1<<128 (mod m)\r\n  static void\
    \ set_mod(u64 m) {\r\n    assert((m & 1) == 1);\r\n    m64::m = m;\r\n    n2 =\
    \ -u128(m) % m;\r\n    r = m;\r\n    FOR(_, 5) r *= 2 - m * r;\r\n    r = -r;\r\
    \n    assert(r * m == -1ull);\r\n  }\r\n  static u64 reduce(u128 b) { return (b\
    \ + u128(u64(b) * r) * m) >> 64; }\r\n\r\n  u64 x;\r\n  m64() : x(0) {}\r\n  m64(u64\
    \ x) : x(reduce(u128(x) * n2)){};\r\n  u64 val() const {\r\n    u64 y = reduce(x);\r\
    \n    return y >= m ? y - m : y;\r\n  }\r\n  m64 &operator+=(m64 y) {\r\n    x\
    \ += y.x - (m << 1);\r\n    x = (i64(x) < 0 ? x + (m << 1) : x);\r\n    return\
    \ *this;\r\n  }\r\n  m64 &operator-=(m64 y) {\r\n    x -= y.x;\r\n    x = (i64(x)\
    \ < 0 ? x + (m << 1) : x);\r\n    return *this;\r\n  }\r\n  m64 &operator*=(m64\
    \ y) {\r\n    x = reduce(u128(x) * y.x);\r\n    return *this;\r\n  }\r\n  m64\
    \ operator+(m64 y) const { return m64(*this) += y; }\r\n  m64 operator-(m64 y)\
    \ const { return m64(*this) -= y; }\r\n  m64 operator*(m64 y) const { return m64(*this)\
    \ *= y; }\r\n  bool operator==(m64 y) const {\r\n    return (x >= m ? x - m :\
    \ x) == (y.x >= m ? y.x - m : y.x);\r\n  }\r\n  bool operator!=(m64 y) const {\
    \ return not operator==(y); }\r\n  m64 pow(u64 n) const {\r\n    m64 y = 1, z\
    \ = *this;\r\n    for (; n; n >>= 1, z *= z)\r\n      if (n & 1) y *= z;\r\n \
    \   return y;\r\n  }\r\n};\r\n\r\nbool primetest(const uint64_t x) {\r\n  using\
    \ u64 = uint64_t;\r\n  if (x == 2 or x == 3 or x == 5 or x == 7) return true;\r\
    \n  if (x % 2 == 0 or x % 3 == 0 or x % 5 == 0 or x % 7 == 0) return false;\r\n\
    \  if (x < 121) return x > 1;\r\n  const u64 d = (x - 1) >> __builtin_ctzll(x\
    \ - 1);\r\n  m64::set_mod(x);\r\n  const m64 one(1), minus_one(x - 1);\r\n  auto\
    \ ok = [&](u64 a) {\r\n    auto y = m64(a).pow(d);\r\n    u64 t = d;\r\n    while\
    \ (y != one and y != minus_one and t != x - 1) y *= y, t <<= 1;\r\n    if (y !=\
    \ minus_one and t % 2 == 0) return false;\r\n    return true;\r\n  };\r\n  if\
    \ (x < (1ull << 32)) {\r\n    for (u64 a: {2, 7, 61})\r\n      if (not ok(a))\
    \ return false;\r\n  } else {\r\n    for (u64 a: {2, 325, 9375, 28178, 450775,\
    \ 9780504, 1795265022}) {\r\n      if (x <= a) return true;\r\n      if (not ok(a))\
    \ return false;\r\n    }\r\n  }\r\n  return true;\r\n}\n#line 2 \"mod/primitive_root.hpp\"\
    \n\r\n#line 3 \"nt/factor.hpp\"\n\nmt19937_64 rng_mt{random_device{}()};\nll rnd(ll\
    \ n) { return uniform_int_distribution<ll>(0, n - 1)(rng_mt); }\n\nll rho(ll n,\
    \ ll c) {\n  m64::set_mod(n);\n  assert(n > 1);\n  const m64 cc(c);\n  auto f\
    \ = [&](m64 x) { return x * x + cc; };\n  m64 x = 1, y = 2, z = 1, q = 1;\n  ll\
    \ g = 1;\n  const ll m = 1LL << (__lg(n) / 5); // ?\n  for (ll r = 1; g == 1;\
    \ r <<= 1) {\n    x = y;\n    FOR(_, r) y = f(y);\n    for (ll k = 0; k < r and\
    \ g == 1; k += m) {\n      z = y;\n      FOR(_, min(m, r - k)) y = f(y), q *=\
    \ x - y;\n      g = gcd(q.val(), n);\n    }\n  }\n  if (g == n) do {\n      z\
    \ = f(z);\n      g = gcd((x - z).val(), n);\n    } while (g == 1);\n  return g;\n\
    }\n\nll find_prime_factor(ll n) {\n  assert(n > 1);\n  if (primetest(n)) return\
    \ n;\n  FOR(_, 100) {\n    ll m = rho(n, rnd(n));\n    if (primetest(m)) return\
    \ m;\n    n = m;\n  }\n  cerr << \"failed\" << endl;\n  assert(false);\n  return\
    \ -1;\n}\n\n// \u30BD\u30FC\u30C8\u3057\u3066\u304F\u308C\u308B\nvc<pair<ll, int>>\
    \ factor(ll n) {\n  assert(n >= 1);\n  vc<pair<ll, int>> pf;\n  FOR3(p, 2, 100)\
    \ {\n    if (p * p > n) break;\n    if (n % p == 0) {\n      ll e = 0;\n     \
    \ do { n /= p, e += 1; } while (n % p == 0);\n      pf.eb(p, e);\n    }\n  }\n\
    \  while (n > 1) {\n    ll p = find_prime_factor(n);\n    ll e = 0;\n    do {\
    \ n /= p, e += 1; } while (n % p == 0);\n    pf.eb(p, e);\n  }\n  sort(all(pf));\n\
    \  return pf;\n}\n\nvc<pair<ll, int>> factor_by_lpf(ll n, vc<int>& lpf) {\n  vc<pair<ll,\
    \ int>> res;\n  while (n > 1) {\n    int p = lpf[n];\n    int e = 0;\n    while\
    \ (n % p == 0) {\n      n /= p;\n      ++e;\n    }\n    res.eb(p, e);\n  }\n \
    \ return res;\n}\n#line 2 \"mod/fast_div.hpp\"\nstruct fast_div {\r\n  // Min25\
    \ https://judge.yosupo.jp/submission/46090\r\n  // \u540C\u3058\u5B9A\u6570\u3067\
    \u4F55\u5EA6\u3082\u9664\u7B97\u3059\u308B\u3068\u304D\u306E\u9AD8\u901F\u5316\
    \u306B\u4F7F\u3048\u308B\r\n  using i64 = long long;\r\n  using u64 = unsigned\
    \ long long;\r\n  using u128 = __uint128_t;\r\n  constexpr fast_div() : m(), s(),\
    \ x() {}\r\n  constexpr fast_div(int n)\r\n      : m(n), s(std::__lg(n - 1)),\
    \ x(((u128(1) << (s + 64)) + n - 1) / n) {}\r\n  constexpr friend u64 operator/(u64\
    \ n, const fast_div& d) {\r\n    return (u128(n) * d.x >> d.s) >> 64;\r\n  }\r\
    \n  constexpr friend int operator%(u64 n, const fast_div& d) {\r\n    return n\
    \ - n / d * d.m;\r\n  }\r\n  constexpr std::pair<i64, int> divmod(u64 n) const\
    \ {\r\n    u64 q = n / *this;\r\n    return {q, n - q * m};\r\n  }\r\n\r\n  int\
    \ m;\r\n  int s;\r\n  u64 x;\r\n};\r\n#line 3 \"mod/mod_pow.hpp\"\n// int\r\n\
    ll mod_pow(ll a, ll n, int mod){\r\n  fast_div fd(mod);\r\n  a = a % fd;\r\n \
    \ ll p = a;\r\n  ll v = 1;\r\n  while(n){\r\n    if(n & 1) v = v * p % fd;\r\n\
    \    p = p * p % fd;\r\n    n >>= 1;\r\n  }\r\n  return v;\r\n}\r\n\r\nll mod_pow_long(ll\
    \ a, ll n, ll mod){\r\n  a %= mod;\r\n  ll p = a;\r\n  ll v = 1;\r\n  while(n){\r\
    \n    if(n & 1) v = i128(v) * p % mod;\r\n    p = i128(p) * p % mod;\r\n    n\
    \ >>= 1;\r\n  }\r\n  return v;\r\n}\r\n#line 2 \"random/base.hpp\"\n\nu64 RNG_64()\
    \ {\n  static uint64_t x_\n      = uint64_t(chrono::duration_cast<chrono::nanoseconds>(\n\
    \                     chrono::high_resolution_clock::now().time_since_epoch())\n\
    \                     .count())\n        * 10150724397891781847ULL;\n  x_ ^= x_\
    \ << 7;\n  return x_ ^= x_ >> 9;\n}\n\nu64 RNG(u64 lim) { return RNG_64() % lim;\
    \ }\n\nll RNG(ll l, ll r) { return l + RNG_64() % (r - l); }\n#line 6 \"mod/primitive_root.hpp\"\
    \n\r\n// int\r\nint primitive_root(int p) {\r\n  auto pf = factor(p - 1);\r\n\
    \  auto is_ok = [&](int g) -> bool {\r\n    for (auto&& [q, e]: pf)\r\n      if\
    \ (mod_pow(g, (p - 1) / q, p) == 1) return false;\r\n    return true;\r\n  };\r\
    \n  FOR3(x, 1, p) {\r\n    if (is_ok(x)) return x;\r\n  }\r\n  return -1;\r\n\
    }\r\n\r\nll primitive_root_long(ll p) {\r\n  auto pf = factor(p - 1);\r\n  auto\
    \ is_ok = [&](ll g) -> bool {\r\n    for (auto&& [q, e]: pf)\r\n      if (mod_pow_long(g,\
    \ (p - 1) / q, p) == 1) return false;\r\n    return true;\r\n  };\r\n  while (1)\
    \ {\r\n    ll x = RNG(1, p);\r\n    if (is_ok(x)) return x;\r\n  }\r\n  return\
    \ -1;\r\n}\r\n#line 2 \"mod/mod_inv.hpp\"\n// long \u3067\u3082\u5927\u4E08\u592B\
    \r\nll mod_inv(ll val, ll mod) {\r\n  val %= mod;\r\n  if (val < 0) val += mod;\r\
    \n  ll a = val, b = mod, u = 1, v = 0, t;\r\n  while (b > 0) {\r\n    t = a /\
    \ b;\r\n    swap(a -= t * b, b), swap(u -= t * v, v);\r\n  }\r\n  if (u < 0) u\
    \ += mod;\r\n  return u;\r\n}\r\n#line 3 \"ds/hashmap.hpp\"\n\r\n// u64 -> Val\r\
    \ntemplate <typename Val, int LOG = 20>\r\nstruct HashMap {\r\n  int N;\r\n  u64*\
    \ keys;\r\n  Val* vals;\r\n  vc<int> IDS;\r\n  bitset<1 << LOG> used;\r\n  const\
    \ int shift;\r\n  const u64 r = 11995408973635179863ULL;\r\n  HashMap()\r\n  \
    \    : N(1 << LOG), keys(new u64[N]), vals(new Val[N]), shift(64 - __lg(N)) {}\r\
    \n  int hash(ll x) {\r\n    static const u64 FIXED_RANDOM\r\n        = std::chrono::steady_clock::now().time_since_epoch().count();\r\
    \n    return (u64(x + FIXED_RANDOM) * r) >> shift;\r\n  }\r\n\r\n  int index(const\
    \ u64& key) {\r\n    int i = 0;\r\n    for (i = hash(key); used[i] && keys[i]\
    \ != key; (i += 1) &= (N - 1)) {}\r\n    return i;\r\n  }\r\n\r\n  // [] \u3057\
    \u305F\u6642\u70B9\u3067\u8981\u7D20\u306F\u4F5C\u3089\u308C\u308B\r\n  Val& operator[](const\
    \ u64& key) {\r\n    int i = index(key);\r\n    if (!used[i]) IDS.eb(i), used[i]\
    \ = 1, keys[i] = key, vals[i] = Val{};\r\n    return vals[i];\r\n  }\r\n\r\n \
    \ Val get(const u64& key, Val default_value) {\r\n    int i = index(key);\r\n\
    \    if (!used[i]) return default_value;\r\n    return vals[i];\r\n  }\r\n\r\n\
    \  bool count(const u64& key) {\r\n    int i = index(key);\r\n    return used[i]\
    \ && keys[i] == key;\r\n  }\r\n\r\n  void reset() {\r\n    for (auto&& i: IDS)\
    \ used[i] = 0;\r\n    IDS.clear();\r\n  }\r\n\r\n  // f(key, val)\r\n  template\
    \ <typename F>\r\n  void enumerate_all(F f) {\r\n    for (auto&& i: IDS) f(keys[i],\
    \ vals[i]);\r\n  }\r\n};\r\n#line 5 \"mod/mod_kth_root.hpp\"\n\r\n// mod \u306F\
    \ int\r\nint mod_kth_root(ll k, ll a, int mod) {\r\n  assert(primetest(mod) &&\
    \ 0 <= a && a < mod);\r\n  if (k == 0) return (a == 1 ? 1 : -1);\r\n  if (a ==\
    \ 0) return 0;\r\n  if (mod == 2) return a;\r\n  k %= mod - 1;\r\n  fast_div fd(mod);\r\
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
    \ / p, mod);\r\n    int M = 0;\r\n    unordered_map<ll, int> MP;\r\n    ll GM_inv\
    \ = -1;\r\n    if (c) {\r\n      while (M * M < p) ++M;\r\n      MP.reserve(M\
    \ + 1);\r\n      ll Gpow = 1;\r\n      FOR(m, M) {\r\n        MP[Gpow] = m;\r\n\
    \        Gpow = Gpow * G % fd;\r\n      }\r\n      GM_inv = mod_pow(Gpow, mod\
    \ - 2, mod);\r\n    }\r\n\r\n    while (c) {\r\n      /*\r\n      b^{mp^c} = 1\
    \ \u304C\u5206\u304B\u3063\u3066\u3044\u308B\u3002(b/x^{p^e}})^{mp^{c-1}} = 1\
    \ \u306B\u3057\u305F\u3044\u3002\r\n      x = g^{p^{f-c-e}*k} \u3068\u3057\u3066\
    \u63A2\u3059\u3002\u539F\u59CB p \u4E57\u6839 B, G \u306B\u5BFE\u3059\u308B B\
    \ = G^k \u306B\u5E30\u7740\u3002\r\n      */\r\n      ll B = mod_pow(b, m * pc\
    \ / p, mod);\r\n      int k = [&](ll B) -> int {\r\n        FOR(m, M + 1) {\r\n\
    \          if (MP.count(B)) return m * M + MP[B];\r\n          B = B * GM_inv\
    \ % fd;\r\n        }\r\n        return -1;\r\n      }(B);\r\n      x = x * mod_pow(g,\
    \ pf / pc / pe * k, mod) % fd;\r\n      ll exp = pf / pc * k % (mod - 1);\r\n\
    \      b = b * mod_pow(g, mod - 1 - exp, mod) % fd;\r\n      --c;\r\n      pc\
    \ /= p;\r\n    }\r\n    int k = pe - mod_inv(m, pe);\r\n    k = (k * m + 1) /\
    \ pe;\r\n    ll y = mod_pow(b, k, mod);\r\n    x = x * y % fd;\r\n    return x;\r\
    \n  };\r\n\r\n  auto pf = factor(k);\r\n  for (auto&& [p, e]: pf) a = solve_pp(p,\
    \ e, a);\r\n  return a;\r\n}\r\n\r\nll mod_kth_root_long(ll k, ll a, ll mod) {\r\
    \n  static HashMap<ll, 20> MP;\r\n\r\n  assert(primetest(mod) && 0 <= a && a <\
    \ mod);\r\n  if (k == 0) return (a == 1 ? 1 : -1);\r\n  if (a == 0) return 0;\r\
    \n  if (mod == 2) return a;\r\n  k %= mod - 1;\r\n\r\n  ll g = gcd(k, mod - 1);\r\
    \n  if (mod_pow_long(a, (mod - 1) / g, mod) != 1) return -1;\r\n\r\n  ll c = mod_inv(k\
    \ / g, (mod - 1) / g);\r\n  a = mod_pow_long(a, c, mod);\r\n  k = i128(k) * c\
    \ % (mod - 1);\r\n  if (k == 0) return 1;\r\n\r\n  g = primitive_root_long(mod);\r\
    \n\r\n  auto solve_pp = [&](ll p, ll e, ll a) -> ll {\r\n    ll f = 0;\r\n   \
    \ ll pf = 1;\r\n    while (((mod - 1) / pf) % p == 0) ++f, pf *= p;\r\n    ll\
    \ m = (mod - 1) / pf;\r\n    /*\r\n    \u30FB\u4F4D\u6570 Qm \u306E\u5DE1\u56DE\
    \u7FA4\r\n    \u30FBa \u306E p^e \u4E57\u6839\u3092\u3068\u308A\u305F\u3044\u3002\
    \u6301\u3064\u3053\u3068\u306F\u5206\u304B\u3063\u3066\u3044\u308B\r\n    \u30FB\
    a / x^{p^e} = b \u3092\u7DAD\u6301\u3059\u308B\u3002\u307E\u305A\u306F\u3001b\
    \ \u304C p \u3067\u5272\u308C\u308B\u56DE\u6570\u3092\u5897\u3084\u3057\u3066\u3044\
    \u304F\u3002\r\n    */\r\n    ll x = 1, b = a, c = f - e; // b ^ {mp^c} = 1\r\n\
    \    ll pc = 1;\r\n    FOR(c) pc *= p;\r\n    ll pe = 1;\r\n    FOR(e) pe *= p;\r\
    \n    // \u5FC5\u8981\u306A\u3089\u3070\u539F\u59CB p \u4E57\u6839\u306B\u95A2\
    \u3059\u308B\u96E2\u6563\u5BFE\u6570\u554F\u984C\u306E\u30BB\u30C3\u30C8\u30A2\
    \u30C3\u30D7\r\n    ll G = mod_pow_long(g, (mod - 1) / p, mod);\r\n    ll M =\
    \ 0;\r\n    ll GM_inv = -1;\r\n    if (c) {\r\n      while (M * M < p) ++M;\r\n\
    \      MP.reset();\r\n      ll Gpow = 1;\r\n      FOR(m, M) {\r\n        MP[Gpow]\
    \ = m;\r\n        Gpow = i128(Gpow) * G % mod;\r\n      }\r\n      GM_inv = mod_pow_long(Gpow,\
    \ mod - 2, mod);\r\n    }\r\n\r\n    while (c) {\r\n      /*\r\n      b^{mp^c}\
    \ = 1 \u304C\u5206\u304B\u3063\u3066\u3044\u308B\u3002(b/x^{p^e}})^{mp^{c-1}}\
    \ = 1 \u306B\u3057\u305F\u3044\u3002\r\n      x = g^{p^{f-c-e}*k} \u3068\u3057\
    \u3066\u63A2\u3059\u3002\u539F\u59CB p \u4E57\u6839 B, G \u306B\u5BFE\u3059\u308B\
    \ B = G^k \u306B\u5E30\u7740\u3002\r\n      */\r\n      ll B = mod_pow_long(b,\
    \ pc / p * m, mod);\r\n      ll k = [&](ll B) -> ll {\r\n        FOR(m, M + 1)\
    \ {\r\n          if (MP.count(B)) return m * M + MP[B];\r\n          B = i128(B)\
    \ * GM_inv % mod;\r\n        }\r\n        return -1;\r\n      }(B);\r\n      x\
    \ = i128(x) * mod_pow_long(g, pf / pc / pe * k, mod) % mod;\r\n\r\n      ll exp\
    \ = pf / pc * i128(k) % (mod - 1);\r\n      b = i128(b) * mod_pow_long(g, mod\
    \ - 1 - exp, mod) % mod;\r\n      --c;\r\n      pc /= p;\r\n    }\r\n    ll k\
    \ = pe - mod_inv(m, pe);\r\n    k = (i128(k) * m + 1) / pe;\r\n    ll y = mod_pow_long(b,\
    \ k, mod);\r\n    x = i128(x) * y % mod;\r\n    return x;\r\n  };\r\n\r\n  auto\
    \ pf = factor(k);\r\n  for (auto&& [p, e]: pf) a = solve_pp(p, e, a);\r\n  return\
    \ a;\r\n}\r\n"
  code: "#include \"nt/primetest.hpp\"\r\n#include \"mod/primitive_root.hpp\"\r\n\
    #include \"mod/mod_inv.hpp\"\r\n#include \"ds/hashmap.hpp\"\r\n\r\n// mod \u306F\
    \ int\r\nint mod_kth_root(ll k, ll a, int mod) {\r\n  assert(primetest(mod) &&\
    \ 0 <= a && a < mod);\r\n  if (k == 0) return (a == 1 ? 1 : -1);\r\n  if (a ==\
    \ 0) return 0;\r\n  if (mod == 2) return a;\r\n  k %= mod - 1;\r\n  fast_div fd(mod);\r\
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
    \ / p, mod);\r\n    int M = 0;\r\n    unordered_map<ll, int> MP;\r\n    ll GM_inv\
    \ = -1;\r\n    if (c) {\r\n      while (M * M < p) ++M;\r\n      MP.reserve(M\
    \ + 1);\r\n      ll Gpow = 1;\r\n      FOR(m, M) {\r\n        MP[Gpow] = m;\r\n\
    \        Gpow = Gpow * G % fd;\r\n      }\r\n      GM_inv = mod_pow(Gpow, mod\
    \ - 2, mod);\r\n    }\r\n\r\n    while (c) {\r\n      /*\r\n      b^{mp^c} = 1\
    \ \u304C\u5206\u304B\u3063\u3066\u3044\u308B\u3002(b/x^{p^e}})^{mp^{c-1}} = 1\
    \ \u306B\u3057\u305F\u3044\u3002\r\n      x = g^{p^{f-c-e}*k} \u3068\u3057\u3066\
    \u63A2\u3059\u3002\u539F\u59CB p \u4E57\u6839 B, G \u306B\u5BFE\u3059\u308B B\
    \ = G^k \u306B\u5E30\u7740\u3002\r\n      */\r\n      ll B = mod_pow(b, m * pc\
    \ / p, mod);\r\n      int k = [&](ll B) -> int {\r\n        FOR(m, M + 1) {\r\n\
    \          if (MP.count(B)) return m * M + MP[B];\r\n          B = B * GM_inv\
    \ % fd;\r\n        }\r\n        return -1;\r\n      }(B);\r\n      x = x * mod_pow(g,\
    \ pf / pc / pe * k, mod) % fd;\r\n      ll exp = pf / pc * k % (mod - 1);\r\n\
    \      b = b * mod_pow(g, mod - 1 - exp, mod) % fd;\r\n      --c;\r\n      pc\
    \ /= p;\r\n    }\r\n    int k = pe - mod_inv(m, pe);\r\n    k = (k * m + 1) /\
    \ pe;\r\n    ll y = mod_pow(b, k, mod);\r\n    x = x * y % fd;\r\n    return x;\r\
    \n  };\r\n\r\n  auto pf = factor(k);\r\n  for (auto&& [p, e]: pf) a = solve_pp(p,\
    \ e, a);\r\n  return a;\r\n}\r\n\r\nll mod_kth_root_long(ll k, ll a, ll mod) {\r\
    \n  static HashMap<ll, 20> MP;\r\n\r\n  assert(primetest(mod) && 0 <= a && a <\
    \ mod);\r\n  if (k == 0) return (a == 1 ? 1 : -1);\r\n  if (a == 0) return 0;\r\
    \n  if (mod == 2) return a;\r\n  k %= mod - 1;\r\n\r\n  ll g = gcd(k, mod - 1);\r\
    \n  if (mod_pow_long(a, (mod - 1) / g, mod) != 1) return -1;\r\n\r\n  ll c = mod_inv(k\
    \ / g, (mod - 1) / g);\r\n  a = mod_pow_long(a, c, mod);\r\n  k = i128(k) * c\
    \ % (mod - 1);\r\n  if (k == 0) return 1;\r\n\r\n  g = primitive_root_long(mod);\r\
    \n\r\n  auto solve_pp = [&](ll p, ll e, ll a) -> ll {\r\n    ll f = 0;\r\n   \
    \ ll pf = 1;\r\n    while (((mod - 1) / pf) % p == 0) ++f, pf *= p;\r\n    ll\
    \ m = (mod - 1) / pf;\r\n    /*\r\n    \u30FB\u4F4D\u6570 Qm \u306E\u5DE1\u56DE\
    \u7FA4\r\n    \u30FBa \u306E p^e \u4E57\u6839\u3092\u3068\u308A\u305F\u3044\u3002\
    \u6301\u3064\u3053\u3068\u306F\u5206\u304B\u3063\u3066\u3044\u308B\r\n    \u30FB\
    a / x^{p^e} = b \u3092\u7DAD\u6301\u3059\u308B\u3002\u307E\u305A\u306F\u3001b\
    \ \u304C p \u3067\u5272\u308C\u308B\u56DE\u6570\u3092\u5897\u3084\u3057\u3066\u3044\
    \u304F\u3002\r\n    */\r\n    ll x = 1, b = a, c = f - e; // b ^ {mp^c} = 1\r\n\
    \    ll pc = 1;\r\n    FOR(c) pc *= p;\r\n    ll pe = 1;\r\n    FOR(e) pe *= p;\r\
    \n    // \u5FC5\u8981\u306A\u3089\u3070\u539F\u59CB p \u4E57\u6839\u306B\u95A2\
    \u3059\u308B\u96E2\u6563\u5BFE\u6570\u554F\u984C\u306E\u30BB\u30C3\u30C8\u30A2\
    \u30C3\u30D7\r\n    ll G = mod_pow_long(g, (mod - 1) / p, mod);\r\n    ll M =\
    \ 0;\r\n    ll GM_inv = -1;\r\n    if (c) {\r\n      while (M * M < p) ++M;\r\n\
    \      MP.reset();\r\n      ll Gpow = 1;\r\n      FOR(m, M) {\r\n        MP[Gpow]\
    \ = m;\r\n        Gpow = i128(Gpow) * G % mod;\r\n      }\r\n      GM_inv = mod_pow_long(Gpow,\
    \ mod - 2, mod);\r\n    }\r\n\r\n    while (c) {\r\n      /*\r\n      b^{mp^c}\
    \ = 1 \u304C\u5206\u304B\u3063\u3066\u3044\u308B\u3002(b/x^{p^e}})^{mp^{c-1}}\
    \ = 1 \u306B\u3057\u305F\u3044\u3002\r\n      x = g^{p^{f-c-e}*k} \u3068\u3057\
    \u3066\u63A2\u3059\u3002\u539F\u59CB p \u4E57\u6839 B, G \u306B\u5BFE\u3059\u308B\
    \ B = G^k \u306B\u5E30\u7740\u3002\r\n      */\r\n      ll B = mod_pow_long(b,\
    \ pc / p * m, mod);\r\n      ll k = [&](ll B) -> ll {\r\n        FOR(m, M + 1)\
    \ {\r\n          if (MP.count(B)) return m * M + MP[B];\r\n          B = i128(B)\
    \ * GM_inv % mod;\r\n        }\r\n        return -1;\r\n      }(B);\r\n      x\
    \ = i128(x) * mod_pow_long(g, pf / pc / pe * k, mod) % mod;\r\n\r\n      ll exp\
    \ = pf / pc * i128(k) % (mod - 1);\r\n      b = i128(b) * mod_pow_long(g, mod\
    \ - 1 - exp, mod) % mod;\r\n      --c;\r\n      pc /= p;\r\n    }\r\n    ll k\
    \ = pe - mod_inv(m, pe);\r\n    k = (i128(k) * m + 1) / pe;\r\n    ll y = mod_pow_long(b,\
    \ k, mod);\r\n    x = i128(x) * y % mod;\r\n    return x;\r\n  };\r\n\r\n  auto\
    \ pf = factor(k);\r\n  for (auto&& [p, e]: pf) a = solve_pp(p, e, a);\r\n  return\
    \ a;\r\n}\r\n"
  dependsOn:
  - nt/primetest.hpp
  - mod/primitive_root.hpp
  - nt/factor.hpp
  - mod/mod_pow.hpp
  - mod/fast_div.hpp
  - random/base.hpp
  - mod/mod_inv.hpp
  - ds/hashmap.hpp
  isVerificationFile: false
  path: mod/mod_kth_root.hpp
  requiredBy: []
  timestamp: '2023-01-31 21:59:51+09:00'
  verificationStatus: LIBRARY_ALL_WA
  verifiedWith:
  - test/library_checker/math/kth_root_mod.test.cpp
documentation_of: mod/mod_kth_root.hpp
layout: document
redirect_from:
- /library/mod/mod_kth_root.hpp
- /library/mod/mod_kth_root.hpp.html
title: mod/mod_kth_root.hpp
---
