---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: mod/modint.hpp
    title: mod/modint.hpp
  - icon: ':heavy_check_mark:'
    path: mod/modint_common.hpp
    title: mod/modint_common.hpp
  - icon: ':heavy_check_mark:'
    path: setfunc/ranked_zeta.hpp
    title: setfunc/ranked_zeta.hpp
  - icon: ':heavy_check_mark:'
    path: setfunc/sps_composition.hpp
    title: setfunc/sps_composition.hpp
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/5_atcoder/abc213g.test.cpp
    title: test/5_atcoder/abc213g.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/5_atcoder/abc321g.test.cpp
    title: test/5_atcoder/abc321g.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/5_atcoder/arc105.test.cpp
    title: test/5_atcoder/arc105.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
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
    mint C_dense(int n, int k) {\n  assert(n >= 0);\n  if (k < 0 || n < k) return\
    \ 0;\n  static vvc<mint> C;\n  static int H = 0, W = 0;\n  auto calc = [&](int\
    \ i, int j) -> mint {\n    if (i == 0) return (j == 0 ? mint(1) : mint(0));\n\
    \    return C[i - 1][j] + (j ? C[i - 1][j - 1] : 0);\n  };\n  if (W <= k) {\n\
    \    FOR(i, H) {\n      C[i].resize(k + 1);\n      FOR(j, W, k + 1) { C[i][j]\
    \ = calc(i, j); }\n    }\n    W = k + 1;\n  }\n  if (H <= n) {\n    C.resize(n\
    \ + 1);\n    FOR(i, H, n + 1) {\n      C[i].resize(W);\n      FOR(j, W) { C[i][j]\
    \ = calc(i, j); }\n    }\n    H = n + 1;\n  }\n  return C[n][k];\n}\n\ntemplate\
    \ <typename mint, bool large = false, bool dense = false>\nmint C(ll n, ll k)\
    \ {\n  assert(n >= 0);\n  if (k < 0 || n < k) return 0;\n  if constexpr (dense)\
    \ return C_dense<mint>(n, k);\n  if constexpr (!large) return multinomial<mint>(n,\
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
    using modint998 = modint<998244353>;\n#line 2 \"setfunc/ranked_zeta.hpp\"\n\r\n\
    template <typename T, int LIM>\r\nvc<array<T, LIM + 1>> ranked_zeta(const vc<T>&\
    \ f) {\r\n  int n = topbit(len(f));\r\n  assert(n <= LIM);\r\n  assert(len(f)\
    \ == 1 << n);\r\n  vc<array<T, LIM + 1>> Rf(1 << n);\r\n  for (int s = 0; s <\
    \ (1 << n); ++s) Rf[s][popcnt(s)] = f[s];\r\n  for (int i = 0; i < n; ++i) {\r\
    \n    int w = 1 << i;\r\n    for (int p = 0; p < (1 << n); p += 2 * w) {\r\n \
    \     for (int s = p; s < p + w; ++s) {\r\n        int t = s | 1 << i;\r\n   \
    \     for (int d = 0; d <= n; ++d) Rf[t][d] += Rf[s][d];\r\n      }\r\n    }\r\
    \n  }\r\n  return Rf;\r\n}\r\n\r\ntemplate <typename T, int LIM>\r\nvc<T> ranked_mobius(vc<array<T,\
    \ LIM + 1>>& Rf) {\r\n  int n = topbit(len(Rf));\r\n  assert(len(Rf) == 1 << n);\r\
    \n  for (int i = 0; i < n; ++i) {\r\n    int w = 1 << i;\r\n    for (int p = 0;\
    \ p < (1 << n); p += 2 * w) {\r\n      for (int s = p; s < p + w; ++s) {\r\n \
    \       int t = s | 1 << i;\r\n        for (int d = 0; d <= n; ++d) Rf[t][d] -=\
    \ Rf[s][d];\r\n      }\r\n    }\r\n  }\r\n  vc<T> f(1 << n);\r\n  for (int s =\
    \ 0; s < (1 << n); ++s) f[s] = Rf[s][popcnt(s)];\r\n  return f;\r\n}\n#line 2\
    \ \"setfunc/sps_composition.hpp\"\n\n// sum_i f_i/i! s^i, s^i is subset-convolution\n\
    template <typename mint, int LIM>\nvc<mint> sps_composition_egf(vc<mint>& f, vc<mint>&\
    \ s) {\n  const int N = topbit(len(s));\n  assert(len(s) == (1 << N) && s[0] ==\
    \ mint(0));\n  if (len(f) > N) f.resize(N + 1);\n  int D = len(f) - 1;\n  using\
    \ ARR = array<mint, LIM + 1>;\n  vvc<ARR> zs(N);\n  FOR(i, N) {\n    zs[i]\n \
    \       = ranked_zeta<mint, LIM>({s.begin() + (1 << i), s.begin() + (2 << i)});\n\
    \  }\n\n  // dp : (d/dt)^df(s) (d=D,D-1,...)\n  vc<mint> dp(1 << (N - D));\n \
    \ dp[0] = f[D];\n  FOR_R(d, D) {\n    vc<mint> newdp(1 << (N - d));\n    newdp[0]\
    \ = f[d];\n    vc<ARR> zdp = ranked_zeta<mint, LIM>(dp);\n    FOR(i, N - d) {\n\
    \      // zs[1<<i:2<<i], zdp[0:1<<i]\n      vc<ARR> znewdp(1 << i);\n      FOR(k,\
    \ 1 << i) {\n        FOR(p, i + 1) FOR(q, i - p + 1) {\n          znewdp[k][p\
    \ + q] += zdp[k][p] * zs[i][k][q];\n        }\n      }\n      auto x = ranked_mobius<mint,\
    \ LIM>(znewdp);\n      copy(all(x), newdp.begin() + (1 << i));\n    }\n    swap(dp,\
    \ newdp);\n  }\n  return dp;\n}\n\n// sum_i f_i s^i, s^i is subset-convolution\n\
    template <typename mint, int LIM>\nvc<mint> sps_composition_poly(vc<mint> f, vc<mint>\
    \ s) {\n  const int N = topbit(len(s));\n  assert(len(s) == (1 << N));\n  if (f.empty())\
    \ return vc<mint>(1 << N, mint(0));\n  // convert to egf problem\n  int D = min<int>(len(f)\
    \ - 1, N);\n  vc<mint> g(D + 1);\n  mint c = s[0];\n  s[0] = 0;\n  // (x+c)^i\n\
    \  vc<mint> pow(D + 1);\n  pow[0] = 1;\n  FOR(i, len(f)) {\n    FOR(j, D + 1)\
    \ g[j] += f[i] * pow[j];\n    FOR_R(j, D + 1) pow[j] = pow[j] * c + (j == 0 ?\
    \ mint(0) : pow[j - 1]);\n  }\n  // to egf\n  mint factorial = 1;\n  FOR(j, D\
    \ + 1) g[j] *= factorial, factorial *= mint(j + 1);\n  return sps_composition_egf<mint,\
    \ LIM>(g, s);\n}\n#line 3 \"setfunc/sps_log.hpp\"\n\n// exp \u306E\u9006\u624B\
    \u9806\u3067\u8A08\u7B97\u3059\u308B\ntemplate <typename mint, int LIM>\nvc<mint>\
    \ sps_log(vc<mint>& dp) {\n  const int N = topbit(len(dp));\n  assert(len(dp)\
    \ == (1 << N) && dp[0] == mint(1));\n  vc<mint> s(1 << N);\n  FOR_R(i, N) {\n\
    \    vc<mint> a = {dp.begin() + (1 << i), dp.begin() + (2 << i)};\n    vc<mint>\
    \ b = {dp.begin(), dp.begin() + (1 << i)};\n    auto RA = ranked_zeta<mint, LIM>(a);\n\
    \    auto RB = ranked_zeta<mint, LIM>(b);\n    FOR(s, 1 << i) {\n      auto &f\
    \ = RA[s], &g = RB[s];\n      // assert(g[0] == mint(1));\n      FOR(d, i + 1)\
    \ { FOR(i, d) f[d] -= f[i] * g[d - i]; }\n    }\n    a = ranked_mobius<mint, LIM>(RA);\n\
    \    copy(all(a), s.begin() + (1 << i));\n  }\n  return s;\n}\n"
  code: "#include \"mod/modint.hpp\"\n#include \"setfunc/sps_composition.hpp\"\n\n\
    // exp \u306E\u9006\u624B\u9806\u3067\u8A08\u7B97\u3059\u308B\ntemplate <typename\
    \ mint, int LIM>\nvc<mint> sps_log(vc<mint>& dp) {\n  const int N = topbit(len(dp));\n\
    \  assert(len(dp) == (1 << N) && dp[0] == mint(1));\n  vc<mint> s(1 << N);\n \
    \ FOR_R(i, N) {\n    vc<mint> a = {dp.begin() + (1 << i), dp.begin() + (2 << i)};\n\
    \    vc<mint> b = {dp.begin(), dp.begin() + (1 << i)};\n    auto RA = ranked_zeta<mint,\
    \ LIM>(a);\n    auto RB = ranked_zeta<mint, LIM>(b);\n    FOR(s, 1 << i) {\n \
    \     auto &f = RA[s], &g = RB[s];\n      // assert(g[0] == mint(1));\n      FOR(d,\
    \ i + 1) { FOR(i, d) f[d] -= f[i] * g[d - i]; }\n    }\n    a = ranked_mobius<mint,\
    \ LIM>(RA);\n    copy(all(a), s.begin() + (1 << i));\n  }\n  return s;\n}"
  dependsOn:
  - mod/modint.hpp
  - mod/modint_common.hpp
  - setfunc/sps_composition.hpp
  - setfunc/ranked_zeta.hpp
  isVerificationFile: false
  path: setfunc/sps_log.hpp
  requiredBy: []
  timestamp: '2024-11-14 21:00:22+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/5_atcoder/abc213g.test.cpp
  - test/5_atcoder/abc321g.test.cpp
  - test/5_atcoder/arc105.test.cpp
documentation_of: setfunc/sps_log.hpp
layout: document
redirect_from:
- /library/setfunc/sps_log.hpp
- /library/setfunc/sps_log.hpp.html
title: setfunc/sps_log.hpp
---
