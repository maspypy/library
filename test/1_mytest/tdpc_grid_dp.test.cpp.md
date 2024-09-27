---
data:
  _extendedDependsOn:
  - icon: ':x:'
    path: ds/hashmap.hpp
    title: ds/hashmap.hpp
  - icon: ':question:'
    path: mod/modint.hpp
    title: mod/modint.hpp
  - icon: ':x:'
    path: mod/modint61.hpp
    title: mod/modint61.hpp
  - icon: ':question:'
    path: mod/modint_common.hpp
    title: mod/modint_common.hpp
  - icon: ':question:'
    path: my_template.hpp
    title: my_template.hpp
  - icon: ':x:'
    path: other/connected_dp.hpp
    title: other/connected_dp.hpp
  - icon: ':question:'
    path: random/base.hpp
    title: random/base.hpp
  - icon: ':x:'
    path: random/hash_vector.hpp
    title: random/hash_vector.hpp
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
  bundledCode: "#line 1 \"test/1_mytest/tdpc_grid_dp.test.cpp\"\n#define PROBLEM \"\
    https://judge.yosupo.jp/problem/aplusb\"\n#line 1 \"my_template.hpp\"\n#if defined(LOCAL)\n\
    #include <my_template_compiled.hpp>\n#else\n\n// https://codeforces.com/blog/entry/96344\n\
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
    \ others.end()), ...);\n}\n#endif\n#line 3 \"test/1_mytest/tdpc_grid_dp.test.cpp\"\
    \n\n#line 2 \"ds/hashmap.hpp\"\n\r\n// u64 -> Val\r\ntemplate <typename Val>\r\
    \nstruct HashMap {\r\n  // n \u306F\u5165\u308C\u305F\u3044\u3082\u306E\u306E\u500B\
    \u6570\u3067 ok\r\n  HashMap(u32 n = 0) { build(n); }\r\n  void build(u32 n) {\r\
    \n    u32 k = 8;\r\n    while (k < n * 2) k *= 2;\r\n    cap = k / 2, mask = k\
    \ - 1;\r\n    key.resize(k), val.resize(k), used.assign(k, 0);\r\n  }\r\n\r\n\
    \  // size \u3092\u4FDD\u3063\u305F\u307E\u307E. size=0 \u306B\u3059\u308B\u3068\
    \u304D\u306F build \u3059\u308B\u3053\u3068.\r\n  void clear() {\r\n    used.assign(len(used),\
    \ 0);\r\n    cap = (mask + 1) / 2;\r\n  }\r\n  int size() { return len(used) /\
    \ 2 - cap; }\r\n\r\n  int index(const u64& k) {\r\n    int i = 0;\r\n    for (i\
    \ = hash(k); used[i] && key[i] != k; i = (i + 1) & mask) {}\r\n    return i;\r\
    \n  }\r\n\r\n  Val& operator[](const u64& k) {\r\n    if (cap == 0) extend();\r\
    \n    int i = index(k);\r\n    if (!used[i]) { used[i] = 1, key[i] = k, val[i]\
    \ = Val{}, --cap; }\r\n    return val[i];\r\n  }\r\n\r\n  Val get(const u64& k,\
    \ Val default_value) {\r\n    int i = index(k);\r\n    return (used[i] ? val[i]\
    \ : default_value);\r\n  }\r\n\r\n  bool count(const u64& k) {\r\n    int i =\
    \ index(k);\r\n    return used[i] && key[i] == k;\r\n  }\r\n\r\n  // f(key, val)\r\
    \n  template <typename F>\r\n  void enumerate_all(F f) {\r\n    FOR(i, len(used))\
    \ if (used[i]) f(key[i], val[i]);\r\n  }\r\n\r\nprivate:\r\n  u32 cap, mask;\r\
    \n  vc<u64> key;\r\n  vc<Val> val;\r\n  vc<bool> used;\r\n\r\n  u64 hash(u64 x)\
    \ {\r\n    static const u64 FIXED_RANDOM = std::chrono::steady_clock::now().time_since_epoch().count();\r\
    \n    x += FIXED_RANDOM;\r\n    x = (x ^ (x >> 30)) * 0xbf58476d1ce4e5b9;\r\n\
    \    x = (x ^ (x >> 27)) * 0x94d049bb133111eb;\r\n    return (x ^ (x >> 31)) &\
    \ mask;\r\n  }\r\n\r\n  void extend() {\r\n    vc<pair<u64, Val>> dat;\r\n   \
    \ dat.reserve(len(used) / 2 - cap);\r\n    FOR(i, len(used)) {\r\n      if (used[i])\
    \ dat.eb(key[i], val[i]);\r\n    }\r\n    build(2 * len(dat));\r\n    for (auto&\
    \ [a, b]: dat) (*this)[a] = b;\r\n  }\r\n};\n#line 2 \"random/hash_vector.hpp\"\
    \n\n#line 2 \"random/base.hpp\"\n\nu64 RNG_64() {\n  static uint64_t x_\n    \
    \  = uint64_t(chrono::duration_cast<chrono::nanoseconds>(chrono::high_resolution_clock::now().time_since_epoch()).count())\
    \ * 10150724397891781847ULL;\n  x_ ^= x_ << 7;\n  return x_ ^= x_ >> 9;\n}\n\n\
    u64 RNG(u64 lim) { return RNG_64() % lim; }\n\nll RNG(ll l, ll r) { return l +\
    \ RNG_64() % (r - l); }\n#line 2 \"mod/modint61.hpp\"\n\r\nstruct modint61 {\r\
    \n  static constexpr u64 mod = (1ULL << 61) - 1;\r\n  u64 val;\r\n  constexpr\
    \ modint61() : val(0ULL) {}\r\n  constexpr modint61(u32 x) : val(x) {}\r\n  constexpr\
    \ modint61(u64 x) : val(x % mod) {}\r\n  constexpr modint61(int x) : val((x <\
    \ 0) ? (x + static_cast<ll>(mod)) : x) {}\r\n  constexpr modint61(ll x) : val(((x\
    \ %= static_cast<ll>(mod)) < 0) ? (x + static_cast<ll>(mod)) : x) {}\r\n  static\
    \ constexpr u64 get_mod() { return mod; }\r\n\r\n  modint61 &operator+=(const\
    \ modint61 &a) {\r\n    val = ((val += a.val) >= mod) ? (val - mod) : val;\r\n\
    \    return *this;\r\n  }\r\n  modint61 &operator-=(const modint61 &a) {\r\n \
    \   val = ((val -= a.val) >= mod) ? (val + mod) : val;\r\n    return *this;\r\n\
    \  }\r\n  modint61 &operator*=(const modint61 &a) {\r\n    const unsigned __int128\
    \ y = static_cast<unsigned __int128>(val) * a.val;\r\n    val = (y >> 61) + (y\
    \ & mod);\r\n    val = (val >= mod) ? (val - mod) : val;\r\n    return *this;\r\
    \n  }\r\n  modint61 operator-() const { return modint61(val ? mod - val : u64(0));\
    \ }\r\n  modint61 &operator/=(const modint61 &a) { return (*this *= a.inverse());\
    \ }\r\n  modint61 operator+(const modint61 &p) const { return modint61(*this)\
    \ += p; }\r\n  modint61 operator-(const modint61 &p) const { return modint61(*this)\
    \ -= p; }\r\n  modint61 operator*(const modint61 &p) const { return modint61(*this)\
    \ *= p; }\r\n  modint61 operator/(const modint61 &p) const { return modint61(*this)\
    \ /= p; }\r\n  bool operator<(const modint61 &other) const { return val < other.val;\
    \ }\r\n  bool operator==(const modint61 &p) const { return val == p.val; }\r\n\
    \  bool operator!=(const modint61 &p) const { return val != p.val; }\r\n  modint61\
    \ inverse() const {\r\n    ll a = val, b = mod, u = 1, v = 0, t;\r\n    while\
    \ (b > 0) {\r\n      t = a / b;\r\n      swap(a -= t * b, b), swap(u -= t * v,\
    \ v);\r\n    }\r\n    return modint61(u);\r\n  }\r\n  modint61 pow(ll n) const\
    \ {\r\n    assert(n >= 0);\r\n    modint61 ret(1), mul(val);\r\n    while (n >\
    \ 0) {\r\n      if (n & 1) ret *= mul;\r\n      mul *= mul, n >>= 1;\r\n    }\r\
    \n    return ret;\r\n  }\r\n};\r\n\r\n#ifdef FASTIO\r\nvoid rd(modint61 &x) {\r\
    \n  fastio::rd(x.val);\r\n  assert(0 <= x.val && x.val < modint61::mod);\r\n}\r\
    \n\r\nvoid wt(modint61 x) { fastio::wt(x.val); }\r\n#endif\n#line 5 \"random/hash_vector.hpp\"\
    \n\ntemplate <typename T>\nu64 hash_vector(vc<T> X) {\n  using mint = modint61;\n\
    \  static vc<mint> hash_base;\n  int n = len(X);\n  while (len(hash_base) <= n)\
    \ { hash_base.eb(RNG(mint::get_mod())); }\n  mint H = 0;\n  FOR(i, n) H += hash_base[i]\
    \ * mint(X[i]);\n  H += hash_base[n];\n  return H.val;\n}\n#line 2 \"mod/modint_common.hpp\"\
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
    \ 1004535809) return {21, 836905998};\n    if (mod == 1045430273) return {20,\
    \ 363};\n    if (mod == 1051721729) return {20, 330};\n    if (mod == 1053818881)\
    \ return {20, 2789};\n    return {-1, -1};\n  }\n  static constexpr bool can_ntt()\
    \ { return ntt_info().fi != -1; }\n};\n\n#ifdef FASTIO\ntemplate <int mod>\nvoid\
    \ rd(modint<mod> &x) {\n  fastio::rd(x.val);\n  x.val %= mod;\n  // assert(0 <=\
    \ x.val && x.val < mod);\n}\ntemplate <int mod>\nvoid wt(modint<mod> x) {\n  fastio::wt(x.val);\n\
    }\n#endif\n\nusing modint107 = modint<1000000007>;\nusing modint998 = modint<998244353>;\n\
    #line 3 \"other/connected_dp.hpp\"\n\n// dot case: https://atcoder.jp/contests/ttpc2023/submissions/57905985\n\
    \nnamespace connected_dp_squares {\n// pair<\u65B0\u3057\u3044\u72B6\u614B\u3001\
    \u4ECA\u306E\u6210\u5206 \u2192 \u65B0\u3057\u3044\u6210\u5206>\nvc<pair<vc<int>,\
    \ vc<int>>> next_states(const vc<int>& now) {\n  int N = len(now);\n  vc<pair<vc<int>,\
    \ vc<int>>> res;\n  FOR(s, 1 << N) {\n    vc<int> par(N + N);\n    FOR(i, N) par[i]\
    \ = (s & 1 << i ? i : -1);\n    FOR(i, N) par[N + i] = (now[i] == -1 ? -1 : now[i]\
    \ + N);\n    auto find = [&](int x) -> int {\n      while (par[x] != x) { x =\
    \ par[x] = par[par[x]]; }\n      return x;\n    };\n    auto merge = [&](int a,\
    \ int b) -> void {\n      a = find(a), b = find(b);\n      if (a == b) return;\n\
    \      if (a > b) swap(a, b);\n      par[b] = a;\n    };\n\n    FOR(i, N - 1)\
    \ if (par[i] != -1 && par[i + 1] != -1) merge(i, i + 1);\n    FOR(i, N) if (par[i]\
    \ != -1 && par[N + i] != -1) merge(i, N + i);\n    FOR(i, N + N) if (par[i] !=\
    \ -1) par[i] = find(i);\n    FOR(i, N, N + N) if (par[i] >= N) par[i] = -1;\n\
    \    res.eb(vc<int>(par.begin(), par.begin() + N), vc<int>(par.begin() + N, par.end()));\n\
    \  }\n  return res;\n}\n\nvc<int> reverse_state(const vc<int>& now) {\n  int N\
    \ = len(now);\n  vc<int> max_i(N, -1);\n  FOR(i, N) if (now[i] != -1) max_i[now[i]]\
    \ = i;\n  vc<int> rev(N, -1);\n  FOR(i, N) {\n    if (now[i] == -1) continue;\n\
    \    int x = max_i[now[i]];\n    rev[N - 1 - i] = N - 1 - x;\n  }\n  return rev;\n\
    }\n\n// 0, 1 \uFF1A\u7A7A\u306E\u5217\u3001\u9818\u57DF\u306E\u624B\u524D\u3001\
    \u5F8C\u308D\n// \u9023\u7D50\u9818\u57DF\u3092\u3072\u3068\u3064\u4F5C\u308B\u3002\
    \n// \u72B6\u614B\uFF1A-1 \u304C\u9078\u3093\u3067\u3044\u306A\u3044\u30020,1,2,3\
    \ \u7B49\u306F\u540C\u3058\u6210\u5206\u306B\u306F\u540C\u3058\u5024\u304C\u5165\
    \u308B\u3002\n// [states, edges]\npair<vvc<int>, vc<pair<int, int>>> connedted_dp_graph(int\
    \ N, bool merge_reverse) {\n  HashMap<int> MP;\n  vvc<int> states;\n  vc<pair<int,\
    \ int>> edges;\n\n  states.eb(vc<int>(N, -1));\n  states.eb(vc<int>(N, -1));\n\
    \  MP[hash_vector<int>(states[0])] = 0;\n\n  int p = -1;\n  while (1) {\n    if\
    \ (++p == len(states)) break;\n    if (p == 1) {\n      edges.eb(1, 1);\n    \
    \  continue;\n    }\n    vc<int> now = states[p];\n    for (auto&& [nxt, convert]:\
    \ next_states(now)) {\n      // \u4ECA\u306E\u6210\u5206\u6570\u3001\u6D88\u3048\
    \u308B\u6210\u5206\u6570\n      int a = 0, b = 0;\n      FOR(v, N) if (now[v]\
    \ == v) {\n        ++a;\n        if (convert[v] == -1) ++b;\n      }\n      //\
    \ \u6D88\u3048\u308B\u6210\u5206\u304C\u3042\u3063\u3066\u3088\u3044\u306E\u306F\
    \u3001\u7D42\u72B6\u614B\u306B\u3044\u304F\u3068\u304D\u306E\u307F\n      if (b\
    \ >= 2) continue;\n      if (b == 1) {\n        if (MAX(nxt) != -1) continue;\n\
    \        edges.eb(p, 1);\n        continue;\n      }\n      u64 h = hash_vector<int>(nxt);\n\
    \      if (merge_reverse) { chmin(h, hash_vector<int>(reverse_state(nxt))); }\n\
    \      if (!MP.count(h)) { MP[h] = len(states), states.eb(nxt); }\n      edges.eb(p,\
    \ MP[h]);\n    }\n  }\n  return {states, edges};\n}\n\n// 0, 1 \uFF1A\u7A7A\u306E\
    \u5217\u3001\u9818\u57DF\u306E\u624B\u524D\u3001\u5F8C\u308D\n// \u591A\u89D2\u5F62\
    \uFF08\u7A7A\u6D1E\u306A\u3057\uFF09\u3092\u3072\u3068\u3064\u4F5C\u308B\u3002\
    \n// \u72B6\u614B\uFF1A-1 \u304C\u9078\u3093\u3067\u3044\u306A\u3044\u30020,1,2,3\
    \ \u7B49\u306F\u540C\u3058\u6210\u5206\u306B\u306F\u540C\u3058\u5024\u304C\u5165\
    \u308B\u3002\n// [states, edges]\npair<vvc<int>, vc<pair<int, int>>> polygon_dp_graph(int\
    \ N) {\n  HashMap<int> MP;\n  vvc<int> states;\n  vc<pair<int, int>> edges;\n\n\
    \  states.eb(vc<int>(N, -1));\n  states.eb(vc<int>(N, -1));\n  MP[hash_vector<int>(states[0])]\
    \ = 0;\n\n  int p = -1;\n  while (1) {\n    if (++p == len(states)) break;\n \
    \   if (p == 1) {\n      edges.eb(1, 1);\n      continue;\n    }\n    vc<int>\
    \ now = states[p];\n    for (auto&& [nxt, convert]: next_states(now)) {\n    \
    \  // \u4ECA\u306E\u6210\u5206\u6570\u3001\u6D88\u3048\u308B\u6210\u5206\u6570\
    \n      int a = 0, b = 0;\n      FOR(v, N) if (now[v] == v) {\n        ++a;\n\
    \        if (convert[v] == -1) ++b;\n      }\n      // \u6D88\u3048\u308B\u6210\
    \u5206\u304C\u3042\u3063\u3066\u3088\u3044\u306E\u306F\u3001\u7D42\u72B6\u614B\
    \u306B\u3044\u304F\u3068\u304D\u306E\u307F\n      if (b >= 2) continue;\n    \
    \  if (b == 1) {\n        if (MAX(nxt) != -1) continue;\n        edges.eb(p, 1);\n\
    \        continue;\n      }\n      bool ok = [&](vc<int>& now, vc<int>& nxt, vc<int>&\
    \ convert) -> bool {\n        // \u9802\u70B9\u306E\u307F\u3067\u63A5\u3059\u308B\
    \u306E\u306F\u30C0\u30E1\n        FOR(i, N - 1) {\n          bool a1 = now[i]\
    \ != -1, a2 = now[i + 1] != -1;\n          bool b1 = nxt[i] != -1, b2 = nxt[i\
    \ + 1] != -1;\n          if (a1 && !a2 && !b1 && b2) return false;\n         \
    \ if (!a1 && a2 && b1 && !b2) return false;\n        }\n        // empty region\
    \ \u3092\u9589\u3058\u308B\u3053\u3068\u3068\u3001\u7570\u306A\u308B\u9023\u7D50\
    \u6210\u5206\u304C\u30DE\u30FC\u30B8\u3055\u308C\u308B\u3053\u3068\u304C\u540C\
    \u5024\n        int close = 0;\n        int after = 0;\n        vc<bool> is_new(N,\
    \ 1);\n        FOR(i, N) if (convert[i] != -1) is_new[convert[i]] = 0;\n     \
    \   FOR(i, N) if (nxt[i] == i && !is_new[i])++ after;\n        vc<int> I;\n  \
    \      FOR(i, N) if (now[i] != -1) I.eb(i);\n        FOR(k, len(I) - 1) {\n  \
    \        int i = I[k], j = I[k + 1];\n          if (j == i + 1) continue;\n  \
    \        bool cl = 1;\n          FOR(p, i + 1, j) if (nxt[p] == -1) cl = 0;\n\
    \          if (cl) close++;\n        }\n        return a - close == after;\n \
    \     }(now, nxt, convert);\n      if (!ok) continue;\n      u64 h = hash_vector<int>(nxt);\n\
    \      if (!MP.count(h)) {\n        MP[h] = len(states);\n        states.eb(nxt);\n\
    \      }\n      edges.eb(p, MP[h]);\n    }\n  }\n  return {states, edges};\n}\n\
    } // namespace connected_dp_squares\n#line 8 \"test/1_mytest/tdpc_grid_dp.test.cpp\"\
    \n\nusing mint = modint107;\n\nmint calc_tdpc_grid(int H, int W) {\n  HashMap<int>\
    \ MP;\n\n  using P = pair<vc<int>, int>;\n  vc<P> states;\n\n  auto get_hash =\
    \ [&](vc<int> a, int b) -> ll {\n    a.eb(b);\n    return hash_vector<int>(a);\n\
    \  };\n\n  vc<int> init(H, -1);\n  init[0] = 0;\n  states.eb(init, 0);\n  vc<int>\
    \ end(H, -1);\n  end[H - 1] = H - 1;\n  states.eb(end, H - 1);\n  FOR(i, 2) {\n\
    \    auto [a, b] = states[i];\n    ll h = get_hash(a, b);\n    MP[h] = i;\n  }\n\
    \n  vc<pi> edges;\n\n  int p = -1;\n  while (1) {\n    ++p;\n    if (p >= len(states))\
    \ break;\n    auto [now, r] = states[p];\n    for (auto&& [nxt, convert]: connected_dp_squares::next_states(now))\
    \ {\n      int s = convert[r];\n      if (s == -1) continue;\n      ll h = get_hash(nxt,\
    \ s);\n      if (!MP.count(h)) {\n        MP[h] = len(states);\n        states.eb(nxt,\
    \ s);\n      }\n      edges.eb(p, MP[h]);\n    }\n  }\n\n  int S = len(states);\n\
    \  vc<mint> dp(S);\n  dp[0] = mint(1);\n  FOR(W + 1) {\n    vc<mint> newdp(S);\n\
    \    for (auto&& [a, b]: edges) newdp[b] += dp[a];\n    swap(dp, newdp);\n  }\n\
    \  return dp[1];\n}\n\nvoid test() {\n  assert(calc_tdpc_grid(2, 2).val == 3);\n\
    \  assert(calc_tdpc_grid(5, 8).val == 950397139);\n  assert(calc_tdpc_grid(8,\
    \ 5).val == 950397139);\n}\n\nvoid solve() {\n  int a, b;\n  cin >> a >> b;\n\
    \  cout << a + b << \"\\n\";\n}\n\nsigned main() {\n  test();\n  solve();\n  return\
    \ 0;\n}\n"
  code: "#define PROBLEM \"https://judge.yosupo.jp/problem/aplusb\"\n#include \"my_template.hpp\"\
    \n\n#include \"ds/hashmap.hpp\"\n#include \"random/hash_vector.hpp\"\n#include\
    \ \"mod/modint.hpp\"\n#include \"other/connected_dp.hpp\"\n\nusing mint = modint107;\n\
    \nmint calc_tdpc_grid(int H, int W) {\n  HashMap<int> MP;\n\n  using P = pair<vc<int>,\
    \ int>;\n  vc<P> states;\n\n  auto get_hash = [&](vc<int> a, int b) -> ll {\n\
    \    a.eb(b);\n    return hash_vector<int>(a);\n  };\n\n  vc<int> init(H, -1);\n\
    \  init[0] = 0;\n  states.eb(init, 0);\n  vc<int> end(H, -1);\n  end[H - 1] =\
    \ H - 1;\n  states.eb(end, H - 1);\n  FOR(i, 2) {\n    auto [a, b] = states[i];\n\
    \    ll h = get_hash(a, b);\n    MP[h] = i;\n  }\n\n  vc<pi> edges;\n\n  int p\
    \ = -1;\n  while (1) {\n    ++p;\n    if (p >= len(states)) break;\n    auto [now,\
    \ r] = states[p];\n    for (auto&& [nxt, convert]: connected_dp_squares::next_states(now))\
    \ {\n      int s = convert[r];\n      if (s == -1) continue;\n      ll h = get_hash(nxt,\
    \ s);\n      if (!MP.count(h)) {\n        MP[h] = len(states);\n        states.eb(nxt,\
    \ s);\n      }\n      edges.eb(p, MP[h]);\n    }\n  }\n\n  int S = len(states);\n\
    \  vc<mint> dp(S);\n  dp[0] = mint(1);\n  FOR(W + 1) {\n    vc<mint> newdp(S);\n\
    \    for (auto&& [a, b]: edges) newdp[b] += dp[a];\n    swap(dp, newdp);\n  }\n\
    \  return dp[1];\n}\n\nvoid test() {\n  assert(calc_tdpc_grid(2, 2).val == 3);\n\
    \  assert(calc_tdpc_grid(5, 8).val == 950397139);\n  assert(calc_tdpc_grid(8,\
    \ 5).val == 950397139);\n}\n\nvoid solve() {\n  int a, b;\n  cin >> a >> b;\n\
    \  cout << a + b << \"\\n\";\n}\n\nsigned main() {\n  test();\n  solve();\n  return\
    \ 0;\n}"
  dependsOn:
  - my_template.hpp
  - ds/hashmap.hpp
  - random/hash_vector.hpp
  - random/base.hpp
  - mod/modint61.hpp
  - mod/modint.hpp
  - mod/modint_common.hpp
  - other/connected_dp.hpp
  isVerificationFile: true
  path: test/1_mytest/tdpc_grid_dp.test.cpp
  requiredBy: []
  timestamp: '2024-09-28 04:06:11+09:00'
  verificationStatus: TEST_WRONG_ANSWER
  verifiedWith: []
documentation_of: test/1_mytest/tdpc_grid_dp.test.cpp
layout: document
redirect_from:
- /verify/test/1_mytest/tdpc_grid_dp.test.cpp
- /verify/test/1_mytest/tdpc_grid_dp.test.cpp.html
title: test/1_mytest/tdpc_grid_dp.test.cpp
---
