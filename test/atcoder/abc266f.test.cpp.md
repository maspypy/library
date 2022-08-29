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
    )\nonlinejudge_verify.languages.cplusplus_bundle.BundleErrorAt: graph/degree.hpp:\
    \ line -1: no such header\n"
  code: "#define PROBLEM \"https://atcoder.jp/contests/abc266/tasks/abc266_f\"\n#include\
    \ \"my_template.hpp\"\n#include \"other/io.hpp\"\n#include \"graph/unicyclic.hpp\"\
    \n#include \"graph/tree.hpp\"\n\nvoid solve() {\n  LL(N);\n  Graph<int, 0> G(N);\n\
    \  G.read_graph(N);\n\n  UnicyclicGraph X(G);\n  auto T = X.tree;\n  TREE<decltype(T)>\
    \ tree(T, X.root);\n\n  ll root = X.root;\n  ll bottom = X.TO[X.root];\n\n  LL(Q);\n\
    \  FOR(Q) {\n    LL(a, b);\n    --a, --b;\n    ll ca = tree.lca(a, bottom);\n\
    \    ll cb = tree.lca(b, bottom);\n    Yes(ca == cb);\n  }\n}\n\nsigned main()\
    \ {\n  cout << fixed << setprecision(15);\n\n  ll T = 1;\n  // LL(T);\n  FOR(T)\
    \ solve();\n\n  return 0;\n}\n"
  dependsOn: []
  isVerificationFile: true
  path: test/atcoder/abc266f.test.cpp
  requiredBy: []
  timestamp: '1970-01-01 00:00:00+00:00'
  verificationStatus: TEST_WRONG_ANSWER
  verifiedWith: []
documentation_of: test/atcoder/abc266f.test.cpp
layout: document
redirect_from:
- /verify/test/atcoder/abc266f.test.cpp
- /verify/test/atcoder/abc266f.test.cpp.html
title: test/atcoder/abc266f.test.cpp
---
