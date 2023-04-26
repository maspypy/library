---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: true
  _pathExtension: cpp
  _verificationStatusIcon: ':x:'
  attributes: {}
  bundledCode: "Traceback (most recent call last):\n  File \"/opt/hostedtoolcache/Python/3.11.3/x64/lib/python3.11/site-packages/onlinejudge_verify/documentation/build.py\"\
    , line 71, in _render_source_code_stat\n    bundled_code = language.bundle(stat.path,\
    \ basedir=basedir, options={'include_paths': [basedir]}).decode()\n          \
    \         ^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^\n\
    \  File \"/opt/hostedtoolcache/Python/3.11.3/x64/lib/python3.11/site-packages/onlinejudge_verify/languages/cplusplus.py\"\
    , line 187, in bundle\n    bundler.update(path)\n  File \"/opt/hostedtoolcache/Python/3.11.3/x64/lib/python3.11/site-packages/onlinejudge_verify/languages/cplusplus_bundle.py\"\
    , line 401, in update\n    self.update(self._resolve(pathlib.Path(included), included_from=path))\n\
    \  File \"/opt/hostedtoolcache/Python/3.11.3/x64/lib/python3.11/site-packages/onlinejudge_verify/languages/cplusplus_bundle.py\"\
    , line 401, in update\n    self.update(self._resolve(pathlib.Path(included), included_from=path))\n\
    \  File \"/opt/hostedtoolcache/Python/3.11.3/x64/lib/python3.11/site-packages/onlinejudge_verify/languages/cplusplus_bundle.py\"\
    , line 401, in update\n    self.update(self._resolve(pathlib.Path(included), included_from=path))\n\
    \  [Previous line repeated 1 more time]\n  File \"/opt/hostedtoolcache/Python/3.11.3/x64/lib/python3.11/site-packages/onlinejudge_verify/languages/cplusplus_bundle.py\"\
    , line 260, in _resolve\n    raise BundleErrorAt(path, -1, \"no such header\"\
    )\nonlinejudge_verify.languages.cplusplus_bundle.BundleErrorAt: mod/barret.hpp:\
    \ line -1: no such header\n"
  code: "#define PROBLEM \"https://atcoder.jp/contests/agc013/tasks/agc013_e\"\n#include\
    \ \"my_template.hpp\"\n#include \"other/io.hpp\"\n#include \"mod/modint.hpp\"\n\
    #include \"poly/slice_rational_fps.hpp\"\n\nusing mint = modint107;\n\nvoid solve()\
    \ {\n  LL(N, M);\n  using poly = vc<mint>;\n  poly f = {0, 1, 1};\n  poly Q =\
    \ {1, -4, 2, -1};\n  int now = 0;\n  FOR(M) {\n    INT(x);\n    f = slice_rational_fps(f,\
    \ Q, x - now);\n    now = x;\n    mint a = f[0];\n    f = convolution(f, Q);\n\
    \    f.resize(3);\n    f[1] -= a;\n    f[2] -= a;\n  }\n  f = slice_rational_fps(f,\
    \ Q, N - now);\n  print(f[0]);\n}\n\nsigned main() {\n  solve();\n  return 0;\n\
    }"
  dependsOn: []
  isVerificationFile: true
  path: test_atcoder/agc013e.test.cpp
  requiredBy: []
  timestamp: '1970-01-01 00:00:00+00:00'
  verificationStatus: TEST_WRONG_ANSWER
  verifiedWith: []
documentation_of: test_atcoder/agc013e.test.cpp
layout: document
redirect_from:
- /verify/test_atcoder/agc013e.test.cpp
- /verify/test_atcoder/agc013e.test.cpp.html
title: test_atcoder/agc013e.test.cpp
---
