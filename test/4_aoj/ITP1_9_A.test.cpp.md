---
data:
  _extendedDependsOn:
  - icon: ':question:'
    path: my_template.hpp
    title: my_template.hpp
  - icon: ':question:'
    path: other/io2.hpp
    title: other/io2.hpp
  - icon: ':heavy_check_mark:'
    path: string/split.hpp
    title: string/split.hpp
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=ITP1_9_A
    links:
    - https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=ITP1_9_A
  bundledCode: "#line 1 \"test/4_aoj/ITP1_9_A.test.cpp\"\n#define PROBLEM \\\n  \"\
    https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=ITP1_9_A\"\n#line 1\
    \ \"my_template.hpp\"\n#if defined(USE_PCH)\n#include <my_template_compiled.hpp>\n\
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
    \ ng, bool check_ok = true) {\n  if (check_ok) assert(check(ok));\n  while (1)\
    \ {\n    ll x = (ok + ng) / 2;\n    if (x == ok || x == ng) break;\n    (check(x)\
    \ ? ok : ng) = x;\n  }\n  return ok;\n}\ntemplate <typename F>\ndouble binary_search_real(F\
    \ check, double ok, double ng, int iter = 100) {\n  FOR(iter) {\n    double x\
    \ = (ok + ng) / 2;\n    (check(x) ? ok : ng) = x;\n  }\n  return (ok + ng) / 2;\n\
    }\n\ntemplate <class T, class S>\ninline bool chmax(T &a, const S &b) {\n  T c\
    \ = max<T>(a, b);\n  bool changed = (c != a);\n  a = c;\n  return changed;\n}\n\
    template <class T, class S>\ninline bool chmin(T &a, const S &b) {\n  T c = min<T>(a,\
    \ b);\n  bool changed = (c != a);\n  a = c;\n  return changed;\n}\n\n// ? \u306F\
    \ -1\nvc<int> s_to_vi(const string &S, char first_char) {\n  vc<int> A(S.size());\n\
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
    }\n#endif\n#line 1 \"other/io2.hpp\"\n#define INT(...)   \\\r\n  int __VA_ARGS__;\
    \ \\\r\n  IN(__VA_ARGS__)\r\n#define LL(...)   \\\r\n  ll __VA_ARGS__; \\\r\n\
    \  IN(__VA_ARGS__)\r\n#define STR(...)      \\\r\n  string __VA_ARGS__; \\\r\n\
    \  IN(__VA_ARGS__)\r\n#define CHR(...)    \\\r\n  char __VA_ARGS__; \\\r\n  IN(__VA_ARGS__)\r\
    \n#define DBL(...)           \\\r\n  long double __VA_ARGS__; \\\r\n  IN(__VA_ARGS__)\r\
    \n\r\n#define VEC(type, name, size) \\\r\n  vector<type> name(size);    \\\r\n\
    \  read(name)\r\n#define VV(type, name, h, w)                     \\\r\n  vector<vector<type>>\
    \ name(h, vector<type>(w)); \\\r\n  read(name)\r\n\r\nvoid read(int &a) { cin\
    \ >> a; }\r\nvoid read(long long &a) { cin >> a; }\r\nvoid read(char &a) { cin\
    \ >> a; }\r\nvoid read(double &a) { cin >> a; }\r\nvoid read(long double &a) {\
    \ cin >> a; }\r\nvoid read(string &a) { cin >> a; }\r\ntemplate <class T, class\
    \ S>\r\nvoid read(pair<T, S> &p) {\r\n  read(p.first), read(p.second);\r\n}\r\n\
    template <class T>\r\nvoid read(vector<T> &a) {\r\n  for (auto &i : a) read(i);\r\
    \n}\r\ntemplate <class T>\r\nvoid read(T &a) {\r\n  cin >> a;\r\n}\r\nvoid IN()\
    \ {}\r\ntemplate <class Head, class... Tail>\r\nvoid IN(Head &head, Tail &...tail)\
    \ {\r\n  read(head);\r\n  IN(tail...);\r\n}\r\n\r\ntemplate <typename T, typename\
    \ U>\r\nostream &operator<<(ostream &os, const pair<T, U> &A) {\r\n  os << A.fi\
    \ << \" \" << A.se;\r\n  return os;\r\n}\r\n\r\ntemplate <typename T>\r\nostream\
    \ &operator<<(ostream &os, const vector<T> &A) {\r\n  for (size_t i = 0; i < A.size();\
    \ i++) {\r\n    if (i) os << \" \";\r\n    os << A[i];\r\n  }\r\n  return os;\r\
    \n}\r\n\r\nclass CoutInitializer {\r\n public:\r\n  CoutInitializer() { std::cout\
    \ << std::fixed << std::setprecision(15); }\r\n};\r\nstatic CoutInitializer cout_initializer;\r\
    \n\r\nvoid print() {\r\n  cout << \"\\n\";\r\n  cout.flush();\r\n}\r\n\r\ntemplate\
    \ <class Head, class... Tail>\r\nvoid print(Head &&head, Tail &&...tail) {\r\n\
    \  cout << head;\r\n  if (sizeof...(Tail)) cout << \" \";\r\n  print(forward<Tail>(tail)...);\r\
    \n}\r\n\r\n#if defined(LOCAL)\r\ntemplate <class... Ts>\r\ninline void _show_pack(const\
    \ char *func, int line, const char *names,\r\n                       Ts &&...args)\
    \ {\r\n  // [DEBUG] solve:123 \u306E\u3088\u3046\u306B\u5148\u982D\u306B\u51FA\
    \u3059\r\n  cout << \"[DEBUG \" << func << ':' << line << \"] \";\r\n\r\n  const\
    \ char *p = names;\r\n  bool first = true;\r\n\r\n  auto next_token = [&]() ->\
    \ std::pair<const char *, const char *> {\r\n    while (*p == ' ' || *p == ',')\
    \ ++p;\r\n    const char *l = p;\r\n    while (*p && *p != ',') ++p;\r\n    const\
    \ char *r = p;\r\n    return {l, r};\r\n  };\r\n\r\n  (\r\n      [&] {\r\n   \
    \     auto [l, r] = next_token();\r\n        while (r > l && r[-1] == ' ') --r;\r\
    \n        if (!first) cout << ' ';\r\n        first = false;\r\n        std::string\
    \ name(l, r);\r\n        cout << name << \" = \" << args;\r\n      }(),\r\n  \
    \    ...);\r\n  print();\r\n}\r\n\r\n#define SHOW(...) _show_pack(__func__, __LINE__,\
    \ #__VA_ARGS__, __VA_ARGS__)\r\n#else\r\n#define SHOW(...)\r\n#endif\r\n\r\nvoid\
    \ YES(bool t = 1) { print(t ? \"YES\" : \"NO\"); }\r\nvoid NO(bool t = 1) { YES(!t);\
    \ }\r\nvoid Yes(bool t = 1) { print(t ? \"Yes\" : \"No\"); }\r\nvoid No(bool t\
    \ = 1) { Yes(!t); }\r\nvoid yes(bool t = 1) { print(t ? \"yes\" : \"no\"); }\r\
    \nvoid no(bool t = 1) { yes(!t); }\r\n#line 1 \"string/split.hpp\"\nvc<string>\
    \ split(string S, string seps = \" ,\") {\r\n  vc<string> res = {\"\"};\r\n  for\
    \ (auto&& s : S) {\r\n    if (count(all(seps), s))\r\n      res.eb(\"\");\r\n\
    \    else\r\n      res.back() += s;\r\n  }\r\n  return res;\r\n}\r\n#line 6 \"\
    test/4_aoj/ITP1_9_A.test.cpp\"\n\nvoid solve() {\n  STR(T);\n  string S;\n  ll\
    \ ANS = 0;\n  while (getline(cin, S)) {\n    for (auto&& token : split(S, \" \"\
    )) {\n      for (auto&& t : token)\n        if (isupper(t)) t = tolower(t);\n\
    \      ANS += token == T;\n    }\n  }\n  print(ANS);\n}\n\nsigned main() {\n \
    \ solve();\n  return 0;\n}\n"
  code: "#define PROBLEM \\\n  \"https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=ITP1_9_A\"\
    \n#include \"my_template.hpp\"\n#include \"other/io2.hpp\"\n#include \"string/split.hpp\"\
    \n\nvoid solve() {\n  STR(T);\n  string S;\n  ll ANS = 0;\n  while (getline(cin,\
    \ S)) {\n    for (auto&& token : split(S, \" \")) {\n      for (auto&& t : token)\n\
    \        if (isupper(t)) t = tolower(t);\n      ANS += token == T;\n    }\n  }\n\
    \  print(ANS);\n}\n\nsigned main() {\n  solve();\n  return 0;\n}\n"
  dependsOn:
  - my_template.hpp
  - other/io2.hpp
  - string/split.hpp
  isVerificationFile: true
  path: test/4_aoj/ITP1_9_A.test.cpp
  requiredBy: []
  timestamp: '2026-08-15 16:31:09+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: test/4_aoj/ITP1_9_A.test.cpp
layout: document
redirect_from:
- /verify/test/4_aoj/ITP1_9_A.test.cpp
- /verify/test/4_aoj/ITP1_9_A.test.cpp.html
title: test/4_aoj/ITP1_9_A.test.cpp
---
