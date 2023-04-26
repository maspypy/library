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
  code: "#define PROBLEM \"https://judge.yosupo.jp/problem/aplusb\"\n#include \"my_template.hpp\"\
    \n#include \"other/io.hpp\"\n#include \"mod/modint.hpp\"\n#include \"poly/convolution_leq.hpp\"\
    \n#include \"random/base.hpp\"\n\nusing mint = modint998;\n\nvc<mint> gen(int\
    \ n) {\n  vc<mint> f(n);\n  FOR(i, n) f[i] = RNG(0, mint::get_mod());\n  return\
    \ f;\n}\n\nvoid test_0() {\n  FOR(100) {\n    ll n = RNG(1, 10);\n    ll m = RNG(1,\
    \ 10);\n    auto f = gen(n), g = gen(m);\n    vc<mint> h(len(f) + len(g) - 1);\n\
    \    FOR(i, len(f)) FOR(j, len(g)) if (i <= j) h[i + j] += f[i] * g[j];\n    assert(convolution_leq(f,\
    \ g, 0) == h);\n  }\n}\n\nvoid test_1() {\n  FOR(100) {\n    ll n = RNG(1, 10);\n\
    \    ll m = RNG(1, 10);\n    auto f = gen(n), g = gen(m);\n    vc<mint> h(len(f)\
    \ + len(g) - 1);\n    FOR(i, len(f)) FOR(j, len(g)) if (i < j) h[i + j] += f[i]\
    \ * g[j];\n    assert(convolution_leq(f, g, 1) == h);\n  }\n}\n\nvoid test_2()\
    \ {\n  ll n = RNG(1000, 10000);\n  ll m = RNG(1000, 10000);\n  auto f = gen(n),\
    \ g = gen(m);\n  vc<mint> h(len(f) + len(g) - 1);\n  FOR(i, len(f)) FOR(j, len(g))\
    \ if (i < j) h[i + j] += f[i] * g[j];\n  assert(convolution_leq(f, g, 1) == h);\n\
    }\n\nvoid solve() {\n  LL(a, b);\n  print(a + b);\n}\n\nsigned main() {\n  cout\
    \ << fixed << setprecision(15);\n\n  test_0();\n  test_1();\n  test_2();\n  solve();\n\
    \n  return 0;\n}\n"
  dependsOn: []
  isVerificationFile: true
  path: test/mytest/conv_leq.test.cpp
  requiredBy: []
  timestamp: '1970-01-01 00:00:00+00:00'
  verificationStatus: TEST_WRONG_ANSWER
  verifiedWith: []
documentation_of: test/mytest/conv_leq.test.cpp
layout: document
redirect_from:
- /verify/test/mytest/conv_leq.test.cpp
- /verify/test/mytest/conv_leq.test.cpp.html
title: test/mytest/conv_leq.test.cpp
---
