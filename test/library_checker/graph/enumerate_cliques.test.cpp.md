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
    \                ^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^\n \
    \ File \"/opt/hostedtoolcache/Python/3.11.1/x64/lib/python3.11/site-packages/onlinejudge_verify/languages/cplusplus_bundle.py\"\
    , line 260, in _resolve\n    raise BundleErrorAt(path, -1, \"no such header\"\
    )\nonlinejudge_verify.languages.cplusplus_bundle.BundleErrorAt: enumerate/cliques.hpp:\
    \ line -1: no such header\n"
  code: "#define PROBLEM \"https://judge.yosupo.jp/problem/enumerate_cliques\"\n#include\
    \ \"my_template.hpp\"\n#include \"other/io.hpp\"\n\n#include \"graph/base.hpp\"\
    \n#include \"mod/modint.hpp\"\n#include \"enumerate/cliques.hpp\"\n\nusing mint\
    \ = modint998;\n\nvoid solve() {\n  LL(N, M);\n  VEC(mint, X, N);\n  mint ANS\
    \ = 0;\n  Graph<int, 0> G(N);\n  G.read_graph(M, 0, 0);\n\n  auto f = [&](vc<int>\
    \ C) -> void {\n    mint p = 1;\n    for (auto&& i: C) p *= X[i];\n    ANS +=\
    \ p;\n  };\n  enumerate_cliques(G, f);\n  print(ANS);\n}\n\nsigned main() {\n\
    \  cout << fixed << setprecision(15);\n\n  ll T = 1;\n  // LL(T);\n  FOR(T) solve();\n\
    \n  return 0;\n}\n"
  dependsOn: []
  isVerificationFile: true
  path: test/library_checker/graph/enumerate_cliques.test.cpp
  requiredBy: []
  timestamp: '1970-01-01 00:00:00+00:00'
  verificationStatus: TEST_WRONG_ANSWER
  verifiedWith: []
documentation_of: test/library_checker/graph/enumerate_cliques.test.cpp
layout: document
redirect_from:
- /verify/test/library_checker/graph/enumerate_cliques.test.cpp
- /verify/test/library_checker/graph/enumerate_cliques.test.cpp.html
title: test/library_checker/graph/enumerate_cliques.test.cpp
---
