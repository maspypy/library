---
data:
  _extendedDependsOn:
  - icon: ':question:'
    path: ds/kdtree/kdtree.hpp
    title: ds/kdtree/kdtree.hpp
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
  bundledCode: "#line 1 \"test/1_mytest/kdtree_nns.test.cpp\"\n#define PROBLEM \"\
    https://judge.yosupo.jp/problem/aplusb\"\n\n#line 1 \"my_template.hpp\"\n#if defined(LOCAL)\n\
    #include <my_template_compiled.hpp>\n#else\n\n// https://codeforces.com/blog/entry/96344\n\
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
    \ others.end()), ...);\n}\n#endif\n#line 4 \"test/1_mytest/kdtree_nns.test.cpp\"\
    \n\n#line 2 \"random/base.hpp\"\n\nu64 RNG_64() {\n  static u64 x_ = u64(chrono::duration_cast<chrono::nanoseconds>(chrono::high_resolution_clock::now().time_since_epoch()).count())\
    \ * 10150724397891781847ULL;\n  x_ ^= x_ << 7;\n  return x_ ^= x_ >> 9;\n}\n\n\
    u64 RNG(u64 lim) { return RNG_64() % lim; }\n\nll RNG(ll l, ll r) { return l +\
    \ RNG_64() % (r - l); }\n#line 1 \"ds/kdtree/kdtree.hpp\"\ntemplate <typename\
    \ XY>\nstruct KDTree {\n  // \u5C0F\u6570\u3082\u8003\u616E\u3059\u308B\u3068\u3001\
    \u9589\u3067\u6301\u3064\u8A2D\u8A08\u65B9\u91DD\u306B\u306A\u308B\u3002\u305F\
    \u3060\u3057\u3001\u30AF\u30A8\u30EA\u306F\u3044\u3064\u3082\u306E\u534A\u958B\
    \u3092\u4F7F\u3046\n  vc<tuple<XY, XY, XY, XY>> closed_range;\n  // \u540C\u3058\
    \u5EA7\u6A19\u306E\u70B9\u3082\u96C6\u7D04\u3057\u306A\u3044\u3088\u3046\u306B\
    \u3057\u3066\u3001\u5EA7\u6A19\u3054\u3068\u306B unique \u306A\u30C7\u30FC\u30BF\
    \u3092\u4F7F\u3046\n  vc<int> dat;\n  int n;\n\n  KDTree(vc<XY> xs, vc<XY> ys)\
    \ : n(len(xs)) {\n    int log = 0;\n    while ((1 << log) < n) ++log;\n    dat.assign(1\
    \ << (log + 1), -1);\n    closed_range.resize(1 << (log + 1));\n    vc<int> vs(n);\n\
    \    iota(all(vs), 0);\n    if (n > 0) build(1, xs, ys, vs);\n  }\n\n  // [xl,\
    \ xr) x [yl, yr)\n  vc<int> collect_rect(XY xl, XY xr, XY yl, XY yr, int max_size\
    \ = -1) {\n    assert(xl <= xr && yl <= yr);\n    if (max_size == -1) max_size\
    \ = n;\n    vc<int> res;\n    rect_rec(1, xl, xr, yl, yr, res, max_size);\n  \
    \  return res;\n  }\n\n  // \u8A08\u7B97\u91CF\u4FDD\u8A3C\u306A\u3057\u3001\u70B9\
    \u7FA4\u304C\u30E9\u30F3\u30C0\u30E0\u306A\u3089 O(logN)\n  // N = Q = 10^5 \u3067\
    \u3001\u7D04 1 \u79D2\n  // T \u306F\u5EA7\u6A19\u306E 2 \u4E57\u304C\u30AA\u30FC\
    \u30D0\u30FC\u30D5\u30ED\u30FC\u3057\u306A\u3044\u3082\u306E\u3092\u4F7F\u3046\
    \u3002XY=int, T=long \u306A\u3069\u3002\n  // return \u3059\u308B\u306E\u306F\
    \ index\n  template <typename T>\n  int nearest_neighbor_search(XY x, XY y) {\n\
    \    if (n == 0) return -1;\n    pair<int, T> res = {-1, -1};\n    nns_rec(1,\
    \ x, y, res);\n    return res.fi;\n  }\n\nprivate:\n  void build(int idx, vc<XY>\
    \ xs, vc<XY> ys, vc<int> vs, bool divx = true) {\n    int n = len(xs);\n    auto&\
    \ [xmin, xmax, ymin, ymax] = closed_range[idx];\n    xmin = ymin = infty<XY>;\n\
    \    xmax = ymax = -infty<XY>;\n\n    FOR(i, n) {\n      auto x = xs[i], y = ys[i];\n\
    \      chmin(xmin, x), chmax(xmax, x), chmin(ymin, y), chmax(ymax, y);\n    }\n\
    \    if (n == 1) {\n      dat[idx] = vs[0];\n      return;\n    }\n\n    int m\
    \ = n / 2;\n    vc<int> I(n);\n    iota(all(I), 0);\n    if (divx) {\n      nth_element(I.begin(),\
    \ I.begin() + m, I.end(), [xs](int i, int j) { return xs[i] < xs[j]; });\n   \
    \ } else {\n      nth_element(I.begin(), I.begin() + m, I.end(), [ys](int i, int\
    \ j) { return ys[i] < ys[j]; });\n    }\n    xs = rearrange(xs, I), ys = rearrange(ys,\
    \ I), vs = rearrange(vs, I);\n    build(2 * idx + 0, {xs.begin(), xs.begin() +\
    \ m}, {ys.begin(), ys.begin() + m}, {vs.begin(), vs.begin() + m}, !divx);\n  \
    \  build(2 * idx + 1, {xs.begin() + m, xs.end()}, {ys.begin() + m, ys.end()},\
    \ {vs.begin() + m, vs.end()}, !divx);\n  }\n\n  void rect_rec(int i, XY x1, XY\
    \ x2, XY y1, XY y2, vc<int>& res, int ms) {\n    if (len(res) == ms) return;\n\
    \    auto& [xmin, xmax, ymin, ymax] = closed_range[i];\n    if (x2 <= xmin ||\
    \ xmax < x1) return;\n    if (y2 <= ymin || ymax < y1) return;\n    if (dat[i]\
    \ != -1) {\n      res.eb(dat[i]);\n      return;\n    }\n    rect_rec(2 * i +\
    \ 0, x1, x2, y1, y2, res, ms);\n    rect_rec(2 * i + 1, x1, x2, y1, y2, res, ms);\n\
    \  }\n\n  template <typename T>\n  T best_dist_squared(int i, XY x, XY y) {\n\
    \    auto& [xmin, xmax, ymin, ymax] = closed_range[i];\n    T dx = x - clamp(x,\
    \ xmin, xmax);\n    T dy = y - clamp(y, ymin, ymax);\n    return dx * dx + dy\
    \ * dy;\n  }\n\n  template <typename T>\n  void nns_rec(int i, XY x, XY y, pair<int,\
    \ T>& res) {\n    T d = best_dist_squared<T>(i, x, y);\n    if (res.fi != -1 &&\
    \ d >= res.se) return;\n    if (dat[i] != -1) {\n      res = {dat[i], d};\n  \
    \    return;\n    }\n    T d0 = best_dist_squared<T>(2 * i + 0, x, y);\n    T\
    \ d1 = best_dist_squared<T>(2 * i + 1, x, y);\n    if (d0 < d1) {\n      nns_rec(2\
    \ * i + 0, x, y, res), nns_rec(2 * i + 1, x, y, res);\n    } else {\n      nns_rec(2\
    \ * i + 1, x, y, res), nns_rec(2 * i + 0, x, y, res);\n    }\n  }\n};\n#line 7\
    \ \"test/1_mytest/kdtree_nns.test.cpp\"\n\nvoid test_random_points_nns_is_fast()\
    \ {\n  ll N = 100'000, Q = 100'000;\n  vc<int> X(N), Y(N);\n  ll LIM = 1'000'000'000;\n\
    \  FOR(i, N) X[i] = RNG(0, LIM);\n  FOR(i, N) Y[i] = RNG(0, LIM);\n  KDTree<int>\
    \ KDT(X, Y);\n  FOR(Q) {\n    ll x = RNG(0, LIM);\n    ll y = RNG(0, LIM);\n \
    \   KDT.nearest_neighbor_search<ll>(x, y);\n  }\n}\n\nvoid test_nns_is_correct()\
    \ {\n  ll LIM = RNG(10, 1000);\n  ll N = RNG(1, 100);\n  ll Q = 1000;\n  vc<int>\
    \ X(N), Y(N);\n  FOR(i, N) X[i] = RNG(0, LIM);\n  FOR(i, N) Y[i] = RNG(0, LIM);\n\
    \n  KDTree<int> KDT(X, Y);\n  FOR(Q) {\n    ll x = RNG(0, LIM);\n    ll y = RNG(0,\
    \ LIM);\n    ll min_d = 1'000'000'000;\n    auto dist = [&](int i) -> ll {\n \
    \     ll dx = X[i] - x, dy = Y[i] - y;\n      return dx * dx + dy * dy;\n    };\n\
    \    FOR(i, N) chmin(min_d, dist(i));\n    int k = KDT.nearest_neighbor_search<ll>(x,\
    \ y);\n    assert(min_d == dist(k));\n  }\n}\n\nvoid test() {\n  test_random_points_nns_is_fast();\n\
    \  test_nns_is_correct();\n}\n\nvoid solve() {\n  int a, b;\n  cin >> a >> b;\n\
    \  cout << a + b << \"\\n\";\n}\n\nsigned main() {\n  test();\n  solve();\n\n\
    \  return 0;\n}\n"
  code: "#define PROBLEM \"https://judge.yosupo.jp/problem/aplusb\"\n\n#include \"\
    my_template.hpp\"\n\n#include \"random/base.hpp\"\n#include \"ds/kdtree/kdtree.hpp\"\
    \n\nvoid test_random_points_nns_is_fast() {\n  ll N = 100'000, Q = 100'000;\n\
    \  vc<int> X(N), Y(N);\n  ll LIM = 1'000'000'000;\n  FOR(i, N) X[i] = RNG(0, LIM);\n\
    \  FOR(i, N) Y[i] = RNG(0, LIM);\n  KDTree<int> KDT(X, Y);\n  FOR(Q) {\n    ll\
    \ x = RNG(0, LIM);\n    ll y = RNG(0, LIM);\n    KDT.nearest_neighbor_search<ll>(x,\
    \ y);\n  }\n}\n\nvoid test_nns_is_correct() {\n  ll LIM = RNG(10, 1000);\n  ll\
    \ N = RNG(1, 100);\n  ll Q = 1000;\n  vc<int> X(N), Y(N);\n  FOR(i, N) X[i] =\
    \ RNG(0, LIM);\n  FOR(i, N) Y[i] = RNG(0, LIM);\n\n  KDTree<int> KDT(X, Y);\n\
    \  FOR(Q) {\n    ll x = RNG(0, LIM);\n    ll y = RNG(0, LIM);\n    ll min_d =\
    \ 1'000'000'000;\n    auto dist = [&](int i) -> ll {\n      ll dx = X[i] - x,\
    \ dy = Y[i] - y;\n      return dx * dx + dy * dy;\n    };\n    FOR(i, N) chmin(min_d,\
    \ dist(i));\n    int k = KDT.nearest_neighbor_search<ll>(x, y);\n    assert(min_d\
    \ == dist(k));\n  }\n}\n\nvoid test() {\n  test_random_points_nns_is_fast();\n\
    \  test_nns_is_correct();\n}\n\nvoid solve() {\n  int a, b;\n  cin >> a >> b;\n\
    \  cout << a + b << \"\\n\";\n}\n\nsigned main() {\n  test();\n  solve();\n\n\
    \  return 0;\n}\n"
  dependsOn:
  - my_template.hpp
  - random/base.hpp
  - ds/kdtree/kdtree.hpp
  isVerificationFile: true
  path: test/1_mytest/kdtree_nns.test.cpp
  requiredBy: []
  timestamp: '2024-10-18 02:58:53+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: test/1_mytest/kdtree_nns.test.cpp
layout: document
redirect_from:
- /verify/test/1_mytest/kdtree_nns.test.cpp
- /verify/test/1_mytest/kdtree_nns.test.cpp.html
title: test/1_mytest/kdtree_nns.test.cpp
---
