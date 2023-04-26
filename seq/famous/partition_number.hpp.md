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
    \  [Previous line repeated 1 more time]\n  File \"/opt/hostedtoolcache/Python/3.11.3/x64/lib/python3.11/site-packages/onlinejudge_verify/languages/cplusplus_bundle.py\"\
    , line 260, in _resolve\n    raise BundleErrorAt(path, -1, \"no such header\"\
    )\nonlinejudge_verify.languages.cplusplus_bundle.BundleErrorAt: mod/barret.hpp:\
    \ line -1: no such header\n"
  code: "#include \"poly/fps_inv.hpp\"\r\n\r\ntemplate <typename T>\r\nvc<T> partition_number(int\
    \ N) {\r\n  ll M = sqrt(N) + 10;\r\n  vc<T> f(N + 1);\r\n  FOR3(x, -M, M) {\r\n\
    \    ll d = x * (3 * x - 1) / 2;\r\n    if (d > N) continue;\r\n    f[d] += (x\
    \ % 2 == 0 ? 1 : -1);\r\n  }\r\n  return fps_inv<T>(f);\r\n}\r\n\r\n// n \u3092\
    \ k \u500B\u306B\u5206\u5272\u3059\u308B\u65B9\u6CD5 P[n][k] \u306E\u30C6\u30FC\
    \u30D6\u30EB\r\ntemplate <typename T>\r\nvvc<T> partition_number_2d(int n_max,\
    \ int k_max) {\r\n  vv(T, dp, n_max + 1, k_max + 1);\r\n  dp[0][0] = 1;\r\n  FOR3(n,\
    \ 1, n_max + 1) FOR3(k, 1, k_max + 1) {\r\n    // min = 1\r\n    dp[n][k] += dp[n\
    \ - 1][k - 1];\r\n    // min >= 2\r\n    if (n >= k) dp[n][k] += dp[n - k][k];\r\
    \n  }\r\n  return dp;\r\n}\r\n"
  dependsOn: []
  isVerificationFile: false
  path: seq/famous/partition_number.hpp
  requiredBy: []
  timestamp: '1970-01-01 00:00:00+00:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: seq/famous/partition_number.hpp
layout: document
redirect_from:
- /library/seq/famous/partition_number.hpp
- /library/seq/famous/partition_number.hpp.html
title: seq/famous/partition_number.hpp
---
