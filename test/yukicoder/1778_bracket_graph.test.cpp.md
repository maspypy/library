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
    , line 260, in _resolve\n    raise BundleErrorAt(path, -1, \"no such header\"\
    )\nonlinejudge_verify.languages.cplusplus_bundle.BundleErrorAt: graph/hld.hpp:\
    \ line -1: no such header\n"
  code: "#define PROBLEM \"https://yukicoder.me/problems/no/1778\"\n#include \"my_template.hpp\"\
    \n#include \"other/io.hpp\"\n#include \"graph/bracket_graph.hpp\"\n#include \"\
    graph/hld.hpp\"\n\nvoid solve() {\n  LL(N, Q);\n  STR(S);\n  auto [G, LR] = bracket_graph(S);\n\
    \  vi idx(N);\n  FOR(i, 1, len(LR)) {\n    auto [L, R] = LR[i];\n    idx[L] =\
    \ idx[R - 1] = i;\n  }\n\n  HLD hld(G);\n\n  FOR(Q) {\n    LL(a, b);\n    --a,\
    \ --b;\n    int i = idx[a], j = idx[b];\n    int k = hld.lca(i, j);\n    if (k\
    \ == 0)\n      print(-1);\n    else {\n      auto [l, r] = LR[k];\n      print(l\
    \ + 1, r);\n    }\n  }\n}\n\nsigned main() {\n  cin.tie(nullptr);\n  ios::sync_with_stdio(false);\n\
    \  cout << fixed << setprecision(15);\n\n  ll T = 1;\n  // LL(T);\n  FOR(T) solve();\n\
    \n  return 0;\n}\n"
  dependsOn: []
  isVerificationFile: true
  path: test/yukicoder/1778_bracket_graph.test.cpp
  requiredBy: []
  timestamp: '1970-01-01 00:00:00+00:00'
  verificationStatus: TEST_WRONG_ANSWER
  verifiedWith: []
documentation_of: test/yukicoder/1778_bracket_graph.test.cpp
layout: document
redirect_from:
- /verify/test/yukicoder/1778_bracket_graph.test.cpp
- /verify/test/yukicoder/1778_bracket_graph.test.cpp.html
title: test/yukicoder/1778_bracket_graph.test.cpp
---
