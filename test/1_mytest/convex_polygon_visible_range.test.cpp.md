---
data:
  _extendedDependsOn:
  - icon: ':question:'
    path: geo/base.hpp
    title: geo/base.hpp
  - icon: ':question:'
    path: geo/convex_hull.hpp
    title: geo/convex_hull.hpp
  - icon: ':question:'
    path: geo/convex_polygon.hpp
    title: geo/convex_polygon.hpp
  - icon: ':question:'
    path: geo/incremental_convex_hull.hpp
    title: geo/incremental_convex_hull.hpp
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
  bundledCode: "#line 1 \"test/1_mytest/convex_polygon_visible_range.test.cpp\"\n\
    #define PROBLEM \"https://judge.yosupo.jp/problem/aplusb\"\n#line 1 \"my_template.hpp\"\
    \n#if defined(USE_PCH)\n#include <my_template_compiled.hpp>\n#else\n#if defined(__GNUC__)\n\
    #include <bits/allocator.h>\n#pragma GCC optimize(\"Ofast,unroll-loops\")\n//\
    \ \u74B0\u5883\u306B\u3088\u3063\u3066\u306F\u30B3\u30F3\u30D1\u30A4\u30EB\u6210\
    \u529F\u304B\u3064\u5B9F\u884C\u6642\u30A8\u30E9\u30FC\n#pragma GCC target(\"\
    avx2,popcnt\")\n#endif\n#include <bits/stdc++.h>\n#include <cassert>\n\nusing\
    \ namespace std;\n\nusing ll = long long;\nusing u8 = uint8_t;\nusing u16 = uint16_t;\n\
    using u32 = uint32_t;\nusing u64 = uint64_t;\nusing i128 = __int128;\nusing u128\
    \ = unsigned __int128;\nusing f128 = __float128;\n\ntemplate <class>\nconstexpr\
    \ bool dependent_false = false;\n\ntemplate <class T>\nconstexpr T infty = []\
    \ {\n  static_assert(dependent_false<T>, \"infty<T> is not defined\");\n  return\
    \ T{};\n}();\ntemplate <>\nconstexpr int infty<int> = 1'010'000'000;\ntemplate\
    \ <>\nconstexpr ll infty<ll> = 2'020'000'000'000'000'000;\ntemplate <>\nconstexpr\
    \ u32 infty<u32> = infty<int>;\ntemplate <>\nconstexpr u64 infty<u64> = infty<ll>;\n\
    template <>\nconstexpr i128 infty<i128> = i128(infty<ll>) * 2'000'000'000'000'000'000;\n\
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
    \ ++i)\n#define FOR3(i, a, b) for (ll i = a; i < ll(b); ++i)\n#define FOR1_R(a)\
    \ for (ll i = ll(a) - 1; i >= ll(0); --i)\n#define FOR2_R(i, a) for (ll i = ll(a)\
    \ - 1; i >= ll(0); --i)\n#define FOR3_R(i, a, b) for (ll i = ll(b) - 1; i >= ll(a);\
    \ --i)\n#define overload3(a, b, c, d, ...) d\n#define FOR(...) overload3(__VA_ARGS__,\
    \ FOR3, FOR2, FOR1)(__VA_ARGS__)\n#define FOR_R(...) overload3(__VA_ARGS__, FOR3_R,\
    \ FOR2_R, FOR1_R)(__VA_ARGS__)\n\n#define all(x) (x).begin(), (x).end()\n#define\
    \ len(x) ll(x.size())\n#define elif else if\n\n#define eb emplace_back\n#define\
    \ mp make_pair\n#define mt make_tuple\n#define fi first\n#define se second\n\n\
    #define stoi stoll\n\n// require y > 0\ntemplate <typename T>\nT floor(T x, T\
    \ y) {\n  return x / y - (x % y < 0);\n}\n\n// require y > 0\ntemplate <typename\
    \ T>\nT ceil(T x, T y) {\n  return (x / y) + (x % y > 0);\n}\n\n// require y >\
    \ 0\ntemplate <typename T>\nT bmod(T x, T y) {\n  T r = x % y;\n  return (r <\
    \ 0 ? r + y : r);\n}\n\n// require y > 0\ntemplate <typename T>\npair<T, T> divmod(T\
    \ x, T y) {\n  T q = x / y, r = x % y;\n  if (r < 0) --q, r += y;\n  return {q,\
    \ r};\n}\n\nconstexpr auto TEN = [] {\n  array<u64, 20> A{};\n  A[0] = 1;\n  for\
    \ (int i = 1; i < 20; ++i) A[i] = 10 * A[i - 1];\n  return A;\n}();\n\ntemplate\
    \ <typename T, typename U>\nT SUM(const U &A) {\n  return std::accumulate(A.begin(),\
    \ A.end(), T{});\n}\n\n#define MIN(v) *min_element(all(v))\n#define MAX(v) *max_element(all(v))\n\
    template <class C, class T>\ninline long long LB(const C &c, const T &x) {\n \
    \ return lower_bound(c.begin(), c.end(), x) - c.begin();\n}\ntemplate <class C,\
    \ class T>\ninline long long UB(const C &c, const T &x) {\n  return upper_bound(c.begin(),\
    \ c.end(), x) - c.begin();\n}\n#define UNIQUE(x) sort(all(x)), x.erase(unique(all(x)),\
    \ x.end())\n\ntemplate <typename T>\nT POP(deque<T> &que) {\n  T a = que.front();\n\
    \  que.pop_front();\n  return a;\n}\ntemplate <class T, class Container, class\
    \ Compare>\nT POP(priority_queue<T, Container, Compare> &que) {\n  T a = que.top();\n\
    \  que.pop();\n  return a;\n}\ntemplate <typename T>\nT POP(vc<T> &que) {\n  T\
    \ a = que.back();\n  que.pop_back();\n  return a;\n}\n\ntemplate <typename F>\n\
    i128 binary_search(F check, i128 ok, i128 ng, bool check_ok = true) {\n  if (check_ok)\
    \ assert(check(ok));\n  while (1) {\n    i128 x = (ok + ng) / 2;\n    if (x ==\
    \ ok || x == ng) break;\n    (check(x) ? ok : ng) = x;\n  }\n  return ok;\n}\n\
    \ntemplate <typename F>\ndouble binary_search_real(F check, double ok, double\
    \ ng, int iter = 100) {\n  FOR(iter) {\n    double x = (ok + ng) / 2;\n    (check(x)\
    \ ? ok : ng) = x;\n  }\n  return (ok + ng) / 2;\n}\n\ntemplate <class T, class\
    \ S>\ninline bool chmax(T &a, const S &b) {\n  T c = max<T>(a, b);\n  bool changed\
    \ = (c != a);\n  a = c;\n  return changed;\n}\ntemplate <class T, class S>\ninline\
    \ bool chmin(T &a, const S &b) {\n  T c = min<T>(a, b);\n  bool changed = (c !=\
    \ a);\n  a = c;\n  return changed;\n}\n\n// ? \u306F -1\nvc<int> s_to_vi(const\
    \ string &S, char first_char) {\n  vc<int> A(S.size());\n  FOR(i, S.size()) {\
    \ A[i] = (S[i] != '?' ? S[i] - first_char : -1); }\n  return A;\n}\n\ntemplate\
    \ <typename T, typename U>\nvc<T> cumsum(const vc<U> &A, int off = 1) {\n  int\
    \ N = A.size();\n  vc<T> B(N + 1);\n  FOR(i, N) { B[i + 1] = B[i] + A[i]; }\n\
    \  if (off == 0) B.erase(B.begin());\n  return B;\n}\n\n// stable sort\ntemplate\
    \ <typename T>\nvc<int> argsort(const vc<T> &A) {\n  vc<int> ids(len(A));\n  iota(all(ids),\
    \ 0);\n  sort(all(ids),\n      [&](int i, int j) { return (A[i] == A[j] ? i <\
    \ j : A[i] < A[j]); });\n  return ids;\n}\n\n// A[I[0]], A[I[1]], ...\ntemplate\
    \ <typename T>\nvc<T> rearrange(const vc<T> &A, const vc<int> &I) {\n  vc<T> B(len(I));\n\
    \  FOR(i, len(I)) B[i] = A[I[i]];\n  return B;\n}\n\ntemplate <typename T, typename...\
    \ Vectors>\nvoid concat(vc<T> &first, const Vectors &...others) {\n  first.reserve(first.size()\
    \ + (others.size() + ... + 0));\n  (first.insert(first.end(), others.begin(),\
    \ others.end()), ...);\n}\n\n// i128\ntemplate <class T, enable_if_t<is_same_v<T,\
    \ i128>, int> = 0>\nconstexpr i128 abs(T x) {\n  return x < 0 ? -x : x;\n}\n\n\
    constexpr i128 gcd(i128 a, i128 b) {\n  while (b != 0) {\n    i128 c = a % b;\n\
    \    a = b, b = c;\n  }\n  return abs(a);\n}\n#endif\n#line 3 \"test/1_mytest/convex_polygon_visible_range.test.cpp\"\
    \n\n#line 1 \"geo/base.hpp\"\ntemplate <typename T>\nstruct Point {\n  T x, y;\n\
    \n  Point() : x(0), y(0) {}\n\n  template <typename A, typename B>\n  Point(A\
    \ x, B y) : x(x), y(y) {}\n\n  template <typename A, typename B>\n  Point(pair<A,\
    \ B> p) : x(p.fi), y(p.se) {}\n\n  template <typename U>\n  Point(Point<U> p)\
    \ : x(p.x), y(p.y) {\n    static_assert(!is_integral_v<T> || is_integral_v<U>);\n\
    \  }\n\n  Point operator+=(const Point p) {\n    x += p.x, y += p.y;\n    return\
    \ *this;\n  }\n  Point operator-=(const Point p) {\n    x -= p.x, y -= p.y;\n\
    \    return *this;\n  }\n  Point operator+(Point p) const { return {x + p.x, y\
    \ + p.y}; }\n  Point operator-(Point p) const { return {x - p.x, y - p.y}; }\n\
    \  bool operator==(Point p) const { return x == p.x && y == p.y; }\n  bool operator!=(Point\
    \ p) const { return x != p.x || y != p.y; }\n  Point operator-() const { return\
    \ {-x, -y}; }\n  Point operator*(T t) const { return {x * t, y * t}; }\n  Point\
    \ operator/(T t) const { return {x / t, y / t}; }\n\n  bool operator<(Point p)\
    \ const {\n    if (x != p.x) return x < p.x;\n    return y < p.y;\n  }\n  T dot(const\
    \ Point& other) const { return x * other.x + y * other.y; }\n  T det(const Point&\
    \ other) const { return x * other.y - y * other.x; }\n\n  double norm() { return\
    \ sqrtl(x * x + y * y); }\n  double angle() { return atan2(y, x); }\n\n  Point\
    \ rotate(double theta) {\n    static_assert(!is_integral<T>::value);\n    double\
    \ c = cos(theta), s = sin(theta);\n    return Point{c * x - s * y, s * x + c *\
    \ y};\n  }\n  Point rot90(bool ccw) { return (ccw ? Point{-y, x} : Point{y, -x});\
    \ }\n};\n\n#ifdef FASTIO\ntemplate <typename T>\nvoid rd(Point<T>& p) {\n  fastio::rd(p.x),\
    \ fastio::rd(p.y);\n}\ntemplate <typename T>\nvoid wt(Point<T>& p) {\n  fastio::wt(p.x);\n\
    \  fastio::wt(' ');\n  fastio::wt(p.y);\n}\n#endif\n\n// A -> B -> C \u3068\u9032\
    \u3080\u3068\u304D\u306B\u3001\u5DE6\u306B\u66F2\u304C\u308B\u306A\u3089\u3070\
    \ +1\u3001\u53F3\u306B\u66F2\u304C\u308B\u306A\u3089\u3070 -1\ntemplate <typename\
    \ T>\nint ccw(Point<T> A, Point<T> B, Point<T> C) {\n  T x = (B - A).det(C - A);\n\
    \  if (x > 0) return 1;\n  if (x < 0) return -1;\n  return 0;\n}\n\ntemplate <typename\
    \ REAL, typename T, typename U>\nREAL distance(Point<T> A, Point<U> B) {\n  REAL\
    \ dx = REAL(A.x) - REAL(B.x);\n  REAL dy = REAL(A.y) - REAL(B.y);\n  return sqrt(dx\
    \ * dx + dy * dy);\n}\n\n// ax+by+c\ntemplate <typename T>\nstruct Line {\n  T\
    \ a, b, c;\n\n  Line(T a, T b, T c) : a(a), b(b), c(c) {}\n  Line(Point<T> A,\
    \ Point<T> B) {\n    a = A.y - B.y, b = B.x - A.x, c = A.x * B.y - A.y * B.x;\n\
    \  }\n  Line(T x1, T y1, T x2, T y2) : Line(Point<T>(x1, y1), Point<T>(x2, y2))\
    \ {}\n\n  template <typename U>\n  U eval(Point<U> P) {\n    return U(a) * P.x\
    \ + U(b) * P.y + U(c);\n  }\n\n  template <typename U>\n  T eval(U x, U y) {\n\
    \    return a * x + b * y + c;\n  }\n\n  // \u540C\u3058\u76F4\u7DDA\u304C\u540C\
    \u3058 a,b,c \u3067\u8868\u73FE\u3055\u308C\u308B\u3088\u3046\u306B\u3059\u308B\
    \n  void normalize() {\n    static_assert(is_same_v<T, int> || is_same_v<T, long\
    \ long>);\n    T g = gcd(gcd(abs(a), abs(b)), abs(c));\n    a /= g, b /= g, c\
    \ /= g;\n    if (b < 0) {\n      a = -a, b = -b, c = -c;\n    }\n    if (b ==\
    \ 0 && a < 0) {\n      a = -a, b = -b, c = -c;\n    }\n  }\n\n  bool is_parallel(Line\
    \ other) { return a * other.b - b * other.a == 0; }\n  bool is_orthogonal(Line\
    \ other) { return a * other.a + b * other.b == 0; }\n  bool is_same(Line other)\
    \ {\n    if (a * other.b != b * other.a) return 0;\n    if (a * other.c != c *\
    \ other.a) return 0;\n    if (b * other.c != c * other.b) return 0;\n    return\
    \ 1;\n  }\n};\n\ntemplate <typename T>\nstruct Segment {\n  Point<T> A, B;\n\n\
    \  Segment(Point<T> A, Point<T> B) : A(A), B(B) {}\n  Segment(T x1, T y1, T x2,\
    \ T y2)\n      : Segment(Point<T>(x1, y1), Point<T>(x2, y2)) {}\n\n  bool contain(Point<T>\
    \ C) {\n    T det = (C - A).det(B - A);\n    if (det != 0) return 0;\n    return\
    \ (C - A).dot(B - A) >= 0 && (C - B).dot(A - B) >= 0;\n  }\n\n  Line<T> to_line()\
    \ { return Line(A, B); }\n};\n\ntemplate <typename REAL>\nstruct Circle {\n  Point<REAL>\
    \ O;\n  REAL r;\n  Circle() {}\n  Circle(Point<REAL> O, REAL r) : O(O), r(r) {}\n\
    \  Circle(REAL x, REAL y, REAL r) : O(x, y), r(r) {}\n  template <typename T>\n\
    \  bool contain(Point<T> p) {\n    REAL dx = p.x - O.x, dy = p.y - O.y;\n    return\
    \ dx * dx + dy * dy <= r * r;\n  }\n};\n#line 1 \"geo/convex_hull.hpp\"\n\n#line\
    \ 1 \"geo/base.hpp\"\ntemplate <typename T>\nstruct Point {\n  T x, y;\n\n  Point()\
    \ : x(0), y(0) {}\n\n  template <typename A, typename B>\n  Point(A x, B y) :\
    \ x(x), y(y) {}\n\n  template <typename A, typename B>\n  Point(pair<A, B> p)\
    \ : x(p.fi), y(p.se) {}\n\n  template <typename U>\n  Point(Point<U> p) : x(p.x),\
    \ y(p.y) {\n    static_assert(!is_integral_v<T> || is_integral_v<U>);\n  }\n\n\
    \  Point operator+=(const Point p) {\n    x += p.x, y += p.y;\n    return *this;\n\
    \  }\n  Point operator-=(const Point p) {\n    x -= p.x, y -= p.y;\n    return\
    \ *this;\n  }\n  Point operator+(Point p) const { return {x + p.x, y + p.y}; }\n\
    \  Point operator-(Point p) const { return {x - p.x, y - p.y}; }\n  bool operator==(Point\
    \ p) const { return x == p.x && y == p.y; }\n  bool operator!=(Point p) const\
    \ { return x != p.x || y != p.y; }\n  Point operator-() const { return {-x, -y};\
    \ }\n  Point operator*(T t) const { return {x * t, y * t}; }\n  Point operator/(T\
    \ t) const { return {x / t, y / t}; }\n\n  bool operator<(Point p) const {\n \
    \   if (x != p.x) return x < p.x;\n    return y < p.y;\n  }\n  T dot(const Point&\
    \ other) const { return x * other.x + y * other.y; }\n  T det(const Point& other)\
    \ const { return x * other.y - y * other.x; }\n\n  double norm() { return sqrtl(x\
    \ * x + y * y); }\n  double angle() { return atan2(y, x); }\n\n  Point rotate(double\
    \ theta) {\n    static_assert(!is_integral<T>::value);\n    double c = cos(theta),\
    \ s = sin(theta);\n    return Point{c * x - s * y, s * x + c * y};\n  }\n  Point\
    \ rot90(bool ccw) { return (ccw ? Point{-y, x} : Point{y, -x}); }\n};\n\n#ifdef\
    \ FASTIO\ntemplate <typename T>\nvoid rd(Point<T>& p) {\n  fastio::rd(p.x), fastio::rd(p.y);\n\
    }\ntemplate <typename T>\nvoid wt(Point<T>& p) {\n  fastio::wt(p.x);\n  fastio::wt('\
    \ ');\n  fastio::wt(p.y);\n}\n#endif\n\n// A -> B -> C \u3068\u9032\u3080\u3068\
    \u304D\u306B\u3001\u5DE6\u306B\u66F2\u304C\u308B\u306A\u3089\u3070 +1\u3001\u53F3\
    \u306B\u66F2\u304C\u308B\u306A\u3089\u3070 -1\ntemplate <typename T>\nint ccw(Point<T>\
    \ A, Point<T> B, Point<T> C) {\n  T x = (B - A).det(C - A);\n  if (x > 0) return\
    \ 1;\n  if (x < 0) return -1;\n  return 0;\n}\n\ntemplate <typename REAL, typename\
    \ T, typename U>\nREAL distance(Point<T> A, Point<U> B) {\n  REAL dx = REAL(A.x)\
    \ - REAL(B.x);\n  REAL dy = REAL(A.y) - REAL(B.y);\n  return sqrt(dx * dx + dy\
    \ * dy);\n}\n\n// ax+by+c\ntemplate <typename T>\nstruct Line {\n  T a, b, c;\n\
    \n  Line(T a, T b, T c) : a(a), b(b), c(c) {}\n  Line(Point<T> A, Point<T> B)\
    \ {\n    a = A.y - B.y, b = B.x - A.x, c = A.x * B.y - A.y * B.x;\n  }\n  Line(T\
    \ x1, T y1, T x2, T y2) : Line(Point<T>(x1, y1), Point<T>(x2, y2)) {}\n\n  template\
    \ <typename U>\n  U eval(Point<U> P) {\n    return U(a) * P.x + U(b) * P.y + U(c);\n\
    \  }\n\n  template <typename U>\n  T eval(U x, U y) {\n    return a * x + b *\
    \ y + c;\n  }\n\n  // \u540C\u3058\u76F4\u7DDA\u304C\u540C\u3058 a,b,c \u3067\u8868\
    \u73FE\u3055\u308C\u308B\u3088\u3046\u306B\u3059\u308B\n  void normalize() {\n\
    \    static_assert(is_same_v<T, int> || is_same_v<T, long long>);\n    T g = gcd(gcd(abs(a),\
    \ abs(b)), abs(c));\n    a /= g, b /= g, c /= g;\n    if (b < 0) {\n      a =\
    \ -a, b = -b, c = -c;\n    }\n    if (b == 0 && a < 0) {\n      a = -a, b = -b,\
    \ c = -c;\n    }\n  }\n\n  bool is_parallel(Line other) { return a * other.b -\
    \ b * other.a == 0; }\n  bool is_orthogonal(Line other) { return a * other.a +\
    \ b * other.b == 0; }\n  bool is_same(Line other) {\n    if (a * other.b != b\
    \ * other.a) return 0;\n    if (a * other.c != c * other.a) return 0;\n    if\
    \ (b * other.c != c * other.b) return 0;\n    return 1;\n  }\n};\n\ntemplate <typename\
    \ T>\nstruct Segment {\n  Point<T> A, B;\n\n  Segment(Point<T> A, Point<T> B)\
    \ : A(A), B(B) {}\n  Segment(T x1, T y1, T x2, T y2)\n      : Segment(Point<T>(x1,\
    \ y1), Point<T>(x2, y2)) {}\n\n  bool contain(Point<T> C) {\n    T det = (C -\
    \ A).det(B - A);\n    if (det != 0) return 0;\n    return (C - A).dot(B - A) >=\
    \ 0 && (C - B).dot(A - B) >= 0;\n  }\n\n  Line<T> to_line() { return Line(A, B);\
    \ }\n};\n\ntemplate <typename REAL>\nstruct Circle {\n  Point<REAL> O;\n  REAL\
    \ r;\n  Circle() {}\n  Circle(Point<REAL> O, REAL r) : O(O), r(r) {}\n  Circle(REAL\
    \ x, REAL y, REAL r) : O(x, y), r(r) {}\n  template <typename T>\n  bool contain(Point<T>\
    \ p) {\n    REAL dx = p.x - O.x, dy = p.y - O.y;\n    return dx * dx + dy * dy\
    \ <= r * r;\n  }\n};\n#line 3 \"geo/convex_hull.hpp\"\n\n// allow_180=true \u3067\
    \u540C\u4E00\u5EA7\u6A19\u70B9\u304C\u3042\u308B\u3068\u3053\u308F\u308C\u308B\
    \n// full \u306A\u3089 I[0] \u304C sorted \u3067 min \u306B\u306A\u308B\ntemplate\
    \ <typename T, bool allow_180 = false>\nvector<int> convex_hull(vector<Point<T>>&\
    \ XY, string mode = \"full\",\n                        bool sorted = false) {\n\
    \  assert(mode == \"full\" || mode == \"lower\" || mode == \"upper\");\n  ll N\
    \ = XY.size();\n  if (N == 1) return {0};\n  if (N == 2) {\n    if (XY[0] < XY[1])\
    \ return {0, 1};\n    if (XY[1] < XY[0]) return {1, 0};\n    return {0};\n  }\n\
    \  vc<int> I(N);\n  if (sorted) {\n    FOR(i, N) I[i] = i;\n  } else {\n    I\
    \ = argsort(XY);\n  }\n  if constexpr (allow_180) {\n    FOR(i, N - 1) assert(XY[i]\
    \ != XY[i + 1]);\n  }\n\n  auto check = [&](ll i, ll j, ll k) -> bool {\n    T\
    \ det = (XY[j] - XY[i]).det(XY[k] - XY[i]);\n    if constexpr (allow_180) return\
    \ det >= 0;\n    return det > T(0);\n  };\n\n  auto calc = [&]() {\n    vector<int>\
    \ P;\n    for (auto&& k : I) {\n      while (P.size() > 1) {\n        auto i =\
    \ P[P.size() - 2];\n        auto j = P[P.size() - 1];\n        if (check(i, j,\
    \ k)) break;\n        P.pop_back();\n      }\n      P.eb(k);\n    }\n    return\
    \ P;\n  };\n\n  vc<int> P;\n  if (mode == \"full\" || mode == \"lower\") {\n \
    \   vc<int> Q = calc();\n    P.insert(P.end(), all(Q));\n  }\n  if (mode == \"\
    full\" || mode == \"upper\") {\n    if (!P.empty()) P.pop_back();\n    reverse(all(I));\n\
    \    vc<int> Q = calc();\n    P.insert(P.end(), all(Q));\n  }\n  if (mode == \"\
    upper\") reverse(all(P));\n  while (len(P) >= 2 && XY[P[0]] == XY[P.back()]) P.pop_back();\n\
    \  return P;\n}\n#line 1 \"geo/base.hpp\"\ntemplate <typename T>\nstruct Point\
    \ {\n  T x, y;\n\n  Point() : x(0), y(0) {}\n\n  template <typename A, typename\
    \ B>\n  Point(A x, B y) : x(x), y(y) {}\n\n  template <typename A, typename B>\n\
    \  Point(pair<A, B> p) : x(p.fi), y(p.se) {}\n\n  template <typename U>\n  Point(Point<U>\
    \ p) : x(p.x), y(p.y) {\n    static_assert(!is_integral_v<T> || is_integral_v<U>);\n\
    \  }\n\n  Point operator+=(const Point p) {\n    x += p.x, y += p.y;\n    return\
    \ *this;\n  }\n  Point operator-=(const Point p) {\n    x -= p.x, y -= p.y;\n\
    \    return *this;\n  }\n  Point operator+(Point p) const { return {x + p.x, y\
    \ + p.y}; }\n  Point operator-(Point p) const { return {x - p.x, y - p.y}; }\n\
    \  bool operator==(Point p) const { return x == p.x && y == p.y; }\n  bool operator!=(Point\
    \ p) const { return x != p.x || y != p.y; }\n  Point operator-() const { return\
    \ {-x, -y}; }\n  Point operator*(T t) const { return {x * t, y * t}; }\n  Point\
    \ operator/(T t) const { return {x / t, y / t}; }\n\n  bool operator<(Point p)\
    \ const {\n    if (x != p.x) return x < p.x;\n    return y < p.y;\n  }\n  T dot(const\
    \ Point& other) const { return x * other.x + y * other.y; }\n  T det(const Point&\
    \ other) const { return x * other.y - y * other.x; }\n\n  double norm() { return\
    \ sqrtl(x * x + y * y); }\n  double angle() { return atan2(y, x); }\n\n  Point\
    \ rotate(double theta) {\n    static_assert(!is_integral<T>::value);\n    double\
    \ c = cos(theta), s = sin(theta);\n    return Point{c * x - s * y, s * x + c *\
    \ y};\n  }\n  Point rot90(bool ccw) { return (ccw ? Point{-y, x} : Point{y, -x});\
    \ }\n};\n\n#ifdef FASTIO\ntemplate <typename T>\nvoid rd(Point<T>& p) {\n  fastio::rd(p.x),\
    \ fastio::rd(p.y);\n}\ntemplate <typename T>\nvoid wt(Point<T>& p) {\n  fastio::wt(p.x);\n\
    \  fastio::wt(' ');\n  fastio::wt(p.y);\n}\n#endif\n\n// A -> B -> C \u3068\u9032\
    \u3080\u3068\u304D\u306B\u3001\u5DE6\u306B\u66F2\u304C\u308B\u306A\u3089\u3070\
    \ +1\u3001\u53F3\u306B\u66F2\u304C\u308B\u306A\u3089\u3070 -1\ntemplate <typename\
    \ T>\nint ccw(Point<T> A, Point<T> B, Point<T> C) {\n  T x = (B - A).det(C - A);\n\
    \  if (x > 0) return 1;\n  if (x < 0) return -1;\n  return 0;\n}\n\ntemplate <typename\
    \ REAL, typename T, typename U>\nREAL distance(Point<T> A, Point<U> B) {\n  REAL\
    \ dx = REAL(A.x) - REAL(B.x);\n  REAL dy = REAL(A.y) - REAL(B.y);\n  return sqrt(dx\
    \ * dx + dy * dy);\n}\n\n// ax+by+c\ntemplate <typename T>\nstruct Line {\n  T\
    \ a, b, c;\n\n  Line(T a, T b, T c) : a(a), b(b), c(c) {}\n  Line(Point<T> A,\
    \ Point<T> B) {\n    a = A.y - B.y, b = B.x - A.x, c = A.x * B.y - A.y * B.x;\n\
    \  }\n  Line(T x1, T y1, T x2, T y2) : Line(Point<T>(x1, y1), Point<T>(x2, y2))\
    \ {}\n\n  template <typename U>\n  U eval(Point<U> P) {\n    return U(a) * P.x\
    \ + U(b) * P.y + U(c);\n  }\n\n  template <typename U>\n  T eval(U x, U y) {\n\
    \    return a * x + b * y + c;\n  }\n\n  // \u540C\u3058\u76F4\u7DDA\u304C\u540C\
    \u3058 a,b,c \u3067\u8868\u73FE\u3055\u308C\u308B\u3088\u3046\u306B\u3059\u308B\
    \n  void normalize() {\n    static_assert(is_same_v<T, int> || is_same_v<T, long\
    \ long>);\n    T g = gcd(gcd(abs(a), abs(b)), abs(c));\n    a /= g, b /= g, c\
    \ /= g;\n    if (b < 0) {\n      a = -a, b = -b, c = -c;\n    }\n    if (b ==\
    \ 0 && a < 0) {\n      a = -a, b = -b, c = -c;\n    }\n  }\n\n  bool is_parallel(Line\
    \ other) { return a * other.b - b * other.a == 0; }\n  bool is_orthogonal(Line\
    \ other) { return a * other.a + b * other.b == 0; }\n  bool is_same(Line other)\
    \ {\n    if (a * other.b != b * other.a) return 0;\n    if (a * other.c != c *\
    \ other.a) return 0;\n    if (b * other.c != c * other.b) return 0;\n    return\
    \ 1;\n  }\n};\n\ntemplate <typename T>\nstruct Segment {\n  Point<T> A, B;\n\n\
    \  Segment(Point<T> A, Point<T> B) : A(A), B(B) {}\n  Segment(T x1, T y1, T x2,\
    \ T y2)\n      : Segment(Point<T>(x1, y1), Point<T>(x2, y2)) {}\n\n  bool contain(Point<T>\
    \ C) {\n    T det = (C - A).det(B - A);\n    if (det != 0) return 0;\n    return\
    \ (C - A).dot(B - A) >= 0 && (C - B).dot(A - B) >= 0;\n  }\n\n  Line<T> to_line()\
    \ { return Line(A, B); }\n};\n\ntemplate <typename REAL>\nstruct Circle {\n  Point<REAL>\
    \ O;\n  REAL r;\n  Circle() {}\n  Circle(Point<REAL> O, REAL r) : O(O), r(r) {}\n\
    \  Circle(REAL x, REAL y, REAL r) : O(x, y), r(r) {}\n  template <typename T>\n\
    \  bool contain(Point<T> p) {\n    REAL dx = p.x - O.x, dy = p.y - O.y;\n    return\
    \ dx * dx + dy * dy <= r * r;\n  }\n};\n#line 1 \"geo/convex_hull.hpp\"\n\n#line\
    \ 1 \"geo/base.hpp\"\ntemplate <typename T>\nstruct Point {\n  T x, y;\n\n  Point()\
    \ : x(0), y(0) {}\n\n  template <typename A, typename B>\n  Point(A x, B y) :\
    \ x(x), y(y) {}\n\n  template <typename A, typename B>\n  Point(pair<A, B> p)\
    \ : x(p.fi), y(p.se) {}\n\n  template <typename U>\n  Point(Point<U> p) : x(p.x),\
    \ y(p.y) {\n    static_assert(!is_integral_v<T> || is_integral_v<U>);\n  }\n\n\
    \  Point operator+=(const Point p) {\n    x += p.x, y += p.y;\n    return *this;\n\
    \  }\n  Point operator-=(const Point p) {\n    x -= p.x, y -= p.y;\n    return\
    \ *this;\n  }\n  Point operator+(Point p) const { return {x + p.x, y + p.y}; }\n\
    \  Point operator-(Point p) const { return {x - p.x, y - p.y}; }\n  bool operator==(Point\
    \ p) const { return x == p.x && y == p.y; }\n  bool operator!=(Point p) const\
    \ { return x != p.x || y != p.y; }\n  Point operator-() const { return {-x, -y};\
    \ }\n  Point operator*(T t) const { return {x * t, y * t}; }\n  Point operator/(T\
    \ t) const { return {x / t, y / t}; }\n\n  bool operator<(Point p) const {\n \
    \   if (x != p.x) return x < p.x;\n    return y < p.y;\n  }\n  T dot(const Point&\
    \ other) const { return x * other.x + y * other.y; }\n  T det(const Point& other)\
    \ const { return x * other.y - y * other.x; }\n\n  double norm() { return sqrtl(x\
    \ * x + y * y); }\n  double angle() { return atan2(y, x); }\n\n  Point rotate(double\
    \ theta) {\n    static_assert(!is_integral<T>::value);\n    double c = cos(theta),\
    \ s = sin(theta);\n    return Point{c * x - s * y, s * x + c * y};\n  }\n  Point\
    \ rot90(bool ccw) { return (ccw ? Point{-y, x} : Point{y, -x}); }\n};\n\n#ifdef\
    \ FASTIO\ntemplate <typename T>\nvoid rd(Point<T>& p) {\n  fastio::rd(p.x), fastio::rd(p.y);\n\
    }\ntemplate <typename T>\nvoid wt(Point<T>& p) {\n  fastio::wt(p.x);\n  fastio::wt('\
    \ ');\n  fastio::wt(p.y);\n}\n#endif\n\n// A -> B -> C \u3068\u9032\u3080\u3068\
    \u304D\u306B\u3001\u5DE6\u306B\u66F2\u304C\u308B\u306A\u3089\u3070 +1\u3001\u53F3\
    \u306B\u66F2\u304C\u308B\u306A\u3089\u3070 -1\ntemplate <typename T>\nint ccw(Point<T>\
    \ A, Point<T> B, Point<T> C) {\n  T x = (B - A).det(C - A);\n  if (x > 0) return\
    \ 1;\n  if (x < 0) return -1;\n  return 0;\n}\n\ntemplate <typename REAL, typename\
    \ T, typename U>\nREAL distance(Point<T> A, Point<U> B) {\n  REAL dx = REAL(A.x)\
    \ - REAL(B.x);\n  REAL dy = REAL(A.y) - REAL(B.y);\n  return sqrt(dx * dx + dy\
    \ * dy);\n}\n\n// ax+by+c\ntemplate <typename T>\nstruct Line {\n  T a, b, c;\n\
    \n  Line(T a, T b, T c) : a(a), b(b), c(c) {}\n  Line(Point<T> A, Point<T> B)\
    \ {\n    a = A.y - B.y, b = B.x - A.x, c = A.x * B.y - A.y * B.x;\n  }\n  Line(T\
    \ x1, T y1, T x2, T y2) : Line(Point<T>(x1, y1), Point<T>(x2, y2)) {}\n\n  template\
    \ <typename U>\n  U eval(Point<U> P) {\n    return U(a) * P.x + U(b) * P.y + U(c);\n\
    \  }\n\n  template <typename U>\n  T eval(U x, U y) {\n    return a * x + b *\
    \ y + c;\n  }\n\n  // \u540C\u3058\u76F4\u7DDA\u304C\u540C\u3058 a,b,c \u3067\u8868\
    \u73FE\u3055\u308C\u308B\u3088\u3046\u306B\u3059\u308B\n  void normalize() {\n\
    \    static_assert(is_same_v<T, int> || is_same_v<T, long long>);\n    T g = gcd(gcd(abs(a),\
    \ abs(b)), abs(c));\n    a /= g, b /= g, c /= g;\n    if (b < 0) {\n      a =\
    \ -a, b = -b, c = -c;\n    }\n    if (b == 0 && a < 0) {\n      a = -a, b = -b,\
    \ c = -c;\n    }\n  }\n\n  bool is_parallel(Line other) { return a * other.b -\
    \ b * other.a == 0; }\n  bool is_orthogonal(Line other) { return a * other.a +\
    \ b * other.b == 0; }\n  bool is_same(Line other) {\n    if (a * other.b != b\
    \ * other.a) return 0;\n    if (a * other.c != c * other.a) return 0;\n    if\
    \ (b * other.c != c * other.b) return 0;\n    return 1;\n  }\n};\n\ntemplate <typename\
    \ T>\nstruct Segment {\n  Point<T> A, B;\n\n  Segment(Point<T> A, Point<T> B)\
    \ : A(A), B(B) {}\n  Segment(T x1, T y1, T x2, T y2)\n      : Segment(Point<T>(x1,\
    \ y1), Point<T>(x2, y2)) {}\n\n  bool contain(Point<T> C) {\n    T det = (C -\
    \ A).det(B - A);\n    if (det != 0) return 0;\n    return (C - A).dot(B - A) >=\
    \ 0 && (C - B).dot(A - B) >= 0;\n  }\n\n  Line<T> to_line() { return Line(A, B);\
    \ }\n};\n\ntemplate <typename REAL>\nstruct Circle {\n  Point<REAL> O;\n  REAL\
    \ r;\n  Circle() {}\n  Circle(Point<REAL> O, REAL r) : O(O), r(r) {}\n  Circle(REAL\
    \ x, REAL y, REAL r) : O(x, y), r(r) {}\n  template <typename T>\n  bool contain(Point<T>\
    \ p) {\n    REAL dx = p.x - O.x, dy = p.y - O.y;\n    return dx * dx + dy * dy\
    \ <= r * r;\n  }\n};\n#line 3 \"geo/convex_hull.hpp\"\n\n// allow_180=true \u3067\
    \u540C\u4E00\u5EA7\u6A19\u70B9\u304C\u3042\u308B\u3068\u3053\u308F\u308C\u308B\
    \n// full \u306A\u3089 I[0] \u304C sorted \u3067 min \u306B\u306A\u308B\ntemplate\
    \ <typename T, bool allow_180 = false>\nvector<int> convex_hull(vector<Point<T>>&\
    \ XY, string mode = \"full\",\n                        bool sorted = false) {\n\
    \  assert(mode == \"full\" || mode == \"lower\" || mode == \"upper\");\n  ll N\
    \ = XY.size();\n  if (N == 1) return {0};\n  if (N == 2) {\n    if (XY[0] < XY[1])\
    \ return {0, 1};\n    if (XY[1] < XY[0]) return {1, 0};\n    return {0};\n  }\n\
    \  vc<int> I(N);\n  if (sorted) {\n    FOR(i, N) I[i] = i;\n  } else {\n    I\
    \ = argsort(XY);\n  }\n  if constexpr (allow_180) {\n    FOR(i, N - 1) assert(XY[i]\
    \ != XY[i + 1]);\n  }\n\n  auto check = [&](ll i, ll j, ll k) -> bool {\n    T\
    \ det = (XY[j] - XY[i]).det(XY[k] - XY[i]);\n    if constexpr (allow_180) return\
    \ det >= 0;\n    return det > T(0);\n  };\n\n  auto calc = [&]() {\n    vector<int>\
    \ P;\n    for (auto&& k : I) {\n      while (P.size() > 1) {\n        auto i =\
    \ P[P.size() - 2];\n        auto j = P[P.size() - 1];\n        if (check(i, j,\
    \ k)) break;\n        P.pop_back();\n      }\n      P.eb(k);\n    }\n    return\
    \ P;\n  };\n\n  vc<int> P;\n  if (mode == \"full\" || mode == \"lower\") {\n \
    \   vc<int> Q = calc();\n    P.insert(P.end(), all(Q));\n  }\n  if (mode == \"\
    full\" || mode == \"upper\") {\n    if (!P.empty()) P.pop_back();\n    reverse(all(I));\n\
    \    vc<int> Q = calc();\n    P.insert(P.end(), all(Q));\n  }\n  if (mode == \"\
    upper\") reverse(all(P));\n  while (len(P) >= 2 && XY[P[0]] == XY[P.back()]) P.pop_back();\n\
    \  return P;\n}\n#line 3 \"geo/convex_polygon.hpp\"\n\n// strict: n>=3 \u306E\u53CD\
    \u6642\u8A08\u56DE\u308A\u72ED\u7FA9\u51F8\u591A\u89D2\u5F62\u3002\n// non-strict:\
    \ n=1 \u306E\u70B9\u3001n=2 \u306E\u7DDA\u5206\u3001\u307E\u305F\u306F n>=3 \u306E\
    \u53CD\u6642\u8A08\u56DE\u308A\u51F8\u591A\u89D2\u5F62\u3002\ntemplate <typename\
    \ T, bool is_strict = true>\nstruct Convex_Polygon {\n  using P = Point<T>;\n\
    \  int n;\n  vc<P> point;\n  T area2;\n\n  Convex_Polygon(vc<P> point_) : n(len(point_)),\
    \ point(point_) {\n    assert(n >= 1);\n    if constexpr (is_strict) assert(n\
    \ >= 3);\n    area2 = 0;\n    FOR(i, n) {\n      int j = nxt_idx(i);\n      if\
    \ (n >= 2) assert(point[i] != point[j]);\n      area2 += point[i].det(point[j]);\n\
    \    }\n    assert(area2 >= T(0));\n    if (n >= 3) assert(area2 > T(0));\n  \
    \  if (n >= 3) FOR(i, n) {\n        int j = nxt_idx(i), k = nxt_idx(j);\n    \
    \    T det = (point[j] - point[i]).det(point[k] - point[i]);\n        if constexpr\
    \ (is_strict)\n          assert(det > T(0));\n        else\n          assert(det\
    \ >= T(0));\n      }\n  }\n\n  template <typename F>\n  int periodic_min_comp(F\
    \ comp) const {\n    static_assert(is_strict);\n    int L = 0, M = n, R = n +\
    \ n;\n    while (R - L != 2) {\n      int L1 = (L + M) / 2, R1 = (M + R + 1) /\
    \ 2;\n      if (comp(L1 % n, M % n)) R = M, M = L1;\n      elif (comp(R1 % n,\
    \ M % n)) L = M, M = R1;\n      else L = L1, R = R1;\n    }\n    return M % n;\n\
    \  }\n\n  int nxt_idx(int i) const { return (i + 1 == n ? 0 : i + 1); }\n  int\
    \ prev_idx(int i) const { return (i == 0 ? n - 1 : i - 1); }\n\n  // \u4E2D\uFF1A\
    1, \u5883\u754C\uFF1A0, \u5916\uFF1A-1.\n  int side(P p) const {\n    if (n ==\
    \ 1) return (p == point[0] ? 0 : -1);\n    if (n == 2) {\n      P A = point[0],\
    \ B = point[1];\n      if ((B - A).det(p - A) == 0 && (B - A).dot(p - A) >= 0\
    \ &&\n          (A - B).dot(p - B) >= 0)\n        return 0;\n      return -1;\n\
    \    }\n    int L = 1, R = n - 1;\n    T a = (point[L] - point[0]).det(p - point[0]);\n\
    \    T b = (point[R] - point[0]).det(p - point[0]);\n    if (a < 0 || b > 0) return\
    \ -1;\n    while (R - L >= 2) {\n      int M = (L + R) / 2;\n      T c = (point[M]\
    \ - point[0]).det(p - point[0]);\n      if (c < 0)\n        R = M, b = c;\n  \
    \    else\n        L = M, a = c;\n    }\n    T c = (point[R] - point[L]).det(p\
    \ - point[L]);\n    T x = min({a, -b, c});\n    if (x < 0) return -1;\n    if\
    \ (x > 0) return 1;\n    if (p == point[0]) return 0;\n    if (c != 0 && a ==\
    \ 0 && L != 1) return 1;\n    if (c != 0 && b == 0 && R != n - 1) return 1;\n\
    \    return 0;\n  }\n\n  // return {min, i, j}. i==j \u306F\u9802\u70B9, i!=j\
    \ \u306F\u6700\u9069\u8FBA i -> j\u3002\n  tuple<T, int, int> min_dot(P p) const\
    \ {\n    static_assert(is_strict);\n    assert(p != P(0, 0));\n    int idx = periodic_min_comp(\n\
    \        [&](int i, int j) { return point[i].dot(p) < point[j].dot(p); });\n \
    \   T val = point[idx].dot(p);\n    int prv = prev_idx(idx), nxt = nxt_idx(idx);\n\
    \    if (point[prv].dot(p) == val) return {val, prv, idx};\n    if (point[nxt].dot(p)\
    \ == val) return {val, idx, nxt};\n    return {val, idx, idx};\n  }\n\n  // return\
    \ {max, i, j}. i==j \u306F\u9802\u70B9, i!=j \u306F\u6700\u9069\u8FBA i -> j\u3002\
    \n  tuple<T, int, int> max_dot(P p) const {\n    static_assert(is_strict);\n \
    \   assert(p != P(0, 0));\n    int idx = periodic_min_comp(\n        [&](int i,\
    \ int j) { return point[i].dot(p) > point[j].dot(p); });\n    T val = point[idx].dot(p);\n\
    \    int prv = prev_idx(idx), nxt = nxt_idx(idx);\n    if (point[prv].dot(p) ==\
    \ val) return {val, prv, idx};\n    if (point[nxt].dot(p) == val) return {val,\
    \ idx, nxt};\n    return {val, idx, idx};\n  }\n\n  pair<int, int> visible_range(P\
    \ p) const {\n    static_assert(is_strict);\n    int a = periodic_min_comp(\n\
    \        [&](int i, int j) { return (point[i] - p).det(point[j] - p) < 0; });\n\
    \    int b = periodic_min_comp(\n        [&](int i, int j) { return (point[i]\
    \ - p).det(point[j] - p) > 0; });\n    if ((p - point[a]).det(p - point[prev_idx(a)])\
    \ == T(0)) a = prev_idx(a);\n    if ((p - point[b]).det(p - point[nxt_idx(b)])\
    \ == T(0)) b = nxt_idx(b);\n    return {a, b};\n  }\n\n  bool check_cross(P A,\
    \ P B) const {\n    static_assert(is_strict);\n    FOR(2) {\n      swap(A, B);\n\
    \      auto [a, b] = visible_range(A);\n      if ((point[a] - A).det(B - A) >=\
    \ 0) return false;\n      if ((point[b] - A).det(B - A) <= 0) return false;\n\
    \    }\n    return true;\n  }\n\n  // 0: \u5171\u901A\u70B9\u306A\u3057, 1: \u4E00\
    \u610F\u306A\u5171\u901A\u70B9, 2: \u7570\u306A\u308B\u5171\u901A\u70B9\u304C\
    2\u500B,\n  // infty<int>: \u5883\u754C\u8FBA\u3068\u6B63\u306E\u9577\u3055\u3067\
    \u91CD\u306A\u308B.\n  int count_boundary_cross_line(P A, P B) const {\n    static_assert(is_strict);\n\
    \    assert(A != B);\n    P D = B - A;\n    P normal(-D.y, D.x);\n    auto [min_value,\
    \ min_i, min_j] = min_dot(normal);\n    auto [max_value, max_i, max_j] = max_dot(normal);\n\
    \    T lo = min_value - normal.dot(A);\n    T hi = max_value - normal.dot(A);\n\
    \    if (lo > T(0) || hi < T(0)) return 0;\n    if (lo == T(0) && min_i != min_j)\
    \ return infty<int>;\n    if (hi == T(0) && max_i != max_j) return infty<int>;\n\
    \    if (lo == T(0) || hi == T(0)) return 1;\n    return 2;\n  }\n\n  // return\
    \ {t, eid, s} in increasing t order.\n  // A+t*(B-A) = point[eid]*(1-s)+point[nxt_idx(eid)]*s,\
    \ 0<=s<1.\n  // \u8FBA\u3068\u91CD\u306A\u308B\u5834\u5408\u306F\u3001\u305D\u306E\
    \u8FBA\u306E\u4E21\u7AEF\u70B9\u3092\u8FD4\u3059.\n  template <typename REAL>\n\
    \  vc<tuple<REAL, int, REAL>> boundary_cross_line(P A, P B) const {\n    static_assert(is_strict);\n\
    \    assert(A != B);\n    int cnt = count_boundary_cross_line(A, B);\n    if (cnt\
    \ == 0) return {};\n\n    P D = B - A;\n    P normal(-D.y, D.x);\n    auto [min_value,\
    \ min_i, min_j] = min_dot(normal);\n    auto [max_value, max_i, max_j] = max_dot(normal);\n\
    \    T lo = min_value - normal.dot(A);\n\n    auto vertex_data = [&](int i) ->\
    \ tuple<REAL, int, REAL> {\n      REAL t = (D.x != T(0) ? REAL(point[i].x - A.x)\
    \ / REAL(D.x)\n                            : REAL(point[i].y - A.y) / REAL(D.y));\n\
    \      return {t, i, REAL(0)};\n    };\n    if (cnt == infty<int>) {\n      int\
    \ i = (lo == T(0) ? min_i : max_i);\n      int j = (lo == T(0) ? min_j : max_j);\n\
    \      assert(j == nxt_idx(i));\n      vc<tuple<REAL, int, REAL>> ans = {vertex_data(i),\
    \ vertex_data(j)};\n      if (get<0>(ans[1]) < get<0>(ans[0])) swap(ans[0], ans[1]);\n\
    \      return ans;\n    }\n    if (cnt == 1) return {lo == T(0) ? vertex_data(min_i)\
    \ : vertex_data(max_i)};\n\n    auto eval = [&](int i) -> T {\n      return normal.dot(point[i\
    \ % n]) - normal.dot(A);\n    };\n    int a = min_i, b = max_i;\n    if (b < a)\
    \ b += n;\n    int p = binary_search([&](int i) { return eval(i) < T(0); }, a,\
    \ b);\n    int q = binary_search([&](int i) { return eval(i) > T(0); }, b, a +\
    \ n);\n    auto edge_data = [&](int eid) -> tuple<REAL, int, REAL> {\n      int\
    \ j = nxt_idx(eid);\n      T x = eval(eid), y = eval(eid + 1);\n      if (x ==\
    \ T(0)) return vertex_data(eid);\n      if (y == T(0)) return vertex_data(j);\n\
    \      assert((x < T(0) && T(0) < y) || (y < T(0) && T(0) < x));\n\n      P E\
    \ = point[eid];\n      P F = point[j] - E;\n      T den = D.det(F);\n      assert(den\
    \ != T(0));\n\n      REAL t = REAL((E - A).det(F)) / REAL(den);\n      REAL s\
    \ = REAL((E - A).det(D)) / REAL(den);\n\n      return {t, eid, s};\n    };\n \
    \   vc<tuple<REAL, int, REAL>> ans = {edge_data(p % n), edge_data(q % n)};\n \
    \   if (get<0>(ans[1]) < get<0>(ans[0])) swap(ans[0], ans[1]);\n    return ans;\n\
    \  }\n\n  T area_between(int i, int j) const {\n    assert(i <= j && j <= i +\
    \ n);\n    if (j == i + n) return area2;\n    i %= n, j %= n;\n    if (i > j)\
    \ j += n;\n    if (AREA.empty()) build_AREA();\n    return AREA[j] - AREA[i] +\
    \ point[j % n].det(point[i]);\n  }\n\n  T left_area(Line<T> L) const {\n    static_assert(is_strict);\n\
    \    static_assert(is_same<T, double>::value || is_same<T, long double>::value);\n\
    \    Point<T> normal(L.a, L.b);\n    auto [min_value, a, min_j] = min_dot(normal);\n\
    \    auto [max_value, b, max_j] = max_dot(normal);\n    if (b < a) b += n;\n \
    \   assert(L.eval(point[a % n]) < 0 && L.eval(point[b % n]) > 0);\n    int p =\n\
    \        binary_search([&](int i) { return L.eval(point[i % n]) < 0; }, a, b);\n\
    \    int q = binary_search(\n        [&](int i) { return L.eval(point[i % n])\
    \ > 0; }, b, a + n);\n    T s = L.eval(point[p % n]) /\n          (L.eval(point[p\
    \ % n]) - L.eval(point[(p + 1) % n]));\n    T t = L.eval(point[q % n]) /\n   \
    \       (L.eval(point[q % n]) - L.eval(point[(q + 1) % n]));\n    P A = point[p\
    \ % n], B = point[(p + 1) % n];\n    P C = point[q % n], D = point[(q + 1) % n];\n\
    \    P X = B * s + A * (1 - s), Y = D * t + C * (1 - t);\n    T ans = area_between(p,\
    \ q);\n    ans -= (A - C).det(X - C);\n    ans += (Y - C).det(X - C);\n    return\
    \ ans;\n  }\n\n private:\n  mutable vc<T> AREA;\n\n  void build_AREA() const {\n\
    \    AREA.resize(2 * n);\n    FOR(i, n) AREA[n + i] = AREA[i] = point[i].det(point[nxt_idx(i)]);\n\
    \    AREA = cumsum<T>(AREA);\n  }\n};\n#line 1 \"geo/base.hpp\"\ntemplate <typename\
    \ T>\nstruct Point {\n  T x, y;\n\n  Point() : x(0), y(0) {}\n\n  template <typename\
    \ A, typename B>\n  Point(A x, B y) : x(x), y(y) {}\n\n  template <typename A,\
    \ typename B>\n  Point(pair<A, B> p) : x(p.fi), y(p.se) {}\n\n  template <typename\
    \ U>\n  Point(Point<U> p) : x(p.x), y(p.y) {\n    static_assert(!is_integral_v<T>\
    \ || is_integral_v<U>);\n  }\n\n  Point operator+=(const Point p) {\n    x +=\
    \ p.x, y += p.y;\n    return *this;\n  }\n  Point operator-=(const Point p) {\n\
    \    x -= p.x, y -= p.y;\n    return *this;\n  }\n  Point operator+(Point p) const\
    \ { return {x + p.x, y + p.y}; }\n  Point operator-(Point p) const { return {x\
    \ - p.x, y - p.y}; }\n  bool operator==(Point p) const { return x == p.x && y\
    \ == p.y; }\n  bool operator!=(Point p) const { return x != p.x || y != p.y; }\n\
    \  Point operator-() const { return {-x, -y}; }\n  Point operator*(T t) const\
    \ { return {x * t, y * t}; }\n  Point operator/(T t) const { return {x / t, y\
    \ / t}; }\n\n  bool operator<(Point p) const {\n    if (x != p.x) return x < p.x;\n\
    \    return y < p.y;\n  }\n  T dot(const Point& other) const { return x * other.x\
    \ + y * other.y; }\n  T det(const Point& other) const { return x * other.y - y\
    \ * other.x; }\n\n  double norm() { return sqrtl(x * x + y * y); }\n  double angle()\
    \ { return atan2(y, x); }\n\n  Point rotate(double theta) {\n    static_assert(!is_integral<T>::value);\n\
    \    double c = cos(theta), s = sin(theta);\n    return Point{c * x - s * y, s\
    \ * x + c * y};\n  }\n  Point rot90(bool ccw) { return (ccw ? Point{-y, x} : Point{y,\
    \ -x}); }\n};\n\n#ifdef FASTIO\ntemplate <typename T>\nvoid rd(Point<T>& p) {\n\
    \  fastio::rd(p.x), fastio::rd(p.y);\n}\ntemplate <typename T>\nvoid wt(Point<T>&\
    \ p) {\n  fastio::wt(p.x);\n  fastio::wt(' ');\n  fastio::wt(p.y);\n}\n#endif\n\
    \n// A -> B -> C \u3068\u9032\u3080\u3068\u304D\u306B\u3001\u5DE6\u306B\u66F2\u304C\
    \u308B\u306A\u3089\u3070 +1\u3001\u53F3\u306B\u66F2\u304C\u308B\u306A\u3089\u3070\
    \ -1\ntemplate <typename T>\nint ccw(Point<T> A, Point<T> B, Point<T> C) {\n \
    \ T x = (B - A).det(C - A);\n  if (x > 0) return 1;\n  if (x < 0) return -1;\n\
    \  return 0;\n}\n\ntemplate <typename REAL, typename T, typename U>\nREAL distance(Point<T>\
    \ A, Point<U> B) {\n  REAL dx = REAL(A.x) - REAL(B.x);\n  REAL dy = REAL(A.y)\
    \ - REAL(B.y);\n  return sqrt(dx * dx + dy * dy);\n}\n\n// ax+by+c\ntemplate <typename\
    \ T>\nstruct Line {\n  T a, b, c;\n\n  Line(T a, T b, T c) : a(a), b(b), c(c)\
    \ {}\n  Line(Point<T> A, Point<T> B) {\n    a = A.y - B.y, b = B.x - A.x, c =\
    \ A.x * B.y - A.y * B.x;\n  }\n  Line(T x1, T y1, T x2, T y2) : Line(Point<T>(x1,\
    \ y1), Point<T>(x2, y2)) {}\n\n  template <typename U>\n  U eval(Point<U> P) {\n\
    \    return U(a) * P.x + U(b) * P.y + U(c);\n  }\n\n  template <typename U>\n\
    \  T eval(U x, U y) {\n    return a * x + b * y + c;\n  }\n\n  // \u540C\u3058\
    \u76F4\u7DDA\u304C\u540C\u3058 a,b,c \u3067\u8868\u73FE\u3055\u308C\u308B\u3088\
    \u3046\u306B\u3059\u308B\n  void normalize() {\n    static_assert(is_same_v<T,\
    \ int> || is_same_v<T, long long>);\n    T g = gcd(gcd(abs(a), abs(b)), abs(c));\n\
    \    a /= g, b /= g, c /= g;\n    if (b < 0) {\n      a = -a, b = -b, c = -c;\n\
    \    }\n    if (b == 0 && a < 0) {\n      a = -a, b = -b, c = -c;\n    }\n  }\n\
    \n  bool is_parallel(Line other) { return a * other.b - b * other.a == 0; }\n\
    \  bool is_orthogonal(Line other) { return a * other.a + b * other.b == 0; }\n\
    \  bool is_same(Line other) {\n    if (a * other.b != b * other.a) return 0;\n\
    \    if (a * other.c != c * other.a) return 0;\n    if (b * other.c != c * other.b)\
    \ return 0;\n    return 1;\n  }\n};\n\ntemplate <typename T>\nstruct Segment {\n\
    \  Point<T> A, B;\n\n  Segment(Point<T> A, Point<T> B) : A(A), B(B) {}\n  Segment(T\
    \ x1, T y1, T x2, T y2)\n      : Segment(Point<T>(x1, y1), Point<T>(x2, y2)) {}\n\
    \n  bool contain(Point<T> C) {\n    T det = (C - A).det(B - A);\n    if (det !=\
    \ 0) return 0;\n    return (C - A).dot(B - A) >= 0 && (C - B).dot(A - B) >= 0;\n\
    \  }\n\n  Line<T> to_line() { return Line(A, B); }\n};\n\ntemplate <typename REAL>\n\
    struct Circle {\n  Point<REAL> O;\n  REAL r;\n  Circle() {}\n  Circle(Point<REAL>\
    \ O, REAL r) : O(O), r(r) {}\n  Circle(REAL x, REAL y, REAL r) : O(x, y), r(r)\
    \ {}\n  template <typename T>\n  bool contain(Point<T> p) {\n    REAL dx = p.x\
    \ - O.x, dy = p.y - O.y;\n    return dx * dx + dy * dy <= r * r;\n  }\n};\n#line\
    \ 2 \"geo/incremental_convex_hull.hpp\"\n\n// \u4E0B\u5074\u51F8\u5305\ntemplate\
    \ <typename T, bool strict = true>\nstruct Incremental_Convex_Hull_Lower {\n \
    \ using P = Point<T>;\n  set<P> S;\n\n  Incremental_Convex_Hull_Lower() {}\n\n\
    \  int size() { return len(S); }\n\n  template <typename ADD_V, typename RM_V,\
    \ typename ADD_E, typename RM_E>\n  void add(Point<T> p, ADD_V add_v, RM_V rm_v,\
    \ ADD_E add_e, RM_E rm_e) {\n    int s = side(p);\n    if (strict && s >= 0) return;\n\
    \    if (!strict && s > 0) return;\n\n    // \u70B9\u8FFD\u52A0\n    add_v(p);\n\
    \    S.insert(p);\n\n    vc<P> left;\n    {\n      auto it = S.find(p);\n    \
    \  while (it != S.begin()) {\n        --it;\n        if (left.empty()) {\n   \
    \       left.eb(*it);\n          continue;\n        }\n        auto a = *it;\n\
    \        auto b = left.back();\n        T det = (b - a).det(p - a);\n        if\
    \ (strict && det > 0) break;\n        if (!strict && det >= 0) break;\n      \
    \  left.eb(a);\n      }\n    }\n\n    vc<P> right;\n    {\n      auto it = S.find(p);\n\
    \      while (1) {\n        ++it;\n        if (it == S.end()) break;\n       \
    \ if (right.empty()) {\n          right.eb(*it);\n          continue;\n      \
    \  }\n        auto a = right.back();\n        auto b = *it;\n        T det = (a\
    \ - p).det(b - p);\n        if (strict && det > 0) break;\n        if (!strict\
    \ && det >= 0) break;\n        right.eb(b);\n      }\n    }\n\n    // \u70B9\u524A\
    \u9664\n    if (len(left) > 1) {\n      S.erase(next(S.find(left.back())), S.find(p));\n\
    \    }\n    if (len(right) > 1) {\n      S.erase(next(S.find(p)), S.find(right.back()));\n\
    \    }\n    FOR(i, len(left) - 1) rm_v(left[i]);\n    FOR(i, len(right) - 1) rm_v(right[i]);\n\
    \n    // \u8FBA\u524A\u9664\n    if (len(left) && len(right)) {\n      auto a\
    \ = left[0], b = right[0];\n      rm_e(a, b);\n    }\n    FOR(i, len(left) - 1)\
    \ {\n      auto a = left[i + 1], b = left[i];\n      rm_e(a, b);\n    }\n    FOR(i,\
    \ len(right) - 1) {\n      auto a = right[i], b = right[i + 1];\n      rm_e(a,\
    \ b);\n    }\n    // \u8FBA\u8FFD\u52A0\n    if (len(left)) {\n      add_e(left.back(),\
    \ p);\n    }\n    if (len(right)) {\n      add_e(p, right.back());\n    }\n  }\n\
    \n  // \u4E2D\uFF1A1, \u5883\u754C\uFF1A0, \u5916\uFF1A-1\n  int side(Point<T>\
    \ p) {\n    auto r = S.lower_bound(p);\n    if (r == S.begin()) {\n      // \u5168\
    \u90E8 p \u4EE5\u4E0A\n      if (len(S) && (*r) == p) return 0;\n      return\
    \ -1;\n    }\n    if (r == S.end()) {\n      // p \u306F max \u3088\u308A\u5927\
    \u304D\u3044\n      return -1;\n    }\n    auto l = prev(r);\n    auto p1 = *l,\
    \ p2 = *r;\n    T det = (p - p1).det(p2 - p1);\n    if (det == 0) return 0;\n\
    \    return (det > 0 ? -1 : 1);\n  }\n};\n\ntemplate <typename T, bool strict\
    \ = true>\nstruct Incremental_Convex_Hull {\n  using P = Point<T>;\n  Incremental_Convex_Hull_Lower<T,\
    \ strict> LOWER, UPPER;\n  int cnt_E;\n  T det_sum;\n  bool is_empty;\n\n  Incremental_Convex_Hull()\
    \ : cnt_E(0), det_sum(0), is_empty(1) {}\n\n  int size() { return cnt_E; }\n\n\
    \  bool empty() { return is_empty; }\n\n  template <typename REAL>\n  REAL area()\
    \ {\n    return det_sum * 0.5;\n  }\n  T area_2() { return det_sum; }\n\n  template\
    \ <typename ADD_V, typename RM_V, typename ADD_E, typename RM_E>\n  void add(Point<T>\
    \ p, ADD_V add_v, RM_V rm_v, ADD_E add_e, RM_E rm_e) {\n    is_empty = 0;\n  \
    \  LOWER.add(\n        p, add_v, rm_v,\n        [&](Point<T> a, Point<T> b) {\n\
    \          add_e(a, b);\n          ++cnt_E;\n          det_sum += a.det(b);\n\
    \        },\n        [&](Point<T> a, Point<T> b) {\n          rm_e(a, b);\n  \
    \        --cnt_E;\n          det_sum -= a.det(b);\n        });\n    UPPER.add(\n\
    \        -p, [&](Point<T> p) { add_v(-p); }, [&](Point<T> p) { rm_v(-p); },\n\
    \        [&](Point<T> a, Point<T> b) {\n          add_e(-a, -b);\n          ++cnt_E;\n\
    \          det_sum += a.det(b);\n        },\n        [&](Point<T> a, Point<T>\
    \ b) {\n          rm_e(-a, -b);\n          --cnt_E;\n          det_sum -= a.det(b);\n\
    \        });\n  }\n  void add(Point<T> p) {\n    add(\n        p, [](Point<T>\
    \ p) {}, [](Point<T> p) {}, [](Point<T> s, Point<T> t) {},\n        [](Point<T>\
    \ s, Point<T> t) {});\n  }\n\n  // \u4E2D\uFF1A1\u3001\u5883\u754C\uFF1A0\u3001\
    \u5916\uFF1A-1\n  int side(Point<T> p) {\n    int a = LOWER.side(p);\n    int\
    \ b = UPPER.side(-p);\n    if (a == 0 || b == 0) return 0;\n    return min(a,\
    \ b);\n  }\n};\n#line 1 \"random/base.hpp\"\n\nu64 RNG_64() {\n  static u64 x_\
    \ = u64(chrono::duration_cast<chrono::nanoseconds>(\n                      chrono::high_resolution_clock::now().time_since_epoch())\n\
    \                          .count()) *\n                  10150724397891781847ULL;\n\
    \  x_ ^= x_ << 7;\n  return x_ ^= x_ >> 9;\n}\n\nu64 RNG(u64 lim) {\n  assert(lim\
    \ > 0);\n  return RNG_64() % lim;\n}\n\nll RNG(ll l, ll r) {\n  assert(l < r);\n\
    \  return l + RNG_64() % (r - l);\n}\n#line 9 \"test/1_mytest/convex_polygon_visible_range.test.cpp\"\
    \n\nusing P = Point<ll>;\n\nvoid test() {\n  int N = RNG(3, 10);\n  vc<P> point(N);\n\
    \  FOR(i, N) point[i] = P(RNG(-5, 5), RNG(-5, 5));\n  auto I = convex_hull(point);\n\
    \  point = rearrange(point, I);\n  N = len(point);\n  if (N <= 2) return;\n\n\
    \  Convex_Polygon<ll> X(point);\n  FOR(x, -10, 11) FOR(y, -10, 11) {\n    P p(x,\
    \ y);\n    if (X.side(p) == 1) continue;\n    auto [l, r] = X.visible_range(p);\n\
    \    vc<int> can(N);\n    {\n      int i = l;\n      while (1) {\n        can[i]\
    \ = 1;\n        if (i == r) break;\n        i = (i + 1) % N;\n      }\n    }\n\
    \    FOR(i, N) {\n      int j = (i + N - 1) % N, k = (i + 1) % N;\n      P A =\
    \ point[j], B = point[i], C = point[k];\n      int ok = 0;\n      if ((B - A).det(p\
    \ - A) <= 0) ok = 1;\n      if ((B - C).det(p - C) >= 0) ok = 1;\n      assert(can[i]\
    \ == ok);\n    }\n  }\n}\n\nvoid solve() {\n  int a, b;\n  cin >> a >> b;\n  cout\
    \ << a + b << \"\\n\";\n}\n\nsigned main() {\n  FOR(30000) test();\n  solve();\n\
    \  return 0;\n}\n"
  code: "#define PROBLEM \"https://judge.yosupo.jp/problem/aplusb\"\n#include \"my_template.hpp\"\
    \n\n#include \"geo/base.hpp\"\n#include \"geo/convex_hull.hpp\"\n#include \"geo/convex_polygon.hpp\"\
    \n#include \"geo/incremental_convex_hull.hpp\"\n#include \"random/base.hpp\"\n\
    \nusing P = Point<ll>;\n\nvoid test() {\n  int N = RNG(3, 10);\n  vc<P> point(N);\n\
    \  FOR(i, N) point[i] = P(RNG(-5, 5), RNG(-5, 5));\n  auto I = convex_hull(point);\n\
    \  point = rearrange(point, I);\n  N = len(point);\n  if (N <= 2) return;\n\n\
    \  Convex_Polygon<ll> X(point);\n  FOR(x, -10, 11) FOR(y, -10, 11) {\n    P p(x,\
    \ y);\n    if (X.side(p) == 1) continue;\n    auto [l, r] = X.visible_range(p);\n\
    \    vc<int> can(N);\n    {\n      int i = l;\n      while (1) {\n        can[i]\
    \ = 1;\n        if (i == r) break;\n        i = (i + 1) % N;\n      }\n    }\n\
    \    FOR(i, N) {\n      int j = (i + N - 1) % N, k = (i + 1) % N;\n      P A =\
    \ point[j], B = point[i], C = point[k];\n      int ok = 0;\n      if ((B - A).det(p\
    \ - A) <= 0) ok = 1;\n      if ((B - C).det(p - C) >= 0) ok = 1;\n      assert(can[i]\
    \ == ok);\n    }\n  }\n}\n\nvoid solve() {\n  int a, b;\n  cin >> a >> b;\n  cout\
    \ << a + b << \"\\n\";\n}\n\nsigned main() {\n  FOR(30000) test();\n  solve();\n\
    \  return 0;\n}\n"
  dependsOn:
  - my_template.hpp
  - geo/base.hpp
  - geo/convex_hull.hpp
  - geo/convex_polygon.hpp
  - geo/incremental_convex_hull.hpp
  - random/base.hpp
  isVerificationFile: true
  path: test/1_mytest/convex_polygon_visible_range.test.cpp
  requiredBy: []
  timestamp: '2026-09-24 22:40:16+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: test/1_mytest/convex_polygon_visible_range.test.cpp
layout: document
redirect_from:
- /verify/test/1_mytest/convex_polygon_visible_range.test.cpp
- /verify/test/1_mytest/convex_polygon_visible_range.test.cpp.html
title: test/1_mytest/convex_polygon_visible_range.test.cpp
---
