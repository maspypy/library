---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: alg/group_add.hpp
    title: alg/group_add.hpp
  - icon: ':heavy_check_mark:'
    path: ds/fenwick.hpp
    title: ds/fenwick.hpp
  - icon: ':heavy_check_mark:'
    path: ds/point_add_rectangle_sum.hpp
    title: ds/point_add_rectangle_sum.hpp
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/yukicoder/1490_rect_add_rect_sum.test.cpp
    title: test/yukicoder/1490_rect_add_rect_sum.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 2 \"ds/rectangle_add_ractangle_sum.hpp\"\n\n#line 2 \"alg/group_add.hpp\"\
    \ntemplate <class X>\r\nstruct Group_Add {\r\n  using value_type = X;\r\n  static\
    \ constexpr X op(const X &x, const X &y) noexcept { return x + y; }\r\n  static\
    \ constexpr X inverse(const X &x) noexcept { return -x; }\r\n  static constexpr\
    \ X power(const X &x, ll n) noexcept { return n * x; }\r\n  static constexpr X\
    \ unit() { return X(0); }\r\n  static constexpr bool commute = true;\r\n};\r\n\
    #line 3 \"ds/fenwick.hpp\"\n\ntemplate <typename AbelGroup>\nstruct FenwickTree\
    \ {\n  using E = typename AbelGroup::value_type;\n  int n;\n  vector<E> dat;\n\
    \  E total;\n\n  FenwickTree() : FenwickTree(0) {}\n  FenwickTree(int n) : n(n),\
    \ total(AbelGroup::unit()) {\n    assert(AbelGroup::commute);\n    dat.assign(n,\
    \ AbelGroup::unit());\n  }\n  FenwickTree(vc<E> v) : n(len(v)), total(AbelGroup::unit())\
    \ {\n    assert(AbelGroup::commute);\n    FOR(i, n) total = AbelGroup::op(total,\
    \ v[i]);\n    dat = v;\n    FOR3(i, 1, n + 1) {\n      int j = i + (i & -i);\n\
    \      if (j <= n) dat[j - 1] = AbelGroup::op(dat[i - 1], dat[j - 1]);\n    }\n\
    \  }\n\n  void reset(){\n    total = AbelGroup::unit();\n    dat.assign(n, AbelGroup::unit());\n\
    \  }\n\n  E sum(int k) {\n    E ret = AbelGroup::unit();\n    for (; k > 0; k\
    \ -= k & -k) ret = AbelGroup::op(ret, dat[k - 1]);\n    return ret;\n  }\n\n \
    \ E sum(int L, int R) {\n    E pos = AbelGroup::unit();\n    while (L < R) {\n\
    \      pos = AbelGroup::op(pos, dat[R - 1]);\n      R -= R & -R;\n    }\n    E\
    \ neg = AbelGroup::unit();\n    while (R < L) {\n      neg = AbelGroup::op(neg,\
    \ dat[L - 1]);\n      L -= L & -L;\n    }\n    return AbelGroup::op(pos, AbelGroup::inverse(neg));\n\
    \  }\n\n  E sum_all() { return total; }\n\n  void add(int k, E x) {\n    total\
    \ = AbelGroup::op(total, x);\n    for (++k; k <= n; k += k & -k) dat[k - 1] =\
    \ AbelGroup::op(dat[k - 1], x);\n  }\n\n  template <class F>\n  int max_right(F&\
    \ check) {\n    assert(check(E(0)));\n    ll i = 0;\n    E s = AbelGroup::unit();\n\
    \    int k = 1;\n    int N = len(dat) + 1;\n    while (2 * k < N) k *= 2;\n  \
    \  while (k) {\n      if (i + k < N && check(AbelGroup::op(s, dat[i + k - 1])))\
    \ {\n        i += k;\n        s = AbelGroup::op(s, dat[i - 1]);\n      }\n   \
    \   k >>= 1;\n    }\n    return i;\n  }\n\n  int find_kth(E k) {\n    auto check\
    \ = [&](E x) -> bool { return x <= k; };\n    return max_right(check);\n  }\n\n\
    \  void debug() { print(\"fenwick\", dat); }\n};\n#line 2 \"ds/point_add_rectangle_sum.hpp\"\
    \n\r\n// \u70B9\u7FA4\u306F\u30AF\u30A8\u30EA\u3088\u308A\u524D\u306B\u5168\u90E8\
    \u5165\u529B\u3059\u308B\u3053\u3068 (add_pt)\u3002\r\n// \u540C\u3058\u70B9\u7FA4\
    \u306B\u5BFE\u3057\u3066\u30AF\u30A8\u30EA\u3092\u3084\u308A\u76F4\u305B\u308B\
    \u3002\r\n// SMALL=true \u306B\u3059\u308B\u3068\u3001\u5EA7\u5727\u3092\u3057\
    \u306A\u3044\u305F\u3081\u5C11\u3057\u9AD8\u901F\r\ntemplate <typename AbelGroup,\
    \ bool SMALL = false>\r\nstruct Point_Add_Rectangle_Sum {\r\n  using G = typename\
    \ AbelGroup::value_type;\r\n  int Q;\r\n  vi X, Y;\r\n  vc<G> WT;\r\n  vc<tuple<ll,\
    \ ll, ll, ll>> rect;\r\n\r\n  Point_Add_Rectangle_Sum() {}\r\n\r\n  void add_query(ll\
    \ x, ll y, G w) { X.eb(x), Y.eb(y), WT.eb(w); }\r\n\r\n  void sum_query(ll xl,\
    \ ll yl, ll xr, ll yr) { rect.eb(xl, yl, xr, yr); }\r\n\r\n  vc<G> calc() {\r\n\
    \    int N = len(X), Q = len(rect);\r\n    if (N == 0) return vc<G>(Q, AbelGroup::unit());\r\
    \n    int NX = 0, NY = 0;\r\n    if (!SMALL) {\r\n      vi keyX = X, keyY = Y;\r\
    \n      UNIQUE(keyX), UNIQUE(keyY);\r\n      NX = len(keyX), NY = len(keyY);\r\
    \n      for (auto&& x: X) x = LB(keyX, x);\r\n      for (auto&& y: Y) y = LB(keyY,\
    \ y);\r\n      for (auto&& [xl, yl, xr, yr]: rect) {\r\n        xl = LB(keyX,\
    \ xl);\r\n        xr = LB(keyX, xr);\r\n        yl = LB(keyY, yl);\r\n       \
    \ yr = LB(keyY, yr);\r\n      }\r\n    }\r\n    if (SMALL) {\r\n      ll mx =\
    \ MIN(X);\r\n      ll my = MIN(Y);\r\n      for (auto&& x: X) x -= mx;\r\n   \
    \   for (auto&& y: Y) y -= my;\r\n      NX = MAX(X) + 1, NY = MAX(Y) + 1;\r\n\
    \      for (auto&& [xl, yl, xr, yr]: rect) {\r\n        xl -= mx, xr -= mx;\r\n\
    \        yl -= my, yr -= my;\r\n        xl = max(0, min<int>(xl, NX));\r\n   \
    \     xr = max(0, min<int>(xr, NX));\r\n        yl = max(0, min<int>(yl, NY));\r\
    \n        yr = max(0, min<int>(yr, NY));\r\n      }\r\n    }\r\n    vvc<pair<int,\
    \ G>> ADD(NY + 1);\r\n    vvc<tuple<int, int, int>> CALC_1(NY + 1);\r\n    vvc<tuple<int,\
    \ int, int>> CALC_2(NY + 1);\r\n    FOR(n, N) { ADD[Y[n]].eb(X[n], WT[n]); }\r\
    \n    FOR(q, Q) {\r\n      auto& [xl, yl, xr, yr] = rect[q];\r\n      CALC_1[yr].eb(xl,\
    \ xr, q);\r\n      CALC_2[yl].eb(xl, xr, q);\r\n    };\r\n\r\n    vc<G> res(Q,\
    \ AbelGroup::unit());\r\n    FenwickTree<AbelGroup> bit(NX);\r\n\r\n    FOR(y,\
    \ NY + 1) {\r\n      for (auto&& [xl, xr, q]: CALC_1[y]) {\r\n        auto x =\
    \ bit.sum(xl, xr);\r\n        res[q] = AbelGroup::op(res[q], x);\r\n      }\r\n\
    \      for (auto&& [xl, xr, q]: CALC_2[y]) {\r\n        auto x = AbelGroup::inverse(bit.sum(xl,\
    \ xr));\r\n        res[q] = AbelGroup::op(res[q], x);\r\n      }\r\n      for\
    \ (auto&& [x, g]: ADD[y]) { bit.add(x, g); }\r\n    }\r\n    return res;\r\n \
    \ }\r\n};\r\n#line 4 \"ds/rectangle_add_ractangle_sum.hpp\"\n\ntemplate <typename\
    \ AbelGroup, bool SMALL = false>\nstruct Rectangle_Add_Rectangle_Sum {\n  using\
    \ WT = typename AbelGroup::value_type;\n  using WT4 = tuple<WT, WT, WT, WT>;\n\
    \n  struct G {\n    using X = WT4;\n    using value_type = X;\n    static X op(const\
    \ X &x, const X &y) {\n      auto &[ax, bx, cx, dx] = x;\n      auto &[ay, by,\
    \ cy, dy] = y;\n      return {AbelGroup::op(ax, ay), AbelGroup::op(bx, by),\n\
    \              AbelGroup::op(cx, cy), AbelGroup::op(dx, dy)};\n    }\n    static\
    \ X inverse(const X &x) {\n      auto &[ax, bx, cx, dx] = x;\n      return {AbelGroup::inverse(ax),\
    \ AbelGroup::inverse(bx),\n              AbelGroup::inverse(cx), AbelGroup::inverse(dx)};\n\
    \    }\n    static X power(const X &x, ll n) {\n      auto &[ax, bx, cx, dx] =\
    \ x;\n      return {AbelGroup::power(ax, n), AbelGroup::power(bx, n),\n      \
    \        AbelGroup::power(cx, n), AbelGroup::power(dx, n)};\n    }\n    static\
    \ constexpr X unit() {\n      auto u = AbelGroup::unit();\n      return {u, u,\
    \ u, u};\n    }\n    static constexpr bool commute = true;\n  };\n\n  vc<tuple<ll,\
    \ ll, ll, ll>> query;\n  Point_Add_Rectangle_Sum<G, SMALL> X;\n  ll min_x = 0,\
    \ min_y = 0;\n\n  void add_query(ll xl, ll yl, ll xr, ll yr, WT w) {\n    assert(xl\
    \ <= xr && yl <= yr);\n    chmin(min_x, xl);\n    chmin(min_y, yl);\n    // (xl,yl)\
    \ \u306B (x-xl)(y-yl) \u3092\u52A0\u7B97\n    auto nw = AbelGroup::inverse(w);\n\
    \    X.add_query(xl, yl,\n                {w, AbelGroup::power(w, -yl), AbelGroup::power(w,\
    \ -xl),\n                 AbelGroup::power(w, +xl * yl)});\n    // (xl,yr) \u306B\
    \ (x-xl)(y-yr) \u3092\u6E1B\u7B97\n    X.add_query(xl, yr,\n                {nw,\
    \ AbelGroup::power(w, +yr), AbelGroup::power(w, +xl),\n                 AbelGroup::power(w,\
    \ -xl * yr)});\n    // (xr,yl) \u306B (x-xr)(y-yl) \u3092\u6E1B\u7B97\n    X.add_query(xr,\
    \ yl,\n                {nw, AbelGroup::power(w, +yl), AbelGroup::power(w, +xr),\n\
    \                 AbelGroup::power(w, -xr * yl)});\n    // (xr,yr) \u306B (x-xr)(y-yr)\
    \ \u3092\u52A0\u7B97\n    X.add_query(xr, yr,\n                {w, AbelGroup::power(w,\
    \ -yr), AbelGroup::power(w, -xr),\n                 AbelGroup::power(w, +xr *\
    \ yr)});\n  }\n\n  void sum_query(ll xl, ll yl, ll xr, ll yr) {\n    assert(xl\
    \ <= xr && yl <= yr);\n    query.eb(xl, yl, xr, yr);\n    X.sum_query(min_x, min_y,\
    \ xl, yl);\n    X.sum_query(min_x, min_y, xl, yr);\n    X.sum_query(min_x, min_y,\
    \ xr, yl);\n    X.sum_query(min_x, min_y, xr, yr);\n  }\n\n  vc<WT> calc() {\n\
    \    ll Q = len(query);\n    vc<WT> ANS(Q);\n    auto tmp = X.calc();\n    assert(len(tmp)\
    \ == 4 * Q);\n\n    FOR(q, Q) {\n      auto [xl, yl, xr, yr] = query[q];\n   \
    \   WT p = AbelGroup::unit(), m = AbelGroup::unit();\n      {\n        auto [a,\
    \ b, c, d] = tmp[4 * q + 0];\n        p = AbelGroup::op(p, AbelGroup::power(a,\
    \ xl * yl));\n        p = AbelGroup::op(p, AbelGroup::power(b, xl));\n       \
    \ p = AbelGroup::op(p, AbelGroup::power(c, yl));\n        p = AbelGroup::op(p,\
    \ d);\n      }\n      {\n        auto [a, b, c, d] = tmp[4 * q + 1];\n       \
    \ m = AbelGroup::op(m, AbelGroup::power(a, xl * yr));\n        m = AbelGroup::op(m,\
    \ AbelGroup::power(b, xl));\n        m = AbelGroup::op(m, AbelGroup::power(c,\
    \ yr));\n        m = AbelGroup::op(m, d);\n      }\n      {\n        auto [a,\
    \ b, c, d] = tmp[4 * q + 2];\n        m = AbelGroup::op(m, AbelGroup::power(a,\
    \ xr * yl));\n        m = AbelGroup::op(m, AbelGroup::power(b, xr));\n       \
    \ m = AbelGroup::op(m, AbelGroup::power(c, yl));\n        m = AbelGroup::op(m,\
    \ d);\n      }\n      {\n        auto [a, b, c, d] = tmp[4 * q + 3];\n       \
    \ p = AbelGroup::op(p, AbelGroup::power(a, xr * yr));\n        p = AbelGroup::op(p,\
    \ AbelGroup::power(b, xr));\n        p = AbelGroup::op(p, AbelGroup::power(c,\
    \ yr));\n        p = AbelGroup::op(p, d);\n      }\n      ANS[q] = AbelGroup::op(p,\
    \ AbelGroup::inverse(m));\n    }\n    return ANS;\n  }\n};\n"
  code: "#pragma once\n\n#include \"ds/point_add_rectangle_sum.hpp\"\n\ntemplate <typename\
    \ AbelGroup, bool SMALL = false>\nstruct Rectangle_Add_Rectangle_Sum {\n  using\
    \ WT = typename AbelGroup::value_type;\n  using WT4 = tuple<WT, WT, WT, WT>;\n\
    \n  struct G {\n    using X = WT4;\n    using value_type = X;\n    static X op(const\
    \ X &x, const X &y) {\n      auto &[ax, bx, cx, dx] = x;\n      auto &[ay, by,\
    \ cy, dy] = y;\n      return {AbelGroup::op(ax, ay), AbelGroup::op(bx, by),\n\
    \              AbelGroup::op(cx, cy), AbelGroup::op(dx, dy)};\n    }\n    static\
    \ X inverse(const X &x) {\n      auto &[ax, bx, cx, dx] = x;\n      return {AbelGroup::inverse(ax),\
    \ AbelGroup::inverse(bx),\n              AbelGroup::inverse(cx), AbelGroup::inverse(dx)};\n\
    \    }\n    static X power(const X &x, ll n) {\n      auto &[ax, bx, cx, dx] =\
    \ x;\n      return {AbelGroup::power(ax, n), AbelGroup::power(bx, n),\n      \
    \        AbelGroup::power(cx, n), AbelGroup::power(dx, n)};\n    }\n    static\
    \ constexpr X unit() {\n      auto u = AbelGroup::unit();\n      return {u, u,\
    \ u, u};\n    }\n    static constexpr bool commute = true;\n  };\n\n  vc<tuple<ll,\
    \ ll, ll, ll>> query;\n  Point_Add_Rectangle_Sum<G, SMALL> X;\n  ll min_x = 0,\
    \ min_y = 0;\n\n  void add_query(ll xl, ll yl, ll xr, ll yr, WT w) {\n    assert(xl\
    \ <= xr && yl <= yr);\n    chmin(min_x, xl);\n    chmin(min_y, yl);\n    // (xl,yl)\
    \ \u306B (x-xl)(y-yl) \u3092\u52A0\u7B97\n    auto nw = AbelGroup::inverse(w);\n\
    \    X.add_query(xl, yl,\n                {w, AbelGroup::power(w, -yl), AbelGroup::power(w,\
    \ -xl),\n                 AbelGroup::power(w, +xl * yl)});\n    // (xl,yr) \u306B\
    \ (x-xl)(y-yr) \u3092\u6E1B\u7B97\n    X.add_query(xl, yr,\n                {nw,\
    \ AbelGroup::power(w, +yr), AbelGroup::power(w, +xl),\n                 AbelGroup::power(w,\
    \ -xl * yr)});\n    // (xr,yl) \u306B (x-xr)(y-yl) \u3092\u6E1B\u7B97\n    X.add_query(xr,\
    \ yl,\n                {nw, AbelGroup::power(w, +yl), AbelGroup::power(w, +xr),\n\
    \                 AbelGroup::power(w, -xr * yl)});\n    // (xr,yr) \u306B (x-xr)(y-yr)\
    \ \u3092\u52A0\u7B97\n    X.add_query(xr, yr,\n                {w, AbelGroup::power(w,\
    \ -yr), AbelGroup::power(w, -xr),\n                 AbelGroup::power(w, +xr *\
    \ yr)});\n  }\n\n  void sum_query(ll xl, ll yl, ll xr, ll yr) {\n    assert(xl\
    \ <= xr && yl <= yr);\n    query.eb(xl, yl, xr, yr);\n    X.sum_query(min_x, min_y,\
    \ xl, yl);\n    X.sum_query(min_x, min_y, xl, yr);\n    X.sum_query(min_x, min_y,\
    \ xr, yl);\n    X.sum_query(min_x, min_y, xr, yr);\n  }\n\n  vc<WT> calc() {\n\
    \    ll Q = len(query);\n    vc<WT> ANS(Q);\n    auto tmp = X.calc();\n    assert(len(tmp)\
    \ == 4 * Q);\n\n    FOR(q, Q) {\n      auto [xl, yl, xr, yr] = query[q];\n   \
    \   WT p = AbelGroup::unit(), m = AbelGroup::unit();\n      {\n        auto [a,\
    \ b, c, d] = tmp[4 * q + 0];\n        p = AbelGroup::op(p, AbelGroup::power(a,\
    \ xl * yl));\n        p = AbelGroup::op(p, AbelGroup::power(b, xl));\n       \
    \ p = AbelGroup::op(p, AbelGroup::power(c, yl));\n        p = AbelGroup::op(p,\
    \ d);\n      }\n      {\n        auto [a, b, c, d] = tmp[4 * q + 1];\n       \
    \ m = AbelGroup::op(m, AbelGroup::power(a, xl * yr));\n        m = AbelGroup::op(m,\
    \ AbelGroup::power(b, xl));\n        m = AbelGroup::op(m, AbelGroup::power(c,\
    \ yr));\n        m = AbelGroup::op(m, d);\n      }\n      {\n        auto [a,\
    \ b, c, d] = tmp[4 * q + 2];\n        m = AbelGroup::op(m, AbelGroup::power(a,\
    \ xr * yl));\n        m = AbelGroup::op(m, AbelGroup::power(b, xr));\n       \
    \ m = AbelGroup::op(m, AbelGroup::power(c, yl));\n        m = AbelGroup::op(m,\
    \ d);\n      }\n      {\n        auto [a, b, c, d] = tmp[4 * q + 3];\n       \
    \ p = AbelGroup::op(p, AbelGroup::power(a, xr * yr));\n        p = AbelGroup::op(p,\
    \ AbelGroup::power(b, xr));\n        p = AbelGroup::op(p, AbelGroup::power(c,\
    \ yr));\n        p = AbelGroup::op(p, d);\n      }\n      ANS[q] = AbelGroup::op(p,\
    \ AbelGroup::inverse(m));\n    }\n    return ANS;\n  }\n};\n"
  dependsOn:
  - ds/point_add_rectangle_sum.hpp
  - ds/fenwick.hpp
  - alg/group_add.hpp
  isVerificationFile: false
  path: ds/rectangle_add_ractangle_sum.hpp
  requiredBy: []
  timestamp: '2022-06-27 00:47:49+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/yukicoder/1490_rect_add_rect_sum.test.cpp
documentation_of: ds/rectangle_add_ractangle_sum.hpp
layout: document
redirect_from:
- /library/ds/rectangle_add_ractangle_sum.hpp
- /library/ds/rectangle_add_ractangle_sum.hpp.html
title: ds/rectangle_add_ractangle_sum.hpp
---
