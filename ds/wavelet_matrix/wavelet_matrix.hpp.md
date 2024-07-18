---
data:
  _extendedDependsOn:
  - icon: ':x:'
    path: ds/bit_vector.hpp
    title: ds/bit_vector.hpp
  _extendedRequiredBy:
  - icon: ':warning:'
    path: graph/ds/tree_wavelet_matrix.hpp
    title: graph/ds/tree_wavelet_matrix.hpp
  - icon: ':x:'
    path: string/prefix_substring_LCS.hpp
    title: string/prefix_substring_LCS.hpp
  _extendedVerifiedWith:
  - icon: ':x:'
    path: test/library_checker/datastructure/range_kth_smallest_wavelet.test.cpp
    title: test/library_checker/datastructure/range_kth_smallest_wavelet.test.cpp
  - icon: ':x:'
    path: test/library_checker/datastructure/range_kth_smallest_wavelet2.test.cpp
    title: test/library_checker/datastructure/range_kth_smallest_wavelet2.test.cpp
  - icon: ':x:'
    path: test/library_checker/string/prefix_substring_lcs.test.cpp
    title: test/library_checker/string/prefix_substring_lcs.test.cpp
  - icon: ':x:'
    path: test/yukicoder/1332.test.cpp
    title: test/yukicoder/1332.test.cpp
  - icon: ':x:'
    path: test/yukicoder/2065.test.cpp
    title: test/yukicoder/2065.test.cpp
  - icon: ':x:'
    path: test/yukicoder/919.test.cpp
    title: test/yukicoder/919.test.cpp
  - icon: ':x:'
    path: test/yukicoder/924.test.cpp
    title: test/yukicoder/924.test.cpp
  - icon: ':x:'
    path: test_atcoder/abc127f_1.test.cpp
    title: test_atcoder/abc127f_1.test.cpp
  - icon: ':x:'
    path: test_atcoder/abc324g.test.cpp
    title: test_atcoder/abc324g.test.cpp
  _isVerificationFailed: true
  _pathExtension: hpp
  _verificationStatusIcon: ':x:'
  attributes:
    links: []
  bundledCode: "#line 1 \"ds/bit_vector.hpp\"\nstruct Bit_Vector {\n  vc<pair<u32,\
    \ u32>> dat;\n  Bit_Vector(int n) { dat.assign((n + 63) >> 5, {0, 0}); }\n  void\
    \ set(int i) { dat[i >> 5].fi |= u32(1) << (i & 31); }\n  void reset() { fill(all(dat),\
    \ pair<u32, u32>{0, 0}); }\n  void build() {\n    FOR(i, len(dat) - 1) dat[i +\
    \ 1].se = dat[i].se + popcnt(dat[i].fi);\n  }\n  // [0, k) \u5185\u306E 1 \u306E\
    \u500B\u6570\n  int count(int k, bool f = 1) {\n    auto [a, b] = dat[k >> 5];\n\
    \    int ret = b + popcnt(a & ((u32(1) << (k & 31)) - 1));\n    return (f ? ret\
    \ : k - ret);\n  }\n  int count(int L, int R, bool f = 1) { return count(R, f)\
    \ - count(L, f); }\n};\n#line 2 \"ds/wavelet_matrix/wavelet_matrix.hpp\"\n\r\n\
    // \u5EA7\u5727\u3059\u308B\u304B\u3069\u3046\u304B\u3092 COMPRESS \u3067\u6307\
    \u5B9A\u3059\u308B\r\n// xor \u7684\u306A\u4F7F\u3044\u65B9\u3092\u3059\u308B\u5834\
    \u5408\u306B\u306F\u3001\u30B3\u30F3\u30B9\u30C8\u30E9\u30AF\u30BF\u3067 log \u3092\
    \u6E21\u3059\u3053\u3068\r\ntemplate <typename T, bool COMPRESS, bool USE_SUM>\r\
    \nstruct Wavelet_Matrix {\r\n  static_assert(is_same_v<T, int> || is_same_v<T,\
    \ ll>);\r\n  int N, lg;\r\n  vector<int> mid;\r\n  vector<Bit_Vector> bv;\r\n\
    \  vc<T> key;\r\n  bool set_log;\r\n  vvc<T> cumsum;\r\n\r\n  Wavelet_Matrix()\
    \ {}\r\n\r\n  // \u548C\u3092\u4F7F\u308F\u306A\u3044\u306A\u3089\u3001SUM_data\
    \ \u306F\u7A7A\u3067\u3088\u3044\r\n  Wavelet_Matrix(vc<T> A, vc<T> SUM_data =\
    \ {}, int log = -1) {\r\n    build(A, SUM_data, log);\r\n  }\r\n\r\n  void build(vc<T>\
    \ A, vc<T> SUM_data = {}, int log = -1) {\r\n    if constexpr (USE_SUM) { assert(len(SUM_data)\
    \ == len(A)); }\r\n    N = len(A), lg = log, set_log = (log != -1);\r\n    if\
    \ (N == 0) {\r\n      lg = 0;\r\n      cumsum.resize(1);\r\n      cumsum[0] =\
    \ {0};\r\n      return;\r\n    }\r\n    vc<T>& S = SUM_data;\r\n    if (COMPRESS)\
    \ {\r\n      assert(!set_log);\r\n      key.reserve(N);\r\n      vc<int> I = argsort(A);\r\
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
    \      int l0 = bv[d].rank(L, 0), r0 = bv[d].rank(R, 0);\r\n      int l1 = L +\
    \ mid[d] - l0, r1 = R + mid[d] - r0;\r\n      if (xor_val >> d & 1) swap(l0, l1),\
    \ swap(r0, r1);\r\n      dfs(dfs, d, l0, r0, lx, mx), dfs(dfs, d, l1, r1, mx,\
    \ rx);\r\n    };\r\n    dfs(dfs, lg, L, R, 0, T(1) << lg);\r\n    return {cnt,\
    \ sm};\r\n  }\r\n\r\n  // smallest k, sum of [0,k)\r\n  pair<T, T> kth_value_sum(int\
    \ L, int R, int k, T xor_val = 0) {\r\n    assert(0 <= k && k <= R - L);\r\n \
    \   if (k == R - L) { return {infty<T>, sum_all(L, R)}; }\r\n    if (L == R) return\
    \ {infty<T>, 0};\r\n    if (xor_val != 0) assert(set_log);\r\n    T sm = 0, val\
    \ = 0;\r\n    for (int d = lg - 1; d >= 0; --d) {\r\n      // \u3044\u307E\u5E45\
    \ d+1 \u306E trie node \u306B\u5C45\u3066, \u5E45 d \u306E\u3068\u3053\u308D\u306B\
    \u884C\u304F\r\n      int l0 = bv[d].rank(L, 0), r0 = bv[d].rank(R, 0);\r\n  \
    \    int l1 = L + mid[d] - l0, r1 = R + mid[d] - r0;\r\n      if (xor_val >> d\
    \ & 1) swap(l0, l1), swap(r0, r1);\r\n      if (k < r0 - l0) {\r\n        L =\
    \ l0, R = r0;\r\n      } else {\r\n        k -= r0 - l0, val |= T(1) << d, L =\
    \ l1, R = r1;\r\n        if constexpr (USE_SUM) sm += get(d, l0, r0);\r\n    \
    \  }\r\n    }\r\n    if constexpr (USE_SUM) sm += get(0, L, L + k);\r\n    if\
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
    \ T mx = (lx + rx) / 2;\r\n      int l0 = bv[d].rank(L, 0), r0 = bv[d].rank(R,\
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
    \n      }\r\n      --d;\r\n      T mx = (lx + rx) / 2;\r\n      int l0 = bv[d].rank(L,\
    \ 0), r0 = bv[d].rank(R, 0);\r\n      int l1 = L + mid[d] - l0, r1 = R + mid[d]\
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
    \ sm = 0;\r\n    for (int d = lg - 1; d >= 0; --d) {\r\n      int l0 = bv[d].rank(L,\
    \ 0), r0 = bv[d].rank(R, 0);\r\n      int l1 = L + mid[d] - l0, r1 = R + mid[d]\
    \ - r0;\r\n      if (xor_val >> d & 1) swap(l0, l1), swap(r0, r1);\r\n      if\
    \ (check(cnt + r0 - l0, sm + get(d, l0, r0))) {\r\n        cnt += r0 - l0, sm\
    \ += get(d, l0, r0);\r\n        L = l1, R = r1;\r\n      } else {\r\n        L\
    \ = l0, R = r0;\r\n      }\r\n    }\r\n    int k = binary_search(\r\n        [&](int\
    \ k) -> bool { return check(cnt + k, sm + get(0, L, L + k)); }, 0,\r\n       \
    \ R - L);\r\n    cnt += k, sm += get(0, L, L + k);\r\n    return {cnt, sm};\r\n\
    \  }\r\n\r\nprivate:\r\n  inline T get(int d, int L, int R) {\r\n    if constexpr\
    \ (USE_SUM) return cumsum[d][R] - cumsum[d][L];\r\n    return 0;\r\n  }\r\n};\n"
  code: "#include \"ds/bit_vector.hpp\"\r\n\r\n// \u5EA7\u5727\u3059\u308B\u304B\u3069\
    \u3046\u304B\u3092 COMPRESS \u3067\u6307\u5B9A\u3059\u308B\r\n// xor \u7684\u306A\
    \u4F7F\u3044\u65B9\u3092\u3059\u308B\u5834\u5408\u306B\u306F\u3001\u30B3\u30F3\
    \u30B9\u30C8\u30E9\u30AF\u30BF\u3067 log \u3092\u6E21\u3059\u3053\u3068\r\ntemplate\
    \ <typename T, bool COMPRESS, bool USE_SUM>\r\nstruct Wavelet_Matrix {\r\n  static_assert(is_same_v<T,\
    \ int> || is_same_v<T, ll>);\r\n  int N, lg;\r\n  vector<int> mid;\r\n  vector<Bit_Vector>\
    \ bv;\r\n  vc<T> key;\r\n  bool set_log;\r\n  vvc<T> cumsum;\r\n\r\n  Wavelet_Matrix()\
    \ {}\r\n\r\n  // \u548C\u3092\u4F7F\u308F\u306A\u3044\u306A\u3089\u3001SUM_data\
    \ \u306F\u7A7A\u3067\u3088\u3044\r\n  Wavelet_Matrix(vc<T> A, vc<T> SUM_data =\
    \ {}, int log = -1) {\r\n    build(A, SUM_data, log);\r\n  }\r\n\r\n  void build(vc<T>\
    \ A, vc<T> SUM_data = {}, int log = -1) {\r\n    if constexpr (USE_SUM) { assert(len(SUM_data)\
    \ == len(A)); }\r\n    N = len(A), lg = log, set_log = (log != -1);\r\n    if\
    \ (N == 0) {\r\n      lg = 0;\r\n      cumsum.resize(1);\r\n      cumsum[0] =\
    \ {0};\r\n      return;\r\n    }\r\n    vc<T>& S = SUM_data;\r\n    if (COMPRESS)\
    \ {\r\n      assert(!set_log);\r\n      key.reserve(N);\r\n      vc<int> I = argsort(A);\r\
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
    \      int l0 = bv[d].rank(L, 0), r0 = bv[d].rank(R, 0);\r\n      int l1 = L +\
    \ mid[d] - l0, r1 = R + mid[d] - r0;\r\n      if (xor_val >> d & 1) swap(l0, l1),\
    \ swap(r0, r1);\r\n      dfs(dfs, d, l0, r0, lx, mx), dfs(dfs, d, l1, r1, mx,\
    \ rx);\r\n    };\r\n    dfs(dfs, lg, L, R, 0, T(1) << lg);\r\n    return {cnt,\
    \ sm};\r\n  }\r\n\r\n  // smallest k, sum of [0,k)\r\n  pair<T, T> kth_value_sum(int\
    \ L, int R, int k, T xor_val = 0) {\r\n    assert(0 <= k && k <= R - L);\r\n \
    \   if (k == R - L) { return {infty<T>, sum_all(L, R)}; }\r\n    if (L == R) return\
    \ {infty<T>, 0};\r\n    if (xor_val != 0) assert(set_log);\r\n    T sm = 0, val\
    \ = 0;\r\n    for (int d = lg - 1; d >= 0; --d) {\r\n      // \u3044\u307E\u5E45\
    \ d+1 \u306E trie node \u306B\u5C45\u3066, \u5E45 d \u306E\u3068\u3053\u308D\u306B\
    \u884C\u304F\r\n      int l0 = bv[d].rank(L, 0), r0 = bv[d].rank(R, 0);\r\n  \
    \    int l1 = L + mid[d] - l0, r1 = R + mid[d] - r0;\r\n      if (xor_val >> d\
    \ & 1) swap(l0, l1), swap(r0, r1);\r\n      if (k < r0 - l0) {\r\n        L =\
    \ l0, R = r0;\r\n      } else {\r\n        k -= r0 - l0, val |= T(1) << d, L =\
    \ l1, R = r1;\r\n        if constexpr (USE_SUM) sm += get(d, l0, r0);\r\n    \
    \  }\r\n    }\r\n    if constexpr (USE_SUM) sm += get(0, L, L + k);\r\n    if\
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
    \ T mx = (lx + rx) / 2;\r\n      int l0 = bv[d].rank(L, 0), r0 = bv[d].rank(R,\
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
    \n      }\r\n      --d;\r\n      T mx = (lx + rx) / 2;\r\n      int l0 = bv[d].rank(L,\
    \ 0), r0 = bv[d].rank(R, 0);\r\n      int l1 = L + mid[d] - l0, r1 = R + mid[d]\
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
    \ sm = 0;\r\n    for (int d = lg - 1; d >= 0; --d) {\r\n      int l0 = bv[d].rank(L,\
    \ 0), r0 = bv[d].rank(R, 0);\r\n      int l1 = L + mid[d] - l0, r1 = R + mid[d]\
    \ - r0;\r\n      if (xor_val >> d & 1) swap(l0, l1), swap(r0, r1);\r\n      if\
    \ (check(cnt + r0 - l0, sm + get(d, l0, r0))) {\r\n        cnt += r0 - l0, sm\
    \ += get(d, l0, r0);\r\n        L = l1, R = r1;\r\n      } else {\r\n        L\
    \ = l0, R = r0;\r\n      }\r\n    }\r\n    int k = binary_search(\r\n        [&](int\
    \ k) -> bool { return check(cnt + k, sm + get(0, L, L + k)); }, 0,\r\n       \
    \ R - L);\r\n    cnt += k, sm += get(0, L, L + k);\r\n    return {cnt, sm};\r\n\
    \  }\r\n\r\nprivate:\r\n  inline T get(int d, int L, int R) {\r\n    if constexpr\
    \ (USE_SUM) return cumsum[d][R] - cumsum[d][L];\r\n    return 0;\r\n  }\r\n};"
  dependsOn:
  - ds/bit_vector.hpp
  isVerificationFile: false
  path: ds/wavelet_matrix/wavelet_matrix.hpp
  requiredBy:
  - string/prefix_substring_LCS.hpp
  - graph/ds/tree_wavelet_matrix.hpp
  timestamp: '2024-07-18 10:54:15+09:00'
  verificationStatus: LIBRARY_ALL_WA
  verifiedWith:
  - test/library_checker/datastructure/range_kth_smallest_wavelet2.test.cpp
  - test/library_checker/datastructure/range_kth_smallest_wavelet.test.cpp
  - test/library_checker/string/prefix_substring_lcs.test.cpp
  - test/yukicoder/919.test.cpp
  - test/yukicoder/1332.test.cpp
  - test/yukicoder/2065.test.cpp
  - test/yukicoder/924.test.cpp
  - test_atcoder/abc127f_1.test.cpp
  - test_atcoder/abc324g.test.cpp
documentation_of: ds/wavelet_matrix/wavelet_matrix.hpp
layout: document
redirect_from:
- /library/ds/wavelet_matrix/wavelet_matrix.hpp
- /library/ds/wavelet_matrix/wavelet_matrix.hpp.html
title: ds/wavelet_matrix/wavelet_matrix.hpp
---
