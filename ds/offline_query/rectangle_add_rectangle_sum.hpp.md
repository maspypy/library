---
data:
  _extendedDependsOn:
  - icon: ':question:'
    path: alg/monoid/add.hpp
    title: alg/monoid/add.hpp
  - icon: ':question:'
    path: ds/fenwicktree/fenwicktree.hpp
    title: ds/fenwicktree/fenwicktree.hpp
  - icon: ':question:'
    path: ds/index_compression.hpp
    title: ds/index_compression.hpp
  - icon: ':x:'
    path: ds/offline_query/coeffient_query_2d.hpp
    title: ds/offline_query/coeffient_query_2d.hpp
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':x:'
    path: test/2_library_checker/data_structure/static_rectangle_add_rectangle_sum.test.cpp
    title: test/2_library_checker/data_structure/static_rectangle_add_rectangle_sum.test.cpp
  - icon: ':x:'
    path: test/3_yukicoder/1490.test.cpp
    title: test/3_yukicoder/1490.test.cpp
  _isVerificationFailed: true
  _pathExtension: hpp
  _verificationStatusIcon: ':x:'
  attributes:
    links: []
  bundledCode: "#line 1 \"ds/index_compression.hpp\"\ntemplate <typename T>\nstruct\
    \ Index_Compression_DISTINCT_SMALL {\n  int mi, ma;\n  vc<T> dat;\n  vc<T> build(vc<int>\
    \ X) {\n    mi = 0, ma = -1;\n    if (!X.empty()) mi = MIN(X), ma = MAX(X);\n\
    \    dat.assign(ma - mi + 2, 0);\n    for (auto& x : X) dat[x - mi + 1]++;\n \
    \   FOR(i, len(dat) - 1) dat[i + 1] += dat[i];\n    for (auto& x : X) {\n    \
    \  x = dat[x - mi]++;\n    }\n    FOR_R(i, 1, len(dat)) dat[i] = dat[i - 1];\n\
    \    dat[0] = 0;\n    return X;\n  }\n  int size() { return len(dat); }\n  int\
    \ operator()(ll x) { return dat[clamp<ll>(x - mi, 0, ma - mi + 1)]; }\n};\n\n\
    template <typename T>\nstruct Index_Compression_SAME_SMALL {\n  int mi, ma;\n\
    \  vc<T> dat;\n  vc<T> build(vc<T> X) {\n    mi = 0, ma = -1;\n    if (!X.empty())\
    \ mi = MIN(X), ma = MAX(X);\n    dat.assign(ma - mi + 2, 0);\n    for (auto& x\
    \ : X) dat[x - mi + 1] = 1;\n    FOR(i, len(dat) - 1) dat[i + 1] += dat[i];\n\
    \    for (auto& x : X) {\n      x = dat[x - mi];\n    }\n    return X;\n  }\n\
    \  int size() { return len(dat); }\n  int operator()(ll x) { return dat[clamp<ll>(x\
    \ - mi, 0, ma - mi + 1)]; }\n};\n\ntemplate <typename T>\nstruct Index_Compression_SAME_LARGE\
    \ {\n  vc<T> dat;\n  vc<int> build(vc<T> X) {\n    vc<int> I = argsort(X);\n \
    \   vc<int> res(len(X));\n    for (auto& i : I) {\n      if (!dat.empty() && dat.back()\
    \ == X[i]) {\n        res[i] = len(dat) - 1;\n      } else {\n        res[i] =\
    \ len(dat);\n        dat.eb(X[i]);\n      }\n    }\n    dat.shrink_to_fit();\n\
    \    return res;\n  }\n  int size() { return len(dat); }\n  int operator()(T x)\
    \ { return LB(dat, x); }\n};\n\ntemplate <typename T>\nstruct Index_Compression_DISTINCT_LARGE\
    \ {\n  vc<T> dat;\n  vc<int> build(vc<T> X) {\n    vc<int> I = argsort(X);\n \
    \   vc<int> res(len(X));\n    for (auto& i : I) {\n      res[i] = len(dat), dat.eb(X[i]);\n\
    \    }\n    dat.shrink_to_fit();\n    return res;\n  }\n  int size() { return\
    \ len(dat); }\n  int operator()(T x) { return LB(dat, x); }\n};\n\ntemplate <typename\
    \ T, bool SMALL>\nusing Index_Compression_DISTINCT =\n    typename std::conditional<SMALL,\
    \ Index_Compression_DISTINCT_SMALL<T>,\n                              Index_Compression_DISTINCT_LARGE<T>>::type;\n\
    template <typename T, bool SMALL>\nusing Index_Compression_SAME =\n    typename\
    \ std::conditional<SMALL, Index_Compression_SAME_SMALL<T>,\n                 \
    \             Index_Compression_SAME_LARGE<T>>::type;\n\n// SAME: [2,3,2] -> [0,1,0]\n\
    // DISTINCT: [2,2,3] -> [0,2,1]\n// build \u3067\u5217\u3092\u5727\u7E2E\u3057\
    \u3066\u304F\u308C\u308B. \u305D\u306E\u3042\u3068\n// (x): lower_bound(X,x) \u3092\
    \u304B\u3048\u3059\ntemplate <typename T, bool SAME, bool SMALL>\nusing Index_Compression\
    \ =\n    typename std::conditional<SAME, Index_Compression_SAME<T, SMALL>,\n \
    \                             Index_Compression_DISTINCT<T, SMALL>>::type;\n#line\
    \ 2 \"alg/monoid/add.hpp\"\n\r\ntemplate <typename E>\r\nstruct Monoid_Add {\r\
    \n  using X = E;\r\n  using value_type = X;\r\n  static constexpr X op(const X\
    \ &x, const X &y) noexcept { return x + y; }\r\n  static constexpr X inverse(const\
    \ X &x) noexcept { return -x; }\r\n  static constexpr X power(const X &x, ll n)\
    \ noexcept { return X(n) * x; }\r\n  static constexpr X unit() { return X(0);\
    \ }\r\n  static constexpr bool commute = true;\r\n};\r\n#line 3 \"ds/fenwicktree/fenwicktree.hpp\"\
    \n\ntemplate <typename Monoid>\nstruct FenwickTree {\n  using G = Monoid;\n  using\
    \ MX = Monoid;\n  using E = typename G::value_type;\n  int n;\n  vector<E> dat;\n\
    \  E total;\n\n  FenwickTree() {}\n  FenwickTree(int n) { build(n); }\n  template\
    \ <typename F>\n  FenwickTree(int n, F f) {\n    build(n, f);\n  }\n  FenwickTree(const\
    \ vc<E>& v) { build(v); }\n\n  void build(int m) {\n    n = m;\n    dat.assign(m,\
    \ G::unit());\n    total = G::unit();\n  }\n  void build(const vc<E>& v) {\n \
    \   build(len(v), [&](int i) -> E { return v[i]; });\n  }\n  template <typename\
    \ F>\n  void build(int m, F f) {\n    n = m;\n    dat.clear();\n    dat.reserve(n);\n\
    \    total = G::unit();\n    FOR(i, n) { dat.eb(f(i)); }\n    for (int i = 1;\
    \ i <= n; ++i) {\n      int j = i + (i & -i);\n      if (j <= n) dat[j - 1] =\
    \ G::op(dat[i - 1], dat[j - 1]);\n    }\n    total = prefix_sum(m);\n  }\n\n \
    \ E prod_all() { return total; }\n  E sum_all() { return total; }\n  E sum(int\
    \ k) { return prefix_sum(k); }\n  E prod(int k) { return prefix_prod(k); }\n \
    \ E prefix_sum(int k) { return prefix_prod(k); }\n  E prefix_prod(int k) {\n \
    \   chmin(k, n);\n    E ret = G::unit();\n    for (; k > 0; k -= k & -k) ret =\
    \ G::op(ret, dat[k - 1]);\n    return ret;\n  }\n  E sum(int L, int R) { return\
    \ prod(L, R); }\n  E prod(int L, int R) {\n    chmax(L, 0), chmin(R, n);\n   \
    \ if (L == 0) return prefix_prod(R);\n    assert(0 <= L && L <= R && R <= n);\n\
    \    E pos = G::unit(), neg = G::unit();\n    while (L < R) { pos = G::op(pos,\
    \ dat[R - 1]), R -= R & -R; }\n    while (R < L) { neg = G::op(neg, dat[L - 1]),\
    \ L -= L & -L; }\n    return G::op(pos, G::inverse(neg));\n  }\n\n  vc<E> get_all()\
    \ {\n    vc<E> res(n);\n    FOR(i, n) res[i] = prod(i, i + 1);\n    return res;\n\
    \  }\n\n  void add(int k, E x) { multiply(k, x); }\n  void multiply(int k, E x)\
    \ {\n    static_assert(G::commute);\n    total = G::op(total, x);\n    for (++k;\
    \ k <= n; k += k & -k) dat[k - 1] = G::op(dat[k - 1], x);\n  }\n  void set(int\
    \ k, E x) { add(k, G::op(G::inverse(prod(k, k + 1)), x)); }\n\n  template <class\
    \ F>\n  int max_right(const F check, int L = 0) {\n    assert(check(G::unit()));\n\
    \    E s = G::unit();\n    int i = L;\n    // 2^k \u9032\u3080\u3068\u30C0\u30E1\
    \n    int k = [&]() {\n      while (1) {\n        if (i % 2 == 1) { s = G::op(s,\
    \ G::inverse(dat[i - 1])), i -= 1; }\n        if (i == 0) { return topbit(n) +\
    \ 1; }\n        int k = lowbit(i) - 1;\n        if (i + (1 << k) > n) return k;\n\
    \        E t = G::op(s, dat[i + (1 << k) - 1]);\n        if (!check(t)) { return\
    \ k; }\n        s = G::op(s, G::inverse(dat[i - 1])), i -= i & -i;\n      }\n\
    \    }();\n    while (k) {\n      --k;\n      if (i + (1 << k) - 1 < len(dat))\
    \ {\n        E t = G::op(s, dat[i + (1 << k) - 1]);\n        if (check(t)) { i\
    \ += (1 << k), s = t; }\n      }\n    }\n    return i;\n  }\n\n  // check(i, x)\n\
    \  template <class F>\n  int max_right_with_index(const F check, int L = 0) {\n\
    \    assert(check(L, G::unit()));\n    E s = G::unit();\n    int i = L;\n    //\
    \ 2^k \u9032\u3080\u3068\u30C0\u30E1\n    int k = [&]() {\n      while (1) {\n\
    \        if (i % 2 == 1) { s = G::op(s, G::inverse(dat[i - 1])), i -= 1; }\n \
    \       if (i == 0) { return topbit(n) + 1; }\n        int k = lowbit(i) - 1;\n\
    \        if (i + (1 << k) > n) return k;\n        E t = G::op(s, dat[i + (1 <<\
    \ k) - 1]);\n        if (!check(i + (1 << k), t)) { return k; }\n        s = G::op(s,\
    \ G::inverse(dat[i - 1])), i -= i & -i;\n      }\n    }();\n    while (k) {\n\
    \      --k;\n      if (i + (1 << k) - 1 < len(dat)) {\n        E t = G::op(s,\
    \ dat[i + (1 << k) - 1]);\n        if (check(i + (1 << k), t)) { i += (1 << k),\
    \ s = t; }\n      }\n    }\n    return i;\n  }\n\n  template <class F>\n  int\
    \ min_left(const F check, int R) {\n    assert(check(G::unit()));\n    E s = G::unit();\n\
    \    int i = R;\n    // false \u306B\u306A\u308B\u3068\u3053\u308D\u307E\u3067\
    \u623B\u308B\n    int k = 0;\n    while (i > 0 && check(s)) {\n      s = G::op(s,\
    \ dat[i - 1]);\n      k = lowbit(i);\n      i -= i & -i;\n    }\n    if (check(s))\
    \ {\n      assert(i == 0);\n      return 0;\n    }\n    // 2^k \u9032\u3080\u3068\
    \ ok \u306B\u306A\u308B\n    // false \u3092\u7DAD\u6301\u3057\u3066\u9032\u3080\
    \n    while (k) {\n      --k;\n      E t = G::op(s, G::inverse(dat[i + (1 << k)\
    \ - 1]));\n      if (!check(t)) { i += (1 << k), s = t; }\n    }\n    return i\
    \ + 1;\n  }\n\n  int kth(E k, int L = 0) {\n    return max_right([&k](E x) ->\
    \ bool { return x <= k; }, L);\n  }\n};\n#line 3 \"ds/offline_query/coeffient_query_2d.hpp\"\
    \n\n// A, B\uFF1A\u5B9A\u6570\n// Sparse Laurent Polynomial f(x,y) \u3092\u4E0E\
    \u3048\u308B\n// [x^py^q] f(x,y)/(1-x)^A(1-y)^B \u3092\u305F\u304F\u3055\u3093\
    \u6C42\u3081\u308B\n// O(AB N logN) \u6642\u9593\ntemplate <int A, int B, typename\
    \ T, bool STATIC>\nstruct Coefficient_Query_2D {\n  struct Mono {\n    using value_type\
    \ = array<T, A * B>;\n    using X = value_type;\n    static X op(X x, X y) {\n\
    \      FOR(i, A * B) x[i] += y[i];\n      return x;\n    }\n    static constexpr\
    \ X unit() { return X{}; }\n    static constexpr bool commute = 1;\n  };\n  vc<tuple<ll,\
    \ ll, T, int>> query;\n\n  int nsum = 0;\n  Coefficient_Query_2D() {}\n  void\
    \ add_query(ll x, ll y, T c) {\n    if (c != T(0)) query.eb(x, y, c, -1);\n  }\n\
    \  void sum_query(ll p, ll q) { query.eb(p, q, 0, nsum++); }\n\n  // \u30AA\u30FC\
    \u30D0\u30FC\u30D5\u30ED\u30FC\u306A\u3069\u306E\u72B6\u6CC1\u6B21\u7B2C\u3067\
    \u66F8\u304D\u63DB\u3048\u308B\n  template <int n>\n  void comb_array(ll x, array<T,\
    \ n>& S) {\n    static_assert(n < 4);\n    if constexpr (n == 1) S = {T(1)};\n\
    \    if constexpr (n == 2) S = {T(1), T(x)};\n    if constexpr (n == 3) S = {T(1),\
    \ T(x), T(x * (x - 1) / 2)};\n  }\n  template <int n>\n  void coef_array(ll b,\
    \ array<T, n>& S) {\n    static_assert(n < 4);\n    // [t^x]t^b(1-t)^{-n} \u3092\
    \ binom(x,k) \u306E\u7DDA\u5F62\u7D50\u5408\u3067\u8868\u3059\u4FC2\u6570\n  \
    \  if constexpr (n == 1) S = {T(1)};\n    if constexpr (n == 2) S = {T(1 - b),\
    \ T(1)};\n    if constexpr (n == 3) S = {T((b - 1) * (b - 2) / 2), T(2 - b), T(1)};\n\
    \  }\n\n  vc<T> ANS;\n  bool done = false;\n  void calc_static(const vc<int>&\
    \ ADD_I, vc<int>& GET_I) {\n    if (ADD_I.empty() || GET_I.empty()) return;\n\
    \    Index_Compression<ll, true, false> IY;\n    {\n      vc<ll> tmp;\n      for\
    \ (int q : ADD_I) {\n        auto [a, b, w, qid] = query[q];\n        if (qid\
    \ == -1) tmp.eb(b);\n      }\n      IY.build(tmp);\n    }\n\n    FenwickTree<Mono>\
    \ bit(len(IY));\n\n    array<T, A> CX;\n    array<T, B> CY;\n    array<T, A *\
    \ B> tmp;\n\n    int ptr = 0;\n    for (int q : GET_I) {\n      auto [a, b, w,\
    \ qid] = query[q];\n      while (ptr < len(ADD_I) && (get<0>(query[ADD_I[ptr]]))\
    \ <= a) {\n        int q = ADD_I[ptr++];\n        auto [a, b, w, qid] = query[q];\n\
    \        coef_array<A>(a, CX);\n        coef_array<B>(b, CY);\n        FOR(i,\
    \ A) FOR(j, B) tmp[B * i + j] = CX[i] * CY[j] * w;\n        bit.add(IY(b), tmp);\n\
    \      }\n      comb_array<A>(a, CX);\n      comb_array<B>(b, CY);\n      // calc\
    \ query\n      tmp = bit.prod(IY(b + 1));\n      T ans = 0;\n      FOR(i, A) FOR(j,\
    \ B) ans += tmp[B * i + j] * CX[i] * CY[j];\n      ANS[qid] += ans;\n    }\n \
    \ }\n\n  vc<T> calc() {\n    assert(!done);\n    done = 1;\n    ANS.assign(nsum,\
    \ 0);\n    int Q = len(query);\n    auto comp = [&](int i, int j) -> bool {\n\
    \      return (get<0>(query[i])) < (get<0>(query[j]));\n    };\n    if (STATIC)\
    \ {\n      vc<int> ADD, GET;\n      FOR(i, Q) { (get<3>(query[i]) == -1 ? ADD\
    \ : GET).eb(i); }\n      sort(all(ADD), comp);\n      sort(all(GET), comp);\n\
    \      calc_static(ADD, GET);\n      return ANS;\n    }\n    auto dfs = [&](auto&\
    \ dfs, int L, int R) -> pair<vc<int>, vc<int>> {\n      vc<int> ADD, GET;\n  \
    \    if (R == L + 1) {\n        (get<3>(query[L]) == -1 ? ADD : GET).eb(L);\n\
    \        return {ADD, GET};\n      }\n      int M = (L + R) / 2;\n      auto [ADD1,\
    \ GET1] = dfs(dfs, L, M);\n      auto [ADD2, GET2] = dfs(dfs, M, R);\n      calc_static(ADD1,\
    \ GET2);\n      ADD.resize(len(ADD1) + len(ADD2));\n      GET.resize(len(GET1)\
    \ + len(GET2));\n      merge(all(ADD1), all(ADD2), ADD.begin(), comp);\n     \
    \ merge(all(GET1), all(GET2), GET.begin(), comp);\n      return {ADD, GET};\n\
    \    };\n    dfs(dfs, 0, Q);\n    return ANS;\n  }\n};\n#line 2 \"ds/offline_query/rectangle_add_rectangle_sum.hpp\"\
    \n\ntemplate <typename T, typename XY>\nstruct Rectangle_Add_Rectangle_Sum {\n\
    \  Coefficient_Query_2D<2, 2, T, XY> CQ;\n  void add_query(XY x1, XY x2, XY y1,\
    \ XY y2, T w) {\n    CQ.add_query(x1, y1, w), CQ.add_query(x1, y2, -w);\n    CQ.add_query(x2,\
    \ y1, -w), CQ.add_query(x2, y2, w);\n  }\n  void sum_query(XY x1, XY x2, XY y1,\
    \ XY y2) {\n    --x1, --y1, --x2, --y2;\n    CQ.sum_query(x1, y1), CQ.sum_query(x1,\
    \ y2);\n    CQ.sum_query(x2, y1), CQ.sum_query(x2, y2);\n  }\n  vc<T> calc() {\n\
    \    vc<T> tmp = CQ.calc();\n    int Q = len(tmp) / 4;\n    vc<T> res(Q);\n  \
    \  FOR(q, Q) {\n      res[q] = tmp[4 * q] - tmp[4 * q + 1] - tmp[4 * q + 2] +\
    \ tmp[4 * q + 3];\n    }\n    return res;\n  }\n};\n"
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
  - ds/index_compression.hpp
  - ds/fenwicktree/fenwicktree.hpp
  - alg/monoid/add.hpp
  isVerificationFile: false
  path: ds/offline_query/rectangle_add_rectangle_sum.hpp
  requiredBy: []
  timestamp: '2025-12-07 20:35:27+09:00'
  verificationStatus: LIBRARY_ALL_WA
  verifiedWith:
  - test/3_yukicoder/1490.test.cpp
  - test/2_library_checker/data_structure/static_rectangle_add_rectangle_sum.test.cpp
documentation_of: ds/offline_query/rectangle_add_rectangle_sum.hpp
layout: document
redirect_from:
- /library/ds/offline_query/rectangle_add_rectangle_sum.hpp
- /library/ds/offline_query/rectangle_add_rectangle_sum.hpp.html
title: ds/offline_query/rectangle_add_rectangle_sum.hpp
---
