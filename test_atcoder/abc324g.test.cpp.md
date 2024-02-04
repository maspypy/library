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
    )\nonlinejudge_verify.languages.cplusplus_bundle.BundleErrorAt: ds/wavelet_matrix.hpp:\
    \ line -1: no such header\n"
  code: "#define PROBLEM \"https://atcoder.jp/contests/abc324/tasks/abc324_g\"\n#include\
    \ \"my_template.hpp\"\n#include \"other/io.hpp\"\n\n#include \"ds/wavelet_matrix.hpp\"\
    \n\nvoid solve() {\n  INT(N);\n  VEC(int, A, N);\n  using T = tuple<int, int,\
    \ int, int>;\n  vc<T> dat;\n  dat.eb(0, N, 0, MAX(A) + 1);\n\n  Wavelet_Matrix<int,\
    \ 0> WM(A);\n\n  INT(Q);\n  FOR(Q) {\n    INT(t, s, x);\n    int L = get<0>(dat[s]);\n\
    \    int R = get<1>(dat[s]);\n    int lo = get<2>(dat[s]);\n    int hi = get<3>(dat[s]);\n\
    \    if (t == 1) {\n      auto check = [&](int M) -> bool { return WM.count(L,\
    \ M, lo, hi) >= x; };\n      if (!check(R)) {\n        dat.eb(0, 0, 0, 0);\n \
    \     } else {\n        int M = binary_search(check, R, L - 1);\n        dat[s]\
    \ = {L, M, lo, hi};\n        dat.eb(M, R, lo, hi);\n      }\n    }\n    if (t\
    \ == 2) {\n      if (x >= hi) { dat.eb(0, 0, 0, 0); }\n      elif (x < lo) {\n\
    \        dat[s] = {0, 0, 0, 0};\n        dat.eb(L, R, lo, hi);\n      }\n    \
    \  else {\n        dat[s] = {L, R, lo, x + 1};\n        dat.eb(L, R, x + 1, hi);\n\
    \      }\n    }\n\n    {\n      auto [L, R, lo, hi] = dat.back();\n      int ANS\
    \ = WM.count(L, R, lo, hi);\n      print(ANS);\n    }\n  }\n}\n\nsigned main()\
    \ {\n  solve();\n  return 0;\n}\n"
  dependsOn: []
  isVerificationFile: true
  path: test_atcoder/abc324g.test.cpp
  requiredBy: []
  timestamp: '1970-01-01 00:00:00+00:00'
  verificationStatus: TEST_WRONG_ANSWER
  verifiedWith: []
documentation_of: test_atcoder/abc324g.test.cpp
layout: document
redirect_from:
- /verify/test_atcoder/abc324g.test.cpp
- /verify/test_atcoder/abc324g.test.cpp.html
title: test_atcoder/abc324g.test.cpp
---
