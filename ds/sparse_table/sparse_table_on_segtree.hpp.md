---
data:
  _extendedDependsOn:
  - icon: ':question:'
    path: ds/sparse_table/sparse_table.hpp
    title: ds/sparse_table/sparse_table.hpp
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':x:'
    path: test/3_yukicoder/866.test.cpp
    title: test/3_yukicoder/866.test.cpp
  _isVerificationFailed: true
  _pathExtension: hpp
  _verificationStatusIcon: ':x:'
  attributes:
    links:
    - https://codeforces.com/problemset/problem/713/D
  bundledCode: "#line 1 \"ds/sparse_table/sparse_table.hpp\"\n\n// \u51AA\u7B49\u306A\
    \u30E2\u30CE\u30A4\u30C9\u3067\u3042\u308B\u3053\u3068\u3092\u4EEE\u5B9A\u3002\
    disjoint sparse table \u3088\u308A x \u500D\u9AD8\u901F\ntemplate <class Monoid>\n\
    struct Sparse_Table {\n  using MX = Monoid;\n  using X = typename MX::value_type;\n\
    \  int n, log;\n  vvc<X> dat;\n\n  Sparse_Table() {}\n  Sparse_Table(int n) {\
    \ build(n); }\n  template <typename F>\n  Sparse_Table(int n, F f) {\n    build(n,\
    \ f);\n  }\n  Sparse_Table(const vc<X>& v) { build(v); }\n\n  void build(int m)\
    \ {\n    build(m, [](int i) -> X { return MX::id(); });\n  }\n  void build(const\
    \ vc<X>& v) {\n    build(len(v), [&](int i) -> X { return v[i]; });\n  }\n  template\
    \ <typename F>\n  void build(int m, F f) {\n    n = m, log = 1;\n    while ((1\
    \ << log) < n) ++log;\n    dat.resize(log);\n    dat[0].resize(n);\n    FOR(i,\
    \ n) dat[0][i] = f(i);\n\n    FOR(i, log - 1) {\n      dat[i + 1].resize(len(dat[i])\
    \ - (1 << i));\n      FOR(j, len(dat[i]) - (1 << i)) {\n        dat[i + 1][j]\
    \ = MX::op(dat[i][j], dat[i][j + (1 << i)]);\n      }\n    }\n  }\n\n  X prod(int\
    \ L, int R) const {\n    if (L == R) return MX::id();\n    if (R == L + 1) return\
    \ dat[0][L];\n    int k = topbit(R - L - 1);\n    return MX::op(dat[k][L], dat[k][R\
    \ - (1 << k)]);\n  }\n\n  template <class F>\n  int max_right(const F check, int\
    \ L) const {\n    assert(0 <= L && L <= n && check(MX::id()));\n    if (L == n)\
    \ return n;\n    int ok = L, ng = n + 1;\n    while (ok + 1 < ng) {\n      int\
    \ k = (ok + ng) / 2;\n      bool bl = check(prod(L, k));\n      if (bl) ok = k;\n\
    \      if (!bl) ng = k;\n    }\n    return ok;\n  }\n\n  template <class F>\n\
    \  int min_left(const F check, int R) const {\n    assert(0 <= R && R <= n &&\
    \ check(MX::id()));\n    if (R == 0) return 0;\n    int ok = R, ng = -1;\n   \
    \ while (ng + 1 < ok) {\n      int k = (ok + ng) / 2;\n      bool bl = check(prod(k,\
    \ R));\n      if (bl) ok = k;\n      if (!bl) ng = k;\n    }\n    return ok;\n\
    \  }\n};\n#line 2 \"ds/sparse_table/sparse_table_on_segtree.hpp\"\n/*\nhttps://codeforces.com/problemset/problem/713/D\n\
    \u30FBsparse_table OR disjoint_sparse table \u3092\u30BB\u30B0\u6728\u306B\u4E57\
    \u305B\u308B\n\u30FB\u69CB\u7BC9 O(HW log W)\n\u30FB\u30AF\u30A8\u30EA O(log H)\n\
    */\ntemplate <typename SPARSE_TABLE>\nstruct Sparse_Table_on_SegTree {\n  using\
    \ ST = SPARSE_TABLE;\n  using MX = typename ST::MX;\n  using X = typename MX::value_type;\n\
    \  using value_type = X;\n  static_assert(MX::commute);\n  int H, W;\n  vc<ST>\
    \ dat;\n\n  Sparse_Table_on_SegTree() {}\n  Sparse_Table_on_SegTree(vvc<X> &v)\
    \ {\n    H = len(v), W = (H == 0 ? 0 : len(v[0]));\n    dat.resize(2 * H);\n \
    \   FOR(i, H) { dat[H + i] = ST(v[i]); }\n    FOR_R(i, 1, H) {\n      dat[i] =\
    \ ST(W, [&](int j) -> X {\n        X x = dat[2 * i + 0].prod(j, j + 1);\n    \
    \    X y = dat[2 * i + 1].prod(j, j + 1);\n        return MX::op(x, y);\n    \
    \  });\n    }\n  }\n\n  X prod(int xl, int xr, int yl, int yr) {\n    assert(0\
    \ <= xl && xl <= xr && xr <= H);\n    assert(0 <= yl && yl <= yr && yr <= W);\n\
    \    X res = MX::id();\n    xl += H, xr += H;\n    while (xl < xr) {\n      if\
    \ (xl & 1) res = MX::op(res, dat[xl++].prod(yl, yr));\n      if (xr & 1) res =\
    \ MX::op(res, dat[--xr].prod(yl, yr));\n      xl >>= 1, xr >>= 1;\n    }\n   \
    \ return res;\n  }\n};\n"
  code: "#include \"ds/sparse_table/sparse_table.hpp\"\n/*\nhttps://codeforces.com/problemset/problem/713/D\n\
    \u30FBsparse_table OR disjoint_sparse table \u3092\u30BB\u30B0\u6728\u306B\u4E57\
    \u305B\u308B\n\u30FB\u69CB\u7BC9 O(HW log W)\n\u30FB\u30AF\u30A8\u30EA O(log H)\n\
    */\ntemplate <typename SPARSE_TABLE>\nstruct Sparse_Table_on_SegTree {\n  using\
    \ ST = SPARSE_TABLE;\n  using MX = typename ST::MX;\n  using X = typename MX::value_type;\n\
    \  using value_type = X;\n  static_assert(MX::commute);\n  int H, W;\n  vc<ST>\
    \ dat;\n\n  Sparse_Table_on_SegTree() {}\n  Sparse_Table_on_SegTree(vvc<X> &v)\
    \ {\n    H = len(v), W = (H == 0 ? 0 : len(v[0]));\n    dat.resize(2 * H);\n \
    \   FOR(i, H) { dat[H + i] = ST(v[i]); }\n    FOR_R(i, 1, H) {\n      dat[i] =\
    \ ST(W, [&](int j) -> X {\n        X x = dat[2 * i + 0].prod(j, j + 1);\n    \
    \    X y = dat[2 * i + 1].prod(j, j + 1);\n        return MX::op(x, y);\n    \
    \  });\n    }\n  }\n\n  X prod(int xl, int xr, int yl, int yr) {\n    assert(0\
    \ <= xl && xl <= xr && xr <= H);\n    assert(0 <= yl && yl <= yr && yr <= W);\n\
    \    X res = MX::id();\n    xl += H, xr += H;\n    while (xl < xr) {\n      if\
    \ (xl & 1) res = MX::op(res, dat[xl++].prod(yl, yr));\n      if (xr & 1) res =\
    \ MX::op(res, dat[--xr].prod(yl, yr));\n      xl >>= 1, xr >>= 1;\n    }\n   \
    \ return res;\n  }\n};"
  dependsOn:
  - ds/sparse_table/sparse_table.hpp
  isVerificationFile: false
  path: ds/sparse_table/sparse_table_on_segtree.hpp
  requiredBy: []
  timestamp: '2026-09-28 10:13:21+09:00'
  verificationStatus: LIBRARY_ALL_WA
  verifiedWith:
  - test/3_yukicoder/866.test.cpp
documentation_of: ds/sparse_table/sparse_table_on_segtree.hpp
layout: document
redirect_from:
- /library/ds/sparse_table/sparse_table_on_segtree.hpp
- /library/ds/sparse_table/sparse_table_on_segtree.hpp.html
title: ds/sparse_table/sparse_table_on_segtree.hpp
---
