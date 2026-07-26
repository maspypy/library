---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':warning:'
  attributes:
    links:
    - https://codeforces.com/problemset/problem/713/D
  bundledCode: "#line 1 \"ds/sparse_table/sparse_table_on_segtree.hpp\"\n\n/*\nhttps://codeforces.com/problemset/problem/713/D\n\
    \u30FBsparse_table OR disjoint_sparse table \u3092\u30BB\u30B0\u6728\u306B\u4E57\
    \u305B\u308B\n\u30FB\u69CB\u7BC9 O(HW log W)\n\u30FB\u30AF\u30A8\u30EA O(log H)\n\
    */\ntemplate <typename SPARSE_TABLE>\nstruct Sparse_Table_On_SegTree {\n  using\
    \ ST = SPARSE_TABLE;\n  using MX = typename ST::MX;\n  using X = typename MX::value_type;\n\
    \  using value_type = X;\n  static_assert(MX::commute);\n  int H, W;\n  vc<ST>\
    \ dat;\n\n  Sparse_Table_On_SegTree() {}\n  Sparse_Table_On_SegTree(vvc<X> &v)\
    \ {\n    H = len(v), W = (H == 0 ? 0 : len(v[0]));\n    dat.resize(2 * H);\n \
    \   FOR(i, H) { dat[H + i] = ST(v[i]); }\n    FOR_R(i, 1, H) {\n      dat[i] =\
    \ ST(W, [&](int j) -> X {\n        X x = dat[2 * i + 0].prod(j, j + 1);\n    \
    \    X y = dat[2 * i + 1].prod(j, j + 1);\n        return MX::op(x, y);\n    \
    \  });\n    }\n  }\n\n  X prod(int xl, int xr, int yl, int yr) {\n    assert(0\
    \ <= xl && xl <= xr && xr <= H);\n    assert(0 <= yl && yl <= yr && yr <= W);\n\
    \    X res = MX::unit();\n    xl += H, xr += H;\n    while (xl < xr) {\n     \
    \ if (xl & 1) res = MX::op(res, dat[xl++].prod(yl, yr));\n      if (xr & 1) res\
    \ = MX::op(res, dat[--xr].prod(yl, yr));\n      xl >>= 1, xr >>= 1;\n    }\n \
    \   return res;\n  }\n};\n"
  code: "\n/*\nhttps://codeforces.com/problemset/problem/713/D\n\u30FBsparse_table\
    \ OR disjoint_sparse table \u3092\u30BB\u30B0\u6728\u306B\u4E57\u305B\u308B\n\u30FB\
    \u69CB\u7BC9 O(HW log W)\n\u30FB\u30AF\u30A8\u30EA O(log H)\n*/\ntemplate <typename\
    \ SPARSE_TABLE>\nstruct Sparse_Table_On_SegTree {\n  using ST = SPARSE_TABLE;\n\
    \  using MX = typename ST::MX;\n  using X = typename MX::value_type;\n  using\
    \ value_type = X;\n  static_assert(MX::commute);\n  int H, W;\n  vc<ST> dat;\n\
    \n  Sparse_Table_On_SegTree() {}\n  Sparse_Table_On_SegTree(vvc<X> &v) {\n   \
    \ H = len(v), W = (H == 0 ? 0 : len(v[0]));\n    dat.resize(2 * H);\n    FOR(i,\
    \ H) { dat[H + i] = ST(v[i]); }\n    FOR_R(i, 1, H) {\n      dat[i] = ST(W, [&](int\
    \ j) -> X {\n        X x = dat[2 * i + 0].prod(j, j + 1);\n        X y = dat[2\
    \ * i + 1].prod(j, j + 1);\n        return MX::op(x, y);\n      });\n    }\n \
    \ }\n\n  X prod(int xl, int xr, int yl, int yr) {\n    assert(0 <= xl && xl <=\
    \ xr && xr <= H);\n    assert(0 <= yl && yl <= yr && yr <= W);\n    X res = MX::unit();\n\
    \    xl += H, xr += H;\n    while (xl < xr) {\n      if (xl & 1) res = MX::op(res,\
    \ dat[xl++].prod(yl, yr));\n      if (xr & 1) res = MX::op(res, dat[--xr].prod(yl,\
    \ yr));\n      xl >>= 1, xr >>= 1;\n    }\n    return res;\n  }\n};"
  dependsOn: []
  isVerificationFile: false
  path: ds/sparse_table/sparse_table_on_segtree.hpp
  requiredBy: []
  timestamp: '2023-09-18 22:09:51+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: ds/sparse_table/sparse_table_on_segtree.hpp
layout: document
redirect_from:
- /library/ds/sparse_table/sparse_table_on_segtree.hpp
- /library/ds/sparse_table/sparse_table_on_segtree.hpp.html
title: ds/sparse_table/sparse_table_on_segtree.hpp
---
