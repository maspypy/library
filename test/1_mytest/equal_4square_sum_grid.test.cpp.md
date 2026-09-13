---
data:
  _extendedDependsOn:
  - icon: ':question:'
    path: linalg/transpose.hpp
    title: linalg/transpose.hpp
  - icon: ':question:'
    path: my_template.hpp
    title: my_template.hpp
  - icon: ':heavy_check_mark:'
    path: other/equal_4square_sum_grid.hpp
    title: other/equal_4square_sum_grid.hpp
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
  bundledCode: "#line 1 \"test/1_mytest/equal_4square_sum_grid.test.cpp\"\n#define\
    \ PROBLEM \"https://judge.yosupo.jp/problem/aplusb\"\n#line 1 \"my_template.hpp\"\
    \n#if defined(USE_PCH)\n#include <my_template_compiled.hpp>\n#else\n#if defined(__GNUC__)\n\
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
    \ abs(a);\n}\n#endif\n#line 3 \"test/1_mytest/equal_4square_sum_grid.test.cpp\"\
    \n\n#line 1 \"linalg/transpose.hpp\"\ntemplate <typename VC>\nvc<VC> transpose(const\
    \ vc<VC>& A, int H = -1, int W = -1) {\n  if (H == -1) { H = len(A), W = (len(A)\
    \ == 0 ? 0 : len(A[0])); }\n  vc<VC> B(W, VC(H, 0));\n  FOR(x, H) FOR(y, W) B[y][x]\
    \ = A[x][y];\n  return B;\n}\n#line 1 \"other/equal_4square_sum_grid.hpp\"\n\n\
    // https://atcoder.jp/contests/tupc2023/tasks/tupc2023_k\n// [0,HW-1]\u306E\u9806\
    \u5217\u3067\u3059\u3079\u3066\u306E(2,2)\u6B63\u65B9\u5F62\u306E\u548C\u304C\
    S, \u89E3\u3044\u305F\u5834\u5408.\n// \u4E00\u822C\u306B\u89E3\u3044\u305F\u308F\
    \u3051\u3067\u306F\u306A\u3044. mod HW \u3067\u306F\u89E3\u3051\u3066\u3044\u308B\
    .\n// (even,even) \u306F S \u304C\u78BA\u5B9A. \u4ED6\u306F\u5FAE\u8ABF\u6574\u306F\
    \u3067\u304D\u308B\u3068\u3044\u3046\u611F\u3058.\nvvc<int> equal_4square_sum_grid(int\
    \ H, int W, int S) {\n  assert(H >= 2 && W >= 2);\n  int S0 = (H * W - 1) * 2;\n\
    \  if (H % 2 == 1 && W % 2 == 0) {\n    vvc<int> A = equal_4square_sum_grid(W,\
    \ H, S);\n    A = transpose(A);\n    return A;\n  }\n  // \u89E3\u3044\u3066\u3044\
    \u306A\u3044\u5834\u5408\n  if (H % 2 == 0 && W % 2 == 0) assert(S0 - 3 <= S &&\
    \ S <= S0 + 3);\n  if (W % 2 == 1 && H % 4 == 2) { assert(S0 - 1 <= S && S <=\
    \ S0 + 1); }\n  if (W % 2 == 1 && H % 4 == 0) { assert(S0 - 2 <= S && S <= S0\
    \ + 2); }\n\n  if (S == S0 + 1 || S == S0 - 2) {\n    vvc<int> A = equal_4square_sum_grid(H,\
    \ W, 2 * S0 - S);\n    FOR(x, H) FOR(y, W) A[x][y] = H * W - 1 - A[x][y];\n  \
    \  return A;\n  }\n\n  if (S == S0) {\n    vv(int, A, H, W);\n    FOR(j, W) A[j\
    \ % 2][j] = j, A[(j + 1) % 2][j] = H * W - 1 - j;\n    FOR(i, 2, H) FOR(j, W)\
    \ {\n      if ((i + j) % 2 == 0) A[i][j] = A[i - 2][j] + W;\n      if ((i + j)\
    \ % 2 == 1) A[i][j] = A[i - 2][j] - W;\n    }\n    return A;\n  }\n  if (H % 2\
    \ == 0 && W % 2 == 0) return {}; // \u89E3\u306A\u3057\n  if (S == S0 - 1) {\n\
    \    vv(int, A, H, W);\n    auto nxt = [&](int p) -> int { return (p >= H * W\
    \ / 2 ? H * W - 1 - p : H * W - 2 - p); };\n    int p = H * W - 1;\n    FOR(x,\
    \ H) FOR(y, W) { A[x][y] = p, p = nxt(p); }\n    return A;\n  }\n  assert(W %\
    \ 2 == 1 && H % 4 == 0 && S == S0 + 2);\n  int n = H / 4;\n  vc<int> tmp;\n  FOR(i,\
    \ 2 * n * W) {\n    if (i % 2 == 0) tmp.eb(2 * i);\n    if (i % 2 == 1) tmp.eb(H\
    \ * W - 2 * i);\n  }\n  FOR(i, n * W) {\n    if (i % 2 == 0) tmp.eb(2 * i + 1);\n\
    \    if (i % 2 == 1) tmp.eb(H * W - 2 * i - 1);\n  }\n  FOR(i, 3 * n * W, 4 *\
    \ n * W) { tmp.eb(H * W - tmp[i - n * W]); }\n  int p = 0;\n  vv(int, A, H, W);\n\
    \  FOR(x, H) FOR(y, W) A[x][y] = tmp[p++];\n  if (n % 2 == 0) { FOR(x, 3 * n,\
    \ 4 * n) reverse(all(A[x])); }\n  return A;\n}\n#line 6 \"test/1_mytest/equal_4square_sum_grid.test.cpp\"\
    \n\nvoid test() {\n  FOR(H, 2, 20) {\n    FOR(W, 2, 20) {\n      if (H % 2 ==\
    \ 1 && W % 2 == 0) continue;\n      int S0 = 2 * (H * W - 1);\n      int L = S0,\
    \ R = S0;\n      if (H % 2 == 0 && W % 2 == 0) { L = S0, R = S0; }\n      if (H\
    \ % 4 == 2 && W % 2 == 1) { L = S0 - 1, R = S0 + 1; }\n      if (H % 4 == 0 &&\
    \ W % 2 == 1) { L = S0 - 2, R = S0 + 2; }\n      FOR(S, L, R + 1) {\n        vvc<int>\
    \ A = equal_4square_sum_grid(H, W, S);\n        assert(len(A) == H && len(A[0])\
    \ == W);\n        vc<int> used(H * W);\n        FOR(x, H) FOR(y, W) used[A[x][y]]++;\n\
    \        assert(MIN(used) == 1 && MAX(used) == 1);\n        FOR(x, H - 1) FOR(y,\
    \ W - 1) { assert(A[x][y] + A[x][y + 1] + A[x + 1][y] + A[x + 1][y + 1] == S);\
    \ }\n      }\n    }\n  }\n}\n\nvoid solve() {\n  int x, y;\n  cin >> x >> y;\n\
    \  cout << x + y << \"\\n\";\n}\n\nsigned main() {\n  test();\n  solve();\n}\n"
  code: "#define PROBLEM \"https://judge.yosupo.jp/problem/aplusb\"\n#include \"my_template.hpp\"\
    \n\n#include \"linalg/transpose.hpp\"\n#include \"other/equal_4square_sum_grid.hpp\"\
    \n\nvoid test() {\n  FOR(H, 2, 20) {\n    FOR(W, 2, 20) {\n      if (H % 2 ==\
    \ 1 && W % 2 == 0) continue;\n      int S0 = 2 * (H * W - 1);\n      int L = S0,\
    \ R = S0;\n      if (H % 2 == 0 && W % 2 == 0) { L = S0, R = S0; }\n      if (H\
    \ % 4 == 2 && W % 2 == 1) { L = S0 - 1, R = S0 + 1; }\n      if (H % 4 == 0 &&\
    \ W % 2 == 1) { L = S0 - 2, R = S0 + 2; }\n      FOR(S, L, R + 1) {\n        vvc<int>\
    \ A = equal_4square_sum_grid(H, W, S);\n        assert(len(A) == H && len(A[0])\
    \ == W);\n        vc<int> used(H * W);\n        FOR(x, H) FOR(y, W) used[A[x][y]]++;\n\
    \        assert(MIN(used) == 1 && MAX(used) == 1);\n        FOR(x, H - 1) FOR(y,\
    \ W - 1) { assert(A[x][y] + A[x][y + 1] + A[x + 1][y] + A[x + 1][y + 1] == S);\
    \ }\n      }\n    }\n  }\n}\n\nvoid solve() {\n  int x, y;\n  cin >> x >> y;\n\
    \  cout << x + y << \"\\n\";\n}\n\nsigned main() {\n  test();\n  solve();\n}\n"
  dependsOn:
  - my_template.hpp
  - linalg/transpose.hpp
  - other/equal_4square_sum_grid.hpp
  isVerificationFile: true
  path: test/1_mytest/equal_4square_sum_grid.test.cpp
  requiredBy: []
  timestamp: '2026-08-29 09:00:39+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: test/1_mytest/equal_4square_sum_grid.test.cpp
layout: document
redirect_from:
- /verify/test/1_mytest/equal_4square_sum_grid.test.cpp
- /verify/test/1_mytest/equal_4square_sum_grid.test.cpp.html
title: test/1_mytest/equal_4square_sum_grid.test.cpp
---
