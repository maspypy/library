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
  - icon: ':question:'
    path: ds/kdtree/kdtree_acted_monoid.hpp
    title: ds/kdtree/kdtree_acted_monoid.hpp
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
  bundledCode: "#line 1 \"test/1_mytest/kdtree_am.test.cpp\"\n#define PROBLEM \"https://judge.yosupo.jp/problem/aplusb\"\
    \n#line 1 \"my_template.hpp\"\n#if defined(LOCAL)\n#include <my_template_compiled.hpp>\n\
    #else\n\n// https://codeforces.com/blog/entry/96344\n// https://codeforces.com/blog/entry/126772?#comment-1154880\n\
    #include <bits/allocator.h>\n#pragma GCC optimize(\"Ofast,unroll-loops\")\n#pragma\
    \ GCC target(\"avx2,popcnt\")\n#include <bits/stdc++.h>\n\nusing namespace std;\n\
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
    \ vvvvvc = vector<vvvvc<T>>;\ntemplate <class T>\nusing pq_max = priority_queue<T>;\n\
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
    \    int operator*() const { return s ^ t; }\n    iter &operator++() {\n     \
    \ (t == 0 ? ed = 1 : t = (t - 1) & s);\n      return *this;\n    }\n    bool operator!=(const\
    \ iter) const { return !ed; }\n  };\n  UINT s;\n  all_subset(UINT s) : s(s) {}\n\
    \  iter begin() const { return iter(s); }\n  iter end() const { return iter(0);\
    \ }\n};\n\ntemplate <typename T>\nT floor(T a, T b) {\n  return a / b - (a % b\
    \ && (a ^ b) < 0);\n}\ntemplate <typename T>\nT ceil(T x, T y) {\n  return floor(x\
    \ + y - 1, y);\n}\ntemplate <typename T>\nT bmod(T x, T y) {\n  return x - y *\
    \ floor(x, y);\n}\ntemplate <typename T>\npair<T, T> divmod(T x, T y) {\n  T q\
    \ = floor(x, y);\n  return {q, x - q * y};\n}\n\ntemplate <typename T, typename\
    \ U>\nT SUM(const U &A) {\n  return std::accumulate(A.begin(), A.end(), T{});\n\
    }\n\n#define MIN(v) *min_element(all(v))\n#define MAX(v) *max_element(all(v))\n\
    #define LB(c, x) distance((c).begin(), lower_bound(all(c), (x)))\n#define UB(c,\
    \ x) distance((c).begin(), upper_bound(all(c), (x)))\n#define UNIQUE(x) \\\n \
    \ sort(all(x)), x.erase(unique(all(x)), x.end()), x.shrink_to_fit()\n\ntemplate\
    \ <typename T>\nT POP(deque<T> &que) {\n  T a = que.front();\n  que.pop_front();\n\
    \  return a;\n}\ntemplate <typename T>\nT POP(pq_min<T> &que) {\n  T a = que.top();\n\
    \  que.pop();\n  return a;\n}\ntemplate <typename T>\nT POP(pq_max<T> &que) {\n\
    \  T a = que.top();\n  que.pop();\n  return a;\n}\ntemplate <typename T>\nT POP(vc<T>\
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
    \  return B;\n}\n\ntemplate <typename T, typename... Vectors>\nvoid concat(vc<T>\
    \ &first, const Vectors &...others) {\n  vc<T> &res = first;\n  (res.insert(res.end(),\
    \ others.begin(), others.end()), ...);\n}\n#endif\n#line 3 \"test/1_mytest/kdtree_am.test.cpp\"\
    \n\n#line 1 \"ds/kdtree/kdtree_acted_monoid.hpp\"\ntemplate <class ActedMonoid,\
    \ typename XY>\r\nstruct KDTree_ActedMonoid {\r\n  using AM = ActedMonoid;\r\n\
    \  using MX = typename AM::Monoid_X;\r\n  using MA = typename AM::Monoid_A;\r\n\
    \  using X = typename AM::X;\r\n  using A = typename AM::A;\r\n  static_assert(MX::commute);\r\
    \n\r\n  // \u5C0F\u6570\u3082\u8003\u616E\u3059\u308B\u3068\u3001\u9589\u3067\u6301\
    \u3064\u8A2D\u8A08\u65B9\u91DD\u306B\u306A\u308B\u3002\u305F\u3060\u3057\u3001\
    \u30AF\u30A8\u30EA\u306F\u3044\u3064\u3082\u306E\u534A\u958B\u3092\u4F7F\u3046\
    \r\n  vc<tuple<XY, XY, XY, XY>> closed_range;\r\n  vc<X> dat;\r\n  vc<A> lazy;\r\
    \n  vc<int> size;\r\n  vc<int> pos; // raw data -> index\r\n  int n, log;\r\n\r\
    \n  KDTree_ActedMonoid(vc<XY> xs, vc<XY> ys, vc<X> vs) : n(len(xs)) {\r\n    assert(n\
    \ > 0);\r\n    log = 0;\r\n    while ((1 << log) < n) ++log;\r\n    dat.resize(1\
    \ << (log + 1));\r\n    lazy.assign(1 << log, MA::unit());\r\n    closed_range.assign(1\
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
    \ void push(int idx) {\r\n    if (lazy[idx] == MA::unit()) return;\r\n    apply_at(2\
    \ * idx + 0, lazy[idx]), apply_at(2 * idx + 1, lazy[idx]);\r\n    lazy[idx] =\
    \ MA::unit();\r\n  }\r\n\r\n  X prod_rec(int idx, XY x1, XY x2, XY y1, XY y2)\
    \ {\r\n    if (idx >= len(closed_range)) return MX::unit();\r\n    auto& [xmin,\
    \ xmax, ymin, ymax] = closed_range[idx];\r\n    if (xmin > xmax) return MX::unit();\r\
    \n    if (x2 <= xmin || xmax < x1) return MX::unit();\r\n    if (y2 <= ymin ||\
    \ ymax < y1) return MX::unit();\r\n    if (x1 <= xmin && xmax < x2 && y1 <= ymin\
    \ && ymax < y2) { return dat[idx]; }\r\n    push(idx);\r\n    return MX::op(prod_rec(2\
    \ * idx + 0, x1, x2, y1, y2), prod_rec(2 * idx + 1, x1, x2, y1, y2));\r\n  }\r\
    \n\r\n  void apply_rec(int idx, XY x1, XY x2, XY y1, XY y2, A a) {\r\n    if (idx\
    \ >= len(closed_range)) return;\r\n    auto& [xmin, xmax, ymin, ymax] = closed_range[idx];\r\
    \n    if (xmin > xmax) return;\r\n    if (x2 <= xmin || xmax < x1) return;\r\n\
    \    if (y2 <= ymin || ymax < y1) return;\r\n    if (x1 <= xmin && xmax < x2 &&\
    \ y1 <= ymin && ymax < y2) { return apply_at(idx, a); }\r\n    push(idx);\r\n\
    \    apply_rec(2 * idx + 0, x1, x2, y1, y2, a);\r\n    apply_rec(2 * idx + 1,\
    \ x1, x2, y1, y2, a);\r\n    dat[idx] = MX::op(dat[2 * idx + 0], dat[2 * idx +\
    \ 1]);\r\n  }\r\n};\r\n#line 2 \"alg/monoid/summax.hpp\"\n\ntemplate <typename\
    \ E>\nstruct Monoid_SumMax {\n  using value_type = pair<E, E>;\n  using X = value_type;\n\
    \  static X op(X x, X y) { return {x.fi + y.fi, max(x.se, y.se)}; }\n  static\
    \ X from_element(E e) { return {e, e}; }\n  static constexpr X unit() { return\
    \ {E(0), -infty<E>}; }\n  static constexpr bool commute = 1;\n};\n#line 2 \"alg/monoid/add.hpp\"\
    \n\r\ntemplate <typename E>\r\nstruct Monoid_Add {\r\n  using X = E;\r\n  using\
    \ value_type = X;\r\n  static constexpr X op(const X &x, const X &y) noexcept\
    \ { return x + y; }\r\n  static constexpr X inverse(const X &x) noexcept { return\
    \ -x; }\r\n  static constexpr X power(const X &x, ll n) noexcept { return X(n)\
    \ * x; }\r\n  static constexpr X unit() { return X(0); }\r\n  static constexpr\
    \ bool commute = true;\r\n};\r\n#line 3 \"alg/acted_monoid/summax_add.hpp\"\n\n\
    template <typename E>\nstruct ActedMonoid_SumMax_Add {\n  using Monoid_X = Monoid_SumMax<E>;\n\
    \  using Monoid_A = Monoid_Add<E>;\n  using X = typename Monoid_X::value_type;\n\
    \  using A = typename Monoid_A::value_type;\n  static constexpr X act(const X&\
    \ x, const A& a, const ll& size) {\n    auto [xs, xm] = x;\n    xm = (xm == -infty<E>\
    \ ? xm : xm + a);\n    return {xs + E(size) * a, xm};\n  }\n};\n#line 2 \"random/base.hpp\"\
    \n\nu64 RNG_64() {\n  static u64 x_ = u64(chrono::duration_cast<chrono::nanoseconds>(chrono::high_resolution_clock::now().time_since_epoch()).count())\
    \ * 10150724397891781847ULL;\n  x_ ^= x_ << 7;\n  return x_ ^= x_ >> 9;\n}\n\n\
    u64 RNG(u64 lim) { return RNG_64() % lim; }\n\nll RNG(ll l, ll r) { return l +\
    \ RNG_64() % (r - l); }\n#line 7 \"test/1_mytest/kdtree_am.test.cpp\"\n\nvoid\
    \ test() {\n  ll LIM = RNG(1, 100);\n  int N = RNG(1, 100);\n  using AM = ActedMonoid_SumMax_Add<int>;\n\
    \  using MX = AM::Monoid_X;\n\n  vc<int> X, Y, W;\n  vc<typename MX::value_type>\
    \ val;\n  FOR(i, N) {\n    int x = RNG(0, LIM);\n    int y = RNG(0, LIM);\n  \
    \  int v = RNG(0, 100);\n    X.eb(x), Y.eb(y), val.eb(v, v);\n  }\n  KDTree_ActedMonoid<AM,\
    \ int> KDT(X, Y, val);\n\n  int Q = 100;\n  FOR(Q) {\n    int t = RNG(0, 4);\n\
    \    int xl = RNG(0, LIM), xr = RNG(0, LIM), yl = RNG(0, LIM), yr = RNG(0, LIM);\n\
    \    if (xl > xr) swap(xl, xr);\n    if (yl > yr) swap(yl, yr);\n    if (t ==\
    \ 0) {\n      // multiply\n      int k = RNG(0, N);\n      int a = RNG(0, 100);\n\
    \      int b = RNG(0, 100);\n      KDT.multiply(k, {a, b});\n      val[k].fi +=\
    \ a;\n      chmax(val[k].se, b);\n    }\n    if (t == 1) {\n      // prod\n  \
    \    int sm = 0, mx = MX::unit().se;\n      FOR(k, N) {\n        if (xl <= X[k]\
    \ && X[k] < xr && yl <= Y[k] && Y[k] < yr) { sm += val[k].fi, chmax(mx, val[k].se);\
    \ }\n      }\n      auto res = KDT.prod(xl, xr, yl, yr);\n      assert(res.fi\
    \ == sm && res.se == mx);\n    }\n    if (t == 2) {\n      // prod all\n     \
    \ int sm = 0, mx = MX::unit().se;\n      FOR(k, N) { sm += val[k].fi, chmax(mx,\
    \ val[k].se); }\n      auto res = KDT.prod_all();\n      assert(res.fi == sm &&\
    \ res.se == mx);\n    }\n    if (t == 3) {\n      // apply\n      int a = RNG(0,\
    \ 10);\n      FOR(k, N) {\n        if (xl <= X[k] && X[k] < xr && yl <= Y[k] &&\
    \ Y[k] < yr) { val[k].fi += a, val[k].se += a; }\n      }\n      KDT.apply(xl,\
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
    \ b);\n    }\n    if (t == 1) {\n      // prod\n      int sm = 0, mx = MX::unit().se;\n\
    \      FOR(k, N) {\n        if (xl <= X[k] && X[k] < xr && yl <= Y[k] && Y[k]\
    \ < yr) { sm += val[k].fi, chmax(mx, val[k].se); }\n      }\n      auto res =\
    \ KDT.prod(xl, xr, yl, yr);\n      assert(res.fi == sm && res.se == mx);\n   \
    \ }\n    if (t == 2) {\n      // prod all\n      int sm = 0, mx = MX::unit().se;\n\
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
  timestamp: '2025-07-03 18:22:07+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: test/1_mytest/kdtree_am.test.cpp
layout: document
redirect_from:
- /verify/test/1_mytest/kdtree_am.test.cpp
- /verify/test/1_mytest/kdtree_am.test.cpp.html
title: test/1_mytest/kdtree_am.test.cpp
---
