---
data:
  _extendedDependsOn:
  - icon: ':question:'
    path: mod/barrett.hpp
    title: mod/barrett.hpp
  - icon: ':question:'
    path: mod/mod_inv.hpp
    title: mod/mod_inv.hpp
  - icon: ':question:'
    path: mod/mod_pow.hpp
    title: mod/mod_pow.hpp
  - icon: ':question:'
    path: mod/modint.hpp
    title: mod/modint.hpp
  - icon: ':question:'
    path: mod/modint_common.hpp
    title: mod/modint_common.hpp
  - icon: ':question:'
    path: mod/primitive_root.hpp
    title: mod/primitive_root.hpp
  - icon: ':question:'
    path: nt/factor.hpp
    title: nt/factor.hpp
  - icon: ':question:'
    path: nt/primetest.hpp
    title: nt/primetest.hpp
  - icon: ':question:'
    path: poly/convolution.hpp
    title: poly/convolution.hpp
  - icon: ':question:'
    path: poly/convolution_naive.hpp
    title: poly/convolution_naive.hpp
  - icon: ':question:'
    path: poly/count_terms.hpp
    title: poly/count_terms.hpp
  - icon: ':question:'
    path: poly/fft.hpp
    title: poly/fft.hpp
  - icon: ':question:'
    path: poly/fps_inv.hpp
    title: poly/fps_inv.hpp
  - icon: ':question:'
    path: poly/middle_product.hpp
    title: poly/middle_product.hpp
  - icon: ':question:'
    path: poly/multipoint.hpp
    title: poly/multipoint.hpp
  - icon: ':question:'
    path: poly/ntt.hpp
    title: poly/ntt.hpp
  - icon: ':question:'
    path: random/base.hpp
    title: random/base.hpp
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':x:'
    path: test/library_checker/math/multivariate_convolution_cyclic.test.cpp
    title: test/library_checker/math/multivariate_convolution_cyclic.test.cpp
  _isVerificationFailed: true
  _pathExtension: hpp
  _verificationStatusIcon: ':x:'
  attributes:
    links: []
  bundledCode: "#line 2 \"poly/multipoint.hpp\"\n\r\n#line 2 \"poly/count_terms.hpp\"\
    \ntemplate<typename mint>\r\nint count_terms(const vc<mint>& f){\r\n  int t =\
    \ 0;\r\n  FOR(i, len(f)) if(f[i] != mint(0)) ++t;\r\n  return t;\r\n}\n#line 2\
    \ \"mod/modint_common.hpp\"\n\nstruct has_mod_impl {\n  template <class T>\n \
    \ static auto check(T &&x) -> decltype(x.get_mod(), std::true_type{});\n  template\
    \ <class T>\n  static auto check(...) -> std::false_type;\n};\n\ntemplate <class\
    \ T>\nclass has_mod : public decltype(has_mod_impl::check<T>(std::declval<T>()))\
    \ {};\n\n\ntemplate <typename mint>\nmint inv(int n) {\n  static const int mod\
    \ = mint::get_mod();\n  static vector<mint> dat = {0, 1};\n  assert(0 <= n);\n\
    \  if (n >= mod) n %= mod;\n  while (len(dat) <= n) {\n    int k = len(dat);\n\
    \    int q = (mod + k - 1) / k;\n    dat.eb(dat[k * q - mod] * mint(q));\n  }\n\
    \  return dat[n];\n}\n\ntemplate <typename mint>\nmint fact(int n) {\n  static\
    \ const int mod = mint::get_mod();\n  assert(0 <= n);\n  if (n >= mod) return\
    \ 0;\n  static vector<mint> dat = {1, 1};\n  while (len(dat) <= n) dat.eb(dat[len(dat)\
    \ - 1] * mint(len(dat)));\n  return dat[n];\n}\n\ntemplate <typename mint>\nmint\
    \ fact_inv(int n) {\n  static const int mod = mint::get_mod();\n  assert(-1 <=\
    \ n && n < mod);\n  static vector<mint> dat = {1, 1};\n  if (n == -1) return mint(0);\n\
    \  while (len(dat) <= n) dat.eb(dat[len(dat) - 1] * inv<mint>(len(dat)));\n  return\
    \ dat[n];\n}\n\ntemplate <class mint, class... Ts>\nmint fact_invs(Ts... xs) {\n\
    \  return (mint(1) * ... * fact_inv<mint>(xs));\n}\n\ntemplate <typename mint,\
    \ class Head, class... Tail>\nmint multinomial(Head &&head, Tail &&... tail) {\n\
    \  return fact<mint>(head) * fact_invs<mint>(std::forward<Tail>(tail)...);\n}\n\
    \ntemplate <typename mint>\nmint C_dense(int n, int k) {\n  static vvc<mint> C;\n\
    \  static int H = 0, W = 0;\n  auto calc = [&](int i, int j) -> mint {\n    if\
    \ (i == 0) return (j == 0 ? mint(1) : mint(0));\n    return C[i - 1][j] + (j ?\
    \ C[i - 1][j - 1] : 0);\n  };\n  if (W <= k) {\n    FOR(i, H) {\n      C[i].resize(k\
    \ + 1);\n      FOR(j, W, k + 1) { C[i][j] = calc(i, j); }\n    }\n    W = k +\
    \ 1;\n  }\n  if (H <= n) {\n    C.resize(n + 1);\n    FOR(i, H, n + 1) {\n   \
    \   C[i].resize(W);\n      FOR(j, W) { C[i][j] = calc(i, j); }\n    }\n    H =\
    \ n + 1;\n  }\n  return C[n][k];\n}\n\ntemplate <typename mint, bool large = false,\
    \ bool dense = false>\nmint C(ll n, ll k) {\n  assert(n >= 0);\n  if (k < 0 ||\
    \ n < k) return 0;\n  if (dense) return C_dense<mint>(n, k);\n  if (!large) return\
    \ multinomial<mint>(n, k, n - k);\n  k = min(k, n - k);\n  mint x(1);\n  FOR(i,\
    \ k) x *= mint(n - i);\n  return x * fact_inv<mint>(k);\n}\n\ntemplate <typename\
    \ mint, bool large = false>\nmint C_inv(ll n, ll k) {\n  assert(n >= 0);\n  assert(0\
    \ <= k && k <= n);\n  if (!large) return fact_inv<mint>(n) * fact<mint>(k) * fact<mint>(n\
    \ - k);\n  return mint(1) / C<mint, 1>(n, k);\n}\n\n// [x^d] (1-x) ^ {-n} \u306E\
    \u8A08\u7B97\ntemplate <typename mint, bool large = false, bool dense = false>\n\
    mint C_negative(ll n, ll d) {\n  assert(n >= 0);\n  if (d < 0) return mint(0);\n\
    \  if (n == 0) { return (d == 0 ? mint(1) : mint(0)); }\n  return C<mint, large,\
    \ dense>(n + d - 1, d);\n}\n#line 3 \"mod/modint.hpp\"\n\ntemplate <int mod>\n\
    struct modint {\n  int val;\n  constexpr modint(const ll val = 0) noexcept\n \
    \     : val(val >= 0 ? val % mod : (mod - (-val) % mod) % mod) {}\n  bool operator<(const\
    \ modint &other) const {\n    return val < other.val;\n  } // To use std::map\n\
    \  modint &operator+=(const modint &p) {\n    if ((val += p.val) >= mod) val -=\
    \ mod;\n    return *this;\n  }\n  modint &operator-=(const modint &p) {\n    if\
    \ ((val += mod - p.val) >= mod) val -= mod;\n    return *this;\n  }\n  modint\
    \ &operator*=(const modint &p) {\n    val = (int)(1LL * val * p.val % mod);\n\
    \    return *this;\n  }\n  modint &operator/=(const modint &p) {\n    *this *=\
    \ p.inverse();\n    return *this;\n  }\n  modint operator-() const { return modint(-val);\
    \ }\n  modint operator+(const modint &p) const { return modint(*this) += p; }\n\
    \  modint operator-(const modint &p) const { return modint(*this) -= p; }\n  modint\
    \ operator*(const modint &p) const { return modint(*this) *= p; }\n  modint operator/(const\
    \ modint &p) const { return modint(*this) /= p; }\n  bool operator==(const modint\
    \ &p) const { return val == p.val; }\n  bool operator!=(const modint &p) const\
    \ { return val != p.val; }\n  modint inverse() const {\n    int a = val, b = mod,\
    \ u = 1, v = 0, t;\n    while (b > 0) {\n      t = a / b;\n      swap(a -= t *\
    \ b, b), swap(u -= t * v, v);\n    }\n    return modint(u);\n  }\n  modint pow(ll\
    \ n) const {\n    assert(n >= 0);\n    modint ret(1), mul(val);\n    while (n\
    \ > 0) {\n      if (n & 1) ret *= mul;\n      mul *= mul;\n      n >>= 1;\n  \
    \  }\n    return ret;\n  }\n#ifdef FASTIO\n  void write() { fastio::printer.write(val);\
    \ }\n  void read() { fastio::scanner.read(val); }\n#endif\n  static constexpr\
    \ int get_mod() { return mod; }\n  // (n, r), r \u306F 1 \u306E 2^n \u4E57\u6839\
    \n  static constexpr pair<int, int> ntt_info() {\n    if (mod == 167772161) return\
    \ {25, 17};\n    if (mod == 469762049) return {26, 30};\n    if (mod == 754974721)\
    \ return {24, 362};\n    if (mod == 880803841) return {23, 211};\n    if (mod\
    \ == 998244353) return {23, 31};\n    if (mod == 1045430273) return {20, 363};\n\
    \    if (mod == 1051721729) return {20, 330};\n    if (mod == 1053818881) return\
    \ {20, 2789};\n    return {-1, -1};\n  }\n  static constexpr bool can_ntt() {\
    \ return ntt_info().fi != -1; }\n};\n\nusing modint107 = modint<1000000007>;\n\
    using modint998 = modint<998244353>;\n#line 2 \"mod/mod_inv.hpp\"\n// long \u3067\
    \u3082\u5927\u4E08\u592B\r\nll mod_inv(ll val, ll mod) {\r\n  val %= mod;\r\n\
    \  if (val < 0) val += mod;\r\n  ll a = val, b = mod, u = 1, v = 0, t;\r\n  while\
    \ (b > 0) {\r\n    t = a / b;\r\n    swap(a -= t * b, b), swap(u -= t * v, v);\r\
    \n  }\r\n  if (u < 0) u += mod;\r\n  return u;\r\n}\r\n#line 1 \"poly/convolution_naive.hpp\"\
    \ntemplate <class T>\r\nvector<T> convolution_naive(const vector<T>& a, const\
    \ vector<T>& b) {\r\n  int n = int(a.size()), m = int(b.size());\r\n  vector<T>\
    \ ans(n + m - 1);\r\n  if (n < m) {\r\n    FOR(j, m) FOR(i, n) ans[i + j] += a[i]\
    \ * b[j];\r\n  } else {\r\n    FOR(i, n) FOR(j, m) ans[i + j] += a[i] * b[j];\r\
    \n  }\r\n  return ans;\r\n}\r\n#line 2 \"poly/ntt.hpp\"\n\r\ntemplate <class mint>\r\
    \nvoid ntt(vector<mint>& a, bool inverse) {\r\n  assert(mint::can_ntt());\r\n\
    \  const int rank2 = mint::ntt_info().fi;\r\n  const int mod = mint::get_mod();\r\
    \n  static array<mint, 30> root, iroot;\r\n  static array<mint, 30> rate2, irate2;\r\
    \n  static array<mint, 30> rate3, irate3;\r\n\r\n  static bool prepared = 0;\r\
    \n  if (!prepared) {\r\n    prepared = 1;\r\n    root[rank2] = mint::ntt_info().se;\r\
    \n    iroot[rank2] = mint(1) / root[rank2];\r\n    FOR_R(i, rank2) {\r\n     \
    \ root[i] = root[i + 1] * root[i + 1];\r\n      iroot[i] = iroot[i + 1] * iroot[i\
    \ + 1];\r\n    }\r\n    mint prod = 1, iprod = 1;\r\n    for (int i = 0; i <=\
    \ rank2 - 2; i++) {\r\n      rate2[i] = root[i + 2] * prod;\r\n      irate2[i]\
    \ = iroot[i + 2] * iprod;\r\n      prod *= iroot[i + 2];\r\n      iprod *= root[i\
    \ + 2];\r\n    }\r\n    prod = 1, iprod = 1;\r\n    for (int i = 0; i <= rank2\
    \ - 3; i++) {\r\n      rate3[i] = root[i + 3] * prod;\r\n      irate3[i] = iroot[i\
    \ + 3] * iprod;\r\n      prod *= iroot[i + 3];\r\n      iprod *= root[i + 3];\r\
    \n    }\r\n  }\r\n\r\n  int n = int(a.size());\r\n  int h = topbit(n);\r\n  assert(n\
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
    \       len -= 2;\r\n      }\r\n    }\r\n  }\r\n}\r\n#line 1 \"poly/fft.hpp\"\n\
    namespace CFFT {\r\nusing real = double;\r\n\r\nstruct C {\r\n  real x, y;\r\n\
    \r\n  C() : x(0), y(0) {}\r\n\r\n  C(real x, real y) : x(x), y(y) {}\r\n  inline\
    \ C operator+(const C& c) const { return C(x + c.x, y + c.y); }\r\n  inline C\
    \ operator-(const C& c) const { return C(x - c.x, y - c.y); }\r\n  inline C operator*(const\
    \ C& c) const {\r\n    return C(x * c.x - y * c.y, x * c.y + y * c.x);\r\n  }\r\
    \n\r\n  inline C conj() const { return C(x, -y); }\r\n};\r\n\r\nconst real PI\
    \ = acosl(-1);\r\nint base = 1;\r\nvector<C> rts = {{0, 0}, {1, 0}};\r\nvector<int>\
    \ rev = {0, 1};\r\n\r\nvoid ensure_base(int nbase) {\r\n  if (nbase <= base) return;\r\
    \n  rev.resize(1 << nbase);\r\n  rts.resize(1 << nbase);\r\n  for (int i = 0;\
    \ i < (1 << nbase); i++) {\r\n    rev[i] = (rev[i >> 1] >> 1) + ((i & 1) << (nbase\
    \ - 1));\r\n  }\r\n  while (base < nbase) {\r\n    real angle = PI * 2.0 / (1\
    \ << (base + 1));\r\n    for (int i = 1 << (base - 1); i < (1 << base); i++) {\r\
    \n      rts[i << 1] = rts[i];\r\n      real angle_i = angle * (2 * i + 1 - (1\
    \ << base));\r\n      rts[(i << 1) + 1] = C(cos(angle_i), sin(angle_i));\r\n \
    \   }\r\n    ++base;\r\n  }\r\n}\r\n\r\nvoid fft(vector<C>& a, int n) {\r\n  assert((n\
    \ & (n - 1)) == 0);\r\n  int zeros = __builtin_ctz(n);\r\n  ensure_base(zeros);\r\
    \n  int shift = base - zeros;\r\n  for (int i = 0; i < n; i++) {\r\n    if (i\
    \ < (rev[i] >> shift)) { swap(a[i], a[rev[i] >> shift]); }\r\n  }\r\n  for (int\
    \ k = 1; k < n; k <<= 1) {\r\n    for (int i = 0; i < n; i += 2 * k) {\r\n   \
    \   for (int j = 0; j < k; j++) {\r\n        C z = a[i + j + k] * rts[j + k];\r\
    \n        a[i + j + k] = a[i + j] - z;\r\n        a[i + j] = a[i + j] + z;\r\n\
    \      }\r\n    }\r\n  }\r\n}\r\n} // namespace CFFT\n#line 7 \"poly/convolution.hpp\"\
    \n\r\ntemplate <class mint>\r\nvector<mint> convolution_ntt(vector<mint> a, vector<mint>\
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
    \ const long long nttprimes[] = {754974721, 167772161, 469762049};\r\n  using\
    \ mint0 = modint<754974721>;\r\n  using mint1 = modint<167772161>;\r\n  using\
    \ mint2 = modint<469762049>;\r\n  vc<mint0> a0(n), b0(m);\r\n  vc<mint1> a1(n),\
    \ b1(m);\r\n  vc<mint2> a2(n), b2(m);\r\n  FOR(i, n) a0[i] = a[i].val, a1[i] =\
    \ a[i].val, a2[i] = a[i].val;\r\n  FOR(i, m) b0[i] = b[i].val, b1[i] = b[i].val,\
    \ b2[i] = b[i].val;\r\n  auto c0 = convolution_ntt<mint0>(a0, b0);\r\n  auto c1\
    \ = convolution_ntt<mint1>(a1, b1);\r\n  auto c2 = convolution_ntt<mint2>(a2,\
    \ b2);\r\n  static const long long m01 = 1LL * nttprimes[0] * nttprimes[1];\r\n\
    \  static const long long m0_inv_m1 = mint1(nttprimes[0]).inverse().val;\r\n \
    \ static const long long m01_inv_m2 = mint2(m01).inverse().val;\r\n  static const\
    \ int mod = mint::get_mod();\r\n  auto garner = [&](mint0 x0, mint1 x1, mint2\
    \ x2) -> mint {\r\n    int r0 = x0.val, r1 = x1.val, r2 = x2.val;\r\n    int v1\
    \ = (m0_inv_m1 * (r1 + nttprimes[1] - r0)) % nttprimes[1];\r\n    auto v2 = (mint2(r2)\
    \ - r0 - mint2(nttprimes[0]) * v1) * mint2(m01_inv_m2);\r\n    return mint(r0\
    \ + 1LL * nttprimes[0] * v1 + m01 % mod * v2.val);\r\n  };\r\n  vc<mint> c(len(c0));\r\
    \n  FOR(i, len(c)) c[i] = garner(c0[i], c1[i], c2[i]);\r\n  return c;\r\n}\r\n\
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
    \  }\r\n  return ret;\r\n}\r\n\r\nvector<ll> convolution(const vector<ll>& a,\
    \ const vector<ll>& b) {\r\n  int n = len(a), m = len(b);\r\n  if (!n || !m) return\
    \ {};\r\n  if (min(n, m) <= 60) return convolution_naive(a, b);\r\n  ll abs_sum_a\
    \ = 0, abs_sum_b = 0;\r\n  ll LIM = 1e15;\r\n  FOR(i, n) abs_sum_a = min(LIM,\
    \ abs_sum_a + abs(a[i]));\r\n  FOR(i, n) abs_sum_b = min(LIM, abs_sum_b + abs(b[i]));\r\
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
    \  if (min(n, m) <= 50) return convolution_naive(a, b);\r\n    return convolution_ntt(a,\
    \ b);\r\n  }\r\n  if (min(n, m) <= 200) return convolution_naive(a, b);\r\n  return\
    \ convolution_garner(a, b);\r\n}\r\n#line 4 \"poly/fps_inv.hpp\"\n\r\ntemplate\
    \ <typename mint>\r\nvc<mint> fps_inv_sparse(const vc<mint>& f) {\r\n  int N =\
    \ len(f);\r\n  vc<pair<int, mint>> dat;\r\n  FOR(i, 1, N) if (f[i] != mint(0))\
    \ dat.eb(i, f[i]);\r\n  vc<mint> g(N);\r\n  mint g0 = mint(1) / f[0];\r\n  g[0]\
    \ = g0;\r\n  FOR(n, 1, N) {\r\n    mint rhs = 0;\r\n    for (auto&& [k, fk]: dat)\
    \ {\r\n      if (k > n) break;\r\n      rhs -= fk * g[n - k];\r\n    }\r\n   \
    \ g[n] = rhs * g0;\r\n  }\r\n  return g;\r\n}\r\n\r\ntemplate <typename mint>\r\
    \nvc<mint> fps_inv_dense_ntt(const vc<mint>& F) {\r\n  vc<mint> G = {mint(1) /\
    \ F[0]};\r\n  ll N = len(F), n = 1;\r\n  G.reserve(N);\r\n  while (n < N) {\r\n\
    \    vc<mint> f(2 * n), g(2 * n);\r\n    FOR(i, min(N, 2 * n)) f[i] = F[i];\r\n\
    \    FOR(i, n) g[i] = G[i];\r\n    ntt(f, false), ntt(g, false);\r\n    FOR(i,\
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
    \ (n <= t ? fps_inv_sparse<mint>(f) : fps_inv_dense<mint>(f));\r\n}\r\n#line 2\
    \ \"poly/middle_product.hpp\"\n\n#line 4 \"poly/middle_product.hpp\"\n\n// n,\
    \ m \u6B21\u591A\u9805\u5F0F (n>=m) a, b \u2192 n-m \u6B21\u591A\u9805\u5F0F c\n\
    // c[i] = sum_j b[j]a[i+j]\ntemplate <typename mint>\nvc<mint> middle_product(vc<mint>&\
    \ a, vc<mint>& b) {\n  assert(len(a) >= len(b));\n  if (b.empty()) return vc<mint>(len(a)\
    \ - len(b) + 1);\n  if (min(len(b), len(a) - len(b) + 1) <= 60) {\n    return\
    \ middle_product_naive(a, b);\n  }\n  if constexpr (mint::ntt_info().fi == -1)\
    \ {\n    return middle_product_garner(a, b);\n  } else {\n    int n = 1 << __lg(2\
    \ * len(a) - 1);\n    vc<mint> fa(n), fb(n);\n    copy(a.begin(), a.end(), fa.begin());\n\
    \    copy(b.rbegin(), b.rend(), fb.begin());\n    ntt(fa, 0), ntt(fb, 0);\n  \
    \  FOR(i, n) fa[i] *= fb[i];\n    ntt(fa, 1);\n    fa.resize(len(a));\n    fa.erase(fa.begin(),\
    \ fa.begin() + len(b) - 1);\n    return fa;\n  }\n}\n\ntemplate <typename mint>\n\
    vc<mint> middle_product_garner(vc<mint>& a, vc<mint> b) {\n  int n = len(a), m\
    \ = len(b);\n  if (!n || !m) return {};\n  static const long long nttprimes[]\
    \ = {754974721, 167772161, 469762049};\n  using mint0 = modint<754974721>;\n \
    \ using mint1 = modint<167772161>;\n  using mint2 = modint<469762049>;\n  vc<mint0>\
    \ a0(n), b0(m);\n  vc<mint1> a1(n), b1(m);\n  vc<mint2> a2(n), b2(m);\n  FOR(i,\
    \ n) a0[i] = a[i].val, a1[i] = a[i].val, a2[i] = a[i].val;\n  FOR(i, m) b0[i]\
    \ = b[i].val, b1[i] = b[i].val, b2[i] = b[i].val;\n  auto c0 = middle_product<mint0>(a0,\
    \ b0);\n  auto c1 = middle_product<mint1>(a1, b1);\n  auto c2 = middle_product<mint2>(a2,\
    \ b2);\n  static const long long m01 = 1LL * nttprimes[0] * nttprimes[1];\n  static\
    \ const long long m0_inv_m1 = mint1(nttprimes[0]).inverse().val;\n  static const\
    \ long long m01_inv_m2 = mint2(m01).inverse().val;\n  static const int mod = mint::get_mod();\n\
    \  auto garner = [&](mint0 x0, mint1 x1, mint2 x2) -> mint {\n    int r0 = x0.val,\
    \ r1 = x1.val, r2 = x2.val;\n    int v1 = (m0_inv_m1 * (r1 + nttprimes[1] - r0))\
    \ % nttprimes[1];\n    auto v2 = (mint2(r2) - r0 - mint2(nttprimes[0]) * v1) *\
    \ mint2(m01_inv_m2);\n    return mint(r0 + 1LL * nttprimes[0] * v1 + m01 % mod\
    \ * v2.val);\n  };\n  vc<mint> c(len(c0));\n  FOR(i, len(c)) c[i] = garner(c0[i],\
    \ c1[i], c2[i]);\n  return c;\n}\n\ntemplate <typename mint>\nvc<mint> middle_product_naive(vc<mint>&\
    \ a, vc<mint>& b) {\n  vc<mint> res(len(a) - len(b) + 1);\n  FOR(i, len(res))\
    \ FOR(j, len(b)) res[i] += b[j] * a[i + j];\n  return res;\n}\n#line 5 \"poly/multipoint.hpp\"\
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
    \n    return t[1];\r\n  }\r\n};\r\n\r\ntemplate <typename mint>\r\nvc<mint> multipoint_eval(vc<mint>&\
    \ f, vc<mint>& x) {\r\n  if (x.empty()) return {};\r\n  SubproductTree<mint> F(x);\r\
    \n  return F.evaluation(f);\r\n}\r\n\r\ntemplate <typename mint>\r\nvc<mint> multipoint_interpolate(vc<mint>&\
    \ x, vc<mint>& y) {\r\n  if (x.empty()) return {};\r\n  SubproductTree<mint> F(x);\r\
    \n  return F.interpolation(y);\r\n}\r\n\r\n// calculate f(ar^k) for 0 <= k < m\r\
    \ntemplate <typename mint>\r\nvc<mint> multipoint_eval_on_geom_seq(vc<mint> f,\
    \ mint a, mint r, int m) {\r\n  const int n = len(f);\r\n  if (m == 0) return\
    \ {};\r\n\r\n  auto eval = [&](mint x) -> mint {\r\n    mint fx = 0;\r\n    mint\
    \ pow = 1;\r\n    FOR(i, n) fx += f[i] * pow, pow *= x;\r\n    return fx;\r\n\
    \  };\r\n\r\n  if (r == mint(0)) {\r\n    vc<mint> res(m);\r\n    FOR(i, 1, m)\
    \ res[i] = f[0];\r\n    res[0] = eval(a);\r\n    return res;\r\n  }\r\n  if (n\
    \ < 60 || m < 60) {\r\n    vc<mint> res(m);\r\n    FOR(i, m) res[i] = eval(a),\
    \ a *= r;\r\n    return res;\r\n  }\r\n  assert(r != mint(0));\r\n  // a == 1\
    \ \u306B\u5E30\u7740\r\n  mint pow_a = 1;\r\n  FOR(i, n) f[i] *= pow_a, pow_a\
    \ *= a;\r\n\r\n  auto calc = [&](mint r, int m) -> vc<mint> {\r\n    // r^{t_i}\
    \ \u306E\u8A08\u7B97\r\n    vc<mint> res(m);\r\n    mint pow = 1;\r\n    res[0]\
    \ = 1;\r\n    FOR(i, m - 1) {\r\n      res[i + 1] = res[i] * pow;\r\n      pow\
    \ *= r;\r\n    }\r\n    return res;\r\n  };\r\n\r\n  vc<mint> A = calc(r, n +\
    \ m - 1), B = calc(r.inverse(), max(n, m));\r\n  FOR(i, n) f[i] *= B[i];\r\n \
    \ f = middle_product(A, f);\r\n  FOR(i, m) f[i] *= B[i];\r\n  return f;\r\n}\n\
    #line 2 \"mod/primitive_root.hpp\"\n\r\n#line 2 \"nt/primetest.hpp\"\nstruct m64\
    \ {\r\n  using i64 = int64_t;\r\n  using u64 = uint64_t;\r\n  using u128 = __uint128_t;\r\
    \n\r\n  inline static u64 m, r, n2; // r * m = -1 (mod 1<<64), n2 = 1<<128 (mod\
    \ m)\r\n  static void set_mod(u64 m) {\r\n    assert((m & 1) == 1);\r\n    m64::m\
    \ = m;\r\n    n2 = -u128(m) % m;\r\n    r = m;\r\n    FOR(_, 5) r *= 2 - m * r;\r\
    \n    r = -r;\r\n    assert(r * m == -1ull);\r\n  }\r\n  static u64 reduce(u128\
    \ b) { return (b + u128(u64(b) * r) * m) >> 64; }\r\n\r\n  u64 x;\r\n  m64() :\
    \ x(0) {}\r\n  m64(u64 x) : x(reduce(u128(x) * n2)){};\r\n  u64 val() const {\r\
    \n    u64 y = reduce(x);\r\n    return y >= m ? y - m : y;\r\n  }\r\n  m64 &operator+=(m64\
    \ y) {\r\n    x += y.x - (m << 1);\r\n    x = (i64(x) < 0 ? x + (m << 1) : x);\r\
    \n    return *this;\r\n  }\r\n  m64 &operator-=(m64 y) {\r\n    x -= y.x;\r\n\
    \    x = (i64(x) < 0 ? x + (m << 1) : x);\r\n    return *this;\r\n  }\r\n  m64\
    \ &operator*=(m64 y) {\r\n    x = reduce(u128(x) * y.x);\r\n    return *this;\r\
    \n  }\r\n  m64 operator+(m64 y) const { return m64(*this) += y; }\r\n  m64 operator-(m64\
    \ y) const { return m64(*this) -= y; }\r\n  m64 operator*(m64 y) const { return\
    \ m64(*this) *= y; }\r\n  bool operator==(m64 y) const {\r\n    return (x >= m\
    \ ? x - m : x) == (y.x >= m ? y.x - m : y.x);\r\n  }\r\n  bool operator!=(m64\
    \ y) const { return not operator==(y); }\r\n  m64 pow(u64 n) const {\r\n    m64\
    \ y = 1, z = *this;\r\n    for (; n; n >>= 1, z *= z)\r\n      if (n & 1) y *=\
    \ z;\r\n    return y;\r\n  }\r\n};\r\n\r\nbool primetest(const uint64_t x) {\r\
    \n  using u64 = uint64_t;\r\n  if (x == 2 or x == 3 or x == 5 or x == 7) return\
    \ true;\r\n  if (x % 2 == 0 or x % 3 == 0 or x % 5 == 0 or x % 7 == 0) return\
    \ false;\r\n  if (x < 121) return x > 1;\r\n  const u64 d = (x - 1) >> __builtin_ctzll(x\
    \ - 1);\r\n  m64::set_mod(x);\r\n  const m64 one(1), minus_one(x - 1);\r\n  auto\
    \ ok = [&](u64 a) {\r\n    auto y = m64(a).pow(d);\r\n    u64 t = d;\r\n    while\
    \ (y != one and y != minus_one and t != x - 1) y *= y, t <<= 1;\r\n    if (y !=\
    \ minus_one and t % 2 == 0) return false;\r\n    return true;\r\n  };\r\n  if\
    \ (x < (1ull << 32)) {\r\n    for (u64 a: {2, 7, 61})\r\n      if (not ok(a))\
    \ return false;\r\n  } else {\r\n    for (u64 a: {2, 325, 9375, 28178, 450775,\
    \ 9780504, 1795265022}) {\r\n      if (x <= a) return true;\r\n      if (not ok(a))\
    \ return false;\r\n    }\r\n  }\r\n  return true;\r\n}\n#line 3 \"nt/factor.hpp\"\
    \n\nmt19937_64 rng_mt{random_device{}()};\nll rnd(ll n) { return uniform_int_distribution<ll>(0,\
    \ n - 1)(rng_mt); }\n\nll rho(ll n, ll c) {\n  m64::set_mod(n);\n  assert(n >\
    \ 1);\n  const m64 cc(c);\n  auto f = [&](m64 x) { return x * x + cc; };\n  m64\
    \ x = 1, y = 2, z = 1, q = 1;\n  ll g = 1;\n  const ll m = 1LL << (__lg(n) / 5);\
    \ // ?\n  for (ll r = 1; g == 1; r <<= 1) {\n    x = y;\n    FOR(_, r) y = f(y);\n\
    \    for (ll k = 0; k < r and g == 1; k += m) {\n      z = y;\n      FOR(_, min(m,\
    \ r - k)) y = f(y), q *= x - y;\n      g = gcd(q.val(), n);\n    }\n  }\n  if\
    \ (g == n) do {\n      z = f(z);\n      g = gcd((x - z).val(), n);\n    } while\
    \ (g == 1);\n  return g;\n}\n\nll find_prime_factor(ll n) {\n  assert(n > 1);\n\
    \  if (primetest(n)) return n;\n  FOR(_, 100) {\n    ll m = rho(n, rnd(n));\n\
    \    if (primetest(m)) return m;\n    n = m;\n  }\n  cerr << \"failed\" << endl;\n\
    \  assert(false);\n  return -1;\n}\n\n// \u30BD\u30FC\u30C8\u3057\u3066\u304F\u308C\
    \u308B\nvc<pair<ll, int>> factor(ll n) {\n  assert(n >= 1);\n  vc<pair<ll, int>>\
    \ pf;\n  FOR3(p, 2, 100) {\n    if (p * p > n) break;\n    if (n % p == 0) {\n\
    \      ll e = 0;\n      do { n /= p, e += 1; } while (n % p == 0);\n      pf.eb(p,\
    \ e);\n    }\n  }\n  while (n > 1) {\n    ll p = find_prime_factor(n);\n    ll\
    \ e = 0;\n    do { n /= p, e += 1; } while (n % p == 0);\n    pf.eb(p, e);\n \
    \ }\n  sort(all(pf));\n  return pf;\n}\n\nvc<pair<ll, int>> factor_by_lpf(ll n,\
    \ vc<int>& lpf) {\n  vc<pair<ll, int>> res;\n  while (n > 1) {\n    int p = lpf[n];\n\
    \    int e = 0;\n    while (n % p == 0) {\n      n /= p;\n      ++e;\n    }\n\
    \    res.eb(p, e);\n  }\n  return res;\n}\n#line 2 \"mod/barrett.hpp\"\n\n// https://github.com/atcoder/ac-library/blob/master/atcoder/internal_math.hpp\n\
    struct Barrett {\n  u32 m;\n  u64 im;\n  explicit Barrett(u32 m = 1) : m(m), im(u64(-1)\
    \ / m + 1) {}\n  u32 umod() const { return m; }\n  u32 modulo(u64 z) {\n    if\
    \ (m == 1) return z;\n    u64 x = (u64)(((unsigned __int128)(z)*im) >> 64);\n\
    \    u64 y = x * m;\n    return (z - y + (z < y ? m : 0));\n  }\n  u64 floor(u64\
    \ z) {\n    if (m == 1) return z;\n    u64 x = (u64)(((unsigned __int128)(z)*im)\
    \ >> 64);\n    u64 y = x * m;\n    return (z < y ? x - 1 : x);\n  }\n  pair<u64,\
    \ u32> divmod(u64 z) {\n    if (m == 1) return {z, 0};\n    u64 x = (u64)(((unsigned\
    \ __int128)(z)*im) >> 64);\n    u64 y = x * m;\n    if (z < y) return {x - 1,\
    \ z - y + m};\n    return {x, z - y};\n  }\n  u32 mul(u32 a, u32 b) { return modulo(u64(a)\
    \ * b); }\n};\n#line 3 \"mod/mod_pow.hpp\"\n\r\n// int\r\nll mod_pow(ll a, ll\
    \ n, int mod) {\r\n  a %= mod;\r\n  Barrett bt(mod);\r\n  ll p = a;\r\n  ll v\
    \ = 1;\r\n  while (n) {\r\n    if (n & 1) v = bt.mul(v, p);\r\n    p = bt.mul(p,\
    \ p);\r\n    n >>= 1;\r\n  }\r\n  return v;\r\n}\r\n\r\nll mod_pow_long(ll a,\
    \ ll n, ll mod) {\r\n  a %= mod;\r\n  ll p = a;\r\n  ll v = 1;\r\n  while (n)\
    \ {\r\n    if (n & 1) v = i128(v) * p % mod;\r\n    p = i128(p) * p % mod;\r\n\
    \    n >>= 1;\r\n  }\r\n  return v;\r\n}\r\n#line 2 \"random/base.hpp\"\n\nu64\
    \ RNG_64() {\n  static uint64_t x_\n      = uint64_t(chrono::duration_cast<chrono::nanoseconds>(\n\
    \                     chrono::high_resolution_clock::now().time_since_epoch())\n\
    \                     .count())\n        * 10150724397891781847ULL;\n  x_ ^= x_\
    \ << 7;\n  return x_ ^= x_ >> 9;\n}\n\nu64 RNG(u64 lim) { return RNG_64() % lim;\
    \ }\n\nll RNG(ll l, ll r) { return l + RNG_64() % (r - l); }\n#line 6 \"mod/primitive_root.hpp\"\
    \n\r\n// int\r\nint primitive_root(int p) {\r\n  auto pf = factor(p - 1);\r\n\
    \  auto is_ok = [&](int g) -> bool {\r\n    for (auto&& [q, e]: pf)\r\n      if\
    \ (mod_pow(g, (p - 1) / q, p) == 1) return false;\r\n    return true;\r\n  };\r\
    \n  while (1) {\r\n    int x = RNG(1, p);\r\n    if (is_ok(x)) return x;\r\n \
    \ }\r\n  return -1;\r\n}\r\n\r\nll primitive_root_long(ll p) {\r\n  auto pf =\
    \ factor(p - 1);\r\n  auto is_ok = [&](ll g) -> bool {\r\n    for (auto&& [q,\
    \ e]: pf)\r\n      if (mod_pow_long(g, (p - 1) / q, p) == 1) return false;\r\n\
    \    return true;\r\n  };\r\n  while (1) {\r\n    ll x = RNG(1, p);\r\n    if\
    \ (is_ok(x)) return x;\r\n  }\r\n  return -1;\r\n}\r\n#line 3 \"poly/multivar_convolution_cyclic.hpp\"\
    \n\n/*\nexample : ns = (2, 3)\n[a0, a1, a2, a3, a4, a5] = [a(0,0), a(1,0), a(0,1),\
    \ a(1,1), a(0,2), a(1,2)]\n[b0, b1, b2, b3, b4, b5] = [b(0,0), b(1,0), b(0,1),\
    \ b(1,1), b(0,2), b(1,2)]\n*/\ntemplate <typename mint>\nvc<mint> multivar_convolution_cyclic(vc<int>\
    \ ns, vc<mint> f, vc<mint>& g) {\n  int p = mint::get_mod();\n  for (auto&& n:\
    \ ns) assert((p - 1) % n == 0);\n  mint r = primitive_root(p);\n  mint ir = r.inverse();\n\
    \n  int K = len(ns);\n  int N = 1;\n  for (auto&& n: ns) N *= n;\n  assert(len(f)\
    \ == N);\n  assert(len(g) == N);\n  vc<mint> root(K), iroot(K);\n\n  FOR(k, K)\
    \ { root[k] = r.pow((p - 1) / ns[k]); }\n  FOR(k, K) { iroot[k] = ir.pow((p -\
    \ 1) / ns[k]); }\n\n  int step = 1;\n  FOR(k, K) {\n    int n = ns[k];\n    FOR(i,\
    \ N) if (i % (step * n) < step) {\n      vc<mint> a(n), b(n);\n      FOR(j, n)\
    \ {\n        a[j] = f[i + step * j];\n        b[j] = g[i + step * j];\n      }\n\
    \      a = multipoint_eval_on_geom_seq(a, mint(1), root[k], n);\n      b = multipoint_eval_on_geom_seq(b,\
    \ mint(1), root[k], n);\n      FOR(j, n) {\n        f[i + step * j] = a[j];\n\
    \        g[i + step * j] = b[j];\n      }\n    }\n    step *= n;\n  }\n\n  FOR(i,\
    \ N) f[i] *= g[i];\n\n  step = 1;\n  FOR(k, K) {\n    int n = ns[k];\n    FOR(i,\
    \ N) if (i % (step * n) < step) {\n      vc<mint> a(n);\n      FOR(j, n) { a[j]\
    \ = f[i + step * j]; }\n      a = multipoint_eval_on_geom_seq(a, mint(1), iroot[k],\
    \ n);\n      FOR(j, n) { f[i + step * j] = a[j]; }\n    }\n    step *= n;\n  }\n\
    \n  mint cf = mint(N).inverse();\n  for (auto&& x: f) x *= cf;\n  return f;\n\
    }\n\ntemplate <typename mint>\nvc<vc<mint>> multivar_convolution_cyclic_2d(vc<vc<mint>>&\
    \ f, vc<vc<mint>>& g) {\n  int H = len(f);\n  int W = len(f[0]);\n  assert(len(g)\
    \ == H);\n  assert(len(g[0]) == W);\n  vc<mint> F(H * W), G(H * W);\n  FOR(x,\
    \ H) FOR(y, W) F[x + H * y] = f[x][y];\n  FOR(x, H) FOR(y, W) G[x + H * y] = g[x][y];\n\
    \  F = multivar_convolution_cyclic(vc<int>({H, W}), F, G);\n  vv(mint, h, H, W);\n\
    \  FOR(x, H) FOR(y, W) h[x][y] = F[x + H * y];\n  return h;\n}\n"
  code: "#include \"poly/multipoint.hpp\"\n#include \"mod/primitive_root.hpp\"\n\n\
    /*\nexample : ns = (2, 3)\n[a0, a1, a2, a3, a4, a5] = [a(0,0), a(1,0), a(0,1),\
    \ a(1,1), a(0,2), a(1,2)]\n[b0, b1, b2, b3, b4, b5] = [b(0,0), b(1,0), b(0,1),\
    \ b(1,1), b(0,2), b(1,2)]\n*/\ntemplate <typename mint>\nvc<mint> multivar_convolution_cyclic(vc<int>\
    \ ns, vc<mint> f, vc<mint>& g) {\n  int p = mint::get_mod();\n  for (auto&& n:\
    \ ns) assert((p - 1) % n == 0);\n  mint r = primitive_root(p);\n  mint ir = r.inverse();\n\
    \n  int K = len(ns);\n  int N = 1;\n  for (auto&& n: ns) N *= n;\n  assert(len(f)\
    \ == N);\n  assert(len(g) == N);\n  vc<mint> root(K), iroot(K);\n\n  FOR(k, K)\
    \ { root[k] = r.pow((p - 1) / ns[k]); }\n  FOR(k, K) { iroot[k] = ir.pow((p -\
    \ 1) / ns[k]); }\n\n  int step = 1;\n  FOR(k, K) {\n    int n = ns[k];\n    FOR(i,\
    \ N) if (i % (step * n) < step) {\n      vc<mint> a(n), b(n);\n      FOR(j, n)\
    \ {\n        a[j] = f[i + step * j];\n        b[j] = g[i + step * j];\n      }\n\
    \      a = multipoint_eval_on_geom_seq(a, mint(1), root[k], n);\n      b = multipoint_eval_on_geom_seq(b,\
    \ mint(1), root[k], n);\n      FOR(j, n) {\n        f[i + step * j] = a[j];\n\
    \        g[i + step * j] = b[j];\n      }\n    }\n    step *= n;\n  }\n\n  FOR(i,\
    \ N) f[i] *= g[i];\n\n  step = 1;\n  FOR(k, K) {\n    int n = ns[k];\n    FOR(i,\
    \ N) if (i % (step * n) < step) {\n      vc<mint> a(n);\n      FOR(j, n) { a[j]\
    \ = f[i + step * j]; }\n      a = multipoint_eval_on_geom_seq(a, mint(1), iroot[k],\
    \ n);\n      FOR(j, n) { f[i + step * j] = a[j]; }\n    }\n    step *= n;\n  }\n\
    \n  mint cf = mint(N).inverse();\n  for (auto&& x: f) x *= cf;\n  return f;\n\
    }\n\ntemplate <typename mint>\nvc<vc<mint>> multivar_convolution_cyclic_2d(vc<vc<mint>>&\
    \ f, vc<vc<mint>>& g) {\n  int H = len(f);\n  int W = len(f[0]);\n  assert(len(g)\
    \ == H);\n  assert(len(g[0]) == W);\n  vc<mint> F(H * W), G(H * W);\n  FOR(x,\
    \ H) FOR(y, W) F[x + H * y] = f[x][y];\n  FOR(x, H) FOR(y, W) G[x + H * y] = g[x][y];\n\
    \  F = multivar_convolution_cyclic(vc<int>({H, W}), F, G);\n  vv(mint, h, H, W);\n\
    \  FOR(x, H) FOR(y, W) h[x][y] = F[x + H * y];\n  return h;\n}\n"
  dependsOn:
  - poly/multipoint.hpp
  - poly/fps_inv.hpp
  - poly/count_terms.hpp
  - poly/convolution.hpp
  - mod/modint.hpp
  - mod/modint_common.hpp
  - mod/mod_inv.hpp
  - poly/convolution_naive.hpp
  - poly/ntt.hpp
  - poly/fft.hpp
  - poly/middle_product.hpp
  - mod/primitive_root.hpp
  - nt/factor.hpp
  - nt/primetest.hpp
  - mod/mod_pow.hpp
  - mod/barrett.hpp
  - random/base.hpp
  isVerificationFile: false
  path: poly/multivar_convolution_cyclic.hpp
  requiredBy: []
  timestamp: '2023-04-27 21:29:47+09:00'
  verificationStatus: LIBRARY_ALL_WA
  verifiedWith:
  - test/library_checker/math/multivariate_convolution_cyclic.test.cpp
documentation_of: poly/multivar_convolution_cyclic.hpp
layout: document
redirect_from:
- /library/poly/multivar_convolution_cyclic.hpp
- /library/poly/multivar_convolution_cyclic.hpp.html
title: poly/multivar_convolution_cyclic.hpp
---
