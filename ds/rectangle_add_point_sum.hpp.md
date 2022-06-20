---
data:
  _extendedDependsOn:
  - icon: ':question:'
    path: alg/group_add.hpp
    title: alg/group_add.hpp
  - icon: ':heavy_check_mark:'
    path: ds/fenwick.hpp
    title: ds/fenwick.hpp
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':warning:'
  attributes:
    links: []
  bundledCode: "#line 2 \"alg/group_add.hpp\"\ntemplate <class X>\r\nstruct Group_Add\
    \ {\r\n  using value_type = X;\r\n  static constexpr X op(const X &x, const X\
    \ &y) noexcept { return x + y; }\r\n  static constexpr X inverse(const X &x) noexcept\
    \ { return -x; }\r\n  static constexpr X power(const X &x, ll n) noexcept { return\
    \ n * x; }\r\n  static constexpr X unit() { return X(0); }\r\n  static constexpr\
    \ bool commute = true;\r\n};\r\n#line 3 \"ds/fenwick.hpp\"\n\ntemplate <typename\
    \ AbelGroup>\nstruct FenwickTree {\n  using E = typename AbelGroup::value_type;\n\
    \  int n;\n  vector<E> dat;\n  E total;\n\n  FenwickTree() : FenwickTree(0) {}\n\
    \  FenwickTree(int n) : n(n), total(AbelGroup::unit()) {\n    assert(AbelGroup::commute);\n\
    \    dat.assign(n, AbelGroup::unit());\n  }\n  FenwickTree(vc<E> v) : n(len(v)),\
    \ total(AbelGroup::unit()) {\n    assert(AbelGroup::commute);\n    FOR(i, n) total\
    \ = AbelGroup::op(total, v[i]);\n    dat = v;\n    FOR3(i, 1, n + 1) {\n     \
    \ int j = i + (i & -i);\n      if (j <= n) dat[j - 1] = AbelGroup::op(dat[i -\
    \ 1], dat[j - 1]);\n    }\n  }\n\n  void reset(){\n    total = AbelGroup::unit();\n\
    \    dat.assign(n, AbelGroup::unit());\n  }\n\n  E sum(int k) {\n    E ret = AbelGroup::unit();\n\
    \    for (; k > 0; k -= k & -k) ret = AbelGroup::op(ret, dat[k - 1]);\n    return\
    \ ret;\n  }\n\n  E sum(int L, int R) {\n    E pos = AbelGroup::unit();\n    while\
    \ (L < R) {\n      pos = AbelGroup::op(pos, dat[R - 1]);\n      R -= R & -R;\n\
    \    }\n    E neg = AbelGroup::unit();\n    while (R < L) {\n      neg = AbelGroup::op(neg,\
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
    \  void debug() { print(\"fenwick\", dat); }\n};\n#line 2 \"ds/rectangle_add_point_sum.hpp\"\
    \n\ntemplate <typename AbelGroup, bool SMALL>\nstruct Rectangle_Add_Point_Sum\
    \ {\n  using G = typename AbelGroup::value_type;\n  vc<tuple<ll, ll, ll, ll>>\
    \ rect;\n  vc<G> WT;\n  vc<pi> point;\n\n  Rectangle_Add_Point_Sum() {}\n\n  void\
    \ add_query(ll xl, ll yl, ll xr, ll yr, G g) {\n    rect.eb(xl, xr, yl, yr);\n\
    \    WT.eb(g);\n  }\n\n  void sum_query(ll x, ll y) { point.eb(x, y); }\n\n  vc<G>\
    \ calc() {\n    int N = len(rect), Q = len(point);\n    if (N == 0) return vc<G>(Q,\
    \ AbelGroup::unit());\n    vi keyX, keyY;\n    keyX.reserve(2 * N + Q);\n    keyY.reserve(2\
    \ * N + Q);\n    for (auto&& [xl, yl, xr, yr]: rect) {\n      keyX.eb(xl), keyX.eb(xr),\
    \ keyY.eb(yl), keyY.eb(yr);\n    }\n    for (auto&& [x, y]: point) { keyX.eb(x),\
    \ keyY.eb(y); }\n    int NX = 0, NY = 0;\n    if (!SMALL) {\n      UNIQUE(keyX),\
    \ UNIQUE(keyY);\n      NX = len(keyX), NY = len(keyY);\n      for (auto&& [xl,\
    \ yl, xr, yr]: rect) {\n        xl = LB(keyX, xl), xr = LB(keyX, xr);\n      \
    \  yl = LB(keyY, yl), yr = LB(keyY, yr);\n      }\n      for (auto&& [x, y]: point)\
    \ {\n        x = LB(keyX, x);\n        y = LB(keyY, y);\n      }\n    } else {\n\
    \      ll mx = MIN(keyX), my = MIN(keyY);\n      NX = MAX(keyX) - mx + 1, NY =\
    \ MAX(keyY) - my + 1;\n      for (auto&& [xl, yl, xr, yr]: rect) {\n        xl\
    \ = xl - mx, xr = xr - mx;\n        yl = yl - my, yr = yr - my;\n      }\n   \
    \   for (auto&& [x, y]: point) { x = x - mx, y = y - my; }\n    }\n    vvc<tuple<int,\
    \ int, G>> ADD(NY);\n    vvc<int> CALC(NY);\n    FOR(i, N) {\n      auto [xl,\
    \ yl, xr, yr] = rect[i];\n      ADD[yl].eb(xl, xr, WT[i]);\n      ADD[yr].eb(xl,\
    \ xr, AbelGroup::inverse(WT[i]));\n    }\n    FOR(q, Q) {\n      auto [x, y] =\
    \ point[q];\n      CALC[y].eb(q);\n    }\n    vc<G> res(Q);\n    FenwickTree<AbelGroup>\
    \ bit(NX);\n    FOR(y, NY) {\n      for (auto&& [xl, xr, g]: ADD[y]) {\n     \
    \   bit.add(xl, g);\n        bit.add(xr, AbelGroup::inverse(g));\n      }\n  \
    \    for (auto&& q: CALC[y]) {\n        auto [x, y] = point[q];\n        res[q]\
    \ = bit.sum(x + 1);\n      }\n    }\n    return res;\n  }\n};\n"
  code: "#include \"ds/fenwick.hpp\"\n\ntemplate <typename AbelGroup, bool SMALL>\n\
    struct Rectangle_Add_Point_Sum {\n  using G = typename AbelGroup::value_type;\n\
    \  vc<tuple<ll, ll, ll, ll>> rect;\n  vc<G> WT;\n  vc<pi> point;\n\n  Rectangle_Add_Point_Sum()\
    \ {}\n\n  void add_query(ll xl, ll yl, ll xr, ll yr, G g) {\n    rect.eb(xl, xr,\
    \ yl, yr);\n    WT.eb(g);\n  }\n\n  void sum_query(ll x, ll y) { point.eb(x, y);\
    \ }\n\n  vc<G> calc() {\n    int N = len(rect), Q = len(point);\n    if (N ==\
    \ 0) return vc<G>(Q, AbelGroup::unit());\n    vi keyX, keyY;\n    keyX.reserve(2\
    \ * N + Q);\n    keyY.reserve(2 * N + Q);\n    for (auto&& [xl, yl, xr, yr]: rect)\
    \ {\n      keyX.eb(xl), keyX.eb(xr), keyY.eb(yl), keyY.eb(yr);\n    }\n    for\
    \ (auto&& [x, y]: point) { keyX.eb(x), keyY.eb(y); }\n    int NX = 0, NY = 0;\n\
    \    if (!SMALL) {\n      UNIQUE(keyX), UNIQUE(keyY);\n      NX = len(keyX), NY\
    \ = len(keyY);\n      for (auto&& [xl, yl, xr, yr]: rect) {\n        xl = LB(keyX,\
    \ xl), xr = LB(keyX, xr);\n        yl = LB(keyY, yl), yr = LB(keyY, yr);\n   \
    \   }\n      for (auto&& [x, y]: point) {\n        x = LB(keyX, x);\n        y\
    \ = LB(keyY, y);\n      }\n    } else {\n      ll mx = MIN(keyX), my = MIN(keyY);\n\
    \      NX = MAX(keyX) - mx + 1, NY = MAX(keyY) - my + 1;\n      for (auto&& [xl,\
    \ yl, xr, yr]: rect) {\n        xl = xl - mx, xr = xr - mx;\n        yl = yl -\
    \ my, yr = yr - my;\n      }\n      for (auto&& [x, y]: point) { x = x - mx, y\
    \ = y - my; }\n    }\n    vvc<tuple<int, int, G>> ADD(NY);\n    vvc<int> CALC(NY);\n\
    \    FOR(i, N) {\n      auto [xl, yl, xr, yr] = rect[i];\n      ADD[yl].eb(xl,\
    \ xr, WT[i]);\n      ADD[yr].eb(xl, xr, AbelGroup::inverse(WT[i]));\n    }\n \
    \   FOR(q, Q) {\n      auto [x, y] = point[q];\n      CALC[y].eb(q);\n    }\n\
    \    vc<G> res(Q);\n    FenwickTree<AbelGroup> bit(NX);\n    FOR(y, NY) {\n  \
    \    for (auto&& [xl, xr, g]: ADD[y]) {\n        bit.add(xl, g);\n        bit.add(xr,\
    \ AbelGroup::inverse(g));\n      }\n      for (auto&& q: CALC[y]) {\n        auto\
    \ [x, y] = point[q];\n        res[q] = bit.sum(x + 1);\n      }\n    }\n    return\
    \ res;\n  }\n};"
  dependsOn:
  - ds/fenwick.hpp
  - alg/group_add.hpp
  isVerificationFile: false
  path: ds/rectangle_add_point_sum.hpp
  requiredBy: []
  timestamp: '2022-06-17 22:36:21+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: ds/rectangle_add_point_sum.hpp
layout: document
redirect_from:
- /library/ds/rectangle_add_point_sum.hpp
- /library/ds/rectangle_add_point_sum.hpp.html
title: ds/rectangle_add_point_sum.hpp
---
