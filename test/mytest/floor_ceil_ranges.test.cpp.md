---
data:
  _extendedDependsOn:
  - icon: ':x:'
    path: enumerate/ceil_range.hpp
    title: enumerate/ceil_range.hpp
  - icon: ':x:'
    path: enumerate/floor_range.hpp
    title: enumerate/floor_range.hpp
  - icon: ':question:'
    path: my_template.hpp
    title: my_template.hpp
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
  bundledCode: "#line 1 \"test/mytest/floor_ceil_ranges.test.cpp\"\n#define PROBLEM\
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
    \  return B;\n}\n\ntemplate <typename T, typename... Vectors>\nvc<T> concat(vc<T>\
    \ &first, const Vectors &... others) {\n  vc<T> res = first;\n  (res.insert(res.end(),\
    \ others.begin(), others.end()), ...);\n  return res;\n}\n#endif\n#line 1 \"enumerate/ceil_range.hpp\"\
    \n// \u5546\u304C q \u306E\u533A\u9593 [l,r) \u3092 q \u306B\u3064\u3044\u3066\
    \u6607\u9806\ntemplate <typename F>\nvoid ceil_range(ll N, F f) {\n  assert(N\
    \ <= (1LL << 50));\n  ll sq = sqrtl(N);\n  ll prev = infty<ll>;\n  for (int q\
    \ = 1; q <= sq; ++q) {\n    ll x = double(N + q - 1) / q;\n    f(q, x, prev),\
    \ prev = x;\n  }\n  int n = (N <= sq * sq + sq ? sq : sq + 1);\n  if (N == sq\
    \ * sq) --n;\n  for (int l = n; l >= 1; --l) { f(double(N + l - 1) / l, l, l +\
    \ 1); }\n}\n#line 1 \"enumerate/floor_range.hpp\"\n// \u5546\u304C q \u306E\u533A\
    \u9593 [l,r) \u3092 q \u306B\u3064\u3044\u3066\u6607\u9806\r\ntemplate <typename\
    \ F>\r\nvoid floor_range(u64 N, F f) {\r\n  assert(N <= (u64(1) << 50));\r\n \
    \ u64 sq = sqrtl(N);\r\n  u32 n = (sq * sq + sq <= N ? sq : sq - 1);\r\n  u64\
    \ prev = N + 1;\r\n  for (u32 q = 1; q <= n; ++q) {\r\n    u64 x = double(N) /\
    \ (q + 1) + 1;\r\n    f(q, x, prev), prev = x;\r\n  }\r\n  for (u32 l = sq; l\
    \ >= 1; --l) { f(u64(double(N) / l), l, l + 1); }\r\n}\r\n#line 5 \"test/mytest/floor_ceil_ranges.test.cpp\"\
    \n\nvoid test_floor() {\n  using T = tuple<ll, ll, ll>;\n  auto F = [&](ll N)\
    \ -> vc<T> {\n    vc<T> dat;\n    auto f = [&](ll q, ll l, ll r) -> void { dat.eb(q,\
    \ l, r); };\n    floor_range(N, f);\n    return dat;\n  };\n  auto G = [&](ll\
    \ N) -> vc<T> {\n    vvc<ll> tmp(N + 1);\n    FOR(x, 1, N + 1) tmp[floor(N, x)].eb(x);\n\
    \    vc<T> dat;\n    FOR(x, 1, N + 1) {\n      if (len(tmp[x])) {\n        ll\
    \ lo = tmp[x][0];\n        ll hi = tmp[x].back();\n        dat.eb(x, lo, hi +\
    \ 1);\n      }\n    }\n    return dat;\n  };\n  FOR(N, 1, 100) { assert(F(N) ==\
    \ G(N)); }\n}\n\nvoid test_ceil() {\n  using T = tuple<ll, ll, ll>;\n  auto F\
    \ = [&](ll N) -> vc<T> {\n    vc<T> dat;\n    auto f = [&](ll q, ll l, ll r) ->\
    \ void { dat.eb(q, l, r); };\n    ceil_range(N, f);\n    return dat;\n  };\n \
    \ auto G = [&](ll N) -> vc<T> {\n    vvc<ll> tmp(N + 1);\n    FOR(x, 1, N + 1)\
    \ tmp[ceil(N, x)].eb(x);\n    vc<T> dat;\n    FOR(x, 1, N + 1) {\n      if (x\
    \ == 1) {\n        dat.eb(x, N, infty<ll>);\n        continue;\n      }\n    \
    \  if (len(tmp[x])) {\n        ll lo = tmp[x][0];\n        ll hi = tmp[x].back();\n\
    \        dat.eb(x, lo, hi + 1);\n      }\n    }\n    return dat;\n  };\n  FOR(N,\
    \ 1, 100) { assert(F(N) == G(N)); }\n}\n\nvoid solve() {\n  int a, b;\n  cin >>\
    \ a >> b;\n  cout << a + b << \"\\n\";\n}\n\nsigned main() {\n  test_floor();\n\
    \  test_ceil();\n  solve();\n\n  return 0;\n}\n"
  code: "#define PROBLEM \"https://judge.yosupo.jp/problem/aplusb\"\n#include \"my_template.hpp\"\
    \n#include \"enumerate/ceil_range.hpp\"\n#include \"enumerate/floor_range.hpp\"\
    \n\nvoid test_floor() {\n  using T = tuple<ll, ll, ll>;\n  auto F = [&](ll N)\
    \ -> vc<T> {\n    vc<T> dat;\n    auto f = [&](ll q, ll l, ll r) -> void { dat.eb(q,\
    \ l, r); };\n    floor_range(N, f);\n    return dat;\n  };\n  auto G = [&](ll\
    \ N) -> vc<T> {\n    vvc<ll> tmp(N + 1);\n    FOR(x, 1, N + 1) tmp[floor(N, x)].eb(x);\n\
    \    vc<T> dat;\n    FOR(x, 1, N + 1) {\n      if (len(tmp[x])) {\n        ll\
    \ lo = tmp[x][0];\n        ll hi = tmp[x].back();\n        dat.eb(x, lo, hi +\
    \ 1);\n      }\n    }\n    return dat;\n  };\n  FOR(N, 1, 100) { assert(F(N) ==\
    \ G(N)); }\n}\n\nvoid test_ceil() {\n  using T = tuple<ll, ll, ll>;\n  auto F\
    \ = [&](ll N) -> vc<T> {\n    vc<T> dat;\n    auto f = [&](ll q, ll l, ll r) ->\
    \ void { dat.eb(q, l, r); };\n    ceil_range(N, f);\n    return dat;\n  };\n \
    \ auto G = [&](ll N) -> vc<T> {\n    vvc<ll> tmp(N + 1);\n    FOR(x, 1, N + 1)\
    \ tmp[ceil(N, x)].eb(x);\n    vc<T> dat;\n    FOR(x, 1, N + 1) {\n      if (x\
    \ == 1) {\n        dat.eb(x, N, infty<ll>);\n        continue;\n      }\n    \
    \  if (len(tmp[x])) {\n        ll lo = tmp[x][0];\n        ll hi = tmp[x].back();\n\
    \        dat.eb(x, lo, hi + 1);\n      }\n    }\n    return dat;\n  };\n  FOR(N,\
    \ 1, 100) { assert(F(N) == G(N)); }\n}\n\nvoid solve() {\n  int a, b;\n  cin >>\
    \ a >> b;\n  cout << a + b << \"\\n\";\n}\n\nsigned main() {\n  test_floor();\n\
    \  test_ceil();\n  solve();\n\n  return 0;\n}\n"
  dependsOn:
  - my_template.hpp
  - enumerate/ceil_range.hpp
  - enumerate/floor_range.hpp
  isVerificationFile: true
  path: test/mytest/floor_ceil_ranges.test.cpp
  requiredBy: []
  timestamp: '2024-07-22 11:16:29+09:00'
  verificationStatus: TEST_WRONG_ANSWER
  verifiedWith: []
documentation_of: test/mytest/floor_ceil_ranges.test.cpp
layout: document
redirect_from:
- /verify/test/mytest/floor_ceil_ranges.test.cpp
- /verify/test/mytest/floor_ceil_ranges.test.cpp.html
title: test/mytest/floor_ceil_ranges.test.cpp
---
