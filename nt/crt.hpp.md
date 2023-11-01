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
    path: mod/mongomery_modint.hpp
    title: mod/mongomery_modint.hpp
  - icon: ':question:'
    path: nt/coprime_factorization.hpp
    title: nt/coprime_factorization.hpp
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
    path: test/yukicoder/187.test.cpp
    title: test/yukicoder/187.test.cpp
  - icon: ':x:'
    path: test/yukicoder/1956.test.cpp
    title: test/yukicoder/1956.test.cpp
  - icon: ':x:'
    path: test/yukicoder/2119.test.cpp
    title: test/yukicoder/2119.test.cpp
  - icon: ':x:'
    path: test/yukicoder/590.test.cpp
    title: test/yukicoder/590.test.cpp
  _isVerificationFailed: true
  _pathExtension: hpp
  _verificationStatusIcon: ':x:'
  attributes:
    links: []
  bundledCode: "#line 2 \"mod/mod_inv.hpp\"\n\r\n// long \u3067\u3082\u5927\u4E08\u592B\
    \r\n// (val * x - 1) \u304C mod \u306E\u500D\u6570\u306B\u306A\u308B\u3088\u3046\
    \u306B\u3059\u308B\r\n// \u7279\u306B mod=0 \u306A\u3089 x=0 \u304C\u6E80\u305F\
    \u3059\r\nll mod_inv(ll val, ll mod) {\r\n  if (mod == 0) return 0;\r\n  mod =\
    \ abs(mod);\r\n  val %= mod;\r\n  if (val < 0) val += mod;\r\n  ll a = val, b\
    \ = mod, u = 1, v = 0, t;\r\n  while (b > 0) {\r\n    t = a / b;\r\n    swap(a\
    \ -= t * b, b), swap(u -= t * v, v);\r\n  }\r\n  if (u < 0) u += mod;\r\n  return\
    \ u;\r\n}\r\n#line 1 \"nt/coprime_factorization.hpp\"\n\n/*\n\u4E92\u3044\u306B\
    \u7D20\u306A\u6574\u6570 p1, p2, ..., pk \u3092\u7528\u3044\u3066 n_i = prod p_i^e_i\
    \ \u3068\u8868\u3059.\n[21,60,140,400]\n[3,7,20], [[(0,1),(1,1)],[(0,1),(2,1)],[(1,1),(2,1)],[(2,2)]]\n\
    */\ntemplate <typename T>\npair<vc<T>, vvc<pair<int, int>>> coprime_factorization(vc<T>\
    \ nums) {\n  vc<T> basis;\n  for (T val: nums) {\n    vc<T> new_basis;\n    for\
    \ (T x: basis) {\n      if (val == 1) {\n        new_basis.eb(x);\n        continue;\n\
    \      }\n      vc<T> dat = {val, x};\n      FOR(p, 1, len(dat)) {\n        FOR(i,\
    \ p) {\n          while (1) {\n            if (dat[p] > 1 && dat[i] % dat[p] ==\
    \ 0) dat[i] /= dat[p];\n            elif (dat[i] > 1 && dat[p] % dat[i] == 0)\
    \ dat[p] /= dat[i];\n            else break;\n          }\n          T g = gcd(dat[i],\
    \ dat[p]);\n          if (g == 1 || g == dat[i] || g == dat[p]) continue;\n  \
    \        dat[i] /= g, dat[p] /= g, dat.eb(g);\n        }\n      }\n      val =\
    \ dat[0];\n      FOR(i, 1, len(dat)) if (dat[i] != 1) new_basis.eb(dat[i]);\n\
    \    }\n    if (val > 1) new_basis.eb(val);\n    swap(basis, new_basis);\n  }\n\
    \n  sort(all(basis));\n\n  vvc<pair<int, int>> res(len(nums));\n  FOR(i, len(nums))\
    \ {\n    T x = nums[i];\n    FOR(j, len(basis)) {\n      int e = 0;\n      while\
    \ (x % basis[j] == 0) x /= basis[j], ++e;\n      if (e) res[i].eb(j, e);\n   \
    \ }\n  }\n  return {basis, res};\n}\n#line 2 \"nt/factor.hpp\"\n\n#line 2 \"random/base.hpp\"\
    \n\nu64 RNG_64() {\n  static uint64_t x_\n      = uint64_t(chrono::duration_cast<chrono::nanoseconds>(\n\
    \                     chrono::high_resolution_clock::now().time_since_epoch())\n\
    \                     .count())\n        * 10150724397891781847ULL;\n  x_ ^= x_\
    \ << 7;\n  return x_ ^= x_ >> 9;\n}\n\nu64 RNG(u64 lim) { return RNG_64() % lim;\
    \ }\n\nll RNG(ll l, ll r) { return l + RNG_64() % (r - l); }\n#line 2 \"mod/mongomery_modint.hpp\"\
    \n\n// odd mod.\n// x \u306E\u4EE3\u308F\u308A\u306B rx \u3092\u6301\u3064\ntemplate\
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
    \    }\n    res.eb(p, e);\n  }\n  return res;\n}\n#line 2 \"mod/barrett.hpp\"\n\
    \n// https://github.com/atcoder/ac-library/blob/master/atcoder/internal_math.hpp\n\
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
    nt/crt.hpp\"\n\n// \u975E\u8CA0\u6700\u5C0F\u89E3\u3092 mod new_mod \u3067\u8FD4\
    \u3059 (garner)\ntemplate <typename T>\ni128 CRT(vc<T> vals, vc<T> mods, ll new_mod\
    \ = -1, bool coprime = false) {\n  int n = len(vals);\n  FOR(i, n) {\n    vals[i]\
    \ = ((vals[i] %= mods[i]) >= 0 ? vals[i] : vals[i] + mods[i]);\n  }\n\n  bool\
    \ ng = 0;\n  auto reduction_by_factor = [&]() -> void {\n    unordered_map<T,\
    \ pair<T, int>> MP;\n    FOR(i, n) {\n      for (auto&& [p, e]: factor(mods[i]))\
    \ {\n        T mod = 1;\n        FOR(e) mod *= p;\n        T val = vals[i] % mod;\n\
    \        if (!MP.count(p)) {\n          MP[p] = {mod, val % mod};\n          continue;\n\
    \        }\n        auto& [mod1, val1] = MP[p];\n        if (mod > mod1) swap(mod,\
    \ mod1), swap(val, val1);\n        if (val1 % mod != val) {\n          ng = 1;\n\
    \          return;\n        }\n      }\n    }\n    mods.clear(), vals.clear();\n\
    \    for (auto&& [p, x]: MP) {\n      auto [mod, val] = x;\n      mods.eb(mod),\
    \ vals.eb(val);\n    }\n    n = len(vals);\n  };\n  auto reduction_by_coprime_factor\
    \ = [&]() -> void {\n    auto [basis, pfs] = coprime_factorization<T>(mods);\n\
    \    int k = len(basis);\n    vc<pair<T, int>> dat(k, {1, 0});\n    FOR(i, n)\
    \ {\n      for (auto&& [pid, exp]: pfs[i]) {\n        T mod = 1;\n        FOR(exp)\
    \ mod *= basis[pid];\n        T val = vals[i] % mod;\n        auto& [mod1, val1]\
    \ = dat[pid];\n        if (mod > mod1) swap(mod, mod1), swap(val, val1);\n   \
    \     if (val1 % mod != val) {\n          ng = 1;\n          return;\n       \
    \ }\n      }\n    }\n    mods.clear(), vals.clear();\n    for (auto&& [mod, val]:\
    \ dat) { mods.eb(mod), vals.eb(val); }\n    n = len(vals);\n  };\n  if (!coprime)\
    \ {\n    (n <= 10 ? reduction_by_coprime_factor() : reduction_by_factor());\n\
    \  }\n\n  if (ng) return -1;\n  if (n == 0) return 0;\n\n  vc<ll> cfs(n);\n  if\
    \ (MAX(mods) < (1LL << 31)) {\n    FOR(i, n) {\n      Barrett bt(mods[i]);\n \
    \     ll a = vals[i], prod = 1;\n      FOR(j, i) {\n        a = bt.modulo(a +\
    \ cfs[j] * (mods[i] - prod));\n        prod = bt.mul(prod, mods[j]);\n      }\n\
    \      cfs[i] = bt.mul(mod_inv(prod, mods[i]), a);\n    }\n  } else {\n    FOR(i,\
    \ n) {\n      ll a = vals[i], prod = 1;\n      FOR(j, i) {\n        a = (a + i128(cfs[j])\
    \ * (mods[i] - prod)) % mods[i];\n        prod = i128(prod) * mods[j] % mods[i];\n\
    \      }\n      cfs[i] = mod_inv(prod, mods[i]) * i128(a) % mods[i];\n    }\n\
    \  }\n  i128 ret = 0, prod = 1;\n  FOR(i, n) {\n    ret += prod * cfs[i], prod\
    \ *= mods[i];\n    if (new_mod != -1) { ret %= new_mod, prod %= new_mod; }\n \
    \ }\n  return ret;\n}\n"
  code: "#include \"mod/mod_inv.hpp\"\n#include \"nt/coprime_factorization.hpp\"\n\
    #include \"nt/factor.hpp\"\n#include \"mod/barrett.hpp\"\n\n// \u975E\u8CA0\u6700\
    \u5C0F\u89E3\u3092 mod new_mod \u3067\u8FD4\u3059 (garner)\ntemplate <typename\
    \ T>\ni128 CRT(vc<T> vals, vc<T> mods, ll new_mod = -1, bool coprime = false)\
    \ {\n  int n = len(vals);\n  FOR(i, n) {\n    vals[i] = ((vals[i] %= mods[i])\
    \ >= 0 ? vals[i] : vals[i] + mods[i]);\n  }\n\n  bool ng = 0;\n  auto reduction_by_factor\
    \ = [&]() -> void {\n    unordered_map<T, pair<T, int>> MP;\n    FOR(i, n) {\n\
    \      for (auto&& [p, e]: factor(mods[i])) {\n        T mod = 1;\n        FOR(e)\
    \ mod *= p;\n        T val = vals[i] % mod;\n        if (!MP.count(p)) {\n   \
    \       MP[p] = {mod, val % mod};\n          continue;\n        }\n        auto&\
    \ [mod1, val1] = MP[p];\n        if (mod > mod1) swap(mod, mod1), swap(val, val1);\n\
    \        if (val1 % mod != val) {\n          ng = 1;\n          return;\n    \
    \    }\n      }\n    }\n    mods.clear(), vals.clear();\n    for (auto&& [p, x]:\
    \ MP) {\n      auto [mod, val] = x;\n      mods.eb(mod), vals.eb(val);\n    }\n\
    \    n = len(vals);\n  };\n  auto reduction_by_coprime_factor = [&]() -> void\
    \ {\n    auto [basis, pfs] = coprime_factorization<T>(mods);\n    int k = len(basis);\n\
    \    vc<pair<T, int>> dat(k, {1, 0});\n    FOR(i, n) {\n      for (auto&& [pid,\
    \ exp]: pfs[i]) {\n        T mod = 1;\n        FOR(exp) mod *= basis[pid];\n \
    \       T val = vals[i] % mod;\n        auto& [mod1, val1] = dat[pid];\n     \
    \   if (mod > mod1) swap(mod, mod1), swap(val, val1);\n        if (val1 % mod\
    \ != val) {\n          ng = 1;\n          return;\n        }\n      }\n    }\n\
    \    mods.clear(), vals.clear();\n    for (auto&& [mod, val]: dat) { mods.eb(mod),\
    \ vals.eb(val); }\n    n = len(vals);\n  };\n  if (!coprime) {\n    (n <= 10 ?\
    \ reduction_by_coprime_factor() : reduction_by_factor());\n  }\n\n  if (ng) return\
    \ -1;\n  if (n == 0) return 0;\n\n  vc<ll> cfs(n);\n  if (MAX(mods) < (1LL <<\
    \ 31)) {\n    FOR(i, n) {\n      Barrett bt(mods[i]);\n      ll a = vals[i], prod\
    \ = 1;\n      FOR(j, i) {\n        a = bt.modulo(a + cfs[j] * (mods[i] - prod));\n\
    \        prod = bt.mul(prod, mods[j]);\n      }\n      cfs[i] = bt.mul(mod_inv(prod,\
    \ mods[i]), a);\n    }\n  } else {\n    FOR(i, n) {\n      ll a = vals[i], prod\
    \ = 1;\n      FOR(j, i) {\n        a = (a + i128(cfs[j]) * (mods[i] - prod)) %\
    \ mods[i];\n        prod = i128(prod) * mods[j] % mods[i];\n      }\n      cfs[i]\
    \ = mod_inv(prod, mods[i]) * i128(a) % mods[i];\n    }\n  }\n  i128 ret = 0, prod\
    \ = 1;\n  FOR(i, n) {\n    ret += prod * cfs[i], prod *= mods[i];\n    if (new_mod\
    \ != -1) { ret %= new_mod, prod %= new_mod; }\n  }\n  return ret;\n}"
  dependsOn:
  - mod/mod_inv.hpp
  - nt/coprime_factorization.hpp
  - nt/factor.hpp
  - random/base.hpp
  - nt/primetest.hpp
  - mod/mongomery_modint.hpp
  - mod/barrett.hpp
  isVerificationFile: false
  path: nt/crt.hpp
  requiredBy: []
  timestamp: '2023-11-02 05:00:07+09:00'
  verificationStatus: LIBRARY_ALL_WA
  verifiedWith:
  - test/yukicoder/187.test.cpp
  - test/yukicoder/590.test.cpp
  - test/yukicoder/1956.test.cpp
  - test/yukicoder/2119.test.cpp
documentation_of: nt/crt.hpp
layout: document
redirect_from:
- /library/nt/crt.hpp
- /library/nt/crt.hpp.html
title: nt/crt.hpp
---
