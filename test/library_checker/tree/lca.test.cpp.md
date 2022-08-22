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
  code: "#define PROBLEM \"https://judge.yosupo.jp/problem/lca\"\n#include \"my_template.hpp\"\
    \n#include \"other/io.hpp\"\n\n#include \"graph/hld.hpp\"\n\nvoid solve() {\n\
    \  LL(N, Q);\n  Graph<int, 0> G(N);\n  FOR3(v, 1, N) {\n    LL(p);\n    G.add(p,\
    \ v);\n  }\n  G.build();\n  HLD hld(G);\n\n  FOR(_, Q) {\n    LL(a, b);\n    print(hld.LCA(a,\
    \ b));\n  }\n}\n\nsigned main() {\n  cin.tie(nullptr);\n  ios::sync_with_stdio(false);\n\
    \  cout << setprecision(15);\n\n  solve();\n  return 0;\n}\n"
  dependsOn: []
  isVerificationFile: true
  path: test/library_checker/tree/lca.test.cpp
  requiredBy: []
  timestamp: '1970-01-01 00:00:00+00:00'
  verificationStatus: TEST_WRONG_ANSWER
  verifiedWith: []
documentation_of: test/library_checker/tree/lca.test.cpp
layout: document
redirect_from:
- /verify/test/library_checker/tree/lca.test.cpp
- /verify/test/library_checker/tree/lca.test.cpp.html
title: test/library_checker/tree/lca.test.cpp
---
