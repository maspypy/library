---
data:
  _extendedDependsOn:
  - icon: ':question:'
    path: alg/monoid/add.hpp
    title: alg/monoid/add.hpp
  - icon: ':question:'
    path: ds/fenwick/fenwick.hpp
    title: ds/fenwick/fenwick.hpp
  - icon: ':heavy_check_mark:'
    path: ds/offline_query/point_add_rectangle_sum.hpp
    title: ds/offline_query/point_add_rectangle_sum.hpp
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/library_checker/datastructure/static_rectangle_add_rectangle_sum.test.cpp
    title: test/library_checker/datastructure/static_rectangle_add_rectangle_sum.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/yukicoder/1490.test.cpp
    title: test/yukicoder/1490.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 2 \"ds/offline_query/rectangle_add_rectangle_sum.hpp\"\n\n#line\
    \ 2 \"alg/monoid/add.hpp\"\n\r\ntemplate <typename X>\r\nstruct Monoid_Add {\r\
    \n  using value_type = X;\r\n  static constexpr X op(const X &x, const X &y) noexcept\
    \ { return x + y; }\r\n  static constexpr X inverse(const X &x) noexcept { return\
    \ -x; }\r\n  static constexpr X power(const X &x, ll n) noexcept { return X(n)\
    \ * x; }\r\n  static constexpr X unit() { return X(0); }\r\n  static constexpr\
    \ bool commute = true;\r\n};\r\n#line 3 \"ds/fenwick/fenwick.hpp\"\n\ntemplate\
    \ <typename AbelGroup>\nstruct FenwickTree {\n  using E = typename AbelGroup::value_type;\n\
    \  int n;\n  vector<E> dat;\n  E total;\n\n  FenwickTree(int n = 0) : n(n) {\n\
    \    assert(AbelGroup::commute);\n    reset(n);\n  }\n  FenwickTree(const vector<E>&\
    \ v) {\n    assert(AbelGroup::commute);\n    build(v);\n  }\n\n  void build(const\
    \ vc<E>& v) {\n    n = len(v);\n    total = AbelGroup::unit();\n    for (int i\
    \ = 0; i < n; ++i) total = AbelGroup::op(total, v[i]);\n    dat = v;\n    for\
    \ (int i = 1; i <= n; ++i) {\n      int j = i + (i & -i);\n      if (j <= n) dat[j\
    \ - 1] = AbelGroup::op(dat[i - 1], dat[j - 1]);\n    }\n  }\n\n  void reset(int\
    \ sz = 0) {\n    if (sz) n = sz;\n    total = AbelGroup::unit();\n    dat.assign(n,\
    \ AbelGroup::unit());\n  }\n\n  E prod(int k) {\n    E ret = AbelGroup::unit();\n\
    \    for (; k > 0; k -= k & -k) ret = AbelGroup::op(ret, dat[k - 1]);\n    return\
    \ ret;\n  }\n\n  E prod(int L, int R) {\n    E pos = AbelGroup::unit();\n    while\
    \ (L < R) {\n      pos = AbelGroup::op(pos, dat[R - 1]);\n      R -= R & -R;\n\
    \    }\n    E neg = AbelGroup::unit();\n    while (R < L) {\n      neg = AbelGroup::op(neg,\
    \ dat[L - 1]);\n      L -= L & -L;\n    }\n    return AbelGroup::op(pos, AbelGroup::inverse(neg));\n\
    \  }\n\n  E prod_all() { return total; }\n\n  E sum(int k) { return prod(k); }\n\
    \n  E sum(int L, int R) { return prod(L, R); }\n\n  E sum_all() { return total;\
    \ }\n\n  void multiply(int k, E x) {\n    total = AbelGroup::op(total, x);\n \
    \   for (++k; k <= n; k += k & -k) dat[k - 1] = AbelGroup::op(dat[k - 1], x);\n\
    \  }\n\n  void add(int k, E x) { multiply(k, x); }\n\n  template <class F>\n \
    \ int max_right(F& check) {\n    assert(check(E(0)));\n    ll i = 0;\n    E s\
    \ = AbelGroup::unit();\n    int k = 1;\n    int N = dat.size() + 1;\n    while\
    \ (2 * k < N) k *= 2;\n    while (k) {\n      if (i + k < N && check(AbelGroup::op(s,\
    \ dat[i + k - 1]))) {\n        i += k;\n        s = AbelGroup::op(s, dat[i - 1]);\n\
    \      }\n      k >>= 1;\n    }\n    return i;\n  }\n\n  int find_kth(E k) {\n\
    \    auto check = [&](E x) -> bool { return x <= k; };\n    return max_right(check);\n\
    \  }\n\n  void debug() { print(\"fenwick\", dat); }\n};\n#line 2 \"ds/offline_query/point_add_rectangle_sum.hpp\"\
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
    \ - 1;\r\n      }\r\n      keyX.shrink_to_fit();\r\n      for (auto &&[xl, xr,\
    \ yl, yr]: rect) {\r\n        xl = LB(keyX, xl);\r\n        xr = LB(keyX, xr);\r\
    \n      }\r\n      NX = len(keyX);\r\n    }\r\n    if (SMALL_X) {\r\n      XY\
    \ mx = numeric_limits<XY>::max();\r\n      for (auto &&[x, y, g]: point) chmin(mx,\
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
    \ g);\r\n    }\r\n    return res;\r\n  }\r\n};\n#line 4 \"ds/offline_query/rectangle_add_rectangle_sum.hpp\"\
    \n\ntemplate <typename AbelGroup, typename XY, bool SMALL_X = false>\nstruct Rectangle_Add_Rectangle_Sum\
    \ {\n  using WT = typename AbelGroup::value_type;\n  using WT4 = tuple<WT, WT,\
    \ WT, WT>;\n\n  struct G {\n    using X = WT4;\n    using value_type = X;\n  \
    \  static X op(const X &x, const X &y) {\n      auto &[ax, bx, cx, dx] = x;\n\
    \      auto &[ay, by, cy, dy] = y;\n      return {AbelGroup::op(ax, ay), AbelGroup::op(bx,\
    \ by),\n              AbelGroup::op(cx, cy), AbelGroup::op(dx, dy)};\n    }\n\
    \    static X inverse(const X &x) {\n      auto &[ax, bx, cx, dx] = x;\n     \
    \ return {AbelGroup::inverse(ax), AbelGroup::inverse(bx),\n              AbelGroup::inverse(cx),\
    \ AbelGroup::inverse(dx)};\n    }\n    static X power(const X &x, ll n) {\n  \
    \    auto &[ax, bx, cx, dx] = x;\n      return {AbelGroup::power(ax, n), AbelGroup::power(bx,\
    \ n),\n              AbelGroup::power(cx, n), AbelGroup::power(dx, n)};\n    }\n\
    \    static constexpr X unit() {\n      auto u = AbelGroup::unit();\n      return\
    \ {u, u, u, u};\n    }\n    static constexpr bool commute = true;\n  };\n\n  vector<tuple<XY,\
    \ XY, XY, XY>> query;\n  Point_Add_Rectangle_Sum<G, XY, SMALL_X> X;\n  XY min_x\
    \ = 0, min_y = 0;\n\n  void add_query(XY xl, XY xr, XY yl, XY yr, WT w) {\n  \
    \  assert(xl <= xr && yl <= yr);\n    min_x = min(min_x, xl);\n    min_y = min(min_y,\
    \ yl);\n    // (xl,yl) \u306B (x-xl)(y-yl) \u3092\u52A0\u7B97\n    auto nw = AbelGroup::inverse(w);\n\
    \    X.add_query(xl, yl,\n                {w, AbelGroup::power(w, -yl), AbelGroup::power(w,\
    \ -xl),\n                 AbelGroup::power(w, +ll(xl) * yl)});\n    // (xl,yr)\
    \ \u306B (x-xl)(y-yr) \u3092\u6E1B\u7B97\n    X.add_query(xl, yr,\n          \
    \      {nw, AbelGroup::power(w, +yr), AbelGroup::power(w, +xl),\n            \
    \     AbelGroup::power(w, -ll(xl) * yr)});\n    // (xr,yl) \u306B (x-xr)(y-yl)\
    \ \u3092\u6E1B\u7B97\n    X.add_query(xr, yl,\n                {nw, AbelGroup::power(w,\
    \ +yl), AbelGroup::power(w, +xr),\n                 AbelGroup::power(w, -ll(xr)\
    \ * yl)});\n    // (xr,yr) \u306B (x-xr)(y-yr) \u3092\u52A0\u7B97\n    X.add_query(xr,\
    \ yr,\n                {w, AbelGroup::power(w, -yr), AbelGroup::power(w, -xr),\n\
    \                 AbelGroup::power(w, +ll(xr) * yr)});\n  }\n\n  void sum_query(XY\
    \ xl, XY xr, XY yl, XY yr) {\n    assert(xl <= xr && yl <= yr);\n    query.emplace_back(xl,\
    \ xr, yl, yr);\n    X.sum_query(min_x, xl, min_y, yl);\n    X.sum_query(min_x,\
    \ xl, min_y, yr);\n    X.sum_query(min_x, xr, min_y, yl);\n    X.sum_query(min_x,\
    \ xr, min_y, yr);\n  }\n\n  vector<WT> calc() {\n    int Q = query.size();\n \
    \   vector<WT> ANS(Q);\n    auto tmp = X.calc();\n\n    for (int q = 0; q < Q;\
    \ ++q) {\n      auto [xl, xr, yl, yr] = query[q];\n      WT p = AbelGroup::unit(),\
    \ m = AbelGroup::unit();\n      {\n        auto [a, b, c, d] = tmp[4 * q + 0];\n\
    \        p = AbelGroup::op(p, AbelGroup::power(a, ll(xl) * yl));\n        p =\
    \ AbelGroup::op(p, AbelGroup::power(b, xl));\n        p = AbelGroup::op(p, AbelGroup::power(c,\
    \ yl));\n        p = AbelGroup::op(p, d);\n      }\n      {\n        auto [a,\
    \ b, c, d] = tmp[4 * q + 1];\n        m = AbelGroup::op(m, AbelGroup::power(a,\
    \ ll(xl) * yr));\n        m = AbelGroup::op(m, AbelGroup::power(b, xl));\n   \
    \     m = AbelGroup::op(m, AbelGroup::power(c, yr));\n        m = AbelGroup::op(m,\
    \ d);\n      }\n      {\n        auto [a, b, c, d] = tmp[4 * q + 2];\n       \
    \ m = AbelGroup::op(m, AbelGroup::power(a, ll(xr) * yl));\n        m = AbelGroup::op(m,\
    \ AbelGroup::power(b, xr));\n        m = AbelGroup::op(m, AbelGroup::power(c,\
    \ yl));\n        m = AbelGroup::op(m, d);\n      }\n      {\n        auto [a,\
    \ b, c, d] = tmp[4 * q + 3];\n        p = AbelGroup::op(p, AbelGroup::power(a,\
    \ ll(xr) * yr));\n        p = AbelGroup::op(p, AbelGroup::power(b, xr));\n   \
    \     p = AbelGroup::op(p, AbelGroup::power(c, yr));\n        p = AbelGroup::op(p,\
    \ d);\n      }\n      ANS[q] = AbelGroup::op(p, AbelGroup::inverse(m));\n    }\n\
    \    return ANS;\n  }\n};\n"
  code: "#pragma once\n\n#include \"ds/offline_query/point_add_rectangle_sum.hpp\"\
    \n\ntemplate <typename AbelGroup, typename XY, bool SMALL_X = false>\nstruct Rectangle_Add_Rectangle_Sum\
    \ {\n  using WT = typename AbelGroup::value_type;\n  using WT4 = tuple<WT, WT,\
    \ WT, WT>;\n\n  struct G {\n    using X = WT4;\n    using value_type = X;\n  \
    \  static X op(const X &x, const X &y) {\n      auto &[ax, bx, cx, dx] = x;\n\
    \      auto &[ay, by, cy, dy] = y;\n      return {AbelGroup::op(ax, ay), AbelGroup::op(bx,\
    \ by),\n              AbelGroup::op(cx, cy), AbelGroup::op(dx, dy)};\n    }\n\
    \    static X inverse(const X &x) {\n      auto &[ax, bx, cx, dx] = x;\n     \
    \ return {AbelGroup::inverse(ax), AbelGroup::inverse(bx),\n              AbelGroup::inverse(cx),\
    \ AbelGroup::inverse(dx)};\n    }\n    static X power(const X &x, ll n) {\n  \
    \    auto &[ax, bx, cx, dx] = x;\n      return {AbelGroup::power(ax, n), AbelGroup::power(bx,\
    \ n),\n              AbelGroup::power(cx, n), AbelGroup::power(dx, n)};\n    }\n\
    \    static constexpr X unit() {\n      auto u = AbelGroup::unit();\n      return\
    \ {u, u, u, u};\n    }\n    static constexpr bool commute = true;\n  };\n\n  vector<tuple<XY,\
    \ XY, XY, XY>> query;\n  Point_Add_Rectangle_Sum<G, XY, SMALL_X> X;\n  XY min_x\
    \ = 0, min_y = 0;\n\n  void add_query(XY xl, XY xr, XY yl, XY yr, WT w) {\n  \
    \  assert(xl <= xr && yl <= yr);\n    min_x = min(min_x, xl);\n    min_y = min(min_y,\
    \ yl);\n    // (xl,yl) \u306B (x-xl)(y-yl) \u3092\u52A0\u7B97\n    auto nw = AbelGroup::inverse(w);\n\
    \    X.add_query(xl, yl,\n                {w, AbelGroup::power(w, -yl), AbelGroup::power(w,\
    \ -xl),\n                 AbelGroup::power(w, +ll(xl) * yl)});\n    // (xl,yr)\
    \ \u306B (x-xl)(y-yr) \u3092\u6E1B\u7B97\n    X.add_query(xl, yr,\n          \
    \      {nw, AbelGroup::power(w, +yr), AbelGroup::power(w, +xl),\n            \
    \     AbelGroup::power(w, -ll(xl) * yr)});\n    // (xr,yl) \u306B (x-xr)(y-yl)\
    \ \u3092\u6E1B\u7B97\n    X.add_query(xr, yl,\n                {nw, AbelGroup::power(w,\
    \ +yl), AbelGroup::power(w, +xr),\n                 AbelGroup::power(w, -ll(xr)\
    \ * yl)});\n    // (xr,yr) \u306B (x-xr)(y-yr) \u3092\u52A0\u7B97\n    X.add_query(xr,\
    \ yr,\n                {w, AbelGroup::power(w, -yr), AbelGroup::power(w, -xr),\n\
    \                 AbelGroup::power(w, +ll(xr) * yr)});\n  }\n\n  void sum_query(XY\
    \ xl, XY xr, XY yl, XY yr) {\n    assert(xl <= xr && yl <= yr);\n    query.emplace_back(xl,\
    \ xr, yl, yr);\n    X.sum_query(min_x, xl, min_y, yl);\n    X.sum_query(min_x,\
    \ xl, min_y, yr);\n    X.sum_query(min_x, xr, min_y, yl);\n    X.sum_query(min_x,\
    \ xr, min_y, yr);\n  }\n\n  vector<WT> calc() {\n    int Q = query.size();\n \
    \   vector<WT> ANS(Q);\n    auto tmp = X.calc();\n\n    for (int q = 0; q < Q;\
    \ ++q) {\n      auto [xl, xr, yl, yr] = query[q];\n      WT p = AbelGroup::unit(),\
    \ m = AbelGroup::unit();\n      {\n        auto [a, b, c, d] = tmp[4 * q + 0];\n\
    \        p = AbelGroup::op(p, AbelGroup::power(a, ll(xl) * yl));\n        p =\
    \ AbelGroup::op(p, AbelGroup::power(b, xl));\n        p = AbelGroup::op(p, AbelGroup::power(c,\
    \ yl));\n        p = AbelGroup::op(p, d);\n      }\n      {\n        auto [a,\
    \ b, c, d] = tmp[4 * q + 1];\n        m = AbelGroup::op(m, AbelGroup::power(a,\
    \ ll(xl) * yr));\n        m = AbelGroup::op(m, AbelGroup::power(b, xl));\n   \
    \     m = AbelGroup::op(m, AbelGroup::power(c, yr));\n        m = AbelGroup::op(m,\
    \ d);\n      }\n      {\n        auto [a, b, c, d] = tmp[4 * q + 2];\n       \
    \ m = AbelGroup::op(m, AbelGroup::power(a, ll(xr) * yl));\n        m = AbelGroup::op(m,\
    \ AbelGroup::power(b, xr));\n        m = AbelGroup::op(m, AbelGroup::power(c,\
    \ yl));\n        m = AbelGroup::op(m, d);\n      }\n      {\n        auto [a,\
    \ b, c, d] = tmp[4 * q + 3];\n        p = AbelGroup::op(p, AbelGroup::power(a,\
    \ ll(xr) * yr));\n        p = AbelGroup::op(p, AbelGroup::power(b, xr));\n   \
    \     p = AbelGroup::op(p, AbelGroup::power(c, yr));\n        p = AbelGroup::op(p,\
    \ d);\n      }\n      ANS[q] = AbelGroup::op(p, AbelGroup::inverse(m));\n    }\n\
    \    return ANS;\n  }\n};\n"
  dependsOn:
  - ds/offline_query/point_add_rectangle_sum.hpp
  - ds/fenwick/fenwick.hpp
  - alg/monoid/add.hpp
  isVerificationFile: false
  path: ds/offline_query/rectangle_add_rectangle_sum.hpp
  requiredBy: []
  timestamp: '2022-12-02 06:10:25+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/yukicoder/1490.test.cpp
  - test/library_checker/datastructure/static_rectangle_add_rectangle_sum.test.cpp
documentation_of: ds/offline_query/rectangle_add_rectangle_sum.hpp
layout: document
redirect_from:
- /library/ds/offline_query/rectangle_add_rectangle_sum.hpp
- /library/ds/offline_query/rectangle_add_rectangle_sum.hpp.html
title: ds/offline_query/rectangle_add_rectangle_sum.hpp
---
