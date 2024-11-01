---
data:
  _extendedDependsOn:
  - icon: ':question:'
    path: mod/modint.hpp
    title: mod/modint.hpp
  - icon: ':question:'
    path: mod/modint_common.hpp
    title: mod/modint_common.hpp
  - icon: ':heavy_check_mark:'
    path: seq/hook_length_formula.hpp
    title: seq/hook_length_formula.hpp
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/3_yukicoder/2149.test.cpp
    title: test/3_yukicoder/2149.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 2 \"seq/hook_length_formula.hpp\"\n\n#line 2 \"mod/modint_common.hpp\"\
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
    #line 4 \"seq/hook_length_formula.hpp\"\n\ntemplate <typename mint>\nmint hook_length_formula(vc<int>\
    \ A) {\n  if (len(A) == 0) return 1;\n  int H = len(A), W = A[0];\n  FOR(i, H\
    \ - 1) assert(A[i] >= A[i + 1]);\n  vc<int> B(W);\n  reverse(all(A));\n  mint\
    \ ANS = fact<mint>(SUM<int>(A));\n  for (auto&& a: A) {\n    FOR(j, a) { ANS *=\
    \ inv<mint>(B[j] + a - j), ++B[j]; }\n  }\n  return ANS;\n}\n#line 2 \"seq/domino_standard_tableaux.hpp\"\
    \n\ntemplate <typename mint>\nmint domino_standard_tableaux(vc<int> A) {\n  int\
    \ N = len(A);\n  if (N == 0) return mint(1);\n  FOR(i, N - 1) assert(A[i] >= A[i\
    \ + 1]);\n  int x = 0;\n  FOR(i, N) {\n    if (A[i] % 2 == 1) { x += (i % 2 ==\
    \ 0 ? 1 : -1); }\n  }\n  if (x != 0) return 0;\n  FOR(i, N) A[i] += N - 1 - i;\n\
    \  int ev = 0, od = 0;\n  vc<int> P, Q;\n  FOR_R(i, N) {\n    if (A[i] % 2 ==\
    \ 0) { P.eb(A[i] / 2 - ev), ++ev; }\n    if (A[i] % 2 == 1) { Q.eb(A[i] / 2 -\
    \ od), ++od; }\n  }\n  reverse(all(P)), reverse(all(Q));\n  int b = SUM<int>(P),\
    \ c = SUM<int>(Q);\n  return C<mint>(b + c, b) * hook_length_formula<mint>(P)\n\
    \         * hook_length_formula<mint>(Q);\n}\n"
  code: "#include \"seq/hook_length_formula.hpp\"\n\ntemplate <typename mint>\nmint\
    \ domino_standard_tableaux(vc<int> A) {\n  int N = len(A);\n  if (N == 0) return\
    \ mint(1);\n  FOR(i, N - 1) assert(A[i] >= A[i + 1]);\n  int x = 0;\n  FOR(i,\
    \ N) {\n    if (A[i] % 2 == 1) { x += (i % 2 == 0 ? 1 : -1); }\n  }\n  if (x !=\
    \ 0) return 0;\n  FOR(i, N) A[i] += N - 1 - i;\n  int ev = 0, od = 0;\n  vc<int>\
    \ P, Q;\n  FOR_R(i, N) {\n    if (A[i] % 2 == 0) { P.eb(A[i] / 2 - ev), ++ev;\
    \ }\n    if (A[i] % 2 == 1) { Q.eb(A[i] / 2 - od), ++od; }\n  }\n  reverse(all(P)),\
    \ reverse(all(Q));\n  int b = SUM<int>(P), c = SUM<int>(Q);\n  return C<mint>(b\
    \ + c, b) * hook_length_formula<mint>(P)\n         * hook_length_formula<mint>(Q);\n\
    }\n"
  dependsOn:
  - seq/hook_length_formula.hpp
  - mod/modint.hpp
  - mod/modint_common.hpp
  isVerificationFile: false
  path: seq/domino_standard_tableaux.hpp
  requiredBy: []
  timestamp: '2024-10-25 01:17:46+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/3_yukicoder/2149.test.cpp
documentation_of: seq/domino_standard_tableaux.hpp
layout: document
redirect_from:
- /library/seq/domino_standard_tableaux.hpp
- /library/seq/domino_standard_tableaux.hpp.html
title: seq/domino_standard_tableaux.hpp
---
