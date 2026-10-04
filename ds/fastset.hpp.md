---
data:
  _extendedDependsOn: []
  _extendedRequiredBy:
  - icon: ':warning:'
    path: bigint/redundant_binary_number.hpp
    title: bigint/redundant_binary_number.hpp
  - icon: ':warning:'
    path: ds/incremental_rectangle_union.hpp
    title: ds/incremental_rectangle_union.hpp
  - icon: ':warning:'
    path: ds/intervals.hpp
    title: ds/intervals.hpp
  - icon: ':warning:'
    path: ds/segtree/range_add_make_decreasing.hpp
    title: ds/segtree/range_add_make_decreasing.hpp
  - icon: ':warning:'
    path: ds/segtree/range_add_make_increasing.hpp
    title: ds/segtree/range_add_make_increasing.hpp
  - icon: ':heavy_check_mark:'
    path: ds/segtree/range_assignment_segtree.hpp
    title: ds/segtree/range_assignment_segtree.hpp
  - icon: ':heavy_check_mark:'
    path: ds/segtree/sortable_segtree.hpp
    title: ds/segtree/sortable_segtree.hpp
  - icon: ':heavy_check_mark:'
    path: ds/sortable_array.hpp
    title: ds/sortable_array.hpp
  - icon: ':warning:'
    path: geo/delaunay_triangulation_of_convex_polygon.hpp
    title: geo/delaunay_triangulation_of_convex_polygon.hpp
  - icon: ':heavy_check_mark:'
    path: graph/all_cycle_common_vertices.hpp
    title: graph/all_cycle_common_vertices.hpp
  - icon: ':warning:'
    path: graph/compress_tree.hpp
    title: graph/compress_tree.hpp
  - icon: ':heavy_check_mark:'
    path: graph/ds/incremental_centroid.hpp
    title: graph/ds/incremental_centroid.hpp
  - icon: ':heavy_check_mark:'
    path: graph/toposort.hpp
    title: graph/toposort.hpp
  - icon: ':warning:'
    path: other/cuboid_union_volume.hpp
    title: other/cuboid_union_volume.hpp
  - icon: ':warning:'
    path: string/enumerate_occurrences.hpp
    title: string/enumerate_occurrences.hpp
  - icon: ':heavy_check_mark:'
    path: string/suffix_tree.hpp
    title: string/suffix_tree.hpp
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/1_mytest/all_cycle_common_vertex.test.cpp
    title: test/1_mytest/all_cycle_common_vertex.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/1_mytest/decremental_fastset.test.cpp
    title: test/1_mytest/decremental_fastset.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/1_mytest/range_assign.test.cpp
    title: test/1_mytest/range_assign.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/1_mytest/sortable_array.test.cpp
    title: test/1_mytest/sortable_array.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/2_library_checker/data_structure/predecessor_problem.test.cpp
    title: test/2_library_checker/data_structure/predecessor_problem.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/2_library_checker/data_structure/range_set_range_composite.test.cpp
    title: test/2_library_checker/data_structure/range_set_range_composite.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/2_library_checker/data_structure/sort_segtree.test.cpp
    title: test/2_library_checker/data_structure/sort_segtree.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/2_library_checker/data_structure/sort_segtree_1.test.cpp
    title: test/2_library_checker/data_structure/sort_segtree_1.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/3_yukicoder/2361.test.cpp
    title: test/3_yukicoder/2361.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/3_yukicoder/2809.test.cpp
    title: test/3_yukicoder/2809.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/4_aoj/2251_1.test.cpp
    title: test/4_aoj/2251_1.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/4_aoj/2636.test.cpp
    title: test/4_aoj/2636.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 1 \"ds/fastset.hpp\"\n// 64-ary tree\n// space: (N/63) * u64\n\
    struct FastSet {\n  static constexpr u32 B = 64;\n  int n = 0, log = 0;\n  vvc<u64>\
    \ seg;\n\n  FastSet() {}\n  FastSet(int n) { build(n); }\n\n  int size() { return\
    \ n; }\n\n  void fill_one() {\n    int cur = n;\n    for (auto& vs : seg) {\n\
    \      int p = cur / B, q = cur % B;\n      FOR(i, p) vs[i] = -1ull;\n      if\
    \ (q) vs[p] = full_mask(q);\n      cur = (cur + B - 1) / B;\n    }\n  }\n\n  template\
    \ <typename F>\n  FastSet(int n, F f) {\n    build(n, f);\n  }\n\n  void build(int\
    \ m) {\n    seg.clear();\n    n = m;\n    do {\n      seg.push_back(vc<u64>((m\
    \ + B - 1) / B));\n      m = (m + B - 1) / B;\n    } while (m > 1);\n    log =\
    \ len(seg);\n  }\n  template <typename F>\n  void build(int n, F f) {\n    build(n);\n\
    \    FOR(i, n) { seg[0][i / B] |= u64(bool(f(i))) << (i % B); }\n    FOR(h, log\
    \ - 1) {\n      FOR(i, len(seg[h])) {\n        seg[h + 1][i / B] |= u64(bool(seg[h][i]))\
    \ << (i % B);\n      }\n    }\n  }\n\n  bool operator[](int i) const {\n    assert(0\
    \ <= i && i < n);\n    return seg[0][i / B] >> (i % B) & 1;\n  }\n  void insert(int\
    \ i) {\n    assert(0 <= i && i < n);\n    for (int h = 0; h < log; h++) {\n  \
    \    u64& x = seg[h][i / B];\n      u64 mask = u64(1) << (i % B);\n      if (x\
    \ & mask) return;\n      x |= mask;\n      i /= B;\n    }\n  }\n  void add(int\
    \ i) { insert(i); }\n  void erase(int i) {\n    assert(0 <= i && i < n);\n   \
    \ for (int h = 0; h < log; h++) {\n      u64& x = seg[h][i / B];\n      u64 mask\
    \ = u64(1) << (i % B);\n      if (!(x & mask)) return;\n      x ^= mask;\n   \
    \   if (x) return;\n      i /= B;\n    }\n  }\n  void remove(int i) { erase(i);\
    \ }\n\n  // min[x,n) or n\n  int next(int i) {\n    assert(i <= n);\n    chmax(i,\
    \ 0);\n    for (int h = 0; h < log; h++) {\n      if (i / B == seg[h].size())\
    \ break;\n      u64 d = seg[h][i / B] >> (i % B);\n      if (!d) {\n        i\
    \ = i / B + 1;\n        continue;\n      }\n      i += lowbit(d);\n      for (int\
    \ g = h - 1; g >= 0; g--) {\n        i *= B;\n        i += lowbit(seg[g][i / B]);\n\
    \      }\n      return i;\n    }\n    return n;\n  }\n\n  // max [0,x], or -1\n\
    \  int prev(int i) {\n    assert(i >= -1);\n    if (i >= n) i = n - 1;\n    for\
    \ (int h = 0; h < log; h++) {\n      if (i == -1) break;\n      u64 d = seg[h][i\
    \ / B] << (63 - i % B);\n      if (!d) {\n        i = i / B - 1;\n        continue;\n\
    \      }\n      i -= __builtin_clzll(d);\n      for (int g = h - 1; g >= 0; g--)\
    \ {\n        i *= B;\n        i += topbit(seg[g][i / B]);\n      }\n      return\
    \ i;\n    }\n    return -1;\n  }\n\n  bool any(int l, int r) {\n    assert(0 <=\
    \ l && l <= r && r <= n);\n    return next(l) < r;\n  }\n\n  // [l, r)\n  template\
    \ <typename F>\n  void enumerate(int l, int r, F f) {\n    assert(0 <= l && l\
    \ <= r && r <= n);\n    for (int x = next(l); x < r; x = next(x + 1)) f(x);\n\
    \  }\n\n  void reset() {\n    enumerate(0, n, [&](int i) -> void { erase(i); });\n\
    \  }\n\n  string to_string() {\n    string s(n, '?');\n    for (int i = 0; i <\
    \ n; ++i) s[i] = ((*this)[i] ? '1' : '0');\n    return s;\n  }\n};\n"
  code: "// 64-ary tree\n// space: (N/63) * u64\nstruct FastSet {\n  static constexpr\
    \ u32 B = 64;\n  int n = 0, log = 0;\n  vvc<u64> seg;\n\n  FastSet() {}\n  FastSet(int\
    \ n) { build(n); }\n\n  int size() { return n; }\n\n  void fill_one() {\n    int\
    \ cur = n;\n    for (auto& vs : seg) {\n      int p = cur / B, q = cur % B;\n\
    \      FOR(i, p) vs[i] = -1ull;\n      if (q) vs[p] = full_mask(q);\n      cur\
    \ = (cur + B - 1) / B;\n    }\n  }\n\n  template <typename F>\n  FastSet(int n,\
    \ F f) {\n    build(n, f);\n  }\n\n  void build(int m) {\n    seg.clear();\n \
    \   n = m;\n    do {\n      seg.push_back(vc<u64>((m + B - 1) / B));\n      m\
    \ = (m + B - 1) / B;\n    } while (m > 1);\n    log = len(seg);\n  }\n  template\
    \ <typename F>\n  void build(int n, F f) {\n    build(n);\n    FOR(i, n) { seg[0][i\
    \ / B] |= u64(bool(f(i))) << (i % B); }\n    FOR(h, log - 1) {\n      FOR(i, len(seg[h]))\
    \ {\n        seg[h + 1][i / B] |= u64(bool(seg[h][i])) << (i % B);\n      }\n\
    \    }\n  }\n\n  bool operator[](int i) const {\n    assert(0 <= i && i < n);\n\
    \    return seg[0][i / B] >> (i % B) & 1;\n  }\n  void insert(int i) {\n    assert(0\
    \ <= i && i < n);\n    for (int h = 0; h < log; h++) {\n      u64& x = seg[h][i\
    \ / B];\n      u64 mask = u64(1) << (i % B);\n      if (x & mask) return;\n  \
    \    x |= mask;\n      i /= B;\n    }\n  }\n  void add(int i) { insert(i); }\n\
    \  void erase(int i) {\n    assert(0 <= i && i < n);\n    for (int h = 0; h <\
    \ log; h++) {\n      u64& x = seg[h][i / B];\n      u64 mask = u64(1) << (i %\
    \ B);\n      if (!(x & mask)) return;\n      x ^= mask;\n      if (x) return;\n\
    \      i /= B;\n    }\n  }\n  void remove(int i) { erase(i); }\n\n  // min[x,n)\
    \ or n\n  int next(int i) {\n    assert(i <= n);\n    chmax(i, 0);\n    for (int\
    \ h = 0; h < log; h++) {\n      if (i / B == seg[h].size()) break;\n      u64\
    \ d = seg[h][i / B] >> (i % B);\n      if (!d) {\n        i = i / B + 1;\n   \
    \     continue;\n      }\n      i += lowbit(d);\n      for (int g = h - 1; g >=\
    \ 0; g--) {\n        i *= B;\n        i += lowbit(seg[g][i / B]);\n      }\n \
    \     return i;\n    }\n    return n;\n  }\n\n  // max [0,x], or -1\n  int prev(int\
    \ i) {\n    assert(i >= -1);\n    if (i >= n) i = n - 1;\n    for (int h = 0;\
    \ h < log; h++) {\n      if (i == -1) break;\n      u64 d = seg[h][i / B] << (63\
    \ - i % B);\n      if (!d) {\n        i = i / B - 1;\n        continue;\n    \
    \  }\n      i -= __builtin_clzll(d);\n      for (int g = h - 1; g >= 0; g--) {\n\
    \        i *= B;\n        i += topbit(seg[g][i / B]);\n      }\n      return i;\n\
    \    }\n    return -1;\n  }\n\n  bool any(int l, int r) {\n    assert(0 <= l &&\
    \ l <= r && r <= n);\n    return next(l) < r;\n  }\n\n  // [l, r)\n  template\
    \ <typename F>\n  void enumerate(int l, int r, F f) {\n    assert(0 <= l && l\
    \ <= r && r <= n);\n    for (int x = next(l); x < r; x = next(x + 1)) f(x);\n\
    \  }\n\n  void reset() {\n    enumerate(0, n, [&](int i) -> void { erase(i); });\n\
    \  }\n\n  string to_string() {\n    string s(n, '?');\n    for (int i = 0; i <\
    \ n; ++i) s[i] = ((*this)[i] ? '1' : '0');\n    return s;\n  }\n};\n"
  dependsOn: []
  isVerificationFile: false
  path: ds/fastset.hpp
  requiredBy:
  - graph/all_cycle_common_vertices.hpp
  - graph/compress_tree.hpp
  - graph/ds/incremental_centroid.hpp
  - graph/toposort.hpp
  - ds/intervals.hpp
  - ds/sortable_array.hpp
  - ds/incremental_rectangle_union.hpp
  - ds/segtree/range_assignment_segtree.hpp
  - ds/segtree/range_add_make_increasing.hpp
  - ds/segtree/range_add_make_decreasing.hpp
  - ds/segtree/sortable_segtree.hpp
  - other/cuboid_union_volume.hpp
  - geo/delaunay_triangulation_of_convex_polygon.hpp
  - string/suffix_tree.hpp
  - string/enumerate_occurrences.hpp
  - bigint/redundant_binary_number.hpp
  timestamp: '2026-10-04 23:53:53+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/1_mytest/all_cycle_common_vertex.test.cpp
  - test/1_mytest/decremental_fastset.test.cpp
  - test/1_mytest/sortable_array.test.cpp
  - test/1_mytest/range_assign.test.cpp
  - test/3_yukicoder/2809.test.cpp
  - test/3_yukicoder/2361.test.cpp
  - test/2_library_checker/data_structure/sort_segtree_1.test.cpp
  - test/2_library_checker/data_structure/predecessor_problem.test.cpp
  - test/2_library_checker/data_structure/range_set_range_composite.test.cpp
  - test/2_library_checker/data_structure/sort_segtree.test.cpp
  - test/4_aoj/2251_1.test.cpp
  - test/4_aoj/2636.test.cpp
documentation_of: ds/fastset.hpp
layout: document
redirect_from:
- /library/ds/fastset.hpp
- /library/ds/fastset.hpp.html
title: ds/fastset.hpp
---
