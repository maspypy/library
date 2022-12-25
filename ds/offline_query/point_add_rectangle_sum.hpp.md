---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: alg/monoid/add.hpp
    title: alg/monoid/add.hpp
  - icon: ':heavy_check_mark:'
    path: ds/fenwicktree/fenwicktree.hpp
    title: ds/fenwicktree/fenwicktree.hpp
  _extendedRequiredBy:
  - icon: ':heavy_check_mark:'
    path: ds/offline_query/rectangle_add_rectangle_sum.hpp
    title: ds/offline_query/rectangle_add_rectangle_sum.hpp
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/library_checker/datastructure/rectangle_sum_sweep.test.cpp
    title: test/library_checker/datastructure/rectangle_sum_sweep.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/library_checker/datastructure/static_rectangle_add_rectangle_sum.test.cpp
    title: test/library_checker/datastructure/static_rectangle_add_rectangle_sum.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/yukicoder/1490.test.cpp
    title: test/yukicoder/1490.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/yukicoder/2161.test.cpp
    title: test/yukicoder/2161.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 2 \"alg/monoid/add.hpp\"\n\r\ntemplate <typename X>\r\nstruct\
    \ Monoid_Add {\r\n  using value_type = X;\r\n  static constexpr X op(const X &x,\
    \ const X &y) noexcept { return x + y; }\r\n  static constexpr X inverse(const\
    \ X &x) noexcept { return -x; }\r\n  static constexpr X power(const X &x, ll n)\
    \ noexcept { return X(n) * x; }\r\n  static constexpr X unit() { return X(0);\
    \ }\r\n  static constexpr bool commute = true;\r\n};\r\n#line 3 \"ds/fenwicktree/fenwicktree.hpp\"\
    \n\ntemplate <typename Monoid>\nstruct FenwickTree {\n  using G = Monoid;\n  using\
    \ E = typename G::value_type;\n  int n;\n  vector<E> dat;\n  E total;\n\n  FenwickTree()\
    \ {}\n  FenwickTree(int n) { build(n); }\n  template <typename F>\n  FenwickTree(int\
    \ n, F f) {\n    build(n, f);\n  }\n  FenwickTree(const vc<E>& v) { build(v);\
    \ }\n\n  void build(int m) {\n    n = m;\n    dat.assign(m, G::unit());\n    total\
    \ = G::unit();\n  }\n  void build(const vc<E>& v) {\n    build(len(v), [&](int\
    \ i) -> E { return v[i]; });\n  }\n  template <typename F>\n  void build(int m,\
    \ F f) {\n    n = m;\n    dat.clear();\n    dat.reserve(n);\n    total = G::unit();\n\
    \    FOR(i, n) { dat.eb(f(i)); }\n    for (int i = 1; i <= n; ++i) {\n      int\
    \ j = i + (i & -i);\n      if (j <= n) dat[j - 1] = G::op(dat[i - 1], dat[j -\
    \ 1]);\n    }\n    total = prefix_sum(m);\n  }\n\n  E prod_all() { return total;\
    \ }\n  E sum_all() { return total; }\n  E sum(int k) { return prefix_sum(k); }\n\
    \  E prod(int k) { return prefix_prod(k); }\n  E prefix_sum(int k) { return prefix_prod(k);\
    \ }\n  E prefix_prod(int k) {\n    E ret = G::unit();\n    for (; k > 0; k -=\
    \ k & -k) ret = G::op(ret, dat[k - 1]);\n    return ret;\n  }\n  E sum(int L,\
    \ int R) { return prod(L, R); }\n  E prod(int L, int R) {\n    if (L == 0) return\
    \ prefix_prod(R);\n    assert(0 <= L && L <= R && R <= n);\n    E pos = G::unit(),\
    \ neg = G::unit();\n    while (L < R) { pos = G::op(pos, dat[R - 1]), R -= R &\
    \ -R; }\n    while (R < L) { neg = G::op(neg, dat[L - 1]), L -= L & -L; }\n  \
    \  return G::op(pos, G::inverse(neg));\n  }\n\n  void add(int k, E x) { multiply(k,\
    \ x); }\n  void multiply(int k, E x) {\n    static_assert(G::commute);\n    total\
    \ = G::op(total, x);\n    for (++k; k <= n; k += k & -k) dat[k - 1] = G::op(dat[k\
    \ - 1], x);\n  }\n\n  template <class F>\n  int max_right(const F check) {\n \
    \   assert(check(G::unit()));\n    int i = 0;\n    E s = G::unit();\n    int k\
    \ = 1;\n    while (2 * k <= n) k *= 2;\n    while (k) {\n      E t = G::op(s,\
    \ dat[i + k - 1]);\n      if (check(t)) { i += k, s = t; }\n      k >>= 1;\n \
    \   }\n    return i;\n  }\n\n  int kth(E k) {\n    return max_right([&k](E x)\
    \ -> bool { return x <= k; });\n  }\n};\n#line 2 \"ds/offline_query/point_add_rectangle_sum.hpp\"\
    \n\r\ntemplate <typename AbelGroup, typename XY, bool SMALL_X = false>\r\nstruct\
    \ Point_Add_Rectangle_Sum {\r\n  using G = typename AbelGroup::value_type;\r\n\
    \  using Point = tuple<XY, XY, G>;\r\n  vector<Point> point;\r\n  vector<tuple<XY,\
    \ XY, XY, XY>> rect;\r\n\r\n  Point_Add_Rectangle_Sum() {}\r\n\r\n  void add_query(XY\
    \ x, XY y, G w) { point.eb(x, y, w); }\r\n  void sum_query(XY xl, XY xr, XY yl,\
    \ XY yr) { rect.eb(xl, xr, yl, yr); }\r\n\r\n  vector<G> calc() {\r\n    int N\
    \ = point.size(), Q = rect.size();\r\n    if (N == 0 || Q == 0) return vector<G>(Q,\
    \ AbelGroup::unit());\r\n    // X \u65B9\u5411\u306E\u5EA7\u5727\r\n    int NX\
    \ = 0;\r\n    if (!SMALL_X) {\r\n      sort(all(point),\r\n           [&](auto\
    \ &x, auto &y) -> bool { return get<0>(x) < get<0>(y); });\r\n      vc<XY> keyX;\r\
    \n      keyX.reserve(N);\r\n      for (auto &&[a, b, c]: point) {\r\n        if\
    \ (len(keyX) == 0 || keyX.back() != a) { keyX.eb(a); }\r\n        a = len(keyX)\
    \ - 1;\r\n      }\r\n      for (auto &&[xl, xr, yl, yr]: rect) {\r\n        xl\
    \ = LB(keyX, xl);\r\n        xr = LB(keyX, xr);\r\n      }\r\n      NX = len(keyX);\r\
    \n    }\r\n    if (SMALL_X) {\r\n      XY mx = numeric_limits<XY>::max();\r\n\
    \      for (auto &&[x, y, g]: point) chmin(mx, x);\r\n      for (auto &&[x, y,\
    \ g]: point) x -= mx, chmax(NX, x + 1);\r\n      for (auto &&[xl, xr, yl, yr]:\
    \ rect) {\r\n        xl -= mx, xr -= mx;\r\n        xl = max(0, min<int>(xl, NX));\r\
    \n        xr = max(0, min<int>(xr, NX));\r\n      }\r\n    }\r\n\r\n    vc<tuple<XY,\
    \ int, int, int>> event(Q + Q);\r\n    FOR(q, Q) {\r\n      auto &[xl, xr, yl,\
    \ yr] = rect[q];\r\n      event[2 * q] = {yl, xl, xr, 2 * q};\r\n      event[2\
    \ * q + 1] = {yr, xl, xr, 2 * q + 1};\r\n    }\r\n    sort(all(point),\r\n   \
    \      [&](auto &x, auto &y) -> bool { return get<1>(x) < get<1>(y); });\r\n \
    \   sort(all(event),\r\n         [&](auto &x, auto &y) -> bool { return get<0>(x)\
    \ < get<0>(y); });\r\n\r\n    FenwickTree<AbelGroup> bit(NX);\r\n    vc<G> res(Q,\
    \ AbelGroup::unit());\r\n    int j = 0;\r\n    for (auto &&[y, xl, xr, qq]: event)\
    \ {\r\n      while (j < N && get<1>(point[j]) < y) {\r\n        bit.add(get<0>(point[j]),\
    \ get<2>(point[j]));\r\n        ++j;\r\n      }\r\n      G g = bit.sum(xl, xr);\r\
    \n      int q = qq / 2;\r\n      if (qq % 2 == 0) g = AbelGroup::inverse(g);\r\
    \n      res[q] = AbelGroup::op(res[q], g);\r\n    }\r\n    return res;\r\n  }\r\
    \n};\n"
  code: "#include \"ds/fenwicktree/fenwicktree.hpp\"\r\n\r\ntemplate <typename AbelGroup,\
    \ typename XY, bool SMALL_X = false>\r\nstruct Point_Add_Rectangle_Sum {\r\n \
    \ using G = typename AbelGroup::value_type;\r\n  using Point = tuple<XY, XY, G>;\r\
    \n  vector<Point> point;\r\n  vector<tuple<XY, XY, XY, XY>> rect;\r\n\r\n  Point_Add_Rectangle_Sum()\
    \ {}\r\n\r\n  void add_query(XY x, XY y, G w) { point.eb(x, y, w); }\r\n  void\
    \ sum_query(XY xl, XY xr, XY yl, XY yr) { rect.eb(xl, xr, yl, yr); }\r\n\r\n \
    \ vector<G> calc() {\r\n    int N = point.size(), Q = rect.size();\r\n    if (N\
    \ == 0 || Q == 0) return vector<G>(Q, AbelGroup::unit());\r\n    // X \u65B9\u5411\
    \u306E\u5EA7\u5727\r\n    int NX = 0;\r\n    if (!SMALL_X) {\r\n      sort(all(point),\r\
    \n           [&](auto &x, auto &y) -> bool { return get<0>(x) < get<0>(y); });\r\
    \n      vc<XY> keyX;\r\n      keyX.reserve(N);\r\n      for (auto &&[a, b, c]:\
    \ point) {\r\n        if (len(keyX) == 0 || keyX.back() != a) { keyX.eb(a); }\r\
    \n        a = len(keyX) - 1;\r\n      }\r\n      for (auto &&[xl, xr, yl, yr]:\
    \ rect) {\r\n        xl = LB(keyX, xl);\r\n        xr = LB(keyX, xr);\r\n    \
    \  }\r\n      NX = len(keyX);\r\n    }\r\n    if (SMALL_X) {\r\n      XY mx =\
    \ numeric_limits<XY>::max();\r\n      for (auto &&[x, y, g]: point) chmin(mx,\
    \ x);\r\n      for (auto &&[x, y, g]: point) x -= mx, chmax(NX, x + 1);\r\n  \
    \    for (auto &&[xl, xr, yl, yr]: rect) {\r\n        xl -= mx, xr -= mx;\r\n\
    \        xl = max(0, min<int>(xl, NX));\r\n        xr = max(0, min<int>(xr, NX));\r\
    \n      }\r\n    }\r\n\r\n    vc<tuple<XY, int, int, int>> event(Q + Q);\r\n \
    \   FOR(q, Q) {\r\n      auto &[xl, xr, yl, yr] = rect[q];\r\n      event[2 *\
    \ q] = {yl, xl, xr, 2 * q};\r\n      event[2 * q + 1] = {yr, xl, xr, 2 * q + 1};\r\
    \n    }\r\n    sort(all(point),\r\n         [&](auto &x, auto &y) -> bool { return\
    \ get<1>(x) < get<1>(y); });\r\n    sort(all(event),\r\n         [&](auto &x,\
    \ auto &y) -> bool { return get<0>(x) < get<0>(y); });\r\n\r\n    FenwickTree<AbelGroup>\
    \ bit(NX);\r\n    vc<G> res(Q, AbelGroup::unit());\r\n    int j = 0;\r\n    for\
    \ (auto &&[y, xl, xr, qq]: event) {\r\n      while (j < N && get<1>(point[j])\
    \ < y) {\r\n        bit.add(get<0>(point[j]), get<2>(point[j]));\r\n        ++j;\r\
    \n      }\r\n      G g = bit.sum(xl, xr);\r\n      int q = qq / 2;\r\n      if\
    \ (qq % 2 == 0) g = AbelGroup::inverse(g);\r\n      res[q] = AbelGroup::op(res[q],\
    \ g);\r\n    }\r\n    return res;\r\n  }\r\n};"
  dependsOn:
  - ds/fenwicktree/fenwicktree.hpp
  - alg/monoid/add.hpp
  isVerificationFile: false
  path: ds/offline_query/point_add_rectangle_sum.hpp
  requiredBy:
  - ds/offline_query/rectangle_add_rectangle_sum.hpp
  timestamp: '2022-12-11 11:10:53+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/yukicoder/2161.test.cpp
  - test/yukicoder/1490.test.cpp
  - test/library_checker/datastructure/rectangle_sum_sweep.test.cpp
  - test/library_checker/datastructure/static_rectangle_add_rectangle_sum.test.cpp
documentation_of: ds/offline_query/point_add_rectangle_sum.hpp
layout: document
redirect_from:
- /library/ds/offline_query/point_add_rectangle_sum.hpp
- /library/ds/offline_query/point_add_rectangle_sum.hpp.html
title: ds/offline_query/point_add_rectangle_sum.hpp
---
