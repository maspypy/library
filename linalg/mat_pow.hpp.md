---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: linalg/mat_mul.hpp
    title: linalg/mat_mul.hpp
  - icon: ':heavy_check_mark:'
    path: mod/factorial.hpp
    title: mod/factorial.hpp
  - icon: ':heavy_check_mark:'
    path: mod/modint.hpp
    title: mod/modint.hpp
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/yukicoder/1750.test.cpp
    title: test/yukicoder/1750.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/yukicoder/1810.test.cpp
    title: test/yukicoder/1810.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 1 \"mod/factorial.hpp\"\n\ntemplate <typename mint>\nmint inv(int\
    \ n) {\n  static const int mod = mint::get_mod();\n  static vector<mint> dat =\
    \ {0, 1};\n  assert(0 <= n);\n  if (n >= mod) n %= mod;\n  while (len(dat) <=\
    \ n) {\n    int k = len(dat);\n    int q = (mod + k - 1) / k;\n    dat.eb(dat[k\
    \ * q - mod] * mint(q));\n  }\n  return dat[n];\n}\n\ntemplate <typename mint>\n\
    mint fact(int n) {\n  static const int mod = mint::get_mod();\n  assert(0 <= n);\n\
    \  if (n >= mod) return 0;\n  static vector<mint> dat = {1, 1};\n  while (len(dat)\
    \ <= n) dat.eb(dat[len(dat) - 1] * mint(len(dat)));\n  return dat[n];\n}\n\ntemplate\
    \ <typename mint>\nmint fact_inv(int n) {\n  static const int mod = mint::get_mod();\n\
    \  assert(-1 <= n && n < mod);\n  static vector<mint> dat = {1, 1};\n  if (n ==\
    \ -1) return mint(0);\n  while (len(dat) <= n) dat.eb(dat[len(dat) - 1] * inv<mint>(len(dat)));\n\
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
    \n\ntemplate <int mod>\nstruct modint {\n  int val;\n  constexpr modint(ll x =\
    \ 0) noexcept {\n    if (0 <= x && x < mod)\n      val = x;\n    else {\n    \
    \  x %= mod;\n      val = (x < 0 ? x + mod : x);\n    }\n  }\n  bool operator<(const\
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
    \ }\n  void read() {\n    ll x;\n    fastio::scanner.read(x);\n    if (x < 0 ||\
    \ x >= mod) x %= mod;\n    if (x < 0) x += mod;\n    val += x;\n  }\n#endif\n\
    \  static constexpr int get_mod() { return mod; }\n\n  // (n, r), r \u306F 1 \u306E\
    \ 2^n \u4E57\u6839\n  static constexpr pair<int, int> ntt_info() {\n    if (mod\
    \ == 167772161) return {25, 17};\n    if (mod == 469762049) return {26, 30};\n\
    \    if (mod == 754974721) return {24, 362};\n    if (mod == 880803841) return\
    \ {23, 211};\n    if (mod == 998244353) return {23, 31};\n    if (mod == 1045430273)\
    \ return {20, 363};\n    if (mod == 1051721729) return {20, 330};\n    if (mod\
    \ == 1053818881) return {20, 2789};\n    return {-1, -1};\n  }\n};\n\nstruct ArbitraryModInt\
    \ {\n  static constexpr bool is_modint = true;\n  int val;\n  ArbitraryModInt()\
    \ : val(0) {}\n  ArbitraryModInt(int64_t y)\n      : val(y >= 0 ? y % get_mod()\n\
    \                   : (get_mod() - (-y) % get_mod()) % get_mod()) {}\n  bool operator<(const\
    \ ArbitraryModInt &other) const {\n    return val < other.val;\n  } // To use\
    \ std::map<ArbitraryModInt, T>\n  static int &get_mod() {\n    static int mod\
    \ = 0;\n    return mod;\n  }\n  static void set_mod(int md) { get_mod() = md;\
    \ }\n  ArbitraryModInt &operator+=(const ArbitraryModInt &p) {\n    if ((val +=\
    \ p.val) >= get_mod()) val -= get_mod();\n    return *this;\n  }\n  ArbitraryModInt\
    \ &operator-=(const ArbitraryModInt &p) {\n    if ((val += get_mod() - p.val)\
    \ >= get_mod()) val -= get_mod();\n    return *this;\n  }\n  ArbitraryModInt &operator*=(const\
    \ ArbitraryModInt &p) {\n    long long a = (long long)val * p.val;\n    int xh\
    \ = (int)(a >> 32), xl = (int)a, d, m;\n    asm(\"divl %4; \\n\\t\" : \"=a\"(d),\
    \ \"=d\"(m) : \"d\"(xh), \"a\"(xl), \"r\"(get_mod()));\n    val = m;\n    return\
    \ *this;\n  }\n  ArbitraryModInt &operator/=(const ArbitraryModInt &p) {\n   \
    \ *this *= p.inverse();\n    return *this;\n  }\n  ArbitraryModInt operator-()\
    \ const { return ArbitraryModInt(get_mod() - val); }\n  ArbitraryModInt operator+(const\
    \ ArbitraryModInt &p) const {\n    return ArbitraryModInt(*this) += p;\n  }\n\
    \  ArbitraryModInt operator-(const ArbitraryModInt &p) const {\n    return ArbitraryModInt(*this)\
    \ -= p;\n  }\n  ArbitraryModInt operator*(const ArbitraryModInt &p) const {\n\
    \    return ArbitraryModInt(*this) *= p;\n  }\n  ArbitraryModInt operator/(const\
    \ ArbitraryModInt &p) const {\n    return ArbitraryModInt(*this) /= p;\n  }\n\
    \  bool operator==(const ArbitraryModInt &p) const { return val == p.val; }\n\
    \  bool operator!=(const ArbitraryModInt &p) const { return val != p.val; }\n\
    \  ArbitraryModInt inverse() const {\n    int a = val, b = get_mod(), u = 1, v\
    \ = 0, t;\n    while (b > 0) {\n      t = a / b;\n      swap(a -= t * b, b), swap(u\
    \ -= t * v, v);\n    }\n    return ArbitraryModInt(u);\n  }\n  ArbitraryModInt\
    \ pow(int64_t n) const {\n    assert(n >= 0);\n    ArbitraryModInt ret(1), mul(val);\n\
    \    while (n > 0) {\n      if (n & 1) ret *= mul;\n      mul *= mul;\n      n\
    \ >>= 1;\n    }\n    return ret;\n  }\n#ifdef FASTIO\n  void write() { fastio::printer.write(val);\
    \ }\n  void read() { fastio::scanner.read(val); }\n#endif\n  static constexpr\
    \ pair<int, int> ntt_info() { return {-1, -1}; }\n};\n\nusing modint107 = modint<1000000007>;\n\
    using modint998 = modint<998244353>;\nusing amint = ArbitraryModInt;\n\nstruct\
    \ has_mod_impl {\n  template <class T>\n  static auto check(T &&x) -> decltype(x.get_mod(),\
    \ std::true_type{});\n  template <class T>\n  static auto check(...) -> std::false_type;\n\
    };\n\ntemplate <class T>\nclass has_mod : public decltype(has_mod_impl::check<T>(std::declval<T>()))\
    \ {};\n#line 3 \"linalg/mat_mul.hpp\"\n\r\ntemplate <class T, typename enable_if<has_mod<T>::value>::type*\
    \ = nullptr>\r\nvc<vc<T>> mat_mul(const vc<vc<T>>& A, const vc<vc<T>>& B) {\r\n\
    \  constexpr int mod = T::get_mod();\r\n  auto N = len(A), M = len(B), K = len(B[0]);\r\
    \n  vv(int, b, K, M);\r\n  FOR(i, M) FOR(j, K) b[j][i] = B[i][j].val;\r\n  vv(T,\
    \ C, N, K);\r\n\r\n  if (M <= 16) {\r\n    FOR(i, N) FOR(j, K) {\r\n      u64\
    \ sm = 0;\r\n      FOR(m, M) sm += u64(A[i][m].val) * b[j][m];\r\n      C[i][j]\
    \ = sm % mod;\r\n    }\r\n  } else {\r\n    FOR(i, N) FOR(j, K) {\r\n      i128\
    \ sm = 0;\r\n      FOR(m, M) sm += ll(A[i][m].val) * b[j][m];\r\n      C[i][j]\
    \ = sm % mod;\r\n    }\r\n  }\r\n  return C;\r\n}\r\n\r\ntemplate <class T, typename\
    \ enable_if<!has_mod<T>::value>::type* = nullptr>\r\nvc<vc<T>> mat_mul(const vc<vc<T>>&\
    \ A, const vc<vc<T>>& B) {\r\n  auto N = len(A), M = len(B), K = len(B[0]);\r\n\
    \  vv(T, b, K, M);\r\n  FOR(i, M) FOR(j, K) b[j][i] = B[i][j];\r\n  vv(T, C, N,\
    \ K);\r\n  FOR(n, N) FOR(m, M) FOR(k, K) C[n][k] += A[n][m] * b[k][m];\r\n  return\
    \ C;\r\n}\r\n#line 2 \"linalg/mat_pow.hpp\"\ntemplate<typename T>\r\nvc<vc<T>>\
    \ mat_pow(vc<vc<T>> A, ll n){\r\n  int N = len(A);\r\n  vv(T, ret, N, N);\r\n\
    \  FOR(i, N) ret[i][i] = T(1);\r\n  while(n){\r\n    if(n & 1) ret = mat_mul(ret,\
    \ A);\r\n    n /= 2;\r\n    if(n) A = mat_mul(A, A);\r\n  }\r\n  return ret;\r\
    \n}\n"
  code: "#include \"linalg/mat_mul.hpp\"\r\ntemplate<typename T>\r\nvc<vc<T>> mat_pow(vc<vc<T>>\
    \ A, ll n){\r\n  int N = len(A);\r\n  vv(T, ret, N, N);\r\n  FOR(i, N) ret[i][i]\
    \ = T(1);\r\n  while(n){\r\n    if(n & 1) ret = mat_mul(ret, A);\r\n    n /= 2;\r\
    \n    if(n) A = mat_mul(A, A);\r\n  }\r\n  return ret;\r\n}"
  dependsOn:
  - linalg/mat_mul.hpp
  - mod/modint.hpp
  - mod/factorial.hpp
  isVerificationFile: false
  path: linalg/mat_pow.hpp
  requiredBy: []
  timestamp: '2023-02-23 05:23:26+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/yukicoder/1810.test.cpp
  - test/yukicoder/1750.test.cpp
documentation_of: linalg/mat_pow.hpp
layout: document
redirect_from:
- /library/linalg/mat_pow.hpp
- /library/linalg/mat_pow.hpp.html
title: linalg/mat_pow.hpp
---
