---
data:
  _extendedDependsOn:
  - icon: ':x:'
    path: game/dyadic_rational.hpp
    title: game/dyadic_rational.hpp
  - icon: ':question:'
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
  bundledCode: "#line 1 \"test/mytest/dyadic_rational.test.cpp\"\n#define PROBLEM\
    \ \"https://judge.yosupo.jp/problem/aplusb\"\n#line 1 \"my_template.hpp\"\n#if\
    \ defined(LOCAL)\n#include <my_template_compiled.hpp>\n#else\n\n// https://codeforces.com/blog/entry/96344\n\
    #pragma GCC optimize(\"Ofast,unroll-loops\")\n// \u3044\u307E\u306E CF \u3060\u3068\
    \u3053\u308C\u5165\u308C\u308B\u3068\u52D5\u304B\u306A\u3044\uFF1F\n// #pragma\
    \ GCC target(\"avx2,popcnt\")\n\n#include <bits/stdc++.h>\n\nusing namespace std;\n\
    \nusing ll = long long;\nusing u32 = unsigned int;\nusing u64 = unsigned long\
    \ long;\nusing i128 = __int128;\nusing u128 = unsigned __int128;\nusing f128 =\
    \ __float128;\n\ntemplate <class T>\nconstexpr T infty = 0;\ntemplate <>\nconstexpr\
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
    \ greater<T>>;\n\n#define vv(type, name, h, ...) \\\n  vector<vector<type>> name(h,\
    \ vector<type>(__VA_ARGS__))\n#define vvv(type, name, h, w, ...)   \\\n  vector<vector<vector<type>>>\
    \ name( \\\n      h, vector<vector<type>>(w, vector<type>(__VA_ARGS__)))\n#define\
    \ vvvv(type, name, a, b, c, ...)       \\\n  vector<vector<vector<vector<type>>>>\
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
    \  return B;\n}\n\ntemplate <typename T, typename... Vectors>\nvc<T> concat(vc<T>\
    \ &first, const Vectors &... others) {\n  vc<T> res = first;\n  (res.insert(res.end(),\
    \ others.begin(), others.end()), ...);\n  return res;\n}\n#endif\n#line 1 \"game/dyadic_rational.hpp\"\
    \n// a+b/2^M \u306E\u5F62\u3067\u6301\u3064\ntemplate <typename INTEGER>\nstruct\
    \ Dyadic_Rational {\n  using X = Dyadic_Rational;\n  INTEGER a, b;\n  static constexpr\
    \ int M = std::numeric_limits<INTEGER>::digits - 2;\n\n  Dyadic_Rational(INTEGER\
    \ a = 0) : a(a), b(0) {}\n\n  // x + y / z\n  Dyadic_Rational(INTEGER x, INTEGER\
    \ y, INTEGER z) : a(x), b(y) {\n    auto [q, r] = divmod(b, z);\n    a += q;\n\
    \    b = r;\n    b *= (INTEGER(1) << M) / z;\n  }\n\n  // x/y\n  Dyadic_Rational(INTEGER\
    \ x, INTEGER y) : Dyadic_Rational(0, x, y) {}\n\n  static X from_ab(INTEGER a,\
    \ INTEGER b) {\n    X x(a);\n    x.b = b;\n    return x;\n  }\n\n  // \u6BD4\u8F03\
    \n  bool operator==(X const& rhs) const { return (a == rhs.a && b == rhs.b); }\n\
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
    \    return std::to_string(y) + \"/\" + std::to_string(z);\n  }\n};\n#line 4 \"\
    test/mytest/dyadic_rational.test.cpp\"\n\nvoid test() {\n  using X = Dyadic_Rational<ll>;\n\
    \  // \u8DB3\u3057\n  assert(X(1) + X(2) == X(3));\n  assert(X(-3) + X(2) == X(-1));\n\
    \  assert(X(-3) + X(3) == X(0));\n  assert(X(3, 8) + X(1, 2) == X(7, 8));\n  assert(X(3,\
    \ 8) + X(3, 8) == X(3, 4));\n  assert(X(3, 8) + X(-3, 8) == X(0));\n  assert(X(2,\
    \ 8) + X(-1, 4) == X(0));\n  // \u5F15\u304D\n  assert(X(1) - X(2) == X(-1));\n\
    \  assert(X(-3) - X(2) == X(-5));\n  assert(X(-3) - X(3) == X(-6));\n  assert(X(3,\
    \ 8) - X(1, 2) == X(-1, 8));\n  assert(X(3, 8) - X(3, 8) == X(0, 1));\n  assert(X(3,\
    \ 8) - X(-3, 8) == X(3, 4));\n  assert(X(2, 8) - X(-1, 4) == X(1, 2));\n  // \u4E0D\
    \u7B49\u53F7\n  assert(X(1) < X(2));\n  assert(X(-3) < X(2));\n  assert(X(-3)\
    \ < X(3));\n  assert(X(3, 8) < X(1, 2));\n  assert(X(3, 8) == X(3, 8));\n  assert(X(3,\
    \ 8) > X(-3, 8));\n  assert(X(2, 8) > X(-1, 4));\n  // {x|y}\n  assert(X::simplest(X(1),\
    \ X(2)) == X(3, 2));\n  assert(X::simplest(X(-3), X(0)) == X(-1));\n  assert(X::simplest(X(1),\
    \ X(5)) == X(2));\n  assert(X::simplest(X(-3), X(1)) == X(0));\n  assert(X::simplest(X(9,\
    \ 16), X(5, 8)) == X(19, 32));\n  assert(X::simplest(X(1, 2), X(2, 1)) == X(1));\n\
    \  assert(X::simplest(X(1, 8), X(5, 8)) == X(1, 2));\n  assert(X::simplest(X(-91,\
    \ 64), X(-41, 32)) == X(-11, 8));\n  assert(X::simplest(X(-3, 2), X(-1, 1)) ==\
    \ X(-5, 4));\n}\n\nvoid solve() {\n  int a, b;\n  cin >> a >> b;\n  cout << a\
    \ + b << \"\\n\";\n}\n\nsigned main() {\n  test();\n  solve();\n  return 0;\n\
    }\n"
  code: "#define PROBLEM \"https://judge.yosupo.jp/problem/aplusb\"\n#include \"my_template.hpp\"\
    \n#include \"game/dyadic_rational.hpp\"\n\nvoid test() {\n  using X = Dyadic_Rational<ll>;\n\
    \  // \u8DB3\u3057\n  assert(X(1) + X(2) == X(3));\n  assert(X(-3) + X(2) == X(-1));\n\
    \  assert(X(-3) + X(3) == X(0));\n  assert(X(3, 8) + X(1, 2) == X(7, 8));\n  assert(X(3,\
    \ 8) + X(3, 8) == X(3, 4));\n  assert(X(3, 8) + X(-3, 8) == X(0));\n  assert(X(2,\
    \ 8) + X(-1, 4) == X(0));\n  // \u5F15\u304D\n  assert(X(1) - X(2) == X(-1));\n\
    \  assert(X(-3) - X(2) == X(-5));\n  assert(X(-3) - X(3) == X(-6));\n  assert(X(3,\
    \ 8) - X(1, 2) == X(-1, 8));\n  assert(X(3, 8) - X(3, 8) == X(0, 1));\n  assert(X(3,\
    \ 8) - X(-3, 8) == X(3, 4));\n  assert(X(2, 8) - X(-1, 4) == X(1, 2));\n  // \u4E0D\
    \u7B49\u53F7\n  assert(X(1) < X(2));\n  assert(X(-3) < X(2));\n  assert(X(-3)\
    \ < X(3));\n  assert(X(3, 8) < X(1, 2));\n  assert(X(3, 8) == X(3, 8));\n  assert(X(3,\
    \ 8) > X(-3, 8));\n  assert(X(2, 8) > X(-1, 4));\n  // {x|y}\n  assert(X::simplest(X(1),\
    \ X(2)) == X(3, 2));\n  assert(X::simplest(X(-3), X(0)) == X(-1));\n  assert(X::simplest(X(1),\
    \ X(5)) == X(2));\n  assert(X::simplest(X(-3), X(1)) == X(0));\n  assert(X::simplest(X(9,\
    \ 16), X(5, 8)) == X(19, 32));\n  assert(X::simplest(X(1, 2), X(2, 1)) == X(1));\n\
    \  assert(X::simplest(X(1, 8), X(5, 8)) == X(1, 2));\n  assert(X::simplest(X(-91,\
    \ 64), X(-41, 32)) == X(-11, 8));\n  assert(X::simplest(X(-3, 2), X(-1, 1)) ==\
    \ X(-5, 4));\n}\n\nvoid solve() {\n  int a, b;\n  cin >> a >> b;\n  cout << a\
    \ + b << \"\\n\";\n}\n\nsigned main() {\n  test();\n  solve();\n  return 0;\n}"
  dependsOn:
  - my_template.hpp
  - game/dyadic_rational.hpp
  isVerificationFile: true
  path: test/mytest/dyadic_rational.test.cpp
  requiredBy: []
  timestamp: '2024-07-22 11:16:29+09:00'
  verificationStatus: TEST_WRONG_ANSWER
  verifiedWith: []
documentation_of: test/mytest/dyadic_rational.test.cpp
layout: document
redirect_from:
- /verify/test/mytest/dyadic_rational.test.cpp
- /verify/test/mytest/dyadic_rational.test.cpp.html
title: test/mytest/dyadic_rational.test.cpp
---
