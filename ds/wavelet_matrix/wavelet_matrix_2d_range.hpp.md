---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: alg/monoid/dummy.hpp
    title: alg/monoid/dummy.hpp
  - icon: ':heavy_check_mark:'
    path: ds/bit_vector.hpp
    title: ds/bit_vector.hpp
  - icon: ':heavy_check_mark:'
    path: ds/dummy_data_structure.hpp
    title: ds/dummy_data_structure.hpp
  - icon: ':heavy_check_mark:'
    path: ds/index_compression.hpp
    title: ds/index_compression.hpp
  - icon: ':heavy_check_mark:'
    path: ds/wavelet_matrix/wavelet_matrix.hpp
    title: ds/wavelet_matrix/wavelet_matrix.hpp
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/2_library_checker/data_structure/point_add_rectangle_sum_wm_abel.test.cpp
    title: test/2_library_checker/data_structure/point_add_rectangle_sum_wm_abel.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/2_library_checker/data_structure/point_add_rectangle_sum_wm_mono.test.cpp
    title: test/2_library_checker/data_structure/point_add_rectangle_sum_wm_mono.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/2_library_checker/data_structure/rectangle_sum_wm.test.cpp
    title: test/2_library_checker/data_structure/rectangle_sum_wm.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/2_library_checker/data_structure/rectangle_sum_wm_abel.test.cpp
    title: test/2_library_checker/data_structure/rectangle_sum_wm_abel.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/3_yukicoder/1600_2.test.cpp
    title: test/3_yukicoder/1600_2.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/3_yukicoder/1625_2.test.cpp
    title: test/3_yukicoder/1625_2.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/3_yukicoder/1919_2.test.cpp
    title: test/3_yukicoder/1919_2.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/3_yukicoder/2859.test.cpp
    title: test/3_yukicoder/2859.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 1 \"ds/bit_vector.hpp\"\nstruct Bit_Vector {\n  int n;\n  bool\
    \ prepared = 0;\n  vc<pair<u64, u32>> dat;\n  Bit_Vector(int n = 0) : n(n) { dat.assign((n\
    \ + 127) >> 6, {0, 0}); }\n  void set(int i) {\n    assert(!prepared && (0 <=\
    \ i && i < n));\n    dat[i >> 6].fi |= u64(1) << (i & 63);\n  }\n  void reset()\
    \ {\n    fill(all(dat), pair<u64, u32>{0, 0});\n    prepared = 0;\n  }\n  void\
    \ build() {\n    prepared = 1;\n    FOR(i, len(dat) - 1) dat[i + 1].se = dat[i].se\
    \ + popcnt(dat[i].fi);\n  }\n  bool operator[](int i) const { return dat[i >>\
    \ 6].fi >> (i & 63) & 1; }\n  // [0, k) \u5185\u306E 1 \u306E\u500B\u6570\n  int\
    \ count_prefix(int k, bool f = true) const {\n    assert(prepared);\n    auto\
    \ [a, b] = dat[k >> 6];\n    int ret = b + popcnt(a & ((u64(1) << (k & 63)) -\
    \ 1));\n    return (f ? ret : k - ret);\n  }\n  int count(int L, int R, bool f\
    \ = true) const {\n    return count_prefix(R, f) - count_prefix(L, f);\n  }\n\
    \  string to_string() const {\n    string ans;\n    FOR(i, n) ans += '0' + (dat[i\
    \ / 64].fi >> (i % 64) & 1);\n    return ans;\n  }\n};\n#line 1 \"alg/monoid/dummy.hpp\"\
    \nstruct Monoid_Dummy {\n  using value_type = char;\n  static constexpr bool commute\
    \ = true;\n  static value_type op(value_type, value_type) { return 0; }\n  static\
    \ value_type unit() { return 0; }\n};\n#line 2 \"ds/dummy_data_structure.hpp\"\
    \n\nstruct Dummy_Data_Structure {\n  using MX = Monoid_Dummy;\n  using T = typename\
    \ MX::value_type;\n  void build(const vc<T>& A) {}\n};\n#line 3 \"ds/wavelet_matrix/wavelet_matrix.hpp\"\
    \n\r\ntemplate <typename Y, typename SEGTREE>\r\nstruct Uncompressed_Wavelet_Matrix\
    \ {\r\n  using Mono = typename SEGTREE::MX;\r\n  using T = typename Mono::value_type;\r\
    \n  static_assert(Mono::commute);\r\n  static_assert(is_same_v<Y, int> || is_same_v<Y,\
    \ ll>);\r\n  int n = 0, log = 0;\r\n  vc<int> mid;\r\n  vc<Bit_Vector> bv;\r\n\
    \  vc<SEGTREE> seg;\r\n  Y limit;\r\n\r\n  Uncompressed_Wavelet_Matrix() = default;\r\
    \n\r\n  // f(i) = {A[i], dat[i]}\r\n  template <typename F>\r\n  Uncompressed_Wavelet_Matrix(int\
    \ n, F f, int log = -1) {\r\n    build(n, f, log);\r\n  }\r\n  Uncompressed_Wavelet_Matrix(const\
    \ vc<Y>& A, int log = -1) {\r\n    static_assert(is_same_v<SEGTREE, Dummy_Data_Structure>);\r\
    \n    build(\r\n        len(A), [&](int i) -> pair<Y, T> { return {A[i], Mono::unit()};\
    \ }, log);\r\n  }\r\n\r\n  template <typename F>\r\n  void build(int n, F f, int\
    \ log = -1) {\r\n    this->n = n;\r\n    vc<Y> A(n);\r\n    vc<T> S(n);\r\n  \
    \  FOR(i, n) tie(A[i], S[i]) = f(i);\r\n    if (log == -1) {\r\n      log = (n\
    \ == 0 ? 0 : topbit(MAX(A)) + 1);\r\n    } else {\r\n      for (auto& x : A) assert(0\
    \ <= x && topbit(x) < log);\r\n    }\r\n    this->log = log;\r\n    limit = Y(1)\
    \ << log;\r\n    if constexpr (is_same_v<Y, int>) assert(0 <= log && log <= 30);\r\
    \n    if constexpr (is_same_v<Y, ll>) assert(0 <= log && log <= 62);\r\n    mid.resize(log),\
    \ bv.assign(log, Bit_Vector(n));\r\n    vc<Y> A0(n), A1(n);\r\n    vc<T> S0(n),\
    \ S1(n);\r\n    seg.resize(log + 1);\r\n    seg[log].build(S);\r\n    for (int\
    \ d = log - 1; d >= 0; --d) {\r\n      int p0 = 0, p1 = 0;\r\n      for (int i\
    \ = 0; i < n; ++i) {\r\n        if (A[i] >> d & 1) {\r\n          bv[d].set(i),\
    \ A1[p1] = A[i], S1[p1] = S[i], p1++;\r\n        } else {\r\n          A0[p0]\
    \ = A[i], S0[p0] = S[i], p0++;\r\n        }\r\n      }\r\n      swap(A, A0), swap(S,\
    \ S0);\r\n      move(A1.begin(), A1.begin() + p1, A.begin() + p0);\r\n      move(S1.begin(),\
    \ S1.begin() + p1, S.begin() + p0);\r\n      mid[d] = p0, bv[d].build(), seg[d].build(S);\r\
    \n    }\r\n  }\r\n\r\n  tuple<int, int, int, int> get_subtree(int d, int L, int\
    \ R) const {\r\n    assert(1 <= d && d <= log);\r\n    int a = bv[d - 1].count_prefix(L),\
    \ b = bv[d - 1].count_prefix(R);\r\n    return {L - a, R - b, mid[d - 1] + a,\
    \ mid[d - 1] + b};\r\n  }\r\n\r\n  template <typename F>\r\n  void work_point(F\
    \ f, int i) {\r\n    assert(0 <= i && i < n);\r\n    f(log, i);\r\n    FOR_R(d,\
    \ log) {\r\n      int a = bv[d].count_prefix(i);\r\n      if (bv[d][i]) {\r\n\
    \        i = mid[d] + a;\r\n      } else {\r\n        i = i - a;\r\n      }\r\n\
    \      f(d, i);\r\n    }\r\n  }\r\n\r\n  template <typename F>\r\n  void work_prefix(F\
    \ f, int L, int R, Y y) const {\r\n    chmin(y, limit);\r\n    if (y == 0) return;\r\
    \n    if (y == limit) {\r\n      f(log, L, R);\r\n      return;\r\n    }\r\n \
    \   FOR_R(d, log) {\r\n      auto [L0, R0, L1, R1] = get_subtree(d + 1, L, R);\r\
    \n      if (y >> d & 1) {\r\n        f(d, L0, R0);\r\n        L = L1, R = R1;\r\
    \n      } else {\r\n        L = L0, R = R0;\r\n      }\r\n    }\r\n  }\r\n\r\n\
    \  template <typename F>\r\n  void work_range(F f, int L, int R, Y y1, Y y2) const\
    \ {\r\n    chmin(y2, limit);\r\n    if (y1 >= y2) return;\r\n    assert(0 <= y1\
    \ && y1 <= y2 && y2 <= limit);\r\n    if (y1 == 0) return work_prefix(f, L, R,\
    \ y2);\r\n    auto dfs = [&](auto& dfs, int d, int L, int R, Y y1, Y y2) -> void\
    \ {\r\n      if (y1 == y2) return;\r\n      if (y1 == 0 && y2 == Y(1) << d) {\r\
    \n        f(d, L, R);\r\n        return;\r\n      }\r\n      assert(d > 0);\r\n\
    \      auto [L0, R0, L1, R1] = get_subtree(d, L, R);\r\n      Y m = (Y(1) << (d\
    \ - 1));\r\n\r\n      if (y2 <= m) {\r\n        dfs(dfs, d - 1, L0, R0, y1, y2);\r\
    \n      } else if (y1 >= m) {\r\n        dfs(dfs, d - 1, L1, R1, y1 - m, y2 -\
    \ m);\r\n      } else {\r\n        dfs(dfs, d - 1, L0, R0, y1, m);\r\n       \
    \ dfs(dfs, d - 1, L1, R1, 0, y2 - m);\r\n      }\r\n    };\r\n    dfs(dfs, log,\
    \ L, R, y1, y2);\r\n  }\r\n\r\n  // [L,R) x [0,y)\r\n  int prefix_count(int L,\
    \ int R, Y y) const {\r\n    int cnt = 0;\r\n    work_prefix([&](int d, int a,\
    \ int b) { cnt += b - a; }, L, R, y);\r\n    return cnt;\r\n  }\r\n\r\n  // [L,R)\
    \ x [y1,y2)\r\n  int count(int L, int R, Y y1, Y y2) const {\r\n    return prefix_count(L,\
    \ R, y2) - prefix_count(L, R, y1);\r\n  }\r\n\r\n  // [L,R) x [0,y)\r\n  T prefix_prod(int\
    \ L, int R, Y y) const {\r\n    T ans = Mono::unit();\r\n    work_prefix(\r\n\
    \        [&](int d, int a, int b) { ans = Mono::op(ans, seg[d].prod(a, b)); },\
    \ L,\r\n        R, y);\r\n    return ans;\r\n  }\r\n  // [L,R) x [y1,y2)\r\n \
    \ T prod(int L, int R, Y y1, Y y2) const {\r\n    T ans = Mono::unit();\r\n  \
    \  work_range(\r\n        [&](int d, int a, int b) { ans = Mono::op(ans, seg[d].prod(a,\
    \ b)); }, L,\r\n        R, y1, y2);\r\n    return ans;\r\n  }\r\n  T prod_all(int\
    \ L, int R) const { return seg[log].prod(L, R); }\r\n\r\n  // [L,R) x [0,y)\r\n\
    \  pair<int, T> prefix_count_and_prod(int L, int R, Y y) const {\r\n    pair<int,\
    \ T> ans = {0, Mono::unit()};\r\n    work_prefix(\r\n        [&](int d, int a,\
    \ int b) {\r\n          ans.fi += b - a;\r\n          ans.se = Mono::op(ans.se,\
    \ seg[d].prod(a, b));\r\n        },\r\n        L, R, y);\r\n    return ans;\r\n\
    \  }\r\n  // [L,R) x [y1,y2)\r\n  pair<int, T> count_and_prod(int L, int R, Y\
    \ y1, Y y2) const {\r\n    pair<int, T> ans = {0, Mono::unit()};\r\n    work_range(\r\
    \n        [&](int d, int a, int b) {\r\n          ans.fi += b - a;\r\n       \
    \   ans.se = Mono::op(ans.se, seg[d].prod(a, b));\r\n        },\r\n        L,\
    \ R, y1, y2);\r\n    return ans;\r\n  }\r\n\r\n  Y kth(int L, int R, int k) const\
    \ {\r\n    assert(0 <= k && k < R - L);\r\n    Y ans = 0;\r\n    for (int d =\
    \ log - 1; d >= 0; --d) {\r\n      auto [L0, R0, L1, R1] = get_subtree(d + 1,\
    \ L, R);\r\n      if (k < R0 - L0) {\r\n        L = L0, R = R0;\r\n      } else\
    \ {\r\n        ans |= Y(1) << d;\r\n        k -= R0 - L0, L = L1, R = R1;\r\n\
    \      }\r\n    }\r\n    return ans;\r\n  }\r\n\r\n  template <bool upper>\r\n\
    \  Y median(int L, int R) const {\r\n    assert(0 <= L && L < R && R <= n);\r\n\
    \    int k = (upper ? (R - L) / 2 : (R - L - 1) / 2);\r\n    return kth(L, R,\
    \ k);\r\n  }\r\n\r\n  void set(int i, T t) {\r\n    assert(0 <= i && i < n);\r\
    \n    work_point([&](int d, int i) { seg[d].set(i, t); }, i);\r\n  }\r\n  void\
    \ multiply(int i, T t) {\r\n    assert(0 <= i && i < n);\r\n    work_point([&](int\
    \ d, int i) { seg[d].multiply(i, t); }, i);\r\n  }\r\n  void add(int i, T t) {\r\
    \n    assert(0 <= i && i < n);\r\n    work_point([&](int d, int i) { seg[d].add(i,\
    \ t); }, i);\r\n  }\r\n\r\n  // [L,R) x [0,y) \u3067\u306E check(y, cnt, prod)\
    \ \u304C true \u3068\u306A\u308B\u6700\u5927\u306E (Y,cnt,prod)\r\n  template\
    \ <typename F>\r\n  tuple<Y, int, T> max_right(F check, int L, int R) const {\r\
    \n    assert(limit < infty<Y>);\r\n    int cnt = 0;\r\n    Y y = 0;\r\n    T t\
    \ = Mono::unit();\r\n    T t_all = seg[log].prod(L, R);\r\n    assert(check(0,\
    \ 0, Mono::unit()));\r\n    if (check(limit, R - L, t_all)) {\r\n      y = binary_search([&](Y\
    \ y) -> bool { return check(y, R - L, t_all); },\r\n                        limit,\
    \ infty<Y> + 1);\r\n      return {y, R - L, t_all};\r\n    }\r\n    for (int d\
    \ = log - 1; d >= 0; --d) {\r\n      auto [L0, R0, L1, R1] = get_subtree(d + 1,\
    \ L, R);\r\n      Y y1 = y | Y(1) << d;\r\n      int cnt1 = cnt + R0 - L0;\r\n\
    \      T t1 = Mono::op(t, seg[d].prod(L0, R0));\r\n      if (check(y1, cnt1, t1))\
    \ {\r\n        y = y1, cnt = cnt1, t = t1, L = L1, R = R1;\r\n      } else {\r\
    \n        L = L0, R = R0;\r\n      }\r\n    }\r\n    return {y, cnt, t};\r\n \
    \ }\r\n\r\n  // [L,R) x [0,y) \u3067\u306E check(y, cnt, prod) \u304C true \u3068\
    \u306A\u308B\u6700\u5927\u306E (Y,cnt,prod)\r\n  template <typename F>\r\n  tuple<Y,\
    \ int, T> max_right_many(F check, vc<pair<int, int>> LR) const {\r\n    assert(limit\
    \ < infty<Y>);\r\n    int cnt = 0;\r\n    Y y = 0;\r\n    T t = Mono::unit();\r\
    \n    T t_all = Mono::unit();\r\n    int cnt_all = 0;\r\n    for (auto& [l, r]\
    \ : LR)\r\n      t_all = Mono::op(t_all, prod_all(l, r)), cnt_all += r - l;\r\n\
    \    assert(check(0, 0, Mono::unit()));\r\n    if (check(limit, cnt_all, t_all))\
    \ {\r\n      y = binary_search([&](Y y) -> bool { return check(y, cnt_all, t_all);\
    \ },\r\n                        limit, infty<Y> + 1);\r\n      return {y, cnt_all,\
    \ t_all};\r\n    }\r\n    for (int d = log - 1; d >= 0; --d) {\r\n      Y y1 =\
    \ Y(1) << d;\r\n      T t1 = t;\r\n      int cnt1 = 0;\r\n      for (auto& [L,\
    \ R] : LR) {\r\n        auto [L0, R0, L1, R1] = get_subtree(d + 1, L, R);\r\n\
    \        cnt1 += R0 - L0;\r\n        t1 = Mono::op(t1, seg[d].prod(L0, R0));\r\
    \n      }\r\n      if (check(y1, cnt1, t1)) {\r\n        y = y1, cnt = cnt1, t\
    \ = t1;\r\n        for (auto& [L, R] : LR) {\r\n          auto [L0, R0, L1, R1]\
    \ = get_subtree(d + 1, L, R);\r\n          L = L1, R = R1;\r\n        }\r\n  \
    \    } else {\r\n        for (auto& [L, R] : LR) {\r\n          auto [L0, R0,\
    \ L1, R1] = get_subtree(d + 1, L, R);\r\n          L = L0, R = R0;\r\n       \
    \ }\r\n      }\r\n    }\r\n    return {y, cnt, t};\r\n  }\r\n\r\n  // [L,R) x\
    \ [y, inf) \u3067\u306E check(y, cnt, prod) \u304C true \u3068\u306A\u308B\u6700\
    \u5C0F\u306E (y,cnt,prod)\r\n  // cnt==0 \u3060\u3068 true \u3067\u3042\u308B\u3053\
    \u3068\u306F\u4EEE\u5B9A\u3059\u308B\r\n  // https://qoj.ac/contest/1047/problem/5094\r\
    \n  template <typename F>\r\n  tuple<Y, int, T> min_left_many(F check, vc<pair<int,\
    \ int>> LR) const {\r\n    assert(check(limit, 0, Mono::unit()));\r\n    int cnt\
    \ = 0;\r\n    Y y = limit;\r\n    T t = Mono::unit();\r\n    T t_all = Mono::unit();\r\
    \n    int cnt_all = 0;\r\n    for (auto& [l, r] : LR)\r\n      t_all = Mono::op(t_all,\
    \ prod_all(l, r)), cnt_all += r - l;\r\n    if (check(0, cnt_all, t_all)) {\r\n\
    \      return {0, cnt_all, t_all};\r\n    }\r\n    for (int d = log - 1; d >=\
    \ 0; --d) {\r\n      Y y1 = y - (Y(1) << d);\r\n      T t1 = t;\r\n      int cnt1\
    \ = cnt;\r\n      for (auto& [L, R] : LR) {\r\n        auto [L0, R0, L1, R1] =\
    \ get_subtree(d + 1, L, R);\r\n        cnt1 += R1 - L1;\r\n        t1 = Mono::op(t1,\
    \ seg[d].prod(L1, R1));\r\n      }\r\n      if (check(y1, cnt1, t1)) {\r\n   \
    \     y = y1, cnt = cnt1, t = t1;\r\n        SHOW(y);\r\n        for (auto& [L,\
    \ R] : LR) {\r\n          auto [L0, R0, L1, R1] = get_subtree(d + 1, L, R);\r\n\
    \          L = L0, R = R0;\r\n        }\r\n      } else {\r\n        for (auto&\
    \ [L, R] : LR) {\r\n          auto [L0, R0, L1, R1] = get_subtree(d + 1, L, R);\r\
    \n          L = L1, R = R1;\r\n        }\r\n      }\r\n    }\r\n    SHOW(y, cnt,\
    \ t);\r\n    return {y, cnt, t};\r\n  }\r\n};\r\n\r\ntemplate <typename Y, typename\
    \ SEGTREE>\r\nstruct Compressed_Wavelet_Matrix {\r\n  using Mono = typename SEGTREE::MX;\r\
    \n  using T = typename Mono::value_type;\r\n\r\n  int n = 0;\r\n  vc<Y> key;\r\
    \n  Uncompressed_Wavelet_Matrix<int, SEGTREE> wm;\r\n\r\n  Compressed_Wavelet_Matrix()\
    \ = default;\r\n\r\n  // f(i) = {A[i], dat[i]}\r\n  template <typename F>\r\n\
    \  Compressed_Wavelet_Matrix(int n, F f) {\r\n    build(n, f);\r\n  }\r\n\r\n\
    \  Compressed_Wavelet_Matrix(const vc<Y>& A) {\r\n    static_assert(is_same_v<SEGTREE,\
    \ Dummy_Data_Structure>);\r\n    build(A);\r\n  }\r\n\r\n  template <typename\
    \ F>\r\n  void build(int n, F f) {\r\n    this->n = n;\r\n    vc<Y> A(n);\r\n\
    \    vc<T> S(n);\r\n    FOR(i, n) tie(A[i], S[i]) = f(i);\r\n\r\n    key = A;\r\
    \n    UNIQUE(key);\r\n\r\n    wm.build(n, [&](int i) -> pair<int, T> {\r\n   \
    \   int k = LB(key, A[i]);\r\n      return {k, S[i]};\r\n    });\r\n  }\r\n\r\n\
    \  void build(const vc<Y>& A) {\r\n    static_assert(is_same_v<SEGTREE, Dummy_Data_Structure>);\r\
    \n    n = len(A);\r\n    key = A;\r\n    UNIQUE(key);\r\n\r\n    wm.build(n, [&](int\
    \ i) -> pair<int, T> {\r\n      int k = LB(key, A[i]);\r\n      return {k, Mono::unit()};\r\
    \n    });\r\n  }\r\n\r\n  Y kth(int L, int R, int k) const { return key[wm.kth(L,\
    \ R, k)]; }\r\n\r\n  template <bool upper>\r\n  Y median(int L, int R) const {\r\
    \n    return key[wm.template median<upper>(L, R)];\r\n  }\r\n\r\n  // [L,R) x\
    \ [-inf,y)\r\n  int prefix_count(int L, int R, Y y) const {\r\n    return wm.prefix_count(L,\
    \ R, LB(key, y));\r\n  }\r\n\r\n  // [L,R) x [y1,y2)\r\n  int count(int L, int\
    \ R, Y y1, Y y2) const {\r\n    return wm.count(L, R, LB(key, y1), LB(key, y2));\r\
    \n  }\r\n\r\n  // [L,R) x [-inf,y)\r\n  T prefix_prod(int L, int R, Y y) const\
    \ {\r\n    return wm.prefix_prod(L, R, LB(key, y));\r\n  }\r\n\r\n  // [L,R) x\
    \ [y1,y2)\r\n  T prod(int L, int R, Y y1, Y y2) const {\r\n    return wm.prod(L,\
    \ R, LB(key, y1), LB(key, y2));\r\n  }\r\n\r\n  T prod_all(int L, int R) const\
    \ { return wm.prod_all(L, R); }\r\n\r\n  // [L,R) x [-inf,y)\r\n  pair<int, T>\
    \ prefix_count_and_prod(int L, int R, Y y) const {\r\n    return wm.prefix_count_and_prod(L,\
    \ R, LB(key, y));\r\n  }\r\n\r\n  // [L,R) x [y1,y2)\r\n  pair<int, T> count_and_prod(int\
    \ L, int R, Y y1, Y y2) const {\r\n    return wm.count_and_prod(L, R, LB(key,\
    \ y1), LB(key, y2));\r\n  }\r\n\r\n  void set(int i, T t) { wm.set(i, t); }\r\n\
    \r\n  void multiply(int i, T t) { wm.multiply(i, t); }\r\n\r\n  void add(int i,\
    \ T t) { wm.add(i, t); }\r\n};\r\n\r\ntemplate <typename Y, bool compress, typename\
    \ SEGTREE = Dummy_Data_Structure>\r\nusing Wavelet_Matrix =\r\n    conditional_t<compress,\
    \ Compressed_Wavelet_Matrix<Y, SEGTREE>,\r\n                  Uncompressed_Wavelet_Matrix<Y,\
    \ SEGTREE>>;\r\n#line 1 \"ds/index_compression.hpp\"\ntemplate <typename T>\n\
    struct Index_Compression_DISTINCT_SMALL {\n  int mi, ma;\n  vc<T> dat;\n  vc<T>\
    \ build(vc<int> X) {\n    mi = 0, ma = -1;\n    if (!X.empty()) mi = MIN(X), ma\
    \ = MAX(X);\n    dat.assign(ma - mi + 2, 0);\n    for (auto& x : X) dat[x - mi\
    \ + 1]++;\n    FOR(i, len(dat) - 1) dat[i + 1] += dat[i];\n    for (auto& x :\
    \ X) {\n      x = dat[x - mi]++;\n    }\n    FOR_R(i, 1, len(dat)) dat[i] = dat[i\
    \ - 1];\n    dat[0] = 0;\n    return X;\n  }\n  int size() { return len(dat);\
    \ }\n  int operator()(ll x) { return dat[clamp<ll>(x - mi, 0, ma - mi + 1)]; }\n\
    };\n\ntemplate <typename T>\nstruct Index_Compression_SAME_SMALL {\n  int mi,\
    \ ma;\n  vc<T> dat;\n  vc<T> build(vc<T> X) {\n    mi = 0, ma = -1;\n    if (!X.empty())\
    \ mi = MIN(X), ma = MAX(X);\n    dat.assign(ma - mi + 2, 0);\n    for (auto& x\
    \ : X) dat[x - mi + 1] = 1;\n    FOR(i, len(dat) - 1) dat[i + 1] += dat[i];\n\
    \    for (auto& x : X) {\n      x = dat[x - mi];\n    }\n    return X;\n  }\n\
    \  int size() { return len(dat); }\n  int operator()(ll x) { return dat[clamp<ll>(x\
    \ - mi, 0, ma - mi + 1)]; }\n};\n\ntemplate <typename T>\nstruct Index_Compression_SAME_LARGE\
    \ {\n  vc<T> dat;\n  vc<int> build(vc<T> X) {\n    vc<int> I = argsort(X);\n \
    \   vc<int> res(len(X));\n    for (auto& i : I) {\n      if (!dat.empty() && dat.back()\
    \ == X[i]) {\n        res[i] = len(dat) - 1;\n      } else {\n        res[i] =\
    \ len(dat);\n        dat.eb(X[i]);\n      }\n    }\n    dat.shrink_to_fit();\n\
    \    return res;\n  }\n  int size() { return len(dat); }\n  int operator()(T x)\
    \ { return LB(dat, x); }\n};\n\ntemplate <typename T>\nstruct Index_Compression_DISTINCT_LARGE\
    \ {\n  vc<T> dat;\n  vc<int> build(vc<T> X) {\n    vc<int> I = argsort(X);\n \
    \   vc<int> res(len(X));\n    for (auto& i : I) {\n      res[i] = len(dat), dat.eb(X[i]);\n\
    \    }\n    dat.shrink_to_fit();\n    return res;\n  }\n  int size() { return\
    \ len(dat); }\n  int operator()(T x) { return LB(dat, x); }\n};\n\ntemplate <typename\
    \ T, bool SMALL>\nusing Index_Compression_DISTINCT =\n    typename std::conditional<SMALL,\
    \ Index_Compression_DISTINCT_SMALL<T>,\n                              Index_Compression_DISTINCT_LARGE<T>>::type;\n\
    template <typename T, bool SMALL>\nusing Index_Compression_SAME =\n    typename\
    \ std::conditional<SMALL, Index_Compression_SAME_SMALL<T>,\n                 \
    \             Index_Compression_SAME_LARGE<T>>::type;\n\n// SAME: [2,3,2] -> [0,1,0]\n\
    // DISTINCT: [2,2,3] -> [0,2,1]\n// build \u3067\u5217\u3092\u5727\u7E2E\u3057\
    \u3066\u304F\u308C\u308B. \u305D\u306E\u3042\u3068\n// (x): lower_bound(X,x) \u3092\
    \u304B\u3048\u3059\ntemplate <typename T, bool SAME, bool SMALL>\nusing Index_Compression\
    \ =\n    typename std::conditional<SAME, Index_Compression_SAME<T, SMALL>,\n \
    \                             Index_Compression_DISTINCT<T, SMALL>>::type;\n#line\
    \ 3 \"ds/wavelet_matrix/wavelet_matrix_2d_range.hpp\"\n\ntemplate <typename XY,\
    \ bool compress_X, bool compress_Y,\n          typename SEGTREE = Dummy_Data_Structure>\n\
    struct Wavelet_Matrix_2D_Range {\n  // \u70B9\u7FA4\u3092 X \u6607\u9806\u306B\
    \u4E26\u3079\u308B.\n  Wavelet_Matrix<XY, compress_Y, SEGTREE> WM;\n  using Mono\
    \ = typename SEGTREE::MX;\n  using T = typename Mono::value_type;\n  static_assert(Mono::commute);\n\
    \n  Index_Compression<XY, false, !compress_X> IDX_X;\n\n  int n;\n  vc<int> new_idx;\n\
    \n  template <typename F>\n  Wavelet_Matrix_2D_Range(int n, F f) {\n    build(n,\
    \ f);\n  }\n\n  template <typename F>\n  void build(int m, F f) {\n    n = m;\n\
    \    vc<XY> X(n), Y(n);\n    vc<T> S(n);\n    FOR(i, n) {\n      auto tmp = f(i);\n\
    \      X[i] = get<0>(tmp), Y[i] = get<1>(tmp), S[i] = get<2>(tmp);\n    }\n  \
    \  new_idx = IDX_X.build(X);\n    vc<int> I(n);\n    FOR(i, n) I[new_idx[i]] =\
    \ i;\n    Y = rearrange(Y, I);\n    S = rearrange(S, I);\n    WM.build(n, [&](int\
    \ i) -> pair<XY, T> { return {Y[i], S[i]}; });\n  }\n\n  int count(XY x1, XY x2,\
    \ XY y1, XY y2) {\n    return WM.count(IDX_X(x1), IDX_X(x2), y1, y2);\n  }\n\n\
    \  // [L,R) x [-inf,y)\n  pair<int, T> prefix_count_and_prod(XY x1, XY x2, XY\
    \ y) {\n    return WM.prefix_count_and_prod(IDX_X(x1), IDX_X(x2), y);\n  }\n\n\
    \  // [L,R) x [y1,y2)\n  pair<int, T> count_and_prod(XY x1, XY x2, XY y1, XY y2)\
    \ {\n    return WM.count_and_prod(IDX_X(x1), IDX_X(x2), y1, y2);\n  }\n\n  //\
    \ [L,R) x [-inf,inf)\n  T prod_all(XY x1, XY x2) { return WM.prod_all(IDX_X(x1),\
    \ IDX_X(x2)); }\n  // [L,R) x [-inf,y)\n  T prefix_prod(XY x1, XY x2, XY y) {\n\
    \    return WM.prefix_prod(IDX_X(x1), IDX_X(x2), y);\n  }\n  // [L,R) x [y1,y2)\n\
    \  T prod(XY x1, XY x2, XY y1, XY y2) {\n    return WM.prod(IDX_X(x1), IDX_X(x2),\
    \ y1, y2);\n  }\n  // i \u306F\u6700\u521D\u306B\u6E21\u3057\u305F\u30A4\u30F3\
    \u30C7\u30C3\u30AF\u30B9\n  void set(int i, T t) { WM.set(new_idx[i], t); }\n\
    \  // i \u306F\u6700\u521D\u306B\u6E21\u3057\u305F\u30A4\u30F3\u30C7\u30C3\u30AF\
    \u30B9\n  void multiply(int i, T t) { WM.multiply(new_idx[i], t); }\n  void add(int\
    \ i, T t) { WM.multiply(new_idx[i], t); }\n};\n"
  code: "#include \"ds/wavelet_matrix/wavelet_matrix.hpp\"\n#include \"ds/index_compression.hpp\"\
    \n\ntemplate <typename XY, bool compress_X, bool compress_Y,\n          typename\
    \ SEGTREE = Dummy_Data_Structure>\nstruct Wavelet_Matrix_2D_Range {\n  // \u70B9\
    \u7FA4\u3092 X \u6607\u9806\u306B\u4E26\u3079\u308B.\n  Wavelet_Matrix<XY, compress_Y,\
    \ SEGTREE> WM;\n  using Mono = typename SEGTREE::MX;\n  using T = typename Mono::value_type;\n\
    \  static_assert(Mono::commute);\n\n  Index_Compression<XY, false, !compress_X>\
    \ IDX_X;\n\n  int n;\n  vc<int> new_idx;\n\n  template <typename F>\n  Wavelet_Matrix_2D_Range(int\
    \ n, F f) {\n    build(n, f);\n  }\n\n  template <typename F>\n  void build(int\
    \ m, F f) {\n    n = m;\n    vc<XY> X(n), Y(n);\n    vc<T> S(n);\n    FOR(i, n)\
    \ {\n      auto tmp = f(i);\n      X[i] = get<0>(tmp), Y[i] = get<1>(tmp), S[i]\
    \ = get<2>(tmp);\n    }\n    new_idx = IDX_X.build(X);\n    vc<int> I(n);\n  \
    \  FOR(i, n) I[new_idx[i]] = i;\n    Y = rearrange(Y, I);\n    S = rearrange(S,\
    \ I);\n    WM.build(n, [&](int i) -> pair<XY, T> { return {Y[i], S[i]}; });\n\
    \  }\n\n  int count(XY x1, XY x2, XY y1, XY y2) {\n    return WM.count(IDX_X(x1),\
    \ IDX_X(x2), y1, y2);\n  }\n\n  // [L,R) x [-inf,y)\n  pair<int, T> prefix_count_and_prod(XY\
    \ x1, XY x2, XY y) {\n    return WM.prefix_count_and_prod(IDX_X(x1), IDX_X(x2),\
    \ y);\n  }\n\n  // [L,R) x [y1,y2)\n  pair<int, T> count_and_prod(XY x1, XY x2,\
    \ XY y1, XY y2) {\n    return WM.count_and_prod(IDX_X(x1), IDX_X(x2), y1, y2);\n\
    \  }\n\n  // [L,R) x [-inf,inf)\n  T prod_all(XY x1, XY x2) { return WM.prod_all(IDX_X(x1),\
    \ IDX_X(x2)); }\n  // [L,R) x [-inf,y)\n  T prefix_prod(XY x1, XY x2, XY y) {\n\
    \    return WM.prefix_prod(IDX_X(x1), IDX_X(x2), y);\n  }\n  // [L,R) x [y1,y2)\n\
    \  T prod(XY x1, XY x2, XY y1, XY y2) {\n    return WM.prod(IDX_X(x1), IDX_X(x2),\
    \ y1, y2);\n  }\n  // i \u306F\u6700\u521D\u306B\u6E21\u3057\u305F\u30A4\u30F3\
    \u30C7\u30C3\u30AF\u30B9\n  void set(int i, T t) { WM.set(new_idx[i], t); }\n\
    \  // i \u306F\u6700\u521D\u306B\u6E21\u3057\u305F\u30A4\u30F3\u30C7\u30C3\u30AF\
    \u30B9\n  void multiply(int i, T t) { WM.multiply(new_idx[i], t); }\n  void add(int\
    \ i, T t) { WM.multiply(new_idx[i], t); }\n};"
  dependsOn:
  - ds/wavelet_matrix/wavelet_matrix.hpp
  - ds/bit_vector.hpp
  - ds/dummy_data_structure.hpp
  - alg/monoid/dummy.hpp
  - ds/index_compression.hpp
  isVerificationFile: false
  path: ds/wavelet_matrix/wavelet_matrix_2d_range.hpp
  requiredBy: []
  timestamp: '2026-04-13 21:44:04+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/2_library_checker/data_structure/rectangle_sum_wm_abel.test.cpp
  - test/2_library_checker/data_structure/rectangle_sum_wm.test.cpp
  - test/2_library_checker/data_structure/point_add_rectangle_sum_wm_mono.test.cpp
  - test/2_library_checker/data_structure/point_add_rectangle_sum_wm_abel.test.cpp
  - test/3_yukicoder/1625_2.test.cpp
  - test/3_yukicoder/1919_2.test.cpp
  - test/3_yukicoder/2859.test.cpp
  - test/3_yukicoder/1600_2.test.cpp
documentation_of: ds/wavelet_matrix/wavelet_matrix_2d_range.hpp
layout: document
redirect_from:
- /library/ds/wavelet_matrix/wavelet_matrix_2d_range.hpp
- /library/ds/wavelet_matrix/wavelet_matrix_2d_range.hpp.html
title: ds/wavelet_matrix/wavelet_matrix_2d_range.hpp
---
