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
  _extendedRequiredBy:
  - icon: ':x:'
    path: linalg/implicit_matrix/vandermonde.hpp
    title: linalg/implicit_matrix/vandermonde.hpp
  - icon: ':x:'
    path: poly/composition_f_ex.hpp
    title: poly/composition_f_ex.hpp
  - icon: ':x:'
    path: poly/product_of_pow_of_linear.hpp
    title: poly/product_of_pow_of_linear.hpp
  - icon: ':x:'
    path: poly/sum_of_exp_bx.hpp
    title: poly/sum_of_exp_bx.hpp
  - icon: ':x:'
    path: seq/sum_of_powers.hpp
    title: seq/sum_of_powers.hpp
  _extendedVerifiedWith:
  - icon: ':x:'
    path: test/mytest/partial_frac.test.cpp
    title: test/mytest/partial_frac.test.cpp
  - icon: ':x:'
    path: test/mytest/vandermonde.test.cpp
    title: test/mytest/vandermonde.test.cpp
  - icon: ':x:'
    path: test/yukicoder/1145.test.cpp
    title: test/yukicoder/1145.test.cpp
  - icon: ':x:'
    path: test/yukicoder/1875.test.cpp
    title: test/yukicoder/1875.test.cpp
  - icon: ':x:'
    path: test/yukicoder/1962.test.cpp
    title: test/yukicoder/1962.test.cpp
  - icon: ':x:'
    path: test_atcoder/abc276_g.test.cpp
    title: test_atcoder/abc276_g.test.cpp
  - icon: ':x:'
    path: test_atcoder/abc276_g_2.test.cpp
    title: test_atcoder/abc276_g_2.test.cpp
  - icon: ':x:'
    path: test_atcoder/arc154f.test.cpp
    title: test_atcoder/arc154f.test.cpp
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
  code: "#pragma once\n\n#include \"poly/convolution.hpp\"\n\n// \u6709\u7406\u5F0F\
    \u306E\u548C\u3092\u8A08\u7B97\u3059\u308B\u3002\u5206\u5272\u7D71\u6CBB O(Nlog^2N)\u3002\
    N \u306F\u6B21\u6570\u306E\u548C\u3002\ntemplate <typename mint>\npair<vc<mint>,\
    \ vc<mint>> sum_of_rationals(vc<pair<vc<mint>, vc<mint>>> dat) {\n  if (len(dat)\
    \ == 0) {\n    vc<mint> f = {0}, g = {1};\n    return {f, g};\n  }\n  using P\
    \ = pair<vc<mint>, vc<mint>>;\n  auto add = [&](P& a, P& b) -> P {\n    int na\
    \ = len(a.fi) - 1, da = len(a.se) - 1;\n    int nb = len(b.fi) - 1, db = len(b.se)\
    \ - 1;\n    int n = max(na + db, da + nb);\n    vc<mint> num(n + 1);\n    {\n\
    \      auto f = convolution(a.fi, b.se);\n      FOR(i, len(f)) num[i] += f[i];\n\
    \    }\n    {\n      auto f = convolution(a.se, b.fi);\n      FOR(i, len(f)) num[i]\
    \ += f[i];\n    }\n    auto den = convolution(a.se, b.se);\n    return {num, den};\n\
    \  };\n\n  while (len(dat) > 1) {\n    int n = len(dat);\n    FOR(i, 1, n, 2)\
    \ { dat[i - 1] = add(dat[i - 1], dat[i]); }\n    FOR(i, ceil(n, 2)) dat[i] = dat[2\
    \ * i];\n    dat.resize(ceil(n, 2));\n  }\n  return dat[0];\n}"
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
  path: poly/sum_of_rationals.hpp
  requiredBy:
  - linalg/implicit_matrix/vandermonde.hpp
  - seq/sum_of_powers.hpp
  - poly/sum_of_exp_bx.hpp
  - poly/product_of_pow_of_linear.hpp
  - poly/composition_f_ex.hpp
  timestamp: '2023-04-27 03:47:30+09:00'
  verificationStatus: LIBRARY_ALL_WA
  verifiedWith:
  - test_atcoder/arc154f.test.cpp
  - test_atcoder/abc276_g.test.cpp
  - test_atcoder/abc276_g_2.test.cpp
  - test/yukicoder/1962.test.cpp
  - test/yukicoder/1145.test.cpp
  - test/yukicoder/1875.test.cpp
  - test/mytest/partial_frac.test.cpp
  - test/mytest/vandermonde.test.cpp
documentation_of: poly/sum_of_rationals.hpp
layout: document
redirect_from:
- /library/poly/sum_of_rationals.hpp
- /library/poly/sum_of_rationals.hpp.html
title: poly/sum_of_rationals.hpp
---
