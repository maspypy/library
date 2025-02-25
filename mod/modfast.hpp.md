---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: ds/hashmap.hpp
    title: ds/hashmap.hpp
  - icon: ':heavy_check_mark:'
    path: mod/barrett.hpp
    title: mod/barrett.hpp
  - icon: ':heavy_check_mark:'
    path: mod/mod_inv.hpp
    title: mod/mod_inv.hpp
  - icon: ':heavy_check_mark:'
    path: mod/mod_log_998244353.hpp
    title: mod/mod_log_998244353.hpp
  - icon: ':heavy_check_mark:'
    path: mod/mod_pow.hpp
    title: mod/mod_pow.hpp
  - icon: ':heavy_check_mark:'
    path: mod/modint.hpp
    title: mod/modint.hpp
  - icon: ':heavy_check_mark:'
    path: mod/modint_common.hpp
    title: mod/modint_common.hpp
  - icon: ':heavy_check_mark:'
    path: mod/mongomery_modint.hpp
    title: mod/mongomery_modint.hpp
  - icon: ':heavy_check_mark:'
    path: mod/primitive_root.hpp
    title: mod/primitive_root.hpp
  - icon: ':heavy_check_mark:'
    path: nt/factor.hpp
    title: nt/factor.hpp
  - icon: ':heavy_check_mark:'
    path: nt/lpf_table.hpp
    title: nt/lpf_table.hpp
  - icon: ':heavy_check_mark:'
    path: nt/primetable.hpp
    title: nt/primetable.hpp
  - icon: ':heavy_check_mark:'
    path: nt/primetest.hpp
    title: nt/primetest.hpp
  - icon: ':heavy_check_mark:'
    path: random/base.hpp
    title: random/base.hpp
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/1_mytest/modfast.test.cpp
    title: test/1_mytest/modfast.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 2 \"mod/primitive_root.hpp\"\n\r\n#line 2 \"nt/factor.hpp\"\n\
    \n#line 2 \"random/base.hpp\"\n\nu64 RNG_64() {\n  static u64 x_ = u64(chrono::duration_cast<chrono::nanoseconds>(chrono::high_resolution_clock::now().time_since_epoch()).count())\
    \ * 10150724397891781847ULL;\n  x_ ^= x_ << 7;\n  return x_ ^= x_ >> 9;\n}\n\n\
    u64 RNG(u64 lim) { return RNG_64() % lim; }\n\nll RNG(ll l, ll r) { return l +\
    \ RNG_64() % (r - l); }\n#line 2 \"mod/mongomery_modint.hpp\"\n\n// odd mod.\n\
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
    \ g += q / p;\r\n  }\r\n  return g;\r\n}\r\n#line 2 \"mod/modint_common.hpp\"\n\
    \nstruct has_mod_impl {\n  template <class T>\n  static auto check(T &&x) -> decltype(x.get_mod(),\
    \ std::true_type{});\n  template <class T>\n  static auto check(...) -> std::false_type;\n\
    };\n\ntemplate <class T>\nclass has_mod : public decltype(has_mod_impl::check<T>(std::declval<T>()))\
    \ {};\n\ntemplate <typename mint>\nmint inv(int n) {\n  static const int mod =\
    \ mint::get_mod();\n  static vector<mint> dat = {0, 1};\n  assert(0 <= n);\n \
    \ if (n >= mod) n %= mod;\n  while (len(dat) <= n) {\n    int k = len(dat);\n\
    \    int q = (mod + k - 1) / k;\n    dat.eb(dat[k * q - mod] * mint::raw(q));\n\
    \  }\n  return dat[n];\n}\n\ntemplate <typename mint>\nmint fact(int n) {\n  static\
    \ const int mod = mint::get_mod();\n  assert(0 <= n && n < mod);\n  static vector<mint>\
    \ dat = {1, 1};\n  while (len(dat) <= n) dat.eb(dat[len(dat) - 1] * mint::raw(len(dat)));\n\
    \  return dat[n];\n}\n\ntemplate <typename mint>\nmint fact_inv(int n) {\n  static\
    \ vector<mint> dat = {1, 1};\n  if (n < 0) return mint(0);\n  while (len(dat)\
    \ <= n) dat.eb(dat[len(dat) - 1] * inv<mint>(len(dat)));\n  return dat[n];\n}\n\
    \ntemplate <class mint, class... Ts>\nmint fact_invs(Ts... xs) {\n  return (mint(1)\
    \ * ... * fact_inv<mint>(xs));\n}\n\ntemplate <typename mint, class Head, class...\
    \ Tail>\nmint multinomial(Head &&head, Tail &&... tail) {\n  return fact<mint>(head)\
    \ * fact_invs<mint>(std::forward<Tail>(tail)...);\n}\n\ntemplate <typename mint>\n\
    mint C_dense(int n, int k) {\n  assert(n >= 0);\n  if (k < 0 || n < k) return\
    \ 0;\n  static vvc<mint> C;\n  static int H = 0, W = 0;\n  auto calc = [&](int\
    \ i, int j) -> mint {\n    if (i == 0) return (j == 0 ? mint(1) : mint(0));\n\
    \    return C[i - 1][j] + (j ? C[i - 1][j - 1] : 0);\n  };\n  if (W <= k) {\n\
    \    FOR(i, H) {\n      C[i].resize(k + 1);\n      FOR(j, W, k + 1) { C[i][j]\
    \ = calc(i, j); }\n    }\n    W = k + 1;\n  }\n  if (H <= n) {\n    C.resize(n\
    \ + 1);\n    FOR(i, H, n + 1) {\n      C[i].resize(W);\n      FOR(j, W) { C[i][j]\
    \ = calc(i, j); }\n    }\n    H = n + 1;\n  }\n  return C[n][k];\n}\n\ntemplate\
    \ <typename mint, bool large = false, bool dense = false>\nmint C(ll n, ll k)\
    \ {\n  assert(n >= 0);\n  if (k < 0 || n < k) return 0;\n  if constexpr (dense)\
    \ return C_dense<mint>(n, k);\n  if constexpr (!large) return multinomial<mint>(n,\
    \ k, n - k);\n  k = min(k, n - k);\n  mint x(1);\n  FOR(i, k) x *= mint(n - i);\n\
    \  return x * fact_inv<mint>(k);\n}\n\ntemplate <typename mint, bool large = false>\n\
    mint C_inv(ll n, ll k) {\n  assert(n >= 0);\n  assert(0 <= k && k <= n);\n  if\
    \ (!large) return fact_inv<mint>(n) * fact<mint>(k) * fact<mint>(n - k);\n  return\
    \ mint(1) / C<mint, 1>(n, k);\n}\n\n// [x^d](1-x)^{-n}\ntemplate <typename mint,\
    \ bool large = false, bool dense = false>\nmint C_negative(ll n, ll d) {\n  assert(n\
    \ >= 0);\n  if (d < 0) return mint(0);\n  if (n == 0) { return (d == 0 ? mint(1)\
    \ : mint(0)); }\n  return C<mint, large, dense>(n + d - 1, d);\n}\n#line 3 \"\
    mod/modint.hpp\"\n\ntemplate <int mod>\nstruct modint {\n  static constexpr u32\
    \ umod = u32(mod);\n  static_assert(umod < u32(1) << 31);\n  u32 val;\n\n  static\
    \ modint raw(u32 v) {\n    modint x;\n    x.val = v;\n    return x;\n  }\n  constexpr\
    \ modint() : val(0) {}\n  constexpr modint(u32 x) : val(x % umod) {}\n  constexpr\
    \ modint(u64 x) : val(x % umod) {}\n  constexpr modint(u128 x) : val(x % umod)\
    \ {}\n  constexpr modint(int x) : val((x %= mod) < 0 ? x + mod : x){};\n  constexpr\
    \ modint(ll x) : val((x %= mod) < 0 ? x + mod : x){};\n  constexpr modint(i128\
    \ x) : val((x %= mod) < 0 ? x + mod : x){};\n  bool operator<(const modint &other)\
    \ const { return val < other.val; }\n  modint &operator+=(const modint &p) {\n\
    \    if ((val += p.val) >= umod) val -= umod;\n    return *this;\n  }\n  modint\
    \ &operator-=(const modint &p) {\n    if ((val += umod - p.val) >= umod) val -=\
    \ umod;\n    return *this;\n  }\n  modint &operator*=(const modint &p) {\n   \
    \ val = u64(val) * p.val % umod;\n    return *this;\n  }\n  modint &operator/=(const\
    \ modint &p) {\n    *this *= p.inverse();\n    return *this;\n  }\n  modint operator-()\
    \ const { return modint::raw(val ? mod - val : u32(0)); }\n  modint operator+(const\
    \ modint &p) const { return modint(*this) += p; }\n  modint operator-(const modint\
    \ &p) const { return modint(*this) -= p; }\n  modint operator*(const modint &p)\
    \ const { return modint(*this) *= p; }\n  modint operator/(const modint &p) const\
    \ { return modint(*this) /= p; }\n  bool operator==(const modint &p) const { return\
    \ val == p.val; }\n  bool operator!=(const modint &p) const { return val != p.val;\
    \ }\n  modint inverse() const {\n    int a = val, b = mod, u = 1, v = 0, t;\n\
    \    while (b > 0) {\n      t = a / b;\n      swap(a -= t * b, b), swap(u -= t\
    \ * v, v);\n    }\n    return modint(u);\n  }\n  modint pow(ll n) const {\n  \
    \  if (n < 0) return inverse().pow(-n);\n    assert(n >= 0);\n    modint ret(1),\
    \ mul(val);\n    while (n > 0) {\n      if (n & 1) ret *= mul;\n      mul *= mul;\n\
    \      n >>= 1;\n    }\n    return ret;\n  }\n  static constexpr int get_mod()\
    \ { return mod; }\n  // (n, r), r \u306F 1 \u306E 2^n \u4E57\u6839\n  static constexpr\
    \ pair<int, int> ntt_info() {\n    if (mod == 120586241) return {20, 74066978};\n\
    \    if (mod == 167772161) return {25, 17};\n    if (mod == 469762049) return\
    \ {26, 30};\n    if (mod == 754974721) return {24, 362};\n    if (mod == 880803841)\
    \ return {23, 211};\n    if (mod == 943718401) return {22, 663003469};\n    if\
    \ (mod == 998244353) return {23, 31};\n    if (mod == 1004535809) return {21,\
    \ 582313106};\n    if (mod == 1012924417) return {21, 368093570};\n    return\
    \ {-1, -1};\n  }\n  static constexpr bool can_ntt() { return ntt_info().fi !=\
    \ -1; }\n};\n\n#ifdef FASTIO\ntemplate <int mod>\nvoid rd(modint<mod> &x) {\n\
    \  fastio::rd(x.val);\n  x.val %= mod;\n  // assert(0 <= x.val && x.val < mod);\n\
    }\ntemplate <int mod>\nvoid wt(modint<mod> x) {\n  fastio::wt(x.val);\n}\n#endif\n\
    \nusing modint107 = modint<1000000007>;\nusing modint998 = modint<998244353>;\n\
    #line 2 \"mod/mod_inv.hpp\"\n\r\n// long \u3067\u3082\u5927\u4E08\u592B\r\n//\
    \ (val * x - 1) \u304C mod \u306E\u500D\u6570\u306B\u306A\u308B\u3088\u3046\u306B\
    \u3059\u308B\r\n// \u7279\u306B mod=0 \u306A\u3089 x=0 \u304C\u6E80\u305F\u3059\
    \r\nll mod_inv(ll val, ll mod) {\r\n  if (mod == 0) return 0;\r\n  mod = abs(mod);\r\
    \n  val %= mod;\r\n  if (val < 0) val += mod;\r\n  ll a = val, b = mod, u = 1,\
    \ v = 0, t;\r\n  while (b > 0) {\r\n    t = a / b;\r\n    swap(a -= t * b, b),\
    \ swap(u -= t * v, v);\r\n  }\r\n  if (u < 0) u += mod;\r\n  return u;\r\n}\r\n\
    #line 3 \"mod/mod_log_998244353.hpp\"\n\nnamespace DISCRETE_LOG_998 {\nconst int\
    \ A = 32768;\nconst int B = 30464;\nconst int r = 3;\nconst int mod = 998244353;\n\
    \nu32 rpow_0[A + 1];\nu32 rpow_1[A + 1];\nu32 AX[4 * B + 1];\nu32 AI[4 * B + 1];\n\
    u32 BX[4 * B + 1];\nu32 BI[4 * B + 1];\n\nu32 get_pow_30(u32 n) { return u64(rpow_1[n\
    \ / A]) * rpow_0[n % A] % mod; }\nu32 get_pow(u64 n) { return get_pow_30(n % (mod\
    \ - 1)); }\nu32 H(u32 x) { return x >> 13; }; // hash func\n\nvoid __attribute__((constructor))\
    \ init_table() {\n  rpow_0[0] = rpow_1[0] = 1;\n  FOR(i, A) rpow_0[i + 1] = u64(rpow_0[i])\
    \ * r % mod;\n  FOR(i, A) rpow_1[i + 1] = u64(rpow_1[i]) * rpow_0[A] % mod;\n\
    \  FOR(i, B) {\n    u32 x = get_pow_30(A * i);\n    int k = H(x);\n    while (AX[k])\
    \ ++k;\n    AX[k] = x, AI[k] = i;\n  }\n  FOR(i, A) {\n    u32 x = get_pow_30(B\
    \ * i);\n    int k = H(x);\n    while (BX[k]) ++k;\n    BX[k] = x, BI[k] = i;\n\
    \  }\n}\n\n// \u639B\u3051\u7B97 17 \u56DE + hashmap 2 \u56DE\n// 10^7 \u56DE\
    \ 0.6 sec\nint mod_log_998_primitive_root(modint998 a) {\n  // a^A \u306F 1 \u306E\
    \ B \u4E57\u6839\u306A\u306E\u3067 pow(r, xA) \u3068\u66F8\u3051\u308B\n  modint998\
    \ b = a;\n  FOR(15) b *= b;\n  int k = H(b.val);\n  while (AX[k] != b.val) ++k;\n\
    \  int x = AI[k];\n  // ar^{-x} \u306F 1 \u306E A \u4E57\u6839\u306A\u306E\u3067\
    \ pow(r, yB) \u3068\u66F8\u3051\u308B\n  a *= get_pow_30(mod - 1 - x);\n  k =\
    \ H(a.val);\n  while (BX[k] != a.val) ++k;\n  int y = BI[k];\n  return x + y *\
    \ B;\n}\n\nint mod_log_998(int a, int b) {\n  int x = mod_log_998_primitive_root(a);\n\
    \  int y = mod_log_998_primitive_root(b);\n  int m = 998244353 - 1;\n  int g =\
    \ gcd(x, m);\n  if (y % g != 0) return -1;\n  x /= g, y /= g, m /= g;\n  return\
    \ mod_inv(x, g) * y % m;\n}\n\nu32 mod_pow_998_primitive_root(u64 n) { return\
    \ get_pow(n); }\n} // namespace DISCRETE_LOG_998\nusing DISCRETE_LOG_998::mod_pow_998_primitive_root;\n\
    using DISCRETE_LOG_998::mod_log_998_primitive_root;\nusing DISCRETE_LOG_998::mod_log_998;\n\
    #line 2 \"nt/primetable.hpp\"\n\ntemplate <typename T = int>\nvc<T> primetable(int\
    \ LIM) {\n  ++LIM;\n  const int S = 32768;\n  static int done = 2;\n  static vc<T>\
    \ primes = {2}, sieve(S + 1);\n\n  if (done < LIM) {\n    done = LIM;\n\n    primes\
    \ = {2}, sieve.assign(S + 1, 0);\n    const int R = LIM / 2;\n    primes.reserve(int(LIM\
    \ / log(LIM) * 1.1));\n    vc<pair<int, int>> cp;\n    for (int i = 3; i <= S;\
    \ i += 2) {\n      if (!sieve[i]) {\n        cp.eb(i, i * i / 2);\n        for\
    \ (int j = i * i; j <= S; j += 2 * i) sieve[j] = 1;\n      }\n    }\n    for (int\
    \ L = 1; L <= R; L += S) {\n      array<bool, S> block{};\n      for (auto& [p,\
    \ idx]: cp)\n        for (int i = idx; i < S + L; idx = (i += p)) block[i - L]\
    \ = 1;\n      FOR(i, min(S, R - L)) if (!block[i]) primes.eb((L + i) * 2 + 1);\n\
    \    }\n  }\n  int k = LB(primes, LIM + 1);\n  return {primes.begin(), primes.begin()\
    \ + k};\n}\n#line 3 \"nt/lpf_table.hpp\"\n\n// [0, LIM], 0, 1 \u306B\u306F -1\
    \ \u304C\u5165\u308B\u3002\nvc<int> lpf_table(ll LIM) {\n  auto primes = primetable(LIM);\n\
    \  vc<int> res(LIM + 1, -1);\n  FOR_R(i, len(primes)) {\n    auto p = primes[i];\n\
    \    FOR3(j, 1, LIM / p + 1) res[p * j] = p;\n  }\n  return res;\n}\n#line 2 \"\
    ds/hashmap.hpp\"\n\r\n// u64 -> Val\r\ntemplate <typename Val>\r\nstruct HashMap\
    \ {\r\n  // n \u306F\u5165\u308C\u305F\u3044\u3082\u306E\u306E\u500B\u6570\u3067\
    \ ok\r\n  HashMap(u32 n = 0) { build(n); }\r\n  void build(u32 n) {\r\n    u32\
    \ k = 8;\r\n    while (k < n * 2) k *= 2;\r\n    cap = k / 2, mask = k - 1;\r\n\
    \    key.resize(k), val.resize(k), used.assign(k, 0);\r\n  }\r\n\r\n  // size\
    \ \u3092\u4FDD\u3063\u305F\u307E\u307E. size=0 \u306B\u3059\u308B\u3068\u304D\u306F\
    \ build \u3059\u308B\u3053\u3068.\r\n  void clear() {\r\n    used.assign(len(used),\
    \ 0);\r\n    cap = (mask + 1) / 2;\r\n  }\r\n  int size() { return len(used) /\
    \ 2 - cap; }\r\n\r\n  int index(const u64& k) {\r\n    int i = 0;\r\n    for (i\
    \ = hash(k); used[i] && key[i] != k; i = (i + 1) & mask) {}\r\n    return i;\r\
    \n  }\r\n\r\n  Val& operator[](const u64& k) {\r\n    if (cap == 0) extend();\r\
    \n    int i = index(k);\r\n    if (!used[i]) { used[i] = 1, key[i] = k, val[i]\
    \ = Val{}, --cap; }\r\n    return val[i];\r\n  }\r\n\r\n  Val get(const u64& k,\
    \ Val default_value) {\r\n    int i = index(k);\r\n    return (used[i] ? val[i]\
    \ : default_value);\r\n  }\r\n\r\n  bool count(const u64& k) {\r\n    int i =\
    \ index(k);\r\n    return used[i] && key[i] == k;\r\n  }\r\n\r\n  // f(key, val)\r\
    \n  template <typename F>\r\n  void enumerate_all(F f) {\r\n    FOR(i, len(used))\
    \ if (used[i]) f(key[i], val[i]);\r\n  }\r\n\r\nprivate:\r\n  u32 cap, mask;\r\
    \n  vc<u64> key;\r\n  vc<Val> val;\r\n  vc<bool> used;\r\n\r\n  u64 hash(u64 x)\
    \ {\r\n    static const u64 FIXED_RANDOM = std::chrono::steady_clock::now().time_since_epoch().count();\r\
    \n    x += FIXED_RANDOM;\r\n    x = (x ^ (x >> 30)) * 0xbf58476d1ce4e5b9;\r\n\
    \    x = (x ^ (x >> 27)) * 0x94d049bb133111eb;\r\n    return (x ^ (x >> 31)) &\
    \ mask;\r\n  }\r\n\r\n  void extend() {\r\n    vc<pair<u64, Val>> dat;\r\n   \
    \ dat.reserve(len(used) / 2 - cap);\r\n    FOR(i, len(used)) {\r\n      if (used[i])\
    \ dat.eb(key[i], val[i]);\r\n    }\r\n    build(2 * len(dat));\r\n    for (auto&\
    \ [a, b]: dat) (*this)[a] = b;\r\n  }\r\n};\n#line 5 \"mod/modfast.hpp\"\n\ntemplate\
    \ <int p>\nstruct ModFast {\n  static_assert(p < (1 << 30));\n\n  u32 root;\n\
    \  array<u32, 65537> POW[2];\n  array<pair<u16, u16>, 1 + (1 << 20)> FRAC;\n\n\
    \  static constexpr int K = 1 << 21;\n  array<u32, 2 * K + 1> LOG;\n  array<u32,\
    \ 2 * K + 1> INV;\n\n  ModFast() {\n    root = (p == 998244353 ? 3 : primitive_root(p));\n\
    \    build_pow();\n    build_inv();\n    build_log();\n    build_frac();\n  }\n\
    \n  void build_inv() {\n    INV[K + 1] = 1;\n    for (u32 i = 2; i <= K; ++i)\
    \ {\n      u64 q = (p + i - 1) / i;\n      INV[K + i] = INV[K + i * q - p] * u64(q)\
    \ % p;\n    }\n    FOR(i, 1, K + 1) INV[K - i] = p - INV[K + i];\n  }\n\n  u32\
    \ pow(u32 a, ll exp) {\n    assert(0 <= a && a < p && exp >= 0);\n    if (a ==\
    \ 0) return (exp == 0 ? 1 : 0);\n    exp %= p - 1;\n    assert(pow_r(log_r(a))\
    \ == a);\n    return pow_r(log_r(a) * exp % (p - 1));\n  }\n\n  u32 pow_r(u32\
    \ exp) {\n    assert(0 <= exp && exp <= 2 * p - 2);\n    return u64(POW[0][exp\
    \ & 65535]) * POW[1][exp >> 16] % p;\n  }\n\n  // [0, 2p-2)\n  u32 log_r(u32 x)\
    \ {\n    assert(1 <= x && x < p);\n    auto [a, b] = FRAC[x >> 10];\n    u32 t\
    \ = x * b - a * p;\n    return LOG[K + t] + (p - 1) - LOG[K + b];\n  }\n\n  u32\
    \ inverse(u32 x) {\n    assert(1 <= x && x < p);\n    auto [a, b] = FRAC[x >>\
    \ 10];\n    u32 t = x * b - a * p;\n    return INV[K + t] * u64(b) % p;\n  }\n\
    \nprivate:\n  void build_pow() {\n    POW[0][0] = POW[1][0] = 1;\n    FOR(i, (1\
    \ << 16)) POW[0][i + 1] = POW[0][i] * u64(root) % p;\n    FOR(i, (1 << 16)) POW[1][i\
    \ + 1] = POW[1][i] * u64(POW[0][1 << 16]) % p;\n  }\n\n  // 0.72sec [0.10sec if\
    \ p=998]\n  void build_log() {\n    if (p == 998244353) return build_log_998();\n\
    \    auto lpf = lpf_table(1 << 21);\n    const int S = 5'000'000;\n    HashMap<u32>\
    \ MP(S);\n    u32 pw = 1;\n    for (int k = 0; k < S; ++k, pw = u64(root) * pw\
    \ % p) { MP[pw] = k; }\n    u32 q = pow_r(p - 1 - S);\n\n    LOG[K + 1] = 0;\n\
    \    FOR(i, 2, 1 + (1 << 21)) {\n      if (lpf[i] < i) {\n        LOG[K + i] =\
    \ (LOG[K + lpf[i]] + LOG[K + i / lpf[i]]) % (p - 1);\n        continue;\n    \
    \  }\n      u32 s = i;\n      LOG[K + i] = 0;\n      while (1) {\n        u32\
    \ v = MP.get(s, -1);\n        if (v != u32(-1)) {\n          LOG[K + i] += v;\n\
    \          break;\n        }\n        LOG[K + i] += S, s = u64(s) * q % p;\n \
    \     }\n    }\n    FOR(i, 1, 1 + (1 << 21)) { LOG[K - i] = (LOG[K + i] + (p -\
    \ 1) / 2) % (p - 1); }\n  }\n\n  void build_log_998() {\n    auto lpf = lpf_table(1\
    \ << 21);\n    LOG[K + 1] = 0;\n    FOR(i, 2, 1 + (1 << 21)) { LOG[K + i] = (lpf[i]\
    \ < i ? (LOG[K + lpf[i]] + LOG[K + i / lpf[i]]) % (p - 1) : mod_log_998_primitive_root(i));\
    \ }\n    FOR(i, 1, 1 + (1 << 21)) { LOG[K - i] = (LOG[K + i] + (p - 1) / 2) %\
    \ (p - 1); }\n  }\n\n  void build_frac() {\n    vc<tuple<u16, u16, u16, u16>>\
    \ que;\n    que.eb(0, 1, 1, 1);\n    while (len(que)) {\n      auto [a, b, c,\
    \ d] = POP(que);\n      if (b + d < 2048) {\n        que.eb(a + c, b + d, c, d),\
    \ que.eb(a, b, a + c, b + d);\n        continue;\n      }\n      u32 s = (u64(a)\
    \ * p) / (1024 * b);\n      u32 t = (u64(c) * p) / (1024 * d);\n      FRAC[s]\
    \ = {a, b}, FRAC[t] = {c, d};\n      a = min(a, c), b = min(b, d);\n      FOR(i,\
    \ s + 1, t) FRAC[i] = {a, b};\n    }\n  }\n};\n"
  code: "#include \"mod/primitive_root.hpp\"\n#include \"mod/mod_log_998244353.hpp\"\
    \n#include \"nt/lpf_table.hpp\"\n#include \"ds/hashmap.hpp\"\n\ntemplate <int\
    \ p>\nstruct ModFast {\n  static_assert(p < (1 << 30));\n\n  u32 root;\n  array<u32,\
    \ 65537> POW[2];\n  array<pair<u16, u16>, 1 + (1 << 20)> FRAC;\n\n  static constexpr\
    \ int K = 1 << 21;\n  array<u32, 2 * K + 1> LOG;\n  array<u32, 2 * K + 1> INV;\n\
    \n  ModFast() {\n    root = (p == 998244353 ? 3 : primitive_root(p));\n    build_pow();\n\
    \    build_inv();\n    build_log();\n    build_frac();\n  }\n\n  void build_inv()\
    \ {\n    INV[K + 1] = 1;\n    for (u32 i = 2; i <= K; ++i) {\n      u64 q = (p\
    \ + i - 1) / i;\n      INV[K + i] = INV[K + i * q - p] * u64(q) % p;\n    }\n\
    \    FOR(i, 1, K + 1) INV[K - i] = p - INV[K + i];\n  }\n\n  u32 pow(u32 a, ll\
    \ exp) {\n    assert(0 <= a && a < p && exp >= 0);\n    if (a == 0) return (exp\
    \ == 0 ? 1 : 0);\n    exp %= p - 1;\n    assert(pow_r(log_r(a)) == a);\n    return\
    \ pow_r(log_r(a) * exp % (p - 1));\n  }\n\n  u32 pow_r(u32 exp) {\n    assert(0\
    \ <= exp && exp <= 2 * p - 2);\n    return u64(POW[0][exp & 65535]) * POW[1][exp\
    \ >> 16] % p;\n  }\n\n  // [0, 2p-2)\n  u32 log_r(u32 x) {\n    assert(1 <= x\
    \ && x < p);\n    auto [a, b] = FRAC[x >> 10];\n    u32 t = x * b - a * p;\n \
    \   return LOG[K + t] + (p - 1) - LOG[K + b];\n  }\n\n  u32 inverse(u32 x) {\n\
    \    assert(1 <= x && x < p);\n    auto [a, b] = FRAC[x >> 10];\n    u32 t = x\
    \ * b - a * p;\n    return INV[K + t] * u64(b) % p;\n  }\n\nprivate:\n  void build_pow()\
    \ {\n    POW[0][0] = POW[1][0] = 1;\n    FOR(i, (1 << 16)) POW[0][i + 1] = POW[0][i]\
    \ * u64(root) % p;\n    FOR(i, (1 << 16)) POW[1][i + 1] = POW[1][i] * u64(POW[0][1\
    \ << 16]) % p;\n  }\n\n  // 0.72sec [0.10sec if p=998]\n  void build_log() {\n\
    \    if (p == 998244353) return build_log_998();\n    auto lpf = lpf_table(1 <<\
    \ 21);\n    const int S = 5'000'000;\n    HashMap<u32> MP(S);\n    u32 pw = 1;\n\
    \    for (int k = 0; k < S; ++k, pw = u64(root) * pw % p) { MP[pw] = k; }\n  \
    \  u32 q = pow_r(p - 1 - S);\n\n    LOG[K + 1] = 0;\n    FOR(i, 2, 1 + (1 << 21))\
    \ {\n      if (lpf[i] < i) {\n        LOG[K + i] = (LOG[K + lpf[i]] + LOG[K +\
    \ i / lpf[i]]) % (p - 1);\n        continue;\n      }\n      u32 s = i;\n    \
    \  LOG[K + i] = 0;\n      while (1) {\n        u32 v = MP.get(s, -1);\n      \
    \  if (v != u32(-1)) {\n          LOG[K + i] += v;\n          break;\n       \
    \ }\n        LOG[K + i] += S, s = u64(s) * q % p;\n      }\n    }\n    FOR(i,\
    \ 1, 1 + (1 << 21)) { LOG[K - i] = (LOG[K + i] + (p - 1) / 2) % (p - 1); }\n \
    \ }\n\n  void build_log_998() {\n    auto lpf = lpf_table(1 << 21);\n    LOG[K\
    \ + 1] = 0;\n    FOR(i, 2, 1 + (1 << 21)) { LOG[K + i] = (lpf[i] < i ? (LOG[K\
    \ + lpf[i]] + LOG[K + i / lpf[i]]) % (p - 1) : mod_log_998_primitive_root(i));\
    \ }\n    FOR(i, 1, 1 + (1 << 21)) { LOG[K - i] = (LOG[K + i] + (p - 1) / 2) %\
    \ (p - 1); }\n  }\n\n  void build_frac() {\n    vc<tuple<u16, u16, u16, u16>>\
    \ que;\n    que.eb(0, 1, 1, 1);\n    while (len(que)) {\n      auto [a, b, c,\
    \ d] = POP(que);\n      if (b + d < 2048) {\n        que.eb(a + c, b + d, c, d),\
    \ que.eb(a, b, a + c, b + d);\n        continue;\n      }\n      u32 s = (u64(a)\
    \ * p) / (1024 * b);\n      u32 t = (u64(c) * p) / (1024 * d);\n      FRAC[s]\
    \ = {a, b}, FRAC[t] = {c, d};\n      a = min(a, c), b = min(b, d);\n      FOR(i,\
    \ s + 1, t) FRAC[i] = {a, b};\n    }\n  }\n};\n"
  dependsOn:
  - mod/primitive_root.hpp
  - nt/factor.hpp
  - random/base.hpp
  - nt/primetest.hpp
  - mod/mongomery_modint.hpp
  - mod/mod_pow.hpp
  - mod/barrett.hpp
  - mod/mod_log_998244353.hpp
  - mod/modint.hpp
  - mod/modint_common.hpp
  - mod/mod_inv.hpp
  - nt/lpf_table.hpp
  - nt/primetable.hpp
  - ds/hashmap.hpp
  isVerificationFile: false
  path: mod/modfast.hpp
  requiredBy: []
  timestamp: '2025-02-25 18:00:53+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/1_mytest/modfast.test.cpp
documentation_of: mod/modfast.hpp
layout: document
redirect_from:
- /library/mod/modfast.hpp
- /library/mod/modfast.hpp.html
title: mod/modfast.hpp
---
