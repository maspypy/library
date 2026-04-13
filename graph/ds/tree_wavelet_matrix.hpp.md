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
  - icon: ':question:'
    path: ds/hashmap.hpp
    title: ds/hashmap.hpp
  - icon: ':question:'
    path: ds/wavelet_matrix/wavelet_matrix.hpp
    title: ds/wavelet_matrix/wavelet_matrix.hpp
  - icon: ':question:'
    path: graph/base.hpp
    title: graph/base.hpp
  - icon: ':question:'
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
    \    return ans;\n  }\n};\n#line 1 \"alg/monoid/dummy.hpp\"\nstruct Monoid_Dummy\
    \ {\n  using value_type = char;\n  static constexpr bool commute = true;\n  static\
    \ value_type op(value_type, value_type) { return 0; }\n  static value_type unit()\
    \ { return 0; }\n};\n#line 2 \"ds/dummy_data_structure.hpp\"\n\nstruct Dummy_Data_Structure\
    \ {\n  using MX = Monoid_Dummy;\n  using T = typename MX::value_type;\n  void\
    \ build(const vc<T>& A) {}\n};\n#line 3 \"ds/wavelet_matrix/wavelet_matrix.hpp\"\
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
    \ f, int L, int R, Y y) const {\r\n    assert(0 <= y && y <= limit);\r\n    if\
    \ (y == 0) return;\r\n    if (y == limit) {\r\n      f(log, L, R);\r\n      return;\r\
    \n    }\r\n    FOR_R(d, log) {\r\n      auto [L0, R0, L1, R1] = get_subtree(d\
    \ + 1, L, R);\r\n      if (y >> d & 1) {\r\n        f(d, L0, R0);\r\n        L\
    \ = L1, R = R1;\r\n      } else {\r\n        L = L0, R = R0;\r\n      }\r\n  \
    \  }\r\n  }\r\n\r\n  template <typename F>\r\n  void work_range(F f, int L, int\
    \ R, Y y1, Y y2) const {\r\n    assert(0 <= y1 && y1 <= y2 && y2 <= limit);\r\n\
    \    if (y1 == 0) return work_prefix(f, L, R, y2);\r\n    auto dfs = [&](auto&\
    \ dfs, int d, int L, int R, Y y1, Y y2) -> void {\r\n      if (y1 == y2) return;\r\
    \n      if (y1 == 0 && y2 == Y(1) << d) {\r\n        f(d, L, R);\r\n        return;\r\
    \n      }\r\n      assert(d > 0);\r\n      auto [L0, R0, L1, R1] = get_subtree(d,\
    \ L, R);\r\n      Y m = (Y(1) << (d - 1));\r\n\r\n      if (y2 <= m) {\r\n   \
    \     dfs(dfs, d - 1, L0, R0, y1, y2);\r\n      } else if (y1 >= m) {\r\n    \
    \    dfs(dfs, d - 1, L1, R1, y1 - m, y2 - m);\r\n      } else {\r\n        dfs(dfs,\
    \ d - 1, L0, R0, y1, m);\r\n        dfs(dfs, d - 1, L1, R1, 0, y2 - m);\r\n  \
    \    }\r\n    };\r\n    dfs(dfs, log, L, R, y1, y2);\r\n  }\r\n\r\n  // [L,R)\
    \ x [0,y)\r\n  int prefix_count(int L, int R, Y y) const {\r\n    int cnt = 0;\r\
    \n    work_prefix([&](int d, int a, int b) { cnt += b - a; }, L, R, y);\r\n  \
    \  return cnt;\r\n  }\r\n\r\n  // [L,R) x [y1,y2)\r\n  int count(int L, int R,\
    \ Y y1, Y y2) const {\r\n    return prefix_count(L, R, y2) - prefix_count(L, R,\
    \ y1);\r\n  }\r\n\r\n  // [L,R) x [0,y)\r\n  T prefix_prod(int L, int R, Y y)\
    \ const {\r\n    T ans = Mono::unit();\r\n    work_prefix(\r\n        [&](int\
    \ d, int a, int b) { ans = Mono::op(ans, seg[d].prod(a, b)); }, L,\r\n       \
    \ R, y);\r\n    return ans;\r\n  }\r\n  // [L,R) x [y1,y2)\r\n  T prod(int L,\
    \ int R, Y y1, Y y2) const {\r\n    T ans = Mono::unit();\r\n    work_range(\r\
    \n        [&](int d, int a, int b) { ans = Mono::op(ans, seg[d].prod(a, b)); },\
    \ L,\r\n        R, y1, y2);\r\n    return ans;\r\n  }\r\n  T prod_all(int L, int\
    \ R) const { return seg[log].prod(L, R); }\r\n\r\n  // [L,R) x [0,y)\r\n  pair<int,\
    \ T> prefix_count_and_prod(int L, int R, Y y) const {\r\n    pair<int, T> ans\
    \ = {0, Mono::unit()};\r\n    work_prefix(\r\n        [&](int d, int a, int b)\
    \ {\r\n          ans.fi += b - a;\r\n          ans.se = Mono::op(ans.se, seg[d].prod(a,\
    \ b));\r\n        },\r\n        L, R, y);\r\n    return ans;\r\n  }\r\n  // [L,R)\
    \ x [y1,y2)\r\n  pair<int, T> count_and_prod(int L, int R, Y y1, Y y2) const {\r\
    \n    pair<int, T> ans = {0, Mono::unit()};\r\n    work_range(\r\n        [&](int\
    \ d, int a, int b) {\r\n          ans.fi += b - a;\r\n          ans.se = Mono::op(ans.se,\
    \ seg[d].prod(a, b));\r\n        },\r\n        L, R, y1, y2);\r\n    return ans;\r\
    \n  }\r\n\r\n  Y kth(int L, int R, int k) const {\r\n    assert(0 <= k && k <\
    \ R - L);\r\n    Y ans = 0;\r\n    for (int d = log - 1; d >= 0; --d) {\r\n  \
    \    auto [L0, R0, L1, R1] = get_subtree(d + 1, L, R);\r\n      if (k < R0 - L0)\
    \ {\r\n        L = L0, R = R0;\r\n      } else {\r\n        ans |= Y(1) << d;\r\
    \n        k -= R0 - L0, L = L1, R = R1;\r\n      }\r\n    }\r\n    return ans;\r\
    \n  }\r\n\r\n  template <bool upper>\r\n  Y median(int L, int R) const {\r\n \
    \   assert(0 <= L && L < R && R <= n);\r\n    int k = (upper ? (R - L) / 2 : (R\
    \ - L - 1) / 2);\r\n    return kth(L, R, k);\r\n  }\r\n\r\n  void set(int i, T\
    \ t) {\r\n    assert(0 <= i && i < n);\r\n    work_point([&](int d, int i) { seg[d].set(i,\
    \ t); }, i);\r\n  }\r\n  void multiply(int i, T t) {\r\n    assert(0 <= i && i\
    \ < n);\r\n    work_point([&](int d, int i) { seg[d].multiply(i, t); }, i);\r\n\
    \  }\r\n  void add(int i, T t) {\r\n    assert(0 <= i && i < n);\r\n    work_point([&](int\
    \ d, int i) { seg[d].add(i, t); }, i);\r\n  }\r\n\r\n  // [L,R) x [0,y) \u3067\
    \u306E check(y, cnt, prod) \u304C true \u3068\u306A\u308B\u6700\u5927\u306E (Y,cnt,prod)\r\
    \n  template <typename F>\r\n  tuple<Y, int, T> max_right(F check, int L, int\
    \ R) const {\r\n    assert(limit < infty<Y>);\r\n    int cnt = 0;\r\n    Y y =\
    \ 0;\r\n    T t = Mono::unit();\r\n    T t_all = seg[log].prod(L, R);\r\n    assert(check(0,\
    \ 0, Mono::unit()));\r\n    if (check(limit, R - L, t_all)) {\r\n      y = binary_search([&](Y\
    \ y) -> bool { return check(y, R - L, t_all); },\r\n                        limit,\
    \ infty<Y> + 1);\r\n      return {y, R - L, t_all};\r\n    }\r\n    for (int d\
    \ = log - 1; d >= 0; --d) {\r\n      auto [L0, R0, L1, R1] = get_subtree(d + 1,\
    \ L, R);\r\n      Y y1 = y | Y(1) << d;\r\n      int cnt1 = cnt + R0 - L0;\r\n\
    \      T t1 = Mono::op(t, seg[d].prod(L0, R0));\r\n      if (check(y1, cnt1, t1))\
    \ {\r\n        y = y1, cnt = cnt1, t = t1, L = L1, R = R1;\r\n      } else {\r\
    \n        L = L0, R = R0;\r\n      }\r\n    }\r\n    return {y, cnt, t};\r\n \
    \ }\r\n};\r\n\r\ntemplate <typename Y, typename SEGTREE>\r\nstruct Compressed_Wavelet_Matrix\
    \ {\r\n  using Mono = typename SEGTREE::MX;\r\n  using T = typename Mono::value_type;\r\
    \n\r\n  int n = 0;\r\n  vc<Y> key;\r\n  Uncompressed_Wavelet_Matrix<int, SEGTREE>\
    \ wm;\r\n\r\n  Compressed_Wavelet_Matrix() = default;\r\n\r\n  // f(i) = {A[i],\
    \ dat[i]}\r\n  template <typename F>\r\n  Compressed_Wavelet_Matrix(int n, F f)\
    \ {\r\n    build(n, f);\r\n  }\r\n\r\n  Compressed_Wavelet_Matrix(const vc<Y>&\
    \ A) {\r\n    static_assert(is_same_v<SEGTREE, Dummy_Data_Structure>);\r\n   \
    \ build(A);\r\n  }\r\n\r\n  template <typename F>\r\n  void build(int n, F f)\
    \ {\r\n    this->n = n;\r\n    vc<Y> A(n);\r\n    vc<T> S(n);\r\n    FOR(i, n)\
    \ tie(A[i], S[i]) = f(i);\r\n\r\n    key = A;\r\n    UNIQUE(key);\r\n\r\n    wm.build(n,\
    \ [&](int i) -> pair<int, T> {\r\n      int k = LB(key, A[i]);\r\n      return\
    \ {k, S[i]};\r\n    });\r\n  }\r\n\r\n  void build(const vc<Y>& A) {\r\n    static_assert(is_same_v<SEGTREE,\
    \ Dummy_Data_Structure>);\r\n    n = len(A);\r\n    key = A;\r\n    UNIQUE(key);\r\
    \n\r\n    wm.build(n, [&](int i) -> pair<int, T> {\r\n      int k = LB(key, A[i]);\r\
    \n      return {k, Mono::unit()};\r\n    });\r\n  }\r\n\r\n  Y kth(int L, int\
    \ R, int k) const { return key[wm.kth(L, R, k)]; }\r\n\r\n  template <bool upper>\r\
    \n  Y median(int L, int R) const {\r\n    return key[wm.template median<upper>(L,\
    \ R)];\r\n  }\r\n\r\n  // [L,R) x [-inf,y)\r\n  int prefix_count(int L, int R,\
    \ Y y) const {\r\n    return wm.prefix_count(L, R, LB(key, y));\r\n  }\r\n\r\n\
    \  // [L,R) x [y1,y2)\r\n  int count(int L, int R, Y y1, Y y2) const {\r\n   \
    \ return wm.count(L, R, LB(key, y1), LB(key, y2));\r\n  }\r\n\r\n  // [L,R) x\
    \ [-inf,y)\r\n  T prefix_prod(int L, int R, Y y) const {\r\n    return wm.prefix_prod(L,\
    \ R, LB(key, y));\r\n  }\r\n\r\n  // [L,R) x [y1,y2)\r\n  T prod(int L, int R,\
    \ Y y1, Y y2) const {\r\n    return wm.prod(L, R, LB(key, y1), LB(key, y2));\r\
    \n  }\r\n\r\n  T prod_all(int L, int R) const { return wm.prod_all(L, R); }\r\n\
    \r\n  // [L,R) x [-inf,y)\r\n  pair<int, T> prefix_count_and_prod(int L, int R,\
    \ Y y) const {\r\n    return wm.prefix_count_and_prod(L, R, LB(key, y));\r\n \
    \ }\r\n\r\n  // [L,R) x [y1,y2)\r\n  pair<int, T> count_and_prod(int L, int R,\
    \ Y y1, Y y2) const {\r\n    return wm.count_and_prod(L, R, LB(key, y1), LB(key,\
    \ y2));\r\n  }\r\n\r\n  void set(int i, T t) { wm.set(i, t); }\r\n\r\n  void multiply(int\
    \ i, T t) { wm.multiply(i, t); }\r\n\r\n  void add(int i, T t) { wm.add(i, t);\
    \ }\r\n};\r\n\r\ntemplate <typename Y, bool compress, typename SEGTREE = Dummy_Data_Structure>\r\
    \nusing Wavelet_Matrix =\r\n    conditional_t<compress, Compressed_Wavelet_Matrix<Y,\
    \ SEGTREE>,\r\n                  Uncompressed_Wavelet_Matrix<Y, SEGTREE>>;\r\n\
    #line 2 \"graph/tree.hpp\"\n\r\n#line 2 \"ds/hashmap.hpp\"\n\r\n// u64 -> Val\r\
    \ntemplate <typename Val>\r\nstruct HashMap {\r\n  // n \u306F\u5165\u308C\u305F\
    \u3044\u3082\u306E\u306E\u500B\u6570\u3067 ok\r\n  HashMap(u32 n = 0) { build(n);\
    \ }\r\n  void build(u32 n) {\r\n    u32 k = 8;\r\n    while (k < n * 2) k *= 2;\r\
    \n    cap = k / 2, mask = k - 1;\r\n    key.resize(k), val.resize(k), used.assign(k,\
    \ 0);\r\n  }\r\n\r\n  // size \u3092\u4FDD\u3063\u305F\u307E\u307E. size=0 \u306B\
    \u3059\u308B\u3068\u304D\u306F build \u3059\u308B\u3053\u3068.\r\n  void clear()\
    \ {\r\n    used.assign(len(used), 0);\r\n    cap = (mask + 1) / 2;\r\n  }\r\n\
    \  int size() { return len(used) / 2 - cap; }\r\n\r\n  int index(const u64& k)\
    \ {\r\n    int i = 0;\r\n    for (i = hash(k); used[i] && key[i] != k; i = (i\
    \ + 1) & mask) {}\r\n    return i;\r\n  }\r\n\r\n  Val& operator[](const u64&\
    \ k) {\r\n    if (cap == 0) extend();\r\n    int i = index(k);\r\n    if (!used[i])\
    \ { used[i] = 1, key[i] = k, val[i] = Val{}, --cap; }\r\n    return val[i];\r\n\
    \  }\r\n\r\n  Val get(const u64& k, Val default_value) {\r\n    int i = index(k);\r\
    \n    return (used[i] ? val[i] : default_value);\r\n  }\r\n\r\n  bool count(const\
    \ u64& k) {\r\n    int i = index(k);\r\n    return used[i] && key[i] == k;\r\n\
    \  }\r\n\r\n  // f(key, val)\r\n  template <typename F>\r\n  void enumerate_all(F\
    \ f) {\r\n    FOR(i, len(used)) if (used[i]) f(key[i], val[i]);\r\n  }\r\n\r\n\
    private:\r\n  u32 cap, mask;\r\n  vc<u64> key;\r\n  vc<Val> val;\r\n  vc<bool>\
    \ used;\r\n\r\n  u64 hash(u64 x) {\r\n    static const u64 FIXED_RANDOM = std::chrono::steady_clock::now().time_since_epoch().count();\r\
    \n    x += FIXED_RANDOM;\r\n    x = (x ^ (x >> 30)) * 0xbf58476d1ce4e5b9;\r\n\
    \    x = (x ^ (x >> 27)) * 0x94d049bb133111eb;\r\n    return (x ^ (x >> 31)) &\
    \ mask;\r\n  }\r\n\r\n  void extend() {\r\n    vc<pair<u64, Val>> dat;\r\n   \
    \ dat.reserve(len(used) / 2 - cap);\r\n    FOR(i, len(used)) {\r\n      if (used[i])\
    \ dat.eb(key[i], val[i]);\r\n    }\r\n    build(2 * len(dat));\r\n    for (auto&\
    \ [a, b]: dat) (*this)[a] = b;\r\n  }\r\n};\n#line 3 \"graph/base.hpp\"\n\ntemplate\
    \ <typename T>\nstruct Edge {\n  int frm, to;\n  T cost;\n  int id;\n};\n\ntemplate\
    \ <typename T = int, bool directed = false>\nstruct Graph {\n  static constexpr\
    \ bool is_directed = directed;\n  int N, M;\n  using cost_type = T;\n  using edge_type\
    \ = Edge<T>;\n  vector<edge_type> edges;\n  vector<int> indptr;\n  vector<edge_type>\
    \ csr_edges;\n  vc<int> vc_deg, vc_indeg, vc_outdeg;\n  bool prepared;\n\n  class\
    \ OutgoingEdges {\n  public:\n    OutgoingEdges(const Graph* G, int l, int r)\
    \ : G(G), l(l), r(r) {}\n\n    const edge_type* begin() const {\n      if (l ==\
    \ r) { return 0; }\n      return &G->csr_edges[l];\n    }\n\n    const edge_type*\
    \ end() const {\n      if (l == r) { return 0; }\n      return &G->csr_edges[r];\n\
    \    }\n\n  private:\n    const Graph* G;\n    int l, r;\n  };\n\n  bool is_prepared()\
    \ { return prepared; }\n\n  Graph() : N(0), M(0), prepared(0) {}\n  Graph(int\
    \ N) : N(N), M(0), prepared(0) {}\n\n  void build(int n) {\n    N = n, M = 0;\n\
    \    prepared = 0;\n    edges.clear();\n    indptr.clear();\n    csr_edges.clear();\n\
    \    vc_deg.clear();\n    vc_indeg.clear();\n    vc_outdeg.clear();\n  }\n\n \
    \ void add(int frm, int to, T cost = 1, int i = -1) {\n    assert(!prepared);\n\
    \    assert(0 <= frm && 0 <= to && to < N);\n    if (i == -1) i = M;\n    auto\
    \ e = edge_type({frm, to, cost, i});\n    edges.eb(e);\n    ++M;\n  }\n\n#ifdef\
    \ FASTIO\n  // wt, off\n  void read_tree(bool wt = false, int off = 1) { read_graph(N\
    \ - 1, wt, off); }\n\n  void read_graph(int M, bool wt = false, int off = 1) {\n\
    \    for (int m = 0; m < M; ++m) {\n      INT(a, b);\n      a -= off, b -= off;\n\
    \      if (!wt) {\n        add(a, b);\n      } else {\n        T c;\n        read(c);\n\
    \        add(a, b, c);\n      }\n    }\n    build();\n  }\n#endif\n\n  void build()\
    \ {\n    assert(!prepared);\n    prepared = true;\n    indptr.assign(N + 1, 0);\n\
    \    for (auto&& e: edges) {\n      indptr[e.frm + 1]++;\n      if (!directed)\
    \ indptr[e.to + 1]++;\n    }\n    for (int v = 0; v < N; ++v) { indptr[v + 1]\
    \ += indptr[v]; }\n    auto counter = indptr;\n    csr_edges.resize(indptr.back()\
    \ + 1);\n    for (auto&& e: edges) {\n      csr_edges[counter[e.frm]++] = e;\n\
    \      if (!directed) csr_edges[counter[e.to]++] = edge_type({e.to, e.frm, e.cost,\
    \ e.id});\n    }\n  }\n\n  OutgoingEdges operator[](int v) const {\n    assert(prepared);\n\
    \    return {this, indptr[v], indptr[v + 1]};\n  }\n\n  vc<int> deg_array() {\n\
    \    if (vc_deg.empty()) calc_deg();\n    return vc_deg;\n  }\n\n  pair<vc<int>,\
    \ vc<int>> deg_array_inout() {\n    if (vc_indeg.empty()) calc_deg_inout();\n\
    \    return {vc_indeg, vc_outdeg};\n  }\n\n  int deg(int v) {\n    if (vc_deg.empty())\
    \ calc_deg();\n    return vc_deg[v];\n  }\n\n  int in_deg(int v) {\n    if (vc_indeg.empty())\
    \ calc_deg_inout();\n    return vc_indeg[v];\n  }\n\n  int out_deg(int v) {\n\
    \    if (vc_outdeg.empty()) calc_deg_inout();\n    return vc_outdeg[v];\n  }\n\
    \n#ifdef FASTIO\n  void debug() {\n#ifdef LOCAL\n    print(\"Graph\");\n    if\
    \ (!prepared) {\n      print(\"frm to cost id\");\n      for (auto&& e: edges)\
    \ print(e.frm, e.to, e.cost, e.id);\n    } else {\n      print(\"indptr\", indptr);\n\
    \      print(\"frm to cost id\");\n      FOR(v, N) for (auto&& e: (*this)[v])\
    \ print(e.frm, e.to, e.cost, e.id);\n    }\n#endif\n  }\n#endif\n\n  vc<int> new_idx;\n\
    \  vc<bool> used_e;\n\n  // G \u306B\u304A\u3051\u308B\u9802\u70B9 V[i] \u304C\
    \u3001\u65B0\u3057\u3044\u30B0\u30E9\u30D5\u3067 i \u306B\u306A\u308B\u3088\u3046\
    \u306B\u3059\u308B\n  // {G, es}\n  // sum(deg(v)) \u306E\u8A08\u7B97\u91CF\u306B\
    \u306A\u3063\u3066\u3044\u3066\u3001\n  // \u65B0\u3057\u3044\u30B0\u30E9\u30D5\
    \u306E n+m \u3088\u308A\u5927\u304D\u3044\u53EF\u80FD\u6027\u304C\u3042\u308B\u306E\
    \u3067\u6CE8\u610F\n  Graph<T, directed> rearrange(vc<int> V, bool keep_eid =\
    \ 0) {\n    if (len(new_idx) != N) new_idx.assign(N, -1);\n    int n = len(V);\n\
    \    FOR(i, n) new_idx[V[i]] = i;\n    Graph<T, directed> G(n);\n    vc<int> history;\n\
    \    FOR(i, n) {\n      for (auto&& e: (*this)[V[i]]) {\n        if (len(used_e)\
    \ <= e.id) used_e.resize(e.id + 1);\n        if (used_e[e.id]) continue;\n   \
    \     int a = e.frm, b = e.to;\n        if (new_idx[a] != -1 && new_idx[b] !=\
    \ -1) {\n          history.eb(e.id);\n          used_e[e.id] = 1;\n          int\
    \ eid = (keep_eid ? e.id : -1);\n          G.add(new_idx[a], new_idx[b], e.cost,\
    \ eid);\n        }\n      }\n    }\n    FOR(i, n) new_idx[V[i]] = -1;\n    for\
    \ (auto&& eid: history) used_e[eid] = 0;\n    G.build();\n    return G;\n  }\n\
    \n  Graph<T, true> to_directed_tree(int root = -1) {\n    if (root == -1) root\
    \ = 0;\n    assert(!is_directed && prepared && M == N - 1);\n    Graph<T, true>\
    \ G1(N);\n    vc<int> par(N, -1);\n    auto dfs = [&](auto& dfs, int v) -> void\
    \ {\n      for (auto& e: (*this)[v]) {\n        if (e.to == par[v]) continue;\n\
    \        par[e.to] = v, dfs(dfs, e.to);\n      }\n    };\n    dfs(dfs, root);\n\
    \    for (auto& e: edges) {\n      int a = e.frm, b = e.to;\n      if (par[a]\
    \ == b) swap(a, b);\n      assert(par[b] == a);\n      G1.add(a, b, e.cost);\n\
    \    }\n    G1.build();\n    return G1;\n  }\n\n  HashMap<int> MP_FOR_EID;\n\n\
    \  int get_eid(u64 a, u64 b) {\n    if (len(MP_FOR_EID) == 0) {\n      MP_FOR_EID.build(N\
    \ - 1);\n      for (auto& e: edges) {\n        u64 a = e.frm, b = e.to;\n    \
    \    u64 k = to_eid_key(a, b);\n        MP_FOR_EID[k] = e.id;\n      }\n    }\n\
    \    return MP_FOR_EID.get(to_eid_key(a, b), -1);\n  }\n\n  u64 to_eid_key(u64\
    \ a, u64 b) {\n    if (!directed && a > b) swap(a, b);\n    return N * a + b;\n\
    \  }\n\nprivate:\n  void calc_deg() {\n    assert(vc_deg.empty());\n    vc_deg.resize(N);\n\
    \    for (auto&& e: edges) vc_deg[e.frm]++, vc_deg[e.to]++;\n  }\n\n  void calc_deg_inout()\
    \ {\n    assert(vc_indeg.empty());\n    vc_indeg.resize(N);\n    vc_outdeg.resize(N);\n\
    \    for (auto&& e: edges) { vc_indeg[e.to]++, vc_outdeg[e.frm]++; }\n  }\n};\n\
    #line 4 \"graph/tree.hpp\"\n\r\n// HLD euler tour \u3092\u3068\u3063\u3066\u3044\
    \u308D\u3044\u308D\u3002\r\ntemplate <typename GT>\r\nstruct Tree {\r\n  using\
    \ Graph_type = GT;\r\n  GT &G;\r\n  using WT = typename GT::cost_type;\r\n  int\
    \ N;\r\n  vector<int> LID, RID, head, V, parent, VtoE;\r\n  vc<int> depth;\r\n\
    \  vc<WT> depth_weighted;\r\n\r\n  Tree(GT &G, int r = 0, bool hld = 1) : G(G)\
    \ { build(r, hld); }\r\n\r\n  void build(int r = 0, bool hld = 1) {\r\n    if\
    \ (r == -1) return; // build \u3092\u9045\u5EF6\u3057\u305F\u3044\u3068\u304D\r\
    \n    N = G.N;\r\n    LID.assign(N, -1), RID.assign(N, -1), head.assign(N, r);\r\
    \n    V.assign(N, -1), parent.assign(N, -1), VtoE.assign(N, -1);\r\n    depth.assign(N,\
    \ -1), depth_weighted.assign(N, 0);\r\n    assert(G.is_prepared());\r\n    int\
    \ t1 = 0;\r\n    dfs_sz(r, -1, hld);\r\n    dfs_hld(r, t1);\r\n  }\r\n\r\n  void\
    \ dfs_sz(int v, int p, bool hld) {\r\n    auto &sz = RID;\r\n    parent[v] = p;\r\
    \n    depth[v] = (p == -1 ? 0 : depth[p] + 1);\r\n    sz[v] = 1;\r\n    int l\
    \ = G.indptr[v], r = G.indptr[v + 1];\r\n    auto &csr = G.csr_edges;\r\n    //\
    \ \u4F7F\u3046\u8FBA\u304C\u3042\u308C\u3070\u5148\u982D\u306B\u3059\u308B\r\n\
    \    for (int i = r - 2; i >= l; --i) {\r\n      if (hld && depth[csr[i + 1].to]\
    \ == -1) swap(csr[i], csr[i + 1]);\r\n    }\r\n    int hld_sz = 0;\r\n    for\
    \ (int i = l; i < r; ++i) {\r\n      auto e = csr[i];\r\n      if (depth[e.to]\
    \ != -1) continue;\r\n      depth_weighted[e.to] = depth_weighted[v] + e.cost;\r\
    \n      VtoE[e.to] = e.id;\r\n      dfs_sz(e.to, v, hld);\r\n      sz[v] += sz[e.to];\r\
    \n      if (hld && chmax(hld_sz, sz[e.to]) && l < i) { swap(csr[l], csr[i]); }\r\
    \n    }\r\n  }\r\n\r\n  void dfs_hld(int v, int &times) {\r\n    LID[v] = times++;\r\
    \n    RID[v] += LID[v];\r\n    V[LID[v]] = v;\r\n    bool heavy = true;\r\n  \
    \  for (auto &&e: G[v]) {\r\n      if (depth[e.to] <= depth[v]) continue;\r\n\
    \      head[e.to] = (heavy ? head[v] : e.to);\r\n      heavy = false;\r\n    \
    \  dfs_hld(e.to, times);\r\n    }\r\n  }\r\n\r\n  vc<int> heavy_path_at(int v)\
    \ {\r\n    vc<int> P = {v};\r\n    while (1) {\r\n      int a = P.back();\r\n\
    \      for (auto &&e: G[a]) {\r\n        if (e.to != parent[a] && head[e.to] ==\
    \ v) {\r\n          P.eb(e.to);\r\n          break;\r\n        }\r\n      }\r\n\
    \      if (P.back() == a) break;\r\n    }\r\n    return P;\r\n  }\r\n\r\n  int\
    \ heavy_child(int v) {\r\n    int k = LID[v] + 1;\r\n    if (k == N) return -1;\r\
    \n    int w = V[k];\r\n    return (parent[w] == v ? w : -1);\r\n  }\r\n\r\n  vc<int>\
    \ memo_tail;\r\n\r\n  int tail(int v) {\r\n    if (memo_tail.empty()) {\r\n  \
    \    memo_tail.assign(N, -1);\r\n      FOR_R(i, N) {\r\n        int v = V[i];\r\
    \n        int w = heavy_child(v);\r\n        memo_tail[v] = (w == -1 ? v : memo_tail[w]);\r\
    \n      }\r\n    }\r\n    return memo_tail[v];\r\n  }\r\n\r\n  int e_to_v(int\
    \ eid) {\r\n    auto e = G.edges[eid];\r\n    return (parent[e.frm] == e.to ?\
    \ e.frm : e.to);\r\n  }\r\n  int v_to_e(int v) { return VtoE[v]; }\r\n  int get_eid(int\
    \ u, int v) {\r\n    if (parent[u] != v) swap(u, v);\r\n    assert(parent[u] ==\
    \ v);\r\n    return VtoE[u];\r\n  }\r\n\r\n  int ELID(int v) { return 2 * LID[v]\
    \ - depth[v]; }\r\n  int ERID(int v) { return 2 * RID[v] - depth[v] - 1; }\r\n\
    \r\n  // \u76EE\u6A19\u5730\u70B9\u3078\u9032\u3080\u500B\u6570\u304C k\r\n  int\
    \ LA(int v, int k) {\r\n    assert(k <= depth[v]);\r\n    while (1) {\r\n    \
    \  int u = head[v];\r\n      if (LID[v] - k >= LID[u]) return V[LID[v] - k];\r\
    \n      k -= LID[v] - LID[u] + 1;\r\n      v = parent[u];\r\n    }\r\n  }\r\n\
    \  int la(int u, int v) { return LA(u, v); }\r\n\r\n  int LCA(int u, int v) {\r\
    \n    for (;; v = parent[head[v]]) {\r\n      if (LID[u] > LID[v]) swap(u, v);\r\
    \n      if (head[u] == head[v]) return u;\r\n    }\r\n  }\r\n\r\n  int meet(int\
    \ a, int b, int c) { return LCA(a, b) ^ LCA(a, c) ^ LCA(b, c); }\r\n  int lca(int\
    \ u, int v) { return LCA(u, v); }\r\n\r\n  int subtree_size(int v, int root =\
    \ -1) {\r\n    if (root == -1) return RID[v] - LID[v];\r\n    if (v == root) return\
    \ N;\r\n    int x = jump(v, root, 1);\r\n    if (in_subtree(v, x)) return RID[v]\
    \ - LID[v];\r\n    return N - RID[x] + LID[x];\r\n  }\r\n\r\n  int dist(int a,\
    \ int b) {\r\n    int c = LCA(a, b);\r\n    return depth[a] + depth[b] - 2 * depth[c];\r\
    \n  }\r\n\r\n  WT dist_weighted(int a, int b) {\r\n    int c = LCA(a, b);\r\n\
    \    return depth_weighted[a] + depth_weighted[b] - WT(2) * depth_weighted[c];\r\
    \n  }\r\n\r\n  // a is in b\r\n  bool in_subtree(int a, int b) { return LID[b]\
    \ <= LID[a] && LID[a] < RID[b]; }\r\n\r\n  int jump(int a, int b, ll k) {\r\n\
    \    if (k == 1) {\r\n      if (a == b) return -1;\r\n      return (in_subtree(b,\
    \ a) ? LA(b, depth[b] - depth[a] - 1) : parent[a]);\r\n    }\r\n    int c = LCA(a,\
    \ b);\r\n    int d_ac = depth[a] - depth[c];\r\n    int d_bc = depth[b] - depth[c];\r\
    \n    if (k > d_ac + d_bc) return -1;\r\n    if (k <= d_ac) return LA(a, k);\r\
    \n    return LA(b, d_ac + d_bc - k);\r\n  }\r\n\r\n  vc<int> collect_child(int\
    \ v) {\r\n    vc<int> res;\r\n    for (auto &&e: G[v])\r\n      if (e.to != parent[v])\
    \ res.eb(e.to);\r\n    return res;\r\n  }\r\n\r\n  vc<int> collect_subtree(int\
    \ v) { return {V.begin() + LID[v], V.begin() + RID[v]}; }\r\n\r\n  vc<int> collect_light(int\
    \ v) {\r\n    vc<int> res;\r\n    bool skip = true;\r\n    for (auto &&e: G[v])\r\
    \n      if (e.to != parent[v]) {\r\n        if (!skip) res.eb(e.to);\r\n     \
    \   skip = false;\r\n      }\r\n    return res;\r\n  }\r\n\r\n  vc<pair<int, int>>\
    \ get_path_decomposition(int u, int v, bool edge) {\r\n    // [\u59CB\u70B9, \u7D42\
    \u70B9] \u306E\"\u9589\"\u533A\u9593\u5217\u3002\r\n    vc<pair<int, int>> up,\
    \ down;\r\n    while (1) {\r\n      if (head[u] == head[v]) break;\r\n      if\
    \ (LID[u] < LID[v]) {\r\n        down.eb(LID[head[v]], LID[v]);\r\n        v =\
    \ parent[head[v]];\r\n      } else {\r\n        up.eb(LID[u], LID[head[u]]);\r\
    \n        u = parent[head[u]];\r\n      }\r\n    }\r\n    if (LID[u] < LID[v])\
    \ down.eb(LID[u] + edge, LID[v]);\r\n    elif (LID[v] + edge <= LID[u]) up.eb(LID[u],\
    \ LID[v] + edge);\r\n    reverse(all(down));\r\n    up.insert(up.end(), all(down));\r\
    \n    return up;\r\n  }\r\n\r\n  // \u8FBA\u306E\u5217\u306E\u60C5\u5831 (frm,to,str)\r\
    \n  // str = \"heavy_up\", \"heavy_down\", \"light_up\", \"light_down\"\r\n  vc<tuple<int,\
    \ int, string>> get_path_decomposition_detail(int u, int v) {\r\n    vc<tuple<int,\
    \ int, string>> up, down;\r\n    while (1) {\r\n      if (head[u] == head[v])\
    \ break;\r\n      if (LID[u] < LID[v]) {\r\n        if (v != head[v]) down.eb(head[v],\
    \ v, \"heavy_down\"), v = head[v];\r\n        down.eb(parent[v], v, \"light_down\"\
    ), v = parent[v];\r\n      } else {\r\n        if (u != head[u]) up.eb(u, head[u],\
    \ \"heavy_up\"), u = head[u];\r\n        up.eb(u, parent[u], \"light_up\"), u\
    \ = parent[u];\r\n      }\r\n    }\r\n    if (LID[u] < LID[v]) down.eb(u, v, \"\
    heavy_down\");\r\n    elif (LID[v] < LID[u]) up.eb(u, v, \"heavy_up\");\r\n  \
    \  reverse(all(down));\r\n    concat(up, down);\r\n    return up;\r\n  }\r\n\r\
    \n  vc<int> restore_path(int u, int v) {\r\n    vc<int> P;\r\n    for (auto &&[a,\
    \ b]: get_path_decomposition(u, v, 0)) {\r\n      if (a <= b) {\r\n        FOR(i,\
    \ a, b + 1) P.eb(V[i]);\r\n      } else {\r\n        FOR_R(i, b, a + 1) P.eb(V[i]);\r\
    \n      }\r\n    }\r\n    return P;\r\n  }\r\n\r\n  // path [a,b] \u3068 [c,d]\
    \ \u306E\u4EA4\u308F\u308A. \u7A7A\u306A\u3089\u3070 {-1,-1}.\r\n  // https://codeforces.com/problemset/problem/500/G\r\
    \n  pair<int, int> path_intersection(int a, int b, int c, int d) {\r\n    int\
    \ ab = lca(a, b), ac = lca(a, c), ad = lca(a, d);\r\n    int bc = lca(b, c), bd\
    \ = lca(b, d), cd = lca(c, d);\r\n    int x = ab ^ ac ^ bc, y = ab ^ ad ^ bd;\
    \ // meet(a,b,c), meet(a,b,d)\r\n    if (x != y) return {x, y};\r\n    int z =\
    \ ac ^ ad ^ cd;\r\n    if (x != z) x = -1;\r\n    return {x, x};\r\n  }\r\n\r\n\
    \  // uv path \u4E0A\u3067 check(v) \u3092\u6E80\u305F\u3059\u6700\u5F8C\u306E\
    \ v\r\n  // \u306A\u3051\u308C\u3070 \uFF08\u3064\u307E\u308A check(v) \u304C\
    \ ng \uFF09-1\r\n  template <class F>\r\n  int max_path(F check, int u, int v)\
    \ {\r\n    if (!check(u)) return -1;\r\n    auto pd = get_path_decomposition(u,\
    \ v, false);\r\n    for (auto [a, b]: pd) {\r\n      if (!check(V[a])) return\
    \ u;\r\n      if (check(V[b])) {\r\n        u = V[b];\r\n        continue;\r\n\
    \      }\r\n      int c = binary_search([&](int c) -> bool { return check(V[c]);\
    \ }, a, b, 0);\r\n      return V[c];\r\n    }\r\n    return u;\r\n  }\r\n};\r\n\
    #line 4 \"graph/ds/tree_wavelet_matrix.hpp\"\n\n// https://atcoder.jp/contests/pakencamp-2022-day1/tasks/pakencamp_2022_day1_j\n\
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
  code: "\n#include \"ds/wavelet_matrix/wavelet_matrix.hpp\"\n#include \"graph/tree.hpp\"\
    \n\n// https://atcoder.jp/contests/pakencamp-2022-day1/tasks/pakencamp_2022_day1_j\n\
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
  - ds/wavelet_matrix/wavelet_matrix.hpp
  - ds/bit_vector.hpp
  - ds/dummy_data_structure.hpp
  - alg/monoid/dummy.hpp
  - graph/tree.hpp
  - graph/base.hpp
  - ds/hashmap.hpp
  isVerificationFile: false
  path: graph/ds/tree_wavelet_matrix.hpp
  requiredBy: []
  timestamp: '2026-04-13 17:55:57+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: graph/ds/tree_wavelet_matrix.hpp
layout: document
redirect_from:
- /library/graph/ds/tree_wavelet_matrix.hpp
- /library/graph/ds/tree_wavelet_matrix.hpp.html
title: graph/ds/tree_wavelet_matrix.hpp
---
