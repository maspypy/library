---
data:
  _extendedDependsOn:
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
    path: poly/convolution_naive.hpp
    title: poly/convolution_naive.hpp
  - icon: ':question:'
    path: poly/fft.hpp
    title: poly/fft.hpp
  - icon: ':question:'
    path: poly/ntt.hpp
    title: poly/ntt.hpp
  - icon: ':question:'
    path: poly/online/online_convolution.hpp
    title: poly/online/online_convolution.hpp
  _extendedRequiredBy:
  - icon: ':heavy_check_mark:'
    path: poly/online/online_inv.hpp
    title: poly/online/online_inv.hpp
  - icon: ':heavy_check_mark:'
    path: poly/online/online_log.hpp
    title: poly/online/online_log.hpp
  - icon: ':heavy_check_mark:'
    path: poly/online/online_pow.hpp
    title: poly/online/online_pow.hpp
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/mytest/online_division.test.cpp
    title: test/mytest/online_division.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/mytest/online_inv.test.cpp
    title: test/mytest/online_inv.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/mytest/online_log.test.cpp
    title: test/mytest/online_log.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/mytest/online_pow.test.cpp
    title: test/mytest/online_pow.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 2 \"mod/modint_common.hpp\"\n\nstruct has_mod_impl {\n  template\
    \ <class T>\n  static auto check(T &&x) -> decltype(x.get_mod(), std::true_type{});\n\
    \  template <class T>\n  static auto check(...) -> std::false_type;\n};\n\ntemplate\
    \ <class T>\nclass has_mod : public decltype(has_mod_impl::check<T>(std::declval<T>()))\
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
    \ {20, 2789};\n    return {-1, -1};\n  }\n};\n\nusing modint107 = modint<1000000007>;\n\
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
    \nvoid ntt(vector<mint>& a, bool inverse) {\r\n  static constexpr int rank2 =\
    \ mint::ntt_info().fi;\r\n  static constexpr int mod = mint::get_mod();\r\n  static_assert(rank2\
    \ != -1);\r\n  static array<mint, rank2 + 1> root;\r\n  static array<mint, rank2\
    \ + 1> iroot;\r\n  static array<mint, max(0, rank2 - 1)> rate2, irate2;\r\n  static\
    \ array<mint, max(0, rank2 - 2)> rate3, irate3;\r\n  static bool prepared = 0;\r\
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
    \ b) {\r\n  int n = int(a.size()), m = int(b.size());\r\n  int sz = 1;\r\n  while\
    \ (sz < n + m - 1) sz *= 2;\r\n\r\n  // sz = 2^k \u306E\u3068\u304D\u306E\u9AD8\
    \u901F\u5316\u3002\u5206\u5272\u7D71\u6CBB\u7684\u306A\u3084\u3064\u3067\u640D\
    \u3057\u307E\u304F\u308B\u306E\u3067\u3002\r\n  if ((n + m - 3) <= sz / 2) {\r\
    \n    auto a_last = a.back(), b_last = b.back();\r\n    a.pop_back(), b.pop_back();\r\
    \n    auto c = convolution(a, b);\r\n    c.resize(n + m - 1);\r\n    c[n + m -\
    \ 2] = a_last * b_last;\r\n    FOR(i, len(a)) c[i + len(b)] += a[i] * b_last;\r\
    \n    FOR(i, len(b)) c[i + len(a)] += b[i] * a_last;\r\n    return c;\r\n  }\r\
    \n\r\n  a.resize(sz), b.resize(sz);\r\n  bool same = a == b;\r\n  ntt(a, 0);\r\
    \n  if (same) {\r\n    b = a;\r\n  } else {\r\n    ntt(b, 0);\r\n  }\r\n  FOR(i,\
    \ sz) a[i] *= b[i];\r\n  ntt(a, 1);\r\n  a.resize(n + m - 1);\r\n  return a;\r\
    \n}\r\n\r\ntemplate <typename mint>\r\nvector<mint> convolution_garner(const vector<mint>&\
    \ a, const vector<mint>& b) {\r\n  int n = len(a), m = len(b);\r\n  if (!n ||\
    \ !m) return {};\r\n  static const long long nttprimes[] = {754974721, 167772161,\
    \ 469762049};\r\n  using mint0 = modint<754974721>;\r\n  using mint1 = modint<167772161>;\r\
    \n  using mint2 = modint<469762049>;\r\n  vc<mint0> a0(n), b0(m);\r\n  vc<mint1>\
    \ a1(n), b1(m);\r\n  vc<mint2> a2(n), b2(m);\r\n  FOR(i, n) a0[i] = a[i].val,\
    \ a1[i] = a[i].val, a2[i] = a[i].val;\r\n  FOR(i, m) b0[i] = b[i].val, b1[i] =\
    \ b[i].val, b2[i] = b[i].val;\r\n  auto c0 = convolution_ntt<mint0>(a0, b0);\r\
    \n  auto c1 = convolution_ntt<mint1>(a1, b1);\r\n  auto c2 = convolution_ntt<mint2>(a2,\
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
    \nenable_if_t<is_same<mint, modint998>::value, vc<mint>> convolution(\r\n    const\
    \ vc<mint>& a, const vc<mint>& b) {\r\n  int n = len(a), m = len(b);\r\n  if (!n\
    \ || !m) return {};\r\n  if (min(n, m) <= 60) return convolution_naive(a, b);\r\
    \n  return convolution_ntt(a, b);\r\n}\r\n\r\ntemplate <typename mint>\r\nenable_if_t<!is_same<mint,\
    \ modint998>::value, vc<mint>> convolution(\r\n    const vc<mint>& a, const vc<mint>&\
    \ b) {\r\n  int n = len(a), m = len(b);\r\n  if (!n || !m) return {};\r\n  if\
    \ (min(n, m) <= 60) return convolution_naive(a, b);\r\n  return convolution_garner(a,\
    \ b);\r\n}\r\n#line 3 \"poly/online/online_convolution.hpp\"\n\n/*\nquery(i)\uFF1A\
    a[i], b[i] \u3092\u4E0E\u3048\u3066 ab[i] \u3092\u5F97\u308B\u3002\n2^{17}\uFF1A\
    176ms\n2^{18}\uFF1A370ms\n2^{19}\uFF1A800ms\n2^{20}\uFF1A1680ms\n*/\ntemplate\
    \ <typename mint>\nstruct Online_Convolution {\n  const int thresh = 3;\n  vc<mint>\
    \ f, g, h;\n  vc<vc<mint>> fft_f;\n  vc<vc<mint>> fft_g;\n\n  pair<vc<mint>, vc<mint>>\
    \ calc_fft(int k) {\n    // \u73FE\u6642\u70B9\u3067\u306E\u672B\u5C3E 2^k \u9805\
    \u306B\u5BFE\u3059\u308B fft \u30C7\u30FC\u30BF\u3092\u5F97\u308B\n    ll L =\
    \ 1 << k;\n    if (k <= thresh) {\n      vc<mint> f_suff(f.end() - L, f.end());\n\
    \      vc<mint> g_suff(g.end() - L, g.end());\n      return {f_suff, g_suff};\n\
    \    }\n    vc<mint> f_suff(2 * L), g_suff(2 * L);\n    FOR(i, 1 << k) { f_suff[i]\
    \ = f[len(f) - L + i]; }\n    FOR(i, 1 << k) { g_suff[i] = g[len(g) - L + i];\
    \ }\n    if (k <= thresh) return {f_suff, g_suff};\n    ntt(f_suff, 0);\n    ntt(g_suff,\
    \ 0);\n    return {f_suff, g_suff};\n  }\n\n  void calc(int k) {\n    // suffix\
    \ \u306E \u9577\u3055 2^k \u307E\u308F\u308A\u306E\u7573\u307F\u8FBC\u307F\u3092\
    \ h \u306B\u52A0\u7B97\u3059\u308B\n    auto [Ff, Fg] = calc_fft(k);\n    vc<mint>\
    \ Fh(1 << (k + 1));\n    bool square = k >= len(fft_f);\n    if (square) {\n \
    \     // \u9577\u3055 2^k \u306E\u306F\u3058\u3081\u3066\u306E\u584A\u3002\n \
    \     fft_f.eb(Ff);\n      fft_g.eb(Fg);\n    }\n\n    if (k > thresh && square)\
    \ {\n      FOR(i, 1 << (k + 1)) Fh[i] += Ff[i] * Fg[i];\n      ntt(Fh, 1);\n \
    \   }\n    elif (k > thresh && !square) {\n      FOR(i, 1 << (k + 1)) {\n    \
    \    Fh[i] += Ff[i] * fft_g[k][i];\n        Fh[i] += Fg[i] * fft_f[k][i];\n  \
    \    }\n      ntt(Fh, 1);\n    }\n    elif (k <= thresh && square) {\n      FOR(i,\
    \ 1 << k) FOR(j, 1 << k) Fh[i + j] += Ff[i] * Fg[j];\n    }\n    elif (k <= thresh\
    \ && !square) {\n      FOR(i, 1 << k) FOR(j, 1 << k) Fh[i + j] += Ff[i] * fft_g[k][j];\n\
    \      FOR(i, 1 << k) FOR(j, 1 << k) Fh[i + j] += Fg[i] * fft_f[k][j];\n    }\n\
    \    // \u9069\u5207\u306A\u5834\u6240\u306B\u8DB3\u3057\u3053\u3080\n    int\
    \ off = len(f) - 1;\n    FOR(i, len(Fh) - 1) {\n      if (len(h) <= off + i) h.eb(0);\n\
    \      h[off + i] += Fh[i];\n    }\n  }\n\n  mint query(int i, mint f_i, mint\
    \ g_i) {\n    assert(i == len(f));\n    f.eb(f_i);\n    g.eb(g_i);\n    FOR(k,\
    \ 30) {\n      // \u9577\u3055 2^k \u306E\u90E8\u5206\u3092\u51E6\u7406\u3059\u308B\
    \u304B\u3069\u3046\u304B\uFF1F\n      // i+2 \u304C 2^k \u306E\u500D\u6570\u304B\
    \u3064 i+2 >= 2^{k+1}\n      ll L = 1 << k;\n      bool bl = ((i + 2) % L == 0)\
    \ && (i + 2 >= 2 * L);\n      if (!bl) continue;\n      calc(k);\n    }\n    return\
    \ h[i];\n  }\n};\n#line 3 \"poly/online/online_division.hpp\"\n\n// query(i)\uFF1A\
    a[i], b[i] \u3092\u4E0E\u3048\u3066 (f/g)[i] \u3092\u5F97\u308B\u3002\n// g[0]\
    \ == 1 \u3092\u4EEE\u5B9A\u3059\u308B\ntemplate <typename mint>\nstruct Online_Division\
    \ {\n  vc<mint> f, g, F;\n  Online_Convolution<mint> X;\n\n  mint query(int i,\
    \ mint f_i, mint g_i) {\n    assert(i == len(f));\n    f.eb(f_i);\n    g.eb(g_i);\n\
    \    if (i == 0) {\n      assert(g_i == mint(1));\n      F.eb(f_i);\n      return\
    \ F[0];\n    }\n    F.eb(f[i] - X.query(i - 1, F[i - 1], g[i]));\n    return F[i];\n\
    \  }\n};\n"
  code: "#pragma once\n#include \"poly/online/online_convolution.hpp\"\n\n// query(i)\uFF1A\
    a[i], b[i] \u3092\u4E0E\u3048\u3066 (f/g)[i] \u3092\u5F97\u308B\u3002\n// g[0]\
    \ == 1 \u3092\u4EEE\u5B9A\u3059\u308B\ntemplate <typename mint>\nstruct Online_Division\
    \ {\n  vc<mint> f, g, F;\n  Online_Convolution<mint> X;\n\n  mint query(int i,\
    \ mint f_i, mint g_i) {\n    assert(i == len(f));\n    f.eb(f_i);\n    g.eb(g_i);\n\
    \    if (i == 0) {\n      assert(g_i == mint(1));\n      F.eb(f_i);\n      return\
    \ F[0];\n    }\n    F.eb(f[i] - X.query(i - 1, F[i - 1], g[i]));\n    return F[i];\n\
    \  }\n};"
  dependsOn:
  - poly/online/online_convolution.hpp
  - poly/convolution.hpp
  - mod/modint.hpp
  - mod/modint_common.hpp
  - mod/mod_inv.hpp
  - poly/convolution_naive.hpp
  - poly/ntt.hpp
  - poly/fft.hpp
  isVerificationFile: false
  path: poly/online/online_division.hpp
  requiredBy:
  - poly/online/online_pow.hpp
  - poly/online/online_log.hpp
  - poly/online/online_inv.hpp
  timestamp: '2023-03-12 10:53:54+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/mytest/online_division.test.cpp
  - test/mytest/online_inv.test.cpp
  - test/mytest/online_log.test.cpp
  - test/mytest/online_pow.test.cpp
documentation_of: poly/online/online_division.hpp
layout: document
redirect_from:
- /library/poly/online/online_division.hpp
- /library/poly/online/online_division.hpp.html
title: poly/online/online_division.hpp
---
