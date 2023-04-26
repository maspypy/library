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
  - icon: ':x:'
    path: mod/powertable.hpp
    title: mod/powertable.hpp
  - icon: ':question:'
    path: nt/primetable.hpp
    title: nt/primetable.hpp
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
  - icon: ':x:'
    path: poly/poly_taylor_shift.hpp
    title: poly/poly_taylor_shift.hpp
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':x:'
    path: test/library_checker/math/stirling_number_of_the_first_kind.test.cpp
    title: test/library_checker/math/stirling_number_of_the_first_kind.test.cpp
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
  code: "#include \"poly/poly_taylor_shift.hpp\"\r\n\r\ntemplate <typename mint>\r\
    \nvc<mint> stirling_number_1_2d(int nmax, int kmax) {\r\n  vv(mint, A, nmax +\
    \ 1, kmax + 1);\r\n  A[0][0] = 1;\r\n  for (int i = 1; i <= nmax; ++i) {\r\n \
    \   for (int j = 0; j < i + 1; ++j) {\r\n      if (j > kmax) break;\r\n      mint\
    \ &x = A[i][j];\r\n      if (j) x += A[i - 1][j - 1];\r\n      x -= A[i - 1][j]\
    \ * mint(i - 1);\r\n    }\r\n  }\r\n}\r\n\r\n// x(x+1)...(x+n-1) \u306E\u4FC2\u6570\
    \ c(n, k)\r\n// [n] \u306E\u9806\u5217\u306E\u3046\u3061\u3001k \u500B\u306E\u30B5\
    \u30A4\u30AF\u30EB\u306B\u5206\u304B\u308C\u308B\u3082\u306E\u306E\u500B\u6570\
    \u3002\r\n// n \u3092\u56FA\u5B9A\u3057\u305F\u3068\u304D\u306E\u5217\u6319\u3092\
    \ O(n log n) \u3067\u884C\u3046\u3002\r\ntemplate <typename mint>\r\nvc<mint>\
    \ stirling_number_1_n(int n, bool sgn = false) {\r\n  auto dfs = [&](auto self,\
    \ int n) -> vc<mint> {\r\n    if (n == 0) return {1};\r\n    if (n == 1) return\
    \ {0, 1};\r\n    auto f = self(self, n / 2);\r\n    auto g = poly_taylor_shift(f,\
    \ mint(n / 2));\r\n    f = convolution(f, g);\r\n    if (n & 1) {\r\n      g =\
    \ {(n - 1), 1};\r\n      f = convolution(f, g);\r\n    }\r\n    return f;\r\n\
    \  };\r\n  auto f = dfs(dfs, n);\r\n  if (sgn) { FOR(i, n + 1) if ((n + i) % 2\
    \ == 1) f[i] = -f[i]; }\r\n  return f;\r\n}\r\n\r\n// k \u3092\u56FA\u5B9A\u3057\
    \u305F\u3068\u304D\u306E c(n, k) \u306E\u5217\u6319\u3002\r\ntemplate <typename\
    \ mint>\r\nvc<mint> stirling_number_1_k(int k, int n_max, bool sgn = false) {\r\
    \n  if (n_max < k) {\r\n    vc<mint> f(n_max + 1);\r\n    return f;\r\n  }\r\n\
    \  int LIM = n_max - k;\r\n  vc<mint> f(LIM + 1);\r\n  FOR(i, LIM + 1) f[i] =\
    \ inv<mint>(i + 1);\r\n  f = fps_pow(f, k);\r\n  if (sgn) { FOR(i, LIM + 1) if\
    \ (i % 2 == 1) f[i] = -f[i]; }\r\n\r\n  mint cf = fact_inv<mint>(k);\r\n  vc<mint>\
    \ res(n_max + 1);\r\n  FOR(i, len(f)) res[k + i] = cf * f[i] * fact<mint>(k +\
    \ i);\r\n\r\n  return res;\r\n}\r\n"
  dependsOn:
  - poly/poly_taylor_shift.hpp
  - mod/powertable.hpp
  - nt/primetable.hpp
  - poly/convolution.hpp
  - mod/modint.hpp
  - mod/modint_common.hpp
  - mod/mod_inv.hpp
  - poly/convolution_naive.hpp
  - poly/ntt.hpp
  - mod/barret.hpp
  - poly/fft.hpp
  isVerificationFile: false
  path: seq/famous/stirling_number_1.hpp
  requiredBy: []
  timestamp: '2023-04-27 03:47:30+09:00'
  verificationStatus: LIBRARY_ALL_WA
  verifiedWith:
  - test/library_checker/math/stirling_number_of_the_first_kind.test.cpp
documentation_of: seq/famous/stirling_number_1.hpp
layout: document
redirect_from:
- /library/seq/famous/stirling_number_1.hpp
- /library/seq/famous/stirling_number_1.hpp.html
title: seq/famous/stirling_number_1.hpp
---
