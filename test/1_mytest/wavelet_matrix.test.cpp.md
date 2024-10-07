---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: alg/monoid/add.hpp
    title: alg/monoid/add.hpp
  - icon: ':heavy_check_mark:'
    path: alg/monoid/min.hpp
    title: alg/monoid/min.hpp
  - icon: ':heavy_check_mark:'
    path: ds/bit_vector.hpp
    title: ds/bit_vector.hpp
  - icon: ':heavy_check_mark:'
    path: ds/index_compression.hpp
    title: ds/index_compression.hpp
  - icon: ':heavy_check_mark:'
    path: ds/segtree/segtree.hpp
    title: ds/segtree/segtree.hpp
  - icon: ':heavy_check_mark:'
    path: ds/static_range_product_group.hpp
    title: ds/static_range_product_group.hpp
  - icon: ':heavy_check_mark:'
    path: ds/wavelet_matrix/wavelet_matrix.hpp
    title: ds/wavelet_matrix/wavelet_matrix.hpp
  - icon: ':heavy_check_mark:'
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
  bundledCode: "#line 1 \"test/1_mytest/wavelet_matrix.test.cpp\"\n#define PROBLEM\
    \ \"https://judge.yosupo.jp/problem/aplusb\"\n\n#line 1 \"my_template.hpp\"\n\
    #if defined(LOCAL)\n#include <my_template_compiled.hpp>\n#else\n\n// https://codeforces.com/blog/entry/96344\n\
    #pragma GCC optimize(\"Ofast,unroll-loops\")\n// \u3044\u307E\u306E CF \u3060\u3068\
    \u3053\u308C\u5165\u308C\u308B\u3068\u52D5\u304B\u306A\u3044\uFF1F\n// #pragma\
    \ GCC target(\"avx2,popcnt\")\n\n#include <bits/stdc++.h>\n\nusing namespace std;\n\
    \nusing ll = long long;\nusing u8 = uint8_t;\nusing u16 = uint16_t;\nusing u32\
    \ = uint32_t;\nusing u64 = uint64_t;\nusing i128 = __int128;\nusing u128 = unsigned\
    \ __int128;\nusing f128 = __float128;\n\ntemplate <class T>\nconstexpr T infty\
    \ = 0;\ntemplate <>\nconstexpr int infty<int> = 1'010'000'000;\ntemplate <>\n\
    constexpr ll infty<ll> = 2'020'000'000'000'000'000;\ntemplate <>\nconstexpr u32\
    \ infty<u32> = infty<int>;\ntemplate <>\nconstexpr u64 infty<u64> = infty<ll>;\n\
    template <>\nconstexpr i128 infty<i128> = i128(infty<ll>) * 2'000'000'000'000'000'000;\n\
    template <>\nconstexpr double infty<double> = infty<ll>;\ntemplate <>\nconstexpr\
    \ long double infty<long double> = infty<ll>;\n\nusing pi = pair<ll, ll>;\nusing\
    \ vi = vector<ll>;\ntemplate <class T>\nusing vc = vector<T>;\ntemplate <class\
    \ T>\nusing vvc = vector<vc<T>>;\ntemplate <class T>\nusing vvvc = vector<vvc<T>>;\n\
    template <class T>\nusing vvvvc = vector<vvvc<T>>;\ntemplate <class T>\nusing\
    \ vvvvvc = vector<vvvvc<T>>;\ntemplate <class T>\nusing pq = priority_queue<T>;\n\
    template <class T>\nusing pqg = priority_queue<T, vector<T>, greater<T>>;\n\n\
    #define vv(type, name, h, ...) vector<vector<type>> name(h, vector<type>(__VA_ARGS__))\n\
    #define vvv(type, name, h, w, ...) vector<vector<vector<type>>> name(h, vector<vector<type>>(w,\
    \ vector<type>(__VA_ARGS__)))\n#define vvvv(type, name, a, b, c, ...) \\\n  vector<vector<vector<vector<type>>>>\
    \ name(a, vector<vector<vector<type>>>(b, vector<vector<type>>(c, vector<type>(__VA_ARGS__))))\n\
    \n// https://trap.jp/post/1224/\n#define FOR1(a) for (ll _ = 0; _ < ll(a); ++_)\n\
    #define FOR2(i, a) for (ll i = 0; i < ll(a); ++i)\n#define FOR3(i, a, b) for (ll\
    \ i = a; i < ll(b); ++i)\n#define FOR4(i, a, b, c) for (ll i = a; i < ll(b); i\
    \ += (c))\n#define FOR1_R(a) for (ll i = (a)-1; i >= ll(0); --i)\n#define FOR2_R(i,\
    \ a) for (ll i = (a)-1; i >= ll(0); --i)\n#define FOR3_R(i, a, b) for (ll i =\
    \ (b)-1; i >= ll(a); --i)\n#define overload4(a, b, c, d, e, ...) e\n#define overload3(a,\
    \ b, c, d, ...) d\n#define FOR(...) overload4(__VA_ARGS__, FOR4, FOR3, FOR2, FOR1)(__VA_ARGS__)\n\
    #define FOR_R(...) overload3(__VA_ARGS__, FOR3_R, FOR2_R, FOR1_R)(__VA_ARGS__)\n\
    \n#define FOR_subset(t, s) for (ll t = (s); t >= 0; t = (t == 0 ? -1 : (t - 1)\
    \ & (s)))\n#define all(x) x.begin(), x.end()\n#define len(x) ll(x.size())\n#define\
    \ elif else if\n\n#define eb emplace_back\n#define mp make_pair\n#define mt make_tuple\n\
    #define fi first\n#define se second\n\n#define stoi stoll\n\nint popcnt(int x)\
    \ { return __builtin_popcount(x); }\nint popcnt(u32 x) { return __builtin_popcount(x);\
    \ }\nint popcnt(ll x) { return __builtin_popcountll(x); }\nint popcnt(u64 x) {\
    \ return __builtin_popcountll(x); }\nint popcnt_mod_2(int x) { return __builtin_parity(x);\
    \ }\nint popcnt_mod_2(u32 x) { return __builtin_parity(x); }\nint popcnt_mod_2(ll\
    \ x) { return __builtin_parityll(x); }\nint popcnt_mod_2(u64 x) { return __builtin_parityll(x);\
    \ }\n// (0, 1, 2, 3, 4) -> (-1, 0, 1, 1, 2)\nint topbit(int x) { return (x ==\
    \ 0 ? -1 : 31 - __builtin_clz(x)); }\nint topbit(u32 x) { return (x == 0 ? -1\
    \ : 31 - __builtin_clz(x)); }\nint topbit(ll x) { return (x == 0 ? -1 : 63 - __builtin_clzll(x));\
    \ }\nint topbit(u64 x) { return (x == 0 ? -1 : 63 - __builtin_clzll(x)); }\n//\
    \ (0, 1, 2, 3, 4) -> (-1, 0, 1, 0, 2)\nint lowbit(int x) { return (x == 0 ? -1\
    \ : __builtin_ctz(x)); }\nint lowbit(u32 x) { return (x == 0 ? -1 : __builtin_ctz(x));\
    \ }\nint lowbit(ll x) { return (x == 0 ? -1 : __builtin_ctzll(x)); }\nint lowbit(u64\
    \ x) { return (x == 0 ? -1 : __builtin_ctzll(x)); }\n\ntemplate <typename T>\n\
    T floor(T a, T b) {\n  return a / b - (a % b && (a ^ b) < 0);\n}\ntemplate <typename\
    \ T>\nT ceil(T x, T y) {\n  return floor(x + y - 1, y);\n}\ntemplate <typename\
    \ T>\nT bmod(T x, T y) {\n  return x - y * floor(x, y);\n}\ntemplate <typename\
    \ T>\npair<T, T> divmod(T x, T y) {\n  T q = floor(x, y);\n  return {q, x - q\
    \ * y};\n}\n\ntemplate <typename T, typename U>\nT SUM(const vector<U> &A) {\n\
    \  T sm = 0;\n  for (auto &&a: A) sm += a;\n  return sm;\n}\n\n#define MIN(v)\
    \ *min_element(all(v))\n#define MAX(v) *max_element(all(v))\n#define LB(c, x)\
    \ distance((c).begin(), lower_bound(all(c), (x)))\n#define UB(c, x) distance((c).begin(),\
    \ upper_bound(all(c), (x)))\n#define UNIQUE(x) sort(all(x)), x.erase(unique(all(x)),\
    \ x.end()), x.shrink_to_fit()\n\ntemplate <typename T>\nT POP(deque<T> &que) {\n\
    \  T a = que.front();\n  que.pop_front();\n  return a;\n}\ntemplate <typename\
    \ T>\nT POP(pq<T> &que) {\n  T a = que.top();\n  que.pop();\n  return a;\n}\n\
    template <typename T>\nT POP(pqg<T> &que) {\n  T a = que.top();\n  que.pop();\n\
    \  return a;\n}\ntemplate <typename T>\nT POP(vc<T> &que) {\n  T a = que.back();\n\
    \  que.pop_back();\n  return a;\n}\n\ntemplate <typename F>\nll binary_search(F\
    \ check, ll ok, ll ng, bool check_ok = true) {\n  if (check_ok) assert(check(ok));\n\
    \  while (abs(ok - ng) > 1) {\n    auto x = (ng + ok) / 2;\n    (check(x) ? ok\
    \ : ng) = x;\n  }\n  return ok;\n}\ntemplate <typename F>\ndouble binary_search_real(F\
    \ check, double ok, double ng, int iter = 100) {\n  FOR(iter) {\n    double x\
    \ = (ok + ng) / 2;\n    (check(x) ? ok : ng) = x;\n  }\n  return (ok + ng) / 2;\n\
    }\n\ntemplate <class T, class S>\ninline bool chmax(T &a, const S &b) {\n  return\
    \ (a < b ? a = b, 1 : 0);\n}\ntemplate <class T, class S>\ninline bool chmin(T\
    \ &a, const S &b) {\n  return (a > b ? a = b, 1 : 0);\n}\n\n// ? \u306F -1\nvc<int>\
    \ s_to_vi(const string &S, char first_char) {\n  vc<int> A(S.size());\n  FOR(i,\
    \ S.size()) { A[i] = (S[i] != '?' ? S[i] - first_char : -1); }\n  return A;\n\
    }\n\ntemplate <typename T, typename U>\nvector<T> cumsum(vector<U> &A, int off\
    \ = 1) {\n  int N = A.size();\n  vector<T> B(N + 1);\n  FOR(i, N) { B[i + 1] =\
    \ B[i] + A[i]; }\n  if (off == 0) B.erase(B.begin());\n  return B;\n}\n\n// stable\
    \ sort\ntemplate <typename T>\nvector<int> argsort(const vector<T> &A) {\n  vector<int>\
    \ ids(len(A));\n  iota(all(ids), 0);\n  sort(all(ids), [&](int i, int j) { return\
    \ (A[i] == A[j] ? i < j : A[i] < A[j]); });\n  return ids;\n}\n\n// A[I[0]], A[I[1]],\
    \ ...\ntemplate <typename T>\nvc<T> rearrange(const vc<T> &A, const vc<int> &I)\
    \ {\n  vc<T> B(len(I));\n  FOR(i, len(I)) B[i] = A[I[i]];\n  return B;\n}\n\n\
    template <typename T, typename... Vectors>\nvoid concat(vc<T> &first, const Vectors\
    \ &... others) {\n  vc<T> &res = first;\n  (res.insert(res.end(), others.begin(),\
    \ others.end()), ...);\n}\n#endif\n#line 4 \"test/1_mytest/wavelet_matrix.test.cpp\"\
    \n\n#line 2 \"random/base.hpp\"\n\nu64 RNG_64() {\n  static uint64_t x_\n    \
    \  = uint64_t(chrono::duration_cast<chrono::nanoseconds>(chrono::high_resolution_clock::now().time_since_epoch()).count())\
    \ * 10150724397891781847ULL;\n  x_ ^= x_ << 7;\n  return x_ ^= x_ >> 9;\n}\n\n\
    u64 RNG(u64 lim) { return RNG_64() % lim; }\n\nll RNG(ll l, ll r) { return l +\
    \ RNG_64() % (r - l); }\n#line 1 \"ds/bit_vector.hpp\"\nstruct Bit_Vector {\n\
    \  int n;\n  bool prepared = 0;\n  vc<pair<u64, u32>> dat;\n  Bit_Vector(int n)\
    \ : n(n) { dat.assign((n + 127) >> 6, {0, 0}); }\n  void set(int i) {\n    assert(!prepared);\n\
    \    dat[i >> 6].fi |= u64(1) << (i & 63);\n  }\n  void reset() {\n    fill(all(dat),\
    \ pair<u64, u32>{0, 0});\n    prepared = 0;\n  }\n  void build() {\n    prepared\
    \ = 1;\n    FOR(i, len(dat) - 1) dat[i + 1].se = dat[i].se + popcnt(dat[i].fi);\n\
    \  }\n  // [0, k) \u5185\u306E 1 \u306E\u500B\u6570\n  bool operator[](int i)\
    \ { return dat[i >> 6].fi >> (i & 63) & 1; }\n  int count_prefix(int k, bool f\
    \ = true) {\n    assert(prepared);\n    auto [a, b] = dat[k >> 6];\n    int ret\
    \ = b + popcnt(a & ((u64(1) << (k & 63)) - 1));\n    return (f ? ret : k - ret);\n\
    \  }\n  int count(int L, int R, bool f = true) { return count_prefix(R, f) - count_prefix(L,\
    \ f); }\n  string to_string() {\n    string ans;\n    FOR(i, n) ans += '0' + (dat[i\
    \ / 64].fi >> (i % 64) & 1);\n    return ans;\n  }\n};\n#line 1 \"ds/index_compression.hpp\"\
    \ntemplate <typename T>\nstruct Index_Compression_DISTINCT_SMALL {\n  static_assert(is_same_v<T,\
    \ int>);\n  int mi, ma;\n  vc<int> dat;\n  vc<int> build(vc<int> X) {\n    mi\
    \ = 0, ma = -1;\n    if (!X.empty()) mi = MIN(X), ma = MAX(X);\n    dat.assign(ma\
    \ - mi + 2, 0);\n    for (auto& x: X) dat[x - mi + 1]++;\n    FOR(i, len(dat)\
    \ - 1) dat[i + 1] += dat[i];\n    for (auto& x: X) { x = dat[x - mi]++; }\n  \
    \  FOR_R(i, 1, len(dat)) dat[i] = dat[i - 1];\n    dat[0] = 0;\n    return X;\n\
    \  }\n  int operator()(ll x) { return dat[clamp<ll>(x - mi, 0, ma - mi + 1)];\
    \ }\n};\n\ntemplate <typename T>\nstruct Index_Compression_SAME_SMALL {\n  static_assert(is_same_v<T,\
    \ int>);\n  int mi, ma;\n  vc<int> dat;\n  vc<int> build(vc<int> X) {\n    mi\
    \ = 0, ma = -1;\n    if (!X.empty()) mi = MIN(X), ma = MAX(X);\n    dat.assign(ma\
    \ - mi + 2, 0);\n    for (auto& x: X) dat[x - mi + 1] = 1;\n    FOR(i, len(dat)\
    \ - 1) dat[i + 1] += dat[i];\n    for (auto& x: X) { x = dat[x - mi]; }\n    return\
    \ X;\n  }\n  int operator()(ll x) { return dat[clamp<ll>(x - mi, 0, ma - mi +\
    \ 1)]; }\n};\n\ntemplate <typename T>\nstruct Index_Compression_SAME_LARGE {\n\
    \  vc<T> dat;\n  vc<int> build(vc<T> X) {\n    vc<int> I = argsort(X);\n    vc<int>\
    \ res(len(X));\n    for (auto& i: I) {\n      if (!dat.empty() && dat.back() ==\
    \ X[i]) {\n        res[i] = len(dat) - 1;\n      } else {\n        res[i] = len(dat);\n\
    \        dat.eb(X[i]);\n      }\n    }\n    dat.shrink_to_fit();\n    return res;\n\
    \  }\n  int operator()(T x) { return LB(dat, x); }\n};\n\ntemplate <typename T>\n\
    struct Index_Compression_DISTINCT_LARGE {\n  vc<T> dat;\n  vc<int> build(vc<T>\
    \ X) {\n    vc<int> I = argsort(X);\n    vc<int> res(len(X));\n    for (auto&\
    \ i: I) { res[i] = len(dat), dat.eb(X[i]); }\n    dat.shrink_to_fit();\n    return\
    \ res;\n  }\n  int operator()(T x) { return LB(dat, x); }\n};\n\ntemplate <typename\
    \ T, bool SMALL>\nusing Index_Compression_DISTINCT =\n    typename std::conditional<SMALL,\
    \ Index_Compression_DISTINCT_SMALL<T>,\n                              Index_Compression_DISTINCT_LARGE<T>>::type;\n\
    template <typename T, bool SMALL>\nusing Index_Compression_SAME =\n    typename\
    \ std::conditional<SMALL, Index_Compression_SAME_SMALL<T>,\n                 \
    \             Index_Compression_SAME_LARGE<T>>::type;\n\n// SAME: [2,3,2] -> [0,1,0]\n\
    // DISTINCT: [2,2,3] -> [0,2,1]\n// (x): lower_bound(X,x) \u3092\u304B\u3048\u3059\
    \ntemplate <typename T, bool SAME, bool SMALL>\nusing Index_Compression =\n  \
    \  typename std::conditional<SAME, Index_Compression_SAME<T, SMALL>,\n       \
    \                       Index_Compression_DISTINCT<T, SMALL>>::type;\n#line 2\
    \ \"alg/monoid/add.hpp\"\n\r\ntemplate <typename E>\r\nstruct Monoid_Add {\r\n\
    \  using X = E;\r\n  using value_type = X;\r\n  static constexpr X op(const X\
    \ &x, const X &y) noexcept { return x + y; }\r\n  static constexpr X inverse(const\
    \ X &x) noexcept { return -x; }\r\n  static constexpr X power(const X &x, ll n)\
    \ noexcept { return X(n) * x; }\r\n  static constexpr X unit() { return X(0);\
    \ }\r\n  static constexpr bool commute = true;\r\n};\r\n#line 4 \"ds/wavelet_matrix/wavelet_matrix.hpp\"\
    \n\r\n// \u9759\u7684\u30E1\u30BD\u30C3\u30C9inverse\u306E\u5B58\u5728\u3092\u30C1\
    \u30A7\u30C3\u30AF\u3059\u308B\u30C6\u30F3\u30D7\u30EC\u30FC\u30C8\r\ntemplate\
    \ <typename, typename = std::void_t<>>\r\nstruct has_inverse : std::false_type\
    \ {};\r\n\r\ntemplate <typename T>\r\nstruct has_inverse<T, std::void_t<decltype(T::inverse(std::declval<typename\
    \ T::value_type>()))>> : std::true_type {};\r\n\r\nstruct Dummy_Data_Structure\
    \ {\r\n  using MX = Monoid_Add<bool>;\r\n  void build(const vc<bool>& A) {}\r\n\
    };\r\n\r\ntemplate <typename Y, bool SMALL_Y, typename SEGTREE = Dummy_Data_Structure>\r\
    \nstruct Wavelet_Matrix {\r\n  using Mono = typename SEGTREE::MX;\r\n  using T\
    \ = typename Mono::value_type;\r\n  static_assert(Mono::commute);\r\n\r\n  int\
    \ n, log, K;\r\n  Index_Compression<Y, true, SMALL_Y> IDX;\r\n  vc<Y> ItoY;\r\n\
    \  vc<int> mid;\r\n  vc<Bit_Vector> bv;\r\n  vc<SEGTREE> seg;\r\n\r\n  Wavelet_Matrix()\
    \ {}\r\n  Wavelet_Matrix(const vc<Y>& A) { build(A); }\r\n  Wavelet_Matrix(const\
    \ vc<Y>& A, vc<T>& SUM_Data) { build(A, SUM_Data); }\r\n  template <typename F>\r\
    \n  Wavelet_Matrix(int n, F f) {\r\n    build(n, f);\r\n  }\r\n\r\n  template\
    \ <typename F>\r\n  void build(int m, F f) {\r\n    vc<Y> A(m);\r\n    vc<T> S(m);\r\
    \n    for (int i = 0; i < m; ++i) tie(A[i], S[i]) = f(i);\r\n    build(A, S);\r\
    \n  }\r\n\r\n  void build(const vc<Y>& A) { build(A, vc<T>(len(A), Mono::unit()));\
    \ }\r\n  void build(const vc<Y>& A, vc<T> S) {\r\n    n = len(A);\r\n    vc<int>\
    \ B = IDX.build(A);\r\n    K = 0;\r\n    for (auto& x: B) chmax(K, x + 1);\r\n\
    \    ItoY.resize(K);\r\n    FOR(i, n) ItoY[B[i]] = A[i];\r\n    log = 0;\r\n \
    \   while ((1 << log) < K) ++log;\r\n    mid.resize(log), bv.assign(log, Bit_Vector(n));\r\
    \n    vc<int> B0(n), B1(n);\r\n    vc<T> S0(n), S1(n);\r\n    seg.resize(log +\
    \ 1);\r\n    seg[log].build(S);\r\n    for (int d = log - 1; d >= 0; --d) {\r\n\
    \      int p0 = 0, p1 = 0;\r\n      for (int i = 0; i < n; ++i) {\r\n        bool\
    \ f = (B[i] >> d & 1);\r\n        if (!f) { B0[p0] = B[i], S0[p0] = S[i], p0++;\
    \ }\r\n        if (f) { bv[d].set(i), B1[p1] = B[i], S1[p1] = S[i], p1++; }\r\n\
    \      }\r\n      swap(B, B0), swap(S, S0);\r\n      move(B1.begin(), B1.begin()\
    \ + p1, B.begin() + p0);\r\n      move(S1.begin(), S1.begin() + p1, S.begin()\
    \ + p0);\r\n      mid[d] = p0, bv[d].build(), seg[d].build(S);\r\n    }\r\n  }\r\
    \n\r\n  // [L,R) x [0,y)\r\n  int prefix_count(int L, int R, Y y) {\r\n    int\
    \ p = IDX(y);\r\n    if (L == R || p == 0) return 0;\r\n    if (p == K) return\
    \ R - L;\r\n    int cnt = 0;\r\n    for (int d = log - 1; d >= 0; --d) {\r\n \
    \     int l0 = bv[d].count_prefix(L, 0), r0 = bv[d].count_prefix(R, 0);\r\n  \
    \    int l1 = L + mid[d] - l0, r1 = R + mid[d] - r0;\r\n      if (p >> d & 1)\
    \ cnt += r0 - l0, L = l1, R = r1;\r\n      if (!(p >> d & 1)) L = l0, R = r0;\r\
    \n    }\r\n    return cnt;\r\n  }\r\n\r\n  // [L,R) x [y1,y2)\r\n  int count(int\
    \ L, int R, Y y1, Y y2) { return prefix_count(L, R, y2) - prefix_count(L, R, y1);\
    \ }\r\n\r\n  // [L,R) x [0,y)\r\n  pair<int, T> prefix_count_and_prod(int L, int\
    \ R, Y y) {\r\n    int p = IDX(y);\r\n    if (p == 0) return {0, Mono::unit()};\r\
    \n    if (p == K) return {R - L, seg[log].prod(L, R)};\r\n    int cnt = 0;\r\n\
    \    T t = Mono::unit();\r\n    for (int d = log - 1; d >= 0; --d) {\r\n     \
    \ int l0 = bv[d].count_prefix(L, 0), r0 = bv[d].count_prefix(R, 0);\r\n      int\
    \ l1 = L + mid[d] - l0, r1 = R + mid[d] - r0;\r\n      if (p >> d & 1) { cnt +=\
    \ r0 - l0, t = Mono::op(t, seg[d].prod(l0, r0)), L = l1, R = r1; }\r\n      if\
    \ (!(p >> d & 1)) L = l0, R = r0;\r\n    }\r\n    return {cnt, t};\r\n  }\r\n\r\
    \n  // [L,R) x [y1,y2)\r\n  pair<int, T> count_and_prod(int L, int R, Y y1, Y\
    \ y2) {\r\n    if constexpr (has_inverse<Mono>::value) {\r\n      auto [c1, t1]\
    \ = prefix_count_and_prod(L, R, y1);\r\n      auto [c2, t2] = prefix_count_and_prod(L,\
    \ R, y2);\r\n      return {c2 - c1, Mono::op(Mono::inverse(t1), t2)};\r\n    }\r\
    \n    int lo = IDX(y1), hi = IDX(y2), cnt = 0;\r\n    T t = Mono::unit();\r\n\
    \    auto dfs = [&](auto& dfs, int d, int L, int R, int a, int b) -> void {\r\n\
    \      assert(b - a == (1 << d));\r\n      if (hi <= a || b <= lo) return;\r\n\
    \      if (lo <= a && b <= hi) {\r\n        cnt += R - L, t = Mono::op(t, seg[d].prod(L,\
    \ R));\r\n        return;\r\n      }\r\n      --d;\r\n      int c = (a + b) /\
    \ 2;\r\n      int l0 = bv[d].count_prefix(L, 0), r0 = bv[d].count_prefix(R, 0);\r\
    \n      int l1 = L + mid[d] - l0, r1 = R + mid[d] - r0;\r\n      dfs(dfs, d, l0,\
    \ r0, a, c), dfs(dfs, d, l1, r1, c, b);\r\n    };\r\n    dfs(dfs, log, L, R, 0,\
    \ 1 << log);\r\n    return {cnt, t};\r\n  }\r\n\r\n  // [L,R) x [y1,y2)\r\n  T\
    \ prefix_prod(int L, int R, Y y) { return prefix_count_and_prod(L, R, y).se; }\r\
    \n  // [L,R) x [y1,y2)\r\n  T prod(int L, int R, Y y1, Y y2) { return count_and_prod(L,\
    \ R, y1, y2).se; }\r\n  T prod_all(int L, int R) { return seg[log].prod(L, R);\
    \ }\r\n\r\n  Y kth(int L, int R, int k) {\r\n    assert(0 <= k && k < R - L);\r\
    \n    int p = 0;\r\n    for (int d = log - 1; d >= 0; --d) {\r\n      int l0 =\
    \ bv[d].count_prefix(L, 0), r0 = bv[d].count_prefix(R, 0);\r\n      int l1 = L\
    \ + mid[d] - l0, r1 = R + mid[d] - r0;\r\n      if (k < r0 - l0) {\r\n       \
    \ L = l0, R = r0;\r\n      } else {\r\n        k -= r0 - l0, L = l1, R = r1, p\
    \ |= 1 << d;\r\n      }\r\n    }\r\n    return ItoY[p];\r\n  }\r\n\r\n  // y \u4EE5\
    \u4E0A\u6700\u5C0F OR infty<Y>\r\n  Y next(int L, int R, Y y) {\r\n    int k =\
    \ IDX(y);\r\n    int p = K;\r\n\r\n    auto dfs = [&](auto& dfs, int d, int L,\
    \ int R, int a, int b) -> void {\r\n      if (p <= a || L == R || b <= k) return;\r\
    \n      if (d == 0) {\r\n        chmin(p, a);\r\n        return;\r\n      }\r\n\
    \      --d;\r\n      int c = (a + b) / 2;\r\n      int l0 = bv[d].count_prefix(L,\
    \ 0), r0 = bv[d].count_prefix(R, 0);\r\n      int l1 = L + mid[d] - l0, r1 = R\
    \ + mid[d] - r0;\r\n      dfs(dfs, d, l0, r0, a, c), dfs(dfs, d, l1, r1, c, b);\r\
    \n    };\r\n    dfs(dfs, log, L, R, 0, 1 << log);\r\n    return (p == K ? infty<Y>\
    \ : ItoY[p]);\r\n  }\r\n\r\n  // y \u4EE5\u4E0B\u6700\u5927 OR -infty<T>\r\n \
    \ Y prev(int L, int R, Y y) {\r\n    int k = IDX(y + 1);\r\n    int p = -1;\r\n\
    \    auto dfs = [&](auto& dfs, int d, int L, int R, int a, int b) -> void {\r\n\
    \      if (b - 1 <= p || L == R || k <= a) return;\r\n      if (d == 0) {\r\n\
    \        chmax(p, a);\r\n        return;\r\n      }\r\n      --d;\r\n      int\
    \ c = (a + b) / 2;\r\n      int l0 = bv[d].count_prefix(L, 0), r0 = bv[d].count_prefix(R,\
    \ 0);\r\n      int l1 = L + mid[d] - l0, r1 = R + mid[d] - r0;\r\n      dfs(dfs,\
    \ d, l1, r1, c, b), dfs(dfs, d, l0, r0, a, c);\r\n    };\r\n    dfs(dfs, log,\
    \ L, R, 0, 1 << log);\r\n    return (p == -1 ? -infty<Y> : ItoY[p]);\r\n  }\r\n\
    \r\n  Y median(bool UPPER, int L, int R) {\r\n    assert(0 <= L && L < R && R\
    \ <= n);\r\n    int k = (UPPER ? (R - L) / 2 : (R - L - 1) / 2);\r\n    return\
    \ kth(L, R, k);\r\n  }\r\n\r\n  pair<Y, T> kth_value_and_prod(int L, int R, int\
    \ k) {\r\n    assert(0 <= k && k <= R - L);\r\n    if (k == R - L) return {infty<Y>,\
    \ seg[log].prod(L, R)};\r\n    int p = 0;\r\n    T t = Mono::unit();\r\n    for\
    \ (int d = log - 1; d >= 0; --d) {\r\n      int l0 = bv[d].count_prefix(L, 0),\
    \ r0 = bv[d].count_prefix(R, 0);\r\n      int l1 = L + mid[d] - l0, r1 = R + mid[d]\
    \ - r0;\r\n      if (k < r0 - l0) {\r\n        L = l0, R = r0;\r\n      } else\
    \ {\r\n        t = Mono::op(t, seg[d].prod(l0, r0)), k -= r0 - l0, L = l1, R =\
    \ r1, p |= 1 << d;\r\n      }\r\n    }\r\n    t = Mono::op(t, seg[0].prod(L, L\
    \ + k));\r\n    return {ItoY[p], t};\r\n  }\r\n\r\n  T prod_index_range(int L,\
    \ int R, int k1, int k2) {\r\n    static_assert(has_inverse<Mono>::value);\r\n\
    \    T t1 = kth_value_and_prod(L, R, k1).se;\r\n    T t2 = kth_value_and_prod(L,\
    \ R, k2).se;\r\n    return Mono::op(Mono::inverse(t1), t2);\r\n  }\r\n\r\n  //\
    \ [L,R) x [0,y) \u3067\u306E check(cnt, prod) \u304C true \u3068\u306A\u308B\u6700\
    \u5927\u306E (cnt,prod)\r\n  template <typename F>\r\n  pair<int, T> max_right(F\
    \ check, int L, int R) {\r\n    int cnt = 0;\r\n    T t = Mono::unit();\r\n  \
    \  assert(check(0, Mono::unit()));\r\n    if (check(R - L, seg[log].prod(L, R)))\
    \ { return {R - L, seg[log].prod(L, R)}; }\r\n    for (int d = log - 1; d >= 0;\
    \ --d) {\r\n      int l0 = bv[d].count_prefix(L, 0), r0 = bv[d].count_prefix(R,\
    \ 0);\r\n      int l1 = L + mid[d] - l0, r1 = R + mid[d] - r0;\r\n      int cnt1\
    \ = cnt + r0 - l0;\r\n      T t1 = Mono::op(t, seg[d].prod(l0, r0));\r\n     \
    \ if (check(cnt1, t1)) {\r\n        cnt = cnt1, t = t1, L = l1, R = r1;\r\n  \
    \    } else {\r\n        L = l0, R = r0;\r\n      }\r\n    }\r\n    return {cnt,\
    \ t};\r\n  }\r\n\r\n  void set(int i, T t) {\r\n    assert(0 <= i && i < n);\r\
    \n    int L = i, R = i + 1;\r\n    seg[log].set(L, t);\r\n    for (int d = log\
    \ - 1; d >= 0; --d) {\r\n      int l0 = bv[d].count_prefix(L, 0), r0 = bv[d].count_prefix(R,\
    \ 0);\r\n      int l1 = L + mid[d] - l0, r1 = R + mid[d] - r0;\r\n      if (l0\
    \ < r0) L = l0, R = r0;\r\n      if (l0 == r0) L = l1, R = r1;\r\n      seg[d].set(L,\
    \ t);\r\n    }\r\n  }\r\n  void multiply(int i, T t) {\r\n    assert(0 <= i &&\
    \ i < n);\r\n    int L = i, R = i + 1;\r\n    seg[log].multiply(L, t);\r\n   \
    \ for (int d = log - 1; d >= 0; --d) {\r\n      int l0 = bv[d].count_prefix(L,\
    \ 0), r0 = bv[d].count_prefix(R, 0);\r\n      int l1 = L + mid[d] - l0, r1 = R\
    \ + mid[d] - r0;\r\n      if (l0 < r0) L = l0, R = r0;\r\n      if (l0 == r0)\
    \ L = l1, R = r1;\r\n      seg[d].multiply(L, t);\r\n    }\r\n  }\r\n  void add(int\
    \ i, T t) { multiply(i, t); }\r\n};\r\n#line 2 \"ds/static_range_product_group.hpp\"\
    \n\ntemplate <typename Monoid>\nstruct Static_Range_Product_Group {\n  using MX\
    \ = Monoid;\n  using X = typename MX::value_type;\n  int n;\n  vc<X> dat;\n  Static_Range_Product_Group()\
    \ {}\n  template <typename F>\n  Static_Range_Product_Group(int m, F f) {\n  \
    \  build(m, f);\n  }\n  template <typename F>\n  void build(int m, F f) {\n  \
    \  n = m;\n    dat.assign(n + 1, MX::unit());\n    for (int i = 0; i < n; ++i)\
    \ dat[i + 1] = MX::op(dat[i], f(i));\n  }\n  void build(vc<X>& A) {\n    n = len(A);\n\
    \    dat.assign(n + 1, MX::unit());\n    for (int i = 0; i < n; ++i) dat[i + 1]\
    \ = MX::op(dat[i], A[i]);\n  }\n  X prod(int l, int r) { return MX::op(MX::inverse(dat[l]),\
    \ dat[r]); }\n};\n\ntemplate <typename T>\nusing Prefix_Sum = Static_Range_Product_Group<Monoid_Add<T>>;\n\
    #line 2 \"ds/segtree/segtree.hpp\"\n\ntemplate <class Monoid>\nstruct SegTree\
    \ {\n  using MX = Monoid;\n  using X = typename MX::value_type;\n  using value_type\
    \ = X;\n  vc<X> dat;\n  int n, log, size;\n\n  SegTree() {}\n  SegTree(int n)\
    \ { build(n); }\n  template <typename F>\n  SegTree(int n, F f) {\n    build(n,\
    \ f);\n  }\n  SegTree(const vc<X>& v) { build(v); }\n\n  void build(int m) {\n\
    \    build(m, [](int i) -> X { return MX::unit(); });\n  }\n  void build(const\
    \ vc<X>& v) {\n    build(len(v), [&](int i) -> X { return v[i]; });\n  }\n  template\
    \ <typename F>\n  void build(int m, F f) {\n    n = m, log = 1;\n    while ((1\
    \ << log) < n) ++log;\n    size = 1 << log;\n    dat.assign(size << 1, MX::unit());\n\
    \    FOR(i, n) dat[size + i] = f(i);\n    FOR_R(i, 1, size) update(i);\n  }\n\n\
    \  X get(int i) { return dat[size + i]; }\n  vc<X> get_all() { return {dat.begin()\
    \ + size, dat.begin() + size + n}; }\n\n  void update(int i) { dat[i] = Monoid::op(dat[2\
    \ * i], dat[2 * i + 1]); }\n  void set(int i, const X& x) {\n    assert(i < n);\n\
    \    dat[i += size] = x;\n    while (i >>= 1) update(i);\n  }\n\n  void multiply(int\
    \ i, const X& x) {\n    assert(i < n);\n    i += size;\n    dat[i] = Monoid::op(dat[i],\
    \ x);\n    while (i >>= 1) update(i);\n  }\n\n  X prod(int L, int R) {\n    assert(0\
    \ <= L && L <= R && R <= n);\n    X vl = Monoid::unit(), vr = Monoid::unit();\n\
    \    L += size, R += size;\n    while (L < R) {\n      if (L & 1) vl = Monoid::op(vl,\
    \ dat[L++]);\n      if (R & 1) vr = Monoid::op(dat[--R], vr);\n      L >>= 1,\
    \ R >>= 1;\n    }\n    return Monoid::op(vl, vr);\n  }\n\n  X prod_all() { return\
    \ dat[1]; }\n\n  template <class F>\n  int max_right(F check, int L) {\n    assert(0\
    \ <= L && L <= n && check(Monoid::unit()));\n    if (L == n) return n;\n    L\
    \ += size;\n    X sm = Monoid::unit();\n    do {\n      while (L % 2 == 0) L >>=\
    \ 1;\n      if (!check(Monoid::op(sm, dat[L]))) {\n        while (L < size) {\n\
    \          L = 2 * L;\n          if (check(Monoid::op(sm, dat[L]))) { sm = Monoid::op(sm,\
    \ dat[L++]); }\n        }\n        return L - size;\n      }\n      sm = Monoid::op(sm,\
    \ dat[L++]);\n    } while ((L & -L) != L);\n    return n;\n  }\n\n  template <class\
    \ F>\n  int min_left(F check, int R) {\n    assert(0 <= R && R <= n && check(Monoid::unit()));\n\
    \    if (R == 0) return 0;\n    R += size;\n    X sm = Monoid::unit();\n    do\
    \ {\n      --R;\n      while (R > 1 && (R % 2)) R >>= 1;\n      if (!check(Monoid::op(dat[R],\
    \ sm))) {\n        while (R < size) {\n          R = 2 * R + 1;\n          if\
    \ (check(Monoid::op(dat[R], sm))) { sm = Monoid::op(dat[R--], sm); }\n       \
    \ }\n        return R + 1 - size;\n      }\n      sm = Monoid::op(dat[R], sm);\n\
    \    } while ((R & -R) != R);\n    return 0;\n  }\n\n  // prod_{l<=i<r} A[i xor\
    \ x]\n  X xor_prod(int l, int r, int xor_val) {\n    static_assert(Monoid::commute);\n\
    \    X x = Monoid::unit();\n    for (int k = 0; k < log + 1; ++k) {\n      if\
    \ (l >= r) break;\n      if (l & 1) { x = Monoid::op(x, dat[(size >> k) + ((l++)\
    \ ^ xor_val)]); }\n      if (r & 1) { x = Monoid::op(x, dat[(size >> k) + ((--r)\
    \ ^ xor_val)]); }\n      l /= 2, r /= 2, xor_val /= 2;\n    }\n    return x;\n\
    \  }\n};\n#line 2 \"alg/monoid/min.hpp\"\n\r\ntemplate <typename E>\r\nstruct\
    \ Monoid_Min {\r\n  using X = E;\r\n  using value_type = X;\r\n  static constexpr\
    \ X op(const X &x, const X &y) noexcept { return min(x, y); }\r\n  static constexpr\
    \ X unit() { return infty<E>; }\r\n  static constexpr bool commute = true;\r\n\
    };\r\n#line 10 \"test/1_mytest/wavelet_matrix.test.cpp\"\n\ntemplate <bool SMALL_Y,\
    \ typename SEGTREE>\nvoid test(int N) {\n  int MAX = RNG(2, 1 << 10);\n  vc<int>\
    \ A(N);\n  vc<int> X(N);\n  FOR(i, N) X[i] = RNG(MAX);\n  FOR(i, N) A[i] = RNG(MAX);\n\
    \n  Wavelet_Matrix<int, false, SEGTREE> WM(A, X);\n  using Mono = typename SEGTREE::MX;\n\
    \n  int Q = 100;\n  FOR(Q) {\n    int L = RNG(0, max(1, N));\n    int R = RNG(0,\
    \ max(1, N + 1));\n    if (L > R) swap(L, R);\n    int lo = RNG(0, MAX);\n   \
    \ int hi = RNG(0, MAX);\n    if (lo > hi) swap(lo, hi);\n    ++hi;\n    vc<int>\
    \ B = {A.begin() + L, A.begin() + R};\n    vc<int> Y = {X.begin() + L, X.begin()\
    \ + R};\n    int t = RNG(0, 7);\n    if (t == 0) { // count\n      int cnt = 0;\n\
    \      for (auto&& x: B)\n        if (lo <= x && x < hi) cnt += 1;\n      assert(WM.count(L,\
    \ R, lo, hi) == cnt);\n    }\n    if (t == 1) { // sm\n      int sm = Mono::unit();\n\
    \      FOR(i, L, R) if (lo <= A[i] && A[i] < hi) sm = Mono::op(sm, X[i]);\n  \
    \    assert(WM.prod(L, R, lo, hi) == sm);\n    }\n    if (t == 2) { // kth\n \
    \     if (L == R) continue;\n      int k = RNG(R - L);\n      sort(all(B));\n\
    \      assert(WM.kth(L, R, k) == B[k]);\n    }\n    if (is_same_v<Mono, Monoid_Add<int>>\
    \ && t == 3) { // max_right\n      int a = RNG(0, 10);\n      int b = RNG(0, 10);\n\
    \      int c = RNG(0, a * (R - L) + b * MAX * (R - L) + 1);\n      auto check\n\
    \          = [&](int cnt, int sm) -> bool { return a * cnt + b * sm <= c; };\n\
    \      auto p = WM.max_right(check, L, R);\n      int cnt = 0, sm = 0;\n     \
    \ binary_search(\n          [&](int y) -> bool {\n            auto [c, s] = WM.prefix_count_and_prod(L,\
    \ R, y);\n            if (check(c, s)) cnt = c, sm = s;\n            return check(c,\
    \ s);\n          },\n          -10, MAX + 10);\n      assert(p.fi == cnt && p.se\
    \ == sm);\n    }\n    if (t == 4) { // k-th value and prod\n      int k = RNG(0,\
    \ R - L + 1);\n      B.eb(infty<int>);\n      auto I = argsort(B);\n      int\
    \ val = B[I[k]];\n      int sm = Mono::unit();\n      FOR(i, k) sm = Mono::op(sm,\
    \ Y[I[i]]);\n      auto p = WM.kth_value_and_prod(L, R, k);\n      assert(p.fi\
    \ == val && p.se == sm);\n    }\n    if (t == 5) { // next\n      int x = RNG(-1,\
    \ MAX + 2);\n      int ans = infty<int>;\n      for (auto& b: B) {\n        if\
    \ (x <= b) chmin(ans, b);\n      }\n      assert(ans == WM.next(L, R, x));\n \
    \   }\n    if (t == 6) { // prev\n      int x = RNG(-1, MAX + 1);\n      int ans\
    \ = -infty<int>;\n      for (auto& b: B) {\n        if (b <= x) chmax(ans, b);\n\
    \      }\n      assert(ans == WM.prev(L, R, x));\n    }\n  }\n}\n\nvoid solve()\
    \ {\n  int a, b;\n  cin >> a >> b;\n  cout << a + b << \"\\n\";\n}\n\nsigned main()\
    \ {\n  FOR(N, 64) {\n    FOR(50) {\n      test<true, Static_Range_Product_Group<Monoid_Add<int>>>(N);\n\
    \      test<false, Static_Range_Product_Group<Monoid_Add<int>>>(N);\n      test<true,\
    \ SegTree<Monoid_Min<int>>>(N);\n      test<false, SegTree<Monoid_Min<int>>>(N);\n\
    \    }\n  }\n  solve();\n\n  return 0;\n}\n"
  code: "#define PROBLEM \"https://judge.yosupo.jp/problem/aplusb\"\n\n#include \"\
    my_template.hpp\"\n\n#include \"random/base.hpp\"\n#include \"ds/wavelet_matrix/wavelet_matrix.hpp\"\
    \n#include \"ds/static_range_product_group.hpp\"\n#include \"ds/segtree/segtree.hpp\"\
    \n#include \"alg/monoid/min.hpp\"\n\ntemplate <bool SMALL_Y, typename SEGTREE>\n\
    void test(int N) {\n  int MAX = RNG(2, 1 << 10);\n  vc<int> A(N);\n  vc<int> X(N);\n\
    \  FOR(i, N) X[i] = RNG(MAX);\n  FOR(i, N) A[i] = RNG(MAX);\n\n  Wavelet_Matrix<int,\
    \ false, SEGTREE> WM(A, X);\n  using Mono = typename SEGTREE::MX;\n\n  int Q =\
    \ 100;\n  FOR(Q) {\n    int L = RNG(0, max(1, N));\n    int R = RNG(0, max(1,\
    \ N + 1));\n    if (L > R) swap(L, R);\n    int lo = RNG(0, MAX);\n    int hi\
    \ = RNG(0, MAX);\n    if (lo > hi) swap(lo, hi);\n    ++hi;\n    vc<int> B = {A.begin()\
    \ + L, A.begin() + R};\n    vc<int> Y = {X.begin() + L, X.begin() + R};\n    int\
    \ t = RNG(0, 7);\n    if (t == 0) { // count\n      int cnt = 0;\n      for (auto&&\
    \ x: B)\n        if (lo <= x && x < hi) cnt += 1;\n      assert(WM.count(L, R,\
    \ lo, hi) == cnt);\n    }\n    if (t == 1) { // sm\n      int sm = Mono::unit();\n\
    \      FOR(i, L, R) if (lo <= A[i] && A[i] < hi) sm = Mono::op(sm, X[i]);\n  \
    \    assert(WM.prod(L, R, lo, hi) == sm);\n    }\n    if (t == 2) { // kth\n \
    \     if (L == R) continue;\n      int k = RNG(R - L);\n      sort(all(B));\n\
    \      assert(WM.kth(L, R, k) == B[k]);\n    }\n    if (is_same_v<Mono, Monoid_Add<int>>\
    \ && t == 3) { // max_right\n      int a = RNG(0, 10);\n      int b = RNG(0, 10);\n\
    \      int c = RNG(0, a * (R - L) + b * MAX * (R - L) + 1);\n      auto check\n\
    \          = [&](int cnt, int sm) -> bool { return a * cnt + b * sm <= c; };\n\
    \      auto p = WM.max_right(check, L, R);\n      int cnt = 0, sm = 0;\n     \
    \ binary_search(\n          [&](int y) -> bool {\n            auto [c, s] = WM.prefix_count_and_prod(L,\
    \ R, y);\n            if (check(c, s)) cnt = c, sm = s;\n            return check(c,\
    \ s);\n          },\n          -10, MAX + 10);\n      assert(p.fi == cnt && p.se\
    \ == sm);\n    }\n    if (t == 4) { // k-th value and prod\n      int k = RNG(0,\
    \ R - L + 1);\n      B.eb(infty<int>);\n      auto I = argsort(B);\n      int\
    \ val = B[I[k]];\n      int sm = Mono::unit();\n      FOR(i, k) sm = Mono::op(sm,\
    \ Y[I[i]]);\n      auto p = WM.kth_value_and_prod(L, R, k);\n      assert(p.fi\
    \ == val && p.se == sm);\n    }\n    if (t == 5) { // next\n      int x = RNG(-1,\
    \ MAX + 2);\n      int ans = infty<int>;\n      for (auto& b: B) {\n        if\
    \ (x <= b) chmin(ans, b);\n      }\n      assert(ans == WM.next(L, R, x));\n \
    \   }\n    if (t == 6) { // prev\n      int x = RNG(-1, MAX + 1);\n      int ans\
    \ = -infty<int>;\n      for (auto& b: B) {\n        if (b <= x) chmax(ans, b);\n\
    \      }\n      assert(ans == WM.prev(L, R, x));\n    }\n  }\n}\n\nvoid solve()\
    \ {\n  int a, b;\n  cin >> a >> b;\n  cout << a + b << \"\\n\";\n}\n\nsigned main()\
    \ {\n  FOR(N, 64) {\n    FOR(50) {\n      test<true, Static_Range_Product_Group<Monoid_Add<int>>>(N);\n\
    \      test<false, Static_Range_Product_Group<Monoid_Add<int>>>(N);\n      test<true,\
    \ SegTree<Monoid_Min<int>>>(N);\n      test<false, SegTree<Monoid_Min<int>>>(N);\n\
    \    }\n  }\n  solve();\n\n  return 0;\n}\n"
  dependsOn:
  - my_template.hpp
  - random/base.hpp
  - ds/wavelet_matrix/wavelet_matrix.hpp
  - ds/bit_vector.hpp
  - ds/index_compression.hpp
  - alg/monoid/add.hpp
  - ds/static_range_product_group.hpp
  - ds/segtree/segtree.hpp
  - alg/monoid/min.hpp
  isVerificationFile: true
  path: test/1_mytest/wavelet_matrix.test.cpp
  requiredBy: []
  timestamp: '2024-09-28 04:06:11+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: test/1_mytest/wavelet_matrix.test.cpp
layout: document
redirect_from:
- /verify/test/1_mytest/wavelet_matrix.test.cpp
- /verify/test/1_mytest/wavelet_matrix.test.cpp.html
title: test/1_mytest/wavelet_matrix.test.cpp
---
