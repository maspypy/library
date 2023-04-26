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
    \  [Previous line repeated 2 more times]\n  File \"/opt/hostedtoolcache/Python/3.11.3/x64/lib/python3.11/site-packages/onlinejudge_verify/languages/cplusplus_bundle.py\"\
    , line 260, in _resolve\n    raise BundleErrorAt(path, -1, \"no such header\"\
    )\nonlinejudge_verify.languages.cplusplus_bundle.BundleErrorAt: mod/barret.hpp:\
    \ line -1: no such header\n"
  code: "#pragma once\n\n#include \"poly/fps_log.hpp\"\n#include \"poly/fps_exp.hpp\"\
    \n\n// \u3068\u308A\u3042\u3048\u305A dense \u306E\u307F\u3001exp, log \u3067\
    \ O(NlogN)\n// f(x)f(rx)...f(r^{M-1}x)\ntemplate <typename mint>\nvc<mint> product_of_f_rk_x(vc<mint>&\
    \ f, mint r, ll M) {\n  assert(f[0] == mint(1));\n\n  mint pow_r = mint(1);\n\
    \  mint rm = r.pow(M);\n  mint pow_rm = mint(1);\n\n  vc<mint> g = fps_log(f);\n\
    \  FOR(i, 1, len(g)) {\n    pow_r *= r;\n    pow_rm *= rm;\n    if (pow_r == mint(1))\
    \ {\n      g[i] *= mint(M);\n    } else {\n      g[i] *= (pow_rm - mint(1)) /\
    \ (pow_r - mint(1));\n    }\n  }\n  return fps_exp(g);\n}\n"
  dependsOn: []
  isVerificationFile: false
  path: poly/product_of_f_rk_x.hpp
  requiredBy: []
  timestamp: '1970-01-01 00:00:00+00:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: poly/product_of_f_rk_x.hpp
layout: document
redirect_from:
- /library/poly/product_of_f_rk_x.hpp
- /library/poly/product_of_f_rk_x.hpp.html
title: poly/product_of_f_rk_x.hpp
---
