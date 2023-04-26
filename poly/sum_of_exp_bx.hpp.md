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
  code: "#include \"poly/sum_of_rationals.hpp\"\n#include \"poly/fps_inv.hpp\"\n\n\
    // sum a e^{bx} \u3092 N \u6B21\u307E\u3067\u3002O(Mlog^2M + NlogN)\ntemplate\
    \ <typename mint>\nvc<mint> sum_of_exp_bx(int N, vc<pair<mint, mint>> AB) {\n\
    \  using poly = vc<mint>;\n  vc<pair<poly, poly>> fracs;\n  for (auto&& [a, b]:\
    \ AB) {\n    poly num = {a};\n    poly den = {mint(1), -b};\n    fracs.eb(num,\
    \ den);\n  }\n  auto [f, g] = sum_of_rationals<mint>(fracs);\n  g.resize(N + 1);\n\
    \  f = convolution(f, fps_inv(g));\n  f.resize(N + 1);\n  FOR(n, N + 1) f[n] *=\
    \ fact_inv<mint>(n);\n  return f;\n}\n"
  dependsOn: []
  isVerificationFile: false
  path: poly/sum_of_exp_bx.hpp
  requiredBy: []
  timestamp: '1970-01-01 00:00:00+00:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: poly/sum_of_exp_bx.hpp
layout: document
redirect_from:
- /library/poly/sum_of_exp_bx.hpp
- /library/poly/sum_of_exp_bx.hpp.html
title: poly/sum_of_exp_bx.hpp
---
