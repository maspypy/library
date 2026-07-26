---
data:
  _extendedDependsOn:
  - icon: ':question:'
    path: enumerate/product.hpp
    title: enumerate/product.hpp
  - icon: ':question:'
    path: my_template.hpp
    title: my_template.hpp
  - icon: ':heavy_check_mark:'
    path: other/fibonacci_search.hpp
    title: other/fibonacci_search.hpp
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
  bundledCode: "#line 1 \"test/1_mytest/fibonacci_search.test.cpp\"\n#define PROBLEM\
    \ \"https://judge.yosupo.jp/problem/aplusb\"\n#line 1 \"my_template.hpp\"\n#if\
    \ defined(LOCAL)\n#include <my_template_compiled.hpp>\n#else\n#if defined(__GNUC__)\n\
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
    \  (first.insert(first.end(), others.begin(), others.end()), ...);\n}\n#endif\n\
    #line 1 \"other/fibonacci_search.hpp\"\n// returns: {fx, x}\n// [L, R) \u3067\u306E\
    \u6975\u5C0F\u5024\u3092\u3072\u3068\u3064\u6C42\u3081\u308B\u3001\u5358\u5CF0\
    \u306F\u4E0D\u8981\ntemplate <typename T, bool MINIMIZE, typename F>\npair<T,\
    \ ll> fibonacci_search(F f, ll L, ll R) {\n  assert(L < R);\n  --R;\n  ll a =\
    \ L, b = L + 1, c = L + 2, d = L + 3;\n  int n = 0;\n  while (d < R) { b = c,\
    \ c = d, d = b + c - a, ++n; }\n  auto get = [&](ll x) -> T {\n    if (R < x)\
    \ return infty<T>;\n    return (MINIMIZE ? f(x) : -f(x));\n  };\n  T ya = get(a),\
    \ yb = get(b), yc = get(c), yd = get(d);\n  // \u3053\u306E\u4E2D\u3067\u6975\u5C0F\
    \u306A\u3089\u3070\u5168\u4F53\u3067\u3082\u6975\u5C0F\u3001\u3092\u7DAD\u6301\
    \u3059\u308B\n  FOR(n) {\n    if (yb <= yc) {\n      d = c, c = b, b = a + d -\
    \ c;\n      yd = yc, yc = yb, yb = get(b);\n    } else {\n      a = b, b = c,\
    \ c = a + d - b;\n      ya = yb, yb = yc, yc = get(c);\n    }\n  }\n  ll x = a;\n\
    \  T y = ya;\n  if (chmin(y, yb)) x = b;\n  if (chmin(y, yc)) x = c;\n  if (chmin(y,\
    \ yd)) x = d;\n  if (MINIMIZE) return {y, x};\n  return {-y, x};\n}\n#line 2 \"\
    enumerate/product.hpp\"\n\n// [0, A0) x [0, A1) x ...\ntemplate <typename F>\n\
    void enumerate_product(vc<int> A, F query) {\n  int N = len(A);\n  auto dfs =\
    \ [&](auto& dfs, vc<int>& p) -> void {\n    int n = len(p);\n    if (n == N) return\
    \ query(p);\n    FOR(x, A[n]) {\n      p.eb(x);\n      dfs(dfs, p);\n      p.pop_back();\n\
    \    }\n  };\n  vc<int> p;\n  dfs(dfs, p);\n}\n#line 5 \"test/1_mytest/fibonacci_search.test.cpp\"\
    \n\nvoid test() {\n  // permutation\n  FOR(N, 1, 10) {\n    vc<int> A(N);\n  \
    \  iota(all(A), 0);\n    do {\n      auto f = [&](int i) -> int { return A[i];\
    \ };\n      auto [y, i] = fibonacci_search<int, true>(f, 0, N);\n      assert(0\
    \ <= i && i < N);\n      if (0 < i) assert(A[i] < A[i - 1]);\n      if (i + 1\
    \ < N) assert(A[i] < A[i + 1]);\n    } while (next_permutation(all(A)));\n  }\n\
    \  // [0,1]\n  FOR(N, 1, 18) {\n    FOR(s, 1 << N) {\n      vc<int> A(N);\n  \
    \    FOR(i, N) A[i] = s >> i & 1;\n      auto f = [&](int i) -> int { return A[i];\
    \ };\n      auto [y, i] = fibonacci_search<int, true>(f, 0, N);\n      assert(0\
    \ <= i && i < N);\n      if (0 < i) assert(A[i] <= A[i - 1]);\n      if (i + 1\
    \ < N) assert(A[i] <= A[i + 1]);\n    }\n  }\n  // [0,1,2]\n  FOR(N, 1, 13) {\n\
    \    enumerate_product(vc<int>(N, 3), [&](vc<int> A) -> void {\n      auto f =\
    \ [&](int i) -> int { return A[i]; };\n      auto [y, i] = fibonacci_search<int,\
    \ true>(f, 0, N);\n      assert(0 <= i && i < N);\n      if (0 < i) assert(A[i]\
    \ <= A[i - 1]);\n      if (i + 1 < N) assert(A[i] <= A[i + 1]);\n    });\n  }\n\
    }\n\nvoid solve() {\n  int a, b;\n  cin >> a >> b;\n  cout << a + b << \"\\n\"\
    ;\n}\n\nsigned main() {\n  test();\n  solve();\n  return 0;\n}\n"
  code: "#define PROBLEM \"https://judge.yosupo.jp/problem/aplusb\"\n#include \"my_template.hpp\"\
    \n#include \"other/fibonacci_search.hpp\"\n#include \"enumerate/product.hpp\"\n\
    \nvoid test() {\n  // permutation\n  FOR(N, 1, 10) {\n    vc<int> A(N);\n    iota(all(A),\
    \ 0);\n    do {\n      auto f = [&](int i) -> int { return A[i]; };\n      auto\
    \ [y, i] = fibonacci_search<int, true>(f, 0, N);\n      assert(0 <= i && i < N);\n\
    \      if (0 < i) assert(A[i] < A[i - 1]);\n      if (i + 1 < N) assert(A[i] <\
    \ A[i + 1]);\n    } while (next_permutation(all(A)));\n  }\n  // [0,1]\n  FOR(N,\
    \ 1, 18) {\n    FOR(s, 1 << N) {\n      vc<int> A(N);\n      FOR(i, N) A[i] =\
    \ s >> i & 1;\n      auto f = [&](int i) -> int { return A[i]; };\n      auto\
    \ [y, i] = fibonacci_search<int, true>(f, 0, N);\n      assert(0 <= i && i < N);\n\
    \      if (0 < i) assert(A[i] <= A[i - 1]);\n      if (i + 1 < N) assert(A[i]\
    \ <= A[i + 1]);\n    }\n  }\n  // [0,1,2]\n  FOR(N, 1, 13) {\n    enumerate_product(vc<int>(N,\
    \ 3), [&](vc<int> A) -> void {\n      auto f = [&](int i) -> int { return A[i];\
    \ };\n      auto [y, i] = fibonacci_search<int, true>(f, 0, N);\n      assert(0\
    \ <= i && i < N);\n      if (0 < i) assert(A[i] <= A[i - 1]);\n      if (i + 1\
    \ < N) assert(A[i] <= A[i + 1]);\n    });\n  }\n}\n\nvoid solve() {\n  int a,\
    \ b;\n  cin >> a >> b;\n  cout << a + b << \"\\n\";\n}\n\nsigned main() {\n  test();\n\
    \  solve();\n  return 0;\n}\n"
  dependsOn:
  - my_template.hpp
  - other/fibonacci_search.hpp
  - enumerate/product.hpp
  isVerificationFile: true
  path: test/1_mytest/fibonacci_search.test.cpp
  requiredBy: []
  timestamp: '2026-07-26 19:43:20+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: test/1_mytest/fibonacci_search.test.cpp
layout: document
redirect_from:
- /verify/test/1_mytest/fibonacci_search.test.cpp
- /verify/test/1_mytest/fibonacci_search.test.cpp.html
title: test/1_mytest/fibonacci_search.test.cpp
---
