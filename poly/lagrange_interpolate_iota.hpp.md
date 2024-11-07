---
data:
  _extendedDependsOn:
  - icon: ':question:'
    path: alg/monoid/mul.hpp
    title: alg/monoid/mul.hpp
  - icon: ':question:'
    path: ds/sliding_window_aggregation.hpp
    title: ds/sliding_window_aggregation.hpp
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
    path: poly/convolution_karatsuba.hpp
    title: poly/convolution_karatsuba.hpp
  - icon: ':question:'
    path: poly/convolution_naive.hpp
    title: poly/convolution_naive.hpp
  - icon: ':question:'
    path: poly/ntt.hpp
    title: poly/ntt.hpp
  _extendedRequiredBy:
  - icon: ':question:'
    path: poly/from_log_differentiation.hpp
    title: poly/from_log_differentiation.hpp
  - icon: ':question:'
    path: poly/prefix_product_of_poly.hpp
    title: poly/prefix_product_of_poly.hpp
  - icon: ':heavy_check_mark:'
    path: poly/sparse_exp_of_div.hpp
    title: poly/sparse_exp_of_div.hpp
  - icon: ':heavy_check_mark:'
    path: seq/interpolate_poly_exp_sum.hpp
    title: seq/interpolate_poly_exp_sum.hpp
  - icon: ':question:'
    path: seq/kth_term_of_p_recursive.hpp
    title: seq/kth_term_of_p_recursive.hpp
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/1_mytest/factorial_998.test.cpp
    title: test/1_mytest/factorial_998.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/2_library_checker/enumerative_combinatorics/factorial.test.cpp
    title: test/2_library_checker/enumerative_combinatorics/factorial.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/2_library_checker/other/sum_of_exp_times_poly.test.cpp
    title: test/2_library_checker/other/sum_of_exp_times_poly.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/2_library_checker/polynomial/shift_of_sampling_points_of_polynomial.test.cpp
    title: test/2_library_checker/polynomial/shift_of_sampling_points_of_polynomial.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/3_yukicoder/1080_2.test.cpp
    title: test/3_yukicoder/1080_2.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/3_yukicoder/2166.test.cpp
    title: test/3_yukicoder/2166.test.cpp
  - icon: ':x:'
    path: test/3_yukicoder/2747.test.cpp
    title: test/3_yukicoder/2747.test.cpp
  - icon: ':x:'
    path: test/3_yukicoder/502_2.test.cpp
    title: test/3_yukicoder/502_2.test.cpp
  - icon: ':x:'
    path: test/5_atcoder/abc222h_2.test.cpp
    title: test/5_atcoder/abc222h_2.test.cpp
  - icon: ':x:'
    path: test/5_atcoder/abc276_g.test.cpp
    title: test/5_atcoder/abc276_g.test.cpp
  - icon: ':x:'
    path: test/5_atcoder/abc276_g_2.test.cpp
    title: test/5_atcoder/abc276_g_2.test.cpp
  _isVerificationFailed: true
  _pathExtension: hpp
  _verificationStatusIcon: ':question:'
  attributes:
    links: []
  bundledCode: "#line 2 \"alg/monoid/mul.hpp\"\n\r\ntemplate <class T>\r\nstruct Monoid_Mul\
    \ {\r\n  using value_type = T;\r\n  using X = T;\r\n  static constexpr X op(const\
    \ X &x, const X &y) noexcept { return x * y; }\r\n  static constexpr X inverse(const\
    \ X &x) noexcept { return X(1) / x; }\r\n  static constexpr X unit() { return\
    \ X(1); }\r\n  static constexpr bool commute = true;\r\n};\r\n#line 1 \"ds/sliding_window_aggregation.hpp\"\
    \ntemplate <class Monoid>\nstruct Sliding_Window_Aggregation {\n  using X = typename\
    \ Monoid::value_type;\n  using value_type = X;\n  int sz = 0;\n  vc<X> dat;\n\
    \  vc<X> cum_l;\n  X cum_r;\n\n  Sliding_Window_Aggregation() : cum_l({Monoid::unit()}),\
    \ cum_r(Monoid::unit()) {}\n\n  int size() { return sz; }\n\n  void push(X x)\
    \ {\n    ++sz;\n    cum_r = Monoid::op(cum_r, x);\n    dat.eb(x);\n  }\n\n  void\
    \ pop() {\n    --sz;\n    cum_l.pop_back();\n    if (len(cum_l) == 0) {\n    \
    \  cum_l = {Monoid::unit()};\n      cum_r = Monoid::unit();\n      while (len(dat)\
    \ > 1) {\n        cum_l.eb(Monoid::op(dat.back(), cum_l.back()));\n        dat.pop_back();\n\
    \      }\n      dat.pop_back();\n    }\n  }\n\n  X lprod() { return cum_l.back();\
    \ }\n  X rprod() { return cum_r; }\n\n  X prod() { return Monoid::op(cum_l.back(),\
    \ cum_r); }\n};\n\n// \u5B9A\u6570\u500D\u306F\u76EE\u306B\u898B\u3048\u3066\u9045\
    \u304F\u306A\u308B\u306E\u3067\u3001queue \u3067\u3088\u3044\u3068\u304D\u306F\
    \u4F7F\u308F\u306A\u3044\ntemplate <class Monoid>\nstruct SWAG_deque {\n  using\
    \ X = typename Monoid::value_type;\n  using value_type = X;\n  int sz;\n  vc<X>\
    \ dat_l, dat_r;\n  vc<X> cum_l, cum_r;\n\n  SWAG_deque() : sz(0), cum_l({Monoid::unit()}),\
    \ cum_r({Monoid::unit()}) {}\n\n  int size() { return sz; }\n\n  void push_back(X\
    \ x) {\n    ++sz;\n    dat_r.eb(x);\n    cum_r.eb(Monoid::op(cum_r.back(), x));\n\
    \  }\n\n  void push_front(X x) {\n    ++sz;\n    dat_l.eb(x);\n    cum_l.eb(Monoid::op(x,\
    \ cum_l.back()));\n  }\n\n  void push(X x) { push_back(x); }\n\n  void clear()\
    \ {\n    sz = 0;\n    dat_l.clear(), dat_r.clear();\n    cum_l = {Monoid::unit()},\
    \ cum_r = {Monoid::unit()};\n  }\n\n  void pop_front() {\n    if (sz == 1) return\
    \ clear();\n    if (dat_l.empty()) rebuild();\n    --sz;\n    dat_l.pop_back();\n\
    \    cum_l.pop_back();\n  }\n\n  void pop_back() {\n    if (sz == 1) return clear();\n\
    \    if (dat_r.empty()) rebuild();\n    --sz;\n    dat_r.pop_back();\n    cum_r.pop_back();\n\
    \  }\n\n  void pop() { pop_front(); }\n\n  X front() {\n    if (len(dat_l)) return\
    \ dat_l.back();\n    return dat_r[0];\n  }\n\n  X lprod() { return cum_l.back();\
    \ }\n  X rprod() { return cum_r.back(); }\n  X prod() { return Monoid::op(cum_l.back(),\
    \ cum_r.back()); }\n  X prod_all() { return prod(); }\n\nprivate:\n  void rebuild()\
    \ {\n    vc<X> X;\n    reverse(all(dat_l));\n    concat(X, dat_l, dat_r);\n  \
    \  clear();\n    int m = len(X) / 2;\n    FOR_R(i, m) push_front(X[i]);\n    FOR(i,\
    \ m, len(X)) push_back(X[i]);\n    assert(sz == len(X));\n  }\n};\n#line 2 \"\
    mod/modint_common.hpp\"\n\nstruct has_mod_impl {\n  template <class T>\n  static\
    \ auto check(T &&x) -> decltype(x.get_mod(), std::true_type{});\n  template <class\
    \ T>\n  static auto check(...) -> std::false_type;\n};\n\ntemplate <class T>\n\
    class has_mod : public decltype(has_mod_impl::check<T>(std::declval<T>())) {};\n\
    \ntemplate <typename mint>\nmint inv(int n) {\n  static const int mod = mint::get_mod();\n\
    \  static vector<mint> dat = {0, 1};\n  assert(0 <= n);\n  if (n >= mod) n %=\
    \ mod;\n  while (len(dat) <= n) {\n    int k = len(dat);\n    int q = (mod + k\
    \ - 1) / k;\n    dat.eb(dat[k * q - mod] * mint::raw(q));\n  }\n  return dat[n];\n\
    }\n\ntemplate <typename mint>\nmint fact(int n) {\n  static const int mod = mint::get_mod();\n\
    \  assert(0 <= n && n < mod);\n  static vector<mint> dat = {1, 1};\n  while (len(dat)\
    \ <= n) dat.eb(dat[len(dat) - 1] * mint::raw(len(dat)));\n  return dat[n];\n}\n\
    \ntemplate <typename mint>\nmint fact_inv(int n) {\n  static vector<mint> dat\
    \ = {1, 1};\n  if (n < 0) return mint(0);\n  while (len(dat) <= n) dat.eb(dat[len(dat)\
    \ - 1] * inv<mint>(len(dat)));\n  return dat[n];\n}\n\ntemplate <class mint, class...\
    \ Ts>\nmint fact_invs(Ts... xs) {\n  return (mint(1) * ... * fact_inv<mint>(xs));\n\
    }\n\ntemplate <typename mint, class Head, class... Tail>\nmint multinomial(Head\
    \ &&head, Tail &&... tail) {\n  return fact<mint>(head) * fact_invs<mint>(std::forward<Tail>(tail)...);\n\
    }\n\ntemplate <typename mint>\nmint C_dense(int n, int k) {\n  static vvc<mint>\
    \ C;\n  static int H = 0, W = 0;\n  auto calc = [&](int i, int j) -> mint {\n\
    \    if (i == 0) return (j == 0 ? mint(1) : mint(0));\n    return C[i - 1][j]\
    \ + (j ? C[i - 1][j - 1] : 0);\n  };\n  if (W <= k) {\n    FOR(i, H) {\n     \
    \ C[i].resize(k + 1);\n      FOR(j, W, k + 1) { C[i][j] = calc(i, j); }\n    }\n\
    \    W = k + 1;\n  }\n  if (H <= n) {\n    C.resize(n + 1);\n    FOR(i, H, n +\
    \ 1) {\n      C[i].resize(W);\n      FOR(j, W) { C[i][j] = calc(i, j); }\n   \
    \ }\n    H = n + 1;\n  }\n  return C[n][k];\n}\n\ntemplate <typename mint, bool\
    \ large = false, bool dense = false>\nmint C(ll n, ll k) {\n  assert(n >= 0);\n\
    \  if (k < 0 || n < k) return 0;\n  if constexpr (dense) return C_dense<mint>(n,\
    \ k);\n  if constexpr (!large) return multinomial<mint>(n, k, n - k);\n  k = min(k,\
    \ n - k);\n  mint x(1);\n  FOR(i, k) x *= mint(n - i);\n  return x * fact_inv<mint>(k);\n\
    }\n\ntemplate <typename mint, bool large = false>\nmint C_inv(ll n, ll k) {\n\
    \  assert(n >= 0);\n  assert(0 <= k && k <= n);\n  if (!large) return fact_inv<mint>(n)\
    \ * fact<mint>(k) * fact<mint>(n - k);\n  return mint(1) / C<mint, 1>(n, k);\n\
    }\n\n// [x^d](1-x)^{-n}\ntemplate <typename mint, bool large = false, bool dense\
    \ = false>\nmint C_negative(ll n, ll d) {\n  assert(n >= 0);\n  if (d < 0) return\
    \ mint(0);\n  if (n == 0) { return (d == 0 ? mint(1) : mint(0)); }\n  return C<mint,\
    \ large, dense>(n + d - 1, d);\n}\n#line 3 \"mod/modint.hpp\"\n\ntemplate <int\
    \ mod>\nstruct modint {\n  static constexpr u32 umod = u32(mod);\n  static_assert(umod\
    \ < u32(1) << 31);\n  u32 val;\n\n  static modint raw(u32 v) {\n    modint x;\n\
    \    x.val = v;\n    return x;\n  }\n  constexpr modint() : val(0) {}\n  constexpr\
    \ modint(u32 x) : val(x % umod) {}\n  constexpr modint(u64 x) : val(x % umod)\
    \ {}\n  constexpr modint(u128 x) : val(x % umod) {}\n  constexpr modint(int x)\
    \ : val((x %= mod) < 0 ? x + mod : x){};\n  constexpr modint(ll x) : val((x %=\
    \ mod) < 0 ? x + mod : x){};\n  constexpr modint(i128 x) : val((x %= mod) < 0\
    \ ? x + mod : x){};\n  bool operator<(const modint &other) const { return val\
    \ < other.val; }\n  modint &operator+=(const modint &p) {\n    if ((val += p.val)\
    \ >= umod) val -= umod;\n    return *this;\n  }\n  modint &operator-=(const modint\
    \ &p) {\n    if ((val += umod - p.val) >= umod) val -= umod;\n    return *this;\n\
    \  }\n  modint &operator*=(const modint &p) {\n    val = u64(val) * p.val % umod;\n\
    \    return *this;\n  }\n  modint &operator/=(const modint &p) {\n    *this *=\
    \ p.inverse();\n    return *this;\n  }\n  modint operator-() const { return modint::raw(val\
    \ ? mod - val : u32(0)); }\n  modint operator+(const modint &p) const { return\
    \ modint(*this) += p; }\n  modint operator-(const modint &p) const { return modint(*this)\
    \ -= p; }\n  modint operator*(const modint &p) const { return modint(*this) *=\
    \ p; }\n  modint operator/(const modint &p) const { return modint(*this) /= p;\
    \ }\n  bool operator==(const modint &p) const { return val == p.val; }\n  bool\
    \ operator!=(const modint &p) const { return val != p.val; }\n  modint inverse()\
    \ const {\n    int a = val, b = mod, u = 1, v = 0, t;\n    while (b > 0) {\n \
    \     t = a / b;\n      swap(a -= t * b, b), swap(u -= t * v, v);\n    }\n   \
    \ return modint(u);\n  }\n  modint pow(ll n) const {\n    assert(n >= 0);\n  \
    \  modint ret(1), mul(val);\n    while (n > 0) {\n      if (n & 1) ret *= mul;\n\
    \      mul *= mul;\n      n >>= 1;\n    }\n    return ret;\n  }\n  static constexpr\
    \ int get_mod() { return mod; }\n  // (n, r), r \u306F 1 \u306E 2^n \u4E57\u6839\
    \n  static constexpr pair<int, int> ntt_info() {\n    if (mod == 120586241) return\
    \ {20, 74066978};\n    if (mod == 167772161) return {25, 17};\n    if (mod ==\
    \ 469762049) return {26, 30};\n    if (mod == 754974721) return {24, 362};\n \
    \   if (mod == 880803841) return {23, 211};\n    if (mod == 943718401) return\
    \ {22, 663003469};\n    if (mod == 998244353) return {23, 31};\n    if (mod ==\
    \ 1004535809) return {21, 582313106};\n    if (mod == 1012924417) return {21,\
    \ 368093570};\n    return {-1, -1};\n  }\n  static constexpr bool can_ntt() {\
    \ return ntt_info().fi != -1; }\n};\n\n#ifdef FASTIO\ntemplate <int mod>\nvoid\
    \ rd(modint<mod> &x) {\n  fastio::rd(x.val);\n  x.val %= mod;\n  // assert(0 <=\
    \ x.val && x.val < mod);\n}\ntemplate <int mod>\nvoid wt(modint<mod> x) {\n  fastio::wt(x.val);\n\
    }\n#endif\n\nusing modint107 = modint<1000000007>;\nusing modint998 = modint<998244353>;\n\
    #line 2 \"mod/mod_inv.hpp\"\n\r\n// long \u3067\u3082\u5927\u4E08\u592B\r\n//\
    \ (val * x - 1) \u304C mod \u306E\u500D\u6570\u306B\u306A\u308B\u3088\u3046\u306B\
    \u3059\u308B\r\n// \u7279\u306B mod=0 \u306A\u3089 x=0 \u304C\u6E80\u305F\u3059\
    \r\nll mod_inv(ll val, ll mod) {\r\n  if (mod == 0) return 0;\r\n  mod = abs(mod);\r\
    \n  val %= mod;\r\n  if (val < 0) val += mod;\r\n  ll a = val, b = mod, u = 1,\
    \ v = 0, t;\r\n  while (b > 0) {\r\n    t = a / b;\r\n    swap(a -= t * b, b),\
    \ swap(u -= t * v, v);\r\n  }\r\n  if (u < 0) u += mod;\r\n  return u;\r\n}\r\n\
    #line 2 \"mod/crt3.hpp\"\n\nconstexpr u32 mod_pow_constexpr(u64 a, u64 n, u32\
    \ mod) {\n  a %= mod;\n  u64 res = 1;\n  FOR(32) {\n    if (n & 1) res = res *\
    \ a % mod;\n    a = a * a % mod, n /= 2;\n  }\n  return res;\n}\n\ntemplate <typename\
    \ T, u32 p0, u32 p1>\nT CRT2(u64 a0, u64 a1) {\n  static_assert(p0 < p1);\n  static\
    \ constexpr u64 x0_1 = mod_pow_constexpr(p0, p1 - 2, p1);\n  u64 c = (a1 - a0\
    \ + p1) * x0_1 % p1;\n  return a0 + c * p0;\n}\n\ntemplate <typename T, u32 p0,\
    \ u32 p1, u32 p2>\nT CRT3(u64 a0, u64 a1, u64 a2) {\n  static_assert(p0 < p1 &&\
    \ p1 < p2);\n  static constexpr u64 x1 = mod_pow_constexpr(p0, p1 - 2, p1);\n\
    \  static constexpr u64 x2 = mod_pow_constexpr(u64(p0) * p1 % p2, p2 - 2, p2);\n\
    \  static constexpr u64 p01 = u64(p0) * p1;\n  u64 c = (a1 - a0 + p1) * x1 % p1;\n\
    \  u64 ans_1 = a0 + c * p0;\n  c = (a2 - ans_1 % p2 + p2) * x2 % p2;\n  return\
    \ T(ans_1) + T(c) * T(p01);\n}\n\ntemplate <typename T, u32 p0, u32 p1, u32 p2,\
    \ u32 p3>\nT CRT4(u64 a0, u64 a1, u64 a2, u64 a3) {\n  static_assert(p0 < p1 &&\
    \ p1 < p2 && p2 < p3);\n  static constexpr u64 x1 = mod_pow_constexpr(p0, p1 -\
    \ 2, p1);\n  static constexpr u64 x2 = mod_pow_constexpr(u64(p0) * p1 % p2, p2\
    \ - 2, p2);\n  static constexpr u64 x3 = mod_pow_constexpr(u64(p0) * p1 % p3 *\
    \ p2 % p3, p3 - 2, p3);\n  static constexpr u64 p01 = u64(p0) * p1;\n  u64 c =\
    \ (a1 - a0 + p1) * x1 % p1;\n  u64 ans_1 = a0 + c * p0;\n  c = (a2 - ans_1 % p2\
    \ + p2) * x2 % p2;\n  u128 ans_2 = ans_1 + c * static_cast<u128>(p01);\n  c =\
    \ (a3 - ans_2 % p3 + p3) * x3 % p3;\n  return T(ans_2) + T(c) * T(p01) * T(p2);\n\
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
    }\r\n#line 5 \"poly/lagrange_interpolate_iota.hpp\"\n\r\n// Input: f(0), ...,\
    \ f(n-1) and c. Return: f(c)\r\ntemplate <typename T, typename enable_if<has_mod<T>::value>::type\
    \ * = nullptr>\r\nT lagrange_interpolate_iota(vc<T> &f, T c) {\r\n  int n = len(f);\r\
    \n  if (int(c.val) < n) return f[c.val];\r\n  auto a = f;\r\n  FOR(i, n) {\r\n\
    \    a[i] = a[i] * fact_inv<T>(i) * fact_inv<T>(n - 1 - i);\r\n    if ((n - 1\
    \ - i) & 1) a[i] = -a[i];\r\n  }\r\n  vc<T> lp(n + 1), rp(n + 1);\r\n  lp[0] =\
    \ rp[n] = 1;\r\n  FOR(i, n) lp[i + 1] = lp[i] * (c - i);\r\n  FOR_R(i, n) rp[i]\
    \ = rp[i + 1] * (c - i);\r\n  T ANS = 0;\r\n  FOR(i, n) ANS += a[i] * lp[i] *\
    \ rp[i + 1];\r\n  return ANS;\r\n}\r\n\r\n// mod \u3058\u3083\u306A\u3044\u5834\
    \u5408\u3002\u304B\u306A\u308A\u4F4E\u6B21\u306E\u591A\u9805\u5F0F\u3092\u60F3\
    \u5B9A\u3057\u3066\u3044\u308B\u3002O(n^2)\r\n// Input: f(0), ..., f(n-1) and\
    \ c. Return: f(c)\r\ntemplate <typename T, typename enable_if<!has_mod<T>::value>::type\
    \ * = nullptr>\r\nT lagrange_interpolate_iota(vc<T> &f, T c) {\r\n  const int\
    \ LIM = 10;\r\n  int n = len(f);\r\n  assert(n < LIM);\r\n\r\n  // (-1)^{i-j}\
    \ binom(i,j)\r\n  static vvc<int> C;\r\n  if (C.empty()) {\r\n    C.assign(LIM,\
    \ vc<int>(LIM));\r\n    C[0][0] = 1;\r\n    FOR(n, 1, LIM) FOR(k, n + 1) {\r\n\
    \      C[n][k] += C[n - 1][k];\r\n      if (k) C[n][k] += C[n - 1][k - 1];\r\n\
    \    }\r\n    FOR(n, LIM) FOR(k, n + 1) if ((n + k) % 2) C[n][k] = -C[n][k];\r\
    \n  }\r\n  // f(x) = sum a_i binom(x,i)\r\n  vc<T> a(n);\r\n  FOR(i, n) FOR(j,\
    \ i + 1) { a[i] += f[j] * C[i][j]; }\r\n\r\n  T res = 0;\r\n  T b = 1;\r\n  FOR(i,\
    \ n) {\r\n    res += a[i] * b;\r\n    b = b * (c - i) / (1 + i);\r\n  }\r\n  return\
    \ res;\r\n}\r\n\r\n// Input: f(0), ..., f(n-1) and c, m\r\n// Return: f(c), f(c+1),\
    \ ..., f(c+m-1)\r\n// Complexity: M(n, n + m)\r\ntemplate <typename mint>\r\n\
    vc<mint> lagrange_interpolate_iota(vc<mint> &f, mint c, int m) {\r\n  if (m <=\
    \ 60) {\r\n    vc<mint> ANS(m);\r\n    FOR(i, m) ANS[i] = lagrange_interpolate_iota(f,\
    \ c + mint(i));\r\n    return ANS;\r\n  }\r\n  ll n = len(f);\r\n  auto a = f;\r\
    \n  FOR(i, n) {\r\n    a[i] = a[i] * fact_inv<mint>(i) * fact_inv<mint>(n - 1\
    \ - i);\r\n    if ((n - 1 - i) & 1) a[i] = -a[i];\r\n  }\r\n  // x = c, c+1, ...\
    \ \u306B\u5BFE\u3057\u3066 a0/x + a1/(x-1) + ... \u3092\u6C42\u3081\u3066\u304A\
    \u304F\r\n  vc<mint> b(n + m - 1);\r\n  FOR(i, n + m - 1) b[i] = mint(1) / (c\
    \ + mint(i - n + 1));\r\n  a = convolution(a, b);\r\n\r\n  Sliding_Window_Aggregation<Monoid_Mul<mint>>\
    \ swag;\r\n  vc<mint> ANS(m);\r\n  ll L = 0, R = 0;\r\n  FOR(i, m) {\r\n    while\
    \ (L < i) { swag.pop(), ++L; }\r\n    while (R - L < n) { swag.push(c + mint((R++)\
    \ - n + 1)); }\r\n    auto coef = swag.prod();\r\n    if (coef == 0) {\r\n   \
    \   ANS[i] = f[(c + i).val];\r\n    } else {\r\n      ANS[i] = a[i + n - 1] *\
    \ coef;\r\n    }\r\n  }\r\n  return ANS;\r\n}\r\n"
  code: "#pragma once\r\n#include \"alg/monoid/mul.hpp\"\r\n#include \"ds/sliding_window_aggregation.hpp\"\
    \r\n#include \"poly/convolution.hpp\"\r\n\r\n// Input: f(0), ..., f(n-1) and c.\
    \ Return: f(c)\r\ntemplate <typename T, typename enable_if<has_mod<T>::value>::type\
    \ * = nullptr>\r\nT lagrange_interpolate_iota(vc<T> &f, T c) {\r\n  int n = len(f);\r\
    \n  if (int(c.val) < n) return f[c.val];\r\n  auto a = f;\r\n  FOR(i, n) {\r\n\
    \    a[i] = a[i] * fact_inv<T>(i) * fact_inv<T>(n - 1 - i);\r\n    if ((n - 1\
    \ - i) & 1) a[i] = -a[i];\r\n  }\r\n  vc<T> lp(n + 1), rp(n + 1);\r\n  lp[0] =\
    \ rp[n] = 1;\r\n  FOR(i, n) lp[i + 1] = lp[i] * (c - i);\r\n  FOR_R(i, n) rp[i]\
    \ = rp[i + 1] * (c - i);\r\n  T ANS = 0;\r\n  FOR(i, n) ANS += a[i] * lp[i] *\
    \ rp[i + 1];\r\n  return ANS;\r\n}\r\n\r\n// mod \u3058\u3083\u306A\u3044\u5834\
    \u5408\u3002\u304B\u306A\u308A\u4F4E\u6B21\u306E\u591A\u9805\u5F0F\u3092\u60F3\
    \u5B9A\u3057\u3066\u3044\u308B\u3002O(n^2)\r\n// Input: f(0), ..., f(n-1) and\
    \ c. Return: f(c)\r\ntemplate <typename T, typename enable_if<!has_mod<T>::value>::type\
    \ * = nullptr>\r\nT lagrange_interpolate_iota(vc<T> &f, T c) {\r\n  const int\
    \ LIM = 10;\r\n  int n = len(f);\r\n  assert(n < LIM);\r\n\r\n  // (-1)^{i-j}\
    \ binom(i,j)\r\n  static vvc<int> C;\r\n  if (C.empty()) {\r\n    C.assign(LIM,\
    \ vc<int>(LIM));\r\n    C[0][0] = 1;\r\n    FOR(n, 1, LIM) FOR(k, n + 1) {\r\n\
    \      C[n][k] += C[n - 1][k];\r\n      if (k) C[n][k] += C[n - 1][k - 1];\r\n\
    \    }\r\n    FOR(n, LIM) FOR(k, n + 1) if ((n + k) % 2) C[n][k] = -C[n][k];\r\
    \n  }\r\n  // f(x) = sum a_i binom(x,i)\r\n  vc<T> a(n);\r\n  FOR(i, n) FOR(j,\
    \ i + 1) { a[i] += f[j] * C[i][j]; }\r\n\r\n  T res = 0;\r\n  T b = 1;\r\n  FOR(i,\
    \ n) {\r\n    res += a[i] * b;\r\n    b = b * (c - i) / (1 + i);\r\n  }\r\n  return\
    \ res;\r\n}\r\n\r\n// Input: f(0), ..., f(n-1) and c, m\r\n// Return: f(c), f(c+1),\
    \ ..., f(c+m-1)\r\n// Complexity: M(n, n + m)\r\ntemplate <typename mint>\r\n\
    vc<mint> lagrange_interpolate_iota(vc<mint> &f, mint c, int m) {\r\n  if (m <=\
    \ 60) {\r\n    vc<mint> ANS(m);\r\n    FOR(i, m) ANS[i] = lagrange_interpolate_iota(f,\
    \ c + mint(i));\r\n    return ANS;\r\n  }\r\n  ll n = len(f);\r\n  auto a = f;\r\
    \n  FOR(i, n) {\r\n    a[i] = a[i] * fact_inv<mint>(i) * fact_inv<mint>(n - 1\
    \ - i);\r\n    if ((n - 1 - i) & 1) a[i] = -a[i];\r\n  }\r\n  // x = c, c+1, ...\
    \ \u306B\u5BFE\u3057\u3066 a0/x + a1/(x-1) + ... \u3092\u6C42\u3081\u3066\u304A\
    \u304F\r\n  vc<mint> b(n + m - 1);\r\n  FOR(i, n + m - 1) b[i] = mint(1) / (c\
    \ + mint(i - n + 1));\r\n  a = convolution(a, b);\r\n\r\n  Sliding_Window_Aggregation<Monoid_Mul<mint>>\
    \ swag;\r\n  vc<mint> ANS(m);\r\n  ll L = 0, R = 0;\r\n  FOR(i, m) {\r\n    while\
    \ (L < i) { swag.pop(), ++L; }\r\n    while (R - L < n) { swag.push(c + mint((R++)\
    \ - n + 1)); }\r\n    auto coef = swag.prod();\r\n    if (coef == 0) {\r\n   \
    \   ANS[i] = f[(c + i).val];\r\n    } else {\r\n      ANS[i] = a[i + n - 1] *\
    \ coef;\r\n    }\r\n  }\r\n  return ANS;\r\n}\r\n"
  dependsOn:
  - alg/monoid/mul.hpp
  - ds/sliding_window_aggregation.hpp
  - poly/convolution.hpp
  - mod/modint.hpp
  - mod/modint_common.hpp
  - mod/mod_inv.hpp
  - mod/crt3.hpp
  - poly/convolution_naive.hpp
  - poly/convolution_karatsuba.hpp
  - poly/ntt.hpp
  isVerificationFile: false
  path: poly/lagrange_interpolate_iota.hpp
  requiredBy:
  - poly/from_log_differentiation.hpp
  - poly/sparse_exp_of_div.hpp
  - poly/prefix_product_of_poly.hpp
  - seq/interpolate_poly_exp_sum.hpp
  - seq/kth_term_of_p_recursive.hpp
  timestamp: '2024-11-01 21:56:32+09:00'
  verificationStatus: LIBRARY_SOME_WA
  verifiedWith:
  - test/3_yukicoder/1080_2.test.cpp
  - test/3_yukicoder/2747.test.cpp
  - test/3_yukicoder/502_2.test.cpp
  - test/3_yukicoder/2166.test.cpp
  - test/5_atcoder/abc276_g_2.test.cpp
  - test/5_atcoder/abc222h_2.test.cpp
  - test/5_atcoder/abc276_g.test.cpp
  - test/1_mytest/factorial_998.test.cpp
  - test/2_library_checker/enumerative_combinatorics/factorial.test.cpp
  - test/2_library_checker/other/sum_of_exp_times_poly.test.cpp
  - test/2_library_checker/polynomial/shift_of_sampling_points_of_polynomial.test.cpp
documentation_of: poly/lagrange_interpolate_iota.hpp
layout: document
redirect_from:
- /library/poly/lagrange_interpolate_iota.hpp
- /library/poly/lagrange_interpolate_iota.hpp.html
title: poly/lagrange_interpolate_iota.hpp
---
