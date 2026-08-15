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
    \  File \"/opt/hostedtoolcache/Python/3.12.13/x64/lib/python3.12/site-packages/onlinejudge_verify/languages/cplusplus_bundle.py\"\
    , line 401, in update\n    self.update(self._resolve(pathlib.Path(included), included_from=path))\n\
    \  [Previous line repeated 1 more time]\n  File \"/opt/hostedtoolcache/Python/3.12.13/x64/lib/python3.12/site-packages/onlinejudge_verify/languages/cplusplus_bundle.py\"\
    , line 260, in _resolve\n    raise BundleErrorAt(path, -1, \"no such header\"\
    )\nonlinejudge_verify.languages.cplusplus_bundle.BundleErrorAt: nt/primetable.hpp:\
    \ line -1: no such header\n"
  code: "#define PROBLEM \"https://judge.yosupo.jp/problem/aplusb\"\n#include \"my_template.hpp\"\
    \n\n#include \"poly/composition_f_x_plus_1x.hpp\"\n#include \"random/base.hpp\"\
    \n\nusing mint = modint998;\n\nvoid test() {\n  FOR(N, 0, 1000) {\n    vc<mint>\
    \ f(N + 1);\n    FOR(i, N + 1) f[i] = RNG(0, mint::get_mod());\n    vc<mint> F(2\
    \ * N + 1);\n    FOR(i, N + 1) {\n      FOR(j, i + 1) { F[N + j - (i - j)] +=\
    \ f[i] * C<mint>(i, j); }\n    }\n    vc<mint> G = composition_f_x_plus_1x<mint>(f);\n\
    \    assert(F == G);\n  }\n}\n\nvoid solve() {\n  int a, b;\n  cin >> a >> b;\n\
    \  cout << a + b << \"\\n\";\n};\n\nsigned main() {\n  test();\n  solve();\n}\n"
  dependsOn: []
  isVerificationFile: true
  path: test/1_mytest/composition_f_x_plus_1x.test.cpp
  requiredBy: []
  timestamp: '1970-01-01 00:00:00+00:00'
  verificationStatus: TEST_WRONG_ANSWER
  verifiedWith: []
documentation_of: test/1_mytest/composition_f_x_plus_1x.test.cpp
layout: document
redirect_from:
- /verify/test/1_mytest/composition_f_x_plus_1x.test.cpp
- /verify/test/1_mytest/composition_f_x_plus_1x.test.cpp.html
title: test/1_mytest/composition_f_x_plus_1x.test.cpp
---
