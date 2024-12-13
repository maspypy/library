---
data:
  _extendedDependsOn:
  - icon: ':question:'
    path: mod/barrett.hpp
    title: mod/barrett.hpp
  - icon: ':question:'
    path: mod/mod_pow.hpp
    title: mod/mod_pow.hpp
  - icon: ':question:'
    path: mod/mongomery_modint.hpp
    title: mod/mongomery_modint.hpp
  - icon: ':question:'
    path: my_template.hpp
    title: my_template.hpp
  - icon: ':question:'
    path: nt/factor.hpp
    title: nt/factor.hpp
  - icon: ':heavy_check_mark:'
    path: nt/four_square.hpp
    title: nt/four_square.hpp
  - icon: ':question:'
    path: nt/gaussian_integers.hpp
    title: nt/gaussian_integers.hpp
  - icon: ':question:'
    path: nt/primetest.hpp
    title: nt/primetest.hpp
  - icon: ':question:'
    path: nt/three_square.hpp
    title: nt/three_square.hpp
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
  bundledCode: "#line 1 \"test/1_mytest/four_square.test.cpp\"\n#define PROBLEM \"\
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
    \ return __builtin_popcountll(x); }\nint popcnt_sgn(int x) { return (__builtin_parity(unsigned(x))\
    \ & 1 ? -1 : 1); }\nint popcnt_sgn(u32 x) { return (__builtin_parity(x) & 1 ?\
    \ -1 : 1); }\nint popcnt_sgn(ll x) { return (__builtin_parityll(x) & 1 ? -1 :\
    \ 1); }\nint popcnt_sgn(u64 x) { return (__builtin_parityll(x) & 1 ? -1 : 1);\
    \ }\n// (0, 1, 2, 3, 4) -> (-1, 0, 1, 1, 2)\nint topbit(int x) { return (x ==\
    \ 0 ? -1 : 31 - __builtin_clz(x)); }\nint topbit(u32 x) { return (x == 0 ? -1\
    \ : 31 - __builtin_clz(x)); }\nint topbit(ll x) { return (x == 0 ? -1 : 63 - __builtin_clzll(x));\
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
    \ others.begin(), others.end()), ...);\n}\n#endif\n#line 3 \"test/1_mytest/four_square.test.cpp\"\
    \n\n#line 2 \"random/base.hpp\"\n\nu64 RNG_64() {\n  static u64 x_ = u64(chrono::duration_cast<chrono::nanoseconds>(chrono::high_resolution_clock::now().time_since_epoch()).count())\
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
    \n  }\r\n  return true;\r\n}\n#line 2 \"nt/factor.hpp\"\n\n#line 5 \"nt/factor.hpp\"\
    \n\ntemplate <typename mint>\nll rho(ll n, ll c) {\n  assert(n > 1);\n  const\
    \ mint cc(c);\n  auto f = [&](mint x) { return x * x + cc; };\n  mint x = 1, y\
    \ = 2, z = 1, q = 1;\n  ll g = 1;\n  const ll m = 1LL << (__lg(n) / 5);\n  for\
    \ (ll r = 1; g == 1; r <<= 1) {\n    x = y;\n    FOR(r) y = f(y);\n    for (ll\
    \ k = 0; k < r && g == 1; k += m) {\n      z = y;\n      FOR(min(m, r - k)) y\
    \ = f(y), q *= x - y;\n      g = gcd(q.val(), n);\n    }\n  }\n  if (g == n) do\
    \ {\n      z = f(z);\n      g = gcd((x - z).val(), n);\n    } while (g == 1);\n\
    \  return g;\n}\n\nll find_prime_factor(ll n) {\n  assert(n > 1);\n  if (primetest(n))\
    \ return n;\n  FOR(100) {\n    ll m = 0;\n    if (n < (1 << 30)) {\n      using\
    \ mint = Mongomery_modint_32<20231025>;\n      mint::set_mod(n);\n      m = rho<mint>(n,\
    \ RNG(0, n));\n    } else {\n      using mint = Mongomery_modint_64<20231025>;\n\
    \      mint::set_mod(n);\n      m = rho<mint>(n, RNG(0, n));\n    }\n    if (primetest(m))\
    \ return m;\n    n = m;\n  }\n  assert(0);\n  return -1;\n}\n\n// \u30BD\u30FC\
    \u30C8\u3057\u3066\u304F\u308C\u308B\nvc<pair<ll, int>> factor(ll n) {\n  assert(n\
    \ >= 1);\n  vc<pair<ll, int>> pf;\n  FOR(p, 2, 100) {\n    if (p * p > n) break;\n\
    \    if (n % p == 0) {\n      ll e = 0;\n      do { n /= p, e += 1; } while (n\
    \ % p == 0);\n      pf.eb(p, e);\n    }\n  }\n  while (n > 1) {\n    ll p = find_prime_factor(n);\n\
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
    \n    a = bt.mul(a, a), n >>= 1;\r\n  }\r\n  return r;\r\n}\n#line 3 \"nt/gaussian_integers.hpp\"\
    \n\r\ntemplate <typename T>\r\nstruct Gaussian_Integer {\r\n  T x, y;\r\n  using\
    \ G = Gaussian_Integer;\r\n\r\n  Gaussian_Integer(T x = 0, T y = 0) : x(x), y(y)\
    \ {}\r\n  Gaussian_Integer(pair<T, T> p) : x(p.fi), y(p.se) {}\r\n\r\n  T norm()\
    \ const { return x * x + y * y; }\r\n  G conjugate() const { return G(x, -y);\
    \ }\r\n\r\n  G &operator+=(const G &g) {\r\n    x += g.x, y += g.y;\r\n    return\
    \ *this;\r\n  }\r\n  G &operator-=(const G &g) {\r\n    x -= g.x, y -= g.y;\r\n\
    \    return *this;\r\n  }\r\n  G &operator*=(const G &g) {\r\n    tie(x, y) =\
    \ mp(x * g.x - y * g.y, x * g.y + y * g.x);\r\n    return *this;\r\n  }\r\n  G\
    \ &operator/=(const G &g) {\r\n    *this *= g.conjugate();\r\n    T n = g.norm();\r\
    \n    x = floor(x + n / 2, n);\r\n    y = floor(y + n / 2, n);\r\n    return *this;\r\
    \n  }\r\n  G &operator%=(const G &g) {\r\n    auto q = G(*this) / g;\r\n    q\
    \ *= g;\r\n    (*this) -= q;\r\n    return *this;\r\n  }\r\n  G operator-() {\
    \ return G(-x, -y); }\r\n  G operator+(const G &g) { return G(*this) += g; }\r\
    \n  G operator-(const G &g) { return G(*this) -= g; }\r\n  G operator*(const G\
    \ &g) { return G(*this) *= g; }\r\n  G operator/(const G &g) { return G(*this)\
    \ /= g; }\r\n  G operator%(const G &g) { return G(*this) %= g; }\r\n  bool operator==(const\
    \ G &g) { return (x == g.x && y == g.y); }\r\n\r\n  static G gcd(G a, G b) {\r\
    \n    while (b.x != 0 || b.y != 0) {\r\n      a %= b;\r\n      swap(a, b);\r\n\
    \    }\r\n    return a;\r\n  }\r\n\r\n  G pow(ll n) const {\r\n    assert(n >=\
    \ 0);\r\n    G ret(1), mul(*this);\r\n    while (n > 0) {\r\n      if (n & 1)\
    \ ret *= mul;\r\n      mul *= mul;\r\n      n >>= 1;\r\n    }\r\n    return ret;\r\
    \n  }\r\n\r\n  // (g,x,y) s.t ax+by=g\r\n  static tuple<G, G, G> extgcd(G a, G\
    \ b) {\r\n    if (b.x != 0 || b.y != 0) {\r\n      G q = a / b;\r\n      auto\
    \ [g, x, y] = extgcd(b, a - q * b);\r\n      return {g, y, x - q * y};\r\n   \
    \ }\r\n    return {a, G{1, 0}, G{0, 0}};\r\n  }\r\n};\r\n\r\npair<ll, ll> solve_norm_equation_prime(ll\
    \ p) {\r\n  using G = Gaussian_Integer<i128>;\r\n  assert(p == 2 || p % 4 == 1);\r\
    \n  if (p == 2) return {1, 1};\r\n  ll x = [&]() -> ll {\r\n    ll x = 1;\r\n\
    \    while (1) {\r\n      ++x;\r\n      ll pow_x = 1;\r\n      if (p < (1 << 30))\
    \ {\r\n        pow_x = mod_pow(x, (p - 1) / 4, p);\r\n        if (pow_x * pow_x\
    \ % p == p - 1) return pow_x;\r\n      } else {\r\n        pow_x = mod_pow_64(x,\
    \ (p - 1) / 4, p);\r\n        if (i128(pow_x) * pow_x % p == p - 1) return pow_x;\r\
    \n      }\r\n    }\r\n    return -1;\r\n  }();\r\n  G a(p, 0), b(x, 1);\r\n  a\
    \ = G::gcd(a, b);\r\n  assert(a.norm() == p);\r\n  return {a.x, a.y};\r\n}\r\n\
    \r\ntemplate <typename T>\r\nvc<Gaussian_Integer<T>> solve_norm_equation_factor(vc<pair<ll,\
    \ int>> pfs) {\r\n  using G = Gaussian_Integer<T>;\r\n  vc<G> res;\r\n  for (auto\
    \ &&[p, e]: pfs) {\r\n    if (p % 4 == 3 && e % 2 == 1) return {};\r\n  }\r\n\r\
    \n  res.eb(G(1, 0));\r\n  for (auto &&[p, e]: pfs) {\r\n    if (p % 4 == 3) {\r\
    \n      T pp = 1;\r\n      FOR(e / 2) pp *= p;\r\n      for (auto &&g: res) {\r\
    \n        g.x *= pp;\r\n        g.y *= pp;\r\n      }\r\n      continue;\r\n \
    \   }\r\n    auto [pix, piy] = solve_norm_equation_prime(p);\r\n    G pi(pix,\
    \ piy);\r\n    vc<G> pows(e + 1);\r\n    pows[0] = G(1, 0);\r\n    FOR(i, e) pows[i\
    \ + 1] = pows[i] * pi;\r\n    if (p == 2) {\r\n      for (auto &&g: res) g *=\
    \ pows[e];\r\n      continue;\r\n    }\r\n    vc<G> pis(e + 1);\r\n    FOR(j,\
    \ e + 1) { pis[j] = pows[j] * (pows[e - j].conjugate()); }\r\n    vc<G> new_res;\r\
    \n    new_res.reserve(len(res) * (e + 1));\r\n    for (auto &&g: res) {\r\n  \
    \    for (auto &&a: pis) { new_res.eb(g * a); }\r\n    }\r\n    swap(res, new_res);\r\
    \n  }\r\n\r\n  for (auto &&g: res) {\r\n    while (g.x <= 0 || g.y < 0) { g =\
    \ G(-g.y, g.x); }\r\n  }\r\n  return res;\r\n}\r\n\r\n// i128 \u3092\u4F7F\u3046\
    \u3068 N <= 10^{18} \u3082\u3067\u304D\u308B\r\n// \u30CE\u30EB\u30E0\u304C\u3068\
    \u308C\u308B\u3088\u3046\u306B\u30012 \u4E57\u3057\u3066\u3082\u30AA\u30FC\u30D0\
    \u30FC\u30D5\u30ED\u30FC\u3057\u306A\u3044\u578B\u3092\u4F7F\u304A\u3046\r\n//\
    \ 0 <= arg < 90 \u3068\u306A\u308B\u3082\u306E\u306E\u307F\u8FD4\u3059\u3002\r\
    \n// \u5358\u6570\u500D\u306F\u4F5C\u3089\u306A\u3044\u306E\u3067\u3001\u4F7F\u3046\
    \u3068\u304D\u306B\u6C17\u3092\u4ED8\u3051\u308B\u3002\r\ntemplate <typename T>\r\
    \nvc<Gaussian_Integer<T>> solve_norm_equation(T N) {\r\n  using G = Gaussian_Integer<T>;\r\
    \n  vc<G> res;\r\n  if (N < 0) return {};\r\n  if (N == 0) {\r\n    res.eb(G(0,\
    \ 0));\r\n    return res;\r\n  }\r\n  auto pfs = factor(N);\r\n  return solve_norm_equation_factor<T>(pfs);\r\
    \n}\r\n#line 3 \"nt/three_square.hpp\"\n\n// https://math.stackexchange.com/questions/483101/rabin-and-shallit-algorithm\n\
    // ERH \u306E\u3082\u3068 O(log^2N) \uFF1F\ntuple<ll, ll, ll> three_square(ll\
    \ N) {\n  if (N == 0) return {0, 0, 0};\n  auto F = [&](ll n) -> tuple<ll, ll,\
    \ ll> {\n    if (N == 2) return {1, 1, 0};\n    if (N == 3) return {1, 1, 1};\n\
    \    if (N == 10) return {3, 1, 0};\n    if (N == 34) return {5, 3, 0};\n    if\
    \ (N == 58) return {7, 3, 0};\n    if (N == 85) return {9, 2, 0};\n    if (N ==\
    \ 130) return {11, 3, 0};\n    if (N == 214) return {14, 3, 3};\n    if (N ==\
    \ 226) return {15, 1, 0};\n    if (N == 370) return {19, 3, 0};\n    if (N ==\
    \ 526) return {21, 9, 2};\n    if (N == 706) return {25, 9, 0};\n    if (N ==\
    \ 730) return {27, 1, 0};\n    if (N == 1414) return {33, 18, 1};\n    if (N ==\
    \ 1906) return {41, 15, 0};\n    if (N == 2986) return {45, 31, 0};\n    if (N\
    \ == 9634) return {97, 15, 0};\n    ll x = sqrtl(N);\n    if (N == x * x) return\
    \ {x, 0, 0};\n    if (N % 4 != 1 && x % 2 == 0) --x;\n    if (N % 4 == 1 && x\
    \ % 2 == 1) --x;\n    x += 2;\n    while (1) {\n      x -= 2;\n      ll k = N\
    \ - x * x;\n      if (k < 0) break;\n      if (k % 2 == 1 && primetest(k)) {\n\
    \        auto [a, b] = solve_norm_equation_prime(k);\n        a = abs(a), b =\
    \ abs(b);\n        return {a, b, x};\n      }\n      if (k % 2 == 0 && primetest(k\
    \ / 2)) {\n        auto [a, b] = solve_norm_equation_prime(k / 2);\n        tie(a,\
    \ b) = mp(a + b, a - b);\n        a = abs(a), b = abs(b);\n        return {a,\
    \ b, x};\n      }\n    }\n    assert(0);\n    return {-1, -1, -1};\n  };\n  ll\
    \ e = 0;\n  while (N % 4 == 0) N /= 4, ++e;\n  if (N % 8 == 7) return {-1, -1,\
    \ -1};\n  auto [a, b, c] = F(N);\n  return {a << e, b << e, c << e};\n}\n#line\
    \ 2 \"nt/four_square.hpp\"\n\ntuple<ll, ll, ll, ll> four_square(ll N) {\n  if\
    \ (N == 0) return {0, 0, 0, 0};\n  ll e = 0;\n  while (N % 4 == 0) N /= 4, ++e;\n\
    \  auto [a, b, c] = three_square(N);\n  if (a != -1) return {a << e, b << e, c\
    \ << e, 0};\n  tie(a, b, c) = three_square(N - 1);\n  return {a << e, b << e,\
    \ c << e, 1LL << e};\n}\n#line 6 \"test/1_mytest/four_square.test.cpp\"\n\nvoid\
    \ test() {\n  FOR(N, 1000000) {\n    auto [a, b, c, d] = four_square(N);\n   \
    \ assert(N == a * a + b * b + c * c + d * d);\n  }\n  vi TEN = {1};\n  FOR(18)\
    \ TEN.eb(TEN.back() * 10);\n  FOR(100000) {\n    ll K = RNG(0, 18);\n    ll N\
    \ = RNG(TEN[K], TEN[K + 1]);\n    auto [a, b, c, d] = four_square(N);\n    assert(N\
    \ == a * a + b * b + c * c + d * d);\n  }\n}\n\nvoid solve() {\n  int a, b;\n\
    \  cin >> a >> b;\n  cout << a + b << \"\\n\";\n}\n\nsigned main() {\n  test();\n\
    \  solve();\n\n  return 0;\n}\n"
  code: "#define PROBLEM \"https://judge.yosupo.jp/problem/aplusb\"\n#include \"my_template.hpp\"\
    \n\n#include \"random/base.hpp\"\n#include \"nt/four_square.hpp\"\n\nvoid test()\
    \ {\n  FOR(N, 1000000) {\n    auto [a, b, c, d] = four_square(N);\n    assert(N\
    \ == a * a + b * b + c * c + d * d);\n  }\n  vi TEN = {1};\n  FOR(18) TEN.eb(TEN.back()\
    \ * 10);\n  FOR(100000) {\n    ll K = RNG(0, 18);\n    ll N = RNG(TEN[K], TEN[K\
    \ + 1]);\n    auto [a, b, c, d] = four_square(N);\n    assert(N == a * a + b *\
    \ b + c * c + d * d);\n  }\n}\n\nvoid solve() {\n  int a, b;\n  cin >> a >> b;\n\
    \  cout << a + b << \"\\n\";\n}\n\nsigned main() {\n  test();\n  solve();\n\n\
    \  return 0;\n}"
  dependsOn:
  - my_template.hpp
  - random/base.hpp
  - nt/four_square.hpp
  - nt/three_square.hpp
  - nt/primetest.hpp
  - mod/mongomery_modint.hpp
  - nt/gaussian_integers.hpp
  - nt/factor.hpp
  - mod/mod_pow.hpp
  - mod/barrett.hpp
  isVerificationFile: true
  path: test/1_mytest/four_square.test.cpp
  requiredBy: []
  timestamp: '2024-12-13 13:55:16+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: test/1_mytest/four_square.test.cpp
layout: document
redirect_from:
- /verify/test/1_mytest/four_square.test.cpp
- /verify/test/1_mytest/four_square.test.cpp.html
title: test/1_mytest/four_square.test.cpp
---
