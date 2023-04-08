---
data:
  _extendedDependsOn:
  - icon: ':question:'
    path: alg/monoid/add.hpp
    title: alg/monoid/add.hpp
  - icon: ':heavy_check_mark:'
    path: ds/bit_vector.hpp
    title: ds/bit_vector.hpp
  - icon: ':heavy_check_mark:'
    path: ds/wavelet_matrix.hpp
    title: ds/wavelet_matrix.hpp
  - icon: ':x:'
    path: graph/tree.hpp
    title: graph/tree.hpp
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':warning:'
  attributes:
    links:
    - https://atcoder.jp/contests/pakencamp-2022-day1/tasks/pakencamp_2022_day1_j
    - https://atcoder.jp/contests/utpc2011/tasks/utpc2011_12
  bundledCode: "#line 1 \"graph/ds/tree_wavelet_matrix.hpp\"\n\n#line 1 \"ds/bit_vector.hpp\"\
    \nstruct Bit_Vector {\n  vc<pair<u32, u32>> dat;\n  Bit_Vector(int n) { dat.assign((n\
    \ + 63) >> 5, {0, 0}); }\n\n  void set(int i) { dat[i >> 5].fi |= u32(1) << (i\
    \ & 31); }\n\n  void build() {\n    FOR(i, len(dat) - 1) dat[i + 1].se = dat[i].se\
    \ + popcnt(dat[i].fi);\n  }\n\n  // [0, k) \u5185\u306E 1 \u306E\u500B\u6570\n\
    \  int rank(int k, bool f = 1) {\n    auto [a, b] = dat[k >> 5];\n    int ret\
    \ = b + popcnt(a & ((u32(1) << (k & 31)) - 1));\n    return (f ? ret : k - ret);\n\
    \  }\n};\n#line 2 \"alg/monoid/add.hpp\"\n\r\ntemplate <typename X>\r\nstruct\
    \ Monoid_Add {\r\n  using value_type = X;\r\n  static constexpr X op(const X &x,\
    \ const X &y) noexcept { return x + y; }\r\n  static constexpr X inverse(const\
    \ X &x) noexcept { return -x; }\r\n  static constexpr X power(const X &x, ll n)\
    \ noexcept { return X(n) * x; }\r\n  static constexpr X unit() { return X(0);\
    \ }\r\n  static constexpr bool commute = true;\r\n};\r\n#line 3 \"ds/wavelet_matrix.hpp\"\
    \n\r\n// \u5EA7\u5727\u3059\u308B\u304B\u3069\u3046\u304B\u3092 COMPRESS \u3067\
    \u6307\u5B9A\u3059\u308B\r\n// xor \u7684\u306A\u4F7F\u3044\u65B9\u3092\u3059\u308B\
    \u5834\u5408\u306B\u306F\u3001\u30B3\u30F3\u30B9\u30C8\u30E9\u30AF\u30BF\u3067\
    \ log \u3092\u6E21\u3059\u3053\u3068\r\ntemplate <typename T, bool COMPRESS, typename\
    \ Monoid = Monoid_Add<T>>\r\nstruct Wavelet_Matrix {\r\n  using MX = Monoid;\r\
    \n  using X = typename MX::value_type;\r\n  static_assert(MX::commute);\r\n  int\
    \ N, lg;\r\n  vector<int> mid;\r\n  vector<Bit_Vector> bv;\r\n  vc<T> key;\r\n\
    \  bool set_log;\r\n  vvc<X> cumsum;\r\n\r\n  Wavelet_Matrix() {}\r\n\r\n  //\
    \ \u548C\u3092\u4F7F\u308F\u306A\u3044\u306A\u3089\u3001SUM_data \u306F\u7A7A\u3067\
    \u3088\u3044\r\n  Wavelet_Matrix(vc<T> A, vc<X> SUM_data = {}, int log = -1) {\r\
    \n    build(A, SUM_data, log);\r\n  }\r\n\r\n  void build(vc<T> A, vc<X> SUM_data\
    \ = {}, int log = -1) {\r\n    N = len(A), lg = log, set_log = (log != -1);\r\n\
    \    bool MAKE_SUM = !(SUM_data.empty());\r\n    vc<X>& S = SUM_data;\r\n    if\
    \ (COMPRESS) {\r\n      assert(!set_log);\r\n      key.reserve(N);\r\n      vc<int>\
    \ I = argsort(A);\r\n      for (auto&& i: I) {\r\n        if (key.empty() || key.back()\
    \ != A[i]) key.eb(A[i]);\r\n        A[i] = len(key) - 1;\r\n      }\r\n      key.shrink_to_fit();\r\
    \n    }\r\n    if (lg == -1) lg = __lg(max<ll>(MAX(A), 1)) + 1;\r\n    mid.resize(lg);\r\
    \n    bv.assign(lg, Bit_Vector(N));\r\n    if (MAKE_SUM) cumsum.assign(1 + lg,\
    \ vc<X>(N + 1, MX::unit()));\r\n    S.resize(N);\r\n    vc<T> A0(N), A1(N);\r\n\
    \    vc<X> S0(N), S1(N);\r\n    FOR_R(d, -1, lg) {\r\n      int p0 = 0, p1 = 0;\r\
    \n      if (MAKE_SUM) {\r\n        FOR(i, N) { cumsum[d + 1][i + 1] = MX::op(cumsum[d\
    \ + 1][i], S[i]); }\r\n      }\r\n      if (d == -1) break;\r\n      FOR(i, N)\
    \ {\r\n        bool f = (A[i] >> d & 1);\r\n        if (!f) {\r\n          if\
    \ (MAKE_SUM) S0[p0] = S[i];\r\n          A0[p0++] = A[i];\r\n        }\r\n   \
    \     if (f) {\r\n          if (MAKE_SUM) S1[p1] = S[i];\r\n          bv[d].set(i),\
    \ A1[p1++] = A[i];\r\n        }\r\n      }\r\n      mid[d] = p0;\r\n      bv[d].build();\r\
    \n      swap(A, A0), swap(S, S0);\r\n      FOR(i, p1) A[p0 + i] = A1[i], S[p0\
    \ + i] = S1[i];\r\n    }\r\n  }\r\n\r\n  // xor \u3057\u305F\u7D50\u679C\u3067\
    \ [a, b) \u306B\u53CE\u307E\u308B\u3082\u306E\u3092\u6570\u3048\u308B\r\n  int\
    \ count(int L, int R, T a, T b, T xor_val = 0) {\r\n    return prefix_count(L,\
    \ R, b, xor_val) - prefix_count(L, R, a, xor_val);\r\n  }\r\n\r\n  int count(vc<pair<int,\
    \ int>> segments, T a, T b, T xor_val = 0) {\r\n    int res = 0;\r\n    for (auto&&\
    \ [L, R]: segments) res += count(L, R, a, b, xor_val);\r\n    return res;\r\n\
    \  }\r\n\r\n  // xor \u3057\u305F\u7D50\u679C\u3067\u3001[L, R) \u306E\u4E2D\u3067\
    \ k>=0 \u756A\u76EE\u3068 prefix sum\r\n  pair<T, X> kth_value_and_sum(int L,\
    \ int R, int k, T xor_val = 0) {\r\n    if (xor_val != 0) assert(set_log);\r\n\
    \    assert(0 <= k && k <= R - L);\r\n    if (k == R - L) { return {infty<T>,\
    \ sum_all(L, R)}; }\r\n    int cnt = 0;\r\n    X sm = MX::unit();\r\n    T ret\
    \ = 0;\r\n    for (int d = lg - 1; d >= 0; --d) {\r\n      bool f = (xor_val >>\
    \ d) & 1;\r\n      int l0 = bv[d].rank(L, 0), r0 = bv[d].rank(R, 0);\r\n     \
    \ int c = (f ? (R - L) - (r0 - l0) : (r0 - l0));\r\n      if (cnt + c > k) {\r\
    \n        if (!f) L = l0, R = r0;\r\n        if (f) L += mid[d] - l0, R += mid[d]\
    \ - r0;\r\n      } else {\r\n        X s = (f ? get(d, L + mid[d] - l0, R + mid[d]\
    \ - r0) : get(d, l0, r0));\r\n        cnt += c, ret |= T(1) << d, sm = MX::op(sm,\
    \ s);\r\n        if (!f) L += mid[d] - l0, R += mid[d] - r0;\r\n        if (f)\
    \ L = l0, R = r0;\r\n      }\r\n    }\r\n    sm = MX::op(sm, get(0, L, L + k -\
    \ cnt));\r\n    if (COMPRESS) ret = key[ret];\r\n    return {ret, sm};\r\n  }\r\
    \n\r\n  // xor \u3057\u305F\u7D50\u679C\u3067\u3001[L, R) \u306E\u4E2D\u3067 k>=0\
    \ \u756A\u76EE\u3068 prefix sum\r\n  pair<T, X> kth_value_and_sum(vc<pair<int,\
    \ int>> segments, int k,\r\n                               T xor_val = 0) {\r\n\
    \    if (xor_val != 0) assert(set_log);\r\n    int total_len = 0;\r\n    for (auto&&\
    \ [L, R]: segments) total_len += R - L;\r\n    assert(0 <= k && k <= total_len);\r\
    \n    if (k == total_len) { return {infty<T>, sum_all(segments)}; }\r\n    int\
    \ cnt = 0;\r\n    X sm = MX::unit();\r\n    T ret = 0;\r\n    for (int d = lg\
    \ - 1; d >= 0; --d) {\r\n      bool f = (xor_val >> d) & 1;\r\n      int c = 0;\r\
    \n      for (auto&& [L, R]: segments) {\r\n        int l0 = bv[d].rank(L, 0),\
    \ r0 = bv[d].rank(R, 0);\r\n        c += (f ? (R - L) - (r0 - l0) : (r0 - l0));\r\
    \n      }\r\n      if (cnt + c > k) {\r\n        for (auto&& [L, R]: segments)\
    \ {\r\n          int l0 = bv[d].rank(L, 0), r0 = bv[d].rank(R, 0);\r\n       \
    \   if (!f) L = l0, R = r0;\r\n          if (f) L += mid[d] - l0, R += mid[d]\
    \ - r0;\r\n        }\r\n      } else {\r\n        cnt += c, ret |= T(1) << d;\r\
    \n        for (auto&& [L, R]: segments) {\r\n          int l0 = bv[d].rank(L,\
    \ 0), r0 = bv[d].rank(R, 0);\r\n          X s = (f ? get(d, L + mid[d] - l0, R\
    \ + mid[d] - r0) : get(d, l0, r0));\r\n          sm = MX::op(sm, s);\r\n     \
    \     if (!f) L += mid[d] - l0, R += mid[d] - r0;\r\n          if (f) L = l0,\
    \ R = r0;\r\n        }\r\n      }\r\n    }\r\n    for (auto&& [L, R]: segments)\
    \ {\r\n      int t = min(R - L, k - cnt);\r\n      sm = MX::op(sm, get(0, L, L\
    \ + t));\r\n      cnt += t;\r\n    }\r\n    if (COMPRESS) ret = key[ret];\r\n\
    \    return {ret, sm};\r\n  }\r\n\r\n  // xor \u3057\u305F\u7D50\u679C\u3067\u3001\
    [L, R) \u306E\u4E2D\u3067 k>=0 \u756A\u76EE\r\n  T kth(int L, int R, int k, T\
    \ xor_val = 0) {\r\n    if (xor_val != 0) assert(set_log);\r\n    assert(0 <=\
    \ k && k < R - L);\r\n    int cnt = 0;\r\n    T ret = 0;\r\n    for (int d = lg\
    \ - 1; d >= 0; --d) {\r\n      bool f = (xor_val >> d) & 1;\r\n      int l0 =\
    \ bv[d].rank(L, 0), r0 = bv[d].rank(R, 0);\r\n      int c = (f ? (R - L) - (r0\
    \ - l0) : (r0 - l0));\r\n      if (cnt + c > k) {\r\n        if (!f) L = l0, R\
    \ = r0;\r\n        if (f) L += mid[d] - l0, R += mid[d] - r0;\r\n      } else\
    \ {\r\n        cnt += c, ret |= T(1) << d;\r\n        if (!f) L += mid[d] - l0,\
    \ R += mid[d] - r0;\r\n        if (f) L = l0, R = r0;\r\n      }\r\n    }\r\n\
    \    if (COMPRESS) ret = key[ret];\r\n    return ret;\r\n  }\r\n\r\n  T kth(vc<pair<int,\
    \ int>> segments, int k, T xor_val = 0) {\r\n    int total_len = 0;\r\n    for\
    \ (auto&& [L, R]: segments) total_len += R - L;\r\n    assert(0 <= k && k < total_len);\r\
    \n    int cnt = 0;\r\n    T ret = 0;\r\n    for (int d = lg - 1; d >= 0; --d)\
    \ {\r\n      bool f = (xor_val >> d) & 1;\r\n      int c = 0;\r\n      for (auto&&\
    \ [L, R]: segments) {\r\n        int l0 = bv[d].rank(L, 0), r0 = bv[d].rank(R,\
    \ 0);\r\n        c += (f ? (R - L) - (r0 - l0) : (r0 - l0));\r\n      }\r\n  \
    \    if (cnt + c > k) {\r\n        for (auto&& [L, R]: segments) {\r\n       \
    \   int l0 = bv[d].rank(L, 0), r0 = bv[d].rank(R, 0);\r\n          if (!f) L =\
    \ l0, R = r0;\r\n          if (f) L += mid[d] - l0, R += mid[d] - r0;\r\n    \
    \    }\r\n      } else {\r\n        cnt += c, ret |= T(1) << d;\r\n        for\
    \ (auto&& [L, R]: segments) {\r\n          int l0 = bv[d].rank(L, 0), r0 = bv[d].rank(R,\
    \ 0);\r\n          if (!f) L += mid[d] - l0, R += mid[d] - r0;\r\n          if\
    \ (f) L = l0, R = r0;\r\n        }\r\n      }\r\n    }\r\n    if (COMPRESS) ret\
    \ = key[ret];\r\n    return ret;\r\n  }\r\n\r\n  // xor \u3057\u305F\u7D50\u679C\
    \u3067\u3001[L, R) \u306E\u4E2D\u3067\u4E2D\u592E\u5024\u3002\r\n  // LOWER =\
    \ true\uFF1A\u4E0B\u5074\u4E2D\u592E\u5024\u3001false\uFF1A\u4E0A\u5074\u4E2D\u592E\
    \u5024\r\n  T median(bool UPPER, int L, int R, T xor_val = 0) {\r\n    int n =\
    \ R - L;\r\n    int k = (UPPER ? n / 2 : (n - 1) / 2);\r\n    return kth(L, R,\
    \ k, xor_val);\r\n  }\r\n\r\n  T median(bool UPPER, vc<pair<int, int>> segments,\
    \ T xor_val = 0) {\r\n    int n = 0;\r\n    for (auto&& [L, R]: segments) n +=\
    \ R - L;\r\n    int k = (UPPER ? n / 2 : (n - 1) / 2);\r\n    return kth(segments,\
    \ k, xor_val);\r\n  }\r\n\r\n  // xor \u3057\u305F\u7D50\u679C\u3067 [k1, k2)\
    \ \u756A\u76EE\u3067\u3042\u308B\u3068\u3053\u308D\u306E SUM_data \u306E\u548C\
    \r\n  X sum(int L, int R, int k1, int k2, T xor_val = 0) {\r\n    return prefix_sum(L,\
    \ R, k2, xor_val) - prefix_sum(L, R, k1, xor_val);\r\n  }\r\n\r\n  X sum_all(int\
    \ L, int R) { return get(lg, L, R); }\r\n\r\n  X sum_all(vc<pair<int, int>> segments)\
    \ {\r\n    X sm = MX::unit();\r\n    for (auto&& [L, R]: segments) { sm = MX::op(sm,\
    \ get(lg, L, R)); }\r\n    return sm;\r\n  }\r\n\r\n  // check(cnt, prefix sum)\
    \ \u304C true \u3068\u306A\u308B\u3088\u3046\u306A\u6700\u5927\u306E (cnt, sum)\r\
    \n  template <typename F>\r\n  pair<int, X> max_right(F check, int L, int R, T\
    \ xor_val = 0) {\r\n    assert(check(0, MX::unit()));\r\n    if (xor_val != 0)\
    \ assert(set_log);\r\n    if (check(R - L, get(lg, L, R))) return {R - L, get(lg,\
    \ L, R)};\r\n    int cnt = 0;\r\n    X sm = MX::unit();\r\n    for (int d = lg\
    \ - 1; d >= 0; --d) {\r\n      bool f = (xor_val >> d) & 1;\r\n      int l0 =\
    \ bv[d].rank(L, 0), r0 = bv[d].rank(R, 0);\r\n      int c = (f ? (R - L) - (r0\
    \ - l0) : (r0 - l0));\r\n      X s = (f ? get(d, L + mid[d] - l0, R + mid[d] -\
    \ r0) : get(d, l0, r0));\r\n      if (check(cnt + c, MX::op(sm, s))) {\r\n   \
    \     cnt += c, sm = MX::op(sm, s);\r\n        if (f) L = l0, R = r0;\r\n    \
    \    if (!f) L += mid[d] - l0, R += mid[d] - r0;\r\n      } else {\r\n       \
    \ if (!f) L = l0, R = r0;\r\n        if (f) L += mid[d] - l0, R += mid[d] - r0;\r\
    \n      }\r\n    }\r\n    int k = binary_search(\r\n        [&](int k) -> bool\
    \ {\r\n          return check(cnt + k, MX::op(sm, get(0, L, L + k)));\r\n    \
    \    },\r\n        0, R - L);\r\n    cnt += k;\r\n    sm = MX::op(sm, get(0, L,\
    \ L + k));\r\n    return {cnt, sm};\r\n  }\r\n\r\nprivate:\r\n  inline X get(int\
    \ d, int L, int R) {\r\n    return MX::op(MX::inverse(cumsum[d][L]), cumsum[d][R]);\r\
    \n  }\r\n\r\n  // xor \u3057\u305F\u7D50\u679C\u3067 [0, x) \u306B\u53CE\u307E\
    \u308B\u3082\u306E\u3092\u6570\u3048\u308B\r\n  int prefix_count(int L, int R,\
    \ T x, T xor_val = 0) {\r\n    if (xor_val != 0) assert(set_log);\r\n    x = (COMPRESS\
    \ ? LB(key, x) : x);\r\n    if (x == 0) return 0;\r\n    if (x >= (1 << lg)) return\
    \ R - L;\r\n    int cnt = 0;\r\n    FOR_R(d, lg) {\r\n      bool add = (x >> d)\
    \ & 1;\r\n      bool f = ((xor_val) >> d) & 1;\r\n      int l0 = bv[d].rank(L,\
    \ 0), r0 = bv[d].rank(R, 0);\r\n      int kf = (f ? (R - L) - (r0 - l0) : (r0\
    \ - l0));\r\n      if (add) {\r\n        cnt += kf;\r\n        if (f) { L = l0,\
    \ R = r0; }\r\n        if (!f) { L += mid[d] - l0, R += mid[d] - r0; }\r\n   \
    \   } else {\r\n        if (!f) L = l0, R = r0;\r\n        if (f) L += mid[d]\
    \ - l0, R += mid[d] - r0;\r\n      }\r\n    }\r\n    return cnt;\r\n  }\r\n\r\n\
    \  // xor \u3057\u305F\u7D50\u679C\u3067 [0, k) \u756A\u76EE\u306E\u3082\u306E\
    \u306E\u548C\r\n  X prefix_sum(int L, int R, int k, T xor_val = 0) {\r\n    return\
    \ kth_value_and_sum(L, R, k, xor_val).se;\r\n  }\r\n\r\n  // xor \u3057\u305F\u7D50\
    \u679C\u3067 [0, k) \u756A\u76EE\u306E\u3082\u306E\u306E\u548C\r\n  X prefix_sum(vc<pair<int,\
    \ int>> segments, int k, T xor_val = 0) {\r\n    return kth_value_and_sum(segments,\
    \ k, xor_val).se;\r\n  }\r\n};\n#line 1 \"graph/tree.hpp\"\n// HLD euler tour\
    \ \u3092\u3068\u3063\u3066\u3044\u308D\u3044\u308D\u3002\r\n// \u6728\u4EE5\u5916\
    \u3001\u975E\u9023\u7D50\u3067\u3082 dfs \u9806\u5E8F\u3084\u89AA\u304C\u3068\u308C\
    \u308B\u3002\r\ntemplate <typename GT>\r\nstruct Tree {\r\n  using Graph_type\
    \ = GT;\r\n  GT *G_ptr;\r\n  using WT = typename GT::cost_type;\r\n  int N;\r\n\
    \  vector<int> LID, RID, head, V, parent, VtoE;\r\n  vc<int> depth;\r\n  vc<WT>\
    \ depth_weighted;\r\n\r\n  Tree() {}\r\n  Tree(GT &G, int r = 0, bool hld = 1)\
    \ { build(G, r, hld); }\r\n\r\n  void build(GT &G, int r = 0, bool hld = 1) {\r\
    \n    G_ptr = &G;\r\n    N = G.N;\r\n    LID.assign(N, -1), RID.assign(N, -1),\
    \ head.assign(N, r);\r\n    V.assign(N, -1), parent.assign(N, -1), VtoE.assign(N,\
    \ -1);\r\n    depth.assign(N, -1), depth_weighted.assign(N, 0);\r\n    assert(G.is_prepared());\r\
    \n    int t1 = 0;\r\n    dfs_sz(r, -1, hld);\r\n    dfs_hld(r, t1);\r\n  }\r\n\
    \r\n  void dfs_sz(int v, int p, bool hld) {\r\n    auto &sz = RID;\r\n    parent[v]\
    \ = p;\r\n    depth[v] = (p == -1 ? 0 : depth[p] + 1);\r\n    sz[v] = 1;\r\n \
    \   int l = G_ptr->indptr[v], r = G_ptr->indptr[v + 1];\r\n    auto &csr = G_ptr->csr_edges;\r\
    \n    // \u4F7F\u3046\u8FBA\u304C\u3042\u308C\u3070\u5148\u982D\u306B\u3059\u308B\
    \r\n    for (int i = r - 2; i >= l; --i) {\r\n      if (hld && depth[csr[i + 1].to]\
    \ == -1) swap(csr[i], csr[i + 1]);\r\n    }\r\n    int hld_sz = 0;\r\n    for\
    \ (int i = l; i < r; ++i) {\r\n      auto e = csr[i];\r\n      if (depth[e.to]\
    \ != -1) continue;\r\n      depth_weighted[e.to] = depth_weighted[v] + e.cost;\r\
    \n      VtoE[e.to] = e.id;\r\n      dfs_sz(e.to, v, hld);\r\n      sz[v] += sz[e.to];\r\
    \n      if (hld && chmax(hld_sz, sz[e.to]) && l < i) { swap(csr[l], csr[i]); }\r\
    \n    }\r\n  }\r\n\r\n  void dfs_hld(int v, int &times) {\r\n    LID[v] = times++;\r\
    \n    RID[v] += LID[v];\r\n    V[LID[v]] = v;\r\n    bool heavy = true;\r\n  \
    \  for (auto &&e: (*G_ptr)[v]) {\r\n      if (depth[e.to] <= depth[v]) continue;\r\
    \n      head[e.to] = (heavy ? head[v] : e.to);\r\n      heavy = false;\r\n   \
    \   dfs_hld(e.to, times);\r\n    }\r\n  }\r\n\r\n  vc<int> heavy_path_at(int v)\
    \ {\r\n    vc<int> P = {v};\r\n    while (1) {\r\n      int a = P.back();\r\n\
    \      for (auto &&e: (*G_ptr)[a]) {\r\n        if (e.to != parent[a] && head[e.to]\
    \ == v) {\r\n          P.eb(e.to);\r\n          break;\r\n        }\r\n      }\r\
    \n      if (P.back() == a) break;\r\n    }\r\n    return P;\r\n  }\r\n\r\n  int\
    \ e_to_v(int eid) {\r\n    auto e = (*G_ptr).edges[eid];\r\n    return (parent[e.frm]\
    \ == e.to ? e.frm : e.to);\r\n  }\r\n  int v_to_e(int v) { return VtoE[v]; }\r\
    \n\r\n  int ELID(int v) { return 2 * LID[v] - depth[v]; }\r\n  int ERID(int v)\
    \ { return 2 * RID[v] - depth[v] - 1; }\r\n\r\n  /* k: 0-indexed */\r\n  int LA(int\
    \ v, int k) {\r\n    assert(k <= depth[v]);\r\n    while (1) {\r\n      int u\
    \ = head[v];\r\n      if (LID[v] - k >= LID[u]) return V[LID[v] - k];\r\n    \
    \  k -= LID[v] - LID[u] + 1;\r\n      v = parent[u];\r\n    }\r\n  }\r\n\r\n \
    \ int LCA(int u, int v) {\r\n    for (;; v = parent[head[v]]) {\r\n      if (LID[u]\
    \ > LID[v]) swap(u, v);\r\n      if (head[u] == head[v]) return u;\r\n    }\r\n\
    \  }\r\n\r\n  int lca(int u, int v) { return LCA(u, v); }\r\n  int la(int u, int\
    \ v) { return LA(u, v); }\r\n\r\n  int subtree_size(int v) { return RID[v] - LID[v];\
    \ }\r\n\r\n  int dist(int a, int b) {\r\n    int c = LCA(a, b);\r\n    return\
    \ depth[a] + depth[b] - 2 * depth[c];\r\n  }\r\n\r\n  WT dist(int a, int b, bool\
    \ weighted) {\r\n    assert(weighted);\r\n    int c = LCA(a, b);\r\n    return\
    \ depth_weighted[a] + depth_weighted[b] - WT(2) * depth_weighted[c];\r\n  }\r\n\
    \r\n  // a is in b\r\n  bool in_subtree(int a, int b) { return LID[b] <= LID[a]\
    \ && LID[a] < RID[b]; }\r\n\r\n  int jump(int a, int b, ll k) {\r\n    if (k ==\
    \ 1) {\r\n      if (a == b) return -1;\r\n      return (in_subtree(b, a) ? LA(b,\
    \ depth[b] - depth[a] - 1) : parent[a]);\r\n    }\r\n    int c = LCA(a, b);\r\n\
    \    int d_ac = depth[a] - depth[c];\r\n    int d_bc = depth[b] - depth[c];\r\n\
    \    if (k > d_ac + d_bc) return -1;\r\n    if (k <= d_ac) return LA(a, k);\r\n\
    \    return LA(b, d_ac + d_bc - k);\r\n  }\r\n\r\n  vc<int> collect_child(int\
    \ v) {\r\n    vc<int> res;\r\n    for (auto &&e: (*G_ptr)[v])\r\n      if (e.to\
    \ != parent[v]) res.eb(e.to);\r\n    return res;\r\n  }\r\n\r\n  vc<pair<int,\
    \ int>> get_path_decomposition(int u, int v, bool edge) {\r\n    // [\u59CB\u70B9\
    , \u7D42\u70B9] \u306E\"\u9589\"\u533A\u9593\u5217\u3002\r\n    vc<pair<int, int>>\
    \ up, down;\r\n    while (1) {\r\n      if (head[u] == head[v]) break;\r\n   \
    \   if (LID[u] < LID[v]) {\r\n        down.eb(LID[head[v]], LID[v]);\r\n     \
    \   v = parent[head[v]];\r\n      } else {\r\n        up.eb(LID[u], LID[head[u]]);\r\
    \n        u = parent[head[u]];\r\n      }\r\n    }\r\n    if (LID[u] < LID[v])\
    \ down.eb(LID[u] + edge, LID[v]);\r\n    elif (LID[v] + edge <= LID[u]) up.eb(LID[u],\
    \ LID[v] + edge);\r\n    reverse(all(down));\r\n    up.insert(up.end(), all(down));\r\
    \n    return up;\r\n  }\r\n\r\n  vc<int> restore_path(int u, int v) {\r\n    vc<int>\
    \ P;\r\n    for (auto &&[a, b]: get_path_decomposition(u, v, 0)) {\r\n      if\
    \ (a <= b) {\r\n        FOR(i, a, b + 1) P.eb(V[i]);\r\n      } else {\r\n   \
    \     FOR_R(i, b, a + 1) P.eb(V[i]);\r\n      }\r\n    }\r\n    return P;\r\n\
    \  }\r\n};\r\n#line 4 \"graph/ds/tree_wavelet_matrix.hpp\"\n\n// https://atcoder.jp/contests/pakencamp-2022-day1/tasks/pakencamp_2022_day1_j\n\
    // https://atcoder.jp/contests/utpc2011/tasks/utpc2011_12\ntemplate <typename\
    \ TREE, bool edge, typename T, bool COMPRESS,\n          typename Monoid = Monoid_Add<T>>\n\
    struct Tree_Wavelet_Matrix {\n  TREE& tree;\n  int N;\n  using WM = Wavelet_Matrix<T,\
    \ COMPRESS, Monoid_Add<T>>;\n  using X = typename Monoid::value_type;\n  WM wm;\n\
    \n  Tree_Wavelet_Matrix(TREE& tree, vc<T> A, vc<X> SUM_data = {}, int log = -1)\n\
    \      : tree(tree), N(tree.N) {\n    vc<X>& S = SUM_data;\n    vc<T> A1;\n  \
    \  vc<X> S1;\n    A1.resize(N);\n    if (!S.empty()) S1.resize(N);\n    if (!edge)\
    \ {\n      assert(len(A) == N && (len(S) == 0 || len(S) == N));\n      FOR(v,\
    \ N) A1[tree.LID[v]] = A[v];\n      if (len(S) == N) { FOR(v, N) S1[tree.LID[v]]\
    \ = S[v]; }\n      wm.build(A1, S1, log);\n    } else {\n      assert(len(A) ==\
    \ N - 1 && (len(S) == 0 || len(S) == N - 1));\n      if (!S.empty()) {\n     \
    \   FOR(e, N - 1) { S1[tree.LID[tree.e_to_v(e)]] = S[e]; }\n      }\n      FOR(e,\
    \ N - 1) { A1[tree.LID[tree.e_to_v(e)]] = A[e]; }\n      wm.build(A1, S1, log);\n\
    \    }\n  }\n\n  // xor \u3057\u305F\u7D50\u679C\u3067 [a, b) \u306B\u53CE\u307E\
    \u308B\u3082\u306E\u3092\u6570\u3048\u308B\n  int count_path(int s, int t, T a,\
    \ T b, T xor_val = 0) {\n    return wm.count(get_segments(s, t), a, b, xor_val);\n\
    \  }\n\n  // xor \u3057\u305F\u7D50\u679C\u3067 [a, b) \u306B\u53CE\u307E\u308B\
    \u3082\u306E\u3092\u6570\u3048\u308B\n  int count_subtree(int u, T a, T b, T xor_val\
    \ = 0) {\n    int l = tree.LID[u], r = tree.RID[u];\n    return wm.count(l + edge,\
    \ r, a, b, xor_val);\n  }\n\n  // xor \u3057\u305F\u7D50\u679C\u3067\u3001[L,\
    \ R) \u306E\u4E2D\u3067 k>=0 \u756A\u76EE\u3068 prefix sum\n  pair<T, X> kth_value_and_sum_path(int\
    \ s, int t, int k, T xor_val = 0) {\n    return wm.kth_value_and_sum(get_segments(s,\
    \ t), k, xor_val);\n  }\n\n  // xor \u3057\u305F\u7D50\u679C\u3067\u3001[L, R)\
    \ \u306E\u4E2D\u3067 k>=0 \u756A\u76EE\u3068 prefix sum\n  pair<T, X> kth_value_and_sum_subtree(int\
    \ u, int k, T xor_val = 0) {\n    int l = tree.LID[u], r = tree.RID[u];\n    return\
    \ wm.kth_value_and_sum(l + edge, r, k, xor_val);\n  }\n\n  // xor \u3057\u305F\
    \u7D50\u679C\u3067\u3001[L, R) \u306E\u4E2D\u3067 k>=0 \u756A\u76EE\n  T kth_path(int\
    \ s, int t, int k, T xor_val = 0) {\n    return wm.kth(get_segments(s, t), k,\
    \ xor_val);\n  }\n\n  // xor \u3057\u305F\u7D50\u679C\u3067\u3001[L, R) \u306E\
    \u4E2D\u3067 k>=0 \u756A\u76EE\n  T kth_subtree(int u, int k, T xor_val = 0) {\n\
    \    int l = tree.LID[u], r = tree.RID[u];\n    return wm.kth(l + edge, r, k,\
    \ xor_val);\n  }\n\n  // xor \u3057\u305F\u7D50\u679C\u3067\u3001[L, R) \u306E\
    \u4E2D\u3067\u4E2D\u592E\u5024\u3002\n  // LOWER = true\uFF1A\u4E0B\u5074\u4E2D\
    \u592E\u5024\u3001false\uFF1A\u4E0A\u5074\u4E2D\u592E\u5024\n  T median_path(bool\
    \ UPPER, int s, int t, T xor_val = 0) {\n    return wm.median(UPPER, get_segments(s,\
    \ t), xor_val);\n  }\n\n  T median_subtree(bool UPPER, int u, T xor_val = 0) {\n\
    \    int l = tree.LID[u], r = tree.RID[u];\n    return wm.median(UPPER, l + edge,\
    \ r, xor_val);\n  }\n\n  // xor \u3057\u305F\u7D50\u679C\u3067 [k1, k2) \u756A\
    \u76EE\u3067\u3042\u308B\u3068\u3053\u308D\u306E SUM_data \u306E\u548C\n  X sum_path(int\
    \ s, int t, int k1, int k2, T xor_val = 0) {\n    return wm.sum(get_segments(s,\
    \ t), k1, k2, xor_val);\n  }\n\n  // xor \u3057\u305F\u7D50\u679C\u3067 [k1, k2)\
    \ \u756A\u76EE\u3067\u3042\u308B\u3068\u3053\u308D\u306E SUM_data \u306E\u548C\
    \n  X sum_subtree(int u, int k1, int k2, T xor_val = 0) {\n    int l = tree.LID[u],\
    \ r = tree.RID[u];\n    return wm.sum(l + edge, r, k1, k2, xor_val);\n  }\n\n\
    \  X sum_all_path(int s, int t) { return wm.sum_all(get_segments(s, t)); }\n\n\
    \  X sum_all_subtree(int u) {\n    int l = tree.LID[u], r = tree.RID[u];\n   \
    \ return wm.sum_all(l + edge, r);\n  }\n\nprivate:\n  vc<pair<int, int>> get_segments(int\
    \ s, int t) {\n    vc<pair<int, int>> segments = tree.get_path_decomposition(s,\
    \ t, edge);\n    for (auto&& [a, b]: segments) {\n      if (a >= b) swap(a, b);\n\
    \      ++b;\n    }\n    return segments;\n  }\n};\n"
  code: "\n#include \"ds/wavelet_matrix.hpp\"\n#include \"graph/tree.hpp\"\n\n// https://atcoder.jp/contests/pakencamp-2022-day1/tasks/pakencamp_2022_day1_j\n\
    // https://atcoder.jp/contests/utpc2011/tasks/utpc2011_12\ntemplate <typename\
    \ TREE, bool edge, typename T, bool COMPRESS,\n          typename Monoid = Monoid_Add<T>>\n\
    struct Tree_Wavelet_Matrix {\n  TREE& tree;\n  int N;\n  using WM = Wavelet_Matrix<T,\
    \ COMPRESS, Monoid_Add<T>>;\n  using X = typename Monoid::value_type;\n  WM wm;\n\
    \n  Tree_Wavelet_Matrix(TREE& tree, vc<T> A, vc<X> SUM_data = {}, int log = -1)\n\
    \      : tree(tree), N(tree.N) {\n    vc<X>& S = SUM_data;\n    vc<T> A1;\n  \
    \  vc<X> S1;\n    A1.resize(N);\n    if (!S.empty()) S1.resize(N);\n    if (!edge)\
    \ {\n      assert(len(A) == N && (len(S) == 0 || len(S) == N));\n      FOR(v,\
    \ N) A1[tree.LID[v]] = A[v];\n      if (len(S) == N) { FOR(v, N) S1[tree.LID[v]]\
    \ = S[v]; }\n      wm.build(A1, S1, log);\n    } else {\n      assert(len(A) ==\
    \ N - 1 && (len(S) == 0 || len(S) == N - 1));\n      if (!S.empty()) {\n     \
    \   FOR(e, N - 1) { S1[tree.LID[tree.e_to_v(e)]] = S[e]; }\n      }\n      FOR(e,\
    \ N - 1) { A1[tree.LID[tree.e_to_v(e)]] = A[e]; }\n      wm.build(A1, S1, log);\n\
    \    }\n  }\n\n  // xor \u3057\u305F\u7D50\u679C\u3067 [a, b) \u306B\u53CE\u307E\
    \u308B\u3082\u306E\u3092\u6570\u3048\u308B\n  int count_path(int s, int t, T a,\
    \ T b, T xor_val = 0) {\n    return wm.count(get_segments(s, t), a, b, xor_val);\n\
    \  }\n\n  // xor \u3057\u305F\u7D50\u679C\u3067 [a, b) \u306B\u53CE\u307E\u308B\
    \u3082\u306E\u3092\u6570\u3048\u308B\n  int count_subtree(int u, T a, T b, T xor_val\
    \ = 0) {\n    int l = tree.LID[u], r = tree.RID[u];\n    return wm.count(l + edge,\
    \ r, a, b, xor_val);\n  }\n\n  // xor \u3057\u305F\u7D50\u679C\u3067\u3001[L,\
    \ R) \u306E\u4E2D\u3067 k>=0 \u756A\u76EE\u3068 prefix sum\n  pair<T, X> kth_value_and_sum_path(int\
    \ s, int t, int k, T xor_val = 0) {\n    return wm.kth_value_and_sum(get_segments(s,\
    \ t), k, xor_val);\n  }\n\n  // xor \u3057\u305F\u7D50\u679C\u3067\u3001[L, R)\
    \ \u306E\u4E2D\u3067 k>=0 \u756A\u76EE\u3068 prefix sum\n  pair<T, X> kth_value_and_sum_subtree(int\
    \ u, int k, T xor_val = 0) {\n    int l = tree.LID[u], r = tree.RID[u];\n    return\
    \ wm.kth_value_and_sum(l + edge, r, k, xor_val);\n  }\n\n  // xor \u3057\u305F\
    \u7D50\u679C\u3067\u3001[L, R) \u306E\u4E2D\u3067 k>=0 \u756A\u76EE\n  T kth_path(int\
    \ s, int t, int k, T xor_val = 0) {\n    return wm.kth(get_segments(s, t), k,\
    \ xor_val);\n  }\n\n  // xor \u3057\u305F\u7D50\u679C\u3067\u3001[L, R) \u306E\
    \u4E2D\u3067 k>=0 \u756A\u76EE\n  T kth_subtree(int u, int k, T xor_val = 0) {\n\
    \    int l = tree.LID[u], r = tree.RID[u];\n    return wm.kth(l + edge, r, k,\
    \ xor_val);\n  }\n\n  // xor \u3057\u305F\u7D50\u679C\u3067\u3001[L, R) \u306E\
    \u4E2D\u3067\u4E2D\u592E\u5024\u3002\n  // LOWER = true\uFF1A\u4E0B\u5074\u4E2D\
    \u592E\u5024\u3001false\uFF1A\u4E0A\u5074\u4E2D\u592E\u5024\n  T median_path(bool\
    \ UPPER, int s, int t, T xor_val = 0) {\n    return wm.median(UPPER, get_segments(s,\
    \ t), xor_val);\n  }\n\n  T median_subtree(bool UPPER, int u, T xor_val = 0) {\n\
    \    int l = tree.LID[u], r = tree.RID[u];\n    return wm.median(UPPER, l + edge,\
    \ r, xor_val);\n  }\n\n  // xor \u3057\u305F\u7D50\u679C\u3067 [k1, k2) \u756A\
    \u76EE\u3067\u3042\u308B\u3068\u3053\u308D\u306E SUM_data \u306E\u548C\n  X sum_path(int\
    \ s, int t, int k1, int k2, T xor_val = 0) {\n    return wm.sum(get_segments(s,\
    \ t), k1, k2, xor_val);\n  }\n\n  // xor \u3057\u305F\u7D50\u679C\u3067 [k1, k2)\
    \ \u756A\u76EE\u3067\u3042\u308B\u3068\u3053\u308D\u306E SUM_data \u306E\u548C\
    \n  X sum_subtree(int u, int k1, int k2, T xor_val = 0) {\n    int l = tree.LID[u],\
    \ r = tree.RID[u];\n    return wm.sum(l + edge, r, k1, k2, xor_val);\n  }\n\n\
    \  X sum_all_path(int s, int t) { return wm.sum_all(get_segments(s, t)); }\n\n\
    \  X sum_all_subtree(int u) {\n    int l = tree.LID[u], r = tree.RID[u];\n   \
    \ return wm.sum_all(l + edge, r);\n  }\n\nprivate:\n  vc<pair<int, int>> get_segments(int\
    \ s, int t) {\n    vc<pair<int, int>> segments = tree.get_path_decomposition(s,\
    \ t, edge);\n    for (auto&& [a, b]: segments) {\n      if (a >= b) swap(a, b);\n\
    \      ++b;\n    }\n    return segments;\n  }\n};"
  dependsOn:
  - ds/wavelet_matrix.hpp
  - ds/bit_vector.hpp
  - alg/monoid/add.hpp
  - graph/tree.hpp
  isVerificationFile: false
  path: graph/ds/tree_wavelet_matrix.hpp
  requiredBy: []
  timestamp: '2023-04-09 03:51:17+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: graph/ds/tree_wavelet_matrix.hpp
layout: document
redirect_from:
- /library/graph/ds/tree_wavelet_matrix.hpp
- /library/graph/ds/tree_wavelet_matrix.hpp.html
title: graph/ds/tree_wavelet_matrix.hpp
---
