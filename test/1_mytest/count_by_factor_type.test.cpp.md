---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: mod/montgomery_modint.hpp
    title: mod/montgomery_modint.hpp
  - icon: ':heavy_check_mark:'
    path: my_template.hpp
    title: my_template.hpp
  - icon: ':heavy_check_mark:'
    path: nt/count_by_factor_type.hpp
    title: nt/count_by_factor_type.hpp
  - icon: ':heavy_check_mark:'
    path: nt/factor.hpp
    title: nt/factor.hpp
  - icon: ':heavy_check_mark:'
    path: nt/is_prime.hpp
    title: nt/is_prime.hpp
  - icon: ':heavy_check_mark:'
    path: nt/prime_sum.hpp
    title: nt/prime_sum.hpp
  - icon: ':heavy_check_mark:'
    path: nt/prime_table.hpp
    title: nt/prime_table.hpp
  - icon: ':heavy_check_mark:'
    path: other/bit.hpp
    title: other/bit.hpp
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
  bundledCode: "#line 1 \"test/1_mytest/count_by_factor_type.test.cpp\"\n#define PROBLEM\
    \ \"https://judge.yosupo.jp/problem/aplusb\"\n#line 1 \"my_template.hpp\"\n#if\
    \ defined(USE_PCH)\n#include <my_template_compiled.hpp>\n#else\n#if defined(__GNUC__)\n\
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
    template <>\nconstexpr double infty<double> = infty<i128>;\ntemplate <>\nconstexpr\
    \ long double infty<long double> = infty<i128>;\n\nusing pi = pair<ll, ll>;\n\
    using vi = vector<ll>;\ntemplate <class T>\nusing vc = vector<T>;\ntemplate <class\
    \ T>\nusing vvc = vector<vc<T>>;\ntemplate <class T>\nusing vvvc = vector<vvc<T>>;\n\
    template <class T>\nusing vvvvc = vector<vvvc<T>>;\ntemplate <class T>\nusing\
    \ pq_max = priority_queue<T>;\ntemplate <class T>\nusing pq_min = priority_queue<T,\
    \ vector<T>, greater<T>>;\n\n#define vv(type, name, h, ...) \\\n  vector<vector<type>>\
    \ name(h, vector<type>(__VA_ARGS__))\n#define vvv(type, name, h, w, ...)   \\\n\
    \  vector<vector<vector<type>>> name( \\\n      h, vector<vector<type>>(w, vector<type>(__VA_ARGS__)))\n\
    #define vvvv(type, name, a, b, c, ...)       \\\n  vector<vector<vector<vector<type>>>>\
    \ name( \\\n      a, vector<vector<vector<type>>>(       \\\n             b, vector<vector<type>>(c,\
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
    \  return a;\n}\n\ntemplate <typename F>\ni128 binary_search(F check, i128 ok,\
    \ i128 ng, bool check_ok = true) {\n  if (check_ok) assert(check(ok));\n  while\
    \ (1) {\n    i128 x = (ok + ng) / 2;\n    if (x == ok || x == ng) break;\n   \
    \ (check(x) ? ok : ng) = x;\n  }\n  return ok;\n}\n\ntemplate <typename F>\ndouble\
    \ binary_search_real(F check, double ok, double ng, int iter = 100) {\n  FOR(iter)\
    \ {\n    double x = (ok + ng) / 2;\n    (check(x) ? ok : ng) = x;\n  }\n  return\
    \ (ok + ng) / 2;\n}\n\ntemplate <class T, class S>\ninline bool chmax(T &a, const\
    \ S &b) {\n  T c = max<T>(a, b);\n  bool changed = (c != a);\n  a = c;\n  return\
    \ changed;\n}\ntemplate <class T, class S>\ninline bool chmin(T &a, const S &b)\
    \ {\n  T c = min<T>(a, b);\n  bool changed = (c != a);\n  a = c;\n  return changed;\n\
    }\n\n// ? \u306F -1\nvc<int> s_to_vi(const string &S, char first_char) {\n  vc<int>\
    \ A(S.size());\n  FOR(i, S.size()) { A[i] = (S[i] != '?' ? S[i] - first_char :\
    \ -1); }\n  return A;\n}\n\ntemplate <typename T, typename U>\nvc<T> cumsum(const\
    \ vc<U> &A, int off = 1) {\n  int N = A.size();\n  vc<T> B(N + 1);\n  FOR(i, N)\
    \ { B[i + 1] = B[i] + A[i]; }\n  if (off == 0) B.erase(B.begin());\n  return B;\n\
    }\n\n// stable sort\ntemplate <typename T>\nvc<int> argsort(const vc<T> &A) {\n\
    \  vc<int> ids(len(A));\n  iota(all(ids), 0);\n  sort(all(ids),\n      [&](int\
    \ i, int j) { return (A[i] == A[j] ? i < j : A[i] < A[j]); });\n  return ids;\n\
    }\n\n// A[I[0]], A[I[1]], ...\ntemplate <typename T>\nvc<T> rearrange(const vc<T>\
    \ &A, const vc<int> &I) {\n  vc<T> B(len(I));\n  FOR(i, len(I)) B[i] = A[I[i]];\n\
    \  return B;\n}\n\ntemplate <typename T, typename... Vectors>\nvoid concat(vc<T>\
    \ &first, const Vectors &...others) {\n  first.reserve(first.size() + (others.size()\
    \ + ... + 0));\n  (first.insert(first.end(), others.begin(), others.end()), ...);\n\
    }\n\n// i128\ntemplate <class T, enable_if_t<is_same_v<T, i128>, int> = 0>\nconstexpr\
    \ i128 abs(T x) {\n  return x < 0 ? -x : x;\n}\n\nconstexpr i128 gcd(i128 a, i128\
    \ b) {\n  while (b != 0) {\n    i128 c = a % b;\n    a = b, b = c;\n  }\n  return\
    \ abs(a);\n}\n#endif\n#line 3 \"test/1_mytest/count_by_factor_type.test.cpp\"\n\
    \n#line 1 \"nt/prime_table.hpp\"\n\ntemplate <typename T = int>\nvc<T> prime_table(int\
    \ LIM) {\n  ++LIM;\n  const int S = 32768;\n  static int done = 2;\n  static vc<T>\
    \ primes = {2}, sieve(S + 1);\n\n  if (done < LIM) {\n    done = LIM;\n\n    primes\
    \ = {2}, sieve.assign(S + 1, 0);\n    const int R = LIM / 2;\n    primes.reserve(int(LIM\
    \ / log(LIM) * 1.1));\n    vc<pair<int, int>> cp;\n    for (int i = 3; i <= S;\
    \ i += 2) {\n      if (!sieve[i]) {\n        cp.eb(i, i * i / 2);\n        for\
    \ (int j = i * i; j <= S; j += 2 * i) sieve[j] = 1;\n      }\n    }\n    for (int\
    \ L = 1; L <= R; L += S) {\n      array<bool, S> block{};\n      for (auto& [p,\
    \ idx] : cp)\n        for (int i = idx; i < S + L; idx = (i += p)) block[i - L]\
    \ = 1;\n      FOR(i, min(S, R - L)) if (!block[i]) primes.eb((L + i) * 2 + 1);\n\
    \    }\n  }\n  int k = LB(primes, LIM);\n  return {primes.begin(), primes.begin()\
    \ + k};\n}\n#line 1 \"nt/prime_table.hpp\"\n\ntemplate <typename T = int>\nvc<T>\
    \ prime_table(int LIM) {\n  ++LIM;\n  const int S = 32768;\n  static int done\
    \ = 2;\n  static vc<T> primes = {2}, sieve(S + 1);\n\n  if (done < LIM) {\n  \
    \  done = LIM;\n\n    primes = {2}, sieve.assign(S + 1, 0);\n    const int R =\
    \ LIM / 2;\n    primes.reserve(int(LIM / log(LIM) * 1.1));\n    vc<pair<int, int>>\
    \ cp;\n    for (int i = 3; i <= S; i += 2) {\n      if (!sieve[i]) {\n       \
    \ cp.eb(i, i * i / 2);\n        for (int j = i * i; j <= S; j += 2 * i) sieve[j]\
    \ = 1;\n      }\n    }\n    for (int L = 1; L <= R; L += S) {\n      array<bool,\
    \ S> block{};\n      for (auto& [p, idx] : cp)\n        for (int i = idx; i <\
    \ S + L; idx = (i += p)) block[i - L] = 1;\n      FOR(i, min(S, R - L)) if (!block[i])\
    \ primes.eb((L + i) * 2 + 1);\n    }\n  }\n  int k = LB(primes, LIM);\n  return\
    \ {primes.begin(), primes.begin() + k};\n}\n#line 2 \"nt/prime_sum.hpp\"\n\n/*\n\
    N \u3068\u5B8C\u5168\u4E57\u6CD5\u7684\u95A2\u6570 f \u306E prefix sum \u95A2\u6570\
    \ F \u3092\u4E0E\u3048\u308B\u3002\nn = floor(N/d) \u3068\u306A\u308B n \u306B\
    \u5BFE\u3059\u308B sum_{p <= n} f(p) \u3092\u8A08\u7B97\u3059\u308B\u3002\n\u7279\
    \u306B\u3001\u7D20\u6570\u306E k \u4E57\u548C\u3084\u3001mod m \u3054\u3068\u3067\
    \u306E\u7D20\u6570\u306E k \u4E57\u548C\u304C\u8A08\u7B97\u3067\u304D\u308B\u3002\
    \nComplexity: O(N^{3/4}/logN) time, O(N^{1/2}) space.\n*/\ntemplate <typename\
    \ T>\nstruct Prime_Sum {\n  ll N;\n  ll sqN;\n  vc<T> sum_lo, sum_hi;\n  bool\
    \ calculated;\n\n  Prime_Sum(ll N) : N(N), sqN(sqrtl(N)), calculated(0) {}\n\n\
    \  // [1, x] \u305F\u3060\u3057\u3001x = floor(N, i) \u306E\u5F62\n  T operator[](ll\
    \ x) {\n    assert(calculated);\n    return (x <= sqN ? sum_lo[x] : sum_hi[double(N)\
    \ / x]);\n  }\n\n  template <typename F>\n  void calc(const F f) {\n    auto primes\
    \ = prime_table<int>(sqN);\n    sum_lo.resize(sqN + 1);\n    sum_hi.resize(sqN\
    \ + 1);\n    FOR(i, 1, sqN + 1) sum_lo[i] = f(i) - 1;\n    FOR(i, 1, sqN + 1)\
    \ sum_hi[i] = f(double(N) / i) - 1;\n    for (int p : primes) {\n      ll pp =\
    \ ll(p) * p;\n      if (pp > N) break;\n      int R = min(sqN, N / pp);\n    \
    \  int M = sqN / p;\n      T x = sum_lo[p - 1];\n      T fp = sum_lo[p] - sum_lo[p\
    \ - 1];\n      for (int i = 1; i <= M; ++i) sum_hi[i] -= fp * (sum_hi[i * p] -\
    \ x);\n      for (int i = M + 1; i <= R; ++i)\n        sum_hi[i] -= fp * (sum_lo[N\
    \ / (double(i) * p)] - x);\n      for (int n = sqN; n >= pp; --n) sum_lo[n] -=\
    \ fp * (sum_lo[n / p] - x);\n    }\n    calculated = 1;\n  }\n\n  void calc_count()\
    \ {\n    calc([](ll x) -> T { return x; });\n  }\n\n  void calc_sum() {\n    calc([](ll\
    \ x) -> T {\n      ll a = x, b = x + 1;\n      if (!(x & 1)) a /= 2;\n      if\
    \ (x & 1) b /= 2;\n      return T(a) * T(b);\n    });\n  }\n};\n#line 3 \"nt/count_by_factor_type.hpp\"\
    \n\n// factor type: \u964D\u9806 270 -> (3,1,1)\n// N=10^9: 1324 \u7A2E\u985E\
    , 0.4sec\n// https://atcoder.jp/contests/xmascon20/tasks/xmascon20_d\nmap<vc<int>,\
    \ ll> count_by_factor_type(ll N) {\n  ll sqN = sqrtl(N);\n  auto P = prime_table<int>(sqN);\n\
    \  Prime_Sum<ll> X(N);\n  X.calc_count();\n\n  // 1 and prime\n  map<vc<int>,\
    \ ll> ANS;\n  ANS[vc<int>()] = 1;\n  if (X[N] > 0) ANS[vc<int>({1})] = X[N];\n\
    \n  auto add = [&](vc<int> F, int k) -> vc<int> {\n    int p = len(F);\n    F.eb(k);\n\
    \    while (0 < p && F[p - 1] < F[p]) {\n      swap(F[p - 1], F[p]), --p;\n  \
    \  }\n    return F;\n  };\n\n  // t = up_i^k \u306E\u3068\u304D\u306B\n  auto\
    \ dfs = [&](auto& dfs, ll t, ll i, ll k, vc<int> U) -> void {\n    // U * primes\
    \ \u3092\u8FFD\u52A0\u3059\u308B\n    vc<int> nxt1 = add(U, k + 1);\n    ANS[nxt1]++;\n\
    \    vc<int> Uk = add(U, k);\n    vc<int> nxt2 = add(Uk, 1);\n    ll cnt = X[N\
    \ / t] - X[P[i]];\n    if (cnt > 0) ANS[nxt2] += X[N / t] - X[P[i]];\n    ll lim\
    \ = sqrtl(double(N) / t);\n    if (P[i] <= lim) {\n      dfs(dfs, t * P[i], i,\
    \ k + 1, U);\n    }\n    FOR(j, i + 1, len(P)) {\n      if (P[j] > lim) break;\n\
    \      dfs(dfs, t * P[j], j, 1, Uk);\n    }\n  };\n  FOR(i, len(P)) if (P[i] <=\
    \ sqN) dfs(dfs, P[i], i, 1, {});\n  return ANS;\n}\n#line 1 \"nt/factor.hpp\"\n\
    \n#line 1 \"random/base.hpp\"\n\nu64 RNG_64() {\n  static u64 x_ = u64(chrono::duration_cast<chrono::nanoseconds>(\n\
    \                      chrono::high_resolution_clock::now().time_since_epoch())\n\
    \                          .count()) *\n                  10150724397891781847ULL;\n\
    \  x_ ^= x_ << 7;\n  return x_ ^= x_ >> 9;\n}\n\nu64 RNG(u64 lim) {\n  assert(lim\
    \ > 0);\n  return RNG_64() % lim;\n}\n\nll RNG(ll l, ll r) {\n  assert(l < r);\n\
    \  return l + RNG_64() % (r - l);\n}\n#line 1 \"other/bit.hpp\"\n\nint popcnt(int\
    \ x) { return __builtin_popcount(x); }\nint popcnt(u32 x) { return __builtin_popcount(x);\
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
    T kth_bit(int k) {\n  assert(0 <= k && k < int(8 * sizeof(T)));\n  return T(1)\
    \ << k;\n}\ntemplate <typename T>\nbool has_kth_bit(T x, int k) {\n  assert(0\
    \ <= k && k < int(8 * sizeof(T)));\n  return x >> k & 1;\n}\n\ntemplate <typename\
    \ UINT>\nstruct all_bit {\n  static_assert(is_unsigned<UINT>::value);\n  UINT\
    \ s;\n  all_bit(UINT s) : s(s) {}\n  struct iter {\n    UINT s;\n    int operator*()\
    \ const { return lowbit(s); }\n    void operator++() { s &= s - 1; }\n    bool\
    \ operator!=(nullptr_t) const { return s; }\n  };\n  iter begin() const { return\
    \ {s}; }\n  nullptr_t end() const { return nullptr; }\n};\n\ntemplate <typename\
    \ UINT>\nstruct all_subset {\n  static_assert(is_unsigned<UINT>::value);\n  UINT\
    \ s;\n  all_subset(UINT s) : s(s) {}\n  struct iter {\n    UINT s, t;\n    bool\
    \ done = false;\n    UINT operator*() const { return t; }\n    void operator++()\
    \ {\n      done = (t == 0);\n      t = (t - 1) & s;\n    }\n    bool operator!=(nullptr_t)\
    \ const { return !done; }\n  };\n  iter begin() const { return {s, s}; }\n  nullptr_t\
    \ end() const { return nullptr; }\n};\n\nconstexpr u64 full_mask(int n) {\n  assert(0\
    \ <= n && n <= 64);\n  return n == 64 ? -1ULL : (1ULL << n) - 1;\n}\n\nu64 bit_reverse(u64\
    \ x) {\n  x = ((x & 0x5555555555555555ULL) << 1) | ((x >> 1) & 0x5555555555555555ULL);\n\
    \  x = ((x & 0x3333333333333333ULL) << 2) | ((x >> 2) & 0x3333333333333333ULL);\n\
    \  x = ((x & 0x0f0f0f0f0f0f0f0fULL) << 4) | ((x >> 4) & 0x0f0f0f0f0f0f0f0fULL);\n\
    \  x = ((x & 0x00ff00ff00ff00ffULL) << 8) | ((x >> 8) & 0x00ff00ff00ff00ffULL);\n\
    \  x = ((x & 0x0000ffff0000ffffULL) << 16) | ((x >> 16) & 0x0000ffff0000ffffULL);\n\
    \  x = (x << 32) | (x >> 32);\n  return x;\n}\n#line 1 \"mod/montgomery_modint.hpp\"\
    \n\n// odd mod.\n// x \u306E\u4EE3\u308F\u308A\u306B rx \u3092\u6301\u3064\ntemplate\
    \ <int id, typename U1, typename U2>\nstruct Montgomery_modint {\n  using mint\
    \ = Montgomery_modint;\n  inline static U1 m, r, n2;\n  static constexpr int W\
    \ = numeric_limits<U1>::digits;\n\n  static void set_mod(U1 mod) {\n    assert(mod\
    \ & 1 && mod <= U1(1) << (W - 2));\n    m = mod, n2 = -U2(m) % m, r = m;\n   \
    \ FOR(6) r *= 2 - m * r;\n    r = -r;\n    assert(r * m == U1(-1));\n  }\n  static\
    \ U1 reduce(U2 b) { return (b + U2(U1(b) * r) * m) >> W; }\n\n  U1 x;\n  Montgomery_modint()\
    \ : x(0) {}\n  Montgomery_modint(U1 x) : x(reduce(U2(x) * n2)){};\n  U1 val()\
    \ const {\n    U1 y = reduce(x);\n    return y >= m ? y - m : y;\n  }\n  mint\
    \ &operator+=(mint y) {\n    x = ((x += y.x) >= m ? x - m : x);\n    return *this;\n\
    \  }\n  mint &operator-=(mint y) {\n    x -= (x >= y.x ? y.x : y.x - m);\n   \
    \ return *this;\n  }\n  mint &operator*=(mint y) {\n    x = reduce(U2(x) * y.x);\n\
    \    return *this;\n  }\n  mint operator+(mint y) const { return mint(*this) +=\
    \ y; }\n  mint operator-(mint y) const { return mint(*this) -= y; }\n  mint operator*(mint\
    \ y) const { return mint(*this) *= y; }\n  bool operator==(mint y) const {\n \
    \   return (x >= m ? x - m : x) == (y.x >= m ? y.x - m : y.x);\n  }\n  bool operator!=(mint\
    \ y) const { return not operator==(y); }\n  mint pow(ll n) const {\n    assert(n\
    \ >= 0);\n    mint y = 1, z = *this;\n    for (; n; n >>= 1, z *= z)\n      if\
    \ (n & 1) y *= z;\n    return y;\n  }\n};\n\ntemplate <int id>\nusing Montgomery_modint_32\
    \ = Montgomery_modint<id, u32, u64>;\ntemplate <int id>\nusing Montgomery_modint_64\
    \ = Montgomery_modint<id, u64, u128>;\n#line 3 \"nt/is_prime.hpp\"\n\nbool is_prime(const\
    \ u64 x) {\n  assert(x < u64(1) << 62);\n  if (x == 2 or x == 3 or x == 5 or x\
    \ == 7) return true;\n  if (x % 2 == 0 or x % 3 == 0 or x % 5 == 0 or x % 7 ==\
    \ 0) return false;\n  if (x < 121) return x > 1;\n  const u64 d = (x - 1) >> lowbit(x\
    \ - 1);\n\n  using mint = Montgomery_modint_64<202311020>;\n\n  mint::set_mod(x);\n\
    \  const mint one(u64(1)), minus_one(x - 1);\n  auto ok = [&](u64 a) -> bool {\n\
    \    auto y = mint(a).pow(d);\n    u64 t = d;\n    while (y != one && y != minus_one\
    \ && t != x - 1) y *= y, t <<= 1;\n    if (y != minus_one && t % 2 == 0) return\
    \ false;\n    return true;\n  };\n  if (x < (u64(1) << 32)) {\n    for (u64 a\
    \ : {2, 7, 61})\n      if (!ok(a)) return false;\n  } else {\n    for (u64 a :\
    \ {2, 325, 9375, 28178, 450775, 9780504, 1795265022}) {\n      if (!ok(a)) return\
    \ false;\n    }\n  }\n  return true;\n}\n#line 4 \"nt/factor.hpp\"\n\ntemplate\
    \ <typename mint>\nll rho(ll n, ll c) {\n  assert(n > 1);\n  const mint cc(c);\n\
    \  auto f = [&](mint x) { return x * x + cc; };\n  mint x = 1, y = 2, z = 1, q\
    \ = 1;\n  ll g = 1;\n  const ll m = 1LL << (__lg(n) / 5);\n  for (ll r = 1; g\
    \ == 1; r <<= 1) {\n    x = y;\n    FOR(r) y = f(y);\n    for (ll k = 0; k < r\
    \ && g == 1; k += m) {\n      z = y;\n      FOR(min(m, r - k)) y = f(y), q *=\
    \ x - y;\n      g = gcd(q.val(), n);\n    }\n  }\n  if (g == n) do {\n      z\
    \ = f(z);\n      g = gcd((x - z).val(), n);\n    } while (g == 1);\n  return g;\n\
    }\n\nll find_prime_factor(ll n) {\n  assert(1 < n && n < (1LL << 62));\n  if (n\
    \ % 2 == 0) return 2;\n  if (is_prime(n)) return n;\n  FOR(100) {\n    ll m =\
    \ 0;\n    if (n < (1 << 30)) {\n      using mint = Montgomery_modint_32<20231025>;\n\
    \      mint::set_mod(n);\n      m = rho<mint>(n, RNG(0, n));\n    } else {\n \
    \     using mint = Montgomery_modint_64<20231025>;\n      mint::set_mod(n);\n\
    \      m = rho<mint>(n, RNG(0, n));\n    }\n    if (is_prime(m)) return m;\n \
    \   n = m;\n  }\n  assert(0);\n  return -1;\n}\n\n// \u30BD\u30FC\u30C8\u3057\u3066\
    \u304F\u308C\u308B\nvc<pair<ll, int>> factor(ll n) {\n  assert(1 <= n && n < (1LL\
    \ << 62));\n  vc<pair<ll, int>> pf;\n  FOR(p, 2, 100) {\n    if (p * p > n) break;\n\
    \    if (n % p == 0) {\n      ll e = 0;\n      do {\n        n /= p, e += 1;\n\
    \      } while (n % p == 0);\n      pf.eb(p, e);\n    }\n  }\n  while (n > 1)\
    \ {\n    ll p = find_prime_factor(n);\n    ll e = 0;\n    do {\n      n /= p,\
    \ e += 1;\n    } while (n % p == 0);\n    pf.eb(p, e);\n  }\n  sort(all(pf));\n\
    \  return pf;\n}\n\nvc<pair<ll, int>> factor_by_lpf(ll n, vc<int>& lpf) {\n  vc<pair<ll,\
    \ int>> res;\n  while (n > 1) {\n    int p = lpf[n];\n    int e = 0;\n    while\
    \ (n % p == 0) {\n      n /= p;\n      ++e;\n    }\n    res.eb(p, e);\n  }\n \
    \ return res;\n}\n#line 6 \"test/1_mytest/count_by_factor_type.test.cpp\"\n\n\
    void test() {\n  map<vc<int>, ll> god;\n  FOR(N, 1, 1000) {\n    vc<int> S;\n\
    \    for (auto& [p, e]: factor(N)) S.eb(e);\n    sort(all(S));\n    reverse(all(S));\n\
    \    god[S]++;\n    map<vc<int>, ll> ans = count_by_factor_type(N);\n    assert(god\
    \ == ans);\n  }\n}\n\nvoid solve() {\n  int x, y;\n  cin >> x >> y;\n  cout <<\
    \ x + y << \"\\n\";\n}\n\nsigned main() {\n  test();\n  solve();\n  return 0;\n\
    }\n"
  code: "#define PROBLEM \"https://judge.yosupo.jp/problem/aplusb\"\n#include \"my_template.hpp\"\
    \n\n#include \"nt/count_by_factor_type.hpp\"\n#include \"nt/factor.hpp\"\n\nvoid\
    \ test() {\n  map<vc<int>, ll> god;\n  FOR(N, 1, 1000) {\n    vc<int> S;\n   \
    \ for (auto& [p, e]: factor(N)) S.eb(e);\n    sort(all(S));\n    reverse(all(S));\n\
    \    god[S]++;\n    map<vc<int>, ll> ans = count_by_factor_type(N);\n    assert(god\
    \ == ans);\n  }\n}\n\nvoid solve() {\n  int x, y;\n  cin >> x >> y;\n  cout <<\
    \ x + y << \"\\n\";\n}\n\nsigned main() {\n  test();\n  solve();\n  return 0;\n\
    }"
  dependsOn:
  - my_template.hpp
  - nt/count_by_factor_type.hpp
  - nt/prime_table.hpp
  - nt/prime_sum.hpp
  - nt/factor.hpp
  - random/base.hpp
  - nt/is_prime.hpp
  - other/bit.hpp
  - mod/montgomery_modint.hpp
  isVerificationFile: true
  path: test/1_mytest/count_by_factor_type.test.cpp
  requiredBy: []
  timestamp: '2026-09-04 09:44:55+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: test/1_mytest/count_by_factor_type.test.cpp
layout: document
redirect_from:
- /verify/test/1_mytest/count_by_factor_type.test.cpp
- /verify/test/1_mytest/count_by_factor_type.test.cpp.html
title: test/1_mytest/count_by_factor_type.test.cpp
---
