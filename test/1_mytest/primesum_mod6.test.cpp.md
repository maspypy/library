---
data:
  _extendedDependsOn:
  - icon: ':question:'
    path: my_template.hpp
    title: my_template.hpp
  - icon: ':heavy_check_mark:'
    path: nt/prime_sum.hpp
    title: nt/prime_sum.hpp
  - icon: ':heavy_check_mark:'
    path: nt/prime_sum_mod6.hpp
    title: nt/prime_sum_mod6.hpp
  - icon: ':heavy_check_mark:'
    path: nt/prime_table.hpp
    title: nt/prime_table.hpp
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
    \ ng, bool check_ok = true) {\n  if (check_ok) assert(check(ok));\n  while (1)\
    \ {\n    ll x = (ok + ng) / 2;\n    if (x == ok || x == ng) break;\n    (check(x)\
    \ ? ok : ng) = x;\n  }\n  return ok;\n}\ntemplate <typename F>\ndouble binary_search_real(F\
    \ check, double ok, double ng, int iter = 100) {\n  FOR(iter) {\n    double x\
    \ = (ok + ng) / 2;\n    (check(x) ? ok : ng) = x;\n  }\n  return (ok + ng) / 2;\n\
    }\n\ntemplate <class T, class S>\ninline bool chmax(T &a, const S &b) {\n  T c\
    \ = max<T>(a, b);\n  bool changed = (c != a);\n  a = c;\n  return changed;\n}\n\
    template <class T, class S>\ninline bool chmin(T &a, const S &b) {\n  T c = min<T>(a,\
    \ b);\n  bool changed = (c != a);\n  a = c;\n  return changed;\n}\n\n// ? \u306F\
    \ -1\nvc<int> s_to_vi(const string &S, char first_char) {\n  vc<int> A(S.size());\n\
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
    \  (first.insert(first.end(), others.begin(), others.end()), ...);\n}\n\n// i128\n\
    template <class T, enable_if_t<is_same_v<T, i128>, int> = 0>\nconstexpr i128 abs(T\
    \ x) {\n  return x < 0 ? -x : x;\n}\n\nconstexpr i128 gcd(i128 a, i128 b) {\n\
    \  while (b != 0) {\n    i128 c = a % b;\n    a = b, b = c;\n  }\n  return abs(a);\n\
    }\n#endif\n#line 1 \"nt/prime_table.hpp\"\n\ntemplate <typename T = int>\nvc<T>\
    \ prime_table(int LIM) {\n  ++LIM;\n  const int S = 32768;\n  static int done\
    \ = 2;\n  static vc<T> primes = {2}, sieve(S + 1);\n\n  if (done < LIM) {\n  \
    \  done = LIM;\n\n    primes = {2}, sieve.assign(S + 1, 0);\n    const int R =\
    \ LIM / 2;\n    primes.reserve(int(LIM / log(LIM) * 1.1));\n    vc<pair<int, int>>\
    \ cp;\n    for (int i = 3; i <= S; i += 2) {\n      if (!sieve[i]) {\n       \
    \ cp.eb(i, i * i / 2);\n        for (int j = i * i; j <= S; j += 2 * i) sieve[j]\
    \ = 1;\n      }\n    }\n    for (int L = 1; L <= R; L += S) {\n      array<bool,\
    \ S> block{};\n      for (auto& [p, idx] : cp)\n        for (int i = idx; i <\
    \ S + L; idx = (i += p)) block[i - L] = 1;\n      FOR(i, min(S, R - L)) if (!block[i])\
    \ primes.eb((L + i) * 2 + 1);\n    }\n  }\n  int k = LB(primes, LIM + 1);\n  return\
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
    \ (x & 1) b /= 2;\n      return T(a) * T(b);\n    });\n  }\n};\n#line 1 \"nt/prime_table.hpp\"\
    \n\ntemplate <typename T = int>\nvc<T> prime_table(int LIM) {\n  ++LIM;\n  const\
    \ int S = 32768;\n  static int done = 2;\n  static vc<T> primes = {2}, sieve(S\
    \ + 1);\n\n  if (done < LIM) {\n    done = LIM;\n\n    primes = {2}, sieve.assign(S\
    \ + 1, 0);\n    const int R = LIM / 2;\n    primes.reserve(int(LIM / log(LIM)\
    \ * 1.1));\n    vc<pair<int, int>> cp;\n    for (int i = 3; i <= S; i += 2) {\n\
    \      if (!sieve[i]) {\n        cp.eb(i, i * i / 2);\n        for (int j = i\
    \ * i; j <= S; j += 2 * i) sieve[j] = 1;\n      }\n    }\n    for (int L = 1;\
    \ L <= R; L += S) {\n      array<bool, S> block{};\n      for (auto& [p, idx]\
    \ : cp)\n        for (int i = idx; i < S + L; idx = (i += p)) block[i - L] = 1;\n\
    \      FOR(i, min(S, R - L)) if (!block[i]) primes.eb((L + i) * 2 + 1);\n    }\n\
    \  }\n  int k = LB(primes, LIM + 1);\n  return {primes.begin(), primes.begin()\
    \ + k};\n}\n#line 3 \"nt/prime_sum_mod6.hpp\"\n\ntemplate <typename T>\nstruct\
    \ Prime_Sum_Mod_6 {\n  ll N;\n  ll sqN;\n\n  Prime_Sum<T> A, B;\n  Prime_Sum_Mod_6(ll\
    \ N) : N(N), sqN(sqrtl(N)), A(N), B(N) {}\n\n  pair<T, T> operator[](ll x) {\n\
    \    T a = A[x], b = B[x];\n    return {(a + b) / T(2), (a - b) / T(2)};\n  }\n\
    \n  void calc_count() {\n    A.calc([](ll x) -> T { return ((x + 2) / 3 - (x %\
    \ 6 == 4)); });\n    B.calc([](ll x) -> T { return ((x + 5) % 6 <= 3 ? 1 : 0);\
    \ });\n  }\n\n  void calc_sum() {\n    A.calc([](ll x) -> T {\n      ll n = (x\
    \ + 2) / 3 - (x % 6 == 4);\n      ll k = n / 2;\n      if (n % 2 == 0) {\n   \
    \     return T(6 * k) * T(k);\n      }\n      return T(6 * k) * T(k) + T(6 * k\
    \ + 1);\n    });\n    B.calc([](ll x) -> T {\n      ll n = (x + 2) / 3 - (x %\
    \ 6 == 4);\n      ll k = n / 2;\n      if (n % 2 == 0) {\n        return T(-4\
    \ * k);\n      }\n      return T(-4 * k + 6 * k + 1);\n    });\n  }\n};\n#line\
    \ 4 \"test/1_mytest/primesum_mod6.test.cpp\"\n\nvoid test_count() {\n  ll LIM\
    \ = 10000;\n  vc<int> A1(LIM), A5(LIM);\n  for (auto&& p : prime_table(LIM))\n\
    \    if (p % 6 == 1) {\n      A1[p]++;\n    }\n  for (auto&& p : prime_table(LIM))\n\
    \    if (p % 6 == 5) {\n      A5[p]++;\n    }\n  A1 = cumsum<int>(A1, 0);\n  A5\
    \ = cumsum<int>(A5, 0);\n\n  FOR(N, LIM) {\n    Prime_Sum_Mod_6<int> X(N);\n \
    \   X.calc_count();\n    FOR(K, 1, N + 10) { assert(X[N / K] == mp(A1[N / K],\
    \ A5[N / K])); }\n  }\n}\n\nvoid test_sum() {\n  ll LIM = 10000;\n  vc<int> A1(LIM),\
    \ A5(LIM);\n  for (auto&& p : prime_table(LIM))\n    if (p % 6 == 1) {\n     \
    \ A1[p] += p;\n    }\n  for (auto&& p : prime_table(LIM))\n    if (p % 6 == 5)\
    \ {\n      A5[p] += p;\n    }\n  A1 = cumsum<int>(A1, 0);\n  A5 = cumsum<int>(A5,\
    \ 0);\n\n  FOR(N, LIM) {\n    Prime_Sum_Mod_6<int> X(N);\n    X.calc_sum();\n\
    \    FOR(K, 1, N + 10) { assert(X[N / K] == mp(A1[N / K], A5[N / K])); }\n  }\n\
    }\n\nvoid solve() {\n  int a, b;\n  cin >> a >> b;\n  cout << a + b << \"\\n\"\
    ;\n}\n\nsigned main() {\n  test_count();\n  test_sum();\n  solve();\n\n  return\
    \ 0;\n}\n"
  code: "#define PROBLEM \"https://judge.yosupo.jp/problem/aplusb\"\n#include \"my_template.hpp\"\
    \n#include \"nt/prime_sum_mod6.hpp\"\n\nvoid test_count() {\n  ll LIM = 10000;\n\
    \  vc<int> A1(LIM), A5(LIM);\n  for (auto&& p : prime_table(LIM))\n    if (p %\
    \ 6 == 1) {\n      A1[p]++;\n    }\n  for (auto&& p : prime_table(LIM))\n    if\
    \ (p % 6 == 5) {\n      A5[p]++;\n    }\n  A1 = cumsum<int>(A1, 0);\n  A5 = cumsum<int>(A5,\
    \ 0);\n\n  FOR(N, LIM) {\n    Prime_Sum_Mod_6<int> X(N);\n    X.calc_count();\n\
    \    FOR(K, 1, N + 10) { assert(X[N / K] == mp(A1[N / K], A5[N / K])); }\n  }\n\
    }\n\nvoid test_sum() {\n  ll LIM = 10000;\n  vc<int> A1(LIM), A5(LIM);\n  for\
    \ (auto&& p : prime_table(LIM))\n    if (p % 6 == 1) {\n      A1[p] += p;\n  \
    \  }\n  for (auto&& p : prime_table(LIM))\n    if (p % 6 == 5) {\n      A5[p]\
    \ += p;\n    }\n  A1 = cumsum<int>(A1, 0);\n  A5 = cumsum<int>(A5, 0);\n\n  FOR(N,\
    \ LIM) {\n    Prime_Sum_Mod_6<int> X(N);\n    X.calc_sum();\n    FOR(K, 1, N +\
    \ 10) { assert(X[N / K] == mp(A1[N / K], A5[N / K])); }\n  }\n}\n\nvoid solve()\
    \ {\n  int a, b;\n  cin >> a >> b;\n  cout << a + b << \"\\n\";\n}\n\nsigned main()\
    \ {\n  test_count();\n  test_sum();\n  solve();\n\n  return 0;\n}\n"
  dependsOn:
  - my_template.hpp
  - nt/prime_sum_mod6.hpp
  - nt/prime_sum.hpp
  - nt/prime_table.hpp
  isVerificationFile: true
  path: test/1_mytest/primesum_mod6.test.cpp
  requiredBy: []
  timestamp: '2026-08-16 04:03:00+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: test/1_mytest/primesum_mod6.test.cpp
layout: document
redirect_from:
- /verify/test/1_mytest/primesum_mod6.test.cpp
- /verify/test/1_mytest/primesum_mod6.test.cpp.html
title: test/1_mytest/primesum_mod6.test.cpp
---
