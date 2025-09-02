---
data:
  _extendedDependsOn:
  - icon: ':question:'
    path: mod/barrett.hpp
    title: mod/barrett.hpp
  - icon: ':question:'
    path: mod/mod_pow.hpp
    title: mod/mod_pow.hpp
  - icon: ':question:'
    path: mod/modint_common.hpp
    title: mod/modint_common.hpp
  - icon: ':question:'
    path: mod/mongomery_modint.hpp
    title: mod/mongomery_modint.hpp
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
  _extendedRequiredBy:
  - icon: ':x:'
    path: mod/mod_log.hpp
    title: mod/mod_log.hpp
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/1_mytest/31bit_modint.test.cpp
    title: test/1_mytest/31bit_modint.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/1_mytest/O1_inv.test.cpp
    title: test/1_mytest/O1_inv.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/1_mytest/geometric_sequence_sum.test.cpp
    title: test/1_mytest/geometric_sequence_sum.test.cpp
  - icon: ':x:'
    path: test/2_library_checker/convolution/convolution_mod_107_dmint.test.cpp
    title: test/2_library_checker/convolution/convolution_mod_107_dmint.test.cpp
  - icon: ':x:'
    path: test/2_library_checker/convolution/convolution_mod_dmint.test.cpp
    title: test/2_library_checker/convolution/convolution_mod_dmint.test.cpp
  - icon: ':x:'
    path: test/2_library_checker/convolution/convolution_mod_setntt.test.cpp
    title: test/2_library_checker/convolution/convolution_mod_setntt.test.cpp
  - icon: ':x:'
    path: test/2_library_checker/convolution/multivariate_convolution_cyclic.test.cpp
    title: test/2_library_checker/convolution/multivariate_convolution_cyclic.test.cpp
  - icon: ':x:'
    path: test/2_library_checker/number_theory/discrete_logarithm_mod.test.cpp
    title: test/2_library_checker/number_theory/discrete_logarithm_mod.test.cpp
  - icon: ':x:'
    path: test/2_library_checker/polynomial/composition_dmint.test.cpp
    title: test/2_library_checker/polynomial/composition_dmint.test.cpp
  - icon: ':x:'
    path: test/2_library_checker/polynomial/compositional_inverse_dmint.test.cpp
    title: test/2_library_checker/polynomial/compositional_inverse_dmint.test.cpp
  - icon: ':x:'
    path: test/2_library_checker/polynomial/exp_of_fps_dmint.test.cpp
    title: test/2_library_checker/polynomial/exp_of_fps_dmint.test.cpp
  - icon: ':x:'
    path: test/2_library_checker/polynomial/exp_of_fps_sparse_dmint.test.cpp
    title: test/2_library_checker/polynomial/exp_of_fps_sparse_dmint.test.cpp
  - icon: ':x:'
    path: test/2_library_checker/polynomial/inv_of_fps.test.cpp
    title: test/2_library_checker/polynomial/inv_of_fps.test.cpp
  - icon: ':x:'
    path: test/2_library_checker/polynomial/inv_of_fps_dmint.test.cpp
    title: test/2_library_checker/polynomial/inv_of_fps_dmint.test.cpp
  - icon: ':x:'
    path: test/2_library_checker/polynomial/inv_of_fps_sparse_dmint.test.cpp
    title: test/2_library_checker/polynomial/inv_of_fps_sparse_dmint.test.cpp
  - icon: ':x:'
    path: test/2_library_checker/polynomial/log_of_fps_dmint.test.cpp
    title: test/2_library_checker/polynomial/log_of_fps_dmint.test.cpp
  - icon: ':x:'
    path: test/2_library_checker/polynomial/log_of_fps_sparse_dmint.test.cpp
    title: test/2_library_checker/polynomial/log_of_fps_sparse_dmint.test.cpp
  - icon: ':x:'
    path: test/2_library_checker/polynomial/pow_of_fps_dmint.test.cpp
    title: test/2_library_checker/polynomial/pow_of_fps_dmint.test.cpp
  - icon: ':x:'
    path: test/2_library_checker/polynomial/pow_of_fps_sparse_dmint.test.cpp
    title: test/2_library_checker/polynomial/pow_of_fps_sparse_dmint.test.cpp
  - icon: ':x:'
    path: test/3_yukicoder/1339.test.cpp
    title: test/3_yukicoder/1339.test.cpp
  - icon: ':x:'
    path: test/3_yukicoder/1667.test.cpp
    title: test/3_yukicoder/1667.test.cpp
  _isVerificationFailed: true
  _pathExtension: hpp
  _verificationStatusIcon: ':question:'
  attributes:
    links: []
  bundledCode: "#line 2 \"mod/dynamic_modint.hpp\"\n\n#line 2 \"mod/modint_common.hpp\"\
    \n\nstruct has_mod_impl {\n  template <class T>\n  static auto check(T &&x) ->\
    \ decltype(x.get_mod(), std::true_type{});\n  template <class T>\n  static auto\
    \ check(...) -> std::false_type;\n};\n\ntemplate <class T>\nclass has_mod : public\
    \ decltype(has_mod_impl::check<T>(std::declval<T>())) {};\n\ntemplate <typename\
    \ mint>\nmint inv(int n) {\n  static const int mod = mint::get_mod();\n  static\
    \ vector<mint> dat = {0, 1};\n  assert(0 <= n);\n  if (n >= mod) n %= mod;\n \
    \ while (len(dat) <= n) {\n    int k = len(dat);\n    int q = (mod + k - 1) /\
    \ k;\n    dat.eb(dat[k * q - mod] * mint::raw(q));\n  }\n  return dat[n];\n}\n\
    \ntemplate <>\ndouble inv<double>(int n) {\n  assert(n != 0);\n  return 1.0 /\
    \ n;\n}\n\ntemplate <typename mint>\nmint fact(int n) {\n  static const int mod\
    \ = mint::get_mod();\n  assert(0 <= n && n < mod);\n  static vector<mint> dat\
    \ = {1, 1};\n  while (len(dat) <= n) dat.eb(dat[len(dat) - 1] * mint(len(dat)));\n\
    \  return dat[n];\n}\n\ntemplate <typename mint>\nmint fact_inv(int n) {\n  static\
    \ vector<mint> dat = {1, 1};\n  if (n < 0) return mint(0);\n  while (len(dat)\
    \ <= n) dat.eb(dat[len(dat) - 1] * inv<mint>(len(dat)));\n  return dat[n];\n}\n\
    \ntemplate <class mint, class... Ts>\nmint fact_invs(Ts... xs) {\n  return (mint(1)\
    \ * ... * fact_inv<mint>(xs));\n}\n\ntemplate <typename mint, class Head, class...\
    \ Tail>\nmint multinomial(Head &&head, Tail &&...tail) {\n  return fact<mint>(head)\
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
    \ >= 0);\n  if (d < 0) return mint(0);\n  if (n == 0) {\n    return (d == 0 ?\
    \ mint(1) : mint(0));\n  }\n  return C<mint, large, dense>(n + d - 1, d);\n}\n\
    #line 2 \"mod/primitive_root.hpp\"\n\r\n#line 2 \"nt/factor.hpp\"\n\n#line 2 \"\
    random/base.hpp\"\n\nu64 RNG_64() {\n  static u64 x_ = u64(chrono::duration_cast<chrono::nanoseconds>(chrono::high_resolution_clock::now().time_since_epoch()).count())\
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
    \ g += q / p;\r\n  }\r\n  return g;\r\n}\r\n#line 6 \"mod/dynamic_modint.hpp\"\
    \n\ntemplate <int id>\nstruct Dynamic_Modint {\n  static constexpr bool is_modint\
    \ = true;\n  using mint = Dynamic_Modint;\n  u32 val;\n  static Barrett bt;\n\
    \  static u32 umod() { return bt.umod(); }\n\n  static int get_mod() { return\
    \ (int)(bt.umod()); }\n  static void set_mod(int m) {\n    assert(1 <= m);\n \
    \   bt = Barrett(m);\n  }\n\n  static Dynamic_Modint raw(u32 v) {\n    Dynamic_Modint\
    \ x;\n    x.val = v;\n    return x;\n  }\n  Dynamic_Modint() : val(0) {}\n  Dynamic_Modint(u32\
    \ x) : val(bt.modulo(x)) {}\n  Dynamic_Modint(u64 x) : val(bt.modulo(x)) {}\n\
    \  Dynamic_Modint(int x) : val((x %= get_mod()) < 0 ? x + get_mod() : x) {}\n\
    \  Dynamic_Modint(ll x) : val((x %= get_mod()) < 0 ? x + get_mod() : x) {}\n \
    \ Dynamic_Modint(i128 x) : val((x %= get_mod()) < 0 ? x + get_mod() : x){};\n\n\
    \  mint& operator+=(const mint& rhs) {\n    val = (val += rhs.val) < umod() ?\
    \ val : val - umod();\n    return *this;\n  }\n  mint& operator-=(const mint&\
    \ rhs) {\n    val = (val += umod() - rhs.val) < umod() ? val : val - umod();\n\
    \    return *this;\n  }\n  mint& operator*=(const mint& rhs) {\n    val = bt.mul(val,\
    \ rhs.val);\n    return *this;\n  }\n  mint& operator/=(const mint& rhs) { return\
    \ *this = *this * rhs.inverse(); }\n  mint operator-() const { return mint() -\
    \ *this; }\n  mint pow(ll n) const {\n    assert(0 <= n);\n    mint x = *this,\
    \ r = 1;\n    while (n) {\n      if (n & 1) r *= x;\n      x *= x, n >>= 1;\n\
    \    }\n    return r;\n  }\n  mint inverse() const {\n    int x = val, mod = get_mod();\n\
    \    int a = x, b = mod, u = 1, v = 0, t;\n    while (b > 0) {\n      t = a /\
    \ b;\n      swap(a -= t * b, b), swap(u -= t * v, v);\n    }\n    if (u < 0) u\
    \ += mod;\n    return u;\n  }\n\n  friend mint operator+(const mint& lhs, const\
    \ mint& rhs) { return mint(lhs) += rhs; }\n  friend mint operator-(const mint&\
    \ lhs, const mint& rhs) { return mint(lhs) -= rhs; }\n  friend mint operator*(const\
    \ mint& lhs, const mint& rhs) { return mint(lhs) *= rhs; }\n  friend mint operator/(const\
    \ mint& lhs, const mint& rhs) { return mint(lhs) /= rhs; }\n  friend bool operator==(const\
    \ mint& lhs, const mint& rhs) { return lhs.val == rhs.val; }\n  friend bool operator!=(const\
    \ mint& lhs, const mint& rhs) { return lhs.val != rhs.val; }\n  static pair<int,\
    \ int>& get_ntt() {\n    static pair<int, int> p = {-1, -1};\n    return p;\n\
    \  }\n  static void set_ntt_info() {\n    int mod = get_mod();\n    int k = lowbit(mod\
    \ - 1);\n    int r = primitive_root(mod);\n    r = mod_pow(r, (mod - 1) >> k,\
    \ mod);\n    get_ntt() = {k, r};\n  }\n  static pair<int, int> ntt_info() { return\
    \ get_ntt(); }\n  static bool can_ntt() { return ntt_info().fi != -1; }\n};\n\n\
    #ifdef FASTIO\ntemplate <int id>\nvoid rd(Dynamic_Modint<id>& x) {\n  fastio::rd(x.val);\n\
    \  x.val %= Dynamic_Modint<id>::umod();\n}\ntemplate <int id>\nvoid wt(Dynamic_Modint<id>\
    \ x) {\n  fastio::wt(x.val);\n}\n#endif\n\nusing dmint = Dynamic_Modint<-1>;\n\
    template <int id>\nBarrett Dynamic_Modint<id>::bt;\n"
  code: "#pragma once\n\n#include \"mod/modint_common.hpp\"\n#include \"mod/primitive_root.hpp\"\
    \n#include \"mod/barrett.hpp\"\n\ntemplate <int id>\nstruct Dynamic_Modint {\n\
    \  static constexpr bool is_modint = true;\n  using mint = Dynamic_Modint;\n \
    \ u32 val;\n  static Barrett bt;\n  static u32 umod() { return bt.umod(); }\n\n\
    \  static int get_mod() { return (int)(bt.umod()); }\n  static void set_mod(int\
    \ m) {\n    assert(1 <= m);\n    bt = Barrett(m);\n  }\n\n  static Dynamic_Modint\
    \ raw(u32 v) {\n    Dynamic_Modint x;\n    x.val = v;\n    return x;\n  }\n  Dynamic_Modint()\
    \ : val(0) {}\n  Dynamic_Modint(u32 x) : val(bt.modulo(x)) {}\n  Dynamic_Modint(u64\
    \ x) : val(bt.modulo(x)) {}\n  Dynamic_Modint(int x) : val((x %= get_mod()) <\
    \ 0 ? x + get_mod() : x) {}\n  Dynamic_Modint(ll x) : val((x %= get_mod()) < 0\
    \ ? x + get_mod() : x) {}\n  Dynamic_Modint(i128 x) : val((x %= get_mod()) < 0\
    \ ? x + get_mod() : x){};\n\n  mint& operator+=(const mint& rhs) {\n    val =\
    \ (val += rhs.val) < umod() ? val : val - umod();\n    return *this;\n  }\n  mint&\
    \ operator-=(const mint& rhs) {\n    val = (val += umod() - rhs.val) < umod()\
    \ ? val : val - umod();\n    return *this;\n  }\n  mint& operator*=(const mint&\
    \ rhs) {\n    val = bt.mul(val, rhs.val);\n    return *this;\n  }\n  mint& operator/=(const\
    \ mint& rhs) { return *this = *this * rhs.inverse(); }\n  mint operator-() const\
    \ { return mint() - *this; }\n  mint pow(ll n) const {\n    assert(0 <= n);\n\
    \    mint x = *this, r = 1;\n    while (n) {\n      if (n & 1) r *= x;\n     \
    \ x *= x, n >>= 1;\n    }\n    return r;\n  }\n  mint inverse() const {\n    int\
    \ x = val, mod = get_mod();\n    int a = x, b = mod, u = 1, v = 0, t;\n    while\
    \ (b > 0) {\n      t = a / b;\n      swap(a -= t * b, b), swap(u -= t * v, v);\n\
    \    }\n    if (u < 0) u += mod;\n    return u;\n  }\n\n  friend mint operator+(const\
    \ mint& lhs, const mint& rhs) { return mint(lhs) += rhs; }\n  friend mint operator-(const\
    \ mint& lhs, const mint& rhs) { return mint(lhs) -= rhs; }\n  friend mint operator*(const\
    \ mint& lhs, const mint& rhs) { return mint(lhs) *= rhs; }\n  friend mint operator/(const\
    \ mint& lhs, const mint& rhs) { return mint(lhs) /= rhs; }\n  friend bool operator==(const\
    \ mint& lhs, const mint& rhs) { return lhs.val == rhs.val; }\n  friend bool operator!=(const\
    \ mint& lhs, const mint& rhs) { return lhs.val != rhs.val; }\n  static pair<int,\
    \ int>& get_ntt() {\n    static pair<int, int> p = {-1, -1};\n    return p;\n\
    \  }\n  static void set_ntt_info() {\n    int mod = get_mod();\n    int k = lowbit(mod\
    \ - 1);\n    int r = primitive_root(mod);\n    r = mod_pow(r, (mod - 1) >> k,\
    \ mod);\n    get_ntt() = {k, r};\n  }\n  static pair<int, int> ntt_info() { return\
    \ get_ntt(); }\n  static bool can_ntt() { return ntt_info().fi != -1; }\n};\n\n\
    #ifdef FASTIO\ntemplate <int id>\nvoid rd(Dynamic_Modint<id>& x) {\n  fastio::rd(x.val);\n\
    \  x.val %= Dynamic_Modint<id>::umod();\n}\ntemplate <int id>\nvoid wt(Dynamic_Modint<id>\
    \ x) {\n  fastio::wt(x.val);\n}\n#endif\n\nusing dmint = Dynamic_Modint<-1>;\n\
    template <int id>\nBarrett Dynamic_Modint<id>::bt;\n"
  dependsOn:
  - mod/modint_common.hpp
  - mod/primitive_root.hpp
  - nt/factor.hpp
  - random/base.hpp
  - nt/primetest.hpp
  - mod/mongomery_modint.hpp
  - mod/mod_pow.hpp
  - mod/barrett.hpp
  isVerificationFile: false
  path: mod/dynamic_modint.hpp
  requiredBy:
  - mod/mod_log.hpp
  timestamp: '2025-07-05 14:54:01+09:00'
  verificationStatus: LIBRARY_SOME_WA
  verifiedWith:
  - test/3_yukicoder/1339.test.cpp
  - test/3_yukicoder/1667.test.cpp
  - test/2_library_checker/convolution/convolution_mod_107_dmint.test.cpp
  - test/2_library_checker/convolution/convolution_mod_dmint.test.cpp
  - test/2_library_checker/convolution/multivariate_convolution_cyclic.test.cpp
  - test/2_library_checker/convolution/convolution_mod_setntt.test.cpp
  - test/2_library_checker/number_theory/discrete_logarithm_mod.test.cpp
  - test/2_library_checker/polynomial/inv_of_fps_dmint.test.cpp
  - test/2_library_checker/polynomial/inv_of_fps_sparse_dmint.test.cpp
  - test/2_library_checker/polynomial/log_of_fps_dmint.test.cpp
  - test/2_library_checker/polynomial/composition_dmint.test.cpp
  - test/2_library_checker/polynomial/compositional_inverse_dmint.test.cpp
  - test/2_library_checker/polynomial/exp_of_fps_dmint.test.cpp
  - test/2_library_checker/polynomial/exp_of_fps_sparse_dmint.test.cpp
  - test/2_library_checker/polynomial/inv_of_fps.test.cpp
  - test/2_library_checker/polynomial/pow_of_fps_sparse_dmint.test.cpp
  - test/2_library_checker/polynomial/log_of_fps_sparse_dmint.test.cpp
  - test/2_library_checker/polynomial/pow_of_fps_dmint.test.cpp
  - test/1_mytest/31bit_modint.test.cpp
  - test/1_mytest/O1_inv.test.cpp
  - test/1_mytest/geometric_sequence_sum.test.cpp
documentation_of: mod/dynamic_modint.hpp
layout: document
redirect_from:
- /library/mod/dynamic_modint.hpp
- /library/mod/dynamic_modint.hpp.html
title: mod/dynamic_modint.hpp
---
