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
  code: "#include \"ds/unionfind.hpp\"\r\n#include \"graph/base.hpp\"\r\n#include\
    \ \"graph/hld.hpp\"\r\n\r\ntemplate <typename T = int>\r\nstruct FunctionalGraph\
    \ {\r\n  int N, M;\r\n  Graph<T, 1> tree; // \u65B0\u3057\u3044\u9802\u70B9 N\
    \ \u3092\u6839\u3068\u3057\u3066\u8FFD\u52A0\u3057\u305F\u6709\u5411\u6728\u3002\
    \u9006\u5411\u304D\u306E\u8FBA\u306B\u306A\u308B\u3002\r\n  // HLD<Graph<T, 1>>\
    \ hld;\r\n  vc<int> TO;\r\n  vc<T> wt;\r\n  vc<int> root;\r\n  vvc<int> cyc;\r\
    \n\r\n  FunctionalGraph() {}\r\n  FunctionalGraph(int N) : N(N), M(0), TO(N, -1),\
    \ wt(N), root(N, -1) {}\r\n\r\n  void add(int a, int b, T c = 1) {\r\n    assert(0\
    \ <= a && a < N);\r\n    assert(TO[a] == -1);\r\n    ++M;\r\n    TO[a] = b;\r\n\
    \    wt[a] = c;\r\n  }\r\n\r\n  void build() {\r\n    assert(N == M);\r\n    UnionFind\
    \ uf(N);\r\n    FOR(v, N) if (!uf.merge(v, TO[v])) { root[v] = v; }\r\n    FOR(v,\
    \ N) if (root[v] == v) root[uf[v]] = v;\r\n    FOR(v, N) root[v] = root[uf[v]];\r\
    \n\r\n    tree = Graph<T, 1>(N + 1);\r\n    FOR(v, N) {\r\n      if (root[v] !=\
    \ v)\r\n        tree.add(TO[v], v);\r\n      else\r\n        tree.add(N, v);\r\
    \n    }\r\n    tree.build();\r\n    cyc.resize(N);\r\n    FOR(v, N) if (root[v]\
    \ == v) {\r\n      vc<int> C = {TO[root[v]]};\r\n      while (C.back() != v) C.eb(TO[C.back()]);\r\
    \n      cyc[v] = C;\r\n    }\r\n  }\r\n\r\n  void debug() {\r\n    print(\"TO\"\
    , TO);\r\n    print(\"root\");\r\n    print(root);\r\n    print(\"\u6839\u3092\
    \u8FFD\u52A0\u3057\u305F\u6728 tree\");\r\n    tree.debug();\r\n  }\r\n};\r\n"
  dependsOn: []
  isVerificationFile: false
  path: graph/functional.hpp
  requiredBy: []
  timestamp: '1970-01-01 00:00:00+00:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: graph/functional.hpp
layout: document
redirect_from:
- /library/graph/functional.hpp
- /library/graph/functional.hpp.html
title: graph/functional.hpp
---
