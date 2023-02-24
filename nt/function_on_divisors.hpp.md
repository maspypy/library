---
data:
  _extendedDependsOn:
  - icon: ':question:'
    path: nt/factor.hpp
    title: nt/factor.hpp
  - icon: ':question:'
    path: nt/primetest.hpp
    title: nt/primetest.hpp
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/yukicoder/1728.test.cpp
    title: test/yukicoder/1728.test.cpp
  - icon: ':x:'
    path: test_atcoder/abc212g.test.cpp
    title: test_atcoder/abc212g.test.cpp
  _isVerificationFailed: true
  _pathExtension: hpp
  _verificationStatusIcon: ':question:'
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
    \    res.eb(p, e);\n  }\n  return res;\n}\n#line 2 \"nt/function_on_divisors.hpp\"\
    \n\ntemplate <typename T>\nstruct Function_on_Divisors {\n  vc<pair<ll, int>>\
    \ pf;\n  vc<ll> divs;\n  vc<T> dat;\n\n  Function_on_Divisors(ll N) : Function_on_Divisors(factor(N))\
    \ {}\n  Function_on_Divisors(vc<pair<ll, int>> pf) : pf(pf) {\n    ll n = 1;\n\
    \    for (auto&& [p, e]: pf) n *= (e + 1);\n    divs.reserve(n);\n    divs = {1};\n\
    \    for (auto&& [p, e]: pf) {\n      int n = len(divs);\n      ll q = p;\n  \
    \    FOR(e) {\n        FOR(i, n) divs.eb(divs[i] * q);\n        q *= p;\n    \
    \  }\n    }\n  }\n\n  // f(p, k) \u3092\u4E0E\u3048\u308B \u2192 \u4E57\u6CD5\u7684\
    \u306B\u62E1\u5F35\n  template <typename F>\n  void set_multiplicative(F f) {\n\
    \    dat.reserve(len(divs));\n    dat = {T(1)};\n    for (auto&& [p, e]: pf) {\n\
    \      int n = len(divs);\n      FOR(k, 1, e + 1) { FOR(i, n) dat.eb(dat[i] *\
    \ f(p, k)); }\n    }\n  }\n\n  void set_euler_phi() {\n    dat.resize(len(divs));\n\
    \    FOR(i, len(divs)) dat[i] = T(divs[i]);\n    divisor_mobius();\n  }\n\n  void\
    \ multiplier_zeta() {\n    ll k = 1;\n    for (auto&& [p, e]: pf) {\n      ll\
    \ mod = k * (e + 1);\n      FOR(i, len(divs) / mod) {\n        FOR_R(j, mod -\
    \ k) { dat[mod * i + j] += dat[mod * i + j + k]; }\n      }\n      k *= (e + 1);\n\
    \    }\n  }\n\n  void multiplier_mobius() {\n    ll k = 1;\n    for (auto&& [p,\
    \ e]: pf) {\n      ll mod = k * (e + 1);\n      FOR(i, len(divs) / mod) {\n  \
    \      FOR(j, mod - k) { dat[mod * i + j] -= dat[mod * i + j + k]; }\n      }\n\
    \      k *= (e + 1);\n    }\n  }\n\n  void divisor_zeta() {\n    ll k = 1;\n \
    \   for (auto&& [p, e]: pf) {\n      ll mod = k * (e + 1);\n      FOR(i, len(divs)\
    \ / mod) {\n        FOR(j, mod - k) { dat[mod * i + j + k] += dat[mod * i + j];\
    \ }\n      }\n      k *= (e + 1);\n    }\n  }\n\n  void divisor_mobius() {\n \
    \   ll k = 1;\n    for (auto&& [p, e]: pf) {\n      ll mod = k * (e + 1);\n  \
    \    FOR(i, len(divs) / mod) {\n        FOR_R(j, mod - k) { dat[mod * i + j +\
    \ k] -= dat[mod * i + j]; }\n      }\n      k *= (e + 1);\n    }\n  }\n\n  vc<pair<ll,\
    \ T>> get_all() {\n    vc<pair<ll, T>> res;\n    FOR(i, len(divs)) { res.eb(divs[i],\
    \ dat[i]); }\n    return res;\n  }\n};\n"
  code: "#include \"nt/factor.hpp\"\n\ntemplate <typename T>\nstruct Function_on_Divisors\
    \ {\n  vc<pair<ll, int>> pf;\n  vc<ll> divs;\n  vc<T> dat;\n\n  Function_on_Divisors(ll\
    \ N) : Function_on_Divisors(factor(N)) {}\n  Function_on_Divisors(vc<pair<ll,\
    \ int>> pf) : pf(pf) {\n    ll n = 1;\n    for (auto&& [p, e]: pf) n *= (e + 1);\n\
    \    divs.reserve(n);\n    divs = {1};\n    for (auto&& [p, e]: pf) {\n      int\
    \ n = len(divs);\n      ll q = p;\n      FOR(e) {\n        FOR(i, n) divs.eb(divs[i]\
    \ * q);\n        q *= p;\n      }\n    }\n  }\n\n  // f(p, k) \u3092\u4E0E\u3048\
    \u308B \u2192 \u4E57\u6CD5\u7684\u306B\u62E1\u5F35\n  template <typename F>\n\
    \  void set_multiplicative(F f) {\n    dat.reserve(len(divs));\n    dat = {T(1)};\n\
    \    for (auto&& [p, e]: pf) {\n      int n = len(divs);\n      FOR(k, 1, e +\
    \ 1) { FOR(i, n) dat.eb(dat[i] * f(p, k)); }\n    }\n  }\n\n  void set_euler_phi()\
    \ {\n    dat.resize(len(divs));\n    FOR(i, len(divs)) dat[i] = T(divs[i]);\n\
    \    divisor_mobius();\n  }\n\n  void multiplier_zeta() {\n    ll k = 1;\n   \
    \ for (auto&& [p, e]: pf) {\n      ll mod = k * (e + 1);\n      FOR(i, len(divs)\
    \ / mod) {\n        FOR_R(j, mod - k) { dat[mod * i + j] += dat[mod * i + j +\
    \ k]; }\n      }\n      k *= (e + 1);\n    }\n  }\n\n  void multiplier_mobius()\
    \ {\n    ll k = 1;\n    for (auto&& [p, e]: pf) {\n      ll mod = k * (e + 1);\n\
    \      FOR(i, len(divs) / mod) {\n        FOR(j, mod - k) { dat[mod * i + j] -=\
    \ dat[mod * i + j + k]; }\n      }\n      k *= (e + 1);\n    }\n  }\n\n  void\
    \ divisor_zeta() {\n    ll k = 1;\n    for (auto&& [p, e]: pf) {\n      ll mod\
    \ = k * (e + 1);\n      FOR(i, len(divs) / mod) {\n        FOR(j, mod - k) { dat[mod\
    \ * i + j + k] += dat[mod * i + j]; }\n      }\n      k *= (e + 1);\n    }\n \
    \ }\n\n  void divisor_mobius() {\n    ll k = 1;\n    for (auto&& [p, e]: pf) {\n\
    \      ll mod = k * (e + 1);\n      FOR(i, len(divs) / mod) {\n        FOR_R(j,\
    \ mod - k) { dat[mod * i + j + k] -= dat[mod * i + j]; }\n      }\n      k *=\
    \ (e + 1);\n    }\n  }\n\n  vc<pair<ll, T>> get_all() {\n    vc<pair<ll, T>> res;\n\
    \    FOR(i, len(divs)) { res.eb(divs[i], dat[i]); }\n    return res;\n  }\n};\n"
  dependsOn:
  - nt/factor.hpp
  - nt/primetest.hpp
  isVerificationFile: false
  path: nt/function_on_divisors.hpp
  requiredBy: []
  timestamp: '2023-01-23 15:43:20+09:00'
  verificationStatus: LIBRARY_SOME_WA
  verifiedWith:
  - test_atcoder/abc212g.test.cpp
  - test/yukicoder/1728.test.cpp
documentation_of: nt/function_on_divisors.hpp
layout: document
redirect_from:
- /library/nt/function_on_divisors.hpp
- /library/nt/function_on_divisors.hpp.html
title: nt/function_on_divisors.hpp
---
