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
    path: nt/primetest.hpp
    title: nt/primetest.hpp
  - icon: ':question:'
    path: random/base.hpp
    title: random/base.hpp
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':x:'
    path: test/yukicoder/1728.test.cpp
    title: test/yukicoder/1728.test.cpp
  - icon: ':x:'
    path: test/yukicoder/2264.test.cpp
    title: test/yukicoder/2264.test.cpp
  - icon: ':x:'
    path: test_atcoder/abc212g.test.cpp
    title: test_atcoder/abc212g.test.cpp
  _isVerificationFailed: true
  _pathExtension: hpp
  _verificationStatusIcon: ':x:'
  attributes:
    links: []
  bundledCode: "#line 2 \"nt/factor.hpp\"\n\n#line 2 \"random/base.hpp\"\n\nu64 RNG_64()\
    \ {\n  static uint64_t x_\n      = uint64_t(chrono::duration_cast<chrono::nanoseconds>(\n\
    \                     chrono::high_resolution_clock::now().time_since_epoch())\n\
    \                     .count())\n        * 10150724397891781847ULL;\n  x_ ^= x_\
    \ << 7;\n  return x_ ^= x_ >> 9;\n}\n\nu64 RNG(u64 lim) { return RNG_64() % lim;\
    \ }\n\nll RNG(ll l, ll r) { return l + RNG_64() % (r - l); }\n#line 1 \"mod/mongomery_modint.hpp\"\
    \n// odd mod.\n// x \u306E\u4EE3\u308F\u308A\u306B rx \u3092\u6301\u3064\ntemplate\
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
    \    }\n    res.eb(p, e);\n  }\n  return res;\n}\n#line 2 \"nt/function_on_divisors.hpp\"\
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
    \ k] -= dat[mod * i + j]; }\n      }\n      k *= (e + 1);\n    }\n  }\n\n  //\
    \ (d, fd)\n  template <typename F>\n  void enumerate(F f) {\n    FOR(i, len(divs))\
    \ { f(divs[i], dat[i]); }\n  }\n};\n"
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
    \ (e + 1);\n    }\n  }\n\n  // (d, fd)\n  template <typename F>\n  void enumerate(F\
    \ f) {\n    FOR(i, len(divs)) { f(divs[i], dat[i]); }\n  }\n};\n"
  dependsOn:
  - nt/factor.hpp
  - random/base.hpp
  - nt/primetest.hpp
  - mod/mongomery_modint.hpp
  isVerificationFile: false
  path: nt/function_on_divisors.hpp
  requiredBy: []
  timestamp: '2023-11-02 04:28:32+09:00'
  verificationStatus: LIBRARY_ALL_WA
  verifiedWith:
  - test_atcoder/abc212g.test.cpp
  - test/yukicoder/2264.test.cpp
  - test/yukicoder/1728.test.cpp
documentation_of: nt/function_on_divisors.hpp
layout: document
redirect_from:
- /library/nt/function_on_divisors.hpp
- /library/nt/function_on_divisors.hpp.html
title: nt/function_on_divisors.hpp
---
