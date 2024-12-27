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
  - icon: ':x:'
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
  - icon: ':question:'
    path: ds/segtree/sortable_segtree.hpp
    title: ds/segtree/sortable_segtree.hpp
  - icon: ':question:'
    path: ds/sortable_array.hpp
    title: ds/sortable_array.hpp
  - icon: ':x:'
    path: graph/ds/incremental_centroid.hpp
    title: graph/ds/incremental_centroid.hpp
  - icon: ':x:'
    path: graph/toposort.hpp
    title: graph/toposort.hpp
  - icon: ':warning:'
    path: other/cuboid_union_volume.hpp
    title: other/cuboid_union_volume.hpp
  _extendedVerifiedWith:
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
    path: test/3_yukicoder/2809.test.cpp
    title: test/3_yukicoder/2809.test.cpp
  - icon: ':x:'
    path: test/4_aoj/2251_1.test.cpp
    title: test/4_aoj/2251_1.test.cpp
  - icon: ':x:'
    path: test/4_aoj/2636.test.cpp
    title: test/4_aoj/2636.test.cpp
  - icon: ':x:'
    path: test/5_atcoder/abc217e.test.cpp
    title: test/5_atcoder/abc217e.test.cpp
  - icon: ':x:'
    path: test/5_atcoder/abc223d.test.cpp
    title: test/5_atcoder/abc223d.test.cpp
  - icon: ':x:'
    path: test/5_atcoder/abc237g.test.cpp
    title: test/5_atcoder/abc237g.test.cpp
  - icon: ':x:'
    path: test/5_atcoder/abc237g1.test.cpp
    title: test/5_atcoder/abc237g1.test.cpp
  - icon: ':x:'
    path: test/5_atcoder/abc256d.test.cpp
    title: test/5_atcoder/abc256d.test.cpp
  - icon: ':x:'
    path: test/5_atcoder/abc256ex.test.cpp
    title: test/5_atcoder/abc256ex.test.cpp
  - icon: ':x:'
    path: test/5_atcoder/abc256ex2.test.cpp
    title: test/5_atcoder/abc256ex2.test.cpp
  _isVerificationFailed: true
  _pathExtension: hpp
  _verificationStatusIcon: ':question:'
  attributes:
    links: []
  bundledCode: "#line 2 \"ds/fastset.hpp\"\n\r\n// 64-ary tree\r\n// space: (N/63)\
    \ * u64\r\nstruct FastSet {\r\n  static constexpr u32 B = 64;\r\n  int n, log;\r\
    \n  vvc<u64> seg;\r\n\r\n  FastSet() {}\r\n  FastSet(int n) { build(n); }\r\n\r\
    \n  int size() { return n; }\r\n\r\n  template <typename F>\r\n  FastSet(int n,\
    \ F f) {\r\n    build(n, f);\r\n  }\r\n\r\n  void build(int m) {\r\n    seg.clear();\r\
    \n    n = m;\r\n    do {\r\n      seg.push_back(vc<u64>((m + B - 1) / B));\r\n\
    \      m = (m + B - 1) / B;\r\n    } while (m > 1);\r\n    log = len(seg);\r\n\
    \  }\r\n  template <typename F>\r\n  void build(int n, F f) {\r\n    build(n);\r\
    \n    FOR(i, n) { seg[0][i / B] |= u64(f(i)) << (i % B); }\r\n    FOR(h, log -\
    \ 1) {\r\n      FOR(i, len(seg[h])) { seg[h + 1][i / B] |= u64(bool(seg[h][i]))\
    \ << (i % B); }\r\n    }\r\n  }\r\n\r\n  bool operator[](int i) const { return\
    \ seg[0][i / B] >> (i % B) & 1; }\r\n  void insert(int i) {\r\n    assert(0 <=\
    \ i && i < n);\r\n    for (int h = 0; h < log; h++) { seg[h][i / B] |= u64(1)\
    \ << (i % B), i /= B; }\r\n  }\r\n  void add(int i) { insert(i); }\r\n  void erase(int\
    \ i) {\r\n    assert(0 <= i && i < n);\r\n    u64 x = 0;\r\n    for (int h = 0;\
    \ h < log; h++) {\r\n      seg[h][i / B] &= ~(u64(1) << (i % B));\r\n      seg[h][i\
    \ / B] |= x << (i % B);\r\n      x = bool(seg[h][i / B]);\r\n      i /= B;\r\n\
    \    }\r\n  }\r\n  void remove(int i) { erase(i); }\r\n\r\n  // min[x,n) or n\r\
    \n  int next(int i) {\r\n    assert(i <= n);\r\n    chmax(i, 0);\r\n    for (int\
    \ h = 0; h < log; h++) {\r\n      if (i / B == seg[h].size()) break;\r\n     \
    \ u64 d = seg[h][i / B] >> (i % B);\r\n      if (!d) {\r\n        i = i / B +\
    \ 1;\r\n        continue;\r\n      }\r\n      i += lowbit(d);\r\n      for (int\
    \ g = h - 1; g >= 0; g--) {\r\n        i *= B;\r\n        i += lowbit(seg[g][i\
    \ / B]);\r\n      }\r\n      return i;\r\n    }\r\n    return n;\r\n  }\r\n\r\n\
    \  // max [0,x], or -1\r\n  int prev(int i) {\r\n    assert(i >= -1);\r\n    if\
    \ (i >= n) i = n - 1;\r\n    for (int h = 0; h < log; h++) {\r\n      if (i ==\
    \ -1) break;\r\n      u64 d = seg[h][i / B] << (63 - i % B);\r\n      if (!d)\
    \ {\r\n        i = i / B - 1;\r\n        continue;\r\n      }\r\n      i -= __builtin_clzll(d);\r\
    \n      for (int g = h - 1; g >= 0; g--) {\r\n        i *= B;\r\n        i +=\
    \ topbit(seg[g][i / B]);\r\n      }\r\n      return i;\r\n    }\r\n    return\
    \ -1;\r\n  }\r\n\r\n  bool any(int l, int r) { return next(l) < r; }\r\n\r\n \
    \ // [l, r)\r\n  template <typename F>\r\n  void enumerate(int l, int r, F f)\
    \ {\r\n    for (int x = next(l); x < r; x = next(x + 1)) f(x);\r\n  }\r\n\r\n\
    \  string to_string() {\r\n    string s(n, '?');\r\n    for (int i = 0; i < n;\
    \ ++i) s[i] = ((*this)[i] ? '1' : '0');\r\n    return s;\r\n  }\r\n};\n"
  code: "#pragma once\r\n\r\n// 64-ary tree\r\n// space: (N/63) * u64\r\nstruct FastSet\
    \ {\r\n  static constexpr u32 B = 64;\r\n  int n, log;\r\n  vvc<u64> seg;\r\n\r\
    \n  FastSet() {}\r\n  FastSet(int n) { build(n); }\r\n\r\n  int size() { return\
    \ n; }\r\n\r\n  template <typename F>\r\n  FastSet(int n, F f) {\r\n    build(n,\
    \ f);\r\n  }\r\n\r\n  void build(int m) {\r\n    seg.clear();\r\n    n = m;\r\n\
    \    do {\r\n      seg.push_back(vc<u64>((m + B - 1) / B));\r\n      m = (m +\
    \ B - 1) / B;\r\n    } while (m > 1);\r\n    log = len(seg);\r\n  }\r\n  template\
    \ <typename F>\r\n  void build(int n, F f) {\r\n    build(n);\r\n    FOR(i, n)\
    \ { seg[0][i / B] |= u64(f(i)) << (i % B); }\r\n    FOR(h, log - 1) {\r\n    \
    \  FOR(i, len(seg[h])) { seg[h + 1][i / B] |= u64(bool(seg[h][i])) << (i % B);\
    \ }\r\n    }\r\n  }\r\n\r\n  bool operator[](int i) const { return seg[0][i /\
    \ B] >> (i % B) & 1; }\r\n  void insert(int i) {\r\n    assert(0 <= i && i < n);\r\
    \n    for (int h = 0; h < log; h++) { seg[h][i / B] |= u64(1) << (i % B), i /=\
    \ B; }\r\n  }\r\n  void add(int i) { insert(i); }\r\n  void erase(int i) {\r\n\
    \    assert(0 <= i && i < n);\r\n    u64 x = 0;\r\n    for (int h = 0; h < log;\
    \ h++) {\r\n      seg[h][i / B] &= ~(u64(1) << (i % B));\r\n      seg[h][i / B]\
    \ |= x << (i % B);\r\n      x = bool(seg[h][i / B]);\r\n      i /= B;\r\n    }\r\
    \n  }\r\n  void remove(int i) { erase(i); }\r\n\r\n  // min[x,n) or n\r\n  int\
    \ next(int i) {\r\n    assert(i <= n);\r\n    chmax(i, 0);\r\n    for (int h =\
    \ 0; h < log; h++) {\r\n      if (i / B == seg[h].size()) break;\r\n      u64\
    \ d = seg[h][i / B] >> (i % B);\r\n      if (!d) {\r\n        i = i / B + 1;\r\
    \n        continue;\r\n      }\r\n      i += lowbit(d);\r\n      for (int g =\
    \ h - 1; g >= 0; g--) {\r\n        i *= B;\r\n        i += lowbit(seg[g][i / B]);\r\
    \n      }\r\n      return i;\r\n    }\r\n    return n;\r\n  }\r\n\r\n  // max\
    \ [0,x], or -1\r\n  int prev(int i) {\r\n    assert(i >= -1);\r\n    if (i >=\
    \ n) i = n - 1;\r\n    for (int h = 0; h < log; h++) {\r\n      if (i == -1) break;\r\
    \n      u64 d = seg[h][i / B] << (63 - i % B);\r\n      if (!d) {\r\n        i\
    \ = i / B - 1;\r\n        continue;\r\n      }\r\n      i -= __builtin_clzll(d);\r\
    \n      for (int g = h - 1; g >= 0; g--) {\r\n        i *= B;\r\n        i +=\
    \ topbit(seg[g][i / B]);\r\n      }\r\n      return i;\r\n    }\r\n    return\
    \ -1;\r\n  }\r\n\r\n  bool any(int l, int r) { return next(l) < r; }\r\n\r\n \
    \ // [l, r)\r\n  template <typename F>\r\n  void enumerate(int l, int r, F f)\
    \ {\r\n    for (int x = next(l); x < r; x = next(x + 1)) f(x);\r\n  }\r\n\r\n\
    \  string to_string() {\r\n    string s(n, '?');\r\n    for (int i = 0; i < n;\
    \ ++i) s[i] = ((*this)[i] ? '1' : '0');\r\n    return s;\r\n  }\r\n};"
  dependsOn: []
  isVerificationFile: false
  path: ds/fastset.hpp
  requiredBy:
  - bigint/redundant_binary_number.hpp
  - ds/incremental_rectangle_union.hpp
  - ds/intervals.hpp
  - ds/sortable_array.hpp
  - ds/segtree/range_add_make_decreasing.hpp
  - ds/segtree/sortable_segtree.hpp
  - ds/segtree/range_assignment_segtree.hpp
  - ds/segtree/range_add_make_increasing.hpp
  - other/cuboid_union_volume.hpp
  - graph/ds/incremental_centroid.hpp
  - graph/toposort.hpp
  timestamp: '2024-10-28 19:23:56+09:00'
  verificationStatus: LIBRARY_SOME_WA
  verifiedWith:
  - test/3_yukicoder/2809.test.cpp
  - test/4_aoj/2636.test.cpp
  - test/4_aoj/2251_1.test.cpp
  - test/5_atcoder/abc237g.test.cpp
  - test/5_atcoder/abc256ex2.test.cpp
  - test/5_atcoder/abc256ex.test.cpp
  - test/5_atcoder/abc237g1.test.cpp
  - test/5_atcoder/abc223d.test.cpp
  - test/5_atcoder/abc256d.test.cpp
  - test/5_atcoder/abc217e.test.cpp
  - test/1_mytest/range_assign.test.cpp
  - test/1_mytest/sortable_array.test.cpp
  - test/2_library_checker/data_structure/sort_segtree.test.cpp
  - test/2_library_checker/data_structure/predecessor_problem.test.cpp
  - test/2_library_checker/data_structure/sort_segtree_1.test.cpp
  - test/2_library_checker/data_structure/range_set_range_composite.test.cpp
documentation_of: ds/fastset.hpp
layout: document
redirect_from:
- /library/ds/fastset.hpp
- /library/ds/fastset.hpp.html
title: ds/fastset.hpp
---
