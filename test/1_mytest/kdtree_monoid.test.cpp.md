---
data:
  _extendedDependsOn:
  - icon: ':question:'
    path: alg/monoid/summax.hpp
    title: alg/monoid/summax.hpp
  - icon: ':question:'
    path: ds/kdtree/kdtree_monoid.hpp
    title: ds/kdtree/kdtree_monoid.hpp
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
  bundledCode: "#line 1 \"test/1_mytest/kdtree_monoid.test.cpp\"\n#define PROBLEM\
    \ \"https://judge.yosupo.jp/problem/aplusb\"\n#line 1 \"my_template.hpp\"\n#if\
    \ defined(LOCAL)\n#include <my_template_compiled.hpp>\n#else\n\n// https://codeforces.com/blog/entry/96344\n\
    #pragma GCC optimize(\"Ofast,unroll-loops\")\n// \u3044\u307E\u306E CF \u3060\u3068\
    \u3053\u308C\u5165\u308C\u308B\u3068\u52D5\u304B\u306A\u3044\uFF1F\n// #pragma\
    \ GCC target(\"avx2,popcnt\")\n\n#include <bits/stdc++.h>\n\nusing namespace std;\n\
    \nusing ll = long long;\nusing u32 = unsigned int;\nusing u64 = unsigned long\
    \ long;\nusing i128 = __int128;\nusing u128 = unsigned __int128;\nusing f128 =\
    \ __float128;\n\ntemplate <class T>\nconstexpr T infty = 0;\ntemplate <>\nconstexpr\
    \ int infty<int> = 1'010'000'000;\ntemplate <>\nconstexpr ll infty<ll> = 2'020'000'000'000'000'000;\n\
    template <>\nconstexpr u32 infty<u32> = infty<int>;\ntemplate <>\nconstexpr u64\
    \ infty<u64> = infty<ll>;\ntemplate <>\nconstexpr i128 infty<i128> = i128(infty<ll>)\
    \ * 2'000'000'000'000'000'000;\ntemplate <>\nconstexpr double infty<double> =\
    \ infty<ll>;\ntemplate <>\nconstexpr long double infty<long double> = infty<ll>;\n\
    \nusing pi = pair<ll, ll>;\nusing vi = vector<ll>;\ntemplate <class T>\nusing\
    \ vc = vector<T>;\ntemplate <class T>\nusing vvc = vector<vc<T>>;\ntemplate <class\
    \ T>\nusing vvvc = vector<vvc<T>>;\ntemplate <class T>\nusing vvvvc = vector<vvvc<T>>;\n\
    template <class T>\nusing vvvvvc = vector<vvvvc<T>>;\ntemplate <class T>\nusing\
    \ pq = priority_queue<T>;\ntemplate <class T>\nusing pqg = priority_queue<T, vector<T>,\
    \ greater<T>>;\n\n#define vv(type, name, h, ...) vector<vector<type>> name(h,\
    \ vector<type>(__VA_ARGS__))\n#define vvv(type, name, h, w, ...) vector<vector<vector<type>>>\
    \ name(h, vector<vector<type>>(w, vector<type>(__VA_ARGS__)))\n#define vvvv(type,\
    \ name, a, b, c, ...) \\\n  vector<vector<vector<vector<type>>>> name(a, vector<vector<vector<type>>>(b,\
    \ vector<vector<type>>(c, vector<type>(__VA_ARGS__))))\n\n// https://trap.jp/post/1224/\n\
    #define FOR1(a) for (ll _ = 0; _ < ll(a); ++_)\n#define FOR2(i, a) for (ll i =\
    \ 0; i < ll(a); ++i)\n#define FOR3(i, a, b) for (ll i = a; i < ll(b); ++i)\n#define\
    \ FOR4(i, a, b, c) for (ll i = a; i < ll(b); i += (c))\n#define FOR1_R(a) for\
    \ (ll i = (a)-1; i >= ll(0); --i)\n#define FOR2_R(i, a) for (ll i = (a)-1; i >=\
    \ ll(0); --i)\n#define FOR3_R(i, a, b) for (ll i = (b)-1; i >= ll(a); --i)\n#define\
    \ overload4(a, b, c, d, e, ...) e\n#define overload3(a, b, c, d, ...) d\n#define\
    \ FOR(...) overload4(__VA_ARGS__, FOR4, FOR3, FOR2, FOR1)(__VA_ARGS__)\n#define\
    \ FOR_R(...) overload3(__VA_ARGS__, FOR3_R, FOR2_R, FOR1_R)(__VA_ARGS__)\n\n#define\
    \ FOR_subset(t, s) for (ll t = (s); t >= 0; t = (t == 0 ? -1 : (t - 1) & (s)))\n\
    #define all(x) x.begin(), x.end()\n#define len(x) ll(x.size())\n#define elif else\
    \ if\n\n#define eb emplace_back\n#define mp make_pair\n#define mt make_tuple\n\
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
    \ others.end()), ...);\n}\n#endif\n#line 3 \"test/1_mytest/kdtree_monoid.test.cpp\"\
    \n\n#line 1 \"ds/kdtree/kdtree_monoid.hpp\"\ntemplate <class Monoid, typename\
    \ XY>\r\nstruct KDTree_Monoid {\r\n  using MX = Monoid;\r\n  using X = typename\
    \ MX::value_type;\r\n  static_assert(MX::commute);\r\n\r\n  // \u5C0F\u6570\u3082\
    \u8003\u616E\u3059\u308B\u3068\u3001\u9589\u3067\u6301\u3064\u8A2D\u8A08\u65B9\
    \u91DD\u306B\u306A\u308B\u3002\u305F\u3060\u3057\u3001\u30AF\u30A8\u30EA\u306F\
    \u3044\u3064\u3082\u306E\u534A\u958B\u3092\u4F7F\u3046\r\n  vc<tuple<XY, XY, XY,\
    \ XY>> closed_range;\r\n  vc<X> dat;\r\n  int n;\r\n\r\n  KDTree_Monoid(vc<XY>\
    \ xs, vc<XY> ys, vc<X> vs) : n(len(xs)) {\r\n    assert(n > 0);\r\n    int log\
    \ = 0;\r\n    while ((1 << log) < n) ++log;\r\n    dat.resize(1 << (log + 1));\r\
    \n    closed_range.resize(1 << (log + 1));\r\n    build(1, xs, ys, vs);\r\n  }\r\
    \n\r\n  void multiply(XY x, XY y, const X& v) { multiply_rec(1, x, y, v); }\r\n\
    \r\n  // [xl, xr) x [yl, yr)\r\n  X prod(XY xl, XY xr, XY yl, XY yr) {\r\n   \
    \ assert(xl <= xr && yl <= yr);\r\n    return prod_rec(1, xl, xr, yl, yr);\r\n\
    \  }\r\n\r\n  X prod_all() { return dat[1]; }\r\n\r\nprivate:\r\n  void build(int\
    \ idx, vc<XY> xs, vc<XY> ys, vc<X> vs, bool divx = true) {\r\n    int n = len(xs);\r\
    \n    auto& [xmin, xmax, ymin, ymax] = closed_range[idx];\r\n    xmin = ymin =\
    \ infty<XY>;\r\n    xmax = ymax = -infty<XY>;\r\n\r\n    FOR(i, n) {\r\n     \
    \ auto x = xs[i], y = ys[i];\r\n      chmin(xmin, x), chmax(xmax, x), chmin(ymin,\
    \ y), chmax(ymax, y);\r\n    }\r\n    if (xmin == xmax && ymin == ymax) {\r\n\
    \      X x = MX::unit();\r\n      for (auto&& v: vs) x = MX::op(x, v);\r\n   \
    \   dat[idx] = x;\r\n      return;\r\n    }\r\n\r\n    int m = n / 2;\r\n    vc<int>\
    \ I(n);\r\n    iota(all(I), 0);\r\n    if (divx) {\r\n      nth_element(I.begin(),\
    \ I.begin() + m, I.end(),\r\n                  [xs](int i, int j) { return xs[i]\
    \ < xs[j]; });\r\n    } else {\r\n      nth_element(I.begin(), I.begin() + m,\
    \ I.end(),\r\n                  [ys](int i, int j) { return ys[i] < ys[j]; });\r\
    \n    }\r\n    xs = rearrange(xs, I), ys = rearrange(ys, I), vs = rearrange(vs,\
    \ I);\r\n    build(2 * idx + 0, {xs.begin(), xs.begin() + m},\r\n          {ys.begin(),\
    \ ys.begin() + m}, {vs.begin(), vs.begin() + m}, !divx);\r\n    build(2 * idx\
    \ + 1, {xs.begin() + m, xs.end()}, {ys.begin() + m, ys.end()},\r\n          {vs.begin()\
    \ + m, vs.end()}, !divx);\r\n    dat[idx] = MX::op(dat[2 * idx + 0], dat[2 * idx\
    \ + 1]);\r\n  }\r\n\r\n  inline bool is_leaf(int idx) {\r\n    auto& [xmin, xmax,\
    \ ymin, ymax] = closed_range[idx];\r\n    return xmin == xmax && ymin == ymax;\r\
    \n  }\r\n\r\n  inline bool isin(XY x, XY y, int idx) {\r\n    auto& [xmin, xmax,\
    \ ymin, ymax] = closed_range[idx];\r\n    return (xmin <= x && x <= xmax && ymin\
    \ <= y && y <= ymax);\r\n  }\r\n\r\n  bool multiply_rec(int idx, XY x, XY y, X\
    \ v) {\r\n    if (!isin(x, y, idx)) return false;\r\n    if (is_leaf(idx)) {\r\
    \n      dat[idx] = MX::op(dat[idx], v);\r\n      return true;\r\n    }\r\n   \
    \ bool done = 0;\r\n    if (multiply_rec(2 * idx + 0, x, y, v)) done = 1;\r\n\
    \    if (!done && multiply_rec(2 * idx + 1, x, y, v)) done = 1;\r\n    if (done)\
    \ { dat[idx] = MX::op(dat[2 * idx + 0], dat[2 * idx + 1]); }\r\n    return done;\r\
    \n  }\r\n\r\n  X prod_rec(int idx, XY x1, XY x2, XY y1, XY y2) {\r\n    auto&\
    \ [xmin, xmax, ymin, ymax] = closed_range[idx];\r\n    if (x2 <= xmin || xmax\
    \ < x1) return MX::unit();\r\n    if (y2 <= ymin || ymax < y1) return MX::unit();\r\
    \n    if (x1 <= xmin && xmax < x2 && y1 <= ymin && ymax < y2) { return dat[idx];\
    \ }\r\n    return MX::op(prod_rec(2 * idx + 0, x1, x2, y1, y2),\r\n          \
    \        prod_rec(2 * idx + 1, x1, x2, y1, y2));\r\n  }\r\n};\r\n#line 2 \"alg/monoid/summax.hpp\"\
    \n\ntemplate <typename E>\nstruct Monoid_SumMax {\n  using value_type = pair<E,\
    \ E>;\n  using X = value_type;\n  static X op(X x, X y) { return {x.fi + y.fi,\
    \ max(x.se, y.se)}; }\n  static X from_element(E e) { return {e, e}; }\n  static\
    \ constexpr X unit() { return {E(0), -infty<E>}; }\n  static constexpr bool commute\
    \ = 1;\n};\n#line 2 \"random/base.hpp\"\n\nu64 RNG_64() {\n  static uint64_t x_\n\
    \      = uint64_t(chrono::duration_cast<chrono::nanoseconds>(chrono::high_resolution_clock::now().time_since_epoch()).count())\
    \ * 10150724397891781847ULL;\n  x_ ^= x_ << 7;\n  return x_ ^= x_ >> 9;\n}\n\n\
    u64 RNG(u64 lim) { return RNG_64() % lim; }\n\nll RNG(ll l, ll r) { return l +\
    \ RNG_64() % (r - l); }\n#line 7 \"test/1_mytest/kdtree_monoid.test.cpp\"\n\n\
    void test() {\n  ll LIM = RNG(1, 100);\n  int N = RNG(1, 100);\n  using MX = Monoid_SumMax<int>;\n\
    \n  vc<int> dat[100][100];\n\n  vc<int> X, Y;\n  vc<typename MX::value_type> val;\n\
    \  FOR(i, N) {\n    int x = RNG(0, LIM);\n    int y = RNG(0, LIM);\n    int v\
    \ = RNG(0, 100);\n    dat[x][y].eb(v);\n    X.eb(x), Y.eb(y), val.eb(v, v);\n\
    \  }\n  KDTree_Monoid<MX, int> KDT(X, Y, val);\n\n  int Q = 100;\n  FOR(Q) {\n\
    \    int t = RNG(0, 3);\n    int xl = RNG(0, LIM), xr = RNG(0, LIM), yl = RNG(0,\
    \ LIM), yr = RNG(0, LIM);\n    if (xl > xr) swap(xl, xr);\n    if (yl > yr) swap(yl,\
    \ yr);\n    if (t == 0) {\n      // multiply\n      int k = RNG(0, N);\n     \
    \ int x = X[k], y = Y[k];\n      int v = RNG(0, 100);\n      dat[x][y].eb(v);\n\
    \      KDT.multiply(x, y, {v, v});\n    }\n    if (t == 1) {\n      // prod\n\
    \      int sm = 0, mx = MX::unit().se;\n      FOR(i, xl, xr) FOR(j, yl, yr) {\n\
    \        for (auto&& x: dat[i][j]) sm += x, chmax(mx, x);\n      }\n      auto\
    \ res = KDT.prod(xl, xr, yl, yr);\n      assert(res.fi == sm && res.se == mx);\n\
    \    }\n    if (t == 2) {\n      // prod all\n      int sm = 0, mx = MX::unit().se;\n\
    \      FOR(i, LIM) FOR(j, LIM) {\n        for (auto&& x: dat[i][j]) sm += x, chmax(mx,\
    \ x);\n      }\n      auto res = KDT.prod_all();\n      assert(res.fi == sm &&\
    \ res.se == mx);\n    }\n  }\n}\n\nvoid solve() {\n  int a, b;\n  cin >> a >>\
    \ b;\n  cout << a + b << \"\\n\";\n}\n\nsigned main() {\n  FOR(100) test();\n\
    \  solve();\n\n  return 0;\n}\n"
  code: "#define PROBLEM \"https://judge.yosupo.jp/problem/aplusb\"\n#include \"my_template.hpp\"\
    \n\n#include \"ds/kdtree/kdtree_monoid.hpp\"\n#include \"alg/monoid/summax.hpp\"\
    \n#include \"random/base.hpp\"\n\nvoid test() {\n  ll LIM = RNG(1, 100);\n  int\
    \ N = RNG(1, 100);\n  using MX = Monoid_SumMax<int>;\n\n  vc<int> dat[100][100];\n\
    \n  vc<int> X, Y;\n  vc<typename MX::value_type> val;\n  FOR(i, N) {\n    int\
    \ x = RNG(0, LIM);\n    int y = RNG(0, LIM);\n    int v = RNG(0, 100);\n    dat[x][y].eb(v);\n\
    \    X.eb(x), Y.eb(y), val.eb(v, v);\n  }\n  KDTree_Monoid<MX, int> KDT(X, Y,\
    \ val);\n\n  int Q = 100;\n  FOR(Q) {\n    int t = RNG(0, 3);\n    int xl = RNG(0,\
    \ LIM), xr = RNG(0, LIM), yl = RNG(0, LIM), yr = RNG(0, LIM);\n    if (xl > xr)\
    \ swap(xl, xr);\n    if (yl > yr) swap(yl, yr);\n    if (t == 0) {\n      // multiply\n\
    \      int k = RNG(0, N);\n      int x = X[k], y = Y[k];\n      int v = RNG(0,\
    \ 100);\n      dat[x][y].eb(v);\n      KDT.multiply(x, y, {v, v});\n    }\n  \
    \  if (t == 1) {\n      // prod\n      int sm = 0, mx = MX::unit().se;\n     \
    \ FOR(i, xl, xr) FOR(j, yl, yr) {\n        for (auto&& x: dat[i][j]) sm += x,\
    \ chmax(mx, x);\n      }\n      auto res = KDT.prod(xl, xr, yl, yr);\n      assert(res.fi\
    \ == sm && res.se == mx);\n    }\n    if (t == 2) {\n      // prod all\n     \
    \ int sm = 0, mx = MX::unit().se;\n      FOR(i, LIM) FOR(j, LIM) {\n        for\
    \ (auto&& x: dat[i][j]) sm += x, chmax(mx, x);\n      }\n      auto res = KDT.prod_all();\n\
    \      assert(res.fi == sm && res.se == mx);\n    }\n  }\n}\n\nvoid solve() {\n\
    \  int a, b;\n  cin >> a >> b;\n  cout << a + b << \"\\n\";\n}\n\nsigned main()\
    \ {\n  FOR(100) test();\n  solve();\n\n  return 0;\n}\n"
  dependsOn:
  - my_template.hpp
  - ds/kdtree/kdtree_monoid.hpp
  - alg/monoid/summax.hpp
  - random/base.hpp
  isVerificationFile: true
  path: test/1_mytest/kdtree_monoid.test.cpp
  requiredBy: []
  timestamp: '2024-09-14 09:20:23+09:00'
  verificationStatus: TEST_WRONG_ANSWER
  verifiedWith: []
documentation_of: test/1_mytest/kdtree_monoid.test.cpp
layout: document
redirect_from:
- /verify/test/1_mytest/kdtree_monoid.test.cpp
- /verify/test/1_mytest/kdtree_monoid.test.cpp.html
title: test/1_mytest/kdtree_monoid.test.cpp
---
