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
  - icon: ':x:'
    path: poly/count_terms.hpp
    title: poly/count_terms.hpp
  - icon: ':question:'
    path: poly/fft.hpp
    title: poly/fft.hpp
  - icon: ':x:'
    path: poly/fps_inv.hpp
    title: poly/fps_inv.hpp
  - icon: ':question:'
    path: poly/ntt.hpp
    title: poly/ntt.hpp
  _extendedRequiredBy:
  - icon: ':warning:'
    path: graph/count/count_unicyclic.hpp
    title: graph/count/count_unicyclic.hpp
  - icon: ':x:'
    path: poly/fps_pow.hpp
    title: poly/fps_pow.hpp
  - icon: ':x:'
    path: poly/fps_sqrt.hpp
    title: poly/fps_sqrt.hpp
  - icon: ':x:'
    path: poly/product_of_f_rk_x.hpp
    title: poly/product_of_f_rk_x.hpp
  - icon: ':x:'
    path: seq/famous/stirling_number_2.hpp
    title: seq/famous/stirling_number_2.hpp
  - icon: ':x:'
    path: seq/famous/surjection.hpp
    title: seq/famous/surjection.hpp
  - icon: ':x:'
    path: seq/sum_of_powers.hpp
    title: seq/sum_of_powers.hpp
  _extendedVerifiedWith:
  - icon: ':x:'
    path: test/library_checker/math/stirling_number_of_the_second_kind.test.cpp
    title: test/library_checker/math/stirling_number_of_the_second_kind.test.cpp
  - icon: ':x:'
    path: test/library_checker/polynomial/log_of_fps.test.cpp
    title: test/library_checker/polynomial/log_of_fps.test.cpp
  - icon: ':x:'
    path: test/library_checker/polynomial/log_of_fps_sparse.test.cpp
    title: test/library_checker/polynomial/log_of_fps_sparse.test.cpp
  - icon: ':x:'
    path: test/library_checker/polynomial/pow_of_fps.test.cpp
    title: test/library_checker/polynomial/pow_of_fps.test.cpp
  - icon: ':x:'
    path: test/library_checker/polynomial/pow_of_fps_mint.test.cpp
    title: test/library_checker/polynomial/pow_of_fps_mint.test.cpp
  - icon: ':x:'
    path: test/library_checker/polynomial/pow_of_fps_sparse.test.cpp
    title: test/library_checker/polynomial/pow_of_fps_sparse.test.cpp
  - icon: ':x:'
    path: test/library_checker/polynomial/sqrt_of_fps.test.cpp
    title: test/library_checker/polynomial/sqrt_of_fps.test.cpp
  - icon: ':x:'
    path: test/library_checker/polynomial/sqrt_of_fps_sparse.test.cpp
    title: test/library_checker/polynomial/sqrt_of_fps_sparse.test.cpp
  - icon: ':x:'
    path: test/mytest/bell.test.cpp
    title: test/mytest/bell.test.cpp
  - icon: ':x:'
    path: test/mytest/online_log.test.cpp
    title: test/mytest/online_log.test.cpp
  - icon: ':x:'
    path: test/mytest/online_pow.test.cpp
    title: test/mytest/online_pow.test.cpp
  - icon: ':x:'
    path: test/yukicoder/1145.test.cpp
    title: test/yukicoder/1145.test.cpp
  - icon: ':x:'
    path: test/yukicoder/1321.test.cpp
    title: test/yukicoder/1321.test.cpp
  - icon: ':x:'
    path: test/yukicoder/1392.test.cpp
    title: test/yukicoder/1392.test.cpp
  - icon: ':x:'
    path: test/yukicoder/1533.test.cpp
    title: test/yukicoder/1533.test.cpp
  - icon: ':x:'
    path: test/yukicoder/1549.test.cpp
    title: test/yukicoder/1549.test.cpp
  - icon: ':x:'
    path: test/yukicoder/1939.test.cpp
    title: test/yukicoder/1939.test.cpp
  - icon: ':x:'
    path: test/yukicoder/2097.test.cpp
    title: test/yukicoder/2097.test.cpp
  - icon: ':x:'
    path: test_atcoder/abc222h.test.cpp
    title: test_atcoder/abc222h.test.cpp
  - icon: ':x:'
    path: test_atcoder/arc153f.test.cpp
    title: test_atcoder/arc153f.test.cpp
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
    , line 401, in update\n    self.update(self._resolve(pathlib.Path(included), included_from=path))\n\
    \  File \"/opt/hostedtoolcache/Python/3.11.3/x64/lib/python3.11/site-packages/onlinejudge_verify/languages/cplusplus_bundle.py\"\
    , line 312, in update\n    raise BundleErrorAt(path, i + 1, \"#pragma once found\
    \ in a non-first line\")\nonlinejudge_verify.languages.cplusplus_bundle.BundleErrorAt:\
    \ poly/ntt.hpp: line 2: #pragma once found in a non-first line\n"
  code: "#pragma once\r\n\r\n#include \"poly/fps_inv.hpp\"\r\n#include \"poly/count_terms.hpp\"\
    \r\n\r\ntemplate <typename mint>\r\nvc<mint> fps_log_dense(const vc<mint>& f)\
    \ {\r\n  assert(f[0] == mint(1));\r\n  ll N = len(f);\r\n  vc<mint> df = f;\r\n\
    \  FOR(i, N) df[i] *= mint(i);\r\n  df.erase(df.begin());\r\n  auto f_inv = fps_inv(f);\r\
    \n  auto g = convolution(df, f_inv);\r\n  g.resize(N - 1);\r\n  g.insert(g.begin(),\
    \ 0);\r\n  FOR(i, N) g[i] *= inv<mint>(i);\r\n  return g;\r\n}\r\n\r\ntemplate<typename\
    \ mint>\r\nvc<mint> fps_log_sparse(const vc<mint>& f){\r\n  int N = f.size();\r\
    \n  vc<pair<int, mint>> dat;\r\n  FOR(i, 1, N) if(f[i] != mint(0)) dat.eb(i, f[i]);\r\
    \n\r\n  vc<mint> F(N);\r\n  vc<mint> g(N - 1);\r\n  for (int n = 0; n < N - 1;\
    \ ++n) {\r\n    mint rhs = mint(n + 1) * f[n + 1];\r\n    for (auto &&[i, fi]:\
    \ dat) {\r\n      if (i > n) break;\r\n      rhs -= fi * g[n - i];\r\n    }\r\n\
    \    g[n] = rhs;\r\n    F[n + 1] = rhs * inv<mint>(n + 1);\r\n  }\r\n  return\
    \ F;\r\n}\r\n\r\ntemplate<typename mint>\r\nvc<mint> fps_log(const vc<mint>& f){\r\
    \n  assert(f[0] == mint(1));\r\n  if(count_terms(f) <= 200) return fps_log_sparse(f);\r\
    \n  return fps_log_dense(f);\r\n}\r\n"
  dependsOn:
  - poly/fps_inv.hpp
  - poly/count_terms.hpp
  - poly/convolution.hpp
  - mod/modint.hpp
  - mod/modint_common.hpp
  - mod/mod_inv.hpp
  - poly/convolution_naive.hpp
  - poly/ntt.hpp
  - mod/barret.hpp
  - poly/fft.hpp
  isVerificationFile: false
  path: poly/fps_log.hpp
  requiredBy:
  - graph/count/count_unicyclic.hpp
  - seq/famous/surjection.hpp
  - seq/famous/stirling_number_2.hpp
  - seq/sum_of_powers.hpp
  - poly/fps_sqrt.hpp
  - poly/product_of_f_rk_x.hpp
  - poly/fps_pow.hpp
  timestamp: '2023-04-27 03:47:30+09:00'
  verificationStatus: LIBRARY_ALL_WA
  verifiedWith:
  - test_atcoder/abc222h.test.cpp
  - test_atcoder/arc153f.test.cpp
  - test/yukicoder/1392.test.cpp
  - test/yukicoder/1549.test.cpp
  - test/yukicoder/1321.test.cpp
  - test/yukicoder/1145.test.cpp
  - test/yukicoder/2097.test.cpp
  - test/yukicoder/1533.test.cpp
  - test/yukicoder/1939.test.cpp
  - test/library_checker/polynomial/sqrt_of_fps.test.cpp
  - test/library_checker/polynomial/log_of_fps.test.cpp
  - test/library_checker/polynomial/sqrt_of_fps_sparse.test.cpp
  - test/library_checker/polynomial/pow_of_fps_mint.test.cpp
  - test/library_checker/polynomial/pow_of_fps.test.cpp
  - test/library_checker/polynomial/pow_of_fps_sparse.test.cpp
  - test/library_checker/polynomial/log_of_fps_sparse.test.cpp
  - test/library_checker/math/stirling_number_of_the_second_kind.test.cpp
  - test/mytest/online_log.test.cpp
  - test/mytest/online_pow.test.cpp
  - test/mytest/bell.test.cpp
documentation_of: poly/fps_log.hpp
layout: document
redirect_from:
- /library/poly/fps_log.hpp
- /library/poly/fps_log.hpp.html
title: poly/fps_log.hpp
---
