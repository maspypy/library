---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: ds/fastset.hpp
    title: ds/fastset.hpp
  - icon: ':warning:'
    path: ds/incremental_rectangle_union.hpp
    title: ds/incremental_rectangle_union.hpp
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':warning:'
  attributes:
    links:
    - https://codeforces.com/contest/815/problem/D
  bundledCode: "#line 1 \"ds/incremental_rectangle_union.hpp\"\n\n#line 1 \"ds/fastset.hpp\"\
    \n// 64-ary tree\n// space: (N/63) * u64\nstruct FastSet {\n  static constexpr\
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
    \ l <= r && r <= n);\n    return next(l) < r;\n  }\n\n  // [l, r). erase=true\
    \ \u306E\u3068\u304D\u3001callback \u5185\u304B\u3089 this \u3092\u5909\u66F4\u3057\
    \u3066\u306F\u3044\u3051\u306A\u3044\u3002\n  template <typename F>\n  void enumerate(int\
    \ l, int r, F f, bool erase = false) {\n    assert(0 <= l && l <= r && r <= n);\n\
    \    if (!erase) {\n      for (int x = next(l); x < r; x = next(x + 1)) f(x);\n\
    \      return;\n    }\n    for (int x = next(l); x < r;) {\n      int w = x /\
    \ B;\n      int lo = max(l, w * int(B)) - w * int(B);\n      int hi = min(r, (w\
    \ + 1) * int(B)) - w * int(B);\n      u64 erase_bits = seg[0][w] & (full_mask(hi)\
    \ & ~full_mask(lo));\n      u64 bits = erase_bits;\n      while (bits) {\n   \
    \     int k = lowbit(bits);\n        f(w * int(B) + k);\n        bits ^= u64(1)\
    \ << k;\n      }\n      seg[0][w] ^= erase_bits;\n      if (!seg[0][w]) propagate_empty_word(w);\n\
    \      x = next(min(r, (w + 1) * int(B)));\n    }\n  }\n\n  void reset() {\n \
    \   int x = next(0);\n    while (x < n) {\n      int w = x / B;\n      seg[0][w]\
    \ = 0;\n      propagate_empty_word(w);\n      x = next(min(n, (w + 1) * int(B)));\n\
    \    }\n  }\n\n  string to_string() {\n    string s(n, '?');\n    for (int i =\
    \ 0; i < n; ++i) s[i] = ((*this)[i] ? '1' : '0');\n    return s;\n  }\n\n private:\n\
    \  // seg[0][w] \u304C 0 \u306B\u306A\u3063\u305F\u5F8C\u306B\u547C\u3076\u3002\
    \n  void propagate_empty_word(int i) {\n    for (int h = 1; h < log; ++h) {\n\
    \      u64& y = seg[h][i / B];\n      u64 mask = u64(1) << (i % B);\n      y ^=\
    \ mask;\n      if (y) break;\n      i /= B;\n    }\n  }\n};\n#line 3 \"ds/incremental_rectangle_union.hpp\"\
    \n\n// [0, x] x [0, y] \u3092\u8FFD\u52A0 -> \u548C\u96C6\u5408\u9762\u7A4D\u3092\
    \u53D6\u5F97\ntemplate <typename XY, typename AREA, bool SMALL_XY>\nstruct Incremental_Rectangle_Union\
    \ {\n  FastSet ss;\n  vc<XY> ht;\n  map<XY, XY> MP;  // right end -> height\n\
    \  AREA area;\n\n  Incremental_Rectangle_Union() : area(AREA(0)) {\n    static_assert(!SMALL_XY);\n\
    \    MP[0] = infty<XY>, MP[infty<XY>] = 0;\n  }\n\n  Incremental_Rectangle_Union(int\
    \ LIM)\n      : ss(LIM + 1), ht(LIM + 1), area(AREA(0)) {\n    static_assert(SMALL_XY);\n\
    \    ht[0] = infty<XY>, ht[LIM] = 0, ss.insert(0), ss.insert(LIM);\n  }\n\n  AREA\
    \ add(XY x, XY y) {\n    if constexpr (SMALL_XY) add_fast(x, y);\n    if constexpr\
    \ (!SMALL_XY) add_MP(x, y);\n    return area;\n  }\n\n  void reset() {\n    area\
    \ = 0;\n    if constexpr (SMALL_XY) {\n      int LIM = len(ss) - 1;\n      ss.enumerate(0,\
    \ LIM + 1, [&](int i) -> void {}, true);\n      ht[0] = infty<XY>, ht[LIM] = 0,\
    \ ss.insert(0), ss.insert(LIM);\n    } else {\n      MP.clear(), MP[0] = infty<XY>,\
    \ MP[infty<XY>] = 0;\n    }\n  }\n\n private:\n  void add_MP(XY x, XY y) {\n \
    \   if (x == 0 || y == 0) return;\n    auto it = MP.lower_bound(x);\n    auto\
    \ [rx, ry] = *it;\n    if (ry >= y) return;\n\n    // split\n    if (x < rx) MP[x]\
    \ = ry;\n    it = MP.find(x);\n    while (1) {\n      auto [x2, y2] = *it;\n \
    \     it = prev(MP.erase(it));\n      auto [x1, y1] = *it;\n      // [x1,x2]:\
    \ y2 -> 0\n      area -= AREA(x2 - x1) * AREA(y2);\n      if (y1 >= y) break;\n\
    \    }\n    auto [x1, y1] = *it;\n    // [x1, x]: 0 -> y\n    MP[x] = y, area\
    \ += AREA(x - x1) * AREA(y);\n    return;\n  }\n\n  void add_fast(XY x, XY y)\
    \ {\n    if (x == 0 || y == 0) return;\n    int rx = ss.next(x);\n    int ry =\
    \ ht[rx];\n    if (ry >= y) return;\n\n    // split\n    if (x < rx) ss.insert(x),\
    \ ht[x] = ry;\n    int x2 = x;\n    while (1) {\n      XY y2 = ht[x2];\n     \
    \ ss.erase(x2);\n      int x1 = ss.prev(x2);\n      XY y1 = ht[x1];\n      //\
    \ [x1,x2]: y2 -> 0\n      area -= AREA(x2 - x1) * AREA(y2);\n      x2 = x1;\n\
    \      if (y1 >= y) break;\n    }\n    ss.insert(x), ht[x] = y, area += AREA(x\
    \ - x2) * AREA(y);\n    return;\n  }\n};\n#line 2 \"other/cuboid_union_volume.hpp\"\
    \n\n// [0,a] x [0,b] x [0,c] \u306E\u548C\u96C6\u5408\u306E\u4F53\u7A4D\n// https://codeforces.com/contest/815/problem/D\n\
    template <typename XYZ, typename T, bool SMALL_X>\nT cuboid_union_volume(vc<tuple<XYZ,\
    \ XYZ, XYZ>> dat) {\n  if constexpr (SMALL_X) {\n    int mx_x = 0, mx_z = 0;\n\
    \    for (auto& [x, y, z]: dat) chmax(mx_x, x), chmax(mx_z, z);\n    vc<int> ptr(mx_z\
    \ + 1);\n    for (auto& [x, y, z]: dat) ptr[z]++;\n    ptr = cumsum<int>(ptr);\n\
    \    vc<pair<int, int>> rect(len(dat));\n    for (auto& [x, y, z]: dat) { rect[ptr[z]++]\
    \ = {x, y}; }\n    T vol = 0;\n    Incremental_Rectangle_Union<XYZ, T, true> I(mx_x);\n\
    \    FOR_R(z, 1, mx_z + 1) {\n      FOR(i, ptr[z - 1], ptr[z]) {\n        auto\
    \ [a, b] = rect[i];\n        I.add(a, b);\n      }\n      vol += I.area;\n   \
    \ }\n    return vol;\n  } else {\n    sort(all(dat),\n         [&](auto& a, auto&\
    \ b) -> bool { return get<2>(a) > get<2>(b); });\n    XYZ z = infty<XYZ>;\n  \
    \  T vol = 0, area = 0;\n    Incremental_Rectangle_Union<XYZ, T, false> I;\n \
    \   for (auto& [a, b, c]: dat) {\n      vol += T(z - c) * area, area = I.add(a,\
    \ b), z = c;\n    }\n    vol += z * I.area;\n    return vol;\n  }\n}\n"
  code: "#include \"ds/incremental_rectangle_union.hpp\"\n\n// [0,a] x [0,b] x [0,c]\
    \ \u306E\u548C\u96C6\u5408\u306E\u4F53\u7A4D\n// https://codeforces.com/contest/815/problem/D\n\
    template <typename XYZ, typename T, bool SMALL_X>\nT cuboid_union_volume(vc<tuple<XYZ,\
    \ XYZ, XYZ>> dat) {\n  if constexpr (SMALL_X) {\n    int mx_x = 0, mx_z = 0;\n\
    \    for (auto& [x, y, z]: dat) chmax(mx_x, x), chmax(mx_z, z);\n    vc<int> ptr(mx_z\
    \ + 1);\n    for (auto& [x, y, z]: dat) ptr[z]++;\n    ptr = cumsum<int>(ptr);\n\
    \    vc<pair<int, int>> rect(len(dat));\n    for (auto& [x, y, z]: dat) { rect[ptr[z]++]\
    \ = {x, y}; }\n    T vol = 0;\n    Incremental_Rectangle_Union<XYZ, T, true> I(mx_x);\n\
    \    FOR_R(z, 1, mx_z + 1) {\n      FOR(i, ptr[z - 1], ptr[z]) {\n        auto\
    \ [a, b] = rect[i];\n        I.add(a, b);\n      }\n      vol += I.area;\n   \
    \ }\n    return vol;\n  } else {\n    sort(all(dat),\n         [&](auto& a, auto&\
    \ b) -> bool { return get<2>(a) > get<2>(b); });\n    XYZ z = infty<XYZ>;\n  \
    \  T vol = 0, area = 0;\n    Incremental_Rectangle_Union<XYZ, T, false> I;\n \
    \   for (auto& [a, b, c]: dat) {\n      vol += T(z - c) * area, area = I.add(a,\
    \ b), z = c;\n    }\n    vol += z * I.area;\n    return vol;\n  }\n}\n"
  dependsOn:
  - ds/incremental_rectangle_union.hpp
  - ds/fastset.hpp
  isVerificationFile: false
  path: other/cuboid_union_volume.hpp
  requiredBy: []
  timestamp: '2026-10-05 00:23:18+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: other/cuboid_union_volume.hpp
layout: document
redirect_from:
- /library/other/cuboid_union_volume.hpp
- /library/other/cuboid_union_volume.hpp.html
title: other/cuboid_union_volume.hpp
---
