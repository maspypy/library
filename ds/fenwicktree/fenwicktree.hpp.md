---
data:
  _extendedDependsOn:
  - icon: ':question:'
    path: alg/monoid/add.hpp
    title: alg/monoid/add.hpp
  _extendedRequiredBy:
  - icon: ':heavy_check_mark:'
    path: ds/offline_query/coeffient_query_2d.hpp
    title: ds/offline_query/coeffient_query_2d.hpp
  - icon: ':warning:'
    path: ds/offline_query/point_add_polygon_sum.hpp
    title: ds/offline_query/point_add_polygon_sum.hpp
  - icon: ':heavy_check_mark:'
    path: ds/offline_query/point_add_rectangle_sum.hpp
    title: ds/offline_query/point_add_rectangle_sum.hpp
  - icon: ':heavy_check_mark:'
    path: ds/offline_query/rectangle_add_point_sum.hpp
    title: ds/offline_query/rectangle_add_point_sum.hpp
  - icon: ':heavy_check_mark:'
    path: ds/offline_query/rectangle_add_rectangle_sum.hpp
    title: ds/offline_query/rectangle_add_rectangle_sum.hpp
  - icon: ':heavy_check_mark:'
    path: ds/range_add_range_sum.hpp
    title: ds/range_add_range_sum.hpp
  - icon: ':heavy_check_mark:'
    path: graph/ds/contour_sum.hpp
    title: graph/ds/contour_sum.hpp
  - icon: ':question:'
    path: graph/ds/tree_abelgroup.hpp
    title: graph/ds/tree_abelgroup.hpp
  - icon: ':heavy_check_mark:'
    path: seq/inversion.hpp
    title: seq/inversion.hpp
  - icon: ':question:'
    path: seq/inversion_rotate.hpp
    title: seq/inversion_rotate.hpp
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/aoj/ALDS1_2_A.test.cpp
    title: test/aoj/ALDS1_2_A.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/aoj/ALDS1_5.test.cpp
    title: test/aoj/ALDS1_5.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/aoj/DSL_2_E.test.cpp
    title: test/aoj/DSL_2_E.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/aoj/DSL_2_G.test.cpp
    title: test/aoj/DSL_2_G.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/atcoder/abc190f.test.cpp
    title: test/atcoder/abc190f.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/library_checker/datastructure/point_add_range_sum.test.cpp
    title: test/library_checker/datastructure/point_add_range_sum.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/library_checker/datastructure/range_kth_smallest_pbs.test.cpp
    title: test/library_checker/datastructure/range_kth_smallest_pbs.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/library_checker/datastructure/rectangle_sum_sweep.test.cpp
    title: test/library_checker/datastructure/rectangle_sum_sweep.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/library_checker/datastructure/static_range_inversions_mo.test.cpp
    title: test/library_checker/datastructure/static_range_inversions_mo.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/library_checker/datastructure/static_range_inversions_mo2.test.cpp
    title: test/library_checker/datastructure/static_range_inversions_mo2.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/library_checker/datastructure/static_rectangle_add_rectangle_sum.test.cpp
    title: test/library_checker/datastructure/static_rectangle_add_rectangle_sum.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/library_checker/datastructure/static_rectangle_add_rectangle_sum2.test.cpp
    title: test/library_checker/datastructure/static_rectangle_add_rectangle_sum2.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/library_checker/datastructure/vertex_add_path_sum_abelgroup.test.cpp
    title: test/library_checker/datastructure/vertex_add_path_sum_abelgroup.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/library_checker/datastructure/vertex_add_subtree_sum_dsu.test.cpp
    title: test/library_checker/datastructure/vertex_add_subtree_sum_dsu.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/library_checker/graph/verted_add_contour_sum.test.cpp
    title: test/library_checker/graph/verted_add_contour_sum.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/mytest/rect_add_pt_sum.test.cpp
    title: test/mytest/rect_add_pt_sum.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/yukicoder/1038.test.cpp
    title: test/yukicoder/1038.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/yukicoder/1270.test.cpp
    title: test/yukicoder/1270.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/yukicoder/1311.test.cpp
    title: test/yukicoder/1311.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/yukicoder/1326.test.cpp
    title: test/yukicoder/1326.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/yukicoder/1490.test.cpp
    title: test/yukicoder/1490.test.cpp
  - icon: ':x:'
    path: test/yukicoder/1641.test.cpp
    title: test/yukicoder/1641.test.cpp
  - icon: ':x:'
    path: test/yukicoder/1838.test.cpp
    title: test/yukicoder/1838.test.cpp
  - icon: ':x:'
    path: test/yukicoder/1874.test.cpp
    title: test/yukicoder/1874.test.cpp
  - icon: ':x:'
    path: test/yukicoder/924.test.cpp
    title: test/yukicoder/924.test.cpp
  _isVerificationFailed: true
  _pathExtension: hpp
  _verificationStatusIcon: ':question:'
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
    \ }\n  E prefix_prod(int k) {\n    E ret = G::unit();\n    for (; k > 0; k -=\
    \ k & -k) ret = G::op(ret, dat[k - 1]);\n    return ret;\n  }\n  E sum(int L,\
    \ int R) { return prod(L, R); }\n  E prod(int L, int R) {\n    if (L == 0) return\
    \ prefix_prod(R);\n    assert(0 <= L && L <= R && R <= n);\n    E pos = G::unit(),\
    \ neg = G::unit();\n    while (L < R) { pos = G::op(pos, dat[R - 1]), R -= R &\
    \ -R; }\n    while (R < L) { neg = G::op(neg, dat[L - 1]), L -= L & -L; }\n  \
    \  return G::op(pos, G::inverse(neg));\n  }\n\n  void add(int k, E x) { multiply(k,\
    \ x); }\n  void multiply(int k, E x) {\n    static_assert(G::commute);\n    total\
    \ = G::op(total, x);\n    for (++k; k <= n; k += k & -k) dat[k - 1] = G::op(dat[k\
    \ - 1], x);\n  }\n\n  template <class F>\n  int max_right(const F check) {\n \
    \   assert(check(G::unit()));\n    int i = 0;\n    E s = G::unit();\n    int k\
    \ = 1;\n    while (2 * k <= n) k *= 2;\n    while (k) {\n      E t = G::op(s,\
    \ dat[i + k - 1]);\n      if (check(t)) { i += k, s = t; }\n      k >>= 1;\n \
    \   }\n    return i;\n  }\n\n  int find_kth(E k) {\n    return max_right([&k](E\
    \ x) -> bool { return x <= k; });\n  }\n};\n"
  code: "#pragma once\n#include \"alg/monoid/add.hpp\"\n\ntemplate <typename Monoid>\n\
    struct FenwickTree {\n  using G = Monoid;\n  using E = typename G::value_type;\n\
    \  int n;\n  vector<E> dat;\n  E total;\n\n  FenwickTree() {}\n  FenwickTree(int\
    \ n) { build(n); }\n  template <typename F>\n  FenwickTree(int n, F f) {\n   \
    \ build(n, f);\n  }\n  FenwickTree(const vc<E>& v) { build(v); }\n\n  void build(int\
    \ m) {\n    n = m;\n    dat.assign(m, G::unit());\n    total = G::unit();\n  }\n\
    \  void build(const vc<E>& v) {\n    build(len(v), [&](int i) -> E { return v[i];\
    \ });\n  }\n  template <typename F>\n  void build(int m, F f) {\n    n = m;\n\
    \    dat.clear();\n    dat.reserve(n);\n    total = G::unit();\n    FOR(i, n)\
    \ { dat.eb(f(i)); }\n    for (int i = 1; i <= n; ++i) {\n      int j = i + (i\
    \ & -i);\n      if (j <= n) dat[j - 1] = G::op(dat[i - 1], dat[j - 1]);\n    }\n\
    \    total = prefix_sum(m);\n  }\n\n  E prod_all() { return total; }\n  E sum_all()\
    \ { return total; }\n  E sum(int k) { return prefix_sum(k); }\n  E prod(int k)\
    \ { return prefix_prod(k); }\n  E prefix_sum(int k) { return prefix_prod(k); }\n\
    \  E prefix_prod(int k) {\n    E ret = G::unit();\n    for (; k > 0; k -= k &\
    \ -k) ret = G::op(ret, dat[k - 1]);\n    return ret;\n  }\n  E sum(int L, int\
    \ R) { return prod(L, R); }\n  E prod(int L, int R) {\n    if (L == 0) return\
    \ prefix_prod(R);\n    assert(0 <= L && L <= R && R <= n);\n    E pos = G::unit(),\
    \ neg = G::unit();\n    while (L < R) { pos = G::op(pos, dat[R - 1]), R -= R &\
    \ -R; }\n    while (R < L) { neg = G::op(neg, dat[L - 1]), L -= L & -L; }\n  \
    \  return G::op(pos, G::inverse(neg));\n  }\n\n  void add(int k, E x) { multiply(k,\
    \ x); }\n  void multiply(int k, E x) {\n    static_assert(G::commute);\n    total\
    \ = G::op(total, x);\n    for (++k; k <= n; k += k & -k) dat[k - 1] = G::op(dat[k\
    \ - 1], x);\n  }\n\n  template <class F>\n  int max_right(const F check) {\n \
    \   assert(check(G::unit()));\n    int i = 0;\n    E s = G::unit();\n    int k\
    \ = 1;\n    while (2 * k <= n) k *= 2;\n    while (k) {\n      E t = G::op(s,\
    \ dat[i + k - 1]);\n      if (check(t)) { i += k, s = t; }\n      k >>= 1;\n \
    \   }\n    return i;\n  }\n\n  int find_kth(E k) {\n    return max_right([&k](E\
    \ x) -> bool { return x <= k; });\n  }\n};\n"
  dependsOn:
  - alg/monoid/add.hpp
  isVerificationFile: false
  path: ds/fenwicktree/fenwicktree.hpp
  requiredBy:
  - seq/inversion.hpp
  - seq/inversion_rotate.hpp
  - ds/offline_query/coeffient_query_2d.hpp
  - ds/offline_query/rectangle_add_point_sum.hpp
  - ds/offline_query/rectangle_add_rectangle_sum.hpp
  - ds/offline_query/point_add_rectangle_sum.hpp
  - ds/offline_query/point_add_polygon_sum.hpp
  - ds/range_add_range_sum.hpp
  - graph/ds/tree_abelgroup.hpp
  - graph/ds/contour_sum.hpp
  timestamp: '2022-12-04 04:38:35+09:00'
  verificationStatus: LIBRARY_SOME_WA
  verifiedWith:
  - test/yukicoder/1311.test.cpp
  - test/yukicoder/1490.test.cpp
  - test/yukicoder/1874.test.cpp
  - test/yukicoder/1838.test.cpp
  - test/yukicoder/1326.test.cpp
  - test/yukicoder/1038.test.cpp
  - test/yukicoder/1270.test.cpp
  - test/yukicoder/924.test.cpp
  - test/yukicoder/1641.test.cpp
  - test/mytest/rect_add_pt_sum.test.cpp
  - test/library_checker/datastructure/static_range_inversions_mo2.test.cpp
  - test/library_checker/datastructure/vertex_add_path_sum_abelgroup.test.cpp
  - test/library_checker/datastructure/static_range_inversions_mo.test.cpp
  - test/library_checker/datastructure/point_add_range_sum.test.cpp
  - test/library_checker/datastructure/range_kth_smallest_pbs.test.cpp
  - test/library_checker/datastructure/vertex_add_subtree_sum_dsu.test.cpp
  - test/library_checker/datastructure/rectangle_sum_sweep.test.cpp
  - test/library_checker/datastructure/static_rectangle_add_rectangle_sum2.test.cpp
  - test/library_checker/datastructure/static_rectangle_add_rectangle_sum.test.cpp
  - test/library_checker/graph/verted_add_contour_sum.test.cpp
  - test/atcoder/abc190f.test.cpp
  - test/aoj/DSL_2_E.test.cpp
  - test/aoj/ALDS1_2_A.test.cpp
  - test/aoj/DSL_2_G.test.cpp
  - test/aoj/ALDS1_5.test.cpp
documentation_of: ds/fenwicktree/fenwicktree.hpp
layout: document
redirect_from:
- /library/ds/fenwicktree/fenwicktree.hpp
- /library/ds/fenwicktree/fenwicktree.hpp.html
title: ds/fenwicktree/fenwicktree.hpp
---
