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
    )\nonlinejudge_verify.languages.cplusplus_bundle.BundleErrorAt: alg/monoid/set.hpp:\
    \ line -1: no such header\n"
  code: "#include \"alg/monoid/cntsummax.hpp\"\r\n#include \"alg/monoid/set.hpp\"\r\
    \n\r\ntemplate <typename E, ll none_val>\r\nstruct Lazy_CntSumMax_Set {\r\n  static\
    \ constexpr ll INF = 1LL << 60;\r\n  using MX = Monoid_CntSumMax<E>;\r\n  using\
    \ MA = Monoid_Set<ll, none_val>;\r\n  using X_structure = MX;\r\n  using A_structure\
    \ = MA;\r\n  using X = typename MX::value_type;\r\n  using A = typename MA::value_type;\r\
    \n  static constexpr X act(const X& x, const A& a) {\r\n    if (a == MA::unit())\
    \ return x;\r\n    auto [xc, xs, xm] = x;\r\n    return {xc, xc * a, a};\r\n \
    \ }\r\n};\r\n"
  dependsOn: []
  isVerificationFile: false
  path: alg/acted_monoid/cntsummax_set.hpp
  requiredBy: []
  timestamp: '1970-01-01 00:00:00+00:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: alg/acted_monoid/cntsummax_set.hpp
layout: document
redirect_from:
- /library/alg/acted_monoid/cntsummax_set.hpp
- /library/alg/acted_monoid/cntsummax_set.hpp.html
title: alg/acted_monoid/cntsummax_set.hpp
---
