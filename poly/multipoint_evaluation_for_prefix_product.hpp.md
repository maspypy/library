---
data:
  _extendedDependsOn:
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
    path: other/bit.hpp
    title: other/bit.hpp
  - icon: ':heavy_check_mark:'
    path: poly/convolution.hpp
    title: poly/convolution.hpp
  - icon: ':heavy_check_mark:'
    path: poly/convolution_all.hpp
    title: poly/convolution_all.hpp
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
    path: poly/fps_div.hpp
    title: poly/fps_div.hpp
  - icon: ':heavy_check_mark:'
    path: poly/fps_inv.hpp
    title: poly/fps_inv.hpp
  - icon: ':heavy_check_mark:'
    path: poly/middle_product.hpp
    title: poly/middle_product.hpp
  - icon: ':heavy_check_mark:'
    path: poly/ntt.hpp
    title: poly/ntt.hpp
  - icon: ':heavy_check_mark:'
    path: poly/ntt_doubling.hpp
    title: poly/ntt_doubling.hpp
  - icon: ':heavy_check_mark:'
    path: poly/typical_divide_conquer.hpp
    title: poly/typical_divide_conquer.hpp
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/1_mytest/multipoint_prefix.test.cpp
    title: test/1_mytest/multipoint_prefix.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 1 \"poly/convolution.hpp\"\n\n#line 1 \"mod/modint_common.hpp\"\
    \n\n#line 1 \"other/bit.hpp\"\n\nint popcnt(int x) { return __builtin_popcount(x);\
    \ }\nint popcnt(u32 x) { return __builtin_popcount(x); }\nint popcnt(ll x) { return\
    \ __builtin_popcountll(x); }\nint popcnt(u64 x) { return __builtin_popcountll(x);\
    \ }\nint popcnt_sgn(int x) { return (__builtin_parity(unsigned(x)) & 1 ? -1 :\
    \ 1); }\nint popcnt_sgn(u32 x) { return (__builtin_parity(x) & 1 ? -1 : 1); }\n\
    int popcnt_sgn(ll x) { return (__builtin_parityll(x) & 1 ? -1 : 1); }\nint popcnt_sgn(u64\
    \ x) { return (__builtin_parityll(x) & 1 ? -1 : 1); }\n// (0, 1, 2, 3, 4) -> (-1,\
    \ 0, 1, 1, 2)\nint topbit(int x) { return (x == 0 ? -1 : 31 - __builtin_clz(x));\
    \ }\nint topbit(u32 x) { return (x == 0 ? -1 : 31 - __builtin_clz(x)); }\nint\
    \ topbit(ll x) { return (x == 0 ? -1 : 63 - __builtin_clzll(x)); }\nint topbit(u64\
    \ x) { return (x == 0 ? -1 : 63 - __builtin_clzll(x)); }\n// (0, 1, 2, 3, 4) ->\
    \ (-1, 0, 1, 0, 2)\nint lowbit(int x) { return (x == 0 ? -1 : __builtin_ctz(x));\
    \ }\nint lowbit(u32 x) { return (x == 0 ? -1 : __builtin_ctz(x)); }\nint lowbit(ll\
    \ x) { return (x == 0 ? -1 : __builtin_ctzll(x)); }\nint lowbit(u64 x) { return\
    \ (x == 0 ? -1 : __builtin_ctzll(x)); }\n\ntemplate <typename T>\nT kth_bit(int\
    \ k) {\n  return T(1) << k;\n}\ntemplate <typename T>\nbool has_kth_bit(T x, int\
    \ k) {\n  return x >> k & 1;\n}\n\ntemplate <typename UINT>\nstruct all_bit {\n\
    \  UINT s;\n  all_bit(UINT s) : s(s) {}\n  struct iter {\n    UINT s;\n    int\
    \ operator*() const { return lowbit(s); }\n    void operator++() { s &= s - 1;\
    \ }\n    bool operator!=(nullptr_t) const { return s; }\n  };\n  iter begin()\
    \ const { return {s}; }\n  nullptr_t end() const { return nullptr; }\n};\n\ntemplate\
    \ <typename UINT>\nstruct all_subset {\n  UINT s;\n  all_subset(UINT s) : s(s)\
    \ {}\n  struct iter {\n    UINT s, t;\n    bool done = false;\n    UINT operator*()\
    \ const { return t; }\n    void operator++() {\n      done = (t == 0);\n     \
    \ t = (t - 1) & s;\n    }\n    bool operator!=(nullptr_t) const { return !done;\
    \ }\n  };\n  iter begin() const { return {s, s}; }\n  nullptr_t end() const {\
    \ return nullptr; }\n};\n\nconstexpr u64 full_mask(int n) { return n == 64 ? -1ULL\
    \ : (1ULL << n) - 1; }\n#line 3 \"mod/modint_common.hpp\"\n\nstruct has_mod_impl\
    \ {\n  template <class T>\n  static auto check(T &&x) -> decltype(x.get_mod(),\
    \ std::true_type{});\n  template <class T>\n  static auto check(...) -> std::false_type;\n\
    };\n\ntemplate <class T>\nclass has_mod : public decltype(has_mod_impl::check<T>(std::declval<T>()))\
    \ {};\n\ntemplate <typename mint>\nmint fact(int n) {\n  static const int mod\
    \ = mint::get_mod();\n  assert(0 <= n && n < mod);\n  static vector<mint> dat\
    \ = {1, 1};\n  if (len(dat) <= n) {\n    int now = len(dat);\n    int m = min(mod,\
    \ 1 << (topbit(n) + 1));\n    dat.resize(m);\n    FOR(i, now, m) dat[i] = dat[i\
    \ - 1] * mint::raw(i);\n  }\n  return dat[n];\n}\n\ntemplate <typename mint>\n\
    mint fact_inv(int n) {\n  static const int mod = mint::get_mod();\n  static vector<mint>\
    \ dat = {1, 1};\n  if (n < 0) return mint(0);\n  if (len(dat) <= n) {\n    int\
    \ now = len(dat);\n    int m = min(mod, 1 << (topbit(n) + 1));\n    dat.resize(m);\n\
    \    dat[m - 1] = fact<mint>(m - 1).inverse();\n    FOR_R(i, now, m - 1) dat[i]\
    \ = dat[i + 1] * mint::raw(i + 1);\n  }\n  return dat[n];\n}\n\ntemplate <class\
    \ mint, class... Ts>\nmint fact_invs(Ts... xs) {\n  return (mint(1) * ... * fact_inv<mint>(xs));\n\
    }\n\ntemplate <typename mint>\nmint inv(int n) {\n  static const int mod = mint::get_mod();\n\
    \  assert(1 <= n && n < mod);\n  return fact<mint>(n - 1) * fact_inv<mint>(n);\n\
    }\n\ntemplate <>\ndouble inv<double>(int n) {\n  assert(n != 0);\n  return 1.0\
    \ / n;\n}\n\ntemplate <typename mint, class Head, class... Tail>\nmint multinomial(Head\
    \ &&head, Tail &&...tail) {\n  return fact<mint>(head) * fact_invs<mint>(std::forward<Tail>(tail)...);\n\
    }\n\ntemplate <typename mint>\nmint C_dense(int n, int k) {\n  assert(n >= 0);\n\
    \  if (k < 0 || n < k) return 0;\n  static vvc<mint> C;\n  static int H = 0, W\
    \ = 0;\n  auto calc = [&](int i, int j) -> mint {\n    if (i == 0) return (j ==\
    \ 0 ? mint(1) : mint(0));\n    return C[i - 1][j] + (j ? C[i - 1][j - 1] : 0);\n\
    \  };\n  if (W <= k) {\n    FOR(i, H) {\n      C[i].resize(k + 1);\n      FOR(j,\
    \ W, k + 1) { C[i][j] = calc(i, j); }\n    }\n    W = k + 1;\n  }\n  if (H <=\
    \ n) {\n    C.resize(n + 1);\n    FOR(i, H, n + 1) {\n      C[i].resize(W);\n\
    \      FOR(j, W) { C[i][j] = calc(i, j); }\n    }\n    H = n + 1;\n  }\n  return\
    \ C[n][k];\n}\n\ntemplate <typename mint, bool large = false, bool dense = false>\n\
    mint C(ll n, ll k) {\n  assert(n >= 0);\n  if (k < 0 || n < k) return 0;\n  if\
    \ constexpr (dense) return C_dense<mint>(n, k);\n  if constexpr (!large) return\
    \ multinomial<mint>(n, k, n - k);\n  k = min(k, n - k);\n  mint x(1);\n  FOR(i,\
    \ k) x *= mint(n - i);\n  return x * fact_inv<mint>(k);\n}\n\ntemplate <typename\
    \ mint, bool large = false>\nmint C_inv(ll n, ll k) {\n  assert(n >= 0);\n  assert(0\
    \ <= k && k <= n);\n  if (!large) return fact_inv<mint>(n) * fact<mint>(k) * fact<mint>(n\
    \ - k);\n  return mint(1) / C<mint, 1>(n, k);\n}\n\n// [x^d](1-x)^{-n}\ntemplate\
    \ <typename mint, bool large = false, bool dense = false>\nmint C_negative(ll\
    \ n, ll d) {\n  assert(n >= 0);\n  if (d < 0) return mint(0);\n  if (n == 0) {\n\
    \    return (d == 0 ? mint(1) : mint(0));\n  }\n  return C<mint, large, dense>(n\
    \ + d - 1, d);\n}\n#line 2 \"mod/modint.hpp\"\n\ntemplate <int mod>\nstruct modint\
    \ {\n  static constexpr u32 umod = u32(mod);\n  static_assert(0 < umod && umod\
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
    \ return modint(u);\n  }\n  modint pow(ll n) const {\n    if (n < 0) return inverse().pow(-n);\n\
    \    assert(n >= 0);\n    modint ret(1), mul(val);\n    while (n > 0) {\n    \
    \  if (n & 1) ret *= mul;\n      mul *= mul;\n      n >>= 1;\n    }\n    return\
    \ ret;\n  }\n  static constexpr int get_mod() { return mod; }\n  // (n, r), r\
    \ \u306F 1 \u306E 2^n \u4E57\u6839\n  static constexpr pair<int, int> ntt_info()\
    \ {\n    if (mod == 120586241) return {20, 74066978};\n    if (mod == 167772161)\
    \ return {25, 17};\n    if (mod == 469762049) return {26, 30};\n    if (mod ==\
    \ 754974721) return {24, 362};\n    if (mod == 880803841) return {23, 211};\n\
    \    if (mod == 943718401) return {22, 663003469};\n    if (mod == 998244353)\
    \ return {23, 31};\n    if (mod == 1004535809) return {21, 582313106};\n    if\
    \ (mod == 1012924417) return {21, 368093570};\n    if (mod == 1224736769) return\
    \ {24, 1191450770};\n    if (mod == 2013265921) return {27, 244035102};\n    return\
    \ {-1, -1};\n  }\n  static constexpr bool can_ntt() { return ntt_info().fi !=\
    \ -1; }\n};\n\n#ifdef FASTIO\ntemplate <int mod>\nvoid rd(modint<mod> &x) {\n\
    \  fastio::rd(x.val);\n  x.val %= mod;\n  // assert(0 <= x.val && x.val < mod);\n\
    }\ntemplate <int mod>\nvoid wt(modint<mod> x) {\n  fastio::wt(x.val);\n}\n#endif\n\
    \nusing modint107 = modint<1000000007>;\nusing modint998 = modint<998244353>;\n\
    #line 1 \"mod/mod_inv.hpp\"\n\n// long \u3067\u3082\u5927\u4E08\u592B\n// (val\
    \ * x - 1) \u304C mod \u306E\u500D\u6570\u306B\u306A\u308B\u3088\u3046\u306B\u3059\
    \u308B\n// \u7279\u306B mod=0 \u306A\u3089 x=0 \u304C\u6E80\u305F\u3059\nll mod_inv(ll\
    \ val, ll mod) {\n  if (mod == 0) return 0;\n  mod = abs(mod);\n  val %= mod;\n\
    \  if (val < 0) val += mod;\n  ll a = val, b = mod, u = 1, v = 0, t;\n  while\
    \ (b > 0) {\n    t = a / b;\n    swap(a -= t * b, b), swap(u -= t * v, v);\n \
    \ }\n  if (u < 0) u += mod;\n  return u;\n}\n#line 1 \"mod/crt3.hpp\"\n\nconstexpr\
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
    \ T(ans_3) + T(c) * T(p01) * T(p23);\n}\n#line 1 \"poly/convolution_naive.hpp\"\
    \n\ntemplate <class T, typename enable_if<!has_mod<T>::value>::type* = nullptr>\n\
    vc<T> convolution_naive(const vc<T>& a, const vc<T>& b) {\n  int n = int(a.size()),\
    \ m = int(b.size());\n  if (n > m) return convolution_naive<T>(b, a);\n  if (n\
    \ == 0) return {};\n  vector<T> ans(n + m - 1);\n  FOR(i, n) FOR(j, m) ans[i +\
    \ j] += a[i] * b[j];\n  return ans;\n}\n\ntemplate <class T, typename enable_if<has_mod<T>::value>::type*\
    \ = nullptr>\nvc<T> convolution_naive(const vc<T>& a, const vc<T>& b) {\n  int\
    \ n = int(a.size()), m = int(b.size());\n  if (n > m) return convolution_naive<T>(b,\
    \ a);\n  if (n == 0) return {};\n  vc<T> ans(n + m - 1);\n  if (n <= 16 && (T::get_mod()\
    \ < (1 << 30))) {\n    for (int k = 0; k < n + m - 1; ++k) {\n      int s = max(0,\
    \ k - m + 1);\n      int t = min(n, k + 1);\n      u64 sm = 0;\n      for (int\
    \ i = s; i < t; ++i) { sm += u64(a[i].val) * (b[k - i].val); }\n      ans[k] =\
    \ sm;\n    }\n  } else {\n    for (int k = 0; k < n + m - 1; ++k) {\n      int\
    \ s = max(0, k - m + 1);\n      int t = min(n, k + 1);\n      u128 sm = 0;\n \
    \     for (int i = s; i < t; ++i) { sm += u64(a[i].val) * (b[k - i].val); }\n\
    \      ans[k] = T::raw(sm % T::get_mod());\n    }\n  }\n  return ans;\n}\n#line\
    \ 1 \"poly/convolution_naive.hpp\"\n\ntemplate <class T, typename enable_if<!has_mod<T>::value>::type*\
    \ = nullptr>\nvc<T> convolution_naive(const vc<T>& a, const vc<T>& b) {\n  int\
    \ n = int(a.size()), m = int(b.size());\n  if (n > m) return convolution_naive<T>(b,\
    \ a);\n  if (n == 0) return {};\n  vector<T> ans(n + m - 1);\n  FOR(i, n) FOR(j,\
    \ m) ans[i + j] += a[i] * b[j];\n  return ans;\n}\n\ntemplate <class T, typename\
    \ enable_if<has_mod<T>::value>::type* = nullptr>\nvc<T> convolution_naive(const\
    \ vc<T>& a, const vc<T>& b) {\n  int n = int(a.size()), m = int(b.size());\n \
    \ if (n > m) return convolution_naive<T>(b, a);\n  if (n == 0) return {};\n  vc<T>\
    \ ans(n + m - 1);\n  if (n <= 16 && (T::get_mod() < (1 << 30))) {\n    for (int\
    \ k = 0; k < n + m - 1; ++k) {\n      int s = max(0, k - m + 1);\n      int t\
    \ = min(n, k + 1);\n      u64 sm = 0;\n      for (int i = s; i < t; ++i) { sm\
    \ += u64(a[i].val) * (b[k - i].val); }\n      ans[k] = sm;\n    }\n  } else {\n\
    \    for (int k = 0; k < n + m - 1; ++k) {\n      int s = max(0, k - m + 1);\n\
    \      int t = min(n, k + 1);\n      u128 sm = 0;\n      for (int i = s; i < t;\
    \ ++i) { sm += u64(a[i].val) * (b[k - i].val); }\n      ans[k] = T::raw(sm % T::get_mod());\n\
    \    }\n  }\n  return ans;\n}\n#line 2 \"poly/convolution_karatsuba.hpp\"\n\n\
    // \u4EFB\u610F\u306E\u74B0\u3067\u3067\u304D\u308B\ntemplate <typename T>\nvc<T>\
    \ convolution_karatsuba(const vc<T>& f, const vc<T>& g) {\n  const int thresh\
    \ = 30;\n  if (min(len(f), len(g)) <= thresh) return convolution_naive(f, g);\n\
    \  int n = max(len(f), len(g));\n  int m = ceil(n, 2);\n  vc<T> f1, f2, g1, g2;\n\
    \  if (len(f) < m) f1 = f;\n  if (len(f) >= m) f1 = {f.begin(), f.begin() + m};\n\
    \  if (len(f) >= m) f2 = {f.begin() + m, f.end()};\n  if (len(g) < m) g1 = g;\n\
    \  if (len(g) >= m) g1 = {g.begin(), g.begin() + m};\n  if (len(g) >= m) g2 =\
    \ {g.begin() + m, g.end()};\n  vc<T> a = convolution_karatsuba(f1, g1);\n  vc<T>\
    \ b = convolution_karatsuba(f2, g2);\n  FOR(i, len(f2)) f1[i] += f2[i];\n  FOR(i,\
    \ len(g2)) g1[i] += g2[i];\n  vc<T> c = convolution_karatsuba(f1, g1);\n  vc<T>\
    \ F(len(f) + len(g) - 1);\n  assert(2 * m + len(b) <= len(F));\n  FOR(i, len(a))\
    \ F[i] += a[i], c[i] -= a[i];\n  FOR(i, len(b)) F[2 * m + i] += b[i], c[i] -=\
    \ b[i];\n  if (c.back() == T(0)) c.pop_back();\n  FOR(i, len(c)) if (c[i] != T(0))\
    \ F[m + i] += c[i];\n  return F;\n}\n#line 1 \"other/bit.hpp\"\n\nint popcnt(int\
    \ x) { return __builtin_popcount(x); }\nint popcnt(u32 x) { return __builtin_popcount(x);\
    \ }\nint popcnt(ll x) { return __builtin_popcountll(x); }\nint popcnt(u64 x) {\
    \ return __builtin_popcountll(x); }\nint popcnt_sgn(int x) { return (__builtin_parity(unsigned(x))\
    \ & 1 ? -1 : 1); }\nint popcnt_sgn(u32 x) { return (__builtin_parity(x) & 1 ?\
    \ -1 : 1); }\nint popcnt_sgn(ll x) { return (__builtin_parityll(x) & 1 ? -1 :\
    \ 1); }\nint popcnt_sgn(u64 x) { return (__builtin_parityll(x) & 1 ? -1 : 1);\
    \ }\n// (0, 1, 2, 3, 4) -> (-1, 0, 1, 1, 2)\nint topbit(int x) { return (x ==\
    \ 0 ? -1 : 31 - __builtin_clz(x)); }\nint topbit(u32 x) { return (x == 0 ? -1\
    \ : 31 - __builtin_clz(x)); }\nint topbit(ll x) { return (x == 0 ? -1 : 63 - __builtin_clzll(x));\
    \ }\nint topbit(u64 x) { return (x == 0 ? -1 : 63 - __builtin_clzll(x)); }\n//\
    \ (0, 1, 2, 3, 4) -> (-1, 0, 1, 0, 2)\nint lowbit(int x) { return (x == 0 ? -1\
    \ : __builtin_ctz(x)); }\nint lowbit(u32 x) { return (x == 0 ? -1 : __builtin_ctz(x));\
    \ }\nint lowbit(ll x) { return (x == 0 ? -1 : __builtin_ctzll(x)); }\nint lowbit(u64\
    \ x) { return (x == 0 ? -1 : __builtin_ctzll(x)); }\n\ntemplate <typename T>\n\
    T kth_bit(int k) {\n  return T(1) << k;\n}\ntemplate <typename T>\nbool has_kth_bit(T\
    \ x, int k) {\n  return x >> k & 1;\n}\n\ntemplate <typename UINT>\nstruct all_bit\
    \ {\n  UINT s;\n  all_bit(UINT s) : s(s) {}\n  struct iter {\n    UINT s;\n  \
    \  int operator*() const { return lowbit(s); }\n    void operator++() { s &= s\
    \ - 1; }\n    bool operator!=(nullptr_t) const { return s; }\n  };\n  iter begin()\
    \ const { return {s}; }\n  nullptr_t end() const { return nullptr; }\n};\n\ntemplate\
    \ <typename UINT>\nstruct all_subset {\n  UINT s;\n  all_subset(UINT s) : s(s)\
    \ {}\n  struct iter {\n    UINT s, t;\n    bool done = false;\n    UINT operator*()\
    \ const { return t; }\n    void operator++() {\n      done = (t == 0);\n     \
    \ t = (t - 1) & s;\n    }\n    bool operator!=(nullptr_t) const { return !done;\
    \ }\n  };\n  iter begin() const { return {s, s}; }\n  nullptr_t end() const {\
    \ return nullptr; }\n};\n\nconstexpr u64 full_mask(int n) { return n == 64 ? -1ULL\
    \ : (1ULL << n) - 1; }\n#line 2 \"poly/ntt.hpp\"\n\ntemplate <class mint>\nvoid\
    \ ntt(vector<mint>& a, bool inverse) {\n  assert(mint::can_ntt());\n  const int\
    \ rank2 = mint::ntt_info().fi;\n  const u32 mod = mint::get_mod();\n  static array<mint,\
    \ 30> root, iroot;\n  static array<mint, 30> rate2, irate2;\n  static array<mint,\
    \ 30> rate3, irate3;\n\n  assert(rank2 != -1 && len(a) <= (1 << max(0, rank2)));\n\
    \n  static bool prepared = 0;\n  if (!prepared) {\n    prepared = 1;\n    root[rank2]\
    \ = mint::ntt_info().se;\n    iroot[rank2] = mint(1) / root[rank2];\n    FOR_R(i,\
    \ rank2) {\n      root[i] = root[i + 1] * root[i + 1];\n      iroot[i] = iroot[i\
    \ + 1] * iroot[i + 1];\n    }\n    mint prod = 1, iprod = 1;\n    for (int i =\
    \ 0; i <= rank2 - 2; i++) {\n      rate2[i] = root[i + 2] * prod;\n      irate2[i]\
    \ = iroot[i + 2] * iprod;\n      prod *= iroot[i + 2];\n      iprod *= root[i\
    \ + 2];\n    }\n    prod = 1, iprod = 1;\n    for (int i = 0; i <= rank2 - 3;\
    \ i++) {\n      rate3[i] = root[i + 3] * prod;\n      irate3[i] = iroot[i + 3]\
    \ * iprod;\n      prod *= iroot[i + 3];\n      iprod *= root[i + 3];\n    }\n\
    \  }\n\n  int n = int(a.size());\n  int h = topbit(n);\n  assert(n == 1 << h);\n\
    \  if (!inverse) {\n    int len = 0;\n    while (len < h) {\n      if (h - len\
    \ == 1) {\n        int p = 1 << (h - len - 1);\n        mint rot = 1;\n      \
    \  FOR(s, 1 << len) {\n          int offset = s << (h - len);\n          FOR(i,\
    \ p) {\n            auto l = a[i + offset];\n            auto r = a[i + offset\
    \ + p] * rot;\n            a[i + offset] = l + r;\n            a[i + offset +\
    \ p] = l - r;\n          }\n          rot *= rate2[topbit(~s & -~s)];\n      \
    \  }\n        len++;\n      } else {\n        int p = 1 << (h - len - 2);\n  \
    \      mint rot = 1, imag = root[2];\n        for (int s = 0; s < (1 << len);\
    \ s++) {\n          mint rot2 = rot * rot;\n          mint rot3 = rot2 * rot;\n\
    \          int offset = s << (h - len);\n          for (int i = 0; i < p; i++)\
    \ {\n            u64 mod2 = u64(mod) * mod;\n            u64 a0 = a[i + offset].val;\n\
    \            u64 a1 = u64(a[i + offset + p].val) * rot.val;\n            u64 a2\
    \ = u64(a[i + offset + 2 * p].val) * rot2.val;\n            u64 a3 = u64(a[i +\
    \ offset + 3 * p].val) * rot3.val;\n            u64 a1na3imag = (a1 + mod2 - a3)\
    \ % mod * imag.val;\n            u64 na2 = mod2 - a2;\n            a[i + offset]\
    \ = a0 + a2 + a1 + a3;\n            a[i + offset + 1 * p] = a0 + a2 + (2 * mod2\
    \ - (a1 + a3));\n            a[i + offset + 2 * p] = a0 + na2 + a1na3imag;\n \
    \           a[i + offset + 3 * p] = a0 + na2 + (mod2 - a1na3imag);\n         \
    \ }\n          rot *= rate3[topbit(~s & -~s)];\n        }\n        len += 2;\n\
    \      }\n    }\n  } else {\n    mint coef = mint(1) / mint(len(a));\n    FOR(i,\
    \ len(a)) a[i] *= coef;\n    int len = h;\n    while (len) {\n      if (len ==\
    \ 1) {\n        int p = 1 << (h - len);\n        mint irot = 1;\n        FOR(s,\
    \ 1 << (len - 1)) {\n          int offset = s << (h - len + 1);\n          FOR(i,\
    \ p) {\n            u64 l = a[i + offset].val;\n            u64 r = a[i + offset\
    \ + p].val;\n            a[i + offset] = l + r;\n            a[i + offset + p]\
    \ = (mod + l - r) * irot.val;\n          }\n          irot *= irate2[topbit(~s\
    \ & -~s)];\n        }\n        len--;\n      } else {\n        int p = 1 << (h\
    \ - len);\n        mint irot = 1, iimag = iroot[2];\n        FOR(s, (1 << (len\
    \ - 2))) {\n          mint irot2 = irot * irot;\n          mint irot3 = irot2\
    \ * irot;\n          int offset = s << (h - len + 2);\n          for (int i =\
    \ 0; i < p; i++) {\n            u64 a0 = a[i + offset + 0 * p].val;\n        \
    \    u64 a1 = a[i + offset + 1 * p].val;\n            u64 a2 = a[i + offset +\
    \ 2 * p].val;\n            u64 a3 = a[i + offset + 3 * p].val;\n            u64\
    \ x = (mod + a2 - a3) * iimag.val % mod;\n            a[i + offset] = a0 + a1\
    \ + a2 + a3;\n            a[i + offset + 1 * p] = (a0 + mod - a1 + x) * irot.val;\n\
    \            a[i + offset + 2 * p] = (a0 + a1 + 2 * mod - a2 - a3) * irot2.val;\n\
    \            a[i + offset + 3 * p] = (a0 + 2 * mod - a1 - x) * irot3.val;\n  \
    \        }\n          irot *= irate3[topbit(~s & -~s)];\n        }\n        len\
    \ -= 2;\n      }\n    }\n  }\n}\n#line 8 \"poly/convolution.hpp\"\n\ntemplate\
    \ <class mint>\nvector<mint> convolution_ntt(vector<mint> a, vector<mint> b) {\n\
    \  assert(mint::can_ntt());\n  if (a.empty() || b.empty()) return {};\n  int n\
    \ = int(a.size()), m = int(b.size());\n  int sz = 1;\n  while (sz < n + m - 1)\
    \ sz *= 2;\n\n  // sz = 2^k \u306E\u3068\u304D\u306E\u9AD8\u901F\u5316\u3002\u5206\
    \u5272\u7D71\u6CBB\u7684\u306A\u3084\u3064\u3067\u640D\u3057\u307E\u304F\u308B\
    \u306E\u3067\u3002\n  if ((n + m - 3) <= sz / 2) {\n    auto a_last = a.back(),\
    \ b_last = b.back();\n    a.pop_back(), b.pop_back();\n    auto c = convolution(a,\
    \ b);\n    c.resize(n + m - 1);\n    c[n + m - 2] = a_last * b_last;\n    FOR(i,\
    \ len(a)) c[i + len(b)] += a[i] * b_last;\n    FOR(i, len(b)) c[i + len(a)] +=\
    \ b[i] * a_last;\n    return c;\n  }\n\n  a.resize(sz), b.resize(sz);\n  bool\
    \ same = a == b;\n  ntt(a, 0);\n  if (same) {\n    b = a;\n  } else {\n    ntt(b,\
    \ 0);\n  }\n  FOR(i, sz) a[i] *= b[i];\n  ntt(a, 1);\n  a.resize(n + m - 1);\n\
    \  return a;\n}\n\ntemplate <typename mint>\nvector<mint> convolution_garner(const\
    \ vector<mint>& a, const vector<mint>& b) {\n  int n = len(a), m = len(b);\n \
    \ if (!n || !m) return {};\n  static constexpr int p0 = 167772161;\n  static constexpr\
    \ int p1 = 469762049;\n  static constexpr int p2 = 754974721;\n  using mint0 =\
    \ modint<p0>;\n  using mint1 = modint<p1>;\n  using mint2 = modint<p2>;\n  vc<mint0>\
    \ a0(n), b0(m);\n  vc<mint1> a1(n), b1(m);\n  vc<mint2> a2(n), b2(m);\n  FOR(i,\
    \ n) a0[i] = a[i].val, a1[i] = a[i].val, a2[i] = a[i].val;\n  FOR(i, m) b0[i]\
    \ = b[i].val, b1[i] = b[i].val, b2[i] = b[i].val;\n  auto c0 = convolution_ntt<mint0>(a0,\
    \ b0);\n  auto c1 = convolution_ntt<mint1>(a1, b1);\n  auto c2 = convolution_ntt<mint2>(a2,\
    \ b2);\n  vc<mint> c(len(c0));\n  FOR(i, n + m - 1) {\n    c[i] = CRT3<mint, p0,\
    \ p1, p2>(c0[i].val, c1[i].val, c2[i].val);\n  }\n  return c;\n}\n\nvector<ll>\
    \ convolution(vector<ll> a, vector<ll> b) {\n  int n = len(a), m = len(b);\n \
    \ if (!n || !m) return {};\n  if (min(n, m) <= 2500) return convolution_naive(a,\
    \ b);\n\n  ll mi_a = MIN(a), mi_b = MIN(b);\n  for (auto& x : a) x -= mi_a;\n\
    \  for (auto& x : b) x -= mi_b;\n  assert(MAX(a) * MAX(b) <= 1e18);\n\n  auto\
    \ Ac = cumsum<ll>(a), Bc = cumsum<ll>(b);\n  vi res(n + m - 1);\n  for (int k\
    \ = 0; k < n + m - 1; ++k) {\n    int s = max(0, k - m + 1);\n    int t = min(n,\
    \ k + 1);\n    res[k] += (t - s) * mi_a * mi_b;\n    res[k] += mi_a * (Bc[k -\
    \ s + 1] - Bc[k - t + 1]);\n    res[k] += mi_b * (Ac[t] - Ac[s]);\n  }\n\n  static\
    \ constexpr u32 MOD1 = 1004535809;\n  static constexpr u32 MOD2 = 1012924417;\n\
    \  using mint1 = modint<MOD1>;\n  using mint2 = modint<MOD2>;\n\n  vc<mint1> a1(n),\
    \ b1(m);\n  vc<mint2> a2(n), b2(m);\n  FOR(i, n) a1[i] = a[i], a2[i] = a[i];\n\
    \  FOR(i, m) b1[i] = b[i], b2[i] = b[i];\n\n  auto c1 = convolution_ntt<mint1>(a1,\
    \ b1);\n  auto c2 = convolution_ntt<mint2>(a2, b2);\n\n  FOR(i, n + m - 1) { res[i]\
    \ += CRT2<u64, MOD1, MOD2>(c1[i].val, c2[i].val); }\n  return res;\n}\n\ntemplate\
    \ <typename mint>\nvc<mint> convolution(const vc<mint>& a, const vc<mint>& b)\
    \ {\n  if (mint::get_mod() == 2) {\n    vc<modint998> aa, bb;\n    for (auto&\
    \ x : a) aa.eb(x.val);\n    for (auto& x : b) bb.eb(x.val);\n    aa = convolution<modint998>(aa,\
    \ bb);\n    vc<mint> ANS(len(aa));\n    FOR(i, len(aa)) ANS[i] = aa[i].val & 1;\n\
    \    return ANS;\n  }\n  int n = len(a), m = len(b);\n  if (!n || !m) return {};\n\
    \  if (mint::can_ntt()) {\n    if (min(n, m) <= 50) return convolution_karatsuba<mint>(a,\
    \ b);\n    return convolution_ntt(a, b);\n  }\n  if (min(n, m) <= 200) return\
    \ convolution_karatsuba<mint>(a, b);\n  return convolution_garner(a, b);\n}\n\
    #line 1 \"poly/middle_product.hpp\"\n\n#line 1 \"other/bit.hpp\"\n\nint popcnt(int\
    \ x) { return __builtin_popcount(x); }\nint popcnt(u32 x) { return __builtin_popcount(x);\
    \ }\nint popcnt(ll x) { return __builtin_popcountll(x); }\nint popcnt(u64 x) {\
    \ return __builtin_popcountll(x); }\nint popcnt_sgn(int x) { return (__builtin_parity(unsigned(x))\
    \ & 1 ? -1 : 1); }\nint popcnt_sgn(u32 x) { return (__builtin_parity(x) & 1 ?\
    \ -1 : 1); }\nint popcnt_sgn(ll x) { return (__builtin_parityll(x) & 1 ? -1 :\
    \ 1); }\nint popcnt_sgn(u64 x) { return (__builtin_parityll(x) & 1 ? -1 : 1);\
    \ }\n// (0, 1, 2, 3, 4) -> (-1, 0, 1, 1, 2)\nint topbit(int x) { return (x ==\
    \ 0 ? -1 : 31 - __builtin_clz(x)); }\nint topbit(u32 x) { return (x == 0 ? -1\
    \ : 31 - __builtin_clz(x)); }\nint topbit(ll x) { return (x == 0 ? -1 : 63 - __builtin_clzll(x));\
    \ }\nint topbit(u64 x) { return (x == 0 ? -1 : 63 - __builtin_clzll(x)); }\n//\
    \ (0, 1, 2, 3, 4) -> (-1, 0, 1, 0, 2)\nint lowbit(int x) { return (x == 0 ? -1\
    \ : __builtin_ctz(x)); }\nint lowbit(u32 x) { return (x == 0 ? -1 : __builtin_ctz(x));\
    \ }\nint lowbit(ll x) { return (x == 0 ? -1 : __builtin_ctzll(x)); }\nint lowbit(u64\
    \ x) { return (x == 0 ? -1 : __builtin_ctzll(x)); }\n\ntemplate <typename T>\n\
    T kth_bit(int k) {\n  return T(1) << k;\n}\ntemplate <typename T>\nbool has_kth_bit(T\
    \ x, int k) {\n  return x >> k & 1;\n}\n\ntemplate <typename UINT>\nstruct all_bit\
    \ {\n  UINT s;\n  all_bit(UINT s) : s(s) {}\n  struct iter {\n    UINT s;\n  \
    \  int operator*() const { return lowbit(s); }\n    void operator++() { s &= s\
    \ - 1; }\n    bool operator!=(nullptr_t) const { return s; }\n  };\n  iter begin()\
    \ const { return {s}; }\n  nullptr_t end() const { return nullptr; }\n};\n\ntemplate\
    \ <typename UINT>\nstruct all_subset {\n  UINT s;\n  all_subset(UINT s) : s(s)\
    \ {}\n  struct iter {\n    UINT s, t;\n    bool done = false;\n    UINT operator*()\
    \ const { return t; }\n    void operator++() {\n      done = (t == 0);\n     \
    \ t = (t - 1) & s;\n    }\n    bool operator!=(nullptr_t) const { return !done;\
    \ }\n  };\n  iter begin() const { return {s, s}; }\n  nullptr_t end() const {\
    \ return nullptr; }\n};\n\nconstexpr u64 full_mask(int n) { return n == 64 ? -1ULL\
    \ : (1ULL << n) - 1; }\n#line 2 \"poly/ntt.hpp\"\n\ntemplate <class mint>\nvoid\
    \ ntt(vector<mint>& a, bool inverse) {\n  assert(mint::can_ntt());\n  const int\
    \ rank2 = mint::ntt_info().fi;\n  const u32 mod = mint::get_mod();\n  static array<mint,\
    \ 30> root, iroot;\n  static array<mint, 30> rate2, irate2;\n  static array<mint,\
    \ 30> rate3, irate3;\n\n  assert(rank2 != -1 && len(a) <= (1 << max(0, rank2)));\n\
    \n  static bool prepared = 0;\n  if (!prepared) {\n    prepared = 1;\n    root[rank2]\
    \ = mint::ntt_info().se;\n    iroot[rank2] = mint(1) / root[rank2];\n    FOR_R(i,\
    \ rank2) {\n      root[i] = root[i + 1] * root[i + 1];\n      iroot[i] = iroot[i\
    \ + 1] * iroot[i + 1];\n    }\n    mint prod = 1, iprod = 1;\n    for (int i =\
    \ 0; i <= rank2 - 2; i++) {\n      rate2[i] = root[i + 2] * prod;\n      irate2[i]\
    \ = iroot[i + 2] * iprod;\n      prod *= iroot[i + 2];\n      iprod *= root[i\
    \ + 2];\n    }\n    prod = 1, iprod = 1;\n    for (int i = 0; i <= rank2 - 3;\
    \ i++) {\n      rate3[i] = root[i + 3] * prod;\n      irate3[i] = iroot[i + 3]\
    \ * iprod;\n      prod *= iroot[i + 3];\n      iprod *= root[i + 3];\n    }\n\
    \  }\n\n  int n = int(a.size());\n  int h = topbit(n);\n  assert(n == 1 << h);\n\
    \  if (!inverse) {\n    int len = 0;\n    while (len < h) {\n      if (h - len\
    \ == 1) {\n        int p = 1 << (h - len - 1);\n        mint rot = 1;\n      \
    \  FOR(s, 1 << len) {\n          int offset = s << (h - len);\n          FOR(i,\
    \ p) {\n            auto l = a[i + offset];\n            auto r = a[i + offset\
    \ + p] * rot;\n            a[i + offset] = l + r;\n            a[i + offset +\
    \ p] = l - r;\n          }\n          rot *= rate2[topbit(~s & -~s)];\n      \
    \  }\n        len++;\n      } else {\n        int p = 1 << (h - len - 2);\n  \
    \      mint rot = 1, imag = root[2];\n        for (int s = 0; s < (1 << len);\
    \ s++) {\n          mint rot2 = rot * rot;\n          mint rot3 = rot2 * rot;\n\
    \          int offset = s << (h - len);\n          for (int i = 0; i < p; i++)\
    \ {\n            u64 mod2 = u64(mod) * mod;\n            u64 a0 = a[i + offset].val;\n\
    \            u64 a1 = u64(a[i + offset + p].val) * rot.val;\n            u64 a2\
    \ = u64(a[i + offset + 2 * p].val) * rot2.val;\n            u64 a3 = u64(a[i +\
    \ offset + 3 * p].val) * rot3.val;\n            u64 a1na3imag = (a1 + mod2 - a3)\
    \ % mod * imag.val;\n            u64 na2 = mod2 - a2;\n            a[i + offset]\
    \ = a0 + a2 + a1 + a3;\n            a[i + offset + 1 * p] = a0 + a2 + (2 * mod2\
    \ - (a1 + a3));\n            a[i + offset + 2 * p] = a0 + na2 + a1na3imag;\n \
    \           a[i + offset + 3 * p] = a0 + na2 + (mod2 - a1na3imag);\n         \
    \ }\n          rot *= rate3[topbit(~s & -~s)];\n        }\n        len += 2;\n\
    \      }\n    }\n  } else {\n    mint coef = mint(1) / mint(len(a));\n    FOR(i,\
    \ len(a)) a[i] *= coef;\n    int len = h;\n    while (len) {\n      if (len ==\
    \ 1) {\n        int p = 1 << (h - len);\n        mint irot = 1;\n        FOR(s,\
    \ 1 << (len - 1)) {\n          int offset = s << (h - len + 1);\n          FOR(i,\
    \ p) {\n            u64 l = a[i + offset].val;\n            u64 r = a[i + offset\
    \ + p].val;\n            a[i + offset] = l + r;\n            a[i + offset + p]\
    \ = (mod + l - r) * irot.val;\n          }\n          irot *= irate2[topbit(~s\
    \ & -~s)];\n        }\n        len--;\n      } else {\n        int p = 1 << (h\
    \ - len);\n        mint irot = 1, iimag = iroot[2];\n        FOR(s, (1 << (len\
    \ - 2))) {\n          mint irot2 = irot * irot;\n          mint irot3 = irot2\
    \ * irot;\n          int offset = s << (h - len + 2);\n          for (int i =\
    \ 0; i < p; i++) {\n            u64 a0 = a[i + offset + 0 * p].val;\n        \
    \    u64 a1 = a[i + offset + 1 * p].val;\n            u64 a2 = a[i + offset +\
    \ 2 * p].val;\n            u64 a3 = a[i + offset + 3 * p].val;\n            u64\
    \ x = (mod + a2 - a3) * iimag.val % mod;\n            a[i + offset] = a0 + a1\
    \ + a2 + a3;\n            a[i + offset + 1 * p] = (a0 + mod - a1 + x) * irot.val;\n\
    \            a[i + offset + 2 * p] = (a0 + a1 + 2 * mod - a2 - a3) * irot2.val;\n\
    \            a[i + offset + 3 * p] = (a0 + 2 * mod - a1 - x) * irot3.val;\n  \
    \        }\n          irot *= irate3[topbit(~s & -~s)];\n        }\n        len\
    \ -= 2;\n      }\n    }\n  }\n}\n#line 1 \"mod/crt3.hpp\"\n\nconstexpr u32 mod_pow_constexpr(u64\
    \ a, u64 n, u32 mod) {\n  a %= mod;\n  u64 res = 1;\n  FOR(32) {\n    if (n &\
    \ 1) res = res * a % mod;\n    a = a * a % mod, n /= 2;\n  }\n  return res;\n\
    }\n\ntemplate <typename T, u32 p0, u32 p1>\nT CRT2(u64 a0, u64 a1) {\n  static_assert(p0\
    \ < p1);\n  static constexpr u64 x0_1 = mod_pow_constexpr(p0, p1 - 2, p1);\n \
    \ u64 c = (a1 - a0 + p1) * x0_1 % p1;\n  return a0 + c * p0;\n}\n\ntemplate <typename\
    \ T, u32 p0, u32 p1, u32 p2>\nT CRT3(u64 a0, u64 a1, u64 a2) {\n  static_assert(p0\
    \ < p1 && p1 < p2);\n  static constexpr u64 x1 = mod_pow_constexpr(p0, p1 - 2,\
    \ p1);\n  static constexpr u64 x2 = mod_pow_constexpr(u64(p0) * p1 % p2, p2 -\
    \ 2, p2);\n  static constexpr u64 p01 = u64(p0) * p1;\n  u64 c = (a1 - a0 + p1)\
    \ * x1 % p1;\n  u64 ans_1 = a0 + c * p0;\n  c = (a2 - ans_1 % p2 + p2) * x2 %\
    \ p2;\n  return T(ans_1) + T(c) * T(p01);\n}\n\ntemplate <typename T, u32 p0,\
    \ u32 p1, u32 p2, u32 p3>\nT CRT4(u64 a0, u64 a1, u64 a2, u64 a3) {\n  static_assert(p0\
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
    \ T(ans_3) + T(c) * T(p01) * T(p23);\n}\n#line 1 \"mod/modint_common.hpp\"\n\n\
    #line 1 \"other/bit.hpp\"\n\nint popcnt(int x) { return __builtin_popcount(x);\
    \ }\nint popcnt(u32 x) { return __builtin_popcount(x); }\nint popcnt(ll x) { return\
    \ __builtin_popcountll(x); }\nint popcnt(u64 x) { return __builtin_popcountll(x);\
    \ }\nint popcnt_sgn(int x) { return (__builtin_parity(unsigned(x)) & 1 ? -1 :\
    \ 1); }\nint popcnt_sgn(u32 x) { return (__builtin_parity(x) & 1 ? -1 : 1); }\n\
    int popcnt_sgn(ll x) { return (__builtin_parityll(x) & 1 ? -1 : 1); }\nint popcnt_sgn(u64\
    \ x) { return (__builtin_parityll(x) & 1 ? -1 : 1); }\n// (0, 1, 2, 3, 4) -> (-1,\
    \ 0, 1, 1, 2)\nint topbit(int x) { return (x == 0 ? -1 : 31 - __builtin_clz(x));\
    \ }\nint topbit(u32 x) { return (x == 0 ? -1 : 31 - __builtin_clz(x)); }\nint\
    \ topbit(ll x) { return (x == 0 ? -1 : 63 - __builtin_clzll(x)); }\nint topbit(u64\
    \ x) { return (x == 0 ? -1 : 63 - __builtin_clzll(x)); }\n// (0, 1, 2, 3, 4) ->\
    \ (-1, 0, 1, 0, 2)\nint lowbit(int x) { return (x == 0 ? -1 : __builtin_ctz(x));\
    \ }\nint lowbit(u32 x) { return (x == 0 ? -1 : __builtin_ctz(x)); }\nint lowbit(ll\
    \ x) { return (x == 0 ? -1 : __builtin_ctzll(x)); }\nint lowbit(u64 x) { return\
    \ (x == 0 ? -1 : __builtin_ctzll(x)); }\n\ntemplate <typename T>\nT kth_bit(int\
    \ k) {\n  return T(1) << k;\n}\ntemplate <typename T>\nbool has_kth_bit(T x, int\
    \ k) {\n  return x >> k & 1;\n}\n\ntemplate <typename UINT>\nstruct all_bit {\n\
    \  UINT s;\n  all_bit(UINT s) : s(s) {}\n  struct iter {\n    UINT s;\n    int\
    \ operator*() const { return lowbit(s); }\n    void operator++() { s &= s - 1;\
    \ }\n    bool operator!=(nullptr_t) const { return s; }\n  };\n  iter begin()\
    \ const { return {s}; }\n  nullptr_t end() const { return nullptr; }\n};\n\ntemplate\
    \ <typename UINT>\nstruct all_subset {\n  UINT s;\n  all_subset(UINT s) : s(s)\
    \ {}\n  struct iter {\n    UINT s, t;\n    bool done = false;\n    UINT operator*()\
    \ const { return t; }\n    void operator++() {\n      done = (t == 0);\n     \
    \ t = (t - 1) & s;\n    }\n    bool operator!=(nullptr_t) const { return !done;\
    \ }\n  };\n  iter begin() const { return {s, s}; }\n  nullptr_t end() const {\
    \ return nullptr; }\n};\n\nconstexpr u64 full_mask(int n) { return n == 64 ? -1ULL\
    \ : (1ULL << n) - 1; }\n#line 3 \"mod/modint_common.hpp\"\n\nstruct has_mod_impl\
    \ {\n  template <class T>\n  static auto check(T &&x) -> decltype(x.get_mod(),\
    \ std::true_type{});\n  template <class T>\n  static auto check(...) -> std::false_type;\n\
    };\n\ntemplate <class T>\nclass has_mod : public decltype(has_mod_impl::check<T>(std::declval<T>()))\
    \ {};\n\ntemplate <typename mint>\nmint fact(int n) {\n  static const int mod\
    \ = mint::get_mod();\n  assert(0 <= n && n < mod);\n  static vector<mint> dat\
    \ = {1, 1};\n  if (len(dat) <= n) {\n    int now = len(dat);\n    int m = min(mod,\
    \ 1 << (topbit(n) + 1));\n    dat.resize(m);\n    FOR(i, now, m) dat[i] = dat[i\
    \ - 1] * mint::raw(i);\n  }\n  return dat[n];\n}\n\ntemplate <typename mint>\n\
    mint fact_inv(int n) {\n  static const int mod = mint::get_mod();\n  static vector<mint>\
    \ dat = {1, 1};\n  if (n < 0) return mint(0);\n  if (len(dat) <= n) {\n    int\
    \ now = len(dat);\n    int m = min(mod, 1 << (topbit(n) + 1));\n    dat.resize(m);\n\
    \    dat[m - 1] = fact<mint>(m - 1).inverse();\n    FOR_R(i, now, m - 1) dat[i]\
    \ = dat[i + 1] * mint::raw(i + 1);\n  }\n  return dat[n];\n}\n\ntemplate <class\
    \ mint, class... Ts>\nmint fact_invs(Ts... xs) {\n  return (mint(1) * ... * fact_inv<mint>(xs));\n\
    }\n\ntemplate <typename mint>\nmint inv(int n) {\n  static const int mod = mint::get_mod();\n\
    \  assert(1 <= n && n < mod);\n  return fact<mint>(n - 1) * fact_inv<mint>(n);\n\
    }\n\ntemplate <>\ndouble inv<double>(int n) {\n  assert(n != 0);\n  return 1.0\
    \ / n;\n}\n\ntemplate <typename mint, class Head, class... Tail>\nmint multinomial(Head\
    \ &&head, Tail &&...tail) {\n  return fact<mint>(head) * fact_invs<mint>(std::forward<Tail>(tail)...);\n\
    }\n\ntemplate <typename mint>\nmint C_dense(int n, int k) {\n  assert(n >= 0);\n\
    \  if (k < 0 || n < k) return 0;\n  static vvc<mint> C;\n  static int H = 0, W\
    \ = 0;\n  auto calc = [&](int i, int j) -> mint {\n    if (i == 0) return (j ==\
    \ 0 ? mint(1) : mint(0));\n    return C[i - 1][j] + (j ? C[i - 1][j - 1] : 0);\n\
    \  };\n  if (W <= k) {\n    FOR(i, H) {\n      C[i].resize(k + 1);\n      FOR(j,\
    \ W, k + 1) { C[i][j] = calc(i, j); }\n    }\n    W = k + 1;\n  }\n  if (H <=\
    \ n) {\n    C.resize(n + 1);\n    FOR(i, H, n + 1) {\n      C[i].resize(W);\n\
    \      FOR(j, W) { C[i][j] = calc(i, j); }\n    }\n    H = n + 1;\n  }\n  return\
    \ C[n][k];\n}\n\ntemplate <typename mint, bool large = false, bool dense = false>\n\
    mint C(ll n, ll k) {\n  assert(n >= 0);\n  if (k < 0 || n < k) return 0;\n  if\
    \ constexpr (dense) return C_dense<mint>(n, k);\n  if constexpr (!large) return\
    \ multinomial<mint>(n, k, n - k);\n  k = min(k, n - k);\n  mint x(1);\n  FOR(i,\
    \ k) x *= mint(n - i);\n  return x * fact_inv<mint>(k);\n}\n\ntemplate <typename\
    \ mint, bool large = false>\nmint C_inv(ll n, ll k) {\n  assert(n >= 0);\n  assert(0\
    \ <= k && k <= n);\n  if (!large) return fact_inv<mint>(n) * fact<mint>(k) * fact<mint>(n\
    \ - k);\n  return mint(1) / C<mint, 1>(n, k);\n}\n\n// [x^d](1-x)^{-n}\ntemplate\
    \ <typename mint, bool large = false, bool dense = false>\nmint C_negative(ll\
    \ n, ll d) {\n  assert(n >= 0);\n  if (d < 0) return mint(0);\n  if (n == 0) {\n\
    \    return (d == 0 ? mint(1) : mint(0));\n  }\n  return C<mint, large, dense>(n\
    \ + d - 1, d);\n}\n#line 2 \"mod/modint.hpp\"\n\ntemplate <int mod>\nstruct modint\
    \ {\n  static constexpr u32 umod = u32(mod);\n  static_assert(0 < umod && umod\
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
    \ return modint(u);\n  }\n  modint pow(ll n) const {\n    if (n < 0) return inverse().pow(-n);\n\
    \    assert(n >= 0);\n    modint ret(1), mul(val);\n    while (n > 0) {\n    \
    \  if (n & 1) ret *= mul;\n      mul *= mul;\n      n >>= 1;\n    }\n    return\
    \ ret;\n  }\n  static constexpr int get_mod() { return mod; }\n  // (n, r), r\
    \ \u306F 1 \u306E 2^n \u4E57\u6839\n  static constexpr pair<int, int> ntt_info()\
    \ {\n    if (mod == 120586241) return {20, 74066978};\n    if (mod == 167772161)\
    \ return {25, 17};\n    if (mod == 469762049) return {26, 30};\n    if (mod ==\
    \ 754974721) return {24, 362};\n    if (mod == 880803841) return {23, 211};\n\
    \    if (mod == 943718401) return {22, 663003469};\n    if (mod == 998244353)\
    \ return {23, 31};\n    if (mod == 1004535809) return {21, 582313106};\n    if\
    \ (mod == 1012924417) return {21, 368093570};\n    if (mod == 1224736769) return\
    \ {24, 1191450770};\n    if (mod == 2013265921) return {27, 244035102};\n    return\
    \ {-1, -1};\n  }\n  static constexpr bool can_ntt() { return ntt_info().fi !=\
    \ -1; }\n};\n\n#ifdef FASTIO\ntemplate <int mod>\nvoid rd(modint<mod> &x) {\n\
    \  fastio::rd(x.val);\n  x.val %= mod;\n  // assert(0 <= x.val && x.val < mod);\n\
    }\ntemplate <int mod>\nvoid wt(modint<mod> x) {\n  fastio::wt(x.val);\n}\n#endif\n\
    \nusing modint107 = modint<1000000007>;\nusing modint998 = modint<998244353>;\n\
    #line 5 \"poly/middle_product.hpp\"\n\n// n, m \u6B21\u591A\u9805\u5F0F (n>=m)\
    \ a, b \u2192 n-m \u6B21\u591A\u9805\u5F0F c\n// c[i] = sum_j b[j]a[i+j]\ntemplate\
    \ <typename mint>\nvc<mint> middle_product(vc<mint>& a, vc<mint>& b) {\n  assert(len(a)\
    \ >= len(b));\n  if (b.empty()) return vc<mint>(len(a) - len(b) + 1);\n  if (min(len(b),\
    \ len(a) - len(b) + 1) <= 60) {\n    return middle_product_naive(a, b);\n  }\n\
    \  if (!(mint::can_ntt())) {\n    return middle_product_garner(a, b);\n  } else\
    \ {\n    int n = 1 << __lg(2 * len(a) - 1);\n    vc<mint> fa(n), fb(n);\n    copy(a.begin(),\
    \ a.end(), fa.begin());\n    copy(b.rbegin(), b.rend(), fb.begin());\n    ntt(fa,\
    \ 0), ntt(fb, 0);\n    FOR(i, n) fa[i] *= fb[i];\n    ntt(fa, 1);\n    fa.resize(len(a));\n\
    \    fa.erase(fa.begin(), fa.begin() + len(b) - 1);\n    return fa;\n  }\n}\n\n\
    template <typename mint>\nvc<mint> middle_product_garner(vc<mint>& a, vc<mint>\
    \ b) {\n  int n = len(a), m = len(b);\n  if (!n || !m) return {};\n  static constexpr\
    \ int p0 = 167772161;\n  static constexpr int p1 = 469762049;\n  static constexpr\
    \ int p2 = 754974721;\n  using mint0 = modint<p0>;\n  using mint1 = modint<p1>;\n\
    \  using mint2 = modint<p2>;\n  vc<mint0> a0(n), b0(m);\n  vc<mint1> a1(n), b1(m);\n\
    \  vc<mint2> a2(n), b2(m);\n  FOR(i, n) a0[i] = a[i].val, a1[i] = a[i].val, a2[i]\
    \ = a[i].val;\n  FOR(i, m) b0[i] = b[i].val, b1[i] = b[i].val, b2[i] = b[i].val;\n\
    \  auto c0 = middle_product<mint0>(a0, b0);\n  auto c1 = middle_product<mint1>(a1,\
    \ b1);\n  auto c2 = middle_product<mint2>(a2, b2);\n  vc<mint> c(len(c0));\n \
    \ FOR(i, n - m + 1) {\n    c[i] = CRT3<mint, p0, p1, p2>(c0[i].val, c1[i].val,\
    \ c2[i].val);\n  }\n  return c;\n}\n\ntemplate <typename mint>\nvc<mint> middle_product_naive(vc<mint>&\
    \ a, vc<mint>& b) {\n  vc<mint> res(len(a) - len(b) + 1);\n  FOR(i, len(res))\
    \ FOR(j, len(b)) res[i] += b[j] * a[i + j];\n  return res;\n}\n#line 3 \"poly/typical_divide_conquer.hpp\"\
    \n\n// given polynomial L_i, R_i, f.\n// For each i, calculate [x^n]f(x)L(x)R(x)\n\
    // L(x) = prod_{j<i}L_j(x)\n// R(x) = prod_{i<j}R_j(x)\n// set \u3057\u306A\u304B\
    \u3063\u305F L_i, R_i \u306B\u306F 1 \u304C\u5165\u308B\ntemplate <typename mint>\n\
    struct Typical_Divide_Conquer {\n  int N;\n  using poly = vc<mint>;\n  vc<poly>\
    \ A;\n  vc<poly> B;\n\n  Typical_Divide_Conquer(int N) : N(N), A(N), B(N) {}\n\
    \n  void set_L(int i, poly f) {\n    assert(0 <= i && i < N - 1);\n    A[i] =\
    \ f;\n  }\n  void set_R(int i, poly f) {\n    assert(1 <= i && i < N);\n    B[i]\
    \ = f;\n  }\n\n  // [x^K]  prod_{i<=j}R_j(x) f(x) prod_{j<i}L_j(x)\n  vc<mint>\
    \ calc(int K, poly f) {\n    if (N == 0) return {};\n    f.resize(K + 1);\n  \
    \  // \u6E96\u5099\n    vc<int> lch(N, -1), rch(N, -1);\n    vc<int> deg(N);\n\
    \    FOR(i, N) {\n      if (A[i].empty()) A[i] = {1};\n      if (B[i].empty())\
    \ B[i] = {1};\n      deg[i] = max(len(A[i]) - 1, len(B[i]) - 1);\n      A[i].resize(deg[i]\
    \ + 1);\n      B[i].resize(deg[i] + 1);\n    }\n    {\n      auto dfs = [&](auto&\
    \ dfs, int L, int R) -> int {\n        if (R == L + 1) return L;\n        int\
    \ M = (L + R) / 2;\n        int a = dfs(dfs, L, M), b = dfs(dfs, M, R);\n    \
    \    int v = len(lch);\n        lch.eb(a), rch.eb(b);\n        A.eb(convolution(A[a],\
    \ A[b]));\n        B.eb(convolution(B[a], B[b]));\n        deg.eb(len(A.back())\
    \ - 1);\n        return v;\n      };\n      dfs(dfs, 0, N);\n    }\n    int root\
    \ = len(lch) - 1;\n    int d = deg[root];\n    if (K < d) {\n      int add = d\
    \ - K;\n      vc<mint> g(len(f) + add);\n      FOR(i, len(f)) g[add + i] = f[i];\n\
    \      swap(f, g);\n      K = d;\n    }\n    assert(len(f) == K + 1);\n    if\
    \ (K > d) {\n      int rm = K - d;\n      f = {f.begin() + rm, f.end()};\n   \
    \   K = d;\n    }\n    reverse(all(f));\n    assert(len(f) == d + 1);\n    vc<mint>\
    \ ANS(N);\n    {\n      auto dfs = [&](auto& dfs, int k, poly& g) -> void {\n\
    \        assert(len(g) - 1 == deg[k]);\n        if (k < N) {\n          ANS[k]\
    \ = g[0];\n          return;\n        }\n        poly g1 = middle_product(g, B[rch[k]]);\n\
    \        poly g2 = middle_product(g, A[lch[k]]);\n        dfs(dfs, lch[k], g1),\
    \ dfs(dfs, rch[k], g2);\n      };\n      dfs(dfs, root, f);\n    }\n    return\
    \ ANS;\n  }\n};\n#line 1 \"poly/convolution_all.hpp\"\n\n#line 1 \"poly/convolution.hpp\"\
    \n\n#line 1 \"mod/modint_common.hpp\"\n\n#line 1 \"other/bit.hpp\"\n\nint popcnt(int\
    \ x) { return __builtin_popcount(x); }\nint popcnt(u32 x) { return __builtin_popcount(x);\
    \ }\nint popcnt(ll x) { return __builtin_popcountll(x); }\nint popcnt(u64 x) {\
    \ return __builtin_popcountll(x); }\nint popcnt_sgn(int x) { return (__builtin_parity(unsigned(x))\
    \ & 1 ? -1 : 1); }\nint popcnt_sgn(u32 x) { return (__builtin_parity(x) & 1 ?\
    \ -1 : 1); }\nint popcnt_sgn(ll x) { return (__builtin_parityll(x) & 1 ? -1 :\
    \ 1); }\nint popcnt_sgn(u64 x) { return (__builtin_parityll(x) & 1 ? -1 : 1);\
    \ }\n// (0, 1, 2, 3, 4) -> (-1, 0, 1, 1, 2)\nint topbit(int x) { return (x ==\
    \ 0 ? -1 : 31 - __builtin_clz(x)); }\nint topbit(u32 x) { return (x == 0 ? -1\
    \ : 31 - __builtin_clz(x)); }\nint topbit(ll x) { return (x == 0 ? -1 : 63 - __builtin_clzll(x));\
    \ }\nint topbit(u64 x) { return (x == 0 ? -1 : 63 - __builtin_clzll(x)); }\n//\
    \ (0, 1, 2, 3, 4) -> (-1, 0, 1, 0, 2)\nint lowbit(int x) { return (x == 0 ? -1\
    \ : __builtin_ctz(x)); }\nint lowbit(u32 x) { return (x == 0 ? -1 : __builtin_ctz(x));\
    \ }\nint lowbit(ll x) { return (x == 0 ? -1 : __builtin_ctzll(x)); }\nint lowbit(u64\
    \ x) { return (x == 0 ? -1 : __builtin_ctzll(x)); }\n\ntemplate <typename T>\n\
    T kth_bit(int k) {\n  return T(1) << k;\n}\ntemplate <typename T>\nbool has_kth_bit(T\
    \ x, int k) {\n  return x >> k & 1;\n}\n\ntemplate <typename UINT>\nstruct all_bit\
    \ {\n  UINT s;\n  all_bit(UINT s) : s(s) {}\n  struct iter {\n    UINT s;\n  \
    \  int operator*() const { return lowbit(s); }\n    void operator++() { s &= s\
    \ - 1; }\n    bool operator!=(nullptr_t) const { return s; }\n  };\n  iter begin()\
    \ const { return {s}; }\n  nullptr_t end() const { return nullptr; }\n};\n\ntemplate\
    \ <typename UINT>\nstruct all_subset {\n  UINT s;\n  all_subset(UINT s) : s(s)\
    \ {}\n  struct iter {\n    UINT s, t;\n    bool done = false;\n    UINT operator*()\
    \ const { return t; }\n    void operator++() {\n      done = (t == 0);\n     \
    \ t = (t - 1) & s;\n    }\n    bool operator!=(nullptr_t) const { return !done;\
    \ }\n  };\n  iter begin() const { return {s, s}; }\n  nullptr_t end() const {\
    \ return nullptr; }\n};\n\nconstexpr u64 full_mask(int n) { return n == 64 ? -1ULL\
    \ : (1ULL << n) - 1; }\n#line 3 \"mod/modint_common.hpp\"\n\nstruct has_mod_impl\
    \ {\n  template <class T>\n  static auto check(T &&x) -> decltype(x.get_mod(),\
    \ std::true_type{});\n  template <class T>\n  static auto check(...) -> std::false_type;\n\
    };\n\ntemplate <class T>\nclass has_mod : public decltype(has_mod_impl::check<T>(std::declval<T>()))\
    \ {};\n\ntemplate <typename mint>\nmint fact(int n) {\n  static const int mod\
    \ = mint::get_mod();\n  assert(0 <= n && n < mod);\n  static vector<mint> dat\
    \ = {1, 1};\n  if (len(dat) <= n) {\n    int now = len(dat);\n    int m = min(mod,\
    \ 1 << (topbit(n) + 1));\n    dat.resize(m);\n    FOR(i, now, m) dat[i] = dat[i\
    \ - 1] * mint::raw(i);\n  }\n  return dat[n];\n}\n\ntemplate <typename mint>\n\
    mint fact_inv(int n) {\n  static const int mod = mint::get_mod();\n  static vector<mint>\
    \ dat = {1, 1};\n  if (n < 0) return mint(0);\n  if (len(dat) <= n) {\n    int\
    \ now = len(dat);\n    int m = min(mod, 1 << (topbit(n) + 1));\n    dat.resize(m);\n\
    \    dat[m - 1] = fact<mint>(m - 1).inverse();\n    FOR_R(i, now, m - 1) dat[i]\
    \ = dat[i + 1] * mint::raw(i + 1);\n  }\n  return dat[n];\n}\n\ntemplate <class\
    \ mint, class... Ts>\nmint fact_invs(Ts... xs) {\n  return (mint(1) * ... * fact_inv<mint>(xs));\n\
    }\n\ntemplate <typename mint>\nmint inv(int n) {\n  static const int mod = mint::get_mod();\n\
    \  assert(1 <= n && n < mod);\n  return fact<mint>(n - 1) * fact_inv<mint>(n);\n\
    }\n\ntemplate <>\ndouble inv<double>(int n) {\n  assert(n != 0);\n  return 1.0\
    \ / n;\n}\n\ntemplate <typename mint, class Head, class... Tail>\nmint multinomial(Head\
    \ &&head, Tail &&...tail) {\n  return fact<mint>(head) * fact_invs<mint>(std::forward<Tail>(tail)...);\n\
    }\n\ntemplate <typename mint>\nmint C_dense(int n, int k) {\n  assert(n >= 0);\n\
    \  if (k < 0 || n < k) return 0;\n  static vvc<mint> C;\n  static int H = 0, W\
    \ = 0;\n  auto calc = [&](int i, int j) -> mint {\n    if (i == 0) return (j ==\
    \ 0 ? mint(1) : mint(0));\n    return C[i - 1][j] + (j ? C[i - 1][j - 1] : 0);\n\
    \  };\n  if (W <= k) {\n    FOR(i, H) {\n      C[i].resize(k + 1);\n      FOR(j,\
    \ W, k + 1) { C[i][j] = calc(i, j); }\n    }\n    W = k + 1;\n  }\n  if (H <=\
    \ n) {\n    C.resize(n + 1);\n    FOR(i, H, n + 1) {\n      C[i].resize(W);\n\
    \      FOR(j, W) { C[i][j] = calc(i, j); }\n    }\n    H = n + 1;\n  }\n  return\
    \ C[n][k];\n}\n\ntemplate <typename mint, bool large = false, bool dense = false>\n\
    mint C(ll n, ll k) {\n  assert(n >= 0);\n  if (k < 0 || n < k) return 0;\n  if\
    \ constexpr (dense) return C_dense<mint>(n, k);\n  if constexpr (!large) return\
    \ multinomial<mint>(n, k, n - k);\n  k = min(k, n - k);\n  mint x(1);\n  FOR(i,\
    \ k) x *= mint(n - i);\n  return x * fact_inv<mint>(k);\n}\n\ntemplate <typename\
    \ mint, bool large = false>\nmint C_inv(ll n, ll k) {\n  assert(n >= 0);\n  assert(0\
    \ <= k && k <= n);\n  if (!large) return fact_inv<mint>(n) * fact<mint>(k) * fact<mint>(n\
    \ - k);\n  return mint(1) / C<mint, 1>(n, k);\n}\n\n// [x^d](1-x)^{-n}\ntemplate\
    \ <typename mint, bool large = false, bool dense = false>\nmint C_negative(ll\
    \ n, ll d) {\n  assert(n >= 0);\n  if (d < 0) return mint(0);\n  if (n == 0) {\n\
    \    return (d == 0 ? mint(1) : mint(0));\n  }\n  return C<mint, large, dense>(n\
    \ + d - 1, d);\n}\n#line 2 \"mod/modint.hpp\"\n\ntemplate <int mod>\nstruct modint\
    \ {\n  static constexpr u32 umod = u32(mod);\n  static_assert(0 < umod && umod\
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
    \ return modint(u);\n  }\n  modint pow(ll n) const {\n    if (n < 0) return inverse().pow(-n);\n\
    \    assert(n >= 0);\n    modint ret(1), mul(val);\n    while (n > 0) {\n    \
    \  if (n & 1) ret *= mul;\n      mul *= mul;\n      n >>= 1;\n    }\n    return\
    \ ret;\n  }\n  static constexpr int get_mod() { return mod; }\n  // (n, r), r\
    \ \u306F 1 \u306E 2^n \u4E57\u6839\n  static constexpr pair<int, int> ntt_info()\
    \ {\n    if (mod == 120586241) return {20, 74066978};\n    if (mod == 167772161)\
    \ return {25, 17};\n    if (mod == 469762049) return {26, 30};\n    if (mod ==\
    \ 754974721) return {24, 362};\n    if (mod == 880803841) return {23, 211};\n\
    \    if (mod == 943718401) return {22, 663003469};\n    if (mod == 998244353)\
    \ return {23, 31};\n    if (mod == 1004535809) return {21, 582313106};\n    if\
    \ (mod == 1012924417) return {21, 368093570};\n    if (mod == 1224736769) return\
    \ {24, 1191450770};\n    if (mod == 2013265921) return {27, 244035102};\n    return\
    \ {-1, -1};\n  }\n  static constexpr bool can_ntt() { return ntt_info().fi !=\
    \ -1; }\n};\n\n#ifdef FASTIO\ntemplate <int mod>\nvoid rd(modint<mod> &x) {\n\
    \  fastio::rd(x.val);\n  x.val %= mod;\n  // assert(0 <= x.val && x.val < mod);\n\
    }\ntemplate <int mod>\nvoid wt(modint<mod> x) {\n  fastio::wt(x.val);\n}\n#endif\n\
    \nusing modint107 = modint<1000000007>;\nusing modint998 = modint<998244353>;\n\
    #line 1 \"mod/mod_inv.hpp\"\n\n// long \u3067\u3082\u5927\u4E08\u592B\n// (val\
    \ * x - 1) \u304C mod \u306E\u500D\u6570\u306B\u306A\u308B\u3088\u3046\u306B\u3059\
    \u308B\n// \u7279\u306B mod=0 \u306A\u3089 x=0 \u304C\u6E80\u305F\u3059\nll mod_inv(ll\
    \ val, ll mod) {\n  if (mod == 0) return 0;\n  mod = abs(mod);\n  val %= mod;\n\
    \  if (val < 0) val += mod;\n  ll a = val, b = mod, u = 1, v = 0, t;\n  while\
    \ (b > 0) {\n    t = a / b;\n    swap(a -= t * b, b), swap(u -= t * v, v);\n \
    \ }\n  if (u < 0) u += mod;\n  return u;\n}\n#line 1 \"mod/crt3.hpp\"\n\nconstexpr\
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
    \ T(ans_3) + T(c) * T(p01) * T(p23);\n}\n#line 1 \"poly/convolution_naive.hpp\"\
    \n\ntemplate <class T, typename enable_if<!has_mod<T>::value>::type* = nullptr>\n\
    vc<T> convolution_naive(const vc<T>& a, const vc<T>& b) {\n  int n = int(a.size()),\
    \ m = int(b.size());\n  if (n > m) return convolution_naive<T>(b, a);\n  if (n\
    \ == 0) return {};\n  vector<T> ans(n + m - 1);\n  FOR(i, n) FOR(j, m) ans[i +\
    \ j] += a[i] * b[j];\n  return ans;\n}\n\ntemplate <class T, typename enable_if<has_mod<T>::value>::type*\
    \ = nullptr>\nvc<T> convolution_naive(const vc<T>& a, const vc<T>& b) {\n  int\
    \ n = int(a.size()), m = int(b.size());\n  if (n > m) return convolution_naive<T>(b,\
    \ a);\n  if (n == 0) return {};\n  vc<T> ans(n + m - 1);\n  if (n <= 16 && (T::get_mod()\
    \ < (1 << 30))) {\n    for (int k = 0; k < n + m - 1; ++k) {\n      int s = max(0,\
    \ k - m + 1);\n      int t = min(n, k + 1);\n      u64 sm = 0;\n      for (int\
    \ i = s; i < t; ++i) { sm += u64(a[i].val) * (b[k - i].val); }\n      ans[k] =\
    \ sm;\n    }\n  } else {\n    for (int k = 0; k < n + m - 1; ++k) {\n      int\
    \ s = max(0, k - m + 1);\n      int t = min(n, k + 1);\n      u128 sm = 0;\n \
    \     for (int i = s; i < t; ++i) { sm += u64(a[i].val) * (b[k - i].val); }\n\
    \      ans[k] = T::raw(sm % T::get_mod());\n    }\n  }\n  return ans;\n}\n#line\
    \ 1 \"poly/convolution_naive.hpp\"\n\ntemplate <class T, typename enable_if<!has_mod<T>::value>::type*\
    \ = nullptr>\nvc<T> convolution_naive(const vc<T>& a, const vc<T>& b) {\n  int\
    \ n = int(a.size()), m = int(b.size());\n  if (n > m) return convolution_naive<T>(b,\
    \ a);\n  if (n == 0) return {};\n  vector<T> ans(n + m - 1);\n  FOR(i, n) FOR(j,\
    \ m) ans[i + j] += a[i] * b[j];\n  return ans;\n}\n\ntemplate <class T, typename\
    \ enable_if<has_mod<T>::value>::type* = nullptr>\nvc<T> convolution_naive(const\
    \ vc<T>& a, const vc<T>& b) {\n  int n = int(a.size()), m = int(b.size());\n \
    \ if (n > m) return convolution_naive<T>(b, a);\n  if (n == 0) return {};\n  vc<T>\
    \ ans(n + m - 1);\n  if (n <= 16 && (T::get_mod() < (1 << 30))) {\n    for (int\
    \ k = 0; k < n + m - 1; ++k) {\n      int s = max(0, k - m + 1);\n      int t\
    \ = min(n, k + 1);\n      u64 sm = 0;\n      for (int i = s; i < t; ++i) { sm\
    \ += u64(a[i].val) * (b[k - i].val); }\n      ans[k] = sm;\n    }\n  } else {\n\
    \    for (int k = 0; k < n + m - 1; ++k) {\n      int s = max(0, k - m + 1);\n\
    \      int t = min(n, k + 1);\n      u128 sm = 0;\n      for (int i = s; i < t;\
    \ ++i) { sm += u64(a[i].val) * (b[k - i].val); }\n      ans[k] = T::raw(sm % T::get_mod());\n\
    \    }\n  }\n  return ans;\n}\n#line 2 \"poly/convolution_karatsuba.hpp\"\n\n\
    // \u4EFB\u610F\u306E\u74B0\u3067\u3067\u304D\u308B\ntemplate <typename T>\nvc<T>\
    \ convolution_karatsuba(const vc<T>& f, const vc<T>& g) {\n  const int thresh\
    \ = 30;\n  if (min(len(f), len(g)) <= thresh) return convolution_naive(f, g);\n\
    \  int n = max(len(f), len(g));\n  int m = ceil(n, 2);\n  vc<T> f1, f2, g1, g2;\n\
    \  if (len(f) < m) f1 = f;\n  if (len(f) >= m) f1 = {f.begin(), f.begin() + m};\n\
    \  if (len(f) >= m) f2 = {f.begin() + m, f.end()};\n  if (len(g) < m) g1 = g;\n\
    \  if (len(g) >= m) g1 = {g.begin(), g.begin() + m};\n  if (len(g) >= m) g2 =\
    \ {g.begin() + m, g.end()};\n  vc<T> a = convolution_karatsuba(f1, g1);\n  vc<T>\
    \ b = convolution_karatsuba(f2, g2);\n  FOR(i, len(f2)) f1[i] += f2[i];\n  FOR(i,\
    \ len(g2)) g1[i] += g2[i];\n  vc<T> c = convolution_karatsuba(f1, g1);\n  vc<T>\
    \ F(len(f) + len(g) - 1);\n  assert(2 * m + len(b) <= len(F));\n  FOR(i, len(a))\
    \ F[i] += a[i], c[i] -= a[i];\n  FOR(i, len(b)) F[2 * m + i] += b[i], c[i] -=\
    \ b[i];\n  if (c.back() == T(0)) c.pop_back();\n  FOR(i, len(c)) if (c[i] != T(0))\
    \ F[m + i] += c[i];\n  return F;\n}\n#line 1 \"other/bit.hpp\"\n\nint popcnt(int\
    \ x) { return __builtin_popcount(x); }\nint popcnt(u32 x) { return __builtin_popcount(x);\
    \ }\nint popcnt(ll x) { return __builtin_popcountll(x); }\nint popcnt(u64 x) {\
    \ return __builtin_popcountll(x); }\nint popcnt_sgn(int x) { return (__builtin_parity(unsigned(x))\
    \ & 1 ? -1 : 1); }\nint popcnt_sgn(u32 x) { return (__builtin_parity(x) & 1 ?\
    \ -1 : 1); }\nint popcnt_sgn(ll x) { return (__builtin_parityll(x) & 1 ? -1 :\
    \ 1); }\nint popcnt_sgn(u64 x) { return (__builtin_parityll(x) & 1 ? -1 : 1);\
    \ }\n// (0, 1, 2, 3, 4) -> (-1, 0, 1, 1, 2)\nint topbit(int x) { return (x ==\
    \ 0 ? -1 : 31 - __builtin_clz(x)); }\nint topbit(u32 x) { return (x == 0 ? -1\
    \ : 31 - __builtin_clz(x)); }\nint topbit(ll x) { return (x == 0 ? -1 : 63 - __builtin_clzll(x));\
    \ }\nint topbit(u64 x) { return (x == 0 ? -1 : 63 - __builtin_clzll(x)); }\n//\
    \ (0, 1, 2, 3, 4) -> (-1, 0, 1, 0, 2)\nint lowbit(int x) { return (x == 0 ? -1\
    \ : __builtin_ctz(x)); }\nint lowbit(u32 x) { return (x == 0 ? -1 : __builtin_ctz(x));\
    \ }\nint lowbit(ll x) { return (x == 0 ? -1 : __builtin_ctzll(x)); }\nint lowbit(u64\
    \ x) { return (x == 0 ? -1 : __builtin_ctzll(x)); }\n\ntemplate <typename T>\n\
    T kth_bit(int k) {\n  return T(1) << k;\n}\ntemplate <typename T>\nbool has_kth_bit(T\
    \ x, int k) {\n  return x >> k & 1;\n}\n\ntemplate <typename UINT>\nstruct all_bit\
    \ {\n  UINT s;\n  all_bit(UINT s) : s(s) {}\n  struct iter {\n    UINT s;\n  \
    \  int operator*() const { return lowbit(s); }\n    void operator++() { s &= s\
    \ - 1; }\n    bool operator!=(nullptr_t) const { return s; }\n  };\n  iter begin()\
    \ const { return {s}; }\n  nullptr_t end() const { return nullptr; }\n};\n\ntemplate\
    \ <typename UINT>\nstruct all_subset {\n  UINT s;\n  all_subset(UINT s) : s(s)\
    \ {}\n  struct iter {\n    UINT s, t;\n    bool done = false;\n    UINT operator*()\
    \ const { return t; }\n    void operator++() {\n      done = (t == 0);\n     \
    \ t = (t - 1) & s;\n    }\n    bool operator!=(nullptr_t) const { return !done;\
    \ }\n  };\n  iter begin() const { return {s, s}; }\n  nullptr_t end() const {\
    \ return nullptr; }\n};\n\nconstexpr u64 full_mask(int n) { return n == 64 ? -1ULL\
    \ : (1ULL << n) - 1; }\n#line 2 \"poly/ntt.hpp\"\n\ntemplate <class mint>\nvoid\
    \ ntt(vector<mint>& a, bool inverse) {\n  assert(mint::can_ntt());\n  const int\
    \ rank2 = mint::ntt_info().fi;\n  const u32 mod = mint::get_mod();\n  static array<mint,\
    \ 30> root, iroot;\n  static array<mint, 30> rate2, irate2;\n  static array<mint,\
    \ 30> rate3, irate3;\n\n  assert(rank2 != -1 && len(a) <= (1 << max(0, rank2)));\n\
    \n  static bool prepared = 0;\n  if (!prepared) {\n    prepared = 1;\n    root[rank2]\
    \ = mint::ntt_info().se;\n    iroot[rank2] = mint(1) / root[rank2];\n    FOR_R(i,\
    \ rank2) {\n      root[i] = root[i + 1] * root[i + 1];\n      iroot[i] = iroot[i\
    \ + 1] * iroot[i + 1];\n    }\n    mint prod = 1, iprod = 1;\n    for (int i =\
    \ 0; i <= rank2 - 2; i++) {\n      rate2[i] = root[i + 2] * prod;\n      irate2[i]\
    \ = iroot[i + 2] * iprod;\n      prod *= iroot[i + 2];\n      iprod *= root[i\
    \ + 2];\n    }\n    prod = 1, iprod = 1;\n    for (int i = 0; i <= rank2 - 3;\
    \ i++) {\n      rate3[i] = root[i + 3] * prod;\n      irate3[i] = iroot[i + 3]\
    \ * iprod;\n      prod *= iroot[i + 3];\n      iprod *= root[i + 3];\n    }\n\
    \  }\n\n  int n = int(a.size());\n  int h = topbit(n);\n  assert(n == 1 << h);\n\
    \  if (!inverse) {\n    int len = 0;\n    while (len < h) {\n      if (h - len\
    \ == 1) {\n        int p = 1 << (h - len - 1);\n        mint rot = 1;\n      \
    \  FOR(s, 1 << len) {\n          int offset = s << (h - len);\n          FOR(i,\
    \ p) {\n            auto l = a[i + offset];\n            auto r = a[i + offset\
    \ + p] * rot;\n            a[i + offset] = l + r;\n            a[i + offset +\
    \ p] = l - r;\n          }\n          rot *= rate2[topbit(~s & -~s)];\n      \
    \  }\n        len++;\n      } else {\n        int p = 1 << (h - len - 2);\n  \
    \      mint rot = 1, imag = root[2];\n        for (int s = 0; s < (1 << len);\
    \ s++) {\n          mint rot2 = rot * rot;\n          mint rot3 = rot2 * rot;\n\
    \          int offset = s << (h - len);\n          for (int i = 0; i < p; i++)\
    \ {\n            u64 mod2 = u64(mod) * mod;\n            u64 a0 = a[i + offset].val;\n\
    \            u64 a1 = u64(a[i + offset + p].val) * rot.val;\n            u64 a2\
    \ = u64(a[i + offset + 2 * p].val) * rot2.val;\n            u64 a3 = u64(a[i +\
    \ offset + 3 * p].val) * rot3.val;\n            u64 a1na3imag = (a1 + mod2 - a3)\
    \ % mod * imag.val;\n            u64 na2 = mod2 - a2;\n            a[i + offset]\
    \ = a0 + a2 + a1 + a3;\n            a[i + offset + 1 * p] = a0 + a2 + (2 * mod2\
    \ - (a1 + a3));\n            a[i + offset + 2 * p] = a0 + na2 + a1na3imag;\n \
    \           a[i + offset + 3 * p] = a0 + na2 + (mod2 - a1na3imag);\n         \
    \ }\n          rot *= rate3[topbit(~s & -~s)];\n        }\n        len += 2;\n\
    \      }\n    }\n  } else {\n    mint coef = mint(1) / mint(len(a));\n    FOR(i,\
    \ len(a)) a[i] *= coef;\n    int len = h;\n    while (len) {\n      if (len ==\
    \ 1) {\n        int p = 1 << (h - len);\n        mint irot = 1;\n        FOR(s,\
    \ 1 << (len - 1)) {\n          int offset = s << (h - len + 1);\n          FOR(i,\
    \ p) {\n            u64 l = a[i + offset].val;\n            u64 r = a[i + offset\
    \ + p].val;\n            a[i + offset] = l + r;\n            a[i + offset + p]\
    \ = (mod + l - r) * irot.val;\n          }\n          irot *= irate2[topbit(~s\
    \ & -~s)];\n        }\n        len--;\n      } else {\n        int p = 1 << (h\
    \ - len);\n        mint irot = 1, iimag = iroot[2];\n        FOR(s, (1 << (len\
    \ - 2))) {\n          mint irot2 = irot * irot;\n          mint irot3 = irot2\
    \ * irot;\n          int offset = s << (h - len + 2);\n          for (int i =\
    \ 0; i < p; i++) {\n            u64 a0 = a[i + offset + 0 * p].val;\n        \
    \    u64 a1 = a[i + offset + 1 * p].val;\n            u64 a2 = a[i + offset +\
    \ 2 * p].val;\n            u64 a3 = a[i + offset + 3 * p].val;\n            u64\
    \ x = (mod + a2 - a3) * iimag.val % mod;\n            a[i + offset] = a0 + a1\
    \ + a2 + a3;\n            a[i + offset + 1 * p] = (a0 + mod - a1 + x) * irot.val;\n\
    \            a[i + offset + 2 * p] = (a0 + a1 + 2 * mod - a2 - a3) * irot2.val;\n\
    \            a[i + offset + 3 * p] = (a0 + 2 * mod - a1 - x) * irot3.val;\n  \
    \        }\n          irot *= irate3[topbit(~s & -~s)];\n        }\n        len\
    \ -= 2;\n      }\n    }\n  }\n}\n#line 8 \"poly/convolution.hpp\"\n\ntemplate\
    \ <class mint>\nvector<mint> convolution_ntt(vector<mint> a, vector<mint> b) {\n\
    \  assert(mint::can_ntt());\n  if (a.empty() || b.empty()) return {};\n  int n\
    \ = int(a.size()), m = int(b.size());\n  int sz = 1;\n  while (sz < n + m - 1)\
    \ sz *= 2;\n\n  // sz = 2^k \u306E\u3068\u304D\u306E\u9AD8\u901F\u5316\u3002\u5206\
    \u5272\u7D71\u6CBB\u7684\u306A\u3084\u3064\u3067\u640D\u3057\u307E\u304F\u308B\
    \u306E\u3067\u3002\n  if ((n + m - 3) <= sz / 2) {\n    auto a_last = a.back(),\
    \ b_last = b.back();\n    a.pop_back(), b.pop_back();\n    auto c = convolution(a,\
    \ b);\n    c.resize(n + m - 1);\n    c[n + m - 2] = a_last * b_last;\n    FOR(i,\
    \ len(a)) c[i + len(b)] += a[i] * b_last;\n    FOR(i, len(b)) c[i + len(a)] +=\
    \ b[i] * a_last;\n    return c;\n  }\n\n  a.resize(sz), b.resize(sz);\n  bool\
    \ same = a == b;\n  ntt(a, 0);\n  if (same) {\n    b = a;\n  } else {\n    ntt(b,\
    \ 0);\n  }\n  FOR(i, sz) a[i] *= b[i];\n  ntt(a, 1);\n  a.resize(n + m - 1);\n\
    \  return a;\n}\n\ntemplate <typename mint>\nvector<mint> convolution_garner(const\
    \ vector<mint>& a, const vector<mint>& b) {\n  int n = len(a), m = len(b);\n \
    \ if (!n || !m) return {};\n  static constexpr int p0 = 167772161;\n  static constexpr\
    \ int p1 = 469762049;\n  static constexpr int p2 = 754974721;\n  using mint0 =\
    \ modint<p0>;\n  using mint1 = modint<p1>;\n  using mint2 = modint<p2>;\n  vc<mint0>\
    \ a0(n), b0(m);\n  vc<mint1> a1(n), b1(m);\n  vc<mint2> a2(n), b2(m);\n  FOR(i,\
    \ n) a0[i] = a[i].val, a1[i] = a[i].val, a2[i] = a[i].val;\n  FOR(i, m) b0[i]\
    \ = b[i].val, b1[i] = b[i].val, b2[i] = b[i].val;\n  auto c0 = convolution_ntt<mint0>(a0,\
    \ b0);\n  auto c1 = convolution_ntt<mint1>(a1, b1);\n  auto c2 = convolution_ntt<mint2>(a2,\
    \ b2);\n  vc<mint> c(len(c0));\n  FOR(i, n + m - 1) {\n    c[i] = CRT3<mint, p0,\
    \ p1, p2>(c0[i].val, c1[i].val, c2[i].val);\n  }\n  return c;\n}\n\nvector<ll>\
    \ convolution(vector<ll> a, vector<ll> b) {\n  int n = len(a), m = len(b);\n \
    \ if (!n || !m) return {};\n  if (min(n, m) <= 2500) return convolution_naive(a,\
    \ b);\n\n  ll mi_a = MIN(a), mi_b = MIN(b);\n  for (auto& x : a) x -= mi_a;\n\
    \  for (auto& x : b) x -= mi_b;\n  assert(MAX(a) * MAX(b) <= 1e18);\n\n  auto\
    \ Ac = cumsum<ll>(a), Bc = cumsum<ll>(b);\n  vi res(n + m - 1);\n  for (int k\
    \ = 0; k < n + m - 1; ++k) {\n    int s = max(0, k - m + 1);\n    int t = min(n,\
    \ k + 1);\n    res[k] += (t - s) * mi_a * mi_b;\n    res[k] += mi_a * (Bc[k -\
    \ s + 1] - Bc[k - t + 1]);\n    res[k] += mi_b * (Ac[t] - Ac[s]);\n  }\n\n  static\
    \ constexpr u32 MOD1 = 1004535809;\n  static constexpr u32 MOD2 = 1012924417;\n\
    \  using mint1 = modint<MOD1>;\n  using mint2 = modint<MOD2>;\n\n  vc<mint1> a1(n),\
    \ b1(m);\n  vc<mint2> a2(n), b2(m);\n  FOR(i, n) a1[i] = a[i], a2[i] = a[i];\n\
    \  FOR(i, m) b1[i] = b[i], b2[i] = b[i];\n\n  auto c1 = convolution_ntt<mint1>(a1,\
    \ b1);\n  auto c2 = convolution_ntt<mint2>(a2, b2);\n\n  FOR(i, n + m - 1) { res[i]\
    \ += CRT2<u64, MOD1, MOD2>(c1[i].val, c2[i].val); }\n  return res;\n}\n\ntemplate\
    \ <typename mint>\nvc<mint> convolution(const vc<mint>& a, const vc<mint>& b)\
    \ {\n  if (mint::get_mod() == 2) {\n    vc<modint998> aa, bb;\n    for (auto&\
    \ x : a) aa.eb(x.val);\n    for (auto& x : b) bb.eb(x.val);\n    aa = convolution<modint998>(aa,\
    \ bb);\n    vc<mint> ANS(len(aa));\n    FOR(i, len(aa)) ANS[i] = aa[i].val & 1;\n\
    \    return ANS;\n  }\n  int n = len(a), m = len(b);\n  if (!n || !m) return {};\n\
    \  if (mint::can_ntt()) {\n    if (min(n, m) <= 50) return convolution_karatsuba<mint>(a,\
    \ b);\n    return convolution_ntt(a, b);\n  }\n  if (min(n, m) <= 200) return\
    \ convolution_karatsuba<mint>(a, b);\n  return convolution_garner(a, b);\n}\n\
    #line 1 \"poly/ntt_doubling.hpp\"\n\n#line 1 \"other/bit.hpp\"\n\nint popcnt(int\
    \ x) { return __builtin_popcount(x); }\nint popcnt(u32 x) { return __builtin_popcount(x);\
    \ }\nint popcnt(ll x) { return __builtin_popcountll(x); }\nint popcnt(u64 x) {\
    \ return __builtin_popcountll(x); }\nint popcnt_sgn(int x) { return (__builtin_parity(unsigned(x))\
    \ & 1 ? -1 : 1); }\nint popcnt_sgn(u32 x) { return (__builtin_parity(x) & 1 ?\
    \ -1 : 1); }\nint popcnt_sgn(ll x) { return (__builtin_parityll(x) & 1 ? -1 :\
    \ 1); }\nint popcnt_sgn(u64 x) { return (__builtin_parityll(x) & 1 ? -1 : 1);\
    \ }\n// (0, 1, 2, 3, 4) -> (-1, 0, 1, 1, 2)\nint topbit(int x) { return (x ==\
    \ 0 ? -1 : 31 - __builtin_clz(x)); }\nint topbit(u32 x) { return (x == 0 ? -1\
    \ : 31 - __builtin_clz(x)); }\nint topbit(ll x) { return (x == 0 ? -1 : 63 - __builtin_clzll(x));\
    \ }\nint topbit(u64 x) { return (x == 0 ? -1 : 63 - __builtin_clzll(x)); }\n//\
    \ (0, 1, 2, 3, 4) -> (-1, 0, 1, 0, 2)\nint lowbit(int x) { return (x == 0 ? -1\
    \ : __builtin_ctz(x)); }\nint lowbit(u32 x) { return (x == 0 ? -1 : __builtin_ctz(x));\
    \ }\nint lowbit(ll x) { return (x == 0 ? -1 : __builtin_ctzll(x)); }\nint lowbit(u64\
    \ x) { return (x == 0 ? -1 : __builtin_ctzll(x)); }\n\ntemplate <typename T>\n\
    T kth_bit(int k) {\n  return T(1) << k;\n}\ntemplate <typename T>\nbool has_kth_bit(T\
    \ x, int k) {\n  return x >> k & 1;\n}\n\ntemplate <typename UINT>\nstruct all_bit\
    \ {\n  UINT s;\n  all_bit(UINT s) : s(s) {}\n  struct iter {\n    UINT s;\n  \
    \  int operator*() const { return lowbit(s); }\n    void operator++() { s &= s\
    \ - 1; }\n    bool operator!=(nullptr_t) const { return s; }\n  };\n  iter begin()\
    \ const { return {s}; }\n  nullptr_t end() const { return nullptr; }\n};\n\ntemplate\
    \ <typename UINT>\nstruct all_subset {\n  UINT s;\n  all_subset(UINT s) : s(s)\
    \ {}\n  struct iter {\n    UINT s, t;\n    bool done = false;\n    UINT operator*()\
    \ const { return t; }\n    void operator++() {\n      done = (t == 0);\n     \
    \ t = (t - 1) & s;\n    }\n    bool operator!=(nullptr_t) const { return !done;\
    \ }\n  };\n  iter begin() const { return {s, s}; }\n  nullptr_t end() const {\
    \ return nullptr; }\n};\n\nconstexpr u64 full_mask(int n) { return n == 64 ? -1ULL\
    \ : (1ULL << n) - 1; }\n#line 2 \"poly/ntt.hpp\"\n\ntemplate <class mint>\nvoid\
    \ ntt(vector<mint>& a, bool inverse) {\n  assert(mint::can_ntt());\n  const int\
    \ rank2 = mint::ntt_info().fi;\n  const u32 mod = mint::get_mod();\n  static array<mint,\
    \ 30> root, iroot;\n  static array<mint, 30> rate2, irate2;\n  static array<mint,\
    \ 30> rate3, irate3;\n\n  assert(rank2 != -1 && len(a) <= (1 << max(0, rank2)));\n\
    \n  static bool prepared = 0;\n  if (!prepared) {\n    prepared = 1;\n    root[rank2]\
    \ = mint::ntt_info().se;\n    iroot[rank2] = mint(1) / root[rank2];\n    FOR_R(i,\
    \ rank2) {\n      root[i] = root[i + 1] * root[i + 1];\n      iroot[i] = iroot[i\
    \ + 1] * iroot[i + 1];\n    }\n    mint prod = 1, iprod = 1;\n    for (int i =\
    \ 0; i <= rank2 - 2; i++) {\n      rate2[i] = root[i + 2] * prod;\n      irate2[i]\
    \ = iroot[i + 2] * iprod;\n      prod *= iroot[i + 2];\n      iprod *= root[i\
    \ + 2];\n    }\n    prod = 1, iprod = 1;\n    for (int i = 0; i <= rank2 - 3;\
    \ i++) {\n      rate3[i] = root[i + 3] * prod;\n      irate3[i] = iroot[i + 3]\
    \ * iprod;\n      prod *= iroot[i + 3];\n      iprod *= root[i + 3];\n    }\n\
    \  }\n\n  int n = int(a.size());\n  int h = topbit(n);\n  assert(n == 1 << h);\n\
    \  if (!inverse) {\n    int len = 0;\n    while (len < h) {\n      if (h - len\
    \ == 1) {\n        int p = 1 << (h - len - 1);\n        mint rot = 1;\n      \
    \  FOR(s, 1 << len) {\n          int offset = s << (h - len);\n          FOR(i,\
    \ p) {\n            auto l = a[i + offset];\n            auto r = a[i + offset\
    \ + p] * rot;\n            a[i + offset] = l + r;\n            a[i + offset +\
    \ p] = l - r;\n          }\n          rot *= rate2[topbit(~s & -~s)];\n      \
    \  }\n        len++;\n      } else {\n        int p = 1 << (h - len - 2);\n  \
    \      mint rot = 1, imag = root[2];\n        for (int s = 0; s < (1 << len);\
    \ s++) {\n          mint rot2 = rot * rot;\n          mint rot3 = rot2 * rot;\n\
    \          int offset = s << (h - len);\n          for (int i = 0; i < p; i++)\
    \ {\n            u64 mod2 = u64(mod) * mod;\n            u64 a0 = a[i + offset].val;\n\
    \            u64 a1 = u64(a[i + offset + p].val) * rot.val;\n            u64 a2\
    \ = u64(a[i + offset + 2 * p].val) * rot2.val;\n            u64 a3 = u64(a[i +\
    \ offset + 3 * p].val) * rot3.val;\n            u64 a1na3imag = (a1 + mod2 - a3)\
    \ % mod * imag.val;\n            u64 na2 = mod2 - a2;\n            a[i + offset]\
    \ = a0 + a2 + a1 + a3;\n            a[i + offset + 1 * p] = a0 + a2 + (2 * mod2\
    \ - (a1 + a3));\n            a[i + offset + 2 * p] = a0 + na2 + a1na3imag;\n \
    \           a[i + offset + 3 * p] = a0 + na2 + (mod2 - a1na3imag);\n         \
    \ }\n          rot *= rate3[topbit(~s & -~s)];\n        }\n        len += 2;\n\
    \      }\n    }\n  } else {\n    mint coef = mint(1) / mint(len(a));\n    FOR(i,\
    \ len(a)) a[i] *= coef;\n    int len = h;\n    while (len) {\n      if (len ==\
    \ 1) {\n        int p = 1 << (h - len);\n        mint irot = 1;\n        FOR(s,\
    \ 1 << (len - 1)) {\n          int offset = s << (h - len + 1);\n          FOR(i,\
    \ p) {\n            u64 l = a[i + offset].val;\n            u64 r = a[i + offset\
    \ + p].val;\n            a[i + offset] = l + r;\n            a[i + offset + p]\
    \ = (mod + l - r) * irot.val;\n          }\n          irot *= irate2[topbit(~s\
    \ & -~s)];\n        }\n        len--;\n      } else {\n        int p = 1 << (h\
    \ - len);\n        mint irot = 1, iimag = iroot[2];\n        FOR(s, (1 << (len\
    \ - 2))) {\n          mint irot2 = irot * irot;\n          mint irot3 = irot2\
    \ * irot;\n          int offset = s << (h - len + 2);\n          for (int i =\
    \ 0; i < p; i++) {\n            u64 a0 = a[i + offset + 0 * p].val;\n        \
    \    u64 a1 = a[i + offset + 1 * p].val;\n            u64 a2 = a[i + offset +\
    \ 2 * p].val;\n            u64 a3 = a[i + offset + 3 * p].val;\n            u64\
    \ x = (mod + a2 - a3) * iimag.val % mod;\n            a[i + offset] = a0 + a1\
    \ + a2 + a3;\n            a[i + offset + 1 * p] = (a0 + mod - a1 + x) * irot.val;\n\
    \            a[i + offset + 2 * p] = (a0 + a1 + 2 * mod - a2 - a3) * irot2.val;\n\
    \            a[i + offset + 3 * p] = (a0 + 2 * mod - a1 - x) * irot3.val;\n  \
    \        }\n          irot *= irate3[topbit(~s & -~s)];\n        }\n        len\
    \ -= 2;\n      }\n    }\n  }\n}\n#line 3 \"poly/ntt_doubling.hpp\"\n\n// 2^k \u6B21\
    \u591A\u9805\u5F0F\u306E\u9577\u3055 2^k \u304C\u4E0E\u3048\u3089\u308C\u308B\u306E\
    \u3067 2^k+1 \u306B\u3059\u308B\ntemplate <typename mint, bool transposed = false>\n\
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
    \ 1);\n    FOR(i, M) a[i] += tmp[i];\n  }\n}\n#line 4 \"poly/convolution_all.hpp\"\
    \n\ntemplate <typename T>\nvc<T> convolution_all(vc<vc<T>>& polys) {\n  if (len(polys)\
    \ == 0) return {T(1)};\n  while (1) {\n    int n = len(polys);\n    if (n == 1)\
    \ break;\n    int m = ceil(n, 2);\n    FOR(i, m) {\n      if (2 * i + 1 == n)\
    \ {\n        polys[i] = polys[2 * i];\n      } else {\n        polys[i] = convolution(polys[2\
    \ * i], polys[2 * i + 1]);\n      }\n    }\n    polys.resize(m);\n  }\n  return\
    \ polys[0];\n}\n\n// product of 1-A[i]x\ntemplate <typename mint>\nvc<mint> convolution_all_1(vc<mint>\
    \ A) {\n  if (!mint::can_ntt()) {\n    vvc<mint> polys;\n    for (auto& a: A)\
    \ polys.eb(vc<mint>({mint(1), -a}));\n    return convolution_all(polys);\n  }\n\
    \  int D = 6;\n  using poly = vc<mint>;\n  int n = 1;\n  while (n < len(A)) n\
    \ *= 2;\n  int k = topbit(n);\n  vc<mint> F(n), nxt_F(n);\n  FOR(i, len(A)) F[i]\
    \ = -A[i];\n  FOR(d, k) {\n    int b = 1 << d;\n    if (d < D) {\n      fill(all(nxt_F),\
    \ mint(0));\n      for (int L = 0; L < n; L += 2 * b) {\n        FOR(i, b) FOR(j,\
    \ b) { nxt_F[L + i + j] += F[L + i] * F[L + b + j]; }\n        FOR(i, b) nxt_F[L\
    \ + b + i] += F[L + i] + F[L + b + i];\n      }\n    }\n    elif (d == D) {\n\
    \      for (int L = 0; L < n; L += 2 * b) {\n        poly f1 = {F.begin() + L,\
    \ F.begin() + L + b};\n        poly f2 = {F.begin() + L + b, F.begin() + L + 2\
    \ * b};\n        f1.resize(2 * b), f2.resize(2 * b), ntt(f1, 0), ntt(f2, 0);\n\
    \        FOR(i, b) nxt_F[L + i] = f1[i] * f2[i] + f1[i] + f2[i];\n        FOR(i,\
    \ b, 2 * b) nxt_F[L + i] = f1[i] * f2[i] - f1[i] - f2[i];\n      }\n    }\n  \
    \  else {\n      for (int L = 0; L < n; L += 2 * b) {\n        poly f1 = {F.begin()\
    \ + L, F.begin() + L + b};\n        poly f2 = {F.begin() + L + b, F.begin() +\
    \ L + 2 * b};\n        ntt_doubling(f1), ntt_doubling(f2);\n        FOR(i, b)\
    \ nxt_F[L + i] = f1[i] * f2[i] + f1[i] + f2[i];\n        FOR(i, b, 2 * b) nxt_F[L\
    \ + i] = f1[i] * f2[i] - f1[i] - f2[i];\n      }\n    }\n    swap(F, nxt_F);\n\
    \  }\n  if (k - 1 >= D) ntt(F, 1);\n  F.eb(1), reverse(all(F));\n  F.resize(len(A)\
    \ + 1);\n  return F;\n}\n#line 1 \"poly/fps_div.hpp\"\n\n#line 1 \"poly/count_terms.hpp\"\
    \ntemplate<typename mint>\nint count_terms(const vc<mint>& f){\n  int t = 0;\n\
    \  FOR(i, len(f)) if(f[i] != mint(0)) ++t;\n  return t;\n}\n#line 1 \"poly/count_terms.hpp\"\
    \ntemplate<typename mint>\nint count_terms(const vc<mint>& f){\n  int t = 0;\n\
    \  FOR(i, len(f)) if(f[i] != mint(0)) ++t;\n  return t;\n}\n#line 1 \"poly/convolution.hpp\"\
    \n\n#line 1 \"mod/modint_common.hpp\"\n\n#line 1 \"other/bit.hpp\"\n\nint popcnt(int\
    \ x) { return __builtin_popcount(x); }\nint popcnt(u32 x) { return __builtin_popcount(x);\
    \ }\nint popcnt(ll x) { return __builtin_popcountll(x); }\nint popcnt(u64 x) {\
    \ return __builtin_popcountll(x); }\nint popcnt_sgn(int x) { return (__builtin_parity(unsigned(x))\
    \ & 1 ? -1 : 1); }\nint popcnt_sgn(u32 x) { return (__builtin_parity(x) & 1 ?\
    \ -1 : 1); }\nint popcnt_sgn(ll x) { return (__builtin_parityll(x) & 1 ? -1 :\
    \ 1); }\nint popcnt_sgn(u64 x) { return (__builtin_parityll(x) & 1 ? -1 : 1);\
    \ }\n// (0, 1, 2, 3, 4) -> (-1, 0, 1, 1, 2)\nint topbit(int x) { return (x ==\
    \ 0 ? -1 : 31 - __builtin_clz(x)); }\nint topbit(u32 x) { return (x == 0 ? -1\
    \ : 31 - __builtin_clz(x)); }\nint topbit(ll x) { return (x == 0 ? -1 : 63 - __builtin_clzll(x));\
    \ }\nint topbit(u64 x) { return (x == 0 ? -1 : 63 - __builtin_clzll(x)); }\n//\
    \ (0, 1, 2, 3, 4) -> (-1, 0, 1, 0, 2)\nint lowbit(int x) { return (x == 0 ? -1\
    \ : __builtin_ctz(x)); }\nint lowbit(u32 x) { return (x == 0 ? -1 : __builtin_ctz(x));\
    \ }\nint lowbit(ll x) { return (x == 0 ? -1 : __builtin_ctzll(x)); }\nint lowbit(u64\
    \ x) { return (x == 0 ? -1 : __builtin_ctzll(x)); }\n\ntemplate <typename T>\n\
    T kth_bit(int k) {\n  return T(1) << k;\n}\ntemplate <typename T>\nbool has_kth_bit(T\
    \ x, int k) {\n  return x >> k & 1;\n}\n\ntemplate <typename UINT>\nstruct all_bit\
    \ {\n  UINT s;\n  all_bit(UINT s) : s(s) {}\n  struct iter {\n    UINT s;\n  \
    \  int operator*() const { return lowbit(s); }\n    void operator++() { s &= s\
    \ - 1; }\n    bool operator!=(nullptr_t) const { return s; }\n  };\n  iter begin()\
    \ const { return {s}; }\n  nullptr_t end() const { return nullptr; }\n};\n\ntemplate\
    \ <typename UINT>\nstruct all_subset {\n  UINT s;\n  all_subset(UINT s) : s(s)\
    \ {}\n  struct iter {\n    UINT s, t;\n    bool done = false;\n    UINT operator*()\
    \ const { return t; }\n    void operator++() {\n      done = (t == 0);\n     \
    \ t = (t - 1) & s;\n    }\n    bool operator!=(nullptr_t) const { return !done;\
    \ }\n  };\n  iter begin() const { return {s, s}; }\n  nullptr_t end() const {\
    \ return nullptr; }\n};\n\nconstexpr u64 full_mask(int n) { return n == 64 ? -1ULL\
    \ : (1ULL << n) - 1; }\n#line 3 \"mod/modint_common.hpp\"\n\nstruct has_mod_impl\
    \ {\n  template <class T>\n  static auto check(T &&x) -> decltype(x.get_mod(),\
    \ std::true_type{});\n  template <class T>\n  static auto check(...) -> std::false_type;\n\
    };\n\ntemplate <class T>\nclass has_mod : public decltype(has_mod_impl::check<T>(std::declval<T>()))\
    \ {};\n\ntemplate <typename mint>\nmint fact(int n) {\n  static const int mod\
    \ = mint::get_mod();\n  assert(0 <= n && n < mod);\n  static vector<mint> dat\
    \ = {1, 1};\n  if (len(dat) <= n) {\n    int now = len(dat);\n    int m = min(mod,\
    \ 1 << (topbit(n) + 1));\n    dat.resize(m);\n    FOR(i, now, m) dat[i] = dat[i\
    \ - 1] * mint::raw(i);\n  }\n  return dat[n];\n}\n\ntemplate <typename mint>\n\
    mint fact_inv(int n) {\n  static const int mod = mint::get_mod();\n  static vector<mint>\
    \ dat = {1, 1};\n  if (n < 0) return mint(0);\n  if (len(dat) <= n) {\n    int\
    \ now = len(dat);\n    int m = min(mod, 1 << (topbit(n) + 1));\n    dat.resize(m);\n\
    \    dat[m - 1] = fact<mint>(m - 1).inverse();\n    FOR_R(i, now, m - 1) dat[i]\
    \ = dat[i + 1] * mint::raw(i + 1);\n  }\n  return dat[n];\n}\n\ntemplate <class\
    \ mint, class... Ts>\nmint fact_invs(Ts... xs) {\n  return (mint(1) * ... * fact_inv<mint>(xs));\n\
    }\n\ntemplate <typename mint>\nmint inv(int n) {\n  static const int mod = mint::get_mod();\n\
    \  assert(1 <= n && n < mod);\n  return fact<mint>(n - 1) * fact_inv<mint>(n);\n\
    }\n\ntemplate <>\ndouble inv<double>(int n) {\n  assert(n != 0);\n  return 1.0\
    \ / n;\n}\n\ntemplate <typename mint, class Head, class... Tail>\nmint multinomial(Head\
    \ &&head, Tail &&...tail) {\n  return fact<mint>(head) * fact_invs<mint>(std::forward<Tail>(tail)...);\n\
    }\n\ntemplate <typename mint>\nmint C_dense(int n, int k) {\n  assert(n >= 0);\n\
    \  if (k < 0 || n < k) return 0;\n  static vvc<mint> C;\n  static int H = 0, W\
    \ = 0;\n  auto calc = [&](int i, int j) -> mint {\n    if (i == 0) return (j ==\
    \ 0 ? mint(1) : mint(0));\n    return C[i - 1][j] + (j ? C[i - 1][j - 1] : 0);\n\
    \  };\n  if (W <= k) {\n    FOR(i, H) {\n      C[i].resize(k + 1);\n      FOR(j,\
    \ W, k + 1) { C[i][j] = calc(i, j); }\n    }\n    W = k + 1;\n  }\n  if (H <=\
    \ n) {\n    C.resize(n + 1);\n    FOR(i, H, n + 1) {\n      C[i].resize(W);\n\
    \      FOR(j, W) { C[i][j] = calc(i, j); }\n    }\n    H = n + 1;\n  }\n  return\
    \ C[n][k];\n}\n\ntemplate <typename mint, bool large = false, bool dense = false>\n\
    mint C(ll n, ll k) {\n  assert(n >= 0);\n  if (k < 0 || n < k) return 0;\n  if\
    \ constexpr (dense) return C_dense<mint>(n, k);\n  if constexpr (!large) return\
    \ multinomial<mint>(n, k, n - k);\n  k = min(k, n - k);\n  mint x(1);\n  FOR(i,\
    \ k) x *= mint(n - i);\n  return x * fact_inv<mint>(k);\n}\n\ntemplate <typename\
    \ mint, bool large = false>\nmint C_inv(ll n, ll k) {\n  assert(n >= 0);\n  assert(0\
    \ <= k && k <= n);\n  if (!large) return fact_inv<mint>(n) * fact<mint>(k) * fact<mint>(n\
    \ - k);\n  return mint(1) / C<mint, 1>(n, k);\n}\n\n// [x^d](1-x)^{-n}\ntemplate\
    \ <typename mint, bool large = false, bool dense = false>\nmint C_negative(ll\
    \ n, ll d) {\n  assert(n >= 0);\n  if (d < 0) return mint(0);\n  if (n == 0) {\n\
    \    return (d == 0 ? mint(1) : mint(0));\n  }\n  return C<mint, large, dense>(n\
    \ + d - 1, d);\n}\n#line 2 \"mod/modint.hpp\"\n\ntemplate <int mod>\nstruct modint\
    \ {\n  static constexpr u32 umod = u32(mod);\n  static_assert(0 < umod && umod\
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
    \ return modint(u);\n  }\n  modint pow(ll n) const {\n    if (n < 0) return inverse().pow(-n);\n\
    \    assert(n >= 0);\n    modint ret(1), mul(val);\n    while (n > 0) {\n    \
    \  if (n & 1) ret *= mul;\n      mul *= mul;\n      n >>= 1;\n    }\n    return\
    \ ret;\n  }\n  static constexpr int get_mod() { return mod; }\n  // (n, r), r\
    \ \u306F 1 \u306E 2^n \u4E57\u6839\n  static constexpr pair<int, int> ntt_info()\
    \ {\n    if (mod == 120586241) return {20, 74066978};\n    if (mod == 167772161)\
    \ return {25, 17};\n    if (mod == 469762049) return {26, 30};\n    if (mod ==\
    \ 754974721) return {24, 362};\n    if (mod == 880803841) return {23, 211};\n\
    \    if (mod == 943718401) return {22, 663003469};\n    if (mod == 998244353)\
    \ return {23, 31};\n    if (mod == 1004535809) return {21, 582313106};\n    if\
    \ (mod == 1012924417) return {21, 368093570};\n    if (mod == 1224736769) return\
    \ {24, 1191450770};\n    if (mod == 2013265921) return {27, 244035102};\n    return\
    \ {-1, -1};\n  }\n  static constexpr bool can_ntt() { return ntt_info().fi !=\
    \ -1; }\n};\n\n#ifdef FASTIO\ntemplate <int mod>\nvoid rd(modint<mod> &x) {\n\
    \  fastio::rd(x.val);\n  x.val %= mod;\n  // assert(0 <= x.val && x.val < mod);\n\
    }\ntemplate <int mod>\nvoid wt(modint<mod> x) {\n  fastio::wt(x.val);\n}\n#endif\n\
    \nusing modint107 = modint<1000000007>;\nusing modint998 = modint<998244353>;\n\
    #line 1 \"mod/mod_inv.hpp\"\n\n// long \u3067\u3082\u5927\u4E08\u592B\n// (val\
    \ * x - 1) \u304C mod \u306E\u500D\u6570\u306B\u306A\u308B\u3088\u3046\u306B\u3059\
    \u308B\n// \u7279\u306B mod=0 \u306A\u3089 x=0 \u304C\u6E80\u305F\u3059\nll mod_inv(ll\
    \ val, ll mod) {\n  if (mod == 0) return 0;\n  mod = abs(mod);\n  val %= mod;\n\
    \  if (val < 0) val += mod;\n  ll a = val, b = mod, u = 1, v = 0, t;\n  while\
    \ (b > 0) {\n    t = a / b;\n    swap(a -= t * b, b), swap(u -= t * v, v);\n \
    \ }\n  if (u < 0) u += mod;\n  return u;\n}\n#line 1 \"mod/crt3.hpp\"\n\nconstexpr\
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
    \ T(ans_3) + T(c) * T(p01) * T(p23);\n}\n#line 1 \"poly/convolution_naive.hpp\"\
    \n\ntemplate <class T, typename enable_if<!has_mod<T>::value>::type* = nullptr>\n\
    vc<T> convolution_naive(const vc<T>& a, const vc<T>& b) {\n  int n = int(a.size()),\
    \ m = int(b.size());\n  if (n > m) return convolution_naive<T>(b, a);\n  if (n\
    \ == 0) return {};\n  vector<T> ans(n + m - 1);\n  FOR(i, n) FOR(j, m) ans[i +\
    \ j] += a[i] * b[j];\n  return ans;\n}\n\ntemplate <class T, typename enable_if<has_mod<T>::value>::type*\
    \ = nullptr>\nvc<T> convolution_naive(const vc<T>& a, const vc<T>& b) {\n  int\
    \ n = int(a.size()), m = int(b.size());\n  if (n > m) return convolution_naive<T>(b,\
    \ a);\n  if (n == 0) return {};\n  vc<T> ans(n + m - 1);\n  if (n <= 16 && (T::get_mod()\
    \ < (1 << 30))) {\n    for (int k = 0; k < n + m - 1; ++k) {\n      int s = max(0,\
    \ k - m + 1);\n      int t = min(n, k + 1);\n      u64 sm = 0;\n      for (int\
    \ i = s; i < t; ++i) { sm += u64(a[i].val) * (b[k - i].val); }\n      ans[k] =\
    \ sm;\n    }\n  } else {\n    for (int k = 0; k < n + m - 1; ++k) {\n      int\
    \ s = max(0, k - m + 1);\n      int t = min(n, k + 1);\n      u128 sm = 0;\n \
    \     for (int i = s; i < t; ++i) { sm += u64(a[i].val) * (b[k - i].val); }\n\
    \      ans[k] = T::raw(sm % T::get_mod());\n    }\n  }\n  return ans;\n}\n#line\
    \ 1 \"poly/convolution_naive.hpp\"\n\ntemplate <class T, typename enable_if<!has_mod<T>::value>::type*\
    \ = nullptr>\nvc<T> convolution_naive(const vc<T>& a, const vc<T>& b) {\n  int\
    \ n = int(a.size()), m = int(b.size());\n  if (n > m) return convolution_naive<T>(b,\
    \ a);\n  if (n == 0) return {};\n  vector<T> ans(n + m - 1);\n  FOR(i, n) FOR(j,\
    \ m) ans[i + j] += a[i] * b[j];\n  return ans;\n}\n\ntemplate <class T, typename\
    \ enable_if<has_mod<T>::value>::type* = nullptr>\nvc<T> convolution_naive(const\
    \ vc<T>& a, const vc<T>& b) {\n  int n = int(a.size()), m = int(b.size());\n \
    \ if (n > m) return convolution_naive<T>(b, a);\n  if (n == 0) return {};\n  vc<T>\
    \ ans(n + m - 1);\n  if (n <= 16 && (T::get_mod() < (1 << 30))) {\n    for (int\
    \ k = 0; k < n + m - 1; ++k) {\n      int s = max(0, k - m + 1);\n      int t\
    \ = min(n, k + 1);\n      u64 sm = 0;\n      for (int i = s; i < t; ++i) { sm\
    \ += u64(a[i].val) * (b[k - i].val); }\n      ans[k] = sm;\n    }\n  } else {\n\
    \    for (int k = 0; k < n + m - 1; ++k) {\n      int s = max(0, k - m + 1);\n\
    \      int t = min(n, k + 1);\n      u128 sm = 0;\n      for (int i = s; i < t;\
    \ ++i) { sm += u64(a[i].val) * (b[k - i].val); }\n      ans[k] = T::raw(sm % T::get_mod());\n\
    \    }\n  }\n  return ans;\n}\n#line 2 \"poly/convolution_karatsuba.hpp\"\n\n\
    // \u4EFB\u610F\u306E\u74B0\u3067\u3067\u304D\u308B\ntemplate <typename T>\nvc<T>\
    \ convolution_karatsuba(const vc<T>& f, const vc<T>& g) {\n  const int thresh\
    \ = 30;\n  if (min(len(f), len(g)) <= thresh) return convolution_naive(f, g);\n\
    \  int n = max(len(f), len(g));\n  int m = ceil(n, 2);\n  vc<T> f1, f2, g1, g2;\n\
    \  if (len(f) < m) f1 = f;\n  if (len(f) >= m) f1 = {f.begin(), f.begin() + m};\n\
    \  if (len(f) >= m) f2 = {f.begin() + m, f.end()};\n  if (len(g) < m) g1 = g;\n\
    \  if (len(g) >= m) g1 = {g.begin(), g.begin() + m};\n  if (len(g) >= m) g2 =\
    \ {g.begin() + m, g.end()};\n  vc<T> a = convolution_karatsuba(f1, g1);\n  vc<T>\
    \ b = convolution_karatsuba(f2, g2);\n  FOR(i, len(f2)) f1[i] += f2[i];\n  FOR(i,\
    \ len(g2)) g1[i] += g2[i];\n  vc<T> c = convolution_karatsuba(f1, g1);\n  vc<T>\
    \ F(len(f) + len(g) - 1);\n  assert(2 * m + len(b) <= len(F));\n  FOR(i, len(a))\
    \ F[i] += a[i], c[i] -= a[i];\n  FOR(i, len(b)) F[2 * m + i] += b[i], c[i] -=\
    \ b[i];\n  if (c.back() == T(0)) c.pop_back();\n  FOR(i, len(c)) if (c[i] != T(0))\
    \ F[m + i] += c[i];\n  return F;\n}\n#line 1 \"other/bit.hpp\"\n\nint popcnt(int\
    \ x) { return __builtin_popcount(x); }\nint popcnt(u32 x) { return __builtin_popcount(x);\
    \ }\nint popcnt(ll x) { return __builtin_popcountll(x); }\nint popcnt(u64 x) {\
    \ return __builtin_popcountll(x); }\nint popcnt_sgn(int x) { return (__builtin_parity(unsigned(x))\
    \ & 1 ? -1 : 1); }\nint popcnt_sgn(u32 x) { return (__builtin_parity(x) & 1 ?\
    \ -1 : 1); }\nint popcnt_sgn(ll x) { return (__builtin_parityll(x) & 1 ? -1 :\
    \ 1); }\nint popcnt_sgn(u64 x) { return (__builtin_parityll(x) & 1 ? -1 : 1);\
    \ }\n// (0, 1, 2, 3, 4) -> (-1, 0, 1, 1, 2)\nint topbit(int x) { return (x ==\
    \ 0 ? -1 : 31 - __builtin_clz(x)); }\nint topbit(u32 x) { return (x == 0 ? -1\
    \ : 31 - __builtin_clz(x)); }\nint topbit(ll x) { return (x == 0 ? -1 : 63 - __builtin_clzll(x));\
    \ }\nint topbit(u64 x) { return (x == 0 ? -1 : 63 - __builtin_clzll(x)); }\n//\
    \ (0, 1, 2, 3, 4) -> (-1, 0, 1, 0, 2)\nint lowbit(int x) { return (x == 0 ? -1\
    \ : __builtin_ctz(x)); }\nint lowbit(u32 x) { return (x == 0 ? -1 : __builtin_ctz(x));\
    \ }\nint lowbit(ll x) { return (x == 0 ? -1 : __builtin_ctzll(x)); }\nint lowbit(u64\
    \ x) { return (x == 0 ? -1 : __builtin_ctzll(x)); }\n\ntemplate <typename T>\n\
    T kth_bit(int k) {\n  return T(1) << k;\n}\ntemplate <typename T>\nbool has_kth_bit(T\
    \ x, int k) {\n  return x >> k & 1;\n}\n\ntemplate <typename UINT>\nstruct all_bit\
    \ {\n  UINT s;\n  all_bit(UINT s) : s(s) {}\n  struct iter {\n    UINT s;\n  \
    \  int operator*() const { return lowbit(s); }\n    void operator++() { s &= s\
    \ - 1; }\n    bool operator!=(nullptr_t) const { return s; }\n  };\n  iter begin()\
    \ const { return {s}; }\n  nullptr_t end() const { return nullptr; }\n};\n\ntemplate\
    \ <typename UINT>\nstruct all_subset {\n  UINT s;\n  all_subset(UINT s) : s(s)\
    \ {}\n  struct iter {\n    UINT s, t;\n    bool done = false;\n    UINT operator*()\
    \ const { return t; }\n    void operator++() {\n      done = (t == 0);\n     \
    \ t = (t - 1) & s;\n    }\n    bool operator!=(nullptr_t) const { return !done;\
    \ }\n  };\n  iter begin() const { return {s, s}; }\n  nullptr_t end() const {\
    \ return nullptr; }\n};\n\nconstexpr u64 full_mask(int n) { return n == 64 ? -1ULL\
    \ : (1ULL << n) - 1; }\n#line 2 \"poly/ntt.hpp\"\n\ntemplate <class mint>\nvoid\
    \ ntt(vector<mint>& a, bool inverse) {\n  assert(mint::can_ntt());\n  const int\
    \ rank2 = mint::ntt_info().fi;\n  const u32 mod = mint::get_mod();\n  static array<mint,\
    \ 30> root, iroot;\n  static array<mint, 30> rate2, irate2;\n  static array<mint,\
    \ 30> rate3, irate3;\n\n  assert(rank2 != -1 && len(a) <= (1 << max(0, rank2)));\n\
    \n  static bool prepared = 0;\n  if (!prepared) {\n    prepared = 1;\n    root[rank2]\
    \ = mint::ntt_info().se;\n    iroot[rank2] = mint(1) / root[rank2];\n    FOR_R(i,\
    \ rank2) {\n      root[i] = root[i + 1] * root[i + 1];\n      iroot[i] = iroot[i\
    \ + 1] * iroot[i + 1];\n    }\n    mint prod = 1, iprod = 1;\n    for (int i =\
    \ 0; i <= rank2 - 2; i++) {\n      rate2[i] = root[i + 2] * prod;\n      irate2[i]\
    \ = iroot[i + 2] * iprod;\n      prod *= iroot[i + 2];\n      iprod *= root[i\
    \ + 2];\n    }\n    prod = 1, iprod = 1;\n    for (int i = 0; i <= rank2 - 3;\
    \ i++) {\n      rate3[i] = root[i + 3] * prod;\n      irate3[i] = iroot[i + 3]\
    \ * iprod;\n      prod *= iroot[i + 3];\n      iprod *= root[i + 3];\n    }\n\
    \  }\n\n  int n = int(a.size());\n  int h = topbit(n);\n  assert(n == 1 << h);\n\
    \  if (!inverse) {\n    int len = 0;\n    while (len < h) {\n      if (h - len\
    \ == 1) {\n        int p = 1 << (h - len - 1);\n        mint rot = 1;\n      \
    \  FOR(s, 1 << len) {\n          int offset = s << (h - len);\n          FOR(i,\
    \ p) {\n            auto l = a[i + offset];\n            auto r = a[i + offset\
    \ + p] * rot;\n            a[i + offset] = l + r;\n            a[i + offset +\
    \ p] = l - r;\n          }\n          rot *= rate2[topbit(~s & -~s)];\n      \
    \  }\n        len++;\n      } else {\n        int p = 1 << (h - len - 2);\n  \
    \      mint rot = 1, imag = root[2];\n        for (int s = 0; s < (1 << len);\
    \ s++) {\n          mint rot2 = rot * rot;\n          mint rot3 = rot2 * rot;\n\
    \          int offset = s << (h - len);\n          for (int i = 0; i < p; i++)\
    \ {\n            u64 mod2 = u64(mod) * mod;\n            u64 a0 = a[i + offset].val;\n\
    \            u64 a1 = u64(a[i + offset + p].val) * rot.val;\n            u64 a2\
    \ = u64(a[i + offset + 2 * p].val) * rot2.val;\n            u64 a3 = u64(a[i +\
    \ offset + 3 * p].val) * rot3.val;\n            u64 a1na3imag = (a1 + mod2 - a3)\
    \ % mod * imag.val;\n            u64 na2 = mod2 - a2;\n            a[i + offset]\
    \ = a0 + a2 + a1 + a3;\n            a[i + offset + 1 * p] = a0 + a2 + (2 * mod2\
    \ - (a1 + a3));\n            a[i + offset + 2 * p] = a0 + na2 + a1na3imag;\n \
    \           a[i + offset + 3 * p] = a0 + na2 + (mod2 - a1na3imag);\n         \
    \ }\n          rot *= rate3[topbit(~s & -~s)];\n        }\n        len += 2;\n\
    \      }\n    }\n  } else {\n    mint coef = mint(1) / mint(len(a));\n    FOR(i,\
    \ len(a)) a[i] *= coef;\n    int len = h;\n    while (len) {\n      if (len ==\
    \ 1) {\n        int p = 1 << (h - len);\n        mint irot = 1;\n        FOR(s,\
    \ 1 << (len - 1)) {\n          int offset = s << (h - len + 1);\n          FOR(i,\
    \ p) {\n            u64 l = a[i + offset].val;\n            u64 r = a[i + offset\
    \ + p].val;\n            a[i + offset] = l + r;\n            a[i + offset + p]\
    \ = (mod + l - r) * irot.val;\n          }\n          irot *= irate2[topbit(~s\
    \ & -~s)];\n        }\n        len--;\n      } else {\n        int p = 1 << (h\
    \ - len);\n        mint irot = 1, iimag = iroot[2];\n        FOR(s, (1 << (len\
    \ - 2))) {\n          mint irot2 = irot * irot;\n          mint irot3 = irot2\
    \ * irot;\n          int offset = s << (h - len + 2);\n          for (int i =\
    \ 0; i < p; i++) {\n            u64 a0 = a[i + offset + 0 * p].val;\n        \
    \    u64 a1 = a[i + offset + 1 * p].val;\n            u64 a2 = a[i + offset +\
    \ 2 * p].val;\n            u64 a3 = a[i + offset + 3 * p].val;\n            u64\
    \ x = (mod + a2 - a3) * iimag.val % mod;\n            a[i + offset] = a0 + a1\
    \ + a2 + a3;\n            a[i + offset + 1 * p] = (a0 + mod - a1 + x) * irot.val;\n\
    \            a[i + offset + 2 * p] = (a0 + a1 + 2 * mod - a2 - a3) * irot2.val;\n\
    \            a[i + offset + 3 * p] = (a0 + 2 * mod - a1 - x) * irot3.val;\n  \
    \        }\n          irot *= irate3[topbit(~s & -~s)];\n        }\n        len\
    \ -= 2;\n      }\n    }\n  }\n}\n#line 8 \"poly/convolution.hpp\"\n\ntemplate\
    \ <class mint>\nvector<mint> convolution_ntt(vector<mint> a, vector<mint> b) {\n\
    \  assert(mint::can_ntt());\n  if (a.empty() || b.empty()) return {};\n  int n\
    \ = int(a.size()), m = int(b.size());\n  int sz = 1;\n  while (sz < n + m - 1)\
    \ sz *= 2;\n\n  // sz = 2^k \u306E\u3068\u304D\u306E\u9AD8\u901F\u5316\u3002\u5206\
    \u5272\u7D71\u6CBB\u7684\u306A\u3084\u3064\u3067\u640D\u3057\u307E\u304F\u308B\
    \u306E\u3067\u3002\n  if ((n + m - 3) <= sz / 2) {\n    auto a_last = a.back(),\
    \ b_last = b.back();\n    a.pop_back(), b.pop_back();\n    auto c = convolution(a,\
    \ b);\n    c.resize(n + m - 1);\n    c[n + m - 2] = a_last * b_last;\n    FOR(i,\
    \ len(a)) c[i + len(b)] += a[i] * b_last;\n    FOR(i, len(b)) c[i + len(a)] +=\
    \ b[i] * a_last;\n    return c;\n  }\n\n  a.resize(sz), b.resize(sz);\n  bool\
    \ same = a == b;\n  ntt(a, 0);\n  if (same) {\n    b = a;\n  } else {\n    ntt(b,\
    \ 0);\n  }\n  FOR(i, sz) a[i] *= b[i];\n  ntt(a, 1);\n  a.resize(n + m - 1);\n\
    \  return a;\n}\n\ntemplate <typename mint>\nvector<mint> convolution_garner(const\
    \ vector<mint>& a, const vector<mint>& b) {\n  int n = len(a), m = len(b);\n \
    \ if (!n || !m) return {};\n  static constexpr int p0 = 167772161;\n  static constexpr\
    \ int p1 = 469762049;\n  static constexpr int p2 = 754974721;\n  using mint0 =\
    \ modint<p0>;\n  using mint1 = modint<p1>;\n  using mint2 = modint<p2>;\n  vc<mint0>\
    \ a0(n), b0(m);\n  vc<mint1> a1(n), b1(m);\n  vc<mint2> a2(n), b2(m);\n  FOR(i,\
    \ n) a0[i] = a[i].val, a1[i] = a[i].val, a2[i] = a[i].val;\n  FOR(i, m) b0[i]\
    \ = b[i].val, b1[i] = b[i].val, b2[i] = b[i].val;\n  auto c0 = convolution_ntt<mint0>(a0,\
    \ b0);\n  auto c1 = convolution_ntt<mint1>(a1, b1);\n  auto c2 = convolution_ntt<mint2>(a2,\
    \ b2);\n  vc<mint> c(len(c0));\n  FOR(i, n + m - 1) {\n    c[i] = CRT3<mint, p0,\
    \ p1, p2>(c0[i].val, c1[i].val, c2[i].val);\n  }\n  return c;\n}\n\nvector<ll>\
    \ convolution(vector<ll> a, vector<ll> b) {\n  int n = len(a), m = len(b);\n \
    \ if (!n || !m) return {};\n  if (min(n, m) <= 2500) return convolution_naive(a,\
    \ b);\n\n  ll mi_a = MIN(a), mi_b = MIN(b);\n  for (auto& x : a) x -= mi_a;\n\
    \  for (auto& x : b) x -= mi_b;\n  assert(MAX(a) * MAX(b) <= 1e18);\n\n  auto\
    \ Ac = cumsum<ll>(a), Bc = cumsum<ll>(b);\n  vi res(n + m - 1);\n  for (int k\
    \ = 0; k < n + m - 1; ++k) {\n    int s = max(0, k - m + 1);\n    int t = min(n,\
    \ k + 1);\n    res[k] += (t - s) * mi_a * mi_b;\n    res[k] += mi_a * (Bc[k -\
    \ s + 1] - Bc[k - t + 1]);\n    res[k] += mi_b * (Ac[t] - Ac[s]);\n  }\n\n  static\
    \ constexpr u32 MOD1 = 1004535809;\n  static constexpr u32 MOD2 = 1012924417;\n\
    \  using mint1 = modint<MOD1>;\n  using mint2 = modint<MOD2>;\n\n  vc<mint1> a1(n),\
    \ b1(m);\n  vc<mint2> a2(n), b2(m);\n  FOR(i, n) a1[i] = a[i], a2[i] = a[i];\n\
    \  FOR(i, m) b1[i] = b[i], b2[i] = b[i];\n\n  auto c1 = convolution_ntt<mint1>(a1,\
    \ b1);\n  auto c2 = convolution_ntt<mint2>(a2, b2);\n\n  FOR(i, n + m - 1) { res[i]\
    \ += CRT2<u64, MOD1, MOD2>(c1[i].val, c2[i].val); }\n  return res;\n}\n\ntemplate\
    \ <typename mint>\nvc<mint> convolution(const vc<mint>& a, const vc<mint>& b)\
    \ {\n  if (mint::get_mod() == 2) {\n    vc<modint998> aa, bb;\n    for (auto&\
    \ x : a) aa.eb(x.val);\n    for (auto& x : b) bb.eb(x.val);\n    aa = convolution<modint998>(aa,\
    \ bb);\n    vc<mint> ANS(len(aa));\n    FOR(i, len(aa)) ANS[i] = aa[i].val & 1;\n\
    \    return ANS;\n  }\n  int n = len(a), m = len(b);\n  if (!n || !m) return {};\n\
    \  if (mint::can_ntt()) {\n    if (min(n, m) <= 50) return convolution_karatsuba<mint>(a,\
    \ b);\n    return convolution_ntt(a, b);\n  }\n  if (min(n, m) <= 200) return\
    \ convolution_karatsuba<mint>(a, b);\n  return convolution_garner(a, b);\n}\n\
    #line 3 \"poly/fps_inv.hpp\"\n\ntemplate <typename mint>\nvc<mint> fps_inv_sparse(const\
    \ vc<mint>& f) {\n  int N = len(f);\n  vc<pair<int, mint>> dat;\n  FOR(i, 1, N)\
    \ if (f[i] != mint(0)) dat.eb(i, f[i]);\n  vc<mint> g(N);\n  mint g0 = mint(1)\
    \ / f[0];\n  g[0] = g0;\n  FOR(n, 1, N) {\n    mint rhs = 0;\n    for (auto&&\
    \ [k, fk]: dat) {\n      if (k > n) break;\n      rhs -= fk * g[n - k];\n    }\n\
    \    g[n] = rhs * g0;\n  }\n  return g;\n}\n\ntemplate <typename mint>\nvc<mint>\
    \ fps_inv_dense_ntt(const vc<mint>& F) {\n  vc<mint> G = {mint(1) / F[0]};\n \
    \ ll N = len(F), n = 1;\n  G.reserve(N);\n  while (n < N) {\n    vc<mint> f(2\
    \ * n), g(2 * n);\n    FOR(i, min(N, 2 * n)) f[i] = F[i];\n    FOR(i, n) g[i]\
    \ = G[i];\n    ntt(f, false), ntt(g, false);\n    FOR(i, 2 * n) f[i] *= g[i];\n\
    \    ntt(f, true);\n    FOR(i, n) f[i] = 0;\n    ntt(f, false);\n    FOR(i, 2\
    \ * n) f[i] *= g[i];\n    ntt(f, true);\n    FOR(i, n, min(N, 2 * n)) G.eb(-f[i]);\n\
    \    n *= 2;\n  }\n  return G;\n}\n\ntemplate <typename mint>\nvc<mint> fps_inv_dense(const\
    \ vc<mint>& F) {\n  if (mint::can_ntt()) return fps_inv_dense_ntt(F);\n  const\
    \ int N = len(F);\n  vc<mint> R = {mint(1) / F[0]};\n  vc<mint> p;\n  int m =\
    \ 1;\n  while (m < N) {\n    p = convolution(R, R);\n    p.resize(m + m);\n  \
    \  vc<mint> f = {F.begin(), F.begin() + min(m + m, N)};\n    p = convolution(p,\
    \ f);\n    R.resize(m + m);\n    FOR(i, m + m) R[i] = R[i] + R[i] - p[i];\n  \
    \  m += m;\n  }\n  R.resize(N);\n  return R;\n}\n\ntemplate <typename mint>\n\
    vc<mint> fps_inv(const vc<mint>& f) {\n  assert(f[0] != mint(0));\n  int n = count_terms(f);\n\
    \  int t = (mint::can_ntt() ? 160 : 820);\n  return (n <= t ? fps_inv_sparse<mint>(f)\
    \ : fps_inv_dense<mint>(f));\n}\n#line 4 \"poly/fps_div.hpp\"\n\n// f/g. f \u306E\
    \u9577\u3055\u3067\u51FA\u529B\u3055\u308C\u308B.\ntemplate <typename mint, bool\
    \ SPARSE = false>\nvc<mint> fps_div(vc<mint> f, vc<mint> g) {\n  if (SPARSE ||\
    \ count_terms(g) < 200) return fps_div_sparse(f, g);\n  int n = len(f);\n  g.resize(n);\n\
    \  g = fps_inv<mint>(g);\n  f = convolution(f, g);\n  f.resize(n);\n  return f;\n\
    }\n\n// f/g \u305F\u3060\u3057 g \u306F sparse\ntemplate <typename mint>\nvc<mint>\
    \ fps_div_sparse(vc<mint> f, vc<mint>& g) {\n  if (g[0] != mint(1)) {\n    mint\
    \ cf = g[0].inverse();\n    for (auto&& x: f) x *= cf;\n    for (auto&& x: g)\
    \ x *= cf;\n  }\n\n  vc<pair<int, mint>> dat;\n  FOR(i, 1, len(g)) if (g[i] !=\
    \ mint(0)) dat.eb(i, -g[i]);\n  FOR(i, len(f)) {\n    for (auto&& [j, x]: dat)\
    \ {\n      if (i >= j) f[i] += x * f[i - j];\n    }\n  }\n  return f;\n}\n#line\
    \ 4 \"poly/multipoint_evaluation_for_prefix_product.hpp\"\n\n// F[0](point[i])\
    \ ... F[CNT[i]-1](point[i])\ntemplate <typename mint>\nvc<mint> multipoint_evaluation_for_prefix_product(vvc<mint>\
    \ F, vc<mint> point, vc<int> CNT) {\n  int N = len(point);\n  if (N == 0) return\
    \ {};\n  auto I = argsort(CNT);\n  point = rearrange(point, I), CNT = rearrange(CNT,\
    \ I);\n  vvc<mint> G1, G2;\n  vvvc<mint> L(N), R(N);\n  FOR(i, N) {\n    vc<mint>\
    \ f{mint(1), -point[i]};\n    L[i].eb(f), R[i].eb(f), G2.eb(f);\n  }\n  int K\
    \ = 0;\n  for (auto& f: F) reverse(all(f));\n  FOR(i, CNT[0]) { G1.eb(F[i]), K\
    \ += len(F[i]) - 1; }\n  FOR(j, N - 1) {\n    FOR(k, CNT[j], CNT[j + 1]) {\n \
    \     vc<mint> g(len(F[k]));\n      g.back() = 1;\n      L[j].eb(F[k]), R[j +\
    \ 1].eb(g), K += len(g) - 1;\n    }\n  }\n  Typical_Divide_Conquer<mint> TDC(N);\n\
    \  FOR(i, N - 1) TDC.set_L(i, convolution_all<mint>(L[i]));\n  FOR(i, 1, N) TDC.set_R(i,\
    \ convolution_all<mint>(R[i]));\n  vc<mint> g1 = convolution_all<mint>(G1);\n\
    \  vc<mint> g2 = convolution_all<mint>(G2);\n  g1.resize(K + 1), g2.resize(K +\
    \ 1);\n  vc<mint> ANS = TDC.calc(K, fps_div<mint>(g1, g2));\n  I = argsort(I);\n\
    \  ANS = rearrange(ANS, I);\n  return ANS;\n}\n"
  code: "#include \"poly/typical_divide_conquer.hpp\"\n#include \"poly/convolution_all.hpp\"\
    \n#include \"poly/fps_div.hpp\"\n\n// F[0](point[i]) ... F[CNT[i]-1](point[i])\n\
    template <typename mint>\nvc<mint> multipoint_evaluation_for_prefix_product(vvc<mint>\
    \ F, vc<mint> point, vc<int> CNT) {\n  int N = len(point);\n  if (N == 0) return\
    \ {};\n  auto I = argsort(CNT);\n  point = rearrange(point, I), CNT = rearrange(CNT,\
    \ I);\n  vvc<mint> G1, G2;\n  vvvc<mint> L(N), R(N);\n  FOR(i, N) {\n    vc<mint>\
    \ f{mint(1), -point[i]};\n    L[i].eb(f), R[i].eb(f), G2.eb(f);\n  }\n  int K\
    \ = 0;\n  for (auto& f: F) reverse(all(f));\n  FOR(i, CNT[0]) { G1.eb(F[i]), K\
    \ += len(F[i]) - 1; }\n  FOR(j, N - 1) {\n    FOR(k, CNT[j], CNT[j + 1]) {\n \
    \     vc<mint> g(len(F[k]));\n      g.back() = 1;\n      L[j].eb(F[k]), R[j +\
    \ 1].eb(g), K += len(g) - 1;\n    }\n  }\n  Typical_Divide_Conquer<mint> TDC(N);\n\
    \  FOR(i, N - 1) TDC.set_L(i, convolution_all<mint>(L[i]));\n  FOR(i, 1, N) TDC.set_R(i,\
    \ convolution_all<mint>(R[i]));\n  vc<mint> g1 = convolution_all<mint>(G1);\n\
    \  vc<mint> g2 = convolution_all<mint>(G2);\n  g1.resize(K + 1), g2.resize(K +\
    \ 1);\n  vc<mint> ANS = TDC.calc(K, fps_div<mint>(g1, g2));\n  I = argsort(I);\n\
    \  ANS = rearrange(ANS, I);\n  return ANS;\n}\n"
  dependsOn:
  - poly/typical_divide_conquer.hpp
  - poly/convolution.hpp
  - mod/modint.hpp
  - mod/modint_common.hpp
  - other/bit.hpp
  - mod/mod_inv.hpp
  - mod/crt3.hpp
  - poly/convolution_naive.hpp
  - poly/convolution_karatsuba.hpp
  - poly/ntt.hpp
  - poly/middle_product.hpp
  - poly/convolution_all.hpp
  - poly/ntt_doubling.hpp
  - poly/fps_div.hpp
  - poly/count_terms.hpp
  - poly/fps_inv.hpp
  isVerificationFile: false
  path: poly/multipoint_evaluation_for_prefix_product.hpp
  requiredBy: []
  timestamp: '2026-08-16 04:03:00+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/1_mytest/multipoint_prefix.test.cpp
documentation_of: poly/multipoint_evaluation_for_prefix_product.hpp
layout: document
redirect_from:
- /library/poly/multipoint_evaluation_for_prefix_product.hpp
- /library/poly/multipoint_evaluation_for_prefix_product.hpp.html
title: poly/multipoint_evaluation_for_prefix_product.hpp
---
