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
    path: test/library_checker/convolution/mul_mod2n_convolution.test.cpp
    title: test/library_checker/convolution/mul_mod2n_convolution.test.cpp
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
  code: "#include \"poly/convolution.hpp\"\r\n\r\ntemplate <typename mint>\r\nvc<mint>\
    \ multiplicative_convolution_mod2n(vc<mint>& A, vc<mint>& B){\r\n  int N = 0;\r\
    \n  while((1<<N) < len(A)) ++N;\r\n  assert((1<<N) == len(A) && (1<<N) == len(B));\r\
    \n  \r\n  int mask = (1 << N) - 1;\r\n\r\n  vc<vc<vc<mint>>> AA(N + 1);\r\n  vc<vc<vc<mint>>>\
    \ BB(N + 1);\r\n  vc<vc<vc<mint>>> CC(N + 1);\r\n\r\n  auto shape = [&](int n)\
    \ -> pair<int, int> {\r\n    int H = (N - n >= 2 ? 2 : 1);\r\n    int W = 1 <<\
    \ max(N - n - 2, 0);\r\n    return {H, W};\r\n  };\r\n\r\n  FOR(n, N + 1) {\r\n\
    \    // 2 \u3067 n \u56DE\u5272\u308C\u308B\u3068\u3053\u308D\r\n    auto [H,\
    \ W] = shape(n);\r\n    AA[n].assign(H, vc<mint>(W));\r\n    BB[n].assign(H, vc<mint>(W));\r\
    \n    CC[n].assign(H, vc<mint>(W));\r\n    int x = (1 << n) & mask;\r\n    auto\
    \ &a = AA[n], &b = BB[n];\r\n    FOR(j, W) {\r\n      a[0][j] = A[x];\r\n    \
    \  b[0][j] = B[x];\r\n      if (H == 2) {\r\n        a[1][j] = A[(1 << N) - x];\r\
    \n        b[1][j] = B[(1 << N) - x];\r\n      }\r\n      x = (5 * x) & mask;\r\
    \n    }\r\n  }\r\n  // n \u3092\u56FA\u5B9A\u3057\u3066\u5404\u8EF8\u65B9\u5411\
    \u306B fft\u3002\u5408\u8A08 O(N2^N)\r\n  FOR(n, N + 1) {\r\n    auto &a = AA[n],\
    \ &b = BB[n];\r\n    auto [H, W] = shape(n);\r\n    FOR(i, H) {\r\n      ntt(a[i],\
    \ false);\r\n      ntt(b[i], false);\r\n    }\r\n    if (H == 2) {\r\n      FOR(j,\
    \ W) {\r\n        tie(a[0][j], a[1][j]) = mp(a[0][j] + a[1][j], a[0][j] - a[1][j]);\r\
    \n        tie(b[0][j], b[1][j]) = mp(b[0][j] + b[1][j], b[0][j] - b[1][j]);\r\n\
    \      }\r\n    }\r\n  }\r\n  FOR(n1, N + 1) FOR(n2, N + 1) {\r\n    // \u5FC5\
    \u8981\u306A\u9577\u3055\u306E fft \u5404\u70B9\u7A4D\u3092\u5FC5\u8981\u306A\u5834\
    \u6240\u306B\u8DB3\u3057\u3053\u3080\u3002\u5408\u8A08 O(2^N)\r\n    int n3 =\
    \ min(N, int(n1 + n2));\r\n    auto [H, W] = shape(n3);\r\n    FOR(i, H) FOR(j,\
    \ W) CC[n3][i][j] += AA[n1][i][j] * BB[n2][i][j];\r\n  }\r\n\r\n  FOR(n, N + 1)\
    \ {\r\n    // inverse fft\r\n    auto &c = CC[n];\r\n    auto [H, W] = shape(n);\r\
    \n    FOR(i, H) ntt(c[i], true);\r\n    if (H == 2) {\r\n      FOR(j, W) {\r\n\
    \        tie(c[0][j], c[1][j]) = mp(c[0][j] + c[1][j], c[0][j] - c[1][j]);\r\n\
    \      }\r\n    }\r\n    mint coef = mint(1) / mint(H);\r\n    FOR(i, H) FOR(j,\
    \ W) c[i][j] *= coef;  \r\n  }\r\n\r\n  vc<mint> C(1 << N);\r\n  FOR(n, N + 1)\
    \ {\r\n    auto [H, W] = shape(n);\r\n    int x = (1 << n) & mask;\r\n    auto\
    \ &c = CC[n];\r\n    FOR(j, W) {\r\n      C[x] = c[0][j];\r\n      if (H == 2)\
    \ { C[(1 << N) - x] = c[1][j]; }\r\n      x = (5 * x) & mask;\r\n    }\r\n  }\r\
    \n  return C;\r\n}"
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
  path: nt/multiplicative_convolution_mod2n.hpp
  requiredBy: []
  timestamp: '2023-04-27 03:47:30+09:00'
  verificationStatus: LIBRARY_ALL_WA
  verifiedWith:
  - test/library_checker/convolution/mul_mod2n_convolution.test.cpp
documentation_of: nt/multiplicative_convolution_mod2n.hpp
layout: document
redirect_from:
- /library/nt/multiplicative_convolution_mod2n.hpp
- /library/nt/multiplicative_convolution_mod2n.hpp.html
title: nt/multiplicative_convolution_mod2n.hpp
---
