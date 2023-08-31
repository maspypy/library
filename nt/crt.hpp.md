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
    path: nt/coprime_factorization.hpp
    title: nt/coprime_factorization.hpp
  - icon: ':question:'
    path: nt/factor.hpp
    title: nt/factor.hpp
  - icon: ':question:'
    path: nt/primetest.hpp
    title: nt/primetest.hpp
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
  bundledCode: "#line 2 \"mod/mod_inv.hpp\"\n// long \u3067\u3082\u5927\u4E08\u592B\
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
    \ }\n  }\n  return {basis, res};\n}\n#line 2 \"nt/primetest.hpp\"\nstruct m64\
    \ {\r\n  using i64 = int64_t;\r\n  using u64 = uint64_t;\r\n  using u128 = __uint128_t;\r\
    \n\r\n  inline static u64 m, r, n2; // r * m = -1 (mod 1<<64), n2 = 1<<128 (mod\
    \ m)\r\n  static void set_mod(u64 m) {\r\n    assert((m & 1) == 1);\r\n    m64::m\
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
    \    res.eb(p, e);\n  }\n  return res;\n}\n#line 2 \"mod/barrett.hpp\"\n\n// https://github.com/atcoder/ac-library/blob/master/atcoder/internal_math.hpp\n\
    struct Barrett {\n  u32 m;\n  u64 im;\n  explicit Barrett(u32 m = 1) : m(m), im(u64(-1)\
    \ / m + 1) {}\n  u32 umod() const { return m; }\n  u32 modulo(u64 z) {\n    if\
    \ (m == 1) return 0;\n    u64 x = (u64)(((unsigned __int128)(z)*im) >> 64);\n\
    \    u64 y = x * m;\n    return (z - y + (z < y ? m : 0));\n  }\n  u64 floor(u64\
    \ z) {\n    if (m == 1) return z;\n    u64 x = (u64)(((unsigned __int128)(z)*im)\
    \ >> 64);\n    u64 y = x * m;\n    return (z < y ? x - 1 : x);\n  }\n  pair<u64,\
    \ u32> divmod(u64 z) {\n    if (m == 1) return {z, 0};\n    u64 x = (u64)(((unsigned\
    \ __int128)(z)*im) >> 64);\n    u64 y = x * m;\n    if (z < y) return {x - 1,\
    \ z - y + m};\n    return {x, z - y};\n  }\n  u32 mul(u32 a, u32 b) { return modulo(u64(a)\
    \ * b); }\n};\n#line 5 \"nt/crt.hpp\"\n\n// \u975E\u8CA0\u6700\u5C0F\u89E3\u3092\
    \ mod new_mod \u3067\u8FD4\u3059 (garner)\ntemplate <typename T>\ni128 CRT(vc<T>\
    \ vals, vc<T> mods, ll new_mod = -1, bool coprime = false) {\n  int n = len(vals);\n\
    \  FOR(i, n) {\n    vals[i] = ((vals[i] %= mods[i]) >= 0 ? vals[i] : vals[i] +\
    \ mods[i]);\n  }\n\n  bool ng = 0;\n  auto reduction_by_factor = [&]() -> void\
    \ {\n    unordered_map<T, pair<T, int>> MP;\n    FOR(i, n) {\n      for (auto&&\
    \ [p, e]: factor(mods[i])) {\n        T mod = 1;\n        FOR(e) mod *= p;\n \
    \       T val = vals[i] % mod;\n        if (!MP.count(p)) {\n          MP[p] =\
    \ {mod, val % mod};\n          continue;\n        }\n        auto& [mod1, val1]\
    \ = MP[p];\n        if (mod > mod1) swap(mod, mod1), swap(val, val1);\n      \
    \  if (val1 % mod != val) {\n          ng = 1;\n          return;\n        }\n\
    \      }\n    }\n    mods.clear(), vals.clear();\n    for (auto&& [p, x]: MP)\
    \ {\n      auto [mod, val] = x;\n      mods.eb(mod), vals.eb(val);\n    }\n  \
    \  n = len(vals);\n  };\n  auto reduction_by_coprime_factor = [&]() -> void {\n\
    \    auto [basis, pfs] = coprime_factorization<T>(mods);\n    int k = len(basis);\n\
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
    \ != -1) { ret %= new_mod, prod %= new_mod; }\n  }\n  return ret;\n}\n"
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
  - nt/primetest.hpp
  - mod/barrett.hpp
  isVerificationFile: false
  path: nt/crt.hpp
  requiredBy: []
  timestamp: '2023-08-20 22:02:21+09:00'
  verificationStatus: LIBRARY_ALL_WA
  verifiedWith:
  - test/yukicoder/2119.test.cpp
  - test/yukicoder/1956.test.cpp
  - test/yukicoder/187.test.cpp
  - test/yukicoder/590.test.cpp
documentation_of: nt/crt.hpp
layout: document
redirect_from:
- /library/nt/crt.hpp
- /library/nt/crt.hpp.html
title: nt/crt.hpp
---
