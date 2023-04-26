---
data:
  _extendedDependsOn:
  - icon: ':question:'
    path: mod/barret.hpp
    title: mod/barret.hpp
  - icon: ':question:'
    path: mod/mod_inv.hpp
    title: mod/mod_inv.hpp
  - icon: ':question:'
    path: mod/modint.hpp
    title: mod/modint.hpp
  - icon: ':question:'
    path: mod/modint_common.hpp
    title: mod/modint_common.hpp
  - icon: ':question:'
    path: my_template.hpp
    title: my_template.hpp
  - icon: ':question:'
    path: other/io.hpp
    title: other/io.hpp
  - icon: ':question:'
    path: poly/convolution.hpp
    title: poly/convolution.hpp
  - icon: ':x:'
    path: poly/convolution_leq.hpp
    title: poly/convolution_leq.hpp
  - icon: ':question:'
    path: poly/convolution_naive.hpp
    title: poly/convolution_naive.hpp
  - icon: ':question:'
    path: poly/fft.hpp
    title: poly/fft.hpp
  - icon: ':question:'
    path: poly/ntt.hpp
    title: poly/ntt.hpp
  - icon: ':question:'
    path: random/base.hpp
    title: random/base.hpp
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: true
  _pathExtension: cpp
  _verificationStatusIcon: ':x:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: https://judge.yosupo.jp/problem/aplusb
    links:
    - https://judge.yosupo.jp/problem/aplusb
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
    \  File \"/opt/hostedtoolcache/Python/3.11.3/x64/lib/python3.11/site-packages/onlinejudge_verify/languages/cplusplus_bundle.py\"\
    , line 312, in update\n    raise BundleErrorAt(path, i + 1, \"#pragma once found\
    \ in a non-first line\")\nonlinejudge_verify.languages.cplusplus_bundle.BundleErrorAt:\
    \ poly/ntt.hpp: line 2: #pragma once found in a non-first line\n"
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
  dependsOn:
  - my_template.hpp
  - other/io.hpp
  - mod/modint.hpp
  - mod/modint_common.hpp
  - poly/convolution_leq.hpp
  - poly/convolution.hpp
  - mod/mod_inv.hpp
  - poly/convolution_naive.hpp
  - poly/ntt.hpp
  - mod/barret.hpp
  - poly/fft.hpp
  - random/base.hpp
  isVerificationFile: true
  path: test/mytest/conv_leq.test.cpp
  requiredBy: []
  timestamp: '2023-04-27 03:47:30+09:00'
  verificationStatus: TEST_WRONG_ANSWER
  verifiedWith: []
documentation_of: test/mytest/conv_leq.test.cpp
layout: document
redirect_from:
- /verify/test/mytest/conv_leq.test.cpp
- /verify/test/mytest/conv_leq.test.cpp.html
title: test/mytest/conv_leq.test.cpp
---
