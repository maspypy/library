---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: true
  _pathExtension: cpp
  _verificationStatusIcon: ':x:'
  attributes: {}
  bundledCode: "Traceback (most recent call last):\n  File \"/opt/hostedtoolcache/Python/3.11.0/x64/lib/python3.11/site-packages/onlinejudge_verify/documentation/build.py\"\
    , line 71, in _render_source_code_stat\n    bundled_code = language.bundle(stat.path,\
    \ basedir=basedir, options={'include_paths': [basedir]}).decode()\n          \
    \         ^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^\n\
    \  File \"/opt/hostedtoolcache/Python/3.11.0/x64/lib/python3.11/site-packages/onlinejudge_verify/languages/cplusplus.py\"\
    , line 187, in bundle\n    bundler.update(path)\n  File \"/opt/hostedtoolcache/Python/3.11.0/x64/lib/python3.11/site-packages/onlinejudge_verify/languages/cplusplus_bundle.py\"\
    , line 401, in update\n    self.update(self._resolve(pathlib.Path(included), included_from=path))\n\
    \  File \"/opt/hostedtoolcache/Python/3.11.0/x64/lib/python3.11/site-packages/onlinejudge_verify/languages/cplusplus_bundle.py\"\
    , line 401, in update\n    self.update(self._resolve(pathlib.Path(included), included_from=path))\n\
    \  File \"/opt/hostedtoolcache/Python/3.11.0/x64/lib/python3.11/site-packages/onlinejudge_verify/languages/cplusplus_bundle.py\"\
    , line 401, in update\n    self.update(self._resolve(pathlib.Path(included), included_from=path))\n\
    \                ^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^\n \
    \ File \"/opt/hostedtoolcache/Python/3.11.0/x64/lib/python3.11/site-packages/onlinejudge_verify/languages/cplusplus_bundle.py\"\
    , line 260, in _resolve\n    raise BundleErrorAt(path, -1, \"no such header\"\
    )\nonlinejudge_verify.languages.cplusplus_bundle.BundleErrorAt: ds/disjoint_sparse/disjointsparse.hpp:\
    \ line -1: no such header\n"
  code: "#define PROBLEM \"https://atcoder.jp/contests/arc151/tasks/arc151_e\"\n#include\
    \ \"my_template.hpp\"\n#include \"other/io.hpp\"\n#include \"string/longest_common_substring.hpp\"\
    \n#include \"graph/shortest_path/dijkstra.hpp\"\n\nvoid solve() {\n  INT(N);\n\
    \  VEC(int, A, N);\n  INT(P);\n  VEC(int, B, P);\n  INT(Q);\n  VEC(int, C, Q);\n\
    \n  int lcp = [&]() -> int {\n    auto [l1, r1, l2, r2] = longest_common_substring(B,\
    \ C);\n    return r1 - l1;\n  }();\n\n  if (lcp >= 1) { return print(P + Q - 2\
    \ * lcp); }\n\n  // \u3042\u3068\u306F\u30011 \u6587\u5B57\u3092\u7D4C\u7531\u3057\
    \u3066\u3046\u308D\u3046\u308D\u3059\u308B\u5834\u5408\n  for (auto&& x: A) --x;\n\
    \  for (auto&& x: B) --x;\n  for (auto&& x: C) --x;\n  int S = N;\n  int T = N\
    \ + 1;\n  Graph<int, 0> G(N + 2);\n  for (auto&& x: B) { G.add(S, x, P - 1); }\n\
    \  for (auto&& x: C) { G.add(x, T, Q - 1); }\n  FOR(i, N - 1) {\n    G.add(A[i],\
    \ A[i + 1], 2);\n    G.add(A[i + 1], A[i], 2);\n  }\n  G.build();\n\n  auto [dist,\
    \ par] = dijkstra(G, S, 1 << 30);\n  print(dist[T]);\n}\n\nsigned main() {\n \
    \ cin.tie(nullptr);\n  ios::sync_with_stdio(false);\n  cout << setprecision(15);\n\
    \n  solve();\n\n  return 0;\n}\n"
  dependsOn: []
  isVerificationFile: true
  path: test/atcoder/arc151_e.test.cpp
  requiredBy: []
  timestamp: '1970-01-01 00:00:00+00:00'
  verificationStatus: TEST_WRONG_ANSWER
  verifiedWith: []
documentation_of: test/atcoder/arc151_e.test.cpp
layout: document
redirect_from:
- /verify/test/atcoder/arc151_e.test.cpp
- /verify/test/atcoder/arc151_e.test.cpp.html
title: test/atcoder/arc151_e.test.cpp
---
