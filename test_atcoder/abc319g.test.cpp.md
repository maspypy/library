---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: true
  _pathExtension: cpp
  _verificationStatusIcon: ':x:'
  attributes: {}
  bundledCode: "Traceback (most recent call last):\n  File \"/opt/hostedtoolcache/Python/3.12.0/x64/lib/python3.12/site-packages/onlinejudge_verify/documentation/build.py\"\
    , line 71, in _render_source_code_stat\n    bundled_code = language.bundle(stat.path,\
    \ basedir=basedir, options={'include_paths': [basedir]}).decode()\n          \
    \         ^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^\n\
    \  File \"/opt/hostedtoolcache/Python/3.12.0/x64/lib/python3.12/site-packages/onlinejudge_verify/languages/cplusplus.py\"\
    , line 187, in bundle\n    bundler.update(path)\n  File \"/opt/hostedtoolcache/Python/3.12.0/x64/lib/python3.12/site-packages/onlinejudge_verify/languages/cplusplus_bundle.py\"\
    , line 401, in update\n    self.update(self._resolve(pathlib.Path(included), included_from=path))\n\
    \                ^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^\n \
    \ File \"/opt/hostedtoolcache/Python/3.12.0/x64/lib/python3.12/site-packages/onlinejudge_verify/languages/cplusplus_bundle.py\"\
    , line 260, in _resolve\n    raise BundleErrorAt(path, -1, \"no such header\"\
    )\nonlinejudge_verify.languages.cplusplus_bundle.BundleErrorAt: graph/implicit_graph/cograph_bfs.hpp:\
    \ line -1: no such header\n"
  code: "#define PROBLEM \"https://atcoder.jp/contests/abc319/tasks/abc319_g\"\n#include\
    \ \"my_template.hpp\"\n#include \"other/io.hpp\"\n\n#include \"graph/implicit_graph/cograph_bfs.hpp\"\
    \n#include \"mod/modint.hpp\"\nusing mint = modint998;\n\nvoid solve() {\n  LL(N,\
    \ M);\n  Graph<int, 0> G(N);\n  G.read_graph(M);\n\n  auto dist = cograph_bfs(G,\
    \ 0).fi;\n\n  ll d = dist[N - 1];\n  if (d == infty<int>) return print(-1);\n\n\
    \  vvc<int> V(d + 1);\n  FOR(v, N) {\n    if (dist[v] <= d) V[dist[v]].eb(v);\n\
    \  }\n\n  vc<mint> dp(N);\n  dp[0] = 1;\n  vc<int> pre(N);\n  FOR(i, 1, d + 1)\
    \ {\n    mint base = 0;\n    for (auto&& v: V[i - 1]) pre[v] = 1, base += dp[v];\n\
    \    for (auto&& v: V[i]) {\n      dp[v] += base;\n      for (auto& e: G[v]) {\n\
    \        if (pre[e.to]) dp[v] -= dp[e.to];\n      }\n    }\n    for (auto&& v:\
    \ V[i - 1]) pre[v] = 0;\n  }\n  // print(dp);\n  print(dp[N - 1]);\n}\n\nsigned\
    \ main() {\n  solve();\n  return 0;\n}\n"
  dependsOn: []
  isVerificationFile: true
  path: test_atcoder/abc319g.test.cpp
  requiredBy: []
  timestamp: '1970-01-01 00:00:00+00:00'
  verificationStatus: TEST_WRONG_ANSWER
  verifiedWith: []
documentation_of: test_atcoder/abc319g.test.cpp
layout: document
redirect_from:
- /verify/test_atcoder/abc319g.test.cpp
- /verify/test_atcoder/abc319g.test.cpp.html
title: test_atcoder/abc319g.test.cpp
---
