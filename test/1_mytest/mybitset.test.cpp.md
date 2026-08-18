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
    )\nonlinejudge_verify.languages.cplusplus_bundle.BundleErrorAt: ds/my_bitset.hpp:\
    \ line -1: no such header\n"
  code: "#define PROBLEM \"https://judge.yosupo.jp/problem/aplusb\"\n#include \"my_template.hpp\"\
    \n\n#include \"random/base.hpp\"\n#include \"ds/my_bitset.hpp\"\n\nvoid test()\
    \ {\n  FOR(N, 2000) {\n    int Q = 10 * N;\n    vc<int> A(N);\n    My_Bitset B(N);\n\
    \    FOR(Q) {\n      int t = RNG(0, 4);\n      int i = RNG(0, N);\n      if (t\
    \ == 0) {\n        A[i] = 0;\n        B[i] = 0;\n      }\n      if (t == 1) {\n\
    \        A[i] = 1;\n        B[i] = 1;\n      }\n      if (t == 2) {\n        int\
    \ p = i;\n        while (p < N && A[p] == 0) ++p;\n        assert(B.next(i) ==\
    \ p);\n      }\n      if (t == 3) {\n        int p = i;\n        while (p >= 0\
    \ && A[p] == 0) --p;\n        assert(B.prev(i) == p);\n      }\n    }\n  }\n}\n\
    \nvoid solve() {\n  int a, b;\n  cin >> a >> b;\n  cout << a + b << \"\\n\";\n\
    }\n\nsigned main() {\n  test();\n  solve();\n  return 0;\n}"
  dependsOn: []
  isVerificationFile: true
  path: test/1_mytest/mybitset.test.cpp
  requiredBy: []
  timestamp: '1970-01-01 00:00:00+00:00'
  verificationStatus: TEST_WRONG_ANSWER
  verifiedWith: []
documentation_of: test/1_mytest/mybitset.test.cpp
layout: document
redirect_from:
- /verify/test/1_mytest/mybitset.test.cpp
- /verify/test/1_mytest/mybitset.test.cpp.html
title: test/1_mytest/mybitset.test.cpp
---
