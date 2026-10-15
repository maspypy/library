---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/1_mytest/seg2d.test.cpp
    title: test/1_mytest/seg2d.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/2_library_checker/data_structure/point_add_rectangle_sum_seg2d.test.cpp
    title: test/2_library_checker/data_structure/point_add_rectangle_sum_seg2d.test.cpp
  - icon: ':x:'
    path: test/3_yukicoder/1600.test.cpp
    title: test/3_yukicoder/1600.test.cpp
  _isVerificationFailed: true
  _pathExtension: hpp
  _verificationStatusIcon: ':question:'
  attributes:
    links:
    - https://github.com/maspypy/library/blob/main/ds/segtree/segtree_2d.hpp
  bundledCode: "#line 1 \"ds/segtree/segtree_2d.hpp\"\n// Source: https://github.com/maspypy/library/blob/main/ds/segtree/segtree_2d.hpp\n\
    // \u70B9\u306E\u91CD\u8907\u304C\u3042\u3063\u3066\u3082\u5225\u306E\u70B9\u3068\
    \u3057\u3066 set \u306A\u3069\u304C\u3055\u308C\u308B\ntemplate <typename Monoid,\
    \ typename XY, bool SMALL_X = false>\nstruct SegTree_2D {\n  using MX = Monoid;\n\
    \  using S = typename MX::value_type;\n  static_assert(MX::commute);\n  int N;\n\
    \  // X to idx\n  vc<XY> keyX;\n  int minX;\n  // top node \u306E\u70B9\u5217\n\
    \  vc<XY> all_Y;\n  vc<int> pos;\n  // segtree data\n  int NX, log, size;\n  vc<int>\
    \ indptr;\n  vc<S> dat;\n  // fractional cascading\n  vc<int> to_left;\n\n  SegTree_2D(vc<XY>&\
    \ X, vc<XY>& Y)\n      : SegTree_2D(len(X), [&](int i) -> tuple<XY, XY, S> {\n\
    \          return {X[i], Y[i], MX::id()};\n        }) {}\n\n  SegTree_2D(vc<XY>&\
    \ X, vc<XY>& Y, vc<S>& vals)\n      : SegTree_2D(len(X), [&](int i) -> tuple<XY,\
    \ XY, S> {\n          return {X[i], Y[i], vals[i]};\n        }) {}\n\n  // f(i)\
    \ = (x,y,val)\n  template <typename F>\n  SegTree_2D(int N, F f) {\n    vc<XY>\
    \ X(N), Y(N);\n    vc<S> wt(N);\n    FOR(i, N) {\n      auto [a, b, c] = f(i);\n\
    \      X[i] = a, Y[i] = b, wt[i] = c;\n    }\n    if (!SMALL_X) {\n      keyX\
    \ = X;\n      UNIQUE(keyX);\n      NX = len(keyX);\n    } else {\n      minX =\
    \ (X.empty() ? 0 : MIN(X));\n      NX = (X.empty() ? 1 : MAX(X) - minX + 1);\n\
    \    }\n\n    log = 0;\n    while ((1 << log) < NX) ++log;\n    size = (1 << log);\n\
    \n    vc<int> IX(N);\n    FOR(i, N) IX[i] = xtoi(X[i]);\n    indptr.assign(2 *\
    \ size, 0);\n    for (auto i: IX) {\n      i += size;\n      while (i) indptr[i]++,\
    \ i /= 2;\n    }\n    indptr = cumsum<int>(indptr);\n    dat.assign(2 * indptr.back(),\
    \ MX::id());\n    to_left.assign(indptr[size], 0);\n\n    vc<int> ptr = indptr;\n\
    \    vc<int> I = argsort(Y);\n    pos.resize(N);\n    FOR(i, N) pos[I[i]] = i;\n\
    \    for (auto raw_idx: I) {\n      int i = IX[raw_idx] + size;\n      int j =\
    \ -1;\n      while (i) {\n        int p = ptr[i];\n        ptr[i]++;\n       \
    \ dat[indptr[i + 1] + p] = wt[raw_idx];\n        if (j != -1) { to_left[p] = (j\
    \ % 2 == 0); }\n        j = i, i /= 2;\n      }\n    }\n    to_left = cumsum<int>(to_left);\n\
    \n    FOR(i, 2 * size) {\n      int off = 2 * indptr[i], n = indptr[i + 1] - indptr[i];\n\
    \      FOR_R(j, 1, n) {\n        dat[off + j] = MX::op(dat[off + 2 * j + 0], dat[off\
    \ + 2 * j + 1]);\n      }\n    }\n    all_Y = Y;\n    sort(all(all_Y));\n  }\n\
    \n  // \u6700\u521D\u306B\u4E0E\u3048\u305F\u70B9\u7FA4\u306E index\n  void multiply(int\
    \ raw_idx, S val) {\n    int i = 1, p = pos[raw_idx];\n    while (1) {\n     \
    \ multiply_i(i, p - indptr[i], val);\n      if (i >= size) break;\n      int lc\
    \ = to_left[p] - to_left[indptr[i]];\n      int rc = (p - indptr[i]) - lc;\n \
    \     if (to_left[p + 1] - to_left[p]) {\n        p = indptr[2 * i + 0] + lc;\n\
    \        i = 2 * i + 0;\n      } else {\n        p = indptr[2 * i + 1] + rc;\n\
    \        i = 2 * i + 1;\n      }\n    }\n  }\n\n  // \u6700\u521D\u306B\u4E0E\u3048\
    \u305F\u70B9\u7FA4\u306E index\n  void set(int raw_idx, S val) {\n    int i =\
    \ 1, p = pos[raw_idx];\n    while (1) {\n      set_i(i, p - indptr[i], val);\n\
    \      if (i >= size) break;\n      int lc = to_left[p] - to_left[indptr[i]];\n\
    \      int rc = (p - indptr[i]) - lc;\n      if (to_left[p + 1] - to_left[p])\
    \ {\n        p = indptr[2 * i + 0] + lc;\n        i = 2 * i + 0;\n      } else\
    \ {\n        p = indptr[2 * i + 1] + rc;\n        i = 2 * i + 1;\n      }\n  \
    \  }\n  }\n\n  S prod(XY lx, XY rx, XY ly, XY ry) {\n    assert(lx <= rx && ly\
    \ <= ry);\n    int L = xtoi(lx), R = xtoi(rx);\n    S res = MX::id();\n    auto\
    \ dfs = [&](auto& dfs, int i, int l, int r, int a, int b) -> void {\n      if\
    \ (a == b || R <= l || r <= L) return;\n      if (L <= l && r <= R) {\n      \
    \  res = MX::op(res, prod_i(i, a, b));\n        return;\n      }\n      int la\
    \ = to_left[indptr[i] + a] - to_left[indptr[i]];\n      int ra = a - la;\n   \
    \   int lb = to_left[indptr[i] + b] - to_left[indptr[i]];\n      int rb = b -\
    \ lb;\n      int m = (l + r) / 2;\n      dfs(dfs, 2 * i + 0, l, m, la, lb);\n\
    \      dfs(dfs, 2 * i + 1, m, r, ra, rb);\n    };\n    dfs(dfs, 1, 0, size, LB(all_Y,\
    \ ly), LB(all_Y, ry));\n    return res;\n  }\n\n  // \u77E9\u5F62\u5185\u306E\u5168\
    \u70B9\u3092\u6570\u3048\u308B, NlogN\n  int count(XY lx, XY rx, XY ly, XY ry)\
    \ {\n    assert(lx <= rx && ly <= ry);\n    int L = xtoi(lx), R = xtoi(rx);\n\
    \    int res = 0;\n    auto dfs = [&](auto& dfs, int i, int l, int r, int a, int\
    \ b) -> void {\n      if (a == b || R <= l || r <= L) return;\n      if (L <=\
    \ l && r <= R) {\n        res += b - a;\n        return;\n      }\n      int la\
    \ = to_left[indptr[i] + a] - to_left[indptr[i]];\n      int ra = a - la;\n   \
    \   int lb = to_left[indptr[i] + b] - to_left[indptr[i]];\n      int rb = b -\
    \ lb;\n      int m = (l + r) / 2;\n      dfs(dfs, 2 * i + 0, l, m, la, lb);\n\
    \      dfs(dfs, 2 * i + 1, m, r, ra, rb);\n    };\n    dfs(dfs, 1, 0, size, LB(all_Y,\
    \ ly), LB(all_Y, ry));\n    return res;\n  }\n\nprivate:\n  inline int xtoi(XY\
    \ x) {\n    if constexpr (SMALL_X) return clamp<XY>(x - minX, 0, NX);\n    return\
    \ LB(keyX, x);\n  }\n\n  S prod_i(int i, int a, int b) {\n    int LID = indptr[i],\
    \ n = indptr[i + 1] - indptr[i];\n    int off = 2 * LID;\n    int L = n + a, R\
    \ = n + b;\n    S val = MX::id();\n    while (L < R) {\n      if (L & 1) val =\
    \ MX::op(val, dat[off + (L++)]);\n      if (R & 1) val = MX::op(dat[off + (--R)],\
    \ val);\n      L >>= 1, R >>= 1;\n    }\n    return val;\n  }\n  void multiply_i(int\
    \ i, int j, S val) {\n    int LID = indptr[i], n = indptr[i + 1] - indptr[i];\n\
    \    int off = 2 * LID;\n    j += n;\n    while (j) {\n      dat[off + j] = MX::op(dat[off\
    \ + j], val);\n      j >>= 1;\n    }\n  }\n  void set_i(int i, int j, S val) {\n\
    \    int LID = indptr[i], n = indptr[i + 1] - indptr[i];\n    int off = 2 * LID;\n\
    \    j += n;\n    dat[off + j] = val;\n    while (j > 1) {\n      j /= 2;\n  \
    \    dat[off + j] = MX::op(dat[off + 2 * j + 0], dat[off + 2 * j + 1]);\n    }\n\
    \  }\n};\n"
  code: "// Source: https://github.com/maspypy/library/blob/main/ds/segtree/segtree_2d.hpp\n\
    // \u70B9\u306E\u91CD\u8907\u304C\u3042\u3063\u3066\u3082\u5225\u306E\u70B9\u3068\
    \u3057\u3066 set \u306A\u3069\u304C\u3055\u308C\u308B\ntemplate <typename Monoid,\
    \ typename XY, bool SMALL_X = false>\nstruct SegTree_2D {\n  using MX = Monoid;\n\
    \  using S = typename MX::value_type;\n  static_assert(MX::commute);\n  int N;\n\
    \  // X to idx\n  vc<XY> keyX;\n  int minX;\n  // top node \u306E\u70B9\u5217\n\
    \  vc<XY> all_Y;\n  vc<int> pos;\n  // segtree data\n  int NX, log, size;\n  vc<int>\
    \ indptr;\n  vc<S> dat;\n  // fractional cascading\n  vc<int> to_left;\n\n  SegTree_2D(vc<XY>&\
    \ X, vc<XY>& Y)\n      : SegTree_2D(len(X), [&](int i) -> tuple<XY, XY, S> {\n\
    \          return {X[i], Y[i], MX::id()};\n        }) {}\n\n  SegTree_2D(vc<XY>&\
    \ X, vc<XY>& Y, vc<S>& vals)\n      : SegTree_2D(len(X), [&](int i) -> tuple<XY,\
    \ XY, S> {\n          return {X[i], Y[i], vals[i]};\n        }) {}\n\n  // f(i)\
    \ = (x,y,val)\n  template <typename F>\n  SegTree_2D(int N, F f) {\n    vc<XY>\
    \ X(N), Y(N);\n    vc<S> wt(N);\n    FOR(i, N) {\n      auto [a, b, c] = f(i);\n\
    \      X[i] = a, Y[i] = b, wt[i] = c;\n    }\n    if (!SMALL_X) {\n      keyX\
    \ = X;\n      UNIQUE(keyX);\n      NX = len(keyX);\n    } else {\n      minX =\
    \ (X.empty() ? 0 : MIN(X));\n      NX = (X.empty() ? 1 : MAX(X) - minX + 1);\n\
    \    }\n\n    log = 0;\n    while ((1 << log) < NX) ++log;\n    size = (1 << log);\n\
    \n    vc<int> IX(N);\n    FOR(i, N) IX[i] = xtoi(X[i]);\n    indptr.assign(2 *\
    \ size, 0);\n    for (auto i: IX) {\n      i += size;\n      while (i) indptr[i]++,\
    \ i /= 2;\n    }\n    indptr = cumsum<int>(indptr);\n    dat.assign(2 * indptr.back(),\
    \ MX::id());\n    to_left.assign(indptr[size], 0);\n\n    vc<int> ptr = indptr;\n\
    \    vc<int> I = argsort(Y);\n    pos.resize(N);\n    FOR(i, N) pos[I[i]] = i;\n\
    \    for (auto raw_idx: I) {\n      int i = IX[raw_idx] + size;\n      int j =\
    \ -1;\n      while (i) {\n        int p = ptr[i];\n        ptr[i]++;\n       \
    \ dat[indptr[i + 1] + p] = wt[raw_idx];\n        if (j != -1) { to_left[p] = (j\
    \ % 2 == 0); }\n        j = i, i /= 2;\n      }\n    }\n    to_left = cumsum<int>(to_left);\n\
    \n    FOR(i, 2 * size) {\n      int off = 2 * indptr[i], n = indptr[i + 1] - indptr[i];\n\
    \      FOR_R(j, 1, n) {\n        dat[off + j] = MX::op(dat[off + 2 * j + 0], dat[off\
    \ + 2 * j + 1]);\n      }\n    }\n    all_Y = Y;\n    sort(all(all_Y));\n  }\n\
    \n  // \u6700\u521D\u306B\u4E0E\u3048\u305F\u70B9\u7FA4\u306E index\n  void multiply(int\
    \ raw_idx, S val) {\n    int i = 1, p = pos[raw_idx];\n    while (1) {\n     \
    \ multiply_i(i, p - indptr[i], val);\n      if (i >= size) break;\n      int lc\
    \ = to_left[p] - to_left[indptr[i]];\n      int rc = (p - indptr[i]) - lc;\n \
    \     if (to_left[p + 1] - to_left[p]) {\n        p = indptr[2 * i + 0] + lc;\n\
    \        i = 2 * i + 0;\n      } else {\n        p = indptr[2 * i + 1] + rc;\n\
    \        i = 2 * i + 1;\n      }\n    }\n  }\n\n  // \u6700\u521D\u306B\u4E0E\u3048\
    \u305F\u70B9\u7FA4\u306E index\n  void set(int raw_idx, S val) {\n    int i =\
    \ 1, p = pos[raw_idx];\n    while (1) {\n      set_i(i, p - indptr[i], val);\n\
    \      if (i >= size) break;\n      int lc = to_left[p] - to_left[indptr[i]];\n\
    \      int rc = (p - indptr[i]) - lc;\n      if (to_left[p + 1] - to_left[p])\
    \ {\n        p = indptr[2 * i + 0] + lc;\n        i = 2 * i + 0;\n      } else\
    \ {\n        p = indptr[2 * i + 1] + rc;\n        i = 2 * i + 1;\n      }\n  \
    \  }\n  }\n\n  S prod(XY lx, XY rx, XY ly, XY ry) {\n    assert(lx <= rx && ly\
    \ <= ry);\n    int L = xtoi(lx), R = xtoi(rx);\n    S res = MX::id();\n    auto\
    \ dfs = [&](auto& dfs, int i, int l, int r, int a, int b) -> void {\n      if\
    \ (a == b || R <= l || r <= L) return;\n      if (L <= l && r <= R) {\n      \
    \  res = MX::op(res, prod_i(i, a, b));\n        return;\n      }\n      int la\
    \ = to_left[indptr[i] + a] - to_left[indptr[i]];\n      int ra = a - la;\n   \
    \   int lb = to_left[indptr[i] + b] - to_left[indptr[i]];\n      int rb = b -\
    \ lb;\n      int m = (l + r) / 2;\n      dfs(dfs, 2 * i + 0, l, m, la, lb);\n\
    \      dfs(dfs, 2 * i + 1, m, r, ra, rb);\n    };\n    dfs(dfs, 1, 0, size, LB(all_Y,\
    \ ly), LB(all_Y, ry));\n    return res;\n  }\n\n  // \u77E9\u5F62\u5185\u306E\u5168\
    \u70B9\u3092\u6570\u3048\u308B, NlogN\n  int count(XY lx, XY rx, XY ly, XY ry)\
    \ {\n    assert(lx <= rx && ly <= ry);\n    int L = xtoi(lx), R = xtoi(rx);\n\
    \    int res = 0;\n    auto dfs = [&](auto& dfs, int i, int l, int r, int a, int\
    \ b) -> void {\n      if (a == b || R <= l || r <= L) return;\n      if (L <=\
    \ l && r <= R) {\n        res += b - a;\n        return;\n      }\n      int la\
    \ = to_left[indptr[i] + a] - to_left[indptr[i]];\n      int ra = a - la;\n   \
    \   int lb = to_left[indptr[i] + b] - to_left[indptr[i]];\n      int rb = b -\
    \ lb;\n      int m = (l + r) / 2;\n      dfs(dfs, 2 * i + 0, l, m, la, lb);\n\
    \      dfs(dfs, 2 * i + 1, m, r, ra, rb);\n    };\n    dfs(dfs, 1, 0, size, LB(all_Y,\
    \ ly), LB(all_Y, ry));\n    return res;\n  }\n\nprivate:\n  inline int xtoi(XY\
    \ x) {\n    if constexpr (SMALL_X) return clamp<XY>(x - minX, 0, NX);\n    return\
    \ LB(keyX, x);\n  }\n\n  S prod_i(int i, int a, int b) {\n    int LID = indptr[i],\
    \ n = indptr[i + 1] - indptr[i];\n    int off = 2 * LID;\n    int L = n + a, R\
    \ = n + b;\n    S val = MX::id();\n    while (L < R) {\n      if (L & 1) val =\
    \ MX::op(val, dat[off + (L++)]);\n      if (R & 1) val = MX::op(dat[off + (--R)],\
    \ val);\n      L >>= 1, R >>= 1;\n    }\n    return val;\n  }\n  void multiply_i(int\
    \ i, int j, S val) {\n    int LID = indptr[i], n = indptr[i + 1] - indptr[i];\n\
    \    int off = 2 * LID;\n    j += n;\n    while (j) {\n      dat[off + j] = MX::op(dat[off\
    \ + j], val);\n      j >>= 1;\n    }\n  }\n  void set_i(int i, int j, S val) {\n\
    \    int LID = indptr[i], n = indptr[i + 1] - indptr[i];\n    int off = 2 * LID;\n\
    \    j += n;\n    dat[off + j] = val;\n    while (j > 1) {\n      j /= 2;\n  \
    \    dat[off + j] = MX::op(dat[off + 2 * j + 0], dat[off + 2 * j + 1]);\n    }\n\
    \  }\n};\n"
  dependsOn: []
  isVerificationFile: false
  path: ds/segtree/segtree_2d.hpp
  requiredBy: []
  timestamp: '2026-10-15 19:54:56+09:00'
  verificationStatus: LIBRARY_SOME_WA
  verifiedWith:
  - test/1_mytest/seg2d.test.cpp
  - test/3_yukicoder/1600.test.cpp
  - test/2_library_checker/data_structure/point_add_rectangle_sum_seg2d.test.cpp
documentation_of: ds/segtree/segtree_2d.hpp
layout: document
redirect_from:
- /library/ds/segtree/segtree_2d.hpp
- /library/ds/segtree/segtree_2d.hpp.html
title: ds/segtree/segtree_2d.hpp
---
