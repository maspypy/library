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
    )\nonlinejudge_verify.languages.cplusplus_bundle.BundleErrorAt: enumerate/multisets.hpp:\
    \ line -1: no such header\n"
  code: "#define PROBLEM \"https://judge.yosupo.jp/problem/aplusb\"\n#include \"my_template.hpp\"\
    \n#include \"other/io.hpp\"\n\n#include \"enumerate/multisets.hpp\"\n#include\
    \ \"mod/modint.hpp\"\n\nusing mint = modint998;\n\nvoid test() {\n  {\n    vvc<int>\
    \ res;\n    auto f = [&](vc<int> A) -> void { res.eb(A); };\n    enumerate_multisets(3,\
    \ 2, f);\n    assert(len(res) == 6);\n    assert(res[0] == vc<int>({0, 0}));\n\
    \    assert(res[1] == vc<int>({0, 1}));\n    assert(res[2] == vc<int>({0, 2}));\n\
    \    assert(res[3] == vc<int>({1, 1}));\n    assert(res[4] == vc<int>({1, 2}));\n\
    \    assert(res[5] == vc<int>({2, 2}));\n  }\n  {\n    int cnt = 0;\n    auto\
    \ f = [&](vc<int> A) -> void { ++cnt; };\n    enumerate_multisets(3, 4, f);\n\
    \    assert(cnt == 15);\n  }\n}\n\nvoid solve() {\n  LL(a, b);\n  print(a + b);\n\
    }\n\nsigned main() {\n  cout << fixed << setprecision(15);\n\n  test();\n  solve();\n\
    \n  return 0;\n}\n"
  dependsOn: []
  isVerificationFile: true
  path: test/mytest/enumerate_multisets.test.cpp
  requiredBy: []
  timestamp: '1970-01-01 00:00:00+00:00'
  verificationStatus: TEST_WRONG_ANSWER
  verifiedWith: []
documentation_of: test/mytest/enumerate_multisets.test.cpp
layout: document
redirect_from:
- /verify/test/mytest/enumerate_multisets.test.cpp
- /verify/test/mytest/enumerate_multisets.test.cpp.html
title: test/mytest/enumerate_multisets.test.cpp
---
