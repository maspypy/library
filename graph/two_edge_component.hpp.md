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
  bundledCode: "Traceback (most recent call last):\n  File \"/opt/hostedtoolcache/Python/3.10.6/x64/lib/python3.10/site-packages/onlinejudge_verify/documentation/build.py\"\
    , line 71, in _render_source_code_stat\n    bundled_code = language.bundle(stat.path,\
    \ basedir=basedir, options={'include_paths': [basedir]}).decode()\n  File \"/opt/hostedtoolcache/Python/3.10.6/x64/lib/python3.10/site-packages/onlinejudge_verify/languages/cplusplus.py\"\
    , line 187, in bundle\n    bundler.update(path)\n  File \"/opt/hostedtoolcache/Python/3.10.6/x64/lib/python3.10/site-packages/onlinejudge_verify/languages/cplusplus_bundle.py\"\
    , line 401, in update\n    self.update(self._resolve(pathlib.Path(included), included_from=path))\n\
    \  File \"/opt/hostedtoolcache/Python/3.10.6/x64/lib/python3.10/site-packages/onlinejudge_verify/languages/cplusplus_bundle.py\"\
    , line 260, in _resolve\n    raise BundleErrorAt(path, -1, \"no such header\"\
    )\nonlinejudge_verify.languages.cplusplus_bundle.BundleErrorAt: graph/hld.hpp:\
    \ line -1: no such header\n"
  code: "#include \"graph/hld.hpp\"\r\n\r\n// (\u6210\u5206\u6570, \u6210\u5206\u756A\
    \u53F7\u306E vector)\r\ntemplate <typename Graph>\r\npair<int, vc<int>> two_edge_component(Graph&\
    \ G) {\r\n  HLD hld(G);\r\n  int N = G.N;\r\n  vc<int> DP(N);\r\n  for (auto&&\
    \ e: G.edges) {\r\n    if (!hld.in_tree[e.id]) {\r\n      int a = e.frm, b = e.to;\r\
    \n      if (hld.depth[a] < hld.depth[b]) swap(a, b);\r\n      DP[a]++, DP[b]--;\r\
    \n    }\r\n  }\r\n  auto& V = hld.V;\r\n  FOR_R(i, len(V)) {\r\n    int v = V[i];\r\
    \n    int p = hld.parent[v];\r\n    if (p != -1) DP[p] += DP[v];\r\n  }\r\n  int\
    \ C = 0;\r\n  vc<int> comp(N, -1);\r\n  FOR(v, N) if (DP[v] == 0) comp[v] = C++;\r\
    \n  for (auto&& v: V)\r\n    if (comp[v] == -1) comp[v] = comp[hld.parent[v]];\r\
    \n  return {C, comp};\r\n}\r\n"
  dependsOn: []
  isVerificationFile: false
  path: graph/two_edge_component.hpp
  requiredBy: []
  timestamp: '1970-01-01 00:00:00+00:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: graph/two_edge_component.hpp
layout: document
redirect_from:
- /library/graph/two_edge_component.hpp
- /library/graph/two_edge_component.hpp.html
title: graph/two_edge_component.hpp
---
