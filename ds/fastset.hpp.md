---
data:
  _extendedDependsOn:
  - icon: ':question:'
    path: other/bit.hpp
    title: other/bit.hpp
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
  - icon: ':x:'
    path: graph/all_cycle_common_vertices.hpp
    title: graph/all_cycle_common_vertices.hpp
  - icon: ':warning:'
    path: graph/compress_tree.hpp
    title: graph/compress_tree.hpp
  - icon: ':heavy_check_mark:'
    path: graph/ds/incremental_centroid.hpp
    title: graph/ds/incremental_centroid.hpp
  - icon: ':question:'
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
  - icon: ':x:'
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
  _isVerificationFailed: true
  _pathExtension: hpp
  _verificationStatusIcon: ':question:'
  attributes:
    links: []
  bundledCode: "#line 1 \"other/bit.hpp\"\n\nint popcnt(int x) { return __builtin_popcount(x);\
    \ }\nint popcnt(u32 x) { return __builtin_popcount(x); }\nint popcnt(ll x) { return\
    \ __builtin_popcountll(x); }\nint popcnt(u64 x) { return __builtin_popcountll(x);\
    \ }\nint popcnt_sgn(int x) { return (__builtin_parity(unsigned(x)) & 1 ? -1 :\
    \ 1); }\nint popcnt_sgn(u32 x) { return (__builtin_parity(x) & 1 ? -1 : 1); }\n\
    int popcnt_sgn(ll x) { return (__builtin_parityll(x) & 1 ? -1 : 1); }\nint popcnt_sgn(u64\
    \ x) { return (__builtin_parityll(x) & 1 ? -1 : 1); }\n// (0, 1, 2, 3, 4) -> (-1,\
    \ 0, 1, 1, 2)\nint topbit(int x) { return (x == 0 ? -1 : 31 - __builtin_clz(x));\
    \ }\nint topbit(u32 x) { return (x == 0 ? -1 : 31 - __builtin_clz(x)); }\nint\
    \ topbit(ll x) { return (x == 0 ? -1 : 63 - __builtin_clzll(x)); }\nint topbit(u64\
    \ x) { return (x == 0 ? -1 : 63 - __builtin_clzll(x)); }\n// (0, 1, 2, 3, 4) ->\
    \ (-1, 0, 1, 0, 2)\nint lowbit(int x) { return (x == 0 ? -1 : __builtin_ctz(x));\
    \ }\nint lowbit(u32 x) { return (x == 0 ? -1 : __builtin_ctz(x)); }\nint lowbit(ll\
    \ x) { return (x == 0 ? -1 : __builtin_ctzll(x)); }\nint lowbit(u64 x) { return\
    \ (x == 0 ? -1 : __builtin_ctzll(x)); }\n\ntemplate <typename T>\nT kth_bit(int\
    \ k) {\n  return T(1) << k;\n}\ntemplate <typename T>\nbool has_kth_bit(T x, int\
    \ k) {\n  return x >> k & 1;\n}\n\ntemplate <typename UINT>\nstruct all_bit {\n\
    \  UINT s;\n  all_bit(UINT s) : s(s) {}\n  struct iter {\n    UINT s;\n    int\
    \ operator*() const { return lowbit(s); }\n    void operator++() { s &= s - 1;\
    \ }\n    bool operator!=(nullptr_t) const { return s; }\n  };\n  iter begin()\
    \ const { return {s}; }\n  nullptr_t end() const { return nullptr; }\n};\n\ntemplate\
    \ <typename UINT>\nstruct all_subset {\n  UINT s;\n  all_subset(UINT s) : s(s)\
    \ {}\n  struct iter {\n    UINT s, t;\n    bool done = false;\n    UINT operator*()\
    \ const { return t; }\n    void operator++() {\n      done = (t == 0);\n     \
    \ t = (t - 1) & s;\n    }\n    bool operator!=(nullptr_t) const { return !done;\
    \ }\n  };\n  iter begin() const { return {s, s}; }\n  nullptr_t end() const {\
    \ return nullptr; }\n};\n\nconstexpr u64 full_mask(int n) { return n == 64 ? -1ULL\
    \ : (1ULL << n) - 1; }\n#line 2 \"ds/fastset.hpp\"\n\n// 64-ary tree\n// space:\
    \ (N/63) * u64\nstruct FastSet {\n  static constexpr u32 B = 64;\n  int n = 0,\
    \ log = 0;\n  vvc<u64> seg;\n\n  FastSet() {}\n  FastSet(int n) { build(n); }\n\
    \n  int size() { return n; }\n\n  void fill_one() {\n    int cur = n;\n    for\
    \ (auto& vs : seg) {\n      int p = cur / B, q = cur % B;\n      FOR(i, p) vs[i]\
    \ = -1ull;\n      if (q) vs[p] = full_mask(q);\n      cur = (cur + B - 1) / B;\n\
    \    }\n  }\n\n  template <typename F>\n  FastSet(int n, F f) {\n    build(n,\
    \ f);\n  }\n\n  void build(int m) {\n    seg.clear();\n    n = m;\n    do {\n\
    \      seg.push_back(vc<u64>((m + B - 1) / B));\n      m = (m + B - 1) / B;\n\
    \    } while (m > 1);\n    log = len(seg);\n  }\n  template <typename F>\n  void\
    \ build(int n, F f) {\n    build(n);\n    FOR(i, n) { seg[0][i / B] |= u64(f(i))\
    \ << (i % B); }\n    FOR(h, log - 1) {\n      FOR(i, len(seg[h])) {\n        seg[h\
    \ + 1][i / B] |= u64(bool(seg[h][i])) << (i % B);\n      }\n    }\n  }\n\n  bool\
    \ operator[](int i) const { return seg[0][i / B] >> (i % B) & 1; }\n  void insert(int\
    \ i) {\n    assert(0 <= i && i < n);\n    for (int h = 0; h < log; h++) {\n  \
    \    seg[h][i / B] |= u64(1) << (i % B), i /= B;\n    }\n  }\n  void add(int i)\
    \ { insert(i); }\n  void erase(int i) {\n    assert(0 <= i && i < n);\n    u64\
    \ x = 0;\n    for (int h = 0; h < log; h++) {\n      seg[h][i / B] &= ~(u64(1)\
    \ << (i % B));\n      seg[h][i / B] |= x << (i % B);\n      x = bool(seg[h][i\
    \ / B]);\n      i /= B;\n    }\n  }\n  void remove(int i) { erase(i); }\n\n  //\
    \ min[x,n) or n\n  int next(int i) {\n    assert(i <= n);\n    chmax(i, 0);\n\
    \    for (int h = 0; h < log; h++) {\n      if (i / B == seg[h].size()) break;\n\
    \      u64 d = seg[h][i / B] >> (i % B);\n      if (!d) {\n        i = i / B +\
    \ 1;\n        continue;\n      }\n      i += lowbit(d);\n      for (int g = h\
    \ - 1; g >= 0; g--) {\n        i *= B;\n        i += lowbit(seg[g][i / B]);\n\
    \      }\n      return i;\n    }\n    return n;\n  }\n\n  // max [0,x], or -1\n\
    \  int prev(int i) {\n    assert(i >= -1);\n    if (i >= n) i = n - 1;\n    for\
    \ (int h = 0; h < log; h++) {\n      if (i == -1) break;\n      u64 d = seg[h][i\
    \ / B] << (63 - i % B);\n      if (!d) {\n        i = i / B - 1;\n        continue;\n\
    \      }\n      i -= __builtin_clzll(d);\n      for (int g = h - 1; g >= 0; g--)\
    \ {\n        i *= B;\n        i += topbit(seg[g][i / B]);\n      }\n      return\
    \ i;\n    }\n    return -1;\n  }\n\n  bool any(int l, int r) { return next(l)\
    \ < r; }\n\n  // [l, r)\n  template <typename F>\n  void enumerate(int l, int\
    \ r, F f) {\n    for (int x = next(l); x < r; x = next(x + 1)) f(x);\n  }\n\n\
    \  void reset() {\n    enumerate(0, n, [&](int i) -> void { erase(i); });\n  }\n\
    \n  string to_string() {\n    string s(n, '?');\n    for (int i = 0; i < n; ++i)\
    \ s[i] = ((*this)[i] ? '1' : '0');\n    return s;\n  }\n};\n"
  code: "#include \"other/bit.hpp\"\n\n// 64-ary tree\n// space: (N/63) * u64\nstruct\
    \ FastSet {\n  static constexpr u32 B = 64;\n  int n = 0, log = 0;\n  vvc<u64>\
    \ seg;\n\n  FastSet() {}\n  FastSet(int n) { build(n); }\n\n  int size() { return\
    \ n; }\n\n  void fill_one() {\n    int cur = n;\n    for (auto& vs : seg) {\n\
    \      int p = cur / B, q = cur % B;\n      FOR(i, p) vs[i] = -1ull;\n      if\
    \ (q) vs[p] = full_mask(q);\n      cur = (cur + B - 1) / B;\n    }\n  }\n\n  template\
    \ <typename F>\n  FastSet(int n, F f) {\n    build(n, f);\n  }\n\n  void build(int\
    \ m) {\n    seg.clear();\n    n = m;\n    do {\n      seg.push_back(vc<u64>((m\
    \ + B - 1) / B));\n      m = (m + B - 1) / B;\n    } while (m > 1);\n    log =\
    \ len(seg);\n  }\n  template <typename F>\n  void build(int n, F f) {\n    build(n);\n\
    \    FOR(i, n) { seg[0][i / B] |= u64(f(i)) << (i % B); }\n    FOR(h, log - 1)\
    \ {\n      FOR(i, len(seg[h])) {\n        seg[h + 1][i / B] |= u64(bool(seg[h][i]))\
    \ << (i % B);\n      }\n    }\n  }\n\n  bool operator[](int i) const { return\
    \ seg[0][i / B] >> (i % B) & 1; }\n  void insert(int i) {\n    assert(0 <= i &&\
    \ i < n);\n    for (int h = 0; h < log; h++) {\n      seg[h][i / B] |= u64(1)\
    \ << (i % B), i /= B;\n    }\n  }\n  void add(int i) { insert(i); }\n  void erase(int\
    \ i) {\n    assert(0 <= i && i < n);\n    u64 x = 0;\n    for (int h = 0; h <\
    \ log; h++) {\n      seg[h][i / B] &= ~(u64(1) << (i % B));\n      seg[h][i /\
    \ B] |= x << (i % B);\n      x = bool(seg[h][i / B]);\n      i /= B;\n    }\n\
    \  }\n  void remove(int i) { erase(i); }\n\n  // min[x,n) or n\n  int next(int\
    \ i) {\n    assert(i <= n);\n    chmax(i, 0);\n    for (int h = 0; h < log; h++)\
    \ {\n      if (i / B == seg[h].size()) break;\n      u64 d = seg[h][i / B] >>\
    \ (i % B);\n      if (!d) {\n        i = i / B + 1;\n        continue;\n     \
    \ }\n      i += lowbit(d);\n      for (int g = h - 1; g >= 0; g--) {\n       \
    \ i *= B;\n        i += lowbit(seg[g][i / B]);\n      }\n      return i;\n   \
    \ }\n    return n;\n  }\n\n  // max [0,x], or -1\n  int prev(int i) {\n    assert(i\
    \ >= -1);\n    if (i >= n) i = n - 1;\n    for (int h = 0; h < log; h++) {\n \
    \     if (i == -1) break;\n      u64 d = seg[h][i / B] << (63 - i % B);\n    \
    \  if (!d) {\n        i = i / B - 1;\n        continue;\n      }\n      i -= __builtin_clzll(d);\n\
    \      for (int g = h - 1; g >= 0; g--) {\n        i *= B;\n        i += topbit(seg[g][i\
    \ / B]);\n      }\n      return i;\n    }\n    return -1;\n  }\n\n  bool any(int\
    \ l, int r) { return next(l) < r; }\n\n  // [l, r)\n  template <typename F>\n\
    \  void enumerate(int l, int r, F f) {\n    for (int x = next(l); x < r; x = next(x\
    \ + 1)) f(x);\n  }\n\n  void reset() {\n    enumerate(0, n, [&](int i) -> void\
    \ { erase(i); });\n  }\n\n  string to_string() {\n    string s(n, '?');\n    for\
    \ (int i = 0; i < n; ++i) s[i] = ((*this)[i] ? '1' : '0');\n    return s;\n  }\n\
    };"
  dependsOn:
  - other/bit.hpp
  isVerificationFile: false
  path: ds/fastset.hpp
  requiredBy:
  - bigint/redundant_binary_number.hpp
  - graph/all_cycle_common_vertices.hpp
  - graph/ds/incremental_centroid.hpp
  - graph/compress_tree.hpp
  - graph/toposort.hpp
  - ds/incremental_rectangle_union.hpp
  - ds/intervals.hpp
  - ds/sortable_array.hpp
  - ds/segtree/range_add_make_increasing.hpp
  - ds/segtree/range_assignment_segtree.hpp
  - ds/segtree/range_add_make_decreasing.hpp
  - ds/segtree/sortable_segtree.hpp
  - geo/delaunay_triangulation_of_convex_polygon.hpp
  - other/cuboid_union_volume.hpp
  - string/enumerate_occurrences.hpp
  - string/suffix_tree.hpp
  timestamp: '2026-08-17 08:30:43+09:00'
  verificationStatus: LIBRARY_SOME_WA
  verifiedWith:
  - test/1_mytest/all_cycle_common_vertex.test.cpp
  - test/1_mytest/range_assign.test.cpp
  - test/1_mytest/sortable_array.test.cpp
  - test/1_mytest/decremental_fastset.test.cpp
  - test/2_library_checker/data_structure/sort_segtree.test.cpp
  - test/2_library_checker/data_structure/range_set_range_composite.test.cpp
  - test/2_library_checker/data_structure/sort_segtree_1.test.cpp
  - test/2_library_checker/data_structure/predecessor_problem.test.cpp
  - test/4_aoj/2251_1.test.cpp
  - test/4_aoj/2636.test.cpp
  - test/3_yukicoder/2361.test.cpp
  - test/3_yukicoder/2809.test.cpp
documentation_of: ds/fastset.hpp
layout: document
redirect_from:
- /library/ds/fastset.hpp
- /library/ds/fastset.hpp.html
title: ds/fastset.hpp
---
