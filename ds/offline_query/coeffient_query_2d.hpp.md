---
data:
  _extendedDependsOn:
  - icon: ':question:'
    path: alg/monoid/add.hpp
    title: alg/monoid/add.hpp
  - icon: ':question:'
    path: ds/fenwick/fenwick.hpp
    title: ds/fenwick/fenwick.hpp
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':x:'
    path: test/library_checker/datastructure/static_rectangle_add_rectangle_sum2.test.cpp
    title: test/library_checker/datastructure/static_rectangle_add_rectangle_sum2.test.cpp
  _isVerificationFailed: true
  _pathExtension: hpp
  _verificationStatusIcon: ':x:'
  attributes:
    links: []
  bundledCode: "#line 2 \"alg/monoid/add.hpp\"\n\r\ntemplate <typename X>\r\nstruct\
    \ Monoid_Add {\r\n  using value_type = X;\r\n  static constexpr X op(const X &x,\
    \ const X &y) noexcept { return x + y; }\r\n  static constexpr X inverse(const\
    \ X &x) noexcept { return -x; }\r\n  static constexpr X power(const X &x, ll n)\
    \ noexcept { return X(n) * x; }\r\n  static constexpr X unit() { return X(0);\
    \ }\r\n  static constexpr bool commute = true;\r\n};\r\n#line 3 \"ds/fenwick/fenwick.hpp\"\
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
    \  void debug() { print(\"fenwick\", dat); }\n};\n#line 2 \"ds/offline_query/coeffient_query_2d.hpp\"\
    \n\n// A, B\uFF1A\u5B9A\u6570\n// Sparse Laurent Polynomial f(x,y) \u3092\u4E0E\
    \u3048\u308B\n// [x^py^q] f(x,y)/(1-x)^A(1-y)^B \u3092\u305F\u304F\u3055\u3093\
    \u6C42\u3081\u308B\n// O(AB N logN) \u6642\u9593\ntemplate <int A, int B, typename\
    \ T>\nstruct Coefficient_Query_2D {\n  struct Mono {\n    using value_type = array<T,\
    \ A * B>;\n    using X = value_type;\n    static X op(X x, X y) {\n      FOR(i,\
    \ A * B) x[i] += y[i];\n      return x;\n    }\n    static constexpr X unit()\
    \ { return X{}; }\n    static constexpr bool commute = 1;\n  };\n\n  vc<tuple<ll,\
    \ ll, T>> F;\n  vc<pi> QUERY;\n\n  Coefficient_Query_2D() {}\n  void add(ll x,\
    \ ll y, T c) { F.eb(x, y, c); }\n  void query(ll p, ll q) { QUERY.eb(p, q); }\n\
    \n  // \u6700\u5F8C\u306B (A-1)!(B-1)! \u3067\u5272\u308B\u304B\u3069\u3046\u304B\
    \u3002\u3075\u3064\u3046\u306F\u5272\u308B\u3002\n  vc<T> calc(bool div_fact =\
    \ true) {\n    // \u52A0\u7B97\u3059\u308B\u70B9\u306E x \u306B\u3064\u3044\u3066\
    \u5EA7\u5727\n    sort(all(F),\n         [&](auto& a, auto& b) -> bool { return\
    \ get<0>(a) < get<0>(b); });\n    vi keyX;\n    keyX.reserve(len(F));\n    for\
    \ (auto&& [a, b, c]: F) {\n      if (keyX.empty() || keyX.back() != a) keyX.eb(a);\n\
    \      a = len(keyX) - 1;\n    }\n    keyX.shrink_to_fit();\n\n    // y \u6607\
    \u9806\u306B\u30AF\u30A8\u30EA\u51E6\u7406\u3059\u308B\n    const int Q = len(QUERY);\n\
    \    vc<int> I(Q);\n    iota(all(I), 0);\n    sort(all(I),\n         [&](auto&\
    \ a, auto& b) -> bool { return QUERY[a].se < QUERY[b].se; });\n    sort(all(F),\n\
    \         [&](auto& a, auto& b) -> bool { return get<1>(a) < get<1>(b); });\n\n\
    \    FenwickTree<Mono> bit(len(keyX));\n\n    vc<T> res(Q);\n    int ptr = 0;\n\
    \    for (auto&& qid: I) {\n      auto [p, q] = QUERY[qid];\n      // y <= q \u3068\
    \u306A\u308B F \u306E\u52A0\u7B97\n      while (ptr < len(F) && get<1>(F[ptr])\
    \ <= q) {\n        auto& [ia, b, w] = F[ptr++];\n        ll a = keyX[ia];\n  \
    \      // w(p-a+1)...(p-a+A-1)(q-b+1)...(q-b+B-1) \u3092 p,q \u306E\u591A\u9805\
    \u5F0F\u3068\u3057\u3066\n        vc<T> f(A), g(B);\n        f[0] = w, g[0] =\
    \ 1;\n        FOR(i, A - 1) { FOR_R(j, i + 1) f[j + 1] += f[j] * T(-a + 1 + i);\
    \ }\n        FOR(i, B - 1) { FOR_R(j, i + 1) g[j + 1] += g[j] * T(-b + 1 + i);\
    \ }\n        reverse(all(f));\n        reverse(all(g));\n        array<T, A *\
    \ B> G{};\n        FOR(i, A) FOR(j, B) G[B * i + j] = f[i] * g[j];\n        bit.add(ia,\
    \ G);\n      }\n      auto SM = bit.sum(UB(keyX, p));\n      T sm = 0;\n     \
    \ T pow_p = 1;\n      FOR(i, A) {\n        T prod = pow_p;\n        FOR(j, B)\
    \ {\n          sm += prod * SM[B * i + j];\n          prod *= T(q);\n        }\n\
    \        pow_p *= T(p);\n      }\n      res[qid] = sm;\n    }\n    if (div_fact)\
    \ {\n      T cf = T(1);\n      FOR(a, 1, A) cf *= T(a);\n      FOR(b, 1, B) cf\
    \ *= T(b);\n      for (auto&& x: res) x /= cf;\n    }\n    return res;\n  }\n\
    };\n"
  code: "#include \"ds/fenwick/fenwick.hpp\"\n\n// A, B\uFF1A\u5B9A\u6570\n// Sparse\
    \ Laurent Polynomial f(x,y) \u3092\u4E0E\u3048\u308B\n// [x^py^q] f(x,y)/(1-x)^A(1-y)^B\
    \ \u3092\u305F\u304F\u3055\u3093\u6C42\u3081\u308B\n// O(AB N logN) \u6642\u9593\
    \ntemplate <int A, int B, typename T>\nstruct Coefficient_Query_2D {\n  struct\
    \ Mono {\n    using value_type = array<T, A * B>;\n    using X = value_type;\n\
    \    static X op(X x, X y) {\n      FOR(i, A * B) x[i] += y[i];\n      return\
    \ x;\n    }\n    static constexpr X unit() { return X{}; }\n    static constexpr\
    \ bool commute = 1;\n  };\n\n  vc<tuple<ll, ll, T>> F;\n  vc<pi> QUERY;\n\n  Coefficient_Query_2D()\
    \ {}\n  void add(ll x, ll y, T c) { F.eb(x, y, c); }\n  void query(ll p, ll q)\
    \ { QUERY.eb(p, q); }\n\n  // \u6700\u5F8C\u306B (A-1)!(B-1)! \u3067\u5272\u308B\
    \u304B\u3069\u3046\u304B\u3002\u3075\u3064\u3046\u306F\u5272\u308B\u3002\n  vc<T>\
    \ calc(bool div_fact = true) {\n    // \u52A0\u7B97\u3059\u308B\u70B9\u306E x\
    \ \u306B\u3064\u3044\u3066\u5EA7\u5727\n    sort(all(F),\n         [&](auto& a,\
    \ auto& b) -> bool { return get<0>(a) < get<0>(b); });\n    vi keyX;\n    keyX.reserve(len(F));\n\
    \    for (auto&& [a, b, c]: F) {\n      if (keyX.empty() || keyX.back() != a)\
    \ keyX.eb(a);\n      a = len(keyX) - 1;\n    }\n    keyX.shrink_to_fit();\n\n\
    \    // y \u6607\u9806\u306B\u30AF\u30A8\u30EA\u51E6\u7406\u3059\u308B\n    const\
    \ int Q = len(QUERY);\n    vc<int> I(Q);\n    iota(all(I), 0);\n    sort(all(I),\n\
    \         [&](auto& a, auto& b) -> bool { return QUERY[a].se < QUERY[b].se; });\n\
    \    sort(all(F),\n         [&](auto& a, auto& b) -> bool { return get<1>(a) <\
    \ get<1>(b); });\n\n    FenwickTree<Mono> bit(len(keyX));\n\n    vc<T> res(Q);\n\
    \    int ptr = 0;\n    for (auto&& qid: I) {\n      auto [p, q] = QUERY[qid];\n\
    \      // y <= q \u3068\u306A\u308B F \u306E\u52A0\u7B97\n      while (ptr < len(F)\
    \ && get<1>(F[ptr]) <= q) {\n        auto& [ia, b, w] = F[ptr++];\n        ll\
    \ a = keyX[ia];\n        // w(p-a+1)...(p-a+A-1)(q-b+1)...(q-b+B-1) \u3092 p,q\
    \ \u306E\u591A\u9805\u5F0F\u3068\u3057\u3066\n        vc<T> f(A), g(B);\n    \
    \    f[0] = w, g[0] = 1;\n        FOR(i, A - 1) { FOR_R(j, i + 1) f[j + 1] +=\
    \ f[j] * T(-a + 1 + i); }\n        FOR(i, B - 1) { FOR_R(j, i + 1) g[j + 1] +=\
    \ g[j] * T(-b + 1 + i); }\n        reverse(all(f));\n        reverse(all(g));\n\
    \        array<T, A * B> G{};\n        FOR(i, A) FOR(j, B) G[B * i + j] = f[i]\
    \ * g[j];\n        bit.add(ia, G);\n      }\n      auto SM = bit.sum(UB(keyX,\
    \ p));\n      T sm = 0;\n      T pow_p = 1;\n      FOR(i, A) {\n        T prod\
    \ = pow_p;\n        FOR(j, B) {\n          sm += prod * SM[B * i + j];\n     \
    \     prod *= T(q);\n        }\n        pow_p *= T(p);\n      }\n      res[qid]\
    \ = sm;\n    }\n    if (div_fact) {\n      T cf = T(1);\n      FOR(a, 1, A) cf\
    \ *= T(a);\n      FOR(b, 1, B) cf *= T(b);\n      for (auto&& x: res) x /= cf;\n\
    \    }\n    return res;\n  }\n};"
  dependsOn:
  - ds/fenwick/fenwick.hpp
  - alg/monoid/add.hpp
  isVerificationFile: false
  path: ds/offline_query/coeffient_query_2d.hpp
  requiredBy: []
  timestamp: '2022-12-02 19:49:10+09:00'
  verificationStatus: LIBRARY_ALL_WA
  verifiedWith:
  - test/library_checker/datastructure/static_rectangle_add_rectangle_sum2.test.cpp
documentation_of: ds/offline_query/coeffient_query_2d.hpp
layout: document
redirect_from:
- /library/ds/offline_query/coeffient_query_2d.hpp
- /library/ds/offline_query/coeffient_query_2d.hpp.html
title: ds/offline_query/coeffient_query_2d.hpp
---
