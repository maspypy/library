---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: true
  _pathExtension: cpp
  _verificationStatusIcon: ':x:'
  attributes: {}
  bundledCode: "Traceback (most recent call last):\n  File \"/opt/hostedtoolcache/Python/3.11.1/x64/lib/python3.11/site-packages/onlinejudge_verify/documentation/build.py\"\
    , line 71, in _render_source_code_stat\n    bundled_code = language.bundle(stat.path,\
    \ basedir=basedir, options={'include_paths': [basedir]}).decode()\n          \
    \         ^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^\n\
    \  File \"/opt/hostedtoolcache/Python/3.11.1/x64/lib/python3.11/site-packages/onlinejudge_verify/languages/cplusplus.py\"\
    , line 187, in bundle\n    bundler.update(path)\n  File \"/opt/hostedtoolcache/Python/3.11.1/x64/lib/python3.11/site-packages/onlinejudge_verify/languages/cplusplus_bundle.py\"\
    , line 401, in update\n    self.update(self._resolve(pathlib.Path(included), included_from=path))\n\
    \  File \"/opt/hostedtoolcache/Python/3.11.1/x64/lib/python3.11/site-packages/onlinejudge_verify/languages/cplusplus_bundle.py\"\
    , line 401, in update\n    self.update(self._resolve(pathlib.Path(included), included_from=path))\n\
    \                ^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^\n \
    \ File \"/opt/hostedtoolcache/Python/3.11.1/x64/lib/python3.11/site-packages/onlinejudge_verify/languages/cplusplus_bundle.py\"\
    , line 260, in _resolve\n    raise BundleErrorAt(path, -1, \"no such header\"\
    )\nonlinejudge_verify.languages.cplusplus_bundle.BundleErrorAt: graph/check_bipartite.hpp:\
    \ line -1: no such header\n"
  code: "#define PROBLEM \"https://atcoder.jp/contests/abc274/tasks/abc274_g\"\n#include\
    \ \"my_template.hpp\"\n#include \"other/io.hpp\"\n#include \"flow/bipartite.hpp\"\
    \n\nvoid solve() {\n  LL(H, W);\n  VEC(string, S, H);\n  Graph<bool, 0> G(2 *\
    \ H * W);\n\n  FOR(x, H) FOR(y, W) {\n    if (S[x][y] == '#') continue;\n    ll\
    \ px = x;\n    ll py = y;\n    while (px > 0 && S[px - 1][y] == '.') --px;\n \
    \   while (py > 0 && S[x][py - 1] == '.') --py;\n    // (px,y), (x, py)\n    ll\
    \ a = W * px + y;\n    ll b = W * x + py;\n    G.add(a, b + H * W);\n  }\n  G.build();\n\
    \n  BipartiteMatching<decltype(G)> X(G);\n  auto cov = X.vertex_cover();\n  print(len(cov));\n\
    }\n\nsigned main() {\n  cout << fixed << setprecision(15);\n\n  ll T = 1;\n  //\
    \ LL(T);\n  FOR(T) solve();\n\n  return 0;\n}"
  dependsOn: []
  isVerificationFile: true
  path: test_atcoder/abc274g.test.cpp
  requiredBy: []
  timestamp: '1970-01-01 00:00:00+00:00'
  verificationStatus: TEST_WRONG_ANSWER
  verifiedWith: []
documentation_of: test_atcoder/abc274g.test.cpp
layout: document
redirect_from:
- /verify/test_atcoder/abc274g.test.cpp
- /verify/test_atcoder/abc274g.test.cpp.html
title: test_atcoder/abc274g.test.cpp
---
