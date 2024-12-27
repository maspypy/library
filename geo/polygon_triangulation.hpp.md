---
data:
  _extendedDependsOn:
  - icon: ':question:'
    path: ds/hashmap.hpp
    title: ds/hashmap.hpp
  - icon: ':question:'
    path: ds/splaytree/splaytree.hpp
    title: ds/splaytree/splaytree.hpp
  - icon: ':question:'
    path: ds/splaytree/splaytree_basic.hpp
    title: ds/splaytree/splaytree_basic.hpp
  - icon: ':question:'
    path: geo/angle_sort.hpp
    title: geo/angle_sort.hpp
  - icon: ':question:'
    path: geo/base.hpp
    title: geo/base.hpp
  - icon: ':question:'
    path: graph/base.hpp
    title: graph/base.hpp
  - icon: ':heavy_check_mark:'
    path: graph/planar_graph.hpp
    title: graph/planar_graph.hpp
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/1_mytest/polygon_triangulation.test.cpp
    title: test/1_mytest/polygon_triangulation.test.cpp
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
    \  return 0;\n}\n\ntemplate <typename REAL, typename T, typename U>\nREAL dist(Point<T>\
    \ A, Point<U> B) {\n  REAL dx = REAL(A.x) - REAL(B.x);\n  REAL dy = REAL(A.y)\
    \ - REAL(B.y);\n  return sqrt(dx * dx + dy * dy);\n}\n\n// ax+by+c\ntemplate <typename\
    \ T>\nstruct Line {\n  T a, b, c;\n\n  Line(T a, T b, T c) : a(a), b(b), c(c)\
    \ {}\n  Line(Point<T> A, Point<T> B) { a = A.y - B.y, b = B.x - A.x, c = A.x *\
    \ B.y - A.y * B.x; }\n  Line(T x1, T y1, T x2, T y2) : Line(Point<T>(x1, y1),\
    \ Point<T>(x2, y2)) {}\n\n  template <typename U>\n  U eval(Point<U> P) {\n  \
    \  return a * P.x + b * P.y + c;\n  }\n\n  template <typename U>\n  T eval(U x,\
    \ U y) {\n    return a * x + b * y + c;\n  }\n\n  // \u540C\u3058\u76F4\u7DDA\u304C\
    \u540C\u3058 a,b,c \u3067\u8868\u73FE\u3055\u308C\u308B\u3088\u3046\u306B\u3059\
    \u308B\n  void normalize() {\n    static_assert(is_same_v<T, int> || is_same_v<T,\
    \ long long>);\n    T g = gcd(gcd(abs(a), abs(b)), abs(c));\n    a /= g, b /=\
    \ g, c /= g;\n    if (b < 0) { a = -a, b = -b, c = -c; }\n    if (b == 0 && a\
    \ < 0) { a = -a, b = -b, c = -c; }\n  }\n\n  bool is_parallel(Line other) { return\
    \ a * other.b - b * other.a == 0; }\n  bool is_orthogonal(Line other) { return\
    \ a * other.a + b * other.b == 0; }\n};\n\ntemplate <typename T>\nstruct Segment\
    \ {\n  Point<T> A, B;\n\n  Segment(Point<T> A, Point<T> B) : A(A), B(B) {}\n \
    \ Segment(T x1, T y1, T x2, T y2) : Segment(Point<T>(x1, y1), Point<T>(x2, y2))\
    \ {}\n\n  bool contain(Point<T> C) {\n    T det = (C - A).det(B - A);\n    if\
    \ (det != 0) return 0;\n    return (C - A).dot(B - A) >= 0 && (C - B).dot(A -\
    \ B) >= 0;\n  }\n\n  Line<T> to_Line() { return Line(A, B); }\n};\n\ntemplate\
    \ <typename REAL>\nstruct Circle {\n  Point<REAL> O;\n  REAL r;\n  Circle(Point<REAL>\
    \ O, REAL r) : O(O), r(r) {}\n  Circle(REAL x, REAL y, REAL r) : O(x, y), r(r)\
    \ {}\n  template <typename T>\n  bool contain(Point<T> p) {\n    REAL dx = p.x\
    \ - O.x, dy = p.y - O.y;\n    return dx * dx + dy * dy <= r * r;\n  }\n};\n#line\
    \ 2 \"ds/splaytree/splaytree.hpp\"\n\n/*\nupdate \u3067\u3061\u3083\u3093\u3068\
    \ prod \u304C\u8A08\u7B97\u3055\u308C\u3066\u304F\u308C\u308C\u3070 prod \u306F\
    \ op(lprod,x,rprod) \u3067\u306A\u304F\u3066\u3082\u3088\u3044.\n*/\n\n// Node\
    \ \u578B\u3092\u5225\u306B\u5B9A\u7FA9\u3057\u3066\u4F7F\u3046\ntemplate <typename\
    \ Node>\nstruct SplayTree {\n  Node *pool;\n  const int NODES;\n  int pid;\n \
    \ using np = Node *;\n  using X = typename Node::value_type;\n  using A = typename\
    \ Node::operator_type;\n  vc<np> FREE;\n\n  SplayTree(int NODES) : NODES(NODES),\
    \ pid(0) { pool = new Node[NODES]; }\n  ~SplayTree() { delete[] pool; }\n\n  void\
    \ free_subtree(np c) {\n    if (!c) return;\n    auto dfs = [&](auto &dfs, np\
    \ c) -> void {\n      if (c->l) dfs(dfs, c->l);\n      if (c->r) dfs(dfs, c->r);\n\
    \      FREE.eb(c);\n    };\n    dfs(dfs, c);\n  }\n\n  void reset() {\n    pid\
    \ = 0;\n    FREE.clear();\n  }\n\n  np new_root() { return nullptr; }\n\n  np\
    \ new_node(const X &x) {\n    assert(!FREE.empty() || pid < NODES);\n    np n\
    \ = (FREE.empty() ? &(pool[pid++]) : POP(FREE));\n    Node::new_node(n, x);\n\
    \    return n;\n  }\n\n  np new_node(const vc<X> &dat) {\n    auto dfs = [&](auto\
    \ &dfs, int l, int r) -> np {\n      if (l == r) return nullptr;\n      if (r\
    \ == l + 1) return new_node(dat[l]);\n      int m = (l + r) / 2;\n      np l_root\
    \ = dfs(dfs, l, m);\n      np r_root = dfs(dfs, m + 1, r);\n      np root = new_node(dat[m]);\n\
    \      root->l = l_root, root->r = r_root;\n      if (l_root) l_root->p = root;\n\
    \      if (r_root) r_root->p = root;\n      root->update();\n      return root;\n\
    \    };\n    return dfs(dfs, 0, len(dat));\n  }\n\n  u32 get_size(np root) { return\
    \ (root ? root->size : 0); }\n\n  np merge(np l_root, np r_root) {\n    if (!l_root)\
    \ return r_root;\n    if (!r_root) return l_root;\n    assert((!l_root->p) &&\
    \ (!r_root->p));\n    splay_kth(r_root, 0); // splay \u3057\u305F\u306E\u3067\
    \ prop \u6E08\n    r_root->l = l_root;\n    l_root->p = r_root;\n    r_root->update();\n\
    \    return r_root;\n  }\n  np merge3(np a, np b, np c) { return merge(merge(a,\
    \ b), c); }\n  np merge4(np a, np b, np c, np d) { return merge(merge(merge(a,\
    \ b), c), d); }\n\n  pair<np, np> split(np root, u32 k) {\n    assert(!root ||\
    \ !root->p);\n    if (k == 0) return {nullptr, root};\n    if (k == (root->size))\
    \ return {root, nullptr};\n    splay_kth(root, k - 1);\n    np right = root->r;\n\
    \    root->r = nullptr, right->p = nullptr;\n    root->update();\n    return {root,\
    \ right};\n  }\n  tuple<np, np, np> split3(np root, u32 l, u32 r) {\n    np nm,\
    \ nr;\n    tie(root, nr) = split(root, r);\n    tie(root, nm) = split(root, l);\n\
    \    return {root, nm, nr};\n  }\n  tuple<np, np, np, np> split4(np root, u32\
    \ i, u32 j, u32 k) {\n    np d;\n    tie(root, d) = split(root, k);\n    auto\
    \ [a, b, c] = split3(root, i, j);\n    return {a, b, c, d};\n  }\n\n  tuple<np,\
    \ np, np> split_L_root_R(np root) {\n    u32 s = (root->l ? root->l->size : 0);\n\
    \    return split3(root, s, s + 1);\n  }\n\n  // \u90E8\u5206\u6728\u304C\u533A\
    \u9593 [l,r) \u306B\u5BFE\u5FDC\u3059\u308B\u3088\u3046\u306A\u30CE\u30FC\u30C9\
    \u3092\u4F5C\u3063\u3066\u8FD4\u3059\n  // \u305D\u306E\u30CE\u30FC\u30C9\u304C\
    \ root \u306B\u306A\u308B\u308F\u3051\u3067\u306F\u306A\u3044\u306E\u3067\u3001\
    \n  // \u3053\u306E\u30CE\u30FC\u30C9\u3092\u53C2\u7167\u3057\u305F\u5F8C\u306B\
    \u3059\u3050\u306B splay \u3057\u3066\u6839\u306B\u6301\u3061\u4E0A\u3052\u308B\
    \u3053\u3068\n  void goto_between(np &root, u32 l, u32 r) {\n    if (l == 0 &&\
    \ r == root->size) return;\n    if (l == 0) {\n      splay_kth(root, r);\n   \
    \   root = root->l;\n      return;\n    }\n    if (r == root->size) {\n      splay_kth(root,\
    \ l - 1);\n      root = root->r;\n      return;\n    }\n    splay_kth(root, r);\n\
    \    np rp = root;\n    root = rp->l;\n    root->p = nullptr;\n    splay_kth(root,\
    \ l - 1);\n    root->p = rp;\n    rp->l = root;\n    rp->update();\n    root =\
    \ root->r;\n  }\n\n  vc<X> get_all(const np &root) {\n    vc<X> res;\n    auto\
    \ dfs = [&](auto &dfs, np root) -> void {\n      if (!root) return;\n      root->prop();\n\
    \      dfs(dfs, root->l);\n      res.eb(root->get());\n      dfs(dfs, root->r);\n\
    \    };\n    dfs(dfs, root);\n    return res;\n  }\n\n  X get(np &root, u32 k)\
    \ {\n    assert(root == nullptr || !root->p);\n    splay_kth(root, k);\n    return\
    \ root->get();\n  }\n\n  void set(np &root, u32 k, const X &x) {\n    assert(root\
    \ != nullptr && !root->p);\n    splay_kth(root, k);\n    root->set(x);\n  }\n\n\
    \  void multiply(np &root, u32 k, const X &x) {\n    assert(root != nullptr &&\
    \ !root->p);\n    splay_kth(root, k);\n    root->multiply(x);\n  }\n\n  X prod(np\
    \ &root, u32 l, u32 r) {\n    assert(root == nullptr || !root->p);\n    using\
    \ Mono = typename Node::Monoid_X;\n    if (l == r) return Mono::unit();\n    assert(0\
    \ <= l && l < r && r <= root->size);\n    goto_between(root, l, r);\n    X res\
    \ = root->prod;\n    splay(root, true);\n    return res;\n  }\n\n  X prod(np &root)\
    \ {\n    assert(root == nullptr || !root->p);\n    using Mono = typename Node::Monoid_X;\n\
    \    return (root ? root->prod : Mono::unit());\n  }\n\n  void apply(np &root,\
    \ u32 l, u32 r, const A &a) {\n    if (l == r) return;\n    assert(0 <= l && l\
    \ < r && r <= root->size);\n    goto_between(root, l, r);\n    root->apply(a);\n\
    \    splay(root, true);\n  }\n  void apply(np &root, const A &a) {\n    if (!root)\
    \ return;\n    root->apply(a);\n  }\n\n  void reverse(np &root, u32 l, u32 r)\
    \ {\n    assert(root == nullptr || !root->p);\n    if (l == r) return;\n    assert(0\
    \ <= l && l < r && r <= root->size);\n    goto_between(root, l, r);\n    root->reverse();\n\
    \    splay(root, true);\n  }\n  void reverse(np root) {\n    if (!root) return;\n\
    \    root->reverse();\n  }\n\n  void rotate(Node *n) {\n    // n \u3092\u6839\u306B\
    \u8FD1\u3065\u3051\u308B\u3002prop, update \u306F rotate \u306E\u5916\u3067\u884C\
    \u3046\u3002\n    Node *pp, *p, *c;\n    p = n->p;\n    pp = p->p;\n    if (p->l\
    \ == n) {\n      c = n->r;\n      n->r = p;\n      p->l = c;\n    } else {\n \
    \     c = n->l;\n      n->l = p;\n      p->r = c;\n    }\n    if (pp && pp->l\
    \ == p) pp->l = n;\n    if (pp && pp->r == p) pp->r = n;\n    n->p = pp;\n   \
    \ p->p = n;\n    if (c) c->p = p;\n  }\n\n  void prop_from_root(np c) {\n    if\
    \ (!c->p) {\n      c->prop();\n      return;\n    }\n    prop_from_root(c->p);\n\
    \    c->prop();\n  }\n\n  void splay(Node *me, bool prop_from_root_done) {\n \
    \   // \u3053\u308C\u3092\u547C\u3076\u6642\u70B9\u3067\u3001me \u306E\u7956\u5148\
    \uFF08me \u3092\u9664\u304F\uFF09\u306F\u65E2\u306B prop \u6E08\u3067\u3042\u308B\
    \u3053\u3068\u3092\u4EEE\u5B9A\n    // \u7279\u306B\u3001splay \u7D42\u4E86\u6642\
    \u70B9\u3067 me \u306F upd / prop \u6E08\u3067\u3042\u308B\n    if (!prop_from_root_done)\
    \ prop_from_root(me);\n    me->prop();\n    while (me->p) {\n      np p = me->p;\n\
    \      np pp = p->p;\n      if (!pp) {\n        rotate(me);\n        p->update();\n\
    \        break;\n      }\n      bool same = (p->l == me && pp->l == p) || (p->r\
    \ == me && pp->r == p);\n      if (same) rotate(p), rotate(me);\n      if (!same)\
    \ rotate(me), rotate(me);\n      pp->update(), p->update();\n    }\n    // me\
    \ \u306E update \u306F\u6700\u5F8C\u3060\u3051\u3067\u3088\u3044\n    me->update();\n\
    \  }\n\n  void splay_kth(np &root, u32 k) {\n    assert(0 <= k && k < (root->size));\n\
    \    while (1) {\n      root->prop();\n      u32 sl = (root->l ? root->l->size\
    \ : 0);\n      if (k == sl) break;\n      if (k < sl)\n        root = root->l;\n\
    \      else {\n        k -= sl + 1;\n        root = root->r;\n      }\n    }\n\
    \    splay(root, true);\n  }\n\n  // check(x), \u5DE6\u5074\u306E\u30CE\u30FC\u30C9\
    \u5168\u4F53\u304C check \u3092\u6E80\u305F\u3059\u3088\u3046\u306B\u5207\u308B\
    \n  template <typename F>\n  pair<np, np> split_max_right(np root, F check) {\n\
    \    if (!root) return {nullptr, nullptr};\n    assert(!root->p);\n    np c =\
    \ find_max_right(root, check);\n    if (!c) {\n      splay(root, true);\n    \
    \  return {nullptr, root};\n    }\n    splay(c, true);\n    np right = c->r;\n\
    \    if (!right) return {c, nullptr};\n    right->p = nullptr;\n    c->r = nullptr;\n\
    \    c->update();\n    return {c, right};\n  }\n\n  // check(x, cnt), \u5DE6\u5074\
    \u306E\u30CE\u30FC\u30C9\u5168\u4F53\u304C check \u3092\u6E80\u305F\u3059\u3088\
    \u3046\u306B\u5207\u308B\n  template <typename F>\n  pair<np, np> split_max_right_cnt(np\
    \ root, F check) {\n    if (!root) return {nullptr, nullptr};\n    assert(!root->p);\n\
    \    np c = find_max_right_cnt(root, check);\n    if (!c) {\n      splay(root,\
    \ true);\n      return {nullptr, root};\n    }\n    splay(c, true);\n    np right\
    \ = c->r;\n    if (!right) return {c, nullptr};\n    right->p = nullptr;\n   \
    \ c->r = nullptr;\n    c->update();\n    return {c, right};\n  }\n\n  // \u5DE6\
    \u5074\u306E\u30CE\u30FC\u30C9\u5168\u4F53\u306E prod \u304C check \u3092\u6E80\
    \u305F\u3059\u3088\u3046\u306B\u5207\u308B\n  template <typename F>\n  pair<np,\
    \ np> split_max_right_prod(np root, F check) {\n    if (!root) return {nullptr,\
    \ nullptr};\n    assert(!root->p);\n    np c = find_max_right_prod(root, check);\n\
    \    if (!c) {\n      splay(root, true);\n      return {nullptr, root};\n    }\n\
    \    splay(c, true);\n    np right = c->r;\n    if (!right) return {c, nullptr};\n\
    \    right->p = nullptr;\n    c->r = nullptr;\n    c->update();\n    return {c,\
    \ right};\n  }\n\n  template <typename F>\n  np find_max_right(np root, const\
    \ F &check) {\n    // \u6700\u5F8C\u306B\u898B\u3064\u3051\u305F ok \u306E\u70B9\
    \u3001\u6700\u5F8C\u306B\u63A2\u7D22\u3057\u305F\u70B9\n    np last_ok = nullptr,\
    \ last = nullptr;\n    while (root) {\n      last = root;\n      root->prop();\n\
    \      if (check(root->x)) {\n        last_ok = root;\n        root = root->r;\n\
    \      } else {\n        root = root->l;\n      }\n    }\n    splay(last, true);\n\
    \    return last_ok;\n  }\n\n  template <typename F>\n  np find_max_right_cnt(np\
    \ root, const F &check) {\n    // \u6700\u5F8C\u306B\u898B\u3064\u3051\u305F ok\
    \ \u306E\u70B9\u3001\u6700\u5F8C\u306B\u63A2\u7D22\u3057\u305F\u70B9\n    np last_ok\
    \ = nullptr, last = nullptr;\n    ll n = 0;\n    while (root) {\n      last =\
    \ root;\n      root->prop();\n      ll ns = (root->l ? root->l->size : 0);\n \
    \     if (check(root->x, n + ns + 1)) {\n        last_ok = root;\n        n +=\
    \ ns + 1;\n        root = root->r;\n      } else {\n        root = root->l;\n\
    \      }\n    }\n    splay(last, true);\n    return last_ok;\n  }\n\n  template\
    \ <typename F>\n  np find_max_right_prod(np root, const F &check) {\n    using\
    \ Mono = typename Node::Monoid_X;\n    X prod = Mono::unit();\n    // \u6700\u5F8C\
    \u306B\u898B\u3064\u3051\u305F ok \u306E\u70B9\u3001\u6700\u5F8C\u306B\u63A2\u7D22\
    \u3057\u305F\u70B9\n    np last_ok = nullptr, last = nullptr;\n    while (root)\
    \ {\n      last = root;\n      root->prop();\n      np tmp = root->r;\n      root->r\
    \ = nullptr;\n      root->update();\n      X lprod = Mono::op(prod, root->prod);\n\
    \      root->r = tmp;\n      root->update();\n      if (check(lprod)) {\n    \
    \    prod = lprod;\n        last_ok = root;\n        root = root->r;\n      }\
    \ else {\n        root = root->l;\n      }\n    }\n    splay(last, true);\n  \
    \  return last_ok;\n  }\n};\n#line 2 \"ds/splaytree/splaytree_basic.hpp\"\n\n\
    namespace SplayTreeNodes {\ntemplate <typename S>\nstruct Node_Basic {\n  using\
    \ value_type = S;\n  using operator_type = int;\n  using np = Node_Basic *;\n\n\
    \  np p, l, r;\n  bool rev;\n  S x;\n  u32 size;\n\n  static void new_node(np\
    \ n, const S &x) {\n    n->p = n->l = n->r = nullptr;\n    n->x = x, n->size =\
    \ 1, n->rev = 0;\n  }\n\n  void update() {\n    size = 1;\n    if (l) { size +=\
    \ l->size; }\n    if (r) { size += r->size; }\n  }\n\n  void prop() {\n    if\
    \ (rev) {\n      if (l) { l->rev ^= 1, swap(l->l, l->r); }\n      if (r) { r->rev\
    \ ^= 1, swap(r->l, r->r); }\n      rev = 0;\n    }\n  }\n\n  // update, prop \u4EE5\
    \u5916\u3067\u547C\u3070\u308C\u308B\u3082\u306E\u306F\u3001splay \u5F8C\u3067\
    \u3042\u308B\u3053\u3068\u304C\u60F3\u5B9A\u3055\u308C\u3066\u3044\u308B\u3002\
    \n  // \u3057\u305F\u304C\u3063\u3066\u305D\u306E\u6642\u70B9\u3067 update, prop\
    \ \u6E08\u3067\u3042\u308B\u3053\u3068\u3092\u4EEE\u5B9A\u3057\u3066\u3088\u3044\
    \u3002\n  S get() { return x; }\n  void set(const S &xx) {\n    x = xx;\n    update();\n\
    \  }\n  void reverse() {\n    swap(l, r);\n    rev ^= 1;\n  }\n};\ntemplate <typename\
    \ S>\nusing SplayTree_Basic = SplayTree<Node_Basic<S>>;\n} // namespace SplayTreeNodes\n\
    \nusing SplayTreeNodes::SplayTree_Basic;\n#line 2 \"ds/hashmap.hpp\"\n\r\n// u64\
    \ -> Val\r\ntemplate <typename Val>\r\nstruct HashMap {\r\n  // n \u306F\u5165\
    \u308C\u305F\u3044\u3082\u306E\u306E\u500B\u6570\u3067 ok\r\n  HashMap(u32 n =\
    \ 0) { build(n); }\r\n  void build(u32 n) {\r\n    u32 k = 8;\r\n    while (k\
    \ < n * 2) k *= 2;\r\n    cap = k / 2, mask = k - 1;\r\n    key.resize(k), val.resize(k),\
    \ used.assign(k, 0);\r\n  }\r\n\r\n  // size \u3092\u4FDD\u3063\u305F\u307E\u307E\
    . size=0 \u306B\u3059\u308B\u3068\u304D\u306F build \u3059\u308B\u3053\u3068.\r\
    \n  void clear() {\r\n    used.assign(len(used), 0);\r\n    cap = (mask + 1) /\
    \ 2;\r\n  }\r\n  int size() { return len(used) / 2 - cap; }\r\n\r\n  int index(const\
    \ u64& k) {\r\n    int i = 0;\r\n    for (i = hash(k); used[i] && key[i] != k;\
    \ i = (i + 1) & mask) {}\r\n    return i;\r\n  }\r\n\r\n  Val& operator[](const\
    \ u64& k) {\r\n    if (cap == 0) extend();\r\n    int i = index(k);\r\n    if\
    \ (!used[i]) { used[i] = 1, key[i] = k, val[i] = Val{}, --cap; }\r\n    return\
    \ val[i];\r\n  }\r\n\r\n  Val get(const u64& k, Val default_value) {\r\n    int\
    \ i = index(k);\r\n    return (used[i] ? val[i] : default_value);\r\n  }\r\n\r\
    \n  bool count(const u64& k) {\r\n    int i = index(k);\r\n    return used[i]\
    \ && key[i] == k;\r\n  }\r\n\r\n  // f(key, val)\r\n  template <typename F>\r\n\
    \  void enumerate_all(F f) {\r\n    FOR(i, len(used)) if (used[i]) f(key[i], val[i]);\r\
    \n  }\r\n\r\nprivate:\r\n  u32 cap, mask;\r\n  vc<u64> key;\r\n  vc<Val> val;\r\
    \n  vc<bool> used;\r\n\r\n  u64 hash(u64 x) {\r\n    static const u64 FIXED_RANDOM\
    \ = std::chrono::steady_clock::now().time_since_epoch().count();\r\n    x += FIXED_RANDOM;\r\
    \n    x = (x ^ (x >> 30)) * 0xbf58476d1ce4e5b9;\r\n    x = (x ^ (x >> 27)) * 0x94d049bb133111eb;\r\
    \n    return (x ^ (x >> 31)) & mask;\r\n  }\r\n\r\n  void extend() {\r\n    vc<pair<u64,\
    \ Val>> dat;\r\n    dat.reserve(len(used) / 2 - cap);\r\n    FOR(i, len(used))\
    \ {\r\n      if (used[i]) dat.eb(key[i], val[i]);\r\n    }\r\n    build(2 * len(dat));\r\
    \n    for (auto& [a, b]: dat) (*this)[a] = b;\r\n  }\r\n};\n#line 3 \"graph/base.hpp\"\
    \n\ntemplate <typename T>\nstruct Edge {\n  int frm, to;\n  T cost;\n  int id;\n\
    };\n\ntemplate <typename T = int, bool directed = false>\nstruct Graph {\n  static\
    \ constexpr bool is_directed = directed;\n  int N, M;\n  using cost_type = T;\n\
    \  using edge_type = Edge<T>;\n  vector<edge_type> edges;\n  vector<int> indptr;\n\
    \  vector<edge_type> csr_edges;\n  vc<int> vc_deg, vc_indeg, vc_outdeg;\n  bool\
    \ prepared;\n\n  class OutgoingEdges {\n  public:\n    OutgoingEdges(const Graph*\
    \ G, int l, int r) : G(G), l(l), r(r) {}\n\n    const edge_type* begin() const\
    \ {\n      if (l == r) { return 0; }\n      return &G->csr_edges[l];\n    }\n\n\
    \    const edge_type* end() const {\n      if (l == r) { return 0; }\n      return\
    \ &G->csr_edges[r];\n    }\n\n  private:\n    const Graph* G;\n    int l, r;\n\
    \  };\n\n  bool is_prepared() { return prepared; }\n\n  Graph() : N(0), M(0),\
    \ prepared(0) {}\n  Graph(int N) : N(N), M(0), prepared(0) {}\n\n  void build(int\
    \ n) {\n    N = n, M = 0;\n    prepared = 0;\n    edges.clear();\n    indptr.clear();\n\
    \    csr_edges.clear();\n    vc_deg.clear();\n    vc_indeg.clear();\n    vc_outdeg.clear();\n\
    \  }\n\n  void add(int frm, int to, T cost = 1, int i = -1) {\n    assert(!prepared);\n\
    \    assert(0 <= frm && 0 <= to && to < N);\n    if (i == -1) i = M;\n    auto\
    \ e = edge_type({frm, to, cost, i});\n    edges.eb(e);\n    ++M;\n  }\n\n#ifdef\
    \ FASTIO\n  // wt, off\n  void read_tree(bool wt = false, int off = 1) { read_graph(N\
    \ - 1, wt, off); }\n\n  void read_graph(int M, bool wt = false, int off = 1) {\n\
    \    for (int m = 0; m < M; ++m) {\n      INT(a, b);\n      a -= off, b -= off;\n\
    \      if (!wt) {\n        add(a, b);\n      } else {\n        T c;\n        read(c);\n\
    \        add(a, b, c);\n      }\n    }\n    build();\n  }\n#endif\n\n  void build()\
    \ {\n    assert(!prepared);\n    prepared = true;\n    indptr.assign(N + 1, 0);\n\
    \    for (auto&& e: edges) {\n      indptr[e.frm + 1]++;\n      if (!directed)\
    \ indptr[e.to + 1]++;\n    }\n    for (int v = 0; v < N; ++v) { indptr[v + 1]\
    \ += indptr[v]; }\n    auto counter = indptr;\n    csr_edges.resize(indptr.back()\
    \ + 1);\n    for (auto&& e: edges) {\n      csr_edges[counter[e.frm]++] = e;\n\
    \      if (!directed) csr_edges[counter[e.to]++] = edge_type({e.to, e.frm, e.cost,\
    \ e.id});\n    }\n  }\n\n  OutgoingEdges operator[](int v) const {\n    assert(prepared);\n\
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
    \    }\n    G1.build();\n    return G1;\n  }\n\n  HashMap<int> MP_FOR_EID;\n\n\
    \  int get_eid(u64 a, u64 b) {\n    if (len(MP_FOR_EID) == 0) {\n      MP_FOR_EID.build(N\
    \ - 1);\n      for (auto& e: edges) {\n        u64 a = e.frm, b = e.to;\n    \
    \    u64 k = to_eid_key(a, b);\n        MP_FOR_EID[k] = e.id;\n      }\n    }\n\
    \    return MP_FOR_EID.get(to_eid_key(a, b), -1);\n  }\n\n  u64 to_eid_key(u64\
    \ a, u64 b) {\n    if (!directed && a > b) swap(a, b);\n    return N * a + b;\n\
    \  }\n\nprivate:\n  void calc_deg() {\n    assert(vc_deg.empty());\n    vc_deg.resize(N);\n\
    \    for (auto&& e: edges) vc_deg[e.frm]++, vc_deg[e.to]++;\n  }\n\n  void calc_deg_inout()\
    \ {\n    assert(vc_indeg.empty());\n    vc_indeg.resize(N);\n    vc_outdeg.resize(N);\n\
    \    for (auto&& e: edges) { vc_indeg[e.to]++, vc_outdeg[e.frm]++; }\n  }\n};\n\
    #line 2 \"geo/angle_sort.hpp\"\n\r\n#line 4 \"geo/angle_sort.hpp\"\n\r\n// lower:\
    \ -1, origin: 0, upper: 1, (-pi,pi]\r\ntemplate <typename T> int lower_or_upper(const\
    \ Point<T> &p) {\r\n  if (p.y != 0)\r\n    return (p.y > 0 ? 1 : -1);\r\n  if\
    \ (p.x > 0)\r\n    return -1;\r\n  if (p.x < 0)\r\n    return 1;\r\n  return 0;\r\
    \n}\r\n\r\n// L<R:-1, L==R:0, L>R:1, (-pi,pi]\r\ntemplate <typename T> int angle_comp_3(const\
    \ Point<T> &L, const Point<T> &R) {\r\n  int a = lower_or_upper(L), b = lower_or_upper(R);\r\
    \n  if (a != b)\r\n    return (a < b ? -1 : +1);\r\n  T det = L.det(R);\r\n  if\
    \ (det > 0)\r\n    return -1;\r\n  if (det < 0)\r\n    return 1;\r\n  return 0;\r\
    \n}\r\n\r\n// \u504F\u89D2\u30BD\u30FC\u30C8\u306B\u5BFE\u3059\u308B argsort,\
    \ (-pi,pi]\r\ntemplate <typename T> vector<int> angle_sort(vector<Point<T>> &P)\
    \ {\r\n  vc<int> I(len(P));\r\n  FOR(i, len(P)) I[i] = i;\r\n  sort(all(I), [&](auto\
    \ &L, auto &R) -> bool {\r\n    return angle_comp_3(P[L], P[R]) == -1;\r\n  });\r\
    \n  return I;\r\n}\r\n\r\n// \u504F\u89D2\u30BD\u30FC\u30C8\u306B\u5BFE\u3059\u308B\
    \ argsort, (-pi,pi]\r\ntemplate <typename T> vector<int> angle_sort(vector<pair<T,\
    \ T>> &P) {\r\n  vc<Point<T>> tmp(len(P));\r\n  FOR(i, len(P)) tmp[i] = Point<T>(P[i]);\r\
    \n  return angle_sort<T>(tmp);\r\n}\r\n#line 4 \"graph/planar_graph.hpp\"\n\n\
    /*\n\u30FB\u9023\u7D50\u5E73\u9762\u30B0\u30E9\u30D5\u306B\u306A\u3063\u3066\u3044\
    \u306A\u3044\u3068\u304D\u306B\u3069\u3046\u52D5\u4F5C\u3059\u308B\u304B\u306F\
    \u4F55\u3082\u8003\u3048\u3066\u3044\u306A\u3044\n\u30FBN=1 \u3082\u6271\u308F\
    \u306A\u3044\n\u30FB0\u756A\u76EE\u306B\u5916\u9762\u304C\u5165\u308B\n*/\ntemplate\
    \ <typename XY>\nstruct Planar_Graph {\n  using P = Point<XY>;\n  int NV, NE,\
    \ NF;\n  // \u9802\u70B9, \u8FBA\u304B\u3089\u306A\u308B\u30B0\u30E9\u30D5. \u6709\
    \u5411\u8FBA\u3092 2 \u3064\u5165\u308C\u3066\u304A\u304F\n  Graph<int, 1> G;\n\
    \  // \u9802\u70B9\u5C5E\u6027\n  vc<P> point; // \u5EA7\u6A19\n  // \u8FBA\u5C5E\
    \u6027\n  vc<int> left_face; // \u6709\u5411\u8FBA\u306E\u5DE6\u306B\u3042\u308B\
    \u9762\u306E\u756A\u53F7\n  vc<int> nxt_edge;  // \u9762\u3092\u53CD\u6642\u8A08\
    \u56DE\u308A\u306B\u307E\u308F\u308B\u3068\u304D\u306E\u6B21\u306E\u8FBA\n  //\
    \ \u9762\u5C5E\u6027\n  vc<int> first_edge;\n\n  Planar_Graph(int N, vc<P> point)\
    \ : NV(N), G(N), point(point) { assert(N > 1); }\n\n  void add(int a, int b) {\
    \ G.add(a, b), G.add(b, a); }\n  void build() {\n    G.build();\n    NE = G.M\
    \ / 2;\n    nxt_edge.assign(G.M, -1);\n    left_face.assign(G.M, -1);\n    int\
    \ v0 = 0;\n    int e0 = 0;\n    FOR(v, NV) {\n      if (point[v] < point[v0])\
    \ v0 = v;\n      vc<int> eid;\n      vc<P> dir;\n      for (auto& e: G[v]) {\n\
    \        eid.eb(e.id);\n        dir.eb(point[e.to] - point[e.frm]);\n      }\n\
    \      auto I = angle_sort(dir);\n      assert(len(I) > 0);\n      FOR(k, len(I))\
    \ {\n        int i = (k == 0 ? I.back() : I[k - 1]);\n        int j = I[k];\n\
    \        i = eid[i], j = eid[j];\n        nxt_edge[j ^ 1] = i;\n      }\n    \
    \  if (v == v0) e0 = eid[I[0]] ^ 1;\n    }\n    for (auto& x: nxt_edge) assert(x\
    \ != -1);\n\n    auto make_face = [&](int e) -> void {\n      int p = len(first_edge);\n\
    \      first_edge.eb(e);\n      while (left_face[e] == -1) {\n        left_face[e]\
    \ = p;\n        e = nxt_edge[e];\n      }\n    };\n\n    make_face(e0);\n    FOR(e,\
    \ 2 * NE) {\n      if (left_face[e] == -1) make_face(e);\n    }\n    NF = len(first_edge);\n\
    \    assert(NV - NE + NF == 2);\n  }\n\n  // return {vs, es}\n  // vs = [v0,v1,v2,v0],\
    \ es = [e0,e1,e2]\n  pair<vc<int>, vc<int>> get_face_data(int fid) {\n    vc<int>\
    \ eid = {first_edge[fid]};\n    while (1) {\n      int e = nxt_edge[eid.back()];\n\
    \      if (e == first_edge[fid]) break;\n      eid.eb(e);\n    }\n    vc<int>\
    \ vid;\n    for (auto& e: eid) vid.eb(G.edges[e].frm);\n    vid.eb(vid[0]);\n\
    \    return {vid, eid};\n  }\n};\n#line 4 \"geo/polygon_triangulation.hpp\"\n\n\
    template <typename T>\nvc<tuple<int, int, int>> monotone_polygon_triangulation(vc<Point<T>>\
    \ point) {\n  int N = len(point);\n  int rot = min_element(all(point)) - point.begin();\n\
    \  rotate(point.begin(), point.begin() + rot, point.end());\n  int n = max_element(all(point))\
    \ - point.begin();\n  FOR(i, n) assert(point[i] < point[i + 1]);\n  FOR(i, n,\
    \ N) assert(point[(i + 1) % N] < point[i]);\n  vc<tuple<int, int, int>> res;\n\
    \  auto side = [&](int i) -> int {\n    assert(i != 0 && i != n);\n    return\
    \ (i < n ? 0 : 1);\n  };\n  vc<int> I = argsort(point);\n  vc<int> stack = {I[0],\
    \ I[1]};\n  int s = side(I[1]);\n  FOR(i, 2, N - 1) {\n    int v = I[i], t = side(v);\n\
    \    if (s == 0 && t == 0) {\n      while (len(stack) >= 2 && ccw(point[stack[len(stack)\
    \ - 2]], point[stack[len(stack) - 1]], point[v]) == 1) {\n        res.eb(stack[len(stack)\
    \ - 2], stack[len(stack) - 1], v), POP(stack);\n      }\n      stack.eb(v);\n\
    \    }\n    elif (s == 1 && t == 1) {\n      while (len(stack) >= 2 && ccw(point[stack[len(stack)\
    \ - 2]], point[stack[len(stack) - 1]], point[v]) == -1) {\n        res.eb(stack[len(stack)\
    \ - 2], v, stack[len(stack) - 1]), POP(stack);\n      }\n      stack.eb(v);\n\
    \    }\n    elif (s == 0 && t == 1) {\n      FOR(j, len(stack) - 1) res.eb(stack[j],\
    \ stack[j + 1], v);\n      stack = {stack.back(), v}, s = t;\n    }\n    elif\
    \ (s == 1 && t == 0) {\n      FOR(j, len(stack) - 1) res.eb(stack[j], v, stack[j\
    \ + 1]);\n      stack = {stack.back(), v}, s = t;\n    }\n  }\n  if (s == 0) {\
    \ FOR(j, len(stack) - 1) res.eb(stack[j], stack[j + 1], n); }\n  elif (s == 1)\
    \ { FOR(j, len(stack) - 1) res.eb(stack[j], n, stack[j + 1]); }\n  for (auto&\
    \ [a, b, c]: res) a = (a + rot) % N, b = (b + rot) % N, c = (c + rot) % N;\n \
    \ return res;\n}\n\n// (i,j,k), ccw\ntemplate <typename T>\nvc<tuple<int, int,\
    \ int>> polygon_triangulation(vc<Point<T>> point) {\n  using P = Point<T>;\n \
    \ int N = len(point);\n  enum vtype { MERGE, SPLIT, START, END, UPPER, LOWER };\n\
    \  auto pre = [&](int i) -> int { return (i > 0 ? i - 1 : N - 1); };\n  auto nxt\
    \ = [&](int i) -> int { return (i < N - 1 ? i + 1 : 0); };\n  auto get_vtype =\
    \ [&](int i) -> vtype {\n    int l = pre(i), r = nxt(i);\n    if (point[i] < point[l]\
    \ && point[i] < point[r]) { return (ccw(point[l], point[i], point[r]) == 1 ? START\
    \ : SPLIT); }\n    if (point[l] < point[i] && point[r] < point[i]) { return (ccw(point[l],\
    \ point[i], point[r]) == 1 ? END : MERGE); }\n    if (point[l] < point[i] && point[i]\
    \ < point[r]) return LOWER;\n    if (point[r] < point[i] && point[i] < point[l])\
    \ return UPPER;\n    assert(0);\n    return END;\n  };\n  SplayTree_Basic<int>\
    \ ST(N);\n  using np = decltype(ST)::np;\n  vc<np> nodes(N);\n  FOR(i, N) nodes[i]\
    \ = ST.new_node(i);\n  np S = ST.new_root();\n  auto comp = [&](int i, P p) ->\
    \ bool {\n    P A = point[i], B = point[nxt(i)];\n    return ccw(A, B, p) == -1;\n\
    \  };\n\n  vc<int> helper(N, -1);\n  vc<bool> merged(N);\n\n  Planar_Graph<T>\
    \ G(N, point);\n  FOR(i, N) G.add(i, nxt(i));\n\n  auto add_edge = [&](int v,\
    \ int w) -> void { merged[w] = 1, G.add(v, w); };\n\n  auto fix_up = [&](int v,\
    \ int e) -> void {\n    int w = helper[e];\n    if (get_vtype(w) == vtype::MERGE\
    \ && !merged[w]) { add_edge(v, w); }\n  };\n  auto I = argsort(point);\n  for\
    \ (auto& i: I) {\n    vtype t = get_vtype(i);\n    if (t == vtype::MERGE) {\n\
    \      ST.splay(nodes[i], 1), S = nodes[i];\n      int n = (nodes[i]->l ? nodes[i]->l->size\
    \ : 0);\n      auto [L, M, R] = ST.split3(S, n, n + 1);\n      int j = ST.get(R,\
    \ 0);\n      S = ST.merge(L, R);\n      fix_up(i, i), fix_up(i, j);\n      helper[j]\
    \ = i;\n    }\n    if (t == vtype::SPLIT) {\n      auto [L, R] = ST.split_max_right(S,\
    \ [&](int k) -> bool { return comp(k, point[i]); });\n      int j = ST.get(R,\
    \ 0);\n      add_edge(i, helper[j]);\n      helper[j] = i, helper[pre(i)] = i;\n\
    \      S = ST.merge3(L, nodes[pre(i)], R);\n    }\n    if (t == vtype::START)\
    \ {\n      auto [L, R] = ST.split_max_right(S, [&](int k) -> bool { return comp(k,\
    \ point[i]); });\n      S = ST.merge3(L, nodes[pre(i)], R), helper[pre(i)] = i;\n\
    \    }\n    if (t == vtype::END) {\n      ST.splay(nodes[i], 1), S = nodes[i];\n\
    \      int n = (nodes[i]->l ? nodes[i]->l->size : 0);\n      auto [L, M, R] =\
    \ ST.split3(S, n, n + 1);\n      S = ST.merge(L, R);\n      fix_up(i, i);\n  \
    \  }\n    if (t == vtype::UPPER) {\n      ST.splay(nodes[i], 1), S = nodes[i];\n\
    \      int n = (nodes[i]->l ? nodes[i]->l->size : 0);\n      auto [L, M, R] =\
    \ ST.split3(S, n, n + 1);\n      S = ST.merge3(L, nodes[pre(i)], R);\n      fix_up(i,\
    \ i);\n      helper[pre(i)] = i;\n    }\n    if (t == vtype::LOWER) {\n      auto\
    \ [L, R] = ST.split_max_right(S, [&](int k) -> bool { return comp(k, point[i]);\
    \ });\n      int j = ST.get(R, 0);\n      S = ST.merge(L, R);\n      fix_up(i,\
    \ j);\n      helper[j] = i;\n    }\n  }\n  G.build();\n  vc<tuple<int, int, int>>\
    \ ANS;\n  FOR(f, 1, G.NF) {\n    auto [vs, es] = G.get_face_data(f);\n    POP(vs);\n\
    \    vc<P> sub = rearrange(point, vs);\n    for (auto& [a, b, c]: monotone_polygon_triangulation(sub))\
    \ ANS.eb(vs[a], vs[b], vs[c]);\n  }\n  return ANS;\n}\n"
  code: "#include \"geo/base.hpp\"\n#include \"ds/splaytree/splaytree_basic.hpp\"\n\
    #include \"graph/planar_graph.hpp\"\n\ntemplate <typename T>\nvc<tuple<int, int,\
    \ int>> monotone_polygon_triangulation(vc<Point<T>> point) {\n  int N = len(point);\n\
    \  int rot = min_element(all(point)) - point.begin();\n  rotate(point.begin(),\
    \ point.begin() + rot, point.end());\n  int n = max_element(all(point)) - point.begin();\n\
    \  FOR(i, n) assert(point[i] < point[i + 1]);\n  FOR(i, n, N) assert(point[(i\
    \ + 1) % N] < point[i]);\n  vc<tuple<int, int, int>> res;\n  auto side = [&](int\
    \ i) -> int {\n    assert(i != 0 && i != n);\n    return (i < n ? 0 : 1);\n  };\n\
    \  vc<int> I = argsort(point);\n  vc<int> stack = {I[0], I[1]};\n  int s = side(I[1]);\n\
    \  FOR(i, 2, N - 1) {\n    int v = I[i], t = side(v);\n    if (s == 0 && t ==\
    \ 0) {\n      while (len(stack) >= 2 && ccw(point[stack[len(stack) - 2]], point[stack[len(stack)\
    \ - 1]], point[v]) == 1) {\n        res.eb(stack[len(stack) - 2], stack[len(stack)\
    \ - 1], v), POP(stack);\n      }\n      stack.eb(v);\n    }\n    elif (s == 1\
    \ && t == 1) {\n      while (len(stack) >= 2 && ccw(point[stack[len(stack) - 2]],\
    \ point[stack[len(stack) - 1]], point[v]) == -1) {\n        res.eb(stack[len(stack)\
    \ - 2], v, stack[len(stack) - 1]), POP(stack);\n      }\n      stack.eb(v);\n\
    \    }\n    elif (s == 0 && t == 1) {\n      FOR(j, len(stack) - 1) res.eb(stack[j],\
    \ stack[j + 1], v);\n      stack = {stack.back(), v}, s = t;\n    }\n    elif\
    \ (s == 1 && t == 0) {\n      FOR(j, len(stack) - 1) res.eb(stack[j], v, stack[j\
    \ + 1]);\n      stack = {stack.back(), v}, s = t;\n    }\n  }\n  if (s == 0) {\
    \ FOR(j, len(stack) - 1) res.eb(stack[j], stack[j + 1], n); }\n  elif (s == 1)\
    \ { FOR(j, len(stack) - 1) res.eb(stack[j], n, stack[j + 1]); }\n  for (auto&\
    \ [a, b, c]: res) a = (a + rot) % N, b = (b + rot) % N, c = (c + rot) % N;\n \
    \ return res;\n}\n\n// (i,j,k), ccw\ntemplate <typename T>\nvc<tuple<int, int,\
    \ int>> polygon_triangulation(vc<Point<T>> point) {\n  using P = Point<T>;\n \
    \ int N = len(point);\n  enum vtype { MERGE, SPLIT, START, END, UPPER, LOWER };\n\
    \  auto pre = [&](int i) -> int { return (i > 0 ? i - 1 : N - 1); };\n  auto nxt\
    \ = [&](int i) -> int { return (i < N - 1 ? i + 1 : 0); };\n  auto get_vtype =\
    \ [&](int i) -> vtype {\n    int l = pre(i), r = nxt(i);\n    if (point[i] < point[l]\
    \ && point[i] < point[r]) { return (ccw(point[l], point[i], point[r]) == 1 ? START\
    \ : SPLIT); }\n    if (point[l] < point[i] && point[r] < point[i]) { return (ccw(point[l],\
    \ point[i], point[r]) == 1 ? END : MERGE); }\n    if (point[l] < point[i] && point[i]\
    \ < point[r]) return LOWER;\n    if (point[r] < point[i] && point[i] < point[l])\
    \ return UPPER;\n    assert(0);\n    return END;\n  };\n  SplayTree_Basic<int>\
    \ ST(N);\n  using np = decltype(ST)::np;\n  vc<np> nodes(N);\n  FOR(i, N) nodes[i]\
    \ = ST.new_node(i);\n  np S = ST.new_root();\n  auto comp = [&](int i, P p) ->\
    \ bool {\n    P A = point[i], B = point[nxt(i)];\n    return ccw(A, B, p) == -1;\n\
    \  };\n\n  vc<int> helper(N, -1);\n  vc<bool> merged(N);\n\n  Planar_Graph<T>\
    \ G(N, point);\n  FOR(i, N) G.add(i, nxt(i));\n\n  auto add_edge = [&](int v,\
    \ int w) -> void { merged[w] = 1, G.add(v, w); };\n\n  auto fix_up = [&](int v,\
    \ int e) -> void {\n    int w = helper[e];\n    if (get_vtype(w) == vtype::MERGE\
    \ && !merged[w]) { add_edge(v, w); }\n  };\n  auto I = argsort(point);\n  for\
    \ (auto& i: I) {\n    vtype t = get_vtype(i);\n    if (t == vtype::MERGE) {\n\
    \      ST.splay(nodes[i], 1), S = nodes[i];\n      int n = (nodes[i]->l ? nodes[i]->l->size\
    \ : 0);\n      auto [L, M, R] = ST.split3(S, n, n + 1);\n      int j = ST.get(R,\
    \ 0);\n      S = ST.merge(L, R);\n      fix_up(i, i), fix_up(i, j);\n      helper[j]\
    \ = i;\n    }\n    if (t == vtype::SPLIT) {\n      auto [L, R] = ST.split_max_right(S,\
    \ [&](int k) -> bool { return comp(k, point[i]); });\n      int j = ST.get(R,\
    \ 0);\n      add_edge(i, helper[j]);\n      helper[j] = i, helper[pre(i)] = i;\n\
    \      S = ST.merge3(L, nodes[pre(i)], R);\n    }\n    if (t == vtype::START)\
    \ {\n      auto [L, R] = ST.split_max_right(S, [&](int k) -> bool { return comp(k,\
    \ point[i]); });\n      S = ST.merge3(L, nodes[pre(i)], R), helper[pre(i)] = i;\n\
    \    }\n    if (t == vtype::END) {\n      ST.splay(nodes[i], 1), S = nodes[i];\n\
    \      int n = (nodes[i]->l ? nodes[i]->l->size : 0);\n      auto [L, M, R] =\
    \ ST.split3(S, n, n + 1);\n      S = ST.merge(L, R);\n      fix_up(i, i);\n  \
    \  }\n    if (t == vtype::UPPER) {\n      ST.splay(nodes[i], 1), S = nodes[i];\n\
    \      int n = (nodes[i]->l ? nodes[i]->l->size : 0);\n      auto [L, M, R] =\
    \ ST.split3(S, n, n + 1);\n      S = ST.merge3(L, nodes[pre(i)], R);\n      fix_up(i,\
    \ i);\n      helper[pre(i)] = i;\n    }\n    if (t == vtype::LOWER) {\n      auto\
    \ [L, R] = ST.split_max_right(S, [&](int k) -> bool { return comp(k, point[i]);\
    \ });\n      int j = ST.get(R, 0);\n      S = ST.merge(L, R);\n      fix_up(i,\
    \ j);\n      helper[j] = i;\n    }\n  }\n  G.build();\n  vc<tuple<int, int, int>>\
    \ ANS;\n  FOR(f, 1, G.NF) {\n    auto [vs, es] = G.get_face_data(f);\n    POP(vs);\n\
    \    vc<P> sub = rearrange(point, vs);\n    for (auto& [a, b, c]: monotone_polygon_triangulation(sub))\
    \ ANS.eb(vs[a], vs[b], vs[c]);\n  }\n  return ANS;\n}"
  dependsOn:
  - geo/base.hpp
  - ds/splaytree/splaytree_basic.hpp
  - ds/splaytree/splaytree.hpp
  - graph/planar_graph.hpp
  - graph/base.hpp
  - ds/hashmap.hpp
  - geo/angle_sort.hpp
  isVerificationFile: false
  path: geo/polygon_triangulation.hpp
  requiredBy: []
  timestamp: '2024-12-25 20:50:37+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/1_mytest/polygon_triangulation.test.cpp
documentation_of: geo/polygon_triangulation.hpp
layout: document
redirect_from:
- /library/geo/polygon_triangulation.hpp
- /library/geo/polygon_triangulation.hpp.html
title: geo/polygon_triangulation.hpp
---
