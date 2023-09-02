---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: true
  _pathExtension: cpp
  _verificationStatusIcon: ':x:'
  attributes: {}
  bundledCode: "Traceback (most recent call last):\n  File \"/opt/hostedtoolcache/Python/3.11.4/x64/lib/python3.11/site-packages/onlinejudge_verify/documentation/build.py\"\
    , line 71, in _render_source_code_stat\n    bundled_code = language.bundle(stat.path,\
    \ basedir=basedir, options={'include_paths': [basedir]}).decode()\n          \
    \         ^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^\n\
    \  File \"/opt/hostedtoolcache/Python/3.11.4/x64/lib/python3.11/site-packages/onlinejudge_verify/languages/cplusplus.py\"\
    , line 187, in bundle\n    bundler.update(path)\n  File \"/opt/hostedtoolcache/Python/3.11.4/x64/lib/python3.11/site-packages/onlinejudge_verify/languages/cplusplus_bundle.py\"\
    , line 401, in update\n    self.update(self._resolve(pathlib.Path(included), included_from=path))\n\
    \                ^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^\n \
    \ File \"/opt/hostedtoolcache/Python/3.11.4/x64/lib/python3.11/site-packages/onlinejudge_verify/languages/cplusplus_bundle.py\"\
    , line 260, in _resolve\n    raise BundleErrorAt(path, -1, \"no such header\"\
    )\nonlinejudge_verify.languages.cplusplus_bundle.BundleErrorAt: graph/max_matching_size.hpp:\
    \ line -1: no such header\n"
  code: "#define PROBLEM \"https://judge.yosupo.jp/problem/aplusb\"\n#include \"my_template.hpp\"\
    \n#include \"other/io.hpp\"\n#include \"random/random_graph.hpp\"\n#include \"\
    graph/max_matching_size.hpp\"\n#include \"graph/maximum_matching_of_line_graph.hpp\"\
    \n\nvoid test() {\n  FOR(100) {\n    FOR(n, 10) {\n      auto G = random_graph<false>(n,\
    \ 1);\n      int m = G.M;\n      Graph<int, 0> LG(m);\n      FOR(i, m) FOR(j,\
    \ i) if (i != j) {\n        auto ei = G.edges[i];\n        auto ej = G.edges[j];\n\
    \        bool ok = 0;\n        if (ei.frm == ej.frm) ok = 1;\n        if (ei.frm\
    \ == ej.to) ok = 1;\n        if (ei.to == ej.frm) ok = 1;\n        if (ei.to ==\
    \ ej.to) ok = 1;\n        if (ok) LG.add(i, j);\n      }\n      LG.build();\n\
    \      vc<pair<int, int>> res = maximum_matching_of_line_graph(G);\n      assert(len(res)\
    \ == max_matching_size(LG));\n      vc<int> done(m);\n      for (auto&& [a, b]:\
    \ res) {\n        assert(!done[a]);\n        assert(!done[b]);\n        done[a]\
    \ = done[b] = 1;\n        auto ei = G.edges[a];\n        auto ej = G.edges[b];\n\
    \        bool ok = 0;\n        if (ei.frm == ej.frm) ok = 1;\n        if (ei.frm\
    \ == ej.to) ok = 1;\n        if (ei.to == ej.frm) ok = 1;\n        if (ei.to ==\
    \ ej.to) ok = 1;\n        assert(ok);\n      }\n    }\n  }\n}\n\nvoid solve()\
    \ {\n  LL(a, b);\n  print(a + b);\n}\n\nsigned main() {\n  test();\n  solve();\n\
    \  return 0;\n}"
  dependsOn: []
  isVerificationFile: true
  path: test/mytest/matching_line_graph.test.cpp
  requiredBy: []
  timestamp: '1970-01-01 00:00:00+00:00'
  verificationStatus: TEST_WRONG_ANSWER
  verifiedWith: []
documentation_of: test/mytest/matching_line_graph.test.cpp
layout: document
redirect_from:
- /verify/test/mytest/matching_line_graph.test.cpp
- /verify/test/mytest/matching_line_graph.test.cpp.html
title: test/mytest/matching_line_graph.test.cpp
---
