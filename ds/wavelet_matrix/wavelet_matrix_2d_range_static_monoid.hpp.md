---
data:
  _extendedDependsOn:
  - icon: ':question:'
    path: alg/monoid/add.hpp
    title: alg/monoid/add.hpp
  - icon: ':x:'
    path: ds/bit_vector.hpp
    title: ds/bit_vector.hpp
  - icon: ':question:'
    path: ds/segtree/segtree.hpp
    title: ds/segtree/segtree.hpp
  - icon: ':x:'
    path: ds/sparse_table/disjoint_sparse_table.hpp
    title: ds/sparse_table/disjoint_sparse_table.hpp
  - icon: ':question:'
    path: ds/sparse_table/sparse_table.hpp
    title: ds/sparse_table/sparse_table.hpp
  - icon: ':x:'
    path: ds/static_range_product.hpp
    title: ds/static_range_product.hpp
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':x:'
    path: test/yukicoder/1600_2.test.cpp
    title: test/yukicoder/1600_2.test.cpp
  _isVerificationFailed: true
  _pathExtension: hpp
  _verificationStatusIcon: ':x:'
  attributes:
    links: []
  bundledCode: "#line 1 \"ds/bit_vector.hpp\"\nstruct Bit_Vector {\n  vc<pair<u32,\
    \ u32>> dat;\n  Bit_Vector(int n) { dat.assign((n + 63) >> 5, {0, 0}); }\n\n \
    \ void set(int i) { dat[i >> 5].fi |= u32(1) << (i & 31); }\n\n  void build()\
    \ {\n    FOR(i, len(dat) - 1) dat[i + 1].se = dat[i].se + popcnt(dat[i].fi);\n\
    \  }\n\n  // [0, k) \u5185\u306E 1 \u306E\u500B\u6570\n  int rank(int k, bool\
    \ f = 1) {\n    auto [a, b] = dat[k >> 5];\n    int ret = b + popcnt(a & ((u32(1)\
    \ << (k & 31)) - 1));\n    return (f ? ret : k - ret);\n  }\n};\n#line 2 \"ds/segtree/segtree.hpp\"\
    \n\ntemplate <class Monoid>\nstruct SegTree {\n  using MX = Monoid;\n  using X\
    \ = typename MX::value_type;\n  using value_type = X;\n  vc<X> dat;\n  int n,\
    \ log, size;\n\n  SegTree() {}\n  SegTree(int n) { build(n); }\n  template <typename\
    \ F>\n  SegTree(int n, F f) {\n    build(n, f);\n  }\n  SegTree(const vc<X>& v)\
    \ { build(v); }\n\n  void build(int m) {\n    build(m, [](int i) -> X { return\
    \ MX::unit(); });\n  }\n  void build(const vc<X>& v) {\n    build(len(v), [&](int\
    \ i) -> X { return v[i]; });\n  }\n  template <typename F>\n  void build(int m,\
    \ F f) {\n    n = m, log = 1;\n    while ((1 << log) < n) ++log;\n    size = 1\
    \ << log;\n    dat.assign(size << 1, MX::unit());\n    FOR(i, n) dat[size + i]\
    \ = f(i);\n    FOR_R(i, 1, size) update(i);\n  }\n\n  X get(int i) { return dat[size\
    \ + i]; }\n  vc<X> get_all() { return {dat.begin() + size, dat.begin() + size\
    \ + n}; }\n\n  void update(int i) { dat[i] = Monoid::op(dat[2 * i], dat[2 * i\
    \ + 1]); }\n  void set(int i, const X& x) {\n    assert(i < n);\n    dat[i +=\
    \ size] = x;\n    while (i >>= 1) update(i);\n  }\n\n  void multiply(int i, const\
    \ X& x) {\n    assert(i < n);\n    i += size;\n    dat[i] = Monoid::op(dat[i],\
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
    \  }\n};\n#line 2 \"alg/monoid/add.hpp\"\n\r\ntemplate <typename E>\r\nstruct\
    \ Monoid_Add {\r\n  using X = E;\r\n  using value_type = X;\r\n  static constexpr\
    \ X op(const X &x, const X &y) noexcept { return x + y; }\r\n  static constexpr\
    \ X inverse(const X &x) noexcept { return -x; }\r\n  static constexpr X power(const\
    \ X &x, ll n) noexcept { return X(n) * x; }\r\n  static constexpr X unit() { return\
    \ X(0); }\r\n  static constexpr bool commute = true;\r\n};\r\n#line 2 \"ds/sparse_table/sparse_table.hpp\"\
    \n\n// \u51AA\u7B49\u306A\u30E2\u30CE\u30A4\u30C9\u3067\u3042\u308B\u3053\u3068\
    \u3092\u4EEE\u5B9A\u3002disjoint sparse table \u3088\u308A x \u500D\u9AD8\u901F\
    \ntemplate <class Monoid>\nstruct Sparse_Table {\n  using MX = Monoid;\n  using\
    \ X = typename MX::value_type;\n  int n, log;\n  vvc<X> dat;\n\n  Sparse_Table()\
    \ {}\n  Sparse_Table(int n) { build(n); }\n  template <typename F>\n  Sparse_Table(int\
    \ n, F f) {\n    build(n, f);\n  }\n  Sparse_Table(const vc<X>& v) { build(v);\
    \ }\n\n  void build(int m) {\n    build(m, [](int i) -> X { return MX::unit();\
    \ });\n  }\n  void build(const vc<X>& v) {\n    build(len(v), [&](int i) -> X\
    \ { return v[i]; });\n  }\n  template <typename F>\n  void build(int m, F f) {\n\
    \    n = m, log = 1;\n    while ((1 << log) < n) ++log;\n    dat.resize(log);\n\
    \    dat[0].resize(n);\n    FOR(i, n) dat[0][i] = f(i);\n\n    FOR(i, log - 1)\
    \ {\n      dat[i + 1].resize(len(dat[i]) - (1 << i));\n      FOR(j, len(dat[i])\
    \ - (1 << i)) {\n        dat[i + 1][j] = MX::op(dat[i][j], dat[i][j + (1 << i)]);\n\
    \      }\n    }\n  }\n\n  X prod(int L, int R) {\n    if (L == R) return MX::unit();\n\
    \    if (R == L + 1) return dat[0][L];\n    int k = topbit(R - L - 1);\n    return\
    \ MX::op(dat[k][L], dat[k][R - (1 << k)]);\n  }\n\n  template <class F>\n  int\
    \ max_right(const F check, int L) {\n    assert(0 <= L && L <= n && check(MX::unit()));\n\
    \    if (L == n) return n;\n    int ok = L, ng = n + 1;\n    while (ok + 1 < ng)\
    \ {\n      int k = (ok + ng) / 2;\n      bool bl = check(prod(L, k));\n      if\
    \ (bl) ok = k;\n      if (!bl) ng = k;\n    }\n    return ok;\n  }\n\n  template\
    \ <class F>\n  int min_left(const F check, int R) {\n    assert(0 <= R && R <=\
    \ n && check(MX::unit()));\n    if (R == 0) return 0;\n    int ok = R, ng = -1;\n\
    \    while (ng + 1 < ok) {\n      int k = (ok + ng) / 2;\n      bool bl = check(prod(k,\
    \ R));\n      if (bl) ok = k;\n      if (!bl) ng = k;\n    }\n    return ok;\n\
    \  }\n};\n#line 2 \"ds/sparse_table/disjoint_sparse_table.hpp\"\n\r\ntemplate\
    \ <class Monoid>\r\nstruct Disjoint_Sparse_Table {\r\n  using MX = Monoid;\r\n\
    \  using X = typename MX::value_type;\r\n  int n, log;\r\n  vvc<X> dat;\r\n\r\n\
    \  Disjoint_Sparse_Table() {}\r\n  Disjoint_Sparse_Table(int n) { build(n); }\r\
    \n  template <typename F>\r\n  Disjoint_Sparse_Table(int n, F f) {\r\n    build(n,\
    \ f);\r\n  }\r\n  Disjoint_Sparse_Table(const vc<X>& v) { build(v); }\r\n\r\n\
    \  void build(int m) {\r\n    build(m, [](int i) -> X { return MX::unit(); });\r\
    \n  }\r\n  void build(const vc<X>& v) {\r\n    build(len(v), [&](int i) -> X {\
    \ return v[i]; });\r\n  }\r\n  template <typename F>\r\n  void build(int m, F\
    \ f) {\r\n    n = m, log = 1;\r\n    while ((1 << log) < n) ++log;\r\n    dat.resize(log);\r\
    \n    dat[0].reserve(n);\r\n    FOR(i, n) dat[0].eb(f(i));\r\n    FOR(i, 1, log)\
    \ {\r\n      auto& v = dat[i];\r\n      v = dat[0];\r\n      int b = 1 << i;\r\
    \n      for (int m = b; m <= n; m += 2 * b) {\r\n        int L = m - b, R = min(n,\
    \ m + b);\r\n        FOR_R(j, L + 1, m) v[j - 1] = MX::op(v[j - 1], v[j]);\r\n\
    \        FOR(j, m, R - 1) v[j + 1] = MX::op(v[j], v[j + 1]);\r\n      }\r\n  \
    \  }\r\n  }\r\n\r\n  X prod(int L, int R) {\r\n    if (L == R) return MX::unit();\r\
    \n    --R;\r\n    if (L == R) return dat[0][L];\r\n    int k = topbit(L ^ R);\r\
    \n    return MX::op(dat[k][L], dat[k][R]);\r\n  }\r\n\r\n  template <class F>\r\
    \n  int max_right(const F check, int L) {\r\n    assert(0 <= L && L <= n && check(MX::unit()));\r\
    \n    if (L == n) return n;\r\n    int ok = L, ng = n + 1;\r\n    while (ok +\
    \ 1 < ng) {\r\n      int k = (ok + ng) / 2;\r\n      bool bl = check(prod(L, k));\r\
    \n      if (bl) ok = k;\r\n      if (!bl) ng = k;\r\n    }\r\n    return ok;\r\
    \n  }\r\n\r\n  template <class F>\r\n  int min_left(const F check, int R) {\r\n\
    \    assert(0 <= R && R <= n && check(MX::unit()));\r\n    if (R == 0) return\
    \ 0;\r\n    int ok = R, ng = -1;\r\n    while (ng + 1 < ok) {\r\n      int k =\
    \ (ok + ng) / 2;\r\n      bool bl = check(prod(k, R));\r\n      if (bl) ok = k;\r\
    \n      if (!bl) ng = k;\r\n    }\r\n    return ok;\r\n  }\r\n};\n#line 3 \"ds/static_range_product.hpp\"\
    \n\n/*\n\u53C2\u8003\uFF1Ahttps://judge.yosupo.jp/submission/106668\n\u9577\u3055\
    \ 2^LOG \u306E\u30D6\u30ED\u30C3\u30AF\u306B\u5206\u3051\u308B\uFF0E\u30D6\u30ED\
    \u30C3\u30AF\u5185\u306E prefix, suffix \u3092\u6301\u3064\uFF0E\n\u30D6\u30ED\
    \u30C3\u30AF\u7A4D\u306E\u5217\u3092 ST(DST) \u3067\u6301\u3064\uFF0E\u30D6\u30ED\
    \u30C3\u30AF\u3092\u307E\u305F\u3050\u7A4D\u306F O(1).\n\u77ED\u3044\u3082\u306E\
    \u306F O(1) \u3092\u8AE6\u3081\u3066\u611A\u76F4\u3068\u3044\u3046\u3053\u3068\
    \u306B\u3059\u308B\uFF0E\n\u524D\u8A08\u7B97\uFF1AO(Nlog(N)/2^LOG)\n\u30AF\u30A8\
    \u30EA\uFF1AO(1) / worst O(2^LOG)\n*/\ntemplate <typename Monoid, typename SPARSE_TABLE,\
    \ int LOG = 4>\nstruct Static_Range_Product {\n  using MX = Monoid;\n  using X\
    \ = typename MX::value_type;\n  int N, b_num;\n  vc<X> A, pre, suf; // inclusive\n\
    \  SPARSE_TABLE ST;\n\n  Static_Range_Product() {}\n  template <typename F>\n\
    \  Static_Range_Product(int n, F f) {\n    build(n, f);\n  }\n  Static_Range_Product(const\
    \ vc<X>& v) { build(v); }\n\n  void build(const vc<X>& v) {\n    build(len(v),\
    \ [&](int i) -> X { return v[i]; });\n  }\n  template <typename F>\n  void build(int\
    \ m, F f) {\n    N = m;\n    b_num = N >> LOG;\n    A.resize(N);\n    FOR(i, N)\
    \ A[i] = f(i);\n    pre = A, suf = A;\n    constexpr int mask = (1 << LOG) - 1;\n\
    \    FOR(i, 1, N) {\n      if (i & mask) pre[i] = MX::op(pre[i - 1], A[i]);\n\
    \    }\n    FOR_R(i, 1, N) {\n      if (i & mask) suf[i - 1] = MX::op(A[i - 1],\
    \ suf[i]);\n    }\n    ST.build(b_num, [&](int i) -> X { return suf[i << LOG];\
    \ });\n  }\n\n  // O(1) or O(R-L)\n  X prod(int L, int R) {\n    if (L == R) return\
    \ MX::unit();\n    R -= 1;\n    int a = L >> LOG, b = R >> LOG;\n    if (a < b)\
    \ {\n      X x = ST.prod(a + 1, b);\n      x = MX::op(suf[L], x);\n      x = MX::op(x,\
    \ pre[R]);\n      return x;\n    }\n    X x = A[L];\n    FOR(i, L + 1, R + 1)\
    \ x = MX::op(x, A[i]);\n    return x;\n  }\n};\n#line 5 \"ds/wavelet_matrix/wavelet_matrix_2d_range_static_monoid.hpp\"\
    \n\ntemplate <typename Monoid, typename ST, typename XY, bool SMALL_X, bool SMALL_Y>\n\
    struct Wavelet_Matrix_2D_Range_Static_Monoid {\n  // \u70B9\u7FA4\u3092 Y \u6607\
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
    \ mid;\n  vector<Bit_Vector> bv;\n  vc<int> new_idx;\n  vc<int> A;\n  using SEG\
    \ = Static_Range_Product<Monoid, ST, 4>;\n  vc<SEG> dat;\n\n  template <typename\
    \ F>\n  Wavelet_Matrix_2D_Range_Static_Monoid(int N, F f) {\n    build(N, f);\n\
    \  }\n\n  template <typename F>\n  void build(int N_, F f) {\n    N = N_;\n  \
    \  if (N == 0) {\n      lg = 0;\n      return;\n    }\n    vc<XY> tmp(N), Y(N);\n\
    \    vc<X> S(N);\n    FOR(i, N) tie(tmp[i], Y[i], S[i]) = f(i);\n    auto I =\
    \ argsort(Y);\n    tmp = rearrange(tmp, I), Y = rearrange(Y, I), S = rearrange(S,\
    \ I);\n    XtoI.build(tmp), YtoI.build(Y);\n    new_idx.resize(N);\n    FOR(i,\
    \ N) new_idx[I[i]] = i;\n\n    // \u3042\u3068\u306F\u666E\u901A\u306B\n    lg\
    \ = tmp.empty() ? 0 : __lg(XtoI(MAX(tmp) + 1)) + 1;\n    mid.resize(lg), bv.assign(lg,\
    \ Bit_Vector(N));\n    dat.resize(lg);\n    A.resize(N);\n    FOR(i, N) A[i] =\
    \ XtoI(tmp[i]);\n\n    vc<XY> A0(N), A1(N);\n    vc<X> S0(N), S1(N);\n    FOR_R(d,\
    \ lg) {\n      int p0 = 0, p1 = 0;\n      FOR(i, N) {\n        bool f = (A[i]\
    \ >> d & 1);\n        if (!f) { S0[p0] = S[i], A0[p0] = A[i], p0++; }\n      \
    \  if (f) { S1[p1] = S[i], A1[p1] = A[i], bv[d].set(i), p1++; }\n      }\n   \
    \   mid[d] = p0;\n      bv[d].build();\n      swap(A, A0), swap(S, S0);\n    \
    \  FOR(i, p1) A[p0 + i] = A1[i], S[p0 + i] = S1[i];\n      dat[d].build(N, [&](int\
    \ i) -> X { return S[i]; });\n    }\n    FOR(i, N) A[i] = XtoI(tmp[i]);\n  }\n\
    \n  int count(XY x1, XY x2, XY y1, XY y2) {\n    if (N == 0) return 0;\n    x1\
    \ = XtoI(x1), x2 = XtoI(x2);\n    y1 = YtoI(y1), y2 = YtoI(y2);\n    return prefix_count(y1,\
    \ y2, x2) - prefix_count(y1, y2, x1);\n  }\n\n  X prod(XY x1, XY x2, XY y1, XY\
    \ y2) {\n    if (N == 0) return MX::unit();\n    assert(x1 <= x2 && y1 <= y2);\n\
    \    x1 = XtoI(x1), x2 = XtoI(x2);\n    y1 = YtoI(y1), y2 = YtoI(y2);\n    X res\
    \ = MX::unit();\n    prod_dfs(y1, y2, x1, x2, lg - 1, res);\n    return res;\n\
    \  }\n\nprivate:\n  int prefix_count(int L, int R, int x) {\n    int cnt = 0;\n\
    \    FOR_R(d, lg) {\n      int l0 = bv[d].rank(L, 0), r0 = bv[d].rank(R, 0);\n\
    \      if (x >> d & 1) {\n        cnt += r0 - l0, L += mid[d] - l0, R += mid[d]\
    \ - r0;\n      } else {\n        L = l0, R = r0;\n      }\n    }\n    return cnt;\n\
    \  }\n\n  void prod_dfs(int L, int R, int x1, int x2, int d, X& res) {\n    chmax(x1,\
    \ 0), chmin(x2, 1 << (d + 1));\n    if (x1 >= x2) { return; }\n    assert(0 <=\
    \ x1 && x1 < x2 && x2 <= (1 << (d + 1)));\n    if (x1 == 0 && x2 == (1 << (d +\
    \ 1))) {\n      res = MX::op(res, dat[d + 1].prod(L, R));\n      return;\n   \
    \ }\n    int l0 = bv[d].rank(L, 0), r0 = bv[d].rank(R, 0);\n    prod_dfs(l0, r0,\
    \ x1, x2, d - 1, res);\n    prod_dfs(L + mid[d] - l0, R + mid[d] - r0, x1 - (1\
    \ << d), x2 - (1 << d),\n             d - 1, res);\n  }\n};\n"
  code: "#include \"ds/bit_vector.hpp\"\n#include \"ds/segtree/segtree.hpp\"\n#include\
    \ \"alg/monoid/add.hpp\"\n#include \"ds/static_range_product.hpp\"\n\ntemplate\
    \ <typename Monoid, typename ST, typename XY, bool SMALL_X, bool SMALL_Y>\nstruct\
    \ Wavelet_Matrix_2D_Range_Static_Monoid {\n  // \u70B9\u7FA4\u3092 Y \u6607\u9806\
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
    \ mid;\n  vector<Bit_Vector> bv;\n  vc<int> new_idx;\n  vc<int> A;\n  using SEG\
    \ = Static_Range_Product<Monoid, ST, 4>;\n  vc<SEG> dat;\n\n  template <typename\
    \ F>\n  Wavelet_Matrix_2D_Range_Static_Monoid(int N, F f) {\n    build(N, f);\n\
    \  }\n\n  template <typename F>\n  void build(int N_, F f) {\n    N = N_;\n  \
    \  if (N == 0) {\n      lg = 0;\n      return;\n    }\n    vc<XY> tmp(N), Y(N);\n\
    \    vc<X> S(N);\n    FOR(i, N) tie(tmp[i], Y[i], S[i]) = f(i);\n    auto I =\
    \ argsort(Y);\n    tmp = rearrange(tmp, I), Y = rearrange(Y, I), S = rearrange(S,\
    \ I);\n    XtoI.build(tmp), YtoI.build(Y);\n    new_idx.resize(N);\n    FOR(i,\
    \ N) new_idx[I[i]] = i;\n\n    // \u3042\u3068\u306F\u666E\u901A\u306B\n    lg\
    \ = tmp.empty() ? 0 : __lg(XtoI(MAX(tmp) + 1)) + 1;\n    mid.resize(lg), bv.assign(lg,\
    \ Bit_Vector(N));\n    dat.resize(lg);\n    A.resize(N);\n    FOR(i, N) A[i] =\
    \ XtoI(tmp[i]);\n\n    vc<XY> A0(N), A1(N);\n    vc<X> S0(N), S1(N);\n    FOR_R(d,\
    \ lg) {\n      int p0 = 0, p1 = 0;\n      FOR(i, N) {\n        bool f = (A[i]\
    \ >> d & 1);\n        if (!f) { S0[p0] = S[i], A0[p0] = A[i], p0++; }\n      \
    \  if (f) { S1[p1] = S[i], A1[p1] = A[i], bv[d].set(i), p1++; }\n      }\n   \
    \   mid[d] = p0;\n      bv[d].build();\n      swap(A, A0), swap(S, S0);\n    \
    \  FOR(i, p1) A[p0 + i] = A1[i], S[p0 + i] = S1[i];\n      dat[d].build(N, [&](int\
    \ i) -> X { return S[i]; });\n    }\n    FOR(i, N) A[i] = XtoI(tmp[i]);\n  }\n\
    \n  int count(XY x1, XY x2, XY y1, XY y2) {\n    if (N == 0) return 0;\n    x1\
    \ = XtoI(x1), x2 = XtoI(x2);\n    y1 = YtoI(y1), y2 = YtoI(y2);\n    return prefix_count(y1,\
    \ y2, x2) - prefix_count(y1, y2, x1);\n  }\n\n  X prod(XY x1, XY x2, XY y1, XY\
    \ y2) {\n    if (N == 0) return MX::unit();\n    assert(x1 <= x2 && y1 <= y2);\n\
    \    x1 = XtoI(x1), x2 = XtoI(x2);\n    y1 = YtoI(y1), y2 = YtoI(y2);\n    X res\
    \ = MX::unit();\n    prod_dfs(y1, y2, x1, x2, lg - 1, res);\n    return res;\n\
    \  }\n\nprivate:\n  int prefix_count(int L, int R, int x) {\n    int cnt = 0;\n\
    \    FOR_R(d, lg) {\n      int l0 = bv[d].rank(L, 0), r0 = bv[d].rank(R, 0);\n\
    \      if (x >> d & 1) {\n        cnt += r0 - l0, L += mid[d] - l0, R += mid[d]\
    \ - r0;\n      } else {\n        L = l0, R = r0;\n      }\n    }\n    return cnt;\n\
    \  }\n\n  void prod_dfs(int L, int R, int x1, int x2, int d, X& res) {\n    chmax(x1,\
    \ 0), chmin(x2, 1 << (d + 1));\n    if (x1 >= x2) { return; }\n    assert(0 <=\
    \ x1 && x1 < x2 && x2 <= (1 << (d + 1)));\n    if (x1 == 0 && x2 == (1 << (d +\
    \ 1))) {\n      res = MX::op(res, dat[d + 1].prod(L, R));\n      return;\n   \
    \ }\n    int l0 = bv[d].rank(L, 0), r0 = bv[d].rank(R, 0);\n    prod_dfs(l0, r0,\
    \ x1, x2, d - 1, res);\n    prod_dfs(L + mid[d] - l0, R + mid[d] - r0, x1 - (1\
    \ << d), x2 - (1 << d),\n             d - 1, res);\n  }\n};\n"
  dependsOn:
  - ds/bit_vector.hpp
  - ds/segtree/segtree.hpp
  - alg/monoid/add.hpp
  - ds/static_range_product.hpp
  - ds/sparse_table/sparse_table.hpp
  - ds/sparse_table/disjoint_sparse_table.hpp
  isVerificationFile: false
  path: ds/wavelet_matrix/wavelet_matrix_2d_range_static_monoid.hpp
  requiredBy: []
  timestamp: '2024-04-04 05:27:34+09:00'
  verificationStatus: LIBRARY_ALL_WA
  verifiedWith:
  - test/yukicoder/1600_2.test.cpp
documentation_of: ds/wavelet_matrix/wavelet_matrix_2d_range_static_monoid.hpp
layout: document
redirect_from:
- /library/ds/wavelet_matrix/wavelet_matrix_2d_range_static_monoid.hpp
- /library/ds/wavelet_matrix/wavelet_matrix_2d_range_static_monoid.hpp.html
title: ds/wavelet_matrix/wavelet_matrix_2d_range_static_monoid.hpp
---
