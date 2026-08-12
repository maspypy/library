---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: convex/nth_element_from_sorted_matrix.hpp
    title: convex/nth_element_from_sorted_matrix.hpp
  - icon: ':question:'
    path: my_template.hpp
    title: my_template.hpp
  - icon: ':question:'
    path: random/base.hpp
    title: random/base.hpp
  - icon: ':heavy_check_mark:'
    path: random/shuffle.hpp
    title: random/shuffle.hpp
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
  bundledCode: "#line 1 \"test/1_mytest/nth_element_from_sorted_matrix.test.cpp\"\n\
    #define PROBLEM \"https://judge.yosupo.jp/problem/aplusb\"\n#line 1 \"my_template.hpp\"\
    \n#if defined(USE_PCH)\n#include <my_template_compiled.hpp>\n#else\n#if defined(__GNUC__)\n\
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
    }\n#endif\n#line 3 \"test/1_mytest/nth_element_from_sorted_matrix.test.cpp\"\n\
    \n#line 2 \"random/base.hpp\"\n\nu64 RNG_64() {\n  static u64 x_ = u64(chrono::duration_cast<chrono::nanoseconds>(chrono::high_resolution_clock::now().time_since_epoch()).count())\
    \ * 10150724397891781847ULL;\n  x_ ^= x_ << 7;\n  return x_ ^= x_ >> 9;\n}\n\n\
    u64 RNG(u64 lim) { return RNG_64() % lim; }\n\nll RNG(ll l, ll r) { return l +\
    \ RNG_64() % (r - l); }\n#line 2 \"random/shuffle.hpp\"\n\ntemplate <typename\
    \ T>\nvoid shuffle(vc<T>& A) {\n  FOR(i, len(A)) {\n    int j = RNG(0, i + 1);\n\
    \    if (i != j) swap(A[i], A[j]);\n  }\n}\n#line 1 \"convex/nth_element_from_sorted_matrix.hpp\"\
    \n\n// https://uoj.ac/problem/891\ntemplate <typename T, typename F>\nvi nth_element_from_sorted_matrix(ll\
    \ N, ll M, ll K, F f, int k1 = 0, int k2 = 0,\n                              \
    \    bool tr = false) {\n  if (K == 0) return vi(N, 0);\n  if (N > M) {\n    vi\
    \ A = nth_element_from_sorted_matrix<T>(M, N, K, f, k2, k1, !tr);\n    vi B(N\
    \ + 1);\n    FOR(i, M) B[0] += 1, B[A[i]] -= 1;\n    FOR(i, N) B[i + 1] += B[i];\n\
    \    B.pop_back();\n    return B;\n  }\n  vi A(N);\n  if (K > N) {\n    A = nth_element_from_sorted_matrix<T>(N,\
    \ M / 2, (K - N) / 2, f, k1, k2 + 1,\n                                       \
    \   tr);\n    for (auto &a : A) a *= 2;\n    K = K - (K - N) / 2 * 2;\n  }\n \
    \ pq_min<pair<T, int>> que;\n  auto g = [&](ll i, ll j) -> T {\n    i = ((i +\
    \ 1) << k1) - 1;\n    j = ((j + 1) << k2) - 1;\n    return (tr ? f(j, i) : f(i,\
    \ j));\n  };\n  if (A[0] < M) que.emplace(g(0, A[0]), 0);\n  FOR(i, 1, N) if (A[i]\
    \ < A[i - 1]) que.emplace(g(i, A[i]), i);\n  while (K) {\n    --K;\n    auto [x,\
    \ i] = POP(que);\n    A[i]++;\n    if (K == 0) break;\n    if (A[i] < M && (i\
    \ == 0 || A[i - 1] > A[i])) {\n      que.emplace(g(i, A[i]), i);\n    }\n    if\
    \ (i + 1 < N && A[i + 1] == A[i] - 1) {\n      que.emplace(g(i + 1, A[i + 1]),\
    \ i + 1);\n    }\n  }\n  return A;\n}\n#line 7 \"test/1_mytest/nth_element_from_sorted_matrix.test.cpp\"\
    \n\nvoid test() {\n  ll N = RNG(1, 20);\n  ll M = RNG(1, 20);\n  vv(int, A, N,\
    \ M);\n  vc<pair<int, int>> IJ;\n  FOR(i, N) FOR(j, M) IJ.eb(i, j);\n  shuffle(IJ);\n\
    \  FOR(k, len(IJ)) {\n    auto [i, j] = IJ[k];\n    A[i][j] = k;\n  }\n\n  FOR(i,\
    \ N) sort(all(A[i]));\n  FOR(j, M) {\n    vc<int> col(N);\n    FOR(i, N) col[i]\
    \ = A[i][j];\n    sort(all(col));\n    FOR(i, N) A[i][j] = col[i];\n  }\n  if\
    \ (RNG(0, 2)) {\n    vv(int, B, M, N);\n    FOR(i, N) FOR(j, M) B[j][i] = A[i][j];\n\
    \    swap(A, B);\n    swap(N, M);\n  }\n\n  int K = RNG(0, N * M + 1);\n  auto\
    \ f = [&](int i, int j) -> int { return A[i][j]; };\n\n  vi L = nth_element_from_sorted_matrix<int>(N,\
    \ M, K, f);\n\n  FOR(i, N) {\n    FOR(j, L[i]) { assert(A[i][j] < K); }\n    FOR(j,\
    \ L[i], M) { assert(A[i][j] >= K); }\n  }\n}\n\nvoid test2() {\n  ll N = RNG(1,\
    \ 20);\n  ll M = N;\n  vv(int, A, N, M);\n  vc<pair<int, int>> IJ;\n  FOR(i, N)\
    \ FOR(j, M) IJ.eb(i, j);\n  shuffle(IJ);\n  FOR(k, len(IJ)) {\n    auto [i, j]\
    \ = IJ[k];\n    A[i][j] = k;\n  }\n\n  FOR(i, N) sort(all(A[i]));\n  FOR(j, M)\
    \ {\n    vc<int> col(N);\n    FOR(i, N) col[i] = A[i][j];\n    sort(all(col));\n\
    \    FOR(i, N) A[i][j] = col[i];\n  }\n  if (RNG(0, 2)) {\n    vv(int, B, M, N);\n\
    \    FOR(i, N) FOR(j, M) B[j][i] = A[i][j];\n    swap(A, B);\n    swap(N, M);\n\
    \  }\n\n  int K = RNG(0, N * M + 1);\n  set<pair<int, int>> st;\n  auto f = [&](int\
    \ i, int j) -> int {\n    st.insert(mp(i, j));\n    return A[i][j];\n  };\n\n\
    \  nth_element_from_sorted_matrix<int>(N, M, K, f);\n  int QLE = len(st);\n  assert(QLE\
    \ <= 5 * N);\n}\n\nvoid solve() {\n  int a, b;\n  cin >> a >> b;\n  cout << a\
    \ + b << \"\\n\";\n}\n\nsigned main() {\n  FOR(50000) test();\n  FOR(50000) test2();\n\
    \  solve();\n  return 0;\n}\n"
  code: "#define PROBLEM \"https://judge.yosupo.jp/problem/aplusb\"\n#include \"my_template.hpp\"\
    \n\n#include \"random/base.hpp\"\n#include \"random/shuffle.hpp\"\n#include \"\
    convex/nth_element_from_sorted_matrix.hpp\"\n\nvoid test() {\n  ll N = RNG(1,\
    \ 20);\n  ll M = RNG(1, 20);\n  vv(int, A, N, M);\n  vc<pair<int, int>> IJ;\n\
    \  FOR(i, N) FOR(j, M) IJ.eb(i, j);\n  shuffle(IJ);\n  FOR(k, len(IJ)) {\n   \
    \ auto [i, j] = IJ[k];\n    A[i][j] = k;\n  }\n\n  FOR(i, N) sort(all(A[i]));\n\
    \  FOR(j, M) {\n    vc<int> col(N);\n    FOR(i, N) col[i] = A[i][j];\n    sort(all(col));\n\
    \    FOR(i, N) A[i][j] = col[i];\n  }\n  if (RNG(0, 2)) {\n    vv(int, B, M, N);\n\
    \    FOR(i, N) FOR(j, M) B[j][i] = A[i][j];\n    swap(A, B);\n    swap(N, M);\n\
    \  }\n\n  int K = RNG(0, N * M + 1);\n  auto f = [&](int i, int j) -> int { return\
    \ A[i][j]; };\n\n  vi L = nth_element_from_sorted_matrix<int>(N, M, K, f);\n\n\
    \  FOR(i, N) {\n    FOR(j, L[i]) { assert(A[i][j] < K); }\n    FOR(j, L[i], M)\
    \ { assert(A[i][j] >= K); }\n  }\n}\n\nvoid test2() {\n  ll N = RNG(1, 20);\n\
    \  ll M = N;\n  vv(int, A, N, M);\n  vc<pair<int, int>> IJ;\n  FOR(i, N) FOR(j,\
    \ M) IJ.eb(i, j);\n  shuffle(IJ);\n  FOR(k, len(IJ)) {\n    auto [i, j] = IJ[k];\n\
    \    A[i][j] = k;\n  }\n\n  FOR(i, N) sort(all(A[i]));\n  FOR(j, M) {\n    vc<int>\
    \ col(N);\n    FOR(i, N) col[i] = A[i][j];\n    sort(all(col));\n    FOR(i, N)\
    \ A[i][j] = col[i];\n  }\n  if (RNG(0, 2)) {\n    vv(int, B, M, N);\n    FOR(i,\
    \ N) FOR(j, M) B[j][i] = A[i][j];\n    swap(A, B);\n    swap(N, M);\n  }\n\n \
    \ int K = RNG(0, N * M + 1);\n  set<pair<int, int>> st;\n  auto f = [&](int i,\
    \ int j) -> int {\n    st.insert(mp(i, j));\n    return A[i][j];\n  };\n\n  nth_element_from_sorted_matrix<int>(N,\
    \ M, K, f);\n  int QLE = len(st);\n  assert(QLE <= 5 * N);\n}\n\nvoid solve()\
    \ {\n  int a, b;\n  cin >> a >> b;\n  cout << a + b << \"\\n\";\n}\n\nsigned main()\
    \ {\n  FOR(50000) test();\n  FOR(50000) test2();\n  solve();\n  return 0;\n}"
  dependsOn:
  - my_template.hpp
  - random/base.hpp
  - random/shuffle.hpp
  - convex/nth_element_from_sorted_matrix.hpp
  isVerificationFile: true
  path: test/1_mytest/nth_element_from_sorted_matrix.test.cpp
  requiredBy: []
  timestamp: '2026-08-11 20:16:07+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: test/1_mytest/nth_element_from_sorted_matrix.test.cpp
layout: document
redirect_from:
- /verify/test/1_mytest/nth_element_from_sorted_matrix.test.cpp
- /verify/test/1_mytest/nth_element_from_sorted_matrix.test.cpp.html
title: test/1_mytest/nth_element_from_sorted_matrix.test.cpp
---
