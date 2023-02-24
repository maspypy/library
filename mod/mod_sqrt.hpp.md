---
data:
  _extendedDependsOn:
  - icon: ':question:'
    path: mod/factorial.hpp
    title: mod/factorial.hpp
  - icon: ':question:'
    path: mod/modint.hpp
    title: mod/modint.hpp
  - icon: ':question:'
    path: random/base.hpp
    title: random/base.hpp
  _extendedRequiredBy:
  - icon: ':x:'
    path: nt/four_square.hpp
    title: nt/four_square.hpp
  - icon: ':heavy_check_mark:'
    path: poly/fps_sqrt.hpp
    title: poly/fps_sqrt.hpp
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/library_checker/math/sqrt_mod.test.cpp
    title: test/library_checker/math/sqrt_mod.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/library_checker/polynomial/sqrt_of_fps.test.cpp
    title: test/library_checker/polynomial/sqrt_of_fps.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/library_checker/polynomial/sqrt_of_fps_sparse.test.cpp
    title: test/library_checker/polynomial/sqrt_of_fps_sparse.test.cpp
  - icon: ':x:'
    path: test/mytest/four_square.test.cpp
    title: test/mytest/four_square.test.cpp
  _isVerificationFailed: true
  _pathExtension: hpp
  _verificationStatusIcon: ':question:'
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
    \ {};\n#line 2 \"random/base.hpp\"\n\nu64 RNG_64() {\n  static uint64_t x_\n \
    \     = uint64_t(chrono::duration_cast<chrono::nanoseconds>(\n               \
    \      chrono::high_resolution_clock::now().time_since_epoch())\n            \
    \         .count())\n        * 10150724397891781847ULL;\n  x_ ^= x_ << 7;\n  return\
    \ x_ ^= x_ >> 9;\n}\n\nu64 RNG(u64 lim) { return RNG_64() % lim; }\n\nll RNG(ll\
    \ l, ll r) { return l + RNG_64() % (r - l); }\n#line 3 \"mod/mod_sqrt.hpp\"\n\r\
    \ntemplate <typename mint>\r\nmint mod_sqrt(mint a) {\r\n  int p = mint::get_mod();\r\
    \n  if (p == 2) return a;\r\n  if (a == 0) return 0;\r\n  int k = (p - 1) / 2;\r\
    \n  if (a.pow(k) != 1) return 0;\r\n  auto find = [&]() -> pair<mint, mint> {\r\
    \n    while (1) {\r\n      mint b = RNG(2, p);\r\n      mint D = b * b - a;\r\n\
    \      if (D == 0) return {b, D};\r\n      if (D.pow(k) != mint(1)) return {b,\
    \ D};\r\n    }\r\n  };\r\n  auto [b, D] = find();\r\n  if (D == 0) return b;\r\
    \n  ++k;\r\n  // (b + sqrt(D))^k\r\n  mint f0 = b, f1 = 1;\r\n  mint g0 = 1, g1\
    \ = 0;\r\n  while (k) {\r\n    if (k & 1) { tie(g0, g1) = mp(f0 * g0 + D * f1\
    \ * g1, f1 * g0 + f0 * g1); }\r\n    tie(f0, f1) = mp(f0 * f0 + D * f1 * f1, mint(2)\
    \ * f0 * f1);\r\n    k >>= 1;\r\n  }\r\n  return g0;\r\n}\r\n"
  code: "#include \"mod/modint.hpp\"\r\n#include \"random/base.hpp\"\r\n\r\ntemplate\
    \ <typename mint>\r\nmint mod_sqrt(mint a) {\r\n  int p = mint::get_mod();\r\n\
    \  if (p == 2) return a;\r\n  if (a == 0) return 0;\r\n  int k = (p - 1) / 2;\r\
    \n  if (a.pow(k) != 1) return 0;\r\n  auto find = [&]() -> pair<mint, mint> {\r\
    \n    while (1) {\r\n      mint b = RNG(2, p);\r\n      mint D = b * b - a;\r\n\
    \      if (D == 0) return {b, D};\r\n      if (D.pow(k) != mint(1)) return {b,\
    \ D};\r\n    }\r\n  };\r\n  auto [b, D] = find();\r\n  if (D == 0) return b;\r\
    \n  ++k;\r\n  // (b + sqrt(D))^k\r\n  mint f0 = b, f1 = 1;\r\n  mint g0 = 1, g1\
    \ = 0;\r\n  while (k) {\r\n    if (k & 1) { tie(g0, g1) = mp(f0 * g0 + D * f1\
    \ * g1, f1 * g0 + f0 * g1); }\r\n    tie(f0, f1) = mp(f0 * f0 + D * f1 * f1, mint(2)\
    \ * f0 * f1);\r\n    k >>= 1;\r\n  }\r\n  return g0;\r\n}\r\n"
  dependsOn:
  - mod/modint.hpp
  - mod/factorial.hpp
  - random/base.hpp
  isVerificationFile: false
  path: mod/mod_sqrt.hpp
  requiredBy:
  - nt/four_square.hpp
  - poly/fps_sqrt.hpp
  timestamp: '2023-02-23 14:02:30+09:00'
  verificationStatus: LIBRARY_SOME_WA
  verifiedWith:
  - test/library_checker/math/sqrt_mod.test.cpp
  - test/library_checker/polynomial/sqrt_of_fps_sparse.test.cpp
  - test/library_checker/polynomial/sqrt_of_fps.test.cpp
  - test/mytest/four_square.test.cpp
documentation_of: mod/mod_sqrt.hpp
layout: document
redirect_from:
- /library/mod/mod_sqrt.hpp
- /library/mod/mod_sqrt.hpp.html
title: mod/mod_sqrt.hpp
---
