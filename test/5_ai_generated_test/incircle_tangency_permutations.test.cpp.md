---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: geo/base.hpp
    title: geo/base.hpp
  - icon: ':heavy_check_mark:'
    path: geo/incircle.hpp
    title: geo/incircle.hpp
  - icon: ':heavy_check_mark:'
    path: geo/triangle_area.hpp
    title: geo/triangle_area.hpp
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
    #line 1 \"geo/incircle.hpp\"\n// Source: https://github.com/maspypy/library/blob/main/geo/incircle.hpp\n\
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
    \ 1 \"geo/triangle_area.hpp\"\n// Source: https://github.com/maspypy/library/blob/main/geo/triangle_area.hpp\n\
    template <typename REAL, typename T>\nREAL triangle_area(Point<T> A, Point<T>\
    \ B, Point<T> C) {\n  return abs((B - A).det(C - A)) * 0.5;\n}\n#line 4 \"geo/incircle.hpp\"\
    \n\ntemplate <typename REAL, typename T>\nCircle<REAL> incircle(Point<T> A, Point<T>\
    \ B, Point<T> C) {\n  REAL a = distance<REAL, T, T>(B, C);\n  REAL b = distance<REAL,\
    \ T, T>(C, A);\n  REAL c = distance<REAL, T, T>(A, B);\n  REAL x = (a * A.x +\
    \ b * B.x + c * C.x) / (a + b + c);\n  REAL y = (a * A.y + b * B.y + c * C.y)\
    \ / (a + b + c);\n  REAL r = 2 * triangle_area<REAL>(A, B, C) / (a + b + c);\n\
    \  return Circle<REAL>(x, y, r);\n}\n#line 3 \"test/5_ai_generated_test/incircle_tangency_permutations.test.cpp\"\
    \n\n// \u975E\u9000\u5316\u306E\u6574\u6570\u5EA7\u6A19\u4E09\u89D2\u5F62\u306B\
    \u5BFE\u3057\u3001\u4E2D\u5FC3\u304C\u4E09\u8FBA\u306E\u5185\u5074\u306B\u3042\
    \u308A\u3001\u5404\u8FBA\u307E\u3067\u306E\n// \u7B26\u53F7\u4ED8\u304D\u8DDD\u96E2\
    \u304C\u534A\u5F84\u3068\u4E00\u81F4\u3059\u308B\u3053\u3068\u3092\u691C\u67FB\
    \u3059\u308B\u3002\u8FBA\u9577\u52A0\u91CD\u5E73\u5747\u306F\u4F7F\u308F\u306A\
    \u3044\u3002\n// 3-4-5\u4E09\u89D2\u5F62\u306E\u9589\u5F62\u5F0F\u30016\u901A\u308A\
    \u306E\u9806\u5E8F\u3001\u884C\u5217\u5F0F1\u306E\u7D30\u9577\u3044\u4E09\u89D2\
    \u5F62\u3082\u691C\u8A3C\u3002\n// \u6574\u6570\u306E\u8FBA\u5DEE\u3068\u5916\u7A4D\
    \u306Fll\u3067\u8868\u305B\u308B\u7BC4\u56F2\u306B\u9650\u5B9A\u3002\u4E71\u6570\
    seed\u306F\u56FA\u5B9A\u3002\n\nnamespace {\nusing P = Point<ll>;\nusing Tri =\
    \ array<P, 3>;\nint triangles = 0, calls = 0;\n\nlong double cross(P a, P b, P\
    \ c) {\n  return (long double)(b.x-a.x)*(c.y-a.y) - (long double)(b.y-a.y)*(c.x-a.x);\n\
    }\n\ntemplate<class Real>\nvoid verify(const Tri& base, optional<array<long double,\
    \ 3>> exact = nullopt) {\n  long double orient = cross(base[0],base[1],base[2]);\n\
    \  long double scale = 1;\n  for (P p : base) scale = max({scale, fabsl(p.x),\
    \ fabsl(p.y)});\n  const long double eps = 32 * numeric_limits<Real>::epsilon()\
    \ * scale;\n  auto require = [&](bool ok, const char* label, long double observed,\
    \ long double expected) {\n    if (ok) return;\n    cerr << \"incircle \" << label\
    \ << \" real_bytes=\" << sizeof(Real)\n         << \" case=\" << triangles <<\
    \ \" got=\" << setprecision(18) << observed\n         << \" want=\" << expected\
    \ << \" tolerance=\" << eps;\n    for (P p : base) cerr << \" (\" << p.x << ','\
    \ << p.y << ')';\n    cerr << '\\n';\n    abort();\n  };\n  array<int,3> ids{0,1,2};\n\
    \  array<long double,3> baseline{};\n  do {\n    auto c = incircle<Real>(base[ids[0]],base[ids[1]],base[ids[2]]);\n\
    \    array<long double,3> result{c.O.x,c.O.y,c.r};\n    require(c.r > 0, \"positive\
    \ radius\", c.r, 0);\n    for (int j=0;j<3;++j) {\n      P a=base[j], b=base[(j+1)%3];\n\
    \      long double dx=b.x-a.x, dy=b.y-a.y;\n      long double d=(dx*(result[1]-a.y)\
    \ - dy*(result[0]-a.x))/hypotl(dx,dy);\n      if (orient<0) d=-d;\n      require(d>0\
    \ && fabsl(d-result[2])<=eps, \"side distance\", d,result[2]);\n    }\n    if\
    \ (ids == array<int,3>{0,1,2}) baseline=result;\n    for(int j=0;j<3;++j) {\n\
    \      require(fabsl(result[j]-baseline[j])<=eps, \"permutation\", result[j],baseline[j]);\n\
    \      if(exact) require(fabsl(result[j]-(*exact)[j])<=eps, \"3-4-5\", result[j],(*exact)[j]);\n\
    \    }\n    ++calls;\n  } while(next_permutation(ids.begin(),ids.end()));\n}\n\
    \nvoid test(const Tri& t, optional<array<long double,3>> exact = nullopt) {\n\
    \  ++triangles;\n  verify<double>(t,exact);\n  verify<long double>(t,exact);\n\
    }\n}  // namespace\n\nint main() {\n  for (ll s : {1LL, 19LL, 100000LL}) {\n \
    \   for (ll y : {-1000000LL, 0LL, 1000000LL}) {\n      test({P{0,y},P{3*s,y},P{0,y+4*s}},array<long\
    \ double,3>{1.L*s,1.L*(y+s),1.L*s});\n      test({P{0,y},P{-4*s,y},P{0,y+3*s}},array<long\
    \ double,3>{-1.L*s,1.L*(y+s),1.L*s});\n    }\n  }\n  for (ll n : {10LL, 1000LL,\
    \ 100000LL}) test({P{0,0},P{n,1},P{n-1,1}});\n\n  mt19937 rng(0x14c1c1);\n  for\
    \ (int i=0;i<3000;) {\n    Tri t{};\n    for (auto& p : t) p=P{int(rng()%2001)-1000,int(rng()%2001)-1000};\n\
    \    if (cross(t[0],t[1],t[2])==0) continue;\n    test(t);\n    ++i;\n  }\n  cout\
    \ << \"incircle: \" << triangles << \" triangles, \" << calls << \" calls passed\\\
    n\";\n}\n"
  code: "#include \"my_template.hpp\"\n#include \"geo/incircle.hpp\"\n\n// \u975E\u9000\
    \u5316\u306E\u6574\u6570\u5EA7\u6A19\u4E09\u89D2\u5F62\u306B\u5BFE\u3057\u3001\
    \u4E2D\u5FC3\u304C\u4E09\u8FBA\u306E\u5185\u5074\u306B\u3042\u308A\u3001\u5404\
    \u8FBA\u307E\u3067\u306E\n// \u7B26\u53F7\u4ED8\u304D\u8DDD\u96E2\u304C\u534A\u5F84\
    \u3068\u4E00\u81F4\u3059\u308B\u3053\u3068\u3092\u691C\u67FB\u3059\u308B\u3002\
    \u8FBA\u9577\u52A0\u91CD\u5E73\u5747\u306F\u4F7F\u308F\u306A\u3044\u3002\n// 3-4-5\u4E09\
    \u89D2\u5F62\u306E\u9589\u5F62\u5F0F\u30016\u901A\u308A\u306E\u9806\u5E8F\u3001\
    \u884C\u5217\u5F0F1\u306E\u7D30\u9577\u3044\u4E09\u89D2\u5F62\u3082\u691C\u8A3C\
    \u3002\n// \u6574\u6570\u306E\u8FBA\u5DEE\u3068\u5916\u7A4D\u306Fll\u3067\u8868\
    \u305B\u308B\u7BC4\u56F2\u306B\u9650\u5B9A\u3002\u4E71\u6570seed\u306F\u56FA\u5B9A\
    \u3002\n\nnamespace {\nusing P = Point<ll>;\nusing Tri = array<P, 3>;\nint triangles\
    \ = 0, calls = 0;\n\nlong double cross(P a, P b, P c) {\n  return (long double)(b.x-a.x)*(c.y-a.y)\
    \ - (long double)(b.y-a.y)*(c.x-a.x);\n}\n\ntemplate<class Real>\nvoid verify(const\
    \ Tri& base, optional<array<long double, 3>> exact = nullopt) {\n  long double\
    \ orient = cross(base[0],base[1],base[2]);\n  long double scale = 1;\n  for (P\
    \ p : base) scale = max({scale, fabsl(p.x), fabsl(p.y)});\n  const long double\
    \ eps = 32 * numeric_limits<Real>::epsilon() * scale;\n  auto require = [&](bool\
    \ ok, const char* label, long double observed, long double expected) {\n    if\
    \ (ok) return;\n    cerr << \"incircle \" << label << \" real_bytes=\" << sizeof(Real)\n\
    \         << \" case=\" << triangles << \" got=\" << setprecision(18) << observed\n\
    \         << \" want=\" << expected << \" tolerance=\" << eps;\n    for (P p :\
    \ base) cerr << \" (\" << p.x << ',' << p.y << ')';\n    cerr << '\\n';\n    abort();\n\
    \  };\n  array<int,3> ids{0,1,2};\n  array<long double,3> baseline{};\n  do {\n\
    \    auto c = incircle<Real>(base[ids[0]],base[ids[1]],base[ids[2]]);\n    array<long\
    \ double,3> result{c.O.x,c.O.y,c.r};\n    require(c.r > 0, \"positive radius\"\
    , c.r, 0);\n    for (int j=0;j<3;++j) {\n      P a=base[j], b=base[(j+1)%3];\n\
    \      long double dx=b.x-a.x, dy=b.y-a.y;\n      long double d=(dx*(result[1]-a.y)\
    \ - dy*(result[0]-a.x))/hypotl(dx,dy);\n      if (orient<0) d=-d;\n      require(d>0\
    \ && fabsl(d-result[2])<=eps, \"side distance\", d,result[2]);\n    }\n    if\
    \ (ids == array<int,3>{0,1,2}) baseline=result;\n    for(int j=0;j<3;++j) {\n\
    \      require(fabsl(result[j]-baseline[j])<=eps, \"permutation\", result[j],baseline[j]);\n\
    \      if(exact) require(fabsl(result[j]-(*exact)[j])<=eps, \"3-4-5\", result[j],(*exact)[j]);\n\
    \    }\n    ++calls;\n  } while(next_permutation(ids.begin(),ids.end()));\n}\n\
    \nvoid test(const Tri& t, optional<array<long double,3>> exact = nullopt) {\n\
    \  ++triangles;\n  verify<double>(t,exact);\n  verify<long double>(t,exact);\n\
    }\n}  // namespace\n\nint main() {\n  for (ll s : {1LL, 19LL, 100000LL}) {\n \
    \   for (ll y : {-1000000LL, 0LL, 1000000LL}) {\n      test({P{0,y},P{3*s,y},P{0,y+4*s}},array<long\
    \ double,3>{1.L*s,1.L*(y+s),1.L*s});\n      test({P{0,y},P{-4*s,y},P{0,y+3*s}},array<long\
    \ double,3>{-1.L*s,1.L*(y+s),1.L*s});\n    }\n  }\n  for (ll n : {10LL, 1000LL,\
    \ 100000LL}) test({P{0,0},P{n,1},P{n-1,1}});\n\n  mt19937 rng(0x14c1c1);\n  for\
    \ (int i=0;i<3000;) {\n    Tri t{};\n    for (auto& p : t) p=P{int(rng()%2001)-1000,int(rng()%2001)-1000};\n\
    \    if (cross(t[0],t[1],t[2])==0) continue;\n    test(t);\n    ++i;\n  }\n  cout\
    \ << \"incircle: \" << triangles << \" triangles, \" << calls << \" calls passed\\\
    n\";\n}\n"
  dependsOn:
  - my_template.hpp
  - geo/incircle.hpp
  - geo/base.hpp
  - geo/triangle_area.hpp
  isVerificationFile: true
  path: test/5_ai_generated_test/incircle_tangency_permutations.test.cpp
  requiredBy: []
  timestamp: '2026-11-29 04:16:05+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: test/5_ai_generated_test/incircle_tangency_permutations.test.cpp
layout: document
redirect_from:
- /verify/test/5_ai_generated_test/incircle_tangency_permutations.test.cpp
- /verify/test/5_ai_generated_test/incircle_tangency_permutations.test.cpp.html
title: test/5_ai_generated_test/incircle_tangency_permutations.test.cpp
---
