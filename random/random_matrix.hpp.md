---
data:
  _extendedDependsOn:
  - icon: ':question:'
    path: linalg/det.hpp
    title: linalg/det.hpp
  - icon: ':heavy_check_mark:'
    path: linalg/matrix_mul.hpp
    title: linalg/matrix_mul.hpp
  - icon: ':question:'
    path: mod/barrett.hpp
    title: mod/barrett.hpp
  - icon: ':question:'
    path: mod/modint.hpp
    title: mod/modint.hpp
  - icon: ':question:'
    path: mod/modint_common.hpp
    title: mod/modint_common.hpp
  - icon: ':question:'
    path: random/base.hpp
    title: random/base.hpp
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/1_mytest/blackbox_solve_linear.test.cpp
    title: test/1_mytest/blackbox_solve_linear.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 1 \"random/random_matrix.hpp\"\n\n#line 2 \"random/base.hpp\"\
    \n\nu64 RNG_64() {\n  static u64 x_ = u64(chrono::duration_cast<chrono::nanoseconds>(chrono::high_resolution_clock::now().time_since_epoch()).count())\
    \ * 10150724397891781847ULL;\n  x_ ^= x_ << 7;\n  return x_ ^= x_ >> 9;\n}\n\n\
    u64 RNG(u64 lim) { return RNG_64() % lim; }\n\nll RNG(ll l, ll r) { return l +\
    \ RNG_64() % (r - l); }\n#line 2 \"mod/barrett.hpp\"\n\n// https://github.com/atcoder/ac-library/blob/master/atcoder/internal_math.hpp\n\
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
    \  }\n\n  u64 mul(u64 a, u64 b) { return modulo(u128(a) * b); }\n};\n#line 2 \"\
    linalg/det.hpp\"\n\r\nint det_mod(vvc<int> A, int mod) {\r\n  Barrett bt(mod);\r\
    \n  const int n = len(A);\r\n  ll det = 1;\r\n  FOR(i, n) {\r\n    FOR(j, i, n)\
    \ {\r\n      if (A[j][i] == 0) continue;\r\n      if (i != j) { swap(A[i], A[j]),\
    \ det = mod - det; }\r\n      break;\r\n    }\r\n    FOR(j, i + 1, n) {\r\n  \
    \    while (A[i][i] != 0) {\r\n        ll c = mod - A[j][i] / A[i][i];\r\n   \
    \     FOR_R(k, i, n) { A[j][k] = bt.modulo(A[j][k] + A[i][k] * c); }\r\n     \
    \   swap(A[i], A[j]), det = mod - det;\r\n      }\r\n      swap(A[i], A[j]), det\
    \ = mod - det;\r\n    }\r\n  }\r\n  FOR(i, n) det = bt.mul(det, A[i][i]);\r\n\
    \  return det % mod;\r\n}\r\n\r\ntemplate <typename mint>\r\nmint det(vvc<mint>&\
    \ A) {\r\n  const int n = len(A);\r\n  vv(int, B, n, n);\r\n  FOR(i, n) FOR(j,\
    \ n) B[i][j] = A[i][j].val;\r\n  return det_mod(B, mint::get_mod());\r\n}\r\n\
    #line 2 \"mod/modint_common.hpp\"\n\nstruct has_mod_impl {\n  template <class\
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
    \  assert(n >= 0);\n    modint ret(1), mul(val);\n    while (n > 0) {\n      if\
    \ (n & 1) ret *= mul;\n      mul *= mul;\n      n >>= 1;\n    }\n    return ret;\n\
    \  }\n  static constexpr int get_mod() { return mod; }\n  // (n, r), r \u306F\
    \ 1 \u306E 2^n \u4E57\u6839\n  static constexpr pair<int, int> ntt_info() {\n\
    \    if (mod == 120586241) return {20, 74066978};\n    if (mod == 167772161) return\
    \ {25, 17};\n    if (mod == 469762049) return {26, 30};\n    if (mod == 754974721)\
    \ return {24, 362};\n    if (mod == 880803841) return {23, 211};\n    if (mod\
    \ == 943718401) return {22, 663003469};\n    if (mod == 998244353) return {23,\
    \ 31};\n    if (mod == 1004535809) return {21, 582313106};\n    if (mod == 1012924417)\
    \ return {21, 368093570};\n    return {-1, -1};\n  }\n  static constexpr bool\
    \ can_ntt() { return ntt_info().fi != -1; }\n};\n\n#ifdef FASTIO\ntemplate <int\
    \ mod>\nvoid rd(modint<mod> &x) {\n  fastio::rd(x.val);\n  x.val %= mod;\n  //\
    \ assert(0 <= x.val && x.val < mod);\n}\ntemplate <int mod>\nvoid wt(modint<mod>\
    \ x) {\n  fastio::wt(x.val);\n}\n#endif\n\nusing modint107 = modint<1000000007>;\n\
    using modint998 = modint<998244353>;\n#line 3 \"linalg/matrix_mul.hpp\"\n\r\n\
    template <class T, typename enable_if<has_mod<T>::value>::type* = nullptr>\r\n\
    vc<vc<T>> matrix_mul(const vc<vc<T>>& A, const vc<vc<T>>& B, int N1 = -1,\r\n\
    \                     int N2 = -1, int N3 = -1) {\r\n  if (N1 == -1) { N1 = len(A),\
    \ N2 = len(B), N3 = len(B[0]); }\r\n  vv(u32, b, N3, N2);\r\n  FOR(i, N2) FOR(j,\
    \ N3) b[j][i] = B[i][j].val;\r\n  vv(T, C, N1, N3);\r\n\r\n  if ((T::get_mod()\
    \ < (1 << 30)) && N2 <= 16) {\r\n    FOR(i, N1) FOR(j, N3) {\r\n      u64 sm =\
    \ 0;\r\n      FOR(m, N2) sm += u64(A[i][m].val) * b[j][m];\r\n      C[i][j] =\
    \ sm;\r\n    }\r\n  } else {\r\n    FOR(i, N1) FOR(j, N3) {\r\n      u128 sm =\
    \ 0;\r\n      FOR(m, N2) sm += u64(A[i][m].val) * b[j][m];\r\n      C[i][j] =\
    \ T::raw(sm % (T::get_mod()));\r\n    }\r\n  }\r\n  return C;\r\n}\r\n\r\ntemplate\
    \ <class T, typename enable_if<!has_mod<T>::value>::type* = nullptr>\r\nvc<vc<T>>\
    \ matrix_mul(const vc<vc<T>>& A, const vc<vc<T>>& B, int N1 = -1,\r\n        \
    \             int N2 = -1, int N3 = -1) {\r\n  if (N1 == -1) { N1 = len(A), N2\
    \ = len(B), N3 = len(B[0]); }\r\n  vv(T, b, N2, N3);\r\n  FOR(i, N2) FOR(j, N3)\
    \ b[j][i] = B[i][j];\r\n  vv(T, C, N1, N3);\r\n  FOR(n, N1) FOR(m, N2) FOR(k,\
    \ N3) C[n][k] += A[n][m] * b[k][m];\r\n  return C;\r\n}\r\n\r\n// square-matrix\
    \ defined as array\r\ntemplate <class T, int N,\r\n          typename enable_if<has_mod<T>::value>::type*\
    \ = nullptr>\r\narray<array<T, N>, N> matrix_mul(const array<array<T, N>, N>&\
    \ A,\r\n                                 const array<array<T, N>, N>& B) {\r\n\
    \  array<array<T, N>, N> C{};\r\n\r\n  if ((T::get_mod() < (1 << 30)) && N <=\
    \ 16) {\r\n    FOR(i, N) FOR(k, N) {\r\n      u64 sm = 0;\r\n      FOR(j, N) sm\
    \ += u64(A[i][j].val) * (B[j][k].val);\r\n      C[i][k] = sm;\r\n    }\r\n  }\
    \ else {\r\n    FOR(i, N) FOR(k, N) {\r\n      u128 sm = 0;\r\n      FOR(j, N)\
    \ sm += u64(A[i][j].val) * (B[j][k].val);\r\n      C[i][k] = sm;\r\n    }\r\n\
    \  }\r\n  return C;\r\n}\r\n\r\n// square-matrix defined as array\r\ntemplate\
    \ <class T, int N,\r\n          typename enable_if<!has_mod<T>::value>::type*\
    \ = nullptr>\r\narray<array<T, N>, N> matrix_mul(const array<array<T, N>, N>&\
    \ A,\r\n                                 const array<array<T, N>, N>& B) {\r\n\
    \  array<array<T, N>, N> C{};\r\n  FOR(i, N) FOR(j, N) FOR(k, N) C[i][k] += A[i][j]\
    \ * B[j][k];\r\n  return C;\r\n}\r\n#line 5 \"random/random_matrix.hpp\"\n\ntemplate\
    \ <typename mint>\nvvc<mint> random_matrix(int n, int m, int rk) {\n  if (n ==\
    \ m && m == rk) {\n    while (1) {\n      vv(mint, A, n, n);\n      FOR(i, n)\
    \ FOR(j, n) A[i][j] = RNG(0, mint::get_mod());\n      if (det(A) == mint(0)) continue;\n\
    \      return A;\n    }\n  }\n  vvc<mint> L = random_matrix<mint>(n, n, n);\n\
    \  vvc<mint> R = random_matrix<mint>(m, m, m);\n  vv(mint, A, n, m);\n  FOR(i,\
    \ rk) A[i][i] = 1;\n  A = matrix_mul<mint>(L, A, n, n, m);\n  A = matrix_mul<mint>(A,\
    \ R, n, m, m);\n  return A;\n}\n"
  code: "\n#include \"random/base.hpp\"\n#include \"linalg/det.hpp\"\n#include \"\
    linalg/matrix_mul.hpp\"\n\ntemplate <typename mint>\nvvc<mint> random_matrix(int\
    \ n, int m, int rk) {\n  if (n == m && m == rk) {\n    while (1) {\n      vv(mint,\
    \ A, n, n);\n      FOR(i, n) FOR(j, n) A[i][j] = RNG(0, mint::get_mod());\n  \
    \    if (det(A) == mint(0)) continue;\n      return A;\n    }\n  }\n  vvc<mint>\
    \ L = random_matrix<mint>(n, n, n);\n  vvc<mint> R = random_matrix<mint>(m, m,\
    \ m);\n  vv(mint, A, n, m);\n  FOR(i, rk) A[i][i] = 1;\n  A = matrix_mul<mint>(L,\
    \ A, n, n, m);\n  A = matrix_mul<mint>(A, R, n, m, m);\n  return A;\n}\n"
  dependsOn:
  - random/base.hpp
  - linalg/det.hpp
  - mod/barrett.hpp
  - linalg/matrix_mul.hpp
  - mod/modint.hpp
  - mod/modint_common.hpp
  isVerificationFile: false
  path: random/random_matrix.hpp
  requiredBy: []
  timestamp: '2024-10-25 01:17:46+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/1_mytest/blackbox_solve_linear.test.cpp
documentation_of: random/random_matrix.hpp
layout: document
redirect_from:
- /library/random/random_matrix.hpp
- /library/random/random_matrix.hpp.html
title: random/random_matrix.hpp
---
