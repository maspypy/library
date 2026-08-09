---
data:
  _extendedDependsOn:
  - icon: ':x:'
    path: enumerate/ceil_range.hpp
    title: enumerate/ceil_range.hpp
  - icon: ':x:'
    path: enumerate/floor_range.hpp
    title: enumerate/floor_range.hpp
  - icon: ':x:'
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
  bundledCode: "#line 1 \"test/1_mytest/floor_ceil_ranges.test.cpp\"\n#define PROBLEM\
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
    \ {\n    ll x = midpoint(ok, ng);\n    if (x == ok || x == ng) break;\n    (check(x)\
    \ ? ok : ng) = x;\n  }\n  return ok;\n}\ntemplate <typename F>\ndouble binary_search_real(F\
    \ check, double ok, double ng, int iter = 100) {\n  FOR(iter) {\n    double x\
    \ = midpoint(ok, ng);\n    (check(x) ? ok : ng) = x;\n  }\n  return midpoint(ok,\
    \ ng);\n}\n\ntemplate <class T, class S>\ninline bool chmax(T &a, const S &b)\
    \ {\n  T c = max<T>(a, b);\n  bool changed = (c != a);\n  a = c;\n  return changed;\n\
    }\ntemplate <class T, class S>\ninline bool chmin(T &a, const S &b) {\n  T c =\
    \ min<T>(a, b);\n  bool changed = (c != a);\n  a = c;\n  return changed;\n}\n\n\
    // ? \u306F -1\nvc<int> s_to_vi(const string &S, char first_char) {\n  vc<int>\
    \ A(S.size());\n  FOR(i, S.size()) { A[i] = (S[i] != '?' ? S[i] - first_char :\
    \ -1); }\n  return A;\n}\n\ntemplate <typename T, typename U>\nvc<T> cumsum(const\
    \ vc<U> &A, int off = 1) {\n  int N = A.size();\n  vc<T> B(N + 1);\n  FOR(i, N)\
    \ { B[i + 1] = B[i] + A[i]; }\n  if (off == 0) B.erase(B.begin());\n  return B;\n\
    }\n\n// stable sort\ntemplate <typename T>\nvc<int> argsort(const vc<T> &A) {\n\
    \  vc<int> ids(len(A));\n  iota(all(ids), 0);\n  sort(all(ids),\n       [&](int\
    \ i, int j) { return (A[i] == A[j] ? i < j : A[i] < A[j]); });\n  return ids;\n\
    }\n\n// A[I[0]], A[I[1]], ...\ntemplate <typename T>\nvc<T> rearrange(const vc<T>\
    \ &A, const vc<int> &I) {\n  vc<T> B(len(I));\n  FOR(i, len(I)) B[i] = A[I[i]];\n\
    \  return B;\n}\n\ntemplate <typename T, typename... Vectors>\nvoid concat(vc<T>\
    \ &first, const Vectors &...others) {\n  first.reserve(first.size() + (others.size()\
    \ + ... + 0));\n  (first.insert(first.end(), others.begin(), others.end()), ...);\n\
    }\n\n// i128\ntemplate <class T, enable_if_t<is_same_v<T, i128>, int> = 0>\nconstexpr\
    \ i128 abs(T x) {\n  return x < 0 ? -x : x;\n}\n\nconstexpr i128 gcd(i128 a, i128\
    \ b) {\n  while (b != 0) {\n    i128 c = a % b;\n    a = b, b = c;\n  }\n  return\
    \ abs(a);\n}\n#endif\n#line 1 \"enumerate/ceil_range.hpp\"\n// \u5546\u304C q\
    \ \u306E\u533A\u9593 [l,r) \u3092 q \u306B\u3064\u3044\u3066\u6607\u9806\ntemplate\
    \ <typename F>\nvoid ceil_range(ll N, F f) {\n  assert(N <= (1LL << 50));\n  ll\
    \ sq = sqrtl(N);\n  ll prev = infty<ll>;\n  for (int q = 1; q <= sq; ++q) {\n\
    \    ll x = (N + q - 1) / q;\n    f(q, x, prev), prev = x;\n  }\n  int n = (N\
    \ <= sq * sq + sq ? sq : sq + 1);\n  if (N == sq * sq) --n;\n  for (int l = n;\
    \ l >= 1; --l) { f((N + l - 1) / l, l, l + 1); }\n}\n#line 1 \"enumerate/floor_range.hpp\"\
    \n// \u5546\u304C q \u306E\u533A\u9593 [l,r) \u3092 q \u306B\u3064\u3044\u3066\
    \u6607\u9806\r\ntemplate <typename F>\r\nvoid floor_range(u64 N, F f, bool Q_ASC\
    \ = true, bool INCLUDE_Q_IS_0 = false) {\r\n  u64 sq = sqrtl(N);\r\n  u32 n =\
    \ (sq * sq + sq <= N ? sq : sq - 1);\r\n  if (Q_ASC) {\r\n    if (INCLUDE_Q_IS_0)\
    \ f(0, N + 1, infty<ll>);\r\n    for (u32 q = 1; q <= n; ++q) { f(q, N / (q +\
    \ 1) + 1, N / q + 1); }\r\n    for (u32 l = sq; l >= 1; --l) { f(N / l, l, l +\
    \ 1); }\r\n  } else {\r\n    for (u32 l = 1; l <= sq; ++l) { f(N / l, l, l + 1);\
    \ }\r\n    for (u32 q = n; q >= 1; --q) { f(q, N / (q + 1) + 1, N / q + 1); }\r\
    \n    if (INCLUDE_Q_IS_0) f(0, N + 1, infty<ll>);\r\n  }\r\n}\r\n#line 5 \"test/1_mytest/floor_ceil_ranges.test.cpp\"\
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
  path: test/1_mytest/floor_ceil_ranges.test.cpp
  requiredBy: []
  timestamp: '2026-08-10 06:35:00+09:00'
  verificationStatus: TEST_WRONG_ANSWER
  verifiedWith: []
documentation_of: test/1_mytest/floor_ceil_ranges.test.cpp
layout: document
redirect_from:
- /verify/test/1_mytest/floor_ceil_ranges.test.cpp
- /verify/test/1_mytest/floor_ceil_ranges.test.cpp.html
title: test/1_mytest/floor_ceil_ranges.test.cpp
---
