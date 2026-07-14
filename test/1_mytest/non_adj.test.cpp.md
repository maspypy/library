---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: true
  _pathExtension: cpp
  _verificationStatusIcon: ':x:'
  attributes: {}
  bundledCode: "Traceback (most recent call last):\n  File \"/opt/hostedtoolcache/Python/3.14.6/x64/lib/python3.14/site-packages/onlinejudge_verify/documentation/build.py\"\
    , line 71, in _render_source_code_stat\n    bundled_code = language.bundle(stat.path,\
    \ basedir=basedir, options={'include_paths': [basedir]}).decode()\n          \
    \         ~~~~~~~~~~~~~~~^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^\n\
    \  File \"/opt/hostedtoolcache/Python/3.14.6/x64/lib/python3.14/site-packages/onlinejudge_verify/languages/cplusplus.py\"\
    , line 187, in bundle\n    bundler.update(path)\n    ~~~~~~~~~~~~~~^^^^^^\n  File\
    \ \"/opt/hostedtoolcache/Python/3.14.6/x64/lib/python3.14/site-packages/onlinejudge_verify/languages/cplusplus_bundle.py\"\
    , line 401, in update\n    self.update(self._resolve(pathlib.Path(included), included_from=path))\n\
    \                ~~~~~~~~~~~~~^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^\n \
    \ File \"/opt/hostedtoolcache/Python/3.14.6/x64/lib/python3.14/site-packages/onlinejudge_verify/languages/cplusplus_bundle.py\"\
    , line 260, in _resolve\n    raise BundleErrorAt(path, -1, \"no such header\"\
    )\nonlinejudge_verify.languages.cplusplus_bundle.BundleErrorAt: convex/non_adjecent_selection.hpp:\
    \ line -1: no such header\n"
  code: "#define PROBLEM \"https://judge.yosupo.jp/problem/aplusb\"\n\n#include \"\
    my_template.hpp\"\n\n#include \"convex/non_adjecent_selection.hpp\"\n#include\
    \ \"random/base.hpp\"\n\nvoid test() {\n  FOR(100) {\n    FOR(N, 10) {\n     \
    \ vi A(N);\n      FOR(i, N) A[i] = RNG(0, 1000000000);\n\n      Non_Adjacent_Selection<ll,\
    \ true> MI(A);\n      Non_Adjacent_Selection<ll, false> MA(A);\n      FOR(cnt,\
    \ ceil<int>(N, 2) + 1) {\n        ll mi = infty<ll>, ma = -infty<ll>;\n      \
    \  FOR(s, 1 << N) {\n          if (s & (s >> 1)) continue;\n          if (popcnt(s)\
    \ != cnt) continue;\n          ll sm = 0;\n          FOR(i, N) if (s >> i & 1)\
    \ sm += A[i];\n          chmin(mi, sm), chmax(ma, sm);\n        }\n        assert(MI.ANS[cnt]\
    \ == mi);\n        assert(MA.ANS[cnt] == ma);\n\n        {\n          vc<int>\
    \ I = MI.restore(cnt);\n          FOR(k, len(I) - 1) assert(I[k + 1] >= I[k] +\
    \ 2);\n          ll sm = 0;\n          for (auto& i: I) sm += A[i];\n        \
    \  assert(mi == sm);\n        }\n        {\n          vc<int> I = MA.restore(cnt);\n\
    \          FOR(k, len(I) - 1) assert(I[k + 1] >= I[k] + 2);\n          ll sm =\
    \ 0;\n          for (auto& i: I) sm += A[i];\n          assert(ma == sm);\n  \
    \      }\n      }\n    }\n  }\n}\n\nvoid solve() {\n  int a, b;\n  cin >> a >>\
    \ b;\n  cout << a + b << \"\\n\";\n}\n\nsigned main() {\n  test();\n  solve();\n\
    \  return 0;\n}"
  dependsOn: []
  isVerificationFile: true
  path: test/1_mytest/non_adj.test.cpp
  requiredBy: []
  timestamp: '1970-01-01 00:00:00+00:00'
  verificationStatus: TEST_WRONG_ANSWER
  verifiedWith: []
documentation_of: test/1_mytest/non_adj.test.cpp
layout: document
redirect_from:
- /verify/test/1_mytest/non_adj.test.cpp
- /verify/test/1_mytest/non_adj.test.cpp.html
title: test/1_mytest/non_adj.test.cpp
---
