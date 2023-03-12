---
data:
  _extendedDependsOn:
  - icon: ':question:'
    path: mod/modint.hpp
    title: mod/modint.hpp
  - icon: ':question:'
    path: mod/modint_common.hpp
    title: mod/modint_common.hpp
  _extendedRequiredBy:
  - icon: ':x:'
    path: linalg/det_A_plus_xB.hpp
    title: linalg/det_A_plus_xB.hpp
  - icon: ':x:'
    path: linalg/mat_pow.hpp
    title: linalg/mat_pow.hpp
  - icon: ':x:'
    path: poly/from_log_differentiation.hpp
    title: poly/from_log_differentiation.hpp
  - icon: ':x:'
    path: poly/prefix_product_of_poly.hpp
    title: poly/prefix_product_of_poly.hpp
  - icon: ':x:'
    path: poly/sparse_exp_of_div.hpp
    title: poly/sparse_exp_of_div.hpp
  - icon: ':x:'
    path: seq/kth_term_of_p_recursive.hpp
    title: seq/kth_term_of_p_recursive.hpp
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/library_checker/matrix/matrix_product.test.cpp
    title: test/library_checker/matrix/matrix_product.test.cpp
  - icon: ':x:'
    path: test/mytest/factorial_998.test.cpp
    title: test/mytest/factorial_998.test.cpp
  - icon: ':x:'
    path: test/yukicoder/1080_2.test.cpp
    title: test/yukicoder/1080_2.test.cpp
  - icon: ':x:'
    path: test/yukicoder/1303.test.cpp
    title: test/yukicoder/1303.test.cpp
  - icon: ':x:'
    path: test/yukicoder/1750.test.cpp
    title: test/yukicoder/1750.test.cpp
  - icon: ':x:'
    path: test/yukicoder/1810.test.cpp
    title: test/yukicoder/1810.test.cpp
  - icon: ':x:'
    path: test/yukicoder/1907.test.cpp
    title: test/yukicoder/1907.test.cpp
  - icon: ':x:'
    path: test/yukicoder/2166.test.cpp
    title: test/yukicoder/2166.test.cpp
  - icon: ':x:'
    path: test/yukicoder/426.test.cpp
    title: test/yukicoder/426.test.cpp
  - icon: ':x:'
    path: test/yukicoder/502_2.test.cpp
    title: test/yukicoder/502_2.test.cpp
  - icon: ':x:'
    path: test_atcoder/abc222h_2.test.cpp
    title: test_atcoder/abc222h_2.test.cpp
  - icon: ':x:'
    path: test_atcoder/abc276_g.test.cpp
    title: test_atcoder/abc276_g.test.cpp
  - icon: ':x:'
    path: test_atcoder/abc276_g_2.test.cpp
    title: test_atcoder/abc276_g_2.test.cpp
  _isVerificationFailed: true
  _pathExtension: hpp
  _verificationStatusIcon: ':question:'
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
    \ {20, 2789};\n    return {-1, -1};\n  }\n};\n\nusing modint107 = modint<1000000007>;\n\
    using modint998 = modint<998244353>;\n#line 3 \"linalg/mat_mul.hpp\"\n\r\ntemplate\
    \ <class T, typename enable_if<has_mod<T>::value>::type* = nullptr>\r\nvc<vc<T>>\
    \ mat_mul(const vc<vc<T>>& A, const vc<vc<T>>& B) {\r\n  constexpr int mod = T::get_mod();\r\
    \n  auto N = len(A), M = len(B), K = len(B[0]);\r\n  vv(int, b, K, M);\r\n  FOR(i,\
    \ M) FOR(j, K) b[j][i] = B[i][j].val;\r\n  vv(T, C, N, K);\r\n\r\n  if (M <= 16)\
    \ {\r\n    FOR(i, N) FOR(j, K) {\r\n      u64 sm = 0;\r\n      FOR(m, M) sm +=\
    \ u64(A[i][m].val) * b[j][m];\r\n      C[i][j] = sm % mod;\r\n    }\r\n  } else\
    \ {\r\n    FOR(i, N) FOR(j, K) {\r\n      i128 sm = 0;\r\n      FOR(m, M) sm +=\
    \ ll(A[i][m].val) * b[j][m];\r\n      C[i][j] = sm % mod;\r\n    }\r\n  }\r\n\
    \  return C;\r\n}\r\n\r\ntemplate <class T, typename enable_if<!has_mod<T>::value>::type*\
    \ = nullptr>\r\nvc<vc<T>> mat_mul(const vc<vc<T>>& A, const vc<vc<T>>& B) {\r\n\
    \  auto N = len(A), M = len(B), K = len(B[0]);\r\n  vv(T, b, K, M);\r\n  FOR(i,\
    \ M) FOR(j, K) b[j][i] = B[i][j];\r\n  vv(T, C, N, K);\r\n  FOR(n, N) FOR(m, M)\
    \ FOR(k, K) C[n][k] += A[n][m] * b[k][m];\r\n  return C;\r\n}\r\n"
  code: "#pragma once\r\n#include \"mod/modint.hpp\"\r\n\r\ntemplate <class T, typename\
    \ enable_if<has_mod<T>::value>::type* = nullptr>\r\nvc<vc<T>> mat_mul(const vc<vc<T>>&\
    \ A, const vc<vc<T>>& B) {\r\n  constexpr int mod = T::get_mod();\r\n  auto N\
    \ = len(A), M = len(B), K = len(B[0]);\r\n  vv(int, b, K, M);\r\n  FOR(i, M) FOR(j,\
    \ K) b[j][i] = B[i][j].val;\r\n  vv(T, C, N, K);\r\n\r\n  if (M <= 16) {\r\n \
    \   FOR(i, N) FOR(j, K) {\r\n      u64 sm = 0;\r\n      FOR(m, M) sm += u64(A[i][m].val)\
    \ * b[j][m];\r\n      C[i][j] = sm % mod;\r\n    }\r\n  } else {\r\n    FOR(i,\
    \ N) FOR(j, K) {\r\n      i128 sm = 0;\r\n      FOR(m, M) sm += ll(A[i][m].val)\
    \ * b[j][m];\r\n      C[i][j] = sm % mod;\r\n    }\r\n  }\r\n  return C;\r\n}\r\
    \n\r\ntemplate <class T, typename enable_if<!has_mod<T>::value>::type* = nullptr>\r\
    \nvc<vc<T>> mat_mul(const vc<vc<T>>& A, const vc<vc<T>>& B) {\r\n  auto N = len(A),\
    \ M = len(B), K = len(B[0]);\r\n  vv(T, b, K, M);\r\n  FOR(i, M) FOR(j, K) b[j][i]\
    \ = B[i][j];\r\n  vv(T, C, N, K);\r\n  FOR(n, N) FOR(m, M) FOR(k, K) C[n][k] +=\
    \ A[n][m] * b[k][m];\r\n  return C;\r\n}\r\n"
  dependsOn:
  - mod/modint.hpp
  - mod/modint_common.hpp
  isVerificationFile: false
  path: linalg/mat_mul.hpp
  requiredBy:
  - poly/sparse_exp_of_div.hpp
  - poly/prefix_product_of_poly.hpp
  - poly/from_log_differentiation.hpp
  - seq/kth_term_of_p_recursive.hpp
  - linalg/det_A_plus_xB.hpp
  - linalg/mat_pow.hpp
  timestamp: '2023-03-12 10:53:54+09:00'
  verificationStatus: LIBRARY_SOME_WA
  verifiedWith:
  - test_atcoder/abc222h_2.test.cpp
  - test_atcoder/abc276_g_2.test.cpp
  - test_atcoder/abc276_g.test.cpp
  - test/mytest/factorial_998.test.cpp
  - test/yukicoder/1907.test.cpp
  - test/yukicoder/502_2.test.cpp
  - test/yukicoder/2166.test.cpp
  - test/yukicoder/1810.test.cpp
  - test/yukicoder/1303.test.cpp
  - test/yukicoder/426.test.cpp
  - test/yukicoder/1750.test.cpp
  - test/yukicoder/1080_2.test.cpp
  - test/library_checker/matrix/matrix_product.test.cpp
documentation_of: linalg/mat_mul.hpp
layout: document
redirect_from:
- /library/linalg/mat_mul.hpp
- /library/linalg/mat_mul.hpp.html
title: linalg/mat_mul.hpp
---
