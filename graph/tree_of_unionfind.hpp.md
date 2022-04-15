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
  bundledCode: "#line 1 \"graph/tree_of_unionfind.hpp\"\n/*\r\n\u30DE\u30FC\u30B8\u904E\
    \u7A0B\u3092\u8868\u3059\u6728\u3092\u69CB\u7BC9\u3059\u308B\r\nq \u56DE\u76EE\
    \u306B\u30DE\u30FC\u30B8\u3057\u3066\u3067\u304D\u308B\u6210\u5206\uFF1AN+q\r\n\
    \u6700\u5F8C\u306B\u5168\u90E8\u3092\u30DE\u30FC\u30B8\u3057\u3066\u3001\u6839\
    \ N+Q \u3092\u8FFD\u52A0\u3059\u308B\r\n\u5168\u90E8\u3067 N+Q+1 \u9802\u70B9\u3001\
    \u6839\u304C N+Q \u306E\u6839\u4ED8\u304D\u6728\r\n*/\r\nGraph<int> tree_of_unionfind(int\
    \ N, vc<pair<int, int>> query) {\r\n  UnionFind uf(N);\r\n  vc<int> root(N);\r\
    \n  iota(all(root), 0);\r\n  int Q = len(query);\r\n  Graph<int> G(N + Q + 1);\r\
    \n  FOR(q, Q) {\r\n    int v = N + q;\r\n    auto [a, b] = query[q];\r\n    assert(0\
    \ <= a && a < N);\r\n    assert(0 <= b && b < N);\r\n    a = uf[a], b = uf[b];\r\
    \n    G.add(v, root[a]);\r\n    if (b != a) G.add(v, root[b]);\r\n    uf.merge(a,\
    \ b);\r\n    root[uf[a]] = v;\r\n  }\r\n  int r = N + Q;\r\n  FOR(v, N) if (uf[v]\
    \ == v) G.add(r, root[v]);\r\n  G.build();\r\n  return G;\r\n}\n"
  code: "/*\r\n\u30DE\u30FC\u30B8\u904E\u7A0B\u3092\u8868\u3059\u6728\u3092\u69CB\u7BC9\
    \u3059\u308B\r\nq \u56DE\u76EE\u306B\u30DE\u30FC\u30B8\u3057\u3066\u3067\u304D\
    \u308B\u6210\u5206\uFF1AN+q\r\n\u6700\u5F8C\u306B\u5168\u90E8\u3092\u30DE\u30FC\
    \u30B8\u3057\u3066\u3001\u6839 N+Q \u3092\u8FFD\u52A0\u3059\u308B\r\n\u5168\u90E8\
    \u3067 N+Q+1 \u9802\u70B9\u3001\u6839\u304C N+Q \u306E\u6839\u4ED8\u304D\u6728\
    \r\n*/\r\nGraph<int> tree_of_unionfind(int N, vc<pair<int, int>> query) {\r\n\
    \  UnionFind uf(N);\r\n  vc<int> root(N);\r\n  iota(all(root), 0);\r\n  int Q\
    \ = len(query);\r\n  Graph<int> G(N + Q + 1);\r\n  FOR(q, Q) {\r\n    int v =\
    \ N + q;\r\n    auto [a, b] = query[q];\r\n    assert(0 <= a && a < N);\r\n  \
    \  assert(0 <= b && b < N);\r\n    a = uf[a], b = uf[b];\r\n    G.add(v, root[a]);\r\
    \n    if (b != a) G.add(v, root[b]);\r\n    uf.merge(a, b);\r\n    root[uf[a]]\
    \ = v;\r\n  }\r\n  int r = N + Q;\r\n  FOR(v, N) if (uf[v] == v) G.add(r, root[v]);\r\
    \n  G.build();\r\n  return G;\r\n}"
  dependsOn: []
  isVerificationFile: false
  path: graph/tree_of_unionfind.hpp
  requiredBy: []
  timestamp: '2022-04-16 04:26:49+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: graph/tree_of_unionfind.hpp
layout: document
redirect_from:
- /library/graph/tree_of_unionfind.hpp
- /library/graph/tree_of_unionfind.hpp.html
title: graph/tree_of_unionfind.hpp
---
