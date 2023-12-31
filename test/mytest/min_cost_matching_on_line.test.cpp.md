---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: convex/slope.hpp
    title: convex/slope.hpp
  - icon: ':heavy_check_mark:'
    path: flow/min_cost_matching_on_line.hpp
    title: flow/min_cost_matching_on_line.hpp
  - icon: ':heavy_check_mark:'
    path: my_template.hpp
    title: my_template.hpp
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: https://judge.yosupo.jp/problem/aplusb
    links:
    - https://atcoder.jp/contests/kupc2016/tasks/kupc2016_h
    - https://judge.yosupo.jp/problem/aplusb
  bundledCode: "#line 1 \"test/mytest/min_cost_matching_on_line.test.cpp\"\n#define\
    \ PROBLEM \"https://judge.yosupo.jp/problem/aplusb\"\n#line 1 \"my_template.hpp\"\
    \n#if defined(LOCAL)\n#include <my_template_compiled.hpp>\n#else\n#pragma GCC\
    \ optimize(\"Ofast\")\n#pragma GCC optimize(\"unroll-loops\")\n\n#include <bits/stdc++.h>\n\
    \nusing namespace std;\n\nusing ll = long long;\nusing u32 = unsigned int;\nusing\
    \ u64 = unsigned long long;\nusing i128 = __int128;\nusing u128 = unsigned __int128;\n\
    using f128 = __float128;\n\ntemplate <class T>\nconstexpr T infty = 0;\ntemplate\
    \ <>\nconstexpr int infty<int> = 1'000'000'000;\ntemplate <>\nconstexpr ll infty<ll>\
    \ = ll(infty<int>) * infty<int> * 2;\ntemplate <>\nconstexpr u32 infty<u32> =\
    \ infty<int>;\ntemplate <>\nconstexpr u64 infty<u64> = infty<ll>;\ntemplate <>\n\
    constexpr i128 infty<i128> = i128(infty<ll>) * infty<ll>;\ntemplate <>\nconstexpr\
    \ double infty<double> = infty<ll>;\ntemplate <>\nconstexpr long double infty<long\
    \ double> = infty<ll>;\n\nusing pi = pair<ll, ll>;\nusing vi = vector<ll>;\ntemplate\
    \ <class T>\nusing vc = vector<T>;\ntemplate <class T>\nusing vvc = vector<vc<T>>;\n\
    template <class T>\nusing vvvc = vector<vvc<T>>;\ntemplate <class T>\nusing vvvvc\
    \ = vector<vvvc<T>>;\ntemplate <class T>\nusing vvvvvc = vector<vvvvc<T>>;\ntemplate\
    \ <class T>\nusing pq = priority_queue<T>;\ntemplate <class T>\nusing pqg = priority_queue<T,\
    \ vector<T>, greater<T>>;\n\n#define vv(type, name, h, ...) \\\n  vector<vector<type>>\
    \ name(h, vector<type>(__VA_ARGS__))\n#define vvv(type, name, h, w, ...)   \\\n\
    \  vector<vector<vector<type>>> name( \\\n      h, vector<vector<type>>(w, vector<type>(__VA_ARGS__)))\n\
    #define vvvv(type, name, a, b, c, ...)       \\\n  vector<vector<vector<vector<type>>>>\
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
    \  return B;\n}\n#endif\n#line 1 \"convex/slope.hpp\"\nstruct Slope_Trick {\r\n\
    \  static constexpr ll LMIN = -infty<ll>;\r\n  static constexpr ll RMAX = infty<ll>;\r\
    \n  pq<ll> que_l;\r\n  pqg<ll> que_r;\r\n\r\n  ll add_l, add_r;\r\n  i128 min_f;\
    \ // infty \u3092\u8DB3\u3057\u5F15\u304D\u3057\u3066\u3082\u58CA\u308C\u306A\u3044\
    \u3088\u3046\u306B i128 \u306B\u3059\u308B\r\n\r\n  Slope_Trick() : add_l(0),\
    \ add_r(0), min_f(0) {}\r\n  Slope_Trick(vc<ll> left, vc<ll> right)\r\n      :\
    \ que_l(all(left)), que_r(all(right)), add_l(0), add_r(0), min_f(0) {}\r\n\r\n\
    \  int size() { return len(que_l) + len(que_r); }\r\n  tuple<ll, ll, i128> get_min()\
    \ { return {top_L(), top_R(), min_f}; }\r\n\r\n  void add_const(ll a) { min_f\
    \ += a; }\r\n\r\n  // O(|a| log N)\r\n  void add_linear(ll a, ll b) {\r\n    min_f\
    \ += b;\r\n    FOR(max<int>(a, 0)) {\r\n      ll x = pop_L();\r\n      min_f +=\
    \ x;\r\n      push_R(x);\r\n    }\r\n    FOR(max<int>(-a, 0)) {\r\n      ll x\
    \ = pop_R();\r\n      min_f -= x;\r\n      push_L(x);\r\n    }\r\n  }\r\n\r\n\
    \  // (a-x)+\r\n  void add_a_minus_x(ll a) {\r\n    min_f += max<ll>(0, a - top_R());\r\
    \n    push_R(a), push_L(pop_R());\r\n  }\r\n  // (x-a)+\r\n  void add_x_minus_a(ll\
    \ a) {\r\n    min_f += max<ll>(0, top_L() - a);\r\n    push_L(a), push_R(pop_L());\r\
    \n  }\r\n\r\n  // |x-a|\r\n  void add_abs(ll a) {\r\n    add_a_minus_x(a);\r\n\
    \    add_x_minus_a(a);\r\n  }\r\n\r\n  // \u5897\u52A0\u5074\u3092\u6D88\u3057\
    \u3066\u3001\u6E1B\u5C11\u5074\u306E\u307F\u306B\u3059\u308B\r\n  void clear_right()\
    \ { que_r = pqg<ll>(); }\r\n  // \u6E1B\u5C11\u5074\u3092\u6D88\u3057\u3066\u3001\
    \u5897\u52A0\u5074\u306E\u307F\u306B\u3059\u308B\r\n  void clear_left() { que_l\
    \ = pq<ll>(); }\r\n  void shift(const ll &a) { add_l += a, add_r += a; }\r\n\r\
    \n  // g(x) = min_{x-b <= y <= x-a} f(y)\r\n  void sliding_window_minimum(const\
    \ ll &a, const ll &b) {\r\n    add_l += a, add_r += b;\r\n  }\r\n\r\n  // O(size\
    \ log(size))\r\n  i128 eval(ll x) {\r\n    i128 y = min_f;\r\n    pq<ll> que_l_copy\
    \ = que_l;\r\n    pqg<ll> que_r_copy = que_r;\r\n    while (len(que_l_copy)) {\
    \ y += max<ll>(0, (POP(que_l_copy) + add_l) - x); }\r\n    while (len(que_r_copy))\
    \ { y += max<ll>(0, x - (POP(que_r_copy) + add_r)); }\r\n    return y;\r\n  }\r\
    \n\r\n  void push_R(const ll &x) { que_r.emplace(x - add_r); }\r\n  void push_L(const\
    \ ll &x) { que_l.emplace(x - add_l); }\r\n  ll top_R() {\r\n    if (que_r.empty())\
    \ que_r.emplace(RMAX);\r\n    return que_r.top() + add_r;\r\n  }\r\n  ll top_L()\
    \ {\r\n    if (que_l.empty()) que_l.emplace(LMIN);\r\n    return que_l.top() +\
    \ add_l;\r\n  }\r\n  ll pop_R() {\r\n    ll res = top_R();\r\n    que_r.pop();\r\
    \n    return res;\r\n  }\r\n  ll pop_L() {\r\n    ll res = top_L();\r\n    que_l.pop();\r\
    \n    return res;\r\n  }\r\n\r\n#ifdef FASTIO\r\n  void debug() {\r\n    vi left,\
    \ right;\r\n    pq<ll> que_l_copy = que_l;\r\n    pqg<ll> que_r_copy = que_r;\r\
    \n    while (len(que_l_copy)) { left.eb(POP(que_l_copy) + add_l); }\r\n    while\
    \ (len(que_r_copy)) { right.eb(POP(que_r_copy) + add_r); }\r\n    sort(all(left));\r\
    \n    sort(all(right));\r\n    print(\"min_f\", min_f, \"left\", left, \"right\"\
    , right);\r\n  }\r\n#endif\r\n};\n#line 2 \"flow/min_cost_matching_on_line.hpp\"\
    \n\n// \u5EA7\u6A19 0, ..., N-1 \u306B A_i \u500B\u3042\u308B\n// \u5EA7\u6A19\
    \ 0, ..., N-1 \u3067 B_i \u500B\u307E\u3067\u53D7\u3051\u5165\u308C\u3089\u308C\
    \u308B\nll min_cost_matching_on_line_1(vi A, vi B) {\n  assert(SUM<ll>(A) <= SUM<ll>(B));\n\
    \  const int N = len(A);\n  Slope_Trick f(vi(N + 1, 0), vi());\n  FOR(i, N) {\n\
    \    ll c = A[i] - B[i];\n    f.shift(c);\n    f.clear_right();\n    f.add_abs(0);\n\
    \  }\n  return f.eval(0);\n}\n#line 4 \"test/mytest/min_cost_matching_on_line.test.cpp\"\
    \n\nvoid test() {\n  // https://atcoder.jp/contests/kupc2016/tasks/kupc2016_h\n\
    \  vi A = {3, 1}, B = {1, 5};\n  assert(min_cost_matching_on_line_1(A, B) == 2);\n\
    \  A = {3, 3, 1, 1, 1}, B = {1, 2, 3, 4, 5};\n  assert(min_cost_matching_on_line_1(A,\
    \ B) == 6);\n  A = {10, 2, 5, 6, 2, 6, 3,  2, 2,  5, 3, 11, 13, 2,\n       2,\
    \  7, 7, 3, 9, 5, 13, 4, 17, 2, 2, 2,  4},\n  B = {46, 3, 4, 2, 10, 2, 5, 2, 6,\
    \ 7,  20, 13, 9, 49,\n       3,  8, 4, 3, 19, 9, 3, 5, 4, 13, 9,  5,  7};\n  assert(min_cost_matching_on_line_1(A,\
    \ B) == 48);\n  A = {1236501, 770807,  4003004, 131688,  1965412, 266841,\n  \
    \     3980782, 565060,  816313,  192940,  541896,  250801,\n       217586,  3806049,\
    \ 1220252, 1161079, 31168,   2008961},\n  B = {3878348, 423911,  8031742, 1035156,\
    \ 24256,    10344593,\n       19379,   3867285, 4481365, 1475384, 1959412,  1383457,\n\
    \       164869,  4633165, 6674637, 9732852, 10459147, 2810788};\n  assert(min_cost_matching_on_line_1(A,\
    \ B) == 6302172);\n  A = {1234567891, 1}, B = {1, 99999999999};\n  assert(min_cost_matching_on_line_1(A,\
    \ B) == 1234567890);\n}\n\nvoid solve() {\n  int a, b;\n  cin >> a >> b;\n  cout\
    \ << a + b << \"\\n\";\n}\n\nsigned main() {\n  test();\n  solve();\n\n  return\
    \ 0;\n}\n"
  code: "#define PROBLEM \"https://judge.yosupo.jp/problem/aplusb\"\n#include \"my_template.hpp\"\
    \n#include \"flow/min_cost_matching_on_line.hpp\"\n\nvoid test() {\n  // https://atcoder.jp/contests/kupc2016/tasks/kupc2016_h\n\
    \  vi A = {3, 1}, B = {1, 5};\n  assert(min_cost_matching_on_line_1(A, B) == 2);\n\
    \  A = {3, 3, 1, 1, 1}, B = {1, 2, 3, 4, 5};\n  assert(min_cost_matching_on_line_1(A,\
    \ B) == 6);\n  A = {10, 2, 5, 6, 2, 6, 3,  2, 2,  5, 3, 11, 13, 2,\n       2,\
    \  7, 7, 3, 9, 5, 13, 4, 17, 2, 2, 2,  4},\n  B = {46, 3, 4, 2, 10, 2, 5, 2, 6,\
    \ 7,  20, 13, 9, 49,\n       3,  8, 4, 3, 19, 9, 3, 5, 4, 13, 9,  5,  7};\n  assert(min_cost_matching_on_line_1(A,\
    \ B) == 48);\n  A = {1236501, 770807,  4003004, 131688,  1965412, 266841,\n  \
    \     3980782, 565060,  816313,  192940,  541896,  250801,\n       217586,  3806049,\
    \ 1220252, 1161079, 31168,   2008961},\n  B = {3878348, 423911,  8031742, 1035156,\
    \ 24256,    10344593,\n       19379,   3867285, 4481365, 1475384, 1959412,  1383457,\n\
    \       164869,  4633165, 6674637, 9732852, 10459147, 2810788};\n  assert(min_cost_matching_on_line_1(A,\
    \ B) == 6302172);\n  A = {1234567891, 1}, B = {1, 99999999999};\n  assert(min_cost_matching_on_line_1(A,\
    \ B) == 1234567890);\n}\n\nvoid solve() {\n  int a, b;\n  cin >> a >> b;\n  cout\
    \ << a + b << \"\\n\";\n}\n\nsigned main() {\n  test();\n  solve();\n\n  return\
    \ 0;\n}\n"
  dependsOn:
  - my_template.hpp
  - flow/min_cost_matching_on_line.hpp
  - convex/slope.hpp
  isVerificationFile: true
  path: test/mytest/min_cost_matching_on_line.test.cpp
  requiredBy: []
  timestamp: '2023-11-10 12:48:50+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: test/mytest/min_cost_matching_on_line.test.cpp
layout: document
redirect_from:
- /verify/test/mytest/min_cost_matching_on_line.test.cpp
- /verify/test/mytest/min_cost_matching_on_line.test.cpp.html
title: test/mytest/min_cost_matching_on_line.test.cpp
---