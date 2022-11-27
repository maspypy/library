---
data:
  _extendedDependsOn:
  - icon: ':question:'
    path: alg/monoid/add.hpp
    title: alg/monoid/add.hpp
  - icon: ':question:'
    path: ds/fenwick.hpp
    title: ds/fenwick.hpp
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':x:'
    path: test/mytest/rect_add_pt_sum.test.cpp
    title: test/mytest/rect_add_pt_sum.test.cpp
  _isVerificationFailed: true
  _pathExtension: hpp
  _verificationStatusIcon: ':x:'
  attributes:
    links: []
  bundledCode: "#line 2 \"alg/monoid/add.hpp\"\n\r\ntemplate <typename E>\r\nstruct\
    \ Monoid_Add {\r\n  using X = E;\r\n  using value_type = X;\r\n  static constexpr\
    \ X op(const X &x, const X &y) noexcept { return x + y; }\r\n  static constexpr\
    \ X inverse(const X &x) noexcept { return -x; }\r\n  static constexpr X power(const\
    \ X &x, ll n) noexcept { return X(n) * x; }\r\n  static constexpr X unit() { return\
    \ X(0); }\r\n  static constexpr bool commute = true;\r\n};\r\n#line 3 \"ds/fenwick.hpp\"\
    \n\ntemplate <typename AbelGroup>\nstruct FenwickTree {\n  using E = typename\
    \ AbelGroup::value_type;\n  int n;\n  vector<E> dat;\n  E total;\n\n  FenwickTree(int\
    \ n = 0) : n(n) {\n    assert(AbelGroup::commute);\n    reset(n);\n  }\n  FenwickTree(const\
    \ vector<E>& v) {\n    assert(AbelGroup::commute);\n    build(v);\n  }\n\n  void\
    \ build(const vc<E>& v) {\n    n = len(v);\n    total = AbelGroup::unit();\n \
    \   for (int i = 0; i < n; ++i) total = AbelGroup::op(total, v[i]);\n    dat =\
    \ v;\n    for (int i = 1; i <= n; ++i) {\n      int j = i + (i & -i);\n      if\
    \ (j <= n) dat[j - 1] = AbelGroup::op(dat[i - 1], dat[j - 1]);\n    }\n  }\n\n\
    \  void reset(int sz = 0) {\n    if (sz) n = sz;\n    total = AbelGroup::unit();\n\
    \    dat.assign(n, AbelGroup::unit());\n  }\n\n  E prod(int k) {\n    E ret =\
    \ AbelGroup::unit();\n    for (; k > 0; k -= k & -k) ret = AbelGroup::op(ret,\
    \ dat[k - 1]);\n    return ret;\n  }\n\n  E prod(int L, int R) {\n    E pos =\
    \ AbelGroup::unit();\n    while (L < R) {\n      pos = AbelGroup::op(pos, dat[R\
    \ - 1]);\n      R -= R & -R;\n    }\n    E neg = AbelGroup::unit();\n    while\
    \ (R < L) {\n      neg = AbelGroup::op(neg, dat[L - 1]);\n      L -= L & -L;\n\
    \    }\n    return AbelGroup::op(pos, AbelGroup::inverse(neg));\n  }\n\n  E prod_all()\
    \ { return total; }\n\n  E sum(int k) { return prod(k); }\n\n  E sum(int L, int\
    \ R) { return prod(L, R); }\n\n  E sum_all() { return total; }\n\n  void multiply(int\
    \ k, E x) {\n    total = AbelGroup::op(total, x);\n    for (++k; k <= n; k +=\
    \ k & -k) dat[k - 1] = AbelGroup::op(dat[k - 1], x);\n  }\n\n  void add(int k,\
    \ E x) { multiply(k, x); }\n\n  template <class F>\n  int max_right(F& check)\
    \ {\n    assert(check(E(0)));\n    ll i = 0;\n    E s = AbelGroup::unit();\n \
    \   int k = 1;\n    int N = dat.size() + 1;\n    while (2 * k < N) k *= 2;\n \
    \   while (k) {\n      if (i + k < N && check(AbelGroup::op(s, dat[i + k - 1])))\
    \ {\n        i += k;\n        s = AbelGroup::op(s, dat[i - 1]);\n      }\n   \
    \   k >>= 1;\n    }\n    return i;\n  }\n\n  int find_kth(E k) {\n    auto check\
    \ = [&](E x) -> bool { return x <= k; };\n    return max_right(check);\n  }\n\n\
    \  void debug() { print(\"fenwick\", dat); }\n};\n#line 2 \"ds/query/rectangle_add_point_sum.hpp\"\
    \n\ntemplate <typename AbelGroup, bool SMALL>\nstruct Rectangle_Add_Point_Sum\
    \ {\n  using G = typename AbelGroup::value_type;\n  vc<tuple<ll, ll, ll, ll>>\
    \ rect;\n  vc<G> WT;\n  vc<pi> point;\n\n  Rectangle_Add_Point_Sum() {}\n\n  void\
    \ add_query(ll xl, ll xr, ll yl, ll yr, G g) {\n    rect.eb(xl, xr, yl, yr);\n\
    \    WT.eb(g);\n  }\n\n  void sum_query(ll x, ll y) { point.eb(x, y); }\n\n  vc<G>\
    \ calc() {\n    int N = len(rect), Q = len(point);\n    if (N == 0) return vc<G>(Q,\
    \ AbelGroup::unit());\n    vi keyX, keyY;\n    keyX.reserve(2 * N + Q);\n    keyY.reserve(2\
    \ * N + Q);\n    for (auto&& [xl, xr, yl, yr]: rect) {\n      keyX.eb(xl), keyX.eb(xr),\
    \ keyY.eb(yl), keyY.eb(yr);\n    }\n    for (auto&& [x, y]: point) { keyX.eb(x),\
    \ keyY.eb(y); }\n    int NX = 0, NY = 0;\n    if (!SMALL) {\n      UNIQUE(keyX),\
    \ UNIQUE(keyY);\n      NX = len(keyX), NY = len(keyY);\n      for (auto&& [xl,\
    \ xr, yl, yr]: rect) {\n        xl = LB(keyX, xl), xr = LB(keyX, xr);\n      \
    \  yl = LB(keyY, yl), yr = LB(keyY, yr);\n      }\n      for (auto&& [x, y]: point)\
    \ {\n        x = LB(keyX, x);\n        y = LB(keyY, y);\n      }\n    } else {\n\
    \      ll mx = MIN(keyX), my = MIN(keyY);\n      NX = MAX(keyX) - mx + 1, NY =\
    \ MAX(keyY) - my + 1;\n      for (auto&& [xl, xr, yl, yr]: rect) {\n        xl\
    \ = xl - mx, xr = xr - mx;\n        yl = yl - my, yr = yr - my;\n      }\n   \
    \   for (auto&& [x, y]: point) { x = x - mx, y = y - my; }\n    }\n    vvc<tuple<int,\
    \ int, G>> ADD(NY);\n    vvc<int> CALC(NY);\n    FOR(i, N) {\n      auto [xl,\
    \ xr, yl, yr] = rect[i];\n      ADD[yl].eb(xl, xr, WT[i]);\n      ADD[yr].eb(xl,\
    \ xr, AbelGroup::inverse(WT[i]));\n    }\n    FOR(q, Q) {\n      auto [x, y] =\
    \ point[q];\n      CALC[y].eb(q);\n    }\n    vc<G> res(Q);\n    FenwickTree<AbelGroup>\
    \ bit(NX);\n    FOR(y, NY) {\n      for (auto&& [xl, xr, g]: ADD[y]) {\n     \
    \   bit.add(xl, g);\n        bit.add(xr, AbelGroup::inverse(g));\n      }\n  \
    \    for (auto&& q: CALC[y]) {\n        auto [x, y] = point[q];\n        res[q]\
    \ = bit.prod(x + 1);\n      }\n    }\n    return res;\n  }\n};\n"
  code: "#include \"ds/fenwick.hpp\"\n\ntemplate <typename AbelGroup, bool SMALL>\n\
    struct Rectangle_Add_Point_Sum {\n  using G = typename AbelGroup::value_type;\n\
    \  vc<tuple<ll, ll, ll, ll>> rect;\n  vc<G> WT;\n  vc<pi> point;\n\n  Rectangle_Add_Point_Sum()\
    \ {}\n\n  void add_query(ll xl, ll xr, ll yl, ll yr, G g) {\n    rect.eb(xl, xr,\
    \ yl, yr);\n    WT.eb(g);\n  }\n\n  void sum_query(ll x, ll y) { point.eb(x, y);\
    \ }\n\n  vc<G> calc() {\n    int N = len(rect), Q = len(point);\n    if (N ==\
    \ 0) return vc<G>(Q, AbelGroup::unit());\n    vi keyX, keyY;\n    keyX.reserve(2\
    \ * N + Q);\n    keyY.reserve(2 * N + Q);\n    for (auto&& [xl, xr, yl, yr]: rect)\
    \ {\n      keyX.eb(xl), keyX.eb(xr), keyY.eb(yl), keyY.eb(yr);\n    }\n    for\
    \ (auto&& [x, y]: point) { keyX.eb(x), keyY.eb(y); }\n    int NX = 0, NY = 0;\n\
    \    if (!SMALL) {\n      UNIQUE(keyX), UNIQUE(keyY);\n      NX = len(keyX), NY\
    \ = len(keyY);\n      for (auto&& [xl, xr, yl, yr]: rect) {\n        xl = LB(keyX,\
    \ xl), xr = LB(keyX, xr);\n        yl = LB(keyY, yl), yr = LB(keyY, yr);\n   \
    \   }\n      for (auto&& [x, y]: point) {\n        x = LB(keyX, x);\n        y\
    \ = LB(keyY, y);\n      }\n    } else {\n      ll mx = MIN(keyX), my = MIN(keyY);\n\
    \      NX = MAX(keyX) - mx + 1, NY = MAX(keyY) - my + 1;\n      for (auto&& [xl,\
    \ xr, yl, yr]: rect) {\n        xl = xl - mx, xr = xr - mx;\n        yl = yl -\
    \ my, yr = yr - my;\n      }\n      for (auto&& [x, y]: point) { x = x - mx, y\
    \ = y - my; }\n    }\n    vvc<tuple<int, int, G>> ADD(NY);\n    vvc<int> CALC(NY);\n\
    \    FOR(i, N) {\n      auto [xl, xr, yl, yr] = rect[i];\n      ADD[yl].eb(xl,\
    \ xr, WT[i]);\n      ADD[yr].eb(xl, xr, AbelGroup::inverse(WT[i]));\n    }\n \
    \   FOR(q, Q) {\n      auto [x, y] = point[q];\n      CALC[y].eb(q);\n    }\n\
    \    vc<G> res(Q);\n    FenwickTree<AbelGroup> bit(NX);\n    FOR(y, NY) {\n  \
    \    for (auto&& [xl, xr, g]: ADD[y]) {\n        bit.add(xl, g);\n        bit.add(xr,\
    \ AbelGroup::inverse(g));\n      }\n      for (auto&& q: CALC[y]) {\n        auto\
    \ [x, y] = point[q];\n        res[q] = bit.prod(x + 1);\n      }\n    }\n    return\
    \ res;\n  }\n};\n"
  dependsOn:
  - ds/fenwick.hpp
  - alg/monoid/add.hpp
  isVerificationFile: false
  path: ds/query/rectangle_add_point_sum.hpp
  requiredBy: []
  timestamp: '2022-11-27 14:09:46+09:00'
  verificationStatus: LIBRARY_ALL_WA
  verifiedWith:
  - test/mytest/rect_add_pt_sum.test.cpp
documentation_of: ds/query/rectangle_add_point_sum.hpp
layout: document
redirect_from:
- /library/ds/query/rectangle_add_point_sum.hpp
- /library/ds/query/rectangle_add_point_sum.hpp.html
title: ds/query/rectangle_add_point_sum.hpp
---
