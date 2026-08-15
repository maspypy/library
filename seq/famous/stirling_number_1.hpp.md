---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':warning:'
  attributes:
    links: []
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
    \                ^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^\n \
    \ File \"/opt/hostedtoolcache/Python/3.12.13/x64/lib/python3.12/site-packages/onlinejudge_verify/languages/cplusplus_bundle.py\"\
    , line 260, in _resolve\n    raise BundleErrorAt(path, -1, \"no such header\"\
    )\nonlinejudge_verify.languages.cplusplus_bundle.BundleErrorAt: nt/primetable.hpp:\
    \ line -1: no such header\n"
  code: "#include \"poly/fps_div.hpp\"\r\n#include \"poly/fps_pow.hpp\"\r\n#include\
    \ \"poly/poly_taylor_shift.hpp\"\r\n\r\ntemplate <typename mint>\r\nvvc<mint>\
    \ stirling_number_1_2d(int nmax, int kmax, bool sgn = false) {\r\n  vv(mint, A,\
    \ nmax + 1, kmax + 1);\r\n  A[0][0] = 1;\r\n  for (int i = 1; i <= nmax; ++i)\
    \ {\r\n    for (int j = 0; j < i + 1; ++j) {\r\n      if (j > kmax) break;\r\n\
    \      mint &x = A[i][j];\r\n      if (j) x += A[i - 1][j - 1];\r\n      x -=\
    \ A[i - 1][j] * mint(i - 1);\r\n    }\r\n  }\r\n  if (!sgn) {\r\n    FOR(n, nmax\
    \ + 1) FOR(i, n + 1) {\r\n      if (i > kmax) break;\r\n      if ((n + i) % 2\
    \ == 1) A[n][i] = -A[n][i];\r\n    }\r\n  }\r\n  return A;\r\n}\r\n\r\n// x(x+1)...(x+n-1)\
    \ \u306E\u4FC2\u6570 c(n, k)\r\n// signed=true: \u4E0B\u964D\u3079\u304D x(x-1)...(x-n+1)\r\
    \n// [n] \u306E\u9806\u5217\u306E\u3046\u3061\u3001k \u500B\u306E\u30B5\u30A4\u30AF\
    \u30EB\u306B\u5206\u304B\u308C\u308B\u3082\u306E\u306E\u500B\u6570\u3002\r\n//\
    \ n \u3092\u56FA\u5B9A\u3057\u305F\u3068\u304D\u306E\u5217\u6319\u3092 O(n log\
    \ n) \u3067\u884C\u3046\u3002\r\ntemplate <typename mint>\r\nvc<mint> stirling_number_1_n(int\
    \ n, bool sgn = false) {\r\n  auto dfs = [&](auto self, int n) -> vc<mint> {\r\
    \n    if (n == 0) return {1};\r\n    if (n == 1) return {0, 1};\r\n    auto f\
    \ = self(self, n / 2);\r\n    auto g = poly_taylor_shift(f, mint(n / 2));\r\n\
    \    f = convolution(f, g);\r\n    if (n & 1) {\r\n      g = {(n - 1), 1};\r\n\
    \      f = convolution(f, g);\r\n    }\r\n    return f;\r\n  };\r\n  auto f =\
    \ dfs(dfs, n);\r\n  if (sgn) {\r\n    FOR(i, n + 1) if ((n + i) % 2 == 1) f[i]\
    \ = -f[i];\r\n  }\r\n  return f;\r\n}\r\n\r\n// k \u3092\u56FA\u5B9A\u3057\u305F\
    \u3068\u304D\u306E c(n, k) \u306E\u5217\u6319\u3002\r\ntemplate <typename mint>\r\
    \nvc<mint> stirling_number_1_k(int k, int n_max, bool sgn = false) {\r\n  if (n_max\
    \ < k) {\r\n    vc<mint> f(n_max + 1);\r\n    return f;\r\n  }\r\n  int LIM =\
    \ n_max - k;\r\n  vc<mint> f(LIM + 1);\r\n  FOR(i, LIM + 1) f[i] = inv<mint>(i\
    \ + 1);\r\n  f = fps_pow(f, k);\r\n  if (sgn) {\r\n    FOR(i, LIM + 1) if (i %\
    \ 2 == 1) f[i] = -f[i];\r\n  }\r\n\r\n  mint cf = fact_inv<mint>(k);\r\n  vc<mint>\
    \ res(n_max + 1);\r\n  FOR(i, len(f)) res[k + i] = cf * f[i] * fact<mint>(k +\
    \ i);\r\n\r\n  return res;\r\n}\r\n\r\n// s(n,i) \u3092\u9006\u9806\u306B\u4E26\
    \u3079\u305F\u3082\u306E\r\n// (1+0x)(1+1x)(1+2x)...(1+(N-1)x) \u3092 [x^K] \u307E\
    \u3067\r\ntemplate <typename mint>\r\nvc<mint> stirling_number_1_suffix(ll N,\
    \ ll K) {\r\n  // \u307E\u305A\u306F e^{Nx}-1 / e^x-1 \u3092 [x^K] \u307E\u3067\
    \r\n  vc<mint> num(K + 1), den(K + 1);\r\n  mint powN = 1;\r\n  FOR(k, K + 1)\
    \ {\r\n    powN *= N;\r\n    num[k] = fact_inv<mint>(k + 1) * powN;\r\n    den[k]\
    \ = fact_inv<mint>(k + 1);\r\n  }\r\n  vc<mint> S = fps_div<mint>(num, den);\r\
    \n  FOR(i, K + 1) S[i] *= fact<mint>(i);\r\n  vc<mint> LOG_F(K + 1);\r\n  FOR(i,\
    \ 1, K + 1) LOG_F[i] = S[i] * inv<mint>(i) * (2 * (i & 1) - 1);\r\n  return fps_exp(LOG_F);\r\
    \n}\r\n"
  dependsOn: []
  isVerificationFile: false
  path: seq/famous/stirling_number_1.hpp
  requiredBy: []
  timestamp: '1970-01-01 00:00:00+00:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: seq/famous/stirling_number_1.hpp
layout: document
redirect_from:
- /library/seq/famous/stirling_number_1.hpp
- /library/seq/famous/stirling_number_1.hpp.html
title: seq/famous/stirling_number_1.hpp
---
