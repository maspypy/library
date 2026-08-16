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
  code: "#define PROBLEM \"https://judge.yosupo.jp/problem/aplusb\"\n#include \"my_template.hpp\"\
    \n\n#include \"mod/modint.hpp\"\n#include \"mod/dynamic_modint.hpp\"\n#include\
    \ \"random/base.hpp\"\n#include \"mod/O1_inverse.hpp\"\n\ntemplate <typename mint>\n\
    void test() {\n  FOR(10000000) {\n    int x = RNG(1, mint::get_mod());\n    mint\
    \ v = O1_inverse<mint>(x);\n    mint prd = v * mint::raw(x);\n    assert(prd ==\
    \ mint(1));\n  }\n}\n\nvoid solve() {\n  int a, b;\n  cin >> a >> b;\n  cout <<\
    \ a + b << \"\\n\";\n}\n\nsigned main() {\n  test<modint998>();\n  test<modint107>();\n\
    \  dmint::set_mod(998244353);\n  test<dmint>();\n  dmint::set_mod(2);\n  test<dmint>();\n\
    \  dmint::set_mod(3);\n  test<dmint>();\n  dmint::set_mod(5);\n  test<dmint>();\n\
    \  dmint::set_mod(1'000'003);\n  test<dmint>();\n  dmint::set_mod(1'048'573);\n\
    \  test<dmint>();\n  dmint::set_mod(1'048'583);\n  test<dmint>();\n  dmint::set_mod(2097143);\n\
    \  test<dmint>();\n  dmint::set_mod(2097169);\n  test<dmint>();\n  solve();\n\
    }\n"
  dependsOn: []
  isVerificationFile: true
  path: test/1_mytest/O1_inv.test.cpp
  requiredBy: []
  timestamp: '1970-01-01 00:00:00+00:00'
  verificationStatus: TEST_WRONG_ANSWER
  verifiedWith: []
documentation_of: test/1_mytest/O1_inv.test.cpp
layout: document
redirect_from:
- /verify/test/1_mytest/O1_inv.test.cpp
- /verify/test/1_mytest/O1_inv.test.cpp.html
title: test/1_mytest/O1_inv.test.cpp
---
