---
data:
  _extendedDependsOn:
  - icon: ':question:'
    path: alg/monoid/add.hpp
    title: alg/monoid/add.hpp
  - icon: ':heavy_check_mark:'
    path: ds/bit_vector.hpp
    title: ds/bit_vector.hpp
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/mytest/wavelet_matrix_sum.test.cpp
    title: test/mytest/wavelet_matrix_sum.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/yukicoder/2065.test.cpp
    title: test/yukicoder/2065.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/yukicoder/924.test.cpp
    title: test/yukicoder/924.test.cpp
  - icon: ':heavy_check_mark:'
    path: test_atcoder/abc127f_1.test.cpp
    title: test_atcoder/abc127f_1.test.cpp
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
    \ << (k & 31)) - 1));\n    return (f ? ret : k - ret);\n  }\n};\n#line 2 \"alg/monoid/add.hpp\"\
    \n\r\ntemplate <typename X>\r\nstruct Monoid_Add {\r\n  using value_type = X;\r\
    \n  static constexpr X op(const X &x, const X &y) noexcept { return x + y; }\r\
    \n  static constexpr X inverse(const X &x) noexcept { return -x; }\r\n  static\
    \ constexpr X power(const X &x, ll n) noexcept { return X(n) * x; }\r\n  static\
    \ constexpr X unit() { return X(0); }\r\n  static constexpr bool commute = true;\r\
    \n};\r\n#line 3 \"ds/wavelet_matrix_sum.hpp\"\n\n// \u5EA7\u5727\u3059\u308B\u304B\
    \u3069\u3046\u304B\u3092 COMPRESS \u3067\u6307\u5B9A\u3059\u308B\n// xor \u7684\
    \u306A\u4F7F\u3044\u65B9\u3092\u3059\u308B\u5834\u5408\u306B\u306F\u3001\u30B3\
    \u30F3\u30B9\u30C8\u30E9\u30AF\u30BF\u3067 log \u3092\u6E21\u3059\u3053\u3068\n\
    template <typename T, bool COMPRESS, typename Monoid = Monoid_Add<T>>\nstruct\
    \ Wavelet_Matrix_Sum {\n  using MX = Monoid;\n  using X = typename MX::value_type;\n\
    \  int N, lg;\n  vector<int> mid;\n  vector<Bit_Vector> bv;\n  vc<T> key;\n  const\
    \ bool set_log;\n  vvc<X> cumsum;\n\n  Wavelet_Matrix_Sum(vc<T> A, int log = -1)\n\
    \      : Wavelet_Matrix_Sum([](int a) -> X { return a; }, A, log) {}\n\n  template\
    \ <typename FUNC>\n  Wavelet_Matrix_Sum(FUNC F, vector<T> A, int log = -1)\n \
    \     : N(len(A)), lg(log), set_log(log != -1) {\n    if (COMPRESS) {\n      assert(!set_log);\n\
    \      key.reserve(N);\n      vc<int> I = argsort(A);\n      for (auto&& i: I)\
    \ {\n        if (key.empty() || key.back() != A[i]) key.eb(A[i]);\n        A[i]\
    \ = len(key) - 1;\n      }\n      key.shrink_to_fit();\n    }\n    if (lg == -1)\
    \ lg = __lg(max<ll>(MAX(A), 1)) + 1;\n    mid.resize(lg);\n    bv.assign(lg, Bit_Vector(N));\n\
    \    cumsum.assign(1 + lg, vc<X>(N + 1, MX::unit()));\n    vc<T> A0(N), A1(N);\n\
    \    FOR_R(d, -1, lg) {\n      int p0 = 0, p1 = 0;\n      FOR(i, N) {\n      \
    \  X x = F(COMPRESS ? key[A[i]] : A[i]);\n        cumsum[d + 1][i + 1] = MX::op(cumsum[d\
    \ + 1][i], x);\n      }\n      if (d == -1) break;\n      FOR(i, N) {\n      \
    \  bool f = (A[i] >> d & 1);\n        if (!f) A0[p0++] = A[i];\n        if (f)\
    \ bv[d].set(i), A1[p1++] = A[i];\n      }\n      mid[d] = p0;\n      bv[d].build();\n\
    \      swap(A, A0);\n      FOR(i, p1) A[p0 + i] = A1[i];\n    }\n  }\n\n  // xor\
    \ \u3057\u305F\u7D50\u679C\u304C [a, b) \u306B\u53CE\u307E\u308B\u3082\u306E\u3092\
    \u6570\u3048\u308B\n  // \u500B\u6570\u304A\u3088\u3073\u548C\u3092\u8FD4\u3059\
    \n  pair<int, X> count(int L, int R, T a, T b, T xor_val = 0) {\n    auto [c1,\
    \ s1] = prefix_count(L, R, a, xor_val);\n    auto [c2, s2] = prefix_count(L, R,\
    \ b, xor_val);\n    return {c2 - c1, MX::op(MX::inverse(s1), s2)};\n  }\n\n  //\
    \ xor \u3057\u305F\u7D50\u679C\u304C [0, x) \u306B\u53CE\u307E\u308B\u3082\u306E\
    \u3092\u6570\u3048\u308B\n  // \u500B\u6570\u304A\u3088\u3073\u548C\u3092\u8FD4\
    \u3059\n  pair<int, X> prefix_count(int L, int R, T x, T xor_val = 0) {\n    if\
    \ (xor_val != 0) assert(set_log);\n    x = (COMPRESS ? LB(key, x) : x);\n    if\
    \ (x >= (1 << lg)) return {R - L, get(lg, L, R)};\n    int cnt = 0;\n    X sm\
    \ = MX::unit();\n    FOR_R(d, lg) {\n      bool add = (x >> d) & 1;\n      bool\
    \ f = ((xor_val) >> d) & 1;\n      int l0 = bv[d].rank(L, 0), r0 = bv[d].rank(R,\
    \ 0);\n      int kf = (f ? (R - L) - (r0 - l0) : (r0 - l0));\n      if (add) {\n\
    \        cnt += kf;\n        if (f) {\n          sm = MX::op(sm, get(d, L + mid[d]\
    \ - l0, R + mid[d] - r0));\n          L = l0, R = r0;\n        } else {\n    \
    \      sm = MX::op(sm, get(d, l0, r0));\n          L = L + mid[d] - l0, R = R\
    \ + mid[d] - r0;\n        }\n      } else {\n        if (!f) L = l0, R = r0;\n\
    \        if (f) L += mid[d] - l0, R += mid[d] - r0;\n      }\n    }\n    return\
    \ {cnt, sm};\n  }\n\n  // [L, R) \u306E\u4E2D\u3067 k \u756A\u76EE\u3001\u304A\
    \u3088\u3073\u3001\u4E0B\u4F4D k \u500B\u306E\u548C\n  // k = R-L \u306E\u3068\
    \u304D\u306E first \u306F\u3001infty<T> \u3092\u8FD4\u3059\n  pair<T, X> kth(int\
    \ L, int R, int k, T xor_val = 0) {\n    if (xor_val != 0) assert(set_log);\n\
    \    if (k == R - L) return {infty<T>, get(lg, L, R)};\n    assert(0 <= k && k\
    \ < R - L);\n    T ret = 0;\n    X sm = 0;\n    for (int d = lg - 1; d >= 0; --d)\
    \ {\n      bool f = (xor_val >> d) & 1;\n      int l0 = bv[d].rank(L, 0), r0 =\
    \ bv[d].rank(R, 0);\n      int kf = (f ? (R - L) - (r0 - l0) : (r0 - l0));\n \
    \     if (k < kf) {\n        if (!f) L = l0, R = r0;\n        if (f) L += mid[d]\
    \ - l0, R += mid[d] - r0;\n      } else {\n        k -= kf, ret |= T(1) << d;\n\
    \        if (f) {\n          sm = MX::op(sm, get(d, L + mid[d] - l0, R + mid[d]\
    \ - r0));\n          L = l0, R = r0;\n        } else {\n          sm = MX::op(sm,\
    \ get(d, l0, r0));\n          L = L + mid[d] - l0, R = R + mid[d] - r0;\n    \
    \    }\n      }\n    }\n    if (k) sm = MX::op(sm, get(0, L, L + k));\n    return\
    \ {(COMPRESS ? key[ret] : ret), sm};\n  }\n\n  // check(prefix sum) \u304C true\
    \ \u3068\u306A\u308B\u4E0A\u9650\u306E\u6700\u5927\u5024 (or infty<T>)\n  template\
    \ <typename F>\n  T max_right_value(F check, int L, int R, T xor_val = 0) {\n\
    \    assert(check(MX::unit()));\n    if (xor_val != 0) assert(set_log);\n    if\
    \ (check(get(lg, L, R))) return infty<T>;\n    T ret = 0;\n    X sm = MX::unit();\n\
    \    for (int d = lg - 1; d >= 0; --d) {\n      bool f = ((xor_val) >> d) & 1;\n\
    \      int l0 = bv[d].rank(L, 0), r0 = bv[d].rank(R, 0);\n      X lo_sm = (f ?\
    \ get(d, L + mid[d] - l0, R + mid[d] - r0) : get(d, l0, r0));\n      if (check(MX::op(sm,\
    \ lo_sm))) {\n        sm = MX::op(sm, lo_sm);\n        ret |= 1 << d;\n      \
    \  if (f) L = l0, R = r0;\n        if (!f) L = L + mid[d] - l0, R = R + mid[d]\
    \ - r0;\n      } else {\n        if (!f) L = l0, R = r0;\n        if (f) L = L\
    \ + mid[d] - l0, R = R + mid[d] - r0;\n      }\n    }\n    return (COMPRESS ?\
    \ key[ret] : ret);\n  }\n\n  // check(prefix sum) \u304C true \u3068\u306A\u308B\
    \u52A0\u7B97\u500B\u6570\u306E\u6700\u5927\u5024\n  template <typename F>\n  int\
    \ max_right_count(F check, int L, int R, T xor_val = 0) {\n    assert(check(MX::unit()));\n\
    \    if (xor_val != 0) assert(set_log);\n    if (check(get(lg, L, R))) return\
    \ R - L;\n    int ret = 0;\n    X sm = MX::unit();\n    for (int d = lg - 1; d\
    \ >= 0; --d) {\n      bool f = (xor_val >> d) & 1;\n      int l0 = bv[d].rank(L,\
    \ 0), r0 = bv[d].rank(R, 0);\n      int kf = (f ? (R - L) - (r0 - l0) : (r0 -\
    \ l0));\n      X lo_sm = (f ? get(d, L + mid[d] - l0, R + mid[d] - r0) : get(d,\
    \ l0, r0));\n      if (check(MX::op(sm, lo_sm))) {\n        sm = MX::op(sm, lo_sm),\
    \ ret += kf;\n        if (f) L = l0, R = r0;\n        if (!f) L += mid[d] - l0,\
    \ R += mid[d] - r0;\n      } else {\n        if (!f) L = l0, R = r0;\n       \
    \ if (f) L += mid[d] - l0, R += mid[d] - r0;\n      }\n    }\n    ret += binary_search(\n\
    \        [&](int k) -> bool { return check(MX::op(sm, get(0, L, L + k))); }, 0,\n\
    \        R - L);\n    return ret;\n  }\n\nprivate:\n  inline X get(int d, int\
    \ L, int R) {\n    return MX::op(MX::inverse(cumsum[d][L]), cumsum[d][R]);\n \
    \ }\n};\n"
  code: "#include \"ds/bit_vector.hpp\"\n#include \"alg/monoid/add.hpp\"\n\n// \u5EA7\
    \u5727\u3059\u308B\u304B\u3069\u3046\u304B\u3092 COMPRESS \u3067\u6307\u5B9A\u3059\
    \u308B\n// xor \u7684\u306A\u4F7F\u3044\u65B9\u3092\u3059\u308B\u5834\u5408\u306B\
    \u306F\u3001\u30B3\u30F3\u30B9\u30C8\u30E9\u30AF\u30BF\u3067 log \u3092\u6E21\u3059\
    \u3053\u3068\ntemplate <typename T, bool COMPRESS, typename Monoid = Monoid_Add<T>>\n\
    struct Wavelet_Matrix_Sum {\n  using MX = Monoid;\n  using X = typename MX::value_type;\n\
    \  int N, lg;\n  vector<int> mid;\n  vector<Bit_Vector> bv;\n  vc<T> key;\n  const\
    \ bool set_log;\n  vvc<X> cumsum;\n\n  Wavelet_Matrix_Sum(vc<T> A, int log = -1)\n\
    \      : Wavelet_Matrix_Sum([](int a) -> X { return a; }, A, log) {}\n\n  template\
    \ <typename FUNC>\n  Wavelet_Matrix_Sum(FUNC F, vector<T> A, int log = -1)\n \
    \     : N(len(A)), lg(log), set_log(log != -1) {\n    if (COMPRESS) {\n      assert(!set_log);\n\
    \      key.reserve(N);\n      vc<int> I = argsort(A);\n      for (auto&& i: I)\
    \ {\n        if (key.empty() || key.back() != A[i]) key.eb(A[i]);\n        A[i]\
    \ = len(key) - 1;\n      }\n      key.shrink_to_fit();\n    }\n    if (lg == -1)\
    \ lg = __lg(max<ll>(MAX(A), 1)) + 1;\n    mid.resize(lg);\n    bv.assign(lg, Bit_Vector(N));\n\
    \    cumsum.assign(1 + lg, vc<X>(N + 1, MX::unit()));\n    vc<T> A0(N), A1(N);\n\
    \    FOR_R(d, -1, lg) {\n      int p0 = 0, p1 = 0;\n      FOR(i, N) {\n      \
    \  X x = F(COMPRESS ? key[A[i]] : A[i]);\n        cumsum[d + 1][i + 1] = MX::op(cumsum[d\
    \ + 1][i], x);\n      }\n      if (d == -1) break;\n      FOR(i, N) {\n      \
    \  bool f = (A[i] >> d & 1);\n        if (!f) A0[p0++] = A[i];\n        if (f)\
    \ bv[d].set(i), A1[p1++] = A[i];\n      }\n      mid[d] = p0;\n      bv[d].build();\n\
    \      swap(A, A0);\n      FOR(i, p1) A[p0 + i] = A1[i];\n    }\n  }\n\n  // xor\
    \ \u3057\u305F\u7D50\u679C\u304C [a, b) \u306B\u53CE\u307E\u308B\u3082\u306E\u3092\
    \u6570\u3048\u308B\n  // \u500B\u6570\u304A\u3088\u3073\u548C\u3092\u8FD4\u3059\
    \n  pair<int, X> count(int L, int R, T a, T b, T xor_val = 0) {\n    auto [c1,\
    \ s1] = prefix_count(L, R, a, xor_val);\n    auto [c2, s2] = prefix_count(L, R,\
    \ b, xor_val);\n    return {c2 - c1, MX::op(MX::inverse(s1), s2)};\n  }\n\n  //\
    \ xor \u3057\u305F\u7D50\u679C\u304C [0, x) \u306B\u53CE\u307E\u308B\u3082\u306E\
    \u3092\u6570\u3048\u308B\n  // \u500B\u6570\u304A\u3088\u3073\u548C\u3092\u8FD4\
    \u3059\n  pair<int, X> prefix_count(int L, int R, T x, T xor_val = 0) {\n    if\
    \ (xor_val != 0) assert(set_log);\n    x = (COMPRESS ? LB(key, x) : x);\n    if\
    \ (x >= (1 << lg)) return {R - L, get(lg, L, R)};\n    int cnt = 0;\n    X sm\
    \ = MX::unit();\n    FOR_R(d, lg) {\n      bool add = (x >> d) & 1;\n      bool\
    \ f = ((xor_val) >> d) & 1;\n      int l0 = bv[d].rank(L, 0), r0 = bv[d].rank(R,\
    \ 0);\n      int kf = (f ? (R - L) - (r0 - l0) : (r0 - l0));\n      if (add) {\n\
    \        cnt += kf;\n        if (f) {\n          sm = MX::op(sm, get(d, L + mid[d]\
    \ - l0, R + mid[d] - r0));\n          L = l0, R = r0;\n        } else {\n    \
    \      sm = MX::op(sm, get(d, l0, r0));\n          L = L + mid[d] - l0, R = R\
    \ + mid[d] - r0;\n        }\n      } else {\n        if (!f) L = l0, R = r0;\n\
    \        if (f) L += mid[d] - l0, R += mid[d] - r0;\n      }\n    }\n    return\
    \ {cnt, sm};\n  }\n\n  // [L, R) \u306E\u4E2D\u3067 k \u756A\u76EE\u3001\u304A\
    \u3088\u3073\u3001\u4E0B\u4F4D k \u500B\u306E\u548C\n  // k = R-L \u306E\u3068\
    \u304D\u306E first \u306F\u3001infty<T> \u3092\u8FD4\u3059\n  pair<T, X> kth(int\
    \ L, int R, int k, T xor_val = 0) {\n    if (xor_val != 0) assert(set_log);\n\
    \    if (k == R - L) return {infty<T>, get(lg, L, R)};\n    assert(0 <= k && k\
    \ < R - L);\n    T ret = 0;\n    X sm = 0;\n    for (int d = lg - 1; d >= 0; --d)\
    \ {\n      bool f = (xor_val >> d) & 1;\n      int l0 = bv[d].rank(L, 0), r0 =\
    \ bv[d].rank(R, 0);\n      int kf = (f ? (R - L) - (r0 - l0) : (r0 - l0));\n \
    \     if (k < kf) {\n        if (!f) L = l0, R = r0;\n        if (f) L += mid[d]\
    \ - l0, R += mid[d] - r0;\n      } else {\n        k -= kf, ret |= T(1) << d;\n\
    \        if (f) {\n          sm = MX::op(sm, get(d, L + mid[d] - l0, R + mid[d]\
    \ - r0));\n          L = l0, R = r0;\n        } else {\n          sm = MX::op(sm,\
    \ get(d, l0, r0));\n          L = L + mid[d] - l0, R = R + mid[d] - r0;\n    \
    \    }\n      }\n    }\n    if (k) sm = MX::op(sm, get(0, L, L + k));\n    return\
    \ {(COMPRESS ? key[ret] : ret), sm};\n  }\n\n  // check(prefix sum) \u304C true\
    \ \u3068\u306A\u308B\u4E0A\u9650\u306E\u6700\u5927\u5024 (or infty<T>)\n  template\
    \ <typename F>\n  T max_right_value(F check, int L, int R, T xor_val = 0) {\n\
    \    assert(check(MX::unit()));\n    if (xor_val != 0) assert(set_log);\n    if\
    \ (check(get(lg, L, R))) return infty<T>;\n    T ret = 0;\n    X sm = MX::unit();\n\
    \    for (int d = lg - 1; d >= 0; --d) {\n      bool f = ((xor_val) >> d) & 1;\n\
    \      int l0 = bv[d].rank(L, 0), r0 = bv[d].rank(R, 0);\n      X lo_sm = (f ?\
    \ get(d, L + mid[d] - l0, R + mid[d] - r0) : get(d, l0, r0));\n      if (check(MX::op(sm,\
    \ lo_sm))) {\n        sm = MX::op(sm, lo_sm);\n        ret |= 1 << d;\n      \
    \  if (f) L = l0, R = r0;\n        if (!f) L = L + mid[d] - l0, R = R + mid[d]\
    \ - r0;\n      } else {\n        if (!f) L = l0, R = r0;\n        if (f) L = L\
    \ + mid[d] - l0, R = R + mid[d] - r0;\n      }\n    }\n    return (COMPRESS ?\
    \ key[ret] : ret);\n  }\n\n  // check(prefix sum) \u304C true \u3068\u306A\u308B\
    \u52A0\u7B97\u500B\u6570\u306E\u6700\u5927\u5024\n  template <typename F>\n  int\
    \ max_right_count(F check, int L, int R, T xor_val = 0) {\n    assert(check(MX::unit()));\n\
    \    if (xor_val != 0) assert(set_log);\n    if (check(get(lg, L, R))) return\
    \ R - L;\n    int ret = 0;\n    X sm = MX::unit();\n    for (int d = lg - 1; d\
    \ >= 0; --d) {\n      bool f = (xor_val >> d) & 1;\n      int l0 = bv[d].rank(L,\
    \ 0), r0 = bv[d].rank(R, 0);\n      int kf = (f ? (R - L) - (r0 - l0) : (r0 -\
    \ l0));\n      X lo_sm = (f ? get(d, L + mid[d] - l0, R + mid[d] - r0) : get(d,\
    \ l0, r0));\n      if (check(MX::op(sm, lo_sm))) {\n        sm = MX::op(sm, lo_sm),\
    \ ret += kf;\n        if (f) L = l0, R = r0;\n        if (!f) L += mid[d] - l0,\
    \ R += mid[d] - r0;\n      } else {\n        if (!f) L = l0, R = r0;\n       \
    \ if (f) L += mid[d] - l0, R += mid[d] - r0;\n      }\n    }\n    ret += binary_search(\n\
    \        [&](int k) -> bool { return check(MX::op(sm, get(0, L, L + k))); }, 0,\n\
    \        R - L);\n    return ret;\n  }\n\nprivate:\n  inline X get(int d, int\
    \ L, int R) {\n    return MX::op(MX::inverse(cumsum[d][L]), cumsum[d][R]);\n \
    \ }\n};\n"
  dependsOn:
  - ds/bit_vector.hpp
  - alg/monoid/add.hpp
  isVerificationFile: false
  path: ds/wavelet_matrix_sum.hpp
  requiredBy: []
  timestamp: '2023-02-01 23:31:55+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test_atcoder/abc127f_1.test.cpp
  - test/mytest/wavelet_matrix_sum.test.cpp
  - test/yukicoder/2065.test.cpp
  - test/yukicoder/924.test.cpp
documentation_of: ds/wavelet_matrix_sum.hpp
layout: document
redirect_from:
- /library/ds/wavelet_matrix_sum.hpp
- /library/ds/wavelet_matrix_sum.hpp.html
title: ds/wavelet_matrix_sum.hpp
---
