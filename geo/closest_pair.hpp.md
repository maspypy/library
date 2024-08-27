---
data:
  _extendedDependsOn:
  - icon: ':question:'
    path: ds/hashmap.hpp
    title: ds/hashmap.hpp
  - icon: ':heavy_check_mark:'
    path: geo/base.hpp
    title: geo/base.hpp
  - icon: ':question:'
    path: random/base.hpp
    title: random/base.hpp
  - icon: ':heavy_check_mark:'
    path: random/hash_pair.hpp
    title: random/hash_pair.hpp
  - icon: ':question:'
    path: random/shuffle.hpp
    title: random/shuffle.hpp
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/2_library_checker/geometry/closest_pair.test.cpp
    title: test/2_library_checker/geometry/closest_pair.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/2_library_checker/geometry/closest_pair_dc.test.cpp
    title: test/2_library_checker/geometry/closest_pair_dc.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/4_aoj/CGL_5_A.test.cpp
    title: test/4_aoj/CGL_5_A.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 2 \"geo/base.hpp\"\ntemplate <typename T>\nstruct Point {\n\
    \  T x, y;\n\n  Point() : x(0), y(0) {}\n\n  template <typename A, typename B>\n\
    \  Point(A x, B y) : x(x), y(y) {}\n\n  template <typename A, typename B>\n  Point(pair<A,\
    \ B> p) : x(p.fi), y(p.se) {}\n\n  Point operator+=(const Point p) {\n    x +=\
    \ p.x, y += p.y;\n    return *this;\n  }\n  Point operator-=(const Point p) {\n\
    \    x -= p.x, y -= p.y;\n    return *this;\n  }\n  Point operator+(Point p) const\
    \ { return {x + p.x, y + p.y}; }\n  Point operator-(Point p) const { return {x\
    \ - p.x, y - p.y}; }\n  bool operator==(Point p) const { return x == p.x && y\
    \ == p.y; }\n  bool operator!=(Point p) const { return x != p.x || y != p.y; }\n\
    \  Point operator-() const { return {-x, -y}; }\n  Point operator*(T t) const\
    \ { return {x * t, y * t}; }\n  Point operator/(T t) const { return {x / t, y\
    \ / t}; }\n\n  bool operator<(Point p) const {\n    if (x != p.x) return x < p.x;\n\
    \    return y < p.y;\n  }\n  T dot(Point other) { return x * other.x + y * other.y;\
    \ }\n  T det(Point other) { return x * other.y - y * other.x; }\n\n  double norm()\
    \ { return sqrtl(x * x + y * y); }\n  double angle() { return atan2(y, x); }\n\
    \n  Point rotate(double theta) {\n    static_assert(!is_integral<T>::value);\n\
    \    double c = cos(theta), s = sin(theta);\n    return Point{c * x - s * y, s\
    \ * x + c * y};\n  }\n};\n\n#ifdef FASTIO\ntemplate <typename T>\nvoid rd(Point<T>\
    \ &p) {\n  fastio::rd(p.x), fastio::rd(p.y);\n}\ntemplate <typename T>\nvoid wt(Point<T>\
    \ &p) {\n  fastio::wt(p.x);\n  fastio::wt(' ');\n  fastio::wt(p.y);\n}\n#endif\n\
    \n// A -> B -> C \u3068\u9032\u3080\u3068\u304D\u306B\u3001\u5DE6\u306B\u66F2\u304C\
    \u308B\u306A\u3089\u3070 +1\u3001\u53F3\u306B\u66F2\u304C\u308B\u306A\u3089\u3070\
    \ -1\ntemplate <typename T>\nint ccw(Point<T> A, Point<T> B, Point<T> C) {\n \
    \ T x = (B - A).det(C - A);\n  if (x > 0) return 1;\n  if (x < 0) return -1;\n\
    \  return 0;\n}\n\ntemplate <typename REAL, typename T, typename U>\nREAL dist(Point<T>\
    \ A, Point<U> B) {\n  REAL dx = REAL(A.x) - REAL(B.x);\n  REAL dy = REAL(A.y)\
    \ - REAL(B.y);\n  return sqrt(dx * dx + dy * dy);\n}\n\n// ax+by+c\ntemplate <typename\
    \ T>\nstruct Line {\n  T a, b, c;\n\n  Line(T a, T b, T c) : a(a), b(b), c(c)\
    \ {}\n  Line(Point<T> A, Point<T> B) {\n    a = A.y - B.y, b = B.x - A.x, c =\
    \ A.x * B.y - A.y * B.x;\n  }\n  Line(T x1, T y1, T x2, T y2) : Line(Point<T>(x1,\
    \ y1), Point<T>(x2, y2)) {}\n\n  template <typename U>\n  U eval(Point<U> P) {\n\
    \    return a * P.x + b * P.y + c;\n  }\n\n  template <typename U>\n  T eval(U\
    \ x, U y) {\n    return a * x + b * y + c;\n  }\n\n  // \u540C\u3058\u76F4\u7DDA\
    \u304C\u540C\u3058 a,b,c \u3067\u8868\u73FE\u3055\u308C\u308B\u3088\u3046\u306B\
    \u3059\u308B\n  void normalize() {\n    static_assert(is_same_v<T, int> || is_same_v<T,\
    \ long long>);\n    T g = gcd(gcd(abs(a), abs(b)), abs(c));\n    a /= g, b /=\
    \ g, c /= g;\n    if (b < 0) { a = -a, b = -b, c = -c; }\n    if (b == 0 && a\
    \ < 0) { a = -a, b = -b, c = -c; }\n  }\n\n  bool is_parallel(Line other) { return\
    \ a * other.b - b * other.a == 0; }\n  bool is_orthogonal(Line other) { return\
    \ a * other.a + b * other.b == 0; }\n};\n\ntemplate <typename T>\nstruct Segment\
    \ {\n  Point<T> A, B;\n\n  Segment(Point<T> A, Point<T> B) : A(A), B(B) {}\n \
    \ Segment(T x1, T y1, T x2, T y2)\n      : Segment(Point<T>(x1, y1), Point<T>(x2,\
    \ y2)) {}\n\n  bool contain(Point<T> C) {\n    static_assert(is_integral<T>::value);\n\
    \    T det = (C - A).det(B - A);\n    if (det != 0) return 0;\n    return (C -\
    \ A).dot(B - A) >= 0 && (C - B).dot(A - B) >= 0;\n  }\n\n  Line<T> to_Line() {\
    \ return Line(A, B); }\n};\n\ntemplate <typename REAL>\nstruct Circle {\n  Point<REAL>\
    \ O;\n  REAL r;\n  Circle(Point<REAL> O, REAL r) : O(O), r(r) {}\n  Circle(REAL\
    \ x, REAL y, REAL r) : O(x, y), r(r) {}\n  template <typename T>\n  bool contain(Point<T>\
    \ p) {\n    REAL dx = p.x - O.x, dy = p.y - O.y;\n    return dx * dx + dy * dy\
    \ <= r * r;\n  }\n};\n\ntemplate <typename T>\nstruct Polygon {\n  vc<Point<T>>\
    \ points;\n  T a;\n\n  template <typename A, typename B>\n  Polygon(vc<pair<A,\
    \ B>> pairs) {\n    for (auto &&[a, b]: pairs) points.eb(Point<T>(a, b));\n  \
    \  build();\n  }\n  Polygon(vc<Point<T>> points) : points(points) { build(); }\n\
    \n  int size() { return len(points); }\n\n  template <typename REAL>\n  REAL area()\
    \ {\n    return a * 0.5;\n  }\n\n  template <enable_if_t<is_integral<T>::value,\
    \ int> = 0>\n  T area_2() {\n    return a;\n  }\n\n  bool is_convex() {\n    FOR(j,\
    \ len(points)) {\n      int i = (j == 0 ? len(points) - 1 : j - 1);\n      int\
    \ k = (j == len(points) - 1 ? 0 : j + 1);\n      if ((points[j] - points[i]).det(points[k]\
    \ - points[j]) < 0) return false;\n    }\n    return true;\n  }\n\nprivate:\n\
    \  void build() {\n    a = 0;\n    FOR(i, len(points)) {\n      int j = (i + 1\
    \ == len(points) ? 0 : i + 1);\n      a += points[i].det(points[j]);\n    }\n\
    \    if (a < 0) {\n      a = -a;\n      reverse(all(points));\n    }\n  }\n};\n\
    #line 2 \"random/base.hpp\"\n\nu64 RNG_64() {\n  static uint64_t x_\n      = uint64_t(chrono::duration_cast<chrono::nanoseconds>(\n\
    \                     chrono::high_resolution_clock::now().time_since_epoch())\n\
    \                     .count())\n        * 10150724397891781847ULL;\n  x_ ^= x_\
    \ << 7;\n  return x_ ^= x_ >> 9;\n}\n\nu64 RNG(u64 lim) { return RNG_64() % lim;\
    \ }\n\nll RNG(ll l, ll r) { return l + RNG_64() % (r - l); }\n#line 2 \"random/shuffle.hpp\"\
    \n\ntemplate <typename T>\nvoid shuffle(vc<T>& A) {\n  FOR(i, len(A)) {\n    int\
    \ j = RNG(0, i + 1);\n    if (i != j) swap(A[i], A[j]);\n  }\n}\n#line 2 \"ds/hashmap.hpp\"\
    \n\r\n// u64 -> Val\r\ntemplate <typename Val>\r\nstruct HashMap {\r\n  // n \u306F\
    \u5165\u308C\u305F\u3044\u3082\u306E\u306E\u500B\u6570\u3067 ok\r\n  HashMap(u32\
    \ n = 0) { build(n); }\r\n  void build(u32 n) {\r\n    u32 k = 8;\r\n    while\
    \ (k < n * 2) k *= 2;\r\n    cap = k / 2, mask = k - 1;\r\n    key.resize(k),\
    \ val.resize(k), used.assign(k, 0);\r\n  }\r\n\r\n  // size \u3092\u4FDD\u3063\
    \u305F\u307E\u307E. size=0 \u306B\u3059\u308B\u3068\u304D\u306F build \u3059\u308B\
    \u3053\u3068.\r\n  void clear() {\r\n    used.assign(len(used), 0);\r\n    cap\
    \ = (mask + 1) / 2;\r\n  }\r\n  int size() { return len(used) / 2 - cap; }\r\n\
    \r\n  int index(const u64& k) {\r\n    int i = 0;\r\n    for (i = hash(k); used[i]\
    \ && key[i] != k; i = (i + 1) & mask) {}\r\n    return i;\r\n  }\r\n\r\n  Val&\
    \ operator[](const u64& k) {\r\n    if (cap == 0) extend();\r\n    int i = index(k);\r\
    \n    if (!used[i]) { used[i] = 1, key[i] = k, val[i] = Val{}, --cap; }\r\n  \
    \  return val[i];\r\n  }\r\n\r\n  Val get(const u64& k, Val default_value) {\r\
    \n    int i = index(k);\r\n    return (used[i] ? val[i] : default_value);\r\n\
    \  }\r\n\r\n  bool count(const u64& k) {\r\n    int i = index(k);\r\n    return\
    \ used[i] && key[i] == k;\r\n  }\r\n\r\n  // f(key, val)\r\n  template <typename\
    \ F>\r\n  void enumerate_all(F f) {\r\n    FOR(i, len(used)) if (used[i]) f(key[i],\
    \ val[i]);\r\n  }\r\n\r\nprivate:\r\n  u32 cap, mask;\r\n  vc<u64> key;\r\n  vc<Val>\
    \ val;\r\n  vc<bool> used;\r\n\r\n  u64 hash(u64 x) {\r\n    static const u64\
    \ FIXED_RANDOM = std::chrono::steady_clock::now().time_since_epoch().count();\r\
    \n    x += FIXED_RANDOM;\r\n    x = (x ^ (x >> 30)) * 0xbf58476d1ce4e5b9;\r\n\
    \    x = (x ^ (x >> 27)) * 0x94d049bb133111eb;\r\n    return (x ^ (x >> 31)) &\
    \ mask;\r\n  }\r\n\r\n  void extend() {\r\n    vc<pair<u64, Val>> dat;\r\n   \
    \ dat.reserve(len(used) / 2 - cap);\r\n    FOR(i, len(used)) {\r\n      if (used[i])\
    \ dat.eb(key[i], val[i]);\r\n    }\r\n    build(2 * len(dat));\r\n    for (auto&\
    \ [a, b]: dat) (*this)[a] = b;\r\n  }\r\n};\n#line 2 \"random/hash_pair.hpp\"\n\
    \ntemplate <typename T>\nu64 hash_pair(pair<T, T> X) {\n  static ll hash_base\
    \ = 0;\n  if (hash_base == 0) hash_base = RNG_64();\n  return hash_base * X.fi\
    \ + X.se;\n}\n#line 6 \"geo/closest_pair.hpp\"\n\ntemplate <typename T>\npair<int,\
    \ int> closest_pair(vc<Point<T>> points) {\n  int N = len(points);\n  assert(N\
    \ >= 2);\n  HashMap<int> MP(N);\n  vc<int> I(N);\n  iota(all(I), 0);\n  shuffle(I);\n\
    \  points = rearrange(points, I);\n\n  auto calc = [&](int i, int j) -> T {\n\
    \    return (points[j] - points[i]).dot(points[j] - points[i]);\n  };\n\n  T best\
    \ = calc(0, 1);\n  pair<int, int> res = {0, 1};\n  T w = sqrtl(best);\n\n  vc<int>\
    \ nxt(N, -1);\n\n  auto insert = [&](int i) -> void {\n    u64 k = hash_pair<ll>({points[i].x\
    \ / w, points[i].y / w});\n    nxt[i] = MP.get(k, -1);\n    MP[k] = i;\n  };\n\
    \n  auto query = [&](int i) -> bool {\n    ll a = points[i].x / w;\n    ll b =\
    \ points[i].y / w;\n    bool upd = 0;\n    FOR(dx, -1, 2) FOR(dy, -1, 2) {\n \
    \     u64 k = hash_pair<ll>({a + dx, b + dy});\n      int j = MP.get(k, -1);\n\
    \      while (j != -1) {\n        if (chmin(best, calc(i, j))) { upd = 1, res\
    \ = {i, j}, w = sqrtl(best); }\n        j = nxt[j];\n      }\n    }\n    return\
    \ upd;\n  };\n\n  if (best == T(0)) {\n    res.fi = I[res.fi], res.se = I[res.se];\n\
    \    return res;\n  }\n\n  insert(0), insert(1);\n  FOR(i, 2, N) {\n    if (query(i))\
    \ {\n      if (best == T(0)) break;\n      MP.build(N);\n      FOR(j, i) insert(j);\n\
    \    }\n    insert(i);\n  }\n  res.fi = I[res.fi], res.se = I[res.se];\n  return\
    \ res;\n}\n\npair<int, int> closest_pair_dc(vc<Point<ll>> point) {\n  int N =\
    \ len(point);\n  assert(N >= 2);\n\n  auto I = argsort(point);\n  point = rearrange(point,\
    \ I);\n\n  ll best = -1;\n  pair<int, int> best_pair = {-1, -1};\n\n  auto upd\
    \ = [&](int i, int j) -> void {\n    Point<ll> p = point[i] - point[j];\n    ll\
    \ d = p.dot(p);\n    if (best == -1 || best > d) { best = d, best_pair = {I[i],\
    \ I[j]}; }\n  };\n  upd(0, 1);\n\n  auto dfs = [&](auto &dfs, int L, int R) ->\
    \ vc<int> {\n    // return: [L,R) \u3092 y \u306B\u3064\u3044\u3066 sort \u3057\
    \u305F\u3082\u306E\n    if (R == L + 1) return {L};\n    int M = (L + R) / 2;\n\
    \    vc<int> I0 = dfs(dfs, L, M);\n    vc<int> I1 = dfs(dfs, M, R);\n    vc<int>\
    \ I;\n    vc<int> near;\n    int a = 0, b = 0;\n    FOR(R - L) {\n      int idx\
    \ = [&]() -> int {\n        if (a == len(I0)) return I1[b++];\n        if (b ==\
    \ len(I1)) return I0[a++];\n        int i = I0[a], j = I1[b];\n        if (point[i].y\
    \ < point[j].y) {\n          ++a;\n          return i;\n        }\n        ++b;\n\
    \        return j;\n      }();\n      I.eb(idx);\n      ll dx = point[M].x - point[idx].x;\n\
    \      if (dx * dx > best) { continue; }\n      FOR_R(k, len(near)) {\n      \
    \  int j = near[k];\n        ll dy = point[idx].y - point[j].y;\n        if (best\
    \ == 0 || dy * dy > best) break;\n        upd(idx, j);\n      }\n      near.eb(idx);\n\
    \    }\n    return I;\n  };\n  dfs(dfs, 0, N);\n  return best_pair;\n}\n"
  code: "#include \"geo/base.hpp\"\n#include \"random/base.hpp\"\n#include \"random/shuffle.hpp\"\
    \n#include \"ds/hashmap.hpp\"\n#include \"random/hash_pair.hpp\"\n\ntemplate <typename\
    \ T>\npair<int, int> closest_pair(vc<Point<T>> points) {\n  int N = len(points);\n\
    \  assert(N >= 2);\n  HashMap<int> MP(N);\n  vc<int> I(N);\n  iota(all(I), 0);\n\
    \  shuffle(I);\n  points = rearrange(points, I);\n\n  auto calc = [&](int i, int\
    \ j) -> T {\n    return (points[j] - points[i]).dot(points[j] - points[i]);\n\
    \  };\n\n  T best = calc(0, 1);\n  pair<int, int> res = {0, 1};\n  T w = sqrtl(best);\n\
    \n  vc<int> nxt(N, -1);\n\n  auto insert = [&](int i) -> void {\n    u64 k = hash_pair<ll>({points[i].x\
    \ / w, points[i].y / w});\n    nxt[i] = MP.get(k, -1);\n    MP[k] = i;\n  };\n\
    \n  auto query = [&](int i) -> bool {\n    ll a = points[i].x / w;\n    ll b =\
    \ points[i].y / w;\n    bool upd = 0;\n    FOR(dx, -1, 2) FOR(dy, -1, 2) {\n \
    \     u64 k = hash_pair<ll>({a + dx, b + dy});\n      int j = MP.get(k, -1);\n\
    \      while (j != -1) {\n        if (chmin(best, calc(i, j))) { upd = 1, res\
    \ = {i, j}, w = sqrtl(best); }\n        j = nxt[j];\n      }\n    }\n    return\
    \ upd;\n  };\n\n  if (best == T(0)) {\n    res.fi = I[res.fi], res.se = I[res.se];\n\
    \    return res;\n  }\n\n  insert(0), insert(1);\n  FOR(i, 2, N) {\n    if (query(i))\
    \ {\n      if (best == T(0)) break;\n      MP.build(N);\n      FOR(j, i) insert(j);\n\
    \    }\n    insert(i);\n  }\n  res.fi = I[res.fi], res.se = I[res.se];\n  return\
    \ res;\n}\n\npair<int, int> closest_pair_dc(vc<Point<ll>> point) {\n  int N =\
    \ len(point);\n  assert(N >= 2);\n\n  auto I = argsort(point);\n  point = rearrange(point,\
    \ I);\n\n  ll best = -1;\n  pair<int, int> best_pair = {-1, -1};\n\n  auto upd\
    \ = [&](int i, int j) -> void {\n    Point<ll> p = point[i] - point[j];\n    ll\
    \ d = p.dot(p);\n    if (best == -1 || best > d) { best = d, best_pair = {I[i],\
    \ I[j]}; }\n  };\n  upd(0, 1);\n\n  auto dfs = [&](auto &dfs, int L, int R) ->\
    \ vc<int> {\n    // return: [L,R) \u3092 y \u306B\u3064\u3044\u3066 sort \u3057\
    \u305F\u3082\u306E\n    if (R == L + 1) return {L};\n    int M = (L + R) / 2;\n\
    \    vc<int> I0 = dfs(dfs, L, M);\n    vc<int> I1 = dfs(dfs, M, R);\n    vc<int>\
    \ I;\n    vc<int> near;\n    int a = 0, b = 0;\n    FOR(R - L) {\n      int idx\
    \ = [&]() -> int {\n        if (a == len(I0)) return I1[b++];\n        if (b ==\
    \ len(I1)) return I0[a++];\n        int i = I0[a], j = I1[b];\n        if (point[i].y\
    \ < point[j].y) {\n          ++a;\n          return i;\n        }\n        ++b;\n\
    \        return j;\n      }();\n      I.eb(idx);\n      ll dx = point[M].x - point[idx].x;\n\
    \      if (dx * dx > best) { continue; }\n      FOR_R(k, len(near)) {\n      \
    \  int j = near[k];\n        ll dy = point[idx].y - point[j].y;\n        if (best\
    \ == 0 || dy * dy > best) break;\n        upd(idx, j);\n      }\n      near.eb(idx);\n\
    \    }\n    return I;\n  };\n  dfs(dfs, 0, N);\n  return best_pair;\n}\n"
  dependsOn:
  - geo/base.hpp
  - random/base.hpp
  - random/shuffle.hpp
  - ds/hashmap.hpp
  - random/hash_pair.hpp
  isVerificationFile: false
  path: geo/closest_pair.hpp
  requiredBy: []
  timestamp: '2024-08-26 01:20:39+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/2_library_checker/geometry/closest_pair_dc.test.cpp
  - test/2_library_checker/geometry/closest_pair.test.cpp
  - test/4_aoj/CGL_5_A.test.cpp
documentation_of: geo/closest_pair.hpp
layout: document
redirect_from:
- /library/geo/closest_pair.hpp
- /library/geo/closest_pair.hpp.html
title: geo/closest_pair.hpp
---
