---
data:
  _extendedDependsOn: []
  _extendedRequiredBy:
  - icon: ':heavy_check_mark:'
    path: ds/intervals.hpp
    title: ds/intervals.hpp
  - icon: ':question:'
    path: ds/segtree/sortable_segtree.hpp
    title: ds/segtree/sortable_segtree.hpp
  - icon: ':heavy_check_mark:'
    path: graph/dag_path_cover.hpp
    title: graph/dag_path_cover.hpp
  - icon: ':warning:'
    path: graph/implicit_graph/cograph_unionfind.hpp
    title: graph/implicit_graph/cograph_unionfind.hpp
  - icon: ':heavy_check_mark:'
    path: graph/toposort.hpp
    title: graph/toposort.hpp
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/aoj/2251_1.test.cpp
    title: test/aoj/2251_1.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/library_checker/datastructure/predecessor_problem.test.cpp
    title: test/library_checker/datastructure/predecessor_problem.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/library_checker/datastructure/sort_segtree.test.cpp
    title: test/library_checker/datastructure/sort_segtree.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/library_checker/datastructure/sort_segtree_1.test.cpp
    title: test/library_checker/datastructure/sort_segtree_1.test.cpp
  - icon: ':heavy_check_mark:'
    path: test_atcoder/abc223d.test.cpp
    title: test_atcoder/abc223d.test.cpp
  - icon: ':x:'
    path: test_atcoder/abc237g.test.cpp
    title: test_atcoder/abc237g.test.cpp
  - icon: ':heavy_check_mark:'
    path: test_atcoder/abc256d.test.cpp
    title: test_atcoder/abc256d.test.cpp
  - icon: ':heavy_check_mark:'
    path: test_atcoder/abc256ex.test.cpp
    title: test_atcoder/abc256ex.test.cpp
  - icon: ':heavy_check_mark:'
    path: test_atcoder/abc256ex2.test.cpp
    title: test_atcoder/abc256ex2.test.cpp
  _isVerificationFailed: true
  _pathExtension: hpp
  _verificationStatusIcon: ':question:'
  attributes:
    links: []
  bundledCode: "#line 1 \"ds/fastset.hpp\"\n/* 64\u5206\u6728\u3002\r\ninsert, erase\r\
    \n[]\u3067\u306E\u5B58\u5728\u5224\u5B9A\r\nnext, prev\r\n*/\r\nstruct FastSet\
    \ {\r\n  using uint = unsigned;\r\n  using ull = unsigned long long;\r\n\r\n \
    \ int bsr(ull x) { return 63 - __builtin_clzll(x); }\r\n  int bsf(ull x) { return\
    \ __builtin_ctzll(x); }\r\n\r\n  static constexpr uint B = 64;\r\n  int n, lg;\r\
    \n  vector<vector<ull>> seg;\r\n  FastSet(int _n) : n(_n) {\r\n    do {\r\n  \
    \    seg.push_back(vector<ull>((_n + B - 1) / B));\r\n      _n = (_n + B - 1)\
    \ / B;\r\n    } while (_n > 1);\r\n    lg = int(seg.size());\r\n  }\r\n  bool\
    \ operator[](int i) const { return (seg[0][i / B] >> (i % B) & 1) != 0; }\r\n\
    \  void insert(int i) {\r\n    for (int h = 0; h < lg; h++) {\r\n      seg[h][i\
    \ / B] |= 1ULL << (i % B);\r\n      i /= B;\r\n    }\r\n  }\r\n  void erase(int\
    \ i) {\r\n    for (int h = 0; h < lg; h++) {\r\n      seg[h][i / B] &= ~(1ULL\
    \ << (i % B));\r\n      if (seg[h][i / B]) break;\r\n      i /= B;\r\n    }\r\n\
    \  }\r\n\r\n  // x\u4EE5\u4E0A\u6700\u5C0F\u306E\u8981\u7D20\u3092\u8FD4\u3059\
    \u3002\u5B58\u5728\u3057\u306A\u3051\u308C\u3070 n\u3002\r\n  int next(int i)\
    \ {\r\n    chmax(i, 0);\r\n    if (i >= n) return n;\r\n    for (int h = 0; h\
    \ < lg; h++) {\r\n      if (i / B == seg[h].size()) break;\r\n      ull d = seg[h][i\
    \ / B] >> (i % B);\r\n      if (!d) {\r\n        i = i / B + 1;\r\n        continue;\r\
    \n      }\r\n      // find\r\n      i += bsf(d);\r\n      for (int g = h - 1;\
    \ g >= 0; g--) {\r\n        i *= B;\r\n        i += bsf(seg[g][i / B]);\r\n  \
    \    }\r\n      return i;\r\n    }\r\n    return n;\r\n  }\r\n\r\n  // x\u4EE5\
    \u4E0B\u6700\u5927\u306E\u8981\u7D20\u3092\u8FD4\u3059\u3002\u5B58\u5728\u3057\
    \u306A\u3051\u308C\u3070 -1\u3002\r\n  int prev(int i) {\r\n    if (i < 0) return\
    \ -1;\r\n    if (i >= n) i = n - 1;\r\n    for (int h = 0; h < lg; h++) {\r\n\
    \      if (i == -1) break;\r\n      ull d = seg[h][i / B] << (63 - i % 64);\r\n\
    \      if (!d) {\r\n        i = i / B - 1;\r\n        continue;\r\n      }\r\n\
    \      // find\r\n      i += bsr(d) - (B - 1);\r\n      for (int g = h - 1; g\
    \ >= 0; g--) {\r\n        i *= B;\r\n        i += bsr(seg[g][i / B]);\r\n    \
    \  }\r\n      return i;\r\n    }\r\n    return -1;\r\n  }\r\n\r\n  // [l, r)\r\
    \n  template <typename F>\r\n  void enumerate(int l, int r, F f) {\r\n    int\
    \ x = l - 1;\r\n    while (1) {\r\n      x = next(x + 1);\r\n      if (x >= r)\
    \ break;\r\n      f(x);\r\n    }\r\n  }\r\n\r\n  void debug() {\r\n    string\
    \ s;\r\n    for (int i = 0; i < n; ++i) s += ((*this)[i] ? '1' : '0');\r\n   \
    \ print(s);\r\n  }\r\n};\r\n"
  code: "/* 64\u5206\u6728\u3002\r\ninsert, erase\r\n[]\u3067\u306E\u5B58\u5728\u5224\
    \u5B9A\r\nnext, prev\r\n*/\r\nstruct FastSet {\r\n  using uint = unsigned;\r\n\
    \  using ull = unsigned long long;\r\n\r\n  int bsr(ull x) { return 63 - __builtin_clzll(x);\
    \ }\r\n  int bsf(ull x) { return __builtin_ctzll(x); }\r\n\r\n  static constexpr\
    \ uint B = 64;\r\n  int n, lg;\r\n  vector<vector<ull>> seg;\r\n  FastSet(int\
    \ _n) : n(_n) {\r\n    do {\r\n      seg.push_back(vector<ull>((_n + B - 1) /\
    \ B));\r\n      _n = (_n + B - 1) / B;\r\n    } while (_n > 1);\r\n    lg = int(seg.size());\r\
    \n  }\r\n  bool operator[](int i) const { return (seg[0][i / B] >> (i % B) & 1)\
    \ != 0; }\r\n  void insert(int i) {\r\n    for (int h = 0; h < lg; h++) {\r\n\
    \      seg[h][i / B] |= 1ULL << (i % B);\r\n      i /= B;\r\n    }\r\n  }\r\n\
    \  void erase(int i) {\r\n    for (int h = 0; h < lg; h++) {\r\n      seg[h][i\
    \ / B] &= ~(1ULL << (i % B));\r\n      if (seg[h][i / B]) break;\r\n      i /=\
    \ B;\r\n    }\r\n  }\r\n\r\n  // x\u4EE5\u4E0A\u6700\u5C0F\u306E\u8981\u7D20\u3092\
    \u8FD4\u3059\u3002\u5B58\u5728\u3057\u306A\u3051\u308C\u3070 n\u3002\r\n  int\
    \ next(int i) {\r\n    chmax(i, 0);\r\n    if (i >= n) return n;\r\n    for (int\
    \ h = 0; h < lg; h++) {\r\n      if (i / B == seg[h].size()) break;\r\n      ull\
    \ d = seg[h][i / B] >> (i % B);\r\n      if (!d) {\r\n        i = i / B + 1;\r\
    \n        continue;\r\n      }\r\n      // find\r\n      i += bsf(d);\r\n    \
    \  for (int g = h - 1; g >= 0; g--) {\r\n        i *= B;\r\n        i += bsf(seg[g][i\
    \ / B]);\r\n      }\r\n      return i;\r\n    }\r\n    return n;\r\n  }\r\n\r\n\
    \  // x\u4EE5\u4E0B\u6700\u5927\u306E\u8981\u7D20\u3092\u8FD4\u3059\u3002\u5B58\
    \u5728\u3057\u306A\u3051\u308C\u3070 -1\u3002\r\n  int prev(int i) {\r\n    if\
    \ (i < 0) return -1;\r\n    if (i >= n) i = n - 1;\r\n    for (int h = 0; h <\
    \ lg; h++) {\r\n      if (i == -1) break;\r\n      ull d = seg[h][i / B] << (63\
    \ - i % 64);\r\n      if (!d) {\r\n        i = i / B - 1;\r\n        continue;\r\
    \n      }\r\n      // find\r\n      i += bsr(d) - (B - 1);\r\n      for (int g\
    \ = h - 1; g >= 0; g--) {\r\n        i *= B;\r\n        i += bsr(seg[g][i / B]);\r\
    \n      }\r\n      return i;\r\n    }\r\n    return -1;\r\n  }\r\n\r\n  // [l,\
    \ r)\r\n  template <typename F>\r\n  void enumerate(int l, int r, F f) {\r\n \
    \   int x = l - 1;\r\n    while (1) {\r\n      x = next(x + 1);\r\n      if (x\
    \ >= r) break;\r\n      f(x);\r\n    }\r\n  }\r\n\r\n  void debug() {\r\n    string\
    \ s;\r\n    for (int i = 0; i < n; ++i) s += ((*this)[i] ? '1' : '0');\r\n   \
    \ print(s);\r\n  }\r\n};\r\n"
  dependsOn: []
  isVerificationFile: false
  path: ds/fastset.hpp
  requiredBy:
  - graph/toposort.hpp
  - graph/dag_path_cover.hpp
  - graph/implicit_graph/cograph_unionfind.hpp
  - ds/intervals.hpp
  - ds/segtree/sortable_segtree.hpp
  timestamp: '2023-02-28 19:13:41+09:00'
  verificationStatus: LIBRARY_SOME_WA
  verifiedWith:
  - test/library_checker/datastructure/sort_segtree_1.test.cpp
  - test/library_checker/datastructure/sort_segtree.test.cpp
  - test/library_checker/datastructure/predecessor_problem.test.cpp
  - test/aoj/2251_1.test.cpp
  - test_atcoder/abc237g.test.cpp
  - test_atcoder/abc223d.test.cpp
  - test_atcoder/abc256d.test.cpp
  - test_atcoder/abc256ex2.test.cpp
  - test_atcoder/abc256ex.test.cpp
documentation_of: ds/fastset.hpp
layout: document
redirect_from:
- /library/ds/fastset.hpp
- /library/ds/fastset.hpp.html
title: ds/fastset.hpp
---
