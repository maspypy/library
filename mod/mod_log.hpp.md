---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: alg/acted_set/from_monoid.hpp
    title: alg/acted_set/from_monoid.hpp
  - icon: ':heavy_check_mark:'
    path: alg/monoid/mul.hpp
    title: alg/monoid/mul.hpp
  - icon: ':heavy_check_mark:'
    path: ds/hashmap.hpp
    title: ds/hashmap.hpp
  - icon: ':heavy_check_mark:'
    path: mod/factorial.hpp
    title: mod/factorial.hpp
  - icon: ':heavy_check_mark:'
    path: mod/modint.hpp
    title: mod/modint.hpp
  - icon: ':heavy_check_mark:'
    path: nt/discrete_log.hpp
    title: nt/discrete_log.hpp
  - icon: ':heavy_check_mark:'
    path: random/base.hpp
    title: random/base.hpp
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/library_checker/math/discrete_logarithm_mod.test.cpp
    title: test/library_checker/math/discrete_logarithm_mod.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 1 \"mod/factorial.hpp\"\n\ntemplate <typename mint>\nmint inv(int\
    \ n) {\n  static const int mod = mint::get_mod();\n  static vector<mint> dat =\
    \ {0, 1};\n  assert(0 <= n);\n  if (n >= mod) n %= mod;\n  while (len(dat) <=\
    \ n) {\n    int k = len(dat);\n    int q = (mod + k - 1) / k;\n    dat.eb(dat[k\
    \ * q - mod] * mint(q));\n  }\n  return dat[n];\n}\n\ntemplate <typename mint>\n\
    mint fact(int n) {\n  static const int mod = mint::get_mod();\n  assert(0 <= n);\n\
    \  if (n >= mod) return 0;\n  static vector<mint> dat = {1, 1};\n  while (len(dat)\
    \ <= n) dat.eb(dat[len(dat) - 1] * mint(len(dat)));\n  return dat[n];\n}\n\ntemplate\
    \ <typename mint>\nmint fact_inv(int n) {\n  static const int mod = mint::get_mod();\n\
    \  assert(-1 <= n && n < mod);\n  static vector<mint> dat = {1, 1};\n  if (n ==\
    \ -1) return mint(0);\n  while (len(dat) <= n) dat.eb(dat[len(dat) - 1] * inv<mint>(len(dat)));\n\
    \  return dat[n];\n}\n\ntemplate <class mint, class... Ts>\nmint fact_invs(Ts...\
    \ xs) {\n  return (mint(1) * ... * fact_inv<mint>(xs));\n}\n\ntemplate <typename\
    \ mint, class Head, class... Tail>\nmint multinomial(Head &&head, Tail &&... tail)\
    \ {\n  return fact<mint>(head) * fact_invs<mint>(std::forward<Tail>(tail)...);\n\
    }\n\ntemplate <typename mint>\nmint C_dense(int n, int k) {\n  static vvc<mint>\
    \ C;\n  static int H = 0, W = 0;\n  auto calc = [&](int i, int j) -> mint {\n\
    \    if (i == 0) return (j == 0 ? mint(1) : mint(0));\n    return C[i - 1][j]\
    \ + (j ? C[i - 1][j - 1] : 0);\n  };\n  if (W <= k) {\n    FOR(i, H) {\n     \
    \ C[i].resize(k + 1);\n      FOR(j, W, k + 1) { C[i][j] = calc(i, j); }\n    }\n\
    \    W = k + 1;\n  }\n  if (H <= n) {\n    C.resize(n + 1);\n    FOR(i, H, n +\
    \ 1) {\n      C[i].resize(W);\n      FOR(j, W) { C[i][j] = calc(i, j); }\n   \
    \ }\n    H = n + 1;\n  }\n  return C[n][k];\n}\n\ntemplate <typename mint, bool\
    \ large = false, bool dense = false>\nmint C(ll n, ll k) {\n  assert(n >= 0);\n\
    \  if (k < 0 || n < k) return 0;\n  if (dense) return C_dense<mint>(n, k);\n \
    \ if (!large) return multinomial<mint>(n, k, n - k);\n  k = min(k, n - k);\n \
    \ mint x(1);\n  FOR(i, k) x *= mint(n - i);\n  return x * fact_inv<mint>(k);\n\
    }\n\ntemplate <typename mint, bool large = false>\nmint C_inv(ll n, ll k) {\n\
    \  assert(n >= 0);\n  assert(0 <= k && k <= n);\n  if (!large) return fact_inv<mint>(n)\
    \ * fact<mint>(k) * fact<mint>(n - k);\n  return mint(1) / C<mint, 1>(n, k);\n\
    }\n\n// [x^d] (1-x) ^ {-n} \u306E\u8A08\u7B97\ntemplate <typename mint, bool large\
    \ = false, bool dense = false>\nmint C_negative(ll n, ll d) {\n  assert(n >= 0);\n\
    \  if (d < 0) return mint(0);\n  if (n == 0) { return (d == 0 ? mint(1) : mint(0));\
    \ }\n  return C<mint, large, dense>(n + d - 1, d);\n}\n#line 3 \"mod/modint.hpp\"\
    \n\ntemplate <int mod>\nstruct modint {\n  int val;\n  constexpr modint(const\
    \ ll val = 0) noexcept\n      : val(val >= 0 ? val % mod : (mod - (-val) % mod)\
    \ % mod) {}\n  bool operator<(const modint &other) const {\n    return val < other.val;\n\
    \  } // To use std::map\n  modint &operator+=(const modint &p) {\n    if ((val\
    \ += p.val) >= mod) val -= mod;\n    return *this;\n  }\n  modint &operator-=(const\
    \ modint &p) {\n    if ((val += mod - p.val) >= mod) val -= mod;\n    return *this;\n\
    \  }\n  modint &operator*=(const modint &p) {\n    val = (int)(1LL * val * p.val\
    \ % mod);\n    return *this;\n  }\n  modint &operator/=(const modint &p) {\n \
    \   *this *= p.inverse();\n    return *this;\n  }\n  modint operator-() const\
    \ { return modint(-val); }\n  modint operator+(const modint &p) const { return\
    \ modint(*this) += p; }\n  modint operator-(const modint &p) const { return modint(*this)\
    \ -= p; }\n  modint operator*(const modint &p) const { return modint(*this) *=\
    \ p; }\n  modint operator/(const modint &p) const { return modint(*this) /= p;\
    \ }\n  bool operator==(const modint &p) const { return val == p.val; }\n  bool\
    \ operator!=(const modint &p) const { return val != p.val; }\n  modint inverse()\
    \ const {\n    int a = val, b = mod, u = 1, v = 0, t;\n    while (b > 0) {\n \
    \     t = a / b;\n      swap(a -= t * b, b), swap(u -= t * v, v);\n    }\n   \
    \ return modint(u);\n  }\n  modint pow(ll n) const {\n    assert(n >= 0);\n  \
    \  modint ret(1), mul(val);\n    while (n > 0) {\n      if (n & 1) ret *= mul;\n\
    \      mul *= mul;\n      n >>= 1;\n    }\n    return ret;\n  }\n#ifdef FASTIO\n\
    \  void write() { fastio::printer.write(val); }\n  void read() { fastio::scanner.read(val);\
    \ }\n#endif\n  static constexpr int get_mod() { return mod; }\n  // (n, r), r\
    \ \u306F 1 \u306E 2^n \u4E57\u6839\n  static constexpr pair<int, int> ntt_info()\
    \ {\n    if (mod == 167772161) return {25, 17};\n    if (mod == 469762049) return\
    \ {26, 30};\n    if (mod == 754974721) return {24, 362};\n    if (mod == 880803841)\
    \ return {23, 211};\n    if (mod == 998244353) return {23, 31};\n    if (mod ==\
    \ 1045430273) return {20, 363};\n    if (mod == 1051721729) return {20, 330};\n\
    \    if (mod == 1053818881) return {20, 2789};\n    return {-1, -1};\n  }\n};\n\
    \nstruct ArbitraryModInt {\n  static constexpr bool is_modint = true;\n  int val;\n\
    \  ArbitraryModInt() : val(0) {}\n  ArbitraryModInt(int64_t y)\n      : val(y\
    \ >= 0 ? y % get_mod()\n                   : (get_mod() - (-y) % get_mod()) %\
    \ get_mod()) {}\n  bool operator<(const ArbitraryModInt &other) const {\n    return\
    \ val < other.val;\n  } // To use std::map<ArbitraryModInt, T>\n  static int &get_mod()\
    \ {\n    static int mod = 0;\n    return mod;\n  }\n  static void set_mod(int\
    \ md) { get_mod() = md; }\n  ArbitraryModInt &operator+=(const ArbitraryModInt\
    \ &p) {\n    if ((val += p.val) >= get_mod()) val -= get_mod();\n    return *this;\n\
    \  }\n  ArbitraryModInt &operator-=(const ArbitraryModInt &p) {\n    if ((val\
    \ += get_mod() - p.val) >= get_mod()) val -= get_mod();\n    return *this;\n \
    \ }\n  ArbitraryModInt &operator*=(const ArbitraryModInt &p) {\n    long long\
    \ a = (long long)val * p.val;\n    int xh = (int)(a >> 32), xl = (int)a, d, m;\n\
    \    asm(\"divl %4; \\n\\t\" : \"=a\"(d), \"=d\"(m) : \"d\"(xh), \"a\"(xl), \"\
    r\"(get_mod()));\n    val = m;\n    return *this;\n  }\n  ArbitraryModInt &operator/=(const\
    \ ArbitraryModInt &p) {\n    *this *= p.inverse();\n    return *this;\n  }\n \
    \ ArbitraryModInt operator-() const { return ArbitraryModInt(get_mod() - val);\
    \ }\n  ArbitraryModInt operator+(const ArbitraryModInt &p) const {\n    return\
    \ ArbitraryModInt(*this) += p;\n  }\n  ArbitraryModInt operator-(const ArbitraryModInt\
    \ &p) const {\n    return ArbitraryModInt(*this) -= p;\n  }\n  ArbitraryModInt\
    \ operator*(const ArbitraryModInt &p) const {\n    return ArbitraryModInt(*this)\
    \ *= p;\n  }\n  ArbitraryModInt operator/(const ArbitraryModInt &p) const {\n\
    \    return ArbitraryModInt(*this) /= p;\n  }\n  bool operator==(const ArbitraryModInt\
    \ &p) const { return val == p.val; }\n  bool operator!=(const ArbitraryModInt\
    \ &p) const { return val != p.val; }\n  ArbitraryModInt inverse() const {\n  \
    \  int a = val, b = get_mod(), u = 1, v = 0, t;\n    while (b > 0) {\n      t\
    \ = a / b;\n      swap(a -= t * b, b), swap(u -= t * v, v);\n    }\n    return\
    \ ArbitraryModInt(u);\n  }\n  ArbitraryModInt pow(int64_t n) const {\n    assert(n\
    \ >= 0);\n    ArbitraryModInt ret(1), mul(val);\n    while (n > 0) {\n      if\
    \ (n & 1) ret *= mul;\n      mul *= mul;\n      n >>= 1;\n    }\n    return ret;\n\
    \  }\n#ifdef FASTIO\n  void write() { fastio::printer.write(val); }\n  void read()\
    \ { fastio::scanner.read(val); }\n#endif\n  static constexpr pair<int, int> ntt_info()\
    \ { return {-1, -1}; }\n};\n\nusing modint107 = modint<1000000007>;\nusing modint998\
    \ = modint<998244353>;\nusing amint = ArbitraryModInt;\n\nstruct has_mod_impl\
    \ {\n  template <class T>\n  static auto check(T &&x) -> decltype(x.get_mod(),\
    \ std::true_type{});\n  template <class T>\n  static auto check(...) -> std::false_type;\n\
    };\n\ntemplate <class T>\nclass has_mod : public decltype(has_mod_impl::check<T>(std::declval<T>()))\
    \ {};\n#line 1 \"alg/acted_set/from_monoid.hpp\"\ntemplate <typename Monoid>\n\
    struct ActedSet_From_Monoid {\n  using Monoid_A = Monoid;\n  using A = typename\
    \ Monoid::value_type;\n  using S = A;\n  static S act(const S &x, const A &g)\
    \ { return Monoid::op(x, g); }\n};\n#line 2 \"random/base.hpp\"\n\nu64 RNG_64()\
    \ {\n  static uint64_t x_\n      = uint64_t(chrono::duration_cast<chrono::nanoseconds>(\n\
    \                     chrono::high_resolution_clock::now().time_since_epoch())\n\
    \                     .count())\n        * 10150724397891781847ULL;\n  x_ ^= x_\
    \ << 7;\n  return x_ ^= x_ >> 9;\n}\n\nu64 RNG(u64 lim) { return RNG_64() % lim;\
    \ }\n\nll RNG(ll l, ll r) { return l + RNG_64() % (r - l); }\n#line 3 \"ds/hashmap.hpp\"\
    \n\r\n// u64 -> Val\r\ntemplate <typename Val, int LOG = 20>\r\nstruct HashMap\
    \ {\r\n  int N;\r\n  u64* keys;\r\n  Val* vals;\r\n  vc<int> IDS;\r\n  bitset<1\
    \ << LOG> used;\r\n  const int shift;\r\n  const u64 r = 11995408973635179863ULL;\r\
    \n  HashMap()\r\n      : N(1 << LOG), keys(new u64[N]), vals(new Val[N]), shift(64\
    \ - __lg(N)) {}\r\n  int hash(ll x) {\r\n    static const u64 FIXED_RANDOM\r\n\
    \        = std::chrono::steady_clock::now().time_since_epoch().count();\r\n  \
    \  return (u64(x + FIXED_RANDOM) * r) >> shift;\r\n  }\r\n\r\n  int index(const\
    \ u64& key) {\r\n    int i = 0;\r\n    for (i = hash(key); used[i] && keys[i]\
    \ != key; (i += 1) &= (N - 1)) {}\r\n    return i;\r\n  }\r\n\r\n  // [] \u3057\
    \u305F\u6642\u70B9\u3067\u8981\u7D20\u306F\u4F5C\u3089\u308C\u308B\r\n  Val& operator[](const\
    \ u64& key) {\r\n    int i = index(key);\r\n    if (!used[i]) IDS.eb(i), used[i]\
    \ = 1, keys[i] = key, vals[i] = Val{};\r\n    return vals[i];\r\n  }\r\n\r\n \
    \ Val get(const u64& key, Val default_value) {\r\n    int i = index(key);\r\n\
    \    if (!used[i]) return default_value;\r\n    return vals[i];\r\n  }\r\n\r\n\
    \  bool count(const u64& key) {\r\n    int i = index(key);\r\n    return used[i]\
    \ && keys[i] == key;\r\n  }\r\n\r\n  void reset() {\r\n    for (auto&& i: IDS)\
    \ used[i] = 0;\r\n    IDS.clear();\r\n  }\r\n\r\n  // f(key, val)\r\n  template\
    \ <typename F>\r\n  void enumerate_all(F f) {\r\n    for (auto&& i: IDS) f(keys[i],\
    \ vals[i]);\r\n  }\r\n};\r\n#line 3 \"nt/discrete_log.hpp\"\n\r\n// \u7FA4 X \u306E\
    \u4F5C\u7528\u3059\u308B\u96C6\u5408 S\u3001\u30CF\u30C3\u30B7\u30E5\u95A2\u6570\
    \ H\uFF1AS -> Z\r\n// x in G, s, t in S \u306B\u5BFE\u3057\u3066 x^ns = t \u3092\
    \u89E3\u304F\r\n// [lb, ub) \u306E\u6700\u521D\u306E\u89E3\u3092\u304B\u3048\u3059\
    \u3002\u306A\u3051\u308C\u3070 -1 \u3092\u304B\u3048\u3059\u3002\r\ntemplate <typename\
    \ ActedSet, typename F, int MP_SIZE = 20>\r\nll discrete_log_acted(typename ActedSet::A\
    \ x, typename ActedSet::S s,\r\n                      typename ActedSet::S t,\
    \ F H, ll lb, ll ub) {\r\n  static HashMap<int, MP_SIZE> MP;\r\n  MP.reset();\r\
    \n  using Group = typename ActedSet::Monoid_A;\r\n  using G = typename Group::value_type;\r\
    \n  G xinv = Group::inverse(x);\r\n  assert(Group::op(x, xinv) == Group::unit());\r\
    \n  if (lb >= ub) return -1;\r\n  auto xpow = [&](ll n) -> G {\r\n    G p = x;\r\
    \n    G res = Group::unit();\r\n    while (n) {\r\n      if (n & 1) res = Group::op(res,\
    \ p);\r\n      p = Group::op(p, p);\r\n      n /= 2;\r\n    }\r\n    return res;\r\
    \n  };\r\n  s = ActedSet::act(s, xpow(lb));\r\n  u64 LIM = ub - lb;\r\n\r\n  ll\
    \ K = sqrt(LIM) + 1;\r\n\r\n  FOR(k, K + 1) {\r\n    ll key = H(s);\r\n    if\
    \ (!MP.count(key)) MP[key] = k;\r\n    if (k != K) s = ActedSet::act(s, x);\r\n\
    \  }\r\n\r\n  x = Group::inverse(xpow(K));\r\n  FOR(k, K + 1) {\r\n    ll key\
    \ = H(t);\r\n    if (MP.count(key)) {\r\n      ll res = k * K + MP[key] + lb;\r\
    \n      return (res >= ub ? -1 : res);\r\n    }\r\n    t = ActedSet::act(t, x);\r\
    \n  }\r\n  return -1;\r\n}\r\n\r\n// \u7FA4 X \u306B\u304A\u3051\u308B log_a b\
    \ \u306E\u8A08\u7B97\r\n// \u30CF\u30C3\u30B7\u30E5\u95A2\u6570 H : X -> long\
    \ long \u3092\u6301\u305F\u305B\u308B\r\n// [lb, ub) \u306E\u6700\u521D\u306E\u89E3\
    \u3092\u304B\u3048\u3059\u3001\u306A\u3051\u308C\u3070 -1\r\ntemplate <typename\
    \ Group, typename F>\r\nll discrete_log_group(typename Group::X a, typename Group::X\
    \ b, F H, ll lb,\r\n                      ll ub) {\r\n  using AM = ActedSet_From_Monoid<Group>;\r\
    \n  return discrete_log_acted<AM>(a, Group::unit(), b, H, lb, ub);\r\n}\n#line\
    \ 2 \"alg/monoid/mul.hpp\"\n\r\ntemplate <class T>\r\nstruct Monoid_Mul {\r\n\
    \  using value_type = T;\r\n  using X = T;\r\n  static constexpr X op(const X\
    \ &x, const X &y) noexcept { return x * y; }\r\n  static constexpr X inverse(const\
    \ X &x) noexcept { return X(1) / x; }\r\n  static constexpr X unit() { return\
    \ X(1); }\r\n  static constexpr bool commute = true;\r\n};\r\n#line 4 \"mod/mod_log.hpp\"\
    \n\r\nint mod_log(int mod, ll a, ll b) {\r\n  a = divmod(a, mod).se;\r\n  b =\
    \ divmod(b, mod).se;\r\n  // \u307E\u305A\u7FA4\u306B\u5E30\u7740\u3059\u308B\u3002\
    \u5C0F\u3055\u3044\u5834\u5408\u306F\u8ABF\u3079\u308B\r\n  ll p = 1 % mod;\r\n\
    \  FOR(k, 32) {\r\n    if (p == b) return k;\r\n    p = p * a % mod;\r\n  }\r\n\
    \  if (a == 0 || b == 0) return -1;\r\n  ll g = gcd(mod, p);\r\n  if (b % g !=\
    \ 0) return -1;\r\n  mod /= g;\r\n  a %= mod, b %= mod;\r\n  if (gcd(b, mod) >\
    \ 1) return -1;\r\n  // \u7FA4\u306B\u5E30\u7740\u3055\u308C\u305F\r\n  amint::set_mod(mod);\r\
    \n  return discrete_log_group<Monoid_Mul<amint>>(\r\n      amint(a), amint(b),\
    \ [](auto x) { return x.val; }, 32, mod);\r\n}\r\n"
  code: "#include \"mod/modint.hpp\"\r\n#include \"nt/discrete_log.hpp\"\r\n#include\
    \ \"alg/monoid/mul.hpp\"\r\n\r\nint mod_log(int mod, ll a, ll b) {\r\n  a = divmod(a,\
    \ mod).se;\r\n  b = divmod(b, mod).se;\r\n  // \u307E\u305A\u7FA4\u306B\u5E30\u7740\
    \u3059\u308B\u3002\u5C0F\u3055\u3044\u5834\u5408\u306F\u8ABF\u3079\u308B\r\n \
    \ ll p = 1 % mod;\r\n  FOR(k, 32) {\r\n    if (p == b) return k;\r\n    p = p\
    \ * a % mod;\r\n  }\r\n  if (a == 0 || b == 0) return -1;\r\n  ll g = gcd(mod,\
    \ p);\r\n  if (b % g != 0) return -1;\r\n  mod /= g;\r\n  a %= mod, b %= mod;\r\
    \n  if (gcd(b, mod) > 1) return -1;\r\n  // \u7FA4\u306B\u5E30\u7740\u3055\u308C\
    \u305F\r\n  amint::set_mod(mod);\r\n  return discrete_log_group<Monoid_Mul<amint>>(\r\
    \n      amint(a), amint(b), [](auto x) { return x.val; }, 32, mod);\r\n}\r\n"
  dependsOn:
  - mod/modint.hpp
  - mod/factorial.hpp
  - nt/discrete_log.hpp
  - alg/acted_set/from_monoid.hpp
  - ds/hashmap.hpp
  - random/base.hpp
  - alg/monoid/mul.hpp
  isVerificationFile: false
  path: mod/mod_log.hpp
  requiredBy: []
  timestamp: '2023-02-23 14:02:30+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/library_checker/math/discrete_logarithm_mod.test.cpp
documentation_of: mod/mod_log.hpp
layout: document
redirect_from:
- /library/mod/mod_log.hpp
- /library/mod/mod_log.hpp.html
title: mod/mod_log.hpp
---
