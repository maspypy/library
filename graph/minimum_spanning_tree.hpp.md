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
    - https://codeforces.com/contest/828/problem/F
  bundledCode: "Traceback (most recent call last):\n  File \"/opt/hostedtoolcache/Python/3.11.0/x64/lib/python3.11/site-packages/onlinejudge_verify/documentation/build.py\"\
    , line 71, in _render_source_code_stat\n    bundled_code = language.bundle(stat.path,\
    \ basedir=basedir, options={'include_paths': [basedir]}).decode()\n          \
    \         ^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^\n\
    \  File \"/opt/hostedtoolcache/Python/3.11.0/x64/lib/python3.11/site-packages/onlinejudge_verify/languages/cplusplus.py\"\
    , line 187, in bundle\n    bundler.update(path)\n  File \"/opt/hostedtoolcache/Python/3.11.0/x64/lib/python3.11/site-packages/onlinejudge_verify/languages/cplusplus_bundle.py\"\
    , line 401, in update\n    self.update(self._resolve(pathlib.Path(included), included_from=path))\n\
    \                ^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^\n \
    \ File \"/opt/hostedtoolcache/Python/3.11.0/x64/lib/python3.11/site-packages/onlinejudge_verify/languages/cplusplus_bundle.py\"\
    , line 260, in _resolve\n    raise BundleErrorAt(path, -1, \"no such header\"\
    )\nonlinejudge_verify.languages.cplusplus_bundle.BundleErrorAt: ds/unionfind/unionfind.hpp:\
    \ line -1: no such header\n"
  code: "#include \"ds/unionfind/unionfind.hpp\"\r\n#include \"graph/base.hpp\"\r\n\
    #include \"graph/tree.hpp\"\r\n#include \"graph/ds/treemonoid.hpp\"\r\n#include\
    \ \"graph/ds/dualtreemonoid.hpp\"\r\n#include \"alg/monoid/min.hpp\"\r\n#include\
    \ \"alg/monoid/max.hpp\"\r\n\r\n// return : {T mst_cost, vc<bool> in_mst, Graph\
    \ MST}\r\ntemplate <typename T>\r\ntuple<T, vc<bool>, Graph<T>> minimum_spanning_tree(Graph<T>&\
    \ G) {\r\n  int N = G.N;\r\n  int M = len(G.edges);\r\n  vc<pair<T, int>> edges;\r\
    \n  FOR(i, M) {\r\n    auto& e = G.edges[i];\r\n    edges.eb(e.cost, i);\r\n \
    \ }\r\n  sort(all(edges));\r\n  vc<bool> in_mst(M);\r\n  UnionFind uf(N);\r\n\
    \  T mst_cost = T(0);\r\n  Graph<T> MST(N);\r\n  for (auto&& [cost, i]: edges)\
    \ {\r\n    auto& e = G.edges[i];\r\n    if (uf.merge(e.frm, e.to)) {\r\n     \
    \ in_mst[i] = 1;\r\n      mst_cost += e.cost;\r\n    }\r\n  }\r\n  FOR(i, M) if\
    \ (in_mst[i]) {\r\n    auto& e = G.edges[i];\r\n    MST.add(e.frm, e.to, e.cost);\r\
    \n  }\r\n  MST.build();\r\n  return {mst_cost, in_mst, MST};\r\n}\r\n\r\n// https://codeforces.com/contest/828/problem/F\r\
    \n// return : {T mst_cost, vc<bool> in_mst, Graph MST, vc<T> dat}\r\n// dat :\
    \ \u8FBA\u3054\u3068\u306B\u3001\u4ED6\u306E\u8FBA\u3092\u4FDD\u3063\u305F\u3068\
    \u304D\u306B MST \u8FBA\u306B\u306A\u308B\u6700\u5927\u91CD\u307F\r\ntemplate\
    \ <typename T>\r\ntuple<T, vc<bool>, Graph<T>, vc<T>> minimum_spanning_tree_cycle_data(\r\
    \n    Graph<T>& G) {\r\n  int N = G.N;\r\n  int M = len(G.edges);\r\n  auto [mst_cost,\
    \ in_mst, MST] = minimum_spanning_tree(G);\r\n  TREE tree(MST);\r\n  vc<T> dat;\r\
    \n  FOR(i, M) if (in_mst[i]) dat.eb(G.edges[i].cost);\r\n  TreeMonoid<decltype(tree),\
    \ Monoid_Max<T>, 1> TM1(tree, dat);\r\n  DualTreeMonoid<decltype(tree), Monoid_Min<T>,\
    \ 1> TM2(tree);\r\n  FOR(i, M) {\r\n    if (!in_mst[i]) {\r\n      auto& e = G.edges[i];\r\
    \n      TM2.apply_path(e.frm, e.to, e.cost);\r\n    }\r\n  }\r\n  vc<T> ANS(M);\r\
    \n  int m = 0;\r\n  FOR(i, M) {\r\n    auto& e = G.edges[i];\r\n    if (in_mst[i])\r\
    \n      ANS[i] = TM2.get(m++);\r\n    else\r\n      ANS[i] = TM1.prod_path(e.frm,\
    \ e.to);\r\n  }\r\n  return {mst_cost, in_mst, MST, ANS};\r\n}"
  dependsOn: []
  isVerificationFile: false
  path: graph/minimum_spanning_tree.hpp
  requiredBy: []
  timestamp: '1970-01-01 00:00:00+00:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: graph/minimum_spanning_tree.hpp
layout: document
redirect_from:
- /library/graph/minimum_spanning_tree.hpp
- /library/graph/minimum_spanning_tree.hpp.html
title: graph/minimum_spanning_tree.hpp
---
