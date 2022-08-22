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
  code: "#define PROBLEM \\\n  \"https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=GRL_3_B\"\
    \n\n#include \"my_template.hpp\"\n#include \"other/io.hpp\"\n#include \"graph/two_edge_component.hpp\"\
    \n\nvoid solve() {\n  LL(N, M);\n  Graph<int, 0> G(N);\n  G.read_graph(M, 0, 0);\n\
    \  auto [C, comp] = two_edge_component(G);\n  vc<pi> ANS;\n  for (auto&& e: G.edges)\
    \ {\n    auto a = e.frm, b = e.to;\n    if (a > b) swap(a, b);\n    if (comp[a]\
    \ != comp[b]) ANS.eb(a, b);\n  }\n  sort(all(ANS));\n  for (auto&& x: ANS) print(x);\n\
    }\n\nsigned main() {\n  cout << fixed << setprecision(15);\n\n  ll T = 1;\n  //\
    \ LL(T);\n  FOR(T) solve();\n\n  return 0;\n}\n"
  dependsOn: []
  isVerificationFile: true
  path: test/aoj/GRL_3_B.test.cpp
  requiredBy: []
  timestamp: '1970-01-01 00:00:00+00:00'
  verificationStatus: TEST_WRONG_ANSWER
  verifiedWith: []
documentation_of: test/aoj/GRL_3_B.test.cpp
layout: document
redirect_from:
- /verify/test/aoj/GRL_3_B.test.cpp
- /verify/test/aoj/GRL_3_B.test.cpp.html
title: test/aoj/GRL_3_B.test.cpp
---
