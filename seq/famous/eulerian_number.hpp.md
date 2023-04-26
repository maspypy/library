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
  code: "#include \"mod/powertable.hpp\"\n#include \"poly/convolution.hpp\"\n\n//\
    \ Eulerian number\n// sum n^dx^n = A_d(x) / (1-x)^{d+1} \u3068\u306A\u308B d \u6B21\
    \u591A\u9805\u5F0F\u306E\u4FC2\u6570\u5217\ntemplate <typename mint>\nvvc<mint>\
    \ eulerian_number_2d(int N, int K) {\n  vv(mint, A, N + 1, K + 1);\n  A[0][0]\
    \ = mint(1);\n  FOR(d, N) FOR(k, 1, K + 1) {\n    A[d + 1][k] = mint(k) * A[d][k]\
    \ + mint(d - k + 2) * A[d][k - 1];\n  }\n  return A;\n}\n\ntemplate <typename\
    \ mint>\nvc<mint> eulerian_number_n(int n) {\n  vc<mint> f = powertable_2<mint>(n,\
    \ n);\n  vc<mint> g(n + 1);\n  FOR(k, n + 1) g[k] = C<mint>(n + 1, k);\n  FOR(k,\
    \ 1, n + 1, 2) g[k] = -g[k];\n  f = convolution(f, g);\n  f.resize(n + 1);\n \
    \ return f;\n}"
  dependsOn: []
  isVerificationFile: false
  path: seq/famous/eulerian_number.hpp
  requiredBy: []
  timestamp: '1970-01-01 00:00:00+00:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: seq/famous/eulerian_number.hpp
layout: document
redirect_from:
- /library/seq/famous/eulerian_number.hpp
- /library/seq/famous/eulerian_number.hpp.html
title: seq/famous/eulerian_number.hpp
---
