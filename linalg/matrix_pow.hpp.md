---
data:
  _extendedDependsOn:
  - icon: ':question:'
    path: linalg/matrix_mul.hpp
    title: linalg/matrix_mul.hpp
  - icon: ':question:'
    path: mod/modint.hpp
    title: mod/modint.hpp
  - icon: ':question:'
    path: mod/modint_common.hpp
    title: mod/modint_common.hpp
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/2_library_checker/linear_algebra/pow_of_matrix.test.cpp
    title: test/2_library_checker/linear_algebra/pow_of_matrix.test.cpp
  - icon: ':x:'
    path: test/3_yukicoder/1750.test.cpp
    title: test/3_yukicoder/1750.test.cpp
  - icon: ':x:'
    path: test/3_yukicoder/1810.test.cpp
    title: test/3_yukicoder/1810.test.cpp
  - icon: ':x:'
    path: test/3_yukicoder/2810.test.cpp
    title: test/3_yukicoder/2810.test.cpp
  _isVerificationFailed: true
  _pathExtension: hpp
  _verificationStatusIcon: ':question:'
  attributes:
    links: []
  bundledCode: "#line 2 \"mod/modint_common.hpp\"\n\nstruct has_mod_impl {\n  template\
    \ <class T>\n  static auto check(T &&x) -> decltype(x.get_mod(), std::true_type{});\n\
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
    \ * B[j][k];\r\n  return C;\r\n}\r\n#line 2 \"linalg/matrix_pow.hpp\"\n\r\ntemplate\
    \ <typename T>\r\nvc<vc<T>> matrix_pow(vc<vc<T>> A, ll n) {\r\n  int N = len(A);\r\
    \n  vv(T, ret, N, N);\r\n  FOR(i, N) ret[i][i] = T(1);\r\n  while (n) {\r\n  \
    \  if (n & 1) ret = matrix_mul(ret, A, N, N, N);\r\n    n /= 2;\r\n    if (n)\
    \ A = matrix_mul(A, A, N, N, N);\r\n  }\r\n  return ret;\r\n}\r\n\r\ntemplate\
    \ <typename T, int N>\r\narray<array<T, N>, N> matrix_pow(array<array<T, N>, N>\
    \ A, ll n) {\r\n  array<array<T, N>, N> ret{};\r\n  FOR(i, N) ret[i][i] = T(1);\r\
    \n  while (n) {\r\n    if (n & 1) ret = matrix_mul<T, N>(ret, A);\r\n    n /=\
    \ 2;\r\n    if (n) A = matrix_mul<T, N>(A, A);\r\n  }\r\n  return ret;\r\n}\n"
  code: "#include \"linalg/matrix_mul.hpp\"\r\n\r\ntemplate <typename T>\r\nvc<vc<T>>\
    \ matrix_pow(vc<vc<T>> A, ll n) {\r\n  int N = len(A);\r\n  vv(T, ret, N, N);\r\
    \n  FOR(i, N) ret[i][i] = T(1);\r\n  while (n) {\r\n    if (n & 1) ret = matrix_mul(ret,\
    \ A, N, N, N);\r\n    n /= 2;\r\n    if (n) A = matrix_mul(A, A, N, N, N);\r\n\
    \  }\r\n  return ret;\r\n}\r\n\r\ntemplate <typename T, int N>\r\narray<array<T,\
    \ N>, N> matrix_pow(array<array<T, N>, N> A, ll n) {\r\n  array<array<T, N>, N>\
    \ ret{};\r\n  FOR(i, N) ret[i][i] = T(1);\r\n  while (n) {\r\n    if (n & 1) ret\
    \ = matrix_mul<T, N>(ret, A);\r\n    n /= 2;\r\n    if (n) A = matrix_mul<T, N>(A,\
    \ A);\r\n  }\r\n  return ret;\r\n}"
  dependsOn:
  - linalg/matrix_mul.hpp
  - mod/modint.hpp
  - mod/modint_common.hpp
  isVerificationFile: false
  path: linalg/matrix_pow.hpp
  requiredBy: []
  timestamp: '2024-11-14 21:00:22+09:00'
  verificationStatus: LIBRARY_SOME_WA
  verifiedWith:
  - test/3_yukicoder/2810.test.cpp
  - test/3_yukicoder/1750.test.cpp
  - test/3_yukicoder/1810.test.cpp
  - test/2_library_checker/linear_algebra/pow_of_matrix.test.cpp
documentation_of: linalg/matrix_pow.hpp
layout: document
redirect_from:
- /library/linalg/matrix_pow.hpp
- /library/linalg/matrix_pow.hpp.html
title: linalg/matrix_pow.hpp
---
