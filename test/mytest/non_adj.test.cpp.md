---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: convex/non_adjecent_selection.hpp
    title: convex/non_adjecent_selection.hpp
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
  bundledCode: "#line 1 \"test/mytest/non_adj.test.cpp\"\n#define PROBLEM \"https://judge.yosupo.jp/problem/aplusb\"\
    \n\n#line 1 \"my_template.hpp\"\n#if defined(LOCAL)\n#include <my_template_compiled.hpp>\n\
    #else\n#pragma GCC optimize(\"Ofast\")\n#pragma GCC optimize(\"unroll-loops\"\
    )\n\n#include <bits/stdc++.h>\n\nusing namespace std;\n\nusing ll = long long;\n\
    using u32 = unsigned int;\nusing u64 = unsigned long long;\nusing i128 = __int128;\n\
    using u128 = unsigned __int128;\nusing f128 = __float128;\n\ntemplate <class T>\n\
    constexpr T infty = 0;\ntemplate <>\nconstexpr int infty<int> = 1'000'000'000;\n\
    template <>\nconstexpr ll infty<ll> = ll(infty<int>) * infty<int> * 2;\ntemplate\
    \ <>\nconstexpr u32 infty<u32> = infty<int>;\ntemplate <>\nconstexpr u64 infty<u64>\
    \ = infty<ll>;\ntemplate <>\nconstexpr i128 infty<i128> = i128(infty<ll>) * infty<ll>;\n\
    template <>\nconstexpr double infty<double> = infty<ll>;\ntemplate <>\nconstexpr\
    \ long double infty<long double> = infty<ll>;\n\nusing pi = pair<ll, ll>;\nusing\
    \ vi = vector<ll>;\ntemplate <class T>\nusing vc = vector<T>;\ntemplate <class\
    \ T>\nusing vvc = vector<vc<T>>;\ntemplate <class T>\nusing vvvc = vector<vvc<T>>;\n\
    template <class T>\nusing vvvvc = vector<vvvc<T>>;\ntemplate <class T>\nusing\
    \ vvvvvc = vector<vvvvc<T>>;\ntemplate <class T>\nusing pq = priority_queue<T>;\n\
    template <class T>\nusing pqg = priority_queue<T, vector<T>, greater<T>>;\n\n\
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
    \  return B;\n}\n#endif\n#line 4 \"test/mytest/non_adj.test.cpp\"\n\n#line 1 \"\
    convex/non_adjecent_selection.hpp\"\n\n// https://atcoder.jp/contests/joisc2018/tasks/joisc2018_j\n\
    template <typename T, bool MINIMIZE>\nstruct Non_Adjacent_Selection {\n  int N;\n\
    \  vc<T> ANS;\n  vc<pair<int, int>> history;\n\n  Non_Adjacent_Selection(vc<T>&\
    \ A) { calc(A); }\n\n  void calc(vc<T> A) {\n    if (MINIMIZE) {\n      for (auto&\
    \ x: A) x = -x;\n    }\n    N = len(A);\n    vc<bool> rest(N + 2, 1);\n    rest[0]\
    \ = rest[N + 1] = 0;\n    vc<pair<int, int>> range(N + 2);\n    vc<int> left(N\
    \ + 2), right(N + 2);\n    vc<T> val(N + 2);\n    pq<pair<T, int>> que;\n    FOR(i,\
    \ N + 2) { left[i] = i - 1, right[i] = i + 1; }\n    FOR(i, N) {\n      val[i\
    \ + 1] = A[i], range[i + 1] = {i, i + 1};\n      que.emplace(val[i + 1], i + 1);\n\
    \    }\n\n    ANS = {0};\n    while (len(que)) {\n      auto [add, i] = POP(que);\n\
    \      if (!rest[i]) continue;\n      ANS.eb(ANS.back() + add);\n      int L =\
    \ left[i], R = right[i];\n      history.eb(range[i]);\n      if (1 <= L) { right[left[L]]\
    \ = i, left[i] = left[L]; }\n      if (R <= N) { left[right[R]] = i, right[i]\
    \ = right[R]; }\n      if (rest[L] && rest[R]) {\n        val[i] = val[L] + val[R]\
    \ - val[i];\n        que.emplace(val[i], i);\n        range[i] = {range[L].fi,\
    \ range[R].se};\n      } else {\n        rest[i] = 0;\n      }\n      rest[L]\
    \ = rest[R] = 0;\n    }\n\n    if (MINIMIZE) {\n      for (auto& x: ANS) x = -x;\n\
    \    }\n  }\n\n  vc<int> restore(int n) {\n    vc<int> F(N + 1);\n    FOR(i, n)\
    \ {\n      auto [a, b] = history[i];\n      F[a]++, F[b]--;\n    }\n    F = cumsum<int>(F,\
    \ 0);\n    vc<int> I;\n    FOR(i, N) if (F[i] & 1) I.eb(i);\n    return I;\n \
    \ }\n};\n#line 2 \"random/base.hpp\"\n\nu64 RNG_64() {\n  static uint64_t x_\n\
    \      = uint64_t(chrono::duration_cast<chrono::nanoseconds>(\n              \
    \       chrono::high_resolution_clock::now().time_since_epoch())\n           \
    \          .count())\n        * 10150724397891781847ULL;\n  x_ ^= x_ << 7;\n \
    \ return x_ ^= x_ >> 9;\n}\n\nu64 RNG(u64 lim) { return RNG_64() % lim; }\n\n\
    ll RNG(ll l, ll r) { return l + RNG_64() % (r - l); }\n#line 7 \"test/mytest/non_adj.test.cpp\"\
    \n\nvoid test() {\n  FOR(100) {\n    FOR(N, 10) {\n      vi A(N);\n      FOR(i,\
    \ N) A[i] = RNG(0, 1000000000);\n\n      Non_Adjacent_Selection<ll, true> MI(A);\n\
    \      Non_Adjacent_Selection<ll, false> MA(A);\n      FOR(cnt, ceil<int>(N, 2)\
    \ + 1) {\n        ll mi = infty<ll>, ma = -infty<ll>;\n        FOR(s, 1 << N)\
    \ {\n          if (s & (s >> 1)) continue;\n          if (popcnt(s) != cnt) continue;\n\
    \          ll sm = 0;\n          FOR(i, N) if (s >> i & 1) sm += A[i];\n     \
    \     chmin(mi, sm), chmax(ma, sm);\n        }\n        assert(MI.ANS[cnt] ==\
    \ mi);\n        assert(MA.ANS[cnt] == ma);\n\n        {\n          vc<int> I =\
    \ MI.restore(cnt);\n          FOR(k, len(I) - 1) assert(I[k + 1] >= I[k] + 2);\n\
    \          ll sm = 0;\n          for (auto& i: I) sm += A[i];\n          assert(mi\
    \ == sm);\n        }\n        {\n          vc<int> I = MA.restore(cnt);\n    \
    \      FOR(k, len(I) - 1) assert(I[k + 1] >= I[k] + 2);\n          ll sm = 0;\n\
    \          for (auto& i: I) sm += A[i];\n          assert(ma == sm);\n       \
    \ }\n      }\n    }\n  }\n}\n\nvoid solve() {\n  int a, b;\n  cin >> a >> b;\n\
    \  cout << a + b << \"\\n\";\n}\n\nsigned main() {\n  test();\n  solve();\n  return\
    \ 0;\n}\n"
  code: "#define PROBLEM \"https://judge.yosupo.jp/problem/aplusb\"\n\n#include \"\
    my_template.hpp\"\n\n#include \"convex/non_adjecent_selection.hpp\"\n#include\
    \ \"random/base.hpp\"\n\nvoid test() {\n  FOR(100) {\n    FOR(N, 10) {\n     \
    \ vi A(N);\n      FOR(i, N) A[i] = RNG(0, 1000000000);\n\n      Non_Adjacent_Selection<ll,\
    \ true> MI(A);\n      Non_Adjacent_Selection<ll, false> MA(A);\n      FOR(cnt,\
    \ ceil<int>(N, 2) + 1) {\n        ll mi = infty<ll>, ma = -infty<ll>;\n      \
    \  FOR(s, 1 << N) {\n          if (s & (s >> 1)) continue;\n          if (popcnt(s)\
    \ != cnt) continue;\n          ll sm = 0;\n          FOR(i, N) if (s >> i & 1)\
    \ sm += A[i];\n          chmin(mi, sm), chmax(ma, sm);\n        }\n        assert(MI.ANS[cnt]\
    \ == mi);\n        assert(MA.ANS[cnt] == ma);\n\n        {\n          vc<int>\
    \ I = MI.restore(cnt);\n          FOR(k, len(I) - 1) assert(I[k + 1] >= I[k] +\
    \ 2);\n          ll sm = 0;\n          for (auto& i: I) sm += A[i];\n        \
    \  assert(mi == sm);\n        }\n        {\n          vc<int> I = MA.restore(cnt);\n\
    \          FOR(k, len(I) - 1) assert(I[k + 1] >= I[k] + 2);\n          ll sm =\
    \ 0;\n          for (auto& i: I) sm += A[i];\n          assert(ma == sm);\n  \
    \      }\n      }\n    }\n  }\n}\n\nvoid solve() {\n  int a, b;\n  cin >> a >>\
    \ b;\n  cout << a + b << \"\\n\";\n}\n\nsigned main() {\n  test();\n  solve();\n\
    \  return 0;\n}"
  dependsOn:
  - my_template.hpp
  - convex/non_adjecent_selection.hpp
  - random/base.hpp
  isVerificationFile: true
  path: test/mytest/non_adj.test.cpp
  requiredBy: []
  timestamp: '2023-11-09 01:44:55+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: test/mytest/non_adj.test.cpp
layout: document
redirect_from:
- /verify/test/mytest/non_adj.test.cpp
- /verify/test/mytest/non_adj.test.cpp.html
title: test/mytest/non_adj.test.cpp
---