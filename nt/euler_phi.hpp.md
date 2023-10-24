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
    path: mod/modint_common.hpp
    title: mod/modint_common.hpp
  - icon: ':question:'
    path: nt/factor.hpp
    title: nt/factor.hpp
  - icon: ':question:'
    path: nt/primetable.hpp
    title: nt/primetable.hpp
  - icon: ':question:'
    path: nt/primetest.hpp
    title: nt/primetest.hpp
  - icon: ':heavy_check_mark:'
    path: nt/zeta.hpp
    title: nt/zeta.hpp
  - icon: ':question:'
    path: random/base.hpp
    title: random/base.hpp
  _extendedRequiredBy:
  - icon: ':heavy_check_mark:'
    path: mod/tetration.hpp
    title: mod/tetration.hpp
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/aoj/NTL_1_D.test.cpp
    title: test/aoj/NTL_1_D.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/library_checker/math/tetration.test.cpp
    title: test/library_checker/math/tetration.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/yukicoder/1262.test.cpp
    title: test/yukicoder/1262.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 2 \"nt/primetable.hpp\"\n\ntemplate <typename T = int>\nvc<T>\
    \ primetable(int LIM) {\n  ++LIM;\n  const int S = 32768;\n  static int done =\
    \ 2;\n  static vc<T> primes = {2}, sieve(S + 1);\n\n  if (done < LIM) {\n    done\
    \ = LIM;\n\n    primes = {2}, sieve.assign(S + 1, 0);\n    const int R = LIM /\
    \ 2;\n    primes.reserve(int(LIM / log(LIM) * 1.1));\n    vc<pair<int, int>> cp;\n\
    \    for (int i = 3; i <= S; i += 2) {\n      if (!sieve[i]) {\n        cp.eb(i,\
    \ i * i / 2);\n        for (int j = i * i; j <= S; j += 2 * i) sieve[j] = 1;\n\
    \      }\n    }\n    for (int L = 1; L <= R; L += S) {\n      array<bool, S> block{};\n\
    \      for (auto& [p, idx]: cp)\n        for (int i = idx; i < S + L; idx = (i\
    \ += p)) block[i - L] = 1;\n      FOR(i, min(S, R - L)) if (!block[i]) primes.eb((L\
    \ + i) * 2 + 1);\n    }\n  }\n  int k = LB(primes, LIM + 1);\n  return {primes.begin(),\
    \ primes.begin() + k};\n}\n#line 3 \"nt/zeta.hpp\"\n\r\ntemplate <typename T>\r\
    \nvoid divisor_zeta(vc<T>& A) {\r\n  assert(A[0] == 0);\r\n  int N = len(A) -\
    \ 1;\r\n  auto P = primetable(N);\r\n  for (auto&& p: P) { FOR3(x, 1, N / p +\
    \ 1) A[p * x] += A[x]; }\r\n}\r\n\r\ntemplate <typename T>\r\nvoid divisor_mobius(vc<T>&\
    \ A) {\r\n  assert(A[0] == 0);\r\n  int N = len(A) - 1;\r\n  auto P = primetable(N);\r\
    \n  for (auto&& p: P) { FOR3_R(x, 1, N / p + 1) A[p * x] -= A[x]; }\r\n}\r\n\r\
    \ntemplate <typename T>\r\nvoid multiplier_zeta(vc<T>& A) {\r\n  assert(A[0] ==\
    \ 0);\r\n  int N = len(A) - 1;\r\n  auto P = primetable(N);\r\n  for (auto&& p:\
    \ P) { FOR3_R(x, 1, N / p + 1) A[x] += A[p * x]; }\r\n}\r\n\r\ntemplate <typename\
    \ T>\r\nvoid multiplier_mobius(vc<T>& A) {\r\n  assert(A[0] == 0);\r\n  int N\
    \ = len(A) - 1;\r\n  auto P = primetable(N);\r\n  for (auto&& p: P) { FOR3(x,\
    \ 1, N / p + 1) A[x] -= A[p * x]; }\r\n}\r\n#line 2 \"nt/factor.hpp\"\n\n#line\
    \ 2 \"random/base.hpp\"\n\nu64 RNG_64() {\n  static uint64_t x_\n      = uint64_t(chrono::duration_cast<chrono::nanoseconds>(\n\
    \                     chrono::high_resolution_clock::now().time_since_epoch())\n\
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
    \  Dynamic_Modint_64(int x) : val((x %= get_mod()) < 0 ? x + get_mod() : x) {}\n\
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
    };\n\nusing dmint64 = Dynamic_Modint_64<-1>;\ntemplate <int id>\nBarrett_64 Dynamic_Modint_64<id>::bt;\n\
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
    \      FOR(min(m, r - k)) y = f(y), q *= x - y;\n      g = gcd(q.val, n);\n  \
    \  }\n  }\n  if (g == n) do {\n      z = f(z);\n      g = gcd((x - z).val, n);\n\
    \    } while (g == 1);\n  return g;\n}\n\nll find_prime_factor(ll n) {\n  assert(n\
    \ > 1);\n  if (primetest(n)) return n;\n  FOR(100) {\n    ll m = rho(n, RNG(0,\
    \ n));\n    if (primetest(m)) return m;\n    n = m;\n  }\n  assert(0);\n  return\
    \ -1;\n}\n\n// \u30BD\u30FC\u30C8\u3057\u3066\u304F\u308C\u308B\nvc<pair<ll, int>>\
    \ factor(ll n) {\n  assert(n >= 1);\n  vc<pair<ll, int>> pf;\n  FOR(p, 2, 100)\
    \ {\n    if (p * p > n) break;\n    if (n % p == 0) {\n      ll e = 0;\n     \
    \ do { n /= p, e += 1; } while (n % p == 0);\n      pf.eb(p, e);\n    }\n  }\n\
    \  while (n > 1) {\n    ll p = find_prime_factor(n);\n    ll e = 0;\n    do {\
    \ n /= p, e += 1; } while (n % p == 0);\n    pf.eb(p, e);\n  }\n  sort(all(pf));\n\
    \  return pf;\n}\n\nvc<pair<ll, int>> factor_by_lpf(ll n, vc<int>& lpf) {\n  vc<pair<ll,\
    \ int>> res;\n  while (n > 1) {\n    int p = lpf[n];\n    int e = 0;\n    while\
    \ (n % p == 0) {\n      n /= p;\n      ++e;\n    }\n    res.eb(p, e);\n  }\n \
    \ return res;\n}\n#line 3 \"nt/euler_phi.hpp\"\n\r\nll euler_phi(ll n) {\r\n \
    \ auto pf = factor(n);\r\n  for (auto&& [p, e]: pf) n -= n / p;\r\n  return n;\r\
    \n}\r\n\r\ntemplate <typename T>\r\nvc<T> euler_phi_table(ll n) {\r\n  vc<T> A(n\
    \ + 1);\r\n  FOR(i, 1, n + 1) A[i] = T(i);\r\n  divisor_mobius(A);\r\n  return\
    \ A;\r\n}\r\n"
  code: "#include \"nt/zeta.hpp\"\r\n#include \"nt/factor.hpp\"\r\n\r\nll euler_phi(ll\
    \ n) {\r\n  auto pf = factor(n);\r\n  for (auto&& [p, e]: pf) n -= n / p;\r\n\
    \  return n;\r\n}\r\n\r\ntemplate <typename T>\r\nvc<T> euler_phi_table(ll n)\
    \ {\r\n  vc<T> A(n + 1);\r\n  FOR(i, 1, n + 1) A[i] = T(i);\r\n  divisor_mobius(A);\r\
    \n  return A;\r\n}\r\n"
  dependsOn:
  - nt/zeta.hpp
  - nt/primetable.hpp
  - nt/factor.hpp
  - random/base.hpp
  - nt/primetest.hpp
  - mod/dynamic_modint_64.hpp
  - mod/modint_common.hpp
  - mod/barrett.hpp
  isVerificationFile: false
  path: nt/euler_phi.hpp
  requiredBy:
  - mod/tetration.hpp
  timestamp: '2023-10-24 22:55:22+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/yukicoder/1262.test.cpp
  - test/aoj/NTL_1_D.test.cpp
  - test/library_checker/math/tetration.test.cpp
documentation_of: nt/euler_phi.hpp
layout: document
redirect_from:
- /library/nt/euler_phi.hpp
- /library/nt/euler_phi.hpp.html
title: nt/euler_phi.hpp
---
