---
data:
  _extendedDependsOn:
  - icon: ':x:'
    path: ds/offline_query/mo.hpp
    title: ds/offline_query/mo.hpp
  - icon: ':x:'
    path: mod/modint.hpp
    title: mod/modint.hpp
  - icon: ':x:'
    path: mod/modint_common.hpp
    title: mod/modint_common.hpp
  - icon: ':x:'
    path: mod/prefix_sum_of_binom.hpp
    title: mod/prefix_sum_of_binom.hpp
  - icon: ':question:'
    path: my_template.hpp
    title: my_template.hpp
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: true
  _pathExtension: cpp
  _verificationStatusIcon: ':x:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: https://judge.yosupo.jp/problem/aplusb
    links:
    - https://judge.yosupo.jp/problem/aplusb
  bundledCode: "#line 1 \"test/1_mytest/prefix_sum_of_binom.test.cpp\"\n#define PROBLEM\
    \ \"https://judge.yosupo.jp/problem/aplusb\"\n#line 1 \"my_template.hpp\"\n#if\
    \ defined(LOCAL)\n#include <my_template_compiled.hpp>\n#else\n#if defined(__GNUC__)\n\
    #include <bits/allocator.h>\n#pragma GCC optimize(\"Ofast,unroll-loops\")\n//\
    \ \u74B0\u5883\u306B\u3088\u3063\u3066\u306F\u30B3\u30F3\u30D1\u30A4\u30EB\u6210\
    \u529F\u304B\u3064\u5B9F\u884C\u6642\u30A8\u30E9\u30FC\n#pragma GCC target(\"\
    avx2,popcnt\")\n#endif\n#include <bits/stdc++.h>\n#include <cassert>\n\nusing\
    \ namespace std;\n\nusing ll = long long;\nusing u8 = uint8_t;\nusing u16 = uint16_t;\n\
    using u32 = uint32_t;\nusing u64 = uint64_t;\nusing i128 = __int128;\nusing u128\
    \ = unsigned __int128;\nusing f128 = __float128;\n\ntemplate <class>\nconstexpr\
    \ bool dependent_false = false;\n\ntemplate <class T>\nconstexpr T infty = []\
    \ {\n  static_assert(dependent_false<T>, \"infty<T> is not defined\");\n  return\
    \ T{};\n}();\ntemplate <>\nconstexpr int infty<int> = 1'010'000'000;\ntemplate\
    \ <>\nconstexpr ll infty<ll> = 2'020'000'000'000'000'000;\ntemplate <>\nconstexpr\
    \ u32 infty<u32> = infty<int>;\ntemplate <>\nconstexpr u64 infty<u64> = infty<ll>;\n\
    template <>\nconstexpr i128 infty<i128> = i128(infty<ll>) * 2'000'000'000'000'000'000;\n\
    template <>\nconstexpr double infty<double> = numeric_limits<double>::infinity();\n\
    template <>\nconstexpr long double infty<long double> =\n    numeric_limits<long\
    \ double>::infinity();\n\nusing pi = pair<ll, ll>;\nusing vi = vector<ll>;\ntemplate\
    \ <class T>\nusing vc = vector<T>;\ntemplate <class T>\nusing vvc = vector<vc<T>>;\n\
    template <class T>\nusing vvvc = vector<vvc<T>>;\ntemplate <class T>\nusing vvvvc\
    \ = vector<vvvc<T>>;\ntemplate <class T>\nusing pq_max = priority_queue<T>;\n\
    template <class T>\nusing pq_min = priority_queue<T, vector<T>, greater<T>>;\n\
    \n#define vv(type, name, h, ...) \\\n  vector<vector<type>> name(h, vector<type>(__VA_ARGS__))\n\
    #define vvv(type, name, h, w, ...)   \\\n  vector<vector<vector<type>>> name(\
    \ \\\n      h, vector<vector<type>>(w, vector<type>(__VA_ARGS__)))\n#define vvvv(type,\
    \ name, a, b, c, ...)       \\\n  vector<vector<vector<vector<type>>>> name( \\\
    \n      a, vector<vector<vector<type>>>(       \\\n             b, vector<vector<type>>(c,\
    \ vector<type>(__VA_ARGS__))))\n\n// https://trap.jp/post/1224/\n#define FOR1(a)\
    \ for (ll _ = 0; _ < ll(a); ++_)\n#define FOR2(i, a) for (ll i = 0; i < ll(a);\
    \ ++i)\n#define FOR3(i, a, b) for (ll i = a; i < ll(b); ++i)\n#define FOR4(i,\
    \ a, b, c) for (ll i = a; i < ll(b); i += (c))\n#define FOR1_R(a) for (ll i =\
    \ ll(a) - 1; i >= ll(0); --i)\n#define FOR2_R(i, a) for (ll i = ll(a) - 1; i >=\
    \ ll(0); --i)\n#define FOR3_R(i, a, b) for (ll i = ll(b) - 1; i >= ll(a); --i)\n\
    #define overload4(a, b, c, d, e, ...) e\n#define overload3(a, b, c, d, ...) d\n\
    #define FOR(...) overload4(__VA_ARGS__, FOR4, FOR3, FOR2, FOR1)(__VA_ARGS__)\n\
    #define FOR_R(...) overload3(__VA_ARGS__, FOR3_R, FOR2_R, FOR1_R)(__VA_ARGS__)\n\
    \n#define all(x) (x).begin(), (x).end()\n#define len(x) ll(x.size())\n#define\
    \ elif else if\n\n#define eb emplace_back\n#define mp make_pair\n#define mt make_tuple\n\
    #define fi first\n#define se second\n\n#define stoi stoll\n\n// require y > 0\n\
    template <typename T>\nT floor(T x, T y) {\n  return x / y - (x % y < 0);\n}\n\
    \n// require y > 0\ntemplate <typename T>\nT ceil(T x, T y) {\n  return (x / y)\
    \ + (x % y > 0);\n}\n\n// require y > 0\ntemplate <typename T>\nT bmod(T x, T\
    \ y) {\n  T r = x % y;\n  return (r < 0 ? r + y : r);\n}\n\n// require y > 0\n\
    template <typename T>\npair<T, T> divmod(T x, T y) {\n  T q = x / y, r = x % y;\n\
    \  if (r < 0) --q, r += y;\n  return {q, r};\n}\n\nconstexpr auto TEN = [] {\n\
    \  array<u64, 20> A{};\n  A[0] = 1;\n  for (int i = 1; i < 20; ++i) A[i] = 10\
    \ * A[i - 1];\n  return A;\n}();\n\ntemplate <typename T, typename U>\nT SUM(const\
    \ U &A) {\n  return std::accumulate(A.begin(), A.end(), T{});\n}\n\n#define MIN(v)\
    \ *min_element(all(v))\n#define MAX(v) *max_element(all(v))\ntemplate <class C,\
    \ class T>\ninline long long LB(const C &c, const T &x) {\n  return lower_bound(c.begin(),\
    \ c.end(), x) - c.begin();\n}\ntemplate <class C, class T>\ninline long long UB(const\
    \ C &c, const T &x) {\n  return upper_bound(c.begin(), c.end(), x) - c.begin();\n\
    }\n#define UNIQUE(x) sort(all(x)), x.erase(unique(all(x)), x.end())\n\ntemplate\
    \ <typename T>\nT POP(deque<T> &que) {\n  T a = que.front();\n  que.pop_front();\n\
    \  return a;\n}\ntemplate <class T, class Container, class Compare>\nT POP(priority_queue<T,\
    \ Container, Compare> &que) {\n  T a = que.top();\n  que.pop();\n  return a;\n\
    }\ntemplate <typename T>\nT POP(vc<T> &que) {\n  T a = que.back();\n  que.pop_back();\n\
    \  return a;\n}\n\ntemplate <typename F>\nll binary_search(F check, ll ok, ll\
    \ ng, bool check_ok = true) {\n  if (check_ok) assert(check(ok));\n  while (llabs(ok\
    \ - ng) > 1) {\n    auto x = (ng + ok) / 2;\n    (check(x) ? ok : ng) = x;\n \
    \ }\n  return ok;\n}\ntemplate <typename F>\ndouble binary_search_real(F check,\
    \ double ok, double ng, int iter = 100) {\n  FOR(iter) {\n    double x = (ok +\
    \ ng) / 2;\n    (check(x) ? ok : ng) = x;\n  }\n  return (ok + ng) / 2;\n}\n\n\
    template <class T, class S>\ninline bool chmax(T &a, const S &b) {\n  T c = max<T>(a,\
    \ b);\n  bool changed = (c != a);\n  a = c;\n  return changed;\n}\ntemplate <class\
    \ T, class S>\ninline bool chmin(T &a, const S &b) {\n  T c = min<T>(a, b);\n\
    \  bool changed = (c != a);\n  a = c;\n  return changed;\n}\n\n// ? \u306F -1\n\
    vc<int> s_to_vi(const string &S, char first_char) {\n  vc<int> A(S.size());\n\
    \  FOR(i, S.size()) { A[i] = (S[i] != '?' ? S[i] - first_char : -1); }\n  return\
    \ A;\n}\n\ntemplate <typename T, typename U>\nvc<T> cumsum(const vc<U> &A, int\
    \ off = 1) {\n  int N = A.size();\n  vc<T> B(N + 1);\n  FOR(i, N) { B[i + 1] =\
    \ B[i] + A[i]; }\n  if (off == 0) B.erase(B.begin());\n  return B;\n}\n\n// stable\
    \ sort\ntemplate <typename T>\nvc<int> argsort(const vc<T> &A) {\n  vc<int> ids(len(A));\n\
    \  iota(all(ids), 0);\n  sort(all(ids),\n       [&](int i, int j) { return (A[i]\
    \ == A[j] ? i < j : A[i] < A[j]); });\n  return ids;\n}\n\n// A[I[0]], A[I[1]],\
    \ ...\ntemplate <typename T>\nvc<T> rearrange(const vc<T> &A, const vc<int> &I)\
    \ {\n  vc<T> B(len(I));\n  FOR(i, len(I)) B[i] = A[I[i]];\n  return B;\n}\n\n\
    template <typename T, typename... Vectors>\nvoid concat(vc<T> &first, const Vectors\
    \ &...others) {\n  first.reserve(first.size() + (others.size() + ... + 0));\n\
    \  (first.insert(first.end(), others.begin(), others.end()), ...);\n}\n#endif\n\
    #line 3 \"test/1_mytest/prefix_sum_of_binom.test.cpp\"\n\n#line 2 \"mod/modint_common.hpp\"\
    \n\nstruct has_mod_impl {\n  template <class T>\n  static auto check(T &&x) ->\
    \ decltype(x.get_mod(), std::true_type{});\n  template <class T>\n  static auto\
    \ check(...) -> std::false_type;\n};\n\ntemplate <class T>\nclass has_mod : public\
    \ decltype(has_mod_impl::check<T>(std::declval<T>())) {};\n\ntemplate <typename\
    \ mint>\nmint fact(int n) {\n  static const int mod = mint::get_mod();\n  assert(0\
    \ <= n && n < mod);\n  static vector<mint> dat = {1, 1};\n  if (len(dat) <= n)\
    \ {\n    int now = len(dat);\n    int m = min(mod, 1 << (topbit(n) + 1));\n  \
    \  dat.resize(m);\n    FOR(i, now, m) dat[i] = dat[i - 1] * mint::raw(i);\n  }\n\
    \  return dat[n];\n}\n\ntemplate <typename mint>\nmint fact_inv(int n) {\n  static\
    \ const int mod = mint::get_mod();\n  static vector<mint> dat = {1, 1};\n  if\
    \ (n < 0) return mint(0);\n  if (len(dat) <= n) {\n    int now = len(dat);\n \
    \   int m = min(mod, 1 << (topbit(n) + 1));\n    dat.resize(m);\n    dat[m - 1]\
    \ = fact<mint>(m - 1).inverse();\n    FOR_R(i, now, m - 1) dat[i] = dat[i + 1]\
    \ * mint::raw(i + 1);\n  }\n  return dat[n];\n}\n\ntemplate <class mint, class...\
    \ Ts>\nmint fact_invs(Ts... xs) {\n  return (mint(1) * ... * fact_inv<mint>(xs));\n\
    }\n\ntemplate <typename mint>\nmint inv(int n) {\n  static const int mod = mint::get_mod();\n\
    \  assert(1 <= n && n < mod);\n  return fact<mint>(n - 1) * fact_inv<mint>(n);\n\
    }\n\ntemplate <>\ndouble inv<double>(int n) {\n  assert(n != 0);\n  return 1.0\
    \ / n;\n}\n\ntemplate <typename mint, class Head, class... Tail>\nmint multinomial(Head\
    \ &&head, Tail &&...tail) {\n  return fact<mint>(head) * fact_invs<mint>(std::forward<Tail>(tail)...);\n\
    }\n\ntemplate <typename mint>\nmint C_dense(int n, int k) {\n  assert(n >= 0);\n\
    \  if (k < 0 || n < k) return 0;\n  static vvc<mint> C;\n  static int H = 0, W\
    \ = 0;\n  auto calc = [&](int i, int j) -> mint {\n    if (i == 0) return (j ==\
    \ 0 ? mint(1) : mint(0));\n    return C[i - 1][j] + (j ? C[i - 1][j - 1] : 0);\n\
    \  };\n  if (W <= k) {\n    FOR(i, H) {\n      C[i].resize(k + 1);\n      FOR(j,\
    \ W, k + 1) { C[i][j] = calc(i, j); }\n    }\n    W = k + 1;\n  }\n  if (H <=\
    \ n) {\n    C.resize(n + 1);\n    FOR(i, H, n + 1) {\n      C[i].resize(W);\n\
    \      FOR(j, W) { C[i][j] = calc(i, j); }\n    }\n    H = n + 1;\n  }\n  return\
    \ C[n][k];\n}\n\ntemplate <typename mint, bool large = false, bool dense = false>\n\
    mint C(ll n, ll k) {\n  assert(n >= 0);\n  if (k < 0 || n < k) return 0;\n  if\
    \ constexpr (dense) return C_dense<mint>(n, k);\n  if constexpr (!large) return\
    \ multinomial<mint>(n, k, n - k);\n  k = min(k, n - k);\n  mint x(1);\n  FOR(i,\
    \ k) x *= mint(n - i);\n  return x * fact_inv<mint>(k);\n}\n\ntemplate <typename\
    \ mint, bool large = false>\nmint C_inv(ll n, ll k) {\n  assert(n >= 0);\n  assert(0\
    \ <= k && k <= n);\n  if (!large) return fact_inv<mint>(n) * fact<mint>(k) * fact<mint>(n\
    \ - k);\n  return mint(1) / C<mint, 1>(n, k);\n}\n\n// [x^d](1-x)^{-n}\ntemplate\
    \ <typename mint, bool large = false, bool dense = false>\nmint C_negative(ll\
    \ n, ll d) {\n  assert(n >= 0);\n  if (d < 0) return mint(0);\n  if (n == 0) {\n\
    \    return (d == 0 ? mint(1) : mint(0));\n  }\n  return C<mint, large, dense>(n\
    \ + d - 1, d);\n}\n#line 3 \"mod/modint.hpp\"\n\ntemplate <int mod>\nstruct modint\
    \ {\n  static constexpr u32 umod = u32(mod);\n  static_assert(umod < u32(1) <<\
    \ 31);\n  u32 val;\n\n  static modint raw(u32 v) {\n    modint x;\n    x.val =\
    \ v;\n    return x;\n  }\n  constexpr modint() : val(0) {}\n  constexpr modint(u32\
    \ x) : val(x % umod) {}\n  constexpr modint(u64 x) : val(x % umod) {}\n  constexpr\
    \ modint(u128 x) : val(x % umod) {}\n  constexpr modint(int x) : val((x %= mod)\
    \ < 0 ? x + mod : x){};\n  constexpr modint(ll x) : val((x %= mod) < 0 ? x + mod\
    \ : x){};\n  constexpr modint(i128 x) : val((x %= mod) < 0 ? x + mod : x){};\n\
    \  bool operator<(const modint &other) const { return val < other.val; }\n  modint\
    \ &operator+=(const modint &p) {\n    if ((val += p.val) >= umod) val -= umod;\n\
    \    return *this;\n  }\n  modint &operator-=(const modint &p) {\n    if ((val\
    \ += umod - p.val) >= umod) val -= umod;\n    return *this;\n  }\n  modint &operator*=(const\
    \ modint &p) {\n    val = u64(val) * p.val % umod;\n    return *this;\n  }\n \
    \ modint &operator/=(const modint &p) {\n    *this *= p.inverse();\n    return\
    \ *this;\n  }\n  modint operator-() const { return modint::raw(val ? mod - val\
    \ : u32(0)); }\n  modint operator+(const modint &p) const { return modint(*this)\
    \ += p; }\n  modint operator-(const modint &p) const { return modint(*this) -=\
    \ p; }\n  modint operator*(const modint &p) const { return modint(*this) *= p;\
    \ }\n  modint operator/(const modint &p) const { return modint(*this) /= p; }\n\
    \  bool operator==(const modint &p) const { return val == p.val; }\n  bool operator!=(const\
    \ modint &p) const { return val != p.val; }\n  modint inverse() const {\n    int\
    \ a = val, b = mod, u = 1, v = 0, t;\n    while (b > 0) {\n      t = a / b;\n\
    \      swap(a -= t * b, b), swap(u -= t * v, v);\n    }\n    return modint(u);\n\
    \  }\n  modint pow(ll n) const {\n    if (n < 0) return inverse().pow(-n);\n \
    \   assert(n >= 0);\n    modint ret(1), mul(val);\n    while (n > 0) {\n     \
    \ if (n & 1) ret *= mul;\n      mul *= mul;\n      n >>= 1;\n    }\n    return\
    \ ret;\n  }\n  static constexpr int get_mod() { return mod; }\n  // (n, r), r\
    \ \u306F 1 \u306E 2^n \u4E57\u6839\n  static constexpr pair<int, int> ntt_info()\
    \ {\n    if (mod == 120586241) return {20, 74066978};\n    if (mod == 167772161)\
    \ return {25, 17};\n    if (mod == 469762049) return {26, 30};\n    if (mod ==\
    \ 754974721) return {24, 362};\n    if (mod == 880803841) return {23, 211};\n\
    \    if (mod == 943718401) return {22, 663003469};\n    if (mod == 998244353)\
    \ return {23, 31};\n    if (mod == 1004535809) return {21, 582313106};\n    if\
    \ (mod == 1012924417) return {21, 368093570};\n    if (mod == 1224736769) return\
    \ {24, 1191450770};\n    if (mod == 2013265921) return {27, 244035102};\n    return\
    \ {-1, -1};\n  }\n  static constexpr bool can_ntt() { return ntt_info().fi !=\
    \ -1; }\n};\n\n#ifdef FASTIO\ntemplate <int mod>\nvoid rd(modint<mod> &x) {\n\
    \  fastio::rd(x.val);\n  x.val %= mod;\n  // assert(0 <= x.val && x.val < mod);\n\
    }\ntemplate <int mod>\nvoid wt(modint<mod> x) {\n  fastio::wt(x.val);\n}\n#endif\n\
    \nusing modint107 = modint<1000000007>;\nusing modint998 = modint<998244353>;\n\
    #line 1 \"ds/offline_query/mo.hpp\"\n// Nsqrt(Q)\r\nstruct Mo {\r\n  vc<pair<int,\
    \ int>> LR;\r\n  void add(int L, int R) { LR.emplace_back(L, R); }\r\n\r\n  static\
    \ vc<int> get_mo_order(vc<pair<int, int>> LR) {\r\n    int N = 1;\r\n    for (auto\
    \ &&[l, r]: LR) chmax(N, l), chmax(N, r);\r\n    int Q = len(LR);\r\n    if (Q\
    \ == 0) return {};\r\n    int bs = sqrt(3) * N / sqrt(2 * Q);\r\n    chmax(bs,\
    \ 1);\r\n    vc<int> I(Q);\r\n    iota(all(I), 0);\r\n    sort(all(I), [&](int\
    \ a, int b) {\r\n      int aa = LR[a].fi / bs, bb = LR[b].fi / bs;\r\n      if\
    \ (aa != bb) return aa < bb;\r\n      return (aa & 1) ? LR[a].se > LR[b].se :\
    \ LR[a].se < LR[b].se;\r\n    });\r\n\r\n    auto cost = [&](int a, int b) ->\
    \ int {\r\n      return abs(LR[I[a]].fi - LR[I[b]].fi) + abs(LR[I[a]].se - LR[I[b]].se);\r\
    \n    };\r\n\r\n    // \u30E9\u30F3\u30C0\u30E0\u30B1\u30FC\u30B9\u3067\u6570\u30D1\
    \u30FC\u30BB\u30F3\u30C8\r\n    FOR(k, Q - 5) {\r\n      if (cost(k, k + 2) +\
    \ cost(k + 1, k + 3)\r\n          < cost(k, k + 1) + cost(k + 2, k + 3)) {\r\n\
    \        swap(I[k + 1], I[k + 2]);\r\n      }\r\n      if (cost(k, k + 3) + cost(k\
    \ + 1, k + 4)\r\n          < cost(k, k + 1) + cost(k + 3, k + 4)) {\r\n      \
    \  swap(I[k + 1], I[k + 3]);\r\n      }\r\n    }\r\n    return I;\r\n  }\r\n\r\
    \n  template <typename F1, typename F2, typename F3, typename F4, typename F5>\r\
    \n  void calc(F1 add_l, F2 add_r, F3 rm_l, F4 rm_r, F5 query) {\r\n    auto I\
    \ = get_mo_order(LR);\r\n    int l = 0, r = 0;\r\n    for (auto idx: I) {\r\n\
    \      while (l > LR[idx].fi) add_l(--l);\r\n      while (r < LR[idx].se) add_r(r++);\r\
    \n      while (l < LR[idx].fi) rm_l(l++);\r\n      while (r > LR[idx].se) rm_r(--r);\r\
    \n      query(idx);\r\n    }\r\n  }\r\n};\r\n#line 2 \"mod/prefix_sum_of_binom.hpp\"\
    \n\ntemplate <typename mint>\nstruct Prefix_Sum_Of_Binom {\n  static constexpr\
    \ u32 mod = mint::get_mod();\n  const int MAX_N;\n  const int B;\n  vc<mint> POW;\n\
    \  vvc<mint> dat;\n\n  Prefix_Sum_Of_Binom(int MAX_N) : MAX_N(MAX_N), B(sqrt(MAX_N\
    \ + 1)) {\n    assert(MAX_N >= 0);\n    int K = ceil(MAX_N, B + B) + 2;\n    int\
    \ p = max(MAX_N, K * B);\n    POW.assign(p + 1, mint(1));\n    FOR(i, p) POW[i\
    \ + 1] = POW[i] + POW[i];\n    dat.resize(K);\n    FOR(k, 0, K) {\n      // [0,\
    \ kB] \u3067\u306E closed sum\n      vc<mint>& f = dat[k];\n      if (MAX_N +\
    \ 1 - k * B <= 0) continue;\n      f.resize(MAX_N + 1 - k * B);\n      int m =\
    \ k * B;\n      f[0] = POW[m] * fact<mint>(m);\n      FOR(i, MAX_N - m) {\n  \
    \      f[i + 1] = f[i] + f[i] - fact<mint>(i + m) * fact_inv<mint>(i);\n     \
    \ }\n    }\n  }\n\n  // \\sum_{k=0}^{m-1} binom(n,k)\n  mint query(int n, int\
    \ m) {\n    assert(0 <= m);\n    chmin(m, n + 1);\n    if (m == 0) return mint(0);\n\
    \    if (m + m > n + 1) return POW[n] - query(n, n + 1 - m);\n    --m;\n    int\
    \ a = m / B;\n\n    if (m <= a * B + B / 2) {\n      u128 t = 0;\n      FOR(i,\
    \ a * B + 1, m + 1) {\n        t += u64(fact_inv<mint>(i).val) * (fact_inv<mint>(n\
    \ - i).val);\n      }\n      return _get(n, a) + mint::raw(t % mod) * fact<mint>(n);\n\
    \    } else {\n      u128 t = 0;\n      FOR(i, m + 1, (a + 1) * B + 1) {\n   \
    \     t += u64(fact_inv<mint>(i).val) * (fact_inv<mint>(n - i).val);\n      }\n\
    \      return _get(n, a + 1) - mint::raw(t % mod) * fact<mint>(n);\n    }\n  \
    \  return 0;\n  }\n\n private:\n  mint _get(int n, int k) {\n    if (n <= k *\
    \ B) return POW[n];\n    return dat[k][n - k * B] * fact_inv<mint>(k * B);\n \
    \ }\n};\n\ntemplate <typename mint>\nstruct Prefix_Sum_Of_Binom_Offline {\n  vc<pair<int,\
    \ int>> query;\n\n  void add(int n, int m) { query.eb(n, m); }\n\n  vc<mint> calc()\
    \ {\n    int Q = len(query);\n    vc<mint> ANS(Q);\n    auto I = Mo::get_mo_order(query);\n\
    \    int n = 0, m = 0;\n    mint ans = 0;\n    mint inv2 = inv<mint>(2);\n   \
    \ for (auto& i : I) {\n      auto [nn, mm] = query[i];\n      while (n < nn) {\n\
    \        ans = ans + ans - C<mint>(n, m - 1);\n        n++;\n      }\n      while\
    \ (n > nn) {\n        ans += C<mint>(n - 1, m - 1);\n        ans *= inv2;\n  \
    \      --n;\n      }\n      while (m < mm) {\n        ans += C<mint>(n, m++);\n\
    \      }\n      while (m > mm) {\n        ans -= C<mint>(n, --m);\n      }\n \
    \     ANS[i] = ans;\n    }\n    return ANS;\n  }\n};\n#line 6 \"test/1_mytest/prefix_sum_of_binom.test.cpp\"\
    \n\nusing mint = modint998;\n\nvoid test() {\n  FOR(LIM, 0, 500) {\n    Prefix_Sum_Of_Binom<mint>\
    \ X(LIM);\n    FOR(N, LIM + 1) {\n      mint sm = 0;\n      FOR(k, N + 10) {\n\
    \        assert(sm == X.query(N, k));\n        sm += C<mint>(N, k);\n      }\n\
    \    }\n  }\n}\n\nvoid solve() {\n  int a, b;\n  cin >> a >> b;\n  cout << a +\
    \ b << \"\\n\";\n}\n\nsigned main() {\n  test();\n  solve();\n  return 0;\n}\n"
  code: "#define PROBLEM \"https://judge.yosupo.jp/problem/aplusb\"\n#include \"my_template.hpp\"\
    \n\n#include \"mod/modint.hpp\"\n#include \"mod/prefix_sum_of_binom.hpp\"\n\n\
    using mint = modint998;\n\nvoid test() {\n  FOR(LIM, 0, 500) {\n    Prefix_Sum_Of_Binom<mint>\
    \ X(LIM);\n    FOR(N, LIM + 1) {\n      mint sm = 0;\n      FOR(k, N + 10) {\n\
    \        assert(sm == X.query(N, k));\n        sm += C<mint>(N, k);\n      }\n\
    \    }\n  }\n}\n\nvoid solve() {\n  int a, b;\n  cin >> a >> b;\n  cout << a +\
    \ b << \"\\n\";\n}\n\nsigned main() {\n  test();\n  solve();\n  return 0;\n}\n"
  dependsOn:
  - my_template.hpp
  - mod/modint.hpp
  - mod/modint_common.hpp
  - mod/prefix_sum_of_binom.hpp
  - ds/offline_query/mo.hpp
  isVerificationFile: true
  path: test/1_mytest/prefix_sum_of_binom.test.cpp
  requiredBy: []
  timestamp: '2026-07-26 19:43:20+09:00'
  verificationStatus: TEST_WRONG_ANSWER
  verifiedWith: []
documentation_of: test/1_mytest/prefix_sum_of_binom.test.cpp
layout: document
redirect_from:
- /verify/test/1_mytest/prefix_sum_of_binom.test.cpp
- /verify/test/1_mytest/prefix_sum_of_binom.test.cpp.html
title: test/1_mytest/prefix_sum_of_binom.test.cpp
---
