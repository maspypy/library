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
    \n\n#include \"random/base.hpp\"\n#include \"mod/modint.hpp\"\n#include \"mod/dynamic_modint.hpp\"\
    \n#include \"poly/convolution.hpp\"\n\ntemplate <typename mint>\nvoid test() {\n\
    \  const u32 mod = mint::get_mod();\n  auto check = [&](ll x, ll y) -> void {\n\
    \    mint mx = x, my = y;\n    assert((x + y) % mod == (mx + my).val);\n    assert((x\
    \ + mod - y) % mod == (mx - my).val);\n    assert((x * y) % mod == (mx * my).val);\n\
    \    mint mz = mx / my;\n    ll z = mz.val;\n    assert(y * z % mod == x);\n \
    \ };\n  FOR(10000) {\n    ll x = RNG(0, mint::get_mod());\n    ll y = RNG(0, mint::get_mod());\n\
    \    check(x, y);\n  }\n  FOR(i, 1, 100) FOR(j, 1, 100) { check(mod - i, mod -\
    \ j); }\n}\n\ntemplate <typename mint>\nvoid test_conv() {\n  int N = RNG(1000,\
    \ 10000);\n  int M = RNG(1000, 10000);\n  vc<mint> A(N), B(M);\n  FOR(i, N) A[i]\
    \ = RNG(0, u32(-1));\n  FOR(i, M) B[i] = RNG(0, u32(-1));\n  vc<mint> S(N + M\
    \ - 1);\n  FOR(i, N) FOR(j, M) { S[i + j] += A[i] * B[j]; }\n  auto f = convolution_ntt(A,\
    \ B);\n  assert(S == f);\n}\n\nvoid solve() {\n  int a, b;\n  cin >> a >> b;\n\
    \  cout << a + b << \"\\n\";\n}\n\nsigned main() {\n  {\n    constexpr u32 mod\
    \ = (u32(1) << 31) - 19;\n    dmint::set_mod(mod);\n    test<modint<mod>>();\n\
    \    test<dmint>();\n  }\n\n  const u32 mod = 2013265921;\n  dmint::set_mod(mod);\n\
    \  dmint::set_ntt_info();\n  FOR(10) test_conv<modint<2013265921>>();\n  FOR(10)\
    \ test_conv<dmint>();\n\n  solve();\n  return 0;\n}"
  dependsOn: []
  isVerificationFile: true
  path: test/1_mytest/31bit_modint.test.cpp
  requiredBy: []
  timestamp: '1970-01-01 00:00:00+00:00'
  verificationStatus: TEST_WRONG_ANSWER
  verifiedWith: []
documentation_of: test/1_mytest/31bit_modint.test.cpp
layout: document
redirect_from:
- /verify/test/1_mytest/31bit_modint.test.cpp
- /verify/test/1_mytest/31bit_modint.test.cpp.html
title: test/1_mytest/31bit_modint.test.cpp
---
