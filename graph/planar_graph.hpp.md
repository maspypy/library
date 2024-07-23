---
data:
  _extendedDependsOn:
  - icon: ':x:'
    path: geo/angle_sort.hpp
    title: geo/angle_sort.hpp
  - icon: ':question:'
    path: geo/base.hpp
    title: geo/base.hpp
  - icon: ':question:'
    path: graph/base.hpp
    title: graph/base.hpp
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':x:'
    path: test/yukicoder/1777.test.cpp
    title: test/yukicoder/1777.test.cpp
  _isVerificationFailed: true
  _pathExtension: hpp
  _verificationStatusIcon: ':x:'
  attributes:
    links: []
  bundledCode: "#line 2 \"graph/base.hpp\"\n\ntemplate <typename T>\nstruct Edge {\n\
    \  int frm, to;\n  T cost;\n  int id;\n};\n\ntemplate <typename T = int, bool\
    \ directed = false>\nstruct Graph {\n  static constexpr bool is_directed = directed;\n\
    \  int N, M;\n  using cost_type = T;\n  using edge_type = Edge<T>;\n  vector<edge_type>\
    \ edges;\n  vector<int> indptr;\n  vector<edge_type> csr_edges;\n  vc<int> vc_deg,\
    \ vc_indeg, vc_outdeg;\n  bool prepared;\n\n  class OutgoingEdges {\n  public:\n\
    \    OutgoingEdges(const Graph* G, int l, int r) : G(G), l(l), r(r) {}\n\n   \
    \ const edge_type* begin() const {\n      if (l == r) { return 0; }\n      return\
    \ &G->csr_edges[l];\n    }\n\n    const edge_type* end() const {\n      if (l\
    \ == r) { return 0; }\n      return &G->csr_edges[r];\n    }\n\n  private:\n \
    \   const Graph* G;\n    int l, r;\n  };\n\n  bool is_prepared() { return prepared;\
    \ }\n\n  Graph() : N(0), M(0), prepared(0) {}\n  Graph(int N) : N(N), M(0), prepared(0)\
    \ {}\n\n  void build(int n) {\n    N = n, M = 0;\n    prepared = 0;\n    edges.clear();\n\
    \    indptr.clear();\n    csr_edges.clear();\n    vc_deg.clear();\n    vc_indeg.clear();\n\
    \    vc_outdeg.clear();\n  }\n\n  void add(int frm, int to, T cost = 1, int i\
    \ = -1) {\n    assert(!prepared);\n    assert(0 <= frm && 0 <= to && to < N);\n\
    \    if (i == -1) i = M;\n    auto e = edge_type({frm, to, cost, i});\n    edges.eb(e);\n\
    \    ++M;\n  }\n\n#ifdef FASTIO\n  // wt, off\n  void read_tree(bool wt = false,\
    \ int off = 1) { read_graph(N - 1, wt, off); }\n\n  void read_graph(int M, bool\
    \ wt = false, int off = 1) {\n    for (int m = 0; m < M; ++m) {\n      INT(a,\
    \ b);\n      a -= off, b -= off;\n      if (!wt) {\n        add(a, b);\n     \
    \ } else {\n        T c;\n        read(c);\n        add(a, b, c);\n      }\n \
    \   }\n    build();\n  }\n#endif\n\n  void build() {\n    assert(!prepared);\n\
    \    prepared = true;\n    indptr.assign(N + 1, 0);\n    for (auto&& e: edges)\
    \ {\n      indptr[e.frm + 1]++;\n      if (!directed) indptr[e.to + 1]++;\n  \
    \  }\n    for (int v = 0; v < N; ++v) { indptr[v + 1] += indptr[v]; }\n    auto\
    \ counter = indptr;\n    csr_edges.resize(indptr.back() + 1);\n    for (auto&&\
    \ e: edges) {\n      csr_edges[counter[e.frm]++] = e;\n      if (!directed)\n\
    \        csr_edges[counter[e.to]++] = edge_type({e.to, e.frm, e.cost, e.id});\n\
    \    }\n  }\n\n  OutgoingEdges operator[](int v) const {\n    assert(prepared);\n\
    \    return {this, indptr[v], indptr[v + 1]};\n  }\n\n  vc<int> deg_array() {\n\
    \    if (vc_deg.empty()) calc_deg();\n    return vc_deg;\n  }\n\n  pair<vc<int>,\
    \ vc<int>> deg_array_inout() {\n    if (vc_indeg.empty()) calc_deg_inout();\n\
    \    return {vc_indeg, vc_outdeg};\n  }\n\n  int deg(int v) {\n    if (vc_deg.empty())\
    \ calc_deg();\n    return vc_deg[v];\n  }\n\n  int in_deg(int v) {\n    if (vc_indeg.empty())\
    \ calc_deg_inout();\n    return vc_indeg[v];\n  }\n\n  int out_deg(int v) {\n\
    \    if (vc_outdeg.empty()) calc_deg_inout();\n    return vc_outdeg[v];\n  }\n\
    \n#ifdef FASTIO\n  void debug() {\n    print(\"Graph\");\n    if (!prepared) {\n\
    \      print(\"frm to cost id\");\n      for (auto&& e: edges) print(e.frm, e.to,\
    \ e.cost, e.id);\n    } else {\n      print(\"indptr\", indptr);\n      print(\"\
    frm to cost id\");\n      FOR(v, N) for (auto&& e: (*this)[v]) print(e.frm, e.to,\
    \ e.cost, e.id);\n    }\n  }\n#endif\n\n  vc<int> new_idx;\n  vc<bool> used_e;\n\
    \n  // G \u306B\u304A\u3051\u308B\u9802\u70B9 V[i] \u304C\u3001\u65B0\u3057\u3044\
    \u30B0\u30E9\u30D5\u3067 i \u306B\u306A\u308B\u3088\u3046\u306B\u3059\u308B\n\
    \  // {G, es}\n  // sum(deg(v)) \u306E\u8A08\u7B97\u91CF\u306B\u306A\u3063\u3066\
    \u3044\u3066\u3001\n  // \u65B0\u3057\u3044\u30B0\u30E9\u30D5\u306E n+m \u3088\
    \u308A\u5927\u304D\u3044\u53EF\u80FD\u6027\u304C\u3042\u308B\u306E\u3067\u6CE8\
    \u610F\n  Graph<T, directed> rearrange(vc<int> V, bool keep_eid = 0) {\n    if\
    \ (len(new_idx) != N) new_idx.assign(N, -1);\n    int n = len(V);\n    FOR(i,\
    \ n) new_idx[V[i]] = i;\n    Graph<T, directed> G(n);\n    vc<int> history;\n\
    \    FOR(i, n) {\n      for (auto&& e: (*this)[V[i]]) {\n        if (len(used_e)\
    \ <= e.id) used_e.resize(e.id + 1);\n        if (used_e[e.id]) continue;\n   \
    \     int a = e.frm, b = e.to;\n        if (new_idx[a] != -1 && new_idx[b] !=\
    \ -1) {\n          history.eb(e.id);\n          used_e[e.id] = 1;\n          int\
    \ eid = (keep_eid ? e.id : -1);\n          G.add(new_idx[a], new_idx[b], e.cost,\
    \ eid);\n        }\n      }\n    }\n    FOR(i, n) new_idx[V[i]] = -1;\n    for\
    \ (auto&& eid: history) used_e[eid] = 0;\n    G.build();\n    return G;\n  }\n\
    \n  Graph<T, true> to_directed_tree(int root = -1) {\n    if (root == -1) root\
    \ = 0;\n    assert(!is_directed && prepared && M == N - 1);\n    Graph<T, true>\
    \ G1(N);\n    vc<int> par(N, -1);\n    auto dfs = [&](auto& dfs, int v) -> void\
    \ {\n      for (auto& e: (*this)[v]) {\n        if (e.to == par[v]) continue;\n\
    \        par[e.to] = v, dfs(dfs, e.to);\n      }\n    };\n    dfs(dfs, root);\n\
    \    for (auto& e: edges) {\n      int a = e.frm, b = e.to;\n      if (par[a]\
    \ == b) swap(a, b);\n      assert(par[b] == a);\n      G1.add(a, b, e.cost);\n\
    \    }\n    G1.build();\n    return G1;\n  }\n\nprivate:\n  void calc_deg() {\n\
    \    assert(vc_deg.empty());\n    vc_deg.resize(N);\n    for (auto&& e: edges)\
    \ vc_deg[e.frm]++, vc_deg[e.to]++;\n  }\n\n  void calc_deg_inout() {\n    assert(vc_indeg.empty());\n\
    \    vc_indeg.resize(N);\n    vc_outdeg.resize(N);\n    for (auto&& e: edges)\
    \ { vc_indeg[e.to]++, vc_outdeg[e.frm]++; }\n  }\n};\n#line 2 \"geo/base.hpp\"\
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
    \ const {\n    if (x != p.x) return x < p.x;\n    return y < p.y;\n  }\n  T dot(Point\
    \ other) { return x * other.x + y * other.y; }\n  T det(Point other) { return\
    \ x * other.y - y * other.x; }\n\n  double norm() { return sqrtl(x * x + y * y);\
    \ }\n  double angle() { return atan2(y, x); }\n\n  Point rotate(double theta)\
    \ {\n    static_assert(!is_integral<T>::value);\n    double c = cos(theta), s\
    \ = sin(theta);\n    return Point{c * x - s * y, s * x + c * y};\n  }\n};\n\n\
    #ifdef FASTIO\ntemplate <typename T>\nvoid rd(Point<T> &p) {\n  fastio::rd(p.x),\
    \ fastio::rd(p.y);\n}\ntemplate <typename T>\nvoid wt(Point<T> &p) {\n  fastio::wt(p.x);\n\
    \  fastio::wt(' ');\n  fastio::wt(p.y);\n}\n#endif\n\n// A -> B -> C \u3068\u9032\
    \u3080\u3068\u304D\u306B\u3001\u5DE6\u306B\u66F2\u304C\u308B\u306A\u3089\u3070\
    \ +1\u3001\u53F3\u306B\u66F2\u304C\u308B\u306A\u3089\u3070 -1\ntemplate <typename\
    \ T>\nint ccw(Point<T> A, Point<T> B, Point<T> C) {\n  T x = (B - A).det(C - A);\n\
    \  if (x > 0) return 1;\n  if (x < 0) return -1;\n  return 0;\n}\n\ntemplate <typename\
    \ REAL, typename T, typename U>\nREAL dist(Point<T> A, Point<U> B) {\n  REAL dx\
    \ = REAL(A.x) - REAL(B.x);\n  REAL dy = REAL(A.y) - REAL(B.y);\n  return sqrt(dx\
    \ * dx + dy * dy);\n}\n\n// ax+by+c\ntemplate <typename T>\nstruct Line {\n  T\
    \ a, b, c;\n\n  Line(T a, T b, T c) : a(a), b(b), c(c) {}\n  Line(Point<T> A,\
    \ Point<T> B) {\n    a = A.y - B.y, b = B.x - A.x, c = A.x * B.y - A.y * B.x;\n\
    \  }\n  Line(T x1, T y1, T x2, T y2) : Line(Point<T>(x1, y1), Point<T>(x2, y2))\
    \ {}\n\n  template <typename U>\n  U eval(Point<U> P) {\n    return a * P.x +\
    \ b * P.y + c;\n  }\n\n  template <typename U>\n  T eval(U x, U y) {\n    return\
    \ a * x + b * y + c;\n  }\n\n  // \u540C\u3058\u76F4\u7DDA\u304C\u540C\u3058 a,b,c\
    \ \u3067\u8868\u73FE\u3055\u308C\u308B\u3088\u3046\u306B\u3059\u308B\n  void normalize()\
    \ {\n    static_assert(is_same_v<T, int> || is_same_v<T, long long>);\n    T g\
    \ = gcd(gcd(abs(a), abs(b)), abs(c));\n    a /= g, b /= g, c /= g;\n    if (b\
    \ < 0) { a = -a, b = -b, c = -c; }\n    if (b == 0 && a < 0) { a = -a, b = -b,\
    \ c = -c; }\n  }\n\n  bool is_parallel(Line other) { return a * other.b - b *\
    \ other.a == 0; }\n  bool is_orthogonal(Line other) { return a * other.a + b *\
    \ other.b == 0; }\n};\n\ntemplate <typename T>\nstruct Segment {\n  Point<T> A,\
    \ B;\n\n  Segment(Point<T> A, Point<T> B) : A(A), B(B) {}\n  Segment(T x1, T y1,\
    \ T x2, T y2)\n      : Segment(Point<T>(x1, y1), Point<T>(x2, y2)) {}\n\n  bool\
    \ contain(Point<T> C) {\n    static_assert(is_integral<T>::value);\n    T det\
    \ = (C - A).det(B - A);\n    if (det != 0) return 0;\n    return (C - A).dot(B\
    \ - A) >= 0 && (C - B).dot(A - B) >= 0;\n  }\n\n  Line<T> to_Line() { return Line(A,\
    \ B); }\n};\n\ntemplate <typename REAL>\nstruct Circle {\n  Point<REAL> O;\n \
    \ REAL r;\n  Circle(Point<REAL> O, REAL r) : O(O), r(r) {}\n  Circle(REAL x, REAL\
    \ y, REAL r) : O(x, y), r(r) {}\n  template <typename T>\n  bool contain(Point<T>\
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
    #line 2 \"geo/angle_sort.hpp\"\n\r\n#line 4 \"geo/angle_sort.hpp\"\n\r\n// \u504F\
    \u89D2\u30BD\u30FC\u30C8\u306B\u5BFE\u3059\u308B argsort\r\ntemplate <typename\
    \ T>\r\nvector<int> angle_sort(vector<Point<T>>& P) {\r\n  vector<int> lower,\
    \ origin, upper;\r\n  const Point<T> O = {0, 0};\r\n  FOR(i, len(P)) {\r\n   \
    \ if (P[i] == O) origin.eb(i);\r\n    elif ((P[i].y < 0) || (P[i].y == 0 && P[i].x\
    \ > 0)) lower.eb(i);\r\n    else upper.eb(i);\r\n  }\r\n  sort(all(lower), [&](auto&\
    \ i, auto& j) { return P[i].det(P[j]) > 0; });\r\n  sort(all(upper), [&](auto&\
    \ i, auto& j) { return P[i].det(P[j]) > 0; });\r\n  return concat(lower, orign,\
    \ upper);\r\n}\r\n\r\n// \u504F\u89D2\u30BD\u30FC\u30C8\u306B\u5BFE\u3059\u308B\
    \ argsort\r\ntemplate <typename T>\r\nvector<int> angle_sort(vector<pair<T, T>>&\
    \ P) {\r\n  vc<Point<T>> tmp(len(P));\r\n  FOR(i, len(P)) tmp[i] = Point<T>(P[i]);\r\
    \n  return angle_sort<T>(tmp);\r\n}\r\n#line 4 \"graph/planar_graph.hpp\"\n\n\
    /*\n\u30FB\u9023\u7D50\u5E73\u9762\u30B0\u30E9\u30D5\u306B\u306A\u3063\u3066\u3044\
    \u306A\u3044\u3068\u304D\u306B\u3069\u3046\u52D5\u4F5C\u3059\u308B\u304B\u306F\
    \u4F55\u3082\u8003\u3048\u3066\u3044\u306A\u3044\n\u30FBN=1 \u3082\u6271\u308F\
    \u306A\u3044\n*/\ntemplate <typename XY>\nstruct Planar_Graph {\n  using P = Point<XY>;\n\
    \  int NV, NE, NF;\n  // \u9802\u70B9, \u8FBA\u304B\u3089\u306A\u308B\u30B0\u30E9\
    \u30D5. \u6709\u5411\u8FBA\u3092 2 \u3064\u5165\u308C\u3066\u304A\u304F\n  Graph<int,\
    \ 1> G;\n  // \u9802\u70B9\u5C5E\u6027\n  vc<P> point; // \u5EA7\u6A19\n  // \u8FBA\
    \u5C5E\u6027\n  vc<int> left_face; // \u6709\u5411\u8FBA\u306E\u5DE6\u306B\u3042\
    \u308B\u9762\u306E\u756A\u53F7\n  vc<int> nxt_edge;  // \u9762\u3092\u53CD\u6642\
    \u8A08\u56DE\u308A\u306B\u307E\u308F\u308B\u3068\u304D\u306E\u6B21\u306E\u8FBA\
    \n  // \u9762\u5C5E\u6027\n  vc<int> first_edge;\n\n  Planar_Graph(int N, vc<P>\
    \ point) : NV(N), G(N), point(point) {\n    assert(N > 1);\n  }\n\n  void add(int\
    \ a, int b) { G.add(a, b), G.add(b, a); }\n  void build() {\n    G.build();\n\
    \    NE = G.M / 2;\n    nxt_edge.assign(G.M, -1);\n    left_face.assign(G.M, -1);\n\
    \    int v0 = 0;\n    int e0 = 0;\n    FOR(v, NV) {\n      if (point[v] < point[v0])\
    \ v0 = v;\n      vc<int> eid;\n      vc<P> dir;\n      for (auto& e: G[v]) {\n\
    \        eid.eb(e.id);\n        dir.eb(point[e.to] - point[e.frm]);\n      }\n\
    \      auto I = angle_sort(dir);\n      assert(len(I) > 0);\n      FOR(k, len(I))\
    \ {\n        int i = (k == 0 ? I.back() : I[k - 1]);\n        int j = I[k];\n\
    \        i = eid[i], j = eid[j];\n        nxt_edge[j ^ 1] = i;\n      }\n    \
    \  if (v == v0) e0 = eid[I[0] ^ 1];\n    }\n    for (auto& x: nxt_edge) assert(x\
    \ != -1);\n\n    auto make_face = [&](int e) -> void {\n      int p = len(first_edge);\n\
    \      first_edge.eb(e);\n      while (left_face[e] == -1) {\n        left_face[e]\
    \ = p;\n        e = nxt_edge[e];\n      }\n    };\n\n    make_face(e0);\n    FOR(e,\
    \ 2 * NE) {\n      if (left_face[e] == -1) make_face(e);\n    }\n    NF = len(first_edge);\n\
    \    assert(NV - NE + NF == 2);\n  }\n\n  // return {vs, es}\n  // vs = [v0,v1,v2,v0],\
    \ es = [e0,e1,e2]\n  pair<vc<int>, vc<int>> get_face_data(int fid) {\n    vc<int>\
    \ eid = {first_edge[fid]};\n    while (1) {\n      int e = nxt_edge[eid.back()];\n\
    \      if (e == first_edge[fid]) break;\n      eid.eb(e);\n    }\n    vc<int>\
    \ vid;\n    for (auto& e: eid) vid.eb(G.edges[e].frm);\n    vid.eb(vid[0]);\n\
    \    return {vid, eid};\n  }\n};\n"
  code: "#include \"graph/base.hpp\"\n#include \"geo/base.hpp\"\n#include \"geo/angle_sort.hpp\"\
    \n\n/*\n\u30FB\u9023\u7D50\u5E73\u9762\u30B0\u30E9\u30D5\u306B\u306A\u3063\u3066\
    \u3044\u306A\u3044\u3068\u304D\u306B\u3069\u3046\u52D5\u4F5C\u3059\u308B\u304B\
    \u306F\u4F55\u3082\u8003\u3048\u3066\u3044\u306A\u3044\n\u30FBN=1 \u3082\u6271\
    \u308F\u306A\u3044\n*/\ntemplate <typename XY>\nstruct Planar_Graph {\n  using\
    \ P = Point<XY>;\n  int NV, NE, NF;\n  // \u9802\u70B9, \u8FBA\u304B\u3089\u306A\
    \u308B\u30B0\u30E9\u30D5. \u6709\u5411\u8FBA\u3092 2 \u3064\u5165\u308C\u3066\u304A\
    \u304F\n  Graph<int, 1> G;\n  // \u9802\u70B9\u5C5E\u6027\n  vc<P> point; // \u5EA7\
    \u6A19\n  // \u8FBA\u5C5E\u6027\n  vc<int> left_face; // \u6709\u5411\u8FBA\u306E\
    \u5DE6\u306B\u3042\u308B\u9762\u306E\u756A\u53F7\n  vc<int> nxt_edge;  // \u9762\
    \u3092\u53CD\u6642\u8A08\u56DE\u308A\u306B\u307E\u308F\u308B\u3068\u304D\u306E\
    \u6B21\u306E\u8FBA\n  // \u9762\u5C5E\u6027\n  vc<int> first_edge;\n\n  Planar_Graph(int\
    \ N, vc<P> point) : NV(N), G(N), point(point) {\n    assert(N > 1);\n  }\n\n \
    \ void add(int a, int b) { G.add(a, b), G.add(b, a); }\n  void build() {\n   \
    \ G.build();\n    NE = G.M / 2;\n    nxt_edge.assign(G.M, -1);\n    left_face.assign(G.M,\
    \ -1);\n    int v0 = 0;\n    int e0 = 0;\n    FOR(v, NV) {\n      if (point[v]\
    \ < point[v0]) v0 = v;\n      vc<int> eid;\n      vc<P> dir;\n      for (auto&\
    \ e: G[v]) {\n        eid.eb(e.id);\n        dir.eb(point[e.to] - point[e.frm]);\n\
    \      }\n      auto I = angle_sort(dir);\n      assert(len(I) > 0);\n      FOR(k,\
    \ len(I)) {\n        int i = (k == 0 ? I.back() : I[k - 1]);\n        int j =\
    \ I[k];\n        i = eid[i], j = eid[j];\n        nxt_edge[j ^ 1] = i;\n     \
    \ }\n      if (v == v0) e0 = eid[I[0] ^ 1];\n    }\n    for (auto& x: nxt_edge)\
    \ assert(x != -1);\n\n    auto make_face = [&](int e) -> void {\n      int p =\
    \ len(first_edge);\n      first_edge.eb(e);\n      while (left_face[e] == -1)\
    \ {\n        left_face[e] = p;\n        e = nxt_edge[e];\n      }\n    };\n\n\
    \    make_face(e0);\n    FOR(e, 2 * NE) {\n      if (left_face[e] == -1) make_face(e);\n\
    \    }\n    NF = len(first_edge);\n    assert(NV - NE + NF == 2);\n  }\n\n  //\
    \ return {vs, es}\n  // vs = [v0,v1,v2,v0], es = [e0,e1,e2]\n  pair<vc<int>, vc<int>>\
    \ get_face_data(int fid) {\n    vc<int> eid = {first_edge[fid]};\n    while (1)\
    \ {\n      int e = nxt_edge[eid.back()];\n      if (e == first_edge[fid]) break;\n\
    \      eid.eb(e);\n    }\n    vc<int> vid;\n    for (auto& e: eid) vid.eb(G.edges[e].frm);\n\
    \    vid.eb(vid[0]);\n    return {vid, eid};\n  }\n};\n"
  dependsOn:
  - graph/base.hpp
  - geo/base.hpp
  - geo/angle_sort.hpp
  isVerificationFile: false
  path: graph/planar_graph.hpp
  requiredBy: []
  timestamp: '2024-07-23 21:27:24+09:00'
  verificationStatus: LIBRARY_ALL_WA
  verifiedWith:
  - test/yukicoder/1777.test.cpp
documentation_of: graph/planar_graph.hpp
layout: document
redirect_from:
- /library/graph/planar_graph.hpp
- /library/graph/planar_graph.hpp.html
title: graph/planar_graph.hpp
---
