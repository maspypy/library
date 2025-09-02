---
data:
  _extendedDependsOn:
  - icon: ':x:'
    path: geo/base.hpp
    title: geo/base.hpp
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':warning:'
  attributes:
    links:
    - https://cp-algorithms.com/geometry/delaunay.html
  bundledCode: "#line 1 \"geo/delaunay_triangulation.hpp\"\n\n#line 2 \"geo/base.hpp\"\
    \ntemplate <typename T>\nstruct Point {\n  T x, y;\n\n  Point() : x(0), y(0) {}\n\
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
    \ dx * dx + dy * dy <= r * r;\n  }\n};\n#line 3 \"geo/delaunay_triangulation.hpp\"\
    \n\n// \u3068\u308A\u3042\u3048\u305A\u30B3\u30D4\u30DA\u3057\u305F\u3082\u306E\
    \u3092\u4F7F\u3046\n\nnamespace CP_ALGO {\n// https://cp-algorithms.com/geometry/delaunay.html\n\
    typedef long long ll;\n\nbool ge(const ll& a, const ll& b) { return a >= b; }\n\
    bool le(const ll& a, const ll& b) { return a <= b; }\nbool eq(const ll& a, const\
    \ ll& b) { return a == b; }\nbool gt(const ll& a, const ll& b) { return a > b;\
    \ }\nbool lt(const ll& a, const ll& b) { return a < b; }\nint sgn(const ll& a)\
    \ { return a >= 0 ? a ? 1 : 0 : -1; }\n\nstruct pt {\n  ll x, y;\n  pt() {}\n\
    \  pt(ll _x, ll _y) : x(_x), y(_y) {}\n  pt operator-(const pt& p) const { return\
    \ pt(x - p.x, y - p.y); }\n  ll cross(const pt& p) const { return x * p.y - y\
    \ * p.x; }\n  ll cross(const pt& a, const pt& b) const { return (a - *this).cross(b\
    \ - *this); }\n  ll dot(const pt& p) const { return x * p.x + y * p.y; }\n  ll\
    \ dot(const pt& a, const pt& b) const { return (a - *this).dot(b - *this); }\n\
    \  ll sqrLength() const { return this->dot(*this); }\n  bool operator==(const\
    \ pt& p) const { return eq(x, p.x) && eq(y, p.y); }\n};\n\nconst pt inf_pt = pt(1e18,\
    \ 1e18);\n\nstruct QuadEdge {\n  pt origin;\n  QuadEdge* rot = nullptr;\n  QuadEdge*\
    \ onext = nullptr;\n  bool used = false;\n  QuadEdge* rev() const { return rot->rot;\
    \ }\n  QuadEdge* lnext() const { return rot->rev()->onext->rot; }\n  QuadEdge*\
    \ oprev() const { return rot->onext->rot; }\n  pt dest() const { return rev()->origin;\
    \ }\n};\n\nQuadEdge* make_edge(pt from, pt to) {\n  QuadEdge* e1 = new QuadEdge;\n\
    \  QuadEdge* e2 = new QuadEdge;\n  QuadEdge* e3 = new QuadEdge;\n  QuadEdge* e4\
    \ = new QuadEdge;\n  e1->origin = from;\n  e2->origin = to;\n  e3->origin = e4->origin\
    \ = inf_pt;\n  e1->rot = e3;\n  e2->rot = e4;\n  e3->rot = e2;\n  e4->rot = e1;\n\
    \  e1->onext = e1;\n  e2->onext = e2;\n  e3->onext = e4;\n  e4->onext = e3;\n\
    \  return e1;\n}\n\nvoid splice(QuadEdge* a, QuadEdge* b) {\n  swap(a->onext->rot->onext,\
    \ b->onext->rot->onext);\n  swap(a->onext, b->onext);\n}\n\nvoid delete_edge(QuadEdge*\
    \ e) {\n  splice(e, e->oprev());\n  splice(e->rev(), e->rev()->oprev());\n  delete\
    \ e->rev()->rot;\n  delete e->rev();\n  delete e->rot;\n  delete e;\n}\n\nQuadEdge*\
    \ connect(QuadEdge* a, QuadEdge* b) {\n  QuadEdge* e = make_edge(a->dest(), b->origin);\n\
    \  splice(e, a->lnext());\n  splice(e->rev(), b);\n  return e;\n}\n\nbool left_of(pt\
    \ p, QuadEdge* e) { return gt(p.cross(e->origin, e->dest()), 0); }\n\nbool right_of(pt\
    \ p, QuadEdge* e) { return lt(p.cross(e->origin, e->dest()), 0); }\n\ntemplate\
    \ <class T>\nT det3(T a1, T a2, T a3, T b1, T b2, T b3, T c1, T c2, T c3) {\n\
    \  return a1 * (b2 * c3 - c2 * b3) - a2 * (b1 * c3 - c1 * b3) + a3 * (b1 * c2\
    \ - c1 * b2);\n}\n\nbool in_circle(pt a, pt b, pt c, pt d) {\n// If there is __int128,\
    \ calculate directly.\n// Otherwise, calculate angles.\n#if defined(__LP64__)\
    \ || defined(_WIN64)\n  __int128 det = -det3<__int128>(b.x, b.y, b.sqrLength(),\
    \ c.x, c.y, c.sqrLength(), d.x, d.y, d.sqrLength());\n  det += det3<__int128>(a.x,\
    \ a.y, a.sqrLength(), c.x, c.y, c.sqrLength(), d.x, d.y, d.sqrLength());\n  det\
    \ -= det3<__int128>(a.x, a.y, a.sqrLength(), b.x, b.y, b.sqrLength(), d.x, d.y,\
    \ d.sqrLength());\n  det += det3<__int128>(a.x, a.y, a.sqrLength(), b.x, b.y,\
    \ b.sqrLength(), c.x, c.y, c.sqrLength());\n  return det > 0;\n#else\n  auto ang\
    \ = [](pt l, pt mid, pt r) {\n    ll x = mid.dot(l, r);\n    ll y = mid.cross(l,\
    \ r);\n    long double res = atan2((long double)x, (long double)y);\n    return\
    \ res;\n  };\n  long double kek = ang(a, b, c) + ang(c, d, a) - ang(b, c, d) -\
    \ ang(d, a, b);\n  if (kek > 1e-8)\n    return true;\n  else\n    return false;\n\
    #endif\n}\n\npair<QuadEdge*, QuadEdge*> build_tr(int l, int r, vector<pt>& p)\
    \ {\n  if (r - l + 1 == 2) {\n    QuadEdge* res = make_edge(p[l], p[r]);\n   \
    \ return make_pair(res, res->rev());\n  }\n  if (r - l + 1 == 3) {\n    QuadEdge\
    \ *a = make_edge(p[l], p[l + 1]), *b = make_edge(p[l + 1], p[r]);\n    splice(a->rev(),\
    \ b);\n    int sg = sgn(p[l].cross(p[l + 1], p[r]));\n    if (sg == 0) return\
    \ make_pair(a, b->rev());\n    QuadEdge* c = connect(b, a);\n    if (sg == 1)\n\
    \      return make_pair(a, b->rev());\n    else\n      return make_pair(c->rev(),\
    \ c);\n  }\n  int mid = (l + r) / 2;\n  QuadEdge *ldo, *ldi, *rdo, *rdi;\n  tie(ldo,\
    \ ldi) = build_tr(l, mid, p);\n  tie(rdi, rdo) = build_tr(mid + 1, r, p);\n  while\
    \ (true) {\n    if (left_of(rdi->origin, ldi)) {\n      ldi = ldi->lnext();\n\
    \      continue;\n    }\n    if (right_of(ldi->origin, rdi)) {\n      rdi = rdi->rev()->onext;\n\
    \      continue;\n    }\n    break;\n  }\n  QuadEdge* basel = connect(rdi->rev(),\
    \ ldi);\n  auto valid = [&basel](QuadEdge* e) { return right_of(e->dest(), basel);\
    \ };\n  if (ldi->origin == ldo->origin) ldo = basel->rev();\n  if (rdi->origin\
    \ == rdo->origin) rdo = basel;\n  while (true) {\n    QuadEdge* lcand = basel->rev()->onext;\n\
    \    if (valid(lcand)) {\n      while (in_circle(basel->dest(), basel->origin,\
    \ lcand->dest(), lcand->onext->dest())) {\n        QuadEdge* t = lcand->onext;\n\
    \        delete_edge(lcand);\n        lcand = t;\n      }\n    }\n    QuadEdge*\
    \ rcand = basel->oprev();\n    if (valid(rcand)) {\n      while (in_circle(basel->dest(),\
    \ basel->origin, rcand->dest(), rcand->oprev()->dest())) {\n        QuadEdge*\
    \ t = rcand->oprev();\n        delete_edge(rcand);\n        rcand = t;\n     \
    \ }\n    }\n    if (!valid(lcand) && !valid(rcand)) break;\n    if (!valid(lcand)\
    \ || (valid(rcand) && in_circle(lcand->dest(), lcand->origin, rcand->origin, rcand->dest())))\n\
    \      basel = connect(rcand, basel->rev());\n    else\n      basel = connect(basel->rev(),\
    \ lcand->rev());\n  }\n  return make_pair(ldo, rdo);\n}\n\nvector<tuple<pt, pt,\
    \ pt>> delaunay(vector<pt> p) {\n  sort(p.begin(), p.end(), [](const pt& a, const\
    \ pt& b) { return lt(a.x, b.x) || (eq(a.x, b.x) && lt(a.y, b.y)); });\n  auto\
    \ res = build_tr(0, (int)p.size() - 1, p);\n  QuadEdge* e = res.first;\n  vector<QuadEdge*>\
    \ edges = {e};\n  while (lt(e->onext->dest().cross(e->dest(), e->origin), 0))\
    \ e = e->onext;\n  auto add = [&p, &e, &edges]() {\n    QuadEdge* curr = e;\n\
    \    do {\n      curr->used = true;\n      p.push_back(curr->origin);\n      edges.push_back(curr->rev());\n\
    \      curr = curr->lnext();\n    } while (curr != e);\n  };\n  add();\n  p.clear();\n\
    \  int kek = 0;\n  while (kek < (int)edges.size()) {\n    if (!(e = edges[kek++])->used)\
    \ add();\n  }\n  vector<tuple<pt, pt, pt>> ans;\n  for (int i = 0; i < (int)p.size();\
    \ i += 3) { ans.push_back(make_tuple(p[i], p[i + 1], p[i + 2])); }\n  return ans;\n\
    }\n} // namespace CP_ALGO\n\ntemplate <typename T>\nvc<tuple<int, int, int>> delaunay(vc<Point<T>>\
    \ point) {\n  using P = Point<T>;\n  map<P, int> MP;\n  vc<CP_ALGO::pt> tmp;\n\
    \  int n = len(point);\n  FOR(i, n) {\n    P p = point[i];\n    MP[p] = i;\n \
    \   tmp.eb(CP_ALGO::pt(p.x, p.y));\n  }\n  auto tri = CP_ALGO::delaunay(tmp);\n\
    \  vc<tuple<int, int, int>> ANS;\n  for (auto [a, b, c]: tri) {\n    int i = MP[P(a.x,\
    \ a.y)];\n    int j = MP[P(b.x, b.y)];\n    int k = MP[P(c.x, c.y)];\n    ANS.eb(i,\
    \ j, k);\n  }\n  return ANS;\n}\n"
  code: "\n#include \"geo/base.hpp\"\n\n// \u3068\u308A\u3042\u3048\u305A\u30B3\u30D4\
    \u30DA\u3057\u305F\u3082\u306E\u3092\u4F7F\u3046\n\nnamespace CP_ALGO {\n// https://cp-algorithms.com/geometry/delaunay.html\n\
    typedef long long ll;\n\nbool ge(const ll& a, const ll& b) { return a >= b; }\n\
    bool le(const ll& a, const ll& b) { return a <= b; }\nbool eq(const ll& a, const\
    \ ll& b) { return a == b; }\nbool gt(const ll& a, const ll& b) { return a > b;\
    \ }\nbool lt(const ll& a, const ll& b) { return a < b; }\nint sgn(const ll& a)\
    \ { return a >= 0 ? a ? 1 : 0 : -1; }\n\nstruct pt {\n  ll x, y;\n  pt() {}\n\
    \  pt(ll _x, ll _y) : x(_x), y(_y) {}\n  pt operator-(const pt& p) const { return\
    \ pt(x - p.x, y - p.y); }\n  ll cross(const pt& p) const { return x * p.y - y\
    \ * p.x; }\n  ll cross(const pt& a, const pt& b) const { return (a - *this).cross(b\
    \ - *this); }\n  ll dot(const pt& p) const { return x * p.x + y * p.y; }\n  ll\
    \ dot(const pt& a, const pt& b) const { return (a - *this).dot(b - *this); }\n\
    \  ll sqrLength() const { return this->dot(*this); }\n  bool operator==(const\
    \ pt& p) const { return eq(x, p.x) && eq(y, p.y); }\n};\n\nconst pt inf_pt = pt(1e18,\
    \ 1e18);\n\nstruct QuadEdge {\n  pt origin;\n  QuadEdge* rot = nullptr;\n  QuadEdge*\
    \ onext = nullptr;\n  bool used = false;\n  QuadEdge* rev() const { return rot->rot;\
    \ }\n  QuadEdge* lnext() const { return rot->rev()->onext->rot; }\n  QuadEdge*\
    \ oprev() const { return rot->onext->rot; }\n  pt dest() const { return rev()->origin;\
    \ }\n};\n\nQuadEdge* make_edge(pt from, pt to) {\n  QuadEdge* e1 = new QuadEdge;\n\
    \  QuadEdge* e2 = new QuadEdge;\n  QuadEdge* e3 = new QuadEdge;\n  QuadEdge* e4\
    \ = new QuadEdge;\n  e1->origin = from;\n  e2->origin = to;\n  e3->origin = e4->origin\
    \ = inf_pt;\n  e1->rot = e3;\n  e2->rot = e4;\n  e3->rot = e2;\n  e4->rot = e1;\n\
    \  e1->onext = e1;\n  e2->onext = e2;\n  e3->onext = e4;\n  e4->onext = e3;\n\
    \  return e1;\n}\n\nvoid splice(QuadEdge* a, QuadEdge* b) {\n  swap(a->onext->rot->onext,\
    \ b->onext->rot->onext);\n  swap(a->onext, b->onext);\n}\n\nvoid delete_edge(QuadEdge*\
    \ e) {\n  splice(e, e->oprev());\n  splice(e->rev(), e->rev()->oprev());\n  delete\
    \ e->rev()->rot;\n  delete e->rev();\n  delete e->rot;\n  delete e;\n}\n\nQuadEdge*\
    \ connect(QuadEdge* a, QuadEdge* b) {\n  QuadEdge* e = make_edge(a->dest(), b->origin);\n\
    \  splice(e, a->lnext());\n  splice(e->rev(), b);\n  return e;\n}\n\nbool left_of(pt\
    \ p, QuadEdge* e) { return gt(p.cross(e->origin, e->dest()), 0); }\n\nbool right_of(pt\
    \ p, QuadEdge* e) { return lt(p.cross(e->origin, e->dest()), 0); }\n\ntemplate\
    \ <class T>\nT det3(T a1, T a2, T a3, T b1, T b2, T b3, T c1, T c2, T c3) {\n\
    \  return a1 * (b2 * c3 - c2 * b3) - a2 * (b1 * c3 - c1 * b3) + a3 * (b1 * c2\
    \ - c1 * b2);\n}\n\nbool in_circle(pt a, pt b, pt c, pt d) {\n// If there is __int128,\
    \ calculate directly.\n// Otherwise, calculate angles.\n#if defined(__LP64__)\
    \ || defined(_WIN64)\n  __int128 det = -det3<__int128>(b.x, b.y, b.sqrLength(),\
    \ c.x, c.y, c.sqrLength(), d.x, d.y, d.sqrLength());\n  det += det3<__int128>(a.x,\
    \ a.y, a.sqrLength(), c.x, c.y, c.sqrLength(), d.x, d.y, d.sqrLength());\n  det\
    \ -= det3<__int128>(a.x, a.y, a.sqrLength(), b.x, b.y, b.sqrLength(), d.x, d.y,\
    \ d.sqrLength());\n  det += det3<__int128>(a.x, a.y, a.sqrLength(), b.x, b.y,\
    \ b.sqrLength(), c.x, c.y, c.sqrLength());\n  return det > 0;\n#else\n  auto ang\
    \ = [](pt l, pt mid, pt r) {\n    ll x = mid.dot(l, r);\n    ll y = mid.cross(l,\
    \ r);\n    long double res = atan2((long double)x, (long double)y);\n    return\
    \ res;\n  };\n  long double kek = ang(a, b, c) + ang(c, d, a) - ang(b, c, d) -\
    \ ang(d, a, b);\n  if (kek > 1e-8)\n    return true;\n  else\n    return false;\n\
    #endif\n}\n\npair<QuadEdge*, QuadEdge*> build_tr(int l, int r, vector<pt>& p)\
    \ {\n  if (r - l + 1 == 2) {\n    QuadEdge* res = make_edge(p[l], p[r]);\n   \
    \ return make_pair(res, res->rev());\n  }\n  if (r - l + 1 == 3) {\n    QuadEdge\
    \ *a = make_edge(p[l], p[l + 1]), *b = make_edge(p[l + 1], p[r]);\n    splice(a->rev(),\
    \ b);\n    int sg = sgn(p[l].cross(p[l + 1], p[r]));\n    if (sg == 0) return\
    \ make_pair(a, b->rev());\n    QuadEdge* c = connect(b, a);\n    if (sg == 1)\n\
    \      return make_pair(a, b->rev());\n    else\n      return make_pair(c->rev(),\
    \ c);\n  }\n  int mid = (l + r) / 2;\n  QuadEdge *ldo, *ldi, *rdo, *rdi;\n  tie(ldo,\
    \ ldi) = build_tr(l, mid, p);\n  tie(rdi, rdo) = build_tr(mid + 1, r, p);\n  while\
    \ (true) {\n    if (left_of(rdi->origin, ldi)) {\n      ldi = ldi->lnext();\n\
    \      continue;\n    }\n    if (right_of(ldi->origin, rdi)) {\n      rdi = rdi->rev()->onext;\n\
    \      continue;\n    }\n    break;\n  }\n  QuadEdge* basel = connect(rdi->rev(),\
    \ ldi);\n  auto valid = [&basel](QuadEdge* e) { return right_of(e->dest(), basel);\
    \ };\n  if (ldi->origin == ldo->origin) ldo = basel->rev();\n  if (rdi->origin\
    \ == rdo->origin) rdo = basel;\n  while (true) {\n    QuadEdge* lcand = basel->rev()->onext;\n\
    \    if (valid(lcand)) {\n      while (in_circle(basel->dest(), basel->origin,\
    \ lcand->dest(), lcand->onext->dest())) {\n        QuadEdge* t = lcand->onext;\n\
    \        delete_edge(lcand);\n        lcand = t;\n      }\n    }\n    QuadEdge*\
    \ rcand = basel->oprev();\n    if (valid(rcand)) {\n      while (in_circle(basel->dest(),\
    \ basel->origin, rcand->dest(), rcand->oprev()->dest())) {\n        QuadEdge*\
    \ t = rcand->oprev();\n        delete_edge(rcand);\n        rcand = t;\n     \
    \ }\n    }\n    if (!valid(lcand) && !valid(rcand)) break;\n    if (!valid(lcand)\
    \ || (valid(rcand) && in_circle(lcand->dest(), lcand->origin, rcand->origin, rcand->dest())))\n\
    \      basel = connect(rcand, basel->rev());\n    else\n      basel = connect(basel->rev(),\
    \ lcand->rev());\n  }\n  return make_pair(ldo, rdo);\n}\n\nvector<tuple<pt, pt,\
    \ pt>> delaunay(vector<pt> p) {\n  sort(p.begin(), p.end(), [](const pt& a, const\
    \ pt& b) { return lt(a.x, b.x) || (eq(a.x, b.x) && lt(a.y, b.y)); });\n  auto\
    \ res = build_tr(0, (int)p.size() - 1, p);\n  QuadEdge* e = res.first;\n  vector<QuadEdge*>\
    \ edges = {e};\n  while (lt(e->onext->dest().cross(e->dest(), e->origin), 0))\
    \ e = e->onext;\n  auto add = [&p, &e, &edges]() {\n    QuadEdge* curr = e;\n\
    \    do {\n      curr->used = true;\n      p.push_back(curr->origin);\n      edges.push_back(curr->rev());\n\
    \      curr = curr->lnext();\n    } while (curr != e);\n  };\n  add();\n  p.clear();\n\
    \  int kek = 0;\n  while (kek < (int)edges.size()) {\n    if (!(e = edges[kek++])->used)\
    \ add();\n  }\n  vector<tuple<pt, pt, pt>> ans;\n  for (int i = 0; i < (int)p.size();\
    \ i += 3) { ans.push_back(make_tuple(p[i], p[i + 1], p[i + 2])); }\n  return ans;\n\
    }\n} // namespace CP_ALGO\n\ntemplate <typename T>\nvc<tuple<int, int, int>> delaunay(vc<Point<T>>\
    \ point) {\n  using P = Point<T>;\n  map<P, int> MP;\n  vc<CP_ALGO::pt> tmp;\n\
    \  int n = len(point);\n  FOR(i, n) {\n    P p = point[i];\n    MP[p] = i;\n \
    \   tmp.eb(CP_ALGO::pt(p.x, p.y));\n  }\n  auto tri = CP_ALGO::delaunay(tmp);\n\
    \  vc<tuple<int, int, int>> ANS;\n  for (auto [a, b, c]: tri) {\n    int i = MP[P(a.x,\
    \ a.y)];\n    int j = MP[P(b.x, b.y)];\n    int k = MP[P(c.x, c.y)];\n    ANS.eb(i,\
    \ j, k);\n  }\n  return ANS;\n}"
  dependsOn:
  - geo/base.hpp
  isVerificationFile: false
  path: geo/delaunay_triangulation.hpp
  requiredBy: []
  timestamp: '2025-06-20 14:02:37+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: geo/delaunay_triangulation.hpp
layout: document
redirect_from:
- /library/geo/delaunay_triangulation.hpp
- /library/geo/delaunay_triangulation.hpp.html
title: geo/delaunay_triangulation.hpp
---
