---
data:
  _extendedDependsOn:
  - icon: ':question:'
    path: alg/monoid/add.hpp
    title: alg/monoid/add.hpp
  - icon: ':heavy_check_mark:'
    path: ds/fenwicktree/fenwicktree.hpp
    title: ds/fenwicktree/fenwicktree.hpp
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':warning:'
  attributes:
    links:
    - https://atcoder.jp/contests/pakencamp-2021-day3/tasks/pakencamp_2021_day3_f
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
    \ }\n  E prefix_prod(int k) {\n    chmin(k, n);\n    E ret = G::unit();\n    for\
    \ (; k > 0; k -= k & -k) ret = G::op(ret, dat[k - 1]);\n    return ret;\n  }\n\
    \  E sum(int L, int R) { return prod(L, R); }\n  E prod(int L, int R) {\n    chmax(L,\
    \ 0), chmin(R, n);\n    if (L == 0) return prefix_prod(R);\n    assert(0 <= L\
    \ && L <= R && R <= n);\n    E pos = G::unit(), neg = G::unit();\n    while (L\
    \ < R) { pos = G::op(pos, dat[R - 1]), R -= R & -R; }\n    while (R < L) { neg\
    \ = G::op(neg, dat[L - 1]), L -= L & -L; }\n    return G::op(pos, G::inverse(neg));\n\
    \  }\n\n  void add(int k, E x) { multiply(k, x); }\n  void multiply(int k, E x)\
    \ {\n    static_assert(G::commute);\n    total = G::op(total, x);\n    for (++k;\
    \ k <= n; k += k & -k) dat[k - 1] = G::op(dat[k - 1], x);\n  }\n\n  template <class\
    \ F>\n  int max_right(const F check) {\n    assert(check(G::unit()));\n    int\
    \ i = 0;\n    E s = G::unit();\n    int k = 1;\n    while (2 * k <= n) k *= 2;\n\
    \    while (k) {\n      if (i + k - 1 < len(dat)) {\n        E t = G::op(s, dat[i\
    \ + k - 1]);\n        if (check(t)) { i += k, s = t; }\n      }\n      k >>= 1;\n\
    \    }\n    return i;\n  }\n\n  int kth(E k) {\n    return max_right([&k](E x)\
    \ -> bool { return x <= k; });\n  }\n};\n#line 2 \"ds/offline_query/point_add_polygon_sum.hpp\"\
    \n\r\n/*\r\npolygon \u306F\u4E0D\u7B49\u5F0F aix + biy >= ci \u306B\u3088\u308A\
    \u6E21\u3059\u3002\r\npolygon \u306F\u51F8\u3067\u3001\u4E0D\u7B49\u5F0F\u306E\
    \u5217\u306F\u3001\u8FBA\u304C\u53CD\u6642\u8A08\u56DE\u308A\u306B\u56DE\u308B\
    \u3088\u3046\u306B\u3059\u308B\u3002\r\n(ai, bi) \u306F\u30B3\u30F3\u30B9\u30C8\
    \u30E9\u30AF\u30BF\u306B\u6E21\u3059\u3002\r\nadd_polygon \u3067 ci \u3092\u6E21\
    \u3059\u3002\r\n\u4F7F\u7528\u4F8B\uFF1Ahttps://atcoder.jp/contests/pakencamp-2021-day3/tasks/pakencamp_2021_day3_f\r\
    \n*/\r\ntemplate <typename AbelGroup, bool SMALL>\r\nstruct Point_Add_Polygon_Sum\
    \ {\r\n  using G = typename AbelGroup::value_type;\r\n  G total;\r\n  vc<pi> AB;\r\
    \n  vi X, Y;\r\n  vc<G> WT;\r\n  vvc<ll> poly;\r\n\r\n  Point_Add_Polygon_Sum(vc<pi>\
    \ AB) : total(AbelGroup::unit()), AB(AB) {\r\n    poly.resize(len(AB));\r\n  }\r\
    \n\r\n  void add_query(ll x, ll y, G g) {\r\n    X.eb(x);\r\n    Y.eb(y);\r\n\
    \    WT.eb(g);\r\n    total = AbelGroup::op(total, g);\r\n  }\r\n\r\n  void sum_query(vi\
    \ C) {\r\n    assert(len(C) == len(AB));\r\n    FOR(n, len(AB)) poly[n].eb(C[n]);\r\
    \n  }\r\n\r\n  vc<G> calc() {\r\n    int Q = len(poly[0]);\r\n    int N = len(X);\r\
    \n    vc<G> res(Q, total);\r\n    int K = len(AB);\r\n    FOR(k, K) {\r\n    \
    \  auto [a, b] = AB[(k + K - 1) % K];\r\n      auto [c, d] = AB[k];\r\n      //\
    \ ax+by>=ci \u304B\u3064 cx+dy<cj \u3068\u306A\u308B\u70B9\u306E\u5BC4\u4E0E\u3092\
    \u7B54\u304B\u3089\u5F15\u304F\r\n      vi A(N), B(N);\r\n      FOR(i, N) {\r\n\
    \        A[i] = -(a * X[i] + b * Y[i]);\r\n        B[i] = c * X[i] + d * Y[i];\r\
    \n      }\r\n      vi C(Q), D(Q);\r\n      FOR(q, Q) {\r\n        C[q] = -(poly[(k\
    \ + K - 1) % K][q]) + 1;\r\n        D[q] = poly[k][q];\r\n      }\r\n      //\
    \ A[i]<C[q] \u304B\u3064 B[i]<D[q] \u3068\u306A\u308B i \u306E\u5BC4\u4E0E\u3092\
    \ q \u304B\u3089\u5F15\u304F\r\n      int NA = 0, NB = 0;\r\n      if (!SMALL)\
    \ {\r\n        vi keyA = A, keyB = B;\r\n        UNIQUE(keyA), UNIQUE(keyB);\r\
    \n        for (auto&& x: A) x = LB(keyA, x);\r\n        for (auto&& x: B) x =\
    \ LB(keyB, x);\r\n        for (auto&& x: C) x = LB(keyA, x);\r\n        for (auto&&\
    \ x: D) x = LB(keyB, x);\r\n        NA = len(keyA) + 1;\r\n        NB = len(keyB)\
    \ + 1;\r\n      } else {\r\n        ll minA = MIN(A);\r\n        ll minB = MIN(B);\r\
    \n        for (auto&& x: A) x -= minA;\r\n        for (auto&& x: B) x -= minB;\r\
    \n        for (auto&& x: C) x -= minA;\r\n        for (auto&& x: D) x -= minB;\r\
    \n        NA = MAX(A) + 2;\r\n        NB = MAX(B) + 2;\r\n        for (auto&&\
    \ x: C) x = clamp<ll>(x, 0, NA - 1);\r\n        for (auto&& x: D) x = clamp<ll>(x,\
    \ 0, NB - 1);\r\n      }\r\n      vvc<int> PID(NB + 1);\r\n      vvc<int> QID(NB\
    \ + 1);\r\n      FOR(i, N) PID[B[i]].eb(i);\r\n      FOR(q, Q) QID[D[q]].eb(q);\r\
    \n\r\n      FenwickTree<AbelGroup> bit(NA);\r\n      FOR(b, NB) {\r\n        for\
    \ (auto&& q: QID[b]) {\r\n          G x = bit.sum(C[q]);\r\n          res[q] =\
    \ AbelGroup::op(res[q], AbelGroup::inverse(x));\r\n        }\r\n        for (auto&&\
    \ i: PID[b]) { bit.add(A[i], WT[i]); }\r\n      }\r\n    }\r\n    return res;\r\
    \n  }\r\n};\n"
  code: "#include \"ds/fenwicktree/fenwicktree.hpp\"\r\n\r\n/*\r\npolygon \u306F\u4E0D\
    \u7B49\u5F0F aix + biy >= ci \u306B\u3088\u308A\u6E21\u3059\u3002\r\npolygon \u306F\
    \u51F8\u3067\u3001\u4E0D\u7B49\u5F0F\u306E\u5217\u306F\u3001\u8FBA\u304C\u53CD\
    \u6642\u8A08\u56DE\u308A\u306B\u56DE\u308B\u3088\u3046\u306B\u3059\u308B\u3002\
    \r\n(ai, bi) \u306F\u30B3\u30F3\u30B9\u30C8\u30E9\u30AF\u30BF\u306B\u6E21\u3059\
    \u3002\r\nadd_polygon \u3067 ci \u3092\u6E21\u3059\u3002\r\n\u4F7F\u7528\u4F8B\
    \uFF1Ahttps://atcoder.jp/contests/pakencamp-2021-day3/tasks/pakencamp_2021_day3_f\r\
    \n*/\r\ntemplate <typename AbelGroup, bool SMALL>\r\nstruct Point_Add_Polygon_Sum\
    \ {\r\n  using G = typename AbelGroup::value_type;\r\n  G total;\r\n  vc<pi> AB;\r\
    \n  vi X, Y;\r\n  vc<G> WT;\r\n  vvc<ll> poly;\r\n\r\n  Point_Add_Polygon_Sum(vc<pi>\
    \ AB) : total(AbelGroup::unit()), AB(AB) {\r\n    poly.resize(len(AB));\r\n  }\r\
    \n\r\n  void add_query(ll x, ll y, G g) {\r\n    X.eb(x);\r\n    Y.eb(y);\r\n\
    \    WT.eb(g);\r\n    total = AbelGroup::op(total, g);\r\n  }\r\n\r\n  void sum_query(vi\
    \ C) {\r\n    assert(len(C) == len(AB));\r\n    FOR(n, len(AB)) poly[n].eb(C[n]);\r\
    \n  }\r\n\r\n  vc<G> calc() {\r\n    int Q = len(poly[0]);\r\n    int N = len(X);\r\
    \n    vc<G> res(Q, total);\r\n    int K = len(AB);\r\n    FOR(k, K) {\r\n    \
    \  auto [a, b] = AB[(k + K - 1) % K];\r\n      auto [c, d] = AB[k];\r\n      //\
    \ ax+by>=ci \u304B\u3064 cx+dy<cj \u3068\u306A\u308B\u70B9\u306E\u5BC4\u4E0E\u3092\
    \u7B54\u304B\u3089\u5F15\u304F\r\n      vi A(N), B(N);\r\n      FOR(i, N) {\r\n\
    \        A[i] = -(a * X[i] + b * Y[i]);\r\n        B[i] = c * X[i] + d * Y[i];\r\
    \n      }\r\n      vi C(Q), D(Q);\r\n      FOR(q, Q) {\r\n        C[q] = -(poly[(k\
    \ + K - 1) % K][q]) + 1;\r\n        D[q] = poly[k][q];\r\n      }\r\n      //\
    \ A[i]<C[q] \u304B\u3064 B[i]<D[q] \u3068\u306A\u308B i \u306E\u5BC4\u4E0E\u3092\
    \ q \u304B\u3089\u5F15\u304F\r\n      int NA = 0, NB = 0;\r\n      if (!SMALL)\
    \ {\r\n        vi keyA = A, keyB = B;\r\n        UNIQUE(keyA), UNIQUE(keyB);\r\
    \n        for (auto&& x: A) x = LB(keyA, x);\r\n        for (auto&& x: B) x =\
    \ LB(keyB, x);\r\n        for (auto&& x: C) x = LB(keyA, x);\r\n        for (auto&&\
    \ x: D) x = LB(keyB, x);\r\n        NA = len(keyA) + 1;\r\n        NB = len(keyB)\
    \ + 1;\r\n      } else {\r\n        ll minA = MIN(A);\r\n        ll minB = MIN(B);\r\
    \n        for (auto&& x: A) x -= minA;\r\n        for (auto&& x: B) x -= minB;\r\
    \n        for (auto&& x: C) x -= minA;\r\n        for (auto&& x: D) x -= minB;\r\
    \n        NA = MAX(A) + 2;\r\n        NB = MAX(B) + 2;\r\n        for (auto&&\
    \ x: C) x = clamp<ll>(x, 0, NA - 1);\r\n        for (auto&& x: D) x = clamp<ll>(x,\
    \ 0, NB - 1);\r\n      }\r\n      vvc<int> PID(NB + 1);\r\n      vvc<int> QID(NB\
    \ + 1);\r\n      FOR(i, N) PID[B[i]].eb(i);\r\n      FOR(q, Q) QID[D[q]].eb(q);\r\
    \n\r\n      FenwickTree<AbelGroup> bit(NA);\r\n      FOR(b, NB) {\r\n        for\
    \ (auto&& q: QID[b]) {\r\n          G x = bit.sum(C[q]);\r\n          res[q] =\
    \ AbelGroup::op(res[q], AbelGroup::inverse(x));\r\n        }\r\n        for (auto&&\
    \ i: PID[b]) { bit.add(A[i], WT[i]); }\r\n      }\r\n    }\r\n    return res;\r\
    \n  }\r\n};"
  dependsOn:
  - ds/fenwicktree/fenwicktree.hpp
  - alg/monoid/add.hpp
  isVerificationFile: false
  path: ds/offline_query/point_add_polygon_sum.hpp
  requiredBy: []
  timestamp: '2023-01-19 00:13:06+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: ds/offline_query/point_add_polygon_sum.hpp
layout: document
redirect_from:
- /library/ds/offline_query/point_add_polygon_sum.hpp
- /library/ds/offline_query/point_add_polygon_sum.hpp.html
title: ds/offline_query/point_add_polygon_sum.hpp
---
