---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/library_checker/datastructure/range_kth_smallest_wavelet.test.cpp
    title: test/library_checker/datastructure/range_kth_smallest_wavelet.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/yukicoder/1332_range_freq.test.cpp
    title: test/yukicoder/1332_range_freq.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/yukicoder/919_waveletmatrix.test.cpp
    title: test/yukicoder/919_waveletmatrix.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/yukicoder/924.test.cpp
    title: test/yukicoder/924.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 1 \"ds/waveletmatrix.hpp\"\n#include <immintrin.h>\r\n\r\nstruct\
    \ bit_vector {\r\n  using u32 = uint32_t;\r\n  using i64 = int64_t;\r\n  using\
    \ u64 = uint64_t;\r\n\r\n  static constexpr u32 w = 64;\r\n  vector<u64> block;\r\
    \n  vector<u32> count;\r\n  u32 n, zeros;\r\n\r\n  inline u32 get(u32 i) const\
    \ { return u32(block[i / w] >> (i % w)) & 1u; }\r\n  inline void set(u32 i) {\
    \ block[i / w] |= 1LL << (i % w); }\r\n\r\n  bit_vector() {}\r\n  bit_vector(int\
    \ _n) { init(_n); }\r\n  __attribute__((optimize(\"O3\", \"unroll-loops\"))) void\
    \ init(int _n) {\r\n    n = zeros = _n;\r\n    block.resize(n / w + 1, 0);\r\n\
    \    count.resize(block.size(), 0);\r\n  }\r\n\r\n  __attribute__((target(\"popcnt\"\
    ))) void build() {\r\n    for (u32 i = 1; i < block.size(); ++i)\r\n      count[i]\
    \ = count[i - 1] + _mm_popcnt_u64(block[i - 1]);\r\n    zeros = rank0(n);\r\n\
    \  }\r\n\r\n  inline u32 rank0(u32 i) const { return i - rank1(i); }\r\n  __attribute__((target(\"\
    bmi2,popcnt\"))) inline u32 rank1(u32 i) const {\r\n    return count[i / w] +\
    \ _mm_popcnt_u64(_bzhi_u64(block[i / w], i % w));\r\n  }\r\n};\r\n\r\n/*\r\n\u30B3\
    \u30F3\u30B9\u30C8\u30E9\u30AF\u30BF\uFF1Avector<T> \u3092\u6E21\u3059\r\n\u9759\
    \u7684\u306A\u5217\u306B\u5BFE\u3057\u3066\u6B21\u304C O(log N) \u6642\u9593\u3067\
    \u884C\u3048\u308B\r\n\u30FBfreq(l, r, lower, upper)\uFF1A[lower, upper) \u5185\
    \u306E\u8981\u7D20\u306E\u6570\u3048\u4E0A\u3052\r\n\u30FBkth(l, r, lower, upper)\uFF1A\
    [lower, upper) \u5185\u3092\u30BD\u30FC\u30C8\u3057\u305F\u3068\u304D\u306E k\
    \ \u756A\u76EE\r\n*/\r\ntemplate <typename T>\r\nstruct WaveletMatrix {\r\n  using\
    \ u32 = uint32_t;\r\n  using i64 = int64_t;\r\n  using u64 = uint64_t;\r\n\r\n\
    \  int n, lg;\r\n  vc<T> key;\r\n  vc<int> A;\r\n  vector<bit_vector> bv;\r\n\r\
    \n  __attribute__((optimize(\"O3\"))) WaveletMatrix(const vc<T>& dat)\r\n    \
    \  : n(len(dat)) {\r\n    key = dat;\r\n    UNIQUE(key);\r\n    A.resize(n);\r\
    \n    FOR(i, n) A[i] = LB(key, dat[i]);\r\n    lg = __lg(max(MAX(A), 1)) + 1;\r\
    \n    bv.assign(lg, n);\r\n    vc<int> cur = A, nxt(n);\r\n    for (int h = lg\
    \ - 1; h >= 0; --h) {\r\n      for (int i = 0; i < n; ++i)\r\n        if ((cur[i]\
    \ >> h) & 1) bv[h].set(i);\r\n      bv[h].build();\r\n      array<decltype(begin(nxt)),\
    \ 2> it{begin(nxt), begin(nxt) + bv[h].zeros};\r\n      for (int i = 0; i < n;\
    \ ++i) *it[bv[h].get(i)]++ = cur[i];\r\n      swap(cur, nxt);\r\n    }\r\n  }\r\
    \n\r\n  inline pair<u32, u32> succ0(int l, int r, int h) const {\r\n    return\
    \ make_pair(bv[h].rank0(l), bv[h].rank0(r));\r\n  }\r\n\r\n  inline pair<u32,\
    \ u32> succ1(int l, int r, int h) const {\r\n    u32 l0 = bv[h].rank0(l);\r\n\
    \    u32 r0 = bv[h].rank0(r);\r\n    u32 zeros = bv[h].zeros;\r\n    return make_pair(l\
    \ + zeros - l0, r + zeros - r0);\r\n  }\r\n\r\n  T kth(u32 l, u32 r, u32 k) const\
    \ {\r\n    int res = 0;\r\n    for (int h = lg - 1; h >= 0; --h) {\r\n      u32\
    \ l0 = bv[h].rank0(l), r0 = bv[h].rank0(r);\r\n      if (k < r0 - l0)\r\n    \
    \    l = l0, r = r0;\r\n      else {\r\n        k -= r0 - l0;\r\n        res |=\
    \ 1 << h;\r\n        l += bv[h].zeros - l0;\r\n        r += bv[h].zeros - r0;\r\
    \n      }\r\n    }\r\n    return key[res];\r\n  }\r\n\r\n  int freq(int l, int\
    \ r, T lower, T upper) {\r\n    return freq_upper(l, r, upper) - freq_upper(l,\
    \ r, lower);\r\n  }\r\n\r\nprivate:\r\n  int freq_upper(int l, int r, T upper_t)\
    \ {\r\n    int upper = LB(key, upper_t);\r\n    if (upper >= (1 << lg)) return\
    \ r - l;\r\n    int ret = 0;\r\n    for (int h = lg - 1; h >= 0; --h) {\r\n  \
    \    bool f = (upper >> h) & 1;\r\n      u32 l0 = bv[h].rank0(l), r0 = bv[h].rank0(r);\r\
    \n      if (f) {\r\n        ret += r0 - l0;\r\n        l += bv[h].zeros - l0;\r\
    \n        r += bv[h].zeros - r0;\r\n      } else {\r\n        l = l0;\r\n    \
    \    r = r0;\r\n      }\r\n    }\r\n    return ret;\r\n  }\r\n};\n"
  code: "#include <immintrin.h>\r\n\r\nstruct bit_vector {\r\n  using u32 = uint32_t;\r\
    \n  using i64 = int64_t;\r\n  using u64 = uint64_t;\r\n\r\n  static constexpr\
    \ u32 w = 64;\r\n  vector<u64> block;\r\n  vector<u32> count;\r\n  u32 n, zeros;\r\
    \n\r\n  inline u32 get(u32 i) const { return u32(block[i / w] >> (i % w)) & 1u;\
    \ }\r\n  inline void set(u32 i) { block[i / w] |= 1LL << (i % w); }\r\n\r\n  bit_vector()\
    \ {}\r\n  bit_vector(int _n) { init(_n); }\r\n  __attribute__((optimize(\"O3\"\
    , \"unroll-loops\"))) void init(int _n) {\r\n    n = zeros = _n;\r\n    block.resize(n\
    \ / w + 1, 0);\r\n    count.resize(block.size(), 0);\r\n  }\r\n\r\n  __attribute__((target(\"\
    popcnt\"))) void build() {\r\n    for (u32 i = 1; i < block.size(); ++i)\r\n \
    \     count[i] = count[i - 1] + _mm_popcnt_u64(block[i - 1]);\r\n    zeros = rank0(n);\r\
    \n  }\r\n\r\n  inline u32 rank0(u32 i) const { return i - rank1(i); }\r\n  __attribute__((target(\"\
    bmi2,popcnt\"))) inline u32 rank1(u32 i) const {\r\n    return count[i / w] +\
    \ _mm_popcnt_u64(_bzhi_u64(block[i / w], i % w));\r\n  }\r\n};\r\n\r\n/*\r\n\u30B3\
    \u30F3\u30B9\u30C8\u30E9\u30AF\u30BF\uFF1Avector<T> \u3092\u6E21\u3059\r\n\u9759\
    \u7684\u306A\u5217\u306B\u5BFE\u3057\u3066\u6B21\u304C O(log N) \u6642\u9593\u3067\
    \u884C\u3048\u308B\r\n\u30FBfreq(l, r, lower, upper)\uFF1A[lower, upper) \u5185\
    \u306E\u8981\u7D20\u306E\u6570\u3048\u4E0A\u3052\r\n\u30FBkth(l, r, lower, upper)\uFF1A\
    [lower, upper) \u5185\u3092\u30BD\u30FC\u30C8\u3057\u305F\u3068\u304D\u306E k\
    \ \u756A\u76EE\r\n*/\r\ntemplate <typename T>\r\nstruct WaveletMatrix {\r\n  using\
    \ u32 = uint32_t;\r\n  using i64 = int64_t;\r\n  using u64 = uint64_t;\r\n\r\n\
    \  int n, lg;\r\n  vc<T> key;\r\n  vc<int> A;\r\n  vector<bit_vector> bv;\r\n\r\
    \n  __attribute__((optimize(\"O3\"))) WaveletMatrix(const vc<T>& dat)\r\n    \
    \  : n(len(dat)) {\r\n    key = dat;\r\n    UNIQUE(key);\r\n    A.resize(n);\r\
    \n    FOR(i, n) A[i] = LB(key, dat[i]);\r\n    lg = __lg(max(MAX(A), 1)) + 1;\r\
    \n    bv.assign(lg, n);\r\n    vc<int> cur = A, nxt(n);\r\n    for (int h = lg\
    \ - 1; h >= 0; --h) {\r\n      for (int i = 0; i < n; ++i)\r\n        if ((cur[i]\
    \ >> h) & 1) bv[h].set(i);\r\n      bv[h].build();\r\n      array<decltype(begin(nxt)),\
    \ 2> it{begin(nxt), begin(nxt) + bv[h].zeros};\r\n      for (int i = 0; i < n;\
    \ ++i) *it[bv[h].get(i)]++ = cur[i];\r\n      swap(cur, nxt);\r\n    }\r\n  }\r\
    \n\r\n  inline pair<u32, u32> succ0(int l, int r, int h) const {\r\n    return\
    \ make_pair(bv[h].rank0(l), bv[h].rank0(r));\r\n  }\r\n\r\n  inline pair<u32,\
    \ u32> succ1(int l, int r, int h) const {\r\n    u32 l0 = bv[h].rank0(l);\r\n\
    \    u32 r0 = bv[h].rank0(r);\r\n    u32 zeros = bv[h].zeros;\r\n    return make_pair(l\
    \ + zeros - l0, r + zeros - r0);\r\n  }\r\n\r\n  T kth(u32 l, u32 r, u32 k) const\
    \ {\r\n    int res = 0;\r\n    for (int h = lg - 1; h >= 0; --h) {\r\n      u32\
    \ l0 = bv[h].rank0(l), r0 = bv[h].rank0(r);\r\n      if (k < r0 - l0)\r\n    \
    \    l = l0, r = r0;\r\n      else {\r\n        k -= r0 - l0;\r\n        res |=\
    \ 1 << h;\r\n        l += bv[h].zeros - l0;\r\n        r += bv[h].zeros - r0;\r\
    \n      }\r\n    }\r\n    return key[res];\r\n  }\r\n\r\n  int freq(int l, int\
    \ r, T lower, T upper) {\r\n    return freq_upper(l, r, upper) - freq_upper(l,\
    \ r, lower);\r\n  }\r\n\r\nprivate:\r\n  int freq_upper(int l, int r, T upper_t)\
    \ {\r\n    int upper = LB(key, upper_t);\r\n    if (upper >= (1 << lg)) return\
    \ r - l;\r\n    int ret = 0;\r\n    for (int h = lg - 1; h >= 0; --h) {\r\n  \
    \    bool f = (upper >> h) & 1;\r\n      u32 l0 = bv[h].rank0(l), r0 = bv[h].rank0(r);\r\
    \n      if (f) {\r\n        ret += r0 - l0;\r\n        l += bv[h].zeros - l0;\r\
    \n        r += bv[h].zeros - r0;\r\n      } else {\r\n        l = l0;\r\n    \
    \    r = r0;\r\n      }\r\n    }\r\n    return ret;\r\n  }\r\n};"
  dependsOn: []
  isVerificationFile: false
  path: ds/waveletmatrix.hpp
  requiredBy: []
  timestamp: '2022-05-02 00:48:11+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/yukicoder/1332_range_freq.test.cpp
  - test/yukicoder/919_waveletmatrix.test.cpp
  - test/yukicoder/924.test.cpp
  - test/library_checker/datastructure/range_kth_smallest_wavelet.test.cpp
documentation_of: ds/waveletmatrix.hpp
layout: document
redirect_from:
- /library/ds/waveletmatrix.hpp
- /library/ds/waveletmatrix.hpp.html
title: ds/waveletmatrix.hpp
---
