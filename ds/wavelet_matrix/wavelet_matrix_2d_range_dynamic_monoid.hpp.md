---
data:
  _extendedDependsOn:
  - icon: ':x:'
    path: ds/bit_vector.hpp
    title: ds/bit_vector.hpp
  - icon: ':question:'
    path: ds/segtree/segtree.hpp
    title: ds/segtree/segtree.hpp
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':x:'
    path: test/yukicoder/1625_2.test.cpp
    title: test/yukicoder/1625_2.test.cpp
  _isVerificationFailed: true
  _pathExtension: hpp
  _verificationStatusIcon: ':x:'
  attributes:
    links: []
  bundledCode: "#line 2 \"ds/segtree/segtree.hpp\"\n\ntemplate <class Monoid>\nstruct\
    \ SegTree {\n  using MX = Monoid;\n  using X = typename MX::value_type;\n  using\
    \ value_type = X;\n  vc<X> dat;\n  int n, log, size;\n\n  SegTree() {}\n  SegTree(int\
    \ n) { build(n); }\n  template <typename F>\n  SegTree(int n, F f) {\n    build(n,\
    \ f);\n  }\n  SegTree(const vc<X>& v) { build(v); }\n\n  void build(int m) {\n\
    \    build(m, [](int i) -> X { return MX::unit(); });\n  }\n  void build(const\
    \ vc<X>& v) {\n    build(len(v), [&](int i) -> X { return v[i]; });\n  }\n  template\
    \ <typename F>\n  void build(int m, F f) {\n    n = m, log = 1;\n    while ((1\
    \ << log) < n) ++log;\n    size = 1 << log;\n    dat.assign(size << 1, MX::unit());\n\
    \    FOR(i, n) dat[size + i] = f(i);\n    FOR_R(i, 1, size) update(i);\n  }\n\n\
    \  X get(int i) { return dat[size + i]; }\n  vc<X> get_all() { return {dat.begin()\
    \ + size, dat.begin() + size + n}; }\n\n  void update(int i) { dat[i] = Monoid::op(dat[2\
    \ * i], dat[2 * i + 1]); }\n  void set(int i, const X& x) {\n    assert(i < n);\n\
    \    dat[i += size] = x;\n    while (i >>= 1) update(i);\n  }\n\n  void multiply(int\
    \ i, const X& x) {\n    assert(i < n);\n    i += size;\n    dat[i] = Monoid::op(dat[i],\
    \ x);\n    while (i >>= 1) update(i);\n  }\n\n  X prod(int L, int R) {\n    assert(0\
    \ <= L && L <= R && R <= n);\n    X vl = Monoid::unit(), vr = Monoid::unit();\n\
    \    L += size, R += size;\n    while (L < R) {\n      if (L & 1) vl = Monoid::op(vl,\
    \ dat[L++]);\n      if (R & 1) vr = Monoid::op(dat[--R], vr);\n      L >>= 1,\
    \ R >>= 1;\n    }\n    return Monoid::op(vl, vr);\n  }\n\n  X prod_all() { return\
    \ dat[1]; }\n\n  template <class F>\n  int max_right(F check, int L) {\n    assert(0\
    \ <= L && L <= n && check(Monoid::unit()));\n    if (L == n) return n;\n    L\
    \ += size;\n    X sm = Monoid::unit();\n    do {\n      while (L % 2 == 0) L >>=\
    \ 1;\n      if (!check(Monoid::op(sm, dat[L]))) {\n        while (L < size) {\n\
    \          L = 2 * L;\n          if (check(Monoid::op(sm, dat[L]))) { sm = Monoid::op(sm,\
    \ dat[L++]); }\n        }\n        return L - size;\n      }\n      sm = Monoid::op(sm,\
    \ dat[L++]);\n    } while ((L & -L) != L);\n    return n;\n  }\n\n  template <class\
    \ F>\n  int min_left(F check, int R) {\n    assert(0 <= R && R <= n && check(Monoid::unit()));\n\
    \    if (R == 0) return 0;\n    R += size;\n    X sm = Monoid::unit();\n    do\
    \ {\n      --R;\n      while (R > 1 && (R % 2)) R >>= 1;\n      if (!check(Monoid::op(dat[R],\
    \ sm))) {\n        while (R < size) {\n          R = 2 * R + 1;\n          if\
    \ (check(Monoid::op(dat[R], sm))) { sm = Monoid::op(dat[R--], sm); }\n       \
    \ }\n        return R + 1 - size;\n      }\n      sm = Monoid::op(dat[R], sm);\n\
    \    } while ((R & -R) != R);\n    return 0;\n  }\n\n  // prod_{l<=i<r} A[i xor\
    \ x]\n  X xor_prod(int l, int r, int xor_val) {\n    static_assert(Monoid::commute);\n\
    \    X x = Monoid::unit();\n    for (int k = 0; k < log + 1; ++k) {\n      if\
    \ (l >= r) break;\n      if (l & 1) { x = Monoid::op(x, dat[(size >> k) + ((l++)\
    \ ^ xor_val)]); }\n      if (r & 1) { x = Monoid::op(x, dat[(size >> k) + ((--r)\
    \ ^ xor_val)]); }\n      l /= 2, r /= 2, xor_val /= 2;\n    }\n    return x;\n\
    \  }\n};\n#line 1 \"ds/bit_vector.hpp\"\nstruct Bit_Vector {\n  vc<pair<u32, u32>>\
    \ dat;\n  Bit_Vector(int n) { dat.assign((n + 63) >> 5, {0, 0}); }\n  void set(int\
    \ i) { dat[i >> 5].fi |= u32(1) << (i & 31); }\n  void reset() { fill(all(dat),\
    \ pair<u32, u32>{0, 0}); }\n  void build() {\n    FOR(i, len(dat) - 1) dat[i +\
    \ 1].se = dat[i].se + popcnt(dat[i].fi);\n  }\n  // [0, k) \u5185\u306E 1 \u306E\
    \u500B\u6570\n  int count(int k, bool f = 1) {\n    auto [a, b] = dat[k >> 5];\n\
    \    int ret = b + popcnt(a & ((u32(1) << (k & 31)) - 1));\n    return (f ? ret\
    \ : k - ret);\n  }\n  int count(int L, int R, bool f = 1) { return count(R, f)\
    \ - count(L, f); }\n};\n#line 3 \"ds/wavelet_matrix/wavelet_matrix_2d_range_dynamic_monoid.hpp\"\
    \n\ntemplate <typename Monoid, typename XY, bool SMALL_X, bool SMALL_Y>\nstruct\
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
    \    vc<XY> A0(N), A1(N);\n    vc<X> S0(N), S1(N);\n    FOR_R(d, lg) {\n     \
    \ int p0 = 0, p1 = 0;\n      FOR(i, N) {\n        bool f = (A[i] >> d & 1);\n\
    \        if (!f) { S0[p0] = S[i], A0[p0] = A[i], p0++; }\n        if (f) { S1[p1]\
    \ = S[i], A1[p1] = A[i], bv[d].set(i), p1++; }\n      }\n      mid[d] = p0;\n\
    \      bv[d].build();\n      swap(A, A0), swap(S, S0);\n      FOR(i, p1) A[p0\
    \ + i] = A1[i], S[p0 + i] = S1[i];\n      dat[d].build(N, [&](int i) -> X { return\
    \ S[i]; });\n    }\n    FOR(i, N) A[i] = XtoI(tmp[i]);\n  }\n\n  int count(XY\
    \ x1, XY x2, XY y1, XY y2) {\n    if (N == 0) return 0;\n    x1 = XtoI(x1), x2\
    \ = XtoI(x2);\n    y1 = YtoI(y1), y2 = YtoI(y2);\n    return prefix_count(y1,\
    \ y2, x2) - prefix_count(y1, y2, x1);\n  }\n\n  X prod(XY x1, XY x2, XY y1, XY\
    \ y2) {\n    if (N == 0) return MX::unit();\n    assert(x1 <= x2 && y1 <= y2);\n\
    \    x1 = XtoI(x1), x2 = XtoI(x2);\n    y1 = YtoI(y1), y2 = YtoI(y2);\n    X res\
    \ = MX::unit();\n    prod_dfs(y1, y2, x1, x2, lg - 1, res);\n    return res;\n\
    \  }\n\n  // \u6700\u521D\u306B\u4E0E\u3048\u305F\u70B9\u7FA4\u306E index\n  void\
    \ set(int i, X x) {\n    assert(0 <= i && i < N);\n    i = new_idx[i];\n    int\
    \ a = A[i];\n    FOR_R(d, lg) {\n      if (a >> d & 1) {\n        i = mid[d] +\
    \ bv[d].rank(i, 1);\n      } else {\n        i = bv[d].rank(i, 0);\n      }\n\
    \      dat[d].set(i, x);\n    }\n  }\n  void multiply(int i, X x) {\n    assert(0\
    \ <= i && i < N);\n    i = new_idx[i];\n    int a = A[i];\n    FOR_R(d, lg) {\n\
    \      if (a >> d & 1) {\n        i = mid[d] + bv[d].rank(i, 1);\n      } else\
    \ {\n        i = bv[d].rank(i, 0);\n      }\n      dat[d].multiply(i, x);\n  \
    \  }\n  }\n\nprivate:\n  int prefix_count(int L, int R, int x) {\n    int cnt\
    \ = 0;\n    FOR_R(d, lg) {\n      int l0 = bv[d].rank(L, 0), r0 = bv[d].rank(R,\
    \ 0);\n      if (x >> d & 1) {\n        cnt += r0 - l0, L += mid[d] - l0, R +=\
    \ mid[d] - r0;\n      } else {\n        L = l0, R = r0;\n      }\n    }\n    return\
    \ cnt;\n  }\n\n  void prod_dfs(int L, int R, int x1, int x2, int d, X& res) {\n\
    \    chmax(x1, 0), chmin(x2, 1 << (d + 1));\n    if (x1 >= x2) { return; }\n \
    \   assert(0 <= x1 && x1 < x2 && x2 <= (1 << (d + 1)));\n    if (x1 == 0 && x2\
    \ == (1 << (d + 1))) {\n      res = MX::op(res, dat[d + 1].prod(L, R));\n    \
    \  return;\n    }\n    int l0 = bv[d].rank(L, 0), r0 = bv[d].rank(R, 0);\n   \
    \ prod_dfs(l0, r0, x1, x2, d - 1, res);\n    prod_dfs(L + mid[d] - l0, R + mid[d]\
    \ - r0, x1 - (1 << d), x2 - (1 << d),\n             d - 1, res);\n  }\n};\n"
  code: "#include \"ds/segtree/segtree.hpp\"\n#include \"ds/bit_vector.hpp\"\n\ntemplate\
    \ <typename Monoid, typename XY, bool SMALL_X, bool SMALL_Y>\nstruct Wavelet_Matrix_2D_Range_Dynamic_Monoid\
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
    \ YtoI;\n\n  int N, lg;\n  vector<int> mid;\n  vector<Bit_Vector> bv;\n  vc<int>\
    \ new_idx;\n  vc<int> A;\n  // \u5404\u6BB5\u306B fenwick tree\n  vc<SegTree<Monoid>>\
    \ dat;\n\n  template <typename F>\n  Wavelet_Matrix_2D_Range_Dynamic_Monoid(int\
    \ N, F f) {\n    build(N, f);\n  }\n\n  template <typename F>\n  void build(int\
    \ N_, F f) {\n    N = N_;\n    if (N == 0) {\n      lg = 0;\n      return;\n \
    \   }\n    vc<XY> tmp(N), Y(N);\n    vc<X> S(N);\n    FOR(i, N) tie(tmp[i], Y[i],\
    \ S[i]) = f(i);\n    auto I = argsort(Y);\n    tmp = rearrange(tmp, I), Y = rearrange(Y,\
    \ I), S = rearrange(S, I);\n    XtoI.build(tmp), YtoI.build(Y);\n    new_idx.resize(N);\n\
    \    FOR(i, N) new_idx[I[i]] = i;\n\n    // \u3042\u3068\u306F\u666E\u901A\u306B\
    \n    lg = __lg(XtoI(MAX(tmp) + 1)) + 1;\n    mid.resize(lg), bv.assign(lg, Bit_Vector(N));\n\
    \    dat.resize(lg);\n    A.resize(N);\n    FOR(i, N) A[i] = XtoI(tmp[i]);\n\n\
    \    vc<XY> A0(N), A1(N);\n    vc<X> S0(N), S1(N);\n    FOR_R(d, lg) {\n     \
    \ int p0 = 0, p1 = 0;\n      FOR(i, N) {\n        bool f = (A[i] >> d & 1);\n\
    \        if (!f) { S0[p0] = S[i], A0[p0] = A[i], p0++; }\n        if (f) { S1[p1]\
    \ = S[i], A1[p1] = A[i], bv[d].set(i), p1++; }\n      }\n      mid[d] = p0;\n\
    \      bv[d].build();\n      swap(A, A0), swap(S, S0);\n      FOR(i, p1) A[p0\
    \ + i] = A1[i], S[p0 + i] = S1[i];\n      dat[d].build(N, [&](int i) -> X { return\
    \ S[i]; });\n    }\n    FOR(i, N) A[i] = XtoI(tmp[i]);\n  }\n\n  int count(XY\
    \ x1, XY x2, XY y1, XY y2) {\n    if (N == 0) return 0;\n    x1 = XtoI(x1), x2\
    \ = XtoI(x2);\n    y1 = YtoI(y1), y2 = YtoI(y2);\n    return prefix_count(y1,\
    \ y2, x2) - prefix_count(y1, y2, x1);\n  }\n\n  X prod(XY x1, XY x2, XY y1, XY\
    \ y2) {\n    if (N == 0) return MX::unit();\n    assert(x1 <= x2 && y1 <= y2);\n\
    \    x1 = XtoI(x1), x2 = XtoI(x2);\n    y1 = YtoI(y1), y2 = YtoI(y2);\n    X res\
    \ = MX::unit();\n    prod_dfs(y1, y2, x1, x2, lg - 1, res);\n    return res;\n\
    \  }\n\n  // \u6700\u521D\u306B\u4E0E\u3048\u305F\u70B9\u7FA4\u306E index\n  void\
    \ set(int i, X x) {\n    assert(0 <= i && i < N);\n    i = new_idx[i];\n    int\
    \ a = A[i];\n    FOR_R(d, lg) {\n      if (a >> d & 1) {\n        i = mid[d] +\
    \ bv[d].rank(i, 1);\n      } else {\n        i = bv[d].rank(i, 0);\n      }\n\
    \      dat[d].set(i, x);\n    }\n  }\n  void multiply(int i, X x) {\n    assert(0\
    \ <= i && i < N);\n    i = new_idx[i];\n    int a = A[i];\n    FOR_R(d, lg) {\n\
    \      if (a >> d & 1) {\n        i = mid[d] + bv[d].rank(i, 1);\n      } else\
    \ {\n        i = bv[d].rank(i, 0);\n      }\n      dat[d].multiply(i, x);\n  \
    \  }\n  }\n\nprivate:\n  int prefix_count(int L, int R, int x) {\n    int cnt\
    \ = 0;\n    FOR_R(d, lg) {\n      int l0 = bv[d].rank(L, 0), r0 = bv[d].rank(R,\
    \ 0);\n      if (x >> d & 1) {\n        cnt += r0 - l0, L += mid[d] - l0, R +=\
    \ mid[d] - r0;\n      } else {\n        L = l0, R = r0;\n      }\n    }\n    return\
    \ cnt;\n  }\n\n  void prod_dfs(int L, int R, int x1, int x2, int d, X& res) {\n\
    \    chmax(x1, 0), chmin(x2, 1 << (d + 1));\n    if (x1 >= x2) { return; }\n \
    \   assert(0 <= x1 && x1 < x2 && x2 <= (1 << (d + 1)));\n    if (x1 == 0 && x2\
    \ == (1 << (d + 1))) {\n      res = MX::op(res, dat[d + 1].prod(L, R));\n    \
    \  return;\n    }\n    int l0 = bv[d].rank(L, 0), r0 = bv[d].rank(R, 0);\n   \
    \ prod_dfs(l0, r0, x1, x2, d - 1, res);\n    prod_dfs(L + mid[d] - l0, R + mid[d]\
    \ - r0, x1 - (1 << d), x2 - (1 << d),\n             d - 1, res);\n  }\n};\n"
  dependsOn:
  - ds/segtree/segtree.hpp
  - ds/bit_vector.hpp
  isVerificationFile: false
  path: ds/wavelet_matrix/wavelet_matrix_2d_range_dynamic_monoid.hpp
  requiredBy: []
  timestamp: '2024-07-18 10:54:15+09:00'
  verificationStatus: LIBRARY_ALL_WA
  verifiedWith:
  - test/yukicoder/1625_2.test.cpp
documentation_of: ds/wavelet_matrix/wavelet_matrix_2d_range_dynamic_monoid.hpp
layout: document
redirect_from:
- /library/ds/wavelet_matrix/wavelet_matrix_2d_range_dynamic_monoid.hpp
- /library/ds/wavelet_matrix/wavelet_matrix_2d_range_dynamic_monoid.hpp.html
title: ds/wavelet_matrix/wavelet_matrix_2d_range_dynamic_monoid.hpp
---
