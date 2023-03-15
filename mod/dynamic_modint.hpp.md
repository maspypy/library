---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: mod/modint_common.hpp
    title: mod/modint_common.hpp
  _extendedRequiredBy:
  - icon: ':heavy_check_mark:'
    path: mod/mod_log.hpp
    title: mod/mod_log.hpp
  - icon: ':heavy_check_mark:'
    path: nt/four_square.hpp
    title: nt/four_square.hpp
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/library_checker/convolution/convolution_mod_107_amint.test.cpp
    title: test/library_checker/convolution/convolution_mod_107_amint.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/library_checker/math/discrete_logarithm_mod.test.cpp
    title: test/library_checker/math/discrete_logarithm_mod.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/library_checker/math/multivariate_convolution_cyclic.test.cpp
    title: test/library_checker/math/multivariate_convolution_cyclic.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/library_checker/math/sqrt_mod.test.cpp
    title: test/library_checker/math/sqrt_mod.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/library_checker/polynomial/exp_of_fps_amint.test.cpp
    title: test/library_checker/polynomial/exp_of_fps_amint.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/library_checker/polynomial/inv_of_fps_amint.test.cpp
    title: test/library_checker/polynomial/inv_of_fps_amint.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/library_checker/polynomial/pow_of_fps_mint.test.cpp
    title: test/library_checker/polynomial/pow_of_fps_mint.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/mytest/four_square.test.cpp
    title: test/mytest/four_square.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/yukicoder/1339.test.cpp
    title: test/yukicoder/1339.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/yukicoder/1667.test.cpp
    title: test/yukicoder/1667.test.cpp
  - icon: ':heavy_check_mark:'
    path: test_atcoder/abc222g.test.cpp
    title: test_atcoder/abc222g.test.cpp
  - icon: ':heavy_check_mark:'
    path: test_atcoder/abc270_g.test.cpp
    title: test_atcoder/abc270_g.test.cpp
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
    \ dense>(n + d - 1, d);\n}\n#line 3 \"mod/dynamic_modint.hpp\"\n\nstruct Dynamic_ModInt\
    \ {\n  static constexpr bool is_modint = true;\n  int val;\n  Dynamic_ModInt()\
    \ : val(0) {}\n  Dynamic_ModInt(int64_t y)\n      : val(y >= 0 ? y % get_mod()\n\
    \                   : (get_mod() - (-y) % get_mod()) % get_mod()) {}\n  bool operator<(const\
    \ Dynamic_ModInt &other) const {\n    return val < other.val;\n  } // To use std::map<Dynamic_ModInt,\
    \ T>\n  static int &get_mod() {\n    static int mod = 0;\n    return mod;\n  }\n\
    \  static void set_mod(int md) { get_mod() = md; }\n  Dynamic_ModInt &operator+=(const\
    \ Dynamic_ModInt &p) {\n    if ((val += p.val) >= get_mod()) val -= get_mod();\n\
    \    return *this;\n  }\n  Dynamic_ModInt &operator-=(const Dynamic_ModInt &p)\
    \ {\n    if ((val += get_mod() - p.val) >= get_mod()) val -= get_mod();\n    return\
    \ *this;\n  }\n  Dynamic_ModInt &operator*=(const Dynamic_ModInt &p) {\n    long\
    \ long a = (long long)val * p.val;\n    int xh = (int)(a >> 32), xl = (int)a,\
    \ d, m;\n    asm(\"divl %4; \\n\\t\" : \"=a\"(d), \"=d\"(m) : \"d\"(xh), \"a\"\
    (xl), \"r\"(get_mod()));\n    val = m;\n    return *this;\n  }\n  Dynamic_ModInt\
    \ &operator/=(const Dynamic_ModInt &p) {\n    *this *= p.inverse();\n    return\
    \ *this;\n  }\n  Dynamic_ModInt operator-() const { return Dynamic_ModInt(get_mod()\
    \ - val); }\n  Dynamic_ModInt operator+(const Dynamic_ModInt &p) const {\n   \
    \ return Dynamic_ModInt(*this) += p;\n  }\n  Dynamic_ModInt operator-(const Dynamic_ModInt\
    \ &p) const {\n    return Dynamic_ModInt(*this) -= p;\n  }\n  Dynamic_ModInt operator*(const\
    \ Dynamic_ModInt &p) const {\n    return Dynamic_ModInt(*this) *= p;\n  }\n  Dynamic_ModInt\
    \ operator/(const Dynamic_ModInt &p) const {\n    return Dynamic_ModInt(*this)\
    \ /= p;\n  }\n  bool operator==(const Dynamic_ModInt &p) const { return val ==\
    \ p.val; }\n  bool operator!=(const Dynamic_ModInt &p) const { return val != p.val;\
    \ }\n  Dynamic_ModInt inverse() const {\n    int a = val, b = get_mod(), u = 1,\
    \ v = 0, t;\n    while (b > 0) {\n      t = a / b;\n      swap(a -= t * b, b),\
    \ swap(u -= t * v, v);\n    }\n    return Dynamic_ModInt(u);\n  }\n  Dynamic_ModInt\
    \ pow(int64_t n) const {\n    assert(n >= 0);\n    Dynamic_ModInt ret(1), mul(val);\n\
    \    while (n > 0) {\n      if (n & 1) ret *= mul;\n      mul *= mul;\n      n\
    \ >>= 1;\n    }\n    return ret;\n  }\n#ifdef FASTIO\n  void write() { fastio::printer.write(val);\
    \ }\n  void read() { fastio::scanner.read(val); }\n#endif\n  static constexpr\
    \ pair<int, int> ntt_info() { return {-1, -1}; }\n};\n\nusing dmint = Dynamic_ModInt;\n"
  code: "#pragma once\n#include \"mod/modint_common.hpp\"\n\nstruct Dynamic_ModInt\
    \ {\n  static constexpr bool is_modint = true;\n  int val;\n  Dynamic_ModInt()\
    \ : val(0) {}\n  Dynamic_ModInt(int64_t y)\n      : val(y >= 0 ? y % get_mod()\n\
    \                   : (get_mod() - (-y) % get_mod()) % get_mod()) {}\n  bool operator<(const\
    \ Dynamic_ModInt &other) const {\n    return val < other.val;\n  } // To use std::map<Dynamic_ModInt,\
    \ T>\n  static int &get_mod() {\n    static int mod = 0;\n    return mod;\n  }\n\
    \  static void set_mod(int md) { get_mod() = md; }\n  Dynamic_ModInt &operator+=(const\
    \ Dynamic_ModInt &p) {\n    if ((val += p.val) >= get_mod()) val -= get_mod();\n\
    \    return *this;\n  }\n  Dynamic_ModInt &operator-=(const Dynamic_ModInt &p)\
    \ {\n    if ((val += get_mod() - p.val) >= get_mod()) val -= get_mod();\n    return\
    \ *this;\n  }\n  Dynamic_ModInt &operator*=(const Dynamic_ModInt &p) {\n    long\
    \ long a = (long long)val * p.val;\n    int xh = (int)(a >> 32), xl = (int)a,\
    \ d, m;\n    asm(\"divl %4; \\n\\t\" : \"=a\"(d), \"=d\"(m) : \"d\"(xh), \"a\"\
    (xl), \"r\"(get_mod()));\n    val = m;\n    return *this;\n  }\n  Dynamic_ModInt\
    \ &operator/=(const Dynamic_ModInt &p) {\n    *this *= p.inverse();\n    return\
    \ *this;\n  }\n  Dynamic_ModInt operator-() const { return Dynamic_ModInt(get_mod()\
    \ - val); }\n  Dynamic_ModInt operator+(const Dynamic_ModInt &p) const {\n   \
    \ return Dynamic_ModInt(*this) += p;\n  }\n  Dynamic_ModInt operator-(const Dynamic_ModInt\
    \ &p) const {\n    return Dynamic_ModInt(*this) -= p;\n  }\n  Dynamic_ModInt operator*(const\
    \ Dynamic_ModInt &p) const {\n    return Dynamic_ModInt(*this) *= p;\n  }\n  Dynamic_ModInt\
    \ operator/(const Dynamic_ModInt &p) const {\n    return Dynamic_ModInt(*this)\
    \ /= p;\n  }\n  bool operator==(const Dynamic_ModInt &p) const { return val ==\
    \ p.val; }\n  bool operator!=(const Dynamic_ModInt &p) const { return val != p.val;\
    \ }\n  Dynamic_ModInt inverse() const {\n    int a = val, b = get_mod(), u = 1,\
    \ v = 0, t;\n    while (b > 0) {\n      t = a / b;\n      swap(a -= t * b, b),\
    \ swap(u -= t * v, v);\n    }\n    return Dynamic_ModInt(u);\n  }\n  Dynamic_ModInt\
    \ pow(int64_t n) const {\n    assert(n >= 0);\n    Dynamic_ModInt ret(1), mul(val);\n\
    \    while (n > 0) {\n      if (n & 1) ret *= mul;\n      mul *= mul;\n      n\
    \ >>= 1;\n    }\n    return ret;\n  }\n#ifdef FASTIO\n  void write() { fastio::printer.write(val);\
    \ }\n  void read() { fastio::scanner.read(val); }\n#endif\n  static constexpr\
    \ pair<int, int> ntt_info() { return {-1, -1}; }\n};\n\nusing dmint = Dynamic_ModInt;\n"
  dependsOn:
  - mod/modint_common.hpp
  isVerificationFile: false
  path: mod/dynamic_modint.hpp
  requiredBy:
  - nt/four_square.hpp
  - mod/mod_log.hpp
  timestamp: '2023-03-12 10:53:54+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test_atcoder/abc270_g.test.cpp
  - test_atcoder/abc222g.test.cpp
  - test/mytest/four_square.test.cpp
  - test/yukicoder/1339.test.cpp
  - test/yukicoder/1667.test.cpp
  - test/library_checker/math/multivariate_convolution_cyclic.test.cpp
  - test/library_checker/math/sqrt_mod.test.cpp
  - test/library_checker/math/discrete_logarithm_mod.test.cpp
  - test/library_checker/polynomial/exp_of_fps_amint.test.cpp
  - test/library_checker/polynomial/inv_of_fps_amint.test.cpp
  - test/library_checker/polynomial/pow_of_fps_mint.test.cpp
  - test/library_checker/convolution/convolution_mod_107_amint.test.cpp
documentation_of: mod/dynamic_modint.hpp
layout: document
redirect_from:
- /library/mod/dynamic_modint.hpp
- /library/mod/dynamic_modint.hpp.html
title: mod/dynamic_modint.hpp
---
