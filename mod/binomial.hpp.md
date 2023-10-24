---
data:
  _extendedDependsOn:
  - icon: ':question:'
    path: mod/barrett.hpp
    title: mod/barrett.hpp
  - icon: ':question:'
    path: mod/dynamic_modint_64.hpp
    title: mod/dynamic_modint_64.hpp
  - icon: ':question:'
    path: mod/mod_inv.hpp
    title: mod/mod_inv.hpp
  - icon: ':question:'
    path: mod/mod_pow.hpp
    title: mod/mod_pow.hpp
  - icon: ':question:'
    path: mod/modint_common.hpp
    title: mod/modint_common.hpp
  - icon: ':x:'
    path: mod/primitive_root.hpp
    title: mod/primitive_root.hpp
  - icon: ':x:'
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
  _verificationStatusIcon: ':x:'
  attributes:
    links: []
  bundledCode: "#line 2 \"mod/primitive_root.hpp\"\n\r\n#line 2 \"nt/factor.hpp\"\n\
    \n#line 2 \"random/base.hpp\"\n\nu64 RNG_64() {\n  static uint64_t x_\n      =\
    \ uint64_t(chrono::duration_cast<chrono::nanoseconds>(\n                     chrono::high_resolution_clock::now().time_since_epoch())\n\
    \                     .count())\n        * 10150724397891781847ULL;\n  x_ ^= x_\
    \ << 7;\n  return x_ ^= x_ >> 9;\n}\n\nu64 RNG(u64 lim) { return RNG_64() % lim;\
    \ }\n\nll RNG(ll l, ll r) { return l + RNG_64() % (r - l); }\n#line 2 \"mod/dynamic_modint_64.hpp\"\
    \n\n#line 2 \"mod/modint_common.hpp\"\n\nstruct has_mod_impl {\n  template <class\
    \ T>\n  static auto check(T &&x) -> decltype(x.get_mod(), std::true_type{});\n\
    \  template <class T>\n  static auto check(...) -> std::false_type;\n};\n\ntemplate\
    \ <class T>\nclass has_mod : public decltype(has_mod_impl::check<T>(std::declval<T>()))\
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
    mint C_dense(int n, int k) {\n  static vvc<mint> C;\n  static int H = 0, W = 0;\n\
    \  auto calc = [&](int i, int j) -> mint {\n    if (i == 0) return (j == 0 ? mint(1)\
    \ : mint(0));\n    return C[i - 1][j] + (j ? C[i - 1][j - 1] : 0);\n  };\n  if\
    \ (W <= k) {\n    FOR(i, H) {\n      C[i].resize(k + 1);\n      FOR(j, W, k +\
    \ 1) { C[i][j] = calc(i, j); }\n    }\n    W = k + 1;\n  }\n  if (H <= n) {\n\
    \    C.resize(n + 1);\n    FOR(i, H, n + 1) {\n      C[i].resize(W);\n      FOR(j,\
    \ W) { C[i][j] = calc(i, j); }\n    }\n    H = n + 1;\n  }\n  return C[n][k];\n\
    }\n\ntemplate <typename mint, bool large = false, bool dense = false>\nmint C(ll\
    \ n, ll k) {\n  assert(n >= 0);\n  if (k < 0 || n < k) return 0;\n  if constexpr\
    \ (dense) return C_dense<mint>(n, k);\n  if constexpr (!large) return multinomial<mint>(n,\
    \ k, n - k);\n  k = min(k, n - k);\n  mint x(1);\n  FOR(i, k) x *= mint(n - i);\n\
    \  return x * fact_inv<mint>(k);\n}\n\ntemplate <typename mint, bool large = false>\n\
    mint C_inv(ll n, ll k) {\n  assert(n >= 0);\n  assert(0 <= k && k <= n);\n  if\
    \ (!large) return fact_inv<mint>(n) * fact<mint>(k) * fact<mint>(n - k);\n  return\
    \ mint(1) / C<mint, 1>(n, k);\n}\n\n// [x^d] (1-x) ^ {-n} \u306E\u8A08\u7B97\n\
    template <typename mint, bool large = false, bool dense = false>\nmint C_negative(ll\
    \ n, ll d) {\n  assert(n >= 0);\n  if (d < 0) return mint(0);\n  if (n == 0) {\
    \ return (d == 0 ? mint(1) : mint(0)); }\n  return C<mint, large, dense>(n + d\
    \ - 1, d);\n}\n#line 2 \"mod/barrett.hpp\"\n\n// https://github.com/atcoder/ac-library/blob/master/atcoder/internal_math.hpp\n\
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
    mod/dynamic_modint_64.hpp\"\n\n// https://codeforces.com/contest/453/problem/D\n\
    template <int id>\nstruct Dynamic_Modint_64 {\n  static constexpr bool is_modint\
    \ = true;\n  using mint = Dynamic_Modint_64;\n  u64 val;\n  static Barrett_64\
    \ bt;\n  static u64 umod() { return bt.umod(); }\n\n  static ll get_mod() { return\
    \ (ll)(bt.umod()); }\n  static void set_mod(ll m) {\n    assert(1 <= m);\n   \
    \ bt = Barrett_64(m);\n  }\n\n  Dynamic_Modint_64() : val(0) {}\n  Dynamic_Modint_64(u64\
    \ x) : val(bt.modulo(x)) {}\n  Dynamic_Modint_64(u128 x) : val(bt.modulo(x)) {}\n\
    \  Dynamic_Modint_64(ll x) : val((x %= get_mod()) < 0 ? x + get_mod() : x) {}\n\
    \  Dynamic_Modint_64(i128 x) : val((x %= get_mod()) < 0 ? x + get_mod() : x) {}\n\
    \n  mint& operator+=(const mint& rhs) {\n    val = (val += rhs.val) < umod() ?\
    \ val : val - umod();\n    return *this;\n  }\n  mint& operator-=(const mint&\
    \ rhs) {\n    val = (val += umod() - rhs.val) < umod() ? val : val - umod();\n\
    \    return *this;\n  }\n  mint& operator*=(const mint& rhs) {\n    val = bt.mul(val,\
    \ rhs.val);\n    return *this;\n  }\n  mint& operator/=(const mint& rhs) { return\
    \ *this = *this * rhs.inverse(); }\n  mint operator-() const { return mint() -\
    \ *this; }\n  mint pow(ll n) const {\n    assert(0 <= n);\n    mint x = *this,\
    \ r = u64(1);\n    while (n) {\n      if (n & 1) r *= x;\n      x *= x, n >>=\
    \ 1;\n    }\n    return r;\n  }\n  mint inverse() const {\n    ll x = val, mod\
    \ = get_mod();\n    ll a = x, b = mod, u = 1, v = 0, t;\n    while (b > 0) {\n\
    \      t = a / b;\n      swap(a -= t * b, b), swap(u -= t * v, v);\n    }\n  \
    \  if (u < 0) u += mod;\n    return u64(u);\n  }\n\n  friend mint operator+(const\
    \ mint& lhs, const mint& rhs) {\n    return mint(lhs) += rhs;\n  }\n  friend mint\
    \ operator-(const mint& lhs, const mint& rhs) {\n    return mint(lhs) -= rhs;\n\
    \  }\n  friend mint operator*(const mint& lhs, const mint& rhs) {\n    return\
    \ mint(lhs) *= rhs;\n  }\n  friend mint operator/(const mint& lhs, const mint&\
    \ rhs) {\n    return mint(lhs) /= rhs;\n  }\n  friend bool operator==(const mint&\
    \ lhs, const mint& rhs) {\n    return lhs.val == rhs.val;\n  }\n  friend bool\
    \ operator!=(const mint& lhs, const mint& rhs) {\n    return lhs.val != rhs.val;\n\
    \  }\n#ifdef FASTIO\n  void write() { fastio::printer.write(val); }\n  void read()\
    \ {\n    fastio::scanner.read(val);\n    val = bt.modulo(val);\n  }\n#endif\n\
    };\n\nusing dmint = Dynamic_Modint_64<-1>;\ntemplate <int id>\nBarrett_64 Dynamic_Modint_64<id>::bt;\n\
    #line 3 \"nt/primetest.hpp\"\n\r\nbool primetest(const u64 x) {\r\n  if (x ==\
    \ 2 or x == 3 or x == 5 or x == 7) return true;\r\n  if (x % 2 == 0 or x % 3 ==\
    \ 0 or x % 5 == 0 or x % 7 == 0) return false;\r\n  if (x < 121) return x > 1;\r\
    \n  const u64 d = (x - 1) >> lowbit(x - 1);\r\n  using m64 = Dynamic_Modint_64<20231024>;\r\
    \n\r\n  m64::set_mod(x);\r\n  const m64 one(u64(1)), minus_one(x - 1);\r\n  auto\
    \ ok = [&](u64 a) -> bool {\r\n    auto y = m64(a).pow(d);\r\n    u64 t = d;\r\
    \n    while (y != one && y != minus_one && t != x - 1) y *= y, t <<= 1;\r\n  \
    \  if (y != minus_one && t % 2 == 0) return false;\r\n    return true;\r\n  };\r\
    \n  if (x < (1ull << 32)) {\r\n    for (u64 a: {2, 7, 61})\r\n      if (!ok(a))\
    \ return false;\r\n  } else {\r\n    for (u64 a: {2, 325, 9375, 28178, 450775,\
    \ 9780504, 1795265022}) {\r\n      if (x <= a) return true;\r\n      if (!ok(a))\
    \ return false;\r\n    }\r\n  }\r\n  return true;\r\n}\n#line 5 \"nt/factor.hpp\"\
    \n\nll rho(ll n, ll c) {\n  using m64 = Dynamic_Modint_64<20231025>;\n  m64::set_mod(n);\n\
    \  assert(n > 1);\n  const m64 cc(c);\n  auto f = [&](m64 x) { return x * x +\
    \ cc; };\n  m64 x = 1, y = 2, z = 1, q = 1;\n  ll g = 1;\n  const ll m = 1LL <<\
    \ (__lg(n) / 5); // ?\n  for (ll r = 1; g == 1; r <<= 1) {\n    x = y;\n    FOR(_,\
    \ r) y = f(y);\n    for (ll k = 0; k < r && g == 1; k += m) {\n      z = y;\n\
    \      FOR(min(m, r - k)) y = f(y), q *= x - y;\n      g = gcd(q.val(), n);\n\
    \    }\n  }\n  if (g == n) do {\n      z = f(z);\n      g = gcd((x - z).val(),\
    \ n);\n    } while (g == 1);\n  return g;\n}\n\nll find_prime_factor(ll n) {\n\
    \  assert(n > 1);\n  if (primetest(n)) return n;\n  FOR(100) {\n    ll m = rho(n,\
    \ RNG(0, n));\n    if (primetest(m)) return m;\n    n = m;\n  }\n  assert(0);\n\
    \  return -1;\n}\n\n// \u30BD\u30FC\u30C8\u3057\u3066\u304F\u308C\u308B\nvc<pair<ll,\
    \ int>> factor(ll n) {\n  assert(n >= 1);\n  vc<pair<ll, int>> pf;\n  FOR(p, 2,\
    \ 100) {\n    if (p * p > n) break;\n    if (n % p == 0) {\n      ll e = 0;\n\
    \      do { n /= p, e += 1; } while (n % p == 0);\n      pf.eb(p, e);\n    }\n\
    \  }\n  while (n > 1) {\n    ll p = find_prime_factor(n);\n    ll e = 0;\n   \
    \ do { n /= p, e += 1; } while (n % p == 0);\n    pf.eb(p, e);\n  }\n  sort(all(pf));\n\
    \  return pf;\n}\n\nvc<pair<ll, int>> factor_by_lpf(ll n, vc<int>& lpf) {\n  vc<pair<ll,\
    \ int>> res;\n  while (n > 1) {\n    int p = lpf[n];\n    int e = 0;\n    while\
    \ (n % p == 0) {\n      n /= p;\n      ++e;\n    }\n    res.eb(p, e);\n  }\n \
    \ return res;\n}\n#line 3 \"mod/mod_pow.hpp\"\n\r\nint mod_pow(int a, ll n, int\
    \ mod) {\r\n  assert(n >= 0);\r\n  a = ((a %= mod) < 0 ? a + mod : a);\r\n  Barrett\
    \ bt(mod);\r\n  int p = a, v = bt.modulo(1);\r\n  while (n) {\r\n    if (n & 1)\
    \ v = bt.mul(v, p);\r\n    p = bt.mul(p, p);\r\n    n >>= 1;\r\n  }\r\n  return\
    \ v;\r\n}\r\n\r\nll mod_pow_64(ll a, ll n, ll mod) {\r\n  assert(n >= 0);\r\n\
    \  a = ((a %= mod) < 0 ? a + mod : a);\r\n  Barrett bt(mod);\r\n  ll p = a, v\
    \ = bt.modulo(1);\r\n  while (n) {\r\n    if (n & 1) v = bt.mul(v, p);\r\n   \
    \ p = bt.mul(p, p);\r\n    n >>= 1;\r\n  }\r\n  return v;\r\n}\r\n#line 6 \"mod/primitive_root.hpp\"\
    \n\r\n// int\r\nint primitive_root(int p) {\r\n  auto pf = factor(p - 1);\r\n\
    \  auto is_ok = [&](int g) -> bool {\r\n    for (auto&& [q, e]: pf)\r\n      if\
    \ (mod_pow(g, (p - 1) / q, p) == 1) return false;\r\n    return true;\r\n  };\r\
    \n  while (1) {\r\n    int x = RNG(1, p);\r\n    if (is_ok(x)) return x;\r\n \
    \ }\r\n  return -1;\r\n}\r\n\r\nll primitive_root_64(ll p) {\r\n  auto pf = factor(p\
    \ - 1);\r\n  auto is_ok = [&](ll g) -> bool {\r\n    for (auto&& [q, e]: pf)\r\
    \n      if (mod_pow_64(g, (p - 1) / q, p) == 1) return false;\r\n    return true;\r\
    \n  };\r\n  while (1) {\r\n    ll x = RNG(1, p);\r\n    if (is_ok(x)) return x;\r\
    \n  }\r\n  return -1;\r\n}\r\n#line 2 \"mod/mod_inv.hpp\"\n\r\n// long \u3067\u3082\
    \u5927\u4E08\u592B\r\n// (val * x - 1) \u304C mod \u306E\u500D\u6570\u306B\u306A\
    \u308B\u3088\u3046\u306B\u3059\u308B\r\n// \u7279\u306B mod=0 \u306A\u3089 x=0\
    \ \u304C\u6E80\u305F\u3059\r\nll mod_inv(ll val, ll mod) {\r\n  if (mod == 0)\
    \ return 0;\r\n  mod = abs(mod);\r\n  val %= mod;\r\n  if (val < 0) val += mod;\r\
    \n  ll a = val, b = mod, u = 1, v = 0, t;\r\n  while (b > 0) {\r\n    t = a /\
    \ b;\r\n    swap(a -= t * b, b), swap(u -= t * v, v);\r\n  }\r\n  if (u < 0) u\
    \ += mod;\r\n  return u;\r\n}\r\n#line 3 \"mod/binomial.hpp\"\n\r\nstruct Binomial_PrimePower\
    \ {\r\n  int p, e;\r\n  int pp;\r\n  int root;\r\n  int ord;\r\n  vc<int> exp;\r\
    \n  vc<int> log_fact;\r\n  vc<int> power;\r\n  Barrett bt_p, bt_pp;\r\n\r\n  Binomial_PrimePower(int\
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
  - random/base.hpp
  - nt/primetest.hpp
  - mod/dynamic_modint_64.hpp
  - mod/modint_common.hpp
  - mod/barrett.hpp
  - mod/mod_pow.hpp
  - mod/mod_inv.hpp
  isVerificationFile: false
  path: mod/binomial.hpp
  requiredBy: []
  timestamp: '2023-10-24 21:40:49+09:00'
  verificationStatus: LIBRARY_ALL_WA
  verifiedWith:
  - test/yukicoder/2181.test.cpp
  - test/yukicoder/2120.test.cpp
  - test/library_checker/math/binomial_coefficient.test.cpp
documentation_of: mod/binomial.hpp
layout: document
redirect_from:
- /library/mod/binomial.hpp
- /library/mod/binomial.hpp.html
title: mod/binomial.hpp
---
