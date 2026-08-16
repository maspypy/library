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
  code: "#define PROBLEM \"https://judge.yosupo.jp/problem/convolution_mod_1000000007\"\
    \n#include \"my_template.hpp\"\n#include \"other/io.hpp\"\n\n#include \"mod/dynamic_modint.hpp\"\
    \n#include \"poly/convolution.hpp\"\n\nvoid solve() {\n  using mint = dmint;\n\
    \  dmint::set_mod(1e9 + 7);\n  LL(N, M);\n  VEC(mint, A, N);\n  VEC(mint, B, M);\n\
    \  auto ANS = convolution(A, B);\n  print(ANS);\n}\n\nsigned main() {\n  solve();\n\
    \  return 0;\n}\n"
  dependsOn: []
  isVerificationFile: true
  path: test/2_library_checker/convolution/convolution_mod_107_dmint.test.cpp
  requiredBy: []
  timestamp: '1970-01-01 00:00:00+00:00'
  verificationStatus: TEST_WRONG_ANSWER
  verifiedWith: []
documentation_of: test/2_library_checker/convolution/convolution_mod_107_dmint.test.cpp
layout: document
redirect_from:
- /verify/test/2_library_checker/convolution/convolution_mod_107_dmint.test.cpp
- /verify/test/2_library_checker/convolution/convolution_mod_107_dmint.test.cpp.html
title: test/2_library_checker/convolution/convolution_mod_107_dmint.test.cpp
---
