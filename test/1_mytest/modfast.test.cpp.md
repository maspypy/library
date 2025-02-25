---
data:
  _extendedDependsOn:
  - icon: ':question:'
    path: ds/hashmap.hpp
    title: ds/hashmap.hpp
  - icon: ':question:'
    path: mod/barrett.hpp
    title: mod/barrett.hpp
  - icon: ':question:'
    path: mod/mod_pow.hpp
    title: mod/mod_pow.hpp
  - icon: ':x:'
    path: mod/modfast.hpp
    title: mod/modfast.hpp
  - icon: ':question:'
    path: mod/mongomery_modint.hpp
    title: mod/mongomery_modint.hpp
  - icon: ':question:'
    path: mod/primitive_root.hpp
    title: mod/primitive_root.hpp
  - icon: ':question:'
    path: my_template.hpp
    title: my_template.hpp
  - icon: ':question:'
    path: nt/factor.hpp
    title: nt/factor.hpp
  - icon: ':question:'
    path: nt/lpf_table.hpp
    title: nt/lpf_table.hpp
  - icon: ':question:'
    path: nt/primetable.hpp
    title: nt/primetable.hpp
  - icon: ':question:'
    path: nt/primetest.hpp
    title: nt/primetest.hpp
  - icon: ':question:'
    path: random/base.hpp
    title: random/base.hpp
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
  bundledCode: "#line 1 \"test/1_mytest/modfast.test.cpp\"\n#define PROBLEM \"https://judge.yosupo.jp/problem/aplusb\"\
    \n#line 1 \"my_template.hpp\"\n#if defined(LOCAL)\n#include <my_template_compiled.hpp>\n\
    #else\n\n// https://codeforces.com/blog/entry/96344\n// https://codeforces.com/blog/entry/126772?#comment-1154880\n\
    #include <bits/allocator.h>\n#pragma GCC optimize(\"Ofast,unroll-loops\")\n#pragma\
    \ GCC target(\"avx2,popcnt\")\n#include <bits/stdc++.h>\n\nusing namespace std;\n\
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
    \n#define all(x) x.begin(), x.end()\n#define len(x) ll(x.size())\n#define elif\
    \ else if\n\n#define eb emplace_back\n#define mp make_pair\n#define mt make_tuple\n\
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
    \ x, int k) {\n  return x >> k & 1;\n}\n\ntemplate <typename UINT>\nstruct all_bit\
    \ {\n  struct iter {\n    UINT s;\n    iter(UINT s) : s(s) {}\n    int operator*()\
    \ const { return lowbit(s); }\n    iter &operator++() {\n      s &= s - 1;\n \
    \     return *this;\n    }\n    bool operator!=(const iter) const { return s !=\
    \ 0; }\n  };\n  UINT s;\n  all_bit(UINT s) : s(s) {}\n  iter begin() const { return\
    \ iter(s); }\n  iter end() const { return iter(0); }\n};\n\ntemplate <typename\
    \ UINT>\nstruct all_subset {\n  static_assert(is_unsigned<UINT>::value);\n  struct\
    \ iter {\n    UINT s, t;\n    bool ed;\n    iter(UINT s) : s(s), t(s), ed(0) {}\n\
    \    int operator*() const { return s ^ t; }\n    iter &operator++() {\n     \
    \ (t == 0 ? ed = 1 : t = (t - 1) & s);\n      return *this;\n    }\n    bool operator!=(const\
    \ iter) const { return !ed; }\n  };\n  UINT s;\n  all_subset(UINT s) : s(s) {}\n\
    \  iter begin() const { return iter(s); }\n  iter end() const { return iter(0);\
    \ }\n};\n\ntemplate <typename T>\nT floor(T a, T b) {\n  return a / b - (a % b\
    \ && (a ^ b) < 0);\n}\ntemplate <typename T>\nT ceil(T x, T y) {\n  return floor(x\
    \ + y - 1, y);\n}\ntemplate <typename T>\nT bmod(T x, T y) {\n  return x - y *\
    \ floor(x, y);\n}\ntemplate <typename T>\npair<T, T> divmod(T x, T y) {\n  T q\
    \ = floor(x, y);\n  return {q, x - q * y};\n}\n\ntemplate <typename T, typename\
    \ U>\nT SUM(const vector<U> &A) {\n  T sm = 0;\n  for (auto &&a: A) sm += a;\n\
    \  return sm;\n}\n\n#define MIN(v) *min_element(all(v))\n#define MAX(v) *max_element(all(v))\n\
    #define LB(c, x) distance((c).begin(), lower_bound(all(c), (x)))\n#define UB(c,\
    \ x) distance((c).begin(), upper_bound(all(c), (x)))\n#define UNIQUE(x) sort(all(x)),\
    \ x.erase(unique(all(x)), x.end()), x.shrink_to_fit()\n\ntemplate <typename T>\n\
    T POP(deque<T> &que) {\n  T a = que.front();\n  que.pop_front();\n  return a;\n\
    }\ntemplate <typename T>\nT POP(pq<T> &que) {\n  T a = que.top();\n  que.pop();\n\
    \  return a;\n}\ntemplate <typename T>\nT POP(pqg<T> &que) {\n  T a = que.top();\n\
    \  que.pop();\n  return a;\n}\ntemplate <typename T>\nT POP(vc<T> &que) {\n  T\
    \ a = que.back();\n  que.pop_back();\n  return a;\n}\n\ntemplate <typename F>\n\
    ll binary_search(F check, ll ok, ll ng, bool check_ok = true) {\n  if (check_ok)\
    \ assert(check(ok));\n  while (abs(ok - ng) > 1) {\n    auto x = (ng + ok) / 2;\n\
    \    (check(x) ? ok : ng) = x;\n  }\n  return ok;\n}\ntemplate <typename F>\n\
    double binary_search_real(F check, double ok, double ng, int iter = 100) {\n \
    \ FOR(iter) {\n    double x = (ok + ng) / 2;\n    (check(x) ? ok : ng) = x;\n\
    \  }\n  return (ok + ng) / 2;\n}\n\ntemplate <class T, class S>\ninline bool chmax(T\
    \ &a, const S &b) {\n  return (a < b ? a = b, 1 : 0);\n}\ntemplate <class T, class\
    \ S>\ninline bool chmin(T &a, const S &b) {\n  return (a > b ? a = b, 1 : 0);\n\
    }\n\n// ? \u306F -1\nvc<int> s_to_vi(const string &S, char first_char) {\n  vc<int>\
    \ A(S.size());\n  FOR(i, S.size()) { A[i] = (S[i] != '?' ? S[i] - first_char :\
    \ -1); }\n  return A;\n}\n\ntemplate <typename T, typename U>\nvector<T> cumsum(vector<U>\
    \ &A, int off = 1) {\n  int N = A.size();\n  vector<T> B(N + 1);\n  FOR(i, N)\
    \ { B[i + 1] = B[i] + A[i]; }\n  if (off == 0) B.erase(B.begin());\n  return B;\n\
    }\n\n// stable sort\ntemplate <typename T>\nvector<int> argsort(const vector<T>\
    \ &A) {\n  vector<int> ids(len(A));\n  iota(all(ids), 0);\n  sort(all(ids), [&](int\
    \ i, int j) { return (A[i] == A[j] ? i < j : A[i] < A[j]); });\n  return ids;\n\
    }\n\n// A[I[0]], A[I[1]], ...\ntemplate <typename T>\nvc<T> rearrange(const vc<T>\
    \ &A, const vc<int> &I) {\n  vc<T> B(len(I));\n  FOR(i, len(I)) B[i] = A[I[i]];\n\
    \  return B;\n}\n\ntemplate <typename T, typename... Vectors>\nvoid concat(vc<T>\
    \ &first, const Vectors &... others) {\n  vc<T> &res = first;\n  (res.insert(res.end(),\
    \ others.begin(), others.end()), ...);\n}\n#endif\n#line 3 \"test/1_mytest/modfast.test.cpp\"\
    \n\n#line 2 \"mod/primitive_root.hpp\"\n\r\n#line 2 \"nt/factor.hpp\"\n\n#line\
    \ 2 \"random/base.hpp\"\n\nu64 RNG_64() {\n  static u64 x_ = u64(chrono::duration_cast<chrono::nanoseconds>(chrono::high_resolution_clock::now().time_since_epoch()).count())\
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
    \n  if (mod == 1) return 0;\r\n  a = ((a %= mod) < 0 ? a + mod : a);\r\n  if ((mod\
    \ & 1) && (mod < (1 << 30))) {\r\n    using mint = Mongomery_modint_32<202311021>;\r\
    \n    mint::set_mod(mod);\r\n    return mint(a).pow(n).val();\r\n  }\r\n  Barrett\
    \ bt(mod);\r\n  int r = 1;\r\n  while (n) {\r\n    if (n & 1) r = bt.mul(r, a);\r\
    \n    a = bt.mul(a, a), n >>= 1;\r\n  }\r\n  return r;\r\n}\r\n\r\nu64 mod_pow_64(ll\
    \ a, ll n, u64 mod) {\r\n  assert(n >= 0);\r\n  if (mod == 1) return 0;\r\n  a\
    \ = ((a %= mod) < 0 ? a + mod : a);\r\n  if ((mod & 1) && (mod < (u64(1) << 62)))\
    \ {\r\n    using mint = Mongomery_modint_64<202311021>;\r\n    mint::set_mod(mod);\r\
    \n    return mint(a).pow(n).val();\r\n  }\r\n  Barrett_64 bt(mod);\r\n  ll r =\
    \ 1;\r\n  while (n) {\r\n    if (n & 1) r = bt.mul(r, a);\r\n    a = bt.mul(a,\
    \ a), n >>= 1;\r\n  }\r\n  return r;\r\n}\n#line 6 \"mod/primitive_root.hpp\"\n\
    \r\n// int\r\nint primitive_root(int p) {\r\n  auto pf = factor(p - 1);\r\n  auto\
    \ is_ok = [&](int g) -> bool {\r\n    for (auto&& [q, e]: pf)\r\n      if (mod_pow(g,\
    \ (p - 1) / q, p) == 1) return false;\r\n    return true;\r\n  };\r\n  while (1)\
    \ {\r\n    int x = RNG(1, p);\r\n    if (is_ok(x)) return x;\r\n  }\r\n  return\
    \ -1;\r\n}\r\n\r\nll primitive_root_64(ll p) {\r\n  auto pf = factor(p - 1);\r\
    \n  auto is_ok = [&](ll g) -> bool {\r\n    for (auto&& [q, e]: pf)\r\n      if\
    \ (mod_pow_64(g, (p - 1) / q, p) == 1) return false;\r\n    return true;\r\n \
    \ };\r\n  while (1) {\r\n    ll x = RNG(1, p);\r\n    if (is_ok(x)) return x;\r\
    \n  }\r\n  return -1;\r\n}\r\n\r\n// https://codeforces.com/contest/1190/problem/F\r\
    \nll primitive_root_prime_power_64(ll p, ll e) {\r\n  assert(p >= 3);\r\n  ll\
    \ g = primitive_root_64(p);\r\n  ll q = p;\r\n  ll phi = p - 1;\r\n  FOR(e - 1)\
    \ {\r\n    q *= p;\r\n    phi *= p;\r\n    if (mod_pow_64(g, phi / p, q) == 1)\
    \ g += q / p;\r\n  }\r\n  return g;\r\n}\r\n#line 2 \"nt/primetable.hpp\"\n\n\
    template <typename T = int>\nvc<T> primetable(int LIM) {\n  ++LIM;\n  const int\
    \ S = 32768;\n  static int done = 2;\n  static vc<T> primes = {2}, sieve(S + 1);\n\
    \n  if (done < LIM) {\n    done = LIM;\n\n    primes = {2}, sieve.assign(S + 1,\
    \ 0);\n    const int R = LIM / 2;\n    primes.reserve(int(LIM / log(LIM) * 1.1));\n\
    \    vc<pair<int, int>> cp;\n    for (int i = 3; i <= S; i += 2) {\n      if (!sieve[i])\
    \ {\n        cp.eb(i, i * i / 2);\n        for (int j = i * i; j <= S; j += 2\
    \ * i) sieve[j] = 1;\n      }\n    }\n    for (int L = 1; L <= R; L += S) {\n\
    \      array<bool, S> block{};\n      for (auto& [p, idx]: cp)\n        for (int\
    \ i = idx; i < S + L; idx = (i += p)) block[i - L] = 1;\n      FOR(i, min(S, R\
    \ - L)) if (!block[i]) primes.eb((L + i) * 2 + 1);\n    }\n  }\n  int k = LB(primes,\
    \ LIM + 1);\n  return {primes.begin(), primes.begin() + k};\n}\n#line 3 \"nt/lpf_table.hpp\"\
    \n\n// [0, LIM], 0, 1 \u306B\u306F -1 \u304C\u5165\u308B\u3002\nvc<int> lpf_table(ll\
    \ LIM) {\n  auto primes = primetable(LIM);\n  vc<int> res(LIM + 1, -1);\n  FOR_R(i,\
    \ len(primes)) {\n    auto p = primes[i];\n    FOR3(j, 1, LIM / p + 1) res[p *\
    \ j] = p;\n  }\n  return res;\n}\n#line 2 \"ds/hashmap.hpp\"\n\r\n// u64 -> Val\r\
    \ntemplate <typename Val>\r\nstruct HashMap {\r\n  // n \u306F\u5165\u308C\u305F\
    \u3044\u3082\u306E\u306E\u500B\u6570\u3067 ok\r\n  HashMap(u32 n = 0) { build(n);\
    \ }\r\n  void build(u32 n) {\r\n    u32 k = 8;\r\n    while (k < n * 2) k *= 2;\r\
    \n    cap = k / 2, mask = k - 1;\r\n    key.resize(k), val.resize(k), used.assign(k,\
    \ 0);\r\n  }\r\n\r\n  // size \u3092\u4FDD\u3063\u305F\u307E\u307E. size=0 \u306B\
    \u3059\u308B\u3068\u304D\u306F build \u3059\u308B\u3053\u3068.\r\n  void clear()\
    \ {\r\n    used.assign(len(used), 0);\r\n    cap = (mask + 1) / 2;\r\n  }\r\n\
    \  int size() { return len(used) / 2 - cap; }\r\n\r\n  int index(const u64& k)\
    \ {\r\n    int i = 0;\r\n    for (i = hash(k); used[i] && key[i] != k; i = (i\
    \ + 1) & mask) {}\r\n    return i;\r\n  }\r\n\r\n  Val& operator[](const u64&\
    \ k) {\r\n    if (cap == 0) extend();\r\n    int i = index(k);\r\n    if (!used[i])\
    \ { used[i] = 1, key[i] = k, val[i] = Val{}, --cap; }\r\n    return val[i];\r\n\
    \  }\r\n\r\n  Val get(const u64& k, Val default_value) {\r\n    int i = index(k);\r\
    \n    return (used[i] ? val[i] : default_value);\r\n  }\r\n\r\n  bool count(const\
    \ u64& k) {\r\n    int i = index(k);\r\n    return used[i] && key[i] == k;\r\n\
    \  }\r\n\r\n  // f(key, val)\r\n  template <typename F>\r\n  void enumerate_all(F\
    \ f) {\r\n    FOR(i, len(used)) if (used[i]) f(key[i], val[i]);\r\n  }\r\n\r\n\
    private:\r\n  u32 cap, mask;\r\n  vc<u64> key;\r\n  vc<Val> val;\r\n  vc<bool>\
    \ used;\r\n\r\n  u64 hash(u64 x) {\r\n    static const u64 FIXED_RANDOM = std::chrono::steady_clock::now().time_since_epoch().count();\r\
    \n    x += FIXED_RANDOM;\r\n    x = (x ^ (x >> 30)) * 0xbf58476d1ce4e5b9;\r\n\
    \    x = (x ^ (x >> 27)) * 0x94d049bb133111eb;\r\n    return (x ^ (x >> 31)) &\
    \ mask;\r\n  }\r\n\r\n  void extend() {\r\n    vc<pair<u64, Val>> dat;\r\n   \
    \ dat.reserve(len(used) / 2 - cap);\r\n    FOR(i, len(used)) {\r\n      if (used[i])\
    \ dat.eb(key[i], val[i]);\r\n    }\r\n    build(2 * len(dat));\r\n    for (auto&\
    \ [a, b]: dat) (*this)[a] = b;\r\n  }\r\n};\n#line 4 \"mod/modfast.hpp\"\n\ntemplate\
    \ <int p>\nstruct ModFast {\n  static_assert(p < (1 << 30));\n\n  u32 root;\n\
    \  array<u32, 65537> POW[2];\n  array<pair<u16, u16>, 1 + (1 << 20)> FRAC;\n\n\
    \  static constexpr int K = 1 << 21;\n  array<u32, 2 * K + 1> LOG;\n  array<u32,\
    \ 2 * K + 1> INV;\n\n  ModFast() {\n    root = (p == 998244353 ? 3 : primitive_root(p));\n\
    \    build_pow();\n    build_inv();\n    build_log();\n    build_frac();\n  }\n\
    \n  void build_inv() {\n    INV[K + 1] = 1;\n    for (u32 i = 2; i <= K; ++i)\
    \ {\n      u64 q = (p + i - 1) / i;\n      INV[K + i] = INV[K + i * q - p] * u64(q)\
    \ % p;\n    }\n    FOR(i, 1, K + 1) INV[K - i] = p - INV[K + i];\n  }\n\n  u32\
    \ pow(u32 a, ll exp) {\n    assert(0 <= a && a < p && 0 <= exp && exp < (1 <<\
    \ 30));\n    if (a == 0) return (exp == 0 ? 1 : 0);\n    return pow_r(log_r(a)\
    \ * exp % (p - 1));\n  }\n\n  u32 pow_r(u32 exp) {\n    assert(0 <= exp && exp\
    \ <= p - 1);\n    return u64(POW[0][exp & 32767]) * POW[1][exp >> 15] % p;\n \
    \ }\n\n  // [0, 2p-2)\n  u32 log_r(u32 x) {\n    assert(1 <= x && x < p);\n  \
    \  auto [a, b] = FRAC[x >> 10];\n    u32 t = x * b - a * p;\n    return LOG[K\
    \ + t] + (p - 1) - LOG[K + b];\n  }\n\n  u32 inverse(u32 x) {\n    assert(1 <=\
    \ x && x < p);\n    auto [a, b] = FRAC[x >> 10];\n    u32 t = x * b - a * p;\n\
    \    return INV[K + t] * u64(b) % p;\n  }\n\nprivate:\n  void build_pow() {\n\
    \    POW[0][0] = POW[1][0] = 1;\n    FOR(i, (1 << 15)) POW[0][i + 1] = POW[0][i]\
    \ * u64(root) % p;\n    FOR(i, (1 << 15)) POW[1][i + 1] = POW[1][i] * u64(POW[0][1\
    \ << 15]) % p;\n  }\n\n  // 0.17 sec. mod_log_998 \u3092 include \u3059\u308B\u3068\
    \ 0.1 sec.\n  void build_log() {\n#ifdef MOD_LOG_998\n    if (p == 998244353)\
    \ return build_log_998();\n#endif\n    const int LIM = 1 << 21;\n    auto lpf\
    \ = lpf_table(LIM);\n\n    const int S = 1 << 17;\n    HashMap<u32> MP(S);\n \
    \   u32 pw = 1;\n    for (int k = 0; k < S; ++k, pw = u64(root) * pw % p) { MP[pw]\
    \ = k; }\n    u32 q = pow_r(p - 1 - S);\n    auto BSGS = [&](u32 s) -> u32 {\n\
    \      u32 ans = 0;\n      while (1) {\n        u32 v = MP.get(s, -1);\n     \
    \   if (v != u32(-1)) { return ans + v; }\n        ans += S, s = u64(s) * q %\
    \ p;\n      }\n      return 0;\n    };\n\n    LOG[K + 1] = 0;\n    FOR(i, 2, 1\
    \ + (1 << 21)) {\n      if (lpf[i] < i) {\n        LOG[K + i] = (LOG[K + lpf[i]]\
    \ + LOG[K + i / lpf[i]]) % (p - 1);\n        continue;\n      }\n      if (i <\
    \ 100) {\n        LOG[K + i] = BSGS(i);\n        continue;\n      }\n      while\
    \ (1) {\n        u32 k = RNG(0, p - 1);\n        u64 ans = p - 1 - k;\n      \
    \  u32 x = u64(i) * pow_r(k) % p;\n        auto div = [&](u32 q) -> void { x /=\
    \ q, ans += LOG[K + q]; };\n        for (u32 q: {2, 3, 5, 7, 11, 13, 17, 19})\
    \ {\n          while (x % q == 0) div(q);\n        }\n        if (x >= LIM) continue;\n\
    \        while (i < x && x < LIM && lpf[x] < i) div(lpf[x]);\n        if (1 <\
    \ x && x < i) div(x);\n        if (x == 1) {\n          LOG[K + i] = ans % (p\
    \ - 1);\n          break;\n        }\n      }\n    }\n    FOR(i, 1, 1 + (1 <<\
    \ 21)) { LOG[K - i] = (LOG[K + i] + (p - 1) / 2) % (p - 1); }\n  }\n\n#ifdef MOD_LOG_998\n\
    \  void build_log_998() {\n    auto lpf = lpf_table(1 << 21);\n    LOG[K + 1]\
    \ = 0;\n    FOR(i, 2, 1 + (1 << 21)) { LOG[K + i] = (lpf[i] < i ? (LOG[K + lpf[i]]\
    \ + LOG[K + i / lpf[i]]) % (p - 1) : mod_log_998_primitive_root(i)); }\n    FOR(i,\
    \ 1, 1 + (1 << 21)) { LOG[K - i] = (LOG[K + i] + (p - 1) / 2) % (p - 1); }\n \
    \ }\n#endif\n\n  void build_frac() {\n    vc<tuple<u16, u16, u16, u16>> que;\n\
    \    que.eb(0, 1, 1, 1);\n    while (len(que)) {\n      auto [a, b, c, d] = POP(que);\n\
    \      if (b + d < 2048) {\n        que.eb(a + c, b + d, c, d), que.eb(a, b, a\
    \ + c, b + d);\n        continue;\n      }\n      u32 s = (u64(a) * p) / (1024\
    \ * b);\n      u32 t = (u64(c) * p) / (1024 * d);\n      FRAC[s] = {a, b}, FRAC[t]\
    \ = {c, d};\n      a = min(a, c), b = min(b, d);\n      FOR(i, s + 1, t) FRAC[i]\
    \ = {a, b};\n    }\n  }\n};\n#line 6 \"test/1_mytest/modfast.test.cpp\"\n\nusing\
    \ mint = modint998;\n\ntemplate <typename mint>\nvoid test() {\n  constexpr u32\
    \ mod = mint::get_mod();\n  ModFast<mod> fast;\n\n  FOR(1 << 20) {\n    mint x\
    \ = RNG(1, mod);\n    mint y = fast.inverse(x.val);\n    assert(x * y == 1);\n\
    \  }\n\n  FOR(1 << 20) {\n    mint x = RNG(1, mod);\n    int exp = RNG(0, mod);\n\
    \    mint y = fast.pow(x.val, exp);\n    assert(x.pow(exp) == y);\n  }\n}\n\n\
    void solve() {\n  int a, b;\n  cin >> a >> b;\n  cout << a + b << \"\\n\";\n}\n\
    \nsigned main() {\n  test<modint998>();\n  test<modint107>();\n  solve();\n}\n"
  code: "#define PROBLEM \"https://judge.yosupo.jp/problem/aplusb\"\n#include \"my_template.hpp\"\
    \n\n#include \"mod/modfast.hpp\"\n#include \"random/base.hpp\"\n\nusing mint =\
    \ modint998;\n\ntemplate <typename mint>\nvoid test() {\n  constexpr u32 mod =\
    \ mint::get_mod();\n  ModFast<mod> fast;\n\n  FOR(1 << 20) {\n    mint x = RNG(1,\
    \ mod);\n    mint y = fast.inverse(x.val);\n    assert(x * y == 1);\n  }\n\n \
    \ FOR(1 << 20) {\n    mint x = RNG(1, mod);\n    int exp = RNG(0, mod);\n    mint\
    \ y = fast.pow(x.val, exp);\n    assert(x.pow(exp) == y);\n  }\n}\n\nvoid solve()\
    \ {\n  int a, b;\n  cin >> a >> b;\n  cout << a + b << \"\\n\";\n}\n\nsigned main()\
    \ {\n  test<modint998>();\n  test<modint107>();\n  solve();\n}"
  dependsOn:
  - my_template.hpp
  - mod/modfast.hpp
  - mod/primitive_root.hpp
  - nt/factor.hpp
  - random/base.hpp
  - nt/primetest.hpp
  - mod/mongomery_modint.hpp
  - mod/mod_pow.hpp
  - mod/barrett.hpp
  - nt/lpf_table.hpp
  - nt/primetable.hpp
  - ds/hashmap.hpp
  isVerificationFile: true
  path: test/1_mytest/modfast.test.cpp
  requiredBy: []
  timestamp: '2025-02-26 02:14:25+09:00'
  verificationStatus: TEST_WRONG_ANSWER
  verifiedWith: []
documentation_of: test/1_mytest/modfast.test.cpp
layout: document
redirect_from:
- /verify/test/1_mytest/modfast.test.cpp
- /verify/test/1_mytest/modfast.test.cpp.html
title: test/1_mytest/modfast.test.cpp
---
