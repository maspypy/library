---
data:
  _extendedDependsOn:
  - icon: ':question:'
    path: datetime/datetime.hpp
    title: datetime/datetime.hpp
  - icon: ':question:'
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
    - https://judge.yosupo.jp/problem/aplusb
  bundledCode: "#line 1 \"test/1_mytest/datetime.test.cpp\"\n#define PROBLEM \"https://judge.yosupo.jp/problem/aplusb\"\
    \n#line 1 \"my_template.hpp\"\n#if defined(LOCAL)\n#include <my_template_compiled.hpp>\n\
    #else\n\n// https://codeforces.com/blog/entry/96344\n#pragma GCC optimize(\"Ofast,unroll-loops\"\
    )\n// \u3044\u307E\u306E CF \u3060\u3068\u3053\u308C\u5165\u308C\u308B\u3068\u52D5\
    \u304B\u306A\u3044\uFF1F\n// #pragma GCC target(\"avx2,popcnt\")\n\n#include <bits/stdc++.h>\n\
    \nusing namespace std;\n\nusing ll = long long;\nusing u8 = uint8_t;\nusing u16\
    \ = uint16_t;\nusing u32 = uint32_t;\nusing u64 = uint64_t;\nusing i128 = __int128;\n\
    using u128 = unsigned __int128;\nusing f128 = __float128;\n\ntemplate <class T>\n\
    constexpr T infty = 0;\ntemplate <>\nconstexpr int infty<int> = 1'010'000'000;\n\
    template <>\nconstexpr ll infty<ll> = 2'020'000'000'000'000'000;\ntemplate <>\n\
    constexpr u32 infty<u32> = infty<int>;\ntemplate <>\nconstexpr u64 infty<u64>\
    \ = infty<ll>;\ntemplate <>\nconstexpr i128 infty<i128> = i128(infty<ll>) * 2'000'000'000'000'000'000;\n\
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
    T kth_bit(int k) {\n  return T(1) << k;\n}\ntemplate <typename T>\nbool has_kth_bit(T\
    \ x, int k) {\n  return x >> k & 1;\n}\n\ntemplate <typename T>\nT floor(T a,\
    \ T b) {\n  return a / b - (a % b && (a ^ b) < 0);\n}\ntemplate <typename T>\n\
    T ceil(T x, T y) {\n  return floor(x + y - 1, y);\n}\ntemplate <typename T>\n\
    T bmod(T x, T y) {\n  return x - y * floor(x, y);\n}\ntemplate <typename T>\n\
    pair<T, T> divmod(T x, T y) {\n  T q = floor(x, y);\n  return {q, x - q * y};\n\
    }\n\ntemplate <typename T, typename U>\nT SUM(const vector<U> &A) {\n  T sm =\
    \ 0;\n  for (auto &&a: A) sm += a;\n  return sm;\n}\n\n#define MIN(v) *min_element(all(v))\n\
    #define MAX(v) *max_element(all(v))\n#define LB(c, x) distance((c).begin(), lower_bound(all(c),\
    \ (x)))\n#define UB(c, x) distance((c).begin(), upper_bound(all(c), (x)))\n#define\
    \ UNIQUE(x) sort(all(x)), x.erase(unique(all(x)), x.end()), x.shrink_to_fit()\n\
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
    \ vector<T> &A) {\n  vector<int> ids(len(A));\n  iota(all(ids), 0);\n  sort(all(ids),\
    \ [&](int i, int j) { return (A[i] == A[j] ? i < j : A[i] < A[j]); });\n  return\
    \ ids;\n}\n\n// A[I[0]], A[I[1]], ...\ntemplate <typename T>\nvc<T> rearrange(const\
    \ vc<T> &A, const vc<int> &I) {\n  vc<T> B(len(I));\n  FOR(i, len(I)) B[i] = A[I[i]];\n\
    \  return B;\n}\n\ntemplate <typename T, typename... Vectors>\nvoid concat(vc<T>\
    \ &first, const Vectors &... others) {\n  vc<T> &res = first;\n  (res.insert(res.end(),\
    \ others.begin(), others.end()), ...);\n}\n#endif\n#line 1 \"datetime/datetime.hpp\"\
    \nstruct DateTime {\n  static constexpr int month_days[13]\n      = {0, 31, 28,\
    \ 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};\n  int year, month, day;\n  DateTime(int\
    \ y, int m, int d) : year(y), month(m), day(d) {}\n\n  // 1\u5E741\u67081\u65E5\
    \u304C 0 \u3068\u306A\u308B\u3088\u3046\u306B\u5909\u63DB\n  int to_int() {\n\
    \    int y = (month <= 2 ? year - 1 : year);\n    int m = (month <= 2 ? month\
    \ + 12 : month);\n    int d = day;\n    return 365 * y + y / 4 - y / 100 + y /\
    \ 400 + 306 * (m + 1) / 10 + d - 429;\n  }\n\n  // to_int() \u306E\u9006\u95A2\
    \u6570\n  static DateTime from_int(int x) {\n    int y = x * 400 / 146097 + 1;\n\
    \    int d = x - DateTime(y, 1, 1).to_int();\n    int m = 1;\n    while (d >=\
    \ 28) {\n      int k = month_days[m] + (m == 2 && is_leap_year(y) ? 1 : 0);\n\
    \      if (d < k) break;\n      ++m;\n      d -= k;\n    }\n    if (m == 13) {\n\
    \      ++y;\n      m = 1;\n    }\n    ++d;\n    return DateTime(y, m, d);\n  }\n\
    \n  // \u65E5\u66DC\u65E5\u304C 0 \u3068\u3057\u3066\u3001\u66DC\u65E5\u3092 [0,\
    \ 7) \u3067\u8FD4\u3059\n  int weekday() { return (to_int() + 1) % 7; }\n\n  DateTime&\
    \ operator++() {\n    ++day;\n    int lim = month_days[month];\n    if (is_leap_year(year)\
    \ && month == 2) lim = 29;\n    if (day <= lim) return (*this);\n    day = 1;\n\
    \    ++month;\n    if (month == 13) {\n      ++year;\n      month = 1;\n    }\n\
    \    return (*this);\n  }\n  DateTime operator++(int) {\n    DateTime tmp = *this;\n\
    \    ++*this;\n    return tmp;\n  }\n\n  bool operator==(DateTime const& rhs)\
    \ const {\n    return to_tuple() == rhs.to_tuple();\n  }\n  bool operator!=(DateTime\
    \ const& rhs) const {\n    return to_tuple() != rhs.to_tuple();\n  }\n  bool operator<(DateTime\
    \ const& rhs) const {\n    return to_tuple() < rhs.to_tuple();\n  }\n  bool operator<=(DateTime\
    \ const& rhs) const {\n    return to_tuple() <= rhs.to_tuple();\n  }\n  bool operator>(DateTime\
    \ const& rhs) const {\n    return to_tuple() > rhs.to_tuple();\n  }\n  bool operator>=(DateTime\
    \ const& rhs) const {\n    return to_tuple() >= rhs.to_tuple();\n  }\n\n  // yyyy[sep]mm[sep]dd\n\
    \  string to_string(string sep = \"-\") {\n    string y = std::to_string(year);\n\
    \    string m = std::to_string(month);\n    string d = std::to_string(day);\n\
    \    while (len(y) < 4) y = \"0\" + y;\n    while (len(m) < 2) m = \"0\" + m;\n\
    \    while (len(d) < 2) d = \"0\" + d;\n    return y + sep + m + sep + d;\n  }\n\
    \n  tuple<int, int, int> to_tuple() const { return {year, month, day}; }\n\n \
    \ static bool is_leap_year(int y) {\n    if (y % 400 == 0) return true;\n    return\
    \ (y % 4 == 0 && y % 100 != 0);\n  }\n\n  static bool is_valid_date(int y, int\
    \ m, int d) {\n    if (!(1 <= m && m <= 12)) return 0;\n    int mx = month_days[m];\n\
    \    if (m == 2 && is_leap_year(y)) ++mx;\n    return (1 <= d && d <= mx);\n \
    \ }\n};\n#line 4 \"test/1_mytest/datetime.test.cpp\"\n\nusing DT = DateTime;\n\
    \nvoid test_ARC23_A() {\n  auto f = [&](int y, int m, int d) -> int {\n    return\
    \ DateTime(2014, 5, 17).to_int() - DateTime(y, m, d).to_int();\n  };\n  assert(9449\
    \ == f(1988, 7, 3));\n  assert(735369 == f(1, 1, 1));\n}\n\nvoid test_from_int()\
    \ {\n  DT A(1, 1, 1);\n  FOR(x, 1000000) {\n    DT B = DT::from_int(x);\n    assert(A\
    \ == B);\n    assert(A.to_int() == x);\n    ++A;\n  }\n}\n\nvoid solve() {\n \
    \ int a, b;\n  cin >> a >> b;\n  cout << a + b << \"\\n\";\n}\n\nsigned main()\
    \ {\n  test_ARC23_A();\n  test_from_int();\n  solve();\n\n  return 0;\n}\n"
  code: "#define PROBLEM \"https://judge.yosupo.jp/problem/aplusb\"\n#include \"my_template.hpp\"\
    \n#include \"datetime/datetime.hpp\"\n\nusing DT = DateTime;\n\nvoid test_ARC23_A()\
    \ {\n  auto f = [&](int y, int m, int d) -> int {\n    return DateTime(2014, 5,\
    \ 17).to_int() - DateTime(y, m, d).to_int();\n  };\n  assert(9449 == f(1988, 7,\
    \ 3));\n  assert(735369 == f(1, 1, 1));\n}\n\nvoid test_from_int() {\n  DT A(1,\
    \ 1, 1);\n  FOR(x, 1000000) {\n    DT B = DT::from_int(x);\n    assert(A == B);\n\
    \    assert(A.to_int() == x);\n    ++A;\n  }\n}\n\nvoid solve() {\n  int a, b;\n\
    \  cin >> a >> b;\n  cout << a + b << \"\\n\";\n}\n\nsigned main() {\n  test_ARC23_A();\n\
    \  test_from_int();\n  solve();\n\n  return 0;\n}\n"
  dependsOn:
  - my_template.hpp
  - datetime/datetime.hpp
  isVerificationFile: true
  path: test/1_mytest/datetime.test.cpp
  requiredBy: []
  timestamp: '2024-11-16 23:01:41+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: test/1_mytest/datetime.test.cpp
layout: document
redirect_from:
- /verify/test/1_mytest/datetime.test.cpp
- /verify/test/1_mytest/datetime.test.cpp.html
title: test/1_mytest/datetime.test.cpp
---