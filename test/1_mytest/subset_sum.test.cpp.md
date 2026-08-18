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
    )\nonlinejudge_verify.languages.cplusplus_bundle.BundleErrorAt: ds/my_bitset.hpp:\
    \ line -1: no such header\n"
  code: "#define PROBLEM \"https://judge.yosupo.jp/problem/aplusb\"\n#include \"my_template.hpp\"\
    \n\n#include \"knapsack/subset_sum.hpp\"\n#include \"random/base.hpp\"\n\nvoid\
    \ test() {\n  FOR(10) {\n    FOR(N, 10) {\n      vc<int> A(N);\n      FOR(i, N)\
    \ A[i] = RNG(0, 100);\n      FOR(s, 1, 500) {\n        vc<int> I1 = subset_sum_solution_1<int>(A,\
    \ s);\n        vc<int> I2 = subset_sum_solution_2<int>(A, s);\n        vc<int>\
    \ I3 = subset_sum_solution_3<int>(A, s);\n        vc<int> I4 = subset_sum_solution_4<int>(A,\
    \ s);\n        vc<int> I5 = subset_sum_solution_4<int>(A, s);\n        if (I1.empty())\
    \ {\n          assert(I2.empty());\n          assert(I3.empty());\n          assert(I4.empty());\n\
    \          assert(I5.empty());\n          continue;\n        }\n        for (vc<int>\
    \ I: {I1, I2, I3, I4, I5}) {\n          FOR(i, len(I) - 1) assert(I[i] != I[i\
    \ + 1]);\n          int sm = 0;\n          for (auto& i: I) sm += A[i];\n    \
    \      assert(sm == s);\n        }\n      }\n    }\n  }\n}\n\nvoid solve() {\n\
    \  int a, b;\n  cin >> a >> b;\n  cout << a + b << \"\\n\";\n}\n\nsigned main()\
    \ {\n  test();\n  solve();\n  return 0;\n}"
  dependsOn: []
  isVerificationFile: true
  path: test/1_mytest/subset_sum.test.cpp
  requiredBy: []
  timestamp: '1970-01-01 00:00:00+00:00'
  verificationStatus: TEST_WRONG_ANSWER
  verifiedWith: []
documentation_of: test/1_mytest/subset_sum.test.cpp
layout: document
redirect_from:
- /verify/test/1_mytest/subset_sum.test.cpp
- /verify/test/1_mytest/subset_sum.test.cpp.html
title: test/1_mytest/subset_sum.test.cpp
---
