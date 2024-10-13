---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: mod/crt3.hpp
    title: mod/crt3.hpp
  - icon: ':heavy_check_mark:'
    path: mod/modint.hpp
    title: mod/modint.hpp
  - icon: ':heavy_check_mark:'
    path: mod/modint_common.hpp
    title: mod/modint_common.hpp
  - icon: ':heavy_check_mark:'
    path: poly/ntt.hpp
    title: poly/ntt.hpp
  - icon: ':heavy_check_mark:'
    path: poly/online/online_convolution.hpp
    title: poly/online/online_convolution.hpp
  - icon: ':warning:'
    path: poly/online/online_convolution_garner.hpp
    title: poly/online/online_convolution_garner.hpp
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':warning:'
  attributes:
    links: []
  bundledCode: "#line 2 \"mod/crt3.hpp\"\n\nconstexpr u32 mod_pow_constexpr(u64 a,\
    \ u64 n, u32 mod) {\n  a %= mod;\n  u64 res = 1;\n  FOR(32) {\n    if (n & 1)\
    \ res = res * a % mod;\n    a = a * a % mod, n /= 2;\n  }\n  return res;\n}\n\n\
    template <typename T, u32 p0, u32 p1>\nT CRT2(u64 a0, u64 a1) {\n  static_assert(p0\
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
    \ T(ans_3) + T(c) * T(p01) * T(p23);\n}\n#line 2 \"poly/ntt.hpp\"\n\r\ntemplate\
    \ <class mint>\r\nvoid ntt(vector<mint>& a, bool inverse) {\r\n  assert(mint::can_ntt());\r\
    \n  const int rank2 = mint::ntt_info().fi;\r\n  const int mod = mint::get_mod();\r\
    \n  static array<mint, 30> root, iroot;\r\n  static array<mint, 30> rate2, irate2;\r\
    \n  static array<mint, 30> rate3, irate3;\r\n\r\n  assert(rank2 != -1 && len(a)\
    \ <= (1 << max(0, rank2)));\r\n\r\n  static bool prepared = 0;\r\n  if (!prepared)\
    \ {\r\n    prepared = 1;\r\n    root[rank2] = mint::ntt_info().se;\r\n    iroot[rank2]\
    \ = mint(1) / root[rank2];\r\n    FOR_R(i, rank2) {\r\n      root[i] = root[i\
    \ + 1] * root[i + 1];\r\n      iroot[i] = iroot[i + 1] * iroot[i + 1];\r\n   \
    \ }\r\n    mint prod = 1, iprod = 1;\r\n    for (int i = 0; i <= rank2 - 2; i++)\
    \ {\r\n      rate2[i] = root[i + 2] * prod;\r\n      irate2[i] = iroot[i + 2]\
    \ * iprod;\r\n      prod *= iroot[i + 2];\r\n      iprod *= root[i + 2];\r\n \
    \   }\r\n    prod = 1, iprod = 1;\r\n    for (int i = 0; i <= rank2 - 3; i++)\
    \ {\r\n      rate3[i] = root[i + 3] * prod;\r\n      irate3[i] = iroot[i + 3]\
    \ * iprod;\r\n      prod *= iroot[i + 3];\r\n      iprod *= root[i + 3];\r\n \
    \   }\r\n  }\r\n\r\n  int n = int(a.size());\r\n  int h = topbit(n);\r\n  assert(n\
    \ == 1 << h);\r\n  if (!inverse) {\r\n    int len = 0;\r\n    while (len < h)\
    \ {\r\n      if (h - len == 1) {\r\n        int p = 1 << (h - len - 1);\r\n  \
    \      mint rot = 1;\r\n        FOR(s, 1 << len) {\r\n          int offset = s\
    \ << (h - len);\r\n          FOR(i, p) {\r\n            auto l = a[i + offset];\r\
    \n            auto r = a[i + offset + p] * rot;\r\n            a[i + offset] =\
    \ l + r;\r\n            a[i + offset + p] = l - r;\r\n          }\r\n        \
    \  rot *= rate2[topbit(~s & -~s)];\r\n        }\r\n        len++;\r\n      } else\
    \ {\r\n        int p = 1 << (h - len - 2);\r\n        mint rot = 1, imag = root[2];\r\
    \n        for (int s = 0; s < (1 << len); s++) {\r\n          mint rot2 = rot\
    \ * rot;\r\n          mint rot3 = rot2 * rot;\r\n          int offset = s << (h\
    \ - len);\r\n          for (int i = 0; i < p; i++) {\r\n            u64 mod2 =\
    \ u64(mod) * mod;\r\n            u64 a0 = a[i + offset].val;\r\n            u64\
    \ a1 = u64(a[i + offset + p].val) * rot.val;\r\n            u64 a2 = u64(a[i +\
    \ offset + 2 * p].val) * rot2.val;\r\n            u64 a3 = u64(a[i + offset +\
    \ 3 * p].val) * rot3.val;\r\n            u64 a1na3imag = (a1 + mod2 - a3) % mod\
    \ * imag.val;\r\n            u64 na2 = mod2 - a2;\r\n            a[i + offset]\
    \ = a0 + a2 + a1 + a3;\r\n            a[i + offset + 1 * p] = a0 + a2 + (2 * mod2\
    \ - (a1 + a3));\r\n            a[i + offset + 2 * p] = a0 + na2 + a1na3imag;\r\
    \n            a[i + offset + 3 * p] = a0 + na2 + (mod2 - a1na3imag);\r\n     \
    \     }\r\n          rot *= rate3[topbit(~s & -~s)];\r\n        }\r\n        len\
    \ += 2;\r\n      }\r\n    }\r\n  } else {\r\n    mint coef = mint(1) / mint(len(a));\r\
    \n    FOR(i, len(a)) a[i] *= coef;\r\n    int len = h;\r\n    while (len) {\r\n\
    \      if (len == 1) {\r\n        int p = 1 << (h - len);\r\n        mint irot\
    \ = 1;\r\n        FOR(s, 1 << (len - 1)) {\r\n          int offset = s << (h -\
    \ len + 1);\r\n          FOR(i, p) {\r\n            u64 l = a[i + offset].val;\r\
    \n            u64 r = a[i + offset + p].val;\r\n            a[i + offset] = l\
    \ + r;\r\n            a[i + offset + p] = (mod + l - r) * irot.val;\r\n      \
    \    }\r\n          irot *= irate2[topbit(~s & -~s)];\r\n        }\r\n       \
    \ len--;\r\n      } else {\r\n        int p = 1 << (h - len);\r\n        mint\
    \ irot = 1, iimag = iroot[2];\r\n        FOR(s, (1 << (len - 2))) {\r\n      \
    \    mint irot2 = irot * irot;\r\n          mint irot3 = irot2 * irot;\r\n   \
    \       int offset = s << (h - len + 2);\r\n          for (int i = 0; i < p; i++)\
    \ {\r\n            u64 a0 = a[i + offset + 0 * p].val;\r\n            u64 a1 =\
    \ a[i + offset + 1 * p].val;\r\n            u64 a2 = a[i + offset + 2 * p].val;\r\
    \n            u64 a3 = a[i + offset + 3 * p].val;\r\n            u64 x = (mod\
    \ + a2 - a3) * iimag.val % mod;\r\n            a[i + offset] = a0 + a1 + a2 +\
    \ a3;\r\n            a[i + offset + 1 * p] = (a0 + mod - a1 + x) * irot.val;\r\
    \n            a[i + offset + 2 * p] = (a0 + a1 + 2 * mod - a2 - a3) * irot2.val;\r\
    \n            a[i + offset + 3 * p] = (a0 + 2 * mod - a1 - x) * irot3.val;\r\n\
    \          }\r\n          irot *= irate3[topbit(~s & -~s)];\r\n        }\r\n \
    \       len -= 2;\r\n      }\r\n    }\r\n  }\r\n}\r\n#line 2 \"mod/modint_common.hpp\"\
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
    \ 1004535809) return {21, 836905998};\n    if (mod == 1045430273) return {20,\
    \ 363};\n    if (mod == 1051721729) return {20, 330};\n    if (mod == 1053818881)\
    \ return {20, 2789};\n    return {-1, -1};\n  }\n  static constexpr bool can_ntt()\
    \ { return ntt_info().fi != -1; }\n};\n\n#ifdef FASTIO\ntemplate <int mod>\nvoid\
    \ rd(modint<mod> &x) {\n  fastio::rd(x.val);\n  x.val %= mod;\n  // assert(0 <=\
    \ x.val && x.val < mod);\n}\ntemplate <int mod>\nvoid wt(modint<mod> x) {\n  fastio::wt(x.val);\n\
    }\n#endif\n\nusing modint107 = modint<1000000007>;\nusing modint998 = modint<998244353>;\n\
    #line 4 \"poly/online/online_convolution.hpp\"\n\n/*\nquery(i)\uFF1Aa[i], b[i]\
    \ \u3092\u4E0E\u3048\u3066 ab[i] \u3092\u5F97\u308B\u3002\n2^{17}\uFF1A127ms\n\
    2^{18}\uFF1A277ms\n2^{19}\uFF1A570ms\n2^{20}\uFF1A1220ms\n*/\ntemplate <class\
    \ mint>\nstruct Online_Convolution {\n  vc<mint> f, g, h, b0, b1;\n  vvc<mint>\
    \ fm, gm;\n  int p;\n\n  Online_Convolution() : p(0) { assert(mint::can_ntt());\
    \ }\n\n  mint query(int i, mint f_i, mint g_i) {\n    assert(i == p);\n    f.eb(f_i),\
    \ g.eb(g_i);\n    int z = __builtin_ctz(p + 2), w = 1 << z, s;\n    if (p + 2\
    \ == w) {\n      b0 = f, b0.resize(2 * w);\n      ntt(b0, false);\n      fm.eb(b0.begin(),\
    \ b0.begin() + w);\n      b1 = g, b1.resize(2 * w);\n      ntt(b1, false);\n \
    \     gm.eb(b1.begin(), b1.begin() + w);\n      FOR(i, 2 * w) b0[i] *= b1[i];\n\
    \      s = w - 2;\n      h.resize(2 * s + 2);\n    } else {\n      b0.assign(f.end()\
    \ - w, f.end()), b0.resize(2 * w);\n      ntt(b0, false);\n      FOR(i, 2 * w)\
    \ b0[i] *= gm[z][i];\n      b1.assign(g.end() - w, g.end()), b1.resize(2 * w);\n\
    \      ntt(b1, false);\n      FOR(i, 2 * w) b0[i] += b1[i] * fm[z][i];\n     \
    \ s = w - 1;\n    }\n    ntt(b0, true);\n    FOR(i, s + 1) h[p + i] += b0[s +\
    \ i];\n    return h[p++];\n  }\n};\n#line 3 \"poly/online/online_convolution_garner.hpp\"\
    \n\ntemplate <class mint>\nstruct Online_Convolution_Garner {\n  static constexpr\
    \ int p0 = 167772161;\n  static constexpr int p1 = 469762049;\n  static constexpr\
    \ int p2 = 754974721;\n  using mint0 = modint<p0>;\n  using mint1 = modint<p1>;\n\
    \  using mint2 = modint<p2>;\n  Online_Convolution<mint0> OC0;\n  Online_Convolution<mint1>\
    \ OC1;\n  Online_Convolution<mint2> OC2;\n  int p;\n  Online_Convolution_Garner()\
    \ : p(0) {}\n\n  mint query(int i, mint f_i, mint g_i) {\n    assert(i == p);\n\
    \    p++;\n    u64 x0 = OC0.query(i, f_i.val, g_i.val).val;\n    u64 x1 = OC1.query(i,\
    \ f_i.val, g_i.val).val;\n    u64 x2 = OC2.query(i, f_i.val, g_i.val).val;\n \
    \   return CRT3<mint, p0, p1, p2>(x0, x1, x2);\n  }\n};\n#line 3 \"poly/online/online_exp_garner.hpp\"\
    \n\n// query(i)\uFF1Af[i] \u3092\u4E0E\u3048\u3066 (f^{-1})[i] \u3092\u5F97\u308B\
    \u3002\ntemplate <typename mint>\nstruct Online_Exp_Garner {\n  vc<mint> F;\n\
    \  Online_Convolution_Garner<mint> X;\n\n  mint query(int i, mint f_i) {\n   \
    \ assert(i == len(F));\n    if (i == 0) {\n      assert(f_i == mint(0));\n   \
    \   F.eb(mint(1));\n      return mint(1);\n    }\n    mint x = inv<mint>(i) *\
    \ X.query(i - 1, F[i - 1], f_i * mint(i));\n    F.eb(x);\n    return x;\n  }\n\
    };\n"
  code: "#pragma once\n#include \"poly/online/online_convolution_garner.hpp\"\n\n\
    // query(i)\uFF1Af[i] \u3092\u4E0E\u3048\u3066 (f^{-1})[i] \u3092\u5F97\u308B\u3002\
    \ntemplate <typename mint>\nstruct Online_Exp_Garner {\n  vc<mint> F;\n  Online_Convolution_Garner<mint>\
    \ X;\n\n  mint query(int i, mint f_i) {\n    assert(i == len(F));\n    if (i ==\
    \ 0) {\n      assert(f_i == mint(0));\n      F.eb(mint(1));\n      return mint(1);\n\
    \    }\n    mint x = inv<mint>(i) * X.query(i - 1, F[i - 1], f_i * mint(i));\n\
    \    F.eb(x);\n    return x;\n  }\n};\n"
  dependsOn:
  - poly/online/online_convolution_garner.hpp
  - mod/crt3.hpp
  - poly/online/online_convolution.hpp
  - poly/ntt.hpp
  - mod/modint.hpp
  - mod/modint_common.hpp
  isVerificationFile: false
  path: poly/online/online_exp_garner.hpp
  requiredBy: []
  timestamp: '2024-10-11 20:53:53+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: poly/online/online_exp_garner.hpp
layout: document
redirect_from:
- /library/poly/online/online_exp_garner.hpp
- /library/poly/online/online_exp_garner.hpp.html
title: poly/online/online_exp_garner.hpp
---
