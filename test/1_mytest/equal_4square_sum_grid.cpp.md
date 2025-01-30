---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: linalg/transpose.hpp
    title: linalg/transpose.hpp
  - icon: ':heavy_check_mark:'
    path: my_template.hpp
    title: my_template.hpp
  - icon: ':warning:'
    path: other/equal_4square_sum_grid.hpp
    title: other/equal_4square_sum_grid.hpp
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':warning:'
  attributes:
    links:
    - https://judge.yosupo.jp/problem/aplusb
  bundledCode: "#line 1 \"test/1_mytest/equal_4square_sum_grid.cpp\"\n#define PROBLEM\
    \ \"https://judge.yosupo.jp/problem/aplusb\"\n#line 1 \"my_template.hpp\"\n#if\
    \ defined(LOCAL)\n#include <my_template_compiled.hpp>\n#else\n\n// https://codeforces.com/blog/entry/96344\n\
    // https://codeforces.com/blog/entry/126772?#comment-1154880\n#include <bits/allocator.h>\n\
    #pragma GCC optimize(\"Ofast,unroll-loops\")\n#pragma GCC target(\"avx2,popcnt\"\
    )\n#include <bits/stdc++.h>\n\nusing namespace std;\n\nusing ll = long long;\n\
    using u8 = uint8_t;\nusing u16 = uint16_t;\nusing u32 = uint32_t;\nusing u64 =\
    \ uint64_t;\nusing i128 = __int128;\nusing u128 = unsigned __int128;\nusing f128\
    \ = __float128;\n\ntemplate <class T>\nconstexpr T infty = 0;\ntemplate <>\nconstexpr\
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
    \ others.begin(), others.end()), ...);\n}\n#endif\n#line 3 \"test/1_mytest/equal_4square_sum_grid.cpp\"\
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
    \ 4 * n) reverse(all(A[x])); }\n  return A;\n}\n#line 6 \"test/1_mytest/equal_4square_sum_grid.cpp\"\
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
  isVerificationFile: false
  path: test/1_mytest/equal_4square_sum_grid.cpp
  requiredBy: []
  timestamp: '2025-01-27 19:24:29+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: test/1_mytest/equal_4square_sum_grid.cpp
layout: document
redirect_from:
- /library/test/1_mytest/equal_4square_sum_grid.cpp
- /library/test/1_mytest/equal_4square_sum_grid.cpp.html
title: test/1_mytest/equal_4square_sum_grid.cpp
---
