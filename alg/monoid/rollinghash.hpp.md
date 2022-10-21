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
  bundledCode: "Traceback (most recent call last):\n  File \"/opt/hostedtoolcache/Python/3.10.8/x64/lib/python3.10/site-packages/onlinejudge_verify/documentation/build.py\"\
    , line 71, in _render_source_code_stat\n    bundled_code = language.bundle(stat.path,\
    \ basedir=basedir, options={'include_paths': [basedir]}).decode()\n  File \"/opt/hostedtoolcache/Python/3.10.8/x64/lib/python3.10/site-packages/onlinejudge_verify/languages/cplusplus.py\"\
    , line 187, in bundle\n    bundler.update(path)\n  File \"/opt/hostedtoolcache/Python/3.10.8/x64/lib/python3.10/site-packages/onlinejudge_verify/languages/cplusplus_bundle.py\"\
    , line 401, in update\n    self.update(self._resolve(pathlib.Path(included), included_from=path))\n\
    \  File \"/opt/hostedtoolcache/Python/3.10.8/x64/lib/python3.10/site-packages/onlinejudge_verify/languages/cplusplus_bundle.py\"\
    , line 260, in _resolve\n    raise BundleErrorAt(path, -1, \"no such header\"\
    )\nonlinejudge_verify.languages.cplusplus_bundle.BundleErrorAt: other/random.hpp:\
    \ line -1: no such header\n"
  code: "#pragma once\r\n#include \"other/random.hpp\"\r\n#include \"mod/modint61.hpp\"\
    \r\n\r\n// pow of base, val\r\nstruct Monoid_Rolling_Hash {\r\n  using value_type\
    \ = pair<modint61, modint61>;\r\n  using X = value_type;\r\n\r\n  static u64&\
    \ base() {\r\n    static u64 x = 0;\r\n    while (x == 0) {\r\n      RandomNumberGenerator\
    \ RNG;\r\n      x = RNG(modint61::get_mod());\r\n    }\r\n    return x;\r\n  }\r\
    \n  static X from_element(u64 x) { return {base(), x}; }\r\n  static X op(X x,\
    \ X y) { return {x.fi * y.fi, x.se * y.fi + y.se}; }\r\n  static constexpr X unit()\
    \ { return {1, 0}; }\r\n  static constexpr bool commute = false;\r\n};"
  dependsOn: []
  isVerificationFile: false
  path: alg/monoid/rollinghash.hpp
  requiredBy: []
  timestamp: '1970-01-01 00:00:00+00:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: alg/monoid/rollinghash.hpp
layout: document
redirect_from:
- /library/alg/monoid/rollinghash.hpp
- /library/alg/monoid/rollinghash.hpp.html
title: alg/monoid/rollinghash.hpp
---
