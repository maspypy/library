---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: geo/base.hpp
    title: geo/base.hpp
  - icon: ':heavy_check_mark:'
    path: geo/incremental_convexhull.hpp
    title: geo/incremental_convexhull.hpp
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
    PROBLEM: https://judge.yosupo.jp/problem/aplusb
    links:
    - https://judge.yosupo.jp/problem/aplusb
  bundledCode: "#line 1 \"test/1_mytest/incremental_ch.test.cpp\"\n#define PROBLEM\
    \ \"https://judge.yosupo.jp/problem/aplusb\"\n#line 1 \"my_template.hpp\"\n#if\
    \ defined(LOCAL)\n#include <my_template_compiled.hpp>\n#else\n\n// https://codeforces.com/blog/entry/96344\n\
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
    \ others.begin(), others.end()), ...);\n}\n#endif\n#line 2 \"geo/base.hpp\"\n\
    template <typename T>\nstruct Point {\n  T x, y;\n\n  Point() : x(0), y(0) {}\n\
    \n  template <typename A, typename B>\n  Point(A x, B y) : x(x), y(y) {}\n\n \
    \ template <typename A, typename B>\n  Point(pair<A, B> p) : x(p.fi), y(p.se)\
    \ {}\n\n  Point operator+=(const Point p) {\n    x += p.x, y += p.y;\n    return\
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
    \ REAL, typename T, typename U>\nREAL dist(Point<T> A, Point<U> B) {\n  REAL dx\
    \ = REAL(A.x) - REAL(B.x);\n  REAL dy = REAL(A.y) - REAL(B.y);\n  return sqrt(dx\
    \ * dx + dy * dy);\n}\n\n// ax+by+c\ntemplate <typename T>\nstruct Line {\n  T\
    \ a, b, c;\n\n  Line(T a, T b, T c) : a(a), b(b), c(c) {}\n  Line(Point<T> A,\
    \ Point<T> B) { a = A.y - B.y, b = B.x - A.x, c = A.x * B.y - A.y * B.x; }\n \
    \ Line(T x1, T y1, T x2, T y2) : Line(Point<T>(x1, y1), Point<T>(x2, y2)) {}\n\
    \n  template <typename U>\n  U eval(Point<U> P) {\n    return U(a) * P.x + U(b)\
    \ * P.y + U(c);\n  }\n\n  template <typename U>\n  T eval(U x, U y) {\n    return\
    \ a * x + b * y + c;\n  }\n\n  // \u540C\u3058\u76F4\u7DDA\u304C\u540C\u3058 a,b,c\
    \ \u3067\u8868\u73FE\u3055\u308C\u308B\u3088\u3046\u306B\u3059\u308B\n  void normalize()\
    \ {\n    static_assert(is_same_v<T, int> || is_same_v<T, long long>);\n    T g\
    \ = gcd(gcd(abs(a), abs(b)), abs(c));\n    a /= g, b /= g, c /= g;\n    if (b\
    \ < 0) { a = -a, b = -b, c = -c; }\n    if (b == 0 && a < 0) { a = -a, b = -b,\
    \ c = -c; }\n  }\n\n  bool is_parallel(Line other) { return a * other.b - b *\
    \ other.a == 0; }\n  bool is_orthogonal(Line other) { return a * other.a + b *\
    \ other.b == 0; }\n};\n\ntemplate <typename T>\nstruct Segment {\n  Point<T> A,\
    \ B;\n\n  Segment(Point<T> A, Point<T> B) : A(A), B(B) {}\n  Segment(T x1, T y1,\
    \ T x2, T y2) : Segment(Point<T>(x1, y1), Point<T>(x2, y2)) {}\n\n  bool contain(Point<T>\
    \ C) {\n    T det = (C - A).det(B - A);\n    if (det != 0) return 0;\n    return\
    \ (C - A).dot(B - A) >= 0 && (C - B).dot(A - B) >= 0;\n  }\n\n  Line<T> to_Line()\
    \ { return Line(A, B); }\n};\n\ntemplate <typename REAL>\nstruct Circle {\n  Point<REAL>\
    \ O;\n  REAL r;\n  Circle() {}\n  Circle(Point<REAL> O, REAL r) : O(O), r(r) {}\n\
    \  Circle(REAL x, REAL y, REAL r) : O(x, y), r(r) {}\n  template <typename T>\n\
    \  bool contain(Point<T> p) {\n    REAL dx = p.x - O.x, dy = p.y - O.y;\n    return\
    \ dx * dx + dy * dy <= r * r;\n  }\n};\n#line 2 \"geo/incremental_convexhull.hpp\"\
    \n\n// \u4E0B\u5074\u51F8\u5305\ntemplate <typename T, bool strict = true>\nstruct\
    \ IncrementalConvexHull_Lower {\n  using P = Point<T>;\n  set<P> S;\n\n  IncrementalConvexHull_Lower()\
    \ {}\n\n  int size() { return len(S); }\n\n  template <typename ADD_V, typename\
    \ RM_V, typename ADD_E, typename RM_E>\n  void add(Point<T> p, ADD_V add_v, RM_V\
    \ rm_v, ADD_E add_e, RM_E rm_e) {\n    int s = side(p);\n    if (strict && s >=\
    \ 0) return;\n    if (!strict && s > 0) return;\n\n    // \u70B9\u8FFD\u52A0\n\
    \    add_v(p);\n    S.insert(p);\n\n    vc<P> left;\n    {\n      auto it = S.find(p);\n\
    \      while (it != S.begin()) {\n        --it;\n        if (left.empty()) {\n\
    \          left.eb(*it);\n          continue;\n        }\n        auto a = *it;\n\
    \        auto b = left.back();\n        T det = (b - a).det(p - a);\n        if\
    \ (strict && det > 0) break;\n        if (!strict && det >= 0) break;\n      \
    \  left.eb(a);\n      }\n    }\n\n    vc<P> right;\n    {\n      auto it = S.find(p);\n\
    \      while (1) {\n        ++it;\n        if (it == S.end()) break;\n       \
    \ if (right.empty()) {\n          right.eb(*it);\n          continue;\n      \
    \  }\n        auto a = right.back();\n        auto b = *it;\n        T det = (a\
    \ - p).det(b - p);\n        if (strict && det > 0) break;\n        if (!strict\
    \ && det >= 0) break;\n        right.eb(b);\n      }\n    }\n\n    // \u70B9\u524A\
    \u9664\n    if (len(left) > 1) { S.erase(next(S.find(left.back())), S.find(p));\
    \ }\n    if (len(right) > 1) { S.erase(next(S.find(p)), S.find(right.back()));\
    \ }\n    FOR(i, len(left) - 1) rm_v(left[i]);\n    FOR(i, len(right) - 1) rm_v(right[i]);\n\
    \n    // \u8FBA\u524A\u9664\n    if (len(left) && len(right)) {\n      auto a\
    \ = left[0], b = right[0];\n      rm_e(a, b);\n    }\n    FOR(i, len(left) - 1)\
    \ {\n      auto a = left[i + 1], b = left[i];\n      rm_e(a, b);\n    }\n    FOR(i,\
    \ len(right) - 1) {\n      auto a = right[i], b = right[i + 1];\n      rm_e(a,\
    \ b);\n    }\n    // \u8FBA\u8FFD\u52A0\n    if (len(left)) { add_e(left.back(),\
    \ p); }\n    if (len(right)) { add_e(p, right.back()); }\n  }\n\n  // \u4E2D\uFF1A\
    1, \u5883\u754C\uFF1A0, \u5916\uFF1A-1\n  int side(Point<T> p) {\n    auto r =\
    \ S.lower_bound(p);\n    if (r == S.begin()) {\n      // \u5168\u90E8 p \u4EE5\
    \u4E0A\n      if (len(S) && (*r) == p) return 0;\n      return -1;\n    }\n  \
    \  if (r == S.end()) {\n      // p \u306F max \u3088\u308A\u5927\u304D\u3044\n\
    \      return -1;\n    }\n    auto l = prev(r);\n    auto p1 = *l, p2 = *r;\n\
    \    T det = (p - p1).det(p2 - p1);\n    if (det == 0) return 0;\n    return (det\
    \ > 0 ? -1 : 1);\n  }\n};\n\ntemplate <typename T, bool strict = true>\nstruct\
    \ Incremental_ConvexHull {\n  using P = Point<T>;\n  IncrementalConvexHull_Lower<T,\
    \ strict> LOWER, UPPER;\n  int cnt_E;\n  T det_sum;\n  bool is_empty;\n\n  Incremental_ConvexHull()\
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
    \ b);\n  }\n};\n#line 4 \"test/1_mytest/incremental_ch.test.cpp\"\n\n// geocon2013\
    \ c sample \u3088\u308A\nvoid test() {\n  {\n    Incremental_ConvexHull<ll> X;\n\
    \    assert(X.area_2() == 0);\n    assert(X.side(Point<ll>(2, 2)) == -1);\n  \
    \  assert(X.side(Point<ll>(1, 2)) == -1);\n    assert(X.side(Point<ll>(1, 1))\
    \ == -1);\n    assert(X.side(Point<ll>(2, 1)) == -1);\n    X.add(Point<ll>(1,\
    \ 1));\n    assert(X.side(Point<ll>(2, 2)) == -1);\n    assert(X.side(Point<ll>(1,\
    \ 2)) == -1);\n    assert(X.side(Point<ll>(1, 1)) == 0);\n    assert(X.side(Point<ll>(2,\
    \ 1)) == -1);\n    X.add(Point<ll>(5, 1));\n    assert(X.area_2() == 0);\n   \
    \ assert(X.side(Point<ll>(2, 2)) == -1);\n    assert(X.side(Point<ll>(1, 2)) ==\
    \ -1);\n    assert(X.side(Point<ll>(1, 1)) == 0);\n    assert(X.side(Point<ll>(2,\
    \ 1)) == 0);\n    X.add(Point<ll>(1, 5));\n    assert(X.area_2() == 16);\n   \
    \ assert(X.side(Point<ll>(2, 2)) == 1);\n    assert(X.side(Point<ll>(1, 2)) ==\
    \ 0);\n    assert(X.side(Point<ll>(1, 1)) == 0);\n    assert(X.side(Point<ll>(2,\
    \ 1)) == 0);\n  }\n  {\n    Incremental_ConvexHull<ll> X;\n    X.add(Point<ll>(2,\
    \ 1));\n    X.add(Point<ll>(4, 1));\n    X.add(Point<ll>(6, 1));\n    assert(X.side(Point<ll>(1,\
    \ 1)) == -1);\n    assert(X.side(Point<ll>(3, 1)) == 0);\n    assert(X.side(Point<ll>(5,\
    \ 1)) == 0);\n    assert(X.side(Point<ll>(7, 1)) == -1);\n  }\n}\n\nvoid solve()\
    \ {\n  int a, b;\n  cin >> a >> b;\n  cout << a + b << \"\\n\";\n}\n\nsigned main()\
    \ {\n  test();\n  solve();\n  return 0;\n}\n"
  code: "#define PROBLEM \"https://judge.yosupo.jp/problem/aplusb\"\n#include \"my_template.hpp\"\
    \n#include \"geo/incremental_convexhull.hpp\"\n\n// geocon2013 c sample \u3088\
    \u308A\nvoid test() {\n  {\n    Incremental_ConvexHull<ll> X;\n    assert(X.area_2()\
    \ == 0);\n    assert(X.side(Point<ll>(2, 2)) == -1);\n    assert(X.side(Point<ll>(1,\
    \ 2)) == -1);\n    assert(X.side(Point<ll>(1, 1)) == -1);\n    assert(X.side(Point<ll>(2,\
    \ 1)) == -1);\n    X.add(Point<ll>(1, 1));\n    assert(X.side(Point<ll>(2, 2))\
    \ == -1);\n    assert(X.side(Point<ll>(1, 2)) == -1);\n    assert(X.side(Point<ll>(1,\
    \ 1)) == 0);\n    assert(X.side(Point<ll>(2, 1)) == -1);\n    X.add(Point<ll>(5,\
    \ 1));\n    assert(X.area_2() == 0);\n    assert(X.side(Point<ll>(2, 2)) == -1);\n\
    \    assert(X.side(Point<ll>(1, 2)) == -1);\n    assert(X.side(Point<ll>(1, 1))\
    \ == 0);\n    assert(X.side(Point<ll>(2, 1)) == 0);\n    X.add(Point<ll>(1, 5));\n\
    \    assert(X.area_2() == 16);\n    assert(X.side(Point<ll>(2, 2)) == 1);\n  \
    \  assert(X.side(Point<ll>(1, 2)) == 0);\n    assert(X.side(Point<ll>(1, 1)) ==\
    \ 0);\n    assert(X.side(Point<ll>(2, 1)) == 0);\n  }\n  {\n    Incremental_ConvexHull<ll>\
    \ X;\n    X.add(Point<ll>(2, 1));\n    X.add(Point<ll>(4, 1));\n    X.add(Point<ll>(6,\
    \ 1));\n    assert(X.side(Point<ll>(1, 1)) == -1);\n    assert(X.side(Point<ll>(3,\
    \ 1)) == 0);\n    assert(X.side(Point<ll>(5, 1)) == 0);\n    assert(X.side(Point<ll>(7,\
    \ 1)) == -1);\n  }\n}\n\nvoid solve() {\n  int a, b;\n  cin >> a >> b;\n  cout\
    \ << a + b << \"\\n\";\n}\n\nsigned main() {\n  test();\n  solve();\n  return\
    \ 0;\n}\n"
  dependsOn:
  - my_template.hpp
  - geo/incremental_convexhull.hpp
  - geo/base.hpp
  isVerificationFile: true
  path: test/1_mytest/incremental_ch.test.cpp
  requiredBy: []
  timestamp: '2025-07-03 18:22:07+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: test/1_mytest/incremental_ch.test.cpp
layout: document
redirect_from:
- /verify/test/1_mytest/incremental_ch.test.cpp
- /verify/test/1_mytest/incremental_ch.test.cpp.html
title: test/1_mytest/incremental_ch.test.cpp
---
