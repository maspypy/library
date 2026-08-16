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
  code: "#include \"nt/factor.hpp\"\r\n\r\n// sort \u306F\u3057\u306A\u3044\r\nvc<ll>\
    \ divisors_by_pf(const vc<pair<ll, int>>& pf) {\r\n  vi div = {1};\r\n  for (auto&&\
    \ [p, e]: pf) {\r\n    ll n = len(div);\r\n    ll pp = 1;\r\n    FOR3(i, 1, e\
    \ + 1) {\r\n      pp *= p;\r\n      FOR(j, n) div.eb(div[j] * pp);\r\n    }\r\n\
    \  }\r\n  return div;\r\n}\r\n\r\n// sort \u306F\u3057\u306A\u3044\r\nvc<ll> divisors(ll\
    \ N) {\r\n  auto pf = factor(N);\r\n  return divisors_by_pf(pf);\r\n}\r\n\r\n\
    // sort \u306F\u3057\u306A\u3044\r\nvc<ll> divisors_by_lpf(ll N, vc<int>& lpf)\
    \ {\r\n  auto pf = factor_by_lpf(N, lpf);\r\n  return divisors_by_pf(pf);\r\n}"
  dependsOn: []
  isVerificationFile: false
  path: nt/divisors.hpp
  requiredBy: []
  timestamp: '1970-01-01 00:00:00+00:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: nt/divisors.hpp
layout: document
redirect_from:
- /library/nt/divisors.hpp
- /library/nt/divisors.hpp.html
title: nt/divisors.hpp
---
