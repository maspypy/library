---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: true
  _pathExtension: cpp
  _verificationStatusIcon: ':x:'
  attributes: {}
  bundledCode: "Traceback (most recent call last):\n  File \"/opt/hostedtoolcache/Python/3.10.8/x64/lib/python3.10/site-packages/onlinejudge_verify/documentation/build.py\"\
    , line 71, in _render_source_code_stat\n    bundled_code = language.bundle(stat.path,\
    \ basedir=basedir, options={'include_paths': [basedir]}).decode()\n  File \"/opt/hostedtoolcache/Python/3.10.8/x64/lib/python3.10/site-packages/onlinejudge_verify/languages/cplusplus.py\"\
    , line 187, in bundle\n    bundler.update(path)\n  File \"/opt/hostedtoolcache/Python/3.10.8/x64/lib/python3.10/site-packages/onlinejudge_verify/languages/cplusplus_bundle.py\"\
    , line 401, in update\n    self.update(self._resolve(pathlib.Path(included), included_from=path))\n\
    \  File \"/opt/hostedtoolcache/Python/3.10.8/x64/lib/python3.10/site-packages/onlinejudge_verify/languages/cplusplus_bundle.py\"\
    , line 260, in _resolve\n    raise BundleErrorAt(path, -1, \"no such header\"\
    )\nonlinejudge_verify.languages.cplusplus_bundle.BundleErrorAt: graph/dijkstra.hpp:\
    \ line -1: no such header\n"
  code: "#define PROBLEM \"https://judge.yosupo.jp/problem/shortest_path\"\r\n\r\n\
    #include \"my_template.hpp\"\r\n#include \"other/io.hpp\"\r\n\r\n#include \"graph/dijkstra.hpp\"\
    \r\n#include \"graph/restore_path.hpp\"\r\n\r\nvoid solve() {\r\n  LL(N, M, s,\
    \ t);\r\n  Graph<ll, true> G(N);\r\n  G.read_graph(M, 1, 0);\r\n\r\n  const ll\
    \ INF = 1LL << 60;\r\n\r\n  auto [dist, par] = dijkstra<ll>(G, s, INF);\r\n  if\
    \ (dist[t] == INF) return print(-1);\r\n\r\n  vector<int> pth = restore_path(par,\
    \ t);\r\n  print(dist[t], len(pth) - 1);\r\n  FOR(i, len(pth) - 1) print(pth[i],\
    \ pth[i + 1]);\r\n}\r\n\r\nsigned main() {\r\n  cin.tie(nullptr);\r\n  ios::sync_with_stdio(false);\r\
    \n  cout << setprecision(15);\r\n\r\n  solve();\r\n\r\n  return 0;\r\n}\r\n"
  dependsOn: []
  isVerificationFile: true
  path: test/library_checker/graph/shortest_path.test.cpp
  requiredBy: []
  timestamp: '1970-01-01 00:00:00+00:00'
  verificationStatus: TEST_WRONG_ANSWER
  verifiedWith: []
documentation_of: test/library_checker/graph/shortest_path.test.cpp
layout: document
redirect_from:
- /verify/test/library_checker/graph/shortest_path.test.cpp
- /verify/test/library_checker/graph/shortest_path.test.cpp.html
title: test/library_checker/graph/shortest_path.test.cpp
---
