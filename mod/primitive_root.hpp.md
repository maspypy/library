---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':warning:'
  attributes:
    links:
    - https://codeforces.com/contest/1190/problem/F
  bundledCode: "Traceback (most recent call last):\n  File \"/opt/hostedtoolcache/Python/3.12.13/x64/lib/python3.12/site-packages/onlinejudge_verify/documentation/build.py\"\
    , line 71, in _render_source_code_stat\n    bundled_code = language.bundle(stat.path,\
    \ basedir=basedir, options={'include_paths': [basedir]}).decode()\n          \
    \         ^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^\n\
    \  File \"/opt/hostedtoolcache/Python/3.12.13/x64/lib/python3.12/site-packages/onlinejudge_verify/languages/cplusplus.py\"\
    , line 187, in bundle\n    bundler.update(path)\n  File \"/opt/hostedtoolcache/Python/3.12.13/x64/lib/python3.12/site-packages/onlinejudge_verify/languages/cplusplus_bundle.py\"\
    , line 401, in update\n    self.update(self._resolve(pathlib.Path(included), included_from=path))\n\
    \  File \"/opt/hostedtoolcache/Python/3.12.13/x64/lib/python3.12/site-packages/onlinejudge_verify/languages/cplusplus_bundle.py\"\
    , line 401, in update\n    self.update(self._resolve(pathlib.Path(included), included_from=path))\n\
    \                ^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^\n \
    \ File \"/opt/hostedtoolcache/Python/3.12.13/x64/lib/python3.12/site-packages/onlinejudge_verify/languages/cplusplus_bundle.py\"\
    , line 260, in _resolve\n    raise BundleErrorAt(path, -1, \"no such header\"\
    )\nonlinejudge_verify.languages.cplusplus_bundle.BundleErrorAt: nt/primetest.hpp:\
    \ line -1: no such header\n"
  code: "\n#include \"nt/factor.hpp\"\n#include \"mod/mod_pow.hpp\"\n#include \"random/base.hpp\"\
    \n\n// int\nint primitive_root(int p, bool min = true) {\n  auto pf = factor(p\
    \ - 1);\n  auto is_ok = [&](int g) -> bool {\n    for (auto&& [q, e] : pf)\n \
    \     if (mod_pow(g, (p - 1) / q, p) == 1) return false;\n    return true;\n \
    \ };\n  if (min) {\n    FOR(x, 1, p) if (is_ok(x)) return x;\n  }\n  while (1)\
    \ {\n    int x = RNG(1, p);\n    if (is_ok(x)) return x;\n  }\n  return -1;\n\
    }\n\nll primitive_root_64(ll p) {\n  auto pf = factor(p - 1);\n  auto is_ok =\
    \ [&](ll g) -> bool {\n    for (auto&& [q, e] : pf)\n      if (mod_pow_64(g, (p\
    \ - 1) / q, p) == 1) return false;\n    return true;\n  };\n  while (1) {\n  \
    \  ll x = RNG(1, p);\n    if (is_ok(x)) return x;\n  }\n  return -1;\n}\n\n//\
    \ https://codeforces.com/contest/1190/problem/F\nll primitive_root_prime_power_64(ll\
    \ p, ll e) {\n  assert(p >= 3);\n  ll g = primitive_root_64(p);\n  ll q = p;\n\
    \  ll phi = p - 1;\n  FOR(e - 1) {\n    q *= p;\n    phi *= p;\n    if (mod_pow_64(g,\
    \ phi / p, q) == 1) g += q / p;\n  }\n  return g;\n}\n"
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
