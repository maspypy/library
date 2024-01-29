---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: true
  _pathExtension: cpp
  _verificationStatusIcon: ':x:'
  attributes: {}
  bundledCode: "Traceback (most recent call last):\n  File \"/opt/hostedtoolcache/Python/3.12.1/x64/lib/python3.12/site-packages/onlinejudge_verify/documentation/build.py\"\
    , line 71, in _render_source_code_stat\n    bundled_code = language.bundle(stat.path,\
    \ basedir=basedir, options={'include_paths': [basedir]}).decode()\n          \
    \         ^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^\n\
    \  File \"/opt/hostedtoolcache/Python/3.12.1/x64/lib/python3.12/site-packages/onlinejudge_verify/languages/cplusplus.py\"\
    , line 187, in bundle\n    bundler.update(path)\n  File \"/opt/hostedtoolcache/Python/3.12.1/x64/lib/python3.12/site-packages/onlinejudge_verify/languages/cplusplus_bundle.py\"\
    , line 401, in update\n    self.update(self._resolve(pathlib.Path(included), included_from=path))\n\
    \                ^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^\n \
    \ File \"/opt/hostedtoolcache/Python/3.12.1/x64/lib/python3.12/site-packages/onlinejudge_verify/languages/cplusplus_bundle.py\"\
    , line 260, in _resolve\n    raise BundleErrorAt(path, -1, \"no such header\"\
    )\nonlinejudge_verify.languages.cplusplus_bundle.BundleErrorAt: graph/count/count_unicyclic.hpp:\
    \ line -1: no such header\n"
  code: "#define PROBLEM \"https://judge.yosupo.jp/problem/aplusb\"\n#include \"my_template.hpp\"\
    \n\n#include \"graph/count/count_unicyclic.hpp\"\n#include \"graph/count/count_tree.hpp\"\
    \n#include \"graph/count/count_forest.hpp\"\n#include \"mod/modint.hpp\"\n\nusing\
    \ mint = modint998;\n\nvoid test() {\n  int N = 10;\n  auto uni = count_unicyclic<mint>(N);\n\
    \  assert(uni\n         == vc<mint>(\n             {0, 0, 0, 1, 15, 222, 3660,\
    \ 68295, 1436568, 33779340, 880107840}));\n  auto tree = count_tree<mint>(N);\n\
    \  assert(tree\n         == vc<mint>(\n             {0, 1, 1, 3, 16, 125, 1296,\
    \ 16807, 262144, 4782969, 100000000}));\n  auto forest = count_forest<mint>(N);\n\
    \  assert(forest\n         == vc<mint>(\n             {1, 1, 2, 7, 38, 291, 2932,\
    \ 36961, 561948, 10026505, 205608536}));\n}\n\nvoid solve() {\n  int a, b;\n \
    \ cin >> a >> b;\n  cout << a + b << \"\\n\";\n}\n\nsigned main() {\n  test();\n\
    \  solve();\n  return 0;\n}\n"
  dependsOn: []
  isVerificationFile: true
  path: test/mytest/graph_count.test.cpp
  requiredBy: []
  timestamp: '1970-01-01 00:00:00+00:00'
  verificationStatus: TEST_WRONG_ANSWER
  verifiedWith: []
documentation_of: test/mytest/graph_count.test.cpp
layout: document
redirect_from:
- /verify/test/mytest/graph_count.test.cpp
- /verify/test/mytest/graph_count.test.cpp.html
title: test/mytest/graph_count.test.cpp
---
