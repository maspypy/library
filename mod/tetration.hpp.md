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
    \                ^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^\n \
    \ File \"/opt/hostedtoolcache/Python/3.11.3/x64/lib/python3.11/site-packages/onlinejudge_verify/languages/cplusplus_bundle.py\"\
    , line 260, in _resolve\n    raise BundleErrorAt(path, -1, \"no such header\"\
    )\nonlinejudge_verify.languages.cplusplus_bundle.BundleErrorAt: mod/fast_div.hpp:\
    \ line -1: no such header\n"
  code: "#include \"mod/fast_div.hpp\"\r\n#include \"nt/euler_phi.hpp\"\r\n\r\nint\
    \ tetration(vc<ll> a, int mod) {\r\n  for (auto&& x: a) assert(x > 0);\r\n\r\n\
    \  // a[0]^(a[1]^(a[2]^...))\r\n  vc<int> mod_chain = {mod};\r\n  while (mod_chain.back()\
    \ > 1) mod_chain.eb(euler_phi(mod_chain.back()));\r\n  while (len(a) > len(mod_chain))\
    \ a.pop_back();\r\n  while (len(mod_chain) > len(a)) mod_chain.pop_back();\r\n\
    \r\n  auto pow = [&](ll x, int n, int mod) -> int {\r\n    fast_div fd(mod);\r\
    \n    if (x >= mod) x = x % fd + mod;\r\n    ll v = 1;\r\n    do {\r\n      if\
    \ (n & 1) {\r\n        v *= x;\r\n        if (v >= mod) v = v % fd + mod;\r\n\
    \      }\r\n      x *= x;\r\n      if (x >= mod) x = x % fd + mod;\r\n      n\
    \ /= 2;\r\n    } while (n);\r\n    return v;\r\n  };\r\n\r\n  int v = 1;\r\n \
    \ FOR_R(i, len(a)) v = pow(a[i], v, mod_chain[i]);\r\n  return v % mod;\r\n}\r\
    \n"
  dependsOn: []
  isVerificationFile: false
  path: mod/tetration.hpp
  requiredBy: []
  timestamp: '1970-01-01 00:00:00+00:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: mod/tetration.hpp
layout: document
redirect_from:
- /library/mod/tetration.hpp
- /library/mod/tetration.hpp.html
title: mod/tetration.hpp
---
