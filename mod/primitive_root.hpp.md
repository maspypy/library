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
  code: "#pragma once\r\n\r\n#include \"nt/factor.hpp\"\r\n#include \"mod/mod_pow.hpp\"\
    \r\n#include \"other/random.hpp\"\r\n\r\n// int\r\nint primitive_root(int p) {\r\
    \n  auto pf = factor(p - 1);\r\n  auto is_ok = [&](int g) -> bool {\r\n    for\
    \ (auto&& [q, e]: pf)\r\n      if (mod_pow(g, (p - 1) / q, p) == 1) return false;\r\
    \n    return true;\r\n  };\r\n  FOR3(x, 1, p) {\r\n    if (is_ok(x)) return x;\r\
    \n  }\r\n  return -1;\r\n}\r\n\r\nll primitive_root_long(ll p) {\r\n  auto pf\
    \ = factor(p - 1);\r\n  auto is_ok = [&](ll g) -> bool {\r\n    for (auto&& [q,\
    \ e]: pf)\r\n      if (mod_pow_long(g, (p - 1) / q, p) == 1) return false;\r\n\
    \    return true;\r\n  };\r\n  while (1) {\r\n    ll x = RNG(1, p);\r\n    if\
    \ (is_ok(x)) return x;\r\n  }\r\n  return -1;\r\n}\r\n"
  dependsOn: []
  isVerificationFile: false
  path: mod/primitive_root.hpp
  requiredBy: []
  timestamp: '1970-01-01 00:00:00+00:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: mod/primitive_root.hpp
layout: document
redirect_from:
- /library/mod/primitive_root.hpp
- /library/mod/primitive_root.hpp.html
title: mod/primitive_root.hpp
---
