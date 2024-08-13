---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: https://judge.yosupo.jp/problem/aplusb
    links:
    - https://codeforces.com/blog/entry/96344
    - https://judge.yosupo.jp/problem/aplusb
    - https://trap.jp/post/1224/
  bundledCode: "#line 1 \"test/1_mytest/slice_rational_fps.test.cpp\"\n#line 1 \"\
    main.cpp\"\n#define PROBLEM \"https://judge.yosupo.jp/problem/aplusb\"\n#line\
    \ 1 \"library/my_template.hpp\"\n#if defined(LOCAL)\n#include <my_template_compiled.hpp>\n\
    #else\n\n// https://codeforces.com/blog/entry/96344\n#pragma GCC optimize(\"Ofast,unroll-loops\"\
    )\n// \u3044\u307E\u306E CF \u3060\u3068\u3053\u308C\u5165\u308C\u308B\u3068\u52D5\
    \u304B\u306A\u3044\uFF1F\n// #pragma GCC target(\"avx2,popcnt\")\n\n#include <bits/stdc++.h>\n\
    \nusing namespace std;\n\nusing ll = long long;\nusing u32 = unsigned int;\nusing\
    \ u64 = unsigned long long;\nusing i128 = __int128;\nusing u128 = unsigned __int128;\n\
    using f128 = __float128;\n\ntemplate <class T>\nconstexpr T infty = 0;\ntemplate\
    \ <>\nconstexpr int infty<int> = 1'000'000'000;\ntemplate <>\nconstexpr ll infty<ll>\
    \ = ll(infty<int>) * infty<int> * 2;\ntemplate <>\nconstexpr u32 infty<u32> =\
    \ infty<int>;\ntemplate <>\nconstexpr u64 infty<u64> = infty<ll>;\ntemplate <>\n\
    constexpr i128 infty<i128> = i128(infty<ll>) * infty<ll>;\ntemplate <>\nconstexpr\
    \ double infty<double> = infty<ll>;\ntemplate <>\nconstexpr long double infty<long\
    \ double> = infty<ll>;\n\nusing pi = pair<ll, ll>;\nusing vi = vector<ll>;\ntemplate\
    \ <class T>\nusing vc = vector<T>;\ntemplate <class T>\nusing vvc = vector<vc<T>>;\n\
    template <class T>\nusing vvvc = vector<vvc<T>>;\ntemplate <class T>\nusing vvvvc\
    \ = vector<vvvc<T>>;\ntemplate <class T>\nusing vvvvvc = vector<vvvvc<T>>;\ntemplate\
    \ <class T>\nusing pq = priority_queue<T>;\ntemplate <class T>\nusing pqg = priority_queue<T,\
    \ vector<T>, greater<T>>;\n\n#define vv(type, name, h, ...) \\\n  vector<vector<type>>\
    \ name(h, vector<type>(__VA_ARGS__))\n#define vvv(type, name, h, w, ...)   \\\n\
    \  vector<vector<vector<type>>> name( \\\n      h, vector<vector<type>>(w, vector<type>(__VA_ARGS__)))\n\
    #define vvvv(type, name, a, b, c, ...)       \\\n  vector<vector<vector<vector<type>>>>\
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
    \  return B;\n}\n#endif\n#line 2 \"library/random/base.hpp\"\n\nu64 RNG_64() {\n\
    \  static uint64_t x_\n      = uint64_t(chrono::duration_cast<chrono::nanoseconds>(\n\
    \                     chrono::high_resolution_clock::now().time_since_epoch())\n\
    \                     .count())\n        * 10150724397891781847ULL;\n  x_ ^= x_\
    \ << 7;\n  return x_ ^= x_ >> 9;\n}\n\nu64 RNG(u64 lim) { return RNG_64() % lim;\
    \ }\n\nll RNG(ll l, ll r) { return l + RNG_64() % (r - l); }\n#line 4 \"main.cpp\"\
    \n\n#line 2 \"library/mod/modint_common.hpp\"\n\nstruct has_mod_impl {\n  template\
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
    library/mod/modint.hpp\"\n\ntemplate <int mod>\nstruct modint {\n  static constexpr\
    \ u32 umod = u32(mod);\n  static_assert(umod < u32(1) << 31);\n  u32 val;\n\n\
    \  static modint raw(u32 v) {\n    modint x;\n    x.val = v;\n    return x;\n\
    \  }\n  constexpr modint() : val(0) {}\n  constexpr modint(u32 x) : val(x % umod)\
    \ {}\n  constexpr modint(u64 x) : val(x % umod) {}\n  constexpr modint(u128 x)\
    \ : val(x % umod) {}\n  constexpr modint(int x) : val((x %= mod) < 0 ? x + mod\
    \ : x){};\n  constexpr modint(ll x) : val((x %= mod) < 0 ? x + mod : x){};\n \
    \ constexpr modint(i128 x) : val((x %= mod) < 0 ? x + mod : x){};\n  bool operator<(const\
    \ modint &other) const { return val < other.val; }\n  modint &operator+=(const\
    \ modint &p) {\n    if ((val += p.val) >= umod) val -= umod;\n    return *this;\n\
    \  }\n  modint &operator-=(const modint &p) {\n    if ((val += umod - p.val) >=\
    \ umod) val -= umod;\n    return *this;\n  }\n  modint &operator*=(const modint\
    \ &p) {\n    val = u64(val) * p.val % umod;\n    return *this;\n  }\n  modint\
    \ &operator/=(const modint &p) {\n    *this *= p.inverse();\n    return *this;\n\
    \  }\n  modint operator-() const { return modint::raw(val ? mod - val : u32(0));\
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
    \  }\n    return ret;\n  }\n  static constexpr int get_mod() { return mod; }\n\
    \  // (n, r), r \u306F 1 \u306E 2^n \u4E57\u6839\n  static constexpr pair<int,\
    \ int> ntt_info() {\n    if (mod == 120586241) return {20, 74066978};\n    if\
    \ (mod == 167772161) return {25, 17};\n    if (mod == 469762049) return {26, 30};\n\
    \    if (mod == 754974721) return {24, 362};\n    if (mod == 880803841) return\
    \ {23, 211};\n    if (mod == 943718401) return {22, 663003469};\n    if (mod ==\
    \ 998244353) return {23, 31};\n    if (mod == 1045430273) return {20, 363};\n\
    \    if (mod == 1051721729) return {20, 330};\n    if (mod == 1053818881) return\
    \ {20, 2789};\n    return {-1, -1};\n  }\n  static constexpr bool can_ntt() {\
    \ return ntt_info().fi != -1; }\n};\n\n#ifdef FASTIO\ntemplate <int mod>\nvoid\
    \ rd(modint<mod> &x) {\n  fastio::rd(x.val);\n  x.val %= mod;\n  // assert(0 <=\
    \ x.val && x.val < mod);\n}\ntemplate <int mod>\nvoid wt(modint<mod> x) {\n  fastio::wt(x.val);\n\
    }\n#endif\n\nusing modint107 = modint<1000000007>;\nusing modint998 = modint<998244353>;\n\
    #line 2 \"library/mod/mod_inv.hpp\"\n\n// long \u3067\u3082\u5927\u4E08\u592B\n\
    // (val * x - 1) \u304C mod \u306E\u500D\u6570\u306B\u306A\u308B\u3088\u3046\u306B\
    \u3059\u308B\n// \u7279\u306B mod=0 \u306A\u3089 x=0 \u304C\u6E80\u305F\u3059\n\
    ll mod_inv(ll val, ll mod) {\n  if (mod == 0) return 0;\n  mod = abs(mod);\n \
    \ val %= mod;\n  if (val < 0) val += mod;\n  ll a = val, b = mod, u = 1, v = 0,\
    \ t;\n  while (b > 0) {\n    t = a / b;\n    swap(a -= t * b, b), swap(u -= t\
    \ * v, v);\n  }\n  if (u < 0) u += mod;\n  return u;\n}\n#line 2 \"library/mod/crt3.hpp\"\
    \n\nconstexpr u32 mod_pow_constexpr(u64 a, u64 n, u32 mod) {\n  a %= mod;\n  u64\
    \ res = 1;\n  FOR(32) {\n    if (n & 1) res = res * a % mod;\n    a = a * a %\
    \ mod, n /= 2;\n  }\n  return res;\n}\n\ntemplate <typename T, u32 p0, u32 p1,\
    \ u32 p2>\nT CRT3(u64 a0, u64 a1, u64 a2) {\n  static_assert(p0 < p1 && p1 < p2);\n\
    \  static constexpr u64 x0_1 = mod_pow_constexpr(p0, p1 - 2, p1);\n  static constexpr\
    \ u64 x01_2 = mod_pow_constexpr(u64(p0) * p1 % p2, p2 - 2, p2);\n  u64 c = (a1\
    \ - a0 + p1) * x0_1 % p1;\n  u64 a = a0 + c * p0;\n  c = (a2 - a % p2 + p2) *\
    \ x01_2 % p2;\n  return T(a) + T(c) * T(p0) * T(p1);\n}\n#line 2 \"library/poly/convolution_naive.hpp\"\
    \n\ntemplate <class T, typename enable_if<!has_mod<T>::value>::type* = nullptr>\n\
    vc<T> convolution_naive(const vc<T>& a, const vc<T>& b) {\n  int n = int(a.size()),\
    \ m = int(b.size());\n  if (n > m) return convolution_naive<T>(b, a);\n  if (n\
    \ == 0) return {};\n  vector<T> ans(n + m - 1);\n  FOR(i, n) FOR(j, m) ans[i +\
    \ j] += a[i] * b[j];\n  return ans;\n}\n\ntemplate <class T, typename enable_if<has_mod<T>::value>::type*\
    \ = nullptr>\nvc<T> convolution_naive(const vc<T>& a, const vc<T>& b) {\n  int\
    \ n = int(a.size()), m = int(b.size());\n  if (n > m) return convolution_naive<T>(b,\
    \ a);\n  if (n == 0) return {};\n  vc<T> ans(n + m - 1);\n  if (n <= 16 && (T::get_mod()\
    \ < (1 << 30))) {\n    for (int k = 0; k < n + m - 1; ++k) {\n      int s = max(0,\
    \ k - m + 1);\n      int t = min(n, k + 1);\n      u64 sm = 0;\n      for (int\
    \ i = s; i < t; ++i) { sm += u64(a[i].val) * (b[k - i].val); }\n      ans[k] =\
    \ sm;\n    }\n  } else {\n    for (int k = 0; k < n + m - 1; ++k) {\n      int\
    \ s = max(0, k - m + 1);\n      int t = min(n, k + 1);\n      u128 sm = 0;\n \
    \     for (int i = s; i < t; ++i) { sm += u64(a[i].val) * (b[k - i].val); }\n\
    \      ans[k] = T::raw(sm % T::get_mod());\n    }\n  }\n  return ans;\n}\n#line\
    \ 2 \"library/poly/convolution_karatsuba.hpp\"\n\n// \u4EFB\u610F\u306E\u74B0\u3067\
    \u3067\u304D\u308B\ntemplate <typename T>\nvc<T> convolution_karatsuba(const vc<T>&\
    \ f, const vc<T>& g) {\n  const int thresh = 30;\n  if (min(len(f), len(g)) <=\
    \ thresh) return convolution_naive(f, g);\n  int n = max(len(f), len(g));\n  int\
    \ m = ceil(n, 2);\n  vc<T> f1, f2, g1, g2;\n  if (len(f) < m) f1 = f;\n  if (len(f)\
    \ >= m) f1 = {f.begin(), f.begin() + m};\n  if (len(f) >= m) f2 = {f.begin() +\
    \ m, f.end()};\n  if (len(g) < m) g1 = g;\n  if (len(g) >= m) g1 = {g.begin(),\
    \ g.begin() + m};\n  if (len(g) >= m) g2 = {g.begin() + m, g.end()};\n  vc<T>\
    \ a = convolution_karatsuba(f1, g1);\n  vc<T> b = convolution_karatsuba(f2, g2);\n\
    \  FOR(i, len(f2)) f1[i] += f2[i];\n  FOR(i, len(g2)) g1[i] += g2[i];\n  vc<T>\
    \ c = convolution_karatsuba(f1, g1);\n  vc<T> F(len(f) + len(g) - 1);\n  assert(2\
    \ * m + len(b) <= len(F));\n  FOR(i, len(a)) F[i] += a[i], c[i] -= a[i];\n  FOR(i,\
    \ len(b)) F[2 * m + i] += b[i], c[i] -= b[i];\n  if (c.back() == T(0)) c.pop_back();\n\
    \  FOR(i, len(c)) if (c[i] != T(0)) F[m + i] += c[i];\n  return F;\n}\n#line 2\
    \ \"library/poly/ntt.hpp\"\n\ntemplate <class mint>\nvoid ntt(vector<mint>& a,\
    \ bool inverse) {\n  assert(mint::can_ntt());\n  const int rank2 = mint::ntt_info().fi;\n\
    \  const int mod = mint::get_mod();\n  static array<mint, 30> root, iroot;\n \
    \ static array<mint, 30> rate2, irate2;\n  static array<mint, 30> rate3, irate3;\n\
    \n  assert(rank2 != -1 && len(a) <= (1 << max(0, rank2)));\n\n  static bool prepared\
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
    \ = 0;\n    while (len < h) {\n      if (h - len == 1) {\n        int p = 1 <<\
    \ (h - len - 1);\n        mint rot = 1;\n        FOR(s, 1 << len) {\n        \
    \  int offset = s << (h - len);\n          FOR(i, p) {\n            auto l = a[i\
    \ + offset];\n            auto r = a[i + offset + p] * rot;\n            a[i +\
    \ offset] = l + r;\n            a[i + offset + p] = l - r;\n          }\n    \
    \      rot *= rate2[topbit(~s & -~s)];\n        }\n        len++;\n      } else\
    \ {\n        int p = 1 << (h - len - 2);\n        mint rot = 1, imag = root[2];\n\
    \        for (int s = 0; s < (1 << len); s++) {\n          mint rot2 = rot * rot;\n\
    \          mint rot3 = rot2 * rot;\n          int offset = s << (h - len);\n \
    \         for (int i = 0; i < p; i++) {\n            u64 mod2 = u64(mod) * mod;\n\
    \            u64 a0 = a[i + offset].val;\n            u64 a1 = u64(a[i + offset\
    \ + p].val) * rot.val;\n            u64 a2 = u64(a[i + offset + 2 * p].val) *\
    \ rot2.val;\n            u64 a3 = u64(a[i + offset + 3 * p].val) * rot3.val;\n\
    \            u64 a1na3imag = (a1 + mod2 - a3) % mod * imag.val;\n            u64\
    \ na2 = mod2 - a2;\n            a[i + offset] = a0 + a2 + a1 + a3;\n         \
    \   a[i + offset + 1 * p] = a0 + a2 + (2 * mod2 - (a1 + a3));\n            a[i\
    \ + offset + 2 * p] = a0 + na2 + a1na3imag;\n            a[i + offset + 3 * p]\
    \ = a0 + na2 + (mod2 - a1na3imag);\n          }\n          rot *= rate3[topbit(~s\
    \ & -~s)];\n        }\n        len += 2;\n      }\n    }\n  } else {\n    mint\
    \ coef = mint(1) / mint(len(a));\n    FOR(i, len(a)) a[i] *= coef;\n    int len\
    \ = h;\n    while (len) {\n      if (len == 1) {\n        int p = 1 << (h - len);\n\
    \        mint irot = 1;\n        FOR(s, 1 << (len - 1)) {\n          int offset\
    \ = s << (h - len + 1);\n          FOR(i, p) {\n            u64 l = a[i + offset].val;\n\
    \            u64 r = a[i + offset + p].val;\n            a[i + offset] = l + r;\n\
    \            a[i + offset + p] = (mod + l - r) * irot.val;\n          }\n    \
    \      irot *= irate2[topbit(~s & -~s)];\n        }\n        len--;\n      } else\
    \ {\n        int p = 1 << (h - len);\n        mint irot = 1, iimag = iroot[2];\n\
    \        FOR(s, (1 << (len - 2))) {\n          mint irot2 = irot * irot;\n   \
    \       mint irot3 = irot2 * irot;\n          int offset = s << (h - len + 2);\n\
    \          for (int i = 0; i < p; i++) {\n            u64 a0 = a[i + offset +\
    \ 0 * p].val;\n            u64 a1 = a[i + offset + 1 * p].val;\n            u64\
    \ a2 = a[i + offset + 2 * p].val;\n            u64 a3 = a[i + offset + 3 * p].val;\n\
    \            u64 x = (mod + a2 - a3) * iimag.val % mod;\n            a[i + offset]\
    \ = a0 + a1 + a2 + a3;\n            a[i + offset + 1 * p] = (a0 + mod - a1 + x)\
    \ * irot.val;\n            a[i + offset + 2 * p] = (a0 + a1 + 2 * mod - a2 - a3)\
    \ * irot2.val;\n            a[i + offset + 3 * p] = (a0 + 2 * mod - a1 - x) *\
    \ irot3.val;\n          }\n          irot *= irate3[topbit(~s & -~s)];\n     \
    \   }\n        len -= 2;\n      }\n    }\n  }\n}\n#line 1 \"library/poly/fft.hpp\"\
    \nnamespace CFFT {\nusing real = double;\n\nstruct C {\n  real x, y;\n\n  C()\
    \ : x(0), y(0) {}\n\n  C(real x, real y) : x(x), y(y) {}\n  inline C operator+(const\
    \ C& c) const { return C(x + c.x, y + c.y); }\n  inline C operator-(const C& c)\
    \ const { return C(x - c.x, y - c.y); }\n  inline C operator*(const C& c) const\
    \ {\n    return C(x * c.x - y * c.y, x * c.y + y * c.x);\n  }\n\n  inline C conj()\
    \ const { return C(x, -y); }\n};\n\nconst real PI = acosl(-1);\nint base = 1;\n\
    vector<C> rts = {{0, 0}, {1, 0}};\nvector<int> rev = {0, 1};\n\nvoid ensure_base(int\
    \ nbase) {\n  if (nbase <= base) return;\n  rev.resize(1 << nbase);\n  rts.resize(1\
    \ << nbase);\n  for (int i = 0; i < (1 << nbase); i++) {\n    rev[i] = (rev[i\
    \ >> 1] >> 1) + ((i & 1) << (nbase - 1));\n  }\n  while (base < nbase) {\n   \
    \ real angle = PI * 2.0 / (1 << (base + 1));\n    for (int i = 1 << (base - 1);\
    \ i < (1 << base); i++) {\n      rts[i << 1] = rts[i];\n      real angle_i = angle\
    \ * (2 * i + 1 - (1 << base));\n      rts[(i << 1) + 1] = C(cos(angle_i), sin(angle_i));\n\
    \    }\n    ++base;\n  }\n}\n\nvoid fft(vector<C>& a, int n) {\n  assert((n &\
    \ (n - 1)) == 0);\n  int zeros = __builtin_ctz(n);\n  ensure_base(zeros);\n  int\
    \ shift = base - zeros;\n  for (int i = 0; i < n; i++) {\n    if (i < (rev[i]\
    \ >> shift)) { swap(a[i], a[rev[i] >> shift]); }\n  }\n  for (int k = 1; k < n;\
    \ k <<= 1) {\n    for (int i = 0; i < n; i += 2 * k) {\n      for (int j = 0;\
    \ j < k; j++) {\n        C z = a[i + j + k] * rts[j + k];\n        a[i + j + k]\
    \ = a[i + j] - z;\n        a[i + j] = a[i + j] + z;\n      }\n    }\n  }\n}\n\
    } // namespace CFFT\n#line 9 \"library/poly/convolution.hpp\"\n\ntemplate <class\
    \ mint>\nvector<mint> convolution_ntt(vector<mint> a, vector<mint> b) {\n  if\
    \ (a.empty() || b.empty()) return {};\n  int n = int(a.size()), m = int(b.size());\n\
    \  int sz = 1;\n  while (sz < n + m - 1) sz *= 2;\n\n  // sz = 2^k \u306E\u3068\
    \u304D\u306E\u9AD8\u901F\u5316\u3002\u5206\u5272\u7D71\u6CBB\u7684\u306A\u3084\
    \u3064\u3067\u640D\u3057\u307E\u304F\u308B\u306E\u3067\u3002\n  if ((n + m - 3)\
    \ <= sz / 2) {\n    auto a_last = a.back(), b_last = b.back();\n    a.pop_back(),\
    \ b.pop_back();\n    auto c = convolution(a, b);\n    c.resize(n + m - 1);\n \
    \   c[n + m - 2] = a_last * b_last;\n    FOR(i, len(a)) c[i + len(b)] += a[i]\
    \ * b_last;\n    FOR(i, len(b)) c[i + len(a)] += b[i] * a_last;\n    return c;\n\
    \  }\n\n  a.resize(sz), b.resize(sz);\n  bool same = a == b;\n  ntt(a, 0);\n \
    \ if (same) {\n    b = a;\n  } else {\n    ntt(b, 0);\n  }\n  FOR(i, sz) a[i]\
    \ *= b[i];\n  ntt(a, 1);\n  a.resize(n + m - 1);\n  return a;\n}\n\ntemplate <typename\
    \ mint>\nvector<mint> convolution_garner(const vector<mint>& a, const vector<mint>&\
    \ b) {\n  int n = len(a), m = len(b);\n  if (!n || !m) return {};\n  static constexpr\
    \ int p0 = 167772161;\n  static constexpr int p1 = 469762049;\n  static constexpr\
    \ int p2 = 754974721;\n  using mint0 = modint<p0>;\n  using mint1 = modint<p1>;\n\
    \  using mint2 = modint<p2>;\n  vc<mint0> a0(n), b0(m);\n  vc<mint1> a1(n), b1(m);\n\
    \  vc<mint2> a2(n), b2(m);\n  FOR(i, n) a0[i] = a[i].val, a1[i] = a[i].val, a2[i]\
    \ = a[i].val;\n  FOR(i, m) b0[i] = b[i].val, b1[i] = b[i].val, b2[i] = b[i].val;\n\
    \  auto c0 = convolution_ntt<mint0>(a0, b0);\n  auto c1 = convolution_ntt<mint1>(a1,\
    \ b1);\n  auto c2 = convolution_ntt<mint2>(a2, b2);\n  vc<mint> c(len(c0));\n\
    \  FOR(i, n + m - 1) {\n    c[i] = CRT3<mint, p0, p1, p2>(c0[i].val, c1[i].val,\
    \ c2[i].val);\n  }\n  return c;\n}\n\ntemplate <typename R>\nvc<double> convolution_fft(const\
    \ vc<R>& a, const vc<R>& b) {\n  using C = CFFT::C;\n  int need = (int)a.size()\
    \ + (int)b.size() - 1;\n  int nbase = 1;\n  while ((1 << nbase) < need) nbase++;\n\
    \  CFFT::ensure_base(nbase);\n  int sz = 1 << nbase;\n  vector<C> fa(sz);\n  for\
    \ (int i = 0; i < sz; i++) {\n    double x = (i < (int)a.size() ? a[i] : 0);\n\
    \    double y = (i < (int)b.size() ? b[i] : 0);\n    fa[i] = C(x, y);\n  }\n \
    \ CFFT::fft(fa, sz);\n  C r(0, -0.25 / (sz >> 1)), s(0, 1), t(0.5, 0);\n  for\
    \ (int i = 0; i <= (sz >> 1); i++) {\n    int j = (sz - i) & (sz - 1);\n    C\
    \ z = (fa[j] * fa[j] - (fa[i] * fa[i]).conj()) * r;\n    fa[j] = (fa[i] * fa[i]\
    \ - (fa[j] * fa[j]).conj()) * r;\n    fa[i] = z;\n  }\n  for (int i = 0; i < (sz\
    \ >> 1); i++) {\n    C A0 = (fa[i] + fa[i + (sz >> 1)]) * t;\n    C A1 = (fa[i]\
    \ - fa[i + (sz >> 1)]) * t * CFFT::rts[(sz >> 1) + i];\n    fa[i] = A0 + A1 *\
    \ s;\n  }\n  CFFT::fft(fa, sz >> 1);\n  vector<double> ret(need);\n  for (int\
    \ i = 0; i < need; i++) {\n    ret[i] = (i & 1 ? fa[i >> 1].y : fa[i >> 1].x);\n\
    \  }\n  return ret;\n}\n\nvector<ll> convolution(const vector<ll>& a, const vector<ll>&\
    \ b) {\n  int n = len(a), m = len(b);\n  if (!n || !m) return {};\n  if (min(n,\
    \ m) <= 2500) return convolution_naive(a, b);\n  ll abs_sum_a = 0, abs_sum_b =\
    \ 0;\n  ll LIM = 1e15;\n  FOR(i, n) abs_sum_a = min(LIM, abs_sum_a + abs(a[i]));\n\
    \  FOR(i, m) abs_sum_b = min(LIM, abs_sum_b + abs(b[i]));\n  if (i128(abs_sum_a)\
    \ * abs_sum_b < 1e15) {\n    vc<double> c = convolution_fft<ll>(a, b);\n    vc<ll>\
    \ res(len(c));\n    FOR(i, len(c)) res[i] = ll(floor(c[i] + .5));\n    return\
    \ res;\n  }\n\n  static constexpr unsigned long long MOD1 = 754974721; // 2^24\n\
    \  static constexpr unsigned long long MOD2 = 167772161; // 2^25\n  static constexpr\
    \ unsigned long long MOD3 = 469762049; // 2^26\n  static constexpr unsigned long\
    \ long M2M3 = MOD2 * MOD3;\n  static constexpr unsigned long long M1M3 = MOD1\
    \ * MOD3;\n  static constexpr unsigned long long M1M2 = MOD1 * MOD2;\n  static\
    \ constexpr unsigned long long M1M2M3 = MOD1 * MOD2 * MOD3;\n\n  static const\
    \ unsigned long long i1 = mod_inv(MOD2 * MOD3, MOD1);\n  static const unsigned\
    \ long long i2 = mod_inv(MOD1 * MOD3, MOD2);\n  static const unsigned long long\
    \ i3 = mod_inv(MOD1 * MOD2, MOD3);\n\n  using mint1 = modint<MOD1>;\n  using mint2\
    \ = modint<MOD2>;\n  using mint3 = modint<MOD3>;\n\n  vc<mint1> a1(n), b1(m);\n\
    \  vc<mint2> a2(n), b2(m);\n  vc<mint3> a3(n), b3(m);\n  FOR(i, n) a1[i] = a[i],\
    \ a2[i] = a[i], a3[i] = a[i];\n  FOR(i, m) b1[i] = b[i], b2[i] = b[i], b3[i] =\
    \ b[i];\n\n  auto c1 = convolution_ntt<mint1>(a1, b1);\n  auto c2 = convolution_ntt<mint2>(a2,\
    \ b2);\n  auto c3 = convolution_ntt<mint3>(a3, b3);\n\n  vc<ll> c(n + m - 1);\n\
    \  FOR(i, n + m - 1) {\n    u64 x = 0;\n    x += (c1[i].val * i1) % MOD1 * M2M3;\n\
    \    x += (c2[i].val * i2) % MOD2 * M1M3;\n    x += (c3[i].val * i3) % MOD3 *\
    \ M1M2;\n    ll diff = c1[i].val - ((long long)(x) % (long long)(MOD1));\n   \
    \ if (diff < 0) diff += MOD1;\n    static constexpr unsigned long long offset[5]\n\
    \        = {0, 0, M1M2M3, 2 * M1M2M3, 3 * M1M2M3};\n    x -= offset[diff % 5];\n\
    \    c[i] = x;\n  }\n  return c;\n}\n\ntemplate <typename mint>\nvc<mint> convolution(const\
    \ vc<mint>& a, const vc<mint>& b) {\n  int n = len(a), m = len(b);\n  if (!n ||\
    \ !m) return {};\n  if (mint::can_ntt()) {\n    if (min(n, m) <= 50) return convolution_karatsuba<mint>(a,\
    \ b);\n    return convolution_ntt(a, b);\n  }\n  if (min(n, m) <= 200) return\
    \ convolution_karatsuba<mint>(a, b);\n  return convolution_garner(a, b);\n}\n\
    #line 2 \"library/poly/transposed_ntt.hpp\"\n\ntemplate <class mint>\nvoid transposed_ntt(vector<mint>&\
    \ a, bool inverse) {\n  assert(mint::can_ntt());\n  const int rank2 = mint::ntt_info().fi;\n\
    \  const int mod = mint::get_mod();\n  static array<mint, 30> root, iroot;\n \
    \ static array<mint, 30> rate2, irate2;\n  static array<mint, 30> rate3, irate3;\n\
    \n  assert(rank2 != -1 && len(a) <= (1 << max(0, rank2)));\n\n  static bool prepared\
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
    \ & -~s)];\n        }\n        len += 2;\n      }\n    }\n  }\n}\n#line 2 \"library/poly/fps_div.hpp\"\
    \n\n#line 2 \"library/poly/count_terms.hpp\"\ntemplate<typename mint>\nint count_terms(const\
    \ vc<mint>& f){\n  int t = 0;\n  FOR(i, len(f)) if(f[i] != mint(0)) ++t;\n  return\
    \ t;\n}\n#line 4 \"library/poly/fps_inv.hpp\"\n\ntemplate <typename mint>\nvc<mint>\
    \ fps_inv_sparse(const vc<mint>& f) {\n  int N = len(f);\n  vc<pair<int, mint>>\
    \ dat;\n  FOR(i, 1, N) if (f[i] != mint(0)) dat.eb(i, f[i]);\n  vc<mint> g(N);\n\
    \  mint g0 = mint(1) / f[0];\n  g[0] = g0;\n  FOR(n, 1, N) {\n    mint rhs = 0;\n\
    \    for (auto&& [k, fk]: dat) {\n      if (k > n) break;\n      rhs -= fk * g[n\
    \ - k];\n    }\n    g[n] = rhs * g0;\n  }\n  return g;\n}\n\ntemplate <typename\
    \ mint>\nvc<mint> fps_inv_dense_ntt(const vc<mint>& F) {\n  vc<mint> G = {mint(1)\
    \ / F[0]};\n  ll N = len(F), n = 1;\n  G.reserve(N);\n  while (n < N) {\n    vc<mint>\
    \ f(2 * n), g(2 * n);\n    FOR(i, min(N, 2 * n)) f[i] = F[i];\n    FOR(i, n) g[i]\
    \ = G[i];\n    ntt(f, false), ntt(g, false);\n    FOR(i, 2 * n) f[i] *= g[i];\n\
    \    ntt(f, true);\n    FOR(i, n) f[i] = 0;\n    ntt(f, false);\n    FOR(i, 2\
    \ * n) f[i] *= g[i];\n    ntt(f, true);\n    FOR(i, n, min(N, 2 * n)) G.eb(-f[i]);\n\
    \    n *= 2;\n  }\n  return G;\n}\n\ntemplate <typename mint>\nvc<mint> fps_inv_dense(const\
    \ vc<mint>& F) {\n  if (mint::can_ntt()) return fps_inv_dense_ntt(F);\n  const\
    \ int N = len(F);\n  vc<mint> R = {mint(1) / F[0]};\n  vc<mint> p;\n  int m =\
    \ 1;\n  while (m < N) {\n    p = convolution(R, R);\n    p.resize(m + m);\n  \
    \  vc<mint> f = {F.begin(), F.begin() + min(m + m, N)};\n    p = convolution(p,\
    \ f);\n    R.resize(m + m);\n    FOR(i, m + m) R[i] = R[i] + R[i] - p[i];\n  \
    \  m += m;\n  }\n  R.resize(N);\n  return R;\n}\n\ntemplate <typename mint>\n\
    vc<mint> fps_inv(const vc<mint>& f) {\n  assert(f[0] != mint(0));\n  int n = count_terms(f);\n\
    \  int t = (mint::can_ntt() ? 160 : 820);\n  return (n <= t ? fps_inv_sparse<mint>(f)\
    \ : fps_inv_dense<mint>(f));\n}\n#line 5 \"library/poly/fps_div.hpp\"\n\n// f/g.\
    \ f \u306E\u9577\u3055\u3067\u51FA\u529B\u3055\u308C\u308B.\ntemplate <typename\
    \ mint, bool SPARSE = false>\nvc<mint> fps_div(vc<mint> f, vc<mint> g) {\n  if\
    \ (SPARSE || count_terms(g) < 200) return fps_div_sparse(f, g);\n  int n = len(f);\n\
    \  g.resize(n);\n  g = fps_inv<mint>(g);\n  f = convolution(f, g);\n  f.resize(n);\n\
    \  return f;\n}\n\n// f/g \u305F\u3060\u3057 g \u306F sparse\ntemplate <typename\
    \ mint>\nvc<mint> fps_div_sparse(vc<mint> f, vc<mint>& g) {\n  if (g[0] != mint(1))\
    \ {\n    mint cf = g[0].inverse();\n    for (auto&& x: f) x *= cf;\n    for (auto&&\
    \ x: g) x *= cf;\n  }\n\n  vc<pair<int, mint>> dat;\n  FOR(i, 1, len(g)) if (g[i]\
    \ != mint(0)) dat.eb(i, -g[i]);\n  FOR(i, len(f)) {\n    for (auto&& [j, x]: dat)\
    \ {\n      if (i >= j) f[i] += x * f[i - j];\n    }\n  }\n  return f;\n}\n#line\
    \ 2 \"library/poly/poly_divmod.hpp\"\n\n#line 4 \"library/poly/poly_divmod.hpp\"\
    \ntemplate <typename mint>\npair<vc<mint>, vc<mint>> poly_divmod(vc<mint> f, vc<mint>\
    \ g) {\n  assert(g.back() != 0);\n  if (len(f) < len(g)) { return {{}, f}; }\n\
    \  auto rf = f, rg = g;\n  reverse(all(rf)), reverse(all(rg));\n  ll deg = len(rf)\
    \ - len(rg) + 1;\n  rf.resize(deg), rg.resize(deg);\n  rg = fps_inv(rg);\n  auto\
    \ q = convolution(rf, rg);\n  q.resize(deg);\n  reverse(all(q));\n  auto h = convolution(q,\
    \ g);\n  FOR(i, len(f)) f[i] -= h[i];\n  while (len(f) > 0 && f.back() == 0) f.pop_back();\n\
    \  return {q, f};\n}\n#line 5 \"library/poly/slice_rational_fps.hpp\"\n\ntemplate\
    \ <typename mint>\nvc<mint> slice_rational_fps(vector<mint> P, vector<mint> Q,\
    \ ll L, ll R) {\n  while (len(Q) && Q.back() == mint(0)) POP(Q);\n  assert(Q[0]\
    \ == mint(1));\n  if (len(Q) == 1) {\n    vc<mint> ANS(R - L);\n    FOR(i, L,\
    \ R) if (i < len(P)) ANS[i - L] = P[i];\n    return ANS;\n  }\n  vc<mint> Q0 =\
    \ Q;\n\n  int n = 1;\n  while (n < len(Q)) n += n;\n  Q.resize(2 * n), ntt(Q,\
    \ 0);\n\n  vc<mint> W(n);\n  {\n    vc<int> btr(n);\n    int log = topbit(n);\n\
    \    FOR(i, n) { btr[i] = (btr[i >> 1] >> 1) + ((i & 1) << (log - 1)); }\n   \
    \ int t = mint::ntt_info().fi;\n    mint r = mint::ntt_info().se;\n    mint dw\
    \ = r.inverse().pow((1 << t) / (2 * n));\n    mint w = 1;\n    for (auto& i: btr)\
    \ { W[i] = w, w *= dw; }\n  }\n\n  mint z = W[n / 2].inverse();\n  auto doubling\
    \ = [&](vc<mint> f, bool t) -> vc<mint> {\n    mint r = 1;\n    if (!t) {\n  \
    \    vc<mint> g(2 * n);\n      copy(all(f), g.begin());\n      ntt(f, 1);\n  \
    \    FOR(i, 1, n) r *= z, f[i] *= r;\n      ntt(f, 0);\n      copy(all(f), g.begin()\
    \ + n);\n      return g;\n    } else {\n      vc<mint> g = {f.begin(), f.begin()\
    \ + n};\n      f = {f.begin() + n, f.begin() + 2 * n};\n      transposed_ntt(f,\
    \ 0);\n      FOR(i, 1, n) r *= z, f[i] *= r;\n      transposed_ntt(f, 1);\n  \
    \    FOR(i, n) g[i] += f[i];\n      return g;\n    }\n  };\n\n  auto dfs = [&](auto&\
    \ dfs, vc<mint> Q, ll N) -> vc<mint> {\n    vc<mint> nxt_Q(2 * n);\n    FOR(i,\
    \ n) nxt_Q[i] = Q[2 * i] * Q[2 * i + 1];\n    nxt_Q.resize(n);\n    vc<mint> p;\n\
    \    if (N / 2 >= n) {\n      nxt_Q = doubling(nxt_Q, 0);\n      p = dfs(dfs,\
    \ nxt_Q, N / 2);\n      p = doubling(p, 1);\n    } else {\n      ntt(nxt_Q, 1);\n\
    \      nxt_Q = fps_inv<mint>(nxt_Q);\n      p.resize(n);\n      FOR(i, N / 2 +\
    \ 1) p[i] += nxt_Q[N / 2 - i];\n      transposed_ntt(p, 1);\n    }\n    assert(len(p)\
    \ == n);\n    p.resize(2 * n);\n    if (N % 2 == 0) {\n      FOR_R(i, n) {\n \
    \       p[2 * i + 1] = Q[2 * i + 0] * inv<mint>(2) * p[i];\n        p[2 * i +\
    \ 0] = Q[2 * i + 1] * inv<mint>(2) * p[i];\n      }\n    } else {\n      FOR_R(i,\
    \ n) {\n        p[2 * i + 1] = -Q[2 * i + 0] * inv<mint>(2) * W[i] * p[i];\n \
    \       p[2 * i + 0] = Q[2 * i + 1] * inv<mint>(2) * W[i] * p[i];\n      }\n \
    \   }\n    assert(len(p) == 2 * n);\n    return p;\n  };\n\n  vc<mint> p = dfs(dfs,\
    \ Q, L + n - 1);\n  transposed_ntt(p, 0);\n  p.resize(n);\n  reverse(all(p));\n\
    \  swap(Q, Q0);\n  p.resize(len(Q) - 1);\n  // 1/Q \u306E L \u4EE5\u964D\u304C\
    \ p \u3067\u306F\u3058\u307E\u308B\n  auto [f, g] = poly_divmod(P, Q);\n  p =\
    \ convolution<mint>(p, Q);\n  p.resize(len(Q) - 1);\n  p = convolution<mint>(p,\
    \ g);\n  p = poly_divmod(p, Q).se;\n  p.resize(R - L);\n  Q.resize(R - L);\n \
    \ p = fps_div<mint>(p, Q);\n  FOR(i, L, len(f)) if (i < R) p[i - L] += f[i];\n\
    \  return p;\n}\n#line 7 \"main.cpp\"\n\nusing mint = modint998;\n\nvc<mint> gen(int\
    \ n) {\n  vc<mint> f(n);\n  FOR(i, n) f[i] = RNG(0, 100);\n  return f;\n}\n\n\
    void test() {\n  using poly = vc<mint>;\n  FOR(n, 1, 10) FOR(m, n) {\n    poly\
    \ P = gen(m), Q = gen(n);\n    Q[0] = mint(1);\n    poly f = P, g = Q;\n    f.resize(100),\
    \ g.resize(100);\n    vc<mint> F = fps_div(f, g);\n    FOR(i, 50) {\n      poly\
    \ A = slice_rational_fps(P, Q, i, i + n - 1);\n      poly B = {F.begin() + i,\
    \ F.begin() + i + n - 1};\n      assert(A == B);\n    }\n  }\n  int n = 500;\n\
    \  int m = 499;\n  poly P = gen(m), Q = gen(n);\n  Q[0] = mint(1);\n  poly f =\
    \ P, g = Q;\n  f.resize(1000), g.resize(1000);\n  vc<mint> F = fps_div(f, g);\n\
    \  FOR(i, 500) {\n    auto A = slice_rational_fps(P, Q, i, i + n - 1);\n    poly\
    \ B = {F.begin() + i, F.begin() + i + n - 1};\n    assert(A == B);\n  }\n}\n\n\
    void solve() {\n  int a, b;\n  cin >> a >> b;\n  cout << a + b << \"\\n\";\n}\n\
    \nsigned main() {\n  test();\n  solve();\n  return 0;\n}\n"
  code: "#line 1 \"main.cpp\"\n#define PROBLEM \"https://judge.yosupo.jp/problem/aplusb\"\
    \n#line 1 \"library/my_template.hpp\"\n#if defined(LOCAL)\n#include <my_template_compiled.hpp>\n\
    #else\n\n// https://codeforces.com/blog/entry/96344\n#pragma GCC optimize(\"Ofast,unroll-loops\"\
    )\n// \u3044\u307E\u306E CF \u3060\u3068\u3053\u308C\u5165\u308C\u308B\u3068\u52D5\
    \u304B\u306A\u3044\uFF1F\n// #pragma GCC target(\"avx2,popcnt\")\n\n#include <bits/stdc++.h>\n\
    \nusing namespace std;\n\nusing ll = long long;\nusing u32 = unsigned int;\nusing\
    \ u64 = unsigned long long;\nusing i128 = __int128;\nusing u128 = unsigned __int128;\n\
    using f128 = __float128;\n\ntemplate <class T>\nconstexpr T infty = 0;\ntemplate\
    \ <>\nconstexpr int infty<int> = 1'000'000'000;\ntemplate <>\nconstexpr ll infty<ll>\
    \ = ll(infty<int>) * infty<int> * 2;\ntemplate <>\nconstexpr u32 infty<u32> =\
    \ infty<int>;\ntemplate <>\nconstexpr u64 infty<u64> = infty<ll>;\ntemplate <>\n\
    constexpr i128 infty<i128> = i128(infty<ll>) * infty<ll>;\ntemplate <>\nconstexpr\
    \ double infty<double> = infty<ll>;\ntemplate <>\nconstexpr long double infty<long\
    \ double> = infty<ll>;\n\nusing pi = pair<ll, ll>;\nusing vi = vector<ll>;\ntemplate\
    \ <class T>\nusing vc = vector<T>;\ntemplate <class T>\nusing vvc = vector<vc<T>>;\n\
    template <class T>\nusing vvvc = vector<vvc<T>>;\ntemplate <class T>\nusing vvvvc\
    \ = vector<vvvc<T>>;\ntemplate <class T>\nusing vvvvvc = vector<vvvvc<T>>;\ntemplate\
    \ <class T>\nusing pq = priority_queue<T>;\ntemplate <class T>\nusing pqg = priority_queue<T,\
    \ vector<T>, greater<T>>;\n\n#define vv(type, name, h, ...) \\\n  vector<vector<type>>\
    \ name(h, vector<type>(__VA_ARGS__))\n#define vvv(type, name, h, w, ...)   \\\n\
    \  vector<vector<vector<type>>> name( \\\n      h, vector<vector<type>>(w, vector<type>(__VA_ARGS__)))\n\
    #define vvvv(type, name, a, b, c, ...)       \\\n  vector<vector<vector<vector<type>>>>\
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
    \  return B;\n}\n#endif\n#line 2 \"library/random/base.hpp\"\n\nu64 RNG_64() {\n\
    \  static uint64_t x_\n      = uint64_t(chrono::duration_cast<chrono::nanoseconds>(\n\
    \                     chrono::high_resolution_clock::now().time_since_epoch())\n\
    \                     .count())\n        * 10150724397891781847ULL;\n  x_ ^= x_\
    \ << 7;\n  return x_ ^= x_ >> 9;\n}\n\nu64 RNG(u64 lim) { return RNG_64() % lim;\
    \ }\n\nll RNG(ll l, ll r) { return l + RNG_64() % (r - l); }\n#line 4 \"main.cpp\"\
    \n\n#line 2 \"library/mod/modint_common.hpp\"\n\nstruct has_mod_impl {\n  template\
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
    library/mod/modint.hpp\"\n\ntemplate <int mod>\nstruct modint {\n  static constexpr\
    \ u32 umod = u32(mod);\n  static_assert(umod < u32(1) << 31);\n  u32 val;\n\n\
    \  static modint raw(u32 v) {\n    modint x;\n    x.val = v;\n    return x;\n\
    \  }\n  constexpr modint() : val(0) {}\n  constexpr modint(u32 x) : val(x % umod)\
    \ {}\n  constexpr modint(u64 x) : val(x % umod) {}\n  constexpr modint(u128 x)\
    \ : val(x % umod) {}\n  constexpr modint(int x) : val((x %= mod) < 0 ? x + mod\
    \ : x){};\n  constexpr modint(ll x) : val((x %= mod) < 0 ? x + mod : x){};\n \
    \ constexpr modint(i128 x) : val((x %= mod) < 0 ? x + mod : x){};\n  bool operator<(const\
    \ modint &other) const { return val < other.val; }\n  modint &operator+=(const\
    \ modint &p) {\n    if ((val += p.val) >= umod) val -= umod;\n    return *this;\n\
    \  }\n  modint &operator-=(const modint &p) {\n    if ((val += umod - p.val) >=\
    \ umod) val -= umod;\n    return *this;\n  }\n  modint &operator*=(const modint\
    \ &p) {\n    val = u64(val) * p.val % umod;\n    return *this;\n  }\n  modint\
    \ &operator/=(const modint &p) {\n    *this *= p.inverse();\n    return *this;\n\
    \  }\n  modint operator-() const { return modint::raw(val ? mod - val : u32(0));\
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
    \  }\n    return ret;\n  }\n  static constexpr int get_mod() { return mod; }\n\
    \  // (n, r), r \u306F 1 \u306E 2^n \u4E57\u6839\n  static constexpr pair<int,\
    \ int> ntt_info() {\n    if (mod == 120586241) return {20, 74066978};\n    if\
    \ (mod == 167772161) return {25, 17};\n    if (mod == 469762049) return {26, 30};\n\
    \    if (mod == 754974721) return {24, 362};\n    if (mod == 880803841) return\
    \ {23, 211};\n    if (mod == 943718401) return {22, 663003469};\n    if (mod ==\
    \ 998244353) return {23, 31};\n    if (mod == 1045430273) return {20, 363};\n\
    \    if (mod == 1051721729) return {20, 330};\n    if (mod == 1053818881) return\
    \ {20, 2789};\n    return {-1, -1};\n  }\n  static constexpr bool can_ntt() {\
    \ return ntt_info().fi != -1; }\n};\n\n#ifdef FASTIO\ntemplate <int mod>\nvoid\
    \ rd(modint<mod> &x) {\n  fastio::rd(x.val);\n  x.val %= mod;\n  // assert(0 <=\
    \ x.val && x.val < mod);\n}\ntemplate <int mod>\nvoid wt(modint<mod> x) {\n  fastio::wt(x.val);\n\
    }\n#endif\n\nusing modint107 = modint<1000000007>;\nusing modint998 = modint<998244353>;\n\
    #line 2 \"library/mod/mod_inv.hpp\"\n\n// long \u3067\u3082\u5927\u4E08\u592B\n\
    // (val * x - 1) \u304C mod \u306E\u500D\u6570\u306B\u306A\u308B\u3088\u3046\u306B\
    \u3059\u308B\n// \u7279\u306B mod=0 \u306A\u3089 x=0 \u304C\u6E80\u305F\u3059\n\
    ll mod_inv(ll val, ll mod) {\n  if (mod == 0) return 0;\n  mod = abs(mod);\n \
    \ val %= mod;\n  if (val < 0) val += mod;\n  ll a = val, b = mod, u = 1, v = 0,\
    \ t;\n  while (b > 0) {\n    t = a / b;\n    swap(a -= t * b, b), swap(u -= t\
    \ * v, v);\n  }\n  if (u < 0) u += mod;\n  return u;\n}\n#line 2 \"library/mod/crt3.hpp\"\
    \n\nconstexpr u32 mod_pow_constexpr(u64 a, u64 n, u32 mod) {\n  a %= mod;\n  u64\
    \ res = 1;\n  FOR(32) {\n    if (n & 1) res = res * a % mod;\n    a = a * a %\
    \ mod, n /= 2;\n  }\n  return res;\n}\n\ntemplate <typename T, u32 p0, u32 p1,\
    \ u32 p2>\nT CRT3(u64 a0, u64 a1, u64 a2) {\n  static_assert(p0 < p1 && p1 < p2);\n\
    \  static constexpr u64 x0_1 = mod_pow_constexpr(p0, p1 - 2, p1);\n  static constexpr\
    \ u64 x01_2 = mod_pow_constexpr(u64(p0) * p1 % p2, p2 - 2, p2);\n  u64 c = (a1\
    \ - a0 + p1) * x0_1 % p1;\n  u64 a = a0 + c * p0;\n  c = (a2 - a % p2 + p2) *\
    \ x01_2 % p2;\n  return T(a) + T(c) * T(p0) * T(p1);\n}\n#line 2 \"library/poly/convolution_naive.hpp\"\
    \n\ntemplate <class T, typename enable_if<!has_mod<T>::value>::type* = nullptr>\n\
    vc<T> convolution_naive(const vc<T>& a, const vc<T>& b) {\n  int n = int(a.size()),\
    \ m = int(b.size());\n  if (n > m) return convolution_naive<T>(b, a);\n  if (n\
    \ == 0) return {};\n  vector<T> ans(n + m - 1);\n  FOR(i, n) FOR(j, m) ans[i +\
    \ j] += a[i] * b[j];\n  return ans;\n}\n\ntemplate <class T, typename enable_if<has_mod<T>::value>::type*\
    \ = nullptr>\nvc<T> convolution_naive(const vc<T>& a, const vc<T>& b) {\n  int\
    \ n = int(a.size()), m = int(b.size());\n  if (n > m) return convolution_naive<T>(b,\
    \ a);\n  if (n == 0) return {};\n  vc<T> ans(n + m - 1);\n  if (n <= 16 && (T::get_mod()\
    \ < (1 << 30))) {\n    for (int k = 0; k < n + m - 1; ++k) {\n      int s = max(0,\
    \ k - m + 1);\n      int t = min(n, k + 1);\n      u64 sm = 0;\n      for (int\
    \ i = s; i < t; ++i) { sm += u64(a[i].val) * (b[k - i].val); }\n      ans[k] =\
    \ sm;\n    }\n  } else {\n    for (int k = 0; k < n + m - 1; ++k) {\n      int\
    \ s = max(0, k - m + 1);\n      int t = min(n, k + 1);\n      u128 sm = 0;\n \
    \     for (int i = s; i < t; ++i) { sm += u64(a[i].val) * (b[k - i].val); }\n\
    \      ans[k] = T::raw(sm % T::get_mod());\n    }\n  }\n  return ans;\n}\n#line\
    \ 2 \"library/poly/convolution_karatsuba.hpp\"\n\n// \u4EFB\u610F\u306E\u74B0\u3067\
    \u3067\u304D\u308B\ntemplate <typename T>\nvc<T> convolution_karatsuba(const vc<T>&\
    \ f, const vc<T>& g) {\n  const int thresh = 30;\n  if (min(len(f), len(g)) <=\
    \ thresh) return convolution_naive(f, g);\n  int n = max(len(f), len(g));\n  int\
    \ m = ceil(n, 2);\n  vc<T> f1, f2, g1, g2;\n  if (len(f) < m) f1 = f;\n  if (len(f)\
    \ >= m) f1 = {f.begin(), f.begin() + m};\n  if (len(f) >= m) f2 = {f.begin() +\
    \ m, f.end()};\n  if (len(g) < m) g1 = g;\n  if (len(g) >= m) g1 = {g.begin(),\
    \ g.begin() + m};\n  if (len(g) >= m) g2 = {g.begin() + m, g.end()};\n  vc<T>\
    \ a = convolution_karatsuba(f1, g1);\n  vc<T> b = convolution_karatsuba(f2, g2);\n\
    \  FOR(i, len(f2)) f1[i] += f2[i];\n  FOR(i, len(g2)) g1[i] += g2[i];\n  vc<T>\
    \ c = convolution_karatsuba(f1, g1);\n  vc<T> F(len(f) + len(g) - 1);\n  assert(2\
    \ * m + len(b) <= len(F));\n  FOR(i, len(a)) F[i] += a[i], c[i] -= a[i];\n  FOR(i,\
    \ len(b)) F[2 * m + i] += b[i], c[i] -= b[i];\n  if (c.back() == T(0)) c.pop_back();\n\
    \  FOR(i, len(c)) if (c[i] != T(0)) F[m + i] += c[i];\n  return F;\n}\n#line 2\
    \ \"library/poly/ntt.hpp\"\n\ntemplate <class mint>\nvoid ntt(vector<mint>& a,\
    \ bool inverse) {\n  assert(mint::can_ntt());\n  const int rank2 = mint::ntt_info().fi;\n\
    \  const int mod = mint::get_mod();\n  static array<mint, 30> root, iroot;\n \
    \ static array<mint, 30> rate2, irate2;\n  static array<mint, 30> rate3, irate3;\n\
    \n  assert(rank2 != -1 && len(a) <= (1 << max(0, rank2)));\n\n  static bool prepared\
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
    \ = 0;\n    while (len < h) {\n      if (h - len == 1) {\n        int p = 1 <<\
    \ (h - len - 1);\n        mint rot = 1;\n        FOR(s, 1 << len) {\n        \
    \  int offset = s << (h - len);\n          FOR(i, p) {\n            auto l = a[i\
    \ + offset];\n            auto r = a[i + offset + p] * rot;\n            a[i +\
    \ offset] = l + r;\n            a[i + offset + p] = l - r;\n          }\n    \
    \      rot *= rate2[topbit(~s & -~s)];\n        }\n        len++;\n      } else\
    \ {\n        int p = 1 << (h - len - 2);\n        mint rot = 1, imag = root[2];\n\
    \        for (int s = 0; s < (1 << len); s++) {\n          mint rot2 = rot * rot;\n\
    \          mint rot3 = rot2 * rot;\n          int offset = s << (h - len);\n \
    \         for (int i = 0; i < p; i++) {\n            u64 mod2 = u64(mod) * mod;\n\
    \            u64 a0 = a[i + offset].val;\n            u64 a1 = u64(a[i + offset\
    \ + p].val) * rot.val;\n            u64 a2 = u64(a[i + offset + 2 * p].val) *\
    \ rot2.val;\n            u64 a3 = u64(a[i + offset + 3 * p].val) * rot3.val;\n\
    \            u64 a1na3imag = (a1 + mod2 - a3) % mod * imag.val;\n            u64\
    \ na2 = mod2 - a2;\n            a[i + offset] = a0 + a2 + a1 + a3;\n         \
    \   a[i + offset + 1 * p] = a0 + a2 + (2 * mod2 - (a1 + a3));\n            a[i\
    \ + offset + 2 * p] = a0 + na2 + a1na3imag;\n            a[i + offset + 3 * p]\
    \ = a0 + na2 + (mod2 - a1na3imag);\n          }\n          rot *= rate3[topbit(~s\
    \ & -~s)];\n        }\n        len += 2;\n      }\n    }\n  } else {\n    mint\
    \ coef = mint(1) / mint(len(a));\n    FOR(i, len(a)) a[i] *= coef;\n    int len\
    \ = h;\n    while (len) {\n      if (len == 1) {\n        int p = 1 << (h - len);\n\
    \        mint irot = 1;\n        FOR(s, 1 << (len - 1)) {\n          int offset\
    \ = s << (h - len + 1);\n          FOR(i, p) {\n            u64 l = a[i + offset].val;\n\
    \            u64 r = a[i + offset + p].val;\n            a[i + offset] = l + r;\n\
    \            a[i + offset + p] = (mod + l - r) * irot.val;\n          }\n    \
    \      irot *= irate2[topbit(~s & -~s)];\n        }\n        len--;\n      } else\
    \ {\n        int p = 1 << (h - len);\n        mint irot = 1, iimag = iroot[2];\n\
    \        FOR(s, (1 << (len - 2))) {\n          mint irot2 = irot * irot;\n   \
    \       mint irot3 = irot2 * irot;\n          int offset = s << (h - len + 2);\n\
    \          for (int i = 0; i < p; i++) {\n            u64 a0 = a[i + offset +\
    \ 0 * p].val;\n            u64 a1 = a[i + offset + 1 * p].val;\n            u64\
    \ a2 = a[i + offset + 2 * p].val;\n            u64 a3 = a[i + offset + 3 * p].val;\n\
    \            u64 x = (mod + a2 - a3) * iimag.val % mod;\n            a[i + offset]\
    \ = a0 + a1 + a2 + a3;\n            a[i + offset + 1 * p] = (a0 + mod - a1 + x)\
    \ * irot.val;\n            a[i + offset + 2 * p] = (a0 + a1 + 2 * mod - a2 - a3)\
    \ * irot2.val;\n            a[i + offset + 3 * p] = (a0 + 2 * mod - a1 - x) *\
    \ irot3.val;\n          }\n          irot *= irate3[topbit(~s & -~s)];\n     \
    \   }\n        len -= 2;\n      }\n    }\n  }\n}\n#line 1 \"library/poly/fft.hpp\"\
    \nnamespace CFFT {\nusing real = double;\n\nstruct C {\n  real x, y;\n\n  C()\
    \ : x(0), y(0) {}\n\n  C(real x, real y) : x(x), y(y) {}\n  inline C operator+(const\
    \ C& c) const { return C(x + c.x, y + c.y); }\n  inline C operator-(const C& c)\
    \ const { return C(x - c.x, y - c.y); }\n  inline C operator*(const C& c) const\
    \ {\n    return C(x * c.x - y * c.y, x * c.y + y * c.x);\n  }\n\n  inline C conj()\
    \ const { return C(x, -y); }\n};\n\nconst real PI = acosl(-1);\nint base = 1;\n\
    vector<C> rts = {{0, 0}, {1, 0}};\nvector<int> rev = {0, 1};\n\nvoid ensure_base(int\
    \ nbase) {\n  if (nbase <= base) return;\n  rev.resize(1 << nbase);\n  rts.resize(1\
    \ << nbase);\n  for (int i = 0; i < (1 << nbase); i++) {\n    rev[i] = (rev[i\
    \ >> 1] >> 1) + ((i & 1) << (nbase - 1));\n  }\n  while (base < nbase) {\n   \
    \ real angle = PI * 2.0 / (1 << (base + 1));\n    for (int i = 1 << (base - 1);\
    \ i < (1 << base); i++) {\n      rts[i << 1] = rts[i];\n      real angle_i = angle\
    \ * (2 * i + 1 - (1 << base));\n      rts[(i << 1) + 1] = C(cos(angle_i), sin(angle_i));\n\
    \    }\n    ++base;\n  }\n}\n\nvoid fft(vector<C>& a, int n) {\n  assert((n &\
    \ (n - 1)) == 0);\n  int zeros = __builtin_ctz(n);\n  ensure_base(zeros);\n  int\
    \ shift = base - zeros;\n  for (int i = 0; i < n; i++) {\n    if (i < (rev[i]\
    \ >> shift)) { swap(a[i], a[rev[i] >> shift]); }\n  }\n  for (int k = 1; k < n;\
    \ k <<= 1) {\n    for (int i = 0; i < n; i += 2 * k) {\n      for (int j = 0;\
    \ j < k; j++) {\n        C z = a[i + j + k] * rts[j + k];\n        a[i + j + k]\
    \ = a[i + j] - z;\n        a[i + j] = a[i + j] + z;\n      }\n    }\n  }\n}\n\
    } // namespace CFFT\n#line 9 \"library/poly/convolution.hpp\"\n\ntemplate <class\
    \ mint>\nvector<mint> convolution_ntt(vector<mint> a, vector<mint> b) {\n  if\
    \ (a.empty() || b.empty()) return {};\n  int n = int(a.size()), m = int(b.size());\n\
    \  int sz = 1;\n  while (sz < n + m - 1) sz *= 2;\n\n  // sz = 2^k \u306E\u3068\
    \u304D\u306E\u9AD8\u901F\u5316\u3002\u5206\u5272\u7D71\u6CBB\u7684\u306A\u3084\
    \u3064\u3067\u640D\u3057\u307E\u304F\u308B\u306E\u3067\u3002\n  if ((n + m - 3)\
    \ <= sz / 2) {\n    auto a_last = a.back(), b_last = b.back();\n    a.pop_back(),\
    \ b.pop_back();\n    auto c = convolution(a, b);\n    c.resize(n + m - 1);\n \
    \   c[n + m - 2] = a_last * b_last;\n    FOR(i, len(a)) c[i + len(b)] += a[i]\
    \ * b_last;\n    FOR(i, len(b)) c[i + len(a)] += b[i] * a_last;\n    return c;\n\
    \  }\n\n  a.resize(sz), b.resize(sz);\n  bool same = a == b;\n  ntt(a, 0);\n \
    \ if (same) {\n    b = a;\n  } else {\n    ntt(b, 0);\n  }\n  FOR(i, sz) a[i]\
    \ *= b[i];\n  ntt(a, 1);\n  a.resize(n + m - 1);\n  return a;\n}\n\ntemplate <typename\
    \ mint>\nvector<mint> convolution_garner(const vector<mint>& a, const vector<mint>&\
    \ b) {\n  int n = len(a), m = len(b);\n  if (!n || !m) return {};\n  static constexpr\
    \ int p0 = 167772161;\n  static constexpr int p1 = 469762049;\n  static constexpr\
    \ int p2 = 754974721;\n  using mint0 = modint<p0>;\n  using mint1 = modint<p1>;\n\
    \  using mint2 = modint<p2>;\n  vc<mint0> a0(n), b0(m);\n  vc<mint1> a1(n), b1(m);\n\
    \  vc<mint2> a2(n), b2(m);\n  FOR(i, n) a0[i] = a[i].val, a1[i] = a[i].val, a2[i]\
    \ = a[i].val;\n  FOR(i, m) b0[i] = b[i].val, b1[i] = b[i].val, b2[i] = b[i].val;\n\
    \  auto c0 = convolution_ntt<mint0>(a0, b0);\n  auto c1 = convolution_ntt<mint1>(a1,\
    \ b1);\n  auto c2 = convolution_ntt<mint2>(a2, b2);\n  vc<mint> c(len(c0));\n\
    \  FOR(i, n + m - 1) {\n    c[i] = CRT3<mint, p0, p1, p2>(c0[i].val, c1[i].val,\
    \ c2[i].val);\n  }\n  return c;\n}\n\ntemplate <typename R>\nvc<double> convolution_fft(const\
    \ vc<R>& a, const vc<R>& b) {\n  using C = CFFT::C;\n  int need = (int)a.size()\
    \ + (int)b.size() - 1;\n  int nbase = 1;\n  while ((1 << nbase) < need) nbase++;\n\
    \  CFFT::ensure_base(nbase);\n  int sz = 1 << nbase;\n  vector<C> fa(sz);\n  for\
    \ (int i = 0; i < sz; i++) {\n    double x = (i < (int)a.size() ? a[i] : 0);\n\
    \    double y = (i < (int)b.size() ? b[i] : 0);\n    fa[i] = C(x, y);\n  }\n \
    \ CFFT::fft(fa, sz);\n  C r(0, -0.25 / (sz >> 1)), s(0, 1), t(0.5, 0);\n  for\
    \ (int i = 0; i <= (sz >> 1); i++) {\n    int j = (sz - i) & (sz - 1);\n    C\
    \ z = (fa[j] * fa[j] - (fa[i] * fa[i]).conj()) * r;\n    fa[j] = (fa[i] * fa[i]\
    \ - (fa[j] * fa[j]).conj()) * r;\n    fa[i] = z;\n  }\n  for (int i = 0; i < (sz\
    \ >> 1); i++) {\n    C A0 = (fa[i] + fa[i + (sz >> 1)]) * t;\n    C A1 = (fa[i]\
    \ - fa[i + (sz >> 1)]) * t * CFFT::rts[(sz >> 1) + i];\n    fa[i] = A0 + A1 *\
    \ s;\n  }\n  CFFT::fft(fa, sz >> 1);\n  vector<double> ret(need);\n  for (int\
    \ i = 0; i < need; i++) {\n    ret[i] = (i & 1 ? fa[i >> 1].y : fa[i >> 1].x);\n\
    \  }\n  return ret;\n}\n\nvector<ll> convolution(const vector<ll>& a, const vector<ll>&\
    \ b) {\n  int n = len(a), m = len(b);\n  if (!n || !m) return {};\n  if (min(n,\
    \ m) <= 2500) return convolution_naive(a, b);\n  ll abs_sum_a = 0, abs_sum_b =\
    \ 0;\n  ll LIM = 1e15;\n  FOR(i, n) abs_sum_a = min(LIM, abs_sum_a + abs(a[i]));\n\
    \  FOR(i, m) abs_sum_b = min(LIM, abs_sum_b + abs(b[i]));\n  if (i128(abs_sum_a)\
    \ * abs_sum_b < 1e15) {\n    vc<double> c = convolution_fft<ll>(a, b);\n    vc<ll>\
    \ res(len(c));\n    FOR(i, len(c)) res[i] = ll(floor(c[i] + .5));\n    return\
    \ res;\n  }\n\n  static constexpr unsigned long long MOD1 = 754974721; // 2^24\n\
    \  static constexpr unsigned long long MOD2 = 167772161; // 2^25\n  static constexpr\
    \ unsigned long long MOD3 = 469762049; // 2^26\n  static constexpr unsigned long\
    \ long M2M3 = MOD2 * MOD3;\n  static constexpr unsigned long long M1M3 = MOD1\
    \ * MOD3;\n  static constexpr unsigned long long M1M2 = MOD1 * MOD2;\n  static\
    \ constexpr unsigned long long M1M2M3 = MOD1 * MOD2 * MOD3;\n\n  static const\
    \ unsigned long long i1 = mod_inv(MOD2 * MOD3, MOD1);\n  static const unsigned\
    \ long long i2 = mod_inv(MOD1 * MOD3, MOD2);\n  static const unsigned long long\
    \ i3 = mod_inv(MOD1 * MOD2, MOD3);\n\n  using mint1 = modint<MOD1>;\n  using mint2\
    \ = modint<MOD2>;\n  using mint3 = modint<MOD3>;\n\n  vc<mint1> a1(n), b1(m);\n\
    \  vc<mint2> a2(n), b2(m);\n  vc<mint3> a3(n), b3(m);\n  FOR(i, n) a1[i] = a[i],\
    \ a2[i] = a[i], a3[i] = a[i];\n  FOR(i, m) b1[i] = b[i], b2[i] = b[i], b3[i] =\
    \ b[i];\n\n  auto c1 = convolution_ntt<mint1>(a1, b1);\n  auto c2 = convolution_ntt<mint2>(a2,\
    \ b2);\n  auto c3 = convolution_ntt<mint3>(a3, b3);\n\n  vc<ll> c(n + m - 1);\n\
    \  FOR(i, n + m - 1) {\n    u64 x = 0;\n    x += (c1[i].val * i1) % MOD1 * M2M3;\n\
    \    x += (c2[i].val * i2) % MOD2 * M1M3;\n    x += (c3[i].val * i3) % MOD3 *\
    \ M1M2;\n    ll diff = c1[i].val - ((long long)(x) % (long long)(MOD1));\n   \
    \ if (diff < 0) diff += MOD1;\n    static constexpr unsigned long long offset[5]\n\
    \        = {0, 0, M1M2M3, 2 * M1M2M3, 3 * M1M2M3};\n    x -= offset[diff % 5];\n\
    \    c[i] = x;\n  }\n  return c;\n}\n\ntemplate <typename mint>\nvc<mint> convolution(const\
    \ vc<mint>& a, const vc<mint>& b) {\n  int n = len(a), m = len(b);\n  if (!n ||\
    \ !m) return {};\n  if (mint::can_ntt()) {\n    if (min(n, m) <= 50) return convolution_karatsuba<mint>(a,\
    \ b);\n    return convolution_ntt(a, b);\n  }\n  if (min(n, m) <= 200) return\
    \ convolution_karatsuba<mint>(a, b);\n  return convolution_garner(a, b);\n}\n\
    #line 2 \"library/poly/transposed_ntt.hpp\"\n\ntemplate <class mint>\nvoid transposed_ntt(vector<mint>&\
    \ a, bool inverse) {\n  assert(mint::can_ntt());\n  const int rank2 = mint::ntt_info().fi;\n\
    \  const int mod = mint::get_mod();\n  static array<mint, 30> root, iroot;\n \
    \ static array<mint, 30> rate2, irate2;\n  static array<mint, 30> rate3, irate3;\n\
    \n  assert(rank2 != -1 && len(a) <= (1 << max(0, rank2)));\n\n  static bool prepared\
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
    \ & -~s)];\n        }\n        len += 2;\n      }\n    }\n  }\n}\n#line 2 \"library/poly/fps_div.hpp\"\
    \n\n#line 2 \"library/poly/count_terms.hpp\"\ntemplate<typename mint>\nint count_terms(const\
    \ vc<mint>& f){\n  int t = 0;\n  FOR(i, len(f)) if(f[i] != mint(0)) ++t;\n  return\
    \ t;\n}\n#line 4 \"library/poly/fps_inv.hpp\"\n\ntemplate <typename mint>\nvc<mint>\
    \ fps_inv_sparse(const vc<mint>& f) {\n  int N = len(f);\n  vc<pair<int, mint>>\
    \ dat;\n  FOR(i, 1, N) if (f[i] != mint(0)) dat.eb(i, f[i]);\n  vc<mint> g(N);\n\
    \  mint g0 = mint(1) / f[0];\n  g[0] = g0;\n  FOR(n, 1, N) {\n    mint rhs = 0;\n\
    \    for (auto&& [k, fk]: dat) {\n      if (k > n) break;\n      rhs -= fk * g[n\
    \ - k];\n    }\n    g[n] = rhs * g0;\n  }\n  return g;\n}\n\ntemplate <typename\
    \ mint>\nvc<mint> fps_inv_dense_ntt(const vc<mint>& F) {\n  vc<mint> G = {mint(1)\
    \ / F[0]};\n  ll N = len(F), n = 1;\n  G.reserve(N);\n  while (n < N) {\n    vc<mint>\
    \ f(2 * n), g(2 * n);\n    FOR(i, min(N, 2 * n)) f[i] = F[i];\n    FOR(i, n) g[i]\
    \ = G[i];\n    ntt(f, false), ntt(g, false);\n    FOR(i, 2 * n) f[i] *= g[i];\n\
    \    ntt(f, true);\n    FOR(i, n) f[i] = 0;\n    ntt(f, false);\n    FOR(i, 2\
    \ * n) f[i] *= g[i];\n    ntt(f, true);\n    FOR(i, n, min(N, 2 * n)) G.eb(-f[i]);\n\
    \    n *= 2;\n  }\n  return G;\n}\n\ntemplate <typename mint>\nvc<mint> fps_inv_dense(const\
    \ vc<mint>& F) {\n  if (mint::can_ntt()) return fps_inv_dense_ntt(F);\n  const\
    \ int N = len(F);\n  vc<mint> R = {mint(1) / F[0]};\n  vc<mint> p;\n  int m =\
    \ 1;\n  while (m < N) {\n    p = convolution(R, R);\n    p.resize(m + m);\n  \
    \  vc<mint> f = {F.begin(), F.begin() + min(m + m, N)};\n    p = convolution(p,\
    \ f);\n    R.resize(m + m);\n    FOR(i, m + m) R[i] = R[i] + R[i] - p[i];\n  \
    \  m += m;\n  }\n  R.resize(N);\n  return R;\n}\n\ntemplate <typename mint>\n\
    vc<mint> fps_inv(const vc<mint>& f) {\n  assert(f[0] != mint(0));\n  int n = count_terms(f);\n\
    \  int t = (mint::can_ntt() ? 160 : 820);\n  return (n <= t ? fps_inv_sparse<mint>(f)\
    \ : fps_inv_dense<mint>(f));\n}\n#line 5 \"library/poly/fps_div.hpp\"\n\n// f/g.\
    \ f \u306E\u9577\u3055\u3067\u51FA\u529B\u3055\u308C\u308B.\ntemplate <typename\
    \ mint, bool SPARSE = false>\nvc<mint> fps_div(vc<mint> f, vc<mint> g) {\n  if\
    \ (SPARSE || count_terms(g) < 200) return fps_div_sparse(f, g);\n  int n = len(f);\n\
    \  g.resize(n);\n  g = fps_inv<mint>(g);\n  f = convolution(f, g);\n  f.resize(n);\n\
    \  return f;\n}\n\n// f/g \u305F\u3060\u3057 g \u306F sparse\ntemplate <typename\
    \ mint>\nvc<mint> fps_div_sparse(vc<mint> f, vc<mint>& g) {\n  if (g[0] != mint(1))\
    \ {\n    mint cf = g[0].inverse();\n    for (auto&& x: f) x *= cf;\n    for (auto&&\
    \ x: g) x *= cf;\n  }\n\n  vc<pair<int, mint>> dat;\n  FOR(i, 1, len(g)) if (g[i]\
    \ != mint(0)) dat.eb(i, -g[i]);\n  FOR(i, len(f)) {\n    for (auto&& [j, x]: dat)\
    \ {\n      if (i >= j) f[i] += x * f[i - j];\n    }\n  }\n  return f;\n}\n#line\
    \ 2 \"library/poly/poly_divmod.hpp\"\n\n#line 4 \"library/poly/poly_divmod.hpp\"\
    \ntemplate <typename mint>\npair<vc<mint>, vc<mint>> poly_divmod(vc<mint> f, vc<mint>\
    \ g) {\n  assert(g.back() != 0);\n  if (len(f) < len(g)) { return {{}, f}; }\n\
    \  auto rf = f, rg = g;\n  reverse(all(rf)), reverse(all(rg));\n  ll deg = len(rf)\
    \ - len(rg) + 1;\n  rf.resize(deg), rg.resize(deg);\n  rg = fps_inv(rg);\n  auto\
    \ q = convolution(rf, rg);\n  q.resize(deg);\n  reverse(all(q));\n  auto h = convolution(q,\
    \ g);\n  FOR(i, len(f)) f[i] -= h[i];\n  while (len(f) > 0 && f.back() == 0) f.pop_back();\n\
    \  return {q, f};\n}\n#line 5 \"library/poly/slice_rational_fps.hpp\"\n\ntemplate\
    \ <typename mint>\nvc<mint> slice_rational_fps(vector<mint> P, vector<mint> Q,\
    \ ll L, ll R) {\n  while (len(Q) && Q.back() == mint(0)) POP(Q);\n  assert(Q[0]\
    \ == mint(1));\n  if (len(Q) == 1) {\n    vc<mint> ANS(R - L);\n    FOR(i, L,\
    \ R) if (i < len(P)) ANS[i - L] = P[i];\n    return ANS;\n  }\n  vc<mint> Q0 =\
    \ Q;\n\n  int n = 1;\n  while (n < len(Q)) n += n;\n  Q.resize(2 * n), ntt(Q,\
    \ 0);\n\n  vc<mint> W(n);\n  {\n    vc<int> btr(n);\n    int log = topbit(n);\n\
    \    FOR(i, n) { btr[i] = (btr[i >> 1] >> 1) + ((i & 1) << (log - 1)); }\n   \
    \ int t = mint::ntt_info().fi;\n    mint r = mint::ntt_info().se;\n    mint dw\
    \ = r.inverse().pow((1 << t) / (2 * n));\n    mint w = 1;\n    for (auto& i: btr)\
    \ { W[i] = w, w *= dw; }\n  }\n\n  mint z = W[n / 2].inverse();\n  auto doubling\
    \ = [&](vc<mint> f, bool t) -> vc<mint> {\n    mint r = 1;\n    if (!t) {\n  \
    \    vc<mint> g(2 * n);\n      copy(all(f), g.begin());\n      ntt(f, 1);\n  \
    \    FOR(i, 1, n) r *= z, f[i] *= r;\n      ntt(f, 0);\n      copy(all(f), g.begin()\
    \ + n);\n      return g;\n    } else {\n      vc<mint> g = {f.begin(), f.begin()\
    \ + n};\n      f = {f.begin() + n, f.begin() + 2 * n};\n      transposed_ntt(f,\
    \ 0);\n      FOR(i, 1, n) r *= z, f[i] *= r;\n      transposed_ntt(f, 1);\n  \
    \    FOR(i, n) g[i] += f[i];\n      return g;\n    }\n  };\n\n  auto dfs = [&](auto&\
    \ dfs, vc<mint> Q, ll N) -> vc<mint> {\n    vc<mint> nxt_Q(2 * n);\n    FOR(i,\
    \ n) nxt_Q[i] = Q[2 * i] * Q[2 * i + 1];\n    nxt_Q.resize(n);\n    vc<mint> p;\n\
    \    if (N / 2 >= n) {\n      nxt_Q = doubling(nxt_Q, 0);\n      p = dfs(dfs,\
    \ nxt_Q, N / 2);\n      p = doubling(p, 1);\n    } else {\n      ntt(nxt_Q, 1);\n\
    \      nxt_Q = fps_inv<mint>(nxt_Q);\n      p.resize(n);\n      FOR(i, N / 2 +\
    \ 1) p[i] += nxt_Q[N / 2 - i];\n      transposed_ntt(p, 1);\n    }\n    assert(len(p)\
    \ == n);\n    p.resize(2 * n);\n    if (N % 2 == 0) {\n      FOR_R(i, n) {\n \
    \       p[2 * i + 1] = Q[2 * i + 0] * inv<mint>(2) * p[i];\n        p[2 * i +\
    \ 0] = Q[2 * i + 1] * inv<mint>(2) * p[i];\n      }\n    } else {\n      FOR_R(i,\
    \ n) {\n        p[2 * i + 1] = -Q[2 * i + 0] * inv<mint>(2) * W[i] * p[i];\n \
    \       p[2 * i + 0] = Q[2 * i + 1] * inv<mint>(2) * W[i] * p[i];\n      }\n \
    \   }\n    assert(len(p) == 2 * n);\n    return p;\n  };\n\n  vc<mint> p = dfs(dfs,\
    \ Q, L + n - 1);\n  transposed_ntt(p, 0);\n  p.resize(n);\n  reverse(all(p));\n\
    \  swap(Q, Q0);\n  p.resize(len(Q) - 1);\n  // 1/Q \u306E L \u4EE5\u964D\u304C\
    \ p \u3067\u306F\u3058\u307E\u308B\n  auto [f, g] = poly_divmod(P, Q);\n  p =\
    \ convolution<mint>(p, Q);\n  p.resize(len(Q) - 1);\n  p = convolution<mint>(p,\
    \ g);\n  p = poly_divmod(p, Q).se;\n  p.resize(R - L);\n  Q.resize(R - L);\n \
    \ p = fps_div<mint>(p, Q);\n  FOR(i, L, len(f)) if (i < R) p[i - L] += f[i];\n\
    \  return p;\n}\n#line 7 \"main.cpp\"\n\nusing mint = modint998;\n\nvc<mint> gen(int\
    \ n) {\n  vc<mint> f(n);\n  FOR(i, n) f[i] = RNG(0, 100);\n  return f;\n}\n\n\
    void test() {\n  using poly = vc<mint>;\n  FOR(n, 1, 10) FOR(m, n) {\n    poly\
    \ P = gen(m), Q = gen(n);\n    Q[0] = mint(1);\n    poly f = P, g = Q;\n    f.resize(100),\
    \ g.resize(100);\n    vc<mint> F = fps_div(f, g);\n    FOR(i, 50) {\n      poly\
    \ A = slice_rational_fps(P, Q, i, i + n - 1);\n      poly B = {F.begin() + i,\
    \ F.begin() + i + n - 1};\n      assert(A == B);\n    }\n  }\n  int n = 500;\n\
    \  int m = 499;\n  poly P = gen(m), Q = gen(n);\n  Q[0] = mint(1);\n  poly f =\
    \ P, g = Q;\n  f.resize(1000), g.resize(1000);\n  vc<mint> F = fps_div(f, g);\n\
    \  FOR(i, 500) {\n    auto A = slice_rational_fps(P, Q, i, i + n - 1);\n    poly\
    \ B = {F.begin() + i, F.begin() + i + n - 1};\n    assert(A == B);\n  }\n}\n\n\
    void solve() {\n  int a, b;\n  cin >> a >> b;\n  cout << a + b << \"\\n\";\n}\n\
    \nsigned main() {\n  test();\n  solve();\n  return 0;\n}\n"
  dependsOn: []
  isVerificationFile: true
  path: test/1_mytest/slice_rational_fps.test.cpp
  requiredBy: []
  timestamp: '2024-08-13 23:38:32+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: test/1_mytest/slice_rational_fps.test.cpp
layout: document
redirect_from:
- /verify/test/1_mytest/slice_rational_fps.test.cpp
- /verify/test/1_mytest/slice_rational_fps.test.cpp.html
title: test/1_mytest/slice_rational_fps.test.cpp
---
