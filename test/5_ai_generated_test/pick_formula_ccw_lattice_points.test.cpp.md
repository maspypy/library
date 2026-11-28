---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: geo/base.hpp
    title: geo/base.hpp
  - icon: ':heavy_check_mark:'
    path: geo/pick_formula.hpp
    title: geo/pick_formula.hpp
  - icon: ':question:'
    path: my_template.hpp
    title: my_template.hpp
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    links: []
  bundledCode: "#line 1 \"my_template.hpp\"\n// Source: https://github.com/maspypy/library/blob/main/my_template.hpp\n\
    #if defined(USE_PCH)\n#include <my_template_compiled.hpp>\n\n#if defined(__GNUC__)\n\
    #pragma GCC optimize(\"Ofast,unroll-loops\")\n#if !defined(MASPY_NON_AVX2)\n#pragma\
    \ GCC target(\"avx2,popcnt\")\n#endif\n#endif\n\n#else  // MASPY_TEMPLATE_BODY\n\
    #include <bits/stdc++.h>\n#include <cassert>\n\n#if defined(__GNUC__)\n#pragma\
    \ GCC optimize(\"Ofast,unroll-loops\")\n#endif\n\nusing namespace std;\n\nusing\
    \ ll = long long;\nusing u8 = uint8_t;\nusing u16 = uint16_t;\nusing u32 = uint32_t;\n\
    using u64 = uint64_t;\nusing i128 = __int128;\nusing u128 = unsigned __int128;\n\
    using f128 = __float128;\n\ntemplate <class>\nconstexpr bool dependent_false =\
    \ false;\n\ntemplate <class T>\nconstexpr T infty = [] {\n  static_assert(dependent_false<T>,\
    \ \"infty<T> is not defined\");\n  return T{};\n}();\ntemplate <>\nconstexpr int\
    \ infty<int> = 1'010'000'000;\ntemplate <>\nconstexpr ll infty<ll> = 4'040'000'000'000'000'000;\n\
    template <>\nconstexpr u32 infty<u32> = infty<int>;\ntemplate <>\nconstexpr u64\
    \ infty<u64> = infty<ll>;\ntemplate <>\nconstexpr i128 infty<i128> = i128(infty<ll>)\
    \ * 4'000'000'000'000'000'000;\ntemplate <>\nconstexpr double infty<double> =\
    \ infty<i128>;\ntemplate <>\nconstexpr long double infty<long double> = infty<i128>;\n\
    \nusing pi = pair<ll, ll>;\nusing vi = vector<ll>;\ntemplate <class T>\nusing\
    \ vc = vector<T>;\ntemplate <class T>\nusing vvc = vector<vc<T>>;\ntemplate <class\
    \ T>\nusing vvvc = vector<vvc<T>>;\ntemplate <class T>\nusing vvvvc = vector<vvvc<T>>;\n\
    template <class T>\nusing pq_max = priority_queue<T>;\ntemplate <class T>\nusing\
    \ pq_min = priority_queue<T, vector<T>, greater<T>>;\n\n#define vv(type, name,\
    \ h, ...) \\\n  vector<vector<type>> name(h, vector<type>(__VA_ARGS__))\n#define\
    \ vvv(type, name, h, w, ...)   \\\n  vector<vector<vector<type>>> name( \\\n \
    \     h, vector<vector<type>>(w, vector<type>(__VA_ARGS__)))\n#define vvvv(type,\
    \ name, a, b, c, ...)       \\\n  vector<vector<vector<vector<type>>>> name( \\\
    \n      a, vector<vector<vector<type>>>(       \\\n             b, vector<vector<type>>(c,\
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
    \ a);\n  a = c;\n  return changed;\n}\n\n// bit operations\nint popcnt(int x)\
    \ { return __builtin_popcount(x); }\nint popcnt(u32 x) { return __builtin_popcount(x);\
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
    T kth_bit(int k) {\n  assert(0 <= k && k < int(8 * sizeof(T)));\n  return T(1)\
    \ << k;\n}\ntemplate <typename T>\nbool has_kth_bit(T x, int k) {\n  assert(0\
    \ <= k && k < int(8 * sizeof(T)));\n  return x >> k & 1;\n}\n\ntemplate <typename\
    \ T>\nstruct all_bit {\n  static_assert(is_integral<T>::value);\n  T s;\n  all_bit(T\
    \ s) : s(s) { assert(s >= 0); }\n  struct iter {\n    T s;\n    int operator*()\
    \ const { return lowbit(s); }\n    void operator++() { s &= s - 1; }\n    bool\
    \ operator!=(nullptr_t) const { return s; }\n  };\n  iter begin() const { return\
    \ {s}; }\n  nullptr_t end() const { return nullptr; }\n};\n\ntemplate <typename\
    \ T>\nstruct all_subset {\n  static_assert(is_integral<T>::value);\n  T s;\n \
    \ all_subset(T s) : s(s) { assert(s >= 0); }\n  struct iter {\n    T s, t;\n \
    \   bool done = false;\n    T operator*() const { return t; }\n    void operator++()\
    \ {\n      done = (t == 0);\n      t = (t - 1) & s;\n    }\n    bool operator!=(nullptr_t)\
    \ const { return !done; }\n  };\n  iter begin() const { return {s, s}; }\n  nullptr_t\
    \ end() const { return nullptr; }\n};\n\nconstexpr u64 full_mask(int n) {\n  assert(0\
    \ <= n && n <= 64);\n  return n == 64 ? -1ULL : (1ULL << n) - 1;\n}\n\nu64 bit_reverse(u64\
    \ x) {\n  x = ((x & 0x5555555555555555ULL) << 1) | ((x >> 1) & 0x5555555555555555ULL);\n\
    \  x = ((x & 0x3333333333333333ULL) << 2) | ((x >> 2) & 0x3333333333333333ULL);\n\
    \  x = ((x & 0x0f0f0f0f0f0f0f0fULL) << 4) | ((x >> 4) & 0x0f0f0f0f0f0f0f0fULL);\n\
    \  x = ((x & 0x00ff00ff00ff00ffULL) << 8) | ((x >> 8) & 0x00ff00ff00ff00ffULL);\n\
    \  x = ((x & 0x0000ffff0000ffffULL) << 16) | ((x >> 16) & 0x0000ffff0000ffffULL);\n\
    \  x = (x << 32) | (x >> 32);\n  return x;\n}\n\n// ? \u306F -1\nvc<int> s_to_vi(const\
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
    \    a = b, b = c;\n  }\n  return abs(a);\n}\n#endif  // MASPY_TEMPLATE_BODY\n\
    #line 1 \"geo/base.hpp\"\n// Source: https://github.com/maspypy/library/blob/main/geo/base.hpp\n\
    template <typename T>\nstruct Point {\n  T x, y;\n\n  Point() : x(0), y(0) {}\n\
    \n  template <typename A, typename B>\n  Point(A x, B y) : x(x), y(y) {}\n\n \
    \ template <typename A, typename B>\n  Point(pair<A, B> p) : x(p.fi), y(p.se)\
    \ {}\n\n  template <typename U>\n  Point(Point<U> p) : x(p.x), y(p.y) {\n    static_assert(!is_integral_v<T>\
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
    \ { assert(a != 0 || b != 0); }\n  Line(Point<T> A, Point<T> B) {\n    a = A.y\
    \ - B.y, b = B.x - A.x, c = A.x * B.y - A.y * B.x;\n    assert(a != 0 || b !=\
    \ 0);\n  }\n  Line(T x1, T y1, T x2, T y2) : Line(Point<T>(x1, y1), Point<T>(x2,\
    \ y2)) {}\n\n  template <typename U>\n  auto eval(Point<U> P) const {\n    return\
    \ eval(P.x, P.y);\n  }\n\n  template <typename U>\n  auto eval(U x, U y) const\
    \ {\n    return a * x + b * y + c;\n  }\n\n  // \u540C\u3058\u76F4\u7DDA\u304C\
    \u540C\u3058 a,b,c \u3067\u8868\u73FE\u3055\u308C\u308B\u3088\u3046\u306B\u3059\
    \u308B\n  void normalize() {\n    static_assert(is_same_v<T, int> || is_same_v<T,\
    \ long long>);\n    T g = gcd(gcd(abs(a), abs(b)), abs(c));\n    a /= g, b /=\
    \ g, c /= g;\n    if (b < 0) {\n      a = -a, b = -b, c = -c;\n    }\n    if (b\
    \ == 0 && a < 0) {\n      a = -a, b = -b, c = -c;\n    }\n  }\n\n  bool is_parallel(Line\
    \ other) { return a * other.b - b * other.a == 0; }\n  bool is_orthogonal(Line\
    \ other) { return a * other.a + b * other.b == 0; }\n  bool is_same(Line other)\
    \ {\n    if (a * other.b != b * other.a) return 0;\n    if (a * other.c != c *\
    \ other.a) return 0;\n    if (b * other.c != c * other.b) return 0;\n    return\
    \ 1;\n  }\n};\n\ntemplate <typename T>\nstruct Segment {\n  Point<T> A, B;\n\n\
    \  Segment(Point<T> A, Point<T> B) : A(A), B(B) { assert(A != B); }\n  Segment(T\
    \ x1, T y1, T x2, T y2)\n      : Segment(Point<T>(x1, y1), Point<T>(x2, y2)) {}\n\
    \n  bool contain(Point<T> C) {\n    T det = (C - A).det(B - A);\n    if (det !=\
    \ 0) return 0;\n    return (C - A).dot(B - A) >= 0 && (C - B).dot(A - B) >= 0;\n\
    \  }\n\n  Line<T> to_line() { return Line(A, B); }\n};\n\ntemplate <typename REAL>\n\
    struct Circle {\n  Point<REAL> O;\n  REAL r;\n  Circle() {}\n  Circle(Point<REAL>\
    \ O, REAL r) : O(O), r(r) {}\n  Circle(REAL x, REAL y, REAL r) : O(x, y), r(r)\
    \ {}\n  template <typename T>\n  bool contain(Point<T> p) {\n    REAL dx = p.x\
    \ - O.x, dy = p.y - O.y;\n    return dx * dx + dy * dy <= r * r;\n  }\n};\n#line\
    \ 1 \"geo/pick_formula.hpp\"\n// Source: https://github.com/maspypy/library/blob/main/geo/pick_formula.hpp\n\
    \n// input: ccw simple polygon\n// return: area2, inner, boundary\ntemplate <typename\
    \ T>\ntuple<i128, i128, i128> pick_formula(vc<Point<T>>& A) {\n  using P = Point<T>;\n\
    \  int N = len(A);\n  i128 area2 = 0;\n  i128 bd = 0;\n  FOR(i, N) {\n    P a\
    \ = A[i], b = A[(i + 1) % N];\n    area2 += i128(a.x) * b.y - i128(a.y) * b.x;\n\
    \    P d = b - a;\n    bd += gcd(d.x, d.y);\n  }\n  assert(area2 >= 0);\n  i128\
    \ in = (area2 + 2 - bd) / 2;\n  return {area2, in, bd};\n}\n#line 4 \"test/5_ai_generated_test/pick_formula_ccw_lattice_points.test.cpp\"\
    \n\n// \u53CD\u6642\u8A08\u56DE\u308A\u306E\u5358\u7D14\u306A\u683C\u5B50\u591A\
    \u89D2\u5F62\u3060\u3051\u3092\u6E21\u3059\u3002\u5883\u754C\u70B9\u306F\u7DDA\
    \u5206\u4E0A\u5224\u5B9A\u3001\n// \u5185\u70B9\u306F\u6C34\u5E73\u534A\u76F4\u7DDA\
    \u3068\u306E\u4EA4\u5DEE\u306E\u5076\u5947\u3067\u6570\u3048\u3001Pick \u306E\u516C\
    \u5F0F\u3084 gcd \u306F\u4F7F\u308F\u306A\u3044\u3002\n// \u9762\u7A4D\u306F\u751F\
    \u6210\u5143\u306E\u4E09\u89D2\u5F62\u30FB\u9577\u65B9\u5F62\u30FB\u6B20\u3051\
    \u305F\u9577\u65B9\u5F62\u306E\u9762\u7A4D\u3068\u5909\u63DB\u306E\u884C\u5217\
    \u5F0F\u3067\u6C42\u3081\u308B\u3002\n// \u51F9\u9802\u70B9\u3001\u6C34\u5E73\u8FBA\
    \u3001\u540C\u4E00\u76F4\u7DDA\u4E0A\u306E\u9023\u7D9A\u8FBA\u3001\u659C\u3081\
    \u306E\u683C\u5B50\u8FBA\u3001\u5DE8\u5927\u306A\u5E73\u884C\u79FB\u52D5\u3082\
    \u78BA\u8A8D\u3059\u308B\u3002\n\nnamespace {\nusing P = Point<ll>;\n\ntuple<i128,\
    \ i128, i128> enumerate_points(const vc<P>& a, i128 area2) {\n  ll xmin = a[0].x,\
    \ xmax = xmin, ymin = a[0].y, ymax = ymin;\n  for (P p : a) {\n    xmin = min(xmin,\
    \ p.x), xmax = max(xmax, p.x);\n    ymin = min(ymin, p.y), ymax = max(ymax, p.y);\n\
    \  }\n\n  i128 inner = 0, boundary = 0;\n  for (ll x = xmin; x <= xmax; ++x) {\n\
    \    for (ll y = ymin; y <= ymax; ++y) {\n      bool inside = false, on_edge =\
    \ false;\n      for (size_t i = 0; i < a.size(); ++i) {\n        P p = a[i], q\
    \ = a[(i + 1) % a.size()];\n        if (p.y > q.y) swap(p, q);\n        i128 side\
    \ = (i128(q.x) - p.x) * (i128(y) - p.y)\n                  - (i128(q.y) - p.y)\
    \ * (i128(x) - p.x);\n        if (side == 0 && min(p.x, q.x) <= x && x <= max(p.x,\
    \ q.x)\n                      && p.y <= y && y <= q.y) {\n          on_edge =\
    \ true;\n          break;\n        }\n        // \u4E0A\u5074\u7AEF\u70B9\u3092\
    \u9664\u5916\u3057\u3001\u9802\u70B9\u3092\u901A\u308B\u534A\u76F4\u7DDA\u3067\
    \u306E\u4E8C\u91CD\u30AB\u30A6\u30F3\u30C8\u3092\u9632\u3050\u3002\n        if\
    \ (p.y <= y && y < q.y && side > 0) inside = !inside;\n      }\n      boundary\
    \ += on_edge;\n      inner += !on_edge && inside;\n    }\n  }\n  return {area2,\
    \ inner, boundary};\n}\n\nvoid test_polygon(vc<P> points, tuple<i128, i128, i128>\
    \ want, int id) {\n  auto got = pick_formula(points);\n  if (got == want) return;\n\
    \  cerr << \"pick_formula mismatch at case \" << id << ':';\n  for (P p : points)\
    \ cerr << \" (\" << p.x << ',' << p.y << ')';\n  cerr << \"; area2/inner/boundary\
    \ agreement = \"\n       << (get<0>(got) == get<0>(want)) << '/'\n       << (get<1>(got)\
    \ == get<1>(want)) << '/'\n       << (get<2>(got) == get<2>(want)) << '\\n';\n\
    \  abort();\n}\n}  // namespace\n\nint main() {\n  int id = 0;\n  const array<array<ll,\
    \ 4>, 4> matrices{{\n      {1, 0, 0, 1}, {1, 2, -1, 1}, {0, -2, 1, 1}, {-2, 1,\
    \ -1, -1}\n  }};\n  constexpr ll big = 4'000'000'000'000'000'000LL;\n  auto check\
    \ = [&](const vc<P>& shape, ll base_area2) {\n    for (auto [a, b, c, d] : matrices)\
    \ {\n      for (auto [sx, sy] : {pair<ll, ll>{-13, 11}, {big, -big}, {-big, big}})\
    \ {\n        vc<P> poly;\n        for (P p : shape) poly.emplace_back(a * p.x\
    \ + b * p.y + sx,\n                                             c * p.x + d *\
    \ p.y + sy);\n        rotate(poly.begin(), poly.begin() + (id % poly.size()),\
    \ poly.end());\n        test_polygon(poly, enumerate_points(poly, base_area2 *\
    \ (a*d - b*c)), id++);\n      }\n    }\n  };\n\n  for (ll w = 1; w <= 5; ++w)\
    \ {\n    for (ll h = 1; h <= 5; ++h) {\n      check({{0, 0}, {w, 0}, {0, h}},\
    \ w*h);\n      for (ll cut_x = 1; cut_x < w; ++cut_x) {\n        check({{0, 0},\
    \ {cut_x, 0}, {w, 0}, {w, h}, {0, h}}, 2*w*h);\n        for (ll cut_y = 1; cut_y\
    \ < h; ++cut_y) {\n          check({{0, 0}, {w, 0}, {w, cut_y}, {cut_x, cut_y},\
    \ {cut_x, h}, {0, h}},\n                2*(w*h - (w-cut_x)*(h-cut_y)));\n    \
    \    }\n      }\n    }\n  }\n\n  // \u5185\u70B9\u6570\u3068\u9762\u7A4D\u304C\
    \ 64 bit \u306B\u53CE\u307E\u3089\u306A\u3044\u30B1\u30FC\u30B9\u3002\u9577\u65B9\
    \u5F62\u3060\u3051\u306F\u9589\u5F62\u5F0F\u3067\u691C\u67FB\u3059\u308B\u3002\
    \n  constexpr ll w = 4'000'000'001LL, h = 4'000'000'003LL;\n  test_polygon({{-big,\
    \ big}, {-big+w, big}, {-big+w, big+h}, {-big, big+h}},\n               {2*i128(w)*h,\
    \ i128(w-1)*(h-1), 2*i128(w+h)}, id++);\n  cout << \"pick_formula: \" << id <<\
    \ \" cases passed\\n\";\n}\n"
  code: "#include \"my_template.hpp\"\n#include \"geo/base.hpp\"\n#include \"geo/pick_formula.hpp\"\
    \n\n// \u53CD\u6642\u8A08\u56DE\u308A\u306E\u5358\u7D14\u306A\u683C\u5B50\u591A\
    \u89D2\u5F62\u3060\u3051\u3092\u6E21\u3059\u3002\u5883\u754C\u70B9\u306F\u7DDA\
    \u5206\u4E0A\u5224\u5B9A\u3001\n// \u5185\u70B9\u306F\u6C34\u5E73\u534A\u76F4\u7DDA\
    \u3068\u306E\u4EA4\u5DEE\u306E\u5076\u5947\u3067\u6570\u3048\u3001Pick \u306E\u516C\
    \u5F0F\u3084 gcd \u306F\u4F7F\u308F\u306A\u3044\u3002\n// \u9762\u7A4D\u306F\u751F\
    \u6210\u5143\u306E\u4E09\u89D2\u5F62\u30FB\u9577\u65B9\u5F62\u30FB\u6B20\u3051\
    \u305F\u9577\u65B9\u5F62\u306E\u9762\u7A4D\u3068\u5909\u63DB\u306E\u884C\u5217\
    \u5F0F\u3067\u6C42\u3081\u308B\u3002\n// \u51F9\u9802\u70B9\u3001\u6C34\u5E73\u8FBA\
    \u3001\u540C\u4E00\u76F4\u7DDA\u4E0A\u306E\u9023\u7D9A\u8FBA\u3001\u659C\u3081\
    \u306E\u683C\u5B50\u8FBA\u3001\u5DE8\u5927\u306A\u5E73\u884C\u79FB\u52D5\u3082\
    \u78BA\u8A8D\u3059\u308B\u3002\n\nnamespace {\nusing P = Point<ll>;\n\ntuple<i128,\
    \ i128, i128> enumerate_points(const vc<P>& a, i128 area2) {\n  ll xmin = a[0].x,\
    \ xmax = xmin, ymin = a[0].y, ymax = ymin;\n  for (P p : a) {\n    xmin = min(xmin,\
    \ p.x), xmax = max(xmax, p.x);\n    ymin = min(ymin, p.y), ymax = max(ymax, p.y);\n\
    \  }\n\n  i128 inner = 0, boundary = 0;\n  for (ll x = xmin; x <= xmax; ++x) {\n\
    \    for (ll y = ymin; y <= ymax; ++y) {\n      bool inside = false, on_edge =\
    \ false;\n      for (size_t i = 0; i < a.size(); ++i) {\n        P p = a[i], q\
    \ = a[(i + 1) % a.size()];\n        if (p.y > q.y) swap(p, q);\n        i128 side\
    \ = (i128(q.x) - p.x) * (i128(y) - p.y)\n                  - (i128(q.y) - p.y)\
    \ * (i128(x) - p.x);\n        if (side == 0 && min(p.x, q.x) <= x && x <= max(p.x,\
    \ q.x)\n                      && p.y <= y && y <= q.y) {\n          on_edge =\
    \ true;\n          break;\n        }\n        // \u4E0A\u5074\u7AEF\u70B9\u3092\
    \u9664\u5916\u3057\u3001\u9802\u70B9\u3092\u901A\u308B\u534A\u76F4\u7DDA\u3067\
    \u306E\u4E8C\u91CD\u30AB\u30A6\u30F3\u30C8\u3092\u9632\u3050\u3002\n        if\
    \ (p.y <= y && y < q.y && side > 0) inside = !inside;\n      }\n      boundary\
    \ += on_edge;\n      inner += !on_edge && inside;\n    }\n  }\n  return {area2,\
    \ inner, boundary};\n}\n\nvoid test_polygon(vc<P> points, tuple<i128, i128, i128>\
    \ want, int id) {\n  auto got = pick_formula(points);\n  if (got == want) return;\n\
    \  cerr << \"pick_formula mismatch at case \" << id << ':';\n  for (P p : points)\
    \ cerr << \" (\" << p.x << ',' << p.y << ')';\n  cerr << \"; area2/inner/boundary\
    \ agreement = \"\n       << (get<0>(got) == get<0>(want)) << '/'\n       << (get<1>(got)\
    \ == get<1>(want)) << '/'\n       << (get<2>(got) == get<2>(want)) << '\\n';\n\
    \  abort();\n}\n}  // namespace\n\nint main() {\n  int id = 0;\n  const array<array<ll,\
    \ 4>, 4> matrices{{\n      {1, 0, 0, 1}, {1, 2, -1, 1}, {0, -2, 1, 1}, {-2, 1,\
    \ -1, -1}\n  }};\n  constexpr ll big = 4'000'000'000'000'000'000LL;\n  auto check\
    \ = [&](const vc<P>& shape, ll base_area2) {\n    for (auto [a, b, c, d] : matrices)\
    \ {\n      for (auto [sx, sy] : {pair<ll, ll>{-13, 11}, {big, -big}, {-big, big}})\
    \ {\n        vc<P> poly;\n        for (P p : shape) poly.emplace_back(a * p.x\
    \ + b * p.y + sx,\n                                             c * p.x + d *\
    \ p.y + sy);\n        rotate(poly.begin(), poly.begin() + (id % poly.size()),\
    \ poly.end());\n        test_polygon(poly, enumerate_points(poly, base_area2 *\
    \ (a*d - b*c)), id++);\n      }\n    }\n  };\n\n  for (ll w = 1; w <= 5; ++w)\
    \ {\n    for (ll h = 1; h <= 5; ++h) {\n      check({{0, 0}, {w, 0}, {0, h}},\
    \ w*h);\n      for (ll cut_x = 1; cut_x < w; ++cut_x) {\n        check({{0, 0},\
    \ {cut_x, 0}, {w, 0}, {w, h}, {0, h}}, 2*w*h);\n        for (ll cut_y = 1; cut_y\
    \ < h; ++cut_y) {\n          check({{0, 0}, {w, 0}, {w, cut_y}, {cut_x, cut_y},\
    \ {cut_x, h}, {0, h}},\n                2*(w*h - (w-cut_x)*(h-cut_y)));\n    \
    \    }\n      }\n    }\n  }\n\n  // \u5185\u70B9\u6570\u3068\u9762\u7A4D\u304C\
    \ 64 bit \u306B\u53CE\u307E\u3089\u306A\u3044\u30B1\u30FC\u30B9\u3002\u9577\u65B9\
    \u5F62\u3060\u3051\u306F\u9589\u5F62\u5F0F\u3067\u691C\u67FB\u3059\u308B\u3002\
    \n  constexpr ll w = 4'000'000'001LL, h = 4'000'000'003LL;\n  test_polygon({{-big,\
    \ big}, {-big+w, big}, {-big+w, big+h}, {-big, big+h}},\n               {2*i128(w)*h,\
    \ i128(w-1)*(h-1), 2*i128(w+h)}, id++);\n  cout << \"pick_formula: \" << id <<\
    \ \" cases passed\\n\";\n}\n"
  dependsOn:
  - my_template.hpp
  - geo/base.hpp
  - geo/pick_formula.hpp
  isVerificationFile: true
  path: test/5_ai_generated_test/pick_formula_ccw_lattice_points.test.cpp
  requiredBy: []
  timestamp: '2026-11-29 04:16:05+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: test/5_ai_generated_test/pick_formula_ccw_lattice_points.test.cpp
layout: document
redirect_from:
- /verify/test/5_ai_generated_test/pick_formula_ccw_lattice_points.test.cpp
- /verify/test/5_ai_generated_test/pick_formula_ccw_lattice_points.test.cpp.html
title: test/5_ai_generated_test/pick_formula_ccw_lattice_points.test.cpp
---
