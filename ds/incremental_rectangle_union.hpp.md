---
data:
  _extendedDependsOn:
  - icon: ':question:'
    path: ds/fastset.hpp
    title: ds/fastset.hpp
  - icon: ':question:'
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
  bundledCode: "#line 1 \"ds/incremental_rectangle_union.hpp\"\n\n#line 1 \"other/bit.hpp\"\
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
    \ n == 64 ? -1ULL : (1ULL << n) - 1; }\n\nu64 bit_reverse(u64 x) {\n  x = ((x\
    \ & 0x5555555555555555ULL) << 1) | ((x >> 1) & 0x5555555555555555ULL);\n  x =\
    \ ((x & 0x3333333333333333ULL) << 2) | ((x >> 2) & 0x3333333333333333ULL);\n \
    \ x = ((x & 0x0f0f0f0f0f0f0f0fULL) << 4) | ((x >> 4) & 0x0f0f0f0f0f0f0f0fULL);\n\
    \  x = ((x & 0x00ff00ff00ff00ffULL) << 8) | ((x >> 8) & 0x00ff00ff00ff00ffULL);\n\
    \  x = ((x & 0x0000ffff0000ffffULL) << 16) | ((x >> 16) & 0x0000ffff0000ffffULL);\n\
    \  x = (x << 32) | (x >> 32);\n  return x;\n}\n#line 2 \"ds/fastset.hpp\"\n\n\
    // 64-ary tree\n// space: (N/63) * u64\nstruct FastSet {\n  static constexpr u32\
    \ B = 64;\n  int n = 0, log = 0;\n  vvc<u64> seg;\n\n  FastSet() {}\n  FastSet(int\
    \ n) { build(n); }\n\n  int size() { return n; }\n\n  void fill_one() {\n    int\
    \ cur = n;\n    for (auto& vs : seg) {\n      int p = cur / B, q = cur % B;\n\
    \      FOR(i, p) vs[i] = -1ull;\n      if (q) vs[p] = full_mask(q);\n      cur\
    \ = (cur + B - 1) / B;\n    }\n  }\n\n  template <typename F>\n  FastSet(int n,\
    \ F f) {\n    build(n, f);\n  }\n\n  void build(int m) {\n    seg.clear();\n \
    \   n = m;\n    do {\n      seg.push_back(vc<u64>((m + B - 1) / B));\n      m\
    \ = (m + B - 1) / B;\n    } while (m > 1);\n    log = len(seg);\n  }\n  template\
    \ <typename F>\n  void build(int n, F f) {\n    build(n);\n    FOR(i, n) { seg[0][i\
    \ / B] |= u64(f(i)) << (i % B); }\n    FOR(h, log - 1) {\n      FOR(i, len(seg[h]))\
    \ {\n        seg[h + 1][i / B] |= u64(bool(seg[h][i])) << (i % B);\n      }\n\
    \    }\n  }\n\n  bool operator[](int i) const { return seg[0][i / B] >> (i % B)\
    \ & 1; }\n  void insert(int i) {\n    assert(0 <= i && i < n);\n    for (int h\
    \ = 0; h < log; h++) {\n      seg[h][i / B] |= u64(1) << (i % B), i /= B;\n  \
    \  }\n  }\n  void add(int i) { insert(i); }\n  void erase(int i) {\n    assert(0\
    \ <= i && i < n);\n    u64 x = 0;\n    for (int h = 0; h < log; h++) {\n     \
    \ seg[h][i / B] &= ~(u64(1) << (i % B));\n      seg[h][i / B] |= x << (i % B);\n\
    \      x = bool(seg[h][i / B]);\n      i /= B;\n    }\n  }\n  void remove(int\
    \ i) { erase(i); }\n\n  // min[x,n) or n\n  int next(int i) {\n    assert(i <=\
    \ n);\n    chmax(i, 0);\n    for (int h = 0; h < log; h++) {\n      if (i / B\
    \ == seg[h].size()) break;\n      u64 d = seg[h][i / B] >> (i % B);\n      if\
    \ (!d) {\n        i = i / B + 1;\n        continue;\n      }\n      i += lowbit(d);\n\
    \      for (int g = h - 1; g >= 0; g--) {\n        i *= B;\n        i += lowbit(seg[g][i\
    \ / B]);\n      }\n      return i;\n    }\n    return n;\n  }\n\n  // max [0,x],\
    \ or -1\n  int prev(int i) {\n    assert(i >= -1);\n    if (i >= n) i = n - 1;\n\
    \    for (int h = 0; h < log; h++) {\n      if (i == -1) break;\n      u64 d =\
    \ seg[h][i / B] << (63 - i % B);\n      if (!d) {\n        i = i / B - 1;\n  \
    \      continue;\n      }\n      i -= __builtin_clzll(d);\n      for (int g =\
    \ h - 1; g >= 0; g--) {\n        i *= B;\n        i += topbit(seg[g][i / B]);\n\
    \      }\n      return i;\n    }\n    return -1;\n  }\n\n  bool any(int l, int\
    \ r) { return next(l) < r; }\n\n  // [l, r)\n  template <typename F>\n  void enumerate(int\
    \ l, int r, F f) {\n    for (int x = next(l); x < r; x = next(x + 1)) f(x);\n\
    \  }\n\n  void reset() {\n    enumerate(0, n, [&](int i) -> void { erase(i); });\n\
    \  }\n\n  string to_string() {\n    string s(n, '?');\n    for (int i = 0; i <\
    \ n; ++i) s[i] = ((*this)[i] ? '1' : '0');\n    return s;\n  }\n};\n#line 3 \"\
    ds/incremental_rectangle_union.hpp\"\n\n// [0, x] x [0, y] \u3092\u8FFD\u52A0\
    \ -> \u548C\u96C6\u5408\u9762\u7A4D\u3092\u53D6\u5F97\ntemplate <typename XY,\
    \ typename AREA, bool SMALL_XY>\nstruct Incremental_Rectangle_Union {\n  FastSet\
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
  timestamp: '2026-08-19 06:34:57+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: ds/incremental_rectangle_union.hpp
layout: document
redirect_from:
- /library/ds/incremental_rectangle_union.hpp
- /library/ds/incremental_rectangle_union.hpp.html
title: ds/incremental_rectangle_union.hpp
---
