---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: my_template.hpp
    title: my_template.hpp
  - icon: ':heavy_check_mark:'
    path: other/reduce_intervals.hpp
    title: other/reduce_intervals.hpp
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
  bundledCode: "#line 1 \"test/1_mytest/reduce_intervals.test.cpp\"\n#define PROBLEM\
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
    template <>\nconstexpr double infty<double> = infty<i128>;\ntemplate <>\nconstexpr\
    \ long double infty<long double> = infty<i128>;\n\nusing pi = pair<ll, ll>;\n\
    using vi = vector<ll>;\ntemplate <class T>\nusing vc = vector<T>;\ntemplate <class\
    \ T>\nusing vvc = vector<vc<T>>;\ntemplate <class T>\nusing vvvc = vector<vvc<T>>;\n\
    template <class T>\nusing vvvvc = vector<vvvc<T>>;\ntemplate <class T>\nusing\
    \ pq_max = priority_queue<T>;\ntemplate <class T>\nusing pq_min = priority_queue<T,\
    \ vector<T>, greater<T>>;\n\n#define vv(type, name, h, ...) \\\n  vector<vector<type>>\
    \ name(h, vector<type>(__VA_ARGS__))\n#define vvv(type, name, h, w, ...)   \\\n\
    \  vector<vector<vector<type>>> name( \\\n      h, vector<vector<type>>(w, vector<type>(__VA_ARGS__)))\n\
    #define vvvv(type, name, a, b, c, ...)       \\\n  vector<vector<vector<vector<type>>>>\
    \ name( \\\n      a, vector<vector<vector<type>>>(       \\\n             b, vector<vector<type>>(c,\
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
    \  return a;\n}\n\ntemplate <typename F>\ni128 binary_search(F check, i128 ok,\
    \ i128 ng, bool check_ok = true) {\n  if (check_ok) assert(check(ok));\n  while\
    \ (1) {\n    i128 x = (ok + ng) / 2;\n    if (x == ok || x == ng) break;\n   \
    \ (check(x) ? ok : ng) = x;\n  }\n  return ok;\n}\n\ntemplate <typename F>\ndouble\
    \ binary_search_real(F check, double ok, double ng, int iter = 100) {\n  FOR(iter)\
    \ {\n    double x = (ok + ng) / 2;\n    (check(x) ? ok : ng) = x;\n  }\n  return\
    \ (ok + ng) / 2;\n}\n\ntemplate <class T, class S>\ninline bool chmax(T &a, const\
    \ S &b) {\n  T c = max<T>(a, b);\n  bool changed = (c != a);\n  a = c;\n  return\
    \ changed;\n}\ntemplate <class T, class S>\ninline bool chmin(T &a, const S &b)\
    \ {\n  T c = min<T>(a, b);\n  bool changed = (c != a);\n  a = c;\n  return changed;\n\
    }\n\n// ? \u306F -1\nvc<int> s_to_vi(const string &S, char first_char) {\n  vc<int>\
    \ A(S.size());\n  FOR(i, S.size()) { A[i] = (S[i] != '?' ? S[i] - first_char :\
    \ -1); }\n  return A;\n}\n\ntemplate <typename T, typename U>\nvc<T> cumsum(const\
    \ vc<U> &A, int off = 1) {\n  int N = A.size();\n  vc<T> B(N + 1);\n  FOR(i, N)\
    \ { B[i + 1] = B[i] + A[i]; }\n  if (off == 0) B.erase(B.begin());\n  return B;\n\
    }\n\n// stable sort\ntemplate <typename T>\nvc<int> argsort(const vc<T> &A) {\n\
    \  vc<int> ids(len(A));\n  iota(all(ids), 0);\n  sort(all(ids),\n      [&](int\
    \ i, int j) { return (A[i] == A[j] ? i < j : A[i] < A[j]); });\n  return ids;\n\
    }\n\n// A[I[0]], A[I[1]], ...\ntemplate <typename T>\nvc<T> rearrange(const vc<T>\
    \ &A, const vc<int> &I) {\n  vc<T> B(len(I));\n  FOR(i, len(I)) B[i] = A[I[i]];\n\
    \  return B;\n}\n\ntemplate <typename T, typename... Vectors>\nvoid concat(vc<T>\
    \ &first, const Vectors &...others) {\n  first.reserve(first.size() + (others.size()\
    \ + ... + 0));\n  (first.insert(first.end(), others.begin(), others.end()), ...);\n\
    }\n\n// i128\ntemplate <class T, enable_if_t<is_same_v<T, i128>, int> = 0>\nconstexpr\
    \ i128 abs(T x) {\n  return x < 0 ? -x : x;\n}\n\nconstexpr i128 gcd(i128 a, i128\
    \ b) {\n  while (b != 0) {\n    i128 c = a % b;\n    a = b, b = c;\n  }\n  return\
    \ abs(a);\n}\n#endif\n#line 3 \"test/1_mytest/reduce_intervals.test.cpp\"\n\n\
    #line 1 \"other/reduce_intervals.hpp\"\n\n// rm_included = true : I < J \u3068\
    \u306A\u308B J \u304C\u5B58\u5728\u3059\u308C\u3070 I \u3092\u6D88\u3059\n// rm_included\
    \ = false : I > J \u3068\u306A\u308B J \u304C\u5B58\u5728\u3059\u308C\u3070 I\
    \ \u3092\u6D88\u3059\n// \u6B8B\u3059\u533A\u9593\u306E\u30A4\u30F3\u30C7\u30C3\
    \u30AF\u30B9\u3092\u533A\u9593\u306E\u9806\u5E8F\u306B\u3064\u3044\u3066\u30BD\
    \u30FC\u30C8\u3057\u3066\u8FD4\u3059\n// \u5B8C\u5168\u306B\u540C\u3058\u533A\u9593\
    \u306F\u4EFB\u610F\u306B\u9078\u3093\u3060\u3072\u3068\u3064\u3060\u3051\u6B8B\
    \u3059\ntemplate <typename T>\nvc<int> reduce_intervals(vc<T> L, vc<T> R, bool\
    \ rm_included) {\n  int N = len(L);\n  vc<int> ANS;\n  vc<int> I(N);\n  FOR(i,\
    \ N) I[i] = i;\n  if (rm_included) {\n    sort(all(I), [&](auto &a, auto &b) ->\
    \ bool {\n      if (L[a] != L[b])\n        return L[a] < L[b];\n      return R[a]\
    \ > R[b];\n    });\n    for (auto &j : I) {\n      if (!ANS.empty()) {\n     \
    \   int i = ANS.back();\n        if (R[j] <= R[i])\n          continue;\n    \
    \  }\n      ANS.eb(j);\n    }\n  } else {\n    sort(all(I), [&](auto &a, auto\
    \ &b) -> bool {\n      if (R[a] != R[b])\n        return R[a] < R[b];\n      return\
    \ L[a] > L[b];\n    });\n    for (auto &j : I) {\n      if (!ANS.empty()) {\n\
    \        int i = ANS.back();\n        if (L[j] <= L[i])\n          continue;\n\
    \      }\n      ANS.eb(j);\n    }\n  }\n  return ANS;\n}\n#line 1 \"random/base.hpp\"\
    \n\nu64 RNG_64() {\n  static u64 x_ = u64(chrono::duration_cast<chrono::nanoseconds>(\n\
    \                      chrono::high_resolution_clock::now().time_since_epoch())\n\
    \                          .count()) *\n                  10150724397891781847ULL;\n\
    \  x_ ^= x_ << 7;\n  return x_ ^= x_ >> 9;\n}\n\nu64 RNG(u64 lim) {\n  assert(lim\
    \ > 0);\n  return RNG_64() % lim;\n}\n\nll RNG(ll l, ll r) {\n  assert(l < r);\n\
    \  return l + RNG_64() % (r - l);\n}\n#line 6 \"test/1_mytest/reduce_intervals.test.cpp\"\
    \n\nvoid test(bool rm_included) {\n  FOR(mx, 100) {\n    FOR(NN, 100) {\n    \
    \  set<pair<int, int>> st;\n      vc<int> L, R;\n      FOR(i, NN) {\n        int\
    \ a = RNG(0, mx + 1);\n        int b = RNG(0, mx + 1);\n        if (a > b)\n \
    \         swap(a, b);\n        pair<int, int> p = {a, b};\n        if (st.count(p))\n\
    \          continue;\n        st.insert(p);\n        L.eb(a), R.eb(b);\n     \
    \ }\n      int N = len(L);\n      auto I = reduce_intervals(L, R, rm_included);\n\
    \      vc<int> er(N, 1);\n      for (auto &i : I)\n        er[i] = 0;\n      FOR(i,\
    \ N) if (er[i]) {\n        bool ok = 0;\n        for (auto &j : I) {\n       \
    \   if (rm_included && L[j] <= L[i] && R[i] <= R[j])\n            ok = 1;\n  \
    \        if (!rm_included && L[i] <= L[j] && R[j] <= R[i])\n            ok = 1;\n\
    \        }\n        assert(ok);\n      }\n      L = rearrange(L, I);\n      R\
    \ = rearrange(R, I);\n      FOR(k, len(L) - 1) { assert(L[k] < L[k + 1] && R[k]\
    \ < R[k + 1]); }\n    }\n  }\n}\n\nvoid solve() {\n  int a, b;\n  cin >> a >>\
    \ b;\n  cout << a + b << '\\n';\n}\n\nsigned main() {\n  test(false);\n  test(true);\n\
    \  solve();\n  return 0;\n}\n"
  code: "#define PROBLEM \"https://judge.yosupo.jp/problem/aplusb\"\n#include \"my_template.hpp\"\
    \n\n#include \"other/reduce_intervals.hpp\"\n#include \"random/base.hpp\"\n\n\
    void test(bool rm_included) {\n  FOR(mx, 100) {\n    FOR(NN, 100) {\n      set<pair<int,\
    \ int>> st;\n      vc<int> L, R;\n      FOR(i, NN) {\n        int a = RNG(0, mx\
    \ + 1);\n        int b = RNG(0, mx + 1);\n        if (a > b)\n          swap(a,\
    \ b);\n        pair<int, int> p = {a, b};\n        if (st.count(p))\n        \
    \  continue;\n        st.insert(p);\n        L.eb(a), R.eb(b);\n      }\n    \
    \  int N = len(L);\n      auto I = reduce_intervals(L, R, rm_included);\n    \
    \  vc<int> er(N, 1);\n      for (auto &i : I)\n        er[i] = 0;\n      FOR(i,\
    \ N) if (er[i]) {\n        bool ok = 0;\n        for (auto &j : I) {\n       \
    \   if (rm_included && L[j] <= L[i] && R[i] <= R[j])\n            ok = 1;\n  \
    \        if (!rm_included && L[i] <= L[j] && R[j] <= R[i])\n            ok = 1;\n\
    \        }\n        assert(ok);\n      }\n      L = rearrange(L, I);\n      R\
    \ = rearrange(R, I);\n      FOR(k, len(L) - 1) { assert(L[k] < L[k + 1] && R[k]\
    \ < R[k + 1]); }\n    }\n  }\n}\n\nvoid solve() {\n  int a, b;\n  cin >> a >>\
    \ b;\n  cout << a + b << '\\n';\n}\n\nsigned main() {\n  test(false);\n  test(true);\n\
    \  solve();\n  return 0;\n}\n"
  dependsOn:
  - my_template.hpp
  - other/reduce_intervals.hpp
  - random/base.hpp
  isVerificationFile: true
  path: test/1_mytest/reduce_intervals.test.cpp
  requiredBy: []
  timestamp: '2026-08-30 21:41:42+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: test/1_mytest/reduce_intervals.test.cpp
layout: document
redirect_from:
- /verify/test/1_mytest/reduce_intervals.test.cpp
- /verify/test/1_mytest/reduce_intervals.test.cpp.html
title: test/1_mytest/reduce_intervals.test.cpp
---
