---
data:
  _extendedDependsOn:
  - icon: ':question:'
    path: ds/unionfind/unionfind.hpp
    title: ds/unionfind/unionfind.hpp
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':x:'
    path: test/2_library_checker/data_structure/range_parallel_uf.test.cpp
    title: test/2_library_checker/data_structure/range_parallel_uf.test.cpp
  _isVerificationFailed: true
  _pathExtension: hpp
  _verificationStatusIcon: ':x:'
  attributes:
    links: []
  bundledCode: "#line 2 \"ds/unionfind/unionfind.hpp\"\n\nstruct UnionFind {\n  int\
    \ n, n_comp;\n  vc<int> dat; // par or (-size)\n  UnionFind(int n = 0) { build(n);\
    \ }\n\n  void build(int m) {\n    n = m, n_comp = m;\n    dat.assign(n, -1);\n\
    \  }\n\n  void reset() { build(n); }\n\n  int operator[](int x) {\n    while (dat[x]\
    \ >= 0) {\n      int pp = dat[dat[x]];\n      if (pp < 0) { return dat[x]; }\n\
    \      x = dat[x] = pp;\n    }\n    return x;\n  }\n\n  ll size(int x) {\n   \
    \ x = (*this)[x];\n    return -dat[x];\n  }\n\n  bool merge(int x, int y) {\n\
    \    x = (*this)[x], y = (*this)[y];\n    if (x == y) return false;\n    if (-dat[x]\
    \ < -dat[y]) swap(x, y);\n    dat[x] += dat[y], dat[y] = x, n_comp--;\n    return\
    \ true;\n  }\n\n  vc<int> get_all() {\n    vc<int> A(n);\n    FOR(i, n) A[i] =\
    \ (*this)[i];\n    return A;\n  }\n};\n#line 2 \"ds/unionfind/parallel_unionfind.hpp\"\
    \n\nstruct Range_Parallel_UnionFind {\n  int N;\n  int log;\n  // ufs[i][a]==ufs[i][b]\
    \ iff [a,...,a+2^i) == [b,...,b+2^i)\n  vc<UnionFind> ufs;\n  Range_Parallel_UnionFind(int\
    \ n) : N(n) {\n    log = 1;\n    while ((1 << log) < n) ++log;\n    ufs.resize(log);\n\
    \    FOR(i, log) {\n      ll n = 1 << i;\n      ufs[i].build(N - n + 1);\n   \
    \ }\n  }\n\n  // f(r1,r2) : \u6210\u5206 r2 \u3092 r1 \u306B\u30DE\u30FC\u30B8\
    \n  template <typename F>\n  void merge(int L1, int R1, int L2, int R2, F f) {\n\
    \    assert(R1 - L1 == R2 - L2);\n    int n = R1 - L1;\n    if (n == 0) return;\n\
    \    if (n == 1) return merge_inner(0, L1, L2, f);\n    int k = topbit(n - 1);\n\
    \    merge_inner(k, L1, L2, f);\n    merge_inner(k, R1 - (1 << k), R2 - (1 <<\
    \ k), f);\n  }\n\n  // f(r1,r2) : \u6210\u5206 r2 \u3092 r1 \u306B\u30DE\u30FC\
    \u30B8\n  template <typename F>\n  void merge(int i, int j, F f) {\n    merge_inner(0,\
    \ i, j, f);\n  }\n\n  template <typename F>\n  void merge_inner(int k, int L1,\
    \ int L2, const F& f) {\n    if (k == 0) {\n      int a = ufs[0][L1], b = ufs[0][L2];\n\
    \      if (a == b) return;\n      ufs[0].merge(a, b);\n      int c = ufs[0][a];\n\
    \      return f(c, a ^ b ^ c);\n    }\n    if (!ufs[k].merge(L1, L2)) return;\n\
    \    merge_inner(k - 1, L1, L2, f);\n    merge_inner(k - 1, L1 + (1 << (k - 1)),\
    \ L2 + (1 << (k - 1)), f);\n  }\n};\n"
  code: "#include \"ds/unionfind/unionfind.hpp\"\n\nstruct Range_Parallel_UnionFind\
    \ {\n  int N;\n  int log;\n  // ufs[i][a]==ufs[i][b] iff [a,...,a+2^i) == [b,...,b+2^i)\n\
    \  vc<UnionFind> ufs;\n  Range_Parallel_UnionFind(int n) : N(n) {\n    log = 1;\n\
    \    while ((1 << log) < n) ++log;\n    ufs.resize(log);\n    FOR(i, log) {\n\
    \      ll n = 1 << i;\n      ufs[i].build(N - n + 1);\n    }\n  }\n\n  // f(r1,r2)\
    \ : \u6210\u5206 r2 \u3092 r1 \u306B\u30DE\u30FC\u30B8\n  template <typename F>\n\
    \  void merge(int L1, int R1, int L2, int R2, F f) {\n    assert(R1 - L1 == R2\
    \ - L2);\n    int n = R1 - L1;\n    if (n == 0) return;\n    if (n == 1) return\
    \ merge_inner(0, L1, L2, f);\n    int k = topbit(n - 1);\n    merge_inner(k, L1,\
    \ L2, f);\n    merge_inner(k, R1 - (1 << k), R2 - (1 << k), f);\n  }\n\n  // f(r1,r2)\
    \ : \u6210\u5206 r2 \u3092 r1 \u306B\u30DE\u30FC\u30B8\n  template <typename F>\n\
    \  void merge(int i, int j, F f) {\n    merge_inner(0, i, j, f);\n  }\n\n  template\
    \ <typename F>\n  void merge_inner(int k, int L1, int L2, const F& f) {\n    if\
    \ (k == 0) {\n      int a = ufs[0][L1], b = ufs[0][L2];\n      if (a == b) return;\n\
    \      ufs[0].merge(a, b);\n      int c = ufs[0][a];\n      return f(c, a ^ b\
    \ ^ c);\n    }\n    if (!ufs[k].merge(L1, L2)) return;\n    merge_inner(k - 1,\
    \ L1, L2, f);\n    merge_inner(k - 1, L1 + (1 << (k - 1)), L2 + (1 << (k - 1)),\
    \ f);\n  }\n};\n"
  dependsOn:
  - ds/unionfind/unionfind.hpp
  isVerificationFile: false
  path: ds/unionfind/parallel_unionfind.hpp
  requiredBy: []
  timestamp: '2024-06-12 04:39:59+09:00'
  verificationStatus: LIBRARY_ALL_WA
  verifiedWith:
  - test/2_library_checker/data_structure/range_parallel_uf.test.cpp
documentation_of: ds/unionfind/parallel_unionfind.hpp
layout: document
redirect_from:
- /library/ds/unionfind/parallel_unionfind.hpp
- /library/ds/unionfind/parallel_unionfind.hpp.html
title: ds/unionfind/parallel_unionfind.hpp
---
