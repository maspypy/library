---
data:
  _extendedDependsOn:
  - icon: ':question:'
    path: mod/fast_div.hpp
    title: mod/fast_div.hpp
  - icon: ':question:'
    path: mod/mod_inv.hpp
    title: mod/mod_inv.hpp
  - icon: ':question:'
    path: nt/factor.hpp
    title: nt/factor.hpp
  - icon: ':question:'
    path: nt/primetest.hpp
    title: nt/primetest.hpp
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/yukicoder/187.test.cpp
    title: test/yukicoder/187.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/yukicoder/1956.test.cpp
    title: test/yukicoder/1956.test.cpp
  - icon: ':x:'
    path: test/yukicoder/2119.test.cpp
    title: test/yukicoder/2119.test.cpp
  _isVerificationFailed: true
  _pathExtension: hpp
  _verificationStatusIcon: ':question:'
  attributes:
    links: []
  bundledCode: "#line 2 \"mod/fast_div.hpp\"\nstruct fast_div {\r\n  // Min25 https://judge.yosupo.jp/submission/46090\r\
    \n  // \u540C\u3058\u5B9A\u6570\u3067\u4F55\u5EA6\u3082\u9664\u7B97\u3059\u308B\
    \u3068\u304D\u306E\u9AD8\u901F\u5316\u306B\u4F7F\u3048\u308B\r\n  using i64 =\
    \ long long;\r\n  using u64 = unsigned long long;\r\n  using u128 = __uint128_t;\r\
    \n  constexpr fast_div() : m(), s(), x() {}\r\n  constexpr fast_div(int n)\r\n\
    \      : m(n), s(std::__lg(n - 1)), x(((u128(1) << (s + 64)) + n - 1) / n) {}\r\
    \n  constexpr friend u64 operator/(u64 n, const fast_div& d) {\r\n    return (u128(n)\
    \ * d.x >> d.s) >> 64;\r\n  }\r\n  constexpr friend int operator%(u64 n, const\
    \ fast_div& d) {\r\n    return n - n / d * d.m;\r\n  }\r\n  constexpr std::pair<i64,\
    \ int> divmod(u64 n) const {\r\n    u64 q = n / *this;\r\n    return {q, n - q\
    \ * m};\r\n  }\r\n\r\n  int m;\r\n  int s;\r\n  u64 x;\r\n};\r\n#line 2 \"mod/mod_inv.hpp\"\
    \n// long \u3067\u3082\u5927\u4E08\u592B\r\nll mod_inv(ll val, ll mod) {\r\n \
    \ val %= mod;\r\n  if (val < 0) val += mod;\r\n  ll a = val, b = mod, u = 1, v\
    \ = 0, t;\r\n  while (b > 0) {\r\n    t = a / b;\r\n    swap(a -= t * b, b), swap(u\
    \ -= t * v, v);\r\n  }\r\n  if (u < 0) u += mod;\r\n  return u;\r\n}\r\n#line\
    \ 2 \"nt/primetest.hpp\"\nstruct m64 {\r\n  using i64 = int64_t;\r\n  using u64\
    \ = uint64_t;\r\n  using u128 = __uint128_t;\r\n\r\n  inline static u64 m, r,\
    \ n2; // r * m = -1 (mod 1<<64), n2 = 1<<128 (mod m)\r\n  static void set_mod(u64\
    \ m) {\r\n    assert(m < (1ull << 62));\r\n    assert((m & 1) == 1);\r\n    m64::m\
    \ = m;\r\n    n2 = -u128(m) % m;\r\n    r = m;\r\n    FOR(_, 5) r *= 2 - m * r;\r\
    \n    r = -r;\r\n    assert(r * m == -1ull);\r\n  }\r\n  static u64 reduce(u128\
    \ b) { return (b + u128(u64(b) * r) * m) >> 64; }\r\n\r\n  u64 x;\r\n  m64() :\
    \ x(0) {}\r\n  m64(u64 x) : x(reduce(u128(x) * n2)){};\r\n  u64 val() const {\r\
    \n    u64 y = reduce(x);\r\n    return y >= m ? y - m : y;\r\n  }\r\n  m64 &operator+=(m64\
    \ y) {\r\n    x += y.x - (m << 1);\r\n    x = (i64(x) < 0 ? x + (m << 1) : x);\r\
    \n    return *this;\r\n  }\r\n  m64 &operator-=(m64 y) {\r\n    x -= y.x;\r\n\
    \    x = (i64(x) < 0 ? x + (m << 1) : x);\r\n    return *this;\r\n  }\r\n  m64\
    \ &operator*=(m64 y) {\r\n    x = reduce(u128(x) * y.x);\r\n    return *this;\r\
    \n  }\r\n  m64 operator+(m64 y) const { return m64(*this) += y; }\r\n  m64 operator-(m64\
    \ y) const { return m64(*this) -= y; }\r\n  m64 operator*(m64 y) const { return\
    \ m64(*this) *= y; }\r\n  bool operator==(m64 y) const {\r\n    return (x >= m\
    \ ? x - m : x) == (y.x >= m ? y.x - m : y.x);\r\n  }\r\n  bool operator!=(m64\
    \ y) const { return not operator==(y); }\r\n  m64 pow(u64 n) const {\r\n    m64\
    \ y = 1, z = *this;\r\n    for (; n; n >>= 1, z *= z)\r\n      if (n & 1) y *=\
    \ z;\r\n    return y;\r\n  }\r\n};\r\n\r\nbool primetest(const uint64_t x) {\r\
    \n  using u64 = uint64_t;\r\n  if (x == 2 or x == 3 or x == 5 or x == 7) return\
    \ true;\r\n  if (x % 2 == 0 or x % 3 == 0 or x % 5 == 0 or x % 7 == 0) return\
    \ false;\r\n  if (x < 121) return x > 1;\r\n  const u64 d = (x - 1) >> __builtin_ctzll(x\
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
    \    res.eb(p, e);\n  }\n  return res;\n}\n#line 5 \"nt/crt.hpp\"\n\n// \u6700\
    \u5C0F\u89E3\u3092 mod new_mod \u3067\u8FD4\u3059\n// \u89E3\u306A\u3057\u306A\
    \u3089 -1 \u3092\u8FD4\u3059\ni128 CRT(vc<int> vals, vc<int> mods, ll new_mod\
    \ = -1, bool coprime = false) {\n  int n = len(vals);\n  FOR(i, n) {\n    vals[i]\
    \ %= mods[i];\n    if (vals[i] < 0) vals[i] += mods[i];\n  }\n  if (!coprime)\
    \ {\n    unordered_map<ll, vc<pi>> MP;\n    FOR(i, n) {\n      for (auto&& [p,\
    \ e]: factor(mods[i])) {\n        int mod = 1;\n        FOR(e) mod *= p;\n   \
    \     MP[p].eb(vals[i] % mod, mod);\n      }\n    }\n    vc<int> xx, mm;\n   \
    \ for (auto&& [p, dat]: MP) {\n      int mod = 1;\n      int val = 0;\n      for\
    \ (auto&& [x, m]: dat)\n        if (chmax(mod, m)) val = x;\n      for (auto&&\
    \ [x, m]: dat)\n        if ((val - x) % m != 0) return -1;\n      xx.eb(val);\n\
    \      mm.eb(mod);\n    }\n    swap(vals, xx);\n    swap(mods, mm);\n    n = len(vals);\n\
    \  }\n\n  vc<int> cfs(n);\n  FOR(i, n) {\n    auto mod = fast_div(mods[i]);\n\
    \    ll a = vals[i];\n    ll prod = 1;\n    FOR(j, i) {\n      a = (a + cfs[j]\
    \ * (mods[i] - prod)) % mod;\n      prod = prod * mods[j] % mod;\n    }\n    cfs[i]\
    \ = mod_inv(prod, mods[i]) * a % mod;\n  }\n  i128 ret = 0;\n  i128 prod = 1;\n\
    \  FOR(i, n) {\n    ret += prod * cfs[i];\n    prod *= mods[i];\n    if (new_mod\
    \ != -1) {\n      ret %= new_mod;\n      prod %= new_mod;\n    }\n  }\n  return\
    \ ret;\n}\n"
  code: "#pragma once\n#include \"mod/fast_div.hpp\"\n#include \"mod/mod_inv.hpp\"\
    \n#include \"nt/factor.hpp\"\n\n// \u6700\u5C0F\u89E3\u3092 mod new_mod \u3067\
    \u8FD4\u3059\n// \u89E3\u306A\u3057\u306A\u3089 -1 \u3092\u8FD4\u3059\ni128 CRT(vc<int>\
    \ vals, vc<int> mods, ll new_mod = -1, bool coprime = false) {\n  int n = len(vals);\n\
    \  FOR(i, n) {\n    vals[i] %= mods[i];\n    if (vals[i] < 0) vals[i] += mods[i];\n\
    \  }\n  if (!coprime) {\n    unordered_map<ll, vc<pi>> MP;\n    FOR(i, n) {\n\
    \      for (auto&& [p, e]: factor(mods[i])) {\n        int mod = 1;\n        FOR(e)\
    \ mod *= p;\n        MP[p].eb(vals[i] % mod, mod);\n      }\n    }\n    vc<int>\
    \ xx, mm;\n    for (auto&& [p, dat]: MP) {\n      int mod = 1;\n      int val\
    \ = 0;\n      for (auto&& [x, m]: dat)\n        if (chmax(mod, m)) val = x;\n\
    \      for (auto&& [x, m]: dat)\n        if ((val - x) % m != 0) return -1;\n\
    \      xx.eb(val);\n      mm.eb(mod);\n    }\n    swap(vals, xx);\n    swap(mods,\
    \ mm);\n    n = len(vals);\n  }\n\n  vc<int> cfs(n);\n  FOR(i, n) {\n    auto\
    \ mod = fast_div(mods[i]);\n    ll a = vals[i];\n    ll prod = 1;\n    FOR(j,\
    \ i) {\n      a = (a + cfs[j] * (mods[i] - prod)) % mod;\n      prod = prod *\
    \ mods[j] % mod;\n    }\n    cfs[i] = mod_inv(prod, mods[i]) * a % mod;\n  }\n\
    \  i128 ret = 0;\n  i128 prod = 1;\n  FOR(i, n) {\n    ret += prod * cfs[i];\n\
    \    prod *= mods[i];\n    if (new_mod != -1) {\n      ret %= new_mod;\n     \
    \ prod %= new_mod;\n    }\n  }\n  return ret;\n}\n"
  dependsOn:
  - mod/fast_div.hpp
  - mod/mod_inv.hpp
  - nt/factor.hpp
  - nt/primetest.hpp
  isVerificationFile: false
  path: nt/crt.hpp
  requiredBy: []
  timestamp: '2022-11-27 19:00:13+09:00'
  verificationStatus: LIBRARY_SOME_WA
  verifiedWith:
  - test/yukicoder/187.test.cpp
  - test/yukicoder/1956.test.cpp
  - test/yukicoder/2119.test.cpp
documentation_of: nt/crt.hpp
layout: document
redirect_from:
- /library/nt/crt.hpp
- /library/nt/crt.hpp.html
title: nt/crt.hpp
---
