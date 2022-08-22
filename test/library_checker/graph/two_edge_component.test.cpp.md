---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: true
  _pathExtension: cpp
  _verificationStatusIcon: ':x:'
  attributes: {}
  bundledCode: "Traceback (most recent call last):\n  File \"/opt/hostedtoolcache/Python/3.10.6/x64/lib/python3.10/site-packages/onlinejudge_verify/documentation/build.py\"\
    , line 71, in _render_source_code_stat\n    bundled_code = language.bundle(stat.path,\
    \ basedir=basedir, options={'include_paths': [basedir]}).decode()\n  File \"/opt/hostedtoolcache/Python/3.10.6/x64/lib/python3.10/site-packages/onlinejudge_verify/languages/cplusplus.py\"\
    , line 187, in bundle\n    bundler.update(path)\n  File \"/opt/hostedtoolcache/Python/3.10.6/x64/lib/python3.10/site-packages/onlinejudge_verify/languages/cplusplus_bundle.py\"\
    , line 401, in update\n    self.update(self._resolve(pathlib.Path(included), included_from=path))\n\
    \  File \"/opt/hostedtoolcache/Python/3.10.6/x64/lib/python3.10/site-packages/onlinejudge_verify/languages/cplusplus_bundle.py\"\
    , line 401, in update\n    self.update(self._resolve(pathlib.Path(included), included_from=path))\n\
    \  File \"/opt/hostedtoolcache/Python/3.10.6/x64/lib/python3.10/site-packages/onlinejudge_verify/languages/cplusplus_bundle.py\"\
    , line 260, in _resolve\n    raise BundleErrorAt(path, -1, \"no such header\"\
    )\nonlinejudge_verify.languages.cplusplus_bundle.BundleErrorAt: graph/hld.hpp:\
    \ line -1: no such header\n"
  code: "#define PROBLEM \"https://judge.yosupo.jp/problem/two_edge_connected_components\"\
    \r\n#include \"my_template.hpp\"\r\n#include \"other/io.hpp\"\r\n#include \"graph/two_edge_component.hpp\"\
    \r\n\r\nvoid solve() {\r\n  LL(N, M);\r\n  Graph G(N);\r\n  G.read_graph(M, false,\
    \ 0);\r\n\r\n  auto [C, comp] = two_edge_component(G);\r\n  vc<vc<int>> ANS(C);\r\
    \n  FOR(v, N) ANS[comp[v]].eb(v);\r\n  print(len(ANS));\r\n  for (auto&& ans:\
    \ ANS) print(len(ans), ans);\r\n}\r\n\r\nsigned main() {\r\n  solve();\r\n\r\n\
    \  return 0;\r\n}\r\n"
  dependsOn: []
  isVerificationFile: true
  path: test/library_checker/graph/two_edge_component.test.cpp
  requiredBy: []
  timestamp: '1970-01-01 00:00:00+00:00'
  verificationStatus: TEST_WRONG_ANSWER
  verifiedWith: []
documentation_of: test/library_checker/graph/two_edge_component.test.cpp
layout: document
redirect_from:
- /verify/test/library_checker/graph/two_edge_component.test.cpp
- /verify/test/library_checker/graph/two_edge_component.test.cpp.html
title: test/library_checker/graph/two_edge_component.test.cpp
---
