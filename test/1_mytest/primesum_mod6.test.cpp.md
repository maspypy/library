---
data:
  _extendedDependsOn:
  - icon: ':question:'
    path: my_template.hpp
    title: my_template.hpp
  - icon: ':heavy_check_mark:'
    path: nt/primesum.hpp
    title: nt/primesum.hpp
  - icon: ':heavy_check_mark:'
    path: nt/primesum_mod6.hpp
    title: nt/primesum_mod6.hpp
  - icon: ':question:'
    path: nt/primetable.hpp
    title: nt/primetable.hpp
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
  bundledCode: "#line 1 \"test/1_mytest/primesum_mod6.test.cpp\"\n#define PROBLEM\
    \ \"https://judge.yosupo.jp/problem/aplusb\"\n#line 1 \"my_template.hpp\"\n#if\
    \ defined(LOCAL)\n#include <my_template_compiled.hpp>\n#else\n\n// https://codeforces.com/blog/entry/96344\n\
    // https://codeforces.com/blog/entry/126772?#comment-1154880\n#if defined(__GNUC__)\n\
    #include <bits/allocator.h>\n#pragma GCC optimize(\"Ofast,unroll-loops\")\n#pragma\
    \ GCC target(\"avx2,popcnt\")\n#endif\n#include <bits/stdc++.h>\n\nusing namespace\
    \ std;\n\nusing ll = long long;\nusing u8 = uint8_t;\nusing u16 = uint16_t;\n\
    using u32 = uint32_t;\nusing u64 = uint64_t;\nusing i128 = __int128;\nusing u128\
    \ = unsigned __int128;\nusing f128 = __float128;\n\ntemplate <class T>\nconstexpr\
    \ T infty = 0;\ntemplate <>\nconstexpr int infty<int> = 1'010'000'000;\ntemplate\
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
    \ (a) - 1; i >= ll(0); --i)\n#define FOR2_R(i, a) for (ll i = (a) - 1; i >= ll(0);\
    \ --i)\n#define FOR3_R(i, a, b) for (ll i = (b) - 1; i >= ll(a); --i)\n#define\
    \ overload4(a, b, c, d, e, ...) e\n#define overload3(a, b, c, d, ...) d\n#define\
    \ FOR(...) overload4(__VA_ARGS__, FOR4, FOR3, FOR2, FOR1)(__VA_ARGS__)\n#define\
    \ FOR_R(...) overload3(__VA_ARGS__, FOR3_R, FOR2_R, FOR1_R)(__VA_ARGS__)\n\n#define\
    \ all(x) x.begin(), x.end()\n#define len(x) ll(x.size())\n#define elif else if\n\
    \n#define eb emplace_back\n#define mp make_pair\n#define mt make_tuple\n#define\
    \ fi first\n#define se second\n\n#define stoi stoll\n\nint popcnt(int x) { return\
    \ __builtin_popcount(x); }\nint popcnt(u32 x) { return __builtin_popcount(x);\
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
    \    UINT operator*() const { return s ^ t; }\n    iter &operator++() {\n    \
    \  (t == 0 ? ed = 1 : t = (t - 1) & s);\n      return *this;\n    }\n    bool\
    \ operator!=(const iter) const { return !ed; }\n  };\n  UINT s;\n  all_subset(UINT\
    \ s) : s(s) {}\n  iter begin() const { return iter(s); }\n  iter end() const {\
    \ return iter(0); }\n};\n\ntemplate <typename T>\nT floor(T a, T b) {\n  return\
    \ a / b - (a % b && (a ^ b) < 0);\n}\ntemplate <typename T>\nT ceil(T x, T y)\
    \ {\n  return floor(x + y - 1, y);\n}\ntemplate <typename T>\nT bmod(T x, T y)\
    \ {\n  return x - y * floor(x, y);\n}\ntemplate <typename T>\npair<T, T> divmod(T\
    \ x, T y) {\n  T q = floor(x, y);\n  return {q, x - q * y};\n}\n\ninline constexpr\
    \ std::array<u64, 20> TEN_TAB = [] {\n  std::array<u64, 20> a{};\n  u64 x = 1;\n\
    \  for (int i = 0; i <= 19; ++i) {\n    a[i] = x, x *= 10;\n  }\n  return a;\n\
    }();\n\ninline constexpr u64 TEN(int n) {\n  assert(0 <= n && n <= 19);\n  return\
    \ TEN_TAB[n];\n}\n\ntemplate <int N>\ninline constexpr u64 TEN_v = [] {\n  static_assert(0\
    \ <= N && N <= 19);\n  return TEN_TAB[N];\n}();\n\ntemplate <typename T, typename\
    \ U>\nT SUM(const U &A) {\n  return std::accumulate(A.begin(), A.end(), T{});\n\
    }\n\n#define MIN(v) *min_element(all(v))\n#define MAX(v) *max_element(all(v))\n\
    #define LB(c, x) distance((c).begin(), lower_bound(all(c), (x)))\n#define UB(c,\
    \ x) distance((c).begin(), upper_bound(all(c), (x)))\n#define UNIQUE(x) \\\n \
    \ sort(all(x)), x.erase(unique(all(x)), x.end()), x.shrink_to_fit()\n\ntemplate\
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
    template <class T, class S>\ninline bool chmax(T &a, const S &b) {\n  return (a\
    \ < b ? a = b, 1 : 0);\n}\ntemplate <class T, class S>\ninline bool chmin(T &a,\
    \ const S &b) {\n  return (a > b ? a = b, 1 : 0);\n}\n\n// ? \u306F -1\nvc<int>\
    \ s_to_vi(const string &S, char first_char) {\n  vc<int> A(S.size());\n  FOR(i,\
    \ S.size()) { A[i] = (S[i] != '?' ? S[i] - first_char : -1); }\n  return A;\n\
    }\n\ntemplate <typename T, typename U>\nvc<T> cumsum(const vc<U> &A, int off =\
    \ 1) {\n  int N = A.size();\n  vc<T> B(N + 1);\n  FOR(i, N) { B[i + 1] = B[i]\
    \ + A[i]; }\n  if (off == 0) B.erase(B.begin());\n  return B;\n}\n\n// stable\
    \ sort\ntemplate <typename T>\nvc<int> argsort(const vc<T> &A) {\n  vc<int> ids(len(A));\n\
    \  iota(all(ids), 0);\n  sort(all(ids),\n       [&](int i, int j) { return (A[i]\
    \ == A[j] ? i < j : A[i] < A[j]); });\n  return ids;\n}\n\n// A[I[0]], A[I[1]],\
    \ ...\ntemplate <typename T>\nvc<T> rearrange(const vc<T> &A, const vc<int> &I)\
    \ {\n  vc<T> B(len(I));\n  FOR(i, len(I)) B[i] = A[I[i]];\n  return B;\n}\n\n\
    template <typename T, typename... Vectors>\nvoid concat(vc<T> &first, const Vectors\
    \ &...others) {\n  vc<T> &res = first;\n  (res.insert(res.end(), others.begin(),\
    \ others.end()), ...);\n}\n#endif\n#line 2 \"nt/primetable.hpp\"\n\ntemplate <typename\
    \ T = int>\nvc<T> primetable(int LIM) {\n  ++LIM;\n  const int S = 32768;\n  static\
    \ int done = 2;\n  static vc<T> primes = {2}, sieve(S + 1);\n\n  if (done < LIM)\
    \ {\n    done = LIM;\n\n    primes = {2}, sieve.assign(S + 1, 0);\n    const int\
    \ R = LIM / 2;\n    primes.reserve(int(LIM / log(LIM) * 1.1));\n    vc<pair<int,\
    \ int>> cp;\n    for (int i = 3; i <= S; i += 2) {\n      if (!sieve[i]) {\n \
    \       cp.eb(i, i * i / 2);\n        for (int j = i * i; j <= S; j += 2 * i)\
    \ sieve[j] = 1;\n      }\n    }\n    for (int L = 1; L <= R; L += S) {\n     \
    \ array<bool, S> block{};\n      for (auto& [p, idx]: cp)\n        for (int i\
    \ = idx; i < S + L; idx = (i += p)) block[i - L] = 1;\n      FOR(i, min(S, R -\
    \ L)) if (!block[i]) primes.eb((L + i) * 2 + 1);\n    }\n  }\n  int k = LB(primes,\
    \ LIM + 1);\n  return {primes.begin(), primes.begin() + k};\n}\n#line 3 \"nt/primesum.hpp\"\
    \n\r\n/*\r\nN \u3068\u5B8C\u5168\u4E57\u6CD5\u7684\u95A2\u6570 f \u306E prefix\
    \ sum \u95A2\u6570 F \u3092\u4E0E\u3048\u308B\u3002\r\nn = floor(N/d) \u3068\u306A\
    \u308B n \u306B\u5BFE\u3059\u308B sum_{p <= n} f(p) \u3092\u8A08\u7B97\u3059\u308B\
    \u3002\r\n\u7279\u306B\u3001\u7D20\u6570\u306E k \u4E57\u548C\u3084\u3001mod m\
    \ \u3054\u3068\u3067\u306E\u7D20\u6570\u306E k \u4E57\u548C\u304C\u8A08\u7B97\u3067\
    \u304D\u308B\u3002\r\nComplexity: O(N^{3/4}/logN) time, O(N^{1/2}) space.\r\n\
    */\r\ntemplate <typename T>\r\nstruct PrimeSum {\r\n  ll N;\r\n  ll sqN;\r\n \
    \ vc<T> sum_lo, sum_hi;\r\n  bool calculated;\r\n\r\n  PrimeSum(ll N) : N(N),\
    \ sqN(sqrtl(N)), calculated(0) {}\r\n\r\n  // [1, x] \u305F\u3060\u3057\u3001\
    x = floor(N, i) \u306E\u5F62\r\n  T operator[](ll x) {\r\n    assert(calculated);\r\
    \n    return (x <= sqN ? sum_lo[x] : sum_hi[double(N) / x]);\r\n  }\r\n\r\n  template\
    \ <typename F>\r\n  void calc(const F f) {\r\n    auto primes = primetable<int>(sqN);\r\
    \n    sum_lo.resize(sqN + 1);\r\n    sum_hi.resize(sqN + 1);\r\n    FOR3(i, 1,\
    \ sqN + 1) sum_lo[i] = f(i) - 1;\r\n    FOR3(i, 1, sqN + 1) sum_hi[i] = f(double(N)\
    \ / i) - 1;\r\n    for (int p: primes) {\r\n      ll pp = ll(p) * p;\r\n     \
    \ if (pp > N) break;\r\n      int R = min(sqN, N / pp);\r\n      int M = sqN /\
    \ p;\r\n      T x = sum_lo[p - 1];\r\n      T fp = sum_lo[p] - sum_lo[p - 1];\r\
    \n      for (int i = 1; i <= M; ++i) sum_hi[i] -= fp * (sum_hi[i * p] - x);\r\n\
    \      for (int i = M + 1; i <= R; ++i) sum_hi[i] -= fp * (sum_lo[N / (double(i)\
    \ * p)] - x);\r\n      for (int n = sqN; n >= pp; --n) sum_lo[n] -= fp * (sum_lo[n\
    \ / p] - x);\r\n    }\r\n    calculated = 1;\r\n  }\r\n\r\n  void calc_count()\
    \ {\r\n    calc([](ll x) -> T { return x; });\r\n  }\r\n\r\n  void calc_sum()\
    \ {\r\n    calc([](ll x) -> T {\r\n      ll a = x, b = x + 1;\r\n      if (!(x\
    \ & 1)) a /= 2;\r\n      if (x & 1) b /= 2;\r\n      return T(a) * T(b);\r\n \
    \   });\r\n  }\r\n};\n#line 3 \"nt/primesum_mod6.hpp\"\n\ntemplate <typename T>\n\
    struct PrimeSum_Mod_6 {\n  ll N;\n  ll sqN;\n\n  PrimeSum<T> A, B;\n  PrimeSum_Mod_6(ll\
    \ N) : N(N), sqN(sqrtl(N)), A(N), B(N) {}\n\n  pair<T, T> operator[](ll x) {\n\
    \    T a = A[x], b = B[x];\n    return {(a + b) / T(2), (a - b) / T(2)};\n  }\n\
    \n  void calc_count() {\n    A.calc([](ll x) -> T { return ((x + 2) / 3 - (x %\
    \ 6 == 4)); });\n    B.calc([](ll x) -> T { return ((x + 5) % 6 <= 3 ? 1 : 0);\
    \ });\n  }\n\n  void calc_sum() {\n    A.calc([](ll x) -> T {\n      ll n = (x\
    \ + 2) / 3 - (x % 6 == 4);\n      ll k = n / 2;\n      if (n % 2 == 0) { return\
    \ T(6 * k) * T(k); }\n      return T(6 * k) * T(k) + T(6 * k + 1);\n    });\n\
    \    B.calc([](ll x) -> T {\n      ll n = (x + 2) / 3 - (x % 6 == 4);\n      ll\
    \ k = n / 2;\n      if (n % 2 == 0) { return T(-4 * k); }\n      return T(-4 *\
    \ k + 6 * k + 1);\n    });\n  }\n};\n#line 4 \"test/1_mytest/primesum_mod6.test.cpp\"\
    \n\nvoid test_count() {\n  ll LIM = 10000;\n  vc<int> A1(LIM), A5(LIM);\n  for\
    \ (auto&& p: primetable(LIM))\n    if (p % 6 == 1) { A1[p]++; }\n  for (auto&&\
    \ p: primetable(LIM))\n    if (p % 6 == 5) { A5[p]++; }\n  A1 = cumsum<int>(A1,\
    \ 0);\n  A5 = cumsum<int>(A5, 0);\n\n  FOR(N, LIM) {\n    PrimeSum_Mod_6<int>\
    \ X(N);\n    X.calc_count();\n    FOR(K, 1, N + 10) { assert(X[N / K] == mp(A1[N\
    \ / K], A5[N / K])); }\n  }\n}\n\nvoid test_sum() {\n  ll LIM = 10000;\n  vc<int>\
    \ A1(LIM), A5(LIM);\n  for (auto&& p: primetable(LIM))\n    if (p % 6 == 1) {\
    \ A1[p] += p; }\n  for (auto&& p: primetable(LIM))\n    if (p % 6 == 5) { A5[p]\
    \ += p; }\n  A1 = cumsum<int>(A1, 0);\n  A5 = cumsum<int>(A5, 0);\n\n  FOR(N,\
    \ LIM) {\n    PrimeSum_Mod_6<int> X(N);\n    X.calc_sum();\n    FOR(K, 1, N +\
    \ 10) { assert(X[N / K] == mp(A1[N / K], A5[N / K])); }\n  }\n}\n\nvoid solve()\
    \ {\n  int a, b;\n  cin >> a >> b;\n  cout << a + b << \"\\n\";\n}\n\nsigned main()\
    \ {\n  test_count();\n  test_sum();\n  solve();\n\n  return 0;\n}\n"
  code: "#define PROBLEM \"https://judge.yosupo.jp/problem/aplusb\"\n#include \"my_template.hpp\"\
    \n#include \"nt/primesum_mod6.hpp\"\n\nvoid test_count() {\n  ll LIM = 10000;\n\
    \  vc<int> A1(LIM), A5(LIM);\n  for (auto&& p: primetable(LIM))\n    if (p % 6\
    \ == 1) { A1[p]++; }\n  for (auto&& p: primetable(LIM))\n    if (p % 6 == 5) {\
    \ A5[p]++; }\n  A1 = cumsum<int>(A1, 0);\n  A5 = cumsum<int>(A5, 0);\n\n  FOR(N,\
    \ LIM) {\n    PrimeSum_Mod_6<int> X(N);\n    X.calc_count();\n    FOR(K, 1, N\
    \ + 10) { assert(X[N / K] == mp(A1[N / K], A5[N / K])); }\n  }\n}\n\nvoid test_sum()\
    \ {\n  ll LIM = 10000;\n  vc<int> A1(LIM), A5(LIM);\n  for (auto&& p: primetable(LIM))\n\
    \    if (p % 6 == 1) { A1[p] += p; }\n  for (auto&& p: primetable(LIM))\n    if\
    \ (p % 6 == 5) { A5[p] += p; }\n  A1 = cumsum<int>(A1, 0);\n  A5 = cumsum<int>(A5,\
    \ 0);\n\n  FOR(N, LIM) {\n    PrimeSum_Mod_6<int> X(N);\n    X.calc_sum();\n \
    \   FOR(K, 1, N + 10) { assert(X[N / K] == mp(A1[N / K], A5[N / K])); }\n  }\n\
    }\n\nvoid solve() {\n  int a, b;\n  cin >> a >> b;\n  cout << a + b << \"\\n\"\
    ;\n}\n\nsigned main() {\n  test_count();\n  test_sum();\n  solve();\n\n  return\
    \ 0;\n}\n"
  dependsOn:
  - my_template.hpp
  - nt/primesum_mod6.hpp
  - nt/primesum.hpp
  - nt/primetable.hpp
  isVerificationFile: true
  path: test/1_mytest/primesum_mod6.test.cpp
  requiredBy: []
  timestamp: '2025-09-01 21:30:48+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: test/1_mytest/primesum_mod6.test.cpp
layout: document
redirect_from:
- /verify/test/1_mytest/primesum_mod6.test.cpp
- /verify/test/1_mytest/primesum_mod6.test.cpp.html
title: test/1_mytest/primesum_mod6.test.cpp
---
