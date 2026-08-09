---
data:
  _extendedDependsOn:
  - icon: ':x:'
    path: ds/fastset.hpp
    title: ds/fastset.hpp
  - icon: ':x:'
    path: other/bit.hpp
    title: other/bit.hpp
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
  bundledCode: "#line 1 \"ds/incremental_rectangle_union.hpp\"\n\n#line 2 \"other/bit.hpp\"\
    \n\nint popcnt(int x) { return __builtin_popcount(x); }\nint popcnt(u32 x) { return\
    \ __builtin_popcount(x); }\nint popcnt(ll x) { return __builtin_popcountll(x);\
    \ }\nint popcnt(u64 x) { return __builtin_popcountll(x); }\nint popcnt_sgn(int\
    \ x) { return (__builtin_parity(unsigned(x)) & 1 ? -1 : 1); }\nint popcnt_sgn(u32\
    \ x) { return (__builtin_parity(x) & 1 ? -1 : 1); }\nint popcnt_sgn(ll x) { return\
    \ (__builtin_parityll(x) & 1 ? -1 : 1); }\nint popcnt_sgn(u64 x) { return (__builtin_parityll(x)\
    \ & 1 ? -1 : 1); }\n// (0, 1, 2, 3, 4) -> (-1, 0, 1, 1, 2)\nint topbit(int x)\
    \ { return (x == 0 ? -1 : 31 - __builtin_clz(x)); }\nint topbit(u32 x) { return\
    \ (x == 0 ? -1 : 31 - __builtin_clz(x)); }\nint topbit(ll x) { return (x == 0\
    \ ? -1 : 63 - __builtin_clzll(x)); }\nint topbit(u64 x) { return (x == 0 ? -1\
    \ : 63 - __builtin_clzll(x)); }\n// (0, 1, 2, 3, 4) -> (-1, 0, 1, 0, 2)\nint lowbit(int\
    \ x) { return (x == 0 ? -1 : __builtin_ctz(x)); }\nint lowbit(u32 x) { return\
    \ (x == 0 ? -1 : __builtin_ctz(x)); }\nint lowbit(ll x) { return (x == 0 ? -1\
    \ : __builtin_ctzll(x)); }\nint lowbit(u64 x) { return (x == 0 ? -1 : __builtin_ctzll(x));\
    \ }\n\ntemplate <typename T>\nT kth_bit(int k) {\n  return T(1) << k;\n}\ntemplate\
    \ <typename T>\nbool has_kth_bit(T x, int k) {\n  return x >> k & 1;\n}\n\ntemplate\
    \ <typename UINT>\nstruct all_bit {\n  UINT s;\n  all_bit(UINT s) : s(s) {}\n\
    \  struct iter {\n    UINT s;\n    int operator*() const { return lowbit(s); }\n\
    \    void operator++() { s &= s - 1; }\n    bool operator!=(nullptr_t) const {\
    \ return s; }\n  };\n  iter begin() const { return {s}; }\n  nullptr_t end() const\
    \ { return nullptr; }\n};\n\ntemplate <typename UINT>\nstruct all_subset {\n \
    \ UINT s;\n  all_subset(UINT s) : s(s) {}\n  struct iter {\n    UINT s, t;\n \
    \   bool done = false;\n    UINT operator*() const { return t; }\n    void operator++()\
    \ {\n      done = (t == 0);\n      t = (t - 1) & s;\n    }\n    bool operator!=(nullptr_t)\
    \ const { return !done; }\n  };\n  iter begin() const { return {s, s}; }\n  nullptr_t\
    \ end() const { return nullptr; }\n};\n\nconstexpr u64 full_mask(int n) { return\
    \ n == 64 ? -1ULL : (1ULL << n) - 1; }\n#line 3 \"ds/fastset.hpp\"\n\r\n// 64-ary\
    \ tree\r\n// space: (N/63) * u64\r\nstruct FastSet {\r\n  static constexpr u32\
    \ B = 64;\r\n  int n = 0, log = 0;\r\n  vvc<u64> seg;\r\n\r\n  FastSet() {}\r\n\
    \  FastSet(int n) { build(n); }\r\n\r\n  int size() { return n; }\r\n\r\n  void\
    \ fillone() {\r\n    int cur = n;\r\n    for (auto& vs : seg) {\r\n      int p\
    \ = cur / B, q = cur % B;\r\n      FOR(i, p) vs[i] = -1ull;\r\n      if (q) vs[p]\
    \ = full_mask(q);\r\n      cur = (cur + B - 1) / B;\r\n    }\r\n  }\r\n\r\n  template\
    \ <typename F>\r\n  FastSet(int n, F f) {\r\n    build(n, f);\r\n  }\r\n\r\n \
    \ void build(int m) {\r\n    seg.clear();\r\n    n = m;\r\n    do {\r\n      seg.push_back(vc<u64>((m\
    \ + B - 1) / B));\r\n      m = (m + B - 1) / B;\r\n    } while (m > 1);\r\n  \
    \  log = len(seg);\r\n  }\r\n  template <typename F>\r\n  void build(int n, F\
    \ f) {\r\n    build(n);\r\n    FOR(i, n) { seg[0][i / B] |= u64(f(i)) << (i %\
    \ B); }\r\n    FOR(h, log - 1) {\r\n      FOR(i, len(seg[h])) {\r\n        seg[h\
    \ + 1][i / B] |= u64(bool(seg[h][i])) << (i % B);\r\n      }\r\n    }\r\n  }\r\
    \n\r\n  bool operator[](int i) const { return seg[0][i / B] >> (i % B) & 1; }\r\
    \n  void insert(int i) {\r\n    assert(0 <= i && i < n);\r\n    for (int h = 0;\
    \ h < log; h++) {\r\n      seg[h][i / B] |= u64(1) << (i % B), i /= B;\r\n   \
    \ }\r\n  }\r\n  void add(int i) { insert(i); }\r\n  void erase(int i) {\r\n  \
    \  assert(0 <= i && i < n);\r\n    u64 x = 0;\r\n    for (int h = 0; h < log;\
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
    \  void reset() {\r\n    enumerate(0, n, [&](int i) -> void { erase(i); });\r\n\
    \  }\r\n\r\n  string to_string() {\r\n    string s(n, '?');\r\n    for (int i\
    \ = 0; i < n; ++i) s[i] = ((*this)[i] ? '1' : '0');\r\n    return s;\r\n  }\r\n\
    };\n#line 3 \"ds/incremental_rectangle_union.hpp\"\n\n// [0, x] x [0, y] \u3092\
    \u8FFD\u52A0 -> \u548C\u96C6\u5408\u9762\u7A4D\u3092\u53D6\u5F97\ntemplate <typename\
    \ XY, typename AREA, bool SMALL_XY>\nstruct Incremental_Rectangle_Union {\n  FastSet\
    \ ss;\n  vc<XY> ht;\n  map<XY, XY> MP; // right end -> height\n  AREA area;\n\n\
    \  Incremental_Rectangle_Union() : area(AREA(0)) {\n    static_assert(!SMALL_XY);\n\
    \    MP[0] = infty<XY>, MP[infty<XY>] = 0;\n  }\n\n  Incremental_Rectangle_Union(int\
    \ LIM)\n      : ss(LIM + 1), ht(LIM + 1), area(AREA(0)) {\n    static_assert(SMALL_XY);\n\
    \    ht[0] = infty<XY>, ht[LIM] = 0, ss.insert(0), ss.insert(LIM);\n  }\n\n  AREA\
    \ add(XY x, XY y) {\n    if constexpr (SMALL_XY) add_fast(x, y);\n    if constexpr\
    \ (!SMALL_XY) add_MP(x, y);\n    return area;\n  }\n\n  void reset() {\n    area\
    \ = 0;\n    if constexpr (SMALL_XY) {\n      int LIM = len(ss) - 1;\n      ss.enumerate(0,\
    \ LIM + 1, [&](int i) -> void { ss.erase(i); });\n      ht[0] = infty<XY>, ht[LIM]\
    \ = 0, ss.insert(0), ss.insert(LIM);\n    } else {\n      MP.clear(), MP[0] =\
    \ infty<XY>, MP[infty<XY>] = 0;\n    }\n  }\n\nprivate:\n  void add_MP(XY x, XY\
    \ y) {\n    if (x == 0 || y == 0) return;\n    auto it = MP.lower_bound(x);\n\
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
    \  vc<XY> ht;\n  map<XY, XY> MP; // right end -> height\n  AREA area;\n\n  Incremental_Rectangle_Union()\
    \ : area(AREA(0)) {\n    static_assert(!SMALL_XY);\n    MP[0] = infty<XY>, MP[infty<XY>]\
    \ = 0;\n  }\n\n  Incremental_Rectangle_Union(int LIM)\n      : ss(LIM + 1), ht(LIM\
    \ + 1), area(AREA(0)) {\n    static_assert(SMALL_XY);\n    ht[0] = infty<XY>,\
    \ ht[LIM] = 0, ss.insert(0), ss.insert(LIM);\n  }\n\n  AREA add(XY x, XY y) {\n\
    \    if constexpr (SMALL_XY) add_fast(x, y);\n    if constexpr (!SMALL_XY) add_MP(x,\
    \ y);\n    return area;\n  }\n\n  void reset() {\n    area = 0;\n    if constexpr\
    \ (SMALL_XY) {\n      int LIM = len(ss) - 1;\n      ss.enumerate(0, LIM + 1, [&](int\
    \ i) -> void { ss.erase(i); });\n      ht[0] = infty<XY>, ht[LIM] = 0, ss.insert(0),\
    \ ss.insert(LIM);\n    } else {\n      MP.clear(), MP[0] = infty<XY>, MP[infty<XY>]\
    \ = 0;\n    }\n  }\n\nprivate:\n  void add_MP(XY x, XY y) {\n    if (x == 0 ||\
    \ y == 0) return;\n    auto it = MP.lower_bound(x);\n    auto [rx, ry] = *it;\n\
    \    if (ry >= y) return;\n\n    // split\n    if (x < rx) MP[x] = ry;\n    it\
    \ = MP.find(x);\n    while (1) {\n      auto [x2, y2] = *it;\n      it = prev(MP.erase(it));\n\
    \      auto [x1, y1] = *it;\n      // [x1,x2]: y2 -> 0\n      area -= AREA(x2\
    \ - x1) * AREA(y2);\n      if (y1 >= y) break;\n    }\n    auto [x1, y1] = *it;\n\
    \    // [x1, x]: 0 -> y\n    MP[x] = y, area += AREA(x - x1) * AREA(y);\n    return;\n\
    \  }\n\n  void add_fast(XY x, XY y) {\n    if (x == 0 || y == 0) return;\n   \
    \ int rx = ss.next(x);\n    int ry = ht[rx];\n    if (ry >= y) return;\n\n   \
    \ // split\n    if (x < rx) ss.insert(x), ht[x] = ry;\n    int x2 = x;\n    while\
    \ (1) {\n      XY y2 = ht[x2];\n      ss.erase(x2);\n      int x1 = ss.prev(x2);\n\
    \      XY y1 = ht[x1];\n      // [x1,x2]: y2 -> 0\n      area -= AREA(x2 - x1)\
    \ * AREA(y2);\n      x2 = x1;\n      if (y1 >= y) break;\n    }\n    ss.insert(x),\
    \ ht[x] = y, area += AREA(x - x2) * AREA(y);\n    return;\n  }\n};\n"
  dependsOn:
  - ds/fastset.hpp
  - other/bit.hpp
  isVerificationFile: false
  path: ds/incremental_rectangle_union.hpp
  requiredBy:
  - other/cuboid_union_volume.hpp
  timestamp: '2026-08-08 03:36:12+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: ds/incremental_rectangle_union.hpp
layout: document
redirect_from:
- /library/ds/incremental_rectangle_union.hpp
- /library/ds/incremental_rectangle_union.hpp.html
title: ds/incremental_rectangle_union.hpp
---
