---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: alg/acted_monoid/summax_add.hpp
    title: alg/acted_monoid/summax_add.hpp
  - icon: ':question:'
    path: alg/monoid/add.hpp
    title: alg/monoid/add.hpp
  - icon: ':heavy_check_mark:'
    path: alg/monoid/summax.hpp
    title: alg/monoid/summax.hpp
  - icon: ':heavy_check_mark:'
    path: ds/kdtree/kdtree_acted_monoid.hpp
    title: ds/kdtree/kdtree_acted_monoid.hpp
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
  bundledCode: "#line 1 \"test/1_mytest/kdtree_am.test.cpp\"\n#define PROBLEM \"https://judge.yosupo.jp/problem/aplusb\"\
    \n#line 1 \"my_template.hpp\"\n#if defined(USE_PCH)\n#include <my_template_compiled.hpp>\n\
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
    \ abs(a);\n}\n#endif\n#line 3 \"test/1_mytest/kdtree_am.test.cpp\"\n\n#line 1\
    \ \"ds/kdtree/kdtree_acted_monoid.hpp\"\ntemplate <class ActedMonoid, typename\
    \ XY>\r\nstruct KDTree_ActedMonoid {\r\n  using AM = ActedMonoid;\r\n  using MX\
    \ = typename AM::Monoid_X;\r\n  using MA = typename AM::Monoid_A;\r\n  using X\
    \ = typename AM::X;\r\n  using A = typename AM::A;\r\n  static_assert(MX::commute);\r\
    \n\r\n  // \u5C0F\u6570\u3082\u8003\u616E\u3059\u308B\u3068\u3001\u9589\u3067\u6301\
    \u3064\u8A2D\u8A08\u65B9\u91DD\u306B\u306A\u308B\u3002\u305F\u3060\u3057\u3001\
    \u30AF\u30A8\u30EA\u306F\u3044\u3064\u3082\u306E\u534A\u958B\u3092\u4F7F\u3046\
    \r\n  vc<tuple<XY, XY, XY, XY>> closed_range;\r\n  vc<X> dat;\r\n  vc<A> lazy;\r\
    \n  vc<int> size;\r\n  vc<int> pos; // raw data -> index\r\n  int n, log;\r\n\r\
    \n  KDTree_ActedMonoid(vc<XY> xs, vc<XY> ys, vc<X> vs) : n(len(xs)) {\r\n    assert(n\
    \ > 0);\r\n    log = 0;\r\n    while ((1 << log) < n) ++log;\r\n    dat.resize(1\
    \ << (log + 1));\r\n    lazy.assign(1 << log, MA::id());\r\n    closed_range.assign(1\
    \ << (log + 1), {infty<XY>, -infty<XY>, infty<XY>, -infty<XY>});\r\n    size.resize(1\
    \ << (log + 1));\r\n    vc<int> ids(n);\r\n    pos.resize(n);\r\n    FOR(i, n)\
    \ ids[i] = i;\r\n    build(1, xs, ys, vs, ids);\r\n  }\r\n\r\n  void set(int i,\
    \ const X& v) {\r\n    i = pos[i];\r\n    for (int k = log; k >= 1; k--) { push(i\
    \ >> k); }\r\n    dat[i] = v;\r\n    while (i > 1) i /= 2, dat[i] = MX::op(dat[2\
    \ * i], dat[2 * i + 1]);\r\n  }\r\n  void multiply(int i, const X& v) {\r\n  \
    \  i = pos[i];\r\n    for (int k = log; k >= 1; k--) { push(i >> k); }\r\n   \
    \ dat[i] = MX::op(dat[i], v);\r\n    while (i > 1) i /= 2, dat[i] = MX::op(dat[2\
    \ * i], dat[2 * i + 1]);\r\n  }\r\n\r\n  // [xl, xr) x [yl, yr)\r\n  X prod(XY\
    \ xl, XY xr, XY yl, XY yr) {\r\n    assert(xl <= xr && yl <= yr);\r\n    return\
    \ prod_rec(1, xl, xr, yl, yr);\r\n  }\r\n\r\n  X prod_all() { return dat[1]; }\r\
    \n\r\n  // [xl, xr) x [yl, yr)\r\n  void apply(XY xl, XY xr, XY yl, XY yr, A a)\
    \ {\r\n    assert(xl <= xr && yl <= yr);\r\n    return apply_rec(1, xl, xr, yl,\
    \ yr, a);\r\n  }\r\n\r\nprivate:\r\n  void build(int idx, vc<XY> xs, vc<XY> ys,\
    \ vc<X> vs, vc<int> ids, bool divx = true) {\r\n    int n = len(xs);\r\n    size[idx]\
    \ = n;\r\n    auto& [xmin, xmax, ymin, ymax] = closed_range[idx];\r\n    xmin\
    \ = ymin = infty<XY>;\r\n    xmax = ymax = -infty<XY>;\r\n\r\n    FOR(i, n) {\r\
    \n      auto x = xs[i], y = ys[i];\r\n      chmin(xmin, x), chmax(xmax, x), chmin(ymin,\
    \ y), chmax(ymax, y);\r\n    }\r\n    if (n == 1) {\r\n      dat[idx] = vs[0];\r\
    \n      pos[ids[0]] = idx;\r\n      return;\r\n    }\r\n\r\n    int m = n / 2;\r\
    \n    vc<int> I(n);\r\n    iota(all(I), 0);\r\n    if (divx) {\r\n      nth_element(I.begin(),\
    \ I.begin() + m, I.end(), [xs](int i, int j) { return xs[i] < xs[j]; });\r\n \
    \   } else {\r\n      nth_element(I.begin(), I.begin() + m, I.end(), [ys](int\
    \ i, int j) { return ys[i] < ys[j]; });\r\n    }\r\n    xs = rearrange(xs, I),\
    \ ys = rearrange(ys, I), vs = rearrange(vs, I), ids = rearrange(ids, I);\r\n \
    \   build(2 * idx + 0, {xs.begin(), xs.begin() + m}, {ys.begin(), ys.begin() +\
    \ m}, {vs.begin(), vs.begin() + m}, {ids.begin(), ids.begin() + m}, !divx);\r\n\
    \    build(2 * idx + 1, {xs.begin() + m, xs.end()}, {ys.begin() + m, ys.end()},\
    \ {vs.begin() + m, vs.end()}, {ids.begin() + m, ids.end()}, !divx);\r\n    dat[idx]\
    \ = MX::op(dat[2 * idx + 0], dat[2 * idx + 1]);\r\n  }\r\n\r\n  inline bool isin(XY\
    \ x, XY y, int idx) {\r\n    auto& [xmin, xmax, ymin, ymax] = closed_range[idx];\r\
    \n    return (xmin <= x && x <= xmax && ymin <= y && y <= ymax);\r\n  }\r\n\r\n\
    \  void apply_at(int idx, A a) {\r\n    dat[idx] = AM::act(dat[idx], a, size[idx]);\r\
    \n    if (idx < (1 << log)) lazy[idx] = MA::op(lazy[idx], a);\r\n  }\r\n\r\n \
    \ void push(int idx) {\r\n    if (lazy[idx] == MA::id()) return;\r\n    apply_at(2\
    \ * idx + 0, lazy[idx]), apply_at(2 * idx + 1, lazy[idx]);\r\n    lazy[idx] =\
    \ MA::id();\r\n  }\r\n\r\n  X prod_rec(int idx, XY x1, XY x2, XY y1, XY y2) {\r\
    \n    if (idx >= len(closed_range)) return MX::id();\r\n    auto& [xmin, xmax,\
    \ ymin, ymax] = closed_range[idx];\r\n    if (xmin > xmax) return MX::id();\r\n\
    \    if (x2 <= xmin || xmax < x1) return MX::id();\r\n    if (y2 <= ymin || ymax\
    \ < y1) return MX::id();\r\n    if (x1 <= xmin && xmax < x2 && y1 <= ymin && ymax\
    \ < y2) { return dat[idx]; }\r\n    push(idx);\r\n    return MX::op(prod_rec(2\
    \ * idx + 0, x1, x2, y1, y2), prod_rec(2 * idx + 1, x1, x2, y1, y2));\r\n  }\r\
    \n\r\n  void apply_rec(int idx, XY x1, XY x2, XY y1, XY y2, A a) {\r\n    if (idx\
    \ >= len(closed_range)) return;\r\n    auto& [xmin, xmax, ymin, ymax] = closed_range[idx];\r\
    \n    if (xmin > xmax) return;\r\n    if (x2 <= xmin || xmax < x1) return;\r\n\
    \    if (y2 <= ymin || ymax < y1) return;\r\n    if (x1 <= xmin && xmax < x2 &&\
    \ y1 <= ymin && ymax < y2) { return apply_at(idx, a); }\r\n    push(idx);\r\n\
    \    apply_rec(2 * idx + 0, x1, x2, y1, y2, a);\r\n    apply_rec(2 * idx + 1,\
    \ x1, x2, y1, y2, a);\r\n    dat[idx] = MX::op(dat[2 * idx + 0], dat[2 * idx +\
    \ 1]);\r\n  }\r\n};\r\n#line 1 \"alg/monoid/summax.hpp\"\n\ntemplate <typename\
    \ E>\nstruct Monoid_SumMax {\n  using value_type = pair<E, E>;\n  using X = value_type;\n\
    \  static X op(X x, X y) { return {x.fi + y.fi, max(x.se, y.se)}; }\n  static\
    \ X from_element(E e) { return {e, e}; }\n  static constexpr X id() { return {E(0),\
    \ -infty<E>}; }\n  static constexpr bool commute = 1;\n};\n#line 1 \"alg/monoid/add.hpp\"\
    \n\ntemplate <typename E>\nstruct Monoid_Add {\n  using X = E;\n  using value_type\
    \ = X;\n  static constexpr X op(const X &x, const X &y) noexcept { return x +\
    \ y; }\n  static constexpr X inverse(const X &x) noexcept { return -x; }\n  static\
    \ constexpr X power(const X &x, ll n) noexcept { return X(n) * x; }\n  static\
    \ constexpr X id() { return X(0); }\n  static constexpr bool commute = true;\n\
    };\n#line 3 \"alg/acted_monoid/summax_add.hpp\"\n\ntemplate <typename E>\nstruct\
    \ ActedMonoid_SumMax_Add {\n  using Monoid_X = Monoid_SumMax<E>;\n  using Monoid_A\
    \ = Monoid_Add<E>;\n  using X = typename Monoid_X::value_type;\n  using A = typename\
    \ Monoid_A::value_type;\n  static constexpr X act(const X& x, const A& a, const\
    \ ll& size) {\n    auto [xs, xm] = x;\n    xm = (xm == -infty<E> ? xm : xm + a);\n\
    \    return {xs + E(size) * a, xm};\n  }\n};\n#line 1 \"random/base.hpp\"\n\n\
    u64 RNG_64() {\n  static u64 x_ = u64(chrono::duration_cast<chrono::nanoseconds>(\n\
    \                      chrono::high_resolution_clock::now().time_since_epoch())\n\
    \                          .count()) *\n                  10150724397891781847ULL;\n\
    \  x_ ^= x_ << 7;\n  return x_ ^= x_ >> 9;\n}\n\nu64 RNG(u64 lim) {\n  assert(lim\
    \ > 0);\n  return RNG_64() % lim;\n}\n\nll RNG(ll l, ll r) {\n  assert(l < r);\n\
    \  return l + RNG_64() % (r - l);\n}\n#line 7 \"test/1_mytest/kdtree_am.test.cpp\"\
    \n\nvoid test() {\n  ll LIM = RNG(1, 100);\n  int N = RNG(1, 100);\n  using AM\
    \ = ActedMonoid_SumMax_Add<int>;\n  using MX = AM::Monoid_X;\n\n  vc<int> X, Y,\
    \ W;\n  vc<typename MX::value_type> val;\n  FOR(i, N) {\n    int x = RNG(0, LIM);\n\
    \    int y = RNG(0, LIM);\n    int v = RNG(0, 100);\n    X.eb(x), Y.eb(y), val.eb(v,\
    \ v);\n  }\n  KDTree_ActedMonoid<AM, int> KDT(X, Y, val);\n\n  int Q = 100;\n\
    \  FOR(Q) {\n    int t = RNG(0, 4);\n    int xl = RNG(0, LIM), xr = RNG(0, LIM),\
    \ yl = RNG(0, LIM), yr = RNG(0, LIM);\n    if (xl > xr) swap(xl, xr);\n    if\
    \ (yl > yr) swap(yl, yr);\n    if (t == 0) {\n      // multiply\n      int k =\
    \ RNG(0, N);\n      int a = RNG(0, 100);\n      int b = RNG(0, 100);\n      KDT.multiply(k,\
    \ {a, b});\n      val[k].fi += a;\n      chmax(val[k].se, b);\n    }\n    if (t\
    \ == 1) {\n      // prod\n      int sm = 0, mx = MX::id().se;\n      FOR(k, N)\
    \ {\n        if (xl <= X[k] && X[k] < xr && yl <= Y[k] && Y[k] < yr) { sm += val[k].fi,\
    \ chmax(mx, val[k].se); }\n      }\n      auto res = KDT.prod(xl, xr, yl, yr);\n\
    \      assert(res.fi == sm && res.se == mx);\n    }\n    if (t == 2) {\n     \
    \ // prod all\n      int sm = 0, mx = MX::id().se;\n      FOR(k, N) { sm += val[k].fi,\
    \ chmax(mx, val[k].se); }\n      auto res = KDT.prod_all();\n      assert(res.fi\
    \ == sm && res.se == mx);\n    }\n    if (t == 3) {\n      // apply\n      int\
    \ a = RNG(0, 10);\n      FOR(k, N) {\n        if (xl <= X[k] && X[k] < xr && yl\
    \ <= Y[k] && Y[k] < yr) { val[k].fi += a, val[k].se += a; }\n      }\n      KDT.apply(xl,\
    \ xr, yl, yr, a);\n    }\n  }\n}\n\nvoid solve() {\n  int a, b;\n  cin >> a >>\
    \ b;\n  cout << a + b << \"\\n\";\n}\n\nsigned main() {\n  FOR(100) test();\n\
    \  solve();\n  return 0;\n}\n"
  code: "#define PROBLEM \"https://judge.yosupo.jp/problem/aplusb\"\n#include \"my_template.hpp\"\
    \n\n#include \"ds/kdtree/kdtree_acted_monoid.hpp\"\n#include \"alg/acted_monoid/summax_add.hpp\"\
    \n#include \"random/base.hpp\"\n\nvoid test() {\n  ll LIM = RNG(1, 100);\n  int\
    \ N = RNG(1, 100);\n  using AM = ActedMonoid_SumMax_Add<int>;\n  using MX = AM::Monoid_X;\n\
    \n  vc<int> X, Y, W;\n  vc<typename MX::value_type> val;\n  FOR(i, N) {\n    int\
    \ x = RNG(0, LIM);\n    int y = RNG(0, LIM);\n    int v = RNG(0, 100);\n    X.eb(x),\
    \ Y.eb(y), val.eb(v, v);\n  }\n  KDTree_ActedMonoid<AM, int> KDT(X, Y, val);\n\
    \n  int Q = 100;\n  FOR(Q) {\n    int t = RNG(0, 4);\n    int xl = RNG(0, LIM),\
    \ xr = RNG(0, LIM), yl = RNG(0, LIM), yr = RNG(0, LIM);\n    if (xl > xr) swap(xl,\
    \ xr);\n    if (yl > yr) swap(yl, yr);\n    if (t == 0) {\n      // multiply\n\
    \      int k = RNG(0, N);\n      int a = RNG(0, 100);\n      int b = RNG(0, 100);\n\
    \      KDT.multiply(k, {a, b});\n      val[k].fi += a;\n      chmax(val[k].se,\
    \ b);\n    }\n    if (t == 1) {\n      // prod\n      int sm = 0, mx = MX::id().se;\n\
    \      FOR(k, N) {\n        if (xl <= X[k] && X[k] < xr && yl <= Y[k] && Y[k]\
    \ < yr) { sm += val[k].fi, chmax(mx, val[k].se); }\n      }\n      auto res =\
    \ KDT.prod(xl, xr, yl, yr);\n      assert(res.fi == sm && res.se == mx);\n   \
    \ }\n    if (t == 2) {\n      // prod all\n      int sm = 0, mx = MX::id().se;\n\
    \      FOR(k, N) { sm += val[k].fi, chmax(mx, val[k].se); }\n      auto res =\
    \ KDT.prod_all();\n      assert(res.fi == sm && res.se == mx);\n    }\n    if\
    \ (t == 3) {\n      // apply\n      int a = RNG(0, 10);\n      FOR(k, N) {\n \
    \       if (xl <= X[k] && X[k] < xr && yl <= Y[k] && Y[k] < yr) { val[k].fi +=\
    \ a, val[k].se += a; }\n      }\n      KDT.apply(xl, xr, yl, yr, a);\n    }\n\
    \  }\n}\n\nvoid solve() {\n  int a, b;\n  cin >> a >> b;\n  cout << a + b << \"\
    \\n\";\n}\n\nsigned main() {\n  FOR(100) test();\n  solve();\n  return 0;\n}"
  dependsOn:
  - my_template.hpp
  - ds/kdtree/kdtree_acted_monoid.hpp
  - alg/acted_monoid/summax_add.hpp
  - alg/monoid/summax.hpp
  - alg/monoid/add.hpp
  - random/base.hpp
  isVerificationFile: true
  path: test/1_mytest/kdtree_am.test.cpp
  requiredBy: []
  timestamp: '2026-08-30 21:41:42+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: test/1_mytest/kdtree_am.test.cpp
layout: document
redirect_from:
- /verify/test/1_mytest/kdtree_am.test.cpp
- /verify/test/1_mytest/kdtree_am.test.cpp.html
title: test/1_mytest/kdtree_am.test.cpp
---
