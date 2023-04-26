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
    \                ^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^\n \
    \ File \"/opt/hostedtoolcache/Python/3.11.3/x64/lib/python3.11/site-packages/onlinejudge_verify/languages/cplusplus_bundle.py\"\
    , line 260, in _resolve\n    raise BundleErrorAt(path, -1, \"no such header\"\
    )\nonlinejudge_verify.languages.cplusplus_bundle.BundleErrorAt: mod/barret.hpp:\
    \ line -1: no such header\n"
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
  dependsOn: []
  isVerificationFile: false
  path: poly/convolution_leq.hpp
  requiredBy: []
  timestamp: '1970-01-01 00:00:00+00:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: poly/convolution_leq.hpp
layout: document
redirect_from:
- /library/poly/convolution_leq.hpp
- /library/poly/convolution_leq.hpp.html
title: poly/convolution_leq.hpp
---
