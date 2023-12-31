---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: alg/acted_monoid/summax_add.hpp
    title: alg/acted_monoid/summax_add.hpp
  - icon: ':heavy_check_mark:'
    path: alg/monoid/add.hpp
    title: alg/monoid/add.hpp
  - icon: ':heavy_check_mark:'
    path: alg/monoid/summax.hpp
    title: alg/monoid/summax.hpp
  - icon: ':heavy_check_mark:'
    path: ds/kdtree/kdtree_acted_monoid.hpp
    title: ds/kdtree/kdtree_acted_monoid.hpp
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
  bundledCode: "#line 1 \"test/mytest/kdtree_am.test.cpp\"\n#define PROBLEM \"https://judge.yosupo.jp/problem/aplusb\"\
    \n#line 1 \"my_template.hpp\"\n#if defined(LOCAL)\n#include <my_template_compiled.hpp>\n\
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
    \  return B;\n}\n#endif\n#line 3 \"test/mytest/kdtree_am.test.cpp\"\n\n#line 1\
    \ \"ds/kdtree/kdtree_acted_monoid.hpp\"\ntemplate <class ActedMonoid, typename\
    \ XY>\r\nstruct KDTree_ActedMonoid {\r\n  using AM = ActedMonoid;\r\n  using MX\
    \ = typename AM::Monoid_X;\r\n  using MA = typename AM::Monoid_A;\r\n  using X\
    \ = typename AM::X;\r\n  using A = typename AM::A;\r\n  static_assert(MX::commute);\r\
    \n\r\n  // \u5C0F\u6570\u3082\u8003\u616E\u3059\u308B\u3068\u3001\u9589\u3067\u6301\
    \u3064\u8A2D\u8A08\u65B9\u91DD\u306B\u306A\u308B\u3002\u305F\u3060\u3057\u3001\
    \u30AF\u30A8\u30EA\u306F\u3044\u3064\u3082\u306E\u534A\u958B\u3092\u4F7F\u3046\
    \r\n  vc<tuple<XY, XY, XY, XY>> closed_range;\r\n  vc<X> dat;\r\n  vc<A> lazy;\r\
    \n  vc<int> size;\r\n  int n;\r\n\r\n  KDTree_ActedMonoid(vc<XY> xs, vc<XY> ys,\
    \ vc<X> vs) : n(len(xs)) {\r\n    assert(n > 0);\r\n    int log = 0;\r\n    while\
    \ ((1 << log) < n) ++log;\r\n    dat.resize(1 << (log + 1));\r\n    lazy.assign(1\
    \ << log, MA::unit());\r\n    closed_range.resize(1 << (log + 1));\r\n    size.resize(1\
    \ << (log + 1));\r\n    build(1, xs, ys, vs);\r\n  }\r\n\r\n  void multiply(XY\
    \ x, XY y, const X& v) { multiply_rec(1, x, y, v); }\r\n\r\n  // [xl, xr) x [yl,\
    \ yr)\r\n  X prod(XY xl, XY xr, XY yl, XY yr) {\r\n    assert(xl <= xr && yl <=\
    \ yr);\r\n    return prod_rec(1, xl, xr, yl, yr);\r\n  }\r\n\r\n  X prod_all()\
    \ { return dat[1]; }\r\n\r\n  // [xl, xr) x [yl, yr)\r\n  void apply(XY xl, XY\
    \ xr, XY yl, XY yr, A a) {\r\n    assert(xl <= xr && yl <= yr);\r\n    return\
    \ apply_rec(1, xl, xr, yl, yr, a);\r\n  }\r\n\r\nprivate:\r\n  void build(int\
    \ idx, vc<XY> xs, vc<XY> ys, vc<X> vs, bool divx = true) {\r\n    int n = len(xs);\r\
    \n    size[idx] = n;\r\n    auto& [xmin, xmax, ymin, ymax] = closed_range[idx];\r\
    \n    xmin = ymin = infty<XY>;\r\n    xmax = ymax = -infty<XY>;\r\n\r\n    FOR(i,\
    \ n) {\r\n      auto x = xs[i], y = ys[i];\r\n      chmin(xmin, x), chmax(xmax,\
    \ x), chmin(ymin, y), chmax(ymax, y);\r\n    }\r\n    if (xmin == xmax && ymin\
    \ == ymax) {\r\n      X x = MX::unit();\r\n      for (auto&& v: vs) x = MX::op(x,\
    \ v);\r\n      dat[idx] = x;\r\n      return;\r\n    }\r\n\r\n    int m = n /\
    \ 2;\r\n    vc<int> I(n);\r\n    iota(all(I), 0);\r\n    if (divx) {\r\n     \
    \ nth_element(I.begin(), I.begin() + m, I.end(),\r\n                  [xs](int\
    \ i, int j) { return xs[i] < xs[j]; });\r\n    } else {\r\n      nth_element(I.begin(),\
    \ I.begin() + m, I.end(),\r\n                  [ys](int i, int j) { return ys[i]\
    \ < ys[j]; });\r\n    }\r\n    xs = rearrange(xs, I), ys = rearrange(ys, I), vs\
    \ = rearrange(vs, I);\r\n    build(2 * idx + 0, {xs.begin(), xs.begin() + m},\r\
    \n          {ys.begin(), ys.begin() + m}, {vs.begin(), vs.begin() + m}, !divx);\r\
    \n    build(2 * idx + 1, {xs.begin() + m, xs.end()}, {ys.begin() + m, ys.end()},\r\
    \n          {vs.begin() + m, vs.end()}, !divx);\r\n    dat[idx] = MX::op(dat[2\
    \ * idx + 0], dat[2 * idx + 1]);\r\n  }\r\n\r\n  inline bool is_leaf(int idx)\
    \ {\r\n    auto& [xmin, xmax, ymin, ymax] = closed_range[idx];\r\n    return xmin\
    \ == xmax && ymin == ymax;\r\n  }\r\n\r\n  inline bool isin(XY x, XY y, int idx)\
    \ {\r\n    auto& [xmin, xmax, ymin, ymax] = closed_range[idx];\r\n    return (xmin\
    \ <= x && x <= xmax && ymin <= y && y <= ymax);\r\n  }\r\n\r\n  void apply_at(int\
    \ idx, A a) {\r\n    dat[idx] = AM::act(dat[idx], a, size[idx]);\r\n    if (!is_leaf(idx))\
    \ lazy[idx] = MA::op(lazy[idx], a);\r\n  }\r\n\r\n  void push(int idx) {\r\n \
    \   if (lazy[idx] == MA::unit()) return;\r\n    apply_at(2 * idx + 0, lazy[idx]),\
    \ apply_at(2 * idx + 1, lazy[idx]);\r\n    lazy[idx] = MA::unit();\r\n  }\r\n\r\
    \n  bool multiply_rec(int idx, XY x, XY y, X v) {\r\n    if (!isin(x, y, idx))\
    \ return false;\r\n    if (is_leaf(idx)) {\r\n      dat[idx] = MX::op(dat[idx],\
    \ v);\r\n      size[idx] += 1;\r\n      return true;\r\n    }\r\n    push(idx);\r\
    \n    bool done = 0;\r\n    if (multiply_rec(2 * idx + 0, x, y, v)) done = 1;\r\
    \n    if (!done && multiply_rec(2 * idx + 1, x, y, v)) done = 1;\r\n    if (done)\
    \ {\r\n      dat[idx] = MX::op(dat[2 * idx + 0], dat[2 * idx + 1]);\r\n      size[idx]\
    \ = size[2 * idx + 0] + size[2 * idx + 1];\r\n    }\r\n    return done;\r\n  }\r\
    \n\r\n  X prod_rec(int idx, XY x1, XY x2, XY y1, XY y2) {\r\n    auto& [xmin,\
    \ xmax, ymin, ymax] = closed_range[idx];\r\n    if (x2 <= xmin || xmax < x1) return\
    \ MX::unit();\r\n    if (y2 <= ymin || ymax < y1) return MX::unit();\r\n    if\
    \ (x1 <= xmin && xmax < x2 && y1 <= ymin && ymax < y2) { return dat[idx]; }\r\n\
    \    push(idx);\r\n    return MX::op(prod_rec(2 * idx + 0, x1, x2, y1, y2),\r\n\
    \                  prod_rec(2 * idx + 1, x1, x2, y1, y2));\r\n  }\r\n\r\n  void\
    \ apply_rec(int idx, XY x1, XY x2, XY y1, XY y2, A a) {\r\n    auto& [xmin, xmax,\
    \ ymin, ymax] = closed_range[idx];\r\n    if (x2 <= xmin || xmax < x1) return;\r\
    \n    if (y2 <= ymin || ymax < y1) return;\r\n    if (x1 <= xmin && xmax < x2\
    \ && y1 <= ymin && ymax < y2) {\r\n      return apply_at(idx, a);\r\n    }\r\n\
    \    push(idx);\r\n    apply_rec(2 * idx + 0, x1, x2, y1, y2, a);\r\n    apply_rec(2\
    \ * idx + 1, x1, x2, y1, y2, a);\r\n    dat[idx] = MX::op(dat[2 * idx + 0], dat[2\
    \ * idx + 1]);\r\n  }\r\n};\r\n#line 2 \"alg/monoid/summax.hpp\"\n\ntemplate <typename\
    \ E>\nstruct Monoid_SumMax {\n  using value_type = pair<E, E>;\n  using X = value_type;\n\
    \  static X op(X x, X y) { return {x.fi + y.fi, max(x.se, y.se)}; }\n  static\
    \ X from_element(E e) { return {e, e}; }\n  static constexpr X unit() { return\
    \ {E(0), -infty<E>}; }\n  static constexpr bool commute = 1;\n};\n#line 2 \"alg/monoid/add.hpp\"\
    \n\r\ntemplate <typename X>\r\nstruct Monoid_Add {\r\n  using value_type = X;\r\
    \n  static constexpr X op(const X &x, const X &y) noexcept { return x + y; }\r\
    \n  static constexpr X inverse(const X &x) noexcept { return -x; }\r\n  static\
    \ constexpr X power(const X &x, ll n) noexcept { return X(n) * x; }\r\n  static\
    \ constexpr X unit() { return X(0); }\r\n  static constexpr bool commute = true;\r\
    \n};\r\n#line 3 \"alg/acted_monoid/summax_add.hpp\"\n\ntemplate <typename E>\n\
    struct ActedMonoid_SumMax_Add {\n  using Monoid_X = Monoid_SumMax<E>;\n  using\
    \ Monoid_A = Monoid_Add<E>;\n  using X = typename Monoid_X::value_type;\n  using\
    \ A = typename Monoid_A::value_type;\n  static constexpr X act(const X& x, const\
    \ A& a, const ll& size) {\n    auto [xs, xm] = x;\n    xm = (xm == -infty<E> ?\
    \ xm : xm + a);\n    return {xs + E(size) * a, xm};\n  }\n};\n#line 2 \"random/base.hpp\"\
    \n\nu64 RNG_64() {\n  static uint64_t x_\n      = uint64_t(chrono::duration_cast<chrono::nanoseconds>(\n\
    \                     chrono::high_resolution_clock::now().time_since_epoch())\n\
    \                     .count())\n        * 10150724397891781847ULL;\n  x_ ^= x_\
    \ << 7;\n  return x_ ^= x_ >> 9;\n}\n\nu64 RNG(u64 lim) { return RNG_64() % lim;\
    \ }\n\nll RNG(ll l, ll r) { return l + RNG_64() % (r - l); }\n#line 7 \"test/mytest/kdtree_am.test.cpp\"\
    \n\nvoid test() {\n  ll LIM = RNG(1, 100);\n  int N = RNG(1, 100);\n  using AM\
    \ = ActedMonoid_SumMax_Add<int>;\n  using MX = AM::Monoid_X;\n\n  vc<int> dat[100][100];\n\
    \n  vc<int> X, Y;\n  vc<typename MX::value_type> val;\n  FOR(i, N) {\n    int\
    \ x = RNG(0, LIM);\n    int y = RNG(0, LIM);\n    int v = RNG(0, 100);\n    dat[x][y].eb(v);\n\
    \    X.eb(x), Y.eb(y), val.eb(v, v);\n  }\n  KDTree_ActedMonoid<AM, int> KDT(X,\
    \ Y, val);\n\n  int Q = 100;\n  FOR(Q) {\n    int t = RNG(0, 4);\n    int xl =\
    \ RNG(0, LIM), xr = RNG(0, LIM), yl = RNG(0, LIM), yr = RNG(0, LIM);\n    if (xl\
    \ > xr) swap(xl, xr);\n    if (yl > yr) swap(yl, yr);\n    if (t == 0) {\n   \
    \   // multiply\n      int k = RNG(0, N);\n      int x = X[k], y = Y[k];\n   \
    \   int v = RNG(0, 100);\n      dat[x][y].eb(v);\n      KDT.multiply(x, y, {v,\
    \ v});\n    }\n    if (t == 1) {\n      // prod\n      int sm = 0, mx = MX::unit().se;\n\
    \      FOR(i, xl, xr) FOR(j, yl, yr) {\n        for (auto&& x: dat[i][j]) sm +=\
    \ x, chmax(mx, x);\n      }\n      auto res = KDT.prod(xl, xr, yl, yr);\n    \
    \  assert(res.fi == sm && res.se == mx);\n    }\n    if (t == 2) {\n      // prod\
    \ all\n      int sm = 0, mx = MX::unit().se;\n      FOR(i, LIM) FOR(j, LIM) {\n\
    \        for (auto&& x: dat[i][j]) sm += x, chmax(mx, x);\n      }\n      auto\
    \ res = KDT.prod_all();\n      assert(res.fi == sm && res.se == mx);\n    }\n\
    \    if (t == 3) {\n      // apply\n      int a = RNG(0, 10);\n      FOR(i, xl,\
    \ xr) FOR(j, yl, yr) {\n        for (auto&& x: dat[i][j]) x += a;\n      }\n \
    \     KDT.apply(xl, xr, yl, yr, a);\n    }\n  }\n}\n\nvoid solve() {\n  int a,\
    \ b;\n  cin >> a >> b;\n  cout << a + b << \"\\n\";\n}\n\nsigned main() {\n  FOR(100)\
    \ test();\n  solve();\n  return 0;\n}\n"
  code: "#define PROBLEM \"https://judge.yosupo.jp/problem/aplusb\"\n#include \"my_template.hpp\"\
    \n\n#include \"ds/kdtree/kdtree_acted_monoid.hpp\"\n#include \"alg/acted_monoid/summax_add.hpp\"\
    \n#include \"random/base.hpp\"\n\nvoid test() {\n  ll LIM = RNG(1, 100);\n  int\
    \ N = RNG(1, 100);\n  using AM = ActedMonoid_SumMax_Add<int>;\n  using MX = AM::Monoid_X;\n\
    \n  vc<int> dat[100][100];\n\n  vc<int> X, Y;\n  vc<typename MX::value_type> val;\n\
    \  FOR(i, N) {\n    int x = RNG(0, LIM);\n    int y = RNG(0, LIM);\n    int v\
    \ = RNG(0, 100);\n    dat[x][y].eb(v);\n    X.eb(x), Y.eb(y), val.eb(v, v);\n\
    \  }\n  KDTree_ActedMonoid<AM, int> KDT(X, Y, val);\n\n  int Q = 100;\n  FOR(Q)\
    \ {\n    int t = RNG(0, 4);\n    int xl = RNG(0, LIM), xr = RNG(0, LIM), yl =\
    \ RNG(0, LIM), yr = RNG(0, LIM);\n    if (xl > xr) swap(xl, xr);\n    if (yl >\
    \ yr) swap(yl, yr);\n    if (t == 0) {\n      // multiply\n      int k = RNG(0,\
    \ N);\n      int x = X[k], y = Y[k];\n      int v = RNG(0, 100);\n      dat[x][y].eb(v);\n\
    \      KDT.multiply(x, y, {v, v});\n    }\n    if (t == 1) {\n      // prod\n\
    \      int sm = 0, mx = MX::unit().se;\n      FOR(i, xl, xr) FOR(j, yl, yr) {\n\
    \        for (auto&& x: dat[i][j]) sm += x, chmax(mx, x);\n      }\n      auto\
    \ res = KDT.prod(xl, xr, yl, yr);\n      assert(res.fi == sm && res.se == mx);\n\
    \    }\n    if (t == 2) {\n      // prod all\n      int sm = 0, mx = MX::unit().se;\n\
    \      FOR(i, LIM) FOR(j, LIM) {\n        for (auto&& x: dat[i][j]) sm += x, chmax(mx,\
    \ x);\n      }\n      auto res = KDT.prod_all();\n      assert(res.fi == sm &&\
    \ res.se == mx);\n    }\n    if (t == 3) {\n      // apply\n      int a = RNG(0,\
    \ 10);\n      FOR(i, xl, xr) FOR(j, yl, yr) {\n        for (auto&& x: dat[i][j])\
    \ x += a;\n      }\n      KDT.apply(xl, xr, yl, yr, a);\n    }\n  }\n}\n\nvoid\
    \ solve() {\n  int a, b;\n  cin >> a >> b;\n  cout << a + b << \"\\n\";\n}\n\n\
    signed main() {\n  FOR(100) test();\n  solve();\n  return 0;\n}\n"
  dependsOn:
  - my_template.hpp
  - ds/kdtree/kdtree_acted_monoid.hpp
  - alg/acted_monoid/summax_add.hpp
  - alg/monoid/summax.hpp
  - alg/monoid/add.hpp
  - random/base.hpp
  isVerificationFile: true
  path: test/mytest/kdtree_am.test.cpp
  requiredBy: []
  timestamp: '2023-11-09 01:44:55+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: test/mytest/kdtree_am.test.cpp
layout: document
redirect_from:
- /verify/test/mytest/kdtree_am.test.cpp
- /verify/test/mytest/kdtree_am.test.cpp.html
title: test/mytest/kdtree_am.test.cpp
---