---
data:
  _extendedDependsOn: []
  _extendedRequiredBy:
  - icon: ':warning:'
    path: ds/segtree/range_add_make_decreasing.hpp
    title: ds/segtree/range_add_make_decreasing.hpp
  - icon: ':warning:'
    path: ds/segtree/range_add_make_increasing.hpp
    title: ds/segtree/range_add_make_increasing.hpp
  - icon: ':heavy_check_mark:'
    path: geo/range_closest_pair_query.hpp
    title: geo/range_closest_pair_query.hpp
  - icon: ':question:'
    path: graph/ds/dual_tree_monoid.hpp
    title: graph/ds/dual_tree_monoid.hpp
  - icon: ':question:'
    path: graph/minimum_spanning_tree.hpp
    title: graph/minimum_spanning_tree.hpp
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/1_mytest/range_closest_pair.test.cpp
    title: test/1_mytest/range_closest_pair.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/2_library_checker/data_structure/range_affine_point_add.test.cpp
    title: test/2_library_checker/data_structure/range_affine_point_add.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/2_library_checker/tree/mst.test.cpp
    title: test/2_library_checker/tree/mst.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/3_yukicoder/1524.test.cpp
    title: test/3_yukicoder/1524.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/3_yukicoder/2498.test.cpp
    title: test/3_yukicoder/2498.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/3_yukicoder/913.test.cpp
    title: test/3_yukicoder/913.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/4_aoj/DSL_2_D.test.cpp
    title: test/4_aoj/DSL_2_D.test.cpp
  - icon: ':x:'
    path: test/4_aoj/GRL_2_A.test.cpp
    title: test/4_aoj/GRL_2_A.test.cpp
  _isVerificationFailed: true
  _pathExtension: hpp
  _verificationStatusIcon: ':question:'
  attributes:
    links: []
  bundledCode: "#line 2 \"ds/segtree/dual_segtree.hpp\"\n\ntemplate <typename Monoid>\n\
    struct Dual_SegTree {\n  using MA = Monoid;\n  using A = typename MA::value_type;\n\
    \  int n, log, size;\n  vc<A> laz;\n\n  Dual_SegTree() : Dual_SegTree(0) {}\n\
    \  Dual_SegTree(int n) {\n    build(n, [&](int i) -> A { return MA::unit(); });\n\
    \  }\n  template <typename F>\n  Dual_SegTree(int n, F f) {\n    build(n, f);\n\
    \  }\n\n  template <typename F>\n  void build(int m, F f) {\n    n = m;\n    log\
    \ = 1;\n    while ((1 << log) < n) ++log;\n    size = 1 << log;\n    laz.assign(size\
    \ << 1, MA::unit());\n    FOR(i, n) laz[size + i] = f(i);\n  }\n  void build(int\
    \ n) {\n    build(n, [&](int i) -> A { return MA::unit(); });\n  }\n\n  A get(int\
    \ p) {\n    assert(0 <= p && p < n);\n    p += size;\n    for (int i = log; i\
    \ >= 1; i--) push(p >> i);\n    return laz[p];\n  }\n\n  vc<A> get_all() {\n \
    \   FOR(i, size) push(i);\n    return {laz.begin() + size, laz.begin() + size\
    \ + n};\n  }\n\n  void set(int p, A x) {\n    get(p);\n    laz[p + size] = x;\n\
    \  }\n\n  void apply(int l, int r, const A& a) {\n    assert(0 <= l && l <= r\
    \ && r <= n);\n    if (l == r) return;\n    l += size, r += size;\n    if (!MA::commute)\
    \ {\n      for (int i = log; i >= 1; i--) {\n        if (((l >> i) << i) != l)\
    \ push(l >> i);\n        if (((r >> i) << i) != r) push((r - 1) >> i);\n     \
    \ }\n    }\n    while (l < r) {\n      if (l & 1) all_apply(l++, a);\n      if\
    \ (r & 1) all_apply(--r, a);\n      l >>= 1, r >>= 1;\n    }\n  }\n\nprivate:\n\
    \  void push(int k) {\n    if (laz[k] == MA::unit()) return;\n    all_apply(2\
    \ * k, laz[k]), all_apply(2 * k + 1, laz[k]);\n    laz[k] = MA::unit();\n  }\n\
    \  void all_apply(int k, A a) { laz[k] = MA::op(laz[k], a); }\n};\n"
  code: "#pragma once\n\ntemplate <typename Monoid>\nstruct Dual_SegTree {\n  using\
    \ MA = Monoid;\n  using A = typename MA::value_type;\n  int n, log, size;\n  vc<A>\
    \ laz;\n\n  Dual_SegTree() : Dual_SegTree(0) {}\n  Dual_SegTree(int n) {\n   \
    \ build(n, [&](int i) -> A { return MA::unit(); });\n  }\n  template <typename\
    \ F>\n  Dual_SegTree(int n, F f) {\n    build(n, f);\n  }\n\n  template <typename\
    \ F>\n  void build(int m, F f) {\n    n = m;\n    log = 1;\n    while ((1 << log)\
    \ < n) ++log;\n    size = 1 << log;\n    laz.assign(size << 1, MA::unit());\n\
    \    FOR(i, n) laz[size + i] = f(i);\n  }\n  void build(int n) {\n    build(n,\
    \ [&](int i) -> A { return MA::unit(); });\n  }\n\n  A get(int p) {\n    assert(0\
    \ <= p && p < n);\n    p += size;\n    for (int i = log; i >= 1; i--) push(p >>\
    \ i);\n    return laz[p];\n  }\n\n  vc<A> get_all() {\n    FOR(i, size) push(i);\n\
    \    return {laz.begin() + size, laz.begin() + size + n};\n  }\n\n  void set(int\
    \ p, A x) {\n    get(p);\n    laz[p + size] = x;\n  }\n\n  void apply(int l, int\
    \ r, const A& a) {\n    assert(0 <= l && l <= r && r <= n);\n    if (l == r) return;\n\
    \    l += size, r += size;\n    if (!MA::commute) {\n      for (int i = log; i\
    \ >= 1; i--) {\n        if (((l >> i) << i) != l) push(l >> i);\n        if (((r\
    \ >> i) << i) != r) push((r - 1) >> i);\n      }\n    }\n    while (l < r) {\n\
    \      if (l & 1) all_apply(l++, a);\n      if (r & 1) all_apply(--r, a);\n  \
    \    l >>= 1, r >>= 1;\n    }\n  }\n\nprivate:\n  void push(int k) {\n    if (laz[k]\
    \ == MA::unit()) return;\n    all_apply(2 * k, laz[k]), all_apply(2 * k + 1, laz[k]);\n\
    \    laz[k] = MA::unit();\n  }\n  void all_apply(int k, A a) { laz[k] = MA::op(laz[k],\
    \ a); }\n};\n"
  dependsOn: []
  isVerificationFile: false
  path: ds/segtree/dual_segtree.hpp
  requiredBy:
  - ds/segtree/range_add_make_decreasing.hpp
  - ds/segtree/range_add_make_increasing.hpp
  - graph/ds/dual_tree_monoid.hpp
  - graph/minimum_spanning_tree.hpp
  - geo/range_closest_pair_query.hpp
  timestamp: '2024-10-12 22:46:11+09:00'
  verificationStatus: LIBRARY_SOME_WA
  verifiedWith:
  - test/3_yukicoder/1524.test.cpp
  - test/3_yukicoder/2498.test.cpp
  - test/3_yukicoder/913.test.cpp
  - test/4_aoj/DSL_2_D.test.cpp
  - test/4_aoj/GRL_2_A.test.cpp
  - test/2_library_checker/data_structure/range_affine_point_add.test.cpp
  - test/2_library_checker/tree/mst.test.cpp
  - test/1_mytest/range_closest_pair.test.cpp
documentation_of: ds/segtree/dual_segtree.hpp
layout: document
redirect_from:
- /library/ds/segtree/dual_segtree.hpp
- /library/ds/segtree/dual_segtree.hpp.html
title: ds/segtree/dual_segtree.hpp
---
