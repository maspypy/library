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
    \                ^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^\n \
    \ File \"/opt/hostedtoolcache/Python/3.12.13/x64/lib/python3.12/site-packages/onlinejudge_verify/languages/cplusplus_bundle.py\"\
    , line 260, in _resolve\n    raise BundleErrorAt(path, -1, \"no such header\"\
    )\nonlinejudge_verify.languages.cplusplus_bundle.BundleErrorAt: string/count_unborderd_string.hpp:\
    \ line -1: no such header\n"
  code: "#define PROBLEM \"https://judge.yosupo.jp/problem/aplusb\"\n#include \"my_template.hpp\"\
    \n\n#include \"string/count_unborderd_string.hpp\"\n#include \"mod/modint.hpp\"\
    \n\nusing mint = modint998;\n\nvoid test() {\n  vc<mint> A = count_unbordered_string<mint>(20,\
    \ 2);\n  vc<mint> A003000 = {1, 2, 2, 4, 6, 12, 20, 40, 74, 148, 284, 568, 1116,\
    \ 2232, 4424, 8848, 17622, 35244, 70340, 140680, 281076};\n  assert(A == A003000);\n\
    \n  vc<mint> B = count_unbordered_string<mint>(20, 3);\n  vc<mint> A019308\n \
    \     = {1, 3, 6, 18, 48, 144, 414, 1242, 3678, 11034, 32958, 98874, 296208, 888624,\
    \ 2664630, 7993890, 23977992, 71933976, 215790894, 647372682, 1942085088};\n \
    \ assert(B == A019308);\n}\n\nvoid solve() {\n  int a, b;\n  cin >> a >> b;\n\
    \  cout << a + b << \"\\n\";\n}\n\nsigned main() {\n  test();\n  solve();\n  return\
    \ 0;\n}\n"
  dependsOn: []
  isVerificationFile: true
  path: test/1_mytest/count_unbordered_string.test.cpp
  requiredBy: []
  timestamp: '1970-01-01 00:00:00+00:00'
  verificationStatus: TEST_WRONG_ANSWER
  verifiedWith: []
documentation_of: test/1_mytest/count_unbordered_string.test.cpp
layout: document
redirect_from:
- /verify/test/1_mytest/count_unbordered_string.test.cpp
- /verify/test/1_mytest/count_unbordered_string.test.cpp.html
title: test/1_mytest/count_unbordered_string.test.cpp
---
