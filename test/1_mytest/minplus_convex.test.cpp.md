---
data:
  _extendedDependsOn:
  - icon: ':question:'
    path: convex/minplus_convolution.hpp
    title: convex/minplus_convolution.hpp
  - icon: ':question:'
    path: my_template.hpp
    title: my_template.hpp
  - icon: ':question:'
    path: random/base.hpp
    title: random/base.hpp
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
  bundledCode: "#line 1 \"test/1_mytest/minplus_convex.test.cpp\"\n#define PROBLEM\
    \ \"https://judge.yosupo.jp/problem/aplusb\"\n#line 1 \"my_template.hpp\"\n#if\
    \ defined(USE_PCH)\n#include <my_template_compiled.hpp>\n#else\n#if defined(__GNUC__)\n\
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
    }\n#endif\n#line 1 \"random/base.hpp\"\n\nu64 RNG_64() {\n  static u64 x_ = u64(chrono::duration_cast<chrono::nanoseconds>(chrono::high_resolution_clock::now().time_since_epoch()).count())\
    \ * 10150724397891781847ULL;\n  x_ ^= x_ << 7;\n  return x_ ^= x_ >> 9;\n}\n\n\
    u64 RNG(u64 lim) { return RNG_64() % lim; }\n\nll RNG(ll l, ll r) { return l +\
    \ RNG_64() % (r - l); }\n#line 1 \"convex/minplus_convolution.hpp\"\n\ntemplate\
    \ <typename T>\nvc<T> minplus_convolution_convex_convex(vc<T>& A, vc<T>& B) {\n\
    \  int n = len(A), m = len(B);\n  if (n == 0 || m == 0) return {};\n  vc<T> C(n\
    \ + m - 1, infty<T>);\n  while (n > 0 && A[n - 1] == infty<T>) --n;\n  while (m\
    \ > 0 && B[m - 1] == infty<T>) --m;\n  if (n == 0 || m == 0) return C;\n  int\
    \ a = 0, b = 0;\n  while (a < n && A[a] == infty<T>) ++a;\n  while (b < m && B[b]\
    \ == infty<T>) ++b;\n  C[a + b] = A[a] + B[b];\n  for (int i = a + b + 1; i <\
    \ n + m - 1; ++i) {\n    if (b == m - 1 || (a != n - 1 && A[a + 1] + B[b] < A[a]\
    \ + B[b + 1])) {\n      chmin(C[i], A[++a] + B[b]);\n    } else {\n      chmin(C[i],\
    \ A[a] + B[++b]);\n    }\n  }\n  return C;\n}\n\ntemplate <typename T>\nvc<T>\
    \ minplus_convolution_arbitrary_convex(vc<T>& A, vc<T>& B) {\n  int n = len(A),\
    \ m0 = len(B);\n  if (n == 0 || m0 == 0) return {};\n  const T INF = infty<T>;\n\
    \  const T BIG = INF + INF + 1;\n\n  vc<T> C(n + m0 - 1, INF);\n\n  int m = m0;\n\
    \  while (m > 0 && B[m - 1] == INF) --m;\n  if (m == 0) return C;\n  int b = 0;\n\
    \  while (b < m && B[b] == INF) ++b;\n\n  int z = n + m - b - 1;\n  vc<int> idx(z\
    \ + 1);\n\n  // \u5B9F\u969B\u306B\u6700\u5C0F\u5024\u63A2\u7D22\u3059\u308B\u90E8\
    \u5206\u3060\u3051 BIG \u306B\u3059\u308B\u3002\n  fill(C.begin() + b, C.begin()\
    \ + n + m - 1, BIG);\n\n  idx[0] = 0;\n  idx[z] = n - 1;\n\n  int d = 1;\n  while\
    \ (d < z) d <<= 1;\n\n  for (int q = d >> 1; q > 0; q >>= 1) {\n    for (int h\
    \ = q; h < z; h += q << 1) {\n      int l = h - q;\n      int r = min(h + q, z);\n\
    \n      idx[h] = idx[l];\n      for (int j = idx[l]; j <= idx[r]; ++j) {\n   \
    \     int k = b + h - j;\n        if (j <= h && k < m && C[b + h] >= A[j] + B[k])\
    \ {\n          C[b + h] = A[j] + B[k];\n          idx[h] = j;\n        }\n   \
    \   }\n    }\n  }\n\n  FOR(h, z) {\n    int j = idx[h];\n    int k = b + h - j;\n\
    \    C[b + h] = (A[j] == INF || B[k] == INF ? INF : A[j] + B[k]);\n  }\n\n  return\
    \ C;\n}\n\ntemplate <typename T, bool convA, bool convB>\nvc<T> minplus_convolution(vc<T>&\
    \ A, vc<T>& B) {\n  static_assert(convA || convB);\n  if constexpr (convA && convB)\
    \ return minplus_convolution_convex_convex(A, B);\n  if constexpr (convA && !convB)\n\
    \    return minplus_convolution_arbitrary_convex(B, A);\n  if constexpr (convB\
    \ && !convA)\n    return minplus_convolution_arbitrary_convex(A, B);\n  return\
    \ {};\n}\n#line 5 \"test/1_mytest/minplus_convex.test.cpp\"\n\nvc<int> gen(int\
    \ L, int N, int R, bool convex) {\n  vc<int> A(N);\n  FOR(i, N) A[i] = RNG(-100,\
    \ 100);\n  if (!convex) return A;\n  sort(all(A));\n  A = cumsum<int>(A);\n  FOR(L)\
    \ A.insert(A.begin(), infty<int>);\n  FOR(R) A.insert(A.end(), infty<int>);\n\
    \  return A;\n}\n\nvc<int> naive(vc<int> A, vc<int> B) {\n  int N = len(A), M\
    \ = len(B);\n  vc<int> C(N + M - 1, infty<int>);\n  FOR(i, N) FOR(j, M) {\n  \
    \  if (A[i] == infty<int> || B[j] == infty<int>) continue;\n    chmin(C[i + j],\
    \ A[i] + B[j]);\n  }\n  return C;\n}\n\nvoid test() {\n  FOR(a1, 5) FOR(b1, 1,\
    \ 10) FOR(c1, 5) {\n    vc<int> A = gen(a1, b1, c1, true);\n    FOR(a2, 5) FOR(b2,\
    \ 1, 10) FOR(c2, 5) {\n      vc<int> B = gen(a2, b2, c2, true);\n      vc<int>\
    \ C = minplus_convolution<int, 1, 1>(A, B);\n      assert(naive(A, B) == C);\n\
    \    }\n  }\n  FOR(a1, 5) FOR(b1, 1, 10) FOR(c1, 5) {\n    vc<int> A = gen(a1,\
    \ b1, c1, true);\n    FOR(a2, 5) FOR(b2, 1, 10) FOR(c2, 5) {\n      vc<int> B\
    \ = gen(a2, b2, c2, false);\n      vc<int> C = minplus_convolution<int, 1, false>(A,\
    \ B);\n      assert(naive(A, B) == C);\n    }\n  }\n}\n\nvoid solve() {\n  int\
    \ a, b;\n  cin >> a >> b;\n  cout << a + b << \"\\n\";\n}\n\nsigned main() {\n\
    \  test();\n  solve();\n\n  return 0;\n}\n"
  code: "#define PROBLEM \"https://judge.yosupo.jp/problem/aplusb\"\n#include \"my_template.hpp\"\
    \n#include \"random/base.hpp\"\n#include \"convex/minplus_convolution.hpp\"\n\n\
    vc<int> gen(int L, int N, int R, bool convex) {\n  vc<int> A(N);\n  FOR(i, N)\
    \ A[i] = RNG(-100, 100);\n  if (!convex) return A;\n  sort(all(A));\n  A = cumsum<int>(A);\n\
    \  FOR(L) A.insert(A.begin(), infty<int>);\n  FOR(R) A.insert(A.end(), infty<int>);\n\
    \  return A;\n}\n\nvc<int> naive(vc<int> A, vc<int> B) {\n  int N = len(A), M\
    \ = len(B);\n  vc<int> C(N + M - 1, infty<int>);\n  FOR(i, N) FOR(j, M) {\n  \
    \  if (A[i] == infty<int> || B[j] == infty<int>) continue;\n    chmin(C[i + j],\
    \ A[i] + B[j]);\n  }\n  return C;\n}\n\nvoid test() {\n  FOR(a1, 5) FOR(b1, 1,\
    \ 10) FOR(c1, 5) {\n    vc<int> A = gen(a1, b1, c1, true);\n    FOR(a2, 5) FOR(b2,\
    \ 1, 10) FOR(c2, 5) {\n      vc<int> B = gen(a2, b2, c2, true);\n      vc<int>\
    \ C = minplus_convolution<int, 1, 1>(A, B);\n      assert(naive(A, B) == C);\n\
    \    }\n  }\n  FOR(a1, 5) FOR(b1, 1, 10) FOR(c1, 5) {\n    vc<int> A = gen(a1,\
    \ b1, c1, true);\n    FOR(a2, 5) FOR(b2, 1, 10) FOR(c2, 5) {\n      vc<int> B\
    \ = gen(a2, b2, c2, false);\n      vc<int> C = minplus_convolution<int, 1, false>(A,\
    \ B);\n      assert(naive(A, B) == C);\n    }\n  }\n}\n\nvoid solve() {\n  int\
    \ a, b;\n  cin >> a >> b;\n  cout << a + b << \"\\n\";\n}\n\nsigned main() {\n\
    \  test();\n  solve();\n\n  return 0;\n}\n"
  dependsOn:
  - my_template.hpp
  - random/base.hpp
  - convex/minplus_convolution.hpp
  isVerificationFile: true
  path: test/1_mytest/minplus_convex.test.cpp
  requiredBy: []
  timestamp: '2026-08-16 04:03:00+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: test/1_mytest/minplus_convex.test.cpp
layout: document
redirect_from:
- /verify/test/1_mytest/minplus_convex.test.cpp
- /verify/test/1_mytest/minplus_convex.test.cpp.html
title: test/1_mytest/minplus_convex.test.cpp
---
