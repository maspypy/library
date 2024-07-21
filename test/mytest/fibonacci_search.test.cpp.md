---
data:
  _extendedDependsOn:
  - icon: ':question:'
    path: enumerate/product.hpp
    title: enumerate/product.hpp
  - icon: ':question:'
    path: my_template.hpp
    title: my_template.hpp
  - icon: ':x:'
    path: other/fibonacci_search.hpp
    title: other/fibonacci_search.hpp
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
  bundledCode: "#line 1 \"test/mytest/fibonacci_search.test.cpp\"\n#define PROBLEM\
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
    \ greater<T>>;\n\n#define vv(type, name, h, ...) \\\n  vector<vector<type>> name(h,\
    \ vector<type>(__VA_ARGS__))\n#define vvv(type, name, h, w, ...)   \\\n  vector<vector<vector<type>>>\
    \ name( \\\n      h, vector<vector<type>>(w, vector<type>(__VA_ARGS__)))\n#define\
    \ vvvv(type, name, a, b, c, ...)       \\\n  vector<vector<vector<vector<type>>>>\
    \ name( \\\n      a, vector<vector<vector<type>>>(       \\\n             b, vector<vector<type>>(c,\
    \ vector<type>(__VA_ARGS__))))\n\n// https://trap.jp/post/1224/\n#define FOR1(a)\
    \ for (ll _ = 0; _ < ll(a); ++_)\n#define FOR2(i, a) for (ll i = 0; i < ll(a);\
    \ ++i)\n#define FOR3(i, a, b) for (ll i = a; i < ll(b); ++i)\n#define FOR4(i,\
    \ a, b, c) for (ll i = a; i < ll(b); i += (c))\n#define FOR1_R(a) for (ll i =\
    \ (a)-1; i >= ll(0); --i)\n#define FOR2_R(i, a) for (ll i = (a)-1; i >= ll(0);\
    \ --i)\n#define FOR3_R(i, a, b) for (ll i = (b)-1; i >= ll(a); --i)\n#define overload4(a,\
    \ b, c, d, e, ...) e\n#define overload3(a, b, c, d, ...) d\n#define FOR(...) overload4(__VA_ARGS__,\
    \ FOR4, FOR3, FOR2, FOR1)(__VA_ARGS__)\n#define FOR_R(...) overload3(__VA_ARGS__,\
    \ FOR3_R, FOR2_R, FOR1_R)(__VA_ARGS__)\n\n#define FOR_subset(t, s) \\\n  for (ll\
    \ t = (s); t >= 0; t = (t == 0 ? -1 : (t - 1) & (s)))\n#define all(x) x.begin(),\
    \ x.end()\n#define len(x) ll(x.size())\n#define elif else if\n\n#define eb emplace_back\n\
    #define mp make_pair\n#define mt make_tuple\n#define fi first\n#define se second\n\
    \n#define stoi stoll\n\nint popcnt(int x) { return __builtin_popcount(x); }\n\
    int popcnt(u32 x) { return __builtin_popcount(x); }\nint popcnt(ll x) { return\
    \ __builtin_popcountll(x); }\nint popcnt(u64 x) { return __builtin_popcountll(x);\
    \ }\nint popcnt_mod_2(int x) { return __builtin_parity(x); }\nint popcnt_mod_2(u32\
    \ x) { return __builtin_parity(x); }\nint popcnt_mod_2(ll x) { return __builtin_parityll(x);\
    \ }\nint popcnt_mod_2(u64 x) { return __builtin_parityll(x); }\n// (0, 1, 2, 3,\
    \ 4) -> (-1, 0, 1, 1, 2)\nint topbit(int x) { return (x == 0 ? -1 : 31 - __builtin_clz(x));\
    \ }\nint topbit(u32 x) { return (x == 0 ? -1 : 31 - __builtin_clz(x)); }\nint\
    \ topbit(ll x) { return (x == 0 ? -1 : 63 - __builtin_clzll(x)); }\nint topbit(u64\
    \ x) { return (x == 0 ? -1 : 63 - __builtin_clzll(x)); }\n// (0, 1, 2, 3, 4) ->\
    \ (-1, 0, 1, 0, 2)\nint lowbit(int x) { return (x == 0 ? -1 : __builtin_ctz(x));\
    \ }\nint lowbit(u32 x) { return (x == 0 ? -1 : __builtin_ctz(x)); }\nint lowbit(ll\
    \ x) { return (x == 0 ? -1 : __builtin_ctzll(x)); }\nint lowbit(u64 x) { return\
    \ (x == 0 ? -1 : __builtin_ctzll(x)); }\n\ntemplate <typename T>\nT floor(T a,\
    \ T b) {\n  return a / b - (a % b && (a ^ b) < 0);\n}\ntemplate <typename T>\n\
    T ceil(T x, T y) {\n  return floor(x + y - 1, y);\n}\ntemplate <typename T>\n\
    T bmod(T x, T y) {\n  return x - y * floor(x, y);\n}\ntemplate <typename T>\n\
    pair<T, T> divmod(T x, T y) {\n  T q = floor(x, y);\n  return {q, x - q * y};\n\
    }\n\ntemplate <typename T, typename U>\nT SUM(const vector<U> &A) {\n  T sm =\
    \ 0;\n  for (auto &&a: A) sm += a;\n  return sm;\n}\n\n#define MIN(v) *min_element(all(v))\n\
    #define MAX(v) *max_element(all(v))\n#define LB(c, x) distance((c).begin(), lower_bound(all(c),\
    \ (x)))\n#define UB(c, x) distance((c).begin(), upper_bound(all(c), (x)))\n#define\
    \ UNIQUE(x) \\\n  sort(all(x)), x.erase(unique(all(x)), x.end()), x.shrink_to_fit()\n\
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
    \ vector<T> &A) {\n  vector<int> ids(len(A));\n  iota(all(ids), 0);\n  sort(all(ids),\n\
    \       [&](int i, int j) { return (A[i] == A[j] ? i < j : A[i] < A[j]); });\n\
    \  return ids;\n}\n\n// A[I[0]], A[I[1]], ...\ntemplate <typename T>\nvc<T> rearrange(const\
    \ vc<T> &A, const vc<int> &I) {\n  vc<T> B(len(I));\n  FOR(i, len(I)) B[i] = A[I[i]];\n\
    \  return B;\n}\n#endif\n#line 1 \"other/fibonacci_search.hpp\"\n// returns: {fx,\
    \ x}\n// [L, R) \u3067\u306E\u6975\u5C0F\u5024\u3092\u3072\u3068\u3064\u6C42\u3081\
    \u308B\u3001\u5358\u5CF0\u306F\u4E0D\u8981\ntemplate <typename T, bool MINIMIZE,\
    \ typename F>\npair<T, ll> fibonacci_search(F f, ll L, ll R) {\n  assert(L < R);\n\
    \  --R;\n  ll a = L, b = L + 1, c = L + 2, d = L + 3;\n  int n = 0;\n  while (d\
    \ < R) { b = c, c = d, d = b + c - a, ++n; }\n  auto get = [&](ll x) -> T {\n\
    \    if (R < x) return infty<T>;\n    return (MINIMIZE ? f(x) : -f(x));\n  };\n\
    \  T ya = get(a), yb = get(b), yc = get(c), yd = get(d);\n  // \u3053\u306E\u4E2D\
    \u3067\u6975\u5C0F\u306A\u3089\u3070\u5168\u4F53\u3067\u3082\u6975\u5C0F\u3001\
    \u3092\u7DAD\u6301\u3059\u308B\n  FOR(n) {\n    if (yb <= yc) {\n      d = c,\
    \ c = b, b = a + d - c;\n      yd = yc, yc = yb, yb = get(b);\n    } else {\n\
    \      a = b, b = c, c = a + d - b;\n      ya = yb, yb = yc, yc = get(c);\n  \
    \  }\n  }\n  ll x = a;\n  T y = ya;\n  if (chmin(y, yb)) x = b;\n  if (chmin(y,\
    \ yc)) x = c;\n  if (chmin(y, yd)) x = d;\n  if (MINIMIZE) return {y, x};\n  return\
    \ {-y, x};\n}\n#line 1 \"enumerate/product.hpp\"\n// [0, A0) x [0, A1) x ...\n\
    template <typename F>\nvoid enumerate_product(vc<int> A, F query) {\n  int N =\
    \ len(A);\n  auto dfs = [&](auto& dfs, vc<int>& p) -> void {\n    int n = len(p);\n\
    \    if (n == N) return query(p);\n    FOR(x, A[n]) {\n      p.eb(x);\n      dfs(dfs,\
    \ p);\n      p.pop_back();\n    }\n  };\n  vc<int> p;\n  dfs(dfs, p);\n}\n#line\
    \ 5 \"test/mytest/fibonacci_search.test.cpp\"\n\nvoid test() {\n  // permutation\n\
    \  FOR(N, 1, 10) {\n    vc<int> A(N);\n    iota(all(A), 0);\n    do {\n      auto\
    \ f = [&](int i) -> int { return A[i]; };\n      auto [y, i] = fibonacci_search<int,\
    \ true>(f, 0, N);\n      assert(0 <= i && i < N);\n      if (0 < i) assert(A[i]\
    \ < A[i - 1]);\n      if (i + 1 < N) assert(A[i] < A[i + 1]);\n    } while (next_permutation(all(A)));\n\
    \  }\n  // [0,1]\n  FOR(N, 1, 18) {\n    FOR(s, 1 << N) {\n      vc<int> A(N);\n\
    \      FOR(i, N) A[i] = s >> i & 1;\n      auto f = [&](int i) -> int { return\
    \ A[i]; };\n      auto [y, i] = fibonacci_search<int, true>(f, 0, N);\n      assert(0\
    \ <= i && i < N);\n      if (0 < i) assert(A[i] <= A[i - 1]);\n      if (i + 1\
    \ < N) assert(A[i] <= A[i + 1]);\n    }\n  }\n  // [0,1,2]\n  FOR(N, 1, 13) {\n\
    \    enumerate_product(vc<int>(N, 3), [&](vc<int> A) -> void {\n      auto f =\
    \ [&](int i) -> int { return A[i]; };\n      auto [y, i] = fibonacci_search<int,\
    \ true>(f, 0, N);\n      assert(0 <= i && i < N);\n      if (0 < i) assert(A[i]\
    \ <= A[i - 1]);\n      if (i + 1 < N) assert(A[i] <= A[i + 1]);\n    });\n  }\n\
    }\n\nvoid solve() {\n  int a, b;\n  cin >> a >> b;\n  cout << a + b << \"\\n\"\
    ;\n}\n\nsigned main() {\n  test();\n  solve();\n  return 0;\n}\n"
  code: "#define PROBLEM \"https://judge.yosupo.jp/problem/aplusb\"\n#include \"my_template.hpp\"\
    \n#include \"other/fibonacci_search.hpp\"\n#include \"enumerate/product.hpp\"\n\
    \nvoid test() {\n  // permutation\n  FOR(N, 1, 10) {\n    vc<int> A(N);\n    iota(all(A),\
    \ 0);\n    do {\n      auto f = [&](int i) -> int { return A[i]; };\n      auto\
    \ [y, i] = fibonacci_search<int, true>(f, 0, N);\n      assert(0 <= i && i < N);\n\
    \      if (0 < i) assert(A[i] < A[i - 1]);\n      if (i + 1 < N) assert(A[i] <\
    \ A[i + 1]);\n    } while (next_permutation(all(A)));\n  }\n  // [0,1]\n  FOR(N,\
    \ 1, 18) {\n    FOR(s, 1 << N) {\n      vc<int> A(N);\n      FOR(i, N) A[i] =\
    \ s >> i & 1;\n      auto f = [&](int i) -> int { return A[i]; };\n      auto\
    \ [y, i] = fibonacci_search<int, true>(f, 0, N);\n      assert(0 <= i && i < N);\n\
    \      if (0 < i) assert(A[i] <= A[i - 1]);\n      if (i + 1 < N) assert(A[i]\
    \ <= A[i + 1]);\n    }\n  }\n  // [0,1,2]\n  FOR(N, 1, 13) {\n    enumerate_product(vc<int>(N,\
    \ 3), [&](vc<int> A) -> void {\n      auto f = [&](int i) -> int { return A[i];\
    \ };\n      auto [y, i] = fibonacci_search<int, true>(f, 0, N);\n      assert(0\
    \ <= i && i < N);\n      if (0 < i) assert(A[i] <= A[i - 1]);\n      if (i + 1\
    \ < N) assert(A[i] <= A[i + 1]);\n    });\n  }\n}\n\nvoid solve() {\n  int a,\
    \ b;\n  cin >> a >> b;\n  cout << a + b << \"\\n\";\n}\n\nsigned main() {\n  test();\n\
    \  solve();\n  return 0;\n}\n"
  dependsOn:
  - my_template.hpp
  - other/fibonacci_search.hpp
  - enumerate/product.hpp
  isVerificationFile: true
  path: test/mytest/fibonacci_search.test.cpp
  requiredBy: []
  timestamp: '2024-07-21 16:21:08+09:00'
  verificationStatus: TEST_WRONG_ANSWER
  verifiedWith: []
documentation_of: test/mytest/fibonacci_search.test.cpp
layout: document
redirect_from:
- /verify/test/mytest/fibonacci_search.test.cpp
- /verify/test/mytest/fibonacci_search.test.cpp.html
title: test/mytest/fibonacci_search.test.cpp
---
