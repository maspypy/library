---
data:
  _extendedDependsOn:
  - icon: ':question:'
    path: alg/monoid/add.hpp
    title: alg/monoid/add.hpp
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':warning:'
  attributes:
    links: []
  bundledCode: "#line 2 \"alg/monoid/add.hpp\"\n\r\ntemplate <typename X>\r\nstruct\
    \ Monoid_Add {\r\n  using value_type = X;\r\n  static constexpr X op(const X &x,\
    \ const X &y) noexcept { return x + y; }\r\n  static constexpr X inverse(const\
    \ X &x) noexcept { return -x; }\r\n  static constexpr X power(const X &x, ll n)\
    \ noexcept { return X(n) * x; }\r\n  static constexpr X unit() { return X(0);\
    \ }\r\n  static constexpr bool commute = true;\r\n};\r\n#line 2 \"ds/wavelet_matrix_sum.hpp\"\
    \n\n// Wavelet Matrix \u4E0A\u3067\u3055\u3089\u306B\u7D2F\u7A4D\u548C\u3092\u7BA1\
    \u7406\u3057\u3066\u3001\u77E9\u5F62\u548C\u304C\u3068\u308C\u308B\u3088\u3046\
    \u306B\u3057\u305F\u3082\u306E\n// \u548C\u306F\u3001\u5909\u63DB\u95A2\u6570\
    \ f \u3092\u6E21\u3057\u3066\u3001f(x) \u306E\u53EF\u63DB\u7FA4\u306B\u95A2\u3059\
    \u308B\u548C\ntemplate <typename T, typename Monoid = Monoid_Add<T>>\nstruct Wavelet_Matrix_Sum\
    \ {\n  using G = Monoid;\n  using GT = typename G::value_type;\n  static_assert(G::commute);\n\
    \  struct BitVector {\n    vector<u64> buf;\n    vector<int> sum;\n    BitVector(const\
    \ vector<char>& a = {}) {\n      int n = a.size();\n      buf.assign((n + 63)\
    \ >> 6, 0);\n      sum.assign(buf.size() + 1, 0);\n      FOR(i, n) if (a[i]) {\n\
    \        buf[i >> 6] |= 1ull << (i & 63);\n        sum[(i >> 6) + 1]++;\n    \
    \  }\n      FOR(i, buf.size()) sum[i + 1] += sum[i];\n    }\n    int rank(int\
    \ k, bool f = 1) {\n      int ret = sum[k >> 6]\n                + __builtin_popcountll(buf[k\
    \ >> 6] & ((1ull << (k & 63)) - 1));\n      if (!f)\n        return k - ret;\n\
    \      else\n        return ret;\n    }\n  };\n\n  int N, lg;\n  vector<int> mid;\n\
    \  vector<BitVector> bv;\n  vector<vector<GT>> cumsum;\n  vc<T> key;\n\n  template\
    \ <typename F>\n  Wavelet_Matrix_Sum(\n      vector<T>& dat, F f = [](T x) ->\
    \ GT { return x; })\n      : N(dat.size()) {\n    key = dat;\n    UNIQUE(key);\n\
    \    vc<int> A(N);\n    FOR(i, N) A[i] = LB(key, dat[i]);\n    lg = __lg(max(MAX(A),\
    \ 1)) + 1;\n\n    mid.resize(lg);\n    bv.resize(lg);\n    cumsum.resize(lg);\n\
    \    for (int d = lg - 1; d >= 0; d--) {\n      vector<char> add;\n      vector\
    \ nxt(2, vector<int>());\n      for (auto& x: A) {\n        add.push_back(x >>\
    \ d & 1);\n        nxt[x >> d & 1].push_back(x);\n      }\n      mid[d] = (int)nxt[0].size();\n\
    \      bv[d] = BitVector(add);\n      swap(A, nxt[0]);\n      A.insert(A.end(),\
    \ all(nxt[1]));\n      vc<GT> cs(N + 1);\n      cs[0] = G::unit();\n      FOR(i,\
    \ N) cs[i + 1] = G::op(cs[i], f(key[A[i]]));\n      cumsum[d] = cs;\n    }\n \
    \ }\n\n  // [L, R) \u5185\u306B\u3042\u308B [a, b) \u3092\u6570\u3048\u308B\n\
    \  int freq(int L, int R, T a, T b) {\n    return freq_upper(L, R, b) - freq_upper(L,\
    \ R, a);\n  }\n  int freq_upper(int L, int R, T t) {\n    int x = LB(key, t);\n\
    \    if (x >= (1 << lg)) return R - L;\n    int ret = 0;\n    for (int h = lg\
    \ - 1; h >= 0; --h) {\n      bool f = (x >> h) & 1;\n      if (f) ret += bv[h].rank(R,\
    \ 0) - bv[h].rank(L, 0);\n      L = bv[h].rank(L, f) + (f ? mid[h] : 0);\n   \
    \   R = bv[h].rank(R, f) + (f ? mid[h] : 0);\n    }\n    return ret;\n  }\n\n\
    \  // [L, R) \u306E\u4E2D\u3067 k>=0 \u756A\u76EE\n  T kth(int L, int R, int k)\
    \ {\n    assert(0 <= k && k < R - L);\n    int ret = 0;\n    for (int h = lg -\
    \ 1; h >= 0; h--) {\n      int l0 = bv[h].rank(L, 0), r0 = bv[h].rank(R, 0);\n\
    \      if (k < r0 - l0)\n        L = l0, R = r0;\n      else {\n        k -= r0\
    \ - l0;\n        ret |= 1 << h;\n        L += mid[h] - l0, R += mid[h] - r0;\n\
    \      }\n    }\n    return key[ret];\n  }\n\n  // [L, R) \u306E\u4E2D\u3067\u5C0F\
    \u3055\u3044\u65B9\u304B\u3089 k \u500B\u306E\u7DCF\u548C\n  T sum_by_count(int\
    \ L, int R, int k) {\n    assert(0 <= k && k <= R - L);\n    T pos = G::unit(),\
    \ neg = G::unit();\n    for (int h = lg - 1; h >= 0; h--) {\n      int l0 = bv[h].rank(L,\
    \ 0), r0 = bv[h].rank(R, 0);\n      if (k < r0 - l0) {\n        L = l0, R = r0;\n\
    \      } else {\n        k -= r0 - l0;\n        pos = G::op(pos, cumsum[h][r0]);\n\
    \        neg = G::op(neg, cumsum[h][l0]);\n        L += mid[h] - l0, R += mid[h]\
    \ - r0;\n      }\n    }\n    if (k) {\n      pos = G::op(pos, cumsum[0][L + k]);\n\
    \      neg = G::op(neg, cumsum[0][L]);\n    }\n    return G::op(pos, G::inverse(neg));\n\
    \  }\n\n  // [L, R) \u306E\u4E2D\u3067 value \u672A\u6E80\u306E\u3082\u306E\u306E\
    \u548C\n  T sum_by_value(int L, int R, T value) {\n    int x = LB(key, value);\n\
    \    T pos = G::unit(), neg = G::unit();\n    for (int h = lg - 1; h >= 0; h--)\
    \ {\n      bool f = (x >> h) & 1;\n      int l0 = bv[h].rank(L, 0), r0 = bv[h].rank(R,\
    \ 0);\n      if (f) {\n        pos = G::op(pos, cumsum[h][r0]);\n        neg =\
    \ G::op(neg, cumsum[h][l0]);\n      }\n      L = bv[h].rank(L, f) + (f ? mid[h]\
    \ : 0);\n      R = bv[h].rank(R, f) + (f ? mid[h] : 0);\n    }\n    return G::op(pos,\
    \ G::inverse(neg));\n  }\n};\n"
  code: "#include \"alg/monoid/add.hpp\"\n\n// Wavelet Matrix \u4E0A\u3067\u3055\u3089\
    \u306B\u7D2F\u7A4D\u548C\u3092\u7BA1\u7406\u3057\u3066\u3001\u77E9\u5F62\u548C\
    \u304C\u3068\u308C\u308B\u3088\u3046\u306B\u3057\u305F\u3082\u306E\n// \u548C\u306F\
    \u3001\u5909\u63DB\u95A2\u6570 f \u3092\u6E21\u3057\u3066\u3001f(x) \u306E\u53EF\
    \u63DB\u7FA4\u306B\u95A2\u3059\u308B\u548C\ntemplate <typename T, typename Monoid\
    \ = Monoid_Add<T>>\nstruct Wavelet_Matrix_Sum {\n  using G = Monoid;\n  using\
    \ GT = typename G::value_type;\n  static_assert(G::commute);\n  struct BitVector\
    \ {\n    vector<u64> buf;\n    vector<int> sum;\n    BitVector(const vector<char>&\
    \ a = {}) {\n      int n = a.size();\n      buf.assign((n + 63) >> 6, 0);\n  \
    \    sum.assign(buf.size() + 1, 0);\n      FOR(i, n) if (a[i]) {\n        buf[i\
    \ >> 6] |= 1ull << (i & 63);\n        sum[(i >> 6) + 1]++;\n      }\n      FOR(i,\
    \ buf.size()) sum[i + 1] += sum[i];\n    }\n    int rank(int k, bool f = 1) {\n\
    \      int ret = sum[k >> 6]\n                + __builtin_popcountll(buf[k >>\
    \ 6] & ((1ull << (k & 63)) - 1));\n      if (!f)\n        return k - ret;\n  \
    \    else\n        return ret;\n    }\n  };\n\n  int N, lg;\n  vector<int> mid;\n\
    \  vector<BitVector> bv;\n  vector<vector<GT>> cumsum;\n  vc<T> key;\n\n  template\
    \ <typename F>\n  Wavelet_Matrix_Sum(\n      vector<T>& dat, F f = [](T x) ->\
    \ GT { return x; })\n      : N(dat.size()) {\n    key = dat;\n    UNIQUE(key);\n\
    \    vc<int> A(N);\n    FOR(i, N) A[i] = LB(key, dat[i]);\n    lg = __lg(max(MAX(A),\
    \ 1)) + 1;\n\n    mid.resize(lg);\n    bv.resize(lg);\n    cumsum.resize(lg);\n\
    \    for (int d = lg - 1; d >= 0; d--) {\n      vector<char> add;\n      vector\
    \ nxt(2, vector<int>());\n      for (auto& x: A) {\n        add.push_back(x >>\
    \ d & 1);\n        nxt[x >> d & 1].push_back(x);\n      }\n      mid[d] = (int)nxt[0].size();\n\
    \      bv[d] = BitVector(add);\n      swap(A, nxt[0]);\n      A.insert(A.end(),\
    \ all(nxt[1]));\n      vc<GT> cs(N + 1);\n      cs[0] = G::unit();\n      FOR(i,\
    \ N) cs[i + 1] = G::op(cs[i], f(key[A[i]]));\n      cumsum[d] = cs;\n    }\n \
    \ }\n\n  // [L, R) \u5185\u306B\u3042\u308B [a, b) \u3092\u6570\u3048\u308B\n\
    \  int freq(int L, int R, T a, T b) {\n    return freq_upper(L, R, b) - freq_upper(L,\
    \ R, a);\n  }\n  int freq_upper(int L, int R, T t) {\n    int x = LB(key, t);\n\
    \    if (x >= (1 << lg)) return R - L;\n    int ret = 0;\n    for (int h = lg\
    \ - 1; h >= 0; --h) {\n      bool f = (x >> h) & 1;\n      if (f) ret += bv[h].rank(R,\
    \ 0) - bv[h].rank(L, 0);\n      L = bv[h].rank(L, f) + (f ? mid[h] : 0);\n   \
    \   R = bv[h].rank(R, f) + (f ? mid[h] : 0);\n    }\n    return ret;\n  }\n\n\
    \  // [L, R) \u306E\u4E2D\u3067 k>=0 \u756A\u76EE\n  T kth(int L, int R, int k)\
    \ {\n    assert(0 <= k && k < R - L);\n    int ret = 0;\n    for (int h = lg -\
    \ 1; h >= 0; h--) {\n      int l0 = bv[h].rank(L, 0), r0 = bv[h].rank(R, 0);\n\
    \      if (k < r0 - l0)\n        L = l0, R = r0;\n      else {\n        k -= r0\
    \ - l0;\n        ret |= 1 << h;\n        L += mid[h] - l0, R += mid[h] - r0;\n\
    \      }\n    }\n    return key[ret];\n  }\n\n  // [L, R) \u306E\u4E2D\u3067\u5C0F\
    \u3055\u3044\u65B9\u304B\u3089 k \u500B\u306E\u7DCF\u548C\n  T sum_by_count(int\
    \ L, int R, int k) {\n    assert(0 <= k && k <= R - L);\n    T pos = G::unit(),\
    \ neg = G::unit();\n    for (int h = lg - 1; h >= 0; h--) {\n      int l0 = bv[h].rank(L,\
    \ 0), r0 = bv[h].rank(R, 0);\n      if (k < r0 - l0) {\n        L = l0, R = r0;\n\
    \      } else {\n        k -= r0 - l0;\n        pos = G::op(pos, cumsum[h][r0]);\n\
    \        neg = G::op(neg, cumsum[h][l0]);\n        L += mid[h] - l0, R += mid[h]\
    \ - r0;\n      }\n    }\n    if (k) {\n      pos = G::op(pos, cumsum[0][L + k]);\n\
    \      neg = G::op(neg, cumsum[0][L]);\n    }\n    return G::op(pos, G::inverse(neg));\n\
    \  }\n\n  // [L, R) \u306E\u4E2D\u3067 value \u672A\u6E80\u306E\u3082\u306E\u306E\
    \u548C\n  T sum_by_value(int L, int R, T value) {\n    int x = LB(key, value);\n\
    \    T pos = G::unit(), neg = G::unit();\n    for (int h = lg - 1; h >= 0; h--)\
    \ {\n      bool f = (x >> h) & 1;\n      int l0 = bv[h].rank(L, 0), r0 = bv[h].rank(R,\
    \ 0);\n      if (f) {\n        pos = G::op(pos, cumsum[h][r0]);\n        neg =\
    \ G::op(neg, cumsum[h][l0]);\n      }\n      L = bv[h].rank(L, f) + (f ? mid[h]\
    \ : 0);\n      R = bv[h].rank(R, f) + (f ? mid[h] : 0);\n    }\n    return G::op(pos,\
    \ G::inverse(neg));\n  }\n};\n"
  dependsOn:
  - alg/monoid/add.hpp
  isVerificationFile: false
  path: ds/wavelet_matrix_sum.hpp
  requiredBy: []
  timestamp: '2022-12-12 09:21:05+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: ds/wavelet_matrix_sum.hpp
layout: document
redirect_from:
- /library/ds/wavelet_matrix_sum.hpp
- /library/ds/wavelet_matrix_sum.hpp.html
title: ds/wavelet_matrix_sum.hpp
---
