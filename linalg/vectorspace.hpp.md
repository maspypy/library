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
  bundledCode: "#line 1 \"linalg/vectorspace.hpp\"\n// K^n \u306E subspace \u3092\u7BA1\
    \u7406\u3059\u308B\u3002\r\n// add\uFF1A\u751F\u6210\u7CFB\u306B\u30D9\u30AF\u30C8\
    \u30EB\u3092\u8FFD\u52A0\r\n// dim, get_basis, contain\r\ntemplate <typename K>\r\
    \nstruct VectorSpace {\r\n  vc<vc<K>> basis;\r\n  vc<int> pivot;\r\n  int n;\r\
    \n\r\n  VectorSpace(int n) : n(n) {}\r\n\r\n  int dim() { return len(basis); }\r\
    \n\r\n  vc<vc<K>> get_basis() { return basis; }\r\n\r\n  void add(const vc<K>&\
    \ v) {\r\n    vc<K> w = reduce(v);\r\n    int p = n;\r\n    FOR(i, n) if (w[i]\
    \ != K(0)) chmin(p, i);\r\n    if (p == n) return;\r\n    K c = K(1) / w[p];\r\
    \n    FOR3(j, p, n) w[j] *= c;\r\n\r\n    FOR(i, len(basis)) {\r\n      K c =\
    \ basis[i][p];\r\n      if (c == K(0)) continue;\r\n      FOR3(j, p, n) basis[i][j]\
    \ -= c * w[j];\r\n    }\r\n\r\n    basis.eb(w);\r\n    pivot.eb(p);\r\n    int\
    \ k = len(basis) - 1;\r\n    while (k > 0 && pivot[k - 1] > p) {\r\n      swap(basis[k],\
    \ basis[k - 1]);\r\n      swap(pivot[k], pivot[k - 1]);\r\n      --k;\r\n    }\r\
    \n  }\r\n\r\n  bool contain(const vc<K>& v) {\r\n    vc<K> w = reduce(v);\r\n\
    \    FOR(i, n) if (w[i] != K(0)) return false;\r\n    return true;\r\n  }\r\n\r\
    \nprivate:\r\n  vc<K> reduce(vc<K> v) {\r\n    FOR(i, len(basis)) {\r\n      int\
    \ p = pivot[i];\r\n      K c = v[p];\r\n      FOR3(j, p, n) v[j] -= basis[i][j]\
    \ * c;\r\n    }\r\n    return v;\r\n  }\r\n};\r\n"
  code: "// K^n \u306E subspace \u3092\u7BA1\u7406\u3059\u308B\u3002\r\n// add\uFF1A\
    \u751F\u6210\u7CFB\u306B\u30D9\u30AF\u30C8\u30EB\u3092\u8FFD\u52A0\r\n// dim,\
    \ get_basis, contain\r\ntemplate <typename K>\r\nstruct VectorSpace {\r\n  vc<vc<K>>\
    \ basis;\r\n  vc<int> pivot;\r\n  int n;\r\n\r\n  VectorSpace(int n) : n(n) {}\r\
    \n\r\n  int dim() { return len(basis); }\r\n\r\n  vc<vc<K>> get_basis() { return\
    \ basis; }\r\n\r\n  void add(const vc<K>& v) {\r\n    vc<K> w = reduce(v);\r\n\
    \    int p = n;\r\n    FOR(i, n) if (w[i] != K(0)) chmin(p, i);\r\n    if (p ==\
    \ n) return;\r\n    K c = K(1) / w[p];\r\n    FOR3(j, p, n) w[j] *= c;\r\n\r\n\
    \    FOR(i, len(basis)) {\r\n      K c = basis[i][p];\r\n      if (c == K(0))\
    \ continue;\r\n      FOR3(j, p, n) basis[i][j] -= c * w[j];\r\n    }\r\n\r\n \
    \   basis.eb(w);\r\n    pivot.eb(p);\r\n    int k = len(basis) - 1;\r\n    while\
    \ (k > 0 && pivot[k - 1] > p) {\r\n      swap(basis[k], basis[k - 1]);\r\n   \
    \   swap(pivot[k], pivot[k - 1]);\r\n      --k;\r\n    }\r\n  }\r\n\r\n  bool\
    \ contain(const vc<K>& v) {\r\n    vc<K> w = reduce(v);\r\n    FOR(i, n) if (w[i]\
    \ != K(0)) return false;\r\n    return true;\r\n  }\r\n\r\nprivate:\r\n  vc<K>\
    \ reduce(vc<K> v) {\r\n    FOR(i, len(basis)) {\r\n      int p = pivot[i];\r\n\
    \      K c = v[p];\r\n      FOR3(j, p, n) v[j] -= basis[i][j] * c;\r\n    }\r\n\
    \    return v;\r\n  }\r\n};\r\n"
  dependsOn: []
  isVerificationFile: false
  path: linalg/vectorspace.hpp
  requiredBy: []
  timestamp: '2022-04-16 04:26:49+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: linalg/vectorspace.hpp
layout: document
redirect_from:
- /library/linalg/vectorspace.hpp
- /library/linalg/vectorspace.hpp.html
title: linalg/vectorspace.hpp
---
