---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':warning:'
  attributes:
    links: []
  bundledCode: "#line 1 \"ds/wavelet_matrix/wavelet_matrix_2d_range_dynamic_monoid.hpp\"\
    \ntemplate <typename Monoid, typename XY, bool SMALL_X, bool SMALL_Y>\nstruct\
    \ Wavelet_Matrix_2D_Range_Dynamic_Monoid {\n  // \u70B9\u7FA4\u3092 Y \u6607\u9806\
    \u306B\u4E26\u3079\u308B.\n  // X \u3092\u6574\u6570\u306B\u306A\u304A\u3057\u3066\
    \ binary trie \u307F\u305F\u3044\u306B\u632F\u308A\u5206\u3051\u308B\n  using\
    \ MX = Monoid;\n  using X = typename MX::value_type;\n  static_assert(MX::commute);\n\
    \n  template <bool SMALL>\n  struct TO_IDX {\n    vc<XY> key;\n    XY mi, ma;\n\
    \    vc<int> dat;\n\n    void build(vc<XY>& X) {\n      if constexpr (SMALL) {\n\
    \        mi = (X.empty() ? 0 : MIN(X));\n        ma = (X.empty() ? 0 : MAX(X));\n\
    \        dat.assign(ma - mi + 2, 0);\n        for (auto& x: X) { dat[x - mi +\
    \ 1]++; }\n        FOR(i, len(dat) - 1) dat[i + 1] += dat[i];\n      } else {\n\
    \        key = X;\n        sort(all(key));\n      }\n    }\n    int operator()(XY\
    \ x) {\n      if constexpr (SMALL) {\n        return dat[clamp<XY>(x - mi, 0,\
    \ ma - mi + 1)];\n      } else {\n        return LB(key, x);\n      }\n    }\n\
    \  };\n\n  TO_IDX<SMALL_X> XtoI;\n  TO_IDX<SMALL_Y> YtoI;\n\n  int N, lg;\n  vector<int>\
    \ mid;\n  vector<Bit_Vector> bv;\n  vc<int> new_idx;\n  vc<int> A;\n  // \u5404\
    \u6BB5\u306B fenwick tree\n  vc<SegTree<Monoid>> dat;\n\n  template <typename\
    \ F>\n  Wavelet_Matrix_2D_Range_Dynamic_Monoid(int N, F f) {\n    build(N, f);\n\
    \  }\n\n  template <typename F>\n  void build(int N_, F f) {\n    N = N_;\n  \
    \  if (N == 0) {\n      lg = 0;\n      return;\n    }\n    vc<XY> tmp(N), Y(N);\n\
    \    vc<X> S(N);\n    FOR(i, N) tie(tmp[i], Y[i], S[i]) = f(i);\n    auto I =\
    \ argsort(Y);\n    tmp = rearrange(tmp, I), Y = rearrange(Y, I), S = rearrange(S,\
    \ I);\n    XtoI.build(tmp), YtoI.build(Y);\n    new_idx.resize(N);\n    FOR(i,\
    \ N) new_idx[I[i]] = i;\n\n    // \u3042\u3068\u306F\u666E\u901A\u306B\n    lg\
    \ = __lg(XtoI(MAX(tmp) + 1)) + 1;\n    mid.resize(lg), bv.assign(lg, Bit_Vector(N));\n\
    \    dat.resize(lg);\n    A.resize(N);\n    FOR(i, N) A[i] = XtoI(tmp[i]);\n\n\
    \    vc<int> A0(N), A1(N);\n    vc<X> S0(N), S1(N);\n    FOR_R(d, lg) {\n    \
    \  int p0 = 0, p1 = 0;\n      FOR(i, N) {\n        bool f = (A[i] >> d & 1);\n\
    \        if (!f) { S0[p0] = S[i], A0[p0] = A[i], p0++; }\n        if (f) { S1[p1]\
    \ = S[i], A1[p1] = A[i], bv[d].set(i), p1++; }\n      }\n      mid[d] = p0;\n\
    \      bv[d].build();\n      swap(A, A0), swap(S, S0);\n      FOR(i, p1) A[p0\
    \ + i] = A1[i], S[p0 + i] = S1[i];\n      dat[d].build(N, [&](int i) -> X { return\
    \ S[i]; });\n    }\n    FOR(i, N) A[i] = XtoI(tmp[i]);\n  }\n\n  int count(XY\
    \ x1, XY x2, XY y1, XY y2) {\n    x1 = XtoI(x1), x2 = XtoI(x2);\n    y1 = YtoI(y1),\
    \ y2 = YtoI(y2);\n    return prefix_count(y1, y2, x2) - prefix_count(y1, y2, x1);\n\
    \  }\n\n  X prod(XY x1, XY x2, XY y1, XY y2) {\n    assert(x1 <= x2 && y1 <= y2);\n\
    \    x1 = XtoI(x1), x2 = XtoI(x2);\n    y1 = YtoI(y1), y2 = YtoI(y2);\n    X res\
    \ = MX::unit();\n    prod_dfs(y1, y2, x1, x2, lg - 1, res);\n    return res;\n\
    \  }\n\n  // \u6700\u521D\u306B\u4E0E\u3048\u305F\u70B9\u7FA4\u306E index\n  void\
    \ set(int i, X x) {\n    assert(0 <= i && i < N);\n    i = new_idx[i];\n    int\
    \ a = A[i];\n    FOR_R(d, lg) {\n      if (a >> d & 1) {\n        i = mid[d] +\
    \ bv[d].rank(i, 1);\n      } else {\n        i = bv[d].rank(i, 0);\n      }\n\
    \      dat[d].set(i, x);\n    }\n  }\n\nprivate:\n  int prefix_count(int L, int\
    \ R, int x) {\n    int cnt = 0;\n    FOR_R(d, lg) {\n      int l0 = bv[d].rank(L,\
    \ 0), r0 = bv[d].rank(R, 0);\n      if (x >> d & 1) {\n        cnt += r0 - l0,\
    \ L += mid[d] - l0, R += mid[d] - r0;\n      } else {\n        L = l0, R = r0;\n\
    \      }\n    }\n    return cnt;\n  }\n\n  void prod_dfs(int L, int R, int x1,\
    \ int x2, int d, X& res) {\n    chmax(x1, 0), chmin(x2, 1 << (d + 1));\n    if\
    \ (x1 >= x2) { return; }\n    assert(0 <= x1 && x1 < x2 && x2 <= (1 << (d + 1)));\n\
    \    if (x1 == 0 && x2 == (1 << (d + 1))) {\n      res = MX::op(res, dat[d + 1].prod(L,\
    \ R));\n      return;\n    }\n    int l0 = bv[d].rank(L, 0), r0 = bv[d].rank(R,\
    \ 0);\n    prod_dfs(l0, r0, x1, x2, d - 1, res);\n    prod_dfs(L + mid[d] - l0,\
    \ R + mid[d] - r0, x1 - (1 << d), x2 - (1 << d),\n             d - 1, res);\n\
    \  }\n};\n\nvoid solve() {\n  LL(N, Q);\n  vc<u32> X(N), Y(N);\n  vc<u64> W(N);\n\
    \  FOR(i, N) read(X[i], Y[i], W[i]);\n  using QQ = tuple<u32, u32, u32, u32>;\n\
    \  vc<QQ> query(Q);\n  FOR(q, Q) {\n    LL(t);\n    if (t == 0) {\n      U32(x,\
    \ y, w);\n      X.eb(x);\n      Y.eb(y);\n      W.eb(0);\n      query[q] = mt(-1,\
    \ x, y, w);\n    } else {\n      U32(a, b, c, d);\n      query[q] = mt(a, c, b,\
    \ d);\n    }\n  }\n\n  Wavelet_Matrix_2D_Range_Dynamic_Monoid<Monoid_Add<ll>,\
    \ int, false, false> WM(\n      len(X), [&](int i) -> tuple<int, int, ll> {\n\
    \        return {X[i], Y[i], W[i]};\n      });\n  int idx = N;\n  FOR(q, Q) {\n\
    \    auto [a, b, c, d] = query[q];\n    if (a == u32(-1)) {\n      WM.set(idx++,\
    \ d);\n    } else {\n      print(WM.prod(a, b, c, d));\n    }\n  }\n}\n"
  code: "template <typename Monoid, typename XY, bool SMALL_X, bool SMALL_Y>\nstruct\
    \ Wavelet_Matrix_2D_Range_Dynamic_Monoid {\n  // \u70B9\u7FA4\u3092 Y \u6607\u9806\
    \u306B\u4E26\u3079\u308B.\n  // X \u3092\u6574\u6570\u306B\u306A\u304A\u3057\u3066\
    \ binary trie \u307F\u305F\u3044\u306B\u632F\u308A\u5206\u3051\u308B\n  using\
    \ MX = Monoid;\n  using X = typename MX::value_type;\n  static_assert(MX::commute);\n\
    \n  template <bool SMALL>\n  struct TO_IDX {\n    vc<XY> key;\n    XY mi, ma;\n\
    \    vc<int> dat;\n\n    void build(vc<XY>& X) {\n      if constexpr (SMALL) {\n\
    \        mi = (X.empty() ? 0 : MIN(X));\n        ma = (X.empty() ? 0 : MAX(X));\n\
    \        dat.assign(ma - mi + 2, 0);\n        for (auto& x: X) { dat[x - mi +\
    \ 1]++; }\n        FOR(i, len(dat) - 1) dat[i + 1] += dat[i];\n      } else {\n\
    \        key = X;\n        sort(all(key));\n      }\n    }\n    int operator()(XY\
    \ x) {\n      if constexpr (SMALL) {\n        return dat[clamp<XY>(x - mi, 0,\
    \ ma - mi + 1)];\n      } else {\n        return LB(key, x);\n      }\n    }\n\
    \  };\n\n  TO_IDX<SMALL_X> XtoI;\n  TO_IDX<SMALL_Y> YtoI;\n\n  int N, lg;\n  vector<int>\
    \ mid;\n  vector<Bit_Vector> bv;\n  vc<int> new_idx;\n  vc<int> A;\n  // \u5404\
    \u6BB5\u306B fenwick tree\n  vc<SegTree<Monoid>> dat;\n\n  template <typename\
    \ F>\n  Wavelet_Matrix_2D_Range_Dynamic_Monoid(int N, F f) {\n    build(N, f);\n\
    \  }\n\n  template <typename F>\n  void build(int N_, F f) {\n    N = N_;\n  \
    \  if (N == 0) {\n      lg = 0;\n      return;\n    }\n    vc<XY> tmp(N), Y(N);\n\
    \    vc<X> S(N);\n    FOR(i, N) tie(tmp[i], Y[i], S[i]) = f(i);\n    auto I =\
    \ argsort(Y);\n    tmp = rearrange(tmp, I), Y = rearrange(Y, I), S = rearrange(S,\
    \ I);\n    XtoI.build(tmp), YtoI.build(Y);\n    new_idx.resize(N);\n    FOR(i,\
    \ N) new_idx[I[i]] = i;\n\n    // \u3042\u3068\u306F\u666E\u901A\u306B\n    lg\
    \ = __lg(XtoI(MAX(tmp) + 1)) + 1;\n    mid.resize(lg), bv.assign(lg, Bit_Vector(N));\n\
    \    dat.resize(lg);\n    A.resize(N);\n    FOR(i, N) A[i] = XtoI(tmp[i]);\n\n\
    \    vc<int> A0(N), A1(N);\n    vc<X> S0(N), S1(N);\n    FOR_R(d, lg) {\n    \
    \  int p0 = 0, p1 = 0;\n      FOR(i, N) {\n        bool f = (A[i] >> d & 1);\n\
    \        if (!f) { S0[p0] = S[i], A0[p0] = A[i], p0++; }\n        if (f) { S1[p1]\
    \ = S[i], A1[p1] = A[i], bv[d].set(i), p1++; }\n      }\n      mid[d] = p0;\n\
    \      bv[d].build();\n      swap(A, A0), swap(S, S0);\n      FOR(i, p1) A[p0\
    \ + i] = A1[i], S[p0 + i] = S1[i];\n      dat[d].build(N, [&](int i) -> X { return\
    \ S[i]; });\n    }\n    FOR(i, N) A[i] = XtoI(tmp[i]);\n  }\n\n  int count(XY\
    \ x1, XY x2, XY y1, XY y2) {\n    x1 = XtoI(x1), x2 = XtoI(x2);\n    y1 = YtoI(y1),\
    \ y2 = YtoI(y2);\n    return prefix_count(y1, y2, x2) - prefix_count(y1, y2, x1);\n\
    \  }\n\n  X prod(XY x1, XY x2, XY y1, XY y2) {\n    assert(x1 <= x2 && y1 <= y2);\n\
    \    x1 = XtoI(x1), x2 = XtoI(x2);\n    y1 = YtoI(y1), y2 = YtoI(y2);\n    X res\
    \ = MX::unit();\n    prod_dfs(y1, y2, x1, x2, lg - 1, res);\n    return res;\n\
    \  }\n\n  // \u6700\u521D\u306B\u4E0E\u3048\u305F\u70B9\u7FA4\u306E index\n  void\
    \ set(int i, X x) {\n    assert(0 <= i && i < N);\n    i = new_idx[i];\n    int\
    \ a = A[i];\n    FOR_R(d, lg) {\n      if (a >> d & 1) {\n        i = mid[d] +\
    \ bv[d].rank(i, 1);\n      } else {\n        i = bv[d].rank(i, 0);\n      }\n\
    \      dat[d].set(i, x);\n    }\n  }\n\nprivate:\n  int prefix_count(int L, int\
    \ R, int x) {\n    int cnt = 0;\n    FOR_R(d, lg) {\n      int l0 = bv[d].rank(L,\
    \ 0), r0 = bv[d].rank(R, 0);\n      if (x >> d & 1) {\n        cnt += r0 - l0,\
    \ L += mid[d] - l0, R += mid[d] - r0;\n      } else {\n        L = l0, R = r0;\n\
    \      }\n    }\n    return cnt;\n  }\n\n  void prod_dfs(int L, int R, int x1,\
    \ int x2, int d, X& res) {\n    chmax(x1, 0), chmin(x2, 1 << (d + 1));\n    if\
    \ (x1 >= x2) { return; }\n    assert(0 <= x1 && x1 < x2 && x2 <= (1 << (d + 1)));\n\
    \    if (x1 == 0 && x2 == (1 << (d + 1))) {\n      res = MX::op(res, dat[d + 1].prod(L,\
    \ R));\n      return;\n    }\n    int l0 = bv[d].rank(L, 0), r0 = bv[d].rank(R,\
    \ 0);\n    prod_dfs(l0, r0, x1, x2, d - 1, res);\n    prod_dfs(L + mid[d] - l0,\
    \ R + mid[d] - r0, x1 - (1 << d), x2 - (1 << d),\n             d - 1, res);\n\
    \  }\n};\n\nvoid solve() {\n  LL(N, Q);\n  vc<u32> X(N), Y(N);\n  vc<u64> W(N);\n\
    \  FOR(i, N) read(X[i], Y[i], W[i]);\n  using QQ = tuple<u32, u32, u32, u32>;\n\
    \  vc<QQ> query(Q);\n  FOR(q, Q) {\n    LL(t);\n    if (t == 0) {\n      U32(x,\
    \ y, w);\n      X.eb(x);\n      Y.eb(y);\n      W.eb(0);\n      query[q] = mt(-1,\
    \ x, y, w);\n    } else {\n      U32(a, b, c, d);\n      query[q] = mt(a, c, b,\
    \ d);\n    }\n  }\n\n  Wavelet_Matrix_2D_Range_Dynamic_Monoid<Monoid_Add<ll>,\
    \ int, false, false> WM(\n      len(X), [&](int i) -> tuple<int, int, ll> {\n\
    \        return {X[i], Y[i], W[i]};\n      });\n  int idx = N;\n  FOR(q, Q) {\n\
    \    auto [a, b, c, d] = query[q];\n    if (a == u32(-1)) {\n      WM.set(idx++,\
    \ d);\n    } else {\n      print(WM.prod(a, b, c, d));\n    }\n  }\n}\n"
  dependsOn: []
  isVerificationFile: false
  path: ds/wavelet_matrix/wavelet_matrix_2d_range_dynamic_monoid.hpp
  requiredBy: []
  timestamp: '2024-02-04 20:58:47+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: ds/wavelet_matrix/wavelet_matrix_2d_range_dynamic_monoid.hpp
layout: document
redirect_from:
- /library/ds/wavelet_matrix/wavelet_matrix_2d_range_dynamic_monoid.hpp
- /library/ds/wavelet_matrix/wavelet_matrix_2d_range_dynamic_monoid.hpp.html
title: ds/wavelet_matrix/wavelet_matrix_2d_range_dynamic_monoid.hpp
---
