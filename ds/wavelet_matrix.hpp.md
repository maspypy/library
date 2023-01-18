---
data:
  _extendedDependsOn:
  - icon: ':question:'
    path: ds/bit_vector.hpp
    title: ds/bit_vector.hpp
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':x:'
    path: test/library_checker/datastructure/range_kth_smallest_wavelet.test.cpp
    title: test/library_checker/datastructure/range_kth_smallest_wavelet.test.cpp
  - icon: ':x:'
    path: test/library_checker/datastructure/range_kth_smallest_wavelet2.test.cpp
    title: test/library_checker/datastructure/range_kth_smallest_wavelet2.test.cpp
  - icon: ':x:'
    path: test/mytest/wavelet_matrix.test.cpp
    title: test/mytest/wavelet_matrix.test.cpp
  - icon: ':x:'
    path: test/yukicoder/1332.test.cpp
    title: test/yukicoder/1332.test.cpp
  - icon: ':x:'
    path: test/yukicoder/919.test.cpp
    title: test/yukicoder/919.test.cpp
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
    \ << (k & 31)) - 1));\n    return (f ? ret : k - ret);\n  }\n};\n#line 2 \"ds/wavelet_matrix.hpp\"\
    \n\r\n// \u5EA7\u5727\u3059\u308B\u304B\u3069\u3046\u304B\u3092 COMPRESS \u3067\
    \u6307\u5B9A\u3059\u308B\r\n// xor \u7684\u306A\u4F7F\u3044\u65B9\u3092\u3059\u308B\
    \u5834\u5408\u306B\u306F\u3001\u30B3\u30F3\u30B9\u30C8\u30E9\u30AF\u30BF\u3067\
    \ log \u3092\u6E21\u3059\u3053\u3068\r\ntemplate <typename T, bool COMPRESS>\r\
    \nstruct Wavelet_Matrix {\r\n  int N, lg;\r\n  vector<int> mid;\r\n  vector<Bit_Vector>\
    \ bv;\r\n  vc<T> key;\r\n  const bool set_log;\r\n\r\n  Wavelet_Matrix(vector<T>\
    \ A, int log = -1)\r\n      : N(len(A)), lg(log), set_log(log != -1) {\r\n   \
    \ if (COMPRESS) {\r\n      assert(!set_log);\r\n      key.reserve(N);\r\n    \
    \  vc<int> I = argsort(A);\r\n      for (auto&& i: I) {\r\n        if (key.empty()\
    \ || key.back() != A[i]) key.eb(A[i]);\r\n        A[i] = len(key) - 1;\r\n   \
    \   }\r\n      key.shrink_to_fit();\r\n    }\r\n    if (lg == -1) lg = __lg(max<ll>(MAX(A),\
    \ 1)) + 1;\r\n    mid.resize(lg);\r\n    bv.assign(lg, Bit_Vector(N));\r\n   \
    \ vc<T> A0(N), A1(N);\r\n    FOR_R(d, lg) {\r\n      int p0 = 0, p1 = 0;\r\n \
    \     FOR(i, N) {\r\n        bool f = (A[i] >> d & 1);\r\n        if (!f) A0[p0++]\
    \ = A[i];\r\n        if (f) bv[d].set(i), A1[p1++] = A[i];\r\n      }\r\n    \
    \  mid[d] = p0;\r\n      bv[d].build();\r\n      swap(A, A0);\r\n      FOR(i,\
    \ p1) A[p0 + i] = A1[i];\r\n    }\r\n  }\r\n\r\n  // xor \u3057\u305F\u7D50\u679C\
    \u3067 [a, b) \u306B\u53CE\u307E\u308B\u3082\u306E\u3092\u6570\u3048\u308B\r\n\
    \  int count(int L, int R, T a, T b, T xor_val = 0) {\r\n    return prefix_count(L,\
    \ R, b, xor_val) - prefix_count(L, R, a, xor_val);\r\n  }\r\n\r\n  // xor \u3057\
    \u305F\u7D50\u679C\u3067 [0, x) \u306B\u53CE\u307E\u308B\u3082\u306E\u3092\u6570\
    \u3048\u308B\r\n  int prefix_count(int L, int R, T x, T xor_val = 0) {\r\n   \
    \ if (xor_val != 0) assert(set_log);\r\n    x = (COMPRESS ? LB(key, x) : x);\r\
    \n    if (x >= (1 << lg)) return R - L;\r\n    int ret = 0;\r\n    FOR_R(d, lg)\
    \ {\r\n      bool add = (x >> d) & 1;\r\n      bool f = ((x ^ xor_val) >> d) &\
    \ 1;\r\n      if (add) ret += bv[d].rank(R, !f) - bv[d].rank(L, !f);\r\n     \
    \ L = bv[d].rank(L, f) + (f ? mid[d] : 0);\r\n      R = bv[d].rank(R, f) + (f\
    \ ? mid[d] : 0);\r\n    }\r\n    return ret;\r\n  }\r\n\r\n  // [L, R) \u306E\u4E2D\
    \u3067 k>=0 \u756A\u76EE\r\n  T kth(int L, int R, int k, T xor_val = 0) {\r\n\
    \    if (xor_val != 0) assert(set_log);\r\n    assert(0 <= k && k < R - L);\r\n\
    \    T ret = 0;\r\n    for (int d = lg - 1; d >= 0; --d) {\r\n      bool f = (xor_val\
    \ >> d) & 1;\r\n      int l0 = bv[d].rank(L, 0), r0 = bv[d].rank(R, 0);\r\n  \
    \    int kf = (f ? (R - L) - (r0 - l0) : (r0 - l0));\r\n      if (k < kf) {\r\n\
    \        if (!f) L = l0, R = r0;\r\n        if (f) L += mid[d] - l0, R += mid[d]\
    \ - r0;\r\n      } else {\r\n        k -= kf, ret |= T(1) << d;\r\n        if\
    \ (!f) L += mid[d] - l0, R += mid[d] - r0;\r\n        if (f) L = l0, R = r0;\r\
    \n      }\r\n    }\r\n    return (COMPRESS ? key[ret] : ret);\r\n  }\r\n};\r\n"
  code: "#include \"ds/bit_vector.hpp\"\r\n\r\n// \u5EA7\u5727\u3059\u308B\u304B\u3069\
    \u3046\u304B\u3092 COMPRESS \u3067\u6307\u5B9A\u3059\u308B\r\n// xor \u7684\u306A\
    \u4F7F\u3044\u65B9\u3092\u3059\u308B\u5834\u5408\u306B\u306F\u3001\u30B3\u30F3\
    \u30B9\u30C8\u30E9\u30AF\u30BF\u3067 log \u3092\u6E21\u3059\u3053\u3068\r\ntemplate\
    \ <typename T, bool COMPRESS>\r\nstruct Wavelet_Matrix {\r\n  int N, lg;\r\n \
    \ vector<int> mid;\r\n  vector<Bit_Vector> bv;\r\n  vc<T> key;\r\n  const bool\
    \ set_log;\r\n\r\n  Wavelet_Matrix(vector<T> A, int log = -1)\r\n      : N(len(A)),\
    \ lg(log), set_log(log != -1) {\r\n    if (COMPRESS) {\r\n      assert(!set_log);\r\
    \n      key.reserve(N);\r\n      vc<int> I = argsort(A);\r\n      for (auto&&\
    \ i: I) {\r\n        if (key.empty() || key.back() != A[i]) key.eb(A[i]);\r\n\
    \        A[i] = len(key) - 1;\r\n      }\r\n      key.shrink_to_fit();\r\n   \
    \ }\r\n    if (lg == -1) lg = __lg(max<ll>(MAX(A), 1)) + 1;\r\n    mid.resize(lg);\r\
    \n    bv.assign(lg, Bit_Vector(N));\r\n    vc<T> A0(N), A1(N);\r\n    FOR_R(d,\
    \ lg) {\r\n      int p0 = 0, p1 = 0;\r\n      FOR(i, N) {\r\n        bool f =\
    \ (A[i] >> d & 1);\r\n        if (!f) A0[p0++] = A[i];\r\n        if (f) bv[d].set(i),\
    \ A1[p1++] = A[i];\r\n      }\r\n      mid[d] = p0;\r\n      bv[d].build();\r\n\
    \      swap(A, A0);\r\n      FOR(i, p1) A[p0 + i] = A1[i];\r\n    }\r\n  }\r\n\
    \r\n  // xor \u3057\u305F\u7D50\u679C\u3067 [a, b) \u306B\u53CE\u307E\u308B\u3082\
    \u306E\u3092\u6570\u3048\u308B\r\n  int count(int L, int R, T a, T b, T xor_val\
    \ = 0) {\r\n    return prefix_count(L, R, b, xor_val) - prefix_count(L, R, a,\
    \ xor_val);\r\n  }\r\n\r\n  // xor \u3057\u305F\u7D50\u679C\u3067 [0, x) \u306B\
    \u53CE\u307E\u308B\u3082\u306E\u3092\u6570\u3048\u308B\r\n  int prefix_count(int\
    \ L, int R, T x, T xor_val = 0) {\r\n    if (xor_val != 0) assert(set_log);\r\n\
    \    x = (COMPRESS ? LB(key, x) : x);\r\n    if (x >= (1 << lg)) return R - L;\r\
    \n    int ret = 0;\r\n    FOR_R(d, lg) {\r\n      bool add = (x >> d) & 1;\r\n\
    \      bool f = ((x ^ xor_val) >> d) & 1;\r\n      if (add) ret += bv[d].rank(R,\
    \ !f) - bv[d].rank(L, !f);\r\n      L = bv[d].rank(L, f) + (f ? mid[d] : 0);\r\
    \n      R = bv[d].rank(R, f) + (f ? mid[d] : 0);\r\n    }\r\n    return ret;\r\
    \n  }\r\n\r\n  // [L, R) \u306E\u4E2D\u3067 k>=0 \u756A\u76EE\r\n  T kth(int L,\
    \ int R, int k, T xor_val = 0) {\r\n    if (xor_val != 0) assert(set_log);\r\n\
    \    assert(0 <= k && k < R - L);\r\n    T ret = 0;\r\n    for (int d = lg - 1;\
    \ d >= 0; --d) {\r\n      bool f = (xor_val >> d) & 1;\r\n      int l0 = bv[d].rank(L,\
    \ 0), r0 = bv[d].rank(R, 0);\r\n      int kf = (f ? (R - L) - (r0 - l0) : (r0\
    \ - l0));\r\n      if (k < kf) {\r\n        if (!f) L = l0, R = r0;\r\n      \
    \  if (f) L += mid[d] - l0, R += mid[d] - r0;\r\n      } else {\r\n        k -=\
    \ kf, ret |= T(1) << d;\r\n        if (!f) L += mid[d] - l0, R += mid[d] - r0;\r\
    \n        if (f) L = l0, R = r0;\r\n      }\r\n    }\r\n    return (COMPRESS ?\
    \ key[ret] : ret);\r\n  }\r\n};\r\n"
  dependsOn:
  - ds/bit_vector.hpp
  isVerificationFile: false
  path: ds/wavelet_matrix.hpp
  requiredBy: []
  timestamp: '2022-12-13 09:39:12+09:00'
  verificationStatus: LIBRARY_ALL_WA
  verifiedWith:
  - test/library_checker/datastructure/range_kth_smallest_wavelet.test.cpp
  - test/library_checker/datastructure/range_kth_smallest_wavelet2.test.cpp
  - test/yukicoder/1332.test.cpp
  - test/yukicoder/919.test.cpp
  - test/mytest/wavelet_matrix.test.cpp
documentation_of: ds/wavelet_matrix.hpp
layout: document
redirect_from:
- /library/ds/wavelet_matrix.hpp
- /library/ds/wavelet_matrix.hpp.html
title: ds/wavelet_matrix.hpp
---
