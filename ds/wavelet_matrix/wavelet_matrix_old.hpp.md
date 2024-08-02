---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: ds/bit_vector.hpp
    title: ds/bit_vector.hpp
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':warning:'
  attributes:
    links: []
  bundledCode: "#line 1 \"ds/bit_vector.hpp\"\nstruct Bit_Vector {\n  int n;\n  vc<pair<u64,\
    \ u32>> dat;\n  Bit_Vector(int n) : n(n) { dat.assign((n + 127) >> 6, {0, 0});\
    \ }\n  void set(int i) { dat[i >> 6].fi |= u64(1) << (i & 63); }\n  void reset()\
    \ { fill(all(dat), pair<u64, u32>{0, 0}); }\n  void build() {\n    FOR(i, len(dat)\
    \ - 1) dat[i + 1].se = dat[i].se + popcnt(dat[i].fi);\n  }\n  // [0, k) \u5185\
    \u306E 1 \u306E\u500B\u6570\n  int count_prefix(int k, bool f = true) {\n    auto\
    \ [a, b] = dat[k >> 6];\n    int ret = b + popcnt(a & ((u64(1) << (k & 63)) -\
    \ 1));\n    return (f ? ret : k - ret);\n  }\n  int count(int L, int R, bool f\
    \ = true) {\n    return count_prefix(R, f) - count_prefix(L, f);\n  }\n  string\
    \ to_string() {\n    string ans;\n    FOR(i, n) ans += '0' + (dat[i / 64].fi >>\
    \ (i % 64) & 1);\n    return ans;\n  }\n};\n#line 2 \"ds/wavelet_matrix/wavelet_matrix_old.hpp\"\
    \n\n// \u5EA7\u5727\u3059\u308B\u304B\u3069\u3046\u304B\u3092 COMPRESS \u3067\u6307\
    \u5B9A\u3059\u308B\n// xor \u7684\u306A\u4F7F\u3044\u65B9\u3092\u3059\u308B\u5834\
    \u5408\u306B\u306F\u3001\u30B3\u30F3\u30B9\u30C8\u30E9\u30AF\u30BF\u3067 log \u3092\
    \u6E21\u3059\u3053\u3068\ntemplate <typename T, bool COMPRESS, bool USE_SUM>\n\
    struct Wavelet_Matrix_Old {\n  static_assert(is_same_v<T, int> || is_same_v<T,\
    \ ll>);\n  int N, lg;\n  vector<int> mid;\n  vector<Bit_Vector> bv;\n  vc<T> key;\n\
    \  bool set_log;\n  vvc<T> cumsum;\n\n  Wavelet_Matrix_Old() {}\n\n  // \u548C\
    \u3092\u4F7F\u308F\u306A\u3044\u306A\u3089\u3001SUM_data \u306F\u7A7A\u3067\u3088\
    \u3044\n  Wavelet_Matrix_Old(vc<T> A, vc<T> SUM_data = {}, int log = -1) {\n \
    \   build(A, SUM_data, log);\n  }\n\n  void build(vc<T> A, vc<T> SUM_data = {},\
    \ int log = -1) {\n    if constexpr (USE_SUM) { assert(len(SUM_data) == len(A));\
    \ }\n    N = len(A), lg = log, set_log = (log != -1);\n    if (N == 0) {\n   \
    \   lg = 0;\n      cumsum.resize(1);\n      cumsum[0] = {0};\n      return;\n\
    \    }\n    vc<T>& S = SUM_data;\n    if (COMPRESS) {\n      assert(!set_log);\n\
    \      key.reserve(N);\n      vc<int> I = argsort(A);\n      for (auto&& i: I)\
    \ {\n        if (key.empty() || key.back() != A[i]) key.eb(A[i]);\n        A[i]\
    \ = len(key) - 1;\n      }\n      key.shrink_to_fit();\n    }\n    if (lg == -1)\
    \ lg = __lg(max<ll>(MAX(A), 1)) + 1;\n    mid.resize(lg), bv.assign(lg, Bit_Vector(N));\n\
    \    if constexpr (USE_SUM) cumsum.assign(1 + lg, vc<T>(N + 1, 0));\n    S.resize(N);\n\
    \    vc<T> A0(N), A1(N);\n    vc<T> S0(N), S1(N);\n    FOR_R(d, -1, lg) {\n  \
    \    int p0 = 0, p1 = 0;\n      if constexpr (USE_SUM) {\n        FOR(i, N) {\
    \ cumsum[d + 1][i + 1] = cumsum[d + 1][i] + S[i]; }\n      }\n      if (d == -1)\
    \ break;\n      FOR(i, N) {\n        bool f = (A[i] >> d & 1);\n        if (!f)\
    \ {\n          if constexpr (USE_SUM) S0[p0] = S[i];\n          A0[p0++] = A[i];\n\
    \        } else {\n          if constexpr (USE_SUM) S1[p1] = S[i];\n         \
    \ bv[d].set(i), A1[p1++] = A[i];\n        }\n      }\n      mid[d] = p0;\n   \
    \   bv[d].build();\n      swap(A, A0), swap(S, S0);\n      FOR(i, p1) A[p0 + i]\
    \ = A1[i], S[p0 + i] = S1[i];\n    }\n  }\n\n  // [L,R) x [a,b), (cnt, monoid\
    \ value)\n  pair<int, T> range_cnt_sum(int L, int R, T a, T b, T xor_val = 0)\
    \ {\n    if (xor_val != 0) assert(set_log);\n    if (a == b) return {0, 0};\n\
    \    if (COMPRESS) a = LB(key, a), b = LB(key, b);\n    int cnt = 0;\n    T sm\
    \ = 0;\n    auto dfs = [&](auto& dfs, int d, int L, int R, T lx, T rx) -> void\
    \ {\n      if (rx <= a || b <= lx) return;\n      if (a <= lx && rx <= b) {\n\
    \        cnt += R - L, sm += get(d, L, R);\n        return;\n      }\n      --d;\n\
    \      T mx = (lx + rx) / 2;\n      int l0 = bv[d].count(L, 0), r0 = bv[d].count(R,\
    \ 0);\n      int l1 = L + mid[d] - l0, r1 = R + mid[d] - r0;\n      if (xor_val\
    \ >> d & 1) swap(l0, l1), swap(r0, r1);\n      dfs(dfs, d, l0, r0, lx, mx), dfs(dfs,\
    \ d, l1, r1, mx, rx);\n    };\n    dfs(dfs, lg, L, R, 0, T(1) << lg);\n    return\
    \ {cnt, sm};\n  }\n\n  // smallest k, sum of [0,k)\n  pair<T, T> kth_value_sum(int\
    \ L, int R, int k, T xor_val = 0) {\n    assert(0 <= k && k <= R - L);\n    if\
    \ (k == R - L) { return {infty<T>, sum_all(L, R)}; }\n    if (L == R) return {infty<T>,\
    \ 0};\n    if (xor_val != 0) assert(set_log);\n    T sm = 0, val = 0;\n    for\
    \ (int d = lg - 1; d >= 0; --d) {\n      // \u3044\u307E\u5E45 d+1 \u306E trie\
    \ node \u306B\u5C45\u3066, \u5E45 d \u306E\u3068\u3053\u308D\u306B\u884C\u304F\
    \n      int l0 = bv[d].count(L, 0), r0 = bv[d].count(R, 0);\n      int l1 = L\
    \ + mid[d] - l0, r1 = R + mid[d] - r0;\n      if (xor_val >> d & 1) swap(l0, l1),\
    \ swap(r0, r1);\n      if (k < r0 - l0) {\n        L = l0, R = r0;\n      } else\
    \ {\n        k -= r0 - l0, val |= T(1) << d, L = l1, R = r1;\n        if constexpr\
    \ (USE_SUM) sm += get(d, l0, r0);\n      }\n    }\n    if constexpr (USE_SUM)\
    \ sm += get(0, L, L + k);\n    if (COMPRESS) val = key[val];\n\n    return {val,\
    \ sm};\n  }\n\n  int count(int L, int R, T a, T b, T xor_val = 0) {\n    return\
    \ range_cnt_sum(L, R, a, b, xor_val).fi;\n  }\n  T sum(int L, int R, T a, T b,\
    \ T xor_val = 0) {\n    static_assert(USE_SUM);\n    return range_cnt_sum(L, R,\
    \ a, b, xor_val).se;\n  }\n\n  T sum_index_range(int L, int R, int k1, int k2,\
    \ T xor_val = 0) {\n    static_assert(USE_SUM);\n    return kth_value_sum(L, R,\
    \ k2, xor_val).se\n           - kth_value_sum(L, R, k1, xor_val).se;\n  }\n  T\
    \ kth(int L, int R, int k, T xor_val = 0) {\n    assert(0 <= k && k < R - L);\n\
    \    return kth_value_sum(L, R, k, xor_val).fi;\n  }\n\n  // x \u4EE5\u4E0A\u6700\
    \u5C0F OR infty<T>\n  T next(int L, int R, T x, T xor_val = 0) {\n    if (xor_val\
    \ != 0) assert(set_log);\n    if (L == R) return infty<T>;\n    if (COMPRESS)\
    \ x = LB(key, x);\n    T ans = infty<T>;\n\n    auto dfs = [&](auto& dfs, int\
    \ d, int L, int R, T lx, T rx) -> void {\n      if (ans <= lx || L == R || rx\
    \ <= x) return;\n      if (d == 0) {\n        chmin(ans, lx);\n        return;\n\
    \      }\n      --d;\n      T mx = (lx + rx) / 2;\n      int l0 = bv[d].count(L,\
    \ 0), r0 = bv[d].count(R, 0);\n      int l1 = L + mid[d] - l0, r1 = R + mid[d]\
    \ - r0;\n      if (xor_val >> d & 1) swap(l0, l1), swap(r0, r1);\n      dfs(dfs,\
    \ d, l0, r0, lx, mx), dfs(dfs, d, l1, r1, mx, rx);\n    };\n    dfs(dfs, lg, L,\
    \ R, 0, T(1) << lg);\n    if (COMPRESS && ans < infty<T>) ans = key[ans];\n  \
    \  return ans;\n  }\n\n  // x \u4EE5\u4E0B\u6700\u5927 OR -infty<T>\n  T prev(int\
    \ L, int R, T x, T xor_val = 0) {\n    if (xor_val != 0) assert(set_log);\n  \
    \  if (L == R) return -infty<T>;\n    T ans = -infty<int>;\n    ++x;\n    if (COMPRESS)\
    \ x = LB(key, x);\n\n    auto dfs = [&](auto& dfs, int d, int L, int R, T lx,\
    \ T rx) -> void {\n      if ((rx - 1) <= ans || L == R || x <= lx) return;\n \
    \     if (d == 0) {\n        chmax(ans, lx);\n        return;\n      }\n     \
    \ --d;\n      T mx = (lx + rx) / 2;\n      int l0 = bv[d].count(L, 0), r0 = bv[d].count(R,\
    \ 0);\n      int l1 = L + mid[d] - l0, r1 = R + mid[d] - r0;\n      if (xor_val\
    \ >> d & 1) swap(l0, l1), swap(r0, r1);\n      dfs(dfs, d, l1, r1, mx, rx), dfs(dfs,\
    \ d, l0, r0, lx, mx);\n    };\n    dfs(dfs, lg, L, R, 0, T(1) << lg);\n    if\
    \ (COMPRESS && ans != -infty<T>) ans = key[ans];\n    return ans;\n  }\n\n  //\
    \ xor \u3057\u305F\u7D50\u679C\u3067\u3001[L, R) \u306E\u4E2D\u3067\u4E2D\u592E\
    \u5024\u3002\n  // LOWER = true\uFF1A\u4E0B\u5074\u4E2D\u592E\u5024\u3001false\uFF1A\
    \u4E0A\u5074\u4E2D\u592E\u5024\n  T median(bool UPPER, int L, int R, T xor_val\
    \ = 0) {\n    int n = R - L;\n    int k = (UPPER ? n / 2 : (n - 1) / 2);\n   \
    \ return kth(L, R, k, xor_val);\n  }\n\n  T sum_all(int L, int R) { return get(lg,\
    \ L, R); }\n\n  // check(cnt, prefix sum) \u304C true \u3068\u306A\u308B\u3088\
    \u3046\u306A\u6700\u5927\u306E (cnt, sum)\n  template <typename F>\n  pair<int,\
    \ T> max_right(F check, int L, int R, T xor_val = 0) {\n    assert(check(0, 0));\n\
    \    if (xor_val != 0) assert(set_log);\n    if (L == R) return {0, 0};\n    if\
    \ (check(R - L, get(lg, L, R))) return {R - L, get(lg, L, R)};\n    int cnt =\
    \ 0;\n    T sm = 0;\n    for (int d = lg - 1; d >= 0; --d) {\n      int l0 = bv[d].count(L,\
    \ 0), r0 = bv[d].count(R, 0);\n      int l1 = L + mid[d] - l0, r1 = R + mid[d]\
    \ - r0;\n      if (xor_val >> d & 1) swap(l0, l1), swap(r0, r1);\n      if (check(cnt\
    \ + r0 - l0, sm + get(d, l0, r0))) {\n        cnt += r0 - l0, sm += get(d, l0,\
    \ r0);\n        L = l1, R = r1;\n      } else {\n        L = l0, R = r0;\n   \
    \   }\n    }\n    int k = binary_search(\n        [&](int k) -> bool { return\
    \ check(cnt + k, sm + get(0, L, L + k)); }, 0,\n        R - L);\n    cnt += k,\
    \ sm += get(0, L, L + k);\n    return {cnt, sm};\n  }\n\nprivate:\n  inline T\
    \ get(int d, int L, int R) {\n    if constexpr (USE_SUM) return cumsum[d][R] -\
    \ cumsum[d][L];\n    return 0;\n  }\n};\n"
  code: "#include \"ds/bit_vector.hpp\"\n\n// \u5EA7\u5727\u3059\u308B\u304B\u3069\
    \u3046\u304B\u3092 COMPRESS \u3067\u6307\u5B9A\u3059\u308B\n// xor \u7684\u306A\
    \u4F7F\u3044\u65B9\u3092\u3059\u308B\u5834\u5408\u306B\u306F\u3001\u30B3\u30F3\
    \u30B9\u30C8\u30E9\u30AF\u30BF\u3067 log \u3092\u6E21\u3059\u3053\u3068\ntemplate\
    \ <typename T, bool COMPRESS, bool USE_SUM>\nstruct Wavelet_Matrix_Old {\n  static_assert(is_same_v<T,\
    \ int> || is_same_v<T, ll>);\n  int N, lg;\n  vector<int> mid;\n  vector<Bit_Vector>\
    \ bv;\n  vc<T> key;\n  bool set_log;\n  vvc<T> cumsum;\n\n  Wavelet_Matrix_Old()\
    \ {}\n\n  // \u548C\u3092\u4F7F\u308F\u306A\u3044\u306A\u3089\u3001SUM_data \u306F\
    \u7A7A\u3067\u3088\u3044\n  Wavelet_Matrix_Old(vc<T> A, vc<T> SUM_data = {}, int\
    \ log = -1) {\n    build(A, SUM_data, log);\n  }\n\n  void build(vc<T> A, vc<T>\
    \ SUM_data = {}, int log = -1) {\n    if constexpr (USE_SUM) { assert(len(SUM_data)\
    \ == len(A)); }\n    N = len(A), lg = log, set_log = (log != -1);\n    if (N ==\
    \ 0) {\n      lg = 0;\n      cumsum.resize(1);\n      cumsum[0] = {0};\n     \
    \ return;\n    }\n    vc<T>& S = SUM_data;\n    if (COMPRESS) {\n      assert(!set_log);\n\
    \      key.reserve(N);\n      vc<int> I = argsort(A);\n      for (auto&& i: I)\
    \ {\n        if (key.empty() || key.back() != A[i]) key.eb(A[i]);\n        A[i]\
    \ = len(key) - 1;\n      }\n      key.shrink_to_fit();\n    }\n    if (lg == -1)\
    \ lg = __lg(max<ll>(MAX(A), 1)) + 1;\n    mid.resize(lg), bv.assign(lg, Bit_Vector(N));\n\
    \    if constexpr (USE_SUM) cumsum.assign(1 + lg, vc<T>(N + 1, 0));\n    S.resize(N);\n\
    \    vc<T> A0(N), A1(N);\n    vc<T> S0(N), S1(N);\n    FOR_R(d, -1, lg) {\n  \
    \    int p0 = 0, p1 = 0;\n      if constexpr (USE_SUM) {\n        FOR(i, N) {\
    \ cumsum[d + 1][i + 1] = cumsum[d + 1][i] + S[i]; }\n      }\n      if (d == -1)\
    \ break;\n      FOR(i, N) {\n        bool f = (A[i] >> d & 1);\n        if (!f)\
    \ {\n          if constexpr (USE_SUM) S0[p0] = S[i];\n          A0[p0++] = A[i];\n\
    \        } else {\n          if constexpr (USE_SUM) S1[p1] = S[i];\n         \
    \ bv[d].set(i), A1[p1++] = A[i];\n        }\n      }\n      mid[d] = p0;\n   \
    \   bv[d].build();\n      swap(A, A0), swap(S, S0);\n      FOR(i, p1) A[p0 + i]\
    \ = A1[i], S[p0 + i] = S1[i];\n    }\n  }\n\n  // [L,R) x [a,b), (cnt, monoid\
    \ value)\n  pair<int, T> range_cnt_sum(int L, int R, T a, T b, T xor_val = 0)\
    \ {\n    if (xor_val != 0) assert(set_log);\n    if (a == b) return {0, 0};\n\
    \    if (COMPRESS) a = LB(key, a), b = LB(key, b);\n    int cnt = 0;\n    T sm\
    \ = 0;\n    auto dfs = [&](auto& dfs, int d, int L, int R, T lx, T rx) -> void\
    \ {\n      if (rx <= a || b <= lx) return;\n      if (a <= lx && rx <= b) {\n\
    \        cnt += R - L, sm += get(d, L, R);\n        return;\n      }\n      --d;\n\
    \      T mx = (lx + rx) / 2;\n      int l0 = bv[d].count(L, 0), r0 = bv[d].count(R,\
    \ 0);\n      int l1 = L + mid[d] - l0, r1 = R + mid[d] - r0;\n      if (xor_val\
    \ >> d & 1) swap(l0, l1), swap(r0, r1);\n      dfs(dfs, d, l0, r0, lx, mx), dfs(dfs,\
    \ d, l1, r1, mx, rx);\n    };\n    dfs(dfs, lg, L, R, 0, T(1) << lg);\n    return\
    \ {cnt, sm};\n  }\n\n  // smallest k, sum of [0,k)\n  pair<T, T> kth_value_sum(int\
    \ L, int R, int k, T xor_val = 0) {\n    assert(0 <= k && k <= R - L);\n    if\
    \ (k == R - L) { return {infty<T>, sum_all(L, R)}; }\n    if (L == R) return {infty<T>,\
    \ 0};\n    if (xor_val != 0) assert(set_log);\n    T sm = 0, val = 0;\n    for\
    \ (int d = lg - 1; d >= 0; --d) {\n      // \u3044\u307E\u5E45 d+1 \u306E trie\
    \ node \u306B\u5C45\u3066, \u5E45 d \u306E\u3068\u3053\u308D\u306B\u884C\u304F\
    \n      int l0 = bv[d].count(L, 0), r0 = bv[d].count(R, 0);\n      int l1 = L\
    \ + mid[d] - l0, r1 = R + mid[d] - r0;\n      if (xor_val >> d & 1) swap(l0, l1),\
    \ swap(r0, r1);\n      if (k < r0 - l0) {\n        L = l0, R = r0;\n      } else\
    \ {\n        k -= r0 - l0, val |= T(1) << d, L = l1, R = r1;\n        if constexpr\
    \ (USE_SUM) sm += get(d, l0, r0);\n      }\n    }\n    if constexpr (USE_SUM)\
    \ sm += get(0, L, L + k);\n    if (COMPRESS) val = key[val];\n\n    return {val,\
    \ sm};\n  }\n\n  int count(int L, int R, T a, T b, T xor_val = 0) {\n    return\
    \ range_cnt_sum(L, R, a, b, xor_val).fi;\n  }\n  T sum(int L, int R, T a, T b,\
    \ T xor_val = 0) {\n    static_assert(USE_SUM);\n    return range_cnt_sum(L, R,\
    \ a, b, xor_val).se;\n  }\n\n  T sum_index_range(int L, int R, int k1, int k2,\
    \ T xor_val = 0) {\n    static_assert(USE_SUM);\n    return kth_value_sum(L, R,\
    \ k2, xor_val).se\n           - kth_value_sum(L, R, k1, xor_val).se;\n  }\n  T\
    \ kth(int L, int R, int k, T xor_val = 0) {\n    assert(0 <= k && k < R - L);\n\
    \    return kth_value_sum(L, R, k, xor_val).fi;\n  }\n\n  // x \u4EE5\u4E0A\u6700\
    \u5C0F OR infty<T>\n  T next(int L, int R, T x, T xor_val = 0) {\n    if (xor_val\
    \ != 0) assert(set_log);\n    if (L == R) return infty<T>;\n    if (COMPRESS)\
    \ x = LB(key, x);\n    T ans = infty<T>;\n\n    auto dfs = [&](auto& dfs, int\
    \ d, int L, int R, T lx, T rx) -> void {\n      if (ans <= lx || L == R || rx\
    \ <= x) return;\n      if (d == 0) {\n        chmin(ans, lx);\n        return;\n\
    \      }\n      --d;\n      T mx = (lx + rx) / 2;\n      int l0 = bv[d].count(L,\
    \ 0), r0 = bv[d].count(R, 0);\n      int l1 = L + mid[d] - l0, r1 = R + mid[d]\
    \ - r0;\n      if (xor_val >> d & 1) swap(l0, l1), swap(r0, r1);\n      dfs(dfs,\
    \ d, l0, r0, lx, mx), dfs(dfs, d, l1, r1, mx, rx);\n    };\n    dfs(dfs, lg, L,\
    \ R, 0, T(1) << lg);\n    if (COMPRESS && ans < infty<T>) ans = key[ans];\n  \
    \  return ans;\n  }\n\n  // x \u4EE5\u4E0B\u6700\u5927 OR -infty<T>\n  T prev(int\
    \ L, int R, T x, T xor_val = 0) {\n    if (xor_val != 0) assert(set_log);\n  \
    \  if (L == R) return -infty<T>;\n    T ans = -infty<int>;\n    ++x;\n    if (COMPRESS)\
    \ x = LB(key, x);\n\n    auto dfs = [&](auto& dfs, int d, int L, int R, T lx,\
    \ T rx) -> void {\n      if ((rx - 1) <= ans || L == R || x <= lx) return;\n \
    \     if (d == 0) {\n        chmax(ans, lx);\n        return;\n      }\n     \
    \ --d;\n      T mx = (lx + rx) / 2;\n      int l0 = bv[d].count(L, 0), r0 = bv[d].count(R,\
    \ 0);\n      int l1 = L + mid[d] - l0, r1 = R + mid[d] - r0;\n      if (xor_val\
    \ >> d & 1) swap(l0, l1), swap(r0, r1);\n      dfs(dfs, d, l1, r1, mx, rx), dfs(dfs,\
    \ d, l0, r0, lx, mx);\n    };\n    dfs(dfs, lg, L, R, 0, T(1) << lg);\n    if\
    \ (COMPRESS && ans != -infty<T>) ans = key[ans];\n    return ans;\n  }\n\n  //\
    \ xor \u3057\u305F\u7D50\u679C\u3067\u3001[L, R) \u306E\u4E2D\u3067\u4E2D\u592E\
    \u5024\u3002\n  // LOWER = true\uFF1A\u4E0B\u5074\u4E2D\u592E\u5024\u3001false\uFF1A\
    \u4E0A\u5074\u4E2D\u592E\u5024\n  T median(bool UPPER, int L, int R, T xor_val\
    \ = 0) {\n    int n = R - L;\n    int k = (UPPER ? n / 2 : (n - 1) / 2);\n   \
    \ return kth(L, R, k, xor_val);\n  }\n\n  T sum_all(int L, int R) { return get(lg,\
    \ L, R); }\n\n  // check(cnt, prefix sum) \u304C true \u3068\u306A\u308B\u3088\
    \u3046\u306A\u6700\u5927\u306E (cnt, sum)\n  template <typename F>\n  pair<int,\
    \ T> max_right(F check, int L, int R, T xor_val = 0) {\n    assert(check(0, 0));\n\
    \    if (xor_val != 0) assert(set_log);\n    if (L == R) return {0, 0};\n    if\
    \ (check(R - L, get(lg, L, R))) return {R - L, get(lg, L, R)};\n    int cnt =\
    \ 0;\n    T sm = 0;\n    for (int d = lg - 1; d >= 0; --d) {\n      int l0 = bv[d].count(L,\
    \ 0), r0 = bv[d].count(R, 0);\n      int l1 = L + mid[d] - l0, r1 = R + mid[d]\
    \ - r0;\n      if (xor_val >> d & 1) swap(l0, l1), swap(r0, r1);\n      if (check(cnt\
    \ + r0 - l0, sm + get(d, l0, r0))) {\n        cnt += r0 - l0, sm += get(d, l0,\
    \ r0);\n        L = l1, R = r1;\n      } else {\n        L = l0, R = r0;\n   \
    \   }\n    }\n    int k = binary_search(\n        [&](int k) -> bool { return\
    \ check(cnt + k, sm + get(0, L, L + k)); }, 0,\n        R - L);\n    cnt += k,\
    \ sm += get(0, L, L + k);\n    return {cnt, sm};\n  }\n\nprivate:\n  inline T\
    \ get(int d, int L, int R) {\n    if constexpr (USE_SUM) return cumsum[d][R] -\
    \ cumsum[d][L];\n    return 0;\n  }\n};"
  dependsOn:
  - ds/bit_vector.hpp
  isVerificationFile: false
  path: ds/wavelet_matrix/wavelet_matrix_old.hpp
  requiredBy: []
  timestamp: '2024-07-27 02:46:37+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: ds/wavelet_matrix/wavelet_matrix_old.hpp
layout: document
redirect_from:
- /library/ds/wavelet_matrix/wavelet_matrix_old.hpp
- /library/ds/wavelet_matrix/wavelet_matrix_old.hpp.html
title: ds/wavelet_matrix/wavelet_matrix_old.hpp
---
