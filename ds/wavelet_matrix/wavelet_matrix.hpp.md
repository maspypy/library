---
data:
  _extendedDependsOn:
  - icon: ':question:'
    path: alg/monoid/dummy.hpp
    title: alg/monoid/dummy.hpp
  - icon: ':question:'
    path: ds/bit_vector.hpp
    title: ds/bit_vector.hpp
  - icon: ':question:'
    path: ds/dummy_data_structure.hpp
    title: ds/dummy_data_structure.hpp
  _extendedRequiredBy:
  - icon: ':question:'
    path: ds/wavelet_matrix/wavelet_matrix_2d_range.hpp
    title: ds/wavelet_matrix/wavelet_matrix_2d_range.hpp
  - icon: ':warning:'
    path: graph/ds/tree_wavelet_matrix.hpp
    title: graph/ds/tree_wavelet_matrix.hpp
  - icon: ':heavy_check_mark:'
    path: string/prefix_substring_LCS.hpp
    title: string/prefix_substring_LCS.hpp
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/2_library_checker/data_structure/point_add_rectangle_sum_wm_abel.test.cpp
    title: test/2_library_checker/data_structure/point_add_rectangle_sum_wm_abel.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/2_library_checker/data_structure/point_add_rectangle_sum_wm_mono.test.cpp
    title: test/2_library_checker/data_structure/point_add_rectangle_sum_wm_mono.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/2_library_checker/data_structure/range_kth_smallest_wavelet.test.cpp
    title: test/2_library_checker/data_structure/range_kth_smallest_wavelet.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/2_library_checker/data_structure/rectangle_sum_wm.test.cpp
    title: test/2_library_checker/data_structure/rectangle_sum_wm.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/2_library_checker/data_structure/rectangle_sum_wm_abel.test.cpp
    title: test/2_library_checker/data_structure/rectangle_sum_wm_abel.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/2_library_checker/string/prefix_substring_lcs.test.cpp
    title: test/2_library_checker/string/prefix_substring_lcs.test.cpp
  - icon: ':x:'
    path: test/3_yukicoder/1332.test.cpp
    title: test/3_yukicoder/1332.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/3_yukicoder/1600_2.test.cpp
    title: test/3_yukicoder/1600_2.test.cpp
  - icon: ':x:'
    path: test/3_yukicoder/1625_2.test.cpp
    title: test/3_yukicoder/1625_2.test.cpp
  - icon: ':x:'
    path: test/3_yukicoder/1919_2.test.cpp
    title: test/3_yukicoder/1919_2.test.cpp
  - icon: ':x:'
    path: test/3_yukicoder/2065.test.cpp
    title: test/3_yukicoder/2065.test.cpp
  - icon: ':x:'
    path: test/3_yukicoder/2859.test.cpp
    title: test/3_yukicoder/2859.test.cpp
  - icon: ':x:'
    path: test/3_yukicoder/919.test.cpp
    title: test/3_yukicoder/919.test.cpp
  - icon: ':x:'
    path: test/3_yukicoder/924.test.cpp
    title: test/3_yukicoder/924.test.cpp
  _isVerificationFailed: true
  _pathExtension: hpp
  _verificationStatusIcon: ':question:'
  attributes:
    links:
    - https://github.com/maspypy/library/blob/main/ds/wavelet_matrix/wavelet_matrix.hpp
    - https://qoj.ac/contest/1047/problem/5094
  bundledCode: "#line 1 \"ds/wavelet_matrix/wavelet_matrix.hpp\"\n// Source: https://github.com/maspypy/library/blob/main/ds/wavelet_matrix/wavelet_matrix.hpp\n\
    #line 1 \"ds/bit_vector.hpp\"\n// Source: https://github.com/maspypy/library/blob/main/ds/bit_vector.hpp\n\
    \nstruct Bit_Vector {\n  int n;\n  bool prepared = 0;\n  vc<pair<u64, u32>> dat;\n\
    \  Bit_Vector(int n = 0) : n(n) { dat.assign((n + 127) >> 6, {0, 0}); }\n  void\
    \ set(int i) {\n    assert(!prepared && (0 <= i && i < n));\n    dat[i >> 6].fi\
    \ |= u64(1) << (i & 63);\n  }\n  void reset() {\n    fill(all(dat), pair<u64,\
    \ u32>{0, 0});\n    prepared = 0;\n  }\n  void build() {\n    prepared = 1;\n\
    \    FOR(i, len(dat) - 1) dat[i + 1].se = dat[i].se + popcnt(dat[i].fi);\n  }\n\
    \  bool operator[](int i) const { return dat[i >> 6].fi >> (i & 63) & 1; }\n \
    \ // [0, k) \u5185\u306E 1 \u306E\u500B\u6570\n  int count_prefix(int k, bool\
    \ f = true) const {\n    assert(prepared);\n    auto [a, b] = dat[k >> 6];\n \
    \   int ret = b + popcnt(a & ((u64(1) << (k & 63)) - 1));\n    return (f ? ret\
    \ : k - ret);\n  }\n  int count(int L, int R, bool f = true) const {\n    return\
    \ count_prefix(R, f) - count_prefix(L, f);\n  }\n  string to_string() const {\n\
    \    string ans;\n    FOR(i, n) ans += '0' + (dat[i / 64].fi >> (i % 64) & 1);\n\
    \    return ans;\n  }\n};\n#line 1 \"ds/dummy_data_structure.hpp\"\n// Source:\
    \ https://github.com/maspypy/library/blob/main/ds/dummy_data_structure.hpp\n#line\
    \ 1 \"alg/monoid/dummy.hpp\"\n// Source: https://github.com/maspypy/library/blob/main/alg/monoid/dummy.hpp\n\
    struct Monoid_Dummy {\n  using value_type = char;\n  static constexpr bool commute\
    \ = true;\n  static value_type op(value_type, value_type) { return 0; }\n  static\
    \ value_type id() { return 0; }\n};\n#line 3 \"ds/dummy_data_structure.hpp\"\n\
    \nstruct Dummy_Data_Structure {\n  using MX = Monoid_Dummy;\n  using T = typename\
    \ MX::value_type;\n  void build(const vc<T>& A) {}\n};\n#line 4 \"ds/wavelet_matrix/wavelet_matrix.hpp\"\
    \n\ntemplate <typename Y, typename SEGTREE>\nstruct Uncompressed_Wavelet_Matrix\
    \ {\n  using Mono = typename SEGTREE::MX;\n  using T = typename Mono::value_type;\n\
    \  static_assert(Mono::commute);\n  static_assert(is_same_v<Y, int> || is_same_v<Y,\
    \ ll>);\n  int n = 0, log = 0;\n  vc<int> mid;\n  vc<Bit_Vector> bv;\n  vc<SEGTREE>\
    \ seg;\n  Y limit;\n\n  Uncompressed_Wavelet_Matrix() = default;\n\n  // f(i)\
    \ = {A[i], dat[i]}\n  template <typename F>\n  Uncompressed_Wavelet_Matrix(int\
    \ n, F f, int log = -1) {\n    build(n, f, log);\n  }\n  Uncompressed_Wavelet_Matrix(const\
    \ vc<Y>& A, int log = -1) {\n    static_assert(is_same_v<SEGTREE, Dummy_Data_Structure>);\n\
    \    build(len(A), [&](int i) -> pair<Y, T> { return {A[i], Mono::id()}; }, log);\n\
    \  }\n\n  template <typename F>\n  void build(int n, F f, int log = -1) {\n  \
    \  this->n = n;\n    vc<Y> A(n);\n    vc<T> S(n);\n    FOR(i, n) tie(A[i], S[i])\
    \ = f(i);\n    if (log == -1) {\n      log = (n == 0 ? 0 : topbit(MAX(A)) + 1);\n\
    \    } else {\n      for (auto& x : A) assert(0 <= x && topbit(x) < log);\n  \
    \  }\n    this->log = log;\n    limit = Y(1) << log;\n    if constexpr (is_same_v<Y,\
    \ int>) assert(0 <= log && log <= 30);\n    if constexpr (is_same_v<Y, ll>) assert(0\
    \ <= log && log <= 62);\n    mid.resize(log), bv.assign(log, Bit_Vector(n));\n\
    \    vc<Y> A0(n), A1(n);\n    vc<T> S0(n), S1(n);\n    seg.resize(log + 1);\n\
    \    seg[log].build(S);\n    for (int d = log - 1; d >= 0; --d) {\n      int p0\
    \ = 0, p1 = 0;\n      for (int i = 0; i < n; ++i) {\n        if (A[i] >> d & 1)\
    \ {\n          bv[d].set(i), A1[p1] = A[i], S1[p1] = S[i], p1++;\n        } else\
    \ {\n          A0[p0] = A[i], S0[p0] = S[i], p0++;\n        }\n      }\n     \
    \ swap(A, A0), swap(S, S0);\n      move(A1.begin(), A1.begin() + p1, A.begin()\
    \ + p0);\n      move(S1.begin(), S1.begin() + p1, S.begin() + p0);\n      mid[d]\
    \ = p0, bv[d].build(), seg[d].build(S);\n    }\n  }\n\n  tuple<int, int, int,\
    \ int> get_subtree(int d, int L, int R) const {\n    assert(1 <= d && d <= log);\n\
    \    int a = bv[d - 1].count_prefix(L), b = bv[d - 1].count_prefix(R);\n    return\
    \ {L - a, R - b, mid[d - 1] + a, mid[d - 1] + b};\n  }\n\n  template <typename\
    \ F>\n  void work_point(F f, int i) {\n    assert(0 <= i && i < n);\n    f(log,\
    \ i);\n    FOR_R(d, log) {\n      int a = bv[d].count_prefix(i);\n      if (bv[d][i])\
    \ {\n        i = mid[d] + a;\n      } else {\n        i = i - a;\n      }\n  \
    \    f(d, i);\n    }\n  }\n\n  template <typename F>\n  void work_prefix(F f,\
    \ int L, int R, Y y) const {\n    chmin(y, limit);\n    if (y == 0) return;\n\
    \    if (y == limit) {\n      f(log, L, R);\n      return;\n    }\n    FOR_R(d,\
    \ log) {\n      auto [L0, R0, L1, R1] = get_subtree(d + 1, L, R);\n      if (y\
    \ >> d & 1) {\n        f(d, L0, R0);\n        L = L1, R = R1;\n      } else {\n\
    \        L = L0, R = R0;\n      }\n    }\n  }\n\n  template <typename F>\n  void\
    \ work_range(F f, int L, int R, Y y1, Y y2) const {\n    chmin(y2, limit);\n \
    \   if (y1 >= y2) return;\n    assert(0 <= y1 && y1 <= y2 && y2 <= limit);\n \
    \   if (y1 == 0) return work_prefix(f, L, R, y2);\n    auto dfs = [&](auto& dfs,\
    \ int d, int L, int R, Y y1, Y y2) -> void {\n      if (y1 == y2) return;\n  \
    \    if (y1 == 0 && y2 == Y(1) << d) {\n        f(d, L, R);\n        return;\n\
    \      }\n      assert(d > 0);\n      auto [L0, R0, L1, R1] = get_subtree(d, L,\
    \ R);\n      Y m = (Y(1) << (d - 1));\n\n      if (y2 <= m) {\n        dfs(dfs,\
    \ d - 1, L0, R0, y1, y2);\n      } else if (y1 >= m) {\n        dfs(dfs, d - 1,\
    \ L1, R1, y1 - m, y2 - m);\n      } else {\n        dfs(dfs, d - 1, L0, R0, y1,\
    \ m);\n        dfs(dfs, d - 1, L1, R1, 0, y2 - m);\n      }\n    };\n    dfs(dfs,\
    \ log, L, R, y1, y2);\n  }\n\n  // [L,R) x [0,y)\n  int prefix_count(int L, int\
    \ R, Y y) const {\n    int cnt = 0;\n    work_prefix([&](int d, int a, int b)\
    \ { cnt += b - a; }, L, R, y);\n    return cnt;\n  }\n\n  // [L,R) x [y1,y2)\n\
    \  int count(int L, int R, Y y1, Y y2) const {\n    return prefix_count(L, R,\
    \ y2) - prefix_count(L, R, y1);\n  }\n\n  // [L,R) x [0,y)\n  T prefix_prod(int\
    \ L, int R, Y y) const {\n    T ans = Mono::id();\n    work_prefix(\n        [&](int\
    \ d, int a, int b) { ans = Mono::op(ans, seg[d].prod(a, b)); }, L,\n        R,\
    \ y);\n    return ans;\n  }\n  // [L,R) x [y1,y2)\n  T prod(int L, int R, Y y1,\
    \ Y y2) const {\n    T ans = Mono::id();\n    work_range(\n        [&](int d,\
    \ int a, int b) { ans = Mono::op(ans, seg[d].prod(a, b)); }, L,\n        R, y1,\
    \ y2);\n    return ans;\n  }\n  T prod_all(int L, int R) const { return seg[log].prod(L,\
    \ R); }\n\n  // [L,R) x [0,y)\n  pair<int, T> prefix_count_and_prod(int L, int\
    \ R, Y y) const {\n    pair<int, T> ans = {0, Mono::id()};\n    work_prefix(\n\
    \        [&](int d, int a, int b) {\n          ans.fi += b - a;\n          ans.se\
    \ = Mono::op(ans.se, seg[d].prod(a, b));\n        },\n        L, R, y);\n    return\
    \ ans;\n  }\n  // [L,R) x [y1,y2)\n  pair<int, T> count_and_prod(int L, int R,\
    \ Y y1, Y y2) const {\n    pair<int, T> ans = {0, Mono::id()};\n    work_range(\n\
    \        [&](int d, int a, int b) {\n          ans.fi += b - a;\n          ans.se\
    \ = Mono::op(ans.se, seg[d].prod(a, b));\n        },\n        L, R, y1, y2);\n\
    \    return ans;\n  }\n\n  Y kth(int L, int R, int k) const {\n    assert(0 <=\
    \ k && k < R - L);\n    Y ans = 0;\n    for (int d = log - 1; d >= 0; --d) {\n\
    \      auto [L0, R0, L1, R1] = get_subtree(d + 1, L, R);\n      if (k < R0 - L0)\
    \ {\n        L = L0, R = R0;\n      } else {\n        ans |= Y(1) << d;\n    \
    \    k -= R0 - L0, L = L1, R = R1;\n      }\n    }\n    return ans;\n  }\n\n \
    \ template <bool upper>\n  Y median(int L, int R) const {\n    assert(0 <= L &&\
    \ L < R && R <= n);\n    int k = (upper ? (R - L) / 2 : (R - L - 1) / 2);\n  \
    \  return kth(L, R, k);\n  }\n\n  void set(int i, T t) {\n    assert(0 <= i &&\
    \ i < n);\n    work_point([&](int d, int i) { seg[d].set(i, t); }, i);\n  }\n\
    \  void multiply(int i, T t) {\n    assert(0 <= i && i < n);\n    work_point([&](int\
    \ d, int i) { seg[d].multiply(i, t); }, i);\n  }\n  void add(int i, T t) {\n \
    \   assert(0 <= i && i < n);\n    work_point([&](int d, int i) { seg[d].add(i,\
    \ t); }, i);\n  }\n\n  // [L,R) x [0,y) \u3067\u306E check(y, cnt, prod) \u304C\
    \ true \u3068\u306A\u308B\u6700\u5927\u306E (Y,cnt,prod)\n  // cnt \u306F\u30C7\
    \u30FC\u30BF\u4EF6\u6570\u5168\u4F53\u3067\u3042\u3063\u3066, activate/deactivate\
    \ \u3092\u8003\u616E\u3059\u308B\u5834\u5408\u306B\u306F\n  // prod \u306E\u65B9\
    \u3092\u898B\u308B\u5FC5\u8981\u304C\u3042\u308B\n  template <typename F>\n  tuple<Y,\
    \ int, T> max_right(F check, int L, int R) const {\n    int cnt = 0;\n    Y y\
    \ = 0;\n    T t = Mono::id();\n    T t_all = seg[log].prod(L, R);\n    assert(check(0,\
    \ 0, Mono::id()));\n    if (check(infty<Y>, R - L, t_all)) {\n      return {infty<Y>,\
    \ R - L, t_all};\n    }\n    for (int d = log - 1; d >= 0; --d) {\n      auto\
    \ [L0, R0, L1, R1] = get_subtree(d + 1, L, R);\n      Y y1 = y | Y(1) << d;\n\
    \      int cnt1 = cnt + R0 - L0;\n      T t1 = Mono::op(t, seg[d].prod(L0, R0));\n\
    \      if (check(y1, cnt1, t1)) {\n        y = y1, cnt = cnt1, t = t1, L = L1,\
    \ R = R1;\n      } else {\n        L = L0, R = R0;\n      }\n    }\n    return\
    \ {y, cnt, t};\n  }\n\n  // [L,R) x [0,y) \u3067\u306E check(y, cnt, prod) \u304C\
    \ true \u3068\u306A\u308B\u6700\u5927\u306E (Y,cnt,prod)\n  template <typename\
    \ F>\n  tuple<Y, int, T> max_right_many(F check, vc<pair<int, int>> LR) const\
    \ {\n    int cnt = 0;\n    Y y = 0;\n    T t = Mono::id();\n    T t_all = Mono::id();\n\
    \    int cnt_all = 0;\n    for (auto& [l, r] : LR)\n      t_all = Mono::op(t_all,\
    \ prod_all(l, r)), cnt_all += r - l;\n    assert(check(0, 0, Mono::id()));\n \
    \   if (check(infty<Y>, cnt_all, t_all)) {\n      return {infty<Y>, cnt_all, t_all};\n\
    \    }\n    for (int d = log - 1; d >= 0; --d) {\n      Y y1 = Y(1) << d;\n  \
    \    T t1 = t;\n      int cnt1 = 0;\n      for (auto& [L, R] : LR) {\n       \
    \ auto [L0, R0, L1, R1] = get_subtree(d + 1, L, R);\n        cnt1 += R0 - L0;\n\
    \        t1 = Mono::op(t1, seg[d].prod(L0, R0));\n      }\n      if (check(y1,\
    \ cnt1, t1)) {\n        y = y1, cnt = cnt1, t = t1;\n        for (auto& [L, R]\
    \ : LR) {\n          auto [L0, R0, L1, R1] = get_subtree(d + 1, L, R);\n     \
    \     L = L1, R = R1;\n        }\n      } else {\n        for (auto& [L, R] :\
    \ LR) {\n          auto [L0, R0, L1, R1] = get_subtree(d + 1, L, R);\n       \
    \   L = L0, R = R0;\n        }\n      }\n    }\n    return {y, cnt, t};\n  }\n\
    \n  // [L,R) x [y, inf) \u3067\u306E check(y, cnt, prod) \u304C true \u3068\u306A\
    \u308B\u6700\u5C0F\u306E (y,cnt,prod)\n  // cnt==0 \u3060\u3068 true \u3067\u3042\
    \u308B\u3053\u3068\u306F\u4EEE\u5B9A\u3059\u308B\n  // https://qoj.ac/contest/1047/problem/5094\n\
    \  template <typename F>\n  tuple<Y, int, T> min_left_many(F check, vc<pair<int,\
    \ int>> LR) const {\n    assert(check(limit, 0, Mono::id()));\n    int cnt = 0;\n\
    \    Y y = limit;\n    T t = Mono::id();\n    T t_all = Mono::id();\n    int cnt_all\
    \ = 0;\n    for (auto& [l, r] : LR)\n      t_all = Mono::op(t_all, prod_all(l,\
    \ r)), cnt_all += r - l;\n    if (check(0, cnt_all, t_all)) {\n      return {0,\
    \ cnt_all, t_all};\n    }\n    for (int d = log - 1; d >= 0; --d) {\n      Y y1\
    \ = y - (Y(1) << d);\n      T t1 = t;\n      int cnt1 = cnt;\n      for (auto&\
    \ [L, R] : LR) {\n        auto [L0, R0, L1, R1] = get_subtree(d + 1, L, R);\n\
    \        cnt1 += R1 - L1;\n        t1 = Mono::op(t1, seg[d].prod(L1, R1));\n \
    \     }\n      if (check(y1, cnt1, t1)) {\n        y = y1, cnt = cnt1, t = t1;\n\
    \        SHOW(y);\n        for (auto& [L, R] : LR) {\n          auto [L0, R0,\
    \ L1, R1] = get_subtree(d + 1, L, R);\n          L = L0, R = R0;\n        }\n\
    \      } else {\n        for (auto& [L, R] : LR) {\n          auto [L0, R0, L1,\
    \ R1] = get_subtree(d + 1, L, R);\n          L = L1, R = R1;\n        }\n    \
    \  }\n    }\n    SHOW(y, cnt, t);\n    return {y, cnt, t};\n  }\n};\n\ntemplate\
    \ <typename Y, typename SEGTREE>\nstruct Compressed_Wavelet_Matrix {\n  using\
    \ Mono = typename SEGTREE::MX;\n  using T = typename Mono::value_type;\n\n  int\
    \ n = 0;\n  vc<Y> key;\n  Uncompressed_Wavelet_Matrix<int, SEGTREE> wm;\n\n  Compressed_Wavelet_Matrix()\
    \ = default;\n\n  // f(i) = {A[i], dat[i]}\n  template <typename F>\n  Compressed_Wavelet_Matrix(int\
    \ n, F f) {\n    build(n, f);\n  }\n\n  Compressed_Wavelet_Matrix(const vc<Y>&\
    \ A) {\n    static_assert(is_same_v<SEGTREE, Dummy_Data_Structure>);\n    build(A);\n\
    \  }\n\n  template <typename F>\n  void build(int n, F f) {\n    this->n = n;\n\
    \    vc<Y> A(n);\n    vc<T> S(n);\n    FOR(i, n) tie(A[i], S[i]) = f(i);\n\n \
    \   key = A;\n    UNIQUE(key);\n\n    wm.build(n, [&](int i) -> pair<int, T> {\n\
    \      int k = LB(key, A[i]);\n      return {k, S[i]};\n    });\n  }\n\n  void\
    \ build(const vc<Y>& A) {\n    static_assert(is_same_v<SEGTREE, Dummy_Data_Structure>);\n\
    \    n = len(A);\n    key = A;\n    UNIQUE(key);\n\n    wm.build(n, [&](int i)\
    \ -> pair<int, T> {\n      int k = LB(key, A[i]);\n      return {k, Mono::id()};\n\
    \    });\n  }\n\n  Y kth(int L, int R, int k) const { return key[wm.kth(L, R,\
    \ k)]; }\n\n  template <bool upper>\n  Y median(int L, int R) const {\n    return\
    \ key[wm.template median<upper>(L, R)];\n  }\n\n  // [L,R) x [-inf,y)\n  int prefix_count(int\
    \ L, int R, Y y) const {\n    return wm.prefix_count(L, R, LB(key, y));\n  }\n\
    \n  // [L,R) x [y1,y2)\n  int count(int L, int R, Y y1, Y y2) const {\n    return\
    \ wm.count(L, R, LB(key, y1), LB(key, y2));\n  }\n\n  // [L,R) x [-inf,y)\n  T\
    \ prefix_prod(int L, int R, Y y) const {\n    return wm.prefix_prod(L, R, LB(key,\
    \ y));\n  }\n\n  // [L,R) x [y1,y2)\n  T prod(int L, int R, Y y1, Y y2) const\
    \ {\n    return wm.prod(L, R, LB(key, y1), LB(key, y2));\n  }\n\n  T prod_all(int\
    \ L, int R) const { return wm.prod_all(L, R); }\n\n  // [L,R) x [-inf,y)\n  pair<int,\
    \ T> prefix_count_and_prod(int L, int R, Y y) const {\n    return wm.prefix_count_and_prod(L,\
    \ R, LB(key, y));\n  }\n\n  // [L,R) x [y1,y2)\n  pair<int, T> count_and_prod(int\
    \ L, int R, Y y1, Y y2) const {\n    return wm.count_and_prod(L, R, LB(key, y1),\
    \ LB(key, y2));\n  }\n\n  void set(int i, T t) { wm.set(i, t); }\n\n  void multiply(int\
    \ i, T t) { wm.multiply(i, t); }\n\n  void add(int i, T t) { wm.add(i, t); }\n\
    };\n\ntemplate <typename Y, bool compress, typename SEGTREE = Dummy_Data_Structure>\n\
    using Wavelet_Matrix =\n    conditional_t<compress, Compressed_Wavelet_Matrix<Y,\
    \ SEGTREE>,\n        Uncompressed_Wavelet_Matrix<Y, SEGTREE>>;\n"
  code: "// Source: https://github.com/maspypy/library/blob/main/ds/wavelet_matrix/wavelet_matrix.hpp\n\
    #include \"ds/bit_vector.hpp\"\n#include \"ds/dummy_data_structure.hpp\"\n\ntemplate\
    \ <typename Y, typename SEGTREE>\nstruct Uncompressed_Wavelet_Matrix {\n  using\
    \ Mono = typename SEGTREE::MX;\n  using T = typename Mono::value_type;\n  static_assert(Mono::commute);\n\
    \  static_assert(is_same_v<Y, int> || is_same_v<Y, ll>);\n  int n = 0, log = 0;\n\
    \  vc<int> mid;\n  vc<Bit_Vector> bv;\n  vc<SEGTREE> seg;\n  Y limit;\n\n  Uncompressed_Wavelet_Matrix()\
    \ = default;\n\n  // f(i) = {A[i], dat[i]}\n  template <typename F>\n  Uncompressed_Wavelet_Matrix(int\
    \ n, F f, int log = -1) {\n    build(n, f, log);\n  }\n  Uncompressed_Wavelet_Matrix(const\
    \ vc<Y>& A, int log = -1) {\n    static_assert(is_same_v<SEGTREE, Dummy_Data_Structure>);\n\
    \    build(len(A), [&](int i) -> pair<Y, T> { return {A[i], Mono::id()}; }, log);\n\
    \  }\n\n  template <typename F>\n  void build(int n, F f, int log = -1) {\n  \
    \  this->n = n;\n    vc<Y> A(n);\n    vc<T> S(n);\n    FOR(i, n) tie(A[i], S[i])\
    \ = f(i);\n    if (log == -1) {\n      log = (n == 0 ? 0 : topbit(MAX(A)) + 1);\n\
    \    } else {\n      for (auto& x : A) assert(0 <= x && topbit(x) < log);\n  \
    \  }\n    this->log = log;\n    limit = Y(1) << log;\n    if constexpr (is_same_v<Y,\
    \ int>) assert(0 <= log && log <= 30);\n    if constexpr (is_same_v<Y, ll>) assert(0\
    \ <= log && log <= 62);\n    mid.resize(log), bv.assign(log, Bit_Vector(n));\n\
    \    vc<Y> A0(n), A1(n);\n    vc<T> S0(n), S1(n);\n    seg.resize(log + 1);\n\
    \    seg[log].build(S);\n    for (int d = log - 1; d >= 0; --d) {\n      int p0\
    \ = 0, p1 = 0;\n      for (int i = 0; i < n; ++i) {\n        if (A[i] >> d & 1)\
    \ {\n          bv[d].set(i), A1[p1] = A[i], S1[p1] = S[i], p1++;\n        } else\
    \ {\n          A0[p0] = A[i], S0[p0] = S[i], p0++;\n        }\n      }\n     \
    \ swap(A, A0), swap(S, S0);\n      move(A1.begin(), A1.begin() + p1, A.begin()\
    \ + p0);\n      move(S1.begin(), S1.begin() + p1, S.begin() + p0);\n      mid[d]\
    \ = p0, bv[d].build(), seg[d].build(S);\n    }\n  }\n\n  tuple<int, int, int,\
    \ int> get_subtree(int d, int L, int R) const {\n    assert(1 <= d && d <= log);\n\
    \    int a = bv[d - 1].count_prefix(L), b = bv[d - 1].count_prefix(R);\n    return\
    \ {L - a, R - b, mid[d - 1] + a, mid[d - 1] + b};\n  }\n\n  template <typename\
    \ F>\n  void work_point(F f, int i) {\n    assert(0 <= i && i < n);\n    f(log,\
    \ i);\n    FOR_R(d, log) {\n      int a = bv[d].count_prefix(i);\n      if (bv[d][i])\
    \ {\n        i = mid[d] + a;\n      } else {\n        i = i - a;\n      }\n  \
    \    f(d, i);\n    }\n  }\n\n  template <typename F>\n  void work_prefix(F f,\
    \ int L, int R, Y y) const {\n    chmin(y, limit);\n    if (y == 0) return;\n\
    \    if (y == limit) {\n      f(log, L, R);\n      return;\n    }\n    FOR_R(d,\
    \ log) {\n      auto [L0, R0, L1, R1] = get_subtree(d + 1, L, R);\n      if (y\
    \ >> d & 1) {\n        f(d, L0, R0);\n        L = L1, R = R1;\n      } else {\n\
    \        L = L0, R = R0;\n      }\n    }\n  }\n\n  template <typename F>\n  void\
    \ work_range(F f, int L, int R, Y y1, Y y2) const {\n    chmin(y2, limit);\n \
    \   if (y1 >= y2) return;\n    assert(0 <= y1 && y1 <= y2 && y2 <= limit);\n \
    \   if (y1 == 0) return work_prefix(f, L, R, y2);\n    auto dfs = [&](auto& dfs,\
    \ int d, int L, int R, Y y1, Y y2) -> void {\n      if (y1 == y2) return;\n  \
    \    if (y1 == 0 && y2 == Y(1) << d) {\n        f(d, L, R);\n        return;\n\
    \      }\n      assert(d > 0);\n      auto [L0, R0, L1, R1] = get_subtree(d, L,\
    \ R);\n      Y m = (Y(1) << (d - 1));\n\n      if (y2 <= m) {\n        dfs(dfs,\
    \ d - 1, L0, R0, y1, y2);\n      } else if (y1 >= m) {\n        dfs(dfs, d - 1,\
    \ L1, R1, y1 - m, y2 - m);\n      } else {\n        dfs(dfs, d - 1, L0, R0, y1,\
    \ m);\n        dfs(dfs, d - 1, L1, R1, 0, y2 - m);\n      }\n    };\n    dfs(dfs,\
    \ log, L, R, y1, y2);\n  }\n\n  // [L,R) x [0,y)\n  int prefix_count(int L, int\
    \ R, Y y) const {\n    int cnt = 0;\n    work_prefix([&](int d, int a, int b)\
    \ { cnt += b - a; }, L, R, y);\n    return cnt;\n  }\n\n  // [L,R) x [y1,y2)\n\
    \  int count(int L, int R, Y y1, Y y2) const {\n    return prefix_count(L, R,\
    \ y2) - prefix_count(L, R, y1);\n  }\n\n  // [L,R) x [0,y)\n  T prefix_prod(int\
    \ L, int R, Y y) const {\n    T ans = Mono::id();\n    work_prefix(\n        [&](int\
    \ d, int a, int b) { ans = Mono::op(ans, seg[d].prod(a, b)); }, L,\n        R,\
    \ y);\n    return ans;\n  }\n  // [L,R) x [y1,y2)\n  T prod(int L, int R, Y y1,\
    \ Y y2) const {\n    T ans = Mono::id();\n    work_range(\n        [&](int d,\
    \ int a, int b) { ans = Mono::op(ans, seg[d].prod(a, b)); }, L,\n        R, y1,\
    \ y2);\n    return ans;\n  }\n  T prod_all(int L, int R) const { return seg[log].prod(L,\
    \ R); }\n\n  // [L,R) x [0,y)\n  pair<int, T> prefix_count_and_prod(int L, int\
    \ R, Y y) const {\n    pair<int, T> ans = {0, Mono::id()};\n    work_prefix(\n\
    \        [&](int d, int a, int b) {\n          ans.fi += b - a;\n          ans.se\
    \ = Mono::op(ans.se, seg[d].prod(a, b));\n        },\n        L, R, y);\n    return\
    \ ans;\n  }\n  // [L,R) x [y1,y2)\n  pair<int, T> count_and_prod(int L, int R,\
    \ Y y1, Y y2) const {\n    pair<int, T> ans = {0, Mono::id()};\n    work_range(\n\
    \        [&](int d, int a, int b) {\n          ans.fi += b - a;\n          ans.se\
    \ = Mono::op(ans.se, seg[d].prod(a, b));\n        },\n        L, R, y1, y2);\n\
    \    return ans;\n  }\n\n  Y kth(int L, int R, int k) const {\n    assert(0 <=\
    \ k && k < R - L);\n    Y ans = 0;\n    for (int d = log - 1; d >= 0; --d) {\n\
    \      auto [L0, R0, L1, R1] = get_subtree(d + 1, L, R);\n      if (k < R0 - L0)\
    \ {\n        L = L0, R = R0;\n      } else {\n        ans |= Y(1) << d;\n    \
    \    k -= R0 - L0, L = L1, R = R1;\n      }\n    }\n    return ans;\n  }\n\n \
    \ template <bool upper>\n  Y median(int L, int R) const {\n    assert(0 <= L &&\
    \ L < R && R <= n);\n    int k = (upper ? (R - L) / 2 : (R - L - 1) / 2);\n  \
    \  return kth(L, R, k);\n  }\n\n  void set(int i, T t) {\n    assert(0 <= i &&\
    \ i < n);\n    work_point([&](int d, int i) { seg[d].set(i, t); }, i);\n  }\n\
    \  void multiply(int i, T t) {\n    assert(0 <= i && i < n);\n    work_point([&](int\
    \ d, int i) { seg[d].multiply(i, t); }, i);\n  }\n  void add(int i, T t) {\n \
    \   assert(0 <= i && i < n);\n    work_point([&](int d, int i) { seg[d].add(i,\
    \ t); }, i);\n  }\n\n  // [L,R) x [0,y) \u3067\u306E check(y, cnt, prod) \u304C\
    \ true \u3068\u306A\u308B\u6700\u5927\u306E (Y,cnt,prod)\n  // cnt \u306F\u30C7\
    \u30FC\u30BF\u4EF6\u6570\u5168\u4F53\u3067\u3042\u3063\u3066, activate/deactivate\
    \ \u3092\u8003\u616E\u3059\u308B\u5834\u5408\u306B\u306F\n  // prod \u306E\u65B9\
    \u3092\u898B\u308B\u5FC5\u8981\u304C\u3042\u308B\n  template <typename F>\n  tuple<Y,\
    \ int, T> max_right(F check, int L, int R) const {\n    int cnt = 0;\n    Y y\
    \ = 0;\n    T t = Mono::id();\n    T t_all = seg[log].prod(L, R);\n    assert(check(0,\
    \ 0, Mono::id()));\n    if (check(infty<Y>, R - L, t_all)) {\n      return {infty<Y>,\
    \ R - L, t_all};\n    }\n    for (int d = log - 1; d >= 0; --d) {\n      auto\
    \ [L0, R0, L1, R1] = get_subtree(d + 1, L, R);\n      Y y1 = y | Y(1) << d;\n\
    \      int cnt1 = cnt + R0 - L0;\n      T t1 = Mono::op(t, seg[d].prod(L0, R0));\n\
    \      if (check(y1, cnt1, t1)) {\n        y = y1, cnt = cnt1, t = t1, L = L1,\
    \ R = R1;\n      } else {\n        L = L0, R = R0;\n      }\n    }\n    return\
    \ {y, cnt, t};\n  }\n\n  // [L,R) x [0,y) \u3067\u306E check(y, cnt, prod) \u304C\
    \ true \u3068\u306A\u308B\u6700\u5927\u306E (Y,cnt,prod)\n  template <typename\
    \ F>\n  tuple<Y, int, T> max_right_many(F check, vc<pair<int, int>> LR) const\
    \ {\n    int cnt = 0;\n    Y y = 0;\n    T t = Mono::id();\n    T t_all = Mono::id();\n\
    \    int cnt_all = 0;\n    for (auto& [l, r] : LR)\n      t_all = Mono::op(t_all,\
    \ prod_all(l, r)), cnt_all += r - l;\n    assert(check(0, 0, Mono::id()));\n \
    \   if (check(infty<Y>, cnt_all, t_all)) {\n      return {infty<Y>, cnt_all, t_all};\n\
    \    }\n    for (int d = log - 1; d >= 0; --d) {\n      Y y1 = Y(1) << d;\n  \
    \    T t1 = t;\n      int cnt1 = 0;\n      for (auto& [L, R] : LR) {\n       \
    \ auto [L0, R0, L1, R1] = get_subtree(d + 1, L, R);\n        cnt1 += R0 - L0;\n\
    \        t1 = Mono::op(t1, seg[d].prod(L0, R0));\n      }\n      if (check(y1,\
    \ cnt1, t1)) {\n        y = y1, cnt = cnt1, t = t1;\n        for (auto& [L, R]\
    \ : LR) {\n          auto [L0, R0, L1, R1] = get_subtree(d + 1, L, R);\n     \
    \     L = L1, R = R1;\n        }\n      } else {\n        for (auto& [L, R] :\
    \ LR) {\n          auto [L0, R0, L1, R1] = get_subtree(d + 1, L, R);\n       \
    \   L = L0, R = R0;\n        }\n      }\n    }\n    return {y, cnt, t};\n  }\n\
    \n  // [L,R) x [y, inf) \u3067\u306E check(y, cnt, prod) \u304C true \u3068\u306A\
    \u308B\u6700\u5C0F\u306E (y,cnt,prod)\n  // cnt==0 \u3060\u3068 true \u3067\u3042\
    \u308B\u3053\u3068\u306F\u4EEE\u5B9A\u3059\u308B\n  // https://qoj.ac/contest/1047/problem/5094\n\
    \  template <typename F>\n  tuple<Y, int, T> min_left_many(F check, vc<pair<int,\
    \ int>> LR) const {\n    assert(check(limit, 0, Mono::id()));\n    int cnt = 0;\n\
    \    Y y = limit;\n    T t = Mono::id();\n    T t_all = Mono::id();\n    int cnt_all\
    \ = 0;\n    for (auto& [l, r] : LR)\n      t_all = Mono::op(t_all, prod_all(l,\
    \ r)), cnt_all += r - l;\n    if (check(0, cnt_all, t_all)) {\n      return {0,\
    \ cnt_all, t_all};\n    }\n    for (int d = log - 1; d >= 0; --d) {\n      Y y1\
    \ = y - (Y(1) << d);\n      T t1 = t;\n      int cnt1 = cnt;\n      for (auto&\
    \ [L, R] : LR) {\n        auto [L0, R0, L1, R1] = get_subtree(d + 1, L, R);\n\
    \        cnt1 += R1 - L1;\n        t1 = Mono::op(t1, seg[d].prod(L1, R1));\n \
    \     }\n      if (check(y1, cnt1, t1)) {\n        y = y1, cnt = cnt1, t = t1;\n\
    \        SHOW(y);\n        for (auto& [L, R] : LR) {\n          auto [L0, R0,\
    \ L1, R1] = get_subtree(d + 1, L, R);\n          L = L0, R = R0;\n        }\n\
    \      } else {\n        for (auto& [L, R] : LR) {\n          auto [L0, R0, L1,\
    \ R1] = get_subtree(d + 1, L, R);\n          L = L1, R = R1;\n        }\n    \
    \  }\n    }\n    SHOW(y, cnt, t);\n    return {y, cnt, t};\n  }\n};\n\ntemplate\
    \ <typename Y, typename SEGTREE>\nstruct Compressed_Wavelet_Matrix {\n  using\
    \ Mono = typename SEGTREE::MX;\n  using T = typename Mono::value_type;\n\n  int\
    \ n = 0;\n  vc<Y> key;\n  Uncompressed_Wavelet_Matrix<int, SEGTREE> wm;\n\n  Compressed_Wavelet_Matrix()\
    \ = default;\n\n  // f(i) = {A[i], dat[i]}\n  template <typename F>\n  Compressed_Wavelet_Matrix(int\
    \ n, F f) {\n    build(n, f);\n  }\n\n  Compressed_Wavelet_Matrix(const vc<Y>&\
    \ A) {\n    static_assert(is_same_v<SEGTREE, Dummy_Data_Structure>);\n    build(A);\n\
    \  }\n\n  template <typename F>\n  void build(int n, F f) {\n    this->n = n;\n\
    \    vc<Y> A(n);\n    vc<T> S(n);\n    FOR(i, n) tie(A[i], S[i]) = f(i);\n\n \
    \   key = A;\n    UNIQUE(key);\n\n    wm.build(n, [&](int i) -> pair<int, T> {\n\
    \      int k = LB(key, A[i]);\n      return {k, S[i]};\n    });\n  }\n\n  void\
    \ build(const vc<Y>& A) {\n    static_assert(is_same_v<SEGTREE, Dummy_Data_Structure>);\n\
    \    n = len(A);\n    key = A;\n    UNIQUE(key);\n\n    wm.build(n, [&](int i)\
    \ -> pair<int, T> {\n      int k = LB(key, A[i]);\n      return {k, Mono::id()};\n\
    \    });\n  }\n\n  Y kth(int L, int R, int k) const { return key[wm.kth(L, R,\
    \ k)]; }\n\n  template <bool upper>\n  Y median(int L, int R) const {\n    return\
    \ key[wm.template median<upper>(L, R)];\n  }\n\n  // [L,R) x [-inf,y)\n  int prefix_count(int\
    \ L, int R, Y y) const {\n    return wm.prefix_count(L, R, LB(key, y));\n  }\n\
    \n  // [L,R) x [y1,y2)\n  int count(int L, int R, Y y1, Y y2) const {\n    return\
    \ wm.count(L, R, LB(key, y1), LB(key, y2));\n  }\n\n  // [L,R) x [-inf,y)\n  T\
    \ prefix_prod(int L, int R, Y y) const {\n    return wm.prefix_prod(L, R, LB(key,\
    \ y));\n  }\n\n  // [L,R) x [y1,y2)\n  T prod(int L, int R, Y y1, Y y2) const\
    \ {\n    return wm.prod(L, R, LB(key, y1), LB(key, y2));\n  }\n\n  T prod_all(int\
    \ L, int R) const { return wm.prod_all(L, R); }\n\n  // [L,R) x [-inf,y)\n  pair<int,\
    \ T> prefix_count_and_prod(int L, int R, Y y) const {\n    return wm.prefix_count_and_prod(L,\
    \ R, LB(key, y));\n  }\n\n  // [L,R) x [y1,y2)\n  pair<int, T> count_and_prod(int\
    \ L, int R, Y y1, Y y2) const {\n    return wm.count_and_prod(L, R, LB(key, y1),\
    \ LB(key, y2));\n  }\n\n  void set(int i, T t) { wm.set(i, t); }\n\n  void multiply(int\
    \ i, T t) { wm.multiply(i, t); }\n\n  void add(int i, T t) { wm.add(i, t); }\n\
    };\n\ntemplate <typename Y, bool compress, typename SEGTREE = Dummy_Data_Structure>\n\
    using Wavelet_Matrix =\n    conditional_t<compress, Compressed_Wavelet_Matrix<Y,\
    \ SEGTREE>,\n        Uncompressed_Wavelet_Matrix<Y, SEGTREE>>;\n"
  dependsOn:
  - ds/bit_vector.hpp
  - ds/dummy_data_structure.hpp
  - alg/monoid/dummy.hpp
  isVerificationFile: false
  path: ds/wavelet_matrix/wavelet_matrix.hpp
  requiredBy:
  - graph/ds/tree_wavelet_matrix.hpp
  - ds/wavelet_matrix/wavelet_matrix_2d_range.hpp
  - string/prefix_substring_LCS.hpp
  timestamp: '2026-10-15 19:54:56+09:00'
  verificationStatus: LIBRARY_SOME_WA
  verifiedWith:
  - test/3_yukicoder/1332.test.cpp
  - test/3_yukicoder/919.test.cpp
  - test/3_yukicoder/924.test.cpp
  - test/3_yukicoder/1625_2.test.cpp
  - test/3_yukicoder/1919_2.test.cpp
  - test/3_yukicoder/2859.test.cpp
  - test/3_yukicoder/1600_2.test.cpp
  - test/3_yukicoder/2065.test.cpp
  - test/2_library_checker/data_structure/rectangle_sum_wm.test.cpp
  - test/2_library_checker/data_structure/point_add_rectangle_sum_wm_mono.test.cpp
  - test/2_library_checker/data_structure/point_add_rectangle_sum_wm_abel.test.cpp
  - test/2_library_checker/data_structure/rectangle_sum_wm_abel.test.cpp
  - test/2_library_checker/data_structure/range_kth_smallest_wavelet.test.cpp
  - test/2_library_checker/string/prefix_substring_lcs.test.cpp
documentation_of: ds/wavelet_matrix/wavelet_matrix.hpp
layout: document
redirect_from:
- /library/ds/wavelet_matrix/wavelet_matrix.hpp
- /library/ds/wavelet_matrix/wavelet_matrix.hpp.html
title: ds/wavelet_matrix/wavelet_matrix.hpp
---
