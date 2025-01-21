---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: convex/maxplus_convolution.hpp
    title: convex/maxplus_convolution.hpp
  - icon: ':heavy_check_mark:'
    path: convex/monotone_minima.hpp
    title: convex/monotone_minima.hpp
  - icon: ':question:'
    path: my_template.hpp
    title: my_template.hpp
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
  bundledCode: "#line 1 \"test/1_mytest/maxplus_concave.test.cpp\"\n#define PROBLEM\
    \ \"https://judge.yosupo.jp/problem/aplusb\"\n#line 1 \"my_template.hpp\"\n#if\
    \ defined(LOCAL)\n#include <my_template_compiled.hpp>\n#else\n\n// https://codeforces.com/blog/entry/96344\n\
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
    \ others.begin(), others.end()), ...);\n}\n#endif\n#line 2 \"random/base.hpp\"\
    \n\nu64 RNG_64() {\n  static u64 x_ = u64(chrono::duration_cast<chrono::nanoseconds>(chrono::high_resolution_clock::now().time_since_epoch()).count())\
    \ * 10150724397891781847ULL;\n  x_ ^= x_ << 7;\n  return x_ ^= x_ >> 9;\n}\n\n\
    u64 RNG(u64 lim) { return RNG_64() % lim; }\n\nll RNG(ll l, ll r) { return l +\
    \ RNG_64() % (r - l); }\n#line 1 \"convex/monotone_minima.hpp\"\n\n// select(i,j,k)\
    \ : (i,j) -> (i,k) \u3092\u884C\u3046\u304B\u3069\u3046\u304B\ntemplate <typename\
    \ F>\nvc<int> monotone_minima(int H, int W, F select) {\n  vc<int> min_col(H);\n\
    \  auto dfs = [&](auto& dfs, int x1, int x2, int y1, int y2) -> void {\n    if\
    \ (x1 == x2) return;\n    int x = (x1 + x2) / 2;\n    int best_y = y1;\n    for\
    \ (int y = y1 + 1; y < y2; ++y) {\n      if (select(x, best_y, y)) best_y = y;\n\
    \    }\n    min_col[x] = best_y;\n    dfs(dfs, x1, x, y1, best_y + 1);\n    dfs(dfs,\
    \ x + 1, x2, best_y, y2);\n  };\n  dfs(dfs, 0, H, 0, W);\n  return min_col;\n\
    }\n#line 2 \"convex/maxplus_convolution.hpp\"\n\ntemplate <typename T>\nvc<T>\
    \ maxplus_convolution_concave_concave(vc<T>& A, vc<T>& B) {\n  int n = len(A),\
    \ m = len(B);\n  if (n == 0 && m == 0) return {};\n  vc<T> C(n + m - 1, -infty<T>);\n\
    \  while (n > 0 && A[n - 1] == -infty<T>) --n;\n  while (m > 0 && B[m - 1] ==\
    \ -infty<T>) --m;\n  if (n == 0 || m == 0) return C;\n  int a = 0, b = 0;\n  while\
    \ (a < n && A[a] == -infty<T>) ++a;\n  while (b < m && B[b] == -infty<T>) ++b;\n\
    \  C[a + b] = A[a] + B[b];\n  for (int i = a + b + 1; i < n + m - 1; ++i) {\n\
    \    if (b == m - 1 || (a != n - 1 && A[a + 1] + B[b] > A[a] + B[b + 1])) {\n\
    \      chmax(C[i], A[++a] + B[b]);\n    } else {\n      chmax(C[i], A[a] + B[++b]);\n\
    \    }\n  }\n  return C;\n}\n\ntemplate <typename T>\nvc<T> maxplus_convolution_arbitrary_concave(vc<T>&\
    \ A, vc<T>& B) {\n  int n = len(A), m = len(B);\n  if (n == 0 && m == 0) return\
    \ {};\n  vc<T> C(n + m - 1, -infty<T>);\n  while (m > 0 && B[m - 1] == -infty<T>)\
    \ --m;\n  if (m == 0) return C;\n  int b = 0;\n  while (b < m && B[b] == -infty<T>)\
    \ ++b;\n\n  auto select = [&](int i, int j, int k) -> bool {\n    if (i < k) return\
    \ false;\n    if (i - j >= m - b) return true;\n    return A[j] + B[b + i - j]\
    \ <= A[k] + B[b + i - k];\n  };\n  vc<int> J = monotone_minima(n + m - b - 1,\
    \ n, select);\n  FOR(i, n + m - b - 1) {\n    T x = A[J[i]], y = B[b + i - J[i]];\n\
    \    if (x > -infty<T> && y > -infty<T>) C[b + i] = x + y;\n  }\n  return C;\n\
    }\n\ntemplate <typename T, bool conA, bool conB>\nvc<T> maxplus_convolution(vc<T>&\
    \ A, vc<T>& B) {\n  static_assert(conA || conB);\n  if constexpr (conA && conB)\
    \ return maxplus_convolution_concave_concave(A, B);\n  if constexpr (conA && !conB)\n\
    \    return maxplus_convolution_arbitrary_concave(B, A);\n  if constexpr (conB\
    \ && !conA)\n    return maxplus_convolution_arbitrary_concave(A, B);\n  return\
    \ {};\n}\n#line 5 \"test/1_mytest/maxplus_concave.test.cpp\"\n\nvc<int> gen(int\
    \ L, int N, int R, bool concave) {\n  vc<int> A(N);\n  FOR(i, N) A[i] = RNG(-100,\
    \ 100);\n  if (!concave) return A;\n  sort(all(A));\n  reverse(all(A));\n  A =\
    \ cumsum<int>(A);\n  FOR(L) A.insert(A.begin(), -infty<int>);\n  FOR(R) A.insert(A.end(),\
    \ -infty<int>);\n  return A;\n}\n\nvc<int> naive(vc<int> A, vc<int> B) {\n  int\
    \ N = len(A), M = len(B);\n  vc<int> C(N + M - 1, -infty<int>);\n  FOR(i, N) FOR(j,\
    \ M) {\n    if (A[i] == -infty<int> || B[j] == -infty<int>) continue;\n    chmax(C[i\
    \ + j], A[i] + B[j]);\n  }\n  return C;\n}\n\nvoid test() {\n  FOR(a1, 5) FOR(b1,\
    \ 1, 10) FOR(c1, 5) {\n    vc<int> A = gen(a1, b1, c1, true);\n    FOR(a2, 5)\
    \ FOR(b2, 1, 10) FOR(c2, 5) {\n      vc<int> B = gen(a2, b2, c2, true);\n    \
    \  vc<int> C = maxplus_convolution<int, 1, 1>(A, B);\n      assert(naive(A, B)\
    \ == C);\n    }\n  }\n  FOR(a1, 5) FOR(b1, 1, 10) FOR(c1, 5) {\n    vc<int> A\
    \ = gen(a1, b1, c1, true);\n    FOR(a2, 5) FOR(b2, 1, 10) FOR(c2, 5) {\n     \
    \ vc<int> B = gen(a2, b2, c2, false);\n      vc<int> C = maxplus_convolution<int,\
    \ 1, false>(A, B);\n      assert(naive(A, B) == C);\n    }\n  }\n}\n\nvoid solve()\
    \ {\n  int a, b;\n  cin >> a >> b;\n  cout << a + b << \"\\n\";\n}\n\nsigned main()\
    \ {\n  test();\n  solve();\n\n  return 0;\n}\n"
  code: "#define PROBLEM \"https://judge.yosupo.jp/problem/aplusb\"\n#include \"my_template.hpp\"\
    \n#include \"random/base.hpp\"\n#include \"convex/maxplus_convolution.hpp\"\n\n\
    vc<int> gen(int L, int N, int R, bool concave) {\n  vc<int> A(N);\n  FOR(i, N)\
    \ A[i] = RNG(-100, 100);\n  if (!concave) return A;\n  sort(all(A));\n  reverse(all(A));\n\
    \  A = cumsum<int>(A);\n  FOR(L) A.insert(A.begin(), -infty<int>);\n  FOR(R) A.insert(A.end(),\
    \ -infty<int>);\n  return A;\n}\n\nvc<int> naive(vc<int> A, vc<int> B) {\n  int\
    \ N = len(A), M = len(B);\n  vc<int> C(N + M - 1, -infty<int>);\n  FOR(i, N) FOR(j,\
    \ M) {\n    if (A[i] == -infty<int> || B[j] == -infty<int>) continue;\n    chmax(C[i\
    \ + j], A[i] + B[j]);\n  }\n  return C;\n}\n\nvoid test() {\n  FOR(a1, 5) FOR(b1,\
    \ 1, 10) FOR(c1, 5) {\n    vc<int> A = gen(a1, b1, c1, true);\n    FOR(a2, 5)\
    \ FOR(b2, 1, 10) FOR(c2, 5) {\n      vc<int> B = gen(a2, b2, c2, true);\n    \
    \  vc<int> C = maxplus_convolution<int, 1, 1>(A, B);\n      assert(naive(A, B)\
    \ == C);\n    }\n  }\n  FOR(a1, 5) FOR(b1, 1, 10) FOR(c1, 5) {\n    vc<int> A\
    \ = gen(a1, b1, c1, true);\n    FOR(a2, 5) FOR(b2, 1, 10) FOR(c2, 5) {\n     \
    \ vc<int> B = gen(a2, b2, c2, false);\n      vc<int> C = maxplus_convolution<int,\
    \ 1, false>(A, B);\n      assert(naive(A, B) == C);\n    }\n  }\n}\n\nvoid solve()\
    \ {\n  int a, b;\n  cin >> a >> b;\n  cout << a + b << \"\\n\";\n}\n\nsigned main()\
    \ {\n  test();\n  solve();\n\n  return 0;\n}\n"
  dependsOn:
  - my_template.hpp
  - random/base.hpp
  - convex/maxplus_convolution.hpp
  - convex/monotone_minima.hpp
  isVerificationFile: true
  path: test/1_mytest/maxplus_concave.test.cpp
  requiredBy: []
  timestamp: '2024-12-26 06:32:57+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: test/1_mytest/maxplus_concave.test.cpp
layout: document
redirect_from:
- /verify/test/1_mytest/maxplus_concave.test.cpp
- /verify/test/1_mytest/maxplus_concave.test.cpp.html
title: test/1_mytest/maxplus_concave.test.cpp
---
