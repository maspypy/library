---
data:
  _extendedDependsOn:
  - icon: ':question:'
    path: ds/index_compression.hpp
    title: ds/index_compression.hpp
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
  bundledCode: "#line 1 \"test/1_mytest/index_compression.test.cpp\"\n#define PROBLEM\
    \ \"https://judge.yosupo.jp/problem/aplusb\"\n\n#line 1 \"my_template.hpp\"\n\
    #if defined(LOCAL)\n#include <my_template_compiled.hpp>\n#else\n\n// https://codeforces.com/blog/entry/96344\n\
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
    \ x, T y) {\n  T q = floor(x, y);\n  return {q, x - q * y};\n}\n\ninline constexpr\
    \ std::array<u64, 20> TEN_TAB = [] {\n  std::array<u64, 20> a{};\n  u64 x = 1;\n\
    \  for (int i = 0; i <= 19; ++i) {\n    a[i] = x, x *= 10;\n  }\n  return a;\n\
    }();\n\ninline constexpr u64 TEN(int n) {\n  assert(0 <= n && n <= 19);\n  return\
    \ TEN_TAB[n];\n}\n\ntemplate <int N>\ninline constexpr u64 TEN_v = [] {\n  static_assert(0\
    \ <= N && N <= 19);\n  return TEN_TAB[N];\n}();\n\ntemplate <typename T, typename\
    \ U>\nT SUM(const U &A) {\n  return std::accumulate(A.begin(), A.end(), T{});\n\
    }\n\n#define MIN(v) *min_element(all(v))\n#define MAX(v) *max_element(all(v))\n\
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
    \ others.end()), ...);\n}\n#endif\n#line 4 \"test/1_mytest/index_compression.test.cpp\"\
    \n\n#line 1 \"ds/index_compression.hpp\"\ntemplate <typename T>\nstruct Index_Compression_DISTINCT_SMALL\
    \ {\n  static_assert(is_same_v<T, int>);\n  int mi, ma;\n  vc<int> dat;\n  vc<int>\
    \ build(vc<int> X) {\n    mi = 0, ma = -1;\n    if (!X.empty()) mi = MIN(X), ma\
    \ = MAX(X);\n    dat.assign(ma - mi + 2, 0);\n    for (auto& x: X) dat[x - mi\
    \ + 1]++;\n    FOR(i, len(dat) - 1) dat[i + 1] += dat[i];\n    for (auto& x: X)\
    \ { x = dat[x - mi]++; }\n    FOR_R(i, 1, len(dat)) dat[i] = dat[i - 1];\n   \
    \ dat[0] = 0;\n    return X;\n  }\n  int operator()(ll x) { return dat[clamp<ll>(x\
    \ - mi, 0, ma - mi + 1)]; }\n};\n\ntemplate <typename T>\nstruct Index_Compression_SAME_SMALL\
    \ {\n  static_assert(is_same_v<T, int>);\n  int mi, ma;\n  vc<int> dat;\n  vc<int>\
    \ build(vc<int> X) {\n    mi = 0, ma = -1;\n    if (!X.empty()) mi = MIN(X), ma\
    \ = MAX(X);\n    dat.assign(ma - mi + 2, 0);\n    for (auto& x: X) dat[x - mi\
    \ + 1] = 1;\n    FOR(i, len(dat) - 1) dat[i + 1] += dat[i];\n    for (auto& x:\
    \ X) { x = dat[x - mi]; }\n    return X;\n  }\n  int operator()(ll x) { return\
    \ dat[clamp<ll>(x - mi, 0, ma - mi + 1)]; }\n};\n\ntemplate <typename T>\nstruct\
    \ Index_Compression_SAME_LARGE {\n  vc<T> dat;\n  vc<int> build(vc<T> X) {\n \
    \   vc<int> I = argsort(X);\n    vc<int> res(len(X));\n    for (auto& i: I) {\n\
    \      if (!dat.empty() && dat.back() == X[i]) {\n        res[i] = len(dat) -\
    \ 1;\n      } else {\n        res[i] = len(dat);\n        dat.eb(X[i]);\n    \
    \  }\n    }\n    dat.shrink_to_fit();\n    return res;\n  }\n  int operator()(T\
    \ x) { return LB(dat, x); }\n};\n\ntemplate <typename T>\nstruct Index_Compression_DISTINCT_LARGE\
    \ {\n  vc<T> dat;\n  vc<int> build(vc<T> X) {\n    vc<int> I = argsort(X);\n \
    \   vc<int> res(len(X));\n    for (auto& i: I) { res[i] = len(dat), dat.eb(X[i]);\
    \ }\n    dat.shrink_to_fit();\n    return res;\n  }\n  int operator()(T x) { return\
    \ LB(dat, x); }\n};\n\ntemplate <typename T, bool SMALL>\nusing Index_Compression_DISTINCT\
    \ = typename std::conditional<SMALL, Index_Compression_DISTINCT_SMALL<T>, Index_Compression_DISTINCT_LARGE<T>>::type;\n\
    template <typename T, bool SMALL>\nusing Index_Compression_SAME = typename std::conditional<SMALL,\
    \ Index_Compression_SAME_SMALL<T>, Index_Compression_SAME_LARGE<T>>::type;\n\n\
    // SAME: [2,3,2] -> [0,1,0]\n// DISTINCT: [2,2,3] -> [0,2,1]\n// build \u3067\u5217\
    \u3092\u5727\u7E2E\u3057\u3066\u304F\u308C\u308B. \u305D\u306E\u3042\u3068\n//\
    \ (x): lower_bound(X,x) \u3092\u304B\u3048\u3059\ntemplate <typename T, bool SAME,\
    \ bool SMALL>\nusing Index_Compression = typename std::conditional<SAME, Index_Compression_SAME<T,\
    \ SMALL>, Index_Compression_DISTINCT<T, SMALL>>::type;\n#line 2 \"random/base.hpp\"\
    \n\nu64 RNG_64() {\n  static u64 x_ = u64(chrono::duration_cast<chrono::nanoseconds>(chrono::high_resolution_clock::now().time_since_epoch()).count())\
    \ * 10150724397891781847ULL;\n  x_ ^= x_ << 7;\n  return x_ ^= x_ >> 9;\n}\n\n\
    u64 RNG(u64 lim) { return RNG_64() % lim; }\n\nll RNG(ll l, ll r) { return l +\
    \ RNG_64() % (r - l); }\n#line 7 \"test/1_mytest/index_compression.test.cpp\"\n\
    \ntemplate <bool SMALL>\nvoid test_distinct() {\n  vc<int> X = {3, 4, 7, 4, 3,\
    \ 6, 6, 7, 3};\n  Index_Compression<int, false, SMALL> IDX;\n  vc<int> Y = IDX.build(X);\n\
    \  assert(Y == vc<int>({0, 3, 7, 4, 1, 5, 6, 8, 2}));\n  assert(IDX(1) == 0 &&\
    \ IDX(2) == 0 && IDX(3) == 0);\n  assert(IDX(4) == 3 && IDX(5) == 5 && IDX(6)\
    \ == 5);\n  assert(IDX(7) == 7 && IDX(8) == 9 && IDX(9) == 9);\n\n  FOR(100) {\n\
    \    FOR(N, 0, 300) {\n      vc<int> X(N);\n      FOR(i, N) X[i] = RNG(-100, 100);\n\
    \      Index_Compression<int, false, SMALL> IDX;\n      vc<int> Y = IDX.build(X);\n\
    \      auto I = argsort(X);\n      FOR(i, N) assert(Y[I[i]] == i);\n      X =\
    \ rearrange(X, I);\n      FOR(x, -100, 100) assert(IDX(x) == LB(X, x));\n    }\n\
    \  }\n}\n\ntemplate <bool SMALL>\nvoid test_same() {\n  vc<int> X = {3, 4, 7,\
    \ 4, 3, 6, 6, 7, 3};\n  Index_Compression<int, true, SMALL> IDX;\n  vc<int> Y\
    \ = IDX.build(X);\n  assert(Y == vc<int>({0, 1, 3, 1, 0, 2, 2, 3, 0}));\n  assert(IDX(1)\
    \ == 0 && IDX(2) == 0 && IDX(3) == 0);\n  assert(IDX(4) == 1 && IDX(5) == 2 &&\
    \ IDX(6) == 2);\n  assert(IDX(7) == 3 && IDX(8) == 4 && IDX(9) == 4);\n\n  FOR(100)\
    \ {\n    FOR(N, 0, 300) {\n      vc<int> X(N);\n      FOR(i, N) X[i] = RNG(-100,\
    \ 100);\n      Index_Compression<int, true, SMALL> IDX;\n      vc<int> Y = IDX.build(X);\n\
    \      vc<int> key = X;\n      UNIQUE(key);\n      FOR(i, N) assert(LB(key, X[i])\
    \ == Y[i]);\n      FOR(x, -100, 100) assert(IDX(x) == LB(key, x));\n    }\n  }\n\
    }\n\nvoid solve() {\n  int a, b;\n  cin >> a >> b;\n  cout << a + b << \"\\n\"\
    ;\n}\n\nsigned main() {\n  test_distinct<false>();\n  test_distinct<true>();\n\
    \  test_same<false>();\n  test_same<true>();\n  solve();\n}\n"
  code: "#define PROBLEM \"https://judge.yosupo.jp/problem/aplusb\"\n\n#include \"\
    my_template.hpp\"\n\n#include \"ds/index_compression.hpp\"\n#include \"random/base.hpp\"\
    \n\ntemplate <bool SMALL>\nvoid test_distinct() {\n  vc<int> X = {3, 4, 7, 4,\
    \ 3, 6, 6, 7, 3};\n  Index_Compression<int, false, SMALL> IDX;\n  vc<int> Y =\
    \ IDX.build(X);\n  assert(Y == vc<int>({0, 3, 7, 4, 1, 5, 6, 8, 2}));\n  assert(IDX(1)\
    \ == 0 && IDX(2) == 0 && IDX(3) == 0);\n  assert(IDX(4) == 3 && IDX(5) == 5 &&\
    \ IDX(6) == 5);\n  assert(IDX(7) == 7 && IDX(8) == 9 && IDX(9) == 9);\n\n  FOR(100)\
    \ {\n    FOR(N, 0, 300) {\n      vc<int> X(N);\n      FOR(i, N) X[i] = RNG(-100,\
    \ 100);\n      Index_Compression<int, false, SMALL> IDX;\n      vc<int> Y = IDX.build(X);\n\
    \      auto I = argsort(X);\n      FOR(i, N) assert(Y[I[i]] == i);\n      X =\
    \ rearrange(X, I);\n      FOR(x, -100, 100) assert(IDX(x) == LB(X, x));\n    }\n\
    \  }\n}\n\ntemplate <bool SMALL>\nvoid test_same() {\n  vc<int> X = {3, 4, 7,\
    \ 4, 3, 6, 6, 7, 3};\n  Index_Compression<int, true, SMALL> IDX;\n  vc<int> Y\
    \ = IDX.build(X);\n  assert(Y == vc<int>({0, 1, 3, 1, 0, 2, 2, 3, 0}));\n  assert(IDX(1)\
    \ == 0 && IDX(2) == 0 && IDX(3) == 0);\n  assert(IDX(4) == 1 && IDX(5) == 2 &&\
    \ IDX(6) == 2);\n  assert(IDX(7) == 3 && IDX(8) == 4 && IDX(9) == 4);\n\n  FOR(100)\
    \ {\n    FOR(N, 0, 300) {\n      vc<int> X(N);\n      FOR(i, N) X[i] = RNG(-100,\
    \ 100);\n      Index_Compression<int, true, SMALL> IDX;\n      vc<int> Y = IDX.build(X);\n\
    \      vc<int> key = X;\n      UNIQUE(key);\n      FOR(i, N) assert(LB(key, X[i])\
    \ == Y[i]);\n      FOR(x, -100, 100) assert(IDX(x) == LB(key, x));\n    }\n  }\n\
    }\n\nvoid solve() {\n  int a, b;\n  cin >> a >> b;\n  cout << a + b << \"\\n\"\
    ;\n}\n\nsigned main() {\n  test_distinct<false>();\n  test_distinct<true>();\n\
    \  test_same<false>();\n  test_same<true>();\n  solve();\n}"
  dependsOn:
  - my_template.hpp
  - ds/index_compression.hpp
  - random/base.hpp
  isVerificationFile: true
  path: test/1_mytest/index_compression.test.cpp
  requiredBy: []
  timestamp: '2025-09-01 21:30:48+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: test/1_mytest/index_compression.test.cpp
layout: document
redirect_from:
- /verify/test/1_mytest/index_compression.test.cpp
- /verify/test/1_mytest/index_compression.test.cpp.html
title: test/1_mytest/index_compression.test.cpp
---
