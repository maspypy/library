---
data:
  _extendedDependsOn:
  - icon: ':question:'
    path: alg/monoid/affine.hpp
    title: alg/monoid/affine.hpp
  - icon: ':heavy_check_mark:'
    path: ds/segtree/prefix_max_segtree.hpp
    title: ds/segtree/prefix_max_segtree.hpp
  - icon: ':question:'
    path: mod/modint.hpp
    title: mod/modint.hpp
  - icon: ':question:'
    path: mod/modint_common.hpp
    title: mod/modint_common.hpp
  - icon: ':question:'
    path: my_template.hpp
    title: my_template.hpp
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
  bundledCode: "#line 1 \"test/1_mytest/prefix_max_segtree.test.cpp\"\n#define PROBLEM\
    \ \"https://judge.yosupo.jp/problem/aplusb\"\n\n#line 1 \"my_template.hpp\"\n\
    #if defined(LOCAL)\n#include <my_template_compiled.hpp>\n#else\n\n// https://codeforces.com/blog/entry/96344\n\
    #pragma GCC optimize(\"Ofast,unroll-loops\")\n// \u3044\u307E\u306E CF \u3060\u3068\
    \u3053\u308C\u5165\u308C\u308B\u3068\u52D5\u304B\u306A\u3044\uFF1F\n// #pragma\
    \ GCC target(\"avx2,popcnt\")\n\n#include <bits/stdc++.h>\n\nusing namespace std;\n\
    \nusing ll = long long;\nusing u8 = uint8_t;\nusing u16 = uint16_t;\nusing u32\
    \ = uint32_t;\nusing u64 = uint64_t;\nusing i128 = __int128;\nusing u128 = unsigned\
    \ __int128;\nusing f128 = __float128;\n\ntemplate <class T>\nconstexpr T infty\
    \ = 0;\ntemplate <>\nconstexpr int infty<int> = 1'010'000'000;\ntemplate <>\n\
    constexpr ll infty<ll> = 2'020'000'000'000'000'000;\ntemplate <>\nconstexpr u32\
    \ infty<u32> = infty<int>;\ntemplate <>\nconstexpr u64 infty<u64> = infty<ll>;\n\
    template <>\nconstexpr i128 infty<i128> = i128(infty<ll>) * 2'000'000'000'000'000'000;\n\
    template <>\nconstexpr double infty<double> = infty<ll>;\ntemplate <>\nconstexpr\
    \ long double infty<long double> = infty<ll>;\n\nusing pi = pair<ll, ll>;\nusing\
    \ vi = vector<ll>;\ntemplate <class T>\nusing vc = vector<T>;\ntemplate <class\
    \ T>\nusing vvc = vector<vc<T>>;\ntemplate <class T>\nusing vvvc = vector<vvc<T>>;\n\
    template <class T>\nusing vvvvc = vector<vvvc<T>>;\ntemplate <class T>\nusing\
    \ vvvvvc = vector<vvvvc<T>>;\ntemplate <class T>\nusing pq = priority_queue<T>;\n\
    template <class T>\nusing pqg = priority_queue<T, vector<T>, greater<T>>;\n\n\
    #define vv(type, name, h, ...) vector<vector<type>> name(h, vector<type>(__VA_ARGS__))\n\
    #define vvv(type, name, h, w, ...) vector<vector<vector<type>>> name(h, vector<vector<type>>(w,\
    \ vector<type>(__VA_ARGS__)))\n#define vvvv(type, name, a, b, c, ...) \\\n  vector<vector<vector<vector<type>>>>\
    \ name(a, vector<vector<vector<type>>>(b, vector<vector<type>>(c, vector<type>(__VA_ARGS__))))\n\
    \n// https://trap.jp/post/1224/\n#define FOR1(a) for (ll _ = 0; _ < ll(a); ++_)\n\
    #define FOR2(i, a) for (ll i = 0; i < ll(a); ++i)\n#define FOR3(i, a, b) for (ll\
    \ i = a; i < ll(b); ++i)\n#define FOR4(i, a, b, c) for (ll i = a; i < ll(b); i\
    \ += (c))\n#define FOR1_R(a) for (ll i = (a)-1; i >= ll(0); --i)\n#define FOR2_R(i,\
    \ a) for (ll i = (a)-1; i >= ll(0); --i)\n#define FOR3_R(i, a, b) for (ll i =\
    \ (b)-1; i >= ll(a); --i)\n#define overload4(a, b, c, d, e, ...) e\n#define overload3(a,\
    \ b, c, d, ...) d\n#define FOR(...) overload4(__VA_ARGS__, FOR4, FOR3, FOR2, FOR1)(__VA_ARGS__)\n\
    #define FOR_R(...) overload3(__VA_ARGS__, FOR3_R, FOR2_R, FOR1_R)(__VA_ARGS__)\n\
    \n#define FOR_subset(t, s) for (ll t = (s); t >= 0; t = (t == 0 ? -1 : (t - 1)\
    \ & (s)))\n#define all(x) x.begin(), x.end()\n#define len(x) ll(x.size())\n#define\
    \ elif else if\n\n#define eb emplace_back\n#define mp make_pair\n#define mt make_tuple\n\
    #define fi first\n#define se second\n\n#define stoi stoll\n\nint popcnt(int x)\
    \ { return __builtin_popcount(x); }\nint popcnt(u32 x) { return __builtin_popcount(x);\
    \ }\nint popcnt(ll x) { return __builtin_popcountll(x); }\nint popcnt(u64 x) {\
    \ return __builtin_popcountll(x); }\nint popcnt_sgn(int x) { return (__builtin_parity(x)\
    \ & 1 ? -1 : 1); }\nint popcnt_sgn(u32 x) { return (__builtin_parity(x) & 1 ?\
    \ -1 : 1); }\nint popcnt_sgn(ll x) { return (__builtin_parity(x) & 1 ? -1 : 1);\
    \ }\nint popcnt_sgn(u64 x) { return (__builtin_parity(x) & 1 ? -1 : 1); }\n//\
    \ (0, 1, 2, 3, 4) -> (-1, 0, 1, 1, 2)\nint topbit(int x) { return (x == 0 ? -1\
    \ : 31 - __builtin_clz(x)); }\nint topbit(u32 x) { return (x == 0 ? -1 : 31 -\
    \ __builtin_clz(x)); }\nint topbit(ll x) { return (x == 0 ? -1 : 63 - __builtin_clzll(x));\
    \ }\nint topbit(u64 x) { return (x == 0 ? -1 : 63 - __builtin_clzll(x)); }\n//\
    \ (0, 1, 2, 3, 4) -> (-1, 0, 1, 0, 2)\nint lowbit(int x) { return (x == 0 ? -1\
    \ : __builtin_ctz(x)); }\nint lowbit(u32 x) { return (x == 0 ? -1 : __builtin_ctz(x));\
    \ }\nint lowbit(ll x) { return (x == 0 ? -1 : __builtin_ctzll(x)); }\nint lowbit(u64\
    \ x) { return (x == 0 ? -1 : __builtin_ctzll(x)); }\n\ntemplate <typename T>\n\
    T kth_bit(int k) {\n  return T(1) << k;\n}\ntemplate <typename T>\nbool has_kth_bit(T\
    \ x, int k) {\n  return x >> k & 1;\n}\n\ntemplate <typename T>\nT floor(T a,\
    \ T b) {\n  return a / b - (a % b && (a ^ b) < 0);\n}\ntemplate <typename T>\n\
    T ceil(T x, T y) {\n  return floor(x + y - 1, y);\n}\ntemplate <typename T>\n\
    T bmod(T x, T y) {\n  return x - y * floor(x, y);\n}\ntemplate <typename T>\n\
    pair<T, T> divmod(T x, T y) {\n  T q = floor(x, y);\n  return {q, x - q * y};\n\
    }\n\ntemplate <typename T, typename U>\nT SUM(const vector<U> &A) {\n  T sm =\
    \ 0;\n  for (auto &&a: A) sm += a;\n  return sm;\n}\n\n#define MIN(v) *min_element(all(v))\n\
    #define MAX(v) *max_element(all(v))\n#define LB(c, x) distance((c).begin(), lower_bound(all(c),\
    \ (x)))\n#define UB(c, x) distance((c).begin(), upper_bound(all(c), (x)))\n#define\
    \ UNIQUE(x) sort(all(x)), x.erase(unique(all(x)), x.end()), x.shrink_to_fit()\n\
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
    \ vector<T> &A) {\n  vector<int> ids(len(A));\n  iota(all(ids), 0);\n  sort(all(ids),\
    \ [&](int i, int j) { return (A[i] == A[j] ? i < j : A[i] < A[j]); });\n  return\
    \ ids;\n}\n\n// A[I[0]], A[I[1]], ...\ntemplate <typename T>\nvc<T> rearrange(const\
    \ vc<T> &A, const vc<int> &I) {\n  vc<T> B(len(I));\n  FOR(i, len(I)) B[i] = A[I[i]];\n\
    \  return B;\n}\n\ntemplate <typename T, typename... Vectors>\nvoid concat(vc<T>\
    \ &first, const Vectors &... others) {\n  vc<T> &res = first;\n  (res.insert(res.end(),\
    \ others.begin(), others.end()), ...);\n}\n#endif\n#line 4 \"test/1_mytest/prefix_max_segtree.test.cpp\"\
    \n\n#line 1 \"ds/segtree/prefix_max_segtree.hpp\"\n\n/*\nkey[0],...,key[n-1] \u304C\
    \u3042\u308B\n\u30E2\u30CE\u30A4\u30C9\u306E\u5217 x[0],...,x[n-1] \u304C\u3042\
    \u308B\nquery(l,r): l \u304B\u3089\u898B\u3048\u308B\u3068\u3053\u308D\u306B\u5BFE\
    \u3059\u308B monoid product\n\u898B\u3048\u308B: key[i]==max(key[0]...key[i])\n\
    Qlog^2n\nhttps://qoj.ac/contest/1540/problem/8338\n*/\ntemplate <typename KEY_TYPE,\
    \ typename Monoid>\nstruct Prefix_Max_SegTree {\n  using MX = Monoid;\n  using\
    \ KEY = KEY_TYPE;\n  using X = typename MX::value_type;\n  int n, size, log;\n\
    \  struct Data {\n    KEY max;\n    X prod, rprod; // rprod \u306F\u3053\u306E\
    \u533A\u9593\u3060\u3051\u3067\u8A08\u7B97\u3057\u305F\u3068\u304D\u306E\u53F3\
    \u5074\n  };\n\n  vc<Data> dat;\n\n  Prefix_Max_SegTree() {}\n  Prefix_Max_SegTree(int\
    \ n) { build(n); }\n  template <typename F>\n  Prefix_Max_SegTree(int n, F f)\
    \ {\n    build(n, f);\n  }\n  Prefix_Max_SegTree(const vc<X>& v) { build(v); }\n\
    \n  void build(int m) {\n    build(m, [](int i) -> pair<KEY, X> { return {-infty<int>,\
    \ MX::unit()}; });\n  }\n  template <typename F>\n  void build(int m, F f) {\n\
    \    n = m, log = 1;\n    while ((1 << log) < n) ++log;\n    size = 1 << log;\n\
    \    dat.assign(size << 1, {-infty<int>, MX::unit(), MX::unit()});\n    FOR(i,\
    \ n) {\n      auto [k, x] = f(i);\n      dat[size + i] = {k, x, MX::unit()};\n\
    \    }\n    FOR_R(i, 1, size) update(i);\n  }\n\n  void set(int i, pair<KEY, X>\
    \ p) {\n    int k = p.fi;\n    X x = p.se;\n    i += size;\n    dat[i] = {k, x,\
    \ MX::unit()};\n    while (i > 1) i /= 2, update(i);\n  }\n\n  X prod_all() {\
    \ return dat[1].prod; }\n  X prod(int L, int R) {\n    KEY k = -infty<KEY>;\n\
    \    vc<int> suff;\n    L += size, R += size;\n    X prod = MX::unit();\n    while\
    \ (L < R) {\n      if (L & 1) { prod = MX::op(prod, dfs(L, k)), chmax(k, dat[L].max),\
    \ ++L; }\n      if (R & 1) { suff.eb(--R); }\n      L /= 2, R /= 2;\n    }\n \
    \   reverse(all(suff));\n    for (auto& v: suff) { prod = MX::op(prod, dfs(v,\
    \ k)), chmax(k, dat[v].max); }\n    return prod;\n  }\n\n  pair<KEY, X> get(int\
    \ i) { return {dat[size + i].max, dat[size + i].prod}; }\n  pair<vc<KEY>, vc<X>>\
    \ get_all() {\n    vc<KEY> key(n);\n    vc<X> x(n);\n    FOR(i, n) key[i] = dat[size\
    \ + i].max, x[i] = dat[size + i].prod;\n    return {key, x};\n  }\n\nprivate:\n\
    \  void update(int i) {\n    assert(0 <= i && i < size);\n    dat[i].max = max(dat[2\
    \ * i + 0].max, dat[2 * i + 1].max);\n    dat[i].rprod = dfs(2 * i + 1, dat[2\
    \ * i + 0].max);\n    dat[i].prod = MX::op(dat[2 * i + 0].prod, dat[i].rprod);\n\
    \  }\n\n  X dfs(int v, KEY k) {\n    // prefix \u306B k \u3092\u7F6E\u3044\u305F\
    \u5834\u5408\u306E subtree(v) \u3067\u306E\u5024\n    if (size <= v) { return\
    \ (k <= dat[v].max ? dat[v].prod : MX::unit()); }\n    if (k <= dat[2 * v + 0].max)\
    \ { return MX::op(dfs(2 * v + 0, k), dat[v].rprod); }\n    return dfs(2 * v +\
    \ 1, k);\n  }\n};\n#line 2 \"random/base.hpp\"\n\nu64 RNG_64() {\n  static u64\
    \ x_ = u64(chrono::duration_cast<chrono::nanoseconds>(chrono::high_resolution_clock::now().time_since_epoch()).count())\
    \ * 10150724397891781847ULL;\n  x_ ^= x_ << 7;\n  return x_ ^= x_ >> 9;\n}\n\n\
    u64 RNG(u64 lim) { return RNG_64() % lim; }\n\nll RNG(ll l, ll r) { return l +\
    \ RNG_64() % (r - l); }\n#line 2 \"alg/monoid/affine.hpp\"\n\n// op(F, G) = comp(G,F),\
    \ F \u306E\u3042\u3068\u3067 G\ntemplate <typename K>\nstruct Monoid_Affine {\n\
    \  using F = pair<K, K>;\n  using value_type = F;\n  using X = value_type;\n \
    \ static constexpr F op(const F &x, const F &y) noexcept {\n    return F({x.first\
    \ * y.first, x.second * y.first + y.second});\n  }\n  static constexpr F inverse(const\
    \ F &x) {\n    auto [a, b] = x;\n    a = K(1) / a;\n    return {a, a * (-b)};\n\
    \  }\n  static constexpr K eval(const F &f, K x) noexcept {\n    return f.first\
    \ * x + f.second;\n  }\n  static constexpr F unit() { return {K(1), K(0)}; }\n\
    \  static constexpr bool commute = false;\n};\n#line 2 \"mod/modint_common.hpp\"\
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
    \ n, ll d) {\n  assert(n >= 0);\n  if (d < 0) return mint(0);\n  if (n == 0) {\
    \ return (d == 0 ? mint(1) : mint(0)); }\n  return C<mint, large, dense>(n + d\
    \ - 1, d);\n}\n#line 3 \"mod/modint.hpp\"\n\ntemplate <int mod>\nstruct modint\
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
    \  }\n  modint pow(ll n) const {\n    assert(n >= 0);\n    modint ret(1), mul(val);\n\
    \    while (n > 0) {\n      if (n & 1) ret *= mul;\n      mul *= mul;\n      n\
    \ >>= 1;\n    }\n    return ret;\n  }\n  static constexpr int get_mod() { return\
    \ mod; }\n  // (n, r), r \u306F 1 \u306E 2^n \u4E57\u6839\n  static constexpr\
    \ pair<int, int> ntt_info() {\n    if (mod == 120586241) return {20, 74066978};\n\
    \    if (mod == 167772161) return {25, 17};\n    if (mod == 469762049) return\
    \ {26, 30};\n    if (mod == 754974721) return {24, 362};\n    if (mod == 880803841)\
    \ return {23, 211};\n    if (mod == 943718401) return {22, 663003469};\n    if\
    \ (mod == 998244353) return {23, 31};\n    if (mod == 1004535809) return {21,\
    \ 582313106};\n    if (mod == 1012924417) return {21, 368093570};\n    return\
    \ {-1, -1};\n  }\n  static constexpr bool can_ntt() { return ntt_info().fi !=\
    \ -1; }\n};\n\n#ifdef FASTIO\ntemplate <int mod>\nvoid rd(modint<mod> &x) {\n\
    \  fastio::rd(x.val);\n  x.val %= mod;\n  // assert(0 <= x.val && x.val < mod);\n\
    }\ntemplate <int mod>\nvoid wt(modint<mod> x) {\n  fastio::wt(x.val);\n}\n#endif\n\
    \nusing modint107 = modint<1000000007>;\nusing modint998 = modint<998244353>;\n\
    #line 9 \"test/1_mytest/prefix_max_segtree.test.cpp\"\n\nusing mint = modint998;\n\
    using F = pair<mint, mint>;\n\nvoid test(ll N) {\n  vc<int> key(N);\n  vc<F> X(N);\n\
    \  auto get = [&]() -> pair<int, F> {\n    int k = RNG(0, 100);\n    mint a =\
    \ RNG(0, mint::get_mod());\n    mint b = RNG(0, mint::get_mod());\n    return\
    \ {k, {a, b}};\n  };\n\n  FOR(i, N) tie(key[i], X[i]) = get();\n\n  auto segf\
    \ = [&](int i) -> pair<int, F> { return {key[i], X[i]}; };\n\n  using Mono = Monoid_Affine<mint>;\n\
    \  Prefix_Max_SegTree<int, Mono> seg(N, segf);\n\n  auto naive = [&](int L, int\
    \ R) -> F {\n    int mx = -infty<int>;\n    F prod = Mono::unit();\n    FOR(i,\
    \ L, R) {\n      if (mx <= key[i]) {\n        mx = key[i];\n        prod = Mono::op(prod,\
    \ X[i]);\n      }\n    }\n    return prod;\n  };\n\n  /*\n  set\n  get\n  get_all\n\
    \  prod\n  prod_all\n  */\n  int Q = 1000;\n  FOR(Q) {\n    int t = RNG(0, 5);\n\
    \    int i = RNG(0, N);\n    int L = RNG(0, N), R = RNG(0, N);\n    auto [k, x]\
    \ = get();\n    if (L > R) swap(L, R);\n    ++R;\n    if (t == 0) {\n      key[i]\
    \ = k, X[i] = x;\n      seg.set(i, {k, x});\n    }\n    if (t == 1) {\n      auto\
    \ [k, x] = seg.get(i);\n      assert(key[i] == k);\n      assert(X[i] == x);\n\
    \    }\n    if (t == 2) {\n      auto [k, x] = seg.get_all();\n      assert(key\
    \ == k);\n      assert(X == x);\n    }\n    if (t == 3) { assert(naive(L, R) ==\
    \ seg.prod(L, R)); }\n    if (t == 4) { assert(naive(0, N) == seg.prod_all());\
    \ }\n  }\n}\n\nvoid solve() {\n  int a, b;\n  cin >> a >> b;\n  cout << a + b\
    \ << \"\\n\";\n}\n\nsigned main() {\n  FOR(100) FOR(N, 1, 100) { test(N); }\n\
    \  solve();\n  return 0;\n}\n"
  code: "#define PROBLEM \"https://judge.yosupo.jp/problem/aplusb\"\n\n#include \"\
    my_template.hpp\"\n\n#include \"ds/segtree/prefix_max_segtree.hpp\"\n#include\
    \ \"random/base.hpp\"\n#include \"alg/monoid/affine.hpp\"\n#include \"mod/modint.hpp\"\
    \n\nusing mint = modint998;\nusing F = pair<mint, mint>;\n\nvoid test(ll N) {\n\
    \  vc<int> key(N);\n  vc<F> X(N);\n  auto get = [&]() -> pair<int, F> {\n    int\
    \ k = RNG(0, 100);\n    mint a = RNG(0, mint::get_mod());\n    mint b = RNG(0,\
    \ mint::get_mod());\n    return {k, {a, b}};\n  };\n\n  FOR(i, N) tie(key[i],\
    \ X[i]) = get();\n\n  auto segf = [&](int i) -> pair<int, F> { return {key[i],\
    \ X[i]}; };\n\n  using Mono = Monoid_Affine<mint>;\n  Prefix_Max_SegTree<int,\
    \ Mono> seg(N, segf);\n\n  auto naive = [&](int L, int R) -> F {\n    int mx =\
    \ -infty<int>;\n    F prod = Mono::unit();\n    FOR(i, L, R) {\n      if (mx <=\
    \ key[i]) {\n        mx = key[i];\n        prod = Mono::op(prod, X[i]);\n    \
    \  }\n    }\n    return prod;\n  };\n\n  /*\n  set\n  get\n  get_all\n  prod\n\
    \  prod_all\n  */\n  int Q = 1000;\n  FOR(Q) {\n    int t = RNG(0, 5);\n    int\
    \ i = RNG(0, N);\n    int L = RNG(0, N), R = RNG(0, N);\n    auto [k, x] = get();\n\
    \    if (L > R) swap(L, R);\n    ++R;\n    if (t == 0) {\n      key[i] = k, X[i]\
    \ = x;\n      seg.set(i, {k, x});\n    }\n    if (t == 1) {\n      auto [k, x]\
    \ = seg.get(i);\n      assert(key[i] == k);\n      assert(X[i] == x);\n    }\n\
    \    if (t == 2) {\n      auto [k, x] = seg.get_all();\n      assert(key == k);\n\
    \      assert(X == x);\n    }\n    if (t == 3) { assert(naive(L, R) == seg.prod(L,\
    \ R)); }\n    if (t == 4) { assert(naive(0, N) == seg.prod_all()); }\n  }\n}\n\
    \nvoid solve() {\n  int a, b;\n  cin >> a >> b;\n  cout << a + b << \"\\n\";\n\
    }\n\nsigned main() {\n  FOR(100) FOR(N, 1, 100) { test(N); }\n  solve();\n  return\
    \ 0;\n}\n"
  dependsOn:
  - my_template.hpp
  - ds/segtree/prefix_max_segtree.hpp
  - random/base.hpp
  - alg/monoid/affine.hpp
  - mod/modint.hpp
  - mod/modint_common.hpp
  isVerificationFile: true
  path: test/1_mytest/prefix_max_segtree.test.cpp
  requiredBy: []
  timestamp: '2024-11-16 23:01:41+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: test/1_mytest/prefix_max_segtree.test.cpp
layout: document
redirect_from:
- /verify/test/1_mytest/prefix_max_segtree.test.cpp
- /verify/test/1_mytest/prefix_max_segtree.test.cpp.html
title: test/1_mytest/prefix_max_segtree.test.cpp
---
