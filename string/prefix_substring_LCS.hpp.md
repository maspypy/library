---
data:
  _extendedDependsOn:
  - icon: ':question:'
    path: alg/monoid/add.hpp
    title: alg/monoid/add.hpp
  - icon: ':question:'
    path: ds/bit_vector.hpp
    title: ds/bit_vector.hpp
  - icon: ':question:'
    path: ds/index_compression.hpp
    title: ds/index_compression.hpp
  - icon: ':question:'
    path: ds/wavelet_matrix/wavelet_matrix.hpp
    title: ds/wavelet_matrix/wavelet_matrix.hpp
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/library_checker/string/prefix_substring_lcs.test.cpp
    title: test/library_checker/string/prefix_substring_lcs.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links:
    - https://codeforces.com/blog/entry/111625
  bundledCode: "#line 1 \"ds/bit_vector.hpp\"\nstruct Bit_Vector {\n  int n;\n  vc<pair<u64,\
    \ u32>> dat;\n  Bit_Vector(int n) : n(n) { dat.assign((n + 127) >> 6, {0, 0});\
    \ }\n  void set(int i) { dat[i >> 6].fi |= u64(1) << (i & 63); }\n  void reset()\
    \ { fill(all(dat), pair<u64, u32>{0, 0}); }\n  void build() {\n    FOR(i, len(dat)\
    \ - 1) dat[i + 1].se = dat[i].se + popcnt(dat[i].fi);\n  }\n  // [0, k) \u5185\
    \u306E 1 \u306E\u500B\u6570\n  int count(int k, bool f) {\n    auto [a, b] = dat[k\
    \ >> 6];\n    int ret = b + popcnt(a & ((u64(1) << (k & 63)) - 1));\n    return\
    \ (f ? ret : k - ret);\n  }\n  int count(int L, int R, bool f) { return count(R,\
    \ f) - count(L, f); }\n  string to_string() {\n    string ans;\n    FOR(i, n)\
    \ ans += '0' + (dat[i / 64].fi >> (i % 64) & 1);\n    return ans;\n  }\n};\n#line\
    \ 1 \"ds/index_compression.hpp\"\ntemplate <typename T>\nstruct Index_Compression_DISTINCT_SMALL\
    \ {\n  static_assert(is_same_v<T, int>);\n  int mi, ma;\n  vc<int> dat;\n  vc<int>\
    \ build(vc<int> X) {\n    mi = 0, ma = -1;\n    if (!X.empty()) mi = MIN(X), ma\
    \ = MAX(X);\n    dat.assign(ma - mi + 2, 0);\n    for (auto& x: X) dat[x - mi\
    \ + 1]++;\n    FOR(i, len(dat) - 1) dat[i + 1] += dat[i];\n    for (auto& x: X)\
    \ { x = dat[x - mi]++; }\n    FOR_R(i, 1, len(dat)) dat[i] = dat[i - 1];\n   \
    \ dat[0] = 0;\n    return X;\n  }\n  int operator()(ll x) { return dat[clamp<ll>(x\
    \ - mi, 0, ma - mi + 1)]; }\n};\n\ntemplate <typename T>\nstruct Index_Compression_SAME_SMALL\
    \ {\n  static_assert(is_same_v<T, int>);\n  int mi, ma;\n  vc<int> dat;\n  vc<int>\
    \ build(vc<int> X) {\n    mi = 0, ma = -1;\n    if (!X.empty()) mi = MIN(X), ma\
    \ = MAX(X);\n    dat.assign(ma - mi + 2, 0);\n    for (auto& x: X) dat[x - mi\
    \ + 1] = 1;\n    FOR(i, len(dat) - 1) dat[i + 1] += dat[i];\n    for (auto& x:\
    \ X) { x = dat[x - mi]; }\n    return X;\n  }\n  int operator()(ll x) { return\
    \ dat[clamp<ll>(x - mi, 0, ma - mi + 1)]; }\n};\n\ntemplate <typename T>\nstruct\
    \ Index_Compression_SAME_LARGE {\n  vc<T> dat;\n  vc<int> build(vc<T> X) {\n \
    \   vc<int> I = argsort(X);\n    vc<int> res(len(X));\n    for (auto& i: I) {\n\
    \      if (!dat.empty() && dat.back() == X[i]) {\n        res[i] = len(dat) -\
    \ 1;\n      } else {\n        res[i] = len(dat);\n        dat.eb(X[i]);\n    \
    \  }\n    }\n    dat.shrink_to_fit();\n    return res;\n  }\n  int operator()(T\
    \ x) { return LB(dat, x); }\n};\n\ntemplate <typename T>\nstruct Index_Compression_DISTINCT_LARGE\
    \ {\n  vc<T> dat;\n  vc<int> build(vc<T> X) {\n    vc<int> I = argsort(X);\n \
    \   vc<int> res(len(X));\n    for (auto& i: I) { res[i] = len(dat), dat.eb(X[i]);\
    \ }\n    dat.shrink_to_fit();\n    return res;\n  }\n  int operator()(T x) { return\
    \ LB(dat, x); }\n};\n\ntemplate <typename T, bool SMALL>\nusing Index_Compression_DISTINCT\
    \ =\n    typename std::conditional<SMALL, Index_Compression_DISTINCT_SMALL<T>,\n\
    \                              Index_Compression_DISTINCT_LARGE<T>>::type;\ntemplate\
    \ <typename T, bool SMALL>\nusing Index_Compression_SAME =\n    typename std::conditional<SMALL,\
    \ Index_Compression_SAME_SMALL<T>,\n                              Index_Compression_SAME_LARGE<T>>::type;\n\
    \n// SAME: [2,3,2] -> [0,1,0]\n// DISTINCT: [2,2,3] -> [0,2,1]\n// (x): lower_bound(X,x)\
    \ \u3092\u304B\u3048\u3059\ntemplate <typename T, bool SAME, bool SMALL>\nusing\
    \ Index_Compression =\n    typename std::conditional<SAME, Index_Compression_SAME<T,\
    \ SMALL>,\n                              Index_Compression_DISTINCT<T, SMALL>>::type;\n\
    #line 2 \"alg/monoid/add.hpp\"\n\r\ntemplate <typename E>\r\nstruct Monoid_Add\
    \ {\r\n  using X = E;\r\n  using value_type = X;\r\n  static constexpr X op(const\
    \ X &x, const X &y) noexcept { return x + y; }\r\n  static constexpr X inverse(const\
    \ X &x) noexcept { return -x; }\r\n  static constexpr X power(const X &x, ll n)\
    \ noexcept { return X(n) * x; }\r\n  static constexpr X unit() { return X(0);\
    \ }\r\n  static constexpr bool commute = true;\r\n};\r\n#line 4 \"ds/wavelet_matrix/wavelet_matrix.hpp\"\
    \n\r\n// \u9759\u7684\u30E1\u30BD\u30C3\u30C9inverse\u306E\u5B58\u5728\u3092\u30C1\
    \u30A7\u30C3\u30AF\u3059\u308B\u30C6\u30F3\u30D7\u30EC\u30FC\u30C8\r\ntemplate\
    \ <typename, typename = std::void_t<>>\r\nstruct has_inverse : std::false_type\
    \ {};\r\n\r\ntemplate <typename T>\r\nstruct has_inverse<T, std::void_t<decltype(\r\
    \n                          T::inverse(std::declval<typename T::value_type>()))>>\r\
    \n    : std::true_type {};\r\n\r\nstruct Dummy_Data_Structure {\r\n  using MX\
    \ = Monoid_Add<bool>;\r\n  void build(const vc<bool>& A) {}\r\n};\r\n\r\ntemplate\
    \ <typename Y, bool SMALL_Y, typename SEGTREE = Dummy_Data_Structure>\r\nstruct\
    \ Wavelet_Matrix {\r\n  using Mono = typename SEGTREE::MX;\r\n  using T = typename\
    \ Mono::value_type;\r\n  static_assert(Mono::commute);\r\n\r\n  int n, log, K;\r\
    \n  Index_Compression<Y, true, SMALL_Y> IDX;\r\n  vc<Y> ItoY;\r\n  vc<int> mid;\r\
    \n  vc<Bit_Vector> bv;\r\n  vc<SEGTREE> seg;\r\n\r\n  Wavelet_Matrix() {}\r\n\
    \  Wavelet_Matrix(const vc<Y>& A) { build(A); }\r\n  Wavelet_Matrix(const vc<Y>&\
    \ A, vc<T>& SUM_Data) { build(A, SUM_Data); }\r\n  template <typename F>\r\n \
    \ Wavelet_Matrix(int n, F f) {\r\n    build(n, f);\r\n  }\r\n\r\n  template <typename\
    \ F>\r\n  void build(int m, F f) {\r\n    vc<Y> A(m);\r\n    vc<T> S(m);\r\n \
    \   for (int i = 0; i < m; ++i) tie(A[i], S[i]) = f(i);\r\n  }\r\n\r\n  void build(const\
    \ vc<Y>& A) { build(A, vc<T>(len(A), Mono::unit())); }\r\n  void build(const vc<Y>&\
    \ A, vc<T> S) {\r\n    n = len(A);\r\n    vc<int> B = IDX.build(A);\r\n    K =\
    \ 0;\r\n    for (auto& x: B) chmax(K, x + 1);\r\n    ItoY.resize(K);\r\n    FOR(i,\
    \ n) ItoY[B[i]] = A[i];\r\n    log = 0;\r\n    while ((1 << log) < K) ++log;\r\
    \n    mid.resize(log), bv.assign(log, Bit_Vector(n));\r\n    vc<int> B0(n), B1(n);\r\
    \n    vc<T> S0(n), S1(n);\r\n    seg.resize(log + 1);\r\n    seg[log].build(S);\r\
    \n    for (int d = log - 1; d >= 0; --d) {\r\n      int p0 = 0, p1 = 0;\r\n  \
    \    for (int i = 0; i < n; ++i) {\r\n        bool f = (B[i] >> d & 1);\r\n  \
    \      if (!f) { B0[p0] = B[i], S0[p0] = S[i], p0++; }\r\n        if (f) { bv[d].set(i),\
    \ B1[p1] = B[i], S1[p1] = S[i], p1++; }\r\n      }\r\n      swap(B, B0), swap(S,\
    \ S0);\r\n      move(B1.begin(), B1.begin() + p1, B.begin() + p0);\r\n      move(S1.begin(),\
    \ S1.begin() + p1, S.begin() + p0);\r\n      mid[d] = p0, bv[d].build(), seg[d].build(S);\r\
    \n    }\r\n  }\r\n\r\n  // [L,R) x [0,y)\r\n  int prefix_count(int L, int R, Y\
    \ y) {\r\n    int p = IDX(y);\r\n    if (p == 0) return 0;\r\n    if (p == K)\
    \ return R - L;\r\n    int cnt = 0;\r\n    for (int d = log - 1; d >= 0; --d)\
    \ {\r\n      int l0 = bv[d].count(L, 0), r0 = bv[d].count(R, 0);\r\n      int\
    \ l1 = L + mid[d] - l0, r1 = R + mid[d] - r0;\r\n      if (p >> d & 1) cnt +=\
    \ r0 - l0, L = l1, R = r1;\r\n      if (!(p >> d & 1)) L = l0, R = r0;\r\n   \
    \ }\r\n    return cnt;\r\n  }\r\n\r\n  // [L,R) x [y1,y2)\r\n  int count(int L,\
    \ int R, Y y1, Y y2) {\r\n    return prefix_count(L, R, y2) - prefix_count(L,\
    \ R, y1);\r\n  }\r\n\r\n  // [L,R) x [0,y)\r\n  pair<int, T> prefix_count_and_prod(int\
    \ L, int R, Y y) {\r\n    int p = IDX(y);\r\n    if (p == 0) return {0, Mono::unit()};\r\
    \n    if (p == K) return {R - L, seg[log].prod(L, R)};\r\n    int cnt = 0;\r\n\
    \    T t = Mono::unit();\r\n    for (int d = log - 1; d >= 0; --d) {\r\n     \
    \ int l0 = bv[d].count(L, 0), r0 = bv[d].count(R, 0);\r\n      int l1 = L + mid[d]\
    \ - l0, r1 = R + mid[d] - r0;\r\n      if (p >> d & 1) {\r\n        cnt += r0\
    \ - l0, t = Mono::op(t, seg[d].prod(l0, r0)), L = l1, R = r1;\r\n      }\r\n \
    \     if (!(p >> d & 1)) L = l0, R = r0;\r\n    }\r\n    return {cnt, t};\r\n\
    \  }\r\n\r\n  // [L,R) x [y1,y2)\r\n  pair<int, T> count_and_prod(int L, int R,\
    \ Y y1, Y y2) {\r\n    if constexpr (has_inverse<Mono>::value) {\r\n      auto\
    \ [c1, t1] = prefix_count_and_prod(L, R, y1);\r\n      auto [c2, t2] = prefix_count_and_prod(L,\
    \ R, y2);\r\n      return {c2 - c1, Mono::op(Mono::inverse(t1), t2)};\r\n    }\r\
    \n    int lo = IDX(y1), hi = IDX(y2), cnt = 0;\r\n    T t = Mono::unit();\r\n\
    \    auto dfs = [&](auto& dfs, int d, int L, int R, int a, int b) -> void {\r\n\
    \      assert(b - a == (1 << d));\r\n      if (hi <= a || b <= lo) return;\r\n\
    \      if (lo <= a && b <= hi) {\r\n        cnt += R - L, t = Mono::op(t, seg[d].prod(L,\
    \ R));\r\n        return;\r\n      }\r\n      --d;\r\n      int c = (a + b) /\
    \ 2;\r\n      int l0 = bv[d].count(L, 0), r0 = bv[d].count(R, 0);\r\n      int\
    \ l1 = L + mid[d] - l0, r1 = R + mid[d] - r0;\r\n      dfs(dfs, d, l0, r0, a,\
    \ c), dfs(dfs, d, l1, r1, c, b);\r\n    };\r\n    dfs(dfs, log, L, R, 0, 1 <<\
    \ log);\r\n    return {cnt, t};\r\n  }\r\n\r\n  // [L,R) x [y1,y2)\r\n  T prefix_prod(int\
    \ L, int R, Y y) { return prefix_count_and_prod(L, R, y).se; }\r\n  // [L,R) x\
    \ [y1,y2)\r\n  T prod(int L, int R, Y y1, Y y2) { return count_and_prod(L, R,\
    \ y1, y2).se; }\r\n\r\n  Y kth(int L, int R, int k) {\r\n    assert(0 <= k &&\
    \ k < R - L);\r\n    int p = 0;\r\n    for (int d = log - 1; d >= 0; --d) {\r\n\
    \      int l0 = bv[d].count(L, 0), r0 = bv[d].count(R, 0);\r\n      int l1 = L\
    \ + mid[d] - l0, r1 = R + mid[d] - r0;\r\n      if (k < r0 - l0) {\r\n       \
    \ L = l0, R = r0;\r\n      } else {\r\n        k -= r0 - l0, L = l1, R = r1, p\
    \ |= 1 << d;\r\n      }\r\n    }\r\n    return ItoY[p];\r\n  }\r\n\r\n  // y \u4EE5\
    \u4E0A\u6700\u5C0F OR infty<Y>\r\n  Y next(int L, int R, Y y) {\r\n    int k =\
    \ IDX(y);\r\n    int p = K;\r\n\r\n    auto dfs = [&](auto& dfs, int d, int L,\
    \ int R, int a, int b) -> void {\r\n      if (p <= a || L == R || b <= k) return;\r\
    \n      if (d == 0) {\r\n        chmin(p, a);\r\n        return;\r\n      }\r\n\
    \      --d;\r\n      int c = (a + b) / 2;\r\n      int l0 = bv[d].count(L, 0),\
    \ r0 = bv[d].count(R, 0);\r\n      int l1 = L + mid[d] - l0, r1 = R + mid[d] -\
    \ r0;\r\n      dfs(dfs, d, l0, r0, a, c), dfs(dfs, d, l1, r1, c, b);\r\n    };\r\
    \n    dfs(dfs, log, L, R, 0, 1 << log);\r\n    return (p == K ? infty<Y> : ItoY[p]);\r\
    \n  }\r\n\r\n  // y \u4EE5\u4E0B\u6700\u5927 OR -infty<T>\r\n  Y prev(int L, int\
    \ R, Y y) {\r\n    int k = IDX(y + 1);\r\n    int p = -1;\r\n    auto dfs = [&](auto&\
    \ dfs, int d, int L, int R, int a, int b) -> void {\r\n      if (b - 1 <= p ||\
    \ L == R || k <= a) return;\r\n      if (d == 0) {\r\n        chmax(p, a);\r\n\
    \        return;\r\n      }\r\n      --d;\r\n      int c = (a + b) / 2;\r\n  \
    \    int l0 = bv[d].count(L, 0), r0 = bv[d].count(R, 0);\r\n      int l1 = L +\
    \ mid[d] - l0, r1 = R + mid[d] - r0;\r\n      dfs(dfs, d, l1, r1, c, b), dfs(dfs,\
    \ d, l0, r0, a, c);\r\n    };\r\n    dfs(dfs, log, L, R, 0, 1 << log);\r\n   \
    \ return (p == -1 ? -infty<Y> : ItoY[p]);\r\n  }\r\n\r\n  Y median(bool UPPER,\
    \ int L, int R) {\r\n    assert(0 <= L && L < R && R <= n);\r\n    int k = (UPPER\
    \ ? (R - L) / 2 : (R - L - 1) / 2);\r\n    return kth(L, R, k);\r\n  }\r\n\r\n\
    \  pair<Y, T> kth_value_and_prod(int L, int R, int k) {\r\n    assert(0 <= k &&\
    \ k <= R - L);\r\n    if (k == R - L) return {infty<Y>, seg[log].prod(L, R)};\r\
    \n    int p = 0;\r\n    T t = Mono::unit();\r\n    for (int d = log - 1; d >=\
    \ 0; --d) {\r\n      int l0 = bv[d].count(L, 0), r0 = bv[d].count(R, 0);\r\n \
    \     int l1 = L + mid[d] - l0, r1 = R + mid[d] - r0;\r\n      if (k < r0 - l0)\
    \ {\r\n        L = l0, R = r0;\r\n      } else {\r\n        t = Mono::op(t, seg[d].prod(l0,\
    \ r0)), k -= r0 - l0, L = l1, R = r1,\r\n        p |= 1 << d;\r\n      }\r\n \
    \   }\r\n    t = Mono::op(t, seg[0].prod(L, L + k));\r\n    return {ItoY[p], t};\r\
    \n  }\r\n\r\n  T prod_index_range(int L, int R, int k1, int k2) {\r\n    static_assert(has_inverse<Mono>::value);\r\
    \n    T t1 = kth_value_and_prod(L, R, k1).se;\r\n    T t2 = kth_value_and_prod(L,\
    \ R, k2).se;\r\n    return Mono::op(Mono::inverse(t1), t2);\r\n  }\r\n\r\n  //\
    \ [L,R) x [0,y) \u3067\u306E check(cnt, prod) \u304C true \u3068\u306A\u308B\u6700\
    \u5927\u306E (cnt,prod)\r\n  template <typename F>\r\n  pair<int, T> max_right(F\
    \ check, int L, int R) {\r\n    int cnt = 0;\r\n    T t = Mono::unit();\r\n  \
    \  assert(check(0, Mono::unit()));\r\n    if (check(R - L, seg[log].prod(L, R)))\
    \ {\r\n      return {R - L, seg[log].prod(L, R)};\r\n    }\r\n    for (int d =\
    \ log - 1; d >= 0; --d) {\r\n      int l0 = bv[d].count(L, 0), r0 = bv[d].count(R,\
    \ 0);\r\n      int l1 = L + mid[d] - l0, r1 = R + mid[d] - r0;\r\n      int cnt1\
    \ = cnt + r0 - l0, t1 = Mono::op(t, seg[d].prod(l0, r0));\r\n      if (check(cnt1,\
    \ t1)) {\r\n        cnt = cnt1, t = t1, L = l1, R = r1;\r\n      } else {\r\n\
    \        L = l0, R = r0;\r\n      }\r\n    }\r\n    return {cnt, t};\r\n  }\r\n\
    \r\n  void set(int i, T t) {\r\n    assert(0 <= i && i < n);\r\n    int L = i,\
    \ R = i + 1;\r\n    seg[log].set(L, t);\r\n    for (int d = log - 1; d >= 0; --d)\
    \ {\r\n      int l0 = bv[d].count(L, 0), r0 = bv[d].count(R, 0);\r\n      int\
    \ l1 = L + mid[d] - l0, r1 = R + mid[d] - r0;\r\n      if (l0 < r0) L = l0, R\
    \ = r0;\r\n      if (l0 == r0) L = l1, R = r1;\r\n      seg[d].set(L, t);\r\n\
    \    }\r\n  }\r\n  void multiply(int i, T t) {\r\n    assert(0 <= i && i < n);\r\
    \n    int L = i, R = i + 1;\r\n    seg[log].multiply(L, t);\r\n    for (int d\
    \ = log - 1; d >= 0; --d) {\r\n      int l0 = bv[d].count(L, 0), r0 = bv[d].count(R,\
    \ 0);\r\n      int l1 = L + mid[d] - l0, r1 = R + mid[d] - r0;\r\n      if (l0\
    \ < r0) L = l0, R = r0;\r\n      if (l0 == r0) L = l1, R = r1;\r\n      seg[d].multiply(L,\
    \ t);\r\n    }\r\n  }\r\n};\r\n\r\n/*\r\n// \u5EA7\u5727\u3059\u308B\u304B\u3069\
    \u3046\u304B\u3092 COMPRESS \u3067\u6307\u5B9A\u3059\u308B\r\n// xor \u7684\u306A\
    \u4F7F\u3044\u65B9\u3092\u3059\u308B\u5834\u5408\u306B\u306F\u3001\u30B3\u30F3\
    \u30B9\u30C8\u30E9\u30AF\u30BF\u3067 log \u3092\u6E21\u3059\u3053\u3068\r\ntemplate\
    \ <typename T, bool COMPRESS, bool USE_SUM>\r\nstruct Wavelet_Matrix_Old {\r\n\
    \  static_assert(is_same_v<T, int> || is_same_v<T, ll>);\r\n  int N, lg;\r\n \
    \ vector<int> mid;\r\n  vector<Bit_Vector> bv;\r\n  vc<T> key;\r\n  bool set_log;\r\
    \n  vvc<T> cumsum;\r\n\r\n  Wavelet_Matrix_Old() {}\r\n\r\n  // \u548C\u3092\u4F7F\
    \u308F\u306A\u3044\u306A\u3089\u3001SUM_data \u306F\u7A7A\u3067\u3088\u3044\r\n\
    \  Wavelet_Matrix_Old(vc<T> A, vc<T> SUM_data = {}, int log = -1) {\r\n    build(A,\
    \ SUM_data, log);\r\n  }\r\n\r\n  void build(vc<T> A, vc<T> SUM_data = {}, int\
    \ log = -1) {\r\n    if constexpr (USE_SUM) { assert(len(SUM_data) == len(A));\
    \ }\r\n    N = len(A), lg = log, set_log = (log != -1);\r\n    if (N == 0) {\r\
    \n      lg = 0;\r\n      cumsum.resize(1);\r\n      cumsum[0] = {0};\r\n     \
    \ return;\r\n    }\r\n    vc<T>& S = SUM_data;\r\n    if (COMPRESS) {\r\n    \
    \  assert(!set_log);\r\n      key.reserve(N);\r\n      vc<int> I = argsort(A);\r\
    \n      for (auto&& i: I) {\r\n        if (key.empty() || key.back() != A[i])\
    \ key.eb(A[i]);\r\n        A[i] = len(key) - 1;\r\n      }\r\n      key.shrink_to_fit();\r\
    \n    }\r\n    if (lg == -1) lg = __lg(max<ll>(MAX(A), 1)) + 1;\r\n    mid.resize(lg),\
    \ bv.assign(lg, Bit_Vector(N));\r\n    if constexpr (USE_SUM) cumsum.assign(1\
    \ + lg, vc<T>(N + 1, 0));\r\n    S.resize(N);\r\n    vc<T> A0(N), A1(N);\r\n \
    \   vc<T> S0(N), S1(N);\r\n    FOR_R(d, -1, lg) {\r\n      int p0 = 0, p1 = 0;\r\
    \n      if constexpr (USE_SUM) {\r\n        FOR(i, N) { cumsum[d + 1][i + 1] =\
    \ cumsum[d + 1][i] + S[i]; }\r\n      }\r\n      if (d == -1) break;\r\n     \
    \ FOR(i, N) {\r\n        bool f = (A[i] >> d & 1);\r\n        if (!f) {\r\n  \
    \        if constexpr (USE_SUM) S0[p0] = S[i];\r\n          A0[p0++] = A[i];\r\
    \n        } else {\r\n          if constexpr (USE_SUM) S1[p1] = S[i];\r\n    \
    \      bv[d].set(i), A1[p1++] = A[i];\r\n        }\r\n      }\r\n      mid[d]\
    \ = p0;\r\n      bv[d].build();\r\n      swap(A, A0), swap(S, S0);\r\n      FOR(i,\
    \ p1) A[p0 + i] = A1[i], S[p0 + i] = S1[i];\r\n    }\r\n  }\r\n\r\n  // [L,R)\
    \ x [a,b), (cnt, monoid value)\r\n  pair<int, T> range_cnt_sum(int L, int R, T\
    \ a, T b, T xor_val = 0) {\r\n    if (xor_val != 0) assert(set_log);\r\n    if\
    \ (a == b) return {0, 0};\r\n    if (COMPRESS) a = LB(key, a), b = LB(key, b);\r\
    \n    int cnt = 0;\r\n    T sm = 0;\r\n    auto dfs = [&](auto& dfs, int d, int\
    \ L, int R, T lx, T rx) -> void {\r\n      if (rx <= a || b <= lx) return;\r\n\
    \      if (a <= lx && rx <= b) {\r\n        cnt += R - L, sm += get(d, L, R);\r\
    \n        return;\r\n      }\r\n      --d;\r\n      T mx = (lx + rx) / 2;\r\n\
    \      int l0 = bv[d].count(L, 0), r0 = bv[d].count(R, 0);\r\n      int l1 = L\
    \ + mid[d] - l0, r1 = R + mid[d] - r0;\r\n      if (xor_val >> d & 1) swap(l0,\
    \ l1), swap(r0, r1);\r\n      dfs(dfs, d, l0, r0, lx, mx), dfs(dfs, d, l1, r1,\
    \ mx, rx);\r\n    };\r\n    dfs(dfs, lg, L, R, 0, T(1) << lg);\r\n    return {cnt,\
    \ sm};\r\n  }\r\n\r\n  // smallest k, sum of [0,k)\r\n  pair<T, T> kth_value_sum(int\
    \ L, int R, int k, T xor_val = 0) {\r\n    assert(0 <= k && k <= R - L);\r\n \
    \   if (k == R - L) { return {infty<T>, sum_all(L, R)}; }\r\n    if (L == R) return\
    \ {infty<T>, 0};\r\n    if (xor_val != 0) assert(set_log);\r\n    T sm = 0, val\
    \ = 0;\r\n    for (int d = lg - 1; d >= 0; --d) {\r\n      // \u3044\u307E\u5E45\
    \ d+1 \u306E trie node \u306B\u5C45\u3066, \u5E45 d \u306E\u3068\u3053\u308D\u306B\
    \u884C\u304F\r\n      int l0 = bv[d].count(L, 0), r0 = bv[d].count(R, 0);\r\n\
    \      int l1 = L + mid[d] - l0, r1 = R + mid[d] - r0;\r\n      if (xor_val >>\
    \ d & 1) swap(l0, l1), swap(r0, r1);\r\n      if (k < r0 - l0) {\r\n        L\
    \ = l0, R = r0;\r\n      } else {\r\n        k -= r0 - l0, val |= T(1) << d, L\
    \ = l1, R = r1;\r\n        if constexpr (USE_SUM) sm += get(d, l0, r0);\r\n  \
    \    }\r\n    }\r\n    if constexpr (USE_SUM) sm += get(0, L, L + k);\r\n    if\
    \ (COMPRESS) val = key[val];\r\n\r\n    return {val, sm};\r\n  }\r\n\r\n  int\
    \ count(int L, int R, T a, T b, T xor_val = 0) {\r\n    return range_cnt_sum(L,\
    \ R, a, b, xor_val).fi;\r\n  }\r\n  T sum(int L, int R, T a, T b, T xor_val =\
    \ 0) {\r\n    static_assert(USE_SUM);\r\n    return range_cnt_sum(L, R, a, b,\
    \ xor_val).se;\r\n  }\r\n\r\n  T sum_index_range(int L, int R, int k1, int k2,\
    \ T xor_val = 0) {\r\n    static_assert(USE_SUM);\r\n    return kth_value_sum(L,\
    \ R, k2, xor_val).se\r\n           - kth_value_sum(L, R, k1, xor_val).se;\r\n\
    \  }\r\n  T kth(int L, int R, int k, T xor_val = 0) {\r\n    assert(0 <= k &&\
    \ k < R - L);\r\n    return kth_value_sum(L, R, k, xor_val).fi;\r\n  }\r\n\r\n\
    \  // x \u4EE5\u4E0A\u6700\u5C0F OR infty<T>\r\n  T next(int L, int R, T x, T\
    \ xor_val = 0) {\r\n    if (xor_val != 0) assert(set_log);\r\n    if (L == R)\
    \ return infty<T>;\r\n    if (COMPRESS) x = LB(key, x);\r\n    T ans = infty<T>;\r\
    \n\r\n    auto dfs = [&](auto& dfs, int d, int L, int R, T lx, T rx) -> void {\r\
    \n      if (ans <= lx || L == R || rx <= x) return;\r\n      if (d == 0) {\r\n\
    \        chmin(ans, lx);\r\n        return;\r\n      }\r\n      --d;\r\n     \
    \ T mx = (lx + rx) / 2;\r\n      int l0 = bv[d].count(L, 0), r0 = bv[d].count(R,\
    \ 0);\r\n      int l1 = L + mid[d] - l0, r1 = R + mid[d] - r0;\r\n      if (xor_val\
    \ >> d & 1) swap(l0, l1), swap(r0, r1);\r\n      dfs(dfs, d, l0, r0, lx, mx),\
    \ dfs(dfs, d, l1, r1, mx, rx);\r\n    };\r\n    dfs(dfs, lg, L, R, 0, T(1) <<\
    \ lg);\r\n    if (COMPRESS && ans < infty<T>) ans = key[ans];\r\n    return ans;\r\
    \n  }\r\n\r\n  // x \u4EE5\u4E0B\u6700\u5927 OR -infty<T>\r\n  T prev(int L, int\
    \ R, T x, T xor_val = 0) {\r\n    if (xor_val != 0) assert(set_log);\r\n    if\
    \ (L == R) return -infty<T>;\r\n    T ans = -infty<int>;\r\n    ++x;\r\n    if\
    \ (COMPRESS) x = LB(key, x);\r\n\r\n    auto dfs = [&](auto& dfs, int d, int L,\
    \ int R, T lx, T rx) -> void {\r\n      if ((rx - 1) <= ans || L == R || x <=\
    \ lx) return;\r\n      if (d == 0) {\r\n        chmax(ans, lx);\r\n        return;\r\
    \n      }\r\n      --d;\r\n      T mx = (lx + rx) / 2;\r\n      int l0 = bv[d].count(L,\
    \ 0), r0 = bv[d].count(R, 0);\r\n      int l1 = L + mid[d] - l0, r1 = R + mid[d]\
    \ - r0;\r\n      if (xor_val >> d & 1) swap(l0, l1), swap(r0, r1);\r\n      dfs(dfs,\
    \ d, l1, r1, mx, rx), dfs(dfs, d, l0, r0, lx, mx);\r\n    };\r\n    dfs(dfs, lg,\
    \ L, R, 0, T(1) << lg);\r\n    if (COMPRESS && ans != -infty<T>) ans = key[ans];\r\
    \n    return ans;\r\n  }\r\n\r\n  // xor \u3057\u305F\u7D50\u679C\u3067\u3001\
    [L, R) \u306E\u4E2D\u3067\u4E2D\u592E\u5024\u3002\r\n  // LOWER = true\uFF1A\u4E0B\
    \u5074\u4E2D\u592E\u5024\u3001false\uFF1A\u4E0A\u5074\u4E2D\u592E\u5024\r\n  T\
    \ median(bool UPPER, int L, int R, T xor_val = 0) {\r\n    int n = R - L;\r\n\
    \    int k = (UPPER ? n / 2 : (n - 1) / 2);\r\n    return kth(L, R, k, xor_val);\r\
    \n  }\r\n\r\n  T sum_all(int L, int R) { return get(lg, L, R); }\r\n\r\n  // check(cnt,\
    \ prefix sum) \u304C true \u3068\u306A\u308B\u3088\u3046\u306A\u6700\u5927\u306E\
    \ (cnt, sum)\r\n  template <typename F>\r\n  pair<int, T> max_right(F check, int\
    \ L, int R, T xor_val = 0) {\r\n    assert(check(0, 0));\r\n    if (xor_val !=\
    \ 0) assert(set_log);\r\n    if (L == R) return {0, 0};\r\n    if (check(R - L,\
    \ get(lg, L, R))) return {R - L, get(lg, L, R)};\r\n    int cnt = 0;\r\n    T\
    \ sm = 0;\r\n    for (int d = lg - 1; d >= 0; --d) {\r\n      int l0 = bv[d].count(L,\
    \ 0), r0 = bv[d].count(R, 0);\r\n      int l1 = L + mid[d] - l0, r1 = R + mid[d]\
    \ - r0;\r\n      if (xor_val >> d & 1) swap(l0, l1), swap(r0, r1);\r\n      if\
    \ (check(cnt + r0 - l0, sm + get(d, l0, r0))) {\r\n        cnt += r0 - l0, sm\
    \ += get(d, l0, r0);\r\n        L = l1, R = r1;\r\n      } else {\r\n        L\
    \ = l0, R = r0;\r\n      }\r\n    }\r\n    int k = binary_search(\r\n        [&](int\
    \ k) -> bool { return check(cnt + k, sm + get(0, L, L + k)); }, 0,\r\n       \
    \ R - L);\r\n    cnt += k, sm += get(0, L, L + k);\r\n    return {cnt, sm};\r\n\
    \  }\r\n\r\nprivate:\r\n  inline T get(int d, int L, int R) {\r\n    if constexpr\
    \ (USE_SUM) return cumsum[d][R] - cumsum[d][L];\r\n    return 0;\r\n  }\r\n};\r\
    \n*/\r\n#line 2 \"string/prefix_substring_LCS.hpp\"\n\n// https://codeforces.com/blog/entry/111625\n\
    struct Prefix_Substring_LCS {\n  int N, M;\n  vc<Wavelet_Matrix<int, true>> WM;\n\
    \n  template <typename STRING>\n  Prefix_Substring_LCS(STRING S, STRING T) {\n\
    \    build(S, T);\n  }\n\n  template <typename STRING>\n  void build(STRING S,\
    \ STRING T) {\n    N = len(S), M = len(T);\n    vv(int, dph, N + 1, M + 1);\n\
    \    vv(int, dpv, N + 1, M + 1);\n    FOR(j, M + 1) dph[0][j] = j;\n    FOR(i,\
    \ 1, N + 1) FOR(j, 1, M + 1) {\n      bool same = S[i - 1] == T[j - 1];\n    \
    \  int a = dph[i - 1][j], b = dpv[i][j - 1];\n      dph[i][j] = (same ? b : max(a,\
    \ b));\n      dpv[i][j] = (same ? a : min(a, b));\n    }\n    FOR(i, N + 1) {\
    \ WM.eb(Wavelet_Matrix<int, true>(dph[i])); }\n  }\n\n  // LCS(S[0:n], T[L:R])\n\
    \  int query(int n, int L, int R) { return WM[n].count(L + 1, R + 1, 0, L + 1);\
    \ }\n};\n"
  code: "#include \"ds/wavelet_matrix/wavelet_matrix.hpp\"\n\n// https://codeforces.com/blog/entry/111625\n\
    struct Prefix_Substring_LCS {\n  int N, M;\n  vc<Wavelet_Matrix<int, true>> WM;\n\
    \n  template <typename STRING>\n  Prefix_Substring_LCS(STRING S, STRING T) {\n\
    \    build(S, T);\n  }\n\n  template <typename STRING>\n  void build(STRING S,\
    \ STRING T) {\n    N = len(S), M = len(T);\n    vv(int, dph, N + 1, M + 1);\n\
    \    vv(int, dpv, N + 1, M + 1);\n    FOR(j, M + 1) dph[0][j] = j;\n    FOR(i,\
    \ 1, N + 1) FOR(j, 1, M + 1) {\n      bool same = S[i - 1] == T[j - 1];\n    \
    \  int a = dph[i - 1][j], b = dpv[i][j - 1];\n      dph[i][j] = (same ? b : max(a,\
    \ b));\n      dpv[i][j] = (same ? a : min(a, b));\n    }\n    FOR(i, N + 1) {\
    \ WM.eb(Wavelet_Matrix<int, true>(dph[i])); }\n  }\n\n  // LCS(S[0:n], T[L:R])\n\
    \  int query(int n, int L, int R) { return WM[n].count(L + 1, R + 1, 0, L + 1);\
    \ }\n};\n"
  dependsOn:
  - ds/wavelet_matrix/wavelet_matrix.hpp
  - ds/bit_vector.hpp
  - ds/index_compression.hpp
  - alg/monoid/add.hpp
  isVerificationFile: false
  path: string/prefix_substring_LCS.hpp
  requiredBy: []
  timestamp: '2024-07-19 20:55:35+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/library_checker/string/prefix_substring_lcs.test.cpp
documentation_of: string/prefix_substring_LCS.hpp
layout: document
redirect_from:
- /library/string/prefix_substring_LCS.hpp
- /library/string/prefix_substring_LCS.hpp.html
title: string/prefix_substring_LCS.hpp
---
