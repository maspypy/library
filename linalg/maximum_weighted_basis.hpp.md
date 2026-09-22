---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':warning:'
  attributes:
    links: []
  bundledCode: "#line 1 \"linalg/maximum_weighted_basis.hpp\"\n\ntemplate <typename\
    \ T, typename WT>\nstruct Maximum_Weighted_Basis {\n  int n;\n  vc<int> idx;\n\
    \  vvc<T> basis;  // basis[k][k] = 1, basis[k][0..k) = 0\n  vc<WT> wt;\n  WT wt_sum;\n\
    \  int dim, nxt_idx;\n\n  Maximum_Weighted_Basis(int n)\n      : n(n),\n     \
    \   idx(n, -1),\n        basis(n, vc<T>(n)),\n        wt(n, WT(0)),\n        wt_sum(0),\n\
    \        dim(0),\n        nxt_idx(0) {}\n\n  // \u6D88\u3048\u308B\u3082\u306E\
    \u306E\u756A\u53F7\n  int add(vc<T> x, WT w) {\n    assert(len(x) == n);\n   \
    \ int p = nxt_idx++;\n\n    FOR(k, n) {\n      if (x[k] == T(0)) continue;\n\n\
    \      if (idx[k] == -1) {\n        T c = T(1) / x[k];\n        FOR(j, k, n) x[j]\
    \ *= c;\n\n        idx[k] = p;\n        wt[k] = w;\n        basis[k] = x;\n  \
    \      wt_sum += w;\n        ++dim;\n        return -1;\n      }\n\n      if (wt[k]\
    \ < w) {\n        wt_sum = wt_sum - wt[k] + w;\n        swap(idx[k], p);\n   \
    \     swap(wt[k], w);\n        swap(basis[k], x);\n\n        T c = T(1) / basis[k][k];\n\
    \        FOR(j, k, n) basis[k][j] *= c;\n      }\n\n      T c = x[k];\n      FOR(j,\
    \ k, n) x[j] -= c * basis[k][j];\n    }\n\n    return p;\n  }\n};\n"
  code: "\ntemplate <typename T, typename WT>\nstruct Maximum_Weighted_Basis {\n \
    \ int n;\n  vc<int> idx;\n  vvc<T> basis;  // basis[k][k] = 1, basis[k][0..k)\
    \ = 0\n  vc<WT> wt;\n  WT wt_sum;\n  int dim, nxt_idx;\n\n  Maximum_Weighted_Basis(int\
    \ n)\n      : n(n),\n        idx(n, -1),\n        basis(n, vc<T>(n)),\n      \
    \  wt(n, WT(0)),\n        wt_sum(0),\n        dim(0),\n        nxt_idx(0) {}\n\
    \n  // \u6D88\u3048\u308B\u3082\u306E\u306E\u756A\u53F7\n  int add(vc<T> x, WT\
    \ w) {\n    assert(len(x) == n);\n    int p = nxt_idx++;\n\n    FOR(k, n) {\n\
    \      if (x[k] == T(0)) continue;\n\n      if (idx[k] == -1) {\n        T c =\
    \ T(1) / x[k];\n        FOR(j, k, n) x[j] *= c;\n\n        idx[k] = p;\n     \
    \   wt[k] = w;\n        basis[k] = x;\n        wt_sum += w;\n        ++dim;\n\
    \        return -1;\n      }\n\n      if (wt[k] < w) {\n        wt_sum = wt_sum\
    \ - wt[k] + w;\n        swap(idx[k], p);\n        swap(wt[k], w);\n        swap(basis[k],\
    \ x);\n\n        T c = T(1) / basis[k][k];\n        FOR(j, k, n) basis[k][j] *=\
    \ c;\n      }\n\n      T c = x[k];\n      FOR(j, k, n) x[j] -= c * basis[k][j];\n\
    \    }\n\n    return p;\n  }\n};"
  dependsOn: []
  isVerificationFile: false
  path: linalg/maximum_weighted_basis.hpp
  requiredBy: []
  timestamp: '2026-09-22 16:12:29+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: linalg/maximum_weighted_basis.hpp
layout: document
redirect_from:
- /library/linalg/maximum_weighted_basis.hpp
- /library/linalg/maximum_weighted_basis.hpp.html
title: linalg/maximum_weighted_basis.hpp
---
