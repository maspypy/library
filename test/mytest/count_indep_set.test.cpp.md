---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: true
  _pathExtension: cpp
  _verificationStatusIcon: ':x:'
  attributes: {}
  bundledCode: "Traceback (most recent call last):\n  File \"/opt/hostedtoolcache/Python/3.11.3/x64/lib/python3.11/site-packages/onlinejudge_verify/documentation/build.py\"\
    , line 71, in _render_source_code_stat\n    bundled_code = language.bundle(stat.path,\
    \ basedir=basedir, options={'include_paths': [basedir]}).decode()\n          \
    \         ^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^\n\
    \  File \"/opt/hostedtoolcache/Python/3.11.3/x64/lib/python3.11/site-packages/onlinejudge_verify/languages/cplusplus.py\"\
    , line 187, in bundle\n    bundler.update(path)\n  File \"/opt/hostedtoolcache/Python/3.11.3/x64/lib/python3.11/site-packages/onlinejudge_verify/languages/cplusplus_bundle.py\"\
    , line 401, in update\n    self.update(self._resolve(pathlib.Path(included), included_from=path))\n\
    \  File \"/opt/hostedtoolcache/Python/3.11.3/x64/lib/python3.11/site-packages/onlinejudge_verify/languages/cplusplus_bundle.py\"\
    , line 401, in update\n    self.update(self._resolve(pathlib.Path(included), included_from=path))\n\
    \  File \"/opt/hostedtoolcache/Python/3.11.3/x64/lib/python3.11/site-packages/onlinejudge_verify/languages/cplusplus_bundle.py\"\
    , line 401, in update\n    self.update(self._resolve(pathlib.Path(included), included_from=path))\n\
    \  [Previous line repeated 1 more time]\n  File \"/opt/hostedtoolcache/Python/3.11.3/x64/lib/python3.11/site-packages/onlinejudge_verify/languages/cplusplus_bundle.py\"\
    , line 260, in _resolve\n    raise BundleErrorAt(path, -1, \"no such header\"\
    )\nonlinejudge_verify.languages.cplusplus_bundle.BundleErrorAt: mod/barret.hpp:\
    \ line -1: no such header\n"
  code: "#define PROBLEM \"https://judge.yosupo.jp/problem/aplusb\"\n#include \"my_template.hpp\"\
    \n#include \"other/io.hpp\"\n#include \"random/random_graph.hpp\"\n#include \"\
    graph/base.hpp\"\n#include \"graph/count/count_independent_set.hpp\"\n\nvoid test()\
    \ {\n  FOR(100) {\n    FOR(n, 10) {\n      auto G = random_graph<0>(n, 1);\n \
    \     vv(int, adj, n, n);\n\n      for (auto&& e: G.edges) adj[e.frm][e.to] =\
    \ adj[e.to][e.frm] = 1;\n      auto X = count_independent_set<decltype(G)>(G);\n\
    \      auto Y = count_independent_set_by_size<decltype(G)>(G);\n      FOR(s, 1\
    \ << n) {\n        bool ok = 1;\n        FOR(i, n) FOR(j, n) {\n          if ((s\
    \ >> i & 1) && (s >> j & 1) && adj[i][j]) ok = 0;\n        }\n        if (!ok)\
    \ continue;\n        --X;\n        --Y[popcnt(s)];\n      }\n      assert(X ==\
    \ 0);\n      assert(len(Y) == n + 1);\n      FOR(i, n + 1) assert(Y[i] == 0);\n\
    \    }\n  }\n}\n\nvoid solve() {\n  LL(a, b);\n  print(a + b);\n}\n\nsigned main()\
    \ {\n  test();\n  solve();\n  return 0;\n}\n"
  dependsOn: []
  isVerificationFile: true
  path: test/mytest/count_indep_set.test.cpp
  requiredBy: []
  timestamp: '1970-01-01 00:00:00+00:00'
  verificationStatus: TEST_WRONG_ANSWER
  verifiedWith: []
documentation_of: test/mytest/count_indep_set.test.cpp
layout: document
redirect_from:
- /verify/test/mytest/count_indep_set.test.cpp
- /verify/test/mytest/count_indep_set.test.cpp.html
title: test/mytest/count_indep_set.test.cpp
---
