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
    \                ^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^\n \
    \ File \"/opt/hostedtoolcache/Python/3.12.13/x64/lib/python3.12/site-packages/onlinejudge_verify/languages/cplusplus_bundle.py\"\
    , line 260, in _resolve\n    raise BundleErrorAt(path, -1, \"no such header\"\
    )\nonlinejudge_verify.languages.cplusplus_bundle.BundleErrorAt: nt/primetable.hpp:\
    \ line -1: no such header\n"
  code: "#include \"nt/primetable.hpp\"\n\n// n \u304C p \u3092\u6301\u3064\u3068\u304D\
    \ f(n, p) \u3092\u547C\u3076\ntemplate <typename F>\nvoid factor_interval(ll L,\
    \ ll R, F f) {\n  int n = R - L;\n  auto primes = primetable(sqrt(R));\n  vi A(n);\n\
    \  iota(all(A), L);\n  for (auto&& p: primes) {\n    ll pp = 1;\n    while (1)\
    \ {\n      if (pp > R / p) break;\n      pp *= p;\n      ll s = ceil(L, pp) *\
    \ pp;\n      while (s < R) {\n        f(s, p);\n        A[s - L] /= p;\n     \
    \   s += pp;\n      }\n    }\n  }\n  FOR(i, n) if (A[i] > 1) f(L + i, A[i]);\n\
    }\n"
  dependsOn: []
  isVerificationFile: false
  path: nt/factor_interval.hpp
  requiredBy: []
  timestamp: '1970-01-01 00:00:00+00:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: nt/factor_interval.hpp
layout: document
redirect_from:
- /library/nt/factor_interval.hpp
- /library/nt/factor_interval.hpp.html
title: nt/factor_interval.hpp
---
