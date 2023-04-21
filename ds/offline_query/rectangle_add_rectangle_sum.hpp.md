---
data:
  _extendedDependsOn:
  - icon: ':question:'
    path: alg/monoid/add.hpp
    title: alg/monoid/add.hpp
  - icon: ':question:'
    path: ds/fenwicktree/fenwicktree.hpp
    title: ds/fenwicktree/fenwicktree.hpp
  - icon: ':heavy_check_mark:'
    path: ds/offline_query/coeffient_query_2d.hpp
    title: ds/offline_query/coeffient_query_2d.hpp
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
    \ -> bool { return x <= k; });\n  }\n};\n#line 2 \"ds/offline_query/coeffient_query_2d.hpp\"\
    \n\n// A, B\uFF1A\u5B9A\u6570\n// Sparse Laurent Polynomial f(x,y) \u3092\u4E0E\
    \u3048\u308B\n// [x^py^q] f(x,y)/(1-x)^A(1-y)^B \u3092\u305F\u304F\u3055\u3093\
    \u6C42\u3081\u308B\n// O(AB N logN) \u6642\u9593\ntemplate <int A, int B, typename\
    \ T, typename XY>\nstruct Coefficient_Query_2D {\n  struct Mono {\n    using value_type\
    \ = array<T, A * B>;\n    using X = value_type;\n    static X op(X x, X y) {\n\
    \      FOR(i, A * B) x[i] += y[i];\n      return x;\n    }\n    static constexpr\
    \ X unit() { return X{}; }\n    static constexpr bool commute = 1;\n  };\n\n \
    \ vc<tuple<XY, XY, T>> F;\n  vc<pair<XY, XY>> QUERY;\n\n  Coefficient_Query_2D()\
    \ {}\n  void add_query(XY x, XY y, T c) { F.eb(x, y, c); }\n  void sum_query(XY\
    \ p, XY q) { QUERY.eb(p, q); }\n\n  // div_fact\uFF1A\u6700\u5F8C\u306B (A-1)!(B-1)!\
    \ \u3067\u5272\u308B\u304B\u3069\u3046\u304B\u3002\u3075\u3064\u3046\u306F\u5272\
    \u308B\u3002\n  vc<T> calc(bool div_fact = true) {\n    // \u52A0\u7B97\u3059\u308B\
    \u70B9\u306E x \u306B\u3064\u3044\u3066\u5EA7\u5727\n    sort(all(F),\n      \
    \   [&](auto& a, auto& b) -> bool { return get<0>(a) < get<0>(b); });\n    vc<XY>\
    \ keyX;\n    keyX.reserve(len(F));\n    for (auto&& [a, b, c]: F) {\n      if\
    \ (keyX.empty() || keyX.back() != a) keyX.eb(a);\n      a = len(keyX) - 1;\n \
    \   }\n    keyX.shrink_to_fit();\n    // y \u6607\u9806\u306B\u30AF\u30A8\u30EA\
    \u51E6\u7406\u3059\u308B\n    const int Q = len(QUERY);\n    vc<int> I(Q);\n \
    \   iota(all(I), 0);\n    sort(all(I),\n         [&](auto& a, auto& b) -> bool\
    \ { return QUERY[a].se < QUERY[b].se; });\n    sort(all(F),\n         [&](auto&\
    \ a, auto& b) -> bool { return get<1>(a) < get<1>(b); });\n    FenwickTree<Mono>\
    \ bit(len(keyX));\n    vc<T> res(Q);\n    int ptr = 0;\n    for (auto&& qid: I)\
    \ {\n      auto [p, q] = QUERY[qid];\n      // y <= q \u3068\u306A\u308B F \u306E\
    \u52A0\u7B97\n      while (ptr < len(F) && get<1>(F[ptr]) <= q) {\n        auto&\
    \ [ia, b, w] = F[ptr++];\n        XY a = keyX[ia];\n        // w(p-a+1)...(p-a+A-1)(q-b+1)...(q-b+B-1)\
    \ \u3092 p,q \u306E\u591A\u9805\u5F0F\u3068\u3057\u3066\n        vc<T> f(A), g(B);\n\
    \        f[0] = w, g[0] = 1;\n        FOR(i, A - 1) { FOR_R(j, i + 1) f[j + 1]\
    \ += f[j] * T(-a + 1 + i); }\n        FOR(i, B - 1) { FOR_R(j, i + 1) g[j + 1]\
    \ += g[j] * T(-b + 1 + i); }\n        reverse(all(f)), reverse(all(g));\n    \
    \    array<T, A * B> G{};\n        FOR(i, A) FOR(j, B) G[B * i + j] = f[i] * g[j];\n\
    \        bit.add(ia, G);\n      }\n      auto SM = bit.sum(UB(keyX, p));\n   \
    \   T sm = 0, pow_p = 1;\n      FOR(i, A) {\n        T prod = pow_p;\n       \
    \ FOR(j, B) { sm += prod * SM[B * i + j], prod *= T(q); }\n        pow_p *= T(p);\n\
    \      }\n      res[qid] = sm;\n    }\n    if (div_fact && (A >= 3 || B >= 3))\
    \ {\n      T cf = T(1);\n      FOR(a, 1, A) cf *= T(a);\n      FOR(b, 1, B) cf\
    \ *= T(b);\n      for (auto&& x: res) x /= cf;\n    }\n    return res;\n  }\n\
    };\n#line 2 \"ds/offline_query/rectangle_add_rectangle_sum.hpp\"\n\ntemplate <typename\
    \ T, typename XY>\nstruct Rectangle_Add_Rectangle_Sum {\n  Coefficient_Query_2D<2,\
    \ 2, T, XY> CQ;\n  void add_query(XY x1, XY x2, XY y1, XY y2, T w) {\n    CQ.add_query(x1,\
    \ y1, w), CQ.add_query(x1, y2, -w);\n    CQ.add_query(x2, y1, -w), CQ.add_query(x2,\
    \ y2, w);\n  }\n  void sum_query(XY x1, XY x2, XY y1, XY y2) {\n    --x1, --y1,\
    \ --x2, --y2;\n    CQ.sum_query(x1, y1), CQ.sum_query(x1, y2);\n    CQ.sum_query(x2,\
    \ y1), CQ.sum_query(x2, y2);\n  }\n  vc<T> calc() {\n    vc<T> tmp = CQ.calc();\n\
    \    int Q = len(tmp) / 4;\n    vc<T> res(Q);\n    FOR(q, Q) {\n      res[q] =\
    \ tmp[4 * q] - tmp[4 * q + 1] - tmp[4 * q + 2] + tmp[4 * q + 3];\n    }\n    return\
    \ res;\n  }\n};\n"
  code: "#include \"ds/offline_query/coeffient_query_2d.hpp\"\n\ntemplate <typename\
    \ T, typename XY>\nstruct Rectangle_Add_Rectangle_Sum {\n  Coefficient_Query_2D<2,\
    \ 2, T, XY> CQ;\n  void add_query(XY x1, XY x2, XY y1, XY y2, T w) {\n    CQ.add_query(x1,\
    \ y1, w), CQ.add_query(x1, y2, -w);\n    CQ.add_query(x2, y1, -w), CQ.add_query(x2,\
    \ y2, w);\n  }\n  void sum_query(XY x1, XY x2, XY y1, XY y2) {\n    --x1, --y1,\
    \ --x2, --y2;\n    CQ.sum_query(x1, y1), CQ.sum_query(x1, y2);\n    CQ.sum_query(x2,\
    \ y1), CQ.sum_query(x2, y2);\n  }\n  vc<T> calc() {\n    vc<T> tmp = CQ.calc();\n\
    \    int Q = len(tmp) / 4;\n    vc<T> res(Q);\n    FOR(q, Q) {\n      res[q] =\
    \ tmp[4 * q] - tmp[4 * q + 1] - tmp[4 * q + 2] + tmp[4 * q + 3];\n    }\n    return\
    \ res;\n  }\n};"
  dependsOn:
  - ds/offline_query/coeffient_query_2d.hpp
  - ds/fenwicktree/fenwicktree.hpp
  - alg/monoid/add.hpp
  isVerificationFile: false
  path: ds/offline_query/rectangle_add_rectangle_sum.hpp
  requiredBy: []
  timestamp: '2023-01-22 14:33:14+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/library_checker/datastructure/static_rectangle_add_rectangle_sum.test.cpp
  - test/yukicoder/1490.test.cpp
documentation_of: ds/offline_query/rectangle_add_rectangle_sum.hpp
layout: document
redirect_from:
- /library/ds/offline_query/rectangle_add_rectangle_sum.hpp
- /library/ds/offline_query/rectangle_add_rectangle_sum.hpp.html
title: ds/offline_query/rectangle_add_rectangle_sum.hpp
---
