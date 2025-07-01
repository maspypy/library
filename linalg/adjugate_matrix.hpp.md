---
data:
  _extendedDependsOn:
  - icon: ':x:'
    path: linalg/basis.hpp
    title: linalg/basis.hpp
  - icon: ':x:'
    path: linalg/characteristic_poly.hpp
    title: linalg/characteristic_poly.hpp
  - icon: ':x:'
    path: linalg/frobenius.hpp
    title: linalg/frobenius.hpp
  - icon: ':x:'
    path: linalg/matrix_inv.hpp
    title: linalg/matrix_inv.hpp
  - icon: ':question:'
    path: linalg/matrix_mul.hpp
    title: linalg/matrix_mul.hpp
  - icon: ':question:'
    path: mod/crt3.hpp
    title: mod/crt3.hpp
  - icon: ':question:'
    path: mod/mod_inv.hpp
    title: mod/mod_inv.hpp
  - icon: ':question:'
    path: mod/modint.hpp
    title: mod/modint.hpp
  - icon: ':question:'
    path: mod/modint_common.hpp
    title: mod/modint_common.hpp
  - icon: ':question:'
    path: poly/convolution.hpp
    title: poly/convolution.hpp
  - icon: ':question:'
    path: poly/convolution_all.hpp
    title: poly/convolution_all.hpp
  - icon: ':question:'
    path: poly/convolution_karatsuba.hpp
    title: poly/convolution_karatsuba.hpp
  - icon: ':question:'
    path: poly/convolution_naive.hpp
    title: poly/convolution_naive.hpp
  - icon: ':question:'
    path: poly/ntt.hpp
    title: poly/ntt.hpp
  - icon: ':question:'
    path: poly/ntt_doubling.hpp
    title: poly/ntt_doubling.hpp
  - icon: ':question:'
    path: random/base.hpp
    title: random/base.hpp
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':x:'
    path: test/2_library_checker/linear_algebra/adjugate_matrix.test.cpp
    title: test/2_library_checker/linear_algebra/adjugate_matrix.test.cpp
  _isVerificationFailed: true
  _pathExtension: hpp
  _verificationStatusIcon: ':x:'
  attributes:
    links: []
  bundledCode: "#line 1 \"linalg/adjugate_matrix.hpp\"\n\n#line 2 \"random/base.hpp\"\
    \n\nu64 RNG_64() {\n  static u64 x_ = u64(chrono::duration_cast<chrono::nanoseconds>(chrono::high_resolution_clock::now().time_since_epoch()).count())\
    \ * 10150724397891781847ULL;\n  x_ ^= x_ << 7;\n  return x_ ^= x_ >> 9;\n}\n\n\
    u64 RNG(u64 lim) { return RNG_64() % lim; }\n\nll RNG(ll l, ll r) { return l +\
    \ RNG_64() % (r - l); }\n#line 2 \"linalg/matrix_inv.hpp\"\n\r\n// (det, invA)\
    \ \u3092\u304B\u3048\u3059\r\ntemplate <typename T>\r\npair<T, vc<vc<T>>> matrix_inv(vc<vc<T>>\
    \ A) {\r\n  T det = 1;\r\n  int N = len(A);\r\n  vv(T, B, N, N);\r\n  FOR(n, N)\
    \ B[n][n] = 1;\r\n  FOR(i, N) {\r\n    FOR(k, i, N) if (A[k][i] != 0) {\r\n  \
    \    if (k != i) {\r\n        swap(A[i], A[k]), swap(B[i], B[k]);\r\n        det\
    \ = -det;\r\n      }\r\n      break;\r\n    }\r\n    if (A[i][i] == 0) return\
    \ {T(0), {}};\r\n    T c = T(1) / A[i][i];\r\n    det *= A[i][i];\r\n    FOR(j,\
    \ i, N) A[i][j] *= c;\r\n    FOR(j, N) B[i][j] *= c;\r\n    FOR(k, N) if (i !=\
    \ k) {\r\n      T c = A[k][i];\r\n      FOR(j, i, N) A[k][j] -= A[i][j] * c;\r\
    \n      FOR(j, N) B[k][j] -= B[i][j] * c;\r\n    }\r\n  }\r\n  return {det, B};\r\
    \n}\r\n#line 2 \"mod/modint_common.hpp\"\n\nstruct has_mod_impl {\n  template\
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
    \  if (n < 0) return inverse().pow(-n);\n    assert(n >= 0);\n    modint ret(1),\
    \ mul(val);\n    while (n > 0) {\n      if (n & 1) ret *= mul;\n      mul *= mul;\n\
    \      n >>= 1;\n    }\n    return ret;\n  }\n  static constexpr int get_mod()\
    \ { return mod; }\n  // (n, r), r \u306F 1 \u306E 2^n \u4E57\u6839\n  static constexpr\
    \ pair<int, int> ntt_info() {\n    if (mod == 120586241) return {20, 74066978};\n\
    \    if (mod == 167772161) return {25, 17};\n    if (mod == 469762049) return\
    \ {26, 30};\n    if (mod == 754974721) return {24, 362};\n    if (mod == 880803841)\
    \ return {23, 211};\n    if (mod == 943718401) return {22, 663003469};\n    if\
    \ (mod == 998244353) return {23, 31};\n    if (mod == 1004535809) return {21,\
    \ 582313106};\n    if (mod == 1012924417) return {21, 368093570};\n    return\
    \ {-1, -1};\n  }\n  static constexpr bool can_ntt() { return ntt_info().fi !=\
    \ -1; }\n};\n\n#ifdef FASTIO\ntemplate <int mod>\nvoid rd(modint<mod> &x) {\n\
    \  fastio::rd(x.val);\n  x.val %= mod;\n  // assert(0 <= x.val && x.val < mod);\n\
    }\ntemplate <int mod>\nvoid wt(modint<mod> x) {\n  fastio::wt(x.val);\n}\n#endif\n\
    \nusing modint107 = modint<1000000007>;\nusing modint998 = modint<998244353>;\n\
    #line 3 \"linalg/matrix_mul.hpp\"\n\r\ntemplate <class T, typename enable_if<has_mod<T>::value>::type*\
    \ = nullptr>\r\nvc<vc<T>> matrix_mul(const vc<vc<T>>& A, const vc<vc<T>>& B, int\
    \ N1 = -1,\r\n                     int N2 = -1, int N3 = -1) {\r\n  if (N1 ==\
    \ -1) { N1 = len(A), N2 = len(B), N3 = len(B[0]); }\r\n  vv(u32, b, N3, N2);\r\
    \n  FOR(i, N2) FOR(j, N3) b[j][i] = B[i][j].val;\r\n  vv(T, C, N1, N3);\r\n\r\n\
    \  if ((T::get_mod() < (1 << 30)) && N2 <= 16) {\r\n    FOR(i, N1) FOR(j, N3)\
    \ {\r\n      u64 sm = 0;\r\n      FOR(m, N2) sm += u64(A[i][m].val) * b[j][m];\r\
    \n      C[i][j] = sm;\r\n    }\r\n  } else {\r\n    FOR(i, N1) FOR(j, N3) {\r\n\
    \      u128 sm = 0;\r\n      FOR(m, N2) sm += u64(A[i][m].val) * b[j][m];\r\n\
    \      C[i][j] = T::raw(sm % (T::get_mod()));\r\n    }\r\n  }\r\n  return C;\r\
    \n}\r\n\r\ntemplate <class T, typename enable_if<!has_mod<T>::value>::type* =\
    \ nullptr>\r\nvc<vc<T>> matrix_mul(const vc<vc<T>>& A, const vc<vc<T>>& B, int\
    \ N1 = -1,\r\n                     int N2 = -1, int N3 = -1) {\r\n  if (N1 ==\
    \ -1) { N1 = len(A), N2 = len(B), N3 = len(B[0]); }\r\n  vv(T, b, N2, N3);\r\n\
    \  FOR(i, N2) FOR(j, N3) b[j][i] = B[i][j];\r\n  vv(T, C, N1, N3);\r\n  FOR(n,\
    \ N1) FOR(m, N2) FOR(k, N3) C[n][k] += A[n][m] * b[k][m];\r\n  return C;\r\n}\r\
    \n\r\n// square-matrix defined as array\r\ntemplate <class T, int N,\r\n     \
    \     typename enable_if<has_mod<T>::value>::type* = nullptr>\r\narray<array<T,\
    \ N>, N> matrix_mul(const array<array<T, N>, N>& A,\r\n                      \
    \           const array<array<T, N>, N>& B) {\r\n  array<array<T, N>, N> C{};\r\
    \n\r\n  if ((T::get_mod() < (1 << 30)) && N <= 16) {\r\n    FOR(i, N) FOR(k, N)\
    \ {\r\n      u64 sm = 0;\r\n      FOR(j, N) sm += u64(A[i][j].val) * (B[j][k].val);\r\
    \n      C[i][k] = sm;\r\n    }\r\n  } else {\r\n    FOR(i, N) FOR(k, N) {\r\n\
    \      u128 sm = 0;\r\n      FOR(j, N) sm += u64(A[i][j].val) * (B[j][k].val);\r\
    \n      C[i][k] = sm;\r\n    }\r\n  }\r\n  return C;\r\n}\r\n\r\n// square-matrix\
    \ defined as array\r\ntemplate <class T, int N,\r\n          typename enable_if<!has_mod<T>::value>::type*\
    \ = nullptr>\r\narray<array<T, N>, N> matrix_mul(const array<array<T, N>, N>&\
    \ A,\r\n                                 const array<array<T, N>, N>& B) {\r\n\
    \  array<array<T, N>, N> C{};\r\n  FOR(i, N) FOR(j, N) FOR(k, N) C[i][k] += A[i][j]\
    \ * B[j][k];\r\n  return C;\r\n}\r\n#line 2 \"mod/mod_inv.hpp\"\n\r\n// long \u3067\
    \u3082\u5927\u4E08\u592B\r\n// (val * x - 1) \u304C mod \u306E\u500D\u6570\u306B\
    \u306A\u308B\u3088\u3046\u306B\u3059\u308B\r\n// \u7279\u306B mod=0 \u306A\u3089\
    \ x=0 \u304C\u6E80\u305F\u3059\r\nll mod_inv(ll val, ll mod) {\r\n  if (mod ==\
    \ 0) return 0;\r\n  mod = abs(mod);\r\n  val %= mod;\r\n  if (val < 0) val +=\
    \ mod;\r\n  ll a = val, b = mod, u = 1, v = 0, t;\r\n  while (b > 0) {\r\n   \
    \ t = a / b;\r\n    swap(a -= t * b, b), swap(u -= t * v, v);\r\n  }\r\n  if (u\
    \ < 0) u += mod;\r\n  return u;\r\n}\r\n#line 2 \"mod/crt3.hpp\"\n\nconstexpr\
    \ u32 mod_pow_constexpr(u64 a, u64 n, u32 mod) {\n  a %= mod;\n  u64 res = 1;\n\
    \  FOR(32) {\n    if (n & 1) res = res * a % mod;\n    a = a * a % mod, n /= 2;\n\
    \  }\n  return res;\n}\n\ntemplate <typename T, u32 p0, u32 p1>\nT CRT2(u64 a0,\
    \ u64 a1) {\n  static_assert(p0 < p1);\n  static constexpr u64 x0_1 = mod_pow_constexpr(p0,\
    \ p1 - 2, p1);\n  u64 c = (a1 - a0 + p1) * x0_1 % p1;\n  return a0 + c * p0;\n\
    }\n\ntemplate <typename T, u32 p0, u32 p1, u32 p2>\nT CRT3(u64 a0, u64 a1, u64\
    \ a2) {\n  static_assert(p0 < p1 && p1 < p2);\n  static constexpr u64 x1 = mod_pow_constexpr(p0,\
    \ p1 - 2, p1);\n  static constexpr u64 x2 = mod_pow_constexpr(u64(p0) * p1 % p2,\
    \ p2 - 2, p2);\n  static constexpr u64 p01 = u64(p0) * p1;\n  u64 c = (a1 - a0\
    \ + p1) * x1 % p1;\n  u64 ans_1 = a0 + c * p0;\n  c = (a2 - ans_1 % p2 + p2) *\
    \ x2 % p2;\n  return T(ans_1) + T(c) * T(p01);\n}\n\ntemplate <typename T, u32\
    \ p0, u32 p1, u32 p2, u32 p3>\nT CRT4(u64 a0, u64 a1, u64 a2, u64 a3) {\n  static_assert(p0\
    \ < p1 && p1 < p2 && p2 < p3);\n  static constexpr u64 x1 = mod_pow_constexpr(p0,\
    \ p1 - 2, p1);\n  static constexpr u64 x2 = mod_pow_constexpr(u64(p0) * p1 % p2,\
    \ p2 - 2, p2);\n  static constexpr u64 x3 = mod_pow_constexpr(u64(p0) * p1 % p3\
    \ * p2 % p3, p3 - 2, p3);\n  static constexpr u64 p01 = u64(p0) * p1;\n  u64 c\
    \ = (a1 - a0 + p1) * x1 % p1;\n  u64 ans_1 = a0 + c * p0;\n  c = (a2 - ans_1 %\
    \ p2 + p2) * x2 % p2;\n  u128 ans_2 = ans_1 + c * static_cast<u128>(p01);\n  c\
    \ = (a3 - ans_2 % p3 + p3) * x3 % p3;\n  return T(ans_2) + T(c) * T(p01) * T(p2);\n\
    }\n\ntemplate <typename T, u32 p0, u32 p1, u32 p2, u32 p3, u32 p4>\nT CRT5(u64\
    \ a0, u64 a1, u64 a2, u64 a3, u64 a4) {\n  static_assert(p0 < p1 && p1 < p2 &&\
    \ p2 < p3 && p3 < p4);\n  static constexpr u64 x1 = mod_pow_constexpr(p0, p1 -\
    \ 2, p1);\n  static constexpr u64 x2 = mod_pow_constexpr(u64(p0) * p1 % p2, p2\
    \ - 2, p2);\n  static constexpr u64 x3 = mod_pow_constexpr(u64(p0) * p1 % p3 *\
    \ p2 % p3, p3 - 2, p3);\n  static constexpr u64 x4 = mod_pow_constexpr(u64(p0)\
    \ * p1 % p4 * p2 % p4 * p3 % p4, p4 - 2, p4);\n  static constexpr u64 p01 = u64(p0)\
    \ * p1;\n  static constexpr u64 p23 = u64(p2) * p3;\n  u64 c = (a1 - a0 + p1)\
    \ * x1 % p1;\n  u64 ans_1 = a0 + c * p0;\n  c = (a2 - ans_1 % p2 + p2) * x2 %\
    \ p2;\n  u128 ans_2 = ans_1 + c * static_cast<u128>(p01);\n  c = static_cast<u64>(a3\
    \ - ans_2 % p3 + p3) * x3 % p3;\n  u128 ans_3 = ans_2 + static_cast<u128>(c *\
    \ p2) * p01;\n  c = static_cast<u64>(a4 - ans_3 % p4 + p4) * x4 % p4;\n  return\
    \ T(ans_3) + T(c) * T(p01) * T(p23);\n}\n#line 2 \"poly/convolution_naive.hpp\"\
    \n\r\ntemplate <class T, typename enable_if<!has_mod<T>::value>::type* = nullptr>\r\
    \nvc<T> convolution_naive(const vc<T>& a, const vc<T>& b) {\r\n  int n = int(a.size()),\
    \ m = int(b.size());\r\n  if (n > m) return convolution_naive<T>(b, a);\r\n  if\
    \ (n == 0) return {};\r\n  vector<T> ans(n + m - 1);\r\n  FOR(i, n) FOR(j, m)\
    \ ans[i + j] += a[i] * b[j];\r\n  return ans;\r\n}\r\n\r\ntemplate <class T, typename\
    \ enable_if<has_mod<T>::value>::type* = nullptr>\r\nvc<T> convolution_naive(const\
    \ vc<T>& a, const vc<T>& b) {\r\n  int n = int(a.size()), m = int(b.size());\r\
    \n  if (n > m) return convolution_naive<T>(b, a);\r\n  if (n == 0) return {};\r\
    \n  vc<T> ans(n + m - 1);\r\n  if (n <= 16 && (T::get_mod() < (1 << 30))) {\r\n\
    \    for (int k = 0; k < n + m - 1; ++k) {\r\n      int s = max(0, k - m + 1);\r\
    \n      int t = min(n, k + 1);\r\n      u64 sm = 0;\r\n      for (int i = s; i\
    \ < t; ++i) { sm += u64(a[i].val) * (b[k - i].val); }\r\n      ans[k] = sm;\r\n\
    \    }\r\n  } else {\r\n    for (int k = 0; k < n + m - 1; ++k) {\r\n      int\
    \ s = max(0, k - m + 1);\r\n      int t = min(n, k + 1);\r\n      u128 sm = 0;\r\
    \n      for (int i = s; i < t; ++i) { sm += u64(a[i].val) * (b[k - i].val); }\r\
    \n      ans[k] = T::raw(sm % T::get_mod());\r\n    }\r\n  }\r\n  return ans;\r\
    \n}\r\n#line 2 \"poly/convolution_karatsuba.hpp\"\n\n// \u4EFB\u610F\u306E\u74B0\
    \u3067\u3067\u304D\u308B\ntemplate <typename T>\nvc<T> convolution_karatsuba(const\
    \ vc<T>& f, const vc<T>& g) {\n  const int thresh = 30;\n  if (min(len(f), len(g))\
    \ <= thresh) return convolution_naive(f, g);\n  int n = max(len(f), len(g));\n\
    \  int m = ceil(n, 2);\n  vc<T> f1, f2, g1, g2;\n  if (len(f) < m) f1 = f;\n \
    \ if (len(f) >= m) f1 = {f.begin(), f.begin() + m};\n  if (len(f) >= m) f2 = {f.begin()\
    \ + m, f.end()};\n  if (len(g) < m) g1 = g;\n  if (len(g) >= m) g1 = {g.begin(),\
    \ g.begin() + m};\n  if (len(g) >= m) g2 = {g.begin() + m, g.end()};\n  vc<T>\
    \ a = convolution_karatsuba(f1, g1);\n  vc<T> b = convolution_karatsuba(f2, g2);\n\
    \  FOR(i, len(f2)) f1[i] += f2[i];\n  FOR(i, len(g2)) g1[i] += g2[i];\n  vc<T>\
    \ c = convolution_karatsuba(f1, g1);\n  vc<T> F(len(f) + len(g) - 1);\n  assert(2\
    \ * m + len(b) <= len(F));\n  FOR(i, len(a)) F[i] += a[i], c[i] -= a[i];\n  FOR(i,\
    \ len(b)) F[2 * m + i] += b[i], c[i] -= b[i];\n  if (c.back() == T(0)) c.pop_back();\n\
    \  FOR(i, len(c)) if (c[i] != T(0)) F[m + i] += c[i];\n  return F;\n}\n#line 2\
    \ \"poly/ntt.hpp\"\n\r\ntemplate <class mint>\r\nvoid ntt(vector<mint>& a, bool\
    \ inverse) {\r\n  assert(mint::can_ntt());\r\n  const int rank2 = mint::ntt_info().fi;\r\
    \n  const int mod = mint::get_mod();\r\n  static array<mint, 30> root, iroot;\r\
    \n  static array<mint, 30> rate2, irate2;\r\n  static array<mint, 30> rate3, irate3;\r\
    \n\r\n  assert(rank2 != -1 && len(a) <= (1 << max(0, rank2)));\r\n\r\n  static\
    \ bool prepared = 0;\r\n  if (!prepared) {\r\n    prepared = 1;\r\n    root[rank2]\
    \ = mint::ntt_info().se;\r\n    iroot[rank2] = mint(1) / root[rank2];\r\n    FOR_R(i,\
    \ rank2) {\r\n      root[i] = root[i + 1] * root[i + 1];\r\n      iroot[i] = iroot[i\
    \ + 1] * iroot[i + 1];\r\n    }\r\n    mint prod = 1, iprod = 1;\r\n    for (int\
    \ i = 0; i <= rank2 - 2; i++) {\r\n      rate2[i] = root[i + 2] * prod;\r\n  \
    \    irate2[i] = iroot[i + 2] * iprod;\r\n      prod *= iroot[i + 2];\r\n    \
    \  iprod *= root[i + 2];\r\n    }\r\n    prod = 1, iprod = 1;\r\n    for (int\
    \ i = 0; i <= rank2 - 3; i++) {\r\n      rate3[i] = root[i + 3] * prod;\r\n  \
    \    irate3[i] = iroot[i + 3] * iprod;\r\n      prod *= iroot[i + 3];\r\n    \
    \  iprod *= root[i + 3];\r\n    }\r\n  }\r\n\r\n  int n = int(a.size());\r\n \
    \ int h = topbit(n);\r\n  assert(n == 1 << h);\r\n  if (!inverse) {\r\n    int\
    \ len = 0;\r\n    while (len < h) {\r\n      if (h - len == 1) {\r\n        int\
    \ p = 1 << (h - len - 1);\r\n        mint rot = 1;\r\n        FOR(s, 1 << len)\
    \ {\r\n          int offset = s << (h - len);\r\n          FOR(i, p) {\r\n   \
    \         auto l = a[i + offset];\r\n            auto r = a[i + offset + p] *\
    \ rot;\r\n            a[i + offset] = l + r;\r\n            a[i + offset + p]\
    \ = l - r;\r\n          }\r\n          rot *= rate2[topbit(~s & -~s)];\r\n   \
    \     }\r\n        len++;\r\n      } else {\r\n        int p = 1 << (h - len -\
    \ 2);\r\n        mint rot = 1, imag = root[2];\r\n        for (int s = 0; s <\
    \ (1 << len); s++) {\r\n          mint rot2 = rot * rot;\r\n          mint rot3\
    \ = rot2 * rot;\r\n          int offset = s << (h - len);\r\n          for (int\
    \ i = 0; i < p; i++) {\r\n            u64 mod2 = u64(mod) * mod;\r\n         \
    \   u64 a0 = a[i + offset].val;\r\n            u64 a1 = u64(a[i + offset + p].val)\
    \ * rot.val;\r\n            u64 a2 = u64(a[i + offset + 2 * p].val) * rot2.val;\r\
    \n            u64 a3 = u64(a[i + offset + 3 * p].val) * rot3.val;\r\n        \
    \    u64 a1na3imag = (a1 + mod2 - a3) % mod * imag.val;\r\n            u64 na2\
    \ = mod2 - a2;\r\n            a[i + offset] = a0 + a2 + a1 + a3;\r\n         \
    \   a[i + offset + 1 * p] = a0 + a2 + (2 * mod2 - (a1 + a3));\r\n            a[i\
    \ + offset + 2 * p] = a0 + na2 + a1na3imag;\r\n            a[i + offset + 3 *\
    \ p] = a0 + na2 + (mod2 - a1na3imag);\r\n          }\r\n          rot *= rate3[topbit(~s\
    \ & -~s)];\r\n        }\r\n        len += 2;\r\n      }\r\n    }\r\n  } else {\r\
    \n    mint coef = mint(1) / mint(len(a));\r\n    FOR(i, len(a)) a[i] *= coef;\r\
    \n    int len = h;\r\n    while (len) {\r\n      if (len == 1) {\r\n        int\
    \ p = 1 << (h - len);\r\n        mint irot = 1;\r\n        FOR(s, 1 << (len -\
    \ 1)) {\r\n          int offset = s << (h - len + 1);\r\n          FOR(i, p) {\r\
    \n            u64 l = a[i + offset].val;\r\n            u64 r = a[i + offset +\
    \ p].val;\r\n            a[i + offset] = l + r;\r\n            a[i + offset +\
    \ p] = (mod + l - r) * irot.val;\r\n          }\r\n          irot *= irate2[topbit(~s\
    \ & -~s)];\r\n        }\r\n        len--;\r\n      } else {\r\n        int p =\
    \ 1 << (h - len);\r\n        mint irot = 1, iimag = iroot[2];\r\n        FOR(s,\
    \ (1 << (len - 2))) {\r\n          mint irot2 = irot * irot;\r\n          mint\
    \ irot3 = irot2 * irot;\r\n          int offset = s << (h - len + 2);\r\n    \
    \      for (int i = 0; i < p; i++) {\r\n            u64 a0 = a[i + offset + 0\
    \ * p].val;\r\n            u64 a1 = a[i + offset + 1 * p].val;\r\n           \
    \ u64 a2 = a[i + offset + 2 * p].val;\r\n            u64 a3 = a[i + offset + 3\
    \ * p].val;\r\n            u64 x = (mod + a2 - a3) * iimag.val % mod;\r\n    \
    \        a[i + offset] = a0 + a1 + a2 + a3;\r\n            a[i + offset + 1 *\
    \ p] = (a0 + mod - a1 + x) * irot.val;\r\n            a[i + offset + 2 * p] =\
    \ (a0 + a1 + 2 * mod - a2 - a3) * irot2.val;\r\n            a[i + offset + 3 *\
    \ p] = (a0 + 2 * mod - a1 - x) * irot3.val;\r\n          }\r\n          irot *=\
    \ irate3[topbit(~s & -~s)];\r\n        }\r\n        len -= 2;\r\n      }\r\n \
    \   }\r\n  }\r\n}\r\n#line 8 \"poly/convolution.hpp\"\n\r\ntemplate <class mint>\r\
    \nvector<mint> convolution_ntt(vector<mint> a, vector<mint> b) {\r\n  if (a.empty()\
    \ || b.empty()) return {};\r\n  int n = int(a.size()), m = int(b.size());\r\n\
    \  int sz = 1;\r\n  while (sz < n + m - 1) sz *= 2;\r\n\r\n  // sz = 2^k \u306E\
    \u3068\u304D\u306E\u9AD8\u901F\u5316\u3002\u5206\u5272\u7D71\u6CBB\u7684\u306A\
    \u3084\u3064\u3067\u640D\u3057\u307E\u304F\u308B\u306E\u3067\u3002\r\n  if ((n\
    \ + m - 3) <= sz / 2) {\r\n    auto a_last = a.back(), b_last = b.back();\r\n\
    \    a.pop_back(), b.pop_back();\r\n    auto c = convolution(a, b);\r\n    c.resize(n\
    \ + m - 1);\r\n    c[n + m - 2] = a_last * b_last;\r\n    FOR(i, len(a)) c[i +\
    \ len(b)] += a[i] * b_last;\r\n    FOR(i, len(b)) c[i + len(a)] += b[i] * a_last;\r\
    \n    return c;\r\n  }\r\n\r\n  a.resize(sz), b.resize(sz);\r\n  bool same = a\
    \ == b;\r\n  ntt(a, 0);\r\n  if (same) {\r\n    b = a;\r\n  } else {\r\n    ntt(b,\
    \ 0);\r\n  }\r\n  FOR(i, sz) a[i] *= b[i];\r\n  ntt(a, 1);\r\n  a.resize(n + m\
    \ - 1);\r\n  return a;\r\n}\r\n\r\ntemplate <typename mint>\r\nvector<mint> convolution_garner(const\
    \ vector<mint>& a, const vector<mint>& b) {\r\n  int n = len(a), m = len(b);\r\
    \n  if (!n || !m) return {};\r\n  static constexpr int p0 = 167772161;\r\n  static\
    \ constexpr int p1 = 469762049;\r\n  static constexpr int p2 = 754974721;\r\n\
    \  using mint0 = modint<p0>;\r\n  using mint1 = modint<p1>;\r\n  using mint2 =\
    \ modint<p2>;\r\n  vc<mint0> a0(n), b0(m);\r\n  vc<mint1> a1(n), b1(m);\r\n  vc<mint2>\
    \ a2(n), b2(m);\r\n  FOR(i, n) a0[i] = a[i].val, a1[i] = a[i].val, a2[i] = a[i].val;\r\
    \n  FOR(i, m) b0[i] = b[i].val, b1[i] = b[i].val, b2[i] = b[i].val;\r\n  auto\
    \ c0 = convolution_ntt<mint0>(a0, b0);\r\n  auto c1 = convolution_ntt<mint1>(a1,\
    \ b1);\r\n  auto c2 = convolution_ntt<mint2>(a2, b2);\r\n  vc<mint> c(len(c0));\r\
    \n  FOR(i, n + m - 1) { c[i] = CRT3<mint, p0, p1, p2>(c0[i].val, c1[i].val, c2[i].val);\
    \ }\r\n  return c;\r\n}\r\n\r\nvector<ll> convolution(vector<ll> a, vector<ll>\
    \ b) {\r\n  int n = len(a), m = len(b);\r\n  if (!n || !m) return {};\r\n  if\
    \ (min(n, m) <= 2500) return convolution_naive(a, b);\r\n\r\n  ll mi_a = MIN(a),\
    \ mi_b = MIN(b);\r\n  for (auto& x: a) x -= mi_a;\r\n  for (auto& x: b) x -= mi_b;\r\
    \n  assert(MAX(a) * MAX(b) <= 1e18);\r\n\r\n  auto Ac = cumsum<ll>(a), Bc = cumsum<ll>(b);\r\
    \n  vi res(n + m - 1);\r\n  for (int k = 0; k < n + m - 1; ++k) {\r\n    int s\
    \ = max(0, k - m + 1);\r\n    int t = min(n, k + 1);\r\n    res[k] += (t - s)\
    \ * mi_a * mi_b;\r\n    res[k] += mi_a * (Bc[k - s + 1] - Bc[k - t + 1]);\r\n\
    \    res[k] += mi_b * (Ac[t] - Ac[s]);\r\n  }\r\n\r\n  static constexpr u32 MOD1\
    \ = 1004535809;\r\n  static constexpr u32 MOD2 = 1012924417;\r\n  using mint1\
    \ = modint<MOD1>;\r\n  using mint2 = modint<MOD2>;\r\n\r\n  vc<mint1> a1(n), b1(m);\r\
    \n  vc<mint2> a2(n), b2(m);\r\n  FOR(i, n) a1[i] = a[i], a2[i] = a[i];\r\n  FOR(i,\
    \ m) b1[i] = b[i], b2[i] = b[i];\r\n\r\n  auto c1 = convolution_ntt<mint1>(a1,\
    \ b1);\r\n  auto c2 = convolution_ntt<mint2>(a2, b2);\r\n\r\n  FOR(i, n + m -\
    \ 1) { res[i] += CRT2<u64, MOD1, MOD2>(c1[i].val, c2[i].val); }\r\n  return res;\r\
    \n}\r\n\r\ntemplate <typename mint>\r\nvc<mint> convolution(const vc<mint>& a,\
    \ const vc<mint>& b) {\r\n  int n = len(a), m = len(b);\r\n  if (!n || !m) return\
    \ {};\r\n  if (mint::can_ntt()) {\r\n    if (min(n, m) <= 50) return convolution_karatsuba<mint>(a,\
    \ b);\r\n    return convolution_ntt(a, b);\r\n  }\r\n  if (min(n, m) <= 200) return\
    \ convolution_karatsuba<mint>(a, b);\r\n  return convolution_garner(a, b);\r\n\
    }\r\n#line 2 \"linalg/basis.hpp\"\n\n// basis[i]: i \u756A\u76EE\u306B\u8FFD\u52A0\
    \u6210\u529F\u3057\u305F\u3082\u306E. \u5225\u306E\u30E9\u30D9\u30EB\u304C\u3042\
    \u308B\u306A\u3089\u5916\u3067\u7BA1\u7406\u3059\u308B.\n// rbasis: \u4E0A\u4E09\
    \u89D2\u5316\u3055\u308C\u305F\u57FA\u5E95. [i][i]==1.\n// way[i][j]: rbasis[i]\
    \ = sum way[i][j] basis[j]\ntemplate <typename mint>\nstruct Basis {\n  int n,\
    \ rank;\n  vvc<mint> basis;\n  vvc<mint> rbasis;\n  vvc<mint> way;\n  Basis(int\
    \ max_dim) : n(max_dim), rank(0), basis{} {\n    rbasis.assign(max_dim, vc<mint>(max_dim));\n\
    \    way.assign(max_dim, vc<mint>(max_dim));\n  }\n\n  // return : (sum==X \u306B\
    \u3067\u304D\u308B\u304B, \u305D\u306E\u65B9\u6CD5)\n  pair<bool, vc<mint>> solve(vc<mint>\
    \ X) {\n    vc<mint> CF(n);\n    FOR(i, n) {\n      if (rbasis[i][i] == mint(1))\
    \ {\n        CF[i] = X[i];\n        FOR(j, i, n) X[j] -= CF[i] * rbasis[i][j];\n\
    \      }\n    }\n    for (auto& x: X) {\n      if (x != mint(0)) { return {false,\
    \ {}}; }\n    }\n    vc<mint> ANS(rank);\n    FOR(i, n) { FOR(j, rank) ANS[j]\
    \ += CF[i] * way[i][j]; }\n    return {true, ANS};\n  }\n\n  // return : (sum==x\
    \ \u306B\u3067\u304D\u308B\u304B, \u305D\u306E\u65B9\u6CD5). false \u306E\u5834\
    \u5408\u306B\u306F\u8FFD\u52A0\u3059\u308B\n  pair<bool, vc<mint>> solve_or_add(vc<mint>\
    \ X) {\n    vc<mint> Y = X;\n    vc<mint> CF(n);\n    FOR(i, n) {\n      if (rbasis[i][i]\
    \ == mint(1)) {\n        CF[i] = X[i];\n        FOR(j, i, n) X[j] -= CF[i] * rbasis[i][j];\n\
    \      }\n    }\n    int p = [&]() -> int {\n      FOR(i, n) if (X[i] != mint(0))\
    \ return i;\n      return -1;\n    }();\n    if (p == -1) {\n      vc<mint> ANS(rank);\n\
    \      FOR(i, n) { FOR(j, rank) ANS[j] += CF[i] * way[i][j]; }\n      return {true,\
    \ ANS};\n    }\n    mint c = X[p].inverse();\n    FOR(j, p, n) X[j] *= c;\n  \
    \  FOR(i, n) CF[i] *= c;\n    basis.eb(Y), rbasis[p] = X;\n    way[p][rank] =\
    \ c;\n    FOR(i, n) { FOR(j, rank) way[p][j] -= CF[i] * way[i][j]; }\n    ++rank;\n\
    \    return {false, {}};\n  }\n\n  // rank==r \u306E\u6642\u70B9\u307E\u3067\u623B\
    \u3059. Frobenius Form \u7528.\n  void rollback(int r) {\n    while (rank > r)\
    \ {\n      --rank;\n      POP(basis);\n      FOR(i, n) if (way[i][rank] != mint(0))\
    \ {\n        fill(all(rbasis[i]), mint(0));\n        fill(all(way[i]), mint(0));\n\
    \      }\n    }\n  }\n};\n#line 2 \"poly/convolution_all.hpp\"\n\r\n#line 2 \"\
    poly/ntt_doubling.hpp\"\n\n#line 4 \"poly/ntt_doubling.hpp\"\n\n// 2^k \u6B21\u591A\
    \u9805\u5F0F\u306E\u9577\u3055 2^k \u304C\u4E0E\u3048\u3089\u308C\u308B\u306E\u3067\
    \ 2^k+1 \u306B\u3059\u308B\ntemplate <typename mint, bool transposed = false>\n\
    void ntt_doubling(vector<mint>& a) {\n  static array<mint, 30> root;\n  static\
    \ bool prepared = 0;\n  if (!prepared) {\n    prepared = 1;\n    const int rank2\
    \ = mint::ntt_info().fi;\n    root[rank2] = mint::ntt_info().se;\n    FOR_R(i,\
    \ rank2) { root[i] = root[i + 1] * root[i + 1]; }\n  }\n\n  if constexpr (!transposed)\
    \ {\n    const int M = (int)a.size();\n    auto b = a;\n    ntt(b, 1);\n    mint\
    \ r = 1, zeta = root[topbit(2 * M)];\n    FOR(i, M) b[i] *= r, r *= zeta;\n  \
    \  ntt(b, 0);\n    copy(begin(b), end(b), back_inserter(a));\n  } else {\n   \
    \ const int M = len(a) / 2;\n    vc<mint> tmp = {a.begin(), a.begin() + M};\n\
    \    a = {a.begin() + M, a.end()};\n    transposed_ntt(a, 0);\n    mint r = 1,\
    \ zeta = root[topbit(2 * M)];\n    FOR(i, M) a[i] *= r, r *= zeta;\n    transposed_ntt(a,\
    \ 1);\n    FOR(i, M) a[i] += tmp[i];\n  }\n}\n#line 5 \"poly/convolution_all.hpp\"\
    \n\r\ntemplate <typename T>\r\nvc<T> convolution_all(vc<vc<T>>& polys) {\r\n \
    \ if (len(polys) == 0) return {T(1)};\r\n  while (1) {\r\n    int n = len(polys);\r\
    \n    if (n == 1) break;\r\n    int m = ceil(n, 2);\r\n    FOR(i, m) {\r\n   \
    \   if (2 * i + 1 == n) {\r\n        polys[i] = polys[2 * i];\r\n      } else\
    \ {\r\n        polys[i] = convolution(polys[2 * i], polys[2 * i + 1]);\r\n   \
    \   }\r\n    }\r\n    polys.resize(m);\r\n  }\r\n  return polys[0];\r\n}\r\n\r\
    \n// product of 1-A[i]x\r\ntemplate <typename mint>\r\nvc<mint> convolution_all_1(vc<mint>\
    \ A) {\r\n  if (!mint::can_ntt()) {\r\n    vvc<mint> polys;\r\n    for (auto&\
    \ a: A) polys.eb(vc<mint>({mint(1), -a}));\r\n    return convolution_all(polys);\r\
    \n  }\r\n  int D = 6;\r\n  using poly = vc<mint>;\r\n  int n = 1;\r\n  while (n\
    \ < len(A)) n *= 2;\r\n  int k = topbit(n);\r\n  vc<mint> F(n), nxt_F(n);\r\n\
    \  FOR(i, len(A)) F[i] = -A[i];\r\n  FOR(d, k) {\r\n    int b = 1 << d;\r\n  \
    \  if (d < D) {\r\n      fill(all(nxt_F), mint(0));\r\n      for (int L = 0; L\
    \ < n; L += 2 * b) {\r\n        FOR(i, b) FOR(j, b) { nxt_F[L + i + j] += F[L\
    \ + i] * F[L + b + j]; }\r\n        FOR(i, b) nxt_F[L + b + i] += F[L + i] + F[L\
    \ + b + i];\r\n      }\r\n    }\r\n    elif (d == D) {\r\n      for (int L = 0;\
    \ L < n; L += 2 * b) {\r\n        poly f1 = {F.begin() + L, F.begin() + L + b};\r\
    \n        poly f2 = {F.begin() + L + b, F.begin() + L + 2 * b};\r\n        f1.resize(2\
    \ * b), f2.resize(2 * b), ntt(f1, 0), ntt(f2, 0);\r\n        FOR(i, b) nxt_F[L\
    \ + i] = f1[i] * f2[i] + f1[i] + f2[i];\r\n        FOR(i, b, 2 * b) nxt_F[L +\
    \ i] = f1[i] * f2[i] - f1[i] - f2[i];\r\n      }\r\n    }\r\n    else {\r\n  \
    \    for (int L = 0; L < n; L += 2 * b) {\r\n        poly f1 = {F.begin() + L,\
    \ F.begin() + L + b};\r\n        poly f2 = {F.begin() + L + b, F.begin() + L +\
    \ 2 * b};\r\n        ntt_doubling(f1), ntt_doubling(f2);\r\n        FOR(i, b)\
    \ nxt_F[L + i] = f1[i] * f2[i] + f1[i] + f2[i];\r\n        FOR(i, b, 2 * b) nxt_F[L\
    \ + i] = f1[i] * f2[i] - f1[i] - f2[i];\r\n      }\r\n    }\r\n    swap(F, nxt_F);\r\
    \n  }\r\n  if (k - 1 >= D) ntt(F, 1);\r\n  F.eb(1), reverse(all(F));\r\n  F.resize(len(A)\
    \ + 1);\r\n  return F;\r\n}\n#line 8 \"linalg/frobenius.hpp\"\n\n// https://codeforces.com/blog/entry/124815\n\
    // P^{-1}AP = diag(companion(f0),companion(f1),...)\n// without checking: ...|f2|f1|f0.\n\
    // time complexity O(N^3). failure prob O(N/mod).\ntemplate <typename mint>\n\
    struct Frobenius_Form {\n  int n; // b : num of blocks\n  const vvc<mint> A;\n\
    \  vvc<mint> P, IP;\n  vvc<mint> V;\n  vvc<mint> F; // [-a0,-a1,...,-a[k-1]] \u306E\
    \u5F62\u3067\u7BA1\u7406 (x^k \u3068\u5408\u540C\u306A\u3082\u306E)\n\n  Frobenius_Form(vvc<mint>&\
    \ A) : n(len(A)), A(A) {\n    while (!trial()) {}\n  }\n\n  // N^3 + N^2log(exp)\n\
    \  vvc<mint> pow(ll exp) {\n    vv(mint, X, n, n);\n    int s = 0;\n    FOR(k,\
    \ len(F)) {\n      int d = len(F[k]);\n      vc<mint> f = powmod(F[k], exp);\n\
    \      FOR(j, d) {\n        FOR(i, len(f)) { X[s + i][s + j] = f[i]; }\n     \
    \   if (j == d - 1) break;\n        f.insert(f.begin(), 0);\n        divmod_inplace(f,\
    \ F[k]);\n      }\n      s += d;\n    }\n    X = matrix_mul(P, X);\n    X = matrix_mul(X,\
    \ IP);\n    return X;\n  }\n\n  // p(A)\n  vvc<mint> poly_eval(vc<mint>& p) {\n\
    \    vv(mint, X, n, n);\n    int s = 0;\n    FOR(k, len(F)) {\n      int d = len(F[k]);\n\
    \      vc<mint> f = p;\n      divmod_inplace(f, F[k]);\n      FOR(j, d) {\n  \
    \      FOR(i, len(f)) { X[s + i][s + j] = f[i]; }\n        if (j == d - 1) break;\n\
    \        f.insert(f.begin(), 0);\n        divmod_inplace(f, F[k]);\n      }\n\
    \      s += d;\n    }\n    X = matrix_mul(P, X);\n    X = matrix_mul(X, IP);\n\
    \    return X;\n  }\n\n  vc<mint> characteristic_poly() {\n    vvc<mint> polys;\n\
    \    for (auto& f: F) {\n      vc<mint> g = f;\n      for (auto& x: g) x = -x;\n\
    \      g.eb(1);\n      polys.eb(g);\n    }\n    vc<mint> f = convolution_all(polys);\n\
    \    return f;\n  }\n\n  // x^n mod (x^d-g(x))\n  vc<mint> powmod(vc<mint>& g,\
    \ ll n) {\n    if (n < len(g)) {\n      vc<mint> f(n + 1);\n      f[n] = 1;\n\
    \      return f;\n    }\n    vc<mint> f = powmod(g, n / 2);\n    f = convolution_naive(f,\
    \ f);\n    if (n & 1) f.insert(f.begin(), 0);\n    divmod_inplace(f, g);\n   \
    \ return f;\n  }\n\nprivate:\n  bool trial() {\n    V.clear(), F.clear();\n  \
    \  Basis<mint> S(n);\n    while (1) {\n      if (S.rank == n) break;\n      int\
    \ r = S.rank;\n      vc<mint> v = random_vector();\n      V.eb(v);\n      while\
    \ (1) {\n        auto [solved, cf] = S.solve_or_add(v);\n        if (!solved)\
    \ {\n          v = apply(v);\n          continue;\n        }\n        vc<mint>\
    \ f = {cf.begin() + r, cf.end()};\n        F.eb(f);\n        if (len(V) == 1)\
    \ break;\n        v = V.back();\n        int s = 0;\n        FOR(k, len(V) - 1)\
    \ {\n          int d = len(F[k]);\n          vc<mint> R = {cf.begin() + s, cf.begin()\
    \ + s + d};\n          vc<mint> q = divmod_inplace(R, f);\n          if (!R.empty())\
    \ {\n            return false; // failure\n          }\n          FOR(i, len(q))\
    \ { FOR(j, n) v[j] -= q[i] * S.basis[s + i][j]; }\n          s += d;\n       \
    \ }\n        S.rollback(r);\n        V.back() = v;\n        FOR(i, len(f)) {\n\
    \          S.solve_or_add(v);\n          if (i + 1 < len(f)) v = apply(v);\n \
    \       }\n        break;\n      }\n    }\n    P.assign(n, vc<mint>(n));\n   \
    \ FOR(i, n) FOR(j, n) P[i][j] = S.basis[j][i];\n    IP = matrix_inv<mint>(P).se;\n\
    \    return true;\n  }\n\n  vc<mint> random_vector() {\n    vc<mint> v(n);\n \
    \   FOR(i, n) v[i] = RNG(0, mint::get_mod());\n    return v;\n  }\n\n  vc<mint>\
    \ apply(vc<mint> v) {\n    vc<mint> w(n);\n    FOR(i, n) FOR(j, n) w[i] += A[i][j]\
    \ * v[j];\n    return w;\n  }\n\n  // f mod= (x^d-g(x)) (inplace), return : q\n\
    \  vc<mint> divmod_inplace(vc<mint>& f, vc<mint>& g) {\n    while (len(f) && f.back()\
    \ == mint(0)) POP(f);\n    int d = len(g);\n    vc<mint> q;\n    FOR_R(i, d, len(f))\
    \ {\n      q.eb(f[i]);\n      FOR(j, len(g)) f[i - d + j] += f[i] * g[j];\n  \
    \    f[i] = 0;\n    }\n    while (len(f) && f.back() == mint(0)) POP(f);\n   \
    \ reverse(all(q));\n    return q;\n  }\n};\n#line 1 \"linalg/characteristic_poly.hpp\"\
    \ntemplate <typename T>\r\nvoid to_Hessenberg_matrix(vc<vc<T>>& A) {\r\n  /*\r\
    \n  P^{-1}AP \u306E\u5F62\u306E\u5909\u63DB\u3067\u3001Hessenberg \u884C\u5217\
    \u306B\u5909\u5F62\u3059\u308B\u3002\r\n  \u7279\u5B9A\u591A\u9805\u5F0F\u306E\
    \u8A08\u7B97\u306B\u7528\u3044\u308B\u3053\u3068\u304C\u3067\u304D\u308B\u3002\
    \r\n  */\r\n  int n = len(A);\r\n  FOR(k, n - 2) {\r\n    FOR3(i, k + 1, n) if\
    \ (A[i][k] != 0) {\r\n      if (i != k + 1) {\r\n        swap(A[i], A[k + 1]);\r\
    \n        FOR(j, n) swap(A[j][i], A[j][k + 1]);\r\n      }\r\n      break;\r\n\
    \    }\r\n    if (A[k + 1][k] == 0) continue;\r\n    FOR3(i, k + 2, n) {\r\n \
    \     T c = A[i][k] / A[k + 1][k];\r\n      // i \u884C\u76EE -= k+1 \u884C\u76EE\
    \ * c\r\n      FOR(j, n) A[i][j] -= A[k + 1][j] * c;\r\n      // k+1 \u5217\u76EE\
    \ += i \u5217\u76EE * c\r\n      FOR(j, n) A[j][k + 1] += A[j][i] * c;\r\n   \
    \ }\r\n  }\r\n}\r\n\r\n// det(xI-A)\r\ntemplate <typename T>\r\nvc<T> characteristic_poly(vc<vc<T>>\
    \ A) {\r\n  /*\r\n  \u30FBHessenberg \u884C\u5217\u306B\u5909\u5F62\r\n  \u30FB\
    Hessenberg \u884C\u5217\u306E\u884C\u5217\u5F0F\u306F\u3001\u6700\u5F8C\u306E\u5217\
    \u3067\u5834\u5408\u5206\u3051\u3059\u308C\u3070 dp \u3067\u304D\u308B\r\n  */\r\
    \n  int n = len(A);\r\n  to_Hessenberg_matrix(A);\r\n  vc<vc<T>> DP(n + 1);\r\n\
    \  DP[0] = {1};\r\n  FOR(k, n) {\r\n    DP[k + 1].resize(k + 2);\r\n    auto&\
    \ dp = DP[k + 1];\r\n    // (k, k) \u6210\u5206\u3092\u4F7F\u3046\u5834\u5408\r\
    \n    FOR(i, len(DP[k])) dp[i + 1] += DP[k][i];\r\n    FOR(i, len(DP[k])) dp[i]\
    \ -= DP[k][i] * A[k][k];\r\n    // \u4E0B\u5074\u5BFE\u89D2\u306E\u7DCF\u7A4D\u3092\
    \u7BA1\u7406\r\n    T prod = 1;\r\n    FOR_R(i, k) {\r\n      // (i, k) \u6210\
    \u5206\u3092\u4F7F\u3046\u5834\u5408\r\n      prod *= A[i + 1][i];\r\n      T\
    \ c = prod * A[i][k];\r\n      // DP[i] \u306E c \u500D\u3092\u52A0\u7B97\r\n\
    \      FOR(j, len(DP[i])) dp[j] -= DP[i][j] * c;\r\n    }\r\n  }\r\n  return DP[n];\r\
    \n}\r\n#line 6 \"linalg/adjugate_matrix.hpp\"\n\ntemplate <typename mint>\nvvc<mint>\
    \ adjugate_matrix(vvc<mint> A) {\n  int N = len(A);\n  Frobenius_Form<mint> X(A);\n\
    \  auto F = X.characteristic_poly();\n  if (N % 2 == 0) {\n    for (auto& x: F)\
    \ x = -x;\n  }\n  F.erase(F.begin());\n  return X.poly_eval(F);\n}\n"
  code: "\n#include \"linalg/frobenius.hpp\"\n#include \"mod/modint.hpp\"\n#include\
    \ \"linalg/characteristic_poly.hpp\"\n#include \"linalg/frobenius.hpp\"\n\ntemplate\
    \ <typename mint>\nvvc<mint> adjugate_matrix(vvc<mint> A) {\n  int N = len(A);\n\
    \  Frobenius_Form<mint> X(A);\n  auto F = X.characteristic_poly();\n  if (N %\
    \ 2 == 0) {\n    for (auto& x: F) x = -x;\n  }\n  F.erase(F.begin());\n  return\
    \ X.poly_eval(F);\n}"
  dependsOn:
  - linalg/frobenius.hpp
  - random/base.hpp
  - linalg/matrix_inv.hpp
  - linalg/matrix_mul.hpp
  - mod/modint.hpp
  - mod/modint_common.hpp
  - poly/convolution.hpp
  - mod/mod_inv.hpp
  - mod/crt3.hpp
  - poly/convolution_naive.hpp
  - poly/convolution_karatsuba.hpp
  - poly/ntt.hpp
  - linalg/basis.hpp
  - poly/convolution_all.hpp
  - poly/ntt_doubling.hpp
  - linalg/characteristic_poly.hpp
  isVerificationFile: false
  path: linalg/adjugate_matrix.hpp
  requiredBy: []
  timestamp: '2025-02-12 05:55:32+09:00'
  verificationStatus: LIBRARY_ALL_WA
  verifiedWith:
  - test/2_library_checker/linear_algebra/adjugate_matrix.test.cpp
documentation_of: linalg/adjugate_matrix.hpp
layout: document
redirect_from:
- /library/linalg/adjugate_matrix.hpp
- /library/linalg/adjugate_matrix.hpp.html
title: linalg/adjugate_matrix.hpp
---
