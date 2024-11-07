---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: graph/tournament.hpp
    title: graph/tournament.hpp
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
  bundledCode: "#line 1 \"test/1_mytest/tournament.test.cpp\"\n#define PROBLEM \"\
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
    \ others.end()), ...);\n}\n#endif\n#line 3 \"test/1_mytest/tournament.test.cpp\"\
    \n\n#line 2 \"random/base.hpp\"\n\nu64 RNG_64() {\n  static u64 x_ = u64(chrono::duration_cast<chrono::nanoseconds>(chrono::high_resolution_clock::now().time_since_epoch()).count())\
    \ * 10150724397891781847ULL;\n  x_ ^= x_ << 7;\n  return x_ ^= x_ >> 9;\n}\n\n\
    u64 RNG(u64 lim) { return RNG_64() % lim; }\n\nll RNG(ll l, ll r) { return l +\
    \ RNG_64() % (r - l); }\n#line 1 \"graph/tournament.hpp\"\n// https://yukicoder.me/problems/no/2085\n\
    // https://codeforces.com/problemset/problem/412/D\ntemplate <typename F>\nvc<int>\
    \ hamiltonian_path_in_tournament(int n, F check) {\n  auto dfs = [&](auto& dfs,\
    \ int L, int R) -> vc<int> {\n    if (R == L + 1) return {L};\n    int M = (L\
    \ + R) / 2;\n    vc<int> X = dfs(dfs, L, M);\n    vc<int> Y = dfs(dfs, M, R);\n\
    \    vc<int> P;\n    P.reserve(R - L);\n    int i = 0, j = 0;\n    while (len(P)\
    \ < R - L) {\n      if (i == len(X)) { P.eb(Y[j++]); }\n      elif (j == len(Y))\
    \ { P.eb(X[i++]); }\n      else {\n        if (check(X[i], Y[j])) {\n        \
    \  P.eb(X[i++]);\n        } else {\n          P.eb(Y[j++]);\n        }\n     \
    \ }\n    }\n    return P;\n  };\n  return dfs(dfs, 0, n);\n}\n\n// https://atcoder.jp/contests/joisp2024/tasks/joisp2024_l\n\
    vc<string> from_outdegrees(vc<int> A) {\n  int N = len(A);\n  vc<int> F(N);\n\
    \  for (auto& x: A) F[x]++;\n\n  vc<string> ANS(N, string(N, '-'));\n  FOR(i,\
    \ N) {\n    int lose = N - 1 - i - A[i];\n    F[A[i]]--;\n    FOR(j, i + 1, N)\
    \ { ANS[i][j] = '1', ANS[j][i] = '0'; }\n    int p = N;\n    FOR_R(x, N) {\n \
    \     int k = min(lose, F[x]);\n      p -= F[x];\n      FOR(j, p, p + k) { ANS[i][j]\
    \ = '0', ANS[j][i] = '1'; }\n      lose -= k;\n    }\n    FOR(j, i + 1, N) {\n\
    \      if (ANS[i][j] == '0') {\n        F[A[j]]--;\n        A[j]--;\n        F[A[j]]++;\n\
    \      }\n    }\n  }\n  return ANS;\n}\n#line 6 \"test/1_mytest/tournament.test.cpp\"\
    \n\nvoid test() {\n  auto gen = [&](int N) -> vvc<bool> {\n    vv(bool, mat, N,\
    \ N);\n    FOR(i, N) FOR(j, i) {\n      bool b = RNG(0, 2);\n      if (b) mat[i][j]\
    \ = 1;\n      if (!b) mat[j][i] = 1;\n    }\n    return mat;\n  };\n\n  FOR(10)\
    \ {\n    FOR(N, 1, 20) {\n      auto G = gen(N);\n      auto check = [&](int i,\
    \ int j) -> bool { return G[i][j]; };\n      auto P = hamiltonian_path_in_tournament(N,\
    \ check);\n      vc<bool> use(N);\n      for (auto&& x: P) use[x] = 1;\n     \
    \ assert(len(P) == N);\n      assert(SUM<int>(use) == N);\n      FOR(i, N - 1)\
    \ {\n        ll a = P[i], b = P[i + 1];\n        assert(G[a][b]);\n      }\n \
    \   }\n  }\n}\n\nvoid solve() {\n  int a, b;\n  cin >> a >> b;\n  cout << a +\
    \ b << \"\\n\";\n}\n\nsigned main() {\n  test();\n  solve();\n\n  return 0;\n\
    }\n"
  code: "#define PROBLEM \"https://judge.yosupo.jp/problem/aplusb\"\n#include \"my_template.hpp\"\
    \n\n#include \"random/base.hpp\"\n#include \"graph/tournament.hpp\"\n\nvoid test()\
    \ {\n  auto gen = [&](int N) -> vvc<bool> {\n    vv(bool, mat, N, N);\n    FOR(i,\
    \ N) FOR(j, i) {\n      bool b = RNG(0, 2);\n      if (b) mat[i][j] = 1;\n   \
    \   if (!b) mat[j][i] = 1;\n    }\n    return mat;\n  };\n\n  FOR(10) {\n    FOR(N,\
    \ 1, 20) {\n      auto G = gen(N);\n      auto check = [&](int i, int j) -> bool\
    \ { return G[i][j]; };\n      auto P = hamiltonian_path_in_tournament(N, check);\n\
    \      vc<bool> use(N);\n      for (auto&& x: P) use[x] = 1;\n      assert(len(P)\
    \ == N);\n      assert(SUM<int>(use) == N);\n      FOR(i, N - 1) {\n        ll\
    \ a = P[i], b = P[i + 1];\n        assert(G[a][b]);\n      }\n    }\n  }\n}\n\n\
    void solve() {\n  int a, b;\n  cin >> a >> b;\n  cout << a + b << \"\\n\";\n}\n\
    \nsigned main() {\n  test();\n  solve();\n\n  return 0;\n}"
  dependsOn:
  - my_template.hpp
  - random/base.hpp
  - graph/tournament.hpp
  isVerificationFile: true
  path: test/1_mytest/tournament.test.cpp
  requiredBy: []
  timestamp: '2024-11-07 04:20:47+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: test/1_mytest/tournament.test.cpp
layout: document
redirect_from:
- /verify/test/1_mytest/tournament.test.cpp
- /verify/test/1_mytest/tournament.test.cpp.html
title: test/1_mytest/tournament.test.cpp
---
