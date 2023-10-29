---
data:
  _extendedDependsOn:
  - icon: ':question:'
    path: alg/monoid/add.hpp
    title: alg/monoid/add.hpp
  - icon: ':question:'
    path: ds/fenwicktree/fenwicktree.hpp
    title: ds/fenwicktree/fenwicktree.hpp
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/mytest/fenwick_raq.test.cpp
    title: test/mytest/fenwick_raq.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links:
    - https://codeforces.com/contest/860/submission/228355081
    - https://maspypy.github.io/library/test/mytest/fenwick_raq.test.cpp
  bundledCode: "#line 1 \"ds/fenwicktree/fenwicktree_range_add.hpp\"\n\n#line 2 \"\
    alg/monoid/add.hpp\"\n\r\ntemplate <typename X>\r\nstruct Monoid_Add {\r\n  using\
    \ value_type = X;\r\n  static constexpr X op(const X &x, const X &y) noexcept\
    \ { return x + y; }\r\n  static constexpr X inverse(const X &x) noexcept { return\
    \ -x; }\r\n  static constexpr X power(const X &x, ll n) noexcept { return X(n)\
    \ * x; }\r\n  static constexpr X unit() { return X(0); }\r\n  static constexpr\
    \ bool commute = true;\r\n};\r\n#line 3 \"ds/fenwicktree/fenwicktree.hpp\"\n\n\
    template <typename Monoid>\nstruct FenwickTree {\n  using G = Monoid;\n  using\
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
    \ -> bool { return x <= k; });\n  }\n};\n#line 3 \"ds/fenwicktree/fenwicktree_range_add.hpp\"\
    \n\n// \u9045\u5EF6\u30BB\u30B0\u6728\u3088\u308A 4 \uFF5E 5 \u500D\u9AD8\u901F\
    \uFF1F\n// https://maspypy.github.io/library/test/mytest/fenwick_raq.test.cpp\n\
    // https://codeforces.com/contest/860/submission/228355081\ntemplate <typename\
    \ AbelGroup>\nstruct FenwickTree_Range_Add {\n  using G = AbelGroup;\n  using\
    \ E = typename AbelGroup::value_type;\n  int n;\n  FenwickTree<G> bit0;\n  FenwickTree<G>\
    \ bit1;\n\n  FenwickTree_Range_Add() {}\n  FenwickTree_Range_Add(int n) { build(n);\
    \ }\n  template <typename F>\n  FenwickTree_Range_Add(int n, F f) {\n    build(n,\
    \ f);\n  }\n  FenwickTree_Range_Add(const vc<E>& v) { build(v); }\n\n  void build(int\
    \ m) {\n    n = m;\n    bit0.build(n), bit1.build(n);\n  }\n  void build(const\
    \ vc<E>& v) {\n    build(len(v), [&](int i) -> E { return v[i]; });\n  }\n  template\
    \ <typename F>\n  void build(int m, F f) {\n    n = m;\n    bit0.build(m, f);\n\
    \    bit1.build(m);\n  }\n\n  void add_at(int i, E val) { bit0.add(i, val); }\n\
    \n  void add(int L, int R, E val) {\n    bit0.add(L, G::power(val, -L));\n   \
    \ bit0.add(R, G::power(val, R));\n    bit1.add(L, val);\n    bit1.add(R, G::inverse(val));\n\
    \  }\n\n  E prod(int L, int R) {\n    E prod_R = G::op(G::power(bit1.prod(R),\
    \ R), bit0.prod(R));\n    E prod_L = G::op(G::power(bit1.prod(L), L), bit0.prod(L));\n\
    \    return G::op(G::inverse(prod_L), prod_R);\n  }\n};\n"
  code: "\n#include \"ds/fenwicktree/fenwicktree.hpp\"\n\n// \u9045\u5EF6\u30BB\u30B0\
    \u6728\u3088\u308A 4 \uFF5E 5 \u500D\u9AD8\u901F\uFF1F\n// https://maspypy.github.io/library/test/mytest/fenwick_raq.test.cpp\n\
    // https://codeforces.com/contest/860/submission/228355081\ntemplate <typename\
    \ AbelGroup>\nstruct FenwickTree_Range_Add {\n  using G = AbelGroup;\n  using\
    \ E = typename AbelGroup::value_type;\n  int n;\n  FenwickTree<G> bit0;\n  FenwickTree<G>\
    \ bit1;\n\n  FenwickTree_Range_Add() {}\n  FenwickTree_Range_Add(int n) { build(n);\
    \ }\n  template <typename F>\n  FenwickTree_Range_Add(int n, F f) {\n    build(n,\
    \ f);\n  }\n  FenwickTree_Range_Add(const vc<E>& v) { build(v); }\n\n  void build(int\
    \ m) {\n    n = m;\n    bit0.build(n), bit1.build(n);\n  }\n  void build(const\
    \ vc<E>& v) {\n    build(len(v), [&](int i) -> E { return v[i]; });\n  }\n  template\
    \ <typename F>\n  void build(int m, F f) {\n    n = m;\n    bit0.build(m, f);\n\
    \    bit1.build(m);\n  }\n\n  void add_at(int i, E val) { bit0.add(i, val); }\n\
    \n  void add(int L, int R, E val) {\n    bit0.add(L, G::power(val, -L));\n   \
    \ bit0.add(R, G::power(val, R));\n    bit1.add(L, val);\n    bit1.add(R, G::inverse(val));\n\
    \  }\n\n  E prod(int L, int R) {\n    E prod_R = G::op(G::power(bit1.prod(R),\
    \ R), bit0.prod(R));\n    E prod_L = G::op(G::power(bit1.prod(L), L), bit0.prod(L));\n\
    \    return G::op(G::inverse(prod_L), prod_R);\n  }\n};"
  dependsOn:
  - ds/fenwicktree/fenwicktree.hpp
  - alg/monoid/add.hpp
  isVerificationFile: false
  path: ds/fenwicktree/fenwicktree_range_add.hpp
  requiredBy: []
  timestamp: '2023-10-16 08:46:25+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/mytest/fenwick_raq.test.cpp
documentation_of: ds/fenwicktree/fenwicktree_range_add.hpp
layout: document
redirect_from:
- /library/ds/fenwicktree/fenwicktree_range_add.hpp
- /library/ds/fenwicktree/fenwicktree_range_add.hpp.html
title: ds/fenwicktree/fenwicktree_range_add.hpp
---
