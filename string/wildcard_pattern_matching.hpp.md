---
data:
  _extendedDependsOn:
  - icon: ':question:'
    path: mod/modint.hpp
    title: mod/modint.hpp
  - icon: ':question:'
    path: mod/modint_common.hpp
    title: mod/modint_common.hpp
  - icon: ':question:'
    path: poly/middle_product.hpp
    title: poly/middle_product.hpp
  - icon: ':question:'
    path: poly/ntt.hpp
    title: poly/ntt.hpp
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':x:'
    path: test/yukicoder/2231.test.cpp
    title: test/yukicoder/2231.test.cpp
  _isVerificationFailed: true
  _pathExtension: hpp
  _verificationStatusIcon: ':x:'
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
    \ {20, 2789};\n    return {-1, -1};\n  }\n  static constexpr bool can_ntt() {\
    \ return ntt_info().fi != -1; }\n};\n\nusing modint107 = modint<1000000007>;\n\
    using modint998 = modint<998244353>;\n#line 2 \"poly/ntt.hpp\"\n\r\ntemplate <class\
    \ mint>\r\nvoid ntt(vector<mint>& a, bool inverse) {\r\n  assert(mint::can_ntt());\r\
    \n  const int rank2 = mint::ntt_info().fi;\r\n  const int mod = mint::get_mod();\r\
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
    \       len -= 2;\r\n      }\r\n    }\r\n  }\r\n}\r\n#line 2 \"poly/middle_product.hpp\"\
    \n\n#line 4 \"poly/middle_product.hpp\"\n\n// n, m \u6B21\u591A\u9805\u5F0F (n>=m)\
    \ a, b \u2192 n-m \u6B21\u591A\u9805\u5F0F c\n// c[i] = sum_j b[j]a[i+j]\ntemplate\
    \ <typename mint>\nvc<mint> middle_product(vc<mint>& a, vc<mint>& b) {\n  assert(len(a)\
    \ >= len(b));\n  if (b.empty()) return vc<mint>(len(a) - len(b) + 1);\n  if (min(len(b),\
    \ len(a) - len(b) + 1) <= 60) {\n    return middle_product_naive(a, b);\n  }\n\
    \  if constexpr (mint::ntt_info().fi == -1) {\n    return middle_product_garner(a,\
    \ b);\n  } else {\n    int n = 1 << __lg(2 * len(a) - 1);\n    vc<mint> fa(n),\
    \ fb(n);\n    copy(a.begin(), a.end(), fa.begin());\n    copy(b.rbegin(), b.rend(),\
    \ fb.begin());\n    ntt(fa, 0), ntt(fb, 0);\n    FOR(i, n) fa[i] *= fb[i];\n \
    \   ntt(fa, 1);\n    fa.resize(len(a));\n    fa.erase(fa.begin(), fa.begin() +\
    \ len(b) - 1);\n    return fa;\n  }\n}\n\ntemplate <typename mint>\nvc<mint> middle_product_garner(vc<mint>&\
    \ a, vc<mint> b) {\n  int n = len(a), m = len(b);\n  if (!n || !m) return {};\n\
    \  static const long long nttprimes[] = {754974721, 167772161, 469762049};\n \
    \ using mint0 = modint<754974721>;\n  using mint1 = modint<167772161>;\n  using\
    \ mint2 = modint<469762049>;\n  vc<mint0> a0(n), b0(m);\n  vc<mint1> a1(n), b1(m);\n\
    \  vc<mint2> a2(n), b2(m);\n  FOR(i, n) a0[i] = a[i].val, a1[i] = a[i].val, a2[i]\
    \ = a[i].val;\n  FOR(i, m) b0[i] = b[i].val, b1[i] = b[i].val, b2[i] = b[i].val;\n\
    \  auto c0 = middle_product<mint0>(a0, b0);\n  auto c1 = middle_product<mint1>(a1,\
    \ b1);\n  auto c2 = middle_product<mint2>(a2, b2);\n  static const long long m01\
    \ = 1LL * nttprimes[0] * nttprimes[1];\n  static const long long m0_inv_m1 = mint1(nttprimes[0]).inverse().val;\n\
    \  static const long long m01_inv_m2 = mint2(m01).inverse().val;\n  static const\
    \ int mod = mint::get_mod();\n  auto garner = [&](mint0 x0, mint1 x1, mint2 x2)\
    \ -> mint {\n    int r0 = x0.val, r1 = x1.val, r2 = x2.val;\n    int v1 = (m0_inv_m1\
    \ * (r1 + nttprimes[1] - r0)) % nttprimes[1];\n    auto v2 = (mint2(r2) - r0 -\
    \ mint2(nttprimes[0]) * v1) * mint2(m01_inv_m2);\n    return mint(r0 + 1LL * nttprimes[0]\
    \ * v1 + m01 % mod * v2.val);\n  };\n  vc<mint> c(len(c0));\n  FOR(i, len(c))\
    \ c[i] = garner(c0[i], c1[i], c2[i]);\n  return c;\n}\n\ntemplate <typename mint>\n\
    vc<mint> middle_product_naive(vc<mint>& a, vc<mint>& b) {\n  vc<mint> res(len(a)\
    \ - len(b) + 1);\n  FOR(i, len(res)) FOR(j, len(b)) res[i] += b[j] * a[i + j];\n\
    \  return res;\n}\n#line 4 \"string/wildcard_pattern_matching.hpp\"\n\nvc<bool>\
    \ wildcard_pattern_matching(string S, string T, char WILD = '?') {\n  using mint\
    \ = modint998;\n  int N = len(S), M = len(T);\n  int mi = 1024;\n  for (auto&&\
    \ x: S)\n    if (x != '?') chmin(mi, x);\n  for (auto&& x: T)\n    if (x != '?')\
    \ chmin(mi, x);\n  vc<mint> f1(N), g1(M);\n  FOR(i, N) f1[i] = (S[i] == '?' ?\
    \ 0 : S[i] - mi + 1);\n  FOR(i, M) g1[i] = (T[i] == '?' ? 0 : T[i] - mi + 1);\n\
    \  vc<mint> f2(N), f3(N), g2(M), g3(M);\n  FOR(i, N) f2[i] = f1[i] * f1[i], f3[i]\
    \ = f2[i] * f1[i];\n  FOR(i, M) g2[i] = g1[i] * g1[i], g3[i] = g2[i] * g1[i];\n\
    \  vc<mint> A = middle_product(f1, g3);\n  vc<mint> B = middle_product(f2, g2);\n\
    \  vc<mint> C = middle_product(f3, g1);\n  FOR(i, len(A)) A[i] = A[i] - B[i] -\
    \ B[i] + C[i];\n  vc<bool> res(len(A));\n  FOR(i, len(res)) res[i] = A[i] == mint(0);\n\
    \  return res;\n}\n"
  code: "#include \"mod/modint.hpp\"\n#include \"poly/ntt.hpp\"\n#include \"poly/middle_product.hpp\"\
    \n\nvc<bool> wildcard_pattern_matching(string S, string T, char WILD = '?') {\n\
    \  using mint = modint998;\n  int N = len(S), M = len(T);\n  int mi = 1024;\n\
    \  for (auto&& x: S)\n    if (x != '?') chmin(mi, x);\n  for (auto&& x: T)\n \
    \   if (x != '?') chmin(mi, x);\n  vc<mint> f1(N), g1(M);\n  FOR(i, N) f1[i] =\
    \ (S[i] == '?' ? 0 : S[i] - mi + 1);\n  FOR(i, M) g1[i] = (T[i] == '?' ? 0 : T[i]\
    \ - mi + 1);\n  vc<mint> f2(N), f3(N), g2(M), g3(M);\n  FOR(i, N) f2[i] = f1[i]\
    \ * f1[i], f3[i] = f2[i] * f1[i];\n  FOR(i, M) g2[i] = g1[i] * g1[i], g3[i] =\
    \ g2[i] * g1[i];\n  vc<mint> A = middle_product(f1, g3);\n  vc<mint> B = middle_product(f2,\
    \ g2);\n  vc<mint> C = middle_product(f3, g1);\n  FOR(i, len(A)) A[i] = A[i] -\
    \ B[i] - B[i] + C[i];\n  vc<bool> res(len(A));\n  FOR(i, len(res)) res[i] = A[i]\
    \ == mint(0);\n  return res;\n}"
  dependsOn:
  - mod/modint.hpp
  - mod/modint_common.hpp
  - poly/ntt.hpp
  - poly/middle_product.hpp
  isVerificationFile: false
  path: string/wildcard_pattern_matching.hpp
  requiredBy: []
  timestamp: '2023-04-27 16:27:36+09:00'
  verificationStatus: LIBRARY_ALL_WA
  verifiedWith:
  - test/yukicoder/2231.test.cpp
documentation_of: string/wildcard_pattern_matching.hpp
layout: document
redirect_from:
- /library/string/wildcard_pattern_matching.hpp
- /library/string/wildcard_pattern_matching.hpp.html
title: string/wildcard_pattern_matching.hpp
---
