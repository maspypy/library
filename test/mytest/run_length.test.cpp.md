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
    )\nonlinejudge_verify.languages.cplusplus_bundle.BundleErrorAt: other/random.hpp:\
    \ line -1: no such header\n"
  code: "#define PROBLEM \"https://judge.yosupo.jp/problem/aplusb\"\n#include \"my_template.hpp\"\
    \n#include \"other/io.hpp\"\n#include \"other/random.hpp\"\n#include \"string/run_length.hpp\"\
    \n\nvoid test() {\n  {\n    string A = \"aabbcaaab\";\n    auto res = run_length(A);\n\
    \    assert(len(res) == 5);\n    assert(res[0].fi == 'a' && res[0].se == 2);\n\
    \    assert(res[1].fi == 'b' && res[1].se == 2);\n    assert(res[2].fi == 'c'\
    \ && res[2].se == 1);\n    assert(res[3].fi == 'a' && res[3].se == 3);\n    assert(res[4].fi\
    \ == 'b' && res[4].se == 1);\n  }\n  {\n    string A = \"aaaaaa\";\n    auto res\
    \ = run_length(A);\n    assert(len(res) == 1);\n    assert(res[0].fi == 'a' &&\
    \ res[0].se == 6);\n  }\n  {\n    string A = \"\";\n    auto res = run_length(A);\n\
    \    assert(len(res) == 0);\n  }\n  {\n    vc<int> A = {1, 1, 2, 2, 3, 1, 1, 1,\
    \ 2};\n    auto res = run_length(A);\n    assert(len(res) == 5);\n    assert(res[0].fi\
    \ == 1 && res[0].se == 2);\n    assert(res[1].fi == 2 && res[1].se == 2);\n  \
    \  assert(res[2].fi == 3 && res[2].se == 1);\n    assert(res[3].fi == 1 && res[3].se\
    \ == 3);\n    assert(res[4].fi == 2 && res[4].se == 1);\n  }\n}\n\nvoid solve()\
    \ {\n  LL(a, b);\n  print(a + b);\n}\n\nsigned main() {\n  cout << fixed << setprecision(15);\n\
    \n  test();\n  solve();\n\n  return 0;\n}\n"
  dependsOn: []
  isVerificationFile: true
  path: test/mytest/run_length.test.cpp
  requiredBy: []
  timestamp: '1970-01-01 00:00:00+00:00'
  verificationStatus: TEST_WRONG_ANSWER
  verifiedWith: []
documentation_of: test/mytest/run_length.test.cpp
layout: document
redirect_from:
- /verify/test/mytest/run_length.test.cpp
- /verify/test/mytest/run_length.test.cpp.html
title: test/mytest/run_length.test.cpp
---
