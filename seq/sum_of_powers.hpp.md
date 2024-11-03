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
    path: poly/fps_log.hpp
    title: poly/fps_log.hpp
  - icon: ':heavy_check_mark:'
    path: poly/ntt.hpp
    title: poly/ntt.hpp
  - icon: ':heavy_check_mark:'
    path: poly/ntt_doubling.hpp
    title: poly/ntt_doubling.hpp
  - icon: ':heavy_check_mark:'
    path: poly/sum_of_rationals.hpp
    title: poly/sum_of_rationals.hpp
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/3_yukicoder/1145.test.cpp
    title: test/3_yukicoder/1145.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/3_yukicoder/1575.test.cpp
    title: test/3_yukicoder/1575.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/3_yukicoder/2459.test.cpp
    title: test/3_yukicoder/2459.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/3_yukicoder/2747.test.cpp
    title: test/3_yukicoder/2747.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 2 \"poly/convolution_all.hpp\"\n\r\n#line 2 \"mod/modint_common.hpp\"\
    \n\nstruct has_mod_impl {\n  template <class T>\n  static auto check(T &&x) ->\
    \ decltype(x.get_mod(), std::true_type{});\n  template <class T>\n  static auto\
    \ check(...) -> std::false_type;\n};\n\ntemplate <class T>\nclass has_mod : public\
    \ decltype(has_mod_impl::check<T>(std::declval<T>())) {};\n\ntemplate <typename\
    \ mint>\nmint inv(int n) {\n  static const int mod = mint::get_mod();\n  static\
    \ vector<mint> dat = {0, 1};\n  assert(0 <= n);\n  if (n >= mod) n %= mod;\n \
    \ while (len(dat) <= n) {\n    int k = len(dat);\n    int q = (mod + k - 1) /\
    \ k;\n    dat.eb(dat[k * q - mod] * mint::raw(q));\n  }\n  return dat[n];\n}\n\
    \ntemplate <typename mint>\nmint fact(int n) {\n  static const int mod = mint::get_mod();\n\
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
    }\r\n#line 2 \"poly/ntt_doubling.hpp\"\n\n#line 4 \"poly/ntt_doubling.hpp\"\n\n\
    // 2^k \u6B21\u591A\u9805\u5F0F\u306E\u9577\u3055 2^k \u304C\u4E0E\u3048\u3089\
    \u308C\u308B\u306E\u3067 2^k+1 \u306B\u3059\u308B\ntemplate <typename mint, bool\
    \ transposed = false>\nvoid ntt_doubling(vector<mint>& a) {\n  static array<mint,\
    \ 30> root;\n  static bool prepared = 0;\n  if (!prepared) {\n    prepared = 1;\n\
    \    const int rank2 = mint::ntt_info().fi;\n    root[rank2] = mint::ntt_info().se;\n\
    \    FOR_R(i, rank2) { root[i] = root[i + 1] * root[i + 1]; }\n  }\n\n  if constexpr\
    \ (!transposed) {\n    const int M = (int)a.size();\n    auto b = a;\n    ntt(b,\
    \ 1);\n    mint r = 1, zeta = root[topbit(2 * M)];\n    FOR(i, M) b[i] *= r, r\
    \ *= zeta;\n    ntt(b, 0);\n    copy(begin(b), end(b), back_inserter(a));\n  }\
    \ else {\n    const int M = len(a) / 2;\n    vc<mint> tmp = {a.begin(), a.begin()\
    \ + M};\n    a = {a.begin() + M, a.end()};\n    transposed_ntt(a, 0);\n    mint\
    \ r = 1, zeta = root[topbit(2 * M)];\n    FOR(i, M) a[i] *= r, r *= zeta;\n  \
    \  transposed_ntt(a, 1);\n    FOR(i, M) a[i] += tmp[i];\n  }\n}\n#line 5 \"poly/convolution_all.hpp\"\
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
    \ + 1);\r\n  return F;\r\n}\n#line 2 \"poly/fps_log.hpp\"\n\r\n#line 2 \"poly/count_terms.hpp\"\
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
    \n}\r\n#line 5 \"poly/fps_log.hpp\"\n\r\ntemplate <typename mint>\r\nvc<mint>\
    \ fps_log_dense(const vc<mint>& f) {\r\n  assert(f[0] == mint(1));\r\n  ll N =\
    \ len(f);\r\n  vc<mint> df = f;\r\n  FOR(i, N) df[i] *= mint(i);\r\n  df.erase(df.begin());\r\
    \n  auto f_inv = fps_inv(f);\r\n  auto g = convolution(df, f_inv);\r\n  g.resize(N\
    \ - 1);\r\n  g.insert(g.begin(), 0);\r\n  FOR(i, N) g[i] *= inv<mint>(i);\r\n\
    \  return g;\r\n}\r\n\r\ntemplate <typename mint>\r\nvc<mint> fps_log_sparse(const\
    \ vc<mint>& f) {\r\n  int N = f.size();\r\n  vc<pair<int, mint>> dat;\r\n  FOR(i,\
    \ 1, N) if (f[i] != mint(0)) dat.eb(i, f[i]);\r\n  vc<mint> F(N);\r\n  vc<mint>\
    \ g(N - 1);\r\n  for (int n = 0; n < N - 1; ++n) {\r\n    mint rhs = mint(n +\
    \ 1) * f[n + 1];\r\n    for (auto&& [i, fi]: dat) {\r\n      if (i > n) break;\r\
    \n      rhs -= fi * g[n - i];\r\n    }\r\n    g[n] = rhs;\r\n    F[n + 1] = rhs\
    \ * inv<mint>(n + 1);\r\n  }\r\n  return F;\r\n}\r\n\r\ntemplate <typename mint>\r\
    \nvc<mint> fps_log(const vc<mint>& f) {\r\n  assert(f[0] == mint(1));\r\n  int\
    \ n = count_terms(f);\r\n  int t = (mint::can_ntt() ? 200 : 1200);\r\n  return\
    \ (n <= t ? fps_log_sparse<mint>(f) : fps_log_dense<mint>(f));\r\n}\r\n#line 2\
    \ \"poly/fps_div.hpp\"\n\n#line 5 \"poly/fps_div.hpp\"\n\n// f/g. f \u306E\u9577\
    \u3055\u3067\u51FA\u529B\u3055\u308C\u308B.\ntemplate <typename mint, bool SPARSE\
    \ = false>\nvc<mint> fps_div(vc<mint> f, vc<mint> g) {\n  if (SPARSE || count_terms(g)\
    \ < 200) return fps_div_sparse(f, g);\n  int n = len(f);\n  g.resize(n);\n  g\
    \ = fps_inv<mint>(g);\n  f = convolution(f, g);\n  f.resize(n);\n  return f;\n\
    }\n\n// f/g \u305F\u3060\u3057 g \u306F sparse\ntemplate <typename mint>\nvc<mint>\
    \ fps_div_sparse(vc<mint> f, vc<mint>& g) {\n  if (g[0] != mint(1)) {\n    mint\
    \ cf = g[0].inverse();\n    for (auto&& x: f) x *= cf;\n    for (auto&& x: g)\
    \ x *= cf;\n  }\n\n  vc<pair<int, mint>> dat;\n  FOR(i, 1, len(g)) if (g[i] !=\
    \ mint(0)) dat.eb(i, -g[i]);\n  FOR(i, len(f)) {\n    for (auto&& [j, x]: dat)\
    \ {\n      if (i >= j) f[i] += x * f[i - j];\n    }\n  }\n  return f;\n}\n#line\
    \ 2 \"poly/sum_of_rationals.hpp\"\n\n#line 5 \"poly/sum_of_rationals.hpp\"\n\n\
    // \u6709\u7406\u5F0F\u306E\u548C\u3092\u8A08\u7B97\u3059\u308B\u3002\u5206\u5272\
    \u7D71\u6CBB O(Nlog^2N)\u3002N \u306F\u6B21\u6570\u306E\u548C\u3002\ntemplate\
    \ <typename mint>\npair<vc<mint>, vc<mint>> sum_of_rationals(vc<pair<vc<mint>,\
    \ vc<mint>>> dat) {\n  if (len(dat) == 0) {\n    vc<mint> f = {0}, g = {1};\n\
    \    return {f, g};\n  }\n  using P = pair<vc<mint>, vc<mint>>;\n  auto add =\
    \ [&](P& a, P& b) -> P {\n    int na = len(a.fi) - 1, da = len(a.se) - 1;\n  \
    \  int nb = len(b.fi) - 1, db = len(b.se) - 1;\n    int n = max(na + db, da +\
    \ nb);\n    vc<mint> num(n + 1);\n    {\n      auto f = convolution(a.fi, b.se);\n\
    \      FOR(i, len(f)) num[i] += f[i];\n    }\n    {\n      auto f = convolution(a.se,\
    \ b.fi);\n      FOR(i, len(f)) num[i] += f[i];\n    }\n    auto den = convolution(a.se,\
    \ b.se);\n    return {num, den};\n  };\n\n  while (len(dat) > 1) {\n    int n\
    \ = len(dat);\n    FOR(i, 1, n, 2) { dat[i - 1] = add(dat[i - 1], dat[i]); }\n\
    \    FOR(i, ceil(n, 2)) dat[i] = dat[2 * i];\n    dat.resize(ceil(n, 2));\n  }\n\
    \  return dat[0];\n}\n\n// sum wt[i]/(1-A[i]x)\ntemplate <typename mint>\npair<vc<mint>,\
    \ vc<mint>> sum_of_rationals_1(vc<mint> A, vc<mint> wt) {\n  using poly = vc<mint>;\n\
    \  if (!mint::can_ntt()) {\n    vc<pair<poly, poly>> rationals;\n    FOR(i, len(A))\
    \ rationals.eb(poly({wt[i]}), poly({mint(1), -A[i]}));\n    return sum_of_rationals(rationals);\n\
    \  }\n  int n = 1;\n  while (n < len(A)) n *= 2;\n  int k = topbit(n);\n  vc<mint>\
    \ F(n), G(n);\n  vc<mint> nxt_F(n), nxt_G(n);\n  FOR(i, len(A)) F[i] = -A[i],\
    \ G[i] = wt[i];\n  int D = 6;\n\n  FOR(d, k) {\n    int b = 1 << d;\n    if (d\
    \ < D) {\n      fill(all(nxt_F), mint(0)), fill(all(nxt_G), mint(0));\n      for\
    \ (int L = 0; L < n; L += 2 * b) {\n        FOR(i, b) FOR(j, b) nxt_F[L + i +\
    \ j] += F[L + i] * F[L + b + j];\n        FOR(i, b) FOR(j, b) nxt_G[L + i + j]\
    \ += F[L + i] * G[L + b + j];\n        FOR(i, b) FOR(j, b) nxt_G[L + i + j] +=\
    \ F[L + b + i] * G[L + j];\n        FOR(i, b) nxt_F[L + b + i] += F[L + i] + F[L\
    \ + b + i];\n        FOR(i, b) nxt_G[L + b + i] += G[L + i] + G[L + b + i];\n\
    \      }\n    }\n    elif (d == D) {\n      for (int L = 0; L < n; L += 2 * b)\
    \ {\n        poly f1 = {F.begin() + L, F.begin() + L + b};\n        poly f2 =\
    \ {F.begin() + L + b, F.begin() + L + 2 * b};\n        poly g1 = {G.begin() +\
    \ L, G.begin() + L + b};\n        poly g2 = {G.begin() + L + b, G.begin() + L\
    \ + 2 * b};\n        f1.resize(2 * b), f2.resize(2 * b), g1.resize(2 * b), g2.resize(2\
    \ * b);\n        ntt(f1, 0), ntt(f2, 0), ntt(g1, 0), ntt(g2, 0);\n        FOR(i,\
    \ b) f1[i] += 1, f2[i] += 1;\n        FOR(i, b, 2 * b) f1[i] -= 1, f2[i] -= 1;\n\
    \        FOR(i, 2 * b) nxt_F[L + i] = f1[i] * f2[i] - 1;\n        FOR(i, 2 * b)\
    \ nxt_G[L + i] = g1[i] * f2[i] + g2[i] * f1[i];\n      }\n    }\n    else {\n\
    \      for (int L = 0; L < n; L += 2 * b) {\n        poly f1 = {F.begin() + L,\
    \ F.begin() + L + b};\n        poly f2 = {F.begin() + L + b, F.begin() + L + 2\
    \ * b};\n        poly g1 = {G.begin() + L, G.begin() + L + b};\n        poly g2\
    \ = {G.begin() + L + b, G.begin() + L + 2 * b};\n        ntt_doubling(f1), ntt_doubling(f2),\
    \ ntt_doubling(g1), ntt_doubling(g2);\n        FOR(i, b) f1[i] += 1, f2[i] +=\
    \ 1;\n        FOR(i, b, 2 * b) f1[i] -= 1, f2[i] -= 1;\n        FOR(i, 2 * b)\
    \ nxt_F[L + i] = f1[i] * f2[i] - 1;\n        FOR(i, 2 * b) nxt_G[L + i] = g1[i]\
    \ * f2[i] + g2[i] * f1[i];\n      }\n    }\n    swap(F, nxt_F), swap(G, nxt_G);\n\
    \  }\n  if (k - 1 >= D) ntt(F, 1), ntt(G, 1);\n  F.eb(1);\n  reverse(all(F)),\
    \ reverse(all(G));\n  F.resize(len(A) + 1);\n  G.resize(len(A));\n  return {G,\
    \ F};\n}\n#line 5 \"seq/sum_of_powers.hpp\"\n\n// sum_{a in A} a^n \u3092\u3001\
    n = 0, 1, ..., N \u3067\u5217\u6319\ntemplate <typename T>\nvc<T> sum_of_powers(const\
    \ vc<T>& A, ll N) {\n  auto f = convolution_all_1<T>(A);\n  f.resize(N + 1);\n\
    \  f = fps_log(f);\n  FOR(i, len(f)) f[i] = -f[i] * T(i);\n  f[0] = len(A);\n\
    \  return f;\n}\n\n// sum_{i in [L, R)} i^n \u3092\u3001n = 0, 1, ..., N \u3067\
    \u5217\u6319\ntemplate <typename T>\nvc<T> sum_of_powers_iota(ll L, ll R, ll N)\
    \ {\n  vc<T> F(N + 1), G(N + 1);\n  T powL = 1, powR = 1;\n  FOR(i, 1, N + 2)\
    \ {\n    powL *= T(L), powR *= T(R);\n    F[i - 1] = (powR - powL) * fact_inv<T>(i);\n\
    \    G[i - 1] = fact_inv<T>(i);\n  }\n  F = fps_div(F, G);\n  FOR(i, N + 1) F[i]\
    \ *= fact<T>(i);\n  return F;\n}\n\n// sum ca^n \u3092 n=0,1,...,N \u3067\u5217\
    \u6319\ntemplate <typename T>\nvc<T> sum_of_powers_with_coef(const vc<T>& A, const\
    \ vc<T>& C, int N) {\n  auto [num, den] = sum_of_rationals_1(A, C);\n  num.resize(N\
    \ + 1);\n  den.resize(N + 1);\n  auto f = fps_inv(den);\n  f = convolution(f,\
    \ num);\n  f.resize(N + 1);\n  return f;\n}\n"
  code: "#include \"poly/convolution_all.hpp\"\n#include \"poly/fps_log.hpp\"\n#include\
    \ \"poly/fps_div.hpp\"\n#include \"poly/sum_of_rationals.hpp\"\n\n// sum_{a in\
    \ A} a^n \u3092\u3001n = 0, 1, ..., N \u3067\u5217\u6319\ntemplate <typename T>\n\
    vc<T> sum_of_powers(const vc<T>& A, ll N) {\n  auto f = convolution_all_1<T>(A);\n\
    \  f.resize(N + 1);\n  f = fps_log(f);\n  FOR(i, len(f)) f[i] = -f[i] * T(i);\n\
    \  f[0] = len(A);\n  return f;\n}\n\n// sum_{i in [L, R)} i^n \u3092\u3001n =\
    \ 0, 1, ..., N \u3067\u5217\u6319\ntemplate <typename T>\nvc<T> sum_of_powers_iota(ll\
    \ L, ll R, ll N) {\n  vc<T> F(N + 1), G(N + 1);\n  T powL = 1, powR = 1;\n  FOR(i,\
    \ 1, N + 2) {\n    powL *= T(L), powR *= T(R);\n    F[i - 1] = (powR - powL) *\
    \ fact_inv<T>(i);\n    G[i - 1] = fact_inv<T>(i);\n  }\n  F = fps_div(F, G);\n\
    \  FOR(i, N + 1) F[i] *= fact<T>(i);\n  return F;\n}\n\n// sum ca^n \u3092 n=0,1,...,N\
    \ \u3067\u5217\u6319\ntemplate <typename T>\nvc<T> sum_of_powers_with_coef(const\
    \ vc<T>& A, const vc<T>& C, int N) {\n  auto [num, den] = sum_of_rationals_1(A,\
    \ C);\n  num.resize(N + 1);\n  den.resize(N + 1);\n  auto f = fps_inv(den);\n\
    \  f = convolution(f, num);\n  f.resize(N + 1);\n  return f;\n}"
  dependsOn:
  - poly/convolution_all.hpp
  - poly/convolution.hpp
  - mod/modint.hpp
  - mod/modint_common.hpp
  - mod/mod_inv.hpp
  - mod/crt3.hpp
  - poly/convolution_naive.hpp
  - poly/convolution_karatsuba.hpp
  - poly/ntt.hpp
  - poly/ntt_doubling.hpp
  - poly/fps_log.hpp
  - poly/fps_inv.hpp
  - poly/count_terms.hpp
  - poly/fps_div.hpp
  - poly/sum_of_rationals.hpp
  isVerificationFile: false
  path: seq/sum_of_powers.hpp
  requiredBy: []
  timestamp: '2024-10-25 01:17:46+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/3_yukicoder/1145.test.cpp
  - test/3_yukicoder/2459.test.cpp
  - test/3_yukicoder/1575.test.cpp
  - test/3_yukicoder/2747.test.cpp
documentation_of: seq/sum_of_powers.hpp
layout: document
redirect_from:
- /library/seq/sum_of_powers.hpp
- /library/seq/sum_of_powers.hpp.html
title: seq/sum_of_powers.hpp
---
