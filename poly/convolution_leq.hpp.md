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
    path: test/mytest/conv_leq.test.cpp
    title: test/mytest/conv_leq.test.cpp
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
  code: "#include \"poly/convolution.hpp\"\r\n\r\n// h[k] = sum_{i+j=k and i<=j} f_ig_j\r\
    \n// if strict: i < j\r\ntemplate <typename T>\r\nvc<T> convolution_leq(vc<T>\
    \ f, vc<T> g, bool strict) {\r\n  vc<T> h(len(f) + len(g) - 1);\r\n  ll THRESH\
    \ = 60;\r\n\r\n  ll N = max(len(f), len(g));\r\n  vc<pair<int, int>> que;\r\n\
    \  que.eb(0, N);\r\n  while (!que.empty()) {\r\n    auto [L, R] = que.back();\r\
    \n    que.pop_back();\r\n    if (R - L <= THRESH) {\r\n      FOR3(i, L, min<int>(R,\
    \ len(f))) FOR3(j, i + 1, min<int>(R, len(g))) {\r\n        h[i + j] += f[i] *\
    \ g[j];\r\n      }\r\n      continue;\r\n    }\r\n    ll M = (L + R) / 2;\r\n\
    \    que.eb(L, M), que.eb(M, R);\r\n    if (len(f) <= L || len(g) <= M) continue;\r\
    \n    auto p = convolution<T>({f.begin() + L, f.begin() + min<int>(M, len(f))},\r\
    \n                            {g.begin() + M, g.begin() + min<int>(R, len(g))});\r\
    \n    FOR(i, len(p)) h[L + M + i] += p[i];\r\n  }\r\n  if (!strict) { FOR(i, min(len(f),\
    \ len(g))) h[i + i] += f[i] * g[i]; }\r\n  return h;\r\n}"
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
  path: poly/convolution_leq.hpp
  requiredBy: []
  timestamp: '2023-04-27 03:47:30+09:00'
  verificationStatus: LIBRARY_ALL_WA
  verifiedWith:
  - test/mytest/conv_leq.test.cpp
documentation_of: poly/convolution_leq.hpp
layout: document
redirect_from:
- /library/poly/convolution_leq.hpp
- /library/poly/convolution_leq.hpp.html
title: poly/convolution_leq.hpp
---
