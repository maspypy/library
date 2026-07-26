---
data:
  _extendedDependsOn:
  - icon: ':x:'
    path: convex/path_independent_set.hpp
    title: convex/path_independent_set.hpp
  - icon: ':question:'
    path: my_template.hpp
    title: my_template.hpp
  - icon: ':question:'
    path: random/base.hpp
    title: random/base.hpp
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
  bundledCode: "#line 1 \"test/1_mytest/non_adj.test.cpp\"\n#define PROBLEM \"https://judge.yosupo.jp/problem/aplusb\"\
    \n\n#line 1 \"my_template.hpp\"\n#if defined(LOCAL)\n#include <my_template_compiled.hpp>\n\
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
    #line 4 \"test/1_mytest/non_adj.test.cpp\"\n\n#line 1 \"convex/path_independent_set.hpp\"\
    \n\n// https://atcoder.jp/contests/joisc2018/tasks/joisc2018_j\n// https://atcoder.jp/contests/abc464/tasks/abc464_g\n\
    // \u96A3\u63A5\u3059\u308B\u3082\u306E\u306F\u9078\u3079\u306A\u3044, k \u500B\
    \u9078\u3093\u3060\u3068\u304D\u306E\u6700\u9069\u89E3\u3092\u5168 k \u3067\u5217\
    \u6319\ntemplate <typename T, bool MINIMIZE>\nstruct Path_Independent_Set {\n\
    \  int N;\n  vc<T> ANS;\n  vc<pair<int, int>> history;\n\n  Path_Independent_Set(vc<T>&\
    \ A) { calc(A); }\n\n  void calc(vc<T> A) {\n    if (MINIMIZE) {\n      for (auto&\
    \ x : A) x = -x;\n    }\n    N = len(A);\n    vc<bool> rest(N + 2, 1);\n    rest[0]\
    \ = rest[N + 1] = 0;\n    vc<pair<int, int>> range(N + 2);\n    vc<int> left(N\
    \ + 2), right(N + 2);\n    vc<T> val(N + 2);\n    pq_max<pair<T, int>> que;\n\
    \    FOR(i, N + 2) { left[i] = i - 1, right[i] = i + 1; }\n    FOR(i, N) {\n \
    \     val[i + 1] = A[i], range[i + 1] = {i, i + 1};\n      que.emplace(val[i +\
    \ 1], i + 1);\n    }\n\n    ANS = {0};\n    while (len(que)) {\n      auto [add,\
    \ i] = POP(que);\n      if (!rest[i]) continue;\n      ANS.eb(ANS.back() + add);\n\
    \      int L = left[i], R = right[i];\n      history.eb(range[i]);\n      if (1\
    \ <= L) {\n        right[left[L]] = i, left[i] = left[L];\n      }\n      if (R\
    \ <= N) {\n        left[right[R]] = i, right[i] = right[R];\n      }\n      if\
    \ (rest[L] && rest[R]) {\n        val[i] = val[L] + val[R] - val[i];\n       \
    \ que.emplace(val[i], i);\n        range[i] = {range[L].fi, range[R].se};\n  \
    \    } else {\n        rest[i] = 0;\n      }\n      rest[L] = rest[R] = 0;\n \
    \   }\n\n    if (MINIMIZE) {\n      for (auto& x : ANS) x = -x;\n    }\n  }\n\n\
    \  vc<T> get_ANS() { return ANS; }\n  vc<int> restore(int n) {\n    vc<int> F(N\
    \ + 1);\n    FOR(i, n) {\n      auto [a, b] = history[i];\n      F[a]++, F[b]--;\n\
    \    }\n    F = cumsum<int>(F, 0);\n    vc<int> I;\n    FOR(i, N) if (F[i] & 1)\
    \ I.eb(i);\n    return I;\n  }\n};\n#line 2 \"random/base.hpp\"\n\nu64 RNG_64()\
    \ {\n  static u64 x_ = u64(chrono::duration_cast<chrono::nanoseconds>(chrono::high_resolution_clock::now().time_since_epoch()).count())\
    \ * 10150724397891781847ULL;\n  x_ ^= x_ << 7;\n  return x_ ^= x_ >> 9;\n}\n\n\
    u64 RNG(u64 lim) { return RNG_64() % lim; }\n\nll RNG(ll l, ll r) { return l +\
    \ RNG_64() % (r - l); }\n#line 7 \"test/1_mytest/non_adj.test.cpp\"\n\nvoid test()\
    \ {\n  FOR(100) {\n    FOR(N, 10) {\n      vi A(N);\n      FOR(i, N) A[i] = RNG(0,\
    \ 1000000000);\n\n      Path_Independent_Set<ll, true> MI(A);\n      Path_Independent_Set<ll,\
    \ true> MA(A);\n      FOR(cnt, ceil<int>(N, 2) + 1) {\n        ll mi = infty<ll>,\
    \ ma = -infty<ll>;\n        FOR(s, 1 << N) {\n          if (s & (s >> 1)) continue;\n\
    \          if (popcnt(s) != cnt) continue;\n          ll sm = 0;\n          FOR(i,\
    \ N) if (s >> i & 1) sm += A[i];\n          chmin(mi, sm), chmax(ma, sm);\n  \
    \      }\n        assert(MI.ANS[cnt] == mi);\n        assert(MA.ANS[cnt] == ma);\n\
    \n        {\n          vc<int> I = MI.restore(cnt);\n          FOR(k, len(I) -\
    \ 1) assert(I[k + 1] >= I[k] + 2);\n          ll sm = 0;\n          for (auto&\
    \ i : I) sm += A[i];\n          assert(mi == sm);\n        }\n        {\n    \
    \      vc<int> I = MA.restore(cnt);\n          FOR(k, len(I) - 1) assert(I[k +\
    \ 1] >= I[k] + 2);\n          ll sm = 0;\n          for (auto& i : I) sm += A[i];\n\
    \          assert(ma == sm);\n        }\n      }\n    }\n  }\n}\n\nvoid solve()\
    \ {\n  int a, b;\n  cin >> a >> b;\n  cout << a + b << \"\\n\";\n}\n\nsigned main()\
    \ {\n  test();\n  solve();\n  return 0;\n}\n"
  code: "#define PROBLEM \"https://judge.yosupo.jp/problem/aplusb\"\n\n#include \"\
    my_template.hpp\"\n\n#include \"convex/path_independent_set.hpp\"\n#include \"\
    random/base.hpp\"\n\nvoid test() {\n  FOR(100) {\n    FOR(N, 10) {\n      vi A(N);\n\
    \      FOR(i, N) A[i] = RNG(0, 1000000000);\n\n      Path_Independent_Set<ll,\
    \ true> MI(A);\n      Path_Independent_Set<ll, true> MA(A);\n      FOR(cnt, ceil<int>(N,\
    \ 2) + 1) {\n        ll mi = infty<ll>, ma = -infty<ll>;\n        FOR(s, 1 <<\
    \ N) {\n          if (s & (s >> 1)) continue;\n          if (popcnt(s) != cnt)\
    \ continue;\n          ll sm = 0;\n          FOR(i, N) if (s >> i & 1) sm += A[i];\n\
    \          chmin(mi, sm), chmax(ma, sm);\n        }\n        assert(MI.ANS[cnt]\
    \ == mi);\n        assert(MA.ANS[cnt] == ma);\n\n        {\n          vc<int>\
    \ I = MI.restore(cnt);\n          FOR(k, len(I) - 1) assert(I[k + 1] >= I[k] +\
    \ 2);\n          ll sm = 0;\n          for (auto& i : I) sm += A[i];\n       \
    \   assert(mi == sm);\n        }\n        {\n          vc<int> I = MA.restore(cnt);\n\
    \          FOR(k, len(I) - 1) assert(I[k + 1] >= I[k] + 2);\n          ll sm =\
    \ 0;\n          for (auto& i : I) sm += A[i];\n          assert(ma == sm);\n \
    \       }\n      }\n    }\n  }\n}\n\nvoid solve() {\n  int a, b;\n  cin >> a >>\
    \ b;\n  cout << a + b << \"\\n\";\n}\n\nsigned main() {\n  test();\n  solve();\n\
    \  return 0;\n}\n"
  dependsOn:
  - my_template.hpp
  - convex/path_independent_set.hpp
  - random/base.hpp
  isVerificationFile: true
  path: test/1_mytest/non_adj.test.cpp
  requiredBy: []
  timestamp: '2026-07-26 19:43:20+09:00'
  verificationStatus: TEST_WRONG_ANSWER
  verifiedWith: []
documentation_of: test/1_mytest/non_adj.test.cpp
layout: document
redirect_from:
- /verify/test/1_mytest/non_adj.test.cpp
- /verify/test/1_mytest/non_adj.test.cpp.html
title: test/1_mytest/non_adj.test.cpp
---
