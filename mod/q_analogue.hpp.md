---
data:
  _extendedDependsOn:
  - icon: ':x:'
    path: mod/all_inverse.hpp
    title: mod/all_inverse.hpp
  - icon: ':question:'
    path: mod/modint.hpp
    title: mod/modint.hpp
  - icon: ':question:'
    path: mod/modint_common.hpp
    title: mod/modint_common.hpp
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':warning:'
  attributes:
    links: []
  bundledCode: "#line 2 \"mod/modint_common.hpp\"\n\nstruct has_mod_impl {\n  template\
    \ <class T>\n  static auto check(T &&x) -> decltype(x.get_mod(), std::true_type{});\n\
    \  template <class T>\n  static auto check(...) -> std::false_type;\n};\n\ntemplate\
    \ <class T>\nclass has_mod : public decltype(has_mod_impl::check<T>(std::declval<T>()))\
    \ {};\n\ntemplate <typename mint>\nmint inv(int n) {\n  static const int mod =\
    \ mint::get_mod();\n  static vector<mint> dat = {0, 1};\n  assert(0 <= n);\n \
    \ if (n >= mod) n %= mod;\n  while (len(dat) <= n) {\n    int k = len(dat);\n\
    \    int q = (mod + k - 1) / k;\n    dat.eb(dat[k * q - mod] * mint(q));\n  }\n\
    \  return dat[n];\n}\n\ntemplate <typename mint>\nmint fact(int n) {\n  static\
    \ const int mod = mint::get_mod();\n  assert(0 <= n);\n  if (n >= mod) return\
    \ 0;\n  static vector<mint> dat = {1, 1};\n  while (len(dat) <= n) dat.eb(dat[len(dat)\
    \ - 1] * mint(len(dat)));\n  return dat[n];\n}\n\ntemplate <typename mint>\nmint\
    \ fact_inv(int n) {\n  static vector<mint> dat = {1, 1};\n  if (n < 0) return\
    \ mint(0);\n  while (len(dat) <= n) dat.eb(dat[len(dat) - 1] * inv<mint>(len(dat)));\n\
    \  return dat[n];\n}\n\ntemplate <class mint, class... Ts>\nmint fact_invs(Ts...\
    \ xs) {\n  return (mint(1) * ... * fact_inv<mint>(xs));\n}\n\ntemplate <typename\
    \ mint, class Head, class... Tail>\nmint multinomial(Head &&head, Tail &&... tail)\
    \ {\n  return fact<mint>(head) * fact_invs<mint>(std::forward<Tail>(tail)...);\n\
    }\n\ntemplate <typename mint>\nmint C_dense(int n, int k) {\n  static vvc<mint>\
    \ C;\n  static int H = 0, W = 0;\n  auto calc = [&](int i, int j) -> mint {\n\
    \    if (i == 0) return (j == 0 ? mint(1) : mint(0));\n    return C[i - 1][j]\
    \ + (j ? C[i - 1][j - 1] : 0);\n  };\n  if (W <= k) {\n    FOR(i, H) {\n     \
    \ C[i].resize(k + 1);\n      FOR(j, W, k + 1) { C[i][j] = calc(i, j); }\n    }\n\
    \    W = k + 1;\n  }\n  if (H <= n) {\n    C.resize(n + 1);\n    FOR(i, H, n +\
    \ 1) {\n      C[i].resize(W);\n      FOR(j, W) { C[i][j] = calc(i, j); }\n   \
    \ }\n    H = n + 1;\n  }\n  return C[n][k];\n}\n\ntemplate <typename mint, bool\
    \ large = false, bool dense = false>\nmint C(ll n, ll k) {\n  assert(n >= 0);\n\
    \  if (k < 0 || n < k) return 0;\n  if (dense) return C_dense<mint>(n, k);\n \
    \ if (!large) return multinomial<mint>(n, k, n - k);\n  k = min(k, n - k);\n \
    \ mint x(1);\n  FOR(i, k) x *= mint(n - i);\n  return x * fact_inv<mint>(k);\n\
    }\n\ntemplate <typename mint, bool large = false>\nmint C_inv(ll n, ll k) {\n\
    \  assert(n >= 0);\n  assert(0 <= k && k <= n);\n  if (!large) return fact_inv<mint>(n)\
    \ * fact<mint>(k) * fact<mint>(n - k);\n  return mint(1) / C<mint, 1>(n, k);\n\
    }\n\n// [x^d] (1-x) ^ {-n} \u306E\u8A08\u7B97\ntemplate <typename mint, bool large\
    \ = false, bool dense = false>\nmint C_negative(ll n, ll d) {\n  assert(n >= 0);\n\
    \  if (d < 0) return mint(0);\n  if (n == 0) { return (d == 0 ? mint(1) : mint(0));\
    \ }\n  return C<mint, large, dense>(n + d - 1, d);\n}\n#line 3 \"mod/modint.hpp\"\
    \n\ntemplate <u32 mod>\nstruct modint {\n  static_assert(mod < (u32(1) << 31));\n\
    \  u32 val;\n  constexpr modint() : val(0) {}\n  constexpr modint(u32 x) : val(x\
    \ % mod) {}\n  constexpr modint(u64 x) : val(x % mod) {}\n  constexpr modint(int\
    \ x) : val((x %= int(mod)) < 0 ? x + int(mod) : x){};\n  constexpr modint(ll x)\
    \ : val((x %= int(mod)) < 0 ? x + int(mod) : x){};\n  bool operator<(const modint\
    \ &other) const { return val < other.val; }\n  modint &operator+=(const modint\
    \ &p) {\n    if ((val += p.val) >= mod) val -= mod;\n    return *this;\n  }\n\
    \  modint &operator-=(const modint &p) {\n    if ((val += mod - p.val) >= mod)\
    \ val -= mod;\n    return *this;\n  }\n  modint &operator*=(const modint &p) {\n\
    \    val = u64(val) * p.val % mod;\n    return *this;\n  }\n  modint &operator/=(const\
    \ modint &p) {\n    *this *= p.inverse();\n    return *this;\n  }\n  modint operator-()\
    \ const { return modint(mod - val); }\n  modint operator+(const modint &p) const\
    \ { return modint(*this) += p; }\n  modint operator-(const modint &p) const {\
    \ return modint(*this) -= p; }\n  modint operator*(const modint &p) const { return\
    \ modint(*this) *= p; }\n  modint operator/(const modint &p) const { return modint(*this)\
    \ /= p; }\n  bool operator==(const modint &p) const { return val == p.val; }\n\
    \  bool operator!=(const modint &p) const { return val != p.val; }\n  modint inverse()\
    \ const {\n    int a = val, b = mod, u = 1, v = 0, t;\n    while (b > 0) {\n \
    \     t = a / b;\n      swap(a -= t * b, b), swap(u -= t * v, v);\n    }\n   \
    \ return modint(u);\n  }\n  modint pow(ll n) const {\n    assert(n >= 0);\n  \
    \  modint ret(1), mul(val);\n    while (n > 0) {\n      if (n & 1) ret *= mul;\n\
    \      mul *= mul;\n      n >>= 1;\n    }\n    return ret;\n  }\n#ifdef FASTIO\n\
    \  void write() { fastio::printer.write(val); }\n  void read() {\n    fastio::scanner.read(val);\n\
    \    val %= mod;\n  }\n#endif\n  static constexpr u32 get_mod() { return mod;\
    \ }\n  // (n, r), r \u306F 1 \u306E 2^n \u4E57\u6839\n  static constexpr pair<int,\
    \ int> ntt_info() {\n    if (mod == 167772161) return {25, 17};\n    if (mod ==\
    \ 469762049) return {26, 30};\n    if (mod == 754974721) return {24, 362};\n \
    \   if (mod == 880803841) return {23, 211};\n    if (mod == 998244353) return\
    \ {23, 31};\n    if (mod == 1045430273) return {20, 363};\n    if (mod == 1051721729)\
    \ return {20, 330};\n    if (mod == 1053818881) return {20, 2789};\n    return\
    \ {-1, -1};\n  }\n  static constexpr bool can_ntt() { return ntt_info().fi !=\
    \ -1; }\n};\n\nusing modint107 = modint<1000000007>;\nusing modint998 = modint<998244353>;\n\
    #line 2 \"mod/all_inverse.hpp\"\ntemplate <typename mint>\nvc<mint> all_inverse(vc<mint>&\
    \ X) {\n  for (auto&& x: X) assert(x != mint(0));\n  int N = len(X);\n  vc<mint>\
    \ res(N + 1);\n  res[0] = mint(1);\n  FOR(i, N) res[i + 1] = res[i] * X[i];\n\
    \  mint t = res.back().inverse();\n  res.pop_back();\n  FOR_R(i, N) {\n    res[i]\
    \ *= t;\n    t *= X[i];\n  }\n  return res;\n}\n#line 3 \"mod/q_analogue.hpp\"\
    \n\ntemplate <typename mint>\nstruct q_Analogue {\n  const mint q;\n  const int\
    \ LIM;\n  int D;\n  vc<mint> factorial, ifactorial;\n\n  q_Analogue(mint q, int\
    \ LIM) : q(q), LIM(LIM) {\n    assert(LIM < mint::get_mod());\n    build();\n\
    \  }\n\n  void build() {\n    factorial.reserve(LIM + 1);\n    factorial.eb(1);\n\
    \    mint x = 1;\n    FOR(i, 1, LIM + 1) {\n      if (x == mint(0)) break;\n \
    \     factorial.eb(factorial.back() * x);\n      x = q * x + mint(1);\n    }\n\
    \    ifactorial = all_inverse(factorial);\n    D = len(factorial);\n  }\n\n  mint\
    \ fact(int N) {\n    assert(0 <= N && N <= LIM);\n    return (N < D ? factorial[N]\
    \ : mint(0));\n  }\n  mint fact_inv(int N) {\n    assert(0 <= N && N < D);\n \
    \   return (N < D ? ifactorial[N] : mint(0));\n  }\n  mint binom(int N, int K)\
    \ {\n    assert(0 <= N && N <= LIM);\n    if (K < 0 || K > N) return mint(0);\n\
    \    if (N < D) return factorial[N] * ifactorial[K] * ifactorial[N - K];\n   \
    \ auto [n1, n2] = divmod(N, D);\n    auto [k1, k2] = divmod(K, D);\n    return\
    \ C<mint>(n1, k1) * binom(n2, k2);\n  }\n};\n"
  code: "#include \"mod/modint.hpp\"\n#include \"mod/all_inverse.hpp\"\n\ntemplate\
    \ <typename mint>\nstruct q_Analogue {\n  const mint q;\n  const int LIM;\n  int\
    \ D;\n  vc<mint> factorial, ifactorial;\n\n  q_Analogue(mint q, int LIM) : q(q),\
    \ LIM(LIM) {\n    assert(LIM < mint::get_mod());\n    build();\n  }\n\n  void\
    \ build() {\n    factorial.reserve(LIM + 1);\n    factorial.eb(1);\n    mint x\
    \ = 1;\n    FOR(i, 1, LIM + 1) {\n      if (x == mint(0)) break;\n      factorial.eb(factorial.back()\
    \ * x);\n      x = q * x + mint(1);\n    }\n    ifactorial = all_inverse(factorial);\n\
    \    D = len(factorial);\n  }\n\n  mint fact(int N) {\n    assert(0 <= N && N\
    \ <= LIM);\n    return (N < D ? factorial[N] : mint(0));\n  }\n  mint fact_inv(int\
    \ N) {\n    assert(0 <= N && N < D);\n    return (N < D ? ifactorial[N] : mint(0));\n\
    \  }\n  mint binom(int N, int K) {\n    assert(0 <= N && N <= LIM);\n    if (K\
    \ < 0 || K > N) return mint(0);\n    if (N < D) return factorial[N] * ifactorial[K]\
    \ * ifactorial[N - K];\n    auto [n1, n2] = divmod(N, D);\n    auto [k1, k2] =\
    \ divmod(K, D);\n    return C<mint>(n1, k1) * binom(n2, k2);\n  }\n};\n"
  dependsOn:
  - mod/modint.hpp
  - mod/modint_common.hpp
  - mod/all_inverse.hpp
  isVerificationFile: false
  path: mod/q_analogue.hpp
  requiredBy: []
  timestamp: '2023-08-06 23:25:43+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: mod/q_analogue.hpp
layout: document
redirect_from:
- /library/mod/q_analogue.hpp
- /library/mod/q_analogue.hpp.html
title: mod/q_analogue.hpp
---
