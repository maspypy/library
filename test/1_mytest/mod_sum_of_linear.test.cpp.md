---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: mod/floor_sum_of_linear.hpp
    title: mod/floor_sum_of_linear.hpp
  - icon: ':heavy_check_mark:'
    path: mod/mod_sum_of_linear.hpp
    title: mod/mod_sum_of_linear.hpp
  - icon: ':question:'
    path: my_template.hpp
    title: my_template.hpp
  - icon: ':heavy_check_mark:'
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
  bundledCode: "#line 1 \"test/1_mytest/mod_sum_of_linear.test.cpp\"\n#define PROBLEM\
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
    }\n#endif\n#line 2 \"random/base.hpp\"\n\nu64 RNG_64() {\n  static u64 x_ = u64(chrono::duration_cast<chrono::nanoseconds>(chrono::high_resolution_clock::now().time_since_epoch()).count())\
    \ * 10150724397891781847ULL;\n  x_ ^= x_ << 7;\n  return x_ ^= x_ >> 9;\n}\n\n\
    u64 RNG(u64 lim) { return RNG_64() % lim; }\n\nll RNG(ll l, ll r) { return l +\
    \ RNG_64() % (r - l); }\n#line 4 \"test/1_mytest/mod_sum_of_linear.test.cpp\"\n\
    \n#line 2 \"mod/floor_sum_of_linear.hpp\"\n\n// sum_{x in [L,R)} floor(ax + b,\
    \ mod)\n// I \u306F\u7BC4\u56F2\u5185\u3067 ax+b \u304C\u30AA\u30FC\u30D0\u30FC\
    \u30D5\u30ED\u30FC\u3057\u306A\u3044\u7A0B\u5EA6\ntemplate <typename O = i128,\
    \ typename I = long long>\nO floor_sum_of_linear(I L, I R, I a, I b, I mod) {\n\
    \  assert(L <= R);\n  O res = 0;\n  b += L * a;\n  I N = R - L;\n\n  if (b < 0)\
    \ {\n    I k = ceil(-b, mod);\n    b += k * mod;\n    res -= O(N) * O(k);\n  }\n\
    \n  while (N) {\n    I q;\n    tie(q, a) = divmod(a, mod);\n    res += (N & 1\
    \ ? O(N) * O((N - 1) / 2) * O(q) : O(N / 2) * O(N - 1) * O(q));\n    if (b >=\
    \ mod) {\n      tie(q, b) = divmod(b, mod);\n      res += O(N) * q;\n    }\n \
    \   tie(N, b) = divmod(a * N + b, mod);\n    tie(a, mod) = mp(mod, a);\n  }\n\
    \  return res;\n}\n#line 2 \"mod/mod_sum_of_linear.hpp\"\n\ni128 mod_sum_of_linear(ll\
    \ L, ll R, ll a, ll b, ll mod) {\n  /*\n  sum_{x in [L,R)} (ax + b mod mod)\n\
    \  */\n  i128 s = a * L + b;\n  i128 t = a * (R - 1) + b;\n  i128 sum = (s + t)\
    \ * (R - L) / 2;\n  i128 fsum = floor_sum_of_linear(L, R, a, b, mod);\n  return\
    \ sum - fsum * mod;\n}\n#line 6 \"test/1_mytest/mod_sum_of_linear.test.cpp\"\n\
    \nvoid test() {\n  FOR(100) {\n    int L = RNG(1000);\n    int R = RNG(1000);\n\
    \    if (L > R) swap(L, R);\n    int a = RNG(-1000, 1000);\n    int b = RNG(-1000,\
    \ 1000);\n    int mod = RNG(1, 1000);\n\n    ll ANS = 0;\n    FOR(x, L, R) {\n\
    \      ll v = a * x + b;\n      v %= mod;\n      if (v < 0) v += mod;\n      ANS\
    \ += v;\n    }\n    assert(ANS == mod_sum_of_linear(L, R, a, b, mod));\n  }\n\
    }\n\nvoid solve() {\n  int a, b;\n  cin >> a >> b;\n  cout << a + b << \"\\n\"\
    ;\n}\n\nsigned main() {\n  test();\n  solve();\n\n  return 0;\n}\n"
  code: "#define PROBLEM \"https://judge.yosupo.jp/problem/aplusb\"\n#include \"my_template.hpp\"\
    \n#include \"random/base.hpp\"\n\n#include \"mod/mod_sum_of_linear.hpp\"\n\nvoid\
    \ test() {\n  FOR(100) {\n    int L = RNG(1000);\n    int R = RNG(1000);\n   \
    \ if (L > R) swap(L, R);\n    int a = RNG(-1000, 1000);\n    int b = RNG(-1000,\
    \ 1000);\n    int mod = RNG(1, 1000);\n\n    ll ANS = 0;\n    FOR(x, L, R) {\n\
    \      ll v = a * x + b;\n      v %= mod;\n      if (v < 0) v += mod;\n      ANS\
    \ += v;\n    }\n    assert(ANS == mod_sum_of_linear(L, R, a, b, mod));\n  }\n\
    }\n\nvoid solve() {\n  int a, b;\n  cin >> a >> b;\n  cout << a + b << \"\\n\"\
    ;\n}\n\nsigned main() {\n  test();\n  solve();\n\n  return 0;\n}\n"
  dependsOn:
  - my_template.hpp
  - random/base.hpp
  - mod/mod_sum_of_linear.hpp
  - mod/floor_sum_of_linear.hpp
  isVerificationFile: true
  path: test/1_mytest/mod_sum_of_linear.test.cpp
  requiredBy: []
  timestamp: '2026-08-08 05:13:48+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: test/1_mytest/mod_sum_of_linear.test.cpp
layout: document
redirect_from:
- /verify/test/1_mytest/mod_sum_of_linear.test.cpp
- /verify/test/1_mytest/mod_sum_of_linear.test.cpp.html
title: test/1_mytest/mod_sum_of_linear.test.cpp
---
