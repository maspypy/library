---
data:
  _extendedDependsOn:
  - icon: ':question:'
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
    \ bool SMALL = false>\r\nstruct Point_Add_Rectangle_Sum {\r\n  using WT = typename\
    \ AbelGroup::value_type;\r\n  bool compressed;\r\n  int Q;\r\n  vi X, Y;\r\n \
    \ vi keyX, keyY;\r\n  ll min_x, max_x, min_y, max_y;\r\n  vc<WT> wt;\r\n  vc<vc<pair<int,\
    \ WT>>> add;\r\n  vc<vc<tuple<int, int, int>>> query_l;\r\n  vc<vc<tuple<int,\
    \ int, int>>> query_r;\r\n\r\n  Point_Add_Rectangle_Sum() : compressed(0), Q(0)\
    \ {}\r\n\r\n  void add_query(ll x, ll y, WT w = 1) {\r\n    assert(!compressed);\r\
    \n    X.eb(x), Y.eb(y), wt.eb(w);\r\n    keyX.eb(x), keyY.eb(y);\r\n  }\r\n\r\n\
    \  void compress() {\r\n    compressed = 1;\r\n    int N = len(X);\r\n    if (!SMALL)\
    \ {\r\n      UNIQUE(keyX), UNIQUE(keyY);\r\n      add.resize(len(keyX) + 1);\r\
    \n      FOR(i, N) {\r\n        ll x = X[i], y = Y[i];\r\n        WT w = wt[i];\r\
    \n        x = LB(keyX, x), y = LB(keyY, y);\r\n        add[x].eb(y, w);\r\n  \
    \    }\r\n    } else {\r\n      min_x = (N == 0 ? 0 : MIN(X));\r\n      max_x\
    \ = (N == 0 ? 0 : MAX(X));\r\n      min_y = (N == 0 ? 0 : MIN(Y));\r\n      max_y\
    \ = (N == 0 ? 0 : MAX(Y));\r\n      add.resize(max_x - min_x + 2);\r\n      FOR(i,\
    \ N) {\r\n        ll x = X[i], y = Y[i];\r\n        WT w = wt[i];\r\n        x\
    \ -= min_x, y -= min_y;\r\n        add[x].eb(y, w);\r\n      }\r\n    }\r\n  \
    \  query_l.resize(len(add));\r\n    query_r.resize(len(add));\r\n  }\r\n\r\n \
    \ void sum_query(ll xl, ll yl, ll xr, ll yr) {\r\n    if (!compressed) compress();\r\
    \n    if (!SMALL) {\r\n      xl = LB(keyX, xl), xr = LB(keyX, xr);\r\n      yl\
    \ = LB(keyY, yl), yr = LB(keyY, yr);\r\n    } else {\r\n      xl -= min_x, xr\
    \ -= min_x;\r\n      yl -= min_y, yr -= min_y;\r\n      xl = clamp(xl, 0LL, max_x\
    \ - min_x + 1);\r\n      xr = clamp(xr, 0LL, max_x - min_x + 1);\r\n      yl =\
    \ clamp(yl, 0LL, max_y - min_y + 1);\r\n      yr = clamp(yr, 0LL, max_y - min_y\
    \ + 1);\r\n    }\r\n    query_l[xl].eb(Q, yl, yr);\r\n    query_r[xr].eb(Q, yl,\
    \ yr);\r\n    ++Q;\r\n  }\r\n\r\n  vc<WT> calc() {\r\n    assert(compressed);\r\
    \n    vc<WT> ANS(Q, AbelGroup::unit());\r\n    int k = (SMALL ? max_y - min_y\
    \ + 2 : len(keyY) + 1);\r\n    FenwickTree<AbelGroup> bit(k);\r\n    FOR(x, len(add))\
    \ {\r\n      for (auto&& t: query_l[x]) {\r\n        auto [q, yl, yr] = t;\r\n\
    \        ANS[q] = AbelGroup::op(ANS[q] , AbelGroup::inverse(bit.sum(yl, yr)));\r\
    \n      }\r\n      for (auto&& t: query_r[x]) {\r\n        auto [q, yl, yr] =\
    \ t;\r\n        ANS[q] = AbelGroup::op(ANS[q] , bit.sum(yl, yr));\r\n      }\r\
    \n      for (auto&& t: add[x]) {\r\n        auto [y, w] = t;\r\n        bit.add(y,\
    \ w);\r\n      }\r\n      query_l[x].clear();\r\n      query_r[x].clear();\r\n\
    \    }\r\n    Q = 0;\r\n    return ANS;\r\n  }\r\n};\r\n#line 4 \"ds/rectangle_add_ractangle_sum.hpp\"\
    \n\ntemplate <typename AbelGroup, bool SMALL = false>\nstruct Rectangle_Add_Rectangle_Sum\
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
    \ {u, u, u, u};\n    }\n    static constexpr bool commute = true;\n  };\n\n  vc<tuple<ll,\
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
  timestamp: '2022-05-20 03:30:48+09:00'
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
