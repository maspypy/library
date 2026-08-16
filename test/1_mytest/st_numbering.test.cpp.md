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
    \  File \"/opt/hostedtoolcache/Python/3.12.13/x64/lib/python3.12/site-packages/onlinejudge_verify/languages/cplusplus_bundle.py\"\
    , line 401, in update\n    self.update(self._resolve(pathlib.Path(included), included_from=path))\n\
    \                ^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^\n \
    \ File \"/opt/hostedtoolcache/Python/3.12.13/x64/lib/python3.12/site-packages/onlinejudge_verify/languages/cplusplus_bundle.py\"\
    , line 260, in _resolve\n    raise BundleErrorAt(path, -1, \"no such header\"\
    )\nonlinejudge_verify.languages.cplusplus_bundle.BundleErrorAt: graph/shortest_path/bfs01.hpp:\
    \ line -1: no such header\n"
  code: "#define PROBLEM \"https://judge.yosupo.jp/problem/aplusb\"\n#include \"my_template.hpp\"\
    \n\n#include \"graph/st_numbering.hpp\"\n#include \"random/random_graph.hpp\"\n\
    \nvoid test() {\n  // valid \u306A output \u306B\u306A\u3063\u3066\u3044\u308B\
    \u3053\u3068\u306F\u6700\u5F8C\u306B\u30C1\u30A7\u30C3\u30AF\u3057\u3066\u3044\
    \u308B\u306E\u3067\n  // invalid \u3068\u8A00\u308F\u308C\u305F\u3068\u304D\u306B\
    \u69CB\u7BC9\u4E0D\u53EF\u80FD\u3067\u3042\u308B\u3053\u3068\u3092\u78BA\u304B\
    \u3081\u308C\u3070\u3088\u3044\n  FOR(N, 2, 20) {\n    FOR(100) {\n      Graph<int,\
    \ 0> G(N);\n      for (auto& [a, b]: random_graph<0>(N, false)) { G.add(a, b);\
    \ };\n      G.build();\n\n      auto BCT = block_cut(G);\n      UnionFind uf(N);\n\
    \      for (auto& e: G.edges) uf.merge(e.frm, e.to);\n      FOR(s, N) FOR(t, N)\
    \ {\n        auto ST = st_numbering(G, s, t);\n        assert((!ST.empty()) ==\
    \ check_st_numbering(G, s, t));\n      }\n    }\n  }\n}\n\nvoid solve() {\n  int\
    \ a, b;\n  cin >> a >> b;\n  cout << a + b << \"\\n\";\n}\n\nsigned main() {\n\
    \  test();\n  solve();\n  return 0;\n}"
  dependsOn: []
  isVerificationFile: true
  path: test/1_mytest/st_numbering.test.cpp
  requiredBy: []
  timestamp: '1970-01-01 00:00:00+00:00'
  verificationStatus: TEST_WRONG_ANSWER
  verifiedWith: []
documentation_of: test/1_mytest/st_numbering.test.cpp
layout: document
redirect_from:
- /verify/test/1_mytest/st_numbering.test.cpp
- /verify/test/1_mytest/st_numbering.test.cpp.html
title: test/1_mytest/st_numbering.test.cpp
---
