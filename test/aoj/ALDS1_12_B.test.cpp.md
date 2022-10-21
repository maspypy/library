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
    )\nonlinejudge_verify.languages.cplusplus_bundle.BundleErrorAt: graph/dial.hpp:\
    \ line -1: no such header\n"
  code: "#define PROBLEM \\\n  \"https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=ALDS1_12_B\"\
    \n#include \"my_template.hpp\"\n#include \"other/io.hpp\"\n#include \"graph/dial.hpp\"\
    \n\nvoid solve() {\n  LL(N);\n  Graph<int, 1> G(N);\n  FOR(v, N) {\n    LL(u);\n\
    \    assert(u == v);\n    LL(k);\n    FOR(k) {\n      LL(a, b);\n      G.add(v,\
    \ a, b);\n    }\n  }\n  G.build();\n  auto [dist, par] = dial(G, 0);\n  FOR(v,\
    \ N) print(v, dist[v]);\n}\n\nsigned main() {\n  cin.tie(nullptr);\n  ios::sync_with_stdio(false);\n\
    \  cout << setprecision(15);\n\n  ll T = 1;\n  // LL(T);\n  FOR(T) solve();\n\n\
    \  return 0;\n}\n"
  dependsOn: []
  isVerificationFile: true
  path: test/aoj/ALDS1_12_B.test.cpp
  requiredBy: []
  timestamp: '1970-01-01 00:00:00+00:00'
  verificationStatus: TEST_WRONG_ANSWER
  verifiedWith: []
documentation_of: test/aoj/ALDS1_12_B.test.cpp
layout: document
redirect_from:
- /verify/test/aoj/ALDS1_12_B.test.cpp
- /verify/test/aoj/ALDS1_12_B.test.cpp.html
title: test/aoj/ALDS1_12_B.test.cpp
---
