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
    )\nonlinejudge_verify.languages.cplusplus_bundle.BundleErrorAt: ds/unionfind.hpp:\
    \ line -1: no such header\n"
  code: "#pragma once\r\n\r\n#include \"graph/base.hpp\"\r\n#include \"ds/unionfind.hpp\"\
    \r\n\r\n// \u4E8C\u90E8\u30B0\u30E9\u30D5\u5224\u5B9A + \u5FA9\u5143\r\n// \u4E8C\
    \u90E8\u30B0\u30E9\u30D5\u3067\u306A\u304B\u3063\u305F\u5834\u5408\u306B\u306F\
    \ empty\r\ntemplate <typename Graph>\r\nvc<int> check_bipartite(Graph& G) {\r\n\
    \  assert(G.is_prepared());\r\n\r\n  int n = G.N;\r\n  UnionFind uf(2 * n);\r\n\
    \  for (auto&& e: G.edges) {\r\n    int u = e.frm, v = e.to;\r\n    if (e.cost\
    \ == 0) uf.merge(u, v), uf.merge(u + n, v + n);\r\n    if (e.cost != 0) uf.merge(u\
    \ + n, v), uf.merge(u, v + n);\r\n  }\r\n\r\n  vc<int> color(2 * n, -1);\r\n \
    \ FOR(v, n) if (uf[v] == v && color[uf[v]] < 0) {\r\n    color[uf[v]] = 0;\r\n\
    \    color[uf[v + n]] = 1;\r\n  }\r\n  FOR(v, n) color[v] = color[uf[v]];\r\n\
    \  color.resize(n);\r\n  FOR(v, n) if (uf[v] == uf[v + n]) return {};\r\n  return\
    \ color;\r\n}\r\n"
  dependsOn: []
  isVerificationFile: false
  path: graph/check_bipartite.hpp
  requiredBy: []
  timestamp: '1970-01-01 00:00:00+00:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: graph/check_bipartite.hpp
layout: document
redirect_from:
- /library/graph/check_bipartite.hpp
- /library/graph/check_bipartite.hpp.html
title: graph/check_bipartite.hpp
---
