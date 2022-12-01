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
  code: "#include \"graph/base.hpp\"\r\n#include \"ds/unionfind.hpp\"\r\n\r\n/*\r\n\
    \u30DE\u30FC\u30B8\u904E\u7A0B\u3092\u8868\u3059\u6728\u3092\u69CB\u7BC9\u3059\
    \u308B\r\nq \u56DE\u76EE\u306B\u30DE\u30FC\u30B8\u3057\u3066\u3067\u304D\u308B\
    \u6210\u5206\uFF1AN+q\r\nadd_root = true \u306E\u5834\u5408\uFF1A\u6700\u5F8C\u306B\
    \u5168\u90E8\u3092\u30DE\u30FC\u30B8\u3057\u3066\u3001\u6839 N+Q \u3092\u8FFD\u52A0\
    \u3059\u308B\r\n*/\r\nGraph<int> tree_of_unionfind(int N, vc<pair<int, int>> query,\
    \ bool add_root) {\r\n  UnionFind uf(N + len(query));\r\n  vc<int> root(N);\r\n\
    \  iota(all(root), 0);\r\n  int Q = len(query);\r\n  Graph<int> G(N + Q + add_root);\r\
    \n  FOR(q, Q) {\r\n    int v = N + q;\r\n    auto [a, b] = query[q];\r\n    a\
    \ = uf[a], b = uf[b];\r\n    G.add(v, root[a]);\r\n    if (b != a) G.add(v, root[b]);\r\
    \n    uf.merge(a, b);\r\n    uf.merge(b, v);\r\n    root[uf[v]] = v;\r\n  }\r\n\
    \  if (add_root) {\r\n    int r = N + Q;\r\n    FOR(v, N) if (uf[v] == v) G.add(r,\
    \ root[v]);\r\n  }\r\n  G.build();\r\n  return G;\r\n}\r\n"
  dependsOn: []
  isVerificationFile: false
  path: graph/tree_of_unionfind.hpp
  requiredBy: []
  timestamp: '1970-01-01 00:00:00+00:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: graph/tree_of_unionfind.hpp
layout: document
redirect_from:
- /library/graph/tree_of_unionfind.hpp
- /library/graph/tree_of_unionfind.hpp.html
title: graph/tree_of_unionfind.hpp
---
