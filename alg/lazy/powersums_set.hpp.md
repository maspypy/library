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
  bundledCode: "Traceback (most recent call last):\n  File \"/opt/hostedtoolcache/Python/3.11.0/x64/lib/python3.11/site-packages/onlinejudge_verify/documentation/build.py\"\
    , line 71, in _render_source_code_stat\n    bundled_code = language.bundle(stat.path,\
    \ basedir=basedir, options={'include_paths': [basedir]}).decode()\n          \
    \         ^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^\n\
    \  File \"/opt/hostedtoolcache/Python/3.11.0/x64/lib/python3.11/site-packages/onlinejudge_verify/languages/cplusplus.py\"\
    , line 187, in bundle\n    bundler.update(path)\n  File \"/opt/hostedtoolcache/Python/3.11.0/x64/lib/python3.11/site-packages/onlinejudge_verify/languages/cplusplus_bundle.py\"\
    , line 401, in update\n    self.update(self._resolve(pathlib.Path(included), included_from=path))\n\
    \                ^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^\n \
    \ File \"/opt/hostedtoolcache/Python/3.11.0/x64/lib/python3.11/site-packages/onlinejudge_verify/languages/cplusplus_bundle.py\"\
    , line 260, in _resolve\n    raise BundleErrorAt(path, -1, \"no such header\"\
    )\nonlinejudge_verify.languages.cplusplus_bundle.BundleErrorAt: alg/group/power_sums.hpp:\
    \ line -1: no such header\n"
  code: "#pragma once\r\n\r\n#include \"alg/monoid/set.hpp\"\r\n#include \"alg/group/power_sums.hpp\"\
    \r\n\r\ntemplate <typename mint, int K>\r\nstruct Lazy_Power_Sums_Set {\r\n  using\
    \ MX = Group_power_sums<mint, K>;\r\n  using MA = Monoid_Set<int, -1>;\r\n  using\
    \ X_structure = MX;\r\n  using A_structure = MA;\r\n  using X = typename MX::value_type;\r\
    \n  using A = typename MA::value_type;\r\n  static X act(const X &x, const A &b)\
    \ {\r\n    if (b == -1) return x;\r\n    mint a = b;\r\n    vc<mint> y(K);\r\n\
    \    vc<mint> pow(K);\r\n    pow[0] = mint(1);\r\n    FOR(k, K - 1) pow[k + 1]\
    \ = pow[k] * a;\r\n    FOR(i, 5) y[i] = x[0] * pow[i];\r\n    return y;\r\n  }\r\
    \n};\r\n"
  dependsOn: []
  isVerificationFile: false
  path: alg/lazy/powersums_set.hpp
  requiredBy: []
  timestamp: '1970-01-01 00:00:00+00:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: alg/lazy/powersums_set.hpp
layout: document
redirect_from:
- /library/alg/lazy/powersums_set.hpp
- /library/alg/lazy/powersums_set.hpp.html
title: alg/lazy/powersums_set.hpp
---
