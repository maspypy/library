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
  bundledCode: "Traceback (most recent call last):\n  File \"/opt/hostedtoolcache/Python/3.10.8/x64/lib/python3.10/site-packages/onlinejudge_verify/documentation/build.py\"\
    , line 71, in _render_source_code_stat\n    bundled_code = language.bundle(stat.path,\
    \ basedir=basedir, options={'include_paths': [basedir]}).decode()\n  File \"/opt/hostedtoolcache/Python/3.10.8/x64/lib/python3.10/site-packages/onlinejudge_verify/languages/cplusplus.py\"\
    , line 187, in bundle\n    bundler.update(path)\n  File \"/opt/hostedtoolcache/Python/3.10.8/x64/lib/python3.10/site-packages/onlinejudge_verify/languages/cplusplus_bundle.py\"\
    , line 401, in update\n    self.update(self._resolve(pathlib.Path(included), included_from=path))\n\
    \  File \"/opt/hostedtoolcache/Python/3.10.8/x64/lib/python3.10/site-packages/onlinejudge_verify/languages/cplusplus_bundle.py\"\
    , line 260, in _resolve\n    raise BundleErrorAt(path, -1, \"no such header\"\
    )\nonlinejudge_verify.languages.cplusplus_bundle.BundleErrorAt: graph/dijkstra.hpp:\
    \ line -1: no such header\n"
  code: "#include \"graph/dijkstra.hpp\"\r\n#include \"graph/bfs01.hpp\"\r\n\r\ntemplate\
    \ <typename T, typename Graph>\r\nT MinCostCycle(Graph& G, T INF) {\r\n  int M\
    \ = G.M;\r\n  int N = G.N;\r\n  T mx = 0;\r\n  T res = INF;\r\n\r\n  FOR(i, M)\
    \ {\r\n    auto& e = G.edges[i];\r\n    T cost = e.cost;\r\n    int frm = e.to,\
    \ to = e.frm;\r\n    Graph Gi(N);\r\n    FOR(j, M) if (i != j) {\r\n      auto&\
    \ e = G.edges[j];\r\n      Gi.add(e.frm, e.to, e.cost);\r\n    }\r\n    Gi.build();\r\
    \n\r\n    T x = (mx <= 1 ? bfs01<decltype(Gi), T>(Gi, frm).fi[to] : dijkstra<T>(Gi,\
    \ frm, INF).fi[to]);\r\n    if (x == -1) x = INF;\r\n    chmin(res, cost + x);\r\
    \n  }\r\n  if (res == INF) res = -1;\r\n  return res;\r\n}\r\n"
  dependsOn: []
  isVerificationFile: false
  path: graph/mincostcycle.hpp
  requiredBy: []
  timestamp: '1970-01-01 00:00:00+00:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: graph/mincostcycle.hpp
layout: document
redirect_from:
- /library/graph/mincostcycle.hpp
- /library/graph/mincostcycle.hpp.html
title: graph/mincostcycle.hpp
---
