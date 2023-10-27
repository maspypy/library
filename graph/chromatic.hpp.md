---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: mod/barrett.hpp
    title: mod/barrett.hpp
  - icon: ':heavy_check_mark:'
    path: mod/dynamic_modint_64.hpp
    title: mod/dynamic_modint_64.hpp
  - icon: ':heavy_check_mark:'
    path: mod/modint_common.hpp
    title: mod/modint_common.hpp
  - icon: ':heavy_check_mark:'
    path: nt/primetest.hpp
    title: nt/primetest.hpp
  - icon: ':question:'
    path: random/base.hpp
    title: random/base.hpp
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/library_checker/graph/chromatic_number.test.cpp
    title: test/library_checker/graph/chromatic_number.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 2 \"random/base.hpp\"\n\nu64 RNG_64() {\n  static uint64_t x_\n\
    \      = uint64_t(chrono::duration_cast<chrono::nanoseconds>(\n              \
    \       chrono::high_resolution_clock::now().time_since_epoch())\n           \
    \          .count())\n        * 10150724397891781847ULL;\n  x_ ^= x_ << 7;\n \
    \ return x_ ^= x_ >> 9;\n}\n\nu64 RNG(u64 lim) { return RNG_64() % lim; }\n\n\
    ll RNG(ll l, ll r) { return l + RNG_64() % (r - l); }\n#line 2 \"mod/dynamic_modint_64.hpp\"\
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
    \ return false;\r\n    }\r\n  }\r\n  return true;\r\n}\n#line 3 \"graph/chromatic.hpp\"\
    \n\r\n// O(N2^N)\r\ntemplate <typename Graph, int TRIAL = 0>\r\nint chromatic_number(Graph&\
    \ G) {\r\n  assert(G.is_prepared());\r\n\r\n  int N = G.N;\r\n  vc<int> nbd(N);\r\
    \n  FOR(v, N) for (auto&& e: G[v]) nbd[v] |= 1 << e.to;\r\n\r\n  // s \u306E subset\
    \ \u3067\u3042\u308B\u3088\u3046\u306A\u72EC\u7ACB\u96C6\u5408\u306E\u6570\u3048\
    \u4E0A\u3052\r\n  vc<int> dp(1 << N);\r\n  dp[0] = 1;\r\n  FOR(v, N) FOR(s, 1\
    \ << v) { dp[s | 1 << v] = dp[s] + dp[s & (~nbd[v])]; }\r\n\r\n  vi pow(1 << N);\r\
    \n  auto solve_p = [&](int p) -> int {\r\n    FOR(s, 1 << N) pow[s] = ((N - popcnt(s))\
    \ & 1 ? 1 : -1);\r\n    FOR(k, 1, N) {\r\n      ll sum = 0;\r\n      FOR(s, 1\
    \ << N) {\r\n        pow[s] = pow[s] * dp[s];\r\n        if (p) pow[s] %= p;\r\
    \n        sum += pow[s];\r\n      }\r\n      if (p) sum %= p;\r\n      if (sum\
    \ != 0) { return k; }\r\n    }\r\n    return N;\r\n  };\r\n\r\n  int ANS = 0;\r\
    \n  chmax(ANS, solve_p(0));\r\n\r\n  FOR(TRIAL) {\r\n    int p;\r\n    while (1)\
    \ {\r\n      p = RNG(1LL << 30, 1LL << 31);\r\n      if (primetest(p)) break;\r\
    \n    }\r\n    chmax(ANS, solve_p(p));\r\n  }\r\n  return ANS;\r\n}\r\n"
  code: "#include \"random/base.hpp\"\r\n#include \"nt/primetest.hpp\"\r\n\r\n// O(N2^N)\r\
    \ntemplate <typename Graph, int TRIAL = 0>\r\nint chromatic_number(Graph& G) {\r\
    \n  assert(G.is_prepared());\r\n\r\n  int N = G.N;\r\n  vc<int> nbd(N);\r\n  FOR(v,\
    \ N) for (auto&& e: G[v]) nbd[v] |= 1 << e.to;\r\n\r\n  // s \u306E subset \u3067\
    \u3042\u308B\u3088\u3046\u306A\u72EC\u7ACB\u96C6\u5408\u306E\u6570\u3048\u4E0A\
    \u3052\r\n  vc<int> dp(1 << N);\r\n  dp[0] = 1;\r\n  FOR(v, N) FOR(s, 1 << v)\
    \ { dp[s | 1 << v] = dp[s] + dp[s & (~nbd[v])]; }\r\n\r\n  vi pow(1 << N);\r\n\
    \  auto solve_p = [&](int p) -> int {\r\n    FOR(s, 1 << N) pow[s] = ((N - popcnt(s))\
    \ & 1 ? 1 : -1);\r\n    FOR(k, 1, N) {\r\n      ll sum = 0;\r\n      FOR(s, 1\
    \ << N) {\r\n        pow[s] = pow[s] * dp[s];\r\n        if (p) pow[s] %= p;\r\
    \n        sum += pow[s];\r\n      }\r\n      if (p) sum %= p;\r\n      if (sum\
    \ != 0) { return k; }\r\n    }\r\n    return N;\r\n  };\r\n\r\n  int ANS = 0;\r\
    \n  chmax(ANS, solve_p(0));\r\n\r\n  FOR(TRIAL) {\r\n    int p;\r\n    while (1)\
    \ {\r\n      p = RNG(1LL << 30, 1LL << 31);\r\n      if (primetest(p)) break;\r\
    \n    }\r\n    chmax(ANS, solve_p(p));\r\n  }\r\n  return ANS;\r\n}\r\n"
  dependsOn:
  - random/base.hpp
  - nt/primetest.hpp
  - mod/dynamic_modint_64.hpp
  - mod/modint_common.hpp
  - mod/barrett.hpp
  isVerificationFile: false
  path: graph/chromatic.hpp
  requiredBy: []
  timestamp: '2023-10-24 22:55:22+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/library_checker/graph/chromatic_number.test.cpp
documentation_of: graph/chromatic.hpp
layout: document
redirect_from:
- /library/graph/chromatic.hpp
- /library/graph/chromatic.hpp.html
title: graph/chromatic.hpp
---
