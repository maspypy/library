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
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':x:'
    path: test/mytest/pascal.test.cpp
    title: test/mytest/pascal.test.cpp
  - icon: ':x:'
    path: test/yukicoder/2108.test.cpp
    title: test/yukicoder/2108.test.cpp
  - icon: ':x:'
    path: test/yukicoder/2243.test.cpp
    title: test/yukicoder/2243.test.cpp
  - icon: ':x:'
    path: test_atcoder/abc267g.test.cpp
    title: test_atcoder/abc267g.test.cpp
  _isVerificationFailed: true
  _pathExtension: hpp
  _verificationStatusIcon: ':x:'
  attributes:
    links: []
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
    , line 312, in update\n    raise BundleErrorAt(path, i + 1, \"#pragma once found\
    \ in a non-first line\")\nonlinejudge_verify.languages.cplusplus_bundle.BundleErrorAt:\
    \ poly/ntt.hpp: line 2: #pragma once found in a non-first line\n"
  code: "#include \"poly/convolution.hpp\"\n\n// transpose = 0\uFF1Ag[i] = sum binom(i,j)\
    \ f[j]\n// transpose = 1\uFF1Ag[i] = sum binom(j,i) f[j]\ntemplate <typename mint>\n\
    vc<mint> pascal(vc<mint> f, bool transpose, bool inverse) {\n  if (!transpose)\
    \ {\n    int n = len(f);\n    vc<mint> g(n);\n    FOR(i, n) g[i] = fact_inv<mint>(i);\n\
    \    if (inverse) FOR(i, n) if (i & 1) g[i] = -g[i];\n    FOR(i, n) f[i] *= fact_inv<mint>(i);\n\
    \    f = convolution(f, g);\n    f.resize(n);\n    FOR(i, n) f[i] *= fact<mint>(i);\n\
    \    return f;\n  }\n  int n = len(f);\n  FOR(i, n) f[i] *= fact<mint>(i);\n \
    \ reverse(all(f));\n  vc<mint> g(n);\n  FOR(i, n) g[i] = fact_inv<mint>(i);\n\
    \  if (inverse) FOR(i, n) if (i & 1) g[i] = -g[i];\n  f = convolution(f, g);\n\
    \  f.resize(n);\n  reverse(all(f));\n  FOR(i, n) f[i] *= fact_inv<mint>(i);\n\
    \  return f;\n}\n"
  dependsOn:
  - poly/convolution.hpp
  - mod/modint.hpp
  - mod/modint_common.hpp
  - mod/mod_inv.hpp
  - poly/convolution_naive.hpp
  - poly/ntt.hpp
  - mod/barret.hpp
  - poly/fft.hpp
  isVerificationFile: false
  path: linalg/implicit_matrix/pascal.hpp
  requiredBy: []
  timestamp: '2023-04-27 03:47:30+09:00'
  verificationStatus: LIBRARY_ALL_WA
  verifiedWith:
  - test_atcoder/abc267g.test.cpp
  - test/yukicoder/2108.test.cpp
  - test/yukicoder/2243.test.cpp
  - test/mytest/pascal.test.cpp
documentation_of: linalg/implicit_matrix/pascal.hpp
layout: document
redirect_from:
- /library/linalg/implicit_matrix/pascal.hpp
- /library/linalg/implicit_matrix/pascal.hpp.html
title: linalg/implicit_matrix/pascal.hpp
---
