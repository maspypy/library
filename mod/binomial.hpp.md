---
data:
  _extendedDependsOn:
  - icon: ':question:'
    path: mod/fast_div.hpp
    title: mod/fast_div.hpp
  - icon: ':question:'
    path: nt/factor.hpp
    title: nt/factor.hpp
  - icon: ':question:'
    path: nt/primetest.hpp
    title: nt/primetest.hpp
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/library_checker/math/binomial_coefficient.test.cpp
    title: test/library_checker/math/binomial_coefficient.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/yukicoder/2120.test.cpp
    title: test/yukicoder/2120.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/yukicoder/2181.test.cpp
    title: test/yukicoder/2181.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
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
    \ return false;\r\n    }\r\n  }\r\n  return true;\r\n}\n#line 3 \"nt/factor.hpp\"\
    \n\nmt19937_64 rng_mt{random_device{}()};\nll rnd(ll n) { return uniform_int_distribution<ll>(0,\
    \ n - 1)(rng_mt); }\n\nll rho(ll n, ll c) {\n  m64::set_mod(n);\n  assert(n >\
    \ 1);\n  const m64 cc(c);\n  auto f = [&](m64 x) { return x * x + cc; };\n  m64\
    \ x = 1, y = 2, z = 1, q = 1;\n  ll g = 1;\n  const ll m = 1LL << (__lg(n) / 5);\
    \ // ?\n  for (ll r = 1; g == 1; r <<= 1) {\n    x = y;\n    FOR(_, r) y = f(y);\n\
    \    for (ll k = 0; k < r and g == 1; k += m) {\n      z = y;\n      FOR(_, min(m,\
    \ r - k)) y = f(y), q *= x - y;\n      g = gcd(q.val(), n);\n    }\n  }\n  if\
    \ (g == n) do {\n      z = f(z);\n      g = gcd((x - z).val(), n);\n    } while\
    \ (g == 1);\n  return g;\n}\n\nll find_prime_factor(ll n) {\n  assert(n > 1);\n\
    \  if (primetest(n)) return n;\n  FOR(_, 100) {\n    ll m = rho(n, rnd(n));\n\
    \    if (primetest(m)) return m;\n    n = m;\n  }\n  cerr << \"failed\" << endl;\n\
    \  assert(false);\n  return -1;\n}\n\n// \u30BD\u30FC\u30C8\u3057\u3066\u304F\u308C\
    \u308B\nvc<pair<ll, int>> factor(ll n) {\n  assert(n >= 1);\n  vc<pair<ll, int>>\
    \ pf;\n  FOR3(p, 2, 100) {\n    if (p * p > n) break;\n    if (n % p == 0) {\n\
    \      ll e = 0;\n      do { n /= p, e += 1; } while (n % p == 0);\n      pf.eb(p,\
    \ e);\n    }\n  }\n  while (n > 1) {\n    ll p = find_prime_factor(n);\n    ll\
    \ e = 0;\n    do { n /= p, e += 1; } while (n % p == 0);\n    pf.eb(p, e);\n \
    \ }\n  sort(all(pf));\n  return pf;\n}\n\nvc<pair<ll, int>> factor_by_lpf(ll n,\
    \ vc<int>& lpf) {\n  vc<pair<ll, int>> res;\n  while (n > 1) {\n    int p = lpf[n];\n\
    \    int e = 0;\n    while (n % p == 0) {\n      n /= p;\n      ++e;\n    }\n\
    \    res.eb(p, e);\n  }\n  return res;\n}\n#line 2 \"mod/fast_div.hpp\"\nstruct\
    \ fast_div {\r\n  // Min25 https://judge.yosupo.jp/submission/46090\r\n  // \u540C\
    \u3058\u5B9A\u6570\u3067\u4F55\u5EA6\u3082\u9664\u7B97\u3059\u308B\u3068\u304D\
    \u306E\u9AD8\u901F\u5316\u306B\u4F7F\u3048\u308B\r\n  using i64 = long long;\r\
    \n  using u64 = unsigned long long;\r\n  using u128 = __uint128_t;\r\n  constexpr\
    \ fast_div() : m(), s(), x() {}\r\n  constexpr fast_div(int n)\r\n      : m(n),\
    \ s(std::__lg(n - 1)), x(((u128(1) << (s + 64)) + n - 1) / n) {}\r\n  constexpr\
    \ friend u64 operator/(u64 n, const fast_div& d) {\r\n    return (u128(n) * d.x\
    \ >> d.s) >> 64;\r\n  }\r\n  constexpr friend int operator%(u64 n, const fast_div&\
    \ d) {\r\n    return n - n / d * d.m;\r\n  }\r\n  constexpr std::pair<i64, int>\
    \ divmod(u64 n) const {\r\n    u64 q = n / *this;\r\n    return {q, n - q * m};\r\
    \n  }\r\n\r\n  int m;\r\n  int s;\r\n  u64 x;\r\n};\r\n#line 3 \"mod/binomial.hpp\"\
    \nstruct Binomial {\r\n  // mod \u3092\u7D20\u56E0\u6570\u5206\u89E3\u3057\u3066\
    \u968E\u4E57\u3092\u524D\u8A08\u7B97 \u2192 \u4E8C\u9805\u4FC2\u6570\u30AF\u30A8\
    \u30EA\r\n  // O(mod) \u6642\u9593\u524D\u8A08\u7B97\r\n  int mod;\r\n  vc<pair<ll,\
    \ int>> pf;\r\n  vc<int> pp;\r\n  vc<vc<int>> fact;\r\n  vc<int> crt_coef;\r\n\
    \r\n  Binomial(int mod) : mod(mod) {\r\n    pf = factor(mod);\r\n    int S = len(pf);\r\
    \n    pp.resize(S);\r\n    fact.resize(S);\r\n    crt_coef.resize(S);\r\n    FOR(s,\
    \ S) {\r\n      auto [p, e] = pf[s];\r\n      pp[s] = 1;\r\n      FOR(e) pp[s]\
    \ *= p;\r\n      auto& F = fact[s];\r\n      // mod pp \u3067\u306E fact \u306E\
    \u5468\u671F\r\n      F.resize(pp[s] * 2);\r\n      F[0] = 1;\r\n      fast_div\
    \ fd_p(p);\r\n      fast_div fd_pp(pp[s]);\r\n      FOR(x, 1, len(F)) {\r\n  \
    \      if (x % fd_p == 0)\r\n          F[x] = F[x - 1];\r\n        else\r\n  \
    \        F[x] = F[x - 1] * x % fd_pp;\r\n      }\r\n      int other = mod / fd_pp;\r\
    \n      while (crt_coef[s] % fd_pp != 1) crt_coef[s] += other;\r\n    }\r\n  }\r\
    \n\r\n  int mod_pow(int a, int n, fast_div d) {\r\n    ll x = 1, p = a;\r\n  \
    \  while (n) {\r\n      if (n & 1) x = x * p % d;\r\n      p = p * p % d;\r\n\
    \      n >>= 1;\r\n    }\r\n    return x;\r\n  }\r\n\r\n  int C(ll n, ll k) {\r\
    \n    assert(n >= 0);\r\n    if (k < 0 || k > n) return 0;\r\n    ll ANS = 0;\r\
    \n    FOR(s, len(pf)) {\r\n      int p = pf[s].fi;\r\n      fast_div fd_p(p);\r\
    \n      fast_div fd_pp(pp[s]);\r\n      fast_div fd_len(len(fact[s]));\r\n   \
    \   auto get_fact = [&](ll n) -> pi {\r\n        // p^e * x \u3068\u3057\u3066\
    \u3001(e, x mod pp) \u3092\u8FD4\u3059\r\n        ll x = 1, e = 0;\r\n       \
    \ while (n) {\r\n          x = x * fact[s][n % fd_len] % fd_pp;\r\n          n\
    \ = n / fd_p;\r\n          e += n;\r\n        }\r\n        return {e, x};\r\n\
    \      };\r\n      auto a = get_fact(n);\r\n      auto b = get_fact(k);\r\n  \
    \    auto c = get_fact(n - k);\r\n      ll e = a.fi - b.fi - c.fi;\r\n      ll\
    \ x = a.se;\r\n      ll y = b.se * c.se % fd_pp;\r\n      int phi = pp[s] - pp[s]\
    \ / pf[s].fi;\r\n      x = x * mod_pow(y, phi - 1, fd_pp) % fd_pp;\r\n      FOR(min<int>(e,\
    \ pf[s].se)) x *= p;\r\n      x = x % fd_pp;\r\n      ANS += x * crt_coef[s];\r\
    \n    }\r\n    return ANS % mod;\r\n  }\r\n};\r\n"
  code: "#include \"nt/factor.hpp\"\r\n#include \"mod/fast_div.hpp\"\r\nstruct Binomial\
    \ {\r\n  // mod \u3092\u7D20\u56E0\u6570\u5206\u89E3\u3057\u3066\u968E\u4E57\u3092\
    \u524D\u8A08\u7B97 \u2192 \u4E8C\u9805\u4FC2\u6570\u30AF\u30A8\u30EA\r\n  // O(mod)\
    \ \u6642\u9593\u524D\u8A08\u7B97\r\n  int mod;\r\n  vc<pair<ll, int>> pf;\r\n\
    \  vc<int> pp;\r\n  vc<vc<int>> fact;\r\n  vc<int> crt_coef;\r\n\r\n  Binomial(int\
    \ mod) : mod(mod) {\r\n    pf = factor(mod);\r\n    int S = len(pf);\r\n    pp.resize(S);\r\
    \n    fact.resize(S);\r\n    crt_coef.resize(S);\r\n    FOR(s, S) {\r\n      auto\
    \ [p, e] = pf[s];\r\n      pp[s] = 1;\r\n      FOR(e) pp[s] *= p;\r\n      auto&\
    \ F = fact[s];\r\n      // mod pp \u3067\u306E fact \u306E\u5468\u671F\r\n   \
    \   F.resize(pp[s] * 2);\r\n      F[0] = 1;\r\n      fast_div fd_p(p);\r\n   \
    \   fast_div fd_pp(pp[s]);\r\n      FOR(x, 1, len(F)) {\r\n        if (x % fd_p\
    \ == 0)\r\n          F[x] = F[x - 1];\r\n        else\r\n          F[x] = F[x\
    \ - 1] * x % fd_pp;\r\n      }\r\n      int other = mod / fd_pp;\r\n      while\
    \ (crt_coef[s] % fd_pp != 1) crt_coef[s] += other;\r\n    }\r\n  }\r\n\r\n  int\
    \ mod_pow(int a, int n, fast_div d) {\r\n    ll x = 1, p = a;\r\n    while (n)\
    \ {\r\n      if (n & 1) x = x * p % d;\r\n      p = p * p % d;\r\n      n >>=\
    \ 1;\r\n    }\r\n    return x;\r\n  }\r\n\r\n  int C(ll n, ll k) {\r\n    assert(n\
    \ >= 0);\r\n    if (k < 0 || k > n) return 0;\r\n    ll ANS = 0;\r\n    FOR(s,\
    \ len(pf)) {\r\n      int p = pf[s].fi;\r\n      fast_div fd_p(p);\r\n      fast_div\
    \ fd_pp(pp[s]);\r\n      fast_div fd_len(len(fact[s]));\r\n      auto get_fact\
    \ = [&](ll n) -> pi {\r\n        // p^e * x \u3068\u3057\u3066\u3001(e, x mod\
    \ pp) \u3092\u8FD4\u3059\r\n        ll x = 1, e = 0;\r\n        while (n) {\r\n\
    \          x = x * fact[s][n % fd_len] % fd_pp;\r\n          n = n / fd_p;\r\n\
    \          e += n;\r\n        }\r\n        return {e, x};\r\n      };\r\n    \
    \  auto a = get_fact(n);\r\n      auto b = get_fact(k);\r\n      auto c = get_fact(n\
    \ - k);\r\n      ll e = a.fi - b.fi - c.fi;\r\n      ll x = a.se;\r\n      ll\
    \ y = b.se * c.se % fd_pp;\r\n      int phi = pp[s] - pp[s] / pf[s].fi;\r\n  \
    \    x = x * mod_pow(y, phi - 1, fd_pp) % fd_pp;\r\n      FOR(min<int>(e, pf[s].se))\
    \ x *= p;\r\n      x = x % fd_pp;\r\n      ANS += x * crt_coef[s];\r\n    }\r\n\
    \    return ANS % mod;\r\n  }\r\n};\r\n"
  dependsOn:
  - nt/factor.hpp
  - nt/primetest.hpp
  - mod/fast_div.hpp
  isVerificationFile: false
  path: mod/binomial.hpp
  requiredBy: []
  timestamp: '2023-01-09 23:28:24+09:00'
  verificationStatus: LIBRARY_ALL_AC
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
