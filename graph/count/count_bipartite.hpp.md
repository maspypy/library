---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: alg/monoid/mul.hpp
    title: alg/monoid/mul.hpp
  - icon: ':heavy_check_mark:'
    path: ds/power_query.hpp
    title: ds/power_query.hpp
  - icon: ':heavy_check_mark:'
    path: mod/barrett.hpp
    title: mod/barrett.hpp
  - icon: ':heavy_check_mark:'
    path: mod/crt3.hpp
    title: mod/crt3.hpp
  - icon: ':heavy_check_mark:'
    path: mod/mod_inv.hpp
    title: mod/mod_inv.hpp
  - icon: ':heavy_check_mark:'
    path: mod/mod_pow.hpp
    title: mod/mod_pow.hpp
  - icon: ':heavy_check_mark:'
    path: mod/mod_sqrt.hpp
    title: mod/mod_sqrt.hpp
  - icon: ':heavy_check_mark:'
    path: mod/modint.hpp
    title: mod/modint.hpp
  - icon: ':heavy_check_mark:'
    path: mod/modint_common.hpp
    title: mod/modint_common.hpp
  - icon: ':heavy_check_mark:'
    path: mod/mongomery_modint.hpp
    title: mod/mongomery_modint.hpp
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
    path: poly/fft.hpp
    title: poly/fft.hpp
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
    path: poly/fps_sqrt.hpp
    title: poly/fps_sqrt.hpp
  - icon: ':heavy_check_mark:'
    path: poly/integrate.hpp
    title: poly/integrate.hpp
  - icon: ':heavy_check_mark:'
    path: poly/ntt.hpp
    title: poly/ntt.hpp
  - icon: ':heavy_check_mark:'
    path: random/base.hpp
    title: random/base.hpp
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/mytest/count_bipartite.test.cpp
    title: test/mytest/count_bipartite.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links:
    - https://oeis.org/A001832
    - https://oeis.org/A047864
  bundledCode: "#line 2 \"poly/fps_log.hpp\"\n\r\n#line 2 \"poly/count_terms.hpp\"\
    \ntemplate<typename mint>\r\nint count_terms(const vc<mint>& f){\r\n  int t =\
    \ 0;\r\n  FOR(i, len(f)) if(f[i] != mint(0)) ++t;\r\n  return t;\r\n}\n#line 2\
    \ \"mod/modint_common.hpp\"\n\nstruct has_mod_impl {\n  template <class T>\n \
    \ static auto check(T &&x) -> decltype(x.get_mod(), std::true_type{});\n  template\
    \ <class T>\n  static auto check(...) -> std::false_type;\n};\n\ntemplate <class\
    \ T>\nclass has_mod : public decltype(has_mod_impl::check<T>(std::declval<T>()))\
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
    \ 31};\n    if (mod == 1045430273) return {20, 363};\n    if (mod == 1051721729)\
    \ return {20, 330};\n    if (mod == 1053818881) return {20, 2789};\n    return\
    \ {-1, -1};\n  }\n  static constexpr bool can_ntt() { return ntt_info().fi !=\
    \ -1; }\n};\n\n#ifdef FASTIO\ntemplate <int mod>\nvoid rd(modint<mod> &x) {\n\
    \  fastio::rd(x.val);\n  x.val %= mod;\n  // assert(0 <= x.val && x.val < mod);\n\
    }\ntemplate <int mod>\nvoid wt(modint<mod> x) {\n  fastio::wt(x.val);\n}\n#endif\n\
    \nusing modint107 = modint<1000000007>;\nusing modint998 = modint<998244353>;\n\
    #line 2 \"mod/mod_inv.hpp\"\n\r\n// long \u3067\u3082\u5927\u4E08\u592B\r\n//\
    \ (val * x - 1) \u304C mod \u306E\u500D\u6570\u306B\u306A\u308B\u3088\u3046\u306B\
    \u3059\u308B\r\n// \u7279\u306B mod=0 \u306A\u3089 x=0 \u304C\u6E80\u305F\u3059\
    \r\nll mod_inv(ll val, ll mod) {\r\n  if (mod == 0) return 0;\r\n  mod = abs(mod);\r\
    \n  val %= mod;\r\n  if (val < 0) val += mod;\r\n  ll a = val, b = mod, u = 1,\
    \ v = 0, t;\r\n  while (b > 0) {\r\n    t = a / b;\r\n    swap(a -= t * b, b),\
    \ swap(u -= t * v, v);\r\n  }\r\n  if (u < 0) u += mod;\r\n  return u;\r\n}\r\n\
    #line 1 \"mod/crt3.hpp\"\n\nconstexpr u32 mod_pow_constexpr(u64 a, u64 n, u32\
    \ mod) {\n  a %= mod;\n  u64 res = 1;\n  FOR(32) {\n    if (n & 1) res = res *\
    \ a % mod;\n    a = a * a % mod, n /= 2;\n  }\n  return res;\n}\n\ntemplate <typename\
    \ T, u32 p0, u32 p1, u32 p2>\nT CRT3(u64 a0, u64 a1, u64 a2) {\n  static_assert(p0\
    \ < p1 && p1 < p2);\n  static constexpr u64 x0_1 = mod_pow_constexpr(p0, p1 -\
    \ 2, p1);\n  static constexpr u64 x01_2 = mod_pow_constexpr(u64(p0) * p1 % p2,\
    \ p2 - 2, p2);\n  u64 c = (a1 - a0 + p1) * x0_1 % p1;\n  u64 a = a0 + c * p0;\n\
    \  c = (a2 - a % p2 + p2) * x01_2 % p2;\n  return T(a) + T(c) * T(p0) * T(p1);\n\
    }\n#line 2 \"poly/convolution_naive.hpp\"\n\r\ntemplate <class T, typename enable_if<!has_mod<T>::value>::type*\
    \ = nullptr>\r\nvc<T> convolution_naive(const vc<T>& a, const vc<T>& b) {\r\n\
    \  int n = int(a.size()), m = int(b.size());\r\n  if (n > m) return convolution_naive<T>(b,\
    \ a);\r\n  if (n == 0) return {};\r\n  vector<T> ans(n + m - 1);\r\n  FOR(i, n)\
    \ FOR(j, m) ans[i + j] += a[i] * b[j];\r\n  return ans;\r\n}\r\n\r\ntemplate <class\
    \ T, typename enable_if<has_mod<T>::value>::type* = nullptr>\r\nvc<T> convolution_naive(const\
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
    \   }\r\n  }\r\n}\r\n#line 1 \"poly/fft.hpp\"\nnamespace CFFT {\r\nusing real\
    \ = double;\r\n\r\nstruct C {\r\n  real x, y;\r\n\r\n  C() : x(0), y(0) {}\r\n\
    \r\n  C(real x, real y) : x(x), y(y) {}\r\n  inline C operator+(const C& c) const\
    \ { return C(x + c.x, y + c.y); }\r\n  inline C operator-(const C& c) const {\
    \ return C(x - c.x, y - c.y); }\r\n  inline C operator*(const C& c) const {\r\n\
    \    return C(x * c.x - y * c.y, x * c.y + y * c.x);\r\n  }\r\n\r\n  inline C\
    \ conj() const { return C(x, -y); }\r\n};\r\n\r\nconst real PI = acosl(-1);\r\n\
    int base = 1;\r\nvector<C> rts = {{0, 0}, {1, 0}};\r\nvector<int> rev = {0, 1};\r\
    \n\r\nvoid ensure_base(int nbase) {\r\n  if (nbase <= base) return;\r\n  rev.resize(1\
    \ << nbase);\r\n  rts.resize(1 << nbase);\r\n  for (int i = 0; i < (1 << nbase);\
    \ i++) {\r\n    rev[i] = (rev[i >> 1] >> 1) + ((i & 1) << (nbase - 1));\r\n  }\r\
    \n  while (base < nbase) {\r\n    real angle = PI * 2.0 / (1 << (base + 1));\r\
    \n    for (int i = 1 << (base - 1); i < (1 << base); i++) {\r\n      rts[i <<\
    \ 1] = rts[i];\r\n      real angle_i = angle * (2 * i + 1 - (1 << base));\r\n\
    \      rts[(i << 1) + 1] = C(cos(angle_i), sin(angle_i));\r\n    }\r\n    ++base;\r\
    \n  }\r\n}\r\n\r\nvoid fft(vector<C>& a, int n) {\r\n  assert((n & (n - 1)) ==\
    \ 0);\r\n  int zeros = __builtin_ctz(n);\r\n  ensure_base(zeros);\r\n  int shift\
    \ = base - zeros;\r\n  for (int i = 0; i < n; i++) {\r\n    if (i < (rev[i] >>\
    \ shift)) { swap(a[i], a[rev[i] >> shift]); }\r\n  }\r\n  for (int k = 1; k <\
    \ n; k <<= 1) {\r\n    for (int i = 0; i < n; i += 2 * k) {\r\n      for (int\
    \ j = 0; j < k; j++) {\r\n        C z = a[i + j + k] * rts[j + k];\r\n       \
    \ a[i + j + k] = a[i + j] - z;\r\n        a[i + j] = a[i + j] + z;\r\n      }\r\
    \n    }\r\n  }\r\n}\r\n} // namespace CFFT\n#line 9 \"poly/convolution.hpp\"\n\
    \r\ntemplate <class mint>\r\nvector<mint> convolution_ntt(vector<mint> a, vector<mint>\
    \ b) {\r\n  if (a.empty() || b.empty()) return {};\r\n  int n = int(a.size()),\
    \ m = int(b.size());\r\n  int sz = 1;\r\n  while (sz < n + m - 1) sz *= 2;\r\n\
    \r\n  // sz = 2^k \u306E\u3068\u304D\u306E\u9AD8\u901F\u5316\u3002\u5206\u5272\
    \u7D71\u6CBB\u7684\u306A\u3084\u3064\u3067\u640D\u3057\u307E\u304F\u308B\u306E\
    \u3067\u3002\r\n  if ((n + m - 3) <= sz / 2) {\r\n    auto a_last = a.back(),\
    \ b_last = b.back();\r\n    a.pop_back(), b.pop_back();\r\n    auto c = convolution(a,\
    \ b);\r\n    c.resize(n + m - 1);\r\n    c[n + m - 2] = a_last * b_last;\r\n \
    \   FOR(i, len(a)) c[i + len(b)] += a[i] * b_last;\r\n    FOR(i, len(b)) c[i +\
    \ len(a)] += b[i] * a_last;\r\n    return c;\r\n  }\r\n\r\n  a.resize(sz), b.resize(sz);\r\
    \n  bool same = a == b;\r\n  ntt(a, 0);\r\n  if (same) {\r\n    b = a;\r\n  }\
    \ else {\r\n    ntt(b, 0);\r\n  }\r\n  FOR(i, sz) a[i] *= b[i];\r\n  ntt(a, 1);\r\
    \n  a.resize(n + m - 1);\r\n  return a;\r\n}\r\n\r\ntemplate <typename mint>\r\
    \nvector<mint> convolution_garner(const vector<mint>& a, const vector<mint>& b)\
    \ {\r\n  int n = len(a), m = len(b);\r\n  if (!n || !m) return {};\r\n  static\
    \ constexpr int p0 = 167772161;\r\n  static constexpr int p1 = 469762049;\r\n\
    \  static constexpr int p2 = 754974721;\r\n  using mint0 = modint<p0>;\r\n  using\
    \ mint1 = modint<p1>;\r\n  using mint2 = modint<p2>;\r\n  vc<mint0> a0(n), b0(m);\r\
    \n  vc<mint1> a1(n), b1(m);\r\n  vc<mint2> a2(n), b2(m);\r\n  FOR(i, n) a0[i]\
    \ = a[i].val, a1[i] = a[i].val, a2[i] = a[i].val;\r\n  FOR(i, m) b0[i] = b[i].val,\
    \ b1[i] = b[i].val, b2[i] = b[i].val;\r\n  auto c0 = convolution_ntt<mint0>(a0,\
    \ b0);\r\n  auto c1 = convolution_ntt<mint1>(a1, b1);\r\n  auto c2 = convolution_ntt<mint2>(a2,\
    \ b2);\r\n  vc<mint> c(len(c0));\r\n  FOR(i, n + m - 1) {\r\n    c[i] = CRT3<mint,\
    \ p0, p1, p2>(c0[i].val, c1[i].val, c2[i].val);\r\n  }\r\n  return c;\r\n}\r\n\
    \r\ntemplate <typename R>\r\nvc<double> convolution_fft(const vc<R>& a, const\
    \ vc<R>& b) {\r\n  using C = CFFT::C;\r\n  int need = (int)a.size() + (int)b.size()\
    \ - 1;\r\n  int nbase = 1;\r\n  while ((1 << nbase) < need) nbase++;\r\n  CFFT::ensure_base(nbase);\r\
    \n  int sz = 1 << nbase;\r\n  vector<C> fa(sz);\r\n  for (int i = 0; i < sz; i++)\
    \ {\r\n    double x = (i < (int)a.size() ? a[i] : 0);\r\n    double y = (i < (int)b.size()\
    \ ? b[i] : 0);\r\n    fa[i] = C(x, y);\r\n  }\r\n  CFFT::fft(fa, sz);\r\n  C r(0,\
    \ -0.25 / (sz >> 1)), s(0, 1), t(0.5, 0);\r\n  for (int i = 0; i <= (sz >> 1);\
    \ i++) {\r\n    int j = (sz - i) & (sz - 1);\r\n    C z = (fa[j] * fa[j] - (fa[i]\
    \ * fa[i]).conj()) * r;\r\n    fa[j] = (fa[i] * fa[i] - (fa[j] * fa[j]).conj())\
    \ * r;\r\n    fa[i] = z;\r\n  }\r\n  for (int i = 0; i < (sz >> 1); i++) {\r\n\
    \    C A0 = (fa[i] + fa[i + (sz >> 1)]) * t;\r\n    C A1 = (fa[i] - fa[i + (sz\
    \ >> 1)]) * t * CFFT::rts[(sz >> 1) + i];\r\n    fa[i] = A0 + A1 * s;\r\n  }\r\
    \n  CFFT::fft(fa, sz >> 1);\r\n  vector<double> ret(need);\r\n  for (int i = 0;\
    \ i < need; i++) {\r\n    ret[i] = (i & 1 ? fa[i >> 1].y : fa[i >> 1].x);\r\n\
    \  }\r\n  return ret;\r\n}\r\n\r\nvector<ll> convolution(const vector<ll>& a,\
    \ const vector<ll>& b) {\r\n  int n = len(a), m = len(b);\r\n  if (!n || !m) return\
    \ {};\r\n  if (min(n, m) <= 2500) return convolution_naive(a, b);\r\n  ll abs_sum_a\
    \ = 0, abs_sum_b = 0;\r\n  ll LIM = 1e15;\r\n  FOR(i, n) abs_sum_a = min(LIM,\
    \ abs_sum_a + abs(a[i]));\r\n  FOR(i, m) abs_sum_b = min(LIM, abs_sum_b + abs(b[i]));\r\
    \n  if (i128(abs_sum_a) * abs_sum_b < 1e15) {\r\n    vc<double> c = convolution_fft<ll>(a,\
    \ b);\r\n    vc<ll> res(len(c));\r\n    FOR(i, len(c)) res[i] = ll(floor(c[i]\
    \ + .5));\r\n    return res;\r\n  }\r\n\r\n  static constexpr unsigned long long\
    \ MOD1 = 754974721; // 2^24\r\n  static constexpr unsigned long long MOD2 = 167772161;\
    \ // 2^25\r\n  static constexpr unsigned long long MOD3 = 469762049; // 2^26\r\
    \n  static constexpr unsigned long long M2M3 = MOD2 * MOD3;\r\n  static constexpr\
    \ unsigned long long M1M3 = MOD1 * MOD3;\r\n  static constexpr unsigned long long\
    \ M1M2 = MOD1 * MOD2;\r\n  static constexpr unsigned long long M1M2M3 = MOD1 *\
    \ MOD2 * MOD3;\r\n\r\n  static const unsigned long long i1 = mod_inv(MOD2 * MOD3,\
    \ MOD1);\r\n  static const unsigned long long i2 = mod_inv(MOD1 * MOD3, MOD2);\r\
    \n  static const unsigned long long i3 = mod_inv(MOD1 * MOD2, MOD3);\r\n\r\n \
    \ using mint1 = modint<MOD1>;\r\n  using mint2 = modint<MOD2>;\r\n  using mint3\
    \ = modint<MOD3>;\r\n\r\n  vc<mint1> a1(n), b1(m);\r\n  vc<mint2> a2(n), b2(m);\r\
    \n  vc<mint3> a3(n), b3(m);\r\n  FOR(i, n) a1[i] = a[i], a2[i] = a[i], a3[i] =\
    \ a[i];\r\n  FOR(i, m) b1[i] = b[i], b2[i] = b[i], b3[i] = b[i];\r\n\r\n  auto\
    \ c1 = convolution_ntt<mint1>(a1, b1);\r\n  auto c2 = convolution_ntt<mint2>(a2,\
    \ b2);\r\n  auto c3 = convolution_ntt<mint3>(a3, b3);\r\n\r\n  vc<ll> c(n + m\
    \ - 1);\r\n  FOR(i, n + m - 1) {\r\n    u64 x = 0;\r\n    x += (c1[i].val * i1)\
    \ % MOD1 * M2M3;\r\n    x += (c2[i].val * i2) % MOD2 * M1M3;\r\n    x += (c3[i].val\
    \ * i3) % MOD3 * M1M2;\r\n    ll diff = c1[i].val - ((long long)(x) % (long long)(MOD1));\r\
    \n    if (diff < 0) diff += MOD1;\r\n    static constexpr unsigned long long offset[5]\r\
    \n        = {0, 0, M1M2M3, 2 * M1M2M3, 3 * M1M2M3};\r\n    x -= offset[diff %\
    \ 5];\r\n    c[i] = x;\r\n  }\r\n  return c;\r\n}\r\n\r\ntemplate <typename mint>\r\
    \nvc<mint> convolution(const vc<mint>& a, const vc<mint>& b) {\r\n  int n = len(a),\
    \ m = len(b);\r\n  if (!n || !m) return {};\r\n  if (mint::can_ntt()) {\r\n  \
    \  if (min(n, m) <= 50) return convolution_karatsuba<mint>(a, b);\r\n    return\
    \ convolution_ntt(a, b);\r\n  }\r\n  if (min(n, m) <= 200) return convolution_karatsuba<mint>(a,\
    \ b);\r\n  return convolution_garner(a, b);\r\n}\r\n#line 4 \"poly/fps_inv.hpp\"\
    \n\r\ntemplate <typename mint>\r\nvc<mint> fps_inv_sparse(const vc<mint>& f) {\r\
    \n  int N = len(f);\r\n  vc<pair<int, mint>> dat;\r\n  FOR(i, 1, N) if (f[i] !=\
    \ mint(0)) dat.eb(i, f[i]);\r\n  vc<mint> g(N);\r\n  mint g0 = mint(1) / f[0];\r\
    \n  g[0] = g0;\r\n  FOR(n, 1, N) {\r\n    mint rhs = 0;\r\n    for (auto&& [k,\
    \ fk]: dat) {\r\n      if (k > n) break;\r\n      rhs -= fk * g[n - k];\r\n  \
    \  }\r\n    g[n] = rhs * g0;\r\n  }\r\n  return g;\r\n}\r\n\r\ntemplate <typename\
    \ mint>\r\nvc<mint> fps_inv_dense_ntt(const vc<mint>& F) {\r\n  vc<mint> G = {mint(1)\
    \ / F[0]};\r\n  ll N = len(F), n = 1;\r\n  G.reserve(N);\r\n  while (n < N) {\r\
    \n    vc<mint> f(2 * n), g(2 * n);\r\n    FOR(i, min(N, 2 * n)) f[i] = F[i];\r\
    \n    FOR(i, n) g[i] = G[i];\r\n    ntt(f, false), ntt(g, false);\r\n    FOR(i,\
    \ 2 * n) f[i] *= g[i];\r\n    ntt(f, true);\r\n    FOR(i, n) f[i] = 0;\r\n   \
    \ ntt(f, false);\r\n    FOR(i, 2 * n) f[i] *= g[i];\r\n    ntt(f, true);\r\n \
    \   FOR(i, n, min(N, 2 * n)) G.eb(-f[i]);\r\n    n *= 2;\r\n  }\r\n  return G;\r\
    \n}\r\n\r\ntemplate <typename mint>\r\nvc<mint> fps_inv_dense(const vc<mint>&\
    \ F) {\r\n  if (mint::can_ntt()) return fps_inv_dense_ntt(F);\r\n  const int N\
    \ = len(F);\r\n  vc<mint> R = {mint(1) / F[0]};\r\n  vc<mint> p;\r\n  int m =\
    \ 1;\r\n  while (m < N) {\r\n    p = convolution(R, R);\r\n    p.resize(m + m);\r\
    \n    vc<mint> f = {F.begin(), F.begin() + min(m + m, N)};\r\n    p = convolution(p,\
    \ f);\r\n    R.resize(m + m);\r\n    FOR(i, m + m) R[i] = R[i] + R[i] - p[i];\r\
    \n    m += m;\r\n  }\r\n  R.resize(N);\r\n  return R;\r\n}\r\n\r\ntemplate <typename\
    \ mint>\r\nvc<mint> fps_inv(const vc<mint>& f) {\r\n  assert(f[0] != mint(0));\r\
    \n  int n = count_terms(f);\r\n  int t = (mint::can_ntt() ? 160 : 820);\r\n  return\
    \ (n <= t ? fps_inv_sparse<mint>(f) : fps_inv_dense<mint>(f));\r\n}\r\n#line 5\
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
    \ (n <= t ? fps_log_sparse<mint>(f) : fps_log_dense<mint>(f));\r\n}\r\n#line 2\
    \ \"poly/integrate.hpp\"\n\n// \u4E0D\u5B9A\u7A4D\u5206\uFF1Aintegrate(f)\n//\
    \ \u5B9A\u7A4D\u5206\uFF1Aintegrate(f, L, R)\ntemplate <typename mint>\nvc<mint>\
    \ integrate(const vc<mint>& f) {\n  vc<mint> g(len(f) + 1);\n  FOR3(i, 1, len(g))\
    \ g[i] = f[i - 1] * inv<mint>(i);\n  return g;\n}\n\n// \u4E0D\u5B9A\u7A4D\u5206\
    \uFF1Aintegrate(f)\n// \u5B9A\u7A4D\u5206\uFF1Aintegrate(f, L, R)\ntemplate <typename\
    \ mint>\nmint integrate(const vc<mint>& f, mint L, mint R) {\n  mint I = 0;\n\
    \  mint pow_L = 1, pow_R = 1;\n  FOR(i, len(f)) {\n    pow_L *= L, pow_R *= R;\n\
    \    I += inv<mint>(i + 1) * f[i] * (pow_R - pow_L);\n  }\n  return I;\n}\n#line\
    \ 2 \"poly/differentiate.hpp\"\n\ntemplate <typename mint>\nvc<mint> differentiate(const\
    \ vc<mint>& f) {\n  if (len(f) <= 1) return {};\n  vc<mint> g(len(f) - 1);\n \
    \ FOR(i, len(g)) g[i] = f[i + 1] * mint(i + 1);\n  return g;\n}\n#line 6 \"poly/fps_exp.hpp\"\
    \n\r\ntemplate <typename mint>\r\nvc<mint> fps_exp_sparse(vc<mint>& f) {\r\n \
    \ if (len(f) == 0) return {mint(1)};\r\n  assert(f[0] == 0);\r\n  int N = len(f);\r\
    \n  // df \u3092\u6301\u305F\u305B\u308B\r\n  vc<pair<int, mint>> dat;\r\n  FOR(i,\
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
    \ : fps_exp_dense<mint>(f));\r\n}\r\n#line 5 \"poly/fps_pow.hpp\"\n\r\n// fps\
    \ \u306E k \u4E57\u3092\u6C42\u3081\u308B\u3002k >= 0 \u306E\u524D\u63D0\u3067\
    \u3042\u308B\u3002\r\n// \u5B9A\u6570\u9805\u304C 1 \u3067\u3001k \u304C mint\
    \ \u306E\u5834\u5408\u306B\u306F\u3001fps_pow_1 \u3092\u4F7F\u3046\u3053\u3068\
    \u3002\r\n// \u30FBdense \u306A\u5834\u5408\uFF1A log, exp \u3092\u4F7F\u3046\
    \ O(NlogN)\r\n// \u30FBsparse \u306A\u5834\u5408\uFF1A O(NK)\r\ntemplate <typename\
    \ mint>\r\nvc<mint> fps_pow(const vc<mint>& f, ll k) {\r\n  assert(0 <= k);\r\n\
    \  int n = len(f);\r\n  if (k == 0) {\r\n    vc<mint> g(n);\r\n    g[0] = mint(1);\r\
    \n    return g;\r\n  }\r\n  int d = n;\r\n  FOR_R(i, n) if (f[i] != 0) d = i;\r\
    \n  // d * k >= n\r\n  if (d >= ceil<ll>(n, k)) {\r\n    vc<mint> g(n);\r\n  \
    \  return g;\r\n  }\r\n  ll off = d * k;\r\n  mint c = f[d];\r\n  mint c_inv =\
    \ mint(1) / mint(c);\r\n  vc<mint> g(n - off);\r\n  FOR(i, n - off) g[i] = f[d\
    \ + i] * c_inv;\r\n  g = fps_pow_1(g, mint(k));\r\n  vc<mint> h(n);\r\n  c = c.pow(k);\r\
    \n  FOR(i, len(g)) h[off + i] = g[i] * c;\r\n  return h;\r\n}\r\n\r\ntemplate\
    \ <typename mint>\r\nvc<mint> fps_pow_1_sparse(const vc<mint>& f, mint K) {\r\n\
    \  int N = len(f);\r\n  assert(N == 0 || f[0] == mint(1));\r\n  vc<pair<int, mint>>\
    \ dat;\r\n  FOR(i, 1, N) if (f[i] != mint(0)) dat.eb(i, f[i]);\r\n  vc<mint> g(N);\r\
    \n  g[0] = 1;\r\n  FOR(n, N - 1) {\r\n    mint& x = g[n + 1];\r\n    for (auto&&\
    \ [d, cf]: dat) {\r\n      if (d > n + 1) break;\r\n      mint t = cf * g[n -\
    \ d + 1];\r\n      x += t * (K * mint(d) - mint(n - d + 1));\r\n    }\r\n    x\
    \ *= inv<mint>(n + 1);\r\n  }\r\n  return g;\r\n}\r\n\r\ntemplate <typename mint>\r\
    \nvc<mint> fps_pow_1_dense(const vc<mint>& f, mint K) {\r\n  assert(f[0] == mint(1));\r\
    \n  auto log_f = fps_log(f);\r\n  FOR(i, len(f)) log_f[i] *= K;\r\n  return fps_exp_dense(log_f);\r\
    \n}\r\n\r\ntemplate <typename mint>\r\nvc<mint> fps_pow_1(const vc<mint>& f, mint\
    \ K) {\r\n  int n = count_terms(f);\r\n  int t = (mint::can_ntt() ? 100 : 1300);\r\
    \n  return (n <= t ? fps_pow_1_sparse(f, K) : fps_pow_1_dense(f, K));\r\n}\r\n\
    \r\n// f^e, sparse, O(NMK)\r\ntemplate <typename mint>\r\nvvc<mint> fps_pow_1_sparse_2d(vvc<mint>\
    \ f, mint n) {\r\n  assert(f[0][0] == mint(1));\r\n  int N = len(f), M = len(f[0]);\r\
    \n  vv(mint, dp, N, M);\r\n  dp[0] = fps_pow_1_sparse<mint>(f[0], n);\r\n\r\n\
    \  vc<tuple<int, int, mint>> dat;\r\n  FOR(i, N) FOR(j, M) {\r\n    if ((i > 0\
    \ || j > 0) && f[i][j] != mint(0)) dat.eb(i, j, f[i][j]);\r\n  }\r\n  FOR(i, 1,\
    \ N) {\r\n    FOR(j, M) {\r\n      // F = f^n, f dF = n df F\r\n      // [x^{i-1}y^j]\r\
    \n      mint lhs = 0, rhs = 0;\r\n      for (auto&& [a, b, c]: dat) {\r\n    \
    \    if (a < i && b <= j) lhs += dp[i - a][j - b] * mint(i - a);\r\n        if\
    \ (a <= i && b <= j) rhs += dp[i - a][j - b] * c * mint(a);\r\n      }\r\n   \
    \   dp[i][j] = (n * rhs - lhs) * inv<mint>(i);\r\n    }\r\n  }\r\n  return dp;\r\
    \n}\r\n#line 2 \"random/base.hpp\"\n\nu64 RNG_64() {\n  static uint64_t x_\n \
    \     = uint64_t(chrono::duration_cast<chrono::nanoseconds>(\n               \
    \      chrono::high_resolution_clock::now().time_since_epoch())\n            \
    \         .count())\n        * 10150724397891781847ULL;\n  x_ ^= x_ << 7;\n  return\
    \ x_ ^= x_ >> 9;\n}\n\nu64 RNG(u64 lim) { return RNG_64() % lim; }\n\nll RNG(ll\
    \ l, ll r) { return l + RNG_64() % (r - l); }\n#line 2 \"mod/mod_pow.hpp\"\n\r\
    \n#line 2 \"mod/mongomery_modint.hpp\"\n\n// odd mod.\n// x \u306E\u4EE3\u308F\
    \u308A\u306B rx \u3092\u6301\u3064\ntemplate <int id, typename U1, typename U2>\n\
    struct Mongomery_modint {\n  using mint = Mongomery_modint;\n  inline static U1\
    \ m, r, n2;\n  static constexpr int W = numeric_limits<U1>::digits;\n\n  static\
    \ void set_mod(U1 mod) {\n    assert(mod & 1 && mod <= U1(1) << (W - 2));\n  \
    \  m = mod, n2 = -U2(m) % m, r = m;\n    FOR(5) r *= 2 - m * r;\n    r = -r;\n\
    \    assert(r * m == U1(-1));\n  }\n  static U1 reduce(U2 b) { return (b + U2(U1(b)\
    \ * r) * m) >> W; }\n\n  U1 x;\n  Mongomery_modint() : x(0) {}\n  Mongomery_modint(U1\
    \ x) : x(reduce(U2(x) * n2)){};\n  U1 val() const {\n    U1 y = reduce(x);\n \
    \   return y >= m ? y - m : y;\n  }\n  mint &operator+=(mint y) {\n    x = ((x\
    \ += y.x) >= m ? x - m : x);\n    return *this;\n  }\n  mint &operator-=(mint\
    \ y) {\n    x -= (x >= y.x ? y.x : y.x - m);\n    return *this;\n  }\n  mint &operator*=(mint\
    \ y) {\n    x = reduce(U2(x) * y.x);\n    return *this;\n  }\n  mint operator+(mint\
    \ y) const { return mint(*this) += y; }\n  mint operator-(mint y) const { return\
    \ mint(*this) -= y; }\n  mint operator*(mint y) const { return mint(*this) *=\
    \ y; }\n  bool operator==(mint y) const {\n    return (x >= m ? x - m : x) ==\
    \ (y.x >= m ? y.x - m : y.x);\n  }\n  bool operator!=(mint y) const { return not\
    \ operator==(y); }\n  mint pow(ll n) const {\n    assert(n >= 0);\n    mint y\
    \ = 1, z = *this;\n    for (; n; n >>= 1, z *= z)\n      if (n & 1) y *= z;\n\
    \    return y;\n  }\n};\n\ntemplate <int id>\nusing Mongomery_modint_32 = Mongomery_modint<id,\
    \ u32, u64>;\ntemplate <int id>\nusing Mongomery_modint_64 = Mongomery_modint<id,\
    \ u64, u128>;\n#line 2 \"mod/barrett.hpp\"\n\n// https://github.com/atcoder/ac-library/blob/master/atcoder/internal_math.hpp\n\
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
    \  }\n\n  u64 mul(u64 a, u64 b) { return modulo(u128(a) * b); }\n};\n#line 5 \"\
    mod/mod_pow.hpp\"\n\r\nu32 mod_pow(int a, ll n, int mod) {\r\n  assert(n >= 0);\r\
    \n  a = ((a %= mod) < 0 ? a + mod : a);\r\n  if ((mod & 1) && (mod < (1 << 30)))\
    \ {\r\n    using mint = Mongomery_modint_32<202311021>;\r\n    mint::set_mod(mod);\r\
    \n    return mint(a).pow(n).val();\r\n  }\r\n  Barrett bt(mod);\r\n  int r = 1;\r\
    \n  while (n) {\r\n    if (n & 1) r = bt.mul(r, a);\r\n    a = bt.mul(a, a), n\
    \ >>= 1;\r\n  }\r\n  return r;\r\n}\r\n\r\nu64 mod_pow_64(ll a, ll n, u64 mod)\
    \ {\r\n  assert(n >= 0);\r\n  a = ((a %= mod) < 0 ? a + mod : a);\r\n  if ((mod\
    \ & 1) && (mod < (u64(1) << 62))) {\r\n    using mint = Mongomery_modint_64<202311021>;\r\
    \n    mint::set_mod(mod);\r\n    return mint(a).pow(n).val();\r\n  }\r\n  Barrett_64\
    \ bt(mod);\r\n  ll r = 1;\r\n  while (n) {\r\n    if (n & 1) r = bt.mul(r, a);\r\
    \n    a = bt.mul(a, a), n >>= 1;\r\n  }\r\n  return r;\r\n}\n#line 3 \"mod/mod_sqrt.hpp\"\
    \n\r\n// p \u306F\u7D20\u6570. \u89E3\u306A\u3057\u306F -1.\r\nint mod_sqrt(int\
    \ a, int p) {\r\n  if (p == 2) return a;\r\n  if (a == 0) return 0;\r\n  int k\
    \ = (p - 1) / 2;\r\n  if (mod_pow(a, k, p) != 1) return -1;\r\n  auto find = [&]()\
    \ -> pi {\r\n    while (1) {\r\n      ll b = RNG(2, p);\r\n      ll D = (b * b\
    \ - a) % p;\r\n      if (D == 0) return {b, D};\r\n      if (mod_pow(D, k, p)\
    \ != 1) return {b, D};\r\n    }\r\n  };\r\n  auto [b, D] = find();\r\n  if (D\
    \ == 0) return b;\r\n  ++k;\r\n  // (b + sqrt(D))^k\r\n  ll f0 = b, f1 = 1, g0\
    \ = 1, g1 = 0;\r\n  while (k) {\r\n    if (k & 1) {\r\n      tie(g0, g1) = mp(f0\
    \ * g0 + D * f1 % p * g1, f1 * g0 + f0 * g1);\r\n      g0 %= p, g1 %= p;\r\n \
    \   }\r\n    tie(f0, f1) = mp(f0 * f0 + D * f1 % p * f1, 2 * f0 * f1);\r\n   \
    \ f0 %= p, f1 %= p;\r\n    k >>= 1;\r\n  }\r\n  if (g0 < 0) g0 += p;\r\n  return\
    \ g0;\r\n}\r\n\r\n// p \u306F\u7D20\u6570. \u89E3\u306A\u3057\u306F -1.\r\nll\
    \ mod_sqrt_64(ll a, ll p) {\r\n  if (p == 2) return a;\r\n  if (a == 0) return\
    \ 0;\r\n  ll k = (p - 1) / 2;\r\n  if (mod_pow_64(a, k, p) != 1) return -1;\r\n\
    \  auto find = [&]() -> pair<i128, i128> {\r\n    while (1) {\r\n      i128 b\
    \ = RNG(2, p);\r\n      i128 D = b * b - a;\r\n      if (D == 0) return {b, D};\r\
    \n      if (mod_pow_64(D, k, p) != 1) return {b, D};\r\n    }\r\n  };\r\n  auto\
    \ [b, D] = find();\r\n  if (D == 0) return b;\r\n  ++k;\r\n  // (b + sqrt(D))^k\r\
    \n  i128 f0 = b, f1 = 1, g0 = 1, g1 = 0;\r\n  while (k) {\r\n    if (k & 1) {\r\
    \n      tie(g0, g1) = mp(f0 * g0 + D * f1 % p * g1, f1 * g0 + f0 * g1);\r\n  \
    \    g0 %= p, g1 %= p;\r\n    }\r\n    tie(f0, f1) = mp(f0 * f0 + D * f1 % p *\
    \ f1, 2 * f0 * f1);\r\n    f0 %= p, f1 %= p;\r\n    k >>= 1;\r\n  }\r\n  return\
    \ g0;\r\n}\r\n#line 5 \"poly/fps_sqrt.hpp\"\n\r\ntemplate <typename mint>\r\n\
    vc<mint> fps_sqrt_dense(vc<mint>& f) {\r\n  assert(f[0] == mint(1));\r\n  int\
    \ n = len(f);\r\n  vc<mint> R = {1};\r\n  while (len(R) < n) {\r\n    int m =\
    \ min(2 * int(len(R)), n);\r\n    R.resize(m);\r\n    vc<mint> tmp = {f.begin(),\
    \ f.begin() + m};\r\n    tmp = convolution(tmp, fps_inv(R));\r\n    tmp.resize(m);\r\
    \n    FOR(i, m) R[i] += tmp[i];\r\n    mint c = mint(1) / mint(2);\r\n    FOR(i,\
    \ len(R)) R[i] *= c;\r\n  }\r\n  R.resize(n);\r\n  return R;\r\n}\r\n\r\ntemplate\
    \ <typename mint>\r\nvc<mint> fps_sqrt_sparse(vc<mint>& f) {\r\n  return fps_pow_1_sparse(f,\
    \ inv<mint>(2));\r\n}\r\n\r\ntemplate <typename mint>\r\nvc<mint> fps_sqrt(vc<mint>&\
    \ f) {\r\n  if (count_terms(f) <= 200) return fps_sqrt_sparse(f);\r\n  return\
    \ fps_sqrt_dense(f);\r\n}\r\n\r\ntemplate <typename mint>\r\nvc<mint> fps_sqrt_any(vc<mint>&\
    \ f) {\r\n  int n = len(f);\r\n  int d = n;\r\n  FOR_R(i, n) if (f[i] != 0) d\
    \ = i;\r\n  if (d == n) return f;\r\n  if (d & 1) return {};\r\n  mint y = f[d];\r\
    \n  mint x = mod_sqrt(y.val, mint::get_mod());\r\n  if (x * x != y) return {};\r\
    \n  mint c = mint(1) / y;\r\n  vc<mint> g(n - d);\r\n  FOR(i, n - d) g[i] = f[d\
    \ + i] * c;\r\n  g = fps_sqrt(g);\r\n  FOR(i, len(g)) g[i] *= x;\r\n  g.resize(n);\r\
    \n  FOR_R(i, n) {\r\n    if (i >= d / 2)\r\n      g[i] = g[i - d / 2];\r\n   \
    \ else\r\n      g[i] = 0;\r\n  }\r\n  return g;\r\n}\r\n#line 2 \"alg/monoid/mul.hpp\"\
    \n\r\ntemplate <class T>\r\nstruct Monoid_Mul {\r\n  using value_type = T;\r\n\
    \  using X = T;\r\n  static constexpr X op(const X &x, const X &y) noexcept {\
    \ return x * y; }\r\n  static constexpr X inverse(const X &x) noexcept { return\
    \ X(1) / x; }\r\n  static constexpr X unit() { return X(1); }\r\n  static constexpr\
    \ bool commute = true;\r\n};\r\n#line 2 \"ds/power_query.hpp\"\n\n// \u5B9A\u6570\
    \u3092\u3079\u304D\u4E57\u3059\u308B\u30AF\u30A8\u30EA\u3002 B \u4E57\u5206\u305A\
    \u3064\u524D\u8A08\u7B97\u3002\ntemplate <typename Mono, int B = 1024>\nstruct\
    \ Power_Query {\n  using X = typename Mono::value_type;\n  vvc<X> dat;\n\n  Power_Query(X\
    \ a) { dat.eb(make_pow(a)); }\n\n  X operator()(ll n) {\n    X res = Mono::unit();\n\
    \    int k = 0;\n    while (n) {\n      int r = n % B;\n      n /= B;\n      if\
    \ (len(dat) == k) { dat.eb(make_pow(dat[k - 1].back())); }\n      res = Mono::op(res,\
    \ dat[k][r]);\n      ++k;\n    }\n    return res;\n  }\n\n  X operator[](ll n)\
    \ { return (*this)(n); }\n\nprivate:\n  vc<X> make_pow(X a) {\n    vc<X> res =\
    \ {Mono::unit()};\n    FOR(B) { res.eb(Mono::op(res.back(), a)); }\n    return\
    \ res;\n  }\n};\n#line 4 \"graph/count/count_bipartite.hpp\"\n\n// connected =\
    \ false: https://oeis.org/A047864\n// connected = true: https://oeis.org/A001832\n\
    template <typename mint>\nvc<mint> count_bipartite(int N, bool connected) {\n\
    \  Power_Query<Monoid_Mul<mint>> POW2(mint(2));\n  Power_Query<Monoid_Mul<mint>>\
    \ iPOW2(inv<mint>(2));\n\n  // colored bipartite\n  vc<mint> F(N + 1);\n  FOR(i,\
    \ N + 1) F[i] = fact_inv<mint>(i) * iPOW2[i * (i - 1) / 2];\n  F = convolution(F,\
    \ F);\n  F.resize(N + 1);\n  FOR(i, N + 1) F[i] *= POW2[i * (i - 1) / 2];\n\n\
    \  // colored bipartite connected\n  if (connected) {\n    F = fps_log(F);\n \
    \   FOR(i, N + 1) F[i] *= inv<mint>(2);\n    FOR(i, N + 1) F[i] *= fact<mint>(i);\n\
    \    return F;\n  }\n  F = fps_sqrt(F);\n  FOR(i, N + 1) F[i] *= fact<mint>(i);\n\
    \  return F;\n}\n"
  code: "#include \"poly/fps_log.hpp\"\n#include \"poly/fps_sqrt.hpp\"\n#include \"\
    ds/power_query.hpp\"\n\n// connected = false: https://oeis.org/A047864\n// connected\
    \ = true: https://oeis.org/A001832\ntemplate <typename mint>\nvc<mint> count_bipartite(int\
    \ N, bool connected) {\n  Power_Query<Monoid_Mul<mint>> POW2(mint(2));\n  Power_Query<Monoid_Mul<mint>>\
    \ iPOW2(inv<mint>(2));\n\n  // colored bipartite\n  vc<mint> F(N + 1);\n  FOR(i,\
    \ N + 1) F[i] = fact_inv<mint>(i) * iPOW2[i * (i - 1) / 2];\n  F = convolution(F,\
    \ F);\n  F.resize(N + 1);\n  FOR(i, N + 1) F[i] *= POW2[i * (i - 1) / 2];\n\n\
    \  // colored bipartite connected\n  if (connected) {\n    F = fps_log(F);\n \
    \   FOR(i, N + 1) F[i] *= inv<mint>(2);\n    FOR(i, N + 1) F[i] *= fact<mint>(i);\n\
    \    return F;\n  }\n  F = fps_sqrt(F);\n  FOR(i, N + 1) F[i] *= fact<mint>(i);\n\
    \  return F;\n}"
  dependsOn:
  - poly/fps_log.hpp
  - poly/fps_inv.hpp
  - poly/count_terms.hpp
  - poly/convolution.hpp
  - mod/modint.hpp
  - mod/modint_common.hpp
  - mod/mod_inv.hpp
  - mod/crt3.hpp
  - poly/convolution_naive.hpp
  - poly/convolution_karatsuba.hpp
  - poly/ntt.hpp
  - poly/fft.hpp
  - poly/fps_sqrt.hpp
  - poly/fps_pow.hpp
  - poly/fps_exp.hpp
  - poly/integrate.hpp
  - poly/differentiate.hpp
  - mod/mod_sqrt.hpp
  - random/base.hpp
  - mod/mod_pow.hpp
  - mod/mongomery_modint.hpp
  - mod/barrett.hpp
  - ds/power_query.hpp
  - alg/monoid/mul.hpp
  isVerificationFile: false
  path: graph/count/count_bipartite.hpp
  requiredBy: []
  timestamp: '2023-12-29 16:32:29+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/mytest/count_bipartite.test.cpp
documentation_of: graph/count/count_bipartite.hpp
layout: document
redirect_from:
- /library/graph/count/count_bipartite.hpp
- /library/graph/count/count_bipartite.hpp.html
title: graph/count/count_bipartite.hpp
---