---
data:
  _extendedDependsOn:
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
    path: poly/fft.hpp
    title: poly/fft.hpp
  - icon: ':question:'
    path: poly/ntt.hpp
    title: poly/ntt.hpp
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/aoj/NTL_2_A.test.cpp
    title: test/aoj/NTL_2_A.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/aoj/NTL_2_B.test.cpp
    title: test/aoj/NTL_2_B.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/aoj/NTL_2_C.test.cpp
    title: test/aoj/NTL_2_C.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/library_checker/addition_of_bigintegers.test.cpp
    title: test/library_checker/addition_of_bigintegers.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/library_checker/multiplication_of_bigintegers.test.cpp
    title: test/library_checker/multiplication_of_bigintegers.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/library_checker/sample/aplusb128.test.cpp
    title: test/library_checker/sample/aplusb128.test.cpp
  - icon: ':x:'
    path: test/yukicoder/2508.test.cpp
    title: test/yukicoder/2508.test.cpp
  - icon: ':x:'
    path: test/yukicoder/303.test.cpp
    title: test/yukicoder/303.test.cpp
  _isVerificationFailed: true
  _pathExtension: hpp
  _verificationStatusIcon: ':question:'
  attributes:
    links:
    - https://codeforces.com/contest/504/problem/D
    - https://codeforces.com/contest/759/problem/E
    - https://codeforces.com/contest/986/problem/D
    - https://codeforces.com/problemset/problem/582/D
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
    \ modint(u64 x) : val(x % umod) {}\n  constexpr modint(int x) : val((x %= mod)\
    \ < 0 ? x + mod : x){};\n  constexpr modint(ll x) : val((x %= mod) < 0 ? x + mod\
    \ : x){};\n  bool operator<(const modint &other) const { return val < other.val;\
    \ }\n  modint &operator+=(const modint &p) {\n    if ((val += p.val) >= umod)\
    \ val -= umod;\n    return *this;\n  }\n  modint &operator-=(const modint &p)\
    \ {\n    if ((val += umod - p.val) >= umod) val -= umod;\n    return *this;\n\
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
    \      mul *= mul;\n      n >>= 1;\n    }\n    return ret;\n  }\n#ifdef FASTIO\n\
    \  void write() { fastio::printer.write(val); }\n  void read() {\n    fastio::scanner.read(val);\n\
    \    val %= mod;\n  }\n#endif\n  static constexpr int get_mod() { return mod;\
    \ }\n  // (n, r), r \u306F 1 \u306E 2^n \u4E57\u6839\n  static constexpr pair<int,\
    \ int> ntt_info() {\n    if (mod == 167772161) return {25, 17};\n    if (mod ==\
    \ 469762049) return {26, 30};\n    if (mod == 754974721) return {24, 362};\n \
    \   if (mod == 880803841) return {23, 211};\n    if (mod == 943718401) return\
    \ {22, 663003469};\n    if (mod == 998244353) return {23, 31};\n    if (mod ==\
    \ 1045430273) return {20, 363};\n    if (mod == 1051721729) return {20, 330};\n\
    \    if (mod == 1053818881) return {20, 2789};\n    return {-1, -1};\n  }\n  static\
    \ constexpr bool can_ntt() { return ntt_info().fi != -1; }\n};\n\nusing modint107\
    \ = modint<1000000007>;\nusing modint998 = modint<998244353>;\n#line 2 \"mod/mod_inv.hpp\"\
    \n\r\n// long \u3067\u3082\u5927\u4E08\u592B\r\n// (val * x - 1) \u304C mod \u306E\
    \u500D\u6570\u306B\u306A\u308B\u3088\u3046\u306B\u3059\u308B\r\n// \u7279\u306B\
    \ mod=0 \u306A\u3089 x=0 \u304C\u6E80\u305F\u3059\r\nll mod_inv(ll val, ll mod)\
    \ {\r\n  if (mod == 0) return 0;\r\n  mod = abs(mod);\r\n  val %= mod;\r\n  if\
    \ (val < 0) val += mod;\r\n  ll a = val, b = mod, u = 1, v = 0, t;\r\n  while\
    \ (b > 0) {\r\n    t = a / b;\r\n    swap(a -= t * b, b), swap(u -= t * v, v);\r\
    \n  }\r\n  if (u < 0) u += mod;\r\n  return u;\r\n}\r\n#line 1 \"mod/crt3.hpp\"\
    \n\nconstexpr u32 mod_pow_constexpr(u64 a, u64 n, u32 mod) {\n  a %= mod;\n  u64\
    \ res = 1;\n  FOR(32) {\n    if (n & 1) res = res * a % mod;\n    a = a * a %\
    \ mod, n /= 2;\n  }\n  return res;\n}\n\ntemplate <typename T, u32 p0, u32 p1,\
    \ u32 p2>\nT CRT3(u64 a0, u64 a1, u64 a2) {\n  static_assert(p0 < p1 && p1 < p2);\n\
    \  static constexpr u64 x0_1 = mod_pow_constexpr(p0, p1 - 2, p1);\n  static constexpr\
    \ u64 x01_2 = mod_pow_constexpr(u64(p0) * p1 % p2, p2 - 2, p2);\n  u64 c = (a1\
    \ - a0 + p1) * x0_1 % p1;\n  u64 a = a0 + c * p0;\n  c = (a2 - a % p2 + p2) *\
    \ x01_2 % p2;\n  return T(a) + T(c) * T(p0) * T(p1);\n}\n#line 2 \"poly/convolution_naive.hpp\"\
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
    \n\r\n  static bool prepared = 0;\r\n  if (!prepared) {\r\n    prepared = 1;\r\
    \n    root[rank2] = mint::ntt_info().se;\r\n    iroot[rank2] = mint(1) / root[rank2];\r\
    \n    FOR_R(i, rank2) {\r\n      root[i] = root[i + 1] * root[i + 1];\r\n    \
    \  iroot[i] = iroot[i + 1] * iroot[i + 1];\r\n    }\r\n    mint prod = 1, iprod\
    \ = 1;\r\n    for (int i = 0; i <= rank2 - 2; i++) {\r\n      rate2[i] = root[i\
    \ + 2] * prod;\r\n      irate2[i] = iroot[i + 2] * iprod;\r\n      prod *= iroot[i\
    \ + 2];\r\n      iprod *= root[i + 2];\r\n    }\r\n    prod = 1, iprod = 1;\r\n\
    \    for (int i = 0; i <= rank2 - 3; i++) {\r\n      rate3[i] = root[i + 3] *\
    \ prod;\r\n      irate3[i] = iroot[i + 3] * iprod;\r\n      prod *= iroot[i +\
    \ 3];\r\n      iprod *= root[i + 3];\r\n    }\r\n  }\r\n\r\n  int n = int(a.size());\r\
    \n  int h = topbit(n);\r\n  assert(n == 1 << h);\r\n  if (!inverse) {\r\n    int\
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
    \ {\r\n    int x = (i < (int)a.size() ? a[i] : 0);\r\n    int y = (i < (int)b.size()\
    \ ? b[i] : 0);\r\n    fa[i] = C(x, y);\r\n  }\r\n  CFFT::fft(fa, sz);\r\n  C r(0,\
    \ -0.25 / (sz >> 1)), s(0, 1), t(0.5, 0);\r\n  for (int i = 0; i <= (sz >> 1);\
    \ i++) {\r\n    int j = (sz - i) & (sz - 1);\r\n    C z = (fa[j] * fa[j] - (fa[i]\
    \ * fa[i]).conj()) * r;\r\n    fa[j] = (fa[i] * fa[i] - (fa[j] * fa[j]).conj())\
    \ * r;\r\n    fa[i] = z;\r\n  }\r\n  for (int i = 0; i < (sz >> 1); i++) {\r\n\
    \    C A0 = (fa[i] + fa[i + (sz >> 1)]) * t;\r\n    C A1 = (fa[i] - fa[i + (sz\
    \ >> 1)]) * t * CFFT::rts[(sz >> 1) + i];\r\n    fa[i] = A0 + A1 * s;\r\n  }\r\
    \n  CFFT::fft(fa, sz >> 1);\r\n  vector<double> ret(need);\r\n  for (int i = 0;\
    \ i < need; i++) {\r\n    ret[i] = (i & 1 ? fa[i >> 1].y : fa[i >> 1].x);\r\n\
    \  }\r\n  return ret;\r\n}\r\n\r\nvi convolution(vi a, vi b) {\r\n  int n = len(a),\
    \ m = len(b);\r\n  if (!n || !m) return {};\r\n  if (min(n, m) <= 2500) return\
    \ convolution_naive(a, b);\r\n\r\n  ll min_a = MIN(a), min_b = MIN(b);\r\n  for\
    \ (auto& x: a) x -= min_a;\r\n  for (auto& x: b) x -= min_b;\r\n\r\n  static constexpr\
    \ int p0 = 1045430273;\r\n  static constexpr int p1 = 1051721729;\r\n  static\
    \ constexpr int p2 = 1053818881;\r\n  using mint0 = modint<p0>;\r\n  using mint1\
    \ = modint<p1>;\r\n  using mint2 = modint<p2>;\r\n  vc<mint0> a0(n), b0(m);\r\n\
    \  vc<mint1> a1(n), b1(m);\r\n  vc<mint2> a2(n), b2(m);\r\n  FOR(i, n) a0[i] =\
    \ u64(a[i]), a1[i] = u64(a[i]), a2[i] = u64(a[i]);\r\n  FOR(i, m) b0[i] = u64(b[i]),\
    \ b1[i] = u64(b[i]), b2[i] = u64(b[i]);\r\n  auto c0 = convolution_ntt<mint0>(a0,\
    \ b0);\r\n  auto c1 = convolution_ntt<mint1>(a1, b1);\r\n  auto c2 = convolution_ntt<mint2>(a2,\
    \ b2);\r\n\r\n  vi c(n + m - 1);\r\n  FOR(i, n + m - 1) {\r\n    c[i] = CRT3<u64,\
    \ p0, p1, p2>(c0[i].val, c1[i].val, c2[i].val);\r\n  }\r\n  return c;\r\n}\r\n\
    \r\ntemplate <typename mint>\r\nvc<mint> convolution(const vc<mint>& a, const\
    \ vc<mint>& b) {\r\n  int n = len(a), m = len(b);\r\n  if (!n || !m) return {};\r\
    \n  if (mint::can_ntt()) {\r\n    if (min(n, m) <= 50) return convolution_karatsuba<mint>(a,\
    \ b);\r\n    return convolution_ntt(a, b);\r\n  }\r\n  if (min(n, m) <= 200) return\
    \ convolution_karatsuba<mint>(a, b);\r\n  return convolution_garner(a, b);\r\n\
    }\r\n#line 2 \"bigint/base.hpp\"\n\n// 10^9 \u305A\u3064\u533A\u5207\u3063\u3066\
    \nstruct BigInteger {\n  static constexpr int TEN[]\n      = {1,      10,    \
    \  100,      1000,      10000,\n         100000, 1000000, 10000000, 100000000,\
    \ 1000000000};\n  static constexpr int LOG = 9;\n  static constexpr int MOD =\
    \ TEN[LOG];\n  using bint = BigInteger;\n  int sgn; // +1 or -1. \u5185\u90E8\u72B6\
    \u614B\u3067 -0 \u3092\u8A31\u5BB9\u3059\u308B.\n  vc<int> dat;\n\n  BigInteger()\
    \ : sgn(1) {}\n  BigInteger(i128 val) {\n    sgn = 1;\n    if (val != 0) {\n \
    \     if (val < 0) sgn = -1, val = -val;\n      while (val > 0) {\n        dat.eb(val\
    \ % MOD);\n        val /= MOD;\n      }\n    }\n  }\n  BigInteger(string s) {\n\
    \    assert(!s.empty());\n    sgn = 1;\n    if (s[0] == '-') {\n      sgn = -1;\n\
    \      s.erase(s.begin());\n      assert(!s.empty());\n    }\n    if (s[0] ==\
    \ '0') s.clear();\n    reverse(all(s));\n    int n = len(s);\n    int m = ceil(n,\
    \ LOG);\n    dat.assign(m, 0);\n    FOR(i, n) { dat[i / LOG] += TEN[i % LOG] *\
    \ (s[i] - '0'); }\n  }\n  bint &operator=(const bint &p) {\n    sgn = p.sgn;\n\
    \    dat = p.dat;\n    return *this;\n  }\n  bool operator<(const bint &p) const\
    \ {\n    if (sgn != p.sgn) return sgn < p.sgn;\n    if (len(dat) != len(p.dat))\
    \ {\n      if (sgn == 1) return len(dat) < len(p.dat);\n      if (sgn == -1) return\
    \ len(dat) > len(p.dat);\n    }\n    FOR_R(i, len(dat)) {\n      if (dat[i] ==\
    \ p.dat[i]) continue;\n      if (sgn == 1) return dat[i] < p.dat[i];\n      if\
    \ (sgn == -1) return dat[i] > p.dat[i];\n    }\n    return false;\n  }\n  bool\
    \ operator>(const bint &p) const { return p < *this; }\n  bool operator<=(const\
    \ bint &p) const { return !(*this > p); }\n  bool operator>=(const bint &p) const\
    \ { return !(*this < p); }\n  bint &operator+=(const bint p) {\n    if (sgn !=\
    \ p.sgn) {\n      *this -= (-p);\n      return *this;\n    }\n    int n = max(len(dat),\
    \ len(p.dat));\n    dat.resize(n + 1);\n    FOR(i, n) {\n      if (i < len(p.dat))\
    \ dat[i] += p.dat[i];\n      if (dat[i] >= MOD) dat[i] -= MOD, dat[i + 1] += 1;\n\
    \    }\n    while (len(dat) && dat.back() == 0) dat.pop_back();\n    return *this;\n\
    \  }\n  bint &operator-=(const bint p) {\n    if (sgn != p.sgn) {\n      *this\
    \ += (-p);\n      return *this;\n    }\n    if ((sgn == 1 && *this < p) || (sgn\
    \ == -1 && *this > p)) {\n      *this = p - *this;\n      sgn = -sgn;\n      return\
    \ *this;\n    }\n    FOR(i, len(p.dat)) { dat[i] -= p.dat[i]; }\n    FOR(i, len(dat)\
    \ - 1) {\n      if (dat[i] < 0) dat[i] += MOD, dat[i + 1] -= 1;\n    }\n    while\
    \ (len(dat) && dat.back() == 0) { dat.pop_back(); }\n    return *this;\n  }\n\
    \  bint &operator*=(const bint &p) {\n    sgn *= p.sgn;\n    dat = convolve(dat,\
    \ p.dat);\n    return *this;\n  }\n  // bint &operator/=(const bint &p) { return\
    \ *this; }\n  bint operator-() const {\n    bint p = *this;\n    p.sgn *= -1;\n\
    \    return p;\n  }\n  bint operator+(const bint &p) const { return bint(*this)\
    \ += p; }\n  bint operator-(const bint &p) const { return bint(*this) -= p; }\n\
    \  bint operator*(const bint &p) const { return bint(*this) *= p; }\n  // bint\
    \ operator/(const modint &p) const { return modint(*this) /= p; }\n  bool operator==(const\
    \ bint &p) const {\n    return (sgn == p.sgn && dat == p.dat);\n  }\n  bool operator!=(const\
    \ bint &p) const {\n    return (sgn != p.sgn || dat != p.dat);\n  }\n\n  vc<int>\
    \ convolve(const vc<int> &a, const vc<int> &b) {\n    int n = len(a), m = len(b);\n\
    \    if (!n || !m) return {};\n    if (min(n, m) <= 500) {\n      vc<int> c(n\
    \ + m - 1);\n      u128 x = 0;\n      FOR(k, n + m - 1) {\n        int s = max<int>(0,\
    \ k + 1 - m), t = min<int>(k, n - 1);\n        FOR(i, s, t + 1) { x += u64(a[i])\
    \ * b[k - i]; }\n        c[k] = x % MOD, x = x / MOD;\n      }\n      while (x\
    \ > 0) { c.eb(x % MOD), x = x / MOD; }\n      return c;\n    }\n    static constexpr\
    \ int p0 = 167772161;\n    static constexpr int p1 = 469762049;\n    static constexpr\
    \ int p2 = 754974721;\n    using mint0 = modint<p0>;\n    using mint1 = modint<p1>;\n\
    \    using mint2 = modint<p2>;\n    vc<mint0> a0(all(a)), b0(all(b));\n    vc<mint1>\
    \ a1(all(a)), b1(all(b));\n    vc<mint2> a2(all(a)), b2(all(b));\n    auto c0\
    \ = convolution_ntt<mint0>(a0, b0);\n    auto c1 = convolution_ntt<mint1>(a1,\
    \ b1);\n    auto c2 = convolution_ntt<mint2>(a2, b2);\n    vc<int> c(len(c0));\n\
    \    u128 x = 0;\n    FOR(i, n + m - 1) {\n      x += CRT3<u128, p0, p1, p2>(c0[i].val,\
    \ c1[i].val, c2[i].val);\n      c[i] = x % MOD, x = x / MOD;\n    }\n    while\
    \ (x) { c.eb(x % MOD), x = x / MOD; }\n    return c;\n  }\n\n  string to_string()\
    \ {\n    if (dat.empty()) return \"0\";\n    string s;\n    for (int x: dat) {\n\
    \      FOR(LOG) {\n        s += '0' + (x % 10);\n        x = x / 10;\n      }\n\
    \    }\n    while (s.back() == '0') s.pop_back();\n    if (sgn == -1) s += '-';\n\
    \    reverse(all(s));\n    return s;\n  }\n\n  // https://codeforces.com/contest/504/problem/D\n\
    \  string to_binary_string() {\n    vc<u32> A(all(dat));\n    string ANS;\n  \
    \  while (1) {\n      while (len(A) && A.back() == u32(0)) POP(A);\n      if (A.empty())\
    \ break;\n      u64 rem = 0;\n      FOR_R(i, len(A)) {\n        rem = rem * MOD\
    \ + A[i];\n        A[i] = rem >> 32;\n        rem &= u32(-1);\n      }\n     \
    \ FOR(i, 32) { ANS += '0' + (rem >> i & 1); }\n    }\n    while (len(ANS) && ANS.back()\
    \ == '0') ANS.pop_back();\n    reverse(all(ANS));\n    if (ANS.empty()) ANS +=\
    \ '0';\n    return ANS;\n  }\n\n  // https://codeforces.com/contest/759/problem/E\n\
    \  pair<bint, int> divmod(int p) {\n    assert(dat.empty() || sgn == 1);\n   \
    \ vc<int> after;\n    ll rm = 0;\n    FOR_R(i, len(dat)) {\n      rm = rm * MOD\
    \ + dat[i];\n      after.eb(rm / p);\n      rm = rm % p;\n    }\n    reverse(all(after));\n\
    \    while (len(after) && after.back() == 0) POP(after);\n    bint q;\n    q.sgn\
    \ = 1;\n    q.dat = after;\n    return {q, rm};\n  }\n\n  // https://codeforces.com/problemset/problem/582/D\n\
    \  vc<int> base_p_representation(int p) {\n    vc<u32> A(all(dat));\n    vc<int>\
    \ res;\n    while (1) {\n      while (len(A) && A.back() == u32(0)) POP(A);\n\
    \      if (A.empty()) break;\n      u64 rm = 0;\n      FOR_R(i, len(A)) {\n  \
    \      rm = rm * MOD + A[i];\n        A[i] = rm / p;\n        rm %= p;\n     \
    \ }\n      res.eb(rm);\n    }\n    reverse(all(res));\n    return res;\n  }\n\n\
    \  // overflow \u7121\u8996\u3057\u3066\u8A08\u7B97\n  ll to_ll() {\n    ll x\
    \ = 0;\n    FOR_R(i, len(dat)) x = MOD * x + dat[i];\n    return sgn * x;\n  }\n\
    \n  // https://codeforces.com/contest/986/problem/D\n  bint pow(ll n) {\n    auto\
    \ dfs = [&](auto &dfs, ll n) -> bint {\n      if (n == 1) return (*this);\n  \
    \    bint x = dfs(dfs, n / 2);\n      x *= x;\n      if (n & 1) x *= (*this);\n\
    \      return x;\n    };\n    if (n == 0) return bint(1);\n    return dfs(dfs,\
    \ n);\n  }\n\n  // https://codeforces.com/contest/986/problem/D\n  double log10()\
    \ {\n    assert(!dat.empty() && sgn == 1);\n    if (len(dat) <= 3) {\n      double\
    \ x = 0;\n      FOR_R(i, len(dat)) x = MOD * x + dat[i];\n      return std::log10(x);\n\
    \    }\n    double x = 0;\n    FOR(i, 4) x = MOD * x + dat[len(dat) - 1 - i];\n\
    \    x = std::log10(x);\n    x += double(LOG) * (len(dat) - 4);\n    return x;\n\
    \  }\n\n#ifdef FASTIO\n  void write() { fastio::printer.write(to_string()); }\n\
    \  void read() {\n    string s;\n    fastio::scanner.read(s);\n    *this = bint(s);\n\
    \  }\n#endif\n};\n"
  code: "#include \"poly/convolution.hpp\"\n\n// 10^9 \u305A\u3064\u533A\u5207\u3063\
    \u3066\nstruct BigInteger {\n  static constexpr int TEN[]\n      = {1,      10,\
    \      100,      1000,      10000,\n         100000, 1000000, 10000000, 100000000,\
    \ 1000000000};\n  static constexpr int LOG = 9;\n  static constexpr int MOD =\
    \ TEN[LOG];\n  using bint = BigInteger;\n  int sgn; // +1 or -1. \u5185\u90E8\u72B6\
    \u614B\u3067 -0 \u3092\u8A31\u5BB9\u3059\u308B.\n  vc<int> dat;\n\n  BigInteger()\
    \ : sgn(1) {}\n  BigInteger(i128 val) {\n    sgn = 1;\n    if (val != 0) {\n \
    \     if (val < 0) sgn = -1, val = -val;\n      while (val > 0) {\n        dat.eb(val\
    \ % MOD);\n        val /= MOD;\n      }\n    }\n  }\n  BigInteger(string s) {\n\
    \    assert(!s.empty());\n    sgn = 1;\n    if (s[0] == '-') {\n      sgn = -1;\n\
    \      s.erase(s.begin());\n      assert(!s.empty());\n    }\n    if (s[0] ==\
    \ '0') s.clear();\n    reverse(all(s));\n    int n = len(s);\n    int m = ceil(n,\
    \ LOG);\n    dat.assign(m, 0);\n    FOR(i, n) { dat[i / LOG] += TEN[i % LOG] *\
    \ (s[i] - '0'); }\n  }\n  bint &operator=(const bint &p) {\n    sgn = p.sgn;\n\
    \    dat = p.dat;\n    return *this;\n  }\n  bool operator<(const bint &p) const\
    \ {\n    if (sgn != p.sgn) return sgn < p.sgn;\n    if (len(dat) != len(p.dat))\
    \ {\n      if (sgn == 1) return len(dat) < len(p.dat);\n      if (sgn == -1) return\
    \ len(dat) > len(p.dat);\n    }\n    FOR_R(i, len(dat)) {\n      if (dat[i] ==\
    \ p.dat[i]) continue;\n      if (sgn == 1) return dat[i] < p.dat[i];\n      if\
    \ (sgn == -1) return dat[i] > p.dat[i];\n    }\n    return false;\n  }\n  bool\
    \ operator>(const bint &p) const { return p < *this; }\n  bool operator<=(const\
    \ bint &p) const { return !(*this > p); }\n  bool operator>=(const bint &p) const\
    \ { return !(*this < p); }\n  bint &operator+=(const bint p) {\n    if (sgn !=\
    \ p.sgn) {\n      *this -= (-p);\n      return *this;\n    }\n    int n = max(len(dat),\
    \ len(p.dat));\n    dat.resize(n + 1);\n    FOR(i, n) {\n      if (i < len(p.dat))\
    \ dat[i] += p.dat[i];\n      if (dat[i] >= MOD) dat[i] -= MOD, dat[i + 1] += 1;\n\
    \    }\n    while (len(dat) && dat.back() == 0) dat.pop_back();\n    return *this;\n\
    \  }\n  bint &operator-=(const bint p) {\n    if (sgn != p.sgn) {\n      *this\
    \ += (-p);\n      return *this;\n    }\n    if ((sgn == 1 && *this < p) || (sgn\
    \ == -1 && *this > p)) {\n      *this = p - *this;\n      sgn = -sgn;\n      return\
    \ *this;\n    }\n    FOR(i, len(p.dat)) { dat[i] -= p.dat[i]; }\n    FOR(i, len(dat)\
    \ - 1) {\n      if (dat[i] < 0) dat[i] += MOD, dat[i + 1] -= 1;\n    }\n    while\
    \ (len(dat) && dat.back() == 0) { dat.pop_back(); }\n    return *this;\n  }\n\
    \  bint &operator*=(const bint &p) {\n    sgn *= p.sgn;\n    dat = convolve(dat,\
    \ p.dat);\n    return *this;\n  }\n  // bint &operator/=(const bint &p) { return\
    \ *this; }\n  bint operator-() const {\n    bint p = *this;\n    p.sgn *= -1;\n\
    \    return p;\n  }\n  bint operator+(const bint &p) const { return bint(*this)\
    \ += p; }\n  bint operator-(const bint &p) const { return bint(*this) -= p; }\n\
    \  bint operator*(const bint &p) const { return bint(*this) *= p; }\n  // bint\
    \ operator/(const modint &p) const { return modint(*this) /= p; }\n  bool operator==(const\
    \ bint &p) const {\n    return (sgn == p.sgn && dat == p.dat);\n  }\n  bool operator!=(const\
    \ bint &p) const {\n    return (sgn != p.sgn || dat != p.dat);\n  }\n\n  vc<int>\
    \ convolve(const vc<int> &a, const vc<int> &b) {\n    int n = len(a), m = len(b);\n\
    \    if (!n || !m) return {};\n    if (min(n, m) <= 500) {\n      vc<int> c(n\
    \ + m - 1);\n      u128 x = 0;\n      FOR(k, n + m - 1) {\n        int s = max<int>(0,\
    \ k + 1 - m), t = min<int>(k, n - 1);\n        FOR(i, s, t + 1) { x += u64(a[i])\
    \ * b[k - i]; }\n        c[k] = x % MOD, x = x / MOD;\n      }\n      while (x\
    \ > 0) { c.eb(x % MOD), x = x / MOD; }\n      return c;\n    }\n    static constexpr\
    \ int p0 = 167772161;\n    static constexpr int p1 = 469762049;\n    static constexpr\
    \ int p2 = 754974721;\n    using mint0 = modint<p0>;\n    using mint1 = modint<p1>;\n\
    \    using mint2 = modint<p2>;\n    vc<mint0> a0(all(a)), b0(all(b));\n    vc<mint1>\
    \ a1(all(a)), b1(all(b));\n    vc<mint2> a2(all(a)), b2(all(b));\n    auto c0\
    \ = convolution_ntt<mint0>(a0, b0);\n    auto c1 = convolution_ntt<mint1>(a1,\
    \ b1);\n    auto c2 = convolution_ntt<mint2>(a2, b2);\n    vc<int> c(len(c0));\n\
    \    u128 x = 0;\n    FOR(i, n + m - 1) {\n      x += CRT3<u128, p0, p1, p2>(c0[i].val,\
    \ c1[i].val, c2[i].val);\n      c[i] = x % MOD, x = x / MOD;\n    }\n    while\
    \ (x) { c.eb(x % MOD), x = x / MOD; }\n    return c;\n  }\n\n  string to_string()\
    \ {\n    if (dat.empty()) return \"0\";\n    string s;\n    for (int x: dat) {\n\
    \      FOR(LOG) {\n        s += '0' + (x % 10);\n        x = x / 10;\n      }\n\
    \    }\n    while (s.back() == '0') s.pop_back();\n    if (sgn == -1) s += '-';\n\
    \    reverse(all(s));\n    return s;\n  }\n\n  // https://codeforces.com/contest/504/problem/D\n\
    \  string to_binary_string() {\n    vc<u32> A(all(dat));\n    string ANS;\n  \
    \  while (1) {\n      while (len(A) && A.back() == u32(0)) POP(A);\n      if (A.empty())\
    \ break;\n      u64 rem = 0;\n      FOR_R(i, len(A)) {\n        rem = rem * MOD\
    \ + A[i];\n        A[i] = rem >> 32;\n        rem &= u32(-1);\n      }\n     \
    \ FOR(i, 32) { ANS += '0' + (rem >> i & 1); }\n    }\n    while (len(ANS) && ANS.back()\
    \ == '0') ANS.pop_back();\n    reverse(all(ANS));\n    if (ANS.empty()) ANS +=\
    \ '0';\n    return ANS;\n  }\n\n  // https://codeforces.com/contest/759/problem/E\n\
    \  pair<bint, int> divmod(int p) {\n    assert(dat.empty() || sgn == 1);\n   \
    \ vc<int> after;\n    ll rm = 0;\n    FOR_R(i, len(dat)) {\n      rm = rm * MOD\
    \ + dat[i];\n      after.eb(rm / p);\n      rm = rm % p;\n    }\n    reverse(all(after));\n\
    \    while (len(after) && after.back() == 0) POP(after);\n    bint q;\n    q.sgn\
    \ = 1;\n    q.dat = after;\n    return {q, rm};\n  }\n\n  // https://codeforces.com/problemset/problem/582/D\n\
    \  vc<int> base_p_representation(int p) {\n    vc<u32> A(all(dat));\n    vc<int>\
    \ res;\n    while (1) {\n      while (len(A) && A.back() == u32(0)) POP(A);\n\
    \      if (A.empty()) break;\n      u64 rm = 0;\n      FOR_R(i, len(A)) {\n  \
    \      rm = rm * MOD + A[i];\n        A[i] = rm / p;\n        rm %= p;\n     \
    \ }\n      res.eb(rm);\n    }\n    reverse(all(res));\n    return res;\n  }\n\n\
    \  // overflow \u7121\u8996\u3057\u3066\u8A08\u7B97\n  ll to_ll() {\n    ll x\
    \ = 0;\n    FOR_R(i, len(dat)) x = MOD * x + dat[i];\n    return sgn * x;\n  }\n\
    \n  // https://codeforces.com/contest/986/problem/D\n  bint pow(ll n) {\n    auto\
    \ dfs = [&](auto &dfs, ll n) -> bint {\n      if (n == 1) return (*this);\n  \
    \    bint x = dfs(dfs, n / 2);\n      x *= x;\n      if (n & 1) x *= (*this);\n\
    \      return x;\n    };\n    if (n == 0) return bint(1);\n    return dfs(dfs,\
    \ n);\n  }\n\n  // https://codeforces.com/contest/986/problem/D\n  double log10()\
    \ {\n    assert(!dat.empty() && sgn == 1);\n    if (len(dat) <= 3) {\n      double\
    \ x = 0;\n      FOR_R(i, len(dat)) x = MOD * x + dat[i];\n      return std::log10(x);\n\
    \    }\n    double x = 0;\n    FOR(i, 4) x = MOD * x + dat[len(dat) - 1 - i];\n\
    \    x = std::log10(x);\n    x += double(LOG) * (len(dat) - 4);\n    return x;\n\
    \  }\n\n#ifdef FASTIO\n  void write() { fastio::printer.write(to_string()); }\n\
    \  void read() {\n    string s;\n    fastio::scanner.read(s);\n    *this = bint(s);\n\
    \  }\n#endif\n};"
  dependsOn:
  - poly/convolution.hpp
  - mod/modint.hpp
  - mod/modint_common.hpp
  - mod/mod_inv.hpp
  - mod/crt3.hpp
  - poly/convolution_naive.hpp
  - poly/convolution_karatsuba.hpp
  - poly/ntt.hpp
  - poly/fft.hpp
  isVerificationFile: false
  path: bigint/base.hpp
  requiredBy: []
  timestamp: '2023-11-01 19:15:19+09:00'
  verificationStatus: LIBRARY_SOME_WA
  verifiedWith:
  - test/aoj/NTL_2_B.test.cpp
  - test/aoj/NTL_2_A.test.cpp
  - test/aoj/NTL_2_C.test.cpp
  - test/library_checker/multiplication_of_bigintegers.test.cpp
  - test/library_checker/sample/aplusb128.test.cpp
  - test/library_checker/addition_of_bigintegers.test.cpp
  - test/yukicoder/303.test.cpp
  - test/yukicoder/2508.test.cpp
documentation_of: bigint/base.hpp
layout: document
redirect_from:
- /library/bigint/base.hpp
- /library/bigint/base.hpp.html
title: bigint/base.hpp
---
