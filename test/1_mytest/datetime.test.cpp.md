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
    \n#line 1 \"my_template.hpp\"\n#if defined(USE_PCH)\n#include <my_template_compiled.hpp>\n\
    #else\n#if defined(__GNUC__)\n#include <bits/allocator.h>\n#pragma GCC optimize(\"\
    Ofast,unroll-loops\")\n// \u74B0\u5883\u306B\u3088\u3063\u3066\u306F\u30B3\u30F3\
    \u30D1\u30A4\u30EB\u6210\u529F\u304B\u3064\u5B9F\u884C\u6642\u30A8\u30E9\u30FC\
    \n#pragma GCC target(\"avx2,popcnt\")\n#endif\n#include <bits/stdc++.h>\n#include\
    \ <cassert>\n\nusing namespace std;\n\nusing ll = long long;\nusing u8 = uint8_t;\n\
    using u16 = uint16_t;\nusing u32 = uint32_t;\nusing u64 = uint64_t;\nusing i128\
    \ = __int128;\nusing u128 = unsigned __int128;\nusing f128 = __float128;\n\ntemplate\
    \ <class>\nconstexpr bool dependent_false = false;\n\ntemplate <class T>\nconstexpr\
    \ T infty = [] {\n  static_assert(dependent_false<T>, \"infty<T> is not defined\"\
    );\n  return T{};\n}();\ntemplate <>\nconstexpr int infty<int> = 1'010'000'000;\n\
    template <>\nconstexpr ll infty<ll> = 2'020'000'000'000'000'000;\ntemplate <>\n\
    constexpr u32 infty<u32> = infty<int>;\ntemplate <>\nconstexpr u64 infty<u64>\
    \ = infty<ll>;\ntemplate <>\nconstexpr i128 infty<i128> = i128(infty<ll>) * 2'000'000'000'000'000'000;\n\
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
    \ ng, bool check_ok = true) {\n  if (check_ok) assert(check(ok));\n  while (llabs(ok\
    \ - ng) > 1) {\n    auto x = (ng + ok) / 2;\n    (check(x) ? ok : ng) = x;\n \
    \ }\n  return ok;\n}\ntemplate <typename F>\ndouble binary_search_real(F check,\
    \ double ok, double ng, int iter = 100) {\n  FOR(iter) {\n    double x = (ok +\
    \ ng) / 2;\n    (check(x) ? ok : ng) = x;\n  }\n  return (ok + ng) / 2;\n}\n\n\
    template <class T, class S>\ninline bool chmax(T &a, const S &b) {\n  T c = max<T>(a,\
    \ b);\n  bool changed = (c != a);\n  a = c;\n  return changed;\n}\ntemplate <class\
    \ T, class S>\ninline bool chmin(T &a, const S &b) {\n  T c = min<T>(a, b);\n\
    \  bool changed = (c != a);\n  a = c;\n  return changed;\n}\n\n// ? \u306F -1\n\
    vc<int> s_to_vi(const string &S, char first_char) {\n  vc<int> A(S.size());\n\
    \  FOR(i, S.size()) { A[i] = (S[i] != '?' ? S[i] - first_char : -1); }\n  return\
    \ A;\n}\n\ntemplate <typename T, typename U>\nvc<T> cumsum(const vc<U> &A, int\
    \ off = 1) {\n  int N = A.size();\n  vc<T> B(N + 1);\n  FOR(i, N) { B[i + 1] =\
    \ B[i] + A[i]; }\n  if (off == 0) B.erase(B.begin());\n  return B;\n}\n\n// stable\
    \ sort\ntemplate <typename T>\nvc<int> argsort(const vc<T> &A) {\n  vc<int> ids(len(A));\n\
    \  iota(all(ids), 0);\n  sort(all(ids),\n       [&](int i, int j) { return (A[i]\
    \ == A[j] ? i < j : A[i] < A[j]); });\n  return ids;\n}\n\n// A[I[0]], A[I[1]],\
    \ ...\ntemplate <typename T>\nvc<T> rearrange(const vc<T> &A, const vc<int> &I)\
    \ {\n  vc<T> B(len(I));\n  FOR(i, len(I)) B[i] = A[I[i]];\n  return B;\n}\n\n\
    template <typename T, typename... Vectors>\nvoid concat(vc<T> &first, const Vectors\
    \ &...others) {\n  first.reserve(first.size() + (others.size() + ... + 0));\n\
    \  (first.insert(first.end(), others.begin(), others.end()), ...);\n}\n\n// i128\n\
    template <class T, enable_if_t<is_same_v<T, i128>, int> = 0>\nconstexpr i128 abs(T\
    \ x) {\n  return x < 0 ? -x : x;\n}\n\nconstexpr i128 gcd(i128 a, i128 b) {\n\
    \  while (b != 0) {\n    i128 c = a % b;\n    a = b, b = c;\n  }\n  return abs(a);\n\
    }\n#endif\n#line 1 \"datetime/datetime.hpp\"\n// https://codeforces.com/problemset/problem/698/E\n\
    struct DateTime {\n  static constexpr int month_days[13] = {0, 31, 28, 31, 30,\
    \ 31, 30, 31, 31, 30, 31, 30, 31};\n  ll year;\n  int month, day;\n  DateTime(ll\
    \ y, int m, int d) : year(y), month(m), day(d) {}\n\n  // 1\u5E741\u67081\u65E5\
    \u304C 0 \u3068\u306A\u308B\u3088\u3046\u306B\u5909\u63DB (return: long long)\n\
    \  ll to_int() {\n    ll y = (month <= 2 ? year - 1 : year);\n    int m = (month\
    \ <= 2 ? month + 12 : month);\n    int d = day;\n    return 365 * y + y / 4 -\
    \ y / 100 + y / 400 + 306 * (m + 1) / 10 + d - 429;\n  }\n\n  // to_int() \u306E\
    \u9006\u95A2\u6570\n  static DateTime from_int(ll x) {\n    ll y = x * 400 / 146097\
    \ + 1;\n    int d = x - DateTime(y, 1, 1).to_int();\n    int m = 1;\n    while\
    \ (d >= 28) {\n      int k = month_days[m] + (m == 2 && is_leap_year(y) ? 1 :\
    \ 0);\n      if (d < k) break;\n      ++m;\n      d -= k;\n    }\n    if (m ==\
    \ 13) {\n      ++y;\n      m = 1;\n    }\n    ++d;\n    return DateTime(y, m,\
    \ d);\n  }\n\n  // \u65E5\u66DC\u65E5\u304C 0 \u3068\u3057\u3066\u3001\u66DC\u65E5\
    \u3092 [0, 7) \u3067\u8FD4\u3059\n  int weekday() { return (to_int() + 1) % 7;\
    \ }\n\n  DateTime& operator++() {\n    ++day;\n    int lim = month_days[month];\n\
    \    if (is_leap_year(year) && month == 2) lim = 29;\n    if (day <= lim) return\
    \ (*this);\n    day = 1;\n    ++month;\n    if (month == 13) {\n      ++year;\n\
    \      month = 1;\n    }\n    return (*this);\n  }\n  DateTime operator++(int)\
    \ {\n    DateTime tmp = *this;\n    ++*this;\n    return tmp;\n  }\n\n  bool operator==(DateTime\
    \ const& rhs) const { return to_tuple() == rhs.to_tuple(); }\n  bool operator!=(DateTime\
    \ const& rhs) const { return to_tuple() != rhs.to_tuple(); }\n  bool operator<(DateTime\
    \ const& rhs) const { return to_tuple() < rhs.to_tuple(); }\n  bool operator<=(DateTime\
    \ const& rhs) const { return to_tuple() <= rhs.to_tuple(); }\n  bool operator>(DateTime\
    \ const& rhs) const { return to_tuple() > rhs.to_tuple(); }\n  bool operator>=(DateTime\
    \ const& rhs) const { return to_tuple() >= rhs.to_tuple(); }\n\n  // yyyy[sep]mm[sep]dd\n\
    \  string to_string(string sep = \"-\") {\n    string y = std::to_string(year);\n\
    \    string m = std::to_string(month);\n    string d = std::to_string(day);\n\
    \    while (len(y) < 4) y = \"0\" + y;\n    while (len(m) < 2) m = \"0\" + m;\n\
    \    while (len(d) < 2) d = \"0\" + d;\n    return y + sep + m + sep + d;\n  }\n\
    \n  tuple<ll, int, int> to_tuple() const { return {year, month, day}; }\n\n  static\
    \ bool is_leap_year(ll y) {\n    if (y % 400 == 0) return true;\n    return (y\
    \ % 4 == 0 && y % 100 != 0);\n  }\n\n  static bool is_valid_date(ll y, int m,\
    \ int d) {\n    if (!(1 <= m && m <= 12)) return 0;\n    int mx = month_days[m];\n\
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
  timestamp: '2026-08-08 05:13:48+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: test/1_mytest/datetime.test.cpp
layout: document
redirect_from:
- /verify/test/1_mytest/datetime.test.cpp
- /verify/test/1_mytest/datetime.test.cpp.html
title: test/1_mytest/datetime.test.cpp
---
