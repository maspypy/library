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
    )\nonlinejudge_verify.languages.cplusplus_bundle.BundleErrorAt: graph/count/count_bipartite.hpp:\
    \ line -1: no such header\n"
  code: "#define PROBLEM \"https://judge.yosupo.jp/problem/aplusb\"\n#include \"my_template.hpp\"\
    \n\n#include \"mod/modint.hpp\"\n#include \"graph/count/count_bipartite.hpp\"\n\
    \nusing mint = modint998;\n\nvoid test() {\n  vc<mint> A = count_bipartite<mint>(10,\
    \ true);\n  vc<mint> B = {0LL,    1LL,     1LL,       3LL,        19LL,      \
    \  195LL,\n                3031LL, 67263LL, 2086099LL, 89224635LL, 5254054111LL};\n\
    \  assert(A == B);\n  A = count_bipartite<mint>(10, false);\n  B = {1LL,    1LL,\
    \      2LL,       7LL,         41LL,        376LL,\n       5177LL, 103237LL, 2922446LL,\
    \ 116011231LL, 6433447397LL};\n  assert(A == B);\n}\n\nvoid solve() {\n  int a,\
    \ b;\n  cin >> a >> b;\n  cout << a + b << \"\\n\";\n}\n\nsigned main() {\n  test();\n\
    \  solve();\n  return 0;\n}"
  dependsOn: []
  isVerificationFile: true
  path: test/mytest/count_bipartite.test.cpp
  requiredBy: []
  timestamp: '1970-01-01 00:00:00+00:00'
  verificationStatus: TEST_WRONG_ANSWER
  verifiedWith: []
documentation_of: test/mytest/count_bipartite.test.cpp
layout: document
redirect_from:
- /verify/test/mytest/count_bipartite.test.cpp
- /verify/test/mytest/count_bipartite.test.cpp.html
title: test/mytest/count_bipartite.test.cpp
---
