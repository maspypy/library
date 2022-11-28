---
data:
  _extendedDependsOn:
  - icon: ':question:'
    path: alg/monoid/add.hpp
    title: alg/monoid/add.hpp
  - icon: ':heavy_check_mark:'
    path: ds/fenwick.hpp
    title: ds/fenwick.hpp
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
    \ }\r\n  static constexpr bool commute = true;\r\n};\r\n#line 3 \"ds/fenwick.hpp\"\
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
    \  void debug() { print(\"fenwick\", dat); }\n};\n#line 2 \"ds/query/point_add_polygon_sum.hpp\"\
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
  code: "#include \"ds/fenwick.hpp\"\r\n\r\n/*\r\npolygon \u306F\u4E0D\u7B49\u5F0F\
    \ aix + biy >= ci \u306B\u3088\u308A\u6E21\u3059\u3002\r\npolygon \u306F\u51F8\
    \u3067\u3001\u4E0D\u7B49\u5F0F\u306E\u5217\u306F\u3001\u8FBA\u304C\u53CD\u6642\
    \u8A08\u56DE\u308A\u306B\u56DE\u308B\u3088\u3046\u306B\u3059\u308B\u3002\r\n(ai,\
    \ bi) \u306F\u30B3\u30F3\u30B9\u30C8\u30E9\u30AF\u30BF\u306B\u6E21\u3059\u3002\
    \r\nadd_polygon \u3067 ci \u3092\u6E21\u3059\u3002\r\n\u4F7F\u7528\u4F8B\uFF1A\
    https://atcoder.jp/contests/pakencamp-2021-day3/tasks/pakencamp_2021_day3_f\r\n\
    */\r\ntemplate <typename AbelGroup, bool SMALL>\r\nstruct Point_Add_Polygon_Sum\
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
  - ds/fenwick.hpp
  - alg/monoid/add.hpp
  isVerificationFile: false
  path: ds/query/point_add_polygon_sum.hpp
  requiredBy: []
  timestamp: '2022-11-28 14:51:10+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: ds/query/point_add_polygon_sum.hpp
layout: document
redirect_from:
- /library/ds/query/point_add_polygon_sum.hpp
- /library/ds/query/point_add_polygon_sum.hpp.html
title: ds/query/point_add_polygon_sum.hpp
---
