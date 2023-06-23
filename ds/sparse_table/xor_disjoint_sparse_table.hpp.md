---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':x:'
    path: test/yukicoder/1891.test.cpp
    title: test/yukicoder/1891.test.cpp
  _isVerificationFailed: true
  _pathExtension: hpp
  _verificationStatusIcon: ':x:'
  attributes:
    links: []
  bundledCode: "#line 1 \"ds/sparse_table/xor_disjoint_sparse_table.hpp\"\ntemplate\
    \ <typename Monoid>\nstruct Xor_Disjoint_Sparse_Table {\n  using MX = Monoid;\n\
    \  using X = typename Monoid::value_type;\n  int log;\n  vvc<X> dat;\n\n  Xor_Disjoint_Sparse_Table()\
    \ {}\n  Xor_Disjoint_Sparse_Table(int n) { build(n); }\n  template <typename F>\n\
    \  Xor_Disjoint_Sparse_Table(int n, F f) {\n    build(n, f);\n  }\n  Xor_Disjoint_Sparse_Table(const\
    \ vc<X>& v) { build(v); }\n\n  void build(int m) {\n    build(m, [](int i) ->\
    \ X { return MX::unit(); });\n  }\n  void build(const vc<X>& v) {\n    build(len(v),\
    \ [&](int i) -> X { return v[i]; });\n  }\n  template <typename F>\n  void build(int\
    \ m, F f) {\n    log = 0;\n    while ((1 << log) < m) ++log;\n    assert(m ==\
    \ (1 << log));\n    // \u5404 k, i \u306B\u5BFE\u3057\u3066\u3001prod_{0<=j<2^k}\
    \ A[i^j] \u3092\u6301\u3064\n    dat.resize(log + 1);\n    dat[0].reserve(1 <<\
    \ log);\n    FOR(i, 1 << log) dat[0].eb(f(i));\n    FOR(k, log) {\n      dat[k\
    \ + 1].assign(1 << log, MX::unit());\n      FOR(i, 1 << log) {\n        dat[k\
    \ + 1][i] = MX::op(dat[k][i], dat[k][i ^ (1 << k)]);\n      }\n    }\n  }\n\n\
    \  // calculate prod_{l<=i<r} A[x xor i], in O(log N) time.\n  X prod(int l, int\
    \ r, int xor_val) {\n    X xl = MX::unit(), xr = MX::unit();\n    FOR(k, log +\
    \ 1) {\n      if (l >= r) break;\n      if (l & 1 << k) {\n        xl = MX::op(xl,\
    \ dat[k][l ^ xor_val]);\n        l += (1 << k);\n      }\n      if (r & 1 << k)\
    \ {\n        r -= (1 << k);\n        xr = MX::op(dat[k][r ^ xor_val], xr);\n \
    \     }\n    }\n    return MX::op(xl, xr);\n  }\n};\n"
  code: "template <typename Monoid>\nstruct Xor_Disjoint_Sparse_Table {\n  using MX\
    \ = Monoid;\n  using X = typename Monoid::value_type;\n  int log;\n  vvc<X> dat;\n\
    \n  Xor_Disjoint_Sparse_Table() {}\n  Xor_Disjoint_Sparse_Table(int n) { build(n);\
    \ }\n  template <typename F>\n  Xor_Disjoint_Sparse_Table(int n, F f) {\n    build(n,\
    \ f);\n  }\n  Xor_Disjoint_Sparse_Table(const vc<X>& v) { build(v); }\n\n  void\
    \ build(int m) {\n    build(m, [](int i) -> X { return MX::unit(); });\n  }\n\
    \  void build(const vc<X>& v) {\n    build(len(v), [&](int i) -> X { return v[i];\
    \ });\n  }\n  template <typename F>\n  void build(int m, F f) {\n    log = 0;\n\
    \    while ((1 << log) < m) ++log;\n    assert(m == (1 << log));\n    // \u5404\
    \ k, i \u306B\u5BFE\u3057\u3066\u3001prod_{0<=j<2^k} A[i^j] \u3092\u6301\u3064\
    \n    dat.resize(log + 1);\n    dat[0].reserve(1 << log);\n    FOR(i, 1 << log)\
    \ dat[0].eb(f(i));\n    FOR(k, log) {\n      dat[k + 1].assign(1 << log, MX::unit());\n\
    \      FOR(i, 1 << log) {\n        dat[k + 1][i] = MX::op(dat[k][i], dat[k][i\
    \ ^ (1 << k)]);\n      }\n    }\n  }\n\n  // calculate prod_{l<=i<r} A[x xor i],\
    \ in O(log N) time.\n  X prod(int l, int r, int xor_val) {\n    X xl = MX::unit(),\
    \ xr = MX::unit();\n    FOR(k, log + 1) {\n      if (l >= r) break;\n      if\
    \ (l & 1 << k) {\n        xl = MX::op(xl, dat[k][l ^ xor_val]);\n        l +=\
    \ (1 << k);\n      }\n      if (r & 1 << k) {\n        r -= (1 << k);\n      \
    \  xr = MX::op(dat[k][r ^ xor_val], xr);\n      }\n    }\n    return MX::op(xl,\
    \ xr);\n  }\n};"
  dependsOn: []
  isVerificationFile: false
  path: ds/sparse_table/xor_disjoint_sparse_table.hpp
  requiredBy: []
  timestamp: '2023-04-08 01:03:35+09:00'
  verificationStatus: LIBRARY_ALL_WA
  verifiedWith:
  - test/yukicoder/1891.test.cpp
documentation_of: ds/sparse_table/xor_disjoint_sparse_table.hpp
layout: document
redirect_from:
- /library/ds/sparse_table/xor_disjoint_sparse_table.hpp
- /library/ds/sparse_table/xor_disjoint_sparse_table.hpp.html
title: ds/sparse_table/xor_disjoint_sparse_table.hpp
---
