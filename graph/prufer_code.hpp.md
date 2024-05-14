---
data:
  _extendedDependsOn: []
  _extendedRequiredBy:
  - icon: ':warning:'
    path: enumerate/labeled_tree.hpp
    title: enumerate/labeled_tree.hpp
  _extendedVerifiedWith:
  - icon: ':x:'
    path: test/mytest/prufer.test.cpp
    title: test/mytest/prufer.test.cpp
  _isVerificationFailed: true
  _pathExtension: hpp
  _verificationStatusIcon: ':x:'
  attributes:
    links: []
  bundledCode: "#line 1 \"graph/prufer_code.hpp\"\n\n// [0,n-1]^{n-1}, \u305F\u3060\
    \u3057\u672B\u5C3E\u306F n-1, \u3068\u3044\u3046\u5B9A\u5F0F\u5316 (n=1 ok)\n\
    vc<int> to_prufer_code(Graph<int, 0>& G) {\n  // \u30E9\u30D9\u30EB\u6700\u5C0F\
    \u306E\u8449\u3092\u3068\u308B -> \u89AA\u3092\u5217\u306B\u8FFD\u52A0\n  int\
    \ n = G.N;\n  vc<int> par(n);\n  {\n    auto dfs = [&](auto& dfs, int v, int p)\
    \ -> void {\n      par[v] = p;\n      for (auto& e: G[v])\n        if (e.to !=\
    \ p) dfs(dfs, e.to, v);\n    };\n    dfs(dfs, n - 1, -1);\n  }\n  vc<int> deg\
    \ = G.deg_array();\n  vc<int> res(n - 1);\n  int p = 0;\n  int leaf = -1;\n  FOR(i,\
    \ n - 1) {\n    if (leaf == -1) {\n      while (deg[p] != 1) ++p;\n      leaf\
    \ = p;\n    }\n    res[i] = par[leaf];\n    deg[leaf]--, deg[par[leaf]]--;\n \
    \   leaf = (deg[par[leaf]] == 1 && par[leaf] < p ? par[leaf] : -1);\n  }\n  return\
    \ res;\n}\n\nGraph<int, 0> from_prufer_code(vc<int> code) {\n  int n = len(code)\
    \ + 1;\n  Graph<int, 0> G(n);\n  if (n == 1) return G;\n  assert(code.back() ==\
    \ n - 1);\n  vc<int> deg(n, 1);\n  for (auto& v: code) deg[v]++;\n\n  int p =\
    \ 0;\n  int leaf = -1;\n  FOR(i, n - 1) {\n    if (leaf == -1) {\n      while\
    \ (deg[p] != 1) p++;\n      leaf = p;\n    }\n    G.add(code[i], leaf);\n    deg[leaf]--,\
    \ deg[code[i]]--;\n    leaf = (code[i] < p && deg[code[i]] == 1 ? code[i] : -1);\n\
    \  }\n  G.build();\n  return G;\n}\n"
  code: "\n// [0,n-1]^{n-1}, \u305F\u3060\u3057\u672B\u5C3E\u306F n-1, \u3068\u3044\
    \u3046\u5B9A\u5F0F\u5316 (n=1 ok)\nvc<int> to_prufer_code(Graph<int, 0>& G) {\n\
    \  // \u30E9\u30D9\u30EB\u6700\u5C0F\u306E\u8449\u3092\u3068\u308B -> \u89AA\u3092\
    \u5217\u306B\u8FFD\u52A0\n  int n = G.N;\n  vc<int> par(n);\n  {\n    auto dfs\
    \ = [&](auto& dfs, int v, int p) -> void {\n      par[v] = p;\n      for (auto&\
    \ e: G[v])\n        if (e.to != p) dfs(dfs, e.to, v);\n    };\n    dfs(dfs, n\
    \ - 1, -1);\n  }\n  vc<int> deg = G.deg_array();\n  vc<int> res(n - 1);\n  int\
    \ p = 0;\n  int leaf = -1;\n  FOR(i, n - 1) {\n    if (leaf == -1) {\n      while\
    \ (deg[p] != 1) ++p;\n      leaf = p;\n    }\n    res[i] = par[leaf];\n    deg[leaf]--,\
    \ deg[par[leaf]]--;\n    leaf = (deg[par[leaf]] == 1 && par[leaf] < p ? par[leaf]\
    \ : -1);\n  }\n  return res;\n}\n\nGraph<int, 0> from_prufer_code(vc<int> code)\
    \ {\n  int n = len(code) + 1;\n  Graph<int, 0> G(n);\n  if (n == 1) return G;\n\
    \  assert(code.back() == n - 1);\n  vc<int> deg(n, 1);\n  for (auto& v: code)\
    \ deg[v]++;\n\n  int p = 0;\n  int leaf = -1;\n  FOR(i, n - 1) {\n    if (leaf\
    \ == -1) {\n      while (deg[p] != 1) p++;\n      leaf = p;\n    }\n    G.add(code[i],\
    \ leaf);\n    deg[leaf]--, deg[code[i]]--;\n    leaf = (code[i] < p && deg[code[i]]\
    \ == 1 ? code[i] : -1);\n  }\n  G.build();\n  return G;\n}\n"
  dependsOn: []
  isVerificationFile: false
  path: graph/prufer_code.hpp
  requiredBy:
  - enumerate/labeled_tree.hpp
  timestamp: '2024-05-14 16:33:21+09:00'
  verificationStatus: LIBRARY_ALL_WA
  verifiedWith:
  - test/mytest/prufer.test.cpp
documentation_of: graph/prufer_code.hpp
layout: document
redirect_from:
- /library/graph/prufer_code.hpp
- /library/graph/prufer_code.hpp.html
title: graph/prufer_code.hpp
---
