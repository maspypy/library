---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: true
  _pathExtension: cpp
  _verificationStatusIcon: ':x:'
  attributes: {}
  bundledCode: "Traceback (most recent call last):\n  File \"/opt/hostedtoolcache/Python/3.12.14/x64/lib/python3.12/site-packages/onlinejudge_verify/documentation/build.py\"\
    , line 71, in _render_source_code_stat\n    bundled_code = language.bundle(stat.path,\
    \ basedir=basedir, options={'include_paths': [basedir]}).decode()\n          \
    \         ^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^\n\
    \  File \"/opt/hostedtoolcache/Python/3.12.14/x64/lib/python3.12/site-packages/onlinejudge_verify/languages/cplusplus.py\"\
    , line 187, in bundle\n    bundler.update(path)\n  File \"/opt/hostedtoolcache/Python/3.12.14/x64/lib/python3.12/site-packages/onlinejudge_verify/languages/cplusplus_bundle.py\"\
    , line 401, in update\n    self.update(self._resolve(pathlib.Path(included), included_from=path))\n\
    \  File \"/opt/hostedtoolcache/Python/3.12.14/x64/lib/python3.12/site-packages/onlinejudge_verify/languages/cplusplus_bundle.py\"\
    , line 401, in update\n    self.update(self._resolve(pathlib.Path(included), included_from=path))\n\
    \  File \"/opt/hostedtoolcache/Python/3.12.14/x64/lib/python3.12/site-packages/onlinejudge_verify/languages/cplusplus_bundle.py\"\
    , line 401, in update\n    self.update(self._resolve(pathlib.Path(included), included_from=path))\n\
    \                ^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^\n \
    \ File \"/opt/hostedtoolcache/Python/3.12.14/x64/lib/python3.12/site-packages/onlinejudge_verify/languages/cplusplus_bundle.py\"\
    , line 260, in _resolve\n    raise BundleErrorAt(path, -1, \"no such header\"\
    )\nonlinejudge_verify.languages.cplusplus_bundle.BundleErrorAt: other/bit.hpp:\
    \ line -1: no such header\n"
  code: "#define PROBLEM \"https://judge.yosupo.jp/problem/aplusb\"\n\n#include \"\
    my_template.hpp\"\n\n#include \"ds/sortable_array.hpp\"\n#include \"random/base.hpp\"\
    \n\nvoid test() {\n  int N = RNG(1, 64);\n  int MAX = RNG(2, 20);\n  vc<int> A(N);\n\
    \  FOR(i, N) A[i] = RNG(MAX);\n  Sortable_Array X(1000, MAX, A);\n\n  int Q =\
    \ 1000;\n  FOR(Q) {\n    int t = RNG(0, 5);\n    if (t == 0) {\n      vc<int>\
    \ B = X.get_all();\n      assert(A == B);\n    }\n    if (t == 0) {\n      int\
    \ idx = RNG(0, N);\n      assert(A[idx] == X.get(idx));\n    }\n    if (t == 2)\
    \ {\n      int idx = RNG(0, N);\n      int x = RNG(MAX);\n      A[idx] = x;\n\
    \      X.set(idx, x);\n    }\n    if (t == 3) {\n      int L = RNG(0, N);\n  \
    \    int R = RNG(0, N);\n      if (L > R) swap(L, R);\n      ++R;\n      X.sort_inc(L,\
    \ R);\n      sort(A.begin() + L, A.begin() + R);\n    }\n    if (t == 4) {\n \
    \     int L = RNG(0, N);\n      int R = RNG(0, N);\n      if (L > R) swap(L, R);\n\
    \      ++R;\n      X.sort_dec(L, R);\n      sort(A.begin() + L, A.begin() + R);\n\
    \      reverse(A.begin() + L, A.begin() + R);\n    }\n  }\n}\n\nvoid solve() {\n\
    \  int a, b;\n  cin >> a >> b;\n  cout << a + b << \"\\n\";\n}\n\nsigned main()\
    \ {\n  FOR(100) test();\n  solve();\n  return 0;\n}"
  dependsOn: []
  isVerificationFile: true
  path: test/1_mytest/sortable_array.test.cpp
  requiredBy: []
  timestamp: '1970-01-01 00:00:00+00:00'
  verificationStatus: TEST_WRONG_ANSWER
  verifiedWith: []
documentation_of: test/1_mytest/sortable_array.test.cpp
layout: document
redirect_from:
- /verify/test/1_mytest/sortable_array.test.cpp
- /verify/test/1_mytest/sortable_array.test.cpp.html
title: test/1_mytest/sortable_array.test.cpp
---
