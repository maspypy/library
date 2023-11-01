---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/library_checker/datastructure/point_add_rectangle_sum_seg2d.test.cpp
    title: test/library_checker/datastructure/point_add_rectangle_sum_seg2d.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/mytest/seg2d.test.cpp
    title: test/mytest/seg2d.test.cpp
  - icon: ':x:'
    path: test/yukicoder/1600.test.cpp
    title: test/yukicoder/1600.test.cpp
  - icon: ':x:'
    path: test/yukicoder/1625_2.test.cpp
    title: test/yukicoder/1625_2.test.cpp
  - icon: ':x:'
    path: test_atcoder/abc266h.test.cpp
    title: test_atcoder/abc266h.test.cpp
  - icon: ':x:'
    path: test_atcoder/abc324g2.test.cpp
    title: test_atcoder/abc324g2.test.cpp
  _isVerificationFailed: true
  _pathExtension: hpp
  _verificationStatusIcon: ':question:'
  attributes:
    links: []
  bundledCode: "#line 1 \"ds/segtree/segtree_2d.hpp\"\n// \u70B9\u306E\u91CD\u8907\
    \ OK\r\ntemplate <typename Monoid, typename XY, bool SMALL_X = false>\r\nstruct\
    \ SegTree_2D {\r\n  using MX = Monoid;\r\n  using S = typename MX::value_type;\r\
    \n  static_assert(MX::commute);\r\n  int N;\r\n  // X to idx\r\n  vc<XY> keyX;\r\
    \n  int minX;\r\n  // top node \u306E\u70B9\u5217\r\n  vc<XY> all_Y;\r\n  vc<int>\
    \ pos;\r\n  // segtree data\r\n  int NX, log, size;\r\n  vc<int> indptr;\r\n \
    \ vc<S> dat;\r\n  // fractional cascading\r\n  vc<int> to_left;\r\n\r\n  SegTree_2D(vc<XY>&\
    \ X, vc<XY>& Y)\r\n      : SegTree_2D(len(X), [&](int i) -> tuple<XY, XY, S> {\r\
    \n          return {X[i], Y[i], MX::unit()};\r\n        }) {}\r\n\r\n  SegTree_2D(vc<XY>&\
    \ X, vc<XY>& Y, vc<S>& vals)\r\n      : SegTree_2D(len(X), [&](int i) -> tuple<XY,\
    \ XY, S> {\r\n          return {X[i], Y[i], vals[i]};\r\n        }) {}\r\n\r\n\
    \  // f(i) = (x,y,val)\r\n  template <typename F>\r\n  SegTree_2D(int N, F f)\
    \ {\r\n    vc<XY> X(N), Y(N);\r\n    vc<S> wt(N);\r\n    FOR(i, N) {\r\n     \
    \ auto [a, b, c] = f(i);\r\n      X[i] = a, Y[i] = b, wt[i] = c;\r\n    }\r\n\
    \    if (!SMALL_X) {\r\n      keyX = X;\r\n      UNIQUE(keyX);\r\n      NX = len(keyX);\r\
    \n    } else {\r\n      minX = (X.empty() ? 0 : MIN(X));\r\n      NX = (X.empty()\
    \ ? 1 : MAX(X) - minX + 1);\r\n    }\r\n\r\n    log = 0;\r\n    while ((1 << log)\
    \ < NX) ++log;\r\n    size = (1 << log);\r\n\r\n    vc<int> IX(N);\r\n    FOR(i,\
    \ N) IX[i] = xtoi(X[i]);\r\n    indptr.assign(2 * size, 0);\r\n    for (auto i:\
    \ IX) {\r\n      i += size;\r\n      while (i) indptr[i]++, i /= 2;\r\n    }\r\
    \n    indptr = cumsum<int>(indptr);\r\n    dat.assign(2 * indptr.back(), MX::unit());\r\
    \n    to_left.assign(indptr[size], 0);\r\n\r\n    vc<int> ptr = indptr;\r\n  \
    \  vc<int> I = argsort(Y);\r\n    pos.resize(N);\r\n    FOR(i, N) pos[I[i]] =\
    \ i;\r\n    for (auto raw_idx: I) {\r\n      int i = IX[raw_idx] + size;\r\n \
    \     int j = -1;\r\n      while (i) {\r\n        int p = ptr[i];\r\n        ptr[i]++;\r\
    \n        dat[indptr[i + 1] + p] = wt[raw_idx];\r\n        if (j != -1) { to_left[p]\
    \ = (j % 2 == 0); }\r\n        j = i, i /= 2;\r\n      }\r\n    }\r\n    to_left\
    \ = cumsum<int>(to_left);\r\n\r\n    FOR(i, 2 * size) {\r\n      int off = 2 *\
    \ indptr[i], n = indptr[i + 1] - indptr[i];\r\n      FOR_R(j, 1, n) {\r\n    \
    \    dat[off + j] = MX::op(dat[off + 2 * j + 0], dat[off + 2 * j + 1]);\r\n  \
    \    }\r\n    }\r\n    all_Y = Y;\r\n    sort(all(all_Y));\r\n  }\r\n\r\n  //\
    \ \u6700\u521D\u306B\u4E0E\u3048\u305F\u70B9\u7FA4\u306E index\r\n  void multiply(int\
    \ raw_idx, S val) {\r\n    int i = 1, p = pos[raw_idx];\r\n    while (1) {\r\n\
    \      multiply_i(i, p - indptr[i], val);\r\n      if (i >= size) break;\r\n \
    \     int lc = to_left[p] - to_left[indptr[i]];\r\n      int rc = (p - indptr[i])\
    \ - lc;\r\n      if (to_left[p + 1] - to_left[p]) {\r\n        p = indptr[2 *\
    \ i + 0] + lc;\r\n        i = 2 * i + 0;\r\n      } else {\r\n        p = indptr[2\
    \ * i + 1] + rc;\r\n        i = 2 * i + 1;\r\n      }\r\n    }\r\n  }\r\n\r\n\
    \  // \u6700\u521D\u306B\u4E0E\u3048\u305F\u70B9\u7FA4\u306E index\r\n  void set(int\
    \ raw_idx, S val) {\r\n    int i = 1, p = pos[raw_idx];\r\n    while (1) {\r\n\
    \      set_i(i, p - indptr[i], val);\r\n      if (i >= size) break;\r\n      int\
    \ lc = to_left[p] - to_left[indptr[i]];\r\n      int rc = (p - indptr[i]) - lc;\r\
    \n      if (to_left[p + 1] - to_left[p]) {\r\n        p = indptr[2 * i + 0] +\
    \ lc;\r\n        i = 2 * i + 0;\r\n      } else {\r\n        p = indptr[2 * i\
    \ + 1] + rc;\r\n        i = 2 * i + 1;\r\n      }\r\n    }\r\n  }\r\n\r\n  S prod(XY\
    \ lx, XY rx, XY ly, XY ry) {\r\n    int L = xtoi(lx), R = xtoi(rx);\r\n    S res\
    \ = MX::unit();\r\n    auto dfs = [&](auto& dfs, int i, int l, int r, int a, int\
    \ b) -> void {\r\n      if (a == b || R <= l || r <= L) return;\r\n      if (L\
    \ <= l && r <= R) {\r\n        res = MX::op(res, prod_i(i, a, b));\r\n       \
    \ return;\r\n      }\r\n      int la = to_left[indptr[i] + a] - to_left[indptr[i]];\r\
    \n      int ra = a - la;\r\n      int lb = to_left[indptr[i] + b] - to_left[indptr[i]];\r\
    \n      int rb = b - lb;\r\n      int m = (l + r) / 2;\r\n      dfs(dfs, 2 * i\
    \ + 0, l, m, la, lb);\r\n      dfs(dfs, 2 * i + 1, m, r, ra, rb);\r\n    };\r\n\
    \    dfs(dfs, 1, 0, size, LB(all_Y, ly), LB(all_Y, ry));\r\n    return res;\r\n\
    \  }\r\n\r\n  // \u77E9\u5F62\u5185\u306E\u5168\u70B9\u3092\u6570\u3048\u308B\
    , NlogN\r\n  int count(XY lx, XY rx, XY ly, XY ry) {\r\n    int L = xtoi(lx),\
    \ R = xtoi(rx);\r\n    int res = 0;\r\n    auto dfs = [&](auto& dfs, int i, int\
    \ l, int r, int a, int b) -> void {\r\n      if (a == b || R <= l || r <= L) return;\r\
    \n      if (L <= l && r <= R) {\r\n        res += b - a;\r\n        return;\r\n\
    \      }\r\n      int la = to_left[indptr[i] + a] - to_left[indptr[i]];\r\n  \
    \    int ra = a - la;\r\n      int lb = to_left[indptr[i] + b] - to_left[indptr[i]];\r\
    \n      int rb = b - lb;\r\n      int m = (l + r) / 2;\r\n      dfs(dfs, 2 * i\
    \ + 0, l, m, la, lb);\r\n      dfs(dfs, 2 * i + 1, m, r, ra, rb);\r\n    };\r\n\
    \    dfs(dfs, 1, 0, size, LB(all_Y, ly), LB(all_Y, ry));\r\n    return res;\r\n\
    \  }\r\n\r\nprivate:\r\n  inline int xtoi(XY x) {\r\n    if constexpr (SMALL_X)\
    \ return clamp<XY>(x - minX, 0, NX);\r\n    return LB(keyX, x);\r\n  }\r\n\r\n\
    \  S prod_i(int i, int a, int b) {\r\n    int LID = indptr[i], n = indptr[i +\
    \ 1] - indptr[i];\r\n    int off = 2 * LID;\r\n    int L = n + a, R = n + b;\r\
    \n    S val = MX::unit();\r\n    while (L < R) {\r\n      if (L & 1) val = MX::op(val,\
    \ dat[off + (L++)]);\r\n      if (R & 1) val = MX::op(dat[off + (--R)], val);\r\
    \n      L >>= 1, R >>= 1;\r\n    }\r\n    return val;\r\n  }\r\n  void multiply_i(int\
    \ i, int j, S val) {\r\n    int LID = indptr[i], n = indptr[i + 1] - indptr[i];\r\
    \n    int off = 2 * LID;\r\n    j += n;\r\n    while (j) {\r\n      dat[off +\
    \ j] = MX::op(dat[off + j], val);\r\n      j >>= 1;\r\n    }\r\n  }\r\n  void\
    \ set_i(int i, int j, S val) {\r\n    int LID = indptr[i], n = indptr[i + 1] -\
    \ indptr[i];\r\n    int off = 2 * LID;\r\n    j += n;\r\n    dat[off + j] = val;\r\
    \n    while (j > 1) {\r\n      j /= 2;\r\n      dat[off + j] = MX::op(dat[off\
    \ + 2 * j + 0], dat[off + 2 * j + 1]);\r\n    }\r\n  }\r\n};\r\n"
  code: "// \u70B9\u306E\u91CD\u8907 OK\r\ntemplate <typename Monoid, typename XY,\
    \ bool SMALL_X = false>\r\nstruct SegTree_2D {\r\n  using MX = Monoid;\r\n  using\
    \ S = typename MX::value_type;\r\n  static_assert(MX::commute);\r\n  int N;\r\n\
    \  // X to idx\r\n  vc<XY> keyX;\r\n  int minX;\r\n  // top node \u306E\u70B9\u5217\
    \r\n  vc<XY> all_Y;\r\n  vc<int> pos;\r\n  // segtree data\r\n  int NX, log, size;\r\
    \n  vc<int> indptr;\r\n  vc<S> dat;\r\n  // fractional cascading\r\n  vc<int>\
    \ to_left;\r\n\r\n  SegTree_2D(vc<XY>& X, vc<XY>& Y)\r\n      : SegTree_2D(len(X),\
    \ [&](int i) -> tuple<XY, XY, S> {\r\n          return {X[i], Y[i], MX::unit()};\r\
    \n        }) {}\r\n\r\n  SegTree_2D(vc<XY>& X, vc<XY>& Y, vc<S>& vals)\r\n   \
    \   : SegTree_2D(len(X), [&](int i) -> tuple<XY, XY, S> {\r\n          return\
    \ {X[i], Y[i], vals[i]};\r\n        }) {}\r\n\r\n  // f(i) = (x,y,val)\r\n  template\
    \ <typename F>\r\n  SegTree_2D(int N, F f) {\r\n    vc<XY> X(N), Y(N);\r\n   \
    \ vc<S> wt(N);\r\n    FOR(i, N) {\r\n      auto [a, b, c] = f(i);\r\n      X[i]\
    \ = a, Y[i] = b, wt[i] = c;\r\n    }\r\n    if (!SMALL_X) {\r\n      keyX = X;\r\
    \n      UNIQUE(keyX);\r\n      NX = len(keyX);\r\n    } else {\r\n      minX =\
    \ (X.empty() ? 0 : MIN(X));\r\n      NX = (X.empty() ? 1 : MAX(X) - minX + 1);\r\
    \n    }\r\n\r\n    log = 0;\r\n    while ((1 << log) < NX) ++log;\r\n    size\
    \ = (1 << log);\r\n\r\n    vc<int> IX(N);\r\n    FOR(i, N) IX[i] = xtoi(X[i]);\r\
    \n    indptr.assign(2 * size, 0);\r\n    for (auto i: IX) {\r\n      i += size;\r\
    \n      while (i) indptr[i]++, i /= 2;\r\n    }\r\n    indptr = cumsum<int>(indptr);\r\
    \n    dat.assign(2 * indptr.back(), MX::unit());\r\n    to_left.assign(indptr[size],\
    \ 0);\r\n\r\n    vc<int> ptr = indptr;\r\n    vc<int> I = argsort(Y);\r\n    pos.resize(N);\r\
    \n    FOR(i, N) pos[I[i]] = i;\r\n    for (auto raw_idx: I) {\r\n      int i =\
    \ IX[raw_idx] + size;\r\n      int j = -1;\r\n      while (i) {\r\n        int\
    \ p = ptr[i];\r\n        ptr[i]++;\r\n        dat[indptr[i + 1] + p] = wt[raw_idx];\r\
    \n        if (j != -1) { to_left[p] = (j % 2 == 0); }\r\n        j = i, i /= 2;\r\
    \n      }\r\n    }\r\n    to_left = cumsum<int>(to_left);\r\n\r\n    FOR(i, 2\
    \ * size) {\r\n      int off = 2 * indptr[i], n = indptr[i + 1] - indptr[i];\r\
    \n      FOR_R(j, 1, n) {\r\n        dat[off + j] = MX::op(dat[off + 2 * j + 0],\
    \ dat[off + 2 * j + 1]);\r\n      }\r\n    }\r\n    all_Y = Y;\r\n    sort(all(all_Y));\r\
    \n  }\r\n\r\n  // \u6700\u521D\u306B\u4E0E\u3048\u305F\u70B9\u7FA4\u306E index\r\
    \n  void multiply(int raw_idx, S val) {\r\n    int i = 1, p = pos[raw_idx];\r\n\
    \    while (1) {\r\n      multiply_i(i, p - indptr[i], val);\r\n      if (i >=\
    \ size) break;\r\n      int lc = to_left[p] - to_left[indptr[i]];\r\n      int\
    \ rc = (p - indptr[i]) - lc;\r\n      if (to_left[p + 1] - to_left[p]) {\r\n \
    \       p = indptr[2 * i + 0] + lc;\r\n        i = 2 * i + 0;\r\n      } else\
    \ {\r\n        p = indptr[2 * i + 1] + rc;\r\n        i = 2 * i + 1;\r\n     \
    \ }\r\n    }\r\n  }\r\n\r\n  // \u6700\u521D\u306B\u4E0E\u3048\u305F\u70B9\u7FA4\
    \u306E index\r\n  void set(int raw_idx, S val) {\r\n    int i = 1, p = pos[raw_idx];\r\
    \n    while (1) {\r\n      set_i(i, p - indptr[i], val);\r\n      if (i >= size)\
    \ break;\r\n      int lc = to_left[p] - to_left[indptr[i]];\r\n      int rc =\
    \ (p - indptr[i]) - lc;\r\n      if (to_left[p + 1] - to_left[p]) {\r\n      \
    \  p = indptr[2 * i + 0] + lc;\r\n        i = 2 * i + 0;\r\n      } else {\r\n\
    \        p = indptr[2 * i + 1] + rc;\r\n        i = 2 * i + 1;\r\n      }\r\n\
    \    }\r\n  }\r\n\r\n  S prod(XY lx, XY rx, XY ly, XY ry) {\r\n    int L = xtoi(lx),\
    \ R = xtoi(rx);\r\n    S res = MX::unit();\r\n    auto dfs = [&](auto& dfs, int\
    \ i, int l, int r, int a, int b) -> void {\r\n      if (a == b || R <= l || r\
    \ <= L) return;\r\n      if (L <= l && r <= R) {\r\n        res = MX::op(res,\
    \ prod_i(i, a, b));\r\n        return;\r\n      }\r\n      int la = to_left[indptr[i]\
    \ + a] - to_left[indptr[i]];\r\n      int ra = a - la;\r\n      int lb = to_left[indptr[i]\
    \ + b] - to_left[indptr[i]];\r\n      int rb = b - lb;\r\n      int m = (l + r)\
    \ / 2;\r\n      dfs(dfs, 2 * i + 0, l, m, la, lb);\r\n      dfs(dfs, 2 * i + 1,\
    \ m, r, ra, rb);\r\n    };\r\n    dfs(dfs, 1, 0, size, LB(all_Y, ly), LB(all_Y,\
    \ ry));\r\n    return res;\r\n  }\r\n\r\n  // \u77E9\u5F62\u5185\u306E\u5168\u70B9\
    \u3092\u6570\u3048\u308B, NlogN\r\n  int count(XY lx, XY rx, XY ly, XY ry) {\r\
    \n    int L = xtoi(lx), R = xtoi(rx);\r\n    int res = 0;\r\n    auto dfs = [&](auto&\
    \ dfs, int i, int l, int r, int a, int b) -> void {\r\n      if (a == b || R <=\
    \ l || r <= L) return;\r\n      if (L <= l && r <= R) {\r\n        res += b -\
    \ a;\r\n        return;\r\n      }\r\n      int la = to_left[indptr[i] + a] -\
    \ to_left[indptr[i]];\r\n      int ra = a - la;\r\n      int lb = to_left[indptr[i]\
    \ + b] - to_left[indptr[i]];\r\n      int rb = b - lb;\r\n      int m = (l + r)\
    \ / 2;\r\n      dfs(dfs, 2 * i + 0, l, m, la, lb);\r\n      dfs(dfs, 2 * i + 1,\
    \ m, r, ra, rb);\r\n    };\r\n    dfs(dfs, 1, 0, size, LB(all_Y, ly), LB(all_Y,\
    \ ry));\r\n    return res;\r\n  }\r\n\r\nprivate:\r\n  inline int xtoi(XY x) {\r\
    \n    if constexpr (SMALL_X) return clamp<XY>(x - minX, 0, NX);\r\n    return\
    \ LB(keyX, x);\r\n  }\r\n\r\n  S prod_i(int i, int a, int b) {\r\n    int LID\
    \ = indptr[i], n = indptr[i + 1] - indptr[i];\r\n    int off = 2 * LID;\r\n  \
    \  int L = n + a, R = n + b;\r\n    S val = MX::unit();\r\n    while (L < R) {\r\
    \n      if (L & 1) val = MX::op(val, dat[off + (L++)]);\r\n      if (R & 1) val\
    \ = MX::op(dat[off + (--R)], val);\r\n      L >>= 1, R >>= 1;\r\n    }\r\n   \
    \ return val;\r\n  }\r\n  void multiply_i(int i, int j, S val) {\r\n    int LID\
    \ = indptr[i], n = indptr[i + 1] - indptr[i];\r\n    int off = 2 * LID;\r\n  \
    \  j += n;\r\n    while (j) {\r\n      dat[off + j] = MX::op(dat[off + j], val);\r\
    \n      j >>= 1;\r\n    }\r\n  }\r\n  void set_i(int i, int j, S val) {\r\n  \
    \  int LID = indptr[i], n = indptr[i + 1] - indptr[i];\r\n    int off = 2 * LID;\r\
    \n    j += n;\r\n    dat[off + j] = val;\r\n    while (j > 1) {\r\n      j /=\
    \ 2;\r\n      dat[off + j] = MX::op(dat[off + 2 * j + 0], dat[off + 2 * j + 1]);\r\
    \n    }\r\n  }\r\n};\r\n"
  dependsOn: []
  isVerificationFile: false
  path: ds/segtree/segtree_2d.hpp
  requiredBy: []
  timestamp: '2023-09-16 20:38:43+09:00'
  verificationStatus: LIBRARY_SOME_WA
  verifiedWith:
  - test/yukicoder/1600.test.cpp
  - test/yukicoder/1625_2.test.cpp
  - test/mytest/seg2d.test.cpp
  - test/library_checker/datastructure/point_add_rectangle_sum_seg2d.test.cpp
  - test_atcoder/abc266h.test.cpp
  - test_atcoder/abc324g2.test.cpp
documentation_of: ds/segtree/segtree_2d.hpp
layout: document
redirect_from:
- /library/ds/segtree/segtree_2d.hpp
- /library/ds/segtree/segtree_2d.hpp.html
title: ds/segtree/segtree_2d.hpp
---
