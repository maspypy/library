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
    )\nonlinejudge_verify.languages.cplusplus_bundle.BundleErrorAt: nt/primetest.hpp:\
    \ line -1: no such header\n"
  code: "#define PROBLEM \\\n  \"https://judge.yosupo.jp/problem/multivariate_convolution_cyclic\"\
    \n#include \"my_template.hpp\"\n#include \"other/io.hpp\"\n#include \"poly/multivar_convolution_cyclic.hpp\"\
    \n#include \"mod/dynamic_modint.hpp\"\n\nusing mint = dmint;\n\nvoid solve() {\n\
    \  INT(p, K);\n  mint::set_mod(p);\n  VEC(int, ns, K);\n  int N = 1;\n  for (auto&&\
    \ n: ns) N *= n;\n  VEC(mint, f, N);\n  VEC(mint, g, N);\n  print(multivar_convolution_cyclic(ns,\
    \ f, g));\n}\n\nsigned main() {\n  solve();\n  return 0;\n}\n"
  dependsOn: []
  isVerificationFile: true
  path: test/2_library_checker/convolution/multivariate_convolution_cyclic.test.cpp
  requiredBy: []
  timestamp: '1970-01-01 00:00:00+00:00'
  verificationStatus: TEST_WRONG_ANSWER
  verifiedWith: []
documentation_of: test/2_library_checker/convolution/multivariate_convolution_cyclic.test.cpp
layout: document
redirect_from:
- /verify/test/2_library_checker/convolution/multivariate_convolution_cyclic.test.cpp
- /verify/test/2_library_checker/convolution/multivariate_convolution_cyclic.test.cpp.html
title: test/2_library_checker/convolution/multivariate_convolution_cyclic.test.cpp
---
