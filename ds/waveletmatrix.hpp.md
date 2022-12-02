---
data:
  _extendedDependsOn:
  - icon: ':question:'
    path: alg/monoid/add.hpp
    title: alg/monoid/add.hpp
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/atcoder/abc127f_1.test.cpp
    title: test/atcoder/abc127f_1.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/library_checker/datastructure/range_kth_smallest_wavelet.test.cpp
    title: test/library_checker/datastructure/range_kth_smallest_wavelet.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/mytest/wavelet_matrix_sum.test.cpp
    title: test/mytest/wavelet_matrix_sum.test.cpp
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
  _isVerificationFailed: true
  _pathExtension: hpp
  _verificationStatusIcon: ':question:'
  attributes:
    links: []
  bundledCode: "#line 2 \"alg/monoid/add.hpp\"\n\r\ntemplate <typename X>\r\nstruct\
    \ Monoid_Add {\r\n  using value_type = X;\r\n  static constexpr X op(const X &x,\
    \ const X &y) noexcept { return x + y; }\r\n  static constexpr X inverse(const\
    \ X &x) noexcept { return -x; }\r\n  static constexpr X power(const X &x, ll n)\
    \ noexcept { return X(n) * x; }\r\n  static constexpr X unit() { return X(0);\
    \ }\r\n  static constexpr bool commute = true;\r\n};\r\n#line 2 \"ds/waveletmatrix.hpp\"\
    \n\r\n// Wavelet Matrix \u4E0A\u3067\u3055\u3089\u306B\u7D2F\u7A4D\u548C\u3092\
    \u7BA1\u7406\u3057\u3066\u3001\r\n// \u77E9\u5F62\u548C\u304C\u3068\u308C\u308B\
    \u3088\u3046\u306B\u3057\u305F\u3082\u306E\r\ntemplate <typename T, bool SUM_QUERY\
    \ = false,\r\n          typename AbelGroup = Monoid_Add<ll>>\r\nstruct WaveletMatrix\
    \ {\r\n  struct BitVector {\r\n    vector<u64> buf;\r\n    vector<int> sum;\r\n\
    \    BitVector(const vector<char>& a = {}) {\r\n      int n = a.size();\r\n  \
    \    buf.assign((n + 63) >> 6, 0);\r\n      sum.assign(buf.size() + 1, 0);\r\n\
    \      FOR(i, n) if (a[i]) {\r\n        buf[i >> 6] |= 1ull << (i & 63);\r\n \
    \       sum[(i >> 6) + 1]++;\r\n      }\r\n      FOR(i, buf.size()) sum[i + 1]\
    \ += sum[i];\r\n    }\r\n    int rank(int k, bool f = 1) {\r\n      int ret =\
    \ sum[k >> 6]\r\n                + __builtin_popcountll(buf[k >> 6] & ((1ull <<\
    \ (k & 63)) - 1));\r\n      if (!f)\r\n        return k - ret;\r\n      else\r\
    \n        return ret;\r\n    }\r\n  };\r\n\r\n  int N, lg;\r\n  vector<int> mid;\r\
    \n  vector<BitVector> bv;\r\n  vector<vector<T>> cumsum;\r\n  vc<T> key;\r\n \
    \ WaveletMatrix(vector<T>& dat) : N(dat.size()) {\r\n    key = dat;\r\n    UNIQUE(key);\r\
    \n    vc<int> A(N);\r\n    FOR(i, N) A[i] = LB(key, dat[i]);\r\n    lg = __lg(max(MAX(A),\
    \ 1)) + 1;\r\n\r\n    mid.resize(lg);\r\n    bv.resize(lg);\r\n    cumsum.resize(lg);\r\
    \n    for (int d = lg - 1; d >= 0; d--) {\r\n      vector<char> add;\r\n     \
    \ vector nxt(2, vector<int>());\r\n      for (auto& x: A) {\r\n        add.push_back(x\
    \ >> d & 1);\r\n        nxt[x >> d & 1].push_back(x);\r\n      }\r\n      mid[d]\
    \ = (int)nxt[0].size();\r\n      bv[d] = BitVector(add);\r\n      swap(A, nxt[0]);\r\
    \n      A.insert(A.end(), all(nxt[1]));\r\n      if (SUM_QUERY) {\r\n        vc<T>\
    \ cs(N + 1);\r\n        cs[0] = AbelGroup::unit();\r\n        FOR(i, N) cs[i +\
    \ 1] = AbelGroup::op(cs[i], key[A[i]]);\r\n        cumsum[d] = cs;\r\n      }\r\
    \n    }\r\n  }\r\n\r\n  // [L, R) \u5185\u306B\u3042\u308B [a, b) \u3092\u6570\
    \u3048\u308B\r\n  int freq(int L, int R, T a, T b) {\r\n    return freq_upper(L,\
    \ R, b) - freq_upper(L, R, a);\r\n  }\r\n  int freq_upper(int L, int R, T t) {\r\
    \n    int x = LB(key, t);\r\n    if (x >= (1 << lg)) return R - L;\r\n    int\
    \ ret = 0;\r\n    for (int h = lg - 1; h >= 0; --h) {\r\n      bool f = (x >>\
    \ h) & 1;\r\n      if (f) ret += bv[h].rank(R, 0) - bv[h].rank(L, 0);\r\n    \
    \  L = bv[h].rank(L, f) + (f ? mid[h] : 0);\r\n      R = bv[h].rank(R, f) + (f\
    \ ? mid[h] : 0);\r\n    }\r\n    return ret;\r\n  }\r\n\r\n  // [L, R) \u306E\u4E2D\
    \u3067 k>=0 \u756A\u76EE\r\n  T kth(int L, int R, int k) {\r\n    assert(0 <=\
    \ k && k < R - L);\r\n    int ret = 0;\r\n    for (int h = lg - 1; h >= 0; h--)\
    \ {\r\n      int l0 = bv[h].rank(L, 0), r0 = bv[h].rank(R, 0);\r\n      if (k\
    \ < r0 - l0)\r\n        L = l0, R = r0;\r\n      else {\r\n        k -= r0 - l0;\r\
    \n        ret |= 1 << h;\r\n        L += mid[h] - l0, R += mid[h] - r0;\r\n  \
    \    }\r\n    }\r\n    return key[ret];\r\n  }\r\n\r\n  // [L, R) \u306E\u4E2D\
    \u3067\u5C0F\u3055\u3044\u65B9\u304B\u3089 k \u500B\u306E\u7DCF\u548C\r\n  T sum(int\
    \ L, int R, int k) {\r\n    assert(SUM_QUERY);\r\n    assert(0 <= k && k <= R\
    \ - L);\r\n    T pos = AbelGroup::unit(), neg = AbelGroup::unit();\r\n    for\
    \ (int h = lg - 1; h >= 0; h--) {\r\n      int l0 = bv[h].rank(L, 0), r0 = bv[h].rank(R,\
    \ 0);\r\n      if (k < r0 - l0) {\r\n        L = l0, R = r0;\r\n      } else {\r\
    \n        k -= r0 - l0;\r\n        pos = AbelGroup::op(pos, cumsum[h][r0]);\r\n\
    \        neg = AbelGroup::op(neg, cumsum[h][l0]);\r\n        L += mid[h] - l0,\
    \ R += mid[h] - r0;\r\n      }\r\n    }\r\n    if (k) {\r\n      pos = AbelGroup::op(pos,\
    \ cumsum[0][L + k]);\r\n      neg = AbelGroup::op(neg, cumsum[0][L]);\r\n    }\r\
    \n    return AbelGroup::op(pos, AbelGroup::inverse(neg));\r\n  }\r\n};\r\n"
  code: "#include \"alg/monoid/add.hpp\"\r\n\r\n// Wavelet Matrix \u4E0A\u3067\u3055\
    \u3089\u306B\u7D2F\u7A4D\u548C\u3092\u7BA1\u7406\u3057\u3066\u3001\r\n// \u77E9\
    \u5F62\u548C\u304C\u3068\u308C\u308B\u3088\u3046\u306B\u3057\u305F\u3082\u306E\
    \r\ntemplate <typename T, bool SUM_QUERY = false,\r\n          typename AbelGroup\
    \ = Monoid_Add<ll>>\r\nstruct WaveletMatrix {\r\n  struct BitVector {\r\n    vector<u64>\
    \ buf;\r\n    vector<int> sum;\r\n    BitVector(const vector<char>& a = {}) {\r\
    \n      int n = a.size();\r\n      buf.assign((n + 63) >> 6, 0);\r\n      sum.assign(buf.size()\
    \ + 1, 0);\r\n      FOR(i, n) if (a[i]) {\r\n        buf[i >> 6] |= 1ull << (i\
    \ & 63);\r\n        sum[(i >> 6) + 1]++;\r\n      }\r\n      FOR(i, buf.size())\
    \ sum[i + 1] += sum[i];\r\n    }\r\n    int rank(int k, bool f = 1) {\r\n    \
    \  int ret = sum[k >> 6]\r\n                + __builtin_popcountll(buf[k >> 6]\
    \ & ((1ull << (k & 63)) - 1));\r\n      if (!f)\r\n        return k - ret;\r\n\
    \      else\r\n        return ret;\r\n    }\r\n  };\r\n\r\n  int N, lg;\r\n  vector<int>\
    \ mid;\r\n  vector<BitVector> bv;\r\n  vector<vector<T>> cumsum;\r\n  vc<T> key;\r\
    \n  WaveletMatrix(vector<T>& dat) : N(dat.size()) {\r\n    key = dat;\r\n    UNIQUE(key);\r\
    \n    vc<int> A(N);\r\n    FOR(i, N) A[i] = LB(key, dat[i]);\r\n    lg = __lg(max(MAX(A),\
    \ 1)) + 1;\r\n\r\n    mid.resize(lg);\r\n    bv.resize(lg);\r\n    cumsum.resize(lg);\r\
    \n    for (int d = lg - 1; d >= 0; d--) {\r\n      vector<char> add;\r\n     \
    \ vector nxt(2, vector<int>());\r\n      for (auto& x: A) {\r\n        add.push_back(x\
    \ >> d & 1);\r\n        nxt[x >> d & 1].push_back(x);\r\n      }\r\n      mid[d]\
    \ = (int)nxt[0].size();\r\n      bv[d] = BitVector(add);\r\n      swap(A, nxt[0]);\r\
    \n      A.insert(A.end(), all(nxt[1]));\r\n      if (SUM_QUERY) {\r\n        vc<T>\
    \ cs(N + 1);\r\n        cs[0] = AbelGroup::unit();\r\n        FOR(i, N) cs[i +\
    \ 1] = AbelGroup::op(cs[i], key[A[i]]);\r\n        cumsum[d] = cs;\r\n      }\r\
    \n    }\r\n  }\r\n\r\n  // [L, R) \u5185\u306B\u3042\u308B [a, b) \u3092\u6570\
    \u3048\u308B\r\n  int freq(int L, int R, T a, T b) {\r\n    return freq_upper(L,\
    \ R, b) - freq_upper(L, R, a);\r\n  }\r\n  int freq_upper(int L, int R, T t) {\r\
    \n    int x = LB(key, t);\r\n    if (x >= (1 << lg)) return R - L;\r\n    int\
    \ ret = 0;\r\n    for (int h = lg - 1; h >= 0; --h) {\r\n      bool f = (x >>\
    \ h) & 1;\r\n      if (f) ret += bv[h].rank(R, 0) - bv[h].rank(L, 0);\r\n    \
    \  L = bv[h].rank(L, f) + (f ? mid[h] : 0);\r\n      R = bv[h].rank(R, f) + (f\
    \ ? mid[h] : 0);\r\n    }\r\n    return ret;\r\n  }\r\n\r\n  // [L, R) \u306E\u4E2D\
    \u3067 k>=0 \u756A\u76EE\r\n  T kth(int L, int R, int k) {\r\n    assert(0 <=\
    \ k && k < R - L);\r\n    int ret = 0;\r\n    for (int h = lg - 1; h >= 0; h--)\
    \ {\r\n      int l0 = bv[h].rank(L, 0), r0 = bv[h].rank(R, 0);\r\n      if (k\
    \ < r0 - l0)\r\n        L = l0, R = r0;\r\n      else {\r\n        k -= r0 - l0;\r\
    \n        ret |= 1 << h;\r\n        L += mid[h] - l0, R += mid[h] - r0;\r\n  \
    \    }\r\n    }\r\n    return key[ret];\r\n  }\r\n\r\n  // [L, R) \u306E\u4E2D\
    \u3067\u5C0F\u3055\u3044\u65B9\u304B\u3089 k \u500B\u306E\u7DCF\u548C\r\n  T sum(int\
    \ L, int R, int k) {\r\n    assert(SUM_QUERY);\r\n    assert(0 <= k && k <= R\
    \ - L);\r\n    T pos = AbelGroup::unit(), neg = AbelGroup::unit();\r\n    for\
    \ (int h = lg - 1; h >= 0; h--) {\r\n      int l0 = bv[h].rank(L, 0), r0 = bv[h].rank(R,\
    \ 0);\r\n      if (k < r0 - l0) {\r\n        L = l0, R = r0;\r\n      } else {\r\
    \n        k -= r0 - l0;\r\n        pos = AbelGroup::op(pos, cumsum[h][r0]);\r\n\
    \        neg = AbelGroup::op(neg, cumsum[h][l0]);\r\n        L += mid[h] - l0,\
    \ R += mid[h] - r0;\r\n      }\r\n    }\r\n    if (k) {\r\n      pos = AbelGroup::op(pos,\
    \ cumsum[0][L + k]);\r\n      neg = AbelGroup::op(neg, cumsum[0][L]);\r\n    }\r\
    \n    return AbelGroup::op(pos, AbelGroup::inverse(neg));\r\n  }\r\n};\r\n"
  dependsOn:
  - alg/monoid/add.hpp
  isVerificationFile: false
  path: ds/waveletmatrix.hpp
  requiredBy: []
  timestamp: '2022-11-28 14:51:10+09:00'
  verificationStatus: LIBRARY_SOME_WA
  verifiedWith:
  - test/yukicoder/2065.test.cpp
  - test/yukicoder/924.test.cpp
  - test/yukicoder/1332.test.cpp
  - test/yukicoder/919.test.cpp
  - test/mytest/wavelet_matrix_sum.test.cpp
  - test/library_checker/datastructure/range_kth_smallest_wavelet.test.cpp
  - test/atcoder/abc127f_1.test.cpp
documentation_of: ds/waveletmatrix.hpp
layout: document
redirect_from:
- /library/ds/waveletmatrix.hpp
- /library/ds/waveletmatrix.hpp.html
title: ds/waveletmatrix.hpp
---
