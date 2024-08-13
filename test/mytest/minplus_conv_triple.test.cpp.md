---
data:
  _extendedDependsOn:
  - icon: ':question:'
    path: convex/minplus_convolution.hpp
    title: convex/minplus_convolution.hpp
  - icon: ':x:'
    path: convex/minplus_convolution_of_triples.hpp
    title: convex/minplus_convolution_of_triples.hpp
  - icon: ':question:'
    path: convex/monotone_minima.hpp
    title: convex/monotone_minima.hpp
  - icon: ':question:'
    path: my_template.hpp
    title: my_template.hpp
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
  bundledCode: "#line 1 \"test/mytest/minplus_conv_triple.test.cpp\"\n#define PROBLEM\
    \ \"https://judge.yosupo.jp/problem/aplusb\"\n#line 1 \"my_template.hpp\"\n#if\
    \ defined(LOCAL)\n#include <my_template_compiled.hpp>\n#else\n\n// https://codeforces.com/blog/entry/96344\n\
    #pragma GCC optimize(\"Ofast,unroll-loops\")\n// \u3044\u307E\u306E CF \u3060\u3068\
    \u3053\u308C\u5165\u308C\u308B\u3068\u52D5\u304B\u306A\u3044\uFF1F\n// #pragma\
    \ GCC target(\"avx2,popcnt\")\n\n#include <bits/stdc++.h>\n\nusing namespace std;\n\
    \nusing ll = long long;\nusing u32 = unsigned int;\nusing u64 = unsigned long\
    \ long;\nusing i128 = __int128;\nusing u128 = unsigned __int128;\nusing f128 =\
    \ __float128;\n\ntemplate <class T>\nconstexpr T infty = 0;\ntemplate <>\nconstexpr\
    \ int infty<int> = 1'010'000'000;\ntemplate <>\nconstexpr ll infty<ll> = 2'020'000'000'000'000'000;\n\
    template <>\nconstexpr u32 infty<u32> = infty<int>;\ntemplate <>\nconstexpr u64\
    \ infty<u64> = infty<ll>;\ntemplate <>\nconstexpr i128 infty<i128> = i128(infty<ll>)\
    \ * 2'000'000'000'000'000'000;\ntemplate <>\nconstexpr double infty<double> =\
    \ infty<ll>;\ntemplate <>\nconstexpr long double infty<long double> = infty<ll>;\n\
    \nusing pi = pair<ll, ll>;\nusing vi = vector<ll>;\ntemplate <class T>\nusing\
    \ vc = vector<T>;\ntemplate <class T>\nusing vvc = vector<vc<T>>;\ntemplate <class\
    \ T>\nusing vvvc = vector<vvc<T>>;\ntemplate <class T>\nusing vvvvc = vector<vvvc<T>>;\n\
    template <class T>\nusing vvvvvc = vector<vvvvc<T>>;\ntemplate <class T>\nusing\
    \ pq = priority_queue<T>;\ntemplate <class T>\nusing pqg = priority_queue<T, vector<T>,\
    \ greater<T>>;\n\n#define vv(type, name, h, ...) vector<vector<type>> name(h,\
    \ vector<type>(__VA_ARGS__))\n#define vvv(type, name, h, w, ...) vector<vector<vector<type>>>\
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
    \ others.end()), ...);\n}\n#endif\n#line 3 \"test/mytest/minplus_conv_triple.test.cpp\"\
    \n\n#line 2 \"random/base.hpp\"\n\nu64 RNG_64() {\n  static uint64_t x_\n    \
    \  = uint64_t(chrono::duration_cast<chrono::nanoseconds>(\n                  \
    \   chrono::high_resolution_clock::now().time_since_epoch())\n               \
    \      .count())\n        * 10150724397891781847ULL;\n  x_ ^= x_ << 7;\n  return\
    \ x_ ^= x_ >> 9;\n}\n\nu64 RNG(u64 lim) { return RNG_64() % lim; }\n\nll RNG(ll\
    \ l, ll r) { return l + RNG_64() % (r - l); }\n#line 1 \"convex/monotone_minima.hpp\"\
    \n\n// select(i,j,k) : (i,j) -> (i,k) \u3092\u884C\u3046\u304B\u3069\u3046\u304B\
    \ntemplate <typename F>\nvc<int> monotone_minima(int H, int W, F select) {\n \
    \ vc<int> min_col(H);\n  auto dfs = [&](auto& dfs, int x1, int x2, int y1, int\
    \ y2) -> void {\n    if (x1 == x2) return;\n    int x = (x1 + x2) / 2;\n    int\
    \ best_y = y1;\n    for (int y = y1 + 1; y < y2; ++y) {\n      if (select(x, best_y,\
    \ y)) best_y = y;\n    }\n    min_col[x] = best_y;\n    dfs(dfs, x1, x, y1, best_y\
    \ + 1);\n    dfs(dfs, x + 1, x2, best_y, y2);\n  };\n  dfs(dfs, 0, H, 0, W);\n\
    \  return min_col;\n}\n#line 2 \"convex/minplus_convolution.hpp\"\n\ntemplate\
    \ <typename T>\nvc<T> minplus_convolution_convex_convex(vc<T>& A, vc<T>& B) {\n\
    \  int n = len(A), m = len(B);\n  if (n == 0 && m == 0) return {};\n  vc<T> C(n\
    \ + m - 1, infty<T>);\n  while (n > 0 && A[n - 1] == infty<T>) --n;\n  while (m\
    \ > 0 && B[m - 1] == infty<T>) --m;\n  if (n == 0 || m == 0) return C;\n  int\
    \ a = 0, b = 0;\n  while (a < n && A[a] == infty<T>) ++a;\n  while (b < m && B[b]\
    \ == infty<T>) ++b;\n  C[a + b] = A[a] + B[b];\n  for (int i = a + b + 1; i <\
    \ n + m - 1; ++i) {\n    if (b == m - 1 || (a != n - 1 && A[a + 1] + B[b] < A[a]\
    \ + B[b + 1])) {\n      chmin(C[i], A[++a] + B[b]);\n    } else {\n      chmin(C[i],\
    \ A[a] + B[++b]);\n    }\n  }\n  return C;\n}\n\ntemplate <typename T>\nvc<T>\
    \ minplus_convolution_arbitrary_convex(vc<T>& A, vc<T>& B) {\n  int n = len(A),\
    \ m = len(B);\n  if (n == 0 && m == 0) return {};\n  vc<T> C(n + m - 1, infty<T>);\n\
    \  while (m > 0 && B[m - 1] == infty<T>) --m;\n  if (m == 0) return C;\n  int\
    \ b = 0;\n  while (b < m && B[b] == infty<T>) ++b;\n\n  auto select = [&](int\
    \ i, int j, int k) -> bool {\n    if (i < k) return false;\n    if (i - j >= m\
    \ - b) return true;\n    return A[j] + B[b + i - j] >= A[k] + B[b + i - k];\n\
    \  };\n  vc<int> J = monotone_minima(n + m - b - 1, n, select);\n  FOR(i, n +\
    \ m - b - 1) {\n    T x = A[J[i]], y = B[b + i - J[i]];\n    if (x < infty<T>\
    \ && y < infty<T>) C[b + i] = x + y;\n  }\n  return C;\n}\n\ntemplate <typename\
    \ T, bool convA, bool convB>\nvc<T> minplus_convolution(vc<T>& A, vc<T>& B) {\n\
    \  static_assert(convA || convB);\n  if constexpr (convA && convB) return minplus_convolution_convex_convex(A,\
    \ B);\n  if constexpr (convA && !convB)\n    return minplus_convolution_arbitrary_convex(B,\
    \ A);\n  if constexpr (convB && !convA)\n    return minplus_convolution_arbitrary_convex(A,\
    \ B);\n  return {};\n}\n#line 2 \"convex/minplus_convolution_of_triples.hpp\"\n\
    \n// https://codeforces.com/contest/436/problem/E\n// \u9577\u3055 3 \u306E\u6570\
    \u5217 {a[i][0], a[i][1], a[i][2]} \u305F\u3061\u306E\u7573\u307F\u8FBC\u307F\
    , O(NlogN)\n// \u540C\u7A2E\u306E\u554F\u984C\uFF1A(a_i,b_i) \u304C\u3042\u3063\
    \u3066\u3001b_i \u306F a_i \u3092\u53D6\u3063\u3066\u304B\u3089\u3060\u3051\u53D6\
    \u308C\u308B\ntemplate <typename T>\nstruct MinPlus_Convolution_of_Triples {\n\
    \  int N = 0;\n  T sm0 = 0;\n  vc<array<T, 3>> dat;\n  vc<T> dp1, dp2, dp;\n \
    \ vc<int> I1, I2;\n  bool solved = false;\n\n  void add(T x0, T x1, T x2) { sm0\
    \ += x0, dat.eb(array<T, 3>{x0, x1, x2}); }\n\n  void solve() {\n    solved =\
    \ true;\n    N = dat.size();\n    FOR(i, N) {\n      int a = dat[i][1] - dat[i][0],\
    \ b = dat[i][2] - dat[i][1];\n      (a <= b ? I1 : I2).eb(i);\n    };\n    sort(all(I2),\
    \ [&](int i, int j) -> bool {\n      return dat[i][2] - dat[i][0] < dat[j][2]\
    \ - dat[j][0];\n    });\n    solve_1();\n    solve_2();\n    dp = minplus_convolution<T,\
    \ true, false>(dp1, dp2);\n    for (auto&& x: dp) x += sm0;\n  }\n\n  T operator[](int\
    \ i) { return dp[i]; }\n\n  vc<int> restore(int k) {\n    assert(solved);\n  \
    \  int k1 = -1, k2 = -1;\n    FOR(i, k + 1) {\n      int j = k - i;\n      if\
    \ (0 <= i && i < len(dp1) && 0 <= j && j < len(dp2)\n          && dp1[i] + dp2[j]\
    \ + sm0 == dp[k]) {\n        k1 = i, k2 = j;\n        break;\n      }\n    }\n\
    \    assert(k1 != -1 && k2 != -1);\n    vc<int> x(N);\n    vc<int> x1 = restore_1(k1);\n\
    \    vc<int> x2 = restore_2(k2);\n    for (int i = 0; i < N; ++i) x[i] = x1[i]\
    \ + x2[i];\n    return x;\n  }\n\nprivate:\n  void solve_1() {\n    dp1.reserve(len(I1));\n\
    \    for (int i: I1) {\n      dp1.eb(dat[i][1] - dat[i][0]), dp1.eb(dat[i][2]\
    \ - dat[i][1]);\n    }\n    sort(all(dp1));\n    dp1 = cumsum<T>(dp1);\n  }\n\n\
    \  vc<int> restore_1(int k) {\n    vc<pair<T, int>> A;\n    for (int i: I1) {\n\
    \      A.eb(dat[i][1] - dat[i][0], i);\n      A.eb(dat[i][2] - dat[i][1], i);\n\
    \    }\n    nth_element(A.begin(), A.begin() + k, A.end());\n    vc<int> x(N);\n\
    \    FOR(i, k) x[A[i].se]++;\n    return x;\n  }\n\n  void solve_2() {\n    //\
    \ B-A > C-B \u306E\u30B1\u30FC\u30B9\n    // \u89E3\u306E\u69CB\u9020\u3092\u8003\
    \u3048\u308B\u3068\u3001\u307B\u3068\u3093\u3069\u3059\u3079\u3066\u3067 x=0 or\
    \ x=2 \u3068\u3044\u3046\u3068\u308A\u304B\u305F\u306B\u306A\u308B\n    // \u65E2\
    \u306B C-A \u3067\u30BD\u30FC\u30C8\u6E08\n    auto& I = I2;\n    int n = len(I);\n\
    \    dp2.assign(2 * n + 1, infty<T>);\n    // \u5076\u6570\u500B\n    dp2[0] =\
    \ 0;\n    for (int i = 0; i < n; ++i) {\n      dp2[2 * i + 2] = dp2[2 * i] + (dat[I[i]][2]\
    \ - dat[I[i]][0]);\n    }\n    // \u5947\u6570\u500B, prefix \u304B\u3089\u3072\
    \u3068\u3064\u30AD\u30E3\u30F3\u30BB\u30EB\u3059\u308B\n    T ma = -infty<T>;\n\
    \    for (int i = 0; i < n; ++i) {\n      chmax(ma, dat[I[i]][2] - dat[I[i]][1]);\n\
    \      chmin(dp2[2 * i + 1], dp2[2 * i + 2] - ma);\n    }\n    // \u5947\u6570\
    \u500B, suffix \u304B\u3089\u3072\u3068\u3064\u8FFD\u52A0\u3059\u308B\n    T mi\
    \ = infty<T>;\n    for (int i = n - 1; i >= 0; --i) {\n      chmin(mi, dat[I[i]][1]\
    \ - dat[I[i]][0]);\n      chmin(dp2[2 * i + 1], dp2[2 * i] + mi);\n    }\n   \
    \ return;\n  }\n\n  vc<int> restore_2(int k) {\n    auto& I = I2;\n    int n =\
    \ len(I);\n    vc<int> x(N);\n    if (k % 2 == 0) {\n      FOR(i, k / 2) x[I[i]]\
    \ = 2;\n      return x;\n    }\n    pair<T, int> ma = {-infty<T>, -1};\n    FOR(i,\
    \ (k + 1) / 2) {\n      if (chmax(ma.fi, dat[I[i]][2] - dat[I[i]][1])) ma.se =\
    \ I[i];\n    }\n    if (dp2[k] == dp2[k + 1] - ma.fi) {\n      FOR(i, (k + 1)\
    \ / 2) x[I[i]] = 2;\n      x[ma.se]--;\n      return x;\n    }\n    pair<T, int>\
    \ mi = {infty<T>, -1};\n    for (int i = n - 1; i >= k / 2; --i) {\n      if (chmin(mi.fi,\
    \ dat[I[i]][1] - dat[I[i]][0])) mi.se = I[i];\n    }\n    if (dp2[k] == dp2[k\
    \ - 1] + mi.fi) {\n      FOR(i, (k - 1) / 2) x[I[i]] = 2;\n      x[mi.se] = 1;\n\
    \      return x;\n    }\n    assert(0);\n    return x;\n  }\n};\n#line 6 \"test/mytest/minplus_conv_triple.test.cpp\"\
    \n\nvoid test() {\n  FOR(N, 0, 300) {\n    vi A(N), B(N), C(N);\n    FOR(i, N)\
    \ A[i] = RNG(1, 1 << 30);\n    FOR(i, N) B[i] = RNG(1, 1 << 30);\n    FOR(i, N)\
    \ C[i] = RNG(1, 1 << 30);\n    // \u611A\u76F4\n    vi dp(2 * N + 1, infty<ll>);\n\
    \    dp[0] = 0;\n    FOR(i, N) {\n      ll a = A[i], b = B[i], c = C[i];\n   \
    \   vi newdp(2 * N + 1, infty<ll>);\n      FOR(i, len(dp)) {\n        if (i +\
    \ 0 <= 2 * N) chmin(newdp[i + 0], dp[i] + a);\n        if (i + 1 <= 2 * N) chmin(newdp[i\
    \ + 1], dp[i] + b);\n        if (i + 2 <= 2 * N) chmin(newdp[i + 2], dp[i] + c);\n\
    \      }\n      swap(dp, newdp);\n    }\n\n    MinPlus_Convolution_of_Triples<ll>\
    \ X;\n    FOR(i, N) X.add(A[i], B[i], C[i]);\n    X.solve();\n    FOR(K, 2 * N\
    \ + 1) {\n      ll val = X[K];\n      vc<int> x = X.restore(K);\n      assert(SUM<int>(x)\
    \ == K);\n      ll sm = 0;\n      FOR(i, N) {\n        assert(0 <= x[i] && x[i]\
    \ <= 2);\n        if (x[i] == 0) sm += A[i];\n        if (x[i] == 1) sm += B[i];\n\
    \        if (x[i] == 2) sm += C[i];\n      }\n      assert(sm == val && val ==\
    \ dp[K]);\n    }\n  }\n}\n\nvoid solve() {\n  int a, b;\n  cin >> a >> b;\n  cout\
    \ << a + b << \"\\n\";\n}\n\nsigned main() {\n  test();\n  solve();\n  return\
    \ 0;\n}\n"
  code: "#define PROBLEM \"https://judge.yosupo.jp/problem/aplusb\"\n#include \"my_template.hpp\"\
    \n\n#include \"random/base.hpp\"\n#include \"convex/minplus_convolution_of_triples.hpp\"\
    \n\nvoid test() {\n  FOR(N, 0, 300) {\n    vi A(N), B(N), C(N);\n    FOR(i, N)\
    \ A[i] = RNG(1, 1 << 30);\n    FOR(i, N) B[i] = RNG(1, 1 << 30);\n    FOR(i, N)\
    \ C[i] = RNG(1, 1 << 30);\n    // \u611A\u76F4\n    vi dp(2 * N + 1, infty<ll>);\n\
    \    dp[0] = 0;\n    FOR(i, N) {\n      ll a = A[i], b = B[i], c = C[i];\n   \
    \   vi newdp(2 * N + 1, infty<ll>);\n      FOR(i, len(dp)) {\n        if (i +\
    \ 0 <= 2 * N) chmin(newdp[i + 0], dp[i] + a);\n        if (i + 1 <= 2 * N) chmin(newdp[i\
    \ + 1], dp[i] + b);\n        if (i + 2 <= 2 * N) chmin(newdp[i + 2], dp[i] + c);\n\
    \      }\n      swap(dp, newdp);\n    }\n\n    MinPlus_Convolution_of_Triples<ll>\
    \ X;\n    FOR(i, N) X.add(A[i], B[i], C[i]);\n    X.solve();\n    FOR(K, 2 * N\
    \ + 1) {\n      ll val = X[K];\n      vc<int> x = X.restore(K);\n      assert(SUM<int>(x)\
    \ == K);\n      ll sm = 0;\n      FOR(i, N) {\n        assert(0 <= x[i] && x[i]\
    \ <= 2);\n        if (x[i] == 0) sm += A[i];\n        if (x[i] == 1) sm += B[i];\n\
    \        if (x[i] == 2) sm += C[i];\n      }\n      assert(sm == val && val ==\
    \ dp[K]);\n    }\n  }\n}\n\nvoid solve() {\n  int a, b;\n  cin >> a >> b;\n  cout\
    \ << a + b << \"\\n\";\n}\n\nsigned main() {\n  test();\n  solve();\n  return\
    \ 0;\n}"
  dependsOn:
  - my_template.hpp
  - random/base.hpp
  - convex/minplus_convolution_of_triples.hpp
  - convex/minplus_convolution.hpp
  - convex/monotone_minima.hpp
  isVerificationFile: true
  path: test/mytest/minplus_conv_triple.test.cpp
  requiredBy: []
  timestamp: '2024-08-13 20:27:42+09:00'
  verificationStatus: TEST_WRONG_ANSWER
  verifiedWith: []
documentation_of: test/mytest/minplus_conv_triple.test.cpp
layout: document
redirect_from:
- /verify/test/mytest/minplus_conv_triple.test.cpp
- /verify/test/mytest/minplus_conv_triple.test.cpp.html
title: test/mytest/minplus_conv_triple.test.cpp
---
