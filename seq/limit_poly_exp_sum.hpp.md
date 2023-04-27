---
data:
  _extendedDependsOn:
  - icon: ':question:'
    path: mod/modint.hpp
    title: mod/modint.hpp
  - icon: ':question:'
    path: mod/modint_common.hpp
    title: mod/modint_common.hpp
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/library_checker/math/sum_of_exp_times_poly_limit.test.cpp
    title: test/library_checker/math/sum_of_exp_times_poly_limit.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 2 \"mod/modint_common.hpp\"\n\nstruct has_mod_impl {\n  template\
    \ <class T>\n  static auto check(T &&x) -> decltype(x.get_mod(), std::true_type{});\n\
    \  template <class T>\n  static auto check(...) -> std::false_type;\n};\n\ntemplate\
    \ <class T>\nclass has_mod : public decltype(has_mod_impl::check<T>(std::declval<T>()))\
    \ {};\n\n\ntemplate <typename mint>\nmint inv(int n) {\n  static const int mod\
    \ = mint::get_mod();\n  static vector<mint> dat = {0, 1};\n  assert(0 <= n);\n\
    \  if (n >= mod) n %= mod;\n  while (len(dat) <= n) {\n    int k = len(dat);\n\
    \    int q = (mod + k - 1) / k;\n    dat.eb(dat[k * q - mod] * mint(q));\n  }\n\
    \  return dat[n];\n}\n\ntemplate <typename mint>\nmint fact(int n) {\n  static\
    \ const int mod = mint::get_mod();\n  assert(0 <= n);\n  if (n >= mod) return\
    \ 0;\n  static vector<mint> dat = {1, 1};\n  while (len(dat) <= n) dat.eb(dat[len(dat)\
    \ - 1] * mint(len(dat)));\n  return dat[n];\n}\n\ntemplate <typename mint>\nmint\
    \ fact_inv(int n) {\n  static const int mod = mint::get_mod();\n  assert(-1 <=\
    \ n && n < mod);\n  static vector<mint> dat = {1, 1};\n  if (n == -1) return mint(0);\n\
    \  while (len(dat) <= n) dat.eb(dat[len(dat) - 1] * inv<mint>(len(dat)));\n  return\
    \ dat[n];\n}\n\ntemplate <class mint, class... Ts>\nmint fact_invs(Ts... xs) {\n\
    \  return (mint(1) * ... * fact_inv<mint>(xs));\n}\n\ntemplate <typename mint,\
    \ class Head, class... Tail>\nmint multinomial(Head &&head, Tail &&... tail) {\n\
    \  return fact<mint>(head) * fact_invs<mint>(std::forward<Tail>(tail)...);\n}\n\
    \ntemplate <typename mint>\nmint C_dense(int n, int k) {\n  static vvc<mint> C;\n\
    \  static int H = 0, W = 0;\n  auto calc = [&](int i, int j) -> mint {\n    if\
    \ (i == 0) return (j == 0 ? mint(1) : mint(0));\n    return C[i - 1][j] + (j ?\
    \ C[i - 1][j - 1] : 0);\n  };\n  if (W <= k) {\n    FOR(i, H) {\n      C[i].resize(k\
    \ + 1);\n      FOR(j, W, k + 1) { C[i][j] = calc(i, j); }\n    }\n    W = k +\
    \ 1;\n  }\n  if (H <= n) {\n    C.resize(n + 1);\n    FOR(i, H, n + 1) {\n   \
    \   C[i].resize(W);\n      FOR(j, W) { C[i][j] = calc(i, j); }\n    }\n    H =\
    \ n + 1;\n  }\n  return C[n][k];\n}\n\ntemplate <typename mint, bool large = false,\
    \ bool dense = false>\nmint C(ll n, ll k) {\n  assert(n >= 0);\n  if (k < 0 ||\
    \ n < k) return 0;\n  if (dense) return C_dense<mint>(n, k);\n  if (!large) return\
    \ multinomial<mint>(n, k, n - k);\n  k = min(k, n - k);\n  mint x(1);\n  FOR(i,\
    \ k) x *= mint(n - i);\n  return x * fact_inv<mint>(k);\n}\n\ntemplate <typename\
    \ mint, bool large = false>\nmint C_inv(ll n, ll k) {\n  assert(n >= 0);\n  assert(0\
    \ <= k && k <= n);\n  if (!large) return fact_inv<mint>(n) * fact<mint>(k) * fact<mint>(n\
    \ - k);\n  return mint(1) / C<mint, 1>(n, k);\n}\n\n// [x^d] (1-x) ^ {-n} \u306E\
    \u8A08\u7B97\ntemplate <typename mint, bool large = false, bool dense = false>\n\
    mint C_negative(ll n, ll d) {\n  assert(n >= 0);\n  if (d < 0) return mint(0);\n\
    \  if (n == 0) { return (d == 0 ? mint(1) : mint(0)); }\n  return C<mint, large,\
    \ dense>(n + d - 1, d);\n}\n#line 3 \"mod/modint.hpp\"\n\ntemplate <int mod>\n\
    struct modint {\n  int val;\n  constexpr modint(const ll val = 0) noexcept\n \
    \     : val(val >= 0 ? val % mod : (mod - (-val) % mod) % mod) {}\n  bool operator<(const\
    \ modint &other) const {\n    return val < other.val;\n  } // To use std::map\n\
    \  modint &operator+=(const modint &p) {\n    if ((val += p.val) >= mod) val -=\
    \ mod;\n    return *this;\n  }\n  modint &operator-=(const modint &p) {\n    if\
    \ ((val += mod - p.val) >= mod) val -= mod;\n    return *this;\n  }\n  modint\
    \ &operator*=(const modint &p) {\n    val = (int)(1LL * val * p.val % mod);\n\
    \    return *this;\n  }\n  modint &operator/=(const modint &p) {\n    *this *=\
    \ p.inverse();\n    return *this;\n  }\n  modint operator-() const { return modint(-val);\
    \ }\n  modint operator+(const modint &p) const { return modint(*this) += p; }\n\
    \  modint operator-(const modint &p) const { return modint(*this) -= p; }\n  modint\
    \ operator*(const modint &p) const { return modint(*this) *= p; }\n  modint operator/(const\
    \ modint &p) const { return modint(*this) /= p; }\n  bool operator==(const modint\
    \ &p) const { return val == p.val; }\n  bool operator!=(const modint &p) const\
    \ { return val != p.val; }\n  modint inverse() const {\n    int a = val, b = mod,\
    \ u = 1, v = 0, t;\n    while (b > 0) {\n      t = a / b;\n      swap(a -= t *\
    \ b, b), swap(u -= t * v, v);\n    }\n    return modint(u);\n  }\n  modint pow(ll\
    \ n) const {\n    assert(n >= 0);\n    modint ret(1), mul(val);\n    while (n\
    \ > 0) {\n      if (n & 1) ret *= mul;\n      mul *= mul;\n      n >>= 1;\n  \
    \  }\n    return ret;\n  }\n#ifdef FASTIO\n  void write() { fastio::printer.write(val);\
    \ }\n  void read() { fastio::scanner.read(val); }\n#endif\n  static constexpr\
    \ int get_mod() { return mod; }\n  // (n, r), r \u306F 1 \u306E 2^n \u4E57\u6839\
    \n  static constexpr pair<int, int> ntt_info() {\n    if (mod == 167772161) return\
    \ {25, 17};\n    if (mod == 469762049) return {26, 30};\n    if (mod == 754974721)\
    \ return {24, 362};\n    if (mod == 880803841) return {23, 211};\n    if (mod\
    \ == 998244353) return {23, 31};\n    if (mod == 1045430273) return {20, 363};\n\
    \    if (mod == 1051721729) return {20, 330};\n    if (mod == 1053818881) return\
    \ {20, 2789};\n    return {-1, -1};\n  }\n  static constexpr bool can_ntt() {\
    \ return ntt_info().fi != -1; }\n};\n\nusing modint107 = modint<1000000007>;\n\
    using modint998 = modint<998244353>;\n#line 2 \"seq/limit_poly_exp_sum.hpp\"\n\
    template <typename mint>\r\nmint limit_poly_exp_sum(vc<mint> a, mint r) {\r\n\
    \  /*\r\n  a[i] = (prefix sum of r^i * (polynomial of i)) \u3068\u306A\u3063\u3066\
    \u3044\u308B\u3082\u306E\u306E\u6975\u9650\r\n  fps \u3067\u306F (1-rx)^d(1-x)\
    \ \u306E\u5F62\u306E\u5206\u6BCD\u3092\u6301\u3064\u5834\u5408\u3068\u3044\u3046\
    \u3053\u3068\u306B\u306A\u308B\r\n  f(x) = g(x) / (1-rx)^d + c / (1-x) \u3068\u3057\
    \u3066\u3001c \u304C\u7B54\u3067\u3042\u308B\r\n  */\r\n  mint c = 0;\r\n  int\
    \ d = len(a) - 1;\r\n  mint p = 1;\r\n  FOR(i, d + 1) {\r\n    c += a[d - i] *\
    \ p * C<mint>(d, i);\r\n    p *= -r;\r\n  }\r\n  c /= (mint(1) - r).pow(d);\r\n\
    \  return c;\r\n}\r\n"
  code: "#include \"mod/modint.hpp\"\r\ntemplate <typename mint>\r\nmint limit_poly_exp_sum(vc<mint>\
    \ a, mint r) {\r\n  /*\r\n  a[i] = (prefix sum of r^i * (polynomial of i)) \u3068\
    \u306A\u3063\u3066\u3044\u308B\u3082\u306E\u306E\u6975\u9650\r\n  fps \u3067\u306F\
    \ (1-rx)^d(1-x) \u306E\u5F62\u306E\u5206\u6BCD\u3092\u6301\u3064\u5834\u5408\u3068\
    \u3044\u3046\u3053\u3068\u306B\u306A\u308B\r\n  f(x) = g(x) / (1-rx)^d + c / (1-x)\
    \ \u3068\u3057\u3066\u3001c \u304C\u7B54\u3067\u3042\u308B\r\n  */\r\n  mint c\
    \ = 0;\r\n  int d = len(a) - 1;\r\n  mint p = 1;\r\n  FOR(i, d + 1) {\r\n    c\
    \ += a[d - i] * p * C<mint>(d, i);\r\n    p *= -r;\r\n  }\r\n  c /= (mint(1) -\
    \ r).pow(d);\r\n  return c;\r\n}\r\n"
  dependsOn:
  - mod/modint.hpp
  - mod/modint_common.hpp
  isVerificationFile: false
  path: seq/limit_poly_exp_sum.hpp
  requiredBy: []
  timestamp: '2023-04-27 03:47:30+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/library_checker/math/sum_of_exp_times_poly_limit.test.cpp
documentation_of: seq/limit_poly_exp_sum.hpp
layout: document
redirect_from:
- /library/seq/limit_poly_exp_sum.hpp
- /library/seq/limit_poly_exp_sum.hpp.html
title: seq/limit_poly_exp_sum.hpp
---
