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
    links:
    - https://yukicoder.me/problems/no/1891
  bundledCode: "#line 1 \"ds/xor_sparsetable.hpp\"\n// \u30E2\u30CE\u30A4\u30C9\u306E\
    \u5217\u3092\u4E0E\u3048\u308B\u3002\u6B21\u304C\u5BFE\u6570\u6642\u9593\u3067\
    \u8A08\u7B97\u3067\u304D\u308B\u3002\n// \u30FBprod_{l<=i<r} A[i xor x]\n// https://yukicoder.me/problems/no/1891\n\
    template <typename Monoid>\nstruct Xor_SparseTable {\n  using X = typename Monoid::value_type;\n\
    \  int LOG;\n  vc<vc<X>> dat;\n  Xor_SparseTable(vc<X>& A) {\n    LOG = 0;\n \
    \   while ((1 << LOG) < len(A)) ++LOG;\n    assert(len(A) == (1 << LOG));\n  \
    \  // \u5404 k, i \u306B\u5BFE\u3057\u3066\u3001prod_{0<=j<2^k} A[i^j] \u3092\u6301\
    \u3064\n    dat.resize(LOG + 1);\n    dat[0] = A;\n    FOR(k, LOG) {\n      dat[k\
    \ + 1].assign(1 << LOG, Monoid::unit());\n      FOR(i, 1 << LOG) {\n        dat[k\
    \ + 1][i] = Monoid::op(dat[k][i], dat[k][i ^ (1 << k)]);\n      }\n    }\n  }\n\
    \n  // prod_{l<=i<r} A[x xor i]\n  X prod(int l, int r, int xor_val) {\n    X\
    \ xl = Monoid::unit();\n    X xr = Monoid::unit();\n    FOR(k, LOG + 1) {\n  \
    \    if (l >= r) break;\n      if (l & 1 << k) {\n        xl = Monoid::op(xl,\
    \ dat[k][l ^ xor_val]);\n        l += (1 << k);\n      }\n      if (r & 1 << k)\
    \ {\n        r -= (1 << k);\n        xr = Monoid::op(dat[k][r ^ xor_val], xr);\n\
    \      }\n    }\n\n    return Monoid::op(xl, xr);\n  }\n};\n"
  code: "// \u30E2\u30CE\u30A4\u30C9\u306E\u5217\u3092\u4E0E\u3048\u308B\u3002\u6B21\
    \u304C\u5BFE\u6570\u6642\u9593\u3067\u8A08\u7B97\u3067\u304D\u308B\u3002\n// \u30FB\
    prod_{l<=i<r} A[i xor x]\n// https://yukicoder.me/problems/no/1891\ntemplate <typename\
    \ Monoid>\nstruct Xor_SparseTable {\n  using X = typename Monoid::value_type;\n\
    \  int LOG;\n  vc<vc<X>> dat;\n  Xor_SparseTable(vc<X>& A) {\n    LOG = 0;\n \
    \   while ((1 << LOG) < len(A)) ++LOG;\n    assert(len(A) == (1 << LOG));\n  \
    \  // \u5404 k, i \u306B\u5BFE\u3057\u3066\u3001prod_{0<=j<2^k} A[i^j] \u3092\u6301\
    \u3064\n    dat.resize(LOG + 1);\n    dat[0] = A;\n    FOR(k, LOG) {\n      dat[k\
    \ + 1].assign(1 << LOG, Monoid::unit());\n      FOR(i, 1 << LOG) {\n        dat[k\
    \ + 1][i] = Monoid::op(dat[k][i], dat[k][i ^ (1 << k)]);\n      }\n    }\n  }\n\
    \n  // prod_{l<=i<r} A[x xor i]\n  X prod(int l, int r, int xor_val) {\n    X\
    \ xl = Monoid::unit();\n    X xr = Monoid::unit();\n    FOR(k, LOG + 1) {\n  \
    \    if (l >= r) break;\n      if (l & 1 << k) {\n        xl = Monoid::op(xl,\
    \ dat[k][l ^ xor_val]);\n        l += (1 << k);\n      }\n      if (r & 1 << k)\
    \ {\n        r -= (1 << k);\n        xr = Monoid::op(dat[k][r ^ xor_val], xr);\n\
    \      }\n    }\n\n    return Monoid::op(xl, xr);\n  }\n};"
  dependsOn: []
  isVerificationFile: false
  path: ds/xor_sparsetable.hpp
  requiredBy: []
  timestamp: '2022-04-24 16:42:51+09:00'
  verificationStatus: LIBRARY_ALL_WA
  verifiedWith:
  - test/yukicoder/1891.test.cpp
documentation_of: ds/xor_sparsetable.hpp
layout: document
redirect_from:
- /library/ds/xor_sparsetable.hpp
- /library/ds/xor_sparsetable.hpp.html
title: ds/xor_sparsetable.hpp
---
