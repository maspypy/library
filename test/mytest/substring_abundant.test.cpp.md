---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: my_template.hpp
    title: my_template.hpp
  - icon: ':heavy_check_mark:'
    path: string/run_length.hpp
    title: string/run_length.hpp
  - icon: ':heavy_check_mark:'
    path: string/substring_abundant_string.hpp
    title: string/substring_abundant_string.hpp
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
  bundledCode: "#line 1 \"test/mytest/substring_abundant.test.cpp\"\n#define PROBLEM\
    \ \"https://judge.yosupo.jp/problem/aplusb\"\n#line 1 \"my_template.hpp\"\n#if\
    \ defined(LOCAL)\n#include <my_template_compiled.hpp>\n#else\n#pragma GCC optimize(\"\
    Ofast\")\n#pragma GCC optimize(\"unroll-loops\")\n\n#include <bits/stdc++.h>\n\
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
    \  return B;\n}\n#endif\n#line 1 \"string/run_length.hpp\"\ntemplate <typename\
    \ STRING = string, typename CHAR = char>\nvc<pair<CHAR, int>> run_length(STRING&\
    \ S) {\n  vc<pair<CHAR, int>> res;\n  for (auto&& x: S) {\n    if (res.empty()\
    \ || res.back().fi != x) { res.emplace_back(x, 0); }\n    res.back().se++;\n \
    \ }\n  return res;\n}\n#line 2 \"string/substring_abundant_string.hpp\"\n\n//\
    \ \u90E8\u5206\u6587\u5B57\u5217\u306E\u7A2E\u985E\u6570\u304C\u6700\u5927\u3067\
    \u3042\u308B\u3088\u3046\u306A 01 \u6587\u5B57\u5217\u306E\u69CB\u6210\n// https://qoj.ac/contest/1096/problem/5434?v=1\n\
    // https://oeis.org/A094913\n// https://www.mimuw.edu.pl/~rytter/MYPAPERS/paper.pdf\n\
    string substring_abundant_string(ll N) {\n  ll N0 = N;\n  N = 1;\n  while ((1\
    \ << N) + (N - 1) < N0) ++N;\n\n  string S = [&]() -> string {\n    if (N == 1)\
    \ return \"01\";\n    if (N == 2) return \"00110\";\n\n    auto SHIFT = [&](string\
    \ x, string y) -> string {\n      int n = len(x);\n      x += x;\n      FOR(i,\
    \ n, n + n) {\n        if (x.substr(i - len(y), len(y)) == y) { return x.substr(i\
    \ - n, n); }\n      }\n      return \"\";\n    };\n    auto oplus = [&](string\
    \ x, string y) -> string {\n      int n = topbit(len(y));\n      assert(len(x)\
    \ == (1 << n) && len(y) == (1 << n));\n      return x + SHIFT(y, x.substr(len(x)\
    \ - n, n));\n    };\n    auto NOT = [&](string x) -> string {\n      string y;\n\
    \      for (auto&& s: x) y += (s == '0' ? '1' : '0');\n      return y;\n    };\n\
    \    auto PSI = [&](string x) -> string {\n      int a = 0;\n      FOR(i, len(x))\
    \ {\n        a ^= (x[i] - '0');\n        x[i] = ('0' + a);\n      }\n      return\
    \ x;\n    };\n\n    auto NEXT = [&](string x) -> string {\n      x = PSI(x);\n\
    \      return oplus(x, NOT(x));\n    };\n\n    auto otimes = [&](string x, string\
    \ y) -> string {\n      string t;\n      FOR(topbit(len(x))) t += '0';\n     \
    \ x = SHIFT(x, t);\n      y = SHIFT(y, t);\n      rotate(x.begin(), x.end() -\
    \ len(t), x.end());\n      rotate(y.begin(), y.end() - len(t), y.end());\n\n \
    \     int n = len(x);\n      int x0 = 0, x1 = 0, y0 = 0, y1 = 1;\n      for (auto&&\
    \ [k, v]: run_length(x)) {\n        if (k == '0') chmax(x0, v);\n        if (k\
    \ == '1') chmax(x1, v);\n      }\n      for (auto&& [k, v]: run_length(y)) {\n\
    \        if (k == '0') chmax(y0, v);\n        if (k == '1') chmax(y1, v);\n  \
    \    }\n      string X, Y;\n      for (auto&& [k, v]: run_length(x)) {\n     \
    \   if (k == '0' && v < x0) { X += string(v, k); }\n        if (k == '0' && v\
    \ == x0) { X += string(v - 1, k); }\n        if (k == '1' && v < x1) { X += string(v,\
    \ k); }\n        if (k == '1' && v == x1) { X += string(v + 1, k); }\n      }\n\
    \      for (auto&& [k, v]: run_length(y)) {\n        if (k == '0' && v < y0) {\
    \ Y += string(v, k); }\n        if (k == '0' && v == y0) { Y += string(v + 1,\
    \ k); }\n        if (k == '1' && v < y1) { Y += string(v, k); }\n        if (k\
    \ == '1' && v == y1) { Y += string(v - 1, k); }\n      }\n      return X + Y;\n\
    \    };\n\n    string x = \"0011\", y = \"0011\";\n    FOR(i, 2, N - 1) {\n  \
    \    string t;\n      FOR(i) t += '1';\n      x = SHIFT(x, t);\n      x = NEXT(x);\n\
    \      y = SHIFT(y, t);\n      y = NOT(NEXT(y));\n    }\n    x = otimes(x, y);\n\
    \    FOR(i, N - 1) x += x[i];\n    return x;\n  }();\n  return S.substr(0, N0);\n\
    }\n#line 4 \"test/mytest/substring_abundant.test.cpp\"\n\nvoid test() {\n  auto\
    \ check = [&](ll N) -> bool {\n    string S = substring_abundant_string(N);\n\
    \    assert(len(S) == N);\n    ll ub = 1;\n    FOR(k, 1, N + 1) {\n      ub =\
    \ min(ub * 2, N);\n      ll n = min(ub, N - k + 1);\n      set<string> ss;\n \
    \     FOR(i, N - k + 1) { ss.insert(S.substr(i, k)); }\n      if (len(ss) != n)\
    \ return 0;\n    }\n    return 1;\n  };\n  FOR(n, 1, 100) { assert(check(n));\
    \ }\n}\n\nvoid solve() {\n  int a, b;\n  cin >> a >> b;\n  cout << a + b << \"\
    \\n\";\n}\n\nsigned main() {\n  test();\n  solve();\n  return 0;\n}\n"
  code: "#define PROBLEM \"https://judge.yosupo.jp/problem/aplusb\"\n#include \"my_template.hpp\"\
    \n#include \"string/substring_abundant_string.hpp\"\n\nvoid test() {\n  auto check\
    \ = [&](ll N) -> bool {\n    string S = substring_abundant_string(N);\n    assert(len(S)\
    \ == N);\n    ll ub = 1;\n    FOR(k, 1, N + 1) {\n      ub = min(ub * 2, N);\n\
    \      ll n = min(ub, N - k + 1);\n      set<string> ss;\n      FOR(i, N - k +\
    \ 1) { ss.insert(S.substr(i, k)); }\n      if (len(ss) != n) return 0;\n    }\n\
    \    return 1;\n  };\n  FOR(n, 1, 100) { assert(check(n)); }\n}\n\nvoid solve()\
    \ {\n  int a, b;\n  cin >> a >> b;\n  cout << a + b << \"\\n\";\n}\n\nsigned main()\
    \ {\n  test();\n  solve();\n  return 0;\n}"
  dependsOn:
  - my_template.hpp
  - string/substring_abundant_string.hpp
  - string/run_length.hpp
  isVerificationFile: true
  path: test/mytest/substring_abundant.test.cpp
  requiredBy: []
  timestamp: '2023-11-09 02:18:09+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: test/mytest/substring_abundant.test.cpp
layout: document
redirect_from:
- /verify/test/mytest/substring_abundant.test.cpp
- /verify/test/mytest/substring_abundant.test.cpp.html
title: test/mytest/substring_abundant.test.cpp
---