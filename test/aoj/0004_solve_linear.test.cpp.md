---
data:
  _extendedDependsOn:
  - icon: ':question:'
    path: linalg/solve_linear.hpp
    title: linalg/solve_linear.hpp
  - icon: ':question:'
    path: my_template.hpp
    title: my_template.hpp
  - icon: ':question:'
    path: other/io2.hpp
    title: other/io2.hpp
  - icon: ':question:'
    path: string/split.hpp
    title: string/split.hpp
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: true
  _pathExtension: cpp
  _verificationStatusIcon: ':x:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=0004
    links:
    - https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=0004
  bundledCode: "#line 1 \"test/aoj/0004_solve_linear.test.cpp\"\n#define PROBLEM \"\
    https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=0004\"\n#line 1 \"my_template.hpp\"\
    \n#include <bits/stdc++.h>\n\nusing namespace std;\n\nusing ll = long long;\n\
    using pi = pair<ll, ll>;\nusing vi = vector<ll>;\nusing u32 = unsigned int;\n\
    using u64 = unsigned long long;\nusing i128 = __int128;\n\ntemplate <class T>\n\
    using vc = vector<T>;\ntemplate <class T>\nusing vvc = vector<vc<T>>;\ntemplate\
    \ <class T>\nusing vvvc = vector<vvc<T>>;\ntemplate <class T>\nusing vvvvc = vector<vvvc<T>>;\n\
    template <class T>\nusing vvvvvc = vector<vvvvc<T>>;\ntemplate <class T>\nusing\
    \ pq = priority_queue<T>;\ntemplate <class T>\nusing pqg = priority_queue<T, vector<T>,\
    \ greater<T>>;\n\n#define vec(type, name, ...) vector<type> name(__VA_ARGS__)\n\
    #define vv(type, name, h, ...) \\\n  vector<vector<type>> name(h, vector<type>(__VA_ARGS__))\n\
    #define vvv(type, name, h, w, ...)   \\\n  vector<vector<vector<type>>> name(\
    \ \\\n      h, vector<vector<type>>(w, vector<type>(__VA_ARGS__)))\n#define vvvv(type,\
    \ name, a, b, c, ...)       \\\n  vector<vector<vector<vector<type>>>> name( \\\
    \n      a, vector<vector<vector<type>>>(       \\\n             b, vector<vector<type>>(c,\
    \ vector<type>(__VA_ARGS__))))\n\n// https://trap.jp/post/1224/\n#define FOR1(a)\
    \ for (ll _ = 0; _ < ll(a); ++_)\n#define FOR2(i, a) for (ll i = 0; i < ll(a);\
    \ ++i)\n#define FOR3(i, a, b) for (ll i = a; i < ll(b); ++i)\n#define FOR4(i,\
    \ a, b, c) for (ll i = a; i < ll(b); i += (c))\n#define FOR1_R(a) for (ll i =\
    \ (a)-1; i >= ll(0); --i)\n#define FOR2_R(i, a) for (ll i = (a)-1; i >= ll(0);\
    \ --i)\n#define FOR3_R(i, a, b) for (ll i = (b)-1; i >= ll(a); --i)\n#define FOR4_R(i,\
    \ a, b, c) for (ll i = (b)-1; i >= ll(a); i -= (c))\n#define overload4(a, b, c,\
    \ d, e, ...) e\n#define FOR(...) overload4(__VA_ARGS__, FOR4, FOR3, FOR2, FOR1)(__VA_ARGS__)\n\
    #define FOR_R(...) \\\n  overload4(__VA_ARGS__, FOR4_R, FOR3_R, FOR2_R, FOR1_R)(__VA_ARGS__)\n\
    \n#define FOR_subset(t, s) for (ll t = s; t >= 0; t = (t == 0 ? -1 : (t - 1) &\
    \ s))\n#define all(x) x.begin(), x.end()\n#define len(x) ll(x.size())\n#define\
    \ elif else if\n\n#define eb emplace_back\n#define mp make_pair\n#define mt make_tuple\n\
    #define fi first\n#define se second\n\n#define stoi stoll\n\ntemplate <typename\
    \ T>\nT SUM(vector<T> &A) {\n  T sum = T(0);\n  for (auto &&a: A) sum += a;\n\
    \  return sum;\n}\n\n#define MIN(v) *min_element(all(v))\n#define MAX(v) *max_element(all(v))\n\
    #define LB(c, x) distance((c).begin(), lower_bound(all(c), (x)))\n#define UB(c,\
    \ x) distance((c).begin(), upper_bound(all(c), (x)))\n#define UNIQUE(x) sort(all(x)),\
    \ x.erase(unique(all(x)), x.end())\n\nint popcnt(int x) { return __builtin_popcount(x);\
    \ }\nint popcnt(u32 x) { return __builtin_popcount(x); }\nint popcnt(ll x) { return\
    \ __builtin_popcountll(x); }\nint popcnt(u64 x) { return __builtin_popcountll(x);\
    \ }\n// (0, 1, 2, 3, 4) -> (-1, 0, 1, 1, 2)\nint topbit(int x) { return (x ==\
    \ 0 ? -1 : 31 - __builtin_clz(x)); }\nint topbit(u32 x) { return (x == 0 ? -1\
    \ : 31 - __builtin_clz(x)); }\nint topbit(ll x) { return (x == 0 ? -1 : 63 - __builtin_clzll(x));\
    \ }\nint topbit(u64 x) { return (x == 0 ? -1 : 63 - __builtin_clzll(x)); }\n//\
    \ (0, 1, 2, 3, 4) -> (-1, 0, 1, 0, 2)\nint lowbit(int x) { return (x == 0 ? -1\
    \ : __builtin_ctz(x)); }\nint lowbit(u32 x) { return (x == 0 ? -1 : __builtin_ctz(x));\
    \ }\nint lowbit(ll x) { return (x == 0 ? -1 : __builtin_ctzll(x)); }\nint lowbit(u64\
    \ x) { return (x == 0 ? -1 : __builtin_ctzll(x)); }\n\ntemplate <typename T, typename\
    \ U>\nT ceil(T x, U y) {\n  return (x > 0 ? (x + y - 1) / y : x / y);\n}\n\ntemplate\
    \ <typename T, typename U>\nT floor(T x, U y) {\n  return (x > 0 ? x / y : (x\
    \ - y + 1) / y);\n}\n\ntemplate <typename T, typename U>\npair<T, T> divmod(T\
    \ x, U y) {\n  T q = floor(x, y);\n  return {q, x - q * y};\n}\n\nll binary_search(function<bool(ll)>\
    \ check, ll ok, ll ng) {\n  assert(check(ok));\n  while (abs(ok - ng) > 1) {\n\
    \    auto x = (ng + ok) / 2;\n    if (check(x))\n      ok = x;\n    else\n   \
    \   ng = x;\n  }\n  return ok;\n}\n\ntemplate <typename F>\ndouble binary_search_real(F\
    \ check, double ok, double ng, int iter = 100) {\n  FOR(iter) {\n    double x\
    \ = (ok + ng) / 2;\n    if (check(x)) {\n      ok = x;\n    } else {\n      ng\
    \ = x;\n    }\n  }\n  return (ok + ng) / 2;\n}\n\ntemplate <class T, class S>\n\
    inline bool chmax(T &a, const S &b) {\n  return (a < b ? a = b, 1 : 0);\n}\ntemplate\
    \ <class T, class S>\ninline bool chmin(T &a, const S &b) {\n  return (a > b ?\
    \ a = b, 1 : 0);\n}\n\nvi s_to_vi(const string &S, char first_char) {\n  vi A(S.size());\n\
    \  FOR(i, S.size()) { A[i] = S[i] - first_char; }\n  return A;\n}\n\ntemplate\
    \ <typename T>\nvector<T> cumsum(vector<T> &A, int off = 1) {\n  int N = A.size();\n\
    \  vector<T> B(N + 1);\n  FOR(i, N) { B[i + 1] = B[i] + A[i]; }\n  if (off ==\
    \ 0) B.erase(B.begin());\n  return B;\n}\n\ntemplate <typename CNT, typename T>\n\
    vc<CNT> bincount(const vc<T> &A, int size) {\n  vc<CNT> C(size);\n  for (auto\
    \ &&x: A) { ++C[x]; }\n  return C;\n}\n\ntemplate <typename T>\nvector<int> argsort(const\
    \ vector<T> &A) {\n  // stable\n  vector<int> ids(A.size());\n  iota(all(ids),\
    \ 0);\n  sort(all(ids),\n       [&](int i, int j) { return A[i] < A[j] || (A[i]\
    \ == A[j] && i < j); });\n  return ids;\n}\n\n// A[I[0]], A[I[1]], ...\ntemplate\
    \ <typename T>\nvc<T> rearrange(const vc<T> &A, const vc<int> &I) {\n  int n =\
    \ len(A);\n  assert(len(I) == n);\n  vc<T> B(n);\n  FOR(i, n) B[i] = A[I[i]];\n\
    \  return B;\n}\n#line 1 \"other/io2.hpp\"\n#define INT(...) \\\r\n  int __VA_ARGS__;\
    \ \\\r\n  IN(__VA_ARGS__)\r\n#define LL(...) \\\r\n  ll __VA_ARGS__; \\\r\n  IN(__VA_ARGS__)\r\
    \n#define STR(...) \\\r\n  string __VA_ARGS__; \\\r\n  IN(__VA_ARGS__)\r\n#define\
    \ CHR(...) \\\r\n  char __VA_ARGS__; \\\r\n  IN(__VA_ARGS__)\r\n#define DBL(...)\
    \ \\\r\n  long double __VA_ARGS__; \\\r\n  IN(__VA_ARGS__)\r\n\r\n#define VEC(type,\
    \ name, size) \\\r\n  vector<type> name(size);    \\\r\n  read(name)\r\n#define\
    \ VV(type, name, h, w)                     \\\r\n  vector<vector<type>> name(h,\
    \ vector<type>(w)); \\\r\n  read(name)\r\n\r\nvoid read(int &a) { cin >> a; }\r\
    \nvoid read(long long &a) { cin >> a; }\r\nvoid read(char &a) { cin >> a; }\r\n\
    void read(double &a) { cin >> a; }\r\nvoid read(long double &a) { cin >> a; }\r\
    \nvoid read(string &a) { cin >> a; }\r\ntemplate <class T, class S> void read(pair<T,\
    \ S> &p) { read(p.first), read(p.second); }\r\ntemplate <class T> void read(vector<T>\
    \ &a) {for(auto &i : a) read(i);}\r\ntemplate <class T> void read(T &a) { cin\
    \ >> a; }\r\nvoid IN() {}\r\ntemplate <class Head, class... Tail> void IN(Head\
    \ &head, Tail &...tail) {\r\n  read(head);\r\n  IN(tail...);\r\n}\r\n\r\ntemplate\
    \ <typename T, typename U>\r\nostream& operator<<(ostream& os, const pair<T, U>&\
    \ A) {\r\n  os << A.fi << \" \" << A.se;\r\n  return os;\r\n}\r\n\r\ntemplate\
    \ <typename T>\r\nostream& operator<<(ostream& os, const vector<T>& A) {\r\n \
    \ for (size_t i = 0; i < A.size(); i++) {\r\n    if(i) os << \" \";\r\n    os\
    \ << A[i];\r\n  }\r\n  return os;\r\n}\r\n\r\nvoid print() {\r\n  cout << \"\\\
    n\";\r\n  cout.flush();\r\n}\r\n\r\ntemplate <class Head, class... Tail>\r\nvoid\
    \ print(Head&& head, Tail&&... tail) {\r\n  cout << head;\r\n  if (sizeof...(Tail))\
    \ cout << \" \";\r\n  print(forward<Tail>(tail)...);\r\n}\r\n\r\nvoid YES(bool\
    \ t = 1) { print(t ? \"YES\" : \"NO\"); }\r\nvoid NO(bool t = 1) { YES(!t); }\r\
    \nvoid Yes(bool t = 1) { print(t ? \"Yes\" : \"No\"); }\r\nvoid No(bool t = 1)\
    \ { Yes(!t); }\r\nvoid yes(bool t = 1) { print(t ? \"yes\" : \"no\"); }\r\nvoid\
    \ no(bool t = 1) { yes(!t); }\r\n#line 1 \"string/split.hpp\"\nvc<string> split(string\
    \ S, char sep = ',') {\r\n  vc<string> res = {\"\"};\r\n  for (auto&& s: S) {\r\
    \n    if (s == sep)\r\n      res.eb(\"\");\r\n    else\r\n      res.back() +=\
    \ s;\r\n  }\r\n  return res;\r\n}\r\n\r\nvc<string> split(string S, string seps\
    \ = \" ,\") {\r\n  vc<string> res = {\"\"};\r\n  for (auto&& s: S) {\r\n    if\
    \ (count(all(seps), s))\r\n      res.eb(\"\");\r\n    else\r\n      res.back()\
    \ += s;\r\n  }\r\n  return res;\r\n}\r\n#line 1 \"linalg/solve_linear.hpp\"\n\
    /*\r\n0 \u884C\u76EE\u306B\u89E3\u306E\u3072\u3068\u3064\u3002\r\n1\uFF5E\u884C\
    \u76EE\u306B\u89E3\u7A7A\u9593\u306E\u57FA\u5E95\u304C\u884C\u30D9\u30AF\u30C8\
    \u30EB\u3068\u3057\u3066\u5165\u308B\u3002\r\n\u89E3\u306A\u3057 = empty\r\n*/\r\
    \ntemplate <typename T>\r\nvc<vc<T>> solve_linear(vc<vc<T>> a, vc<T> b) {\r\n\
    \  auto n = len(a), m = len(a[0]);\r\n  int rk = 0;\r\n  FOR(j, m) {\r\n    if\
    \ (a[rk][j] == 0) {\r\n      FOR3(i, rk + 1, n) if (a[i][j] != 0) {\r\n      \
    \  swap(a[rk], a[i]);\r\n        swap(b[rk], b[i]);\r\n        break;\r\n    \
    \  }\r\n    }\r\n    if (a[rk][j] == 0) continue;\r\n    T c = T(1) / a[rk][j];\r\
    \n    for (auto&& x: a[rk]) x *= c;\r\n    b[rk] *= c;\r\n    FOR(i, n) if (i\
    \ != rk) {\r\n      T c = a[i][j];\r\n      b[i] -= b[rk] * c;\r\n      FOR3(k,\
    \ j, m) { a[i][k] -= a[rk][k] * c; }\r\n    }\r\n    ++rk;\r\n    if (rk == n)\
    \ break;\r\n  }\r\n  FOR3(i, rk, n) if (b[i] != 0) return {};\r\n  vc<vc<T>> res(1,\
    \ vc<T>(m));\r\n  vc<int> pivot(m, -1);\r\n  int p = 0;\r\n  FOR(i, rk) {\r\n\
    \    while (a[i][p] == 0) ++p;\r\n    res[0][p] = b[i];\r\n    pivot[p] = i;\r\
    \n  }\r\n  FOR(j, m) if (pivot[j] == -1) {\r\n    vc<T> x(m);\r\n    x[j] = -1;\r\
    \n    FOR(k, j) if (pivot[k] != -1) x[k] = a[pivot[k]][j];\r\n    res.eb(x);\r\
    \n  }\r\n  return res;\r\n}\r\n#line 6 \"test/aoj/0004_solve_linear.test.cpp\"\
    \n\nusing Re = double;\n\nvoid solve() {\n  Re a, b, c, d, e, f;\n  while (cin\
    \ >> a >> b >> c >> d >> e >> f) {\n    vv(Re, A, 2, 2);\n    A[0] = {a, b};\n\
    \    A[1] = {d, e};\n    vc<Re> b = {c, f};\n    auto res = solve_linear(A, b);\n\
    \    auto x = res[0];\n    printf(\"%.3f %.3f\\n\", x[0], x[1]);\n  }\n}\n\nsigned\
    \ main() {\n  cout << fixed << setprecision(15);\n\n  ll T = 1;\n  // LL(T);\n\
    \  FOR(T) solve();\n\n  return 0;\n}\n"
  code: "#define PROBLEM \"https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=0004\"\
    \n#include \"my_template.hpp\"\n#include \"other/io2.hpp\"\n#include \"string/split.hpp\"\
    \n#include \"linalg/solve_linear.hpp\"\n\nusing Re = double;\n\nvoid solve() {\n\
    \  Re a, b, c, d, e, f;\n  while (cin >> a >> b >> c >> d >> e >> f) {\n    vv(Re,\
    \ A, 2, 2);\n    A[0] = {a, b};\n    A[1] = {d, e};\n    vc<Re> b = {c, f};\n\
    \    auto res = solve_linear(A, b);\n    auto x = res[0];\n    printf(\"%.3f %.3f\\\
    n\", x[0], x[1]);\n  }\n}\n\nsigned main() {\n  cout << fixed << setprecision(15);\n\
    \n  ll T = 1;\n  // LL(T);\n  FOR(T) solve();\n\n  return 0;\n}\n"
  dependsOn:
  - my_template.hpp
  - other/io2.hpp
  - string/split.hpp
  - linalg/solve_linear.hpp
  isVerificationFile: true
  path: test/aoj/0004_solve_linear.test.cpp
  requiredBy: []
  timestamp: '2022-07-10 21:46:21+09:00'
  verificationStatus: TEST_WRONG_ANSWER
  verifiedWith: []
documentation_of: test/aoj/0004_solve_linear.test.cpp
layout: document
redirect_from:
- /verify/test/aoj/0004_solve_linear.test.cpp
- /verify/test/aoj/0004_solve_linear.test.cpp.html
title: test/aoj/0004_solve_linear.test.cpp
---
