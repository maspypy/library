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
    path: mod/powertable.hpp
    title: mod/powertable.hpp
  - icon: ':question:'
    path: my_template.hpp
    title: my_template.hpp
  - icon: ':question:'
    path: nt/primetable.hpp
    title: nt/primetable.hpp
  - icon: ':heavy_check_mark:'
    path: poly/composition.hpp
    title: poly/composition.hpp
  - icon: ':heavy_check_mark:'
    path: poly/compositional_inverse.hpp
    title: poly/compositional_inverse.hpp
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
    path: poly/count_terms.hpp
    title: poly/count_terms.hpp
  - icon: ':question:'
    path: poly/differentiate.hpp
    title: poly/differentiate.hpp
  - icon: ':question:'
    path: poly/fft.hpp
    title: poly/fft.hpp
  - icon: ':question:'
    path: poly/fps_div.hpp
    title: poly/fps_div.hpp
  - icon: ':question:'
    path: poly/fps_exp.hpp
    title: poly/fps_exp.hpp
  - icon: ':question:'
    path: poly/fps_inv.hpp
    title: poly/fps_inv.hpp
  - icon: ':question:'
    path: poly/fps_log.hpp
    title: poly/fps_log.hpp
  - icon: ':question:'
    path: poly/fps_pow.hpp
    title: poly/fps_pow.hpp
  - icon: ':question:'
    path: poly/integrate.hpp
    title: poly/integrate.hpp
  - icon: ':question:'
    path: poly/ntt.hpp
    title: poly/ntt.hpp
  - icon: ':question:'
    path: poly/poly_taylor_shift.hpp
    title: poly/poly_taylor_shift.hpp
  - icon: ':question:'
    path: poly/power_projection.hpp
    title: poly/power_projection.hpp
  - icon: ':question:'
    path: poly/transposed_ntt.hpp
    title: poly/transposed_ntt.hpp
  - icon: ':question:'
    path: random/base.hpp
    title: random/base.hpp
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: https://judge.yosupo.jp/problem/aplusb
    links:
    - https://judge.yosupo.jp/problem/aplusb
  bundledCode: "#line 1 \"test/mytest/compositional_inverset.test.cpp\"\n#define PROBLEM\
    \ \"https://judge.yosupo.jp/problem/aplusb\"\n#line 1 \"my_template.hpp\"\n#if\
    \ defined(LOCAL)\n#include <my_template_compiled.hpp>\n#else\n\n// https://codeforces.com/blog/entry/96344\n\
    #pragma GCC optimize(\"Ofast,unroll-loops\")\n// \u3044\u307E\u306E CF \u3060\u3068\
    \u3053\u308C\u5165\u308C\u308B\u3068\u52D5\u304B\u306A\u3044\uFF1F\n// #pragma\
    \ GCC target(\"avx2,popcnt\")\n\n#include <bits/stdc++.h>\n\nusing namespace std;\n\
    \nusing ll = long long;\nusing u32 = unsigned int;\nusing u64 = unsigned long\
    \ long;\nusing i128 = __int128;\nusing u128 = unsigned __int128;\nusing f128 =\
    \ __float128;\n\ntemplate <class T>\nconstexpr T infty = 0;\ntemplate <>\nconstexpr\
    \ int infty<int> = 1'010'000'000;\ntemplate <>\nconstexpr ll infty<ll> = 2'020'000'000'000'000'000;\n\
    template <>\nconstexpr u32 infty<u32> = infty<int>;\ntemplate <>\nconstexpr u64\
    \ infty<u64> = infty<ll>;\ntemplate <>\nconstexpr i128 infty<i128> = i128(infty<ll>)\
    \ * 2'000'000'000'000'000'000;\ntemplate <>\nconstexpr double infty<double> =\
    \ infty<ll>;\ntemplate <>\nconstexpr long double infty<long double> = infty<ll>;\n\
    \nusing pi = pair<ll, ll>;\nusing vi = vector<ll>;\ntemplate <class T>\nusing\
    \ vc = vector<T>;\ntemplate <class T>\nusing vvc = vector<vc<T>>;\ntemplate <class\
    \ T>\nusing vvvc = vector<vvc<T>>;\ntemplate <class T>\nusing vvvvc = vector<vvvc<T>>;\n\
    template <class T>\nusing vvvvvc = vector<vvvvc<T>>;\ntemplate <class T>\nusing\
    \ pq = priority_queue<T>;\ntemplate <class T>\nusing pqg = priority_queue<T, vector<T>,\
    \ greater<T>>;\n\n#define vv(type, name, h, ...) \\\n  vector<vector<type>> name(h,\
    \ vector<type>(__VA_ARGS__))\n#define vvv(type, name, h, w, ...)   \\\n  vector<vector<vector<type>>>\
    \ name( \\\n      h, vector<vector<type>>(w, vector<type>(__VA_ARGS__)))\n#define\
    \ vvvv(type, name, a, b, c, ...)       \\\n  vector<vector<vector<vector<type>>>>\
    \ name( \\\n      a, vector<vector<vector<type>>>(       \\\n             b, vector<vector<type>>(c,\
    \ vector<type>(__VA_ARGS__))))\n\n// https://trap.jp/post/1224/\n#define FOR1(a)\
    \ for (ll _ = 0; _ < ll(a); ++_)\n#define FOR2(i, a) for (ll i = 0; i < ll(a);\
    \ ++i)\n#define FOR3(i, a, b) for (ll i = a; i < ll(b); ++i)\n#define FOR4(i,\
    \ a, b, c) for (ll i = a; i < ll(b); i += (c))\n#define FOR1_R(a) for (ll i =\
    \ (a)-1; i >= ll(0); --i)\n#define FOR2_R(i, a) for (ll i = (a)-1; i >= ll(0);\
    \ --i)\n#define FOR3_R(i, a, b) for (ll i = (b)-1; i >= ll(a); --i)\n#define overload4(a,\
    \ b, c, d, e, ...) e\n#define overload3(a, b, c, d, ...) d\n#define FOR(...) overload4(__VA_ARGS__,\
    \ FOR4, FOR3, FOR2, FOR1)(__VA_ARGS__)\n#define FOR_R(...) overload3(__VA_ARGS__,\
    \ FOR3_R, FOR2_R, FOR1_R)(__VA_ARGS__)\n\n#define FOR_subset(t, s) \\\n  for (ll\
    \ t = (s); t >= 0; t = (t == 0 ? -1 : (t - 1) & (s)))\n#define all(x) x.begin(),\
    \ x.end()\n#define len(x) ll(x.size())\n#define elif else if\n\n#define eb emplace_back\n\
    #define mp make_pair\n#define mt make_tuple\n#define fi first\n#define se second\n\
    \n#define stoi stoll\n\nint popcnt(int x) { return __builtin_popcount(x); }\n\
    int popcnt(u32 x) { return __builtin_popcount(x); }\nint popcnt(ll x) { return\
    \ __builtin_popcountll(x); }\nint popcnt(u64 x) { return __builtin_popcountll(x);\
    \ }\nint popcnt_mod_2(int x) { return __builtin_parity(x); }\nint popcnt_mod_2(u32\
    \ x) { return __builtin_parity(x); }\nint popcnt_mod_2(ll x) { return __builtin_parityll(x);\
    \ }\nint popcnt_mod_2(u64 x) { return __builtin_parityll(x); }\n// (0, 1, 2, 3,\
    \ 4) -> (-1, 0, 1, 1, 2)\nint topbit(int x) { return (x == 0 ? -1 : 31 - __builtin_clz(x));\
    \ }\nint topbit(u32 x) { return (x == 0 ? -1 : 31 - __builtin_clz(x)); }\nint\
    \ topbit(ll x) { return (x == 0 ? -1 : 63 - __builtin_clzll(x)); }\nint topbit(u64\
    \ x) { return (x == 0 ? -1 : 63 - __builtin_clzll(x)); }\n// (0, 1, 2, 3, 4) ->\
    \ (-1, 0, 1, 0, 2)\nint lowbit(int x) { return (x == 0 ? -1 : __builtin_ctz(x));\
    \ }\nint lowbit(u32 x) { return (x == 0 ? -1 : __builtin_ctz(x)); }\nint lowbit(ll\
    \ x) { return (x == 0 ? -1 : __builtin_ctzll(x)); }\nint lowbit(u64 x) { return\
    \ (x == 0 ? -1 : __builtin_ctzll(x)); }\n\ntemplate <typename T>\nT floor(T a,\
    \ T b) {\n  return a / b - (a % b && (a ^ b) < 0);\n}\ntemplate <typename T>\n\
    T ceil(T x, T y) {\n  return floor(x + y - 1, y);\n}\ntemplate <typename T>\n\
    T bmod(T x, T y) {\n  return x - y * floor(x, y);\n}\ntemplate <typename T>\n\
    pair<T, T> divmod(T x, T y) {\n  T q = floor(x, y);\n  return {q, x - q * y};\n\
    }\n\ntemplate <typename T, typename U>\nT SUM(const vector<U> &A) {\n  T sm =\
    \ 0;\n  for (auto &&a: A) sm += a;\n  return sm;\n}\n\n#define MIN(v) *min_element(all(v))\n\
    #define MAX(v) *max_element(all(v))\n#define LB(c, x) distance((c).begin(), lower_bound(all(c),\
    \ (x)))\n#define UB(c, x) distance((c).begin(), upper_bound(all(c), (x)))\n#define\
    \ UNIQUE(x) \\\n  sort(all(x)), x.erase(unique(all(x)), x.end()), x.shrink_to_fit()\n\
    \ntemplate <typename T>\nT POP(deque<T> &que) {\n  T a = que.front();\n  que.pop_front();\n\
    \  return a;\n}\ntemplate <typename T>\nT POP(pq<T> &que) {\n  T a = que.top();\n\
    \  que.pop();\n  return a;\n}\ntemplate <typename T>\nT POP(pqg<T> &que) {\n \
    \ T a = que.top();\n  que.pop();\n  return a;\n}\ntemplate <typename T>\nT POP(vc<T>\
    \ &que) {\n  T a = que.back();\n  que.pop_back();\n  return a;\n}\n\ntemplate\
    \ <typename F>\nll binary_search(F check, ll ok, ll ng, bool check_ok = true)\
    \ {\n  if (check_ok) assert(check(ok));\n  while (abs(ok - ng) > 1) {\n    auto\
    \ x = (ng + ok) / 2;\n    (check(x) ? ok : ng) = x;\n  }\n  return ok;\n}\ntemplate\
    \ <typename F>\ndouble binary_search_real(F check, double ok, double ng, int iter\
    \ = 100) {\n  FOR(iter) {\n    double x = (ok + ng) / 2;\n    (check(x) ? ok :\
    \ ng) = x;\n  }\n  return (ok + ng) / 2;\n}\n\ntemplate <class T, class S>\ninline\
    \ bool chmax(T &a, const S &b) {\n  return (a < b ? a = b, 1 : 0);\n}\ntemplate\
    \ <class T, class S>\ninline bool chmin(T &a, const S &b) {\n  return (a > b ?\
    \ a = b, 1 : 0);\n}\n\n// ? \u306F -1\nvc<int> s_to_vi(const string &S, char first_char)\
    \ {\n  vc<int> A(S.size());\n  FOR(i, S.size()) { A[i] = (S[i] != '?' ? S[i] -\
    \ first_char : -1); }\n  return A;\n}\n\ntemplate <typename T, typename U>\nvector<T>\
    \ cumsum(vector<U> &A, int off = 1) {\n  int N = A.size();\n  vector<T> B(N +\
    \ 1);\n  FOR(i, N) { B[i + 1] = B[i] + A[i]; }\n  if (off == 0) B.erase(B.begin());\n\
    \  return B;\n}\n\n// stable sort\ntemplate <typename T>\nvector<int> argsort(const\
    \ vector<T> &A) {\n  vector<int> ids(len(A));\n  iota(all(ids), 0);\n  sort(all(ids),\n\
    \       [&](int i, int j) { return (A[i] == A[j] ? i < j : A[i] < A[j]); });\n\
    \  return ids;\n}\n\n// A[I[0]], A[I[1]], ...\ntemplate <typename T>\nvc<T> rearrange(const\
    \ vc<T> &A, const vc<int> &I) {\n  vc<T> B(len(I));\n  FOR(i, len(I)) B[i] = A[I[i]];\n\
    \  return B;\n}\n\ntemplate <typename T, typename... Vectors>\nvc<T> concat(vc<T>\
    \ &first, const Vectors &... others) {\n  vc<T> res = first;\n  (res.insert(res.end(),\
    \ others.begin(), others.end()), ...);\n  return res;\n}\n#endif\n#line 3 \"test/mytest/compositional_inverset.test.cpp\"\
    \n\n#line 2 \"poly/differentiate.hpp\"\n\ntemplate <typename mint>\nvc<mint> differentiate(const\
    \ vc<mint>& f) {\n  if (len(f) <= 1) return {};\n  vc<mint> g(len(f) - 1);\n \
    \ FOR(i, len(g)) g[i] = f[i + 1] * mint(i + 1);\n  return g;\n}\n#line 2 \"poly/composition.hpp\"\
    \n\r\n#line 2 \"mod/modint_common.hpp\"\n\nstruct has_mod_impl {\n  template <class\
    \ T>\n  static auto check(T &&x) -> decltype(x.get_mod(), std::true_type{});\n\
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
    \ 31};\n    if (mod == 1004535809) return {21, 836905998};\n    if (mod == 1045430273)\
    \ return {20, 363};\n    if (mod == 1051721729) return {20, 330};\n    if (mod\
    \ == 1053818881) return {20, 2789};\n    return {-1, -1};\n  }\n  static constexpr\
    \ bool can_ntt() { return ntt_info().fi != -1; }\n};\n\n#ifdef FASTIO\ntemplate\
    \ <int mod>\nvoid rd(modint<mod> &x) {\n  fastio::rd(x.val);\n  x.val %= mod;\n\
    \  // assert(0 <= x.val && x.val < mod);\n}\ntemplate <int mod>\nvoid wt(modint<mod>\
    \ x) {\n  fastio::wt(x.val);\n}\n#endif\n\nusing modint107 = modint<1000000007>;\n\
    using modint998 = modint<998244353>;\n#line 2 \"mod/mod_inv.hpp\"\n\r\n// long\
    \ \u3067\u3082\u5927\u4E08\u592B\r\n// (val * x - 1) \u304C mod \u306E\u500D\u6570\
    \u306B\u306A\u308B\u3088\u3046\u306B\u3059\u308B\r\n// \u7279\u306B mod=0 \u306A\
    \u3089 x=0 \u304C\u6E80\u305F\u3059\r\nll mod_inv(ll val, ll mod) {\r\n  if (mod\
    \ == 0) return 0;\r\n  mod = abs(mod);\r\n  val %= mod;\r\n  if (val < 0) val\
    \ += mod;\r\n  ll a = val, b = mod, u = 1, v = 0, t;\r\n  while (b > 0) {\r\n\
    \    t = a / b;\r\n    swap(a -= t * b, b), swap(u -= t * v, v);\r\n  }\r\n  if\
    \ (u < 0) u += mod;\r\n  return u;\r\n}\r\n#line 2 \"mod/crt3.hpp\"\n\nconstexpr\
    \ u32 mod_pow_constexpr(u64 a, u64 n, u32 mod) {\n  a %= mod;\n  u64 res = 1;\n\
    \  FOR(32) {\n    if (n & 1) res = res * a % mod;\n    a = a * a % mod, n /= 2;\n\
    \  }\n  return res;\n}\n\ntemplate <typename T, u32 p0, u32 p1>\nT CRT2(u64 a0,\
    \ u64 a1) {\n  static_assert(p0 < p1);\n  static constexpr u64 x0_1 = mod_pow_constexpr(p0,\
    \ p1 - 2, p1);\n  u64 c = (a1 - a0 + p1) * x0_1 % p1;\n  return a0 + c * p0;\n\
    }\n\ntemplate <typename T, u32 p0, u32 p1, u32 p2>\nT CRT3(u64 a0, u64 a1, u64\
    \ a2) {\n  static_assert(p0 < p1 && p1 < p2);\n  static constexpr u64 x1 = mod_pow_constexpr(p0,\
    \ p1 - 2, p1);\n  static constexpr u64 x2 = mod_pow_constexpr(u64(p0) * p1 % p2,\
    \ p2 - 2, p2);\n  static constexpr u64 p01 = u64(p0) * p1;\n  u64 c = (a1 - a0\
    \ + p1) * x1 % p1;\n  u64 ans_1 = a0 + c * p0;\n  c = (a2 - ans_1 % p2 + p2) *\
    \ x2 % p2;\n  return T(ans_1) + T(c) * T(p01);\n}\n\ntemplate <typename T, u32\
    \ p0, u32 p1, u32 p2, u32 p3, u32 p4>\nT CRT5(u64 a0, u64 a1, u64 a2, u64 a3,\
    \ u64 a4) {\n  static_assert(p0 < p1 && p1 < p2 && p2 < p3 && p3 < p4);\n  static\
    \ constexpr u64 x1 = mod_pow_constexpr(p0, p1 - 2, p1);\n  static constexpr u64\
    \ x2 = mod_pow_constexpr(u64(p0) * p1 % p2, p2 - 2, p2);\n  static constexpr u64\
    \ x3\n      = mod_pow_constexpr(u64(p0) * p1 % p3 * p2 % p3, p3 - 2, p3);\n  static\
    \ constexpr u64 x4\n      = mod_pow_constexpr(u64(p0) * p1 % p4 * p2 % p4 * p3\
    \ % p4, p4 - 2, p4);\n  static constexpr u64 p01 = u64(p0) * p1;\n  static constexpr\
    \ u64 p23 = u64(p2) * p3;\n  u64 c = (a1 - a0 + p1) * x1 % p1;\n  u64 ans_1 =\
    \ a0 + c * p0;\n  c = (a2 - ans_1 % p2 + p2) * x2 % p2;\n  u128 ans_2 = ans_1\
    \ + c * static_cast<u128>(p01);\n  c = static_cast<u64>(a3 - ans_2 % p3 + p3)\
    \ * x3 % p3;\n  u128 ans_3 = ans_2 + static_cast<u128>(c * p2) * p01;\n  c = static_cast<u64>(a4\
    \ - ans_3 % p4 + p4) * x4 % p4;\n  return T(ans_3) + T(c) * T(p01) * T(p23);\n\
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
    \ b);\r\n  return convolution_garner(a, b);\r\n}\r\n#line 2 \"poly/poly_taylor_shift.hpp\"\
    \n\r\n#line 2 \"nt/primetable.hpp\"\n\ntemplate <typename T = int>\nvc<T> primetable(int\
    \ LIM) {\n  ++LIM;\n  const int S = 32768;\n  static int done = 2;\n  static vc<T>\
    \ primes = {2}, sieve(S + 1);\n\n  if (done < LIM) {\n    done = LIM;\n\n    primes\
    \ = {2}, sieve.assign(S + 1, 0);\n    const int R = LIM / 2;\n    primes.reserve(int(LIM\
    \ / log(LIM) * 1.1));\n    vc<pair<int, int>> cp;\n    for (int i = 3; i <= S;\
    \ i += 2) {\n      if (!sieve[i]) {\n        cp.eb(i, i * i / 2);\n        for\
    \ (int j = i * i; j <= S; j += 2 * i) sieve[j] = 1;\n      }\n    }\n    for (int\
    \ L = 1; L <= R; L += S) {\n      array<bool, S> block{};\n      for (auto& [p,\
    \ idx]: cp)\n        for (int i = idx; i < S + L; idx = (i += p)) block[i - L]\
    \ = 1;\n      FOR(i, min(S, R - L)) if (!block[i]) primes.eb((L + i) * 2 + 1);\n\
    \    }\n  }\n  int k = LB(primes, LIM + 1);\n  return {primes.begin(), primes.begin()\
    \ + k};\n}\n#line 3 \"mod/powertable.hpp\"\n\r\n// a^0, ..., a^N\r\ntemplate <typename\
    \ mint>\r\nvc<mint> powertable_1(mint a, ll N) {\r\n  // table of a^i\r\n  vc<mint>\
    \ f(N + 1, 1);\r\n  FOR(i, N) f[i + 1] = a * f[i];\r\n  return f;\r\n}\r\n\r\n\
    // 0^e, ..., N^e\r\ntemplate <typename mint>\r\nvc<mint> powertable_2(ll e, ll\
    \ N) {\r\n  auto primes = primetable(N);\r\n  vc<mint> f(N + 1, 1);\r\n  f[0]\
    \ = mint(0).pow(e);\r\n  for (auto&& p: primes) {\r\n    if (p > N) break;\r\n\
    \    mint xp = mint(p).pow(e);\r\n    ll pp = p;\r\n    while (pp <= N) {\r\n\
    \      ll i = pp;\r\n      while (i <= N) {\r\n        f[i] *= xp;\r\n       \
    \ i += pp;\r\n      }\r\n      pp *= p;\r\n    }\r\n  }\r\n  return f;\r\n}\r\n\
    #line 5 \"poly/poly_taylor_shift.hpp\"\n\r\n// f(x) -> f(x+c)\r\ntemplate <typename\
    \ mint>\r\nvc<mint> poly_taylor_shift(vc<mint> f, mint c) {\r\n  if (c == mint(0))\
    \ return f;\r\n  ll N = len(f);\r\n  FOR(i, N) f[i] *= fact<mint>(i);\r\n  auto\
    \ b = powertable_1<mint>(c, N);\r\n  FOR(i, N) b[i] *= fact_inv<mint>(i);\r\n\
    \  reverse(all(f));\r\n  f = convolution(f, b);\r\n  f.resize(N);\r\n  reverse(all(f));\r\
    \n  FOR(i, N) f[i] *= fact_inv<mint>(i);\r\n  return f;\r\n}\r\n#line 2 \"poly/transposed_ntt.hpp\"\
    \n\ntemplate <class mint>\nvoid transposed_ntt(vector<mint>& a, bool inverse)\
    \ {\n  assert(mint::can_ntt());\n  const int rank2 = mint::ntt_info().fi;\n  const\
    \ int mod = mint::get_mod();\n  static array<mint, 30> root, iroot;\n  static\
    \ array<mint, 30> rate2, irate2;\n  static array<mint, 30> rate3, irate3;\n\n\
    \  assert(rank2 != -1 && len(a) <= (1 << max(0, rank2)));\n\n  static bool prepared\
    \ = 0;\n  if (!prepared) {\n    prepared = 1;\n    root[rank2] = mint::ntt_info().se;\n\
    \    iroot[rank2] = mint(1) / root[rank2];\n    FOR_R(i, rank2) {\n      root[i]\
    \ = root[i + 1] * root[i + 1];\n      iroot[i] = iroot[i + 1] * iroot[i + 1];\n\
    \    }\n    mint prod = 1, iprod = 1;\n    for (int i = 0; i <= rank2 - 2; i++)\
    \ {\n      rate2[i] = root[i + 2] * prod;\n      irate2[i] = iroot[i + 2] * iprod;\n\
    \      prod *= iroot[i + 2];\n      iprod *= root[i + 2];\n    }\n    prod = 1,\
    \ iprod = 1;\n    for (int i = 0; i <= rank2 - 3; i++) {\n      rate3[i] = root[i\
    \ + 3] * prod;\n      irate3[i] = iroot[i + 3] * iprod;\n      prod *= iroot[i\
    \ + 3];\n      iprod *= root[i + 3];\n    }\n  }\n\n  int n = int(a.size());\n\
    \  int h = topbit(n);\n  assert(n == 1 << h);\n  if (!inverse) {\n    int len\
    \ = h;\n    while (len > 0) {\n      if (len == 1) {\n        int p = 1 << (h\
    \ - len);\n        mint rot = 1;\n        FOR(s, 1 << (len - 1)) {\n         \
    \ int offset = s << (h - len + 1);\n          FOR(i, p) {\n            u64 l =\
    \ a[i + offset].val;\n            u64 r = a[i + offset + p].val;\n           \
    \ a[i + offset] = l + r;\n            a[i + offset + p] = (mod + l - r) * rot.val;\n\
    \          }\n          rot *= rate2[topbit(~s & -~s)];\n        }\n        len--;\n\
    \      } else {\n        int p = 1 << (h - len);\n        mint rot = 1, imag =\
    \ root[2];\n        FOR(s, (1 << (len - 2))) {\n          int offset = s << (h\
    \ - len + 2);\n          mint rot2 = rot * rot;\n          mint rot3 = rot2 *\
    \ rot;\n          for (int i = 0; i < p; i++) {\n            u64 a0 = a[i + offset\
    \ + 0 * p].val;\n            u64 a1 = a[i + offset + 1 * p].val;\n           \
    \ u64 a2 = a[i + offset + 2 * p].val;\n            u64 a3 = a[i + offset + 3 *\
    \ p].val;\n            u64 x = (mod + a2 - a3) * imag.val % mod;\n           \
    \ a[i + offset] = a0 + a1 + a2 + a3;\n            a[i + offset + 1 * p] = (a0\
    \ + mod - a1 + x) * rot.val;\n            a[i + offset + 2 * p] = (a0 + a1 + 2\
    \ * mod - a2 - a3) * rot2.val;\n            a[i + offset + 3 * p] = (a0 + 2 *\
    \ mod - a1 - x) * rot3.val;\n          }\n          rot *= rate3[topbit(~s & -~s)];\n\
    \        }\n        len -= 2;\n      }\n    }\n  } else {\n    mint coef = mint(1)\
    \ / mint(len(a));\n    FOR(i, len(a)) a[i] *= coef;\n    int len = 0;\n    while\
    \ (len < h) {\n      if (len == h - 1) {\n        int p = 1 << (h - len - 1);\n\
    \        mint irot = 1;\n        FOR(s, 1 << len) {\n          int offset = s\
    \ << (h - len);\n          FOR(i, p) {\n            auto l = a[i + offset];\n\
    \            auto r = a[i + offset + p] * irot;\n            a[i + offset] = l\
    \ + r;\n            a[i + offset + p] = l - r;\n          }\n          irot *=\
    \ irate2[topbit(~s & -~s)];\n        }\n        len++;\n      } else {\n     \
    \   int p = 1 << (h - len - 2);\n        mint irot = 1, iimag = iroot[2];\n  \
    \      for (int s = 0; s < (1 << len); s++) {\n          mint irot2 = irot * irot;\n\
    \          mint irot3 = irot2 * irot;\n          int offset = s << (h - len);\n\
    \          for (int i = 0; i < p; i++) {\n            u64 mod2 = u64(mod) * mod;\n\
    \            u64 a0 = a[i + offset].val;\n            u64 a1 = u64(a[i + offset\
    \ + p].val) * irot.val;\n            u64 a2 = u64(a[i + offset + 2 * p].val) *\
    \ irot2.val;\n            u64 a3 = u64(a[i + offset + 3 * p].val) * irot3.val;\n\
    \            u64 a1na3imag = (a1 + mod2 - a3) % mod * iimag.val;\n           \
    \ u64 na2 = mod2 - a2;\n            a[i + offset] = a0 + a2 + a1 + a3;\n     \
    \       a[i + offset + 1 * p] = a0 + a2 + (2 * mod2 - (a1 + a3));\n          \
    \  a[i + offset + 2 * p] = a0 + na2 + a1na3imag;\n            a[i + offset + 3\
    \ * p] = a0 + na2 + (mod2 - a1na3imag);\n          }\n          irot *= irate3[topbit(~s\
    \ & -~s)];\n        }\n        len += 2;\n      }\n    }\n  }\n}\n#line 6 \"poly/composition.hpp\"\
    \n\r\ntemplate <typename mint>\r\nvc<mint> composition_old(vc<mint>& Q, vc<mint>&\
    \ P) {\r\n  int n = len(P);\r\n  assert(len(P) == len(Q));\r\n  int k = 1;\r\n\
    \  while (k * k < n) ++k;\r\n  // compute powers of P\r\n  vv(mint, pow1, k +\
    \ 1);\r\n  pow1[0] = {1};\r\n  pow1[1] = P;\r\n  FOR3(i, 2, k + 1) {\r\n    pow1[i]\
    \ = convolution(pow1[i - 1], pow1[1]);\r\n    pow1[i].resize(n);\r\n  }\r\n  vv(mint,\
    \ pow2, k + 1);\r\n  pow2[0] = {1};\r\n  pow2[1] = pow1[k];\r\n  FOR3(i, 2, k\
    \ + 1) {\r\n    pow2[i] = convolution(pow2[i - 1], pow2[1]);\r\n    pow2[i].resize(n);\r\
    \n  }\r\n  vc<mint> ANS(n);\r\n  FOR(i, k + 1) {\r\n    vc<mint> f(n);\r\n   \
    \ FOR(j, k) {\r\n      if (k * i + j < len(Q)) {\r\n        mint coef = Q[k *\
    \ i + j];\r\n        FOR(d, len(pow1[j])) f[d] += pow1[j][d] * coef;\r\n     \
    \ }\r\n    }\r\n    f = convolution(f, pow2[i]);\r\n    f.resize(n);\r\n    FOR(d,\
    \ n) ANS[d] += f[d];\r\n  }\r\n  return ANS;\r\n}\r\n\r\n// f(g(x)), O(Nlog^2N)\r\
    \ntemplate <typename mint>\r\nvc<mint> composition_0_ntt(vc<mint> f, vc<mint>\
    \ g) {\r\n  assert(len(f) == len(g));\r\n  if (f.empty()) return {};\r\n\r\n \
    \ int n0 = len(f);\r\n  int n = 1;\r\n  while (n < len(f)) n *= 2;\r\n  f.resize(n),\
    \ g.resize(n);\r\n\r\n  vc<mint> W(n);\r\n  {\r\n    // bit reverse order\r\n\
    \    vc<int> btr(n);\r\n    int log = topbit(n);\r\n    FOR(i, n) { btr[i] = (btr[i\
    \ >> 1] >> 1) + ((i & 1) << (log - 1)); }\r\n    int t = mint::ntt_info().fi;\r\
    \n    mint r = mint::ntt_info().se;\r\n    mint dw = r.inverse().pow((1 << t)\
    \ / (2 * n));\r\n    mint w = 1;\r\n    for (auto& i: btr) { W[i] = w, w *= dw;\
    \ }\r\n  }\r\n\r\n  auto rec = [&](auto& rec, int n, int k, vc<mint>& Q) -> vc<mint>\
    \ {\r\n    if (n == 1) {\r\n      reverse(all(f));\r\n      transposed_ntt(f,\
    \ 1);\r\n      mint c = mint(1) / mint(k);\r\n      for (auto& x: f) x *= c;\r\
    \n      vc<mint> p(4 * k);\r\n      FOR(i, k) p[2 * i] = f[i];\r\n      return\
    \ p;\r\n    }\r\n    auto doubling_y = [&](vc<mint>& A, int l, int r, bool t)\
    \ -> void {\r\n      mint z = W[k / 2].inverse();\r\n      vc<mint> f(k);\r\n\
    \      if (!t) {\r\n        FOR(i, l, r) {\r\n          FOR(j, k) f[j] = A[2 *\
    \ n * j + i];\r\n          ntt(f, 1);\r\n          mint r = 1;\r\n          FOR(j,\
    \ 1, k) r *= z, f[j] *= r;\r\n          ntt(f, 0);\r\n          FOR(j, k) A[2\
    \ * n * (k + j) + i] = f[j];\r\n        }\r\n      } else {\r\n        FOR(i,\
    \ l, r) {\r\n          FOR(j, k) f[j] = A[2 * n * (k + j) + i];\r\n          transposed_ntt(f,\
    \ 0);\r\n          mint r = 1;\r\n          FOR(j, 1, k) r *= z, f[j] *= r;\r\n\
    \          transposed_ntt(f, 1);\r\n          FOR(j, k) A[2 * n * j + i] += f[j];\r\
    \n        }\r\n      }\r\n    };\r\n\r\n    auto FFT_x = [&](vc<mint>& A, int\
    \ l, int r, bool t) -> void {\r\n      vc<mint> f(2 * n);\r\n      if (!t) {\r\
    \n        FOR(j, l, r) {\r\n          move(A.begin() + 2 * n * j, A.begin() +\
    \ 2 * n * (j + 1), f.begin());\r\n          ntt(f, 0);\r\n          move(all(f),\
    \ A.begin() + 2 * n * j);\r\n        }\r\n      } else {\r\n        FOR(j, l,\
    \ r) {\r\n          move(A.begin() + 2 * n * j, A.begin() + 2 * n * (j + 1), f.begin());\r\
    \n          transposed_ntt(f, 0);\r\n          move(all(f), A.begin() + 2 * n\
    \ * j);\r\n        }\r\n      }\r\n    };\r\n\r\n    if (n <= k) doubling_y(Q,\
    \ 1, n, 0), FFT_x(Q, 0, 2 * k, 0);\r\n    if (n > k) FFT_x(Q, 0, k, 0), doubling_y(Q,\
    \ 0, 2 * n, 0);\r\n\r\n    FOR(i, 2 * n * k) Q[i] += 1;\r\n    FOR(i, 2 * n *\
    \ k, 4 * n * k) Q[i] -= 1;\r\n\r\n    vc<mint> nxt_Q(4 * n * k);\r\n    vc<mint>\
    \ F(2 * n), G(2 * n), f(n), g(n);\r\n    FOR(j, 2 * k) {\r\n      move(Q.begin()\
    \ + 2 * n * j, Q.begin() + 2 * n * j + 2 * n, G.begin());\r\n      FOR(i, n) {\
    \ g[i] = G[2 * i] * G[2 * i + 1]; }\r\n      ntt(g, 1);\r\n      move(g.begin(),\
    \ g.begin() + n / 2, nxt_Q.begin() + n * j);\r\n    }\r\n    FOR(j, 4 * k) nxt_Q[n\
    \ * j] = 0;\r\n\r\n    vc<mint> p = rec(rec, n / 2, k * 2, nxt_Q);\r\n    FOR_R(j,\
    \ 2 * k) {\r\n      move(p.begin() + n * j, p.begin() + n * j + n / 2, f.begin());\r\
    \n      move(Q.begin() + 2 * n * j, Q.begin() + 2 * n * j + 2 * n, G.begin());\r\
    \n      fill(f.begin() + n / 2, f.end(), mint(0));\r\n      transposed_ntt(f,\
    \ 1);\r\n      FOR(i, n) {\r\n        f[i] *= W[i];\r\n        F[2 * i] = G[2\
    \ * i + 1] * f[i], F[2 * i + 1] = -G[2 * i] * f[i];\r\n      }\r\n      move(F.begin(),\
    \ F.end(), p.begin() + 2 * n * j);\r\n    }\r\n    if (n <= k) FFT_x(p, 0, 2 *\
    \ k, 1), doubling_y(p, 0, n, 1);\r\n    if (n > k) doubling_y(p, 0, 2 * n, 1),\
    \ FFT_x(p, 0, k, 1);\r\n    return p;\r\n  };\r\n\r\n  vc<mint> Q(4 * n);\r\n\
    \  FOR(i, n) Q[i] = -g[i];\r\n\r\n  vc<mint> p = rec(rec, n, 1, Q);\r\n  p.resize(n);\r\
    \n  reverse(all(p));\r\n  p.resize(n0);\r\n  return p;\r\n}\r\n\r\ntemplate <typename\
    \ mint>\r\nvc<mint> composition_0_garner(vc<mint> f, vc<mint> g) {\r\n  constexpr\
    \ u32 ps[] = {167772161, 469762049, 754974721};\r\n  using mint0 = modint<ps[0]>;\r\
    \n  using mint1 = modint<ps[1]>;\r\n  using mint2 = modint<ps[2]>;\r\n\r\n  auto\
    \ rec = [&](auto& rec, int n, int k, vc<mint> Q) -> vc<mint> {\r\n    if (n ==\
    \ 1) {\r\n      vc<mint> p(2 * k);\r\n      reverse(all(f));\r\n      FOR(i, k)\
    \ p[2 * i] = f[i];\r\n      return p;\r\n    }\r\n    vc<mint0> Q0(4 * n * k),\
    \ R0(4 * n * k), p0(4 * n * k);\r\n    vc<mint1> Q1(4 * n * k), R1(4 * n * k),\
    \ p1(4 * n * k);\r\n    vc<mint2> Q2(4 * n * k), R2(4 * n * k), p2(4 * n * k);\r\
    \n    FOR(i, 2 * n * k) {\r\n      Q0[i] = Q[i].val, R0[i] = (i % 2 == 0 ? Q[i].val\
    \ : (-Q[i]).val);\r\n      Q1[i] = Q[i].val, R1[i] = (i % 2 == 0 ? Q[i].val :\
    \ (-Q[i]).val);\r\n      Q2[i] = Q[i].val, R2[i] = (i % 2 == 0 ? Q[i].val : (-Q[i]).val);\r\
    \n    }\r\n    ntt(Q0, 0), ntt(Q1, 0), ntt(Q2, 0), ntt(R0, 0), ntt(R1, 0), ntt(R2,\
    \ 0);\r\n    FOR(i, 4 * n * k) Q0[i] *= R0[i], Q1[i] *= R1[i], Q2[i] *= R2[i];\r\
    \n    ntt(Q0, 1), ntt(Q1, 1), ntt(Q2, 1);\r\n    vc<mint> QQ(4 * n * k);\r\n \
    \   FOR(i, 4 * n * k) {\r\n      QQ[i] = CRT3<mint, ps[0], ps[1], ps[2]>(Q0[i].val,\
    \ Q1[i].val, Q2[i].val);\r\n    }\r\n    FOR(i, 0, 2 * n * k, 2) { QQ[2 * n *\
    \ k + i] += Q[i] + Q[i]; }\r\n    vc<mint> nxt_Q(2 * n * k);\r\n    FOR(j, 2 *\
    \ k) FOR(i, n / 2) {\r\n      nxt_Q[n * j + i] = QQ[(2 * n) * j + (2 * i + 0)];\r\
    \n    }\r\n\r\n    vc<mint> nxt_p = rec(rec, n / 2, k * 2, nxt_Q);\r\n    vc<mint>\
    \ pq(4 * n * k);\r\n    FOR(j, 2 * k) FOR(i, n / 2) {\r\n      pq[(2 * n) * j\
    \ + (2 * i + 1)] += nxt_p[n * j + i];\r\n    }\r\n\r\n    vc<mint> p(2 * n * k);\r\
    \n    FOR(i, 2 * n * k) { p[i] += pq[2 * n * k + i]; }\r\n    FOR(i, 4 * n * k)\
    \ {\r\n      p0[i] += pq[i].val, p1[i] += pq[i].val, p2[i] += pq[i].val;\r\n \
    \   }\r\n    transposed_ntt(p0, 1), transposed_ntt(p1, 1), transposed_ntt(p2,\
    \ 1);\r\n    FOR(i, 4 * n * k) p0[i] *= R0[i], p1[i] *= R1[i], p2[i] *= R2[i];\r\
    \n    transposed_ntt(p0, 0), transposed_ntt(p1, 0), transposed_ntt(p2, 0);\r\n\
    \    FOR(i, 2 * n * k) {\r\n      p[i] += CRT3<mint, ps[0], ps[1], ps[2]>(p0[i].val,\
    \ p1[i].val, p2[i].val);\r\n    }\r\n    return p;\r\n  };\r\n  assert(len(f)\
    \ == len(g));\r\n  int n = 1;\r\n  while (n < len(f)) n *= 2;\r\n  int out_len\
    \ = len(f);\r\n  f.resize(n), g.resize(n);\r\n  int k = 1;\r\n  vc<mint> Q(2 *\
    \ n);\r\n  FOR(i, n) Q[i] = -g[i];\r\n  vc<mint> p = rec(rec, n, k, Q);\r\n\r\n\
    \  vc<mint> output(n);\r\n  FOR(i, n) output[i] = p[i];\r\n  reverse(all(output));\r\
    \n  output.resize(out_len);\r\n  return output;\r\n}\r\n\r\ntemplate <typename\
    \ mint>\r\nvc<mint> composition(vc<mint> f, vc<mint> g) {\r\n  assert(len(f) ==\
    \ len(g));\r\n  if (f.empty()) return {};\r\n  // [x^0]g=0 \u306B\u5E30\u7740\u3057\
    \u3066\u304A\u304F\r\n  if (g[0] != mint(0)) {\r\n    f = poly_taylor_shift<mint>(f,\
    \ g[0]);\r\n    g[0] = 0;\r\n  }\r\n  if (mint::can_ntt()) { return composition_0_ntt(f,\
    \ g); }\r\n  return composition_0_garner(f, g);\r\n}\r\n#line 2 \"poly/fps_div.hpp\"\
    \n\n#line 2 \"poly/count_terms.hpp\"\ntemplate<typename mint>\r\nint count_terms(const\
    \ vc<mint>& f){\r\n  int t = 0;\r\n  FOR(i, len(f)) if(f[i] != mint(0)) ++t;\r\
    \n  return t;\r\n}\n#line 4 \"poly/fps_inv.hpp\"\n\r\ntemplate <typename mint>\r\
    \nvc<mint> fps_inv_sparse(const vc<mint>& f) {\r\n  int N = len(f);\r\n  vc<pair<int,\
    \ mint>> dat;\r\n  FOR(i, 1, N) if (f[i] != mint(0)) dat.eb(i, f[i]);\r\n  vc<mint>\
    \ g(N);\r\n  mint g0 = mint(1) / f[0];\r\n  g[0] = g0;\r\n  FOR(n, 1, N) {\r\n\
    \    mint rhs = 0;\r\n    for (auto&& [k, fk]: dat) {\r\n      if (k > n) break;\r\
    \n      rhs -= fk * g[n - k];\r\n    }\r\n    g[n] = rhs * g0;\r\n  }\r\n  return\
    \ g;\r\n}\r\n\r\ntemplate <typename mint>\r\nvc<mint> fps_inv_dense_ntt(const\
    \ vc<mint>& F) {\r\n  vc<mint> G = {mint(1) / F[0]};\r\n  ll N = len(F), n = 1;\r\
    \n  G.reserve(N);\r\n  while (n < N) {\r\n    vc<mint> f(2 * n), g(2 * n);\r\n\
    \    FOR(i, min(N, 2 * n)) f[i] = F[i];\r\n    FOR(i, n) g[i] = G[i];\r\n    ntt(f,\
    \ false), ntt(g, false);\r\n    FOR(i, 2 * n) f[i] *= g[i];\r\n    ntt(f, true);\r\
    \n    FOR(i, n) f[i] = 0;\r\n    ntt(f, false);\r\n    FOR(i, 2 * n) f[i] *= g[i];\r\
    \n    ntt(f, true);\r\n    FOR(i, n, min(N, 2 * n)) G.eb(-f[i]);\r\n    n *= 2;\r\
    \n  }\r\n  return G;\r\n}\r\n\r\ntemplate <typename mint>\r\nvc<mint> fps_inv_dense(const\
    \ vc<mint>& F) {\r\n  if (mint::can_ntt()) return fps_inv_dense_ntt(F);\r\n  const\
    \ int N = len(F);\r\n  vc<mint> R = {mint(1) / F[0]};\r\n  vc<mint> p;\r\n  int\
    \ m = 1;\r\n  while (m < N) {\r\n    p = convolution(R, R);\r\n    p.resize(m\
    \ + m);\r\n    vc<mint> f = {F.begin(), F.begin() + min(m + m, N)};\r\n    p =\
    \ convolution(p, f);\r\n    R.resize(m + m);\r\n    FOR(i, m + m) R[i] = R[i]\
    \ + R[i] - p[i];\r\n    m += m;\r\n  }\r\n  R.resize(N);\r\n  return R;\r\n}\r\
    \n\r\ntemplate <typename mint>\r\nvc<mint> fps_inv(const vc<mint>& f) {\r\n  assert(f[0]\
    \ != mint(0));\r\n  int n = count_terms(f);\r\n  int t = (mint::can_ntt() ? 160\
    \ : 820);\r\n  return (n <= t ? fps_inv_sparse<mint>(f) : fps_inv_dense<mint>(f));\r\
    \n}\r\n#line 5 \"poly/fps_div.hpp\"\n\n// f/g. f \u306E\u9577\u3055\u3067\u51FA\
    \u529B\u3055\u308C\u308B.\ntemplate <typename mint, bool SPARSE = false>\nvc<mint>\
    \ fps_div(vc<mint> f, vc<mint> g) {\n  if (SPARSE || count_terms(g) < 200) return\
    \ fps_div_sparse(f, g);\n  int n = len(f);\n  g.resize(n);\n  g = fps_inv<mint>(g);\n\
    \  f = convolution(f, g);\n  f.resize(n);\n  return f;\n}\n\n// f/g \u305F\u3060\
    \u3057 g \u306F sparse\ntemplate <typename mint>\nvc<mint> fps_div_sparse(vc<mint>\
    \ f, vc<mint>& g) {\n  if (g[0] != mint(1)) {\n    mint cf = g[0].inverse();\n\
    \    for (auto&& x: f) x *= cf;\n    for (auto&& x: g) x *= cf;\n  }\n\n  vc<pair<int,\
    \ mint>> dat;\n  FOR(i, 1, len(g)) if (g[i] != mint(0)) dat.eb(i, -g[i]);\n  FOR(i,\
    \ len(f)) {\n    for (auto&& [j, x]: dat) {\n      if (i >= j) f[i] += x * f[i\
    \ - j];\n    }\n  }\n  return f;\n}\n#line 2 \"poly/integrate.hpp\"\n\n// \u4E0D\
    \u5B9A\u7A4D\u5206\uFF1Aintegrate(f)\n// \u5B9A\u7A4D\u5206\uFF1Aintegrate(f,\
    \ L, R)\ntemplate <typename mint>\nvc<mint> integrate(const vc<mint>& f) {\n \
    \ vc<mint> g(len(f) + 1);\n  FOR3(i, 1, len(g)) g[i] = f[i - 1] * inv<mint>(i);\n\
    \  return g;\n}\n\n// \u4E0D\u5B9A\u7A4D\u5206\uFF1Aintegrate(f)\n// \u5B9A\u7A4D\
    \u5206\uFF1Aintegrate(f, L, R)\ntemplate <typename mint>\nmint integrate(const\
    \ vc<mint>& f, mint L, mint R) {\n  mint I = 0;\n  mint pow_L = 1, pow_R = 1;\n\
    \  FOR(i, len(f)) {\n    pow_L *= L, pow_R *= R;\n    I += inv<mint>(i + 1) *\
    \ f[i] * (pow_R - pow_L);\n  }\n  return I;\n}\n#line 6 \"poly/fps_exp.hpp\"\n\
    \r\ntemplate <typename mint>\r\nvc<mint> fps_exp_sparse(vc<mint>& f) {\r\n  if\
    \ (len(f) == 0) return {mint(1)};\r\n  assert(f[0] == 0);\r\n  int N = len(f);\r\
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
    \ : fps_exp_dense<mint>(f));\r\n}\r\n#line 2 \"poly/fps_log.hpp\"\n\r\n#line 5\
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
    \ (n <= t ? fps_log_sparse<mint>(f) : fps_log_dense<mint>(f));\r\n}\r\n#line 5\
    \ \"poly/fps_pow.hpp\"\n\r\n// fps \u306E k \u4E57\u3092\u6C42\u3081\u308B\u3002\
    k >= 0 \u306E\u524D\u63D0\u3067\u3042\u308B\u3002\r\n// \u5B9A\u6570\u9805\u304C\
    \ 1 \u3067\u3001k \u304C mint \u306E\u5834\u5408\u306B\u306F\u3001fps_pow_1 \u3092\
    \u4F7F\u3046\u3053\u3068\u3002\r\n// \u30FBdense \u306A\u5834\u5408\uFF1A log,\
    \ exp \u3092\u4F7F\u3046 O(NlogN)\r\n// \u30FBsparse \u306A\u5834\u5408\uFF1A\
    \ O(NK)\r\ntemplate <typename mint>\r\nvc<mint> fps_pow(const vc<mint>& f, ll\
    \ k) {\r\n  assert(0 <= k);\r\n  int n = len(f);\r\n  if (k == 0) {\r\n    vc<mint>\
    \ g(n);\r\n    g[0] = mint(1);\r\n    return g;\r\n  }\r\n  int d = n;\r\n  FOR_R(i,\
    \ n) if (f[i] != 0) d = i;\r\n  // d * k >= n\r\n  if (d >= ceil<ll>(n, k)) {\r\
    \n    vc<mint> g(n);\r\n    return g;\r\n  }\r\n  ll off = d * k;\r\n  mint c\
    \ = f[d];\r\n  mint c_inv = mint(1) / mint(c);\r\n  vc<mint> g(n - off);\r\n \
    \ FOR(i, n - off) g[i] = f[d + i] * c_inv;\r\n  g = fps_pow_1(g, mint(k));\r\n\
    \  vc<mint> h(n);\r\n  c = c.pow(k);\r\n  FOR(i, len(g)) h[off + i] = g[i] * c;\r\
    \n  return h;\r\n}\r\n\r\ntemplate <typename mint>\r\nvc<mint> fps_pow_1_sparse(const\
    \ vc<mint>& f, mint K) {\r\n  int N = len(f);\r\n  assert(N == 0 || f[0] == mint(1));\r\
    \n  vc<pair<int, mint>> dat;\r\n  FOR(i, 1, N) if (f[i] != mint(0)) dat.eb(i,\
    \ f[i]);\r\n  vc<mint> g(N);\r\n  g[0] = 1;\r\n  FOR(n, N - 1) {\r\n    mint&\
    \ x = g[n + 1];\r\n    for (auto&& [d, cf]: dat) {\r\n      if (d > n + 1) break;\r\
    \n      mint t = cf * g[n - d + 1];\r\n      x += t * (K * mint(d) - mint(n -\
    \ d + 1));\r\n    }\r\n    x *= inv<mint>(n + 1);\r\n  }\r\n  return g;\r\n}\r\
    \n\r\ntemplate <typename mint>\r\nvc<mint> fps_pow_1_dense(const vc<mint>& f,\
    \ mint K) {\r\n  assert(f[0] == mint(1));\r\n  auto log_f = fps_log(f);\r\n  FOR(i,\
    \ len(f)) log_f[i] *= K;\r\n  return fps_exp_dense(log_f);\r\n}\r\n\r\ntemplate\
    \ <typename mint>\r\nvc<mint> fps_pow_1(const vc<mint>& f, mint K) {\r\n  int\
    \ n = count_terms(f);\r\n  int t = (mint::can_ntt() ? 100 : 1300);\r\n  return\
    \ (n <= t ? fps_pow_1_sparse(f, K) : fps_pow_1_dense(f, K));\r\n}\r\n\r\n// f^e,\
    \ sparse, O(NMK)\r\ntemplate <typename mint>\r\nvvc<mint> fps_pow_1_sparse_2d(vvc<mint>\
    \ f, mint n) {\r\n  assert(f[0][0] == mint(1));\r\n  int N = len(f), M = len(f[0]);\r\
    \n  vv(mint, dp, N, M);\r\n  dp[0] = fps_pow_1_sparse<mint>(f[0], n);\r\n\r\n\
    \  vc<tuple<int, int, mint>> dat;\r\n  FOR(i, N) FOR(j, M) {\r\n    if ((i > 0\
    \ || j > 0) && f[i][j] != mint(0)) dat.eb(i, j, f[i][j]);\r\n  }\r\n  FOR(i, 1,\
    \ N) {\r\n    FOR(j, M) {\r\n      // F = f^n, f dF = n df F\r\n      // [x^{i-1}y^j]\r\
    \n      mint lhs = 0, rhs = 0;\r\n      for (auto&& [a, b, c]: dat) {\r\n    \
    \    if (a < i && b <= j) lhs += dp[i - a][j - b] * mint(i - a);\r\n        if\
    \ (a <= i && b <= j) rhs += dp[i - a][j - b] * c * mint(a);\r\n      }\r\n   \
    \   dp[i][j] = (n * rhs - lhs) * inv<mint>(i);\r\n    }\r\n  }\r\n  return dp;\r\
    \n}\r\n#line 2 \"poly/power_projection.hpp\"\n\n#line 4 \"poly/power_projection.hpp\"\
    \n\ntemplate <typename mint>\nvc<mint> power_projection_0_ntt(vc<mint> wt, vc<mint>\
    \ f, int m) {\n  assert(len(f) == len(wt) && f[0] == mint(0));\n\n  int n = 1;\n\
    \  while (n < len(f)) n *= 2;\n\n  for (auto& x: f) x = -x;\n  f.resize(n), wt.resize(n);\n\
    \  reverse(all(wt));\n  vc<mint>&P = wt, &Q = f;\n  P.resize(4 * n), Q.resize(4\
    \ * n);\n\n  vc<mint> W(n);\n  {\n    // bit reverse order\n    vc<int> btr(n);\n\
    \    int log = topbit(n);\n    FOR(i, n) { btr[i] = (btr[i >> 1] >> 1) + ((i &\
    \ 1) << (log - 1)); }\n    int t = mint::ntt_info().fi;\n    mint r = mint::ntt_info().se;\n\
    \    mint dw = r.inverse().pow((1 << t) / (2 * n));\n    mint w = 1;\n    for\
    \ (auto& i: btr) { W[i] = w, w *= dw; }\n  }\n\n  int k = 1;\n  while (n > 1)\
    \ {\n    /*\n    FFT step\n    04.. -> 048c\n    15.. -> 159d\n    .... -> 26ae\n\
    \    .... -> 37bf\n    */\n\n    auto doubling_y = [&](vc<mint>& A, int l, int\
    \ r) -> void {\n      mint z = W[k / 2].inverse();\n      vc<mint> f(k);\n   \
    \   FOR(i, l, r) {\n        FOR(j, k) f[j] = A[2 * n * j + i];\n        ntt(f,\
    \ 1);\n        mint r = 1;\n        FOR(j, 1, k) r *= z, f[j] *= r;\n        ntt(f,\
    \ 0);\n        FOR(j, k) A[2 * n * (k + j) + i] = f[j];\n      }\n    };\n\n \
    \   auto FFT_x = [&](vc<mint>& A, int l, int r) -> void {\n      vc<mint> f(2\
    \ * n);\n      FOR(j, l, r) {\n        move(A.begin() + 2 * n * j, A.begin() +\
    \ 2 * n * (j + 1), f.begin());\n        ntt(f, 0);\n        move(all(f), A.begin()\
    \ + 2 * n * j);\n      }\n    };\n\n    if (n <= k) {\n      doubling_y(P, 0,\
    \ n), doubling_y(Q, 1, n);\n      FFT_x(P, 0, 2 * k), FFT_x(Q, 0, 2 * k);\n  \
    \  } else {\n      FFT_x(P, 0, k), FFT_x(Q, 0, k);\n      doubling_y(P, 0, 2 *\
    \ n), doubling_y(Q, 0, 2 * n);\n    }\n    FOR(i, 2 * n * k) Q[i] += 1;\n    FOR(i,\
    \ 2 * n * k, 4 * n * k) Q[i] -= 1;\n\n    /*\n    048c -> 0248????\n    159d ->\
    \ ....????\n    26ae\n    37bf\n    */\n    vc<mint> F(2 * n), G(2 * n), f(n),\
    \ g(n);\n    FOR(j, 2 * k) {\n      move(P.begin() + 2 * n * j, P.begin() + 2\
    \ * n * j + 2 * n, F.begin());\n      move(Q.begin() + 2 * n * j, Q.begin() +\
    \ 2 * n * j + 2 * n, G.begin());\n      FOR(i, n) {\n        f[i] = W[i] * (F[2\
    \ * i] * G[2 * i + 1] - F[2 * i + 1] * G[2 * i]);\n        g[i] = G[2 * i] * G[2\
    \ * i + 1];\n      }\n      ntt(f, 1), ntt(g, 1);\n      fill(f.begin() + n /\
    \ 2, f.end(), mint(0));\n      fill(g.begin() + n / 2, g.end(), mint(0));\n  \
    \    move(all(f), P.begin() + n * j);\n      move(all(g), Q.begin() + n * j);\n\
    \    }\n    fill(P.begin() + 2 * n * k, P.end(), mint(0));\n    fill(Q.begin()\
    \ + 2 * n * k, Q.end(), mint(0));\n    FOR(j, 4 * k) Q[n * j] = 0;\n    n /= 2,\
    \ k *= 2;\n  }\n  FOR(i, k) P[i] = P[2 * i];\n  P.resize(k);\n  mint c = mint(1)\
    \ / mint(k);\n  for (auto& x: P) x *= c;\n  ntt(P, 1);\n  reverse(all(P));\n \
    \ P.resize(m + 1);\n  return P;\n}\n\n// \\sum_j[x^j]f^i \u3092 i=0,1,...,m\n\
    template <typename mint>\nvc<mint> power_projection_0_garner(vc<mint> wt, vc<mint>\
    \ f, int m) {\n  assert(len(f) == len(wt) && f[0] == mint(0));\n  int n = 1;\n\
    \  while (n < len(f)) n *= 2;\n  f.resize(n), wt.resize(n);\n  reverse(all(wt));\n\
    \n  constexpr u32 p[] = {167772161, 469762049, 754974721};\n  using mint0 = modint<p[0]>;\n\
    \  using mint1 = modint<p[1]>;\n  using mint2 = modint<p[2]>;\n  vc<mint0> W0(2\
    \ * n);\n  vc<mint1> W1(2 * n);\n  vc<mint2> W2(2 * n);\n  {\n    // bit reverse\
    \ order\n    vc<int> btr(2 * n);\n    int log = topbit(2 * n);\n    FOR(i, 2 *\
    \ n) { btr[i] = (btr[i >> 1] >> 1) + ((i & 1) << (log - 1)); }\n    {\n      int\
    \ t = mint0::ntt_info().fi;\n      mint0 r = mint0::ntt_info().se;\n      mint0\
    \ dw = r.inverse().pow((1 << t) / (4 * n));\n      mint0 w = 1;\n      for (auto&\
    \ i: btr) { W0[i] = w, w *= dw; }\n    }\n    {\n      int t = mint1::ntt_info().fi;\n\
    \      mint1 r = mint1::ntt_info().se;\n      mint1 dw = r.inverse().pow((1 <<\
    \ t) / (4 * n));\n      mint1 w = 1;\n      for (auto& i: btr) { W1[i] = w, w\
    \ *= dw; }\n    }\n    {\n      int t = mint2::ntt_info().fi;\n      mint2 r =\
    \ mint2::ntt_info().se;\n      mint2 dw = r.inverse().pow((1 << t) / (4 * n));\n\
    \      mint2 w = 1;\n      for (auto& i: btr) { W2[i] = w, w *= dw; }\n    }\n\
    \  }\n\n  int k = 1;\n  vc<mint> P(2 * n), Q(2 * n);\n  FOR(i, n) P[i] = wt[i],\
    \ Q[i] = -f[i];\n\n  while (n > 1) {\n    vc<mint0> P0(4 * n * k), Q0(4 * n *\
    \ k);\n    vc<mint1> P1(4 * n * k), Q1(4 * n * k);\n    vc<mint2> P2(4 * n * k),\
    \ Q2(4 * n * k);\n    FOR(i, 2 * n * k) P0[i] = P[i].val, Q0[i] = Q[i].val;\n\
    \    FOR(i, 2 * n * k) P1[i] = P[i].val, Q1[i] = Q[i].val;\n    FOR(i, 2 * n *\
    \ k) P2[i] = P[i].val, Q2[i] = Q[i].val;\n    Q0[2 * n * k] = 1, Q1[2 * n * k]\
    \ = 1, Q2[2 * n * k] = 1;\n    ntt(P0, 0), ntt(Q0, 0), ntt(P1, 0), ntt(Q1, 0),\
    \ ntt(P2, 0), ntt(Q2, 0);\n    FOR(i, 2 * n * k) {\n      P0[i] = inv<mint0>(2)\
    \ * W0[i]\n              * (P0[2 * i] * Q0[2 * i + 1] - P0[2 * i + 1] * Q0[2 *\
    \ i]);\n      Q0[i] = Q0[2 * i] * Q0[2 * i + 1];\n      P1[i] = inv<mint1>(2)\
    \ * W1[i]\n              * (P1[2 * i] * Q1[2 * i + 1] - P1[2 * i + 1] * Q1[2 *\
    \ i]);\n      Q1[i] = Q1[2 * i] * Q1[2 * i + 1];\n      P2[i] = inv<mint2>(2)\
    \ * W2[i]\n              * (P2[2 * i] * Q2[2 * i + 1] - P2[2 * i + 1] * Q2[2 *\
    \ i]);\n      Q2[i] = Q2[2 * i] * Q2[2 * i + 1];\n    }\n    P0.resize(2 * n *\
    \ k), Q0.resize(2 * n * k);\n    P1.resize(2 * n * k), Q1.resize(2 * n * k);\n\
    \    P2.resize(2 * n * k), Q2.resize(2 * n * k);\n    ntt(P0, 1), ntt(Q0, 1),\
    \ ntt(P1, 1), ntt(Q1, 1), ntt(P2, 1), ntt(Q2, 1);\n\n    constexpr i128 K = u128(p[0])\
    \ * p[1] * p[2];\n    auto get = [&](mint0 a, mint1 b, mint2 c) -> mint {\n  \
    \    i128 x = CRT3<u128, p[0], p[1], p[2]>(a.val, b.val, c.val);\n      i128 y\
    \ = K - x;\n      return (x < y ? mint(x) : -mint(y));\n    };\n\n    fill(all(P),\
    \ mint(0));\n    fill(all(Q), mint(0));\n    FOR(j, 2 * k) FOR(i, n / 2) {\n \
    \     int k = n * j + i;\n      P[k] = get(P0[k], P1[k], P2[k]);\n      Q[k] =\
    \ get(Q0[k], Q1[k], Q2[k]);\n    }\n    Q[0] = 0;\n    n /= 2, k *= 2;\n  }\n\
    \  vc<mint> F(k);\n  FOR(i, k) F[i] = P[2 * i];\n  reverse(all(F));\n  F.resize(m\
    \ + 1);\n  return F;\n}\n\n// \\sum_j[x^j]f^i \u3092 i=0,1,...,m\ntemplate <typename\
    \ mint>\nvc<mint> power_projection(vc<mint> wt, vc<mint> f, int m) {\n  assert(len(f)\
    \ == len(wt));\n  if (f.empty()) { return vc<mint>(m + 1, mint(0)); }\n  if (f[0]\
    \ != mint(0)) {\n    mint c = f[0];\n    f[0] = 0;\n    vc<mint> A = power_projection(wt,\
    \ f, m);\n    FOR(p, m + 1) A[p] *= fact_inv<mint>(p);\n    vc<mint> B(m + 1);\n\
    \    mint pow = 1;\n    FOR(q, m + 1) B[q] = pow * fact_inv<mint>(q), pow *= c;\n\
    \    A = convolution<mint>(A, B);\n    A.resize(m + 1);\n    FOR(i, m + 1) A[i]\
    \ *= fact<mint>(i);\n    return A;\n  }\n  if (mint::can_ntt()) { return power_projection_0_ntt(wt,\
    \ f, m); }\n  return power_projection_0_garner(wt, f, m);\n}\n#line 6 \"poly/compositional_inverse.hpp\"\
    \n\n// O(N^2)\ntemplate <typename mint>\nvc<mint> compositional_inverse_old(const\
    \ vc<mint>& F) {\n  const int N = len(F);\n  if (N == 0) return {};\n  assert(F[0]\
    \ == mint(0));\n  if (N == 1) return F;\n  assert(F[0] == mint(0) && F[1] != mint(0));\n\
    \  vc<mint> DF = differentiate(F);\n\n  vc<mint> G(2);\n  G[1] = mint(1) / F[1];\n\
    \  while (len(G) < N) {\n    // G:= G(x)-(F(G(x))-x)/DF(G(x))\n    int n = len(G);\n\
    \    vc<mint> G1, G2;\n    {\n      vc<mint> FF(2 * n), GG(2 * n), DFF(n);\n \
    \     FOR(i, min<int>(len(F), 2 * n)) FF[i] = F[i];\n      FOR(i, min<int>(len(DF),\
    \ n)) DFF[i] = DF[i];\n      FOR(i, n) GG[i] = G[i];\n      G1 = composition(FF,\
    \ GG);\n      G2 = composition(DFF, G);\n    }\n    G1 = {G1.begin() + n, G1.end()};\n\
    \    G1 = fps_div(G1, G2);\n    G.resize(2 * n);\n    FOR(i, n) G[n + i] -= G1[i];\n\
    \  }\n  G.resize(N);\n  return G;\n}\n\ntemplate <typename mint>\nvc<mint> compositional_inverse(vc<mint>\
    \ f) {\n  const int n = len(f) - 1;\n  if (n == -1) return {};\n  assert(f[0]\
    \ == mint(0));\n  if (n == 0) return f;\n  assert(f[1] != mint(0));\n  mint c\
    \ = f[1];\n  mint ic = c.inverse();\n  for (auto& x: f) x *= ic;\n  vc<mint> wt(n\
    \ + 1);\n  wt[n] = 1;\n\n  vc<mint> A = power_projection<mint>(wt, f, n);\n  vc<mint>\
    \ g(n);\n  FOR(i, 1, n + 1) g[n - i] = mint(n) * A[i] * inv<mint>(i);\n  g = fps_pow_1<mint>(g,\
    \ -inv<mint>(n));\n  g.insert(g.begin(), 0);\n\n  mint pow = 1;\n  FOR(i, len(g))\
    \ g[i] *= pow, pow *= ic;\n  return g;\n}\n\n// G->F(G), G->DF(G) \u3092\u4E0E\
    \u3048\u308B\n// len(G) \u307E\u3067\u6C42\u3081\u308B. len(F) \u307E\u3067\u6C42\
    \u3081\u3066\u3082\u3044\u3044\u3088.\n// \u8A08\u7B97\u91CF\u306F\u5408\u6210\
    \u3068\u3060\u3044\u305F\u3044\u540C\u7B49\ntemplate <typename mint, typename\
    \ F1, typename F2>\nvc<mint> compositional_inverse(const vc<mint>& F, F1 comp_F,\
    \ F2 comp_DF) {\n  const int N = len(F);\n  assert(N <= 0 || F[0] == mint(0));\n\
    \  assert(N <= 1 || F[1] != mint(0));\n\n  vc<mint> G(2);\n  G[1] = mint(1) /\
    \ F[1];\n  while (len(G) < N) {\n    int n = len(G);\n    // G:= G(x)-(F(G(x))-x)/DF(G(x))\n\
    \    vc<mint> G2 = comp_DF(G);\n    G.resize(2 * n);\n    vc<mint> G1 = comp_F(G);\n\
    \    G1 = {G1.begin() + n, G1.end()};\n    G1 = fps_div(G1, G2);\n    FOR(i, n)\
    \ G[n + i] -= G1[i];\n  }\n  G.resize(N);\n  return G;\n}\n#line 2 \"random/base.hpp\"\
    \n\nu64 RNG_64() {\n  static uint64_t x_\n      = uint64_t(chrono::duration_cast<chrono::nanoseconds>(\n\
    \                     chrono::high_resolution_clock::now().time_since_epoch())\n\
    \                     .count())\n        * 10150724397891781847ULL;\n  x_ ^= x_\
    \ << 7;\n  return x_ ^= x_ >> 9;\n}\n\nu64 RNG(u64 lim) { return RNG_64() % lim;\
    \ }\n\nll RNG(ll l, ll r) { return l + RNG_64() % (r - l); }\n#line 6 \"test/mytest/compositional_inverset.test.cpp\"\
    \n\nusing mint = modint998;\n\nvoid test() {\n  FOR(N, 100) {\n    vc<mint> f(N);\n\
    \    FOR(i, 1, N) f[i] = RNG(1, 10);\n    vc<mint> A = compositional_inverse<mint>(f);\n\
    \    vc<mint> B = compositional_inverse_old<mint>(f);\n    assert(A == B);\n \
    \   vc<mint> F = composition<mint>(f, A);\n    vc<mint> G = composition<mint>(A,\
    \ f);\n    FOR(i, N) {\n      if (i == 1) {\n        assert(F[i] == mint(1));\n\
    \        assert(G[i] == mint(1));\n      } else {\n        assert(F[i] == mint(0));\n\
    \        assert(G[i] == mint(0));\n      }\n    }\n  }\n}\n\nvoid solve() {\n\
    \  int a, b;\n  cin >> a >> b;\n  cout << a + b << \"\\n\";\n}\n\nsigned main()\
    \ {\n  test();\n  solve();\n}\n"
  code: "#define PROBLEM \"https://judge.yosupo.jp/problem/aplusb\"\n#include \"my_template.hpp\"\
    \n\n#include \"poly/compositional_inverse.hpp\"\n#include \"random/base.hpp\"\n\
    \nusing mint = modint998;\n\nvoid test() {\n  FOR(N, 100) {\n    vc<mint> f(N);\n\
    \    FOR(i, 1, N) f[i] = RNG(1, 10);\n    vc<mint> A = compositional_inverse<mint>(f);\n\
    \    vc<mint> B = compositional_inverse_old<mint>(f);\n    assert(A == B);\n \
    \   vc<mint> F = composition<mint>(f, A);\n    vc<mint> G = composition<mint>(A,\
    \ f);\n    FOR(i, N) {\n      if (i == 1) {\n        assert(F[i] == mint(1));\n\
    \        assert(G[i] == mint(1));\n      } else {\n        assert(F[i] == mint(0));\n\
    \        assert(G[i] == mint(0));\n      }\n    }\n  }\n}\n\nvoid solve() {\n\
    \  int a, b;\n  cin >> a >> b;\n  cout << a + b << \"\\n\";\n}\n\nsigned main()\
    \ {\n  test();\n  solve();\n}\n"
  dependsOn:
  - my_template.hpp
  - poly/compositional_inverse.hpp
  - poly/differentiate.hpp
  - poly/composition.hpp
  - poly/convolution.hpp
  - mod/modint.hpp
  - mod/modint_common.hpp
  - mod/mod_inv.hpp
  - mod/crt3.hpp
  - poly/convolution_naive.hpp
  - poly/convolution_karatsuba.hpp
  - poly/ntt.hpp
  - poly/fft.hpp
  - poly/poly_taylor_shift.hpp
  - mod/powertable.hpp
  - nt/primetable.hpp
  - poly/transposed_ntt.hpp
  - poly/fps_div.hpp
  - poly/count_terms.hpp
  - poly/fps_inv.hpp
  - poly/fps_pow.hpp
  - poly/fps_exp.hpp
  - poly/integrate.hpp
  - poly/fps_log.hpp
  - poly/power_projection.hpp
  - random/base.hpp
  isVerificationFile: true
  path: test/mytest/compositional_inverset.test.cpp
  requiredBy: []
  timestamp: '2024-07-22 11:16:29+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: test/mytest/compositional_inverset.test.cpp
layout: document
redirect_from:
- /verify/test/mytest/compositional_inverset.test.cpp
- /verify/test/mytest/compositional_inverset.test.cpp.html
title: test/mytest/compositional_inverset.test.cpp
---
