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
    - https://judge.yosupo.jp/problem/aplusb
    - https://oeis.org/A000272
    - https://oeis.org/A001858
    - https://trap.jp/post/1224/
  bundledCode: "#line 1 \"test/mytest/count_labeled_forest.test.cpp\"\n#line 1 \"\
    main.cpp\"\n#define PROBLEM \"https://judge.yosupo.jp/problem/aplusb\"\n\n#line\
    \ 1 \"library/my_template.hpp\"\n#if defined(LOCAL)\n#include <my_template_compiled.hpp>\n\
    #else\n#pragma GCC optimize(\"Ofast\")\n#pragma GCC optimize(\"unroll-loops\"\
    )\n\n#include <bits/stdc++.h>\n\nusing namespace std;\n\nusing ll = long long;\n\
    using u32 = unsigned int;\nusing u64 = unsigned long long;\nusing i128 = __int128;\n\
    using u128 = unsigned __int128;\nusing f128 = __float128;\n\ntemplate <class T>\n\
    constexpr T infty = 0;\ntemplate <>\nconstexpr int infty<int> = 1'000'000'000;\n\
    template <>\nconstexpr ll infty<ll> = ll(infty<int>) * infty<int> * 2;\ntemplate\
    \ <>\nconstexpr u32 infty<u32> = infty<int>;\ntemplate <>\nconstexpr u64 infty<u64>\
    \ = infty<ll>;\ntemplate <>\nconstexpr i128 infty<i128> = i128(infty<ll>) * infty<ll>;\n\
    template <>\nconstexpr double infty<double> = infty<ll>;\ntemplate <>\nconstexpr\
    \ long double infty<long double> = infty<ll>;\n\nusing pi = pair<ll, ll>;\nusing\
    \ vi = vector<ll>;\ntemplate <class T>\nusing vc = vector<T>;\ntemplate <class\
    \ T>\nusing vvc = vector<vc<T>>;\ntemplate <class T>\nusing vvvc = vector<vvc<T>>;\n\
    template <class T>\nusing vvvvc = vector<vvvc<T>>;\ntemplate <class T>\nusing\
    \ vvvvvc = vector<vvvvc<T>>;\ntemplate <class T>\nusing pq = priority_queue<T>;\n\
    template <class T>\nusing pqg = priority_queue<T, vector<T>, greater<T>>;\n\n\
    #define vv(type, name, h, ...) \\\n  vector<vector<type>> name(h, vector<type>(__VA_ARGS__))\n\
    #define vvv(type, name, h, w, ...)   \\\n  vector<vector<vector<type>>> name(\
    \ \\\n      h, vector<vector<type>>(w, vector<type>(__VA_ARGS__)))\n#define vvvv(type,\
    \ name, a, b, c, ...)       \\\n  vector<vector<vector<vector<type>>>> name( \\\
    \n      a, vector<vector<vector<type>>>(       \\\n             b, vector<vector<type>>(c,\
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
    \  return B;\n}\n#endif\n#line 4 \"main.cpp\"\n\n#line 2 \"library/mod/modint_common.hpp\"\
    \n\nstruct has_mod_impl {\n  template <class T>\n  static auto check(T&& x) ->\
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
    }\n\ntemplate <typename mint, class Head, class... Tail>\nmint multinomial(Head&&\
    \ head, Tail&&... tail) {\n  return fact<mint>(head) * fact_invs<mint>(std::forward<Tail>(tail)...);\n\
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
    \ large, dense>(n + d - 1, d);\n}\n#line 3 \"library/mod/modint.hpp\"\n\ntemplate\
    \ <int mod>\nstruct modint {\n  static constexpr u32 umod = u32(mod);\n  static_assert(umod\
    \ < u32(1) << 31);\n  u32 val;\n\n  static modint raw(u32 v) {\n    modint x;\n\
    \    x.val = v;\n    return x;\n  }\n  constexpr modint() : val(0) {}\n  constexpr\
    \ modint(u32 x) : val(x % umod) {}\n  constexpr modint(u64 x) : val(x % umod)\
    \ {}\n  constexpr modint(u128 x) : val(x % umod) {}\n  constexpr modint(int x)\
    \ : val((x %= mod) < 0 ? x + mod : x){};\n  constexpr modint(ll x) : val((x %=\
    \ mod) < 0 ? x + mod : x){};\n  constexpr modint(i128 x) : val((x %= mod) < 0\
    \ ? x + mod : x){};\n  bool operator<(const modint& other) const { return val\
    \ < other.val; }\n  modint& operator+=(const modint& p) {\n    if ((val += p.val)\
    \ >= umod) val -= umod;\n    return *this;\n  }\n  modint& operator-=(const modint&\
    \ p) {\n    if ((val += umod - p.val) >= umod) val -= umod;\n    return *this;\n\
    \  }\n  modint& operator*=(const modint& p) {\n    val = u64(val) * p.val % umod;\n\
    \    return *this;\n  }\n  modint& operator/=(const modint& p) {\n    *this *=\
    \ p.inverse();\n    return *this;\n  }\n  modint operator-() const { return modint::raw(val\
    \ ? mod - val : u32(0)); }\n  modint operator+(const modint& p) const { return\
    \ modint(*this) += p; }\n  modint operator-(const modint& p) const { return modint(*this)\
    \ -= p; }\n  modint operator*(const modint& p) const { return modint(*this) *=\
    \ p; }\n  modint operator/(const modint& p) const { return modint(*this) /= p;\
    \ }\n  bool operator==(const modint& p) const { return val == p.val; }\n  bool\
    \ operator!=(const modint& p) const { return val != p.val; }\n  modint inverse()\
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
    \ 1045430273) return {20, 363};\n    if (mod == 1051721729) return {20, 330};\n\
    \    if (mod == 1053818881) return {20, 2789};\n    return {-1, -1};\n  }\n  static\
    \ constexpr bool can_ntt() { return ntt_info().fi != -1; }\n};\n\n#ifdef FASTIO\n\
    template <int mod>\nvoid rd(modint<mod>& x) {\n  fastio::rd(x.val);\n  x.val %=\
    \ mod;\n  // assert(0 <= x.val && x.val < mod);\n}\ntemplate <int mod>\nvoid wt(modint<mod>\
    \ x) {\n  fastio::wt(x.val);\n}\n#endif\n\nusing modint107 = modint<1000000007>;\n\
    using modint998 = modint<998244353>;\n#line 2 \"library/mod/mod_inv.hpp\"\n\n\
    // long \u3067\u3082\u5927\u4E08\u592B\n// (val * x - 1) \u304C mod \u306E\u500D\
    \u6570\u306B\u306A\u308B\u3088\u3046\u306B\u3059\u308B\n// \u7279\u306B mod=0\
    \ \u306A\u3089 x=0 \u304C\u6E80\u305F\u3059\nll mod_inv(ll val, ll mod) {\n  if\
    \ (mod == 0) return 0;\n  mod = abs(mod);\n  val %= mod;\n  if (val < 0) val +=\
    \ mod;\n  ll a = val, b = mod, u = 1, v = 0, t;\n  while (b > 0) {\n    t = a\
    \ / b;\n    swap(a -= t * b, b), swap(u -= t * v, v);\n  }\n  if (u < 0) u +=\
    \ mod;\n  return u;\n}\n#line 1 \"library/mod/crt3.hpp\"\n\nconstexpr u32 mod_pow_constexpr(u64\
    \ a, u64 n, u32 mod) {\n  a %= mod;\n  u64 res = 1;\n  FOR(32) {\n    if (n &\
    \ 1) res = res * a % mod;\n    a = a * a % mod, n /= 2;\n  }\n  return res;\n\
    }\n\ntemplate <typename T, u32 p0, u32 p1, u32 p2>\nT CRT3(u64 a0, u64 a1, u64\
    \ a2) {\n  static_assert(p0 < p1 && p1 < p2);\n  static constexpr u64 x0_1 = mod_pow_constexpr(p0,\
    \ p1 - 2, p1);\n  static constexpr u64 x01_2 = mod_pow_constexpr(u64(p0) * p1\
    \ % p2, p2 - 2, p2);\n  u64 c = (a1 - a0 + p1) * x0_1 % p1;\n  u64 a = a0 + c\
    \ * p0;\n  c = (a2 - a % p2 + p2) * x01_2 % p2;\n  return T(a) + T(c) * T(p0)\
    \ * T(p1);\n}\n#line 2 \"library/poly/convolution_naive.hpp\"\n\ntemplate <class\
    \ T, typename enable_if<!has_mod<T>::value>::type* = nullptr>\nvc<T> convolution_naive(const\
    \ vc<T>& a, const vc<T>& b) {\n  int n = int(a.size()), m = int(b.size());\n \
    \ if (n > m) return convolution_naive<T>(b, a);\n  if (n == 0) return {};\n  vector<T>\
    \ ans(n + m - 1);\n  FOR(i, n) FOR(j, m) ans[i + j] += a[i] * b[j];\n  return\
    \ ans;\n}\n\ntemplate <class T, typename enable_if<has_mod<T>::value>::type* =\
    \ nullptr>\nvc<T> convolution_naive(const vc<T>& a, const vc<T>& b) {\n  int n\
    \ = int(a.size()), m = int(b.size());\n  if (n > m) return convolution_naive<T>(b,\
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
    #line 2 \"library/poly/integrate.hpp\"\n\n// \u4E0D\u5B9A\u7A4D\u5206\uFF1Aintegrate(f)\n\
    // \u5B9A\u7A4D\u5206\uFF1Aintegrate(f, L, R)\ntemplate <typename mint>\nvc<mint>\
    \ integrate(const vc<mint>& f) {\n  vc<mint> g(len(f) + 1);\n  FOR3(i, 1, len(g))\
    \ g[i] = f[i - 1] * inv<mint>(i);\n  return g;\n}\n\n// \u4E0D\u5B9A\u7A4D\u5206\
    \uFF1Aintegrate(f)\n// \u5B9A\u7A4D\u5206\uFF1Aintegrate(f, L, R)\ntemplate <typename\
    \ mint>\nmint integrate(const vc<mint>& f, mint L, mint R) {\n  mint I = 0;\n\
    \  mint pow_L = 1, pow_R = 1;\n  FOR(i, len(f)) {\n    pow_L *= L, pow_R *= R;\n\
    \    I += inv<mint>(i + 1) * f[i] * (pow_R - pow_L);\n  }\n  return I;\n}\n#line\
    \ 2 \"library/poly/differentiate.hpp\"\n\ntemplate <typename mint>\nvc<mint> differentiate(const\
    \ vc<mint>& f) {\n  if (len(f) <= 1) return {};\n  vc<mint> g(len(f) - 1);\n \
    \ FOR(i, len(g)) g[i] = f[i + 1] * mint(i + 1);\n  return g;\n}\n#line 2 \"library/poly/count_terms.hpp\"\
    \ntemplate <typename mint>\nint count_terms(const vc<mint>& f) {\n  int t = 0;\n\
    \  FOR(i, len(f)) if (f[i] != mint(0))++ t;\n  return t;\n}\n#line 6 \"library/poly/fps_exp.hpp\"\
    \n\ntemplate <typename mint>\nvc<mint> fps_exp_sparse(vc<mint>& f) {\n  if (len(f)\
    \ == 0) return {mint(1)};\n  assert(f[0] == 0);\n  int N = len(f);\n  // df \u3092\
    \u6301\u305F\u305B\u308B\n  vc<pair<int, mint>> dat;\n  FOR(i, 1, N) if (f[i]\
    \ != mint(0)) dat.eb(i - 1, mint(i) * f[i]);\n  vc<mint> F(N);\n  F[0] = 1;\n\
    \  FOR(n, 1, N) {\n    mint rhs = 0;\n    for (auto&& [k, fk]: dat) {\n      if\
    \ (k > n - 1) break;\n      rhs += fk * F[n - 1 - k];\n    }\n    F[n] = rhs *\
    \ inv<mint>(n);\n  }\n  return F;\n}\n\ntemplate <typename mint>\nvc<mint> fps_exp_dense(vc<mint>&\
    \ h) {\n  const int n = len(h);\n  assert(n > 0 && h[0] == mint(0));\n  if (mint::can_ntt())\
    \ {\n    vc<mint>& f = h;\n    vc<mint> b = {1, (1 < n ? f[1] : 0)};\n    vc<mint>\
    \ c = {1}, z1, z2 = {1, 1};\n    while (len(b) < n) {\n      int m = len(b);\n\
    \      auto y = b;\n      y.resize(2 * m);\n      ntt(y, 0);\n      z1 = z2;\n\
    \      vc<mint> z(m);\n      FOR(i, m) z[i] = y[i] * z1[i];\n      ntt(z, 1);\n\
    \      FOR(i, m / 2) z[i] = 0;\n      ntt(z, 0);\n      FOR(i, m) z[i] *= -z1[i];\n\
    \      ntt(z, 1);\n      c.insert(c.end(), z.begin() + m / 2, z.end());\n    \
    \  z2 = c;\n      z2.resize(2 * m);\n      ntt(z2, 0);\n\n      vc<mint> x(f.begin(),\
    \ f.begin() + m);\n      FOR(i, len(x) - 1) x[i] = x[i + 1] * mint(i + 1);\n \
    \     x.back() = 0;\n      ntt(x, 0);\n      FOR(i, m) x[i] *= y[i];\n      ntt(x,\
    \ 1);\n\n      FOR(i, m - 1) x[i] -= b[i + 1] * mint(i + 1);\n\n      x.resize(m\
    \ + m);\n      FOR(i, m - 1) x[m + i] = x[i], x[i] = 0;\n      ntt(x, 0);\n  \
    \    FOR(i, m + m) x[i] *= z2[i];\n      ntt(x, 1);\n      FOR_R(i, len(x) - 1)\
    \ x[i + 1] = x[i] * inv<mint>(i + 1);\n      x[0] = 0;\n\n      FOR3(i, m, min(n,\
    \ m + m)) x[i] += f[i];\n      FOR(i, m) x[i] = 0;\n      ntt(x, 0);\n      FOR(i,\
    \ m + m) x[i] *= y[i];\n      ntt(x, 1);\n      b.insert(b.end(), x.begin() +\
    \ m, x.end());\n    }\n    b.resize(n);\n    return b;\n  }\n\n  const int L =\
    \ len(h);\n  assert(L > 0 && h[0] == mint(0));\n  int LOG = 0;\n  while (1 <<\
    \ LOG < L) ++LOG;\n  h.resize(1 << LOG);\n  auto dh = differentiate(h);\n  vc<mint>\
    \ f = {1}, g = {1};\n  int m = 1;\n\n  vc<mint> p;\n\n  FOR(LOG) {\n    p = convolution(f,\
    \ g);\n    p.resize(m);\n    p = convolution(p, g);\n    p.resize(m);\n    g.resize(m);\n\
    \    FOR(i, m) g[i] += g[i] - p[i];\n    p = {dh.begin(), dh.begin() + m - 1};\n\
    \    p = convolution(f, p);\n    p.resize(m + m - 1);\n    FOR(i, m + m - 1) p[i]\
    \ = -p[i];\n    FOR(i, m - 1) p[i] += mint(i + 1) * f[i + 1];\n    p = convolution(p,\
    \ g);\n\n    p.resize(m + m - 1);\n    FOR(i, m - 1) p[i] += dh[i];\n    p = integrate(p);\n\
    \    FOR(i, m + m) p[i] = h[i] - p[i];\n    p[0] += mint(1);\n    f = convolution(f,\
    \ p);\n    f.resize(m + m);\n    m += m;\n  }\n  f.resize(L);\n  return f;\n}\n\
    \ntemplate <typename mint>\nvc<mint> fps_exp(vc<mint>& f) {\n  int n = count_terms(f);\n\
    \  int t = (mint::can_ntt() ? 320 : 3000);\n  return (n <= t ? fps_exp_sparse<mint>(f)\
    \ : fps_exp_dense<mint>(f));\n}\n#line 1 \"library/graph/count/count_labeled_tree.hpp\"\
    \n// https://oeis.org/A000272\ntemplate <typename mint>\nvc<mint> count_labeled_tree(ll\
    \ nmax) {\n  vc<mint> f(nmax + 1);\n  FOR(n, 1, nmax + 1) { f[n] = (n == 1 ? mint(1)\
    \ : mint(n).pow(n - 2)); }\n  return f;\n}\n#line 3 \"library/graph/count/count_labeled_forest.hpp\"\
    \n\n// https://oeis.org/A001858\ntemplate <typename mint>\nvc<mint> count_labeled_forest(int\
    \ N) {\n  vc<mint> f = count_labeled_tree<mint>(N);\n  FOR(i, len(f)) f[i] *=\
    \ fact_inv<mint>(i);\n  f = fps_exp(f);\n  FOR(i, len(f)) f[i] *= fact<mint>(i);\n\
    \  return f;\n}\n#line 7 \"main.cpp\"\n\nusing mint = modint998;\n\nvoid test()\
    \ {\n  vc<mint> F = count_labeled_forest<mint>(10);\n  vi ANS = {1, 1, 2, 7, 38,\
    \ 291, 2932, 36961, 561948, 10026505, 205608536};\n  FOR(n, 11) { assert(F[n]\
    \ == mint(ANS[n])); }\n}\n\nvoid solve() {\n  int a, b;\n  cin >> a >> b;\n  cout\
    \ << a + b << '\\n';\n}\n\nsigned main() {\n  test();\n  solve();\n  return 0;\n\
    }\n"
  code: "#line 1 \"main.cpp\"\n#define PROBLEM \"https://judge.yosupo.jp/problem/aplusb\"\
    \n\n#line 1 \"library/my_template.hpp\"\n#if defined(LOCAL)\n#include <my_template_compiled.hpp>\n\
    #else\n#pragma GCC optimize(\"Ofast\")\n#pragma GCC optimize(\"unroll-loops\"\
    )\n\n#include <bits/stdc++.h>\n\nusing namespace std;\n\nusing ll = long long;\n\
    using u32 = unsigned int;\nusing u64 = unsigned long long;\nusing i128 = __int128;\n\
    using u128 = unsigned __int128;\nusing f128 = __float128;\n\ntemplate <class T>\n\
    constexpr T infty = 0;\ntemplate <>\nconstexpr int infty<int> = 1'000'000'000;\n\
    template <>\nconstexpr ll infty<ll> = ll(infty<int>) * infty<int> * 2;\ntemplate\
    \ <>\nconstexpr u32 infty<u32> = infty<int>;\ntemplate <>\nconstexpr u64 infty<u64>\
    \ = infty<ll>;\ntemplate <>\nconstexpr i128 infty<i128> = i128(infty<ll>) * infty<ll>;\n\
    template <>\nconstexpr double infty<double> = infty<ll>;\ntemplate <>\nconstexpr\
    \ long double infty<long double> = infty<ll>;\n\nusing pi = pair<ll, ll>;\nusing\
    \ vi = vector<ll>;\ntemplate <class T>\nusing vc = vector<T>;\ntemplate <class\
    \ T>\nusing vvc = vector<vc<T>>;\ntemplate <class T>\nusing vvvc = vector<vvc<T>>;\n\
    template <class T>\nusing vvvvc = vector<vvvc<T>>;\ntemplate <class T>\nusing\
    \ vvvvvc = vector<vvvvc<T>>;\ntemplate <class T>\nusing pq = priority_queue<T>;\n\
    template <class T>\nusing pqg = priority_queue<T, vector<T>, greater<T>>;\n\n\
    #define vv(type, name, h, ...) \\\n  vector<vector<type>> name(h, vector<type>(__VA_ARGS__))\n\
    #define vvv(type, name, h, w, ...)   \\\n  vector<vector<vector<type>>> name(\
    \ \\\n      h, vector<vector<type>>(w, vector<type>(__VA_ARGS__)))\n#define vvvv(type,\
    \ name, a, b, c, ...)       \\\n  vector<vector<vector<vector<type>>>> name( \\\
    \n      a, vector<vector<vector<type>>>(       \\\n             b, vector<vector<type>>(c,\
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
    \  return B;\n}\n#endif\n#line 4 \"main.cpp\"\n\n#line 2 \"library/mod/modint_common.hpp\"\
    \n\nstruct has_mod_impl {\n  template <class T>\n  static auto check(T&& x) ->\
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
    }\n\ntemplate <typename mint, class Head, class... Tail>\nmint multinomial(Head&&\
    \ head, Tail&&... tail) {\n  return fact<mint>(head) * fact_invs<mint>(std::forward<Tail>(tail)...);\n\
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
    \ large, dense>(n + d - 1, d);\n}\n#line 3 \"library/mod/modint.hpp\"\n\ntemplate\
    \ <int mod>\nstruct modint {\n  static constexpr u32 umod = u32(mod);\n  static_assert(umod\
    \ < u32(1) << 31);\n  u32 val;\n\n  static modint raw(u32 v) {\n    modint x;\n\
    \    x.val = v;\n    return x;\n  }\n  constexpr modint() : val(0) {}\n  constexpr\
    \ modint(u32 x) : val(x % umod) {}\n  constexpr modint(u64 x) : val(x % umod)\
    \ {}\n  constexpr modint(u128 x) : val(x % umod) {}\n  constexpr modint(int x)\
    \ : val((x %= mod) < 0 ? x + mod : x){};\n  constexpr modint(ll x) : val((x %=\
    \ mod) < 0 ? x + mod : x){};\n  constexpr modint(i128 x) : val((x %= mod) < 0\
    \ ? x + mod : x){};\n  bool operator<(const modint& other) const { return val\
    \ < other.val; }\n  modint& operator+=(const modint& p) {\n    if ((val += p.val)\
    \ >= umod) val -= umod;\n    return *this;\n  }\n  modint& operator-=(const modint&\
    \ p) {\n    if ((val += umod - p.val) >= umod) val -= umod;\n    return *this;\n\
    \  }\n  modint& operator*=(const modint& p) {\n    val = u64(val) * p.val % umod;\n\
    \    return *this;\n  }\n  modint& operator/=(const modint& p) {\n    *this *=\
    \ p.inverse();\n    return *this;\n  }\n  modint operator-() const { return modint::raw(val\
    \ ? mod - val : u32(0)); }\n  modint operator+(const modint& p) const { return\
    \ modint(*this) += p; }\n  modint operator-(const modint& p) const { return modint(*this)\
    \ -= p; }\n  modint operator*(const modint& p) const { return modint(*this) *=\
    \ p; }\n  modint operator/(const modint& p) const { return modint(*this) /= p;\
    \ }\n  bool operator==(const modint& p) const { return val == p.val; }\n  bool\
    \ operator!=(const modint& p) const { return val != p.val; }\n  modint inverse()\
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
    \ 1045430273) return {20, 363};\n    if (mod == 1051721729) return {20, 330};\n\
    \    if (mod == 1053818881) return {20, 2789};\n    return {-1, -1};\n  }\n  static\
    \ constexpr bool can_ntt() { return ntt_info().fi != -1; }\n};\n\n#ifdef FASTIO\n\
    template <int mod>\nvoid rd(modint<mod>& x) {\n  fastio::rd(x.val);\n  x.val %=\
    \ mod;\n  // assert(0 <= x.val && x.val < mod);\n}\ntemplate <int mod>\nvoid wt(modint<mod>\
    \ x) {\n  fastio::wt(x.val);\n}\n#endif\n\nusing modint107 = modint<1000000007>;\n\
    using modint998 = modint<998244353>;\n#line 2 \"library/mod/mod_inv.hpp\"\n\n\
    // long \u3067\u3082\u5927\u4E08\u592B\n// (val * x - 1) \u304C mod \u306E\u500D\
    \u6570\u306B\u306A\u308B\u3088\u3046\u306B\u3059\u308B\n// \u7279\u306B mod=0\
    \ \u306A\u3089 x=0 \u304C\u6E80\u305F\u3059\nll mod_inv(ll val, ll mod) {\n  if\
    \ (mod == 0) return 0;\n  mod = abs(mod);\n  val %= mod;\n  if (val < 0) val +=\
    \ mod;\n  ll a = val, b = mod, u = 1, v = 0, t;\n  while (b > 0) {\n    t = a\
    \ / b;\n    swap(a -= t * b, b), swap(u -= t * v, v);\n  }\n  if (u < 0) u +=\
    \ mod;\n  return u;\n}\n#line 1 \"library/mod/crt3.hpp\"\n\nconstexpr u32 mod_pow_constexpr(u64\
    \ a, u64 n, u32 mod) {\n  a %= mod;\n  u64 res = 1;\n  FOR(32) {\n    if (n &\
    \ 1) res = res * a % mod;\n    a = a * a % mod, n /= 2;\n  }\n  return res;\n\
    }\n\ntemplate <typename T, u32 p0, u32 p1, u32 p2>\nT CRT3(u64 a0, u64 a1, u64\
    \ a2) {\n  static_assert(p0 < p1 && p1 < p2);\n  static constexpr u64 x0_1 = mod_pow_constexpr(p0,\
    \ p1 - 2, p1);\n  static constexpr u64 x01_2 = mod_pow_constexpr(u64(p0) * p1\
    \ % p2, p2 - 2, p2);\n  u64 c = (a1 - a0 + p1) * x0_1 % p1;\n  u64 a = a0 + c\
    \ * p0;\n  c = (a2 - a % p2 + p2) * x01_2 % p2;\n  return T(a) + T(c) * T(p0)\
    \ * T(p1);\n}\n#line 2 \"library/poly/convolution_naive.hpp\"\n\ntemplate <class\
    \ T, typename enable_if<!has_mod<T>::value>::type* = nullptr>\nvc<T> convolution_naive(const\
    \ vc<T>& a, const vc<T>& b) {\n  int n = int(a.size()), m = int(b.size());\n \
    \ if (n > m) return convolution_naive<T>(b, a);\n  if (n == 0) return {};\n  vector<T>\
    \ ans(n + m - 1);\n  FOR(i, n) FOR(j, m) ans[i + j] += a[i] * b[j];\n  return\
    \ ans;\n}\n\ntemplate <class T, typename enable_if<has_mod<T>::value>::type* =\
    \ nullptr>\nvc<T> convolution_naive(const vc<T>& a, const vc<T>& b) {\n  int n\
    \ = int(a.size()), m = int(b.size());\n  if (n > m) return convolution_naive<T>(b,\
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
    #line 2 \"library/poly/integrate.hpp\"\n\n// \u4E0D\u5B9A\u7A4D\u5206\uFF1Aintegrate(f)\n\
    // \u5B9A\u7A4D\u5206\uFF1Aintegrate(f, L, R)\ntemplate <typename mint>\nvc<mint>\
    \ integrate(const vc<mint>& f) {\n  vc<mint> g(len(f) + 1);\n  FOR3(i, 1, len(g))\
    \ g[i] = f[i - 1] * inv<mint>(i);\n  return g;\n}\n\n// \u4E0D\u5B9A\u7A4D\u5206\
    \uFF1Aintegrate(f)\n// \u5B9A\u7A4D\u5206\uFF1Aintegrate(f, L, R)\ntemplate <typename\
    \ mint>\nmint integrate(const vc<mint>& f, mint L, mint R) {\n  mint I = 0;\n\
    \  mint pow_L = 1, pow_R = 1;\n  FOR(i, len(f)) {\n    pow_L *= L, pow_R *= R;\n\
    \    I += inv<mint>(i + 1) * f[i] * (pow_R - pow_L);\n  }\n  return I;\n}\n#line\
    \ 2 \"library/poly/differentiate.hpp\"\n\ntemplate <typename mint>\nvc<mint> differentiate(const\
    \ vc<mint>& f) {\n  if (len(f) <= 1) return {};\n  vc<mint> g(len(f) - 1);\n \
    \ FOR(i, len(g)) g[i] = f[i + 1] * mint(i + 1);\n  return g;\n}\n#line 2 \"library/poly/count_terms.hpp\"\
    \ntemplate <typename mint>\nint count_terms(const vc<mint>& f) {\n  int t = 0;\n\
    \  FOR(i, len(f)) if (f[i] != mint(0))++ t;\n  return t;\n}\n#line 6 \"library/poly/fps_exp.hpp\"\
    \n\ntemplate <typename mint>\nvc<mint> fps_exp_sparse(vc<mint>& f) {\n  if (len(f)\
    \ == 0) return {mint(1)};\n  assert(f[0] == 0);\n  int N = len(f);\n  // df \u3092\
    \u6301\u305F\u305B\u308B\n  vc<pair<int, mint>> dat;\n  FOR(i, 1, N) if (f[i]\
    \ != mint(0)) dat.eb(i - 1, mint(i) * f[i]);\n  vc<mint> F(N);\n  F[0] = 1;\n\
    \  FOR(n, 1, N) {\n    mint rhs = 0;\n    for (auto&& [k, fk]: dat) {\n      if\
    \ (k > n - 1) break;\n      rhs += fk * F[n - 1 - k];\n    }\n    F[n] = rhs *\
    \ inv<mint>(n);\n  }\n  return F;\n}\n\ntemplate <typename mint>\nvc<mint> fps_exp_dense(vc<mint>&\
    \ h) {\n  const int n = len(h);\n  assert(n > 0 && h[0] == mint(0));\n  if (mint::can_ntt())\
    \ {\n    vc<mint>& f = h;\n    vc<mint> b = {1, (1 < n ? f[1] : 0)};\n    vc<mint>\
    \ c = {1}, z1, z2 = {1, 1};\n    while (len(b) < n) {\n      int m = len(b);\n\
    \      auto y = b;\n      y.resize(2 * m);\n      ntt(y, 0);\n      z1 = z2;\n\
    \      vc<mint> z(m);\n      FOR(i, m) z[i] = y[i] * z1[i];\n      ntt(z, 1);\n\
    \      FOR(i, m / 2) z[i] = 0;\n      ntt(z, 0);\n      FOR(i, m) z[i] *= -z1[i];\n\
    \      ntt(z, 1);\n      c.insert(c.end(), z.begin() + m / 2, z.end());\n    \
    \  z2 = c;\n      z2.resize(2 * m);\n      ntt(z2, 0);\n\n      vc<mint> x(f.begin(),\
    \ f.begin() + m);\n      FOR(i, len(x) - 1) x[i] = x[i + 1] * mint(i + 1);\n \
    \     x.back() = 0;\n      ntt(x, 0);\n      FOR(i, m) x[i] *= y[i];\n      ntt(x,\
    \ 1);\n\n      FOR(i, m - 1) x[i] -= b[i + 1] * mint(i + 1);\n\n      x.resize(m\
    \ + m);\n      FOR(i, m - 1) x[m + i] = x[i], x[i] = 0;\n      ntt(x, 0);\n  \
    \    FOR(i, m + m) x[i] *= z2[i];\n      ntt(x, 1);\n      FOR_R(i, len(x) - 1)\
    \ x[i + 1] = x[i] * inv<mint>(i + 1);\n      x[0] = 0;\n\n      FOR3(i, m, min(n,\
    \ m + m)) x[i] += f[i];\n      FOR(i, m) x[i] = 0;\n      ntt(x, 0);\n      FOR(i,\
    \ m + m) x[i] *= y[i];\n      ntt(x, 1);\n      b.insert(b.end(), x.begin() +\
    \ m, x.end());\n    }\n    b.resize(n);\n    return b;\n  }\n\n  const int L =\
    \ len(h);\n  assert(L > 0 && h[0] == mint(0));\n  int LOG = 0;\n  while (1 <<\
    \ LOG < L) ++LOG;\n  h.resize(1 << LOG);\n  auto dh = differentiate(h);\n  vc<mint>\
    \ f = {1}, g = {1};\n  int m = 1;\n\n  vc<mint> p;\n\n  FOR(LOG) {\n    p = convolution(f,\
    \ g);\n    p.resize(m);\n    p = convolution(p, g);\n    p.resize(m);\n    g.resize(m);\n\
    \    FOR(i, m) g[i] += g[i] - p[i];\n    p = {dh.begin(), dh.begin() + m - 1};\n\
    \    p = convolution(f, p);\n    p.resize(m + m - 1);\n    FOR(i, m + m - 1) p[i]\
    \ = -p[i];\n    FOR(i, m - 1) p[i] += mint(i + 1) * f[i + 1];\n    p = convolution(p,\
    \ g);\n\n    p.resize(m + m - 1);\n    FOR(i, m - 1) p[i] += dh[i];\n    p = integrate(p);\n\
    \    FOR(i, m + m) p[i] = h[i] - p[i];\n    p[0] += mint(1);\n    f = convolution(f,\
    \ p);\n    f.resize(m + m);\n    m += m;\n  }\n  f.resize(L);\n  return f;\n}\n\
    \ntemplate <typename mint>\nvc<mint> fps_exp(vc<mint>& f) {\n  int n = count_terms(f);\n\
    \  int t = (mint::can_ntt() ? 320 : 3000);\n  return (n <= t ? fps_exp_sparse<mint>(f)\
    \ : fps_exp_dense<mint>(f));\n}\n#line 1 \"library/graph/count/count_labeled_tree.hpp\"\
    \n// https://oeis.org/A000272\ntemplate <typename mint>\nvc<mint> count_labeled_tree(ll\
    \ nmax) {\n  vc<mint> f(nmax + 1);\n  FOR(n, 1, nmax + 1) { f[n] = (n == 1 ? mint(1)\
    \ : mint(n).pow(n - 2)); }\n  return f;\n}\n#line 3 \"library/graph/count/count_labeled_forest.hpp\"\
    \n\n// https://oeis.org/A001858\ntemplate <typename mint>\nvc<mint> count_labeled_forest(int\
    \ N) {\n  vc<mint> f = count_labeled_tree<mint>(N);\n  FOR(i, len(f)) f[i] *=\
    \ fact_inv<mint>(i);\n  f = fps_exp(f);\n  FOR(i, len(f)) f[i] *= fact<mint>(i);\n\
    \  return f;\n}\n#line 7 \"main.cpp\"\n\nusing mint = modint998;\n\nvoid test()\
    \ {\n  vc<mint> F = count_labeled_forest<mint>(10);\n  vi ANS = {1, 1, 2, 7, 38,\
    \ 291, 2932, 36961, 561948, 10026505, 205608536};\n  FOR(n, 11) { assert(F[n]\
    \ == mint(ANS[n])); }\n}\n\nvoid solve() {\n  int a, b;\n  cin >> a >> b;\n  cout\
    \ << a + b << '\\n';\n}\n\nsigned main() {\n  test();\n  solve();\n  return 0;\n\
    }\n"
  dependsOn: []
  isVerificationFile: true
  path: test/mytest/count_labeled_forest.test.cpp
  requiredBy: []
  timestamp: '2024-01-29 22:33:16+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: test/mytest/count_labeled_forest.test.cpp
layout: document
redirect_from:
- /verify/test/mytest/count_labeled_forest.test.cpp
- /verify/test/mytest/count_labeled_forest.test.cpp.html
title: test/mytest/count_labeled_forest.test.cpp
---
