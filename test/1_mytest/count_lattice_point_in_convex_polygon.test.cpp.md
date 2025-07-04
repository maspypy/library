---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: convex/lattice_point_count.hpp
    title: convex/lattice_point_count.hpp
  - icon: ':heavy_check_mark:'
    path: convex/line_min_function.hpp
    title: convex/line_min_function.hpp
  - icon: ':question:'
    path: geo/base.hpp
    title: geo/base.hpp
  - icon: ':heavy_check_mark:'
    path: geo/convex_hull.hpp
    title: geo/convex_hull.hpp
  - icon: ':heavy_check_mark:'
    path: mod/floor_sum_of_linear.hpp
    title: mod/floor_sum_of_linear.hpp
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
  bundledCode: "#line 1 \"test/1_mytest/count_lattice_point_in_convex_polygon.test.cpp\"\
    \n#define PROBLEM \"https://judge.yosupo.jp/problem/aplusb\"\n\n#line 1 \"my_template.hpp\"\
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
    \ others.begin(), others.end()), ...);\n}\n#endif\n#line 4 \"test/1_mytest/count_lattice_point_in_convex_polygon.test.cpp\"\
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
    \ c1, a2, b2, c2);\n    (r1 < r2 ? i : j)++;\n  }\n}\n#line 2 \"mod/floor_sum_of_linear.hpp\"\
    \n\n// sum_{x in [L,R)} floor(ax + b, mod)\n// I \u306F\u7BC4\u56F2\u5185\u3067\
    \ ax+b \u304C\u30AA\u30FC\u30D0\u30FC\u30D5\u30ED\u30FC\u3057\u306A\u3044\u7A0B\
    \u5EA6\ntemplate <typename O = i128, typename I = long long>\nO floor_sum_of_linear(I\
    \ L, I R, I a, I b, I mod) {\n  assert(L <= R);\n  O res = 0;\n  b += L * a;\n\
    \  I N = R - L;\n\n  if (b < 0) {\n    I k = ceil(-b, mod);\n    b += k * mod;\n\
    \    res -= O(N) * O(k);\n  }\n\n  while (N) {\n    I q;\n    tie(q, a) = divmod(a,\
    \ mod);\n    res += (N & 1 ? O(N) * O((N - 1) / 2) * O(q) : O(N / 2) * O(N - 1)\
    \ * O(q));\n    if (b >= mod) {\n      tie(q, b) = divmod(b, mod);\n      res\
    \ += O(N) * q;\n    }\n    tie(N, b) = divmod(a * N + b, mod);\n    tie(a, mod)\
    \ = mp(mod, a);\n  }\n  return res;\n}\n#line 3 \"convex/lattice_point_count.hpp\"\
    \n\n// ax+by<=c \u3068\u3044\u3046\u534A\u5E73\u9762\u305F\u3061\n// \u6709\u754C\
    \u3067\u306A\u3044\u3068\u304D\u306F 0 \u3092\u8FD4\u3059\n// \uFF08\u683C\u5B50\
    \u70B9\u304C 0 \u500B\u3068\u3044\u3046\u3053\u3068\u306F\u3042\u308B\u306E\u3067\
    \u7B54\u3048\u304C inf \u3068\u306F\u9650\u3089\u306A\u3044\uFF09\n// \u5165\u529B\
    \u304C pow(10,18) \u4EE5\u4E0B\u3068\u304B\u3067\u3042\u308C\u3070\u30AA\u30FC\
    \u30D0\u30FC\u30D5\u30ED\u30FC\u3057\u306A\u3044\u3064\u3082\u308A\ni128 lattice_point_count(vc<tuple<ll,\
    \ ll, ll>> LINE) {\n  ll L = -infty<ll>, R = infty<ll>;\n  vc<tuple<ll, ll, ll>>\
    \ LINE1, LINE2;\n  for (auto& [a, b, c]: LINE) {\n    if (b == 0) {\n      assert(a\
    \ != 0);\n      if (a > 0) { chmin(R, floor<ll>(c, a) + 1); }\n      elif (a <\
    \ 0) { chmax(L, ceil<ll>(-c, -a)); }\n    } else {\n      if (b > 0) { LINE2.eb(-a,\
    \ c, b); }\n      if (b < 0) { LINE1.eb(a, -c, -b); }\n    }\n  }\n  if (L >=\
    \ R) return 0;\n  if (LINE1.empty() || LINE2.empty()) return 0;\n\n  auto LOWER\
    \ = line_max_function_rational(LINE1, L, R);\n  auto UPPER = line_min_function_rational(LINE2,\
    \ L, R);\n\n  i128 ANS = 0;\n\n  bool bad = 0;\n  auto wk = [&](ll L, ll R, ll\
    \ a1, ll b1, ll c1, ll a2, ll b2, ll c2) -> void {\n    // \u4EA4\u70B9 t/s\n\
    \    i128 s = i128(a2) * c1 - i128(a1) * c2;\n    i128 t = i128(b1) * c2 - i128(b2)\
    \ * c1;\n    if (s == 0) {\n      if (t > 0) return;\n    }\n    if (s > 0) {\
    \ chmax(L, ceil<i128>(t, s)); }\n    if (s < 0) { chmin(R, floor<i128>(-t, -s)\
    \ + 1); }\n    if (L >= R) return;\n    if (L == -infty<ll> || R == infty<ll>)\
    \ {\n      bad = 1;\n      return;\n    }\n    ANS += floor_sum_of_linear<i128,\
    \ i128>(L, R, a2, b2, c2);\n    ANS -= floor_sum_of_linear<i128, i128>(L, R, a1,\
    \ b1 - 1, c1);\n  };\n\n  merge_58(LOWER, UPPER, wk);\n  if (bad) return 0;\n\
    \  return ANS;\n}\n#line 7 \"test/1_mytest/count_lattice_point_in_convex_polygon.test.cpp\"\
    \n\nvoid test() {\n  ll N = RNG(0, 7);\n\n  vc<tuple<ll, ll, ll>> LINE;\n  FOR(N)\
    \ {\n    while (1) {\n      ll a = RNG(-3, 4);\n      ll b = RNG(-3, 4);\n   \
    \   if (a == 0 && b == 0) continue;\n      ll c = RNG(-30, 31);\n      LINE.eb(a,\
    \ b, c);\n      break;\n    }\n  }\n\n  ll K = 200;\n  ll god = 0;\n  FOR(x, -2\
    \ * K, 2 * K + 1) {\n    ll mi = -infty<ll>, ma = infty<ll>;\n    for (auto& [a,\
    \ b, c]: LINE) {\n      if (b == 0) {\n        if (a * x <= c) continue;\n   \
    \     mi = infty<ll> + 1;\n        break;\n      }\n      if (b > 0) { chmin(ma,\
    \ floor<ll>(c - a * x, b)); }\n      if (b < 0) { chmax(mi, ceil<ll>(a * x - c,\
    \ -b)); }\n    }\n\n    if (mi > ma) continue;\n    if (abs(x) >= K || mi == -infty<ll>\
    \ || ma == infty<ll>) {\n      god = 0;\n      break;\n    }\n    god += ma -\
    \ mi + 1;\n  }\n\n  ll ANS = lattice_point_count(LINE);\n  assert(god == ANS);\n\
    }\n\nvoid solve() {\n  int a, b;\n  cin >> a >> b;\n  cout << a + b << \"\\n\"\
    ;\n}\n\nsigned main() {\n  FOR(100000) test();\n\n  solve();\n\n  return 0;\n\
    }\n"
  code: "#define PROBLEM \"https://judge.yosupo.jp/problem/aplusb\"\n\n#include \"\
    my_template.hpp\"\n\n#include \"random/base.hpp\"\n#include \"convex/lattice_point_count.hpp\"\
    \n\nvoid test() {\n  ll N = RNG(0, 7);\n\n  vc<tuple<ll, ll, ll>> LINE;\n  FOR(N)\
    \ {\n    while (1) {\n      ll a = RNG(-3, 4);\n      ll b = RNG(-3, 4);\n   \
    \   if (a == 0 && b == 0) continue;\n      ll c = RNG(-30, 31);\n      LINE.eb(a,\
    \ b, c);\n      break;\n    }\n  }\n\n  ll K = 200;\n  ll god = 0;\n  FOR(x, -2\
    \ * K, 2 * K + 1) {\n    ll mi = -infty<ll>, ma = infty<ll>;\n    for (auto& [a,\
    \ b, c]: LINE) {\n      if (b == 0) {\n        if (a * x <= c) continue;\n   \
    \     mi = infty<ll> + 1;\n        break;\n      }\n      if (b > 0) { chmin(ma,\
    \ floor<ll>(c - a * x, b)); }\n      if (b < 0) { chmax(mi, ceil<ll>(a * x - c,\
    \ -b)); }\n    }\n\n    if (mi > ma) continue;\n    if (abs(x) >= K || mi == -infty<ll>\
    \ || ma == infty<ll>) {\n      god = 0;\n      break;\n    }\n    god += ma -\
    \ mi + 1;\n  }\n\n  ll ANS = lattice_point_count(LINE);\n  assert(god == ANS);\n\
    }\n\nvoid solve() {\n  int a, b;\n  cin >> a >> b;\n  cout << a + b << \"\\n\"\
    ;\n}\n\nsigned main() {\n  FOR(100000) test();\n\n  solve();\n\n  return 0;\n}"
  dependsOn:
  - my_template.hpp
  - random/base.hpp
  - convex/lattice_point_count.hpp
  - convex/line_min_function.hpp
  - geo/convex_hull.hpp
  - geo/base.hpp
  - mod/floor_sum_of_linear.hpp
  isVerificationFile: true
  path: test/1_mytest/count_lattice_point_in_convex_polygon.test.cpp
  requiredBy: []
  timestamp: '2025-07-03 18:22:07+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: test/1_mytest/count_lattice_point_in_convex_polygon.test.cpp
layout: document
redirect_from:
- /verify/test/1_mytest/count_lattice_point_in_convex_polygon.test.cpp
- /verify/test/1_mytest/count_lattice_point_in_convex_polygon.test.cpp.html
title: test/1_mytest/count_lattice_point_in_convex_polygon.test.cpp
---
