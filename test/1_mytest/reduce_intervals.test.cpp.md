---
data:
  _extendedDependsOn:
  - icon: ':question:'
    path: my_template.hpp
    title: my_template.hpp
  - icon: ':x:'
    path: other/reduce_intervals.hpp
    title: other/reduce_intervals.hpp
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
  bundledCode: "#line 1 \"test/1_mytest/reduce_intervals.test.cpp\"\n#define PROBLEM\
    \ \"https://judge.yosupo.jp/problem/aplusb\"\n#line 1 \"my_template.hpp\"\n#if\
    \ defined(LOCAL)\n#include <my_template_compiled.hpp>\n#else\n\n// https://codeforces.com/blog/entry/96344\n\
    // https://codeforces.com/blog/entry/126772?#comment-1154880\n#if defined(__GNUC__)\n\
    #include <bits/allocator.h>\n#pragma GCC optimize(\"Ofast,unroll-loops\")\n#pragma\
    \ GCC target(\"avx2,popcnt\")\n#endif\n#include <bits/stdc++.h>\n\nusing namespace\
    \ std;\n\nusing ll = long long;\nusing u8 = uint8_t;\nusing u16 = uint16_t;\n\
    using u32 = uint32_t;\nusing u64 = uint64_t;\nusing i128 = __int128;\nusing u128\
    \ = unsigned __int128;\nusing f128 = __float128;\n\ntemplate <class T>\nconstexpr\
    \ T infty = 0;\ntemplate <>\nconstexpr int infty<int> = 1'010'000'000;\ntemplate\
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
    \ (a) - 1; i >= ll(0); --i)\n#define FOR2_R(i, a) for (ll i = (a) - 1; i >= ll(0);\
    \ --i)\n#define FOR3_R(i, a, b) for (ll i = (b) - 1; i >= ll(a); --i)\n#define\
    \ overload4(a, b, c, d, e, ...) e\n#define overload3(a, b, c, d, ...) d\n#define\
    \ FOR(...) overload4(__VA_ARGS__, FOR4, FOR3, FOR2, FOR1)(__VA_ARGS__)\n#define\
    \ FOR_R(...) overload3(__VA_ARGS__, FOR3_R, FOR2_R, FOR1_R)(__VA_ARGS__)\n\n#define\
    \ all(x) x.begin(), x.end()\n#define len(x) ll(x.size())\n#define elif else if\n\
    \n#define eb emplace_back\n#define mp make_pair\n#define mt make_tuple\n#define\
    \ fi first\n#define se second\n\n#define stoi stoll\n\nint popcnt(int x) { return\
    \ __builtin_popcount(x); }\nint popcnt(u32 x) { return __builtin_popcount(x);\
    \ }\nint popcnt(ll x) { return __builtin_popcountll(x); }\nint popcnt(u64 x) {\
    \ return __builtin_popcountll(x); }\nint popcnt_sgn(int x) { return (__builtin_parity(unsigned(x))\
    \ & 1 ? -1 : 1); }\nint popcnt_sgn(u32 x) { return (__builtin_parity(x) & 1 ?\
    \ -1 : 1); }\nint popcnt_sgn(ll x) { return (__builtin_parityll(x) & 1 ? -1 :\
    \ 1); }\nint popcnt_sgn(u64 x) { return (__builtin_parityll(x) & 1 ? -1 : 1);\
    \ }\n// (0, 1, 2, 3, 4) -> (-1, 0, 1, 1, 2)\nint topbit(int x) { return (x ==\
    \ 0 ? -1 : 31 - __builtin_clz(x)); }\nint topbit(u32 x) { return (x == 0 ? -1\
    \ : 31 - __builtin_clz(x)); }\nint topbit(ll x) { return (x == 0 ? -1 : 63 - __builtin_clzll(x));\
    \ }\nint topbit(u64 x) { return (x == 0 ? -1 : 63 - __builtin_clzll(x)); }\n//\
    \ (0, 1, 2, 3, 4) -> (-1, 0, 1, 0, 2)\nint lowbit(int x) { return (x == 0 ? -1\
    \ : __builtin_ctz(x)); }\nint lowbit(u32 x) { return (x == 0 ? -1 : __builtin_ctz(x));\
    \ }\nint lowbit(ll x) { return (x == 0 ? -1 : __builtin_ctzll(x)); }\nint lowbit(u64\
    \ x) { return (x == 0 ? -1 : __builtin_ctzll(x)); }\n\ntemplate <typename T>\n\
    T kth_bit(int k) {\n  return T(1) << k;\n}\ntemplate <typename T>\nbool has_kth_bit(T\
    \ x, int k) {\n  return x >> k & 1;\n}\n\ntemplate <typename UINT>\nstruct all_bit\
    \ {\n  struct iter {\n    UINT s;\n    iter(UINT s) : s(s) {}\n    int operator*()\
    \ const { return lowbit(s); }\n    iter &operator++() {\n      s &= s - 1;\n \
    \     return *this;\n    }\n    bool operator!=(const iter) const { return s !=\
    \ 0; }\n  };\n  UINT s;\n  all_bit(UINT s) : s(s) {}\n  iter begin() const { return\
    \ iter(s); }\n  iter end() const { return iter(0); }\n};\n\ntemplate <typename\
    \ UINT>\nstruct all_subset {\n  static_assert(is_unsigned<UINT>::value);\n  struct\
    \ iter {\n    UINT s, t;\n    bool ed;\n    iter(UINT s) : s(s), t(s), ed(0) {}\n\
    \    UINT operator*() const { return s ^ t; }\n    iter &operator++() {\n    \
    \  (t == 0 ? ed = 1 : t = (t - 1) & s);\n      return *this;\n    }\n    bool\
    \ operator!=(const iter) const { return !ed; }\n  };\n  UINT s;\n  all_subset(UINT\
    \ s) : s(s) {}\n  iter begin() const { return iter(s); }\n  iter end() const {\
    \ return iter(0); }\n};\n\ntemplate <typename T>\nT floor(T a, T b) {\n  return\
    \ a / b - (a % b && (a ^ b) < 0);\n}\ntemplate <typename T>\nT ceil(T x, T y)\
    \ {\n  return floor(x + y - 1, y);\n}\ntemplate <typename T>\nT bmod(T x, T y)\
    \ {\n  return x - y * floor(x, y);\n}\ntemplate <typename T>\npair<T, T> divmod(T\
    \ x, T y) {\n  T q = floor(x, y);\n  return {q, x - q * y};\n}\n\ntemplate <typename\
    \ T, typename U>\nT SUM(const U &A) {\n  return std::accumulate(A.begin(), A.end(),\
    \ T{});\n}\n\n#define MIN(v) *min_element(all(v))\n#define MAX(v) *max_element(all(v))\n\
    #define LB(c, x) distance((c).begin(), lower_bound(all(c), (x)))\n#define UB(c,\
    \ x) distance((c).begin(), upper_bound(all(c), (x)))\n#define UNIQUE(x) \\\n \
    \ sort(all(x)), x.erase(unique(all(x)), x.end()), x.shrink_to_fit()\n\ntemplate\
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
    template <class T, class S>\ninline bool chmax(T &a, const S &b) {\n  return (a\
    \ < b ? a = b, 1 : 0);\n}\ntemplate <class T, class S>\ninline bool chmin(T &a,\
    \ const S &b) {\n  return (a > b ? a = b, 1 : 0);\n}\n\n// ? \u306F -1\nvc<int>\
    \ s_to_vi(const string &S, char first_char) {\n  vc<int> A(S.size());\n  FOR(i,\
    \ S.size()) { A[i] = (S[i] != '?' ? S[i] - first_char : -1); }\n  return A;\n\
    }\n\ntemplate <typename T, typename U>\nvc<T> cumsum(const vc<U> &A, int off =\
    \ 1) {\n  int N = A.size();\n  vc<T> B(N + 1);\n  FOR(i, N) { B[i + 1] = B[i]\
    \ + A[i]; }\n  if (off == 0) B.erase(B.begin());\n  return B;\n}\n\n// stable\
    \ sort\ntemplate <typename T>\nvc<int> argsort(const vc<T> &A) {\n  vc<int> ids(len(A));\n\
    \  iota(all(ids), 0);\n  sort(all(ids),\n       [&](int i, int j) { return (A[i]\
    \ == A[j] ? i < j : A[i] < A[j]); });\n  return ids;\n}\n\n// A[I[0]], A[I[1]],\
    \ ...\ntemplate <typename T>\nvc<T> rearrange(const vc<T> &A, const vc<int> &I)\
    \ {\n  vc<T> B(len(I));\n  FOR(i, len(I)) B[i] = A[I[i]];\n  return B;\n}\n\n\
    template <typename T, typename... Vectors>\nvoid concat(vc<T> &first, const Vectors\
    \ &...others) {\n  vc<T> &res = first;\n  (res.insert(res.end(), others.begin(),\
    \ others.end()), ...);\n}\n#endif\n#line 3 \"test/1_mytest/reduce_intervals.test.cpp\"\
    \n\n#line 1 \"other/reduce_intervals.hpp\"\n\n// rm_included = true : I < J \u3068\
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
    \      }\n      ANS.eb(j);\n    }\n  }\n  return ANS;\n}\n#line 2 \"random/base.hpp\"\
    \n\nu64 RNG_64() {\n  static u64 x_ = u64(chrono::duration_cast<chrono::nanoseconds>(chrono::high_resolution_clock::now().time_since_epoch()).count())\
    \ * 10150724397891781847ULL;\n  x_ ^= x_ << 7;\n  return x_ ^= x_ >> 9;\n}\n\n\
    u64 RNG(u64 lim) { return RNG_64() % lim; }\n\nll RNG(ll l, ll r) { return l +\
    \ RNG_64() % (r - l); }\n#line 6 \"test/1_mytest/reduce_intervals.test.cpp\"\n\
    \nvoid test(bool rm_included) {\n  FOR(mx, 100) {\n    FOR(NN, 100) {\n      set<pair<int,\
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
  timestamp: '2025-09-01 19:47:27+09:00'
  verificationStatus: TEST_WRONG_ANSWER
  verifiedWith: []
documentation_of: test/1_mytest/reduce_intervals.test.cpp
layout: document
redirect_from:
- /verify/test/1_mytest/reduce_intervals.test.cpp
- /verify/test/1_mytest/reduce_intervals.test.cpp.html
title: test/1_mytest/reduce_intervals.test.cpp
---
