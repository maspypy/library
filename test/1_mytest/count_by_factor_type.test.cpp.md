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
    )\nonlinejudge_verify.languages.cplusplus_bundle.BundleErrorAt: nt/primetest.hpp:\
    \ line -1: no such header\n"
  code: "#define PROBLEM \"https://judge.yosupo.jp/problem/aplusb\"\n#include \"my_template.hpp\"\
    \n\n#include \"nt/count_by_factor_type.hpp\"\n#include \"nt/factor.hpp\"\n\nvoid\
    \ test() {\n  map<vc<int>, ll> god;\n  FOR(N, 1, 1000) {\n    vc<int> S;\n   \
    \ for (auto& [p, e]: factor(N)) S.eb(e);\n    sort(all(S));\n    reverse(all(S));\n\
    \    god[S]++;\n    map<vc<int>, ll> ans = count_by_factor_type(N);\n    assert(god\
    \ == ans);\n  }\n}\n\nvoid solve() {\n  int x, y;\n  cin >> x >> y;\n  cout <<\
    \ x + y << \"\\n\";\n}\n\nsigned main() {\n  test();\n  solve();\n  return 0;\n\
    }"
  dependsOn: []
  isVerificationFile: true
  path: test/1_mytest/count_by_factor_type.test.cpp
  requiredBy: []
  timestamp: '1970-01-01 00:00:00+00:00'
  verificationStatus: TEST_WRONG_ANSWER
  verifiedWith: []
documentation_of: test/1_mytest/count_by_factor_type.test.cpp
layout: document
redirect_from:
- /verify/test/1_mytest/count_by_factor_type.test.cpp
- /verify/test/1_mytest/count_by_factor_type.test.cpp.html
title: test/1_mytest/count_by_factor_type.test.cpp
---
