---
data:
  _extendedDependsOn:
  - icon: ':question:'
    path: game/dyadic_rational.hpp
    title: game/dyadic_rational.hpp
  - icon: ':question:'
    path: game/solve_partizan_game.hpp
    title: game/solve_partizan_game.hpp
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
  bundledCode: "#line 1 \"test/1_mytest/partizan.test.cpp\"\n#define PROBLEM \"https://judge.yosupo.jp/problem/aplusb\"\
    \n\n#line 1 \"my_template.hpp\"\n#if defined(LOCAL)\n#include <my_template_compiled.hpp>\n\
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
    T floor(T a, T b) {\n  return a / b - (a % b && (a ^ b) < 0);\n}\ntemplate <typename\
    \ T>\nT ceil(T x, T y) {\n  return floor(x + y - 1, y);\n}\ntemplate <typename\
    \ T>\nT bmod(T x, T y) {\n  return x - y * floor(x, y);\n}\ntemplate <typename\
    \ T>\npair<T, T> divmod(T x, T y) {\n  T q = floor(x, y);\n  return {q, x - q\
    \ * y};\n}\n\ntemplate <typename T, typename U>\nT SUM(const vector<U> &A) {\n\
    \  T sm = 0;\n  for (auto &&a: A) sm += a;\n  return sm;\n}\n\n#define MIN(v)\
    \ *min_element(all(v))\n#define MAX(v) *max_element(all(v))\n#define LB(c, x)\
    \ distance((c).begin(), lower_bound(all(c), (x)))\n#define UB(c, x) distance((c).begin(),\
    \ upper_bound(all(c), (x)))\n#define UNIQUE(x) sort(all(x)), x.erase(unique(all(x)),\
    \ x.end()), x.shrink_to_fit()\n\ntemplate <typename T>\nT POP(deque<T> &que) {\n\
    \  T a = que.front();\n  que.pop_front();\n  return a;\n}\ntemplate <typename\
    \ T>\nT POP(pq<T> &que) {\n  T a = que.top();\n  que.pop();\n  return a;\n}\n\
    template <typename T>\nT POP(pqg<T> &que) {\n  T a = que.top();\n  que.pop();\n\
    \  return a;\n}\ntemplate <typename T>\nT POP(vc<T> &que) {\n  T a = que.back();\n\
    \  que.pop_back();\n  return a;\n}\n\ntemplate <typename F>\nll binary_search(F\
    \ check, ll ok, ll ng, bool check_ok = true) {\n  if (check_ok) assert(check(ok));\n\
    \  while (abs(ok - ng) > 1) {\n    auto x = (ng + ok) / 2;\n    (check(x) ? ok\
    \ : ng) = x;\n  }\n  return ok;\n}\ntemplate <typename F>\ndouble binary_search_real(F\
    \ check, double ok, double ng, int iter = 100) {\n  FOR(iter) {\n    double x\
    \ = (ok + ng) / 2;\n    (check(x) ? ok : ng) = x;\n  }\n  return (ok + ng) / 2;\n\
    }\n\ntemplate <class T, class S>\ninline bool chmax(T &a, const S &b) {\n  return\
    \ (a < b ? a = b, 1 : 0);\n}\ntemplate <class T, class S>\ninline bool chmin(T\
    \ &a, const S &b) {\n  return (a > b ? a = b, 1 : 0);\n}\n\n// ? \u306F -1\nvc<int>\
    \ s_to_vi(const string &S, char first_char) {\n  vc<int> A(S.size());\n  FOR(i,\
    \ S.size()) { A[i] = (S[i] != '?' ? S[i] - first_char : -1); }\n  return A;\n\
    }\n\ntemplate <typename T, typename U>\nvector<T> cumsum(vector<U> &A, int off\
    \ = 1) {\n  int N = A.size();\n  vector<T> B(N + 1);\n  FOR(i, N) { B[i + 1] =\
    \ B[i] + A[i]; }\n  if (off == 0) B.erase(B.begin());\n  return B;\n}\n\n// stable\
    \ sort\ntemplate <typename T>\nvector<int> argsort(const vector<T> &A) {\n  vector<int>\
    \ ids(len(A));\n  iota(all(ids), 0);\n  sort(all(ids), [&](int i, int j) { return\
    \ (A[i] == A[j] ? i < j : A[i] < A[j]); });\n  return ids;\n}\n\n// A[I[0]], A[I[1]],\
    \ ...\ntemplate <typename T>\nvc<T> rearrange(const vc<T> &A, const vc<int> &I)\
    \ {\n  vc<T> B(len(I));\n  FOR(i, len(I)) B[i] = A[I[i]];\n  return B;\n}\n\n\
    template <typename T, typename... Vectors>\nvoid concat(vc<T> &first, const Vectors\
    \ &... others) {\n  vc<T> &res = first;\n  (res.insert(res.end(), others.begin(),\
    \ others.end()), ...);\n}\n#endif\n#line 1 \"game/dyadic_rational.hpp\"\n// a+b/2^M\
    \ \u306E\u5F62\u3067\u6301\u3064\ntemplate <typename INTEGER>\nstruct Dyadic_Rational\
    \ {\n  using X = Dyadic_Rational;\n  INTEGER a, b;\n  static constexpr int M =\
    \ std::numeric_limits<INTEGER>::digits - 2;\n\n  Dyadic_Rational(INTEGER a = 0)\
    \ : a(a), b(0) {}\n\n  // x + y / z\n  Dyadic_Rational(INTEGER x, INTEGER y, INTEGER\
    \ z) : a(x), b(y) {\n    auto [q, r] = divmod(b, z);\n    a += q;\n    b = r;\n\
    \    b *= (INTEGER(1) << M) / z;\n  }\n\n  // x/y\n  Dyadic_Rational(INTEGER x,\
    \ INTEGER y) : Dyadic_Rational(0, x, y) {}\n\n  static X from_ab(INTEGER a, INTEGER\
    \ b) {\n    X x(a);\n    x.b = b;\n    return x;\n  }\n\n  // \u6BD4\u8F03\n \
    \ bool operator==(X const& rhs) const { return (a == rhs.a && b == rhs.b); }\n\
    \  bool operator!=(X const& rhs) const { return !(*this == rhs); }\n  bool operator<(X\
    \ const& rhs) const {\n    return (a < rhs.a) || (a == rhs.a && b < rhs.b);\n\
    \  }\n  bool operator<=(X const& rhs) const {\n    return (a < rhs.a) || (a ==\
    \ rhs.a && b <= rhs.b);\n  }\n  bool operator>(X const& rhs) const {\n    return\
    \ (a > rhs.a) || (a == rhs.a && b > rhs.b);\n  }\n  bool operator>=(X const& rhs)\
    \ const {\n    return (a > rhs.a) || (a == rhs.a && b >= rhs.b);\n  }\n\n  //\
    \ \u52A0\u6CD5\n  friend X operator+(const X& x, const X& y) {\n    INTEGER a\
    \ = x.a + y.a, b = x.b + y.b;\n    while (b >= INTEGER(1) << M) {\n      ++a;\n\
    \      b -= INTEGER(1) << M;\n    }\n    return from_ab(a, b);\n  }\n  friend\
    \ X operator-(const X& x, const X& y) {\n    INTEGER a = x.a - y.a, b = x.b -\
    \ y.b;\n    while (b < 0) {\n      --a;\n      b += INTEGER(1) << M;\n    }\n\
    \    return from_ab(a, b);\n  }\n  friend X operator-(const X& x) {\n    INTEGER\
    \ a = -x.a, b = -x.b;\n    while (b < 0) {\n      --a;\n      b += INTEGER(1)\
    \ << M;\n    }\n    return from_ab(a, b);\n  }\n  X& operator+=(const X& x) {\
    \ return (*this) = (*this) + x; }\n  X& operator-=(const X& x) { return (*this)\
    \ = (*this) - x; }\n\n  static X simplest(const X& x, const X& y) {\n    assert(x\
    \ < y);\n    if (y.a < 0) return -simplest(-y, -x);\n    {\n      INTEGER l =\
    \ x.a + 1;\n      INTEGER r = (y.b == 0 ? y.a - 1 : y.a);\n      if (l <= 0 &&\
    \ 0 <= r) return X(0);\n      if (l <= r && 0 <= l) return X(l);\n      if (l\
    \ <= r && r <= 0) return X(r);\n    }\n\n    INTEGER l = x.b + 1;\n    INTEGER\
    \ r = (y.b == 0 ? (INTEGER(1) << M) - 1 : y.b - 1);\n    if (l == r) return from_ab(x.a,\
    \ l);\n    int k = topbit(l ^ r);\n    r &= ~((INTEGER(1) << k) - 1);\n    return\
    \ from_ab(x.a, r);\n  }\n\n  static constexpr X infinity() { return from_ab(INTEGER(1)\
    \ << M, 0); }\n\n  string to_string() {\n    ll x = a, y = b, z = INTEGER(1) <<\
    \ M;\n    while (y % 2 == 0 && z % 2 == 0) { y /= 2, z /= 2; }\n    y += x * z;\n\
    \    return std::to_string(y) + \"/\" + std::to_string(z);\n  }\n};\n#line 2 \"\
    game/solve_partizan_game.hpp\"\n\n// \u5168\u90E8 dyadic rational number \u306B\
    \u306A\u308B\u3068\u304D\u3060\u3051\u89E3\u3051\u308B\n// \u5931\u6557\u3057\u305F\
    \u3068\u304D\u306F\u3001empty map \u304C\u8FD4\u308B\n// \u30FBstates\uFF1A\u8208\
    \u5473\u306E\u3042\u308B state \u5168\u4F53\n// \u30FBget_options\uFF1Apair<vc<STATE>,\
    \ vc<STATE>>(STATE), left ops / right ops\ntemplate <typename STATE, typename\
    \ INTEGER, typename F>\nunordered_map<STATE, Dyadic_Rational<INTEGER>> solve_partizan_game(\n\
    \    const vector<STATE>& states, F get_options) {\n  using X = Dyadic_Rational<INTEGER>;\n\
    \  unordered_map<STATE, X> MP;\n\n  bool success = 1;\n\n  auto dfs = [&](auto&\
    \ dfs, const STATE& s) -> X {\n    if (!success) return X();\n    if (MP.count(s))\
    \ return MP[s];\n    vc<X> left, right;\n    X xl = -X::infinity(), xr = X::infinity();\n\
    \    auto [left_ops, right_ops] = get_options(s);\n    for (auto&& t: left_ops)\
    \ chmax(xl, dfs(dfs, t));\n    for (auto&& t: right_ops) chmin(xr, dfs(dfs, t));\n\
    \n    if (xl >= xr) {\n      // switch\n      success = 0;\n      MP.clear();\n\
    \      return X();\n    }\n    return (MP[s] = X::simplest(xl, xr));\n  };\n\n\
    \  for (auto&& s: states) dfs(dfs, s);\n  return MP;\n}\n#line 5 \"test/1_mytest/partizan.test.cpp\"\
    \n\nvoid test_push() {\n  // LESSONS IN PLAY p.113\n  vc<string> states = {\"\
    LR\", \".RL\", \".R\", \"RRL\"};\n  auto get_options = [&](string s) -> pair<vc<string>,\
    \ vc<string>> {\n    vc<string> left_ops, right_ops;\n    FOR(i, len(s)) {\n \
    \     if (s[i] == '.') continue;\n      string t = s;\n      char x = '.';\n \
    \     int p = i;\n      while (p >= 0) {\n        swap(x, t[p--]);\n        if\
    \ (x == '.') break;\n      }\n      if (s[i] == 'L') left_ops.eb(t);\n      if\
    \ (s[i] == 'R') right_ops.eb(t);\n    }\n    return {left_ops, right_ops};\n \
    \ };\n\n  auto MP = solve_partizan_game<string, ll>(states, get_options);\n  //\
    \ for (auto&& [s, x]: MP) { print(s, x.to_string()); }\n  assert(MP[\"LR\"].to_string()\
    \ == \"-3/2\");\n  assert(MP[\".RL\"].to_string() == \"7/4\");\n  assert(MP[\"\
    .R\"].to_string() == \"-2/1\");\n  assert(MP[\"RRL\"].to_string() == \"13/8\"\
    );\n}\n\nvoid test_problem_5_2() {\n  // switch \u306B\u306A\u308B\u306E\u3067\
    \u89E3\u3051\u306A\u3044\n  int LIM = 10;\n  vc<int> states(LIM);\n  iota(all(states),\
    \ 0);\n\n  auto get_options = [&](int s) -> pair<vc<int>, vc<int>> {\n    vc<int>\
    \ left_ops, right_ops;\n    if (s % 3 == 0 && s >= 1) left_ops.eb(s - 1), right_ops.eb(s\
    \ - 1);\n    if (s % 3 == 0 && s >= 2) left_ops.eb(s - 2), right_ops.eb(s - 2);\n\
    \    if (s % 3 == 1 && s >= 1) left_ops.eb(s - 1);\n    if (s % 3 == 1 && s >=\
    \ 2) left_ops.eb(s - 2);\n    if (s % 3 == 2 && s >= 1) right_ops.eb(s - 1);\n\
    \    if (s % 3 == 2 && s >= 2) right_ops.eb(s - 2);\n    return {left_ops, right_ops};\n\
    \  };\n\n  auto MP = solve_partizan_game<int, ll>(states, get_options);\n  assert(MP.empty());\n\
    }\n\nvoid test_problem_5_3() {\n  int LIM = 10;\n  vc<int> states(LIM);\n  iota(all(states),\
    \ 0);\n\n  auto get_options = [&](int s) -> pair<vc<int>, vc<int>> {\n    vc<int>\
    \ left_ops, right_ops;\n    if (s % 2 == 0 && s >= 2) left_ops.eb(s - 2);\n  \
    \  if (s % 2 == 0 && s >= 1) right_ops.eb(s - 1);\n    if (s % 2 == 1 && s >=\
    \ 1) left_ops.eb(s - 1);\n    if (s % 2 == 1 && s >= 2) right_ops.eb(s - 2);\n\
    \    return {left_ops, right_ops};\n  };\n\n  auto MP = solve_partizan_game<int,\
    \ ll>(states, get_options);\n  assert(MP[0].to_string() == \"0/1\");\n  assert(MP[1].to_string()\
    \ == \"1/1\");\n  assert(MP[2].to_string() == \"1/2\");\n  assert(MP[3].to_string()\
    \ == \"3/4\");\n  assert(MP[4].to_string() == \"5/8\");\n  assert(MP[5].to_string()\
    \ == \"11/16\");\n}\n\nint solve_cherries(string s) {\n  // LR cherries \u3092\
    \ O(N) \u3067\u89E3\u304F\n  auto eval = [&](char c) -> int {\n    if (c == 'L')\
    \ return 1;\n    if (c == 'R') return -1;\n    return 0;\n  };\n\n  int n = len(s);\n\
    \  if (n == 0) return 0;\n  int res = 0;\n\n  FOR(2) {\n    reverse(all(s));\n\
    \    while (n >= 2 && s[n - 1] == s[n - 2]) {\n      res += eval(s[n - 1]);\n\
    \      s.pop_back();\n      n = len(s);\n    }\n  }\n\n  char a = '.', b = '.';\n\
    \  FOR_R(i, n - 1) if (s[i] == s[i + 1]) a = s[i];\n  FOR(i, n - 1) if (s[i] ==\
    \ s[i + 1]) b = s[i];\n  int x = eval(s[0]) + eval(a) + eval(b) + eval(s[n - 1]);\n\
    \  return res + x / 2;\n};\n\nvoid test_cherries() {\n  int MAX_LEN = 20;\n  vc<string>\
    \ states;\n  states.eb(\"\");\n  int p = 0, q = 1;\n  FOR(MAX_LEN) {\n    FOR(i,\
    \ p, q) {\n      states.eb(states[i] + \"L\");\n      states.eb(states[i] + \"\
    R\");\n    }\n    p = q;\n    q = len(states);\n  }\n\n  auto get_options = [&](string\
    \ s) -> pair<vc<string>, vc<string>> {\n    vc<string> left, right;\n    int n\
    \ = len(s);\n\n    if (n && s[0] == 'L') left.eb(s.substr(1, n - 1));\n    if\
    \ (n && s[0] == 'R') right.eb(s.substr(1, n - 1));\n    if (n && s[n - 1] == 'L')\
    \ left.eb(s.substr(0, n - 1));\n    if (n && s[n - 1] == 'R') right.eb(s.substr(0,\
    \ n - 1));\n    return {left, right};\n  };\n\n  auto MP = solve_partizan_game<string,\
    \ ll>(states, get_options);\n\n  for (auto&& [s, x]: MP) {\n    int my_ans = solve_cherries(s);\n\
    \    assert(x == Dyadic_Rational<ll>(my_ans, 1));\n  }\n}\n\nvoid test() {\n \
    \ test_push();\n  test_problem_5_2();\n  test_problem_5_3();\n  test_cherries();\n\
    }\n\nvoid solve() {\n  int a, b;\n  cin >> a >> b;\n  cout << a + b << \"\\n\"\
    ;\n}\n\nsigned main() {\n  test();\n  solve();\n  return 0;\n}\n"
  code: "#define PROBLEM \"https://judge.yosupo.jp/problem/aplusb\"\n\n#include \"\
    my_template.hpp\"\n#include \"game/solve_partizan_game.hpp\"\n\nvoid test_push()\
    \ {\n  // LESSONS IN PLAY p.113\n  vc<string> states = {\"LR\", \".RL\", \".R\"\
    , \"RRL\"};\n  auto get_options = [&](string s) -> pair<vc<string>, vc<string>>\
    \ {\n    vc<string> left_ops, right_ops;\n    FOR(i, len(s)) {\n      if (s[i]\
    \ == '.') continue;\n      string t = s;\n      char x = '.';\n      int p = i;\n\
    \      while (p >= 0) {\n        swap(x, t[p--]);\n        if (x == '.') break;\n\
    \      }\n      if (s[i] == 'L') left_ops.eb(t);\n      if (s[i] == 'R') right_ops.eb(t);\n\
    \    }\n    return {left_ops, right_ops};\n  };\n\n  auto MP = solve_partizan_game<string,\
    \ ll>(states, get_options);\n  // for (auto&& [s, x]: MP) { print(s, x.to_string());\
    \ }\n  assert(MP[\"LR\"].to_string() == \"-3/2\");\n  assert(MP[\".RL\"].to_string()\
    \ == \"7/4\");\n  assert(MP[\".R\"].to_string() == \"-2/1\");\n  assert(MP[\"\
    RRL\"].to_string() == \"13/8\");\n}\n\nvoid test_problem_5_2() {\n  // switch\
    \ \u306B\u306A\u308B\u306E\u3067\u89E3\u3051\u306A\u3044\n  int LIM = 10;\n  vc<int>\
    \ states(LIM);\n  iota(all(states), 0);\n\n  auto get_options = [&](int s) ->\
    \ pair<vc<int>, vc<int>> {\n    vc<int> left_ops, right_ops;\n    if (s % 3 ==\
    \ 0 && s >= 1) left_ops.eb(s - 1), right_ops.eb(s - 1);\n    if (s % 3 == 0 &&\
    \ s >= 2) left_ops.eb(s - 2), right_ops.eb(s - 2);\n    if (s % 3 == 1 && s >=\
    \ 1) left_ops.eb(s - 1);\n    if (s % 3 == 1 && s >= 2) left_ops.eb(s - 2);\n\
    \    if (s % 3 == 2 && s >= 1) right_ops.eb(s - 1);\n    if (s % 3 == 2 && s >=\
    \ 2) right_ops.eb(s - 2);\n    return {left_ops, right_ops};\n  };\n\n  auto MP\
    \ = solve_partizan_game<int, ll>(states, get_options);\n  assert(MP.empty());\n\
    }\n\nvoid test_problem_5_3() {\n  int LIM = 10;\n  vc<int> states(LIM);\n  iota(all(states),\
    \ 0);\n\n  auto get_options = [&](int s) -> pair<vc<int>, vc<int>> {\n    vc<int>\
    \ left_ops, right_ops;\n    if (s % 2 == 0 && s >= 2) left_ops.eb(s - 2);\n  \
    \  if (s % 2 == 0 && s >= 1) right_ops.eb(s - 1);\n    if (s % 2 == 1 && s >=\
    \ 1) left_ops.eb(s - 1);\n    if (s % 2 == 1 && s >= 2) right_ops.eb(s - 2);\n\
    \    return {left_ops, right_ops};\n  };\n\n  auto MP = solve_partizan_game<int,\
    \ ll>(states, get_options);\n  assert(MP[0].to_string() == \"0/1\");\n  assert(MP[1].to_string()\
    \ == \"1/1\");\n  assert(MP[2].to_string() == \"1/2\");\n  assert(MP[3].to_string()\
    \ == \"3/4\");\n  assert(MP[4].to_string() == \"5/8\");\n  assert(MP[5].to_string()\
    \ == \"11/16\");\n}\n\nint solve_cherries(string s) {\n  // LR cherries \u3092\
    \ O(N) \u3067\u89E3\u304F\n  auto eval = [&](char c) -> int {\n    if (c == 'L')\
    \ return 1;\n    if (c == 'R') return -1;\n    return 0;\n  };\n\n  int n = len(s);\n\
    \  if (n == 0) return 0;\n  int res = 0;\n\n  FOR(2) {\n    reverse(all(s));\n\
    \    while (n >= 2 && s[n - 1] == s[n - 2]) {\n      res += eval(s[n - 1]);\n\
    \      s.pop_back();\n      n = len(s);\n    }\n  }\n\n  char a = '.', b = '.';\n\
    \  FOR_R(i, n - 1) if (s[i] == s[i + 1]) a = s[i];\n  FOR(i, n - 1) if (s[i] ==\
    \ s[i + 1]) b = s[i];\n  int x = eval(s[0]) + eval(a) + eval(b) + eval(s[n - 1]);\n\
    \  return res + x / 2;\n};\n\nvoid test_cherries() {\n  int MAX_LEN = 20;\n  vc<string>\
    \ states;\n  states.eb(\"\");\n  int p = 0, q = 1;\n  FOR(MAX_LEN) {\n    FOR(i,\
    \ p, q) {\n      states.eb(states[i] + \"L\");\n      states.eb(states[i] + \"\
    R\");\n    }\n    p = q;\n    q = len(states);\n  }\n\n  auto get_options = [&](string\
    \ s) -> pair<vc<string>, vc<string>> {\n    vc<string> left, right;\n    int n\
    \ = len(s);\n\n    if (n && s[0] == 'L') left.eb(s.substr(1, n - 1));\n    if\
    \ (n && s[0] == 'R') right.eb(s.substr(1, n - 1));\n    if (n && s[n - 1] == 'L')\
    \ left.eb(s.substr(0, n - 1));\n    if (n && s[n - 1] == 'R') right.eb(s.substr(0,\
    \ n - 1));\n    return {left, right};\n  };\n\n  auto MP = solve_partizan_game<string,\
    \ ll>(states, get_options);\n\n  for (auto&& [s, x]: MP) {\n    int my_ans = solve_cherries(s);\n\
    \    assert(x == Dyadic_Rational<ll>(my_ans, 1));\n  }\n}\n\nvoid test() {\n \
    \ test_push();\n  test_problem_5_2();\n  test_problem_5_3();\n  test_cherries();\n\
    }\n\nvoid solve() {\n  int a, b;\n  cin >> a >> b;\n  cout << a + b << \"\\n\"\
    ;\n}\n\nsigned main() {\n  test();\n  solve();\n  return 0;\n}"
  dependsOn:
  - my_template.hpp
  - game/solve_partizan_game.hpp
  - game/dyadic_rational.hpp
  isVerificationFile: true
  path: test/1_mytest/partizan.test.cpp
  requiredBy: []
  timestamp: '2024-11-07 04:20:47+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: test/1_mytest/partizan.test.cpp
layout: document
redirect_from:
- /verify/test/1_mytest/partizan.test.cpp
- /verify/test/1_mytest/partizan.test.cpp.html
title: test/1_mytest/partizan.test.cpp
---
