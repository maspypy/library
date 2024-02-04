---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: ds/bit_vector.hpp
    title: ds/bit_vector.hpp
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/library_checker/datastructure/rectangle_sum_wm.test.cpp
    title: test/library_checker/datastructure/rectangle_sum_wm.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/library_checker/datastructure/rectangle_sum_wm_abel.test.cpp
    title: test/library_checker/datastructure/rectangle_sum_wm_abel.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 1 \"ds/bit_vector.hpp\"\nstruct Bit_Vector {\n  vc<pair<u32,\
    \ u32>> dat;\n  Bit_Vector(int n) { dat.assign((n + 63) >> 5, {0, 0}); }\n\n \
    \ void set(int i) { dat[i >> 5].fi |= u32(1) << (i & 31); }\n\n  void build()\
    \ {\n    FOR(i, len(dat) - 1) dat[i + 1].se = dat[i].se + popcnt(dat[i].fi);\n\
    \  }\n\n  // [0, k) \u5185\u306E 1 \u306E\u500B\u6570\n  int rank(int k, bool\
    \ f = 1) {\n    auto [a, b] = dat[k >> 5];\n    int ret = b + popcnt(a & ((u32(1)\
    \ << (k & 31)) - 1));\n    return (f ? ret : k - ret);\n  }\n};\n#line 2 \"ds/wavelet_matrix/wavelet_matrix_2d_range_static_abelgroup.hpp\"\
    \n\ntemplate <typename Monoid, typename XY, bool SMALL_X, bool SMALL_Y>\nstruct\
    \ Wavelet_Matrix_2D_Range_Static_AbelGroup {\n  // \u70B9\u7FA4\u3092 Y \u6607\
    \u9806\u306B\u4E26\u3079\u308B.\n  // X \u3092\u6574\u6570\u306B\u306A\u304A\u3057\
    \u3066 binary trie \u307F\u305F\u3044\u306B\u632F\u308A\u5206\u3051\u308B\n  using\
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
    \ mid;\n  vector<Bit_Vector> bv;\n  vvc<X> dat;\n\n  template <typename F>\n \
    \ Wavelet_Matrix_2D_Range_Static_AbelGroup(int N, F f) {\n    build(N, f);\n \
    \ }\n\n  template <typename F>\n  void build(int N, F f) {\n    if (N == 0) {\n\
    \      lg = 0;\n      return;\n    }\n    vc<XY> A(N), Y(N);\n    vc<X> S(N);\n\
    \    FOR(i, N) tie(A[i], Y[i], S[i]) = f(i);\n    auto I = argsort(Y);\n    A\
    \ = rearrange(A, I), Y = rearrange(Y, I), S = rearrange(S, I);\n    XtoI.build(A),\
    \ YtoI.build(Y);\n\n    // \u3042\u3068\u306F\u666E\u901A\u306B\n    lg = __lg(XtoI(MAX(A)\
    \ + 1)) + 1;\n    mid.resize(lg), bv.assign(lg, Bit_Vector(N));\n    dat.assign(1\
    \ + lg, vc<X>(N + 1, MX::unit()));\n    FOR(i, N) A[i] = XtoI(A[i]);\n\n    vc<int>\
    \ A0(N), A1(N);\n    vc<X> S0(N), S1(N);\n    FOR_R(d, -1, lg) {\n      int p0\
    \ = 0, p1 = 0;\n      FOR(i, N) { dat[d + 1][i + 1] = MX::op(dat[d + 1][i], S[i]);\
    \ }\n      if (d == -1) break;\n      FOR(i, N) {\n        bool f = (A[i] >> d\
    \ & 1);\n        if (!f) { S0[p0] = S[i], A0[p0] = A[i], p0++; }\n        if (f)\
    \ { S1[p1] = S[i], A1[p1] = A[i], bv[d].set(i), p1++; }\n      }\n      mid[d]\
    \ = p0;\n      bv[d].build();\n      swap(A, A0), swap(S, S0);\n      FOR(i, p1)\
    \ A[p0 + i] = A1[i], S[p0 + i] = S1[i];\n    }\n  }\n\n  int count(XY x1, XY x2,\
    \ XY y1, XY y2) {\n    x1 = XtoI(x1), x2 = XtoI(x2);\n    y1 = YtoI(y1), y2 =\
    \ YtoI(y2);\n    return prefix_count(y1, y2, x2) - prefix_count(y1, y2, x1);\n\
    \  }\n\n  X prod(XY x1, XY x2, XY y1, XY y2) { return sum(x1, x2, y1, y2); }\n\
    \  X sum(XY x1, XY x2, XY y1, XY y2) {\n    assert(x1 <= x2 && y1 <= y2);\n  \
    \  x1 = XtoI(x1), x2 = XtoI(x2);\n    y1 = YtoI(y1), y2 = YtoI(y2);\n    X add\
    \ = prefix_sum(y1, y2, x2);\n    X sub = prefix_sum(y1, y2, x1);\n    return MX::op(add,\
    \ MX::inverse(sub));\n  }\n\nprivate:\n  int prefix_count(int L, int R, int x)\
    \ {\n    int cnt = 0;\n    FOR_R(d, lg) {\n      int l0 = bv[d].rank(L, 0), r0\
    \ = bv[d].rank(R, 0);\n      if (x >> d & 1) {\n        cnt += r0 - l0, L += mid[d]\
    \ - l0, R += mid[d] - r0;\n      } else {\n        L = l0, R = r0;\n      }\n\
    \    }\n    return cnt;\n  }\n\n  X prefix_sum(int L, int R, int x) {\n    X add\
    \ = MX::unit(), sub = MX::unit();\n    FOR_R(d, lg) {\n      int l0 = bv[d].rank(L,\
    \ 0), r0 = bv[d].rank(R, 0);\n      if (x >> d & 1) {\n        add = MX::op(add,\
    \ dat[d][r0]);\n        sub = MX::op(sub, dat[d][l0]);\n        L += mid[d] -\
    \ l0, R += mid[d] - r0;\n      } else {\n        L = l0, R = r0;\n      }\n  \
    \  }\n    return MX::op(add, MX::inverse(sub));\n  }\n};\n"
  code: "#include \"ds/bit_vector.hpp\"\n\ntemplate <typename Monoid, typename XY,\
    \ bool SMALL_X, bool SMALL_Y>\nstruct Wavelet_Matrix_2D_Range_Static_AbelGroup\
    \ {\n  // \u70B9\u7FA4\u3092 Y \u6607\u9806\u306B\u4E26\u3079\u308B.\n  // X \u3092\
    \u6574\u6570\u306B\u306A\u304A\u3057\u3066 binary trie \u307F\u305F\u3044\u306B\
    \u632F\u308A\u5206\u3051\u308B\n  using MX = Monoid;\n  using X = typename MX::value_type;\n\
    \  static_assert(MX::commute);\n\n  template <bool SMALL>\n  struct TO_IDX {\n\
    \    vc<XY> key;\n    XY mi, ma;\n    vc<int> dat;\n\n    void build(vc<XY>& X)\
    \ {\n      if constexpr (SMALL) {\n        mi = (X.empty() ? 0 : MIN(X));\n  \
    \      ma = (X.empty() ? 0 : MAX(X));\n        dat.assign(ma - mi + 2, 0);\n \
    \       for (auto& x: X) { dat[x - mi + 1]++; }\n        FOR(i, len(dat) - 1)\
    \ dat[i + 1] += dat[i];\n      } else {\n        key = X;\n        sort(all(key));\n\
    \      }\n    }\n    int operator()(XY x) {\n      if constexpr (SMALL) {\n  \
    \      return dat[clamp<XY>(x - mi, 0, ma - mi + 1)];\n      } else {\n      \
    \  return LB(key, x);\n      }\n    }\n  };\n\n  TO_IDX<SMALL_X> XtoI;\n  TO_IDX<SMALL_Y>\
    \ YtoI;\n\n  int N, lg;\n  vector<int> mid;\n  vector<Bit_Vector> bv;\n  vvc<X>\
    \ dat;\n\n  template <typename F>\n  Wavelet_Matrix_2D_Range_Static_AbelGroup(int\
    \ N, F f) {\n    build(N, f);\n  }\n\n  template <typename F>\n  void build(int\
    \ N, F f) {\n    if (N == 0) {\n      lg = 0;\n      return;\n    }\n    vc<XY>\
    \ A(N), Y(N);\n    vc<X> S(N);\n    FOR(i, N) tie(A[i], Y[i], S[i]) = f(i);\n\
    \    auto I = argsort(Y);\n    A = rearrange(A, I), Y = rearrange(Y, I), S = rearrange(S,\
    \ I);\n    XtoI.build(A), YtoI.build(Y);\n\n    // \u3042\u3068\u306F\u666E\u901A\
    \u306B\n    lg = __lg(XtoI(MAX(A) + 1)) + 1;\n    mid.resize(lg), bv.assign(lg,\
    \ Bit_Vector(N));\n    dat.assign(1 + lg, vc<X>(N + 1, MX::unit()));\n    FOR(i,\
    \ N) A[i] = XtoI(A[i]);\n\n    vc<int> A0(N), A1(N);\n    vc<X> S0(N), S1(N);\n\
    \    FOR_R(d, -1, lg) {\n      int p0 = 0, p1 = 0;\n      FOR(i, N) { dat[d +\
    \ 1][i + 1] = MX::op(dat[d + 1][i], S[i]); }\n      if (d == -1) break;\n    \
    \  FOR(i, N) {\n        bool f = (A[i] >> d & 1);\n        if (!f) { S0[p0] =\
    \ S[i], A0[p0] = A[i], p0++; }\n        if (f) { S1[p1] = S[i], A1[p1] = A[i],\
    \ bv[d].set(i), p1++; }\n      }\n      mid[d] = p0;\n      bv[d].build();\n \
    \     swap(A, A0), swap(S, S0);\n      FOR(i, p1) A[p0 + i] = A1[i], S[p0 + i]\
    \ = S1[i];\n    }\n  }\n\n  int count(XY x1, XY x2, XY y1, XY y2) {\n    x1 =\
    \ XtoI(x1), x2 = XtoI(x2);\n    y1 = YtoI(y1), y2 = YtoI(y2);\n    return prefix_count(y1,\
    \ y2, x2) - prefix_count(y1, y2, x1);\n  }\n\n  X prod(XY x1, XY x2, XY y1, XY\
    \ y2) { return sum(x1, x2, y1, y2); }\n  X sum(XY x1, XY x2, XY y1, XY y2) {\n\
    \    assert(x1 <= x2 && y1 <= y2);\n    x1 = XtoI(x1), x2 = XtoI(x2);\n    y1\
    \ = YtoI(y1), y2 = YtoI(y2);\n    X add = prefix_sum(y1, y2, x2);\n    X sub =\
    \ prefix_sum(y1, y2, x1);\n    return MX::op(add, MX::inverse(sub));\n  }\n\n\
    private:\n  int prefix_count(int L, int R, int x) {\n    int cnt = 0;\n    FOR_R(d,\
    \ lg) {\n      int l0 = bv[d].rank(L, 0), r0 = bv[d].rank(R, 0);\n      if (x\
    \ >> d & 1) {\n        cnt += r0 - l0, L += mid[d] - l0, R += mid[d] - r0;\n \
    \     } else {\n        L = l0, R = r0;\n      }\n    }\n    return cnt;\n  }\n\
    \n  X prefix_sum(int L, int R, int x) {\n    X add = MX::unit(), sub = MX::unit();\n\
    \    FOR_R(d, lg) {\n      int l0 = bv[d].rank(L, 0), r0 = bv[d].rank(R, 0);\n\
    \      if (x >> d & 1) {\n        add = MX::op(add, dat[d][r0]);\n        sub\
    \ = MX::op(sub, dat[d][l0]);\n        L += mid[d] - l0, R += mid[d] - r0;\n  \
    \    } else {\n        L = l0, R = r0;\n      }\n    }\n    return MX::op(add,\
    \ MX::inverse(sub));\n  }\n};"
  dependsOn:
  - ds/bit_vector.hpp
  isVerificationFile: false
  path: ds/wavelet_matrix/wavelet_matrix_2d_range_static_abelgroup.hpp
  requiredBy: []
  timestamp: '2024-02-04 22:24:14+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/library_checker/datastructure/rectangle_sum_wm.test.cpp
  - test/library_checker/datastructure/rectangle_sum_wm_abel.test.cpp
documentation_of: ds/wavelet_matrix/wavelet_matrix_2d_range_static_abelgroup.hpp
layout: document
redirect_from:
- /library/ds/wavelet_matrix/wavelet_matrix_2d_range_static_abelgroup.hpp
- /library/ds/wavelet_matrix/wavelet_matrix_2d_range_static_abelgroup.hpp.html
title: ds/wavelet_matrix/wavelet_matrix_2d_range_static_abelgroup.hpp
---
