---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: mod/all_inverse.hpp
    title: mod/all_inverse.hpp
  - icon: ':heavy_check_mark:'
    path: mod/crt3.hpp
    title: mod/crt3.hpp
  - icon: ':heavy_check_mark:'
    path: mod/mod_inv.hpp
    title: mod/mod_inv.hpp
  - icon: ':heavy_check_mark:'
    path: mod/modint.hpp
    title: mod/modint.hpp
  - icon: ':heavy_check_mark:'
    path: mod/modint_common.hpp
    title: mod/modint_common.hpp
  - icon: ':heavy_check_mark:'
    path: mod/powertable.hpp
    title: mod/powertable.hpp
  - icon: ':heavy_check_mark:'
    path: nt/primetable.hpp
    title: nt/primetable.hpp
  - icon: ':heavy_check_mark:'
    path: poly/convolution.hpp
    title: poly/convolution.hpp
  - icon: ':heavy_check_mark:'
    path: poly/convolution_karatsuba.hpp
    title: poly/convolution_karatsuba.hpp
  - icon: ':heavy_check_mark:'
    path: poly/convolution_naive.hpp
    title: poly/convolution_naive.hpp
  - icon: ':heavy_check_mark:'
    path: poly/count_terms.hpp
    title: poly/count_terms.hpp
  - icon: ':heavy_check_mark:'
    path: poly/differentiate.hpp
    title: poly/differentiate.hpp
  - icon: ':heavy_check_mark:'
    path: poly/fps_div.hpp
    title: poly/fps_div.hpp
  - icon: ':heavy_check_mark:'
    path: poly/fps_exp.hpp
    title: poly/fps_exp.hpp
  - icon: ':heavy_check_mark:'
    path: poly/fps_inv.hpp
    title: poly/fps_inv.hpp
  - icon: ':heavy_check_mark:'
    path: poly/fps_log.hpp
    title: poly/fps_log.hpp
  - icon: ':heavy_check_mark:'
    path: poly/fps_pow.hpp
    title: poly/fps_pow.hpp
  - icon: ':heavy_check_mark:'
    path: poly/integrate.hpp
    title: poly/integrate.hpp
  - icon: ':heavy_check_mark:'
    path: poly/middle_product.hpp
    title: poly/middle_product.hpp
  - icon: ':heavy_check_mark:'
    path: poly/multipoint.hpp
    title: poly/multipoint.hpp
  - icon: ':heavy_check_mark:'
    path: poly/ntt.hpp
    title: poly/ntt.hpp
  - icon: ':heavy_check_mark:'
    path: poly/ntt_doubling.hpp
    title: poly/ntt_doubling.hpp
  - icon: ':heavy_check_mark:'
    path: poly/partial_frac_decomposition_1.hpp
    title: poly/partial_frac_decomposition_1.hpp
  - icon: ':heavy_check_mark:'
    path: poly/poly_taylor_shift.hpp
    title: poly/poly_taylor_shift.hpp
  - icon: ':heavy_check_mark:'
    path: poly/transposed_ntt.hpp
    title: poly/transposed_ntt.hpp
  - icon: ':heavy_check_mark:'
    path: seq/famous/stirling_number_1.hpp
    title: seq/famous/stirling_number_1.hpp
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/1_mytest/composition_log_1_minus_x.test.cpp
    title: test/1_mytest/composition_log_1_minus_x.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 1 \"poly/composition_f_log_1_minus_x.hpp\"\n\n#line 2 \"poly/poly_taylor_shift.hpp\"\
    \n\r\n#line 2 \"nt/primetable.hpp\"\n\ntemplate <typename T = int>\nvc<T> primetable(int\
    \ LIM) {\n  ++LIM;\n  const int S = 32768;\n  static int done = 2;\n  static vc<T>\
    \ primes = {2}, sieve(S + 1);\n\n  if (done < LIM) {\n    done = LIM;\n\n    primes\
    \ = {2}, sieve.assign(S + 1, 0);\n    const int R = LIM / 2;\n    primes.reserve(int(LIM\
    \ / log(LIM) * 1.1));\n    vc<pair<int, int>> cp;\n    for (int i = 3; i <= S;\
    \ i += 2) {\n      if (!sieve[i]) {\n        cp.eb(i, i * i / 2);\n        for\
    \ (int j = i * i; j <= S; j += 2 * i) sieve[j] = 1;\n      }\n    }\n    for (int\
    \ L = 1; L <= R; L += S) {\n      array<bool, S> block{};\n      for (auto& [p,\
    \ idx]: cp)\n        for (int i = idx; i < S + L; idx = (i += p)) block[i - L]\
    \ = 1;\n      FOR(i, min(S, R - L)) if (!block[i]) primes.eb((L + i) * 2 + 1);\n\
    \    }\n  }\n  int k = LB(primes, LIM + 1);\n  return {primes.begin(), primes.begin()\
    \ + k};\n}\n#line 3 \"mod/powertable.hpp\"\n\r\n// a^0, ..., a^N\r\ntemplate <typename\
    \ mint>\r\nvc<mint> powertable_1(mint a, ll N) {\r\n  // table of a^i\r\n  vc<mint>\
    \ f(N + 1, 1);\r\n  FOR(i, N) f[i + 1] = a * f[i];\r\n  return f;\r\n}\r\n\r\n\
    // 0^e, ..., N^e\r\ntemplate <typename mint>\r\nvc<mint> powertable_2(ll e, ll\
    \ N) {\r\n  auto primes = primetable(N);\r\n  vc<mint> f(N + 1, 1);\r\n  f[0]\
    \ = mint(0).pow(e);\r\n  for (auto&& p: primes) {\r\n    if (p > N) break;\r\n\
    \    mint xp = mint(p).pow(e);\r\n    ll pp = p;\r\n    while (pp <= N) {\r\n\
    \      ll i = pp;\r\n      while (i <= N) {\r\n        f[i] *= xp;\r\n       \
    \ i += pp;\r\n      }\r\n      pp *= p;\r\n    }\r\n  }\r\n  return f;\r\n}\r\n\
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
    using modint998 = modint<998244353>;\n#line 2 \"mod/mod_inv.hpp\"\n\r\n// long\
    \ \u3067\u3082\u5927\u4E08\u592B\r\n// (val * x - 1) \u304C mod \u306E\u500D\u6570\
    \u306B\u306A\u308B\u3088\u3046\u306B\u3059\u308B\r\n// \u7279\u306B mod=0 \u306A\
    \u3089 x=0 \u304C\u6E80\u305F\u3059\r\nll mod_inv(ll val, ll mod) {\r\n  if (mod\
    \ == 0) return 0;\r\n  mod = abs(mod);\r\n  val %= mod;\r\n  if (val < 0) val\
    \ += mod;\r\n  ll a = val, b = mod, u = 1, v = 0, t;\r\n  while (b > 0) {\r\n\
    \    t = a / b;\r\n    swap(a -= t * b, b), swap(u -= t * v, v);\r\n  }\r\n  if\
    \ (u < 0) u += mod;\r\n  return u;\r\n}\r\n#line 2 \"mod/crt3.hpp\"\n\nconstexpr\
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
    }\r\n#line 5 \"poly/poly_taylor_shift.hpp\"\n\r\n// f(x) -> f(x+c)\r\ntemplate\
    \ <typename mint>\r\nvc<mint> poly_taylor_shift(vc<mint> f, mint c) {\r\n  if\
    \ (c == mint(0)) return f;\r\n  ll N = len(f);\r\n  FOR(i, N) f[i] *= fact<mint>(i);\r\
    \n  auto b = powertable_1<mint>(c, N);\r\n  FOR(i, N) b[i] *= fact_inv<mint>(i);\r\
    \n  reverse(all(f));\r\n  f = convolution(f, b);\r\n  f.resize(N);\r\n  reverse(all(f));\r\
    \n  FOR(i, N) f[i] *= fact_inv<mint>(i);\r\n  return f;\r\n}\r\n#line 2 \"poly/multipoint.hpp\"\
    \n\r\n#line 2 \"poly/middle_product.hpp\"\n\n#line 6 \"poly/middle_product.hpp\"\
    \n\n// n, m \u6B21\u591A\u9805\u5F0F (n>=m) a, b \u2192 n-m \u6B21\u591A\u9805\
    \u5F0F c\n// c[i] = sum_j b[j]a[i+j]\ntemplate <typename mint>\nvc<mint> middle_product(vc<mint>&\
    \ a, vc<mint>& b) {\n  assert(len(a) >= len(b));\n  if (b.empty()) return vc<mint>(len(a)\
    \ - len(b) + 1);\n  if (min(len(b), len(a) - len(b) + 1) <= 60) {\n    return\
    \ middle_product_naive(a, b);\n  }\n  if (!(mint::can_ntt())) {\n    return middle_product_garner(a,\
    \ b);\n  } else {\n    int n = 1 << __lg(2 * len(a) - 1);\n    vc<mint> fa(n),\
    \ fb(n);\n    copy(a.begin(), a.end(), fa.begin());\n    copy(b.rbegin(), b.rend(),\
    \ fb.begin());\n    ntt(fa, 0), ntt(fb, 0);\n    FOR(i, n) fa[i] *= fb[i];\n \
    \   ntt(fa, 1);\n    fa.resize(len(a));\n    fa.erase(fa.begin(), fa.begin() +\
    \ len(b) - 1);\n    return fa;\n  }\n}\n\ntemplate <typename mint>\nvc<mint> middle_product_garner(vc<mint>&\
    \ a, vc<mint> b) {\n  int n = len(a), m = len(b);\n  if (!n || !m) return {};\n\
    \  static constexpr int p0 = 167772161;\n  static constexpr int p1 = 469762049;\n\
    \  static constexpr int p2 = 754974721;\n  using mint0 = modint<p0>;\n  using\
    \ mint1 = modint<p1>;\n  using mint2 = modint<p2>;\n  vc<mint0> a0(n), b0(m);\n\
    \  vc<mint1> a1(n), b1(m);\n  vc<mint2> a2(n), b2(m);\n  FOR(i, n) a0[i] = a[i].val,\
    \ a1[i] = a[i].val, a2[i] = a[i].val;\n  FOR(i, m) b0[i] = b[i].val, b1[i] = b[i].val,\
    \ b2[i] = b[i].val;\n  auto c0 = middle_product<mint0>(a0, b0);\n  auto c1 = middle_product<mint1>(a1,\
    \ b1);\n  auto c2 = middle_product<mint2>(a2, b2);\n  vc<mint> c(len(c0));\n \
    \ FOR(i, n - m + 1) {\n    c[i] = CRT3<mint, p0, p1, p2>(c0[i].val, c1[i].val,\
    \ c2[i].val);\n  }\n  return c;\n}\n\ntemplate <typename mint>\nvc<mint> middle_product_naive(vc<mint>&\
    \ a, vc<mint>& b) {\n  vc<mint> res(len(a) - len(b) + 1);\n  FOR(i, len(res))\
    \ FOR(j, len(b)) res[i] += b[j] * a[i + j];\n  return res;\n}\n#line 2 \"mod/all_inverse.hpp\"\
    \ntemplate <typename mint>\nvc<mint> all_inverse(vc<mint>& X) {\n  for (auto&&\
    \ x: X) assert(x != mint(0));\n  int N = len(X);\n  vc<mint> res(N + 1);\n  res[0]\
    \ = mint(1);\n  FOR(i, N) res[i + 1] = res[i] * X[i];\n  mint t = res.back().inverse();\n\
    \  res.pop_back();\n  FOR_R(i, N) {\n    res[i] *= t;\n    t *= X[i];\n  }\n \
    \ return res;\n}\n#line 2 \"poly/fps_div.hpp\"\n\n#line 2 \"poly/count_terms.hpp\"\
    \ntemplate<typename mint>\r\nint count_terms(const vc<mint>& f){\r\n  int t =\
    \ 0;\r\n  FOR(i, len(f)) if(f[i] != mint(0)) ++t;\r\n  return t;\r\n}\n#line 4\
    \ \"poly/fps_inv.hpp\"\n\r\ntemplate <typename mint>\r\nvc<mint> fps_inv_sparse(const\
    \ vc<mint>& f) {\r\n  int N = len(f);\r\n  vc<pair<int, mint>> dat;\r\n  FOR(i,\
    \ 1, N) if (f[i] != mint(0)) dat.eb(i, f[i]);\r\n  vc<mint> g(N);\r\n  mint g0\
    \ = mint(1) / f[0];\r\n  g[0] = g0;\r\n  FOR(n, 1, N) {\r\n    mint rhs = 0;\r\
    \n    for (auto&& [k, fk]: dat) {\r\n      if (k > n) break;\r\n      rhs -= fk\
    \ * g[n - k];\r\n    }\r\n    g[n] = rhs * g0;\r\n  }\r\n  return g;\r\n}\r\n\r\
    \ntemplate <typename mint>\r\nvc<mint> fps_inv_dense_ntt(const vc<mint>& F) {\r\
    \n  vc<mint> G = {mint(1) / F[0]};\r\n  ll N = len(F), n = 1;\r\n  G.reserve(N);\r\
    \n  while (n < N) {\r\n    vc<mint> f(2 * n), g(2 * n);\r\n    FOR(i, min(N, 2\
    \ * n)) f[i] = F[i];\r\n    FOR(i, n) g[i] = G[i];\r\n    ntt(f, false), ntt(g,\
    \ false);\r\n    FOR(i, 2 * n) f[i] *= g[i];\r\n    ntt(f, true);\r\n    FOR(i,\
    \ n) f[i] = 0;\r\n    ntt(f, false);\r\n    FOR(i, 2 * n) f[i] *= g[i];\r\n  \
    \  ntt(f, true);\r\n    FOR(i, n, min(N, 2 * n)) G.eb(-f[i]);\r\n    n *= 2;\r\
    \n  }\r\n  return G;\r\n}\r\n\r\ntemplate <typename mint>\r\nvc<mint> fps_inv_dense(const\
    \ vc<mint>& F) {\r\n  if (mint::can_ntt()) return fps_inv_dense_ntt(F);\r\n  const\
    \ int N = len(F);\r\n  vc<mint> R = {mint(1) / F[0]};\r\n  vc<mint> p;\r\n  int\
    \ m = 1;\r\n  while (m < N) {\r\n    p = convolution(R, R);\r\n    p.resize(m\
    \ + m);\r\n    vc<mint> f = {F.begin(), F.begin() + min(m + m, N)};\r\n    p =\
    \ convolution(p, f);\r\n    R.resize(m + m);\r\n    FOR(i, m + m) R[i] = R[i]\
    \ + R[i] - p[i];\r\n    m += m;\r\n  }\r\n  R.resize(N);\r\n  return R;\r\n}\r\
    \n\r\ntemplate <typename mint>\r\nvc<mint> fps_inv(const vc<mint>& f) {\r\n  assert(f[0]\
    \ != mint(0));\r\n  int n = count_terms(f);\r\n  int t = (mint::can_ntt() ? 160\
    \ : 820);\r\n  return (n <= t ? fps_inv_sparse<mint>(f) : fps_inv_dense<mint>(f));\r\
    \n}\r\n#line 5 \"poly/fps_div.hpp\"\n\n// f/g. f \u306E\u9577\u3055\u3067\u51FA\
    \u529B\u3055\u308C\u308B.\ntemplate <typename mint, bool SPARSE = false>\nvc<mint>\
    \ fps_div(vc<mint> f, vc<mint> g) {\n  if (SPARSE || count_terms(g) < 200) return\
    \ fps_div_sparse(f, g);\n  int n = len(f);\n  g.resize(n);\n  g = fps_inv<mint>(g);\n\
    \  f = convolution(f, g);\n  f.resize(n);\n  return f;\n}\n\n// f/g \u305F\u3060\
    \u3057 g \u306F sparse\ntemplate <typename mint>\nvc<mint> fps_div_sparse(vc<mint>\
    \ f, vc<mint>& g) {\n  if (g[0] != mint(1)) {\n    mint cf = g[0].inverse();\n\
    \    for (auto&& x: f) x *= cf;\n    for (auto&& x: g) x *= cf;\n  }\n\n  vc<pair<int,\
    \ mint>> dat;\n  FOR(i, 1, len(g)) if (g[i] != mint(0)) dat.eb(i, -g[i]);\n  FOR(i,\
    \ len(f)) {\n    for (auto&& [j, x]: dat) {\n      if (i >= j) f[i] += x * f[i\
    \ - j];\n    }\n  }\n  return f;\n}\n#line 2 \"poly/ntt_doubling.hpp\"\n\n#line\
    \ 4 \"poly/ntt_doubling.hpp\"\n\n// 2^k \u6B21\u591A\u9805\u5F0F\u306E\u9577\u3055\
    \ 2^k \u304C\u4E0E\u3048\u3089\u308C\u308B\u306E\u3067 2^k+1 \u306B\u3059\u308B\
    \ntemplate <typename mint, bool transposed = false>\nvoid ntt_doubling(vector<mint>&\
    \ a) {\n  static array<mint, 30> root;\n  static bool prepared = 0;\n  if (!prepared)\
    \ {\n    prepared = 1;\n    const int rank2 = mint::ntt_info().fi;\n    root[rank2]\
    \ = mint::ntt_info().se;\n    FOR_R(i, rank2) { root[i] = root[i + 1] * root[i\
    \ + 1]; }\n  }\n\n  if constexpr (!transposed) {\n    const int M = (int)a.size();\n\
    \    auto b = a;\n    ntt(b, 1);\n    mint r = 1, zeta = root[topbit(2 * M)];\n\
    \    FOR(i, M) b[i] *= r, r *= zeta;\n    ntt(b, 0);\n    copy(begin(b), end(b),\
    \ back_inserter(a));\n  } else {\n    const int M = len(a) / 2;\n    vc<mint>\
    \ tmp = {a.begin(), a.begin() + M};\n    a = {a.begin() + M, a.end()};\n    transposed_ntt(a,\
    \ 0);\n    mint r = 1, zeta = root[topbit(2 * M)];\n    FOR(i, M) a[i] *= r, r\
    \ *= zeta;\n    transposed_ntt(a, 1);\n    FOR(i, M) a[i] += tmp[i];\n  }\n}\n\
    #line 2 \"poly/transposed_ntt.hpp\"\n\ntemplate <class mint>\nvoid transposed_ntt(vector<mint>&\
    \ a, bool inverse) {\n  assert(mint::can_ntt());\n  const int rank2 = mint::ntt_info().fi;\n\
    \  const int mod = mint::get_mod();\n  static array<mint, 30> root, iroot;\n \
    \ static array<mint, 30> rate2, irate2;\n  static array<mint, 30> rate3, irate3;\n\
    \n  assert(rank2 != -1 && len(a) <= (1 << max(0, rank2)));\n\n  static bool prepared\
    \ = 0;\n  if (!prepared) {\n    prepared = 1;\n    root[rank2] = mint::ntt_info().se;\n\
    \    iroot[rank2] = mint(1) / root[rank2];\n    FOR_R(i, rank2) {\n      root[i]\
    \ = root[i + 1] * root[i + 1];\n      iroot[i] = iroot[i + 1] * iroot[i + 1];\n\
    \    }\n    mint prod = 1, iprod = 1;\n    for (int i = 0; i <= rank2 - 2; i++)\
    \ {\n      rate2[i] = root[i + 2] * prod;\n      irate2[i] = iroot[i + 2] * iprod;\n\
    \      prod *= iroot[i + 2];\n      iprod *= root[i + 2];\n    }\n    prod = 1,\
    \ iprod = 1;\n    for (int i = 0; i <= rank2 - 3; i++) {\n      rate3[i] = root[i\
    \ + 3] * prod;\n      irate3[i] = iroot[i + 3] * iprod;\n      prod *= iroot[i\
    \ + 3];\n      iprod *= root[i + 3];\n    }\n  }\n\n  int n = int(a.size());\n\
    \  int h = topbit(n);\n  assert(n == 1 << h);\n  if (!inverse) {\n    int len\
    \ = h;\n    while (len > 0) {\n      if (len == 1) {\n        int p = 1 << (h\
    \ - len);\n        mint rot = 1;\n        FOR(s, 1 << (len - 1)) {\n         \
    \ int offset = s << (h - len + 1);\n          FOR(i, p) {\n            u64 l =\
    \ a[i + offset].val;\n            u64 r = a[i + offset + p].val;\n           \
    \ a[i + offset] = l + r;\n            a[i + offset + p] = (mod + l - r) * rot.val;\n\
    \          }\n          rot *= rate2[topbit(~s & -~s)];\n        }\n        len--;\n\
    \      } else {\n        int p = 1 << (h - len);\n        mint rot = 1, imag =\
    \ root[2];\n        FOR(s, (1 << (len - 2))) {\n          int offset = s << (h\
    \ - len + 2);\n          mint rot2 = rot * rot;\n          mint rot3 = rot2 *\
    \ rot;\n          for (int i = 0; i < p; i++) {\n            u64 a0 = a[i + offset\
    \ + 0 * p].val;\n            u64 a1 = a[i + offset + 1 * p].val;\n           \
    \ u64 a2 = a[i + offset + 2 * p].val;\n            u64 a3 = a[i + offset + 3 *\
    \ p].val;\n            u64 x = (mod + a2 - a3) * imag.val % mod;\n           \
    \ a[i + offset] = a0 + a1 + a2 + a3;\n            a[i + offset + 1 * p] = (a0\
    \ + mod - a1 + x) * rot.val;\n            a[i + offset + 2 * p] = (a0 + a1 + 2\
    \ * mod - a2 - a3) * rot2.val;\n            a[i + offset + 3 * p] = (a0 + 2 *\
    \ mod - a1 - x) * rot3.val;\n          }\n          rot *= rate3[topbit(~s & -~s)];\n\
    \        }\n        len -= 2;\n      }\n    }\n  } else {\n    mint coef = mint(1)\
    \ / mint(len(a));\n    FOR(i, len(a)) a[i] *= coef;\n    int len = 0;\n    while\
    \ (len < h) {\n      if (len == h - 1) {\n        int p = 1 << (h - len - 1);\n\
    \        mint irot = 1;\n        FOR(s, 1 << len) {\n          int offset = s\
    \ << (h - len);\n          FOR(i, p) {\n            auto l = a[i + offset];\n\
    \            auto r = a[i + offset + p] * irot;\n            a[i + offset] = l\
    \ + r;\n            a[i + offset + p] = l - r;\n          }\n          irot *=\
    \ irate2[topbit(~s & -~s)];\n        }\n        len++;\n      } else {\n     \
    \   int p = 1 << (h - len - 2);\n        mint irot = 1, iimag = iroot[2];\n  \
    \      for (int s = 0; s < (1 << len); s++) {\n          mint irot2 = irot * irot;\n\
    \          mint irot3 = irot2 * irot;\n          int offset = s << (h - len);\n\
    \          for (int i = 0; i < p; i++) {\n            u64 mod2 = u64(mod) * mod;\n\
    \            u64 a0 = a[i + offset].val;\n            u64 a1 = u64(a[i + offset\
    \ + p].val) * irot.val;\n            u64 a2 = u64(a[i + offset + 2 * p].val) *\
    \ irot2.val;\n            u64 a3 = u64(a[i + offset + 3 * p].val) * irot3.val;\n\
    \            u64 a1na3imag = (a1 + mod2 - a3) % mod * iimag.val;\n           \
    \ u64 na2 = mod2 - a2;\n            a[i + offset] = a0 + a2 + a1 + a3;\n     \
    \       a[i + offset + 1 * p] = a0 + a2 + (2 * mod2 - (a1 + a3));\n          \
    \  a[i + offset + 2 * p] = a0 + na2 + a1na3imag;\n            a[i + offset + 3\
    \ * p] = a0 + na2 + (mod2 - a1na3imag);\n          }\n          irot *= irate3[topbit(~s\
    \ & -~s)];\n        }\n        len += 2;\n      }\n    }\n  }\n}\n#line 8 \"poly/multipoint.hpp\"\
    \n\r\ntemplate <typename mint>\r\nstruct SubproductTree {\r\n  int m;\r\n  int\
    \ sz;\r\n  vc<vc<mint>> T;\r\n  SubproductTree(const vc<mint>& x) {\r\n    m =\
    \ len(x);\r\n    sz = 1;\r\n    while (sz < m) sz *= 2;\r\n    T.resize(2 * sz);\r\
    \n    FOR(i, sz) T[sz + i] = {1, (i < m ? -x[i] : 0)};\r\n    FOR3_R(i, 1, sz)\
    \ T[i] = convolution(T[2 * i], T[2 * i + 1]);\r\n  }\r\n\r\n  vc<mint> evaluation(vc<mint>\
    \ f) {\r\n    int n = len(f);\r\n    if (n == 0) return vc<mint>(m, mint(0));\r\
    \n    f.resize(2 * n - 1);\r\n    vc<vc<mint>> g(2 * sz);\r\n    g[1] = T[1];\r\
    \n    g[1].resize(n);\r\n    g[1] = fps_inv(g[1]);\r\n    g[1] = middle_product(f,\
    \ g[1]);\r\n    g[1].resize(sz);\r\n\r\n    FOR3(i, 1, sz) {\r\n      g[2 * i]\
    \ = middle_product(g[i], T[2 * i + 1]);\r\n      g[2 * i + 1] = middle_product(g[i],\
    \ T[2 * i]);\r\n    }\r\n    vc<mint> vals(m);\r\n    FOR(i, m) vals[i] = g[sz\
    \ + i][0];\r\n    return vals;\r\n  }\r\n\r\n  vc<mint> interpolation(vc<mint>&\
    \ y) {\r\n    assert(len(y) == m);\r\n    vc<mint> a(m);\r\n    FOR(i, m) a[i]\
    \ = T[1][m - i - 1] * (i + 1);\r\n\r\n    a = evaluation(a);\r\n    vc<vc<mint>>\
    \ t(2 * sz);\r\n    FOR(i, sz) t[sz + i] = {(i < m ? y[i] / a[i] : 0)};\r\n  \
    \  FOR3_R(i, 1, sz) {\r\n      t[i] = convolution(t[2 * i], T[2 * i + 1]);\r\n\
    \      auto tt = convolution(t[2 * i + 1], T[2 * i]);\r\n      FOR(k, len(t[i]))\
    \ t[i][k] += tt[k];\r\n    }\r\n    t[1].resize(m);\r\n    reverse(all(t[1]));\r\
    \n    return t[1];\r\n  }\r\n};\r\n\r\ntemplate <typename mint>\r\nvc<mint> multipoint_evaluation_ntt(vc<mint>\
    \ f, vc<mint> point) {\r\n  using poly = vc<mint>;\r\n  int n = 1, k = 0;\r\n\
    \  while (n < len(point)) n *= 2, ++k;\r\n  vv(mint, F, k + 1, 2 * n);\r\n  FOR(i,\
    \ len(point)) F[0][2 * i] = -point[i];\r\n\r\n  FOR(d, k) {\r\n    int b = 1 <<\
    \ d;\r\n    for (int L = 0; L < 2 * n; L += 4 * b) {\r\n      poly f1 = {F[d].begin()\
    \ + L, F[d].begin() + L + b};\r\n      poly f2 = {F[d].begin() + L + 2 * b, F[d].begin()\
    \ + L + 3 * b};\r\n      ntt_doubling(f1), ntt_doubling(f2);\r\n      FOR(i, b)\
    \ f1[i] += 1, f2[i] += 1;\r\n      FOR(i, b, 2 * b) f1[i] -= 1, f2[i] -= 1;\r\n\
    \      copy(all(f1), F[d].begin() + L);\r\n      copy(all(f2), F[d].begin() +\
    \ L + 2 * b);\r\n      FOR(i, 2 * b) { F[d + 1][L + i] = f1[i] * f2[i] - 1; }\r\
    \n    }\r\n  }\r\n  vc<mint> P = {F[k].begin(), F[k].begin() + n};\r\n  ntt(P,\
    \ 1), P.eb(1), reverse(all(P)), P.resize(len(f)), P = fps_inv<mint>(P);\r\n  f.resize(n\
    \ + len(P) - 1), f = middle_product<mint>(f, P), reverse(all(f));\r\n  transposed_ntt(f,\
    \ 1);\r\n  vc<mint>& G = f;\r\n  FOR_R(d, k) {\r\n    vc<mint> nxt_G(n);\r\n \
    \   int b = 1 << d;\r\n    for (int L = 0; L < n; L += 2 * b) {\r\n      vc<mint>\
    \ g1(2 * b), g2(2 * b);\r\n      FOR(i, 2 * b) { g1[i] = G[L + i] * F[d][2 * L\
    \ + 2 * b + i]; }\r\n      FOR(i, 2 * b) { g2[i] = G[L + i] * F[d][2 * L + i];\
    \ }\r\n      ntt_doubling<mint, true>(g1), ntt_doubling<mint, true>(g2);\r\n \
    \     FOR(i, b) { nxt_G[L + i] = g1[i], nxt_G[L + b + i] = g2[i]; }\r\n    }\r\
    \n    swap(G, nxt_G);\r\n  }\r\n  G.resize(len(point));\r\n  return G;\r\n}\r\n\
    \r\ntemplate <typename mint>\r\nvc<mint> multipoint_eval(vc<mint>& f, vc<mint>&\
    \ x) {\r\n  if (x.empty()) return {};\r\n  if (mint::can_ntt()) return multipoint_evaluation_ntt(f,\
    \ x);\r\n  SubproductTree<mint> F(x);\r\n  return F.evaluation(f);\r\n}\r\n\r\n\
    template <typename mint>\r\nvc<mint> multipoint_interpolate(vc<mint>& x, vc<mint>&\
    \ y) {\r\n  if (x.empty()) return {};\r\n  SubproductTree<mint> F(x);\r\n  return\
    \ F.interpolation(y);\r\n}\r\n\r\n// calculate f(ar^k) for 0 <= k < m\r\ntemplate\
    \ <typename mint>\r\nvc<mint> multipoint_eval_on_geom_seq(vc<mint> f, mint a,\
    \ mint r, int m) {\r\n  const int n = len(f);\r\n  if (m == 0) return {};\r\n\r\
    \n  auto eval = [&](mint x) -> mint {\r\n    mint fx = 0;\r\n    mint pow = 1;\r\
    \n    FOR(i, n) fx += f[i] * pow, pow *= x;\r\n    return fx;\r\n  };\r\n\r\n\
    \  if (r == mint(0)) {\r\n    vc<mint> res(m);\r\n    FOR(i, 1, m) res[i] = f[0];\r\
    \n    res[0] = eval(a);\r\n    return res;\r\n  }\r\n  if (n < 60 || m < 60) {\r\
    \n    vc<mint> res(m);\r\n    FOR(i, m) res[i] = eval(a), a *= r;\r\n    return\
    \ res;\r\n  }\r\n  assert(r != mint(0));\r\n  // a == 1 \u306B\u5E30\u7740\r\n\
    \  mint pow_a = 1;\r\n  FOR(i, n) f[i] *= pow_a, pow_a *= a;\r\n\r\n  auto calc\
    \ = [&](mint r, int m) -> vc<mint> {\r\n    // r^{t_i} \u306E\u8A08\u7B97\r\n\
    \    vc<mint> res(m);\r\n    mint pow = 1;\r\n    res[0] = 1;\r\n    FOR(i, m\
    \ - 1) {\r\n      res[i + 1] = res[i] * pow;\r\n      pow *= r;\r\n    }\r\n \
    \   return res;\r\n  };\r\n\r\n  vc<mint> A = calc(r, n + m - 1), B = calc(r.inverse(),\
    \ max(n, m));\r\n  FOR(i, n) f[i] *= B[i];\r\n  f = middle_product(A, f);\r\n\
    \  FOR(i, m) f[i] *= B[i];\r\n  return f;\r\n}\r\n\r\n// Y[i] = f(ar^i)\r\ntemplate\
    \ <typename mint>\r\nvc<mint> multipoint_interpolate_on_geom_seq(vc<mint> Y, mint\
    \ a, mint r) {\r\n  const int n = len(Y);\r\n  if (n == 0) return {};\r\n  if\
    \ (n == 1) return {Y[0]};\r\n  assert(r != mint(0));\r\n  mint ir = r.inverse();\r\
    \n\r\n  vc<mint> POW(n + n - 1), tPOW(n + n - 1);\r\n  POW[0] = tPOW[0] = mint(1);\r\
    \n  FOR(i, n + n - 2) POW[i + 1] = POW[i] * r, tPOW[i + 1] = tPOW[i] * POW[i];\r\
    \n\r\n  vc<mint> iPOW(n + n - 1), itPOW(n + n - 1);\r\n  iPOW[0] = itPOW[0] =\
    \ mint(1);\r\n  FOR(i, n) iPOW[i + 1] = iPOW[i] * ir, itPOW[i + 1] = itPOW[i]\
    \ * iPOW[i];\r\n\r\n  // prod_[1,i] 1-r^k\r\n  vc<mint> S(n);\r\n  S[0] = mint(1);\r\
    \n  FOR(i, 1, n) S[i] = S[i - 1] * (mint(1) - POW[i]);\r\n  vc<mint> iS = all_inverse<mint>(S);\r\
    \n  mint sn = S[n - 1] * (mint(1) - POW[n]);\r\n\r\n  FOR(i, n) {\r\n    Y[i]\
    \ = Y[i] * tPOW[n - 1 - i] * itPOW[n - 1] * iS[i] * iS[n - 1 - i];\r\n    if (i\
    \ % 2 == 1) Y[i] = -Y[i];\r\n  }\r\n\r\n  // sum_i Y[i] / 1-r^ix\r\n  FOR(i, n)\
    \ Y[i] *= itPOW[i];\r\n  vc<mint> f = middle_product(tPOW, Y);\r\n  FOR(i, n)\
    \ f[i] *= itPOW[i];\r\n\r\n  // prod 1-r^ix\r\n  vc<mint> g(n);\r\n  g[0] = mint(1);\r\
    \n  FOR(i, 1, n) {\r\n    g[i] = tPOW[i] * sn * iS[i] * iS[n - i];\r\n    if (i\
    \ % 2 == 1) g[i] = -g[i];\r\n  }\r\n  f = convolution<mint>(f, g);\r\n  f.resize(n);\r\
    \n\r\n  reverse(all(f));\r\n  mint ia = a.inverse();\r\n  mint pow = 1;\r\n  FOR(i,\
    \ n) f[i] *= pow, pow *= ia;\r\n  return f;\r\n}\r\n#line 2 \"poly/partial_frac_decomposition_1.hpp\"\
    \n\n// f(x) / prod(1-a_ix) = sum b_i/1-a_ix\ntemplate <typename mint>\nvc<mint>\
    \ partial_frac_decomposition_1(vc<mint> f, vc<mint> A) {\n  int N = len(A);\n\
    \  assert(len(f) <= N);\n  f.resize(N);\n  SubproductTree<mint> X(A);\n  vc<mint>\
    \ g = X.T[1]; // prod(1-ax)\n  g.resize(N + 1);\n  reverse(all(f));\n  reverse(all(g));\n\
    \  FOR(i, len(g) - 1) g[i] = g[i + 1] * mint(i + 1);\n  g.pop_back();\n  auto\
    \ num = X.evaluation(f);\n  auto den = X.evaluation(g);\n  vc<mint> B(len(A));\n\
    \  FOR(i, len(A)) B[i] = num[i] / den[i];\n  return B;\n}\n#line 2 \"poly/integrate.hpp\"\
    \n\n// \u4E0D\u5B9A\u7A4D\u5206\uFF1Aintegrate(f)\n// \u5B9A\u7A4D\u5206\uFF1A\
    integrate(f, L, R)\ntemplate <typename mint>\nvc<mint> integrate(const vc<mint>&\
    \ f) {\n  vc<mint> g(len(f) + 1);\n  FOR3(i, 1, len(g)) g[i] = f[i - 1] * inv<mint>(i);\n\
    \  return g;\n}\n\n// \u4E0D\u5B9A\u7A4D\u5206\uFF1Aintegrate(f)\n// \u5B9A\u7A4D\
    \u5206\uFF1Aintegrate(f, L, R)\ntemplate <typename mint>\nmint integrate(const\
    \ vc<mint>& f, mint L, mint R) {\n  mint I = 0;\n  mint pow_L = 1, pow_R = 1;\n\
    \  FOR(i, len(f)) {\n    pow_L *= L, pow_R *= R;\n    I += inv<mint>(i + 1) *\
    \ f[i] * (pow_R - pow_L);\n  }\n  return I;\n}\n#line 2 \"poly/differentiate.hpp\"\
    \n\ntemplate <typename mint>\nvc<mint> differentiate(const vc<mint>& f) {\n  if\
    \ (len(f) <= 1) return {};\n  vc<mint> g(len(f) - 1);\n  FOR(i, len(g)) g[i] =\
    \ f[i + 1] * mint(i + 1);\n  return g;\n}\n#line 6 \"poly/fps_exp.hpp\"\n\r\n\
    template <typename mint>\r\nvc<mint> fps_exp_sparse(vc<mint>& f) {\r\n  if (len(f)\
    \ == 0) return {mint(1)};\r\n  assert(f[0] == 0);\r\n  int N = len(f);\r\n  //\
    \ df \u3092\u6301\u305F\u305B\u308B\r\n  vc<pair<int, mint>> dat;\r\n  FOR(i,\
    \ 1, N) if (f[i] != mint(0)) dat.eb(i - 1, mint(i) * f[i]);\r\n  vc<mint> F(N);\r\
    \n  F[0] = 1;\r\n  FOR(n, 1, N) {\r\n    mint rhs = 0;\r\n    for (auto&& [k,\
    \ fk]: dat) {\r\n      if (k > n - 1) break;\r\n      rhs += fk * F[n - 1 - k];\r\
    \n    }\r\n    F[n] = rhs * inv<mint>(n);\r\n  }\r\n  return F;\r\n}\r\n\r\ntemplate\
    \ <typename mint>\r\nvc<mint> fps_exp_dense(vc<mint>& h) {\r\n  const int n =\
    \ len(h);\r\n  assert(n > 0 && h[0] == mint(0));\r\n  if (mint::can_ntt()) {\r\
    \n    vc<mint>& f = h;\r\n    vc<mint> b = {1, (1 < n ? f[1] : 0)};\r\n    vc<mint>\
    \ c = {1}, z1, z2 = {1, 1};\r\n    while (len(b) < n) {\r\n      int m = len(b);\r\
    \n      auto y = b;\r\n      y.resize(2 * m);\r\n      ntt(y, 0);\r\n      z1\
    \ = z2;\r\n      vc<mint> z(m);\r\n      FOR(i, m) z[i] = y[i] * z1[i];\r\n  \
    \    ntt(z, 1);\r\n      FOR(i, m / 2) z[i] = 0;\r\n      ntt(z, 0);\r\n     \
    \ FOR(i, m) z[i] *= -z1[i];\r\n      ntt(z, 1);\r\n      c.insert(c.end(), z.begin()\
    \ + m / 2, z.end());\r\n      z2 = c;\r\n      z2.resize(2 * m);\r\n      ntt(z2,\
    \ 0);\r\n\r\n      vc<mint> x(f.begin(), f.begin() + m);\r\n      FOR(i, len(x)\
    \ - 1) x[i] = x[i + 1] * mint(i + 1);\r\n      x.back() = 0;\r\n      ntt(x, 0);\r\
    \n      FOR(i, m) x[i] *= y[i];\r\n      ntt(x, 1);\r\n\r\n      FOR(i, m - 1)\
    \ x[i] -= b[i + 1] * mint(i + 1);\r\n\r\n      x.resize(m + m);\r\n      FOR(i,\
    \ m - 1) x[m + i] = x[i], x[i] = 0;\r\n      ntt(x, 0);\r\n      FOR(i, m + m)\
    \ x[i] *= z2[i];\r\n      ntt(x, 1);\r\n      FOR_R(i, len(x) - 1) x[i + 1] =\
    \ x[i] * inv<mint>(i + 1);\r\n      x[0] = 0;\r\n\r\n      FOR3(i, m, min(n, m\
    \ + m)) x[i] += f[i];\r\n      FOR(i, m) x[i] = 0;\r\n      ntt(x, 0);\r\n   \
    \   FOR(i, m + m) x[i] *= y[i];\r\n      ntt(x, 1);\r\n      b.insert(b.end(),\
    \ x.begin() + m, x.end());\r\n    }\r\n    b.resize(n);\r\n    return b;\r\n \
    \ }\r\n\r\n  const int L = len(h);\r\n  assert(L > 0 && h[0] == mint(0));\r\n\
    \  int LOG = 0;\r\n  while (1 << LOG < L) ++LOG;\r\n  h.resize(1 << LOG);\r\n\
    \  auto dh = differentiate(h);\r\n  vc<mint> f = {1}, g = {1};\r\n  int m = 1;\r\
    \n\r\n  vc<mint> p;\r\n\r\n  FOR(LOG) {\r\n    p = convolution(f, g);\r\n    p.resize(m);\r\
    \n    p = convolution(p, g);\r\n    p.resize(m);\r\n    g.resize(m);\r\n    FOR(i,\
    \ m) g[i] += g[i] - p[i];\r\n    p = {dh.begin(), dh.begin() + m - 1};\r\n   \
    \ p = convolution(f, p);\r\n    p.resize(m + m - 1);\r\n    FOR(i, m + m - 1)\
    \ p[i] = -p[i];\r\n    FOR(i, m - 1) p[i] += mint(i + 1) * f[i + 1];\r\n    p\
    \ = convolution(p, g);\r\n\r\n    p.resize(m + m - 1);\r\n    FOR(i, m - 1) p[i]\
    \ += dh[i];\r\n    p = integrate(p);\r\n    FOR(i, m + m) p[i] = h[i] - p[i];\r\
    \n    p[0] += mint(1);\r\n    f = convolution(f, p);\r\n    f.resize(m + m);\r\
    \n    m += m;\r\n  }\r\n  f.resize(L);\r\n  return f;\r\n}\r\n\r\ntemplate <typename\
    \ mint>\r\nvc<mint> fps_exp(vc<mint>& f) {\r\n  int n = count_terms(f);\r\n  int\
    \ t = (mint::can_ntt() ? 320 : 3000);\r\n  return (n <= t ? fps_exp_sparse<mint>(f)\
    \ : fps_exp_dense<mint>(f));\r\n}\r\n#line 2 \"poly/fps_log.hpp\"\n\r\n#line 5\
    \ \"poly/fps_log.hpp\"\n\r\ntemplate <typename mint>\r\nvc<mint> fps_log_dense(const\
    \ vc<mint>& f) {\r\n  assert(f[0] == mint(1));\r\n  ll N = len(f);\r\n  vc<mint>\
    \ df = f;\r\n  FOR(i, N) df[i] *= mint(i);\r\n  df.erase(df.begin());\r\n  auto\
    \ f_inv = fps_inv(f);\r\n  auto g = convolution(df, f_inv);\r\n  g.resize(N -\
    \ 1);\r\n  g.insert(g.begin(), 0);\r\n  FOR(i, N) g[i] *= inv<mint>(i);\r\n  return\
    \ g;\r\n}\r\n\r\ntemplate <typename mint>\r\nvc<mint> fps_log_sparse(const vc<mint>&\
    \ f) {\r\n  int N = f.size();\r\n  vc<pair<int, mint>> dat;\r\n  FOR(i, 1, N)\
    \ if (f[i] != mint(0)) dat.eb(i, f[i]);\r\n  vc<mint> F(N);\r\n  vc<mint> g(N\
    \ - 1);\r\n  for (int n = 0; n < N - 1; ++n) {\r\n    mint rhs = mint(n + 1) *\
    \ f[n + 1];\r\n    for (auto&& [i, fi]: dat) {\r\n      if (i > n) break;\r\n\
    \      rhs -= fi * g[n - i];\r\n    }\r\n    g[n] = rhs;\r\n    F[n + 1] = rhs\
    \ * inv<mint>(n + 1);\r\n  }\r\n  return F;\r\n}\r\n\r\ntemplate <typename mint>\r\
    \nvc<mint> fps_log(const vc<mint>& f) {\r\n  assert(f[0] == mint(1));\r\n  int\
    \ n = count_terms(f);\r\n  int t = (mint::can_ntt() ? 200 : 1200);\r\n  return\
    \ (n <= t ? fps_log_sparse<mint>(f) : fps_log_dense<mint>(f));\r\n}\r\n#line 5\
    \ \"poly/fps_pow.hpp\"\n\r\n// fps \u306E k \u4E57\u3092\u6C42\u3081\u308B\u3002\
    k >= 0 \u306E\u524D\u63D0\u3067\u3042\u308B\u3002\r\n// \u5B9A\u6570\u9805\u304C\
    \ 1 \u3067\u3001k \u304C mint \u306E\u5834\u5408\u306B\u306F\u3001fps_pow_1 \u3092\
    \u4F7F\u3046\u3053\u3068\u3002\r\n// \u30FBdense \u306A\u5834\u5408\uFF1A log,\
    \ exp \u3092\u4F7F\u3046 O(NlogN)\r\n// \u30FBsparse \u306A\u5834\u5408\uFF1A\
    \ O(NK)\r\ntemplate <typename mint>\r\nvc<mint> fps_pow(const vc<mint>& f, ll\
    \ k) {\r\n  assert(0 <= k);\r\n  int n = len(f);\r\n  if (k == 0) {\r\n    vc<mint>\
    \ g(n);\r\n    g[0] = mint(1);\r\n    return g;\r\n  }\r\n  int d = n;\r\n  FOR_R(i,\
    \ n) if (f[i] != 0) d = i;\r\n  // d * k >= n\r\n  if (d >= ceil<ll>(n, k)) {\r\
    \n    vc<mint> g(n);\r\n    return g;\r\n  }\r\n  ll off = d * k;\r\n  mint c\
    \ = f[d];\r\n  mint c_inv = mint(1) / mint(c);\r\n  vc<mint> g(n - off);\r\n \
    \ FOR(i, n - off) g[i] = f[d + i] * c_inv;\r\n  g = fps_pow_1(g, mint(k));\r\n\
    \  vc<mint> h(n);\r\n  c = c.pow(k);\r\n  FOR(i, len(g)) h[off + i] = g[i] * c;\r\
    \n  return h;\r\n}\r\n\r\ntemplate <typename mint>\r\nvc<mint> fps_pow_1_sparse(const\
    \ vc<mint>& f, mint K) {\r\n  int N = len(f);\r\n  assert(N == 0 || f[0] == mint(1));\r\
    \n  vc<pair<int, mint>> dat;\r\n  FOR(i, 1, N) if (f[i] != mint(0)) dat.eb(i,\
    \ f[i]);\r\n  vc<mint> g(N);\r\n  g[0] = 1;\r\n  FOR(n, N - 1) {\r\n    mint&\
    \ x = g[n + 1];\r\n    for (auto&& [d, cf]: dat) {\r\n      if (d > n + 1) break;\r\
    \n      mint t = cf * g[n - d + 1];\r\n      x += t * (K * mint(d) - mint(n -\
    \ d + 1));\r\n    }\r\n    x *= inv<mint>(n + 1);\r\n  }\r\n  return g;\r\n}\r\
    \n\r\ntemplate <typename mint>\r\nvc<mint> fps_pow_1_dense(const vc<mint>& f,\
    \ mint K) {\r\n  assert(f[0] == mint(1));\r\n  auto log_f = fps_log(f);\r\n  FOR(i,\
    \ len(f)) log_f[i] *= K;\r\n  return fps_exp_dense(log_f);\r\n}\r\n\r\ntemplate\
    \ <typename mint>\r\nvc<mint> fps_pow_1(const vc<mint>& f, mint K) {\r\n  int\
    \ n = count_terms(f);\r\n  int t = (mint::can_ntt() ? 100 : 1300);\r\n  return\
    \ (n <= t ? fps_pow_1_sparse(f, K) : fps_pow_1_dense(f, K));\r\n}\r\n\r\n// f^e,\
    \ sparse, O(NMK)\r\ntemplate <typename mint>\r\nvvc<mint> fps_pow_1_sparse_2d(vvc<mint>\
    \ f, mint n) {\r\n  assert(f[0][0] == mint(1));\r\n  int N = len(f), M = len(f[0]);\r\
    \n  vv(mint, dp, N, M);\r\n  dp[0] = fps_pow_1_sparse<mint>(f[0], n);\r\n\r\n\
    \  vc<tuple<int, int, mint>> dat;\r\n  FOR(i, N) FOR(j, M) {\r\n    if ((i > 0\
    \ || j > 0) && f[i][j] != mint(0)) dat.eb(i, j, f[i][j]);\r\n  }\r\n  FOR(i, 1,\
    \ N) {\r\n    FOR(j, M) {\r\n      // F = f^n, f dF = n df F\r\n      // [x^{i-1}y^j]\r\
    \n      mint lhs = 0, rhs = 0;\r\n      for (auto&& [a, b, c]: dat) {\r\n    \
    \    if (a < i && b <= j) lhs += dp[i - a][j - b] * mint(i - a);\r\n        if\
    \ (a <= i && b <= j) rhs += dp[i - a][j - b] * c * mint(a);\r\n      }\r\n   \
    \   dp[i][j] = (n * rhs - lhs) * inv<mint>(i);\r\n    }\r\n  }\r\n  return dp;\r\
    \n}\r\n#line 4 \"seq/famous/stirling_number_1.hpp\"\n\r\ntemplate <typename mint>\r\
    \nvc<mint> stirling_number_1_2d(int nmax, int kmax) {\r\n  vv(mint, A, nmax +\
    \ 1, kmax + 1);\r\n  A[0][0] = 1;\r\n  for (int i = 1; i <= nmax; ++i) {\r\n \
    \   for (int j = 0; j < i + 1; ++j) {\r\n      if (j > kmax) break;\r\n      mint\
    \ &x = A[i][j];\r\n      if (j) x += A[i - 1][j - 1];\r\n      x -= A[i - 1][j]\
    \ * mint(i - 1);\r\n    }\r\n  }\r\n}\r\n\r\n// x(x+1)...(x+n-1) \u306E\u4FC2\u6570\
    \ c(n, k)\r\n// [n] \u306E\u9806\u5217\u306E\u3046\u3061\u3001k \u500B\u306E\u30B5\
    \u30A4\u30AF\u30EB\u306B\u5206\u304B\u308C\u308B\u3082\u306E\u306E\u500B\u6570\
    \u3002\r\n// n \u3092\u56FA\u5B9A\u3057\u305F\u3068\u304D\u306E\u5217\u6319\u3092\
    \ O(n log n) \u3067\u884C\u3046\u3002\r\ntemplate <typename mint>\r\nvc<mint>\
    \ stirling_number_1_n(int n, bool sgn = false) {\r\n  auto dfs = [&](auto self,\
    \ int n) -> vc<mint> {\r\n    if (n == 0) return {1};\r\n    if (n == 1) return\
    \ {0, 1};\r\n    auto f = self(self, n / 2);\r\n    auto g = poly_taylor_shift(f,\
    \ mint(n / 2));\r\n    f = convolution(f, g);\r\n    if (n & 1) {\r\n      g =\
    \ {(n - 1), 1};\r\n      f = convolution(f, g);\r\n    }\r\n    return f;\r\n\
    \  };\r\n  auto f = dfs(dfs, n);\r\n  if (sgn) { FOR(i, n + 1) if ((n + i) % 2\
    \ == 1) f[i] = -f[i]; }\r\n  return f;\r\n}\r\n\r\n// k \u3092\u56FA\u5B9A\u3057\
    \u305F\u3068\u304D\u306E c(n, k) \u306E\u5217\u6319\u3002\r\ntemplate <typename\
    \ mint>\r\nvc<mint> stirling_number_1_k(int k, int n_max, bool sgn = false) {\r\
    \n  if (n_max < k) {\r\n    vc<mint> f(n_max + 1);\r\n    return f;\r\n  }\r\n\
    \  int LIM = n_max - k;\r\n  vc<mint> f(LIM + 1);\r\n  FOR(i, LIM + 1) f[i] =\
    \ inv<mint>(i + 1);\r\n  f = fps_pow(f, k);\r\n  if (sgn) { FOR(i, LIM + 1) if\
    \ (i % 2 == 1) f[i] = -f[i]; }\r\n\r\n  mint cf = fact_inv<mint>(k);\r\n  vc<mint>\
    \ res(n_max + 1);\r\n  FOR(i, len(f)) res[k + i] = cf * f[i] * fact<mint>(k +\
    \ i);\r\n\r\n  return res;\r\n}\r\n\r\n// s(n,i) \u3092\u9006\u9806\u306B\u4E26\
    \u3079\u305F\u3082\u306E\r\n// (1+0x)(1+1x)(1+2x)...(1+(N-1)x) \u3092 [x^K] \u307E\
    \u3067\r\ntemplate <typename mint>\r\nvc<mint> stirling_number_1_suffix(ll N,\
    \ ll K) {\r\n  // \u307E\u305A\u306F e^{Nx}-1 / e^x-1 \u3092 [x^K] \u307E\u3067\
    \r\n  vc<mint> num(K + 1), den(K + 1);\r\n  mint powN = 1;\r\n  FOR(k, K + 1)\
    \ {\r\n    powN *= N;\r\n    num[k] = fact_inv<mint>(k + 1) * powN;\r\n    den[k]\
    \ = fact_inv<mint>(k + 1);\r\n  }\r\n  vc<mint> S = fps_div<mint>(num, den);\r\
    \n  FOR(i, K + 1) S[i] *= fact<mint>(i);\r\n  vc<mint> LOG_F(K + 1);\r\n  FOR(i,\
    \ 1, K + 1) LOG_F[i] = S[i] * inv<mint>(i) * (2 * (i & 1) - 1);\r\n  return fps_exp(LOG_F);\r\
    \n}\r\n#line 5 \"poly/composition_f_log_1_minus_x.hpp\"\n\n/*\nf(log(1-x))\n2024/05/01\
    \ noshi\u5408\u6210\u306E\u65B9\u304C\u5C11\u3057\u9AD8\u901F\u306A\u306E\u3067\
    \u4F7F\u308F\u306A\u3044\u304C\nmultipoint \u3092\u9AD8\u901F\u5316\u3059\u308B\
    \u3068\u4F7F\u3048\u308B\u304B\u3082\n*/\ntemplate <typename mint>\nvc<mint> composition_f_log_1_minus_x(vc<mint>\
    \ f) {\n  int N = len(f) - 1;\n  FOR(i, N + 1) f[i] *= fact<mint>(i);\n  vc<mint>\
    \ S = stirling_number_1_n<mint>(N + 1, true);\n  reverse(all(S));\n  f = convolution<mint>(f,\
    \ S);\n  f.resize(N + 1);\n  vc<mint> A(N + 1);\n  FOR(i, N + 1) A[i] = mint::raw(i);\n\
    \  f = partial_frac_decomposition_1(f, A);\n  FOR(i, len(f)) if (i & 1) f[i] =\
    \ -f[i];\n  f = poly_taylor_shift<mint>(f, -1);\n  return f;\n}\n"
  code: "\n#include \"poly/poly_taylor_shift.hpp\"\n#include \"poly/partial_frac_decomposition_1.hpp\"\
    \n#include \"seq/famous/stirling_number_1.hpp\"\n\n/*\nf(log(1-x))\n2024/05/01\
    \ noshi\u5408\u6210\u306E\u65B9\u304C\u5C11\u3057\u9AD8\u901F\u306A\u306E\u3067\
    \u4F7F\u308F\u306A\u3044\u304C\nmultipoint \u3092\u9AD8\u901F\u5316\u3059\u308B\
    \u3068\u4F7F\u3048\u308B\u304B\u3082\n*/\ntemplate <typename mint>\nvc<mint> composition_f_log_1_minus_x(vc<mint>\
    \ f) {\n  int N = len(f) - 1;\n  FOR(i, N + 1) f[i] *= fact<mint>(i);\n  vc<mint>\
    \ S = stirling_number_1_n<mint>(N + 1, true);\n  reverse(all(S));\n  f = convolution<mint>(f,\
    \ S);\n  f.resize(N + 1);\n  vc<mint> A(N + 1);\n  FOR(i, N + 1) A[i] = mint::raw(i);\n\
    \  f = partial_frac_decomposition_1(f, A);\n  FOR(i, len(f)) if (i & 1) f[i] =\
    \ -f[i];\n  f = poly_taylor_shift<mint>(f, -1);\n  return f;\n}\n"
  dependsOn:
  - poly/poly_taylor_shift.hpp
  - mod/powertable.hpp
  - nt/primetable.hpp
  - poly/convolution.hpp
  - mod/modint.hpp
  - mod/modint_common.hpp
  - mod/mod_inv.hpp
  - mod/crt3.hpp
  - poly/convolution_naive.hpp
  - poly/convolution_karatsuba.hpp
  - poly/ntt.hpp
  - poly/partial_frac_decomposition_1.hpp
  - poly/multipoint.hpp
  - poly/middle_product.hpp
  - mod/all_inverse.hpp
  - poly/fps_div.hpp
  - poly/count_terms.hpp
  - poly/fps_inv.hpp
  - poly/ntt_doubling.hpp
  - poly/transposed_ntt.hpp
  - seq/famous/stirling_number_1.hpp
  - poly/fps_pow.hpp
  - poly/fps_exp.hpp
  - poly/integrate.hpp
  - poly/differentiate.hpp
  - poly/fps_log.hpp
  isVerificationFile: false
  path: poly/composition_f_log_1_minus_x.hpp
  requiredBy: []
  timestamp: '2024-10-25 01:17:46+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/1_mytest/composition_log_1_minus_x.test.cpp
documentation_of: poly/composition_f_log_1_minus_x.hpp
layout: document
redirect_from:
- /library/poly/composition_f_log_1_minus_x.hpp
- /library/poly/composition_f_log_1_minus_x.hpp.html
title: poly/composition_f_log_1_minus_x.hpp
---
