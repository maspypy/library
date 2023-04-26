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
  code: "#pragma once\n#include \"mod/fast_div.hpp\"\n#include \"mod/mod_inv.hpp\"\
    \n#include \"nt/factor.hpp\"\n\n// \u6700\u5C0F\u89E3\u3092 mod new_mod \u3067\
    \u8FD4\u3059\n// \u89E3\u306A\u3057\u306A\u3089 -1 \u3092\u8FD4\u3059\ni128 CRT(vc<int>\
    \ vals, vc<int> mods, ll new_mod = -1, bool coprime = false) {\n  int n = len(vals);\n\
    \  FOR(i, n) {\n    vals[i] %= mods[i];\n    if (vals[i] < 0) vals[i] += mods[i];\n\
    \  }\n  if (!coprime) {\n    unordered_map<ll, vc<pi>> MP;\n    FOR(i, n) {\n\
    \      for (auto&& [p, e]: factor(mods[i])) {\n        int mod = 1;\n        FOR(e)\
    \ mod *= p;\n        MP[p].eb(vals[i] % mod, mod);\n      }\n    }\n    vc<int>\
    \ xx, mm;\n    for (auto&& [p, dat]: MP) {\n      int mod = 1;\n      int val\
    \ = 0;\n      for (auto&& [x, m]: dat)\n        if (chmax(mod, m)) val = x;\n\
    \      for (auto&& [x, m]: dat)\n        if ((val - x) % m != 0) return -1;\n\
    \      xx.eb(val);\n      mm.eb(mod);\n    }\n    swap(vals, xx);\n    swap(mods,\
    \ mm);\n    n = len(vals);\n  }\n\n  vc<int> cfs(n);\n  FOR(i, n) {\n    auto\
    \ mod = fast_div(mods[i]);\n    ll a = vals[i];\n    ll prod = 1;\n    FOR(j,\
    \ i) {\n      a = (a + cfs[j] * (mods[i] - prod)) % mod;\n      prod = prod *\
    \ mods[j] % mod;\n    }\n    cfs[i] = mod_inv(prod, mods[i]) * a % mod;\n  }\n\
    \  i128 ret = 0;\n  i128 prod = 1;\n  FOR(i, n) {\n    ret += prod * cfs[i];\n\
    \    prod *= mods[i];\n    if (new_mod != -1) {\n      ret %= new_mod;\n     \
    \ prod %= new_mod;\n    }\n  }\n  return ret;\n}\n"
  dependsOn: []
  isVerificationFile: false
  path: nt/crt.hpp
  requiredBy: []
  timestamp: '1970-01-01 00:00:00+00:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: nt/crt.hpp
layout: document
redirect_from:
- /library/nt/crt.hpp
- /library/nt/crt.hpp.html
title: nt/crt.hpp
---
