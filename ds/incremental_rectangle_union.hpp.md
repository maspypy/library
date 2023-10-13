---
data:
  _extendedDependsOn:
  - icon: ':question:'
    path: ds/fastset.hpp
    title: ds/fastset.hpp
  _extendedRequiredBy:
  - icon: ':warning:'
    path: other/cuboid_union_volume.hpp
    title: other/cuboid_union_volume.hpp
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':warning:'
  attributes:
    links: []
  bundledCode: "#line 1 \"ds/incremental_rectangle_union.hpp\"\n\n#line 1 \"ds/fastset.hpp\"\
    \n/* 64\u5206\u6728\u3002\r\ninsert, erase\r\n[]\u3067\u306E\u5B58\u5728\u5224\
    \u5B9A\r\nnext, prev\r\n*/\r\nstruct FastSet {\r\n  using uint = unsigned;\r\n\
    \  using ull = unsigned long long;\r\n\r\n  int bsr(ull x) { return 63 - __builtin_clzll(x);\
    \ }\r\n  int bsf(ull x) { return __builtin_ctzll(x); }\r\n\r\n  static constexpr\
    \ uint B = 64;\r\n  int n, lg;\r\n  vector<vector<ull>> seg;\r\n  FastSet(int\
    \ _n) : n(_n) {\r\n    do {\r\n      seg.push_back(vector<ull>((_n + B - 1) /\
    \ B));\r\n      _n = (_n + B - 1) / B;\r\n    } while (_n > 1);\r\n    lg = int(seg.size());\r\
    \n  }\r\n  bool operator[](int i) const { return (seg[0][i / B] >> (i % B) & 1)\
    \ != 0; }\r\n  void insert(int i) {\r\n    for (int h = 0; h < lg; h++) {\r\n\
    \      seg[h][i / B] |= 1ULL << (i % B);\r\n      i /= B;\r\n    }\r\n  }\r\n\
    \  void add(int i) { insert(i); }\r\n  void erase(int i) {\r\n    for (int h =\
    \ 0; h < lg; h++) {\r\n      seg[h][i / B] &= ~(1ULL << (i % B));\r\n      if\
    \ (seg[h][i / B]) break;\r\n      i /= B;\r\n    }\r\n  }\r\n  void remove(int\
    \ i) { erase(i); }\r\n\r\n  // x\u4EE5\u4E0A\u6700\u5C0F\u306E\u8981\u7D20\u3092\
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
    \ print(s);\r\n  }\r\n};\r\n#line 3 \"ds/incremental_rectangle_union.hpp\"\n\n\
    // [0, x] x [0, y] \u3092\u8FFD\u52A0 -> \u548C\u96C6\u5408\u9762\u7A4D\u3092\u53D6\
    \u5F97\ntemplate <typename XY, typename AREA, bool SMALL_XY>\nstruct Incremental_Rectangle_Union\
    \ {\n  FastSet ss;\n  vc<XY> ht;\n  map<XY, XY> MP; // right end -> height\n \
    \ ll area;\n\n  Incremental_Rectangle_Union() : area(AREA(0)) {\n    static_assert(!SMALL_XY);\n\
    \    MP[0] = infty<XY>;\n    MP[infty<XY>] = 0;\n  }\n\n  Incremental_Rectangle_Union(int\
    \ LIM)\n      : ss(LIM + 1), ht(LIM + 1), area(AREA(0)) {\n    static_assert(SMALL_XY);\n\
    \    ht[0] = infty<XY>, ht[LIM] = 0, ss.insert(0), ss.insert(LIM);\n  }\n\n  AREA\
    \ add(XY x, XY y) {\n    if constexpr (SMALL_XY) add_fast(x, y);\n    if constexpr\
    \ (!SMALL_XY) add_MP(x, y);\n    return area;\n  }\n\nprivate:\n  void add_MP(XY\
    \ x, XY y) {\n    if (x == 0 || y == 0) return;\n    auto it = MP.lower_bound(x);\n\
    \    auto [rx, ry] = *it;\n    if (ry >= y) return;\n\n    // split\n    if (x\
    \ < rx) MP[x] = ry;\n    it = MP.find(x);\n    while (1) {\n      auto [x2, y2]\
    \ = *it;\n      it = prev(MP.erase(it));\n      auto [x1, y1] = *it;\n      //\
    \ [x1,x2]: y2 -> 0\n      area -= AREA(x2 - x1) * AREA(y2);\n      if (y1 >= y)\
    \ break;\n    }\n    auto [x1, y1] = *it;\n    // [x1, x]: 0 -> y\n    MP[x] =\
    \ y, area += AREA(x - x1) * AREA(y);\n    return;\n  }\n\n  void add_fast(XY x,\
    \ XY y) {\n    if (x == 0 || y == 0) return;\n    int rx = ss.next(x);\n    int\
    \ ry = ht[rx];\n    if (ry >= y) return;\n\n    // split\n    if (x < rx) ss.insert(x),\
    \ ht[x] = ry;\n    int x2 = x;\n    while (1) {\n      XY y2 = ht[x2];\n     \
    \ ss.erase(x2);\n      int x1 = ss.prev(x2);\n      XY y1 = ht[x1];\n      //\
    \ [x1,x2]: y2 -> 0\n      area -= AREA(x2 - x1) * AREA(y2);\n      x2 = x1;\n\
    \      if (y1 >= y) break;\n    }\n    ss.insert(x), ht[x] = y, area += AREA(x\
    \ - x2) * AREA(y);\n    return;\n  }\n};\n"
  code: "\n#include \"ds/fastset.hpp\"\n\n// [0, x] x [0, y] \u3092\u8FFD\u52A0 ->\
    \ \u548C\u96C6\u5408\u9762\u7A4D\u3092\u53D6\u5F97\ntemplate <typename XY, typename\
    \ AREA, bool SMALL_XY>\nstruct Incremental_Rectangle_Union {\n  FastSet ss;\n\
    \  vc<XY> ht;\n  map<XY, XY> MP; // right end -> height\n  ll area;\n\n  Incremental_Rectangle_Union()\
    \ : area(AREA(0)) {\n    static_assert(!SMALL_XY);\n    MP[0] = infty<XY>;\n \
    \   MP[infty<XY>] = 0;\n  }\n\n  Incremental_Rectangle_Union(int LIM)\n      :\
    \ ss(LIM + 1), ht(LIM + 1), area(AREA(0)) {\n    static_assert(SMALL_XY);\n  \
    \  ht[0] = infty<XY>, ht[LIM] = 0, ss.insert(0), ss.insert(LIM);\n  }\n\n  AREA\
    \ add(XY x, XY y) {\n    if constexpr (SMALL_XY) add_fast(x, y);\n    if constexpr\
    \ (!SMALL_XY) add_MP(x, y);\n    return area;\n  }\n\nprivate:\n  void add_MP(XY\
    \ x, XY y) {\n    if (x == 0 || y == 0) return;\n    auto it = MP.lower_bound(x);\n\
    \    auto [rx, ry] = *it;\n    if (ry >= y) return;\n\n    // split\n    if (x\
    \ < rx) MP[x] = ry;\n    it = MP.find(x);\n    while (1) {\n      auto [x2, y2]\
    \ = *it;\n      it = prev(MP.erase(it));\n      auto [x1, y1] = *it;\n      //\
    \ [x1,x2]: y2 -> 0\n      area -= AREA(x2 - x1) * AREA(y2);\n      if (y1 >= y)\
    \ break;\n    }\n    auto [x1, y1] = *it;\n    // [x1, x]: 0 -> y\n    MP[x] =\
    \ y, area += AREA(x - x1) * AREA(y);\n    return;\n  }\n\n  void add_fast(XY x,\
    \ XY y) {\n    if (x == 0 || y == 0) return;\n    int rx = ss.next(x);\n    int\
    \ ry = ht[rx];\n    if (ry >= y) return;\n\n    // split\n    if (x < rx) ss.insert(x),\
    \ ht[x] = ry;\n    int x2 = x;\n    while (1) {\n      XY y2 = ht[x2];\n     \
    \ ss.erase(x2);\n      int x1 = ss.prev(x2);\n      XY y1 = ht[x1];\n      //\
    \ [x1,x2]: y2 -> 0\n      area -= AREA(x2 - x1) * AREA(y2);\n      x2 = x1;\n\
    \      if (y1 >= y) break;\n    }\n    ss.insert(x), ht[x] = y, area += AREA(x\
    \ - x2) * AREA(y);\n    return;\n  }\n};\n"
  dependsOn:
  - ds/fastset.hpp
  isVerificationFile: false
  path: ds/incremental_rectangle_union.hpp
  requiredBy:
  - other/cuboid_union_volume.hpp
  timestamp: '2023-10-14 01:49:54+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: ds/incremental_rectangle_union.hpp
layout: document
redirect_from:
- /library/ds/incremental_rectangle_union.hpp
- /library/ds/incremental_rectangle_union.hpp.html
title: ds/incremental_rectangle_union.hpp
---
