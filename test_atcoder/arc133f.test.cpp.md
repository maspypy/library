---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: true
  _pathExtension: cpp
  _verificationStatusIcon: ':x:'
  attributes: {}
  bundledCode: "Traceback (most recent call last):\n  File \"/opt/hostedtoolcache/Python/3.11.4/x64/lib/python3.11/site-packages/onlinejudge_verify/documentation/build.py\"\
    , line 71, in _render_source_code_stat\n    bundled_code = language.bundle(stat.path,\
    \ basedir=basedir, options={'include_paths': [basedir]}).decode()\n          \
    \         ^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^\n\
    \  File \"/opt/hostedtoolcache/Python/3.11.4/x64/lib/python3.11/site-packages/onlinejudge_verify/languages/cplusplus.py\"\
    , line 187, in bundle\n    bundler.update(path)\n  File \"/opt/hostedtoolcache/Python/3.11.4/x64/lib/python3.11/site-packages/onlinejudge_verify/languages/cplusplus_bundle.py\"\
    , line 401, in update\n    self.update(self._resolve(pathlib.Path(included), included_from=path))\n\
    \  File \"/opt/hostedtoolcache/Python/3.11.4/x64/lib/python3.11/site-packages/onlinejudge_verify/languages/cplusplus_bundle.py\"\
    , line 401, in update\n    self.update(self._resolve(pathlib.Path(included), included_from=path))\n\
    \                ^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^\n \
    \ File \"/opt/hostedtoolcache/Python/3.11.4/x64/lib/python3.11/site-packages/onlinejudge_verify/languages/cplusplus_bundle.py\"\
    , line 260, in _resolve\n    raise BundleErrorAt(path, -1, \"no such header\"\
    )\nonlinejudge_verify.languages.cplusplus_bundle.BundleErrorAt: poly/composition_f_polynomial_1.hpp:\
    \ line -1: no such header\n"
  code: "#define PROBLEM \"https://atcoder.jp/contests/arc133/tasks/arc133_f\"\n#include\
    \ \"my_template.hpp\"\n#include \"other/io.hpp\"\n\n#include \"mod/modint.hpp\"\
    \n#include \"poly/composition_f_rational.hpp\"\n\nusing mint = modint998;\n\n\
    void solve() {\n  LL(N, K);\n  VEC(mint, f, N + 1);\n  f = composition_f_rational_1<mint,\
    \ true>(f, 1, -1, 1, 1);\n  FOR(i, N + 1) f[i] *= mint(N - i - i).pow(K);\n  f\
    \ = composition_f_rational_1<mint, true>(f, 0, 1, 2, -1);\n  f = composition_f_a_plus_bx<mint>(f,\
    \ 1, -1);\n  mint sm = SUM<mint>(f);\n  mint cf = mint(1) / sm;\n  for (auto&&\
    \ x: f) x *= cf;\n  print(f);\n}\n\nsigned main() {\n  solve();\n  return 0;\n\
    }\n"
  dependsOn: []
  isVerificationFile: true
  path: test_atcoder/arc133f.test.cpp
  requiredBy: []
  timestamp: '1970-01-01 00:00:00+00:00'
  verificationStatus: TEST_WRONG_ANSWER
  verifiedWith: []
documentation_of: test_atcoder/arc133f.test.cpp
layout: document
redirect_from:
- /verify/test_atcoder/arc133f.test.cpp
- /verify/test_atcoder/arc133f.test.cpp.html
title: test_atcoder/arc133f.test.cpp
---
