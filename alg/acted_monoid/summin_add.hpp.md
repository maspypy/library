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
    )\nonlinejudge_verify.languages.cplusplus_bundle.BundleErrorAt: alg/monoid/cntsummin.hpp:\
    \ line -1: no such header\n"
  code: "#include \"alg/monoid/cntsummin.hpp\"\r\n#include \"alg/monoid/add.hpp\"\r\
    \n\r\ntemplate <typename E>\r\nstruct ActedMonoid_CntSumMin_Add {\r\n  using Monoid_X\
    \ = Monoid_CntSumMin<E>;\r\n  using Monoid_A = Monoid_Add<E>;\r\n  using X = typename\
    \ Monoid_X::value_type;\r\n  using A = typename Monoid_A::value_type;\r\n  static\
    \ constexpr X act(const X& x, const A& a, const ll& size) {\r\n    auto [xs, xm]\
    \ = x;\r\n    xm = (xm == numeric_limits<E>::max() ? xm : xm + a);\r\n    return\
    \ {xs + E(size) * a, xm};\r\n  }\r\n};\r\n"
  dependsOn: []
  isVerificationFile: false
  path: alg/acted_monoid/summin_add.hpp
  requiredBy: []
  timestamp: '1970-01-01 00:00:00+00:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: alg/acted_monoid/summin_add.hpp
layout: document
redirect_from:
- /library/alg/acted_monoid/summin_add.hpp
- /library/alg/acted_monoid/summin_add.hpp.html
title: alg/acted_monoid/summin_add.hpp
---
