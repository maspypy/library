---
data:
  _extendedDependsOn:
  - icon: ':question:'
    path: mod/barrett.hpp
    title: mod/barrett.hpp
  - icon: ':question:'
    path: mod/mod_inv.hpp
    title: mod/mod_inv.hpp
  - icon: ':question:'
    path: mod/mod_pow.hpp
    title: mod/mod_pow.hpp
  - icon: ':question:'
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
  - icon: ':heavy_check_mark:'
    path: test/library_checker/math/binomial_coefficient.test.cpp
    title: test/library_checker/math/binomial_coefficient.test.cpp
  - icon: ':x:'
    path: test/yukicoder/2120.test.cpp
    title: test/yukicoder/2120.test.cpp
  - icon: ':x:'
    path: test/yukicoder/2181.test.cpp
    title: test/yukicoder/2181.test.cpp
  _isVerificationFailed: true
  _pathExtension: hpp
  _verificationStatusIcon: ':question:'
  attributes:
    links: []
  bundledCode: "#line 2 \"mod/primitive_root.hpp\"\n\r\n#line 2 \"nt/primetest.hpp\"\
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
    \ return res;\n}\n#line 2 \"mod/barrett.hpp\"\n\n// https://github.com/atcoder/ac-library/blob/master/atcoder/internal_math.hpp\n\
    struct Barrett {\n  u32 m;\n  u64 im;\n  explicit Barrett(u32 m = 1) : m(m), im(u64(-1)\
    \ / m + 1) {}\n  u32 umod() const { return m; }\n  u32 modulo(u64 z) {\n    if\
    \ (m == 1) return z;\n    u64 x = (u64)(((unsigned __int128)(z)*im) >> 64);\n\
    \    u64 y = x * m;\n    return (z - y + (z < y ? m : 0));\n  }\n  u64 floor(u64\
    \ z) {\n    if (m == 1) return z;\n    u64 x = (u64)(((unsigned __int128)(z)*im)\
    \ >> 64);\n    u64 y = x * m;\n    return (z < y ? x - 1 : x);\n  }\n  pair<u64,\
    \ u32> divmod(u64 z) {\n    if (m == 1) return {z, 0};\n    u64 x = (u64)(((unsigned\
    \ __int128)(z)*im) >> 64);\n    u64 y = x * m;\n    if (z < y) return {x - 1,\
    \ z - y + m};\n    return {x, z - y};\n  }\n  u32 mul(u32 a, u32 b) { return modulo(u64(a)\
    \ * b); }\n};\n#line 3 \"mod/mod_pow.hpp\"\n\r\n// int\r\nll mod_pow(ll a, ll\
    \ n, int mod) {\r\n  a %= mod;\r\n  Barrett bt(mod);\r\n  ll p = a;\r\n  ll v\
    \ = 1;\r\n  while (n) {\r\n    if (n & 1) v = bt.mul(v, p);\r\n    p = bt.mul(p,\
    \ p);\r\n    n >>= 1;\r\n  }\r\n  return v;\r\n}\r\n\r\nll mod_pow_long(ll a,\
    \ ll n, ll mod) {\r\n  a %= mod;\r\n  ll p = a;\r\n  ll v = 1;\r\n  while (n)\
    \ {\r\n    if (n & 1) v = i128(v) * p % mod;\r\n    p = i128(p) * p % mod;\r\n\
    \    n >>= 1;\r\n  }\r\n  return v;\r\n}\r\n#line 2 \"random/base.hpp\"\n\nu64\
    \ RNG_64() {\n  static uint64_t x_\n      = uint64_t(chrono::duration_cast<chrono::nanoseconds>(\n\
    \                     chrono::high_resolution_clock::now().time_since_epoch())\n\
    \                     .count())\n        * 10150724397891781847ULL;\n  x_ ^= x_\
    \ << 7;\n  return x_ ^= x_ >> 9;\n}\n\nu64 RNG(u64 lim) { return RNG_64() % lim;\
    \ }\n\nll RNG(ll l, ll r) { return l + RNG_64() % (r - l); }\n#line 6 \"mod/primitive_root.hpp\"\
    \n\r\n// int\r\nint primitive_root(int p) {\r\n  auto pf = factor(p - 1);\r\n\
    \  auto is_ok = [&](int g) -> bool {\r\n    for (auto&& [q, e]: pf)\r\n      if\
    \ (mod_pow(g, (p - 1) / q, p) == 1) return false;\r\n    return true;\r\n  };\r\
    \n  while (1) {\r\n    int x = RNG(1, p);\r\n    if (is_ok(x)) return x;\r\n \
    \ }\r\n  return -1;\r\n}\r\n\r\nll primitive_root_long(ll p) {\r\n  auto pf =\
    \ factor(p - 1);\r\n  auto is_ok = [&](ll g) -> bool {\r\n    for (auto&& [q,\
    \ e]: pf)\r\n      if (mod_pow_long(g, (p - 1) / q, p) == 1) return false;\r\n\
    \    return true;\r\n  };\r\n  while (1) {\r\n    ll x = RNG(1, p);\r\n    if\
    \ (is_ok(x)) return x;\r\n  }\r\n  return -1;\r\n}\r\n#line 2 \"mod/mod_inv.hpp\"\
    \n// long \u3067\u3082\u5927\u4E08\u592B\r\nll mod_inv(ll val, ll mod) {\r\n \
    \ val %= mod;\r\n  if (val < 0) val += mod;\r\n  ll a = val, b = mod, u = 1, v\
    \ = 0, t;\r\n  while (b > 0) {\r\n    t = a / b;\r\n    swap(a -= t * b, b), swap(u\
    \ -= t * v, v);\r\n  }\r\n  if (u < 0) u += mod;\r\n  return u;\r\n}\r\n#line\
    \ 3 \"mod/binomial.hpp\"\n\r\nstruct Binomial_PrimePower {\r\n  int p, e;\r\n\
    \  int pp;\r\n  int root;\r\n  int ord;\r\n  vc<int> exp;\r\n  vc<int> log_fact;\r\
    \n  vc<int> power;\r\n  Barrett bt_p, bt_pp;\r\n\r\n  Binomial_PrimePower(int\
    \ p, int e) : p(p), e(e), power(e + 1, 1) {\r\n    FOR(i, e) power[i + 1] = power[i]\
    \ * p;\r\n    pp = power[e];\r\n    bt_p = Barrett(p), bt_pp = Barrett(pp);\r\n\
    \    vc<int> log;\r\n    if (p == 2) {\r\n      if (e <= 1) { return; }\r\n  \
    \    root = 5;\r\n      ord = pp / 4;\r\n      exp.assign(ord, 1);\r\n      log.assign(pp,\
    \ 0);\r\n      FOR(i, ord - 1) { exp[i + 1] = (exp[i] * root) & (pp - 1); }\r\n\
    \      FOR(i, ord) log[exp[i]] = log[pp - exp[i]] = i;\r\n    } else {\r\n   \
    \   root = primitive_root(p);\r\n      ord = pp / p * (p - 1);\r\n      exp.assign(ord,\
    \ 1);\r\n      log.assign(pp, 0);\r\n      FOR(i, ord - 1) { exp[i + 1] = bt_pp.mul(exp[i],\
    \ root); }\r\n      FOR(i, ord) log[exp[i]] = i;\r\n    }\r\n    log_fact.assign(pp,\
    \ 0);\r\n    FOR(i, 1, pp) {\r\n      log_fact[i] = log_fact[i - 1] + log[i];\r\
    \n      if (log_fact[i] >= ord) log_fact[i] -= ord;\r\n    }\r\n  }\r\n\r\n  int\
    \ C(ll n, ll i) {\r\n    assert(n >= 0);\r\n    if (i < 0 || i > n) return 0;\r\
    \n    ll a = i, b = n - i;\r\n    if (pp == 2) { return ((a & b) == 0 ? 1 : 0);\
    \ }\r\n    int log = 0, cnt_p = 0, sgn = 0;\r\n    if (e > 1) {\r\n      while\
    \ (n && cnt_p < e) {\r\n        auto [n1, nr1] = bt_pp.divmod(n);\r\n        auto\
    \ [a1, ar1] = bt_pp.divmod(a);\r\n        auto [b1, br1] = bt_pp.divmod(b);\r\n\
    \        log += log_fact[nr1] - log_fact[ar1] - log_fact[br1];\r\n        if (p\
    \ > 2) {\r\n          sgn += (n1 & 1) + (a1 & 1) + (b1 & 1);\r\n        } else\
    \ {\r\n          sgn += (((nr1 + 1) & 4) + ((ar1 + 1) & 4) + ((br1 + 1) & 4))\
    \ / 4;\r\n        }\r\n        n = bt_p.floor(n), a = bt_p.floor(a), b = bt_p.floor(b);\r\
    \n        cnt_p += n - a - b;\r\n      }\r\n    } else {\r\n      while (n &&\
    \ cnt_p < e) {\r\n        auto [n1, nr1] = bt_pp.divmod(n);\r\n        auto [a1,\
    \ ar1] = bt_pp.divmod(a);\r\n        auto [b1, br1] = bt_pp.divmod(b);\r\n   \
    \     log += log_fact[nr1] - log_fact[ar1] - log_fact[br1];\r\n        if (p >\
    \ 2) {\r\n          sgn += (n1 & 1) + (a1 & 1) + (b1 & 1);\r\n        } else {\r\
    \n          sgn += ((nr1 + 1) >> 2 & 1) + ((ar1 + 1) >> 2 & 1)\r\n           \
    \      + ((br1 + 1) >> 2 & 1);\r\n        }\r\n        n = n1, a = a1, b = b1;\r\
    \n        cnt_p += n - a - b;\r\n      }\r\n    }\r\n    if (cnt_p >= e) return\
    \ 0;\r\n    log %= ord;\r\n    if (log < 0) log += ord;\r\n    int res = exp[log];\r\
    \n    if (sgn & 1) res = pp - res;\r\n    return bt_pp.mul(power[cnt_p], res);\r\
    \n  }\r\n};\r\n\r\nstruct Binomial {\r\n  int mod;\r\n  vc<Binomial_PrimePower>\
    \ BPP;\r\n  vc<int> crt_coef;\r\n  Barrett bt;\r\n\r\n  Binomial(int mod) : mod(mod),\
    \ bt(mod) {\r\n    for (auto&& [p, e]: factor(mod)) {\r\n      int pp = 1;\r\n\
    \      FOR(e) pp *= p;\r\n      BPP.eb(Binomial_PrimePower(p, e));\r\n      int\
    \ other = mod / pp;\r\n      crt_coef.eb(ll(other) * mod_inv(other, pp) % mod);\r\
    \n    }\r\n  }\r\n\r\n  int C(ll n, ll k) {\r\n    assert(n >= 0);\r\n    if (k\
    \ < 0 || k > n) return 0;\r\n    int ANS = 0;\r\n    FOR(s, len(crt_coef)) {\r\
    \n      ANS = bt.modulo(ANS + u64(BPP[s].C(n, k)) * crt_coef[s]);\r\n    }\r\n\
    \    return ANS;\r\n  }\r\n};\n"
  code: "#include \"mod/primitive_root.hpp\"\r\n#include \"mod/mod_inv.hpp\"\r\n\r\
    \nstruct Binomial_PrimePower {\r\n  int p, e;\r\n  int pp;\r\n  int root;\r\n\
    \  int ord;\r\n  vc<int> exp;\r\n  vc<int> log_fact;\r\n  vc<int> power;\r\n \
    \ Barrett bt_p, bt_pp;\r\n\r\n  Binomial_PrimePower(int p, int e) : p(p), e(e),\
    \ power(e + 1, 1) {\r\n    FOR(i, e) power[i + 1] = power[i] * p;\r\n    pp =\
    \ power[e];\r\n    bt_p = Barrett(p), bt_pp = Barrett(pp);\r\n    vc<int> log;\r\
    \n    if (p == 2) {\r\n      if (e <= 1) { return; }\r\n      root = 5;\r\n  \
    \    ord = pp / 4;\r\n      exp.assign(ord, 1);\r\n      log.assign(pp, 0);\r\n\
    \      FOR(i, ord - 1) { exp[i + 1] = (exp[i] * root) & (pp - 1); }\r\n      FOR(i,\
    \ ord) log[exp[i]] = log[pp - exp[i]] = i;\r\n    } else {\r\n      root = primitive_root(p);\r\
    \n      ord = pp / p * (p - 1);\r\n      exp.assign(ord, 1);\r\n      log.assign(pp,\
    \ 0);\r\n      FOR(i, ord - 1) { exp[i + 1] = bt_pp.mul(exp[i], root); }\r\n \
    \     FOR(i, ord) log[exp[i]] = i;\r\n    }\r\n    log_fact.assign(pp, 0);\r\n\
    \    FOR(i, 1, pp) {\r\n      log_fact[i] = log_fact[i - 1] + log[i];\r\n    \
    \  if (log_fact[i] >= ord) log_fact[i] -= ord;\r\n    }\r\n  }\r\n\r\n  int C(ll\
    \ n, ll i) {\r\n    assert(n >= 0);\r\n    if (i < 0 || i > n) return 0;\r\n \
    \   ll a = i, b = n - i;\r\n    if (pp == 2) { return ((a & b) == 0 ? 1 : 0);\
    \ }\r\n    int log = 0, cnt_p = 0, sgn = 0;\r\n    if (e > 1) {\r\n      while\
    \ (n && cnt_p < e) {\r\n        auto [n1, nr1] = bt_pp.divmod(n);\r\n        auto\
    \ [a1, ar1] = bt_pp.divmod(a);\r\n        auto [b1, br1] = bt_pp.divmod(b);\r\n\
    \        log += log_fact[nr1] - log_fact[ar1] - log_fact[br1];\r\n        if (p\
    \ > 2) {\r\n          sgn += (n1 & 1) + (a1 & 1) + (b1 & 1);\r\n        } else\
    \ {\r\n          sgn += (((nr1 + 1) & 4) + ((ar1 + 1) & 4) + ((br1 + 1) & 4))\
    \ / 4;\r\n        }\r\n        n = bt_p.floor(n), a = bt_p.floor(a), b = bt_p.floor(b);\r\
    \n        cnt_p += n - a - b;\r\n      }\r\n    } else {\r\n      while (n &&\
    \ cnt_p < e) {\r\n        auto [n1, nr1] = bt_pp.divmod(n);\r\n        auto [a1,\
    \ ar1] = bt_pp.divmod(a);\r\n        auto [b1, br1] = bt_pp.divmod(b);\r\n   \
    \     log += log_fact[nr1] - log_fact[ar1] - log_fact[br1];\r\n        if (p >\
    \ 2) {\r\n          sgn += (n1 & 1) + (a1 & 1) + (b1 & 1);\r\n        } else {\r\
    \n          sgn += ((nr1 + 1) >> 2 & 1) + ((ar1 + 1) >> 2 & 1)\r\n           \
    \      + ((br1 + 1) >> 2 & 1);\r\n        }\r\n        n = n1, a = a1, b = b1;\r\
    \n        cnt_p += n - a - b;\r\n      }\r\n    }\r\n    if (cnt_p >= e) return\
    \ 0;\r\n    log %= ord;\r\n    if (log < 0) log += ord;\r\n    int res = exp[log];\r\
    \n    if (sgn & 1) res = pp - res;\r\n    return bt_pp.mul(power[cnt_p], res);\r\
    \n  }\r\n};\r\n\r\nstruct Binomial {\r\n  int mod;\r\n  vc<Binomial_PrimePower>\
    \ BPP;\r\n  vc<int> crt_coef;\r\n  Barrett bt;\r\n\r\n  Binomial(int mod) : mod(mod),\
    \ bt(mod) {\r\n    for (auto&& [p, e]: factor(mod)) {\r\n      int pp = 1;\r\n\
    \      FOR(e) pp *= p;\r\n      BPP.eb(Binomial_PrimePower(p, e));\r\n      int\
    \ other = mod / pp;\r\n      crt_coef.eb(ll(other) * mod_inv(other, pp) % mod);\r\
    \n    }\r\n  }\r\n\r\n  int C(ll n, ll k) {\r\n    assert(n >= 0);\r\n    if (k\
    \ < 0 || k > n) return 0;\r\n    int ANS = 0;\r\n    FOR(s, len(crt_coef)) {\r\
    \n      ANS = bt.modulo(ANS + u64(BPP[s].C(n, k)) * crt_coef[s]);\r\n    }\r\n\
    \    return ANS;\r\n  }\r\n};"
  dependsOn:
  - mod/primitive_root.hpp
  - nt/factor.hpp
  - nt/primetest.hpp
  - mod/mod_pow.hpp
  - mod/barrett.hpp
  - random/base.hpp
  - mod/mod_inv.hpp
  isVerificationFile: false
  path: mod/binomial.hpp
  requiredBy: []
  timestamp: '2023-04-27 21:29:47+09:00'
  verificationStatus: LIBRARY_SOME_WA
  verifiedWith:
  - test/yukicoder/2120.test.cpp
  - test/yukicoder/2181.test.cpp
  - test/library_checker/math/binomial_coefficient.test.cpp
documentation_of: mod/binomial.hpp
layout: document
redirect_from:
- /library/mod/binomial.hpp
- /library/mod/binomial.hpp.html
title: mod/binomial.hpp
---
