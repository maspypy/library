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
    \                ^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^\n \
    \ File \"/opt/hostedtoolcache/Python/3.11.0/x64/lib/python3.11/site-packages/onlinejudge_verify/languages/cplusplus_bundle.py\"\
    , line 260, in _resolve\n    raise BundleErrorAt(path, -1, \"no such header\"\
    )\nonlinejudge_verify.languages.cplusplus_bundle.BundleErrorAt: ds/unionfind/unionfind.hpp:\
    \ line -1: no such header\n"
  code: "#define PROBLEM \"https://judge.yosupo.jp/problem/manhattanmst\"\n#include\
    \ \"my_template.hpp\"\n#include \"other/io.hpp\"\n\n#include \"geo/manhattan_mst.hpp\"\
    \n\nvoid solve() {\n  LL(N);\n  using P = pair<int, int>;\n  VEC(P, XY, N);\n\
    \  auto G = Manhattan_MST<int>(XY);\n  ll ANS = 0;\n  for (auto&& e: G.edges)\
    \ { ANS += e.cost; }\n  print(ANS);\n  for (auto&& e: G.edges) { print(e.frm,\
    \ e.to); }\n}\n\nsigned main() {\n  cout << fixed << setprecision(15);\n\n  ll\
    \ T = 1;\n  // LL(T);\n  FOR(T) solve();\n\n  return 0;\n}\n"
  dependsOn: []
  isVerificationFile: true
  path: test/library_checker/graph/manhattan_mst.test.cpp
  requiredBy: []
  timestamp: '1970-01-01 00:00:00+00:00'
  verificationStatus: TEST_WRONG_ANSWER
  verifiedWith: []
documentation_of: test/library_checker/graph/manhattan_mst.test.cpp
layout: document
redirect_from:
- /verify/test/library_checker/graph/manhattan_mst.test.cpp
- /verify/test/library_checker/graph/manhattan_mst.test.cpp.html
title: test/library_checker/graph/manhattan_mst.test.cpp
---
