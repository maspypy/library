---
data:
  _extendedDependsOn:
  - icon: ':x:'
    path: linalg/implicit_matrix/pascal.hpp
    title: linalg/implicit_matrix/pascal.hpp
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
  code: "#define PROBLEM \"https://judge.yosupo.jp/problem/aplusb\"\n\n#include \"\
    my_template.hpp\"\n#include \"other/io.hpp\"\n#include \"random/base.hpp\"\n#include\
    \ \"mod/modint.hpp\"\n#include \"linalg/implicit_matrix/pascal.hpp\"\n\nusing\
    \ mint = modint998;\n\nvc<mint> gen(int N) {\n  int mod = mint::get_mod();\n \
    \ vc<mint> f(N);\n  FOR(i, N) f[i] = RNG(mod);\n  return f;\n}\n\nvc<mint> pascal_naive(vc<mint>\
    \ f, bool transpose) {\n  int N = len(f);\n  vc<mint> g(N);\n  if (!transpose)\
    \ {\n    FOR(i, N) FOR(j, N) if (i >= j) g[i] += C<mint>(i, j) * f[j];\n  }\n\
    \  if (transpose) {\n    FOR(i, N) FOR(j, N) if (i <= j) g[i] += C<mint>(j, i)\
    \ * f[j];\n  }\n  return g;\n}\n\nvoid test() {\n  FOR(t, 2) {\n    FOR(N, 1,\
    \ 100) {\n      vc<mint> f = gen(N);\n      vc<mint> g1 = pascal<mint>(f, t, 0);\n\
    \      vc<mint> g2 = pascal_naive(f, t);\n      assert(g1 == g2);\n      vc<mint>\
    \ h = pascal<mint>(g1, t, 1);\n      assert(f == h);\n    }\n  }\n}\n\nvoid solve()\
    \ {\n  LL(a, b);\n  print(a + b);\n}\n\nsigned main() {\n  test();\n  solve();\n\
    \n  return 0;\n}"
  dependsOn:
  - my_template.hpp
  - other/io.hpp
  - random/base.hpp
  - mod/modint.hpp
  - mod/modint_common.hpp
  - linalg/implicit_matrix/pascal.hpp
  - poly/convolution.hpp
  - mod/mod_inv.hpp
  - poly/convolution_naive.hpp
  - poly/ntt.hpp
  - mod/barret.hpp
  - poly/fft.hpp
  isVerificationFile: true
  path: test/mytest/pascal.test.cpp
  requiredBy: []
  timestamp: '2023-04-27 03:47:30+09:00'
  verificationStatus: TEST_WRONG_ANSWER
  verifiedWith: []
documentation_of: test/mytest/pascal.test.cpp
layout: document
redirect_from:
- /verify/test/mytest/pascal.test.cpp
- /verify/test/mytest/pascal.test.cpp.html
title: test/mytest/pascal.test.cpp
---
