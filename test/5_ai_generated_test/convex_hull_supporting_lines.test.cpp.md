---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: geo/base.hpp
    title: geo/base.hpp
  - icon: ':heavy_check_mark:'
    path: geo/convex_hull.hpp
    title: geo/convex_hull.hpp
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
    #line 1 \"geo/convex_hull.hpp\"\n// Source: https://github.com/maspypy/library/blob/main/geo/convex_hull.hpp\n\
    \n#line 1 \"geo/base.hpp\"\n// Source: https://github.com/maspypy/library/blob/main/geo/base.hpp\n\
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
    \ 4 \"geo/convex_hull.hpp\"\n\n// allow_180=true \u3067\u540C\u4E00\u5EA7\u6A19\
    \u70B9\u304C\u3042\u308B\u3068\u3053\u308F\u308C\u308B\n// full \u306A\u3089 I[0]\
    \ \u304C sorted \u3067 min \u306B\u306A\u308B\ntemplate <typename T, bool allow_180\
    \ = false>\nvector<int> convex_hull(vector<Point<T>>& XY, string mode = \"full\"\
    ,\n                        bool sorted = false) {\n  assert(mode == \"full\" ||\
    \ mode == \"lower\" || mode == \"upper\");\n  ll N = XY.size();\n  if (N == 1)\
    \ return {0};\n  if (N == 2) {\n    if (XY[0] < XY[1]) return {0, 1};\n    if\
    \ (XY[1] < XY[0]) return {1, 0};\n    return {0};\n  }\n  vc<int> I(N);\n  if\
    \ (sorted) {\n    FOR(i, N) I[i] = i;\n  } else {\n    I = argsort(XY);\n  }\n\
    \  if constexpr (allow_180) {\n    FOR(i, N - 1) assert(XY[i] != XY[i + 1]);\n\
    \  }\n\n  auto check = [&](ll i, ll j, ll k) -> bool {\n    T det = (XY[j] - XY[i]).det(XY[k]\
    \ - XY[i]);\n    if constexpr (allow_180) return det >= 0;\n    return det > T(0);\n\
    \  };\n\n  auto calc = [&]() {\n    vector<int> P;\n    for (auto&& k : I) {\n\
    \      while (P.size() > 1) {\n        auto i = P[P.size() - 2];\n        auto\
    \ j = P[P.size() - 1];\n        if (check(i, j, k)) break;\n        P.pop_back();\n\
    \      }\n      P.eb(k);\n    }\n    return P;\n  };\n\n  vc<int> P;\n  if (mode\
    \ == \"full\" || mode == \"lower\") {\n    vc<int> Q = calc();\n    P.insert(P.end(),\
    \ all(Q));\n  }\n  if (mode == \"full\" || mode == \"upper\") {\n    if (!P.empty())\
    \ P.pop_back();\n    reverse(all(I));\n    vc<int> Q = calc();\n    P.insert(P.end(),\
    \ all(Q));\n  }\n  if (mode == \"upper\") reverse(all(P));\n  while (len(P) >=\
    \ 2 && XY[P[0]] == XY[P.back()]) P.pop_back();\n  return P;\n}\n#line 3 \"test/5_ai_generated_test/convex_hull_supporting_lines.test.cpp\"\
    \n\n// \u5C0F\u70B9\u96C6\u5408\u304B\u3089\u652F\u6301\u7DDA\u3092\u5168\u63A2\
    \u7D22\u3002\u5358\u8ABF\u9396\u3092\u4F7F\u308F\u305A\u306B\u5916\u5468\u3092\
    \u7D44\u307F\u7ACB\u3066\u308B\u3002\n// \u91CD\u8907\u5EA7\u6A19\u306E\u4EE3\u8868\
    \ index \u306F\u898F\u5B9A\u305B\u305A\u3001\u5EA7\u6A19\u5217\u3060\u3051\u3092\
    \u6BD4\u8F03\u3059\u308B\u3002\nusing P=Point<ll>;\ni128 cross(P a,P b,P c) {\n\
    \  return (i128(b.x)-a.x)*(i128(c.y)-a.y)-(i128(b.y)-a.y)*(i128(c.x)-a.x);\n}\n\
    vc<P> oracle(vc<P> a,bool keep,string mode) {\n  sort(a.begin(),a.end());\n  a.erase(unique(a.begin(),a.end()),a.end());\n\
    \  int n=a.size();\n  if(n<=1) return a;\n  bool line=all_of(a.begin(),a.end(),[&](P\
    \ p){return cross(a.front(),a.back(),p)==0;});\n  if(line) return keep?a:vc<P>{a.front(),a.back()};\n\
    \  vc<int> next(n,-1);\n  for(int i=0;i<n;++i) for(int j=0;j<n;++j) {\n    if(i==j)\
    \ continue;\n    auto lo=min(a[i],a[j]),hi=max(a[i],a[j]);\n    bool ok=true;\n\
    \    for(int k=0;k<n;++k) {\n      i128 c=cross(a[i],a[j],a[k]);\n      if(c<0)\
    \ ok=false;\n      if(c==0 && k!=i && k!=j) {\n        bool between=lo<a[k] &&\
    \ a[k]<hi;\n        if(keep==between) ok=false;\n      }\n    }\n    if(ok) {\
    \ assert(next[i]==-1); next[i]=j; }\n  }\n  vc<P> full;\n  int i=0;\n  do {\n\
    \    full.push_back(a[i]);\n    assert(next[i]>=0 && int(full.size())<=n);\n \
    \   i=next[i];\n  } while(i!=0);\n  auto turn=max_element(full.begin(),full.end());\n\
    \  if(mode==\"lower\") return vc<P>(full.begin(),turn+1);\n  if(mode==\"upper\"\
    ) {\n    vc<P> r{full.front()};\n    for(auto j=full.end();j!=turn;){--j;r.push_back(*j);}\n\
    \    return r;\n  }\n  return full;\n}\nll calls=0;\ntemplate<bool keep>\nvoid\
    \ check(vc<P> a,int phase) {\n  bool line=a.size()<3 || all_of(a.begin(),a.end(),[&](P\
    \ p){return cross(a.front(),a.back(),p)==0;});\n  for(bool sorted:{false,true})\
    \ {\n    if(sorted) sort(a.begin(),a.end());\n    for(string mode:{\"full\",\"\
    lower\",\"upper\"}) {\n      // \u5168\u70B9\u5171\u7DDA\u306E keep/full \u306E\
    \u5F80\u5FA9\u5217\u306F\u4ED5\u69D8\u3092\u56FA\u5B9A\u305B\u305A\u3001\u7247\
    \u9396\u306E\u307F\u3092\u691C\u67FB\u3002\n      if(keep && line && mode==\"\
    full\" && a.size()>2) continue;\n      auto expect=oracle(a,keep,mode);\n    \
    \  vc<P> got;\n      for(int i:convex_hull<ll,keep>(a,mode,sorted)) {\n      \
    \  assert(0<=i && i<int(a.size())); got.push_back(a[i]);\n      }\n      if(got!=expect)\
    \ {\n        cerr<<\"phase=\"<<phase<<\" keep=\"<<keep<<\" sorted=\"<<sorted<<\"\
    \ mode=\"<<mode<<'\\n';\n        abort();\n      }\n      ++calls;\n    }\n  }\n\
    }\nint main() {\n  mt19937 rng(4504);\n  for(int mask=1;mask<512;++mask) {\n \
    \   vc<P> a;\n    for(int i=0;i<9;++i) if(mask>>i&1) a.emplace_back(i/3-1,i%3-1);\n\
    \    shuffle(a.begin(),a.end(),rng);\n    check<true>(a,mask);\n    for(int j=int(a.size())-1;j>=0;--j)\
    \ if(rng()%2) a.push_back(a[j]);\n    shuffle(a.begin(),a.end(),rng);\n    check<false>(a,mask);\n\
    \  }\n  for(int t=0;t<2000;++t) {\n    vc<P> a;\n    for(int j=1+rng()%16;j;--j)\
    \ {\n      ll x=int(rng()%11)-5,y=int(rng()%11)-5;\n      if(t%7==0) y=2*x;\n\
    \      else if(t%7==1) x=0;\n      if(t%3==0) { x+=4'000'000'000'000'000'000LL;\
    \ y-=4'000'000'000'000'000'000LL; }\n      a.emplace_back(x,y);\n    }\n    check<false>(a,512+t);\n\
    \    sort(a.begin(),a.end()); a.erase(unique(a.begin(),a.end()),a.end());\n  \
    \  shuffle(a.begin(),a.end(),rng);\n    check<true>(a,512+t);\n  }\n  cout<<calls<<\"\
    \ hull calls passed\\n\";\n}\n"
  code: "#include \"my_template.hpp\"\n#include \"geo/convex_hull.hpp\"\n\n// \u5C0F\
    \u70B9\u96C6\u5408\u304B\u3089\u652F\u6301\u7DDA\u3092\u5168\u63A2\u7D22\u3002\
    \u5358\u8ABF\u9396\u3092\u4F7F\u308F\u305A\u306B\u5916\u5468\u3092\u7D44\u307F\
    \u7ACB\u3066\u308B\u3002\n// \u91CD\u8907\u5EA7\u6A19\u306E\u4EE3\u8868 index\
    \ \u306F\u898F\u5B9A\u305B\u305A\u3001\u5EA7\u6A19\u5217\u3060\u3051\u3092\u6BD4\
    \u8F03\u3059\u308B\u3002\nusing P=Point<ll>;\ni128 cross(P a,P b,P c) {\n  return\
    \ (i128(b.x)-a.x)*(i128(c.y)-a.y)-(i128(b.y)-a.y)*(i128(c.x)-a.x);\n}\nvc<P> oracle(vc<P>\
    \ a,bool keep,string mode) {\n  sort(a.begin(),a.end());\n  a.erase(unique(a.begin(),a.end()),a.end());\n\
    \  int n=a.size();\n  if(n<=1) return a;\n  bool line=all_of(a.begin(),a.end(),[&](P\
    \ p){return cross(a.front(),a.back(),p)==0;});\n  if(line) return keep?a:vc<P>{a.front(),a.back()};\n\
    \  vc<int> next(n,-1);\n  for(int i=0;i<n;++i) for(int j=0;j<n;++j) {\n    if(i==j)\
    \ continue;\n    auto lo=min(a[i],a[j]),hi=max(a[i],a[j]);\n    bool ok=true;\n\
    \    for(int k=0;k<n;++k) {\n      i128 c=cross(a[i],a[j],a[k]);\n      if(c<0)\
    \ ok=false;\n      if(c==0 && k!=i && k!=j) {\n        bool between=lo<a[k] &&\
    \ a[k]<hi;\n        if(keep==between) ok=false;\n      }\n    }\n    if(ok) {\
    \ assert(next[i]==-1); next[i]=j; }\n  }\n  vc<P> full;\n  int i=0;\n  do {\n\
    \    full.push_back(a[i]);\n    assert(next[i]>=0 && int(full.size())<=n);\n \
    \   i=next[i];\n  } while(i!=0);\n  auto turn=max_element(full.begin(),full.end());\n\
    \  if(mode==\"lower\") return vc<P>(full.begin(),turn+1);\n  if(mode==\"upper\"\
    ) {\n    vc<P> r{full.front()};\n    for(auto j=full.end();j!=turn;){--j;r.push_back(*j);}\n\
    \    return r;\n  }\n  return full;\n}\nll calls=0;\ntemplate<bool keep>\nvoid\
    \ check(vc<P> a,int phase) {\n  bool line=a.size()<3 || all_of(a.begin(),a.end(),[&](P\
    \ p){return cross(a.front(),a.back(),p)==0;});\n  for(bool sorted:{false,true})\
    \ {\n    if(sorted) sort(a.begin(),a.end());\n    for(string mode:{\"full\",\"\
    lower\",\"upper\"}) {\n      // \u5168\u70B9\u5171\u7DDA\u306E keep/full \u306E\
    \u5F80\u5FA9\u5217\u306F\u4ED5\u69D8\u3092\u56FA\u5B9A\u305B\u305A\u3001\u7247\
    \u9396\u306E\u307F\u3092\u691C\u67FB\u3002\n      if(keep && line && mode==\"\
    full\" && a.size()>2) continue;\n      auto expect=oracle(a,keep,mode);\n    \
    \  vc<P> got;\n      for(int i:convex_hull<ll,keep>(a,mode,sorted)) {\n      \
    \  assert(0<=i && i<int(a.size())); got.push_back(a[i]);\n      }\n      if(got!=expect)\
    \ {\n        cerr<<\"phase=\"<<phase<<\" keep=\"<<keep<<\" sorted=\"<<sorted<<\"\
    \ mode=\"<<mode<<'\\n';\n        abort();\n      }\n      ++calls;\n    }\n  }\n\
    }\nint main() {\n  mt19937 rng(4504);\n  for(int mask=1;mask<512;++mask) {\n \
    \   vc<P> a;\n    for(int i=0;i<9;++i) if(mask>>i&1) a.emplace_back(i/3-1,i%3-1);\n\
    \    shuffle(a.begin(),a.end(),rng);\n    check<true>(a,mask);\n    for(int j=int(a.size())-1;j>=0;--j)\
    \ if(rng()%2) a.push_back(a[j]);\n    shuffle(a.begin(),a.end(),rng);\n    check<false>(a,mask);\n\
    \  }\n  for(int t=0;t<2000;++t) {\n    vc<P> a;\n    for(int j=1+rng()%16;j;--j)\
    \ {\n      ll x=int(rng()%11)-5,y=int(rng()%11)-5;\n      if(t%7==0) y=2*x;\n\
    \      else if(t%7==1) x=0;\n      if(t%3==0) { x+=4'000'000'000'000'000'000LL;\
    \ y-=4'000'000'000'000'000'000LL; }\n      a.emplace_back(x,y);\n    }\n    check<false>(a,512+t);\n\
    \    sort(a.begin(),a.end()); a.erase(unique(a.begin(),a.end()),a.end());\n  \
    \  shuffle(a.begin(),a.end(),rng);\n    check<true>(a,512+t);\n  }\n  cout<<calls<<\"\
    \ hull calls passed\\n\";\n}\n"
  dependsOn:
  - my_template.hpp
  - geo/convex_hull.hpp
  - geo/base.hpp
  isVerificationFile: true
  path: test/5_ai_generated_test/convex_hull_supporting_lines.test.cpp
  requiredBy: []
  timestamp: '2026-11-29 04:16:05+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: test/5_ai_generated_test/convex_hull_supporting_lines.test.cpp
layout: document
redirect_from:
- /verify/test/5_ai_generated_test/convex_hull_supporting_lines.test.cpp
- /verify/test/5_ai_generated_test/convex_hull_supporting_lines.test.cpp.html
title: test/5_ai_generated_test/convex_hull_supporting_lines.test.cpp
---
