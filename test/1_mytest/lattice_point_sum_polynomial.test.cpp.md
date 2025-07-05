---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: alg/monoid/monoid_for_floor_sum.hpp
    title: alg/monoid/monoid_for_floor_sum.hpp
  - icon: ':heavy_check_mark:'
    path: alg/monoid_pow.hpp
    title: alg/monoid_pow.hpp
  - icon: ':heavy_check_mark:'
    path: convex/lattice_point_sum_polynomial.hpp
    title: convex/lattice_point_sum_polynomial.hpp
  - icon: ':heavy_check_mark:'
    path: convex/line_min_function.hpp
    title: convex/line_min_function.hpp
  - icon: ':heavy_check_mark:'
    path: geo/base.hpp
    title: geo/base.hpp
  - icon: ':heavy_check_mark:'
    path: geo/convex_hull.hpp
    title: geo/convex_hull.hpp
  - icon: ':heavy_check_mark:'
    path: mod/crt3.hpp
    title: mod/crt3.hpp
  - icon: ':heavy_check_mark:'
    path: mod/floor_monoid_product.hpp
    title: mod/floor_monoid_product.hpp
  - icon: ':heavy_check_mark:'
    path: mod/floor_sum_of_linear_polynomial.hpp
    title: mod/floor_sum_of_linear_polynomial.hpp
  - icon: ':heavy_check_mark:'
    path: mod/mod_inv.hpp
    title: mod/mod_inv.hpp
  - icon: ':question:'
    path: mod/modint.hpp
    title: mod/modint.hpp
  - icon: ':question:'
    path: mod/modint_common.hpp
    title: mod/modint_common.hpp
  - icon: ':heavy_check_mark:'
    path: mod/powertable.hpp
    title: mod/powertable.hpp
  - icon: ':question:'
    path: my_template.hpp
    title: my_template.hpp
  - icon: ':heavy_check_mark:'
    path: nt/primetable.hpp
    title: nt/primetable.hpp
  - icon: ':heavy_check_mark:'
    path: poly/convolution.hpp
    title: poly/convolution.hpp
  - icon: ':heavy_check_mark:'
    path: poly/convolution_karatsuba.hpp
    title: poly/convolution_karatsuba.hpp
  - icon: ':heavy_check_mark:'
    path: poly/convolution_naive.hpp
    title: poly/convolution_naive.hpp
  - icon: ':heavy_check_mark:'
    path: poly/count_terms.hpp
    title: poly/count_terms.hpp
  - icon: ':heavy_check_mark:'
    path: poly/fps_div.hpp
    title: poly/fps_div.hpp
  - icon: ':heavy_check_mark:'
    path: poly/fps_inv.hpp
    title: poly/fps_inv.hpp
  - icon: ':heavy_check_mark:'
    path: poly/ntt.hpp
    title: poly/ntt.hpp
  - icon: ':heavy_check_mark:'
    path: random/base.hpp
    title: random/base.hpp
  - icon: ':heavy_check_mark:'
    path: seq/famous/bernoulli.hpp
    title: seq/famous/bernoulli.hpp
  - icon: ':heavy_check_mark:'
    path: seq/famous/faulhaber.hpp
    title: seq/famous/faulhaber.hpp
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
  bundledCode: "#line 1 \"test/1_mytest/lattice_point_sum_polynomial.test.cpp\"\n\
    #define PROBLEM \"https://judge.yosupo.jp/problem/aplusb\"\n\n#line 1 \"my_template.hpp\"\
    \n#if defined(LOCAL)\n#include <my_template_compiled.hpp>\n#else\n\n// https://codeforces.com/blog/entry/96344\n\
    // https://codeforces.com/blog/entry/126772?#comment-1154880\n#include <bits/allocator.h>\n\
    #pragma GCC optimize(\"Ofast,unroll-loops\")\n#pragma GCC target(\"avx2,popcnt\"\
    )\n#include <bits/stdc++.h>\n\nusing namespace std;\n\nusing ll = long long;\n\
    using u8 = uint8_t;\nusing u16 = uint16_t;\nusing u32 = uint32_t;\nusing u64 =\
    \ uint64_t;\nusing i128 = __int128;\nusing u128 = unsigned __int128;\nusing f128\
    \ = __float128;\n\ntemplate <class T>\nconstexpr T infty = 0;\ntemplate <>\nconstexpr\
    \ int infty<int> = 1'010'000'000;\ntemplate <>\nconstexpr ll infty<ll> = 2'020'000'000'000'000'000;\n\
    template <>\nconstexpr u32 infty<u32> = infty<int>;\ntemplate <>\nconstexpr u64\
    \ infty<u64> = infty<ll>;\ntemplate <>\nconstexpr i128 infty<i128> = i128(infty<ll>)\
    \ * 2'000'000'000'000'000'000;\ntemplate <>\nconstexpr double infty<double> =\
    \ infty<ll>;\ntemplate <>\nconstexpr long double infty<long double> = infty<ll>;\n\
    \nusing pi = pair<ll, ll>;\nusing vi = vector<ll>;\ntemplate <class T>\nusing\
    \ vc = vector<T>;\ntemplate <class T>\nusing vvc = vector<vc<T>>;\ntemplate <class\
    \ T>\nusing vvvc = vector<vvc<T>>;\ntemplate <class T>\nusing vvvvc = vector<vvvc<T>>;\n\
    template <class T>\nusing vvvvvc = vector<vvvvc<T>>;\ntemplate <class T>\nusing\
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
    \ others.begin(), others.end()), ...);\n}\n#endif\n#line 4 \"test/1_mytest/lattice_point_sum_polynomial.test.cpp\"\
    \n\n#line 2 \"random/base.hpp\"\n\nu64 RNG_64() {\n  static u64 x_ = u64(chrono::duration_cast<chrono::nanoseconds>(chrono::high_resolution_clock::now().time_since_epoch()).count())\
    \ * 10150724397891781847ULL;\n  x_ ^= x_ << 7;\n  return x_ ^= x_ >> 9;\n}\n\n\
    u64 RNG(u64 lim) { return RNG_64() % lim; }\n\nll RNG(ll l, ll r) { return l +\
    \ RNG_64() % (r - l); }\n#line 2 \"convex/line_min_function.hpp\"\n\n#line 2 \"\
    geo/convex_hull.hpp\"\n\n#line 2 \"geo/base.hpp\"\ntemplate <typename T>\nstruct\
    \ Point {\n  T x, y;\n\n  Point() : x(0), y(0) {}\n\n  template <typename A, typename\
    \ B>\n  Point(A x, B y) : x(x), y(y) {}\n\n  template <typename A, typename B>\n\
    \  Point(pair<A, B> p) : x(p.fi), y(p.se) {}\n\n  Point operator+=(const Point\
    \ p) {\n    x += p.x, y += p.y;\n    return *this;\n  }\n  Point operator-=(const\
    \ Point p) {\n    x -= p.x, y -= p.y;\n    return *this;\n  }\n  Point operator+(Point\
    \ p) const { return {x + p.x, y + p.y}; }\n  Point operator-(Point p) const {\
    \ return {x - p.x, y - p.y}; }\n  bool operator==(Point p) const { return x ==\
    \ p.x && y == p.y; }\n  bool operator!=(Point p) const { return x != p.x || y\
    \ != p.y; }\n  Point operator-() const { return {-x, -y}; }\n  Point operator*(T\
    \ t) const { return {x * t, y * t}; }\n  Point operator/(T t) const { return {x\
    \ / t, y / t}; }\n\n  bool operator<(Point p) const {\n    if (x != p.x) return\
    \ x < p.x;\n    return y < p.y;\n  }\n  T dot(const Point& other) const { return\
    \ x * other.x + y * other.y; }\n  T det(const Point& other) const { return x *\
    \ other.y - y * other.x; }\n\n  double norm() { return sqrtl(x * x + y * y); }\n\
    \  double angle() { return atan2(y, x); }\n\n  Point rotate(double theta) {\n\
    \    static_assert(!is_integral<T>::value);\n    double c = cos(theta), s = sin(theta);\n\
    \    return Point{c * x - s * y, s * x + c * y};\n  }\n  Point rot90(bool ccw)\
    \ { return (ccw ? Point{-y, x} : Point{y, -x}); }\n};\n\n#ifdef FASTIO\ntemplate\
    \ <typename T>\nvoid rd(Point<T>& p) {\n  fastio::rd(p.x), fastio::rd(p.y);\n\
    }\ntemplate <typename T>\nvoid wt(Point<T>& p) {\n  fastio::wt(p.x);\n  fastio::wt('\
    \ ');\n  fastio::wt(p.y);\n}\n#endif\n\n// A -> B -> C \u3068\u9032\u3080\u3068\
    \u304D\u306B\u3001\u5DE6\u306B\u66F2\u304C\u308B\u306A\u3089\u3070 +1\u3001\u53F3\
    \u306B\u66F2\u304C\u308B\u306A\u3089\u3070 -1\ntemplate <typename T>\nint ccw(Point<T>\
    \ A, Point<T> B, Point<T> C) {\n  T x = (B - A).det(C - A);\n  if (x > 0) return\
    \ 1;\n  if (x < 0) return -1;\n  return 0;\n}\n\ntemplate <typename REAL, typename\
    \ T, typename U>\nREAL dist(Point<T> A, Point<U> B) {\n  REAL dx = REAL(A.x) -\
    \ REAL(B.x);\n  REAL dy = REAL(A.y) - REAL(B.y);\n  return sqrt(dx * dx + dy *\
    \ dy);\n}\n\n// ax+by+c\ntemplate <typename T>\nstruct Line {\n  T a, b, c;\n\n\
    \  Line(T a, T b, T c) : a(a), b(b), c(c) {}\n  Line(Point<T> A, Point<T> B) {\
    \ a = A.y - B.y, b = B.x - A.x, c = A.x * B.y - A.y * B.x; }\n  Line(T x1, T y1,\
    \ T x2, T y2) : Line(Point<T>(x1, y1), Point<T>(x2, y2)) {}\n\n  template <typename\
    \ U>\n  U eval(Point<U> P) {\n    return U(a) * P.x + U(b) * P.y + U(c);\n  }\n\
    \n  template <typename U>\n  T eval(U x, U y) {\n    return a * x + b * y + c;\n\
    \  }\n\n  // \u540C\u3058\u76F4\u7DDA\u304C\u540C\u3058 a,b,c \u3067\u8868\u73FE\
    \u3055\u308C\u308B\u3088\u3046\u306B\u3059\u308B\n  void normalize() {\n    static_assert(is_same_v<T,\
    \ int> || is_same_v<T, long long>);\n    T g = gcd(gcd(abs(a), abs(b)), abs(c));\n\
    \    a /= g, b /= g, c /= g;\n    if (b < 0) { a = -a, b = -b, c = -c; }\n   \
    \ if (b == 0 && a < 0) { a = -a, b = -b, c = -c; }\n  }\n\n  bool is_parallel(Line\
    \ other) { return a * other.b - b * other.a == 0; }\n  bool is_orthogonal(Line\
    \ other) { return a * other.a + b * other.b == 0; }\n};\n\ntemplate <typename\
    \ T>\nstruct Segment {\n  Point<T> A, B;\n\n  Segment(Point<T> A, Point<T> B)\
    \ : A(A), B(B) {}\n  Segment(T x1, T y1, T x2, T y2) : Segment(Point<T>(x1, y1),\
    \ Point<T>(x2, y2)) {}\n\n  bool contain(Point<T> C) {\n    T det = (C - A).det(B\
    \ - A);\n    if (det != 0) return 0;\n    return (C - A).dot(B - A) >= 0 && (C\
    \ - B).dot(A - B) >= 0;\n  }\n\n  Line<T> to_Line() { return Line(A, B); }\n};\n\
    \ntemplate <typename REAL>\nstruct Circle {\n  Point<REAL> O;\n  REAL r;\n  Circle()\
    \ {}\n  Circle(Point<REAL> O, REAL r) : O(O), r(r) {}\n  Circle(REAL x, REAL y,\
    \ REAL r) : O(x, y), r(r) {}\n  template <typename T>\n  bool contain(Point<T>\
    \ p) {\n    REAL dx = p.x - O.x, dy = p.y - O.y;\n    return dx * dx + dy * dy\
    \ <= r * r;\n  }\n};\n#line 4 \"geo/convex_hull.hpp\"\n\n// allow_180=true \u3067\
    \u540C\u4E00\u5EA7\u6A19\u70B9\u304C\u3042\u308B\u3068\u3053\u308F\u308C\u308B\
    \n// full \u306A\u3089 I[0] \u304C sorted \u3067 min \u306B\u306A\u308B\ntemplate\
    \ <typename T, bool allow_180 = false>\nvector<int> ConvexHull(vector<Point<T>>&\
    \ XY, string mode = \"full\", bool sorted = false) {\n  assert(mode == \"full\"\
    \ || mode == \"lower\" || mode == \"upper\");\n  ll N = XY.size();\n  if (N ==\
    \ 1) return {0};\n  if (N == 2) {\n    if (XY[0] < XY[1]) return {0, 1};\n   \
    \ if (XY[1] < XY[0]) return {1, 0};\n    return {0};\n  }\n  vc<int> I(N);\n \
    \ if (sorted) {\n    FOR(i, N) I[i] = i;\n  } else {\n    I = argsort(XY);\n \
    \ }\n  if constexpr (allow_180) { FOR(i, N - 1) assert(XY[i] != XY[i + 1]); }\n\
    \n  auto check = [&](ll i, ll j, ll k) -> bool {\n    T det = (XY[j] - XY[i]).det(XY[k]\
    \ - XY[i]);\n    if constexpr (allow_180) return det >= 0;\n    return det > T(0);\n\
    \  };\n\n  auto calc = [&]() {\n    vector<int> P;\n    for (auto&& k: I) {\n\
    \      while (P.size() > 1) {\n        auto i = P[P.size() - 2];\n        auto\
    \ j = P[P.size() - 1];\n        if (check(i, j, k)) break;\n        P.pop_back();\n\
    \      }\n      P.eb(k);\n    }\n    return P;\n  };\n\n  vc<int> P;\n  if (mode\
    \ == \"full\" || mode == \"lower\") {\n    vc<int> Q = calc();\n    P.insert(P.end(),\
    \ all(Q));\n  }\n  if (mode == \"full\" || mode == \"upper\") {\n    if (!P.empty())\
    \ P.pop_back();\n    reverse(all(I));\n    vc<int> Q = calc();\n    P.insert(P.end(),\
    \ all(Q));\n  }\n  if (mode == \"upper\") reverse(all(P));\n  while (len(P) >=\
    \ 2 && XY[P[0]] == XY[P.back()]) P.pop_back();\n  return P;\n}\n#line 4 \"convex/line_min_function.hpp\"\
    \n\n// 1 \u6B21\u95A2\u6570\u306E max \u3092 [L,R,a,b] \u306E\u5217\u3068\u3057\
    \u3066\u51FA\u529B\n// https://qoj.ac/contest/1576/problem/8505\ntemplate <typename\
    \ Re, typename T>\nvc<tuple<Re, Re, Re, Re>> line_min_function_real(vc<pair<T,\
    \ T>> LINE) {\n  assert(!LINE.empty());\n  using P = Point<T>;\n  vc<P> point;\n\
    \  for (auto& [x, y]: LINE) point.eb(P(x, y));\n  auto I = ConvexHull(point, \"\
    lower\");\n  point = rearrange(point, I);\n  int N = len(point);\n  if (N >= 2\
    \ && point[N - 1].x == point[N - 2].x) { POP(point), --N; }\n  reverse(all(point));\
    \ // \u50BE\u304D\u306F\u5927\u304D\u3044\u65B9\u304B\u3089\n  Re l = -infty<Re>;\n\
    \  vc<tuple<Re, Re, Re, Re>> ANS;\n  FOR(i, N) {\n    Re r = infty<Re>;\n    auto\
    \ [a, b] = point[i];\n    if (i + 1 < N) {\n      auto [c, d] = point[i + 1];\n\
    \      if (a == c) continue;\n      assert(a > c);\n      r = Re(d - b) / (a -\
    \ c);\n      chmax(r, l), chmin(r, infty<Re>);\n    }\n    if (l < r) ANS.eb(l,\
    \ r, a, b), l = r;\n  }\n  return ANS;\n}\n\n// 1 \u6B21\u95A2\u6570\u306E max\
    \ \u3092 [L,R,a,b] \u306E\u5217\u3068\u3057\u3066\u51FA\u529B\ntemplate <typename\
    \ Re, typename T>\nvc<tuple<Re, Re, Re, Re>> line_max_function_real(vc<pair<T,\
    \ T>> LINE) {\n  assert(!LINE.empty());\n  for (auto& [a, b]: LINE) a = -a, b\
    \ = -b;\n  auto ANS = line_min_function_real<Re, T>(LINE);\n  for (auto& [l, r,\
    \ a, b]: ANS) a = -a, b = -b;\n  return ANS;\n}\n\n// LINE(a,b,c): y=(ax+b)/c,\
    \ \u8A55\u4FA1\u70B9\u306F\u6574\u6570\n// 1 \u6B21\u95A2\u6570\u306E min \u3092\
    \ [L,R,a,b,c] \u306E\u5217\u3068\u3057\u3066\u51FA\u529B\n// \u30AA\u30FC\u30D0\
    \u30FC\u30D5\u30ED\u30FC\u5B89\u5168\nvc<tuple<ll, ll, ll, ll, ll>> line_min_function_rational(vc<tuple<ll,\
    \ ll, ll>> LINE, ll L, ll R) {\n  // \u50BE\u304D\u964D\u9806\n  sort(all(LINE),\
    \ [&](auto& L, auto& R) -> bool {\n    auto& [a1, b1, c1] = L;\n    auto& [a2,\
    \ b2, c2] = R;\n    return i128(a1) * c2 > i128(a2) * c1;\n  });\n  vc<tuple<ll,\
    \ ll, ll, ll, ll>> ANS;\n  for (auto& [a2, b2, c2]: LINE) {\n    while (1) {\n\
    \      if (ANS.empty()) {\n        ANS.eb(L, R, a2, b2, c2);\n        break;\n\
    \      }\n      auto& [L1, R1, a1, b1, c1] = ANS.back();\n      i128 s = i128(c2)\
    \ * a1 - i128(a2) * c1; // >= 0\n      i128 t = i128(b2) * c1 - i128(b1) * c2;\n\
    \      if (s == 0) {\n        // \u5E73\u884C\u306A\u306E\u3067\u5C0F\u3055\u3044\
    \u65B9\u3060\u3051\u3092\u6B8B\u3059\n        if (t >= 0) break;\n        ANS.pop_back();\n\
    \        if (len(ANS)) get<1>(ANS.back()) = R;\n        continue;\n      }\n \
    \     i128 x = ceil<i128>(t, s);\n      // x \u4EE5\u4E0A\u3067 2 \u306E\u65B9\
    \u304C\u4E0B\u306B\u6765\u308B\n      if (x <= L1) {\n        ANS.pop_back();\n\
    \        continue;\n      }\n      if (x < R) {\n        R1 = x;\n        ANS.eb(x,\
    \ R, a2, b2, c2);\n        break;\n      } else {\n        break;\n      }\n \
    \   }\n  }\n  return ANS;\n}\n\n// LINE(a,b,c): y=(ax+b)/c, \u8A55\u4FA1\u70B9\
    \u306F\u6574\u6570\n// 1 \u6B21\u95A2\u6570\u306E max \u3092 [L,R,a,b,c] \u306E\
    \u5217\u3068\u3057\u3066\u51FA\u529B\n// \u30AA\u30FC\u30D0\u30FC\u30D5\u30ED\u30FC\
    \u5B89\u5168\nvc<tuple<ll, ll, ll, ll, ll>> line_max_function_rational(vc<tuple<ll,\
    \ ll, ll>> LINE, ll L, ll R) {\n  for (auto& [a, b, c]: LINE) a = -a, b = -b;\n\
    \  auto ANS = line_min_function_rational(LINE, L, R);\n  for (auto& [L, R, a,\
    \ b, c]: ANS) a = -a, b = -b;\n  return ANS;\n}\n\n// LINE(a,b): y=ax+b, \u8A55\
    \u4FA1\u70B9\u306F\u6574\u6570\n// 1 \u6B21\u95A2\u6570\u306E min \u3092 [L,R,a,b]\
    \ \u306E\u5217\u3068\u3057\u3066\u51FA\u529B\n// \u30AA\u30FC\u30D0\u30FC\u30D5\
    \u30ED\u30FC\u5B89\u5168\nvc<tuple<ll, ll, ll, ll>> line_min_function_integer(vc<pair<ll,\
    \ ll>> LINE, ll L, ll R) {\n  // \u50BE\u304D\u964D\u9806\n  sort(all(LINE), [&](auto&\
    \ L, auto& R) -> bool {\n    auto& [a1, b1] = L;\n    auto& [a2, b2] = R;\n  \
    \  return a1 > a2;\n  });\n  vc<tuple<ll, ll, ll, ll>> ANS;\n  for (auto& [a2,\
    \ b2]: LINE) {\n    while (1) {\n      if (ANS.empty()) {\n        ANS.eb(L, R,\
    \ a2, b2);\n        break;\n      }\n      auto& [L1, R1, a1, b1] = ANS.back();\n\
    \      if (a1 == a2) {\n        if (b1 <= b2) break;\n        ANS.pop_back();\n\
    \        if (len(ANS)) get<1>(ANS.back()) = R;\n        continue;\n      }\n \
    \     ll x = ceil<ll>(b2 - b1, a1 - a2);\n      // x \u4EE5\u4E0A\u3067 2 \u306E\
    \u65B9\u304C\u4E0B\u306B\u6765\u308B\n      if (x <= L1) {\n        ANS.pop_back();\n\
    \        continue;\n      }\n      if (x < R) {\n        R1 = x;\n        ANS.eb(x,\
    \ R, a2, b2);\n        break;\n      } else {\n        break;\n      }\n    }\n\
    \  }\n  return ANS;\n}\n\n// LINE(a,b,c): y=(ax+b)/c, \u8A55\u4FA1\u70B9\u306F\
    \u6574\u6570\n// 1 \u6B21\u95A2\u6570\u306E min \u3092 [L,R,a,b,c] \u306E\u5217\
    \u3068\u3057\u3066\u51FA\u529B\n// c>0, (ax+b)c \u304C\u30AA\u30FC\u30D0\u30FC\
    \u30D5\u30ED\u30FC\u3057\u306A\u3044,\nvc<tuple<ll, ll, ll, ll>> line_max_function_integer(vc<pair<ll,\
    \ ll>> LINE, ll L, ll R) {\n  for (auto& [a, b]: LINE) a = -a, b = -b;\n  auto\
    \ ANS = line_min_function_integer(LINE, L, R);\n  for (auto& [L, R, a, b]: ANS)\
    \ a = -a, b = -b;\n  return ANS;\n}\n\n// (L,R,func) \u306E\u4E0B\u5074\u3068\u4E0A\
    \u5074\u3092\u30DE\u30FC\u30B8\u3059\u308B\u3068\u304D\u306A\u3069\u306B\u4F7F\
    \u3046\u7528\ntemplate <typename T>\nvc<tuple<T, T, T, T, T, T>> merge_46(vc<tuple<T,\
    \ T, T, T>> A, vc<tuple<T, T, T, T>> B) {\n  vc<tuple<T, T, T, T, T, T>> ANS;\n\
    \  reverse(all(A));\n  reverse(all(B));\n  while (len(A) && len(B)) {\n    auto&\
    \ [l1, r1, a1, b1] = A.back();\n    auto& [l2, r2, a2, b2] = B.back();\n    assert(l1\
    \ == l2);\n    T r = min(r1, r2);\n    ANS.eb(l1, r, a1, b1, a2, b2);\n    l1\
    \ = r, l2 = r;\n    if (r1 == r) POP(A);\n    if (r2 == r) POP(B);\n  };\n  return\
    \ ANS;\n}\n\n// (L,R,func) \u306E\u4E0B\u5074\u3068\u4E0A\u5074\u3092\u30DE\u30FC\
    \u30B8\u3059\u308B\u3068\u304D\u306A\u3069\u306B\u4F7F\u3046\u7528\n// f(L,R,a1,b1,a2,b2)\n\
    template <typename T, typename F>\nvoid merge_46(const vc<tuple<T, T, T, T>>&\
    \ A, const vc<tuple<T, T, T, T>>& B, F f) {\n  int i = 0, j = 0;\n  while (i <\
    \ len(A) && j < len(B)) {\n    auto& [l1, r1, a1, b1] = A[i];\n    auto& [l2,\
    \ r2, a2, b2] = B[j];\n    T l = max(l1, l2), r = min(r1, r2);\n    if (l < r)\
    \ f(l, r, a1, b1, a2, b2);\n    (r1 < r2 ? i : j)++;\n  }\n}\n\n// (L,R,func)\
    \ \u306E\u4E0B\u5074\u3068\u4E0A\u5074\u3092\u30DE\u30FC\u30B8\u3059\u308B\u3068\
    \u304D\u306A\u3069\u306B\u4F7F\u3046\u7528\n// f(L,R,a1,b1,a2,b2)\ntemplate <typename\
    \ T, typename F>\nvoid merge_58(const vc<tuple<T, T, T, T, T>>& A, const vc<tuple<T,\
    \ T, T, T, T>>& B, F f) {\n  int i = 0, j = 0;\n  while (i < len(A) && j < len(B))\
    \ {\n    auto& [l1, r1, a1, b1, c1] = A[i];\n    auto& [l2, r2, a2, b2, c2] =\
    \ B[j];\n    T l = max(l1, l2), r = min(r1, r2);\n    if (l < r) f(l, r, a1, b1,\
    \ c1, a2, b2, c2);\n    (r1 < r2 ? i : j)++;\n  }\n}\n#line 2 \"mod/floor_sum_of_linear_polynomial.hpp\"\
    \n\n#line 2 \"alg/monoid_pow.hpp\"\n\n// chat gpt\ntemplate <typename U, typename\
    \ Arg1, typename Arg2>\nstruct has_power_method {\nprivate:\n  // \u30D8\u30EB\
    \u30D1\u30FC\u95A2\u6570\u306E\u5B9F\u88C5\n  template <typename V, typename A1,\
    \ typename A2>\n  static auto check(int)\n      -> decltype(std::declval<V>().power(std::declval<A1>(),\n\
    \                                          std::declval<A2>()),\n            \
    \      std::true_type{});\n  template <typename, typename, typename>\n  static\
    \ auto check(...) -> std::false_type;\n\npublic:\n  // \u30E1\u30BD\u30C3\u30C9\
    \u306E\u6709\u7121\u3092\u8868\u3059\u578B\n  static constexpr bool value = decltype(check<U,\
    \ Arg1, Arg2>(0))::value;\n};\n\ntemplate <typename Monoid>\ntypename Monoid::X\
    \ monoid_pow(typename Monoid::X x, ll exp) {\n  using X = typename Monoid::X;\n\
    \  if constexpr (has_power_method<Monoid, X, ll>::value) {\n    return Monoid::power(x,\
    \ exp);\n  } else {\n    assert(exp >= 0);\n    X res = Monoid::unit();\n    while\
    \ (exp) {\n      if (exp & 1) res = Monoid::op(res, x);\n      x = Monoid::op(x,\
    \ x);\n      exp >>= 1;\n    }\n    return res;\n  }\n}\n#line 3 \"mod/floor_monoid_product.hpp\"\
    \n\n// https://yukicoder.me/submissions/883884\n// https://qoj.ac/contest/1411/problem/7620\n\
    // U \u306F\u7BC4\u56F2\u5185\u3067 ax+b \u304C\u30AA\u30FC\u30D0\u30FC\u30D5\u30ED\
    \u30FC\u3057\u306A\u3044\u7A0B\u5EA6\n// yyy x yyyy x ... yyy x yyy (x \u3092\
    \ N \u500B)\n// k \u500B\u76EE\u306E x \u307E\u3067\u306B floor(ak+b,m) \u500B\
    \u306E y \u304C\u3042\u308B\n// my<=ax+b \u306B\u304A\u3051\u308B lattice path\
    \ \u306B\u304A\u3051\u308B\u8FBA\u306E\u5217\u3068\u898B\u306A\u305B\u308B\ntemplate\
    \ <typename Monoid, typename X, typename U>\nX floor_monoid_product(X x, X y,\
    \ U N, U a, U b, U m) {\n  U c = (a * N + b) / m;\n  X pre = Monoid::unit(), suf\
    \ = Monoid::unit();\n  while (1) {\n    const U p = a / m, q = b / m;\n    a %=\
    \ m, b %= m;\n    x = Monoid::op(x, monoid_pow<Monoid>(y, p));\n    pre = Monoid::op(pre,\
    \ monoid_pow<Monoid>(y, q));\n    c -= (p * N + q);\n    if (c == 0) break;\n\
    \    const U d = (m * c - b - 1) / a + 1;\n    suf = Monoid::op(y, Monoid::op(monoid_pow<Monoid>(x,\
    \ N - d), suf));\n    b = m - b - 1 + a, N = c - 1, c = d;\n    swap(m, a), swap(x,\
    \ y);\n  }\n  x = monoid_pow<Monoid>(x, N);\n  return Monoid::op(Monoid::op(pre,\
    \ x), suf);\n}\n#line 2 \"alg/monoid/monoid_for_floor_sum.hpp\"\n// sum i^k1floor^k2:\
    \ floor path \u3067 (x,y) \u304B\u3089 x \u65B9\u5411\u306B\u9032\u3080\u3068\u304D\
    \u306B x^k1y^k2 \u3092\u8DB3\u3059\ntemplate <typename T, int K1, int K2>\nstruct\
    \ Monoid_for_floor_sum {\n  using ARR = array<array<T, K2 + 1>, K1 + 1>;\n  struct\
    \ Data {\n    ARR dp;\n    T dx, dy;\n  };\n\n  using value_type = Data;\n  using\
    \ X = value_type;\n  static X op(X a, X b) {\n    static constexpr int n = max(K1,\
    \ K2);\n    static T comb[n + 1][n + 1];\n    if (comb[0][0] != T(1)) {\n    \
    \  comb[0][0] = T(1);\n      FOR(i, n) FOR(j, i + 1) { comb[i + 1][j] += comb[i][j],\
    \ comb[i + 1][j + 1] += comb[i][j]; }\n    }\n\n    array<T, K1 + 1> pow_x;\n\
    \    array<T, K2 + 1> pow_y;\n    pow_x[0] = 1, pow_y[0] = 1;\n    FOR(i, K1)\
    \ pow_x[i + 1] = pow_x[i] * a.dx;\n    FOR(i, K2) pow_y[i + 1] = pow_y[i] * a.dy;\n\
    \n    // +dy\n    FOR(i, K1 + 1) {\n      FOR_R(j, K2 + 1) {\n        T x = b.dp[i][j];\n\
    \        FOR(k, j + 1, K2 + 1) b.dp[i][k] += comb[k][j] * pow_y[k - j] * x;\n\
    \      }\n    }\n    // +dx\n    FOR(j, K2 + 1) {\n      FOR_R(i, K1 + 1) { FOR(k,\
    \ i, K1 + 1) a.dp[k][j] += comb[k][i] * pow_x[k - i] * b.dp[i][j]; }\n    }\n\n\
    \    a.dx += b.dx, a.dy += b.dy;\n    return a;\n  }\n\n  static X to_x() {\n\
    \    X x = unit();\n    x.dp[0][0] = 1, x.dx = 1;\n    return x;\n  }\n  static\
    \ X to_y() {\n    X x = unit();\n    x.dy = 1;\n    return x;\n  }\n  static constexpr\
    \ X unit() { return {ARR{}, T(0), T(0)}; }\n  static constexpr bool commute =\
    \ 0;\n};\n#line 5 \"mod/floor_sum_of_linear_polynomial.hpp\"\n\n// \u5168\u90E8\
    \u975E\u8CA0, T \u306F\u7B54, U \u306F ax+b \u304C\u30AA\u30FC\u30D0\u30FC\u30D5\
    \u30ED\u30FC\u3057\u306A\u3044\ntemplate <typename T, int K1, int K2, typename\
    \ U>\narray<array<T, K2 + 1>, K1 + 1> floor_sum_of_linear_polynomial_nonnegative(U\
    \ N, U a, U b, U mod) {\n  static_assert(is_same_v<U, u64> || is_same_v<U, u128>);\n\
    \  assert(a == 0 || N < (U(-1) - b) / a);\n  using Mono = Monoid_for_floor_sum<T,\
    \ K1, K2>;\n  auto x = floor_monoid_product<Mono>(Mono::to_x(), Mono::to_y(),\
    \ N, a, b, mod);\n  return x.dp;\n};\n\n// sum_{L<=x<R} x^i floor(ax+b,mod)^j\n\
    // a+bx \u304C I, U \u3067\u30AA\u30FC\u30D0\u30FC\u30D5\u30ED\u30FC\u3057\u306A\
    \u3044\ntemplate <typename T, int K1, int K2, typename I>\narray<array<T, K2 +\
    \ 1>, K1 + 1> floor_sum_of_linear_polynomial(I L, I R, I a, I b, I mod) {\n  static_assert(is_same_v<I,\
    \ ll> || is_same_v<I, i128>);\n  assert(L <= R && mod > 0);\n  if (a < 0) {\n\
    \    auto ANS = floor_sum_of_linear_polynomial<T, K1, K2, I>(-R + 1, -L + 1, -a,\
    \ b, mod);\n    FOR(i, K1 + 1) {\n      if (i % 2 == 1) { FOR(j, K2 + 1) ANS[i][j]\
    \ = -ANS[i][j]; }\n    }\n    return ANS;\n  }\n  assert(a >= 0);\n  I ADD_X =\
    \ L;\n  I N = R - L;\n  b += a * L;\n  I ADD_Y = floor<I>(b, mod);\n  b -= ADD_Y\
    \ * mod;\n  assert(a >= 0 && b >= 0);\n\n  using Mono = Monoid_for_floor_sum<T,\
    \ K1, K2>;\n  using Data = typename Mono::Data;\n  using U = std::conditional_t<is_same_v<I,\
    \ ll>, u64, u128>;\n  Data A = floor_monoid_product<Mono, Data, U>(Mono::to_x(),\
    \ Mono::to_y(), N, a, b, mod);\n  Data offset = Mono::unit();\n  offset.dx = T(ADD_X),\
    \ offset.dy = T(ADD_Y);\n  A = Mono::op(offset, A);\n  return A.dp;\n};\n#line\
    \ 2 \"poly/fps_div.hpp\"\n\n#line 2 \"poly/count_terms.hpp\"\ntemplate<typename\
    \ mint>\r\nint count_terms(const vc<mint>& f){\r\n  int t = 0;\r\n  FOR(i, len(f))\
    \ if(f[i] != mint(0)) ++t;\r\n  return t;\r\n}\n#line 2 \"mod/modint_common.hpp\"\
    \n\nstruct has_mod_impl {\n  template <class T>\n  static auto check(T &&x) ->\
    \ decltype(x.get_mod(), std::true_type{});\n  template <class T>\n  static auto\
    \ check(...) -> std::false_type;\n};\n\ntemplate <class T>\nclass has_mod : public\
    \ decltype(has_mod_impl::check<T>(std::declval<T>())) {};\n\ntemplate <typename\
    \ mint>\nmint inv(int n) {\n  static const int mod = mint::get_mod();\n  static\
    \ vector<mint> dat = {0, 1};\n  assert(0 <= n);\n  if (n >= mod) n %= mod;\n \
    \ while (len(dat) <= n) {\n    int k = len(dat);\n    int q = (mod + k - 1) /\
    \ k;\n    dat.eb(dat[k * q - mod] * mint::raw(q));\n  }\n  return dat[n];\n}\n\
    \ntemplate <typename mint>\nmint fact(int n) {\n  static const int mod = mint::get_mod();\n\
    \  assert(0 <= n && n < mod);\n  static vector<mint> dat = {1, 1};\n  while (len(dat)\
    \ <= n) dat.eb(dat[len(dat) - 1] * mint::raw(len(dat)));\n  return dat[n];\n}\n\
    \ntemplate <typename mint>\nmint fact_inv(int n) {\n  static vector<mint> dat\
    \ = {1, 1};\n  if (n < 0) return mint(0);\n  while (len(dat) <= n) dat.eb(dat[len(dat)\
    \ - 1] * inv<mint>(len(dat)));\n  return dat[n];\n}\n\ntemplate <class mint, class...\
    \ Ts>\nmint fact_invs(Ts... xs) {\n  return (mint(1) * ... * fact_inv<mint>(xs));\n\
    }\n\ntemplate <typename mint, class Head, class... Tail>\nmint multinomial(Head\
    \ &&head, Tail &&... tail) {\n  return fact<mint>(head) * fact_invs<mint>(std::forward<Tail>(tail)...);\n\
    }\n\ntemplate <typename mint>\nmint C_dense(int n, int k) {\n  assert(n >= 0);\n\
    \  if (k < 0 || n < k) return 0;\n  static vvc<mint> C;\n  static int H = 0, W\
    \ = 0;\n  auto calc = [&](int i, int j) -> mint {\n    if (i == 0) return (j ==\
    \ 0 ? mint(1) : mint(0));\n    return C[i - 1][j] + (j ? C[i - 1][j - 1] : 0);\n\
    \  };\n  if (W <= k) {\n    FOR(i, H) {\n      C[i].resize(k + 1);\n      FOR(j,\
    \ W, k + 1) { C[i][j] = calc(i, j); }\n    }\n    W = k + 1;\n  }\n  if (H <=\
    \ n) {\n    C.resize(n + 1);\n    FOR(i, H, n + 1) {\n      C[i].resize(W);\n\
    \      FOR(j, W) { C[i][j] = calc(i, j); }\n    }\n    H = n + 1;\n  }\n  return\
    \ C[n][k];\n}\n\ntemplate <typename mint, bool large = false, bool dense = false>\n\
    mint C(ll n, ll k) {\n  assert(n >= 0);\n  if (k < 0 || n < k) return 0;\n  if\
    \ constexpr (dense) return C_dense<mint>(n, k);\n  if constexpr (!large) return\
    \ multinomial<mint>(n, k, n - k);\n  k = min(k, n - k);\n  mint x(1);\n  FOR(i,\
    \ k) x *= mint(n - i);\n  return x * fact_inv<mint>(k);\n}\n\ntemplate <typename\
    \ mint, bool large = false>\nmint C_inv(ll n, ll k) {\n  assert(n >= 0);\n  assert(0\
    \ <= k && k <= n);\n  if (!large) return fact_inv<mint>(n) * fact<mint>(k) * fact<mint>(n\
    \ - k);\n  return mint(1) / C<mint, 1>(n, k);\n}\n\n// [x^d](1-x)^{-n}\ntemplate\
    \ <typename mint, bool large = false, bool dense = false>\nmint C_negative(ll\
    \ n, ll d) {\n  assert(n >= 0);\n  if (d < 0) return mint(0);\n  if (n == 0) {\
    \ return (d == 0 ? mint(1) : mint(0)); }\n  return C<mint, large, dense>(n + d\
    \ - 1, d);\n}\n#line 3 \"mod/modint.hpp\"\n\ntemplate <int mod>\nstruct modint\
    \ {\n  static constexpr u32 umod = u32(mod);\n  static_assert(umod < u32(1) <<\
    \ 31);\n  u32 val;\n\n  static modint raw(u32 v) {\n    modint x;\n    x.val =\
    \ v;\n    return x;\n  }\n  constexpr modint() : val(0) {}\n  constexpr modint(u32\
    \ x) : val(x % umod) {}\n  constexpr modint(u64 x) : val(x % umod) {}\n  constexpr\
    \ modint(u128 x) : val(x % umod) {}\n  constexpr modint(int x) : val((x %= mod)\
    \ < 0 ? x + mod : x){};\n  constexpr modint(ll x) : val((x %= mod) < 0 ? x + mod\
    \ : x){};\n  constexpr modint(i128 x) : val((x %= mod) < 0 ? x + mod : x){};\n\
    \  bool operator<(const modint &other) const { return val < other.val; }\n  modint\
    \ &operator+=(const modint &p) {\n    if ((val += p.val) >= umod) val -= umod;\n\
    \    return *this;\n  }\n  modint &operator-=(const modint &p) {\n    if ((val\
    \ += umod - p.val) >= umod) val -= umod;\n    return *this;\n  }\n  modint &operator*=(const\
    \ modint &p) {\n    val = u64(val) * p.val % umod;\n    return *this;\n  }\n \
    \ modint &operator/=(const modint &p) {\n    *this *= p.inverse();\n    return\
    \ *this;\n  }\n  modint operator-() const { return modint::raw(val ? mod - val\
    \ : u32(0)); }\n  modint operator+(const modint &p) const { return modint(*this)\
    \ += p; }\n  modint operator-(const modint &p) const { return modint(*this) -=\
    \ p; }\n  modint operator*(const modint &p) const { return modint(*this) *= p;\
    \ }\n  modint operator/(const modint &p) const { return modint(*this) /= p; }\n\
    \  bool operator==(const modint &p) const { return val == p.val; }\n  bool operator!=(const\
    \ modint &p) const { return val != p.val; }\n  modint inverse() const {\n    int\
    \ a = val, b = mod, u = 1, v = 0, t;\n    while (b > 0) {\n      t = a / b;\n\
    \      swap(a -= t * b, b), swap(u -= t * v, v);\n    }\n    return modint(u);\n\
    \  }\n  modint pow(ll n) const {\n    if (n < 0) return inverse().pow(-n);\n \
    \   assert(n >= 0);\n    modint ret(1), mul(val);\n    while (n > 0) {\n     \
    \ if (n & 1) ret *= mul;\n      mul *= mul;\n      n >>= 1;\n    }\n    return\
    \ ret;\n  }\n  static constexpr int get_mod() { return mod; }\n  // (n, r), r\
    \ \u306F 1 \u306E 2^n \u4E57\u6839\n  static constexpr pair<int, int> ntt_info()\
    \ {\n    if (mod == 120586241) return {20, 74066978};\n    if (mod == 167772161)\
    \ return {25, 17};\n    if (mod == 469762049) return {26, 30};\n    if (mod ==\
    \ 754974721) return {24, 362};\n    if (mod == 880803841) return {23, 211};\n\
    \    if (mod == 943718401) return {22, 663003469};\n    if (mod == 998244353)\
    \ return {23, 31};\n    if (mod == 1004535809) return {21, 582313106};\n    if\
    \ (mod == 1012924417) return {21, 368093570};\n    return {-1, -1};\n  }\n  static\
    \ constexpr bool can_ntt() { return ntt_info().fi != -1; }\n};\n\n#ifdef FASTIO\n\
    template <int mod>\nvoid rd(modint<mod> &x) {\n  fastio::rd(x.val);\n  x.val %=\
    \ mod;\n  // assert(0 <= x.val && x.val < mod);\n}\ntemplate <int mod>\nvoid wt(modint<mod>\
    \ x) {\n  fastio::wt(x.val);\n}\n#endif\n\nusing modint107 = modint<1000000007>;\n\
    using modint998 = modint<998244353>;\n#line 2 \"mod/mod_inv.hpp\"\n\r\n// long\
    \ \u3067\u3082\u5927\u4E08\u592B\r\n// (val * x - 1) \u304C mod \u306E\u500D\u6570\
    \u306B\u306A\u308B\u3088\u3046\u306B\u3059\u308B\r\n// \u7279\u306B mod=0 \u306A\
    \u3089 x=0 \u304C\u6E80\u305F\u3059\r\nll mod_inv(ll val, ll mod) {\r\n  if (mod\
    \ == 0) return 0;\r\n  mod = abs(mod);\r\n  val %= mod;\r\n  if (val < 0) val\
    \ += mod;\r\n  ll a = val, b = mod, u = 1, v = 0, t;\r\n  while (b > 0) {\r\n\
    \    t = a / b;\r\n    swap(a -= t * b, b), swap(u -= t * v, v);\r\n  }\r\n  if\
    \ (u < 0) u += mod;\r\n  return u;\r\n}\r\n#line 2 \"mod/crt3.hpp\"\n\nconstexpr\
    \ u32 mod_pow_constexpr(u64 a, u64 n, u32 mod) {\n  a %= mod;\n  u64 res = 1;\n\
    \  FOR(32) {\n    if (n & 1) res = res * a % mod;\n    a = a * a % mod, n /= 2;\n\
    \  }\n  return res;\n}\n\ntemplate <typename T, u32 p0, u32 p1>\nT CRT2(u64 a0,\
    \ u64 a1) {\n  static_assert(p0 < p1);\n  static constexpr u64 x0_1 = mod_pow_constexpr(p0,\
    \ p1 - 2, p1);\n  u64 c = (a1 - a0 + p1) * x0_1 % p1;\n  return a0 + c * p0;\n\
    }\n\ntemplate <typename T, u32 p0, u32 p1, u32 p2>\nT CRT3(u64 a0, u64 a1, u64\
    \ a2) {\n  static_assert(p0 < p1 && p1 < p2);\n  static constexpr u64 x1 = mod_pow_constexpr(p0,\
    \ p1 - 2, p1);\n  static constexpr u64 x2 = mod_pow_constexpr(u64(p0) * p1 % p2,\
    \ p2 - 2, p2);\n  static constexpr u64 p01 = u64(p0) * p1;\n  u64 c = (a1 - a0\
    \ + p1) * x1 % p1;\n  u64 ans_1 = a0 + c * p0;\n  c = (a2 - ans_1 % p2 + p2) *\
    \ x2 % p2;\n  return T(ans_1) + T(c) * T(p01);\n}\n\ntemplate <typename T, u32\
    \ p0, u32 p1, u32 p2, u32 p3>\nT CRT4(u64 a0, u64 a1, u64 a2, u64 a3) {\n  static_assert(p0\
    \ < p1 && p1 < p2 && p2 < p3);\n  static constexpr u64 x1 = mod_pow_constexpr(p0,\
    \ p1 - 2, p1);\n  static constexpr u64 x2 = mod_pow_constexpr(u64(p0) * p1 % p2,\
    \ p2 - 2, p2);\n  static constexpr u64 x3 = mod_pow_constexpr(u64(p0) * p1 % p3\
    \ * p2 % p3, p3 - 2, p3);\n  static constexpr u64 p01 = u64(p0) * p1;\n  u64 c\
    \ = (a1 - a0 + p1) * x1 % p1;\n  u64 ans_1 = a0 + c * p0;\n  c = (a2 - ans_1 %\
    \ p2 + p2) * x2 % p2;\n  u128 ans_2 = ans_1 + c * static_cast<u128>(p01);\n  c\
    \ = (a3 - ans_2 % p3 + p3) * x3 % p3;\n  return T(ans_2) + T(c) * T(p01) * T(p2);\n\
    }\n\ntemplate <typename T, u32 p0, u32 p1, u32 p2, u32 p3, u32 p4>\nT CRT5(u64\
    \ a0, u64 a1, u64 a2, u64 a3, u64 a4) {\n  static_assert(p0 < p1 && p1 < p2 &&\
    \ p2 < p3 && p3 < p4);\n  static constexpr u64 x1 = mod_pow_constexpr(p0, p1 -\
    \ 2, p1);\n  static constexpr u64 x2 = mod_pow_constexpr(u64(p0) * p1 % p2, p2\
    \ - 2, p2);\n  static constexpr u64 x3 = mod_pow_constexpr(u64(p0) * p1 % p3 *\
    \ p2 % p3, p3 - 2, p3);\n  static constexpr u64 x4 = mod_pow_constexpr(u64(p0)\
    \ * p1 % p4 * p2 % p4 * p3 % p4, p4 - 2, p4);\n  static constexpr u64 p01 = u64(p0)\
    \ * p1;\n  static constexpr u64 p23 = u64(p2) * p3;\n  u64 c = (a1 - a0 + p1)\
    \ * x1 % p1;\n  u64 ans_1 = a0 + c * p0;\n  c = (a2 - ans_1 % p2 + p2) * x2 %\
    \ p2;\n  u128 ans_2 = ans_1 + c * static_cast<u128>(p01);\n  c = static_cast<u64>(a3\
    \ - ans_2 % p3 + p3) * x3 % p3;\n  u128 ans_3 = ans_2 + static_cast<u128>(c *\
    \ p2) * p01;\n  c = static_cast<u64>(a4 - ans_3 % p4 + p4) * x4 % p4;\n  return\
    \ T(ans_3) + T(c) * T(p01) * T(p23);\n}\n#line 2 \"poly/convolution_naive.hpp\"\
    \n\r\ntemplate <class T, typename enable_if<!has_mod<T>::value>::type* = nullptr>\r\
    \nvc<T> convolution_naive(const vc<T>& a, const vc<T>& b) {\r\n  int n = int(a.size()),\
    \ m = int(b.size());\r\n  if (n > m) return convolution_naive<T>(b, a);\r\n  if\
    \ (n == 0) return {};\r\n  vector<T> ans(n + m - 1);\r\n  FOR(i, n) FOR(j, m)\
    \ ans[i + j] += a[i] * b[j];\r\n  return ans;\r\n}\r\n\r\ntemplate <class T, typename\
    \ enable_if<has_mod<T>::value>::type* = nullptr>\r\nvc<T> convolution_naive(const\
    \ vc<T>& a, const vc<T>& b) {\r\n  int n = int(a.size()), m = int(b.size());\r\
    \n  if (n > m) return convolution_naive<T>(b, a);\r\n  if (n == 0) return {};\r\
    \n  vc<T> ans(n + m - 1);\r\n  if (n <= 16 && (T::get_mod() < (1 << 30))) {\r\n\
    \    for (int k = 0; k < n + m - 1; ++k) {\r\n      int s = max(0, k - m + 1);\r\
    \n      int t = min(n, k + 1);\r\n      u64 sm = 0;\r\n      for (int i = s; i\
    \ < t; ++i) { sm += u64(a[i].val) * (b[k - i].val); }\r\n      ans[k] = sm;\r\n\
    \    }\r\n  } else {\r\n    for (int k = 0; k < n + m - 1; ++k) {\r\n      int\
    \ s = max(0, k - m + 1);\r\n      int t = min(n, k + 1);\r\n      u128 sm = 0;\r\
    \n      for (int i = s; i < t; ++i) { sm += u64(a[i].val) * (b[k - i].val); }\r\
    \n      ans[k] = T::raw(sm % T::get_mod());\r\n    }\r\n  }\r\n  return ans;\r\
    \n}\r\n#line 2 \"poly/convolution_karatsuba.hpp\"\n\n// \u4EFB\u610F\u306E\u74B0\
    \u3067\u3067\u304D\u308B\ntemplate <typename T>\nvc<T> convolution_karatsuba(const\
    \ vc<T>& f, const vc<T>& g) {\n  const int thresh = 30;\n  if (min(len(f), len(g))\
    \ <= thresh) return convolution_naive(f, g);\n  int n = max(len(f), len(g));\n\
    \  int m = ceil(n, 2);\n  vc<T> f1, f2, g1, g2;\n  if (len(f) < m) f1 = f;\n \
    \ if (len(f) >= m) f1 = {f.begin(), f.begin() + m};\n  if (len(f) >= m) f2 = {f.begin()\
    \ + m, f.end()};\n  if (len(g) < m) g1 = g;\n  if (len(g) >= m) g1 = {g.begin(),\
    \ g.begin() + m};\n  if (len(g) >= m) g2 = {g.begin() + m, g.end()};\n  vc<T>\
    \ a = convolution_karatsuba(f1, g1);\n  vc<T> b = convolution_karatsuba(f2, g2);\n\
    \  FOR(i, len(f2)) f1[i] += f2[i];\n  FOR(i, len(g2)) g1[i] += g2[i];\n  vc<T>\
    \ c = convolution_karatsuba(f1, g1);\n  vc<T> F(len(f) + len(g) - 1);\n  assert(2\
    \ * m + len(b) <= len(F));\n  FOR(i, len(a)) F[i] += a[i], c[i] -= a[i];\n  FOR(i,\
    \ len(b)) F[2 * m + i] += b[i], c[i] -= b[i];\n  if (c.back() == T(0)) c.pop_back();\n\
    \  FOR(i, len(c)) if (c[i] != T(0)) F[m + i] += c[i];\n  return F;\n}\n#line 2\
    \ \"poly/ntt.hpp\"\n\r\ntemplate <class mint>\r\nvoid ntt(vector<mint>& a, bool\
    \ inverse) {\r\n  assert(mint::can_ntt());\r\n  const int rank2 = mint::ntt_info().fi;\r\
    \n  const int mod = mint::get_mod();\r\n  static array<mint, 30> root, iroot;\r\
    \n  static array<mint, 30> rate2, irate2;\r\n  static array<mint, 30> rate3, irate3;\r\
    \n\r\n  assert(rank2 != -1 && len(a) <= (1 << max(0, rank2)));\r\n\r\n  static\
    \ bool prepared = 0;\r\n  if (!prepared) {\r\n    prepared = 1;\r\n    root[rank2]\
    \ = mint::ntt_info().se;\r\n    iroot[rank2] = mint(1) / root[rank2];\r\n    FOR_R(i,\
    \ rank2) {\r\n      root[i] = root[i + 1] * root[i + 1];\r\n      iroot[i] = iroot[i\
    \ + 1] * iroot[i + 1];\r\n    }\r\n    mint prod = 1, iprod = 1;\r\n    for (int\
    \ i = 0; i <= rank2 - 2; i++) {\r\n      rate2[i] = root[i + 2] * prod;\r\n  \
    \    irate2[i] = iroot[i + 2] * iprod;\r\n      prod *= iroot[i + 2];\r\n    \
    \  iprod *= root[i + 2];\r\n    }\r\n    prod = 1, iprod = 1;\r\n    for (int\
    \ i = 0; i <= rank2 - 3; i++) {\r\n      rate3[i] = root[i + 3] * prod;\r\n  \
    \    irate3[i] = iroot[i + 3] * iprod;\r\n      prod *= iroot[i + 3];\r\n    \
    \  iprod *= root[i + 3];\r\n    }\r\n  }\r\n\r\n  int n = int(a.size());\r\n \
    \ int h = topbit(n);\r\n  assert(n == 1 << h);\r\n  if (!inverse) {\r\n    int\
    \ len = 0;\r\n    while (len < h) {\r\n      if (h - len == 1) {\r\n        int\
    \ p = 1 << (h - len - 1);\r\n        mint rot = 1;\r\n        FOR(s, 1 << len)\
    \ {\r\n          int offset = s << (h - len);\r\n          FOR(i, p) {\r\n   \
    \         auto l = a[i + offset];\r\n            auto r = a[i + offset + p] *\
    \ rot;\r\n            a[i + offset] = l + r;\r\n            a[i + offset + p]\
    \ = l - r;\r\n          }\r\n          rot *= rate2[topbit(~s & -~s)];\r\n   \
    \     }\r\n        len++;\r\n      } else {\r\n        int p = 1 << (h - len -\
    \ 2);\r\n        mint rot = 1, imag = root[2];\r\n        for (int s = 0; s <\
    \ (1 << len); s++) {\r\n          mint rot2 = rot * rot;\r\n          mint rot3\
    \ = rot2 * rot;\r\n          int offset = s << (h - len);\r\n          for (int\
    \ i = 0; i < p; i++) {\r\n            u64 mod2 = u64(mod) * mod;\r\n         \
    \   u64 a0 = a[i + offset].val;\r\n            u64 a1 = u64(a[i + offset + p].val)\
    \ * rot.val;\r\n            u64 a2 = u64(a[i + offset + 2 * p].val) * rot2.val;\r\
    \n            u64 a3 = u64(a[i + offset + 3 * p].val) * rot3.val;\r\n        \
    \    u64 a1na3imag = (a1 + mod2 - a3) % mod * imag.val;\r\n            u64 na2\
    \ = mod2 - a2;\r\n            a[i + offset] = a0 + a2 + a1 + a3;\r\n         \
    \   a[i + offset + 1 * p] = a0 + a2 + (2 * mod2 - (a1 + a3));\r\n            a[i\
    \ + offset + 2 * p] = a0 + na2 + a1na3imag;\r\n            a[i + offset + 3 *\
    \ p] = a0 + na2 + (mod2 - a1na3imag);\r\n          }\r\n          rot *= rate3[topbit(~s\
    \ & -~s)];\r\n        }\r\n        len += 2;\r\n      }\r\n    }\r\n  } else {\r\
    \n    mint coef = mint(1) / mint(len(a));\r\n    FOR(i, len(a)) a[i] *= coef;\r\
    \n    int len = h;\r\n    while (len) {\r\n      if (len == 1) {\r\n        int\
    \ p = 1 << (h - len);\r\n        mint irot = 1;\r\n        FOR(s, 1 << (len -\
    \ 1)) {\r\n          int offset = s << (h - len + 1);\r\n          FOR(i, p) {\r\
    \n            u64 l = a[i + offset].val;\r\n            u64 r = a[i + offset +\
    \ p].val;\r\n            a[i + offset] = l + r;\r\n            a[i + offset +\
    \ p] = (mod + l - r) * irot.val;\r\n          }\r\n          irot *= irate2[topbit(~s\
    \ & -~s)];\r\n        }\r\n        len--;\r\n      } else {\r\n        int p =\
    \ 1 << (h - len);\r\n        mint irot = 1, iimag = iroot[2];\r\n        FOR(s,\
    \ (1 << (len - 2))) {\r\n          mint irot2 = irot * irot;\r\n          mint\
    \ irot3 = irot2 * irot;\r\n          int offset = s << (h - len + 2);\r\n    \
    \      for (int i = 0; i < p; i++) {\r\n            u64 a0 = a[i + offset + 0\
    \ * p].val;\r\n            u64 a1 = a[i + offset + 1 * p].val;\r\n           \
    \ u64 a2 = a[i + offset + 2 * p].val;\r\n            u64 a3 = a[i + offset + 3\
    \ * p].val;\r\n            u64 x = (mod + a2 - a3) * iimag.val % mod;\r\n    \
    \        a[i + offset] = a0 + a1 + a2 + a3;\r\n            a[i + offset + 1 *\
    \ p] = (a0 + mod - a1 + x) * irot.val;\r\n            a[i + offset + 2 * p] =\
    \ (a0 + a1 + 2 * mod - a2 - a3) * irot2.val;\r\n            a[i + offset + 3 *\
    \ p] = (a0 + 2 * mod - a1 - x) * irot3.val;\r\n          }\r\n          irot *=\
    \ irate3[topbit(~s & -~s)];\r\n        }\r\n        len -= 2;\r\n      }\r\n \
    \   }\r\n  }\r\n}\r\n#line 8 \"poly/convolution.hpp\"\n\r\ntemplate <class mint>\r\
    \nvector<mint> convolution_ntt(vector<mint> a, vector<mint> b) {\r\n  if (a.empty()\
    \ || b.empty()) return {};\r\n  int n = int(a.size()), m = int(b.size());\r\n\
    \  int sz = 1;\r\n  while (sz < n + m - 1) sz *= 2;\r\n\r\n  // sz = 2^k \u306E\
    \u3068\u304D\u306E\u9AD8\u901F\u5316\u3002\u5206\u5272\u7D71\u6CBB\u7684\u306A\
    \u3084\u3064\u3067\u640D\u3057\u307E\u304F\u308B\u306E\u3067\u3002\r\n  if ((n\
    \ + m - 3) <= sz / 2) {\r\n    auto a_last = a.back(), b_last = b.back();\r\n\
    \    a.pop_back(), b.pop_back();\r\n    auto c = convolution(a, b);\r\n    c.resize(n\
    \ + m - 1);\r\n    c[n + m - 2] = a_last * b_last;\r\n    FOR(i, len(a)) c[i +\
    \ len(b)] += a[i] * b_last;\r\n    FOR(i, len(b)) c[i + len(a)] += b[i] * a_last;\r\
    \n    return c;\r\n  }\r\n\r\n  a.resize(sz), b.resize(sz);\r\n  bool same = a\
    \ == b;\r\n  ntt(a, 0);\r\n  if (same) {\r\n    b = a;\r\n  } else {\r\n    ntt(b,\
    \ 0);\r\n  }\r\n  FOR(i, sz) a[i] *= b[i];\r\n  ntt(a, 1);\r\n  a.resize(n + m\
    \ - 1);\r\n  return a;\r\n}\r\n\r\ntemplate <typename mint>\r\nvector<mint> convolution_garner(const\
    \ vector<mint>& a, const vector<mint>& b) {\r\n  int n = len(a), m = len(b);\r\
    \n  if (!n || !m) return {};\r\n  static constexpr int p0 = 167772161;\r\n  static\
    \ constexpr int p1 = 469762049;\r\n  static constexpr int p2 = 754974721;\r\n\
    \  using mint0 = modint<p0>;\r\n  using mint1 = modint<p1>;\r\n  using mint2 =\
    \ modint<p2>;\r\n  vc<mint0> a0(n), b0(m);\r\n  vc<mint1> a1(n), b1(m);\r\n  vc<mint2>\
    \ a2(n), b2(m);\r\n  FOR(i, n) a0[i] = a[i].val, a1[i] = a[i].val, a2[i] = a[i].val;\r\
    \n  FOR(i, m) b0[i] = b[i].val, b1[i] = b[i].val, b2[i] = b[i].val;\r\n  auto\
    \ c0 = convolution_ntt<mint0>(a0, b0);\r\n  auto c1 = convolution_ntt<mint1>(a1,\
    \ b1);\r\n  auto c2 = convolution_ntt<mint2>(a2, b2);\r\n  vc<mint> c(len(c0));\r\
    \n  FOR(i, n + m - 1) { c[i] = CRT3<mint, p0, p1, p2>(c0[i].val, c1[i].val, c2[i].val);\
    \ }\r\n  return c;\r\n}\r\n\r\nvector<ll> convolution(vector<ll> a, vector<ll>\
    \ b) {\r\n  int n = len(a), m = len(b);\r\n  if (!n || !m) return {};\r\n  if\
    \ (min(n, m) <= 2500) return convolution_naive(a, b);\r\n\r\n  ll mi_a = MIN(a),\
    \ mi_b = MIN(b);\r\n  for (auto& x: a) x -= mi_a;\r\n  for (auto& x: b) x -= mi_b;\r\
    \n  assert(MAX(a) * MAX(b) <= 1e18);\r\n\r\n  auto Ac = cumsum<ll>(a), Bc = cumsum<ll>(b);\r\
    \n  vi res(n + m - 1);\r\n  for (int k = 0; k < n + m - 1; ++k) {\r\n    int s\
    \ = max(0, k - m + 1);\r\n    int t = min(n, k + 1);\r\n    res[k] += (t - s)\
    \ * mi_a * mi_b;\r\n    res[k] += mi_a * (Bc[k - s + 1] - Bc[k - t + 1]);\r\n\
    \    res[k] += mi_b * (Ac[t] - Ac[s]);\r\n  }\r\n\r\n  static constexpr u32 MOD1\
    \ = 1004535809;\r\n  static constexpr u32 MOD2 = 1012924417;\r\n  using mint1\
    \ = modint<MOD1>;\r\n  using mint2 = modint<MOD2>;\r\n\r\n  vc<mint1> a1(n), b1(m);\r\
    \n  vc<mint2> a2(n), b2(m);\r\n  FOR(i, n) a1[i] = a[i], a2[i] = a[i];\r\n  FOR(i,\
    \ m) b1[i] = b[i], b2[i] = b[i];\r\n\r\n  auto c1 = convolution_ntt<mint1>(a1,\
    \ b1);\r\n  auto c2 = convolution_ntt<mint2>(a2, b2);\r\n\r\n  FOR(i, n + m -\
    \ 1) { res[i] += CRT2<u64, MOD1, MOD2>(c1[i].val, c2[i].val); }\r\n  return res;\r\
    \n}\r\n\r\ntemplate <typename mint>\r\nvc<mint> convolution(const vc<mint>& a,\
    \ const vc<mint>& b) {\r\n  int n = len(a), m = len(b);\r\n  if (!n || !m) return\
    \ {};\r\n  if (mint::can_ntt()) {\r\n    if (min(n, m) <= 50) return convolution_karatsuba<mint>(a,\
    \ b);\r\n    return convolution_ntt(a, b);\r\n  }\r\n  if (min(n, m) <= 200) return\
    \ convolution_karatsuba<mint>(a, b);\r\n  return convolution_garner(a, b);\r\n\
    }\r\n#line 4 \"poly/fps_inv.hpp\"\n\r\ntemplate <typename mint>\r\nvc<mint> fps_inv_sparse(const\
    \ vc<mint>& f) {\r\n  int N = len(f);\r\n  vc<pair<int, mint>> dat;\r\n  FOR(i,\
    \ 1, N) if (f[i] != mint(0)) dat.eb(i, f[i]);\r\n  vc<mint> g(N);\r\n  mint g0\
    \ = mint(1) / f[0];\r\n  g[0] = g0;\r\n  FOR(n, 1, N) {\r\n    mint rhs = 0;\r\
    \n    for (auto&& [k, fk]: dat) {\r\n      if (k > n) break;\r\n      rhs -= fk\
    \ * g[n - k];\r\n    }\r\n    g[n] = rhs * g0;\r\n  }\r\n  return g;\r\n}\r\n\r\
    \ntemplate <typename mint>\r\nvc<mint> fps_inv_dense_ntt(const vc<mint>& F) {\r\
    \n  vc<mint> G = {mint(1) / F[0]};\r\n  ll N = len(F), n = 1;\r\n  G.reserve(N);\r\
    \n  while (n < N) {\r\n    vc<mint> f(2 * n), g(2 * n);\r\n    FOR(i, min(N, 2\
    \ * n)) f[i] = F[i];\r\n    FOR(i, n) g[i] = G[i];\r\n    ntt(f, false), ntt(g,\
    \ false);\r\n    FOR(i, 2 * n) f[i] *= g[i];\r\n    ntt(f, true);\r\n    FOR(i,\
    \ n) f[i] = 0;\r\n    ntt(f, false);\r\n    FOR(i, 2 * n) f[i] *= g[i];\r\n  \
    \  ntt(f, true);\r\n    FOR(i, n, min(N, 2 * n)) G.eb(-f[i]);\r\n    n *= 2;\r\
    \n  }\r\n  return G;\r\n}\r\n\r\ntemplate <typename mint>\r\nvc<mint> fps_inv_dense(const\
    \ vc<mint>& F) {\r\n  if (mint::can_ntt()) return fps_inv_dense_ntt(F);\r\n  const\
    \ int N = len(F);\r\n  vc<mint> R = {mint(1) / F[0]};\r\n  vc<mint> p;\r\n  int\
    \ m = 1;\r\n  while (m < N) {\r\n    p = convolution(R, R);\r\n    p.resize(m\
    \ + m);\r\n    vc<mint> f = {F.begin(), F.begin() + min(m + m, N)};\r\n    p =\
    \ convolution(p, f);\r\n    R.resize(m + m);\r\n    FOR(i, m + m) R[i] = R[i]\
    \ + R[i] - p[i];\r\n    m += m;\r\n  }\r\n  R.resize(N);\r\n  return R;\r\n}\r\
    \n\r\ntemplate <typename mint>\r\nvc<mint> fps_inv(const vc<mint>& f) {\r\n  assert(f[0]\
    \ != mint(0));\r\n  int n = count_terms(f);\r\n  int t = (mint::can_ntt() ? 160\
    \ : 820);\r\n  return (n <= t ? fps_inv_sparse<mint>(f) : fps_inv_dense<mint>(f));\r\
    \n}\r\n#line 5 \"poly/fps_div.hpp\"\n\n// f/g. f \u306E\u9577\u3055\u3067\u51FA\
    \u529B\u3055\u308C\u308B.\ntemplate <typename mint, bool SPARSE = false>\nvc<mint>\
    \ fps_div(vc<mint> f, vc<mint> g) {\n  if (SPARSE || count_terms(g) < 200) return\
    \ fps_div_sparse(f, g);\n  int n = len(f);\n  g.resize(n);\n  g = fps_inv<mint>(g);\n\
    \  f = convolution(f, g);\n  f.resize(n);\n  return f;\n}\n\n// f/g \u305F\u3060\
    \u3057 g \u306F sparse\ntemplate <typename mint>\nvc<mint> fps_div_sparse(vc<mint>\
    \ f, vc<mint>& g) {\n  if (g[0] != mint(1)) {\n    mint cf = g[0].inverse();\n\
    \    for (auto&& x: f) x *= cf;\n    for (auto&& x: g) x *= cf;\n  }\n\n  vc<pair<int,\
    \ mint>> dat;\n  FOR(i, 1, len(g)) if (g[i] != mint(0)) dat.eb(i, -g[i]);\n  FOR(i,\
    \ len(f)) {\n    for (auto&& [j, x]: dat) {\n      if (i >= j) f[i] += x * f[i\
    \ - j];\n    }\n  }\n  return f;\n}\n#line 2 \"nt/primetable.hpp\"\n\ntemplate\
    \ <typename T = int>\nvc<T> primetable(int LIM) {\n  ++LIM;\n  const int S = 32768;\n\
    \  static int done = 2;\n  static vc<T> primes = {2}, sieve(S + 1);\n\n  if (done\
    \ < LIM) {\n    done = LIM;\n\n    primes = {2}, sieve.assign(S + 1, 0);\n   \
    \ const int R = LIM / 2;\n    primes.reserve(int(LIM / log(LIM) * 1.1));\n   \
    \ vc<pair<int, int>> cp;\n    for (int i = 3; i <= S; i += 2) {\n      if (!sieve[i])\
    \ {\n        cp.eb(i, i * i / 2);\n        for (int j = i * i; j <= S; j += 2\
    \ * i) sieve[j] = 1;\n      }\n    }\n    for (int L = 1; L <= R; L += S) {\n\
    \      array<bool, S> block{};\n      for (auto& [p, idx]: cp)\n        for (int\
    \ i = idx; i < S + L; idx = (i += p)) block[i - L] = 1;\n      FOR(i, min(S, R\
    \ - L)) if (!block[i]) primes.eb((L + i) * 2 + 1);\n    }\n  }\n  int k = LB(primes,\
    \ LIM + 1);\n  return {primes.begin(), primes.begin() + k};\n}\n#line 3 \"mod/powertable.hpp\"\
    \n\r\n// a^0, ..., a^N\r\ntemplate <typename mint>\r\nvc<mint> powertable_1(mint\
    \ a, ll N) {\r\n  // table of a^i\r\n  vc<mint> f(N + 1, 1);\r\n  FOR(i, N) f[i\
    \ + 1] = a * f[i];\r\n  return f;\r\n}\r\n\r\n// 0^e, ..., N^e\r\ntemplate <typename\
    \ mint>\r\nvc<mint> powertable_2(ll e, ll N) {\r\n  auto primes = primetable(N);\r\
    \n  vc<mint> f(N + 1, 1);\r\n  f[0] = mint(0).pow(e);\r\n  for (auto&& p: primes)\
    \ {\r\n    if (p > N) break;\r\n    mint xp = mint(p).pow(e);\r\n    ll pp = p;\r\
    \n    while (pp <= N) {\r\n      ll i = pp;\r\n      while (i <= N) {\r\n    \
    \    f[i] *= xp;\r\n        i += pp;\r\n      }\r\n      pp *= p;\r\n    }\r\n\
    \  }\r\n  return f;\r\n}\r\n#line 3 \"seq/famous/bernoulli.hpp\"\n\ntemplate <typename\
    \ mint>\nvc<mint> bernoulli_number(int N) {\n  int n = N / 2;\n  vc<mint> F(n\
    \ + 1), G(n + 1);\n  mint pow = 1;\n  FOR(i, n + 1) {\n    F[i] = fact_inv<mint>(2\
    \ * i) * pow;\n    G[i] = fact_inv<mint>(2 * i + 1) * pow;\n    pow *= inv<mint>(4);\n\
    \  }\n  F = fps_div<mint>(F, G);\n  vc<mint> B(N + 1);\n  if (1 <= N) B[1] = -inv<mint>(2);\n\
    \  FOR(i, n + 1) B[2 * i] = F[i] * fact<mint>(2 * i);\n  return B;\n}\n\ntemplate\
    \ <typename mint>\nmint single_bernoulli(int n) {\n  // https://atcoder.jp/contests/xmascon23/tasks/xmascon23_e\n\
    \  if (n == 0) return 1;\n  if (n == 1) return -inv<mint>(2);\n  /*\n  B_n = [x^n/n!]\
    \ x / (exp(x)-1) = F(1-e^x)\n  F(x) = 1+(1/2)x+(1/3)x^2+...\n  \u3053\u308C\u3092\
    \ x^n \u3067\u6253\u3061\u5207\u308B\n  F(x) = 1+(1/2)x+(1/3)x^2+...+(1/n+1)x^n,\
    \ G(x) = F(1-x)\n  (xF(x)) d/dx = 1-x^{n+1}/1-x\n  ((1-x)G(x)) -d/dx = 1-(1-x)^{n+1}/x\
    \ = H(x)\n  */\n  vc<mint> G(n + 2);\n  mint sm = 0;\n  FOR(i, 1, n + 2) {\n \
    \   mint c = C<mint>(n + 1, i);\n    mint h = (i % 2 == 0 ? c : -c);\n    // H(x)\
    \ = ... gx^{i-1}\n    G[i] = h * inv<mint>(i);\n    sm += inv<mint>(i);\n  }\n\
    \  G[0] = sm;\n  FOR(i, n) G[i + 1] += G[i];\n  vc<mint> pow = powertable_2<mint>(n,\
    \ n);\n  mint ans = 0;\n  FOR(i, n + 1) { ans += pow[i] * G[i]; }\n  return ans;\n\
    }\n#line 2 \"seq/famous/faulhaber.hpp\"\n\n// sum_[1,n]i^k=f(n)\ntemplate <typename\
    \ mint>\nvc<mint> faulhaber_formula(int k) {\n  vc<mint> F = bernoulli_number<mint>(k\
    \ + 1);\n  if (1 <= k) F[1] = inv<mint>(2);\n  reverse(all(F));\n  F[0] = 0;\n\
    \  FOR(r, k + 1) { F[k - r + 1] *= fact<mint>(k) * fact_inv<mint>(r) * fact_inv<mint>(k\
    \ + 1 - r); }\n  return F;\n}\n\n// sum_[1,n]i^k=f(n)\ntemplate <typename mint>\n\
    vvc<mint> faulhaber_formula_2d(int n) {\n  vc<mint> B = bernoulli_number<mint>(n);\n\
    \  if (1 <= n) B[1] = inv<mint>(2);\n  vvc<mint> ANS(n + 1);\n  FOR(k, n + 1)\
    \ {\n    ANS[k].resize(k + 2);\n    FOR(j, k + 1) ANS[k][k + 1 - j] = inv<mint>(k\
    \ + 1) * C<mint>(k + 1, j) * B[j];\n  }\n  return ANS;\n}\n#line 4 \"convex/lattice_point_sum_polynomial.hpp\"\
    \n\n// ax+by<=c \u3068\u3044\u3046\u534A\u5E73\u9762\u305F\u3061. \u975E\u6709\
    \u754C\u306F 0 \u57CB\u3081.\n// \u683C\u5B50\u70B9 (x,y) \u306B\u5BFE\u3057\u3066\
    \ x^iy^j \u306E sum. i<=K1, j<=K2\ntemplate <typename mint, int K1, int K2>\n\
    array<array<mint, K2 + 1>, K1 + 1> lattice_point_sum_polynomial(vc<tuple<ll, ll,\
    \ ll>> LINE) {\n  ll L = -infty<ll>, R = infty<ll>;\n  vc<tuple<ll, ll, ll>> LINE1,\
    \ LINE2;\n  for (auto& [a, b, c]: LINE) {\n    if (b == 0) {\n      assert(a !=\
    \ 0);\n      if (a > 0) { chmin(R, floor<ll>(c, a) + 1); }\n      elif (a < 0)\
    \ { chmax(L, ceil<ll>(-c, -a)); }\n    } else {\n      if (b > 0) { LINE2.eb(-a,\
    \ c, b); }\n      if (b < 0) { LINE1.eb(a, -c, -b); }\n    }\n  }\n  if (L >=\
    \ R) { return {}; }\n  if (LINE1.empty() || LINE2.empty()) return {};\n\n  auto\
    \ LOWER = line_max_function_rational(LINE1, L, R);\n  auto UPPER = line_min_function_rational(LINE2,\
    \ L, R);\n\n  array<array<mint, K2 + 2>, K1 + 1> S;\n  FOR(i, K1 + 1) FOR(j, K2\
    \ + 1) S[i][j] = 0;\n\n  bool bad = 0;\n  auto wk = [&](ll L, ll R, ll a1, ll\
    \ b1, ll c1, ll a2, ll b2, ll c2) -> void {\n    // \u4EA4\u70B9 t/s\n    i128\
    \ s = i128(a2) * c1 - i128(a1) * c2;\n    i128 t = i128(b1) * c2 - i128(b2) *\
    \ c1;\n    if (s == 0) {\n      if (t > 0) return;\n    }\n    if (s > 0) { chmax(L,\
    \ ceil<i128>(t, s)); }\n    if (s < 0) { chmin(R, floor<i128>(-t, -s) + 1); }\n\
    \    if (L >= R) return;\n    if (L == -infty<ll> || R == infty<ll>) {\n     \
    \ bad = 1;\n      return;\n    }\n    auto ADD = floor_sum_of_linear_polynomial<mint,\
    \ K1, K2 + 1, ll>(L, R, a2, b2, c2);\n    auto SUB = floor_sum_of_linear_polynomial<mint,\
    \ K1, K2 + 1, ll>(L, R, a1, b1 - 1, c1);\n    FOR(i, K1 + 1) FOR(j, K2 + 2) S[i][j]\
    \ += ADD[i][j] - SUB[i][j];\n  };\n\n  merge_58(LOWER, UPPER, wk);\n  array<array<mint,\
    \ K2 + 1>, K1 + 1> ANS{};\n  if (bad) return ANS;\n\n  static vvc<mint> CF;\n\
    \  if (CF.empty()) { CF = faulhaber_formula_2d<mint>(K2); }\n  FOR(i, K1 + 1)\
    \ {\n    FOR(j, K2 + 1) {\n      FOR(k, j + 2) { ANS[i][j] += CF[j][k] * S[i][k];\
    \ }\n    }\n  }\n  return ANS;\n}\n#line 8 \"test/1_mytest/lattice_point_sum_polynomial.test.cpp\"\
    \n\nusing mint = modint998;\n\ntemplate <int K1, int K2>\nvoid test() {\n  ll\
    \ N = RNG(0, 7);\n  vc<tuple<ll, ll, ll>> LINE;\n  FOR(N) {\n    while (1) {\n\
    \      ll a = RNG(-3, 4);\n      ll b = RNG(-3, 4);\n      if (a == 0 && b ==\
    \ 0) continue;\n      ll c = RNG(-30, 31);\n      LINE.eb(a, b, c);\n      break;\n\
    \    }\n  }\n\n  array<array<mint, K2 + 1>, K1 + 1> god{};\n  auto add_point =\
    \ [&](ll x, ll y) -> void {\n    FOR(i, K1 + 1) FOR(j, K2 + 1) { god[i][j] +=\
    \ mint(x).pow(i) * mint(y).pow(j); }\n  };\n\n  ll K = 200;\n  FOR(x, -2 * K,\
    \ 2 * K + 1) {\n    ll mi = -infty<ll>, ma = infty<ll>;\n    for (auto& [a, b,\
    \ c]: LINE) {\n      if (b == 0) {\n        // ax>=c\n        if (a * x <= c)\
    \ continue;\n        mi = infty<ll> + 1;\n        break;\n      }\n      if (b\
    \ > 0) { chmin(ma, floor<ll>(c - a * x, b)); }\n      if (b < 0) { chmax(mi, ceil<ll>(a\
    \ * x - c, -b)); }\n    }\n\n    if (mi > ma) continue;\n    if (abs(x) >= K ||\
    \ mi == -infty<ll> || ma == infty<ll>) {\n      FOR(i, K1 + 1) FOR(j, K2 + 1)\
    \ god[i][j] = 0;\n      break;\n    }\n    FOR(y, mi, ma + 1) add_point(x, y);\n\
    \  }\n\n  auto ANS = lattice_point_sum_polynomial<mint, K1, K2>(LINE);\n  assert(god\
    \ == ANS);\n}\n\nvoid solve() {\n  int a, b;\n  cin >> a >> b;\n  cout << a +\
    \ b << \"\\n\";\n}\n\nsigned main() {\n  FOR(1000) {\n    test<0, 0>();\n    test<0,\
    \ 1>();\n    test<0, 2>();\n    test<0, 3>();\n    test<1, 0>();\n    test<1,\
    \ 1>();\n    test<1, 2>();\n    test<1, 3>();\n    test<2, 0>();\n    test<2,\
    \ 1>();\n    test<2, 2>();\n    test<2, 3>();\n    test<3, 0>();\n    test<3,\
    \ 1>();\n    test<3, 2>();\n    test<3, 3>();\n  }\n\n  solve();\n\n  return 0;\n\
    }\n"
  code: "#define PROBLEM \"https://judge.yosupo.jp/problem/aplusb\"\n\n#include \"\
    my_template.hpp\"\n\n#include \"random/base.hpp\"\n#include \"convex/lattice_point_sum_polynomial.hpp\"\
    \n#include \"mod/modint.hpp\"\n\nusing mint = modint998;\n\ntemplate <int K1,\
    \ int K2>\nvoid test() {\n  ll N = RNG(0, 7);\n  vc<tuple<ll, ll, ll>> LINE;\n\
    \  FOR(N) {\n    while (1) {\n      ll a = RNG(-3, 4);\n      ll b = RNG(-3, 4);\n\
    \      if (a == 0 && b == 0) continue;\n      ll c = RNG(-30, 31);\n      LINE.eb(a,\
    \ b, c);\n      break;\n    }\n  }\n\n  array<array<mint, K2 + 1>, K1 + 1> god{};\n\
    \  auto add_point = [&](ll x, ll y) -> void {\n    FOR(i, K1 + 1) FOR(j, K2 +\
    \ 1) { god[i][j] += mint(x).pow(i) * mint(y).pow(j); }\n  };\n\n  ll K = 200;\n\
    \  FOR(x, -2 * K, 2 * K + 1) {\n    ll mi = -infty<ll>, ma = infty<ll>;\n    for\
    \ (auto& [a, b, c]: LINE) {\n      if (b == 0) {\n        // ax>=c\n        if\
    \ (a * x <= c) continue;\n        mi = infty<ll> + 1;\n        break;\n      }\n\
    \      if (b > 0) { chmin(ma, floor<ll>(c - a * x, b)); }\n      if (b < 0) {\
    \ chmax(mi, ceil<ll>(a * x - c, -b)); }\n    }\n\n    if (mi > ma) continue;\n\
    \    if (abs(x) >= K || mi == -infty<ll> || ma == infty<ll>) {\n      FOR(i, K1\
    \ + 1) FOR(j, K2 + 1) god[i][j] = 0;\n      break;\n    }\n    FOR(y, mi, ma +\
    \ 1) add_point(x, y);\n  }\n\n  auto ANS = lattice_point_sum_polynomial<mint,\
    \ K1, K2>(LINE);\n  assert(god == ANS);\n}\n\nvoid solve() {\n  int a, b;\n  cin\
    \ >> a >> b;\n  cout << a + b << \"\\n\";\n}\n\nsigned main() {\n  FOR(1000) {\n\
    \    test<0, 0>();\n    test<0, 1>();\n    test<0, 2>();\n    test<0, 3>();\n\
    \    test<1, 0>();\n    test<1, 1>();\n    test<1, 2>();\n    test<1, 3>();\n\
    \    test<2, 0>();\n    test<2, 1>();\n    test<2, 2>();\n    test<2, 3>();\n\
    \    test<3, 0>();\n    test<3, 1>();\n    test<3, 2>();\n    test<3, 3>();\n\
    \  }\n\n  solve();\n\n  return 0;\n}"
  dependsOn:
  - my_template.hpp
  - random/base.hpp
  - convex/lattice_point_sum_polynomial.hpp
  - convex/line_min_function.hpp
  - geo/convex_hull.hpp
  - geo/base.hpp
  - mod/floor_sum_of_linear_polynomial.hpp
  - mod/floor_monoid_product.hpp
  - alg/monoid_pow.hpp
  - alg/monoid/monoid_for_floor_sum.hpp
  - seq/famous/faulhaber.hpp
  - seq/famous/bernoulli.hpp
  - poly/fps_div.hpp
  - poly/count_terms.hpp
  - poly/fps_inv.hpp
  - poly/convolution.hpp
  - mod/modint.hpp
  - mod/modint_common.hpp
  - mod/mod_inv.hpp
  - mod/crt3.hpp
  - poly/convolution_naive.hpp
  - poly/convolution_karatsuba.hpp
  - poly/ntt.hpp
  - mod/powertable.hpp
  - nt/primetable.hpp
  isVerificationFile: true
  path: test/1_mytest/lattice_point_sum_polynomial.test.cpp
  requiredBy: []
  timestamp: '2025-07-03 18:22:07+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: test/1_mytest/lattice_point_sum_polynomial.test.cpp
layout: document
redirect_from:
- /verify/test/1_mytest/lattice_point_sum_polynomial.test.cpp
- /verify/test/1_mytest/lattice_point_sum_polynomial.test.cpp.html
title: test/1_mytest/lattice_point_sum_polynomial.test.cpp
---
