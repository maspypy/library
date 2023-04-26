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
  code: "#pragma once\r\n#include \"poly/count_terms.hpp\"\r\n#include \"poly/fps_exp.hpp\"\
    \r\n#include \"poly/fps_log.hpp\"\r\n\r\n// fps \u306E k \u4E57\u3092\u6C42\u3081\
    \u308B\u3002k >= 0 \u306E\u524D\u63D0\u3067\u3042\u308B\u3002\r\n// \u5B9A\u6570\
    \u9805\u304C 1 \u3067\u3001k \u304C mint \u306E\u5834\u5408\u306B\u306F\u3001\
    fps_pow_1 \u3092\u4F7F\u3046\u3053\u3068\u3002\r\n// \u30FBdense \u306A\u5834\u5408\
    \uFF1A log, exp \u3092\u4F7F\u3046 O(NlogN)\r\n// \u30FBsparse \u306A\u5834\u5408\
    \uFF1A O(NK)\r\ntemplate <typename mint>\r\nvc<mint> fps_pow(const vc<mint>& f,\
    \ ll k) {\r\n  assert(0 <= k);\r\n  int n = len(f);\r\n  if(k==0){\r\n    vc<mint>\
    \ g(n);\r\n    g[0] = mint(1);\r\n    return g;\r\n  }\r\n  int d = n;\r\n  FOR_R(i,\
    \ n) if (f[i] != 0) d = i;\r\n  // d * k >= n\r\n  if(d >= ceil(n,k)){\r\n   \
    \ vc<mint> g(n);\r\n    return g;\r\n  }\r\n  ll off = d * k;\r\n  mint c = f[d];\r\
    \n  mint c_inv = mint(1) / mint(c);\r\n  vc<mint> g(n - off);\r\n  FOR(i, n -\
    \ off) g[i] = f[d + i] * c_inv;\r\n  g = fps_pow_1(g, mint(k));\r\n  vc<mint>\
    \ h(n);\r\n  c = c.pow(k);\r\n  FOR(i, len(g)) h[off + i] = g[i] * c;\r\n  return\
    \ h;\r\n}\r\n\r\ntemplate <typename mint>\r\nvc<mint> fps_pow_1_sparse(const vc<mint>&\
    \ f, mint K) {\r\n  int N = len(f);\r\n  vc<pair<int, mint>> dat;\r\n  FOR3(i,\
    \ 1, N) if (f[i] != mint(0)) dat.eb(i, f[i]);\r\n  vc<mint> g(N);\r\n  g[0] =\
    \ 1;\r\n  FOR(n, N - 1) {\r\n    mint& x = g[n + 1];\r\n    for (auto&& [d, cf]:\
    \ dat) {\r\n      if (d > n + 1) break;\r\n      mint t = cf * g[n - d + 1];\r\
    \n      x += t * (K * mint(d) - mint(n - d + 1));\r\n    }\r\n    x *= inv<mint>(n\
    \ + 1);\r\n  }\r\n  return g;\r\n}\r\n\r\ntemplate <typename mint>\r\nvc<mint>\
    \ fps_pow_1_dense(const vc<mint>& f, mint K) {\r\n  assert(f[0] == mint(1));\r\
    \n  auto log_f = fps_log(f);\r\n  FOR(i, len(f)) log_f[i] *= K;\r\n  return fps_exp(log_f);\r\
    \n}\r\n\r\ntemplate <typename mint>\r\nvc<mint> fps_pow_1(const vc<mint>& f, mint\
    \ K) {\r\n  if (count_terms(f) <= 100) return fps_pow_1_sparse(f, K);\r\n  return\
    \ fps_pow_1_dense(f, K);\r\n}\r\n"
  dependsOn: []
  isVerificationFile: false
  path: poly/fps_pow.hpp
  requiredBy: []
  timestamp: '1970-01-01 00:00:00+00:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: poly/fps_pow.hpp
layout: document
redirect_from:
- /library/poly/fps_pow.hpp
- /library/poly/fps_pow.hpp.html
title: poly/fps_pow.hpp
---
