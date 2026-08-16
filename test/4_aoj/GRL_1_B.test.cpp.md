---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: true
  _pathExtension: cpp
  _verificationStatusIcon: ':x:'
  attributes: {}
  bundledCode: "Traceback (most recent call last):\n  File \"/opt/hostedtoolcache/Python/3.12.13/x64/lib/python3.12/site-packages/onlinejudge_verify/documentation/build.py\"\
    , line 71, in _render_source_code_stat\n    bundled_code = language.bundle(stat.path,\
    \ basedir=basedir, options={'include_paths': [basedir]}).decode()\n          \
    \         ^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^\n\
    \  File \"/opt/hostedtoolcache/Python/3.12.13/x64/lib/python3.12/site-packages/onlinejudge_verify/languages/cplusplus.py\"\
    , line 187, in bundle\n    bundler.update(path)\n  File \"/opt/hostedtoolcache/Python/3.12.13/x64/lib/python3.12/site-packages/onlinejudge_verify/languages/cplusplus_bundle.py\"\
    , line 401, in update\n    self.update(self._resolve(pathlib.Path(included), included_from=path))\n\
    \                ^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^\n \
    \ File \"/opt/hostedtoolcache/Python/3.12.13/x64/lib/python3.12/site-packages/onlinejudge_verify/languages/cplusplus_bundle.py\"\
    , line 260, in _resolve\n    raise BundleErrorAt(path, -1, \"no such header\"\
    )\nonlinejudge_verify.languages.cplusplus_bundle.BundleErrorAt: graph/shortest_path/bellmanford.hpp:\
    \ line -1: no such header\n"
  code: "#define PROBLEM \"https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=GRL_1_B\"\
    \n#include \"my_template.hpp\"\n#include \"other/io.hpp\"\n#include \"graph/shortest_path/bellmanford.hpp\"\
    \n\nvoid solve() {\n  LL(N, M, s);\n  Graph<int, 1> G(N);\n  G.read_graph(M, 1,\
    \ 0);\n\n  auto [dist, par] = BellmanFord<int, true>(G, s);\n  if (dist.empty())\
    \ { return print(\"NEGATIVE CYCLE\"); }\n  for (auto&& x: dist) {\n    if (x ==\
    \ infty<int>)\n      print(\"INF\");\n    else\n      print(x);\n  }\n}\n\nsigned\
    \ main() {\n  solve();\n\n  return 0;\n}\n"
  dependsOn: []
  isVerificationFile: true
  path: test/4_aoj/GRL_1_B.test.cpp
  requiredBy: []
  timestamp: '1970-01-01 00:00:00+00:00'
  verificationStatus: TEST_WRONG_ANSWER
  verifiedWith: []
documentation_of: test/4_aoj/GRL_1_B.test.cpp
layout: document
redirect_from:
- /verify/test/4_aoj/GRL_1_B.test.cpp
- /verify/test/4_aoj/GRL_1_B.test.cpp.html
title: test/4_aoj/GRL_1_B.test.cpp
---
