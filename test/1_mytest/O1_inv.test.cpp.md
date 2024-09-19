---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: mod/O1_inverse.hpp
    title: mod/O1_inverse.hpp
  - icon: ':heavy_check_mark:'
    path: mod/barrett.hpp
    title: mod/barrett.hpp
  - icon: ':heavy_check_mark:'
    path: mod/dynamic_modint.hpp
    title: mod/dynamic_modint.hpp
  - icon: ':heavy_check_mark:'
    path: mod/mod_pow.hpp
    title: mod/mod_pow.hpp
  - icon: ':heavy_check_mark:'
    path: mod/modint.hpp
    title: mod/modint.hpp
  - icon: ':heavy_check_mark:'
    path: mod/modint_common.hpp
    title: mod/modint_common.hpp
  - icon: ':heavy_check_mark:'
    path: mod/mongomery_modint.hpp
    title: mod/mongomery_modint.hpp
  - icon: ':heavy_check_mark:'
    path: mod/primitive_root.hpp
    title: mod/primitive_root.hpp
  - icon: ':question:'
    path: my_template.hpp
    title: my_template.hpp
  - icon: ':heavy_check_mark:'
    path: nt/factor.hpp
    title: nt/factor.hpp
  - icon: ':heavy_check_mark:'
    path: nt/primetest.hpp
    title: nt/primetest.hpp
  - icon: ':heavy_check_mark:'
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
  bundledCode: "#line 1 \"test/1_mytest/O1_inv.test.cpp\"\n#define PROBLEM \"https://judge.yosupo.jp/problem/aplusb\"\
    \n#line 1 \"my_template.hpp\"\n#if defined(LOCAL)\n#include <my_template_compiled.hpp>\n\
    #else\n\n// https://codeforces.com/blog/entry/96344\n#pragma GCC optimize(\"Ofast,unroll-loops\"\
    )\n// \u3044\u307E\u306E CF \u3060\u3068\u3053\u308C\u5165\u308C\u308B\u3068\u52D5\
    \u304B\u306A\u3044\uFF1F\n// #pragma GCC target(\"avx2,popcnt\")\n\n#include <bits/stdc++.h>\n\
    \nusing namespace std;\n\nusing ll = long long;\nusing u32 = unsigned int;\nusing\
    \ u64 = unsigned long long;\nusing i128 = __int128;\nusing u128 = unsigned __int128;\n\
    using f128 = __float128;\n\ntemplate <class T>\nconstexpr T infty = 0;\ntemplate\
    \ <>\nconstexpr int infty<int> = 1'010'000'000;\ntemplate <>\nconstexpr ll infty<ll>\
    \ = 2'020'000'000'000'000'000;\ntemplate <>\nconstexpr u32 infty<u32> = infty<int>;\n\
    template <>\nconstexpr u64 infty<u64> = infty<ll>;\ntemplate <>\nconstexpr i128\
    \ infty<i128> = i128(infty<ll>) * 2'000'000'000'000'000'000;\ntemplate <>\nconstexpr\
    \ double infty<double> = infty<ll>;\ntemplate <>\nconstexpr long double infty<long\
    \ double> = infty<ll>;\n\nusing pi = pair<ll, ll>;\nusing vi = vector<ll>;\ntemplate\
    \ <class T>\nusing vc = vector<T>;\ntemplate <class T>\nusing vvc = vector<vc<T>>;\n\
    template <class T>\nusing vvvc = vector<vvc<T>>;\ntemplate <class T>\nusing vvvvc\
    \ = vector<vvvc<T>>;\ntemplate <class T>\nusing vvvvvc = vector<vvvvc<T>>;\ntemplate\
    \ <class T>\nusing pq = priority_queue<T>;\ntemplate <class T>\nusing pqg = priority_queue<T,\
    \ vector<T>, greater<T>>;\n\n#define vv(type, name, h, ...) vector<vector<type>>\
    \ name(h, vector<type>(__VA_ARGS__))\n#define vvv(type, name, h, w, ...) vector<vector<vector<type>>>\
    \ name(h, vector<vector<type>>(w, vector<type>(__VA_ARGS__)))\n#define vvvv(type,\
    \ name, a, b, c, ...) \\\n  vector<vector<vector<vector<type>>>> name(a, vector<vector<vector<type>>>(b,\
    \ vector<vector<type>>(c, vector<type>(__VA_ARGS__))))\n\n// https://trap.jp/post/1224/\n\
    #define FOR1(a) for (ll _ = 0; _ < ll(a); ++_)\n#define FOR2(i, a) for (ll i =\
    \ 0; i < ll(a); ++i)\n#define FOR3(i, a, b) for (ll i = a; i < ll(b); ++i)\n#define\
    \ FOR4(i, a, b, c) for (ll i = a; i < ll(b); i += (c))\n#define FOR1_R(a) for\
    \ (ll i = (a)-1; i >= ll(0); --i)\n#define FOR2_R(i, a) for (ll i = (a)-1; i >=\
    \ ll(0); --i)\n#define FOR3_R(i, a, b) for (ll i = (b)-1; i >= ll(a); --i)\n#define\
    \ overload4(a, b, c, d, e, ...) e\n#define overload3(a, b, c, d, ...) d\n#define\
    \ FOR(...) overload4(__VA_ARGS__, FOR4, FOR3, FOR2, FOR1)(__VA_ARGS__)\n#define\
    \ FOR_R(...) overload3(__VA_ARGS__, FOR3_R, FOR2_R, FOR1_R)(__VA_ARGS__)\n\n#define\
    \ FOR_subset(t, s) for (ll t = (s); t >= 0; t = (t == 0 ? -1 : (t - 1) & (s)))\n\
    #define all(x) x.begin(), x.end()\n#define len(x) ll(x.size())\n#define elif else\
    \ if\n\n#define eb emplace_back\n#define mp make_pair\n#define mt make_tuple\n\
    #define fi first\n#define se second\n\n#define stoi stoll\n\nint popcnt(int x)\
    \ { return __builtin_popcount(x); }\nint popcnt(u32 x) { return __builtin_popcount(x);\
    \ }\nint popcnt(ll x) { return __builtin_popcountll(x); }\nint popcnt(u64 x) {\
    \ return __builtin_popcountll(x); }\nint popcnt_mod_2(int x) { return __builtin_parity(x);\
    \ }\nint popcnt_mod_2(u32 x) { return __builtin_parity(x); }\nint popcnt_mod_2(ll\
    \ x) { return __builtin_parityll(x); }\nint popcnt_mod_2(u64 x) { return __builtin_parityll(x);\
    \ }\n// (0, 1, 2, 3, 4) -> (-1, 0, 1, 1, 2)\nint topbit(int x) { return (x ==\
    \ 0 ? -1 : 31 - __builtin_clz(x)); }\nint topbit(u32 x) { return (x == 0 ? -1\
    \ : 31 - __builtin_clz(x)); }\nint topbit(ll x) { return (x == 0 ? -1 : 63 - __builtin_clzll(x));\
    \ }\nint topbit(u64 x) { return (x == 0 ? -1 : 63 - __builtin_clzll(x)); }\n//\
    \ (0, 1, 2, 3, 4) -> (-1, 0, 1, 0, 2)\nint lowbit(int x) { return (x == 0 ? -1\
    \ : __builtin_ctz(x)); }\nint lowbit(u32 x) { return (x == 0 ? -1 : __builtin_ctz(x));\
    \ }\nint lowbit(ll x) { return (x == 0 ? -1 : __builtin_ctzll(x)); }\nint lowbit(u64\
    \ x) { return (x == 0 ? -1 : __builtin_ctzll(x)); }\n\ntemplate <typename T>\n\
    T floor(T a, T b) {\n  return a / b - (a % b && (a ^ b) < 0);\n}\ntemplate <typename\
    \ T>\nT ceil(T x, T y) {\n  return floor(x + y - 1, y);\n}\ntemplate <typename\
    \ T>\nT bmod(T x, T y) {\n  return x - y * floor(x, y);\n}\ntemplate <typename\
    \ T>\npair<T, T> divmod(T x, T y) {\n  T q = floor(x, y);\n  return {q, x - q\
    \ * y};\n}\n\ntemplate <typename T, typename U>\nT SUM(const vector<U> &A) {\n\
    \  T sm = 0;\n  for (auto &&a: A) sm += a;\n  return sm;\n}\n\n#define MIN(v)\
    \ *min_element(all(v))\n#define MAX(v) *max_element(all(v))\n#define LB(c, x)\
    \ distance((c).begin(), lower_bound(all(c), (x)))\n#define UB(c, x) distance((c).begin(),\
    \ upper_bound(all(c), (x)))\n#define UNIQUE(x) sort(all(x)), x.erase(unique(all(x)),\
    \ x.end()), x.shrink_to_fit()\n\ntemplate <typename T>\nT POP(deque<T> &que) {\n\
    \  T a = que.front();\n  que.pop_front();\n  return a;\n}\ntemplate <typename\
    \ T>\nT POP(pq<T> &que) {\n  T a = que.top();\n  que.pop();\n  return a;\n}\n\
    template <typename T>\nT POP(pqg<T> &que) {\n  T a = que.top();\n  que.pop();\n\
    \  return a;\n}\ntemplate <typename T>\nT POP(vc<T> &que) {\n  T a = que.back();\n\
    \  que.pop_back();\n  return a;\n}\n\ntemplate <typename F>\nll binary_search(F\
    \ check, ll ok, ll ng, bool check_ok = true) {\n  if (check_ok) assert(check(ok));\n\
    \  while (abs(ok - ng) > 1) {\n    auto x = (ng + ok) / 2;\n    (check(x) ? ok\
    \ : ng) = x;\n  }\n  return ok;\n}\ntemplate <typename F>\ndouble binary_search_real(F\
    \ check, double ok, double ng, int iter = 100) {\n  FOR(iter) {\n    double x\
    \ = (ok + ng) / 2;\n    (check(x) ? ok : ng) = x;\n  }\n  return (ok + ng) / 2;\n\
    }\n\ntemplate <class T, class S>\ninline bool chmax(T &a, const S &b) {\n  return\
    \ (a < b ? a = b, 1 : 0);\n}\ntemplate <class T, class S>\ninline bool chmin(T\
    \ &a, const S &b) {\n  return (a > b ? a = b, 1 : 0);\n}\n\n// ? \u306F -1\nvc<int>\
    \ s_to_vi(const string &S, char first_char) {\n  vc<int> A(S.size());\n  FOR(i,\
    \ S.size()) { A[i] = (S[i] != '?' ? S[i] - first_char : -1); }\n  return A;\n\
    }\n\ntemplate <typename T, typename U>\nvector<T> cumsum(vector<U> &A, int off\
    \ = 1) {\n  int N = A.size();\n  vector<T> B(N + 1);\n  FOR(i, N) { B[i + 1] =\
    \ B[i] + A[i]; }\n  if (off == 0) B.erase(B.begin());\n  return B;\n}\n\n// stable\
    \ sort\ntemplate <typename T>\nvector<int> argsort(const vector<T> &A) {\n  vector<int>\
    \ ids(len(A));\n  iota(all(ids), 0);\n  sort(all(ids), [&](int i, int j) { return\
    \ (A[i] == A[j] ? i < j : A[i] < A[j]); });\n  return ids;\n}\n\n// A[I[0]], A[I[1]],\
    \ ...\ntemplate <typename T>\nvc<T> rearrange(const vc<T> &A, const vc<int> &I)\
    \ {\n  vc<T> B(len(I));\n  FOR(i, len(I)) B[i] = A[I[i]];\n  return B;\n}\n\n\
    template <typename T, typename... Vectors>\nvoid concat(vc<T> &first, const Vectors\
    \ &... others) {\n  vc<T> &res = first;\n  (res.insert(res.end(), others.begin(),\
    \ others.end()), ...);\n}\n#endif\n#line 3 \"test/1_mytest/O1_inv.test.cpp\"\n\
    \n#line 2 \"mod/modint_common.hpp\"\n\nstruct has_mod_impl {\n  template <class\
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
    using modint998 = modint<998244353>;\n#line 2 \"mod/dynamic_modint.hpp\"\n\n#line\
    \ 2 \"mod/primitive_root.hpp\"\n\r\n#line 2 \"nt/factor.hpp\"\n\n#line 2 \"random/base.hpp\"\
    \n\nu64 RNG_64() {\n  static uint64_t x_\n      = uint64_t(chrono::duration_cast<chrono::nanoseconds>(chrono::high_resolution_clock::now().time_since_epoch()).count())\
    \ * 10150724397891781847ULL;\n  x_ ^= x_ << 7;\n  return x_ ^= x_ >> 9;\n}\n\n\
    u64 RNG(u64 lim) { return RNG_64() % lim; }\n\nll RNG(ll l, ll r) { return l +\
    \ RNG_64() % (r - l); }\n#line 2 \"mod/mongomery_modint.hpp\"\n\n// odd mod.\n\
    // x \u306E\u4EE3\u308F\u308A\u306B rx \u3092\u6301\u3064\ntemplate <int id, typename\
    \ U1, typename U2>\nstruct Mongomery_modint {\n  using mint = Mongomery_modint;\n\
    \  inline static U1 m, r, n2;\n  static constexpr int W = numeric_limits<U1>::digits;\n\
    \n  static void set_mod(U1 mod) {\n    assert(mod & 1 && mod <= U1(1) << (W -\
    \ 2));\n    m = mod, n2 = -U2(m) % m, r = m;\n    FOR(5) r *= 2 - m * r;\n   \
    \ r = -r;\n    assert(r * m == U1(-1));\n  }\n  static U1 reduce(U2 b) { return\
    \ (b + U2(U1(b) * r) * m) >> W; }\n\n  U1 x;\n  Mongomery_modint() : x(0) {}\n\
    \  Mongomery_modint(U1 x) : x(reduce(U2(x) * n2)){};\n  U1 val() const {\n   \
    \ U1 y = reduce(x);\n    return y >= m ? y - m : y;\n  }\n  mint &operator+=(mint\
    \ y) {\n    x = ((x += y.x) >= m ? x - m : x);\n    return *this;\n  }\n  mint\
    \ &operator-=(mint y) {\n    x -= (x >= y.x ? y.x : y.x - m);\n    return *this;\n\
    \  }\n  mint &operator*=(mint y) {\n    x = reduce(U2(x) * y.x);\n    return *this;\n\
    \  }\n  mint operator+(mint y) const { return mint(*this) += y; }\n  mint operator-(mint\
    \ y) const { return mint(*this) -= y; }\n  mint operator*(mint y) const { return\
    \ mint(*this) *= y; }\n  bool operator==(mint y) const {\n    return (x >= m ?\
    \ x - m : x) == (y.x >= m ? y.x - m : y.x);\n  }\n  bool operator!=(mint y) const\
    \ { return not operator==(y); }\n  mint pow(ll n) const {\n    assert(n >= 0);\n\
    \    mint y = 1, z = *this;\n    for (; n; n >>= 1, z *= z)\n      if (n & 1)\
    \ y *= z;\n    return y;\n  }\n};\n\ntemplate <int id>\nusing Mongomery_modint_32\
    \ = Mongomery_modint<id, u32, u64>;\ntemplate <int id>\nusing Mongomery_modint_64\
    \ = Mongomery_modint<id, u64, u128>;\n#line 3 \"nt/primetest.hpp\"\n\r\nbool primetest(const\
    \ u64 x) {\r\n  assert(x < u64(1) << 62);\r\n  if (x == 2 or x == 3 or x == 5\
    \ or x == 7) return true;\r\n  if (x % 2 == 0 or x % 3 == 0 or x % 5 == 0 or x\
    \ % 7 == 0) return false;\r\n  if (x < 121) return x > 1;\r\n  const u64 d = (x\
    \ - 1) >> lowbit(x - 1);\r\n\r\n  using mint = Mongomery_modint_64<202311020>;\r\
    \n\r\n  mint::set_mod(x);\r\n  const mint one(u64(1)), minus_one(x - 1);\r\n \
    \ auto ok = [&](u64 a) -> bool {\r\n    auto y = mint(a).pow(d);\r\n    u64 t\
    \ = d;\r\n    while (y != one && y != minus_one && t != x - 1) y *= y, t <<= 1;\r\
    \n    if (y != minus_one && t % 2 == 0) return false;\r\n    return true;\r\n\
    \  };\r\n  if (x < (u64(1) << 32)) {\r\n    for (u64 a: {2, 7, 61})\r\n      if\
    \ (!ok(a)) return false;\r\n  } else {\r\n    for (u64 a: {2, 325, 9375, 28178,\
    \ 450775, 9780504, 1795265022}) {\r\n      if (!ok(a)) return false;\r\n    }\r\
    \n  }\r\n  return true;\r\n}\n#line 5 \"nt/factor.hpp\"\n\ntemplate <typename\
    \ mint>\nll rho(ll n, ll c) {\n  assert(n > 1);\n  const mint cc(c);\n  auto f\
    \ = [&](mint x) { return x * x + cc; };\n  mint x = 1, y = 2, z = 1, q = 1;\n\
    \  ll g = 1;\n  const ll m = 1LL << (__lg(n) / 5);\n  for (ll r = 1; g == 1; r\
    \ <<= 1) {\n    x = y;\n    FOR(r) y = f(y);\n    for (ll k = 0; k < r && g ==\
    \ 1; k += m) {\n      z = y;\n      FOR(min(m, r - k)) y = f(y), q *= x - y;\n\
    \      g = gcd(q.val(), n);\n    }\n  }\n  if (g == n) do {\n      z = f(z);\n\
    \      g = gcd((x - z).val(), n);\n    } while (g == 1);\n  return g;\n}\n\nll\
    \ find_prime_factor(ll n) {\n  assert(n > 1);\n  if (primetest(n)) return n;\n\
    \  FOR(100) {\n    ll m = 0;\n    if (n < (1 << 30)) {\n      using mint = Mongomery_modint_32<20231025>;\n\
    \      mint::set_mod(n);\n      m = rho<mint>(n, RNG(0, n));\n    } else {\n \
    \     using mint = Mongomery_modint_64<20231025>;\n      mint::set_mod(n);\n \
    \     m = rho<mint>(n, RNG(0, n));\n    }\n    if (primetest(m)) return m;\n \
    \   n = m;\n  }\n  assert(0);\n  return -1;\n}\n\n// \u30BD\u30FC\u30C8\u3057\u3066\
    \u304F\u308C\u308B\nvc<pair<ll, int>> factor(ll n) {\n  assert(n >= 1);\n  vc<pair<ll,\
    \ int>> pf;\n  FOR(p, 2, 100) {\n    if (p * p > n) break;\n    if (n % p == 0)\
    \ {\n      ll e = 0;\n      do { n /= p, e += 1; } while (n % p == 0);\n     \
    \ pf.eb(p, e);\n    }\n  }\n  while (n > 1) {\n    ll p = find_prime_factor(n);\n\
    \    ll e = 0;\n    do { n /= p, e += 1; } while (n % p == 0);\n    pf.eb(p, e);\n\
    \  }\n  sort(all(pf));\n  return pf;\n}\n\nvc<pair<ll, int>> factor_by_lpf(ll\
    \ n, vc<int>& lpf) {\n  vc<pair<ll, int>> res;\n  while (n > 1) {\n    int p =\
    \ lpf[n];\n    int e = 0;\n    while (n % p == 0) {\n      n /= p;\n      ++e;\n\
    \    }\n    res.eb(p, e);\n  }\n  return res;\n}\n#line 2 \"mod/mod_pow.hpp\"\n\
    \r\n#line 2 \"mod/barrett.hpp\"\n\n// https://github.com/atcoder/ac-library/blob/master/atcoder/internal_math.hpp\n\
    struct Barrett {\n  u32 m;\n  u64 im;\n  explicit Barrett(u32 m = 1) : m(m), im(u64(-1)\
    \ / m + 1) {}\n  u32 umod() const { return m; }\n  u32 modulo(u64 z) {\n    if\
    \ (m == 1) return 0;\n    u64 x = (u64)(((unsigned __int128)(z)*im) >> 64);\n\
    \    u64 y = x * m;\n    return (z - y + (z < y ? m : 0));\n  }\n  u64 floor(u64\
    \ z) {\n    if (m == 1) return z;\n    u64 x = (u64)(((unsigned __int128)(z)*im)\
    \ >> 64);\n    u64 y = x * m;\n    return (z < y ? x - 1 : x);\n  }\n  pair<u64,\
    \ u32> divmod(u64 z) {\n    if (m == 1) return {z, 0};\n    u64 x = (u64)(((unsigned\
    \ __int128)(z)*im) >> 64);\n    u64 y = x * m;\n    if (z < y) return {x - 1,\
    \ z - y + m};\n    return {x, z - y};\n  }\n  u32 mul(u32 a, u32 b) { return modulo(u64(a)\
    \ * b); }\n};\n\nstruct Barrett_64 {\n  u128 mod, mh, ml;\n\n  explicit Barrett_64(u64\
    \ mod = 1) : mod(mod) {\n    u128 m = u128(-1) / mod;\n    if (m * mod + mod ==\
    \ u128(0)) ++m;\n    mh = m >> 64;\n    ml = m & u64(-1);\n  }\n\n  u64 umod()\
    \ const { return mod; }\n\n  u64 modulo(u128 x) {\n    u128 z = (x & u64(-1))\
    \ * ml;\n    z = (x & u64(-1)) * mh + (x >> 64) * ml + (z >> 64);\n    z = (x\
    \ >> 64) * mh + (z >> 64);\n    x -= z * mod;\n    return x < mod ? x : x - mod;\n\
    \  }\n\n  u64 mul(u64 a, u64 b) { return modulo(u128(a) * b); }\n};\n#line 5 \"\
    mod/mod_pow.hpp\"\n\r\nu32 mod_pow(int a, ll n, int mod) {\r\n  assert(n >= 0);\r\
    \n  a = ((a %= mod) < 0 ? a + mod : a);\r\n  if ((mod & 1) && (mod < (1 << 30)))\
    \ {\r\n    using mint = Mongomery_modint_32<202311021>;\r\n    mint::set_mod(mod);\r\
    \n    return mint(a).pow(n).val();\r\n  }\r\n  Barrett bt(mod);\r\n  int r = 1;\r\
    \n  while (n) {\r\n    if (n & 1) r = bt.mul(r, a);\r\n    a = bt.mul(a, a), n\
    \ >>= 1;\r\n  }\r\n  return r;\r\n}\r\n\r\nu64 mod_pow_64(ll a, ll n, u64 mod)\
    \ {\r\n  assert(n >= 0);\r\n  a = ((a %= mod) < 0 ? a + mod : a);\r\n  if ((mod\
    \ & 1) && (mod < (u64(1) << 62))) {\r\n    using mint = Mongomery_modint_64<202311021>;\r\
    \n    mint::set_mod(mod);\r\n    return mint(a).pow(n).val();\r\n  }\r\n  Barrett_64\
    \ bt(mod);\r\n  ll r = 1;\r\n  while (n) {\r\n    if (n & 1) r = bt.mul(r, a);\r\
    \n    a = bt.mul(a, a), n >>= 1;\r\n  }\r\n  return r;\r\n}\n#line 6 \"mod/primitive_root.hpp\"\
    \n\r\n// int\r\nint primitive_root(int p) {\r\n  auto pf = factor(p - 1);\r\n\
    \  auto is_ok = [&](int g) -> bool {\r\n    for (auto&& [q, e]: pf)\r\n      if\
    \ (mod_pow(g, (p - 1) / q, p) == 1) return false;\r\n    return true;\r\n  };\r\
    \n  while (1) {\r\n    int x = RNG(1, p);\r\n    if (is_ok(x)) return x;\r\n \
    \ }\r\n  return -1;\r\n}\r\n\r\nll primitive_root_64(ll p) {\r\n  auto pf = factor(p\
    \ - 1);\r\n  auto is_ok = [&](ll g) -> bool {\r\n    for (auto&& [q, e]: pf)\r\
    \n      if (mod_pow_64(g, (p - 1) / q, p) == 1) return false;\r\n    return true;\r\
    \n  };\r\n  while (1) {\r\n    ll x = RNG(1, p);\r\n    if (is_ok(x)) return x;\r\
    \n  }\r\n  return -1;\r\n}\r\n#line 6 \"mod/dynamic_modint.hpp\"\n\ntemplate <int\
    \ id>\nstruct Dynamic_Modint {\n  static constexpr bool is_modint = true;\n  using\
    \ mint = Dynamic_Modint;\n  u32 val;\n  static Barrett bt;\n  static u32 umod()\
    \ { return bt.umod(); }\n\n  static int get_mod() { return (int)(bt.umod()); }\n\
    \  static void set_mod(int m) {\n    assert(1 <= m);\n    bt = Barrett(m);\n \
    \ }\n\n  static Dynamic_Modint raw(u32 v) {\n    Dynamic_Modint x;\n    x.val\
    \ = v;\n    return x;\n  }\n  Dynamic_Modint() : val(0) {}\n  Dynamic_Modint(u32\
    \ x) : val(bt.modulo(x)) {}\n  Dynamic_Modint(u64 x) : val(bt.modulo(x)) {}\n\
    \  Dynamic_Modint(int x) : val((x %= get_mod()) < 0 ? x + get_mod() : x) {}\n\
    \  Dynamic_Modint(ll x) : val((x %= get_mod()) < 0 ? x + get_mod() : x) {}\n \
    \ Dynamic_Modint(i128 x) : val((x %= get_mod()) < 0 ? x + get_mod() : x){};\n\n\
    \  mint& operator+=(const mint& rhs) {\n    val = (val += rhs.val) < umod() ?\
    \ val : val - umod();\n    return *this;\n  }\n  mint& operator-=(const mint&\
    \ rhs) {\n    val = (val += umod() - rhs.val) < umod() ? val : val - umod();\n\
    \    return *this;\n  }\n  mint& operator*=(const mint& rhs) {\n    val = bt.mul(val,\
    \ rhs.val);\n    return *this;\n  }\n  mint& operator/=(const mint& rhs) { return\
    \ *this = *this * rhs.inverse(); }\n  mint operator-() const { return mint() -\
    \ *this; }\n  mint pow(ll n) const {\n    assert(0 <= n);\n    mint x = *this,\
    \ r = 1;\n    while (n) {\n      if (n & 1) r *= x;\n      x *= x, n >>= 1;\n\
    \    }\n    return r;\n  }\n  mint inverse() const {\n    int x = val, mod = get_mod();\n\
    \    int a = x, b = mod, u = 1, v = 0, t;\n    while (b > 0) {\n      t = a /\
    \ b;\n      swap(a -= t * b, b), swap(u -= t * v, v);\n    }\n    if (u < 0) u\
    \ += mod;\n    return u;\n  }\n\n  friend mint operator+(const mint& lhs, const\
    \ mint& rhs) {\n    return mint(lhs) += rhs;\n  }\n  friend mint operator-(const\
    \ mint& lhs, const mint& rhs) {\n    return mint(lhs) -= rhs;\n  }\n  friend mint\
    \ operator*(const mint& lhs, const mint& rhs) {\n    return mint(lhs) *= rhs;\n\
    \  }\n  friend mint operator/(const mint& lhs, const mint& rhs) {\n    return\
    \ mint(lhs) /= rhs;\n  }\n  friend bool operator==(const mint& lhs, const mint&\
    \ rhs) {\n    return lhs.val == rhs.val;\n  }\n  friend bool operator!=(const\
    \ mint& lhs, const mint& rhs) {\n    return lhs.val != rhs.val;\n  }\n  static\
    \ pair<int, int>& get_ntt() {\n    static pair<int, int> p = {-1, -1};\n    return\
    \ p;\n  }\n  static void set_ntt_info() {\n    int mod = get_mod();\n    int k\
    \ = lowbit(mod - 1);\n    int r = primitive_root(mod);\n    r = mod_pow(r, (mod\
    \ - 1) >> k, mod);\n    get_ntt() = {k, r};\n  }\n  static pair<int, int> ntt_info()\
    \ { return get_ntt(); }\n  static bool can_ntt() { return ntt_info().fi != -1;\
    \ }\n};\n\n#ifdef FASTIO\ntemplate <int id>\nvoid rd(Dynamic_Modint<id>& x) {\n\
    \  fastio::rd(x.val);\n  x.val %= Dynamic_Modint<id>::umod();\n}\ntemplate <int\
    \ id>\nvoid wt(Dynamic_Modint<id> x) {\n  fastio::wt(x.val);\n}\n#endif\n\nusing\
    \ dmint = Dynamic_Modint<-1>;\ntemplate <int id>\nBarrett Dynamic_Modint<id>::bt;\n\
    #line 1 \"mod/O1_inverse.hpp\"\n\n// https://qoj.ac/problem/5\n// precompute O(p^{2/3}),\
    \ query O(1)\n// 10^8 query: 3sec\ntemplate <typename mint>\nmint O1_inverse(int\
    \ a) {\n  /*\n  n^3>=p \u3068\u306A\u308B\u3088\u3046\u306B n \u3092\u3068\u308A\
    , n^2\u307E\u3067\u306F\u524D\u8A08\u7B97.\n  a/p \u3092\u6709\u7406\u6570\u8FD1\
    \u4F3C\u3059\u308B x/y. |a/p-x/y|<=|1/ny \u3068\u306A\u308B\u3068\n  |ay-px|<=p/n<=n^2\
    \ \u3088\u308A(ay)^{-1}\u304C\u524D\u8A08\u7B97\u3055\u308C\u3066\u3044\u308B\u306E\
    \u3067\u3067\u304D\u308B.\n\n  x/y \u306F\u5206\u6BCD n \u672A\u6E80\u306E Farey\
    \ \u6570\u5217\u306E\u524D\u5F8C\u3069\u3061\u3089\u304B\u304C\u6E80\u305F\u3059\
    .\n  n^2 bucket \u306B\u5206\u5272\u3057\u3066\u304A\u304F\u3068 bucket \u3054\
    \u3068\u306E\u6709\u7406\u6570\u306F distinct.\n  \u524D\u5F8C\u306E\u3046\u3061\
    \u826F\u3044\u65B9\u3092\u9078\u3079\u3070\u3088\u3044.\n  */\n  static int p\
    \ = 0;\n  static double cp = 0.0;\n  static vc<int> FRAC;\n  static vc<mint> invs;\n\
    \  if (p != mint::get_mod()) {\n    p = mint::get_mod();\n    int k = min(2 <<\
    \ 20, p);\n    invs.resize(k);\n    invs[1] = 1;\n    FOR(i, 2, k) {\n      int\
    \ q = (p + i - 1) / i;\n      invs[i] = invs[i * q - p] * mint::raw(q);\n    }\n\
    \    assert(p <= (1 << 30));\n    FRAC.assign(1 << 20, -1);\n    cp = 1.0 * (1\
    \ << 20) / p;\n    for (int y = 1023; y >= 1; --y) {\n      for (int x = 0; x\
    \ < y; ++x) { FRAC[(x << 20) / y] = {x << 10 | y}; }\n    }\n    FOR(i, 1, len(FRAC))\
    \ if (FRAC[i] == -1) FRAC[i] = FRAC[i - 1];\n    int nxt = 1025;\n    FOR_R(i,\
    \ 1, len(FRAC)) {\n      if (FRAC[i] != FRAC[i - 1]) {\n        nxt = FRAC[i];\n\
    \        continue;\n      }\n      int x1 = FRAC[i] >> 10, y1 = FRAC[i] & 1023;\n\
    \      int x2 = nxt >> 10, y2 = nxt & 1023;\n      int c1 = i * y1 - (x1 << 20);\n\
    \      int c2 = i * y2 - (x2 << 20);\n      if (abs(c2) < abs(c1)) FRAC[i] = nxt;\n\
    \    }\n  }\n  assert(0 <= a && a < p);\n  if (a < len(invs)) return invs[a];\n\
    \n  int k = a * cp;\n  ll x = FRAC[k] >> 10, y = FRAC[k] & 1023;\n  int c = ll(a)\
    \ * y - ll(p) * x;\n  if (c < 0) c = -c, y = -y;\n  return invs[c] * mint(y);\n\
    }\n#line 8 \"test/1_mytest/O1_inv.test.cpp\"\n\ntemplate <typename mint>\nvoid\
    \ test() {\n  FOR(10000000) {\n    int x = RNG(1, mint::get_mod());\n    mint\
    \ v = O1_inverse<mint>(x);\n    mint prd = v * mint::raw(x);\n    assert(prd ==\
    \ mint(1));\n  }\n}\n\nvoid solve() {\n  int a, b;\n  cin >> a >> b;\n  cout <<\
    \ a + b << \"\\n\";\n}\n\nsigned main() {\n  test<modint998>();\n  test<modint107>();\n\
    \  dmint::set_mod(998244353);\n  test<dmint>();\n  dmint::set_mod(2);\n  test<dmint>();\n\
    \  dmint::set_mod(3);\n  test<dmint>();\n  dmint::set_mod(5);\n  test<dmint>();\n\
    \  dmint::set_mod(1'000'003);\n  test<dmint>();\n  dmint::set_mod(1'048'573);\n\
    \  test<dmint>();\n  dmint::set_mod(1'048'583);\n  test<dmint>();\n  dmint::set_mod(2097143);\n\
    \  test<dmint>();\n  dmint::set_mod(2097169);\n  test<dmint>();\n  solve();\n\
    }\n"
  code: "#define PROBLEM \"https://judge.yosupo.jp/problem/aplusb\"\n#include \"my_template.hpp\"\
    \n\n#include \"mod/modint.hpp\"\n#include \"mod/dynamic_modint.hpp\"\n#include\
    \ \"random/base.hpp\"\n#include \"mod/O1_inverse.hpp\"\n\ntemplate <typename mint>\n\
    void test() {\n  FOR(10000000) {\n    int x = RNG(1, mint::get_mod());\n    mint\
    \ v = O1_inverse<mint>(x);\n    mint prd = v * mint::raw(x);\n    assert(prd ==\
    \ mint(1));\n  }\n}\n\nvoid solve() {\n  int a, b;\n  cin >> a >> b;\n  cout <<\
    \ a + b << \"\\n\";\n}\n\nsigned main() {\n  test<modint998>();\n  test<modint107>();\n\
    \  dmint::set_mod(998244353);\n  test<dmint>();\n  dmint::set_mod(2);\n  test<dmint>();\n\
    \  dmint::set_mod(3);\n  test<dmint>();\n  dmint::set_mod(5);\n  test<dmint>();\n\
    \  dmint::set_mod(1'000'003);\n  test<dmint>();\n  dmint::set_mod(1'048'573);\n\
    \  test<dmint>();\n  dmint::set_mod(1'048'583);\n  test<dmint>();\n  dmint::set_mod(2097143);\n\
    \  test<dmint>();\n  dmint::set_mod(2097169);\n  test<dmint>();\n  solve();\n\
    }\n"
  dependsOn:
  - my_template.hpp
  - mod/modint.hpp
  - mod/modint_common.hpp
  - mod/dynamic_modint.hpp
  - mod/primitive_root.hpp
  - nt/factor.hpp
  - random/base.hpp
  - nt/primetest.hpp
  - mod/mongomery_modint.hpp
  - mod/mod_pow.hpp
  - mod/barrett.hpp
  - mod/O1_inverse.hpp
  isVerificationFile: true
  path: test/1_mytest/O1_inv.test.cpp
  requiredBy: []
  timestamp: '2024-09-14 09:20:23+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: test/1_mytest/O1_inv.test.cpp
layout: document
redirect_from:
- /verify/test/1_mytest/O1_inv.test.cpp
- /verify/test/1_mytest/O1_inv.test.cpp.html
title: test/1_mytest/O1_inv.test.cpp
---
